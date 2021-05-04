/* Copyright (c) 2017, Intel Corporation.
 *
 * GSWIP_LMAC header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _GSWIP_LMAC_H
#define _GSWIP_LMAC_H

/*! \defgroup GSWIP_LMAC Register File GSWIP_LMAC - GSWIP Legacy MAC Register Description */
/*! @{ */

/*! Base Address of GSWIP_LMAC */
#define GSWIP_LMAC_MODULE_BASE 0x18442000u

/*! \defgroup MAC_TEST Register MAC_TEST - MAC Test Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_TEST 0x300
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC_TEST 0x18442300u

/*! Register Reset Value */
#define MAC_TEST_RST 0x0000u

/*! Field JTP - Jitter Test Pattern */
#define MAC_TEST_JTP_POS 0
/*! Field JTP - Jitter Test Pattern */
#define MAC_TEST_JTP_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC_PFAD_CFG Register MAC_PFAD_CFG - MAC Pause Frame Source Address Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_PFAD_CFG 0x304
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC_PFAD_CFG 0x18442304u

/*! Register Reset Value */
#define MAC_PFAD_CFG_RST 0x0000u

/*! Field SAMOD - Source Address Mode */
#define MAC_PFAD_CFG_SAMOD_POS 0
/*! Field SAMOD - Source Address Mode */
#define MAC_PFAD_CFG_SAMOD_MASK 0x1u
/*! Constant COMMON - COMMON */
#define CONST_MAC_PFAD_CFG_SAMOD_COMMON 0x0
/*! Constant PORT - PORT */
#define CONST_MAC_PFAD_CFG_SAMOD_PORT 0x1

/*! @} */

/*! \defgroup MAC_PFSA_0 Register MAC_PFSA_0 - Pause Frame Source Address Part 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_PFSA_0 0x308
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC_PFSA_0 0x18442308u

/*! Register Reset Value */
#define MAC_PFSA_0_RST 0x0100u

/*! Field PFAD - Pause Frame Source Address Part 0 */
#define MAC_PFSA_0_PFAD_POS 0
/*! Field PFAD - Pause Frame Source Address Part 0 */
#define MAC_PFSA_0_PFAD_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC_PFSA_1 Register MAC_PFSA_1 - Pause Frame Source Address Part 1 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_PFSA_1 0x30C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC_PFSA_1 0x1844230Cu

/*! Register Reset Value */
#define MAC_PFSA_1_RST 0x8F00u

/*! Field PFAD - Pause Frame Source Address Part 1 */
#define MAC_PFSA_1_PFAD_POS 0
/*! Field PFAD - Pause Frame Source Address Part 1 */
#define MAC_PFSA_1_PFAD_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC_PFSA_2 Register MAC_PFSA_2 - Pause Frame Source Address Part 2 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_PFSA_2 0x310
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC_PFSA_2 0x18442310u

/*! Register Reset Value */
#define MAC_PFSA_2_RST 0x00D0u

/*! Field PFAD - Pause Frame Source Address Part 2 */
#define MAC_PFSA_2_PFAD_POS 0
/*! Field PFAD - Pause Frame Source Address Part 2 */
#define MAC_PFSA_2_PFAD_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC_IER Register MAC_IER - MAC Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_IER 0x320
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC_IER 0x18442320u

/*! Register Reset Value */
#define MAC_IER_RST 0x0000u

/*! Field MAC2 - MAC 2 Interrupt Enable */
#define MAC_IER_MAC2_POS 0
/*! Field MAC2 - MAC 2 Interrupt Enable */
#define MAC_IER_MAC2_MASK 0x1u

/*! Field MAC3 - MAC 3 Interrupt Enable */
#define MAC_IER_MAC3_POS 1
/*! Field MAC3 - MAC 3 Interrupt Enable */
#define MAC_IER_MAC3_MASK 0x2u

/*! Field MAC4 - MAC 4 Interrupt Enable */
#define MAC_IER_MAC4_POS 2
/*! Field MAC4 - MAC 4 Interrupt Enable */
#define MAC_IER_MAC4_MASK 0x4u

/*! @} */

/*! \defgroup MAC_ISR Register MAC_ISR - MAC Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define REG_MAC_ISR 0x324
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC_ISR 0x18442324u

/*! Register Reset Value */
#define MAC_ISR_RST 0x0000u

/*! Field MAC2 - MAC 2 Interrupt */
#define MAC_ISR_MAC2_POS 0
/*! Field MAC2 - MAC 2 Interrupt */
#define MAC_ISR_MAC2_MASK 0x1u

/*! Field MAC3 - MAC 3 Interrupt */
#define MAC_ISR_MAC3_POS 1
/*! Field MAC3 - MAC 3 Interrupt */
#define MAC_ISR_MAC3_MASK 0x2u

/*! Field MAC4 - MAC 4 Interrupt */
#define MAC_ISR_MAC4_POS 2
/*! Field MAC4 - MAC 4 Interrupt */
#define MAC_ISR_MAC4_MASK 0x4u

/*! @} */

/*! \defgroup LMAC_CNT_LSB Register LMAC_CNT_LSB - Legacy MAC Adaption Counter LSB */
/*! @{ */

/*! Register Offset (relative) */
#define LMAC_CNT_LSB 0x328
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_LMAC_CNT_LSB 0x18442328u

/*! Register Reset Value */
#define LMAC_CNT_LSB_RST 0x0000u

/*! Field LSB - Counter Value LSB */
#define LMAC_CNT_LSB_LSB_POS 0
/*! Field LSB - Counter Value LSB */
#define LMAC_CNT_LSB_LSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup LMAC_CNT_MSB Register LMAC_CNT_MSB - Legacy MAC Adaption Counter MSB */
/*! @{ */

/*! Register Offset (relative) */
#define LMAC_CNT_MSB 0x32C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_LMAC_CNT_MSB 0x1844232Cu

/*! Register Reset Value */
#define LMAC_CNT_MSB_RST 0x0000u

/*! Field MSB - Counter Value MSB */
#define LMAC_CNT_MSB_MSB_POS 0
/*! Field MSB - Counter Value MSB */
#define LMAC_CNT_MSB_MSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup LMAC_CNT_ACC Register LMAC_CNT_ACC - Legacy MAC Adaption Counter Access */
/*! @{ */

/*! Register Offset (relative) */
#define LMAC_CNT_ACC 0x330
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_LMAC_CNT_ACC 0x18442330u

/*! Register Reset Value */
#define LMAC_CNT_ACC_RST 0x0000u

/*! Field ADDR - Address for Counter selection */
#define LMAC_CNT_ACC_ADDR_POS 0
/*! Field ADDR - Address for Counter selection */
#define LMAC_CNT_ACC_ADDR_MASK 0x1Fu
/*! Constant SINGLE - Single */
#define CONST_LMAC_CNT_ACC_ADDR_SINGLE 0x0
/*! Constant MULTIPLE - Multiple */
#define CONST_LMAC_CNT_ACC_ADDR_MULTIPLE 0x1
/*! Constant LATE - Late */
#define CONST_LMAC_CNT_ACC_ADDR_LATE 0x2
/*! Constant EXCESS - Excess */
#define CONST_LMAC_CNT_ACC_ADDR_EXCESS 0x3
/*! Constant RXPAUSE - RXPAUSE */
#define CONST_LMAC_CNT_ACC_ADDR_RXPAUSE 0x4
/*! Constant TXPAUSE - TXPAUSE */
#define CONST_LMAC_CNT_ACC_ADDR_TXPAUSE 0x5

