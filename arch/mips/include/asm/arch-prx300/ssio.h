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

#ifndef _SSIO_H
#define _SSIO_H

/*! \defgroup SSIO Register File SSIO - Serial Shift Output Controller Registers */
/*! @{ */

/*! Base Address of SSIO */
#define SSIO_MODULE_BASE 0x16320000u

/*! \defgroup LED_BLINK_H8_0 Register LED_BLINK_H8_0 - Control of LED[28:24] for individual blink rate */
/*! @{ */

/*! Register Offset (relative) */
#define LED_BLINK_H8_0 0x0
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_LED_BLINK_H8_0 0x16320000u

/*! Register Reset Value */
#define LED_BLINK_H8_0_RST 0x00000000u

/*! Field FPID_24 - FSC Divider for LED24 */
#define LED_BLINK_H8_0_FPID_24_POS 0
/*! Field FPID_24 - FSC Divider for LED24 */
#define LED_BLINK_H8_0_FPID_24_MASK 0x3u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_0_FPID_24_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_0_FPID_24_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_0_FPID_24_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_0_FPID_24_V10HZ 0x3

/*! Field GPTD_24 - GPT Divider for LED24 */
#define LED_BLINK_H8_0_GPTD_24_POS 2
/*! Field GPTD_24 - GPT Divider for LED24 */
#define LED_BLINK_H8_0_GPTD_24_MASK 0xCu
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_0_GPTD_24_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_0_GPTD_24_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_0_GPTD_24_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_0_GPTD_24_V250HZ 0x3

/*! Field BLINK_24 - Set Blink rate for LED 24 */
#define LED_BLINK_H8_0_BLINK_24_POS 4
/*! Field BLINK_24 - Set Blink rate for LED 24 */
#define LED_BLINK_H8_0_BLINK_24_MASK 0x30u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_0_BLINK_24_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_0_BLINK_24_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_0_BLINK_24_V1M 0x2

/*! Field FPID_25 - FSC Divider for LED25 */
#define LED_BLINK_H8_0_FPID_25_POS 6
/*! Field FPID_25 - FSC Divider for LED25 */
#define LED_BLINK_H8_0_FPID_25_MASK 0xC0u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_0_FPID_25_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_0_FPID_25_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_0_FPID_25_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_0_FPID_25_V10HZ 0x3

/*! Field GPTD_25 - GPT Divider for LED25 */
#define LED_BLINK_H8_0_GPTD_25_POS 8
/*! Field GPTD_25 - GPT Divider for LED25 */
#define LED_BLINK_H8_0_GPTD_25_MASK 0x300u
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_0_GPTD_25_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_0_GPTD_25_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_0_GPTD_25_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_0_GPTD_25_V250HZ 0x3

/*! Field BLINK_25 - Set Blink rate for LED 25 */
#define LED_BLINK_H8_0_BLINK_25_POS 10
/*! Field BLINK_25 - Set Blink rate for LED 25 */
#define LED_BLINK_H8_0_BLINK_25_MASK 0xC00u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_0_BLINK_25_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_0_BLINK_25_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_0_BLINK_25_V1M 0x2

/*! Field FPID_26 - FSC Divider for LED26 */
#define LED_BLINK_H8_0_FPID_26_POS 12
/*! Field FPID_26 - FSC Divider for LED26 */
#define LED_BLINK_H8_0_FPID_26_MASK 0x3000u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_0_FPID_26_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_0_FPID_26_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_0_FPID_26_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_0_FPID_26_V10HZ 0x3

/*! Field GPTD_26 - GPT Divider for LED26 */
#define LED_BLINK_H8_0_GPTD_26_POS 14
/*! Field GPTD_26 - GPT Divider for LED26 */
#define LED_BLINK_H8_0_GPTD_26_MASK 0xC000u
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_0_GPTD_26_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_0_GPTD_26_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_0_GPTD_26_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_0_GPTD_26_V250HZ 0x3

/*! Field BLINK_26 - Set Blink rate for LED 26 */
#define LED_BLINK_H8_0_BLINK_26_POS 16
/*! Field BLINK_26 - Set Blink rate for LED 26 */
#define LED_BLINK_H8_0_BLINK_26_MASK 0x30000u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_0_BLINK_26_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_0_BLINK_26_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_0_BLINK_26_V1M 0x2

/*! Field FPID_27 - FSC Divider for LED27 */
#define LED_BLINK_H8_0_FPID_27_POS 18
/*! Field FPID_27 - FSC Divider for LED27 */
#define LED_BLINK_H8_0_FPID_27_MASK 0xC0000u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_0_FPID_27_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_0_FPID_27_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_0_FPID_27_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_0_FPID_27_V10HZ 0x3

/*! Field GPTD_27 - GPT Divider for LED27 */
#define LED_BLINK_H8_0_GPTD_27_POS 20
/*! Field GPTD_27 - GPT Divider for LED27 */
#define LED_BLINK_H8_0_GPTD_27_MASK 0x300000u
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_0_GPTD_27_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_0_GPTD_27_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_0_GPTD_27_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_0_GPTD_27_V250HZ 0x3

/*! Field BLINK_27 - Set Blink rate for LED 27 */
#define LED_BLINK_H8_0_BLINK_27_POS 22
/*! Field BLINK_27 - Set Blink rate for LED 27 */
#define LED_BLINK_H8_0_BLINK_27_MASK 0xC00000u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_0_BLINK_27_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_0_BLINK_27_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_0_BLINK_27_V1M 0x2

/*! Field FPID_28 - FSC Divider for LED28 */
#define LED_BLINK_H8_0_FPID_28_POS 24
/*! Field FPID_28 - FSC Divider for LED28 */
#define LED_BLINK_H8_0_FPID_28_MASK 0x3000000u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_0_FPID_28_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_0_FPID_28_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_0_FPID_28_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_0_FPID_28_V10HZ 0x3

/*! Field GPTD_28 - GPT Divider for LED28 */
#define LED_BLINK_H8_0_GPTD_28_POS 26
/*! Field GPTD_28 - GPT Divider for LED28 */
#define LED_BLINK_H8_0_GPTD_28_MASK 0xC000000u
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_0_GPTD_28_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_0_GPTD_28_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_0_GPTD_28_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_0_GPTD_28_V250HZ 0x3

/*! Field BLINK_28 - Set Blink rate for LED 28 */
#define LED_BLINK_H8_0_BLINK_28_POS 28
/*! Field BLINK_28 - Set Blink rate for LED 28 */
#define LED_BLINK_H8_0_BLINK_28_MASK 0x30000000u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_0_BLINK_28_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_0_BLINK_28_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_0_BLINK_28_V1M 0x2

/*! @} */

/*! \defgroup LED_BLINK_H8_1 Register LED_BLINK_H8_1 - Control of LED[31:29] for individual blink rate */
/*! @{ */

/*! Register Offset (relative) */
#define LED_BLINK_H8_1 0x4
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_LED_BLINK_H8_1 0x16320004u

/*! Register Reset Value */
#define LED_BLINK_H8_1_RST 0x00000000u

/*! Field FPID_29 - FSC Divider for LED29 */
#define LED_BLINK_H8_1_FPID_29_POS 0
/*! Field FPID_29 - FSC Divider for LED29 */
#define LED_BLINK_H8_1_FPID_29_MASK 0x3u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_1_FPID_29_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_1_FPID_29_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_1_FPID_29_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_1_FPID_29_V10HZ 0x3

/*! Field GPTD_29 - GPT Divider for LED29 */
#define LED_BLINK_H8_1_GPTD_29_POS 2
/*! Field GPTD_29 - GPT Divider for LED29 */
#define LED_BLINK_H8_1_GPTD_29_MASK 0xCu
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_1_GPTD_29_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_1_GPTD_29_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_1_GPTD_29_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_1_GPTD_29_V250HZ 0x3

/*! Field BLINK_29 - Set Blink rate for LED 29 */
#define LED_BLINK_H8_1_BLINK_29_POS 4
/*! Field BLINK_29 - Set Blink rate for LED 29 */
#define LED_BLINK_H8_1_BLINK_29_MASK 0x30u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_1_BLINK_29_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_1_BLINK_29_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_1_BLINK_29_V1M 0x2

