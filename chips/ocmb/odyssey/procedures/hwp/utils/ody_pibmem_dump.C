/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_pibmem_dump.C $   */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2020,2024                                                    */
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
/// @file  ody_pibmem_dump.C
/// @brief Dump PIBMEM's Array Data in Structure.
///
/// *HW Owner    : Sreekanth Reddy
/// *FW Owner    :
/// *Team        : Pervasive

// ------------------------------------- Mux configs-------------------------------------------------------------
// FSI2PCB(16)                 PIB2PCB(18)                   PCB2PCB(19)          cannot access       can access
//    1                           0                             0                      PIB             EPS - perv
//    0                           1                             0                      PCB             PIB, SBE, EPS
//    0                           0                             1                       -              PIB, PCB n/w
// -------------------------------------------------------------------------------------------------------------------

#include <ody_pibmem_dump.H>
#include <poz_scom_perv.H>

SCOMT_PERV_USE_FSXCOMP_FSXLOG_ROOT_CTRL0;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_SB_CS;
SCOMT_PERV_USE_FSXCOMP_FSXLOG_CBS_CS;
static const uint32_t ODY_PIBMEM_START_ARRAY_ADDRESS   = 0xFFF80000;
static const uint32_t ODY_DEPTH_OF_PIBMEM              = 0x00080000;
static const uint32_t PIBMEM_CTRL_REG                  = 0x000D0010;
static const uint32_t PIBMEM_ADDR_REG                  = 0x000D0011;
static const uint32_t PIBMEM_AUTO_INCR_REG             = 0x000D0013;
static const uint32_t ODY_PIBMEM_ADDR_OFFSET           = 0xFFF80000;
static const uint64_t TPCHIP_CLOCK_STAT_SL = 0x01030008;
static const uint64_t TPCHIP_CPLT_CTRL1    = 0x01000001;

using namespace fapi2;
using namespace scomt::poz;

