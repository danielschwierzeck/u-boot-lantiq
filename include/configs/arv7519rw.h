/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"arv7519rw"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"Arcadyan ARV7519RW"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART		/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET	/* Enable ethernet */

#define CONFIG_LTQ_SUPPORT_NOR_FLASH	/* Have a parallel NOR flash */

#define CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH	/* Build NOR flash SPL */

#define CONFIG_LTQ_SPL_COMP_LZO
#define CONFIG_LTQ_SPL_CONSOLE

#define CONFIG_SYS_DRAM_PROBE

/* Environment */

#if defined(CONFIG_SYS_BOOT_NOR)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(384 * 1024)
#define CONFIG_ENV_SECT_SIZE		(128 * 1024)
#elif defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(384 * 1024)
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
	CONFIG_ENV_UPDATE_UBOOT_NOR

#endif /* __CONFIG_H */
