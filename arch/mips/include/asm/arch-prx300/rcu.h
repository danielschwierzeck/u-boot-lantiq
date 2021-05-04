/* Copyright (c) 2017, Intel Corporation.
 * 
 * Reset control unit  header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _RCU_H
#define _RCU_H

/*! \defgroup RCU Register File RCU - Registers Description */
/*! @{ */

/*! Base Address of RCU */
#define RCU_MODULE_BASE 0x16100000u

/*! \defgroup RST_REQ Register RST_REQ - Reset Request Register */
/*! @{ */

/*! Register Offset (relative) */
#define RST_REQ 0x10
/*! Register Offset (absolute) for 1st Instance RCU */
#define RCU_RST_REQ 0x16100010u

/*! Register Reset Value */
#define RST_REQ_RST 0x30003420u

/*! Field HRST - Reset Request for Reset Domain HRST */
#define RST_REQ_HRST_POS 0
/*! Field HRST - Reset Request for Reset Domain HRST */
#define RST_REQ_HRST_MASK 0x1u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_HRST_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_HRST_ENABLED 0x1

/*! Field CPU_SC - Reset Request for Reset Domain CPU-4KEc */
#define RST_REQ_CPU_SC_POS 1
/*! Field CPU_SC - Reset Request for Reset Domain CPU-4KEc */
#define RST_REQ_CPU_SC_MASK 0x2u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_CPU_SC_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_CPU_SC_ENABLED 0x1

/*! Field CPU_CLUSTER_RST - Reset Request for Reset Domain CPU-Cluster */
#define RST_REQ_CPU_CLUSTER_RST_POS 2
/*! Field CPU_CLUSTER_RST - Reset Request for Reset Domain CPU-Cluster */
#define RST_REQ_CPU_CLUSTER_RST_MASK 0x4u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_CPU_CLUSTER_RST_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_CPU_CLUSTER_RST_ENABLED 0x1

/*! Field CPU_CLUSTER_RLSE - Reset Release for Reset Domain CPU-Cluster */
#define RST_REQ_CPU_CLUSTER_RLSE_POS 3
/*! Field CPU_CLUSTER_RLSE - Reset Release for Reset Domain CPU-Cluster */
#define RST_REQ_CPU_CLUSTER_RLSE_MASK 0x8u
/*! Constant DISABLED - Not Released */
#define CONST_RST_REQ_CPU_CLUSTER_RLSE_DISABLED 0x0
/*! Constant ENABLED - Released */
#define CONST_RST_REQ_CPU_CLUSTER_RLSE_ENABLED 0x1

/*! Field HRST_CFG - HRST Active Level Configuration */
#define RST_REQ_HRST_CFG_POS 5
/*! Field HRST_CFG - HRST Active Level Configuration */
#define RST_REQ_HRST_CFG_MASK 0x20u
/*! Constant DISABLED - Active High, Inactive Low */
#define CONST_RST_REQ_HRST_CFG_DISABLED 0x0
/*! Constant ENABLED - Active Low, Inactive High */
#define CONST_RST_REQ_HRST_CFG_ENABLED 0x1

/*! Field CBM - Reset Request for Reset Domain CQEM and PPv4 QoS */
#define RST_REQ_CBM_POS 7
/*! Field CBM - Reset Request for Reset Domain CQEM and PPv4 QoS */
#define RST_REQ_CBM_MASK 0x80u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_CBM_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_CBM_ENABLED 0x1

/*! Field PHY2 - Reset Request for Reset Domain WAN Serdes */
#define RST_REQ_PHY2_POS 10
/*! Field PHY2 - Reset Request for Reset Domain WAN Serdes */
#define RST_REQ_PHY2_MASK 0x400u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_PHY2_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_PHY2_ENABLED 0x1

/*! Field PHY0 - Reset Request for Reset Domain LAN SERDES 0 */
#define RST_REQ_PHY0_POS 12
/*! Field PHY0 - Reset Request for Reset Domain LAN SERDES 0 */
#define RST_REQ_PHY0_MASK 0x1000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_PHY0_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_PHY0_ENABLED 0x1

