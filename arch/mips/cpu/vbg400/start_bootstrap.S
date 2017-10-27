/*
 *  Startup Code for MIPS32 CPU-core
 *
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <config.h>
#include <version.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/cacheops.h>
#include <asm/addrspace.h>
#include <configs/vbg400.h>

//turn off UBOOT_NO_MICRO if running uboot in ram (like using debugger)
#define UBOOT_NO_MICRO

# Select a Hazard Barrier

#ifdef LIGHT_WEIGHT_HB
#define HB nop
#else
#define HB ehb
#endif
#define CFG_BOOTSTRAP_CODE

#define RVECENT(f,n) \
   b f; nop
#define XVECENT(f,bev) \
   b f     ;           \
   li k0,bev

	.set noreorder
#	.set noat
	.set	mips32r2

	.globl _start
	.text
_start:

#loop_for_ever_start:
#bal loop_for_ever_start

	b conf_ddr

to_start:
	RVECENT(reset,0)	/* U-boot entry point */
	RVECENT(reset,1)	/* software reboot */
	RVECENT(romReserved,2)
	RVECENT(romReserved,3)
	RVECENT(romReserved,4)
	RVECENT(romReserved,5)
	RVECENT(romReserved,6)
	RVECENT(romReserved,7)
	RVECENT(romReserved,8)
	RVECENT(romReserved,9)
	RVECENT(romReserved,10)
	RVECENT(romReserved,11)
	RVECENT(romReserved,12)
	RVECENT(romReserved,13)
	RVECENT(romReserved,14)
	RVECENT(romReserved,15)
	RVECENT(romReserved,16)
	RVECENT(romReserved,17)
	RVECENT(romReserved,18)
	RVECENT(romReserved,19)
	RVECENT(romReserved,20)
	RVECENT(romReserved,21)
	RVECENT(romReserved,22)
	RVECENT(romReserved,23)
	RVECENT(romReserved,24)
	RVECENT(romReserved,25)
	RVECENT(romReserved,26)
	RVECENT(romReserved,27)
	RVECENT(romReserved,28)
	RVECENT(romReserved,29)
	RVECENT(romReserved,30)
	RVECENT(romReserved,31)
	RVECENT(romReserved,32)
	RVECENT(romReserved,33)
	RVECENT(romReserved,34)
	RVECENT(romReserved,35)
	RVECENT(romReserved,36)
	RVECENT(romReserved,37)
	RVECENT(romReserved,38)
	RVECENT(romReserved,39)
	RVECENT(romReserved,40)
	RVECENT(romReserved,41)
	RVECENT(romReserved,42)
	RVECENT(romReserved,43)
	RVECENT(romReserved,44)
	RVECENT(romReserved,45)
	RVECENT(romReserved,46)
	RVECENT(romReserved,47)
	RVECENT(romReserved,48)
	RVECENT(romReserved,49)
	RVECENT(romReserved,50)
	RVECENT(romReserved,51)
	RVECENT(romReserved,52)
	RVECENT(romReserved,53)
	RVECENT(romReserved,54)
	RVECENT(romReserved,55)
	RVECENT(romReserved,56)
	RVECENT(romReserved,57)
	RVECENT(romReserved,58)
	RVECENT(romReserved,59)
	RVECENT(romReserved,60)
	RVECENT(romReserved,61)
	RVECENT(romReserved,62)
	RVECENT(romReserved,63)
	XVECENT(romExcHandle,0x200)	/* bfc00200: R4000 tlbmiss vector */
	RVECENT(romReserved,65)
	RVECENT(romReserved,66)
	RVECENT(romReserved,67)
	RVECENT(romReserved,68)
	RVECENT(romReserved,69)
	RVECENT(romReserved,70)
	RVECENT(romReserved,71)
	RVECENT(romReserved,72)
	RVECENT(romReserved,73)
	RVECENT(romReserved,74)
	RVECENT(romReserved,75)
	RVECENT(romReserved,76)
	RVECENT(romReserved,77)
	RVECENT(romReserved,78)
	RVECENT(romReserved,79)
	XVECENT(romExcHandle,0x280)	/* bfc00280: R4000 xtlbmiss vector */
	RVECENT(romReserved,81)
	RVECENT(romReserved,82)
	RVECENT(romReserved,83)
	RVECENT(romReserved,84)
	RVECENT(romReserved,85)
	RVECENT(romReserved,86)
	RVECENT(romReserved,87)
	RVECENT(romReserved,88)
	RVECENT(romReserved,89)
	RVECENT(romReserved,90)
	RVECENT(romReserved,91)
	RVECENT(romReserved,92)
	RVECENT(romReserved,93)
	RVECENT(romReserved,94)
	RVECENT(romReserved,95)
	XVECENT(romExcHandle,0x300)	/* bfc00300: R4000 cache vector */
	RVECENT(romReserved,97)
	RVECENT(romReserved,98)
	RVECENT(romReserved,99)
	RVECENT(romReserved,100)
	RVECENT(romReserved,101)
	RVECENT(romReserved,102)
	RVECENT(romReserved,103)
	RVECENT(romReserved,104)
	RVECENT(romReserved,105)
	RVECENT(romReserved,106)
	RVECENT(romReserved,107)
	RVECENT(romReserved,108)
	RVECENT(romReserved,109)
	RVECENT(romReserved,110)
	RVECENT(romReserved,111)
	XVECENT(romExcHandle,0x380)	/* bfc00380: R4000 general vector */
	RVECENT(romReserved,113)
	RVECENT(romReserved,114)
	RVECENT(romReserved,115)
	RVECENT(romReserved,116)
	RVECENT(romReserved,116)
	RVECENT(romReserved,118)
	RVECENT(romReserved,119)
	RVECENT(romReserved,120)
	RVECENT(romReserved,121)
	RVECENT(romReserved,122)
	RVECENT(romReserved,123)
	RVECENT(romReserved,124)
	RVECENT(romReserved,125)
	RVECENT(romReserved,126)
	RVECENT(romReserved,127)

	/* We hope there are no more reserved vectors!
	 * 128 * 8 == 1024 == 0x400
	 * so this is address R_VEC+0x400 == 0xbfc00400
	 */
	.align 4

    b bypass_ddr

/***** set DDR ***********************************************************************/
conf_ddr:

/*nop*/
HB

#include "gen3_reg_depot.s"
#include "npu_memory_map.s"
#include "sys_if_map.s"

/*CONFIG_VBG400_CHIP setting is done via config mechanism*/
#ifdef CONFIG_VBG400_CHIPIT
	#include "denali_reg_defines_fpga.s"
