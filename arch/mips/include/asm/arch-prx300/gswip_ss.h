/* Copyright (c) 2017, Intel Corporation.
 *
 * GSWIP_SS header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _GSWIP_SS_H
#define _GSWIP_SS_H

/*! \defgroup GSWIP_SS Register File GSWIP_SS - GSWIP SS Top Register Description */
/*! @{ */

/*! Base Address of GSWIP_SS */
#define GSWIP_SS_MODULE_BASE 0x18440000u

/*! \defgroup GSWIP_CFG Register GSWIP_CFG - GSWIP Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSWIP_CFG 0x0
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_GSWIP_CFG 0x18440000u

/*! Register Reset Value */
#define GSWIP_CFG_RST 0x0000u

/*! Field CORE_SWRES - GSWIP Core Software Reset */
#define GSWIP_CFG_CORE_SWRES_POS 0
/*! Field CORE_SWRES - GSWIP Core Software Reset */
#define GSWIP_CFG_CORE_SWRES_MASK 0x1u
/*! Constant OFF - OFF */
#define CONST_GSWIP_CFG_CORE_SWRES_OFF 0x0
/*! Constant ON - ON */
#define CONST_GSWIP_CFG_CORE_SWRES_ON 0x1

/*! Field CORE_HWRES - GSWIP Core Hardware Reset */
#define GSWIP_CFG_CORE_HWRES_POS 1
/*! Field CORE_HWRES - GSWIP Core Hardware Reset */
#define GSWIP_CFG_CORE_HWRES_MASK 0x2u
/*! Constant OFF - OFF */
#define CONST_GSWIP_CFG_CORE_HWRES_OFF 0x0
/*! Constant ON - ON */
#define CONST_GSWIP_CFG_CORE_HWRES_ON 0x1

/*! Field CORE_SE - Switch Core Enable */
#define GSWIP_CFG_CORE_SE_POS 15
/*! Field CORE_SE - Switch Core Enable */
#define GSWIP_CFG_CORE_SE_MASK 0x8000u
/*! Constant DISABLE - Disable */
#define CONST_GSWIP_CFG_CORE_SE_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_GSWIP_CFG_CORE_SE_ENABLE 0x1

/*! @} */

/*! \defgroup MAC_RST_CTRL Register MAC_RST_CTRL - MAC Reset Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_RST_CTRL 0x4
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC_RST_CTRL 0x18440004u

/*! Register Reset Value */
#define MAC_RST_CTRL_RST 0x0000u

/*! Field XGMAC2_RES - XGMAC 2 Hardware Reset */
#define MAC_RST_CTRL_XGMAC2_RES_POS 0
/*! Field XGMAC2_RES - XGMAC 2 Hardware Reset */
#define MAC_RST_CTRL_XGMAC2_RES_MASK 0x1u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_XGMAC2_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_XGMAC2_RES_ON 0x1

/*! Field XGMAC3_RES - XGMAC 3 Hardware Reset */
#define MAC_RST_CTRL_XGMAC3_RES_POS 1
/*! Field XGMAC3_RES - XGMAC 3 Hardware Reset */
#define MAC_RST_CTRL_XGMAC3_RES_MASK 0x2u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_XGMAC3_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_XGMAC3_RES_ON 0x1

/*! Field XGMAC4_RES - XGMAC 4 Hardware Reset */
#define MAC_RST_CTRL_XGMAC4_RES_POS 2
/*! Field XGMAC4_RES - XGMAC 4 Hardware Reset */
#define MAC_RST_CTRL_XGMAC4_RES_MASK 0x4u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_XGMAC4_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_XGMAC4_RES_ON 0x1

/*! Field LMAC2_RES - Legacy MAC 2 Hardware Reset */
#define MAC_RST_CTRL_LMAC2_RES_POS 3
/*! Field LMAC2_RES - Legacy MAC 2 Hardware Reset */
#define MAC_RST_CTRL_LMAC2_RES_MASK 0x8u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_LMAC2_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_LMAC2_RES_ON 0x1

/*! Field LMAC3_RES - Legacy MAC 3 Hardware Reset */
#define MAC_RST_CTRL_LMAC3_RES_POS 4
/*! Field LMAC3_RES - Legacy MAC 3 Hardware Reset */
#define MAC_RST_CTRL_LMAC3_RES_MASK 0x10u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_LMAC3_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_LMAC3_RES_ON 0x1

/*! Field LMAC4_RES - Legacy GMAC 4 Hardware Reset */
#define MAC_RST_CTRL_LMAC4_RES_POS 5
/*! Field LMAC4_RES - Legacy GMAC 4 Hardware Reset */
#define MAC_RST_CTRL_LMAC4_RES_MASK 0x20u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_LMAC4_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_LMAC4_RES_ON 0x1

/*! Field ADAP2_RES - Adaption 2 Hardware Reset */
#define MAC_RST_CTRL_ADAP2_RES_POS 6
/*! Field ADAP2_RES - Adaption 2 Hardware Reset */
#define MAC_RST_CTRL_ADAP2_RES_MASK 0x40u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_ADAP2_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_ADAP2_RES_ON 0x1

/*! Field ADAP3_RES - Adaption 3 Hardware Reset */
#define MAC_RST_CTRL_ADAP3_RES_POS 7
/*! Field ADAP3_RES - Adaption 3 Hardware Reset */
#define MAC_RST_CTRL_ADAP3_RES_MASK 0x80u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_ADAP3_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_ADAP3_RES_ON 0x1

/*! Field ADAP4_RES - Adaption 4 Hardware Reset */
#define MAC_RST_CTRL_ADAP4_RES_POS 8
/*! Field ADAP4_RES - Adaption 4 Hardware Reset */
#define MAC_RST_CTRL_ADAP4_RES_MASK 0x100u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_ADAP4_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_ADAP4_RES_ON 0x1

/*! Field MACSEC_RES - MACsec Hardware Reset */
#define MAC_RST_CTRL_MACSEC_RES_POS 15
/*! Field MACSEC_RES - MACsec Hardware Reset */
#define MAC_RST_CTRL_MACSEC_RES_MASK 0x8000u
/*! Constant OFF - OFF */
#define CONST_MAC_RST_CTRL_MACSEC_RES_OFF 0x0
/*! Constant ON - ON */
#define CONST_MAC_RST_CTRL_MACSEC_RES_ON 0x1

/*! @} */

/*! \defgroup MACSEC_ENABLE Register MACSEC_ENABLE - MACsec enable register */
/*! @{ */

/*! Register Offset (relative) */
#define MACSEC_ENABLE 0x8
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MACSEC_ENABLE 0x18440008u

/*! Register Reset Value */
#define MACSEC_ENABLE_RST 0x0000u

/*! Field SEL - MACsec Connection */
#define MACSEC_ENABLE_SEL_POS 0
/*! Field SEL - MACsec Connection */
#define MACSEC_ENABLE_SEL_MASK 0xFu
/*! Constant DISABLE - Disable */
#define CONST_MACSEC_ENABLE_SEL_DISABLE 0x0
/*! Constant MAC2 - MAC2 */
#define CONST_MACSEC_ENABLE_SEL_MAC2 0x2
/*! Constant MAC3 - MAC3 */
#define CONST_MACSEC_ENABLE_SEL_MAC3 0x3
/*! Constant MAC4 - MAC4 */
#define CONST_MACSEC_ENABLE_SEL_MAC4 0x4

/*! @} */

/*! \defgroup MAC_ENABLE Register MAC_ENABLE - MAC enable register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_ENABLE 0xC
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC_ENABLE 0x1844000Cu

/*! Register Reset Value */
#define MAC_ENABLE_RST 0x001Cu

/*! Field MAC2_EN - MAC2 Enable */
#define MAC_ENABLE_MAC2_EN_POS 2
/*! Field MAC2_EN - MAC2 Enable */
#define MAC_ENABLE_MAC2_EN_MASK 0x4u
/*! Constant DISABLE - Disable */
#define CONST_MAC_ENABLE_MAC2_EN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_MAC_ENABLE_MAC2_EN_ENABLE 0x1

/*! Field MAC3_EN - MAC3 Enable */
#define MAC_ENABLE_MAC3_EN_POS 3
/*! Field MAC3_EN - MAC3 Enable */
#define MAC_ENABLE_MAC3_EN_MASK 0x8u
/*! Constant DISABLE - Disable */
#define CONST_MAC_ENABLE_MAC3_EN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_MAC_ENABLE_MAC3_EN_ENABLE 0x1

/*! Field MAC4_EN - MAC4 Enable */
#define MAC_ENABLE_MAC4_EN_POS 4
/*! Field MAC4_EN - MAC4 Enable */
#define MAC_ENABLE_MAC4_EN_MASK 0x10u
/*! Constant DISABLE - Disable */
#define CONST_MAC_ENABLE_MAC4_EN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_MAC_ENABLE_MAC4_EN_ENABLE 0x1

/*! @} */

/*! \defgroup GSWIPSS_IER_0 Register GSWIPSS_IER_0 - GSWIP SS Interrupt Enable Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSWIPSS_IER_0 0x10
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_GSWIPSS_IER_0 0x18440010u

/*! Register Reset Value */
#define GSWIPSS_IER_0_RST 0x0000u

/*! Field XGMAC2 - XGMAC MAC 2 Interrupt Enable */
#define GSWIPSS_IER_0_XGMAC2_POS 10
/*! Field XGMAC2 - XGMAC MAC 2 Interrupt Enable */
#define GSWIPSS_IER_0_XGMAC2_MASK 0x400u
/*! Constant DIS - DIS */
#define CONST_GSWIPSS_IER_0_XGMAC2_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSWIPSS_IER_0_XGMAC2_EN 0x1

/*! Field XGMAC3 - XGMAC MAC 3 Interrupt Enable */
#define GSWIPSS_IER_0_XGMAC3_POS 11
/*! Field XGMAC3 - XGMAC MAC 3 Interrupt Enable */
#define GSWIPSS_IER_0_XGMAC3_MASK 0x800u
/*! Constant DIS - DIS */
#define CONST_GSWIPSS_IER_0_XGMAC3_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSWIPSS_IER_0_XGMAC3_EN 0x1

/*! Field XGMAC4 - XGMAC MAC 4 Interrupt Enable */
#define GSWIPSS_IER_0_XGMAC4_POS 12
/*! Field XGMAC4 - XGMAC MAC 4 Interrupt Enable */
#define GSWIPSS_IER_0_XGMAC4_MASK 0x1000u
/*! Constant DIS - DIS */
#define CONST_GSWIPSS_IER_0_XGMAC4_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSWIPSS_IER_0_XGMAC4_EN 0x1

/*! @} */

/*! \defgroup GSWIPSS_ISR_0 Register GSWIPSS_ISR_0 - GSWIP SS Interrupt Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSWIPSS_ISR_0 0x14
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_GSWIPSS_ISR_0 0x18440014u

/*! Register Reset Value */
#define GSWIPSS_ISR_0_RST 0x0000u

/*! Field XGMAC2INT - XGMAC 2 Interrupt */
#define GSWIPSS_ISR_0_XGMAC2INT_POS 10
/*! Field XGMAC2INT - XGMAC 2 Interrupt */
#define GSWIPSS_ISR_0_XGMAC2INT_MASK 0x400u
/*! Constant NOINT - NOINT */
#define CONST_GSWIPSS_ISR_0_XGMAC2INT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSWIPSS_ISR_0_XGMAC2INT_INT 0x1

/*! Field XGMAC3INT - XGMAC 3 Interrupt */
#define GSWIPSS_ISR_0_XGMAC3INT_POS 11
/*! Field XGMAC3INT - XGMAC 3 Interrupt */
#define GSWIPSS_ISR_0_XGMAC3INT_MASK 0x800u
/*! Constant NOINT - NOINT */
#define CONST_GSWIPSS_ISR_0_XGMAC3INT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSWIPSS_ISR_0_XGMAC3INT_INT 0x1

/*! Field XGMAC4INT - XGMAC 4 Interrupt */
#define GSWIPSS_ISR_0_XGMAC4INT_POS 12
/*! Field XGMAC4INT - XGMAC 4 Interrupt */
#define GSWIPSS_ISR_0_XGMAC4INT_MASK 0x1000u
/*! Constant NOINT - NOINT */
#define CONST_GSWIPSS_ISR_0_XGMAC4INT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSWIPSS_ISR_0_XGMAC4INT_INT 0x1

/*! @} */

/*! \defgroup GSWIPSS_IER_1 Register GSWIPSS_IER_1 - GSWIP SS Interrupt Enable Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSWIPSS_IER_1 0x18
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_GSWIPSS_IER_1 0x18440018u

/*! Register Reset Value */
#define GSWIPSS_IER_1_RST 0x0000u

/*! Field LINK2 - Link 2 Status Change Interrupt Enable */
#define GSWIPSS_IER_1_LINK2_POS 2
/*! Field LINK2 - Link 2 Status Change Interrupt Enable */
#define GSWIPSS_IER_1_LINK2_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_GSWIPSS_IER_1_LINK2_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSWIPSS_IER_1_LINK2_EN 0x1

/*! Field LINK3 - Link 3 Status Change Interrupt Enable */
#define GSWIPSS_IER_1_LINK3_POS 3
/*! Field LINK3 - Link 3 Status Change Interrupt Enable */
#define GSWIPSS_IER_1_LINK3_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_GSWIPSS_IER_1_LINK3_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSWIPSS_IER_1_LINK3_EN 0x1

/*! Field LINK4 - Link 4 Status Change Interrupt Enable */
#define GSWIPSS_IER_1_LINK4_POS 4
/*! Field LINK4 - Link 4 Status Change Interrupt Enable */
#define GSWIPSS_IER_1_LINK4_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_GSWIPSS_IER_1_LINK4_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSWIPSS_IER_1_LINK4_EN 0x1

/*! @} */

/*! \defgroup GSWIPSS_ISR_1 Register GSWIPSS_ISR_1 - GSWIP SS Interrupt Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSWIPSS_ISR_1 0x1C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_GSWIPSS_ISR_1 0x1844001Cu

/*! Register Reset Value */
#define GSWIPSS_ISR_1_RST 0x0000u

/*! Field LINK2INT - Link 2 Status Change Interrupt */
#define GSWIPSS_ISR_1_LINK2INT_POS 2
/*! Field LINK2INT - Link 2 Status Change Interrupt */
#define GSWIPSS_ISR_1_LINK2INT_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_GSWIPSS_ISR_1_LINK2INT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSWIPSS_ISR_1_LINK2INT_INT 0x1

/*! Field LINK3INT - Link 3 Status Change MAC 3 Interrupt */
#define GSWIPSS_ISR_1_LINK3INT_POS 3
/*! Field LINK3INT - Link 3 Status Change MAC 3 Interrupt */
#define GSWIPSS_ISR_1_LINK3INT_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_GSWIPSS_ISR_1_LINK3INT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSWIPSS_ISR_1_LINK3INT_INT 0x1

/*! Field LINK4INT - Link 4 Status Change Interrupt */
#define GSWIPSS_ISR_1_LINK4INT_POS 4
/*! Field LINK4INT - Link 4 Status Change Interrupt */
#define GSWIPSS_ISR_1_LINK4INT_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_GSWIPSS_ISR_1_LINK4INT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSWIPSS_ISR_1_LINK4INT_INT 0x1

/*! @} */

/*! \defgroup SPTAG_ETYPE Register SPTAG_ETYPE - Special Tag Ethernet Type Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define SPTAG_ETYPE 0x38
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_SPTAG_ETYPE 0x18440038u

/*! Register Reset Value */
#define SPTAG_ETYPE_RST 0x88C3u

/*! Field ETYPE - Special Tag Ethernet Type */
#define SPTAG_ETYPE_ETYPE_POS 0
/*! Field ETYPE - Special Tag Ethernet Type */
#define SPTAG_ETYPE_ETYPE_MASK 0xFFFFu

/*! @} */

/*! \defgroup NCO0_LSB Register NCO0_LSB - NCO0 LSB Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define NCO0_LSB 0x40
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_NCO0_LSB 0x18440040u

/*! Register Reset Value */
#define NCO0_LSB_RST 0x0000u

/*! Field NCO0_LSB - NCO0 LSB */
#define NCO0_LSB_NCO0_LSB_POS 0
/*! Field NCO0_LSB - NCO0 LSB */
#define NCO0_LSB_NCO0_LSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup NCO0_MSB Register NCO0_MSB - NCO0 MSB Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define NCO0_MSB 0x44
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_NCO0_MSB 0x18440044u

/*! Register Reset Value */
#define NCO0_MSB_RST 0x0030u

