sinclude .config


.S.s:
	$(CPP) $(CFLAGS) $< -o $*.s
.S.o:
	$(CC) $(CFLAGS) -c $< -o $*.o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $*.o

CC =       $(CROSS_COMPILE)gcc
LD =       $(CROSS_COMPILE)ld
OBJCOPY =  $(CROSS_COMPILE)objcopy
OBJDUMP =  $(CROSS_COMPILE)objdump


INCLUDE = include/
CFLAGS = -g -O -G 0 -mabicalls -fPIC -Wall -march=34kc -DRAMSIZE=${RAMSIZE} -EB -D__KERNEL__ -D_MIPS_SZLONG=32  -I$(INCLUDE)
CFLAGS +=-fno-zero-initialized-in-bss -DOPENSSL_NO_BIO -DOPENSSL_NO_FP_API -DOPENSSL_NO_ENGINE -DOPENSSL_NO_OBJECT -DOPENSSL_NO_DH 


