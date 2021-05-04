/* Copyright (c) 2017, Intel Corporation.
 * 
 * Legacy SPI controller header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _SPI_H
#define _SPI_H

/*! \defgroup SPI Register File SPI - Serial Peripheral Interface Register Description */
/*! @{ */

/*! Base Address of SPI0 */
#define SPI0_MODULE_BASE 0x16800000u
/*! Base Address of SPI1 */
#define SPI1_MODULE_BASE 0x16900000u

/*! \defgroup SSC_CLC Register SSC_CLC - CLC Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_CLC 0x0
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_CLC 0x16800000u

/*! Register Reset Value */
#define SSC_CLC_RST 0x00000002u

/*! Field DISR - Disable Request Bit */
#define SSC_CLC_DISR_POS 0
/*! Field DISR - Disable Request Bit */
#define SSC_CLC_DISR_MASK 0x1u
/*! Constant CLK_ON - CLK_ON */
#define CONST_SSC_CLC_DISR_CLK_ON 0x0
/*! Constant CLK_OFF - CLK_OFF */
#define CONST_SSC_CLC_DISR_CLK_OFF 0x1

/*! Field DISS - Disable Status Bit */
#define SSC_CLC_DISS_POS 1
/*! Field DISS - Disable Status Bit */
#define SSC_CLC_DISS_MASK 0x2u
/*! Constant CLK_ON - CLK_ON */
#define CONST_SSC_CLC_DISS_CLK_ON 0x0
/*! Constant CLK_OFF - CLK_OFF */
#define CONST_SSC_CLC_DISS_CLK_OFF 0x1

/*! Field SPEN - Suspend Enable Bit for OCDS */
#define SSC_CLC_SPEN_POS 2
/*! Field SPEN - Suspend Enable Bit for OCDS */
#define SSC_CLC_SPEN_MASK 0x4u
/*! Constant SUS_OFF - SUS_OFF */
#define CONST_SSC_CLC_SPEN_SUS_OFF 0x0
/*! Constant SUS_ON - SUS_ON */
#define CONST_SSC_CLC_SPEN_SUS_ON 0x1

/*! Field EDIS - External Request Disable */
#define SSC_CLC_EDIS_POS 3
/*! Field EDIS - External Request Disable */
#define SSC_CLC_EDIS_MASK 0x8u
/*! Constant SLP_ON - SLP_ON */
#define CONST_SSC_CLC_EDIS_SLP_ON 0x0
/*! Constant SLP_OFF - SLP_OFF */
#define CONST_SSC_CLC_EDIS_SLP_OFF 0x1

/*! Field SBWE - Suspend Bit Write Enable for OCDS */
#define SSC_CLC_SBWE_POS 4
/*! Field SBWE - Suspend Bit Write Enable for OCDS */
#define SSC_CLC_SBWE_MASK 0x10u
/*! Constant SPEN_PROT - SPEN_PROT */
#define CONST_SSC_CLC_SBWE_SPEN_PROT 0x0
/*! Constant SPEN_WE - SPEN_WE */
#define CONST_SSC_CLC_SBWE_SPEN_WE 0x1

/*! Field FSOE - Fast Shut-Off Enable Bit */
#define SSC_CLC_FSOE_POS 5
/*! Field FSOE - Fast Shut-Off Enable Bit */
#define SSC_CLC_FSOE_MASK 0x20u
/*! Constant SLOW_SLP - SLOW_SLP */
#define CONST_SSC_CLC_FSOE_SLOW_SLP 0x0
/*! Constant FAST_SLP - FAST_SLP */
#define CONST_SSC_CLC_FSOE_FAST_SLP 0x1

/*! Field RMC - Clock Divider for Normal Run Mode */
#define SSC_CLC_RMC_POS 8
/*! Field RMC - Clock Divider for Normal Run Mode */
#define SSC_CLC_RMC_MASK 0xFF00u

/*! Field SMC - Clock Divider for Sleep Mode */
#define SSC_CLC_SMC_POS 16
/*! Field SMC - Clock Divider for Sleep Mode */
#define SSC_CLC_SMC_MASK 0xFF0000u

/*! @} */

/*! \defgroup SSC_PISEL Register SSC_PISEL - Port Input Select Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_PISEL 0x4
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_PISEL 0x16800004u

/*! Register Reset Value */
#define SSC_PISEL_RST 0x00000000u

/*! Field MIS - Master Mode Receiver Input Select */
#define SSC_PISEL_MIS_POS 0
/*! Field MIS - Master Mode Receiver Input Select */
#define SSC_PISEL_MIS_MASK 0x1u
/*! Constant A - A */
#define CONST_SSC_PISEL_MIS_A 0x0
/*! Constant B - B */
#define CONST_SSC_PISEL_MIS_B 0x1

/*! Field SIS - Slave Mode Receiver Input Select */
#define SSC_PISEL_SIS_POS 1
/*! Field SIS - Slave Mode Receiver Input Select */
#define SSC_PISEL_SIS_MASK 0x2u
/*! Constant A - A */
#define CONST_SSC_PISEL_SIS_A 0x0
/*! Constant B - B */
#define CONST_SSC_PISEL_SIS_B 0x1

/*! Field CIS - Slave Mode Clock Input Select */
#define SSC_PISEL_CIS_POS 2
/*! Field CIS - Slave Mode Clock Input Select */
#define SSC_PISEL_CIS_MASK 0x4u
/*! Constant A - A */
#define CONST_SSC_PISEL_CIS_A 0x0
/*! Constant B - B */
#define CONST_SSC_PISEL_CIS_B 0x1

/*! Field CLK_PAD_LP_EN - Enable PAD loopback clock to internal shift logic */
#define SSC_PISEL_CLK_PAD_LP_EN_POS 3
/*! Field CLK_PAD_LP_EN - Enable PAD loopback clock to internal shift logic */
#define SSC_PISEL_CLK_PAD_LP_EN_MASK 0x8u
/*! Constant DIS - Disable loopback clock. */
#define CONST_SSC_PISEL_CLK_PAD_LP_EN_DIS 0x0
/*! Constant EN - Enable loopback clock */
#define CONST_SSC_PISEL_CLK_PAD_LP_EN_EN 0x1

