/* Copyright (c) 2017, Intel Corporation.
 *
 * DMA0 header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _DMA_H
#define _DMA_H

/*! \defgroup DMA Register File DMA - DMA Registers */
/*! @{ */

/*! Base Address of ACA_DMA */
#define ACA_DMA_MODULE_BASE 0x14060000u
/*! Base Address of DMA0 */
#define DMA0_MODULE_BASE 0x16E00000u
/*! Base Address of DMA4 */
#define DMA4_MODULE_BASE 0x18E00000u

/*! \defgroup DMA_CLC Register DMA_CLC - Clock Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CLC 0x0
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CLC 0x14060000u

/*! Register Reset Value */
#define DMA_CLC_RST 0x00000000u

/*! Field DISR - Disable Request Bit */
#define DMA_CLC_DISR_POS 0
/*! Field DISR - Disable Request Bit */
#define DMA_CLC_DISR_MASK 0x1u
/*! Constant CLK_ON - CLK_ON */
#define CONST_DMA_CLC_DISR_CLK_ON 0x0
/*! Constant CLK_OFF - CLK_OFF */
#define CONST_DMA_CLC_DISR_CLK_OFF 0x1

/*! Field DISS - Disable Status Bit */
#define DMA_CLC_DISS_POS 1
/*! Field DISS - Disable Status Bit */
#define DMA_CLC_DISS_MASK 0x2u
/*! Constant CLK_ON - CLK_ON */
#define CONST_DMA_CLC_DISS_CLK_ON 0x0
/*! Constant CLK_OFF - CLK_OFF */
#define CONST_DMA_CLC_DISS_CLK_OFF 0x1

/*! Field SPEN - Suspend Enable Bit for OCDS */
#define DMA_CLC_SPEN_POS 2
/*! Field SPEN - Suspend Enable Bit for OCDS */
#define DMA_CLC_SPEN_MASK 0x4u
/*! Constant SUS_OFF - SUS_OFF */
#define CONST_DMA_CLC_SPEN_SUS_OFF 0x0
/*! Constant SUS_ON - SUS_ON */
#define CONST_DMA_CLC_SPEN_SUS_ON 0x1

/*! Field EDIS - External Request Disable */
#define DMA_CLC_EDIS_POS 3
/*! Field EDIS - External Request Disable */
#define DMA_CLC_EDIS_MASK 0x8u
/*! Constant SLP_ON - SLP_ON */
#define CONST_DMA_CLC_EDIS_SLP_ON 0x0
/*! Constant SLP_OFF - SLP_OFF */
#define CONST_DMA_CLC_EDIS_SLP_OFF 0x1

/*! Field SBWE - Suspend Bit Write Enable for OCDS */
#define DMA_CLC_SBWE_POS 4
/*! Field SBWE - Suspend Bit Write Enable for OCDS */
#define DMA_CLC_SBWE_MASK 0x10u
/*! Constant SPEN_PROT - SPEN_PROT */
#define CONST_DMA_CLC_SBWE_SPEN_PROT 0x0
/*! Constant SPEN_WE - SPEN_WE */
#define CONST_DMA_CLC_SBWE_SPEN_WE 0x1

/*! Field FSOE - Fast Shut-Off Enable Bit */
#define DMA_CLC_FSOE_POS 5
/*! Field FSOE - Fast Shut-Off Enable Bit */
#define DMA_CLC_FSOE_MASK 0x20u
/*! Constant SLOW_SLP - SLOW_SLP */
#define CONST_DMA_CLC_FSOE_SLOW_SLP 0x0
/*! Constant FAST_SLP - FAST_SLP */
#define CONST_DMA_CLC_FSOE_FAST_SLP 0x1

/*! @} */

/*! \defgroup DMA_ID Register DMA_ID - Identification Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_ID 0x8
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_ID 0x14060008u

/*! Register Reset Value */
#define DMA_ID_RST 0x00814C0Au

/*! Field REV - Revision */
#define DMA_ID_REV_POS 0
/*! Field REV - Revision */
#define DMA_ID_REV_MASK 0x1Fu

/*! Field ID - Module ID */
#define DMA_ID_ID_POS 8
/*! Field ID - Module ID */
#define DMA_ID_ID_MASK 0xFF00u

/*! Field PRTNR - Number of Ports */
#define DMA_ID_PRTNR_POS 16
/*! Field PRTNR - Number of Ports */
#define DMA_ID_PRTNR_MASK 0xF0000u

/*! Field CHNR - Number of Channels */
#define DMA_ID_CHNR_POS 20
/*! Field CHNR - Number of Channels */
#define DMA_ID_CHNR_MASK 0x7F00000u

/*! @} */

/*! \defgroup DMA_CTRL Register DMA_CTRL - DMA Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CTRL 0x10
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CTRL 0x14060010u

/*! Register Reset Value */
#define DMA_CTRL_RST 0x00040A00u

/*! Field RST - Global Software Reset */
#define DMA_CTRL_RST_POS 0
/*! Field RST - Global Software Reset */
#define DMA_CTRL_RST_MASK 0x1u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CTRL_RST_NO_ACTION 0x0
/*! Constant DMA_RESET - DMA_RESET */
#define CONST_DMA_CTRL_RST_DMA_RESET 0x1

/*! Field DSRAM_PATH_S - Dedicated Descriptor Access port Enable */
#define DMA_CTRL_DSRAM_PATH_S_POS 1
/*! Field DSRAM_PATH_S - Dedicated Descriptor Access port Enable */
#define DMA_CTRL_DSRAM_PATH_S_MASK 0x2u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CTRL_DSRAM_PATH_S_NO_ACTION 0x0
/*! Constant DS_S - DMA dedicated descriptor port enabled */
#define CONST_DMA_CTRL_DSRAM_PATH_S_DS_S 0x1

/*! Field SK_CH - Enable per channel flow control */
#define DMA_CTRL_SK_CH_POS 6
/*! Field SK_CH - Enable per channel flow control */
#define DMA_CTRL_SK_CH_MASK 0x40u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CTRL_SK_CH_NO_ACTION 0x0
/*! Constant SK_CH - Enable per channel flow control mechanism. */
#define CONST_DMA_CTRL_SK_CH_SK_CH 0x1

/*! Field DS_FOD - Enable descriptor fetch on demand */
#define DMA_CTRL_DS_FOD_POS 7
/*! Field DS_FOD - Enable descriptor fetch on demand */
#define DMA_CTRL_DS_FOD_MASK 0x80u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CTRL_DS_FOD_NO_ACTION 0x0
/*! Constant SK_CH - Enable fetch on demand feature. */
#define CONST_DMA_CTRL_DS_FOD_SK_CH 0x1

/*! Field DRB - Descriptor WNP */
#define DMA_CTRL_DRB_POS 8
/*! Field DRB - Descriptor WNP */
#define DMA_CTRL_DRB_MASK 0x100u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CTRL_DRB_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CTRL_DRB_ENABLED 0x1

/*! Field ENBE - Enable Byte Enable */
#define DMA_CTRL_ENBE_POS 9
/*! Field ENBE - Enable Byte Enable */
#define DMA_CTRL_ENBE_MASK 0x200u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CTRL_ENBE_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CTRL_ENBE_ENABLED 0x1

/*! Field PRELOAD_INT - Preload Interval */
#define DMA_CTRL_PRELOAD_INT_POS 10
/*! Field PRELOAD_INT - Preload Interval */
#define DMA_CTRL_PRELOAD_INT_MASK 0xC00u
/*! Constant NONE - no preload */
#define CONST_DMA_CTRL_PRELOAD_INT_NONE 0x0
/*! Constant BURST1 - 1 x burst length */
#define CONST_DMA_CTRL_PRELOAD_INT_BURST1 0x1
/*! Constant BURST2 - 2 x burst length */
#define CONST_DMA_CTRL_PRELOAD_INT_BURST2 0x2
/*! Constant BURST3 - 3 x burst length */
#define CONST_DMA_CTRL_PRELOAD_INT_BURST3 0x3

/*! Field PRELOAD_EN - Descriptor Preload Control */
#define DMA_CTRL_PRELOAD_EN_POS 12
/*! Field PRELOAD_EN - Descriptor Preload Control */
#define DMA_CTRL_PRELOAD_EN_MASK 0x1000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CTRL_PRELOAD_EN_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CTRL_PRELOAD_EN_ENABLED 0x1

/*! Field MBRSTCNT - Multiple Burst Counter */
#define DMA_CTRL_MBRSTCNT_POS 16
/*! Field MBRSTCNT - Multiple Burst Counter */
#define DMA_CTRL_MBRSTCNT_MASK 0x3FF0000u

/*! Field MBRSTARB - Multiple Burst Arbitration */
#define DMA_CTRL_MBRSTARB_POS 30
/*! Field MBRSTARB - Multiple Burst Arbitration */
#define DMA_CTRL_MBRSTARB_MASK 0x40000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CTRL_MBRSTARB_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CTRL_MBRSTARB_ENABLED 0x1

/*! Field PKTARB - Packet Arbitration */
#define DMA_CTRL_PKTARB_POS 31
/*! Field PKTARB - Packet Arbitration */
#define DMA_CTRL_PKTARB_MASK 0x80000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CTRL_PKTARB_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CTRL_PKTARB_ENABLED 0x1

/*! @} */

/*! \defgroup DMA_CPOLL Register DMA_CPOLL - DMA Channel Polling Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CPOLL 0x14
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CPOLL 0x14060014u

/*! Register Reset Value */
#define DMA_CPOLL_RST 0x00000000u

/*! Field CNT - Counter */
#define DMA_CPOLL_CNT_POS 4
/*! Field CNT - Counter */
#define DMA_CPOLL_CNT_MASK 0xFFF0u

/*! Field EN - Enable */
#define DMA_CPOLL_EN_POS 31
/*! Field EN - Enable */
#define DMA_CPOLL_EN_MASK 0x80000000u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_CPOLL_EN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_CPOLL_EN_ENABLE 0x1

/*! @} */

/*! \defgroup DMA_CS Register DMA_CS - DMA Channel Select Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CS 0x18
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CS 0x14060018u

/*! Register Reset Value */
#define DMA_CS_RST 0x00000000u

/*! Field CS - Channel Selection */
#define DMA_CS_CS_POS 0
/*! Field CS - Channel Selection */
#define DMA_CS_CS_MASK 0x3Fu

/*! @} */

/*! \defgroup DMA_CCTRL Register DMA_CCTRL - DMA Channel Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CCTRL 0x1C
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CCTRL 0x1406001Cu

/*! Register Reset Value */
#define DMA_CCTRL_RST 0x00010000u

/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL_ON_OFF_POS 0
/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL_ON_OFF_MASK 0x1u
/*! Constant CHANNEL_OFF - CHANNEL_OFF */
#define CONST_DMA_CCTRL_ON_OFF_CHANNEL_OFF 0x0
/*! Constant CHANNEL_ON - CHANNEL_ON */
#define CONST_DMA_CCTRL_ON_OFF_CHANNEL_ON 0x1

