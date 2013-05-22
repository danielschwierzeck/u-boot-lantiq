/*
 * Copyright (C) 2013-2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_IDENT_STRING	"P661HNUFX"
#define CONFIG_BOARD_NAME	"Zyxel P-661HNU-Fx"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART		/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET	/* Enable ethernet */

#define CONFIG_LTQ_SUPPORT_SPI_FLASH
#define CONFIG_SPI_FLASH_MACRONIX	/* Supports Macronix serial flash */

#define CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH	/* Build SPI flash SPL */
#define CONFIG_SPL_SPI_BUS		0
#define CONFIG_SPL_SPI_CS		4
#define CONFIG_SPL_SPI_MAX_HZ		25000000
#define CONFIG_SPL_SPI_MODE		0

#define CONFIG_LTQ_SPL_COMP_LZO
#define CONFIG_LTQ_SPL_CONSOLE

/* Switch devices */
#define CONFIG_SWITCH_MULTI
#define CONFIG_SWITCH_PSB697X

/* MTD devices */
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_SPI_FLASH_MTD
#define CONFIG_CMD_MTD
#define CONFIG_CMD_MTDPARTS

/* Environment */
#define CONFIG_ENV_SPI_BUS		CONFIG_SPL_SPI_BUS
#define CONFIG_ENV_SPI_CS		CONFIG_SPL_SPI_CS
#define CONFIG_ENV_SPI_MAX_HZ		CONFIG_SPL_SPI_MAX_HZ
#define CONFIG_ENV_SPI_MODE		CONFIG_SPL_SPI_MODE

#if defined(CONFIG_SYS_BOOT_SFSPL)
#define CONFIG_SPL_U_BOOT_OFFS		0x7000
#define CONFIG_SPL_U_BOOT_SIZE		0x44000

#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(512 * 1024)
#define CONFIG_ENV_SECT_SIZE		(256 * 1024)

#define MTDPARTS_DEFAULT		\
	"mtdparts=spi0.4:512k(uboot),256k(uboot_env)"
#else
#define CONFIG_ENV_IS_NOWHERE

#define MTDPARTS_DEFAULT		"mtdparts="
#endif

#define MTDIDS_DEFAULT			"nor0=spi0.4"
#define CONFIG_ENV_SIZE			(8 * 1024)

#if defined(CONFIG_SYS_BOOT_ZYXEL)
#define CONFIG_SYS_TEXT_BASE		0x80800000
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