#else
	#ifdef CONFIG_VBG400_DDR_8BIT
	#define k4t51163qj_e6_8	/*TODO: file not exist yet */
	#else
	#define k4t51163qj_f8
	/*#define k4t51163qj_e6*/
	#endif
	#include "denali_reg_defines.s"
#endif /*0*/

#loop_for_ever_ddr:
#bal loop_for_ever_ddr

#if 1
	/**** test if DDR configured already ********
    * first read gen3_shrd_clock_enable_reg to verify it is not in reset.
    * If it is confirmed {
    * 	read the ready bit
    *   if ready bit is ok
    * 	  ddr already configured, skip configuration and code copy from (flash to ram)
    *   else
    *     configure the ddr and copy code to ddr
    * }
    * else {
    *   enable access to clock enables and soft resets
    *   configure the ddr and copy code to ddr
    * }
	*/
    
    lui     $10, SHARED_REG_BASE_ADDR
	
	/*test if out of reset - can't access phy if in reset, exception result*/
    lw      $15, gen3_shrd_clock_enable_reg($10)
	#bne     $15,0x0000000f,conf_ddr_now

    li      $16, 0x0000000f
    and     $15, $16, $15
	bne     $15,0x0000000f,conf_ddr_now
HB
/*	nop
	nop
*/
    lui     $10, DDR_CSR_BASE_ADDR

    /* test that PHY has initialized- if not, never configured or error in configuration
       test bit 20 (init complete) of reg 44 */
    lw      $15, 0x70($10)
    li      $16, 0x00100000
    and     $15, $16, $15
	beq     $15,$0,conf_ddr_now
HB
/*	nop
	nop
*/
    #ddr ready

	b bypass_ddr
HB
/*	nop*/
	/**** end of ddr test ********/
#endif

conf_ddr_now:
nop

#loop_for_ever_efuse:
#nop
#bal loop_for_ever_efuse

#ifdef WAVE400_READ_EFUSE
/* eFuse handling done in assembly as well as in c code.
Assembly code is tested. C code rewrite the assembly in order to have simpler and clear code.
use compilation switch to select.
*/
#ifdef WAVE400_USE_ASSEMBLY_EFUSE
    #include "red_fix_loading_and_rm_loading.s"
#else
	/* Initialize $gp before it is used in jump
	 */
	bal	1f
HB
/*	nop*/
	.word	_gp
1:
	lw	gp, 0(ra)
	nop
.set noat
    la      ra, return_from_efuse
    nop
    b       read_efuse
HB
/*	nop*/
return_from_efuse:
.set at
#endif /*WAVE400_USE_ASSEMBLY_EFUSE*/
#endif /*WAVE400_READ_EFUSE*/

#ifndef CONFIG_VBG400_CHIPIT
	/*start_clock.s configs the pll, need to define mips24k (TODO: or change file !)*/
	#define mips24k
.set reorder
	#include "start_clock.s"
.set noreorder
#endif

	.equ axi0_priority0_relative ,8
	.equ axi0_priority1_relative ,16
	.equ axi0_priority2_relative ,24
   .equ axi0_priority3_relative ,0
	.equ axi0_priority4_relative ,8
	.equ axi0_priority5_relative ,16
	.equ axi0_priority6_relative ,24
	.equ axi0_priority7_relative ,0


	.equ axi1_priority0_relative ,0
	.equ axi1_priority1_relative ,8
	.equ axi1_priority2_relative ,16
   .equ axi1_priority3_relative ,24
	.equ axi1_priority4_relative ,0
	.equ axi1_priority5_relative ,8
	.equ axi1_priority6_relative ,16
	.equ axi1_priority7_relative ,24

	.equ axi2_priority0_relative ,24
	.equ axi2_priority1_relative ,0
	.equ axi2_priority2_relative ,8
   .equ axi2_priority3_relative ,16
	.equ axi2_priority4_relative ,24
	.equ axi2_priority5_relative ,0
	.equ axi2_priority6_relative ,8
	.equ axi2_priority7_relative ,16

	.equ axi3_priority0_relative ,16
	.equ axi3_priority1_relative ,24
	.equ axi3_priority2_relative ,0
   .equ axi3_priority3_relative ,8
	.equ axi3_priority4_relative ,16
	.equ axi3_priority5_relative ,24
	.equ axi3_priority6_relative ,0
	.equ axi3_priority7_relative ,8

	.equ axi4_priority0_relative ,16
	.equ axi4_priority1_relative ,24
	.equ axi4_priority2_relative ,0
   .equ axi4_priority3_relative ,8
	.equ axi4_priority4_relative ,16
	.equ axi4_priority5_relative ,24
	.equ axi4_priority6_relative ,0
	.equ axi4_priority7_relative ,8

	.equ axi5_priority0_relative ,16
	.equ axi5_priority1_relative ,24
	.equ axi5_priority2_relative ,0
   .equ axi5_priority3_relative ,8
	.equ axi5_priority4_relative ,16
	.equ axi5_priority5_relative ,24
	.equ axi5_priority6_relative ,0
	.equ axi5_priority7_relative ,8


	.equ age_count ,0
	.equ command_age_count ,8
     // bb priority to ddr 
	.equ axi2_r_priority,24
	.equ axi2_w_priority,0
     // npu  priority to ddr 
	.equ axi5_r_priority,24
	.equ axi5_w_priority,0

#/* Configure clocks */

        lui     $10, SHARED_REG_BASE_ADDR

#        /* Enable access to clock enables and soft resets. */
        li      $15, 0x0003
        sw      $15, gen3_shrd_safety_reg($10)
                
#        /* Next enable all of the disabled clock networks */
        lui     $15, 0x0000
        ori     $15, 0x00ff 
        sw      $15, gen3_shrd_clock_enable_reg($10)

#        /* Set the GMAC interface mode before taking it out of reset. */
#        /* Set the top level basic mode configuration register */
        lw      $15, gen3_shrd_basic_mode_config_reg($10)
        lui     $16,0xffff
        ori     $16,0xfffe
        and     $15,$15,$16
        sw      $15, gen3_shrd_basic_mode_config_reg($10)
 
#        /* Now take all of the blocks out of reset  */
        lui     $15, 0x0001
        ori     $15, 0xffff
        sw      $15, gen3_shrd_soft_reset_reg($10)

#        /* Disable access to clock enables and soft resets. */
        lui     $15, 0x0000
        sw      $15, gen3_shrd_safety_reg($10)