/*! Field FPID_30 - FSC Divider for LED30 */
#define LED_BLINK_H8_1_FPID_30_POS 6
/*! Field FPID_30 - FSC Divider for LED30 */
#define LED_BLINK_H8_1_FPID_30_MASK 0xC0u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_1_FPID_30_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_1_FPID_30_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_1_FPID_30_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_1_FPID_30_V10HZ 0x3

/*! Field GPTD_30 - GPT Divider for LED30 */
#define LED_BLINK_H8_1_GPTD_30_POS 8
/*! Field GPTD_30 - GPT Divider for LED30 */
#define LED_BLINK_H8_1_GPTD_30_MASK 0x300u
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_1_GPTD_30_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_1_GPTD_30_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_1_GPTD_30_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_1_GPTD_30_V250HZ 0x3

/*! Field BLINK_30 - Set Blink rate for LED 30 */
#define LED_BLINK_H8_1_BLINK_30_POS 10
/*! Field BLINK_30 - Set Blink rate for LED 30 */
#define LED_BLINK_H8_1_BLINK_30_MASK 0xC00u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_1_BLINK_30_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_1_BLINK_30_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_1_BLINK_30_V1M 0x2

/*! Field FPID_31 - FSC Divider for LED31 */
#define LED_BLINK_H8_1_FPID_31_POS 12
/*! Field FPID_31 - FSC Divider for LED31 */
#define LED_BLINK_H8_1_FPID_31_MASK 0x3000u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_1_FPID_31_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_1_FPID_31_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_1_FPID_31_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_1_FPID_31_V10HZ 0x3

/*! Field GPTD_31 - GPT Divider for LED31 */
#define LED_BLINK_H8_1_GPTD_31_POS 14
/*! Field GPTD_31 - GPT Divider for LED31 */
#define LED_BLINK_H8_1_GPTD_31_MASK 0xC000u
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_1_GPTD_31_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_1_GPTD_31_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_1_GPTD_31_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_1_GPTD_31_V250HZ 0x3

/*! Field BLINK_31 - Set Blink rate for LED 31 */
#define LED_BLINK_H8_1_BLINK_31_POS 16
/*! Field BLINK_31 - Set Blink rate for LED 31 */
#define LED_BLINK_H8_1_BLINK_31_MASK 0x30000u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_1_BLINK_31_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_1_BLINK_31_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_1_BLINK_31_V1M 0x2

/*! Field FPID_L24 - FSC Divider for Lower 24 bits [23:0] */
#define LED_BLINK_H8_1_FPID_L24_POS 18
/*! Field FPID_L24 - FSC Divider for Lower 24 bits [23:0] */
#define LED_BLINK_H8_1_FPID_L24_MASK 0xC0000u
/*! Constant V2HZ - 2Hz */
#define CONST_LED_BLINK_H8_1_FPID_L24_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_LED_BLINK_H8_1_FPID_L24_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_LED_BLINK_H8_1_FPID_L24_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_LED_BLINK_H8_1_FPID_L24_V10HZ 0x3

/*! Field GPTD_L24 - GPT Divider for lower 24 bits [23:0] */
#define LED_BLINK_H8_1_GPTD_L24_POS 20
/*! Field GPTD_L24 - GPT Divider for lower 24 bits [23:0] */
#define LED_BLINK_H8_1_GPTD_L24_MASK 0x300000u
/*! Constant V50HZ - upto 50KHz */
#define CONST_LED_BLINK_H8_1_GPTD_L24_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_LED_BLINK_H8_1_GPTD_L24_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_LED_BLINK_H8_1_GPTD_L24_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_LED_BLINK_H8_1_GPTD_L24_V250HZ 0x3

/*! Field BLINK_L24 - Set Blink rate for LED [23:0] */
#define LED_BLINK_H8_1_BLINK_L24_POS 22
/*! Field BLINK_L24 - Set Blink rate for LED [23:0] */
#define LED_BLINK_H8_1_BLINK_L24_MASK 0xC00000u
/*! Constant FPID - blink at FPID output rate */
#define CONST_LED_BLINK_H8_1_BLINK_L24_FPID 0x0
/*! Constant GPTD - blink at GPT output rate */
#define CONST_LED_BLINK_H8_1_BLINK_L24_GPTD 0x1
/*! Constant V1M - blink at GPT high speed output rate */
#define CONST_LED_BLINK_H8_1_BLINK_L24_V1M 0x2

/*! @} */

/*! \defgroup DUTY_CYCLE_0 Register DUTY_CYCLE_0 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_0 0x8
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_0 0x16320008u

/*! Register Reset Value */
#define DUTY_CYCLE_0_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_0_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_0_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_1 Register DUTY_CYCLE_1 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_1 0xC
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_1 0x1632000Cu

/*! Register Reset Value */
#define DUTY_CYCLE_1_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_1_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_1_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_2 Register DUTY_CYCLE_2 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_2 0x10
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_2 0x16320010u

/*! Register Reset Value */
#define DUTY_CYCLE_2_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_2_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_2_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_3 Register DUTY_CYCLE_3 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_3 0x14
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_3 0x16320014u

/*! Register Reset Value */
#define DUTY_CYCLE_3_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_3_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_3_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_4 Register DUTY_CYCLE_4 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_4 0x18
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_4 0x16320018u

/*! Register Reset Value */
#define DUTY_CYCLE_4_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_4_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_4_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_5 Register DUTY_CYCLE_5 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_5 0x1C
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_5 0x1632001Cu

/*! Register Reset Value */
#define DUTY_CYCLE_5_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_5_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_5_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_6 Register DUTY_CYCLE_6 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_6 0x20
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_6 0x16320020u

/*! Register Reset Value */
#define DUTY_CYCLE_6_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_6_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_6_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_7 Register DUTY_CYCLE_7 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_7 0x24
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_7 0x16320024u

/*! Register Reset Value */
#define DUTY_CYCLE_7_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_7_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_7_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_8 Register DUTY_CYCLE_8 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_8 0x28
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_8 0x16320028u

/*! Register Reset Value */
#define DUTY_CYCLE_8_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_8_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_8_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_9 Register DUTY_CYCLE_9 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_9 0x2C
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_9 0x1632002Cu

/*! Register Reset Value */
#define DUTY_CYCLE_9_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_9_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_9_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_10 Register DUTY_CYCLE_10 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_10 0x30
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_10 0x16320030u

/*! Register Reset Value */
#define DUTY_CYCLE_10_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_10_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_10_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_11 Register DUTY_CYCLE_11 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_11 0x34
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_11 0x16320034u

/*! Register Reset Value */
#define DUTY_CYCLE_11_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_11_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_11_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_12 Register DUTY_CYCLE_12 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_12 0x38
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_12 0x16320038u

/*! Register Reset Value */
#define DUTY_CYCLE_12_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_12_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_12_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_13 Register DUTY_CYCLE_13 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_13 0x3C
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_13 0x1632003Cu

/*! Register Reset Value */
#define DUTY_CYCLE_13_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_13_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_13_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_14 Register DUTY_CYCLE_14 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_14 0x40
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_14 0x16320040u

/*! Register Reset Value */
#define DUTY_CYCLE_14_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_14_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_14_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_15 Register DUTY_CYCLE_15 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_15 0x44
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_15 0x16320044u

/*! Register Reset Value */
#define DUTY_CYCLE_15_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_15_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_15_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_16 Register DUTY_CYCLE_16 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_16 0x48
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_16 0x16320048u

/*! Register Reset Value */
#define DUTY_CYCLE_16_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_16_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_16_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_17 Register DUTY_CYCLE_17 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_17 0x4C
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_17 0x1632004Cu

/*! Register Reset Value */
#define DUTY_CYCLE_17_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_17_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_17_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_18 Register DUTY_CYCLE_18 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_18 0x50
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_18 0x16320050u

/*! Register Reset Value */
#define DUTY_CYCLE_18_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_18_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_18_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_19 Register DUTY_CYCLE_19 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_19 0x54
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_19 0x16320054u

/*! Register Reset Value */
#define DUTY_CYCLE_19_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_19_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_19_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_20 Register DUTY_CYCLE_20 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_20 0x58
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_20 0x16320058u

/*! Register Reset Value */
#define DUTY_CYCLE_20_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_20_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_20_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_21 Register DUTY_CYCLE_21 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_21 0x5C
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_21 0x1632005Cu