/*! Field MAC - MAC for Counter selection */
#define LMAC_CNT_ACC_MAC_POS 8
/*! Field MAC - MAC for Counter selection */
#define LMAC_CNT_ACC_MAC_MASK 0xF00u
/*! Constant MAC2 - MAC2 */
#define CONST_LMAC_CNT_ACC_MAC_MAC2 0x2
/*! Constant MAC3 - MAC3 */
#define CONST_LMAC_CNT_ACC_MAC_MAC3 0x3
/*! Constant MAC4 - MAC4 */
#define CONST_LMAC_CNT_ACC_MAC_MAC4 0x4

/*! Field OPMOD - Access Operation Mode */
#define LMAC_CNT_ACC_OPMOD_POS 13
/*! Field OPMOD - Access Operation Mode */
#define LMAC_CNT_ACC_OPMOD_MASK 0x6000u
/*! Constant RD - RD */
#define CONST_LMAC_CNT_ACC_OPMOD_RD 0x0
/*! Constant CLEARMAC - ClearMAC */
#define CONST_LMAC_CNT_ACC_OPMOD_CLEARMAC 0x1
/*! Constant WR - WR */
#define CONST_LMAC_CNT_ACC_OPMOD_WR 0x2
/*! Constant CLEARALL - ClearAll */
#define CONST_LMAC_CNT_ACC_OPMOD_CLEARALL 0x3

/*! Field BAS - Access Busy/Access Start */
#define LMAC_CNT_ACC_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define LMAC_CNT_ACC_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_LMAC_CNT_ACC_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_LMAC_CNT_ACC_BAS_BUSY 0x1

/*! @} */

/*! \defgroup MAC2_PISR Register MAC2_PISR - MAC 2 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_PISR 0x404
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_PISR 0x18442404u

/*! Register Reset Value */
#define MAC2_PISR_RST 0x0000u

/*! Field RXPAUSE - Pause Frame Received */
#define MAC2_PISR_RXPAUSE_POS 0
/*! Field RXPAUSE - Pause Frame Received */
#define MAC2_PISR_RXPAUSE_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_RXPAUSE_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_RXPAUSE_INT 0x1

/*! Field TXPAUSE - Pause Frame Transmitted */
#define MAC2_PISR_TXPAUSE_POS 1
/*! Field TXPAUSE - Pause Frame Transmitted */
#define MAC2_PISR_TXPAUSE_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_TXPAUSE_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_TXPAUSE_INT 0x1

/*! Field FCSERR - Frame Checksum Error Detected */
#define MAC2_PISR_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Detected */
#define MAC2_PISR_FCSERR_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_FCSERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_FCSERR_INT 0x1

/*! Field LENERR - Length Mismatch Error Detected */
#define MAC2_PISR_LENERR_POS 3
/*! Field LENERR - Length Mismatch Error Detected */
#define MAC2_PISR_LENERR_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_LENERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_LENERR_INT 0x1

/*! Field TOOLONG - Too Long Frame Error Detected */
#define MAC2_PISR_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Detected */
#define MAC2_PISR_TOOLONG_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_TOOLONG_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_TOOLONG_INT 0x1

/*! Field TOOSHORT - Too Short Frame Error Detected */
#define MAC2_PISR_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Detected */
#define MAC2_PISR_TOOSHORT_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_TOOSHORT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_TOOSHORT_INT 0x1

/*! Field JAM - Jam Status Detected */
#define MAC2_PISR_JAM_POS 6
/*! Field JAM - Jam Status Detected */
#define MAC2_PISR_JAM_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_JAM_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_JAM_INT 0x1

/*! Field LPION - Receive Low-power Idle Mode is entered */
#define MAC2_PISR_LPION_POS 7
/*! Field LPION - Receive Low-power Idle Mode is entered */
#define MAC2_PISR_LPION_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_LPION_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_LPION_INT 0x1

/*! Field LPIOFF - Receive Low-power Idle Mode is left */
#define MAC2_PISR_LPIOFF_POS 8
/*! Field LPIOFF - Receive Low-power Idle Mode is left */
#define MAC2_PISR_LPIOFF_MASK 0x100u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_LPIOFF_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_LPIOFF_INT 0x1

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC2_PISR_TXPAUEN_POS 9
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC2_PISR_TXPAUEN_MASK 0x200u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_TXPAUEN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_TXPAUEN_INT 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC2_PISR_RXPAUEN_POS 10
/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC2_PISR_RXPAUEN_MASK 0x400u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_RXPAUEN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_RXPAUEN_INT 0x1

/*! Field FDUP - Full Duplex Status */
#define MAC2_PISR_FDUP_POS 11
/*! Field FDUP - Full Duplex Status */
#define MAC2_PISR_FDUP_MASK 0x800u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_FDUP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_FDUP_INT 0x1

/*! Field SPEED - Megabit Speed Status */
#define MAC2_PISR_SPEED_POS 12
/*! Field SPEED - Megabit Speed Status */
#define MAC2_PISR_SPEED_MASK 0x1000u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_SPEED_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_SPEED_INT 0x1

/*! Field ALIGN - Alignment Error Interrupt */
#define MAC2_PISR_ALIGN_POS 14
/*! Field ALIGN - Alignment Error Interrupt */
#define MAC2_PISR_ALIGN_MASK 0x4000u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_ALIGN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_ALIGN_INT 0x1

/*! Field PHYERR - PHY Error Interrupt */
#define MAC2_PISR_PHYERR_POS 15
/*! Field PHYERR - PHY Error Interrupt */
#define MAC2_PISR_PHYERR_MASK 0x8000u
/*! Constant NOINT - NOINT */
#define CONST_MAC2_PISR_PHYERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC2_PISR_PHYERR_INT 0x1

/*! @} */

/*! \defgroup MAC2_PIER Register MAC2_PIER - MAC 2 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_PIER 0x408
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_PIER 0x18442408u

/*! Register Reset Value */
#define MAC2_PIER_RST 0x0000u

/*! Field RXPAUSE - Receive Pause Frame Interrupt Mask */
#define MAC2_PIER_RXPAUSE_POS 0
/*! Field RXPAUSE - Receive Pause Frame Interrupt Mask */
#define MAC2_PIER_RXPAUSE_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_RXPAUSE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_RXPAUSE_EN 0x1

/*! Field TXPAUSE - Transmit Pause Frame Interrupt Mask */
#define MAC2_PIER_TXPAUSE_POS 1
/*! Field TXPAUSE - Transmit Pause Frame Interrupt Mask */
#define MAC2_PIER_TXPAUSE_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_TXPAUSE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_TXPAUSE_EN 0x1

/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define MAC2_PIER_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define MAC2_PIER_FCSERR_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_FCSERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_FCSERR_EN 0x1

/*! Field LENERR - Length Mismatch Error Interrupt Mask */
#define MAC2_PIER_LENERR_POS 3
/*! Field LENERR - Length Mismatch Error Interrupt Mask */
#define MAC2_PIER_LENERR_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_LENERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_LENERR_EN 0x1

/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define MAC2_PIER_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define MAC2_PIER_TOOLONG_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_TOOLONG_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_TOOLONG_EN 0x1

