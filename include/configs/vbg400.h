/*
 * (C) Copyright 2003-2005
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * This file contains the configuration parameters for the vbg400 board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <configs/autoconf.h>
#include <configs/lq_cfg.h>

#define CONFIG_MIPS32		1	/* MIPS 4Ke CPU core	*/

#ifndef	CPU_CLOCK_RATE
#ifndef CONFIG_VBG400_CHIPIT
#define CPU_CLOCK_RATE      240000000	/* default: 24 MHz clock for the MIPS core */
#else
#define CPU_CLOCK_RATE      48000000	/* default: 24 MHz clock for the MIPS core */
#endif
#endif

#ifndef	SYS_CLOCK_RATE
#ifndef CONFIG_VBG400_CHIPIT
#define SYS_CLOCK_RATE	240000000	/* default: 24 MHz system clock */
#else
#define SYS_CLOCK_RATE	24000000	/* default: 24 MHz system clock */
#endif
#endif

#define CONFIG_BAUDRATE		115200 //enter to default_environment
//#define CONFIG_BAUDRATE		9600 //enter to default_environment


#define VBG400_RAM            1       /* NO flash support   */
#define PROTO		       1
#define JTAG		       1

#define CONFIG_GATEWAYIP 192.168.1.1
#define CONFIG_NETMASK   255.255.255.0

#define CONFIG_MII              1       /* MII PHY management */
#define CONFIG_CMD_MII

#define CONFIG_HAS_ETH0         1
#define CONFIG_HAS_ETH1         0

#define INFINEON_EBU_BOOTCFG  0x40C4  /* CMULT = 8 */
#define CFG_TX_ETH_BUFFER	12

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }


#define	CONFIG_TIMESTAMP		/* Print image info with timestamp */

#ifndef CONFIG_PREBOOT
#define CONFIG_PREBOOT	"echo;"	
#define

#undef	CONFIG_BOOTARGS

#define	CONFIG_VBG400_IP_SWITCH


#define CONFIG_EXTRA_ENV_SETTINGS   <configs/lq_extra_env.h>


/*
 * Chip related
 */
#define VBG400_SYS_INTERFACE_BASE_ADDR	0xa7000000

/* DUummy - to compile lq_spi.c */
#define F_SSC_CLK  5
/* DUummy - to compile lq_extra_env.h */
#ifndef CONFIG_RESET_DDR_CONFIG
#define CONFIG_RESET_DDR_CONFIG "not_supported"
#endif
/*
 * Miscellaneous configurable options
 */
#define CONFIG_CMDLINE_EDITING          /* Command-line editing */

#define	CONFIG_SYS_LONGHELP				/* undef to save memory      */
#define	CONFIG_SYS_PROMPT		"Lantiq # "	/* Monitor Command Prompt    */
#define	CONFIG_SYS_CBSIZE		1024		/* Console I/O Buffer Size   */
#define	CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)  /* Print Buffer Size */
#define	CONFIG_SYS_MAXARGS		32		/* max number of command args*/

//#define CONFIG_SYS_MALLOC_LEN		128*1024
#define CONFIG_SYS_MALLOC_LEN		192*1024

#define CONFIG_SYS_BOOTPARAMS_LEN	128*1024
#define CFG_BOOTPARAMS_LEN CONFIG_SYS_BOOTPARAMS_LEN	/* delete */

//should be aligned to the rate used by timers
//#define CONFIG_SYS_HZ			CPU_CLOCK_RATE
#define CONFIG_SYS_HZ			SYS_CLOCK_RATE


#define CONFIG_SYS_SDRAM_BASE		0xa0000000
#define CFG_SDRAM_BASE CONFIG_SYS_SDRAM_BASE /* delete */


#define	CFG_LOAD_ADDR		0xa0100000	/* default load address	*/
#define CFG_MEMTEST_START	0xa0100000
#define CFG_MEMTEST_END		0xa0800000
/* arad -new added */
#define	CONFIG_SYS_LOAD_ADDR CFG_LOAD_ADDR
#define CONFIG_SYS_MEMTEST_START CFG_MEMTEST_START
#define CONFIG_SYS_MEMTEST_END CFG_MEMTEST_END

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#ifdef CONFIG_DRIVER_VBG400
#define VBG400_VERSION "7"

#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define CFG_MAX_FLASH_SECT	(128)	/* max number of sectors on one chip */
/* arad -new added */
#define CONFIG_SYS_MAX_FLASH_SECT	CFG_MAX_FLASH_SECT	/* max number of sectors on one chip */
#define CONFIG_SYS_MAX_FLASH_BANKS CFG_MAX_FLASH_BANKS

#define VBG400_SPI_WR_ADDR   (VBG400_SYS_INTERFACE_BASE_ADDR+0x120)
#define VBG400_SPI_READ_ADDR (VBG400_SYS_INTERFACE_BASE_ADDR+0x124)
#define VBG400_SPI_MODE_ADDR (VBG400_SYS_INTERFACE_BASE_ADDR+0x130)

