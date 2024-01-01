/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_ppe_utils.H $     */
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
/// @file  ody_ppe_utils.H
/// @brief PPE commonly used functions
///
/// *HWP HW Owner        : Greg Still <stillgs.@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 3
/// *HWP Consumed by     : Cronus, HB, FSP
#ifndef __ODY_PPE_UTILS_H__
#define __ODY_PPE_UTILS_H__

#include <map>
#include <fapi2.H>
#include <ody_ppe_instance_defs.H>

typedef struct
{
    uint16_t    number;
    uint32_t    value;
    const char*  name;
} Reg32Value_t;

typedef struct
{
    uint16_t    number;
    uint32_t    value;
} Reg32N_t;


typedef struct
{
    uint16_t    number;
    uint64_t    value;
    const char*  name;
} Reg64Value_t;

//Register Tables
typedef struct
{
    bool check_one;
    uint16_t startBit;
    uint16_t endBit;
    const char* description;
    std::vector<const char*> enumDescription;
} RegField_t;

/*
 * @brief enumerates opcodes for few instructions.
 */
enum
{
    OPCODE_31         = 31,
    MTSPR_CONST1      = 467,
    MTSPR_BASE_OPCODE = (OPCODE_31 << (31 - 5)) | (MTSPR_CONST1 << (31 - 30)),
    MFSPR_CONST1      = 339,
    MFSPR_BASE_OPCODE = (OPCODE_31 << (31 - 5)) | (MFSPR_CONST1 << (31 - 30)),
    MFMSRD_CONST1     = 83,
    MFCR_CONST1       = 19,
    ADDIS_CONST       = 15,
    ORIS_CONST        = 25,
    ANDIS_CONST       = 29,
    LWZ_CONST         = 32,
    STW_CONST         = 36,
    LVD_CONST         = 5,
};

enum INT_VEC_OFFSET
{
    MCHK_VEC    = 0x000  ,  // 0,
    SRST_VEC    = 0x040  ,  // 64,
    DSI_VEC     = 0x060 ,  // 96,
    ISI_VEC     = 0x080 ,  // 128,
    EXT_VEC     = 0x0A0 ,  // 160,
    ALIG_VEC    = 0x0C0  ,  // 192,
    PRG_VEC     = 0x0E0 ,  // 224,
    DEC_VEC     = 0x100 ,  // 256,
    FIT_VEC     = 0x120 ,  // 288,
    WDT_VEC     = 0x140 ,  // 320,
};

enum PPE_REGS
{
    //SPRS
    PPE_CTR,
    PPE_DACR,
    PPE_DBCR,
    PPE_DEC,
    PPE_EDR,
    PPE_ISR,
    PPE_IVPR,
    PPE_LR,
    PPE_PIR,
    PPE_PVR,
    PPE_SPRG0,
    PPE_SRR0,
    PPE_SRR1,
    PPE_TCR,
    PPE_TSR,
    PPE_XER,
    PPE_MSR,
    PPE_CR,

    //GPRs
    PPE_R0,
    PPE_R1,
    PPE_R2,
    PPE_R3,
    PPE_R4,
    PPE_R5,
    PPE_R6,
    PPE_R7,
    PPE_R8,
    PPE_R9,
    PPE_R10,
    PPE_R13,
    PPE_R28,
    PPE_R29,
    PPE_R30,
    PPE_R31,

    //VDRs
    PPE_D0,
    PPE_D2,
    PPE_D1,
    PPE_D3,
    PPE_D4,
    PPE_D5,
    PPE_D6,
    PPE_D7,
    PPE_D8,
    PPE_D9,
    PPE_D28,
    PPE_D29,
    PPE_D30,
    PPE_D31,

    //XIRs
    PPE_IAR,
    PPE_IR,
    PPE_XCR,
    PPE_XSR,
};

static std::map<enum PPE_REGS, uint32_t> v_ppe_reg_num =
{
    //SPRs
    { PPE_CTR,   9      },
    { PPE_DACR,  316    },
    { PPE_DBCR,  308    },
    { PPE_DEC,   22     },
    { PPE_EDR,   61     },
    { PPE_IR,    3      },
    { PPE_ISR,   62     },
    { PPE_IVPR,  63     },
    { PPE_LR,    8      },
    { PPE_PIR,   286    },
    { PPE_PVR,   287    },
    { PPE_SPRG0, 272    },
    { PPE_SRR0,  26     },
    { PPE_SRR1,  27     },
    { PPE_TCR,   340    },
    { PPE_TSR,   336    },
    { PPE_XER,   1      },
    { PPE_MSR,   42     },
    { PPE_CR,    420    },

    //GPRs
    { PPE_R0,    0     },
    { PPE_R1,    1     },
    { PPE_R2,    2     },
    { PPE_R3,    3     },
    { PPE_R4,    4     },
    { PPE_R5,    5     },
    { PPE_R6,    6     },
    { PPE_R7,    7     },
    { PPE_R8,    8     },
    { PPE_R9,    9     },
    { PPE_R10,   10    },
    { PPE_R13,   13    },
    { PPE_R28,   28    },
    { PPE_R29,   29    },
    { PPE_R30,   30    },
    { PPE_R31,   31    },

    //VDRs
    {PPE_D0,     0     },
    {PPE_D1,     1     },
    {PPE_D2,     2     },
    {PPE_D3,     3     },
    {PPE_D4,     4     },
    {PPE_D5,     5     },
    {PPE_D6,     6     },
    {PPE_D7,     7     },
    {PPE_D8,     8     },
    {PPE_D9,     9     },
    {PPE_D28,    28    },
    {PPE_D29,    29    },
    {PPE_D30,    30    },
    {PPE_D31,    31    },

    //XIRs
    {PPE_IAR,   1000},
    {PPE_IR,    1001},
    {PPE_XCR,   1002},
    {PPE_XSR,   1003},
};

