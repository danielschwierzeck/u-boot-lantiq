/*
 * Copyright (C) 2013 Luka Perkov <luka@openwrt.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"VGV953"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"SPEEDPORT W921V"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART			/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET		/* Enable ethernet */

#define CONFIG_LTQ_SUPPORT_NAND_FLASH		/* Have a ST NAND flash */

#define CONFIG_LTQ_SUPPORT_SPL_NAND_FLASH	/* Build NAND flash SPL */
#define CONFIG_LTQ_SPL_COMP_LZO			/* Compress SPL with LZO */
#define CONFIG_LTQ_SPL_CONSOLE			/* Enable SPL console */


/* Configure Nand */
#define CONFIG_SYS_NAND_SIZE		(32 * 1024 * 1024)
#define CONFIG_SYS_NAND_PAGE_COUNT	32
#define CONFIG_SYS_NAND_PAGE_SIZE	512
#define CONFIG_SYS_NAND_OOBSIZE		16
#define CONFIG_SYS_NAND_BLOCK_SIZE	(16 * 1024)
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	NAND_LARGE_BADBLOCK_POS
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x4000

#define CONFIG_SYS_DRAM_PROBE

#define CONFIG_SPL_TEXT_BASE		0xBE220200

/* UBI */
#define MTDIDS_DEFAULT			"nand0=nand"
#define MTDPARTS_DEFAULT		"mtdparts=nand:256k(uboot),128k(uboot_env);"

#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#define CONFIG_RBTREE
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_LZO

/* Environment */
#if defined(CONFIG_SYS_BOOT_NANDSPL) || defined(CONFIG_SYS_BOOT_NANDTPL)
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(256 * 1024)
#define CONFIG_ENV_SECT_SIZE		(128 * 1024)
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

#define CONFIG_ENV_UPDATE_UBOOT_NAND					\
	"update-uboot-nand=run load-uboot-nandtpl-lzo write-uboot-nand\0"

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS	\
	CONFIG_ENV_UPDATE_UBOOT_NAND

#endif /* __CONFIG_H */