/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define MAC2_PIER_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define MAC2_PIER_TOOSHORT_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_TOOSHORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_TOOSHORT_EN 0x1

/*! Field JAM - Jam Status Interrupt Mask */
#define MAC2_PIER_JAM_POS 6
/*! Field JAM - Jam Status Interrupt Mask */
#define MAC2_PIER_JAM_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_JAM_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_JAM_EN 0x1

/*! Field LPION - Low-power Idle On Interrupt Mask */
#define MAC2_PIER_LPION_POS 7
/*! Field LPION - Low-power Idle On Interrupt Mask */
#define MAC2_PIER_LPION_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_LPION_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_LPION_EN 0x1

/*! Field LPIOFF - Low-power Idle Off Interrupt Mask */
#define MAC2_PIER_LPIOFF_POS 8
/*! Field LPIOFF - Low-power Idle Off Interrupt Mask */
#define MAC2_PIER_LPIOFF_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_LPIOFF_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_LPIOFF_EN 0x1

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC2_PIER_TXPAUEN_POS 9
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC2_PIER_TXPAUEN_MASK 0x200u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_TXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_TXPAUEN_EN 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC2_PIER_RXPAUEN_POS 10
/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC2_PIER_RXPAUEN_MASK 0x400u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_RXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_RXPAUEN_EN 0x1

/*! Field FDUP - Full Duplex Status */
#define MAC2_PIER_FDUP_POS 11
/*! Field FDUP - Full Duplex Status */
#define MAC2_PIER_FDUP_MASK 0x800u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_FDUP_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_FDUP_EN 0x1

/*! Field SPEED - Megabit Speed Status */
#define MAC2_PIER_SPEED_POS 12
/*! Field SPEED - Megabit Speed Status */
#define MAC2_PIER_SPEED_MASK 0x1000u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_SPEED_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_SPEED_EN 0x1

/*! Field ALIGN - Alignment Error Interrupt */
#define MAC2_PIER_ALIGN_POS 14
/*! Field ALIGN - Alignment Error Interrupt */
#define MAC2_PIER_ALIGN_MASK 0x4000u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_ALIGN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_ALIGN_EN 0x1

/*! Field PHYERR - PHY Error Interrupt */
#define MAC2_PIER_PHYERR_POS 15
/*! Field PHYERR - PHY Error Interrupt */
#define MAC2_PIER_PHYERR_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_MAC2_PIER_PHYERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_PIER_PHYERR_EN 0x1

/*! @} */

/*! \defgroup MAC2_CTRL_0 Register MAC2_CTRL_0 - MAC 2 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_CTRL_0 0x40C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_CTRL_0 0x1844240Cu

/*! Register Reset Value */
#define MAC2_CTRL_0_RST 0x0180u

/*! Field FCS - Transmit FCS Control */
#define MAC2_CTRL_0_FCS_POS 7
/*! Field FCS - Transmit FCS Control */
#define MAC2_CTRL_0_FCS_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC2_CTRL_0_FCS_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_CTRL_0_FCS_EN 0x1

/*! Field PADEN - Padding Enable */
#define MAC2_CTRL_0_PADEN_POS 8
/*! Field PADEN - Padding Enable */
#define MAC2_CTRL_0_PADEN_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC2_CTRL_0_PADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_CTRL_0_PADEN_EN 0x1

/*! @} */

/*! \defgroup MAC2_CTRL_1 Register MAC2_CTRL_1 - MAC 2 Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_CTRL_1 0x410
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_CTRL_1 0x18442410u

/*! Register Reset Value */
#define MAC2_CTRL_1_RST 0x000Cu

/*! Field IPG - Minimum Inter Packet Gap Size */
#define MAC2_CTRL_1_IPG_POS 0
/*! Field IPG - Minimum Inter Packet Gap Size */
#define MAC2_CTRL_1_IPG_MASK 0xFu

/*! Field SHORTPRE - Short Preamble Control */
#define MAC2_CTRL_1_SHORTPRE_POS 8
/*! Field SHORTPRE - Short Preamble Control */
#define MAC2_CTRL_1_SHORTPRE_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC2_CTRL_1_SHORTPRE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_CTRL_1_SHORTPRE_EN 0x1

/*! Field DEFERMODE - Defer Model */
#define MAC2_CTRL_1_DEFERMODE_POS 15
/*! Field DEFERMODE - Defer Model */
#define MAC2_CTRL_1_DEFERMODE_MASK 0x8000u
/*! Constant NORMAL - NORMAL */
#define CONST_MAC2_CTRL_1_DEFERMODE_NORMAL 0x0
/*! Constant CRS_BP - CRS_BP */
#define CONST_MAC2_CTRL_1_DEFERMODE_CRS_BP 0x1

/*! @} */

/*! \defgroup MAC2_CTRL_3 Register MAC2_CTRL_3 - MAC 2 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_CTRL_3 0x418
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_CTRL_3 0x18442418u

/*! Register Reset Value */
#define MAC2_CTRL_3_RST 0x000Fu

/*! Field RCNT - Retry Count */
#define MAC2_CTRL_3_RCNT_POS 0
/*! Field RCNT - Retry Count */
#define MAC2_CTRL_3_RCNT_MASK 0xFu

/*! @} */

/*! \defgroup MAC2_CTRL_4 Register MAC2_CTRL_4 - MAC 2 Control Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_CTRL_4 0x41C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_CTRL_4 0x1844241Cu

/*! Register Reset Value */
#define MAC2_CTRL_4_RST 0x1414u

/*! Field WAIT - LPI Wait Time for 100M */
#define MAC2_CTRL_4_WAIT_POS 0
/*! Field WAIT - LPI Wait Time for 100M */
#define MAC2_CTRL_4_WAIT_MASK 0x7Fu

/*! Field LPIEN - LPI Mode Enable */
#define MAC2_CTRL_4_LPIEN_POS 7
/*! Field LPIEN - LPI Mode Enable */
#define MAC2_CTRL_4_LPIEN_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC2_CTRL_4_LPIEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_CTRL_4_LPIEN_EN 0x1

/*! Field GWAIT - LPI Wait Time for 1G */
#define MAC2_CTRL_4_GWAIT_POS 8
/*! Field GWAIT - LPI Wait Time for 1G */
#define MAC2_CTRL_4_GWAIT_MASK 0x7F00u

/*! @} */

/*! \defgroup MAC2_CTRL_5 Register MAC2_CTRL_5 - MAC 2 Control Register 5 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_CTRL_5 0x420
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_CTRL_5 0x18442420u

/*! Register Reset Value */
#define MAC2_CTRL_5_RST 0x0000u

/*! Field PJPS_BP - Prolonged Jam pattern size during backpressure state */
#define MAC2_CTRL_5_PJPS_BP_POS 0
/*! Field PJPS_BP - Prolonged Jam pattern size during backpressure state */
#define MAC2_CTRL_5_PJPS_BP_MASK 0x1u
/*! Constant SHORT - SHORT */
#define CONST_MAC2_CTRL_5_PJPS_BP_SHORT 0x0
/*! Constant LONG - LONG */
#define CONST_MAC2_CTRL_5_PJPS_BP_LONG 0x1