fapi2::ReturnCode ody_pibmem_dump(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint32_t i_start_byte,
    const uint32_t i_num_of_byte,
    const usr_options i_input_switches,
    const bool i_ecc_enable,
    std::vector<pibmem_array_data_t>& o_pibmem_contents)
{
    uint32_t start_address, num_of_address, end_address;
    uint32_t pibmem_indirect_addr;
    uint32_t PIBMEM_START_ARRAY_ADDRESS = ODY_PIBMEM_START_ARRAY_ADDRESS;
    uint32_t DEPTH_OF_ARRAY = ODY_DEPTH_OF_PIBMEM;
    bool sab, sdb;
    pibmem_array_data_t fetch_data;
    fapi2::buffer<uint64_t> l_data64, l_data64_sl_clk_status, pibmem_ctrl_reg_data_org;
    fapi2::buffer<uint64_t> ctrl_reg_data;
    FSXCOMP_FSXLOG_SB_CS_t      SB_CS;
    FSXCOMP_FSXLOG_CBS_CS_t     CBS_CS;
    FSXCOMP_FSXLOG_ROOT_CTRL0_t ROOT_CTRL0;

    FAPI_DBG("Entering...");
    FAPI_DBG("Release PCB reset");
    ROOT_CTRL0 = 0;
    ROOT_CTRL0.set_PCB_RESET(1);
    FAPI_TRY(ROOT_CTRL0.putCfam_CLEAR(i_target));

    FAPI_TRY(ROOT_CTRL0.getCfam(i_target));
    FAPI_TRY(SB_CS.getCfam(i_target));
    FAPI_TRY(CBS_CS.getCfam(i_target));

    sab = CBS_CS.get_SECURE_ACCESS_BIT();
    sdb = SB_CS.get_SECURE_DEBUG_MODE();

    if(sab && !sdb)
    {
        FAPI_ERR("PIBMEM can not be accessed in secure mode without setting secure debug bit");
        goto fapi_try_exit;
    }

    if(!sab)
    {
        FAPI_TRY(fapi2::getScom(i_target, TPCHIP_CPLT_CTRL1, l_data64));
        FAPI_TRY(fapi2::getScom(i_target, TPCHIP_CLOCK_STAT_SL, l_data64_sl_clk_status));

        // RC0bits 16,18,19 != 000 && RC0bit16 != 1 && cplt_ctrl[ pib(bit6) sbe(bit5)] != 1 && checking if pib clocks are started
        if (!((ROOT_CTRL0.get_PIB2PCB()
               ||  ROOT_CTRL0.get_PCB2PCB())         &&
              !(ROOT_CTRL0.get_FSI2PCB())            &&
              !(l_data64.getBit<CPLT_CTRL1_REGION2_FENCE>())    &&
              !(l_data64.getBit<CPLT_CTRL1_REGION1_FENCE>())    &&
              !(l_data64_sl_clk_status.getBit<CLOCK_STAT_SL_UNIT2_SL>())))
        {
            FAPI_ERR("Invalid Mux config(RC0 bits 16,18,19): %#010lX or Fence setup(CPLT_CTRL1 bits 5(sbe),6(pib)): %#018lX or pib clocks not started: %#018lX to perform pibmem dump. \n",
                     ROOT_CTRL0, l_data64, l_data64_sl_clk_status);
            goto fapi_try_exit;
        }
    }

    /// The below code enables/disables ECC checking before doing Dump based on inputs from USER.
    FAPI_TRY(getScom(i_target, PIBMEM_CTRL_REG, pibmem_ctrl_reg_data_org), "Error in reading PIBMEM control register");

    if(i_ecc_enable == true)
    {
        ctrl_reg_data = pibmem_ctrl_reg_data_org & 0xdfffffffffffffff;
        FAPI_TRY(putScom(i_target, PIBMEM_CTRL_REG, ctrl_reg_data), "Error in writing PIBMEM control register");
    }
    else
    {
        ctrl_reg_data = pibmem_ctrl_reg_data_org | 0x2000000000000000;
        FAPI_TRY(putScom(i_target, PIBMEM_CTRL_REG, ctrl_reg_data), "Error in writing PIBMEM control register");
    }

    /// End of code for Enabling/Disabling ECC Checks

    start_address  = (i_start_byte / 8) + PIBMEM_START_ARRAY_ADDRESS;
    end_address    = (((i_start_byte + i_num_of_byte - 1)) / 8) + PIBMEM_START_ARRAY_ADDRESS;
    num_of_address = (end_address - start_address) + 1;

    if(i_input_switches == INTERMEDIATE_TO_INTERMEDIATE)
    {}
    else if(i_input_switches == START_TO_INTERMEDIATE)
    {
        start_address  = PIBMEM_START_ARRAY_ADDRESS;
    }
    else if(i_input_switches == INTERMEDIATE_TO_END )
    {
        num_of_address = (DEPTH_OF_ARRAY + PIBMEM_START_ARRAY_ADDRESS) - start_address;
    }
    else if(i_input_switches == START_TO_END)
    {
        start_address  = PIBMEM_START_ARRAY_ADDRESS;
        num_of_address = DEPTH_OF_ARRAY;
    }

    // Indirect mode of accessing PIBMEM
    pibmem_indirect_addr = (start_address - ODY_PIBMEM_ADDR_OFFSET) >> 3;

    FAPI_TRY(putScom(i_target, PIBMEM_ADDR_REG, pibmem_indirect_addr));

    for(uint32_t i = 0; i < num_of_address; i++)
    {
        FAPI_TRY(getScom(i_target, PIBMEM_AUTO_INCR_REG, l_data64));
        fetch_data.rd_addr = start_address + i;
        fetch_data.rd_data = l_data64;
        o_pibmem_contents.push_back(fetch_data);
    }

    /// Code to restore the PIBMEM Control Register to Original Value
    FAPI_TRY(putScom(i_target, PIBMEM_CTRL_REG, pibmem_ctrl_reg_data_org), "Error in writing PIBMEM control register");
    /// End of Code to restore PIBMEM Control Register's Value

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}
