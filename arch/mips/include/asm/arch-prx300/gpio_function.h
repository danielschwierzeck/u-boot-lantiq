/* Copyright (c) 2017, Intel Corporation.
 *
 * GPIO header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _GPIO_FUNCTION_H
#define _GPIO_FUNCTION_H

/*! \defgroup GPIO_FUNCTION Register File GPIO_FUNCTION - GPIO Functional Mode Register Description */
/*! @{ */

/*! Base Address of GPIO_FUNCTION */
#define GPIO_FUNCTION_MODULE_BASE 0x16300000u

/*! \defgroup OUT_0 Register OUT_0 - Data Output Register */
/*! @{ */

/*! Register Offset (relative) */
#define OUT_0 0x0
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_OUT_0 0x16300000u

/*! Register Reset Value */
#define OUT_0_RST 0x00000000u

/*! Field P0 - Bit Output Value */
#define OUT_0_P0_POS 0
/*! Field P0 - Bit Output Value */
#define OUT_0_P0_MASK 0x1u

/*! Field P1 - Bit Output Value */
#define OUT_0_P1_POS 1
/*! Field P1 - Bit Output Value */
#define OUT_0_P1_MASK 0x2u

/*! Field P2 - Bit Output Value */
#define OUT_0_P2_POS 2
/*! Field P2 - Bit Output Value */
#define OUT_0_P2_MASK 0x4u

/*! Field P3 - Bit Output Value */
#define OUT_0_P3_POS 3
/*! Field P3 - Bit Output Value */
#define OUT_0_P3_MASK 0x8u

/*! Field P4 - Bit Output Value */
#define OUT_0_P4_POS 4
/*! Field P4 - Bit Output Value */
#define OUT_0_P4_MASK 0x10u

/*! Field P5 - Bit Output Value */
#define OUT_0_P5_POS 5
/*! Field P5 - Bit Output Value */
#define OUT_0_P5_MASK 0x20u

/*! Field P6 - Bit Output Value */
#define OUT_0_P6_POS 6
/*! Field P6 - Bit Output Value */
#define OUT_0_P6_MASK 0x40u

/*! Field P7 - Bit Output Value */
#define OUT_0_P7_POS 7
/*! Field P7 - Bit Output Value */
#define OUT_0_P7_MASK 0x80u

/*! Field P8 - Bit Output Value */
#define OUT_0_P8_POS 8
/*! Field P8 - Bit Output Value */
#define OUT_0_P8_MASK 0x100u

/*! Field P9 - Bit Output Value */
#define OUT_0_P9_POS 9
/*! Field P9 - Bit Output Value */
#define OUT_0_P9_MASK 0x200u

/*! Field P10 - Bit Output Value */
#define OUT_0_P10_POS 10
/*! Field P10 - Bit Output Value */
#define OUT_0_P10_MASK 0x400u

/*! Field P11 - Bit Output Value */
#define OUT_0_P11_POS 11
/*! Field P11 - Bit Output Value */
#define OUT_0_P11_MASK 0x800u

/*! Field P12 - Bit Output Value */
#define OUT_0_P12_POS 12
/*! Field P12 - Bit Output Value */
#define OUT_0_P12_MASK 0x1000u

/*! Field P13 - Bit Output Value */
#define OUT_0_P13_POS 13
/*! Field P13 - Bit Output Value */
#define OUT_0_P13_MASK 0x2000u

/*! Field P14 - Bit Output Value */
#define OUT_0_P14_POS 14
/*! Field P14 - Bit Output Value */
#define OUT_0_P14_MASK 0x4000u

/*! Field P15 - Bit Output Value */
#define OUT_0_P15_POS 15
/*! Field P15 - Bit Output Value */
#define OUT_0_P15_MASK 0x8000u

/*! Field P16 - Bit Output Value */
#define OUT_0_P16_POS 16
/*! Field P16 - Bit Output Value */
#define OUT_0_P16_MASK 0x10000u

/*! Field P17 - Bit Output Value */
#define OUT_0_P17_POS 17
/*! Field P17 - Bit Output Value */
#define OUT_0_P17_MASK 0x20000u

/*! Field P18 - Bit Output Value */
#define OUT_0_P18_POS 18
/*! Field P18 - Bit Output Value */
#define OUT_0_P18_MASK 0x40000u

/*! Field P19 - Bit Output Value */
#define OUT_0_P19_POS 19
/*! Field P19 - Bit Output Value */
#define OUT_0_P19_MASK 0x80000u

/*! Field P20 - Bit Output Value */
#define OUT_0_P20_POS 20
/*! Field P20 - Bit Output Value */
#define OUT_0_P20_MASK 0x100000u

/*! Field P21 - Bit Output Value */
#define OUT_0_P21_POS 21
/*! Field P21 - Bit Output Value */
#define OUT_0_P21_MASK 0x200000u

/*! Field P22 - Bit Output Value */
#define OUT_0_P22_POS 22
/*! Field P22 - Bit Output Value */
#define OUT_0_P22_MASK 0x400000u

/*! Field P23 - Bit Output Value */
#define OUT_0_P23_POS 23
/*! Field P23 - Bit Output Value */
#define OUT_0_P23_MASK 0x800000u

/*! Field P24 - Bit Output Value */
#define OUT_0_P24_POS 24
/*! Field P24 - Bit Output Value */
#define OUT_0_P24_MASK 0x1000000u

/*! Field P25 - Bit Output Value */
#define OUT_0_P25_POS 25
/*! Field P25 - Bit Output Value */
#define OUT_0_P25_MASK 0x2000000u

/*! Field P26 - Bit Output Value */
#define OUT_0_P26_POS 26
/*! Field P26 - Bit Output Value */
#define OUT_0_P26_MASK 0x4000000u

/*! Field P27 - Bit Output Value */
#define OUT_0_P27_POS 27
/*! Field P27 - Bit Output Value */
#define OUT_0_P27_MASK 0x8000000u

/*! Field P28 - Bit Output Value */
#define OUT_0_P28_POS 28
/*! Field P28 - Bit Output Value */
#define OUT_0_P28_MASK 0x10000000u

/*! Field P29 - Bit Output Value */
#define OUT_0_P29_POS 29
/*! Field P29 - Bit Output Value */
#define OUT_0_P29_MASK 0x20000000u

/*! Field P30 - Bit Output Value */
#define OUT_0_P30_POS 30
/*! Field P30 - Bit Output Value */
#define OUT_0_P30_MASK 0x40000000u

/*! Field P31 - Bit Output Value */
#define OUT_0_P31_POS 31
/*! Field P31 - Bit Output Value */
#define OUT_0_P31_MASK 0x80000000u

/*! @} */

/*! \defgroup IN_0 Register IN_0 - Data Input Register */
/*! @{ */

/*! Register Offset (relative) */
#define IN_0 0x4
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IN_0 0x16300004u

/*! Register Reset Value */
#define IN_0_RST 0x00000000u

/*! Field P0 - Bit Latched Input Value */
#define IN_0_P0_POS 0
/*! Field P0 - Bit Latched Input Value */
#define IN_0_P0_MASK 0x1u

/*! Field P1 - Bit Latched Input Value */
#define IN_0_P1_POS 1
/*! Field P1 - Bit Latched Input Value */
#define IN_0_P1_MASK 0x2u

/*! Field P2 - Bit Latched Input Value */
#define IN_0_P2_POS 2
/*! Field P2 - Bit Latched Input Value */
#define IN_0_P2_MASK 0x4u

/*! Field P3 - Bit Latched Input Value */
#define IN_0_P3_POS 3
/*! Field P3 - Bit Latched Input Value */
#define IN_0_P3_MASK 0x8u

/*! Field P4 - Bit Latched Input Value */
#define IN_0_P4_POS 4
/*! Field P4 - Bit Latched Input Value */
#define IN_0_P4_MASK 0x10u

/*! Field P5 - Bit Latched Input Value */
#define IN_0_P5_POS 5
/*! Field P5 - Bit Latched Input Value */
#define IN_0_P5_MASK 0x20u

/*! Field P6 - Bit Latched Input Value */
#define IN_0_P6_POS 6
/*! Field P6 - Bit Latched Input Value */
#define IN_0_P6_MASK 0x40u

/*! Field P7 - Bit Latched Input Value */
#define IN_0_P7_POS 7
/*! Field P7 - Bit Latched Input Value */
#define IN_0_P7_MASK 0x80u

/*! Field P8 - Bit Latched Input Value */
#define IN_0_P8_POS 8
/*! Field P8 - Bit Latched Input Value */
#define IN_0_P8_MASK 0x100u

/*! Field P9 - Bit Latched Input Value */
#define IN_0_P9_POS 9
/*! Field P9 - Bit Latched Input Value */
#define IN_0_P9_MASK 0x200u

/*! Field P10 - Bit Latched Input Value */
#define IN_0_P10_POS 10
/*! Field P10 - Bit Latched Input Value */
#define IN_0_P10_MASK 0x400u

/*! Field P11 - Bit Latched Input Value */
#define IN_0_P11_POS 11
/*! Field P11 - Bit Latched Input Value */
#define IN_0_P11_MASK 0x800u

/*! Field P12 - Bit Latched Input Value */
#define IN_0_P12_POS 12
/*! Field P12 - Bit Latched Input Value */
#define IN_0_P12_MASK 0x1000u

/*! Field P13 - Bit Latched Input Value */
#define IN_0_P13_POS 13
/*! Field P13 - Bit Latched Input Value */
#define IN_0_P13_MASK 0x2000u

/*! Field P14 - Bit Latched Input Value */
#define IN_0_P14_POS 14
/*! Field P14 - Bit Latched Input Value */
#define IN_0_P14_MASK 0x4000u

/*! Field P15 - Bit Latched Input Value */
#define IN_0_P15_POS 15
/*! Field P15 - Bit Latched Input Value */
#define IN_0_P15_MASK 0x8000u

/*! Field P16 - Bit Latched Input Value */
#define IN_0_P16_POS 16
/*! Field P16 - Bit Latched Input Value */
#define IN_0_P16_MASK 0x10000u

/*! Field P17 - Bit Latched Input Value */
#define IN_0_P17_POS 17
/*! Field P17 - Bit Latched Input Value */
#define IN_0_P17_MASK 0x20000u

/*! Field P18 - Bit Latched Input Value */
#define IN_0_P18_POS 18
/*! Field P18 - Bit Latched Input Value */
#define IN_0_P18_MASK 0x40000u

/*! Field P19 - Bit Latched Input Value */
#define IN_0_P19_POS 19
/*! Field P19 - Bit Latched Input Value */
#define IN_0_P19_MASK 0x80000u

/*! Field P20 - Bit Latched Input Value */
#define IN_0_P20_POS 20
/*! Field P20 - Bit Latched Input Value */
#define IN_0_P20_MASK 0x100000u

/*! Field P21 - Bit Latched Input Value */
#define IN_0_P21_POS 21
/*! Field P21 - Bit Latched Input Value */
#define IN_0_P21_MASK 0x200000u

/*! Field P22 - Bit Latched Input Value */
#define IN_0_P22_POS 22
/*! Field P22 - Bit Latched Input Value */
#define IN_0_P22_MASK 0x400000u

/*! Field P23 - Bit Latched Input Value */
#define IN_0_P23_POS 23
/*! Field P23 - Bit Latched Input Value */
#define IN_0_P23_MASK 0x800000u

/*! Field P24 - Bit Latched Input Value */
#define IN_0_P24_POS 24
/*! Field P24 - Bit Latched Input Value */
#define IN_0_P24_MASK 0x1000000u

/*! Field P25 - Bit Latched Input Value */
#define IN_0_P25_POS 25
/*! Field P25 - Bit Latched Input Value */
#define IN_0_P25_MASK 0x2000000u

/*! Field P26 - Bit Latched Input Value */
#define IN_0_P26_POS 26
/*! Field P26 - Bit Latched Input Value */
#define IN_0_P26_MASK 0x4000000u

/*! Field P27 - Bit Latched Input Value */
#define IN_0_P27_POS 27
/*! Field P27 - Bit Latched Input Value */
#define IN_0_P27_MASK 0x8000000u

/*! Field P28 - Bit Latched Input Value */
#define IN_0_P28_POS 28
/*! Field P28 - Bit Latched Input Value */
#define IN_0_P28_MASK 0x10000000u

/*! Field P29 - Bit Latched Input Value */
#define IN_0_P29_POS 29
/*! Field P29 - Bit Latched Input Value */
#define IN_0_P29_MASK 0x20000000u

/*! Field P30 - Bit Latched Input Value */
#define IN_0_P30_POS 30
/*! Field P30 - Bit Latched Input Value */
#define IN_0_P30_MASK 0x40000000u

/*! Field P31 - Bit Latched Input Value */
#define IN_0_P31_POS 31
/*! Field P31 - Bit Latched Input Value */
#define IN_0_P31_MASK 0x80000000u

/*! @} */

/*! \defgroup DIR_0 Register DIR_0 - Direction Register */
/*! @{ */

/*! Register Offset (relative) */
#define DIR_0 0x8
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_DIR_0 0x16300008u

/*! Register Reset Value */
#define DIR_0_RST 0x00000000u

/*! Field P0 - Bit Direction */
#define DIR_0_P0_POS 0
/*! Field P0 - Bit Direction */
#define DIR_0_P0_MASK 0x1u
/*! Constant IN - Input */
#define CONST_DIR_0_P0_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P0_OUT 0x1

/*! Field P1 - Bit Direction */
#define DIR_0_P1_POS 1
/*! Field P1 - Bit Direction */
#define DIR_0_P1_MASK 0x2u
/*! Constant IN - Input */
#define CONST_DIR_0_P1_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P1_OUT 0x1

/*! Field P2 - Bit Direction */
#define DIR_0_P2_POS 2
/*! Field P2 - Bit Direction */
#define DIR_0_P2_MASK 0x4u
/*! Constant IN - Input */
#define CONST_DIR_0_P2_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P2_OUT 0x1

/*! Field P3 - Bit Direction */
#define DIR_0_P3_POS 3
/*! Field P3 - Bit Direction */
#define DIR_0_P3_MASK 0x8u
/*! Constant IN - Input */
#define CONST_DIR_0_P3_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P3_OUT 0x1

/*! Field P4 - Bit Direction */
#define DIR_0_P4_POS 4
/*! Field P4 - Bit Direction */
#define DIR_0_P4_MASK 0x10u
/*! Constant IN - Input */
#define CONST_DIR_0_P4_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P4_OUT 0x1

/*! Field P5 - Bit Direction */
#define DIR_0_P5_POS 5
/*! Field P5 - Bit Direction */
#define DIR_0_P5_MASK 0x20u
/*! Constant IN - Input */
#define CONST_DIR_0_P5_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P5_OUT 0x1

/*! Field P6 - Bit Direction */
#define DIR_0_P6_POS 6
/*! Field P6 - Bit Direction */
#define DIR_0_P6_MASK 0x40u
/*! Constant IN - Input */
#define CONST_DIR_0_P6_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P6_OUT 0x1

/*! Field P7 - Bit Direction */
#define DIR_0_P7_POS 7
/*! Field P7 - Bit Direction */
#define DIR_0_P7_MASK 0x80u
/*! Constant IN - Input */
#define CONST_DIR_0_P7_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P7_OUT 0x1

/*! Field P8 - Bit Direction */
#define DIR_0_P8_POS 8
/*! Field P8 - Bit Direction */
#define DIR_0_P8_MASK 0x100u
/*! Constant IN - Input */
#define CONST_DIR_0_P8_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P8_OUT 0x1

/*! Field P9 - Bit Direction */
#define DIR_0_P9_POS 9
/*! Field P9 - Bit Direction */
#define DIR_0_P9_MASK 0x200u
/*! Constant IN - Input */
#define CONST_DIR_0_P9_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P9_OUT 0x1

/*! Field P10 - Bit Direction */
#define DIR_0_P10_POS 10
/*! Field P10 - Bit Direction */
#define DIR_0_P10_MASK 0x400u
/*! Constant IN - Input */
#define CONST_DIR_0_P10_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P10_OUT 0x1

/*! Field P11 - Bit Direction */
#define DIR_0_P11_POS 11
/*! Field P11 - Bit Direction */
#define DIR_0_P11_MASK 0x800u
/*! Constant IN - Input */
#define CONST_DIR_0_P11_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P11_OUT 0x1

/*! Field P12 - Bit Direction */
#define DIR_0_P12_POS 12
/*! Field P12 - Bit Direction */
#define DIR_0_P12_MASK 0x1000u
/*! Constant IN - Input */
#define CONST_DIR_0_P12_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P12_OUT 0x1

/*! Field P13 - Bit Direction */
#define DIR_0_P13_POS 13
/*! Field P13 - Bit Direction */
#define DIR_0_P13_MASK 0x2000u
/*! Constant IN - Input */
#define CONST_DIR_0_P13_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P13_OUT 0x1

/*! Field P14 - Bit Direction */
#define DIR_0_P14_POS 14
/*! Field P14 - Bit Direction */
#define DIR_0_P14_MASK 0x4000u
/*! Constant IN - Input */
#define CONST_DIR_0_P14_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P14_OUT 0x1

/*! Field P15 - Bit Direction */
#define DIR_0_P15_POS 15
/*! Field P15 - Bit Direction */
#define DIR_0_P15_MASK 0x8000u
/*! Constant IN - Input */
#define CONST_DIR_0_P15_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P15_OUT 0x1

/*! Field P16 - Bit Direction */
#define DIR_0_P16_POS 16
/*! Field P16 - Bit Direction */
#define DIR_0_P16_MASK 0x10000u
/*! Constant IN - Input */
#define CONST_DIR_0_P16_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P16_OUT 0x1

/*! Field P17 - Bit Direction */
#define DIR_0_P17_POS 17
/*! Field P17 - Bit Direction */
#define DIR_0_P17_MASK 0x20000u
/*! Constant IN - Input */
#define CONST_DIR_0_P17_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P17_OUT 0x1

/*! Field P18 - Bit Direction */
#define DIR_0_P18_POS 18
/*! Field P18 - Bit Direction */
#define DIR_0_P18_MASK 0x40000u
/*! Constant IN - Input */
#define CONST_DIR_0_P18_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P18_OUT 0x1

/*! Field P19 - Bit Direction */
#define DIR_0_P19_POS 19
/*! Field P19 - Bit Direction */
#define DIR_0_P19_MASK 0x80000u
/*! Constant IN - Input */
#define CONST_DIR_0_P19_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P19_OUT 0x1

/*! Field P20 - Bit Direction */
#define DIR_0_P20_POS 20
/*! Field P20 - Bit Direction */
#define DIR_0_P20_MASK 0x100000u
/*! Constant IN - Input */
#define CONST_DIR_0_P20_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P20_OUT 0x1

/*! Field P21 - Bit Direction */
#define DIR_0_P21_POS 21
/*! Field P21 - Bit Direction */
#define DIR_0_P21_MASK 0x200000u
/*! Constant IN - Input */
#define CONST_DIR_0_P21_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P21_OUT 0x1

/*! Field P22 - Bit Direction */
#define DIR_0_P22_POS 22
/*! Field P22 - Bit Direction */
#define DIR_0_P22_MASK 0x400000u
/*! Constant IN - Input */
#define CONST_DIR_0_P22_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P22_OUT 0x1

/*! Field P23 - Bit Direction */
#define DIR_0_P23_POS 23
/*! Field P23 - Bit Direction */
#define DIR_0_P23_MASK 0x800000u
/*! Constant IN - Input */
#define CONST_DIR_0_P23_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P23_OUT 0x1

/*! Field P24 - Bit Direction */
#define DIR_0_P24_POS 24
/*! Field P24 - Bit Direction */
#define DIR_0_P24_MASK 0x1000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P24_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P24_OUT 0x1

/*! Field P25 - Bit Direction */
#define DIR_0_P25_POS 25
/*! Field P25 - Bit Direction */
#define DIR_0_P25_MASK 0x2000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P25_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P25_OUT 0x1

/*! Field P26 - Bit Direction */
#define DIR_0_P26_POS 26
/*! Field P26 - Bit Direction */
#define DIR_0_P26_MASK 0x4000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P26_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P26_OUT 0x1

/*! Field P27 - Bit Direction */
#define DIR_0_P27_POS 27
/*! Field P27 - Bit Direction */
#define DIR_0_P27_MASK 0x8000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P27_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P27_OUT 0x1

/*! Field P28 - Bit Direction */
#define DIR_0_P28_POS 28
/*! Field P28 - Bit Direction */
#define DIR_0_P28_MASK 0x10000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P28_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P28_OUT 0x1

/*! Field P29 - Bit Direction */
#define DIR_0_P29_POS 29
/*! Field P29 - Bit Direction */
#define DIR_0_P29_MASK 0x20000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P29_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P29_OUT 0x1

/*! Field P30 - Bit Direction */
#define DIR_0_P30_POS 30
/*! Field P30 - Bit Direction */
#define DIR_0_P30_MASK 0x40000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P30_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P30_OUT 0x1

/*! Field P31 - Bit Direction */
#define DIR_0_P31_POS 31
/*! Field P31 - Bit Direction */
#define DIR_0_P31_MASK 0x80000000u
/*! Constant IN - Input */
#define CONST_DIR_0_P31_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_0_P31_OUT 0x1

/*! @} */

/*! \defgroup EXINTCR00 Register EXINTCR00 - External Interrupt Control Register 00 */
/*! @{ */

/*! Register Offset (relative) */
#define EXINTCR00 0x18
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_EXINTCR00 0x16300018u

/*! Register Reset Value */
#define EXINTCR00_RST 0x00000000u

/*! Field P0 - Bit External Interrupt Control */
#define EXINTCR00_P0_POS 0
/*! Field P0 - Bit External Interrupt Control */
#define EXINTCR00_P0_MASK 0x1u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P0_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P0_NEG 0x1

/*! Field P1 - Bit External Interrupt Control */
#define EXINTCR00_P1_POS 1
/*! Field P1 - Bit External Interrupt Control */
#define EXINTCR00_P1_MASK 0x2u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P1_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P1_NEG 0x1

/*! Field P2 - Bit External Interrupt Control */
#define EXINTCR00_P2_POS 2
/*! Field P2 - Bit External Interrupt Control */
#define EXINTCR00_P2_MASK 0x4u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P2_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P2_NEG 0x1

/*! Field P3 - Bit External Interrupt Control */
#define EXINTCR00_P3_POS 3
/*! Field P3 - Bit External Interrupt Control */
#define EXINTCR00_P3_MASK 0x8u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P3_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P3_NEG 0x1

/*! Field P4 - Bit External Interrupt Control */
#define EXINTCR00_P4_POS 4
/*! Field P4 - Bit External Interrupt Control */
#define EXINTCR00_P4_MASK 0x10u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P4_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P4_NEG 0x1

/*! Field P5 - Bit External Interrupt Control */
#define EXINTCR00_P5_POS 5
/*! Field P5 - Bit External Interrupt Control */
#define EXINTCR00_P5_MASK 0x20u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P5_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P5_NEG 0x1

/*! Field P6 - Bit External Interrupt Control */
#define EXINTCR00_P6_POS 6
/*! Field P6 - Bit External Interrupt Control */
#define EXINTCR00_P6_MASK 0x40u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P6_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P6_NEG 0x1

/*! Field P7 - Bit External Interrupt Control */
#define EXINTCR00_P7_POS 7
/*! Field P7 - Bit External Interrupt Control */
#define EXINTCR00_P7_MASK 0x80u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P7_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P7_NEG 0x1

/*! Field P8 - Bit External Interrupt Control */
#define EXINTCR00_P8_POS 8
/*! Field P8 - Bit External Interrupt Control */
#define EXINTCR00_P8_MASK 0x100u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P8_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P8_NEG 0x1

/*! Field P9 - Bit External Interrupt Control */
#define EXINTCR00_P9_POS 9
/*! Field P9 - Bit External Interrupt Control */
#define EXINTCR00_P9_MASK 0x200u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P9_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P9_NEG 0x1

/*! Field P10 - Bit External Interrupt Control */
#define EXINTCR00_P10_POS 10
/*! Field P10 - Bit External Interrupt Control */
#define EXINTCR00_P10_MASK 0x400u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P10_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P10_NEG 0x1

/*! Field P11 - Bit External Interrupt Control */
#define EXINTCR00_P11_POS 11
/*! Field P11 - Bit External Interrupt Control */
#define EXINTCR00_P11_MASK 0x800u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P11_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P11_NEG 0x1

/*! Field P12 - Bit External Interrupt Control */
#define EXINTCR00_P12_POS 12
/*! Field P12 - Bit External Interrupt Control */
#define EXINTCR00_P12_MASK 0x1000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P12_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P12_NEG 0x1

/*! Field P13 - Bit External Interrupt Control */
#define EXINTCR00_P13_POS 13
/*! Field P13 - Bit External Interrupt Control */
#define EXINTCR00_P13_MASK 0x2000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P13_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P13_NEG 0x1

/*! Field P14 - Bit External Interrupt Control */
#define EXINTCR00_P14_POS 14
/*! Field P14 - Bit External Interrupt Control */
#define EXINTCR00_P14_MASK 0x4000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P14_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P14_NEG 0x1

/*! Field P15 - Bit External Interrupt Control */
#define EXINTCR00_P15_POS 15
/*! Field P15 - Bit External Interrupt Control */
#define EXINTCR00_P15_MASK 0x8000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P15_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P15_NEG 0x1

/*! Field P16 - Bit External Interrupt Control */
#define EXINTCR00_P16_POS 16
/*! Field P16 - Bit External Interrupt Control */
#define EXINTCR00_P16_MASK 0x10000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P16_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P16_NEG 0x1

/*! Field P17 - Bit External Interrupt Control */
#define EXINTCR00_P17_POS 17
/*! Field P17 - Bit External Interrupt Control */
#define EXINTCR00_P17_MASK 0x20000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P17_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P17_NEG 0x1

/*! Field P18 - Bit External Interrupt Control */
#define EXINTCR00_P18_POS 18
/*! Field P18 - Bit External Interrupt Control */
#define EXINTCR00_P18_MASK 0x40000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P18_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P18_NEG 0x1

/*! Field P19 - Bit External Interrupt Control */
#define EXINTCR00_P19_POS 19
/*! Field P19 - Bit External Interrupt Control */
#define EXINTCR00_P19_MASK 0x80000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P19_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P19_NEG 0x1

/*! Field P20 - Bit External Interrupt Control */
#define EXINTCR00_P20_POS 20
/*! Field P20 - Bit External Interrupt Control */
#define EXINTCR00_P20_MASK 0x100000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P20_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P20_NEG 0x1

/*! Field P21 - Bit External Interrupt Control */
#define EXINTCR00_P21_POS 21
/*! Field P21 - Bit External Interrupt Control */
#define EXINTCR00_P21_MASK 0x200000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P21_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P21_NEG 0x1

/*! Field P22 - Bit External Interrupt Control */
#define EXINTCR00_P22_POS 22
/*! Field P22 - Bit External Interrupt Control */
#define EXINTCR00_P22_MASK 0x400000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P22_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P22_NEG 0x1

/*! Field P23 - Bit External Interrupt Control */
#define EXINTCR00_P23_POS 23
/*! Field P23 - Bit External Interrupt Control */
#define EXINTCR00_P23_MASK 0x800000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P23_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P23_NEG 0x1

/*! Field P24 - Bit External Interrupt Control */
#define EXINTCR00_P24_POS 24
/*! Field P24 - Bit External Interrupt Control */
#define EXINTCR00_P24_MASK 0x1000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P24_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P24_NEG 0x1

/*! Field P25 - Bit External Interrupt Control */
#define EXINTCR00_P25_POS 25
/*! Field P25 - Bit External Interrupt Control */
#define EXINTCR00_P25_MASK 0x2000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P25_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P25_NEG 0x1

/*! Field P26 - Bit External Interrupt Control */
#define EXINTCR00_P26_POS 26
/*! Field P26 - Bit External Interrupt Control */
#define EXINTCR00_P26_MASK 0x4000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P26_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P26_NEG 0x1

/*! Field P27 - Bit External Interrupt Control */
#define EXINTCR00_P27_POS 27
/*! Field P27 - Bit External Interrupt Control */
#define EXINTCR00_P27_MASK 0x8000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P27_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P27_NEG 0x1

/*! Field P28 - Bit External Interrupt Control */
#define EXINTCR00_P28_POS 28
/*! Field P28 - Bit External Interrupt Control */
#define EXINTCR00_P28_MASK 0x10000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P28_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P28_NEG 0x1