/*! Register Reset Value */
#define DUTY_CYCLE_21_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_21_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_21_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_22 Register DUTY_CYCLE_22 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_22 0x60
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_22 0x16320060u

/*! Register Reset Value */
#define DUTY_CYCLE_22_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_22_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_22_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_23 Register DUTY_CYCLE_23 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_23 0x64
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_23 0x16320064u

/*! Register Reset Value */
#define DUTY_CYCLE_23_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_23_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_23_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_24 Register DUTY_CYCLE_24 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_24 0x68
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_24 0x16320068u

/*! Register Reset Value */
#define DUTY_CYCLE_24_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_24_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_24_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_25 Register DUTY_CYCLE_25 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_25 0x6C
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_25 0x1632006Cu

/*! Register Reset Value */
#define DUTY_CYCLE_25_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_25_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_25_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_26 Register DUTY_CYCLE_26 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_26 0x70
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_26 0x16320070u

/*! Register Reset Value */
#define DUTY_CYCLE_26_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_26_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_26_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_27 Register DUTY_CYCLE_27 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_27 0x74
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_27 0x16320074u

/*! Register Reset Value */
#define DUTY_CYCLE_27_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_27_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_27_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_28 Register DUTY_CYCLE_28 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_28 0x78
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_28 0x16320078u

/*! Register Reset Value */
#define DUTY_CYCLE_28_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_28_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_28_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_29 Register DUTY_CYCLE_29 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_29 0x7C
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_29 0x1632007Cu

/*! Register Reset Value */
#define DUTY_CYCLE_29_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_29_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_29_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_30 Register DUTY_CYCLE_30 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_30 0x80
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_30 0x16320080u

/*! Register Reset Value */
#define DUTY_CYCLE_30_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_30_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_30_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup DUTY_CYCLE_31 Register DUTY_CYCLE_31 - 8bit per LED duty cycle control */
/*! @{ */

/*! Register Offset (relative) */
#define DUTY_CYCLE_31 0x84
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_DUTY_CYCLE_31 0x16320084u

/*! Register Reset Value */
#define DUTY_CYCLE_31_RST 0x00000080u

/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_31_LED_DUTY_CYCLE_POS 0
/*! Field LED_DUTY_CYCLE - 256 level duty cycle for LED */
#define DUTY_CYCLE_31_LED_DUTY_CYCLE_MASK 0xFFu

/*! @} */

/*! \defgroup SSO_CON0 Register SSO_CON0 - Serial Shift Output Control 0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSO_CON0 0x2B0
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_SSO_CON0 0x163202B0u

/*! Register Reset Value */
#define SSO_CON0_RST 0x00000000u

/*! Field LUX_LVL - LUX Level Converted by Hardware */
#define SSO_CON0_LUX_LVL_POS 0
/*! Field LUX_LVL - LUX Level Converted by Hardware */
#define SSO_CON0_LUX_LVL_MASK 0xFFu

/*! Field LUX_CNV_INT - Programmable divider for intervals used by LUX conversion */
#define SSO_CON0_LUX_CNV_INT_POS 8
/*! Field LUX_CNV_INT - Programmable divider for intervals used by LUX conversion */
#define SSO_CON0_LUX_CNV_INT_MASK 0xF00u
/*! Constant DO - no division of 2560Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_DO 0x0
/*! Constant D1 - division of 2, equals to 1280Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D1 0x1
/*! Constant D2 - Division of 4, equals to 640Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D2 0x2
/*! Constant D3 - Division of 8, equals to 320Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D3 0x3
/*! Constant D4 - Division of 16, equals to 160Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D4 0x4
/*! Constant D5 - Division of 32, equals to 80Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D5 0x5
/*! Constant D6 - Division of 64, equals to 40HZ */
#define CONST_SSO_CON0_LUX_CNV_INT_D6 0x6
/*! Constant D7 - Division of 128, equals to 20Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D7 0x7
/*! Constant D8 - Division of 256, equals to 10 Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D8 0x8
/*! Constant D9 - Division of 512, equals to 5Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D9 0x9
/*! Constant D10 - Division of 1024, equals to 2.5Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D10 0xA
/*! Constant D11 - Division of 2048, equals to 1.25Hz */
#define CONST_SSO_CON0_LUX_CNV_INT_D11 0xB

/*! Field LUX_SENSOR_DIS - Discharge time for brightness detection circuit */
#define SSO_CON0_LUX_SENSOR_DIS_POS 12
/*! Field LUX_SENSOR_DIS - Discharge time for brightness detection circuit */
#define SSO_CON0_LUX_SENSOR_DIS_MASK 0x3F000u

/*! Field RZFL - Data clocking edge */
#define SSO_CON0_RZFL_POS 26
/*! Field RZFL - Data clocking edge */
#define SSO_CON0_RZFL_MASK 0x4000000u
/*! Constant RISING - Rising */
#define CONST_SSO_CON0_RZFL_RISING 0x0
/*! Constant FALLING - Falling */
#define CONST_SSO_CON0_RZFL_FALLING 0x1

/*! Field DIMM_EN - Enable Auto Dimming function */
#define SSO_CON0_DIMM_EN_POS 27
/*! Field DIMM_EN - Enable Auto Dimming function */
#define SSO_CON0_DIMM_EN_MASK 0x8000000u
/*! Constant ND - disable dimming controller input */
#define CONST_SSO_CON0_DIMM_EN_ND 0x0
/*! Constant D - enable dimming control */
#define CONST_SSO_CON0_DIMM_EN_D 0x1

/*! Field BLINK_R - Blink rate update control for LED[23:0] */
#define SSO_CON0_BLINK_R_POS 30
/*! Field BLINK_R - Blink rate update control for LED[23:0] */
#define SSO_CON0_BLINK_R_MASK 0x40000000u
/*! Constant OFF - OFF */
#define CONST_SSO_CON0_BLINK_R_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSO_CON0_BLINK_R_ON 0x1

/*! Field SWU - Software Update */
#define SSO_CON0_SWU_POS 31
/*! Field SWU - Software Update */
#define SSO_CON0_SWU_MASK 0x80000000u
/*! Constant OFF - Off */
#define CONST_SSO_CON0_SWU_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON0_SWU_ON 0x1

/*! @} */

/*! \defgroup SSO_CON1 Register SSO_CON1 - Serial Shift Output Control 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSO_CON1 0x2B4
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_SSO_CON1 0x163202B4u

/*! Register Reset Value */
#define SSO_CON1_RST 0x00000000u

/*! Field G0 - SOUT Group 0 */
#define SSO_CON1_G0_POS 0
/*! Field G0 - SOUT Group 0 */
#define SSO_CON1_G0_MASK 0x1u
/*! Constant OFF - Off */
#define CONST_SSO_CON1_G0_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON1_G0_ON 0x1

/*! Field G1 - SOUT Group 1 */
#define SSO_CON1_G1_POS 1
/*! Field G1 - SOUT Group 1 */
#define SSO_CON1_G1_MASK 0x2u
/*! Constant OFF - Off */
#define CONST_SSO_CON1_G1_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON1_G1_ON 0x1

/*! Field G2 - SOUT Group 2 */
#define SSO_CON1_G2_POS 2
/*! Field G2 - SOUT Group 2 */
#define SSO_CON1_G2_MASK 0x4u
/*! Constant OFF - Off */
#define CONST_SSO_CON1_G2_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON1_G2_ON 0x1

/*! Field G3 - SOUT Group 3 */
#define SSO_CON1_G3_POS 3
/*! Field G3 - SOUT Group 3 */
#define SSO_CON1_G3_MASK 0x8u
/*! Constant OFF - Off */
#define CONST_SSO_CON1_G3_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON1_G3_ON 0x1

/*! Field DO - Data Offset */
#define SSO_CON1_DO_POS 18
/*! Field DO - Data Offset */
#define SSO_CON1_DO_MASK 0xC0000u
/*! Constant V0 - 0 */
#define CONST_SSO_CON1_DO_V0 0x0
/*! Constant V1 - 1 */
#define CONST_SSO_CON1_DO_V1 0x1
/*! Constant V2 - 2 */
#define CONST_SSO_CON1_DO_V2 0x2
/*! Constant V3 - 3 */
#define CONST_SSO_CON1_DO_V3 0x3