/*! @} */

/*! \defgroup SSC_ID Register SSC_ID - Identification Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_ID 0x8
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_ID 0x16800008u

/*! Register Reset Value */
#define SSC_ID_RST 0x08084529u

/*! Field REV - Revision */
#define SSC_ID_REV_POS 0
/*! Field REV - Revision */
#define SSC_ID_REV_MASK 0x1Fu

/*! Field CFG - Configuration */
#define SSC_ID_CFG_POS 5
/*! Field CFG - Configuration */
#define SSC_ID_CFG_MASK 0x20u
/*! Constant NO_DMA - NO_DMA */
#define CONST_SSC_ID_CFG_NO_DMA 0x0
/*! Constant DMA - DMA */
#define CONST_SSC_ID_CFG_DMA 0x1

/*! Field ID - Module ID */
#define SSC_ID_ID_POS 8
/*! Field ID - Module ID */
#define SSC_ID_ID_MASK 0xFF00u

/*! Field RXFS - Receive FIFO Size */
#define SSC_ID_RXFS_POS 16
/*! Field RXFS - Receive FIFO Size */
#define SSC_ID_RXFS_MASK 0x3F0000u

/*! Field TXFS - Transmit FIFO Size */
#define SSC_ID_TXFS_POS 24
/*! Field TXFS - Transmit FIFO Size */
#define SSC_ID_TXFS_MASK 0x3F000000u

/*! @} */

/*! \defgroup SSC_MCON Register SSC_MCON - Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_MCON 0x10
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_MCON 0x16800010u

/*! Register Reset Value */
#define SSC_MCON_RST 0x00800000u

/*! Field TXOFF - Transmit Off */
#define SSC_MCON_TXOFF_POS 0
/*! Field TXOFF - Transmit Off */
#define SSC_MCON_TXOFF_MASK 0x1u
/*! Constant NO - NO */
#define CONST_SSC_MCON_TXOFF_NO 0x0
/*! Constant YES - YES */
#define CONST_SSC_MCON_TXOFF_YES 0x1

/*! Field RXOFF - Receive Off */
#define SSC_MCON_RXOFF_POS 1
/*! Field RXOFF - Receive Off */
#define SSC_MCON_RXOFF_MASK 0x2u
/*! Constant NO - NO */
#define CONST_SSC_MCON_RXOFF_NO 0x0
/*! Constant YES - YES */
#define CONST_SSC_MCON_RXOFF_YES 0x1

/*! Field CSBINV - Chip Select Invert */
#define SSC_MCON_CSBINV_POS 2
/*! Field CSBINV - Chip Select Invert */
#define SSC_MCON_CSBINV_MASK 0x4u
/*! Constant CS_LOW - CS_LOW */
#define CONST_SSC_MCON_CSBINV_CS_LOW 0x0
/*! Constant CS_HIGH - CS_HIGH */
#define CONST_SSC_MCON_CSBINV_CS_HIGH 0x1

/*! Field CSBEN - Chip Select Enable */
#define SSC_MCON_CSBEN_POS 3
/*! Field CSBEN - Chip Select Enable */
#define SSC_MCON_CSBEN_MASK 0x8u
/*! Constant OFF - OFF */
#define CONST_SSC_MCON_CSBEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_MCON_CSBEN_ON 0x1

/*! Field HB - Heading Control */
#define SSC_MCON_HB_POS 4
/*! Field HB - Heading Control */
#define SSC_MCON_HB_MASK 0x10u
/*! Constant LSB_1ST - LSB_1ST */
#define CONST_SSC_MCON_HB_LSB_1ST 0x0
/*! Constant MSB_1ST - MSB_1ST */
#define CONST_SSC_MCON_HB_MSB_1ST 0x1

/*! Field PH - Clock Phase Control */
#define SSC_MCON_PH_POS 5
/*! Field PH - Clock Phase Control */
#define SSC_MCON_PH_MASK 0x20u
/*! Constant SHFT_1ST - SHFT_1ST */
#define CONST_SSC_MCON_PH_SHFT_1ST 0x0
/*! Constant CAPT_1ST - CAPT_1ST */
#define CONST_SSC_MCON_PH_CAPT_1ST 0x1

/*! Field PO - Clock Polarity Control */
#define SSC_MCON_PO_POS 6
/*! Field PO - Clock Polarity Control */
#define SSC_MCON_PO_MASK 0x40u
/*! Constant IDLE_LOW - IDLE_LOW */
#define CONST_SSC_MCON_PO_IDLE_LOW 0x0
/*! Constant IDLE_HIGH - IDLE_HIGH */
#define CONST_SSC_MCON_PO_IDLE_HIGH 0x1

/*! Field LB - Loop Back Control */
#define SSC_MCON_LB_POS 7
/*! Field LB - Loop Back Control */
#define SSC_MCON_LB_MASK 0x80u
/*! Constant OFF - OFF */
#define CONST_SSC_MCON_LB_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_MCON_LB_ON 0x1

/*! Field TEN - Transmit Overflow Error Enable */
#define SSC_MCON_TEN_POS 8
/*! Field TEN - Transmit Overflow Error Enable */
#define SSC_MCON_TEN_MASK 0x100u
/*! Constant OFF - OFF */
#define CONST_SSC_MCON_TEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_MCON_TEN_ON 0x1

/*! Field REN - Receive Overflow Error Enable */
#define SSC_MCON_REN_POS 9
/*! Field REN - Receive Overflow Error Enable */
#define SSC_MCON_REN_MASK 0x200u
/*! Constant OFF - OFF */
#define CONST_SSC_MCON_REN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_MCON_REN_ON 0x1

/*! Field AEN - Abort Error Enable */
#define SSC_MCON_AEN_POS 10
/*! Field AEN - Abort Error Enable */
#define SSC_MCON_AEN_MASK 0x400u
/*! Constant OFF - OFF */
#define CONST_SSC_MCON_AEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_MCON_AEN_ON 0x1

