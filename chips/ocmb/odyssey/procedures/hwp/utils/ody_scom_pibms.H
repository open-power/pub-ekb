/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/procedures/hwp/utils/ody_scom_pibms.H $    */
/*                                                                        */
/* OpenPOWER EKB Project                                                  */
/*                                                                        */
/* COPYRIGHT 2016,2024                                                    */
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

#ifndef __ody_pibms_H_
#define __ody_pibms_H_

const uint64_t PERV_FSI2PIB_STATUS_FSI_ODY = 0x1007;
//const uint64_t PERV_TP_PLL_LOCK_REG = 0x010F0019;

const uint64_t PERV_CBS_CS_FSI_ODY = 0x2801;
const uint64_t PERV_SB_CS_FSI_ODY  = 0x2808;

const uint8_t  PERV_CBS_CS_SECURE_ACCESS_BIT_ODY = 4;
const uint8_t  PERV_SB_CS_SECURE_DEBUG_MODE_ODY  = 0;


const uint64_t OTP_STATUS_ODY           = 0x00010002;
const uint64_t OTP_SECURITY_SWITCH_ODY  = 0x00010005;
const uint64_t OTP_CONTROL_ODY          = 0x00010008;

const uint64_t MAILBOX_CBS_CTRL_STATUS_ODY           = 0x00050001;
const uint64_t MAILBOX_CBS_TRACE_ODY                 = 0x00050002;
const uint64_t MAILBOX_CBS_ENVSTAT_ODY               = 0x00050004;
const uint64_t MAILBOX_CBS_SELFBOOT_CTRL_STATUS_ODY  = 0x00050008;
const uint64_t MAILBOX_CBS_SELFBOOT_MSG_ODY          = 0x00050009;
const uint64_t MAILBOX_CBS_DEBUG_PERV_CLK_ODY        = 0x0005000B;
const uint64_t MAILBOX_ROOTCTRL0_ODY                 = 0x00050010;
const uint64_t MAILBOX_ROOTCTRL1_ODY                 = 0x00050011;
const uint64_t MAILBOX_ROOTCTRL2_ODY                 = 0x00050012;
const uint64_t MAILBOX_ROOTCTRL3_ODY                 = 0x00050013;
const uint64_t MAILBOX_ROOTCTRL4_ODY                 = 0x00050014;
const uint64_t MAILBOX_ROOTCTRL5_ODY                 = 0x00050015;
const uint64_t MAILBOX_ROOTCTRL6_ODY                 = 0x00050016;
const uint64_t MAILBOX_ROOTCTRL7_ODY                 = 0x00050017;
const uint64_t MAILBOX_ROOTCTRL8_ODY                 = 0x00050018;
const uint64_t MAILBOX_PERVCTRL0_ODY                 = 0x0005001A;
const uint64_t MAILBOX_PERVCTRL1_ODY                 = 0x0005001B;
const uint64_t MAILBOX_SCRATCH_REG_1_ODY             = 0x00050038;
const uint64_t MAILBOX_SCRATCH_REG_2_ODY             = 0x00050039;
const uint64_t MAILBOX_SCRATCH_REG_3_ODY             = 0x0005003A;
const uint64_t MAILBOX_SCRATCH_REG_4_ODY             = 0x0005003B;
const uint64_t MAILBOX_SCRATCH_REG_5_ODY             = 0x0005003C;
const uint64_t MAILBOX_SCRATCH_REG_6_ODY             = 0x0005003D;
const uint64_t MAILBOX_SCRATCH_REG_7_ODY             = 0x0005003E;
const uint64_t MAILBOX_SCRATCH_REG_8_ODY             = 0x0005003F;
const uint64_t MAILBOX_SCRATCH_REG_9_ODY             = 0x00050180;
const uint64_t MAILBOX_SCRATCH_REG_10_ODY            = 0x00050181;
const uint64_t MAILBOX_SCRATCH_REG_11_ODY            = 0x00050182;
const uint64_t MAILBOX_SCRATCH_REG_12_ODY            = 0x00050183;
const uint64_t MAILBOX_SCRATCH_REG_13_ODY            = 0x00050184;
const uint64_t MAILBOX_SCRATCH_REG_14_ODY            = 0x00050185;
const uint64_t MAILBOX_SCRATCH_REG_15_ODY            = 0x00050186;
const uint64_t MAILBOX_SCRATCH_REG_16_ODY            = 0x00050187;

const uint64_t PIBMEM_CTRL_ODY             = 0x000D0010;
const uint64_t PIBMEM_ADDR_PIB_ODY         = 0x000D0011;
const uint64_t PIBMEM_STATUS_ODY           = 0x000D0015;
const uint64_t PIBMEM_RESET_ODY            = 0x000D0016;

const uint64_t  SPICTL_ERR_INJECT          = 0x00070000;
const uint64_t  SPICTL_COUNTER             = 0x00070001;
const uint64_t  SPICTL_CONFIG              = 0x00070002;
const uint64_t  SPICTL_CLOCK_CONFIG        = 0x00070003;
const uint64_t  SPICTL_MEM_MAPPING         = 0x00070004;
const uint64_t  SPICTL_TRANSMIT_DATA_REG   = 0x00070005;
const uint64_t  SPICTL_RECEIVE_DATA_REG    = 0x00070006;
const uint64_t  SPICTL_SEQ_OP_REG          = 0x00070007;
const uint64_t  SPICTL_STATUS_REG          = 0x00070008;




const uint64_t     SBEFIFO_UPFIFO_STATUS   = 0x000B0001;
const uint64_t     SBEFIFO_HUPFIFO_STATUS   = 0x000B0021;
const uint64_t     SBEFIFO_DOWNFIFO_STATUS = 0x000B0011;
const uint64_t     SBEFIFO_HDOWNFIFO_STATUS = 0x000B0031;

const uint64_t I2CR_CONFIG_REG         = 0x00030000;
const uint64_t I2CR_STATUS_REG         = 0x00030001;
const uint64_t I2CR_ERROR_REG          = 0x00030002;
const uint64_t I2CR_SCRATCH_REG        = 0x00030003;
const uint64_t I2CR_FIRST_ERROR_LOG_REG          = 0x00030004;

const uint64_t PCB_REC_ERR_REG0         = 0x000F0011;
const uint64_t PCB_REC_ERR_REG1         = 0x000F0012;
const uint64_t PCB_REC_ERR_REG2         = 0x000F0013;
const uint64_t PCB_REC_ERR_REG3         = 0x000F0014;
const uint64_t PCB_FIRST_ERR            = 0x000F001E;

#endif