/*! Field FCDSC - Fixed Divider Shift Clock */
#define SSO_CON1_FCDSC_POS 20
/*! Field FCDSC - Fixed Divider Shift Clock */
#define SSO_CON1_FCDSC_MASK 0x300000u
/*! Constant V11_6 - 25 MHz */
#define CONST_SSO_CON1_FCDSC_V11_6 0x0
/*! Constant V1_3_2 - 12.5 MHz */
#define CONST_SSO_CON1_FCDSC_V1_3_2 0x1
/*! Constant V1_64 - 6.25 MHz */
#define CONST_SSO_CON1_FCDSC_V1_64 0x2
/*! Constant V1_128 - 3.125 MHz */
#define CONST_SSO_CON1_FCDSC_V1_128 0x3

/*! Field FPID - FSC Divider for LED [23:0] */
#define SSO_CON1_FPID_POS 23
/*! Field FPID - FSC Divider for LED [23:0] */
#define SSO_CON1_FPID_MASK 0x1800000u
/*! Constant V2HZ - 2Hz */
#define CONST_SSO_CON1_FPID_V2HZ 0x0
/*! Constant V4HZ - 4Hz */
#define CONST_SSO_CON1_FPID_V4HZ 0x1
/*! Constant V8HZ - 8Hz */
#define CONST_SSO_CON1_FPID_V8HZ 0x2
/*! Constant V10HZ - 10Hz */
#define CONST_SSO_CON1_FPID_V10HZ 0x3

/*! Field GPTD - GPT Divider for LED[23:0] */
#define SSO_CON1_GPTD_POS 25
/*! Field GPTD - GPT Divider for LED[23:0] */
#define SSO_CON1_GPTD_MASK 0x6000000u
/*! Constant V50HZ - upto 50KHz */
#define CONST_SSO_CON1_GPTD_V50HZ 0x0
/*! Constant V100HZ - upto 100KHz */
#define CONST_SSO_CON1_GPTD_V100HZ 0x1
/*! Constant V200HZ - upto 200KHz */
#define CONST_SSO_CON1_GPTD_V200HZ 0x2
/*! Constant V250HZ - upto 250KHz */
#define CONST_SSO_CON1_GPTD_V250HZ 0x3

/*! Field SCS - Single Store/Clock Store Operation */
#define SSO_CON1_SCS_POS 28
/*! Field SCS - Single Store/Clock Store Operation */
#define SSO_CON1_SCS_MASK 0x10000000u
/*! Constant SINGLE - Single */
#define CONST_SSO_CON1_SCS_SINGLE 0x0
/*! Constant CLOCK - Clock */
#define CONST_SSO_CON1_SCS_CLOCK 0x1

/*! Field US - Update Source */
#define SSO_CON1_US_POS 30
/*! Field US - Update Source */
#define SSO_CON1_US_MASK 0xC0000000u
/*! Constant SW - SW */
#define CONST_SSO_CON1_US_SW 0x0
/*! Constant GPT2 - GPTC0 Timer 2 */
#define CONST_SSO_CON1_US_GPT2 0x1
/*! Constant FPID - FPID */
#define CONST_SSO_CON1_US_FPID 0x2

/*! @} */

/*! \defgroup SSO_CPU0 Register SSO_CPU0 - Serial Shift Data Output CPU0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSO_CPU0 0x2B8
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_SSO_CPU0 0x163202B8u

/*! Register Reset Value */
#define SSO_CPU0_RST 0x00000000u

/*! Field L0 - SOUT Data 0 */
#define SSO_CPU0_L0_POS 0
/*! Field L0 - SOUT Data 0 */
#define SSO_CPU0_L0_MASK 0x1u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L0_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L0_ON 0x1

/*! Field L1 - SOUT Data 1 */
#define SSO_CPU0_L1_POS 1
/*! Field L1 - SOUT Data 1 */
#define SSO_CPU0_L1_MASK 0x2u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L1_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L1_ON 0x1

/*! Field L2 - SOUT Data 2 */
#define SSO_CPU0_L2_POS 2
/*! Field L2 - SOUT Data 2 */
#define SSO_CPU0_L2_MASK 0x4u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L2_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L2_ON 0x1

/*! Field L3 - SOUT Data 3 */
#define SSO_CPU0_L3_POS 3
/*! Field L3 - SOUT Data 3 */
#define SSO_CPU0_L3_MASK 0x8u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L3_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L3_ON 0x1

/*! Field L4 - SOUT Data 4 */
#define SSO_CPU0_L4_POS 4
/*! Field L4 - SOUT Data 4 */
#define SSO_CPU0_L4_MASK 0x10u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L4_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L4_ON 0x1

/*! Field L5 - SOUT Data 5 */
#define SSO_CPU0_L5_POS 5
/*! Field L5 - SOUT Data 5 */
#define SSO_CPU0_L5_MASK 0x20u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L5_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L5_ON 0x1

/*! Field L6 - SOUT Data 6 */
#define SSO_CPU0_L6_POS 6
/*! Field L6 - SOUT Data 6 */
#define SSO_CPU0_L6_MASK 0x40u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L6_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L6_ON 0x1

/*! Field L7 - SOUT Data 7 */
#define SSO_CPU0_L7_POS 7
/*! Field L7 - SOUT Data 7 */
#define SSO_CPU0_L7_MASK 0x80u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L7_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L7_ON 0x1

/*! Field L8 - SOUT Data 8 */
#define SSO_CPU0_L8_POS 8
/*! Field L8 - SOUT Data 8 */
#define SSO_CPU0_L8_MASK 0x100u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L8_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L8_ON 0x1

/*! Field L9 - SOUT Data 9 */
#define SSO_CPU0_L9_POS 9
/*! Field L9 - SOUT Data 9 */
#define SSO_CPU0_L9_MASK 0x200u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L9_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L9_ON 0x1

/*! Field L10 - SOUT Data 10 */
#define SSO_CPU0_L10_POS 10
/*! Field L10 - SOUT Data 10 */
#define SSO_CPU0_L10_MASK 0x400u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L10_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L10_ON 0x1

/*! Field L11 - SOUT Data 11 */
#define SSO_CPU0_L11_POS 11
/*! Field L11 - SOUT Data 11 */
#define SSO_CPU0_L11_MASK 0x800u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L11_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L11_ON 0x1

/*! Field L12 - SOUT Data 12 */
#define SSO_CPU0_L12_POS 12
/*! Field L12 - SOUT Data 12 */
#define SSO_CPU0_L12_MASK 0x1000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L12_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L12_ON 0x1

/*! Field L13 - SOUT Data 13 */
#define SSO_CPU0_L13_POS 13
/*! Field L13 - SOUT Data 13 */
#define SSO_CPU0_L13_MASK 0x2000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L13_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L13_ON 0x1

/*! Field L14 - SOUT Data 14 */
#define SSO_CPU0_L14_POS 14
/*! Field L14 - SOUT Data 14 */
#define SSO_CPU0_L14_MASK 0x4000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L14_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L14_ON 0x1

/*! Field L15 - SOUT Data 15 */
#define SSO_CPU0_L15_POS 15
/*! Field L15 - SOUT Data 15 */
#define SSO_CPU0_L15_MASK 0x8000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L15_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L15_ON 0x1

/*! Field L16 - SOUT Data 16 */
#define SSO_CPU0_L16_POS 16
/*! Field L16 - SOUT Data 16 */
#define SSO_CPU0_L16_MASK 0x10000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L16_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L16_ON 0x1

/*! Field L17 - SOUT Data 17 */
#define SSO_CPU0_L17_POS 17
/*! Field L17 - SOUT Data 17 */
#define SSO_CPU0_L17_MASK 0x20000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L17_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L17_ON 0x1

/*! Field L18 - SOUT Data 18 */
#define SSO_CPU0_L18_POS 18
/*! Field L18 - SOUT Data 18 */
#define SSO_CPU0_L18_MASK 0x40000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L18_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L18_ON 0x1

/*! Field L19 - SOUT Data 19 */
#define SSO_CPU0_L19_POS 19
/*! Field L19 - SOUT Data 19 */
#define SSO_CPU0_L19_MASK 0x80000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L19_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L19_ON 0x1

/*! Field L20 - SOUT Data 20 */
#define SSO_CPU0_L20_POS 20
/*! Field L20 - SOUT Data 20 */
#define SSO_CPU0_L20_MASK 0x100000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L20_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L20_ON 0x1