/*! Field NCO0_MSB - NCO0 MSB */
#define NCO0_MSB_NCO0_MSB_POS 0
/*! Field NCO0_MSB - NCO0 MSB */
#define NCO0_MSB_NCO0_MSB_MASK 0xFFu

/*! @} */

/*! \defgroup V1588_CFG0 Register V1588_CFG0 - 1588 Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define V1588_CFG0 0x50
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_V1588_CFG0 0x18440050u

/*! Register Reset Value */
#define V1588_CFG0_RST 0x0000u

/*! Field REFTIME_SEL - Reference Time Master Select */
#define V1588_CFG0_REFTIME_SEL_POS 0
/*! Field REFTIME_SEL - Reference Time Master Select */
#define V1588_CFG0_REFTIME_SEL_MASK 0x7u
/*! Constant PON - PON */
#define CONST_V1588_CFG0_REFTIME_SEL_PON 0x0
/*! Constant PCIE0 - PCIe0 */
#define CONST_V1588_CFG0_REFTIME_SEL_PCIE0 0x1
/*! Constant PCIE1 - PCIe1 */
#define CONST_V1588_CFG0_REFTIME_SEL_PCIE1 0x2
/*! Constant XGMAC2 - XGMAC2 */
#define CONST_V1588_CFG0_REFTIME_SEL_XGMAC2 0x3
/*! Constant XGMAC3 - XGMAC3 */
#define CONST_V1588_CFG0_REFTIME_SEL_XGMAC3 0x4
/*! Constant XGMAC4 - XGMAC4 */
#define CONST_V1588_CFG0_REFTIME_SEL_XGMAC4 0x5

/*! Field DIGTIME_SEL - Digital Reference Time Select */
#define V1588_CFG0_DIGTIME_SEL_POS 4
/*! Field DIGTIME_SEL - Digital Reference Time Select */
#define V1588_CFG0_DIGTIME_SEL_MASK 0x70u
/*! Constant PON - PON */
#define CONST_V1588_CFG0_DIGTIME_SEL_PON 0x0
/*! Constant PCIE0 - PCIe0 */
#define CONST_V1588_CFG0_DIGTIME_SEL_PCIE0 0x1
/*! Constant PCIE1 - PCIe1 */
#define CONST_V1588_CFG0_DIGTIME_SEL_PCIE1 0x2
/*! Constant XGMAC2 - XGMAC2 */
#define CONST_V1588_CFG0_DIGTIME_SEL_XGMAC2 0x3
/*! Constant XGMAC3 - XGMAC3 */
#define CONST_V1588_CFG0_DIGTIME_SEL_XGMAC3 0x4
/*! Constant XGMAC4 - XGMAC4 */
#define CONST_V1588_CFG0_DIGTIME_SEL_XGMAC4 0x5

/*! Field BINTIME_SEL - Binary Reference Time Select */
#define V1588_CFG0_BINTIME_SEL_POS 8
/*! Field BINTIME_SEL - Binary Reference Time Select */
#define V1588_CFG0_BINTIME_SEL_MASK 0x700u
/*! Constant PON - PON */
#define CONST_V1588_CFG0_BINTIME_SEL_PON 0x0
/*! Constant PCIE0 - PCIe0 */
#define CONST_V1588_CFG0_BINTIME_SEL_PCIE0 0x1
/*! Constant PCIE1 - PCIe1 */
#define CONST_V1588_CFG0_BINTIME_SEL_PCIE1 0x2
/*! Constant XGMAC2 - XGMAC2 */
#define CONST_V1588_CFG0_BINTIME_SEL_XGMAC2 0x3
/*! Constant XGMAC3 - XGMAC3 */
#define CONST_V1588_CFG0_BINTIME_SEL_XGMAC3 0x4
/*! Constant XGMAC4 - XGMAC4 */
#define CONST_V1588_CFG0_BINTIME_SEL_XGMAC4 0x5

/*! Field PPS_SEL - PPS Master Select */
#define V1588_CFG0_PPS_SEL_POS 12
/*! Field PPS_SEL - PPS Master Select */
#define V1588_CFG0_PPS_SEL_MASK 0x7000u
/*! Constant PON1S - PON1S */
#define CONST_V1588_CFG0_PPS_SEL_PON1S 0x0
/*! Constant PCIE0 - PCIe0 */
#define CONST_V1588_CFG0_PPS_SEL_PCIE0 0x1
/*! Constant PCIE1 - PCIe1 */
#define CONST_V1588_CFG0_PPS_SEL_PCIE1 0x2
/*! Constant XGMAC2 - XGMAC2 */
#define CONST_V1588_CFG0_PPS_SEL_XGMAC2 0x3
/*! Constant XGMAC3 - XGMAC3 */
#define CONST_V1588_CFG0_PPS_SEL_XGMAC3 0x4
/*! Constant XGMAC4 - XGMAC4 */
#define CONST_V1588_CFG0_PPS_SEL_XGMAC4 0x5
/*! Constant PON100US - PON100US */
#define CONST_V1588_CFG0_PPS_SEL_PON100US 0x6
/*! Constant SW - SW */
#define CONST_V1588_CFG0_PPS_SEL_SW 0x7

/*! @} */

/*! \defgroup V1588_CFG1 Register V1588_CFG1 - 1588 Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define V1588_CFG1 0x54
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_V1588_CFG1 0x18440054u

/*! Register Reset Value */
#define V1588_CFG1_RST 0x0000u

/*! Field SW_TRIG - Software Trigger */
#define V1588_CFG1_SW_TRIG_POS 7
/*! Field SW_TRIG - Software Trigger */
#define V1588_CFG1_SW_TRIG_MASK 0x80u
/*! Constant LOW - LOW */
#define CONST_V1588_CFG1_SW_TRIG_LOW 0x0
/*! Constant HIGH - HIGH */
#define CONST_V1588_CFG1_SW_TRIG_HIGH 0x1

/*! Field TRIG0_SEL - Time Aux Trigger 0 Select */
#define V1588_CFG1_TRIG0_SEL_POS 8
/*! Field TRIG0_SEL - Time Aux Trigger 0 Select */
#define V1588_CFG1_TRIG0_SEL_MASK 0xF00u
/*! Constant PON1S - PON1S */
#define CONST_V1588_CFG1_TRIG0_SEL_PON1S 0x0
/*! Constant PCIE0 - PCIe0 */
#define CONST_V1588_CFG1_TRIG0_SEL_PCIE0 0x1
/*! Constant PCIE1 - PCIe1 */
#define CONST_V1588_CFG1_TRIG0_SEL_PCIE1 0x2
/*! Constant XGMAC2 - XGMAC2 */
#define CONST_V1588_CFG1_TRIG0_SEL_XGMAC2 0x3
/*! Constant XGMAC3 - XGMAC3 */
#define CONST_V1588_CFG1_TRIG0_SEL_XGMAC3 0x4
/*! Constant XGMAC4 - XGMAC4 */
#define CONST_V1588_CFG1_TRIG0_SEL_XGMAC4 0x5
/*! Constant PON100US - PON100US */
#define CONST_V1588_CFG1_TRIG0_SEL_PON100US 0x6
/*! Constant EXTPPS0 - EXTPPS0 */
#define CONST_V1588_CFG1_TRIG0_SEL_EXTPPS0 0x8
/*! Constant EXTPPS1 - EXTPPS1 */
#define CONST_V1588_CFG1_TRIG0_SEL_EXTPPS1 0x9
/*! Constant SW - SW */
#define CONST_V1588_CFG1_TRIG0_SEL_SW 0xA

/*! Field TRIG1_SEL - Time Aux Trigger 1 Select */
#define V1588_CFG1_TRIG1_SEL_POS 12
/*! Field TRIG1_SEL - Time Aux Trigger 1 Select */
#define V1588_CFG1_TRIG1_SEL_MASK 0xF000u
/*! Constant PON1S - PON1S */
#define CONST_V1588_CFG1_TRIG1_SEL_PON1S 0x0
/*! Constant PCIE0 - PCIe0 */
#define CONST_V1588_CFG1_TRIG1_SEL_PCIE0 0x1
/*! Constant PCIE1 - PCIe1 */
#define CONST_V1588_CFG1_TRIG1_SEL_PCIE1 0x2
/*! Constant XGMAC2 - XGMAC2 */
#define CONST_V1588_CFG1_TRIG1_SEL_XGMAC2 0x3
/*! Constant XGMAC3 - XGMAC3 */
#define CONST_V1588_CFG1_TRIG1_SEL_XGMAC3 0x4
/*! Constant XGMAC4 - XGMAC4 */
#define CONST_V1588_CFG1_TRIG1_SEL_XGMAC4 0x5
/*! Constant PON100US - PON100US */
#define CONST_V1588_CFG1_TRIG1_SEL_PON100US 0x6
/*! Constant EXTPPS0 - EXTPPS0 */
#define CONST_V1588_CFG1_TRIG1_SEL_EXTPPS0 0x8
/*! Constant EXTPPS1 - EXTPPS1 */
#define CONST_V1588_CFG1_TRIG1_SEL_EXTPPS1 0x9
/*! Constant SW - SW */
#define CONST_V1588_CFG1_TRIG1_SEL_SW 0xA

/*! @} */

/*! \defgroup MAC2_IF_CFG Register MAC2_IF_CFG - MAC 2 Interface Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_IF_CFG 0x1200
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_IF_CFG 0x18441200u

/*! Register Reset Value */
#define MAC2_IF_CFG_RST 0x0000u

/*! Field CFG_2G5 - 2.5Gbps Speed Interface Mode */
#define MAC2_IF_CFG_CFG_2G5_POS 0
/*! Field CFG_2G5 - 2.5Gbps Speed Interface Mode */
#define MAC2_IF_CFG_CFG_2G5_MASK 0x1u
/*! Constant GMII - GMII */
#define CONST_MAC2_IF_CFG_CFG_2G5_GMII 0x0
/*! Constant XGMII - XGMII */
#define CONST_MAC2_IF_CFG_CFG_2G5_XGMII 0x1

/*! Field CFG_1G - Gigabit Speed Interface Mode */
#define MAC2_IF_CFG_CFG_1G_POS 1
/*! Field CFG_1G - Gigabit Speed Interface Mode */
#define MAC2_IF_CFG_CFG_1G_MASK 0x2u
/*! Constant LMAC - LMAC */
#define CONST_MAC2_IF_CFG_CFG_1G_LMAC 0x0
/*! Constant XGMAC - XGMAC */
#define CONST_MAC2_IF_CFG_CFG_1G_XGMAC 0x1

/*! Field CFG_FE - Fast Ethernet Speed Interface Mode */
#define MAC2_IF_CFG_CFG_FE_POS 2
/*! Field CFG_FE - Fast Ethernet Speed Interface Mode */
#define MAC2_IF_CFG_CFG_FE_MASK 0x4u
/*! Constant MII - MII */
#define CONST_MAC2_IF_CFG_CFG_FE_MII 0x0
/*! Constant GMII - GMII */
#define CONST_MAC2_IF_CFG_CFG_FE_GMII 0x1

/*! @} */

/*! \defgroup MAC2_OP_CFG Register MAC2_OP_CFG - MAC 2 Operation Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_OP_CFG 0x1204
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_OP_CFG 0x18441204u

/*! Register Reset Value */
#define MAC2_OP_CFG_RST 0x0120u

/*! Field RX_SPTAG - RX direction special tag */
#define MAC2_OP_CFG_RX_SPTAG_POS 0
/*! Field RX_SPTAG - RX direction special tag */
#define MAC2_OP_CFG_RX_SPTAG_MASK 0x3u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC2_OP_CFG_RX_SPTAG_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC2_OP_CFG_RX_SPTAG_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC2_OP_CFG_RX_SPTAG_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC2_OP_CFG_RX_SPTAG_MODE3 0x3

/*! Field RX_TIME - RX direction time stamp */
#define MAC2_OP_CFG_RX_TIME_POS 2
/*! Field RX_TIME - RX direction time stamp */
#define MAC2_OP_CFG_RX_TIME_MASK 0xCu
/*! Constant MODE0 - MODE0 */
#define CONST_MAC2_OP_CFG_RX_TIME_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC2_OP_CFG_RX_TIME_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC2_OP_CFG_RX_TIME_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC2_OP_CFG_RX_TIME_MODE3 0x3

/*! Field RX_FCS - RX direction FCS */
#define MAC2_OP_CFG_RX_FCS_POS 4
/*! Field RX_FCS - RX direction FCS */
#define MAC2_OP_CFG_RX_FCS_MASK 0x30u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC2_OP_CFG_RX_FCS_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC2_OP_CFG_RX_FCS_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC2_OP_CFG_RX_FCS_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC2_OP_CFG_RX_FCS_MODE3 0x3

/*! Field TX_SPTAG - TX direction special tag */
#define MAC2_OP_CFG_TX_SPTAG_POS 6
/*! Field TX_SPTAG - TX direction special tag */
#define MAC2_OP_CFG_TX_SPTAG_MASK 0xC0u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC2_OP_CFG_TX_SPTAG_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC2_OP_CFG_TX_SPTAG_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC2_OP_CFG_TX_SPTAG_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC2_OP_CFG_TX_SPTAG_MODE3 0x3

/*! Field TX_FCS_RM - TX direction FCS removal */
#define MAC2_OP_CFG_TX_FCS_RM_POS 8
/*! Field TX_FCS_RM - TX direction FCS removal */
#define MAC2_OP_CFG_TX_FCS_RM_MASK 0x100u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC2_OP_CFG_TX_FCS_RM_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC2_OP_CFG_TX_FCS_RM_MODE1 0x1

/*! Field TX_FCS_INS - TX direction FCS insertion */
#define MAC2_OP_CFG_TX_FCS_INS_POS 9
/*! Field TX_FCS_INS - TX direction FCS insertion */
#define MAC2_OP_CFG_TX_FCS_INS_MASK 0x200u
/*! Constant MODE0 - MODE 0 */
#define CONST_MAC2_OP_CFG_TX_FCS_INS_MODE0 0x0
/*! Constant MDIO1 - MODE 1 */
#define CONST_MAC2_OP_CFG_TX_FCS_INS_MDIO1 0x1

/*! @} */

/*! \defgroup MAC2_MTU_CFG Register MAC2_MTU_CFG - MAC 2 MTU Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_MTU_CFG 0x1208
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_MTU_CFG 0x18441208u

/*! Register Reset Value */
#define MAC2_MTU_CFG_RST 0x2800u

/*! Field MTU - Maximum Frame Length Size in byte */
#define MAC2_MTU_CFG_MTU_POS 0
/*! Field MTU - Maximum Frame Length Size in byte */
#define MAC2_MTU_CFG_MTU_MASK 0x3FFFu

/*! @} */

/*! \defgroup MAC2_GINT_CFG0 Register MAC2_GINT_CFG0 - MAC 2 G.INT Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_CFG0 0x120C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_CFG0 0x1844120Cu

/*! Register Reset Value */
#define MAC2_GINT_CFG0_RST 0x0000u

/*! Field GINT_EN - G.INT Enable */
#define MAC2_GINT_CFG0_GINT_EN_POS 0
/*! Field GINT_EN - G.INT Enable */
#define MAC2_GINT_CFG0_GINT_EN_MASK 0x1u
/*! Constant DISABLE - Disable */
#define CONST_MAC2_GINT_CFG0_GINT_EN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_MAC2_GINT_CFG0_GINT_EN_ENABLE 0x1

/*! Field ENCAP_MD - G.INT Encapsulation Mode */
#define MAC2_GINT_CFG0_ENCAP_MD_POS 1
/*! Field ENCAP_MD - G.INT Encapsulation Mode */
#define MAC2_GINT_CFG0_ENCAP_MD_MASK 0x2u
/*! Constant NATIVE - Native */
#define CONST_MAC2_GINT_CFG0_ENCAP_MD_NATIVE 0x0
/*! Constant ETHERNET - Ethernet */
#define CONST_MAC2_GINT_CFG0_ENCAP_MD_ETHERNET 0x1

/*! Field LEN_MD - Encapsulation Length Mode */
#define MAC2_GINT_CFG0_LEN_MD_POS 2
/*! Field LEN_MD - Encapsulation Length Mode */
#define MAC2_GINT_CFG0_LEN_MD_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_MAC2_GINT_CFG0_LEN_MD_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC2_GINT_CFG0_LEN_MD_EN 0x1

/*! Field QID - Starting Queue ID for stream 0 for this MAC */
#define MAC2_GINT_CFG0_QID_POS 3
/*! Field QID - Starting Queue ID for stream 0 for this MAC */
#define MAC2_GINT_CFG0_QID_MASK 0xF8u

