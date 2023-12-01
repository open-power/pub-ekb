/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_sbe_localreg_dump.C $ */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2015,2024                                                    */
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
/// @file ody_sbe_localreg_dump.C
/// @brief

// *HWP HWP Owner       : Pradeep CN <pradeepcn@in.ibm.com>
// *HWP Backup HWP Owner: Anay K Desai
// *HWP FW Owner        :
// *HWP Team            : PERV
// *HWP Level           : 2
// *HWP Consumed by     :

///
/// High-level procedure flow:
/// @verbatim
/// High-level procedure flow:
///
///
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>


#include <ody_ppe_utils.H>
#include <ody_sbe_localreg_dump.H>

// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------

// these are probably in some include file


enum SBE_LREGS
{

    SBE_MISC     = 0x2000 ,
    SBE_EISR     = 0x0000 ,
    SBE_EIMR     = 0x0020 ,
    SBE_EIPR     = 0x0040 ,
    SBE_EITR     = 0x0060 ,
    SBE_EISTR    = 0x0080 ,
    SBE_EINR     = 0x00A0 ,
    SBE_TSEL     = 0x0100 ,
    SBE_DBG      = 0x0120 ,
    SBE_TBR      = 0x0140 ,
    SBE_IVPR     = 0x0160 ,
    SBE_LFR0     = 0x2040 ,
    SBE_LFR1     = 0x2060


};

std::vector<SBEReg_t> v_ody_sppe_local_regs =
{

    { SBE_MISC,      "SBE_MISC" },
    { SBE_EISR,      "SBE_EISR" },
    { SBE_EIMR,      "SBE_EIMR" },
    { SBE_EIPR,      "SBE_EIPR" },
    { SBE_EITR,      "SBE_EITR" },
    { SBE_EISTR,     "SBE_EISTR" },
    { SBE_EINR,      "SBE_EINR" },
    { SBE_TSEL,      "SBE_TSEL" },
    { SBE_DBG,       "SBE_DBG" },
    { SBE_TBR,       "SBE_TBR" },
    { SBE_IVPR,      "SBE_IVPR" },
    { SBE_LFR0,      "SBE_LFR0" },
    { SBE_LFR1,      "SBE_LFR1" },
};



// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// @brief Dump the contents of the SBE SRAM
///
/// @param [in]  i_target                  Chip target
/// @param [out] v_sbe_local_reg_value     Vector of structure of LocalReg
///
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode ody_sbe_localreg_dump( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target ,
        const uint16_t force_halt,
        std::vector<SBESCOMRegValue_t>& v_sbe_local_reg_value)

{
    fapi2::buffer<uint64_t> l_data64;
    SBESCOMRegValue_t l_regVal;
    uint16_t address = 0 ;
    uint32_t scom_address = 0 ;
    uint64_t t_addr;

    FAPI_INF("Executing ody_sbe_localreg_dump " );
    fapi2::buffer<uint32_t> l_gpr0_save;
    fapi2::buffer<uint32_t> l_gpr1_save;
    fapi2::buffer<uint32_t> l_gpr9_save;
    fapi2::buffer<uint64_t> l_sprg0_save;
    fapi2::buffer<uint64_t> buf;

    if (force_halt == 0)
    {
        FAPI_TRY(poll_ppe_halt_state(i_target , PPE_TYPE_SBE, 0));
    }
    else
    {
        FAPI_INF("Forcing halt thruough SCOM");
        FAPI_TRY(halt_ppe(i_target,  PPE_TYPE_SBE, 0));
        FAPI_TRY(poll_ppe_halt_state(i_target, PPE_TYPE_SBE, 0));
    }

    // If SBE is not in halt state
    FAPI_INF("Reading XIRAMDBG after polling");
    t_addr = ppe_get_xir_addr(PPE_TYPE_SBE, PPE_IDX_XIRAMDBG, 0);
    FAPI_TRY(getScom(i_target, t_addr, buf), "Error in GETSCOM");

    if (!buf.getBit<0>())
    {
        FAPI_INF("PPE is not in HALT state");

        for (auto it : v_ody_sppe_local_regs)
        {
            // ******************************************************************
            scom_address = 0xC0000000 + it.number ; // defined in enums in p10_ppe_common.H files
            FAPI_TRY(getScom(i_target , scom_address , buf ));

            //  FAPI_INF(" %-6s : Local_reg_addr :  0xC000_%04x :  0x%016lX \n",it.name.c_str() , it.number , buf);
            l_regVal.reg = it;
            l_regVal.value = buf;
            v_sbe_local_reg_value.push_back(l_regVal);
            // ******************************************************************
        }
    }
    else //If SBE is in halt state
    {
        FAPI_INF("PPE is in HALT state");

        FAPI_TRY(ppe_save_sprg0_gprs(i_target , PPE_TYPE_SBE, 0, l_gpr0_save, l_gpr1_save, l_gpr9_save, l_sprg0_save ));

        for (auto it : v_ody_sppe_local_regs)
        {
            // ******************************************************************
            address = it.number ; // defined in enums in p10_ppe_common.H files
            FAPI_TRY(read_local_ppe_regs(i_target , PPE_TYPE_SBE, 0, address , buf ));

            //  FAPI_INF(" %-6s : Local_reg_addr :  0xC000_%04x :  0x%016lX \n",it.name.c_str() , it.number , buf);
            l_regVal.reg = it;
            l_regVal.value = buf;
            v_sbe_local_reg_value.push_back(l_regVal);
            // ******************************************************************
        }

        FAPI_TRY(ppe_restore_sprg0_gprs(i_target , PPE_TYPE_SBE, 0, l_gpr0_save, l_gpr1_save, l_gpr9_save, l_sprg0_save ));
    }


fapi_try_exit:
    FAPI_INF("< ody_sbe_localreg_dump");
    return fapi2::current_err;
}