/*! Field L21 - SOUT Data 21 */
#define SSO_CPU0_L21_POS 21
/*! Field L21 - SOUT Data 21 */
#define SSO_CPU0_L21_MASK 0x200000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L21_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L21_ON 0x1

/*! Field L22 - SOUT Data 22 */
#define SSO_CPU0_L22_POS 22
/*! Field L22 - SOUT Data 22 */
#define SSO_CPU0_L22_MASK 0x400000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L22_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L22_ON 0x1

/*! Field L23 - SOUT Data 23 */
#define SSO_CPU0_L23_POS 23
/*! Field L23 - SOUT Data 23 */
#define SSO_CPU0_L23_MASK 0x800000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L23_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L23_ON 0x1

/*! Field L24 - SOUT Data 24 */
#define SSO_CPU0_L24_POS 24
/*! Field L24 - SOUT Data 24 */
#define SSO_CPU0_L24_MASK 0x1000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L24_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L24_ON 0x1

/*! Field L25 - SOUT Data 25 */
#define SSO_CPU0_L25_POS 25
/*! Field L25 - SOUT Data 25 */
#define SSO_CPU0_L25_MASK 0x2000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L25_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L25_ON 0x1

/*! Field L26 - SOUT Data 26 */
#define SSO_CPU0_L26_POS 26
/*! Field L26 - SOUT Data 26 */
#define SSO_CPU0_L26_MASK 0x4000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L26_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L26_ON 0x1

/*! Field L27 - SOUT Data 27 */
#define SSO_CPU0_L27_POS 27
/*! Field L27 - SOUT Data 27 */
#define SSO_CPU0_L27_MASK 0x8000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L27_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L27_ON 0x1

/*! Field L28 - SOUT Data 28 */
#define SSO_CPU0_L28_POS 28
/*! Field L28 - SOUT Data 28 */
#define SSO_CPU0_L28_MASK 0x10000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L28_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L28_ON 0x1

/*! Field L29 - SOUT Data 29 */
#define SSO_CPU0_L29_POS 29
/*! Field L29 - SOUT Data 29 */
#define SSO_CPU0_L29_MASK 0x20000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L29_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L29_ON 0x1

/*! Field L30 - SOUT Data 30 */
#define SSO_CPU0_L30_POS 30
/*! Field L30 - SOUT Data 30 */
#define SSO_CPU0_L30_MASK 0x40000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L30_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L30_ON 0x1

/*! Field L31 - SOUT Data 31 */
#define SSO_CPU0_L31_POS 31
/*! Field L31 - SOUT Data 31 */
#define SSO_CPU0_L31_MASK 0x80000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU0_L31_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU0_L31_ON 0x1

/*! @} */

/*! \defgroup SSO_CPU1 Register SSO_CPU1 - Serial Shift Data Output CPU1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSO_CPU1 0x2BC
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_SSO_CPU1 0x163202BCu

/*! Register Reset Value */
#define SSO_CPU1_RST 0x00000000u

/*! Field L0 - SOUT Data 0 */
#define SSO_CPU1_L0_POS 0
/*! Field L0 - SOUT Data 0 */
#define SSO_CPU1_L0_MASK 0x1u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L0_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L0_ON 0x1

/*! Field L1 - SOUT Data 1 */
#define SSO_CPU1_L1_POS 1
/*! Field L1 - SOUT Data 1 */
#define SSO_CPU1_L1_MASK 0x2u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L1_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L1_ON 0x1

/*! Field L2 - SOUT Data 2 */
#define SSO_CPU1_L2_POS 2
/*! Field L2 - SOUT Data 2 */
#define SSO_CPU1_L2_MASK 0x4u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L2_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L2_ON 0x1

/*! Field L3 - SOUT Data 3 */
#define SSO_CPU1_L3_POS 3
/*! Field L3 - SOUT Data 3 */
#define SSO_CPU1_L3_MASK 0x8u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L3_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L3_ON 0x1

/*! Field L4 - SOUT Data 4 */
#define SSO_CPU1_L4_POS 4
/*! Field L4 - SOUT Data 4 */
#define SSO_CPU1_L4_MASK 0x10u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L4_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L4_ON 0x1

/*! Field L5 - SOUT Data 5 */
#define SSO_CPU1_L5_POS 5
/*! Field L5 - SOUT Data 5 */
#define SSO_CPU1_L5_MASK 0x20u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L5_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L5_ON 0x1

/*! Field L6 - SOUT Data 6 */
#define SSO_CPU1_L6_POS 6
/*! Field L6 - SOUT Data 6 */
#define SSO_CPU1_L6_MASK 0x40u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L6_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L6_ON 0x1

/*! Field L7 - SOUT Data 7 */
#define SSO_CPU1_L7_POS 7
/*! Field L7 - SOUT Data 7 */
#define SSO_CPU1_L7_MASK 0x80u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L7_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L7_ON 0x1

/*! Field L8 - SOUT Data 8 */
#define SSO_CPU1_L8_POS 8
/*! Field L8 - SOUT Data 8 */
#define SSO_CPU1_L8_MASK 0x100u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L8_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L8_ON 0x1

/*! Field L9 - SOUT Data 9 */
#define SSO_CPU1_L9_POS 9
/*! Field L9 - SOUT Data 9 */
#define SSO_CPU1_L9_MASK 0x200u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L9_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L9_ON 0x1

/*! Field L10 - SOUT Data 10 */
#define SSO_CPU1_L10_POS 10
/*! Field L10 - SOUT Data 10 */
#define SSO_CPU1_L10_MASK 0x400u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L10_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L10_ON 0x1

/*! Field L11 - SOUT Data 11 */
#define SSO_CPU1_L11_POS 11
/*! Field L11 - SOUT Data 11 */
#define SSO_CPU1_L11_MASK 0x800u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L11_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L11_ON 0x1

/*! Field L12 - SOUT Data 12 */
#define SSO_CPU1_L12_POS 12
/*! Field L12 - SOUT Data 12 */
#define SSO_CPU1_L12_MASK 0x1000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L12_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L12_ON 0x1

/*! Field L13 - SOUT Data 13 */
#define SSO_CPU1_L13_POS 13
/*! Field L13 - SOUT Data 13 */
#define SSO_CPU1_L13_MASK 0x2000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L13_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L13_ON 0x1

/*! Field L14 - SOUT Data 14 */
#define SSO_CPU1_L14_POS 14
/*! Field L14 - SOUT Data 14 */
#define SSO_CPU1_L14_MASK 0x4000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L14_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L14_ON 0x1

/*! Field L15 - SOUT Data 15 */
#define SSO_CPU1_L15_POS 15
/*! Field L15 - SOUT Data 15 */
#define SSO_CPU1_L15_MASK 0x8000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L15_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L15_ON 0x1

/*! Field L16 - SOUT Data 16 */
#define SSO_CPU1_L16_POS 16
/*! Field L16 - SOUT Data 16 */
#define SSO_CPU1_L16_MASK 0x10000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L16_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L16_ON 0x1

/*! Field L17 - SOUT Data 17 */
#define SSO_CPU1_L17_POS 17
/*! Field L17 - SOUT Data 17 */
#define SSO_CPU1_L17_MASK 0x20000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L17_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L17_ON 0x1

/*! Field L18 - SOUT Data 18 */
#define SSO_CPU1_L18_POS 18
/*! Field L18 - SOUT Data 18 */
#define SSO_CPU1_L18_MASK 0x40000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L18_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L18_ON 0x1

/*! Field L19 - SOUT Data 19 */
#define SSO_CPU1_L19_POS 19
/*! Field L19 - SOUT Data 19 */
#define SSO_CPU1_L19_MASK 0x80000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L19_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L19_ON 0x1

/*! Field L20 - SOUT Data 20 */
#define SSO_CPU1_L20_POS 20
/*! Field L20 - SOUT Data 20 */
#define SSO_CPU1_L20_MASK 0x100000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L20_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L20_ON 0x1

/*! Field L21 - SOUT Data 21 */
#define SSO_CPU1_L21_POS 21
/*! Field L21 - SOUT Data 21 */
#define SSO_CPU1_L21_MASK 0x200000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L21_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L21_ON 0x1