/*! Field TUEN - Transmit Underflow Error Enable */
#define SSC_MCON_TUEN_POS 11
/*! Field TUEN - Transmit Underflow Error Enable */
#define SSC_MCON_TUEN_MASK 0x800u
/*! Constant OFF - OFF */
#define CONST_SSC_MCON_TUEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_MCON_TUEN_ON 0x1

/*! Field RUEN - Receive Underflow Error Enable */
#define SSC_MCON_RUEN_POS 12
/*! Field RUEN - Receive Underflow Error Enable */
#define SSC_MCON_RUEN_MASK 0x1000u
/*! Constant OFF - OFF */
#define CONST_SSC_MCON_RUEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_MCON_RUEN_ON 0x1

/*! Field BM - Data Width Selection */
#define SSC_MCON_BM_POS 16
/*! Field BM - Data Width Selection */
#define SSC_MCON_BM_MASK 0x1F0000u
/*! Constant DW2 - DW2 */
#define CONST_SSC_MCON_BM_DW2 0x1
/*! Constant DW3 - DW3 */
#define CONST_SSC_MCON_BM_DW3 0x2
/*! Constant DW4 - DW4 */
#define CONST_SSC_MCON_BM_DW4 0x3
/*! Constant DW5 - DW5 */
#define CONST_SSC_MCON_BM_DW5 0x4
/*! Constant DW6 - DW6 */
#define CONST_SSC_MCON_BM_DW6 0x5
/*! Constant DW7 - DW7 */
#define CONST_SSC_MCON_BM_DW7 0x6
/*! Constant DW8 - DW8 */
#define CONST_SSC_MCON_BM_DW8 0x7
/*! Constant DW16 - DW16 */
#define CONST_SSC_MCON_BM_DW16 0xF
/*! Constant DW24 - DW24 */
#define CONST_SSC_MCON_BM_DW24 0x17
/*! Constant DW32 - DW32 */
#define CONST_SSC_MCON_BM_DW32 0x1F

/*! Field ENBV - Enable Byte Valid Control */
#define SSC_MCON_ENBV_POS 22
/*! Field ENBV - Enable Byte Valid Control */
#define SSC_MCON_ENBV_MASK 0x400000u
/*! Constant BV_OFF - BV_OFF */
#define CONST_SSC_MCON_ENBV_BV_OFF 0x0
/*! Constant BV_ON - BV_ON */
#define CONST_SSC_MCON_ENBV_BV_ON 0x1

/*! Field IDLE - Idle Bit Value */
#define SSC_MCON_IDLE_POS 23
/*! Field IDLE - Idle Bit Value */
#define SSC_MCON_IDLE_MASK 0x800000u
/*! Constant LOW - LOW */
#define CONST_SSC_MCON_IDLE_LOW 0x0
/*! Constant HIGH - HIGH */
#define CONST_SSC_MCON_IDLE_HIGH 0x1

/*! Field EM - Echo Mode */
#define SSC_MCON_EM_POS 24
/*! Field EM - Echo Mode */
#define SSC_MCON_EM_MASK 0x1000000u
/*! Constant ECHO_OFF - ECHO_OFF */
#define CONST_SSC_MCON_EM_ECHO_OFF 0x0
/*! Constant ECHO_ON - ECHO_ON */
#define CONST_SSC_MCON_EM_ECHO_ON 0x1

/*! Field TX_SWP - TX Byte Swap */
#define SSC_MCON_TX_SWP_POS 25
/*! Field TX_SWP - TX Byte Swap */
#define SSC_MCON_TX_SWP_MASK 0x2000000u
/*! Constant SWP_OFF - SWP_OFF */
#define CONST_SSC_MCON_TX_SWP_SWP_OFF 0x0
/*! Constant SWP_ON - SWP_ON */
#define CONST_SSC_MCON_TX_SWP_SWP_ON 0x1

/*! Field RX_SWP - RX Byte Swap */
#define SSC_MCON_RX_SWP_POS 26
/*! Field RX_SWP - RX Byte Swap */
#define SSC_MCON_RX_SWP_MASK 0x4000000u
/*! Constant SWP_OFF - SWP_OFF */
#define CONST_SSC_MCON_RX_SWP_SWP_OFF 0x0
/*! Constant SWP_ON - SWP_ON */
#define CONST_SSC_MCON_RX_SWP_SWP_ON 0x1

/*! Field LTCLKDEL - Latch Clock Delay */
#define SSC_MCON_LTCLKDEL_POS 28
/*! Field LTCLKDEL - Latch Clock Delay */
#define SSC_MCON_LTCLKDEL_MASK 0xF0000000u
/*! Constant DEL0 - DEL0 */
#define CONST_SSC_MCON_LTCLKDEL_DEL0 0x0
/*! Constant DEL0_5 - DEL0_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL0_5 0x1
/*! Constant DEL1 - DEL1 */
#define CONST_SSC_MCON_LTCLKDEL_DEL1 0x2
/*! Constant DEL1_5 - DEL1_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL1_5 0x3
/*! Constant DEL2 - DEL2 */
#define CONST_SSC_MCON_LTCLKDEL_DEL2 0x4
/*! Constant DEL2_5 - DEL2_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL2_5 0x5
/*! Constant DEL3 - DEL3 */
#define CONST_SSC_MCON_LTCLKDEL_DEL3 0x6
/*! Constant DEL3_5 - DEL3_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL3_5 0x7
/*! Constant DEL4 - DEL4 */
#define CONST_SSC_MCON_LTCLKDEL_DEL4 0x8
/*! Constant DEL4_5 - DEL4_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL4_5 0x9
/*! Constant DEL5 - DEL5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL5 0xA
/*! Constant DEL5_5 - DEL5_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL5_5 0xB
/*! Constant DEL6 - DEL6 */
#define CONST_SSC_MCON_LTCLKDEL_DEL6 0xC
/*! Constant DEL6_5 - DEL6_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL6_5 0xD
/*! Constant DEL7 - DEL7 */
#define CONST_SSC_MCON_LTCLKDEL_DEL7 0xE
/*! Constant DEL7_5 - DEL7_5 */
#define CONST_SSC_MCON_LTCLKDEL_DEL7_5 0xF

