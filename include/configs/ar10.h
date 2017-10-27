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
 * This file contains the configuration parameters for the AR9 board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <configs/autoconf.h>
#include <configs/lq_cfg.h>
#include <asm/ar10.h>


#ifdef CONFIG_AR10_CPU_125M_RAM_125M
#define CPU_CLOCK_RATE          125000000   /* 125 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          125000000   /* 125 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_250M_RAM_125M)
#define CPU_CLOCK_RATE          250000000   /* 250 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          125000000   /* 125 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_250M_RAM_250M)
#define CPU_CLOCK_RATE          250000000   /* 250 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          250000000   /* 250 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_500M_RAM_250M)
#define CPU_CLOCK_RATE          500000000   /* 500 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          250000000   /* 250 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_150M_RAM_150M)
#define CPU_CLOCK_RATE          150000000   /* 150 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          150000000   /* 150 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_300M_RAM_150M)
#define CPU_CLOCK_RATE          300000000   /* 300 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          150000000   /* 150 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_300M_RAM_300M)
#define CPU_CLOCK_RATE          300000000   /* 300 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          300000000   /* 300 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_500M_RAM_200M)
#define CPU_CLOCK_RATE          500000000   /* 500 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          200000000   /* 250 MHz clock for RAM           */
#elif defined(CONFIG_AR10_CPU_600M_RAM_300M)
#define CPU_CLOCK_RATE          600000000   /* 600 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          300000000   /* 300 MHz clock for RAM           */
#elif defined(CONFIG_GRX390_CPU_666M_RAM_333M)
#define CPU_CLOCK_RATE          666000000   /* 666 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          333000000   /* 333 MHz clock for RAM           */
#elif defined(CONFIG_GRX390_CPU_180M_RAM_180M)
#define CPU_CLOCK_RATE          180000000   /* 180 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          180000000   /* 180 MHz clock for RAM           */
#elif defined(CONFIG_GRX390_CPU_360M_RAM_180M)
#define CPU_CLOCK_RATE          360000000   /* 360 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          180000000   /* 180 MHz clock for RAM           */
#elif defined(CONFIG_GRX390_CPU_360M_RAM_360M)
#define CPU_CLOCK_RATE          360000000   /* 360 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          360000000   /* 360 MHz clock for RAM           */
#elif defined(CONFIG_GRX390_CPU_720M_RAM_360M)
#define CPU_CLOCK_RATE          720000000   /* 720 MHz clock for the MIPS core */
#define RAM_CLOCK_RATE          360000000   /* 360 MHz clock for RAM           */
#elif defined(CONFIG_GRX390_CPUFREQ_AUTO_DETECT)
#define IS_FUSED ((REG32(AR10_ID_CFG) & 0x20000) ?  1 : 0)
#define CPU_CLOCK_RATE 	((IS_FUSED) ? 600000000 : 720000000)
#define RAM_CLOCK_RATE  ((IS_FUSED) ? 300000000 : 360000000)
#endif

#define F_SSC_CLK  get_fpi_clk()
#define CONFIG_SYS_HZ 1000
#define CONFIG_ENV_SPI_CS 0
#define CONFIG_ENV_SPI_MODE CONFIG_SF_DEFAULT_MODE



#ifndef	CPU_CLOCK_RATE
/* allowed values: 100000000, 133000000, and 150000000 */
#define CPU_CLOCK_RATE	150000000	/* default: 150 MHz clock for the MIPS core */
#endif

//#define CONFIG_BAUDRATE		115200
//#define CONFIG_BAUDRATE           2400

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

#define CONFIG_SYS_ASC_BASE 0xbe100c00
#define	CONFIG_TIMESTAMP		/* Print image info with timestamp */

#ifndef CONFIG_PREBOOT
#define CONFIG_PREBOOT	"echo;"	\
	"echo Type \\\"run flash_nfs\\\" to mount root filesystem over NFS;" \
	"echo"
#endif

#undef	CONFIG_BOOTARGS

#define CONFIG_EXTRA_ENV_SETTINGS   <configs/lq_extra_env.h>

/*
 * Miscellaneous configurable options
 */
#define	CONFIG_SYS_LONGHELP				/* undef to save memory      */
#ifndef CONFIG_DRIVER_GRX390
#define	CONFIG_SYS_PROMPT		"AR10 # "	/* Monitor Command Prompt    */
#else
#define	CONFIG_SYS_PROMPT		"GRX330 # "	/* Monitor Command Prompt    */
#endif /* DRIVER_GRX390 */
#define	CONFIG_SYS_CBSIZE		1024		/* Console I/O Buffer Size   */
#define	CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)  /* Print Buffer Size */
#define	CONFIG_SYS_MAXARGS		32		/* max number of command args*/

