/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_pibmem_dump.H $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2020,2023                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file  ody_pibmem_dump.H
/// @brief Dump PIBMEM's Array Data in Structure.
///
/// *HW Owner    : Sreekanth Reddy
/// *FW Owner    :
/// *Team        : Pervasive

#pragma once

#include <fapi2.H>

typedef struct
{
    uint32_t read_addr;
    uint64_t read_data;
} array_data_t;

typedef enum
{
    START_TILL_END = 0,                         // Dump complete PIBMEM Array contents
    INTERMEDIATE_TILL_END = 1,                  // Dump from Address till End of PIBMEM
    START_TILL_INTERMEDIATE = 2,                // Dump from Start till Number of Bytes
    INTERMEDIATE_TILL_INTERMEDIATE = 3          // Dump from Address till Number of Bytes
} user_options;

/// @typedef ody_pibmem_dump_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*ody_pibmem_dump_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    const uint32_t,
    const uint32_t,
    const user_options,
    const bool,
    std::vector<array_data_t>&);

extern "C"
{

/// @brief Dump the PIBMEM Array based on starting and number of address
/// @param [in] i_target TARGET_TYPE_OCMB_CHIP
/// @return FAPI2_RC_SUCCESS
    fapi2::ReturnCode
    ody_pibmem_dump(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                    const uint32_t i_start_byte,
                    const uint32_t i_num_of_byte,
                    const user_options i_input_switches,
                    const bool i_ecc_enable,
                    std::vector<array_data_t>& o_pibmem_contents);

} // extern C