/*! @} */

/*! \defgroup SSC_STATE Register SSC_STATE - State Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_STATE 0x14
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_STATE 0x16800014u

/*! Register Reset Value */
#define SSC_STATE_RST 0x00000004u

/*! Field EN - Enable Bit */
#define SSC_STATE_EN_POS 0
/*! Field EN - Enable Bit */
#define SSC_STATE_EN_MASK 0x1u
/*! Constant OFF - OFF */
#define CONST_SSC_STATE_EN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_STATE_EN_ON 0x1

/*! Field MS - Master Select Bit */
#define SSC_STATE_MS_POS 1
/*! Field MS - Master Select Bit */
#define SSC_STATE_MS_MASK 0x2u
/*! Constant SLAVE - SLAVE */
#define CONST_SSC_STATE_MS_SLAVE 0x0
/*! Constant MASTER - MASTER */
#define CONST_SSC_STATE_MS_MASTER 0x1

/*! Field SSEL - Slave Selected */
#define SSC_STATE_SSEL_POS 2
/*! Field SSEL - Slave Selected */
#define SSC_STATE_SSEL_MASK 0x4u
/*! Constant UNSEL - UNSEL */
#define CONST_SSC_STATE_SSEL_UNSEL 0x0
/*! Constant SELECT - SELECT */
#define CONST_SSC_STATE_SSEL_SELECT 0x1

/*! Field ME - Mode Error Flag */
#define SSC_STATE_ME_POS 7
/*! Field ME - Mode Error Flag */
#define SSC_STATE_ME_MASK 0x80u
/*! Constant OK - OK */
#define CONST_SSC_STATE_ME_OK 0x0
/*! Constant FAIL - FAIL */
#define CONST_SSC_STATE_ME_FAIL 0x1

/*! Field TE - Transmit Error Flag */
#define SSC_STATE_TE_POS 8
/*! Field TE - Transmit Error Flag */
#define SSC_STATE_TE_MASK 0x100u
/*! Constant OK - OK */
#define CONST_SSC_STATE_TE_OK 0x0
/*! Constant FAIL - FAIL */
#define CONST_SSC_STATE_TE_FAIL 0x1

/*! Field RE - Receive Error Flag */
#define SSC_STATE_RE_POS 9
/*! Field RE - Receive Error Flag */
#define SSC_STATE_RE_MASK 0x200u
/*! Constant OK - OK */
#define CONST_SSC_STATE_RE_OK 0x0
/*! Constant FAIL - FAIL */
#define CONST_SSC_STATE_RE_FAIL 0x1

/*! Field AE - Abort Error Flag */
#define SSC_STATE_AE_POS 10
/*! Field AE - Abort Error Flag */
#define SSC_STATE_AE_MASK 0x400u
/*! Constant OK - OK */
#define CONST_SSC_STATE_AE_OK 0x0
/*! Constant FAIL - FAIL */
#define CONST_SSC_STATE_AE_FAIL 0x1

/*! Field TUE - Transmit Underflow Error Flag */
#define SSC_STATE_TUE_POS 11
/*! Field TUE - Transmit Underflow Error Flag */
#define SSC_STATE_TUE_MASK 0x800u
/*! Constant OK - OK */
#define CONST_SSC_STATE_TUE_OK 0x0
/*! Constant FAIL - FAIL */
#define CONST_SSC_STATE_TUE_FAIL 0x1

/*! Field RUE - Receive Underflow Error Flag */
#define SSC_STATE_RUE_POS 12
/*! Field RUE - Receive Underflow Error Flag */
#define SSC_STATE_RUE_MASK 0x1000u
/*! Constant OK - OK */
#define CONST_SSC_STATE_RUE_OK 0x0
/*! Constant FAIL - FAIL */
#define CONST_SSC_STATE_RUE_FAIL 0x1

/*! Field BSY - Busy Flag */
#define SSC_STATE_BSY_POS 13
/*! Field BSY - Busy Flag */
#define SSC_STATE_BSY_MASK 0x2000u

/*! Field BC - Bit Count Field */
#define SSC_STATE_BC_POS 16
/*! Field BC - Bit Count Field */
#define SSC_STATE_BC_MASK 0x1F0000u

/*! Field TXBV - Transmit Byte Valid */
#define SSC_STATE_TXBV_POS 24
/*! Field TXBV - Transmit Byte Valid */
#define SSC_STATE_TXBV_MASK 0x7000000u

/*! Field TXEOM - Transmit End-of-Message */
#define SSC_STATE_TXEOM_POS 27
/*! Field TXEOM - Transmit End-of-Message */
#define SSC_STATE_TXEOM_MASK 0x8000000u

/*! Field RXBV - Receive Byte Valid */
#define SSC_STATE_RXBV_POS 28
/*! Field RXBV - Receive Byte Valid */
#define SSC_STATE_RXBV_MASK 0x70000000u

/*! Field RXEOM - Receive End-of-Message */
#define SSC_STATE_RXEOM_POS 31
/*! Field RXEOM - Receive End-of-Message */
#define SSC_STATE_RXEOM_MASK 0x80000000u

/*! @} */

/*! \defgroup SSC_WHBSTATE Register SSC_WHBSTATE - Write Hardware Modified State Register Bits */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_WHBSTATE 0x18
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_WHBSTATE 0x16800018u

/*! Register Reset Value */
#define SSC_WHBSTATE_RST 0x00000000u

/*! Field CLREN - Clear Enable Bit */
#define SSC_WHBSTATE_CLREN_POS 0
/*! Field CLREN - Clear Enable Bit */
#define SSC_WHBSTATE_CLREN_MASK 0x1u

/*! Field SETEN - Set Enable Bit */
#define SSC_WHBSTATE_SETEN_POS 1
/*! Field SETEN - Set Enable Bit */
#define SSC_WHBSTATE_SETEN_MASK 0x2u

