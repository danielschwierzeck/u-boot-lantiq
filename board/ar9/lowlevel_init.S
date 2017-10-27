
/*
 *  Memory sub-system initialization code for INCA-IP2 development board.
 *  Andre Messerschmidt
 *  Copyright (c) 2005	Infineon Technologies AG 
 *
 *  Based on Inca-IP code 
 *  Copyright (c) 2003	Wolfgang Denk <wd@denx.de>
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
/* History:
      peng liu May 25, 2006, for PLL setting after reset, 05252006
 */
#include <config.h>
#include <version.h>
#include <asm/regdef.h>
#include <configs/ar9.h>


#if defined(CONFIG_CPU_111M_RAM_111M) || defined(CONFIG_CPU_333M_RAM_111M)
#include "ar9_ddr111_settings.h"  
#elif defined(CONFIG_CPU_166M_RAM_166M) || defined(CONFIG_CPU_333M_RAM_166M) || defined(CONFIG_CPU_500M_RAM_166M) 
 #ifdef CONFIG_ETRON_RAM
  #include "etron_166_settings.h"
 #elif defined(CONFIG_HYNIX_RAM_H5DU2562GTR_E3C)
  #include "hynix_166_settings.h"
 #elif defined(CONFIG_HYNIX_RAM_H5DU5162ETR_E3C)
  #include "hynix64M_166_settings.h"
 #elif defined(CONFIG_QIMONDA_RAM)
  #include "qimonda_166_settings.h"
 #elif defined(CONFIG_NANYA_RAM)
   #include "nanya_ddr166_settings.h"
 #endif
#elif defined(CONFIG_CPU_442M_RAM_147M)
#include "ar9_ddr166_settings.h"
#elif defined(CONFIG_CPU_393M_RAM_196M)
 #ifdef CONFIG_ETRON_RAM
  #include "etron_196_settings.h"
 #elif defined(CONFIG_HYNIX_RAM_H5DU2562GTR_E3C)
  #include "hynix_196_settings.h"
 #elif defined(CONFIG_HYNIX_RAM_H5DU5162ETR_E3C)
   #include "hynix64M_196_settings.h"
 #elif defined(CONFIG_QIMONDA_RAM)
  #include "qimonda_196_settings.h"
 #endif 
#elif defined(CONFIG_CPU_442M_RAM_221M)
#include "ar9_ddr221_settings.h"
#elif defined(CONFIG_CPU_500M_RAM_250M)
#include "ar9_ddr250_settings.h"
#endif

#define EBU_MODUL_BASE		0xB4102000
#define EBU_CLC(value)		0x0000(value)
#define EBU_CON(value)		0x0010(value)
#define EBU_ADDSEL0(value)	0x0020(value)
#define EBU_ADDSEL1(value)	0x0024(value)
#define EBU_ADDSEL2(value)	0x0028(value)
#define EBU_ADDSEL3(value)	0x002C(value)
#define EBU_BUSCON0(value)	0x0060(value)
#define EBU_BUSCON1(value)	0x0064(value)
#define EBU_BUSCON2(value)	0x0068(value)
#define EBU_BUSCON3(value)	0x006C(value)

#define MC_MODUL_BASE		0xBF800000
#define MC_ERRCAUSE(value)	0x0010(value)
#define MC_ERRADDR(value)	0x0020(value)
#define MC_CON(value)		0x0060(value)

#define MC_SRAM_ENABLE		0x00000004
#define MC_SDRAM_ENABLE		0x00000002
#define MC_DDRRAM_ENABLE	0x00000001

#define MC_SDR_MODUL_BASE	0xBF800200
#define MC_IOGP(value)		0x0000(value)
#define MC_CTRLENA(value)	0x0010(value)
#define MC_MRSCODE(value)	0x0020(value)
#define MC_CFGDW(value)		0x0030(value)
#define MC_CFGPB0(value)	0x0040(value)
#define MC_LATENCY(value)	0x0080(value)
#define MC_TREFRESH(value)	0x0090(value)
#define MC_SELFRFSH(value)	0x00A0(value)

