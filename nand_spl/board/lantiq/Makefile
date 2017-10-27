
CONFIG_NAND_SPL	= y

include $(TOPDIR)/config.mk
include $(TOPDIR)/nand_spl/board/lantiq/config.mk

LDSCRIPT= $(TOPDIR)/nand_spl/board/lantiq/u-boot.lds
LDFLAGS	= -Bstatic -T $(nandobj)u-boot.lds -Ttext $(CONFIG_NAND_SPL_TEXT_BASE) $(PLATFORM_LDFLAGS)
AFLAGS	+=-mabicalls -fpic -DCONFIG_NAND_SPL -I$(TOPDIR)/board/$(BOARD)/
CFLAGS	+=-mabicalls -fpic -DCONFIG_NAND_SPL -I$(TOPDIR)/board/$(BOARD)/

SOBJS	= start.o lowlevel_init.o 
COBJS	= nand_boot.o lq_nand.o board.o asc.o clock.o string.o time.o

ifdef CONFIG_LANTIQ_UBOOT_grx500
COBJS += crc32.o
ifdef CONFIG_NAND_ECC_BCH
 COBJS += nand_bch.o bch.o
endif
ifdef CONFIG_NAND_ECC_SOFT 
 COBJS += nand_ecc.o
endif
ifdef CONFIG_SPINAND_LANTIQ
 COBJS +=$(TOPDIR)/drivers/spi/lq_spi.o
endif 
 COBJS +=$(TOPDIR)/arch/mips/cpu/grx500/libmips.a

else
 COBJS += nand_ecc.o
endif

ifdef CONFIG_NAND_BENAND
BCH_VAL = 0
else
BCH_VAL = 8
endif

spinandflag-${CONFIG_GIGA_DEVICE_SPINAND}=--gdsnand 

ifdef CONFIG_TUNE_DDR
COBJS  +=tune_ddr.o
endif

ifdef CONFIG_NAND_SPL_BBT
COBJS  +=nand_bbt.o
endif

ifndef CONFIG_DRIVER_GRX500
ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
COBJS  += cache.o
endif
endif

ifeq (${CONFIG_ENABLE_DDR_DCDC},y) 
COBJS	+= ddr_dcdc.o
endif

ifeq ($(CONFIG_LTQ_SECURE_BOOT)$(CONFIG_DRIVER_VR9)$(DRIVER_AR10),yy)
COBJS  += deu_aes.o 
ifndef  CONFIG_NAND_ECC_HW_REED_SOLOMON
COBJS  += cache.o
endif
endif



#### grx500 secure boot configuration

SIGN_IMAGE_OPT :=

ifeq ($(CONFIG_LTQ_SECURE_BOOT)$(CONFIG_LANTIQ_UBOOT_grx500),yy)
    ifdef CONFIG_CERTIFICATION_SUPPORT
        SIGN_IMAGE_OPT += -cert $(CONFIG_CERTIFICATION)
    endif

    ifeq ($(CONFIG_MANUBOOT)$(CONFIG_MANUBOOT_CREDENTIAL_SUPPORT),yy)
        SIGN_IMAGE_OPT += -cred $(CONFIG_MANUBOOT_CREDENTIAL)
    endif

    ifeq ($(CONFIG_MANUBOOT)$(CONFIG_MANUBOOT_OTP_SUPPORT)$(CONFIG_GRX500_BOOT_4KEC_ONLY),yy)
        COBJS   += otp.o
        CFLAGS += -DOTP_IN_FSB
    endif
endif

#### end grx500 secure boot configuration

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

