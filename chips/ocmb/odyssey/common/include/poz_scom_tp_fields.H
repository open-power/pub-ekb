/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/ocmb/odyssey/common/include/poz_scom_tp_fields.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2023                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#pragma once
#include "scomt_regs.H"

#define SCOMT_PERV_USE_TP_CFAM_FSI_W_FSI2PIB_STATUS \
    _SCOMT_OPEN_NAMESPACE(poz) \
    class TP_CFAM_FSI_W_FSI2PIB_STATUS_t : public CfamRegister<0x1007> \
    { \
        public: \
            _SCOMT_CFAM_REGISTER_BEGIN(TP_CFAM_FSI_W_FSI2PIB_STATUS_t); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, ANY_ERROR, 0); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, SYSTEM_CHECKSTOP, 1); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, SPECIAL_ATTENTION, 2); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, RECOVERABLE_ERROR, 3); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, CHIPLET_INTERRUPT_FROM_HOST, 4); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, ANY_TAP_EVENT, 5); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, LOCAL_CHECKSTOP, 6); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, PROTECTION_CHECK, 7); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, POWER_MANAGEMENT_INTERRUPT, 8); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, RESERVED_9, 9); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, IDLE_INDICATION, 10); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, PIB_ABORT, 11); \
            _SCOMT_INT_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_RCS_ERROR_STATUS_DC, 12, 4); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, VDD_NEST_OBSERVE, 16); \
            _SCOMT_INT_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, PIB_ERROR_CODE, 17, 3); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_0_DC, 20); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_1_DC, 21); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_2_DC, 22); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_3_DC, 23); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_4_DC, 24); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_5_DC, 25); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_6_DC, 26); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, TP_TPFSI_PLL_LOCK_7_DC, 27); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, INTERRUPT_CONDITION_PENDING, 28); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, INTERRUPT_ENABLED, 29); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, SELFBOOT_ENGINE_ATTENTION, 30); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_FSI2PIB_STATUS_t, RESERVED_31, 31); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_PERV_USE_TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET \
    _SCOMT_OPEN_NAMESPACE(poz) \
    class TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_t : public CfamRegister<0x2414> \
    { \
        public: \
            _SCOMT_CFAM_REGISTER_BEGIN(TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_t); \
            _SCOMT_BOOL_FIELD(TP_CFAM_FSI_W_SBE_FIFO_FSB_DOWNFIFO_RESET_t, DNFIFO_RESET, 0); \
    }; _SCOMT_CLOSE_NAMESPACE