#define MC_DDR_MODUL_BASE	0xBF801000
#define MC_DC00(value)		0x0000(value)
#define MC_DC01(value)		0x0010(value)
#define MC_DC02(value)		0x0020(value)
#define MC_DC03(value)		0x0030(value)
#define MC_DC04(value)		0x0040(value)
#define MC_DC05(value)		0x0050(value)
#define MC_DC06(value)		0x0060(value)
#define MC_DC07(value)		0x0070(value)
#define MC_DC08(value)		0x0080(value)
#define MC_DC09(value)		0x0090(value)
#define MC_DC10(value)		0x00A0(value)
#define MC_DC11(value)		0x00B0(value)
#define MC_DC12(value)		0x00C0(value)
#define MC_DC13(value)		0x00D0(value)
#define MC_DC14(value)		0x00E0(value)
#define MC_DC15(value)		0x00F0(value)
#define MC_DC16(value)		0x0100(value)
#define MC_DC17(value)		0x0110(value)
#define MC_DC18(value)		0x0120(value)
#define MC_DC19(value)		0x0130(value)
#define MC_DC20(value)		0x0140(value)
#define MC_DC21(value)		0x0150(value)
#define MC_DC22(value)		0x0160(value)
#define MC_DC23(value)		0x0170(value)
#define MC_DC24(value)		0x0180(value)
#define MC_DC25(value)		0x0190(value)
#define MC_DC26(value)		0x01A0(value)
#define MC_DC27(value)		0x01B0(value)
#define MC_DC28(value)		0x01C0(value)
#define MC_DC29(value)		0x01D0(value)
#define MC_DC30(value)		0x01E0(value)
#define MC_DC31(value)		0x01F0(value)
#define MC_DC32(value)		0x0200(value)
#define MC_DC33(value)		0x0210(value)
#define MC_DC34(value)		0x0220(value)
#define MC_DC35(value)		0x0230(value)
#define MC_DC36(value)		0x0240(value)
#define MC_DC37(value)		0x0250(value)
#define MC_DC38(value)		0x0260(value)
#define MC_DC39(value)		0x0270(value)
#define MC_DC40(value)		0x0280(value)
#define MC_DC41(value)		0x0290(value)
#define MC_DC42(value)		0x02A0(value)
#define MC_DC43(value)		0x02B0(value)
#define MC_DC44(value)		0x02C0(value)
#define MC_DC45(value)		0x02D0(value)
#define MC_DC46(value)		0x02E0(value)

#define RCU_OFFSET  0xBF203000
#define RCU_RST_REQ      (RCU_OFFSET + 0x0010)
#define RCU_STS          (RCU_OFFSET + 0x0014)

#define CGU_OFFSET  0xBF103000
#define  PLL0_CFG     (CGU_OFFSET + 0x0004)
#define  PLL1_CFG     (CGU_OFFSET + 0x0008)
#define  PLL2_CFG     (CGU_OFFSET + 0x000C)
#define  CGU_SYS      (CGU_OFFSET + 0x0010)
#define  CGU_UPDATE   (CGU_OFFSET + 0x0014)
#define  IF_CLK       (CGU_OFFSET + 0x0018)
#define  CGU_SMD      (CGU_OFFSET + 0x0020)
#define  CGU_CT1SR    (CGU_OFFSET + 0x0028)
#define  CGU_CT2SR    (CGU_OFFSET + 0x002C)
#define  CGU_PCMCR    (CGU_OFFSET + 0x0030)
#define  PCI_CR_PCI   (CGU_OFFSET + 0x0034)
#define  CGU_OSC_CTRL (CGU_OFFSET + 0x001C)
#define  CGU_MIPS_PWR_DWN (CGU_OFFSET + 0x0038)
#define  CLK_MEASURE  (CGU_OFFSET + 0x003C)

//05252006
#define  pll0_25MHz_CONFIG 0x00b044C1
#define  pll1_25MHz_CONFIG 0x9AA2E785
#define  pll0_35MHz_CONFIG 0x9D861059
#define  pll1_35MHz_CONFIG 0x1A260CD9
#define  pll2_35MHz_CONFIG 0x8000f1e5
#define  pll0_36MHz_CONFIG 0x1000125D
#define  pll1_36MHz_CONFIG 0x9800f25f
#define  pll2_36MHz_CONFIG 0x8002f2a1
//05252006