/*! Field NUM_STEAM - Number of streams: */
#define MAC2_GINT_CFG0_NUM_STEAM_POS 8
/*! Field NUM_STEAM - Number of streams: */
#define MAC2_GINT_CFG0_NUM_STEAM_MASK 0x100u
/*! Constant V8 - 8 */
#define CONST_MAC2_GINT_CFG0_NUM_STEAM_V8 0x0
/*! Constant V16 - 16 */
#define CONST_MAC2_GINT_CFG0_NUM_STEAM_V16 0x1

/*! Field POS_SID - Bit position of the first valid bit in stream ID in G.INT header */
#define MAC2_GINT_CFG0_POS_SID_POS 9
/*! Field POS_SID - Bit position of the first valid bit in stream ID in G.INT header */
#define MAC2_GINT_CFG0_POS_SID_MASK 0x600u

/*! Field CQESHIFT - Starting Stream ID in CQE Backpressure Bitmap for this MAC */
#define MAC2_GINT_CFG0_CQESHIFT_POS 11
/*! Field CQESHIFT - Starting Stream ID in CQE Backpressure Bitmap for this MAC */
#define MAC2_GINT_CFG0_CQESHIFT_MASK 0xF800u

/*! @} */

/*! \defgroup MAC2_GINT_HD0_CFG Register MAC2_GINT_HD0_CFG - MAC 2 G.INT Header Word 0 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_HD0_CFG 0x1220
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_HD0_CFG 0x18441220u

/*! Register Reset Value */
#define MAC2_GINT_HD0_CFG_RST 0x0000u

/*! Field HD01 - Ethernet Header Byte 0 and 1 */
#define MAC2_GINT_HD0_CFG_HD01_POS 0
/*! Field HD01 - Ethernet Header Byte 0 and 1 */
#define MAC2_GINT_HD0_CFG_HD01_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_GINT_HD1_CFG Register MAC2_GINT_HD1_CFG - MAC 2 G.INT Header Word 1 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_HD1_CFG 0x1224
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_HD1_CFG 0x18441224u

/*! Register Reset Value */
#define MAC2_GINT_HD1_CFG_RST 0x0000u

/*! Field HD23 - Ethernet Header Byte 2 and 3 */
#define MAC2_GINT_HD1_CFG_HD23_POS 0
/*! Field HD23 - Ethernet Header Byte 2 and 3 */
#define MAC2_GINT_HD1_CFG_HD23_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_GINT_HD2_CFG Register MAC2_GINT_HD2_CFG - MAC 2 G.INT Header Word 2 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_HD2_CFG 0x1228
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_HD2_CFG 0x18441228u

/*! Register Reset Value */
#define MAC2_GINT_HD2_CFG_RST 0x0000u

/*! Field HD45 - Ethernet Header Byte 4 and 5 */
#define MAC2_GINT_HD2_CFG_HD45_POS 0
/*! Field HD45 - Ethernet Header Byte 4 and 5 */
#define MAC2_GINT_HD2_CFG_HD45_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_GINT_HD3_CFG Register MAC2_GINT_HD3_CFG - MAC 2 G.INT Header Word 3 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_HD3_CFG 0x122C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_HD3_CFG 0x1844122Cu

/*! Register Reset Value */
#define MAC2_GINT_HD3_CFG_RST 0x0000u

/*! Field HD67 - Ethernet Header Byte 6 and 7 */
#define MAC2_GINT_HD3_CFG_HD67_POS 0
/*! Field HD67 - Ethernet Header Byte 6 and 7 */
#define MAC2_GINT_HD3_CFG_HD67_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_GINT_HD4_CFG Register MAC2_GINT_HD4_CFG - MAC 2 G.INT Header Word 4 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_HD4_CFG 0x1230
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_HD4_CFG 0x18441230u

/*! Register Reset Value */
#define MAC2_GINT_HD4_CFG_RST 0x0000u

/*! Field HD89 - Ethernet Header Byte 8 and 9 */
#define MAC2_GINT_HD4_CFG_HD89_POS 0
/*! Field HD89 - Ethernet Header Byte 8 and 9 */
#define MAC2_GINT_HD4_CFG_HD89_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_GINT_HD5_CFG Register MAC2_GINT_HD5_CFG - MAC 2 G.INT Header Word 5 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_HD5_CFG 0x1234
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_HD5_CFG 0x18441234u

/*! Register Reset Value */
#define MAC2_GINT_HD5_CFG_RST 0x0000u

/*! Field HDAB - Ethernet Header Byte 10 and 11 */
#define MAC2_GINT_HD5_CFG_HDAB_POS 0
/*! Field HDAB - Ethernet Header Byte 10 and 11 */
#define MAC2_GINT_HD5_CFG_HDAB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_GINT_HD6_CFG Register MAC2_GINT_HD6_CFG - MAC 2 G.INT Header Word 6 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_GINT_HD6_CFG 0x1238
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_GINT_HD6_CFG 0x18441238u

/*! Register Reset Value */
#define MAC2_GINT_HD6_CFG_RST 0x0000u

/*! Field HDCD - Ethernet Header Byte 12 and 13 */
#define MAC2_GINT_HD6_CFG_HDCD_POS 0
/*! Field HDCD - Ethernet Header Byte 12 and 13 */
#define MAC2_GINT_HD6_CFG_HDCD_MASK 0xFFFFu

/*! @} */

/*! \defgroup LMAC2_RTXB_CTL Register LMAC2_RTXB_CTL - Legacy MAC 2 Interface Receive Transmit Buffer Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define LMAC2_RTXB_CTL 0x123C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_LMAC2_RTXB_CTL 0x1844123Cu

/*! Register Reset Value */
#define LMAC2_RTXB_CTL_RST 0x0101u

/*! Field RBUF_DLY_WP - RX Buffer Delay Write Pointer */
#define LMAC2_RTXB_CTL_RBUF_DLY_WP_POS 0
/*! Field RBUF_DLY_WP - RX Buffer Delay Write Pointer */
#define LMAC2_RTXB_CTL_RBUF_DLY_WP_MASK 0x7u

/*! Field RBUF_OFL - Receive Buffer Overflow Indicator */
#define LMAC2_RTXB_CTL_RBUF_OFL_POS 3
/*! Field RBUF_OFL - Receive Buffer Overflow Indicator */
#define LMAC2_RTXB_CTL_RBUF_OFL_MASK 0x8u
/*! Constant NONE - NONE */
#define CONST_LMAC2_RTXB_CTL_RBUF_OFL_NONE 0x0
/*! Constant OFL - OFL */
#define CONST_LMAC2_RTXB_CTL_RBUF_OFL_OFL 0x1

/*! Field RBUF_UFL - Receive Buffer Underflow Indicator */
#define LMAC2_RTXB_CTL_RBUF_UFL_POS 4
/*! Field RBUF_UFL - Receive Buffer Underflow Indicator */
#define LMAC2_RTXB_CTL_RBUF_UFL_MASK 0x10u
/*! Constant NONE - NONE */
#define CONST_LMAC2_RTXB_CTL_RBUF_UFL_NONE 0x0
/*! Constant UFL - UFL */
#define CONST_LMAC2_RTXB_CTL_RBUF_UFL_UFL 0x1

/*! Field RBUF_INIT - Receive Buffer Reset */
#define LMAC2_RTXB_CTL_RBUF_INIT_POS 5
/*! Field RBUF_INIT - Receive Buffer Reset */
#define LMAC2_RTXB_CTL_RBUF_INIT_MASK 0x20u
/*! Constant NONE - NONE */
#define CONST_LMAC2_RTXB_CTL_RBUF_INIT_NONE 0x0
/*! Constant INIT - INIT */
#define CONST_LMAC2_RTXB_CTL_RBUF_INIT_INIT 0x1

/*! Field TBUF_DLY_WP - TX Buffer Delay Write Pointer */
#define LMAC2_RTXB_CTL_TBUF_DLY_WP_POS 8
/*! Field TBUF_DLY_WP - TX Buffer Delay Write Pointer */
#define LMAC2_RTXB_CTL_TBUF_DLY_WP_MASK 0x700u

/*! Field TBUF_OFL - Transmit Buffer Overflow Indicator */
#define LMAC2_RTXB_CTL_TBUF_OFL_POS 11
/*! Field TBUF_OFL - Transmit Buffer Overflow Indicator */
#define LMAC2_RTXB_CTL_TBUF_OFL_MASK 0x800u
/*! Constant NONE - NONE */
#define CONST_LMAC2_RTXB_CTL_TBUF_OFL_NONE 0x0
/*! Constant OFL - OFL */
#define CONST_LMAC2_RTXB_CTL_TBUF_OFL_OFL 0x1

/*! Field TBUF_UFL - Transmit Buffer Underflow Indicator */
#define LMAC2_RTXB_CTL_TBUF_UFL_POS 12
/*! Field TBUF_UFL - Transmit Buffer Underflow Indicator */
#define LMAC2_RTXB_CTL_TBUF_UFL_MASK 0x1000u
/*! Constant NONE - NONE */
#define CONST_LMAC2_RTXB_CTL_TBUF_UFL_NONE 0x0
/*! Constant UFL - UFL */
#define CONST_LMAC2_RTXB_CTL_TBUF_UFL_UFL 0x1

/*! Field TBUF_INIT - Transmit Buffer Reset */
#define LMAC2_RTXB_CTL_TBUF_INIT_POS 13
/*! Field TBUF_INIT - Transmit Buffer Reset */
#define LMAC2_RTXB_CTL_TBUF_INIT_MASK 0x2000u
/*! Constant NONE - NONE */
#define CONST_LMAC2_RTXB_CTL_TBUF_INIT_NONE 0x0
/*! Constant INIT - INIT */
#define CONST_LMAC2_RTXB_CTL_TBUF_INIT_INIT 0x1

/*! @} */

/*! \defgroup MAC2_TXTS_0 Register MAC2_TXTS_0 - MAC 2 TX Timestamp Bit 15 to 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_TXTS_0 0x1250
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_TXTS_0 0x18441250u

/*! Register Reset Value */
#define MAC2_TXTS_0_RST 0x0000u

/*! Field TTSLL - Time Stamp Bit 15 to 0 */
#define MAC2_TXTS_0_TTSLL_POS 0
/*! Field TTSLL - Time Stamp Bit 15 to 0 */
#define MAC2_TXTS_0_TTSLL_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_TXTS_1 Register MAC2_TXTS_1 - MAC 2 TX Timestamp Bit 31 to 16 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_TXTS_1 0x1254
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_TXTS_1 0x18441254u

/*! Register Reset Value */
#define MAC2_TXTS_1_RST 0x0000u

/*! Field TTSLH - Time Stamp Bit 31 to 16 */
#define MAC2_TXTS_1_TTSLH_POS 0
/*! Field TTSLH - Time Stamp Bit 31 to 16 */
#define MAC2_TXTS_1_TTSLH_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_TXTS_2 Register MAC2_TXTS_2 - MAC 2 TX Timestamp Bit 47 to 32 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_TXTS_2 0x1258
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_TXTS_2 0x18441258u

/*! Register Reset Value */
#define MAC2_TXTS_2_RST 0x0000u

/*! Field TTSHL - Time Stamp Bit 47 to 32 */
#define MAC2_TXTS_2_TTSHL_POS 0
/*! Field TTSHL - Time Stamp Bit 47 to 32 */
#define MAC2_TXTS_2_TTSHL_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_TXTS_3 Register MAC2_TXTS_3 - MAC 2 TX Timestamp Bit 63 to 48 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_TXTS_3 0x125C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_TXTS_3 0x1844125Cu

/*! Register Reset Value */
#define MAC2_TXTS_3_RST 0x0000u

/*! Field TTSHH - Time Stamp Bit 63 to 48 */
#define MAC2_TXTS_3_TTSHH_POS 0
/*! Field TTSHH - Time Stamp Bit 63 to 48 */
#define MAC2_TXTS_3_TTSHH_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC2_TXTS_CIC Register MAC2_TXTS_CIC - MAC 2 TX Timestamp CIC */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_TXTS_CIC 0x1260
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_TXTS_CIC 0x18441260u

/*! Register Reset Value */
#define MAC2_TXTS_CIC_RST 0x0000u

/*! Field CIC - Time stamp CIC */
#define MAC2_TXTS_CIC_CIC_POS 0
/*! Field CIC - Time stamp CIC */
#define MAC2_TXTS_CIC_CIC_MASK 0x3u
/*! Constant DIS - DIS */
#define CONST_MAC2_TXTS_CIC_CIC_DIS 0x0
/*! Constant IP - IP */
#define CONST_MAC2_TXTS_CIC_CIC_IP 0x1
/*! Constant IPPL - IPPL */
#define CONST_MAC2_TXTS_CIC_CIC_IPPL 0x2
/*! Constant ALL - ALL */
#define CONST_MAC2_TXTS_CIC_CIC_ALL 0x3

/*! Field OST_AVAIL - Time stamp One Step Time stamp Available */
#define MAC2_TXTS_CIC_OST_AVAIL_POS 2
/*! Field OST_AVAIL - Time stamp One Step Time stamp Available */
#define MAC2_TXTS_CIC_OST_AVAIL_MASK 0x4u

/*! Field OSTC - Time stamp One Step Correction Enable */
#define MAC2_TXTS_CIC_OSTC_POS 3
/*! Field OSTC - Time stamp One Step Correction Enable */
#define MAC2_TXTS_CIC_OSTC_MASK 0x8u

/*! Field TTSE - Time Stamp Capture Enable */
#define MAC2_TXTS_CIC_TTSE_POS 4
/*! Field TTSE - Time Stamp Capture Enable */
#define MAC2_TXTS_CIC_TTSE_MASK 0x10u

/*! @} */

/*! \defgroup MAC2_TXTS_ACC Register MAC2_TXTS_ACC - MAC 2 TX Timestamp Access */
/*! @{ */

/*! Register Offset (relative) */
#define MAC2_TXTS_ACC 0x1264
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC2_TXTS_ACC 0x18441264u

/*! Register Reset Value */
#define MAC2_TXTS_ACC_RST 0x0000u

/*! Field ADDR - Time stamp FIFO address */
#define MAC2_TXTS_ACC_ADDR_POS 0
/*! Field ADDR - Time stamp FIFO address */
#define MAC2_TXTS_ACC_ADDR_MASK 0x3Fu

/*! Field OPMOD - Access Operation Mode */
#define MAC2_TXTS_ACC_OPMOD_POS 14
/*! Field OPMOD - Access Operation Mode */
#define MAC2_TXTS_ACC_OPMOD_MASK 0x4000u
/*! Constant RD - RD */
#define CONST_MAC2_TXTS_ACC_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_MAC2_TXTS_ACC_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define MAC2_TXTS_ACC_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define MAC2_TXTS_ACC_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_MAC2_TXTS_ACC_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_MAC2_TXTS_ACC_BAS_BUSY 0x1

/*! @} */

/*! \defgroup PHY2_MODE Register PHY2_MODE - PHY 2 Mode Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define PHY2_MODE 0x1270
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_PHY2_MODE 0x18441270u

/*! Register Reset Value */
#define PHY2_MODE_RST 0x9800u

/*! Field FCONRX - Flow Control Mode RX */
#define PHY2_MODE_FCONRX_POS 5
/*! Field FCONRX - Flow Control Mode RX */
#define PHY2_MODE_FCONRX_MASK 0x60u
/*! Constant AUTO - AUTO */
#define CONST_PHY2_MODE_FCONRX_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY2_MODE_FCONRX_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY2_MODE_FCONRX_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY2_MODE_FCONRX_DIS 0x3

/*! Field FCONTX - Flow Control Mode TX */
#define PHY2_MODE_FCONTX_POS 7
/*! Field FCONTX - Flow Control Mode TX */
#define PHY2_MODE_FCONTX_MASK 0x180u
/*! Constant AUTO - AUTO */
#define CONST_PHY2_MODE_FCONTX_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY2_MODE_FCONTX_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY2_MODE_FCONTX_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY2_MODE_FCONTX_DIS 0x3

/*! Field FDUP - Full Duplex Control */
#define PHY2_MODE_FDUP_POS 9
/*! Field FDUP - Full Duplex Control */
#define PHY2_MODE_FDUP_MASK 0x600u
/*! Constant AUTO - AUTO */
#define CONST_PHY2_MODE_FDUP_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY2_MODE_FDUP_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY2_MODE_FDUP_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY2_MODE_FDUP_DIS 0x3