/*! Field L22 - SOUT Data 22 */
#define SSO_CPU1_L22_POS 22
/*! Field L22 - SOUT Data 22 */
#define SSO_CPU1_L22_MASK 0x400000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L22_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L22_ON 0x1

/*! Field L23 - SOUT Data 23 */
#define SSO_CPU1_L23_POS 23
/*! Field L23 - SOUT Data 23 */
#define SSO_CPU1_L23_MASK 0x800000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L23_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L23_ON 0x1

/*! Field L24 - SOUT Data 24 */
#define SSO_CPU1_L24_POS 24
/*! Field L24 - SOUT Data 24 */
#define SSO_CPU1_L24_MASK 0x1000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L24_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L24_ON 0x1

/*! Field L25 - SOUT Data 25 */
#define SSO_CPU1_L25_POS 25
/*! Field L25 - SOUT Data 25 */
#define SSO_CPU1_L25_MASK 0x2000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L25_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L25_ON 0x1

/*! Field L26 - SOUT Data 26 */
#define SSO_CPU1_L26_POS 26
/*! Field L26 - SOUT Data 26 */
#define SSO_CPU1_L26_MASK 0x4000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L26_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L26_ON 0x1

/*! Field L27 - SOUT Data 27 */
#define SSO_CPU1_L27_POS 27
/*! Field L27 - SOUT Data 27 */
#define SSO_CPU1_L27_MASK 0x8000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L27_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L27_ON 0x1

/*! Field L28 - SOUT Data 28 */
#define SSO_CPU1_L28_POS 28
/*! Field L28 - SOUT Data 28 */
#define SSO_CPU1_L28_MASK 0x10000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L28_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L28_ON 0x1

/*! Field L29 - SOUT Data 29 */
#define SSO_CPU1_L29_POS 29
/*! Field L29 - SOUT Data 29 */
#define SSO_CPU1_L29_MASK 0x20000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L29_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L29_ON 0x1

/*! Field L30 - SOUT Data 30 */
#define SSO_CPU1_L30_POS 30
/*! Field L30 - SOUT Data 30 */
#define SSO_CPU1_L30_MASK 0x40000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L30_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L30_ON 0x1

/*! Field L31 - SOUT Data 31 */
#define SSO_CPU1_L31_POS 31
/*! Field L31 - SOUT Data 31 */
#define SSO_CPU1_L31_MASK 0x80000000u
/*! Constant OFF - Off */
#define CONST_SSO_CPU1_L31_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CPU1_L31_ON 0x1

/*! @} */

/*! \defgroup SSO_AR Register SSO_AR - Serial Shift Data Output CPU Access Rights Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSO_AR 0x2C0
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_SSO_AR 0x163202C0u

/*! Register Reset Value */
#define SSO_AR_RST 0x00000000u

/*! Field L0 - SOUT0 */
#define SSO_AR_L0_POS 0
/*! Field L0 - SOUT0 */
#define SSO_AR_L0_MASK 0x1u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L0_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L0_CPU1 0x1

/*! Field L1 - SOUT1 */
#define SSO_AR_L1_POS 1
/*! Field L1 - SOUT1 */
#define SSO_AR_L1_MASK 0x2u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L1_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L1_CPU1 0x1

/*! Field L2 - SOUT2 */
#define SSO_AR_L2_POS 2
/*! Field L2 - SOUT2 */
#define SSO_AR_L2_MASK 0x4u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L2_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L2_CPU1 0x1

/*! Field L3 - SOUT3 */
#define SSO_AR_L3_POS 3
/*! Field L3 - SOUT3 */
#define SSO_AR_L3_MASK 0x8u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L3_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L3_CPU1 0x1

/*! Field L4 - SOUT4 */
#define SSO_AR_L4_POS 4
/*! Field L4 - SOUT4 */
#define SSO_AR_L4_MASK 0x10u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L4_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L4_CPU1 0x1

/*! Field L5 - SOUT5 */
#define SSO_AR_L5_POS 5
/*! Field L5 - SOUT5 */
#define SSO_AR_L5_MASK 0x20u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L5_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L5_CPU1 0x1

/*! Field L6 - SOUT6 */
#define SSO_AR_L6_POS 6
/*! Field L6 - SOUT6 */
#define SSO_AR_L6_MASK 0x40u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L6_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L6_CPU1 0x1

/*! Field L7 - SOUT7 */
#define SSO_AR_L7_POS 7
/*! Field L7 - SOUT7 */
#define SSO_AR_L7_MASK 0x80u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L7_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L7_CPU1 0x1

/*! Field L8 - SOUT8 */
#define SSO_AR_L8_POS 8
/*! Field L8 - SOUT8 */
#define SSO_AR_L8_MASK 0x100u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L8_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L8_CPU1 0x1

/*! Field L9 - SOUT9 */
#define SSO_AR_L9_POS 9
/*! Field L9 - SOUT9 */
#define SSO_AR_L9_MASK 0x200u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L9_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L9_CPU1 0x1

/*! Field L10 - SOUT10 */
#define SSO_AR_L10_POS 10
/*! Field L10 - SOUT10 */
#define SSO_AR_L10_MASK 0x400u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L10_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L10_CPU1 0x1

/*! Field L11 - SOUT11 */
#define SSO_AR_L11_POS 11
/*! Field L11 - SOUT11 */
#define SSO_AR_L11_MASK 0x800u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L11_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L11_CPU1 0x1

/*! Field L12 - SOUT12 */
#define SSO_AR_L12_POS 12
/*! Field L12 - SOUT12 */
#define SSO_AR_L12_MASK 0x1000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L12_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L12_CPU1 0x1

/*! Field L13 - SOUT13 */
#define SSO_AR_L13_POS 13
/*! Field L13 - SOUT13 */
#define SSO_AR_L13_MASK 0x2000u
/*! Constant CPU0 - CPU0, */
#define CONST_SSO_AR_L13_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L13_CPU1 0x1

/*! Field L14 - SOUT14 */
#define SSO_AR_L14_POS 14
/*! Field L14 - SOUT14 */
#define SSO_AR_L14_MASK 0x4000u
/*! Constant CPU0 - CPU0, */
#define CONST_SSO_AR_L14_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L14_CPU1 0x1

/*! Field L15 - SOUT15 */
#define SSO_AR_L15_POS 15
/*! Field L15 - SOUT15 */
#define SSO_AR_L15_MASK 0x8000u
/*! Constant CPU0 - CPU0, */
#define CONST_SSO_AR_L15_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L15_CPU1 0x1

/*! Field L16 - SOUT16 */
#define SSO_AR_L16_POS 16
/*! Field L16 - SOUT16 */
#define SSO_AR_L16_MASK 0x10000u
/*! Constant CPU0 - CPU0, */
#define CONST_SSO_AR_L16_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L16_CPU1 0x1

/*! Field L17 - SOUT17 */
#define SSO_AR_L17_POS 17
/*! Field L17 - SOUT17 */
#define SSO_AR_L17_MASK 0x20000u
/*! Constant CPU0 - CPU0, */
#define CONST_SSO_AR_L17_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L17_CPU1 0x1

/*! Field L18 - SOUT18 */
#define SSO_AR_L18_POS 18
/*! Field L18 - SOUT18 */
#define SSO_AR_L18_MASK 0x40000u
/*! Constant CPU0 - CPU0, */
#define CONST_SSO_AR_L18_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L18_CPU1 0x1

/*! Field L19 - SOUT19 */
#define SSO_AR_L19_POS 19
/*! Field L19 - SOUT19 */
#define SSO_AR_L19_MASK 0x80000u
/*! Constant CPU0 - CPU0, */
#define CONST_SSO_AR_L19_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L19_CPU1 0x1

/*! Field L20 - SOUT20 */
#define SSO_AR_L20_POS 20
/*! Field L20 - SOUT20 */
#define SSO_AR_L20_MASK 0x100000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L20_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L20_CPU1 0x1

/*! Field L21 - SOUT21 */
#define SSO_AR_L21_POS 21
/*! Field L21 - SOUT21 */
#define SSO_AR_L21_MASK 0x200000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L21_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L21_CPU1 0x1

/*! Field L22 - SOUT22 */
#define SSO_AR_L22_POS 22
/*! Field L22 - SOUT22 */
#define SSO_AR_L22_MASK 0x400000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L22_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L22_CPU1 0x1