//06063001-joelin disable the PCI CFRAME mask -start
/*CFRAME is an I/O signal, in the chip, the output CFRAME is selected via GPIO altsel pins, so if you select MII1 RXD1, the CFRAME will not come out.
But the CFRAME input still take the signal from the pad and not disabled when altsel choose other function. So when MII1_RXD1 is low from other device, the EBU interface will be disabled.

The chip function in such a way that disable the CFRAME mask mean EBU not longer check CFRAME to be the device using the bus.
The side effect is the entire PCI block will see CFRAME low all the time meaning PCI cannot use the bus at all so no more PCI function.
*/
//#define PCI_CR_PR_OFFSET  0xBE105400
#define PCI_CR_PCI_MOD_REG          (PCI_CR_PR_OFFSET + 0x0030)
#define PCI_CONFIG_SPACE  0xB7000000
#define CS_CFM		(PCI_CONFIG_SPACE + 0x6C)
//06063001-joelin disable the PCI CFRAME mask -end
	.set	noreorder


/*
 * void ebu_init(long)
 *
 * a0 has the clock value we are going to run at
 */
	.globl	ebu_init
	.ent	ebu_init
ebu_init:
/*TODO:liupeng */
	j	ra
	nop

	.end	ebu_init


/*
 * void cgu_init(long)
 *
 * a0 has the clock value
 */
	.globl	cgu_init
	.ent	cgu_init
cgu_init:
#ifdef USE_25MHz_CLOCK
        li  t1, PLL0_CFG
        li  a1, pll0_25MHz_CONFIG
        sw  a1, 0(t1)
        li  t1, PLL1_CFG
        li  a1, pll1_25MHz_CONFIG
        sw  a1, 0(t1)
#endif
	li  t2, CGU_SYS
        lw  t2,0(t2)
        beq t2,a0,freq_up2date
        nop
	li  t1, CGU_SYS
	sw	a0,0(t1)

#if defined(CONFIG_CPU_333M_RAM_166M) && defined(CONFIG_USE_PLL1) && !defined(USE_25MHz_CLOCK)
        li  t1, PLL1_CFG
        li  a1, pll1_36MHz_CONFIG
        sw  a1, 0(t1)
#endif
#if (defined(CONFIG_CPU_442M_RAM_221M) || defined(CONFIG_CPU_442M_RAM_147M)) && defined(CONFIG_USE_PLL1)
       li  t1, CGU_SMD
       li  a1, 0x200000
       sw  a1, 0(t1)      // Turn on DDR PAD Class II to INC drive.
       li  t1, PLL0_CFG
       li  a1, 0x00705f21
       sw  a1, 0(t1)

       li  t1, PLL1_CFG
       li  a1, 0x9b753215
       sw  a1, 0(t1)
#endif
#if defined(CONFIG_CLASS_II_DDR_PAD) 
       li  t1, CGU_SMD
       li  a1, 0x200000
       sw  a1, 0(t1)      // Turn on DDR PAD Class II to INC drive.
#endif


    li  t1, CGU_UPDATE
	li  t2, 0x1
	sw  t2, 0(t1)
	nop
#ifdef CONFIG_BOOT_FROM_NOR
    li  t1, RCU_RST_REQ
    li  t2, 0x40000008
	sw  t2,0(t1)
	b   wait_reset
    nop
wait_reset:
    b   wait_reset
    nop
#else
    j   cgu_init
    nop
#endif

freq_up2date:
    j ra
    nop
	.end	cgu_init

/*
 * void ddrram_init(long)
 *
 * a0 has the clock value
 */
	.globl	ddrram_init
	.ent	ddrram_init