ifeq ($(CONFIG_NAND_ECC_HW_REED_SOLOMON)$(CONFIG_LANTIQ_UBOOT_ar10),yy) #hack to break specific Reed Solomon option , we don't need to differentiate in grx500
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
else #not secure boot
ifdef CONFIG_LANTIQ_UBOOT_grx500
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	$(TOPDIR)/scripts_platform/mk_ltq_header.pl --ddr $(TOPDIR)/board/$(BOARD)/ddr.conf \
          --bch 8 --col 2 --row 3 --blocksize $(CONFIG_NAND_BLOCK_SIZE) --pagesize $(CONFIG_NAND_PAGE_SIZE)\
          --offset $(CONFIG_NAND_PAGE_SIZE) --out header.ltq
	$(TOPDIR)/scripts_platform/pad2align.sh -n 1760 header.ltq
	$(HOSTCC) -o bch_enc $(TOPDIR)/board/$(BOARD)/bch_enc.c
	./bch_enc header.ltq header.bch $(CONFIG_GRX500_ROM_HEADER_BCH_CAP)
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_PAGE_SIZE) header.bch
	$(TOPDIR)/scripts_platform/mk_sf_image.pl -i $(nandobj)u-boot-spl.bin -o output.bin -j $(CONFIG_NAND_SPL_TEXT_BASE) -m 0
	$(TOPDIR)/scripts_platform/pad2align.sh -n 440 output.bin
	./bch_enc output.bin output.bch 8
	cp header.bch $(nandobj)u-boot-spl-16k.bin
	cat output.bch >>$(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
else
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	$(TOPDIR)/scripts_platform/mk_mlc_image.pl $(nandobj)u-boot-spl.bin $(nandobj)u-boot-spl-32k.bin
	$(TOPDIR)/scripts_platform/swap_bin.pl $(nandobj)u-boot-spl-32k.bin $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/duplicate.sh $(CONFIG_MLC_NAND_HEADER_NUMBER) $(nandobj)u-boot-spl-16k.bin 
endif
endif
else  #not using REED_SOLOMON
ifdef CONFIG_LTQ_SECURE_BOOT
ifdef CONFIG_LANTIQ_UBOOT_vr9
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin stools ds_crypt.bin
	touch dummy
	$(TOPDIR)/scripts_platform/pad2align.sh -n 0x6000 $(nandobj)u-boot-spl.bin
	cat $(TOPDIR)/stage2_key.bin >>$(nandobj)u-boot-spl.bin
	./stools -i $(nandobj)u-boot-spl.bin -o nand_spl.enc -d ./ds_crypt.bin -a $(CONFIG_NAND_SPL_TEXT_BASE) -k $(CONFIG_AES_KEY) -s
	$(TOPDIR)/scripts_platform/mk_sf.pl dummy nand_spl.enc $(CONFIG_NAND_SPL_TEXT_BASE) $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
endif
ifdef CONFIG_LANTIQ_UBOOT_ar10
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin stools
	touch dummy
	$(TOPDIR)/scripts_platform/pad2align.sh -n 0x6000 $(nandobj)u-boot-spl.bin
	cat $(TOPDIR)/stage2_key.bin >>$(nandobj)u-boot-spl.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n 32 $(nandobj)u-boot-spl.bin
	./stools -i $(nandobj)u-boot-spl.bin -o u-boot-spl.enc -e 0xbe1a0030 -d 0xbe1a0000 -j 0xbe1a0000 \
	-k $(CONFIG_AES_KEY)
	$(TOPDIR)/scripts_platform/mk_sf.pl dummy u-boot-spl.enc 0xbe1a0000 $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
endif
ifdef CONFIG_LANTIQ_UBOOT_grx500
ifdef CONFIG_MANUBOOT
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	$(CONFIG_SIGNTOOL) sign -type BLw  -infile $(nandobj)u-boot-spl.bin \
			   -prikey $(CONFIG_PRIVATE_KEY) \
			   -wrapkey $(CONFIG_PROD_UNIQUE_KEY) \
                           -attribute rollback=2 \
                           -attribute 0x80000000=$(CONFIG_NAND_SPL_TEXT_BASE)\
                           -attribute 0x80000001=0x00000001 \
                           -attribute 0x80000002=$(CONFIG_NAND_SPL_TEXT_BASE) \
                           -encattr \
                           -manuboot \
                           $(SIGN_IMAGE_OPT) \
                           -outfile blwSignedImg.bin
    ifdef CONFIG_GRX500_A11
	sed -i -e 's/0xb6200008 *\(.\{8\}\).\(.*\)/0xb6200008 \1E\2/' \
               -e 's/0xB6200008 *\(.\{8\}\).\(.*\)/0xB6200008 \1E\2/' $(TOPDIR)/board/$(BOARD)/ddr.conf
    endif
	$(TOPDIR)/scripts_platform/mk_ltq_header.pl --ddr $(TOPDIR)/board/$(BOARD)/ddr.conf \
                                                    --bch $(BCH_VAL) --col 2 --row 3 --blocksize $(CONFIG_NAND_BLOCK_SIZE) \
                                                    --pagesize $(CONFIG_NAND_PAGE_SIZE) --offset $(CONFIG_NAND_PAGE_SIZE),0x4000,0x6000,0x8000 --out header.ltq
	$(TOPDIR)/scripts_platform/pad2align.sh -n 1760 header.ltq
	$(HOSTCC) -o bch_enc $(TOPDIR)/board/$(BOARD)/bch_enc.c
	./bch_enc header.ltq header.bch $(CONFIG_GRX500_ROM_HEADER_BCH_CAP)
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_PAGE_SIZE) header.bch
	$(TOPDIR)/scripts_platform/mk_sf_image.pl -i blwSignedImg.bin -o output.bin -j 0xA0900000 -m 1
	$(TOPDIR)/scripts_platform/pad2align.sh -n 440 output.bin
    ifdef CONFIG_NAND_BENAND
	cp header.bch $(nandobj)u-boot-spl-16k.bin
	cat output.bin >> $(nandobj)u-boot-spl-16k.bin
    else
	./bch_enc output.bin output.bch 8
	cp header.bch $(nandobj)u-boot-spl-16k.bin
	cat output.bch >>$(nandobj)u-boot-spl-16k.bin
    endif
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
else # not manuboot
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	$(CONFIG_SIGNTOOL) sign -type BLw  -infile $(nandobj)u-boot-spl.bin \
			   -prikey $(CONFIG_PRIVATE_KEY) \
			   -wrapkey $(CONFIG_PROD_UNIQUE_KEY) \
                           -attribute rollback=2 \
                           -attribute 0x80000000=$(CONFIG_NAND_SPL_TEXT_BASE)\
                           -attribute 0x80000001=0x00000001 \
                           -attribute 0x80000002=$(CONFIG_NAND_SPL_TEXT_BASE) \
                           -encattr \
                           $(SIGN_IMAGE_OPT) \
                           -kdk \
                           -pubkeytype otp \
                           -algo aes256 \
                           -outfile blwSignedImg.bin
    ifdef CONFIG_GRX500_A11
	sed -i -e 's/0xb6200008 *\(.\{8\}\).\(.*\)/0xb6200008 \1E\2/' \
               -e 's/0xB6200008 *\(.\{8\}\).\(.*\)/0xB6200008 \1E\2/' $(TOPDIR)/board/$(BOARD)/ddr.conf
    endif
	$(TOPDIR)/scripts_platform/mk_ltq_header.pl --ddr $(TOPDIR)/board/$(BOARD)/ddr.conf \
                                                    --bch $(BCH_VAL) --col 2 --row 3 --blocksize $(CONFIG_NAND_BLOCK_SIZE) \
                                                    --pagesize $(CONFIG_NAND_PAGE_SIZE) --offset $(CONFIG_NAND_PAGE_SIZE) --out header.ltq
	$(TOPDIR)/scripts_platform/pad2align.sh -n 1760 header.ltq
	$(HOSTCC) -o bch_enc $(TOPDIR)/board/$(BOARD)/bch_enc.c
	./bch_enc header.ltq header.bch $(CONFIG_GRX500_ROM_HEADER_BCH_CAP)
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_PAGE_SIZE) header.bch
	$(TOPDIR)/scripts_platform/mk_sf_image.pl -i blwSignedImg.bin -o output.bin -j 0xa0100000 -m 2
	$(TOPDIR)/scripts_platform/pad2align.sh -n 440 output.bin
    ifdef CONFIG_NAND_BENAND
	cp header.bch $(nandobj)u-boot-spl-16k.bin
	cat output.bin >> $(nandobj)u-boot-spl-16k.bin
    else
	./bch_enc output.bin output.bch 8
	cp header.bch $(nandobj)u-boot-spl-16k.bin
	cat output.bch >>$(nandobj)u-boot-spl-16k.bin
    endif
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
endif # end CONFIG_MANUBOOT
endif 
else  #not secure boot
ifdef CONFIG_LANTIQ_UBOOT_grx500
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin
	$(TOPDIR)/scripts_platform/mk_ltq_header.pl $(spinandflag-y) --ddr $(TOPDIR)/board/$(BOARD)/ddr.conf \
          --bch $(BCH_VAL) --col 2 --row 3 --blocksize $(CONFIG_NAND_BLOCK_SIZE) --pagesize $(CONFIG_NAND_PAGE_SIZE) --offset $(CONFIG_NAND_PAGE_SIZE) --out header.ltq
	$(TOPDIR)/scripts_platform/pad2align.sh -n 1760 header.ltq
	$(HOSTCC) -o bch_enc $(TOPDIR)/board/$(BOARD)/bch_enc.c
	./bch_enc header.ltq header.bch $(CONFIG_GRX500_ROM_HEADER_BCH_CAP)
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_PAGE_SIZE) header.bch
	$(TOPDIR)/scripts_platform/mk_sf_image.pl -i $(nandobj)u-boot-spl.bin -o output.bin -j $(CONFIG_NAND_SPL_TEXT_BASE) -m 0
	$(TOPDIR)/scripts_platform/pad2align.sh -n 440 output.bin