/*! Field RST - Reset */
#define DMA_CCTRL_RST_POS 1
/*! Field RST - Reset */
#define DMA_CCTRL_RST_MASK 0x2u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL_RST_NO_ACTION 0x0
/*! Constant CHANNEL_RESET - CHANNEL_RESET */
#define CONST_DMA_CCTRL_RST_CHANNEL_RESET 0x1

/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL_CH_POLL_POS 2
/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL_CH_POLL_MASK 0x4u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL_CH_POLL_NO_ACTION 0x0
/*! Constant CHANNEL_P - CHANNEL Polling enabled. */
#define CONST_DMA_CCTRL_CH_POLL_CHANNEL_P 0x1

/*! Field DIR - Direction */
#define DMA_CCTRL_DIR_POS 8
/*! Field DIR - Direction */
#define DMA_CCTRL_DIR_MASK 0x100u
/*! Constant RX - RX */
#define CONST_DMA_CCTRL_DIR_RX 0x0
/*! Constant TX - TX */
#define CONST_DMA_CCTRL_DIR_TX 0x1

/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL_CLASS_POS 9
/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL_CLASS_MASK 0xE00u

/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL_PRTNR_POS 12
/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL_PRTNR_MASK 0xF000u

/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL_TXWGT_POS 16
/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL_TXWGT_MASK 0x30000u

/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL_CLASSH_POS 18
/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL_CLASSH_MASK 0xC0000u

/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL_PDEN_POS 23
/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL_PDEN_MASK 0x800000u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_CCTRL_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_CCTRL_PDEN_ENABLE 0x1

/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL_P2PCPY_POS 24
/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL_P2PCPY_MASK 0x1000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL_P2PCPY_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL_P2PCPY_ENABLED 0x1

/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL_LBEN_POS 25
/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL_LBEN_MASK 0x2000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL_LBEN_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL_LBEN_ENABLED 0x1

/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL_LBCHNR_POS 26
/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL_LBCHNR_MASK 0xFC000000u

/*! @} */

/*! \defgroup DMA_CDBA Register DMA_CDBA - DMA Channel Descriptor Base Address Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDBA 0x20
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDBA 0x14060020u

/*! Register Reset Value */
#define DMA_CDBA_RST 0x00000000u

/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA_CDBA_POS 0
/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA_CDBA_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_CDLEN Register DMA_CDLEN - DMA Channel Descriptor Length Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDLEN 0x24
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDLEN 0x14060024u

/*! Register Reset Value */
#define DMA_CDLEN_RST 0x00000000u

/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN_CDLEN_POS 0
/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN_CDLEN_MASK 0xFFFu

/*! @} */

/*! \defgroup DMA_CIS Register DMA_CIS - DMA Channel Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIS 0x28
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIS 0x14060028u

/*! Register Reset Value */
#define DMA_CIS_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS_EOP_POS 1
/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS_EOP_MASK 0x2u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS_EOP_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS_EOP_INTERRUPT_OR_RESET 0x1

/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS_DUR_POS 2
/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS_DUR_MASK 0x4u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS_DUR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS_DUR_INTERRUPT_OR_RESET 0x1

/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS_DESCPT_MASK 0x8u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS_DESCPT_NO_INTERRUPT 0x0
/*! Constant INTERRUPTOR_RESET - INTERRUPTOR_RESET */
#define CONST_DMA_CIS_DESCPT_INTERRUPTOR_RESET 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS_CHOFF_MASK 0x10u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS_CHOFF_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS_CHOFF_INTERRUPT_OR_RESET 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS_RDERR_MASK 0x20u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS_RDERR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS_RDERR_INTERRUPT_OR_RESET 0x1

/*! @} */

/*! \defgroup DMA_CIE Register DMA_CIE - DMA Channel Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIE 0x2C
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIE 0x1406002Cu

/*! Register Reset Value */
#define DMA_CIE_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE_EOP_POS 1
/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE_EOP_MASK 0x2u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE_EOP_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE_EOP_ENABLED 0x1

/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE_DUR_POS 2
/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE_DUR_MASK 0x4u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE_DUR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE_DUR_ENABLED 0x1

/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE_DESCPT_MASK 0x8u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE_DESCPT_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE_DESCPT_ENABLED 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE_CHOFF_MASK 0x10u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE_CHOFF_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE_CHOFF_ENABLED 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE_RDERR_MASK 0x20u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE_RDERR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE_RDERR_ENABLED 0x1

/*! @} */

/*! \defgroup DMA_CGBL Register DMA_CGBL - DMA Channel Global Buffer Length Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CGBL 0x30
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CGBL 0x14060030u

/*! Register Reset Value */
#define DMA_CGBL_RST 0x00000000u

/*! Field GBL - Global Buffer Length */
#define DMA_CGBL_GBL_POS 0
/*! Field GBL - Global Buffer Length */
#define DMA_CGBL_GBL_MASK 0xFFFFu

/*! @} */

/*! \defgroup DMA_CDPTNRD Register DMA_CDPTNRD - DMA Current Descriptor Pointer Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDPTNRD 0x34
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDPTNRD 0x14060034u

/*! Register Reset Value */
#define DMA_CDPTNRD_RST 0x00000000u

/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD_CDPNTR_POS 0
/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD_CDPNTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_CDPTNRD1 Register DMA_CDPTNRD1 - DMA Current Descriptor Pointer 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDPTNRD1 0x38
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDPTNRD1 0x14060038u

/*! Register Reset Value */
#define DMA_CDPTNRD1_RST 0x00000000u

/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD1_CDPNTR_POS 0
/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD1_CDPNTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_PS Register DMA_PS - DMA Port Select Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PS 0x40
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PS 0x14060040u

/*! Register Reset Value */
#define DMA_PS_RST 0x00000000u

/*! Field PS - Port Selection */
#define DMA_PS_PS_POS 0
/*! Field PS - Port Selection */
#define DMA_PS_PS_MASK 0xFu

/*! @} */

/*! \defgroup DMA_PCTRL Register DMA_PCTRL - DMA Port Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PCTRL 0x44
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PCTRL 0x14060044u

/*! Register Reset Value */
#define DMA_PCTRL_RST 0x00001014u

/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL_RXBL16_POS 0
/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL_RXBL16_MASK 0x1u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL_RXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL_RXBL16_B16 0x1

/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL_TXBL16_POS 1
/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL_TXBL16_MASK 0x2u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL_TXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL_TXBL16_B16 0x1

/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL_RXBL_POS 2
/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL_RXBL_MASK 0xCu
/*! Constant WORDS2 - WORDS2 */
#define CONST_DMA_PCTRL_RXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL_RXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL_RXBL_WORDS8 0x3

/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL_TXBL_POS 4
/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL_TXBL_MASK 0x30u
/*! Constant WORDS2 - 2 WORDS */
#define CONST_DMA_PCTRL_TXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL_TXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL_TXBL_WORDS8 0x3

/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL_PDEN_POS 6
/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL_PDEN_MASK 0x40u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_PCTRL_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_PCTRL_PDEN_ENABLE 0x1

/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL_RXENDI_POS 8
/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL_RXENDI_MASK 0x300u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL_RXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL_RXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL_RXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL_RXENDI_B0_B1_B2_B3 0x3

/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL_TXENDI_POS 10
/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL_TXENDI_MASK 0xC00u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL_TXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL_TXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL_TXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL_TXENDI_B0_B1_B2_B3 0x3

/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL_TXWGT_POS 12
/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL_TXWGT_MASK 0x7000u

/*! Field GPC - General Purpose Control */
#define DMA_PCTRL_GPC_POS 16
/*! Field GPC - General Purpose Control */
#define DMA_PCTRL_GPC_MASK 0x10000u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_PCTRL_GPC_NO_ACTION 0x0
/*! Constant FLUSH_MEMCOPY - FLUSH_MEMCOPY */
#define CONST_DMA_PCTRL_GPC_FLUSH_MEMCOPY 0x1

/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL_DBG_P2D_CLS_POS 17
/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL_DBG_P2D_CLS_MASK 0x1E0000u

/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL_DBG_P2D_ACK_POS 21
/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL_DBG_P2D_ACK_MASK 0x200000u

/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL_DBG_D2P_CLS_POS 22
/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL_DBG_D2P_CLS_MASK 0x3C00000u

/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL_DBG_D2P_ACK_POS 26
/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL_DBG_D2P_ACK_MASK 0x4000000u

/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL_DBG_P2D_PREQ_POS 27
/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL_DBG_P2D_PREQ_MASK 0x8000000u

/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL_DBG_D2P_PREQ_POS 28
/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL_DBG_D2P_PREQ_MASK 0x10000000u

/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL_DBG_P2D_RME_POS 29
/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL_DBG_P2D_RME_MASK 0x20000000u

/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL_DBG_D2P_XME_POS 30
/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL_DBG_D2P_XME_MASK 0x40000000u

/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL_DBG_P2D_JMB_POS 31
/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL_DBG_P2D_JMB_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_CS1 Register DMA_CS1 - Channel Select 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CS1 0x50
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CS1 0x14060050u

/*! Register Reset Value */
#define DMA_CS1_RST 0x00000000u

/*! Field CS - Channel Selection */
#define DMA_CS1_CS_POS 0
/*! Field CS - Channel Selection */
#define DMA_CS1_CS_MASK 0x3Fu

/*! @} */

/*! \defgroup DMA_CCTRL1 Register DMA_CCTRL1 - DMA Channel Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CCTRL1 0x54
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CCTRL1 0x14060054u

/*! Register Reset Value */
#define DMA_CCTRL1_RST 0x00010000u

/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL1_ON_OFF_POS 0
/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL1_ON_OFF_MASK 0x1u
/*! Constant CHANNEL_OFF - CHANNEL_OFF */
#define CONST_DMA_CCTRL1_ON_OFF_CHANNEL_OFF 0x0
/*! Constant CHANNEL_ON - CHANNEL_ON */
#define CONST_DMA_CCTRL1_ON_OFF_CHANNEL_ON 0x1

/*! Field RST - Reset */
#define DMA_CCTRL1_RST_POS 1
/*! Field RST - Reset */
#define DMA_CCTRL1_RST_MASK 0x2u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL1_RST_NO_ACTION 0x0
/*! Constant CHANNEL_RESET - CHANNEL_RESET */
#define CONST_DMA_CCTRL1_RST_CHANNEL_RESET 0x1

/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL1_CH_POLL_POS 2
/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL1_CH_POLL_MASK 0x4u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL1_CH_POLL_NO_ACTION 0x0
/*! Constant CHANNEL_P - CHANNEL Polling enabled. */
#define CONST_DMA_CCTRL1_CH_POLL_CHANNEL_P 0x1