static std::map<enum PPE_REGS, const char*> v_ppe_reg_names =
{
    //SPRs
    { PPE_CTR,   "CTR"    },
    { PPE_DACR,  "DACR"   },
    { PPE_DBCR,  "DBCR"   },
    { PPE_DEC,   "DEC"    },
    { PPE_EDR,   "EDR"    },
    { PPE_ISR,   "ISR"    },
    { PPE_IVPR,  "IVPR"   },
    { PPE_LR,    "LR"     },
    { PPE_PIR,   "PIR"    },
    { PPE_PVR,   "PVR"    },
    { PPE_SPRG0, "SPRG0"  },
    { PPE_SRR0,  "SRR0"   },
    { PPE_SRR1,  "SRR1"   },
    { PPE_TCR,   "TCR"    },
    { PPE_TSR,   "TSR"    },
    { PPE_XER,   "XER"    },
    { PPE_MSR,   "MSR"    },
    { PPE_CR,    "CR"     },

    //GPRs
    { PPE_R0,    "R0"     },
    { PPE_R1,    "R1"     },
    { PPE_R2,    "R2"     },
    { PPE_R3,    "R3"     },
    { PPE_R4,    "R4"     },
    { PPE_R5,    "R5"     },
    { PPE_R6,    "R6"     },
    { PPE_R7,    "R7"     },
    { PPE_R8,    "R8"     },
    { PPE_R9,    "R9"     },
    { PPE_R10,   "R10"    },
    { PPE_R13,   "R13"    },
    { PPE_R28,   "R28"    },
    { PPE_R29,   "R29"    },
    { PPE_R30,   "R30"    },
    { PPE_R31,   "R31"    },

    //VDRs
    {PPE_D0,     "D0"     },
    {PPE_D2,     "D1"     },
    {PPE_D1,     "D2"     },
    {PPE_D3,     "D3"     },
    {PPE_D4,     "D4"     },
    {PPE_D5,     "D5"     },
    {PPE_D6,     "D6"     },
    {PPE_D7,     "D7"     },
    {PPE_D8,     "D8"     },
    {PPE_D9,     "D9"     },
    {PPE_D28,    "D28"    },
    {PPE_D29,    "D29"    },
    {PPE_D30,    "D30"    },
    {PPE_D31,    "D31"    },

    //XIRs
    { PPE_IAR,   "IAR"    },
    { PPE_IR,    "IR"     },
    { PPE_XCR,   "XSR"    },
    { PPE_XSR,   "XSR"    },
};

// XSR defines
enum PPE_XSR_DEFS
{
    PPE_XSR_HALTED_STATE         = 0,
    PPE_XSR_HALT_CONDITION_START = 1,
    PPE_XSR_HALT_CONDITION_LEN   = 3,
    PPE_XSR_XCR_CMD_HALT         = 1,
    PPE_XSR_WDT_HALT             = 2,
    PPE_XSR_UMI_HALT             = 3,
    PPE_XSR_DEBUG_HALT           = 4,
    PPE_XSR_DBCR_HALT            = 5,
    PPE_XSR_INPUT_HALT           = 6,
    PPE_XSR_HW_FAILURE           = 7
};

// XCR defines
enum PPE_XCR_DEFS
{
    PPE_XCR_CMD_START           = 1,
    PPE_XCR_CMD_LEN             = 3,

    PPE_XCR_CLEAR_DEBUG_STATUS  = 0,
    PPE_XCR_HALT                = 1,
    PPE_XCR_RESUME              = 2,
    PPE_XCR_SINGLE_STEP         = 3,
    PPE_XCR_TOGGLE_XSR_TRH      = 4,
    PPE_XCR_SOFT_RESET          = 5,
    PPE_XCR_HARD_RESET          = 6,
    PPE_XCR_FORCE_HALT          = 7
};