/*! Field P29 - Bit External Interrupt Control */
#define EXINTCR00_P29_POS 29
/*! Field P29 - Bit External Interrupt Control */
#define EXINTCR00_P29_MASK 0x20000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P29_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P29_NEG 0x1

/*! Field P30 - Bit External Interrupt Control */
#define EXINTCR00_P30_POS 30
/*! Field P30 - Bit External Interrupt Control */
#define EXINTCR00_P30_MASK 0x40000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P30_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P30_NEG 0x1

/*! Field P31 - Bit External Interrupt Control */
#define EXINTCR00_P31_POS 31
/*! Field P31 - Bit External Interrupt Control */
#define EXINTCR00_P31_MASK 0x80000000u
/*! Constant POS - Positive */
#define CONST_EXINTCR00_P31_POS 0x0
/*! Constant NEG - Negative */
#define CONST_EXINTCR00_P31_NEG 0x1

/*! @} */

/*! \defgroup EXINTCR01 Register EXINTCR01 - External Interrupt Control Register 01 */
/*! @{ */

/*! Register Offset (relative) */
#define EXINTCR01 0x1C
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_EXINTCR01 0x1630001Cu

/*! Register Reset Value */
#define EXINTCR01_RST 0x00000000u

/*! Field P0 - Bit External Interrupt Control 1 */
#define EXINTCR01_P0_POS 0
/*! Field P0 - Bit External Interrupt Control 1 */
#define EXINTCR01_P0_MASK 0x1u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P0_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P0_BOTH 0x1

/*! Field P1 - Bit External Interrupt Control 1 */
#define EXINTCR01_P1_POS 1
/*! Field P1 - Bit External Interrupt Control 1 */
#define EXINTCR01_P1_MASK 0x2u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P1_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P1_BOTH 0x1

/*! Field P2 - Bit External Interrupt Control 1 */
#define EXINTCR01_P2_POS 2
/*! Field P2 - Bit External Interrupt Control 1 */
#define EXINTCR01_P2_MASK 0x4u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P2_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P2_BOTH 0x1

/*! Field P3 - Bit External Interrupt Control 1 */
#define EXINTCR01_P3_POS 3
/*! Field P3 - Bit External Interrupt Control 1 */
#define EXINTCR01_P3_MASK 0x8u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P3_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P3_BOTH 0x1

/*! Field P4 - Bit External Interrupt Control 1 */
#define EXINTCR01_P4_POS 4
/*! Field P4 - Bit External Interrupt Control 1 */
#define EXINTCR01_P4_MASK 0x10u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P4_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P4_BOTH 0x1

/*! Field P5 - Bit External Interrupt Control 1 */
#define EXINTCR01_P5_POS 5
/*! Field P5 - Bit External Interrupt Control 1 */
#define EXINTCR01_P5_MASK 0x20u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P5_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P5_BOTH 0x1

/*! Field P6 - Bit External Interrupt Control 1 */
#define EXINTCR01_P6_POS 6
/*! Field P6 - Bit External Interrupt Control 1 */
#define EXINTCR01_P6_MASK 0x40u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P6_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P6_BOTH 0x1

/*! Field P7 - Bit External Interrupt Control 1 */
#define EXINTCR01_P7_POS 7
/*! Field P7 - Bit External Interrupt Control 1 */
#define EXINTCR01_P7_MASK 0x80u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P7_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P7_BOTH 0x1

/*! Field P8 - Bit External Interrupt Control 1 */
#define EXINTCR01_P8_POS 8
/*! Field P8 - Bit External Interrupt Control 1 */
#define EXINTCR01_P8_MASK 0x100u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P8_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P8_BOTH 0x1

/*! Field P9 - Bit External Interrupt Control 1 */
#define EXINTCR01_P9_POS 9
/*! Field P9 - Bit External Interrupt Control 1 */
#define EXINTCR01_P9_MASK 0x200u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P9_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P9_BOTH 0x1

/*! Field P10 - Bit External Interrupt Control 1 */
#define EXINTCR01_P10_POS 10
/*! Field P10 - Bit External Interrupt Control 1 */
#define EXINTCR01_P10_MASK 0x400u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P10_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P10_BOTH 0x1

/*! Field P11 - Bit External Interrupt Control 1 */
#define EXINTCR01_P11_POS 11
/*! Field P11 - Bit External Interrupt Control 1 */
#define EXINTCR01_P11_MASK 0x800u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P11_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P11_BOTH 0x1

/*! Field P12 - Bit External Interrupt Control 1 */
#define EXINTCR01_P12_POS 12
/*! Field P12 - Bit External Interrupt Control 1 */
#define EXINTCR01_P12_MASK 0x1000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P12_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P12_BOTH 0x1

/*! Field P13 - Bit External Interrupt Control 1 */
#define EXINTCR01_P13_POS 13
/*! Field P13 - Bit External Interrupt Control 1 */
#define EXINTCR01_P13_MASK 0x2000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P13_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P13_BOTH 0x1

/*! Field P14 - Bit External Interrupt Control 1 */
#define EXINTCR01_P14_POS 14
/*! Field P14 - Bit External Interrupt Control 1 */
#define EXINTCR01_P14_MASK 0x4000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P14_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P14_BOTH 0x1

/*! Field P15 - Bit External Interrupt Control 1 */
#define EXINTCR01_P15_POS 15
/*! Field P15 - Bit External Interrupt Control 1 */
#define EXINTCR01_P15_MASK 0x8000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P15_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P15_BOTH 0x1

/*! Field P16 - Bit External Interrupt Control 1 */
#define EXINTCR01_P16_POS 16
/*! Field P16 - Bit External Interrupt Control 1 */
#define EXINTCR01_P16_MASK 0x10000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P16_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P16_BOTH 0x1

/*! Field P17 - Bit External Interrupt Control 1 */
#define EXINTCR01_P17_POS 17
/*! Field P17 - Bit External Interrupt Control 1 */
#define EXINTCR01_P17_MASK 0x20000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P17_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P17_BOTH 0x1

/*! Field P18 - Bit External Interrupt Control 1 */
#define EXINTCR01_P18_POS 18
/*! Field P18 - Bit External Interrupt Control 1 */
#define EXINTCR01_P18_MASK 0x40000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P18_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P18_BOTH 0x1

/*! Field P19 - Bit External Interrupt Control 1 */
#define EXINTCR01_P19_POS 19
/*! Field P19 - Bit External Interrupt Control 1 */
#define EXINTCR01_P19_MASK 0x80000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P19_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P19_BOTH 0x1

/*! Field P20 - Bit External Interrupt Control 1 */
#define EXINTCR01_P20_POS 20
/*! Field P20 - Bit External Interrupt Control 1 */
#define EXINTCR01_P20_MASK 0x100000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P20_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P20_BOTH 0x1

/*! Field P21 - Bit External Interrupt Control 1 */
#define EXINTCR01_P21_POS 21
/*! Field P21 - Bit External Interrupt Control 1 */
#define EXINTCR01_P21_MASK 0x200000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P21_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P21_BOTH 0x1

/*! Field P22 - Bit External Interrupt Control 1 */
#define EXINTCR01_P22_POS 22
/*! Field P22 - Bit External Interrupt Control 1 */
#define EXINTCR01_P22_MASK 0x400000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P22_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P22_BOTH 0x1

/*! Field P23 - Bit External Interrupt Control 1 */
#define EXINTCR01_P23_POS 23
/*! Field P23 - Bit External Interrupt Control 1 */
#define EXINTCR01_P23_MASK 0x800000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P23_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P23_BOTH 0x1

/*! Field P24 - Bit External Interrupt Control 1 */
#define EXINTCR01_P24_POS 24
/*! Field P24 - Bit External Interrupt Control 1 */
#define EXINTCR01_P24_MASK 0x1000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P24_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P24_BOTH 0x1

/*! Field P25 - Bit External Interrupt Control 1 */
#define EXINTCR01_P25_POS 25
/*! Field P25 - Bit External Interrupt Control 1 */
#define EXINTCR01_P25_MASK 0x2000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P25_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P25_BOTH 0x1

/*! Field P26 - Bit External Interrupt Control 1 */
#define EXINTCR01_P26_POS 26
/*! Field P26 - Bit External Interrupt Control 1 */
#define EXINTCR01_P26_MASK 0x4000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P26_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P26_BOTH 0x1

/*! Field P27 - Bit External Interrupt Control 1 */
#define EXINTCR01_P27_POS 27
/*! Field P27 - Bit External Interrupt Control 1 */
#define EXINTCR01_P27_MASK 0x8000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P27_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P27_BOTH 0x1

/*! Field P28 - Bit External Interrupt Control 1 */
#define EXINTCR01_P28_POS 28
/*! Field P28 - Bit External Interrupt Control 1 */
#define EXINTCR01_P28_MASK 0x10000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P28_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P28_BOTH 0x1

/*! Field P29 - Bit External Interrupt Control 1 */
#define EXINTCR01_P29_POS 29
/*! Field P29 - Bit External Interrupt Control 1 */
#define EXINTCR01_P29_MASK 0x20000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P29_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P29_BOTH 0x1

/*! Field P30 - Bit External Interrupt Control 1 */
#define EXINTCR01_P30_POS 30
/*! Field P30 - Bit External Interrupt Control 1 */
#define EXINTCR01_P30_MASK 0x40000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P30_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P30_BOTH 0x1

/*! Field P31 - Bit External Interrupt Control 1 */
#define EXINTCR01_P31_POS 31
/*! Field P31 - Bit External Interrupt Control 1 */
#define EXINTCR01_P31_MASK 0x80000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR01_P31_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR01_P31_BOTH 0x1

/*! @} */

/*! \defgroup IRNCR_0 Register IRNCR_0 - Interrupt Node Capture Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNCR_0 0x20
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNCR_0 0x16300020u

/*! Register Reset Value */
#define IRNCR_0_RST 0x00000000u

/*! Field P0 - Interrupt Detection Control */
#define IRNCR_0_P0_POS 0
/*! Field P0 - Interrupt Detection Control */
#define IRNCR_0_P0_MASK 0x1u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P0_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P0_INT 0x1

/*! Field P1 - Interrupt Detection Control */
#define IRNCR_0_P1_POS 1
/*! Field P1 - Interrupt Detection Control */
#define IRNCR_0_P1_MASK 0x2u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P1_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P1_INT 0x1

/*! Field P2 - Interrupt Detection Control */
#define IRNCR_0_P2_POS 2
/*! Field P2 - Interrupt Detection Control */
#define IRNCR_0_P2_MASK 0x4u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P2_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P2_INT 0x1

/*! Field P3 - Interrupt Detection Control */
#define IRNCR_0_P3_POS 3
/*! Field P3 - Interrupt Detection Control */
#define IRNCR_0_P3_MASK 0x8u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P3_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P3_INT 0x1

/*! Field P4 - Interrupt Detection Control */
#define IRNCR_0_P4_POS 4
/*! Field P4 - Interrupt Detection Control */
#define IRNCR_0_P4_MASK 0x10u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P4_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P4_INT 0x1

/*! Field P5 - Interrupt Detection Control */
#define IRNCR_0_P5_POS 5
/*! Field P5 - Interrupt Detection Control */
#define IRNCR_0_P5_MASK 0x20u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P5_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P5_INT 0x1

/*! Field P6 - Interrupt Detection Control */
#define IRNCR_0_P6_POS 6
/*! Field P6 - Interrupt Detection Control */
#define IRNCR_0_P6_MASK 0x40u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P6_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P6_INT 0x1

/*! Field P7 - Interrupt Detection Control */
#define IRNCR_0_P7_POS 7
/*! Field P7 - Interrupt Detection Control */
#define IRNCR_0_P7_MASK 0x80u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P7_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P7_INT 0x1

/*! Field P8 - Interrupt Detection Control */
#define IRNCR_0_P8_POS 8
/*! Field P8 - Interrupt Detection Control */
#define IRNCR_0_P8_MASK 0x100u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P8_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P8_INT 0x1

/*! Field P9 - Interrupt Detection Control */
#define IRNCR_0_P9_POS 9
/*! Field P9 - Interrupt Detection Control */
#define IRNCR_0_P9_MASK 0x200u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P9_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P9_INT 0x1

/*! Field P10 - Interrupt Detection Control */
#define IRNCR_0_P10_POS 10
/*! Field P10 - Interrupt Detection Control */
#define IRNCR_0_P10_MASK 0x400u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P10_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P10_INT 0x1

/*! Field P11 - Interrupt Detection Control */
#define IRNCR_0_P11_POS 11
/*! Field P11 - Interrupt Detection Control */
#define IRNCR_0_P11_MASK 0x800u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P11_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P11_INT 0x1

/*! Field P12 - Interrupt Detection Control */
#define IRNCR_0_P12_POS 12
/*! Field P12 - Interrupt Detection Control */
#define IRNCR_0_P12_MASK 0x1000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P12_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P12_INT 0x1

/*! Field P13 - Interrupt Detection Control */
#define IRNCR_0_P13_POS 13
/*! Field P13 - Interrupt Detection Control */
#define IRNCR_0_P13_MASK 0x2000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P13_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P13_INT 0x1

/*! Field P14 - Interrupt Detection Control */
#define IRNCR_0_P14_POS 14
/*! Field P14 - Interrupt Detection Control */
#define IRNCR_0_P14_MASK 0x4000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P14_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P14_INT 0x1

/*! Field P15 - Interrupt Detection Control */
#define IRNCR_0_P15_POS 15
/*! Field P15 - Interrupt Detection Control */
#define IRNCR_0_P15_MASK 0x8000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P15_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P15_INT 0x1

/*! Field P16 - Interrupt Detection Control */
#define IRNCR_0_P16_POS 16
/*! Field P16 - Interrupt Detection Control */
#define IRNCR_0_P16_MASK 0x10000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P16_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P16_INT 0x1

/*! Field P17 - Interrupt Detection Control */
#define IRNCR_0_P17_POS 17
/*! Field P17 - Interrupt Detection Control */
#define IRNCR_0_P17_MASK 0x20000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P17_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P17_INT 0x1

/*! Field P18 - Interrupt Detection Control */
#define IRNCR_0_P18_POS 18
/*! Field P18 - Interrupt Detection Control */
#define IRNCR_0_P18_MASK 0x40000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P18_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P18_INT 0x1

/*! Field P19 - Interrupt Detection Control */
#define IRNCR_0_P19_POS 19
/*! Field P19 - Interrupt Detection Control */
#define IRNCR_0_P19_MASK 0x80000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P19_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P19_INT 0x1

/*! Field P20 - Interrupt Detection Control */
#define IRNCR_0_P20_POS 20
/*! Field P20 - Interrupt Detection Control */
#define IRNCR_0_P20_MASK 0x100000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P20_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P20_INT 0x1

/*! Field P21 - Interrupt Detection Control */
#define IRNCR_0_P21_POS 21
/*! Field P21 - Interrupt Detection Control */
#define IRNCR_0_P21_MASK 0x200000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P21_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P21_INT 0x1

/*! Field P22 - Interrupt Detection Control */
#define IRNCR_0_P22_POS 22
/*! Field P22 - Interrupt Detection Control */
#define IRNCR_0_P22_MASK 0x400000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P22_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P22_INT 0x1

/*! Field P23 - Interrupt Detection Control */
#define IRNCR_0_P23_POS 23
/*! Field P23 - Interrupt Detection Control */
#define IRNCR_0_P23_MASK 0x800000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P23_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P23_INT 0x1

/*! Field P24 - Interrupt Detection Control */
#define IRNCR_0_P24_POS 24
/*! Field P24 - Interrupt Detection Control */
#define IRNCR_0_P24_MASK 0x1000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P24_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P24_INT 0x1

/*! Field P25 - Interrupt Detection Control */
#define IRNCR_0_P25_POS 25
/*! Field P25 - Interrupt Detection Control */
#define IRNCR_0_P25_MASK 0x2000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P25_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P25_INT 0x1

/*! Field P26 - Interrupt Detection Control */
#define IRNCR_0_P26_POS 26
/*! Field P26 - Interrupt Detection Control */
#define IRNCR_0_P26_MASK 0x4000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P26_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P26_INT 0x1

/*! Field P27 - Interrupt Detection Control */
#define IRNCR_0_P27_POS 27
/*! Field P27 - Interrupt Detection Control */
#define IRNCR_0_P27_MASK 0x8000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P27_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P27_INT 0x1

/*! Field P28 - Interrupt Detection Control */
#define IRNCR_0_P28_POS 28
/*! Field P28 - Interrupt Detection Control */
#define IRNCR_0_P28_MASK 0x10000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P28_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P28_INT 0x1

/*! Field P29 - Interrupt Detection Control */
#define IRNCR_0_P29_POS 29
/*! Field P29 - Interrupt Detection Control */
#define IRNCR_0_P29_MASK 0x20000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P29_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P29_INT 0x1

/*! Field P30 - Interrupt Detection Control */
#define IRNCR_0_P30_POS 30
/*! Field P30 - Interrupt Detection Control */
#define IRNCR_0_P30_MASK 0x40000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P30_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P30_INT 0x1

/*! Field P31 - Interrupt Detection Control */
#define IRNCR_0_P31_POS 31
/*! Field P31 - Interrupt Detection Control */
#define IRNCR_0_P31_MASK 0x80000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_0_P31_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_0_P31_INT 0x1

/*! @} */

/*! \defgroup IRNICR_0 Register IRNICR_0 - IRN Interrupt Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNICR_0 0x24
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNICR_0 0x16300024u

/*! Register Reset Value */
#define IRNICR_0_RST 0x00000000u

/*! Field P0 - Pin Interrupt */
#define IRNICR_0_P0_POS 0
/*! Field P0 - Pin Interrupt */
#define IRNICR_0_P0_MASK 0x1u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P0_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P0_INTSET 0x1

/*! Field P1 - Pin Interrupt */
#define IRNICR_0_P1_POS 1
/*! Field P1 - Pin Interrupt */
#define IRNICR_0_P1_MASK 0x2u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P1_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P1_INTSET 0x1

/*! Field P2 - Pin Interrupt */
#define IRNICR_0_P2_POS 2
/*! Field P2 - Pin Interrupt */
#define IRNICR_0_P2_MASK 0x4u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P2_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P2_INTSET 0x1

/*! Field P3 - Pin Interrupt */
#define IRNICR_0_P3_POS 3
/*! Field P3 - Pin Interrupt */
#define IRNICR_0_P3_MASK 0x8u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P3_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P3_INTSET 0x1

/*! Field P4 - Pin Interrupt */
#define IRNICR_0_P4_POS 4
/*! Field P4 - Pin Interrupt */
#define IRNICR_0_P4_MASK 0x10u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P4_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P4_INTSET 0x1

/*! Field P5 - Pin Interrupt */
#define IRNICR_0_P5_POS 5
/*! Field P5 - Pin Interrupt */
#define IRNICR_0_P5_MASK 0x20u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P5_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P5_INTSET 0x1

/*! Field P6 - Pin Interrupt */
#define IRNICR_0_P6_POS 6
/*! Field P6 - Pin Interrupt */
#define IRNICR_0_P6_MASK 0x40u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P6_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P6_INTSET 0x1

/*! Field P7 - Pin Interrupt */
#define IRNICR_0_P7_POS 7
/*! Field P7 - Pin Interrupt */
#define IRNICR_0_P7_MASK 0x80u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P7_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P7_INTSET 0x1

/*! Field P8 - Pin Interrupt */
#define IRNICR_0_P8_POS 8
/*! Field P8 - Pin Interrupt */
#define IRNICR_0_P8_MASK 0x100u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P8_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P8_INTSET 0x1

/*! Field P9 - Pin Interrupt */
#define IRNICR_0_P9_POS 9
/*! Field P9 - Pin Interrupt */
#define IRNICR_0_P9_MASK 0x200u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P9_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P9_INTSET 0x1

/*! Field P10 - Pin Interrupt */
#define IRNICR_0_P10_POS 10
/*! Field P10 - Pin Interrupt */
#define IRNICR_0_P10_MASK 0x400u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P10_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P10_INTSET 0x1

/*! Field P11 - Pin Interrupt */
#define IRNICR_0_P11_POS 11
/*! Field P11 - Pin Interrupt */
#define IRNICR_0_P11_MASK 0x800u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P11_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P11_INTSET 0x1

/*! Field P12 - Pin Interrupt */
#define IRNICR_0_P12_POS 12
/*! Field P12 - Pin Interrupt */
#define IRNICR_0_P12_MASK 0x1000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P12_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P12_INTSET 0x1

/*! Field P13 - Pin Interrupt */
#define IRNICR_0_P13_POS 13
/*! Field P13 - Pin Interrupt */
#define IRNICR_0_P13_MASK 0x2000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P13_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P13_INTSET 0x1

/*! Field P14 - Pin Interrupt */
#define IRNICR_0_P14_POS 14
/*! Field P14 - Pin Interrupt */
#define IRNICR_0_P14_MASK 0x4000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P14_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P14_INTSET 0x1

/*! Field P15 - Pin Interrupt */
#define IRNICR_0_P15_POS 15
/*! Field P15 - Pin Interrupt */
#define IRNICR_0_P15_MASK 0x8000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P15_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P15_INTSET 0x1

/*! Field P16 - Pin Interrupt */
#define IRNICR_0_P16_POS 16
/*! Field P16 - Pin Interrupt */
#define IRNICR_0_P16_MASK 0x10000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P16_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P16_INTSET 0x1

/*! Field P17 - Pin Interrupt */
#define IRNICR_0_P17_POS 17
/*! Field P17 - Pin Interrupt */
#define IRNICR_0_P17_MASK 0x20000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P17_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P17_INTSET 0x1

/*! Field P18 - Pin Interrupt */
#define IRNICR_0_P18_POS 18
/*! Field P18 - Pin Interrupt */
#define IRNICR_0_P18_MASK 0x40000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P18_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P18_INTSET 0x1

/*! Field P19 - Pin Interrupt */
#define IRNICR_0_P19_POS 19
/*! Field P19 - Pin Interrupt */
#define IRNICR_0_P19_MASK 0x80000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P19_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P19_INTSET 0x1

/*! Field P20 - Pin Interrupt */
#define IRNICR_0_P20_POS 20
/*! Field P20 - Pin Interrupt */
#define IRNICR_0_P20_MASK 0x100000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P20_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P20_INTSET 0x1

/*! Field P21 - Pin Interrupt */
#define IRNICR_0_P21_POS 21
/*! Field P21 - Pin Interrupt */
#define IRNICR_0_P21_MASK 0x200000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P21_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P21_INTSET 0x1

/*! Field P22 - Pin Interrupt */
#define IRNICR_0_P22_POS 22
/*! Field P22 - Pin Interrupt */
#define IRNICR_0_P22_MASK 0x400000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P22_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P22_INTSET 0x1

/*! Field P23 - Pin Interrupt */
#define IRNICR_0_P23_POS 23
/*! Field P23 - Pin Interrupt */
#define IRNICR_0_P23_MASK 0x800000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P23_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P23_INTSET 0x1

/*! Field P24 - Pin Interrupt */
#define IRNICR_0_P24_POS 24
/*! Field P24 - Pin Interrupt */
#define IRNICR_0_P24_MASK 0x1000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P24_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P24_INTSET 0x1

/*! Field P25 - Pin Interrupt */
#define IRNICR_0_P25_POS 25
/*! Field P25 - Pin Interrupt */
#define IRNICR_0_P25_MASK 0x2000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P25_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P25_INTSET 0x1

/*! Field P26 - Pin Interrupt */
#define IRNICR_0_P26_POS 26
/*! Field P26 - Pin Interrupt */
#define IRNICR_0_P26_MASK 0x4000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P26_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P26_INTSET 0x1

/*! Field P27 - Pin Interrupt */
#define IRNICR_0_P27_POS 27
/*! Field P27 - Pin Interrupt */
#define IRNICR_0_P27_MASK 0x8000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P27_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P27_INTSET 0x1

/*! Field P28 - Pin Interrupt */
#define IRNICR_0_P28_POS 28
/*! Field P28 - Pin Interrupt */
#define IRNICR_0_P28_MASK 0x10000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P28_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P28_INTSET 0x1

/*! Field P29 - Pin Interrupt */
#define IRNICR_0_P29_POS 29
/*! Field P29 - Pin Interrupt */
#define IRNICR_0_P29_MASK 0x20000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P29_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P29_INTSET 0x1

/*! Field P30 - Pin Interrupt */
#define IRNICR_0_P30_POS 30
/*! Field P30 - Pin Interrupt */
#define IRNICR_0_P30_MASK 0x40000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P30_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P30_INTSET 0x1

/*! Field P31 - Pin Interrupt */
#define IRNICR_0_P31_POS 31
/*! Field P31 - Pin Interrupt */
#define IRNICR_0_P31_MASK 0x80000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_0_P31_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_0_P31_INTSET 0x1

/*! @} */

/*! \defgroup IRNEN_0 Register IRNEN_0 - IRN Interrupt Enable Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNEN_0 0x28
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNEN_0 0x16300028u

/*! Register Reset Value */
#define IRNEN_0_RST 0x00000000u

/*! Field P0 - Pin Interrupt Enable */
#define IRNEN_0_P0_POS 0
/*! Field P0 - Pin Interrupt Enable */
#define IRNEN_0_P0_MASK 0x1u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P0_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P0_EN 0x1

/*! Field P1 - Pin Interrupt Enable */
#define IRNEN_0_P1_POS 1
/*! Field P1 - Pin Interrupt Enable */
#define IRNEN_0_P1_MASK 0x2u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P1_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P1_EN 0x1

/*! Field P2 - Pin Interrupt Enable */
#define IRNEN_0_P2_POS 2
/*! Field P2 - Pin Interrupt Enable */
#define IRNEN_0_P2_MASK 0x4u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P2_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P2_EN 0x1

/*! Field P3 - Pin Interrupt Enable */
#define IRNEN_0_P3_POS 3
/*! Field P3 - Pin Interrupt Enable */
#define IRNEN_0_P3_MASK 0x8u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P3_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P3_EN 0x1

/*! Field P4 - Pin Interrupt Enable */
#define IRNEN_0_P4_POS 4
/*! Field P4 - Pin Interrupt Enable */
#define IRNEN_0_P4_MASK 0x10u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P4_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P4_EN 0x1

/*! Field P5 - Pin Interrupt Enable */
#define IRNEN_0_P5_POS 5
/*! Field P5 - Pin Interrupt Enable */
#define IRNEN_0_P5_MASK 0x20u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P5_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P5_EN 0x1

/*! Field P6 - Pin Interrupt Enable */
#define IRNEN_0_P6_POS 6
/*! Field P6 - Pin Interrupt Enable */
#define IRNEN_0_P6_MASK 0x40u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P6_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P6_EN 0x1

/*! Field P7 - Pin Interrupt Enable */
#define IRNEN_0_P7_POS 7
/*! Field P7 - Pin Interrupt Enable */
#define IRNEN_0_P7_MASK 0x80u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P7_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P7_EN 0x1

/*! Field P8 - Pin Interrupt Enable */
#define IRNEN_0_P8_POS 8
/*! Field P8 - Pin Interrupt Enable */
#define IRNEN_0_P8_MASK 0x100u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P8_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P8_EN 0x1

/*! Field P9 - Pin Interrupt Enable */
#define IRNEN_0_P9_POS 9
/*! Field P9 - Pin Interrupt Enable */
#define IRNEN_0_P9_MASK 0x200u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P9_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P9_EN 0x1

/*! Field P10 - Pin Interrupt Enable */
#define IRNEN_0_P10_POS 10
/*! Field P10 - Pin Interrupt Enable */
#define IRNEN_0_P10_MASK 0x400u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P10_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P10_EN 0x1

/*! Field P11 - Pin Interrupt Enable */
#define IRNEN_0_P11_POS 11
/*! Field P11 - Pin Interrupt Enable */
#define IRNEN_0_P11_MASK 0x800u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P11_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P11_EN 0x1

/*! Field P12 - Pin Interrupt Enable */
#define IRNEN_0_P12_POS 12
/*! Field P12 - Pin Interrupt Enable */
#define IRNEN_0_P12_MASK 0x1000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P12_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P12_EN 0x1

/*! Field P13 - Pin Interrupt Enable */
#define IRNEN_0_P13_POS 13
/*! Field P13 - Pin Interrupt Enable */
#define IRNEN_0_P13_MASK 0x2000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P13_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P13_EN 0x1

/*! Field P14 - Pin Interrupt Enable */
#define IRNEN_0_P14_POS 14
/*! Field P14 - Pin Interrupt Enable */
#define IRNEN_0_P14_MASK 0x4000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P14_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P14_EN 0x1

