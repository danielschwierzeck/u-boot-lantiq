/*
 * Copyright (C) 2007-2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LANTIQ_CONFIG_H__
#define __LANTIQ_CONFIG_H__

/* Memory usage */
#define CONFIG_SYS_MAXARGS		24
#define CONFIG_SYS_BOOTPARAMS_LEN	128*1024

/* Command line */
#define CONFIG_SYS_PROMPT		"U-Boot # "
#define CONFIG_SYS_CBSIZE		512
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT)+16)

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "

/*
 * Enable advanced console features on demand to reduce
 * flash and RAM footprint
 */
#if defined(CONFIG_LTQ_ADVANCED_CONSOLE)
#define CONFIG_SYS_LONGHELP
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING
#endif

/* SPI flash SPL */
#if defined(CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH) && defined(CONFIG_SYS_BOOT_SFSPL)
#define CONFIG_SPL
#define CONFIG_SPL_SPI_SUPPORT
#define CONFIG_SPL_SPI_FLASH_SUPPORT
#define CONFIG_SPI_SPL_SIMPLE
#endif

/*
 * NAND flash SPL
 * BOOT CFG 06 only (address cycle based probing, 2KB or 512B page size)
 */
#if defined(CONFIG_LTQ_SUPPORT_SPL_NAND_FLASH) && defined(CONFIG_SYS_BOOT_NANDSPL)
#define CONFIG_SPL
#define CONFIG_TPL
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_NAND_DRIVERS
#define CONFIG_SPL_NAND_ECC
#define CONFIG_SPL_NAND_SOFTECC
#endif

/*
 * NAND flash SPL with hardware support
 */
#if defined(CONFIG_LTQ_SUPPORT_SPL_NAND_FLASH) && defined(CONFIG_SYS_BOOT_NANDHWSPL)
#define CONFIG_SPL
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_NAND_DRIVERS
#define CONFIG_SPL_DMA_SUPPORT
#endif

#if defined(CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH) && defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_SPL
#define CONFIG_TPL
#endif

/* Common SPL */
#if defined(CONFIG_SPL)
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_GPIO_SUPPORT
#define CONFIG_SPL_START_S_PATH		\
		"arch/mips/cpu/mips32/lantiq-common"
#define CONFIG_SPL_LDSCRIPT		\
		"arch/mips/cpu/mips32/lantiq-common/u-boot-spl.lds"
#endif

#if defined(CONFIG_LTQ_SPL_CONSOLE)
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#endif

#if defined(CONFIG_LTQ_SPL_COMP_LZO)
#define CONFIG_LZO
#define CONFIG_SPL_LZO_SUPPORT
#endif

/* Basic commands */
#define CONFIG_CMD_BDI
#define CONFIG_CMD_EDITENV
#define CONFIG_CMD_IMI
#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_RUN
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_LOADS
#define CONFIG_CMD_LOADB

/* Other U-Boot settings */
#define CONFIG_UBOOT_VERSION
#define CONFIG_TIMESTAMP

/* Generic board */
#define CONFIG_SYS_GENERIC_BOARD
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_DISPLAY_BOARDINFO

/* Boot interface */
#define CONFIG_FIT
#define CONFIG_OF_LIBFDT
#define CONFIG_MIPS_BOOT_CMDLINE_LEGACY
#define CONFIG_MIPS_BOOT_FDT

/* Default environment */
#if defined(CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH)
#define CONFIG_ENV_WRITE_UBOOT_NOR					\
	"write-uboot-nor="						\
	"protect off " __stringify(CONFIG_SYS_FLASH_BASE) " +$filesize && " \
	"erase " __stringify(CONFIG_SYS_FLASH_BASE) " +$filesize && "	\
	"cp.b $fileaddr " __stringify(CONFIG_SYS_FLASH_BASE) " $filesize\0"

#define CONFIG_ENV_LOAD_UBOOT_NOR					\
	"load-uboot-nor=tftpboot u-boot.ltq.lzo.norspl\0"