/*! Field SPEED_LSB - Speed Control Bit 2 to 0 */
#define PHY2_MODE_SPEED_LSB_POS 11
/*! Field SPEED_LSB - Speed Control Bit 2 to 0 */
#define PHY2_MODE_SPEED_LSB_MASK 0x1800u

/*! Field LNKST - Link Status Control */
#define PHY2_MODE_LNKST_POS 13
/*! Field LNKST - Link Status Control */
#define PHY2_MODE_LNKST_MASK 0x6000u
/*! Constant AUTO - AUTO */
#define CONST_PHY2_MODE_LNKST_AUTO 0x0
/*! Constant UP - UP */
#define CONST_PHY2_MODE_LNKST_UP 0x1
/*! Constant DOWN - DOWN */
#define CONST_PHY2_MODE_LNKST_DOWN 0x2
/*! Constant RES - RES */
#define CONST_PHY2_MODE_LNKST_RES 0x3

/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY2_MODE_SPEED_MSB_POS 15
/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY2_MODE_SPEED_MSB_MASK 0x8000u

/*! @} */

/*! \defgroup PHY_STAT_2 Register PHY_STAT_2 - PHY 2 Status */
/*! @{ */

/*! Register Offset (relative) */
#define PHY_STAT_2 0x1274
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_PHY_STAT_2 0x18441274u

/*! Register Reset Value */
#define PHY_STAT_2_RST 0x0000u

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define PHY_STAT_2_TXPAUEN_POS 0
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define PHY_STAT_2_TXPAUEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_2_TXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_2_TXPAUEN_EN 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define PHY_STAT_2_RXPAUEN_POS 1
/*! Field RXPAUEN - Receive Pause Enable Status */
#define PHY_STAT_2_RXPAUEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_2_RXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_2_RXPAUEN_EN 0x1

/*! Field FDUP - Full Duplex Status */
#define PHY_STAT_2_FDUP_POS 2
/*! Field FDUP - Full Duplex Status */
#define PHY_STAT_2_FDUP_MASK 0x4u
/*! Constant HALF - HALF */
#define CONST_PHY_STAT_2_FDUP_HALF 0x0
/*! Constant FULL - FULL */
#define CONST_PHY_STAT_2_FDUP_FULL 0x1

/*! Field SPEED_LSB - Speed Control Bit 1 to 0 */
#define PHY_STAT_2_SPEED_LSB_POS 3
/*! Field SPEED_LSB - Speed Control Bit 1 to 0 */
#define PHY_STAT_2_SPEED_LSB_MASK 0x18u

/*! Field LSTAT - Link Status */
#define PHY_STAT_2_LSTAT_POS 5
/*! Field LSTAT - Link Status */
#define PHY_STAT_2_LSTAT_MASK 0x20u
/*! Constant DOWN - DOWN */
#define CONST_PHY_STAT_2_LSTAT_DOWN 0x0
/*! Constant UP - UP */
#define CONST_PHY_STAT_2_LSTAT_UP 0x1

/*! Field EEE_CAPABLE - PHY and link partner support EEE for current speed */
#define PHY_STAT_2_EEE_CAPABLE_POS 7
/*! Field EEE_CAPABLE - PHY and link partner support EEE for current speed */
#define PHY_STAT_2_EEE_CAPABLE_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_2_EEE_CAPABLE_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_2_EEE_CAPABLE_EN 0x1

/*! Field CLK_STOP_CAPABLE - PHY supports TX Clock Stop */
#define PHY_STAT_2_CLK_STOP_CAPABLE_POS 8
/*! Field CLK_STOP_CAPABLE - PHY supports TX Clock Stop */
#define PHY_STAT_2_CLK_STOP_CAPABLE_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_2_CLK_STOP_CAPABLE_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_2_CLK_STOP_CAPABLE_EN 0x1

/*! Field TXACT - TX Traffic Active */
#define PHY_STAT_2_TXACT_POS 9
/*! Field TXACT - TX Traffic Active */
#define PHY_STAT_2_TXACT_MASK 0x200u
/*! Constant NOT_ACTIVE - NOT Active */
#define CONST_PHY_STAT_2_TXACT_NOT_ACTIVE 0x0
/*! Constant ACT - ACT */
#define CONST_PHY_STAT_2_TXACT_ACT 0x1

/*! Field RXACT - RX Traffic Active */
#define PHY_STAT_2_RXACT_POS 10
/*! Field RXACT - RX Traffic Active */
#define PHY_STAT_2_RXACT_MASK 0x400u
/*! Constant NOT_ACTIVE - NOT Active */
#define CONST_PHY_STAT_2_RXACT_NOT_ACTIVE 0x0
/*! Constant ACT - ACT */
#define CONST_PHY_STAT_2_RXACT_ACT 0x1

/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY_STAT_2_SPEED_MSB_POS 11
/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY_STAT_2_SPEED_MSB_MASK 0x800u

/*! @} */

/*! \defgroup ANEG_EEE_2 Register ANEG_EEE_2 - PHY 2 EEE auto negotiation overrides */
/*! @{ */

/*! Register Offset (relative) */
#define ANEG_EEE_2 0x1278
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_ANEG_EEE_2 0x18441278u

/*! Register Reset Value */
#define ANEG_EEE_2_RST 0x0000u

/*! Field EEE_CAPABLE - EEE Capable */
#define ANEG_EEE_2_EEE_CAPABLE_POS 0
/*! Field EEE_CAPABLE - EEE Capable */
#define ANEG_EEE_2_EEE_CAPABLE_MASK 0x3u
/*! Constant AUTO - AUTO */
#define CONST_ANEG_EEE_2_EEE_CAPABLE_AUTO 0x0
/*! Constant EN - EN */
#define CONST_ANEG_EEE_2_EEE_CAPABLE_EN 0x1
/*! Constant RES - RES */
#define CONST_ANEG_EEE_2_EEE_CAPABLE_RES 0x2
/*! Constant DIS - DIS */
#define CONST_ANEG_EEE_2_EEE_CAPABLE_DIS 0x3

/*! Field CLK_STOP_CAPABLE - Clock Stop Capable */
#define ANEG_EEE_2_CLK_STOP_CAPABLE_POS 2
/*! Field CLK_STOP_CAPABLE - Clock Stop Capable */
#define ANEG_EEE_2_CLK_STOP_CAPABLE_MASK 0xCu
/*! Constant AUTO - AUTO */
#define CONST_ANEG_EEE_2_CLK_STOP_CAPABLE_AUTO 0x0
/*! Constant EN - EN */
#define CONST_ANEG_EEE_2_CLK_STOP_CAPABLE_EN 0x1
/*! Constant RES - RES */
#define CONST_ANEG_EEE_2_CLK_STOP_CAPABLE_RES 0x2
/*! Constant DIS - DIS */
#define CONST_ANEG_EEE_2_CLK_STOP_CAPABLE_DIS 0x3

/*! @} */

/*! \defgroup XGMAC2_CTRL Register XGMAC2_CTRL - XGMAC 2 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC2_CTRL 0x1280
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC2_CTRL 0x18441280u

/*! Register Reset Value */
#define XGMAC2_CTRL_RST 0x0000u

/*! Field CPC - TX direction CRC CTRL */
#define XGMAC2_CTRL_CPC_POS 0
/*! Field CPC - TX direction CRC CTRL */
#define XGMAC2_CTRL_CPC_MASK 0x3u
/*! Constant PADINS - PADINS */
#define CONST_XGMAC2_CTRL_CPC_PADINS 0x0
/*! Constant CRCINS - CRCINS */
#define CONST_XGMAC2_CTRL_CPC_CRCINS 0x1
/*! Constant NIL - NIL */
#define CONST_XGMAC2_CTRL_CPC_NIL 0x2
/*! Constant RES - RES */
#define CONST_XGMAC2_CTRL_CPC_RES 0x3

/*! Field DIS_RX - MAC Receiver Disable Control */
#define XGMAC2_CTRL_DIS_RX_POS 2
/*! Field DIS_RX - MAC Receiver Disable Control */
#define XGMAC2_CTRL_DIS_RX_MASK 0x4u
/*! Constant NIL - NIL */
#define CONST_XGMAC2_CTRL_DIS_RX_NIL 0x0
/*! Constant DIS - DIS */
#define CONST_XGMAC2_CTRL_DIS_RX_DIS 0x1

/*! Field DIS_TX - MAC Transmitter Disable Control */
#define XGMAC2_CTRL_DIS_TX_POS 3
/*! Field DIS_TX - MAC Transmitter Disable Control */
#define XGMAC2_CTRL_DIS_TX_MASK 0x8u
/*! Constant NIL - NIL */
#define CONST_XGMAC2_CTRL_DIS_TX_NIL 0x0
/*! Constant DIS - DIS */
#define CONST_XGMAC2_CTRL_DIS_TX_DIS 0x1

/*! @} */

/*! \defgroup XGMAC2_REGACC_DATA0 Register XGMAC2_REGACC_DATA0 - XGMAC 2 Register Access Low Data */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC2_REGACC_DATA0 0x1290
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC2_REGACC_DATA0 0x18441290u

/*! Register Reset Value */
#define XGMAC2_REGACC_DATA0_RST 0x0000u

/*! Field LOW - Register Data Bit 15 to 0 */
#define XGMAC2_REGACC_DATA0_LOW_POS 0
/*! Field LOW - Register Data Bit 15 to 0 */
#define XGMAC2_REGACC_DATA0_LOW_MASK 0xFFFFu

/*! @} */

/*! \defgroup XGMAC2_REGACC_DATA1 Register XGMAC2_REGACC_DATA1 - XGMAC 2 Register Access High Data */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC2_REGACC_DATA1 0x1294
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC2_REGACC_DATA1 0x18441294u

/*! Register Reset Value */
#define XGMAC2_REGACC_DATA1_RST 0x0000u

/*! Field HIGH - Register Data Bit 31 to 16 */
#define XGMAC2_REGACC_DATA1_HIGH_POS 0
/*! Field HIGH - Register Data Bit 31 to 16 */
#define XGMAC2_REGACC_DATA1_HIGH_MASK 0xFFFFu

/*! @} */

/*! \defgroup XGMAC2_REGACC_CTRL Register XGMAC2_REGACC_CTRL - XGMAC 2 Register Access Control */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC2_REGACC_CTRL 0x1298
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC2_REGACC_CTRL 0x18441298u

/*! Register Reset Value */
#define XGMAC2_REGACC_CTRL_RST 0x0000u

/*! Field ADDR - Register address */
#define XGMAC2_REGACC_CTRL_ADDR_POS 0
/*! Field ADDR - Register address */
#define XGMAC2_REGACC_CTRL_ADDR_MASK 0x3FFFu

/*! Field OPMOD - Access Operation Mode */
#define XGMAC2_REGACC_CTRL_OPMOD_POS 14
/*! Field OPMOD - Access Operation Mode */
#define XGMAC2_REGACC_CTRL_OPMOD_MASK 0x4000u
/*! Constant RD - RD */
#define CONST_XGMAC2_REGACC_CTRL_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_XGMAC2_REGACC_CTRL_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define XGMAC2_REGACC_CTRL_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define XGMAC2_REGACC_CTRL_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_XGMAC2_REGACC_CTRL_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_XGMAC2_REGACC_CTRL_BAS_BUSY 0x1

/*! @} */

/*! \defgroup MAC3_IF_CFG Register MAC3_IF_CFG - MAC 3 Interface Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_IF_CFG 0x1300
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_IF_CFG 0x18441300u

/*! Register Reset Value */
#define MAC3_IF_CFG_RST 0x0000u

/*! Field CFG_2G5 - 2.5Gbps Speed Interface Mode */
#define MAC3_IF_CFG_CFG_2G5_POS 0
/*! Field CFG_2G5 - 2.5Gbps Speed Interface Mode */
#define MAC3_IF_CFG_CFG_2G5_MASK 0x1u
/*! Constant GMII - GMII */
#define CONST_MAC3_IF_CFG_CFG_2G5_GMII 0x0
/*! Constant XGMII - XGMII */
#define CONST_MAC3_IF_CFG_CFG_2G5_XGMII 0x1

/*! Field CFG_1G - Gigabit Speed Interface Mode */
#define MAC3_IF_CFG_CFG_1G_POS 1
/*! Field CFG_1G - Gigabit Speed Interface Mode */
#define MAC3_IF_CFG_CFG_1G_MASK 0x2u
/*! Constant LMAC - LMAC */
#define CONST_MAC3_IF_CFG_CFG_1G_LMAC 0x0
/*! Constant XGMAC - XGMAC */
#define CONST_MAC3_IF_CFG_CFG_1G_XGMAC 0x1

/*! Field CFG_FE - Fast Ethernet Speed Interface Mode */
#define MAC3_IF_CFG_CFG_FE_POS 2
/*! Field CFG_FE - Fast Ethernet Speed Interface Mode */
#define MAC3_IF_CFG_CFG_FE_MASK 0x4u
/*! Constant MII - MII */
#define CONST_MAC3_IF_CFG_CFG_FE_MII 0x0
/*! Constant GMII - GMII */
#define CONST_MAC3_IF_CFG_CFG_FE_GMII 0x1

/*! @} */

/*! \defgroup MAC3_OP_CFG Register MAC3_OP_CFG - MAC 3 Operation Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_OP_CFG 0x1304
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_OP_CFG 0x18441304u

/*! Register Reset Value */
#define MAC3_OP_CFG_RST 0x0120u

/*! Field RX_SPTAG - RX direction special tag */
#define MAC3_OP_CFG_RX_SPTAG_POS 0
/*! Field RX_SPTAG - RX direction special tag */
#define MAC3_OP_CFG_RX_SPTAG_MASK 0x3u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC3_OP_CFG_RX_SPTAG_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC3_OP_CFG_RX_SPTAG_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC3_OP_CFG_RX_SPTAG_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC3_OP_CFG_RX_SPTAG_MODE3 0x3

/*! Field RX_TIME - RX direction time stamp */
#define MAC3_OP_CFG_RX_TIME_POS 2
/*! Field RX_TIME - RX direction time stamp */
#define MAC3_OP_CFG_RX_TIME_MASK 0xCu
/*! Constant MODE0 - MODE0 */
#define CONST_MAC3_OP_CFG_RX_TIME_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC3_OP_CFG_RX_TIME_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC3_OP_CFG_RX_TIME_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC3_OP_CFG_RX_TIME_MODE3 0x3

/*! Field RX_FCS - RX direction FCS */
#define MAC3_OP_CFG_RX_FCS_POS 4
/*! Field RX_FCS - RX direction FCS */
#define MAC3_OP_CFG_RX_FCS_MASK 0x30u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC3_OP_CFG_RX_FCS_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC3_OP_CFG_RX_FCS_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC3_OP_CFG_RX_FCS_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC3_OP_CFG_RX_FCS_MODE3 0x3

/*! Field TX_SPTAG - TX direction special tag */
#define MAC3_OP_CFG_TX_SPTAG_POS 6
/*! Field TX_SPTAG - TX direction special tag */
#define MAC3_OP_CFG_TX_SPTAG_MASK 0xC0u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC3_OP_CFG_TX_SPTAG_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC3_OP_CFG_TX_SPTAG_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC3_OP_CFG_TX_SPTAG_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC3_OP_CFG_TX_SPTAG_MODE3 0x3

/*! Field TX_FCS_RM - TX direction FCS removal */
#define MAC3_OP_CFG_TX_FCS_RM_POS 8
/*! Field TX_FCS_RM - TX direction FCS removal */
#define MAC3_OP_CFG_TX_FCS_RM_MASK 0x100u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC3_OP_CFG_TX_FCS_RM_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC3_OP_CFG_TX_FCS_RM_MODE1 0x1

/*! Field TX_FCS_INS - TX direction FCS insertion */
#define MAC3_OP_CFG_TX_FCS_INS_POS 9
/*! Field TX_FCS_INS - TX direction FCS insertion */
#define MAC3_OP_CFG_TX_FCS_INS_MASK 0x200u
/*! Constant MODE0 - MODE 0 */
#define CONST_MAC3_OP_CFG_TX_FCS_INS_MODE0 0x0
/*! Constant MDIO1 - MODE 1 */
#define CONST_MAC3_OP_CFG_TX_FCS_INS_MDIO1 0x1

/*! @} */

/*! \defgroup MAC3_MTU_CFG Register MAC3_MTU_CFG - MAC 3 MTU Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_MTU_CFG 0x1308
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_MTU_CFG 0x18441308u

/*! Register Reset Value */
#define MAC3_MTU_CFG_RST 0x2800u

