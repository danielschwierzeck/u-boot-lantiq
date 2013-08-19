/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"EASY80920"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"Lantiq EASY80920 VRX200 Family Board"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART		/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET	/* Enable ethernet */

#define CONFIG_LTQ_SUPPORT_NOR_FLASH	/* Have a parallel NOR flash */

#define CONFIG_LTQ_SUPPORT_SPI_FLASH
#define CONFIG_SPI_FLASH_MACRONIX	/* Have a MX29LV620 serial flash */

#define CONFIG_LTQ_SUPPORT_NAND_FLASH

#define CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH	/* Build SPI flash SPL */
#define CONFIG_SPL_SPI_BUS		0
#define CONFIG_SPL_SPI_CS		4
#define CONFIG_SPL_SPI_MAX_HZ		25000000
#define CONFIG_SPL_SPI_MODE		0

#define CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH	/* Build NOR flash SPL */

#define CONFIG_LTQ_SUPPORT_SPL_NAND_FLASH	/* Build NAND flash SPL */
#define CONFIG_SYS_NAND_PAGE_COUNT	128
#define CONFIG_SYS_NAND_PAGE_SIZE	2048
#define CONFIG_SYS_NAND_OOBSIZE		64
#define CONFIG_SYS_NAND_BLOCK_SIZE	(256 * 1024)
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	NAND_LARGE_BADBLOCK_POS
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x4000

#define CONFIG_LTQ_SPL_COMP_LZO
#define CONFIG_LTQ_SPL_CONSOLE

#define CONFIG_SYS_DRAM_PROBE

/* Environment */
#define CONFIG_ENV_SPI_BUS		CONFIG_SPL_SPI_BUS
#define CONFIG_ENV_SPI_CS		CONFIG_SPL_SPI_CS
#define CONFIG_ENV_SPI_MAX_HZ		CONFIG_SPL_SPI_MAX_HZ
#define CONFIG_ENV_SPI_MODE		CONFIG_SPL_SPI_MODE

#if defined(CONFIG_SYS_BOOT_NOR)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(384 * 1024)
#define CONFIG_ENV_SECT_SIZE		(64 * 1024)
#elif defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(192 * 1024)
#define CONFIG_ENV_SECT_SIZE		(64 * 1024)
#elif defined(CONFIG_SYS_BOOT_SFSPL)
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(192 * 1024)
#define CONFIG_ENV_SECT_SIZE		(64 * 1024)
#elif defined(CONFIG_SYS_BOOT_NANDSPL)
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(256 * 1024)
#define CONFIG_ENV_SECT_SIZE		(256 * 1024)
#else
#define CONFIG_ENV_IS_NOWHERE
#endif

#define CONFIG_ENV_SIZE			(8 * 1024)

#define CONFIG_LOADADDR			CONFIG_SYS_LOAD_ADDR

/* Console */
#define CONFIG_LTQ_ADVANCED_CONSOLE
#define CONFIG_BAUDRATE			115200
#define CONFIG_CONSOLE_ASC		1
#define CONFIG_CONSOLE_DEV		"ttyLTQ1"

/* Pull in default board configs for Lantiq XWAY VRX200 */
#include <asm/lantiq/config.h>
#include <asm/arch/config.h>

/* Pull in default OpenWrt configs for Lantiq SoC */
#include "openwrt-lantiq-common.h"

#define CONFIG_ENV_UPDATE_UBOOT_NOR					\
	"update-uboot-nor=run load-uboot-norspl-lzo write-uboot-nor\0"

#define CONFIG_ENV_UPDATE_UBOOT_SF					\
	"update-uboot-sf=run load-uboot-sfspl-lzo write-uboot-sf\0"

#define CONFIG_ENV_UPDATE_UBOOT_NAND					\
	"update-uboot-nand=run load-uboot-nandspl-lzo write-uboot-nand\0"

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS	\
	CONFIG_ENV_UPDATE_UBOOT_NOR	\
	CONFIG_ENV_UPDATE_UBOOT_SF	\
	CONFIG_ENV_UPDATE_UBOOT_NAND

#endif /* __CONFIG_H */
