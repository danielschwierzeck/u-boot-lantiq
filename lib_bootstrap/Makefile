#
# (C) Copyright 2003
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

include $(TOPDIR)/config.mk

LIB	= libbootstrap.a

ifdef CONFIG_LANTIQ_UBOOT_amazon_se
  OBJS  = bootstrap_board.o
else
ifdef CONFIG_LANTIQ_UBOOT_vbg400
  OBJS  = bootstrap_board.o efuse_handling.o
else
  ifdef CONFIG_BOOT_FROM_NOR
  OBJS	= bootstrap_board.o  
  else
  OBJS    = nand_spl_board.o 
  endif
endif
endif

OBJS +=LzmaDecode.o LzmaWrapper.o

ifdef CONFIG_BOOT_FROM_NOR
ifdef CONFIG_TUNE_DDR
OBJS += tune_ddr.o
endif
endif

all: .depend $(LIB)

bootstrap: .depend $(LIB)

$(LIB):	$(OBJS)
	$(AR) crv $@ $(OBJS)

#########################################################################

.depend:	Makefile $(OBJS:.o=.c)
		$(CC) -M $(CFLAGS) $(OBJS:.o=.c) > $@

sinclude .depend

#########################################################################
