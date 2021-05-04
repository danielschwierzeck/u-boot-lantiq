/* Copyright (c) 2017, Intel Corporation.
 * 
 * CGU header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _CGU_H
#define _CGU_H

/*! \defgroup CGU Register File CGU - Clock Generation Unit Registers Description */
/*! @{ */

/*! Base Address of CGU */
#define CGU_MODULE_BASE 0x16200000u

/*! \defgroup PLL0A_CFG0 Register PLL0A_CFG0 - RO PLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0A_CFG0 0x4
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0A_CFG0 0x16200004u

/*! Register Reset Value */
#define PLL0A_CFG0_RST 0x50000001u

/*! Field PLLEN - PLL Enable/Disable */
#define PLL0A_CFG0_PLLEN_POS 0
/*! Field PLLEN - PLL Enable/Disable */
#define PLL0A_CFG0_PLLEN_MASK 0x1u
/*! Constant DIS - PLL Disable */
#define CONST_PLL0A_CFG0_PLLEN_DIS 0x0
/*! Constant EN - PLL Enable */
#define CONST_PLL0A_CFG0_PLLEN_EN 0x1

/*! Field LOCK - PLL Lock Status */
#define PLL0A_CFG0_LOCK_POS 1
/*! Field LOCK - PLL Lock Status */
#define PLL0A_CFG0_LOCK_MASK 0x2u
/*! Constant FREE - Free running */
#define CONST_PLL0A_CFG0_LOCK_FREE 0x0
/*! Constant LOCK - Lock */
#define CONST_PLL0A_CFG0_LOCK_LOCK 0x1

/*! Field FRAC - PLL Fractional Divider */
#define PLL0A_CFG0_FRAC_POS 2
/*! Field FRAC - PLL Fractional Divider */
#define PLL0A_CFG0_FRAC_MASK 0x3FFFFFCu

/*! Field DSMEN - PLL DSM Enable */
#define PLL0A_CFG0_DSMEN_POS 28
/*! Field DSMEN - PLL DSM Enable */
#define PLL0A_CFG0_DSMEN_MASK 0x10000000u
/*! Constant DIS - Integer Mode */
#define CONST_PLL0A_CFG0_DSMEN_DIS 0x0
/*! Constant EN - Fractional mode */
#define CONST_PLL0A_CFG0_DSMEN_EN 0x1

/*! Field VCOEN - PLL VCO Enable */
#define PLL0A_CFG0_VCOEN_POS 29
/*! Field VCOEN - PLL VCO Enable */
#define PLL0A_CFG0_VCOEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG0_VCOEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG0_VCOEN_EN 0x1

/*! Field DACEN - PLL DAC Enable */
#define PLL0A_CFG0_DACEN_POS 30
/*! Field DACEN - PLL DAC Enable */
#define PLL0A_CFG0_DACEN_MASK 0x40000000u
/*! Constant DIS - Disable the circuit .may cause issue of clock outputs. */
#define CONST_PLL0A_CFG0_DACEN_DIS 0x0
/*! Constant EN - Default. Circuit is enabled. */
#define CONST_PLL0A_CFG0_DACEN_EN 0x1

/*! @} */

/*! \defgroup PLL0A_CFG1 Register PLL0A_CFG1 - RO PLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0A_CFG1 0x8
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0A_CFG1 0x16200008u

/*! Register Reset Value */
#define PLL0A_CFG1_RST 0x0900E003u

/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK0_POS 0
/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK0_MASK 0xFu
/*! Constant GND - ref clk */
#define CONST_PLL0A_CFG1_PLL_CLK0_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0A_CFG1_PLL_CLK0_DIV64 0xF

/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK1_POS 4
/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK1_MASK 0xF0u
/*! Constant GND - ref clk */
#define CONST_PLL0A_CFG1_PLL_CLK1_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0A_CFG1_PLL_CLK1_DIV64 0xF

/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK2_POS 8
/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK2_MASK 0xF00u
/*! Constant GND - ref clk */
#define CONST_PLL0A_CFG1_PLL_CLK2_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0A_CFG1_PLL_CLK2_DIV64 0xF

/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK3_POS 12
/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL0A_CFG1_PLL_CLK3_MASK 0xF000u
/*! Constant GND - ref clk */
#define CONST_PLL0A_CFG1_PLL_CLK3_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0A_CFG1_PLL_CLK3_DIV64 0xF

/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL0A_CFG1_PLL_CLK4_POS 16
/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL0A_CFG1_PLL_CLK4_MASK 0x30000u
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0A_CFG1_PLL_CLK4_DIV4 0x0
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0A_CFG1_PLL_CLK4_DIV6 0x1
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0A_CFG1_PLL_CLK4_DIV8 0x2
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0A_CFG1_PLL_CLK4_DIV12 0x3

/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL0A_CFG1_FOUTEN0_POS 24
/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL0A_CFG1_FOUTEN0_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG1_FOUTEN0_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG1_FOUTEN0_EN 0x1

/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL0A_CFG1_FOUTEN1_POS 25
/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL0A_CFG1_FOUTEN1_MASK 0x2000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG1_FOUTEN1_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG1_FOUTEN1_EN 0x1

/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL0A_CFG1_FOUTEN2_POS 26
/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL0A_CFG1_FOUTEN2_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG1_FOUTEN2_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG1_FOUTEN2_EN 0x1

/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL0A_CFG1_FOUTEN3_POS 27
/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL0A_CFG1_FOUTEN3_MASK 0x8000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG1_FOUTEN3_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG1_FOUTEN3_EN 0x1

/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL0A_CFG1_FOUT4CMLEN_POS 28
/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL0A_CFG1_FOUT4CMLEN_MASK 0x10000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG1_FOUT4CMLEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG1_FOUT4CMLEN_EN 0x1

/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL0A_CFG1_FOUT4DIFFEN_POS 29
/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL0A_CFG1_FOUT4DIFFEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG1_FOUT4DIFFEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG1_FOUT4DIFFEN_EN 0x1

/*! @} */

/*! \defgroup PLL0A_CFG2 Register PLL0A_CFG2 - RO PLL Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0A_CFG2 0xC
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0A_CFG2 0x1620000Cu

/*! Register Reset Value */
#define PLL0A_CFG2_RST 0x1004003Cu

/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL0A_CFG2_FBDIV_POS 0
/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL0A_CFG2_FBDIV_MASK 0xFFFu

/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL0A_CFG2_REFDIV_POS 18
/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL0A_CFG2_REFDIV_MASK 0xFC0000u

/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL0A_CFG2_BYPASS0_POS 24
/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL0A_CFG2_BYPASS0_MASK 0x1000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0A_CFG2_BYPASS0_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0A_CFG2_BYPASS0_EN 0x1

/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL0A_CFG2_BYPASS1_POS 25
/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL0A_CFG2_BYPASS1_MASK 0x2000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0A_CFG2_BYPASS1_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0A_CFG2_BYPASS1_EN 0x1

/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL0A_CFG2_BYPASS2_POS 26
/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL0A_CFG2_BYPASS2_MASK 0x4000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0A_CFG2_BYPASS2_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0A_CFG2_BYPASS2_EN 0x1

/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL0A_CFG2_BYPASS3_POS 27
/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL0A_CFG2_BYPASS3_MASK 0x8000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0A_CFG2_BYPASS3_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0A_CFG2_BYPASS3_EN 0x1

/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL0A_CFG2_FREFCMLEN_POS 28
/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL0A_CFG2_FREFCMLEN_MASK 0x10000000u
/*! Constant DIS - CMOS Mode */
#define CONST_PLL0A_CFG2_FREFCMLEN_DIS 0x0
/*! Constant EN - CML Mode */
#define CONST_PLL0A_CFG2_FREFCMLEN_EN 0x1

/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL0A_CFG2_BYPASS4_POS 29
/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL0A_CFG2_BYPASS4_MASK 0x20000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0A_CFG2_BYPASS4_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0A_CFG2_BYPASS4_EN 0x1

/*! @} */

/*! \defgroup PLL0A_CFG3 Register PLL0A_CFG3 - PLL Configuration Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0A_CFG3 0x10
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0A_CFG3 0x16200010u

/*! Register Reset Value */
#define PLL0A_CFG3_RST 0x00000000u

/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL0A_CFG3_DSKCAIN_POS 0
/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL0A_CFG3_DSKCAIN_MASK 0xFFFu

/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL0A_CFG3_DSKCALOUT_POS 12
/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL0A_CFG3_DSKCALOUT_MASK 0xFFF000u

/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL0A_CFG3_DSKEWEN_POS 24
/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL0A_CFG3_DSKEWEN_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG3_DSKEWEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG3_DSKEWEN_EN 0x1

/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL0A_CFG3_DSKEWCALBP_POS 25
/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL0A_CFG3_DSKEWCALBP_MASK 0x2000000u
/*! Constant NBP - NO bypass */
#define CONST_PLL0A_CFG3_DSKEWCALBP_NBP 0x0
/*! Constant BP - bypass Deskew results */
#define CONST_PLL0A_CFG3_DSKEWCALBP_BP 0x1

/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL0A_CFG3_FASTDSKEWCALEN_POS 26
/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL0A_CFG3_FASTDSKEWCALEN_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL0A_CFG3_FASTDSKEWCALEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_CFG3_FASTDSKEWCALEN_EN 0x1

/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL0A_CFG3_DSKEWCALCNT_POS 27
/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL0A_CFG3_DSKEWCALCNT_MASK 0x38000000u

/*! @} */

/*! \defgroup PLL0A_SSC_CTRL Register PLL0A_SSC_CTRL - RO PLL Spread Spectrum Control */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0A_SSC_CTRL 0x14
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0A_SSC_CTRL 0x16200014u

/*! Register Reset Value */
#define PLL0A_SSC_CTRL_RST 0x00000000u

/*! Field EN - SSC Enable */
#define PLL0A_SSC_CTRL_EN_POS 0
/*! Field EN - SSC Enable */
#define PLL0A_SSC_CTRL_EN_MASK 0x1u
/*! Constant DIS - Disable */
#define CONST_PLL0A_SSC_CTRL_EN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0A_SSC_CTRL_EN_EN 0x1

/*! Field RESET - Reset */
#define PLL0A_SSC_CTRL_RESET_POS 1
/*! Field RESET - Reset */
#define PLL0A_SSC_CTRL_RESET_MASK 0x2u
/*! Constant NONE - No action */
#define CONST_PLL0A_SSC_CTRL_RESET_NONE 0x0
/*! Constant START - Reset */
#define CONST_PLL0A_SSC_CTRL_RESET_START 0x1

/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL0A_SSC_CTRL_SPREAD_POS 2
/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL0A_SSC_CTRL_SPREAD_MASK 0x7Cu

/*! Field DIVVAL - SSC Divider */
#define PLL0A_SSC_CTRL_DIVVAL_POS 8
/*! Field DIVVAL - SSC Divider */
#define PLL0A_SSC_CTRL_DIVVAL_MASK 0xF00u

/*! Field DOWNSPREAD - Downspread Control */
#define PLL0A_SSC_CTRL_DOWNSPREAD_POS 12
/*! Field DOWNSPREAD - Downspread Control */
#define PLL0A_SSC_CTRL_DOWNSPREAD_MASK 0x1000u
/*! Constant CENTER - Center-Spread */
#define CONST_PLL0A_SSC_CTRL_DOWNSPREAD_CENTER 0x0
/*! Constant DOWN - Downspread */
#define CONST_PLL0A_SSC_CTRL_DOWNSPREAD_DOWN 0x1

/*! @} */

/*! \defgroup PLL0B_CFG0 Register PLL0B_CFG0 - RO PLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0B_CFG0 0x24
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0B_CFG0 0x16200024u

/*! Register Reset Value */
#define PLL0B_CFG0_RST 0x50000001u

/*! Field PLLEN - PLL Enable/Disable */
#define PLL0B_CFG0_PLLEN_POS 0
/*! Field PLLEN - PLL Enable/Disable */
#define PLL0B_CFG0_PLLEN_MASK 0x1u
/*! Constant DIS - PLL Disable */
#define CONST_PLL0B_CFG0_PLLEN_DIS 0x0
/*! Constant EN - PLL Enable */
#define CONST_PLL0B_CFG0_PLLEN_EN 0x1

/*! Field LOCK - PLL Lock Status */
#define PLL0B_CFG0_LOCK_POS 1
/*! Field LOCK - PLL Lock Status */
#define PLL0B_CFG0_LOCK_MASK 0x2u
/*! Constant FREE - Free running */
#define CONST_PLL0B_CFG0_LOCK_FREE 0x0
/*! Constant LOCK - Lock */
#define CONST_PLL0B_CFG0_LOCK_LOCK 0x1

/*! Field FRAC - PLL Fractional Divider */
#define PLL0B_CFG0_FRAC_POS 2
/*! Field FRAC - PLL Fractional Divider */
#define PLL0B_CFG0_FRAC_MASK 0x3FFFFFCu

/*! Field DSMEN - PLL DSM Enable */
#define PLL0B_CFG0_DSMEN_POS 28
/*! Field DSMEN - PLL DSM Enable */
#define PLL0B_CFG0_DSMEN_MASK 0x10000000u
/*! Constant DIS - Integer Mode */
#define CONST_PLL0B_CFG0_DSMEN_DIS 0x0
/*! Constant EN - Fractional mode */
#define CONST_PLL0B_CFG0_DSMEN_EN 0x1

/*! Field VCOEN - PLL VCO Enable */
#define PLL0B_CFG0_VCOEN_POS 29
/*! Field VCOEN - PLL VCO Enable */
#define PLL0B_CFG0_VCOEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG0_VCOEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG0_VCOEN_EN 0x1

/*! Field DACEN - PLL DAC Enable */
#define PLL0B_CFG0_DACEN_POS 30
/*! Field DACEN - PLL DAC Enable */
#define PLL0B_CFG0_DACEN_MASK 0x40000000u
/*! Constant DIS - Disable the circuit .may cause issue of clock outputs. */
#define CONST_PLL0B_CFG0_DACEN_DIS 0x0
/*! Constant EN - Default. Circuit is enabled. */
#define CONST_PLL0B_CFG0_DACEN_EN 0x1

/*! @} */

/*! \defgroup PLL0B_CFG1 Register PLL0B_CFG1 - RO PLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0B_CFG1 0x28
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0B_CFG1 0x16200028u

/*! Register Reset Value */
#define PLL0B_CFG1_RST 0x0F003372u

/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK0_POS 0
/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK0_MASK 0xFu
/*! Constant GND - ref clk */
#define CONST_PLL0B_CFG1_PLL_CLK0_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0B_CFG1_PLL_CLK0_DIV64 0xF

/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK1_POS 4
/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK1_MASK 0xF0u
/*! Constant GND - ref clk */
#define CONST_PLL0B_CFG1_PLL_CLK1_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0B_CFG1_PLL_CLK1_DIV64 0xF

/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK2_POS 8
/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK2_MASK 0xF00u
/*! Constant GND - ref clk */
#define CONST_PLL0B_CFG1_PLL_CLK2_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0B_CFG1_PLL_CLK2_DIV64 0xF

/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK3_POS 12
/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL0B_CFG1_PLL_CLK3_MASK 0xF000u
/*! Constant GND - ref clk */
#define CONST_PLL0B_CFG1_PLL_CLK3_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL0B_CFG1_PLL_CLK3_DIV64 0xF

/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL0B_CFG1_PLL_CLK4_POS 16
/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL0B_CFG1_PLL_CLK4_MASK 0x30000u
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL0B_CFG1_PLL_CLK4_DIV4 0x0
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL0B_CFG1_PLL_CLK4_DIV6 0x1
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL0B_CFG1_PLL_CLK4_DIV8 0x2
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL0B_CFG1_PLL_CLK4_DIV12 0x3

/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL0B_CFG1_FOUTEN0_POS 24
/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL0B_CFG1_FOUTEN0_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG1_FOUTEN0_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG1_FOUTEN0_EN 0x1

/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL0B_CFG1_FOUTEN1_POS 25
/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL0B_CFG1_FOUTEN1_MASK 0x2000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG1_FOUTEN1_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG1_FOUTEN1_EN 0x1

/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL0B_CFG1_FOUTEN2_POS 26
/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL0B_CFG1_FOUTEN2_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG1_FOUTEN2_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG1_FOUTEN2_EN 0x1

/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL0B_CFG1_FOUTEN3_POS 27
/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL0B_CFG1_FOUTEN3_MASK 0x8000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG1_FOUTEN3_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG1_FOUTEN3_EN 0x1

/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL0B_CFG1_FOUT4CMLEN_POS 28
/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL0B_CFG1_FOUT4CMLEN_MASK 0x10000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG1_FOUT4CMLEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG1_FOUT4CMLEN_EN 0x1

/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL0B_CFG1_FOUT4DIFFEN_POS 29
/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL0B_CFG1_FOUT4DIFFEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG1_FOUT4DIFFEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG1_FOUT4DIFFEN_EN 0x1

/*! @} */

/*! \defgroup PLL0B_CFG2 Register PLL0B_CFG2 - RO PLL Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0B_CFG2 0x2C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0B_CFG2 0x1620002Cu

/*! Register Reset Value */
#define PLL0B_CFG2_RST 0x10040032u

/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL0B_CFG2_FBDIV_POS 0
/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL0B_CFG2_FBDIV_MASK 0xFFFu

/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL0B_CFG2_REFDIV_POS 18
/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL0B_CFG2_REFDIV_MASK 0xFC0000u

/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL0B_CFG2_BYPASS0_POS 24
/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL0B_CFG2_BYPASS0_MASK 0x1000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0B_CFG2_BYPASS0_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0B_CFG2_BYPASS0_EN 0x1

/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL0B_CFG2_BYPASS1_POS 25
/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL0B_CFG2_BYPASS1_MASK 0x2000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0B_CFG2_BYPASS1_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0B_CFG2_BYPASS1_EN 0x1

/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL0B_CFG2_BYPASS2_POS 26
/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL0B_CFG2_BYPASS2_MASK 0x4000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0B_CFG2_BYPASS2_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0B_CFG2_BYPASS2_EN 0x1

/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL0B_CFG2_BYPASS3_POS 27
/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL0B_CFG2_BYPASS3_MASK 0x8000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0B_CFG2_BYPASS3_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0B_CFG2_BYPASS3_EN 0x1

/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL0B_CFG2_FREFCMLEN_POS 28
/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL0B_CFG2_FREFCMLEN_MASK 0x10000000u
/*! Constant DIS - CMOS Mode */
#define CONST_PLL0B_CFG2_FREFCMLEN_DIS 0x0
/*! Constant EN - CML Mode */
#define CONST_PLL0B_CFG2_FREFCMLEN_EN 0x1

/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL0B_CFG2_BYPASS4_POS 29
/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL0B_CFG2_BYPASS4_MASK 0x20000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL0B_CFG2_BYPASS4_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL0B_CFG2_BYPASS4_EN 0x1

/*! @} */

/*! \defgroup PLL0B_CFG3 Register PLL0B_CFG3 - PLL Configuration Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0B_CFG3 0x30
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0B_CFG3 0x16200030u

/*! Register Reset Value */
#define PLL0B_CFG3_RST 0x00000000u

/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL0B_CFG3_DSKCAIN_POS 0
/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL0B_CFG3_DSKCAIN_MASK 0xFFFu

/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL0B_CFG3_DSKCALOUT_POS 12
/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL0B_CFG3_DSKCALOUT_MASK 0xFFF000u

/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL0B_CFG3_DSKEWEN_POS 24
/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL0B_CFG3_DSKEWEN_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG3_DSKEWEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG3_DSKEWEN_EN 0x1

/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL0B_CFG3_DSKEWCALBP_POS 25
/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL0B_CFG3_DSKEWCALBP_MASK 0x2000000u
/*! Constant NBP - NO bypass */
#define CONST_PLL0B_CFG3_DSKEWCALBP_NBP 0x0
/*! Constant BP - bypass Deskew results */
#define CONST_PLL0B_CFG3_DSKEWCALBP_BP 0x1

/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL0B_CFG3_FASTDSKEWCALEN_POS 26
/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL0B_CFG3_FASTDSKEWCALEN_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL0B_CFG3_FASTDSKEWCALEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_CFG3_FASTDSKEWCALEN_EN 0x1

/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL0B_CFG3_DSKEWCALCNT_POS 27
/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL0B_CFG3_DSKEWCALCNT_MASK 0x38000000u

/*! @} */

/*! \defgroup PLL0B_SSC_CTRL Register PLL0B_SSC_CTRL - RO PLL Spread Spectrum Control */
/*! @{ */

/*! Register Offset (relative) */
#define PLL0B_SSC_CTRL 0x34
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL0B_SSC_CTRL 0x16200034u

/*! Register Reset Value */
#define PLL0B_SSC_CTRL_RST 0x00000000u

