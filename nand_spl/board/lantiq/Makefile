#
# (C) Copyright 2006-2007
# Stefan Roese, DENX Software Engineering, sr@denx.de.
#
# (C) Copyright 2008
# Guennadi Liakhovetki, DENX Software Engineering, <lg@denx.de>
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

CONFIG_NAND_SPL	= y

include $(TOPDIR)/config.mk
include $(TOPDIR)/nand_spl/board/lantiq/config.mk

LDSCRIPT= $(TOPDIR)/nand_spl/board/lantiq/u-boot.lds
LDFLAGS	= -Bstatic -T $(nandobj)u-boot.lds -Ttext $(CONFIG_NAND_SPL_TEXT_BASE) $(PLATFORM_LDFLAGS)
AFLAGS	+=-mabicalls -fpic -DCONFIG_NAND_SPL -I$(TOPDIR)/board/$(BOARD)/
CFLAGS	+=-mabicalls -fpic -DCONFIG_NAND_SPL -I$(TOPDIR)/board/$(BOARD)/

SOBJS	= start.o lowlevel_init.o
COBJS	= nand_boot.o nand_ecc.o lq_nand.o board.o asc.o clock.o tune_ddr.o string.o time.o

ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
COBJS  += cache.o
endif

ifeq (${CONFIG_ENABLE_DDR_DCDC},y)
COBJS	+= ddr_dcdc.o
endif

SRCS	:= $(addprefix $(obj),$(SOBJS:.o=.S) $(COBJS:.o=.c))
OBJS	:= $(addprefix $(obj),$(SOBJS) $(COBJS))
__OBJS	:= $(SOBJS) $(COBJS)
LNDIR	:= $(OBJTREE)/nand_spl/board/lantiq

nandobj	:= $(OBJTREE)/nand_spl/board/lantiq

ALL	= $(nandobj)u-boot-spl $(nandobj)u-boot-spl.bin $(nandobj)u-boot-spl-16k.bin

all:	$(obj).depend $(ALL)
	@rm -f u-boot-spl.bin u-boot-spl-16k.bin
	@ln -s $(nandobj)u-boot-spl.bin $(TOPDIR)/nand_spl/u-boot-spl.bin
	@ln -s $(nandobj)u-boot-spl-16k.bin $(TOPDIR)/nand_spl/u-boot-spl-16k.bin

ifdef CONFIG_NAND_PRELOAD
ALL +=nandpreload.bin

LDFLAGS_NANDPRELOAD = -Bstatic -T nandpreload.lds -Ttext $(CONFIG_NAND_PRELOAD_TEXT_BASE)
OBJS_NANDPRELOAD =  start_nandpreload.o
OBJS_NANDPRELOAD += nand_preload.o

nandpreload.bin: nandpreload
	$(OBJCOPY) ${OBJCFLAGS} -O binary $< $@

nandpreload:  $(OBJS_NANDPRELOAD)
	$(LD) $(LDFLAGS_NANDPRELOAD) $(OBJS_NANDPRELOAD) -Map nandpreload.map -o nandpreload
	$(OBJDUMP) -S -d nandpreload > nandpreload.dis

$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin nandpreload.bin
	touch dummy
	$(TOPDIR)/scripts_platform/mk_sf.pl dummy nandpreload.bin $(CONFIG_NAND_PRELOAD_TEXT_BASE) $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n 512 $(nandobj)u-boot-spl-16k.bin
	cat $(nandobj)u-boot-spl.bin >> $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
else

ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
ifdef CONFIG_LTQ_SECURE_BOOT
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin stools
	$(TOPDIR)/scripts_platform/pad2align.sh -n 0x6000 $(nandobj)u-boot-spl.bin
	cat $(TOPDIR)/stage2_key.bin >>$(nandobj)u-boot-spl.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n 32 $(nandobj)u-boot-spl.bin
	./stools -i $(nandobj)u-boot-spl.bin -o u-boot-spl.enc -e 0xbe1a0030 -d 0xbe1a0000 -j 0xbe1a0000 \
	-k $(CONFIG_AES_KEY)
	$(TOPDIR)/scripts_platform/mk_mlc_image.pl u-boot-spl.enc $(nandobj)u-boot-spl-32k.bin
	$(TOPDIR)/scripts_platform/swap_bin.pl $(nandobj)u-boot-spl-32k.bin $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/duplicate.sh $(CONFIG_MLC_NAND_HEADER_NUMBER) $(nandobj)u-boot-spl-16k.bin
else
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	$(TOPDIR)/scripts_platform/mk_mlc_image.pl $(nandobj)u-boot-spl.bin $(nandobj)u-boot-spl-32k.bin
	$(TOPDIR)/scripts_platform/swap_bin.pl $(nandobj)u-boot-spl-32k.bin $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/duplicate.sh $(CONFIG_MLC_NAND_HEADER_NUMBER) $(nandobj)u-boot-spl-16k.bin
