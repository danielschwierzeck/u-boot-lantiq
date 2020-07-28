#
# SPDX-License-Identifier:  GPL-2.0+
#

ifdef CONFIG_SPL_BUILD
obj-y = nand_spl/
else
extra-y	+= start.o
extra-y	+= unlock_ejtag.o
head-y = start.o
endif

obj-y += clock.o
obj-y += cpu.o
obj-y += lowlevel_init.o

ifdef CONFIG_SPL_BUILD
obj-y += ibl.o
obj-y += init_exception.o
obj-y += init_vpe1.o
obj-y += interaptiv.o
endif
