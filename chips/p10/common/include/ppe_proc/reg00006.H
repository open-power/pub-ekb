/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/common/include/ppe_proc/reg00006.H $                */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2020                                                         */
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
#include "fapi2.H"

#ifndef __PPE_PROC_REG00006_H_
#define __PPE_PROC_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace ppe_proc
{
#endif


template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}

template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}


static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_START1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBE_INTR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_DRTM_REQ chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_TRIG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_RESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}

static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}

static inline bool GET_TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_RW, TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_CLEAR,
                           TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("Invalid dial access TP_TPCHIP_PIB_SBE_SBEPM_LCL_EISR_SBEHFIFO_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}


#ifndef __PPE_HCODE__
}
}

#endif
#endif
