/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_pibms_reg_dump.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016,2023                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file  ody_pibms_reg_dump.H
/// @brief Dump contents of various PIB Masters and Slaves internal registers.
///
/// *HW Owner    : Swathi PS
/// *FW Owner    :
/// *Team        : Pervasive
/// *Consumed by : TBD
/// *Level       :
///
//
// Change History:
// 02/08/2023:  Copied from p10_pibms_reg_dump, changed to use in ODY
//

#ifndef __ODY_PIBMS_REG_DUMP_H__
#define __ODY_PIBMS_REG_DUMP_H__


/// @typedef p9_sbe_localreg_dump_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*ody_pibms_reg_dump_FP_t)
(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    std::vector<sRegV>& regv_set);

extern "C"
{

/// @brief Dump all internal register contents of PIB Masters and Slaves
/// @param [in] i_target TARGET_TYPE_PROC_CHIP
/// @param [in] i_base_address Base offset to be used for all accesses
/// @return FAPI2_RC_SUCCESS
    fapi2::ReturnCode
    ody_pibms_reg_dump(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                       std::vector<sRegV>& regv_set);

} // extern C

#endif