/*! Field EN - SSC Enable */
#define PLL0B_SSC_CTRL_EN_POS 0
/*! Field EN - SSC Enable */
#define PLL0B_SSC_CTRL_EN_MASK 0x1u
/*! Constant DIS - Disable */
#define CONST_PLL0B_SSC_CTRL_EN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL0B_SSC_CTRL_EN_EN 0x1

/*! Field RESET - Reset */
#define PLL0B_SSC_CTRL_RESET_POS 1
/*! Field RESET - Reset */
#define PLL0B_SSC_CTRL_RESET_MASK 0x2u
/*! Constant NONE - No action */
#define CONST_PLL0B_SSC_CTRL_RESET_NONE 0x0
/*! Constant START - Reset */
#define CONST_PLL0B_SSC_CTRL_RESET_START 0x1

/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL0B_SSC_CTRL_SPREAD_POS 2
/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL0B_SSC_CTRL_SPREAD_MASK 0x7Cu

/*! Field DIVVAL - SSC Divider */
#define PLL0B_SSC_CTRL_DIVVAL_POS 8
/*! Field DIVVAL - SSC Divider */
#define PLL0B_SSC_CTRL_DIVVAL_MASK 0xF00u

/*! Field DOWNSPREAD - Downspread Control */
#define PLL0B_SSC_CTRL_DOWNSPREAD_POS 12
/*! Field DOWNSPREAD - Downspread Control */
#define PLL0B_SSC_CTRL_DOWNSPREAD_MASK 0x1000u
/*! Constant CENTER - Center-Spread */
#define CONST_PLL0B_SSC_CTRL_DOWNSPREAD_CENTER 0x0
/*! Constant DOWN - Downspread */
#define CONST_PLL0B_SSC_CTRL_DOWNSPREAD_DOWN 0x1

/*! @} */

/*! \defgroup PLL1_CFG0 Register PLL1_CFG0 - RO PLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL1_CFG0 0x44
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL1_CFG0 0x16200044u

/*! Register Reset Value */
#define PLL1_CFG0_RST 0x51495185u

/*! Field PLLEN - PLL Enable/Disable */
#define PLL1_CFG0_PLLEN_POS 0
/*! Field PLLEN - PLL Enable/Disable */
#define PLL1_CFG0_PLLEN_MASK 0x1u
/*! Constant DIS - PLL Disable */
#define CONST_PLL1_CFG0_PLLEN_DIS 0x0
/*! Constant EN - PLL Enable */
#define CONST_PLL1_CFG0_PLLEN_EN 0x1

/*! Field LOCK - PLL Lock Status */
#define PLL1_CFG0_LOCK_POS 1
/*! Field LOCK - PLL Lock Status */
#define PLL1_CFG0_LOCK_MASK 0x2u
/*! Constant FREE - Free running */
#define CONST_PLL1_CFG0_LOCK_FREE 0x0
/*! Constant LOCK - Lock */
#define CONST_PLL1_CFG0_LOCK_LOCK 0x1

/*! Field FRAC - PLL Fractional Divider */
#define PLL1_CFG0_FRAC_POS 2
/*! Field FRAC - PLL Fractional Divider */
#define PLL1_CFG0_FRAC_MASK 0x3FFFFFCu

/*! Field DSMEN - PLL DSM Enable */
#define PLL1_CFG0_DSMEN_POS 28
/*! Field DSMEN - PLL DSM Enable */
#define PLL1_CFG0_DSMEN_MASK 0x10000000u
/*! Constant DIS - Integer Mode */
#define CONST_PLL1_CFG0_DSMEN_DIS 0x0
/*! Constant EN - Fractional mode */
#define CONST_PLL1_CFG0_DSMEN_EN 0x1

/*! Field VCOEN - PLL VCO Enable */
#define PLL1_CFG0_VCOEN_POS 29
/*! Field VCOEN - PLL VCO Enable */
#define PLL1_CFG0_VCOEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG0_VCOEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG0_VCOEN_EN 0x1

/*! Field DACEN - PLL DAC Enable */
#define PLL1_CFG0_DACEN_POS 30
/*! Field DACEN - PLL DAC Enable */
#define PLL1_CFG0_DACEN_MASK 0x40000000u
/*! Constant DIS - Disable the circuit .may cause issue of clock outputs. */
#define CONST_PLL1_CFG0_DACEN_DIS 0x0
/*! Constant EN - Default. Circuit is enabled. */
#define CONST_PLL1_CFG0_DACEN_EN 0x1

/*! @} */

/*! \defgroup PLL1_CFG1 Register PLL1_CFG1 - RO PLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL1_CFG1 0x48
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL1_CFG1 0x16200048u

/*! Register Reset Value */
#define PLL1_CFG1_RST 0x030000C3u

/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL1_CFG1_PLL_CLK0_POS 0
/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL1_CFG1_PLL_CLK0_MASK 0xFu
/*! Constant GND - ref clk */
#define CONST_PLL1_CFG1_PLL_CLK0_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL1_CFG1_PLL_CLK0_DIV64 0xF

/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL1_CFG1_PLL_CLK1_POS 4
/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL1_CFG1_PLL_CLK1_MASK 0xF0u
/*! Constant GND - ref clk */
#define CONST_PLL1_CFG1_PLL_CLK1_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL1_CFG1_PLL_CLK1_DIV64 0xF

/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL1_CFG1_PLL_CLK2_POS 8
/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL1_CFG1_PLL_CLK2_MASK 0xF00u
/*! Constant GND - ref clk */
#define CONST_PLL1_CFG1_PLL_CLK2_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL1_CFG1_PLL_CLK2_DIV64 0xF

/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL1_CFG1_PLL_CLK3_POS 12
/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL1_CFG1_PLL_CLK3_MASK 0xF000u
/*! Constant GND - ref clk */
#define CONST_PLL1_CFG1_PLL_CLK3_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL1_CFG1_PLL_CLK3_DIV64 0xF

/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL1_CFG1_PLL_CLK4_POS 16
/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL1_CFG1_PLL_CLK4_MASK 0x30000u
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL1_CFG1_PLL_CLK4_DIV4 0x0
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL1_CFG1_PLL_CLK4_DIV6 0x1
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL1_CFG1_PLL_CLK4_DIV8 0x2
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL1_CFG1_PLL_CLK4_DIV12 0x3

/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL1_CFG1_FOUTEN0_POS 24
/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL1_CFG1_FOUTEN0_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG1_FOUTEN0_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG1_FOUTEN0_EN 0x1

/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL1_CFG1_FOUTEN1_POS 25
/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL1_CFG1_FOUTEN1_MASK 0x2000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG1_FOUTEN1_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG1_FOUTEN1_EN 0x1

/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL1_CFG1_FOUTEN2_POS 26
/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL1_CFG1_FOUTEN2_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG1_FOUTEN2_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG1_FOUTEN2_EN 0x1

/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL1_CFG1_FOUTEN3_POS 27
/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL1_CFG1_FOUTEN3_MASK 0x8000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG1_FOUTEN3_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG1_FOUTEN3_EN 0x1

/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL1_CFG1_FOUT4CMLEN_POS 28
/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL1_CFG1_FOUT4CMLEN_MASK 0x10000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG1_FOUT4CMLEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG1_FOUT4CMLEN_EN 0x1

/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL1_CFG1_FOUT4DIFFEN_POS 29
/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL1_CFG1_FOUT4DIFFEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG1_FOUT4DIFFEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG1_FOUT4DIFFEN_EN 0x1

/*! @} */

/*! \defgroup PLL1_CFG2 Register PLL1_CFG2 - RO PLL Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL1_CFG2 0x4C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL1_CFG2 0x1620004Cu

/*! Register Reset Value */
#define PLL1_CFG2_RST 0x10040027u

/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL1_CFG2_FBDIV_POS 0
/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL1_CFG2_FBDIV_MASK 0xFFFu

/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL1_CFG2_REFDIV_POS 18
/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL1_CFG2_REFDIV_MASK 0xFC0000u

/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL1_CFG2_BYPASS0_POS 24
/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL1_CFG2_BYPASS0_MASK 0x1000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL1_CFG2_BYPASS0_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL1_CFG2_BYPASS0_EN 0x1

/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL1_CFG2_BYPASS1_POS 25
/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL1_CFG2_BYPASS1_MASK 0x2000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL1_CFG2_BYPASS1_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL1_CFG2_BYPASS1_EN 0x1

/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL1_CFG2_BYPASS2_POS 26
/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL1_CFG2_BYPASS2_MASK 0x4000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL1_CFG2_BYPASS2_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL1_CFG2_BYPASS2_EN 0x1

/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL1_CFG2_BYPASS3_POS 27
/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL1_CFG2_BYPASS3_MASK 0x8000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL1_CFG2_BYPASS3_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL1_CFG2_BYPASS3_EN 0x1

/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL1_CFG2_FREFCMLEN_POS 28
/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL1_CFG2_FREFCMLEN_MASK 0x10000000u
/*! Constant DIS - CMOS Mode */
#define CONST_PLL1_CFG2_FREFCMLEN_DIS 0x0
/*! Constant EN - CML Mode */
#define CONST_PLL1_CFG2_FREFCMLEN_EN 0x1

/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL1_CFG2_BYPASS4_POS 29
/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL1_CFG2_BYPASS4_MASK 0x20000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL1_CFG2_BYPASS4_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL1_CFG2_BYPASS4_EN 0x1

/*! @} */

/*! \defgroup PLL1_CFG3 Register PLL1_CFG3 - PLL Configuration Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL1_CFG3 0x50
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL1_CFG3 0x16200050u

/*! Register Reset Value */
#define PLL1_CFG3_RST 0x00000000u

/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL1_CFG3_DSKCAIN_POS 0
/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL1_CFG3_DSKCAIN_MASK 0xFFFu

/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL1_CFG3_DSKCALOUT_POS 12
/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL1_CFG3_DSKCALOUT_MASK 0xFFF000u

/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL1_CFG3_DSKEWEN_POS 24
/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL1_CFG3_DSKEWEN_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG3_DSKEWEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG3_DSKEWEN_EN 0x1

/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL1_CFG3_DSKEWCALBP_POS 25
/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL1_CFG3_DSKEWCALBP_MASK 0x2000000u
/*! Constant NBP - NO bypass */
#define CONST_PLL1_CFG3_DSKEWCALBP_NBP 0x0
/*! Constant BP - bypass Deskew results */
#define CONST_PLL1_CFG3_DSKEWCALBP_BP 0x1

/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL1_CFG3_FASTDSKEWCALEN_POS 26
/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL1_CFG3_FASTDSKEWCALEN_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL1_CFG3_FASTDSKEWCALEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL1_CFG3_FASTDSKEWCALEN_EN 0x1

/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL1_CFG3_DSKEWCALCNT_POS 27
/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL1_CFG3_DSKEWCALCNT_MASK 0x38000000u

/*! @} */

/*! \defgroup PLL2_CFG0 Register PLL2_CFG0 - RO PLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL2_CFG0 0x64
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL2_CFG0 0x16200064u

/*! Register Reset Value */
#define PLL2_CFG0_RST 0x50000001u

/*! Field PLLEN - PLL Enable/Disable */
#define PLL2_CFG0_PLLEN_POS 0
/*! Field PLLEN - PLL Enable/Disable */
#define PLL2_CFG0_PLLEN_MASK 0x1u
/*! Constant DIS - PLL Disable */
#define CONST_PLL2_CFG0_PLLEN_DIS 0x0
/*! Constant EN - PLL Enable */
#define CONST_PLL2_CFG0_PLLEN_EN 0x1

/*! Field LOCK - PLL Lock Status */
#define PLL2_CFG0_LOCK_POS 1
/*! Field LOCK - PLL Lock Status */
#define PLL2_CFG0_LOCK_MASK 0x2u
/*! Constant FREE - Free running */
#define CONST_PLL2_CFG0_LOCK_FREE 0x0
/*! Constant LOCK - Lock */
#define CONST_PLL2_CFG0_LOCK_LOCK 0x1

/*! Field FRAC - PLL Fractional Divider */
#define PLL2_CFG0_FRAC_POS 2
/*! Field FRAC - PLL Fractional Divider */
#define PLL2_CFG0_FRAC_MASK 0x3FFFFFCu

/*! Field DSMEN - PLL DSM Enable */
#define PLL2_CFG0_DSMEN_POS 28
/*! Field DSMEN - PLL DSM Enable */
#define PLL2_CFG0_DSMEN_MASK 0x10000000u
/*! Constant DIS - Integer Mode */
#define CONST_PLL2_CFG0_DSMEN_DIS 0x0
/*! Constant EN - Fractional mode */
#define CONST_PLL2_CFG0_DSMEN_EN 0x1

/*! Field VCOEN - PLL VCO Enable */
#define PLL2_CFG0_VCOEN_POS 29
/*! Field VCOEN - PLL VCO Enable */
#define PLL2_CFG0_VCOEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG0_VCOEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG0_VCOEN_EN 0x1

/*! Field DACEN - PLL DAC Enable */
#define PLL2_CFG0_DACEN_POS 30
/*! Field DACEN - PLL DAC Enable */
#define PLL2_CFG0_DACEN_MASK 0x40000000u
/*! Constant DIS - Disable the circuit .may cause issue of clock outputs. */
#define CONST_PLL2_CFG0_DACEN_DIS 0x0
/*! Constant EN - Default. Circuit is enabled. */
#define CONST_PLL2_CFG0_DACEN_EN 0x1

/*! @} */

/*! \defgroup PLL2_CFG1 Register PLL2_CFG1 - RO PLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL2_CFG1 0x68
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL2_CFG1 0x16200068u

/*! Register Reset Value */
#define PLL2_CFG1_RST 0x01000002u

/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL2_CFG1_PLL_CLK0_POS 0
/*! Field PLL_CLK0 - PLL Clock Output 0 Frequency Selection */
#define PLL2_CFG1_PLL_CLK0_MASK 0xFu
/*! Constant GND - ref clk */
#define CONST_PLL2_CFG1_PLL_CLK0_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL2_CFG1_PLL_CLK0_DIV64 0xF

/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL2_CFG1_PLL_CLK1_POS 4
/*! Field PLL_CLK1 - PLL Clock Output 1 Frequency Selection */
#define PLL2_CFG1_PLL_CLK1_MASK 0xF0u
/*! Constant GND - ref clk */
#define CONST_PLL2_CFG1_PLL_CLK1_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL2_CFG1_PLL_CLK1_DIV64 0xF

/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL2_CFG1_PLL_CLK2_POS 8
/*! Field PLL_CLK2 - PLL Clock Output 2 Frequency Selection */
#define PLL2_CFG1_PLL_CLK2_MASK 0xF00u
/*! Constant GND - ref clk */
#define CONST_PLL2_CFG1_PLL_CLK2_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL2_CFG1_PLL_CLK2_DIV64 0xF

/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL2_CFG1_PLL_CLK3_POS 12
/*! Field PLL_CLK3 - PLL Clock Output 3 Frequency Selection */
#define PLL2_CFG1_PLL_CLK3_MASK 0xF000u
/*! Constant GND - ref clk */
#define CONST_PLL2_CFG1_PLL_CLK3_GND 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV6 0x5
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV8 0x6
/*! Constant DIV10 - Divide by 10 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV10 0x7
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV12 0x8
/*! Constant DIV16 - Divide by 16 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV16 0x9
/*! Constant DIV20 - Divide by 20 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV20 0xA
/*! Constant DIV24 - Divide by 24 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV24 0xB
/*! Constant DIV32 - Divide by 32 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV32 0xC
/*! Constant DIV40 - Divide by 40 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV40 0xD
/*! Constant DIV48 - Divide by 48 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV48 0xE
/*! Constant DIV64 - Divide by 64 */
#define CONST_PLL2_CFG1_PLL_CLK3_DIV64 0xF

/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL2_CFG1_PLL_CLK4_POS 16
/*! Field PLL_CLK4 - PLL Clock Output 4 */
#define PLL2_CFG1_PLL_CLK4_MASK 0x30000u
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL2_CFG1_PLL_CLK4_DIV4 0x0
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL2_CFG1_PLL_CLK4_DIV6 0x1
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL2_CFG1_PLL_CLK4_DIV8 0x2
/*! Constant DIV12 - Divide by 12 */
#define CONST_PLL2_CFG1_PLL_CLK4_DIV12 0x3

/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL2_CFG1_FOUTEN0_POS 24
/*! Field FOUTEN0 - PLL Clock Output 0 Enable */
#define PLL2_CFG1_FOUTEN0_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG1_FOUTEN0_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG1_FOUTEN0_EN 0x1

/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL2_CFG1_FOUTEN1_POS 25
/*! Field FOUTEN1 - PLL Clock Output 1 Enable */
#define PLL2_CFG1_FOUTEN1_MASK 0x2000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG1_FOUTEN1_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG1_FOUTEN1_EN 0x1

/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL2_CFG1_FOUTEN2_POS 26
/*! Field FOUTEN2 - PLL Clock Output 2 Enable */
#define PLL2_CFG1_FOUTEN2_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG1_FOUTEN2_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG1_FOUTEN2_EN 0x1

/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL2_CFG1_FOUTEN3_POS 27
/*! Field FOUTEN3 - PLL Clock Output 3 Enable */
#define PLL2_CFG1_FOUTEN3_MASK 0x8000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG1_FOUTEN3_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG1_FOUTEN3_EN 0x1

/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL2_CFG1_FOUT4CMLEN_POS 28
/*! Field FOUT4CMLEN - PLL CML Clock Output 4 Enable */
#define PLL2_CFG1_FOUT4CMLEN_MASK 0x10000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG1_FOUT4CMLEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG1_FOUT4CMLEN_EN 0x1

/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL2_CFG1_FOUT4DIFFEN_POS 29
/*! Field FOUT4DIFFEN - PLL DIFF Clock Output 4 Enable */
#define PLL2_CFG1_FOUT4DIFFEN_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG1_FOUT4DIFFEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG1_FOUT4DIFFEN_EN 0x1

/*! @} */

/*! \defgroup PLL2_CFG2 Register PLL2_CFG2 - RO PLL Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL2_CFG2 0x6C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL2_CFG2 0x1620006Cu

/*! Register Reset Value */
#define PLL2_CFG2_RST 0x10040028u

/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL2_CFG2_FBDIV_POS 0
/*! Field FBDIV - Input Integer Divide Value (FBDIV) */
#define PLL2_CFG2_FBDIV_MASK 0xFFFu

/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL2_CFG2_REFDIV_POS 18
/*! Field REFDIV - PLL Reference Clock Input Divider (REFDIV) */
#define PLL2_CFG2_REFDIV_MASK 0xFC0000u

/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL2_CFG2_BYPASS0_POS 24
/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL2_CFG2_BYPASS0_MASK 0x1000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL2_CFG2_BYPASS0_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL2_CFG2_BYPASS0_EN 0x1

/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL2_CFG2_BYPASS1_POS 25
/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL2_CFG2_BYPASS1_MASK 0x2000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL2_CFG2_BYPASS1_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL2_CFG2_BYPASS1_EN 0x1

/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL2_CFG2_BYPASS2_POS 26
/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL2_CFG2_BYPASS2_MASK 0x4000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL2_CFG2_BYPASS2_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL2_CFG2_BYPASS2_EN 0x1

/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL2_CFG2_BYPASS3_POS 27
/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL2_CFG2_BYPASS3_MASK 0x8000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL2_CFG2_BYPASS3_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL2_CFG2_BYPASS3_EN 0x1

/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL2_CFG2_FREFCMLEN_POS 28
/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL2_CFG2_FREFCMLEN_MASK 0x10000000u
/*! Constant DIS - CMOS Mode */
#define CONST_PLL2_CFG2_FREFCMLEN_DIS 0x0
/*! Constant EN - CML Mode */
#define CONST_PLL2_CFG2_FREFCMLEN_EN 0x1

/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL2_CFG2_BYPASS4_POS 29
/*! Field BYPASS4 - FOUT4 Bypass */
#define PLL2_CFG2_BYPASS4_MASK 0x20000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL2_CFG2_BYPASS4_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL2_CFG2_BYPASS4_EN 0x1

/*! @} */

/*! \defgroup PLL2_CFG3 Register PLL2_CFG3 - PLL Configuration Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL2_CFG3 0x70
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL2_CFG3 0x16200070u

/*! Register Reset Value */
#define PLL2_CFG3_RST 0x00000000u

/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL2_CFG3_DSKCAIN_POS 0
/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL2_CFG3_DSKCAIN_MASK 0xFFFu

/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL2_CFG3_DSKCALOUT_POS 12
/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL2_CFG3_DSKCALOUT_MASK 0xFFF000u

/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL2_CFG3_DSKEWEN_POS 24
/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL2_CFG3_DSKEWEN_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG3_DSKEWEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG3_DSKEWEN_EN 0x1

/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL2_CFG3_DSKEWCALBP_POS 25
/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL2_CFG3_DSKEWCALBP_MASK 0x2000000u
/*! Constant NBP - NO bypass */
#define CONST_PLL2_CFG3_DSKEWCALBP_NBP 0x0
/*! Constant BP - bypass Deskew results */
#define CONST_PLL2_CFG3_DSKEWCALBP_BP 0x1