/*! Field PHY1 - Reset Request for Reset Domain LAN SERDES 1 */
#define RST_REQ_PHY1_POS 13
/*! Field PHY1 - Reset Request for Reset Domain LAN SERDES 1 */
#define RST_REQ_PHY1_MASK 0x2000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_PHY1_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_PHY1_ENABLED 0x1

/*! Field XPCS0 - Reset Request for Reset Domain LAN XPCS0 */
#define RST_REQ_XPCS0_POS 14
/*! Field XPCS0 - Reset Request for Reset Domain LAN XPCS0 */
#define RST_REQ_XPCS0_MASK 0x4000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_XPCS0_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_XPCS0_ENABLED 0x1

/*! Field XPCS1 - Reset Request for Reset Domain LAN XPCS1 */
#define RST_REQ_XPCS1_POS 15
/*! Field XPCS1 - Reset Request for Reset Domain LAN XPCS1 */
#define RST_REQ_XPCS1_MASK 0x8000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_XPCS1_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_XPCS1_ENABLED 0x1

/*! Field XPCS2 - Reset Request for Reset Domain WAN XPCS2 */
#define RST_REQ_XPCS2_POS 16
/*! Field XPCS2 - Reset Request for Reset Domain WAN XPCS2 */
#define RST_REQ_XPCS2_MASK 0x10000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_XPCS2_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_XPCS2_ENABLED 0x1

/*! Field WANSS - Reset Request for Reset Domain WAN Subsystem */
#define RST_REQ_WANSS_POS 17
/*! Field WANSS - Reset Request for Reset Domain WAN Subsystem */
#define RST_REQ_WANSS_MASK 0x20000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_WANSS_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_WANSS_ENABLED 0x1

/*! Field CPHYSS - Reset Request for Reset Domain Combo PHY Subsystem */
#define RST_REQ_CPHYSS_POS 18
/*! Field CPHYSS - Reset Request for Reset Domain Combo PHY Subsystem */
#define RST_REQ_CPHYSS_MASK 0x40000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_CPHYSS_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_CPHYSS_ENABLED 0x1

/*! Field GSWIP - Reset Request for Reset Domain Ethernet Switch */
#define RST_REQ_GSWIP_POS 21
/*! Field GSWIP - Reset Request for Reset Domain Ethernet Switch */
#define RST_REQ_GSWIP_MASK 0x200000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_GSWIP_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_GSWIP_ENABLED 0x1

/*! Field PCIE_CTRL0 - Reset Request for Reset Domain PCIe Controller 0 */
#define RST_REQ_PCIE_CTRL0_POS 22
/*! Field PCIE_CTRL0 - Reset Request for Reset Domain PCIe Controller 0 */
#define RST_REQ_PCIE_CTRL0_MASK 0x400000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_PCIE_CTRL0_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_PCIE_CTRL0_ENABLED 0x1

/*! Field PCIE_CTRL1 - Reset Request for Reset Domain PCIe Controller 1 */
#define RST_REQ_PCIE_CTRL1_POS 23
/*! Field PCIE_CTRL1 - Reset Request for Reset Domain PCIe Controller 1 */
#define RST_REQ_PCIE_CTRL1_MASK 0x800000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_PCIE_CTRL1_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_PCIE_CTRL1_ENABLED 0x1

/*! Field PONIP - Reset Request for Reset Domain PON-IP */
#define RST_REQ_PONIP_POS 28
/*! Field PONIP - Reset Request for Reset Domain PON-IP */
#define RST_REQ_PONIP_MASK 0x10000000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_PONIP_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_PONIP_ENABLED 0x1

/*! Field GPHY - Reset Request for Reset Domain GPHY */
#define RST_REQ_GPHY_POS 29
/*! Field GPHY - Reset Request for Reset Domain GPHY */
#define RST_REQ_GPHY_MASK 0x20000000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_GPHY_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_GPHY_ENABLED 0x1