ddrram_init:
	/* DDR-DRAM Initialization
	 */
	li	t1, MC_MODUL_BASE

	/* Clear Error log registers */
	sw	zero, MC_ERRCAUSE(t1)
	sw	zero, MC_ERRADDR(t1)

	/* Enable DDR module in memory controller */
	li	t3, MC_DDRRAM_ENABLE
	lw	t2, MC_CON(t1)
	or	t3, t2, t3
	sw	t3, MC_CON(t1)

	li	t1, MC_DDR_MODUL_BASE

    /* Write configuration to DDR controller registers */
	li	t2, MC_DC0_VALUE
	sw	t2, MC_DC00(t1)

	li	t2, MC_DC1_VALUE
	sw	t2, MC_DC01(t1)

	li	t2, MC_DC2_VALUE
	sw	t2, MC_DC02(t1)

	li	t2, MC_DC3_VALUE
	sw	t2, MC_DC03(t1)

	li	t2, MC_DC4_VALUE
	sw	t2, MC_DC04(t1)

	li	t2, MC_DC5_VALUE
	sw	t2, MC_DC05(t1)

	li	t2, MC_DC6_VALUE
	sw	t2, MC_DC06(t1)

	li	t2, MC_DC7_VALUE
	sw	t2, MC_DC07(t1)

	li	t2, MC_DC8_VALUE
	sw	t2, MC_DC08(t1)

	li	t2, MC_DC9_VALUE
	sw	t2, MC_DC09(t1)

	li	t2, MC_DC10_VALUE
	sw	t2, MC_DC10(t1)

	li	t2, MC_DC11_VALUE
	sw	t2, MC_DC11(t1)

	li	t2, MC_DC12_VALUE
	sw	t2, MC_DC12(t1)

	li	t2, MC_DC13_VALUE
	sw	t2, MC_DC13(t1)

	li	t2, MC_DC14_VALUE
	sw	t2, MC_DC14(t1)

	li	t2, MC_DC15_VALUE
	sw	t2, MC_DC15(t1)

	li	t2, MC_DC16_VALUE
	sw	t2, MC_DC16(t1)

	li	t2, MC_DC17_VALUE
	sw	t2, MC_DC17(t1)

	li	t2, MC_DC18_VALUE
	sw	t2, MC_DC18(t1)

	li	t2, MC_DC19_VALUE
	sw	t2, MC_DC19(t1)

	li	t2, MC_DC20_VALUE
	sw	t2, MC_DC20(t1)

	li	t2, MC_DC21_VALUE
	sw	t2, MC_DC21(t1)

	li	t2, MC_DC22_VALUE
	sw	t2, MC_DC22(t1)

	li	t2, MC_DC23_VALUE
	sw	t2, MC_DC23(t1)

	li	t2, MC_DC24_VALUE
	sw	t2, MC_DC24(t1)

	li	t2, MC_DC25_VALUE
	sw	t2, MC_DC25(t1)

	li	t2, MC_DC26_VALUE
	sw	t2, MC_DC26(t1)

	li	t2, MC_DC27_VALUE
	sw	t2, MC_DC27(t1)

	li	t2, MC_DC28_VALUE
	sw	t2, MC_DC28(t1)

	li	t2, MC_DC29_VALUE
	sw	t2, MC_DC29(t1)

	li	t2, MC_DC30_VALUE
	sw	t2, MC_DC30(t1)

	li	t2, MC_DC31_VALUE
	sw	t2, MC_DC31(t1)

	li	t2, MC_DC32_VALUE
	sw	t2, MC_DC32(t1)

	li	t2, MC_DC33_VALUE
	sw	t2, MC_DC33(t1)

	li	t2, MC_DC34_VALUE
	sw	t2, MC_DC34(t1)

	li	t2, MC_DC35_VALUE
	sw	t2, MC_DC35(t1)

	li	t2, MC_DC36_VALUE
	sw	t2, MC_DC36(t1)

	li	t2, MC_DC37_VALUE
	sw	t2, MC_DC37(t1)

	li	t2, MC_DC38_VALUE
	sw	t2, MC_DC38(t1)

	li	t2, MC_DC39_VALUE
	sw	t2, MC_DC39(t1)

	li	t2, MC_DC40_VALUE
	sw	t2, MC_DC40(t1)

	li	t2, MC_DC41_VALUE
	sw	t2, MC_DC41(t1)

	li	t2, MC_DC42_VALUE
	sw	t2, MC_DC42(t1)

	li	t2, MC_DC43_VALUE
	sw	t2, MC_DC43(t1)

	li	t2, MC_DC44_VALUE
	sw	t2, MC_DC44(t1)

	li	t2, MC_DC45_VALUE
	sw	t2, MC_DC45(t1)

	li	t2, MC_DC46_VALUE
	sw	t2, MC_DC46(t1)

#if defined(CONFIG_TUNE_DDR) && defined(CONFIG_BOOT_FROM_NOR)
	 li      t3, IFX_CFG_FLASH_DDR_CFG_START_ADDR
   lw      t4, 0(t3)
   li      t3, 0x88888888
   bne     t3, t4, ddr_not_configured
   nop
