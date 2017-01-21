/*
 * Copyright (C) 2011-2016 Daniel Schwierzeck, daniel.schwierzeck@googlemail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_IDENT_STRING	" fb3370"
#define CONFIG_BOARD_NAME	"AVM FritzBox 3370"

#define CONFIG_AUTOBOOT
#define CONFIG_BOOTDELAY 2
#define CONFIG_SYS_SPL_MALLOC_START (CONFIG_SYS_SDRAM_BASE + 100 * 1024 * 1024)
#define CONFIG_SYS_SPL_MALLOC_SIZE (28 * 1024 * 1024)
/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART			/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET		/* Enable ethernet */
#define CONFIG_FW_VRX200_PHY11G_A2X

#define CONFIG_LTQ_SUPPORT_SPI_FLASH
#define CONFIG_SPI_FLASH_MACRONIX		/* Have a MX29LV620 serial flash */

#define CONFIG_LTQ_SUPPORT_NAND_FLASH
#define CONFIG_LTQ_NAND_CS0
#define CONFIG_SYS_NAND_USE_FLASH_BBT
#define CONFIG_BCH
#define CONFIG_NAND_ECC_BCH

#define CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH	/* Build SPI flash SPL */
#define CONFIG_SPL_SPI_BUS		0
#define CONFIG_SPL_SPI_CS		4
#define CONFIG_SPL_SPI_MAX_HZ		25000000
#define CONFIG_SPL_SPI_MODE		0

#define CONFIG_LTQ_SPL_COMP_LZMA
#define CONFIG_LTQ_SPL_CONSOLE
#define CONFIG_LTQ_SPL_MC_TUNE
#define CONFIG_MISC_INIT_R

/* MTD devices */
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_SPI_FLASH_MTD
#define CONFIG_CMD_MTD
#define CONFIG_CMD_MTDPARTS
#define CONFIG_CMD_UBI
#define CONFIG_RBTREE

/* Environment */
#define CONFIG_ENV_SPI_BUS		CONFIG_SPL_SPI_BUS
#define CONFIG_ENV_SPI_CS		CONFIG_SPL_SPI_CS
#define CONFIG_ENV_SPI_MAX_HZ		CONFIG_SPL_SPI_MAX_HZ
#define CONFIG_ENV_SPI_MODE		CONFIG_SPL_SPI_MODE

#if defined(CONFIG_SYS_BOOT_SFSPL)
#define CONFIG_SPL_U_BOOT_OFFS		0x7400
#define CONFIG_SPL_U_BOOT_SIZE		0x37c00
#define CONFIG_SPL_MC_TUNE_OFFS		0x7200

#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		0x3f000
#define CONFIG_ENV_SECT_SIZE		0x1000

#define MTDPARTS_DEFAULT		\
	"mtdparts=spi0.4:252k(uboot),4k(uboot_env);nand-xway:-(ubi)"
#else
#define CONFIG_ENV_IS_NOWHERE

#define MTDPARTS_DEFAULT		"mtdparts="
#endif

#define MTDIDS_DEFAULT			"nor0=spi0.4,nand0=nand-xway"
#define CONFIG_ENV_SIZE			(0x1000)

#if defined(CONFIG_SYS_BOOT_EVA)
#define CONFIG_SYS_TEXT_BASE		0x80100000
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

/* Console */
#define CONFIG_LTQ_ADVANCED_CONSOLE
#define CONFIG_BAUDRATE			115200
#define CONFIG_CONSOLE_ASC		1

/* Commands */
#define CONFIG_CMD_PING
#define CONFIG_CMD_MISC
#define CONFIG_CMD_ECHO

/* Boot */
#define CONFIG_MIPS_BOOT_FDT
#define CONFIG_FIT
#define CONFIG_OF_LIBFDT
#define CONFIG_LZMA
#define CONFIG_LZO

/* Environment */
#define CONFIG_LOADADDR			CONFIG_SYS_LOAD_ADDR

#define CONFIG_ENV_MTDPARTS			\
	"mtdids="MTDIDS_DEFAULT"\0"		\
	"mtdparts="MTDPARTS_DEFAULT"\0"

/* Pull in default board configs for Lantiq XWAY VRX200 */
#include <asm/lantiq/config.h>
#include <asm/arch/config.h>

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS	\
	CONFIG_ENV_MTDPARTS

#endif /* __CONFIG_H */
