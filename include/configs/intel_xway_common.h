// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016-2020 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#ifndef __CONFIG_INTEL_XWAY_COMMON_H
#define __CONFIG_INTEL_XWAY_COMMON_H

/* RAM */
#define CONFIG_SYS_MEMTEST_START	0xa0000000
#define CONFIG_SYS_MEMTEST_END		0xa2000000

/* Serial */
#define CONFIG_BAUDRATE			115200

/* Memory usage */
#define CONFIG_SYS_MAXARGS		24
#define CONFIG_SYS_MALLOC_LEN		(1024 * 1024)
#define CONFIG_SYS_BOOTPARAMS_LEN	(128 * 1024)
#define CONFIG_SYS_CBSIZE		512

/* U-Boot */
#define	CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE

#endif /* __CONFIG_INTEL_XWAY_COMMON_H */