/*! Field P15 - Pin Interrupt Enable */
#define IRNEN_0_P15_POS 15
/*! Field P15 - Pin Interrupt Enable */
#define IRNEN_0_P15_MASK 0x8000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P15_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P15_EN 0x1

/*! Field P16 - Pin Interrupt Enable */
#define IRNEN_0_P16_POS 16
/*! Field P16 - Pin Interrupt Enable */
#define IRNEN_0_P16_MASK 0x10000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P16_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P16_EN 0x1

/*! Field P17 - Pin Interrupt Enable */
#define IRNEN_0_P17_POS 17
/*! Field P17 - Pin Interrupt Enable */
#define IRNEN_0_P17_MASK 0x20000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P17_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P17_EN 0x1

/*! Field P18 - Pin Interrupt Enable */
#define IRNEN_0_P18_POS 18
/*! Field P18 - Pin Interrupt Enable */
#define IRNEN_0_P18_MASK 0x40000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P18_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P18_EN 0x1

/*! Field P19 - Pin Interrupt Enable */
#define IRNEN_0_P19_POS 19
/*! Field P19 - Pin Interrupt Enable */
#define IRNEN_0_P19_MASK 0x80000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P19_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P19_EN 0x1

/*! Field P20 - Pin Interrupt Enable */
#define IRNEN_0_P20_POS 20
/*! Field P20 - Pin Interrupt Enable */
#define IRNEN_0_P20_MASK 0x100000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P20_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P20_EN 0x1

/*! Field P21 - Pin Interrupt Enable */
#define IRNEN_0_P21_POS 21
/*! Field P21 - Pin Interrupt Enable */
#define IRNEN_0_P21_MASK 0x200000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P21_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P21_EN 0x1

/*! Field P22 - Pin Interrupt Enable */
#define IRNEN_0_P22_POS 22
/*! Field P22 - Pin Interrupt Enable */
#define IRNEN_0_P22_MASK 0x400000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P22_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P22_EN 0x1

/*! Field P23 - Pin Interrupt Enable */
#define IRNEN_0_P23_POS 23
/*! Field P23 - Pin Interrupt Enable */
#define IRNEN_0_P23_MASK 0x800000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P23_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P23_EN 0x1

/*! Field P24 - Pin Interrupt Enable */
#define IRNEN_0_P24_POS 24
/*! Field P24 - Pin Interrupt Enable */
#define IRNEN_0_P24_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P24_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P24_EN 0x1

/*! Field P25 - Pin Interrupt Enable */
#define IRNEN_0_P25_POS 25
/*! Field P25 - Pin Interrupt Enable */
#define IRNEN_0_P25_MASK 0x2000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P25_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P25_EN 0x1

/*! Field P26 - Pin Interrupt Enable */
#define IRNEN_0_P26_POS 26
/*! Field P26 - Pin Interrupt Enable */
#define IRNEN_0_P26_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P26_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P26_EN 0x1

/*! Field P27 - Pin Interrupt Enable */
#define IRNEN_0_P27_POS 27
/*! Field P27 - Pin Interrupt Enable */
#define IRNEN_0_P27_MASK 0x8000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P27_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P27_EN 0x1

/*! Field P28 - Pin Interrupt Enable */
#define IRNEN_0_P28_POS 28
/*! Field P28 - Pin Interrupt Enable */
#define IRNEN_0_P28_MASK 0x10000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P28_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P28_EN 0x1

/*! Field P29 - Pin Interrupt Enable */
#define IRNEN_0_P29_POS 29
/*! Field P29 - Pin Interrupt Enable */
#define IRNEN_0_P29_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P29_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P29_EN 0x1

/*! Field P30 - Pin Interrupt Enable */
#define IRNEN_0_P30_POS 30
/*! Field P30 - Pin Interrupt Enable */
#define IRNEN_0_P30_MASK 0x40000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P30_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P30_EN 0x1

/*! Field P31 - Pin Interrupt Enable */
#define IRNEN_0_P31_POS 31
/*! Field P31 - Pin Interrupt Enable */
#define IRNEN_0_P31_MASK 0x80000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_0_P31_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_0_P31_EN 0x1

/*! @} */

/*! \defgroup IRNCFG_0 Register IRNCFG_0 - IRN Interrupt Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNCFG_0 0x2C
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNCFG_0 0x1630002Cu

/*! Register Reset Value */
#define IRNCFG_0_RST 0x00000000u

/*! Field P0 - Interrupt mode */
#define IRNCFG_0_P0_POS 0
/*! Field P0 - Interrupt mode */
#define IRNCFG_0_P0_MASK 0x1u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P0_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P0_LEVEL 0x1

/*! Field P1 - Interrupt mode */
#define IRNCFG_0_P1_POS 1
/*! Field P1 - Interrupt mode */
#define IRNCFG_0_P1_MASK 0x2u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P1_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P1_LEVEL 0x1

/*! Field P2 - Interrupt mode */
#define IRNCFG_0_P2_POS 2
/*! Field P2 - Interrupt mode */
#define IRNCFG_0_P2_MASK 0x4u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P2_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P2_LEVEL 0x1

/*! Field P3 - Interrupt mode */
#define IRNCFG_0_P3_POS 3
/*! Field P3 - Interrupt mode */
#define IRNCFG_0_P3_MASK 0x8u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P3_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P3_LEVEL 0x1

/*! Field P4 - Interrupt mode */
#define IRNCFG_0_P4_POS 4
/*! Field P4 - Interrupt mode */
#define IRNCFG_0_P4_MASK 0x10u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P4_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P4_LEVEL 0x1

/*! Field P5 - Interrupt mode */
#define IRNCFG_0_P5_POS 5
/*! Field P5 - Interrupt mode */
#define IRNCFG_0_P5_MASK 0x20u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P5_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P5_LEVEL 0x1

/*! Field P6 - Interrupt mode */
#define IRNCFG_0_P6_POS 6
/*! Field P6 - Interrupt mode */
#define IRNCFG_0_P6_MASK 0x40u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P6_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P6_LEVEL 0x1

/*! Field P7 - Interrupt mode */
#define IRNCFG_0_P7_POS 7
/*! Field P7 - Interrupt mode */
#define IRNCFG_0_P7_MASK 0x80u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P7_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P7_LEVEL 0x1

/*! Field P8 - Interrupt mode */
#define IRNCFG_0_P8_POS 8
/*! Field P8 - Interrupt mode */
#define IRNCFG_0_P8_MASK 0x100u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P8_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P8_LEVEL 0x1

/*! Field P9 - Interrupt mode */
#define IRNCFG_0_P9_POS 9
/*! Field P9 - Interrupt mode */
#define IRNCFG_0_P9_MASK 0x200u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P9_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P9_LEVEL 0x1

/*! Field P10 - Interrupt mode */
#define IRNCFG_0_P10_POS 10
/*! Field P10 - Interrupt mode */
#define IRNCFG_0_P10_MASK 0x400u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P10_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P10_LEVEL 0x1

/*! Field P11 - Interrupt mode */
#define IRNCFG_0_P11_POS 11
/*! Field P11 - Interrupt mode */
#define IRNCFG_0_P11_MASK 0x800u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P11_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P11_LEVEL 0x1

/*! Field P12 - Interrupt mode */
#define IRNCFG_0_P12_POS 12
/*! Field P12 - Interrupt mode */
#define IRNCFG_0_P12_MASK 0x1000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P12_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P12_LEVEL 0x1

/*! Field P13 - Interrupt mode */
#define IRNCFG_0_P13_POS 13
/*! Field P13 - Interrupt mode */
#define IRNCFG_0_P13_MASK 0x2000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P13_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P13_LEVEL 0x1

/*! Field P14 - Interrupt mode */
#define IRNCFG_0_P14_POS 14
/*! Field P14 - Interrupt mode */
#define IRNCFG_0_P14_MASK 0x4000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P14_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P14_LEVEL 0x1

/*! Field P15 - Interrupt mode */
#define IRNCFG_0_P15_POS 15
/*! Field P15 - Interrupt mode */
#define IRNCFG_0_P15_MASK 0x8000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P15_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P15_LEVEL 0x1

/*! Field P16 - Interrupt mode */
#define IRNCFG_0_P16_POS 16
/*! Field P16 - Interrupt mode */
#define IRNCFG_0_P16_MASK 0x10000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P16_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P16_LEVEL 0x1

/*! Field P17 - Interrupt mode */
#define IRNCFG_0_P17_POS 17
/*! Field P17 - Interrupt mode */
#define IRNCFG_0_P17_MASK 0x20000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P17_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P17_LEVEL 0x1

/*! Field P18 - Interrupt mode */
#define IRNCFG_0_P18_POS 18
/*! Field P18 - Interrupt mode */
#define IRNCFG_0_P18_MASK 0x40000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P18_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P18_LEVEL 0x1

/*! Field P19 - Interrupt mode */
#define IRNCFG_0_P19_POS 19
/*! Field P19 - Interrupt mode */
#define IRNCFG_0_P19_MASK 0x80000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P19_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P19_LEVEL 0x1

/*! Field P20 - Interrupt mode */
#define IRNCFG_0_P20_POS 20
/*! Field P20 - Interrupt mode */
#define IRNCFG_0_P20_MASK 0x100000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P20_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P20_LEVEL 0x1

/*! Field P21 - Interrupt mode */
#define IRNCFG_0_P21_POS 21
/*! Field P21 - Interrupt mode */
#define IRNCFG_0_P21_MASK 0x200000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P21_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P21_LEVEL 0x1

/*! Field P22 - Interrupt mode */
#define IRNCFG_0_P22_POS 22
/*! Field P22 - Interrupt mode */
#define IRNCFG_0_P22_MASK 0x400000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P22_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P22_LEVEL 0x1

/*! Field P23 - Interrupt mode */
#define IRNCFG_0_P23_POS 23
/*! Field P23 - Interrupt mode */
#define IRNCFG_0_P23_MASK 0x800000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P23_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P23_LEVEL 0x1

/*! Field P24 - Interrupt mode */
#define IRNCFG_0_P24_POS 24
/*! Field P24 - Interrupt mode */
#define IRNCFG_0_P24_MASK 0x1000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P24_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P24_LEVEL 0x1

/*! Field P25 - Interrupt mode */
#define IRNCFG_0_P25_POS 25
/*! Field P25 - Interrupt mode */
#define IRNCFG_0_P25_MASK 0x2000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P25_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P25_LEVEL 0x1

/*! Field P26 - Interrupt mode */
#define IRNCFG_0_P26_POS 26
/*! Field P26 - Interrupt mode */
#define IRNCFG_0_P26_MASK 0x4000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P26_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P26_LEVEL 0x1

/*! Field P27 - Interrupt mode */
#define IRNCFG_0_P27_POS 27
/*! Field P27 - Interrupt mode */
#define IRNCFG_0_P27_MASK 0x8000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P27_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P27_LEVEL 0x1

/*! Field P28 - Interrupt mode */
#define IRNCFG_0_P28_POS 28
/*! Field P28 - Interrupt mode */
#define IRNCFG_0_P28_MASK 0x10000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P28_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P28_LEVEL 0x1

/*! Field P29 - Interrupt mode */
#define IRNCFG_0_P29_POS 29
/*! Field P29 - Interrupt mode */
#define IRNCFG_0_P29_MASK 0x20000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P29_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P29_LEVEL 0x1

/*! Field P30 - Interrupt mode */
#define IRNCFG_0_P30_POS 30
/*! Field P30 - Interrupt mode */
#define IRNCFG_0_P30_MASK 0x40000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P30_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P30_LEVEL 0x1

/*! Field P31 - Interrupt mode */
#define IRNCFG_0_P31_POS 31
/*! Field P31 - Interrupt mode */
#define IRNCFG_0_P31_MASK 0x80000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_0_P31_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_0_P31_LEVEL 0x1

/*! @} */

/*! \defgroup IRNENSET_0 Register IRNENSET_0 - IRN Interrupt Enable Set Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNENSET_0 0x30
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNENSET_0 0x16300030u

/*! Register Reset Value */
#define IRNENSET_0_RST 0x00000000u

/*! Field P0 - Interrupt enable */
#define IRNENSET_0_P0_POS 0
/*! Field P0 - Interrupt enable */
#define IRNENSET_0_P0_MASK 0x1u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P0_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P0_EN 0x1

/*! Field P1 - Interrupt enable */
#define IRNENSET_0_P1_POS 1
/*! Field P1 - Interrupt enable */
#define IRNENSET_0_P1_MASK 0x2u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P1_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P1_EN 0x1

/*! Field P2 - Interrupt enable */
#define IRNENSET_0_P2_POS 2
/*! Field P2 - Interrupt enable */
#define IRNENSET_0_P2_MASK 0x4u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P2_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P2_EN 0x1

/*! Field P3 - Interrupt enable */
#define IRNENSET_0_P3_POS 3
/*! Field P3 - Interrupt enable */
#define IRNENSET_0_P3_MASK 0x8u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P3_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P3_EN 0x1

/*! Field P4 - Interrupt enable */
#define IRNENSET_0_P4_POS 4
/*! Field P4 - Interrupt enable */
#define IRNENSET_0_P4_MASK 0x10u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P4_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P4_EN 0x1

/*! Field P5 - Interrupt enable */
#define IRNENSET_0_P5_POS 5
/*! Field P5 - Interrupt enable */
#define IRNENSET_0_P5_MASK 0x20u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P5_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P5_EN 0x1

/*! Field P6 - Interrupt enable */
#define IRNENSET_0_P6_POS 6
/*! Field P6 - Interrupt enable */
#define IRNENSET_0_P6_MASK 0x40u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P6_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P6_EN 0x1

/*! Field P7 - Interrupt enable */
#define IRNENSET_0_P7_POS 7
/*! Field P7 - Interrupt enable */
#define IRNENSET_0_P7_MASK 0x80u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P7_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P7_EN 0x1

/*! Field P8 - Interrupt enable */
#define IRNENSET_0_P8_POS 8
/*! Field P8 - Interrupt enable */
#define IRNENSET_0_P8_MASK 0x100u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P8_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P8_EN 0x1

/*! Field P9 - Interrupt enable */
#define IRNENSET_0_P9_POS 9
/*! Field P9 - Interrupt enable */
#define IRNENSET_0_P9_MASK 0x200u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P9_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P9_EN 0x1

/*! Field P10 - Interrupt enable */
#define IRNENSET_0_P10_POS 10
/*! Field P10 - Interrupt enable */
#define IRNENSET_0_P10_MASK 0x400u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P10_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P10_EN 0x1

/*! Field P11 - Interrupt enable */
#define IRNENSET_0_P11_POS 11
/*! Field P11 - Interrupt enable */
#define IRNENSET_0_P11_MASK 0x800u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P11_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P11_EN 0x1

/*! Field P12 - Interrupt enable */
#define IRNENSET_0_P12_POS 12
/*! Field P12 - Interrupt enable */
#define IRNENSET_0_P12_MASK 0x1000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P12_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P12_EN 0x1

/*! Field P13 - Interrupt enable */
#define IRNENSET_0_P13_POS 13
/*! Field P13 - Interrupt enable */
#define IRNENSET_0_P13_MASK 0x2000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P13_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P13_EN 0x1

/*! Field P14 - Interrupt enable */
#define IRNENSET_0_P14_POS 14
/*! Field P14 - Interrupt enable */
#define IRNENSET_0_P14_MASK 0x4000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P14_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P14_EN 0x1

/*! Field P15 - Interrupt enable */
#define IRNENSET_0_P15_POS 15
/*! Field P15 - Interrupt enable */
#define IRNENSET_0_P15_MASK 0x8000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P15_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P15_EN 0x1

/*! Field P16 - Interrupt enable */
#define IRNENSET_0_P16_POS 16
/*! Field P16 - Interrupt enable */
#define IRNENSET_0_P16_MASK 0x10000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P16_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P16_EN 0x1

/*! Field P17 - Interrupt enable */
#define IRNENSET_0_P17_POS 17
/*! Field P17 - Interrupt enable */
#define IRNENSET_0_P17_MASK 0x20000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P17_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P17_EN 0x1

/*! Field P18 - Interrupt enable */
#define IRNENSET_0_P18_POS 18
/*! Field P18 - Interrupt enable */
#define IRNENSET_0_P18_MASK 0x40000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P18_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P18_EN 0x1

/*! Field P19 - Interrupt enable */
#define IRNENSET_0_P19_POS 19
/*! Field P19 - Interrupt enable */
#define IRNENSET_0_P19_MASK 0x80000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P19_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P19_EN 0x1

/*! Field P20 - Interrupt enable */
#define IRNENSET_0_P20_POS 20
/*! Field P20 - Interrupt enable */
#define IRNENSET_0_P20_MASK 0x100000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P20_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P20_EN 0x1

/*! Field P21 - Interrupt enable */
#define IRNENSET_0_P21_POS 21
/*! Field P21 - Interrupt enable */
#define IRNENSET_0_P21_MASK 0x200000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P21_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P21_EN 0x1

/*! Field P22 - Interrupt enable */
#define IRNENSET_0_P22_POS 22
/*! Field P22 - Interrupt enable */
#define IRNENSET_0_P22_MASK 0x400000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P22_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P22_EN 0x1

/*! Field P23 - Interrupt enable */
#define IRNENSET_0_P23_POS 23
/*! Field P23 - Interrupt enable */
#define IRNENSET_0_P23_MASK 0x800000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P23_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P23_EN 0x1

/*! Field P24 - Interrupt enable */
#define IRNENSET_0_P24_POS 24
/*! Field P24 - Interrupt enable */
#define IRNENSET_0_P24_MASK 0x1000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P24_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P24_EN 0x1

/*! Field P25 - Interrupt enable */
#define IRNENSET_0_P25_POS 25
/*! Field P25 - Interrupt enable */
#define IRNENSET_0_P25_MASK 0x2000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P25_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P25_EN 0x1

/*! Field P26 - Interrupt enable */
#define IRNENSET_0_P26_POS 26
/*! Field P26 - Interrupt enable */
#define IRNENSET_0_P26_MASK 0x4000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P26_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P26_EN 0x1

/*! Field P27 - Interrupt enable */
#define IRNENSET_0_P27_POS 27
/*! Field P27 - Interrupt enable */
#define IRNENSET_0_P27_MASK 0x8000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P27_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P27_EN 0x1

/*! Field P28 - Interrupt enable */
#define IRNENSET_0_P28_POS 28
/*! Field P28 - Interrupt enable */
#define IRNENSET_0_P28_MASK 0x10000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P28_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P28_EN 0x1

/*! Field P29 - Interrupt enable */
#define IRNENSET_0_P29_POS 29
/*! Field P29 - Interrupt enable */
#define IRNENSET_0_P29_MASK 0x20000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P29_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P29_EN 0x1

/*! Field P30 - Interrupt enable */
#define IRNENSET_0_P30_POS 30
/*! Field P30 - Interrupt enable */
#define IRNENSET_0_P30_MASK 0x40000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P30_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P30_EN 0x1

/*! Field P31 - Interrupt enable */
#define IRNENSET_0_P31_POS 31
/*! Field P31 - Interrupt enable */
#define IRNENSET_0_P31_MASK 0x80000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_0_P31_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_0_P31_EN 0x1

/*! @} */

/*! \defgroup IRNENCLR_0 Register IRNENCLR_0 - IRN Interrupt Enable Clear Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNENCLR_0 0x34
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNENCLR_0 0x16300034u

/*! Register Reset Value */
#define IRNENCLR_0_RST 0x00000000u

/*! Field P0 - Interrupt Clear */
#define IRNENCLR_0_P0_POS 0
/*! Field P0 - Interrupt Clear */
#define IRNENCLR_0_P0_MASK 0x1u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P0_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P0_CLR 0x1

/*! Field P1 - Interrupt Clear */
#define IRNENCLR_0_P1_POS 1
/*! Field P1 - Interrupt Clear */
#define IRNENCLR_0_P1_MASK 0x2u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P1_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P1_CLR 0x1

/*! Field P2 - Interrupt Clear */
#define IRNENCLR_0_P2_POS 2
/*! Field P2 - Interrupt Clear */
#define IRNENCLR_0_P2_MASK 0x4u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P2_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P2_CLR 0x1

/*! Field P3 - Interrupt Clear */
#define IRNENCLR_0_P3_POS 3
/*! Field P3 - Interrupt Clear */
#define IRNENCLR_0_P3_MASK 0x8u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P3_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P3_CLR 0x1

/*! Field P4 - Interrupt Clear */
#define IRNENCLR_0_P4_POS 4
/*! Field P4 - Interrupt Clear */
#define IRNENCLR_0_P4_MASK 0x10u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P4_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P4_CLR 0x1

/*! Field P5 - Interrupt Clear */
#define IRNENCLR_0_P5_POS 5
/*! Field P5 - Interrupt Clear */
#define IRNENCLR_0_P5_MASK 0x20u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P5_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P5_CLR 0x1

/*! Field P6 - Interrupt Clear */
#define IRNENCLR_0_P6_POS 6
/*! Field P6 - Interrupt Clear */
#define IRNENCLR_0_P6_MASK 0x40u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P6_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P6_CLR 0x1

/*! Field P7 - Interrupt Clear */
#define IRNENCLR_0_P7_POS 7
/*! Field P7 - Interrupt Clear */
#define IRNENCLR_0_P7_MASK 0x80u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P7_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P7_CLR 0x1

/*! Field P8 - Interrupt Clear */
#define IRNENCLR_0_P8_POS 8
/*! Field P8 - Interrupt Clear */
#define IRNENCLR_0_P8_MASK 0x100u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P8_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P8_CLR 0x1

/*! Field P9 - Interrupt Clear */
#define IRNENCLR_0_P9_POS 9
/*! Field P9 - Interrupt Clear */
#define IRNENCLR_0_P9_MASK 0x200u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P9_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P9_CLR 0x1

/*! Field P10 - Interrupt Clear */
#define IRNENCLR_0_P10_POS 10
/*! Field P10 - Interrupt Clear */
#define IRNENCLR_0_P10_MASK 0x400u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P10_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P10_CLR 0x1

/*! Field P11 - Interrupt Clear */
#define IRNENCLR_0_P11_POS 11
/*! Field P11 - Interrupt Clear */
#define IRNENCLR_0_P11_MASK 0x800u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P11_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P11_CLR 0x1

/*! Field P12 - Interrupt Clear */
#define IRNENCLR_0_P12_POS 12
/*! Field P12 - Interrupt Clear */
#define IRNENCLR_0_P12_MASK 0x1000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P12_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P12_CLR 0x1

/*! Field P13 - Interrupt Clear */
#define IRNENCLR_0_P13_POS 13
/*! Field P13 - Interrupt Clear */
#define IRNENCLR_0_P13_MASK 0x2000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P13_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P13_CLR 0x1

/*! Field P14 - Interrupt Clear */
#define IRNENCLR_0_P14_POS 14
/*! Field P14 - Interrupt Clear */
#define IRNENCLR_0_P14_MASK 0x4000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P14_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P14_CLR 0x1

/*! Field P15 - Interrupt Clear */
#define IRNENCLR_0_P15_POS 15
/*! Field P15 - Interrupt Clear */
#define IRNENCLR_0_P15_MASK 0x8000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P15_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P15_CLR 0x1

/*! Field P16 - Interrupt Clear */
#define IRNENCLR_0_P16_POS 16
/*! Field P16 - Interrupt Clear */
#define IRNENCLR_0_P16_MASK 0x10000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P16_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P16_CLR 0x1

/*! Field P17 - Interrupt Clear */
#define IRNENCLR_0_P17_POS 17
/*! Field P17 - Interrupt Clear */
#define IRNENCLR_0_P17_MASK 0x20000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P17_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P17_CLR 0x1

/*! Field P18 - Interrupt Clear */
#define IRNENCLR_0_P18_POS 18
/*! Field P18 - Interrupt Clear */
#define IRNENCLR_0_P18_MASK 0x40000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P18_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P18_CLR 0x1

/*! Field P19 - Interrupt Clear */
#define IRNENCLR_0_P19_POS 19
/*! Field P19 - Interrupt Clear */
#define IRNENCLR_0_P19_MASK 0x80000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P19_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P19_CLR 0x1

/*! Field P20 - Interrupt Clear */
#define IRNENCLR_0_P20_POS 20
/*! Field P20 - Interrupt Clear */
#define IRNENCLR_0_P20_MASK 0x100000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P20_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P20_CLR 0x1

/*! Field P21 - Interrupt Clear */
#define IRNENCLR_0_P21_POS 21
/*! Field P21 - Interrupt Clear */
#define IRNENCLR_0_P21_MASK 0x200000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P21_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P21_CLR 0x1

/*! Field P22 - Interrupt Clear */
#define IRNENCLR_0_P22_POS 22
/*! Field P22 - Interrupt Clear */
#define IRNENCLR_0_P22_MASK 0x400000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P22_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P22_CLR 0x1

/*! Field P23 - Interrupt Clear */
#define IRNENCLR_0_P23_POS 23
/*! Field P23 - Interrupt Clear */
#define IRNENCLR_0_P23_MASK 0x800000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P23_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P23_CLR 0x1

/*! Field P24 - Interrupt Clear */
#define IRNENCLR_0_P24_POS 24
/*! Field P24 - Interrupt Clear */
#define IRNENCLR_0_P24_MASK 0x1000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P24_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P24_CLR 0x1

/*! Field P25 - Interrupt Clear */
#define IRNENCLR_0_P25_POS 25
/*! Field P25 - Interrupt Clear */
#define IRNENCLR_0_P25_MASK 0x2000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P25_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P25_CLR 0x1

/*! Field P26 - Interrupt Clear */
#define IRNENCLR_0_P26_POS 26
/*! Field P26 - Interrupt Clear */
#define IRNENCLR_0_P26_MASK 0x4000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P26_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P26_CLR 0x1

/*! Field P27 - Interrupt Clear */
#define IRNENCLR_0_P27_POS 27
/*! Field P27 - Interrupt Clear */
#define IRNENCLR_0_P27_MASK 0x8000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P27_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P27_CLR 0x1

/*! Field P28 - Interrupt Clear */
#define IRNENCLR_0_P28_POS 28
/*! Field P28 - Interrupt Clear */
#define IRNENCLR_0_P28_MASK 0x10000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P28_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P28_CLR 0x1

/*! Field P29 - Interrupt Clear */
#define IRNENCLR_0_P29_POS 29
/*! Field P29 - Interrupt Clear */
#define IRNENCLR_0_P29_MASK 0x20000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P29_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P29_CLR 0x1

/*! Field P30 - Interrupt Clear */
#define IRNENCLR_0_P30_POS 30
/*! Field P30 - Interrupt Clear */
#define IRNENCLR_0_P30_MASK 0x40000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P30_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P30_CLR 0x1

/*! Field P31 - Interrupt Clear */
#define IRNENCLR_0_P31_POS 31
/*! Field P31 - Interrupt Clear */
#define IRNENCLR_0_P31_MASK 0x80000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_0_P31_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_0_P31_CLR 0x1

/*! @} */

/*! \defgroup OUTSET_0 Register OUTSET_0 - Output Set Register */
/*! @{ */

/*! Register Offset (relative) */
#define OUTSET_0 0x40
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_OUTSET_0 0x16300040u

/*! Register Reset Value */
#define OUTSET_0_RST 0x00000000u

/*! Field P0 - Pin Output Set */
#define OUTSET_0_P0_POS 0
/*! Field P0 - Pin Output Set */
#define OUTSET_0_P0_MASK 0x1u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P0_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P0_SET 0x1

/*! Field P1 - Pin Output Set */
#define OUTSET_0_P1_POS 1
/*! Field P1 - Pin Output Set */
#define OUTSET_0_P1_MASK 0x2u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P1_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P1_SET 0x1

/*! Field P2 - Pin Output Set */
#define OUTSET_0_P2_POS 2
/*! Field P2 - Pin Output Set */
#define OUTSET_0_P2_MASK 0x4u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P2_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P2_SET 0x1

/*! Field P3 - Pin Output Set */
#define OUTSET_0_P3_POS 3
/*! Field P3 - Pin Output Set */
#define OUTSET_0_P3_MASK 0x8u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P3_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P3_SET 0x1

/*! Field P4 - Pin Output Set */
#define OUTSET_0_P4_POS 4
/*! Field P4 - Pin Output Set */
#define OUTSET_0_P4_MASK 0x10u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P4_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P4_SET 0x1

/*! Field P5 - Pin Output Set */
#define OUTSET_0_P5_POS 5
/*! Field P5 - Pin Output Set */
#define OUTSET_0_P5_MASK 0x20u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P5_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P5_SET 0x1

