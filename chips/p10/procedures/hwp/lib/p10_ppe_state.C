/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/lib/p10_ppe_state.C $                */
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
/// @file  p10_ppe_state.C
/// @brief Get PPE's internal state
///
/// *HWP HW Owner        : Greg Still <stillgs.@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : SBE, Cronus
///
/// @verbatim
///
/// Procedure Summary:
///   - Dump out PPE's internal state
///
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_ppe_state.H>
#include <p10_ppe_utils.H>
#include <p10_ppe_instance_defs.H>
#include <p10_hcd_common.H>

// Vector defining the GPRs
std::vector<enum PPE_REGS> v_ppe_gprs =
{
    { PPE_R0 },
    { PPE_R1 },
    { PPE_R2 },
    { PPE_R3 },
    { PPE_R4 },
    { PPE_R5 },
    { PPE_R6 },
    { PPE_R7 },
    { PPE_R8 },
    { PPE_R9 },
    { PPE_R10},
    { PPE_R13},
    { PPE_R28},
    { PPE_R29},
    { PPE_R30},
    { PPE_R31},
};

// Vector defining the SPRs that are read through ramming
std::vector<enum PPE_REGS> v_ppe_sprs_ram =
{
    { PPE_DACR },
    { PPE_DBCR },
    { PPE_DEC },
    { PPE_ISR },
    { PPE_IVPR },
    { PPE_PIR },
    { PPE_PVR },
    { PPE_SRR1 },
    { PPE_TCR },
    { PPE_TSR },
    { PPE_XER },
};
//-----------------------------------------------------------------------------

/**
 * @brief Perform PPE internal reg "read" operation
 * @param[in]   i_target        Chip Target
 * @param[in]   i_base_address  Base SCOM address of the PPE
 * @param[in]   i_mode          PPE Dump Mode
 * @param[out]  v_ppe_minor_sprs_value   Returned data
 * @param[out]  v_ppe_major_sprs_value   Returned data
 * @param[out]  v_ppe_xirs_value   Returned data
 * @param[out]  v_ppe_gprs_value   Returned data
 * @param[out]  v_ppe_special_sprs_value   Returned data
 * @return  fapi2::ReturnCode
 */