/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL2_CFG3_FASTDSKEWCALEN_POS 26
/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL2_CFG3_FASTDSKEWCALEN_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL2_CFG3_FASTDSKEWCALEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_CFG3_FASTDSKEWCALEN_EN 0x1

/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL2_CFG3_DSKEWCALCNT_POS 27
/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL2_CFG3_DSKEWCALCNT_MASK 0x38000000u

/*! @} */

/*! \defgroup PLL2_SSC_CTRL Register PLL2_SSC_CTRL - RO PLL Spread Spectrum Control */
/*! @{ */

/*! Register Offset (relative) */
#define PLL2_SSC_CTRL 0x74
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL2_SSC_CTRL 0x16200074u

/*! Register Reset Value */
#define PLL2_SSC_CTRL_RST 0x00000000u

/*! Field EN - SSC Enable */
#define PLL2_SSC_CTRL_EN_POS 0
/*! Field EN - SSC Enable */
#define PLL2_SSC_CTRL_EN_MASK 0x1u
/*! Constant DIS - Disable */
#define CONST_PLL2_SSC_CTRL_EN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL2_SSC_CTRL_EN_EN 0x1

/*! Field RESET - Reset */
#define PLL2_SSC_CTRL_RESET_POS 1
/*! Field RESET - Reset */
#define PLL2_SSC_CTRL_RESET_MASK 0x2u
/*! Constant NONE - No action */
#define CONST_PLL2_SSC_CTRL_RESET_NONE 0x0
/*! Constant START - Reset */
#define CONST_PLL2_SSC_CTRL_RESET_START 0x1

/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL2_SSC_CTRL_SPREAD_POS 2
/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL2_SSC_CTRL_SPREAD_MASK 0x7Cu

/*! Field DIVVAL - SSC Divider */
#define PLL2_SSC_CTRL_DIVVAL_POS 8
/*! Field DIVVAL - SSC Divider */
#define PLL2_SSC_CTRL_DIVVAL_MASK 0xF00u

/*! Field DOWNSPREAD - Downspread Control */
#define PLL2_SSC_CTRL_DOWNSPREAD_POS 12
/*! Field DOWNSPREAD - Downspread Control */
#define PLL2_SSC_CTRL_DOWNSPREAD_MASK 0x1000u
/*! Constant CENTER - Center-Spread */
#define CONST_PLL2_SSC_CTRL_DOWNSPREAD_CENTER 0x0
/*! Constant DOWN - Downspread */
#define CONST_PLL2_SSC_CTRL_DOWNSPREAD_DOWN 0x1

/*! @} */

/*! \defgroup PLL3_CFG0 Register PLL3_CFG0 - LJ PLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL3_CFG0 0x84
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL3_CFG0 0x16200084u

/*! Register Reset Value */
#define PLL3_CFG0_RST 0x50000001u

/*! Field PLLEN - PLL Enable */
#define PLL3_CFG0_PLLEN_POS 0
/*! Field PLLEN - PLL Enable */
#define PLL3_CFG0_PLLEN_MASK 0x1u
/*! Constant DIS - PLL Power Down (Disabled) */
#define CONST_PLL3_CFG0_PLLEN_DIS 0x0
/*! Constant EN - PLL Enabled */
#define CONST_PLL3_CFG0_PLLEN_EN 0x1

/*! Field LOCK - PLL Lock Status */
#define PLL3_CFG0_LOCK_POS 1
/*! Field LOCK - PLL Lock Status */
#define PLL3_CFG0_LOCK_MASK 0x2u
/*! Constant FREE - Free running */
#define CONST_PLL3_CFG0_LOCK_FREE 0x0
/*! Constant LOCK - Locked */
#define CONST_PLL3_CFG0_LOCK_LOCK 0x1

/*! Field FRAC - PLL Fractional Divider */
#define PLL3_CFG0_FRAC_POS 2
/*! Field FRAC - PLL Fractional Divider */
#define PLL3_CFG0_FRAC_MASK 0x3FFFFFCu

/*! Field DSMEN - Enable Delta-Sigma Modulator */
#define PLL3_CFG0_DSMEN_POS 28
/*! Field DSMEN - Enable Delta-Sigma Modulator */
#define PLL3_CFG0_DSMEN_MASK 0x10000000u
/*! Constant DIS - Integer Mode */
#define CONST_PLL3_CFG0_DSMEN_DIS 0x0
/*! Constant EN - Fractional Mode */
#define CONST_PLL3_CFG0_DSMEN_EN 0x1

/*! Field DACEN - DAC Enable */
#define PLL3_CFG0_DACEN_POS 30
/*! Field DACEN - DAC Enable */
#define PLL3_CFG0_DACEN_MASK 0x40000000u
/*! Constant DISABLE - Disable */
#define CONST_PLL3_CFG0_DACEN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_PLL3_CFG0_DACEN_ENABLE 0x1

/*! @} */

/*! \defgroup PLL3_CFG1 Register PLL3_CFG1 - LJ PLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL3_CFG1 0x88
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL3_CFG1 0x16200088u

/*! Register Reset Value */
#define PLL3_CFG1_RST 0x2F1016E4u

/*! Field POST_DIV0A - Post Divider 0A */
#define PLL3_CFG1_POST_DIV0A_POS 0
/*! Field POST_DIV0A - Post Divider 0A */
#define PLL3_CFG1_POST_DIV0A_MASK 0x7u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV0A_DIV8 0x7

/*! Field POST_DIV0B - Post Divider 0B */
#define PLL3_CFG1_POST_DIV0B_POS 3
/*! Field POST_DIV0B - Post Divider 0B */
#define PLL3_CFG1_POST_DIV0B_MASK 0x38u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV0B_DIV8 0x7

/*! Field POST_DIV1A - Post Divider 1A */
#define PLL3_CFG1_POST_DIV1A_POS 6
/*! Field POST_DIV1A - Post Divider 1A */
#define PLL3_CFG1_POST_DIV1A_MASK 0x1C0u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV1A_DIV8 0x7

/*! Field POST_DIV1B - Post Divider 1B */
#define PLL3_CFG1_POST_DIV1B_POS 9
/*! Field POST_DIV1B - Post Divider 1B */
#define PLL3_CFG1_POST_DIV1B_MASK 0xE00u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV1B_DIV8 0x7

/*! Field POST_DIV2A - Post Divider 2A */
#define PLL3_CFG1_POST_DIV2A_POS 12
/*! Field POST_DIV2A - Post Divider 2A */
#define PLL3_CFG1_POST_DIV2A_MASK 0x7000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV2A_DIV8 0x7

/*! Field POST_DIV2B - Post Divider 2B */
#define PLL3_CFG1_POST_DIV2B_POS 15
/*! Field POST_DIV2B - Post Divider 2B */
#define PLL3_CFG1_POST_DIV2B_MASK 0x38000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV2B_DIV8 0x7

/*! Field POST_DIV3A - Post Divider 3A */
#define PLL3_CFG1_POST_DIV3A_POS 18
/*! Field POST_DIV3A - Post Divider 3A */
#define PLL3_CFG1_POST_DIV3A_MASK 0x1C0000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV3A_DIV8 0x7

/*! Field POST_DIV3B - Post Divider 3B */
#define PLL3_CFG1_POST_DIV3B_POS 21
/*! Field POST_DIV3B - Post Divider 3B */
#define PLL3_CFG1_POST_DIV3B_MASK 0xE00000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL3_CFG1_POST_DIV3B_DIV8 0x7

/*! Field FOUT0EN - PLL Clock Output 0 Enable */
#define PLL3_CFG1_FOUT0EN_POS 24
/*! Field FOUT0EN - PLL Clock Output 0 Enable */
#define PLL3_CFG1_FOUT0EN_MASK 0x1000000u
/*! Constant M0 - output power down */
#define CONST_PLL3_CFG1_FOUT0EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL3_CFG1_FOUT0EN_M1 0x1

/*! Field FOUT1EN - PLL Clock Output 1 Enable */
#define PLL3_CFG1_FOUT1EN_POS 25
/*! Field FOUT1EN - PLL Clock Output 1 Enable */
#define PLL3_CFG1_FOUT1EN_MASK 0x2000000u
/*! Constant M0 - output power down */
#define CONST_PLL3_CFG1_FOUT1EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL3_CFG1_FOUT1EN_M1 0x1

/*! Field FOUT2EN - PLL Clock Output 2 Enable */
#define PLL3_CFG1_FOUT2EN_POS 26
/*! Field FOUT2EN - PLL Clock Output 2 Enable */
#define PLL3_CFG1_FOUT2EN_MASK 0x4000000u
/*! Constant M0 - output power down */
#define CONST_PLL3_CFG1_FOUT2EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL3_CFG1_FOUT2EN_M1 0x1

/*! Field FOUT3EN - PLL Clock Output 3 Enable */
#define PLL3_CFG1_FOUT3EN_POS 27
/*! Field FOUT3EN - PLL Clock Output 3 Enable */
#define PLL3_CFG1_FOUT3EN_MASK 0x8000000u
/*! Constant M0 - output power down */
#define CONST_PLL3_CFG1_FOUT3EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL3_CFG1_FOUT3EN_M1 0x1

/*! Field POST_DIV0PRE - Enable for Pre-Divide for FOUTCML0N/P */
#define PLL3_CFG1_POST_DIV0PRE_POS 29
/*! Field POST_DIV0PRE - Enable for Pre-Divide for FOUTCML0N/P */
#define PLL3_CFG1_POST_DIV0PRE_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL3_CFG1_POST_DIV0PRE_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL3_CFG1_POST_DIV0PRE_EN 0x1

/*! @} */

/*! \defgroup PLL3_CFG2 Register PLL3_CFG2 - LJPLL Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL3_CFG2 0x8C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL3_CFG2 0x1620008Cu

/*! Register Reset Value */
#define PLL3_CFG2_RST 0x100400FAu

/*! Field FBDIV - LJPLL Feedback Divider */
#define PLL3_CFG2_FBDIV_POS 0
/*! Field FBDIV - LJPLL Feedback Divider */
#define PLL3_CFG2_FBDIV_MASK 0xFFFu

/*! Field REFDIV - PLL Reference Clock Input Divider */
#define PLL3_CFG2_REFDIV_POS 18
/*! Field REFDIV - PLL Reference Clock Input Divider */
#define PLL3_CFG2_REFDIV_MASK 0xFC0000u

/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL3_CFG2_BYPASS0_POS 24
/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL3_CFG2_BYPASS0_MASK 0x1000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL3_CFG2_BYPASS0_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL3_CFG2_BYPASS0_EN 0x1

/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL3_CFG2_BYPASS1_POS 25
/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL3_CFG2_BYPASS1_MASK 0x2000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL3_CFG2_BYPASS1_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL3_CFG2_BYPASS1_EN 0x1

/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL3_CFG2_BYPASS2_POS 26
/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL3_CFG2_BYPASS2_MASK 0x4000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL3_CFG2_BYPASS2_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL3_CFG2_BYPASS2_EN 0x1

/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL3_CFG2_BYPASS3_POS 27
/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL3_CFG2_BYPASS3_MASK 0x8000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL3_CFG2_BYPASS3_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL3_CFG2_BYPASS3_EN 0x1

/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL3_CFG2_FREFCMLEN_POS 28
/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL3_CFG2_FREFCMLEN_MASK 0x10000000u
/*! Constant DIS - CMOS Mode */
#define CONST_PLL3_CFG2_FREFCMLEN_DIS 0x0
/*! Constant EN - CML Mode */
#define CONST_PLL3_CFG2_FREFCMLEN_EN 0x1

/*! @} */

/*! \defgroup PLL3_CFG3 Register PLL3_CFG3 - PLL Configuration Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL3_CFG3 0x90
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL3_CFG3 0x16200090u

/*! Register Reset Value */
#define PLL3_CFG3_RST 0x00000000u

/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL3_CFG3_DSKCAIN_POS 0
/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL3_CFG3_DSKCAIN_MASK 0xFFFu

/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL3_CFG3_DSKCALOUT_POS 12
/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL3_CFG3_DSKCALOUT_MASK 0xFFF000u

/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL3_CFG3_DSKEWEN_POS 24
/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL3_CFG3_DSKEWEN_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL3_CFG3_DSKEWEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL3_CFG3_DSKEWEN_EN 0x1

/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL3_CFG3_DSKEWCALBP_POS 25
/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL3_CFG3_DSKEWCALBP_MASK 0x2000000u
/*! Constant NBP - NO bypass */
#define CONST_PLL3_CFG3_DSKEWCALBP_NBP 0x0
/*! Constant BP - bypass Deskew results */
#define CONST_PLL3_CFG3_DSKEWCALBP_BP 0x1

/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL3_CFG3_FASTDSKEWCALEN_POS 26
/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL3_CFG3_FASTDSKEWCALEN_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL3_CFG3_FASTDSKEWCALEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL3_CFG3_FASTDSKEWCALEN_EN 0x1

/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL3_CFG3_DSKEWCALCNT_POS 27
/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL3_CFG3_DSKEWCALCNT_MASK 0x38000000u

/*! @} */

/*! \defgroup PLL4_CFG0 Register PLL4_CFG0 - LJ PLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL4_CFG0 0xA4
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL4_CFG0 0x162000A4u

/*! Register Reset Value */
#define PLL4_CFG0_RST 0x50000001u

/*! Field PLLEN - PLL Enable */
#define PLL4_CFG0_PLLEN_POS 0
/*! Field PLLEN - PLL Enable */
#define PLL4_CFG0_PLLEN_MASK 0x1u
/*! Constant DIS - PLL Power Down (Disabled) */
#define CONST_PLL4_CFG0_PLLEN_DIS 0x0
/*! Constant EN - PLL Enabled */
#define CONST_PLL4_CFG0_PLLEN_EN 0x1

/*! Field LOCK - PLL Lock Status */
#define PLL4_CFG0_LOCK_POS 1
/*! Field LOCK - PLL Lock Status */
#define PLL4_CFG0_LOCK_MASK 0x2u
/*! Constant FREE - Free running */
#define CONST_PLL4_CFG0_LOCK_FREE 0x0
/*! Constant LOCK - Locked */
#define CONST_PLL4_CFG0_LOCK_LOCK 0x1

/*! Field FRAC - PLL Fractional Divider */
#define PLL4_CFG0_FRAC_POS 2
/*! Field FRAC - PLL Fractional Divider */
#define PLL4_CFG0_FRAC_MASK 0x3FFFFFCu

/*! Field DSMEN - Enable Delta-Sigma Modulator */
#define PLL4_CFG0_DSMEN_POS 28
/*! Field DSMEN - Enable Delta-Sigma Modulator */
#define PLL4_CFG0_DSMEN_MASK 0x10000000u
/*! Constant DIS - Integer Mode */
#define CONST_PLL4_CFG0_DSMEN_DIS 0x0
/*! Constant EN - Fractional Mode */
#define CONST_PLL4_CFG0_DSMEN_EN 0x1

/*! Field DACEN - DAC Enable */
#define PLL4_CFG0_DACEN_POS 30
/*! Field DACEN - DAC Enable */
#define PLL4_CFG0_DACEN_MASK 0x40000000u
/*! Constant DISABLE - Disable */
#define CONST_PLL4_CFG0_DACEN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_PLL4_CFG0_DACEN_ENABLE 0x1

/*! @} */

/*! \defgroup PLL4_CFG1 Register PLL4_CFG1 - LJ PLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL4_CFG1 0xA8
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL4_CFG1 0x162000A8u

/*! Register Reset Value */
#define PLL4_CFG1_RST 0x21000004u

/*! Field POST_DIV0A - Post Divider 0A */
#define PLL4_CFG1_POST_DIV0A_POS 0
/*! Field POST_DIV0A - Post Divider 0A */
#define PLL4_CFG1_POST_DIV0A_MASK 0x7u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV0A_DIV8 0x7

/*! Field POST_DIV0B - Post Divider 0B */
#define PLL4_CFG1_POST_DIV0B_POS 3
/*! Field POST_DIV0B - Post Divider 0B */
#define PLL4_CFG1_POST_DIV0B_MASK 0x38u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV0B_DIV8 0x7

/*! Field POST_DIV1A - Post Divider 1A */
#define PLL4_CFG1_POST_DIV1A_POS 6
/*! Field POST_DIV1A - Post Divider 1A */
#define PLL4_CFG1_POST_DIV1A_MASK 0x1C0u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV1A_DIV8 0x7

/*! Field POST_DIV1B - Post Divider 1B */
#define PLL4_CFG1_POST_DIV1B_POS 9
/*! Field POST_DIV1B - Post Divider 1B */
#define PLL4_CFG1_POST_DIV1B_MASK 0xE00u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV1B_DIV8 0x7

/*! Field POST_DIV2A - Post Divider 2A */
#define PLL4_CFG1_POST_DIV2A_POS 12
/*! Field POST_DIV2A - Post Divider 2A */
#define PLL4_CFG1_POST_DIV2A_MASK 0x7000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV2A_DIV8 0x7

/*! Field POST_DIV2B - Post Divider 2B */
#define PLL4_CFG1_POST_DIV2B_POS 15
/*! Field POST_DIV2B - Post Divider 2B */
#define PLL4_CFG1_POST_DIV2B_MASK 0x38000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV2B_DIV8 0x7

/*! Field POST_DIV3A - Post Divider 3A */
#define PLL4_CFG1_POST_DIV3A_POS 18
/*! Field POST_DIV3A - Post Divider 3A */
#define PLL4_CFG1_POST_DIV3A_MASK 0x1C0000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV3A_DIV8 0x7

/*! Field POST_DIV3B - Post Divider 3B */
#define PLL4_CFG1_POST_DIV3B_POS 21
/*! Field POST_DIV3B - Post Divider 3B */
#define PLL4_CFG1_POST_DIV3B_MASK 0xE00000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL4_CFG1_POST_DIV3B_DIV8 0x7

/*! Field FOUT0EN - PLL Clock Output 0 Enable */
#define PLL4_CFG1_FOUT0EN_POS 24
/*! Field FOUT0EN - PLL Clock Output 0 Enable */
#define PLL4_CFG1_FOUT0EN_MASK 0x1000000u
/*! Constant M0 - output power down */
#define CONST_PLL4_CFG1_FOUT0EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL4_CFG1_FOUT0EN_M1 0x1

/*! Field FOUT1EN - PLL Clock Output 1 Enable */
#define PLL4_CFG1_FOUT1EN_POS 25
/*! Field FOUT1EN - PLL Clock Output 1 Enable */
#define PLL4_CFG1_FOUT1EN_MASK 0x2000000u
/*! Constant M0 - output power down */
#define CONST_PLL4_CFG1_FOUT1EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL4_CFG1_FOUT1EN_M1 0x1

/*! Field FOUT2EN - PLL Clock Output 2 Enable */
#define PLL4_CFG1_FOUT2EN_POS 26
/*! Field FOUT2EN - PLL Clock Output 2 Enable */
#define PLL4_CFG1_FOUT2EN_MASK 0x4000000u
/*! Constant M0 - output power down */
#define CONST_PLL4_CFG1_FOUT2EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL4_CFG1_FOUT2EN_M1 0x1

/*! Field FOUT3EN - PLL Clock Output 3 Enable */
#define PLL4_CFG1_FOUT3EN_POS 27
/*! Field FOUT3EN - PLL Clock Output 3 Enable */
#define PLL4_CFG1_FOUT3EN_MASK 0x8000000u
/*! Constant M0 - output power down */
#define CONST_PLL4_CFG1_FOUT3EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL4_CFG1_FOUT3EN_M1 0x1

/*! Field POST_DIV0PRE - Enable for Pre-Divide for FOUTCML0N/P */
#define PLL4_CFG1_POST_DIV0PRE_POS 29
/*! Field POST_DIV0PRE - Enable for Pre-Divide for FOUTCML0N/P */
#define PLL4_CFG1_POST_DIV0PRE_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL4_CFG1_POST_DIV0PRE_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL4_CFG1_POST_DIV0PRE_EN 0x1

/*! @} */

/*! \defgroup PLL4_CFG2 Register PLL4_CFG2 - LJPLL Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL4_CFG2 0xAC
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL4_CFG2 0x162000ACu

/*! Register Reset Value */
#define PLL4_CFG2_RST 0x1004007Du

/*! Field FBDIV - LJPLL Feedback Divider */
#define PLL4_CFG2_FBDIV_POS 0
/*! Field FBDIV - LJPLL Feedback Divider */
#define PLL4_CFG2_FBDIV_MASK 0xFFFu

/*! Field REFDIV - PLL Reference Clock Input Divider */
#define PLL4_CFG2_REFDIV_POS 18
/*! Field REFDIV - PLL Reference Clock Input Divider */
#define PLL4_CFG2_REFDIV_MASK 0xFC0000u

/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL4_CFG2_BYPASS0_POS 24
/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL4_CFG2_BYPASS0_MASK 0x1000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL4_CFG2_BYPASS0_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL4_CFG2_BYPASS0_EN 0x1

