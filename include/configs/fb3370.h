/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@googlemail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"FB3370"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"AVM FritzBox 3370"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART			/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET		/* Enable ethernet */
#define CONFIG_FW_VRX200_PHY11G_A2X

#define CONFIG_LTQ_SUPPORT_SPI_FLASH
#define CONFIG_SPI_FLASH_MACRONIX		/* Have a MX29LV620 serial flash */

#define CONFIG_LTQ_SUPPORT_NAND_FLASH
#define CONFIG_LTQ_SUPPORT_NAND_FLASH_CS0

#define CONFIG_SYS_NAND_USE_FLASH_BBT

#define CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH	/* Build SPI flash SPL */
#define CONFIG_LTQ_SPL_COMP_LZO			/* Compress SPL with LZO */
#define CONFIG_LTQ_SPL_CONSOLE			/* Enable SPL console */

#define CONFIG_SPL_SPI_BUS		0
#define CONFIG_SPL_SPI_CS		4
#define CONFIG_SPL_SPI_MAX_HZ		25000000
#define CONFIG_SPL_SPI_MODE		0

#define CONFIG_LTQ_SPL_COMP_LZO
#define CONFIG_LTQ_SPL_CONSOLE
#define CONFIG_LTQ_SPL_MC_TUNE

/* MTD devices */
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_SPI_FLASH_MTD
/*#define CONFIG_FLASH_CFI_MTD */
#define CONFIG_CMD_MTD
#define CONFIG_CMD_MTDPARTS
#define MTDIDS_DEFAULT			"nor0=spi0.4,nand0=nand-xway"

/* Environment */
#define CONFIG_ENV_SPI_BUS		CONFIG_SPL_SPI_BUS
#define CONFIG_ENV_SPI_CS		CONFIG_SPL_SPI_CS
#define CONFIG_ENV_SPI_MAX_HZ		CONFIG_SPL_SPI_MAX_HZ
#define CONFIG_ENV_SPI_MODE		CONFIG_SPL_SPI_MODE

#if defined(CONFIG_SYS_BOOT_SFSPL)
#define CONFIG_SPL_U_BOOT_OFFS		0x6800
#define CONFIG_SPL_U_BOOT_SIZE		0x37800
#define CONFIG_SPL_MC_TUNE_OFFS		0x3f800
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		0x3e000
#define CONFIG_ENV_SECT_SIZE	        0x1000

#define MTDPARTS_DEFAULT		\
	"mtdparts=spi0.4:192k(uboot),64k(uboot_env)"
#else
#define CONFIG_ENV_IS_NOWHERE

#define MTDPARTS_DEFAULT		"mtdparts="
#endif

#define CONFIG_ENV_SIZE			(0x1000)
#define CONFIG_LOADADDR			CONFIG_SYS_LOAD_ADDR

#if defined(CONFIG_SYS_BOOT_EVA)
#define CONFIG_SYS_TEXT_BASE		0x80100000
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

/* Console */
#define CONFIG_LTQ_ADVANCED_CONSOLE
#define CONFIG_BAUDRATE			115200
#define CONFIG_CONSOLE_ASC		1
#define CONFIG_CONSOLE_DEV		"ttyLTQ1"

#define CONFIG_MISC_INIT_R

/* Pull in default board configs for Lantiq XWAY VRX200 */
#include <asm/lantiq/config.h>
#include <asm/arch/config.h>

/* Pull in default OpenWrt configs for Lantiq SoC */
#include "openwrt-lantiq-common.h"

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS	\
	CONFIG_ENV_UPDATE_UBOOT_SF

#endif /* __CONFIG_H */