/*! Field MTU - Maximum Frame Length Size in byte */
#define MAC3_MTU_CFG_MTU_POS 0
/*! Field MTU - Maximum Frame Length Size in byte */
#define MAC3_MTU_CFG_MTU_MASK 0x3FFFu

/*! @} */

/*! \defgroup MAC3_GINT_CFG Register MAC3_GINT_CFG - MAC 3 G.INT Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_CFG 0x130C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_CFG 0x1844130Cu

/*! Register Reset Value */
#define MAC3_GINT_CFG_RST 0x0000u

/*! Field GINT_EN - G.INT Enable */
#define MAC3_GINT_CFG_GINT_EN_POS 0
/*! Field GINT_EN - G.INT Enable */
#define MAC3_GINT_CFG_GINT_EN_MASK 0x1u
/*! Constant DISABLE - Disable */
#define CONST_MAC3_GINT_CFG_GINT_EN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_MAC3_GINT_CFG_GINT_EN_ENABLE 0x1

/*! Field ENCAP_MD - G.INT Encapsulation Mode */
#define MAC3_GINT_CFG_ENCAP_MD_POS 1
/*! Field ENCAP_MD - G.INT Encapsulation Mode */
#define MAC3_GINT_CFG_ENCAP_MD_MASK 0x2u
/*! Constant NATIVE - Native */
#define CONST_MAC3_GINT_CFG_ENCAP_MD_NATIVE 0x0
/*! Constant ETHERNET - Ethernet */
#define CONST_MAC3_GINT_CFG_ENCAP_MD_ETHERNET 0x1

/*! Field LEN_MD - Encapsulation Length Mode */
#define MAC3_GINT_CFG_LEN_MD_POS 2
/*! Field LEN_MD - Encapsulation Length Mode */
#define MAC3_GINT_CFG_LEN_MD_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_MAC3_GINT_CFG_LEN_MD_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC3_GINT_CFG_LEN_MD_EN 0x1

/*! Field QID - Starting Queue ID for stream 0 for this MAC */
#define MAC3_GINT_CFG_QID_POS 3
/*! Field QID - Starting Queue ID for stream 0 for this MAC */
#define MAC3_GINT_CFG_QID_MASK 0xF8u

/*! Field NUM_STEAM - Number of streams: */
#define MAC3_GINT_CFG_NUM_STEAM_POS 8
/*! Field NUM_STEAM - Number of streams: */
#define MAC3_GINT_CFG_NUM_STEAM_MASK 0x100u
/*! Constant V8 - 8 */
#define CONST_MAC3_GINT_CFG_NUM_STEAM_V8 0x0
/*! Constant V16 - 16 */
#define CONST_MAC3_GINT_CFG_NUM_STEAM_V16 0x1

/*! Field POS_SID - Bit position of the first valid bit in stream ID in G.INT header */
#define MAC3_GINT_CFG_POS_SID_POS 9
/*! Field POS_SID - Bit position of the first valid bit in stream ID in G.INT header */
#define MAC3_GINT_CFG_POS_SID_MASK 0x600u

/*! Field CQESHIFT - Starting Stream ID in CQE Backpressure Bitmap for this MAC */
#define MAC3_GINT_CFG_CQESHIFT_POS 11
/*! Field CQESHIFT - Starting Stream ID in CQE Backpressure Bitmap for this MAC */
#define MAC3_GINT_CFG_CQESHIFT_MASK 0xF800u

/*! @} */

/*! \defgroup MAC3_GINT_HD0_CFG Register MAC3_GINT_HD0_CFG - MAC 3 G.INT Header Word 0 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_HD0_CFG 0x1320
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_HD0_CFG 0x18441320u

/*! Register Reset Value */
#define MAC3_GINT_HD0_CFG_RST 0x0000u

/*! Field HD01 - Ethernet Header Byte 0 and 1 */
#define MAC3_GINT_HD0_CFG_HD01_POS 0
/*! Field HD01 - Ethernet Header Byte 0 and 1 */
#define MAC3_GINT_HD0_CFG_HD01_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_GINT_HD1_CFG Register MAC3_GINT_HD1_CFG - MAC 3 G.INT Header Word 1 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_HD1_CFG 0x1324
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_HD1_CFG 0x18441324u

/*! Register Reset Value */
#define MAC3_GINT_HD1_CFG_RST 0x0000u

/*! Field HD23 - Ethernet Header Byte 2 and 3 */
#define MAC3_GINT_HD1_CFG_HD23_POS 0
/*! Field HD23 - Ethernet Header Byte 2 and 3 */
#define MAC3_GINT_HD1_CFG_HD23_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_GINT_HD2_CFG Register MAC3_GINT_HD2_CFG - MAC 3 G.INT Header Word 2 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_HD2_CFG 0x1328
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_HD2_CFG 0x18441328u

/*! Register Reset Value */
#define MAC3_GINT_HD2_CFG_RST 0x0000u

/*! Field HD45 - Ethernet Header Byte 4 and 5 */
#define MAC3_GINT_HD2_CFG_HD45_POS 0
/*! Field HD45 - Ethernet Header Byte 4 and 5 */
#define MAC3_GINT_HD2_CFG_HD45_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_GINT_HD3_CFG Register MAC3_GINT_HD3_CFG - MAC 3 G.INT Header Word 3 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_HD3_CFG 0x132C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_HD3_CFG 0x1844132Cu

/*! Register Reset Value */
#define MAC3_GINT_HD3_CFG_RST 0x0000u

/*! Field HD67 - Ethernet Header Byte 6 and 7 */
#define MAC3_GINT_HD3_CFG_HD67_POS 0
/*! Field HD67 - Ethernet Header Byte 6 and 7 */
#define MAC3_GINT_HD3_CFG_HD67_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_GINT_HD4_CFG Register MAC3_GINT_HD4_CFG - MAC 3 G.INT Header Word 4 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_HD4_CFG 0x1330
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_HD4_CFG 0x18441330u

/*! Register Reset Value */
#define MAC3_GINT_HD4_CFG_RST 0x0000u

/*! Field HD89 - Ethernet Header Byte 8 and 9 */
#define MAC3_GINT_HD4_CFG_HD89_POS 0
/*! Field HD89 - Ethernet Header Byte 8 and 9 */
#define MAC3_GINT_HD4_CFG_HD89_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_GINT_HD5_CFG Register MAC3_GINT_HD5_CFG - MAC 3 G.INT Header Word 5 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_HD5_CFG 0x1334
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_HD5_CFG 0x18441334u

/*! Register Reset Value */
#define MAC3_GINT_HD5_CFG_RST 0x0000u

/*! Field HDAB - Ethernet Header Byte 10 and 11 */
#define MAC3_GINT_HD5_CFG_HDAB_POS 0
/*! Field HDAB - Ethernet Header Byte 10 and 11 */
#define MAC3_GINT_HD5_CFG_HDAB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_GINT_HD6_CFG Register MAC3_GINT_HD6_CFG - MAC 3 G.INT Header Word 6 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_GINT_HD6_CFG 0x1338
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_GINT_HD6_CFG 0x18441338u

/*! Register Reset Value */
#define MAC3_GINT_HD6_CFG_RST 0x0000u

/*! Field HDCD - Ethernet Header Byte 12 and 13 */
#define MAC3_GINT_HD6_CFG_HDCD_POS 0
/*! Field HDCD - Ethernet Header Byte 12 and 13 */
#define MAC3_GINT_HD6_CFG_HDCD_MASK 0xFFFFu

/*! @} */

/*! \defgroup LMAC3_RTXB_CTL Register LMAC3_RTXB_CTL - Legacy MAC 3 Interface Receive Buffer Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define LMAC3_RTXB_CTL 0x133C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_LMAC3_RTXB_CTL 0x1844133Cu

/*! Register Reset Value */
#define LMAC3_RTXB_CTL_RST 0x0101u

/*! Field RBUF_DLY_WP - RX Buffer Delay Write Pointer */
#define LMAC3_RTXB_CTL_RBUF_DLY_WP_POS 0
/*! Field RBUF_DLY_WP - RX Buffer Delay Write Pointer */
#define LMAC3_RTXB_CTL_RBUF_DLY_WP_MASK 0x7u

/*! Field RBUF_OFL - Receive Buffer Overflow Indicator */
#define LMAC3_RTXB_CTL_RBUF_OFL_POS 3
/*! Field RBUF_OFL - Receive Buffer Overflow Indicator */
#define LMAC3_RTXB_CTL_RBUF_OFL_MASK 0x8u
/*! Constant NONE - NONE */
#define CONST_LMAC3_RTXB_CTL_RBUF_OFL_NONE 0x0
/*! Constant OFL - OFL */
#define CONST_LMAC3_RTXB_CTL_RBUF_OFL_OFL 0x1

/*! Field RBUF_UFL - Receive Buffer Underflow Indicator */
#define LMAC3_RTXB_CTL_RBUF_UFL_POS 4
/*! Field RBUF_UFL - Receive Buffer Underflow Indicator */
#define LMAC3_RTXB_CTL_RBUF_UFL_MASK 0x10u
/*! Constant NONE - NONE */
#define CONST_LMAC3_RTXB_CTL_RBUF_UFL_NONE 0x0
/*! Constant UFL - UFL */
#define CONST_LMAC3_RTXB_CTL_RBUF_UFL_UFL 0x1

/*! Field RBUF_INIT - Receive Buffer Reset */
#define LMAC3_RTXB_CTL_RBUF_INIT_POS 5
/*! Field RBUF_INIT - Receive Buffer Reset */
#define LMAC3_RTXB_CTL_RBUF_INIT_MASK 0x20u
/*! Constant NONE - NONE */
#define CONST_LMAC3_RTXB_CTL_RBUF_INIT_NONE 0x0
/*! Constant INIT - INIT */
#define CONST_LMAC3_RTXB_CTL_RBUF_INIT_INIT 0x1

/*! Field TBUF_DLY_WP - TX Buffer Delay Write Pointer */
#define LMAC3_RTXB_CTL_TBUF_DLY_WP_POS 8
/*! Field TBUF_DLY_WP - TX Buffer Delay Write Pointer */
#define LMAC3_RTXB_CTL_TBUF_DLY_WP_MASK 0x700u

/*! Field TBUF_OFL - Transmit Buffer Overflow Indicator */
#define LMAC3_RTXB_CTL_TBUF_OFL_POS 11
/*! Field TBUF_OFL - Transmit Buffer Overflow Indicator */
#define LMAC3_RTXB_CTL_TBUF_OFL_MASK 0x800u
/*! Constant NONE - NONE */
#define CONST_LMAC3_RTXB_CTL_TBUF_OFL_NONE 0x0
/*! Constant OFL - OFL */
#define CONST_LMAC3_RTXB_CTL_TBUF_OFL_OFL 0x1

/*! Field TBUF_UFL - Transmit Buffer Underflow Indicator */
#define LMAC3_RTXB_CTL_TBUF_UFL_POS 12
/*! Field TBUF_UFL - Transmit Buffer Underflow Indicator */
#define LMAC3_RTXB_CTL_TBUF_UFL_MASK 0x1000u
/*! Constant NONE - NONE */
#define CONST_LMAC3_RTXB_CTL_TBUF_UFL_NONE 0x0
/*! Constant UFL - UFL */
#define CONST_LMAC3_RTXB_CTL_TBUF_UFL_UFL 0x1

/*! Field TBUF_INIT - Transmit Buffer Reset */
#define LMAC3_RTXB_CTL_TBUF_INIT_POS 13
/*! Field TBUF_INIT - Transmit Buffer Reset */
#define LMAC3_RTXB_CTL_TBUF_INIT_MASK 0x2000u
/*! Constant NONE - NONE */
#define CONST_LMAC3_RTXB_CTL_TBUF_INIT_NONE 0x0
/*! Constant INIT - INIT */
#define CONST_LMAC3_RTXB_CTL_TBUF_INIT_INIT 0x1

/*! @} */

/*! \defgroup MAC3_TXTS_0 Register MAC3_TXTS_0 - MAC 3 TX Timestamp Bit 15 to 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_TXTS_0 0x1350
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_TXTS_0 0x18441350u

/*! Register Reset Value */
#define MAC3_TXTS_0_RST 0x0000u

/*! Field TTSLL - Time Stamp Bit 15 to 0 */
#define MAC3_TXTS_0_TTSLL_POS 0
/*! Field TTSLL - Time Stamp Bit 15 to 0 */
#define MAC3_TXTS_0_TTSLL_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_TXTS_1 Register MAC3_TXTS_1 - MAC 3 TX Timestamp Bit 31 to 16 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_TXTS_1 0x1354
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_TXTS_1 0x18441354u

/*! Register Reset Value */
#define MAC3_TXTS_1_RST 0x0000u

/*! Field TTSLH - Time Stamp Bit 31 to 16 */
#define MAC3_TXTS_1_TTSLH_POS 0
/*! Field TTSLH - Time Stamp Bit 31 to 16 */
#define MAC3_TXTS_1_TTSLH_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_TXTS_2 Register MAC3_TXTS_2 - MAC 3 TX Timestamp Bit 47 to 32 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_TXTS_2 0x1358
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_TXTS_2 0x18441358u

/*! Register Reset Value */
#define MAC3_TXTS_2_RST 0x0000u

/*! Field TTSHL - Time Stamp Bit 47 to 32 */
#define MAC3_TXTS_2_TTSHL_POS 0
/*! Field TTSHL - Time Stamp Bit 47 to 32 */
#define MAC3_TXTS_2_TTSHL_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_TXTS_3 Register MAC3_TXTS_3 - MAC 3 TX Timestamp Bit 63 to 32 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_TXTS_3 0x135C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_TXTS_3 0x1844135Cu

/*! Register Reset Value */
#define MAC3_TXTS_3_RST 0x0000u

/*! Field TTSHH - Time Stamp Bit 63 to 48 */
#define MAC3_TXTS_3_TTSHH_POS 0
/*! Field TTSHH - Time Stamp Bit 63 to 48 */
#define MAC3_TXTS_3_TTSHH_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC3_TXTS_CIC Register MAC3_TXTS_CIC - MAC 3 TX Timestamp CIC */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_TXTS_CIC 0x1360
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_TXTS_CIC 0x18441360u

/*! Register Reset Value */
#define MAC3_TXTS_CIC_RST 0x0000u

/*! Field CIC - Time stamp CIC */
#define MAC3_TXTS_CIC_CIC_POS 0
/*! Field CIC - Time stamp CIC */
#define MAC3_TXTS_CIC_CIC_MASK 0x3u
/*! Constant DIS - DIS */
#define CONST_MAC3_TXTS_CIC_CIC_DIS 0x0
/*! Constant IP - IP */
#define CONST_MAC3_TXTS_CIC_CIC_IP 0x1
/*! Constant IPPL - IPPL */
#define CONST_MAC3_TXTS_CIC_CIC_IPPL 0x2
/*! Constant ALL - ALL */
#define CONST_MAC3_TXTS_CIC_CIC_ALL 0x3

/*! Field OST_AVAIL - Time stamp One Step Time stamp Available */
#define MAC3_TXTS_CIC_OST_AVAIL_POS 2
/*! Field OST_AVAIL - Time stamp One Step Time stamp Available */
#define MAC3_TXTS_CIC_OST_AVAIL_MASK 0x4u

/*! Field OSTC - Time stamp One Step Correction Enable */
#define MAC3_TXTS_CIC_OSTC_POS 3
/*! Field OSTC - Time stamp One Step Correction Enable */
#define MAC3_TXTS_CIC_OSTC_MASK 0x8u

/*! Field TTSE - Time Stamp Capture Enable */
#define MAC3_TXTS_CIC_TTSE_POS 4
/*! Field TTSE - Time Stamp Capture Enable */
#define MAC3_TXTS_CIC_TTSE_MASK 0x10u

/*! @} */

/*! \defgroup MAC3_TXTS_ACC Register MAC3_TXTS_ACC - MAC 3 TX Timestamp Access */
/*! @{ */

/*! Register Offset (relative) */
#define MAC3_TXTS_ACC 0x1364
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC3_TXTS_ACC 0x18441364u

/*! Register Reset Value */
#define MAC3_TXTS_ACC_RST 0x0000u

/*! Field ADDR - Time stamp FIFO address */
#define MAC3_TXTS_ACC_ADDR_POS 0
/*! Field ADDR - Time stamp FIFO address */
#define MAC3_TXTS_ACC_ADDR_MASK 0x3Fu