/*! Field PJPS_NOBP - Prolonged Jam pattern size during no-backpressure state */
#define MAC2_CTRL_5_PJPS_NOBP_POS 1
/*! Field PJPS_NOBP - Prolonged Jam pattern size during no-backpressure state */
#define MAC2_CTRL_5_PJPS_NOBP_MASK 0x2u
/*! Constant SHORT - SHORT */
#define CONST_MAC2_CTRL_5_PJPS_NOBP_SHORT 0x0
/*! Constant LONG - LONG */
#define CONST_MAC2_CTRL_5_PJPS_NOBP_LONG 0x1

/*! @} */

/*! \defgroup MAC2_LPITMER0 Register MAC2_LPITMER0 - MAC 2 LPI Timer Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_LPITMER0 0x424
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_LPITMER0 0x18442424u

/*! Register Reset Value */
#define MAC2_LPITMER0_RST 0x0000u

/*! Field TMLSB - MAC LPI Timer LSB */
#define MAC2_LPITMER0_TMLSB_POS 0
/*! Field TMLSB - MAC LPI Timer LSB */
#define MAC2_LPITMER0_TMLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_LPITMER1 Register MAC2_LPITMER1 - MAC 2 LPI Timer Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_LPITMER1 0x428
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_LPITMER1 0x18442428u

/*! Register Reset Value */
#define MAC2_LPITMER1_RST 0x0000u

/*! Field TMLSB - MAC LPI Timer MSB */
#define MAC2_LPITMER1_TMLSB_POS 0
/*! Field TMLSB - MAC LPI Timer MSB */
#define MAC2_LPITMER1_TMLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_TESTEN Register MAC2_TESTEN - MAC 2 Test Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_TESTEN 0x42C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC2_TESTEN 0x1844242Cu

/*! Register Reset Value */
#define MAC2_TESTEN_RST 0x0000u

/*! Field LOOP - MAC Loopback Enable */
#define MAC2_TESTEN_LOOP_POS 0
/*! Field LOOP - MAC Loopback Enable */
#define MAC2_TESTEN_LOOP_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_MAC2_TESTEN_LOOP_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_TESTEN_LOOP_EN 0x1

/*! Field TXER - Transmit Error Insertion */
#define MAC2_TESTEN_TXER_POS 1
/*! Field TXER - Transmit Error Insertion */
#define MAC2_TESTEN_TXER_MASK 0x2u
/*! Constant NORM - NORM */
#define CONST_MAC2_TESTEN_TXER_NORM 0x0
/*! Constant TEST - TEST */
#define CONST_MAC2_TESTEN_TXER_TEST 0x1

/*! Field JTEN - Jitter Test Enable */
#define MAC2_TESTEN_JTEN_POS 2
/*! Field JTEN - Jitter Test Enable */
#define MAC2_TESTEN_JTEN_MASK 0x4u
/*! Constant NORM - NORM */
#define CONST_MAC2_TESTEN_JTEN_NORM 0x0
/*! Constant TEST - TEST */
#define CONST_MAC2_TESTEN_JTEN_TEST 0x1

/*! Field LPITM - LPI Monitoring Mode */
#define MAC2_TESTEN_LPITM_POS 8
/*! Field LPITM - LPI Monitoring Mode */
#define MAC2_TESTEN_LPITM_MASK 0x300u
/*! Constant TX - TX */
#define CONST_MAC2_TESTEN_LPITM_TX 0x0
/*! Constant RX - RX */
#define CONST_MAC2_TESTEN_LPITM_RX 0x1
/*! Constant TXRX - TXRX */
#define CONST_MAC2_TESTEN_LPITM_TXRX 0x2
/*! Constant RES - RES */
#define CONST_MAC2_TESTEN_LPITM_RES 0x3

/*! @} */

/*! \defgroup MAC3_PISR Register MAC3_PISR - MAC 3 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_PISR 0x434
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_PISR 0x18442434u

/*! Register Reset Value */
#define MAC3_PISR_RST 0x0000u

/*! Field RXPAUSE - Pause Frame Received */
#define MAC3_PISR_RXPAUSE_POS 0
/*! Field RXPAUSE - Pause Frame Received */
#define MAC3_PISR_RXPAUSE_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_RXPAUSE_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_RXPAUSE_INT 0x1

/*! Field TXPAUSE - Pause Frame Transmitted */
#define MAC3_PISR_TXPAUSE_POS 1
/*! Field TXPAUSE - Pause Frame Transmitted */
#define MAC3_PISR_TXPAUSE_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_TXPAUSE_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_TXPAUSE_INT 0x1

/*! Field FCSERR - Frame Checksum Error Detected */
#define MAC3_PISR_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Detected */
#define MAC3_PISR_FCSERR_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_FCSERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_FCSERR_INT 0x1

/*! Field LENERR - Length Mismatch Error Detected */
#define MAC3_PISR_LENERR_POS 3
/*! Field LENERR - Length Mismatch Error Detected */
#define MAC3_PISR_LENERR_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_LENERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_LENERR_INT 0x1

/*! Field TOOLONG - Too Long Frame Error Detected */
#define MAC3_PISR_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Detected */
#define MAC3_PISR_TOOLONG_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_TOOLONG_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_TOOLONG_INT 0x1

/*! Field TOOSHORT - Too Short Frame Error Detected */
#define MAC3_PISR_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Detected */
#define MAC3_PISR_TOOSHORT_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_TOOSHORT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_TOOSHORT_INT 0x1

/*! Field JAM - Jam Status Detected */
#define MAC3_PISR_JAM_POS 6
/*! Field JAM - Jam Status Detected */
#define MAC3_PISR_JAM_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_JAM_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_JAM_INT 0x1

/*! Field LPION - Receive Low-power Idle Mode is entered */
#define MAC3_PISR_LPION_POS 7
/*! Field LPION - Receive Low-power Idle Mode is entered */
#define MAC3_PISR_LPION_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_LPION_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_LPION_INT 0x1

/*! Field LPIOFF - Receive Low-power Idle Mode is left */
#define MAC3_PISR_LPIOFF_POS 8
/*! Field LPIOFF - Receive Low-power Idle Mode is left */
#define MAC3_PISR_LPIOFF_MASK 0x100u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_LPIOFF_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_LPIOFF_INT 0x1

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC3_PISR_TXPAUEN_POS 9
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC3_PISR_TXPAUEN_MASK 0x200u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_TXPAUEN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_TXPAUEN_INT 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC3_PISR_RXPAUEN_POS 10
/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC3_PISR_RXPAUEN_MASK 0x400u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_RXPAUEN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_RXPAUEN_INT 0x1

/*! Field FDUP - Full Duplex Status */
#define MAC3_PISR_FDUP_POS 11
/*! Field FDUP - Full Duplex Status */
#define MAC3_PISR_FDUP_MASK 0x800u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_FDUP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_FDUP_INT 0x1

/*! Field SPEED - Megabit Speed Status */
#define MAC3_PISR_SPEED_POS 12
/*! Field SPEED - Megabit Speed Status */
#define MAC3_PISR_SPEED_MASK 0x1000u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_SPEED_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_SPEED_INT 0x1

/*! Field ALIGN - Alignment Error Interrupt */
#define MAC3_PISR_ALIGN_POS 14
/*! Field ALIGN - Alignment Error Interrupt */
#define MAC3_PISR_ALIGN_MASK 0x4000u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_ALIGN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_ALIGN_INT 0x1