#/* Configure DDR */
        lui     $10, DDR_CSR_BASE_ADDR

        li      $15, DENALI_CTL_00_DATA
        sw      $15, 0x0000($10)

        li      $15, DENALI_CTL_01_DATA
        sw      $15, 0x0004($10)

        li      $15, DENALI_CTL_02_DATA
        sw      $15, 0x0008($10)

        li      $15, DENALI_CTL_03_DATA
        sw      $15, 0x000c($10)

        li      $15, DENALI_CTL_04_DATA
        sw      $15, 0x0010($10)

        li      $15, DENALI_CTL_05_DATA
        sw      $15, 0x0014($10)

        li      $15, DENALI_CTL_06_DATA
        sw      $15, 0x0018($10)

        li      $15, DENALI_CTL_07_DATA
        sw      $15, 0x001c($10)

        li      $15, DENALI_CTL_08_DATA
        sw      $15, 0x0020($10)

        li      $15, DENALI_CTL_09_DATA
        sw      $15, 0x0024($10)

        li      $15, DENALI_CTL_10_DATA
        sw      $15, 0x0028($10)

        li      $15, DENALI_CTL_11_DATA
        sw      $15, 0x002c($10)

        li      $15, DENALI_CTL_12_DATA
        sw      $15, 0x0030($10)

        li      $15, DENALI_CTL_13_DATA
        sw      $15, 0x0034($10)

        li      $15, DENALI_CTL_14_DATA
        sw      $15, 0x0038($10)

        li      $15, DENALI_CTL_15_DATA
        sw      $15, 0x003c($10)

        li      $15, DENALI_CTL_16_DATA
        sw      $15, 0x0040($10)

        li      $15, DENALI_CTL_17_DATA
        sw      $15, 0x0044($10)

        li      $15, DENALI_CTL_18_DATA
        sw      $15, 0x0048($10)

        li      $15, DENALI_CTL_19_DATA
        sw      $15, 0x004c($10)

        li      $15, DENALI_CTL_20_DATA
        sw      $15, 0x0050($10)

        li      $15, DENALI_CTL_21_DATA
        sw      $15, 0x0054($10)

        li      $15, DENALI_CTL_22_DATA
        sw      $15, 0x0058($10)

        li      $15, DENALI_CTL_23_DATA
        sw      $15, 0x005c($10)

        li      $15, DENALI_CTL_24_DATA
        sw      $15, 0x0060($10)
   // a*a=100 clk is max wait before command priority goes higher 
        li      $15, (DENALI_CTL_25_DATA & ~(0x1f<<age_count) & ~(0x1f<<command_age_count) )  | 0xa<< age_count  | 0xa<< command_age_count
        sw      $15, 0x0064($10)

        li      $15, DENALI_CTL_26_DATA
        sw      $15, 0x0068($10)

        li      $15, DENALI_CTL_27_DATA
        sw      $15, 0x006c($10)

        li      $15, DENALI_CTL_28_DATA
        sw      $15, 0x0070($10)

        li      $15, DENALI_CTL_29_DATA
        sw      $15, 0x0074($10)

        li      $15, DENALI_CTL_30_DATA
        sw      $15, 0x0078($10)

        li      $15, DENALI_CTL_31_DATA
        sw      $15, 0x007c($10)

        li      $15, DENALI_CTL_32_DATA
        sw      $15, 0x0080($10)

        li      $15, DENALI_CTL_33_DATA
        sw      $15, 0x0084($10)

        li      $15, DENALI_CTL_34_DATA
        sw      $15, 0x0088($10)

        li      $15, DENALI_CTL_35_DATA
        sw      $15, 0x008c($10)

        li      $15, DENALI_CTL_36_DATA
        sw      $15, 0x0090($10)

        li      $15, DENALI_CTL_37_DATA
        sw      $15, 0x0094($10)

        li      $15, DENALI_CTL_38_DATA
        sw      $15, 0x0098($10)

        li      $15, DENALI_CTL_39_DATA
        sw      $15, 0x009c($10)

        li      $15, DENALI_CTL_40_DATA
        sw      $15, 0x00a0($10)

        li      $15, (DENALI_CTL_41_DATA & ~(0x7<<axi2_r_priority)) | 2<<axi2_r_priority
        sw      $15, 0x00a4($10)

        li      $15, (DENALI_CTL_42_DATA & ~(0x7<<axi2_w_priority)) | 2<<axi2_w_priority 
        sw      $15, 0x00a8($10)

        li      $15, DENALI_CTL_43_DATA
        sw      $15, 0x00ac($10)

        li      $15, DENALI_CTL_44_DATA
        sw      $15, 0x00b0($10)

        li      $15, (DENALI_CTL_45_DATA & ~(0x7<<axi5_r_priority)) | 2<<axi5_r_priority
        sw      $15, 0x00b4($10)

        li      $15, (DENALI_CTL_46_DATA & ~(0x7<<axi2_w_priority)) | 2<<axi2_w_priority 
        sw      $15, 0x00b8($10)

	
        li      $15, (DENALI_CTL_47_DATA  & ~(0xf<<axi0_priority0_relative) & ~(0xf<<axi0_priority1_relative) & ~(0xf<<axi0_priority2_relative))  | 2<< axi0_priority0_relative  | 1<< axi0_priority1_relative  | 1<<axi0_priority2_relative 
        sw      $15, 0x00bc($10)

        li      $15, (DENALI_CTL_48_DATA  & ~(0xf<<axi0_priority3_relative) & ~(0xf<<axi0_priority4_relative) & ~(0xf<<axi0_priority5_relative)& ~(0xf<<axi0_priority6_relative))  | 1<< axi0_priority3_relative  | 1<< axi0_priority4_relative  | 1<<axi0_priority5_relative | 1<<axi0_priority6_relative 
 
        sw      $15, 0x00c0($10)

        li      $15, (DENALI_CTL_49_DATA  & ~(0xf<<axi0_priority7_relative)) | 1<< axi0_priority7_relative 
        sw      $15, 0x00c4($10)

        li      $15, (DENALI_CTL_50_DATA  & ~(0xf<<axi1_priority0_relative) & ~(0xf<<axi1_priority1_relative) & ~(0xf<<axi1_priority2_relative)& ~(0xf<<axi1_priority3_relative))  | 3<< axi1_priority0_relative  | 1<< axi1_priority1_relative  | 1<<axi1_priority2_relative | 1<<axi1_priority3_relative 

        sw      $15, 0x00c8($10)

        li      $15, (DENALI_CTL_51_DATA  & ~(0xf<<axi1_priority4_relative) & ~(0xf<<axi1_priority5_relative) & ~(0xf<<axi1_priority6_relative)& ~(0xf<<axi1_priority7_relative))  | 1<< axi1_priority4_relative  | 1<< axi1_priority5_relative  | 1<<axi1_priority6_relative | 1<<axi1_priority7_relative  
        sw      $15, 0x00cc($10)

        li      $15, (DENALI_CTL_52_DATA  & ~(0xf<<axi2_priority0_relative)) | 4<< axi2_priority0_relative 
        sw      $15, 0x00d0($10)

        li      $15, (DENALI_CTL_53_DATA  & ~(0xf<<axi2_priority1_relative) & ~(0xf<<axi2_priority2_relative) & ~(0xf<<axi2_priority3_relative)& ~(0xf<<axi2_priority4_relative))  | 1<< axi2_priority1_relative  | 1<< axi2_priority2_relative  | 1<<axi2_priority3_relative | 1<<axi2_priority4_relative
        sw      $15, 0x00d4($10)

        li      $15, (DENALI_CTL_54_DATA  & ~(0xf<<axi2_priority5_relative) & ~(0xf<<axi2_priority6_relative) & ~(0xf<<axi2_priority7_relative))  | 1<< axi2_priority5_relative  | 1<< axi2_priority6_relative  | 1<<axi2_priority7_relative 
        sw      $15, 0x00d8($10)

        li      $15, (DENALI_CTL_55_DATA  & ~(0xf<<axi3_priority0_relative) & ~(0xf<<axi3_priority1_relative) )  | 2<< axi3_priority0_relative  | 1<< axi3_priority1_relative  
        sw      $15, 0x00dc($10)

        li      $15, (DENALI_CTL_56_DATA  & ~(0xf<<axi3_priority2_relative) & ~(0xf<<axi3_priority3_relative) & ~(0xf<<axi3_priority4_relative)& ~(0xf<<axi3_priority5_relative))  | 1<< axi3_priority2_relative  | 1<< axi3_priority3_relative  | 1<<axi3_priority4_relative | 1<<axi3_priority5_relative  
        sw      $15, 0x00e0($10)

        li      $15, (DENALI_CTL_57_DATA   & ~(0xf<<axi3_priority6_relative) & ~(0xf<<axi3_priority7_relative) )  | 1<< axi3_priority6_relative  | 1<< axi3_priority7_relative  
        sw      $15, 0x00e4($10)

        li      $15, (DENALI_CTL_58_DATA   & ~(0xf<<axi4_priority0_relative) & ~(0xf<<axi4_priority1_relative) )  | 3<< axi4_priority0_relative  | 1<< axi4_priority1_relative  
        sw      $15, 0x00e8($10)

        li      $15, (DENALI_CTL_59_DATA   & ~(0xf<<axi4_priority2_relative) & ~(0xf<<axi4_priority3_relative) & ~(0xf<<axi4_priority4_relative)& ~(0xf<<axi4_priority5_relative))  | 1<< axi4_priority2_relative  | 1<< axi4_priority3_relative  | 1<<axi4_priority4_relative | 1<<axi4_priority5_relative 
        sw      $15, 0x00ec($10)

        li      $15, (DENALI_CTL_60_DATA   & ~(0xf<<axi4_priority6_relative) & ~(0xf<<axi4_priority7_relative) )  | 1<< axi4_priority6_relative  | 1<< axi4_priority7_relative   
        sw      $15, 0x000f0($10)

        li      $15, (DENALI_CTL_61_DATA   & ~(0xf<<axi5_priority0_relative) & ~(0xf<<axi5_priority1_relative) )  | 4<< axi5_priority0_relative  | 1<< axi5_priority1_relative   
        sw      $15, 0x000f4($10)

        li      $15, (DENALI_CTL_62_DATA   & ~(0xf<<axi5_priority2_relative) & ~(0xf<<axi5_priority3_relative) & ~(0xf<<axi5_priority4_relative)& ~(0xf<<axi5_priority5_relative))  | 1<< axi5_priority2_relative  | 1<< axi5_priority3_relative  | 1<<axi5_priority4_relative | 1<<axi5_priority5_relative  
        sw      $15, 0x00f8($10)

        li      $15, (DENALI_CTL_63_DATA   & ~(0xf<<axi5_priority6_relative) & ~(0xf<<axi5_priority7_relative) )  | 1<< axi5_priority6_relative  | 1<< axi5_priority7_relative
        sw      $15, 0x00fc($10)

        li      $15, DENALI_CTL_64_DATA
        sw      $15, 0x0100($10)

        li      $15, DENALI_CTL_65_DATA
        sw      $15, 0x0104($10)

        li      $15, DENALI_CTL_66_DATA
        sw      $15, 0x0108($10)

        li      $15, DENALI_CTL_67_DATA
        sw      $15, 0x010c($10)

        li      $15, DENALI_CTL_68_DATA
        sw      $15, 0x0110($10)

        li      $15, DENALI_CTL_69_DATA
        sw      $15, 0x0114($10)

        li      $15, DENALI_CTL_70_DATA
        sw      $15, 0x0118($10)

        li      $15, DENALI_CTL_71_DATA
        sw      $15, 0x011c($10)

        li      $15, DENALI_CTL_72_DATA
        sw      $15, 0x0120($10)

        li      $15, DENALI_CTL_73_DATA
        sw      $15, 0x0124($10)


	