endif
else
ifdef CONFIG_LTQ_SECURE_BOOT
ifdef CONFIG_LANTIQ_UBOOT_vr9
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin stools ds_crypt.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n 16384 $(nandobj)u-boot-spl.bin
	./stools -i $(nandobj)u-boot-spl.bin -o nand_spl.enc -d ./ds_crypt.bin -a $(CONFIG_NAND_SPL_TEXT_BASE)
	$(TOPDIR)/scripts_platform/mk_sf.pl $(TOPDIR)/board/$(BOARD)/xrx200_ddr2_197_CAS4_config.conf nand_spl.enc 0xa0600000 $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n 20480 $(nandobj)u-boot-spl-16k.bin
else
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	touch dummy
	$(TOPDIR)/scripts_platform/pad2align.sh -n 32 $(nandobj)u-boot-spl.bin
	./stools -i $(nandobj)u-boot-spl.bin -o u-boot-spl.enc -e 0xbe1a0030 -d 0xbe1a0000 -j 0xbe1a0000 \
	-k $(CONFIG_AES_KEY)
	$(TOPDIR)/scripts_platform/mk_sf.pl dummy u-boot-spl.enc 0xbe1a0000 $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n 16384 $(nandobj)u-boot-spl-16k.bin
endif
else
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	touch dummy
	$(TOPDIR)/scripts_platform/mk_sf.pl dummy $(nandobj)u-boot-spl.bin $(CONFIG_NAND_PRELOAD_TEXT_BASE) $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
endif
endif
endif

$(nandobj)u-boot-spl.bin:	$(nandobj)u-boot-spl
	$(OBJCOPY) ${OBJCFLAGS} -O binary $< $@

$(nandobj)u-boot-spl:	$(OBJS) $(nandobj)u-boot.lds
	cd $(LNDIR) && $(LD) $(LDFLAGS) $(__OBJS) \
		-Map $(nandobj)u-boot-spl.map \
		-o $(nandobj)u-boot-spl
	$(OBJDUMP) -S -d $(nandobj)u-boot-spl > $(nandobj)u-boot-spl.dis

$(nandobj)u-boot.lds: $(LDSCRIPT)
	$(CPP) $(CPPFLAGS) $(LDPPFLAGS) -ansi -D__ASSEMBLY__ -P - <$^ >$@

# create symbolic links for common files

# from cpu directory
$(obj)start.S:
	@rm -f $@
	@ln -s $(TOPDIR)/arch/mips/cpu/$(BOARD)/start_nand_spl.S $@

clock.c:
	@rm -f $@
	@ln -s $(TOPDIR)/arch/mips/cpu/$(BOARD)/clock.c $@

ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
cache.c:
	@rm -f $@
	@ln -s $(TOPDIR)/arch/mips/cpu/$(BOARD)/cache.c $@
endif


# from driver/serial directory
asc.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/serial/lq_asc.c $@


# from board directory
$(obj)lowlevel_init.S:
	@rm -f $@
	@ln -s $(TOPDIR)/board/$(BOARD)/lowlevel_init.S $@


board.c:
	@rm -f $@
	@ln -s $(TOPDIR)/board/$(BOARD)/nand_spl_board.c $@

$(obj)ddr_dcdc.c:
	@rm -f $@
	@ln -s $(TOPDIR)/board/$(BOARD)/ddr_dcdc.c $@

ds_crypt.bin: ds_crypt
	$(OBJCOPY) --gap-fill=0xff -O binary $< $@

ds_crypt: rsa_crypt.o
	$(LD) -G 0 -static -T $(TOPDIR)/board/$(BOARD)/rsalinker.lds --start-group rsa_crypt.o --end-group -o ds_crypt

rsa_crypt.o: $(TOPDIR)/board/$(BOARD)/rsa_crypt.c
	$(CC) -g -ggdb -G0 -fno-common -fno-strict-aliasing -fno-builtin -pipe -eb -Wall -c -o $@ $<

stools: $(TOPDIR)/board/$(BOARD)/stools.c
	$(HOSTCC) -o $@ $<


#from lib_bootstrap directory
tune_ddr.c:
	@rm -f $@
	@ln -s $(TOPDIR)/lib_bootstrap/tune_ddr.c $@


# from nand_spl directory

ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
$(obj)nand_boot.c:
	@rm -f $@
	@ln -s $(TOPDIR)/nand_spl/nand_boot_lq_mlc.c $@

else
$(obj)nand_boot.c:
	@rm -f $@
	@ln -s $(TOPDIR)/nand_spl/nand_boot.c $@

endif

# from drivers/mtd/nand directory
$(obj)nand_ecc.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/nand/nand_ecc.c $@

$(obj)lq_nand.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/nand/lq_nand.c $@


#from lib directory
string.c:
	@rm -f $@
	@ln -s $(TOPDIR)/lib/string.c $@

time.c:
	@rm -f $@
	@ln -s $(TOPDIR)/arch/mips/lib/time.c $@


#########################################################################

$(obj)%.o:	$(obj)%.S
	$(CC) $(AFLAGS) -c -o $@ $<

$(obj)%.o:	$(obj)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