/*! Field L23 - SOUT23 */
#define SSO_AR_L23_POS 23
/*! Field L23 - SOUT23 */
#define SSO_AR_L23_MASK 0x800000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L23_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L23_CPU1 0x1

/*! Field L24 - SOUT24 */
#define SSO_AR_L24_POS 24
/*! Field L24 - SOUT24 */
#define SSO_AR_L24_MASK 0x1000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L24_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L24_CPU1 0x1

/*! Field L25 - SOUT25 */
#define SSO_AR_L25_POS 25
/*! Field L25 - SOUT25 */
#define SSO_AR_L25_MASK 0x2000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L25_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L25_CPU1 0x1

/*! Field L26 - SOUT26 */
#define SSO_AR_L26_POS 26
/*! Field L26 - SOUT26 */
#define SSO_AR_L26_MASK 0x4000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L26_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L26_CPU1 0x1

/*! Field L27 - SOUT27 */
#define SSO_AR_L27_POS 27
/*! Field L27 - SOUT27 */
#define SSO_AR_L27_MASK 0x8000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L27_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L27_CPU1 0x1

/*! Field L28 - SOUT28 */
#define SSO_AR_L28_POS 28
/*! Field L28 - SOUT28 */
#define SSO_AR_L28_MASK 0x10000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L28_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L28_CPU1 0x1

/*! Field L29 - SOUT29 */
#define SSO_AR_L29_POS 29
/*! Field L29 - SOUT29 */
#define SSO_AR_L29_MASK 0x20000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L29_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L29_CPU1 0x1

/*! Field L30 - SOUT30 */
#define SSO_AR_L30_POS 30
/*! Field L30 - SOUT30 */
#define SSO_AR_L30_MASK 0x40000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L30_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L30_CPU1 0x1

/*! Field L31 - SOUT31 */
#define SSO_AR_L31_POS 31
/*! Field L31 - SOUT31 */
#define SSO_AR_L31_MASK 0x80000000u
/*! Constant CPU0 - CPU0 */
#define CONST_SSO_AR_L31_CPU0 0x0
/*! Constant CPU1 - CPU1 */
#define CONST_SSO_AR_L31_CPU1 0x1

/*! @} */

/*! \defgroup SSO_CON2 Register SSO_CON2 - Serial Shift Output Control 2 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSO_CON2 0x2C4
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_SSO_CON2 0x163202C4u

/*! Register Reset Value */
#define SSO_CON2_RST 0x00000000u

/*! Field LB0 - SOUT0 Blink */
#define SSO_CON2_LB0_POS 0
/*! Field LB0 - SOUT0 Blink */
#define SSO_CON2_LB0_MASK 0x1u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB0_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB0_SOUT_BLINK 0x1

/*! Field LB1 - SOUT1 Blink */
#define SSO_CON2_LB1_POS 1
/*! Field LB1 - SOUT1 Blink */
#define SSO_CON2_LB1_MASK 0x2u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB1_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB1_SOUT_BLINK 0x1

/*! Field LB2 - SOUT2 Blink */
#define SSO_CON2_LB2_POS 2
/*! Field LB2 - SOUT2 Blink */
#define SSO_CON2_LB2_MASK 0x4u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB2_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB2_SOUT_BLINK 0x1

/*! Field LB3 - SOUT3 Blink */
#define SSO_CON2_LB3_POS 3
/*! Field LB3 - SOUT3 Blink */
#define SSO_CON2_LB3_MASK 0x8u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB3_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB3_SOUT_BLINK 0x1

/*! Field LB4 - SOUT4 Blink */
#define SSO_CON2_LB4_POS 4
/*! Field LB4 - SOUT4 Blink */
#define SSO_CON2_LB4_MASK 0x10u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB4_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB4_SOUT_BLINK 0x1

/*! Field LB5 - SOUT5 Blink */
#define SSO_CON2_LB5_POS 5
/*! Field LB5 - SOUT5 Blink */
#define SSO_CON2_LB5_MASK 0x20u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB5_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB5_SOUT_BLINK 0x1

/*! Field LB6 - SOUT6 Blink */
#define SSO_CON2_LB6_POS 6
/*! Field LB6 - SOUT6 Blink */
#define SSO_CON2_LB6_MASK 0x40u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB6_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB6_SOUT_BLINK 0x1

/*! Field LB7 - SOUT7 Blink */
#define SSO_CON2_LB7_POS 7
/*! Field LB7 - SOUT7 Blink */
#define SSO_CON2_LB7_MASK 0x80u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB7_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB7_SOUT_BLINK 0x1

/*! Field LB8 - SOUT8 Blink */
#define SSO_CON2_LB8_POS 8
/*! Field LB8 - SOUT8 Blink */
#define SSO_CON2_LB8_MASK 0x100u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB8_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB8_SOUT_BLINK 0x1

/*! Field LB9 - SOUT9 Blink */
#define SSO_CON2_LB9_POS 9
/*! Field LB9 - SOUT9 Blink */
#define SSO_CON2_LB9_MASK 0x200u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB9_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB9_SOUT_BLINK 0x1

/*! Field LB10 - SOUT10 Blink */
#define SSO_CON2_LB10_POS 10
/*! Field LB10 - SOUT10 Blink */
#define SSO_CON2_LB10_MASK 0x400u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB10_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB10_SOUT_BLINK 0x1

/*! Field LB11 - SOUT11 Blink */
#define SSO_CON2_LB11_POS 11
/*! Field LB11 - SOUT11 Blink */
#define SSO_CON2_LB11_MASK 0x800u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB11_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB11_SOUT_BLINK 0x1

/*! Field LB12 - SOUT12 Blink */
#define SSO_CON2_LB12_POS 12
/*! Field LB12 - SOUT12 Blink */
#define SSO_CON2_LB12_MASK 0x1000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB12_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB12_SOUT_BLINK 0x1

/*! Field LB13 - SOUT13 Blink */
#define SSO_CON2_LB13_POS 13
/*! Field LB13 - SOUT13 Blink */
#define SSO_CON2_LB13_MASK 0x2000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB13_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB13_SOUT_BLINK 0x1

/*! Field LB14 - SOUT14 Blink */
#define SSO_CON2_LB14_POS 14
/*! Field LB14 - SOUT14 Blink */
#define SSO_CON2_LB14_MASK 0x4000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB14_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB14_SOUT_BLINK 0x1

/*! Field LB15 - SOUT15 Blink */
#define SSO_CON2_LB15_POS 15
/*! Field LB15 - SOUT15 Blink */
#define SSO_CON2_LB15_MASK 0x8000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB15_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB15_SOUT_BLINK 0x1

/*! Field LB16 - SOUT16 Blink */
#define SSO_CON2_LB16_POS 16
/*! Field LB16 - SOUT16 Blink */
#define SSO_CON2_LB16_MASK 0x10000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB16_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB16_SOUT_BLINK 0x1

/*! Field LB17 - SOUT17 Blink */
#define SSO_CON2_LB17_POS 17
/*! Field LB17 - SOUT17 Blink */
#define SSO_CON2_LB17_MASK 0x20000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB17_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB17_SOUT_BLINK 0x1

/*! Field LB18 - SOUT18 Blink */
#define SSO_CON2_LB18_POS 18
/*! Field LB18 - SOUT18 Blink */
#define SSO_CON2_LB18_MASK 0x40000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB18_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB18_SOUT_BLINK 0x1

/*! Field LB19 - SOUT19 Blink */
#define SSO_CON2_LB19_POS 19
/*! Field LB19 - SOUT19 Blink */
#define SSO_CON2_LB19_MASK 0x80000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB19_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB19_SOUT_BLINK 0x1

/*! Field LB20 - SOUT20 Blink */
#define SSO_CON2_LB20_POS 20
/*! Field LB20 - SOUT20 Blink */
#define SSO_CON2_LB20_MASK 0x100000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB20_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB20_SOUT_BLINK 0x1

/*! Field LB21 - SOUT21 Blink */
#define SSO_CON2_LB21_POS 21
/*! Field LB21 - SOUT21 Blink */
#define SSO_CON2_LB21_MASK 0x200000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB21_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB21_SOUT_BLINK 0x1

/*! Field LB22 - SOUT22 Blink */
#define SSO_CON2_LB22_POS 22
/*! Field LB22 - SOUT22 Blink */
#define SSO_CON2_LB22_MASK 0x400000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB22_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB22_SOUT_BLINK 0x1

