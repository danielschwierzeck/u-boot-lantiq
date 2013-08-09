/*
 * Copyright (C) 2012-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"EASYBOX904"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"Arcadyan EasyBox 904"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART			/* Enable ASC and UART */

#define CONFIG_LTQ_SUPPORT_ETHERNET		/* Enable ethernet */

#define CONFIG_LTQ_SUPPORT_NAND_FLASH

#define CONFIG_SYS_DRAM_PROBE

/* Environment */
#define CONFIG_ENV_IS_NOWHERE

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

#define CONFIG_EXTRA_ENV_SETTINGS	\
	CONFIG_ENV_LANTIQ_DEFAULTS

#endif /* __CONFIG_H */