/*! Field OPMOD - Access Operation Mode */
#define MAC3_TXTS_ACC_OPMOD_POS 14
/*! Field OPMOD - Access Operation Mode */
#define MAC3_TXTS_ACC_OPMOD_MASK 0x4000u
/*! Constant RD - RD */
#define CONST_MAC3_TXTS_ACC_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_MAC3_TXTS_ACC_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define MAC3_TXTS_ACC_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define MAC3_TXTS_ACC_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_MAC3_TXTS_ACC_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_MAC3_TXTS_ACC_BAS_BUSY 0x1

/*! @} */

/*! \defgroup PHY3_MODE Register PHY3_MODE - PHY 3 Mode Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define PHY3_MODE 0x1370
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_PHY3_MODE 0x18441370u

/*! Register Reset Value */
#define PHY3_MODE_RST 0x9800u

/*! Field FCONRX - Flow Control Mode RX */
#define PHY3_MODE_FCONRX_POS 5
/*! Field FCONRX - Flow Control Mode RX */
#define PHY3_MODE_FCONRX_MASK 0x60u
/*! Constant AUTO - AUTO */
#define CONST_PHY3_MODE_FCONRX_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY3_MODE_FCONRX_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY3_MODE_FCONRX_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY3_MODE_FCONRX_DIS 0x3

/*! Field FCONTX - Flow Control Mode TX */
#define PHY3_MODE_FCONTX_POS 7
/*! Field FCONTX - Flow Control Mode TX */
#define PHY3_MODE_FCONTX_MASK 0x180u
/*! Constant AUTO - AUTO */
#define CONST_PHY3_MODE_FCONTX_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY3_MODE_FCONTX_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY3_MODE_FCONTX_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY3_MODE_FCONTX_DIS 0x3

/*! Field FDUP - Full Duplex Control */
#define PHY3_MODE_FDUP_POS 9
/*! Field FDUP - Full Duplex Control */
#define PHY3_MODE_FDUP_MASK 0x600u
/*! Constant AUTO - AUTO */
#define CONST_PHY3_MODE_FDUP_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY3_MODE_FDUP_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY3_MODE_FDUP_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY3_MODE_FDUP_DIS 0x3

/*! Field SPEED_LSB - Speed Control Bit 2 to 0 */
#define PHY3_MODE_SPEED_LSB_POS 11
/*! Field SPEED_LSB - Speed Control Bit 2 to 0 */
#define PHY3_MODE_SPEED_LSB_MASK 0x1800u

/*! Field LNKST - Link Status Control */
#define PHY3_MODE_LNKST_POS 13
/*! Field LNKST - Link Status Control */
#define PHY3_MODE_LNKST_MASK 0x6000u
/*! Constant AUTO - AUTO */
#define CONST_PHY3_MODE_LNKST_AUTO 0x0
/*! Constant UP - UP */
#define CONST_PHY3_MODE_LNKST_UP 0x1
/*! Constant DOWN - DOWN */
#define CONST_PHY3_MODE_LNKST_DOWN 0x2
/*! Constant RES - RES */
#define CONST_PHY3_MODE_LNKST_RES 0x3

/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY3_MODE_SPEED_MSB_POS 15
/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY3_MODE_SPEED_MSB_MASK 0x8000u

/*! @} */

/*! \defgroup PHY_STAT_3 Register PHY_STAT_3 - PHY 3 Status */
/*! @{ */

/*! Register Offset (relative) */
#define PHY_STAT_3 0x1374
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_PHY_STAT_3 0x18441374u

/*! Register Reset Value */
#define PHY_STAT_3_RST 0x0000u

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define PHY_STAT_3_TXPAUEN_POS 0
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define PHY_STAT_3_TXPAUEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_3_TXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_3_TXPAUEN_EN 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define PHY_STAT_3_RXPAUEN_POS 1
/*! Field RXPAUEN - Receive Pause Enable Status */
#define PHY_STAT_3_RXPAUEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_3_RXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_3_RXPAUEN_EN 0x1

/*! Field FDUP - Full Duplex Status */
#define PHY_STAT_3_FDUP_POS 2
/*! Field FDUP - Full Duplex Status */
#define PHY_STAT_3_FDUP_MASK 0x4u
/*! Constant HALF - HALF */
#define CONST_PHY_STAT_3_FDUP_HALF 0x0
/*! Constant FULL - FULL */
#define CONST_PHY_STAT_3_FDUP_FULL 0x1

/*! Field SPEED_LSB - Speed Control Bit 1 to 0 */
#define PHY_STAT_3_SPEED_LSB_POS 3
/*! Field SPEED_LSB - Speed Control Bit 1 to 0 */
#define PHY_STAT_3_SPEED_LSB_MASK 0x18u

/*! Field LSTAT - Link Status */
#define PHY_STAT_3_LSTAT_POS 5
/*! Field LSTAT - Link Status */
#define PHY_STAT_3_LSTAT_MASK 0x20u
/*! Constant DOWN - DOWN */
#define CONST_PHY_STAT_3_LSTAT_DOWN 0x0
/*! Constant UP - UP */
#define CONST_PHY_STAT_3_LSTAT_UP 0x1

/*! Field EEE_CAPABLE - PHY and link partner support EEE for current speed */
#define PHY_STAT_3_EEE_CAPABLE_POS 7
/*! Field EEE_CAPABLE - PHY and link partner support EEE for current speed */
#define PHY_STAT_3_EEE_CAPABLE_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_3_EEE_CAPABLE_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_3_EEE_CAPABLE_EN 0x1

/*! Field CLK_STOP_CAPABLE - PHY supports TX Clock Stop */
#define PHY_STAT_3_CLK_STOP_CAPABLE_POS 8
/*! Field CLK_STOP_CAPABLE - PHY supports TX Clock Stop */
#define PHY_STAT_3_CLK_STOP_CAPABLE_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_3_CLK_STOP_CAPABLE_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_3_CLK_STOP_CAPABLE_EN 0x1

/*! Field TXACT - TX Traffic Active */
#define PHY_STAT_3_TXACT_POS 9
/*! Field TXACT - TX Traffic Active */
#define PHY_STAT_3_TXACT_MASK 0x200u
/*! Constant NOT_ACTIVE - NOT Active */
#define CONST_PHY_STAT_3_TXACT_NOT_ACTIVE 0x0
/*! Constant ACT - ACT */
#define CONST_PHY_STAT_3_TXACT_ACT 0x1

/*! Field RXACT - RX Traffic Active */
#define PHY_STAT_3_RXACT_POS 10
/*! Field RXACT - RX Traffic Active */
#define PHY_STAT_3_RXACT_MASK 0x400u
/*! Constant NOT_ACTIVE - NOT Active */
#define CONST_PHY_STAT_3_RXACT_NOT_ACTIVE 0x0
/*! Constant ACT - ACT */
#define CONST_PHY_STAT_3_RXACT_ACT 0x1

/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY_STAT_3_SPEED_MSB_POS 11
/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY_STAT_3_SPEED_MSB_MASK 0x800u

/*! @} */

/*! \defgroup ANEG_EEE_3 Register ANEG_EEE_3 - PHY 3 EEE auto negotiation overrides */
/*! @{ */

/*! Register Offset (relative) */
#define ANEG_EEE_3 0x1378
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_ANEG_EEE_3 0x18441378u

/*! Register Reset Value */
#define ANEG_EEE_3_RST 0x0000u

/*! Field EEE_CAPABLE - EEE Capable */
#define ANEG_EEE_3_EEE_CAPABLE_POS 0
/*! Field EEE_CAPABLE - EEE Capable */
#define ANEG_EEE_3_EEE_CAPABLE_MASK 0x3u
/*! Constant AUTO - AUTO */
#define CONST_ANEG_EEE_3_EEE_CAPABLE_AUTO 0x0
/*! Constant EN - EN */
#define CONST_ANEG_EEE_3_EEE_CAPABLE_EN 0x1
/*! Constant RES - RES */
#define CONST_ANEG_EEE_3_EEE_CAPABLE_RES 0x2
/*! Constant DIS - DIS */
#define CONST_ANEG_EEE_3_EEE_CAPABLE_DIS 0x3

/*! Field CLK_STOP_CAPABLE - Clock Stop Capable */
#define ANEG_EEE_3_CLK_STOP_CAPABLE_POS 2
/*! Field CLK_STOP_CAPABLE - Clock Stop Capable */
#define ANEG_EEE_3_CLK_STOP_CAPABLE_MASK 0xCu
/*! Constant AUTO - AUTO */
#define CONST_ANEG_EEE_3_CLK_STOP_CAPABLE_AUTO 0x0
/*! Constant EN - EN */
#define CONST_ANEG_EEE_3_CLK_STOP_CAPABLE_EN 0x1
/*! Constant RES - RES */
#define CONST_ANEG_EEE_3_CLK_STOP_CAPABLE_RES 0x2
/*! Constant DIS - DIS */
#define CONST_ANEG_EEE_3_CLK_STOP_CAPABLE_DIS 0x3

/*! @} */

/*! \defgroup XGMAC3_CTRL Register XGMAC3_CTRL - XGMAC 3 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC3_CTRL 0x1380
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC3_CTRL 0x18441380u

/*! Register Reset Value */
#define XGMAC3_CTRL_RST 0x0000u

/*! Field CPC - TX direction CRC CTRL */
#define XGMAC3_CTRL_CPC_POS 0
/*! Field CPC - TX direction CRC CTRL */
#define XGMAC3_CTRL_CPC_MASK 0x3u
/*! Constant PADINS - PADINS */
#define CONST_XGMAC3_CTRL_CPC_PADINS 0x0
/*! Constant CRCINS - CRCINS */
#define CONST_XGMAC3_CTRL_CPC_CRCINS 0x1
/*! Constant NIL - NIL */
#define CONST_XGMAC3_CTRL_CPC_NIL 0x2
/*! Constant RES - RES */
#define CONST_XGMAC3_CTRL_CPC_RES 0x3

/*! Field DIS_RX - MAC Receiver Disable Control */
#define XGMAC3_CTRL_DIS_RX_POS 2
/*! Field DIS_RX - MAC Receiver Disable Control */
#define XGMAC3_CTRL_DIS_RX_MASK 0x4u
/*! Constant NIL - NIL */
#define CONST_XGMAC3_CTRL_DIS_RX_NIL 0x0
/*! Constant DIS - DIS */
#define CONST_XGMAC3_CTRL_DIS_RX_DIS 0x1

/*! Field DIS_TX - MAC Transmitter Disable Control */
#define XGMAC3_CTRL_DIS_TX_POS 3
/*! Field DIS_TX - MAC Transmitter Disable Control */
#define XGMAC3_CTRL_DIS_TX_MASK 0x8u
/*! Constant NIL - NIL */
#define CONST_XGMAC3_CTRL_DIS_TX_NIL 0x0
/*! Constant DIS - DIS */
#define CONST_XGMAC3_CTRL_DIS_TX_DIS 0x1

/*! @} */

/*! \defgroup XGMAC3_REGACC_DATA0 Register XGMAC3_REGACC_DATA0 - XGMAC 3 Register Access Low Data */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC3_REGACC_DATA0 0x1390
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC3_REGACC_DATA0 0x18441390u

/*! Register Reset Value */
#define XGMAC3_REGACC_DATA0_RST 0x0000u

/*! Field LOW - Register Data Bit 15 to 0 */
#define XGMAC3_REGACC_DATA0_LOW_POS 0
/*! Field LOW - Register Data Bit 15 to 0 */
#define XGMAC3_REGACC_DATA0_LOW_MASK 0xFFFFu

/*! @} */

/*! \defgroup XGMAC3_REGACC_DATA1 Register XGMAC3_REGACC_DATA1 - XGMAC 3 Register Access High Data */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC3_REGACC_DATA1 0x1394
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC3_REGACC_DATA1 0x18441394u

/*! Register Reset Value */
#define XGMAC3_REGACC_DATA1_RST 0x0000u

/*! Field HIGH - Register Data Bit 31 to 16 */
#define XGMAC3_REGACC_DATA1_HIGH_POS 0
/*! Field HIGH - Register Data Bit 31 to 16 */
#define XGMAC3_REGACC_DATA1_HIGH_MASK 0xFFFFu

/*! @} */

/*! \defgroup XGMAC3_REGACC_CTRL Register XGMAC3_REGACC_CTRL - XGMAC 3 Register Access Control */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC3_REGACC_CTRL 0x1398
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC3_REGACC_CTRL 0x18441398u

/*! Register Reset Value */
#define XGMAC3_REGACC_CTRL_RST 0x0000u

/*! Field ADDR - Register address */
#define XGMAC3_REGACC_CTRL_ADDR_POS 0
/*! Field ADDR - Register address */
#define XGMAC3_REGACC_CTRL_ADDR_MASK 0x3FFFu

/*! Field OPMOD - Access Operation Mode */
#define XGMAC3_REGACC_CTRL_OPMOD_POS 14
/*! Field OPMOD - Access Operation Mode */
#define XGMAC3_REGACC_CTRL_OPMOD_MASK 0x4000u
/*! Constant RD - RD */
#define CONST_XGMAC3_REGACC_CTRL_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_XGMAC3_REGACC_CTRL_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define XGMAC3_REGACC_CTRL_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define XGMAC3_REGACC_CTRL_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_XGMAC3_REGACC_CTRL_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_XGMAC3_REGACC_CTRL_BAS_BUSY 0x1

/*! @} */

/*! \defgroup MAC4_IF_CFG Register MAC4_IF_CFG - MAC 4 Interface Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_IF_CFG 0x1400
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_IF_CFG 0x18441400u

/*! Register Reset Value */
#define MAC4_IF_CFG_RST 0x0000u

/*! Field CFG_2G5 - 2.5Gbps Speed Interface Mode */
#define MAC4_IF_CFG_CFG_2G5_POS 0
/*! Field CFG_2G5 - 2.5Gbps Speed Interface Mode */
#define MAC4_IF_CFG_CFG_2G5_MASK 0x1u
/*! Constant GMII - GMII */
#define CONST_MAC4_IF_CFG_CFG_2G5_GMII 0x0
/*! Constant XGMII - XGMII */
#define CONST_MAC4_IF_CFG_CFG_2G5_XGMII 0x1

/*! Field CFG_1G - Gigabit Speed Interface Mode */
#define MAC4_IF_CFG_CFG_1G_POS 1
/*! Field CFG_1G - Gigabit Speed Interface Mode */
#define MAC4_IF_CFG_CFG_1G_MASK 0x2u
/*! Constant LMAC - LMAC */
#define CONST_MAC4_IF_CFG_CFG_1G_LMAC 0x0
/*! Constant XGMAC - XGMAC */
#define CONST_MAC4_IF_CFG_CFG_1G_XGMAC 0x1

/*! Field CFG_FE - Fast Ethernet Speed Interface Mode */
#define MAC4_IF_CFG_CFG_FE_POS 2
/*! Field CFG_FE - Fast Ethernet Speed Interface Mode */
#define MAC4_IF_CFG_CFG_FE_MASK 0x4u
/*! Constant MII - MII */
#define CONST_MAC4_IF_CFG_CFG_FE_MII 0x0
/*! Constant GMII - GMII */
#define CONST_MAC4_IF_CFG_CFG_FE_GMII 0x1

/*! @} */

/*! \defgroup MAC4_OP_CFG Register MAC4_OP_CFG - MAC 4 Operation Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_OP_CFG 0x1404
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_OP_CFG 0x18441404u

/*! Register Reset Value */
#define MAC4_OP_CFG_RST 0x0120u

/*! Field RX_SPTAG - RX direction special tag */
#define MAC4_OP_CFG_RX_SPTAG_POS 0
/*! Field RX_SPTAG - RX direction special tag */
#define MAC4_OP_CFG_RX_SPTAG_MASK 0x3u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC4_OP_CFG_RX_SPTAG_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC4_OP_CFG_RX_SPTAG_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC4_OP_CFG_RX_SPTAG_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC4_OP_CFG_RX_SPTAG_MODE3 0x3

/*! Field RX_TIME - RX direction time stamp */
#define MAC4_OP_CFG_RX_TIME_POS 2
/*! Field RX_TIME - RX direction time stamp */
#define MAC4_OP_CFG_RX_TIME_MASK 0xCu
/*! Constant MODE0 - MODE0 */
#define CONST_MAC4_OP_CFG_RX_TIME_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC4_OP_CFG_RX_TIME_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC4_OP_CFG_RX_TIME_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC4_OP_CFG_RX_TIME_MODE3 0x3

