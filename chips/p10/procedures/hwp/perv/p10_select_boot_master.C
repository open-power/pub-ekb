/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/perv/p10_select_boot_master.C $      */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2018,2020                                                    */
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
//------------------------------------------------------------------------------
/// @file  p10_select_boot_master.C
///
/// @brief proc select boot master
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------

#include "p10_select_boot_master.H"
#include <p10_scom_perv_a.H>


fapi2::ReturnCode p10_select_boot_master(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint8_t> l_read_attr;
    fapi2::buffer<uint32_t> l_read_reg;
    FAPI_DBG("p10_select_boot_master: Entering ...");

    FAPI_INF("Reading ATTR_BACKUP_SEEPROM_SELECT");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BACKUP_SEEPROM_SELECT, i_target_chip,
                           l_read_attr));

    // select seeprom image (primary vs secondary) in SBE VITAL
    FAPI_INF("Reading PERV_SB_CS_FSI");
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_SB_CS_FSI, l_read_reg));

    FAPI_INF("select seeprom image (secondary vs primary)");
    (l_read_attr.getBit<7>() == 1) ? l_read_reg.setBit<17>() : l_read_reg.clearBit<17>();

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_SB_CS_FSI, l_read_reg));

    FAPI_DBG("p10_select_boot_master: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