/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL4_CFG2_BYPASS1_POS 25
/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL4_CFG2_BYPASS1_MASK 0x2000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL4_CFG2_BYPASS1_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL4_CFG2_BYPASS1_EN 0x1

/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL4_CFG2_BYPASS2_POS 26
/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL4_CFG2_BYPASS2_MASK 0x4000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL4_CFG2_BYPASS2_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL4_CFG2_BYPASS2_EN 0x1

/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL4_CFG2_BYPASS3_POS 27
/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL4_CFG2_BYPASS3_MASK 0x8000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL4_CFG2_BYPASS3_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL4_CFG2_BYPASS3_EN 0x1

/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL4_CFG2_FREFCMLEN_POS 28
/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL4_CFG2_FREFCMLEN_MASK 0x10000000u
/*! Constant DIS - CMOS Mode */
#define CONST_PLL4_CFG2_FREFCMLEN_DIS 0x0
/*! Constant EN - CML Mode */
#define CONST_PLL4_CFG2_FREFCMLEN_EN 0x1

/*! @} */

/*! \defgroup PLL4_CFG3 Register PLL4_CFG3 - PLL Configuration Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL4_CFG3 0xB0
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL4_CFG3 0x162000B0u

/*! Register Reset Value */
#define PLL4_CFG3_RST 0x00000000u

/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL4_CFG3_DSKCAIN_POS 0
/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL4_CFG3_DSKCAIN_MASK 0xFFFu

/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL4_CFG3_DSKCALOUT_POS 12
/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL4_CFG3_DSKCALOUT_MASK 0xFFF000u

/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL4_CFG3_DSKEWEN_POS 24
/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL4_CFG3_DSKEWEN_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL4_CFG3_DSKEWEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL4_CFG3_DSKEWEN_EN 0x1

/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL4_CFG3_DSKEWCALBP_POS 25
/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL4_CFG3_DSKEWCALBP_MASK 0x2000000u
/*! Constant NBP - NO bypass */
#define CONST_PLL4_CFG3_DSKEWCALBP_NBP 0x0
/*! Constant BP - bypass Deskew results */
#define CONST_PLL4_CFG3_DSKEWCALBP_BP 0x1

/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL4_CFG3_FASTDSKEWCALEN_POS 26
/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL4_CFG3_FASTDSKEWCALEN_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL4_CFG3_FASTDSKEWCALEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL4_CFG3_FASTDSKEWCALEN_EN 0x1

/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL4_CFG3_DSKEWCALCNT_POS 27
/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL4_CFG3_DSKEWCALCNT_MASK 0x38000000u

/*! @} */

/*! \defgroup PLL4_SSC_CTRL Register PLL4_SSC_CTRL - RO PLL Spread Spectrum Control */
/*! @{ */

/*! Register Offset (relative) */
#define PLL4_SSC_CTRL 0xB4
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL4_SSC_CTRL 0x162000B4u

/*! Register Reset Value */
#define PLL4_SSC_CTRL_RST 0x00000000u

/*! Field EN - SSC Enable */
#define PLL4_SSC_CTRL_EN_POS 0
/*! Field EN - SSC Enable */
#define PLL4_SSC_CTRL_EN_MASK 0x1u
/*! Constant DIS - Disable */
#define CONST_PLL4_SSC_CTRL_EN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL4_SSC_CTRL_EN_EN 0x1

/*! Field RESET - Reset */
#define PLL4_SSC_CTRL_RESET_POS 1
/*! Field RESET - Reset */
#define PLL4_SSC_CTRL_RESET_MASK 0x2u
/*! Constant NONE - No action */
#define CONST_PLL4_SSC_CTRL_RESET_NONE 0x0
/*! Constant START - Reset */
#define CONST_PLL4_SSC_CTRL_RESET_START 0x1

/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL4_SSC_CTRL_SPREAD_POS 2
/*! Field SPREAD - Spread Depth Control in 0.1% steps */
#define PLL4_SSC_CTRL_SPREAD_MASK 0x7Cu

/*! Field DIVVAL - SSC Divider */
#define PLL4_SSC_CTRL_DIVVAL_POS 8
/*! Field DIVVAL - SSC Divider */
#define PLL4_SSC_CTRL_DIVVAL_MASK 0xF00u

/*! Field DOWNSPREAD - Downspread Control */
#define PLL4_SSC_CTRL_DOWNSPREAD_POS 12
/*! Field DOWNSPREAD - Downspread Control */
#define PLL4_SSC_CTRL_DOWNSPREAD_MASK 0x1000u
/*! Constant CENTER - Center-Spread */
#define CONST_PLL4_SSC_CTRL_DOWNSPREAD_CENTER 0x0
/*! Constant DOWN - Downspread */
#define CONST_PLL4_SSC_CTRL_DOWNSPREAD_DOWN 0x1

/*! @} */

/*! \defgroup PLL5_CFG0 Register PLL5_CFG0 - LJ PLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL5_CFG0 0xC4
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL5_CFG0 0x162000C4u

/*! Register Reset Value */
#define PLL5_CFG0_RST 0x00000000u

/*! Field PLLEN - PLL Enable */
#define PLL5_CFG0_PLLEN_POS 0
/*! Field PLLEN - PLL Enable */
#define PLL5_CFG0_PLLEN_MASK 0x1u
/*! Constant DIS - PLL Power Down (Disabled) */
#define CONST_PLL5_CFG0_PLLEN_DIS 0x0
/*! Constant EN - PLL Enabled */
#define CONST_PLL5_CFG0_PLLEN_EN 0x1

/*! Field LOCK - PLL Lock Status */
#define PLL5_CFG0_LOCK_POS 1
/*! Field LOCK - PLL Lock Status */
#define PLL5_CFG0_LOCK_MASK 0x2u
/*! Constant FREE - Free running */
#define CONST_PLL5_CFG0_LOCK_FREE 0x0
/*! Constant LOCK - Locked */
#define CONST_PLL5_CFG0_LOCK_LOCK 0x1

/*! Field FRAC - PLL Fractional Divider */
#define PLL5_CFG0_FRAC_POS 2
/*! Field FRAC - PLL Fractional Divider */
#define PLL5_CFG0_FRAC_MASK 0x3FFFFFCu

/*! Field DSMEN - Enable Delta-Sigma Modulator */
#define PLL5_CFG0_DSMEN_POS 28
/*! Field DSMEN - Enable Delta-Sigma Modulator */
#define PLL5_CFG0_DSMEN_MASK 0x10000000u
/*! Constant DIS - Integer Mode */
#define CONST_PLL5_CFG0_DSMEN_DIS 0x0
/*! Constant EN - Fractional Mode */
#define CONST_PLL5_CFG0_DSMEN_EN 0x1

/*! Field DACEN - DAC Enable */
#define PLL5_CFG0_DACEN_POS 30
/*! Field DACEN - DAC Enable */
#define PLL5_CFG0_DACEN_MASK 0x40000000u
/*! Constant DISABLE - Disable */
#define CONST_PLL5_CFG0_DACEN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_PLL5_CFG0_DACEN_ENABLE 0x1

/*! @} */

/*! \defgroup PLL5_CFG1 Register PLL5_CFG1 - LJ PLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL5_CFG1 0xC8
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL5_CFG1 0x162000C8u

/*! Register Reset Value */
#define PLL5_CFG1_RST 0x00000000u

/*! Field POST_DIV0A - Post Divider 0A */
#define PLL5_CFG1_POST_DIV0A_POS 0
/*! Field POST_DIV0A - Post Divider 0A */
#define PLL5_CFG1_POST_DIV0A_MASK 0x7u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV0A_DIV8 0x7

/*! Field POST_DIV0B - Post Divider 0B */
#define PLL5_CFG1_POST_DIV0B_POS 3
/*! Field POST_DIV0B - Post Divider 0B */
#define PLL5_CFG1_POST_DIV0B_MASK 0x38u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV0B_DIV8 0x7

/*! Field POST_DIV1A - Post Divider 1A */
#define PLL5_CFG1_POST_DIV1A_POS 6
/*! Field POST_DIV1A - Post Divider 1A */
#define PLL5_CFG1_POST_DIV1A_MASK 0x1C0u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV1A_DIV8 0x7

/*! Field POST_DIV1B - Post Divider 1B */
#define PLL5_CFG1_POST_DIV1B_POS 9
/*! Field POST_DIV1B - Post Divider 1B */
#define PLL5_CFG1_POST_DIV1B_MASK 0xE00u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV1B_DIV8 0x7

/*! Field POST_DIV2A - Post Divider 2A */
#define PLL5_CFG1_POST_DIV2A_POS 12
/*! Field POST_DIV2A - Post Divider 2A */
#define PLL5_CFG1_POST_DIV2A_MASK 0x7000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV2A_DIV8 0x7

/*! Field POST_DIV2B - Post Divider 2B */
#define PLL5_CFG1_POST_DIV2B_POS 15
/*! Field POST_DIV2B - Post Divider 2B */
#define PLL5_CFG1_POST_DIV2B_MASK 0x38000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV2B_DIV8 0x7

/*! Field POST_DIV3A - Post Divider 3A */
#define PLL5_CFG1_POST_DIV3A_POS 18
/*! Field POST_DIV3A - Post Divider 3A */
#define PLL5_CFG1_POST_DIV3A_MASK 0x1C0000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV3A_DIV8 0x7

/*! Field POST_DIV3B - Post Divider 3B */
#define PLL5_CFG1_POST_DIV3B_POS 21
/*! Field POST_DIV3B - Post Divider 3B */
#define PLL5_CFG1_POST_DIV3B_MASK 0xE00000u
/*! Constant DIV1 - Divide by 1 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV1 0x0
/*! Constant DIV2 - Divide by 2 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV2 0x1
/*! Constant DIV3 - Divide by 3 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV3 0x2
/*! Constant DIV4 - Divide by 4 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV4 0x3
/*! Constant DIV5 - Divide by 5 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV5 0x4
/*! Constant DIV6 - Divide by 6 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV6 0x5
/*! Constant DIV7 - Divide by 7 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV7 0x6
/*! Constant DIV8 - Divide by 8 */
#define CONST_PLL5_CFG1_POST_DIV3B_DIV8 0x7

/*! Field FOUT0EN - PLL Clock Output 0 Enable */
#define PLL5_CFG1_FOUT0EN_POS 24
/*! Field FOUT0EN - PLL Clock Output 0 Enable */
#define PLL5_CFG1_FOUT0EN_MASK 0x1000000u
/*! Constant M0 - output power down */
#define CONST_PLL5_CFG1_FOUT0EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL5_CFG1_FOUT0EN_M1 0x1

/*! Field FOUT1EN - PLL Clock Output 1 Enable */
#define PLL5_CFG1_FOUT1EN_POS 25
/*! Field FOUT1EN - PLL Clock Output 1 Enable */
#define PLL5_CFG1_FOUT1EN_MASK 0x2000000u
/*! Constant M0 - output power down */
#define CONST_PLL5_CFG1_FOUT1EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL5_CFG1_FOUT1EN_M1 0x1

/*! Field FOUT2EN - PLL Clock Output 2 Enable */
#define PLL5_CFG1_FOUT2EN_POS 26
/*! Field FOUT2EN - PLL Clock Output 2 Enable */
#define PLL5_CFG1_FOUT2EN_MASK 0x4000000u
/*! Constant M0 - output power down */
#define CONST_PLL5_CFG1_FOUT2EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL5_CFG1_FOUT2EN_M1 0x1

/*! Field FOUT3EN - PLL Clock Output 3 Enable */
#define PLL5_CFG1_FOUT3EN_POS 27
/*! Field FOUT3EN - PLL Clock Output 3 Enable */
#define PLL5_CFG1_FOUT3EN_MASK 0x8000000u
/*! Constant M0 - output power down */
#define CONST_PLL5_CFG1_FOUT3EN_M0 0x0
/*! Constant M1 - output enabled */
#define CONST_PLL5_CFG1_FOUT3EN_M1 0x1

/*! Field POST_DIV0PRE - Enable for Pre-Divide for FOUTCML0N/P */
#define PLL5_CFG1_POST_DIV0PRE_POS 29
/*! Field POST_DIV0PRE - Enable for Pre-Divide for FOUTCML0N/P */
#define PLL5_CFG1_POST_DIV0PRE_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_PLL5_CFG1_POST_DIV0PRE_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL5_CFG1_POST_DIV0PRE_EN 0x1

/*! @} */

/*! \defgroup PLL5_CFG2 Register PLL5_CFG2 - LJPLL Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL5_CFG2 0xCC
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL5_CFG2 0x162000CCu

/*! Register Reset Value */
#define PLL5_CFG2_RST 0x00000000u

/*! Field FBDIV - LJPLL Feedback Divider */
#define PLL5_CFG2_FBDIV_POS 0
/*! Field FBDIV - LJPLL Feedback Divider */
#define PLL5_CFG2_FBDIV_MASK 0xFFFu

/*! Field REFDIV - PLL Reference Clock Input Divider */
#define PLL5_CFG2_REFDIV_POS 18
/*! Field REFDIV - PLL Reference Clock Input Divider */
#define PLL5_CFG2_REFDIV_MASK 0xFC0000u

/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL5_CFG2_BYPASS0_POS 24
/*! Field BYPASS0 - FOUT0 Bypass */
#define PLL5_CFG2_BYPASS0_MASK 0x1000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL5_CFG2_BYPASS0_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL5_CFG2_BYPASS0_EN 0x1

/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL5_CFG2_BYPASS1_POS 25
/*! Field BYPASS1 - FOUT1 Bypass */
#define PLL5_CFG2_BYPASS1_MASK 0x2000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL5_CFG2_BYPASS1_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL5_CFG2_BYPASS1_EN 0x1

/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL5_CFG2_BYPASS2_POS 26
/*! Field BYPASS2 - FOUT2 Bypass */
#define PLL5_CFG2_BYPASS2_MASK 0x4000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL5_CFG2_BYPASS2_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL5_CFG2_BYPASS2_EN 0x1

/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL5_CFG2_BYPASS3_POS 27
/*! Field BYPASS3 - FOUT3 Bypass */
#define PLL5_CFG2_BYPASS3_MASK 0x8000000u
/*! Constant DIS - Disable Bypass */
#define CONST_PLL5_CFG2_BYPASS3_DIS 0x0
/*! Constant EN - Enable Bypass */
#define CONST_PLL5_CFG2_BYPASS3_EN 0x1

/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL5_CFG2_FREFCMLEN_POS 28
/*! Field FREFCMLEN - Enable Reference Clock CML Mode */
#define PLL5_CFG2_FREFCMLEN_MASK 0x10000000u
/*! Constant DIS - CMOS Mode */
#define CONST_PLL5_CFG2_FREFCMLEN_DIS 0x0
/*! Constant EN - CML Mode */
#define CONST_PLL5_CFG2_FREFCMLEN_EN 0x1

/*! @} */

/*! \defgroup PLL5_CFG3 Register PLL5_CFG3 - PLL Configuration Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PLL5_CFG3 0xD0
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_PLL5_CFG3 0x162000D0u

/*! Register Reset Value */
#define PLL5_CFG3_RST 0x00000000u

/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL5_CFG3_DSKCAIN_POS 0
/*! Field DSKCAIN - 12 b value for calibration override */
#define PLL5_CFG3_DSKCAIN_MASK 0xFFFu

/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL5_CFG3_DSKCALOUT_POS 12
/*! Field DSKCALOUT - 12b value for calibration read out */
#define PLL5_CFG3_DSKCALOUT_MASK 0xFFF000u

/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL5_CFG3_DSKEWEN_POS 24
/*! Field DSKEWEN - Enable DSKEW Calibration */
#define PLL5_CFG3_DSKEWEN_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_PLL5_CFG3_DSKEWEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL5_CFG3_DSKEWEN_EN 0x1

/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL5_CFG3_DSKEWCALBP_POS 25
/*! Field DSKEWCALBP - Bypass DSKEW calibration */
#define PLL5_CFG3_DSKEWCALBP_MASK 0x2000000u
/*! Constant NBP - NO bypass */
#define CONST_PLL5_CFG3_DSKEWCALBP_NBP 0x0
/*! Constant BP - bypass Deskew results */
#define CONST_PLL5_CFG3_DSKEWCALBP_BP 0x1

/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL5_CFG3_FASTDSKEWCALEN_POS 26
/*! Field FASTDSKEWCALEN - Enable FAST DESKEW CALIBRATION */
#define PLL5_CFG3_FASTDSKEWCALEN_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_PLL5_CFG3_FASTDSKEWCALEN_DIS 0x0
/*! Constant EN - Enable */
#define CONST_PLL5_CFG3_FASTDSKEWCALEN_EN 0x1

/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL5_CFG3_DSKEWCALCNT_POS 27
/*! Field DSKEWCALCNT - Programmable counter for deskew calibration loop */
#define PLL5_CFG3_DSKEWCALCNT_MASK 0x38000000u

/*! @} */

/*! \defgroup CGU_CLKGSR0 Register CGU_CLKGSR0 - CGU Clock Gating Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGSR0 0x114
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGSR0 0x16200114u

/*! Register Reset Value */
#define CGU_CLKGSR0_RST 0x00000087u

/*! Field XBAR0 - XBAR0 clock status */
#define CGU_CLKGSR0_XBAR0_POS 0
/*! Field XBAR0 - XBAR0 clock status */
#define CGU_CLKGSR0_XBAR0_MASK 0x1u
/*! Constant GATED - gated */
#define CONST_CGU_CLKGSR0_XBAR0_GATED 0x0
/*! Constant ENABLED - enabled */
#define CONST_CGU_CLKGSR0_XBAR0_ENABLED 0x1

/*! Field XBAR1 - XBAR1 clock status */
#define CGU_CLKGSR0_XBAR1_POS 1
/*! Field XBAR1 - XBAR1 clock status */
#define CGU_CLKGSR0_XBAR1_MASK 0x2u
/*! Constant GATED - gated */
#define CONST_CGU_CLKGSR0_XBAR1_GATED 0x0
/*! Constant ENABLED - enabled */
#define CONST_CGU_CLKGSR0_XBAR1_ENABLED 0x1

/*! Field XBAR2 - XBAR2 clock status */
#define CGU_CLKGSR0_XBAR2_POS 2
/*! Field XBAR2 - XBAR2 clock status */
#define CGU_CLKGSR0_XBAR2_MASK 0x4u
/*! Constant GATED - gated */
#define CONST_CGU_CLKGSR0_XBAR2_GATED 0x0
/*! Constant ENABLED - enabled */
#define CONST_CGU_CLKGSR0_XBAR2_ENABLED 0x1

/*! Field XBAR7 - XBAR7 clock status */
#define CGU_CLKGSR0_XBAR7_POS 7
/*! Field XBAR7 - XBAR7 clock status */
#define CGU_CLKGSR0_XBAR7_MASK 0x80u
/*! Constant GATED - gated */
#define CONST_CGU_CLKGSR0_XBAR7_GATED 0x0
/*! Constant ENABLED - enabled */
#define CONST_CGU_CLKGSR0_XBAR7_ENABLED 0x1

/*! @} */

/*! \defgroup CGU_CLKGCR0_A Register CGU_CLKGCR0_A - CGU Clock Gating Control Register 0_A */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGCR0_A 0x118
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGCR0_A 0x16200118u

/*! Register Reset Value */
#define CGU_CLKGCR0_A_RST 0x00000000u

/*! Field XBAR0 - XBAR0 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR0_POS 0
/*! Field XBAR0 - XBAR0 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR0_MASK 0x1u
/*! Constant XBAR0_0 - No action */
#define CONST_CGU_CLKGCR0_A_XBAR0_XBAR0_0 0x0
/*! Constant XBAR1_1 - Enable request */
#define CONST_CGU_CLKGCR0_A_XBAR0_XBAR1_1 0x1

/*! Field XBAR1 - XBAR1 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR1_POS 1
/*! Field XBAR1 - XBAR1 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR1_MASK 0x2u
/*! Constant XBAR1_0 - No action */
#define CONST_CGU_CLKGCR0_A_XBAR1_XBAR1_0 0x0
/*! Constant XBAR1_1 - Enable request */
#define CONST_CGU_CLKGCR0_A_XBAR1_XBAR1_1 0x1

/*! Field XBAR2 - XBAR2 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR2_POS 2
/*! Field XBAR2 - XBAR2 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR2_MASK 0x4u
/*! Constant XBAR2_0 - No action */
#define CONST_CGU_CLKGCR0_A_XBAR2_XBAR2_0 0x0
/*! Constant XBAR2_1 - Enable request */
#define CONST_CGU_CLKGCR0_A_XBAR2_XBAR2_1 0x1

/*! Field XBAR7 - XBAR7 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR7_POS 7
/*! Field XBAR7 - XBAR7 Clock Enable Request */
#define CGU_CLKGCR0_A_XBAR7_MASK 0x80u
/*! Constant XBAR7_0 - No action */
#define CONST_CGU_CLKGCR0_A_XBAR7_XBAR7_0 0x0
/*! Constant XBAR7_1 - Enable request */
#define CONST_CGU_CLKGCR0_A_XBAR7_XBAR7_1 0x1

