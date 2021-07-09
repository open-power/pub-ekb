/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/istep/p10_do_fw_hb_istep.C $         */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2019,2021                                                    */
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
/// @file p10_do_fw_hb_istep.C
/// @brief Execute hostboot isteps from istep mode by writing to mailbox scratch
///        register 4.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Matt Raybuck <matthew.raybuck@ibm.com>
/// *HWP Consumed by: 3rd Parties such as OpenBMC, Cronus, FSP, etc.
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#include "p10_do_fw_hb_istep.H"
#include "p10_scom_proc.H"

using namespace scomt::proc;

typedef fapi2::buffer<uint32_t> mbox4_buffer_t;

union IStep_Command_t
{
    uint32_t value;
    struct bytes
    {
#ifdef _BIG_ENDIAN
        uint32_t key         : 8;
        uint32_t status      : 8;
        uint32_t istep_major : 8;
        uint32_t istep_minor : 8;
#else
        uint32_t istep_minor : 8;
        uint32_t istep_major : 8;
        uint32_t status      : 8;
        uint32_t key         : 8;
#endif
    } byte;

    IStep_Command_t() : value(0) {};
};

const uint8_t  KEY_SHIFT_AMOUNT = 24;
const uint8_t  STATUS_SHIFT_AMOUNT = 16;
const uint32_t HOSTBOOT_STATUS_BITS = 0x00FF0000;

/* @brief Small helper function to get the key value from the mailbox buffer.
 *
 * @param[in]      i_mboxBuffer   The buffer to extract the key from.
 *
 * @return         uint8_t        The key.
 */
inline uint8_t getKey(const mbox4_buffer_t i_mboxBuffer)
{
    return (i_mboxBuffer >> KEY_SHIFT_AMOUNT);
}

/* @brief Small helper function to get the hostboot status value from the
 *        mailbox buffer.
 *
 * @param[in]      i_mboxBuffer   The buffer to extract the status from.
 *
 * @return         uint8_t        The status value.
 */
inline uint8_t getHbStatus(const mbox4_buffer_t i_mboxBuffer)
{
    return ((i_mboxBuffer & HOSTBOOT_STATUS_BITS) >> STATUS_SHIFT_AMOUNT);
}

fapi2::ReturnCode p10_do_fw_hb_istep(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_istepMajor,
    const uint8_t i_istepMinor,
    const uint64_t i_retry_limit_ms,
    const uint64_t i_delay_ms,
    const uint64_t i_delay_simCycles)
{
    mbox4_buffer_t mboxBuffer{0};
    IStep_Command_t istep;
    uint8_t key = 0;
    uint8_t hb_err = 0;
    uint64_t elapsedTimeMs = 0;

    const uint8_t  RUNNING_BIT = 0x20;
    const uint8_t  GO_BIT      = 0x40;
    const uint8_t  READY_BIT   = 0x80;
    const uint32_t NS_PER_MS   = 1000000;

    FAPI_INF("p10_do_fw_istep: Execute istep %d, substep %d",
             i_istepMajor,
             i_istepMinor);

    // Wait for hostboot to be ready
    do
    {
        // Read the key from the register
        FAPI_TRY(
            fapi2::getCfamRegister(
                i_target,
                TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI,
                mboxBuffer),
            "Error from getCfamRegister for "
            "TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI");

        // Extract the key from the buffer.
        key = getKey(mboxBuffer);

        fapi2::delay(i_delay_ms * NS_PER_MS, i_delay_simCycles);
        elapsedTimeMs += i_delay_ms;
    }
    while (!(key & READY_BIT) && (elapsedTimeMs <= i_retry_limit_ms));

    FAPI_ASSERT((elapsedTimeMs <= i_retry_limit_ms),
                fapi2::DO_FW_HB_ISTEP_NOT_READY()
                .set_TARGET(i_target)
                .set_KEY(key)
                .set_RETRY_LIMIT_MS(i_retry_limit_ms),
                "Ready bit for istep mode wasn't set in %" PRIu64 " ms",
                i_retry_limit_ms);

    // Set the go bit for the key.
    key = (GO_BIT | key);

    // Setup the buffer for the requested istep to execute
    istep.byte.key = key;
    istep.byte.istep_major = i_istepMajor;
    istep.byte.istep_minor = i_istepMinor;

    mboxBuffer = istep.value;

    // Execute the istep by writing to the mailbox register
    FAPI_TRY(
        fapi2::putCfamRegister(
            i_target,
            TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI,
            mboxBuffer),
        "Error from putCfamRegister from "
        "TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI");

    fapi2::delay(i_delay_ms * NS_PER_MS, i_delay_simCycles);

    // Wait for the command to complete.
    elapsedTimeMs = 0;

    do
    {
        // Read the key from the register
        FAPI_TRY(
            fapi2::getCfamRegister(
                i_target,
                TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI,
                mboxBuffer),
            "Error from getCfamRegister from "
            "TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI");

        // Extract the key from the buffer.
        key = getKey(mboxBuffer);

        // Extract the error from the buffer.
        hb_err = getHbStatus(mboxBuffer);
        FAPI_ASSERT((hb_err == 0),
                    fapi2::DO_FW_HB_ISTEP_BAD_HOSTBOOT_STATUS()
                    .set_TARGET(i_target)
                    .set_STATUS(hb_err),
                    "Received non-zero value from hostboot istep status reg: 0x%X",
                    hb_err);

        // Check if the istep command has completed. By checking both the READY
        // and the GO bit it is ensured that SPTask has executed the istep
        // because once the step is completed the GO_BIT is unset.
        //
        // If only the READY_BIT is checked and there aren't sufficient delays
        // prior to checking then we could mistakenly believe that the step was
        // complete and return too soon thus allowing further commands to be
        // written to the mbox before it is ready.
        if ((key & READY_BIT) && !(key & GO_BIT))
        {
            // Command is complete
            break;
        }

        fapi2::delay(i_delay_ms * NS_PER_MS, i_delay_simCycles);
        elapsedTimeMs += i_delay_ms;
    }
    while (((key & RUNNING_BIT) || (key & GO_BIT))
           && (elapsedTimeMs <= i_retry_limit_ms));

    FAPI_ASSERT((elapsedTimeMs <= i_retry_limit_ms),
                fapi2::DO_FW_HB_ISTEP_COMMAND_COMPLETION_TIMEOUT()
                .set_TARGET(i_target)
                .set_KEY(key)
                .set_HB_STATUS(hb_err)
                .set_ISTEP_MAJOR(i_istepMajor)
                .set_ISTEP_MINOR(i_istepMinor)
                .set_MAX_RETRY_TIME_MS(i_retry_limit_ms)
                .set_DELAY_MS(i_delay_ms)
                .set_SIM_CYCLES_DELAY_MS(i_delay_simCycles),
                "Requested istep %d.%d failed to complete in %" PRIu64 " ms",
                i_istepMajor,
                i_istepMinor,
                i_retry_limit_ms);

fapi_try_exit:
    FAPI_INF("p10_do_fw_istep: Exit");
    return fapi2::current_err;
}