/*! Field GLB_SW - Global Software Reset */
#define RST_REQ_GLB_SW_POS 30
/*! Field GLB_SW - Global Software Reset */
#define RST_REQ_GLB_SW_MASK 0x40000000u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ_GLB_SW_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ_GLB_SW_ENABLED 0x1

/*! @} */

/*! \defgroup RST_STAT Register RST_STAT - Reset Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define RST_STAT 0x14
/*! Register Offset (absolute) for 1st Instance RCU */
#define RCU_RST_STAT 0x16100014u

/*! Register Reset Value */
#define RST_STAT_RST 0x38E7F487u

/*! Field HRST - Status of Reset Domain HRST output */
#define RST_STAT_HRST_POS 0
/*! Field HRST - Status of Reset Domain HRST output */
#define RST_STAT_HRST_MASK 0x1u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_HRST_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_HRST_RESET 0x1

/*! Field CPU_SC - Status of Reset Domain CPU -4KEc */
#define RST_STAT_CPU_SC_POS 1
/*! Field CPU_SC - Status of Reset Domain CPU -4KEc */
#define RST_STAT_CPU_SC_MASK 0x2u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_CPU_SC_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_CPU_SC_RESET 0x1

/*! Field CPU_CLUSTER - Status of Reset Domain CPU -InterAPtiv Cluster */
#define RST_STAT_CPU_CLUSTER_POS 2
/*! Field CPU_CLUSTER - Status of Reset Domain CPU -InterAPtiv Cluster */
#define RST_STAT_CPU_CLUSTER_MASK 0x4u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_CPU_CLUSTER_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_CPU_CLUSTER_RESET 0x1

/*! Field CPU_CLUSTER_RC - Status of Reset Domain CPU -InterAPtiv Cluster */
#define RST_STAT_CPU_CLUSTER_RC_POS 3
/*! Field CPU_CLUSTER_RC - Status of Reset Domain CPU -InterAPtiv Cluster */
#define RST_STAT_CPU_CLUSTER_RC_MASK 0x8u
/*! Constant NOT_RDY - Not ready */
#define CONST_RST_STAT_CPU_CLUSTER_RC_NOT_RDY 0x0
/*! Constant RDY - Ready */
#define CONST_RST_STAT_CPU_CLUSTER_RC_RDY 0x1

/*! Field CBM - Status of Reset Domain CQEM and QoS */
#define RST_STAT_CBM_POS 7
/*! Field CBM - Status of Reset Domain CQEM and QoS */
#define RST_STAT_CBM_MASK 0x80u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_CBM_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_CBM_RESET 0x1

/*! Field PHY2 - Status of Reset Domain WAN Serdes */
#define RST_STAT_PHY2_POS 10
/*! Field PHY2 - Status of Reset Domain WAN Serdes */
#define RST_STAT_PHY2_MASK 0x400u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_PHY2_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_PHY2_RESET 0x1

/*! Field PHY0 - Status of Reset Domain LAN Serdes 0 */
#define RST_STAT_PHY0_POS 12
/*! Field PHY0 - Status of Reset Domain LAN Serdes 0 */
#define RST_STAT_PHY0_MASK 0x1000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_PHY0_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_PHY0_RESET 0x1

/*! Field PHY1 - Status of Reset Domain LAN Serdes 1 */
#define RST_STAT_PHY1_POS 13
/*! Field PHY1 - Status of Reset Domain LAN Serdes 1 */
#define RST_STAT_PHY1_MASK 0x2000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_PHY1_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_PHY1_RESET 0x1

/*! Field XPCS0 - Status of Reset Domain LAN XPCS 0 */
#define RST_STAT_XPCS0_POS 14
/*! Field XPCS0 - Status of Reset Domain LAN XPCS 0 */
#define RST_STAT_XPCS0_MASK 0x4000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_XPCS0_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_XPCS0_RESET 0x1