/*! Field DIR - Direction */
#define DMA_CCTRL1_DIR_POS 8
/*! Field DIR - Direction */
#define DMA_CCTRL1_DIR_MASK 0x100u
/*! Constant RX - RX */
#define CONST_DMA_CCTRL1_DIR_RX 0x0
/*! Constant TX - TX */
#define CONST_DMA_CCTRL1_DIR_TX 0x1

/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL1_CLASS_POS 9
/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL1_CLASS_MASK 0xE00u

/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL1_PRTNR_POS 12
/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL1_PRTNR_MASK 0xF000u

/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL1_TXWGT_POS 16
/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL1_TXWGT_MASK 0x30000u

/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL1_CLASSH_POS 18
/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL1_CLASSH_MASK 0xC0000u

/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL1_PDEN_POS 23
/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL1_PDEN_MASK 0x800000u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_CCTRL1_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_CCTRL1_PDEN_ENABLE 0x1

/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL1_P2PCPY_POS 24
/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL1_P2PCPY_MASK 0x1000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL1_P2PCPY_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL1_P2PCPY_ENABLED 0x1

/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL1_LBEN_POS 25
/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL1_LBEN_MASK 0x2000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL1_LBEN_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL1_LBEN_ENABLED 0x1

/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL1_LBCHNR_POS 26
/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL1_LBCHNR_MASK 0xFC000000u

/*! @} */

/*! \defgroup DMA_CDBA1 Register DMA_CDBA1 - Channel Descriptor Base Address 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDBA1 0x58
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDBA1 0x14060058u

/*! Register Reset Value */
#define DMA_CDBA1_RST 0x00000000u

/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA1_CDBA_POS 0
/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA1_CDBA_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_CDLEN1 Register DMA_CDLEN1 - Channel Descriptor Length 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDLEN1 0x5C
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDLEN1 0x1406005Cu

/*! Register Reset Value */
#define DMA_CDLEN1_RST 0x00000000u

/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN1_CDLEN_POS 0
/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN1_CDLEN_MASK 0xFFFu

/*! @} */

/*! \defgroup DMA_CIS1 Register DMA_CIS1 - Channel Interrupt Status 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIS1 0x60
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIS1 0x14060060u

/*! Register Reset Value */
#define DMA_CIS1_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS1_EOP_POS 1
/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS1_EOP_MASK 0x2u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS1_EOP_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS1_EOP_INTERRUPT_OR_RESET 0x1

/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS1_DUR_POS 2
/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS1_DUR_MASK 0x4u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS1_DUR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS1_DUR_INTERRUPT_OR_RESET 0x1

/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS1_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS1_DESCPT_MASK 0x8u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS1_DESCPT_NO_INTERRUPT 0x0
/*! Constant INTERRUPTOR_RESET - INTERRUPTOR_RESET */
#define CONST_DMA_CIS1_DESCPT_INTERRUPTOR_RESET 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS1_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS1_CHOFF_MASK 0x10u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS1_CHOFF_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS1_CHOFF_INTERRUPT_OR_RESET 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS1_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS1_RDERR_MASK 0x20u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS1_RDERR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS1_RDERR_INTERRUPT_OR_RESET 0x1

/*! @} */

/*! \defgroup DMA_CIE1 Register DMA_CIE1 - Channel Interrupt Enable 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIE1 0x64
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIE1 0x14060064u

/*! Register Reset Value */
#define DMA_CIE1_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE1_EOP_POS 1
/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE1_EOP_MASK 0x2u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE1_EOP_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE1_EOP_ENABLED 0x1

/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE1_DUR_POS 2
/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE1_DUR_MASK 0x4u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE1_DUR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE1_DUR_ENABLED 0x1

/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE1_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE1_DESCPT_MASK 0x8u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE1_DESCPT_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE1_DESCPT_ENABLED 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE1_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE1_CHOFF_MASK 0x10u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE1_CHOFF_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE1_CHOFF_ENABLED 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE1_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE1_RDERR_MASK 0x20u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE1_RDERR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE1_RDERR_ENABLED 0x1

/*! @} */

/*! \defgroup DMA_PS1 Register DMA_PS1 - Port Select 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PS1 0x70
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PS1 0x14060070u

/*! Register Reset Value */
#define DMA_PS1_RST 0x00000000u

/*! Field PS - Port Selection */
#define DMA_PS1_PS_POS 0
/*! Field PS - Port Selection */
#define DMA_PS1_PS_MASK 0xFu

/*! @} */

/*! \defgroup DMA_PCTRL1 Register DMA_PCTRL1 - Port Control 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PCTRL1 0x74
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PCTRL1 0x14060074u

/*! Register Reset Value */
#define DMA_PCTRL1_RST 0x00001014u

/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL1_RXBL16_POS 0
/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL1_RXBL16_MASK 0x1u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL1_RXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL1_RXBL16_B16 0x1

/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL1_TXBL16_POS 1
/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL1_TXBL16_MASK 0x2u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL1_TXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL1_TXBL16_B16 0x1

/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL1_RXBL_POS 2
/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL1_RXBL_MASK 0xCu
/*! Constant WORDS2 - WORDS2 */
#define CONST_DMA_PCTRL1_RXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL1_RXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL1_RXBL_WORDS8 0x3

/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL1_TXBL_POS 4
/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL1_TXBL_MASK 0x30u
/*! Constant WORDS2 - 2 WORDS */
#define CONST_DMA_PCTRL1_TXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL1_TXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL1_TXBL_WORDS8 0x3

/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL1_PDEN_POS 6
/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL1_PDEN_MASK 0x40u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_PCTRL1_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_PCTRL1_PDEN_ENABLE 0x1

/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL1_RXENDI_POS 8
/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL1_RXENDI_MASK 0x300u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL1_RXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL1_RXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL1_RXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL1_RXENDI_B0_B1_B2_B3 0x3

/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL1_TXENDI_POS 10
/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL1_TXENDI_MASK 0xC00u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL1_TXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL1_TXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL1_TXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL1_TXENDI_B0_B1_B2_B3 0x3

/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL1_TXWGT_POS 12
/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL1_TXWGT_MASK 0x7000u

/*! Field GPC - General Purpose Control */
#define DMA_PCTRL1_GPC_POS 16
/*! Field GPC - General Purpose Control */
#define DMA_PCTRL1_GPC_MASK 0x10000u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_PCTRL1_GPC_NO_ACTION 0x0
/*! Constant FLUSH_MEMCOPY - FLUSH_MEMCOPY */
#define CONST_DMA_PCTRL1_GPC_FLUSH_MEMCOPY 0x1

/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL1_DBG_P2D_CLS_POS 17
/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL1_DBG_P2D_CLS_MASK 0x1E0000u

/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL1_DBG_P2D_ACK_POS 21
/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL1_DBG_P2D_ACK_MASK 0x200000u

/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL1_DBG_D2P_CLS_POS 22
/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL1_DBG_D2P_CLS_MASK 0x3C00000u

/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL1_DBG_D2P_ACK_POS 26
/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL1_DBG_D2P_ACK_MASK 0x4000000u

/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL1_DBG_P2D_PREQ_POS 27
/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL1_DBG_P2D_PREQ_MASK 0x8000000u

/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL1_DBG_D2P_PREQ_POS 28
/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL1_DBG_D2P_PREQ_MASK 0x10000000u

/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL1_DBG_P2D_RME_POS 29
/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL1_DBG_P2D_RME_MASK 0x20000000u

/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL1_DBG_D2P_XME_POS 30
/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL1_DBG_D2P_XME_MASK 0x40000000u

/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL1_DBG_P2D_JMB_POS 31
/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL1_DBG_P2D_JMB_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_CPDCNT Register DMA_CPDCNT - DMA Ch Packet Drop Counter */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CPDCNT 0x80
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CPDCNT 0x14060080u

/*! Register Reset Value */
#define DMA_CPDCNT_RST 0x00000000u

/*! Field DMA_C_PDCNT - Channel Packet Drop Counter */
#define DMA_CPDCNT_DMA_C_PDCNT_POS 0
/*! Field DMA_C_PDCNT - Channel Packet Drop Counter */
#define DMA_CPDCNT_DMA_C_PDCNT_MASK 0x7FFFFFFFu

/*! @} */

/*! \defgroup DMA_CPDCNT1 Register DMA_CPDCNT1 - DMA Ch Packet Drop Counter */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CPDCNT1 0x84
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CPDCNT1 0x14060084u

/*! Register Reset Value */
#define DMA_CPDCNT1_RST 0x00000000u

/*! Field DMA_C_PDCNT - Channel Packet Drop Counter */
#define DMA_CPDCNT1_DMA_C_PDCNT_POS 0
/*! Field DMA_C_PDCNT - Channel Packet Drop Counter */
#define DMA_CPDCNT1_DMA_C_PDCNT_MASK 0x7FFFFFFFu

/*! @} */

/*! \defgroup DMA_CS2 Register DMA_CS2 - Channel selection 2 register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CS2 0x90
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CS2 0x14060090u

/*! Register Reset Value */
#define DMA_CS2_RST 0x00000000u

/*! Field CS - Channel Selection */
#define DMA_CS2_CS_POS 0
/*! Field CS - Channel Selection */
#define DMA_CS2_CS_MASK 0x3Fu

/*! @} */

/*! \defgroup DMA_CCTRL2 Register DMA_CCTRL2 - channel control register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CCTRL2 0x94
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CCTRL2 0x14060094u

/*! Register Reset Value */
#define DMA_CCTRL2_RST 0x00010000u

/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL2_ON_OFF_POS 0
/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL2_ON_OFF_MASK 0x1u
/*! Constant CHANNEL_OFF - CHANNEL_OFF */
#define CONST_DMA_CCTRL2_ON_OFF_CHANNEL_OFF 0x0
/*! Constant CHANNEL_ON - CHANNEL_ON */
#define CONST_DMA_CCTRL2_ON_OFF_CHANNEL_ON 0x1

/*! Field RST - Reset */
#define DMA_CCTRL2_RST_POS 1
/*! Field RST - Reset */
#define DMA_CCTRL2_RST_MASK 0x2u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL2_RST_NO_ACTION 0x0
/*! Constant CHANNEL_RESET - CHANNEL_RESET */
#define CONST_DMA_CCTRL2_RST_CHANNEL_RESET 0x1

/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL2_CH_POLL_POS 2
/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL2_CH_POLL_MASK 0x4u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL2_CH_POLL_NO_ACTION 0x0
/*! Constant CHANNEL_P - CHANNEL Polling enabled. */
#define CONST_DMA_CCTRL2_CH_POLL_CHANNEL_P 0x1

/*! Field DIR - Direction */
#define DMA_CCTRL2_DIR_POS 8
/*! Field DIR - Direction */
#define DMA_CCTRL2_DIR_MASK 0x100u
/*! Constant RX - RX */
#define CONST_DMA_CCTRL2_DIR_RX 0x0
/*! Constant TX - TX */
#define CONST_DMA_CCTRL2_DIR_TX 0x1