/*! Field PHYERR - PHY Error Interrupt */
#define MAC3_PISR_PHYERR_POS 15
/*! Field PHYERR - PHY Error Interrupt */
#define MAC3_PISR_PHYERR_MASK 0x8000u
/*! Constant NOINT - NOINT */
#define CONST_MAC3_PISR_PHYERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC3_PISR_PHYERR_INT 0x1

/*! @} */

/*! \defgroup MAC3_PIER Register MAC3_PIER - MAC 3 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_PIER 0x438
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_PIER 0x18442438u

/*! Register Reset Value */
#define MAC3_PIER_RST 0x0000u

/*! Field RXPAUSE - Receive Pause Frame Interrupt Mask */
#define MAC3_PIER_RXPAUSE_POS 0
/*! Field RXPAUSE - Receive Pause Frame Interrupt Mask */
#define MAC3_PIER_RXPAUSE_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_RXPAUSE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_RXPAUSE_EN 0x1

/*! Field TXPAUSE - Transmit Pause Frame Interrupt Mask */
#define MAC3_PIER_TXPAUSE_POS 1
/*! Field TXPAUSE - Transmit Pause Frame Interrupt Mask */
#define MAC3_PIER_TXPAUSE_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_TXPAUSE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_TXPAUSE_EN 0x1

/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define MAC3_PIER_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define MAC3_PIER_FCSERR_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_FCSERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_FCSERR_EN 0x1

/*! Field LENERR - Length Mismatch Error Interrupt Mask */
#define MAC3_PIER_LENERR_POS 3
/*! Field LENERR - Length Mismatch Error Interrupt Mask */
#define MAC3_PIER_LENERR_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_LENERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_LENERR_EN 0x1

/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define MAC3_PIER_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define MAC3_PIER_TOOLONG_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_TOOLONG_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_TOOLONG_EN 0x1

/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define MAC3_PIER_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define MAC3_PIER_TOOSHORT_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_TOOSHORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_TOOSHORT_EN 0x1

/*! Field JAM - Jam Status Interrupt Mask */
#define MAC3_PIER_JAM_POS 6
/*! Field JAM - Jam Status Interrupt Mask */
#define MAC3_PIER_JAM_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_JAM_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_JAM_EN 0x1

/*! Field LPION - Low-power Idle On Interrupt Mask */
#define MAC3_PIER_LPION_POS 7
/*! Field LPION - Low-power Idle On Interrupt Mask */
#define MAC3_PIER_LPION_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_LPION_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_LPION_EN 0x1

/*! Field LPIOFF - Low-power Idle Off Interrupt Mask */
#define MAC3_PIER_LPIOFF_POS 8
/*! Field LPIOFF - Low-power Idle Off Interrupt Mask */
#define MAC3_PIER_LPIOFF_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_LPIOFF_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_LPIOFF_EN 0x1

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC3_PIER_TXPAUEN_POS 9
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC3_PIER_TXPAUEN_MASK 0x200u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_TXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_TXPAUEN_EN 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC3_PIER_RXPAUEN_POS 10
/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC3_PIER_RXPAUEN_MASK 0x400u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_RXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_RXPAUEN_EN 0x1

/*! Field FDUP - Full Duplex Status */
#define MAC3_PIER_FDUP_POS 11
/*! Field FDUP - Full Duplex Status */
#define MAC3_PIER_FDUP_MASK 0x800u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_FDUP_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_FDUP_EN 0x1

/*! Field SPEED - Megabit Speed Status */
#define MAC3_PIER_SPEED_POS 12
/*! Field SPEED - Megabit Speed Status */
#define MAC3_PIER_SPEED_MASK 0x1000u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_SPEED_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_SPEED_EN 0x1

/*! Field ALIGN - Alignment Error Interrupt */
#define MAC3_PIER_ALIGN_POS 14
/*! Field ALIGN - Alignment Error Interrupt */
#define MAC3_PIER_ALIGN_MASK 0x4000u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_ALIGN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_ALIGN_EN 0x1

/*! Field PHYERR - PHY Error Interrupt */
#define MAC3_PIER_PHYERR_POS 15
/*! Field PHYERR - PHY Error Interrupt */
#define MAC3_PIER_PHYERR_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_MAC3_PIER_PHYERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_PIER_PHYERR_EN 0x1

/*! @} */

/*! \defgroup MAC3_CTRL_0 Register MAC3_CTRL_0 - MAC 3 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_CTRL_0 0x43C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_CTRL_0 0x1844243Cu

/*! Register Reset Value */
#define MAC3_CTRL_0_RST 0x0180u

/*! Field FCS - Transmit FCS Control */
#define MAC3_CTRL_0_FCS_POS 7
/*! Field FCS - Transmit FCS Control */
#define MAC3_CTRL_0_FCS_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC3_CTRL_0_FCS_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_CTRL_0_FCS_EN 0x1

/*! Field PADEN - Padding Enable */
#define MAC3_CTRL_0_PADEN_POS 8
/*! Field PADEN - Padding Enable */
#define MAC3_CTRL_0_PADEN_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC3_CTRL_0_PADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_CTRL_0_PADEN_EN 0x1

/*! @} */

/*! \defgroup MAC3_CTRL_1 Register MAC3_CTRL_1 - MAC 3 Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_CTRL_1 0x440
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_CTRL_1 0x18442440u

/*! Register Reset Value */
#define MAC3_CTRL_1_RST 0x000Cu

/*! Field IPG - Minimum Inter Packet Gap Size */
#define MAC3_CTRL_1_IPG_POS 0
/*! Field IPG - Minimum Inter Packet Gap Size */
#define MAC3_CTRL_1_IPG_MASK 0xFu

/*! Field SHORTPRE - Short Preamble Control */
#define MAC3_CTRL_1_SHORTPRE_POS 8
/*! Field SHORTPRE - Short Preamble Control */
#define MAC3_CTRL_1_SHORTPRE_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC3_CTRL_1_SHORTPRE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_CTRL_1_SHORTPRE_EN 0x1

/*! Field DEFERMODE - Defer Model */
#define MAC3_CTRL_1_DEFERMODE_POS 15
/*! Field DEFERMODE - Defer Model */
#define MAC3_CTRL_1_DEFERMODE_MASK 0x8000u
/*! Constant NORMAL - NORMAL */
#define CONST_MAC3_CTRL_1_DEFERMODE_NORMAL 0x0
/*! Constant CRS_BP - CRS_BP */
#define CONST_MAC3_CTRL_1_DEFERMODE_CRS_BP 0x1

/*! @} */

/*! \defgroup MAC3_CTRL_3 Register MAC3_CTRL_3 - MAC 3 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_CTRL_3 0x448
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_CTRL_3 0x18442448u

/*! Register Reset Value */
#define MAC3_CTRL_3_RST 0x000Fu

/*! Field RCNT - Retry Count */
#define MAC3_CTRL_3_RCNT_POS 0
/*! Field RCNT - Retry Count */
#define MAC3_CTRL_3_RCNT_MASK 0xFu

/*! @} */

/*! \defgroup MAC3_CTRL_4 Register MAC3_CTRL_4 - MAC 3 Control Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_CTRL_4 0x44C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_CTRL_4 0x1844244Cu

/*! Register Reset Value */
#define MAC3_CTRL_4_RST 0x1414u