/*! Field XPCS1 - Status of Reset Domain LAN XPCS 1 */
#define RST_STAT_XPCS1_POS 15
/*! Field XPCS1 - Status of Reset Domain LAN XPCS 1 */
#define RST_STAT_XPCS1_MASK 0x8000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_XPCS1_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_XPCS1_RESET 0x1

/*! Field XPCS2 - Status of Reset Domain WAN XPCS */
#define RST_STAT_XPCS2_POS 16
/*! Field XPCS2 - Status of Reset Domain WAN XPCS */
#define RST_STAT_XPCS2_MASK 0x10000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_XPCS2_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_XPCS2_RESET 0x1

/*! Field WANSS - Status of Reset Domain WAN SS */
#define RST_STAT_WANSS_POS 17
/*! Field WANSS - Status of Reset Domain WAN SS */
#define RST_STAT_WANSS_MASK 0x20000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_WANSS_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_WANSS_RESET 0x1

/*! Field CPHYSS - Status of Reset Domain CPHY SS */
#define RST_STAT_CPHYSS_POS 18
/*! Field CPHYSS - Status of Reset Domain CPHY SS */
#define RST_STAT_CPHYSS_MASK 0x40000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_CPHYSS_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_CPHYSS_RESET 0x1

/*! Field GSWIP - Status of Reset Domain LAN Ethernet Switch */
#define RST_STAT_GSWIP_POS 21
/*! Field GSWIP - Status of Reset Domain LAN Ethernet Switch */
#define RST_STAT_GSWIP_MASK 0x200000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_GSWIP_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_GSWIP_RESET 0x1

/*! Field PCIE_CTRL0 - Status of Reset Domain PCIe 0 Control */
#define RST_STAT_PCIE_CTRL0_POS 22
/*! Field PCIE_CTRL0 - Status of Reset Domain PCIe 0 Control */
#define RST_STAT_PCIE_CTRL0_MASK 0x400000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_PCIE_CTRL0_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_PCIE_CTRL0_RESET 0x1

/*! Field PCIE_CTRL1 - Status of Reset Domain PCIe 1 Control */
#define RST_STAT_PCIE_CTRL1_POS 23
/*! Field PCIE_CTRL1 - Status of Reset Domain PCIe 1 Control */
#define RST_STAT_PCIE_CTRL1_MASK 0x800000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_PCIE_CTRL1_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_PCIE_CTRL1_RESET 0x1

/*! Field EJTAG - EJTAG Reset Cause Flag */
#define RST_STAT_EJTAG_POS 26
/*! Field EJTAG - EJTAG Reset Cause Flag */
#define RST_STAT_EJTAG_MASK 0x4000000u
/*! Constant NORMAL - Normal */
#define CONST_RST_STAT_EJTAG_NORMAL 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_EJTAG_RESET 0x1

/*! Field POR - Power-On Reset Cause Flag */
#define RST_STAT_POR_POS 27
/*! Field POR - Power-On Reset Cause Flag */
#define RST_STAT_POR_MASK 0x8000000u
/*! Constant NORMAL - Normal */
#define CONST_RST_STAT_POR_NORMAL 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_POR_RESET 0x1

/*! Field PONIP - Status of Reset Domain PON-IP */
#define RST_STAT_PONIP_POS 28
/*! Field PONIP - Status of Reset Domain PON-IP */
#define RST_STAT_PONIP_MASK 0x10000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_PONIP_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_PONIP_RESET 0x1

/*! Field GPHY - Status of Reset Domain GPHY */
#define RST_STAT_GPHY_POS 29
/*! Field GPHY - Status of Reset Domain GPHY */
#define RST_STAT_GPHY_MASK 0x20000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT_GPHY_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_GPHY_RESET 0x1

/*! Field GLB_SW - Global Software Reset Cause Flag */
#define RST_STAT_GLB_SW_POS 30
/*! Field GLB_SW - Global Software Reset Cause Flag */
#define RST_STAT_GLB_SW_MASK 0x40000000u
/*! Constant NORMAL - Normal */
#define CONST_RST_STAT_GLB_SW_NORMAL 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_GLB_SW_RESET 0x1

