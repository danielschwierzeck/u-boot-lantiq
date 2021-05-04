#
# U-Boot - Makefile
#
# (C) Copyright 2000-2006
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:  GPL-2.0+
#

ifndef CONFIG_SPL_BUILD
obj-y += datapath_clear.o grx500.o
endif

ifdef CONFIG_LTQ_BOOT_FROM_NAND
obj-$(CONFIG_SPL_BUILD) += nand_spl_board.o
endif

ifdef CONFIG_LTQ_BOOT_FROM_SPI
#obj-$(CONFIG_SPL_BUILD) += lowlevel_init.o
obj-$(CONFIG_SPL_BUILD) += sfddr_board.o
endif

obj-$(CONFIG_GRX500_THERMAL) += thermal.o
