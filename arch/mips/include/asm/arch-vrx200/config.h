/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * Common board configuration for Lantiq XWAY VRX200 family
 *
 * Use following defines in your board config to enable specific features
 * and drivers for this SoC:
 *
 * CONFIG_LTQ_SUPPORT_UART
 * - support the VRX200 ASC/UART interface and console
 *
 * CONFIG_LTQ_SUPPORT_NOR_FLASH
 * - support a parallel NOR flash via the CFI interface in flash bank 0
 *
 * CONFIG_LTQ_SUPPORT_ETHERNET
 * - support the VRX200 internal switch
 *
 * CONFIG_LTQ_SUPPORT_SPI_FLASH
 * - support the VRX200 SPI interface and serial flash drivers
 * - specific SPI flash drivers must be configured separately
 *
 * CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH
 * - build a preloader that runs in the internal SRAM and loads
 *   the U-Boot from SPI flash into RAM
 */

#ifndef __VRX200_CONFIG_H__
#define __VRX200_CONFIG_H__

/* CPU and SoC type */
#define CONFIG_SOC_LANTIQ
#define CONFIG_SOC_XWAY_VRX200

/* Cache configuration */
#define CONFIG_SYS_MIPS_CACHE_MODE	CONF_CM_CACHABLE_NONCOHERENT
#define CONFIG_SYS_DCACHE_SIZE		(32 * 1024)
#define CONFIG_SYS_ICACHE_SIZE		(32 * 1024)
#define CONFIG_SYS_CACHELINE_SIZE	32
#define CONFIG_SYS_MIPS_CACHE_EXT_INIT

/*
 * Supported clock modes
 * PLL0 clock output is 1000 MHz
 * PLL1 clock output is 393.219 MHz
 */
#define LTQ_CLK_CPU_600_DDR_300	0	/* Base PLL0, OCP 2 */
#define LTQ_CLK_CPU_600_DDR_200	1	/* Base PLL0, OCP 3 */
#define LTQ_CLK_CPU_500_DDR_250	2	/* Base PLL0, OCP 2 */
#define LTQ_CLK_CPU_500_DDR_200	3	/* Base PLL0, OCP 2.5 */
#define LTQ_CLK_CPU_333_DDR_167	4	/* Base PLL0, OCP 2 */
#define LTQ_CLK_CPU_167_DDR_167	5	/* Base PLL0, OCP 1 */
#define LTQ_CLK_CPU_125_DDR_125	6	/* Base PLL0, OCP 1 */
#define LTQ_CLK_CPU_393_DDR_197	7	/* Base PLL1, OCP 2 */
#define LTQ_CLK_CPU_197_DDR_197	8	/* Base PLL1, OCP 1 */

/* CPU speed */
#define CONFIG_SYS_CLOCK_MODE		LTQ_CLK_CPU_500_DDR_250
#define CONFIG_SYS_MIPS_TIMER_FREQ	250000000
#define CONFIG_SYS_HZ			1000

/* RAM */
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_SDRAM_BASE_UC	0xa0000000
#define CONFIG_SYS_MEMTEST_START	0x81000000
#define CONFIG_SYS_MEMTEST_END		0x82000000
#define CONFIG_SYS_LOAD_ADDR		0x81000000
#define CONFIG_SYS_INIT_SP_OFFSET	(32 * 1024)

/* SRAM */
#define CONFIG_SYS_SRAM_BASE		0xBE220000
#define CONFIG_SYS_SRAM_SIZE		0x10000

/* ASC/UART driver and console */
#define CONFIG_LANTIQ_SERIAL
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/* GPIO */
#define CONFIG_LANTIQ_GPIO
#define CONFIG_LTQ_GPIO_MAX_BANKS	3
#define CONFIG_LTQ_HAS_GPIO_BANK3

/* FLASH driver */
#if defined(CONFIG_LTQ_SUPPORT_NOR_FLASH)
#ifndef CONFIG_SYS_MAX_FLASH_BANKS
#	define CONFIG_SYS_MAX_FLASH_BANKS	1
#endif
#define CONFIG_SYS_MAX_FLASH_SECT	256
#define CONFIG_SYS_FLASH_BASE		0xB0000000
#define CONFIG_FLASH_16BIT
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_16BIT
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#define CONFIG_FLASH_SHOW_PROGRESS	50
#define CONFIG_SYS_FLASH_PROTECTION
#define CONFIG_CFI_FLASH_USE_WEAK_ADDR_SWAP

