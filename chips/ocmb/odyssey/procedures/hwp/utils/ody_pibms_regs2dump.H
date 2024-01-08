/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_pibms_regs2dump.H $ */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2019,2024                                                    */
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
#ifndef __ODY_PIBMS_REGS2DUMP_H__
#define __ODY_PIBMS_REGS2DUMP_H__

#include <map>
#include <vector>
#include "ody_scom_pibms.H"

#define ADDR_LEN     8      //register address length
#define VALUE_LEN   16      //register value length

//specify register attribute
#define NO_ATTR        0x00   //default
#define ERR_ATTR       0x01   //error status register
#define SDB_ATTR       0x02   //can be accessed in SDB mode
#define ERR_SDB_ATTR   0x03   //error status register, which can be accessed in SDB mode
#define VLD_ATTR       0x04   //value is already available (may not need this)
#define MBX_ATTR       0x08   //MBX to be read in cfam scope
#define HELP_RC  999


#define CHKRC_BREAK(msg)  if (rc) { ecmdOutput(msg); break; }
#define CHKRC_RETRUN(msg) if (rc) { ecmdOutput(msg); return rc; }
#define RETURN_HELP(rc, msg)   { ecmdOutput(msg); help(); return rc; }

enum eREGBITS_ody
{
    BIT00_ODY, BIT01_ODY, BIT02_ODY, BIT03_ODY, BIT04_ODY, BIT05_ODY, BIT06_ODY, BIT07_ODY,
    BIT08_ODY, BIT09_ODY, BIT10_ODY, BIT11_ODY, BIT12_ODY, BIT13_ODY, BIT14_ODY, BIT15_ODY,
    BIT16_ODY, BIT17_ODY, BIT18_ODY, BIT19_ODY, BIT20_ODY, BIT21_ODY, BIT22_ODY, BIT23_ODY,
    BIT24_ODY, BIT25_ODY, BIT26_ODY, BIT27_ODY, BIT28_ODY, BIT29_ODY, BIT30_ODY, BIT31_ODY,
    BIT32_ODY, BIT33_ODY, BIT34_ODY, BIT35_ODY, BIT36_ODY, BIT37_ODY, BIT38_ODY, BIT39_ODY,
    BIT40_ODY, BIT41_ODY, BIT42_ODY, BIT43_ODY, BIT44_ODY, BIT45_ODY, BIT46_ODY, BIT47_ODY,
    BIT48_ODY, BIT49_ODY, BIT50_ODY, BIT51_ODY, BIT52_ODY, BIT53_ODY, BIT54_ODY, BIT55_ODY,
    BIT56_ODY, BIT57_ODY, BIT58_ODY, BIT59_ODY, BIT60_ODY, BIT61_ODY, BIT62_ODY, BIT63_ODY
};

typedef struct
{
    uint64_t    addr;
    std::string name;
    uint32_t    attr;  //register attribute
} sRegOdy;

typedef struct
{
    sRegOdy     reg;
    uint64_t value;
} sRegVOdy;

typedef struct
{
    uint32_t    bit;   //bit index
    std::string des1;  //description when bit is set to 1
    std::string des0;  //description when bit is set to 0
} sRegBitOdy;

//List what chiplet registers need to dump
//scom id ---> unit name
std::map<uint64_t, std::string> const pibmsUnitMap_ody
{
    {  0x1,    "OTPROM"        },
    {  0x5,    "FSI MAILBOX"   },
    {  0xD,    "PIBMEM"        },
    {  0xB,    "SBE FIFO"      },
    {  0x7,    "SPI CTL"       },
    {  0x3,    "I2CR"           },
    {  0xF,    "PCB CTL"    },
};