/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL2_CLASS_POS 9
/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL2_CLASS_MASK 0xE00u

/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL2_PRTNR_POS 12
/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL2_PRTNR_MASK 0xF000u

/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL2_TXWGT_POS 16
/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL2_TXWGT_MASK 0x30000u

/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL2_CLASSH_POS 18
/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL2_CLASSH_MASK 0xC0000u

/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL2_PDEN_POS 23
/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL2_PDEN_MASK 0x800000u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_CCTRL2_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_CCTRL2_PDEN_ENABLE 0x1

/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL2_P2PCPY_POS 24
/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL2_P2PCPY_MASK 0x1000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL2_P2PCPY_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL2_P2PCPY_ENABLED 0x1

/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL2_LBEN_POS 25
/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL2_LBEN_MASK 0x2000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL2_LBEN_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL2_LBEN_ENABLED 0x1

/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL2_LBCHNR_POS 26
/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL2_LBCHNR_MASK 0xFC000000u

/*! @} */

/*! \defgroup DMA_CDBA2 Register DMA_CDBA2 - Channel Descriptor Base Address register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDBA2 0x98
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDBA2 0x14060098u

/*! Register Reset Value */
#define DMA_CDBA2_RST 0x00000000u

/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA2_CDBA_POS 0
/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA2_CDBA_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_CDLEN2 Register DMA_CDLEN2 - channel descriptor length register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDLEN2 0x9C
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDLEN2 0x1406009Cu

/*! Register Reset Value */
#define DMA_CDLEN2_RST 0x00000000u

/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN2_CDLEN_POS 0
/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN2_CDLEN_MASK 0xFFFu

/*! @} */

/*! \defgroup DMA_CIS2 Register DMA_CIS2 - channel interrupt status register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIS2 0xA0
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIS2 0x140600A0u

/*! Register Reset Value */
#define DMA_CIS2_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS2_EOP_POS 1
/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS2_EOP_MASK 0x2u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS2_EOP_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS2_EOP_INTERRUPT_OR_RESET 0x1

/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS2_DUR_POS 2
/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS2_DUR_MASK 0x4u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS2_DUR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS2_DUR_INTERRUPT_OR_RESET 0x1

/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS2_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS2_DESCPT_MASK 0x8u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS2_DESCPT_NO_INTERRUPT 0x0
/*! Constant INTERRUPTOR_RESET - INTERRUPTOR_RESET */
#define CONST_DMA_CIS2_DESCPT_INTERRUPTOR_RESET 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS2_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS2_CHOFF_MASK 0x10u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS2_CHOFF_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS2_CHOFF_INTERRUPT_OR_RESET 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS2_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS2_RDERR_MASK 0x20u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS2_RDERR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS2_RDERR_INTERRUPT_OR_RESET 0x1

/*! @} */

/*! \defgroup DMA_CIE2 Register DMA_CIE2 - channel interrupt enable register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIE2 0xA4
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIE2 0x140600A4u

/*! Register Reset Value */
#define DMA_CIE2_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE2_EOP_POS 1
/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE2_EOP_MASK 0x2u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE2_EOP_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE2_EOP_ENABLED 0x1

/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE2_DUR_POS 2
/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE2_DUR_MASK 0x4u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE2_DUR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE2_DUR_ENABLED 0x1

/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE2_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE2_DESCPT_MASK 0x8u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE2_DESCPT_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE2_DESCPT_ENABLED 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE2_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE2_CHOFF_MASK 0x10u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE2_CHOFF_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE2_CHOFF_ENABLED 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE2_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE2_RDERR_MASK 0x20u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE2_RDERR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE2_RDERR_ENABLED 0x1

/*! @} */

/*! \defgroup DMA_CDPTNRD2 Register DMA_CDPTNRD2 - DMA Current Descriptor Pointer Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDPTNRD2 0xAC
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDPTNRD2 0x140600ACu

/*! Register Reset Value */
#define DMA_CDPTNRD2_RST 0x00000000u

/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD2_CDPNTR_POS 0
/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD2_CDPNTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_PS2 Register DMA_PS2 - Port Select 2 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PS2 0xB0
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PS2 0x140600B0u

/*! Register Reset Value */
#define DMA_PS2_RST 0x00000000u

/*! Field PS - Port Selection */
#define DMA_PS2_PS_POS 0
/*! Field PS - Port Selection */
#define DMA_PS2_PS_MASK 0xFu

/*! @} */

/*! \defgroup DMA_PCTRL2 Register DMA_PCTRL2 - Port Control 2 register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PCTRL2 0xB4
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PCTRL2 0x140600B4u

/*! Register Reset Value */
#define DMA_PCTRL2_RST 0x00001014u

/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL2_RXBL16_POS 0
/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL2_RXBL16_MASK 0x1u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL2_RXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL2_RXBL16_B16 0x1

/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL2_TXBL16_POS 1
/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL2_TXBL16_MASK 0x2u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL2_TXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL2_TXBL16_B16 0x1

/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL2_RXBL_POS 2
/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL2_RXBL_MASK 0xCu
/*! Constant WORDS2 - WORDS2 */
#define CONST_DMA_PCTRL2_RXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL2_RXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL2_RXBL_WORDS8 0x3

/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL2_TXBL_POS 4
/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL2_TXBL_MASK 0x30u
/*! Constant WORDS2 - 2 WORDS */
#define CONST_DMA_PCTRL2_TXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL2_TXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL2_TXBL_WORDS8 0x3

/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL2_PDEN_POS 6
/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL2_PDEN_MASK 0x40u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_PCTRL2_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_PCTRL2_PDEN_ENABLE 0x1

/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL2_RXENDI_POS 8
/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL2_RXENDI_MASK 0x300u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL2_RXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL2_RXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL2_RXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL2_RXENDI_B0_B1_B2_B3 0x3

/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL2_TXENDI_POS 10
/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL2_TXENDI_MASK 0xC00u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL2_TXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL2_TXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL2_TXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL2_TXENDI_B0_B1_B2_B3 0x3

/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL2_TXWGT_POS 12
/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL2_TXWGT_MASK 0x7000u

/*! Field GPC - General Purpose Control */
#define DMA_PCTRL2_GPC_POS 16
/*! Field GPC - General Purpose Control */
#define DMA_PCTRL2_GPC_MASK 0x10000u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_PCTRL2_GPC_NO_ACTION 0x0
/*! Constant FLUSH_MEMCOPY - FLUSH_MEMCOPY */
#define CONST_DMA_PCTRL2_GPC_FLUSH_MEMCOPY 0x1

/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL2_DBG_P2D_CLS_POS 17
/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL2_DBG_P2D_CLS_MASK 0x1E0000u

/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL2_DBG_P2D_ACK_POS 21
/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL2_DBG_P2D_ACK_MASK 0x200000u

/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL2_DBG_D2P_CLS_POS 22
/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL2_DBG_D2P_CLS_MASK 0x3C00000u

/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL2_DBG_D2P_ACK_POS 26
/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL2_DBG_D2P_ACK_MASK 0x4000000u

/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL2_DBG_P2D_PREQ_POS 27
/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL2_DBG_P2D_PREQ_MASK 0x8000000u

/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL2_DBG_D2P_PREQ_POS 28
/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL2_DBG_D2P_PREQ_MASK 0x10000000u

/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL2_DBG_P2D_RME_POS 29
/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL2_DBG_P2D_RME_MASK 0x20000000u

/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL2_DBG_D2P_XME_POS 30
/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL2_DBG_D2P_XME_MASK 0x40000000u

/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL2_DBG_P2D_JMB_POS 31
/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL2_DBG_P2D_JMB_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_CS3 Register DMA_CS3 - Channel selection register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CS3 0xC0
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CS3 0x140600C0u

/*! Register Reset Value */
#define DMA_CS3_RST 0x00000000u

/*! Field CS - Channel Selection */
#define DMA_CS3_CS_POS 0
/*! Field CS - Channel Selection */
#define DMA_CS3_CS_MASK 0x3Fu

/*! @} */

/*! \defgroup DMA_CCTRL3 Register DMA_CCTRL3 - channel control register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CCTRL3 0xC4
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CCTRL3 0x140600C4u

/*! Register Reset Value */
#define DMA_CCTRL3_RST 0x00010000u

/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL3_ON_OFF_POS 0
/*! Field ON_OFF - Channel On or Off */
#define DMA_CCTRL3_ON_OFF_MASK 0x1u
/*! Constant CHANNEL_OFF - CHANNEL_OFF */
#define CONST_DMA_CCTRL3_ON_OFF_CHANNEL_OFF 0x0
/*! Constant CHANNEL_ON - CHANNEL_ON */
#define CONST_DMA_CCTRL3_ON_OFF_CHANNEL_ON 0x1

/*! Field RST - Reset */
#define DMA_CCTRL3_RST_POS 1
/*! Field RST - Reset */
#define DMA_CCTRL3_RST_MASK 0x2u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL3_RST_NO_ACTION 0x0
/*! Constant CHANNEL_RESET - CHANNEL_RESET */
#define CONST_DMA_CCTRL3_RST_CHANNEL_RESET 0x1

/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL3_CH_POLL_POS 2
/*! Field CH_POLL - Enable Channel Polling --feature removed */
#define DMA_CCTRL3_CH_POLL_MASK 0x4u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_CCTRL3_CH_POLL_NO_ACTION 0x0
/*! Constant CHANNEL_P - CHANNEL Polling enabled. */
#define CONST_DMA_CCTRL3_CH_POLL_CHANNEL_P 0x1

/*! Field DIR - Direction */
#define DMA_CCTRL3_DIR_POS 8
/*! Field DIR - Direction */
#define DMA_CCTRL3_DIR_MASK 0x100u
/*! Constant RX - RX */
#define CONST_DMA_CCTRL3_DIR_RX 0x0
/*! Constant TX - TX */
#define CONST_DMA_CCTRL3_DIR_TX 0x1

/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL3_CLASS_POS 9
/*! Field CLASS - Class lower 3 bits */
#define DMA_CCTRL3_CLASS_MASK 0xE00u

/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL3_PRTNR_POS 12
/*! Field PRTNR - Port Assignment */
#define DMA_CCTRL3_PRTNR_MASK 0xF000u

/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL3_TXWGT_POS 16
/*! Field TXWGT - Channel Weight for Transmit Direction */
#define DMA_CCTRL3_TXWGT_MASK 0x30000u

/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL3_CLASSH_POS 18
/*! Field CLASSH - Class Higher Bits */
#define DMA_CCTRL3_CLASSH_MASK 0xC0000u

/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL3_PDEN_POS 23
/*! Field PDEN - Packet Drop Enable */
#define DMA_CCTRL3_PDEN_MASK 0x800000u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_CCTRL3_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_CCTRL3_PDEN_ENABLE 0x1

