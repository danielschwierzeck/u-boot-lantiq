#
# Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
#
# SPDX-License-Identifier:	GPL-2.0+
#

obj-y = cpu.o pmu.o
obj-y += lowlevel_init.o
obj-$(CONFIG_LTQ_SPL_MC_TUNE) += mem.o
obj-$(CONFIG_SPL_BUILD) += spl.o
extra-$(CONFIG_SPL_BUILD) += start.o