/*! Field WAIT - LPI Wait Time for 100M */
#define MAC3_CTRL_4_WAIT_POS 0
/*! Field WAIT - LPI Wait Time for 100M */
#define MAC3_CTRL_4_WAIT_MASK 0x7Fu

/*! Field LPIEN - LPI Mode Enable */
#define MAC3_CTRL_4_LPIEN_POS 7
/*! Field LPIEN - LPI Mode Enable */
#define MAC3_CTRL_4_LPIEN_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC3_CTRL_4_LPIEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_CTRL_4_LPIEN_EN 0x1

/*! Field GWAIT - LPI Wait Time for 1G */
#define MAC3_CTRL_4_GWAIT_POS 8
/*! Field GWAIT - LPI Wait Time for 1G */
#define MAC3_CTRL_4_GWAIT_MASK 0x7F00u

/*! @} */

/*! \defgroup MAC3_CTRL_5 Register MAC3_CTRL_5 - MAC 3 Control Register 5 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_CTRL_5 0x450
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_CTRL_5 0x18442450u

/*! Register Reset Value */
#define MAC3_CTRL_5_RST 0x0000u

/*! Field PJPS_BP - Prolonged Jam pattern size during backpressure state */
#define MAC3_CTRL_5_PJPS_BP_POS 0
/*! Field PJPS_BP - Prolonged Jam pattern size during backpressure state */
#define MAC3_CTRL_5_PJPS_BP_MASK 0x1u
/*! Constant SHORT - SHORT */
#define CONST_MAC3_CTRL_5_PJPS_BP_SHORT 0x0
/*! Constant LONG - LONG */
#define CONST_MAC3_CTRL_5_PJPS_BP_LONG 0x1

/*! Field PJPS_NOBP - Prolonged Jam pattern size during no-backpressure state */
#define MAC3_CTRL_5_PJPS_NOBP_POS 1
/*! Field PJPS_NOBP - Prolonged Jam pattern size during no-backpressure state */
#define MAC3_CTRL_5_PJPS_NOBP_MASK 0x2u
/*! Constant SHORT - SHORT */
#define CONST_MAC3_CTRL_5_PJPS_NOBP_SHORT 0x0
/*! Constant LONG - LONG */
#define CONST_MAC3_CTRL_5_PJPS_NOBP_LONG 0x1

/*! @} */

/*! \defgroup MAC3_LPITMER0 Register MAC3_LPITMER0 - MAC 3 LPI Timer Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_LPITMER0 0x454
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_LPITMER0 0x18442454u

/*! Register Reset Value */
#define MAC3_LPITMER0_RST 0x0000u

/*! Field TMLSB - MAC LPI Timer LSB */
#define MAC3_LPITMER0_TMLSB_POS 0
/*! Field TMLSB - MAC LPI Timer LSB */
#define MAC3_LPITMER0_TMLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_LPITMER1 Register MAC3_LPITMER1 - MAC 3 LPI Timer Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_LPITMER1 0x458
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_LPITMER1 0x18442458u

/*! Register Reset Value */
#define MAC3_LPITMER1_RST 0x0000u

/*! Field TMLSB - MAC LPI Timer MSB */
#define MAC3_LPITMER1_TMLSB_POS 0
/*! Field TMLSB - MAC LPI Timer MSB */
#define MAC3_LPITMER1_TMLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_TESTEN Register MAC3_TESTEN - MAC 3 Test Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_TESTEN 0x45C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC3_TESTEN 0x1844245Cu

/*! Register Reset Value */
#define MAC3_TESTEN_RST 0x0000u

/*! Field LOOP - MAC Loopback Enable */
#define MAC3_TESTEN_LOOP_POS 0
/*! Field LOOP - MAC Loopback Enable */
#define MAC3_TESTEN_LOOP_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_MAC3_TESTEN_LOOP_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_TESTEN_LOOP_EN 0x1

/*! Field TXER - Transmit Error Insertion */
#define MAC3_TESTEN_TXER_POS 1
/*! Field TXER - Transmit Error Insertion */
#define MAC3_TESTEN_TXER_MASK 0x2u
/*! Constant NORM - NORM */
#define CONST_MAC3_TESTEN_TXER_NORM 0x0
/*! Constant TEST - TEST */
#define CONST_MAC3_TESTEN_TXER_TEST 0x1

/*! Field JTEN - Jitter Test Enable */
#define MAC3_TESTEN_JTEN_POS 2
/*! Field JTEN - Jitter Test Enable */
#define MAC3_TESTEN_JTEN_MASK 0x4u
/*! Constant NORM - NORM */
#define CONST_MAC3_TESTEN_JTEN_NORM 0x0
/*! Constant TEST - TEST */
#define CONST_MAC3_TESTEN_JTEN_TEST 0x1

/*! Field LPITM - LPI Monitoring Mode */
#define MAC3_TESTEN_LPITM_POS 8
/*! Field LPITM - LPI Monitoring Mode */
#define MAC3_TESTEN_LPITM_MASK 0x300u
/*! Constant TX - TX */
#define CONST_MAC3_TESTEN_LPITM_TX 0x0
/*! Constant RX - RX */
#define CONST_MAC3_TESTEN_LPITM_RX 0x1
/*! Constant TXRX - TXRX */
#define CONST_MAC3_TESTEN_LPITM_TXRX 0x2
/*! Constant RES - RES */
#define CONST_MAC3_TESTEN_LPITM_RES 0x3

/*! @} */

/*! \defgroup MAC4_PISR Register MAC4_PISR - MAC 4 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_PISR 0x464
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_PISR 0x18442464u

/*! Register Reset Value */
#define MAC4_PISR_RST 0x0000u

/*! Field RXPAUSE - Pause Frame Received */
#define MAC4_PISR_RXPAUSE_POS 0
/*! Field RXPAUSE - Pause Frame Received */
#define MAC4_PISR_RXPAUSE_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_RXPAUSE_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_RXPAUSE_INT 0x1

/*! Field TXPAUSE - Pause Frame Transmitted */
#define MAC4_PISR_TXPAUSE_POS 1
/*! Field TXPAUSE - Pause Frame Transmitted */
#define MAC4_PISR_TXPAUSE_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_TXPAUSE_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_TXPAUSE_INT 0x1

/*! Field FCSERR - Frame Checksum Error Detected */
#define MAC4_PISR_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Detected */
#define MAC4_PISR_FCSERR_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_FCSERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_FCSERR_INT 0x1

/*! Field LENERR - Length Mismatch Error Detected */
#define MAC4_PISR_LENERR_POS 3
/*! Field LENERR - Length Mismatch Error Detected */
#define MAC4_PISR_LENERR_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_LENERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_LENERR_INT 0x1

/*! Field TOOLONG - Too Long Frame Error Detected */
#define MAC4_PISR_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Detected */
#define MAC4_PISR_TOOLONG_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_TOOLONG_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_TOOLONG_INT 0x1

/*! Field TOOSHORT - Too Short Frame Error Detected */
#define MAC4_PISR_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Detected */
#define MAC4_PISR_TOOSHORT_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_TOOSHORT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_TOOSHORT_INT 0x1

/*! Field JAM - Jam Status Detected */
#define MAC4_PISR_JAM_POS 6
/*! Field JAM - Jam Status Detected */
#define MAC4_PISR_JAM_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_JAM_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_JAM_INT 0x1