fapi2::ReturnCode
ppe_state_data(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               enum PPE_TYPES i_ppe_type,
               uint32_t i_ppe_instance_num,
               const PPE_DUMP_MODE i_mode,
               std::vector<Reg32Value_t>& v_ppe_gprs_value,
               std::vector<Reg32Value_t>& v_ppe_sprs_value,
               std::vector<Reg32Value_t>& v_ppe_xirs_value)
{
    fapi2::buffer<uint64_t> l_raminstr;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_gpr0_save;
    fapi2::buffer<uint64_t> l_sprg0_save;
    bool l_ppe_halt_state = false;
    Reg32Value_t l_regVal;
    uint64_t t_addr;

    char outstr[32];

    FAPI_INF("PPE Type: %s Base Address : 0x%08llX", G_PPE_Types[i_ppe_type].name,
             G_PPE_Types[i_ppe_type].base_address);

    //Halt the engine if requested
    if (i_mode == HALT)
    {
        FAPI_TRY(ppe_halt(i_target, i_ppe_type, i_ppe_instance_num));
    }

    if (i_mode == FORCE_HALT)
    {
        FAPI_TRY(ppe_force_halt(i_target, i_ppe_type, i_ppe_instance_num));
    }

    ///////////////////////////////////////////////////////////////////////////
    //XIRs
    ///////////////////////////////////////////////////////////////////////////
    FAPI_INF("------   XIRs   ------");
    //XIXCR     - XCR(Write-only) and CTR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "CTR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_CTR);
    l_regVal.name = ppe_get_reg_name(PPE_CTR);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    //XIRAMRA(skipped)   - XCR(Write-only) and SPRG0(read below)
    //XIRAMGA(skipped)   - IR(Read-Below) and SPRG0(read below)
    //XIRAMDBG  - XSR(Read Below) and SPRG0
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_sprg0_save), "Error in GETSCOM");
    l_sprg0_save.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "SPRG0");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_SPRG0);
    l_regVal.name = ppe_get_reg_name(PPE_SPRG0);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    //XIRAMEDR  - IR and EDR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 0, 32);
    sprintf(outstr, "IR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_IR);
    l_regVal.name = ppe_get_reg_name(PPE_IR);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);
    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "EDR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_EDR);
    l_regVal.name = ppe_get_reg_name(PPE_EDR);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    //XIDBGPRO  - XSR and IAR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGPRO, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 0, 32);
    sprintf(outstr, "XSR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_XSR);
    l_regVal.name = ppe_get_reg_name(PPE_XSR);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);
    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "IAR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_IAR);
    l_regVal.name = ppe_get_reg_name(PPE_IAR);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    //XIDBGINF  - SRR0 and LR
    t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGINF, i_ppe_instance_num);
    FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 0, 32);
    sprintf(outstr, "SRR0");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_SRR0);
    l_regVal.name = ppe_get_reg_name(PPE_SRR0);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);
    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "LR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = ppe_get_reg_number(PPE_LR);
    l_regVal.name = ppe_get_reg_name(PPE_LR);
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    ///////////////////////////////////////////////////////////////////////////
    //GPRs
    ///////////////////////////////////////////////////////////////////////////
    //If Engine supports VDRs access through XIR, then do it here
    if(ppe_get_xir_vdr_flag(i_ppe_type))
    {
        //VDR0
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDR0, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR0");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R0);
        l_regVal.name = ppe_get_reg_name(PPE_R0);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR1");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R1);
        l_regVal.name = ppe_get_reg_name(PPE_R1);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);

        //VDR2
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDR2, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR2");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R2);
        l_regVal.name = ppe_get_reg_name(PPE_R2);
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR3");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R3);
        l_regVal.name = ppe_get_reg_name(PPE_R3);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);

        //VDR4
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDR4, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR4");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R4);
        l_regVal.name = ppe_get_reg_name(PPE_R4);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR5");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R5);
        l_regVal.name = ppe_get_reg_name(PPE_R5);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);

        //VDR6
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDR6, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR6");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R6);
        l_regVal.name = ppe_get_reg_name(PPE_R6);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR7");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R7);
        l_regVal.name = ppe_get_reg_name(PPE_R7);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);

        //VDR8
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDR8, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR8");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R8);
        l_regVal.name = ppe_get_reg_name(PPE_R8);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR9");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R9);
        l_regVal.name = ppe_get_reg_name(PPE_R9);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);

        //VDRX
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDRX, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR10");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R10);
        l_regVal.name = ppe_get_reg_name(PPE_R10);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR13");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R13);
        l_regVal.name = ppe_get_reg_name(PPE_R13);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);

        //VDR28
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDR28, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR28");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R28);
        l_regVal.name = ppe_get_reg_name(PPE_R28);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR29");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R29);
        l_regVal.name = ppe_get_reg_name(PPE_R29);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);

        //VDR30
        t_addr = ppe_get_vdr_address(i_ppe_type, PPE_IDX_VDR30, i_ppe_instance_num);
        FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
        l_data64.extractToRight(l_data32, 0, 32);
        sprintf(outstr, "GPR30");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R30);
        l_regVal.name = ppe_get_reg_name(PPE_R30);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
        l_data64.extractToRight(l_data32, 32, 32);
        sprintf(outstr, "GPR31");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_R31);
        l_regVal.name = ppe_get_reg_name(PPE_R31);
        l_regVal.value = l_data32;
        v_ppe_gprs_value.push_back(l_regVal);
    }

    //Check the halt state. If Engine is not already halted and we were not asked to halt and
    //were asked to dump SPRs(or GPRs in case not available through XIR) , then it's an error
    ppe_is_halted(i_target, i_ppe_type, i_ppe_instance_num, l_ppe_halt_state);

    //IF PPE is halted(by default or due to halt/force_halt swicthes) or SNAPSHOT mode , get the other internal registers
    if ( ((i_mode == SNAPSHOT) || l_ppe_halt_state) && (i_mode != XIRS))
    {
        //If SNAPSHOT mode and PPE is not halted do XCR halt; before ramming
        if((i_mode == SNAPSHOT) && !(l_ppe_halt_state))
        {
            FAPI_TRY(ppe_halt(i_target, i_ppe_type, i_ppe_instance_num));
        }

        FAPI_DBG("Save GPR0");
        l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(ppe_get_reg_number(PPE_R0), ppe_get_reg_number(PPE_SPRG0)), 0,
                                              32);
        FAPI_DBG("ppe_get_instr_mtspr(%d, SPRG0): 0x%16llX", 0, l_raminstr );
        FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_gpr0_save));
        FAPI_DBG("Saved GPR0 value : 0x%08llX", l_gpr0_save );

        ///////////////////////////////////////////////////////////////////////////
        //SPRs
        ///////////////////////////////////////////////////////////////////////////
        for (auto it : v_ppe_sprs_ram)
        {
            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mfspr(0, ppe_get_reg_number(it)), 0, 32);
            FAPI_DBG("ppe_get_inst_mfspr(R0, %5d): 0x%16llX", it, l_raminstr );
            FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
            t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
            FAPI_TRY(fapi2::putScom(i_target, t_addr, l_raminstr));

            // R0 to SPRG0
            l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(0, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
            FAPI_DBG(": ppe_get_instr_mtspr(R0, SPRG0): 0x%16llX" , l_raminstr );

            FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_data32));
            FAPI_INF("data = 0x%08llX",  l_data32);
            l_regVal.number = ppe_get_reg_number(it);
            l_regVal.name = ppe_get_reg_name(it);
            l_regVal.value = l_data32;
            v_ppe_sprs_value.push_back(l_regVal);
        }

        // MSR
        // MSR to R0
        l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mfmsr(0), 0, 32);
        FAPI_DBG("      ppe_getMfmsrInstruction(R0): 0x%16llX", l_raminstr );
        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
        FAPI_TRY(fapi2::putScom(i_target, t_addr, l_raminstr));

        // R0 to SPRG0
        l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(0, ppe_get_reg_number(PPE_SPRG0)), 0, 32);
        FAPI_DBG("          : ppe_get_instr_mtspr(R0, SPRG0): 0x%16llX", l_raminstr );

        FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_data32));
        sprintf(outstr, "MSR");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);

        l_regVal.number = ppe_get_reg_number(PPE_MSR);
        l_regVal.name = ppe_get_reg_name(PPE_MSR);
        l_regVal.value = l_data32;
        v_ppe_sprs_value.push_back(l_regVal);

        // CR
        // CR to R0
        l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mfcr(0), 0, 32);
        FAPI_DBG("          ppe_getMfcrInstruction(R0): 0x%16llX", l_raminstr );
        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
        FAPI_TRY(fapi2::putScom(i_target, t_addr, l_raminstr));

        // R0 to SPRG0
        l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(0,  ppe_get_reg_number(PPE_SPRG0)), 0, 32);
        FAPI_DBG("          : ppe_get_instr_mtspr(R0, SPRG0): 0x%16llX", l_raminstr );

        FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_data32));
        sprintf(outstr, "CR");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = ppe_get_reg_number(PPE_CR);
        l_regVal.name = ppe_get_reg_name(PPE_CR);
        l_regVal.value = l_data32;
        v_ppe_sprs_value.push_back(l_regVal);

        //If this engine doesn't have VDR XIR access, then RAM them out
        if(!ppe_get_xir_vdr_flag(i_ppe_type))
        {
            for (auto it : v_ppe_gprs)
            {
                l_raminstr.flush<0>().insertFromRight(ppe_get_inst_mtspr(ppe_get_reg_number(it), ppe_get_reg_number(PPE_SPRG0)), 0, 32);
                FAPI_DBG("ppe_get_instr_mtspr(%d, SPRG0): 0x%16llX", it, l_raminstr );
                FAPI_TRY(ppe_ram_read(i_target, i_ppe_type, i_ppe_instance_num, l_raminstr, l_data32));

                sprintf(outstr, "GPR%d", it);

                if (it == 0)
                {
                    FAPI_INF("%-9s = 0x%08llX", outstr, l_gpr0_save);
                    l_regVal.value = l_gpr0_save;
                    l_regVal.number = ppe_get_reg_number(it);
                    l_regVal.name = ppe_get_reg_name(it);
                    v_ppe_gprs_value.push_back(l_regVal);
                }
                else
                {
                    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
                    l_regVal.number = ppe_get_reg_number(it);
                    l_regVal.name = ppe_get_reg_name(it);
                    l_regVal.value = l_data32;
                    v_ppe_gprs_value.push_back(l_regVal);
                }
            }
        }

        FAPI_DBG("Restore GPR0");
        l_gpr0_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
        FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));
        l_data64.flush<0>().insertFromRight(ppe_get_inst_mfspr(ppe_get_reg_number(PPE_R0), ppe_get_reg_number(PPE_SPRG0)), 0,
                                            32);
        FAPI_DBG("ppe_get_instr_mtspr(%d, SPRG0): 0x%16llX", 0, l_data64 );
        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
        FAPI_TRY(fapi2::putScom(i_target, t_addr, l_data64));

        FAPI_DBG("Restore SPRG0");
        FAPI_TRY(ppe_poll_halt_state(i_target, i_ppe_type, i_ppe_instance_num));
        t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
        FAPI_TRY(putScom(i_target, t_addr , l_sprg0_save), "Error in GETSCOM");

        FAPI_DBG("Restore SPRG0 Done");

        //If SNAPSHOT mode and only if initially PPE was not halted then do XCR(resume)
        if ((i_mode == SNAPSHOT) && !(l_ppe_halt_state))
        {
            FAPI_TRY(ppe_resume(i_target, i_ppe_type, i_ppe_instance_num));

            FAPI_INF("------   XIRs after resume  ------");
            //XIXCR     - XCR(Write-only) and CTR
            t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIXCR, i_ppe_instance_num);
            FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "CTR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_CTR);
            l_regVal.name = ppe_get_reg_name(PPE_CTR);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);

            //XIRAMRA(skipped)   - XCR(Write-only) and SPRG0(read below)
            //XIRAMGA(skipped)   - IR(Read-Below) and SPRG0(read below)
            //XIRAMDBG  - XSR(Read Below) and SPRG0
            t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMDBG, i_ppe_instance_num);
            FAPI_TRY(getScom(i_target, t_addr, l_sprg0_save), "Error in GETSCOM");
            l_sprg0_save.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "SPRG0");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_SPRG0);
            l_regVal.name = ppe_get_reg_name(PPE_SPRG0);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);

            //XIRAMEDR  - IR and EDR
            t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIRAMEDR, i_ppe_instance_num);
            FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 0, 32);
            sprintf(outstr, "IR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_IR);
            l_regVal.name = ppe_get_reg_name(PPE_IR);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);
            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "EDR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_EDR);
            l_regVal.name = ppe_get_reg_name(PPE_EDR);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);

            //XIDBGPRO  - XSR and IAR
            t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGPRO, i_ppe_instance_num);
            FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 0, 32);
            sprintf(outstr, "XSR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_XSR);
            l_regVal.name = ppe_get_reg_name(PPE_XSR);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);
            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "IAR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_IAR);
            l_regVal.name = ppe_get_reg_name(PPE_IAR);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);

            //XIDBGINF  - SRR0 and LR
            t_addr = ppe_get_xir_address(i_ppe_type, PPE_IDX_XIDBGINF, i_ppe_instance_num);
            FAPI_TRY(getScom(i_target, t_addr, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 0, 32);
            sprintf(outstr, "SRR0");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_SRR0);
            l_regVal.name = ppe_get_reg_name(PPE_SRR0);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);
            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "LR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = ppe_get_reg_number(PPE_LR);
            l_regVal.name = ppe_get_reg_name(PPE_LR);
            l_regVal.value = l_data32;
            v_ppe_xirs_value.push_back(l_regVal);
        }
    }
    else
    {
        FAPI_INF("\nPPE is not Halted\n");
    }

fapi_try_exit:
    return fapi2::current_err;
}

// Hardware procedure
fapi2::ReturnCode
p10_ppe_state(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
              enum PPE_TYPES i_ppe_type,
              uint32_t i_ppe_instance_num,
              const PPE_DUMP_MODE i_mode,
              std::vector<Reg32Value_t>& v_ppe_gprs_value,
              std::vector<Reg32Value_t>& v_ppe_sprs_value,
              std::vector<Reg32Value_t>& v_ppe_xirs_value
             )
{

    //Call the function to collect the data.
    ppe_state_data(i_target,
                   i_ppe_type,
                   i_ppe_instance_num,
                   i_mode,
                   v_ppe_gprs_value,
                   v_ppe_sprs_value,
                   v_ppe_xirs_value);


    return fapi2::current_err;
} // Procedure
