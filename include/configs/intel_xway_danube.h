// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016-2020 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#ifndef __CONFIG_INTEL_XWAY_DANUBE_H
#define __CONFIG_INTEL_XWAY_DANUBE_H

/* CPU */
#define CONFIG_SYS_MIPS_TIMER_FREQ	166666667

/* RAM */
#define CONFIG_SYS_SDRAM_BASE		0x80000000

/* SRAM */
#define CONFIG_SYS_SRAM_BASE		0xbe1a0000
#define CONFIG_SYS_SRAM_SIZE		0x10000

/* U-Boot */
#define CONFIG_SYS_LOAD_ADDR		0x80100000

#if defined(CONFIG_INTEL_BOOT_RAM)
#define CONFIG_SYS_INIT_SP_ADDR		0x80010000
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

#endif /* __CONFIG_INTEL_XWAY_DANUBE_H */
