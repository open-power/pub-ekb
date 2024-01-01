# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/ocmb/odyssey/procedures/hwp/utils/generic_utils.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2022,2023
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG
#
# A macro to contain all our boilerplate
#
define __GENERIC_UTIL_PROCEDURE
PROCEDURE=$(1)
$$(call ADD_MODULE_SHARED_OBJ,$$(PROCEDURE),ody_ppe_utils.o)
$$(call BUILD_PROCEDURE)
endef
GENERIC_UTIL_PROCEDURE = $(eval $(call __GENERIC_UTIL_PROCEDURE,$1))

define __GENERIC_PPE_PROCEDURE
PROCEDURE=$(1)
$$(call ADD_MODULE_SHARED_OBJ,$$(PROCEDURE),ody_ppe_utils.o)
$$(call BUILD_PROCEDURE)
endef
GENERIC_PPE_PROCEDURE = $(eval $(call __GENERIC_PPE_PROCEDURE,$1))


#
# And now the actual HWP definitions
#
$(call GENERIC_UTIL_PROCEDURE,ody_pibms_reg_dump)
$(call GENERIC_UTIL_PROCEDURE,ody_sbe_localreg_dump)
$(call GENERIC_UTIL_PROCEDURE,ody_pibmem_dump)