/*! Field P6 - Pin Output Set */
#define OUTSET_0_P6_POS 6
/*! Field P6 - Pin Output Set */
#define OUTSET_0_P6_MASK 0x40u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P6_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P6_SET 0x1

/*! Field P7 - Pin Output Set */
#define OUTSET_0_P7_POS 7
/*! Field P7 - Pin Output Set */
#define OUTSET_0_P7_MASK 0x80u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P7_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P7_SET 0x1

/*! Field P8 - Pin Output Set */
#define OUTSET_0_P8_POS 8
/*! Field P8 - Pin Output Set */
#define OUTSET_0_P8_MASK 0x100u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P8_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P8_SET 0x1

/*! Field P9 - Pin Output Set */
#define OUTSET_0_P9_POS 9
/*! Field P9 - Pin Output Set */
#define OUTSET_0_P9_MASK 0x200u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P9_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P9_SET 0x1

/*! Field P10 - Pin Output Set */
#define OUTSET_0_P10_POS 10
/*! Field P10 - Pin Output Set */
#define OUTSET_0_P10_MASK 0x400u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P10_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P10_SET 0x1

/*! Field P11 - Pin Output Set */
#define OUTSET_0_P11_POS 11
/*! Field P11 - Pin Output Set */
#define OUTSET_0_P11_MASK 0x800u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P11_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P11_SET 0x1

/*! Field P12 - Pin Output Set */
#define OUTSET_0_P12_POS 12
/*! Field P12 - Pin Output Set */
#define OUTSET_0_P12_MASK 0x1000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P12_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P12_SET 0x1

/*! Field P13 - Pin Output Set */
#define OUTSET_0_P13_POS 13
/*! Field P13 - Pin Output Set */
#define OUTSET_0_P13_MASK 0x2000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P13_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P13_SET 0x1

/*! Field P14 - Pin Output Set */
#define OUTSET_0_P14_POS 14
/*! Field P14 - Pin Output Set */
#define OUTSET_0_P14_MASK 0x4000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P14_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P14_SET 0x1

/*! Field P15 - Pin Output Set */
#define OUTSET_0_P15_POS 15
/*! Field P15 - Pin Output Set */
#define OUTSET_0_P15_MASK 0x8000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P15_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P15_SET 0x1

/*! Field P16 - Pin Output Set */
#define OUTSET_0_P16_POS 16
/*! Field P16 - Pin Output Set */
#define OUTSET_0_P16_MASK 0x10000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P16_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P16_SET 0x1

/*! Field P17 - Pin Output Set */
#define OUTSET_0_P17_POS 17
/*! Field P17 - Pin Output Set */
#define OUTSET_0_P17_MASK 0x20000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P17_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P17_SET 0x1

/*! Field P18 - Pin Output Set */
#define OUTSET_0_P18_POS 18
/*! Field P18 - Pin Output Set */
#define OUTSET_0_P18_MASK 0x40000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P18_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P18_SET 0x1

/*! Field P19 - Pin Output Set */
#define OUTSET_0_P19_POS 19
/*! Field P19 - Pin Output Set */
#define OUTSET_0_P19_MASK 0x80000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P19_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P19_SET 0x1

/*! Field P20 - Pin Output Set */
#define OUTSET_0_P20_POS 20
/*! Field P20 - Pin Output Set */
#define OUTSET_0_P20_MASK 0x100000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P20_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P20_SET 0x1

/*! Field P21 - Pin Output Set */
#define OUTSET_0_P21_POS 21
/*! Field P21 - Pin Output Set */
#define OUTSET_0_P21_MASK 0x200000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P21_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P21_SET 0x1

/*! Field P22 - Pin Output Set */
#define OUTSET_0_P22_POS 22
/*! Field P22 - Pin Output Set */
#define OUTSET_0_P22_MASK 0x400000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P22_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P22_SET 0x1

/*! Field P23 - Pin Output Set */
#define OUTSET_0_P23_POS 23
/*! Field P23 - Pin Output Set */
#define OUTSET_0_P23_MASK 0x800000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P23_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P23_SET 0x1

/*! Field P24 - Pin Output Set */
#define OUTSET_0_P24_POS 24
/*! Field P24 - Pin Output Set */
#define OUTSET_0_P24_MASK 0x1000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P24_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P24_SET 0x1

/*! Field P25 - Pin Output Set */
#define OUTSET_0_P25_POS 25
/*! Field P25 - Pin Output Set */
#define OUTSET_0_P25_MASK 0x2000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P25_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P25_SET 0x1

/*! Field P26 - Pin Output Set */
#define OUTSET_0_P26_POS 26
/*! Field P26 - Pin Output Set */
#define OUTSET_0_P26_MASK 0x4000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P26_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P26_SET 0x1

/*! Field P27 - Pin Output Set */
#define OUTSET_0_P27_POS 27
/*! Field P27 - Pin Output Set */
#define OUTSET_0_P27_MASK 0x8000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P27_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P27_SET 0x1

/*! Field P28 - Pin Output Set */
#define OUTSET_0_P28_POS 28
/*! Field P28 - Pin Output Set */
#define OUTSET_0_P28_MASK 0x10000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P28_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P28_SET 0x1

/*! Field P29 - Pin Output Set */
#define OUTSET_0_P29_POS 29
/*! Field P29 - Pin Output Set */
#define OUTSET_0_P29_MASK 0x20000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P29_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P29_SET 0x1

/*! Field P30 - Pin Output Set */
#define OUTSET_0_P30_POS 30
/*! Field P30 - Pin Output Set */
#define OUTSET_0_P30_MASK 0x40000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P30_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P30_SET 0x1

/*! Field P31 - Pin Output Set */
#define OUTSET_0_P31_POS 31
/*! Field P31 - Pin Output Set */
#define OUTSET_0_P31_MASK 0x80000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_0_P31_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_0_P31_SET 0x1

/*! @} */

/*! \defgroup OUTCLR_0 Register OUTCLR_0 - Output Clear Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define OUTCLR_0 0x44
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_OUTCLR_0 0x16300044u

/*! Register Reset Value */
#define OUTCLR_0_RST 0x00000000u

/*! Field P0 - Output Clear */
#define OUTCLR_0_P0_POS 0
/*! Field P0 - Output Clear */
#define OUTCLR_0_P0_MASK 0x1u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P0_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P0_CLR 0x1

/*! Field P1 - Output Clear */
#define OUTCLR_0_P1_POS 1
/*! Field P1 - Output Clear */
#define OUTCLR_0_P1_MASK 0x2u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P1_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P1_CLR 0x1

/*! Field P2 - Output Clear */
#define OUTCLR_0_P2_POS 2
/*! Field P2 - Output Clear */
#define OUTCLR_0_P2_MASK 0x4u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P2_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P2_CLR 0x1

/*! Field P3 - Output Clear */
#define OUTCLR_0_P3_POS 3
/*! Field P3 - Output Clear */
#define OUTCLR_0_P3_MASK 0x8u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P3_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P3_CLR 0x1

/*! Field P4 - Output Clear */
#define OUTCLR_0_P4_POS 4
/*! Field P4 - Output Clear */
#define OUTCLR_0_P4_MASK 0x10u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P4_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P4_CLR 0x1

/*! Field P5 - Output Clear */
#define OUTCLR_0_P5_POS 5
/*! Field P5 - Output Clear */
#define OUTCLR_0_P5_MASK 0x20u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P5_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P5_CLR 0x1

/*! Field P6 - Output Clear */
#define OUTCLR_0_P6_POS 6
/*! Field P6 - Output Clear */
#define OUTCLR_0_P6_MASK 0x40u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P6_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P6_CLR 0x1

/*! Field P7 - Output Clear */
#define OUTCLR_0_P7_POS 7
/*! Field P7 - Output Clear */
#define OUTCLR_0_P7_MASK 0x80u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P7_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P7_CLR 0x1

/*! Field P8 - Output Clear */
#define OUTCLR_0_P8_POS 8
/*! Field P8 - Output Clear */
#define OUTCLR_0_P8_MASK 0x100u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P8_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P8_CLR 0x1

/*! Field P9 - Output Clear */
#define OUTCLR_0_P9_POS 9
/*! Field P9 - Output Clear */
#define OUTCLR_0_P9_MASK 0x200u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P9_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P9_CLR 0x1

/*! Field P10 - Output Clear */
#define OUTCLR_0_P10_POS 10
/*! Field P10 - Output Clear */
#define OUTCLR_0_P10_MASK 0x400u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P10_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P10_CLR 0x1

/*! Field P11 - Output Clear */
#define OUTCLR_0_P11_POS 11
/*! Field P11 - Output Clear */
#define OUTCLR_0_P11_MASK 0x800u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P11_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P11_CLR 0x1

/*! Field P12 - Output Clear */
#define OUTCLR_0_P12_POS 12
/*! Field P12 - Output Clear */
#define OUTCLR_0_P12_MASK 0x1000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P12_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P12_CLR 0x1

/*! Field P13 - Output Clear */
#define OUTCLR_0_P13_POS 13
/*! Field P13 - Output Clear */
#define OUTCLR_0_P13_MASK 0x2000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P13_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P13_CLR 0x1

/*! Field P14 - Output Clear */
#define OUTCLR_0_P14_POS 14
/*! Field P14 - Output Clear */
#define OUTCLR_0_P14_MASK 0x4000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P14_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P14_CLR 0x1

/*! Field P15 - Output Clear */
#define OUTCLR_0_P15_POS 15
/*! Field P15 - Output Clear */
#define OUTCLR_0_P15_MASK 0x8000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P15_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P15_CLR 0x1

/*! Field P16 - Output Clear */
#define OUTCLR_0_P16_POS 16
/*! Field P16 - Output Clear */
#define OUTCLR_0_P16_MASK 0x10000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P16_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P16_CLR 0x1

/*! Field P17 - Output Clear */
#define OUTCLR_0_P17_POS 17
/*! Field P17 - Output Clear */
#define OUTCLR_0_P17_MASK 0x20000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P17_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P17_CLR 0x1

/*! Field P18 - Output Clear */
#define OUTCLR_0_P18_POS 18
/*! Field P18 - Output Clear */
#define OUTCLR_0_P18_MASK 0x40000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P18_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P18_CLR 0x1

/*! Field P19 - Output Clear */
#define OUTCLR_0_P19_POS 19
/*! Field P19 - Output Clear */
#define OUTCLR_0_P19_MASK 0x80000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P19_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P19_CLR 0x1

/*! Field P20 - Output Clear */
#define OUTCLR_0_P20_POS 20
/*! Field P20 - Output Clear */
#define OUTCLR_0_P20_MASK 0x100000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P20_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P20_CLR 0x1

/*! Field P21 - Output Clear */
#define OUTCLR_0_P21_POS 21
/*! Field P21 - Output Clear */
#define OUTCLR_0_P21_MASK 0x200000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P21_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P21_CLR 0x1

/*! Field P22 - Output Clear */
#define OUTCLR_0_P22_POS 22
/*! Field P22 - Output Clear */
#define OUTCLR_0_P22_MASK 0x400000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P22_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P22_CLR 0x1

/*! Field P23 - Output Clear */
#define OUTCLR_0_P23_POS 23
/*! Field P23 - Output Clear */
#define OUTCLR_0_P23_MASK 0x800000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P23_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P23_CLR 0x1

/*! Field P24 - Output Clear */
#define OUTCLR_0_P24_POS 24
/*! Field P24 - Output Clear */
#define OUTCLR_0_P24_MASK 0x1000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P24_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P24_CLR 0x1

/*! Field P25 - Output Clear */
#define OUTCLR_0_P25_POS 25
/*! Field P25 - Output Clear */
#define OUTCLR_0_P25_MASK 0x2000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P25_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P25_CLR 0x1

/*! Field P26 - Output Clear */
#define OUTCLR_0_P26_POS 26
/*! Field P26 - Output Clear */
#define OUTCLR_0_P26_MASK 0x4000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P26_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P26_CLR 0x1

/*! Field P27 - Output Clear */
#define OUTCLR_0_P27_POS 27
/*! Field P27 - Output Clear */
#define OUTCLR_0_P27_MASK 0x8000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P27_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P27_CLR 0x1

/*! Field P28 - Output Clear */
#define OUTCLR_0_P28_POS 28
/*! Field P28 - Output Clear */
#define OUTCLR_0_P28_MASK 0x10000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P28_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P28_CLR 0x1

/*! Field P29 - Output Clear */
#define OUTCLR_0_P29_POS 29
/*! Field P29 - Output Clear */
#define OUTCLR_0_P29_MASK 0x20000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P29_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P29_CLR 0x1

/*! Field P30 - Output Clear */
#define OUTCLR_0_P30_POS 30
/*! Field P30 - Output Clear */
#define OUTCLR_0_P30_MASK 0x40000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P30_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P30_CLR 0x1

/*! Field P31 - Output Clear */
#define OUTCLR_0_P31_POS 31
/*! Field P31 - Output Clear */
#define OUTCLR_0_P31_MASK 0x80000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_0_P31_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_0_P31_CLR 0x1

/*! @} */

/*! \defgroup DIRSET_0 Register DIRSET_0 - Direction Set Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define DIRSET_0 0x48
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_DIRSET_0 0x16300048u

/*! Register Reset Value */
#define DIRSET_0_RST 0x00000000u

/*! Field P0 - Pin Direction Set */
#define DIRSET_0_P0_POS 0
/*! Field P0 - Pin Direction Set */
#define DIRSET_0_P0_MASK 0x1u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P0_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P0_SET 0x1

/*! Field P1 - Pin Direction Set */
#define DIRSET_0_P1_POS 1
/*! Field P1 - Pin Direction Set */
#define DIRSET_0_P1_MASK 0x2u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P1_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P1_SET 0x1

/*! Field P2 - Pin Direction Set */
#define DIRSET_0_P2_POS 2
/*! Field P2 - Pin Direction Set */
#define DIRSET_0_P2_MASK 0x4u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P2_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P2_SET 0x1

/*! Field P3 - Pin Direction Set */
#define DIRSET_0_P3_POS 3
/*! Field P3 - Pin Direction Set */
#define DIRSET_0_P3_MASK 0x8u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P3_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P3_SET 0x1

/*! Field P4 - Pin Direction Set */
#define DIRSET_0_P4_POS 4
/*! Field P4 - Pin Direction Set */
#define DIRSET_0_P4_MASK 0x10u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P4_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P4_SET 0x1

/*! Field P5 - Pin Direction Set */
#define DIRSET_0_P5_POS 5
/*! Field P5 - Pin Direction Set */
#define DIRSET_0_P5_MASK 0x20u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P5_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P5_SET 0x1

/*! Field P6 - Pin Direction Set */
#define DIRSET_0_P6_POS 6
/*! Field P6 - Pin Direction Set */
#define DIRSET_0_P6_MASK 0x40u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P6_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P6_SET 0x1

/*! Field P7 - Pin Direction Set */
#define DIRSET_0_P7_POS 7
/*! Field P7 - Pin Direction Set */
#define DIRSET_0_P7_MASK 0x80u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P7_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P7_SET 0x1

/*! Field P8 - Pin Direction Set */
#define DIRSET_0_P8_POS 8
/*! Field P8 - Pin Direction Set */
#define DIRSET_0_P8_MASK 0x100u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P8_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P8_SET 0x1

/*! Field P9 - Pin Direction Set */
#define DIRSET_0_P9_POS 9
/*! Field P9 - Pin Direction Set */
#define DIRSET_0_P9_MASK 0x200u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P9_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P9_SET 0x1

/*! Field P10 - Pin Direction Set */
#define DIRSET_0_P10_POS 10
/*! Field P10 - Pin Direction Set */
#define DIRSET_0_P10_MASK 0x400u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P10_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P10_SET 0x1

/*! Field P11 - Pin Direction Set */
#define DIRSET_0_P11_POS 11
/*! Field P11 - Pin Direction Set */
#define DIRSET_0_P11_MASK 0x800u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P11_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P11_SET 0x1

/*! Field P12 - Pin Direction Set */
#define DIRSET_0_P12_POS 12
/*! Field P12 - Pin Direction Set */
#define DIRSET_0_P12_MASK 0x1000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P12_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P12_SET 0x1

/*! Field P13 - Pin Direction Set */
#define DIRSET_0_P13_POS 13
/*! Field P13 - Pin Direction Set */
#define DIRSET_0_P13_MASK 0x2000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P13_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P13_SET 0x1

/*! Field P14 - Pin Direction Set */
#define DIRSET_0_P14_POS 14
/*! Field P14 - Pin Direction Set */
#define DIRSET_0_P14_MASK 0x4000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P14_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P14_SET 0x1

/*! Field P15 - Pin Direction Set */
#define DIRSET_0_P15_POS 15
/*! Field P15 - Pin Direction Set */
#define DIRSET_0_P15_MASK 0x8000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P15_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P15_SET 0x1

/*! Field P16 - Pin Direction Set */
#define DIRSET_0_P16_POS 16
/*! Field P16 - Pin Direction Set */
#define DIRSET_0_P16_MASK 0x10000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P16_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P16_SET 0x1

/*! Field P17 - Pin Direction Set */
#define DIRSET_0_P17_POS 17
/*! Field P17 - Pin Direction Set */
#define DIRSET_0_P17_MASK 0x20000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P17_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P17_SET 0x1

/*! Field P18 - Pin Direction Set */
#define DIRSET_0_P18_POS 18
/*! Field P18 - Pin Direction Set */
#define DIRSET_0_P18_MASK 0x40000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P18_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P18_SET 0x1

/*! Field P19 - Pin Direction Set */
#define DIRSET_0_P19_POS 19
/*! Field P19 - Pin Direction Set */
#define DIRSET_0_P19_MASK 0x80000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P19_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P19_SET 0x1

/*! Field P20 - Pin Direction Set */
#define DIRSET_0_P20_POS 20
/*! Field P20 - Pin Direction Set */
#define DIRSET_0_P20_MASK 0x100000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P20_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P20_SET 0x1

/*! Field P21 - Pin Direction Set */
#define DIRSET_0_P21_POS 21
/*! Field P21 - Pin Direction Set */
#define DIRSET_0_P21_MASK 0x200000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P21_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P21_SET 0x1

/*! Field P22 - Pin Direction Set */
#define DIRSET_0_P22_POS 22
/*! Field P22 - Pin Direction Set */
#define DIRSET_0_P22_MASK 0x400000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P22_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P22_SET 0x1

/*! Field P23 - Pin Direction Set */
#define DIRSET_0_P23_POS 23
/*! Field P23 - Pin Direction Set */
#define DIRSET_0_P23_MASK 0x800000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P23_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P23_SET 0x1

/*! Field P24 - Pin Direction Set */
#define DIRSET_0_P24_POS 24
/*! Field P24 - Pin Direction Set */
#define DIRSET_0_P24_MASK 0x1000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P24_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P24_SET 0x1

/*! Field P25 - Pin Direction Set */
#define DIRSET_0_P25_POS 25
/*! Field P25 - Pin Direction Set */
#define DIRSET_0_P25_MASK 0x2000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P25_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P25_SET 0x1

/*! Field P26 - Pin Direction Set */
#define DIRSET_0_P26_POS 26
/*! Field P26 - Pin Direction Set */
#define DIRSET_0_P26_MASK 0x4000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P26_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P26_SET 0x1

/*! Field P27 - Pin Direction Set */
#define DIRSET_0_P27_POS 27
/*! Field P27 - Pin Direction Set */
#define DIRSET_0_P27_MASK 0x8000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P27_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P27_SET 0x1

/*! Field P28 - Pin Direction Set */
#define DIRSET_0_P28_POS 28
/*! Field P28 - Pin Direction Set */
#define DIRSET_0_P28_MASK 0x10000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P28_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P28_SET 0x1

/*! Field P29 - Pin Direction Set */
#define DIRSET_0_P29_POS 29
/*! Field P29 - Pin Direction Set */
#define DIRSET_0_P29_MASK 0x20000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P29_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P29_SET 0x1

/*! Field P30 - Pin Direction Set */
#define DIRSET_0_P30_POS 30
/*! Field P30 - Pin Direction Set */
#define DIRSET_0_P30_MASK 0x40000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P30_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P30_SET 0x1

/*! Field P31 - Pin Direction Set */
#define DIRSET_0_P31_POS 31
/*! Field P31 - Pin Direction Set */
#define DIRSET_0_P31_MASK 0x80000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_0_P31_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_0_P31_SET 0x1

/*! @} */

/*! \defgroup DIRCLR_0 Register DIRCLR_0 - Direction Clear Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define DIRCLR_0 0x4C
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_DIRCLR_0 0x1630004Cu

/*! Register Reset Value */
#define DIRCLR_0_RST 0x00000000u

/*! Field P0 - Direction Clear */
#define DIRCLR_0_P0_POS 0
/*! Field P0 - Direction Clear */
#define DIRCLR_0_P0_MASK 0x1u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P0_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P0_CLR 0x1

/*! Field P1 - Direction Clear */
#define DIRCLR_0_P1_POS 1
/*! Field P1 - Direction Clear */
#define DIRCLR_0_P1_MASK 0x2u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P1_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P1_CLR 0x1

/*! Field P2 - Direction Clear */
#define DIRCLR_0_P2_POS 2
/*! Field P2 - Direction Clear */
#define DIRCLR_0_P2_MASK 0x4u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P2_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P2_CLR 0x1

/*! Field P3 - Direction Clear */
#define DIRCLR_0_P3_POS 3
/*! Field P3 - Direction Clear */
#define DIRCLR_0_P3_MASK 0x8u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P3_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P3_CLR 0x1

/*! Field P4 - Direction Clear */
#define DIRCLR_0_P4_POS 4
/*! Field P4 - Direction Clear */
#define DIRCLR_0_P4_MASK 0x10u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P4_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P4_CLR 0x1

/*! Field P5 - Direction Clear */
#define DIRCLR_0_P5_POS 5
/*! Field P5 - Direction Clear */
#define DIRCLR_0_P5_MASK 0x20u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P5_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P5_CLR 0x1

/*! Field P6 - Direction Clear */
#define DIRCLR_0_P6_POS 6
/*! Field P6 - Direction Clear */
#define DIRCLR_0_P6_MASK 0x40u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P6_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P6_CLR 0x1

/*! Field P7 - Direction Clear */
#define DIRCLR_0_P7_POS 7
/*! Field P7 - Direction Clear */
#define DIRCLR_0_P7_MASK 0x80u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P7_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P7_CLR 0x1

/*! Field P8 - Direction Clear */
#define DIRCLR_0_P8_POS 8
/*! Field P8 - Direction Clear */
#define DIRCLR_0_P8_MASK 0x100u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P8_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P8_CLR 0x1

/*! Field P9 - Direction Clear */
#define DIRCLR_0_P9_POS 9
/*! Field P9 - Direction Clear */
#define DIRCLR_0_P9_MASK 0x200u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P9_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P9_CLR 0x1

/*! Field P10 - Direction Clear */
#define DIRCLR_0_P10_POS 10
/*! Field P10 - Direction Clear */
#define DIRCLR_0_P10_MASK 0x400u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P10_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P10_CLR 0x1

/*! Field P11 - Direction Clear */
#define DIRCLR_0_P11_POS 11
/*! Field P11 - Direction Clear */
#define DIRCLR_0_P11_MASK 0x800u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P11_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P11_CLR 0x1

/*! Field P12 - Direction Clear */
#define DIRCLR_0_P12_POS 12
/*! Field P12 - Direction Clear */
#define DIRCLR_0_P12_MASK 0x1000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P12_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P12_CLR 0x1

/*! Field P13 - Direction Clear */
#define DIRCLR_0_P13_POS 13
/*! Field P13 - Direction Clear */
#define DIRCLR_0_P13_MASK 0x2000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P13_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P13_CLR 0x1

/*! Field P14 - Direction Clear */
#define DIRCLR_0_P14_POS 14
/*! Field P14 - Direction Clear */
#define DIRCLR_0_P14_MASK 0x4000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P14_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P14_CLR 0x1

/*! Field P15 - Direction Clear */
#define DIRCLR_0_P15_POS 15
/*! Field P15 - Direction Clear */
#define DIRCLR_0_P15_MASK 0x8000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P15_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P15_CLR 0x1

/*! Field P16 - Direction Clear */
#define DIRCLR_0_P16_POS 16
/*! Field P16 - Direction Clear */
#define DIRCLR_0_P16_MASK 0x10000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P16_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P16_CLR 0x1

/*! Field P17 - Direction Clear */
#define DIRCLR_0_P17_POS 17
/*! Field P17 - Direction Clear */
#define DIRCLR_0_P17_MASK 0x20000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P17_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P17_CLR 0x1

/*! Field P18 - Direction Clear */
#define DIRCLR_0_P18_POS 18
/*! Field P18 - Direction Clear */
#define DIRCLR_0_P18_MASK 0x40000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P18_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P18_CLR 0x1

/*! Field P19 - Direction Clear */
#define DIRCLR_0_P19_POS 19
/*! Field P19 - Direction Clear */
#define DIRCLR_0_P19_MASK 0x80000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P19_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P19_CLR 0x1

/*! Field P20 - Direction Clear */
#define DIRCLR_0_P20_POS 20
/*! Field P20 - Direction Clear */
#define DIRCLR_0_P20_MASK 0x100000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P20_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P20_CLR 0x1

/*! Field P21 - Direction Clear */
#define DIRCLR_0_P21_POS 21
/*! Field P21 - Direction Clear */
#define DIRCLR_0_P21_MASK 0x200000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P21_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P21_CLR 0x1

/*! Field P22 - Direction Clear */
#define DIRCLR_0_P22_POS 22
/*! Field P22 - Direction Clear */
#define DIRCLR_0_P22_MASK 0x400000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P22_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P22_CLR 0x1

/*! Field P23 - Direction Clear */
#define DIRCLR_0_P23_POS 23
/*! Field P23 - Direction Clear */
#define DIRCLR_0_P23_MASK 0x800000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P23_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P23_CLR 0x1

/*! Field P24 - Direction Clear */
#define DIRCLR_0_P24_POS 24
/*! Field P24 - Direction Clear */
#define DIRCLR_0_P24_MASK 0x1000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P24_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P24_CLR 0x1

/*! Field P25 - Direction Clear */
#define DIRCLR_0_P25_POS 25
/*! Field P25 - Direction Clear */
#define DIRCLR_0_P25_MASK 0x2000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P25_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P25_CLR 0x1

/*! Field P26 - Direction Clear */
#define DIRCLR_0_P26_POS 26
/*! Field P26 - Direction Clear */
#define DIRCLR_0_P26_MASK 0x4000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P26_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P26_CLR 0x1

/*! Field P27 - Direction Clear */
#define DIRCLR_0_P27_POS 27
/*! Field P27 - Direction Clear */
#define DIRCLR_0_P27_MASK 0x8000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P27_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P27_CLR 0x1

/*! Field P28 - Direction Clear */
#define DIRCLR_0_P28_POS 28
/*! Field P28 - Direction Clear */
#define DIRCLR_0_P28_MASK 0x10000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P28_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P28_CLR 0x1

/*! Field P29 - Direction Clear */
#define DIRCLR_0_P29_POS 29
/*! Field P29 - Direction Clear */
#define DIRCLR_0_P29_MASK 0x20000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P29_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P29_CLR 0x1

/*! Field P30 - Direction Clear */
#define DIRCLR_0_P30_POS 30
/*! Field P30 - Direction Clear */
#define DIRCLR_0_P30_MASK 0x40000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P30_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P30_CLR 0x1

/*! Field P31 - Direction Clear */
#define DIRCLR_0_P31_POS 31
/*! Field P31 - Direction Clear */
#define DIRCLR_0_P31_MASK 0x80000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_0_P31_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_0_P31_CLR 0x1

/*! @} */

/*! \defgroup OUT_1 Register OUT_1 - Data Output Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define OUT_1 0x100
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_OUT_1 0x16300100u

/*! Register Reset Value */
#define OUT_1_RST 0x00000000u

/*! Field P32 - Bit Output Value */
#define OUT_1_P32_POS 0
/*! Field P32 - Bit Output Value */
#define OUT_1_P32_MASK 0x1u

/*! Field P33 - Bit Output Value */
#define OUT_1_P33_POS 1
/*! Field P33 - Bit Output Value */
#define OUT_1_P33_MASK 0x2u

/*! Field P34 - Bit Output Value */
#define OUT_1_P34_POS 2
/*! Field P34 - Bit Output Value */
#define OUT_1_P34_MASK 0x4u

/*! Field P35 - Bit Output Value */
#define OUT_1_P35_POS 3
/*! Field P35 - Bit Output Value */
#define OUT_1_P35_MASK 0x8u