/*! Field CLRMS - Clear Master Select Bit */
#define SSC_WHBSTATE_CLRMS_POS 2
/*! Field CLRMS - Clear Master Select Bit */
#define SSC_WHBSTATE_CLRMS_MASK 0x4u

/*! Field SETMS - Set Master Select Bit */
#define SSC_WHBSTATE_SETMS_POS 3
/*! Field SETMS - Set Master Select Bit */
#define SSC_WHBSTATE_SETMS_MASK 0x8u

/*! Field CLRRUE - Clear Receive Underflow Error Bit */
#define SSC_WHBSTATE_CLRRUE_POS 4
/*! Field CLRRUE - Clear Receive Underflow Error Bit */
#define SSC_WHBSTATE_CLRRUE_MASK 0x10u

/*! Field SETRUE - Set Receive Underflow Error Bit */
#define SSC_WHBSTATE_SETRUE_POS 5
/*! Field SETRUE - Set Receive Underflow Error Bit */
#define SSC_WHBSTATE_SETRUE_MASK 0x20u

/*! Field CLRME - Clear Mode Error Flag Bit */
#define SSC_WHBSTATE_CLRME_POS 6
/*! Field CLRME - Clear Mode Error Flag Bit */
#define SSC_WHBSTATE_CLRME_MASK 0x40u

/*! Field SETME - Set Mode Error Flag Bit */
#define SSC_WHBSTATE_SETME_POS 7
/*! Field SETME - Set Mode Error Flag Bit */
#define SSC_WHBSTATE_SETME_MASK 0x80u

/*! Field CLRTE - Clear Transmit Error Flag Bit */
#define SSC_WHBSTATE_CLRTE_POS 8
/*! Field CLRTE - Clear Transmit Error Flag Bit */
#define SSC_WHBSTATE_CLRTE_MASK 0x100u

/*! Field CLRRE - Clear Receive Error Flag Bit */
#define SSC_WHBSTATE_CLRRE_POS 9
/*! Field CLRRE - Clear Receive Error Flag Bit */
#define SSC_WHBSTATE_CLRRE_MASK 0x200u

/*! Field CLRAE - Clear Abort Error Flag Bit */
#define SSC_WHBSTATE_CLRAE_POS 10
/*! Field CLRAE - Clear Abort Error Flag Bit */
#define SSC_WHBSTATE_CLRAE_MASK 0x400u

/*! Field CLRTUE - Clear Transmit Underflow Error Flag Bit */
#define SSC_WHBSTATE_CLRTUE_POS 11
/*! Field CLRTUE - Clear Transmit Underflow Error Flag Bit */
#define SSC_WHBSTATE_CLRTUE_MASK 0x800u

/*! Field SETTE - Set Transmit Error Flag Bit */
#define SSC_WHBSTATE_SETTE_POS 12
/*! Field SETTE - Set Transmit Error Flag Bit */
#define SSC_WHBSTATE_SETTE_MASK 0x1000u

/*! Field SETRE - Set Receive Error Flag Bit */
#define SSC_WHBSTATE_SETRE_POS 13
/*! Field SETRE - Set Receive Error Flag Bit */
#define SSC_WHBSTATE_SETRE_MASK 0x2000u

/*! Field SETAE - Set Abort Error Flag Bit */
#define SSC_WHBSTATE_SETAE_POS 14
/*! Field SETAE - Set Abort Error Flag Bit */
#define SSC_WHBSTATE_SETAE_MASK 0x4000u

/*! Field SETTUE - Set Transmit Underflow Error Flag Bit */
#define SSC_WHBSTATE_SETTUE_POS 15
/*! Field SETTUE - Set Transmit Underflow Error Flag Bit */
#define SSC_WHBSTATE_SETTUE_MASK 0x8000u

/*! @} */

/*! \defgroup SSC_TB Register SSC_TB - Transmitter Buffer Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_TB 0x20
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_TB 0x16800020u

/*! Register Reset Value */
#define SSC_TB_RST 0x00000000u

/*! Field TB_VAL - Transmit Data Register Value */
#define SSC_TB_TB_VAL_POS 0
/*! Field TB_VAL - Transmit Data Register Value */
#define SSC_TB_TB_VAL_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup SSC_RB Register SSC_RB - Receiver Buffer Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_RB 0x24
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_RB 0x16800024u

/*! Register Reset Value */
#define SSC_RB_RST 0x00000000u

/*! Field RB_VAL - Receive Data Register Value */
#define SSC_RB_RB_VAL_POS 0
/*! Field RB_VAL - Receive Data Register Value */
#define SSC_RB_RB_VAL_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup SSC_RXFCON Register SSC_RXFCON - Receive FIFO Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_RXFCON 0x30
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_RXFCON 0x16800030u

/*! Register Reset Value */
#define SSC_RXFCON_RST 0x00000100u

/*! Field RXFEN - Receive FIFO Enable */
#define SSC_RXFCON_RXFEN_POS 0
/*! Field RXFEN - Receive FIFO Enable */
#define SSC_RXFCON_RXFEN_MASK 0x1u
/*! Constant OFF - OFF */
#define CONST_SSC_RXFCON_RXFEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_RXFCON_RXFEN_ON 0x1

/*! Field RXFLU - Receive FIFO Flush */
#define SSC_RXFCON_RXFLU_POS 1
/*! Field RXFLU - Receive FIFO Flush */
#define SSC_RXFCON_RXFLU_MASK 0x2u
/*! Constant KEEP - KEEP */
#define CONST_SSC_RXFCON_RXFLU_KEEP 0x0
/*! Constant CLEAR - CLEAR */
#define CONST_SSC_RXFCON_RXFLU_CLEAR 0x1

/*! Field RXFITL - Receive FIFO Interrupt Trigger Level */
#define SSC_RXFCON_RXFITL_POS 8
/*! Field RXFITL - Receive FIFO Interrupt Trigger Level */
#define SSC_RXFCON_RXFITL_MASK 0x700u

/*! @} */