std::vector<sRegOdy> const pibms_regs_2dump_ody =
{
    //addr,                            name,                              attribute
    {OTP_STATUS_ODY,                       "OTP_STATUS",                      ERR_ATTR },  //0x10002, error status
    {OTP_CONTROL_ODY,                      "OTP_CONTROL",                     ERR_ATTR },  //0x10008, error status

    {MAILBOX_CBS_CTRL_STATUS_ODY,          "MAILBOX_CBS_CTRL_STATUS",          MBX_ATTR },  //0x50001, default
    {MAILBOX_CBS_TRACE_ODY,                "MAILBOX_CBS_TRACE",                MBX_ATTR },  //0x50002
    {MAILBOX_CBS_ENVSTAT_ODY,              "MAILBOX_CBS_ENVSTAT",              MBX_ATTR },  //0x50004
    {MAILBOX_CBS_SELFBOOT_CTRL_STATUS_ODY, "MAILBOX_CBS_SELFBOOT_CTRL_STATUS", MBX_ATTR },  //0x50008
    {MAILBOX_CBS_SELFBOOT_MSG_ODY,         "MAILBOX_CBS_SELFBOOT_MSG",         MBX_ATTR },  //0x50009
    {MAILBOX_CBS_DEBUG_PERV_CLK_ODY,       "MAILBOX_CBS_DEBUG_PERV_CLK",       MBX_ATTR },  //0x5000B
    {MAILBOX_ROOTCTRL0_ODY,                "MAILBOX_ROOTCTRL0",                MBX_ATTR },  //0x50010
    {MAILBOX_ROOTCTRL1_ODY,                "MAILBOX_ROOTCTRL1",                MBX_ATTR },  //0x50011
    {MAILBOX_ROOTCTRL2_ODY,                "MAILBOX_ROOTCTRL2",                MBX_ATTR },  //0x50012
    {MAILBOX_ROOTCTRL3_ODY,                "MAILBOX_ROOTCTRL3",                MBX_ATTR },  //0x50013
    {MAILBOX_ROOTCTRL4_ODY,                "MAILBOX_ROOTCTRL4",                MBX_ATTR },  //0x50014
    {MAILBOX_ROOTCTRL5_ODY,                "MAILBOX_ROOTCTRL5",                MBX_ATTR },  //0x50015
    {MAILBOX_ROOTCTRL6_ODY,                "MAILBOX_ROOTCTRL6",                MBX_ATTR },  //0x50016
    {MAILBOX_ROOTCTRL7_ODY,                "MAILBOX_ROOTCTRL7",                MBX_ATTR },  //0x50017
    {MAILBOX_ROOTCTRL8_ODY,                "MAILBOX_ROOTCTRL8",                MBX_ATTR },  //0x50018
    {MAILBOX_PERVCTRL0_ODY,                "MAILBOX_PERVCTRL0",                MBX_ATTR },  //0x5001A
    {MAILBOX_PERVCTRL1_ODY,                "MAILBOX_PERVCTRL1",                MBX_ATTR },  //0x5001B
    {MAILBOX_SCRATCH_REG_1_ODY,            "MAILBOX_SCRATCH_REG_1",            MBX_ATTR },  //0x50038
    {MAILBOX_SCRATCH_REG_2_ODY,            "MAILBOX_SCRATCH_REG_2",            MBX_ATTR },  //0x50039
    {MAILBOX_SCRATCH_REG_3_ODY,            "MAILBOX_SCRATCH_REG_3",            MBX_ATTR },  //0x5003A
    {MAILBOX_SCRATCH_REG_4_ODY,            "MAILBOX_SCRATCH_REG_4",            MBX_ATTR },  //0x5003B
    {MAILBOX_SCRATCH_REG_5_ODY,            "MAILBOX_SCRATCH_REG_5",            MBX_ATTR },  //0x5003C
    {MAILBOX_SCRATCH_REG_6_ODY,            "MAILBOX_SCRATCH_REG_6",            MBX_ATTR },  //0x5003D
    {MAILBOX_SCRATCH_REG_7_ODY,            "MAILBOX_SCRATCH_REG_7",            MBX_ATTR },  //0x5003E
    {MAILBOX_SCRATCH_REG_8_ODY,            "MAILBOX_SCRATCH_REG_8",            MBX_ATTR },  //0x5003F
    {MAILBOX_SCRATCH_REG_9_ODY,            "MAILBOX_SCRATCH_REG_9",            MBX_ATTR },  //0x50180
    {MAILBOX_SCRATCH_REG_10_ODY,           "MAILBOX_SCRATCH_REG_10",           MBX_ATTR },  //0x50181
    {MAILBOX_SCRATCH_REG_11_ODY,           "MAILBOX_SCRATCH_REG_11",           MBX_ATTR },  //0x50182
    {MAILBOX_SCRATCH_REG_12_ODY,           "MAILBOX_SCRATCH_REG_12",           MBX_ATTR },  //0x50183
    {MAILBOX_SCRATCH_REG_13_ODY,           "MAILBOX_SCRATCH_REG_13",           MBX_ATTR },  //0x50184
    {MAILBOX_SCRATCH_REG_14_ODY,           "MAILBOX_SCRATCH_REG_14",           MBX_ATTR },  //0x50185
    {MAILBOX_SCRATCH_REG_15_ODY,           "MAILBOX_SCRATCH_REG_15",           MBX_ATTR },  //0x50186
    {MAILBOX_SCRATCH_REG_16_ODY,           "MAILBOX_SCRATCH_REG_16",           MBX_ATTR },  //0x50187

    {PIBMEM_CTRL_ODY,                      "PIBMEM_CTRL",                     SDB_ATTR },  //0x88000
    {PIBMEM_ADDR_PIB_ODY,                  "PIBMEM_ADDR_PIB",                 SDB_ATTR },  //0x88001
    {PIBMEM_STATUS_ODY,                    "PIBMEM_STATUS",               ERR_SDB_ATTR },  //0x88005
    {PIBMEM_RESET_ODY,                     "PIBMEM_RESET",                    SDB_ATTR },  //0x88006


    {SPICTL_ERR_INJECT,                  "SPICTL_ERR_INJECT",         NO_ATTR},   //C0080
    {SPICTL_COUNTER,                     "SPICTL_COUNTER",            NO_ATTR},   //C0081
    {SPICTL_CONFIG,                      "SPICTL_CONFIG",             NO_ATTR},   //C0082
    {SPICTL_CLOCK_CONFIG,                "SPICTL_CLOCK_CONFIG",       NO_ATTR},   //C0083
    {SPICTL_MEM_MAPPING,                 "SPICTL_MEM_MAPPING",        NO_ATTR},   //C0084
    {SPICTL_TRANSMIT_DATA_REG,           "SPICTL_TRANSMIT_DATA_REG",  NO_ATTR},   //C0085
    {SPICTL_RECEIVE_DATA_REG,            "SPICTL_RECEIVE_DATA_REG",   NO_ATTR},   //C0086
    {SPICTL_SEQ_OP_REG,                  "SPICTL_SEQ_OP_REG",         NO_ATTR},   //C0087
    {SPICTL_STATUS_REG,                  "SPICTL_STATUS_REG",         NO_ATTR},   //C0088


    {SBEFIFO_UPFIFO_STATUS,           "SBEFIFO_UPFIFO_STATUS",            ERR_ATTR},  //0xB0001 EPF.FSI.W.FSI_SBE_FIFO.FSB_UPFIFO_STATUS
    {SBEFIFO_DOWNFIFO_STATUS,         "SBEFIFO_DOWNFIFO_STATUS",          ERR_ATTR},  //0xB0011 EPF.FSI.W.FSI_SBE_FIFO.FSB_DOWNFIFO_STATUS
    {SBEFIFO_HDOWNFIFO_STATUS,        "SBEFIFO2_HDOWNFIFO_STATUS",        ERR_ATTR},  //0xB0021 EPF.FSI.W.FSI_SBE_FIFO2.FSB_UPFIFO_STATUS



    {I2CR_CONFIG_REG,                 "I2CR_CONFIG_REG",                   NO_ATTR},
    {I2CR_STATUS_REG,                 "I2CR_STATUS_REG",                   NO_ATTR},
    {I2CR_ERROR_REG,                  "I2CR_ERROR_REG",                    NO_ATTR},
    {I2CR_SCRATCH_REG,                "I2CR_SCRATCH_REG",                  NO_ATTR},
    {I2CR_FIRST_ERROR_LOG_REG,        "I2CR_FIRST_ERROR_LOG_REG",          NO_ATTR},



    {PCB_REC_ERR_REG0,                "PCB_REC_ERR_REG0",                  NO_ATTR },  //0xF0011  EPP.PIB.PCBMS.REC_ERR_REG0
    {PCB_REC_ERR_REG1,                "PCB_REC_ERR_REG1",                  NO_ATTR },  //0xF0012  EPP.PIB.PCBMS.REC_ERR_REG1
    {PCB_REC_ERR_REG2,                "PCB_REC_ERR_REG2",                  NO_ATTR },  //0xF0013  EPP.PIB.PCBMS.REC_ERR_REG2
    {PCB_REC_ERR_REG3,                "PCB_REC_ERR_REG3",                  NO_ATTR },  //0xF0014  EPP.PIB.PCBMS.REC_ERR_REG3
    {PCB_FIRST_ERR,                   "PCB_FIRST_ERR",                     NO_ATTR },  //0xF001E  EPP.PIB.PCBMS.FIRST_ERR_REG
};