/*! Field P36 - Bit Output Value */
#define OUT_1_P36_POS 4
/*! Field P36 - Bit Output Value */
#define OUT_1_P36_MASK 0x10u

/*! Field P37 - Bit Output Value */
#define OUT_1_P37_POS 5
/*! Field P37 - Bit Output Value */
#define OUT_1_P37_MASK 0x20u

/*! Field P38 - Bit Output Value */
#define OUT_1_P38_POS 6
/*! Field P38 - Bit Output Value */
#define OUT_1_P38_MASK 0x40u

/*! Field P39 - Bit Output Value */
#define OUT_1_P39_POS 7
/*! Field P39 - Bit Output Value */
#define OUT_1_P39_MASK 0x80u

/*! Field P40 - Bit Output Value */
#define OUT_1_P40_POS 8
/*! Field P40 - Bit Output Value */
#define OUT_1_P40_MASK 0x100u

/*! Field P41 - Bit Output Value */
#define OUT_1_P41_POS 9
/*! Field P41 - Bit Output Value */
#define OUT_1_P41_MASK 0x200u

/*! Field P42 - Bit Output Value */
#define OUT_1_P42_POS 10
/*! Field P42 - Bit Output Value */
#define OUT_1_P42_MASK 0x400u

/*! Field P43 - Bit Output Value */
#define OUT_1_P43_POS 11
/*! Field P43 - Bit Output Value */
#define OUT_1_P43_MASK 0x800u

/*! Field P44 - Bit Output Value */
#define OUT_1_P44_POS 12
/*! Field P44 - Bit Output Value */
#define OUT_1_P44_MASK 0x1000u

/*! Field P45 - Bit Output Value */
#define OUT_1_P45_POS 13
/*! Field P45 - Bit Output Value */
#define OUT_1_P45_MASK 0x2000u

/*! Field P46 - Bit Output Value */
#define OUT_1_P46_POS 14
/*! Field P46 - Bit Output Value */
#define OUT_1_P46_MASK 0x4000u

/*! Field P47 - Bit Output Value */
#define OUT_1_P47_POS 15
/*! Field P47 - Bit Output Value */
#define OUT_1_P47_MASK 0x8000u

/*! Field P48 - Bit Output Value */
#define OUT_1_P48_POS 16
/*! Field P48 - Bit Output Value */
#define OUT_1_P48_MASK 0x10000u

/*! Field P49 - Bit Output Value */
#define OUT_1_P49_POS 17
/*! Field P49 - Bit Output Value */
#define OUT_1_P49_MASK 0x20000u

/*! Field P50 - Bit Output Value */
#define OUT_1_P50_POS 18
/*! Field P50 - Bit Output Value */
#define OUT_1_P50_MASK 0x40000u

/*! Field P51 - Bit Output Value */
#define OUT_1_P51_POS 19
/*! Field P51 - Bit Output Value */
#define OUT_1_P51_MASK 0x80000u

/*! Field P52 - Bit Output Value */
#define OUT_1_P52_POS 20
/*! Field P52 - Bit Output Value */
#define OUT_1_P52_MASK 0x100000u

/*! Field P53 - Bit Output Value */
#define OUT_1_P53_POS 21
/*! Field P53 - Bit Output Value */
#define OUT_1_P53_MASK 0x200000u

/*! Field P54 - Bit Output Value */
#define OUT_1_P54_POS 22
/*! Field P54 - Bit Output Value */
#define OUT_1_P54_MASK 0x400000u

/*! Field P55 - Bit Output Value */
#define OUT_1_P55_POS 23
/*! Field P55 - Bit Output Value */
#define OUT_1_P55_MASK 0x800000u

/*! Field P56 - Bit Output Value */
#define OUT_1_P56_POS 24
/*! Field P56 - Bit Output Value */
#define OUT_1_P56_MASK 0x1000000u

/*! Field P57 - Bit Output Value */
#define OUT_1_P57_POS 25
/*! Field P57 - Bit Output Value */
#define OUT_1_P57_MASK 0x2000000u

/*! Field P58 - Bit Output Value */
#define OUT_1_P58_POS 26
/*! Field P58 - Bit Output Value */
#define OUT_1_P58_MASK 0x4000000u

/*! Field P59 - Bit Output Value */
#define OUT_1_P59_POS 27
/*! Field P59 - Bit Output Value */
#define OUT_1_P59_MASK 0x8000000u

/*! Field P60 - Bit Output Value */
#define OUT_1_P60_POS 28
/*! Field P60 - Bit Output Value */
#define OUT_1_P60_MASK 0x10000000u

/*! Field P61 - Bit Output Value */
#define OUT_1_P61_POS 29
/*! Field P61 - Bit Output Value */
#define OUT_1_P61_MASK 0x20000000u

/*! Field P62 - Bit Output Value */
#define OUT_1_P62_POS 30
/*! Field P62 - Bit Output Value */
#define OUT_1_P62_MASK 0x40000000u

/*! Field P63 - Bit Output Value */
#define OUT_1_P63_POS 31
/*! Field P63 - Bit Output Value */
#define OUT_1_P63_MASK 0x80000000u

/*! @} */

/*! \defgroup IN_1 Register IN_1 - Data Input Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define IN_1 0x104
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IN_1 0x16300104u

/*! Register Reset Value */
#define IN_1_RST 0x00000000u

/*! Field P32 - Bit Latched Input Value */
#define IN_1_P32_POS 0
/*! Field P32 - Bit Latched Input Value */
#define IN_1_P32_MASK 0x1u

/*! Field P33 - Bit Latched Input Value */
#define IN_1_P33_POS 1
/*! Field P33 - Bit Latched Input Value */
#define IN_1_P33_MASK 0x2u

/*! Field P34 - Bit Latched Input Value */
#define IN_1_P34_POS 2
/*! Field P34 - Bit Latched Input Value */
#define IN_1_P34_MASK 0x4u

/*! Field P35 - Bit Latched Input Value */
#define IN_1_P35_POS 3
/*! Field P35 - Bit Latched Input Value */
#define IN_1_P35_MASK 0x8u

/*! Field P36 - Bit Latched Input Value */
#define IN_1_P36_POS 4
/*! Field P36 - Bit Latched Input Value */
#define IN_1_P36_MASK 0x10u

/*! Field P37 - Bit Latched Input Value */
#define IN_1_P37_POS 5
/*! Field P37 - Bit Latched Input Value */
#define IN_1_P37_MASK 0x20u

/*! Field P38 - Bit Latched Input Value */
#define IN_1_P38_POS 6
/*! Field P38 - Bit Latched Input Value */
#define IN_1_P38_MASK 0x40u

/*! Field P39 - Bit Latched Input Value */
#define IN_1_P39_POS 7
/*! Field P39 - Bit Latched Input Value */
#define IN_1_P39_MASK 0x80u

/*! Field P40 - Bit Latched Input Value */
#define IN_1_P40_POS 8
/*! Field P40 - Bit Latched Input Value */
#define IN_1_P40_MASK 0x100u

/*! Field P41 - Bit Latched Input Value */
#define IN_1_P41_POS 9
/*! Field P41 - Bit Latched Input Value */
#define IN_1_P41_MASK 0x200u

/*! Field P42 - Bit Latched Input Value */
#define IN_1_P42_POS 10
/*! Field P42 - Bit Latched Input Value */
#define IN_1_P42_MASK 0x400u

/*! Field P43 - Bit Latched Input Value */
#define IN_1_P43_POS 11
/*! Field P43 - Bit Latched Input Value */
#define IN_1_P43_MASK 0x800u

/*! Field P44 - Bit Latched Input Value */
#define IN_1_P44_POS 12
/*! Field P44 - Bit Latched Input Value */
#define IN_1_P44_MASK 0x1000u

/*! Field P45 - Bit Latched Input Value */
#define IN_1_P45_POS 13
/*! Field P45 - Bit Latched Input Value */
#define IN_1_P45_MASK 0x2000u

/*! Field P46 - Bit Latched Input Value */
#define IN_1_P46_POS 14
/*! Field P46 - Bit Latched Input Value */
#define IN_1_P46_MASK 0x4000u

/*! Field P47 - Bit Latched Input Value */
#define IN_1_P47_POS 15
/*! Field P47 - Bit Latched Input Value */
#define IN_1_P47_MASK 0x8000u

/*! Field P48 - Bit Latched Input Value */
#define IN_1_P48_POS 16
/*! Field P48 - Bit Latched Input Value */
#define IN_1_P48_MASK 0x10000u

/*! Field P49 - Bit Latched Input Value */
#define IN_1_P49_POS 17
/*! Field P49 - Bit Latched Input Value */
#define IN_1_P49_MASK 0x20000u

/*! Field P50 - Bit Latched Input Value */
#define IN_1_P50_POS 18
/*! Field P50 - Bit Latched Input Value */
#define IN_1_P50_MASK 0x40000u

/*! Field P51 - Bit Latched Input Value */
#define IN_1_P51_POS 19
/*! Field P51 - Bit Latched Input Value */
#define IN_1_P51_MASK 0x80000u

/*! Field P52 - Bit Latched Input Value */
#define IN_1_P52_POS 20
/*! Field P52 - Bit Latched Input Value */
#define IN_1_P52_MASK 0x100000u

/*! Field P53 - Bit Latched Input Value */
#define IN_1_P53_POS 21
/*! Field P53 - Bit Latched Input Value */
#define IN_1_P53_MASK 0x200000u

/*! Field P54 - Bit Latched Input Value */
#define IN_1_P54_POS 22
/*! Field P54 - Bit Latched Input Value */
#define IN_1_P54_MASK 0x400000u

/*! Field P55 - Bit Latched Input Value */
#define IN_1_P55_POS 23
/*! Field P55 - Bit Latched Input Value */
#define IN_1_P55_MASK 0x800000u

/*! Field P56 - Bit Latched Input Value */
#define IN_1_P56_POS 24
/*! Field P56 - Bit Latched Input Value */
#define IN_1_P56_MASK 0x1000000u

/*! Field P57 - Bit Latched Input Value */
#define IN_1_P57_POS 25
/*! Field P57 - Bit Latched Input Value */
#define IN_1_P57_MASK 0x2000000u

/*! Field P58 - Bit Latched Input Value */
#define IN_1_P58_POS 26
/*! Field P58 - Bit Latched Input Value */
#define IN_1_P58_MASK 0x4000000u

/*! Field P59 - Bit Latched Input Value */
#define IN_1_P59_POS 27
/*! Field P59 - Bit Latched Input Value */
#define IN_1_P59_MASK 0x8000000u

/*! Field P60 - Bit Latched Input Value */
#define IN_1_P60_POS 28
/*! Field P60 - Bit Latched Input Value */
#define IN_1_P60_MASK 0x10000000u

/*! Field P61 - Bit Latched Input Value */
#define IN_1_P61_POS 29
/*! Field P61 - Bit Latched Input Value */
#define IN_1_P61_MASK 0x20000000u

/*! Field P62 - Bit Latched Input Value */
#define IN_1_P62_POS 30
/*! Field P62 - Bit Latched Input Value */
#define IN_1_P62_MASK 0x40000000u

/*! Field P63 - Bit Latched Input Value */
#define IN_1_P63_POS 31
/*! Field P63 - Bit Latched Input Value */
#define IN_1_P63_MASK 0x80000000u

/*! @} */

/*! \defgroup DIR_1 Register DIR_1 - Direction Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define DIR_1 0x108
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_DIR_1 0x16300108u

/*! Register Reset Value */
#define DIR_1_RST 0x00000000u

/*! Field P32 - Bit Direction */
#define DIR_1_P32_POS 0
/*! Field P32 - Bit Direction */
#define DIR_1_P32_MASK 0x1u
/*! Constant IN - Input */
#define CONST_DIR_1_P32_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P32_OUT 0x1

/*! Field P33 - Bit Direction */
#define DIR_1_P33_POS 1
/*! Field P33 - Bit Direction */
#define DIR_1_P33_MASK 0x2u
/*! Constant IN - Input */
#define CONST_DIR_1_P33_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P33_OUT 0x1

/*! Field P34 - Bit Direction */
#define DIR_1_P34_POS 2
/*! Field P34 - Bit Direction */
#define DIR_1_P34_MASK 0x4u
/*! Constant IN - Input */
#define CONST_DIR_1_P34_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P34_OUT 0x1

/*! Field P35 - Bit Direction */
#define DIR_1_P35_POS 3
/*! Field P35 - Bit Direction */
#define DIR_1_P35_MASK 0x8u
/*! Constant IN - Input */
#define CONST_DIR_1_P35_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P35_OUT 0x1

/*! Field P36 - Bit Direction */
#define DIR_1_P36_POS 4
/*! Field P36 - Bit Direction */
#define DIR_1_P36_MASK 0x10u
/*! Constant IN - Input */
#define CONST_DIR_1_P36_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P36_OUT 0x1

/*! Field P37 - Bit Direction */
#define DIR_1_P37_POS 5
/*! Field P37 - Bit Direction */
#define DIR_1_P37_MASK 0x20u
/*! Constant IN - Input */
#define CONST_DIR_1_P37_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P37_OUT 0x1

/*! Field P38 - Bit Direction */
#define DIR_1_P38_POS 6
/*! Field P38 - Bit Direction */
#define DIR_1_P38_MASK 0x40u
/*! Constant IN - Input */
#define CONST_DIR_1_P38_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P38_OUT 0x1

/*! Field P39 - Bit Direction */
#define DIR_1_P39_POS 7
/*! Field P39 - Bit Direction */
#define DIR_1_P39_MASK 0x80u
/*! Constant IN - Input */
#define CONST_DIR_1_P39_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P39_OUT 0x1

/*! Field P40 - Bit Direction */
#define DIR_1_P40_POS 8
/*! Field P40 - Bit Direction */
#define DIR_1_P40_MASK 0x100u
/*! Constant IN - Input */
#define CONST_DIR_1_P40_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P40_OUT 0x1

/*! Field P41 - Bit Direction */
#define DIR_1_P41_POS 9
/*! Field P41 - Bit Direction */
#define DIR_1_P41_MASK 0x200u
/*! Constant IN - Input */
#define CONST_DIR_1_P41_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P41_OUT 0x1

/*! Field P42 - Bit Direction */
#define DIR_1_P42_POS 10
/*! Field P42 - Bit Direction */
#define DIR_1_P42_MASK 0x400u
/*! Constant IN - Input */
#define CONST_DIR_1_P42_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P42_OUT 0x1

/*! Field P43 - Bit Direction */
#define DIR_1_P43_POS 11
/*! Field P43 - Bit Direction */
#define DIR_1_P43_MASK 0x800u
/*! Constant IN - Input */
#define CONST_DIR_1_P43_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P43_OUT 0x1

/*! Field P44 - Bit Direction */
#define DIR_1_P44_POS 12
/*! Field P44 - Bit Direction */
#define DIR_1_P44_MASK 0x1000u
/*! Constant IN - Input */
#define CONST_DIR_1_P44_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P44_OUT 0x1

/*! Field P45 - Bit Direction */
#define DIR_1_P45_POS 13
/*! Field P45 - Bit Direction */
#define DIR_1_P45_MASK 0x2000u
/*! Constant IN - Input */
#define CONST_DIR_1_P45_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P45_OUT 0x1

/*! Field P46 - Bit Direction */
#define DIR_1_P46_POS 14
/*! Field P46 - Bit Direction */
#define DIR_1_P46_MASK 0x4000u
/*! Constant IN - Input */
#define CONST_DIR_1_P46_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P46_OUT 0x1

/*! Field P47 - Bit Direction */
#define DIR_1_P47_POS 15
/*! Field P47 - Bit Direction */
#define DIR_1_P47_MASK 0x8000u
/*! Constant IN - Input */
#define CONST_DIR_1_P47_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P47_OUT 0x1

/*! Field P48 - Bit Direction */
#define DIR_1_P48_POS 16
/*! Field P48 - Bit Direction */
#define DIR_1_P48_MASK 0x10000u
/*! Constant IN - Input */
#define CONST_DIR_1_P48_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P48_OUT 0x1

/*! Field P49 - Bit Direction */
#define DIR_1_P49_POS 17
/*! Field P49 - Bit Direction */
#define DIR_1_P49_MASK 0x20000u
/*! Constant IN - Input */
#define CONST_DIR_1_P49_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P49_OUT 0x1

/*! Field P50 - Bit Direction */
#define DIR_1_P50_POS 18
/*! Field P50 - Bit Direction */
#define DIR_1_P50_MASK 0x40000u
/*! Constant IN - Input */
#define CONST_DIR_1_P50_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P50_OUT 0x1

/*! Field P51 - Bit Direction */
#define DIR_1_P51_POS 19
/*! Field P51 - Bit Direction */
#define DIR_1_P51_MASK 0x80000u
/*! Constant IN - Input */
#define CONST_DIR_1_P51_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P51_OUT 0x1

/*! Field P52 - Bit Direction */
#define DIR_1_P52_POS 20
/*! Field P52 - Bit Direction */
#define DIR_1_P52_MASK 0x100000u
/*! Constant IN - Input */
#define CONST_DIR_1_P52_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P52_OUT 0x1

/*! Field P53 - Bit Direction */
#define DIR_1_P53_POS 21
/*! Field P53 - Bit Direction */
#define DIR_1_P53_MASK 0x200000u
/*! Constant IN - Input */
#define CONST_DIR_1_P53_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P53_OUT 0x1

/*! Field P54 - Bit Direction */
#define DIR_1_P54_POS 22
/*! Field P54 - Bit Direction */
#define DIR_1_P54_MASK 0x400000u
/*! Constant IN - Input */
#define CONST_DIR_1_P54_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P54_OUT 0x1

/*! Field P55 - Bit Direction */
#define DIR_1_P55_POS 23
/*! Field P55 - Bit Direction */
#define DIR_1_P55_MASK 0x800000u
/*! Constant IN - Input */
#define CONST_DIR_1_P55_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P55_OUT 0x1

/*! Field P56 - Bit Direction */
#define DIR_1_P56_POS 24
/*! Field P56 - Bit Direction */
#define DIR_1_P56_MASK 0x1000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P56_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P56_OUT 0x1

/*! Field P57 - Bit Direction */
#define DIR_1_P57_POS 25
/*! Field P57 - Bit Direction */
#define DIR_1_P57_MASK 0x2000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P57_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P57_OUT 0x1

/*! Field P58 - Bit Direction */
#define DIR_1_P58_POS 26
/*! Field P58 - Bit Direction */
#define DIR_1_P58_MASK 0x4000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P58_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P58_OUT 0x1

/*! Field P59 - Bit Direction */
#define DIR_1_P59_POS 27
/*! Field P59 - Bit Direction */
#define DIR_1_P59_MASK 0x8000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P59_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P59_OUT 0x1

/*! Field P60 - Bit Direction */
#define DIR_1_P60_POS 28
/*! Field P60 - Bit Direction */
#define DIR_1_P60_MASK 0x10000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P60_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P60_OUT 0x1

/*! Field P61 - Bit Direction */
#define DIR_1_P61_POS 29
/*! Field P61 - Bit Direction */
#define DIR_1_P61_MASK 0x20000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P61_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P61_OUT 0x1

/*! Field P62 - Bit Direction */
#define DIR_1_P62_POS 30
/*! Field P62 - Bit Direction */
#define DIR_1_P62_MASK 0x40000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P62_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P62_OUT 0x1

/*! Field P63 - Bit Direction */
#define DIR_1_P63_POS 31
/*! Field P63 - Bit Direction */
#define DIR_1_P63_MASK 0x80000000u
/*! Constant IN - Input */
#define CONST_DIR_1_P63_IN 0x0
/*! Constant OUT - Output */
#define CONST_DIR_1_P63_OUT 0x1

/*! @} */

/*! \defgroup EXINTCR10 Register EXINTCR10 - External Interrupt Control Register 10 */
/*! @{ */

/*! Register Offset (relative) */
#define EXINTCR10 0x118
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_EXINTCR10 0x16300118u

/*! Register Reset Value */
#define EXINTCR10_RST 0x00000000u

/*! Field P32 - Bit External Interrupt Control 0 */
#define EXINTCR10_P32_POS 0
/*! Field P32 - Bit External Interrupt Control 0 */
#define EXINTCR10_P32_MASK 0x1u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P32_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P32_NEG 0x1

/*! Field P33 - Bit External Interrupt Control 0 */
#define EXINTCR10_P33_POS 1
/*! Field P33 - Bit External Interrupt Control 0 */
#define EXINTCR10_P33_MASK 0x2u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P33_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P33_NEG 0x1

/*! Field P34 - Bit External Interrupt Control 0 */
#define EXINTCR10_P34_POS 2
/*! Field P34 - Bit External Interrupt Control 0 */
#define EXINTCR10_P34_MASK 0x4u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P34_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P34_NEG 0x1

/*! Field P35 - Bit External Interrupt Control 0 */
#define EXINTCR10_P35_POS 3
/*! Field P35 - Bit External Interrupt Control 0 */
#define EXINTCR10_P35_MASK 0x8u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P35_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P35_NEG 0x1

/*! Field P36 - Bit External Interrupt Control 0 */
#define EXINTCR10_P36_POS 4
/*! Field P36 - Bit External Interrupt Control 0 */
#define EXINTCR10_P36_MASK 0x10u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P36_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P36_NEG 0x1

/*! Field P37 - Bit External Interrupt Control 0 */
#define EXINTCR10_P37_POS 5
/*! Field P37 - Bit External Interrupt Control 0 */
#define EXINTCR10_P37_MASK 0x20u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P37_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P37_NEG 0x1

/*! Field P38 - Bit External Interrupt Control 0 */
#define EXINTCR10_P38_POS 6
/*! Field P38 - Bit External Interrupt Control 0 */
#define EXINTCR10_P38_MASK 0x40u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P38_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P38_NEG 0x1

/*! Field P39 - Bit External Interrupt Control 0 */
#define EXINTCR10_P39_POS 7
/*! Field P39 - Bit External Interrupt Control 0 */
#define EXINTCR10_P39_MASK 0x80u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P39_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P39_NEG 0x1

/*! Field P40 - Bit External Interrupt Control 0 */
#define EXINTCR10_P40_POS 8
/*! Field P40 - Bit External Interrupt Control 0 */
#define EXINTCR10_P40_MASK 0x100u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P40_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P40_NEG 0x1

/*! Field P41 - Bit External Interrupt Control 0 */
#define EXINTCR10_P41_POS 9
/*! Field P41 - Bit External Interrupt Control 0 */
#define EXINTCR10_P41_MASK 0x200u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P41_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P41_NEG 0x1

/*! Field P42 - Bit External Interrupt Control 0 */
#define EXINTCR10_P42_POS 10
/*! Field P42 - Bit External Interrupt Control 0 */
#define EXINTCR10_P42_MASK 0x400u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P42_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P42_NEG 0x1

/*! Field P43 - Bit External Interrupt Control 0 */
#define EXINTCR10_P43_POS 11
/*! Field P43 - Bit External Interrupt Control 0 */
#define EXINTCR10_P43_MASK 0x800u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P43_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P43_NEG 0x1

/*! Field P44 - Bit External Interrupt Control 0 */
#define EXINTCR10_P44_POS 12
/*! Field P44 - Bit External Interrupt Control 0 */
#define EXINTCR10_P44_MASK 0x1000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P44_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P44_NEG 0x1

/*! Field P45 - Bit External Interrupt Control 0 */
#define EXINTCR10_P45_POS 13
/*! Field P45 - Bit External Interrupt Control 0 */
#define EXINTCR10_P45_MASK 0x2000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P45_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P45_NEG 0x1

/*! Field P46 - Bit External Interrupt Control 0 */
#define EXINTCR10_P46_POS 14
/*! Field P46 - Bit External Interrupt Control 0 */
#define EXINTCR10_P46_MASK 0x4000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P46_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P46_NEG 0x1

/*! Field P47 - Bit External Interrupt Control 0 */
#define EXINTCR10_P47_POS 15
/*! Field P47 - Bit External Interrupt Control 0 */
#define EXINTCR10_P47_MASK 0x8000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P47_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P47_NEG 0x1

/*! Field P48 - Bit External Interrupt Control 0 */
#define EXINTCR10_P48_POS 16
/*! Field P48 - Bit External Interrupt Control 0 */
#define EXINTCR10_P48_MASK 0x10000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P48_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P48_NEG 0x1

/*! Field P49 - Bit External Interrupt Control 0 */
#define EXINTCR10_P49_POS 17
/*! Field P49 - Bit External Interrupt Control 0 */
#define EXINTCR10_P49_MASK 0x20000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P49_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P49_NEG 0x1

/*! Field P50 - Bit External Interrupt Control 0 */
#define EXINTCR10_P50_POS 18
/*! Field P50 - Bit External Interrupt Control 0 */
#define EXINTCR10_P50_MASK 0x40000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P50_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P50_NEG 0x1

/*! Field P51 - Bit External Interrupt Control 0 */
#define EXINTCR10_P51_POS 19
/*! Field P51 - Bit External Interrupt Control 0 */
#define EXINTCR10_P51_MASK 0x80000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P51_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P51_NEG 0x1

/*! Field P52 - Bit External Interrupt Control 0 */
#define EXINTCR10_P52_POS 20
/*! Field P52 - Bit External Interrupt Control 0 */
#define EXINTCR10_P52_MASK 0x100000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P52_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P52_NEG 0x1

/*! Field P53 - Bit External Interrupt Control 0 */
#define EXINTCR10_P53_POS 21
/*! Field P53 - Bit External Interrupt Control 0 */
#define EXINTCR10_P53_MASK 0x200000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P53_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P53_NEG 0x1

/*! Field P54 - Bit External Interrupt Control 0 */
#define EXINTCR10_P54_POS 22
/*! Field P54 - Bit External Interrupt Control 0 */
#define EXINTCR10_P54_MASK 0x400000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P54_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P54_NEG 0x1

/*! Field P55 - Bit External Interrupt Control 0 */
#define EXINTCR10_P55_POS 23
/*! Field P55 - Bit External Interrupt Control 0 */
#define EXINTCR10_P55_MASK 0x800000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P55_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P55_NEG 0x1

/*! Field P56 - Bit External Interrupt Control 0 */
#define EXINTCR10_P56_POS 24
/*! Field P56 - Bit External Interrupt Control 0 */
#define EXINTCR10_P56_MASK 0x1000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P56_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P56_NEG 0x1

/*! Field P57 - Bit External Interrupt Control 0 */
#define EXINTCR10_P57_POS 25
/*! Field P57 - Bit External Interrupt Control 0 */
#define EXINTCR10_P57_MASK 0x2000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P57_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P57_NEG 0x1

/*! Field P58 - Bit External Interrupt Control 0 */
#define EXINTCR10_P58_POS 26
/*! Field P58 - Bit External Interrupt Control 0 */
#define EXINTCR10_P58_MASK 0x4000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P58_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P58_NEG 0x1

/*! Field P59 - Bit External Interrupt Control 0 */
#define EXINTCR10_P59_POS 27
/*! Field P59 - Bit External Interrupt Control 0 */
#define EXINTCR10_P59_MASK 0x8000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P59_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P59_NEG 0x1

/*! Field P60 - Bit External Interrupt Control 0 */
#define EXINTCR10_P60_POS 28
/*! Field P60 - Bit External Interrupt Control 0 */
#define EXINTCR10_P60_MASK 0x10000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P60_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P60_NEG 0x1

/*! Field P61 - Bit External Interrupt Control 0 */
#define EXINTCR10_P61_POS 29
/*! Field P61 - Bit External Interrupt Control 0 */
#define EXINTCR10_P61_MASK 0x20000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P61_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P61_NEG 0x1

/*! Field P62 - Bit External Interrupt Control 0 */
#define EXINTCR10_P62_POS 30
/*! Field P62 - Bit External Interrupt Control 0 */
#define EXINTCR10_P62_MASK 0x40000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P62_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P62_NEG 0x1

/*! Field P63 - Bit External Interrupt Control 0 */
#define EXINTCR10_P63_POS 31
/*! Field P63 - Bit External Interrupt Control 0 */
#define EXINTCR10_P63_MASK 0x80000000u
/*! Constant POS - Positive Logic Event */
#define CONST_EXINTCR10_P63_POS 0x0
/*! Constant NEG - Negative Logic Event */
#define CONST_EXINTCR10_P63_NEG 0x1

/*! @} */

/*! \defgroup EXINTCR11 Register EXINTCR11 - External Interrupt Control Register 11 */
/*! @{ */

/*! Register Offset (relative) */
#define EXINTCR11 0x11C
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_EXINTCR11 0x1630011Cu