/*! Field LB23 - SOUT23 Blink */
#define SSO_CON2_LB23_POS 23
/*! Field LB23 - SOUT23 Blink */
#define SSO_CON2_LB23_MASK 0x800000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB23_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB23_SOUT_BLINK 0x1

/*! Field LB24 - SOUT24 Blink */
#define SSO_CON2_LB24_POS 24
/*! Field LB24 - SOUT24 Blink */
#define SSO_CON2_LB24_MASK 0x1000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB24_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB24_SOUT_BLINK 0x1

/*! Field LB25 - SOUT25 Blink */
#define SSO_CON2_LB25_POS 25
/*! Field LB25 - SOUT25 Blink */
#define SSO_CON2_LB25_MASK 0x2000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB25_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB25_SOUT_BLINK 0x1

/*! Field LB26 - SOUT26 Blink */
#define SSO_CON2_LB26_POS 26
/*! Field LB26 - SOUT26 Blink */
#define SSO_CON2_LB26_MASK 0x4000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB26_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB26_SOUT_BLINK 0x1

/*! Field LB27 - SOUT27 Blink */
#define SSO_CON2_LB27_POS 27
/*! Field LB27 - SOUT27 Blink */
#define SSO_CON2_LB27_MASK 0x8000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB27_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB27_SOUT_BLINK 0x1

/*! Field LB28 - SOUT28 Blink */
#define SSO_CON2_LB28_POS 28
/*! Field LB28 - SOUT28 Blink */
#define SSO_CON2_LB28_MASK 0x10000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB28_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB28_SOUT_BLINK 0x1

/*! Field LB29 - SOUT29 Blink */
#define SSO_CON2_LB29_POS 29
/*! Field LB29 - SOUT29 Blink */
#define SSO_CON2_LB29_MASK 0x20000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB29_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB29_SOUT_BLINK 0x1

/*! Field LB30 - SOUT30 Blink */
#define SSO_CON2_LB30_POS 30
/*! Field LB30 - SOUT30 Blink */
#define SSO_CON2_LB30_MASK 0x40000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB30_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB30_SOUT_BLINK 0x1

/*! Field LB31 - SOUT31 Blink */
#define SSO_CON2_LB31_POS 31
/*! Field LB31 - SOUT31 Blink */
#define SSO_CON2_LB31_MASK 0x80000000u
/*! Constant SOUT - Default SOUT */
#define CONST_SSO_CON2_LB31_SOUT 0x0
/*! Constant SOUT_BLINK - Blink */
#define CONST_SSO_CON2_LB31_SOUT_BLINK 0x1

/*! @} */

/*! \defgroup SSO_CON3 Register SSO_CON3 - Serial Shift Output Control 3 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSO_CON3 0x2C8
/*! Register Offset (absolute) for 1st Instance SSIO */
#define SSIO_SSO_CON3 0x163202C8u

/*! Register Reset Value */
#define SSO_CON3_RST 0x00000000u

/*! Field OPT_RX_LOS - OPT RX LOS (from GPIO 20) */
#define SSO_CON3_OPT_RX_LOS_POS 1
/*! Field OPT_RX_LOS - OPT RX LOS (from GPIO 20) */
#define SSO_CON3_OPT_RX_LOS_MASK 0x2u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_RX_LOS_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSO_CON3_OPT_RX_LOS_ON 0x1

/*! Field GPHY_LED0 - GPHY LED 0 Config */
#define SSO_CON3_GPHY_LED0_POS 2
/*! Field GPHY_LED0 - GPHY LED 0 Config */
#define SSO_CON3_GPHY_LED0_MASK 0x4u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_GPHY_LED0_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSO_CON3_GPHY_LED0_ON 0x1

/*! Field GPHY_LED1 - GPHY LED 1 Config */
#define SSO_CON3_GPHY_LED1_POS 3
/*! Field GPHY_LED1 - GPHY LED 1 Config */
#define SSO_CON3_GPHY_LED1_MASK 0x8u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_GPHY_LED1_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSO_CON3_GPHY_LED1_ON 0x1

/*! Field GPHY_LED2 - GPHY LED 2 Config */
#define SSO_CON3_GPHY_LED2_POS 4
/*! Field GPHY_LED2 - GPHY LED 2 Config */
#define SSO_CON3_GPHY_LED2_MASK 0x10u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_GPHY_LED2_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSO_CON3_GPHY_LED2_ON 0x1

/*! Field OPT_TX_PUP - PON-IP TX PUP */
#define SSO_CON3_OPT_TX_PUP_POS 13
/*! Field OPT_TX_PUP - PON-IP TX PUP */
#define SSO_CON3_OPT_TX_PUP_MASK 0x2000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_TX_PUP_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSO_CON3_OPT_TX_PUP_ON 0x1

/*! Field OPT_TX_OFF - PON-IP TX Off */
#define SSO_CON3_OPT_TX_OFF_POS 14
/*! Field OPT_TX_OFF - PON-IP TX Off */
#define SSO_CON3_OPT_TX_OFF_MASK 0x4000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_TX_OFF_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSO_CON3_OPT_TX_OFF_ON 0x1

/*! Field SSI_RST - SSI Interface Reset Output */
#define SSO_CON3_SSI_RST_POS 15
/*! Field SSI_RST - SSI Interface Reset Output */
#define SSO_CON3_SSI_RST_MASK 0x8000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_SSI_RST_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_SSI_RST_ON 0x1

/*! Field OPT_GPIO0 - PON-IP GPIO 0 Config */
#define SSO_CON3_OPT_GPIO0_POS 16
/*! Field OPT_GPIO0 - PON-IP GPIO 0 Config */
#define SSO_CON3_OPT_GPIO0_MASK 0x10000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO0_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO0_ON 0x1

/*! Field OPT_GPIO1 - PON-IP GPIO 1 Config */
#define SSO_CON3_OPT_GPIO1_POS 17
/*! Field OPT_GPIO1 - PON-IP GPIO 1 Config */
#define SSO_CON3_OPT_GPIO1_MASK 0x20000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO1_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO1_ON 0x1

/*! Field OPT_GPIO2 - PON-IP GPIO 2 Config */
#define SSO_CON3_OPT_GPIO2_POS 18
/*! Field OPT_GPIO2 - PON-IP GPIO 2 Config */
#define SSO_CON3_OPT_GPIO2_MASK 0x40000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO2_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO2_ON 0x1

/*! Field OPT_GPIO3 - PON-IP GPIO 3 Config */
#define SSO_CON3_OPT_GPIO3_POS 19
/*! Field OPT_GPIO3 - PON-IP GPIO 3 Config */
#define SSO_CON3_OPT_GPIO3_MASK 0x80000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO3_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO3_ON 0x1

/*! Field OPT_GPIO4 - PON-IP GPIO 4 Config */
#define SSO_CON3_OPT_GPIO4_POS 20
/*! Field OPT_GPIO4 - PON-IP GPIO 4 Config */
#define SSO_CON3_OPT_GPIO4_MASK 0x100000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO4_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO4_ON 0x1

/*! Field OPT_GPIO5 - PON-IP GPIO 5 Config */
#define SSO_CON3_OPT_GPIO5_POS 21
/*! Field OPT_GPIO5 - PON-IP GPIO 5 Config */
#define SSO_CON3_OPT_GPIO5_MASK 0x200000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO5_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO5_ON 0x1

/*! Field OPT_GPIO6 - PON-IP GPIO 6 Config */
#define SSO_CON3_OPT_GPIO6_POS 22
/*! Field OPT_GPIO6 - PON-IP GPIO 6 Config */
#define SSO_CON3_OPT_GPIO6_MASK 0x400000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO6_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO6_ON 0x1

/*! Field OPT_GPIO7 - PON-IP GPIO 7 Config */
#define SSO_CON3_OPT_GPIO7_POS 23
/*! Field OPT_GPIO7 - PON-IP GPIO 7 Config */
#define SSO_CON3_OPT_GPIO7_MASK 0x800000u
/*! Constant OFF - Off */
#define CONST_SSO_CON3_OPT_GPIO7_OFF 0x0
/*! Constant ON - On */
#define CONST_SSO_CON3_OPT_GPIO7_ON 0x1

/*! @} */

/*! @} */

#endif