/*calculate the crc value*/
    li      t3, IFX_CFG_FLASH_DDR_CFG_START_ADDR
    addi    t3, t3, 0x4
    lw      t4, 0(t3)
    lw      t5, 4(t3)
    xor     t4, t4, t5
    lw      t5, 8(t3)
    xor     t4, t4, t5
    lw      t5, 0xc(t3)
    xor     t4, t4, t5
    lw      t5, 0x10(t3)
    bne     t4, t5, ddr_not_configured
    nop
    /*crc correct, load the stored value*/
	  li      t2, IFX_CFG_FLASH_DDR_CFG_START_ADDR
	  addi    t2, t2, 0x04
	  lw      t2, 0(t2)
	  sw      t2, MC_DC15(t1)

	  li      t2, IFX_CFG_FLASH_DDR_CFG_START_ADDR
	  addi    t2, t2, 0x08
	  lw      t2, 0(t2)
	  sw      t2, MC_DC21(t1)

	  li      t2, IFX_CFG_FLASH_DDR_CFG_START_ADDR
	  addi    t2, t2, 0x0c
	  lw      t2, 0(t2)
	  sw      t2, MC_DC22(t1)

	  li      t2, IFX_CFG_FLASH_DDR_CFG_START_ADDR
	  addi    t2, t2, 0x10
	  lw  	t2, 0(t2)
	  sw      t2, MC_DC24(t1)
    
    /*ddr use stored value, put 0 in 0xbe1a7f20*/
    li      t3, 0xBe1a7f20
	  li      t4, 0x0
    sw      t4, 0(t3)

	  b	2f
	  nop

ddr_not_configured:

	  li	t2, 0
	  sw	t2, MC_DC21(t1)

	  li	t2, 0
	  sw	t2, MC_DC22(t1)

    /*ddr not configured, put 0xff in 0xbe1a7f20*/
    li      t3, 0xBe1a7f20
    li      t4, 0xff
    sw      t4, 0(t3)

#endif

2:
  
	li	t2, 0x00000100
	sw	t2, MC_DC03(t1)

	li	t1, 0xbf800070 /*memory controller status register*/
	li	t3, 0x08       
1:
	lw	t2,0(t1)
	and	t2,t3
	bne     t2,t3,1b       /*check for DDR DLL LOCK*/
	nop
	j	ra
	nop

	.end	ddrram_init



	.globl	lowlevel_init
	.ent	lowlevel_init
lowlevel_init:
	/* EBU, CGU and SDRAM/DDR-RAM Initialization.
	 */
	move	t0, ra

#ifdef CONFIG_AR9 
  #ifdef CONFIG_USE_PLL0
     #ifdef CONFIG_CPU_111M_RAM_111M
	li  a0,0x85
     #elif defined(CONFIG_CPU_333M_RAM_111M)
        li  a0,0x81
     #elif defined(CONFIG_CPU_166M_RAM_166M)
        li  a0,0x84
     #elif defined(CONFIG_CPU_333M_RAM_166M)
        li  a0,0x80
     #elif defined(CONFIG_CPU_500M_RAM_166M)
        li  a0,0x89
     #elif defined(CONFIG_CPU_500M_RAM_250M)
        li  a0,0x88
     #endif
  #else /*USE_PLL1*/
     #ifdef CONFIG_CPU_442M_RAM_147M
   	li  a0,0x91
     #else
	li  a0,0x90
     #endif
  #endif

#else /*CONFIG_GR9*/
   #ifdef CONFIG_USE_PLL0
     #ifdef CONFIG_CPU_111M_RAM_111M
        li  a0,0x05
     #elif defined(CONFIG_CPU_333M_RAM_111M)
        li  a0,0x01
     #elif defined(CONFIG_CPU_166M_RAM_166M)
        li  a0,0x04
     #elif defined(CONFIG_CPU_333M_RAM_166M)
        li  a0,0x00
     #elif defined(CONFIG_CPU_500M_RAM_166M)
        li  a0,0x09
     #elif defined(CONFIG_CPU_500M_RAM_250M)
        li  a0,0x08
     #endif
   #else /*USE_PLL1*/
     #ifdef CONFIG_CPU_442M_RAM_147M
        li  a0,0x11
     #else
	li  a0,0x10
     #endif
   #endif
#endif

        bal cgu_init
        nop
#ifdef CONFIG_TUNE_DDR
        li      t1, 0xbf800060
        lw      t2, 0(t1)
        andi    t2, t2, 0x1
        bne     t2, zero, ddr_init_finish
        nop
#endif
1:

        bal ddrram_init
        nop
ddr_init_finish:

        move	ra, t0
	    j	ra
	    nop

	.end	lowlevel_init
