/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011-2014 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#ifndef __LANTIQ_SPL_H__
#define __LANTIQ_SPL_H__

#if defined(CONFIG_LTQ_SPL_CONSOLE)
#define spl_has_console		1

#if defined(CONFIG_LTQ_SPL_DEBUG)
#define spl_has_debug		1
#else
#define spl_has_debug		0
#endif

#if defined(CONFIG_LTQ_SPL_MC_TUNE_DEBUG)
#define spl_mc_tune_debug	1
#else
#define spl_mc_tune_debug	0
#endif

#else
#define spl_has_console		0
#define spl_has_debug		0
#define spl_mc_tune_debug	0
#endif

#define spl_debug(fmt, args...)			\
	do {					\
		if (spl_has_debug)		\
			printf(fmt, ##args);	\
	} while (0)

#define spl_puts(msg)				\
	do {					\
		if (spl_has_console)		\
			puts(msg);		\
	} while (0)

#if defined(CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH) && defined(CONFIG_SYS_BOOT_SFSPL)
#define spl_boot_spi_flash	1
#else
#define spl_boot_spi_flash	0
#endif

#if defined(CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH) && defined(CONFIG_SYS_BOOT_NORSPL)
#define spl_boot_nor_flash	1
#else
#define spl_boot_nor_flash	0
#endif

#if defined(CONFIG_LTQ_SUPPORT_SPL_NAND_FLASH) && defined(CONFIG_SYS_BOOT_NANDSPL)
#define spl_boot_nand_flash	1
#else
#define spl_boot_nand_flash	0
#endif

#if defined(CONFIG_LTQ_SUPPORT_SPL_NAND_FLASH) && defined(CONFIG_SYS_BOOT_NANDHWSPL)

#define spl_boot_hsnand_flash	1
#else
#define spl_boot_hsnand_flash	0
#endif

#if defined(CONFIG_LTQ_SPL_MC_TUNE)
#define spl_mc_tune		1
#else
#define spl_mc_tune		0
#endif

#if defined(CONFIG_LTQ_SPL_REDUND_IMAGES)
#define spl_redund_images	CONFIG_LTQ_SPL_REDUND_IMAGES
#else
#define spl_redund_images	0
#endif

void mips_cache_reset(void);

#endif /* __LANTIQ_SPL_H__ */
