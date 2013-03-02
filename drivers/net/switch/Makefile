#
# This file is released under the terms of GPL v2 and any later version.
# See the file COPYING in the root directory of the source tree for details.
#
# Copyright (C) 2000-2011 Wolfgang Denk, DENX Software Engineering, wd@denx.de
# Copyright (C) 2011-2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
#

include $(TOPDIR)/config.mk

LIB	:= $(obj)libswitch.o

COBJS-$(CONFIG_SWITCH_MULTI) += switch.o
COBJS-$(CONFIG_SWITCH_PSB697X) += psb697x.o

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