/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL3_P2PCPY_POS 24
/*! Field P2PCPY - Peripheral to Peripheral Copy */
#define DMA_CCTRL3_P2PCPY_MASK 0x1000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL3_P2PCPY_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL3_P2PCPY_ENABLED 0x1

/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL3_LBEN_POS 25
/*! Field LBEN - Loopback Enable */
#define DMA_CCTRL3_LBEN_MASK 0x2000000u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CCTRL3_LBEN_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CCTRL3_LBEN_ENABLED 0x1

/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL3_LBCHNR_POS 26
/*! Field LBCHNR - Loopback Channel Number */
#define DMA_CCTRL3_LBCHNR_MASK 0xFC000000u

/*! @} */

/*! \defgroup DMA_CDBA3 Register DMA_CDBA3 - Channel Descriptor Base Address Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDBA3 0xC8
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDBA3 0x140600C8u

/*! Register Reset Value */
#define DMA_CDBA3_RST 0x00000000u

/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA3_CDBA_POS 0
/*! Field CDBA - Channel Descriptor Base Address */
#define DMA_CDBA3_CDBA_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_CDLEN3 Register DMA_CDLEN3 - channel descriptor length register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDLEN3 0xCC
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDLEN3 0x140600CCu

/*! Register Reset Value */
#define DMA_CDLEN3_RST 0x00000000u

/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN3_CDLEN_POS 0
/*! Field CDLEN - Channel Descriptor Length */
#define DMA_CDLEN3_CDLEN_MASK 0xFFFu

/*! @} */

/*! \defgroup DMA_CIS3 Register DMA_CIS3 - channel interrupt status register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIS3 0xD0
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIS3 0x140600D0u

/*! Register Reset Value */
#define DMA_CIS3_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS3_EOP_POS 1
/*! Field EOP - End of Packet Interrupt */
#define DMA_CIS3_EOP_MASK 0x2u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS3_EOP_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS3_EOP_INTERRUPT_OR_RESET 0x1

/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS3_DUR_POS 2
/*! Field DUR - Descriptor Under-Run Interrupt */
#define DMA_CIS3_DUR_MASK 0x4u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS3_DUR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS3_DUR_INTERRUPT_OR_RESET 0x1

/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS3_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt */
#define DMA_CIS3_DESCPT_MASK 0x8u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS3_DESCPT_NO_INTERRUPT 0x0
/*! Constant INTERRUPTOR_RESET - INTERRUPTOR_RESET */
#define CONST_DMA_CIS3_DESCPT_INTERRUPTOR_RESET 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS3_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIS3_CHOFF_MASK 0x10u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS3_CHOFF_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS3_CHOFF_INTERRUPT_OR_RESET 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS3_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIS3_RDERR_MASK 0x20u
/*! Constant NO_INTERRUPT - NO_INTERRUPT */
#define CONST_DMA_CIS3_RDERR_NO_INTERRUPT 0x0
/*! Constant INTERRUPT_OR_RESET - INTERRUPT_OR_RESET */
#define CONST_DMA_CIS3_RDERR_INTERRUPT_OR_RESET 0x1

/*! @} */

/*! \defgroup DMA_CIE3 Register DMA_CIE3 - channel interrupt enable register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CIE3 0xD4
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CIE3 0x140600D4u

/*! Register Reset Value */
#define DMA_CIE3_RST 0x00000000u

/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE3_EOP_POS 1
/*! Field EOP - End of Packet Interrupt Enable */
#define DMA_CIE3_EOP_MASK 0x2u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE3_EOP_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE3_EOP_ENABLED 0x1

/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE3_DUR_POS 2
/*! Field DUR - Descriptor Under Run Interrupt Enable */
#define DMA_CIE3_DUR_MASK 0x4u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE3_DUR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE3_DUR_ENABLED 0x1

/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE3_DESCPT_POS 3
/*! Field DESCPT - Descriptor Complete Interrupt Enable */
#define DMA_CIE3_DESCPT_MASK 0x8u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE3_DESCPT_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE3_DESCPT_ENABLED 0x1

/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE3_CHOFF_POS 4
/*! Field CHOFF - Channel Off Interrupt */
#define DMA_CIE3_CHOFF_MASK 0x10u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE3_CHOFF_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE3_CHOFF_ENABLED 0x1

/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE3_RDERR_POS 5
/*! Field RDERR - SAI Read Error Interrupt */
#define DMA_CIE3_RDERR_MASK 0x20u
/*! Constant DISABLED - DISABLED */
#define CONST_DMA_CIE3_RDERR_DISABLED 0x0
/*! Constant ENABLED - ENABLED */
#define CONST_DMA_CIE3_RDERR_ENABLED 0x1

/*! @} */

/*! \defgroup DMA_CDPTNRD3 Register DMA_CDPTNRD3 - DMA Current Descriptor Pointer Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_CDPTNRD3 0xDC
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_CDPTNRD3 0x140600DCu

/*! Register Reset Value */
#define DMA_CDPTNRD3_RST 0x00000000u

/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD3_CDPNTR_POS 0
/*! Field CDPNTR - Current Descriptor Pointer */
#define DMA_CDPTNRD3_CDPNTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_PS3 Register DMA_PS3 - Port Select 3 Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PS3 0xE0
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PS3 0x140600E0u

/*! Register Reset Value */
#define DMA_PS3_RST 0x00000000u

/*! Field PS - Port Selection */
#define DMA_PS3_PS_POS 0
/*! Field PS - Port Selection */
#define DMA_PS3_PS_MASK 0xFu

/*! @} */

/*! \defgroup DMA_PCTRL3 Register DMA_PCTRL3 - Port control 3 register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PCTRL3 0xE4
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_PCTRL3 0x140600E4u

/*! Register Reset Value */
#define DMA_PCTRL3_RST 0x00001014u

/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL3_RXBL16_POS 0
/*! Field RXBL16 - Burst Length for RX Burst of 16 */
#define DMA_PCTRL3_RXBL16_MASK 0x1u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL3_RXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL3_RXBL16_B16 0x1

/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL3_TXBL16_POS 1
/*! Field TXBL16 - Burst Length for TX Burst of 16 */
#define DMA_PCTRL3_TXBL16_MASK 0x2u
/*! Constant NB - not burst of 16 */
#define CONST_DMA_PCTRL3_TXBL16_NB 0x0
/*! Constant B16 - burst of 16 */
#define CONST_DMA_PCTRL3_TXBL16_B16 0x1

/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL3_RXBL_POS 2
/*! Field RXBL - Burst Length for Receive Direction */
#define DMA_PCTRL3_RXBL_MASK 0xCu
/*! Constant WORDS2 - WORDS2 */
#define CONST_DMA_PCTRL3_RXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL3_RXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL3_RXBL_WORDS8 0x3

/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL3_TXBL_POS 4
/*! Field TXBL - Burst Length for Transmit Direction */
#define DMA_PCTRL3_TXBL_MASK 0x30u
/*! Constant WORDS2 - 2 WORDS */
#define CONST_DMA_PCTRL3_TXBL_WORDS2 0x1
/*! Constant WORDS4 - 4 WORDS */
#define CONST_DMA_PCTRL3_TXBL_WORDS4 0x2
/*! Constant WORDS8 - 8 WORDS */
#define CONST_DMA_PCTRL3_TXBL_WORDS8 0x3

/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL3_PDEN_POS 6
/*! Field PDEN - Packet Drop Enable */
#define DMA_PCTRL3_PDEN_MASK 0x40u
/*! Constant DISABLE - DISABLE */
#define CONST_DMA_PCTRL3_PDEN_DISABLE 0x0
/*! Constant ENABLE - ENABLE */
#define CONST_DMA_PCTRL3_PDEN_ENABLE 0x1

/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL3_RXENDI_POS 8
/*! Field RXENDI - Endianness for Receive Direction */
#define DMA_PCTRL3_RXENDI_MASK 0x300u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL3_RXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL3_RXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL3_RXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL3_RXENDI_B0_B1_B2_B3 0x3

/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL3_TXENDI_POS 10
/*! Field TXENDI - Endianness for Transmit Direction */
#define DMA_PCTRL3_TXENDI_MASK 0xC00u
/*! Constant B3_B2_B1_B0 - B3_B2_B1_B0 */
#define CONST_DMA_PCTRL3_TXENDI_B3_B2_B1_B0 0x0
/*! Constant B2_B3_B0_B1 - B2_B3_B0_B1 */
#define CONST_DMA_PCTRL3_TXENDI_B2_B3_B0_B1 0x1
/*! Constant B1_B0_B3_B2 - B1_B0_B3_B2 */
#define CONST_DMA_PCTRL3_TXENDI_B1_B0_B3_B2 0x2
/*! Constant B0_B1_B2_B3 - B0_B1_B2_B3 */
#define CONST_DMA_PCTRL3_TXENDI_B0_B1_B2_B3 0x3

/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL3_TXWGT_POS 12
/*! Field TXWGT - Port Weight for Transmit Direction */
#define DMA_PCTRL3_TXWGT_MASK 0x7000u

/*! Field GPC - General Purpose Control */
#define DMA_PCTRL3_GPC_POS 16
/*! Field GPC - General Purpose Control */
#define DMA_PCTRL3_GPC_MASK 0x10000u
/*! Constant NO_ACTION - NO_ACTION */
#define CONST_DMA_PCTRL3_GPC_NO_ACTION 0x0
/*! Constant FLUSH_MEMCOPY - FLUSH_MEMCOPY */
#define CONST_DMA_PCTRL3_GPC_FLUSH_MEMCOPY 0x1

/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL3_DBG_P2D_CLS_POS 17
/*! Field DBG_P2D_CLS - Debug infor P2D Class Information */
#define DMA_PCTRL3_DBG_P2D_CLS_MASK 0x1E0000u

/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL3_DBG_P2D_ACK_POS 21
/*! Field DBG_P2D_ACK - Debug infor P2D DMA ACK */
#define DMA_PCTRL3_DBG_P2D_ACK_MASK 0x200000u

/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL3_DBG_D2P_CLS_POS 22
/*! Field DBG_D2P_CLS - Debug D2P Class Information */
#define DMA_PCTRL3_DBG_D2P_CLS_MASK 0x3C00000u

/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL3_DBG_D2P_ACK_POS 26
/*! Field DBG_D2P_ACK - Debug D2P DMA ACK */
#define DMA_PCTRL3_DBG_D2P_ACK_MASK 0x4000000u

/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL3_DBG_P2D_PREQ_POS 27
/*! Field DBG_P2D_PREQ - Debug P2D Peripheral Request */
#define DMA_PCTRL3_DBG_P2D_PREQ_MASK 0x8000000u

