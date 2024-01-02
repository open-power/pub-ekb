/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/perv/ody_extract_sbe_rc.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2023                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
/// @file  ody_extract_sbe_rc.H
/// @brief Check for errors on the SPPE, OTPROM, PIBMEM & PNOR
//------------------------------------------------------------------------------
// *HWP HW Owner        : Sandeep Korrapati <sakorrap@in.ibm.com>
// *HWP HW Backup Owner : Sreekanth Reddy <skadapal@in.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : FSP:HB
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>

typedef fapi2::ReturnCode (*ody_extract_sbe_rc_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&, bool, bool);

/// @brief To look for any correctable errors on the SPPE, OTPROM, PIBMEM & PNOR.
///
/// @param[in]     i_target           Reference to TARGET_TYPE_OCMB_CHIP target
/// @param[in]     i_set_sdb          To program the chip to set SDB (default True as its most used)
/// @param[in]     i_use_scom         True : prefer scom over OMI interface; False : prefer cfam. (default True)
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode ody_extract_sbe_rc(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                         bool i_set_sdb = true,
                                         bool i_use_scom = true);
}
