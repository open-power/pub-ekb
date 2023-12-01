/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_sbe_localreg_dump.H $ */
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
/// @file  ody_sbe_localreg_dump.H
/// @brief Dump a PPE engine's state.
///
/// *HW Owner    : Pradeep CN
/// *FW Owner    :
/// *Team        : Pervasive
/// *Consumed by : TBD
/// *Level       : my
///


#ifndef __ODY_SBE_LOCALREG_DUMP_H__
#define __ODY_SBE_LOCALREG_DUMP_H__
typedef struct
{
    uint16_t     number;
    std::string  name;
} SBEReg_t;

typedef struct
{
    SBEReg_t    reg;
    uint32_t    value;
} SBERegValue_t;

typedef struct
{
    SBEReg_t    reg;
    uint64_t    value;
} SBESCOMRegValue_t;


/// @typedef p10_sbe_localreg_dump_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*ody_sbe_localreg_dump_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&, const uint16_t force_halt , std::vector<SBESCOMRegValue_t>& );


extern "C"
{

/// @brief Dump the local registers of entire SBE
/// @param [in] i_target TARGET_TYPE_PROC_CHIP
/// @param [out] v_sbe_local_reg_value vector of register values
/// @return FAPI2_RC_SUCCESS
    fapi2::ReturnCode
    ody_sbe_localreg_dump(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target , const uint16_t force_halt ,
                          std::vector<SBESCOMRegValue_t>& v_sbe_local_reg_value
                         );

} // extern C

#endif  // __P10_SBE_LOCALREG_DUMP_H__