/*! \defgroup SSC_TXFCON Register SSC_TXFCON - Transmit FIFO Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_TXFCON 0x34
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_TXFCON 0x16800034u

/*! Register Reset Value */
#define SSC_TXFCON_RST 0x00000100u

/*! Field TXFEN - Transmit FIFO Enable */
#define SSC_TXFCON_TXFEN_POS 0
/*! Field TXFEN - Transmit FIFO Enable */
#define SSC_TXFCON_TXFEN_MASK 0x1u
/*! Constant OFF - OFF */
#define CONST_SSC_TXFCON_TXFEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_TXFCON_TXFEN_ON 0x1

/*! Field TXFLU - Transmit FIFO Flush */
#define SSC_TXFCON_TXFLU_POS 1
/*! Field TXFLU - Transmit FIFO Flush */
#define SSC_TXFCON_TXFLU_MASK 0x2u
/*! Constant KEEP - KEEP */
#define CONST_SSC_TXFCON_TXFLU_KEEP 0x0
/*! Constant CLEAR - CLEAR */
#define CONST_SSC_TXFCON_TXFLU_CLEAR 0x1

/*! Field TXFITL - Transmit FIFO Interrupt Trigger Level */
#define SSC_TXFCON_TXFITL_POS 8
/*! Field TXFITL - Transmit FIFO Interrupt Trigger Level */
#define SSC_TXFCON_TXFITL_MASK 0x700u

/*! @} */

/*! \defgroup SSC_FSTAT Register SSC_FSTAT - FIFO Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_FSTAT 0x38
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_FSTAT 0x16800038u

/*! Register Reset Value */
#define SSC_FSTAT_RST 0x00000000u

/*! Field RXFFL - Receive FIFO Filling Level */
#define SSC_FSTAT_RXFFL_POS 0
/*! Field RXFFL - Receive FIFO Filling Level */
#define SSC_FSTAT_RXFFL_MASK 0x3Fu

/*! Field TXFFL - Transmit FIFO Filling Level */
#define SSC_FSTAT_TXFFL_POS 8
/*! Field TXFFL - Transmit FIFO Filling Level */
#define SSC_FSTAT_TXFFL_MASK 0x3F00u

/*! @} */

/*! \defgroup SSC_BR Register SSC_BR - Baudrate Timer Reload Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_BR 0x40
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_BR 0x16800040u

/*! Register Reset Value */
#define SSC_BR_RST 0x00000000u

/*! Field BR_VAL - Baudrate Timer Reload Register Value */
#define SSC_BR_BR_VAL_POS 0
/*! Field BR_VAL - Baudrate Timer Reload Register Value */
#define SSC_BR_BR_VAL_MASK 0xFFFFu

/*! @} */

/*! \defgroup SSC_BRSTAT Register SSC_BRSTAT - Baudrate Timer Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_BRSTAT 0x44
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_BRSTAT 0x16800044u

/*! Register Reset Value */
#define SSC_BRSTAT_RST 0x00000000u

/*! Field BT_VAL - Baudrate Timer Register Value */
#define SSC_BRSTAT_BT_VAL_POS 0
/*! Field BT_VAL - Baudrate Timer Register Value */
#define SSC_BRSTAT_BT_VAL_MASK 0xFFFFu

/*! @} */

/*! \defgroup SSC_SFCON Register SSC_SFCON - Serial Frame Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_SFCON 0x60
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_SFCON 0x16800060u

/*! Register Reset Value */
#define SSC_SFCON_RST 0x00000000u

/*! Field SFEN - Serial Frame Enable */
#define SSC_SFCON_SFEN_POS 0
/*! Field SFEN - Serial Frame Enable */
#define SSC_SFCON_SFEN_MASK 0x1u
/*! Constant OFF - OFF */
#define CONST_SSC_SFCON_SFEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_SFCON_SFEN_ON 0x1

/*! Field IBEN - Enable Interrupt Before Pause */
#define SSC_SFCON_IBEN_POS 2
/*! Field IBEN - Enable Interrupt Before Pause */
#define SSC_SFCON_IBEN_MASK 0x4u
/*! Constant OFF - OFF */
#define CONST_SSC_SFCON_IBEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_SFCON_IBEN_ON 0x1

/*! Field IAEN - Enable Interrupt After Pause */
#define SSC_SFCON_IAEN_POS 3
/*! Field IAEN - Enable Interrupt After Pause */
#define SSC_SFCON_IAEN_MASK 0x8u
/*! Constant OFF - OFF */
#define CONST_SSC_SFCON_IAEN_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_SFCON_IAEN_ON 0x1

/*! Field DLEN - Data Length */
#define SSC_SFCON_DLEN_POS 4
/*! Field DLEN - Data Length */
#define SSC_SFCON_DLEN_MASK 0xFFF0u

/*! Field IDAT - Idle Data Configuration */
#define SSC_SFCON_IDAT_POS 16
/*! Field IDAT - Idle Data Configuration */
#define SSC_SFCON_IDAT_MASK 0x30000u
/*! Constant LOW - LOW */
#define CONST_SSC_SFCON_IDAT_LOW 0x0
/*! Constant HIGH - HIGH */
#define CONST_SSC_SFCON_IDAT_HIGH 0x1
/*! Constant AUTO - AUTO */
#define CONST_SSC_SFCON_IDAT_AUTO 0x2
/*! Constant RES - Res */
#define CONST_SSC_SFCON_IDAT_RES 0x3

/*! Field ICLK - Idle Clock Configuration */
#define SSC_SFCON_ICLK_POS 18
/*! Field ICLK - Idle Clock Configuration */
#define SSC_SFCON_ICLK_MASK 0xC0000u
/*! Constant LOW - LOW */
#define CONST_SSC_SFCON_ICLK_LOW 0x0
/*! Constant HIGH - HIGH */
#define CONST_SSC_SFCON_ICLK_HIGH 0x1
/*! Constant AUTO - AUTO */
#define CONST_SSC_SFCON_ICLK_AUTO 0x2
/*! Constant RUN - RUN */
#define CONST_SSC_SFCON_ICLK_RUN 0x3

