#
# Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
#
# SPDX-License-Identifier:	GPL-2.0+
#

PF_CPPFLAGS_XRX := $(call cc-option,-mtune=34kc,)
PLATFORM_CPPFLAGS += $(PF_CPPFLAGS_XRX)

libs-y += $(CPUDIR)/lantiq-common/

ifndef CONFIG_SPL_BUILD
ifdef CONFIG_SYS_BOOT_SFSPL
ALL-$(CONFIG_SPL_LZO_SUPPORT) += u-boot.ltq.lzo.sfspl
endif
ifdef CONFIG_SYS_BOOT_NANDSPL
ALL-$(CONFIG_SPL_LZO_SUPPORT) += u-boot.ltq.lzo.nandspl
endif
ifdef CONFIG_SYS_BOOT_NANDHWSPL
ALL-$(CONFIG_SPL_LZO_SUPPORT) += u-boot.ltq.lzo.nandhwspl
endif
endif