/*! @} */

/*! \defgroup CGU_CLKGCR0_B Register CGU_CLKGCR0_B - CGU Clock Gating Control Register 0_B */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGCR0_B 0x11C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGCR0_B 0x1620011Cu

/*! Register Reset Value */
#define CGU_CLKGCR0_B_RST 0x00000000u

/*! Field XBAR0 - XBAR0 Clock Disable Request */
#define CGU_CLKGCR0_B_XBAR0_POS 0
/*! Field XBAR0 - XBAR0 Clock Disable Request */
#define CGU_CLKGCR0_B_XBAR0_MASK 0x1u
/*! Constant XBAR0_0 - No action */
#define CONST_CGU_CLKGCR0_B_XBAR0_XBAR0_0 0x0
/*! Constant XBAR0_1 - Disable request */
#define CONST_CGU_CLKGCR0_B_XBAR0_XBAR0_1 0x1

/*! Field XBAR1 - XBAR1 clock Disable Request */
#define CGU_CLKGCR0_B_XBAR1_POS 1
/*! Field XBAR1 - XBAR1 clock Disable Request */
#define CGU_CLKGCR0_B_XBAR1_MASK 0x2u
/*! Constant XBAR1_0 - No action */
#define CONST_CGU_CLKGCR0_B_XBAR1_XBAR1_0 0x0
/*! Constant XBAR1_1 - Disable request */
#define CONST_CGU_CLKGCR0_B_XBAR1_XBAR1_1 0x1

/*! Field XBAR2 - XBAR2 clock Disable Request */
#define CGU_CLKGCR0_B_XBAR2_POS 2
/*! Field XBAR2 - XBAR2 clock Disable Request */
#define CGU_CLKGCR0_B_XBAR2_MASK 0x4u
/*! Constant XBAR2_0 - No action */
#define CONST_CGU_CLKGCR0_B_XBAR2_XBAR2_0 0x0
/*! Constant XBAR2_1 - Disable request */
#define CONST_CGU_CLKGCR0_B_XBAR2_XBAR2_1 0x1

/*! Field XBAR7 - XBAR7 clock Disable Request */
#define CGU_CLKGCR0_B_XBAR7_POS 7
/*! Field XBAR7 - XBAR7 clock Disable Request */
#define CGU_CLKGCR0_B_XBAR7_MASK 0x80u
/*! Constant XBAR7_0 - No action */
#define CONST_CGU_CLKGCR0_B_XBAR7_XBAR7_0 0x0
/*! Constant XBAR7_1 - Disable request */
#define CONST_CGU_CLKGCR0_B_XBAR7_XBAR7_1 0x1

/*! @} */

/*! \defgroup GGU_CLKGSR1 Register GGU_CLKGSR1 - CGU Clock Gating Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GGU_CLKGSR1 0x120
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_GGU_CLKGSR1 0x16200120u

/*! Register Reset Value */
#define GGU_CLKGSR1_RST 0xFEE67FFCu

/*! Field V_CODEC - Voice Codec Clock Status */
#define GGU_CLKGSR1_V_CODEC_POS 2
/*! Field V_CODEC - Voice Codec Clock Status */
#define GGU_CLKGSR1_V_CODEC_MASK 0x4u
/*! Constant V_0 - OFF */
#define CONST_GGU_CLKGSR1_V_CODEC_V_0 0x0
/*! Constant V_1 - ON */
#define CONST_GGU_CLKGSR1_V_CODEC_V_1 0x1

/*! Field DMA0 - DMA0 Clock Status */
#define GGU_CLKGSR1_DMA0_POS 3
/*! Field DMA0 - DMA0 Clock Status */
#define GGU_CLKGSR1_DMA0_MASK 0x8u
/*! Constant DMA0_0 - OFF */
#define CONST_GGU_CLKGSR1_DMA0_DMA0_0 0x0
/*! Constant DMA0_1 - ON */
#define CONST_GGU_CLKGSR1_DMA0_DMA0_1 0x1

/*! Field I2C0 - I2C0 Clock Status */
#define GGU_CLKGSR1_I2C0_POS 4
/*! Field I2C0 - I2C0 Clock Status */
#define GGU_CLKGSR1_I2C0_MASK 0x10u
/*! Constant I2C_0 - OFF */
#define CONST_GGU_CLKGSR1_I2C0_I2C_0 0x0
/*! Constant I2C_1 - ON */
#define CONST_GGU_CLKGSR1_I2C0_I2C_1 0x1

/*! Field I2C1 - I2C1 Clock Status */
#define GGU_CLKGSR1_I2C1_POS 5
/*! Field I2C1 - I2C1 Clock Status */
#define GGU_CLKGSR1_I2C1_MASK 0x20u
/*! Constant I2C_0 - OFF */
#define CONST_GGU_CLKGSR1_I2C1_I2C_0 0x0
/*! Constant I2C_1 - ON */
#define CONST_GGU_CLKGSR1_I2C1_I2C_1 0x1

/*! Field I2C2 - I2C2 Clock Status */
#define GGU_CLKGSR1_I2C2_POS 6
/*! Field I2C2 - I2C2 Clock Status */
#define GGU_CLKGSR1_I2C2_MASK 0x40u
/*! Constant I2C_0 - OFF */
#define CONST_GGU_CLKGSR1_I2C2_I2C_0 0x0
/*! Constant I2C_1 - ON */
#define CONST_GGU_CLKGSR1_I2C2_I2C_1 0x1

/*! Field SPI1 - SPI1 Clock Status */
#define GGU_CLKGSR1_SPI1_POS 7
/*! Field SPI1 - SPI1 Clock Status */
#define GGU_CLKGSR1_SPI1_MASK 0x80u
/*! Constant SPI1_0 - OFF */
#define CONST_GGU_CLKGSR1_SPI1_SPI1_0 0x0
/*! Constant SPI1_1 - ON */
#define CONST_GGU_CLKGSR1_SPI1_SPI1_1 0x1

/*! Field SPI0 - SPI0 Clock Status */
#define GGU_CLKGSR1_SPI0_POS 8
/*! Field SPI0 - SPI0 Clock Status */
#define GGU_CLKGSR1_SPI0_MASK 0x100u
/*! Constant SPI0_0 - OFF */
#define CONST_GGU_CLKGSR1_SPI0_SPI0_0 0x0
/*! Constant SPI0_1 - ON */
#define CONST_GGU_CLKGSR1_SPI0_SPI0_1 0x1

/*! Field QSPI - QSPI Clock Status */
#define GGU_CLKGSR1_QSPI_POS 9
/*! Field QSPI - QSPI Clock Status */
#define GGU_CLKGSR1_QSPI_MASK 0x200u
/*! Constant QSPI_0 - OFF */
#define CONST_GGU_CLKGSR1_QSPI_QSPI_0 0x0
/*! Constant QSPI_1 - ON */
#define CONST_GGU_CLKGSR1_QSPI_QSPI_1 0x1

/*! Field CQEM - CQEM Clock Status */
#define GGU_CLKGSR1_CQEM_POS 10
/*! Field CQEM - CQEM Clock Status */
#define GGU_CLKGSR1_CQEM_MASK 0x400u
/*! Constant V0 - OFF */
#define CONST_GGU_CLKGSR1_CQEM_V0 0x0
/*! Constant V1 - ON */
#define CONST_GGU_CLKGSR1_CQEM_V1 0x1

/*! Field SSO - Serial Shift Output Controller Clock Status */
#define GGU_CLKGSR1_SSO_POS 11
/*! Field SSO - Serial Shift Output Controller Clock Status */
#define GGU_CLKGSR1_SSO_MASK 0x800u
/*! Constant SSO_0 - OFF */
#define CONST_GGU_CLKGSR1_SSO_SSO_0 0x0
/*! Constant SSO_1 - ON */
#define CONST_GGU_CLKGSR1_SSO_SSO_1 0x1

/*! Field GPTC0 - GPTC 0 Clock Status */
#define GGU_CLKGSR1_GPTC0_POS 12
/*! Field GPTC0 - GPTC 0 Clock Status */
#define GGU_CLKGSR1_GPTC0_MASK 0x1000u
/*! Constant GPTC0_0 - OFF */
#define CONST_GGU_CLKGSR1_GPTC0_GPTC0_0 0x0
/*! Constant GPTC0_1 - ON */
#define CONST_GGU_CLKGSR1_GPTC0_GPTC0_1 0x1

/*! Field GPTC1 - GPTC 1 Clock Status */
#define GGU_CLKGSR1_GPTC1_POS 13
/*! Field GPTC1 - GPTC 1 Clock Status */
#define GGU_CLKGSR1_GPTC1_MASK 0x2000u
/*! Constant GPTC1_0 - OFF */
#define CONST_GGU_CLKGSR1_GPTC1_GPTC1_0 0x0
/*! Constant GPTC1_1 - ON */
#define CONST_GGU_CLKGSR1_GPTC1_GPTC1_1 0x1

/*! Field GPTC2 - GPTC 2 Clock Status */
#define GGU_CLKGSR1_GPTC2_POS 14
/*! Field GPTC2 - GPTC 2 Clock Status */
#define GGU_CLKGSR1_GPTC2_MASK 0x4000u
/*! Constant GPTC2_0 - OFF */
#define CONST_GGU_CLKGSR1_GPTC2_GPTC2_0 0x0
/*! Constant GPTC2_1 - ON */
#define CONST_GGU_CLKGSR1_GPTC2_GPTC2_1 0x1

/*! Field UART0 - UART0 Clock Status */
#define GGU_CLKGSR1_UART0_POS 17
/*! Field UART0 - UART0 Clock Status */
#define GGU_CLKGSR1_UART0_MASK 0x20000u
/*! Constant UART_0 - OFF */
#define CONST_GGU_CLKGSR1_UART0_UART_0 0x0
/*! Constant UART_1 - ON */
#define CONST_GGU_CLKGSR1_UART0_UART_1 0x1

/*! Field UART1 - UART1 Clock Status */
#define GGU_CLKGSR1_UART1_POS 18
/*! Field UART1 - UART1 Clock Status */
#define GGU_CLKGSR1_UART1_MASK 0x40000u
/*! Constant UART_0 - OFF */
#define CONST_GGU_CLKGSR1_UART1_UART_0 0x0
/*! Constant UART_1 - ON */
#define CONST_GGU_CLKGSR1_UART1_UART_1 0x1

/*! Field SECPT - Secure Platform Engine Clock Status */
#define GGU_CLKGSR1_SECPT_POS 21
/*! Field SECPT - Secure Platform Engine Clock Status */
#define GGU_CLKGSR1_SECPT_MASK 0x200000u
/*! Constant SRYP_0 - OFF */
#define CONST_GGU_CLKGSR1_SECPT_SRYP_0 0x0
/*! Constant SRYP_1 - ON */
#define CONST_GGU_CLKGSR1_SECPT_SRYP_1 0x1

/*! Field SCPU - Secure CPU Clock Status */
#define GGU_CLKGSR1_SCPU_POS 22
/*! Field SCPU - Secure CPU Clock Status */
#define GGU_CLKGSR1_SCPU_MASK 0x400000u
/*! Constant SCPU_0 - OFF */
#define CONST_GGU_CLKGSR1_SCPU_SCPU_0 0x0
/*! Constant SCPU_1 - ON */
#define CONST_GGU_CLKGSR1_SCPU_SCPU_1 0x1

/*! Field MPE - MPE Clock Status */
#define GGU_CLKGSR1_MPE_POS 23
/*! Field MPE - MPE Clock Status */
#define GGU_CLKGSR1_MPE_MASK 0x800000u
/*! Constant MPE_0 - OFF */
#define CONST_GGU_CLKGSR1_MPE_MPE_0 0x0
/*! Constant MPE_1 - ON */
#define CONST_GGU_CLKGSR1_MPE_MPE_1 0x1

/*! Field TDM - TDM Module Clock Status */
#define GGU_CLKGSR1_TDM_POS 25
/*! Field TDM - TDM Module Clock Status */
#define GGU_CLKGSR1_TDM_MASK 0x2000000u
/*! Constant TDM_0 - OFF */
#define CONST_GGU_CLKGSR1_TDM_TDM_0 0x0
/*! Constant TDM_1 - ON */
#define CONST_GGU_CLKGSR1_TDM_TDM_1 0x1

/*! Field PP - PP Module Clock Status */
#define GGU_CLKGSR1_PP_POS 26
/*! Field PP - PP Module Clock Status */
#define GGU_CLKGSR1_PP_MASK 0x4000000u
/*! Constant PP_0 - OFF */
#define CONST_GGU_CLKGSR1_PP_PP_0 0x0
/*! Constant PP_1 - ON */
#define CONST_GGU_CLKGSR1_PP_PP_1 0x1

/*! Field DMA3 - DMA3 Module Clock Status */
#define GGU_CLKGSR1_DMA3_POS 27
/*! Field DMA3 - DMA3 Module Clock Status */
#define GGU_CLKGSR1_DMA3_MASK 0x8000000u
/*! Constant DMA3_0 - OFF */
#define CONST_GGU_CLKGSR1_DMA3_DMA3_0 0x0
/*! Constant DMA3_1 - ON */
#define CONST_GGU_CLKGSR1_DMA3_DMA3_1 0x1

/*! Field SWITCH - Switch Clock Status */
#define GGU_CLKGSR1_SWITCH_POS 28
/*! Field SWITCH - Switch Clock Status */
#define GGU_CLKGSR1_SWITCH_MASK 0x10000000u
/*! Constant SWITCH_0 - OFF */
#define CONST_GGU_CLKGSR1_SWITCH_SWITCH_0 0x0
/*! Constant SWITCH_1 - ON */
#define CONST_GGU_CLKGSR1_SWITCH_SWITCH_1 0x1

/*! Field PON - PON Clock Status */
#define GGU_CLKGSR1_PON_POS 29
/*! Field PON - PON Clock Status */
#define GGU_CLKGSR1_PON_MASK 0x20000000u
/*! Constant PON_0 - OFF */
#define CONST_GGU_CLKGSR1_PON_PON_0 0x0
/*! Constant PON_1 - ON */
#define CONST_GGU_CLKGSR1_PON_PON_1 0x1

/*! Field AON - AON Clock Status */
#define GGU_CLKGSR1_AON_POS 30
/*! Field AON - AON Clock Status */
#define GGU_CLKGSR1_AON_MASK 0x40000000u
/*! Constant AON_0 - OFF */
#define CONST_GGU_CLKGSR1_AON_AON_0 0x0
/*! Constant AON_1 - ON */
#define CONST_GGU_CLKGSR1_AON_AON_1 0x1

/*! Field DDR - DDR Clock Status */
#define GGU_CLKGSR1_DDR_POS 31
/*! Field DDR - DDR Clock Status */
#define GGU_CLKGSR1_DDR_MASK 0x80000000u
/*! Constant DDR_0 - OFF */
#define CONST_GGU_CLKGSR1_DDR_DDR_0 0x0
/*! Constant DDR_1 - ON */
#define CONST_GGU_CLKGSR1_DDR_DDR_1 0x1

/*! @} */

/*! \defgroup CGU_CLKGCR1_A Register CGU_CLKGCR1_A - CGU Clock Gating Control Register 1_A */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGCR1_A 0x124
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGCR1_A 0x16200124u

/*! Register Reset Value */
#define CGU_CLKGCR1_A_RST 0x00000000u

/*! Field V_CODEC - Voice Codec Clock Enable Request */
#define CGU_CLKGCR1_A_V_CODEC_POS 2
/*! Field V_CODEC - Voice Codec Clock Enable Request */
#define CGU_CLKGCR1_A_V_CODEC_MASK 0x4u
/*! Constant V_0 - No action */
#define CONST_CGU_CLKGCR1_A_V_CODEC_V_0 0x0
/*! Constant V_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_V_CODEC_V_1 0x1

/*! Field DMA0 - DMA0 Clock Enable Request */
#define CGU_CLKGCR1_A_DMA0_POS 3
/*! Field DMA0 - DMA0 Clock Enable Request */
#define CGU_CLKGCR1_A_DMA0_MASK 0x8u
/*! Constant DMA_0 - No action */
#define CONST_CGU_CLKGCR1_A_DMA0_DMA_0 0x0
/*! Constant DMA_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_DMA0_DMA_1 0x1

/*! Field I2C0 - I2C0 Clock Enable Request */
#define CGU_CLKGCR1_A_I2C0_POS 4
/*! Field I2C0 - I2C0 Clock Enable Request */
#define CGU_CLKGCR1_A_I2C0_MASK 0x10u
/*! Constant I2C_0 - No action */
#define CONST_CGU_CLKGCR1_A_I2C0_I2C_0 0x0
/*! Constant I2C_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_I2C0_I2C_1 0x1

/*! Field I2C1 - I2C1 Clock Enable Request */
#define CGU_CLKGCR1_A_I2C1_POS 5
/*! Field I2C1 - I2C1 Clock Enable Request */
#define CGU_CLKGCR1_A_I2C1_MASK 0x20u
/*! Constant I2C_0 - No action */
#define CONST_CGU_CLKGCR1_A_I2C1_I2C_0 0x0
/*! Constant I2C_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_I2C1_I2C_1 0x1

/*! Field I2C2 - I2C2 Clock Enable Request */
#define CGU_CLKGCR1_A_I2C2_POS 6
/*! Field I2C2 - I2C2 Clock Enable Request */
#define CGU_CLKGCR1_A_I2C2_MASK 0x40u
/*! Constant I2C_0 - No action */
#define CONST_CGU_CLKGCR1_A_I2C2_I2C_0 0x0
/*! Constant I2C_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_I2C2_I2C_1 0x1

/*! Field SPI1 - SPI1 Clock Enable Request */
#define CGU_CLKGCR1_A_SPI1_POS 7
/*! Field SPI1 - SPI1 Clock Enable Request */
#define CGU_CLKGCR1_A_SPI1_MASK 0x80u
/*! Constant SPI1_0 - No action */
#define CONST_CGU_CLKGCR1_A_SPI1_SPI1_0 0x0
/*! Constant SPI1_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_SPI1_SPI1_1 0x1

/*! Field SPI0 - SPI0 Clock Enable Request */
#define CGU_CLKGCR1_A_SPI0_POS 8
/*! Field SPI0 - SPI0 Clock Enable Request */
#define CGU_CLKGCR1_A_SPI0_MASK 0x100u
/*! Constant SPI0_0 - No action */
#define CONST_CGU_CLKGCR1_A_SPI0_SPI0_0 0x0
/*! Constant SPI0_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_SPI0_SPI0_1 0x1

/*! Field QSPI - QSPI Clock Enable Request */
#define CGU_CLKGCR1_A_QSPI_POS 9
/*! Field QSPI - QSPI Clock Enable Request */
#define CGU_CLKGCR1_A_QSPI_MASK 0x200u
/*! Constant QSPI_0 - No action */
#define CONST_CGU_CLKGCR1_A_QSPI_QSPI_0 0x0
/*! Constant QSPI_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_QSPI_QSPI_1 0x1

/*! Field CQEM - Carrier Grade QoS Engine Manager Clock Enable Request */
#define CGU_CLKGCR1_A_CQEM_POS 10
/*! Field CQEM - Carrier Grade QoS Engine Manager Clock Enable Request */
#define CGU_CLKGCR1_A_CQEM_MASK 0x400u
/*! Constant CQEM_0 - No action */
#define CONST_CGU_CLKGCR1_A_CQEM_CQEM_0 0x0
/*! Constant CEQM_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_CQEM_CEQM_1 0x1

/*! Field SSO - Serial Shift Output Controller Clock Enable Request */
#define CGU_CLKGCR1_A_SSO_POS 11
/*! Field SSO - Serial Shift Output Controller Clock Enable Request */
#define CGU_CLKGCR1_A_SSO_MASK 0x800u
/*! Constant SSO_0 - No action */
#define CONST_CGU_CLKGCR1_A_SSO_SSO_0 0x0
/*! Constant SSO_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_SSO_SSO_1 0x1

/*! Field GPTC0 - GPTC 0 Clock Enable Request */
#define CGU_CLKGCR1_A_GPTC0_POS 12
/*! Field GPTC0 - GPTC 0 Clock Enable Request */
#define CGU_CLKGCR1_A_GPTC0_MASK 0x1000u
/*! Constant GPTC0_0 - No action */
#define CONST_CGU_CLKGCR1_A_GPTC0_GPTC0_0 0x0
/*! Constant GPTC0_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_GPTC0_GPTC0_1 0x1

/*! Field GPTC1 - GPTC 1 Clock Enable Request */
#define CGU_CLKGCR1_A_GPTC1_POS 13
/*! Field GPTC1 - GPTC 1 Clock Enable Request */
#define CGU_CLKGCR1_A_GPTC1_MASK 0x2000u
/*! Constant GPTC1_0 - No action */
#define CONST_CGU_CLKGCR1_A_GPTC1_GPTC1_0 0x0
/*! Constant GPTC1_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_GPTC1_GPTC1_1 0x1

/*! Field GPTC2 - GPTC 2 Clock Enable Request */
#define CGU_CLKGCR1_A_GPTC2_POS 14
/*! Field GPTC2 - GPTC 2 Clock Enable Request */
#define CGU_CLKGCR1_A_GPTC2_MASK 0x4000u
/*! Constant GPTC2_0 - No action */
#define CONST_CGU_CLKGCR1_A_GPTC2_GPTC2_0 0x0
/*! Constant GPTC2_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_GPTC2_GPTC2_1 0x1

/*! Field UART0 - UART0 Clock Enable Request */
#define CGU_CLKGCR1_A_UART0_POS 17
/*! Field UART0 - UART0 Clock Enable Request */
#define CGU_CLKGCR1_A_UART0_MASK 0x20000u
/*! Constant UART0_0 - No action */
#define CONST_CGU_CLKGCR1_A_UART0_UART0_0 0x0
/*! Constant UART0_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_UART0_UART0_1 0x1

/*! Field UART1 - UART1 Clock Enable Request */
#define CGU_CLKGCR1_A_UART1_POS 18
/*! Field UART1 - UART1 Clock Enable Request */
#define CGU_CLKGCR1_A_UART1_MASK 0x40000u
/*! Constant UART1_0 - No action */
#define CONST_CGU_CLKGCR1_A_UART1_UART1_0 0x0
/*! Constant UART1_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_UART1_UART1_1 0x1

/*! Field SECPT - Secure Platform Engine Clock Enable Request */
#define CGU_CLKGCR1_A_SECPT_POS 21
/*! Field SECPT - Secure Platform Engine Clock Enable Request */
#define CGU_CLKGCR1_A_SECPT_MASK 0x200000u
/*! Constant SRYP_0 - No action */
#define CONST_CGU_CLKGCR1_A_SECPT_SRYP_0 0x0
/*! Constant SRYP_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_SECPT_SRYP_1 0x1

/*! Field SCPU - Secure CPU Clock Enable Request */
#define CGU_CLKGCR1_A_SCPU_POS 22
/*! Field SCPU - Secure CPU Clock Enable Request */
#define CGU_CLKGCR1_A_SCPU_MASK 0x400000u
/*! Constant SCPU_0 - No action */
#define CONST_CGU_CLKGCR1_A_SCPU_SCPU_0 0x0
/*! Constant SCPU_1 - Enable */
#define CONST_CGU_CLKGCR1_A_SCPU_SCPU_1 0x1