#ifdef CONFIG_BOOT_FROM_NAND
#define CONFIG_SYS_MALLOC_LEN		CONFIG_NAND_PAGE_SIZE*1024*2
#else
#define CONFIG_SYS_MALLOC_LEN       512*1024
#endif

#define CONFIG_SYS_BOOTPARAMS_LEN	256*1024

#define CONFIG_SYS_MIPS_TIMER_FREQ	CPU_CLOCK_RATE/2


#define CONFIG_SYS_SDRAM_BASE		0x80000000

#define	CONFIG_SYS_LOAD_ADDR		0x80100000	/* default load address	*/

#define CONFIG_SYS_MEMTEST_START	0x80100000
#define CONFIG_SYS_MEMTEST_END		0x80800000

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define CONFIG_SYS_MAX_FLASH_SECT	(256)	/* max number of sectors on one chip */

#define PHYS_FLASH_1		0xb0000000 /* Flash Bank #1 */
#define PHYS_FLASH_2		0xb0800000 /* Flash Bank #2 */

#define CONFIG_SYS_FLASH_SWAP_ADDR

#define FLASH_FIXUP_ADDR_8(addr)        ((void*)((ulong)(addr)^2))
#define FLASH_FIXUP_ADDR_16(addr)       ((void*)((ulong)(addr)^2))

#define CONFIG_SYS_FLASH_CFI_WIDTH      FLASH_CFI_16BIT

#define CONFIG_EBU_ADDSEL0               0x10000031
#define CONFIG_EBU_BUSCON0               0x0001D7FF


/* The following #defines are needed to get flash environment right */
#define	CONFIG_SYS_MONITOR_BASE	CONFIG_RAM_TEXT_BASE

#define	CONFIG_SYS_MONITOR_LEN		(512 << 10)

#define CONFIG_SYS_INIT_SP_OFFSET	0x400000

#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT	(2 * CONFIG_SYS_HZ) /* Timeout for Flash Erase */
#define CONFIG_SYS_FLASH_WRITE_TOUT	(2 * CONFIG_SYS_HZ) /* Timeout for Flash Write */


#define CONFIG_FLASH_16BIT

#define CONFIG_NR_DRAM_BANKS	1

#define CONFIG_NET_MULTI

#define CONFIG_SYS_MAX_NAND_DEVICE    1
#ifdef CONFIG_NAND_CS0
#define CONFIG_SYS_NAND_BASE   0xb0000000
#else
#define CONFIG_SYS_NAND_BASE   0xb4000000
#endif
#define NAND_BASE_ADDRESS  CONFIG_SYS_NAND_BASE
#define NAND_WRITE(addr, val)     *((volatile u8*)(NAND_BASE_ADDRESS | (addr))) = val;while((*EBU_NAND_WAIT & 0x08) == 0);
#define NAND_READ(addr, val)      val = *((volatile u8*)(NAND_BASE_ADDRESS | (addr)));while((*EBU_NAND_WAIT & 0x08) == 0);

#ifdef CONFIG_NAND_CS0
#define NAND_CE_SET         *EBU_NAND_CON |= 1<<20;
#define NAND_CE_CLEAR       *EBU_NAND_CON &= ~(1<<20);
#else
#define NAND_CE_SET         *EBU_NAND_CON   = 0x00F405F3
#define NAND_CE_CLEAR       *EBU_NAND_CON   = 0x000005F3
#endif

//#define NAND_READY       ( ((*EBU_NAND_WAIT)&0x07) == 7)
#define NAND_READY       ( ((*EBU_NAND_WAIT)&0x01) == 1)

#define NAND_READY_CLEAR  *EBU_NAND_WAIT = 0;
#define WRITE_CMD    0x18
#define WRITE_ADDR   0x14
#define WRITE_LADDR  0x10
#define WRITE_DATA  0x10
#define READ_DATA    0x10
#define READ_LDATA   0x00
#define ACCESS_WAIT
#define IFX_ATC_NAND 0xc176
#define IFX_BTC_NAND 0xc166
#define ST_512WB2_NAND 0x2076
#define NAND_LATCH_ENABLE 
#define NAND_CLRALE  *EBU_NAND_CON &=~(1<<18);
#define NAND_SETALE  *EBU_NAND_CON |=1<<18; 
#define NAND_CLRCLE  *EBU_NAND_CON &=~(1<<19);
#define NAND_SETCLE  *EBU_NAND_CON |=1<<19;