/*! Field LPION - Receive Low-power Idle Mode is entered */
#define MAC4_PISR_LPION_POS 7
/*! Field LPION - Receive Low-power Idle Mode is entered */
#define MAC4_PISR_LPION_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_LPION_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_LPION_INT 0x1

/*! Field LPIOFF - Receive Low-power Idle Mode is left */
#define MAC4_PISR_LPIOFF_POS 8
/*! Field LPIOFF - Receive Low-power Idle Mode is left */
#define MAC4_PISR_LPIOFF_MASK 0x100u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_LPIOFF_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_LPIOFF_INT 0x1

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC4_PISR_TXPAUEN_POS 9
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC4_PISR_TXPAUEN_MASK 0x200u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_TXPAUEN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_TXPAUEN_INT 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC4_PISR_RXPAUEN_POS 10
/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC4_PISR_RXPAUEN_MASK 0x400u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_RXPAUEN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_RXPAUEN_INT 0x1

/*! Field FDUP - Full Duplex Status */
#define MAC4_PISR_FDUP_POS 11
/*! Field FDUP - Full Duplex Status */
#define MAC4_PISR_FDUP_MASK 0x800u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_FDUP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_FDUP_INT 0x1

/*! Field SPEED - Megabit Speed Status */
#define MAC4_PISR_SPEED_POS 12
/*! Field SPEED - Megabit Speed Status */
#define MAC4_PISR_SPEED_MASK 0x1000u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_SPEED_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_SPEED_INT 0x1

/*! Field ALIGN - Alignment Error Interrupt */
#define MAC4_PISR_ALIGN_POS 14
/*! Field ALIGN - Alignment Error Interrupt */
#define MAC4_PISR_ALIGN_MASK 0x4000u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_ALIGN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_ALIGN_INT 0x1

/*! Field PHYERR - PHY Error Interrupt */
#define MAC4_PISR_PHYERR_POS 15
/*! Field PHYERR - PHY Error Interrupt */
#define MAC4_PISR_PHYERR_MASK 0x8000u
/*! Constant NOINT - NOINT */
#define CONST_MAC4_PISR_PHYERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_MAC4_PISR_PHYERR_INT 0x1

/*! @} */

/*! \defgroup MAC4_PIER Register MAC4_PIER - MAC 4 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_PIER 0x468
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_PIER 0x18442468u

/*! Register Reset Value */
#define MAC4_PIER_RST 0x0000u

/*! Field RXPAUSE - Receive Pause Frame Interrupt Mask */
#define MAC4_PIER_RXPAUSE_POS 0
/*! Field RXPAUSE - Receive Pause Frame Interrupt Mask */
#define MAC4_PIER_RXPAUSE_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_RXPAUSE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_RXPAUSE_EN 0x1

/*! Field TXPAUSE - Transmit Pause Frame Interrupt Mask */
#define MAC4_PIER_TXPAUSE_POS 1
/*! Field TXPAUSE - Transmit Pause Frame Interrupt Mask */
#define MAC4_PIER_TXPAUSE_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_TXPAUSE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_TXPAUSE_EN 0x1

/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define MAC4_PIER_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define MAC4_PIER_FCSERR_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_FCSERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_FCSERR_EN 0x1

/*! Field LENERR - Length Mismatch Error Interrupt Mask */
#define MAC4_PIER_LENERR_POS 3
/*! Field LENERR - Length Mismatch Error Interrupt Mask */
#define MAC4_PIER_LENERR_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_LENERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_LENERR_EN 0x1

/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define MAC4_PIER_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define MAC4_PIER_TOOLONG_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_TOOLONG_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_TOOLONG_EN 0x1

/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define MAC4_PIER_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define MAC4_PIER_TOOSHORT_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_TOOSHORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_TOOSHORT_EN 0x1

/*! Field JAM - Jam Status Interrupt Mask */
#define MAC4_PIER_JAM_POS 6
/*! Field JAM - Jam Status Interrupt Mask */
#define MAC4_PIER_JAM_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_JAM_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_JAM_EN 0x1

/*! Field LPION - Low-power Idle On Interrupt Mask */
#define MAC4_PIER_LPION_POS 7
/*! Field LPION - Low-power Idle On Interrupt Mask */
#define MAC4_PIER_LPION_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_LPION_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_LPION_EN 0x1

/*! Field LPIOFF - Low-power Idle Off Interrupt Mask */
#define MAC4_PIER_LPIOFF_POS 8
/*! Field LPIOFF - Low-power Idle Off Interrupt Mask */
#define MAC4_PIER_LPIOFF_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_LPIOFF_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_LPIOFF_EN 0x1

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC4_PIER_TXPAUEN_POS 9
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define MAC4_PIER_TXPAUEN_MASK 0x200u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_TXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_TXPAUEN_EN 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC4_PIER_RXPAUEN_POS 10
/*! Field RXPAUEN - Receive Pause Enable Status */
#define MAC4_PIER_RXPAUEN_MASK 0x400u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_RXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_RXPAUEN_EN 0x1

/*! Field FDUP - Full Duplex Status */
#define MAC4_PIER_FDUP_POS 11
/*! Field FDUP - Full Duplex Status */
#define MAC4_PIER_FDUP_MASK 0x800u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_FDUP_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_FDUP_EN 0x1

/*! Field SPEED - Megabit Speed Status */
#define MAC4_PIER_SPEED_POS 12
/*! Field SPEED - Megabit Speed Status */
#define MAC4_PIER_SPEED_MASK 0x1000u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_SPEED_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_SPEED_EN 0x1

/*! Field ALIGN - Alignment Error Interrupt */
#define MAC4_PIER_ALIGN_POS 14
/*! Field ALIGN - Alignment Error Interrupt */
#define MAC4_PIER_ALIGN_MASK 0x4000u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_ALIGN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_ALIGN_EN 0x1

/*! Field PHYERR - PHY Error Interrupt */
#define MAC4_PIER_PHYERR_POS 15
/*! Field PHYERR - PHY Error Interrupt */
#define MAC4_PIER_PHYERR_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_MAC4_PIER_PHYERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_PIER_PHYERR_EN 0x1

/*! @} */

/*! \defgroup MAC4_CTRL_0 Register MAC4_CTRL_0 - MAC 4 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_CTRL_0 0x46C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_CTRL_0 0x1844246Cu

/*! Register Reset Value */
#define MAC4_CTRL_0_RST 0x0180u

/*! Field FCS - Transmit FCS Control */
#define MAC4_CTRL_0_FCS_POS 7
/*! Field FCS - Transmit FCS Control */
#define MAC4_CTRL_0_FCS_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC4_CTRL_0_FCS_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_CTRL_0_FCS_EN 0x1

/*! Field PADEN - Padding Enable */
#define MAC4_CTRL_0_PADEN_POS 8
/*! Field PADEN - Padding Enable */
#define MAC4_CTRL_0_PADEN_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC4_CTRL_0_PADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_CTRL_0_PADEN_EN 0x1

/*! @} */

/*! \defgroup MAC4_CTRL_1 Register MAC4_CTRL_1 - MAC 4 Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_CTRL_1 0x470
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_CTRL_1 0x18442470u

/*! Register Reset Value */
#define MAC4_CTRL_1_RST 0x000Cu

/*! Field IPG - Minimum Inter Packet Gap Size */
#define MAC4_CTRL_1_IPG_POS 0
/*! Field IPG - Minimum Inter Packet Gap Size */
#define MAC4_CTRL_1_IPG_MASK 0xFu