#define CONFIG_ENV_UPDATE_UBOOT_NOR					\
	"update-uboot-nor=run load-uboot-nor write-uboot-nor\0"
#else
#define CONFIG_ENV_WRITE_UBOOT_NOR
#define CONFIG_ENV_LOAD_UBOOT_NOR
#define CONFIG_ENV_UPDATE_UBOOT_NOR
#endif

#if defined(CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH)
#define CONFIG_ENV_SF_PROBE					\
	"sf-probe=sf probe " __stringify(CONFIG_ENV_SPI_CS) " "	\
	__stringify(CONFIG_ENV_SPI_MAX_HZ) " "			\
	__stringify(CONFIG_ENV_SPI_MODE) " \0"

#define CONFIG_ENV_WRITE_UBOOT_SF				\
	"write-uboot-sf="					\
	"run sf-probe && sf erase 0 +$filesize && "		\
	"sf write $fileaddr 0 $filesize\0"

#define CONFIG_ENV_LOAD_UBOOT_SF					\
	"load-uboot-sf=tftpboot u-boot.ltq.lzo.sfspl\0"

#define CONFIG_ENV_UPDATE_UBOOT_SF					\
	"update-uboot-sf=run load-uboot-sf write-uboot-sf\0"
#else
#define CONFIG_ENV_SF_PROBE
#define CONFIG_ENV_WRITE_UBOOT_SF
#define CONFIG_ENV_LOAD_UBOOT_SF
#define CONFIG_ENV_UPDATE_UBOOT_SF
#endif

#if defined(CONFIG_LTQ_SUPPORT_SPL_NAND_FLASH)
#define CONFIG_ENV_WRITE_UBOOT_NAND				\
	"write-uboot-nand="					\
	"nand erase 0 $filesize && "				\
	"nand write $fileaddr 0 $filesize\0"

#define CONFIG_ENV_LOAD_UBOOT_NAND					\
	"load-uboot-nand=tftpboot u-boot.ltq.lzo.nandspl\0"

#define CONFIG_ENV_LOAD_UBOOT_HSNAND					\
	"load-uboot-hsnand=tftpboot u-boot.ltq.lzo.nandhwspl\0"

#define CONFIG_ENV_UPDATE_UBOOT_NAND					\
	"update-uboot-nand=run load-uboot-nand write-uboot-nand\0"

#define CONFIG_ENV_UPDATE_UBOOT_HSNAND					\
	"update-uboot-hsnand=run load-uboot-hsnand write-uboot-nand\0"
#else
#define CONFIG_ENV_WRITE_UBOOT_NAND
#define CONFIG_ENV_LOAD_UBOOT_NAND
#define CONFIG_ENV_LOAD_UBOOT_HSNAND
#define CONFIG_ENV_UPDATE_UBOOT_NAND
#define CONFIG_ENV_UPDATE_UBOOT_HSNAND
#endif

#define CONFIG_ENV_LANTIQ_DEFAULTS	\
	CONFIG_ENV_WRITE_UBOOT_NOR	\
	CONFIG_ENV_LOAD_UBOOT_NOR	\
	CONFIG_ENV_UPDATE_UBOOT_NOR	\
	CONFIG_ENV_SF_PROBE		\
	CONFIG_ENV_WRITE_UBOOT_SF	\
	CONFIG_ENV_LOAD_UBOOT_SF	\
	CONFIG_ENV_UPDATE_UBOOT_SF	\
	CONFIG_ENV_WRITE_UBOOT_NAND	\
	CONFIG_ENV_LOAD_UBOOT_NAND	\
	CONFIG_ENV_LOAD_UBOOT_HSNAND	\
	CONFIG_ENV_UPDATE_UBOOT_NAND	\
	CONFIG_ENV_UPDATE_UBOOT_HSNAND

#endif /* __LANTIQ_CONFIG_H__ */