/*! Field RX_FCS - RX direction FCS */
#define MAC4_OP_CFG_RX_FCS_POS 4
/*! Field RX_FCS - RX direction FCS */
#define MAC4_OP_CFG_RX_FCS_MASK 0x30u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC4_OP_CFG_RX_FCS_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC4_OP_CFG_RX_FCS_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC4_OP_CFG_RX_FCS_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC4_OP_CFG_RX_FCS_MODE3 0x3

/*! Field TX_SPTAG - TX direction special tag */
#define MAC4_OP_CFG_TX_SPTAG_POS 6
/*! Field TX_SPTAG - TX direction special tag */
#define MAC4_OP_CFG_TX_SPTAG_MASK 0xC0u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC4_OP_CFG_TX_SPTAG_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC4_OP_CFG_TX_SPTAG_MODE1 0x1
/*! Constant MODE2 - MODE2 */
#define CONST_MAC4_OP_CFG_TX_SPTAG_MODE2 0x2
/*! Constant MODE3 - MODE3 */
#define CONST_MAC4_OP_CFG_TX_SPTAG_MODE3 0x3

/*! Field TX_FCS_RM - TX direction FCS removal */
#define MAC4_OP_CFG_TX_FCS_RM_POS 8
/*! Field TX_FCS_RM - TX direction FCS removal */
#define MAC4_OP_CFG_TX_FCS_RM_MASK 0x100u
/*! Constant MODE0 - MODE0 */
#define CONST_MAC4_OP_CFG_TX_FCS_RM_MODE0 0x0
/*! Constant MODE1 - MODE1 */
#define CONST_MAC4_OP_CFG_TX_FCS_RM_MODE1 0x1

/*! Field TX_FCS_INS - TX direction FCS insertion */
#define MAC4_OP_CFG_TX_FCS_INS_POS 9
/*! Field TX_FCS_INS - TX direction FCS insertion */
#define MAC4_OP_CFG_TX_FCS_INS_MASK 0x200u
/*! Constant MODE0 - MODE 0 */
#define CONST_MAC4_OP_CFG_TX_FCS_INS_MODE0 0x0
/*! Constant MDIO1 - MODE 1 */
#define CONST_MAC4_OP_CFG_TX_FCS_INS_MDIO1 0x1

/*! @} */

/*! \defgroup MAC4_MTU_CFG Register MAC4_MTU_CFG - MAC 4 MTU Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_MTU_CFG 0x1408
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_MTU_CFG 0x18441408u

/*! Register Reset Value */
#define MAC4_MTU_CFG_RST 0x2800u

/*! Field MTU - Maximum Frame Length Size in byte */
#define MAC4_MTU_CFG_MTU_POS 0
/*! Field MTU - Maximum Frame Length Size in byte */
#define MAC4_MTU_CFG_MTU_MASK 0x3FFFu

/*! @} */

/*! \defgroup MAC4_GINT_CFG Register MAC4_GINT_CFG - MAC 4 G.INT Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_CFG 0x140C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_CFG 0x1844140Cu

/*! Register Reset Value */
#define MAC4_GINT_CFG_RST 0x0000u

/*! Field GINT_EN - G.INT Enable */
#define MAC4_GINT_CFG_GINT_EN_POS 0
/*! Field GINT_EN - G.INT Enable */
#define MAC4_GINT_CFG_GINT_EN_MASK 0x1u
/*! Constant DISABLE - Disable */
#define CONST_MAC4_GINT_CFG_GINT_EN_DISABLE 0x0
/*! Constant ENABLE - Enable */
#define CONST_MAC4_GINT_CFG_GINT_EN_ENABLE 0x1

/*! Field ENCAP_MD - G.INT Encapsulation Mode */
#define MAC4_GINT_CFG_ENCAP_MD_POS 1
/*! Field ENCAP_MD - G.INT Encapsulation Mode */
#define MAC4_GINT_CFG_ENCAP_MD_MASK 0x2u
/*! Constant NATIVE - Native */
#define CONST_MAC4_GINT_CFG_ENCAP_MD_NATIVE 0x0
/*! Constant ETHERNET - Ethernet */
#define CONST_MAC4_GINT_CFG_ENCAP_MD_ETHERNET 0x1

/*! Field LEN_MD - Encapsulation Length Mode */
#define MAC4_GINT_CFG_LEN_MD_POS 2
/*! Field LEN_MD - Encapsulation Length Mode */
#define MAC4_GINT_CFG_LEN_MD_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_MAC4_GINT_CFG_LEN_MD_DIS 0x0
/*! Constant EN - EN */
#define CONST_MAC4_GINT_CFG_LEN_MD_EN 0x1

/*! Field QID - Starting Queue ID for stream 0 for this MAC */
#define MAC4_GINT_CFG_QID_POS 3
/*! Field QID - Starting Queue ID for stream 0 for this MAC */
#define MAC4_GINT_CFG_QID_MASK 0xF8u

/*! Field NUM_STEAM - Number of streams: */
#define MAC4_GINT_CFG_NUM_STEAM_POS 8
/*! Field NUM_STEAM - Number of streams: */
#define MAC4_GINT_CFG_NUM_STEAM_MASK 0x100u
/*! Constant V8 - 8 */
#define CONST_MAC4_GINT_CFG_NUM_STEAM_V8 0x0
/*! Constant V16 - 16 */
#define CONST_MAC4_GINT_CFG_NUM_STEAM_V16 0x1

/*! Field POS_SID - Bit position of the first valid bit in stream ID in G.INT header */
#define MAC4_GINT_CFG_POS_SID_POS 9
/*! Field POS_SID - Bit position of the first valid bit in stream ID in G.INT header */
#define MAC4_GINT_CFG_POS_SID_MASK 0x600u

/*! Field CQESHIFT - Starting Stream ID in CQE Backpressure Bitmap for this MAC */
#define MAC4_GINT_CFG_CQESHIFT_POS 11
/*! Field CQESHIFT - Starting Stream ID in CQE Backpressure Bitmap for this MAC */
#define MAC4_GINT_CFG_CQESHIFT_MASK 0xF800u

/*! @} */

/*! \defgroup MAC4_GINT_HD0_CFG Register MAC4_GINT_HD0_CFG - MAC 4 G.INT Header Word 0 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_HD0_CFG 0x1420
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_HD0_CFG 0x18441420u

/*! Register Reset Value */
#define MAC4_GINT_HD0_CFG_RST 0x0000u

/*! Field HD01 - Ethernet Header Byte 0 and 1 */
#define MAC4_GINT_HD0_CFG_HD01_POS 0
/*! Field HD01 - Ethernet Header Byte 0 and 1 */
#define MAC4_GINT_HD0_CFG_HD01_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_GINT_HD1_CFG Register MAC4_GINT_HD1_CFG - MAC 4 G.INT Header Word 1 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_HD1_CFG 0x1424
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_HD1_CFG 0x18441424u

/*! Register Reset Value */
#define MAC4_GINT_HD1_CFG_RST 0x0000u

/*! Field HD23 - Ethernet Header Byte 2 and 3 */
#define MAC4_GINT_HD1_CFG_HD23_POS 0
/*! Field HD23 - Ethernet Header Byte 2 and 3 */
#define MAC4_GINT_HD1_CFG_HD23_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_GINT_HD2_CFG Register MAC4_GINT_HD2_CFG - MAC 4 G.INT Header Word 2 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_HD2_CFG 0x1428
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_HD2_CFG 0x18441428u

/*! Register Reset Value */
#define MAC4_GINT_HD2_CFG_RST 0x0000u

/*! Field HD45 - Ethernet Header Byte 4 and 5 */
#define MAC4_GINT_HD2_CFG_HD45_POS 0
/*! Field HD45 - Ethernet Header Byte 4 and 5 */
#define MAC4_GINT_HD2_CFG_HD45_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_GINT_HD3_CFG Register MAC4_GINT_HD3_CFG - MAC 4 G.INT Header Word 3 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_HD3_CFG 0x142C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_HD3_CFG 0x1844142Cu

/*! Register Reset Value */
#define MAC4_GINT_HD3_CFG_RST 0x0000u

/*! Field HD67 - Ethernet Header Byte 6 and 7 */
#define MAC4_GINT_HD3_CFG_HD67_POS 0
/*! Field HD67 - Ethernet Header Byte 6 and 7 */
#define MAC4_GINT_HD3_CFG_HD67_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_GINT_HD4_CFG Register MAC4_GINT_HD4_CFG - MAC 4 G.INT Header Word 4 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_HD4_CFG 0x1430
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_HD4_CFG 0x18441430u

/*! Register Reset Value */
#define MAC4_GINT_HD4_CFG_RST 0x0000u

/*! Field HD89 - Ethernet Header Byte 8 and 9 */
#define MAC4_GINT_HD4_CFG_HD89_POS 0
/*! Field HD89 - Ethernet Header Byte 8 and 9 */
#define MAC4_GINT_HD4_CFG_HD89_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_GINT_HD5_CFG Register MAC4_GINT_HD5_CFG - MAC 4 G.INT Header Word 5 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_HD5_CFG 0x1434
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_HD5_CFG 0x18441434u

/*! Register Reset Value */
#define MAC4_GINT_HD5_CFG_RST 0x0000u

/*! Field HDAB - Ethernet Header Byte 10 and 11 */
#define MAC4_GINT_HD5_CFG_HDAB_POS 0
/*! Field HDAB - Ethernet Header Byte 10 and 11 */
#define MAC4_GINT_HD5_CFG_HDAB_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_GINT_HD6_CFG Register MAC4_GINT_HD6_CFG - MAC 4 G.INT Header Word 6 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_GINT_HD6_CFG 0x1438
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_GINT_HD6_CFG 0x18441438u

/*! Register Reset Value */
#define MAC4_GINT_HD6_CFG_RST 0x0000u

/*! Field HDCD - Ethernet Header Byte 12 and 13 */
#define MAC4_GINT_HD6_CFG_HDCD_POS 0
/*! Field HDCD - Ethernet Header Byte 12 and 13 */
#define MAC4_GINT_HD6_CFG_HDCD_MASK 0xFFFFu

/*! @} */

/*! \defgroup LMAC4_RTXB_CTL Register LMAC4_RTXB_CTL - Legacy MAC 4 Interface Receive Buffer Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define LMAC4_RTXB_CTL 0x143C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_LMAC4_RTXB_CTL 0x1844143Cu

/*! Register Reset Value */
#define LMAC4_RTXB_CTL_RST 0x0101u

/*! Field RBUF_DLY_WP - RX Buffer Delay Write Pointer */
#define LMAC4_RTXB_CTL_RBUF_DLY_WP_POS 0
/*! Field RBUF_DLY_WP - RX Buffer Delay Write Pointer */
#define LMAC4_RTXB_CTL_RBUF_DLY_WP_MASK 0x7u

/*! Field RBUF_OFL - Receive Buffer Overflow Indicator */
#define LMAC4_RTXB_CTL_RBUF_OFL_POS 3
/*! Field RBUF_OFL - Receive Buffer Overflow Indicator */
#define LMAC4_RTXB_CTL_RBUF_OFL_MASK 0x8u
/*! Constant NONE - NONE */
#define CONST_LMAC4_RTXB_CTL_RBUF_OFL_NONE 0x0
/*! Constant OFL - OFL */
#define CONST_LMAC4_RTXB_CTL_RBUF_OFL_OFL 0x1

/*! Field RBUF_UFL - Receive Buffer Underflow Indicator */
#define LMAC4_RTXB_CTL_RBUF_UFL_POS 4
/*! Field RBUF_UFL - Receive Buffer Underflow Indicator */
#define LMAC4_RTXB_CTL_RBUF_UFL_MASK 0x10u
/*! Constant NONE - NONE */
#define CONST_LMAC4_RTXB_CTL_RBUF_UFL_NONE 0x0
/*! Constant UFL - UFL */
#define CONST_LMAC4_RTXB_CTL_RBUF_UFL_UFL 0x1

/*! Field RBUF_INIT - Receive Buffer Reset */
#define LMAC4_RTXB_CTL_RBUF_INIT_POS 5
/*! Field RBUF_INIT - Receive Buffer Reset */
#define LMAC4_RTXB_CTL_RBUF_INIT_MASK 0x20u
/*! Constant NONE - NONE */
#define CONST_LMAC4_RTXB_CTL_RBUF_INIT_NONE 0x0
/*! Constant INIT - INIT */
#define CONST_LMAC4_RTXB_CTL_RBUF_INIT_INIT 0x1

/*! Field TBUF_DLY_WP - TX Buffer Delay Write Pointer */
#define LMAC4_RTXB_CTL_TBUF_DLY_WP_POS 8
/*! Field TBUF_DLY_WP - TX Buffer Delay Write Pointer */
#define LMAC4_RTXB_CTL_TBUF_DLY_WP_MASK 0x700u

/*! Field TBUF_OFL - Transmit Buffer Overflow Indicator */
#define LMAC4_RTXB_CTL_TBUF_OFL_POS 11
/*! Field TBUF_OFL - Transmit Buffer Overflow Indicator */
#define LMAC4_RTXB_CTL_TBUF_OFL_MASK 0x800u
/*! Constant NONE - NONE */
#define CONST_LMAC4_RTXB_CTL_TBUF_OFL_NONE 0x0
/*! Constant OFL - OFL */
#define CONST_LMAC4_RTXB_CTL_TBUF_OFL_OFL 0x1

/*! Field TBUF_UFL - Transmit Buffer Underflow Indicator */
#define LMAC4_RTXB_CTL_TBUF_UFL_POS 12
/*! Field TBUF_UFL - Transmit Buffer Underflow Indicator */
#define LMAC4_RTXB_CTL_TBUF_UFL_MASK 0x1000u
/*! Constant NONE - NONE */
#define CONST_LMAC4_RTXB_CTL_TBUF_UFL_NONE 0x0
/*! Constant UFL - UFL */
#define CONST_LMAC4_RTXB_CTL_TBUF_UFL_UFL 0x1

/*! Field TBUF_INIT - Transmit Buffer Reset */
#define LMAC4_RTXB_CTL_TBUF_INIT_POS 13
/*! Field TBUF_INIT - Transmit Buffer Reset */
#define LMAC4_RTXB_CTL_TBUF_INIT_MASK 0x2000u
/*! Constant NONE - NONE */
#define CONST_LMAC4_RTXB_CTL_TBUF_INIT_NONE 0x0
/*! Constant INIT - INIT */
#define CONST_LMAC4_RTXB_CTL_TBUF_INIT_INIT 0x1

/*! @} */

/*! \defgroup MAC4_TXTS_0 Register MAC4_TXTS_0 - MAC 4 TX Timestamp Bit 15 to 0 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_TXTS_0 0x1450
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_TXTS_0 0x18441450u

/*! Register Reset Value */
#define MAC4_TXTS_0_RST 0x0000u

/*! Field TTSLL - Time Stamp Bit 15 to 0 */
#define MAC4_TXTS_0_TTSLL_POS 0
/*! Field TTSLL - Time Stamp Bit 15 to 0 */
#define MAC4_TXTS_0_TTSLL_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_TXTS_1 Register MAC4_TXTS_1 - MAC 4 TX Timestamp Bit 31 to 16 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_TXTS_1 0x1454
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_TXTS_1 0x18441454u

/*! Register Reset Value */
#define MAC4_TXTS_1_RST 0x0000u

/*! Field TTSLH - Time Stamp Bit 31 to 16 */
#define MAC4_TXTS_1_TTSLH_POS 0
/*! Field TTSLH - Time Stamp Bit 31 to 16 */
#define MAC4_TXTS_1_TTSLH_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_TXTS_2 Register MAC4_TXTS_2 - MAC 4 TX Timestamp Bit 47 to 32 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_TXTS_2 0x1458
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_TXTS_2 0x18441458u

/*! Register Reset Value */
#define MAC4_TXTS_2_RST 0x0000u

/*! Field TTSHL - Time Stamp Bit 47 to 32 */
#define MAC4_TXTS_2_TTSHL_POS 0
/*! Field TTSHL - Time Stamp Bit 47 to 32 */
#define MAC4_TXTS_2_TTSHL_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_TXTS_3 Register MAC4_TXTS_3 - MAC 4 TX Timestamp Bit 63 to 32 */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_TXTS_3 0x145C
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_TXTS_3 0x1844145Cu

/*! Register Reset Value */
#define MAC4_TXTS_3_RST 0x0000u

/*! Field TTSHH - Time Stamp Bit 63 to 48 */
#define MAC4_TXTS_3_TTSHH_POS 0
/*! Field TTSHH - Time Stamp Bit 63 to 48 */
#define MAC4_TXTS_3_TTSHH_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC4_TXTS_CIC Register MAC4_TXTS_CIC - MAC 4 TX Timestamp CIC */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_TXTS_CIC 0x1460
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_TXTS_CIC 0x18441460u

