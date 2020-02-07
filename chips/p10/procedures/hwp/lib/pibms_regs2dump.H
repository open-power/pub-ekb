/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/lib/pibms_regs2dump.H $              */
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
#ifndef __PIBMS_REGS2DUMP_H__
#define __PIBMS_REGS2DUMP_H__

#include <map>
#include <vector>
#include "p10_scom_pibms.H"

#define ADDR_LEN     8      //register address length
#define VALUE_LEN   16      //register value length

//specify register attribute
#define NO_ATTR        0x00   //default
#define ERR_ATTR       0x01   //error status register
#define SDB_ATTR       0x02   //can be accessed in SDB mode
#define ERR_SDB_ATTR   0x03   //error status register, which can be accessed in SDB mode
#define VLD_ATTR       0x04   //value is already available (may not need this)

#define HELP_RC  999


#define CHKRC_BREAK(msg)  if (rc) { ecmdOutput(msg); break; }
#define CHKRC_RETRUN(msg) if (rc) { ecmdOutput(msg); return rc; }
#define RETURN_HELP(rc, msg)   { ecmdOutput(msg); help(); return rc; }

enum eREGBITS
{
    BIT00, BIT01, BIT02, BIT03, BIT04, BIT05, BIT06, BIT07,
    BIT08, BIT09, BIT10, BIT11, BIT12, BIT13, BIT14, BIT15,
    BIT16, BIT17, BIT18, BIT19, BIT20, BIT21, BIT22, BIT23,
    BIT24, BIT25, BIT26, BIT27, BIT28, BIT29, BIT30, BIT31,
    BIT32, BIT33, BIT34, BIT35, BIT36, BIT37, BIT38, BIT39,
    BIT40, BIT41, BIT42, BIT43, BIT44, BIT45, BIT46, BIT47,
    BIT48, BIT49, BIT50, BIT51, BIT52, BIT53, BIT54, BIT55,
    BIT56, BIT57, BIT58, BIT59, BIT60, BIT61, BIT62, BIT63
};

typedef struct
{
    uint64_t    addr;
    std::string name;
    uint32_t    attr;  //register attribute
} sReg;

typedef struct
{
    sReg     reg;
    uint64_t value;
} sRegV;

typedef struct
{
    uint32_t    bit;   //bit index
    std::string des1;  //description when bit is set to 1
    std::string des0;  //description when bit is set to 0
} sRegBit;

//List what chiplet registers need to dump
//scom id ---> unit name
std::map<uint64_t, std::string> const pibmsUnitMap
{
    {  0x1,    "OTPROM"        },
    {  0x5,    "FSI MAILBOX"   },
    {  0x8,    "PIBMEM"        },
    {  0xB,    "SBE FIFO"      },
    {  0xC,    "SPI MASTER"    },
    {  0xD,    "PSU"           },
    {  0xF,    "PCB MASTER"    },
};