#ifdef CONFIG_VBG400_CHIPIT
	li      $15, DENALI_PHY_00_DATA
#else
	li      $15, DENALI_PHY_00_DATA | 3<<13
#endif
        sw      $15, 0x0200($10)

        li      $15, DENALI_PHY_01_DATA
        sw      $15, 0x0204($10)

	li      $15, DENALI_PHY_02_DATA
        sw      $15, 0x0208($10)

	li      $15, DENALI_PHY_03_DATA
        sw      $15, 0x020c($10)


	li      $15, DENALI_PHY_04_DATA
        sw      $15, 0x0210($10)

        li      $15, DENALI_PHY_05_DATA
        sw      $15, 0x0214($10)

	li      $15, DENALI_PHY_06_DATA
        sw      $15, 0x0218($10)

	li      $15, DENALI_PHY_07_DATA
        sw      $15, 0x021c($10)

	li      $15, DENALI_PHY_08_DATA
        sw      $15, 0x0220($10)

        li      $15, DENALI_PHY_09_DATA
        sw      $15, 0x0224($10)

 #  /* set the start bit of the DDR controller */
        /*  addressing reg 00 */
        lw      $15, 0x0000($10)
        li     $16, 0x0001
        or      $15,$15,$16
        sw      $15, 0x0000($10)
	  
  #  /* wait until PHY has initialized */
        /* test bit 20 (init complete) of reg 28 */