/*! Register Reset Value */
#define MAC4_TXTS_CIC_RST 0x0000u

/*! Field CIC - Time stamp CIC */
#define MAC4_TXTS_CIC_CIC_POS 0
/*! Field CIC - Time stamp CIC */
#define MAC4_TXTS_CIC_CIC_MASK 0x3u
/*! Constant DIS - DIS */
#define CONST_MAC4_TXTS_CIC_CIC_DIS 0x0
/*! Constant IP - IP */
#define CONST_MAC4_TXTS_CIC_CIC_IP 0x1
/*! Constant IPPL - IPPL */
#define CONST_MAC4_TXTS_CIC_CIC_IPPL 0x2
/*! Constant ALL - ALL */
#define CONST_MAC4_TXTS_CIC_CIC_ALL 0x3

/*! Field OST_AVAIL - Time stamp One Step Time stamp Available */
#define MAC4_TXTS_CIC_OST_AVAIL_POS 2
/*! Field OST_AVAIL - Time stamp One Step Time stamp Available */
#define MAC4_TXTS_CIC_OST_AVAIL_MASK 0x4u

/*! Field OSTC - Time stamp One Step Correction Enable */
#define MAC4_TXTS_CIC_OSTC_POS 3
/*! Field OSTC - Time stamp One Step Correction Enable */
#define MAC4_TXTS_CIC_OSTC_MASK 0x8u

/*! Field TTSE - Time Stamp Capture Enable */
#define MAC4_TXTS_CIC_TTSE_POS 4
/*! Field TTSE - Time Stamp Capture Enable */
#define MAC4_TXTS_CIC_TTSE_MASK 0x10u

/*! @} */

/*! \defgroup MAC4_TXTS_ACC Register MAC4_TXTS_ACC - MAC 4 TX Timestamp Access */
/*! @{ */

/*! Register Offset (relative) */
#define MAC4_TXTS_ACC 0x1464
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_MAC4_TXTS_ACC 0x18441464u

/*! Register Reset Value */
#define MAC4_TXTS_ACC_RST 0x0000u

/*! Field ADDR - Time stamp FIFO address */
#define MAC4_TXTS_ACC_ADDR_POS 0
/*! Field ADDR - Time stamp FIFO address */
#define MAC4_TXTS_ACC_ADDR_MASK 0x3Fu

/*! Field OPMOD - Access Operation Mode */
#define MAC4_TXTS_ACC_OPMOD_POS 14
/*! Field OPMOD - Access Operation Mode */
#define MAC4_TXTS_ACC_OPMOD_MASK 0x4000u
/*! Constant RD - RD */
#define CONST_MAC4_TXTS_ACC_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_MAC4_TXTS_ACC_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define MAC4_TXTS_ACC_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define MAC4_TXTS_ACC_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_MAC4_TXTS_ACC_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_MAC4_TXTS_ACC_BAS_BUSY 0x1

/*! @} */

/*! \defgroup PHY4_MODE Register PHY4_MODE - PHY 4 Mode Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define PHY4_MODE 0x1470
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_PHY4_MODE 0x18441470u

/*! Register Reset Value */
#define PHY4_MODE_RST 0x9800u

/*! Field FCONRX - Flow Control Mode RX */
#define PHY4_MODE_FCONRX_POS 5
/*! Field FCONRX - Flow Control Mode RX */
#define PHY4_MODE_FCONRX_MASK 0x60u
/*! Constant AUTO - AUTO */
#define CONST_PHY4_MODE_FCONRX_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY4_MODE_FCONRX_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY4_MODE_FCONRX_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY4_MODE_FCONRX_DIS 0x3

/*! Field FCONTX - Flow Control Mode TX */
#define PHY4_MODE_FCONTX_POS 7
/*! Field FCONTX - Flow Control Mode TX */
#define PHY4_MODE_FCONTX_MASK 0x180u
/*! Constant AUTO - AUTO */
#define CONST_PHY4_MODE_FCONTX_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY4_MODE_FCONTX_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY4_MODE_FCONTX_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY4_MODE_FCONTX_DIS 0x3

/*! Field FDUP - Full Duplex Control */
#define PHY4_MODE_FDUP_POS 9
/*! Field FDUP - Full Duplex Control */
#define PHY4_MODE_FDUP_MASK 0x600u
/*! Constant AUTO - AUTO */
#define CONST_PHY4_MODE_FDUP_AUTO 0x0
/*! Constant EN - EN */
#define CONST_PHY4_MODE_FDUP_EN 0x1
/*! Constant RES - RES */
#define CONST_PHY4_MODE_FDUP_RES 0x2
/*! Constant DIS - DIS */
#define CONST_PHY4_MODE_FDUP_DIS 0x3

/*! Field SPEED_LSB - Speed Control Bit 2 to 0 */
#define PHY4_MODE_SPEED_LSB_POS 11
/*! Field SPEED_LSB - Speed Control Bit 2 to 0 */
#define PHY4_MODE_SPEED_LSB_MASK 0x1800u

/*! Field LNKST - Link Status Control */
#define PHY4_MODE_LNKST_POS 13
/*! Field LNKST - Link Status Control */
#define PHY4_MODE_LNKST_MASK 0x6000u
/*! Constant AUTO - AUTO */
#define CONST_PHY4_MODE_LNKST_AUTO 0x0
/*! Constant UP - UP */
#define CONST_PHY4_MODE_LNKST_UP 0x1
/*! Constant DOWN - DOWN */
#define CONST_PHY4_MODE_LNKST_DOWN 0x2
/*! Constant RES - RES */
#define CONST_PHY4_MODE_LNKST_RES 0x3

/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY4_MODE_SPEED_MSB_POS 15
/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY4_MODE_SPEED_MSB_MASK 0x8000u

/*! @} */

/*! \defgroup PHY_STAT_4 Register PHY_STAT_4 - PHY 4 Status */
/*! @{ */

/*! Register Offset (relative) */
#define PHY_STAT_4 0x1474
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_PHY_STAT_4 0x18441474u

/*! Register Reset Value */
#define PHY_STAT_4_RST 0x0000u

/*! Field TXPAUEN - Transmit Pause Enable Status */
#define PHY_STAT_4_TXPAUEN_POS 0
/*! Field TXPAUEN - Transmit Pause Enable Status */
#define PHY_STAT_4_TXPAUEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_4_TXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_4_TXPAUEN_EN 0x1

/*! Field RXPAUEN - Receive Pause Enable Status */
#define PHY_STAT_4_RXPAUEN_POS 1
/*! Field RXPAUEN - Receive Pause Enable Status */
#define PHY_STAT_4_RXPAUEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_4_RXPAUEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_4_RXPAUEN_EN 0x1

/*! Field FDUP - Full Duplex Status */
#define PHY_STAT_4_FDUP_POS 2
/*! Field FDUP - Full Duplex Status */
#define PHY_STAT_4_FDUP_MASK 0x4u
/*! Constant HALF - HALF */
#define CONST_PHY_STAT_4_FDUP_HALF 0x0
/*! Constant FULL - FULL */
#define CONST_PHY_STAT_4_FDUP_FULL 0x1

/*! Field SPEED_LSB - Speed Control Bit 1 to 0 */
#define PHY_STAT_4_SPEED_LSB_POS 3
/*! Field SPEED_LSB - Speed Control Bit 1 to 0 */
#define PHY_STAT_4_SPEED_LSB_MASK 0x18u

/*! Field LSTAT - Link Status */
#define PHY_STAT_4_LSTAT_POS 5
/*! Field LSTAT - Link Status */
#define PHY_STAT_4_LSTAT_MASK 0x20u
/*! Constant DOWN - DOWN */
#define CONST_PHY_STAT_4_LSTAT_DOWN 0x0
/*! Constant UP - UP */
#define CONST_PHY_STAT_4_LSTAT_UP 0x1

/*! Field EEE_CAPABLE - PHY and link partner support EEE for current speed */
#define PHY_STAT_4_EEE_CAPABLE_POS 7
/*! Field EEE_CAPABLE - PHY and link partner support EEE for current speed */
#define PHY_STAT_4_EEE_CAPABLE_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_4_EEE_CAPABLE_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_4_EEE_CAPABLE_EN 0x1

/*! Field CLK_STOP_CAPABLE - PHY supports TX Clock Stop */
#define PHY_STAT_4_CLK_STOP_CAPABLE_POS 8
/*! Field CLK_STOP_CAPABLE - PHY supports TX Clock Stop */
#define PHY_STAT_4_CLK_STOP_CAPABLE_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PHY_STAT_4_CLK_STOP_CAPABLE_DIS 0x0
/*! Constant EN - EN */
#define CONST_PHY_STAT_4_CLK_STOP_CAPABLE_EN 0x1

/*! Field TXACT - TX Traffic Active */
#define PHY_STAT_4_TXACT_POS 9
/*! Field TXACT - TX Traffic Active */
#define PHY_STAT_4_TXACT_MASK 0x200u
/*! Constant NOT_ACTIVE - NOT Active */
#define CONST_PHY_STAT_4_TXACT_NOT_ACTIVE 0x0
/*! Constant ACT - ACT */
#define CONST_PHY_STAT_4_TXACT_ACT 0x1

/*! Field RXACT - RX Traffic Active */
#define PHY_STAT_4_RXACT_POS 10
/*! Field RXACT - RX Traffic Active */
#define PHY_STAT_4_RXACT_MASK 0x400u
/*! Constant NOT_ACTIVE - NOT Active */
#define CONST_PHY_STAT_4_RXACT_NOT_ACTIVE 0x0
/*! Constant ACT - ACT */
#define CONST_PHY_STAT_4_RXACT_ACT 0x1

/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY_STAT_4_SPEED_MSB_POS 11
/*! Field SPEED_MSB - Speed Control Bit 2 */
#define PHY_STAT_4_SPEED_MSB_MASK 0x800u

/*! @} */

/*! \defgroup ANEG_EEE_4 Register ANEG_EEE_4 - PHY 4 EEE auto negotiation overrides */
/*! @{ */

/*! Register Offset (relative) */
#define ANEG_EEE_4 0x1478
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_ANEG_EEE_4 0x18441478u

/*! Register Reset Value */
#define ANEG_EEE_4_RST 0x0000u

/*! Field EEE_CAPABLE - EEE Capable */
#define ANEG_EEE_4_EEE_CAPABLE_POS 0
/*! Field EEE_CAPABLE - EEE Capable */
#define ANEG_EEE_4_EEE_CAPABLE_MASK 0x3u
/*! Constant AUTO - AUTO */
#define CONST_ANEG_EEE_4_EEE_CAPABLE_AUTO 0x0
/*! Constant EN - EN */
#define CONST_ANEG_EEE_4_EEE_CAPABLE_EN 0x1
/*! Constant RES - RES */
#define CONST_ANEG_EEE_4_EEE_CAPABLE_RES 0x2
/*! Constant DIS - DIS */
#define CONST_ANEG_EEE_4_EEE_CAPABLE_DIS 0x3

/*! Field CLK_STOP_CAPABLE - Clock Stop Capable */
#define ANEG_EEE_4_CLK_STOP_CAPABLE_POS 2
/*! Field CLK_STOP_CAPABLE - Clock Stop Capable */
#define ANEG_EEE_4_CLK_STOP_CAPABLE_MASK 0xCu
/*! Constant AUTO - AUTO */
#define CONST_ANEG_EEE_4_CLK_STOP_CAPABLE_AUTO 0x0
/*! Constant EN - EN */
#define CONST_ANEG_EEE_4_CLK_STOP_CAPABLE_EN 0x1
/*! Constant RES - RES */
#define CONST_ANEG_EEE_4_CLK_STOP_CAPABLE_RES 0x2
/*! Constant DIS - DIS */
#define CONST_ANEG_EEE_4_CLK_STOP_CAPABLE_DIS 0x3

/*! @} */

/*! \defgroup XGMAC4_CTRL Register XGMAC4_CTRL - XGMAC 4 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC4_CTRL 0x1480
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC4_CTRL 0x18441480u

/*! Register Reset Value */
#define XGMAC4_CTRL_RST 0x0000u

/*! Field CPC - TX direction CRC CTRL */
#define XGMAC4_CTRL_CPC_POS 0
/*! Field CPC - TX direction CRC CTRL */
#define XGMAC4_CTRL_CPC_MASK 0x3u
/*! Constant PADINS - PADINS */
#define CONST_XGMAC4_CTRL_CPC_PADINS 0x0
/*! Constant CRCINS - CRCINS */
#define CONST_XGMAC4_CTRL_CPC_CRCINS 0x1
/*! Constant NIL - NIL */
#define CONST_XGMAC4_CTRL_CPC_NIL 0x2
/*! Constant RES - RES */
#define CONST_XGMAC4_CTRL_CPC_RES 0x3

/*! Field DIS_RX - MAC Receiver Disable Control */
#define XGMAC4_CTRL_DIS_RX_POS 2
/*! Field DIS_RX - MAC Receiver Disable Control */
#define XGMAC4_CTRL_DIS_RX_MASK 0x4u
/*! Constant NIL - NIL */
#define CONST_XGMAC4_CTRL_DIS_RX_NIL 0x0
/*! Constant DIS - DIS */
#define CONST_XGMAC4_CTRL_DIS_RX_DIS 0x1

/*! Field DIS_TX - MAC Transmitter Disable Control */
#define XGMAC4_CTRL_DIS_TX_POS 3
/*! Field DIS_TX - MAC Transmitter Disable Control */
#define XGMAC4_CTRL_DIS_TX_MASK 0x8u
/*! Constant NIL - NIL */
#define CONST_XGMAC4_CTRL_DIS_TX_NIL 0x0
/*! Constant DIS - DIS */
#define CONST_XGMAC4_CTRL_DIS_TX_DIS 0x1

/*! @} */

/*! \defgroup XGMAC4_REGACC_DATA0 Register XGMAC4_REGACC_DATA0 - XGMAC 4 Register Access Low Data */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC4_REGACC_DATA0 0x1490
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC4_REGACC_DATA0 0x18441490u

/*! Register Reset Value */
#define XGMAC4_REGACC_DATA0_RST 0x0000u

/*! Field LOW - Register Data Bit 15 to 0 */
#define XGMAC4_REGACC_DATA0_LOW_POS 0
/*! Field LOW - Register Data Bit 15 to 0 */
#define XGMAC4_REGACC_DATA0_LOW_MASK 0xFFFFu

/*! @} */

/*! \defgroup XGMAC4_REGACC_DATA1 Register XGMAC4_REGACC_DATA1 - XGMAC 4 Register Access High Data */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC4_REGACC_DATA1 0x1494
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC4_REGACC_DATA1 0x18441494u

/*! Register Reset Value */
#define XGMAC4_REGACC_DATA1_RST 0x0000u

/*! Field HIGH - Register Data Bit 31 to 16 */
#define XGMAC4_REGACC_DATA1_HIGH_POS 0
/*! Field HIGH - Register Data Bit 31 to 16 */
#define XGMAC4_REGACC_DATA1_HIGH_MASK 0xFFFFu

/*! @} */

/*! \defgroup XGMAC4_REGACC_CTRL Register XGMAC4_REGACC_CTRL - XGMAC 4 Register Access Control */
/*! @{ */

/*! Register Offset (relative) */
#define XGMAC4_REGACC_CTRL 0x1498
/*! Register Offset (absolute) for 1st Instance GSWIP_SS */
#define GSWIP_SS_XGMAC4_REGACC_CTRL 0x18441498u

/*! Register Reset Value */
#define XGMAC4_REGACC_CTRL_RST 0x0000u

/*! Field ADDR - Register address */
#define XGMAC4_REGACC_CTRL_ADDR_POS 0
/*! Field ADDR - Register address */
#define XGMAC4_REGACC_CTRL_ADDR_MASK 0x3FFFu

/*! Field OPMOD - Access Operation Mode */
#define XGMAC4_REGACC_CTRL_OPMOD_POS 14
/*! Field OPMOD - Access Operation Mode */
#define XGMAC4_REGACC_CTRL_OPMOD_MASK 0x4000u
/*! Constant RD - RD */
#define CONST_XGMAC4_REGACC_CTRL_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_XGMAC4_REGACC_CTRL_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define XGMAC4_REGACC_CTRL_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define XGMAC4_REGACC_CTRL_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_XGMAC4_REGACC_CTRL_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_XGMAC4_REGACC_CTRL_BAS_BUSY 0x1

/*! @} */

/*! @} */

#endif
