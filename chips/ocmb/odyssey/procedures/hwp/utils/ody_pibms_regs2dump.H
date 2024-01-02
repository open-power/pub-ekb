/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_pibms_regs2dump.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2019,2023                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __PIBMS_REGS2DUMP_H__
#define __PIBMS_REGS2DUMP_H__

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
    {  0xD,    "PIBMEM"        },
    {  0xB,    "SBE FIFO"      },
    {  0x7,    "SPI CTL"       },
    {  0x3,    "I2CR"           },
    {  0xF,    "PCB CTL"    },
};

std::vector<sReg> const pibms_regs_2dump =
{
    //addr,                            name,                              attribute
    {OTP_STATUS,                       "OTP_STATUS",                      ERR_ATTR },  //0x10002, error status
    {OTP_CONTROL,                      "OTP_CONTROL",                     ERR_ATTR },  //0x10008, error status

    {MAILBOX_CBS_CTRL_STATUS,          "MAILBOX_CBS_CTRL_STATUS",          MBX_ATTR },  //0x50001, default
    {MAILBOX_CBS_TRACE,                "MAILBOX_CBS_TRACE",                MBX_ATTR },  //0x50002
    {MAILBOX_CBS_ENVSTAT,              "MAILBOX_CBS_ENVSTAT",              MBX_ATTR },  //0x50004
    {MAILBOX_CBS_SELFBOOT_CTRL_STATUS, "MAILBOX_CBS_SELFBOOT_CTRL_STATUS", MBX_ATTR },  //0x50008
    {MAILBOX_CBS_SELFBOOT_MSG,         "MAILBOX_CBS_SELFBOOT_MSG",         MBX_ATTR },  //0x50009
    {MAILBOX_CBS_DEBUG_PERV_CLK,       "MAILBOX_CBS_DEBUG_PERV_CLK",       MBX_ATTR },  //0x5000B
    {MAILBOX_ROOTCTRL0,                "MAILBOX_ROOTCTRL0",                MBX_ATTR },  //0x50010
    {MAILBOX_ROOTCTRL1,                "MAILBOX_ROOTCTRL1",                MBX_ATTR },  //0x50011
    {MAILBOX_ROOTCTRL2,                "MAILBOX_ROOTCTRL2",                MBX_ATTR },  //0x50012
    {MAILBOX_ROOTCTRL3,                "MAILBOX_ROOTCTRL3",                MBX_ATTR },  //0x50013
    {MAILBOX_ROOTCTRL4,                "MAILBOX_ROOTCTRL4",                MBX_ATTR },  //0x50014
    {MAILBOX_ROOTCTRL5,                "MAILBOX_ROOTCTRL5",                MBX_ATTR },  //0x50015
    {MAILBOX_ROOTCTRL6,                "MAILBOX_ROOTCTRL6",                MBX_ATTR },  //0x50016
    {MAILBOX_ROOTCTRL7,                "MAILBOX_ROOTCTRL7",                MBX_ATTR },  //0x50017
    {MAILBOX_ROOTCTRL8,                "MAILBOX_ROOTCTRL8",                MBX_ATTR },  //0x50018
    {MAILBOX_PERVCTRL0,                "MAILBOX_PERVCTRL0",                MBX_ATTR },  //0x5001A
    {MAILBOX_PERVCTRL1,                "MAILBOX_PERVCTRL1",                MBX_ATTR },  //0x5001B
    {MAILBOX_SCRATCH_REG_1,            "MAILBOX_SCRATCH_REG_1",            MBX_ATTR },  //0x50038
    {MAILBOX_SCRATCH_REG_2,            "MAILBOX_SCRATCH_REG_2",            MBX_ATTR },  //0x50039
    {MAILBOX_SCRATCH_REG_3,            "MAILBOX_SCRATCH_REG_3",            MBX_ATTR },  //0x5003A
    {MAILBOX_SCRATCH_REG_4,            "MAILBOX_SCRATCH_REG_4",            MBX_ATTR },  //0x5003B
    {MAILBOX_SCRATCH_REG_5,            "MAILBOX_SCRATCH_REG_5",            MBX_ATTR },  //0x5003C
    {MAILBOX_SCRATCH_REG_6,            "MAILBOX_SCRATCH_REG_6",            MBX_ATTR },  //0x5003D
    {MAILBOX_SCRATCH_REG_7,            "MAILBOX_SCRATCH_REG_7",            MBX_ATTR },  //0x5003E
    {MAILBOX_SCRATCH_REG_8,            "MAILBOX_SCRATCH_REG_8",            MBX_ATTR },  //0x5003F
    {MAILBOX_SCRATCH_REG_9,            "MAILBOX_SCRATCH_REG_9",            MBX_ATTR },  //0x50180
    {MAILBOX_SCRATCH_REG_10,           "MAILBOX_SCRATCH_REG_10",           MBX_ATTR },  //0x50181
    {MAILBOX_SCRATCH_REG_11,           "MAILBOX_SCRATCH_REG_11",           MBX_ATTR },  //0x50182
    {MAILBOX_SCRATCH_REG_12,           "MAILBOX_SCRATCH_REG_12",           MBX_ATTR },  //0x50183
    {MAILBOX_SCRATCH_REG_13,           "MAILBOX_SCRATCH_REG_13",           MBX_ATTR },  //0x50184
    {MAILBOX_SCRATCH_REG_14,           "MAILBOX_SCRATCH_REG_14",           MBX_ATTR },  //0x50185
    {MAILBOX_SCRATCH_REG_15,           "MAILBOX_SCRATCH_REG_15",           MBX_ATTR },  //0x50186
    {MAILBOX_SCRATCH_REG_16,           "MAILBOX_SCRATCH_REG_16",           MBX_ATTR },  //0x50187

    {PIBMEM_CTRL,                      "PIBMEM_CTRL",                     SDB_ATTR },  //0x88000
    {PIBMEM_ADDR_PIB,                  "PIBMEM_ADDR_PIB",                 SDB_ATTR },  //0x88001
    {PIBMEM_STATUS,                    "PIBMEM_STATUS",               ERR_SDB_ATTR },  //0x88005
    {PIBMEM_RESET,                     "PIBMEM_RESET",                    SDB_ATTR },  //0x88006


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
        MAILBOX_SCRATCH_REG_1,  //print bits0-63
        {
            { 0x1003F,  "RESERVED",  "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_2,  //print  bits0-63
        {
            { 0x1003F,  "RESERVED",           "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_3,
        {
            { 0x1003F,  "RESERVED",                 "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_4,
        {
            { 0x1003F,  "RESERVED",                 "" }

        }
    },
    {
        MAILBOX_SCRATCH_REG_5,
        {
            { 0x1000C,  "Ref clock SPI bus divider",  "" },
            { 0x10C04,  "Round trip delay",  "" },
            { 0x11010,  "RESERVED",  "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_6,
        {
            { 0x10003,  "Odessey PLL Ring Select",           "" },
            { 0x11010,  "Odyssey Nest freq (in MHz) ",           "" }

        }
    },
    {
        MAILBOX_SCRATCH_REG_7,
        {
            { 0x10A02,  "Clockstop on checkstop options ",  "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_8,
        {
            { BIT00,  "OCMB PLL in  bypass ",                 "" }
        }
    },
    {
        MAILBOX_SCRATCH_REG_11,
        {
            { BIT00,  "Used by SBE, HB - FW ISTEP_MODE",                 "" },
            { BIT01,  "SBE should go directly to runtime functionality", "" },
            { BIT02,  "RESERVED",        "" },
            { BIT03,  "RESERVED", "" },
            { BIT06,  "Security disabled",         "" },
            { BIT07,  "Allow attribute overrides", "" }
        }
    },

    {
        //0xC0083
        SPICTL_CLOCK_CONFIG, // bit 0-11, bit 31, bit 32-35
        {
            { 0x1000C, "SPI master4 clock divider", "" },
            { BIT31, "mmSPIsm enabled", "" },
            { 0x12004, "Hardware reset signal for spi slave", "" }
        }
    },
    {
        //0xC0088
        SPICTL_STATUS_REG,
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
        SBEFIFO_HUPFIFO_STATUS,
        {
            { BIT07,  "HUPFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset",  "" },
            { BIT06,  "HUPFIFO_STATUS_REQ_RESET_FR_SP: Host is requesting a FIFO reset",  "" },
            { BIT08,  "HUPFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "HUPFIFO_STATUS_FIFO_FULL: HOST Upstream FIFO is full",  "" },
            { BIT11,  "HUPFIFO_STATUS_FIFO_EMPTY: HOST Upstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0011 - EPF.FSI.W.FSI_SBE_FIFO.FSB_DOWNFIFO_STATUS
        SBEFIFO_DOWNFIFO_STATUS,
        {
            { BIT07,  "DNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT06,  "DNFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset through upstream path",  "" },
            { BIT08,  "DNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "DNFIFO_STATUS_FIFO_FULL: Downstream FIFO is full",  "" },
            { BIT11,  "DNFIFO_STATUS_FIFO_EMPTY: Downstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0001 - EPF.FSI.W.FSI_SBE_FIFO.FSB_UPFIFO_STATUS
        SBEFIFO_HDOWNFIFO_STATUS,
        {
            { BIT06,  "HDNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT07,  "HDNFIFO_STATUS_REQ_RESET_FR_SP: Host is requesting a FIFO reset",  "" },
            { BIT08,  "HDNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "HDNFIFO_STATUS_FIFO_FULL: HOST Upstream FIFO is full",  "" },
            { BIT11,  "HDNFIFO_STATUS_FIFO_EMPTY: HOST Upstream FIFO is empty",  "" }
        }
    },
    {
        //0xB0011 - EPF.FSI.W.FSI_SBE_FIFO.FSB_DOWNFIFO_STATUS
        SBEFIFO_UPFIFO_STATUS,
        {
            { BIT07,  "DNFIFO_STATUS_REQ_RESET_FR_SBE: SBE is requesting a FIFO reset",  "" },
            { BIT06,  "DNFIFO_STATUS_REQ_RESET_FR_SP: External Service Processor (SP) is requesting a FIFO reset through downstream path",  "" },
            { BIT08,  "DNFIFO_STATUS_DEQUEUED_EOT_FLAG: A fifo entry has been dequeued with set EOT flag",  "" },
            { BIT10,  "DNFIFO_STATUS_FIFO_FULL: Upstream FIFO is full",  "" },
            { BIT11,  "DNFIFO_STATUS_FIFO_EMPTY: Upstream FIFO is empty",  "" }
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

};


#endif