ifdef CONFIG_NAND_BENAND
	cp header.bch $(nandobj)u-boot-spl-16k.bin
	cat output.bin >> $(nandobj)u-boot-spl-16k.bin	
else
	./bch_enc output.bin output.bch 8
	cp header.bch $(nandobj)u-boot-spl-16k.bin
	cat output.bch >>$(nandobj)u-boot-spl-16k.bin
endif
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
else
$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl.bin 
	touch dummy
	$(TOPDIR)/scripts_platform/mk_sf.pl dummy $(nandobj)u-boot-spl.bin $(CONFIG_NAND_PRELOAD_TEXT_BASE) $(nandobj)u-boot-spl-16k.bin
	$(TOPDIR)/scripts_platform/pad2align.sh -n $(CONFIG_NAND_SPL_BLOCK_SIZE) $(nandobj)u-boot-spl-16k.bin
endif
endif
endif
endif

$(nandobj)u-boot-spl.bin:	$(nandobj)u-boot-spl
	$(OBJCOPY) ${OBJCFLAGS} -O binary $< $@

$(nandobj)u-boot-spl:$(OBJS) $(nandobj)u-boot.lds
	cd $(LNDIR) && $(LD) $(LDFLAGS) $(__OBJS) \
		 $(PLATFORM_LIBS) \
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

