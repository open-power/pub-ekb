/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/plat/i2c_access.H $                        */
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

/// @file i2c_access.H
///
/// @brief I2C access functions that needs to be specialized for
/// platform implementation.
///

#ifndef _FAPI2_I2C_ACCESS_H_
#define _FAPI2_I2C_ACCESS_H_

#include <plat_i2c_access.H>
#include <fapi2_i2c_access.H>

namespace fapi2
{
///
/// @brief Platform-level implementation of getI2c()
/// @tparam K the type (Kind) of target, from i_target
/// @tparam V the type of the target's Value, from i_target
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_get_size   Size that getI2c will read from the HW target.
/// @param[in]  i_data       Buffer that holds data to write to the HW target.
///                          May be empty if no address/command is required
///                          before the read.
/// @param[out] o_data       Buffer that holds data read from HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, typename V >
inline ReturnCode getI2c(const Target<K, V>& i_target,
                         const size_t i_get_size,
                         const std::vector<uint8_t>& i_data,
                         std::vector<uint8_t>& o_data)
{
    uint8_t l_size = static_cast<uint8_t>(i_get_size) - 1;

    o_data.clear();
    o_data.push_back(l_size);

    for (uint8_t i = 0; i < l_size; i++)
    {
        o_data.push_back(i);
    }

    std::cout << std::hex << "   getI2c "
              << "target: {" << i_target.getType() << ","
              << uint64_t(i_target) << "}; "
              << "i_get_size: " << i_get_size << "; "
              << "i_data: ";

    const uint32_t l_mask = 0xff;

    for (const auto l_byte : i_data)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (l_mask & l_byte);
    }

    std::cout << "; " << std::dec << std::endl;


    return FAPI2_RC_SUCCESS;
}

///
/// @brief Platform-level implementation of putI2c()
/// @tparam K the type (Kind) of target, from i_target
/// @tparam V the type of the target's Value, from i_target
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_data       Buffer that holds data to write to the HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, typename V >
inline ReturnCode putI2c(const Target<K, V>& i_target,
                         const std::vector<uint8_t>& i_data)
{
    std::cout << std::hex << "   putI2c "
              << "target: {" << i_target.getType() << ","
              << uint64_t(i_target) << "}; "
              << "i_data: ";

    const uint32_t l_mask = 0xff;

    for (const auto l_byte : i_data)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (l_mask & l_byte);
    }

    std::cout << "; " << std::dec << std::endl;

    return FAPI2_RC_SUCCESS;
}

};

#endif // _FAPI2_I2C_ACCESS_H_