/*! Field WDT - Watchdog Reset Cause Flag */
#define RST_STAT_WDT_POS 31
/*! Field WDT - Watchdog Reset Cause Flag */
#define RST_STAT_WDT_MASK 0x80000000u
/*! Constant NORMAL - Normal */
#define CONST_RST_STAT_WDT_NORMAL 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT_WDT_RESET 0x1

/*! @} */

/*! \defgroup RST_STAT2 Register RST_STAT2 - Reset Status Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define RST_STAT2 0x24
/*! Register Offset (absolute) for 1st Instance RCU */
#define RCU_RST_STAT2 0x16100024u

/*! Register Reset Value */
#define RST_STAT2_RST 0xF0380F8Fu

/*! Field VCODEC_STA - Reset Status for Vcodec Reset Domain */
#define RST_STAT2_VCODEC_STA_POS 0
/*! Field VCODEC_STA - Reset Status for Vcodec Reset Domain */
#define RST_STAT2_VCODEC_STA_MASK 0x1u
/*! Constant DISABLED - Disabled */
#define CONST_RST_STAT2_VCODEC_STA_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_STAT2_VCODEC_STA_ENABLED 0x1

/*! Field OTP - OCP to SRAM Bridge for OTP Access Reset */
#define RST_STAT2_OTP_POS 1
/*! Field OTP - OCP to SRAM Bridge for OTP Access Reset */
#define RST_STAT2_OTP_MASK 0x2u
/*! Constant DISABLED - Disabled */
#define CONST_RST_STAT2_OTP_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_STAT2_OTP_ENABLED 0x1

/*! Field XBAR7 - Status of Master XBAR2 Reset Domain */
#define RST_STAT2_XBAR7_POS 2
/*! Field XBAR7 - Status of Master XBAR2 Reset Domain */
#define RST_STAT2_XBAR7_MASK 0x4u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_XBAR7_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_XBAR7_RESET 0x1

/*! Field SSX4 - SSX4 Domain */
#define RST_STAT2_SSX4_POS 3
/*! Field SSX4 - SSX4 Domain */
#define RST_STAT2_SSX4_MASK 0x8u
/*! Constant DISABLED - Disabled */
#define CONST_RST_STAT2_SSX4_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_STAT2_SSX4_ENABLED 0x1

/*! Field SR_GPHY - Reset Status for Soft Reset Domain GPHY */
#define RST_STAT2_SR_GPHY_POS 7
/*! Field SR_GPHY - Reset Status for Soft Reset Domain GPHY */
#define RST_STAT2_SR_GPHY_MASK 0x80u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_SR_GPHY_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_SR_GPHY_RESET 0x1

/*! Field SPIDBG - Status of Master SPI Debug Reset Domain */
#define RST_STAT2_SPIDBG_POS 8
/*! Field SPIDBG - Status of Master SPI Debug Reset Domain */
#define RST_STAT2_SPIDBG_MASK 0x100u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_SPIDBG_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_SPIDBG_RESET 0x1

/*! Field ACADMA - Status of Master ACA DMA Reset Domain */
#define RST_STAT2_ACADMA_POS 9
/*! Field ACADMA - Status of Master ACA DMA Reset Domain */
#define RST_STAT2_ACADMA_MASK 0x200u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_ACADMA_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_ACADMA_RESET 0x1

/*! Field HOSTIF - Status of ACA Host Interface Reset Domain */
#define RST_STAT2_HOSTIF_POS 10
/*! Field HOSTIF - Status of ACA Host Interface Reset Domain */
#define RST_STAT2_HOSTIF_MASK 0x400u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_HOSTIF_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_HOSTIF_RESET 0x1

/*! Field ACASL - Status of ACA Shared Link Reset Domain */
#define RST_STAT2_ACASL_POS 11
/*! Field ACASL - Status of ACA Shared Link Reset Domain */
#define RST_STAT2_ACASL_MASK 0x800u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_ACASL_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_ACASL_RESET 0x1