/*! Register Reset Value */
#define EXINTCR11_RST 0x00000000u

/*! Field P32 - Bit External Interrupt Control 1 */
#define EXINTCR11_P32_POS 0
/*! Field P32 - Bit External Interrupt Control 1 */
#define EXINTCR11_P32_MASK 0x1u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P32_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P32_BOTH 0x1

/*! Field P33 - Bit External Interrupt Control 1 */
#define EXINTCR11_P33_POS 1
/*! Field P33 - Bit External Interrupt Control 1 */
#define EXINTCR11_P33_MASK 0x2u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P33_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P33_BOTH 0x1

/*! Field P34 - Bit External Interrupt Control 1 */
#define EXINTCR11_P34_POS 2
/*! Field P34 - Bit External Interrupt Control 1 */
#define EXINTCR11_P34_MASK 0x4u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P34_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P34_BOTH 0x1

/*! Field P35 - Bit External Interrupt Control 1 */
#define EXINTCR11_P35_POS 3
/*! Field P35 - Bit External Interrupt Control 1 */
#define EXINTCR11_P35_MASK 0x8u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P35_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P35_BOTH 0x1

/*! Field P36 - Bit External Interrupt Control 1 */
#define EXINTCR11_P36_POS 4
/*! Field P36 - Bit External Interrupt Control 1 */
#define EXINTCR11_P36_MASK 0x10u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P36_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P36_BOTH 0x1

/*! Field P37 - Bit External Interrupt Control 1 */
#define EXINTCR11_P37_POS 5
/*! Field P37 - Bit External Interrupt Control 1 */
#define EXINTCR11_P37_MASK 0x20u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P37_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P37_BOTH 0x1

/*! Field P38 - Bit External Interrupt Control 1 */
#define EXINTCR11_P38_POS 6
/*! Field P38 - Bit External Interrupt Control 1 */
#define EXINTCR11_P38_MASK 0x40u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P38_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P38_BOTH 0x1

/*! Field P39 - Bit External Interrupt Control 1 */
#define EXINTCR11_P39_POS 7
/*! Field P39 - Bit External Interrupt Control 1 */
#define EXINTCR11_P39_MASK 0x80u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P39_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P39_BOTH 0x1

/*! Field P40 - Bit External Interrupt Control 1 */
#define EXINTCR11_P40_POS 8
/*! Field P40 - Bit External Interrupt Control 1 */
#define EXINTCR11_P40_MASK 0x100u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P40_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P40_BOTH 0x1

/*! Field P41 - Bit External Interrupt Control 1 */
#define EXINTCR11_P41_POS 9
/*! Field P41 - Bit External Interrupt Control 1 */
#define EXINTCR11_P41_MASK 0x200u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P41_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P41_BOTH 0x1

/*! Field P42 - Bit External Interrupt Control 1 */
#define EXINTCR11_P42_POS 10
/*! Field P42 - Bit External Interrupt Control 1 */
#define EXINTCR11_P42_MASK 0x400u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P42_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P42_BOTH 0x1

/*! Field P43 - Bit External Interrupt Control 1 */
#define EXINTCR11_P43_POS 11
/*! Field P43 - Bit External Interrupt Control 1 */
#define EXINTCR11_P43_MASK 0x800u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P43_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P43_BOTH 0x1

/*! Field P44 - Bit External Interrupt Control 1 */
#define EXINTCR11_P44_POS 12
/*! Field P44 - Bit External Interrupt Control 1 */
#define EXINTCR11_P44_MASK 0x1000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P44_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P44_BOTH 0x1

/*! Field P45 - Bit External Interrupt Control 1 */
#define EXINTCR11_P45_POS 13
/*! Field P45 - Bit External Interrupt Control 1 */
#define EXINTCR11_P45_MASK 0x2000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P45_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P45_BOTH 0x1

/*! Field P46 - Bit External Interrupt Control 1 */
#define EXINTCR11_P46_POS 14
/*! Field P46 - Bit External Interrupt Control 1 */
#define EXINTCR11_P46_MASK 0x4000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P46_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P46_BOTH 0x1

/*! Field P47 - Bit External Interrupt Control 1 */
#define EXINTCR11_P47_POS 15
/*! Field P47 - Bit External Interrupt Control 1 */
#define EXINTCR11_P47_MASK 0x8000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P47_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P47_BOTH 0x1

/*! Field P48 - Bit External Interrupt Control 1 */
#define EXINTCR11_P48_POS 16
/*! Field P48 - Bit External Interrupt Control 1 */
#define EXINTCR11_P48_MASK 0x10000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P48_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P48_BOTH 0x1

/*! Field P49 - Bit External Interrupt Control 1 */
#define EXINTCR11_P49_POS 17
/*! Field P49 - Bit External Interrupt Control 1 */
#define EXINTCR11_P49_MASK 0x20000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P49_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P49_BOTH 0x1

/*! Field P50 - Bit External Interrupt Control 1 */
#define EXINTCR11_P50_POS 18
/*! Field P50 - Bit External Interrupt Control 1 */
#define EXINTCR11_P50_MASK 0x40000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P50_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P50_BOTH 0x1

/*! Field P51 - Bit External Interrupt Control 1 */
#define EXINTCR11_P51_POS 19
/*! Field P51 - Bit External Interrupt Control 1 */
#define EXINTCR11_P51_MASK 0x80000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P51_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P51_BOTH 0x1

/*! Field P52 - Bit External Interrupt Control 1 */
#define EXINTCR11_P52_POS 20
/*! Field P52 - Bit External Interrupt Control 1 */
#define EXINTCR11_P52_MASK 0x100000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P52_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P52_BOTH 0x1

/*! Field P53 - Bit External Interrupt Control 1 */
#define EXINTCR11_P53_POS 21
/*! Field P53 - Bit External Interrupt Control 1 */
#define EXINTCR11_P53_MASK 0x200000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P53_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P53_BOTH 0x1

/*! Field P54 - Bit External Interrupt Control 1 */
#define EXINTCR11_P54_POS 22
/*! Field P54 - Bit External Interrupt Control 1 */
#define EXINTCR11_P54_MASK 0x400000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P54_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P54_BOTH 0x1

/*! Field P55 - Bit External Interrupt Control 1 */
#define EXINTCR11_P55_POS 23
/*! Field P55 - Bit External Interrupt Control 1 */
#define EXINTCR11_P55_MASK 0x800000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P55_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P55_BOTH 0x1

/*! Field P56 - Bit External Interrupt Control 1 */
#define EXINTCR11_P56_POS 24
/*! Field P56 - Bit External Interrupt Control 1 */
#define EXINTCR11_P56_MASK 0x1000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P56_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P56_BOTH 0x1

/*! Field P57 - Bit External Interrupt Control 1 */
#define EXINTCR11_P57_POS 25
/*! Field P57 - Bit External Interrupt Control 1 */
#define EXINTCR11_P57_MASK 0x2000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P57_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P57_BOTH 0x1

/*! Field P58 - Bit External Interrupt Control 1 */
#define EXINTCR11_P58_POS 26
/*! Field P58 - Bit External Interrupt Control 1 */
#define EXINTCR11_P58_MASK 0x4000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P58_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P58_BOTH 0x1

/*! Field P59 - Bit External Interrupt Control 1 */
#define EXINTCR11_P59_POS 27
/*! Field P59 - Bit External Interrupt Control 1 */
#define EXINTCR11_P59_MASK 0x8000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P59_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P59_BOTH 0x1

/*! Field P60 - Bit External Interrupt Control 1 */
#define EXINTCR11_P60_POS 28
/*! Field P60 - Bit External Interrupt Control 1 */
#define EXINTCR11_P60_MASK 0x10000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P60_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P60_BOTH 0x1

/*! Field P61 - Bit External Interrupt Control 1 */
#define EXINTCR11_P61_POS 29
/*! Field P61 - Bit External Interrupt Control 1 */
#define EXINTCR11_P61_MASK 0x20000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P61_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P61_BOTH 0x1

/*! Field P62 - Bit External Interrupt Control 1 */
#define EXINTCR11_P62_POS 30
/*! Field P62 - Bit External Interrupt Control 1 */
#define EXINTCR11_P62_MASK 0x40000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P62_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P62_BOTH 0x1

/*! Field P63 - Bit External Interrupt Control 1 */
#define EXINTCR11_P63_POS 31
/*! Field P63 - Bit External Interrupt Control 1 */
#define EXINTCR11_P63_MASK 0x80000000u
/*! Constant SGL - Single Edge */
#define CONST_EXINTCR11_P63_SGL 0x0
/*! Constant BOTH - Both Edges */
#define CONST_EXINTCR11_P63_BOTH 0x1

/*! @} */

/*! \defgroup IRNCR_1 Register IRNCR_1 - Interrupt Node Capture Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNCR_1 0x120
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNCR_1 0x16300120u

/*! Register Reset Value */
#define IRNCR_1_RST 0x00000000u

/*! Field P32 - Interrupt Detection Control */
#define IRNCR_1_P32_POS 0
/*! Field P32 - Interrupt Detection Control */
#define IRNCR_1_P32_MASK 0x1u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P32_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P32_INT 0x1

/*! Field P33 - Interrupt Detection Control */
#define IRNCR_1_P33_POS 1
/*! Field P33 - Interrupt Detection Control */
#define IRNCR_1_P33_MASK 0x2u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P33_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P33_INT 0x1

/*! Field P34 - Interrupt Detection Control */
#define IRNCR_1_P34_POS 2
/*! Field P34 - Interrupt Detection Control */
#define IRNCR_1_P34_MASK 0x4u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P34_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P34_INT 0x1

/*! Field P35 - Interrupt Detection Control */
#define IRNCR_1_P35_POS 3
/*! Field P35 - Interrupt Detection Control */
#define IRNCR_1_P35_MASK 0x8u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P35_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P35_INT 0x1

/*! Field P36 - Interrupt Detection Control */
#define IRNCR_1_P36_POS 4
/*! Field P36 - Interrupt Detection Control */
#define IRNCR_1_P36_MASK 0x10u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P36_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P36_INT 0x1

/*! Field P37 - Interrupt Detection Control */
#define IRNCR_1_P37_POS 5
/*! Field P37 - Interrupt Detection Control */
#define IRNCR_1_P37_MASK 0x20u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P37_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P37_INT 0x1

/*! Field P38 - Interrupt Detection Control */
#define IRNCR_1_P38_POS 6
/*! Field P38 - Interrupt Detection Control */
#define IRNCR_1_P38_MASK 0x40u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P38_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P38_INT 0x1

/*! Field P39 - Interrupt Detection Control */
#define IRNCR_1_P39_POS 7
/*! Field P39 - Interrupt Detection Control */
#define IRNCR_1_P39_MASK 0x80u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P39_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P39_INT 0x1

/*! Field P40 - Interrupt Detection Control */
#define IRNCR_1_P40_POS 8
/*! Field P40 - Interrupt Detection Control */
#define IRNCR_1_P40_MASK 0x100u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P40_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P40_INT 0x1

/*! Field P41 - Interrupt Detection Control */
#define IRNCR_1_P41_POS 9
/*! Field P41 - Interrupt Detection Control */
#define IRNCR_1_P41_MASK 0x200u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P41_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P41_INT 0x1

/*! Field P42 - Interrupt Detection Control */
#define IRNCR_1_P42_POS 10
/*! Field P42 - Interrupt Detection Control */
#define IRNCR_1_P42_MASK 0x400u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P42_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P42_INT 0x1

/*! Field P43 - Interrupt Detection Control */
#define IRNCR_1_P43_POS 11
/*! Field P43 - Interrupt Detection Control */
#define IRNCR_1_P43_MASK 0x800u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P43_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P43_INT 0x1

/*! Field P44 - Interrupt Detection Control */
#define IRNCR_1_P44_POS 12
/*! Field P44 - Interrupt Detection Control */
#define IRNCR_1_P44_MASK 0x1000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P44_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P44_INT 0x1

/*! Field P45 - Interrupt Detection Control */
#define IRNCR_1_P45_POS 13
/*! Field P45 - Interrupt Detection Control */
#define IRNCR_1_P45_MASK 0x2000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P45_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P45_INT 0x1

/*! Field P46 - Interrupt Detection Control */
#define IRNCR_1_P46_POS 14
/*! Field P46 - Interrupt Detection Control */
#define IRNCR_1_P46_MASK 0x4000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P46_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P46_INT 0x1

/*! Field P47 - Interrupt Detection Control */
#define IRNCR_1_P47_POS 15
/*! Field P47 - Interrupt Detection Control */
#define IRNCR_1_P47_MASK 0x8000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P47_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P47_INT 0x1

/*! Field P48 - Interrupt Detection Control */
#define IRNCR_1_P48_POS 16
/*! Field P48 - Interrupt Detection Control */
#define IRNCR_1_P48_MASK 0x10000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P48_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P48_INT 0x1

/*! Field P49 - Interrupt Detection Control */
#define IRNCR_1_P49_POS 17
/*! Field P49 - Interrupt Detection Control */
#define IRNCR_1_P49_MASK 0x20000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P49_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P49_INT 0x1

/*! Field P50 - Interrupt Detection Control */
#define IRNCR_1_P50_POS 18
/*! Field P50 - Interrupt Detection Control */
#define IRNCR_1_P50_MASK 0x40000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P50_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P50_INT 0x1

/*! Field P51 - Interrupt Detection Control */
#define IRNCR_1_P51_POS 19
/*! Field P51 - Interrupt Detection Control */
#define IRNCR_1_P51_MASK 0x80000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P51_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P51_INT 0x1

/*! Field P52 - Interrupt Detection Control */
#define IRNCR_1_P52_POS 20
/*! Field P52 - Interrupt Detection Control */
#define IRNCR_1_P52_MASK 0x100000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P52_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P52_INT 0x1

/*! Field P53 - Interrupt Detection Control */
#define IRNCR_1_P53_POS 21
/*! Field P53 - Interrupt Detection Control */
#define IRNCR_1_P53_MASK 0x200000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P53_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P53_INT 0x1

/*! Field P54 - Interrupt Detection Control */
#define IRNCR_1_P54_POS 22
/*! Field P54 - Interrupt Detection Control */
#define IRNCR_1_P54_MASK 0x400000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P54_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P54_INT 0x1

/*! Field P55 - Interrupt Detection Control */
#define IRNCR_1_P55_POS 23
/*! Field P55 - Interrupt Detection Control */
#define IRNCR_1_P55_MASK 0x800000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P55_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P55_INT 0x1

/*! Field P56 - Interrupt Detection Control */
#define IRNCR_1_P56_POS 24
/*! Field P56 - Interrupt Detection Control */
#define IRNCR_1_P56_MASK 0x1000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P56_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P56_INT 0x1

/*! Field P57 - Interrupt Detection Control */
#define IRNCR_1_P57_POS 25
/*! Field P57 - Interrupt Detection Control */
#define IRNCR_1_P57_MASK 0x2000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P57_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P57_INT 0x1

/*! Field P58 - Interrupt Detection Control */
#define IRNCR_1_P58_POS 26
/*! Field P58 - Interrupt Detection Control */
#define IRNCR_1_P58_MASK 0x4000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P58_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P58_INT 0x1

/*! Field P59 - Interrupt Detection Control */
#define IRNCR_1_P59_POS 27
/*! Field P59 - Interrupt Detection Control */
#define IRNCR_1_P59_MASK 0x8000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P59_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P59_INT 0x1

/*! Field P60 - Interrupt Detection Control */
#define IRNCR_1_P60_POS 28
/*! Field P60 - Interrupt Detection Control */
#define IRNCR_1_P60_MASK 0x10000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P60_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P60_INT 0x1

/*! Field P61 - Interrupt Detection Control */
#define IRNCR_1_P61_POS 29
/*! Field P61 - Interrupt Detection Control */
#define IRNCR_1_P61_MASK 0x20000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P61_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P61_INT 0x1

/*! Field P62 - Interrupt Detection Control */
#define IRNCR_1_P62_POS 30
/*! Field P62 - Interrupt Detection Control */
#define IRNCR_1_P62_MASK 0x40000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P62_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P62_INT 0x1

/*! Field P63 - Interrupt Detection Control */
#define IRNCR_1_P63_POS 31
/*! Field P63 - Interrupt Detection Control */
#define IRNCR_1_P63_MASK 0x80000000u
/*! Constant NULL0 - Both Edges */
#define CONST_IRNCR_1_P63_NULL0 0x0
/*! Constant INT - INTOCC / INTACK */
#define CONST_IRNCR_1_P63_INT 0x1

/*! @} */

/*! \defgroup IRNICR_1 Register IRNICR_1 - IRN Interrupt Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNICR_1 0x124
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNICR_1 0x16300124u

/*! Register Reset Value */
#define IRNICR_1_RST 0x00000000u

/*! Field P32 - Pin Interrupt */
#define IRNICR_1_P32_POS 0
/*! Field P32 - Pin Interrupt */
#define IRNICR_1_P32_MASK 0x1u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P32_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P32_INTSET 0x1

/*! Field P33 - Pin Interrupt */
#define IRNICR_1_P33_POS 1
/*! Field P33 - Pin Interrupt */
#define IRNICR_1_P33_MASK 0x2u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P33_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P33_INTSET 0x1

/*! Field P34 - Pin Interrupt */
#define IRNICR_1_P34_POS 2
/*! Field P34 - Pin Interrupt */
#define IRNICR_1_P34_MASK 0x4u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P34_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P34_INTSET 0x1

/*! Field P35 - Pin Interrupt */
#define IRNICR_1_P35_POS 3
/*! Field P35 - Pin Interrupt */
#define IRNICR_1_P35_MASK 0x8u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P35_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P35_INTSET 0x1

/*! Field P36 - Pin Interrupt */
#define IRNICR_1_P36_POS 4
/*! Field P36 - Pin Interrupt */
#define IRNICR_1_P36_MASK 0x10u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P36_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P36_INTSET 0x1

/*! Field P37 - Pin Interrupt */
#define IRNICR_1_P37_POS 5
/*! Field P37 - Pin Interrupt */
#define IRNICR_1_P37_MASK 0x20u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P37_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P37_INTSET 0x1

/*! Field P38 - Pin Interrupt */
#define IRNICR_1_P38_POS 6
/*! Field P38 - Pin Interrupt */
#define IRNICR_1_P38_MASK 0x40u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P38_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P38_INTSET 0x1

/*! Field P39 - Pin Interrupt */
#define IRNICR_1_P39_POS 7
/*! Field P39 - Pin Interrupt */
#define IRNICR_1_P39_MASK 0x80u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P39_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P39_INTSET 0x1

/*! Field P40 - Pin Interrupt */
#define IRNICR_1_P40_POS 8
/*! Field P40 - Pin Interrupt */
#define IRNICR_1_P40_MASK 0x100u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P40_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P40_INTSET 0x1

/*! Field P41 - Pin Interrupt */
#define IRNICR_1_P41_POS 9
/*! Field P41 - Pin Interrupt */
#define IRNICR_1_P41_MASK 0x200u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P41_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P41_INTSET 0x1

/*! Field P42 - Pin Interrupt */
#define IRNICR_1_P42_POS 10
/*! Field P42 - Pin Interrupt */
#define IRNICR_1_P42_MASK 0x400u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P42_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P42_INTSET 0x1

/*! Field P43 - Pin Interrupt */
#define IRNICR_1_P43_POS 11
/*! Field P43 - Pin Interrupt */
#define IRNICR_1_P43_MASK 0x800u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P43_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P43_INTSET 0x1

/*! Field P44 - Pin Interrupt */
#define IRNICR_1_P44_POS 12
/*! Field P44 - Pin Interrupt */
#define IRNICR_1_P44_MASK 0x1000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P44_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P44_INTSET 0x1

/*! Field P45 - Pin Interrupt */
#define IRNICR_1_P45_POS 13
/*! Field P45 - Pin Interrupt */
#define IRNICR_1_P45_MASK 0x2000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P45_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P45_INTSET 0x1

/*! Field P46 - Pin Interrupt */
#define IRNICR_1_P46_POS 14
/*! Field P46 - Pin Interrupt */
#define IRNICR_1_P46_MASK 0x4000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P46_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P46_INTSET 0x1

/*! Field P47 - Pin Interrupt */
#define IRNICR_1_P47_POS 15
/*! Field P47 - Pin Interrupt */
#define IRNICR_1_P47_MASK 0x8000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P47_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P47_INTSET 0x1

/*! Field P48 - Pin Interrupt */
#define IRNICR_1_P48_POS 16
/*! Field P48 - Pin Interrupt */
#define IRNICR_1_P48_MASK 0x10000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P48_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P48_INTSET 0x1

/*! Field P49 - Pin Interrupt */
#define IRNICR_1_P49_POS 17
/*! Field P49 - Pin Interrupt */
#define IRNICR_1_P49_MASK 0x20000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P49_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P49_INTSET 0x1

/*! Field P50 - Pin Interrupt */
#define IRNICR_1_P50_POS 18
/*! Field P50 - Pin Interrupt */
#define IRNICR_1_P50_MASK 0x40000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P50_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P50_INTSET 0x1

/*! Field P51 - Pin Interrupt */
#define IRNICR_1_P51_POS 19
/*! Field P51 - Pin Interrupt */
#define IRNICR_1_P51_MASK 0x80000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P51_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P51_INTSET 0x1

/*! Field P52 - Pin Interrupt */
#define IRNICR_1_P52_POS 20
/*! Field P52 - Pin Interrupt */
#define IRNICR_1_P52_MASK 0x100000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P52_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P52_INTSET 0x1

/*! Field P53 - Pin Interrupt */
#define IRNICR_1_P53_POS 21
/*! Field P53 - Pin Interrupt */
#define IRNICR_1_P53_MASK 0x200000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P53_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P53_INTSET 0x1

/*! Field P54 - Pin Interrupt */
#define IRNICR_1_P54_POS 22
/*! Field P54 - Pin Interrupt */
#define IRNICR_1_P54_MASK 0x400000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P54_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P54_INTSET 0x1

/*! Field P55 - Pin Interrupt */
#define IRNICR_1_P55_POS 23
/*! Field P55 - Pin Interrupt */
#define IRNICR_1_P55_MASK 0x800000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P55_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P55_INTSET 0x1

/*! Field P56 - Pin Interrupt */
#define IRNICR_1_P56_POS 24
/*! Field P56 - Pin Interrupt */
#define IRNICR_1_P56_MASK 0x1000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P56_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P56_INTSET 0x1

/*! Field P57 - Pin Interrupt */
#define IRNICR_1_P57_POS 25
/*! Field P57 - Pin Interrupt */
#define IRNICR_1_P57_MASK 0x2000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P57_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P57_INTSET 0x1

/*! Field P58 - Pin Interrupt */
#define IRNICR_1_P58_POS 26
/*! Field P58 - Pin Interrupt */
#define IRNICR_1_P58_MASK 0x4000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P58_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P58_INTSET 0x1

/*! Field P59 - Pin Interrupt */
#define IRNICR_1_P59_POS 27
/*! Field P59 - Pin Interrupt */
#define IRNICR_1_P59_MASK 0x8000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P59_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P59_INTSET 0x1

/*! Field P60 - Pin Interrupt */
#define IRNICR_1_P60_POS 28
/*! Field P60 - Pin Interrupt */
#define IRNICR_1_P60_MASK 0x10000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P60_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P60_INTSET 0x1

/*! Field P61 - Pin Interrupt */
#define IRNICR_1_P61_POS 29
/*! Field P61 - Pin Interrupt */
#define IRNICR_1_P61_MASK 0x20000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P61_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P61_INTSET 0x1

/*! Field P62 - Pin Interrupt */
#define IRNICR_1_P62_POS 30
/*! Field P62 - Pin Interrupt */
#define IRNICR_1_P62_MASK 0x40000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P62_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P62_INTSET 0x1

/*! Field P63 - Pin Interrupt */
#define IRNICR_1_P63_POS 31
/*! Field P63 - Pin Interrupt */
#define IRNICR_1_P63_MASK 0x80000000u
/*! Constant INTDIS - Interrupt Disable */
#define CONST_IRNICR_1_P63_INTDIS 0x0
/*! Constant INTSET - Interrupt Set */
#define CONST_IRNICR_1_P63_INTSET 0x1

/*! @} */

/*! \defgroup IRNEN_1 Register IRNEN_1 - IRN Interrupt Enable Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNEN_1 0x128
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNEN_1 0x16300128u

/*! Register Reset Value */
#define IRNEN_1_RST 0x00000000u

/*! Field P32 - Pin Interrupt Enable */
#define IRNEN_1_P32_POS 0
/*! Field P32 - Pin Interrupt Enable */
#define IRNEN_1_P32_MASK 0x1u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P32_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P32_EN 0x1

/*! Field P33 - Pin Interrupt Enable */
#define IRNEN_1_P33_POS 1
/*! Field P33 - Pin Interrupt Enable */
#define IRNEN_1_P33_MASK 0x2u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P33_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P33_EN 0x1

/*! Field P34 - Pin Interrupt Enable */
#define IRNEN_1_P34_POS 2
/*! Field P34 - Pin Interrupt Enable */
#define IRNEN_1_P34_MASK 0x4u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P34_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P34_EN 0x1

/*! Field P35 - Pin Interrupt Enable */
#define IRNEN_1_P35_POS 3
/*! Field P35 - Pin Interrupt Enable */
#define IRNEN_1_P35_MASK 0x8u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P35_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P35_EN 0x1

/*! Field P36 - Pin Interrupt Enable */
#define IRNEN_1_P36_POS 4
/*! Field P36 - Pin Interrupt Enable */
#define IRNEN_1_P36_MASK 0x10u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P36_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P36_EN 0x1

/*! Field P37 - Pin Interrupt Enable */
#define IRNEN_1_P37_POS 5
/*! Field P37 - Pin Interrupt Enable */
#define IRNEN_1_P37_MASK 0x20u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P37_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P37_EN 0x1

/*! Field P38 - Pin Interrupt Enable */
#define IRNEN_1_P38_POS 6
/*! Field P38 - Pin Interrupt Enable */
#define IRNEN_1_P38_MASK 0x40u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P38_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P38_EN 0x1

/*! Field P39 - Pin Interrupt Enable */
#define IRNEN_1_P39_POS 7
/*! Field P39 - Pin Interrupt Enable */
#define IRNEN_1_P39_MASK 0x80u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P39_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P39_EN 0x1

/*! Field P40 - Pin Interrupt Enable */
#define IRNEN_1_P40_POS 8
/*! Field P40 - Pin Interrupt Enable */
#define IRNEN_1_P40_MASK 0x100u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P40_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P40_EN 0x1

/*! Field P41 - Pin Interrupt Enable */
#define IRNEN_1_P41_POS 9
/*! Field P41 - Pin Interrupt Enable */
#define IRNEN_1_P41_MASK 0x200u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P41_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P41_EN 0x1

/*! Field P42 - Pin Interrupt Enable */
#define IRNEN_1_P42_POS 10
/*! Field P42 - Pin Interrupt Enable */
#define IRNEN_1_P42_MASK 0x400u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P42_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P42_EN 0x1

/*! Field P43 - Pin Interrupt Enable */
#define IRNEN_1_P43_POS 11
/*! Field P43 - Pin Interrupt Enable */
#define IRNEN_1_P43_MASK 0x800u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P43_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P43_EN 0x1

/*! Field P44 - Pin Interrupt Enable */
#define IRNEN_1_P44_POS 12
/*! Field P44 - Pin Interrupt Enable */
#define IRNEN_1_P44_MASK 0x1000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P44_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P44_EN 0x1

/*! Field P45 - Pin Interrupt Enable */
#define IRNEN_1_P45_POS 13
/*! Field P45 - Pin Interrupt Enable */
#define IRNEN_1_P45_MASK 0x2000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P45_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P45_EN 0x1

/*! Field P46 - Pin Interrupt Enable */
#define IRNEN_1_P46_POS 14
/*! Field P46 - Pin Interrupt Enable */
#define IRNEN_1_P46_MASK 0x4000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P46_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P46_EN 0x1

/*! Field P47 - Pin Interrupt Enable */
#define IRNEN_1_P47_POS 15
/*! Field P47 - Pin Interrupt Enable */
#define IRNEN_1_P47_MASK 0x8000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P47_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P47_EN 0x1

/*! Field P48 - Pin Interrupt Enable */
#define IRNEN_1_P48_POS 16
/*! Field P48 - Pin Interrupt Enable */
#define IRNEN_1_P48_MASK 0x10000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P48_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P48_EN 0x1

