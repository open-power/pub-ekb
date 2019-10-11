/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/lib/p10_pibms_reg_dump.H $           */
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
/// @file  p9_pibms_reg_dump.H
/// @brief Dump contents of various PIB Masters and Slaves internal registers.
///
/// *HW Owner    : Anay K Desai
/// *HW Owner    : Pradeep Chatnahali
/// *FW Owner    :
/// *Team        : Pervasive
/// *Consumed by : TBD
/// *Level       :
///
//
// Change History:
// 03/28/2019:  Copied from p9_pibms_reg_dump, changed to use in zThemis
//

#ifndef __P10_PIBMS_REG_DUMP_H__
#define __P10_PIBMS_REG_DUMP_H__


/// @typedef p9_sbe_localreg_dump_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pibms_reg_dump_FP_t)
(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    std::vector<sRegV>& regv_set);

extern "C"
{

/// @brief Dump all internal register contents of PIB Masters and Slaves
/// @param [in] i_target TARGET_TYPE_PROC_CHIP
/// @param [in] i_base_address Base offset to be used for all accesses
/// @return FAPI2_RC_SUCCESS
    fapi2::ReturnCode
    p10_pibms_reg_dump(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       std::vector<sRegV>& regv_set);

} // extern C

#endif