#define CONFIG_CMD_FLASH
#else
#define CONFIG_SYS_NO_FLASH
#endif /* CONFIG_NOR_FLASH */

#if defined(CONFIG_LTQ_SUPPORT_SPI_FLASH)
#define CONFIG_LANTIQ_SPI
#define CONFIG_SPI_FLASH

#define CONFIG_CMD_SF
#define CONFIG_CMD_SPI
#endif

#if defined(CONFIG_LTQ_SUPPORT_NAND_FLASH)
#define CONFIG_NAND_LANTIQ
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0xB4000000

#define CONFIG_CMD_NAND
#endif

#if defined(CONFIG_LTQ_SUPPORT_ETHERNET)
#define CONFIG_LANTIQ_DMA
#define CONFIG_LANTIQ_VRX200_SWITCH
#define CONFIG_PHY_LANTIQ

#define CONFIG_SYS_RX_ETH_BUFFER	8
#define CONFIG_PHYLIB
#define CONFIG_MII
#define CONFIG_UDP_CHECKSUM

#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#endif

#define CONFIG_SPL_MAX_SIZE		(32 * 1024)
#define CONFIG_SPL_BSS_MAX_SIZE		(8 * 1024)
#define CONFIG_SPL_STACK_MAX_SIZE	(8 * 1024)
#define CONFIG_SPL_MALLOC_MAX_SIZE	(32 * 1024)
#define CONFIG_SPL_STACK_BSS_IN_SRAM

#if defined(CONFIG_SPL_STACK_BSS_IN_SRAM)
#define CONFIG_SPL_STACK_BASE		(CONFIG_SYS_SRAM_BASE + \
					CONFIG_SPL_MAX_SIZE + \
					CONFIG_SPL_STACK_MAX_SIZE - 1)
#define CONFIG_SPL_BSS_BASE	  	(CONFIG_SPL_STACK_BASE + 1)
#define CONFIG_SPL_MALLOC_BASE		(CONFIG_SYS_SDRAM_BASE + \
					CONFIG_SYS_INIT_SP_OFFSET)
#else
#define CONFIG_SPL_STACK_BASE		(CONFIG_SYS_SDRAM_BASE + \
					CONFIG_SYS_INIT_SP_OFFSET + \
					CONFIG_SPL_STACK_MAX_SIZE - 1)
#define CONFIG_SPL_BSS_BASE		(CONFIG_SPL_STACK_BASE + 1)
#define CONFIG_SPL_MALLOC_BASE		(CONFIG_SPL_BSS_BASE + \
					CONFIG_SPL_BSS_MAX_SIZE)
#endif

#if defined(CONFIG_SYS_BOOT_RAM)
#define CONFIG_SYS_TEXT_BASE		0xA0100000
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SYS_DISABLE_CACHE
#endif

#if defined(CONFIG_SYS_BOOT_EVA)
#define CONFIG_SYS_TEXT_BASE		0x80100000
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

#if defined(CONFIG_SYS_BOOT_ZTE)
#define CONFIG_SYS_TEXT_BASE		0x80800000
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

#if defined(CONFIG_SYS_BOOT_NOR)
#define CONFIG_SYS_TEXT_BASE		0xB0000000
#endif

#if defined(CONFIG_SYS_BOOT_SFSPL)
#define CONFIG_SYS_TEXT_BASE		0x80100000
#define CONFIG_SPL_TEXT_BASE		0xBE220000
#endif

#if defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_SYS_TEXT_BASE		0x80100000
#define CONFIG_SPL_TEXT_BASE		0xB0000000
#endif

#if defined(CONFIG_SYS_BOOT_NOR) || defined(CONFIG_SYS_BOOT_NORSPL)
#define CONFIG_SYS_XWAY_EBU_BOOTCFG	0x688C688C
#define CONFIG_XWAY_SWAP_BYTES
#endif

#define	CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE

#endif /* __VRX200_CONFIG_H__ */