/*! Field MPE - MPE Clock Enable Request */
#define CGU_CLKGCR1_A_MPE_POS 23
/*! Field MPE - MPE Clock Enable Request */
#define CGU_CLKGCR1_A_MPE_MASK 0x800000u
/*! Constant MPE_0 - No action */
#define CONST_CGU_CLKGCR1_A_MPE_MPE_0 0x0
/*! Constant MPE_1 - Enable */
#define CONST_CGU_CLKGCR1_A_MPE_MPE_1 0x1

/*! Field TDM - TDM Module Clock Enable Request */
#define CGU_CLKGCR1_A_TDM_POS 25
/*! Field TDM - TDM Module Clock Enable Request */
#define CGU_CLKGCR1_A_TDM_MASK 0x2000000u
/*! Constant TDM_0 - No action */
#define CONST_CGU_CLKGCR1_A_TDM_TDM_0 0x0
/*! Constant TDM_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_TDM_TDM_1 0x1

/*! Field PP - Packet Processing Engine Clock Enable Request */
#define CGU_CLKGCR1_A_PP_POS 26
/*! Field PP - Packet Processing Engine Clock Enable Request */
#define CGU_CLKGCR1_A_PP_MASK 0x4000000u
/*! Constant PP_0 - No action */
#define CONST_CGU_CLKGCR1_A_PP_PP_0 0x0
/*! Constant PP_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_PP_PP_1 0x1

/*! Field DMA3 - DMA3 Clock Enable Request */
#define CGU_CLKGCR1_A_DMA3_POS 27
/*! Field DMA3 - DMA3 Clock Enable Request */
#define CGU_CLKGCR1_A_DMA3_MASK 0x8000000u
/*! Constant DMA_0 - No action */
#define CONST_CGU_CLKGCR1_A_DMA3_DMA_0 0x0
/*! Constant DMA_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_DMA3_DMA_1 0x1

/*! Field SWITCH - Switch Clock Enable Request */
#define CGU_CLKGCR1_A_SWITCH_POS 28
/*! Field SWITCH - Switch Clock Enable Request */
#define CGU_CLKGCR1_A_SWITCH_MASK 0x10000000u
/*! Constant SWITCH_0 - No action */
#define CONST_CGU_CLKGCR1_A_SWITCH_SWITCH_0 0x0
/*! Constant SWITCH_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_SWITCH_SWITCH_1 0x1

/*! Field PON - PON Clock Enable Request */
#define CGU_CLKGCR1_A_PON_POS 29
/*! Field PON - PON Clock Enable Request */
#define CGU_CLKGCR1_A_PON_MASK 0x20000000u
/*! Constant PON_0 - No action */
#define CONST_CGU_CLKGCR1_A_PON_PON_0 0x0
/*! Constant PON_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_PON_PON_1 0x1

/*! Field AON - AON Clock Enable Request */
#define CGU_CLKGCR1_A_AON_POS 30
/*! Field AON - AON Clock Enable Request */
#define CGU_CLKGCR1_A_AON_MASK 0x40000000u
/*! Constant AON_0 - No action */
#define CONST_CGU_CLKGCR1_A_AON_AON_0 0x0
/*! Constant AON_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_AON_AON_1 0x1

/*! Field DDR - DDR Memory Scheduler Clock Enable Request */
#define CGU_CLKGCR1_A_DDR_POS 31
/*! Field DDR - DDR Memory Scheduler Clock Enable Request */
#define CGU_CLKGCR1_A_DDR_MASK 0x80000000u
/*! Constant DDR_0 - No action */
#define CONST_CGU_CLKGCR1_A_DDR_DDR_0 0x0
/*! Constant DDR_1 - Enable request */
#define CONST_CGU_CLKGCR1_A_DDR_DDR_1 0x1

/*! @} */

/*! \defgroup CGU_CLKGCR1_B Register CGU_CLKGCR1_B - CGU Clock Gating Control Register 1_B */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGCR1_B 0x128
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGCR1_B 0x16200128u

/*! Register Reset Value */
#define CGU_CLKGCR1_B_RST 0x00000000u

/*! Field V_CODEC - Voice Codec Clock Disable Request */
#define CGU_CLKGCR1_B_V_CODEC_POS 2
/*! Field V_CODEC - Voice Codec Clock Disable Request */
#define CGU_CLKGCR1_B_V_CODEC_MASK 0x4u
/*! Constant V_0 - No action */
#define CONST_CGU_CLKGCR1_B_V_CODEC_V_0 0x0
/*! Constant V_1 - Disnable request */
#define CONST_CGU_CLKGCR1_B_V_CODEC_V_1 0x1

/*! Field DMA0 - DMA0 Clock Disable Request */
#define CGU_CLKGCR1_B_DMA0_POS 3
/*! Field DMA0 - DMA0 Clock Disable Request */
#define CGU_CLKGCR1_B_DMA0_MASK 0x8u
/*! Constant DMA_0 - No action */
#define CONST_CGU_CLKGCR1_B_DMA0_DMA_0 0x0
/*! Constant DMA_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_DMA0_DMA_1 0x1

/*! Field I2C0 - I2C0 Clock Disable Request */
#define CGU_CLKGCR1_B_I2C0_POS 4
/*! Field I2C0 - I2C0 Clock Disable Request */
#define CGU_CLKGCR1_B_I2C0_MASK 0x10u
/*! Constant I2C_0 - No action */
#define CONST_CGU_CLKGCR1_B_I2C0_I2C_0 0x0
/*! Constant I2C_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_I2C0_I2C_1 0x1

/*! Field I2C1 - I2C1 Clock Disable Request */
#define CGU_CLKGCR1_B_I2C1_POS 5
/*! Field I2C1 - I2C1 Clock Disable Request */
#define CGU_CLKGCR1_B_I2C1_MASK 0x20u
/*! Constant I2C_0 - No action */
#define CONST_CGU_CLKGCR1_B_I2C1_I2C_0 0x0
/*! Constant I2C_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_I2C1_I2C_1 0x1

/*! Field I2C2 - I2C2 Clock Disable Request */
#define CGU_CLKGCR1_B_I2C2_POS 6
/*! Field I2C2 - I2C2 Clock Disable Request */
#define CGU_CLKGCR1_B_I2C2_MASK 0x40u
/*! Constant I2C_0 - No action */
#define CONST_CGU_CLKGCR1_B_I2C2_I2C_0 0x0
/*! Constant I2C_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_I2C2_I2C_1 0x1

/*! Field SPI1 - SPI1 Clock Disable Request */
#define CGU_CLKGCR1_B_SPI1_POS 7
/*! Field SPI1 - SPI1 Clock Disable Request */
#define CGU_CLKGCR1_B_SPI1_MASK 0x80u
/*! Constant SPI1_0 - No action */
#define CONST_CGU_CLKGCR1_B_SPI1_SPI1_0 0x0
/*! Constant SPI1_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_SPI1_SPI1_1 0x1

/*! Field SPI0 - SPI0 Clock Disable Request */
#define CGU_CLKGCR1_B_SPI0_POS 8
/*! Field SPI0 - SPI0 Clock Disable Request */
#define CGU_CLKGCR1_B_SPI0_MASK 0x100u
/*! Constant SPI0_0 - No action */
#define CONST_CGU_CLKGCR1_B_SPI0_SPI0_0 0x0
/*! Constant SPI0_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_SPI0_SPI0_1 0x1

/*! Field QSPI - QSPI Clock Disable Request */
#define CGU_CLKGCR1_B_QSPI_POS 9
/*! Field QSPI - QSPI Clock Disable Request */
#define CGU_CLKGCR1_B_QSPI_MASK 0x200u
/*! Constant QSPI_0 - No action */
#define CONST_CGU_CLKGCR1_B_QSPI_QSPI_0 0x0
/*! Constant QSPI_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_QSPI_QSPI_1 0x1

/*! Field CQEM - Carrier Grade QoS Engine Manager Clock Disable Request */
#define CGU_CLKGCR1_B_CQEM_POS 10
/*! Field CQEM - Carrier Grade QoS Engine Manager Clock Disable Request */
#define CGU_CLKGCR1_B_CQEM_MASK 0x400u
/*! Constant CQEM_0 - No action */
#define CONST_CGU_CLKGCR1_B_CQEM_CQEM_0 0x0
/*! Constant CEQM_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_CQEM_CEQM_1 0x1

/*! Field SSO - Serial Shift Output Controller Clock Disable Request */
#define CGU_CLKGCR1_B_SSO_POS 11
/*! Field SSO - Serial Shift Output Controller Clock Disable Request */
#define CGU_CLKGCR1_B_SSO_MASK 0x800u
/*! Constant SSO_0 - No action */
#define CONST_CGU_CLKGCR1_B_SSO_SSO_0 0x0
/*! Constant SSO_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_SSO_SSO_1 0x1

/*! Field GPTC0 - GPTC 0 Clock Disable Request */
#define CGU_CLKGCR1_B_GPTC0_POS 12
/*! Field GPTC0 - GPTC 0 Clock Disable Request */
#define CGU_CLKGCR1_B_GPTC0_MASK 0x1000u
/*! Constant GPTC0_0 - No action */
#define CONST_CGU_CLKGCR1_B_GPTC0_GPTC0_0 0x0
/*! Constant GPTC0_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_GPTC0_GPTC0_1 0x1

/*! Field GPTC1 - GPTC 1 Clock Disable Request */
#define CGU_CLKGCR1_B_GPTC1_POS 13
/*! Field GPTC1 - GPTC 1 Clock Disable Request */
#define CGU_CLKGCR1_B_GPTC1_MASK 0x2000u
/*! Constant GPTC1_0 - No action */
#define CONST_CGU_CLKGCR1_B_GPTC1_GPTC1_0 0x0
/*! Constant GPTC1_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_GPTC1_GPTC1_1 0x1

/*! Field GPTC2 - GPTC 2 Clock Disable Request */
#define CGU_CLKGCR1_B_GPTC2_POS 14
/*! Field GPTC2 - GPTC 2 Clock Disable Request */
#define CGU_CLKGCR1_B_GPTC2_MASK 0x4000u
/*! Constant GPTC2_0 - No action */
#define CONST_CGU_CLKGCR1_B_GPTC2_GPTC2_0 0x0
/*! Constant GPTC2_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_GPTC2_GPTC2_1 0x1

/*! Field UART0 - UART0 Clock Disable Request */
#define CGU_CLKGCR1_B_UART0_POS 17
/*! Field UART0 - UART0 Clock Disable Request */
#define CGU_CLKGCR1_B_UART0_MASK 0x20000u
/*! Constant UART0_0 - No action */
#define CONST_CGU_CLKGCR1_B_UART0_UART0_0 0x0
/*! Constant UART0_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_UART0_UART0_1 0x1

/*! Field UART1 - UART1 Clock Disable Request */
#define CGU_CLKGCR1_B_UART1_POS 18
/*! Field UART1 - UART1 Clock Disable Request */
#define CGU_CLKGCR1_B_UART1_MASK 0x40000u
/*! Constant UART1_0 - No action */
#define CONST_CGU_CLKGCR1_B_UART1_UART1_0 0x0
/*! Constant UART1_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_UART1_UART1_1 0x1

/*! Field SECPT - Secure Platform Engine Clock Disable Request */
#define CGU_CLKGCR1_B_SECPT_POS 21
/*! Field SECPT - Secure Platform Engine Clock Disable Request */
#define CGU_CLKGCR1_B_SECPT_MASK 0x200000u
/*! Constant SRYP_0 - No action */
#define CONST_CGU_CLKGCR1_B_SECPT_SRYP_0 0x0
/*! Constant SRYP_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_SECPT_SRYP_1 0x1

/*! Field SCPU - Secure CPU Clock Disable Request */
#define CGU_CLKGCR1_B_SCPU_POS 22
/*! Field SCPU - Secure CPU Clock Disable Request */
#define CGU_CLKGCR1_B_SCPU_MASK 0x400000u
/*! Constant SCPU_0 - No action */
#define CONST_CGU_CLKGCR1_B_SCPU_SCPU_0 0x0
/*! Constant SCPU_1 - Disable */
#define CONST_CGU_CLKGCR1_B_SCPU_SCPU_1 0x1

/*! Field MPE - MPE Clock Disable Request */
#define CGU_CLKGCR1_B_MPE_POS 23
/*! Field MPE - MPE Clock Disable Request */
#define CGU_CLKGCR1_B_MPE_MASK 0x800000u
/*! Constant MPE_0 - No action */
#define CONST_CGU_CLKGCR1_B_MPE_MPE_0 0x0
/*! Constant MPE_1 - Disable */
#define CONST_CGU_CLKGCR1_B_MPE_MPE_1 0x1

/*! Field TDM - TDM Module Clock Disable Request */
#define CGU_CLKGCR1_B_TDM_POS 25
/*! Field TDM - TDM Module Clock Disable Request */
#define CGU_CLKGCR1_B_TDM_MASK 0x2000000u
/*! Constant TDM_0 - No action */
#define CONST_CGU_CLKGCR1_B_TDM_TDM_0 0x0
/*! Constant TDM_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_TDM_TDM_1 0x1

/*! Field PP - Packet Processing Engine Clock Disable Request */
#define CGU_CLKGCR1_B_PP_POS 26
/*! Field PP - Packet Processing Engine Clock Disable Request */
#define CGU_CLKGCR1_B_PP_MASK 0x4000000u
/*! Constant PP_0 - No action */
#define CONST_CGU_CLKGCR1_B_PP_PP_0 0x0
/*! Constant PP_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_PP_PP_1 0x1

/*! Field DMA3 - DMA3 Clock Disable Request */
#define CGU_CLKGCR1_B_DMA3_POS 27
/*! Field DMA3 - DMA3 Clock Disable Request */
#define CGU_CLKGCR1_B_DMA3_MASK 0x8000000u
/*! Constant DMA_0 - No action */
#define CONST_CGU_CLKGCR1_B_DMA3_DMA_0 0x0
/*! Constant DMA_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_DMA3_DMA_1 0x1

/*! Field SWITCH - Switch Clock Disable Request */
#define CGU_CLKGCR1_B_SWITCH_POS 28
/*! Field SWITCH - Switch Clock Disable Request */
#define CGU_CLKGCR1_B_SWITCH_MASK 0x10000000u
/*! Constant SWITCH_0 - No action */
#define CONST_CGU_CLKGCR1_B_SWITCH_SWITCH_0 0x0
/*! Constant SWITCH_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_SWITCH_SWITCH_1 0x1

/*! Field PON - PON Clock Disable Request */
#define CGU_CLKGCR1_B_PON_POS 29
/*! Field PON - PON Clock Disable Request */
#define CGU_CLKGCR1_B_PON_MASK 0x20000000u
/*! Constant PON_0 - No action */
#define CONST_CGU_CLKGCR1_B_PON_PON_0 0x0
/*! Constant PON_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_PON_PON_1 0x1

/*! Field AON - AON Clock Disable Request */
#define CGU_CLKGCR1_B_AON_POS 30
/*! Field AON - AON Clock Disable Request */
#define CGU_CLKGCR1_B_AON_MASK 0x40000000u
/*! Constant AON_0 - No action */
#define CONST_CGU_CLKGCR1_B_AON_AON_0 0x0
/*! Constant AON_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_AON_AON_1 0x1

/*! Field DDR - DDR Memory Scheduler Clock Disable Request */
#define CGU_CLKGCR1_B_DDR_POS 31
/*! Field DDR - DDR Memory Scheduler Clock Disable Request */
#define CGU_CLKGCR1_B_DDR_MASK 0x80000000u
/*! Constant DDR_0 - No action */
#define CONST_CGU_CLKGCR1_B_DDR_DDR_0 0x0
/*! Constant DDR_1 - Disable request */
#define CONST_CGU_CLKGCR1_B_DDR_DDR_1 0x1

/*! @} */

/*! \defgroup CGU_CLKGSR2 Register CGU_CLKGSR2 - CGU Clock Gating Status Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGSR2 0x130
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGSR2 0x16200130u

/*! Register Reset Value */
#define CGU_CLKGSR2_RST 0x00060006u

/*! Field PCIE_CTR0 - PCIe Controller #0 Clock Status */
#define CGU_CLKGSR2_PCIE_CTR0_POS 1
/*! Field PCIE_CTR0 - PCIe Controller #0 Clock Status */
#define CGU_CLKGSR2_PCIE_CTR0_MASK 0x2u
/*! Constant PCIE_CTR0_0 - Disabled */
#define CONST_CGU_CLKGSR2_PCIE_CTR0_PCIE_CTR0_0 0x0
/*! Constant PCIE_CTR0_1 - Enabled */
#define CONST_CGU_CLKGSR2_PCIE_CTR0_PCIE_CTR0_1 0x1

/*! Field PCIE_MSI0 - PCIe MSI #0 Clock Status */
#define CGU_CLKGSR2_PCIE_MSI0_POS 2
/*! Field PCIE_MSI0 - PCIe MSI #0 Clock Status */
#define CGU_CLKGSR2_PCIE_MSI0_MASK 0x4u
/*! Constant PCIE_MSI0_0 - Disabled */
#define CONST_CGU_CLKGSR2_PCIE_MSI0_PCIE_MSI0_0 0x0
/*! Constant PCIE_MSI0_1 - Enabled */
#define CONST_CGU_CLKGSR2_PCIE_MSI0_PCIE_MSI0_1 0x1

/*! Field PCIE_PD0 - PCIe #0 Power Status PD Value */
#define CGU_CLKGSR2_PCIE_PD0_POS 7
/*! Field PCIE_PD0 - PCIe #0 Power Status PD Value */
#define CGU_CLKGSR2_PCIE_PD0_MASK 0x180u
/*! Constant PCIE_NOR - PCIe_NOR */
#define CONST_CGU_CLKGSR2_PCIE_PD0_PCIE_NOR 0x0
/*! Constant PCIE_L0S - PCIe_LOS */
#define CONST_CGU_CLKGSR2_PCIE_PD0_PCIE_L0S 0x1
/*! Constant PCIE_L1 - PCIe_L1 */
#define CONST_CGU_CLKGSR2_PCIE_PD0_PCIE_L1 0x2
/*! Constant PCIE_L3 - PCIe_L3 */
#define CONST_CGU_CLKGSR2_PCIE_PD0_PCIE_L3 0x3

