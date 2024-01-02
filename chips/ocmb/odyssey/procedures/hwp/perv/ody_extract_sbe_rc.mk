# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p10/procedures/hwp/perv/p10_extract_sbe_rc.mk $
#
# OpenPOWER EKB Project
#
# COPYRIGHT 2015,2022
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG
PROCEDURE=ody_extract_sbe_rc
$(call ADD_MODULE_SRCDIR,$(PROCEDURE),$(ROOTPATH)/chips/ocmb/odyssey/procedures/hwp/utils)
OBJS+=ody_ppe_utils.o
$(call BUILD_PROCEDURE)