/*! Field P49 - Pin Interrupt Enable */
#define IRNEN_1_P49_POS 17
/*! Field P49 - Pin Interrupt Enable */
#define IRNEN_1_P49_MASK 0x20000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P49_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P49_EN 0x1

/*! Field P50 - Pin Interrupt Enable */
#define IRNEN_1_P50_POS 18
/*! Field P50 - Pin Interrupt Enable */
#define IRNEN_1_P50_MASK 0x40000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P50_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P50_EN 0x1

/*! Field P51 - Pin Interrupt Enable */
#define IRNEN_1_P51_POS 19
/*! Field P51 - Pin Interrupt Enable */
#define IRNEN_1_P51_MASK 0x80000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P51_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P51_EN 0x1

/*! Field P52 - Pin Interrupt Enable */
#define IRNEN_1_P52_POS 20
/*! Field P52 - Pin Interrupt Enable */
#define IRNEN_1_P52_MASK 0x100000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P52_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P52_EN 0x1

/*! Field P53 - Pin Interrupt Enable */
#define IRNEN_1_P53_POS 21
/*! Field P53 - Pin Interrupt Enable */
#define IRNEN_1_P53_MASK 0x200000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P53_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P53_EN 0x1

/*! Field P54 - Pin Interrupt Enable */
#define IRNEN_1_P54_POS 22
/*! Field P54 - Pin Interrupt Enable */
#define IRNEN_1_P54_MASK 0x400000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P54_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P54_EN 0x1

/*! Field P55 - Pin Interrupt Enable */
#define IRNEN_1_P55_POS 23
/*! Field P55 - Pin Interrupt Enable */
#define IRNEN_1_P55_MASK 0x800000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P55_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P55_EN 0x1

/*! Field P56 - Pin Interrupt Enable */
#define IRNEN_1_P56_POS 24
/*! Field P56 - Pin Interrupt Enable */
#define IRNEN_1_P56_MASK 0x1000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P56_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P56_EN 0x1

/*! Field P57 - Pin Interrupt Enable */
#define IRNEN_1_P57_POS 25
/*! Field P57 - Pin Interrupt Enable */
#define IRNEN_1_P57_MASK 0x2000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P57_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P57_EN 0x1

/*! Field P58 - Pin Interrupt Enable */
#define IRNEN_1_P58_POS 26
/*! Field P58 - Pin Interrupt Enable */
#define IRNEN_1_P58_MASK 0x4000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P58_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P58_EN 0x1

/*! Field P59 - Pin Interrupt Enable */
#define IRNEN_1_P59_POS 27
/*! Field P59 - Pin Interrupt Enable */
#define IRNEN_1_P59_MASK 0x8000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P59_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P59_EN 0x1

/*! Field P60 - Pin Interrupt Enable */
#define IRNEN_1_P60_POS 28
/*! Field P60 - Pin Interrupt Enable */
#define IRNEN_1_P60_MASK 0x10000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P60_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P60_EN 0x1

/*! Field P61 - Pin Interrupt Enable */
#define IRNEN_1_P61_POS 29
/*! Field P61 - Pin Interrupt Enable */
#define IRNEN_1_P61_MASK 0x20000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P61_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P61_EN 0x1

/*! Field P62 - Pin Interrupt Enable */
#define IRNEN_1_P62_POS 30
/*! Field P62 - Pin Interrupt Enable */
#define IRNEN_1_P62_MASK 0x40000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P62_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P62_EN 0x1

/*! Field P63 - Pin Interrupt Enable */
#define IRNEN_1_P63_POS 31
/*! Field P63 - Pin Interrupt Enable */
#define IRNEN_1_P63_MASK 0x80000000u
/*! Constant DIS - Disable */
#define CONST_IRNEN_1_P63_DIS 0x0
/*! Constant EN - Enable */
#define CONST_IRNEN_1_P63_EN 0x1

/*! @} */

/*! \defgroup IRNCFG_1 Register IRNCFG_1 - IRN Interrupt Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNCFG_1 0x12C
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNCFG_1 0x1630012Cu

/*! Register Reset Value */
#define IRNCFG_1_RST 0x00000000u

/*! Field P32 - Interrupt mode */
#define IRNCFG_1_P32_POS 0
/*! Field P32 - Interrupt mode */
#define IRNCFG_1_P32_MASK 0x1u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P32_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P32_LEVEL 0x1

/*! Field P33 - Interrupt mode */
#define IRNCFG_1_P33_POS 1
/*! Field P33 - Interrupt mode */
#define IRNCFG_1_P33_MASK 0x2u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P33_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P33_LEVEL 0x1

/*! Field P34 - Interrupt mode */
#define IRNCFG_1_P34_POS 2
/*! Field P34 - Interrupt mode */
#define IRNCFG_1_P34_MASK 0x4u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P34_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P34_LEVEL 0x1

/*! Field P35 - Interrupt mode */
#define IRNCFG_1_P35_POS 3
/*! Field P35 - Interrupt mode */
#define IRNCFG_1_P35_MASK 0x8u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P35_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P35_LEVEL 0x1

/*! Field P36 - Interrupt mode */
#define IRNCFG_1_P36_POS 4
/*! Field P36 - Interrupt mode */
#define IRNCFG_1_P36_MASK 0x10u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P36_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P36_LEVEL 0x1

/*! Field P37 - Interrupt mode */
#define IRNCFG_1_P37_POS 5
/*! Field P37 - Interrupt mode */
#define IRNCFG_1_P37_MASK 0x20u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P37_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P37_LEVEL 0x1

/*! Field P38 - Interrupt mode */
#define IRNCFG_1_P38_POS 6
/*! Field P38 - Interrupt mode */
#define IRNCFG_1_P38_MASK 0x40u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P38_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P38_LEVEL 0x1

/*! Field P39 - Interrupt mode */
#define IRNCFG_1_P39_POS 7
/*! Field P39 - Interrupt mode */
#define IRNCFG_1_P39_MASK 0x80u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P39_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P39_LEVEL 0x1

/*! Field P40 - Interrupt mode */
#define IRNCFG_1_P40_POS 8
/*! Field P40 - Interrupt mode */
#define IRNCFG_1_P40_MASK 0x100u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P40_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P40_LEVEL 0x1

/*! Field P41 - Interrupt mode */
#define IRNCFG_1_P41_POS 9
/*! Field P41 - Interrupt mode */
#define IRNCFG_1_P41_MASK 0x200u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P41_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P41_LEVEL 0x1

/*! Field P42 - Interrupt mode */
#define IRNCFG_1_P42_POS 10
/*! Field P42 - Interrupt mode */
#define IRNCFG_1_P42_MASK 0x400u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P42_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P42_LEVEL 0x1

/*! Field P43 - Interrupt mode */
#define IRNCFG_1_P43_POS 11
/*! Field P43 - Interrupt mode */
#define IRNCFG_1_P43_MASK 0x800u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P43_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P43_LEVEL 0x1

/*! Field P44 - Interrupt mode */
#define IRNCFG_1_P44_POS 12
/*! Field P44 - Interrupt mode */
#define IRNCFG_1_P44_MASK 0x1000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P44_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P44_LEVEL 0x1

/*! Field P45 - Interrupt mode */
#define IRNCFG_1_P45_POS 13
/*! Field P45 - Interrupt mode */
#define IRNCFG_1_P45_MASK 0x2000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P45_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P45_LEVEL 0x1

/*! Field P46 - Interrupt mode */
#define IRNCFG_1_P46_POS 14
/*! Field P46 - Interrupt mode */
#define IRNCFG_1_P46_MASK 0x4000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P46_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P46_LEVEL 0x1

/*! Field P47 - Interrupt mode */
#define IRNCFG_1_P47_POS 15
/*! Field P47 - Interrupt mode */
#define IRNCFG_1_P47_MASK 0x8000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P47_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P47_LEVEL 0x1

/*! Field P48 - Interrupt mode */
#define IRNCFG_1_P48_POS 16
/*! Field P48 - Interrupt mode */
#define IRNCFG_1_P48_MASK 0x10000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P48_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P48_LEVEL 0x1

/*! Field P49 - Interrupt mode */
#define IRNCFG_1_P49_POS 17
/*! Field P49 - Interrupt mode */
#define IRNCFG_1_P49_MASK 0x20000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P49_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P49_LEVEL 0x1

/*! Field P50 - Interrupt mode */
#define IRNCFG_1_P50_POS 18
/*! Field P50 - Interrupt mode */
#define IRNCFG_1_P50_MASK 0x40000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P50_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P50_LEVEL 0x1

/*! Field P51 - Interrupt mode */
#define IRNCFG_1_P51_POS 19
/*! Field P51 - Interrupt mode */
#define IRNCFG_1_P51_MASK 0x80000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P51_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P51_LEVEL 0x1

/*! Field P52 - Interrupt mode */
#define IRNCFG_1_P52_POS 20
/*! Field P52 - Interrupt mode */
#define IRNCFG_1_P52_MASK 0x100000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P52_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P52_LEVEL 0x1

/*! Field P53 - Interrupt mode */
#define IRNCFG_1_P53_POS 21
/*! Field P53 - Interrupt mode */
#define IRNCFG_1_P53_MASK 0x200000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P53_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P53_LEVEL 0x1

/*! Field P54 - Interrupt mode */
#define IRNCFG_1_P54_POS 22
/*! Field P54 - Interrupt mode */
#define IRNCFG_1_P54_MASK 0x400000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P54_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P54_LEVEL 0x1

/*! Field P55 - Interrupt mode */
#define IRNCFG_1_P55_POS 23
/*! Field P55 - Interrupt mode */
#define IRNCFG_1_P55_MASK 0x800000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P55_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P55_LEVEL 0x1

/*! Field P56 - Interrupt mode */
#define IRNCFG_1_P56_POS 24
/*! Field P56 - Interrupt mode */
#define IRNCFG_1_P56_MASK 0x1000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P56_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P56_LEVEL 0x1

/*! Field P57 - Interrupt mode */
#define IRNCFG_1_P57_POS 25
/*! Field P57 - Interrupt mode */
#define IRNCFG_1_P57_MASK 0x2000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P57_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P57_LEVEL 0x1

/*! Field P58 - Interrupt mode */
#define IRNCFG_1_P58_POS 26
/*! Field P58 - Interrupt mode */
#define IRNCFG_1_P58_MASK 0x4000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P58_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P58_LEVEL 0x1

/*! Field P59 - Interrupt mode */
#define IRNCFG_1_P59_POS 27
/*! Field P59 - Interrupt mode */
#define IRNCFG_1_P59_MASK 0x8000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P59_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P59_LEVEL 0x1

/*! Field P60 - Interrupt mode */
#define IRNCFG_1_P60_POS 28
/*! Field P60 - Interrupt mode */
#define IRNCFG_1_P60_MASK 0x10000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P60_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P60_LEVEL 0x1

/*! Field P61 - Interrupt mode */
#define IRNCFG_1_P61_POS 29
/*! Field P61 - Interrupt mode */
#define IRNCFG_1_P61_MASK 0x20000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P61_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P61_LEVEL 0x1

/*! Field P62 - Interrupt mode */
#define IRNCFG_1_P62_POS 30
/*! Field P62 - Interrupt mode */
#define IRNCFG_1_P62_MASK 0x40000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P62_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P62_LEVEL 0x1

/*! Field P63 - Interrupt mode */
#define IRNCFG_1_P63_POS 31
/*! Field P63 - Interrupt mode */
#define IRNCFG_1_P63_MASK 0x80000000u
/*! Constant EDGE - Edge sensitive */
#define CONST_IRNCFG_1_P63_EDGE 0x0
/*! Constant LEVEL - Level sensitive */
#define CONST_IRNCFG_1_P63_LEVEL 0x1

/*! @} */

/*! \defgroup IRNENSET_1 Register IRNENSET_1 - IRN Interrupt Enable Set Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNENSET_1 0x130
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNENSET_1 0x16300130u

/*! Register Reset Value */
#define IRNENSET_1_RST 0x00000000u

/*! Field P32 - Interrupt enable */
#define IRNENSET_1_P32_POS 0
/*! Field P32 - Interrupt enable */
#define IRNENSET_1_P32_MASK 0x1u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P32_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P32_EN 0x1

/*! Field P33 - Interrupt enable */
#define IRNENSET_1_P33_POS 1
/*! Field P33 - Interrupt enable */
#define IRNENSET_1_P33_MASK 0x2u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P33_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P33_EN 0x1

/*! Field P34 - Interrupt enable */
#define IRNENSET_1_P34_POS 2
/*! Field P34 - Interrupt enable */
#define IRNENSET_1_P34_MASK 0x4u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P34_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P34_EN 0x1

/*! Field P35 - Interrupt enable */
#define IRNENSET_1_P35_POS 3
/*! Field P35 - Interrupt enable */
#define IRNENSET_1_P35_MASK 0x8u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P35_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P35_EN 0x1

/*! Field P36 - Interrupt enable */
#define IRNENSET_1_P36_POS 4
/*! Field P36 - Interrupt enable */
#define IRNENSET_1_P36_MASK 0x10u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P36_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P36_EN 0x1

/*! Field P37 - Interrupt enable */
#define IRNENSET_1_P37_POS 5
/*! Field P37 - Interrupt enable */
#define IRNENSET_1_P37_MASK 0x20u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P37_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P37_EN 0x1

/*! Field P38 - Interrupt enable */
#define IRNENSET_1_P38_POS 6
/*! Field P38 - Interrupt enable */
#define IRNENSET_1_P38_MASK 0x40u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P38_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P38_EN 0x1

/*! Field P39 - Interrupt enable */
#define IRNENSET_1_P39_POS 7
/*! Field P39 - Interrupt enable */
#define IRNENSET_1_P39_MASK 0x80u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P39_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P39_EN 0x1

/*! Field P40 - Interrupt enable */
#define IRNENSET_1_P40_POS 8
/*! Field P40 - Interrupt enable */
#define IRNENSET_1_P40_MASK 0x100u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P40_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P40_EN 0x1

/*! Field P41 - Interrupt enable */
#define IRNENSET_1_P41_POS 9
/*! Field P41 - Interrupt enable */
#define IRNENSET_1_P41_MASK 0x200u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P41_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P41_EN 0x1

/*! Field P42 - Interrupt enable */
#define IRNENSET_1_P42_POS 10
/*! Field P42 - Interrupt enable */
#define IRNENSET_1_P42_MASK 0x400u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P42_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P42_EN 0x1

/*! Field P43 - Interrupt enable */
#define IRNENSET_1_P43_POS 11
/*! Field P43 - Interrupt enable */
#define IRNENSET_1_P43_MASK 0x800u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P43_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P43_EN 0x1

/*! Field P44 - Interrupt enable */
#define IRNENSET_1_P44_POS 12
/*! Field P44 - Interrupt enable */
#define IRNENSET_1_P44_MASK 0x1000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P44_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P44_EN 0x1

/*! Field P45 - Interrupt enable */
#define IRNENSET_1_P45_POS 13
/*! Field P45 - Interrupt enable */
#define IRNENSET_1_P45_MASK 0x2000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P45_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P45_EN 0x1

/*! Field P46 - Interrupt enable */
#define IRNENSET_1_P46_POS 14
/*! Field P46 - Interrupt enable */
#define IRNENSET_1_P46_MASK 0x4000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P46_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P46_EN 0x1

/*! Field P47 - Interrupt enable */
#define IRNENSET_1_P47_POS 15
/*! Field P47 - Interrupt enable */
#define IRNENSET_1_P47_MASK 0x8000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P47_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P47_EN 0x1

/*! Field P48 - Interrupt enable */
#define IRNENSET_1_P48_POS 16
/*! Field P48 - Interrupt enable */
#define IRNENSET_1_P48_MASK 0x10000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P48_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P48_EN 0x1

/*! Field P49 - Interrupt enable */
#define IRNENSET_1_P49_POS 17
/*! Field P49 - Interrupt enable */
#define IRNENSET_1_P49_MASK 0x20000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P49_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P49_EN 0x1

/*! Field P50 - Interrupt enable */
#define IRNENSET_1_P50_POS 18
/*! Field P50 - Interrupt enable */
#define IRNENSET_1_P50_MASK 0x40000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P50_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P50_EN 0x1

/*! Field P51 - Interrupt enable */
#define IRNENSET_1_P51_POS 19
/*! Field P51 - Interrupt enable */
#define IRNENSET_1_P51_MASK 0x80000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P51_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P51_EN 0x1

/*! Field P52 - Interrupt enable */
#define IRNENSET_1_P52_POS 20
/*! Field P52 - Interrupt enable */
#define IRNENSET_1_P52_MASK 0x100000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P52_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P52_EN 0x1

/*! Field P53 - Interrupt enable */
#define IRNENSET_1_P53_POS 21
/*! Field P53 - Interrupt enable */
#define IRNENSET_1_P53_MASK 0x200000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P53_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P53_EN 0x1

/*! Field P54 - Interrupt enable */
#define IRNENSET_1_P54_POS 22
/*! Field P54 - Interrupt enable */
#define IRNENSET_1_P54_MASK 0x400000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P54_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P54_EN 0x1

/*! Field P55 - Interrupt enable */
#define IRNENSET_1_P55_POS 23
/*! Field P55 - Interrupt enable */
#define IRNENSET_1_P55_MASK 0x800000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P55_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P55_EN 0x1

/*! Field P56 - Interrupt enable */
#define IRNENSET_1_P56_POS 24
/*! Field P56 - Interrupt enable */
#define IRNENSET_1_P56_MASK 0x1000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P56_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P56_EN 0x1

/*! Field P57 - Interrupt enable */
#define IRNENSET_1_P57_POS 25
/*! Field P57 - Interrupt enable */
#define IRNENSET_1_P57_MASK 0x2000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P57_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P57_EN 0x1

/*! Field P58 - Interrupt enable */
#define IRNENSET_1_P58_POS 26
/*! Field P58 - Interrupt enable */
#define IRNENSET_1_P58_MASK 0x4000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P58_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P58_EN 0x1

/*! Field P59 - Interrupt enable */
#define IRNENSET_1_P59_POS 27
/*! Field P59 - Interrupt enable */
#define IRNENSET_1_P59_MASK 0x8000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P59_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P59_EN 0x1

/*! Field P60 - Interrupt enable */
#define IRNENSET_1_P60_POS 28
/*! Field P60 - Interrupt enable */
#define IRNENSET_1_P60_MASK 0x10000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P60_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P60_EN 0x1

/*! Field P61 - Interrupt enable */
#define IRNENSET_1_P61_POS 29
/*! Field P61 - Interrupt enable */
#define IRNENSET_1_P61_MASK 0x20000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P61_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P61_EN 0x1

/*! Field P62 - Interrupt enable */
#define IRNENSET_1_P62_POS 30
/*! Field P62 - Interrupt enable */
#define IRNENSET_1_P62_MASK 0x40000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P62_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P62_EN 0x1

/*! Field P63 - Interrupt enable */
#define IRNENSET_1_P63_POS 31
/*! Field P63 - Interrupt enable */
#define IRNENSET_1_P63_MASK 0x80000000u
/*! Constant NA - No actions */
#define CONST_IRNENSET_1_P63_NA 0x0
/*! Constant EN - Enable */
#define CONST_IRNENSET_1_P63_EN 0x1

/*! @} */

/*! \defgroup IRNENCLR_1 Register IRNENCLR_1 - IRN Interrupt Enable Clear Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define IRNENCLR_1 0x134
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_IRNENCLR_1 0x16300134u

/*! Register Reset Value */
#define IRNENCLR_1_RST 0x00000000u

/*! Field P32 - Interrupt Clear */
#define IRNENCLR_1_P32_POS 0
/*! Field P32 - Interrupt Clear */
#define IRNENCLR_1_P32_MASK 0x1u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P32_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P32_CLR 0x1

/*! Field P33 - Interrupt Clear */
#define IRNENCLR_1_P33_POS 1
/*! Field P33 - Interrupt Clear */
#define IRNENCLR_1_P33_MASK 0x2u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P33_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P33_CLR 0x1

/*! Field P34 - Interrupt Clear */
#define IRNENCLR_1_P34_POS 2
/*! Field P34 - Interrupt Clear */
#define IRNENCLR_1_P34_MASK 0x4u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P34_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P34_CLR 0x1

/*! Field P35 - Interrupt Clear */
#define IRNENCLR_1_P35_POS 3
/*! Field P35 - Interrupt Clear */
#define IRNENCLR_1_P35_MASK 0x8u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P35_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P35_CLR 0x1

/*! Field P36 - Interrupt Clear */
#define IRNENCLR_1_P36_POS 4
/*! Field P36 - Interrupt Clear */
#define IRNENCLR_1_P36_MASK 0x10u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P36_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P36_CLR 0x1

/*! Field P37 - Interrupt Clear */
#define IRNENCLR_1_P37_POS 5
/*! Field P37 - Interrupt Clear */
#define IRNENCLR_1_P37_MASK 0x20u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P37_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P37_CLR 0x1

/*! Field P38 - Interrupt Clear */
#define IRNENCLR_1_P38_POS 6
/*! Field P38 - Interrupt Clear */
#define IRNENCLR_1_P38_MASK 0x40u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P38_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P38_CLR 0x1

/*! Field P39 - Interrupt Clear */
#define IRNENCLR_1_P39_POS 7
/*! Field P39 - Interrupt Clear */
#define IRNENCLR_1_P39_MASK 0x80u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P39_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P39_CLR 0x1

/*! Field P40 - Interrupt Clear */
#define IRNENCLR_1_P40_POS 8
/*! Field P40 - Interrupt Clear */
#define IRNENCLR_1_P40_MASK 0x100u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P40_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P40_CLR 0x1

/*! Field P41 - Interrupt Clear */
#define IRNENCLR_1_P41_POS 9
/*! Field P41 - Interrupt Clear */
#define IRNENCLR_1_P41_MASK 0x200u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P41_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P41_CLR 0x1

/*! Field P42 - Interrupt Clear */
#define IRNENCLR_1_P42_POS 10
/*! Field P42 - Interrupt Clear */
#define IRNENCLR_1_P42_MASK 0x400u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P42_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P42_CLR 0x1

/*! Field P43 - Interrupt Clear */
#define IRNENCLR_1_P43_POS 11
/*! Field P43 - Interrupt Clear */
#define IRNENCLR_1_P43_MASK 0x800u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P43_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P43_CLR 0x1

/*! Field P44 - Interrupt Clear */
#define IRNENCLR_1_P44_POS 12
/*! Field P44 - Interrupt Clear */
#define IRNENCLR_1_P44_MASK 0x1000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P44_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P44_CLR 0x1

/*! Field P45 - Interrupt Clear */
#define IRNENCLR_1_P45_POS 13
/*! Field P45 - Interrupt Clear */
#define IRNENCLR_1_P45_MASK 0x2000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P45_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P45_CLR 0x1

/*! Field P46 - Interrupt Clear */
#define IRNENCLR_1_P46_POS 14
/*! Field P46 - Interrupt Clear */
#define IRNENCLR_1_P46_MASK 0x4000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P46_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P46_CLR 0x1

/*! Field P47 - Interrupt Clear */
#define IRNENCLR_1_P47_POS 15
/*! Field P47 - Interrupt Clear */
#define IRNENCLR_1_P47_MASK 0x8000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P47_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P47_CLR 0x1

/*! Field P48 - Interrupt Clear */
#define IRNENCLR_1_P48_POS 16
/*! Field P48 - Interrupt Clear */
#define IRNENCLR_1_P48_MASK 0x10000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P48_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P48_CLR 0x1

/*! Field P49 - Interrupt Clear */
#define IRNENCLR_1_P49_POS 17
/*! Field P49 - Interrupt Clear */
#define IRNENCLR_1_P49_MASK 0x20000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P49_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P49_CLR 0x1

/*! Field P50 - Interrupt Clear */
#define IRNENCLR_1_P50_POS 18
/*! Field P50 - Interrupt Clear */
#define IRNENCLR_1_P50_MASK 0x40000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P50_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P50_CLR 0x1

/*! Field P51 - Interrupt Clear */
#define IRNENCLR_1_P51_POS 19
/*! Field P51 - Interrupt Clear */
#define IRNENCLR_1_P51_MASK 0x80000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P51_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P51_CLR 0x1

/*! Field P52 - Interrupt Clear */
#define IRNENCLR_1_P52_POS 20
/*! Field P52 - Interrupt Clear */
#define IRNENCLR_1_P52_MASK 0x100000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P52_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P52_CLR 0x1

/*! Field P53 - Interrupt Clear */
#define IRNENCLR_1_P53_POS 21
/*! Field P53 - Interrupt Clear */
#define IRNENCLR_1_P53_MASK 0x200000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P53_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P53_CLR 0x1

/*! Field P54 - Interrupt Clear */
#define IRNENCLR_1_P54_POS 22
/*! Field P54 - Interrupt Clear */
#define IRNENCLR_1_P54_MASK 0x400000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P54_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P54_CLR 0x1

/*! Field P55 - Interrupt Clear */
#define IRNENCLR_1_P55_POS 23
/*! Field P55 - Interrupt Clear */
#define IRNENCLR_1_P55_MASK 0x800000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P55_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P55_CLR 0x1

/*! Field P56 - Interrupt Clear */
#define IRNENCLR_1_P56_POS 24
/*! Field P56 - Interrupt Clear */
#define IRNENCLR_1_P56_MASK 0x1000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P56_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P56_CLR 0x1

/*! Field P57 - Interrupt Clear */
#define IRNENCLR_1_P57_POS 25
/*! Field P57 - Interrupt Clear */
#define IRNENCLR_1_P57_MASK 0x2000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P57_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P57_CLR 0x1

/*! Field P58 - Interrupt Clear */
#define IRNENCLR_1_P58_POS 26
/*! Field P58 - Interrupt Clear */
#define IRNENCLR_1_P58_MASK 0x4000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P58_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P58_CLR 0x1

/*! Field P59 - Interrupt Clear */
#define IRNENCLR_1_P59_POS 27
/*! Field P59 - Interrupt Clear */
#define IRNENCLR_1_P59_MASK 0x8000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P59_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P59_CLR 0x1

/*! Field P60 - Interrupt Clear */
#define IRNENCLR_1_P60_POS 28
/*! Field P60 - Interrupt Clear */
#define IRNENCLR_1_P60_MASK 0x10000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P60_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P60_CLR 0x1

/*! Field P61 - Interrupt Clear */
#define IRNENCLR_1_P61_POS 29
/*! Field P61 - Interrupt Clear */
#define IRNENCLR_1_P61_MASK 0x20000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P61_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P61_CLR 0x1

/*! Field P62 - Interrupt Clear */
#define IRNENCLR_1_P62_POS 30
/*! Field P62 - Interrupt Clear */
#define IRNENCLR_1_P62_MASK 0x40000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P62_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P62_CLR 0x1

/*! Field P63 - Interrupt Clear */
#define IRNENCLR_1_P63_POS 31
/*! Field P63 - Interrupt Clear */
#define IRNENCLR_1_P63_MASK 0x80000000u
/*! Constant NA - No action */
#define CONST_IRNENCLR_1_P63_NA 0x0
/*! Constant CLR - Clear interrupt */
#define CONST_IRNENCLR_1_P63_CLR 0x1

/*! @} */

/*! \defgroup OUTSET_1 Register OUTSET_1 - Output Set Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define OUTSET_1 0x140
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_OUTSET_1 0x16300140u

/*! Register Reset Value */
#define OUTSET_1_RST 0x00000000u

/*! Field P32 - Pin Output Set */
#define OUTSET_1_P32_POS 0
/*! Field P32 - Pin Output Set */
#define OUTSET_1_P32_MASK 0x1u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P32_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P32_SET 0x1

/*! Field P33 - Pin Output Set */
#define OUTSET_1_P33_POS 1
/*! Field P33 - Pin Output Set */
#define OUTSET_1_P33_MASK 0x2u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P33_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P33_SET 0x1

/*! Field P34 - Pin Output Set */
#define OUTSET_1_P34_POS 2
/*! Field P34 - Pin Output Set */
#define OUTSET_1_P34_MASK 0x4u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P34_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P34_SET 0x1

/*! Field P35 - Pin Output Set */
#define OUTSET_1_P35_POS 3
/*! Field P35 - Pin Output Set */
#define OUTSET_1_P35_MASK 0x8u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P35_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P35_SET 0x1

/*! Field P36 - Pin Output Set */
#define OUTSET_1_P36_POS 4
/*! Field P36 - Pin Output Set */
#define OUTSET_1_P36_MASK 0x10u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P36_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P36_SET 0x1

/*! Field P37 - Pin Output Set */
#define OUTSET_1_P37_POS 5
/*! Field P37 - Pin Output Set */
#define OUTSET_1_P37_MASK 0x20u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P37_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P37_SET 0x1