wait_ddr_rdy:
        lw      $15, 0x70($10)
        li      $16, 0x00100000
        and     $15, $16, $15
	    beq     $15,$0,wait_ddr_rdy
HB
/*	nop*/

        #ddr ready, continue

#loop_for_ever_ddr_ready:
#nop
#nop
#bal loop_for_ever_ddr_ready


		/*copy to DDR */
        /* Source address in FLASH:    offset 0x00000000, actually 0xBFC00000 */
        li     t0, CFG_FLASH_BASE_HW
        /*Destination address in DDR: offset 0x00100000 */
        li     t1, CONFIG_BOOTSTRAP_TEXT_BASE  
        /* max size of u-boot, feet to 1 sector in flash. can be modify to real size */
        li     a2, 0x10000
        or     a2, a2, CONFIG_BOOTSTRAP_TEXT_BASE #stop condition (TEXT_BASE)

1:
        lw	t3, 0(t0)
#ifdef VALIDATE_DDR
		/*calc checksum*/
        xor     t4,t4,t3
#endif
        sw	t3, 0(t1)
        addu	t0, 4
        bne	t1, a2, 1b
        addu	t1, 4        /* delay slot			*/
        /*end copy */

#ifdef VALIDATE_DDR
        /* calc ddr checksum */
        li      t1,CONFIG_BOOTSTRAP_TEXT_BASE   #point to start of code in DDR
checksum:
		lw      t3,0x0000(t1)   #load word
        xor     t5,t5,t3        #calc ckecksum
        addi    t1,+4
        bne     a2,t1,checksum  #more code?
HB
/*	nop*/
        /* if checksum error, loop forever (or print to uart) */
checksum_err:
        bne     t4,t5,checksum_err
nop
#endif

        /* Jump to where we've relocated ourselves.
         */
        li     t0, CONFIG_BOOTSTRAP_TEXT_BASE
        addi	t0, t0, to_start - _start #_start=go to conf ddr, to_start=after conf ddr, t0 points to 'reset:'
		and     t0, t0, 0xFFFFFFFC
        j	t0
HB
/*	nop*/


/**** End set DDR *******************************************************************/
bypass_ddr:

#loop_for_ever_reset:
#bal loop_for_ever_reset

reset:
	        /*# Initialize the register file*/
        or      $1,$0, $0
        or      $2,$0, $0
        or      $3,$0, $0
        or      $4,$0, $0
        or      $5,$0, $0
        or      $6,$0, $0
        or      $7,$0, $0
        or      $8,$0, $0
        or      $9,$0, $0
        or      $10,$0, $0
        or      $11,$0, $0
        or      $12,$0, $0
        or      $13,$0, $0
        or      $14,$0, $0
        or      $15,$0, $0
        or      $16,$0, $0
        or      $17,$0, $0
        or      $18,$0, $0
        or      $19,$0, $0
        or      $20,$0, $0
        or      $21,$0, $0
        or      $22,$0, $0
        or      $23,$0, $0
        or      $24,$0, $0
        or      $25,$0, $0
        or      $26,$0, $0
        or      $27,$0, $0
        or      $28,$0, $0
        or      $31,$0, $0
        or      $30,$0, $0

        /*#now set 0 to all shadow file GPRs*/
        /* TO DO */

        /*# Clear interrupts mask bits*/
        mfc0    $10, CP0_STATUS        
        li      $11, 0xffff00fe /*clear IE and IM7-0 bits*/
        and     $10, $11        
        mtc0    $10, CP0_STATUS        

	    /* CAUSE register */
	    mtc0	zero, CP0_CAUSE

        # Check the presence of additional Watch registers 
	li	$11, 0x7		# (M_WatchHiI | M_WatchHiR | M_WatchHiW)
	mtc0	$11, $19		# C0_WatchHi
        ehb
	mfc0	$11, $19		# C0_WatchHi
        srl     $11, $11, 31
        beq     $11, $0, 1f 

	li	$11, 0x7		

	# Disable watch exceptions
	mtc0	$0, $18, 1		# C0_WatchLo1
	mtc0	$0, $18, 2		# C0_WatchLo2
	mtc0	$0, $18, 3		# C0_WatchLo3

	# Clear Watch Status bits
	mtc0	$11, $19, 1		# C0_WatchHi1
	mtc0	$11, $19, 2		# C0_WatchHi2
	mtc0	$11, $19, 3		# C0_WatchHi3

1:      # There is only one set of Watch register pair
	# Disable watch exceptions
	mtc0	$0, $18			# C0_WatchLo

	# Clear Watch Status bits
	mtc0	$11, $19		# C0_WatchHi

	# Clear WP bit to avoid watch exception upon user code entry
	# Clear IV bit - Interrupts go to general exception vector
	# Clear software interrupts
	mtc0	$0, $13			# C0_Cause

	# Set KSeg0 to cacheable
    # Config.K0
    mfc0    $10, $16
    li      $11, 0x7
    not     $11
    and     $10, $11
    or      $10, 0x3
    mtc0    $10, $16

    /*# Clear Count register*/
    mtc0    $0, $9

    /*# Set compare to -1 to delay 1st count=compare
    # Also, clears timer interrupt*/
    li      $10, -1
    mtc0    $10, $11

    mtc0    $0,$28

    lui     $3,0x0000
    ori     $4,$0,0x0010
    ori     $5,$0,0x4000
    ori     $6,$0,0x2000

    /*

 ************************************************************************
 *         C O N F I G 1   R E G I S T E R   ( 1 6, SELECT 1 )          *
 ************************************************************************
 *
 *  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |M|  MMU Size |  IS |  IL |  IA |  DS |  DL |  DA |Rsvd |W|C|E|F| Config1
 * | |           |     |     |     |     |     |     |     |R|A|P|P|
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */

	mfc0    $10, $16, 1             # .word 0x400a8001

        # Isolate I$ Line Size
        sll     $11, $10, 10
        srl     $11, 29

        # Skip ahead if No I$
        beq     $11, $0, 10f
