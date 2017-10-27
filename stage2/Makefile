
include config.mk

######## CONFIGURATION #########

LOADADDR = $(CONFIG_STAGE2_LOADADDR)
RAMSIZE = 0x2000000

# Drop some uninteresting sections in the kernel.
# This is only relevant for ELF kernels but doesn't hurt a.out
drop-sections   = .reginfo .mdebug
strip-flags     = $(addprefix --remove-section=,$(drop-sections))

all : elf srec bin

srec : stage2.srec
elf : stage2.elf
bin : stage2.bin

obj-y = start.o string.o
obj-y +=deu_aes.o deu_sha1.o
obj-y +=malloc.o
obj-y +=bn_lib.o crypto_mem.o o_init.o mem_clr.o crypto_err.o bn_add.o \
                       bn_mul.o bn_mont.o bn_div.o bn_sqr.o bn_shift.o bn_mod.o bn_gcd.o\
                       bn_exp2.o bn_prime.o ex_data.o cryptlib.o lhash.o stack.o \
                       bn_ctx.o bn_exp.o bn_recp.o bn_asm.o bn_word.o 
obj-y += dsa_lib.o  dsa_vrf.o dsa_sign.o dsa_ossl.o

stage2.elf : $(obj-y) main.o 
	$(LD) $(LFLAGS) -o stage2.elf -N -Tstage2.lds -Ttext $(LOADADDR) $^

stage2.srec : stage2.elf
	$(OBJCOPY) -S -O srec $(strip-flags) stage2.elf stage2.srec

stage2.bin : stage2.elf
	$(OBJCOPY) -S -O binary $(strip-flags) stage2.elf stage2.bin

clean:
	rm -f *.o *.elf *.srec *.bin



 


