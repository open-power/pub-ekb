/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/lib/p10_pibmem_dump.C $              */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2016,2021                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file  p10_pibmem_dump.C
/// @brief Dump PIBMEM's Array Data in Structure.
///
/// *HW Owner    : Anusha Reddy
/// *FW Owner    :
/// *Team        : Pervasive

// ------------------------------------- Mux configs-------------------------------------------------------------
// FSI2PCB(16)                 PIB2PCB(18)                   PCB2PCB(19)          cannot access       can access
//    1                           0                             0                      PIB             EPS - perv
//    0                           1                             0                      PCB             PIB, SBE, EPS
//    0                           0                             1                       -              PIB, PCB n/w
// -------------------------------------------------------------------------------------------------------------------

#include <fapi2.H>
#include <p10_scom_proc.H>
#include <p10_scom_perv.H>
#include <p10_pibmem_dump.H>


const static uint32_t P10_PIBMEM_START_ARRAY_ADDRESS   = 0x00080000;
const static uint32_t P10_DEPTH_OF_ARRAY               = 0x0000FFEF;
const static uint32_t PIBMEM_CTRL_REG              = 0x0008FFF0;


fapi2::ReturnCode p10_pibmem_dump(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t start_byte,
    const uint32_t num_of_byte,
    const user_options input_switches,
    std::vector<array_data_t>& pibmem_contents,
    const bool ecc_enable)
{
    using namespace scomt;

    uint32_t i, start_address, num_of_address, end_address;
    uint32_t PIBMEM_START_ARRAY_ADDRESS, DEPTH_OF_ARRAY;
    array_data_t fetch_data;
    fapi2::buffer<uint64_t> l_data64, l_data64_sl_clk_status, ctrl_data, original_ctrl_data;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_sb_cs;
    fapi2::buffer<uint32_t> l_data32_cbs_cs;
    bool sab, sdb;

    PIBMEM_START_ARRAY_ADDRESS = P10_PIBMEM_START_ARRAY_ADDRESS;
    DEPTH_OF_ARRAY = P10_DEPTH_OF_ARRAY;

    FAPI_DBG("Release PCB reset");
    l_data32.flush<0>().setBit<perv::FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
    FAPI_TRY(putCfamRegister(i_target, perv::FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, l_data32 ));


    FAPI_TRY(getCfamRegister(i_target, perv::FSXCOMP_FSXLOG_ROOT_CTRL0_FSI, l_data32 ));
    FAPI_TRY(fapi2::getCfamRegister(i_target, perv::FSXCOMP_FSXLOG_SB_CS_FSI, l_data32_sb_cs));    //0x2808
    FAPI_TRY(fapi2::getCfamRegister(i_target, perv::FSXCOMP_FSXLOG_CBS_CS_FSI, l_data32_cbs_cs));    //0x2801

    sab = (l_data32_cbs_cs.getBit<perv::FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>());
    sdb = (l_data32_sb_cs.getBit<perv::FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE>());

    if(sab && !sdb)
    {
        FAPI_ERR("PIBMEM can not be accessed in secure mode without setting secure debug bit");
        goto fapi_try_exit;
    }

    if(!sab)
    {
        FAPI_TRY(getScom(i_target, proc::TP_TPCHIP_TPC_CPLT_CTRL1_RW, l_data64));
        FAPI_TRY(getScom(i_target, proc::TP_TPCHIP_TPC_CLOCK_STAT_SL, l_data64_sl_clk_status));



        // RC0bits 16,18,19 != 000 && RC0bit16 != 1 && cplt_ctrl[ pib(bit6) sbe(bit5)] != 1 && checking if pib clocks are started
        if ( ! ((l_data32.getBit<perv::FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC>()
                 ||  l_data32.getBit<perv::FSXCOMP_FSXLOG_ROOT_CTRL0_PIB2PCB_DC>()
                 ||  l_data32.getBit<perv::FSXCOMP_FSXLOG_ROOT_CTRL0_PCB2PCB_DC>())         &&
                !(l_data32.getBit<perv::FSXCOMP_FSXLOG_ROOT_CTRL0_FSI2PCB_DC>())            &&
                !(l_data64.getBit<proc::TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION2_FENCE_DC>())    &&
                !(l_data64.getBit<proc::TP_TPCHIP_TPC_CPLT_CTRL1_TC_REGION1_FENCE_DC>())    &&
                !(l_data64_sl_clk_status.getBit<proc::TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL>())))
        {
            FAPI_ERR("Invalid Mux config(RC0 bits 16,18,19): %#010lX or Fence setup(CPLT_CTRL1 bits 5(sbe),6(pib)): %#018lX or pib clocks not started: %#018lX to perform pibmem dump. \n",
                     l_data32, l_data64, l_data64_sl_clk_status);
            goto fapi_try_exit;
        }
    }

    /// The below code enables/disables ECC checking before doing Dump based on inputs from USER.
    FAPI_TRY(getScom(i_target, PIBMEM_CTRL_REG, original_ctrl_data), "Error in Reading Control Register");

    if(ecc_enable == true)
    {
        ctrl_data = original_ctrl_data & 0xdfffffffffffffff;
        FAPI_TRY(putScom(i_target, PIBMEM_CTRL_REG, ctrl_data), "Error in Writing Control Register");
    }
    else
    {
        ctrl_data = original_ctrl_data | 0x2000000000000000;
        FAPI_TRY(putScom(i_target, PIBMEM_CTRL_REG, ctrl_data), "Error in Writing Control Register");
    }

    /// End of code for Enabling/Disabling ECC Checks

    start_address  = (start_byte / 8) + PIBMEM_START_ARRAY_ADDRESS;
    end_address    = (((start_byte + num_of_byte - 1)) / 8) + PIBMEM_START_ARRAY_ADDRESS;
    num_of_address = (end_address - start_address) + 1;

    if(input_switches == INTERMEDIATE_TILL_INTERMEDIATE)
    {}
    else if(input_switches == START_TILL_INTERMEDIATE)
    {
        start_address  = PIBMEM_START_ARRAY_ADDRESS;
    }
    else if(input_switches == INTERMEDIATE_TILL_END )
    {
        num_of_address = (DEPTH_OF_ARRAY + PIBMEM_START_ARRAY_ADDRESS) - start_address;
    }
    else if(input_switches == START_TILL_END)
    {
        start_address  = PIBMEM_START_ARRAY_ADDRESS;
        num_of_address = DEPTH_OF_ARRAY;
    }

    for( i = 0 ; i < num_of_address ; i++)
    {
        FAPI_TRY(getScom(i_target, start_address + i, l_data64), "Error in Reading Array");
        fetch_data.read_addr = start_address + i;
        fetch_data.read_data = l_data64;
        pibmem_contents.push_back(fetch_data);
    }

    /// Code to restore the PIBMEM Control Register to Original Value
    FAPI_TRY(putScom(i_target, PIBMEM_CTRL_REG, original_ctrl_data), "Error in Writing Control Register");
    /// End of Code to restore PIBMEM Control Register's Value

fapi_try_exit:
    return fapi2::current_err;
}