/*! Field SHORTPRE - Short Preamble Control */
#define MAC4_CTRL_1_SHORTPRE_POS 8
/*! Field SHORTPRE - Short Preamble Control */
#define MAC4_CTRL_1_SHORTPRE_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_MAC4_CTRL_1_SHORTPRE_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_CTRL_1_SHORTPRE_EN 0x1

/*! Field DEFERMODE - Defer Model */
#define MAC4_CTRL_1_DEFERMODE_POS 15
/*! Field DEFERMODE - Defer Model */
#define MAC4_CTRL_1_DEFERMODE_MASK 0x8000u
/*! Constant NORMAL - NORMAL */
#define CONST_MAC4_CTRL_1_DEFERMODE_NORMAL 0x0
/*! Constant CRS_BP - CRS_BP */
#define CONST_MAC4_CTRL_1_DEFERMODE_CRS_BP 0x1

/*! @} */

/*! \defgroup MAC4_CTRL_3 Register MAC4_CTRL_3 - MAC 4 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_CTRL_3 0x478
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_CTRL_3 0x18442478u

/*! Register Reset Value */
#define MAC4_CTRL_3_RST 0x000Fu

/*! Field RCNT - Retry Count */
#define MAC4_CTRL_3_RCNT_POS 0
/*! Field RCNT - Retry Count */
#define MAC4_CTRL_3_RCNT_MASK 0xFu

/*! @} */

/*! \defgroup MAC4_CTRL_4 Register MAC4_CTRL_4 - MAC 4 Control Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_CTRL_4 0x47C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_CTRL_4 0x1844247Cu

/*! Register Reset Value */
#define MAC4_CTRL_4_RST 0x1414u

/*! Field WAIT - LPI Wait Time for 100M */
#define MAC4_CTRL_4_WAIT_POS 0
/*! Field WAIT - LPI Wait Time for 100M */
#define MAC4_CTRL_4_WAIT_MASK 0x7Fu

/*! Field LPIEN - LPI Mode Enable */
#define MAC4_CTRL_4_LPIEN_POS 7
/*! Field LPIEN - LPI Mode Enable */
#define MAC4_CTRL_4_LPIEN_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_MAC4_CTRL_4_LPIEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_CTRL_4_LPIEN_EN 0x1

/*! Field GWAIT - LPI Wait Time for 1G */
#define MAC4_CTRL_4_GWAIT_POS 8
/*! Field GWAIT - LPI Wait Time for 1G */
#define MAC4_CTRL_4_GWAIT_MASK 0x7F00u

/*! @} */

/*! \defgroup MAC4_CTRL_5 Register MAC4_CTRL_5 - MAC 4 Control Register 5 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_CTRL_5 0x480
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_CTRL_5 0x18442480u

/*! Register Reset Value */
#define MAC4_CTRL_5_RST 0x0000u

/*! Field PJPS_BP - Prolonged Jam pattern size during backpressure state */
#define MAC4_CTRL_5_PJPS_BP_POS 0
/*! Field PJPS_BP - Prolonged Jam pattern size during backpressure state */
#define MAC4_CTRL_5_PJPS_BP_MASK 0x1u
/*! Constant SHORT - SHORT */
#define CONST_MAC4_CTRL_5_PJPS_BP_SHORT 0x0
/*! Constant LONG - LONG */
#define CONST_MAC4_CTRL_5_PJPS_BP_LONG 0x1

/*! Field PJPS_NOBP - Prolonged Jam pattern size during no-backpressure state */
#define MAC4_CTRL_5_PJPS_NOBP_POS 1
/*! Field PJPS_NOBP - Prolonged Jam pattern size during no-backpressure state */
#define MAC4_CTRL_5_PJPS_NOBP_MASK 0x2u
/*! Constant SHORT - SHORT */
#define CONST_MAC4_CTRL_5_PJPS_NOBP_SHORT 0x0
/*! Constant LONG - LONG */
#define CONST_MAC4_CTRL_5_PJPS_NOBP_LONG 0x1

/*! @} */

/*! \defgroup MAC4_LPITMER0 Register MAC4_LPITMER0 - MAC 4 LPI Timer Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_LPITMER0 0x484
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_LPITMER0 0x18442484u

/*! Register Reset Value */
#define MAC4_LPITMER0_RST 0x0000u

/*! Field TMLSB - MAC LPI Timer LSB */
#define MAC4_LPITMER0_TMLSB_POS 0
/*! Field TMLSB - MAC LPI Timer LSB */
#define MAC4_LPITMER0_TMLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_LPITMER1 Register MAC4_LPITMER1 - MAC 4 LPI Timer Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_LPITMER1 0x488
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_LPITMER1 0x18442488u

/*! Register Reset Value */
#define MAC4_LPITMER1_RST 0x0000u

/*! Field TMLSB - MAC LPI Timer MSB */
#define MAC4_LPITMER1_TMLSB_POS 0
/*! Field TMLSB - MAC LPI Timer MSB */
#define MAC4_LPITMER1_TMLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_TESTEN Register MAC4_TESTEN - MAC 4 Test Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_TESTEN 0x48C
/*! Register Offset (absolute) for 1st Instance GSWIP_LMAC */
#define GSWIP_LMAC_MAC4_TESTEN 0x1844248Cu

/*! Register Reset Value */
#define MAC4_TESTEN_RST 0x0000u

/*! Field LOOP - MAC Loopback Enable */
#define MAC4_TESTEN_LOOP_POS 0
/*! Field LOOP - MAC Loopback Enable */
#define MAC4_TESTEN_LOOP_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_MAC4_TESTEN_LOOP_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_TESTEN_LOOP_EN 0x1

/*! Field TXER - Transmit Error Insertion */
#define MAC4_TESTEN_TXER_POS 1
/*! Field TXER - Transmit Error Insertion */
#define MAC4_TESTEN_TXER_MASK 0x2u
/*! Constant NORM - NORM */
#define CONST_MAC4_TESTEN_TXER_NORM 0x0
/*! Constant TEST - TEST */
#define CONST_MAC4_TESTEN_TXER_TEST 0x1

/*! Field JTEN - Jitter Test Enable */
#define MAC4_TESTEN_JTEN_POS 2
/*! Field JTEN - Jitter Test Enable */
#define MAC4_TESTEN_JTEN_MASK 0x4u
/*! Constant NORM - NORM */
#define CONST_MAC4_TESTEN_JTEN_NORM 0x0
/*! Constant TEST - TEST */
#define CONST_MAC4_TESTEN_JTEN_TEST 0x1

/*! Field LPITM - LPI Monitoring Mode */
#define MAC4_TESTEN_LPITM_POS 8
/*! Field LPITM - LPI Monitoring Mode */
#define MAC4_TESTEN_LPITM_MASK 0x300u
/*! Constant TX - TX */
#define CONST_MAC4_TESTEN_LPITM_TX 0x0
/*! Constant RX - RX */
#define CONST_MAC4_TESTEN_LPITM_RX 0x1
/*! Constant TXRX - TXRX */
#define CONST_MAC4_TESTEN_LPITM_TXRX 0x2
/*! Constant RES - RES */
#define CONST_MAC4_TESTEN_LPITM_RES 0x3

/*! @} */

/*! @} */

#endif