uint32_t ppe_get_reg_num(enum PPE_REGS reg);

uint64_t ppe_get_xir_addr(enum PPE_TYPES ppe_type, enum PPE_XIRS_IDX xir_idx, uint32_t ppe_instance_num);

///--------------------------------------------------------------------------------------
/// @brief generates a PPE instruction for some formats
/// @param[in] i_Op      Opcode
/// @param[in] i_Rts     Source or Target Register
/// @param[in] i_RA      Address Register
/// @param[in] i_d       Instruction Data Field
/// @return returns 32 bit instruction representing the PPE instruction.
///--------------------------------------------------------------------------------------
uint32_t ppe_get_instr( const uint16_t i_Op, const uint16_t i_Rts, const uint16_t i_Ra, const uint16_t i_d );

///--------------------------------------------------------------------------------------
/// @brief generates instruction for mtspr
/// @param[in] i_Rs      source register number
/// @param[in] i_Spr represents spr where data is to be moved.
/// @return returns 32 bit instruction representing mtspr instruction.
///--------------------------------------------------------------------------------------
uint32_t ppe_get_instr_mtspr( const uint16_t i_Rs, const uint16_t i_Spr );


///--------------------------------------------------------------------------------------
/// @brief generates instruction for mfspr
/// @param[in] i_Rt      target register number
/// @param[in] i_Spr represents spr where data is to sourced
/// @return returns 32 bit instruction representing mfspr instruction.
///--------------------------------------------------------------------------------------

uint32_t ppe_get_instr_mfspr( const uint16_t i_Rt, const uint16_t i_Spr );

///--------------------------------------------------------------------------------------
/// @brief generates instruction for mfmsr instruction.
/// @param[in]   i_Rt     target register number
/// @return  returns 32 bit instruction representing mfmsr instruction.
/// @note    moves contents of register MSR to i_Rt register.
///--------------------------------------------------------------------------------------
uint32_t ppe_get_instr_mfmsr( const uint16_t i_Rt );

///--------------------------------------------------------------------------------------
/// @brief generates instruction for mfcr instruction.
/// @param[in]   i_Rt     target register number
/// @return  returns 32 bit instruction representing mfcr instruction.
/// @note    moves contents of register CR to i_Rt register.
///--------------------------------------------------------------------------------------
uint32_t ppe_get_instr_mfcr( const uint16_t i_Rt );

///--------------------------------------------------------------------------------------
/// @brief Halts the engine(if not already in halted state)
/// @param[in]  i_target fapi2 target for proc chip
/// @param[in]  i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    programs XCR with halt bit to halt the engine.
///--------------------------------------------------------------------------------------
fapi2::ReturnCode halt_ppe(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type, uint32_t i_ppe_instance_num);

///--------------------------------------------------------------------------------------
/// @brief polls for Halt state. If halt state not detected then will eventually times out
/// @param[in]  i_target fapi2 target for proc chip
/// @param[in]  i_base_address  base SCOM address of the PPE
/// @return  fapi2::ReturnCode
/// @note    moves contents of register MSR to i_Rt register.
///--------------------------------------------------------------------------------------
fapi2::ReturnCode poll_ppe_halt_state(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type, uint32_t i_ppe_instance_num) ;

///--------------------------------------------------------------------------------------
/// @brief Perform RAM "read" operation
/// @param[in]   i_target        Chip Target
/// @param[in]   i_base_address  base SCOM address of the PPE
/// @param[in]   i_instruction   RAM instruction to move a register
/// @param[out]  o_data          Returned data
/// @return  fapi2::ReturnCode
///--------------------------------------------------------------------------------------
fapi2::ReturnCode ppe_ram_read(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const fapi2::buffer<uint64_t> i_instruction,
    fapi2::buffer<uint32_t>& o_data );

#ifndef  __HOSTBOOT_MODULE
fapi2::ReturnCode ppe_save_sprg0_gprs(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    fapi2::buffer<uint32_t>& l_gpr0_save,
    fapi2::buffer<uint32_t>& l_gpr1_save,
    fapi2::buffer<uint32_t>& l_gpr9_save,
    fapi2::buffer<uint64_t>& l_sprg0_save);

fapi2::ReturnCode ppe_restore_sprg0_gprs(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    fapi2::buffer<uint32_t> l_gpr0_save,
    fapi2::buffer<uint32_t> l_gpr1_save,
    fapi2::buffer<uint32_t> l_gpr9_save,
    fapi2::buffer<uint64_t> l_sprg0_save);

fapi2::ReturnCode read_local_ppe_regs(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    enum PPE_TYPES i_ppe_type,
    uint32_t i_ppe_instance_num,
    const uint16_t i_local_address,
    fapi2::buffer<uint64_t>& o_data);

#endif  //__HOSTBOOT_MODULE
#endif  // __P10_PPE_UTILS_H__