#define NAND_DISABLE_CE(nand) *EBU_NAND_CON = *EBU_NAND_CON & ~(1<<20);
#define NAND_ENABLE_CE(nand)  *EBU_NAND_CON = *EBU_NAND_CON |(1<<20);
#define NAND_WAIT_READY(nand) while(!NAND_READY){}
#define WRITE_NAND_COMMAND(d, adr) NAND_WRITE(WRITE_CMD,d);
#define WRITE_NAND_ADDRESS(d, adr) NAND_WRITE(WRITE_ADDR,d);
#define WRITE_NAND(d, adr) NAND_WRITE(WRITE_DATA,d);
#define READ_NAND(adr) *((volatile u8*)(NAND_BASE_ADDRESS | (READ_DATA)))
#define IFX_NAND_CTL_CLRALE *EBU_NAND_CON &=~(1<<18);
#define IFX_NAND_CTL_SETALE *EBU_NAND_CON |=1<<18;


//#define CONFIG_SYS_NAND_PAGE_SIZE   ( 2<<10 )   /* NAND chip page size        */
//#define CONFIG_SYS_NAND_BLOCK_SIZE  ( 256 << 10 ) /* NAND chip block size       */

#define CONFIG_SYS_NAND_PAGE_SIZE   CONFIG_NAND_PAGE_SIZE   /* NAND chip page size        */
#define CONFIG_SYS_NAND_BLOCK_SIZE  CONFIG_NAND_BLOCK_SIZE /* NAND chip block size       */
#define CONFIG_SYS_NAND_PAGE_COUNT  (CONFIG_SYS_NAND_BLOCK_SIZE / CONFIG_SYS_NAND_PAGE_SIZE)
/* NAND chip page count       */


#if (CONFIG_NAND_PAGE_SIZE == 0x200 )
   #define CONFIG_SYS_NAND_BAD_BLOCK_POS   5       /* Location of bad block marker*/
   #define CONFIG_SYS_NAND_OOBSIZE 16
   #define CONFIG_SYS_NAND_ECCPOS      {0, 1, 2, 3, 6, 7}
   #if (CONFIG_NAND_FLASH_SIZE>=32)
    #define CONFIG_SYS_NAND_4_ADDR_CYCLE
   #endif
 #else
   #define CONFIG_SYS_NAND_BAD_BLOCK_POS   0       /* Location of bad block marker*/
   #define CONFIG_SYS_NAND_OOBSIZE 64
   #define CONFIG_SYS_NAND_ECCPOS      {40, 41, 42, 43, 44, 45, 46, 47, \
                                        48, 49, 50, 51, 52, 53, 54, 55, \
                                        56, 57, 58, 59, 60, 61, 62, 63}
   #define CONFIG_SYS_NAND_5_ADDR_CYCLE            /* Fifth addr used (<=128MB)  */
#endif



#define CONFIG_SYS_NAND_ECCSIZE 256
#define CONFIG_SYS_NAND_ECCBYTES    3
#define CONFIG_SYS_NAND_ECCSTEPS    (CONFIG_SYS_NAND_PAGE_SIZE / CONFIG_SYS_NAND_ECCSIZE)
#define CONFIG_SYS_NAND_ECCTOTAL    (CONFIG_SYS_NAND_ECCBYTES * CONFIG_SYS_NAND_ECCSTEPS)


#define CONFIG_SYS_NAND_U_BOOT_SIZE  ( 256 << 10 )

#ifdef CONFIG_LTQ_SECURE_BOOT 
#define CONFIG_SYS_NAND_U_BOOT_DST   CONFIG_STAGE2_LOADADDR
#define CONFIG_SYS_NAND_U_BOOT_START CONFIG_STAGE2_LOADADDR
#else 
#define CONFIG_SYS_NAND_U_BOOT_DST   CONFIG_BOOTSTRAP_TEXT_BASE
#define CONFIG_SYS_NAND_U_BOOT_START CONFIG_BOOTSTRAP_TEXT_BASE
#endif

#ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
#define CONFIG_SYS_NAND_U_BOOT_OFFS  ( CONFIG_MLC_NAND_HEADER_NUMBER * 32768 )
#else
#define CONFIG_SYS_NAND_U_BOOT_OFFS  CONFIG_NAND_SPL_BLOCK_SIZE
#endif

