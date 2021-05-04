-include include/config/auto.conf

ifdef CONFIG_NAND_BOOT
archdir = $(srctree)/arch/$(ARCH)/mach-lantiq/$(CONFIG_SYS_SOC)
curdir = $(srctree)/lib/bootstrap
OBJS = $(srctree)/lib/string.o $(curdir)/LzmaDecode.o
OBJS += $(curdir)/LzmaWrapper.o
OBJS += $(srctree)/lib/crc32.o $(archdir)/start_uncomp.o
OBJS += $(srctree)/lib/ctype.o $(curdir)/nand_spl_board.o
DEPENDS = depends
LIB = libbootstrap.a

INCLUDEDIR = -Iinclude -I$(srctree)/arch/mips/include \
			-I$(srctree)/arch/mips/include/asm/mach-generic \
			-I$(srctree)/include

CFLAGS = $(UBOOTINCLUDE)

CFLAGS +=  -g  -Os -fomit-frame-pointer -D__KERNEL__ -Wall -Wstrict-prototypes -Wno-format-security \
		-fno-builtin -ffreestanding -Os -fno-stack-protector \
		-fno-delete-null-pointer-checks -g -fstack-usage -Wno-format-nonliteral \
		-EB -mabi=32 -D__MIPS__ -G 0 -mabicalls -fpic \
		-msoft-float -ffunction-sections -fdata-sections

all: $(DEPENDS) $(LIB)

$(DEPENDS): $(curdir)/LzmaDecode.o $(curdir)/LzmaWrapper.o $(curdir)/nand_spl_board.o \
		$(archdir)/start_uncomp.o $(srctree)/lib/string.o \
		$(srctree)/lib/ctype.o $(srctree)/lib/crc32.o

$(srctree)/lib/string.o:
	$(CC) $(PLATFORM_CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) $(@:.o=.c) -c -o $@

$(srctree)/lib/ctype.o:
	$(CC) $(PLATFORM_CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) $(@:.o=.c) -c -o $@

$(srctree)/lib/crc32.o:
	$(CC) $(PLATFORM_CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) $(@:.o=.c) -c -o $@

$(archdir)/start_uncomp.o:
	$(CC) $(PLATFORM_CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) $(@:.o=.c) -c -o $@

$(curdir)/LzmaDecode.o:
	$(CC) $(PLATFORM_CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) $(@:.o=.c) -c -o $@

$(curdir)/LzmaWrapper.o:
	$(CC) $(PLATFORM_CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) $(@:.o=.c) -c -o $@

$(curdir)/nand_spl_board.o:
	$(CC) $(PLATFORM_CPPFLAGS) $(CFLAGS) $(INCLUDEDIR) $(@:.o=.c) -c -o $@

$(archdir)/start_uncomp.o:
	$(CC) -D__ASSEMBLY__ $(CFLAGS) $(INCLUDEDIR) $(@:.o=.S) -c -o $@  

$(LIB): $(DEPENDS)
	$(AR) crv $(curdir)/$@ $(OBJS)

endif

obj-$(CONFIG_SPI_BOOT) += LzmaDecode.o LzmaWrapper.o
obj-$(CONFIG_QSPI_BOOT) += LzmaDecode.o LzmaWrapper.o

ifdef CONFIG_SPL_BUILD
obj-$(CONFIG_NOR_BOOT) += bootstrap_board.o LzmaDecode.o LzmaWrapper.o
endif