/*        nop*/
HB

        li      $14, 2
        sllv    $11, $14, $11           # Now have true I$ line size in bytes

        sll     $12, $10, 7
        srl     $12, 29
        li      $14, 64
        sllv    $12, $14, $12           # I$ Sets per way

        sll     $13, $10, 13
        srl     $13, 29                 # I$ Assoc (-1)
        add     $13, 1
        mul     $12, $12, $13           # Total number of sets

        lui     $14, 0x8000             # Get a KSeg0 address for cacheops

        # Clear TagLo/TagHi registers
        mtc0    $0, $28
        mtc0    $0, $29
        mtc0    $0, $28, 2
        mtc0    $0, $29, 2

        move    $15, $12

        # Index Store Tag Cache Op
        # Will invalidate the tag entry, clear the lock bit, and clear the LRF bit
1:      cache   0x8, 0($14)
        add     $15, -1                 # Decrement set counter

        bne     $15, $0, 1b
        add     $14, $11                # Get next line address

nop
#loop_for_ever_cache_end:
#bal loop_for_ever_cache_end

        # Now go through and invalidate the D$
        # Now that the I$ has been flushed, the rest of the code can be
        # moved to kseg0 and run from the cache to go faster
10:

	# Isolate D$ Line Size
        sll     $11, $10, 19
        srl     $11, 29

        # Skip ahead if No D$
        beq     $11, $0, 10f
        nop

        li      $14, 2
        sllv    $11, $14, $11           # Now have true D$ line size in bytes

        sll     $12, $10, 16
        srl     $12, 29
        li      $14, 64
        sllv    $12, $14, $12           # D$ Sets per way

        sll     $13, $10, 22
        srl     $13, 29                 # D$ Assoc (-1)
        add     $13, 1

        mul     $12, $12, $13           # Get total number of sets

        lui     $14, 0x8000             # Get a KSeg0 address for cacheops

        # Clear TagLo/TagHi registers
        mtc0    $0, $28
        mtc0    $0, $29

        move    $15, $12

        # Index Store Tag Cache Op
        # Will invalidate the tag entry, clear the lock bit, and clear the LRF bit
1:      cache   0x9, 0($14)
        add     $15, -1                 # Decrement set counter

        bne     $15, $0, 1b
        add     $14, $11                # Get next line address

nop
#loop_for_ever_cache_end_2:
#bal loop_for_ever_cache_end_2

        # Now both caches have been flushed
        # Initialize the TLB

10:
#if defined(VBG400_DO_TLB)
	# Determine if we have a TLB
        mfc0    $11, $16

        sll     $11, 22
        srl     $11, 29

        li      $15, 0x1        # MT = 1  => TLB

        bne     $11, $15, 15f
        nop

        mfc0    $10, $16, 1                     # .word 0x400a8001

        sll     $11, $10, 1
        srl     $11, 26         # Number of TLB entries (-1)

        mtc0    $0, $2          # EntryLo0
        mtc0    $0, $3          # EntryLo1
        mtc0    $0, $5          # PageMask
        mtc0    $0, $6          # Wired

        li      $12, 0x80000000

1:
        mtc0    $11, $0         # Index register
        mtc0    $12, $10        # EntryHi
        ssnop                   #.word 0x00000040
        ssnop                   #.word 0x00000040

#debug trap - open remarks to stop code:
#loop_for_ever:
#bal loop_for_ever

        TLBWI
        add     $12, (2<<13)    # Add 8K to the address to avoid TLB conflict with previous entry

        bne     $11, $0, 1b
        add     $11, -1

15:
#endif
	# Initialize other register files
        # Good code should obviously not read registers before they are written
        # so this is not not normally needed. But in simulation certain ways of initializing
        # registers may not work (xor rN, rN, rN for one)

        # check for the presence of shadow register sets
        # first verify core is release 2 or higher
        mfc0    $11, $16
        sll     $11, 19
        srl     $11, 29
        beqz    $11, return
/*        nop*/
HB

#define CPUNUM	$3
#if 1
#ifndef DO_NOT_CHECK_FOR_CMP

#define GCMP	$8

	# Determine if there is a coherency manager present.
	# This address is the default configuration address.  If your
	# system was configured with a different address, you must
	# change this value.
	li	GCMP, 0xbfbf8000	# KSEG1(GCMPBASE)
	lw	$9, 0x0008(GCMP)	# GCR_BASE

	addiu	$10, $0, 0x8000		# li r10, M_GCR_BASE_GCR_BASE (~0x7fff)
	and	$9, $10

	lui	$10, 0xa000		# KSEG1BASE
	or	$10, $9

	# This code uses $3 as the CPU number to make descisions about
	# whether to execute code or not.  For CMP systems, we use the
	# real CPU number.  For non-CMP, pretend the CPU number is zero
	# to force the correct behavior.

	bne	$10, GCMP, nogcmp
	move	CPUNUM, $0

	# Change the CCA from non-coherent to coherent
	# Assumption: GCMP => coherent CCA is usable
	mfc0	$10, $16		# C0_Config

	ext	$11, $10, 0, 3		# S_ConfigK0, W_ConfigK0
	xori	$11, 3			# K_CacheAttrCN

	bnez	$11, 1f
	HB

	li	$11, 5			# K_CacheAttrCCS
	ins	$10, $11, 0, 3		# S_ConfigK0, W_ConfigK0

	mtc0	$10, $16		# C0_Config
1:
	# Check the CPU number
	mfc0	CPUNUM, $15, 1		# C0_EBase
	ext	CPUNUM, CPUNUM, 0, 10	# S_EBaseCPUNum, W_EBaseCPUNum

	# Only the Primary Core needs to initialise the Coherence Manager.
	bnez	CPUNUM, 1f
	HB

	# Initialise CM
	#
	# Rewrite the GCR_BASE register to initialise CM_DEFAULT_TARGET
	ins	$9, $0, 0, 2		# M_GCR_BASE_CM_DEFAULT_TARGET, S_GCR_BASE_CM_DEFAULT_TARGET
	sw	$9, 0x0008(GCMP)	# GCR_BASE

	# Disable the CM regions
	lui	$9, 0xffff
	sw	$9, 0x0090(GCMP)	# GCR_REG0_BASE
	sw	$9, 0x0098(GCMP)	# GCR_REG0_MASK
	sw	$9, 0x00a0(GCMP)	# GCR_REG1_BASE
	sw	$9, 0x00a8(GCMP)	# GCR_REG1_MASK
	sw	$9, 0x00b0(GCMP)	# GCR_REG2_BASE
	sw	$9, 0x00b8(GCMP)	# GCR_REG2_MASK
	sw	$9, 0x00c0(GCMP)	# GCR_REG3_BASE
	sw	$9, 0x00c8(GCMP)	# GCR_REG3_MASK

1:
	# Allow interventions from all other cores (including self)
	# For CPU 1 and higher, NOP if access not enabled in GCR_ACCESS.
	li	$9, 0xff
	sw	$9, 0x2008(GCMP)	# GCR_CL_COHERENCE
	ehb

