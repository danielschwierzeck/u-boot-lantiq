#
# This file is released under the terms of GPL v2 and any later version.
# See the file COPYING in the root directory of the source tree for details.
#
# Copyright (C) 2000-2011 Wolfgang Denk, DENX Software Engineering, wd@denx.de
# Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
#

include $(TOPDIR)/config.mk

LIB	= $(obj)lib$(SOC).o

COBJS-y	+= cgu.o chipid.o ebu.o mem.o pmu.o rcu.o
SOBJS-y	+= cgu_init.o mem_init.o

COBJS	:= $(COBJS-y)
SOBJS	:= $(SOBJS-y)
SRCS	:= $(SOBJS:.o=.S) $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(SOBJS) $(COBJS))

all:	$(LIB)

$(LIB):	$(obj).depend $(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
