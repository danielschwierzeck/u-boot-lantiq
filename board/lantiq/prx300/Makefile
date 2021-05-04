#
# U-Boot - Makefile
#
# (C) Copyright 2000-2006
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:  GPL-2.0+
#

ifndef CONFIG_SPL_BUILD
obj-y += prx300.o  
endif

obj-$(CONFIG_CMD_DDR_STATUS) += ddr_debug_status.o

ifdef CONFIG_LTQ_BOOT_FROM_NAND
obj-$(CONFIG_SPL_BUILD) += nand_spl_board.o
endif

ifdef CONFIG_LTQ_BOOT_FROM_SPI
obj-$(CONFIG_SPL_BUILD) += sfddr_board.o
endif

ifdef CONFIG_LTQ_BOOT_FROM_QSPI
obj-$(CONFIG_SPL_BUILD) += qspi_nor_board.o
endif

ifdef CONFIG_SPL_BUILD
obj-$(CONFIG_LTQ_SECURE_BOOT) += sb_arb.o
endif
