#
# U-Boot - Makefile
#
# (C) Copyright 2000-2006
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:  GPL-2.0+
#

ifndef CONFIG_SPL_BUILD
obj-y += vr9.o  
else
#obj-$(CONFIG_NAND_PRELOAD) += start_nandpreload.o nand_preload.o
endif # CONFIG_SPL_BUILD

ifdef CONFIG_LTQ_BOOT_FROM_NAND
obj-$(CONFIG_SPL_BUILD) += nand_spl_board.o lowlevel_init.o
endif # CONFIG_LTQ_BOOT_FROM_NAND 

ifdef CONFIG_LTQ_BOOT_FROM_SPI
obj-$(CONFIG_SPL_BUILD) += lowlevel_init.o
obj-$(CONFIG_SPL_BUILD) += sfddr_board.o
endif # CONFIG_LTQ_BOOT_FROM_SPI

ifdef CONFIG_LTQ_BOOT_FROM_NOR
obj-$(CONFIG_SPL_BUILD) += lowlevel_init.o
endif

obj-$(CONFIG_SPL_BUILD) += ../common/tune_ddr.o