/*! Field XBAR2 - Status of Master XBAR2 Reset Domain */
#define RST_STAT2_XBAR2_POS 19
/*! Field XBAR2 - Status of Master XBAR2 Reset Domain */
#define RST_STAT2_XBAR2_MASK 0x80000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_XBAR2_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_XBAR2_RESET 0x1

/*! Field XBAR1 - Status of Master XBAR1 Reset Domain */
#define RST_STAT2_XBAR1_POS 20
/*! Field XBAR1 - Status of Master XBAR1 Reset Domain */
#define RST_STAT2_XBAR1_MASK 0x100000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_XBAR1_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_XBAR1_RESET 0x1

/*! Field XBAR0 - Status of Master XBAR0 Reset Domain */
#define RST_STAT2_XBAR0_POS 21
/*! Field XBAR0 - Status of Master XBAR0 Reset Domain */
#define RST_STAT2_XBAR0_MASK 0x200000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_XBAR0_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_XBAR0_RESET 0x1

/*! Field GPHY_CDB - Reset status for GPHY CDB Reset Domain */
#define RST_STAT2_GPHY_CDB_POS 28
/*! Field GPHY_CDB - Reset status for GPHY CDB Reset Domain */
#define RST_STAT2_GPHY_CDB_MASK 0x10000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_GPHY_CDB_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_GPHY_CDB_RESET 0x1

/*! Field DDR_CTL - DDR Controller */
#define RST_STAT2_DDR_CTL_POS 29
/*! Field DDR_CTL - DDR Controller */
#define RST_STAT2_DDR_CTL_MASK 0x20000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_DDR_CTL_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_DDR_CTL_RESET 0x1

/*! Field DDR_PUB - DDR PUB Controller */
#define RST_STAT2_DDR_PUB_POS 30
/*! Field DDR_PUB - DDR PUB Controller */
#define RST_STAT2_DDR_PUB_MASK 0x40000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_DDR_PUB_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_DDR_PUB_RESET 0x1

/*! Field DDR_PHY - DDR PHY */
#define RST_STAT2_DDR_PHY_POS 31
/*! Field DDR_PHY - DDR PHY */
#define RST_STAT2_DDR_PHY_MASK 0x80000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_STAT2_DDR_PHY_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_STAT2_DDR_PHY_RESET 0x1

/*! @} */

/*! \defgroup RST_REQ2 Register RST_REQ2 - Reset Request Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define RST_REQ2 0x48
/*! Register Offset (absolute) for 1st Instance RCU */
#define RCU_RST_REQ2 0x16100048u

/*! Register Reset Value */
#define RST_REQ2_RST 0x00000000u

/*! Field VCODEC - Reset Request for Reset Domain voice macro */
#define RST_REQ2_VCODEC_POS 0
/*! Field VCODEC - Reset Request for Reset Domain voice macro */
#define RST_REQ2_VCODEC_MASK 0x1u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ2_VCODEC_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ2_VCODEC_ENABLED 0x1

/*! Field OTP - OCP to SRAM Bridge Reset */
#define RST_REQ2_OTP_POS 1
/*! Field OTP - OCP to SRAM Bridge Reset */
#define RST_REQ2_OTP_MASK 0x2u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ2_OTP_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ2_OTP_ENABLED 0x1

/*! Field XBAR7 - Reset Request for XBAR7 Reset Domain */
#define RST_REQ2_XBAR7_POS 2
/*! Field XBAR7 - Reset Request for XBAR7 Reset Domain */
#define RST_REQ2_XBAR7_MASK 0x4u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_XBAR7_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_XBAR7_RESET 0x1

/*! Field SSX4 - SSX4 Domain */
#define RST_REQ2_SSX4_POS 3
/*! Field SSX4 - SSX4 Domain */
#define RST_REQ2_SSX4_MASK 0x8u
/*! Constant DISABLED - Disabled */
#define CONST_RST_REQ2_SSX4_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_RST_REQ2_SSX4_ENABLED 0x1