//key:   register address
//value: register bits' definition
std::map<uint64_t, std::vector<sRegBitOdy>> const pibmsRegs_ody
{
    //0x10002 - EPP.PIB.OTP.OTPC_M.STATUS_REGISTER
    {
        OTP_STATUS_ODY,
        {
            { BIT00_ODY,  "STATUS_ADDR_NVLD: Address invalid", "" },
            { BIT01_ODY,  "STATUS_WRITE_NVLD: Write invalid",  "" },
            { BIT02_ODY,  "STATUS_READ_NVLD: Read invalid",    "" },
            { BIT03_ODY,  "STATUS_INVLD_CMD_ERR: Invalid command register fields programmed", "" },
            { BIT04_ODY,  "STATUS_CORR_ERR: ECC Correctable error",                 "" },
            { BIT05_ODY,  "STATUS_UNCORR_ERROR: ECC Uncorrectable error",           "" },
            { BIT45_ODY,  "STATUS_DCOMP_ERR: Decompression Engine Error",           "" },
            { BIT46_ODY,  "STATUS_INVLD_PRGM_ERR: Invalid Program Operation error", "" }
        }
    },
    //0x10008 - OTP_CONTROL
    {
        OTP_CONTROL_ODY,
        {
            { BIT00_ODY,  "MODE_DCOMP_ENABLE: Decompression Engine enabled", "" },
            { BIT01_ODY,  "MODE_ECC_ENABLE: ECC checking enabled",  "" },
            { BIT03_ODY,  "MODE_ECC_CHK_DISABLE: ECC check disabled",    "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_1_ODY,  //print bits0-63
        {
            { 0x1003F,  "RESERVED",  "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_2_ODY,  //print  bits0-63
        {
            { 0x1003F,  "RESERVED",           "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_3_ODY,
        {
            { 0x1003F,  "RESERVED",                 "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_4_ODY,
        {
            { 0x1003F,  "RESERVED",                 "" }

        }
    },
    {
        MAILBOX_SCRATCH_REG_5_ODY,
        {
            { 0x1000C,  "Ref clock SPI bus divider",  "" },
            { 0x10C04,  "Round trip delay",  "" },
            { 0x11010,  "RESERVED",  "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_6_ODY,
        {
            { 0x10003,  "Odessey PLL Ring Select",           "" },
            { 0x11010,  "Odyssey Nest freq (in MHz) ",           "" }

        }
    },
    {
        MAILBOX_SCRATCH_REG_7_ODY,
        {
            { 0x10A02,  "Clockstop on checkstop options ",  "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_8_ODY,
        {
            { BIT00_ODY,  "OCMB PLL in  bypass ",                 "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_11_ODY,
        {
            { BIT00_ODY,  "Used by SBE, HB - FW ISTEP_MODE",                 "" },
            { BIT01_ODY,  "SBE should go directly to runtime functionality", "" },
            { BIT02_ODY,  "RESERVED",        "" },
            { BIT03_ODY,  "RESERVED", "" },
            { BIT06_ODY,  "Security disabled",         "" },
            { BIT07_ODY,  "Allow attribute overrides", "" }
        }
    },

    {
        //0xC0083
        SPICTL_CLOCK_CONFIG, // bit 0-11, bit 31, bit 32-35
        {
            { 0x1000C, "SPI master4 clock divider", "" },
            { BIT31_ODY, "mmSPIsm enabled", "" },
            { 0x12004, "Hardware reset signal for spi slave", "" }
        }
    },
    {
        //0xC0088
        SPICTL_STATUS_REG,
        {
            { BIT00_ODY, "Receive data register full", "" },
            { BIT01_ODY, "Receive data register overrun", "" },
            { BIT02_ODY, "Receive data register underrun", "" },
            { BIT04_ODY, "Transmit data register full", "" },
            { BIT05_ODY, "Transmit data register overrun", "" },
            { BIT06_ODY, "Transmit data register underrun", "" },
            { BIT32_ODY, "Counter configuration register parity error", "" },
            { BIT33_ODY, "Clock configuration register parity error", "" },
            { BIT34_ODY, "Sequencer configuration register parity error", "" },
            { BIT35_ODY, "Sequencer fsm error", "" },
            { BIT36_ODY, "Shifter fsm error", "" },
            { BIT37_ODY, "Pattern match register parity error", "" },
            { BIT38_ODY, "Transmit data register parity error", "" },
            { BIT39_ODY, "Receive data register parity error", "" },
            { BIT40_ODY, "Configuration register 1 parity error", "" },
            { BIT42_ODY, "Error register parity error", "" },
            { BIT43_ODY, "Ecc correctable error", "" },
            { BIT44_ODY, "Ecc uncorrectable error", "" },
            { BIT47_ODY, "Memory mapped SPI address overlap", "" },
            { BIT50_ODY, "Port multiplexer error", "" },
            { BIT51_ODY, "Address range error", "" }
        }
    },


    {
        //0xB0001 - EPF.FSI.W.FSI_SBE_FIFO.FSB_UPFIFO_STATUS
        SBEFIFO_HUPFIFO_STATUS,
        {
            { BIT07_ODY,  "HUPFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset",  "" },
            { BIT06_ODY,  "HUPFIFO_STATUS_REQ_RESET_FR_SP: Host is requesting a FIFO reset",  "" },
            { BIT08_ODY,  "HUPFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10_ODY,  "HUPFIFO_STATUS_FIFO_FULL: HOST Upstream FIFO is full",  "" },
            { BIT11_ODY,  "HUPFIFO_STATUS_FIFO_EMPTY: HOST Upstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0011 - EPF.FSI.W.FSI_SBE_FIFO.FSB_DOWNFIFO_STATUS
        SBEFIFO_DOWNFIFO_STATUS,
        {
            { BIT07_ODY,  "DNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT06_ODY,  "DNFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset through upstream path",  "" },
            { BIT08_ODY,  "DNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10_ODY,  "DNFIFO_STATUS_FIFO_FULL: Downstream FIFO is full",  "" },
            { BIT11_ODY,  "DNFIFO_STATUS_FIFO_EMPTY: Downstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0001 - EPF.FSI.W.FSI_SBE_FIFO.FSB_UPFIFO_STATUS
        SBEFIFO_HDOWNFIFO_STATUS,
        {
            { BIT06_ODY,  "HDNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT07_ODY,  "HDNFIFO_STATUS_REQ_RESET_FR_SP: Host is requesting a FIFO reset",  "" },
            { BIT08_ODY,  "HDNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10_ODY,  "HDNFIFO_STATUS_FIFO_FULL: HOST Upstream FIFO is full",  "" },
            { BIT11_ODY,  "HDNFIFO_STATUS_FIFO_EMPTY: HOST Upstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0011 - EPF.FSI.W.FSI_SBE_FIFO.FSB_DOWNFIFO_STATUS
        SBEFIFO_UPFIFO_STATUS,
        {
            { BIT07_ODY,  "DNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT06_ODY,  "DNFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset through downstream path",  "" },
            { BIT08_ODY,  "DNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10_ODY,  "DNFIFO_STATUS_FIFO_FULL: Upstream FIFO is full",  "" },
            { BIT11_ODY,  "DNFIFO_STATUS_FIFO_EMPTY: Upstream FIFO is empty",  "" }
        }
    },

    {
        //0x88005 - EPP.PIB.PIBMEM_SBE.PIBMEM.CTRL_MAC.PIBMEM_STATUS_REG
        PIBMEM_STATUS_ODY,
        {
            { BIT00_ODY,  "ADDR_INVALID_PIB: Address which PIB is trying to access in PIBMEM is not valid one in PIBMEM",  "" },
            { BIT01_ODY,  "WRITE_INVALID_PIB: Address for which PIB is trying to write is not writable",  "" },
            { BIT02_ODY,  "READ_INVALID_PIB: Address for which PIB is trying to read is not readable",  "" },
            { BIT03_ODY,  "ECC_UNCORRECTED_ERROR_PIB: Uncorrectable error occurred while PIB memory read",  "" },
            { BIT04_ODY,  "ECC_CORRECTED_ERROR_PIB: Corrected error in PIB mem read",  "" },
            { BIT06_ODY,  "WRITE_RST_INTERRUPT_PIB: A reset occurred during write operation to PIBMEM from PIB side",  "" },
            { BIT07_ODY,  "READ_RST_INTERRUPT_PIB: A reset occurred during read operation to PIBMEM from PIB side",  "" },
            { BIT19_ODY,  "ADDR_INVALID_FACES: Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM",  "" },
            { BIT20_ODY,  "WRITE_INVALID_FACES: Address which is given by Fast acesss interface, to access in PIBMEM is not valid one in PIBMEM or not writable",  "" },
            { BIT21_ODY,  "READ_INVALID_FACES: Address which is given by Fast acesss interface, to access is not readable",  "" },
            { BIT22_ODY,  "ECC_UNCORRECTED_ERROR_FACES: Uncorrectable error occurred while fast acess interface read",  "" },
            { BIT23_ODY,  "ECC_CORRECTED_ERROR_FACES: Corrected error in fast acess read operation . Data can still be considered as good",  "" },
            { BIT24_ODY,  "BAD_ARRAY_ADDRESS_FACES: Wrong address accessd in indirect mode of operation from fast acess interface",  "" },
            { BIT25_ODY,  "WRITE_RST_INTERRUPT_FACES: Reset occurred during write operation to PIBMEM from fast acess side",  "" },
            { BIT26_ODY,  "READ_RST_INTERRUPT_FACES: Reset occurred during read operation to PIBMEM from fast acess side",  "" }
        }
    },

};


#endif