/*! Field STOP - Stop After Pause */
#define SSC_SFCON_STOP_POS 20
/*! Field STOP - Stop After Pause */
#define SSC_SFCON_STOP_MASK 0x100000u
/*! Constant OFF - OFF */
#define CONST_SSC_SFCON_STOP_OFF 0x0
/*! Constant ON - ON */
#define CONST_SSC_SFCON_STOP_ON 0x1

/*! Field PLEN - Pause Length */
#define SSC_SFCON_PLEN_POS 22
/*! Field PLEN - Pause Length */
#define SSC_SFCON_PLEN_MASK 0xFFC00000u

/*! @} */

/*! \defgroup SSC_SFSTAT Register SSC_SFSTAT - Serial Frame Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_SFSTAT 0x64
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_SFSTAT 0x16800064u

/*! Register Reset Value */
#define SSC_SFSTAT_RST 0x00000000u

/*! Field DBSY - Data Busy */
#define SSC_SFSTAT_DBSY_POS 0
/*! Field DBSY - Data Busy */
#define SSC_SFSTAT_DBSY_MASK 0x1u
/*! Constant NO - NO */
#define CONST_SSC_SFSTAT_DBSY_NO 0x0
/*! Constant YES - YES */
#define CONST_SSC_SFSTAT_DBSY_YES 0x1

/*! Field PBSY - Pause Busy */
#define SSC_SFSTAT_PBSY_POS 1
/*! Field PBSY - Pause Busy */
#define SSC_SFSTAT_PBSY_MASK 0x2u
/*! Constant NO - NO */
#define CONST_SSC_SFSTAT_PBSY_NO 0x0
/*! Constant YES - YES */
#define CONST_SSC_SFSTAT_PBSY_YES 0x1

/*! Field DCNT - Data Bit Count */
#define SSC_SFSTAT_DCNT_POS 4
/*! Field DCNT - Data Bit Count */
#define SSC_SFSTAT_DCNT_MASK 0xFFF0u

/*! Field PCNT - Pause Count */
#define SSC_SFSTAT_PCNT_POS 22
/*! Field PCNT - Pause Count */
#define SSC_SFSTAT_PCNT_MASK 0xFFC00000u

/*! @} */

/*! \defgroup SSC_GPOCON Register SSC_GPOCON - General Purpose Output Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_GPOCON 0x70
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_GPOCON 0x16800070u

/*! Register Reset Value */
#define SSC_GPOCON_RST 0x00000000u

/*! Field INVOUTN - Invert Output OUTn */
#define SSC_GPOCON_INVOUTN_POS 0
/*! Field INVOUTN - Invert Output OUTn */
#define SSC_GPOCON_INVOUTN_MASK 0xFFu
/*! Constant NO - NO */
#define CONST_SSC_GPOCON_INVOUTN_NO 0x00u
/*! Constant YES - YES */
#define CONST_SSC_GPOCON_INVOUTN_YES 0x01u

/*! Field ISCSBN - Output OUTn Is Chip Select */
#define SSC_GPOCON_ISCSBN_POS 8
/*! Field ISCSBN - Output OUTn Is Chip Select */
#define SSC_GPOCON_ISCSBN_MASK 0xFF00u
/*! Constant NO - NO */
#define CONST_SSC_GPOCON_ISCSBN_NO 0x00u
/*! Constant YES - YES */
#define CONST_SSC_GPOCON_ISCSBN_YES 0x01u

/*! @} */

/*! \defgroup SSC_GPOSTAT Register SSC_GPOSTAT - General Purpose Output Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_GPOSTAT 0x74
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_GPOSTAT 0x16800074u

/*! Register Reset Value */
#define SSC_GPOSTAT_RST 0x00000000u

/*! Field OUTN - Output Register Bit n */
#define SSC_GPOSTAT_OUTN_POS 0
/*! Field OUTN - Output Register Bit n */
#define SSC_GPOSTAT_OUTN_MASK 0xFFu

/*! @} */

/*! \defgroup SSC_WHBGPOSTAT Register SSC_WHBGPOSTAT - Force General Purpose Output Register Bits */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_WHBGPOSTAT 0x78
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_WHBGPOSTAT 0x16800078u

/*! Register Reset Value */
#define SSC_WHBGPOSTAT_RST 0x00000000u

/*! Field CLROUTN - Clear Output Register Bit n */
#define SSC_WHBGPOSTAT_CLROUTN_POS 0
/*! Field CLROUTN - Clear Output Register Bit n */
#define SSC_WHBGPOSTAT_CLROUTN_MASK 0xFFu

/*! Field SETOUTN - Set Output Register Bit n */
#define SSC_WHBGPOSTAT_SETOUTN_POS 8
/*! Field SETOUTN - Set Output Register Bit n */
#define SSC_WHBGPOSTAT_SETOUTN_MASK 0xFF00u

/*! @} */

/*! \defgroup SSC_RXREQ Register SSC_RXREQ - Receive Request Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_RXREQ 0x80
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_RXREQ 0x16800080u

/*! Register Reset Value */
#define SSC_RXREQ_RST 0x00000000u

/*! Field RXCNT - Receive Count Value */
#define SSC_RXREQ_RXCNT_POS 0
/*! Field RXCNT - Receive Count Value */
#define SSC_RXREQ_RXCNT_MASK 0xFFFFu

/*! @} */

/*! \defgroup SSC_RXCNT Register SSC_RXCNT - Receive Count Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_RXCNT 0x84
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_RXCNT 0x16800084u

/*! Register Reset Value */
#define SSC_RXCNT_RST 0x00000000u

/*! Field TODO - Receive To Do Value */
#define SSC_RXCNT_TODO_POS 1
/*! Field TODO - Receive To Do Value */
#define SSC_RXCNT_TODO_MASK 0xFFFEu

/*! @} */

/*! \defgroup SSC_DMA_CON Register SSC_DMA_CON - DMA Interface Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_DMA_CON 0xEC
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_DMA_CON 0x168000ECu

/*! Register Reset Value */
#define SSC_DMA_CON_RST 0x00000000u