/*! Field PCIE_CTR1 - PCIe Controller/PHY #1 Clock Status */
#define CGU_CLKGSR2_PCIE_CTR1_POS 17
/*! Field PCIE_CTR1 - PCIe Controller/PHY #1 Clock Status */
#define CGU_CLKGSR2_PCIE_CTR1_MASK 0x20000u
/*! Constant PCIE_CTR1_0 - Enabled */
#define CONST_CGU_CLKGSR2_PCIE_CTR1_PCIE_CTR1_0 0x0
/*! Constant PCIE_CTR1_1 - Disabled */
#define CONST_CGU_CLKGSR2_PCIE_CTR1_PCIE_CTR1_1 0x1

/*! Field PCIE_MSI1 - PCIe MSI #1 Clock Status */
#define CGU_CLKGSR2_PCIE_MSI1_POS 18
/*! Field PCIE_MSI1 - PCIe MSI #1 Clock Status */
#define CGU_CLKGSR2_PCIE_MSI1_MASK 0x40000u
/*! Constant PCIE_MSI1_0 - Disabled */
#define CONST_CGU_CLKGSR2_PCIE_MSI1_PCIE_MSI1_0 0x0
/*! Constant PCIE_MSI1_1 - Enabled */
#define CONST_CGU_CLKGSR2_PCIE_MSI1_PCIE_MSI1_1 0x1

/*! Field PCIE_PD1 - PCIe #1 Power Status PD Value */
#define CGU_CLKGSR2_PCIE_PD1_POS 23
/*! Field PCIE_PD1 - PCIe #1 Power Status PD Value */
#define CGU_CLKGSR2_PCIE_PD1_MASK 0x1800000u
/*! Constant PCIE_NOR - PCIe_NOR */
#define CONST_CGU_CLKGSR2_PCIE_PD1_PCIE_NOR 0x0
/*! Constant PCIE_L0S - PCIe_L0S */
#define CONST_CGU_CLKGSR2_PCIE_PD1_PCIE_L0S 0x1
/*! Constant PCIE_L1_1 - PCIe_L1 */
#define CONST_CGU_CLKGSR2_PCIE_PD1_PCIE_L1_1 0x2
/*! Constant PCIE_L3_1 - PCIe_L3 */
#define CONST_CGU_CLKGSR2_PCIE_PD1_PCIE_L3_1 0x3

/*! @} */

/*! \defgroup CGU_CLKGCR2_A Register CGU_CLKGCR2_A - CGU Clock Gating Control Register 2_A */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGCR2_A 0x134
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGCR2_A 0x16200134u

/*! Register Reset Value */
#define CGU_CLKGCR2_A_RST 0x00000000u

/*! Field PCIE_CTR0 - PCIe Controller 0 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_CTR0_POS 1
/*! Field PCIE_CTR0 - PCIe Controller 0 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_CTR0_MASK 0x2u
/*! Constant PCIE_CTR0 - No action */
#define CONST_CGU_CLKGCR2_A_PCIE_CTR0_PCIE_CTR0 0x0
/*! Constant PCIE_CTR0_1 - Enable request */
#define CONST_CGU_CLKGCR2_A_PCIE_CTR0_PCIE_CTR0_1 0x1

/*! Field PCIE_MSI0 - PCIe MSI 0 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_MSI0_POS 2
/*! Field PCIE_MSI0 - PCIe MSI 0 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_MSI0_MASK 0x4u
/*! Constant PCIE_MSI0_0 - No action */
#define CONST_CGU_CLKGCR2_A_PCIE_MSI0_PCIE_MSI0_0 0x0
/*! Constant PCIE_MSI0_1 - Enable request */
#define CONST_CGU_CLKGCR2_A_PCIE_MSI0_PCIE_MSI0_1 0x1

/*! Field PCIE_CTR1 - PCIe Controller 1 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_CTR1_POS 17
/*! Field PCIE_CTR1 - PCIe Controller 1 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_CTR1_MASK 0x20000u
/*! Constant PCIE_CTR1_0 - No action */
#define CONST_CGU_CLKGCR2_A_PCIE_CTR1_PCIE_CTR1_0 0x0
/*! Constant PCIE_CTR1_1 - Enable request */
#define CONST_CGU_CLKGCR2_A_PCIE_CTR1_PCIE_CTR1_1 0x1

/*! Field PCIE_MSI1 - PCIe MSI 1 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_MSI1_POS 18
/*! Field PCIE_MSI1 - PCIe MSI 1 Clock Enable Request */
#define CGU_CLKGCR2_A_PCIE_MSI1_MASK 0x40000u
/*! Constant PCIE_MSI1_0 - No action */
#define CONST_CGU_CLKGCR2_A_PCIE_MSI1_PCIE_MSI1_0 0x0
/*! Constant PCIE_MSI1_1 - Enable request */
#define CONST_CGU_CLKGCR2_A_PCIE_MSI1_PCIE_MSI1_1 0x1

/*! @} */

/*! \defgroup CGU_CLKGCR2_B Register CGU_CLKGCR2_B - CGU Clock Gating Control Register 2_B */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CLKGCR2_B 0x138
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CLKGCR2_B 0x16200138u

/*! Register Reset Value */
#define CGU_CLKGCR2_B_RST 0x00000000u

/*! Field PCIE_CTR0 - PCIe Controller 0 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_CTR0_POS 1
/*! Field PCIE_CTR0 - PCIe Controller 0 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_CTR0_MASK 0x2u
/*! Constant PCIE_CTR0_0 - No action */
#define CONST_CGU_CLKGCR2_B_PCIE_CTR0_PCIE_CTR0_0 0x0
/*! Constant PCIE_CTR0_1 - Disable request */
#define CONST_CGU_CLKGCR2_B_PCIE_CTR0_PCIE_CTR0_1 0x1

/*! Field PCIE_MSI0 - PCIe MSI 0 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_MSI0_POS 2
/*! Field PCIE_MSI0 - PCIe MSI 0 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_MSI0_MASK 0x4u
/*! Constant PCIE_MSI0_0 - No action */
#define CONST_CGU_CLKGCR2_B_PCIE_MSI0_PCIE_MSI0_0 0x0
/*! Constant PCIE_MSI0_1 - Disable request */
#define CONST_CGU_CLKGCR2_B_PCIE_MSI0_PCIE_MSI0_1 0x1

/*! Field PCIE_CTR1 - PCIe Controller1 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_CTR1_POS 17
/*! Field PCIE_CTR1 - PCIe Controller1 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_CTR1_MASK 0x20000u
/*! Constant PCIE_CTR1_0 - No action */
#define CONST_CGU_CLKGCR2_B_PCIE_CTR1_PCIE_CTR1_0 0x0
/*! Constant PCIE_CTR1_1 - Disable request */
#define CONST_CGU_CLKGCR2_B_PCIE_CTR1_PCIE_CTR1_1 0x1

/*! Field PCIE_MSI1 - PCIe MSI 1 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_MSI1_POS 18
/*! Field PCIE_MSI1 - PCIe MSI 1 Clock Disable Request */
#define CGU_CLKGCR2_B_PCIE_MSI1_MASK 0x40000u
/*! Constant PCIE_MSI1_0 - No action */
#define CONST_CGU_CLKGCR2_B_PCIE_MSI1_PCIE_MSI1_0 0x0
/*! Constant PCIE_MSI1_1 - Disable request */
#define CONST_CGU_CLKGCR2_B_PCIE_MSI1_PCIE_MSI1_1 0x1

/*! @} */

/*! \defgroup CGU_IF_CLK Register CGU_IF_CLK - Interface Clock Register */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_IF_CLK 0x140
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_IF_CLK 0x16200140u

/*! Register Reset Value */
#define CGU_IF_CLK_RST 0x00000080u

/*! Field PLL5_SRC_SEL - Select PLL5 Reference Clock Input Source */
#define CGU_IF_CLK_PLL5_SRC_SEL_POS 1
/*! Field PLL5_SRC_SEL - Select PLL5 Reference Clock Input Source */
#define CGU_IF_CLK_PLL5_SRC_SEL_MASK 0x6u
/*! Constant AON - Active Ethernet Mode */
#define CONST_CGU_IF_CLK_PLL5_SRC_SEL_AON 0x0
/*! Constant PON_1 - PON Mode 1 */
#define CONST_CGU_IF_CLK_PLL5_SRC_SEL_PON_1 0x1
/*! Constant PON_2 - PON Mode 2 */
#define CONST_CGU_IF_CLK_PLL5_SRC_SEL_PON_2 0x2

/*! Field PHY_CML1_SEL - Serdes PHY1 Internal Reference Clock CML MUX 1 Control */
#define CGU_IF_CLK_PHY_CML1_SEL_POS 3
/*! Field PHY_CML1_SEL - Serdes PHY1 Internal Reference Clock CML MUX 1 Control */
#define CGU_IF_CLK_PHY_CML1_SEL_MASK 0x8u
/*! Constant SEL0 - Select PHY1 CML MUX 0 output clock as input */
#define CONST_CGU_IF_CLK_PHY_CML1_SEL_SEL0 0x0
/*! Constant SEL1 - Select PHY0 repeater clock as input */
#define CONST_CGU_IF_CLK_PHY_CML1_SEL_SEL1 0x1

/*! Field SI_CLK_EN - SI_CLK to CPU sub system Enable */
#define CGU_IF_CLK_SI_CLK_EN_POS 7
/*! Field SI_CLK_EN - SI_CLK to CPU sub system Enable */
#define CGU_IF_CLK_SI_CLK_EN_MASK 0x80u
/*! Constant DIS - not Gated */
#define CONST_CGU_IF_CLK_SI_CLK_EN_DIS 0x0
/*! Constant ENB - Gated */
#define CONST_CGU_IF_CLK_SI_CLK_EN_ENB 0x1

/*! Field CLKOD2 - Clock Output CLK_OUT2 Select */
#define CGU_IF_CLK_CLKOD2_POS 10
/*! Field CLKOD2 - Clock Output CLK_OUT2 Select */
#define CGU_IF_CLK_CLKOD2_MASK 0xC00u
/*! Constant XTAL - XTAL */
#define CONST_CGU_IF_CLK_CLKOD2_XTAL 0x0
/*! Constant M25 - 25Mhz or 10Mhz */
#define CONST_CGU_IF_CLK_CLKOD2_M25 0x1
/*! Constant T1E1 - T1E1 clock */
#define CONST_CGU_IF_CLK_CLKOD2_T1E1 0x2
/*! Constant DPLL - Divided clock from the clock input to DPLL */
#define CONST_CGU_IF_CLK_CLKOD2_DPLL 0x3

/*! Field CLKOD1 - Clock Output CLK_OUT1 Select */
#define CGU_IF_CLK_CLKOD1_POS 12
/*! Field CLKOD1 - Clock Output CLK_OUT1 Select */
#define CGU_IF_CLK_CLKOD1_MASK 0x3000u
/*! Constant XTAL - XTAL */
#define CONST_CGU_IF_CLK_CLKOD1_XTAL 0x0
/*! Constant M25 - 25Mhz or 10Mhz */
#define CONST_CGU_IF_CLK_CLKOD1_M25 0x1
/*! Constant T1E1 - T1E1 clock */
#define CONST_CGU_IF_CLK_CLKOD1_T1E1 0x2
/*! Constant DPLL - Divided clock of DPLL clock */
#define CONST_CGU_IF_CLK_CLKOD1_DPLL 0x3

/*! Field CLKOD0 - Clock Output CLK_OUT0 Frequency Select */
#define CGU_IF_CLK_CLKOD0_POS 14
/*! Field CLKOD0 - Clock Output CLK_OUT0 Frequency Select */
#define CGU_IF_CLK_CLKOD0_MASK 0xC000u
/*! Constant RES0 - RES0 */
#define CONST_CGU_IF_CLK_CLKOD0_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_CGU_IF_CLK_CLKOD0_RES1 0x1
/*! Constant V8192 - 8.192 MHz */
#define CONST_CGU_IF_CLK_CLKOD0_V8192 0x2
/*! Constant RES3 - RES3 */
#define CONST_CGU_IF_CLK_CLKOD0_RES3 0x3

/*! Field SYNCE_OUT_SEL0 - 25Mhz or 10Mhz Selection */
#define CGU_IF_CLK_SYNCE_OUT_SEL0_POS 16
/*! Field SYNCE_OUT_SEL0 - 25Mhz or 10Mhz Selection */
#define CGU_IF_CLK_SYNCE_OUT_SEL0_MASK 0x10000u
/*! Constant M25 - 10Mhz Clock is selected for CLKOUT */
#define CONST_CGU_IF_CLK_SYNCE_OUT_SEL0_M25 0x0
/*! Constant M10 - 25Mhz Clock is selected for CLKOUT */
#define CONST_CGU_IF_CLK_SYNCE_OUT_SEL0_M10 0x1

/*! Field SYNCE_OUT_SEL1 - T1E1 Clock Selection */
#define CGU_IF_CLK_SYNCE_OUT_SEL1_POS 17
/*! Field SYNCE_OUT_SEL1 - T1E1 Clock Selection */
#define CGU_IF_CLK_SYNCE_OUT_SEL1_MASK 0x60000u
/*! Constant MD0 - 2.048Mhz Clock */
#define CONST_CGU_IF_CLK_SYNCE_OUT_SEL1_MD0 0x0
/*! Constant MD1 - 1.544Mhz Clock */
#define CONST_CGU_IF_CLK_SYNCE_OUT_SEL1_MD1 0x1
/*! Constant MD2 - 8Khz Clock from divided PLL3 output */
#define CONST_CGU_IF_CLK_SYNCE_OUT_SEL1_MD2 0x2
/*! Constant MD3 - 8Khz Clock from PON-IP NTR */
#define CONST_CGU_IF_CLK_SYNCE_OUT_SEL1_MD3 0x3

/*! Field DPLLCLK_DIV - Clock Divider for DPLL Clock to CLKOUT */
#define CGU_IF_CLK_DPLLCLK_DIV_POS 19
/*! Field DPLLCLK_DIV - Clock Divider for DPLL Clock to CLKOUT */
#define CGU_IF_CLK_DPLLCLK_DIV_MASK 0xF80000u

/*! @} */

/*! \defgroup CGU_PCMCR Register CGU_PCMCR - CGU PCM Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_PCMCR 0x144
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_PCMCR 0x16200144u

/*! Register Reset Value */
#define CGU_PCMCR_RST 0x04000000u

/*! Field FSC_INT - FSC Interrupt Type */
#define CGU_PCMCR_FSC_INT_POS 1
/*! Field FSC_INT - FSC Interrupt Type */
#define CGU_PCMCR_FSC_INT_MASK 0x2u
/*! Constant SHORT - short */
#define CONST_CGU_PCMCR_FSC_INT_SHORT 0x0
/*! Constant STICKY - sticky */
#define CONST_CGU_PCMCR_FSC_INT_STICKY 0x1

/*! Field CTM_SEL - CT Mode */
#define CGU_PCMCR_CTM_SEL_POS 4
/*! Field CTM_SEL - CT Mode */
#define CGU_PCMCR_CTM_SEL_MASK 0x10u
/*! Constant M131 - only option for taking 131.072Mhz */
#define CONST_CGU_PCMCR_CTM_SEL_M131 0x0

/*! Field FSC_DUTY - FSC Duty Cycle Configuration */
#define CGU_PCMCR_FSC_DUTY_POS 5
/*! Field FSC_DUTY - FSC Duty Cycle Configuration */
#define CGU_PCMCR_FSC_DUTY_MASK 0x20u
/*! Constant V5050 - 50:50 */
#define CONST_CGU_PCMCR_FSC_DUTY_V5050 0x0
/*! Constant DCL - DCL */
#define CONST_CGU_PCMCR_FSC_DUTY_DCL 0x1

/*! Field CT_MUX_SEL - Select input ref clk for clock tracking */
#define CGU_PCMCR_CT_MUX_SEL_POS 6
/*! Field CT_MUX_SEL - Select input ref clk for clock tracking */
#define CGU_PCMCR_CT_MUX_SEL_MASK 0xC0u
/*! Constant SYNCE - From LJ-PLL3 Output 8KHz */
#define CONST_CGU_PCMCR_CT_MUX_SEL_SYNCE 0x0
/*! Constant GPC1 - Taking NTR source from GPC1 */
#define CONST_CGU_PCMCR_CT_MUX_SEL_GPC1 0x1
/*! Constant GPC2 - Taking NTR source from GPC2 */
#define CONST_CGU_PCMCR_CT_MUX_SEL_GPC2 0x2
/*! Constant DCL - Taking NTR source from PON-IP */
#define CONST_CGU_PCMCR_CT_MUX_SEL_DCL 0x3

/*! Field CT_TEST_MUX - CT Test Mux */
#define CGU_PCMCR_CT_TEST_MUX_POS 8
/*! Field CT_TEST_MUX - CT Test Mux */
#define CGU_PCMCR_CT_TEST_MUX_MASK 0x100u
/*! Constant CT_REF - use internal generated 8Khz */
#define CONST_CGU_PCMCR_CT_TEST_MUX_CT_REF 0x0
/*! Constant DCL - use PCM Interface DCL Input */
#define CONST_CGU_PCMCR_CT_TEST_MUX_DCL 0x1

/*! Field DNTR - NTR Dividers */
#define CGU_PCMCR_DNTR_POS 11
/*! Field DNTR - NTR Dividers */
#define CGU_PCMCR_DNTR_MASK 0x1800u
/*! Constant D192 - 1.536Mhz divided by 192 */
#define CONST_CGU_PCMCR_DNTR_D192 0x0
/*! Constant D96 - 0.768Mhz divided by 96 */
#define CONST_CGU_PCMCR_DNTR_D96 0x1
/*! Constant D64 - 0.512Mhz divided by 64 */
#define CONST_CGU_PCMCR_DNTR_D64 0x2
/*! Constant D1 - no division, 8Khz */
#define CONST_CGU_PCMCR_DNTR_D1 0x3

/*! Field PCM_SL - PCM Slave Mode */
#define CGU_PCMCR_PCM_SL_POS 13
/*! Field PCM_SL - PCM Slave Mode */
#define CGU_PCMCR_PCM_SL_MASK 0x2000u
/*! Constant MASTER - Master */
#define CONST_CGU_PCMCR_PCM_SL_MASTER 0x0
/*! Constant SLAVE - Slave */
#define CONST_CGU_PCMCR_PCM_SL_SLAVE 0x1

/*! Field MUXFSC - Multiplexing Select FSC */
#define CGU_PCMCR_MUXFSC_POS 18
/*! Field MUXFSC - Multiplexing Select FSC */
#define CGU_PCMCR_MUXFSC_MASK 0x40000u
/*! Constant MASTER - Master */
#define CONST_CGU_PCMCR_MUXFSC_MASTER 0x0
/*! Constant SLAVE - Slave */
#define CONST_CGU_PCMCR_MUXFSC_SLAVE 0x1

/*! Field MUXDCL - Multiplexing Select DCL */
#define CGU_PCMCR_MUXDCL_POS 22
/*! Field MUXDCL - Multiplexing Select DCL */
#define CGU_PCMCR_MUXDCL_MASK 0x400000u
/*! Constant MASTER - Master */
#define CONST_CGU_PCMCR_MUXDCL_MASTER 0x0
/*! Constant SLAVE - Slave */
#define CONST_CGU_PCMCR_MUXDCL_SLAVE 0x1

/*! Field DCL_SEL - Frequency selection of DCL */
#define CGU_PCMCR_DCL_SEL_POS 25
/*! Field DCL_SEL - Frequency selection of DCL */
#define CGU_PCMCR_DCL_SEL_MASK 0xE000000u
/*! Constant V8192_MHZ - 8.192 MHz */
#define CONST_CGU_PCMCR_DCL_SEL_V8192_MHZ 0x0
/*! Constant V4096_MHZ - 4.096 MHz */
#define CONST_CGU_PCMCR_DCL_SEL_V4096_MHZ 0x1
/*! Constant V2048_MHZ - 2.048 MHz */
#define CONST_CGU_PCMCR_DCL_SEL_V2048_MHZ 0x2
/*! Constant V1536_MHZ - 1.536 MHz */
#define CONST_CGU_PCMCR_DCL_SEL_V1536_MHZ 0x3
/*! Constant V1024_MHZ - 1.024 MHz */
#define CONST_CGU_PCMCR_DCL_SEL_V1024_MHZ 0x4
/*! Constant V0512_MHZ - 0.512 MHz */
#define CONST_CGU_PCMCR_DCL_SEL_V0512_MHZ 0x5
/*! Constant RES - res */
#define CONST_CGU_PCMCR_DCL_SEL_RES 0x6

/*! Field INT_SEL - Select FSC Edge for interrupt generation */
#define CGU_PCMCR_INT_SEL_POS 28
/*! Field INT_SEL - Select FSC Edge for interrupt generation */
#define CGU_PCMCR_INT_SEL_MASK 0x30000000u
/*! Constant NINT - no interrupt generation */
#define CONST_CGU_PCMCR_INT_SEL_NINT 0x0
/*! Constant R - FSC rising edge to generate */
#define CONST_CGU_PCMCR_INT_SEL_R 0x1
/*! Constant F - FSC falling edge to generate */
#define CONST_CGU_PCMCR_INT_SEL_F 0x2
/*! Constant RF - Both edge to generate */
#define CONST_CGU_PCMCR_INT_SEL_RF 0x3