/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL3_DBG_D2P_PREQ_POS 28
/*! Field DBG_D2P_PREQ - Debug D2P Peripheral Request */
#define DMA_PCTRL3_DBG_D2P_PREQ_MASK 0x10000000u

/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL3_DBG_P2D_RME_POS 29
/*! Field DBG_P2D_RME - Debug P2D RME */
#define DMA_PCTRL3_DBG_P2D_RME_MASK 0x20000000u

/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL3_DBG_D2P_XME_POS 30
/*! Field DBG_D2P_XME - Debug D2P XME */
#define DMA_PCTRL3_DBG_D2P_XME_MASK 0x40000000u

/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL3_DBG_P2D_JMB_POS 31
/*! Field DBG_P2D_JMB - Debug P2D Jumbo set */
#define DMA_PCTRL3_DBG_P2D_JMB_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_IRNEN1 Register DMA_IRNEN1 - higher 32 channel (channel 32~ 63) Interrupt enable register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_IRNEN1 0xE8
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_IRNEN1 0x140600E8u

/*! Register Reset Value */
#define DMA_IRNEN1_RST 0x00000000u

/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNEN1_CH0_POS 0
/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNEN1_CH0_MASK 0x1u

/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNEN1_CH1_POS 1
/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNEN1_CH1_MASK 0x2u

/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNEN1_CH2_POS 2
/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNEN1_CH2_MASK 0x4u

/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNEN1_CH3_POS 3
/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNEN1_CH3_MASK 0x8u

/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNEN1_CH4_POS 4
/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNEN1_CH4_MASK 0x10u

/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNEN1_CH5_POS 5
/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNEN1_CH5_MASK 0x20u

/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNEN1_CH6_POS 6
/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNEN1_CH6_MASK 0x40u

/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNEN1_CH7_POS 7
/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNEN1_CH7_MASK 0x80u

/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNEN1_CH8_POS 8
/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNEN1_CH8_MASK 0x100u

/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNEN1_CH9_POS 9
/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNEN1_CH9_MASK 0x200u

/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNEN1_CH10_POS 10
/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNEN1_CH10_MASK 0x400u

/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNEN1_CH11_POS 11
/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNEN1_CH11_MASK 0x800u

/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNEN1_CH12_POS 12
/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNEN1_CH12_MASK 0x1000u

/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNEN1_CH13_POS 13
/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNEN1_CH13_MASK 0x2000u

/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNEN1_CH14_POS 14
/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNEN1_CH14_MASK 0x4000u

/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNEN1_CH15_POS 15
/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNEN1_CH15_MASK 0x8000u

/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNEN1_CH16_POS 16
/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNEN1_CH16_MASK 0x10000u

/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNEN1_CH17_POS 17
/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNEN1_CH17_MASK 0x20000u

/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNEN1_CH18_POS 18
/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNEN1_CH18_MASK 0x40000u

/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNEN1_CH19_POS 19
/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNEN1_CH19_MASK 0x80000u

/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNEN1_CH20_POS 20
/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNEN1_CH20_MASK 0x100000u

/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNEN1_CH21_POS 21
/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNEN1_CH21_MASK 0x200000u

/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNEN1_CH22_POS 22
/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNEN1_CH22_MASK 0x400000u

/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNEN1_CH23_POS 23
/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNEN1_CH23_MASK 0x800000u

/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNEN1_CH24_POS 24
/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNEN1_CH24_MASK 0x1000000u

/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNEN1_CH25_POS 25
/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNEN1_CH25_MASK 0x2000000u

/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNEN1_CH26_POS 26
/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNEN1_CH26_MASK 0x4000000u

/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNEN1_CH27_POS 27
/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNEN1_CH27_MASK 0x8000000u

/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNEN1_CH28_POS 28
/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNEN1_CH28_MASK 0x10000000u

/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNEN1_CH29_POS 29
/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNEN1_CH29_MASK 0x20000000u

/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNEN1_CH30_POS 30
/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNEN1_CH30_MASK 0x40000000u

/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNEN1_CH31_POS 31
/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNEN1_CH31_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_IRNCR1 Register DMA_IRNCR1 - higher 32 channel (channel 32~ 63) Interrupt control register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_IRNCR1 0xEC
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_IRNCR1 0x140600ECu

/*! Register Reset Value */
#define DMA_IRNCR1_RST 0x00000000u

/*! Field CH0 - Channel 0 Interrupt Request Enable */
#define DMA_IRNCR1_CH0_POS 0
/*! Field CH0 - Channel 0 Interrupt Request Enable */
#define DMA_IRNCR1_CH0_MASK 0x1u

/*! Field CH1 - Channel 1 Interrupt Request Enable */
#define DMA_IRNCR1_CH1_POS 1
/*! Field CH1 - Channel 1 Interrupt Request Enable */
#define DMA_IRNCR1_CH1_MASK 0x2u

/*! Field CH2 - Channel 2 Interrupt Request Enable */
#define DMA_IRNCR1_CH2_POS 2
/*! Field CH2 - Channel 2 Interrupt Request Enable */
#define DMA_IRNCR1_CH2_MASK 0x4u

/*! Field CH3 - Channel 3 Interrupt Request Enable */
#define DMA_IRNCR1_CH3_POS 3
/*! Field CH3 - Channel 3 Interrupt Request Enable */
#define DMA_IRNCR1_CH3_MASK 0x8u

/*! Field CH4 - Channel 4 Interrupt Request Enable */
#define DMA_IRNCR1_CH4_POS 4
/*! Field CH4 - Channel 4 Interrupt Request Enable */
#define DMA_IRNCR1_CH4_MASK 0x10u

/*! Field CH5 - Channel 5 Interrupt Request Enable */
#define DMA_IRNCR1_CH5_POS 5
/*! Field CH5 - Channel 5 Interrupt Request Enable */
#define DMA_IRNCR1_CH5_MASK 0x20u

/*! Field CH6 - Channel 6 Interrupt Request Enable */
#define DMA_IRNCR1_CH6_POS 6
/*! Field CH6 - Channel 6 Interrupt Request Enable */
#define DMA_IRNCR1_CH6_MASK 0x40u

/*! Field CH7 - Channel 7 Interrupt Request Enable */
#define DMA_IRNCR1_CH7_POS 7
/*! Field CH7 - Channel 7 Interrupt Request Enable */
#define DMA_IRNCR1_CH7_MASK 0x80u

/*! Field CH8 - Channel 8 Interrupt Request Enable */
#define DMA_IRNCR1_CH8_POS 8
/*! Field CH8 - Channel 8 Interrupt Request Enable */
#define DMA_IRNCR1_CH8_MASK 0x100u

/*! Field CH9 - Channel 9 Interrupt Request Enable */
#define DMA_IRNCR1_CH9_POS 9
/*! Field CH9 - Channel 9 Interrupt Request Enable */
#define DMA_IRNCR1_CH9_MASK 0x200u

/*! Field CH10 - Channel 10 Interrupt Request Enable */
#define DMA_IRNCR1_CH10_POS 10
/*! Field CH10 - Channel 10 Interrupt Request Enable */
#define DMA_IRNCR1_CH10_MASK 0x400u

/*! Field CH11 - Channel 11 Interrupt Request Enable */
#define DMA_IRNCR1_CH11_POS 11
/*! Field CH11 - Channel 11 Interrupt Request Enable */
#define DMA_IRNCR1_CH11_MASK 0x800u

/*! Field CH12 - Channel 12 Interrupt Request Enable */
#define DMA_IRNCR1_CH12_POS 12
/*! Field CH12 - Channel 12 Interrupt Request Enable */
#define DMA_IRNCR1_CH12_MASK 0x1000u

/*! Field CH13 - Channel 13 Interrupt Request Enable */
#define DMA_IRNCR1_CH13_POS 13
/*! Field CH13 - Channel 13 Interrupt Request Enable */
#define DMA_IRNCR1_CH13_MASK 0x2000u

/*! Field CH14 - CH14 */
#define DMA_IRNCR1_CH14_POS 14
/*! Field CH14 - CH14 */
#define DMA_IRNCR1_CH14_MASK 0x4000u

/*! Field CH15 - Channel 15 Interrupt Request Enable */
#define DMA_IRNCR1_CH15_POS 15
/*! Field CH15 - Channel 15 Interrupt Request Enable */
#define DMA_IRNCR1_CH15_MASK 0x8000u

/*! Field CH16 - Channel 16 Interrupt Request Enable */
#define DMA_IRNCR1_CH16_POS 16
/*! Field CH16 - Channel 16 Interrupt Request Enable */
#define DMA_IRNCR1_CH16_MASK 0x10000u

/*! Field CH17 - Channel 17 Interrupt Request Enable */
#define DMA_IRNCR1_CH17_POS 17
/*! Field CH17 - Channel 17 Interrupt Request Enable */
#define DMA_IRNCR1_CH17_MASK 0x20000u

/*! Field CH18 - Channel 18 Interrupt Request Enable */
#define DMA_IRNCR1_CH18_POS 18
/*! Field CH18 - Channel 18 Interrupt Request Enable */
#define DMA_IRNCR1_CH18_MASK 0x40000u

/*! Field CH19 - Channel 19 Interrupt Request Enable */
#define DMA_IRNCR1_CH19_POS 19
/*! Field CH19 - Channel 19 Interrupt Request Enable */
#define DMA_IRNCR1_CH19_MASK 0x80000u

/*! Field CH20 - Channel 20 Interrupt Request Enable */
#define DMA_IRNCR1_CH20_POS 20
/*! Field CH20 - Channel 20 Interrupt Request Enable */
#define DMA_IRNCR1_CH20_MASK 0x100000u

/*! Field CH21 - Channel 21 Interrupt Request Enable */
#define DMA_IRNCR1_CH21_POS 21
/*! Field CH21 - Channel 21 Interrupt Request Enable */
#define DMA_IRNCR1_CH21_MASK 0x200000u

/*! Field CH22 - Channel 22 Interrupt Request Enable */
#define DMA_IRNCR1_CH22_POS 22
/*! Field CH22 - Channel 22 Interrupt Request Enable */
#define DMA_IRNCR1_CH22_MASK 0x400000u

/*! Field CH23 - Channel 23 Interrupt Request Enable */
#define DMA_IRNCR1_CH23_POS 23
/*! Field CH23 - Channel 23 Interrupt Request Enable */
#define DMA_IRNCR1_CH23_MASK 0x800000u

/*! Field CH24 - Channel 24 Interrupt Request Enable */
#define DMA_IRNCR1_CH24_POS 24
/*! Field CH24 - Channel 24 Interrupt Request Enable */
#define DMA_IRNCR1_CH24_MASK 0x1000000u

/*! Field CH25 - Channel 25 Interrupt Request Enable */
#define DMA_IRNCR1_CH25_POS 25
/*! Field CH25 - Channel 25 Interrupt Request Enable */
#define DMA_IRNCR1_CH25_MASK 0x2000000u