/*! Field SR_GPHY - Reset Request for Soft Reset Domain GPHY */
#define RST_REQ2_SR_GPHY_POS 7
/*! Field SR_GPHY - Reset Request for Soft Reset Domain GPHY */
#define RST_REQ2_SR_GPHY_MASK 0x80u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_SR_GPHY_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_SR_GPHY_RESET 0x1

/*! Field SPIDBG - Reset Request for ACA SPI Debug */
#define RST_REQ2_SPIDBG_POS 8
/*! Field SPIDBG - Reset Request for ACA SPI Debug */
#define RST_REQ2_SPIDBG_MASK 0x100u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_SPIDBG_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_SPIDBG_RESET 0x1

/*! Field ACADMA - Reset Request for ACA DMA */
#define RST_REQ2_ACADMA_POS 9
/*! Field ACADMA - Reset Request for ACA DMA */
#define RST_REQ2_ACADMA_MASK 0x200u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_ACADMA_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_ACADMA_RESET 0x1

/*! Field HOSTIF - Reset Request for ACA host interface */
#define RST_REQ2_HOSTIF_POS 10
/*! Field HOSTIF - Reset Request for ACA host interface */
#define RST_REQ2_HOSTIF_MASK 0x400u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_HOSTIF_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_HOSTIF_RESET 0x1

/*! Field ACASL - Reset Request for ACA Shared Link */
#define RST_REQ2_ACASL_POS 11
/*! Field ACASL - Reset Request for ACA Shared Link */
#define RST_REQ2_ACASL_MASK 0x800u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_ACASL_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_ACASL_RESET 0x1

/*! Field XBAR2 - Reset Request for XBAR2 Reset Domain */
#define RST_REQ2_XBAR2_POS 19
/*! Field XBAR2 - Reset Request for XBAR2 Reset Domain */
#define RST_REQ2_XBAR2_MASK 0x80000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_XBAR2_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_XBAR2_RESET 0x1

/*! Field XBAR1 - Reset Request for XBAR1 Reset Domain */
#define RST_REQ2_XBAR1_POS 20
/*! Field XBAR1 - Reset Request for XBAR1 Reset Domain */
#define RST_REQ2_XBAR1_MASK 0x100000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_XBAR1_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_XBAR1_RESET 0x1

/*! Field XBAR0 - Reset Request for XBAR0 Reset Domain */
#define RST_REQ2_XBAR0_POS 21
/*! Field XBAR0 - Reset Request for XBAR0 Reset Domain */
#define RST_REQ2_XBAR0_MASK 0x200000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_XBAR0_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_XBAR0_RESET 0x1

/*! Field E123_ABORT_REQ - Abort E123 from on-going operation */
#define RST_REQ2_E123_ABORT_REQ_POS 23
/*! Field E123_ABORT_REQ - Abort E123 from on-going operation */
#define RST_REQ2_E123_ABORT_REQ_MASK 0x800000u
/*! Constant NABT */
#define CONST_RST_REQ2_E123_ABORT_REQ_NABT 0x0
/*! Constant ABT - Abort E123 from on-going operation */
#define CONST_RST_REQ2_E123_ABORT_REQ_ABT 0x1

/*! Field E123_ABORT_ACK - Acknowledge of abort request from E123 */
#define RST_REQ2_E123_ABORT_ACK_POS 24
/*! Field E123_ABORT_ACK - Acknowledge of abort request from E123 */
#define RST_REQ2_E123_ABORT_ACK_MASK 0x1000000u
/*! Constant NACK - not ready for abort */
#define CONST_RST_REQ2_E123_ABORT_ACK_NACK 0x0
/*! Constant ACK - ready for abort/software reset */
#define CONST_RST_REQ2_E123_ABORT_ACK_ACK 0x1

#define RST_REQ2_GPHY_PWR_DOWN_POS	27