/*! Field CT_EN - Clock Track Enable */
#define CGU_PCMCR_CT_EN_POS 31
/*! Field CT_EN - Clock Track Enable */
#define CGU_PCMCR_CT_EN_MASK 0x80000000u
/*! Constant DISABLE - Disable */
#define CONST_CGU_PCMCR_CT_EN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_CGU_PCMCR_CT_EN_ENABLE 0x1

/*! @} */

/*! \defgroup CGU_CT_STAT Register CGU_CT_STAT - CGU Clock Tracking Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CT_STAT 0x148
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CT_STAT 0x16200148u

/*! Register Reset Value */
#define CGU_CT_STAT_RST 0x00000000u

/*! Field PDOUT - Signed Integer Value of phase discriminator output */
#define CGU_CT_STAT_PDOUT_POS 0
/*! Field PDOUT - Signed Integer Value of phase discriminator output */
#define CGU_CT_STAT_PDOUT_MASK 0x7FFFu

/*! @} */

/*! \defgroup CGU_CT_KVAL Register CGU_CT_KVAL - CGU Clock Tracking K Value Register */
/*! @{ */

/*! Register Offset (relative) */
#define CGU_CT_KVAL 0x14C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_CGU_CT_KVAL 0x1620014Cu

/*! Register Reset Value */
#define CGU_CT_KVAL_RST 0x00000000u

/*! Field PLL1K - Positive Integer Value of the output of the CT block */
#define CGU_CT_KVAL_PLL1K_POS 0
/*! Field PLL1K - Positive Integer Value of the output of the CT block */
#define CGU_CT_KVAL_PLL1K_MASK 0xFFFFFu

/*! @} */

/*! \defgroup DPLL_CFG0 Register DPLL_CFG0 - DPLL Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG0 0x200
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG0 0x16200200u

/*! Register Reset Value */
#define DPLL_CFG0_RST 0x00000000u

/*! Field DIVFIN - 16 b value for input frequency divider */
#define DPLL_CFG0_DIVFIN_POS 0
/*! Field DIVFIN - 16 b value for input frequency divider */
#define DPLL_CFG0_DIVFIN_MASK 0xFFFFu

/*! Field DIVFFB - 12b value for feedback frequency divider */
#define DPLL_CFG0_DIVFFB_POS 16
/*! Field DIVFFB - 12b value for feedback frequency divider */
#define DPLL_CFG0_DIVFFB_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup DPLL_CFG1 Register DPLL_CFG1 - DPLL Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG1 0x204
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG1 0x16200204u

/*! Register Reset Value */
#define DPLL_CFG1_RST 0x00000000u

/*! Field SYNCNTMAX - 32 b value for counting FIN pulses */
#define DPLL_CFG1_SYNCNTMAX_POS 0
/*! Field SYNCNTMAX - 32 b value for counting FIN pulses */
#define DPLL_CFG1_SYNCNTMAX_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DPLL_CFG2 Register DPLL_CFG2 - DPLL CFG2 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG2 0x208
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG2 0x16200208u

/*! Register Reset Value */
#define DPLL_CFG2_RST 0x00000000u

/*! Field CNTOFFSET - Count offset for FIN pulse counting */
#define DPLL_CFG2_CNTOFFSET_POS 0
/*! Field CNTOFFSET - Count offset for FIN pulse counting */
#define DPLL_CFG2_CNTOFFSET_MASK 0xFFFFu

/*! Field TARGETCNT - Targeted max pulse counts before FIN and FFB matches */
#define DPLL_CFG2_TARGETCNT_POS 16
/*! Field TARGETCNT - Targeted max pulse counts before FIN and FFB matches */
#define DPLL_CFG2_TARGETCNT_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup DPLL_CFG3 Register DPLL_CFG3 - DPLL CFG3 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG3 0x20C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG3 0x1620020Cu

/*! Register Reset Value */
#define DPLL_CFG3_RST 0x00000000u

/*! Field OTDLY - Delay in FFB pulses */
#define DPLL_CFG3_OTDLY_POS 0
/*! Field OTDLY - Delay in FFB pulses */
#define DPLL_CFG3_OTDLY_MASK 0xFFFFu

/*! Field ISHIFT - Gain of 2**(-ISHIFT) from P-path to I-path */
#define DPLL_CFG3_ISHIFT_POS 16
/*! Field ISHIFT - Gain of 2**(-ISHIFT) from P-path to I-path */
#define DPLL_CFG3_ISHIFT_MASK 0xF0000u

/*! Field PH_STEP_CNT - Number of steps */
#define DPLL_CFG3_PH_STEP_CNT_POS 20
/*! Field PH_STEP_CNT - Number of steps */
#define DPLL_CFG3_PH_STEP_CNT_MASK 0x1F00000u

/*! Field RST_CLKS_EXT - Reset for PLL Sync Clock Domain When RST_CLKS_OV = 1 */
#define DPLL_CFG3_RST_CLKS_EXT_POS 28
/*! Field RST_CLKS_EXT - Reset for PLL Sync Clock Domain When RST_CLKS_OV = 1 */
#define DPLL_CFG3_RST_CLKS_EXT_MASK 0x10000000u

/*! Field RST_CLKS_OV - Override signal for PLL Sync Clock domain reset signal */
#define DPLL_CFG3_RST_CLKS_OV_POS 29
/*! Field RST_CLKS_OV - Override signal for PLL Sync Clock domain reset signal */
#define DPLL_CFG3_RST_CLKS_OV_MASK 0x20000000u

/*! @} */

/*! \defgroup DPLL_CFG4 Register DPLL_CFG4 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG4 0x210
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG4 0x16200210u

/*! Register Reset Value */
#define DPLL_CFG4_RST 0x00000000u

/*! Field INT_OUT - Integer bits output */
#define DPLL_CFG4_INT_OUT_POS 0
/*! Field INT_OUT - Integer bits output */
#define DPLL_CFG4_INT_OUT_MASK 0xFFFu

/*! @} */

/*! \defgroup DPLL_CFG5 Register DPLL_CFG5 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG5 0x214
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG5 0x16200214u

/*! Register Reset Value */
#define DPLL_CFG5_RST 0x00000000u

/*! Field DELAYK - Delays for coarsal to fine comparison */
#define DPLL_CFG5_DELAYK_POS 0
/*! Field DELAYK - Delays for coarsal to fine comparison */
#define DPLL_CFG5_DELAYK_MASK 0xFFFFFFu

/*! Field RST - Reset all counters and registers */
#define DPLL_CFG5_RST_POS 24
/*! Field RST - Reset all counters and registers */
#define DPLL_CFG5_RST_MASK 0x1000000u

/*! Field RST_FFB_OV - Reset FFB logic Override */
#define DPLL_CFG5_RST_FFB_OV_POS 25
/*! Field RST_FFB_OV - Reset FFB logic Override */
#define DPLL_CFG5_RST_FFB_OV_MASK 0x2000000u

/*! Field RST_FFB_EXT - Reset for FFB domain */
#define DPLL_CFG5_RST_FFB_EXT_POS 26
/*! Field RST_FFB_EXT - Reset for FFB domain */
#define DPLL_CFG5_RST_FFB_EXT_MASK 0x4000000u

/*! Field RST_FIN_OV - Reset for FIN Domain Override */
#define DPLL_CFG5_RST_FIN_OV_POS 27
/*! Field RST_FIN_OV - Reset for FIN Domain Override */
#define DPLL_CFG5_RST_FIN_OV_MASK 0x8000000u

/*! Field RST_FIN_EXT - Reset FIN Domain */
#define DPLL_CFG5_RST_FIN_EXT_POS 28
/*! Field RST_FIN_EXT - Reset FIN Domain */
#define DPLL_CFG5_RST_FIN_EXT_MASK 0x10000000u

/*! Field FD - Force Frequency Control */
#define DPLL_CFG5_FD_POS 30
/*! Field FD - Force Frequency Control */
#define DPLL_CFG5_FD_MASK 0x40000000u

/*! Field HOLD_CTRL - DPLL Hold Control by configuration */
#define DPLL_CFG5_HOLD_CTRL_POS 31
/*! Field HOLD_CTRL - DPLL Hold Control by configuration */
#define DPLL_CFG5_HOLD_CTRL_MASK 0x80000000u

/*! @} */

/*! \defgroup DPLL_CFG6 Register DPLL_CFG6 - DPLL CFG 6 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG6 0x218
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG6 0x16200218u

/*! Register Reset Value */
#define DPLL_CFG6_RST 0x00000000u

/*! Field PRESET_EN - Load preset value */
#define DPLL_CFG6_PRESET_EN_POS 0
/*! Field PRESET_EN - Load preset value */
#define DPLL_CFG6_PRESET_EN_MASK 0x1u

/*! Field INT_PRESET - Preset Value for INT output */
#define DPLL_CFG6_INT_PRESET_POS 1
/*! Field INT_PRESET - Preset Value for INT output */
#define DPLL_CFG6_INT_PRESET_MASK 0x1FFEu

/*! @} */

/*! \defgroup DPLL_CFG7 Register DPLL_CFG7 - DPLL CFG 7 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG7 0x21C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG7 0x1620021Cu

/*! Register Reset Value */
#define DPLL_CFG7_RST 0x00000000u

/*! Field FRAC_PRESET - Preset Value for FRAC output */
#define DPLL_CFG7_FRAC_PRESET_POS 1
/*! Field FRAC_PRESET - Preset Value for FRAC output */
#define DPLL_CFG7_FRAC_PRESET_MASK 0x1FFFFFEu

/*! Field OV_FFB - DFT Override FFB */
#define DPLL_CFG7_OV_FFB_POS 25
/*! Field OV_FFB - DFT Override FFB */
#define DPLL_CFG7_OV_FFB_MASK 0x2000000u

/*! Field OV_CLKS - DFT Override CLKS */
#define DPLL_CFG7_OV_CLKS_POS 26
/*! Field OV_CLKS - DFT Override CLKS */
#define DPLL_CFG7_OV_CLKS_MASK 0x4000000u

/*! Field ONTARGETOV - Diagnostic control */
#define DPLL_CFG7_ONTARGETOV_POS 27
/*! Field ONTARGETOV - Diagnostic control */
#define DPLL_CFG7_ONTARGETOV_MASK 0x8000000u

/*! Field PROGRAM - Diagnostic control */
#define DPLL_CFG7_PROGRAM_POS 28
/*! Field PROGRAM - Diagnostic control */
#define DPLL_CFG7_PROGRAM_MASK 0x10000000u

/*! Field TRAN - Status of control transition */
#define DPLL_CFG7_TRAN_POS 29
/*! Field TRAN - Status of control transition */
#define DPLL_CFG7_TRAN_MASK 0x20000000u

/*! Field F_LOCK - Frequency Locked */
#define DPLL_CFG7_F_LOCK_POS 30
/*! Field F_LOCK - Frequency Locked */
#define DPLL_CFG7_F_LOCK_MASK 0x40000000u

/*! Field PH_LOCK - Phase locked */
#define DPLL_CFG7_PH_LOCK_POS 31
/*! Field PH_LOCK - Phase locked */
#define DPLL_CFG7_PH_LOCK_MASK 0x80000000u

/*! @} */

/*! \defgroup DPLL_CFG8 Register DPLL_CFG8 - DPLL CFG 8 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG8 0x220
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG8 0x16200220u

/*! Register Reset Value */
#define DPLL_CFG8_RST 0x00000000u

/*! Field PMP - M gain for proportional frequency comparison loop */
#define DPLL_CFG8_PMP_POS 0
/*! Field PMP - M gain for proportional frequency comparison loop */
#define DPLL_CFG8_PMP_MASK 0xFFu

/*! Field PKP - K gain for proportional frequency comparison loop */
#define DPLL_CFG8_PKP_POS 8
/*! Field PKP - K gain for proportional frequency comparison loop */
#define DPLL_CFG8_PKP_MASK 0x1F00u

/*! Field FMI - M gain for Integral frequency comparison loop */
#define DPLL_CFG8_FMI_POS 16
/*! Field FMI - M gain for Integral frequency comparison loop */
#define DPLL_CFG8_FMI_MASK 0xFF0000u

/*! Field FKI - K gain for Intergral frequency comparison loop */
#define DPLL_CFG8_FKI_POS 24
/*! Field FKI - K gain for Intergral frequency comparison loop */
#define DPLL_CFG8_FKI_MASK 0x1F000000u

/*! @} */

/*! \defgroup DPLL_CFG9 Register DPLL_CFG9 - DPLL CFG 9 */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CFG9 0x224
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CFG9 0x16200224u

/*! Register Reset Value */
#define DPLL_CFG9_RST 0x00000000u

/*! Field FRAC_OUT - Fractional bits output */
#define DPLL_CFG9_FRAC_OUT_POS 0
/*! Field FRAC_OUT - Fractional bits output */
#define DPLL_CFG9_FRAC_OUT_MASK 0xFFFFFFu

/*! @} */

/*! \defgroup DPLL_CTRL Register DPLL_CTRL - DPLL Control */
/*! @{ */

/*! Register Offset (relative) */
#define DPLL_CTRL 0x228
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_DPLL_CTRL 0x16200228u

/*! Register Reset Value */
#define DPLL_CTRL_RST 0x00000000u

/*! Field DPLL_EN - DPLL Enable */
#define DPLL_CTRL_DPLL_EN_POS 0
/*! Field DPLL_EN - DPLL Enable */
#define DPLL_CTRL_DPLL_EN_MASK 0x1u
/*! Constant DIS - Disable DPLL */
#define CONST_DPLL_CTRL_DPLL_EN_DIS 0x0
/*! Constant EN - Enable DPLL */
#define CONST_DPLL_CTRL_DPLL_EN_EN 0x1

/*! Field SYNCE_SRC_SEL - SyncE Clock Source Selection */
#define DPLL_CTRL_SYNCE_SRC_SEL_POS 4
/*! Field SYNCE_SRC_SEL - SyncE Clock Source Selection */
#define DPLL_CTRL_SYNCE_SRC_SEL_MASK 0xF0u
/*! Constant P0_CLK0 - Serdes PHY 0 Recovered Clock 0 */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_P0_CLK0 0x0
/*! Constant P0_CLK1 - Serdes PHY 0 Recovered Clock 1 */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_P0_CLK1 0x1
/*! Constant P1_CLK0 - Serdes PHY 1 Recovered Clock 0 */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_P1_CLK0 0x2
/*! Constant P1_CLK1 - Serdes PHY 1 Recovered Clock 1 */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_P1_CLK1 0x3
/*! Constant P2_CLK0 - WAN Serdes PHY Recovered Clock 0 */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_P2_CLK0 0x4
/*! Constant P2_CLK1 - WAN Serdes PHY Recovered Clock 1 */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_P2_CLK1 0x5
/*! Constant GPHY - P31G GPHY SyncE Output Clock */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_GPHY 0x6
/*! Constant GPC1 - GPC1 over GPIO Clock Input */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_GPC1 0x7
/*! Constant GPC2 - GPC2 over GPIO Clock Input */
#define CONST_DPLL_CTRL_SYNCE_SRC_SEL_GPC2 0x8

/*! Field HOLD_SRC_SEL - Hold Source Selection */
#define DPLL_CTRL_HOLD_SRC_SEL_POS 8
/*! Field HOLD_SRC_SEL - Hold Source Selection */
#define DPLL_CTRL_HOLD_SRC_SEL_MASK 0x700u
/*! Constant P0_LOS - Serdes PHY0 Loss Signal */
#define CONST_DPLL_CTRL_HOLD_SRC_SEL_P0_LOS 0x0
/*! Constant P1_LOS - Serdes PHY1 Loss Signal */
#define CONST_DPLL_CTRL_HOLD_SRC_SEL_P1_LOS 0x1
/*! Constant P2_LOS - WAN Serdes Loss Signal */
#define CONST_DPLL_CTRL_HOLD_SRC_SEL_P2_LOS 0x2
/*! Constant GPHY_NOK - GPHY Not Link Ok */
#define CONST_DPLL_CTRL_HOLD_SRC_SEL_GPHY_NOK 0x3
/*! Constant DIS - Hardware Hold Disable */
#define CONST_DPLL_CTRL_HOLD_SRC_SEL_DIS 0x5

/*! Field LOS_LOS_SEL - External LOS Enable and Invert Control */
#define DPLL_CTRL_LOS_LOS_SEL_POS 12
/*! Field LOS_LOS_SEL - External LOS Enable and Invert Control */
#define DPLL_CTRL_LOS_LOS_SEL_MASK 0x3000u
/*! Constant DIS - Disable OPT_LOS in HOLD "OR" Logic. Output is 0. */
#define CONST_DPLL_CTRL_LOS_LOS_SEL_DIS 0x0
/*! Constant EN_NOINV - Enable OPT_LOS in HOLD "OR" Logic. The external signal is not inverted. */
#define CONST_DPLL_CTRL_LOS_LOS_SEL_EN_NOINV 0x2
/*! Constant EN_INV - Enable OPT_LOS in HOLD "OR" logic. The external signal is inverted. */
#define CONST_DPLL_CTRL_LOS_LOS_SEL_EN_INV 0x3

/*! Field P0_RX_VLD - P0_RX_VLD for read */
#define DPLL_CTRL_P0_RX_VLD_POS 16
/*! Field P0_RX_VLD - P0_RX_VLD for read */
#define DPLL_CTRL_P0_RX_VLD_MASK 0x10000u

/*! Field P1_RX_VLD - P1_RX_VLD for read */
#define DPLL_CTRL_P1_RX_VLD_POS 17
/*! Field P1_RX_VLD - P1_RX_VLD for read */
#define DPLL_CTRL_P1_RX_VLD_MASK 0x20000u

/*! Field P2_RX_VLD - P2_RX_VLD for read */
#define DPLL_CTRL_P2_RX_VLD_POS 18
/*! Field P2_RX_VLD - P2_RX_VLD for read */
#define DPLL_CTRL_P2_RX_VLD_MASK 0x40000u

/*! Field GPHY_OK - GPHY link ok */
#define DPLL_CTRL_GPHY_OK_POS 19
/*! Field GPHY_OK - GPHY link ok */
#define DPLL_CTRL_GPHY_OK_MASK 0x80000u

/*! Field OPT_LOS - OPT_LOS (GPIO20) */
#define DPLL_CTRL_OPT_LOS_POS 20
/*! Field OPT_LOS - OPT_LOS (GPIO20) */
#define DPLL_CTRL_OPT_LOS_MASK 0x100000u

/*! @} */

/*! \defgroup GPHY_FCR Register GPHY_FCR - GPHY Firmware Address Offset */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY_FCR 0x800
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_GPHY_FCR 0x16200800u

/*! Register Reset Value */
#define GPHY_FCR_RST 0x00000000u

/*! Field ADDR - Firmware Address Bit 31 to 0 */
#define GPHY_FCR_ADDR_POS 0
/*! Field ADDR - Firmware Address Bit 31 to 0 */
#define GPHY_FCR_ADDR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup GPHY0_GPS0 Register GPHY0_GPS0 - GPHY0 General Pin Strapping Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY0_GPS0 0x804
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_GPHY0_GPS0 0x16200804u

/*! Register Reset Value */
#define GPHY0_GPS0_RST 0x00000000u

/*! Field GPS - General Pin Strapping bit 31 to 0 */
#define GPHY0_GPS0_GPS_POS 0
/*! Field GPS - General Pin Strapping bit 31 to 0 */
#define GPHY0_GPS0_GPS_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup GPHY0_GPS1 Register GPHY0_GPS1 - GPHY0 General Pin Strapping Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY0_GPS1 0x808
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_GPHY0_GPS1 0x16200808u

/*! Register Reset Value */
#define GPHY0_GPS1_RST 0x00000000u

/*! Field GPS - General Pin Strapping bit 47 to 32 */
#define GPHY0_GPS1_GPS_POS 0
/*! Field GPS - General Pin Strapping bit 47 to 32 */
#define GPHY0_GPS1_GPS_MASK 0xFFFFu

/*! @} */

/*! \defgroup GPHY_BFDEV Register GPHY_BFDEV - GPHY Base Frequency Deviation Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY_BFDEV 0x80C
/*! Register Offset (absolute) for 1st Instance CGU */
#define CGU_GPHY_BFDEV 0x1620080Cu

/*! Register Reset Value */
#define GPHY_BFDEV_RST 0x00000000u

/*! Field BFDEV - Base Frequency Deviation */
#define GPHY_BFDEV_BFDEV_POS 0
/*! Field BFDEV - Base Frequency Deviation */
#define GPHY_BFDEV_BFDEV_MASK 0xFFFFu

/*! @} */

/*! @} */

#endif