std::vector<sReg> const pibms_regs_2dump =
{
    //addr,                            name,                              attribute
    {OTP_STATUS,                       "OTP_STATUS",                      ERR_ATTR },  //0x10002, error status
    {OTP_CONTROL,                      "OTP_CONTROL",                     ERR_ATTR },  //0x10008, error status

    {MAILBOX_CBS_CTRL_STATUS,          "MAILBOX_CBS_CTRL_STATUS",          NO_ATTR },  //0x50001, default
    {MAILBOX_CBS_TRACE,                "MAILBOX_CBS_TRACE",                NO_ATTR },  //0x50002
    {MAILBOX_CBS_ENVSTAT,              "MAILBOX_CBS_ENVSTAT",              NO_ATTR },  //0x50004
    {MAILBOX_CBS_SELFBOOT_CTRL_STATUS, "MAILBOX_CBS_SELFBOOT_CTRL_STATUS", NO_ATTR },  //0x50008
    {MAILBOX_CBS_SELFBOOT_MSG,         "MAILBOX_CBS_SELFBOOT_MSG",         NO_ATTR },  //0x50009
    {MAILBOX_CBS_DEBUG_PERV_CLK,       "MAILBOX_CBS_DEBUG_PERV_CLK",       NO_ATTR },  //0x5000B
    {MAILBOX_ROOTCTRL0,                "MAILBOX_ROOTCTRL0",                NO_ATTR },  //0x50010
    {MAILBOX_ROOTCTRL1,                "MAILBOX_ROOTCTRL1",                NO_ATTR },  //0x50011
    {MAILBOX_ROOTCTRL2,                "MAILBOX_ROOTCTRL2",                NO_ATTR },  //0x50012
    {MAILBOX_ROOTCTRL3,                "MAILBOX_ROOTCTRL3",                NO_ATTR },  //0x50013
    {MAILBOX_ROOTCTRL4,                "MAILBOX_ROOTCTRL4",                NO_ATTR },  //0x50014
    {MAILBOX_ROOTCTRL5,                "MAILBOX_ROOTCTRL5",                NO_ATTR },  //0x50015
    {MAILBOX_ROOTCTRL6,                "MAILBOX_ROOTCTRL6",                NO_ATTR },  //0x50016
    {MAILBOX_ROOTCTRL7,                "MAILBOX_ROOTCTRL7",                NO_ATTR },  //0x50017
    {MAILBOX_ROOTCTRL8,                "MAILBOX_ROOTCTRL8",                NO_ATTR },  //0x50018
    {MAILBOX_PERVCTRL0,                "MAILBOX_PERVCTRL0",                NO_ATTR },  //0x5001A
    {MAILBOX_PERVCTRL1,                "MAILBOX_PERVCTRL1",                NO_ATTR },  //0x5001B
    {MAILBOX_SCRATCH_REG_1,            "MAILBOX_SCRATCH_REG_1",            NO_ATTR },  //0x50038
    {MAILBOX_SCRATCH_REG_2,            "MAILBOX_SCRATCH_REG_2",            NO_ATTR },  //0x50039
    {MAILBOX_SCRATCH_REG_3,            "MAILBOX_SCRATCH_REG_3",            NO_ATTR },  //0x5003A
    {MAILBOX_SCRATCH_REG_4,            "MAILBOX_SCRATCH_REG_4",            NO_ATTR },  //0x5003B
    {MAILBOX_SCRATCH_REG_5,            "MAILBOX_SCRATCH_REG_5",            NO_ATTR },  //0x5003C
    {MAILBOX_SCRATCH_REG_6,            "MAILBOX_SCRATCH_REG_6",            NO_ATTR },  //0x5003D
    {MAILBOX_SCRATCH_REG_7,            "MAILBOX_SCRATCH_REG_7",            NO_ATTR },  //0x5003E
    {MAILBOX_SCRATCH_REG_8,            "MAILBOX_SCRATCH_REG_8",            NO_ATTR },  //0x5003F
    {MAILBOX_SCRATCH_REG_9,            "MAILBOX_SCRATCH_REG_9",            NO_ATTR },  //0x50180
    {MAILBOX_SCRATCH_REG_10,           "MAILBOX_SCRATCH_REG_10",           NO_ATTR },  //0x50181
    {MAILBOX_SCRATCH_REG_11,           "MAILBOX_SCRATCH_REG_11",           NO_ATTR },  //0x50182
    {MAILBOX_SCRATCH_REG_12,           "MAILBOX_SCRATCH_REG_12",           NO_ATTR },  //0x50183
    {MAILBOX_SCRATCH_REG_13,           "MAILBOX_SCRATCH_REG_13",           NO_ATTR },  //0x50184
    {MAILBOX_SCRATCH_REG_14,           "MAILBOX_SCRATCH_REG_14",           NO_ATTR },  //0x50185
    {MAILBOX_SCRATCH_REG_15,           "MAILBOX_SCRATCH_REG_15",           NO_ATTR },  //0x50186
    {MAILBOX_SCRATCH_REG_16,           "MAILBOX_SCRATCH_REG_16",           NO_ATTR },  //0x50187

    {PIBMEM_CTRL,                      "PIBMEM_CTRL",                     SDB_ATTR },  //0x88000
    {PIBMEM_ADDR_PIB,                  "PIBMEM_ADDR_PIB",                 SDB_ATTR },  //0x88001
    {PIBMEM_STATUS,                    "PIBMEM_STATUS",               ERR_SDB_ATTR },  //0x88005
    {PIBMEM_RESET,                     "PIBMEM_RESET",                    SDB_ATTR },  //0x88006
    {PIBMEM_ADDR_FACES,                "PIBMEM_ADDR_FACES",               SDB_ATTR },  //0x88007
    {PIBMEM_FIR_MASK,                  "PIBMEM_FIR_MASK",                 SDB_ATTR },  //0x88008
    {PIBMEM_ECC_CAPTURE,               "PIBMEM_ECC_CAPTURE",              SDB_ATTR },  //0x8800B  (PIBMEM_REPR_0 in P9 ?)


    {SPIMST0_ERR_INJECT,                  "SPIMST0_ERR_INJECT",         NO_ATTR},  //C0000
    {SPIMST0_COUNTER,                     "SPIMST0_COUNTER",            NO_ATTR},  //C0001
    {SPIMST0_CONFIG,                      "SPIMST0_CONFIG",             NO_ATTR},  //C0002
    {SPIMST0_CLOCK_CONFIG,                "SPIMST0_CLOCK_CONFIG",       NO_ATTR},  //C0003
    {SPIMST0_MEM_MAPPING,                 "SPIMST0_MEM_MAPPING",        NO_ATTR},  //C0004
    {SPIMST0_TRANSMIT_DATA_REG,           "SPIMST0_TRANSMIT_DATA_REG",  NO_ATTR},  //C0005
    {SPIMST0_RECEIVE_DATA_REG,            "SPIMST0_RECEIVE_DATA_REG",   NO_ATTR},  //C0006
    {SPIMST0_SEQ_OP_REG,                  "SPIMST0_SEQ_OP_REG",         NO_ATTR},  //C0007
    {SPIMST0_STATUS_REG,                  "SPIMST0_STATUS_REG",         NO_ATTR},  //C0008

    {SPIMST1_ERR_INJECT,                  "SPIMST1_ERR_INJECT",         NO_ATTR},   //C0020
    {SPIMST1_COUNTER,                     "SPIMST1_COUNTER",            NO_ATTR},   //C0021
    {SPIMST1_CONFIG,                      "SPIMST1_CONFIG",             NO_ATTR},   //C0022
    {SPIMST1_CLOCK_CONFIG,                "SPIMST1_CLOCK_CONFIG",       NO_ATTR},   //C0023
    {SPIMST1_MEM_MAPPING,                 "SPIMST1_MEM_MAPPING",        NO_ATTR},   //C0024
    {SPIMST1_TRANSMIT_DATA_REG,           "SPIMST1_TRANSMIT_DATA_REG",  NO_ATTR},   //C0025
    {SPIMST1_RECEIVE_DATA_REG,            "SPIMST1_RECEIVE_DATA_REG",   NO_ATTR},   //C0026
    {SPIMST1_SEQ_OP_REG,                  "SPIMST1_SEQ_OP_REG",         NO_ATTR},   //C0027
    {SPIMST1_STATUS_REG,                  "SPIMST1_STATUS_REG",         NO_ATTR},   //C0028

    {SPIMST2_ERR_INJECT,                  "SPIMST2_ERR_INJECT",         NO_ATTR},   //C0040
    {SPIMST2_COUNTER,                     "SPIMST2_COUNTER",            NO_ATTR},   //C0041
    {SPIMST2_CONFIG,                      "SPIMST2_CONFIG",             NO_ATTR},   //C0042
    {SPIMST2_CLOCK_CONFIG,                "SPIMST2_CLOCK_CONFIG",       NO_ATTR},   //C0043
    {SPIMST2_MEM_MAPPING,                 "SPIMST2_MEM_MAPPING",        NO_ATTR},   //C0044
    {SPIMST2_TRANSMIT_DATA_REG,           "SPIMST2_TRANSMIT_DATA_REG",  NO_ATTR},   //C0045
    {SPIMST2_RECEIVE_DATA_REG,            "SPIMST2_RECEIVE_DATA_REG",   NO_ATTR},   //C0046
    {SPIMST2_SEQ_OP_REG,                  "SPIMST2_SEQ_OP_REG",         NO_ATTR},   //C0047
    {SPIMST2_STATUS_REG,                  "SPIMST2_STATUS_REG",         NO_ATTR},   //C0048

    {SPIMST3_ERR_INJECT,                  "SPIMST3_ERR_INJECT",         NO_ATTR},   //C0060
    {SPIMST3_COUNTER,                     "SPIMST3_COUNTER",            NO_ATTR},   //C0061
    {SPIMST3_CONFIG,                      "SPIMST3_CONFIG",             NO_ATTR},   //C0062
    {SPIMST3_CLOCK_CONFIG,                "SPIMST3_CLOCK_CONFIG",       NO_ATTR},   //C0063
    {SPIMST3_MEM_MAPPING,                 "SPIMST3_MEM_MAPPING",        NO_ATTR},   //C0064
    {SPIMST3_TRANSMIT_DATA_REG,           "SPIMST3_TRANSMIT_DATA_REG",  NO_ATTR},   //C0065
    {SPIMST3_RECEIVE_DATA_REG,            "SPIMST3_RECEIVE_DATA_REG",   NO_ATTR},   //C0066
    {SPIMST3_SEQ_OP_REG,                  "SPIMST3_SEQ_OP_REG",         NO_ATTR},   //C0067
    {SPIMST3_STATUS_REG,                  "SPIMST3_STATUS_REG",         NO_ATTR},   //C0068

    {SPIMST4_ERR_INJECT,                  "SPIMST4_ERR_INJECT",         NO_ATTR},   //C0080
    {SPIMST4_COUNTER,                     "SPIMST4_COUNTER",            NO_ATTR},   //C0081
    {SPIMST4_CONFIG,                      "SPIMST4_CONFIG",             NO_ATTR},   //C0082
    {SPIMST4_CLOCK_CONFIG,                "SPIMST4_CLOCK_CONFIG",       NO_ATTR},   //C0083
    {SPIMST4_MEM_MAPPING,                 "SPIMST4_MEM_MAPPING",        NO_ATTR},   //C0084
    {SPIMST4_TRANSMIT_DATA_REG,           "SPIMST4_TRANSMIT_DATA_REG",  NO_ATTR},   //C0085
    {SPIMST4_RECEIVE_DATA_REG,            "SPIMST4_RECEIVE_DATA_REG",   NO_ATTR},   //C0086
    {SPIMST4_SEQ_OP_REG,                  "SPIMST4_SEQ_OP_REG",         NO_ATTR},   //C0087
    {SPIMST4_STATUS_REG,                  "SPIMST4_STATUS_REG",         NO_ATTR},   //C0088

    {SBEFIFO_UPSTREAM_STATUS,          "SBEFIFO_UPSTREAM_STATUS",           ERR_ATTR },  //0xB0001 EPF.FSI.W.FSI_SBE_FIFO.FSB_UPFIFO_STATUS
    {SBEFIFO_DOWNSTREAM_STATUS,        "SBEFIFO_DOWNSTREAM_STATUS",         ERR_ATTR },  //0xB0011 EPF.FSI.W.FSI_SBE_FIFO.FSB_DOWNFIFO_STATUS
    {SBEFIFO2_UPSTREAM_STATUS,         "SBEFIFO2_UPSTREAM_STATUS",           ERR_ATTR },  //0xB0021 EPF.FSI.W.FSI_SBE_FIFO2.FSB_UPFIFO_STATUS
    {SBEFIFO2_DOWNSTREAM_STATUS,       "SBEFIFO2_DOWNSTREAM_STATUS",         ERR_ATTR },  //0xB0031 EPF.FSI.W.FSI_SBE_FIFO2.FSB_DOWNFIFO_STATUS

    {PSU_PIBHST_CTRL_STATUS,           "PSU_PIBHST_CTRL_STATUS",            SDB_ATTR },  //0xD0000
    {PSU_PIBHST_FILTER,                "PSU_PIBHST_FILTER",                 SDB_ATTR },  //0xD0001
    {PSU_PIBHST_LAST_ADDR_TRACE,       "PSU_PIBHST_LAST_ADDR_TRACE",        SDB_ATTR },  //0xD0002
    {PSU_PIBHST_LAST_REQDATA_TRACE,    "PSU_PIBHST_LAST_REQDATA_TRACE",     SDB_ATTR },  //0xD0003
    {PSU_PIBHST_LAST_RSPDATA_TRACE,    "PSU_PIBHST_LAST_RSPDATA_TRACE",     SDB_ATTR },  //0xD0004
    {PSU_PIBHST_2NDLAST_ADDR_TRACE,    "PSU_PIBHST_2NDLAST_ADDR_TRACE",     SDB_ATTR },  //0xD0005
    {PSU_PIBHST_2NDLAST_REQDATA_TRACE, "PSU_PIBHST_2NDLAST_REQDATA_TRACE",  SDB_ATTR },  //0xD0006
    {PSU_PIBHST_2NDLAST_RSPDATA_TRACE, "PSU_PIBHST_2NDLAST_RSPDATA_TRACE",  SDB_ATTR },  //0xD0007
    {PSU_INSTR_CTRL_STATUS,            "PSU_INSTR_CTRL_STATUS",             SDB_ATTR },  //0xD0010

    {PCBM_REC_ERR_REG0,                "PCBM_REC_ERR_REG0",                  NO_ATTR },  //0xF0011  EPP.PIB.PCBMS.REC_ERR_REG0
    {PCBM_REC_ERR_REG1,                "PCBM_REC_ERR_REG1",                  NO_ATTR },  //0xF0012  EPP.PIB.PCBMS.REC_ERR_REG1
    {PCBM_REC_ERR_REG2,                "PCBM_REC_ERR_REG2",                  NO_ATTR },  //0xF0013  EPP.PIB.PCBMS.REC_ERR_REG2
    {PCBM_REC_ERR_REG3,                "PCBM_REC_ERR_REG3",                  NO_ATTR },  //0xF0014  EPP.PIB.PCBMS.REC_ERR_REG3
    {PCBM_FIRST_ERR,                   "PCBM_FIRST_ERR",                     NO_ATTR },  //0xF001E  EPP.PIB.PCBMS.FIRST_ERR_REG
    {PCBM_ERR_REG,                     "PCBM_ERR_REG",                       NO_ATTR },  //0xF001F  EPP.PIB.PCBMS.ERROR_REG
};