/*! Field GPHY_CDB - Reset Request for GPHY CDB Reset Domain */
#define RST_REQ2_GPHY_CDB_POS 28
/*! Field GPHY_CDB - Reset Request for GPHY CDB Reset Domain */
#define RST_REQ2_GPHY_CDB_MASK 0x10000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_GPHY_CDB_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_GPHY_CDB_RESET 0x1

/*! Field DDR_CTL - DDR Controller */
#define RST_REQ2_DDR_CTL_POS 29
/*! Field DDR_CTL - DDR Controller */
#define RST_REQ2_DDR_CTL_MASK 0x20000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_DDR_CTL_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_DDR_CTL_RESET 0x1

/*! Field DDR_PUB - DDR PUB Controller */
#define RST_REQ2_DDR_PUB_POS 30
/*! Field DDR_PUB - DDR PUB Controller */
#define RST_REQ2_DDR_PUB_MASK 0x40000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_DDR_PUB_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_DDR_PUB_RESET 0x1

/*! Field DDR_PHY - DDR PHY */
#define RST_REQ2_DDR_PHY_POS 31
/*! Field DDR_PHY - DDR PHY */
#define RST_REQ2_DDR_PHY_MASK 0x80000000u
/*! Constant NO_RESET - No Reset */
#define CONST_RST_REQ2_DDR_PHY_NO_RESET 0x0
/*! Constant RESET - Reset */
#define CONST_RST_REQ2_DDR_PHY_RESET 0x1

/*! @} */

/*! \defgroup INTERAPTIV_WDT_RST_EN Register INTERAPTIV_WDT_RST_EN */
/*! @{ */

/*! Register Offset (relative) */
#define INTERAPTIV_WDT_RST_EN 0x50
/*! Register Offset (absolute) for 1st Instance RCU */
#define RCU_INTERAPTIV_WDT_RST_EN 0x16100050u

/*! Register Reset Value */
#define INTERAPTIV_WDT_RST_EN_RST 0x00000000u

/*! Field WDT0 - WDT0 (VPE0) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT0_POS 0
/*! Field WDT0 - WDT0 (VPE0) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT0_MASK 0x1u
/*! Constant DIS - No Enabled. */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT0_DIS 0x0
/*! Constant EN - Enable WDT reset */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT0_EN 0x1

/*! Field WDT1 - WDT1 (VPE1) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT1_POS 1
/*! Field WDT1 - WDT1 (VPE1) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT1_MASK 0x2u
/*! Constant DIS - No Enabled. */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT1_DIS 0x0
/*! Constant EN - Enable WDT reset */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT1_EN 0x1

/*! Field WDT2 - WDT2 (VPE2) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT2_POS 2
/*! Field WDT2 - WDT2 (VPE2) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT2_MASK 0x4u
/*! Constant DIS - No Enabled. */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT2_DIS 0x0
/*! Constant EN - Enable WDT reset */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT2_EN 0x1

/*! Field WDT3 - WDT3 (VPE3) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT3_POS 3
/*! Field WDT3 - WDT3 (VPE3) Reset to Generate General Hardware Reset */
#define INTERAPTIV_WDT_RST_EN_WDT3_MASK 0x8u
/*! Constant DIS - No Enabled. */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT3_DIS 0x0
/*! Constant EN - Enable WDT reset */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT3_EN 0x1

/*! Field WDT_SCPU - GPT2 timer 3 as WDT to SCPU can be enabled to issue chip level reset */
#define INTERAPTIV_WDT_RST_EN_WDT_SCPU_POS 8
/*! Field WDT_SCPU - GPT2 timer 3 as WDT to SCPU can be enabled to issue chip level reset */
#define INTERAPTIV_WDT_RST_EN_WDT_SCPU_MASK 0x100u
/*! Constant DIS - not enabled. */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT_SCPU_DIS 0x0
/*! Constant EN - Enabled as WDT reset. */
#define CONST_INTERAPTIV_WDT_RST_EN_WDT_SCPU_EN 0x1

/*! @} */

/*! @} */

#endif