/*! Field CH26 - Channel 26 Interrupt Request Enable */
#define DMA_IRNCR1_CH26_POS 26
/*! Field CH26 - Channel 26 Interrupt Request Enable */
#define DMA_IRNCR1_CH26_MASK 0x4000000u

/*! Field CH27 - Channel 27 Interrupt Request Enable */
#define DMA_IRNCR1_CH27_POS 27
/*! Field CH27 - Channel 27 Interrupt Request Enable */
#define DMA_IRNCR1_CH27_MASK 0x8000000u

/*! Field CH28 - Channel 28 Interrupt Request Enable */
#define DMA_IRNCR1_CH28_POS 28
/*! Field CH28 - Channel 28 Interrupt Request Enable */
#define DMA_IRNCR1_CH28_MASK 0x10000000u

/*! Field CH29 - Channel 29 Interrupt Request Enable */
#define DMA_IRNCR1_CH29_POS 29
/*! Field CH29 - Channel 29 Interrupt Request Enable */
#define DMA_IRNCR1_CH29_MASK 0x20000000u

/*! Field CH30 - Channel 30 Interrupt Request Enable */
#define DMA_IRNCR1_CH30_POS 30
/*! Field CH30 - Channel 30 Interrupt Request Enable */
#define DMA_IRNCR1_CH30_MASK 0x40000000u

/*! Field CH31 - Channel 31 Interrupt Request Enable */
#define DMA_IRNCR1_CH31_POS 31
/*! Field CH31 - Channel 31 Interrupt Request Enable */
#define DMA_IRNCR1_CH31_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_IRNICR1 Register DMA_IRNICR1 - higher 32 channel (channel 32~ 63) Interrupt Capture register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_IRNICR1 0xF0
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_IRNICR1 0x140600F0u

/*! Register Reset Value */
#define DMA_IRNICR1_RST 0x00000000u

/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNICR1_CH0_POS 0
/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNICR1_CH0_MASK 0x1u

/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNICR1_CH1_POS 1
/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNICR1_CH1_MASK 0x2u

/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNICR1_CH2_POS 2
/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNICR1_CH2_MASK 0x4u

/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNICR1_CH3_POS 3
/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNICR1_CH3_MASK 0x8u

/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNICR1_CH4_POS 4
/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNICR1_CH4_MASK 0x10u

/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNICR1_CH5_POS 5
/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNICR1_CH5_MASK 0x20u

/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNICR1_CH6_POS 6
/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNICR1_CH6_MASK 0x40u

/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNICR1_CH7_POS 7
/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNICR1_CH7_MASK 0x80u

/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNICR1_CH8_POS 8
/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNICR1_CH8_MASK 0x100u

/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNICR1_CH9_POS 9
/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNICR1_CH9_MASK 0x200u

/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNICR1_CH10_POS 10
/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNICR1_CH10_MASK 0x400u

/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNICR1_CH11_POS 11
/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNICR1_CH11_MASK 0x800u

/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNICR1_CH12_POS 12
/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNICR1_CH12_MASK 0x1000u

/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNICR1_CH13_POS 13
/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNICR1_CH13_MASK 0x2000u

/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNICR1_CH14_POS 14
/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNICR1_CH14_MASK 0x4000u

/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNICR1_CH15_POS 15
/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNICR1_CH15_MASK 0x8000u

/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNICR1_CH16_POS 16
/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNICR1_CH16_MASK 0x10000u

/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNICR1_CH17_POS 17
/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNICR1_CH17_MASK 0x20000u

/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNICR1_CH18_POS 18
/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNICR1_CH18_MASK 0x40000u

/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNICR1_CH19_POS 19
/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNICR1_CH19_MASK 0x80000u

/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNICR1_CH20_POS 20
/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNICR1_CH20_MASK 0x100000u

/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNICR1_CH21_POS 21
/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNICR1_CH21_MASK 0x200000u

/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNICR1_CH22_POS 22
/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNICR1_CH22_MASK 0x400000u

/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNICR1_CH23_POS 23
/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNICR1_CH23_MASK 0x800000u

/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNICR1_CH24_POS 24
/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNICR1_CH24_MASK 0x1000000u

/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNICR1_CH25_POS 25
/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNICR1_CH25_MASK 0x2000000u

/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNICR1_CH26_POS 26
/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNICR1_CH26_MASK 0x4000000u

/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNICR1_CH27_POS 27
/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNICR1_CH27_MASK 0x8000000u

/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNICR1_CH28_POS 28
/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNICR1_CH28_MASK 0x10000000u

/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNICR1_CH29_POS 29
/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNICR1_CH29_MASK 0x20000000u

/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNICR1_CH30_POS 30
/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNICR1_CH30_MASK 0x40000000u

/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNICR1_CH31_POS 31
/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNICR1_CH31_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_IRNEN Register DMA_IRNEN - lower 32 channel (channel 0 ~31) interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_IRNEN 0xF4
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_IRNEN 0x140600F4u

/*! Register Reset Value */
#define DMA_IRNEN_RST 0x00000000u

/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNEN_CH0_POS 0
/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNEN_CH0_MASK 0x1u

/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNEN_CH1_POS 1
/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNEN_CH1_MASK 0x2u

/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNEN_CH2_POS 2
/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNEN_CH2_MASK 0x4u

/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNEN_CH3_POS 3
/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNEN_CH3_MASK 0x8u

/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNEN_CH4_POS 4
/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNEN_CH4_MASK 0x10u

/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNEN_CH5_POS 5
/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNEN_CH5_MASK 0x20u

/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNEN_CH6_POS 6
/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNEN_CH6_MASK 0x40u

/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNEN_CH7_POS 7
/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNEN_CH7_MASK 0x80u

/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNEN_CH8_POS 8
/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNEN_CH8_MASK 0x100u

/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNEN_CH9_POS 9
/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNEN_CH9_MASK 0x200u

/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNEN_CH10_POS 10
/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNEN_CH10_MASK 0x400u

/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNEN_CH11_POS 11
/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNEN_CH11_MASK 0x800u

/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNEN_CH12_POS 12
/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNEN_CH12_MASK 0x1000u

/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNEN_CH13_POS 13
/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNEN_CH13_MASK 0x2000u

/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNEN_CH14_POS 14
/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNEN_CH14_MASK 0x4000u

/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNEN_CH15_POS 15
/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNEN_CH15_MASK 0x8000u

/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNEN_CH16_POS 16
/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNEN_CH16_MASK 0x10000u

/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNEN_CH17_POS 17
/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNEN_CH17_MASK 0x20000u

/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNEN_CH18_POS 18
/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNEN_CH18_MASK 0x40000u

/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNEN_CH19_POS 19
/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNEN_CH19_MASK 0x80000u

/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNEN_CH20_POS 20
/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNEN_CH20_MASK 0x100000u

/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNEN_CH21_POS 21
/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNEN_CH21_MASK 0x200000u

/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNEN_CH22_POS 22
/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNEN_CH22_MASK 0x400000u

/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNEN_CH23_POS 23
/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNEN_CH23_MASK 0x800000u

/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNEN_CH24_POS 24
/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNEN_CH24_MASK 0x1000000u

/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNEN_CH25_POS 25
/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNEN_CH25_MASK 0x2000000u

/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNEN_CH26_POS 26
/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNEN_CH26_MASK 0x4000000u

/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNEN_CH27_POS 27
/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNEN_CH27_MASK 0x8000000u

/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNEN_CH28_POS 28
/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNEN_CH28_MASK 0x10000000u

/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNEN_CH29_POS 29
/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNEN_CH29_MASK 0x20000000u

/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNEN_CH30_POS 30
/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNEN_CH30_MASK 0x40000000u

/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNEN_CH31_POS 31
/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNEN_CH31_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_IRNCR Register DMA_IRNCR - lower 32 channel (channel 0 ~31) interrupt Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_IRNCR 0xF8
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_IRNCR 0x140600F8u

/*! Register Reset Value */
#define DMA_IRNCR_RST 0x00000000u

/*! Field CH0 - Channel 0 Interrupt Request Enable */
#define DMA_IRNCR_CH0_POS 0
/*! Field CH0 - Channel 0 Interrupt Request Enable */
#define DMA_IRNCR_CH0_MASK 0x1u

/*! Field CH1 - Channel 1 Interrupt Request Enable */
#define DMA_IRNCR_CH1_POS 1
/*! Field CH1 - Channel 1 Interrupt Request Enable */
#define DMA_IRNCR_CH1_MASK 0x2u

/*! Field CH2 - Channel 2 Interrupt Request Enable */
#define DMA_IRNCR_CH2_POS 2
/*! Field CH2 - Channel 2 Interrupt Request Enable */
#define DMA_IRNCR_CH2_MASK 0x4u

/*! Field CH3 - Channel 3 Interrupt Request Enable */
#define DMA_IRNCR_CH3_POS 3
/*! Field CH3 - Channel 3 Interrupt Request Enable */
#define DMA_IRNCR_CH3_MASK 0x8u

/*! Field CH4 - Channel 4 Interrupt Request Enable */
#define DMA_IRNCR_CH4_POS 4
/*! Field CH4 - Channel 4 Interrupt Request Enable */
#define DMA_IRNCR_CH4_MASK 0x10u

/*! Field CH5 - Channel 5 Interrupt Request Enable */
#define DMA_IRNCR_CH5_POS 5
/*! Field CH5 - Channel 5 Interrupt Request Enable */
#define DMA_IRNCR_CH5_MASK 0x20u

/*! Field CH6 - Channel 6 Interrupt Request Enable */
#define DMA_IRNCR_CH6_POS 6
/*! Field CH6 - Channel 6 Interrupt Request Enable */
#define DMA_IRNCR_CH6_MASK 0x40u

/*! Field CH7 - Channel 7 Interrupt Request Enable */
#define DMA_IRNCR_CH7_POS 7
/*! Field CH7 - Channel 7 Interrupt Request Enable */
#define DMA_IRNCR_CH7_MASK 0x80u

/*! Field CH8 - Channel 8 Interrupt Request Enable */
#define DMA_IRNCR_CH8_POS 8
/*! Field CH8 - Channel 8 Interrupt Request Enable */
#define DMA_IRNCR_CH8_MASK 0x100u

/*! Field CH9 - Channel 9 Interrupt Request Enable */
#define DMA_IRNCR_CH9_POS 9
/*! Field CH9 - Channel 9 Interrupt Request Enable */
#define DMA_IRNCR_CH9_MASK 0x200u

/*! Field CH10 - Channel 10 Interrupt Request Enable */
#define DMA_IRNCR_CH10_POS 10
/*! Field CH10 - Channel 10 Interrupt Request Enable */
#define DMA_IRNCR_CH10_MASK 0x400u

