/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011 Daniel Schwierzeck, daniel.schwierzeck@googlemail.com
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"ZXV10 H201L"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"ZTE ZXV10 H201L"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART		/* Enable ASC and UART */
#define CONFIG_LTQ_SUPPORT_ETHERNET	/* Enable ethernet */
#define CONFIG_LTQ_SUPPORT_NOR_FLASH	/* Have a parallel NOR flash */

#if 0
#define CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH	/* Build NOR flash SPL */

#define CONFIG_LTQ_SPL_COMP_LZO
#define CONFIG_LTQ_SPL_CONSOLE
#endif

/* Switch devices */
#define CONFIG_SWITCH_MULTI
#define CONFIG_SWITCH_RTL8306

/* Environment */
#if defined(CONFIG_SYS_BOOT_NOR)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(256 * 1024)
#define CONFIG_ENV_SECT_SIZE		(64 * 1024)
#elif defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(128 * 1024)
#define CONFIG_ENV_SECT_SIZE		(64 * 1024)
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

/* Commands */
#define CONFIG_CMD_PING

/* Pull in default board configs for Lantiq XWAY Danube */
#include <asm/lantiq/config.h>
#include <asm/arch/config.h>

#if defined(CONFIG_SYS_BOOT_ZTE)
#define CONFIG_SYS_TEXT_BASE		0x80800000
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

#define CONFIG_ENV_UPDATE_UBOOT_NOR					\
	"update-uboot-nor=run load-uboot-norspl-lzo write-uboot-nor\0"

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS	\
	CONFIG_ENV_UPDATE_UBOOT_NOR

#endif /* __CONFIG_H */
