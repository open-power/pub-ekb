/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/istep/p10_do_fw_hb_istep.H $         */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2019,2020                                                    */
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
/// @file p10_do_fw_hb_istep.H
/// @brief Execute hostboot isteps from istep mode by writing to mailbox scratch
///        register 4.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Matt Raybuck <matthew.raybuck@ibm.com>
/// *HWP Consumed by: 3rd Parties such as OpenBMC, Cronus, FSP, etc.
#ifndef _P10_DO_FW_HB_ISTEP_H_
#define _P10_DO_FW_HB_ISTEP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*p10_do_fw_hb_istep_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t i_istepMajor,
    uint8_t i_stepMinor,
    uint64_t i_retry_limit_ms,
    uint64_t i_delay_ms,
    uint64_t i_delay_simCycles);

extern "C"
{
    /*
     * @brief This hardware procedure will accept a given processor target and
     *        hostboot istep and execute it. Optionally, the procedure will accept
     *        delays and retry times to allow hostboot enough time to complete the
     *        istep. The user is responsible for giving the procedure sensible
     *        inputs. Procedure expects target to be master processor. Only a single
     *        istep will be executed per call to this procedure.
     *
     * @param[in]      i_target            The master processor to run the istep on.
     *
     * @param[in]      i_istepMajor        The major IStep number to be executed.
     *
     * @param[in]      i_istepMinor        The minor IStep number to be executed.
     *
     * @param[in opt]  i_retry_limit_ms    The amount of ms to wait for hostboot to
     *                                     become ready and for the istep to
     *                                     complete.
     *
     * @param[in opt]  i_delay_ms          Time in ms to wait between polling
     *                                     retries.
     *
     * @param[in opt]  i_delay_simCycles   Count of Awan cycles to advance.
     */
    fapi2::ReturnCode p10_do_fw_hb_istep(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        uint8_t i_istepMajor,
        uint8_t i_stepMinor,
        uint64_t i_retry_limit_ms  = 2500,
        uint64_t i_delay_ms        = 100,
        uint64_t i_delay_simCycles = 1000);
} //extern C

#endif
