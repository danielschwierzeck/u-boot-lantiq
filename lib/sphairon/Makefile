# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
#

obj-y += util.o
obj-y += flash.o flashlayout.o
obj-y += etl.o
obj-y += boot.o image.o
obj-y += controlfile.o
obj-y += init.o
obj-$(CONFIG_SPHAIRON_ZYCLIP) += zyclip.o

obj-y += cmd_sas_upgrade.o
obj-$(CONFIG_SPHAIRON_ZYCLIP) += cmd_sas_zyclip.o

ifneq ($(CONFIG_UART_BOOT),y)
obj-y += cmd_sas_boot.o
obj-y += cmd_sas_etl.o
obj-y += cmd_sas_controlfile.o
endif

subdir-ccflags-$(CONFIG_SPHAIRON_DEBUG) += -DDEBUG