/*! Field CH11 - Channel 11 Interrupt Request Enable */
#define DMA_IRNCR_CH11_POS 11
/*! Field CH11 - Channel 11 Interrupt Request Enable */
#define DMA_IRNCR_CH11_MASK 0x800u

/*! Field CH12 - Channel 12 Interrupt Request Enable */
#define DMA_IRNCR_CH12_POS 12
/*! Field CH12 - Channel 12 Interrupt Request Enable */
#define DMA_IRNCR_CH12_MASK 0x1000u

/*! Field CH13 - Channel 13 Interrupt Request Enable */
#define DMA_IRNCR_CH13_POS 13
/*! Field CH13 - Channel 13 Interrupt Request Enable */
#define DMA_IRNCR_CH13_MASK 0x2000u

/*! Field CH14 - CH14 */
#define DMA_IRNCR_CH14_POS 14
/*! Field CH14 - CH14 */
#define DMA_IRNCR_CH14_MASK 0x4000u

/*! Field CH15 - Channel 15 Interrupt Request Enable */
#define DMA_IRNCR_CH15_POS 15
/*! Field CH15 - Channel 15 Interrupt Request Enable */
#define DMA_IRNCR_CH15_MASK 0x8000u

/*! Field CH16 - Channel 16 Interrupt Request Enable */
#define DMA_IRNCR_CH16_POS 16
/*! Field CH16 - Channel 16 Interrupt Request Enable */
#define DMA_IRNCR_CH16_MASK 0x10000u

/*! Field CH17 - Channel 17 Interrupt Request Enable */
#define DMA_IRNCR_CH17_POS 17
/*! Field CH17 - Channel 17 Interrupt Request Enable */
#define DMA_IRNCR_CH17_MASK 0x20000u

/*! Field CH18 - Channel 18 Interrupt Request Enable */
#define DMA_IRNCR_CH18_POS 18
/*! Field CH18 - Channel 18 Interrupt Request Enable */
#define DMA_IRNCR_CH18_MASK 0x40000u

/*! Field CH19 - Channel 19 Interrupt Request Enable */
#define DMA_IRNCR_CH19_POS 19
/*! Field CH19 - Channel 19 Interrupt Request Enable */
#define DMA_IRNCR_CH19_MASK 0x80000u

/*! Field CH20 - Channel 20 Interrupt Request Enable */
#define DMA_IRNCR_CH20_POS 20
/*! Field CH20 - Channel 20 Interrupt Request Enable */
#define DMA_IRNCR_CH20_MASK 0x100000u

/*! Field CH21 - Channel 21 Interrupt Request Enable */
#define DMA_IRNCR_CH21_POS 21
/*! Field CH21 - Channel 21 Interrupt Request Enable */
#define DMA_IRNCR_CH21_MASK 0x200000u

/*! Field CH22 - Channel 22 Interrupt Request Enable */
#define DMA_IRNCR_CH22_POS 22
/*! Field CH22 - Channel 22 Interrupt Request Enable */
#define DMA_IRNCR_CH22_MASK 0x400000u

/*! Field CH23 - Channel 23 Interrupt Request Enable */
#define DMA_IRNCR_CH23_POS 23
/*! Field CH23 - Channel 23 Interrupt Request Enable */
#define DMA_IRNCR_CH23_MASK 0x800000u

/*! Field CH24 - Channel 24 Interrupt Request Enable */
#define DMA_IRNCR_CH24_POS 24
/*! Field CH24 - Channel 24 Interrupt Request Enable */
#define DMA_IRNCR_CH24_MASK 0x1000000u

/*! Field CH25 - Channel 25 Interrupt Request Enable */
#define DMA_IRNCR_CH25_POS 25
/*! Field CH25 - Channel 25 Interrupt Request Enable */
#define DMA_IRNCR_CH25_MASK 0x2000000u

/*! Field CH26 - Channel 26 Interrupt Request Enable */
#define DMA_IRNCR_CH26_POS 26
/*! Field CH26 - Channel 26 Interrupt Request Enable */
#define DMA_IRNCR_CH26_MASK 0x4000000u

/*! Field CH27 - Channel 27 Interrupt Request Enable */
#define DMA_IRNCR_CH27_POS 27
/*! Field CH27 - Channel 27 Interrupt Request Enable */
#define DMA_IRNCR_CH27_MASK 0x8000000u

/*! Field CH28 - Channel 28 Interrupt Request Enable */
#define DMA_IRNCR_CH28_POS 28
/*! Field CH28 - Channel 28 Interrupt Request Enable */
#define DMA_IRNCR_CH28_MASK 0x10000000u

/*! Field CH29 - Channel 29 Interrupt Request Enable */
#define DMA_IRNCR_CH29_POS 29
/*! Field CH29 - Channel 29 Interrupt Request Enable */
#define DMA_IRNCR_CH29_MASK 0x20000000u

/*! Field CH30 - Channel 30 Interrupt Request Enable */
#define DMA_IRNCR_CH30_POS 30
/*! Field CH30 - Channel 30 Interrupt Request Enable */
#define DMA_IRNCR_CH30_MASK 0x40000000u

/*! Field CH31 - Channel 31 Interrupt Request Enable */
#define DMA_IRNCR_CH31_POS 31
/*! Field CH31 - Channel 31 Interrupt Request Enable */
#define DMA_IRNCR_CH31_MASK 0x80000000u

/*! @} */

/*! \defgroup DMA_IRNICR Register DMA_IRNICR - lower 32 channel (channel 0 ~31) interrupt Capture Register */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_IRNICR 0xFC
/*! Register Offset (absolute) for 1st Instance ACA_DMA */
#define ACA_DMA_DMA_IRNICR 0x140600FCu

/*! Register Reset Value */
#define DMA_IRNICR_RST 0x00000000u

/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNICR_CH0_POS 0
/*! Field CH0 - Channel 0 Interrupt Request */
#define DMA_IRNICR_CH0_MASK 0x1u

/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNICR_CH1_POS 1
/*! Field CH1 - Channel 1 Interrupt Request */
#define DMA_IRNICR_CH1_MASK 0x2u

/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNICR_CH2_POS 2
/*! Field CH2 - Channel 2 Interrupt Request */
#define DMA_IRNICR_CH2_MASK 0x4u

/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNICR_CH3_POS 3
/*! Field CH3 - Channel 3 Interrupt Request */
#define DMA_IRNICR_CH3_MASK 0x8u

/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNICR_CH4_POS 4
/*! Field CH4 - Channel 4 Interrupt Request */
#define DMA_IRNICR_CH4_MASK 0x10u

/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNICR_CH5_POS 5
/*! Field CH5 - Channel 5 Interrupt Request */
#define DMA_IRNICR_CH5_MASK 0x20u

/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNICR_CH6_POS 6
/*! Field CH6 - Channel 6 Interrupt Request */
#define DMA_IRNICR_CH6_MASK 0x40u

/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNICR_CH7_POS 7
/*! Field CH7 - Channel 7 Interrupt Request */
#define DMA_IRNICR_CH7_MASK 0x80u

/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNICR_CH8_POS 8
/*! Field CH8 - Channel 8 Interrupt Request */
#define DMA_IRNICR_CH8_MASK 0x100u

/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNICR_CH9_POS 9
/*! Field CH9 - Channel 9 Interrupt Request */
#define DMA_IRNICR_CH9_MASK 0x200u

/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNICR_CH10_POS 10
/*! Field CH10 - Channel 10 Interrupt Request */
#define DMA_IRNICR_CH10_MASK 0x400u

/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNICR_CH11_POS 11
/*! Field CH11 - Channel 11 Interrupt Request */
#define DMA_IRNICR_CH11_MASK 0x800u

/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNICR_CH12_POS 12
/*! Field CH12 - Channel 12 Interrupt Request */
#define DMA_IRNICR_CH12_MASK 0x1000u

/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNICR_CH13_POS 13
/*! Field CH13 - Channel 13 Interrupt Request */
#define DMA_IRNICR_CH13_MASK 0x2000u

/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNICR_CH14_POS 14
/*! Field CH14 - Channel 14 Interrupt Request */
#define DMA_IRNICR_CH14_MASK 0x4000u

/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNICR_CH15_POS 15
/*! Field CH15 - Channel 15 Interrupt Request */
#define DMA_IRNICR_CH15_MASK 0x8000u

/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNICR_CH16_POS 16
/*! Field CH16 - Channel 16 Interrupt Request */
#define DMA_IRNICR_CH16_MASK 0x10000u

/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNICR_CH17_POS 17
/*! Field CH17 - Channel 17 Interrupt Request */
#define DMA_IRNICR_CH17_MASK 0x20000u

/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNICR_CH18_POS 18
/*! Field CH18 - Channel 18 Interrupt Request */
#define DMA_IRNICR_CH18_MASK 0x40000u

/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNICR_CH19_POS 19
/*! Field CH19 - Channel 19 Interrupt Request */
#define DMA_IRNICR_CH19_MASK 0x80000u

/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNICR_CH20_POS 20
/*! Field CH20 - Channel 20 Interrupt Request */
#define DMA_IRNICR_CH20_MASK 0x100000u

/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNICR_CH21_POS 21
/*! Field CH21 - Channel 21 Interrupt Request */
#define DMA_IRNICR_CH21_MASK 0x200000u

/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNICR_CH22_POS 22
/*! Field CH22 - Channel 22 Interrupt Request */
#define DMA_IRNICR_CH22_MASK 0x400000u

/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNICR_CH23_POS 23
/*! Field CH23 - Channel 23 Interrupt Request */
#define DMA_IRNICR_CH23_MASK 0x800000u

/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNICR_CH24_POS 24
/*! Field CH24 - Channel 24 Interrupt Request */
#define DMA_IRNICR_CH24_MASK 0x1000000u

/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNICR_CH25_POS 25
/*! Field CH25 - Channel 25 Interrupt Request */
#define DMA_IRNICR_CH25_MASK 0x2000000u

/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNICR_CH26_POS 26
/*! Field CH26 - Channel 26 Interrupt Request */
#define DMA_IRNICR_CH26_MASK 0x4000000u

/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNICR_CH27_POS 27
/*! Field CH27 - Channel 27 Interrupt Request */
#define DMA_IRNICR_CH27_MASK 0x8000000u

/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNICR_CH28_POS 28
/*! Field CH28 - Channel 28 Interrupt Request */
#define DMA_IRNICR_CH28_MASK 0x10000000u

/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNICR_CH29_POS 29
/*! Field CH29 - Channel 29 Interrupt Request */
#define DMA_IRNICR_CH29_MASK 0x20000000u

/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNICR_CH30_POS 30
/*! Field CH30 - Channel 30 Interrupt Request */
#define DMA_IRNICR_CH30_MASK 0x40000000u

/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNICR_CH31_POS 31
/*! Field CH31 - Channel 31 Interrupt Request */
#define DMA_IRNICR_CH31_MASK 0x80000000u

/*! @} */

/*! @} */

#endif