//key:   register address
//value: register bits' definition
std::map<uint64_t, std::vector<sRegBit>> const pibmsRegs
{
    //0x10002 - EPP.PIB.OTP.OTPC_M.STATUS_REGISTER
    {
        OTP_STATUS,
        {
            { BIT00,  "STATUS_ADDR_NVLD: Address invalid", "" },
            { BIT01,  "STATUS_WRITE_NVLD: Write invalid",  "" },
            { BIT02,  "STATUS_READ_NVLD: Read invalid",    "" },
            { BIT03,  "STATUS_INVLD_CMD_ERR: Invalid command register fields programmed", "" },
            { BIT04,  "STATUS_CORR_ERR: ECC Correctable error",                 "" },
            { BIT05,  "STATUS_UNCORR_ERROR: ECC Uncorrectable error",           "" },
            { BIT45,  "STATUS_DCOMP_ERR: Decompression Engine Error",           "" },
            { BIT46,  "STATUS_INVLD_PRGM_ERR: Invalid Program Operation error", "" }
        }
    },
    //0x10008 - OTP_CONTROL
    {
        OTP_CONTROL,
        {
            { BIT00,  "MODE_DCOMP_ENABLE: Decompression Engine enabled", "" },
            { BIT01,  "MODE_ECC_ENABLE: ECC checking enabled",  "" },
            { BIT03,  "MODE_ECC_CHK_DISABLE: ECC check disabled",    "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_1,  //print bit0-7 and bit8-31
        {
            { 0x10008,  "EQ Gard records",  "" },
            { 0x10818,  "EC Gard records",  "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_2,  //print bit0-15 and bit16-19
        {
            { 0x10010,  "Ref clock I2C bus divider",  "" },
            { 0x11004,  "Meshctrl setup",             "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_3,
        {
            { BIT00,  "Used by SBE, HB - FW ISTEP_MODE",  "" },
            { BIT01,  "SBE should go directly to runtime functionality", "" },
            { BIT02,  "The SBE to indicate an MPIPL to Hostboot",        "" },
            { BIT03,  "To indicate that FSP is attached",   "To indicate FSPless" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_4,
        {
            { BIT16,  "Force CP filter PLL into bypass",  "" },
            { BIT17,  "Force SS filter PLL into bypass",  "" },
            { BIT18,  "Force IO filter PLL into bypass",  "" },
            { BIT19,  "Force DPLL into bypass",           "" },
            { BIT20,  "Force nest PLL into bypass",       "" },
            { BIT21,  "Holds OBUS ratio value - Half speed",  "Holds OBUS ratio value - Normal speed" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_5,
        {
            { BIT00,  "In cache contained IPL",       "" },
            { BIT01,  "SBE should init all cores",    "" },
            { BIT02,  "HWP/Init risk level enabled",  "" },
            { BIT03,  "Boot loader HWP flag to not place 12K exception vectors",  "" },
            { BIT04,  "Memory synchronous mode",      "" },
            { BIT05,  "Normal PCI reference clock",  "Slow PCI reference clock" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_6,
        {
            { BIT24,  "Indicates Hostboot slave bit, 0b1 == slave",  "Indicates Hostboot slave bit, 0b0 == master" }
        }
    },
    {
        //0xC0003
        SPIMST0_CLOCK_CONFIG,  // bit 0-11, bit 31, bit 32-35
        {
            { 0x1000C, "SPI master0 clock divider", "" },
            { BIT31, "mmSPIsm enabled", "" },
            { 0x12004, "Hardware reset signal for spi slave", "" }
        }
    },
    {
        //0xC0023
        SPIMST1_CLOCK_CONFIG, // bit 0-11, bit 31, bit 32-35
        {
            { 0x1000C, "SPI master1 clock divider", "" },
            { BIT31, "mmSPIsm enabled", "" },
            { 0x12004, "Hardware reset signal for spi slave", "" }
        }
    },
    {
        //0xC0043
        SPIMST2_CLOCK_CONFIG, // bit 0-11, bit 31, bit 32-35
        {
            { 0x1000C, "SPI master2 clock divider", "" },
            { BIT31, "mmSPIsm enabled", "" },
            { 0x12004, "Hardware reset signal for spi slave", "" }
        }
    },
    {
        //0xC0063
        SPIMST3_CLOCK_CONFIG, // bit 0-11, bit 31, bit 32-35
        {
            { 0x1000C, "SPI master3 clock divider", "" },
            { BIT31, "mmSPIsm enabled", "" },
            { 0x12004, "Hardware reset signal for spi slave", "" }
        }
    },
    {
        //0xC0083
        SPIMST4_CLOCK_CONFIG, // bit 0-11, bit 31, bit 32-35
        {
            { 0x1000C, "SPI master4 clock divider", "" },
            { BIT31, "mmSPIsm enabled", "" },
            { 0x12004, "Hardware reset signal for spi slave", "" }
        }
    },
    {
        //0xC0008
        SPIMST0_STATUS_REG,
        {
            { BIT00, "Receive data register full", "" },
            { BIT01, "Receive data register overrun", "" },
            { BIT02, "Receive data register underrun", "" },
            { BIT04, "Transmit data register full", "" },
            { BIT05, "Transmit data register overrun", "" },
            { BIT06, "Transmit data register underrun", "" },
            { BIT32, "Counter configuration register parity error", "" },
            { BIT33, "Clock configuration register parity error", "" },
            { BIT34, "Sequencer configuration register parity error", "" },
            { BIT35, "Sequencer fsm error", "" },
            { BIT36, "Shifter fsm error", "" },
            { BIT37, "Pattern match register parity error", "" },
            { BIT38, "Transmit data register parity error", "" },
            { BIT39, "Receive data register parity error", "" },
            { BIT40, "Configuration register 1 parity error", "" },
            { BIT42, "Error register parity error", "" },
            { BIT43, "Ecc correctable error", "" },
            { BIT44, "Ecc uncorrectable error", "" },
            { BIT47, "Memory mapped SPI address overlap", "" },
            { BIT50, "Port multiplexer error", "" },
            { BIT51, "Address range error", "" }
        }
    },
    {
        //0xC0028
        SPIMST1_STATUS_REG,
        {
            { BIT00, "Receive data register full", "" },
            { BIT01, "Receive data register overrun", "" },
            { BIT02, "Receive data register underrun", "" },
            { BIT04, "Transmit data register full", "" },
            { BIT05, "Transmit data register overrun", "" },
            { BIT06, "Transmit data register underrun", "" },
            { BIT32, "Counter configuration register parity error", "" },
            { BIT33, "Clock configuration register parity error", "" },
            { BIT34, "Sequencer configuration register parity error", "" },
            { BIT35, "Sequencer fsm error", "" },
            { BIT36, "Shifter fsm error", "" },
            { BIT37, "Pattern match register parity error", "" },
            { BIT38, "Transmit data register parity error", "" },
            { BIT39, "Receive data register parity error", "" },
            { BIT40, "Configuration register 1 parity error", "" },
            { BIT42, "Error register parity error", "" },
            { BIT43, "Ecc correctable error", "" },
            { BIT44, "Ecc uncorrectable error", "" },
            { BIT47, "Memory mapped SPI address overlap", "" },
            { BIT50, "Port multiplexer error", "" },
            { BIT51, "Address range error", "" }
        }
    },
    {
        //0xC0048
        SPIMST2_STATUS_REG,
        {
            { BIT00, "Receive data register full", "" },
            { BIT01, "Receive data register overrun", "" },
            { BIT02, "Receive data register underrun", "" },
            { BIT04, "Transmit data register full", "" },
            { BIT05, "Transmit data register overrun", "" },
            { BIT06, "Transmit data register underrun", "" },
            { BIT32, "Counter configuration register parity error", "" },
            { BIT33, "Clock configuration register parity error", "" },
            { BIT34, "Sequencer configuration register parity error", "" },
            { BIT35, "Sequencer fsm error", "" },
            { BIT36, "Shifter fsm error", "" },
            { BIT37, "Pattern match register parity error", "" },
            { BIT38, "Transmit data register parity error", "" },
            { BIT39, "Receive data register parity error", "" },
            { BIT40, "Configuration register 1 parity error", "" },
            { BIT42, "Error register parity error", "" },
            { BIT43, "Ecc correctable error", "" },
            { BIT44, "Ecc uncorrectable error", "" },
            { BIT47, "Memory mapped SPI address overlap", "" },
            { BIT50, "Port multiplexer error", "" },
            { BIT51, "Address range error", "" }
        }
    },
    {
        //0xC0068
        SPIMST3_STATUS_REG,
        {
            { BIT00, "Receive data register full", "" },
            { BIT01, "Receive data register overrun", "" },
            { BIT02, "Receive data register underrun", "" },
            { BIT04, "Transmit data register full", "" },
            { BIT05, "Transmit data register overrun", "" },
            { BIT06, "Transmit data register underrun", "" },
            { BIT32, "Counter configuration register parity error", "" },
            { BIT33, "Clock configuration register parity error", "" },
            { BIT34, "Sequencer configuration register parity error", "" },
            { BIT35, "Sequencer fsm error", "" },
            { BIT36, "Shifter fsm error", "" },
            { BIT37, "Pattern match register parity error", "" },
            { BIT38, "Transmit data register parity error", "" },
            { BIT39, "Receive data register parity error", "" },
            { BIT40, "Configuration register 1 parity error", "" },
            { BIT42, "Error register parity error", "" },
            { BIT43, "Ecc correctable error", "" },
            { BIT44, "Ecc uncorrectable error", "" },
            { BIT47, "Memory mapped SPI address overlap", "" },
            { BIT50, "Port multiplexer error", "" },
            { BIT51, "Address range error", "" }
        }
    },
    {
        //0xC0088
        SPIMST4_STATUS_REG,
        {
            { BIT00, "Receive data register full", "" },
            { BIT01, "Receive data register overrun", "" },
            { BIT02, "Receive data register underrun", "" },
            { BIT04, "Transmit data register full", "" },
            { BIT05, "Transmit data register overrun", "" },
            { BIT06, "Transmit data register underrun", "" },
            { BIT32, "Counter configuration register parity error", "" },
            { BIT33, "Clock configuration register parity error", "" },
            { BIT34, "Sequencer configuration register parity error", "" },
            { BIT35, "Sequencer fsm error", "" },
            { BIT36, "Shifter fsm error", "" },
            { BIT37, "Pattern match register parity error", "" },
            { BIT38, "Transmit data register parity error", "" },
            { BIT39, "Receive data register parity error", "" },
            { BIT40, "Configuration register 1 parity error", "" },
            { BIT42, "Error register parity error", "" },
            { BIT43, "Ecc correctable error", "" },
            { BIT44, "Ecc uncorrectable error", "" },
            { BIT47, "Memory mapped SPI address overlap", "" },
            { BIT50, "Port multiplexer error", "" },
            { BIT51, "Address range error", "" }
        }
    },

    {
        //0xB0001 - EPF.FSI.W.FSI_SBE_FIFO.FSB_UPFIFO_STATUS
        SBEFIFO_UPSTREAM_STATUS,
        {
            { BIT06,  "UPFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset",  "" },
            { BIT07,  "UPFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset through downstream path",  "" },
            { BIT08,  "UPFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "UPFIFO_STATUS_FIFO_FULL: Upstream FIFO is full",  "" },
            { BIT11,  "UPFIFO_STATUS_FIFO_EMPTY: Upstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0011 - EPF.FSI.W.FSI_SBE_FIFO.FSB_DOWNFIFO_STATUS
        SBEFIFO_DOWNSTREAM_STATUS,
        {
            { BIT06,  "DNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT07,  "DNFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset through upstream path",  "" },
            { BIT08,  "DNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "DNFIFO_STATUS_FIFO_FULL: Downstream FIFO is full",  "" },
            { BIT11,  "DNFIFO_STATUS_FIFO_EMPTY: Downstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0021 - EPF.FSI.W.FSI_SBE_FIFO2.FSB_UPFIFO_STATUS
        SBEFIFO2_UPSTREAM_STATUS,
        {
            { BIT06,  "HUPFIFO_STATUS_REQ_RESET_FR_SP: Host is requesting a FIFO reset",  "" },
            { BIT07,  "HUPFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset through downstream path",  "" },
            { BIT08,  "HUPFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "HUPFIFO_STATUS_FIFO_FULL: Host Upstream FIFO is full",  "" },
            { BIT11,  "HUPFIFO_STATUS_FIFO_EMPTY: Host Upstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0031 - EPF.FSI.W.FSI_SBE_FIFO2.FSB_DOWNFIFO_STATUS
        SBEFIFO2_DOWNSTREAM_STATUS,
        {
            { BIT06,  "HDNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT07,  "HDNFIFO_STATUS_REQ_RESET_FR_SP: Host is requesting a FIFO reset through upstream path",  "" },
            { BIT08,  "HDNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "HDNFIFO_STATUS_FIFO_FULL: Host Downstream FIFO is full",  "" },
            { BIT11,  "HDNFIFO_STATUS_FIFO_EMPTY: Host Downstream FIFO is empty",  "" }
        }
    },
    {
        //0x88005 - EPP.PIB.PIBMEM_SBE.PIBMEM.CTRL_MAC.PIBMEM_STATUS_REG
        PIBMEM_STATUS,
        {
            { BIT00,  "ADDR_INVALID_PIB: Address which PIB is trying to access in PIBMEM is not valid one in PIBMEM",  "" },
            { BIT01,  "WRITE_INVALID_PIB: Address for which PIB is trying to write is not writable",  "" },
            { BIT02,  "READ_INVALID_PIB: Address for which PIB is trying to read is not readable",  "" },
            { BIT03,  "ECC_UNCORRECTED_ERROR_PIB: Uncorrectable error occurred while PIB memory read",  "" },
            { BIT04,  "ECC_CORRECTED_ERROR_PIB: Corrected error in PIB mem read",  "" },
            { BIT06,  "WRITE_RST_INTERRUPT_PIB: A reset occurred during write operation to PIBMEM from PIB side",  "" },
            { BIT07,  "READ_RST_INTERRUPT_PIB: A reset occurred during read operation to PIBMEM from PIB side",  "" },
            { BIT19,  "ADDR_INVALID_FACES: Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM",  "" },
            { BIT20,  "WRITE_INVALID_FACES: Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM or not writable",  "" },
            { BIT21,  "READ_INVALID_FACES: Address which is given by Fast acesss interface, to access is not readable",  "" },
            { BIT22,  "ECC_UNCORRECTED_ERROR_FACES: Uncorrectable error occurred while fast acess interface read",  "" },
            { BIT23,  "ECC_CORRECTED_ERROR_FACES: Corrected error in fast acess read operation . Data can still be considered as good",  "" },
            { BIT24,  "BAD_ARRAY_ADDRESS_FACES: Wrong address accessd in indirect mode of operation from fast acess interface",  "" },
            { BIT25,  "WRITE_RST_INTERRUPT_FACES: Reset occurred during write operation to PIBMEM from fast acess side",  "" },
            { BIT26,  "READ_RST_INTERRUPT_FACES: Reset occurred during read operation to PIBMEM from fast acess side",  "" }
        }
    },
    {
        //0x8800B - EPP.PIB.PIBMEM_SBE.PIBMEM.CTRL_MAC.ECC_CAPTURE_REG
        PIBMEM_ECC_CAPTURE,
        {
            { BIT00,  "ECC_CORRECTED_ERROR: Reports that ECC Corrected Error occured first unless cleared by writing to this register",  "" },
            { BIT01,  "ECC_UNCORRECTED_ERROR: Reports that ECC Uncorrected Error occured first unless cleared by writing to this register",  "" },
        }
    },

};


#endif