cache.c:
	@rm -f $@
	@ln -s $(TOPDIR)/arch/mips/cpu/$(BOARD)/cache.c $@

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

ifeq ($(CONFIG_NAND_ECC_HW_REED_SOLOMON),y)
$(obj)nand_boot.c:
	@rm -f $@
	@ln -s $(TOPDIR)/nand_spl/nand_boot_lq_mlc.c $@
else ifeq ($(CONFIG_SPINAND_LANTIQ),y)		
$(obj)nand_boot.c:
	@rm -f $@
	@ln -s $(TOPDIR)/nand_spl/spinand_boot.c $@
else
$(obj)nand_boot.c:
	@rm -f $@
	@ln -s $(TOPDIR)/nand_spl/nand_boot.c $@
endif

# from drivers/mtd/nand directory
$(obj)nand_ecc.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/nand/nand_ecc.c $@

$(obj)nand_bch.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/nand/nand_bch.c $@

$(obj)bch.c:
	@rm -f $@
	@ln -s $(TOPDIR)/lib/bch.c $@

ifdef CONFIG_SPINAND_LANTIQ
$(obj)lq_nand.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/nand/lq_spinand.c $@
else
$(obj)lq_nand.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/nand/lq_nand.c $@
endif

#from lib directory
string.c:
	@rm -f $@
	@ln -s $(TOPDIR)/lib/string.c $@

time.c:
	@rm -f $@
	@ln -s $(TOPDIR)/arch/mips/lib/time.c $@
		
crc32.c:
	@rm -f $@
	@ln -s $(TOPDIR)/lib/crc32.c

ifeq ($(CONFIG_MANUBOOT)$(CONFIG_MANUBOOT_OTP_SUPPORT)$(CONFIG_GRX500_BOOT_4KEC_ONLY),yy)
OTP_H := otp_bin.h
# OTP_HEX := $(shell hexdump -ve '1/1 "%02x"' $(CONFIG_MANUBOOT_OTP)  )

# old method depend on hexdump
# .PHONY : $(OTP_H)
# $(OTP_H):
#	@echo "Generate OTP content"
# 	-@rm -f  $(TOPDIR)/include/$(OTP_H)
# 	@$(TOPDIR)/scripts_platform/hex2array.pl oem_keys $(OTP_HEX) > $(TOPDIR)/include/$(OTP_H)

.PHONY : $(OTP_H)
$(OTP_H):
	@echo "Generate OTP content"
	-@rm -f  $(TOPDIR)/include/$(OTP_H)
	@$(TOPDIR)/scripts_platform/bin2array.pl $(CONFIG_MANUBOOT_OTP) $(TOPDIR)/include/$(OTP_H) oem_keys

# phony target to force it to rebuild otp_bin.h everytime
otp.c: $(OTP_H)
	@rm -f $@
	@ln -s $(TOPDIR)/common/otp.c $@

endif

#########################################################################

$(obj)%.o:	$(obj)%.S
	$(CC) $(AFLAGS) -c -o $@ $<

$(obj)%.o:	$(obj)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
