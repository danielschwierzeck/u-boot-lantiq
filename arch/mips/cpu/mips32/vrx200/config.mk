#
# Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
#
# SPDX-License-Identifier:	GPL-2.0+
#

PF_CPPFLAGS_XRX := $(call cc-option,-mtune=34kc,)
PLATFORM_CPPFLAGS += $(PF_CPPFLAGS_XRX)

ifdef CONFIG_SPL_BUILD
PF_ABICALLS		:= -mno-abicalls
PF_PIC			:= -fno-pic
PF_PIE			:=
USE_PRIVATE_LIBGCC	:= yes
endif

LIBS-y += $(CPUDIR)/lantiq-common/liblantiq-common.o

ifndef CONFIG_SPL_BUILD
ifdef CONFIG_SYS_BOOT_SFSPL
ALL-y += $(obj)u-boot.ltq.sfspl
ALL-$(CONFIG_SPL_LZO_SUPPORT) += $(obj)u-boot.ltq.lzo.sfspl
ALL-$(CONFIG_SPL_LZMA_SUPPORT) += $(obj)u-boot.ltq.lzma.sfspl
endif
ifdef CONFIG_SYS_BOOT_NORSPL
ALL-y += $(obj)u-boot.ltq.norspl
ALL-$(CONFIG_SPL_LZO_SUPPORT) += $(obj)u-boot.ltq.lzo.norspl
ALL-$(CONFIG_SPL_LZMA_SUPPORT) += $(obj)u-boot.ltq.lzma.norspl
endif
ifdef CONFIG_SYS_BOOT_NANDSPL
ALL-y += $(obj)u-boot.ltq.nandspl
ALL-$(CONFIG_SPL_LZO_SUPPORT) += $(obj)u-boot.ltq.lzo.nandspl
ALL-$(CONFIG_SPL_LZMA_SUPPORT) += $(obj)u-boot.ltq.lzma.nandspl
endif
endif