#undef GCMP
#endif	/* DO_NOT_CHECK_FOR_CMP */
#endif	/* 0 */

nogcmp:

 	/* Clear watch registers.
	 */
	mtc0	zero, CP0_WATCHLO   #done in watch handling above
	mtc0	zero, CP0_WATCHHI

/*#define VBG400_USE_RPS_E83_PATCH*/
#define VBG400_ADD_UNCACHED_HERE

	/* CONFIG7 register */
	mfc0	k0, CP0_CONFIG, 7
#ifdef VBG400_USE_RPS_E83_PATCH
	li	k1, 4 /* Disable RPS due to E83 bug of 24KEC */
	or	k0, k1
#endif
#ifdef VBG400_ADD_UNCACHED_HERE
    li	k1, CONF_CM_UNCACHED
    or	k0, k1
#endif
	mtc0	k0, CP0_CONFIG, 7
	/* Init Timer */
	mtc0	zero, CP0_COUNT
	mtc0	zero, CP0_COMPARE

#ifndef VBG400_ADD_UNCACHED_HERE
	li	t0, CONF_CM_UNCACHED
	mtc0	t0, CP0_CONFIG
#endif

#if 1
#ifndef DO_NOT_CHECK_FOR_MT

	# Config1 is required for MIPS32
	mfc0	$8, $16, 1		# C0_Config1
	bgez	$8, notmtcapable	# No Config2 register
	HB

	mfc0	$8, $16, 2		# C0_Config2
	bgez	$8, notmtcapable	# No Config3 register
	HB

	mfc0	$8, $16, 3		# C0_Config3
	and	$8, (1 << 2)		# M_Config3MT
	beqz	$8, notmtcapable
	HB

	# This core supports MT ASE
	#
	# Start up secondary VPE's
	.set	push
	.set	mt

startmtconfig:
	# This is TC0 bound to VPE0.  Therefore VPEConf0.MVP is set.

	# Enter config mode
	mfc0	$8, $0, 1		# C0_MVPCtl
	or	$8, (1 << 1)		# M_MVPCtlVPC
	mtc0	$8, $0, 1		# C0_MVPCtl
	ehb

#define NTCS	$10
#define NVPES	$11
#define TC	$12

	# Get number of TC's and VPE's
	mfc0	$8, $0, 2		# C0_MVPConf0
	ext	NTCS, $8, 0, 8		# S_MVPConf0PTC, W_MVPConf0PTC
	ext	NVPES, $8, 10, 4	# S_MVPConf0PVPE, W_MVPConf0PVPE

	# Initialise TC's/VPE's
	move	TC, $0
nexttc:
	# Select TCn
	mfc0	$8, $1, 1		# C0_VPECtl
	ins	$8, TC, 0, 8		# S_VPECtlTargTC, W_VPECtlTargTC
	mtc0	$8, $1, 1		# C0_VPECtl
	ehb

	# Bind TC to next VPE
	beqz	TC, nextvpe		# Don't rebind TC0
	HB

	# Halt all TC's other than TC0
	li	$8, 1			# M_TCHaltH
	mttc0	$8, $2, 4		# C0_TCHalt
	ehb

	slt	$9, NVPES, TC
	bnez	$9, 2f			# Bind spare TC's to VPElast
	move	$9, NVPES

	# Set XTC for active TC's
	mftc0	$8, $1, 2		# C0_VPEConf0
	ins	$8, TC, 21, 8		# S_VPEConf0XTC, W_VPEConf0XTC
	mttc0	$8, $1, 2		# C0_VPEConf0

	move	$9, TC
2:
	# Bind TC to a VPE
	mftc0	$8, $2, 2		# C0_TCBind
	ins	$8, $9, 0, 4		# S_TCBindCurVPE, W_TCBindCurVPE
	mttc0	$8, $2, 2		# C0_TCBind

	# Set up TCStatus register:
	# Disable Coprocessor Usable bits
	# Disable MDMX/DSP ASE
	# Clear Dirty TC
	# not dynamically allocatable
	# not allocated
	# Kernel mode
	# interrupt exempt
	# ASID 0
	li	$8, (1 << 10)		# M_TCStatusIXMT
	mttc0	$8, $2, 1		# C0_TCStatus

#ifndef DO_NOT_INIT_GPRS

	# Initialize the TC's register file
	# should not be required with good software practices
	mttgpr	$0, $1
	mttgpr	$0, $2
	mttgpr	$0, $3
	mttgpr	$0, $4
	mttgpr	$0, $5
	mttgpr	$0, $6
	mttgpr	$0, $7
	mttgpr	$0, $8
	mttgpr	$0, $9
	mttgpr	$0, $10
	mttgpr	$0, $11
	mttgpr	$0, $12
	mttgpr	$0, $13
	mttgpr	$0, $14
	mttgpr	$0, $15
	mttgpr	$0, $16
	mttgpr	$0, $17
	mttgpr	$0, $18
	mttgpr	$0, $19
	mttgpr	$0, $20
	mttgpr	$0, $21
	mttgpr	$0, $22
	mttgpr	$0, $23
	mttgpr	$0, $24
	mttgpr	$0, $25
	mttgpr	$0, $26
	mttgpr	$0, $27
	mttgpr	$0, $28
	mttgpr	$0, $29
	mttgpr	$0, $30
	mttgpr	$0, $31

#endif /* DO_NOT_INIT_GPRS */

nextvpe:
	slt	$9, NVPES, TC
	bnez	$9, donevpe		# No more VPE's
	HB

	# Disable multi-threading with TC's
	mftc0	$8, $1, 1		# C0_VPECtl
	ins	$8, $0, 15, 1		# S_VPECtlTE, W_VPECtlTE
	mttc0	$8, $1, 1		# C0_VPECtl

	beqz	TC, 1f
	HB

	# For VPE1..n
	# Clear VPA and set master VPE
	mftc0	$8, $1, 2		# C0_VPEConf0
	ins	$8, $0, 0, 1		# S_VPEConf0VPA, W_VPEConf0VPA
	or	$8, (1 << 1)		# M_VPEConf0MVP
	mttc0	$8, $1, 2		# C0_VPEConf0

	# Copy Status from the current TC to the target TC's Cop0 Status register
	mfc0	$8, $12			# C0_Status
	mttc0	$8, $12			# C0_Status