/*! Field RXON - Receive Path On */
#define SSC_DMA_CON_RXON_POS 0
/*! Field RXON - Receive Path On */
#define SSC_DMA_CON_RXON_MASK 0x1u
/*! Constant NO_DMA - NO_DMA */
#define CONST_SSC_DMA_CON_RXON_NO_DMA 0x0
/*! Constant DMA - DMA */
#define CONST_SSC_DMA_CON_RXON_DMA 0x1

/*! Field TXON - Transmit Path On */
#define SSC_DMA_CON_TXON_POS 1
/*! Field TXON - Transmit Path On */
#define SSC_DMA_CON_TXON_MASK 0x2u
/*! Constant NO_DMA - NO_DMA */
#define CONST_SSC_DMA_CON_TXON_NO_DMA 0x0
/*! Constant DMA - DMA */
#define CONST_SSC_DMA_CON_TXON_DMA 0x1

/*! Field RXCLS - Receive Class */
#define SSC_DMA_CON_RXCLS_POS 2
/*! Field RXCLS - Receive Class */
#define SSC_DMA_CON_RXCLS_MASK 0xCu

/*! @} */

/*! \defgroup SSC_IRNEN Register SSC_IRNEN - Interrupt Node Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_IRNEN 0xF4
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_IRNEN 0x168000F4u

/*! Register Reset Value */
#define SSC_IRNEN_RST 0x00000000u

/*! Field T - Transmit Interrupt Request Enable */
#define SSC_IRNEN_T_POS 0
/*! Field T - Transmit Interrupt Request Enable */
#define SSC_IRNEN_T_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SSC_IRNEN_T_DIS 0x0
/*! Constant EN - EN */
#define CONST_SSC_IRNEN_T_EN 0x1

/*! Field R - Receive Interrupt Request Enable */
#define SSC_IRNEN_R_POS 1
/*! Field R - Receive Interrupt Request Enable */
#define SSC_IRNEN_R_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SSC_IRNEN_R_DIS 0x0
/*! Constant EN - EN */
#define CONST_SSC_IRNEN_R_EN 0x1

/*! Field E - Error Interrupt Request Enable */
#define SSC_IRNEN_E_POS 2
/*! Field E - Error Interrupt Request Enable */
#define SSC_IRNEN_E_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SSC_IRNEN_E_DIS 0x0
/*! Constant EN - EN */
#define CONST_SSC_IRNEN_E_EN 0x1

/*! Field F - Frame End Interrupt Request Enable */
#define SSC_IRNEN_F_POS 3
/*! Field F - Frame End Interrupt Request Enable */
#define SSC_IRNEN_F_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_SSC_IRNEN_F_DIS 0x0
/*! Constant EN - EN */
#define CONST_SSC_IRNEN_F_EN 0x1

/*! Field TFI - TX Finished Interrupt Enable */
#define SSC_IRNEN_TFI_POS 4
/*! Field TFI - TX Finished Interrupt Enable */
#define SSC_IRNEN_TFI_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_SSC_IRNEN_TFI_DIS 0x0
/*! Constant EN - EN */
#define CONST_SSC_IRNEN_TFI_EN 0x1

/*! @} */

/*! \defgroup SSC_IRNCR Register SSC_IRNCR - Interrupt Node Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_IRNCR 0xF8
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_IRNCR 0x168000F8u

/*! Register Reset Value */
#define SSC_IRNCR_RST 0x00000000u

/*! Field T - Transmit Interrupt Request */
#define SSC_IRNCR_T_POS 0
/*! Field T - Transmit Interrupt Request */
#define SSC_IRNCR_T_MASK 0x1u

/*! Field R - Receive Interrupt Request */
#define SSC_IRNCR_R_POS 1
/*! Field R - Receive Interrupt Request */
#define SSC_IRNCR_R_MASK 0x2u

/*! Field E - Error Interrupt Request */
#define SSC_IRNCR_E_POS 2
/*! Field E - Error Interrupt Request */
#define SSC_IRNCR_E_MASK 0x4u

/*! Field F - Frame End Interrupt Request */
#define SSC_IRNCR_F_POS 3
/*! Field F - Frame End Interrupt Request */
#define SSC_IRNCR_F_MASK 0x8u

/*! Field TFI - TX Finished Interrupt Request */
#define SSC_IRNCR_TFI_POS 4
/*! Field TFI - TX Finished Interrupt Request */
#define SSC_IRNCR_TFI_MASK 0x10u

/*! @} */

/*! \defgroup SSC_IRNICR Register SSC_IRNICR - Interrupt Node Interrupt Capture Register */
/*! @{ */

/*! Register Offset (relative) */
#define SSC_IRNICR 0xFC
/*! Register Offset (absolute) for 1st Instance SPI0 */
#define SPI0_SSC_IRNICR 0x168000FCu

/*! Register Reset Value */
#define SSC_IRNICR_RST 0x00000000u

/*! Field T - Transmit Interrupt Request */
#define SSC_IRNICR_T_POS 0
/*! Field T - Transmit Interrupt Request */
#define SSC_IRNICR_T_MASK 0x1u

/*! Field R - Receive Interrupt Request */
#define SSC_IRNICR_R_POS 1
/*! Field R - Receive Interrupt Request */
#define SSC_IRNICR_R_MASK 0x2u

/*! Field E - Error Interrupt Request */
#define SSC_IRNICR_E_POS 2
/*! Field E - Error Interrupt Request */
#define SSC_IRNICR_E_MASK 0x4u

/*! Field F - Frame End Interrupt Request */
#define SSC_IRNICR_F_POS 3
/*! Field F - Frame End Interrupt Request */
#define SSC_IRNICR_F_MASK 0x8u

/*! Field TFI - TX Finished Interrupt Request */
#define SSC_IRNICR_TFI_POS 4
/*! Field TFI - TX Finished Interrupt Request */
#define SSC_IRNICR_TFI_MASK 0x10u

/*! @} */

/*! @} */

#endif
