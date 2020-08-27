/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/lib/p10_pibms_reg_dump.C $           */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2015,2021                                                    */
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
/// @file p9_pibms_reg_dump.C
/// @brief Dump PIB Masters and Slaves Internal Register contents
//
// Change History:
// 03/28/2019:  Copied from p9_pibms_reg_dump, changed to use in P10
//

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <pibms_regs2dump.H>
#include <p10_pibms_reg_dump.H>
#include "p10_scom_perv_2.H"
#include "p10_scom_perv_7.H"
#include "p10_scom_proc_0.H"
#include "p10_scom_proc_4.H"
#include <string>

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// @brief Dump the contents of PIB Masters and Slaves Internal Registers
///
/// @param [in]  i_target             Chip target
///
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode p10_pibms_reg_dump( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                      std::vector<sRegV>& regv_set)
{
    using namespace scomt;

    fapi2::buffer<uint32_t> l_data32_cbs_cs;
    fapi2::buffer<uint32_t> l_data32_sb_cs;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint64_t> l_data64_sl_clk_status;
    uint64_t addr;
    bool sdb, pib_clks_not_running, net_clks_not_running;
    std::string reg_name;

    FAPI_INF("Executing p10_pibms_reg_dump");

    fapi2::buffer<uint64_t> buf;

    FAPI_TRY(fapi2::getCfamRegister(i_target, PERV_CBS_CS_FSI, l_data32_cbs_cs));  //0x2801
    FAPI_TRY(fapi2::getCfamRegister(i_target, PERV_SB_CS_FSI, l_data32_sb_cs));    //0x2808

    FAPI_DBG("Release PCB reset");
    l_data32.flush<0>().setBit<perv::FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
    FAPI_TRY(putCfamRegister(i_target, perv::FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, l_data32 ));
    // only dump registers can be accessed in secure debug mode
    // PERV_CBS_CS_SECURE_ACCESS_BIT = 4,  PERV_SB_CS_SECURE_DEBUG_MODE = 0
    sdb = (l_data32_cbs_cs.getBit<BIT04>() && l_data32_sb_cs.getBit<BIT00>());

    if(l_data32_cbs_cs.getBit<BIT04>() && !l_data32_sb_cs.getBit<BIT00>())
    {
        FAPI_ERR("PIB Master Slave registers can not be accessed in secure mode without setting secure debug bit");
        goto fapi_try_exit;
    }

    if(!l_data32_cbs_cs.getBit<BIT04>())
    {

        FAPI_TRY(getScom(i_target, proc::TP_TPCHIP_TPC_CLOCK_STAT_SL, l_data64_sl_clk_status));

        pib_clks_not_running = l_data64_sl_clk_status.getBit<proc::TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT2_SL>();
        net_clks_not_running = l_data64_sl_clk_status.getBit<proc::TP_TPCHIP_TPC_CLOCK_STAT_SL_UNIT4_SL>();
    }
    else
    {
        pib_clks_not_running = false;
        net_clks_not_running = false;
    }


    if (sdb)
    {
        FAPI_INF("In secure debug mode");
    }

    if (regv_set.size())
    {
        for (std::vector<sRegV>::iterator itr = regv_set.begin(); itr != regv_set.end(); ++itr)
        {
            if (!sdb || ((itr->reg).attr & SDB_ATTR))    //only read registers can be accessed in secure debug mode
            {
                addr = (itr->reg).addr;
                reg_name = (itr->reg).name;

                if( ! (pib_clks_not_running && ((reg_name.find("PIBMEM") != std::string::npos)
                                                || (reg_name.find("PSU") != std::string::npos))) &&
                    ! (net_clks_not_running && (reg_name.find("PCBM") != std::string::npos)))
                {
                    FAPI_TRY((getScom(i_target , addr , buf)));
                    itr->value = buf;
                    //mark value is valid
                    (itr->reg).attr |= VLD_ATTR;
                }
            }
        }
    }

fapi_try_exit:
    FAPI_INF("Exiting p10_pibms_reg_dump");
    return fapi2::current_err;
}