#ifndef OTHER_VPE_EPC_ADDR
#define OTHER_VPE_EPC_ADDR 0x12345678
#endif
	la	$8, OTHER_VPE_EPC_ADDR
	mttc0	$8, $14			# C0_EPC

	mttc0	$0, $13			# C0_Cause

	mfc0	$8, $16			# C0_Config
	mttc0	$8, $16			# C0_Config

	mftc0	$8, $15, 1		# C0_EBase
	ext	$8, $8, 0, 10		# S_EBaseCPUNum, W_EBaseCPUNum
	mttgpr	$8, CPUNUM

	# Finally... arrange for other VPE's to continue from OTHER_VPE_TCRESTART_ADDR
#ifndef OTHER_VPE_TCRESTART_ADDR
#define OTHER_VPE_TCRESTART_ADDR 0x12345678
#endif
	la	$8, OTHER_VPE_TCRESTART_ADDR
	mttc0	$8, $2, 3		# C0_TCRestart

	# Yes.. this is undoing all of the work done above... :)
	mftc0	$8, $2, 1		# C0_TCStatus
	ins	$8, $0, 10, 1		# S_TCStatusIXMT, W_TCStatusIXMT
	ori	$8, (1 << 13)		# M_TCStatusA
	mttc0	$8, $2, 1		# C0_TCStatus

	mttc0	$0, $2, 4		# C0_TCHalt

	mftc0	$8, $1, 2		# C0_VPEConf0
	ori	$8, 1			# M_VPEConf0VPA
	mttc0	$8, $1, 2		# C0_VPEConf0
1:

donevpe:
	addu	TC, 1
	sltu	$9, NTCS, TC
	beqz	$9, nexttc
	HB

	# Exit config mode
	mfc0	$8, $0, 1		# C0_MVPCtl
	ins	$8, $0, 1, 1		# S_MVPCtlVPC, W_MVPCtlVPC
	mtc0	$8, $0, 1		# C0_MVPCtl
	ehb

#undef NTCS
#undef NVPES
#undef TC

notmtcapable:

#endif	/* DO_NOT_CHECK_FOR_MT */
#endif	/* 0 */


	/* Initialize $gp.
	 */
	bal	1f
	nop
	.word	_gp
1:
	lw	gp, 0(ra)


nop
#loop_bofore_exception:
#bal loop_bofore_exception

	/* Set up temporary stack.
	 */
	li	t0, 0xa0000000 + 0x600000
	la	sp, 0(t0)
	la	t9, board_init_f
	j	t9
	nop

return:
        # At this point the chip has been initialized
        # The address of the real code can be loaded into EPC
        # An ERet will clear EXL and jump to EPC

        la      $11, 0x80030120
        mtc0    $11, $14
        ssnop                   #.word 0x00000040
        ssnop                   #.word 0x00000040
        eret



/*
 * void relocate_code (addr_sp, gd, addr_moni)
 *
 * This "function" does not return, instead it continues in RAM
 * after relocating the monitor code.
 *
 * a0 = addr_sp
 * a1 = gd
 * a2 = destination address
 */
	.globl	relocate_code
	.ent	relocate_code
relocate_code:
	move	sp, a0		/* Set new stack pointer	*/

	li	t0, CONFIG_BOOTSTRAP_TEXT_BASE
	la	t3, in_ram
	lw	t2, -12(t3)	/* t2 <-- uboot_end_data	*/  //<<<<<------(a0100b64 t in_ram) (a012c3f0 A uboot_end_data)
													//-12(t3) is NOT uboot_end_data !!!!??? it is declared 3 long before, but not in sys.map
	move	t1, a2

	/*
	 * Fix $gp:
	 *
	 * New $gp = (Old $gp - CONFIG_BOOTSTRAP_TEXT_BASE) + Destination Address
	 */
	move	t6, gp
	sub	gp, CONFIG_BOOTSTRAP_TEXT_BASE
	add	gp, a2		/* gp now adjusted		*/
	sub	t6, gp, t6	/* t6 <-- relocation offset	*/

	/*
	 * t0 = source address
	 * t1 = target address
	 * t2 = source end address
	 */
	/* On the purple board we copy the code earlier in a special way
	 * in order to solve flash problems
	 */

1:
	lw	t3, 0(t0)       /* relocated code loop here ! */
	sw	t3, 0(t1)
	addu	t0, 4
	ble	t0, t2, 1b
	addu	t1, 4		/* delay slot			*/

	/* If caches were enabled, we would have to flush them here.
	 */

	/* Jump to where we've relocated ourselves.
	 */
	addi	t0, a2, in_ram - _start
	j	t0
	nop

	.gpword	_GLOBAL_OFFSET_TABLE_	/* _GLOBAL_OFFSET_TABLE_ - _gp	*/
#	.gpword	__got_start	/* _GLOBAL_OFFSET_TABLE_ - _gp	*/
	.word	uboot_end_data
	.word	uboot_end
	.word	num_got_entries /*define in u-boot.lds*/

in_ram:
	/*
	 * Now we want to update GOT.
	 *
	 * GOT[0] is reserved. GOT[1] is also reserved for the dynamic object
	 * generated by GNU ld. Skip these reserved entries from relocation.
	 */
	lw	t3, -4(t0)	/* t3 <-- num_got_entries	*/
	lw	t4, -16(t0)	/* t4 <-- (_GLOBAL_OFFSET_TABLE_ - _gp)	*/
and     t4, t4, 0x0FFFFFFF
	add	t4, t4, gp	/* t4 now holds _GLOBAL_OFFSET_TABLE_	*/
	addi	t4, t4, 8	/* Skipping first two entries.	*/
	li	t2, 2
1:
	lw	t1, 0(t4)
	beqz	t1, 2f
	add	t1, t6		/*t6 hols the reloc offset*/
	sw	t1, 0(t4)
2:
	addi	t2, 1
	blt	t2, t3, 1b /* if t2 (++ in a loop) < t3 (num_got_entries) jump */
	addi	t4, 4		/* delay slot			*/

	/* Clear BSS.
	 */
	lw	t1, -12(t0)	/* t1 <-- uboot_end_data	*/
	lw	t2, -8(t0)	/* t2 <-- uboot_end		*/
	add	t1, t6		/* adjust pointers		*/
	add	t2, t6

	sub	t1, 4
1:
	addi	t1, 4
	bltl	t1, t2, 1b
	sw	zero, 0(t1)	/* delay slot			*/

	move	a0, a1
	la	t9, board_init_r
	j	t9
	move	a1, a2		/* delay slot			*/

	.end	relocate_code

	/* Exception handlers.
	 */


romReserved:
	b	romReserved

romExcHandle:
	b	romExcHandle