#ifdef CONFIG_BOOT_FROM_NOR
#define IFX_CFG_FLASH_DDR_CFG_START_ADDR      0xB000FFE0
#define IFX_CFG_FLASH_DDR_CFG_SIZE            32
#define IFX_CFG_FLASH_DDR_CFG_END_ADDR        0xb000ffff
#elif defined(CONFIG_BOOT_FROM_SPI)
#define IFX_CFG_FLASH_DDR_CFG_START_ADDR      0x0000FFE0
#define IFX_CFG_FLASH_DDR_CFG_SIZE            32
#define IFX_CFG_FLASH_DDR_CFG_END_ADDR        0x0000ffff
#define CONFIG_ENV_SECT_SIZE 0x1000
#else /*CONFIG_BOOT_FRON_NAND*/
 #ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
   #define IFX_CFG_FLASH_DDR_CFG_START_ADDR      0x0003ffe0
   #define IFX_CFG_FLASH_DDR_CFG_SIZE            32
   #define IFX_CFG_FLASH_DDR_CFG_END_ADDR        0x0003ffff 
 #else
  #ifdef CONFIG_LTQ_SECURE_BOOT
   #define IFX_CFG_FLASH_DDR_CFG_START_ADDR      0x00007fe0
   #define IFX_CFG_FLASH_DDR_CFG_SIZE            32
   #define IFX_CFG_FLASH_DDR_CFG_END_ADDR        0x00007fff
  #else
   #define IFX_CFG_FLASH_DDR_CFG_START_ADDR      0x00003fe0
   #define IFX_CFG_FLASH_DDR_CFG_SIZE            32
   #define IFX_CFG_FLASH_DDR_CFG_END_ADDR        0x00003fff
  #endif
 #endif
#endif

/* Address and size of Primary Environment Sector	*/
#if (defined CONFIG_CMD_UBI) && !(defined CONFIG_NAND_ECC_HW) 
#define CONFIG_ENV_OFFSET     0x100000
#define CONFIG_ENV_ADDR       CONFIG_ENV_OFFSET
#define CONFIG_NAND_ENV_DST   (CONFIG_SYS_NAND_U_BOOT_DST + CONFIG_SYS_NAND_U_BOOT_SIZE)
#elif (defined CONFIG_CMD_UBI) && (defined CONFIG_NAND_ECC_HW)
 #if (CONFIG_NAND_PAGE_SIZE > 0x800)
	#define CONFIG_ENV_OFFSET     0x200000
	#define CONFIG_ENV_ADDR       0x200000
 #else
	#define CONFIG_ENV_OFFSET     0x100000
	#define CONFIG_ENV_ADDR       CONFIG_ENV_OFFSET
 #endif /* CONFIG_NAND_PAGE_SIZE > 0x800 */
#define CONFIG_NAND_ENV_DST   (CONFIG_SYS_NAND_U_BOOT_DST + CONFIG_SYS_NAND_U_BOOT_SIZE)
#else
#define CONFIG_ENV_OFFSET	  IFX_CFG_FLASH_UBOOT_CFG_START_ADDR
#define CONFIG_ENV_ADDR		  IFX_CFG_FLASH_UBOOT_CFG_START_ADDR
#ifndef CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE       IFX_CFG_FLASH_UBOOT_CFG_SIZE
#else
#define CONFIG_ENV_SIZE       0x1000
#endif
#endif


/*define u-boot env range, only meaningful for nand flash*/
#ifndef CONFIG_NAND_ECC_HW
  #ifdef CONFIG_ENV_REDUND
     #define CONFIG_ENV_OFFSET_REDUND    0x140000
     #define CONFIG_ENV_SIZE_REDUND      CONFIG_ENV_SIZE
     #define CONFIG_ENV_RANGE            0x40000
  #else
     #define CONFIG_ENV_RANGE            0x80000
  #endif /* CONFIG_ENV_REDUND */
#else
  #ifdef CONFIG_ENV_REDUND
    #define CONFIG_ENV_SIZE_REDUND      CONFIG_ENV_SIZE
	#if (CONFIG_NAND_PAGE_SIZE > 0x800)
      #define CONFIG_ENV_OFFSET_REDUND    0x600000
      #define CONFIG_ENV_RANGE            0x400000
	#else
      #define CONFIG_ENV_OFFSET_REDUND    0x140000
      #define CONFIG_ENV_RANGE            0x40000
	#endif /* CONFIG_NAND_PAGE_SIZE > 0x800 */
  #else
	#if (CONFIG_NAND_PAGE_SIZE > 0x800)
      #define CONFIG_ENV_RANGE            0x800000
	#else
	  #define CONFIG_ENV_RANGE            0x80000
	#endif /* CONFIG_NAND_PAGE_SIZE > 0x800 */
  #endif /* CONFIG_ENV_REDUND */
#endif /* CONFIG_NAND_ECC_HW */


/*********************************************************/

//#define CONFIG_SYS_RX_ETH_BUFFER        8

#define CONFIG_TUNING_STATUS 0xBE1A7F2C 
//#define CONFIG_TUNING_SP     0xBE22FF00 

#ifdef CONFIG_DEBUG
#define DEBUG
#endif

#define MTDIDS_DEFAULT   CONFIG_MTDIDS
#define MTDPARTS_DEFAULT CONFIG_MTDPARTS


#endif	/* __CONFIG_H */
