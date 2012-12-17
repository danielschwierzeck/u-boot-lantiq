#
# Copyright (C) 2000-2011 Wolfgang Denk, DENX Software Engineering, wd@denx.de
# Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
#
# SPDX-License-Identifier:	GPL-2.0+
#

include $(TOPDIR)/config.mk

LIB	:= $(obj)libswitch.o

COBJS-$(CONFIG_SWITCH_MULTI) += switch.o
COBJS-$(CONFIG_SWITCH_PSB697X) += psb697x.o
COBJS-$(CONFIG_SWITCH_ADM6996I) += adm6996i.o
COBJS-$(CONFIG_SWITCH_AR8216) += ar8216.o
COBJS-$(CONFIG_SWITCH_RTL8306) += rtl8306.o

COBJS	:= $(COBJS-y)
SRCS	:= $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS))

all:	$(LIB)

$(LIB):	$(obj).depend $(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
