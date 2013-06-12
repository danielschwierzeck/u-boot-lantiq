#
# Copyright (C) 2000-2011 Wolfgang Denk, DENX Software Engineering, wd@denx.de
#
# SPDX-License-Identifier:	GPL-2.0+
#

include $(TOPDIR)/config.mk

LIB	= $(obj)liblantiq-common.o

START	= start.o
COBJS-y	= cpu.o pmu.o
COBJS-$(CONFIG_SPL_BUILD) += spl.o
SOBJS-y	= lowlevel_init.o

COBJS	:= $(COBJS-y)
SOBJS	:= $(SOBJS-y)
SRCS	:= $(START:.o=.S) $(SOBJS:.o=.S) $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(SOBJS) $(COBJS))
START	:= $(addprefix $(obj),$(START))

all:	$(LIB)

$(LIB):	$(obj).depend $(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