#define VBG400_SPI_MODE_SW_BIT (0x400) //When this bit is set, FLASH is accessed in SW mode
#define VBG400_SPI_MODE_SHIFT_PAGE_BITS 8 //to increment to next page
#define VBG400_SPI_MODE_CLEAR_PAGE_BITS 0xFCFF //to clean field
#define VBG400_SPI_PAGE_END 0xC0000000

#define VBG400_HW_MODE_READ

#define PHYS_FLASH_1		0x00000000 /* no flash base, only register interface to spi master */
//#define PHYS_FLASH_2		0xb0800000 /* Flash Bank #2 */


//#define VBG400_NPU_SYS_IF_REGS_OFFSET       0x70000000
#define VBG400_SHARED_REGS_OFFSET           0x001c0000
#define VBG400_SYS_RESET_REG_OFFSET         0x00000008
#define VBG400_RESET_OFFSET                 8
#define VBG400_RESET_ADDR                   (VBG400_SYS_INTERFACE_BASE_ADDR+VBG400_SHARED_REGS_OFFSET+VBG400_RESET_OFFSET)
#define VBG400_REBOOT_DATA                  0
#define VBG400_REBOOT_BIT_MASK_NOT          0xfffeffff
/*these shared registers are for clock and delay configuration*/
#define VBG400_SHARED_GMAC_BASE_ADDR        (VBG400_SYS_INTERFACE_BASE_ADDR+VBG400_SHARED_REGS_OFFSET)
#define VBG400_GMAC_MODE_REG_OFFSET         0x68
#define VBG400_GMAC_MODE_REG_ADDR           (VBG400_SYS_INTERFACE_BASE_ADDR+VBG400_SHARED_REGS_OFFSET+VBG400_GMAC_MODE_REG_OFFSET)
#define VBG400_GMAC_MODE_2_REG_OFFSET       0x80
#define VBG400_GMAC_MODE_2_REG_ADDR         (VBG400_SYS_INTERFACE_BASE_ADDR+VBG400_SHARED_REGS_OFFSET+VBG400_GMAC_MODE_2_REG_OFFSET)
#define VBG400_DLY_PGM_REG_OFFSET           0x64
#define VBG400_DLY_PGM_REG_ADDR             (VBG400_SYS_INTERFACE_BASE_ADDR+VBG400_SHARED_REGS_OFFSET+VBG400_DLY_PGM_REG_OFFSET)
#define VBG400_HCYCLE_CALIB_IND_REG_OFFSET  0x90
#define VBG400_HCYCLE_CALIB_IND_REG_ADDR    (VBG400_SYS_INTERFACE_BASE_ADDR+VBG400_SHARED_REGS_OFFSET+VBG400_HCYCLE_CALIB_IND_REG_OFFSET)


/* The following #defines are needed to get flash environment right */

//#define	CFG_MONITOR_BASE	TEXT_BASE
#define	CFG_MONITOR_BASE	0xa0100000
/* arad - new added */
#define	CONFIG_SYS_MONITOR_BASE CFG_MONITOR_BASE

#define	CFG_MONITOR_LEN		(192 << 10)
/* arad - new added */
#define	CONFIG_SYS_MONITOR_LEN CFG_MONITOR_LEN

#define CFG_INIT_SP_OFFSET	0x400000
/* arad - new added */
#define CONFIG_SYS_INIT_SP_OFFSET	CFG_INIT_SP_OFFSET

#define CFG_FLASH_BASE		PHYS_FLASH_1
#define CFG_FLASH_BASE_HW	0xBFC00000
//#define CFG_FLASH_BASE_HW_SECT_1 /*only if u-boot in sector 1: 0xBFC10000*/

//#define CFG_FLASH_BASE_HW_BOOTSTRAP   0xBFC00000
//#define CFG_FLASH_BASE_HW	0xBFC10000/*for uboot in sect 1 (for develop)*/

#define VBG400_FLASH_ENV_SECT 1 

/* arad - new added */
#define CONFIG_SYS_FLASH_BASE CFG_FLASH_BASE

/*to see the env upon Init enable it:*/
#define VBG400_PRINT_ENV
/*to force default env enable it:*/
//#define VBG400_USE_DEFAULT_ENV

#endif //CONFIG_DRIVER_VBG400

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT	(2 * CONFIG_SYS_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(2 * CONFIG_SYS_HZ) /* Timeout for Flash Write */

#define	CFG_ENV_IS_IN_FLASH	1


/* Address and size of Primary Environment Sector	*/
/* Note !:
   The RAM address is now hard coded.
   If DRAM size is autodetect (using initdram()), need to change Env handling as well*/
#define VBG400_SDRAM_SIZE 0x2000000

/* Address and size of Primary Environment Sector	*/
#define CONFIG_ENV_OFFSET		IFX_CFG_FLASH_UBOOT_CFG_START_ADDR
#define CONFIG_ENV_ADDR		  IFX_CFG_FLASH_UBOOT_CFG_START_ADDR
#define CONFIG_ENV_SIZE		  IFX_CFG_FLASH_UBOOT_CFG_SIZE

//#define CONFIG_FLASH_16BIT
#define CONFIG_FLASH_8BIT

#define CONFIG_NR_DRAM_BANKS    1

#define CONFIG_NET_MULTI        0

#endif	/* __CONFIG_H */