/*! Field P38 - Pin Output Set */
#define OUTSET_1_P38_POS 6
/*! Field P38 - Pin Output Set */
#define OUTSET_1_P38_MASK 0x40u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P38_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P38_SET 0x1

/*! Field P39 - Pin Output Set */
#define OUTSET_1_P39_POS 7
/*! Field P39 - Pin Output Set */
#define OUTSET_1_P39_MASK 0x80u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P39_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P39_SET 0x1

/*! Field P40 - Pin Output Set */
#define OUTSET_1_P40_POS 8
/*! Field P40 - Pin Output Set */
#define OUTSET_1_P40_MASK 0x100u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P40_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P40_SET 0x1

/*! Field P41 - Pin Output Set */
#define OUTSET_1_P41_POS 9
/*! Field P41 - Pin Output Set */
#define OUTSET_1_P41_MASK 0x200u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P41_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P41_SET 0x1

/*! Field P42 - Pin Output Set */
#define OUTSET_1_P42_POS 10
/*! Field P42 - Pin Output Set */
#define OUTSET_1_P42_MASK 0x400u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P42_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P42_SET 0x1

/*! Field P43 - Pin Output Set */
#define OUTSET_1_P43_POS 11
/*! Field P43 - Pin Output Set */
#define OUTSET_1_P43_MASK 0x800u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P43_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P43_SET 0x1

/*! Field P44 - Pin Output Set */
#define OUTSET_1_P44_POS 12
/*! Field P44 - Pin Output Set */
#define OUTSET_1_P44_MASK 0x1000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P44_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P44_SET 0x1

/*! Field P45 - Pin Output Set */
#define OUTSET_1_P45_POS 13
/*! Field P45 - Pin Output Set */
#define OUTSET_1_P45_MASK 0x2000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P45_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P45_SET 0x1

/*! Field P46 - Pin Output Set */
#define OUTSET_1_P46_POS 14
/*! Field P46 - Pin Output Set */
#define OUTSET_1_P46_MASK 0x4000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P46_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P46_SET 0x1

/*! Field P47 - Pin Output Set */
#define OUTSET_1_P47_POS 15
/*! Field P47 - Pin Output Set */
#define OUTSET_1_P47_MASK 0x8000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P47_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P47_SET 0x1

/*! Field P48 - Pin Output Set */
#define OUTSET_1_P48_POS 16
/*! Field P48 - Pin Output Set */
#define OUTSET_1_P48_MASK 0x10000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P48_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P48_SET 0x1

/*! Field P49 - Pin Output Set */
#define OUTSET_1_P49_POS 17
/*! Field P49 - Pin Output Set */
#define OUTSET_1_P49_MASK 0x20000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P49_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P49_SET 0x1

/*! Field P50 - Pin Output Set */
#define OUTSET_1_P50_POS 18
/*! Field P50 - Pin Output Set */
#define OUTSET_1_P50_MASK 0x40000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P50_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P50_SET 0x1

/*! Field P51 - Pin Output Set */
#define OUTSET_1_P51_POS 19
/*! Field P51 - Pin Output Set */
#define OUTSET_1_P51_MASK 0x80000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P51_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P51_SET 0x1

/*! Field P52 - Pin Output Set */
#define OUTSET_1_P52_POS 20
/*! Field P52 - Pin Output Set */
#define OUTSET_1_P52_MASK 0x100000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P52_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P52_SET 0x1

/*! Field P53 - Pin Output Set */
#define OUTSET_1_P53_POS 21
/*! Field P53 - Pin Output Set */
#define OUTSET_1_P53_MASK 0x200000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P53_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P53_SET 0x1

/*! Field P54 - Pin Output Set */
#define OUTSET_1_P54_POS 22
/*! Field P54 - Pin Output Set */
#define OUTSET_1_P54_MASK 0x400000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P54_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P54_SET 0x1

/*! Field P55 - Pin Output Set */
#define OUTSET_1_P55_POS 23
/*! Field P55 - Pin Output Set */
#define OUTSET_1_P55_MASK 0x800000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P55_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P55_SET 0x1

/*! Field P56 - Pin Output Set */
#define OUTSET_1_P56_POS 24
/*! Field P56 - Pin Output Set */
#define OUTSET_1_P56_MASK 0x1000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P56_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P56_SET 0x1

/*! Field P57 - Pin Output Set */
#define OUTSET_1_P57_POS 25
/*! Field P57 - Pin Output Set */
#define OUTSET_1_P57_MASK 0x2000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P57_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P57_SET 0x1

/*! Field P58 - Pin Output Set */
#define OUTSET_1_P58_POS 26
/*! Field P58 - Pin Output Set */
#define OUTSET_1_P58_MASK 0x4000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P58_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P58_SET 0x1

/*! Field P59 - Pin Output Set */
#define OUTSET_1_P59_POS 27
/*! Field P59 - Pin Output Set */
#define OUTSET_1_P59_MASK 0x8000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P59_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P59_SET 0x1

/*! Field P60 - Pin Output Set */
#define OUTSET_1_P60_POS 28
/*! Field P60 - Pin Output Set */
#define OUTSET_1_P60_MASK 0x10000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P60_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P60_SET 0x1

/*! Field P61 - Pin Output Set */
#define OUTSET_1_P61_POS 29
/*! Field P61 - Pin Output Set */
#define OUTSET_1_P61_MASK 0x20000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P61_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P61_SET 0x1

/*! Field P62 - Pin Output Set */
#define OUTSET_1_P62_POS 30
/*! Field P62 - Pin Output Set */
#define OUTSET_1_P62_MASK 0x40000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P62_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P62_SET 0x1

/*! Field P63 - Pin Output Set */
#define OUTSET_1_P63_POS 31
/*! Field P63 - Pin Output Set */
#define OUTSET_1_P63_MASK 0x80000000u
/*! Constant NOP - No operation */
#define CONST_OUTSET_1_P63_NOP 0x0
/*! Constant SET - Set Output pin */
#define CONST_OUTSET_1_P63_SET 0x1

/*! @} */

/*! \defgroup OUTCLR_1 Register OUTCLR_1 - Output Clear Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define OUTCLR_1 0x144
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_OUTCLR_1 0x16300144u

/*! Register Reset Value */
#define OUTCLR_1_RST 0x00000000u

/*! Field P32 - Output Clear */
#define OUTCLR_1_P32_POS 0
/*! Field P32 - Output Clear */
#define OUTCLR_1_P32_MASK 0x1u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P32_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P32_CLR 0x1

/*! Field P33 - Output Clear */
#define OUTCLR_1_P33_POS 1
/*! Field P33 - Output Clear */
#define OUTCLR_1_P33_MASK 0x2u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P33_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P33_CLR 0x1

/*! Field P34 - Output Clear */
#define OUTCLR_1_P34_POS 2
/*! Field P34 - Output Clear */
#define OUTCLR_1_P34_MASK 0x4u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P34_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P34_CLR 0x1

/*! Field P35 - Output Clear */
#define OUTCLR_1_P35_POS 3
/*! Field P35 - Output Clear */
#define OUTCLR_1_P35_MASK 0x8u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P35_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P35_CLR 0x1

/*! Field P36 - Output Clear */
#define OUTCLR_1_P36_POS 4
/*! Field P36 - Output Clear */
#define OUTCLR_1_P36_MASK 0x10u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P36_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P36_CLR 0x1

/*! Field P37 - Output Clear */
#define OUTCLR_1_P37_POS 5
/*! Field P37 - Output Clear */
#define OUTCLR_1_P37_MASK 0x20u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P37_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P37_CLR 0x1

/*! Field P38 - Output Clear */
#define OUTCLR_1_P38_POS 6
/*! Field P38 - Output Clear */
#define OUTCLR_1_P38_MASK 0x40u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P38_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P38_CLR 0x1

/*! Field P39 - Output Clear */
#define OUTCLR_1_P39_POS 7
/*! Field P39 - Output Clear */
#define OUTCLR_1_P39_MASK 0x80u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P39_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P39_CLR 0x1

/*! Field P40 - Output Clear */
#define OUTCLR_1_P40_POS 8
/*! Field P40 - Output Clear */
#define OUTCLR_1_P40_MASK 0x100u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P40_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P40_CLR 0x1

/*! Field P41 - Output Clear */
#define OUTCLR_1_P41_POS 9
/*! Field P41 - Output Clear */
#define OUTCLR_1_P41_MASK 0x200u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P41_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P41_CLR 0x1

/*! Field P42 - Output Clear */
#define OUTCLR_1_P42_POS 10
/*! Field P42 - Output Clear */
#define OUTCLR_1_P42_MASK 0x400u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P42_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P42_CLR 0x1

/*! Field P43 - Output Clear */
#define OUTCLR_1_P43_POS 11
/*! Field P43 - Output Clear */
#define OUTCLR_1_P43_MASK 0x800u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P43_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P43_CLR 0x1

/*! Field P44 - Output Clear */
#define OUTCLR_1_P44_POS 12
/*! Field P44 - Output Clear */
#define OUTCLR_1_P44_MASK 0x1000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P44_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P44_CLR 0x1

/*! Field P45 - Output Clear */
#define OUTCLR_1_P45_POS 13
/*! Field P45 - Output Clear */
#define OUTCLR_1_P45_MASK 0x2000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P45_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P45_CLR 0x1

/*! Field P46 - Output Clear */
#define OUTCLR_1_P46_POS 14
/*! Field P46 - Output Clear */
#define OUTCLR_1_P46_MASK 0x4000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P46_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P46_CLR 0x1

/*! Field P47 - Output Clear */
#define OUTCLR_1_P47_POS 15
/*! Field P47 - Output Clear */
#define OUTCLR_1_P47_MASK 0x8000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P47_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P47_CLR 0x1

/*! Field P48 - Output Clear */
#define OUTCLR_1_P48_POS 16
/*! Field P48 - Output Clear */
#define OUTCLR_1_P48_MASK 0x10000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P48_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P48_CLR 0x1

/*! Field P49 - Output Clear */
#define OUTCLR_1_P49_POS 17
/*! Field P49 - Output Clear */
#define OUTCLR_1_P49_MASK 0x20000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P49_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P49_CLR 0x1

/*! Field P50 - Output Clear */
#define OUTCLR_1_P50_POS 18
/*! Field P50 - Output Clear */
#define OUTCLR_1_P50_MASK 0x40000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P50_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P50_CLR 0x1

/*! Field P51 - Output Clear */
#define OUTCLR_1_P51_POS 19
/*! Field P51 - Output Clear */
#define OUTCLR_1_P51_MASK 0x80000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P51_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P51_CLR 0x1

/*! Field P52 - Output Clear */
#define OUTCLR_1_P52_POS 20
/*! Field P52 - Output Clear */
#define OUTCLR_1_P52_MASK 0x100000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P52_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P52_CLR 0x1

/*! Field P53 - Output Clear */
#define OUTCLR_1_P53_POS 21
/*! Field P53 - Output Clear */
#define OUTCLR_1_P53_MASK 0x200000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P53_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P53_CLR 0x1

/*! Field P54 - Output Clear */
#define OUTCLR_1_P54_POS 22
/*! Field P54 - Output Clear */
#define OUTCLR_1_P54_MASK 0x400000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P54_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P54_CLR 0x1

/*! Field P55 - Output Clear */
#define OUTCLR_1_P55_POS 23
/*! Field P55 - Output Clear */
#define OUTCLR_1_P55_MASK 0x800000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P55_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P55_CLR 0x1

/*! Field P56 - Output Clear */
#define OUTCLR_1_P56_POS 24
/*! Field P56 - Output Clear */
#define OUTCLR_1_P56_MASK 0x1000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P56_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P56_CLR 0x1

/*! Field P57 - Output Clear */
#define OUTCLR_1_P57_POS 25
/*! Field P57 - Output Clear */
#define OUTCLR_1_P57_MASK 0x2000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P57_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P57_CLR 0x1

/*! Field P58 - Output Clear */
#define OUTCLR_1_P58_POS 26
/*! Field P58 - Output Clear */
#define OUTCLR_1_P58_MASK 0x4000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P58_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P58_CLR 0x1

/*! Field P59 - Output Clear */
#define OUTCLR_1_P59_POS 27
/*! Field P59 - Output Clear */
#define OUTCLR_1_P59_MASK 0x8000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P59_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P59_CLR 0x1

/*! Field P60 - Output Clear */
#define OUTCLR_1_P60_POS 28
/*! Field P60 - Output Clear */
#define OUTCLR_1_P60_MASK 0x10000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P60_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P60_CLR 0x1

/*! Field P61 - Output Clear */
#define OUTCLR_1_P61_POS 29
/*! Field P61 - Output Clear */
#define OUTCLR_1_P61_MASK 0x20000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P61_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P61_CLR 0x1

/*! Field P62 - Output Clear */
#define OUTCLR_1_P62_POS 30
/*! Field P62 - Output Clear */
#define OUTCLR_1_P62_MASK 0x40000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P62_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P62_CLR 0x1

/*! Field P63 - Output Clear */
#define OUTCLR_1_P63_POS 31
/*! Field P63 - Output Clear */
#define OUTCLR_1_P63_MASK 0x80000000u
/*! Constant NA - No action */
#define CONST_OUTCLR_1_P63_NA 0x0
/*! Constant CLR - Clear Output */
#define CONST_OUTCLR_1_P63_CLR 0x1

/*! @} */

/*! \defgroup DIRSET_1 Register DIRSET_1 - Direction Set Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define DIRSET_1 0x148
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_DIRSET_1 0x16300148u

/*! Register Reset Value */
#define DIRSET_1_RST 0x00000000u

/*! Field P32 - Pin Direction Set */
#define DIRSET_1_P32_POS 0
/*! Field P32 - Pin Direction Set */
#define DIRSET_1_P32_MASK 0x1u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P32_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P32_SET 0x1

/*! Field P33 - Pin Direction Set */
#define DIRSET_1_P33_POS 1
/*! Field P33 - Pin Direction Set */
#define DIRSET_1_P33_MASK 0x2u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P33_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P33_SET 0x1

/*! Field P34 - Pin Direction Set */
#define DIRSET_1_P34_POS 2
/*! Field P34 - Pin Direction Set */
#define DIRSET_1_P34_MASK 0x4u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P34_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P34_SET 0x1

/*! Field P35 - Pin Direction Set */
#define DIRSET_1_P35_POS 3
/*! Field P35 - Pin Direction Set */
#define DIRSET_1_P35_MASK 0x8u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P35_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P35_SET 0x1

/*! Field P36 - Pin Direction Set */
#define DIRSET_1_P36_POS 4
/*! Field P36 - Pin Direction Set */
#define DIRSET_1_P36_MASK 0x10u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P36_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P36_SET 0x1

/*! Field P37 - Pin Direction Set */
#define DIRSET_1_P37_POS 5
/*! Field P37 - Pin Direction Set */
#define DIRSET_1_P37_MASK 0x20u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P37_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P37_SET 0x1

/*! Field P38 - Pin Direction Set */
#define DIRSET_1_P38_POS 6
/*! Field P38 - Pin Direction Set */
#define DIRSET_1_P38_MASK 0x40u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P38_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P38_SET 0x1

/*! Field P39 - Pin Direction Set */
#define DIRSET_1_P39_POS 7
/*! Field P39 - Pin Direction Set */
#define DIRSET_1_P39_MASK 0x80u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P39_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P39_SET 0x1

/*! Field P40 - Pin Direction Set */
#define DIRSET_1_P40_POS 8
/*! Field P40 - Pin Direction Set */
#define DIRSET_1_P40_MASK 0x100u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P40_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P40_SET 0x1

/*! Field P41 - Pin Direction Set */
#define DIRSET_1_P41_POS 9
/*! Field P41 - Pin Direction Set */
#define DIRSET_1_P41_MASK 0x200u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P41_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P41_SET 0x1

/*! Field P42 - Pin Direction Set */
#define DIRSET_1_P42_POS 10
/*! Field P42 - Pin Direction Set */
#define DIRSET_1_P42_MASK 0x400u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P42_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P42_SET 0x1

/*! Field P43 - Pin Direction Set */
#define DIRSET_1_P43_POS 11
/*! Field P43 - Pin Direction Set */
#define DIRSET_1_P43_MASK 0x800u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P43_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P43_SET 0x1

/*! Field P44 - Pin Direction Set */
#define DIRSET_1_P44_POS 12
/*! Field P44 - Pin Direction Set */
#define DIRSET_1_P44_MASK 0x1000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P44_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P44_SET 0x1

/*! Field P45 - Pin Direction Set */
#define DIRSET_1_P45_POS 13
/*! Field P45 - Pin Direction Set */
#define DIRSET_1_P45_MASK 0x2000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P45_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P45_SET 0x1

/*! Field P46 - Pin Direction Set */
#define DIRSET_1_P46_POS 14
/*! Field P46 - Pin Direction Set */
#define DIRSET_1_P46_MASK 0x4000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P46_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P46_SET 0x1

/*! Field P47 - Pin Direction Set */
#define DIRSET_1_P47_POS 15
/*! Field P47 - Pin Direction Set */
#define DIRSET_1_P47_MASK 0x8000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P47_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P47_SET 0x1

/*! Field P48 - Pin Direction Set */
#define DIRSET_1_P48_POS 16
/*! Field P48 - Pin Direction Set */
#define DIRSET_1_P48_MASK 0x10000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P48_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P48_SET 0x1

/*! Field P49 - Pin Direction Set */
#define DIRSET_1_P49_POS 17
/*! Field P49 - Pin Direction Set */
#define DIRSET_1_P49_MASK 0x20000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P49_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P49_SET 0x1

/*! Field P50 - Pin Direction Set */
#define DIRSET_1_P50_POS 18
/*! Field P50 - Pin Direction Set */
#define DIRSET_1_P50_MASK 0x40000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P50_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P50_SET 0x1

/*! Field P51 - Pin Direction Set */
#define DIRSET_1_P51_POS 19
/*! Field P51 - Pin Direction Set */
#define DIRSET_1_P51_MASK 0x80000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P51_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P51_SET 0x1

/*! Field P52 - Pin Direction Set */
#define DIRSET_1_P52_POS 20
/*! Field P52 - Pin Direction Set */
#define DIRSET_1_P52_MASK 0x100000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P52_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P52_SET 0x1

/*! Field P53 - Pin Direction Set */
#define DIRSET_1_P53_POS 21
/*! Field P53 - Pin Direction Set */
#define DIRSET_1_P53_MASK 0x200000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P53_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P53_SET 0x1

/*! Field P54 - Pin Direction Set */
#define DIRSET_1_P54_POS 22
/*! Field P54 - Pin Direction Set */
#define DIRSET_1_P54_MASK 0x400000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P54_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P54_SET 0x1

/*! Field P55 - Pin Direction Set */
#define DIRSET_1_P55_POS 23
/*! Field P55 - Pin Direction Set */
#define DIRSET_1_P55_MASK 0x800000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P55_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P55_SET 0x1

/*! Field P56 - Pin Direction Set */
#define DIRSET_1_P56_POS 24
/*! Field P56 - Pin Direction Set */
#define DIRSET_1_P56_MASK 0x1000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P56_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P56_SET 0x1

/*! Field P57 - Pin Direction Set */
#define DIRSET_1_P57_POS 25
/*! Field P57 - Pin Direction Set */
#define DIRSET_1_P57_MASK 0x2000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P57_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P57_SET 0x1

/*! Field P58 - Pin Direction Set */
#define DIRSET_1_P58_POS 26
/*! Field P58 - Pin Direction Set */
#define DIRSET_1_P58_MASK 0x4000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P58_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P58_SET 0x1

/*! Field P59 - Pin Direction Set */
#define DIRSET_1_P59_POS 27
/*! Field P59 - Pin Direction Set */
#define DIRSET_1_P59_MASK 0x8000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P59_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P59_SET 0x1

/*! Field P60 - Pin Direction Set */
#define DIRSET_1_P60_POS 28
/*! Field P60 - Pin Direction Set */
#define DIRSET_1_P60_MASK 0x10000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P60_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P60_SET 0x1

/*! Field P61 - Pin Direction Set */
#define DIRSET_1_P61_POS 29
/*! Field P61 - Pin Direction Set */
#define DIRSET_1_P61_MASK 0x20000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P61_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P61_SET 0x1

/*! Field P62 - Pin Direction Set */
#define DIRSET_1_P62_POS 30
/*! Field P62 - Pin Direction Set */
#define DIRSET_1_P62_MASK 0x40000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P62_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P62_SET 0x1

/*! Field P63 - Pin Direction Set */
#define DIRSET_1_P63_POS 31
/*! Field P63 - Pin Direction Set */
#define DIRSET_1_P63_MASK 0x80000000u
/*! Constant NOP - No operation */
#define CONST_DIRSET_1_P63_NOP 0x0
/*! Constant SET - Set the Direction */
#define CONST_DIRSET_1_P63_SET 0x1

/*! @} */

/*! \defgroup DIRCLR_1 Register DIRCLR_1 - Direction Clear Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define DIRCLR_1 0x14C
/*! Register Offset (absolute) for 1st Instance GPIO_FUNCTION */
#define GPIO_FUNCTION_DIRCLR_1 0x1630014Cu

/*! Register Reset Value */
#define DIRCLR_1_RST 0x00000000u

/*! Field P32 - Direction Clear */
#define DIRCLR_1_P32_POS 0
/*! Field P32 - Direction Clear */
#define DIRCLR_1_P32_MASK 0x1u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P32_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P32_CLR 0x1

/*! Field P33 - Direction Clear */
#define DIRCLR_1_P33_POS 1
/*! Field P33 - Direction Clear */
#define DIRCLR_1_P33_MASK 0x2u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P33_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P33_CLR 0x1

/*! Field P34 - Direction Clear */
#define DIRCLR_1_P34_POS 2
/*! Field P34 - Direction Clear */
#define DIRCLR_1_P34_MASK 0x4u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P34_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P34_CLR 0x1

/*! Field P35 - Direction Clear */
#define DIRCLR_1_P35_POS 3
/*! Field P35 - Direction Clear */
#define DIRCLR_1_P35_MASK 0x8u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P35_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P35_CLR 0x1

/*! Field P36 - Direction Clear */
#define DIRCLR_1_P36_POS 4
/*! Field P36 - Direction Clear */
#define DIRCLR_1_P36_MASK 0x10u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P36_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P36_CLR 0x1

/*! Field P37 - Direction Clear */
#define DIRCLR_1_P37_POS 5
/*! Field P37 - Direction Clear */
#define DIRCLR_1_P37_MASK 0x20u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P37_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P37_CLR 0x1

/*! Field P38 - Direction Clear */
#define DIRCLR_1_P38_POS 6
/*! Field P38 - Direction Clear */
#define DIRCLR_1_P38_MASK 0x40u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P38_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P38_CLR 0x1

/*! Field P39 - Direction Clear */
#define DIRCLR_1_P39_POS 7
/*! Field P39 - Direction Clear */
#define DIRCLR_1_P39_MASK 0x80u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P39_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P39_CLR 0x1

/*! Field P40 - Direction Clear */
#define DIRCLR_1_P40_POS 8
/*! Field P40 - Direction Clear */
#define DIRCLR_1_P40_MASK 0x100u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P40_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P40_CLR 0x1

/*! Field P41 - Direction Clear */
#define DIRCLR_1_P41_POS 9
/*! Field P41 - Direction Clear */
#define DIRCLR_1_P41_MASK 0x200u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P41_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P41_CLR 0x1

/*! Field P42 - Direction Clear */
#define DIRCLR_1_P42_POS 10
/*! Field P42 - Direction Clear */
#define DIRCLR_1_P42_MASK 0x400u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P42_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P42_CLR 0x1

/*! Field P43 - Direction Clear */
#define DIRCLR_1_P43_POS 11
/*! Field P43 - Direction Clear */
#define DIRCLR_1_P43_MASK 0x800u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P43_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P43_CLR 0x1

/*! Field P44 - Direction Clear */
#define DIRCLR_1_P44_POS 12
/*! Field P44 - Direction Clear */
#define DIRCLR_1_P44_MASK 0x1000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P44_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P44_CLR 0x1

/*! Field P45 - Direction Clear */
#define DIRCLR_1_P45_POS 13
/*! Field P45 - Direction Clear */
#define DIRCLR_1_P45_MASK 0x2000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P45_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P45_CLR 0x1

/*! Field P46 - Direction Clear */
#define DIRCLR_1_P46_POS 14
/*! Field P46 - Direction Clear */
#define DIRCLR_1_P46_MASK 0x4000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P46_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P46_CLR 0x1

/*! Field P47 - Direction Clear */
#define DIRCLR_1_P47_POS 15
/*! Field P47 - Direction Clear */
#define DIRCLR_1_P47_MASK 0x8000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P47_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P47_CLR 0x1

/*! Field P48 - Direction Clear */
#define DIRCLR_1_P48_POS 16
/*! Field P48 - Direction Clear */
#define DIRCLR_1_P48_MASK 0x10000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P48_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P48_CLR 0x1

/*! Field P49 - Direction Clear */
#define DIRCLR_1_P49_POS 17
/*! Field P49 - Direction Clear */
#define DIRCLR_1_P49_MASK 0x20000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P49_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P49_CLR 0x1

/*! Field P50 - Direction Clear */
#define DIRCLR_1_P50_POS 18
/*! Field P50 - Direction Clear */
#define DIRCLR_1_P50_MASK 0x40000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P50_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P50_CLR 0x1

/*! Field P51 - Direction Clear */
#define DIRCLR_1_P51_POS 19
/*! Field P51 - Direction Clear */
#define DIRCLR_1_P51_MASK 0x80000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P51_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P51_CLR 0x1

/*! Field P52 - Direction Clear */
#define DIRCLR_1_P52_POS 20
/*! Field P52 - Direction Clear */
#define DIRCLR_1_P52_MASK 0x100000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P52_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P52_CLR 0x1

/*! Field P53 - Direction Clear */
#define DIRCLR_1_P53_POS 21
/*! Field P53 - Direction Clear */
#define DIRCLR_1_P53_MASK 0x200000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P53_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P53_CLR 0x1

/*! Field P54 - Direction Clear */
#define DIRCLR_1_P54_POS 22
/*! Field P54 - Direction Clear */
#define DIRCLR_1_P54_MASK 0x400000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P54_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P54_CLR 0x1

/*! Field P55 - Direction Clear */
#define DIRCLR_1_P55_POS 23
/*! Field P55 - Direction Clear */
#define DIRCLR_1_P55_MASK 0x800000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P55_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P55_CLR 0x1

/*! Field P56 - Direction Clear */
#define DIRCLR_1_P56_POS 24
/*! Field P56 - Direction Clear */
#define DIRCLR_1_P56_MASK 0x1000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P56_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P56_CLR 0x1

/*! Field P57 - Direction Clear */
#define DIRCLR_1_P57_POS 25
/*! Field P57 - Direction Clear */
#define DIRCLR_1_P57_MASK 0x2000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P57_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P57_CLR 0x1

/*! Field P58 - Direction Clear */
#define DIRCLR_1_P58_POS 26
/*! Field P58 - Direction Clear */
#define DIRCLR_1_P58_MASK 0x4000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P58_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P58_CLR 0x1

/*! Field P59 - Direction Clear */
#define DIRCLR_1_P59_POS 27
/*! Field P59 - Direction Clear */
#define DIRCLR_1_P59_MASK 0x8000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P59_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P59_CLR 0x1

/*! Field P60 - Direction Clear */
#define DIRCLR_1_P60_POS 28
/*! Field P60 - Direction Clear */
#define DIRCLR_1_P60_MASK 0x10000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P60_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P60_CLR 0x1

/*! Field P61 - Direction Clear */
#define DIRCLR_1_P61_POS 29
/*! Field P61 - Direction Clear */
#define DIRCLR_1_P61_MASK 0x20000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P61_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P61_CLR 0x1

/*! Field P62 - Direction Clear */
#define DIRCLR_1_P62_POS 30
/*! Field P62 - Direction Clear */
#define DIRCLR_1_P62_MASK 0x40000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P62_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P62_CLR 0x1

/*! Field P63 - Direction Clear */
#define DIRCLR_1_P63_POS 31
/*! Field P63 - Direction Clear */
#define DIRCLR_1_P63_MASK 0x80000000u
/*! Constant NA - No action */
#define CONST_DIRCLR_1_P63_NA 0x0
/*! Constant CLR - Clear Direction */
#define CONST_DIRCLR_1_P63_CLR 0x1

/*! @} */

/*! @} */

#endif
