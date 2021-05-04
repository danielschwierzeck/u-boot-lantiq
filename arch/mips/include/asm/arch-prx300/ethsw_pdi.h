/* Copyright (c) 2017, Intel Corporation.
 *
 * ETHSW_PDI header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _ETHSW_PDI_H
#define _ETHSW_PDI_H

/*! \defgroup ETHSW_PDI Register File ETHSW_PDI - Switch Macro Register */
/*! @{ */

/*! Base Address of ETHSW_PDI */
#define ETHSW_PDI_MODULE_BASE 0x18450000u

/*! \defgroup ETHSW_SWRES Register ETHSW_SWRES - Ethernet Switch Reset Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_SWRES 0x0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_SWRES 0x18450000u

/*! Register Reset Value */
#define ETHSW_SWRES_RST 0x00000000u

/*! Field R0 - GSWIP Hardware Reset */
#define ETHSW_SWRES_R0_POS 0
/*! Field R0 - GSWIP Hardware Reset */
#define ETHSW_SWRES_R0_MASK 0x1u
/*! Constant RUN - RUN */
#define CONST_ETHSW_SWRES_R0_RUN 0x0
/*! Constant STOP - STOP */
#define CONST_ETHSW_SWRES_R0_STOP 0x1

/*! Field R1 - GSWIP Software Reset */
#define ETHSW_SWRES_R1_POS 1
/*! Field R1 - GSWIP Software Reset */
#define ETHSW_SWRES_R1_MASK 0x2u
/*! Constant RUN - RUN */
#define CONST_ETHSW_SWRES_R1_RUN 0x0
/*! Constant STOP - STOP */
#define CONST_ETHSW_SWRES_R1_STOP 0x1

/*! @} */

/*! \defgroup ETHSW_CLK Register ETHSW_CLK - Ethernet Switch Clock Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CLK 0x4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CLK 0x18450004u

/*! Register Reset Value */
#define ETHSW_CLK_RST 0x00000000u

/*! Field CORACT_OVR - Core Active Override */
#define ETHSW_CLK_CORACT_OVR_POS 1
/*! Field CORACT_OVR - Core Active Override */
#define ETHSW_CLK_CORACT_OVR_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_ETHSW_CLK_CORACT_OVR_DIS 0x0
/*! Constant EN - EN */
#define CONST_ETHSW_CLK_CORACT_OVR_EN 0x1

/*! @} */

/*! \defgroup ETHSW_SSB_MODE Register ETHSW_SSB_MODE - Ethernet Switch Shared Segment Buffer Mode Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_SSB_MODE 0xC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_SSB_MODE 0x1845000Cu

/*! Register Reset Value */
#define ETHSW_SSB_MODE_RST 0x00000000u

/*! Field MODE - Memory Access Mode */
#define ETHSW_SSB_MODE_MODE_POS 0
/*! Field MODE - Memory Access Mode */
#define ETHSW_SSB_MODE_MODE_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_ETHSW_SSB_MODE_MODE_RES0 0x0
/*! Constant WR - WR */
#define CONST_ETHSW_SSB_MODE_MODE_WR 0x1
/*! Constant RD - RD */
#define CONST_ETHSW_SSB_MODE_MODE_RD 0x2
/*! Constant RES3 - RES3 */
#define CONST_ETHSW_SSB_MODE_MODE_RES3 0x3

/*! Field ADDE - Memory Address */
#define ETHSW_SSB_MODE_ADDE_POS 2
/*! Field ADDE - Memory Address */
#define ETHSW_SSB_MODE_ADDE_MASK 0x3Cu

/*! Field TYPE - Memory Type */
#define ETHSW_SSB_MODE_TYPE_POS 6
/*! Field TYPE - Memory Type */
#define ETHSW_SSB_MODE_TYPE_MASK 0x40u
/*! Constant SSB - SSB */
#define CONST_ETHSW_SSB_MODE_TYPE_SSB 0x0
/*! Constant SLL3 - SLL3 */
#define CONST_ETHSW_SSB_MODE_TYPE_SLL3 0x1

/*! @} */

/*! \defgroup ETHSW_SSB_ADDR Register ETHSW_SSB_ADDR - Ethernet Switch Shared Segment Buffer Address Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_SSB_ADDR 0x10
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_SSB_ADDR 0x18450010u

/*! Register Reset Value */
#define ETHSW_SSB_ADDR_RST 0x00000000u

/*! Field ADDE - Memory Address */
#define ETHSW_SSB_ADDR_ADDE_POS 0
/*! Field ADDE - Memory Address */
#define ETHSW_SSB_ADDR_ADDE_MASK 0xFFFFu

/*! @} */

/*! \defgroup ETHSW_SSB_DATA Register ETHSW_SSB_DATA - Ethernet Switch Shared Segment Buffer Data Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_SSB_DATA 0x14
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_SSB_DATA 0x18450014u

/*! Register Reset Value */
#define ETHSW_SSB_DATA_RST 0x00000000u

/*! Field DATA - Data Value */
#define ETHSW_SSB_DATA_DATA_POS 0
/*! Field DATA - Data Value */
#define ETHSW_SSB_DATA_DATA_MASK 0xFFFFu

/*! @} */

/*! \defgroup ETHSW_CAP_0 Register ETHSW_CAP_0 - Ethernet Switch Capability Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_0 0x18
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_0 0x18450018u

/*! Register Reset Value */
#define ETHSW_CAP_0_RST 0x00001A0Au

/*! Field SPEED - Clock frequency */
#define ETHSW_CAP_0_SPEED_POS 0
/*! Field SPEED - Clock frequency */
#define ETHSW_CAP_0_SPEED_MASK 0xFFFFu

/*! @} */

/*! \defgroup ETHSW_CAP_1 Register ETHSW_CAP_1 - Ethernet Switch Capability Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_1 0x1C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_1 0x1845001Cu

/*! Register Reset Value */
#define ETHSW_CAP_1_RST 0x0000A093u

/*! Field PPORTS - Number of MAC Ports */
#define ETHSW_CAP_1_PPORTS_POS 0
/*! Field PPORTS - Number of MAC Ports */
#define ETHSW_CAP_1_PPORTS_MASK 0xFu

/*! Field VPORTS - Number of maximum logical ports over PMAC */
#define ETHSW_CAP_1_VPORTS_POS 4
/*! Field VPORTS - Number of maximum logical ports over PMAC */
#define ETHSW_CAP_1_VPORTS_MASK 0xF0u

/*! Field QUEUE - Number of queues */
#define ETHSW_CAP_1_QUEUE_POS 8
/*! Field QUEUE - Number of queues */
#define ETHSW_CAP_1_QUEUE_MASK 0x7F00u

/*! Field GMAC - MAC operation mode */
#define ETHSW_CAP_1_GMAC_POS 15
/*! Field GMAC - MAC operation mode */
#define ETHSW_CAP_1_GMAC_MASK 0x8000u
/*! Constant FE - FE */
#define CONST_ETHSW_CAP_1_GMAC_FE 0x0
/*! Constant GE - GE */
#define CONST_ETHSW_CAP_1_GMAC_GE 0x1

/*! @} */

/*! \defgroup ETHSW_CAP_2 Register ETHSW_CAP_2 - Ethernet Switch Capability Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_2 0x20
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_2 0x18450020u

/*! Register Reset Value */
#define ETHSW_CAP_2_RST 0x00000000u

/*! Field PACKETS - Number of packets */
#define ETHSW_CAP_2_PACKETS_POS 0
/*! Field PACKETS - Number of packets */
#define ETHSW_CAP_2_PACKETS_MASK 0xFFFu

/*! @} */

/*! \defgroup ETHSW_CAP_3 Register ETHSW_CAP_3 - Ethernet Switch Capability Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_3 0x24
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_3 0x18450024u

/*! Register Reset Value */
#define ETHSW_CAP_3_RST 0x00008020u

/*! Field SHAPERS - Number of traffic shapers */
#define ETHSW_CAP_3_SHAPERS_POS 0
/*! Field SHAPERS - Number of traffic shapers */
#define ETHSW_CAP_3_SHAPERS_MASK 0xFFu

/*! Field METERS - Number of traffic meters */
#define ETHSW_CAP_3_METERS_POS 8
/*! Field METERS - Number of traffic meters */
#define ETHSW_CAP_3_METERS_MASK 0xFF00u

/*! @} */

/*! \defgroup ETHSW_CAP_4 Register ETHSW_CAP_4 - Ethernet Switch Capability Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_4 0x28
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_4 0x18450028u

/*! Register Reset Value */
#define ETHSW_CAP_4_RST 0x00001000u

/*! Field PPPOE - PPPoE table size */
#define ETHSW_CAP_4_PPPOE_POS 8
/*! Field PPPOE - PPPoE table size */
#define ETHSW_CAP_4_PPPOE_MASK 0xFF00u

/*! @} */

/*! \defgroup ETHSW_CAP_5 Register ETHSW_CAP_5 - Ethernet Switch Capability Register 5 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_5 0x2C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_5 0x1845002Cu

/*! Register Reset Value */
#define ETHSW_CAP_5_RST 0x00001020u

/*! Field PROT - Protocol table size */
#define ETHSW_CAP_5_PROT_POS 0
/*! Field PROT - Protocol table size */
#define ETHSW_CAP_5_PROT_MASK 0xFFu

/*! Field IPPLEN - IP packet length table size */
#define ETHSW_CAP_5_IPPLEN_POS 8
/*! Field IPPLEN - IP packet length table size */
#define ETHSW_CAP_5_IPPLEN_MASK 0xFF00u

/*! @} */

/*! \defgroup ETHSW_CAP_6 Register ETHSW_CAP_6 - Ethernet Switch Capability Register 6 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_6 0x30
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_6 0x18450030u

/*! Register Reset Value */
#define ETHSW_CAP_6_RST 0x00004040u

/*! Field APPL - Application table size */
#define ETHSW_CAP_6_APPL_POS 0
/*! Field APPL - Application table size */
#define ETHSW_CAP_6_APPL_MASK 0xFFu

/*! Field MACDASA - MAC DA/SA table size */
#define ETHSW_CAP_6_MACDASA_POS 8
/*! Field MACDASA - MAC DA/SA table size */
#define ETHSW_CAP_6_MACDASA_MASK 0xFF00u

/*! @} */

/*! \defgroup ETHSW_CAP_7 Register ETHSW_CAP_7 - Ethernet Switch Capability Register 7 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_7 0x34
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_7 0x18450034u

/*! Register Reset Value */
#define ETHSW_CAP_7_RST 0x00004040u

/*! Field IPDASAL - IP DA/SA LSB table size */
#define ETHSW_CAP_7_IPDASAL_POS 0
/*! Field IPDASAL - IP DA/SA LSB table size */
#define ETHSW_CAP_7_IPDASAL_MASK 0xFFu

/*! Field IPDASAM - IP DA/SA MSB table size */
#define ETHSW_CAP_7_IPDASAM_POS 8
/*! Field IPDASAM - IP DA/SA MSB table size */
#define ETHSW_CAP_7_IPDASAM_MASK 0xFF00u

/*! @} */

/*! \defgroup ETHSW_CAP_8 Register ETHSW_CAP_8 - Ethernet Switch Capability Register 8 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_8 0x38
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_8 0x18450038u

/*! Register Reset Value */
#define ETHSW_CAP_8_RST 0x00000200u

/*! Field MCAST - Multicast table size */
#define ETHSW_CAP_8_MCAST_POS 0
/*! Field MCAST - Multicast table size */
#define ETHSW_CAP_8_MCAST_MASK 0x1FFFu

/*! @} */

/*! \defgroup ETHSW_CAP_9 Register ETHSW_CAP_9 - Ethernet Switch Capability Register 9 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_9 0x3C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_9 0x1845003Cu

/*! Register Reset Value */
#define ETHSW_CAP_9_RST 0x00000200u

/*! Field FLAGG - Flow Aggregation table size */
#define ETHSW_CAP_9_FLAGG_POS 0
/*! Field FLAGG - Flow Aggregation table size */
#define ETHSW_CAP_9_FLAGG_MASK 0x3FFu

/*! @} */

/*! \defgroup ETHSW_CAP_10 Register ETHSW_CAP_10 - Ethernet Switch Capability Register 10 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_10 0x40
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_10 0x18450040u

/*! Register Reset Value */
#define ETHSW_CAP_10_RST 0x00001000u

/*! Field MACBT - MAC bridging table size */
#define ETHSW_CAP_10_MACBT_POS 0
/*! Field MACBT - MAC bridging table size */
#define ETHSW_CAP_10_MACBT_MASK 0x1FFFu

/*! @} */

/*! \defgroup ETHSW_CAP_11 Register ETHSW_CAP_11 - Ethernet Switch Capability Register 11 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_11 0x44
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_11 0x18450044u

/*! Register Reset Value */
#define ETHSW_CAP_11_RST 0x00000000u

/*! Field BSIZEL - Packet buffer size (lower part, in byte) */
#define ETHSW_CAP_11_BSIZEL_POS 0
/*! Field BSIZEL - Packet buffer size (lower part, in byte) */
#define ETHSW_CAP_11_BSIZEL_MASK 0xFFFFu

/*! @} */

/*! \defgroup ETHSW_CAP_12 Register ETHSW_CAP_12 - Ethernet Switch Capability Register 12 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_12 0x48
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_12 0x18450048u

/*! Register Reset Value */
#define ETHSW_CAP_12_RST 0x00000004u

/*! Field BSIZEH - Packet buffer size (higher part, in byte) */
#define ETHSW_CAP_12_BSIZEH_POS 0
/*! Field BSIZEH - Packet buffer size (higher part, in byte) */
#define ETHSW_CAP_12_BSIZEH_MASK 0x7u

/*! @} */

/*! \defgroup ETHSW_VERSION Register ETHSW_VERSION - Ethernet Switch Version Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_VERSION 0x4C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_VERSION 0x1845004Cu

/*! Register Reset Value */
#define ETHSW_VERSION_RST 0x00000031u

/*! Field REV_ID - Hardware Revision Identification */
#define ETHSW_VERSION_REV_ID_POS 0
/*! Field REV_ID - Hardware Revision Identification */
#define ETHSW_VERSION_REV_ID_MASK 0xFFu

/*! Field MOD_ID - Module Identification */
#define ETHSW_VERSION_MOD_ID_POS 8
/*! Field MOD_ID - Module Identification */
#define ETHSW_VERSION_MOD_ID_MASK 0xFF00u

/*! @} */

/*! \defgroup ETHSW_IER Register ETHSW_IER - Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_IER 0x50
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_IER 0x18450050u

/*! Register Reset Value */
#define ETHSW_IER_RST 0x00000000u

/*! Field BMIE - Buffer Manager Interrupt Enable */
#define ETHSW_IER_BMIE_POS 0
/*! Field BMIE - Buffer Manager Interrupt Enable */
#define ETHSW_IER_BMIE_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_ETHSW_IER_BMIE_DIS 0x0
/*! Constant EN - EN */
#define CONST_ETHSW_IER_BMIE_EN 0x1

/*! Field PCEIE - Parser and Classification Engine Interrupt Enable */
#define ETHSW_IER_PCEIE_POS 1
/*! Field PCEIE - Parser and Classification Engine Interrupt Enable */
#define ETHSW_IER_PCEIE_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_ETHSW_IER_PCEIE_DIS 0x0
/*! Constant EN - EN */
#define CONST_ETHSW_IER_PCEIE_EN 0x1

/*! Field MACIE - PMAC interrupt Enable */
#define ETHSW_IER_MACIE_POS 2
/*! Field MACIE - PMAC interrupt Enable */
#define ETHSW_IER_MACIE_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_ETHSW_IER_MACIE_DIS 0x0
/*! Constant EN - EN */
#define CONST_ETHSW_IER_MACIE_EN 0x1

/*! Field SDMAIE - Store DMA Interrupt Enable */
#define ETHSW_IER_SDMAIE_POS 3
/*! Field SDMAIE - Store DMA Interrupt Enable */
#define ETHSW_IER_SDMAIE_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_ETHSW_IER_SDMAIE_DIS 0x0
/*! Constant EN - EN */
#define CONST_ETHSW_IER_SDMAIE_EN 0x1

/*! Field FDMAIE - Fetch DMA Interrupt Enable */
#define ETHSW_IER_FDMAIE_POS 4
/*! Field FDMAIE - Fetch DMA Interrupt Enable */
#define ETHSW_IER_FDMAIE_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_ETHSW_IER_FDMAIE_DIS 0x0
/*! Constant EN - EN */
#define CONST_ETHSW_IER_FDMAIE_EN 0x1

/*! @} */

/*! \defgroup ETHSW_ISR Register ETHSW_ISR - Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_ISR 0x54
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_ISR 0x18450054u

/*! Register Reset Value */
#define ETHSW_ISR_RST 0x00000000u

/*! Field BMINT - Buffer Manager Interrupt */
#define ETHSW_ISR_BMINT_POS 0
/*! Field BMINT - Buffer Manager Interrupt */
#define ETHSW_ISR_BMINT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_ETHSW_ISR_BMINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_ETHSW_ISR_BMINT_INT 0x1

/*! Field PCEINT - Parser and Classification Engine Interrupt */
#define ETHSW_ISR_PCEINT_POS 1
/*! Field PCEINT - Parser and Classification Engine Interrupt */
#define ETHSW_ISR_PCEINT_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_ETHSW_ISR_PCEINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_ETHSW_ISR_PCEINT_INT 0x1

/*! Field MACINT - PMAC Interrupt */
#define ETHSW_ISR_MACINT_POS 2
/*! Field MACINT - PMAC Interrupt */
#define ETHSW_ISR_MACINT_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_ETHSW_ISR_MACINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_ETHSW_ISR_MACINT_INT 0x1

/*! Field SDMAINT - Store DMA Interrupt */
#define ETHSW_ISR_SDMAINT_POS 3
/*! Field SDMAINT - Store DMA Interrupt */
#define ETHSW_ISR_SDMAINT_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_ETHSW_ISR_SDMAINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_ETHSW_ISR_SDMAINT_INT 0x1

/*! Field FDMAINT - Fetch DMA Interrupt */
#define ETHSW_ISR_FDMAINT_POS 4
/*! Field FDMAINT - Fetch DMA Interrupt */
#define ETHSW_ISR_FDMAINT_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_ETHSW_ISR_FDMAINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_ETHSW_ISR_FDMAINT_INT 0x1

/*! @} */

/*! \defgroup ETHSW_CAP_13 Register ETHSW_CAP_13 - Ethernet Switch Capability Register 13 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_13 0x58
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_13 0x18450058u

/*! Register Reset Value */
#define ETHSW_CAP_13_RST 0x0000269Au

/*! Field EVLAN - Extended VLAN Tagging Operation Table Size */
#define ETHSW_CAP_13_EVLAN_POS 0
/*! Field EVLAN - Extended VLAN Tagging Operation Table Size */
#define ETHSW_CAP_13_EVLAN_MASK 0xFu

/*! Field INTRMON - Traffic Flow RMON Counter Table Size */
#define ETHSW_CAP_13_INTRMON_POS 4
/*! Field INTRMON - Traffic Flow RMON Counter Table Size */
#define ETHSW_CAP_13_INTRMON_MASK 0xF0u

/*! Field PAYLOAD - Payload Table Size */
#define ETHSW_CAP_13_PAYLOAD_POS 8
/*! Field PAYLOAD - Payload Table Size */
#define ETHSW_CAP_13_PAYLOAD_MASK 0xF00u

/*! Field PMAC - Number of PMAC */
#define ETHSW_CAP_13_PMAC_POS 12
/*! Field PMAC - Number of PMAC */
#define ETHSW_CAP_13_PMAC_MASK 0xF000u

/*! @} */

/*! \defgroup ETHSW_CAP_14 Register ETHSW_CAP_14 - Ethernet Switch Capability Register 14 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_14 0x5C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_14 0x1845005Cu

/*! Register Reset Value */
#define ETHSW_CAP_14_RST 0x00000000u

/*! Field NAT - Routing Session Table Size */
#define ETHSW_CAP_14_NAT_POS 0
/*! Field NAT - Routing Session Table Size */
#define ETHSW_CAP_14_NAT_MASK 0xFu

/*! Field PPPOE - Routing PPPoE Table Size */
#define ETHSW_CAP_14_PPPOE_POS 4
/*! Field PPPOE - Routing PPPoE Table Size */
#define ETHSW_CAP_14_PPPOE_MASK 0xF0u

/*! Field DMAC - Routing MAC Table Size for Destination MAC */
#define ETHSW_CAP_14_DMAC_POS 8
/*! Field DMAC - Routing MAC Table Size for Destination MAC */
#define ETHSW_CAP_14_DMAC_MASK 0xF00u

/*! Field SMAC - Routing MAC Table Size for Source MAC */
#define ETHSW_CAP_14_SMAC_POS 12
/*! Field SMAC - Routing MAC Table Size for Source MAC */
#define ETHSW_CAP_14_SMAC_MASK 0xF000u

/*! @} */

/*! \defgroup ETHSW_CAP_15 Register ETHSW_CAP_15 - Ethernet Switch Capability Register 15 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_15 0x60
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_15 0x18450060u

/*! Register Reset Value */
#define ETHSW_CAP_15_RST 0x00000000u

/*! Field RTP - Routing RTP Table Size */
#define ETHSW_CAP_15_RTP_POS 0
/*! Field RTP - Routing RTP Table Size */
#define ETHSW_CAP_15_RTP_MASK 0xFu

/*! Field TUNNEL - Routing Tunnel Table Size */
#define ETHSW_CAP_15_TUNNEL_POS 4
/*! Field TUNNEL - Routing Tunnel Table Size */
#define ETHSW_CAP_15_TUNNEL_MASK 0xF0u

/*! Field MTU - Routing MTU Table Size */
#define ETHSW_CAP_15_MTU_POS 8
/*! Field MTU - Routing MTU Table Size */
#define ETHSW_CAP_15_MTU_MASK 0xF00u

/*! @} */

/*! \defgroup ETHSW_CAP_16 Register ETHSW_CAP_16 - Ethernet Switch Capability Register 16 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_16 0x64
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_16 0x18450064u

/*! Register Reset Value */
#define ETHSW_CAP_16_RST 0x0000003Au

/*! Field VLANMAP - VLAN Filter Table Size */
#define ETHSW_CAP_16_VLANMAP_POS 0
/*! Field VLANMAP - VLAN Filter Table Size */
#define ETHSW_CAP_16_VLANMAP_MASK 0xFu

/*! Field VLANMD - VLAN Filter Table Mode */
#define ETHSW_CAP_16_VLANMD_POS 4
/*! Field VLANMD - VLAN Filter Table Mode */
#define ETHSW_CAP_16_VLANMD_MASK 0x10u
/*! Constant ID - ID */
#define CONST_ETHSW_CAP_16_VLANMD_ID 0x0
/*! Constant TCI - TCI */
#define CONST_ETHSW_CAP_16_VLANMD_TCI 0x1

/*! Field MCSTHW - Multicast HW Enable */
#define ETHSW_CAP_16_MCSTHW_POS 5
/*! Field MCSTHW - Multicast HW Enable */
#define ETHSW_CAP_16_MCSTHW_MASK 0x20u
/*! Constant EN - EN */
#define CONST_ETHSW_CAP_16_MCSTHW_EN 0x0
/*! Constant DIS - DIS */
#define CONST_ETHSW_CAP_16_MCSTHW_DIS 0x1

/*! @} */

/*! \defgroup ETHSW_CAP_17 Register ETHSW_CAP_17 - Ethernet Switch Capability Register 17 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_17 0x68
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_17 0x18450068u

/*! Register Reset Value */
#define ETHSW_CAP_17_RST 0x00000567u

/*! Field BRGPT - Number of Bridge Ports */
#define ETHSW_CAP_17_BRGPT_POS 0
/*! Field BRGPT - Number of Bridge Ports */
#define ETHSW_CAP_17_BRGPT_MASK 0xFu

/*! Field BRG - Number of Bridges */
#define ETHSW_CAP_17_BRG_POS 4
/*! Field BRG - Number of Bridges */
#define ETHSW_CAP_17_BRG_MASK 0xF0u

/*! Field PMAP - Number of P-Mapper */
#define ETHSW_CAP_17_PMAP_POS 8
/*! Field PMAP - Number of P-Mapper */
#define ETHSW_CAP_17_PMAP_MASK 0xF00u

/*! @} */

/*! \defgroup ETHSW_CAP_18 Register ETHSW_CAP_18 - Ethernet Switch Capability Register 18 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CAP_18 0x6C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CAP_18 0x1845006Cu

/*! Register Reset Value */
#define ETHSW_CAP_18_RST 0x00000120u

/*! Field CTPPT - Number of CTP Ports */
#define ETHSW_CAP_18_CTPPT_POS 0
/*! Field CTPPT - Number of CTP Ports */
#define ETHSW_CAP_18_CTPPT_MASK 0xFFFFu

/*! @} */

/*! \defgroup MAC_WM_CFG Register MAC_WM_CFG - MAC Activity Watermark Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define MAC_WM_CFG 0x70
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_MAC_WM_CFG 0x18450070u

/*! Register Reset Value */
#define MAC_WM_CFG_RST 0x00000303u

/*! Field MAC_WM0 - Active MAC/PMAC watermakr for low state activity */
#define MAC_WM_CFG_MAC_WM0_POS 0
/*! Field MAC_WM0 - Active MAC/PMAC watermakr for low state activity */
#define MAC_WM_CFG_MAC_WM0_MASK 0x1Fu

/*! Field MAC_WM1 - Active MAC/PMAC watermakr for high state activity */
#define MAC_WM_CFG_MAC_WM1_POS 8
/*! Field MAC_WM1 - Active MAC/PMAC watermakr for high state activity */
#define MAC_WM_CFG_MAC_WM1_MASK 0x1F00u

/*! @} */

/*! \defgroup PKT_WM0_CFG Register PKT_WM0_CFG - Packet Activity Watermark 0 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define PKT_WM0_CFG 0x74
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PKT_WM0_CFG 0x18450074u

/*! Register Reset Value */
#define PKT_WM0_CFG_RST 0x0000000Au

/*! Field PKT_WM0 - Pending Ingress Packet Watermark for High State Activity */
#define PKT_WM0_CFG_PKT_WM0_POS 0
/*! Field PKT_WM0 - Pending Ingress Packet Watermark for High State Activity */
#define PKT_WM0_CFG_PKT_WM0_MASK 0x7FFu

/*! @} */

/*! \defgroup PKT_WM1_CFG Register PKT_WM1_CFG - Packet Activity Watermark 1 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define PKT_WM1_CFG 0x78
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PKT_WM1_CFG 0x18450078u

/*! Register Reset Value */
#define PKT_WM1_CFG_RST 0x00000014u

/*! Field PKT_WM1 - Pending Ingress Packet Watermark for Low State Activity */
#define PKT_WM1_CFG_PKT_WM1_POS 0
/*! Field PKT_WM1 - Pending Ingress Packet Watermark for Low State Activity */
#define PKT_WM1_CFG_PKT_WM1_MASK 0x7FFu

/*! @} */

/*! \defgroup BM_RAM_VAL_9 Register BM_RAM_VAL_9 - RAM Value Register 9 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_9 0xE8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_9 0x184500E8u

/*! Register Reset Value */
#define BM_RAM_VAL_9_RST 0x00000000u

/*! Field VAL9 - Data value [15:0] */
#define BM_RAM_VAL_9_VAL9_POS 0
/*! Field VAL9 - Data value [15:0] */
#define BM_RAM_VAL_9_VAL9_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_8 Register BM_RAM_VAL_8 - RAM Value Register 8 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_8 0xEC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_8 0x184500ECu

/*! Register Reset Value */
#define BM_RAM_VAL_8_RST 0x00000000u

/*! Field VAL8 - Data value [15:0] */
#define BM_RAM_VAL_8_VAL8_POS 0
/*! Field VAL8 - Data value [15:0] */
#define BM_RAM_VAL_8_VAL8_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_7 Register BM_RAM_VAL_7 - RAM Value Register 7 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_7 0xF0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_7 0x184500F0u

/*! Register Reset Value */
#define BM_RAM_VAL_7_RST 0x00000000u

/*! Field VAL7 - Data value [15:0] */
#define BM_RAM_VAL_7_VAL7_POS 0
/*! Field VAL7 - Data value [15:0] */
#define BM_RAM_VAL_7_VAL7_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_6 Register BM_RAM_VAL_6 - RAM Value Register 6 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_6 0xF4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_6 0x184500F4u

/*! Register Reset Value */
#define BM_RAM_VAL_6_RST 0x00000000u

/*! Field VAL6 - Data value [15:0] */
#define BM_RAM_VAL_6_VAL6_POS 0
/*! Field VAL6 - Data value [15:0] */
#define BM_RAM_VAL_6_VAL6_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_5 Register BM_RAM_VAL_5 - RAM Value Register 5 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_5 0xF8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_5 0x184500F8u

/*! Register Reset Value */
#define BM_RAM_VAL_5_RST 0x00000000u

/*! Field VAL5 - Data value [15:0] */
#define BM_RAM_VAL_5_VAL5_POS 0
/*! Field VAL5 - Data value [15:0] */
#define BM_RAM_VAL_5_VAL5_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_4 Register BM_RAM_VAL_4 - RAM Value Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_4 0xFC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_4 0x184500FCu

/*! Register Reset Value */
#define BM_RAM_VAL_4_RST 0x00000000u

/*! Field VAL4 - Data value [15:0] */
#define BM_RAM_VAL_4_VAL4_POS 0
/*! Field VAL4 - Data value [15:0] */
#define BM_RAM_VAL_4_VAL4_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_3 Register BM_RAM_VAL_3 - RAM Value Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_3 0x100
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_3 0x18450100u

/*! Register Reset Value */
#define BM_RAM_VAL_3_RST 0x00000000u

/*! Field VAL3 - Data value [15:0] */
#define BM_RAM_VAL_3_VAL3_POS 0
/*! Field VAL3 - Data value [15:0] */
#define BM_RAM_VAL_3_VAL3_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_2 Register BM_RAM_VAL_2 - RAM Value Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_2 0x104
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_2 0x18450104u

/*! Register Reset Value */
#define BM_RAM_VAL_2_RST 0x00000000u

/*! Field VAL2 - Data value [15:0] */
#define BM_RAM_VAL_2_VAL2_POS 0
/*! Field VAL2 - Data value [15:0] */
#define BM_RAM_VAL_2_VAL2_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_1 Register BM_RAM_VAL_1 - RAM Value Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_1 0x108
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_1 0x18450108u

/*! Register Reset Value */
#define BM_RAM_VAL_1_RST 0x00000000u

/*! Field VAL1 - Data value [15:0] */
#define BM_RAM_VAL_1_VAL1_POS 0
/*! Field VAL1 - Data value [15:0] */
#define BM_RAM_VAL_1_VAL1_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_VAL_0 Register BM_RAM_VAL_0 - RAM Value Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_VAL_0 0x10C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_VAL_0 0x1845010Cu

/*! Register Reset Value */
#define BM_RAM_VAL_0_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define BM_RAM_VAL_0_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define BM_RAM_VAL_0_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_ADDR Register BM_RAM_ADDR - RAM Address Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_ADDR 0x110
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_ADDR 0x18450110u

/*! Register Reset Value */
#define BM_RAM_ADDR_RST 0x00000000u

/*! Field ADDR - RAM Address */
#define BM_RAM_ADDR_ADDR_POS 0
/*! Field ADDR - RAM Address */
#define BM_RAM_ADDR_ADDR_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_RAM_CTRL Register BM_RAM_CTRL - RAM Access Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RAM_CTRL 0x114
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RAM_CTRL 0x18450114u

/*! Register Reset Value */
#define BM_RAM_CTRL_RST 0x00000000u

/*! Field ADDR - Address for RAM selection */
#define BM_RAM_CTRL_ADDR_POS 0
/*! Field ADDR - Address for RAM selection */
#define BM_RAM_CTRL_ADDR_MASK 0x1Fu
/*! Constant RMONCTPRX - RMONCTPRX */
#define CONST_BM_RAM_CTRL_ADDR_RMONCTPRX 0x0
/*! Constant RMONCTPTX - RMONCTPTX */
#define CONST_BM_RAM_CTRL_ADDR_RMONCTPTX 0x1
/*! Constant RMONBRGRX - RMONBRGRX */
#define CONST_BM_RAM_CTRL_ADDR_RMONBRGRX 0x2
/*! Constant RMONBRGTX - RMONBRGTX */
#define CONST_BM_RAM_CTRL_ADDR_RMONBRGTX 0x3
/*! Constant RMONCTPBP - RMONCTPBP */
#define CONST_BM_RAM_CTRL_ADDR_RMONCTPBP 0x4
/*! Constant RMONFLOWRX - RMONFLOWRX */
#define CONST_BM_RAM_CTRL_ADDR_RMONFLOWRX 0x5
/*! Constant RMONFLOWTX - RMONFLOWTX */
#define CONST_BM_RAM_CTRL_ADDR_RMONFLOWTX 0x6
/*! Constant WFQ - WFQ */
#define CONST_BM_RAM_CTRL_ADDR_WFQ 0x8
/*! Constant PQMCTXT - PQMCTXT */
#define CONST_BM_RAM_CTRL_ADDR_PQMCTXT 0x9
/*! Constant PQMPP - PQMPP */
#define CONST_BM_RAM_CTRL_ADDR_PQMPP 0xA
/*! Constant SLLNP - SLLNP */
#define CONST_BM_RAM_CTRL_ADDR_SLLNP 0xB
/*! Constant SLLHD1 - SLLHD1 */
#define CONST_BM_RAM_CTRL_ADDR_SLLHD1 0xC
/*! Constant SLLHD2 - SLLHD2 */
#define CONST_BM_RAM_CTRL_ADDR_SLLHD2 0xD
/*! Constant QMAP - QMAP */
#define CONST_BM_RAM_CTRL_ADDR_QMAP 0xE
/*! Constant RMONMETER - RMONMETER */
#define CONST_BM_RAM_CTRL_ADDR_RMONMETER 0x19
/*! Constant RMONPMAC - RMONPMAC */
#define CONST_BM_RAM_CTRL_ADDR_RMONPMAC 0x1C

/*! Field OPMOD - Lookup Table Access Operation Mode */
#define BM_RAM_CTRL_OPMOD_POS 5
/*! Field OPMOD - Lookup Table Access Operation Mode */
#define BM_RAM_CTRL_OPMOD_MASK 0x20u
/*! Constant RD - RD */
#define CONST_BM_RAM_CTRL_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_BM_RAM_CTRL_OPMOD_WR 0x1

/*! Field RMON - RMON Counter Access Mode */
#define BM_RAM_CTRL_RMON_POS 6
/*! Field RMON - RMON Counter Access Mode */
#define BM_RAM_CTRL_RMON_MASK 0x40u
/*! Constant V32_BIT - 32-bit */
#define CONST_BM_RAM_CTRL_RMON_V32_BIT 0x0
/*! Constant V64_BIT - 64-bit */
#define CONST_BM_RAM_CTRL_RMON_V64_BIT 0x1

/*! Field BAS - Access Busy/Access Start */
#define BM_RAM_CTRL_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define BM_RAM_CTRL_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_BM_RAM_CTRL_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_BM_RAM_CTRL_BAS_BUSY 0x1

/*! @} */

/*! \defgroup BM_FSQM_GCTRL Register BM_FSQM_GCTRL - Free Segment Queue Manager Global Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_FSQM_GCTRL 0x118
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_FSQM_GCTRL 0x18450118u

/*! Register Reset Value */
#define BM_FSQM_GCTRL_RST 0x000003FFu

/*! Field SEGNUM - Maximum Segment Number */
#define BM_FSQM_GCTRL_SEGNUM_POS 0
/*! Field SEGNUM - Maximum Segment Number */
#define BM_FSQM_GCTRL_SEGNUM_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_CONS_SEG Register BM_CONS_SEG - Number of Consumed Segments Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_CONS_SEG 0x11C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_CONS_SEG 0x1845011Cu

/*! Register Reset Value */
#define BM_CONS_SEG_RST 0x00000000u

/*! Field FSEG - Number of Consumed Segments */
#define BM_CONS_SEG_FSEG_POS 0
/*! Field FSEG - Number of Consumed Segments */
#define BM_CONS_SEG_FSEG_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_CONS_PKT Register BM_CONS_PKT - Number of Consumed Packet Pointers Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_CONS_PKT 0x120
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_CONS_PKT 0x18450120u

/*! Register Reset Value */
#define BM_CONS_PKT_RST 0x00000000u

/*! Field FQP - Number of Consumed Packet Pointers */
#define BM_CONS_PKT_FQP_POS 0
/*! Field FQP - Number of Consumed Packet Pointers */
#define BM_CONS_PKT_FQP_MASK 0x7FFu

/*! @} */

/*! \defgroup BM_GCTRL Register BM_GCTRL - Buffer Manager Global Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_GCTRL 0x124
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_GCTRL 0x18450124u

/*! Register Reset Value */
#define BM_GCTRL_RST 0x00000100u

/*! Field F_SRES - Software Reset for FSQM */
#define BM_GCTRL_F_SRES_POS 0
/*! Field F_SRES - Software Reset for FSQM */
#define BM_GCTRL_F_SRES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_F_SRES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_GCTRL_F_SRES_RES 0x1

/*! Field P_SRES - Software Reset for PQM */
#define BM_GCTRL_P_SRES_POS 1
/*! Field P_SRES - Software Reset for PQM */
#define BM_GCTRL_P_SRES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_P_SRES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_GCTRL_P_SRES_RES 0x1

/*! Field A_SRES - Software Reset for AVG */
#define BM_GCTRL_A_SRES_POS 2
/*! Field A_SRES - Software Reset for AVG */
#define BM_GCTRL_A_SRES_MASK 0x4u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_A_SRES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_GCTRL_A_SRES_RES 0x1

/*! Field S_SRES - Software Reset for Scheduler */
#define BM_GCTRL_S_SRES_POS 3
/*! Field S_SRES - Software Reset for Scheduler */
#define BM_GCTRL_S_SRES_MASK 0x8u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_S_SRES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_GCTRL_S_SRES_RES 0x1

/*! Field R_SRES - Software Reset for RMON */
#define BM_GCTRL_R_SRES_POS 4
/*! Field R_SRES - Software Reset for RMON */
#define BM_GCTRL_R_SRES_MASK 0x10u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_R_SRES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_GCTRL_R_SRES_RES 0x1

/*! Field FS_INI - FSQM RAM initialization */
#define BM_GCTRL_FS_INI_POS 5
/*! Field FS_INI - FSQM RAM initialization */
#define BM_GCTRL_FS_INI_MASK 0x20u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_FS_INI_NOP 0x0
/*! Constant INI - INI */
#define CONST_BM_GCTRL_FS_INI_INI 0x1

/*! Field FP_INI - FPQM RAM initialization */
#define BM_GCTRL_FP_INI_POS 6
/*! Field FP_INI - FPQM RAM initialization */
#define BM_GCTRL_FP_INI_MASK 0x40u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_FP_INI_NOP 0x0
/*! Constant INI - INI */
#define CONST_BM_GCTRL_FP_INI_INI 0x1

/*! Field CX_INI - PQM Context RAM initialization */
#define BM_GCTRL_CX_INI_POS 7
/*! Field CX_INI - PQM Context RAM initialization */
#define BM_GCTRL_CX_INI_MASK 0x80u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_CX_INI_NOP 0x0
/*! Constant INI - INI */
#define CONST_BM_GCTRL_CX_INI_INI 0x1

/*! Field I_FIN - RAM initialization finished */
#define BM_GCTRL_I_FIN_POS 8
/*! Field I_FIN - RAM initialization finished */
#define BM_GCTRL_I_FIN_MASK 0x100u
/*! Constant NOP - NOP */
#define CONST_BM_GCTRL_I_FIN_NOP 0x0
/*! Constant INI - INI */
#define CONST_BM_GCTRL_I_FIN_INI 0x1

/*! Field SAT - RMON Counter Update Mode */
#define BM_GCTRL_SAT_POS 12
/*! Field SAT - RMON Counter Update Mode */
#define BM_GCTRL_SAT_MASK 0x1000u
/*! Constant OFF - OFF */
#define CONST_BM_GCTRL_SAT_OFF 0x0
/*! Constant ON - ON */
#define CONST_BM_GCTRL_SAT_ON 0x1

/*! Field BM_STA - Buffer Manager Initialization Status Bit */
#define BM_GCTRL_BM_STA_POS 13
/*! Field BM_STA - Buffer Manager Initialization Status Bit */
#define BM_GCTRL_BM_STA_MASK 0x2000u
/*! Constant NRDY - NRDY */
#define CONST_BM_GCTRL_BM_STA_NRDY 0x0
/*! Constant RDY - RDY */
#define CONST_BM_GCTRL_BM_STA_RDY 0x1

/*! @} */

/*! \defgroup BM_QUEUE_GCTRL Register BM_QUEUE_GCTRL - Queue Manager Global Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_QUEUE_GCTRL 0x128
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_QUEUE_GCTRL 0x18450128u

/*! Register Reset Value */
#define BM_QUEUE_GCTRL_RST 0x00000118u

/*! Field DPROB - Drop Probability Profile */
#define BM_QUEUE_GCTRL_DPROB_POS 0
/*! Field DPROB - Drop Probability Profile */
#define BM_QUEUE_GCTRL_DPROB_MASK 0x3u
/*! Constant P0 - P0 */
#define CONST_BM_QUEUE_GCTRL_DPROB_P0 0x0
/*! Constant P1 - P1 */
#define CONST_BM_QUEUE_GCTRL_DPROB_P1 0x1
/*! Constant P2 - P2 */
#define CONST_BM_QUEUE_GCTRL_DPROB_P2 0x2
/*! Constant P3 - P3 */
#define CONST_BM_QUEUE_GCTRL_DPROB_P3 0x3

/*! Field AQWF - Average Queue Weight Factor */
#define BM_QUEUE_GCTRL_AQWF_POS 3
/*! Field AQWF - Average Queue Weight Factor */
#define BM_QUEUE_GCTRL_AQWF_MASK 0x78u

/*! Field AQUI - Average Queue Update Interval */
#define BM_QUEUE_GCTRL_AQUI_POS 7
/*! Field AQUI - Average Queue Update Interval */
#define BM_QUEUE_GCTRL_AQUI_MASK 0x380u
/*! Constant UI0010 - UI0010 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI0010 0x0
/*! Constant UI0020 - UI0020 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI0020 0x1
/*! Constant UI0041 - UI0041 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI0041 0x2
/*! Constant UI0082 - UI0082 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI0082 0x3
/*! Constant UI0164 - UI0164 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI0164 0x4
/*! Constant UI0328 - UI0328 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI0328 0x5
/*! Constant UI0655 - UI0655 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI0655 0x6
/*! Constant UI1311 - UI1311 */
#define CONST_BM_QUEUE_GCTRL_AQUI_UI1311 0x7

/*! Field GL_MOD - WRED Mode */
#define BM_QUEUE_GCTRL_GL_MOD_POS 10
/*! Field GL_MOD - WRED Mode */
#define BM_QUEUE_GCTRL_GL_MOD_MASK 0xC00u
/*! Constant LOC - LOC */
#define CONST_BM_QUEUE_GCTRL_GL_MOD_LOC 0x0
/*! Constant GLOB - GLOB */
#define CONST_BM_QUEUE_GCTRL_GL_MOD_GLOB 0x1
/*! Constant PORT - PORT */
#define CONST_BM_QUEUE_GCTRL_GL_MOD_PORT 0x2
/*! Constant RES - RES */
#define CONST_BM_QUEUE_GCTRL_GL_MOD_RES 0x3

/*! Field BUFMOD - Buffer Control Mode */
#define BM_QUEUE_GCTRL_BUFMOD_POS 12
/*! Field BUFMOD - Buffer Control Mode */
#define BM_QUEUE_GCTRL_BUFMOD_MASK 0x1000u
/*! Constant AUTO - AUTO */
#define CONST_BM_QUEUE_GCTRL_BUFMOD_AUTO 0x0
/*! Constant MANU - MANU */
#define CONST_BM_QUEUE_GCTRL_BUFMOD_MANU 0x1

/*! @} */

/*! \defgroup BM_WRED_RTH_0 Register BM_WRED_RTH_0 - WRED Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_WRED_RTH_0 0x12C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_WRED_RTH_0 0x1845012Cu

/*! Register Reset Value */
#define BM_WRED_RTH_0_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_WRED_RTH_0_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_WRED_RTH_0_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_WRED_RTH_1 Register BM_WRED_RTH_1 - WRED Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_WRED_RTH_1 0x130
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_WRED_RTH_1 0x18450130u

/*! Register Reset Value */
#define BM_WRED_RTH_1_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_WRED_RTH_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_WRED_RTH_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_WRED_YTH_0 Register BM_WRED_YTH_0 - WRED Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_WRED_YTH_0 0x134
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_WRED_YTH_0 0x18450134u

/*! Register Reset Value */
#define BM_WRED_YTH_0_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_WRED_YTH_0_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_WRED_YTH_0_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_WRED_YTH_1 Register BM_WRED_YTH_1 - WRED Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_WRED_YTH_1 0x138
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_WRED_YTH_1 0x18450138u

/*! Register Reset Value */
#define BM_WRED_YTH_1_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_WRED_YTH_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_WRED_YTH_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_WRED_GTH_0 Register BM_WRED_GTH_0 - WRED Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_WRED_GTH_0 0x13C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_WRED_GTH_0 0x1845013Cu

/*! Register Reset Value */
#define BM_WRED_GTH_0_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_WRED_GTH_0_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_WRED_GTH_0_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_WRED_GTH_1 Register BM_WRED_GTH_1 - WRED Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_WRED_GTH_1 0x140
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_WRED_GTH_1 0x18450140u

/*! Register Reset Value */
#define BM_WRED_GTH_1_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_WRED_GTH_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_WRED_GTH_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_DROP_GTH_0 Register BM_DROP_GTH_0 - Drop Threshold Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_DROP_GTH_0 0x144
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_DROP_GTH_0 0x18450144u

/*! Register Reset Value */
#define BM_DROP_GTH_0_RST 0x000007FFu

/*! Field THR_FQ - Threshold for frames marked red */
#define BM_DROP_GTH_0_THR_FQ_POS 0
/*! Field THR_FQ - Threshold for frames marked red */
#define BM_DROP_GTH_0_THR_FQ_MASK 0x7FFu

/*! @} */

/*! \defgroup BM_DROP_GTH_1 Register BM_DROP_GTH_1 - Drop Threshold Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_DROP_GTH_1 0x148
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_DROP_GTH_1 0x18450148u

/*! Register Reset Value */
#define BM_DROP_GTH_1_RST 0x000007FFu

/*! Field THY_FQ - Threshold for frames marked yellow */
#define BM_DROP_GTH_1_THY_FQ_POS 0
/*! Field THY_FQ - Threshold for frames marked yellow */
#define BM_DROP_GTH_1_THY_FQ_MASK 0x7FFu

/*! @} */

/*! \defgroup BM_DROP_GTH_2 Register BM_DROP_GTH_2 - Drop Threshold Configuration Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_DROP_GTH_2 0x14C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_DROP_GTH_2 0x1845014Cu

/*! Register Reset Value */
#define BM_DROP_GTH_2_RST 0x000007FFu

/*! Field THG_FQ - Threshold for frames marked green */
#define BM_DROP_GTH_2_THG_FQ_POS 0
/*! Field THG_FQ - Threshold for frames marked green */
#define BM_DROP_GTH_2_THG_FQ_MASK 0x7FFu

/*! @} */

/*! \defgroup BM_IER Register BM_IER - Buffer Manager Global Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_IER 0x150
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_IER 0x18450150u

/*! Register Reset Value */
#define BM_IER_RST 0x00000000u

/*! Field FSQM - Buffer Empty Interrupt Enable */
#define BM_IER_FSQM_POS 0
/*! Field FSQM - Buffer Empty Interrupt Enable */
#define BM_IER_FSQM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_IER_FSQM_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_FSQM_EN 0x1

/*! Field ENQ - PQM Enqueue Interrupt Enable */
#define BM_IER_ENQ_POS 1
/*! Field ENQ - PQM Enqueue Interrupt Enable */
#define BM_IER_ENQ_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_BM_IER_ENQ_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_ENQ_EN 0x1

/*! Field DEQ - PQM dequeue Interrupt Enable */
#define BM_IER_DEQ_POS 2
/*! Field DEQ - PQM dequeue Interrupt Enable */
#define BM_IER_DEQ_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_BM_IER_DEQ_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_DEQ_EN 0x1

/*! Field CNT0 - Counter Group 0 (RMON-QSTOR) Interrupt Enable */
#define BM_IER_CNT0_POS 3
/*! Field CNT0 - Counter Group 0 (RMON-QSTOR) Interrupt Enable */
#define BM_IER_CNT0_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_BM_IER_CNT0_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_CNT0_EN 0x1

/*! Field CNT1 - Counter Group 1 (RMON-QFETCH) Interrupt Enable */
#define BM_IER_CNT1_POS 4
/*! Field CNT1 - Counter Group 1 (RMON-QFETCH) Interrupt Enable */
#define BM_IER_CNT1_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_BM_IER_CNT1_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_CNT1_EN 0x1

/*! Field CNT2 - Counter Group 2 (RMON-SCHEDULER) Interrupt Enable */
#define BM_IER_CNT2_POS 5
/*! Field CNT2 - Counter Group 2 (RMON-SCHEDULER) Interrupt Enable */
#define BM_IER_CNT2_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_BM_IER_CNT2_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_CNT2_EN 0x1

/*! Field CNT3 - Counter Group 3 (RMON-PQM) Interrupt Enable */
#define BM_IER_CNT3_POS 6
/*! Field CNT3 - Counter Group 3 (RMON-PQM) Interrupt Enable */
#define BM_IER_CNT3_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_BM_IER_CNT3_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_CNT3_EN 0x1

/*! Field CNT4 - Counter Group 4 (RMON-CLASSIFICATION) Interrupt Enable */
#define BM_IER_CNT4_POS 7
/*! Field CNT4 - Counter Group 4 (RMON-CLASSIFICATION) Interrupt Enable */
#define BM_IER_CNT4_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_BM_IER_CNT4_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_CNT4_EN 0x1

/*! Field QCGN - Egress Queue Congestion Status Change Interrupt Enable */
#define BM_IER_QCGN_POS 8
/*! Field QCGN - Egress Queue Congestion Status Change Interrupt Enable */
#define BM_IER_QCGN_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_BM_IER_QCGN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_IER_QCGN_EN 0x1

/*! @} */

/*! \defgroup BM_ISR Register BM_ISR - Buffer Manager Global Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_ISR 0x154
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_ISR 0x18450154u

/*! Register Reset Value */
#define BM_ISR_RST 0x00000000u

/*! Field FSQM - Buffer Empty Interrupt */
#define BM_ISR_FSQM_POS 0
/*! Field FSQM - Buffer Empty Interrupt */
#define BM_ISR_FSQM_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_FSQM_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_FSQM_INT 0x1

/*! Field ENQ - PQM Enqueue Interrupt */
#define BM_ISR_ENQ_POS 1
/*! Field ENQ - PQM Enqueue Interrupt */
#define BM_ISR_ENQ_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_ENQ_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_ENQ_INT 0x1

/*! Field DEQ - PQM dequeue Interrupt Enable */
#define BM_ISR_DEQ_POS 2
/*! Field DEQ - PQM dequeue Interrupt Enable */
#define BM_ISR_DEQ_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_DEQ_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_DEQ_INT 0x1

/*! Field CNT0 - Counter Group 0 Interrupt */
#define BM_ISR_CNT0_POS 3
/*! Field CNT0 - Counter Group 0 Interrupt */
#define BM_ISR_CNT0_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_CNT0_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_CNT0_INT 0x1

/*! Field CNT1 - Counter Group 1 Interrupt */
#define BM_ISR_CNT1_POS 4
/*! Field CNT1 - Counter Group 1 Interrupt */
#define BM_ISR_CNT1_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_CNT1_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_CNT1_INT 0x1

/*! Field CNT2 - Counter Group 2 Interrupt */
#define BM_ISR_CNT2_POS 5
/*! Field CNT2 - Counter Group 2 Interrupt */
#define BM_ISR_CNT2_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_CNT2_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_CNT2_INT 0x1

/*! Field CNT3 - Counter Group 3 Interrupt */
#define BM_ISR_CNT3_POS 6
/*! Field CNT3 - Counter Group 3 Interrupt */
#define BM_ISR_CNT3_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_CNT3_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_CNT3_INT 0x1

/*! Field CNT4 - Counter Group 4 Interrupt */
#define BM_ISR_CNT4_POS 7
/*! Field CNT4 - Counter Group 4 Interrupt */
#define BM_ISR_CNT4_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_CNT4_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_CNT4_INT 0x1

/*! Field EQCGN - Egress Queue Congestion Status Change Interrupt */
#define BM_ISR_EQCGN_POS 8
/*! Field EQCGN - Egress Queue Congestion Status Change Interrupt */
#define BM_ISR_EQCGN_MASK 0x100u
/*! Constant NOINT - NOINT */
#define CONST_BM_ISR_EQCGN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_BM_ISR_EQCGN_INT 0x1

/*! @} */

/*! \defgroup BM_CISEL Register BM_CISEL - Buffer Manager RMON Counter Interrupt Select Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_CISEL 0x158
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_CISEL 0x18450158u

/*! Register Reset Value */
#define BM_CISEL_RST 0x00000000u

/*! Field PORT - Port Number */
#define BM_CISEL_PORT_POS 0
/*! Field PORT - Port Number */
#define BM_CISEL_PORT_MASK 0xFu
/*! Constant P0 - P0 */
#define CONST_BM_CISEL_PORT_P0 0x0
/*! Constant P1 - P1 */
#define CONST_BM_CISEL_PORT_P1 0x1
/*! Constant P2 - P2 */
#define CONST_BM_CISEL_PORT_P2 0x2
/*! Constant P3 - P3 */
#define CONST_BM_CISEL_PORT_P3 0x3
/*! Constant P4 - P4 */
#define CONST_BM_CISEL_PORT_P4 0x4
/*! Constant P5 - P5 */
#define CONST_BM_CISEL_PORT_P5 0x5
/*! Constant P6 - P6 */
#define CONST_BM_CISEL_PORT_P6 0x6
/*! Constant P7 - P7 */
#define CONST_BM_CISEL_PORT_P7 0x7
/*! Constant P8 - P8 */
#define CONST_BM_CISEL_PORT_P8 0x8
/*! Constant P9 - P9 */
#define CONST_BM_CISEL_PORT_P9 0x9
/*! Constant P10 - P10 */
#define CONST_BM_CISEL_PORT_P10 0xA
/*! Constant P11 - P11 */
#define CONST_BM_CISEL_PORT_P11 0xB
/*! Constant P12 - P12 */
#define CONST_BM_CISEL_PORT_P12 0xC
/*! Constant P13 - P13 */
#define CONST_BM_CISEL_PORT_P13 0xD
/*! Constant P14 - P14 */
#define CONST_BM_CISEL_PORT_P14 0xE
/*! Constant P15 - P15 */
#define CONST_BM_CISEL_PORT_P15 0xF

/*! @} */

/*! \defgroup BM_DEBUG_CTRL Register BM_DEBUG_CTRL - Debug Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_DEBUG_CTRL 0x15C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_DEBUG_CTRL 0x1845015Cu

/*! Register Reset Value */
#define BM_DEBUG_CTRL_RST 0x00000000u

/*! Field DBG_SEL - Select Signal for Debug Multiplexer */
#define BM_DEBUG_CTRL_DBG_SEL_POS 0
/*! Field DBG_SEL - Select Signal for Debug Multiplexer */
#define BM_DEBUG_CTRL_DBG_SEL_MASK 0xFFu

/*! @} */

/*! \defgroup BM_DEBUG_VAL Register BM_DEBUG_VAL - Debug Value Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_DEBUG_VAL 0x160
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_DEBUG_VAL 0x18450160u

/*! Register Reset Value */
#define BM_DEBUG_VAL_RST 0x00000000u

/*! Field DBG_DAT - Debug Data Value */
#define BM_DEBUG_VAL_DBG_DAT_POS 0
/*! Field DBG_DAT - Debug Data Value */
#define BM_DEBUG_VAL_DBG_DAT_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_EQCGN0 Register BM_EQCGN0 - BM Egress Queue Congestion Notification Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_EQCGN0 0x164
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_EQCGN0 0x18450164u

/*! Register Reset Value */
#define BM_EQCGN0_RST 0x00000000u

/*! Field EQCGN0 - Egress Queue Congestion Notification Queue 15 to 0 */
#define BM_EQCGN0_EQCGN0_POS 0
/*! Field EQCGN0 - Egress Queue Congestion Notification Queue 15 to 0 */
#define BM_EQCGN0_EQCGN0_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_EQCGN1 Register BM_EQCGN1 - BM Egress Queue Congestion Notification Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_EQCGN1 0x168
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_EQCGN1 0x18450168u

/*! Register Reset Value */
#define BM_EQCGN1_RST 0x00000000u

/*! Field EQCGN1 - Egress Queue Congestion Notification Queue 31 to 16 */
#define BM_EQCGN1_EQCGN1_POS 0
/*! Field EQCGN1 - Egress Queue Congestion Notification Queue 31 to 16 */
#define BM_EQCGN1_EQCGN1_MASK 0xFFFFu

/*! @} */

/*! \defgroup BM_OVERHD Register BM_OVERHD - BM WFQ and Shaper Overhead Byte Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define BM_OVERHD 0x184
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_OVERHD 0x18450184u

/*! Register Reset Value */
#define BM_OVERHD_RST 0x00000000u

/*! Field OVERHD - BM WFQ and Shaper Overhead Byte */
#define BM_OVERHD_OVERHD_POS 0
/*! Field OVERHD - BM WFQ and Shaper Overhead Byte */
#define BM_OVERHD_OVERHD_MASK 0xFFu

/*! @} */

/*! \defgroup BM_RMON_GCTRL Register BM_RMON_GCTRL - BM RMON Global Control Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_GCTRL 0x188
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_GCTRL 0x18450188u

/*! Register Reset Value */
#define BM_RMON_GCTRL_RST 0x00000000u

/*! Field METER_RES - Software Reset for Meter RMON RAM */
#define BM_RMON_GCTRL_METER_RES_POS 1
/*! Field METER_RES - Software Reset for Meter RMON RAM */
#define BM_RMON_GCTRL_METER_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_GCTRL_METER_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_GCTRL_METER_RES_RES 0x1

/*! Field ALLITF_RES - Software Reset for All bridge port RMON RAM */
#define BM_RMON_GCTRL_ALLITF_RES_POS 2
/*! Field ALLITF_RES - Software Reset for All bridge port RMON RAM */
#define BM_RMON_GCTRL_ALLITF_RES_MASK 0x4u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_GCTRL_ALLITF_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_GCTRL_ALLITF_RES_RES 0x1

/*! Field INT_RES - Software Reset for a Single bridge port RMON RAM */
#define BM_RMON_GCTRL_INT_RES_POS 3
/*! Field INT_RES - Software Reset for a Single bridge port RMON RAM */
#define BM_RMON_GCTRL_INT_RES_MASK 0x8u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_GCTRL_INT_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_GCTRL_INT_RES_RES 0x1

/*! Field ITFID - Bridge Port ID to be Reset */
#define BM_RMON_GCTRL_ITFID_POS 4
/*! Field ITFID - Bridge Port ID to be Reset */
#define BM_RMON_GCTRL_ITFID_MASK 0xFF0u

/*! Field PMAC_RES - Software Reset for PMAC RMON RAM */
#define BM_RMON_GCTRL_PMAC_RES_POS 12
/*! Field PMAC_RES - Software Reset for PMAC RMON RAM */
#define BM_RMON_GCTRL_PMAC_RES_MASK 0x1000u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_GCTRL_PMAC_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_GCTRL_PMAC_RES_RES 0x1

/*! Field MRMON - Meter RMON Counter Mode */
#define BM_RMON_GCTRL_MRMON_POS 14
/*! Field MRMON - Meter RMON Counter Mode */
#define BM_RMON_GCTRL_MRMON_MASK 0x4000u
/*! Constant PACKET - Packet */
#define CONST_BM_RMON_GCTRL_MRMON_PACKET 0x0
/*! Constant BYTE - Byte */
#define CONST_BM_RMON_GCTRL_MRMON_BYTE 0x1

/*! @} */

/*! \defgroup BM_RXFLOW_RMON Register BM_RXFLOW_RMON - Ethernet RX Traffic Flow RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RXFLOW_RMON 0x18C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RXFLOW_RMON 0x1845018Cu

/*! Register Reset Value */
#define BM_RXFLOW_RMON_RST 0x00000000u

/*! Field MSB - RX Traffic Flow CTP or Bridge Port MSB */
#define BM_RXFLOW_RMON_MSB_POS 3
/*! Field MSB - RX Traffic Flow CTP or Bridge Port MSB */
#define BM_RXFLOW_RMON_MSB_MASK 0x1F8u

/*! Field LSB - RX Traffic Flow RMON Counting LSB Configuration */
#define BM_RXFLOW_RMON_LSB_POS 9
/*! Field LSB - RX Traffic Flow RMON Counting LSB Configuration */
#define BM_RXFLOW_RMON_LSB_MASK 0xE00u

/*! Field MD - RX Traffic Flow RMON Counting Mode */
#define BM_RXFLOW_RMON_MD_POS 14
/*! Field MD - RX Traffic Flow RMON Counting Mode */
#define BM_RXFLOW_RMON_MD_MASK 0xC000u
/*! Constant GL - GL */
#define CONST_BM_RXFLOW_RMON_MD_GL 0x0
/*! Constant LPORT - LPORT */
#define CONST_BM_RXFLOW_RMON_MD_LPORT 0x1
/*! Constant CTP - CTP */
#define CONST_BM_RXFLOW_RMON_MD_CTP 0x2
/*! Constant BRGP - BRGP */
#define CONST_BM_RXFLOW_RMON_MD_BRGP 0x3

/*! @} */

/*! \defgroup BM_TXFLOW_RMON Register BM_TXFLOW_RMON - TX Traffic Flow RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_TXFLOW_RMON 0x190
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_TXFLOW_RMON 0x18450190u

/*! Register Reset Value */
#define BM_TXFLOW_RMON_RST 0x00000000u

/*! Field MSB - TX Traffic Flow CTP or Bridge Port MSB */
#define BM_TXFLOW_RMON_MSB_POS 3
/*! Field MSB - TX Traffic Flow CTP or Bridge Port MSB */
#define BM_TXFLOW_RMON_MSB_MASK 0x1F8u

/*! Field LSB - TX Traffic Flow RMON Counting LSB Configuration */
#define BM_TXFLOW_RMON_LSB_POS 9
/*! Field LSB - TX Traffic Flow RMON Counting LSB Configuration */
#define BM_TXFLOW_RMON_LSB_MASK 0xE00u

/*! Field MD - TX Traffic Flow RMON Counting Mode */
#define BM_TXFLOW_RMON_MD_POS 14
/*! Field MD - TX Traffic Flow RMON Counting Mode */
#define BM_TXFLOW_RMON_MD_MASK 0xC000u
/*! Constant GL - GL */
#define CONST_BM_TXFLOW_RMON_MD_GL 0x0
/*! Constant LPORT - LPORT */
#define CONST_BM_TXFLOW_RMON_MD_LPORT 0x1
/*! Constant CTP - CTP */
#define CONST_BM_TXFLOW_RMON_MD_CTP 0x2
/*! Constant BRGP - BRGP */
#define CONST_BM_TXFLOW_RMON_MD_BRGP 0x3

/*! @} */

/*! \defgroup BM_PCFG Register BM_PCFG - Buffer Manager Port Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG 0x200
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG 0x18450200u

/*! Register Reset Value */
#define BM_PCFG_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL Register BM_RMON_CTRL - Buffer Manager Port RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL 0x204
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL 0x18450204u

/*! Register Reset Value */
#define BM_RMON_CTRL_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_1 Register BM_PCFG_1 - Buffer Manager Port 1 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_1 0x208
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_1 0x18450208u

/*! Register Reset Value */
#define BM_PCFG_1_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_1_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_1_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_1_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_1_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_1 Register BM_RMON_CTRL_1 - Buffer Manager Port 1 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_1 0x20C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_1 0x1845020Cu

/*! Register Reset Value */
#define BM_RMON_CTRL_1_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_1_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_1_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_1_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_1_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_1_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_1_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_1_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_1_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_2 Register BM_PCFG_2 - Buffer Manager Port 2 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_2 0x210
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_2 0x18450210u

/*! Register Reset Value */
#define BM_PCFG_2_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_2_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_2_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_2_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_2_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_2 Register BM_RMON_CTRL_2 - Buffer Manager Port 2 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_2 0x214
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_2 0x18450214u

/*! Register Reset Value */
#define BM_RMON_CTRL_2_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_2_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_2_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_2_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_2_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_2_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_2_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_2_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_2_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_3 Register BM_PCFG_3 - Buffer Manager Port 3 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_3 0x218
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_3 0x18450218u

/*! Register Reset Value */
#define BM_PCFG_3_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_3_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_3_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_3_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_3_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_3 Register BM_RMON_CTRL_3 - Buffer Manager Port 3 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_3 0x21C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_3 0x1845021Cu

/*! Register Reset Value */
#define BM_RMON_CTRL_3_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_3_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_3_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_3_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_3_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_3_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_3_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_3_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_3_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_4 Register BM_PCFG_4 - Buffer Manager Port 4 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_4 0x220
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_4 0x18450220u

/*! Register Reset Value */
#define BM_PCFG_4_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_4_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_4_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_4_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_4_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_4 Register BM_RMON_CTRL_4 - Buffer Manager Port 4 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_4 0x224
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_4 0x18450224u

/*! Register Reset Value */
#define BM_RMON_CTRL_4_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_4_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_4_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_4_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_4_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_4_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_4_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_4_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_4_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_5 Register BM_PCFG_5 - Buffer Manager Port 5 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_5 0x228
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_5 0x18450228u

/*! Register Reset Value */
#define BM_PCFG_5_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_5_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_5_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_5_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_5_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_5 Register BM_RMON_CTRL_5 - Buffer Manager Port 5 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_5 0x22C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_5 0x1845022Cu

/*! Register Reset Value */
#define BM_RMON_CTRL_5_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_5_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_5_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_5_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_5_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_5_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_5_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_5_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_5_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_6 Register BM_PCFG_6 - Buffer Manager Port 6 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_6 0x230
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_6 0x18450230u

/*! Register Reset Value */
#define BM_PCFG_6_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_6_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_6_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_6_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_6_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_6 Register BM_RMON_CTRL_6 - Buffer Manager Port 6 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_6 0x234
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_6 0x18450234u

/*! Register Reset Value */
#define BM_RMON_CTRL_6_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_6_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_6_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_6_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_6_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_6_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_6_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_6_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_6_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_7 Register BM_PCFG_7 - Buffer Manager Port 7 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_7 0x238
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_7 0x18450238u

/*! Register Reset Value */
#define BM_PCFG_7_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_7_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_7_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_7_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_7_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_7 Register BM_RMON_CTRL_7 - Buffer Manager Port 7 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_7 0x23C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_7 0x1845023Cu

/*! Register Reset Value */
#define BM_RMON_CTRL_7_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_7_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_7_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_7_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_7_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_7_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_7_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_7_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_7_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_8 Register BM_PCFG_8 - Buffer Manager Port 8 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_8 0x240
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_8 0x18450240u

/*! Register Reset Value */
#define BM_PCFG_8_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_8_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_8_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_8_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_8_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_8 Register BM_RMON_CTRL_8 - Buffer Manager Port 8 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_8 0x244
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_8 0x18450244u

/*! Register Reset Value */
#define BM_RMON_CTRL_8_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_8_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_8_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_8_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_8_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_8_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_8_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_8_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_8_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_9 Register BM_PCFG_9 - Buffer Manager Port 9 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_9 0x248
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_9 0x18450248u

/*! Register Reset Value */
#define BM_PCFG_9_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_9_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_9_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_9_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_9_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_9 Register BM_RMON_CTRL_9 - Buffer Manager Port 9 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_9 0x24C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_9 0x1845024Cu

/*! Register Reset Value */
#define BM_RMON_CTRL_9_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_9_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_9_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_9_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_9_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_9_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_9_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_9_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_9_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_10 Register BM_PCFG_10 - Buffer Manager Port 10 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_10 0x250
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_10 0x18450250u

/*! Register Reset Value */
#define BM_PCFG_10_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_10_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_10_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_10_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_10_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_10 Register BM_RMON_CTRL_10 - Buffer Manager Port 10 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_10 0x254
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_10 0x18450254u

/*! Register Reset Value */
#define BM_RMON_CTRL_10_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_10_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_10_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_10_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_10_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_10_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_10_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_10_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_10_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PCFG_11 Register BM_PCFG_11 - Buffer Manager Port 11 Configuration Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PCFG_11 0x258
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PCFG_11 0x18450258u

/*! Register Reset Value */
#define BM_PCFG_11_RST 0x00000000u

/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_11_CNTEN_POS 0
/*! Field CNTEN - RMON Counter Enable */
#define BM_PCFG_11_CNTEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_BM_PCFG_11_CNTEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_BM_PCFG_11_CNTEN_EN 0x1

/*! @} */

/*! \defgroup BM_RMON_CTRL_11 Register BM_RMON_CTRL_11 - Buffer Manager Port 11 RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_RMON_CTRL_11 0x25C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_RMON_CTRL_11 0x1845025Cu

/*! Register Reset Value */
#define BM_RMON_CTRL_11_RST 0x00000000u

/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_11_RAM1_RES_POS 0
/*! Field RAM1_RES - Software Reset for CTP RX RMON RAM */
#define BM_RMON_CTRL_11_RAM1_RES_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_11_RAM1_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_11_RAM1_RES_RES 0x1

/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_11_RAM2_RES_POS 1
/*! Field RAM2_RES - Software Reset for CTP TX RMON RAM */
#define BM_RMON_CTRL_11_RAM2_RES_MASK 0x2u
/*! Constant NOP - NOP */
#define CONST_BM_RMON_CTRL_11_RAM2_RES_NOP 0x0
/*! Constant RES - RES */
#define CONST_BM_RMON_CTRL_11_RAM2_RES_RES 0x1

/*! @} */

/*! \defgroup BM_PWRED_RTH_0 Register BM_PWRED_RTH_0 - WRED Port Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0 0x280
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0 0x18450280u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1 Register BM_PWRED_RTH_1 - WRED Port Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1 0x284
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1 0x18450284u

/*! Register Reset Value */
#define BM_PWRED_RTH_1_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0 Register BM_PWRED_YTH_0 - WRED Port Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0 0x288
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0 0x18450288u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1 Register BM_PWRED_YTH_1 - WRED Port Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1 0x28C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1 0x1845028Cu

/*! Register Reset Value */
#define BM_PWRED_YTH_1_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0 Register BM_PWRED_GTH_0 - WRED Port Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0 0x290
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0 0x18450290u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1 Register BM_PWRED_GTH_1 - WRED Port Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1 0x294
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1 0x18450294u

/*! Register Reset Value */
#define BM_PWRED_GTH_1_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_1 Register BM_PWRED_RTH_0_1 - WRED Port 1 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_1 0x298
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_1 0x18450298u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_1_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_1_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_1_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_1 Register BM_PWRED_RTH_1_1 - WRED Port 1 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_1 0x29C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_1 0x1845029Cu

/*! Register Reset Value */
#define BM_PWRED_RTH_1_1_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_1 Register BM_PWRED_YTH_0_1 - WRED Port 1 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_1 0x2A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_1 0x184502A0u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_1_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_1_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_1_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_1 Register BM_PWRED_YTH_1_1 - WRED Port 1 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_1 0x2A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_1 0x184502A4u

/*! Register Reset Value */
#define BM_PWRED_YTH_1_1_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_1 Register BM_PWRED_GTH_0_1 - WRED Port 1 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_1 0x2A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_1 0x184502A8u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_1_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_1_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_1_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_1 Register BM_PWRED_GTH_1_1 - WRED Port 1 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_1 0x2AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_1 0x184502ACu

/*! Register Reset Value */
#define BM_PWRED_GTH_1_1_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_1_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_1_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_2 Register BM_PWRED_RTH_0_2 - WRED Port 2 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_2 0x2B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_2 0x184502B0u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_2_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_2_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_2_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_2 Register BM_PWRED_RTH_1_2 - WRED Port 2 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_2 0x2B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_2 0x184502B4u

/*! Register Reset Value */
#define BM_PWRED_RTH_1_2_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_2_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_2_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_2 Register BM_PWRED_YTH_0_2 - WRED Port 2 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_2 0x2B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_2 0x184502B8u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_2_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_2_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_2_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_2 Register BM_PWRED_YTH_1_2 - WRED Port 2 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_2 0x2BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_2 0x184502BCu

/*! Register Reset Value */
#define BM_PWRED_YTH_1_2_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_2_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_2_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_2 Register BM_PWRED_GTH_0_2 - WRED Port 2 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_2 0x2C0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_2 0x184502C0u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_2_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_2_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_2_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_2 Register BM_PWRED_GTH_1_2 - WRED Port 2 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_2 0x2C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_2 0x184502C4u

/*! Register Reset Value */
#define BM_PWRED_GTH_1_2_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_2_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_2_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_3 Register BM_PWRED_RTH_0_3 - WRED Port 3 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_3 0x2C8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_3 0x184502C8u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_3_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_3_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_3_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_3 Register BM_PWRED_RTH_1_3 - WRED Port 3 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_3 0x2CC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_3 0x184502CCu

/*! Register Reset Value */
#define BM_PWRED_RTH_1_3_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_3_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_3_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_3 Register BM_PWRED_YTH_0_3 - WRED Port 3 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_3 0x2D0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_3 0x184502D0u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_3_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_3_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_3_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_3 Register BM_PWRED_YTH_1_3 - WRED Port 3 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_3 0x2D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_3 0x184502D4u

/*! Register Reset Value */
#define BM_PWRED_YTH_1_3_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_3_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_3_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_3 Register BM_PWRED_GTH_0_3 - WRED Port 3 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_3 0x2D8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_3 0x184502D8u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_3_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_3_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_3_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_3 Register BM_PWRED_GTH_1_3 - WRED Port 3 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_3 0x2DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_3 0x184502DCu

/*! Register Reset Value */
#define BM_PWRED_GTH_1_3_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_3_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_3_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_4 Register BM_PWRED_RTH_0_4 - WRED Port 4 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_4 0x2E0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_4 0x184502E0u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_4_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_4_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_4_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_4 Register BM_PWRED_RTH_1_4 - WRED Port 4 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_4 0x2E4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_4 0x184502E4u

/*! Register Reset Value */
#define BM_PWRED_RTH_1_4_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_4_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_4_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_4 Register BM_PWRED_YTH_0_4 - WRED Port 4 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_4 0x2E8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_4 0x184502E8u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_4_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_4_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_4_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_4 Register BM_PWRED_YTH_1_4 - WRED Port 4 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_4 0x2EC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_4 0x184502ECu

/*! Register Reset Value */
#define BM_PWRED_YTH_1_4_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_4_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_4_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_4 Register BM_PWRED_GTH_0_4 - WRED Port 4 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_4 0x2F0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_4 0x184502F0u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_4_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_4_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_4_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_4 Register BM_PWRED_GTH_1_4 - WRED Port 4 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_4 0x2F4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_4 0x184502F4u

/*! Register Reset Value */
#define BM_PWRED_GTH_1_4_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_4_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_4_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_5 Register BM_PWRED_RTH_0_5 - WRED Port 5 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_5 0x2F8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_5 0x184502F8u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_5_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_5_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_5_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_5 Register BM_PWRED_RTH_1_5 - WRED Port 5 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_5 0x2FC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_5 0x184502FCu

/*! Register Reset Value */
#define BM_PWRED_RTH_1_5_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_5_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_5_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_5 Register BM_PWRED_YTH_0_5 - WRED Port 5 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_5 0x300
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_5 0x18450300u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_5_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_5_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_5_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_5 Register BM_PWRED_YTH_1_5 - WRED Port 5 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_5 0x304
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_5 0x18450304u

/*! Register Reset Value */
#define BM_PWRED_YTH_1_5_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_5_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_5_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_5 Register BM_PWRED_GTH_0_5 - WRED Port 5 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_5 0x308
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_5 0x18450308u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_5_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_5_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_5_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_5 Register BM_PWRED_GTH_1_5 - WRED Port 5 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_5 0x30C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_5 0x1845030Cu

/*! Register Reset Value */
#define BM_PWRED_GTH_1_5_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_5_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_5_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_6 Register BM_PWRED_RTH_0_6 - WRED Port 6 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_6 0x310
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_6 0x18450310u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_6_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_6_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_6_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_6 Register BM_PWRED_RTH_1_6 - WRED Port 6 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_6 0x314
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_6 0x18450314u

/*! Register Reset Value */
#define BM_PWRED_RTH_1_6_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_6_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_6_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_6 Register BM_PWRED_YTH_0_6 - WRED Port 6 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_6 0x318
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_6 0x18450318u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_6_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_6_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_6_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_6 Register BM_PWRED_YTH_1_6 - WRED Port 6 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_6 0x31C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_6 0x1845031Cu

/*! Register Reset Value */
#define BM_PWRED_YTH_1_6_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_6_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_6_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_6 Register BM_PWRED_GTH_0_6 - WRED Port 6 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_6 0x320
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_6 0x18450320u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_6_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_6_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_6_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_6 Register BM_PWRED_GTH_1_6 - WRED Port 6 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_6 0x324
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_6 0x18450324u

/*! Register Reset Value */
#define BM_PWRED_GTH_1_6_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_6_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_6_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_7 Register BM_PWRED_RTH_0_7 - WRED Port 7 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_7 0x328
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_7 0x18450328u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_7_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_7_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_7_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_7 Register BM_PWRED_RTH_1_7 - WRED Port 7 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_7 0x32C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_7 0x1845032Cu

/*! Register Reset Value */
#define BM_PWRED_RTH_1_7_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_7_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_7_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_7 Register BM_PWRED_YTH_0_7 - WRED Port 7 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_7 0x330
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_7 0x18450330u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_7_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_7_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_7_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_7 Register BM_PWRED_YTH_1_7 - WRED Port 7 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_7 0x334
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_7 0x18450334u

/*! Register Reset Value */
#define BM_PWRED_YTH_1_7_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_7_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_7_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_7 Register BM_PWRED_GTH_0_7 - WRED Port 7 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_7 0x338
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_7 0x18450338u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_7_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_7_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_7_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_7 Register BM_PWRED_GTH_1_7 - WRED Port 7 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_7 0x33C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_7 0x1845033Cu

/*! Register Reset Value */
#define BM_PWRED_GTH_1_7_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_7_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_7_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_8 Register BM_PWRED_RTH_0_8 - WRED Port 8 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_8 0x340
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_8 0x18450340u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_8_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_8_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_8_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_8 Register BM_PWRED_RTH_1_8 - WRED Port 8 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_8 0x344
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_8 0x18450344u

/*! Register Reset Value */
#define BM_PWRED_RTH_1_8_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_8_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_8_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_8 Register BM_PWRED_YTH_0_8 - WRED Port 8 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_8 0x348
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_8 0x18450348u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_8_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_8_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_8_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_8 Register BM_PWRED_YTH_1_8 - WRED Port 8 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_8 0x34C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_8 0x1845034Cu

/*! Register Reset Value */
#define BM_PWRED_YTH_1_8_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_8_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_8_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_8 Register BM_PWRED_GTH_0_8 - WRED Port 8 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_8 0x350
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_8 0x18450350u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_8_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_8_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_8_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_8 Register BM_PWRED_GTH_1_8 - WRED Port 8 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_8 0x354
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_8 0x18450354u

/*! Register Reset Value */
#define BM_PWRED_GTH_1_8_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_8_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_8_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_9 Register BM_PWRED_RTH_0_9 - WRED Port 9 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_9 0x358
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_9 0x18450358u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_9_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_9_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_9_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_9 Register BM_PWRED_RTH_1_9 - WRED Port 9 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_9 0x35C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_9 0x1845035Cu

/*! Register Reset Value */
#define BM_PWRED_RTH_1_9_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_9_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_9_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_9 Register BM_PWRED_YTH_0_9 - WRED Port 9 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_9 0x360
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_9 0x18450360u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_9_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_9_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_9_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_9 Register BM_PWRED_YTH_1_9 - WRED Port 9 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_9 0x364
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_9 0x18450364u

/*! Register Reset Value */
#define BM_PWRED_YTH_1_9_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_9_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_9_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_9 Register BM_PWRED_GTH_0_9 - WRED Port 9 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_9 0x368
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_9 0x18450368u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_9_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_9_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_9_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_9 Register BM_PWRED_GTH_1_9 - WRED Port 9 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_9 0x36C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_9 0x1845036Cu

/*! Register Reset Value */
#define BM_PWRED_GTH_1_9_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_9_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_9_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_10 Register BM_PWRED_RTH_0_10 - WRED Port 10 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_10 0x370
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_10 0x18450370u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_10_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_10_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_10_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_10 Register BM_PWRED_RTH_1_10 - WRED Port 10 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_10 0x374
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_10 0x18450374u

/*! Register Reset Value */
#define BM_PWRED_RTH_1_10_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_10_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_10_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_10 Register BM_PWRED_YTH_0_10 - WRED Port 10 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_10 0x378
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_10 0x18450378u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_10_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_10_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_10_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_10 Register BM_PWRED_YTH_1_10 - WRED Port 10 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_10 0x37C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_10 0x1845037Cu

/*! Register Reset Value */
#define BM_PWRED_YTH_1_10_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_10_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_10_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_10 Register BM_PWRED_GTH_0_10 - WRED Port 10 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_10 0x380
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_10 0x18450380u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_10_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_10_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_10_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_10 Register BM_PWRED_GTH_1_10 - WRED Port 10 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_10 0x384
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_10 0x18450384u

/*! Register Reset Value */
#define BM_PWRED_GTH_1_10_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_10_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_10_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_0_11 Register BM_PWRED_RTH_0_11 - WRED Port 11 Red Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_0_11 0x388
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_0_11 0x18450388u

/*! Register Reset Value */
#define BM_PWRED_RTH_0_11_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_11_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_RTH_0_11_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_RTH_1_11 Register BM_PWRED_RTH_1_11 - WRED Port 11 Red Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_RTH_1_11 0x38C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_RTH_1_11 0x1845038Cu

/*! Register Reset Value */
#define BM_PWRED_RTH_1_11_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_11_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_RTH_1_11_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_0_11 Register BM_PWRED_YTH_0_11 - WRED Port 11 Yellow Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_0_11 0x390
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_0_11 0x18450390u

/*! Register Reset Value */
#define BM_PWRED_YTH_0_11_RST 0x00000000u

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_11_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_YTH_0_11_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_YTH_1_11 Register BM_PWRED_YTH_1_11 - WRED Port 11 Yellow Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_YTH_1_11 0x394
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_YTH_1_11 0x18450394u

/*! Register Reset Value */
#define BM_PWRED_YTH_1_11_RST 0x00000000u

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_11_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_YTH_1_11_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_0_11 Register BM_PWRED_GTH_0_11 - WRED Port 11 Green Threshold Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_0_11 0x398
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_0_11 0x18450398u

/*! Register Reset Value */
#define BM_PWRED_GTH_0_11_RST 0x000003FFu

/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_11_MINTH_POS 0
/*! Field MINTH - Minimum Threshold */
#define BM_PWRED_GTH_0_11_MINTH_MASK 0x3FFu

/*! @} */

/*! \defgroup BM_PWRED_GTH_1_11 Register BM_PWRED_GTH_1_11 - WRED Port 11 Green Threshold Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define BM_PWRED_GTH_1_11 0x39C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_PWRED_GTH_1_11 0x1845039Cu

/*! Register Reset Value */
#define BM_PWRED_GTH_1_11_RST 0x000003FFu

/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_11_MAXTH_POS 0
/*! Field MAXTH - Maximum Threshold */
#define BM_PWRED_GTH_1_11_MAXTH_MASK 0x3FFu

/*! @} */

/*! \defgroup PQM_RS Register PQM_RS - Packet Queue Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS 0x404
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS 0x18450404u

/*! Register Reset Value */
#define PQM_RS_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_1 Register PQM_RS_1 - Packet Queue 1 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_1 0x40C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_1 0x1845040Cu

/*! Register Reset Value */
#define PQM_RS_1_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_1_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_1_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_1_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_1_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_1_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_1_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_1_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_1_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_1_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_1_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_1_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_1_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_2 Register PQM_RS_2 - Packet Queue 2 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_2 0x414
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_2 0x18450414u

/*! Register Reset Value */
#define PQM_RS_2_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_2_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_2_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_2_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_2_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_2_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_2_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_2_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_2_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_2_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_2_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_2_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_2_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_3 Register PQM_RS_3 - Packet Queue 3 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_3 0x41C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_3 0x1845041Cu

/*! Register Reset Value */
#define PQM_RS_3_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_3_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_3_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_3_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_3_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_3_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_3_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_3_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_3_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_3_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_3_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_3_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_3_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_4 Register PQM_RS_4 - Packet Queue 4 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_4 0x424
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_4 0x18450424u

/*! Register Reset Value */
#define PQM_RS_4_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_4_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_4_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_4_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_4_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_4_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_4_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_4_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_4_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_4_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_4_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_4_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_4_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_5 Register PQM_RS_5 - Packet Queue 5 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_5 0x42C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_5 0x1845042Cu

/*! Register Reset Value */
#define PQM_RS_5_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_5_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_5_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_5_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_5_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_5_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_5_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_5_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_5_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_5_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_5_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_5_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_5_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_6 Register PQM_RS_6 - Packet Queue 6 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_6 0x434
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_6 0x18450434u

/*! Register Reset Value */
#define PQM_RS_6_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_6_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_6_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_6_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_6_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_6_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_6_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_6_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_6_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_6_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_6_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_6_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_6_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_7 Register PQM_RS_7 - Packet Queue 7 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_7 0x43C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_7 0x1845043Cu

/*! Register Reset Value */
#define PQM_RS_7_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_7_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_7_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_7_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_7_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_7_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_7_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_7_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_7_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_7_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_7_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_7_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_7_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_8 Register PQM_RS_8 - Packet Queue 8 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_8 0x444
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_8 0x18450444u

/*! Register Reset Value */
#define PQM_RS_8_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_8_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_8_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_8_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_8_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_8_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_8_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_8_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_8_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_8_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_8_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_8_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_8_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_9 Register PQM_RS_9 - Packet Queue 9 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_9 0x44C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_9 0x1845044Cu

/*! Register Reset Value */
#define PQM_RS_9_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_9_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_9_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_9_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_9_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_9_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_9_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_9_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_9_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_9_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_9_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_9_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_9_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_10 Register PQM_RS_10 - Packet Queue 10 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_10 0x454
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_10 0x18450454u

/*! Register Reset Value */
#define PQM_RS_10_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_10_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_10_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_10_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_10_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_10_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_10_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_10_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_10_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_10_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_10_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_10_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_10_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_11 Register PQM_RS_11 - Packet Queue 11 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_11 0x45C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_11 0x1845045Cu

/*! Register Reset Value */
#define PQM_RS_11_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_11_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_11_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_11_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_11_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_11_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_11_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_11_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_11_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_11_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_11_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_11_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_11_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_12 Register PQM_RS_12 - Packet Queue 12 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_12 0x464
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_12 0x18450464u

/*! Register Reset Value */
#define PQM_RS_12_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_12_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_12_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_12_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_12_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_12_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_12_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_12_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_12_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_12_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_12_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_12_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_12_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_13 Register PQM_RS_13 - Packet Queue 13 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_13 0x46C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_13 0x1845046Cu

/*! Register Reset Value */
#define PQM_RS_13_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_13_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_13_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_13_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_13_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_13_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_13_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_13_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_13_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_13_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_13_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_13_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_13_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_14 Register PQM_RS_14 - Packet Queue 14 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_14 0x474
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_14 0x18450474u

/*! Register Reset Value */
#define PQM_RS_14_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_14_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_14_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_14_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_14_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_14_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_14_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_14_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_14_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_14_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_14_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_14_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_14_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_15 Register PQM_RS_15 - Packet Queue 15 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_15 0x47C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_15 0x1845047Cu

/*! Register Reset Value */
#define PQM_RS_15_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_15_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_15_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_15_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_15_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_15_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_15_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_15_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_15_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_15_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_15_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_15_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_15_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_16 Register PQM_RS_16 - Packet Queue 16 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_16 0x484
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_16 0x18450484u

/*! Register Reset Value */
#define PQM_RS_16_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_16_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_16_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_16_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_16_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_16_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_16_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_16_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_16_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_16_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_16_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_16_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_16_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_17 Register PQM_RS_17 - Packet Queue 17 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_17 0x48C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_17 0x1845048Cu

/*! Register Reset Value */
#define PQM_RS_17_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_17_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_17_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_17_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_17_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_17_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_17_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_17_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_17_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_17_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_17_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_17_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_17_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_18 Register PQM_RS_18 - Packet Queue 18 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_18 0x494
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_18 0x18450494u

/*! Register Reset Value */
#define PQM_RS_18_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_18_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_18_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_18_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_18_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_18_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_18_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_18_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_18_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_18_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_18_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_18_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_18_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_19 Register PQM_RS_19 - Packet Queue 19 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_19 0x49C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_19 0x1845049Cu

/*! Register Reset Value */
#define PQM_RS_19_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_19_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_19_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_19_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_19_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_19_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_19_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_19_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_19_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_19_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_19_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_19_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_19_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_20 Register PQM_RS_20 - Packet Queue 20 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_20 0x4A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_20 0x184504A4u

/*! Register Reset Value */
#define PQM_RS_20_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_20_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_20_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_20_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_20_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_20_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_20_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_20_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_20_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_20_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_20_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_20_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_20_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_21 Register PQM_RS_21 - Packet Queue 21 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_21 0x4AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_21 0x184504ACu

/*! Register Reset Value */
#define PQM_RS_21_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_21_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_21_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_21_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_21_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_21_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_21_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_21_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_21_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_21_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_21_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_21_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_21_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_22 Register PQM_RS_22 - Packet Queue 22 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_22 0x4B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_22 0x184504B4u

/*! Register Reset Value */
#define PQM_RS_22_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_22_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_22_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_22_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_22_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_22_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_22_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_22_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_22_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_22_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_22_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_22_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_22_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_23 Register PQM_RS_23 - Packet Queue 23 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_23 0x4BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_23 0x184504BCu

/*! Register Reset Value */
#define PQM_RS_23_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_23_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_23_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_23_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_23_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_23_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_23_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_23_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_23_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_23_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_23_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_23_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_23_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_24 Register PQM_RS_24 - Packet Queue 24 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_24 0x4C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_24 0x184504C4u

/*! Register Reset Value */
#define PQM_RS_24_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_24_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_24_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_24_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_24_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_24_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_24_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_24_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_24_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_24_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_24_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_24_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_24_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_25 Register PQM_RS_25 - Packet Queue 25 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_25 0x4CC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_25 0x184504CCu

/*! Register Reset Value */
#define PQM_RS_25_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_25_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_25_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_25_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_25_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_25_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_25_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_25_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_25_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_25_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_25_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_25_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_25_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_26 Register PQM_RS_26 - Packet Queue 26 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_26 0x4D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_26 0x184504D4u

/*! Register Reset Value */
#define PQM_RS_26_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_26_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_26_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_26_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_26_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_26_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_26_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_26_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_26_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_26_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_26_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_26_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_26_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_27 Register PQM_RS_27 - Packet Queue 27 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_27 0x4DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_27 0x184504DCu

/*! Register Reset Value */
#define PQM_RS_27_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_27_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_27_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_27_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_27_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_27_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_27_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_27_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_27_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_27_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_27_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_27_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_27_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_28 Register PQM_RS_28 - Packet Queue 28 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_28 0x4E4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_28 0x184504E4u

/*! Register Reset Value */
#define PQM_RS_28_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_28_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_28_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_28_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_28_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_28_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_28_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_28_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_28_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_28_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_28_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_28_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_28_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_29 Register PQM_RS_29 - Packet Queue 29 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_29 0x4EC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_29 0x184504ECu

/*! Register Reset Value */
#define PQM_RS_29_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_29_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_29_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_29_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_29_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_29_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_29_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_29_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_29_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_29_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_29_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_29_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_29_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_30 Register PQM_RS_30 - Packet Queue 30 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_30 0x4F4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_30 0x184504F4u

/*! Register Reset Value */
#define PQM_RS_30_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_30_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_30_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_30_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_30_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_30_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_30_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_30_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_30_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_30_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_30_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_30_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_30_EN2_EN 0x1

/*! @} */

/*! \defgroup PQM_RS_31 Register PQM_RS_31 - Packet Queue 31 Manager Rate Shaper Assignment Register */
/*! @{ */

/*! Register Offset (relative) */
#define PQM_RS_31 0x4FC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PQM_RS_31 0x184504FCu

/*! Register Reset Value */
#define PQM_RS_31_RST 0x00000000u

/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_31_RS1_POS 0
/*! Field RS1 - Rate Shaper 1 */
#define PQM_RS_31_RS1_MASK 0x1Fu

/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_31_EN1_POS 7
/*! Field EN1 - Rate Shaper 1 Enable */
#define PQM_RS_31_EN1_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_31_EN1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_31_EN1_EN 0x1

/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_31_RS2_POS 8
/*! Field RS2 - Rate Shaper 2 */
#define PQM_RS_31_RS2_MASK 0x1F00u

/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_31_EN2_POS 15
/*! Field EN2 - Rate Shaper 2 Enable */
#define PQM_RS_31_EN2_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PQM_RS_31_EN2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PQM_RS_31_EN2_EN 0x1

/*! @} */

/*! \defgroup RS_CTRL Register RS_CTRL - Rate Shaper Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL 0x500
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL 0x18450500u

/*! Register Reset Value */
#define RS_CTRL_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS Register RS_CBS - Rate Shaper Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS 0x504
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS 0x18450504u

/*! Register Reset Value */
#define RS_CBS_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS Register RS_IBS - Rate Shaper Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS 0x508
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS 0x18450508u

/*! Register Reset Value */
#define RS_IBS_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP Register RS_CIR_EXP - Rate Shaper Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP 0x50C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP 0x1845050Cu

/*! Register Reset Value */
#define RS_CIR_EXP_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT Register RS_CIR_MANT - Rate Shaper Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT 0x510
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT 0x18450510u

/*! Register Reset Value */
#define RS_CIR_MANT_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_1 Register RS_CTRL_1 - Rate Shaper 1 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_1 0x514
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_1 0x18450514u

/*! Register Reset Value */
#define RS_CTRL_1_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_1_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_1_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_1_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_1_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_1_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_1_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_1_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_1_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_1 Register RS_CBS_1 - Rate Shaper 1 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_1 0x518
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_1 0x18450518u

/*! Register Reset Value */
#define RS_CBS_1_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_1_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_1_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_1 Register RS_IBS_1 - Rate Shaper 1 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_1 0x51C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_1 0x1845051Cu

/*! Register Reset Value */
#define RS_IBS_1_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_1_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_1_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_1 Register RS_CIR_EXP_1 - Rate Shaper 1 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_1 0x520
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_1 0x18450520u

/*! Register Reset Value */
#define RS_CIR_EXP_1_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_1_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_1_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_1_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_1_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_1_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_1_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_1_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_1_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_1_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_1_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_1_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_1_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_1_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_1_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_1_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_1_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_1_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_1_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_1 Register RS_CIR_MANT_1 - Rate Shaper 1 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_1 0x524
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_1 0x18450524u

/*! Register Reset Value */
#define RS_CIR_MANT_1_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_1_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_1_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_2 Register RS_CTRL_2 - Rate Shaper 2 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_2 0x528
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_2 0x18450528u

/*! Register Reset Value */
#define RS_CTRL_2_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_2_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_2_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_2_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_2_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_2_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_2_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_2_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_2_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_2 Register RS_CBS_2 - Rate Shaper 2 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_2 0x52C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_2 0x1845052Cu

/*! Register Reset Value */
#define RS_CBS_2_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_2_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_2_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_2 Register RS_IBS_2 - Rate Shaper 2 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_2 0x530
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_2 0x18450530u

/*! Register Reset Value */
#define RS_IBS_2_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_2_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_2_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_2 Register RS_CIR_EXP_2 - Rate Shaper 2 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_2 0x534
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_2 0x18450534u

/*! Register Reset Value */
#define RS_CIR_EXP_2_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_2_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_2_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_2_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_2_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_2_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_2_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_2_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_2_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_2_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_2_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_2_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_2_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_2_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_2_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_2_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_2_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_2_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_2_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_2 Register RS_CIR_MANT_2 - Rate Shaper 2 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_2 0x538
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_2 0x18450538u

/*! Register Reset Value */
#define RS_CIR_MANT_2_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_2_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_2_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_3 Register RS_CTRL_3 - Rate Shaper 3 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_3 0x53C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_3 0x1845053Cu

/*! Register Reset Value */
#define RS_CTRL_3_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_3_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_3_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_3_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_3_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_3_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_3_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_3_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_3_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_3 Register RS_CBS_3 - Rate Shaper 3 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_3 0x540
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_3 0x18450540u

/*! Register Reset Value */
#define RS_CBS_3_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_3_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_3_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_3 Register RS_IBS_3 - Rate Shaper 3 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_3 0x544
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_3 0x18450544u

/*! Register Reset Value */
#define RS_IBS_3_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_3_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_3_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_3 Register RS_CIR_EXP_3 - Rate Shaper 3 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_3 0x548
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_3 0x18450548u

/*! Register Reset Value */
#define RS_CIR_EXP_3_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_3_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_3_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_3_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_3_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_3_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_3_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_3_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_3_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_3_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_3_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_3_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_3_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_3_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_3_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_3_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_3_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_3_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_3_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_3 Register RS_CIR_MANT_3 - Rate Shaper 3 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_3 0x54C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_3 0x1845054Cu

/*! Register Reset Value */
#define RS_CIR_MANT_3_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_3_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_3_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_4 Register RS_CTRL_4 - Rate Shaper 4 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_4 0x550
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_4 0x18450550u

/*! Register Reset Value */
#define RS_CTRL_4_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_4_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_4_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_4_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_4_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_4_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_4_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_4_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_4_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_4 Register RS_CBS_4 - Rate Shaper 4 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_4 0x554
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_4 0x18450554u

/*! Register Reset Value */
#define RS_CBS_4_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_4_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_4_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_4 Register RS_IBS_4 - Rate Shaper 4 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_4 0x558
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_4 0x18450558u

/*! Register Reset Value */
#define RS_IBS_4_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_4_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_4_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_4 Register RS_CIR_EXP_4 - Rate Shaper 4 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_4 0x55C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_4 0x1845055Cu

/*! Register Reset Value */
#define RS_CIR_EXP_4_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_4_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_4_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_4_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_4_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_4_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_4_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_4_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_4_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_4_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_4_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_4_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_4_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_4_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_4_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_4_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_4_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_4_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_4_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_4 Register RS_CIR_MANT_4 - Rate Shaper 4 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_4 0x560
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_4 0x18450560u

/*! Register Reset Value */
#define RS_CIR_MANT_4_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_4_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_4_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_5 Register RS_CTRL_5 - Rate Shaper 5 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_5 0x564
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_5 0x18450564u

/*! Register Reset Value */
#define RS_CTRL_5_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_5_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_5_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_5_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_5_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_5_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_5_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_5_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_5_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_5 Register RS_CBS_5 - Rate Shaper 5 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_5 0x568
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_5 0x18450568u

/*! Register Reset Value */
#define RS_CBS_5_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_5_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_5_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_5 Register RS_IBS_5 - Rate Shaper 5 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_5 0x56C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_5 0x1845056Cu

/*! Register Reset Value */
#define RS_IBS_5_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_5_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_5_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_5 Register RS_CIR_EXP_5 - Rate Shaper 5 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_5 0x570
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_5 0x18450570u

/*! Register Reset Value */
#define RS_CIR_EXP_5_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_5_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_5_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_5_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_5_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_5_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_5_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_5_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_5_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_5_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_5_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_5_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_5_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_5_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_5_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_5_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_5_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_5_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_5_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_5 Register RS_CIR_MANT_5 - Rate Shaper 5 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_5 0x574
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_5 0x18450574u

/*! Register Reset Value */
#define RS_CIR_MANT_5_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_5_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_5_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_6 Register RS_CTRL_6 - Rate Shaper 6 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_6 0x578
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_6 0x18450578u

/*! Register Reset Value */
#define RS_CTRL_6_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_6_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_6_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_6_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_6_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_6_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_6_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_6_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_6_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_6 Register RS_CBS_6 - Rate Shaper 6 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_6 0x57C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_6 0x1845057Cu

/*! Register Reset Value */
#define RS_CBS_6_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_6_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_6_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_6 Register RS_IBS_6 - Rate Shaper 6 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_6 0x580
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_6 0x18450580u

/*! Register Reset Value */
#define RS_IBS_6_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_6_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_6_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_6 Register RS_CIR_EXP_6 - Rate Shaper 6 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_6 0x584
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_6 0x18450584u

/*! Register Reset Value */
#define RS_CIR_EXP_6_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_6_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_6_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_6_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_6_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_6_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_6_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_6_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_6_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_6_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_6_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_6_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_6_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_6_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_6_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_6_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_6_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_6_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_6_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_6 Register RS_CIR_MANT_6 - Rate Shaper 6 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_6 0x588
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_6 0x18450588u

/*! Register Reset Value */
#define RS_CIR_MANT_6_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_6_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_6_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_7 Register RS_CTRL_7 - Rate Shaper 7 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_7 0x58C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_7 0x1845058Cu

/*! Register Reset Value */
#define RS_CTRL_7_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_7_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_7_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_7_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_7_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_7_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_7_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_7_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_7_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_7 Register RS_CBS_7 - Rate Shaper 7 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_7 0x590
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_7 0x18450590u

/*! Register Reset Value */
#define RS_CBS_7_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_7_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_7_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_7 Register RS_IBS_7 - Rate Shaper 7 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_7 0x594
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_7 0x18450594u

/*! Register Reset Value */
#define RS_IBS_7_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_7_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_7_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_7 Register RS_CIR_EXP_7 - Rate Shaper 7 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_7 0x598
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_7 0x18450598u

/*! Register Reset Value */
#define RS_CIR_EXP_7_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_7_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_7_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_7_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_7_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_7_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_7_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_7_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_7_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_7_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_7_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_7_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_7_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_7_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_7_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_7_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_7_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_7_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_7_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_7 Register RS_CIR_MANT_7 - Rate Shaper 7 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_7 0x59C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_7 0x1845059Cu

/*! Register Reset Value */
#define RS_CIR_MANT_7_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_7_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_7_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_8 Register RS_CTRL_8 - Rate Shaper 8 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_8 0x5A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_8 0x184505A0u

/*! Register Reset Value */
#define RS_CTRL_8_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_8_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_8_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_8_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_8_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_8_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_8_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_8_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_8_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_8 Register RS_CBS_8 - Rate Shaper 8 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_8 0x5A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_8 0x184505A4u

/*! Register Reset Value */
#define RS_CBS_8_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_8_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_8_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_8 Register RS_IBS_8 - Rate Shaper 8 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_8 0x5A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_8 0x184505A8u

/*! Register Reset Value */
#define RS_IBS_8_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_8_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_8_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_8 Register RS_CIR_EXP_8 - Rate Shaper 8 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_8 0x5AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_8 0x184505ACu

/*! Register Reset Value */
#define RS_CIR_EXP_8_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_8_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_8_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_8_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_8_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_8_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_8_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_8_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_8_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_8_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_8_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_8_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_8_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_8_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_8_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_8_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_8_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_8_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_8_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_8 Register RS_CIR_MANT_8 - Rate Shaper 8 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_8 0x5B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_8 0x184505B0u

/*! Register Reset Value */
#define RS_CIR_MANT_8_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_8_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_8_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_9 Register RS_CTRL_9 - Rate Shaper 9 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_9 0x5B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_9 0x184505B4u

/*! Register Reset Value */
#define RS_CTRL_9_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_9_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_9_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_9_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_9_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_9_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_9_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_9_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_9_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_9 Register RS_CBS_9 - Rate Shaper 9 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_9 0x5B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_9 0x184505B8u

/*! Register Reset Value */
#define RS_CBS_9_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_9_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_9_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_9 Register RS_IBS_9 - Rate Shaper 9 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_9 0x5BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_9 0x184505BCu

/*! Register Reset Value */
#define RS_IBS_9_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_9_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_9_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_9 Register RS_CIR_EXP_9 - Rate Shaper 9 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_9 0x5C0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_9 0x184505C0u

/*! Register Reset Value */
#define RS_CIR_EXP_9_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_9_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_9_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_9_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_9_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_9_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_9_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_9_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_9_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_9_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_9_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_9_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_9_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_9_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_9_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_9_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_9_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_9_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_9_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_9 Register RS_CIR_MANT_9 - Rate Shaper 9 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_9 0x5C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_9 0x184505C4u

/*! Register Reset Value */
#define RS_CIR_MANT_9_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_9_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_9_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_10 Register RS_CTRL_10 - Rate Shaper 10 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_10 0x5C8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_10 0x184505C8u

/*! Register Reset Value */
#define RS_CTRL_10_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_10_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_10_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_10_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_10_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_10_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_10_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_10_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_10_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_10 Register RS_CBS_10 - Rate Shaper 10 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_10 0x5CC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_10 0x184505CCu

/*! Register Reset Value */
#define RS_CBS_10_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_10_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_10_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_10 Register RS_IBS_10 - Rate Shaper 10 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_10 0x5D0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_10 0x184505D0u

/*! Register Reset Value */
#define RS_IBS_10_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_10_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_10_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_10 Register RS_CIR_EXP_10 - Rate Shaper 10 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_10 0x5D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_10 0x184505D4u

/*! Register Reset Value */
#define RS_CIR_EXP_10_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_10_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_10_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_10_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_10_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_10_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_10_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_10_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_10_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_10_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_10_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_10_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_10_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_10_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_10_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_10_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_10_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_10_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_10_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_10 Register RS_CIR_MANT_10 - Rate Shaper 10 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_10 0x5D8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_10 0x184505D8u

/*! Register Reset Value */
#define RS_CIR_MANT_10_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_10_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_10_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_11 Register RS_CTRL_11 - Rate Shaper 11 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_11 0x5DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_11 0x184505DCu

/*! Register Reset Value */
#define RS_CTRL_11_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_11_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_11_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_11_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_11_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_11_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_11_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_11_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_11_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_11 Register RS_CBS_11 - Rate Shaper 11 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_11 0x5E0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_11 0x184505E0u

/*! Register Reset Value */
#define RS_CBS_11_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_11_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_11_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_11 Register RS_IBS_11 - Rate Shaper 11 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_11 0x5E4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_11 0x184505E4u

/*! Register Reset Value */
#define RS_IBS_11_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_11_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_11_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_11 Register RS_CIR_EXP_11 - Rate Shaper 11 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_11 0x5E8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_11 0x184505E8u

/*! Register Reset Value */
#define RS_CIR_EXP_11_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_11_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_11_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_11_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_11_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_11_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_11_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_11_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_11_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_11_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_11_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_11_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_11_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_11_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_11_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_11_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_11_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_11_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_11_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_11 Register RS_CIR_MANT_11 - Rate Shaper 11 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_11 0x5EC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_11 0x184505ECu

/*! Register Reset Value */
#define RS_CIR_MANT_11_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_11_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_11_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_12 Register RS_CTRL_12 - Rate Shaper 12 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_12 0x5F0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_12 0x184505F0u

/*! Register Reset Value */
#define RS_CTRL_12_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_12_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_12_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_12_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_12_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_12_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_12_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_12_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_12_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_12 Register RS_CBS_12 - Rate Shaper 12 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_12 0x5F4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_12 0x184505F4u

/*! Register Reset Value */
#define RS_CBS_12_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_12_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_12_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_12 Register RS_IBS_12 - Rate Shaper 12 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_12 0x5F8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_12 0x184505F8u

/*! Register Reset Value */
#define RS_IBS_12_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_12_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_12_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_12 Register RS_CIR_EXP_12 - Rate Shaper 12 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_12 0x5FC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_12 0x184505FCu

/*! Register Reset Value */
#define RS_CIR_EXP_12_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_12_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_12_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_12_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_12_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_12_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_12_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_12_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_12_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_12_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_12_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_12_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_12_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_12_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_12_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_12_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_12_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_12_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_12_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_12 Register RS_CIR_MANT_12 - Rate Shaper 12 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_12 0x600
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_12 0x18450600u

/*! Register Reset Value */
#define RS_CIR_MANT_12_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_12_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_12_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_13 Register RS_CTRL_13 - Rate Shaper 13 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_13 0x604
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_13 0x18450604u

/*! Register Reset Value */
#define RS_CTRL_13_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_13_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_13_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_13_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_13_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_13_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_13_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_13_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_13_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_13 Register RS_CBS_13 - Rate Shaper 13 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_13 0x608
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_13 0x18450608u

/*! Register Reset Value */
#define RS_CBS_13_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_13_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_13_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_13 Register RS_IBS_13 - Rate Shaper 13 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_13 0x60C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_13 0x1845060Cu

/*! Register Reset Value */
#define RS_IBS_13_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_13_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_13_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_13 Register RS_CIR_EXP_13 - Rate Shaper 13 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_13 0x610
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_13 0x18450610u

/*! Register Reset Value */
#define RS_CIR_EXP_13_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_13_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_13_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_13_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_13_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_13_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_13_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_13_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_13_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_13_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_13_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_13_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_13_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_13_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_13_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_13_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_13_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_13_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_13_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_13 Register RS_CIR_MANT_13 - Rate Shaper 13 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_13 0x614
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_13 0x18450614u

/*! Register Reset Value */
#define RS_CIR_MANT_13_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_13_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_13_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_14 Register RS_CTRL_14 - Rate Shaper 14 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_14 0x618
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_14 0x18450618u

/*! Register Reset Value */
#define RS_CTRL_14_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_14_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_14_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_14_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_14_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_14_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_14_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_14_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_14_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_14 Register RS_CBS_14 - Rate Shaper 14 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_14 0x61C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_14 0x1845061Cu

/*! Register Reset Value */
#define RS_CBS_14_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_14_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_14_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_14 Register RS_IBS_14 - Rate Shaper 14 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_14 0x620
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_14 0x18450620u

/*! Register Reset Value */
#define RS_IBS_14_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_14_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_14_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_14 Register RS_CIR_EXP_14 - Rate Shaper 14 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_14 0x624
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_14 0x18450624u

/*! Register Reset Value */
#define RS_CIR_EXP_14_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_14_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_14_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_14_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_14_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_14_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_14_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_14_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_14_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_14_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_14_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_14_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_14_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_14_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_14_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_14_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_14_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_14_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_14_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_14 Register RS_CIR_MANT_14 - Rate Shaper 14 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_14 0x628
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_14 0x18450628u

/*! Register Reset Value */
#define RS_CIR_MANT_14_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_14_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_14_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_15 Register RS_CTRL_15 - Rate Shaper 15 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_15 0x62C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_15 0x1845062Cu

/*! Register Reset Value */
#define RS_CTRL_15_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_15_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_15_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_15_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_15_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_15_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_15_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_15_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_15_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_15 Register RS_CBS_15 - Rate Shaper 15 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_15 0x630
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_15 0x18450630u

/*! Register Reset Value */
#define RS_CBS_15_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_15_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_15_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_15 Register RS_IBS_15 - Rate Shaper 15 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_15 0x634
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_15 0x18450634u

/*! Register Reset Value */
#define RS_IBS_15_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_15_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_15_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_15 Register RS_CIR_EXP_15 - Rate Shaper 15 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_15 0x638
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_15 0x18450638u

/*! Register Reset Value */
#define RS_CIR_EXP_15_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_15_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_15_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_15_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_15_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_15_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_15_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_15_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_15_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_15_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_15_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_15_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_15_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_15_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_15_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_15_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_15_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_15_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_15_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_15 Register RS_CIR_MANT_15 - Rate Shaper 15 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_15 0x63C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_15 0x1845063Cu

/*! Register Reset Value */
#define RS_CIR_MANT_15_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_15_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_15_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_16 Register RS_CTRL_16 - Rate Shaper 16 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_16 0x640
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_16 0x18450640u

/*! Register Reset Value */
#define RS_CTRL_16_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_16_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_16_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_16_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_16_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_16_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_16_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_16_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_16_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_16 Register RS_CBS_16 - Rate Shaper 16 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_16 0x644
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_16 0x18450644u

/*! Register Reset Value */
#define RS_CBS_16_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_16_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_16_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_16 Register RS_IBS_16 - Rate Shaper 16 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_16 0x648
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_16 0x18450648u

/*! Register Reset Value */
#define RS_IBS_16_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_16_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_16_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_16 Register RS_CIR_EXP_16 - Rate Shaper 16 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_16 0x64C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_16 0x1845064Cu

/*! Register Reset Value */
#define RS_CIR_EXP_16_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_16_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_16_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_16_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_16_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_16_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_16_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_16_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_16_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_16_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_16_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_16_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_16_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_16_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_16_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_16_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_16_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_16_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_16_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_16 Register RS_CIR_MANT_16 - Rate Shaper 16 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_16 0x650
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_16 0x18450650u

/*! Register Reset Value */
#define RS_CIR_MANT_16_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_16_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_16_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_17 Register RS_CTRL_17 - Rate Shaper 17 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_17 0x654
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_17 0x18450654u

/*! Register Reset Value */
#define RS_CTRL_17_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_17_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_17_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_17_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_17_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_17_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_17_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_17_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_17_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_17 Register RS_CBS_17 - Rate Shaper 17 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_17 0x658
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_17 0x18450658u

/*! Register Reset Value */
#define RS_CBS_17_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_17_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_17_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_17 Register RS_IBS_17 - Rate Shaper 17 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_17 0x65C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_17 0x1845065Cu

/*! Register Reset Value */
#define RS_IBS_17_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_17_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_17_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_17 Register RS_CIR_EXP_17 - Rate Shaper 17 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_17 0x660
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_17 0x18450660u

/*! Register Reset Value */
#define RS_CIR_EXP_17_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_17_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_17_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_17_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_17_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_17_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_17_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_17_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_17_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_17_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_17_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_17_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_17_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_17_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_17_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_17_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_17_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_17_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_17_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_17 Register RS_CIR_MANT_17 - Rate Shaper 17 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_17 0x664
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_17 0x18450664u

/*! Register Reset Value */
#define RS_CIR_MANT_17_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_17_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_17_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_18 Register RS_CTRL_18 - Rate Shaper 18 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_18 0x668
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_18 0x18450668u

/*! Register Reset Value */
#define RS_CTRL_18_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_18_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_18_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_18_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_18_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_18_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_18_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_18_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_18_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_18 Register RS_CBS_18 - Rate Shaper 18 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_18 0x66C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_18 0x1845066Cu

/*! Register Reset Value */
#define RS_CBS_18_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_18_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_18_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_18 Register RS_IBS_18 - Rate Shaper 18 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_18 0x670
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_18 0x18450670u

/*! Register Reset Value */
#define RS_IBS_18_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_18_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_18_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_18 Register RS_CIR_EXP_18 - Rate Shaper 18 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_18 0x674
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_18 0x18450674u

/*! Register Reset Value */
#define RS_CIR_EXP_18_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_18_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_18_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_18_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_18_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_18_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_18_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_18_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_18_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_18_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_18_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_18_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_18_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_18_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_18_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_18_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_18_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_18_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_18_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_18 Register RS_CIR_MANT_18 - Rate Shaper 18 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_18 0x678
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_18 0x18450678u

/*! Register Reset Value */
#define RS_CIR_MANT_18_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_18_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_18_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_19 Register RS_CTRL_19 - Rate Shaper 19 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_19 0x67C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_19 0x1845067Cu

/*! Register Reset Value */
#define RS_CTRL_19_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_19_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_19_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_19_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_19_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_19_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_19_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_19_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_19_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_19 Register RS_CBS_19 - Rate Shaper 19 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_19 0x680
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_19 0x18450680u

/*! Register Reset Value */
#define RS_CBS_19_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_19_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_19_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_19 Register RS_IBS_19 - Rate Shaper 19 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_19 0x684
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_19 0x18450684u

/*! Register Reset Value */
#define RS_IBS_19_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_19_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_19_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_19 Register RS_CIR_EXP_19 - Rate Shaper 19 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_19 0x688
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_19 0x18450688u

/*! Register Reset Value */
#define RS_CIR_EXP_19_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_19_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_19_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_19_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_19_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_19_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_19_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_19_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_19_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_19_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_19_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_19_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_19_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_19_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_19_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_19_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_19_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_19_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_19_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_19 Register RS_CIR_MANT_19 - Rate Shaper 19 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_19 0x68C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_19 0x1845068Cu

/*! Register Reset Value */
#define RS_CIR_MANT_19_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_19_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_19_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_20 Register RS_CTRL_20 - Rate Shaper 20 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_20 0x690
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_20 0x18450690u

/*! Register Reset Value */
#define RS_CTRL_20_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_20_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_20_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_20_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_20_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_20_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_20_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_20_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_20_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_20 Register RS_CBS_20 - Rate Shaper 20 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_20 0x694
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_20 0x18450694u

/*! Register Reset Value */
#define RS_CBS_20_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_20_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_20_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_20 Register RS_IBS_20 - Rate Shaper 20 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_20 0x698
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_20 0x18450698u

/*! Register Reset Value */
#define RS_IBS_20_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_20_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_20_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_20 Register RS_CIR_EXP_20 - Rate Shaper 20 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_20 0x69C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_20 0x1845069Cu

/*! Register Reset Value */
#define RS_CIR_EXP_20_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_20_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_20_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_20_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_20_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_20_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_20_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_20_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_20_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_20_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_20_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_20_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_20_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_20_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_20_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_20_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_20_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_20_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_20_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_20 Register RS_CIR_MANT_20 - Rate Shaper 20 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_20 0x6A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_20 0x184506A0u

/*! Register Reset Value */
#define RS_CIR_MANT_20_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_20_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_20_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_21 Register RS_CTRL_21 - Rate Shaper 21 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_21 0x6A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_21 0x184506A4u

/*! Register Reset Value */
#define RS_CTRL_21_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_21_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_21_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_21_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_21_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_21_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_21_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_21_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_21_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_21 Register RS_CBS_21 - Rate Shaper 21 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_21 0x6A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_21 0x184506A8u

/*! Register Reset Value */
#define RS_CBS_21_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_21_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_21_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_21 Register RS_IBS_21 - Rate Shaper 21 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_21 0x6AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_21 0x184506ACu

/*! Register Reset Value */
#define RS_IBS_21_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_21_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_21_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_21 Register RS_CIR_EXP_21 - Rate Shaper 21 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_21 0x6B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_21 0x184506B0u

/*! Register Reset Value */
#define RS_CIR_EXP_21_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_21_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_21_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_21_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_21_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_21_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_21_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_21_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_21_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_21_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_21_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_21_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_21_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_21_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_21_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_21_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_21_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_21_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_21_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_21 Register RS_CIR_MANT_21 - Rate Shaper 21 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_21 0x6B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_21 0x184506B4u

/*! Register Reset Value */
#define RS_CIR_MANT_21_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_21_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_21_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_22 Register RS_CTRL_22 - Rate Shaper 22 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_22 0x6B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_22 0x184506B8u

/*! Register Reset Value */
#define RS_CTRL_22_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_22_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_22_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_22_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_22_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_22_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_22_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_22_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_22_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_22 Register RS_CBS_22 - Rate Shaper 22 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_22 0x6BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_22 0x184506BCu

/*! Register Reset Value */
#define RS_CBS_22_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_22_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_22_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_22 Register RS_IBS_22 - Rate Shaper 22 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_22 0x6C0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_22 0x184506C0u

/*! Register Reset Value */
#define RS_IBS_22_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_22_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_22_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_22 Register RS_CIR_EXP_22 - Rate Shaper 22 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_22 0x6C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_22 0x184506C4u

/*! Register Reset Value */
#define RS_CIR_EXP_22_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_22_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_22_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_22_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_22_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_22_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_22_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_22_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_22_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_22_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_22_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_22_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_22_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_22_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_22_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_22_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_22_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_22_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_22_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_22 Register RS_CIR_MANT_22 - Rate Shaper 22 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_22 0x6C8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_22 0x184506C8u

/*! Register Reset Value */
#define RS_CIR_MANT_22_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_22_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_22_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_23 Register RS_CTRL_23 - Rate Shaper 23 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_23 0x6CC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_23 0x184506CCu

/*! Register Reset Value */
#define RS_CTRL_23_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_23_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_23_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_23_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_23_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_23_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_23_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_23_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_23_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_23 Register RS_CBS_23 - Rate Shaper 23 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_23 0x6D0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_23 0x184506D0u

/*! Register Reset Value */
#define RS_CBS_23_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_23_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_23_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_23 Register RS_IBS_23 - Rate Shaper 23 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_23 0x6D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_23 0x184506D4u

/*! Register Reset Value */
#define RS_IBS_23_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_23_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_23_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_23 Register RS_CIR_EXP_23 - Rate Shaper 23 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_23 0x6D8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_23 0x184506D8u

/*! Register Reset Value */
#define RS_CIR_EXP_23_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_23_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_23_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_23_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_23_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_23_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_23_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_23_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_23_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_23_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_23_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_23_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_23_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_23_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_23_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_23_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_23_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_23_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_23_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_23 Register RS_CIR_MANT_23 - Rate Shaper 23 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_23 0x6DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_23 0x184506DCu

/*! Register Reset Value */
#define RS_CIR_MANT_23_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_23_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_23_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_24 Register RS_CTRL_24 - Rate Shaper 24 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_24 0x6E0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_24 0x184506E0u

/*! Register Reset Value */
#define RS_CTRL_24_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_24_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_24_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_24_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_24_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_24_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_24_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_24_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_24_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_24 Register RS_CBS_24 - Rate Shaper 24 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_24 0x6E4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_24 0x184506E4u

/*! Register Reset Value */
#define RS_CBS_24_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_24_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_24_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_24 Register RS_IBS_24 - Rate Shaper 24 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_24 0x6E8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_24 0x184506E8u

/*! Register Reset Value */
#define RS_IBS_24_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_24_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_24_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_24 Register RS_CIR_EXP_24 - Rate Shaper 24 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_24 0x6EC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_24 0x184506ECu

/*! Register Reset Value */
#define RS_CIR_EXP_24_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_24_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_24_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_24_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_24_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_24_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_24_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_24_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_24_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_24_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_24_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_24_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_24_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_24_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_24_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_24_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_24_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_24_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_24_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_24 Register RS_CIR_MANT_24 - Rate Shaper 24 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_24 0x6F0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_24 0x184506F0u

/*! Register Reset Value */
#define RS_CIR_MANT_24_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_24_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_24_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_25 Register RS_CTRL_25 - Rate Shaper 25 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_25 0x6F4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_25 0x184506F4u

/*! Register Reset Value */
#define RS_CTRL_25_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_25_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_25_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_25_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_25_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_25_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_25_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_25_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_25_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_25 Register RS_CBS_25 - Rate Shaper 25 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_25 0x6F8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_25 0x184506F8u

/*! Register Reset Value */
#define RS_CBS_25_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_25_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_25_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_25 Register RS_IBS_25 - Rate Shaper 25 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_25 0x6FC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_25 0x184506FCu

/*! Register Reset Value */
#define RS_IBS_25_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_25_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_25_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_25 Register RS_CIR_EXP_25 - Rate Shaper 25 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_25 0x700
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_25 0x18450700u

/*! Register Reset Value */
#define RS_CIR_EXP_25_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_25_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_25_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_25_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_25_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_25_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_25_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_25_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_25_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_25_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_25_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_25_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_25_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_25_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_25_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_25_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_25_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_25_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_25_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_25 Register RS_CIR_MANT_25 - Rate Shaper 25 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_25 0x704
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_25 0x18450704u

/*! Register Reset Value */
#define RS_CIR_MANT_25_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_25_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_25_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_26 Register RS_CTRL_26 - Rate Shaper 26 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_26 0x708
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_26 0x18450708u

/*! Register Reset Value */
#define RS_CTRL_26_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_26_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_26_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_26_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_26_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_26_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_26_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_26_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_26_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_26 Register RS_CBS_26 - Rate Shaper 26 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_26 0x70C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_26 0x1845070Cu

/*! Register Reset Value */
#define RS_CBS_26_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_26_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_26_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_26 Register RS_IBS_26 - Rate Shaper 26 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_26 0x710
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_26 0x18450710u

/*! Register Reset Value */
#define RS_IBS_26_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_26_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_26_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_26 Register RS_CIR_EXP_26 - Rate Shaper 26 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_26 0x714
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_26 0x18450714u

/*! Register Reset Value */
#define RS_CIR_EXP_26_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_26_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_26_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_26_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_26_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_26_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_26_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_26_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_26_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_26_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_26_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_26_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_26_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_26_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_26_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_26_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_26_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_26_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_26_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_26 Register RS_CIR_MANT_26 - Rate Shaper 26 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_26 0x718
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_26 0x18450718u

/*! Register Reset Value */
#define RS_CIR_MANT_26_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_26_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_26_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_27 Register RS_CTRL_27 - Rate Shaper 27 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_27 0x71C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_27 0x1845071Cu

/*! Register Reset Value */
#define RS_CTRL_27_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_27_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_27_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_27_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_27_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_27_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_27_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_27_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_27_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_27 Register RS_CBS_27 - Rate Shaper 27 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_27 0x720
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_27 0x18450720u

/*! Register Reset Value */
#define RS_CBS_27_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_27_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_27_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_27 Register RS_IBS_27 - Rate Shaper 27 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_27 0x724
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_27 0x18450724u

/*! Register Reset Value */
#define RS_IBS_27_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_27_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_27_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_27 Register RS_CIR_EXP_27 - Rate Shaper 27 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_27 0x728
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_27 0x18450728u

/*! Register Reset Value */
#define RS_CIR_EXP_27_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_27_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_27_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_27_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_27_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_27_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_27_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_27_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_27_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_27_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_27_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_27_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_27_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_27_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_27_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_27_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_27_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_27_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_27_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_27 Register RS_CIR_MANT_27 - Rate Shaper 27 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_27 0x72C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_27 0x1845072Cu

/*! Register Reset Value */
#define RS_CIR_MANT_27_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_27_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_27_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_28 Register RS_CTRL_28 - Rate Shaper 28 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_28 0x730
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_28 0x18450730u

/*! Register Reset Value */
#define RS_CTRL_28_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_28_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_28_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_28_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_28_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_28_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_28_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_28_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_28_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_28 Register RS_CBS_28 - Rate Shaper 28 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_28 0x734
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_28 0x18450734u

/*! Register Reset Value */
#define RS_CBS_28_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_28_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_28_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_28 Register RS_IBS_28 - Rate Shaper 28 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_28 0x738
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_28 0x18450738u

/*! Register Reset Value */
#define RS_IBS_28_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_28_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_28_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_28 Register RS_CIR_EXP_28 - Rate Shaper 28 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_28 0x73C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_28 0x1845073Cu

/*! Register Reset Value */
#define RS_CIR_EXP_28_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_28_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_28_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_28_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_28_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_28_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_28_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_28_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_28_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_28_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_28_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_28_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_28_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_28_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_28_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_28_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_28_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_28_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_28_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_28 Register RS_CIR_MANT_28 - Rate Shaper 28 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_28 0x740
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_28 0x18450740u

/*! Register Reset Value */
#define RS_CIR_MANT_28_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_28_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_28_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_29 Register RS_CTRL_29 - Rate Shaper 29 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_29 0x744
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_29 0x18450744u

/*! Register Reset Value */
#define RS_CTRL_29_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_29_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_29_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_29_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_29_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_29_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_29_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_29_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_29_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_29 Register RS_CBS_29 - Rate Shaper 29 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_29 0x748
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_29 0x18450748u

/*! Register Reset Value */
#define RS_CBS_29_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_29_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_29_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_29 Register RS_IBS_29 - Rate Shaper 29 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_29 0x74C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_29 0x1845074Cu

/*! Register Reset Value */
#define RS_IBS_29_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_29_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_29_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_29 Register RS_CIR_EXP_29 - Rate Shaper 29 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_29 0x750
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_29 0x18450750u

/*! Register Reset Value */
#define RS_CIR_EXP_29_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_29_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_29_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_29_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_29_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_29_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_29_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_29_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_29_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_29_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_29_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_29_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_29_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_29_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_29_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_29_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_29_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_29_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_29_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_29 Register RS_CIR_MANT_29 - Rate Shaper 29 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_29 0x754
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_29 0x18450754u

/*! Register Reset Value */
#define RS_CIR_MANT_29_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_29_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_29_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_30 Register RS_CTRL_30 - Rate Shaper 30 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_30 0x758
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_30 0x18450758u

/*! Register Reset Value */
#define RS_CTRL_30_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_30_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_30_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_30_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_30_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_30_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_30_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_30_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_30_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_30 Register RS_CBS_30 - Rate Shaper 30 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_30 0x75C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_30 0x1845075Cu

/*! Register Reset Value */
#define RS_CBS_30_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_30_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_30_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_30 Register RS_IBS_30 - Rate Shaper 30 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_30 0x760
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_30 0x18450760u

/*! Register Reset Value */
#define RS_IBS_30_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_30_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_30_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_30 Register RS_CIR_EXP_30 - Rate Shaper 30 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_30 0x764
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_30 0x18450764u

/*! Register Reset Value */
#define RS_CIR_EXP_30_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_30_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_30_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_30_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_30_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_30_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_30_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_30_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_30_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_30_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_30_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_30_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_30_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_30_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_30_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_30_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_30_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_30_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_30_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_30 Register RS_CIR_MANT_30 - Rate Shaper 30 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_30 0x768
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_30 0x18450768u

/*! Register Reset Value */
#define RS_CIR_MANT_30_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_30_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_30_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CTRL_31 Register RS_CTRL_31 - Rate Shaper 31 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CTRL_31 0x76C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CTRL_31 0x1845076Cu

/*! Register Reset Value */
#define RS_CTRL_31_RST 0x00000000u

/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_31_RSEN_POS 0
/*! Field RSEN - Rate Shaper Enable */
#define RS_CTRL_31_RSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_RS_CTRL_31_RSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_RS_CTRL_31_RSEN_EN 0x1

/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_31_RSMOD_POS 1
/*! Field RSMOD - Rate Shaper Mode */
#define RS_CTRL_31_RSMOD_MASK 0x2u
/*! Constant TOKEN - Token */
#define CONST_RS_CTRL_31_RSMOD_TOKEN 0x0
/*! Constant CRS - CRS */
#define CONST_RS_CTRL_31_RSMOD_CRS 0x1

/*! @} */

/*! \defgroup RS_CBS_31 Register RS_CBS_31 - Rate Shaper 31 Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CBS_31 0x770
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CBS_31 0x18450770u

/*! Register Reset Value */
#define RS_CBS_31_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define RS_CBS_31_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define RS_CBS_31_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_IBS_31 Register RS_IBS_31 - Rate Shaper 31 Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_IBS_31 0x774
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_IBS_31 0x18450774u

/*! Register Reset Value */
#define RS_IBS_31_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_31_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define RS_IBS_31_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup RS_CIR_EXP_31 Register RS_CIR_EXP_31 - Rate Shaper 31 Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_EXP_31 0x778
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_EXP_31 0x18450778u

/*! Register Reset Value */
#define RS_CIR_EXP_31_RST 0x00000000u

/*! Field EXP - Exponent */
#define RS_CIR_EXP_31_EXP_POS 0
/*! Field EXP - Exponent */
#define RS_CIR_EXP_31_EXP_MASK 0xFu
/*! Constant E2P0 - E2P0 */
#define CONST_RS_CIR_EXP_31_EXP_E2P0 0x0
/*! Constant E2P1 - E2P1 */
#define CONST_RS_CIR_EXP_31_EXP_E2P1 0x1
/*! Constant E2P2 - E2P2 */
#define CONST_RS_CIR_EXP_31_EXP_E2P2 0x2
/*! Constant E2P3 - E2P3 */
#define CONST_RS_CIR_EXP_31_EXP_E2P3 0x3
/*! Constant E2P4 - E2P4 */
#define CONST_RS_CIR_EXP_31_EXP_E2P4 0x4
/*! Constant E2P5 - E2P5 */
#define CONST_RS_CIR_EXP_31_EXP_E2P5 0x5
/*! Constant E2P6 - E2P6 */
#define CONST_RS_CIR_EXP_31_EXP_E2P6 0x6
/*! Constant E2P7 - E2P7 */
#define CONST_RS_CIR_EXP_31_EXP_E2P7 0x7
/*! Constant E2P8 - E2P8 */
#define CONST_RS_CIR_EXP_31_EXP_E2P8 0x8
/*! Constant E2P9 - E2P9 */
#define CONST_RS_CIR_EXP_31_EXP_E2P9 0x9
/*! Constant E2P10 - E2P10 */
#define CONST_RS_CIR_EXP_31_EXP_E2P10 0xA
/*! Constant E2P11 - E2P11 */
#define CONST_RS_CIR_EXP_31_EXP_E2P11 0xB
/*! Constant E2P12 - E2P12 */
#define CONST_RS_CIR_EXP_31_EXP_E2P12 0xC
/*! Constant E2P13 - E2P13 */
#define CONST_RS_CIR_EXP_31_EXP_E2P13 0xD
/*! Constant E2P14 - E2P14 */
#define CONST_RS_CIR_EXP_31_EXP_E2P14 0xE
/*! Constant E2P15 - E2P15 */
#define CONST_RS_CIR_EXP_31_EXP_E2P15 0xF

/*! @} */

/*! \defgroup RS_CIR_MANT_31 Register RS_CIR_MANT_31 - Rate Shaper 31 Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define RS_CIR_MANT_31 0x77C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_RS_CIR_MANT_31 0x1845077Cu

/*! Register Reset Value */
#define RS_CIR_MANT_31_RST 0x00000000u

/*! Field MANT - Mantissa */
#define RS_CIR_MANT_31_MANT_POS 0
/*! Field MANT - Mantissa */
#define RS_CIR_MANT_31_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup PCE_DA_FILTER_0 Register PCE_DA_FILTER_0 - PCE Default DA Filter Port Map 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_0 0xF80
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_0 0x18450F80u

/*! Register Reset Value */
#define PCE_DA_FILTER_0_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_0_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_0_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_0_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_0_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_DA_FILTER_1 Register PCE_DA_FILTER_1 - PCE Default DA Filter Port Member 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_1 0xF84
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_1 0x18450F84u

/*! Register Reset Value */
#define PCE_DA_FILTER_1_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_1_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_1_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_1_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_1_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_DA_FILTER_2 Register PCE_DA_FILTER_2 - PCE Default DA Filter Port Member 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_2 0xF88
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_2 0x18450F88u

/*! Register Reset Value */
#define PCE_DA_FILTER_2_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_2_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_2_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_2_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_2_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_DA_FILTER_3 Register PCE_DA_FILTER_3 - PCE Default DA Filter Port Member 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_3 0xF8C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_3 0x18450F8Cu

/*! Register Reset Value */
#define PCE_DA_FILTER_3_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_3_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_3_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_3_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_3_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_DA_FILTER_4 Register PCE_DA_FILTER_4 - PCE Default DA Filter Port Member 4 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_4 0xF90
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_4 0x18450F90u

/*! Register Reset Value */
#define PCE_DA_FILTER_4_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_4_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_4_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_4_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_4_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_DA_FILTER_5 Register PCE_DA_FILTER_5 - PCE Default DA Filter Port Member 5 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_5 0xF94
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_5 0x18450F94u

/*! Register Reset Value */
#define PCE_DA_FILTER_5_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_5_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_5_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_5_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_5_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_DA_FILTER_6 Register PCE_DA_FILTER_6 - PCE Default DA Filter Port Member 6 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_6 0xF98
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_6 0x18450F98u

/*! Register Reset Value */
#define PCE_DA_FILTER_6_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_6_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_6_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_6_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_6_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_DA_FILTER_7 Register PCE_DA_FILTER_7 - PCE Default DA Filter Port Member 7 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DA_FILTER_7 0xF9C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DA_FILTER_7 0x18450F9Cu

/*! Register Reset Value */
#define PCE_DA_FILTER_7_RST 0x0000FFFFu

/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_7_PM_POS 0
/*! Field PM - Default DA filter port member bit 15 to 0 */
#define PCE_DA_FILTER_7_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_DA_FILTER_7_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_DA_FILTER_7_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_0 Register PCE_SA_FILTER_0 - PCE Default SA Filter Port Member 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_0 0xFC0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_0 0x18450FC0u

/*! Register Reset Value */
#define PCE_SA_FILTER_0_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_0_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_0_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_0_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_0_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_1 Register PCE_SA_FILTER_1 - PCE Default SA Filter Port Member 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_1 0xFC4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_1 0x18450FC4u

/*! Register Reset Value */
#define PCE_SA_FILTER_1_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_1_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_1_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_1_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_1_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_2 Register PCE_SA_FILTER_2 - PCE Default SA Filter Port Member 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_2 0xFC8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_2 0x18450FC8u

/*! Register Reset Value */
#define PCE_SA_FILTER_2_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_2_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_2_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_2_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_2_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_3 Register PCE_SA_FILTER_3 - PCE Default SA Filter Port Member 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_3 0xFCC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_3 0x18450FCCu

/*! Register Reset Value */
#define PCE_SA_FILTER_3_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_3_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_3_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_3_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_3_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_4 Register PCE_SA_FILTER_4 - PCE Default SA Filter Port Member 4 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_4 0xFD0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_4 0x18450FD0u

/*! Register Reset Value */
#define PCE_SA_FILTER_4_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_4_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_4_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_4_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_4_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_5 Register PCE_SA_FILTER_5 - PCE Default SA Filter Port Member 5 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_5 0xFD4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_5 0x18450FD4u

/*! Register Reset Value */
#define PCE_SA_FILTER_5_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_5_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_5_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_5_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_5_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_6 Register PCE_SA_FILTER_6 - PCE Default SA Filter Port Member 6 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_6 0xFD8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_6 0x18450FD8u

/*! Register Reset Value */
#define PCE_SA_FILTER_6_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_6_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_6_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_6_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_6_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_SA_FILTER_7 Register PCE_SA_FILTER_7 - PCE Default SA Filter Port Member 7 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_SA_FILTER_7 0xFDC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_SA_FILTER_7 0x18450FDCu

/*! Register Reset Value */
#define PCE_SA_FILTER_7_RST 0x0000FFFFu

/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_7_PM_POS 0
/*! Field PM - Default SA filter port member bit 15 to 0 */
#define PCE_SA_FILTER_7_PM_MASK 0xFFFFu
/*! Constant BLOCK - Block */
#define CONST_PCE_SA_FILTER_7_PM_BLOCK 0x0000u
/*! Constant FWD - FWD */
#define CONST_PCE_SA_FILTER_7_PM_FWD 0x0001u

/*! @} */

/*! \defgroup PCE_INS_CTRL Register PCE_INS_CTRL - PCE Insertion Control */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_INS_CTRL 0x1000
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_INS_CTRL 0x18451000u

/*! Register Reset Value */
#define PCE_INS_CTRL_RST 0x00000000u

/*! Field INS0 - Counting Enable at Insertion Point 0 */
#define PCE_INS_CTRL_INS0_POS 0
/*! Field INS0 - Counting Enable at Insertion Point 0 */
#define PCE_INS_CTRL_INS0_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_INS_CTRL_INS0_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_INS_CTRL_INS0_EN 0x1

/*! Field INS1 - Counting Enable at Insertion Point 1 */
#define PCE_INS_CTRL_INS1_POS 1
/*! Field INS1 - Counting Enable at Insertion Point 1 */
#define PCE_INS_CTRL_INS1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_INS_CTRL_INS1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_INS_CTRL_INS1_EN 0x1

/*! Field INS2 - Counting Enable at Insertion Point 2 */
#define PCE_INS_CTRL_INS2_POS 2
/*! Field INS2 - Counting Enable at Insertion Point 2 */
#define PCE_INS_CTRL_INS2_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_INS_CTRL_INS2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_INS_CTRL_INS2_EN 0x1

/*! Field INS3 - Counting Enable at Insertion Point 3 */
#define PCE_INS_CTRL_INS3_POS 3
/*! Field INS3 - Counting Enable at Insertion Point 3 */
#define PCE_INS_CTRL_INS3_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_INS_CTRL_INS3_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_INS_CTRL_INS3_EN 0x1

/*! @} */

/*! \defgroup PCE_TBL_KEY_21 Register PCE_TBL_KEY_21 - Table Key Data 21 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_21 0x1068
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_21 0x18451068u

/*! Register Reset Value */
#define PCE_TBL_KEY_21_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_21_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_21_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_20 Register PCE_TBL_KEY_20 - Table Key Data 20 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_20 0x106C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_20 0x1845106Cu

/*! Register Reset Value */
#define PCE_TBL_KEY_20_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_20_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_20_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_19 Register PCE_TBL_KEY_19 - Table Key Data 19 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_19 0x1070
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_19 0x18451070u

/*! Register Reset Value */
#define PCE_TBL_KEY_19_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_19_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_19_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_18 Register PCE_TBL_KEY_18 - Table Key Data 18 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_18 0x1074
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_18 0x18451074u

/*! Register Reset Value */
#define PCE_TBL_KEY_18_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_18_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_18_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_17 Register PCE_TBL_KEY_17 - Table Key Data 17 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_17 0x1078
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_17 0x18451078u

/*! Register Reset Value */
#define PCE_TBL_KEY_17_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_17_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_17_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_16 Register PCE_TBL_KEY_16 - Table Key Data 16 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_16 0x107C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_16 0x1845107Cu

/*! Register Reset Value */
#define PCE_TBL_KEY_16_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_16_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_16_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_25 Register PCE_TBL_VAL_25 - Table Value Register 25 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_25 0x1080
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_25 0x18451080u

/*! Register Reset Value */
#define PCE_TBL_VAL_25_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_25_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_25_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_24 Register PCE_TBL_VAL_24 - Table Value Register 24 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_24 0x1084
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_24 0x18451084u

/*! Register Reset Value */
#define PCE_TBL_VAL_24_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_24_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_24_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_23 Register PCE_TBL_VAL_23 - Table Value Register 23 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_23 0x1088
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_23 0x18451088u

/*! Register Reset Value */
#define PCE_TBL_VAL_23_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_23_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_23_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_22 Register PCE_TBL_VAL_22 - Table Value Register 22 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_22 0x108C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_22 0x1845108Cu

/*! Register Reset Value */
#define PCE_TBL_VAL_22_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_22_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_22_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_21 Register PCE_TBL_VAL_21 - Table Value Register 21 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_21 0x1090
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_21 0x18451090u

/*! Register Reset Value */
#define PCE_TBL_VAL_21_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_21_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_21_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_20 Register PCE_TBL_VAL_20 - Table Value Register 20 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_20 0x1094
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_20 0x18451094u

/*! Register Reset Value */
#define PCE_TBL_VAL_20_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_20_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_20_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_19 Register PCE_TBL_VAL_19 - Table Value Register 19 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_19 0x1098
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_19 0x18451098u

/*! Register Reset Value */
#define PCE_TBL_VAL_19_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_19_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_19_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_18 Register PCE_TBL_VAL_18 - Table Value Register 18 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_18 0x109C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_18 0x1845109Cu

/*! Register Reset Value */
#define PCE_TBL_VAL_18_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_18_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_18_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_17 Register PCE_TBL_VAL_17 - Table Value Register 17 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_17 0x10A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_17 0x184510A0u

/*! Register Reset Value */
#define PCE_TBL_VAL_17_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_17_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_17_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_16 Register PCE_TBL_VAL_16 - Table Value Register 16 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_16 0x10A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_16 0x184510A4u

/*! Register Reset Value */
#define PCE_TBL_VAL_16_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_16_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_16_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_MASK_3 Register PCE_TBL_MASK_3 - Table Mask Data 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_MASK_3 0x10A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_MASK_3 0x184510A8u

/*! Register Reset Value */
#define PCE_TBL_MASK_3_RST 0x00000000u

/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_3_MASK0_POS 0
/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_3_MASK0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_MASK_2 Register PCE_TBL_MASK_2 - Table Mask Data 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_MASK_2 0x10AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_MASK_2 0x184510ACu

/*! Register Reset Value */
#define PCE_TBL_MASK_2_RST 0x00000000u

/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_2_MASK0_POS 0
/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_2_MASK0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_MASK_1 Register PCE_TBL_MASK_1 - Table Mask Data 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_MASK_1 0x10B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_MASK_1 0x184510B0u

/*! Register Reset Value */
#define PCE_TBL_MASK_1_RST 0x00000000u

/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_1_MASK0_POS 0
/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_1_MASK0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_15 Register PCE_TBL_VAL_15 - Table Value Register 15 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_15 0x10B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_15 0x184510B4u

/*! Register Reset Value */
#define PCE_TBL_VAL_15_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_15_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_15_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_14 Register PCE_TBL_VAL_14 - Table Value Register 14 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_14 0x10B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_14 0x184510B8u

/*! Register Reset Value */
#define PCE_TBL_VAL_14_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_14_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_14_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_13 Register PCE_TBL_VAL_13 - Table Value Register 13 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_13 0x10BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_13 0x184510BCu

/*! Register Reset Value */
#define PCE_TBL_VAL_13_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_13_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_13_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_12 Register PCE_TBL_VAL_12 - Table Value Register 12 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_12 0x10C0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_12 0x184510C0u

/*! Register Reset Value */
#define PCE_TBL_VAL_12_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_12_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_12_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_11 Register PCE_TBL_VAL_11 - Table Value Register 11 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_11 0x10C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_11 0x184510C4u

/*! Register Reset Value */
#define PCE_TBL_VAL_11_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_11_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_11_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_10 Register PCE_TBL_VAL_10 - Table Value Register 10 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_10 0x10C8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_10 0x184510C8u

/*! Register Reset Value */
#define PCE_TBL_VAL_10_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_10_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_10_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_9 Register PCE_TBL_VAL_9 - Table Value Register 9 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_9 0x10CC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_9 0x184510CCu

/*! Register Reset Value */
#define PCE_TBL_VAL_9_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_9_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_9_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_8 Register PCE_TBL_VAL_8 - Table Value Register 8 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_8 0x10D0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_8 0x184510D0u

/*! Register Reset Value */
#define PCE_TBL_VAL_8_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_8_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_8_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_7 Register PCE_TBL_VAL_7 - Table Value Register 7 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_7 0x10D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_7 0x184510D4u

/*! Register Reset Value */
#define PCE_TBL_VAL_7_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_7_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_7_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_6 Register PCE_TBL_VAL_6 - Table Value Register 6 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_6 0x10D8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_6 0x184510D8u

/*! Register Reset Value */
#define PCE_TBL_VAL_6_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_6_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_6_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_5 Register PCE_TBL_VAL_5 - Table Value Register 5 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_5 0x10DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_5 0x184510DCu

/*! Register Reset Value */
#define PCE_TBL_VAL_5_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_5_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_5_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_15 Register PCE_TBL_KEY_15 - Table Key Data 15 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_15 0x10E0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_15 0x184510E0u

/*! Register Reset Value */
#define PCE_TBL_KEY_15_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_15_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_15_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_14 Register PCE_TBL_KEY_14 - Table Key Data 14 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_14 0x10E4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_14 0x184510E4u

/*! Register Reset Value */
#define PCE_TBL_KEY_14_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_14_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_14_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_13 Register PCE_TBL_KEY_13 - Table Key Data 13 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_13 0x10E8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_13 0x184510E8u

/*! Register Reset Value */
#define PCE_TBL_KEY_13_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_13_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_13_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_12 Register PCE_TBL_KEY_12 - Table Key Data 12 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_12 0x10EC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_12 0x184510ECu

/*! Register Reset Value */
#define PCE_TBL_KEY_12_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_12_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_12_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_11 Register PCE_TBL_KEY_11 - Table Key Data 11 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_11 0x10F0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_11 0x184510F0u

/*! Register Reset Value */
#define PCE_TBL_KEY_11_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_11_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_11_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_10 Register PCE_TBL_KEY_10 - Table Key Data 10 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_10 0x10F4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_10 0x184510F4u

/*! Register Reset Value */
#define PCE_TBL_KEY_10_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_10_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_10_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_9 Register PCE_TBL_KEY_9 - Table Key Data 9 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_9 0x10F8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_9 0x184510F8u

/*! Register Reset Value */
#define PCE_TBL_KEY_9_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_9_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_9_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_8 Register PCE_TBL_KEY_8 - Table Key Data 8 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_8 0x10FC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_8 0x184510FCu

/*! Register Reset Value */
#define PCE_TBL_KEY_8_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_8_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_8_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_7 Register PCE_TBL_KEY_7 - Table Key Data 7 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_7 0x1100
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_7 0x18451100u

/*! Register Reset Value */
#define PCE_TBL_KEY_7_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_7_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_7_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_6 Register PCE_TBL_KEY_6 - Table Key Data 6 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_6 0x1104
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_6 0x18451104u

/*! Register Reset Value */
#define PCE_TBL_KEY_6_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_6_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_6_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_5 Register PCE_TBL_KEY_5 - Table Key Data 5 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_5 0x1108
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_5 0x18451108u

/*! Register Reset Value */
#define PCE_TBL_KEY_5_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_5_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_5_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_4 Register PCE_TBL_KEY_4 - Table Key Data 4 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_4 0x110C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_4 0x1845110Cu

/*! Register Reset Value */
#define PCE_TBL_KEY_4_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_4_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_4_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_3 Register PCE_TBL_KEY_3 - Table Key Data 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_3 0x1110
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_3 0x18451110u

/*! Register Reset Value */
#define PCE_TBL_KEY_3_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_3_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_3_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_2 Register PCE_TBL_KEY_2 - Table Key Data 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_2 0x1114
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_2 0x18451114u

/*! Register Reset Value */
#define PCE_TBL_KEY_2_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_2_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_2_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_1 Register PCE_TBL_KEY_1 - Table Key Data 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_1 0x1118
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_1 0x18451118u

/*! Register Reset Value */
#define PCE_TBL_KEY_1_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_1_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_1_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_KEY_0 Register PCE_TBL_KEY_0 - Table Key Data 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_KEY_0 0x111C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_KEY_0 0x1845111Cu

/*! Register Reset Value */
#define PCE_TBL_KEY_0_RST 0x0000FFFFu

/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_0_KEY0_POS 0
/*! Field KEY0 - Key Value[15:0] */
#define PCE_TBL_KEY_0_KEY0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_MASK_0 Register PCE_TBL_MASK_0 - Table Mask Write Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_MASK_0 0x1120
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_MASK_0 0x18451120u

/*! Register Reset Value */
#define PCE_TBL_MASK_0_RST 0x00000000u

/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_0_MASK0_POS 0
/*! Field MASK0 - Mask Pattern [15:0] */
#define PCE_TBL_MASK_0_MASK0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_4 Register PCE_TBL_VAL_4 - Table Value Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_4 0x1124
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_4 0x18451124u

/*! Register Reset Value */
#define PCE_TBL_VAL_4_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_4_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_4_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_3 Register PCE_TBL_VAL_3 - Table Value Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_3 0x1128
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_3 0x18451128u

/*! Register Reset Value */
#define PCE_TBL_VAL_3_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_3_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_3_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_2 Register PCE_TBL_VAL_2 - Table Value Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_2 0x112C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_2 0x1845112Cu

/*! Register Reset Value */
#define PCE_TBL_VAL_2_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_2_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_2_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_1 Register PCE_TBL_VAL_1 - Table Value Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_1 0x1130
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_1 0x18451130u

/*! Register Reset Value */
#define PCE_TBL_VAL_1_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_1_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_1_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_VAL_0 Register PCE_TBL_VAL_0 - Table Value Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_VAL_0 0x1134
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_VAL_0 0x18451134u

/*! Register Reset Value */
#define PCE_TBL_VAL_0_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_0_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define PCE_TBL_VAL_0_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_TBL_ADDR Register PCE_TBL_ADDR - Table Entry Address Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_ADDR 0x1138
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_ADDR 0x18451138u

/*! Register Reset Value */
#define PCE_TBL_ADDR_RST 0x00000000u

/*! Field ADDR - Table Address */
#define PCE_TBL_ADDR_ADDR_POS 0
/*! Field ADDR - Table Address */
#define PCE_TBL_ADDR_ADDR_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_TBL_CTRL Register PCE_TBL_CTRL - Table Access Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_CTRL 0x113C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_CTRL 0x1845113Cu

/*! Register Reset Value */
#define PCE_TBL_CTRL_RST 0x00000000u

/*! Field ADDR - Lookup Table Address */
#define PCE_TBL_CTRL_ADDR_POS 0
/*! Field ADDR - Lookup Table Address */
#define PCE_TBL_CTRL_ADDR_MASK 0x1Fu
/*! Constant PARS - PARS */
#define CONST_PCE_TBL_CTRL_ADDR_PARS 0x0
/*! Constant VLANMAP - VLANMAP */
#define CONST_PCE_TBL_CTRL_ADDR_VLANMAP 0x2
/*! Constant PPPOE - PPPOE */
#define CONST_PCE_TBL_CTRL_ADDR_PPPOE 0x3
/*! Constant PROT - PROT */
#define CONST_PCE_TBL_CTRL_ADDR_PROT 0x4
/*! Constant APP - APP */
#define CONST_PCE_TBL_CTRL_ADDR_APP 0x5
/*! Constant IPMSB - IPMSB */
#define CONST_PCE_TBL_CTRL_ADDR_IPMSB 0x6
/*! Constant IPLSB - IPLSB */
#define CONST_PCE_TBL_CTRL_ADDR_IPLSB 0x7
/*! Constant IPLEN - IPLEN */
#define CONST_PCE_TBL_CTRL_ADDR_IPLEN 0x8
/*! Constant PCP - PCP */
#define CONST_PCE_TBL_CTRL_ADDR_PCP 0x9
/*! Constant DSCP - DSCP */
#define CONST_PCE_TBL_CTRL_ADDR_DSCP 0xA
/*! Constant MACB - MACB */
#define CONST_PCE_TBL_CTRL_ADDR_MACB 0xB
/*! Constant DSCP2PCP - DSCP2PCP */
#define CONST_PCE_TBL_CTRL_ADDR_DSCP2PCP 0xC
/*! Constant MCSW - MCSW */
#define CONST_PCE_TBL_CTRL_ADDR_MCSW 0xD
/*! Constant MCHW - MCHW */
#define CONST_PCE_TBL_CTRL_ADDR_MCHW 0xE
/*! Constant TFLOW - TFLOW */
#define CONST_PCE_TBL_CTRL_ADDR_TFLOW 0xF
/*! Constant RES16 - RES16 */
#define CONST_PCE_TBL_CTRL_ADDR_RES16 0x10
/*! Constant QMAP - QMAP */
#define CONST_PCE_TBL_CTRL_ADDR_QMAP 0x11
/*! Constant IGCTP - IGCTP */
#define CONST_PCE_TBL_CTRL_ADDR_IGCTP 0x12
/*! Constant EGCTP - EGCTP */
#define CONST_PCE_TBL_CTRL_ADDR_EGCTP 0x13
/*! Constant IGBGP - IGBGP */
#define CONST_PCE_TBL_CTRL_ADDR_IGBGP 0x14
/*! Constant EGBGP - EGBGP */
#define CONST_PCE_TBL_CTRL_ADDR_EGBGP 0x15
/*! Constant MACDA - MACDA */
#define CONST_PCE_TBL_CTRL_ADDR_MACDA 0x16
/*! Constant MACSA - MACSA */
#define CONST_PCE_TBL_CTRL_ADDR_MACSA 0x17
/*! Constant FLAGS - FLAGS */
#define CONST_PCE_TBL_CTRL_ADDR_FLAGS 0x18
/*! Constant BRGCFG - BRGCFG */
#define CONST_PCE_TBL_CTRL_ADDR_BRGCFG 0x19
/*! Constant SPCP - SPCP */
#define CONST_PCE_TBL_CTRL_ADDR_SPCP 0x1A
/*! Constant MAMRK - MAMRK */
#define CONST_PCE_TBL_CTRL_ADDR_MAMRK 0x1B
/*! Constant REMARK - REMARK */
#define CONST_PCE_TBL_CTRL_ADDR_REMARK 0x1C
/*! Constant PAYLOAD - PAYLOAD */
#define CONST_PCE_TBL_CTRL_ADDR_PAYLOAD 0x1D
/*! Constant EXTVLAN - EXTVLAN */
#define CONST_PCE_TBL_CTRL_ADDR_EXTVLAN 0x1E
/*! Constant PMAP - PMAP */
#define CONST_PCE_TBL_CTRL_ADDR_PMAP 0x1F

/*! Field OPMOD - Lookup Table Access Operation Mode */
#define PCE_TBL_CTRL_OPMOD_POS 5
/*! Field OPMOD - Lookup Table Access Operation Mode */
#define PCE_TBL_CTRL_OPMOD_MASK 0x60u
/*! Constant ADRD - ADRD */
#define CONST_PCE_TBL_CTRL_OPMOD_ADRD 0x0
/*! Constant ADWR - ADWR */
#define CONST_PCE_TBL_CTRL_OPMOD_ADWR 0x1
/*! Constant KSRD - KSRD */
#define CONST_PCE_TBL_CTRL_OPMOD_KSRD 0x2
/*! Constant KSWR - KSWR */
#define CONST_PCE_TBL_CTRL_OPMOD_KSWR 0x3

/*! Field GMAP - Group Map */
#define PCE_TBL_CTRL_GMAP_POS 7
/*! Field GMAP - Group Map */
#define PCE_TBL_CTRL_GMAP_MASK 0x780u

/*! Field KEYFORM - Key Format */
#define PCE_TBL_CTRL_KEYFORM_POS 11
/*! Field KEYFORM - Key Format */
#define PCE_TBL_CTRL_KEYFORM_MASK 0x800u
/*! Constant PATTERN - PATTERN */
#define CONST_PCE_TBL_CTRL_KEYFORM_PATTERN 0x0
/*! Constant COLUMN - COLUMN */
#define CONST_PCE_TBL_CTRL_KEYFORM_COLUMN 0x1

/*! Field VLD - Lookup Entry Valid */
#define PCE_TBL_CTRL_VLD_POS 12
/*! Field VLD - Lookup Entry Valid */
#define PCE_TBL_CTRL_VLD_MASK 0x1000u
/*! Constant INVALD - INVALD */
#define CONST_PCE_TBL_CTRL_VLD_INVALD 0x0
/*! Constant VALID - VALID */
#define CONST_PCE_TBL_CTRL_VLD_VALID 0x1

/*! Field TYPE - Lookup Entry Type */
#define PCE_TBL_CTRL_TYPE_POS 13
/*! Field TYPE - Lookup Entry Type */
#define PCE_TBL_CTRL_TYPE_MASK 0x2000u
/*! Constant MASK - MASK */
#define CONST_PCE_TBL_CTRL_TYPE_MASK 0x0
/*! Constant RANGE - RANGE */
#define CONST_PCE_TBL_CTRL_TYPE_RANGE 0x1

/*! Field EXTOP - Lookup Table Access Extended Operation Mode */
#define PCE_TBL_CTRL_EXTOP_POS 14
/*! Field EXTOP - Lookup Table Access Extended Operation Mode */
#define PCE_TBL_CTRL_EXTOP_MASK 0x4000u
/*! Constant DIS - DIS */
#define CONST_PCE_TBL_CTRL_EXTOP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_TBL_CTRL_EXTOP_EN 0x1

/*! Field BAS - Access Busy/Access Start */
#define PCE_TBL_CTRL_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define PCE_TBL_CTRL_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_PCE_TBL_CTRL_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_PCE_TBL_CTRL_BAS_BUSY 0x1

/*! @} */

/*! \defgroup PCE_TBL_STAT Register PCE_TBL_STAT - Table General Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TBL_STAT 0x1140
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TBL_STAT 0x18451140u

/*! Register Reset Value */
#define PCE_TBL_STAT_RST 0x00000002u

/*! Field TFUL - Table Full */
#define PCE_TBL_STAT_TFUL_POS 0
/*! Field TFUL - Table Full */
#define PCE_TBL_STAT_TFUL_MASK 0x1u
/*! Constant OK - OK */
#define CONST_PCE_TBL_STAT_TFUL_OK 0x0
/*! Constant FULL - FULL */
#define CONST_PCE_TBL_STAT_TFUL_FULL 0x1

/*! Field TEMPT - Table Empty */
#define PCE_TBL_STAT_TEMPT_POS 1
/*! Field TEMPT - Table Empty */
#define PCE_TBL_STAT_TEMPT_MASK 0x2u
/*! Constant FILLED - FILLED */
#define CONST_PCE_TBL_STAT_TEMPT_FILLED 0x0
/*! Constant EMPTY - EMPTY */
#define CONST_PCE_TBL_STAT_TEMPT_EMPTY 0x1

/*! Field TBUSY - Table Access Busy */
#define PCE_TBL_STAT_TBUSY_POS 2
/*! Field TBUSY - Table Access Busy */
#define PCE_TBL_STAT_TBUSY_MASK 0x4u
/*! Constant READY - READY */
#define CONST_PCE_TBL_STAT_TBUSY_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_PCE_TBL_STAT_TBUSY_BUSY 0x1

/*! @} */

/*! \defgroup PCE_AGE_0 Register PCE_AGE_0 - Aging Counter Configuration Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_AGE_0 0x1144
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_AGE_0 0x18451144u

/*! Register Reset Value */
#define PCE_AGE_0_RST 0x00000002u

/*! Field EXP - Aging Counter Exponent Value */
#define PCE_AGE_0_EXP_POS 0
/*! Field EXP - Aging Counter Exponent Value */
#define PCE_AGE_0_EXP_MASK 0xFu
/*! Constant S2E0 - S2E0 */
#define CONST_PCE_AGE_0_EXP_S2E0 0x0
/*! Constant S2E1 - S2E1 */
#define CONST_PCE_AGE_0_EXP_S2E1 0x1
/*! Constant S2E2 - S2E2 */
#define CONST_PCE_AGE_0_EXP_S2E2 0x2
/*! Constant S2E3 - S2E3 */
#define CONST_PCE_AGE_0_EXP_S2E3 0x3
/*! Constant S2E4 - S2E4 */
#define CONST_PCE_AGE_0_EXP_S2E4 0x4
/*! Constant S2E5 - S2E5 */
#define CONST_PCE_AGE_0_EXP_S2E5 0x5
/*! Constant S2E6 - S2E6 */
#define CONST_PCE_AGE_0_EXP_S2E6 0x6
/*! Constant S2E7 - S2E7 */
#define CONST_PCE_AGE_0_EXP_S2E7 0x7
/*! Constant S2E8 - S2E8 */
#define CONST_PCE_AGE_0_EXP_S2E8 0x8
/*! Constant S2E9 - S2E9 */
#define CONST_PCE_AGE_0_EXP_S2E9 0x9
/*! Constant S2E10 - S2E10 */
#define CONST_PCE_AGE_0_EXP_S2E10 0xA
/*! Constant S2E11 - S2E11 */
#define CONST_PCE_AGE_0_EXP_S2E11 0xB
/*! Constant S2E12 - S2E12 */
#define CONST_PCE_AGE_0_EXP_S2E12 0xC
/*! Constant S2E13 - S2E13 */
#define CONST_PCE_AGE_0_EXP_S2E13 0xD
/*! Constant S2E14 - S2E14 */
#define CONST_PCE_AGE_0_EXP_S2E14 0xE
/*! Constant S2E15 - S2E15 */
#define CONST_PCE_AGE_0_EXP_S2E15 0xF

/*! @} */

/*! \defgroup PCE_AGE_1 Register PCE_AGE_1 - Aging Counter Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_AGE_1 0x1148
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_AGE_1 0x18451148u

/*! Register Reset Value */
#define PCE_AGE_1_RST 0x0000DF84u

/*! Field MANT - Aging Counter Mantissa Value */
#define PCE_AGE_1_MANT_POS 0
/*! Field MANT - Aging Counter Mantissa Value */
#define PCE_AGE_1_MANT_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_PMAP_1 Register PCE_PMAP_1 - Port Map Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PMAP_1 0x114C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PMAP_1 0x1845114Cu

/*! Register Reset Value */
#define PCE_PMAP_1_RST 0x00000000u

/*! Field PID - Monitoring Port Logical ID */
#define PCE_PMAP_1_PID_POS 0
/*! Field PID - Monitoring Port Logical ID */
#define PCE_PMAP_1_PID_MASK 0xFu

/*! Field SUBID - Monitoring Port SUBID */
#define PCE_PMAP_1_SUBID_POS 4
/*! Field SUBID - Monitoring Port SUBID */
#define PCE_PMAP_1_SUBID_MASK 0xFFF0u

/*! @} */

/*! \defgroup PCE_GCTRL_0 Register PCE_GCTRL_0 - PCE Global Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_GCTRL_0 0x1158
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_GCTRL_0 0x18451158u

/*! Register Reset Value */
#define PCE_GCTRL_0_RST 0x00000000u

/*! Field MTFL - MAC Table Flushing */
#define PCE_GCTRL_0_MTFL_POS 0
/*! Field MTFL - MAC Table Flushing */
#define PCE_GCTRL_0_MTFL_MASK 0x1u
/*! Constant NOP - NOP */
#define CONST_PCE_GCTRL_0_MTFL_NOP 0x0
/*! Constant FLUSH - FLUSH */
#define CONST_PCE_GCTRL_0_MTFL_FLUSH 0x1

/*! Field PLIMMOD - MAC Address Learning Limitation Mode */
#define PCE_GCTRL_0_PLIMMOD_POS 1
/*! Field PLIMMOD - MAC Address Learning Limitation Mode */
#define PCE_GCTRL_0_PLIMMOD_MASK 0x2u
/*! Constant DROP - DROP */
#define CONST_PCE_GCTRL_0_PLIMMOD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_PCE_GCTRL_0_PLIMMOD_FWD 0x1

/*! Field PLCKMOD - Port Lock Mode */
#define PCE_GCTRL_0_PLCKMOD_POS 2
/*! Field PLCKMOD - Port Lock Mode */
#define PCE_GCTRL_0_PLCKMOD_MASK 0x4u
/*! Constant DROP - DROP */
#define CONST_PCE_GCTRL_0_PLCKMOD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_PCE_GCTRL_0_PLCKMOD_FWD 0x1

/*! Field MC_VALID - Access Request */
#define PCE_GCTRL_0_MC_VALID_POS 3
/*! Field MC_VALID - Access Request */
#define PCE_GCTRL_0_MC_VALID_MASK 0x8u
/*! Constant INVAL - INVAL */
#define CONST_PCE_GCTRL_0_MC_VALID_INVAL 0x0
/*! Constant VALID - VALID */
#define CONST_PCE_GCTRL_0_MC_VALID_VALID 0x1

/*! Field IGMP - IGMP Mode Selection */
#define PCE_GCTRL_0_IGMP_POS 15
/*! Field IGMP - IGMP Mode Selection */
#define PCE_GCTRL_0_IGMP_MASK 0x8000u
/*! Constant HW - HW */
#define CONST_PCE_GCTRL_0_IGMP_HW 0x0
/*! Constant SW - SW */
#define CONST_PCE_GCTRL_0_IGMP_SW 0x1

/*! @} */

/*! \defgroup PCE_GCTRL_1 Register PCE_GCTRL_1 - PCE Global Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_GCTRL_1 0x115C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_GCTRL_1 0x1845115Cu

/*! Register Reset Value */
#define PCE_GCTRL_1_RST 0x00000001u

/*! Field LRNMOD - MAC Address Learning Mode */
#define PCE_GCTRL_1_LRNMOD_POS 0
/*! Field LRNMOD - MAC Address Learning Mode */
#define PCE_GCTRL_1_LRNMOD_MASK 0x1u
/*! Constant WAIT - WAIT */
#define CONST_PCE_GCTRL_1_LRNMOD_WAIT 0x0
/*! Constant LRU - LRU */
#define CONST_PCE_GCTRL_1_LRNMOD_LRU 0x1

/*! Field PCE_DIS - PCE Disable after currently processed packet */
#define PCE_GCTRL_1_PCE_DIS_POS 1
/*! Field PCE_DIS - PCE Disable after currently processed packet */
#define PCE_GCTRL_1_PCE_DIS_MASK 0x2u
/*! Constant EN - EN */
#define CONST_PCE_GCTRL_1_PCE_DIS_EN 0x0
/*! Constant DIS - DIS */
#define CONST_PCE_GCTRL_1_PCE_DIS_DIS 0x1

/*! Field MAC_GLOCK - MAC Address Table Lock */
#define PCE_GCTRL_1_MAC_GLOCK_POS 2
/*! Field MAC_GLOCK - MAC Address Table Lock */
#define PCE_GCTRL_1_MAC_GLOCK_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_GCTRL_1_MAC_GLOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_GCTRL_1_MAC_GLOCK_EN 0x1

/*! Field MAC_GLOCKMOD - MAC Address Table Lock forwarding mode */
#define PCE_GCTRL_1_MAC_GLOCKMOD_POS 3
/*! Field MAC_GLOCKMOD - MAC Address Table Lock forwarding mode */
#define PCE_GCTRL_1_MAC_GLOCKMOD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_PCE_GCTRL_1_MAC_GLOCKMOD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_PCE_GCTRL_1_MAC_GLOCKMOD_FWD 0x1

/*! Field RMSEL - Remarking Selection */
#define PCE_GCTRL_1_RMSEL_POS 4
/*! Field RMSEL - Remarking Selection */
#define PCE_GCTRL_1_RMSEL_MASK 0x10u
/*! Constant PRI - PRI */
#define CONST_PCE_GCTRL_1_RMSEL_PRI 0x0
/*! Constant TC - TC */
#define CONST_PCE_GCTRL_1_RMSEL_TC 0x1

/*! Field EGRED - Egress Red Color Forwarding Mode */
#define PCE_GCTRL_1_EGRED_POS 5
/*! Field EGRED - Egress Red Color Forwarding Mode */
#define PCE_GCTRL_1_EGRED_MASK 0x20u
/*! Constant DROP - DROP */
#define CONST_PCE_GCTRL_1_EGRED_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_PCE_GCTRL_1_EGRED_FWD 0x1

/*! Field IGRED - Ingress Red Color Forwarding Mode */
#define PCE_GCTRL_1_IGRED_POS 6
/*! Field IGRED - Ingress Red Color Forwarding Mode */
#define PCE_GCTRL_1_IGRED_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_PCE_GCTRL_1_IGRED_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_PCE_GCTRL_1_IGRED_FWD 0x1

/*! Field SPFMOD - Port Spoofing Detection Violation Forwarding Mode */
#define PCE_GCTRL_1_SPFMOD_POS 7
/*! Field SPFMOD - Port Spoofing Detection Violation Forwarding Mode */
#define PCE_GCTRL_1_SPFMOD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_PCE_GCTRL_1_SPFMOD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_PCE_GCTRL_1_SPFMOD_FWD 0x1

/*! Field DIPSIP - Filter Enable on DIP=SIP */
#define PCE_GCTRL_1_DIPSIP_POS 12
/*! Field DIPSIP - Filter Enable on DIP=SIP */
#define PCE_GCTRL_1_DIPSIP_MASK 0x1000u
/*! Constant DIS - DIS */
#define CONST_PCE_GCTRL_1_DIPSIP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_GCTRL_1_DIPSIP_EN 0x1

/*! Field DASA - Filter Enable on DA=SA */
#define PCE_GCTRL_1_DASA_POS 13
/*! Field DASA - Filter Enable on DA=SA */
#define PCE_GCTRL_1_DASA_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_GCTRL_1_DASA_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_GCTRL_1_DASA_EN 0x1

/*! Field PARSER_DBG - Parser Debug Selection */
#define PCE_GCTRL_1_PARSER_DBG_POS 14
/*! Field PARSER_DBG - Parser Debug Selection */
#define PCE_GCTRL_1_PARSER_DBG_MASK 0xC000u
/*! Constant PARS0 - PARS0 */
#define CONST_PCE_GCTRL_1_PARSER_DBG_PARS0 0x0
/*! Constant PARS1 - PARS1 */
#define CONST_PCE_GCTRL_1_PARSER_DBG_PARS1 0x1
/*! Constant PARS2 - PARS2 */
#define CONST_PCE_GCTRL_1_PARSER_DBG_PARS2 0x2
/*! Constant PARS3 - PARS3 */
#define CONST_PCE_GCTRL_1_PARSER_DBG_PARS3 0x3

/*! @} */

/*! \defgroup WOL_GLB_CTRL Register WOL_GLB_CTRL - Wake-on-LAN Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_GLB_CTRL 0x1178
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_GLB_CTRL 0x18451178u

/*! Register Reset Value */
#define WOL_GLB_CTRL_RST 0x00000000u

/*! Field PASSEN - WoL Password Enable */
#define WOL_GLB_CTRL_PASSEN_POS 0
/*! Field PASSEN - WoL Password Enable */
#define WOL_GLB_CTRL_PASSEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_GLB_CTRL_PASSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_GLB_CTRL_PASSEN_EN 0x1

/*! @} */

/*! \defgroup WOL_DA_0 Register WOL_DA_0 - Wake-on-LAN Destination Address Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_DA_0 0x117C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_DA_0 0x1845117Cu

/*! Register Reset Value */
#define WOL_DA_0_RST 0x00000000u

/*! Field DA0 - WoL Destination Address [15:0] */
#define WOL_DA_0_DA0_POS 0
/*! Field DA0 - WoL Destination Address [15:0] */
#define WOL_DA_0_DA0_MASK 0xFFFFu

/*! @} */

/*! \defgroup WOL_DA_1 Register WOL_DA_1 - Wake-on-LAN Destination Address Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_DA_1 0x1180
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_DA_1 0x18451180u

/*! Register Reset Value */
#define WOL_DA_1_RST 0x00000000u

/*! Field DA1 - WoL Destination Address [31:16] */
#define WOL_DA_1_DA1_POS 0
/*! Field DA1 - WoL Destination Address [31:16] */
#define WOL_DA_1_DA1_MASK 0xFFFFu

/*! @} */

/*! \defgroup WOL_DA_2 Register WOL_DA_2 - Wake-on-LAN Destination Address Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_DA_2 0x1184
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_DA_2 0x18451184u

/*! Register Reset Value */
#define WOL_DA_2_RST 0x00000000u

/*! Field DA2 - WoL Destination Address [47:32] */
#define WOL_DA_2_DA2_POS 0
/*! Field DA2 - WoL Destination Address [47:32] */
#define WOL_DA_2_DA2_MASK 0xFFFFu

/*! @} */

/*! \defgroup WOL_PW_0 Register WOL_PW_0 - Wake-on-LAN Password Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_PW_0 0x1188
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_PW_0 0x18451188u

/*! Register Reset Value */
#define WOL_PW_0_RST 0x00000000u

/*! Field PW0 - WoL Password [15:0] */
#define WOL_PW_0_PW0_POS 0
/*! Field PW0 - WoL Password [15:0] */
#define WOL_PW_0_PW0_MASK 0xFFFFu

/*! @} */

/*! \defgroup WOL_PW_1 Register WOL_PW_1 - Wake-on-LAN Password Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_PW_1 0x118C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_PW_1 0x1845118Cu

/*! Register Reset Value */
#define WOL_PW_1_RST 0x00000000u

/*! Field PW1 - WoL Password [31:16] */
#define WOL_PW_1_PW1_POS 0
/*! Field PW1 - WoL Password [31:16] */
#define WOL_PW_1_PW1_MASK 0xFFFFu

/*! @} */

/*! \defgroup WOL_PW_2 Register WOL_PW_2 - Wake-on-LAN Password Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_PW_2 0x1190
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_PW_2 0x18451190u

/*! Register Reset Value */
#define WOL_PW_2_RST 0x00000000u

/*! Field PW2 - WoL Password [47:32] */
#define WOL_PW_2_PW2_POS 0
/*! Field PW2 - WoL Password [47:32] */
#define WOL_PW_2_PW2_MASK 0xFFFFu

/*! @} */

/*! \defgroup PCE_IER_0 Register PCE_IER_0 - Parser and Classification Engine Global Interrupt Enable Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_IER_0 0x1194
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_IER_0 0x18451194u

/*! Register Reset Value */
#define PCE_IER_0_RST 0x00000000u

/*! Field PINT_0 - Port Interrupt Enable */
#define PCE_IER_0_PINT_0_POS 0
/*! Field PINT_0 - Port Interrupt Enable */
#define PCE_IER_0_PINT_0_MASK 0x1u

/*! Field PINT_1 - Port Interrupt Enable */
#define PCE_IER_0_PINT_1_POS 1
/*! Field PINT_1 - Port Interrupt Enable */
#define PCE_IER_0_PINT_1_MASK 0x2u

/*! Field PINT_2 - Port Interrupt Enable */
#define PCE_IER_0_PINT_2_POS 2
/*! Field PINT_2 - Port Interrupt Enable */
#define PCE_IER_0_PINT_2_MASK 0x4u

/*! Field PINT_3 - Port Interrupt Enable */
#define PCE_IER_0_PINT_3_POS 3
/*! Field PINT_3 - Port Interrupt Enable */
#define PCE_IER_0_PINT_3_MASK 0x8u

/*! Field PINT_4 - Port Interrupt Enable */
#define PCE_IER_0_PINT_4_POS 4
/*! Field PINT_4 - Port Interrupt Enable */
#define PCE_IER_0_PINT_4_MASK 0x10u

/*! Field PINT_5 - Port Interrupt Enable */
#define PCE_IER_0_PINT_5_POS 5
/*! Field PINT_5 - Port Interrupt Enable */
#define PCE_IER_0_PINT_5_MASK 0x20u

/*! Field PINT_6 - Port Interrupt Enable */
#define PCE_IER_0_PINT_6_POS 6
/*! Field PINT_6 - Port Interrupt Enable */
#define PCE_IER_0_PINT_6_MASK 0x40u

/*! Field PINT_7 - Port Interrupt Enable */
#define PCE_IER_0_PINT_7_POS 7
/*! Field PINT_7 - Port Interrupt Enable */
#define PCE_IER_0_PINT_7_MASK 0x80u

/*! Field PINT_8 - Port Interrupt Enable */
#define PCE_IER_0_PINT_8_POS 8
/*! Field PINT_8 - Port Interrupt Enable */
#define PCE_IER_0_PINT_8_MASK 0x100u

/*! Field PINT_9 - Port Interrupt Enable */
#define PCE_IER_0_PINT_9_POS 9
/*! Field PINT_9 - Port Interrupt Enable */
#define PCE_IER_0_PINT_9_MASK 0x200u

/*! Field PINT_10 - Port Interrupt Enable */
#define PCE_IER_0_PINT_10_POS 10
/*! Field PINT_10 - Port Interrupt Enable */
#define PCE_IER_0_PINT_10_MASK 0x400u

/*! Field PINT_11 - Port Interrupt Enable */
#define PCE_IER_0_PINT_11_POS 11
/*! Field PINT_11 - Port Interrupt Enable */
#define PCE_IER_0_PINT_11_MASK 0x800u

/*! Field PINT_12 - Port Interrupt Enable */
#define PCE_IER_0_PINT_12_POS 12
/*! Field PINT_12 - Port Interrupt Enable */
#define PCE_IER_0_PINT_12_MASK 0x1000u

/*! Field PINT_13 - Port Interrupt Enable */
#define PCE_IER_0_PINT_13_POS 13
/*! Field PINT_13 - Port Interrupt Enable */
#define PCE_IER_0_PINT_13_MASK 0x2000u

/*! Field PINT_14 - Port Interrupt Enable */
#define PCE_IER_0_PINT_14_POS 14
/*! Field PINT_14 - Port Interrupt Enable */
#define PCE_IER_0_PINT_14_MASK 0x4000u

/*! Field PINT_15 - Port Interrupt Enable */
#define PCE_IER_0_PINT_15_POS 15
/*! Field PINT_15 - Port Interrupt Enable */
#define PCE_IER_0_PINT_15_MASK 0x8000u

/*! @} */

/*! \defgroup PCE_IER_1 Register PCE_IER_1 - Parser and Classification Engine Global Interrupt Enable Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_IER_1 0x1198
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_IER_1 0x18451198u

/*! Register Reset Value */
#define PCE_IER_1_RST 0x00000000u

/*! Field MTF - MAC Table Full Interrupt Enable */
#define PCE_IER_1_MTF_POS 0
/*! Field MTF - MAC Table Full Interrupt Enable */
#define PCE_IER_1_MTF_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_IER_1_MTF_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_IER_1_MTF_EN 0x1

/*! Field PRDY - Parser Ready Interrupt Enable */
#define PCE_IER_1_PRDY_POS 2
/*! Field PRDY - Parser Ready Interrupt Enable */
#define PCE_IER_1_PRDY_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_IER_1_PRDY_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_IER_1_PRDY_EN 0x1

/*! Field CPH0 - Classification Phase 0 Ready Interrupt Enable */
#define PCE_IER_1_CPH0_POS 3
/*! Field CPH0 - Classification Phase 0 Ready Interrupt Enable */
#define PCE_IER_1_CPH0_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_IER_1_CPH0_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_IER_1_CPH0_EN 0x1

/*! Field CPH1 - Classification Phase 1 Ready Interrupt Enable */
#define PCE_IER_1_CPH1_POS 4
/*! Field CPH1 - Classification Phase 1 Ready Interrupt Enable */
#define PCE_IER_1_CPH1_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_IER_1_CPH1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_IER_1_CPH1_EN 0x1

/*! Field CPH2 - Classification Phase 2 Ready Interrupt Enable */
#define PCE_IER_1_CPH2_POS 5
/*! Field CPH2 - Classification Phase 2 Ready Interrupt Enable */
#define PCE_IER_1_CPH2_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_IER_1_CPH2_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_IER_1_CPH2_EN 0x1

/*! Field FLOWINT - Traffic Flow Table Interrupt Rule matched Interrupt Enable */
#define PCE_IER_1_FLOWINT_POS 6
/*! Field FLOWINT - Traffic Flow Table Interrupt Rule matched Interrupt Enable */
#define PCE_IER_1_FLOWINT_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_IER_1_FLOWINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_IER_1_FLOWINT_EN 0x1

/*! Field CHG - MAC Table Changed Entry Interrupt Enable */
#define PCE_IER_1_CHG_POS 7
/*! Field CHG - MAC Table Changed Entry Interrupt Enable */
#define PCE_IER_1_CHG_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_IER_1_CHG_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_IER_1_CHG_EN 0x1

/*! @} */

/*! \defgroup PCE_ISR_0 Register PCE_ISR_0 - Parser and Classification Engine Global Interrupt Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_ISR_0 0x119C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_ISR_0 0x1845119Cu

/*! Register Reset Value */
#define PCE_ISR_0_RST 0x00000000u

/*! Field PINT_0 - Port Interrupt */
#define PCE_ISR_0_PINT_0_POS 0
/*! Field PINT_0 - Port Interrupt */
#define PCE_ISR_0_PINT_0_MASK 0x1u

/*! Field PINT_1 - Port Interrupt */
#define PCE_ISR_0_PINT_1_POS 1
/*! Field PINT_1 - Port Interrupt */
#define PCE_ISR_0_PINT_1_MASK 0x2u

/*! Field PINT_2 - Port Interrupt */
#define PCE_ISR_0_PINT_2_POS 2
/*! Field PINT_2 - Port Interrupt */
#define PCE_ISR_0_PINT_2_MASK 0x4u

/*! Field PINT_3 - Port Interrupt */
#define PCE_ISR_0_PINT_3_POS 3
/*! Field PINT_3 - Port Interrupt */
#define PCE_ISR_0_PINT_3_MASK 0x8u

/*! Field PINT_4 - Port Interrupt */
#define PCE_ISR_0_PINT_4_POS 4
/*! Field PINT_4 - Port Interrupt */
#define PCE_ISR_0_PINT_4_MASK 0x10u

/*! Field PINT_5 - Port Interrupt */
#define PCE_ISR_0_PINT_5_POS 5
/*! Field PINT_5 - Port Interrupt */
#define PCE_ISR_0_PINT_5_MASK 0x20u

/*! Field PINT_6 - Port Interrupt */
#define PCE_ISR_0_PINT_6_POS 6
/*! Field PINT_6 - Port Interrupt */
#define PCE_ISR_0_PINT_6_MASK 0x40u

/*! Field PINT_7 - Port Interrupt */
#define PCE_ISR_0_PINT_7_POS 7
/*! Field PINT_7 - Port Interrupt */
#define PCE_ISR_0_PINT_7_MASK 0x80u

/*! Field PINT_8 - Port Interrupt */
#define PCE_ISR_0_PINT_8_POS 8
/*! Field PINT_8 - Port Interrupt */
#define PCE_ISR_0_PINT_8_MASK 0x100u

/*! Field PINT_9 - Port Interrupt */
#define PCE_ISR_0_PINT_9_POS 9
/*! Field PINT_9 - Port Interrupt */
#define PCE_ISR_0_PINT_9_MASK 0x200u

/*! Field PINT_10 - Port Interrupt */
#define PCE_ISR_0_PINT_10_POS 10
/*! Field PINT_10 - Port Interrupt */
#define PCE_ISR_0_PINT_10_MASK 0x400u

/*! Field PINT_11 - Port Interrupt */
#define PCE_ISR_0_PINT_11_POS 11
/*! Field PINT_11 - Port Interrupt */
#define PCE_ISR_0_PINT_11_MASK 0x800u

/*! Field PINT_12 - Port Interrupt */
#define PCE_ISR_0_PINT_12_POS 12
/*! Field PINT_12 - Port Interrupt */
#define PCE_ISR_0_PINT_12_MASK 0x1000u

/*! Field PINT_13 - Port Interrupt */
#define PCE_ISR_0_PINT_13_POS 13
/*! Field PINT_13 - Port Interrupt */
#define PCE_ISR_0_PINT_13_MASK 0x2000u

/*! Field PINT_14 - Port Interrupt */
#define PCE_ISR_0_PINT_14_POS 14
/*! Field PINT_14 - Port Interrupt */
#define PCE_ISR_0_PINT_14_MASK 0x4000u

/*! Field PINT_15 - Port Interrupt */
#define PCE_ISR_0_PINT_15_POS 15
/*! Field PINT_15 - Port Interrupt */
#define PCE_ISR_0_PINT_15_MASK 0x8000u

/*! @} */

/*! \defgroup PCE_ISR_1 Register PCE_ISR_1 - Parser and Classification Engine Global Interrupt Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_ISR_1 0x11A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_ISR_1 0x184511A0u

/*! Register Reset Value */
#define PCE_ISR_1_RST 0x00000000u

/*! Field MTF - MAC Table Full Interrupt */
#define PCE_ISR_1_MTF_POS 0
/*! Field MTF - MAC Table Full Interrupt */
#define PCE_ISR_1_MTF_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_ISR_1_MTF_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_ISR_1_MTF_INT 0x1

/*! Field PRDY - Parser Ready Interrupt */
#define PCE_ISR_1_PRDY_POS 2
/*! Field PRDY - Parser Ready Interrupt */
#define PCE_ISR_1_PRDY_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_ISR_1_PRDY_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_ISR_1_PRDY_INT 0x1

/*! Field CPH0 - Classification Phase 0 Ready Interrupt */
#define PCE_ISR_1_CPH0_POS 3
/*! Field CPH0 - Classification Phase 0 Ready Interrupt */
#define PCE_ISR_1_CPH0_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_ISR_1_CPH0_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_ISR_1_CPH0_INT 0x1

/*! Field CPH1 - Classification Phase 1 Ready Interrupt */
#define PCE_ISR_1_CPH1_POS 4
/*! Field CPH1 - Classification Phase 1 Ready Interrupt */
#define PCE_ISR_1_CPH1_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_ISR_1_CPH1_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_ISR_1_CPH1_INT 0x1

/*! Field CPH2 - Classification Phase 2 Ready Interrupt */
#define PCE_ISR_1_CPH2_POS 5
/*! Field CPH2 - Classification Phase 2 Ready Interrupt */
#define PCE_ISR_1_CPH2_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_ISR_1_CPH2_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_ISR_1_CPH2_INT 0x1

/*! Field FLOWINT - Traffic Flow Table Interrupt Rule matched */
#define PCE_ISR_1_FLOWINT_POS 6
/*! Field FLOWINT - Traffic Flow Table Interrupt Rule matched */
#define PCE_ISR_1_FLOWINT_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_ISR_1_FLOWINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_ISR_1_FLOWINT_INT 0x1

/*! Field CHG - MAC Table Changed Entry Interrupt */
#define PCE_ISR_1_CHG_POS 7
/*! Field CHG - MAC Table Changed Entry Interrupt */
#define PCE_ISR_1_CHG_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_ISR_1_CHG_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_ISR_1_CHG_INT 0x1

/*! @} */

/*! \defgroup PARSER_STAT Register PARSER_STAT - Parser Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PARSER_STAT 0x11A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PARSER_STAT 0x184511A4u

/*! Register Reset Value */
#define PARSER_STAT_RST 0x00000000u

/*! Field FIFO_FULL - Parser's FIFO full */
#define PARSER_STAT_FIFO_FULL_POS 0
/*! Field FIFO_FULL - Parser's FIFO full */
#define PARSER_STAT_FIFO_FULL_MASK 0x1u

/*! Field FIFO_RDY - Parser FIFO ready for read. */
#define PARSER_STAT_FIFO_RDY_POS 1
/*! Field FIFO_RDY - Parser FIFO ready for read. */
#define PARSER_STAT_FIFO_RDY_MASK 0x2u

/*! Field FSM_START - Parser FSM start */
#define PARSER_STAT_FSM_START_POS 2
/*! Field FSM_START - Parser FSM start */
#define PARSER_STAT_FSM_START_MASK 0x4u

/*! Field FSM_FIN - Parser FSM finished */
#define PARSER_STAT_FSM_FIN_POS 3
/*! Field FSM_FIN - Parser FSM finished */
#define PARSER_STAT_FSM_FIN_MASK 0x8u

/*! Field PKT_ERR - Packet error detected */
#define PARSER_STAT_PKT_ERR_POS 4
/*! Field PKT_ERR - Packet error detected */
#define PARSER_STAT_PKT_ERR_MASK 0x10u

/*! Field FSM_STATE - Parser FSM State */
#define PARSER_STAT_FSM_STATE_POS 5
/*! Field FSM_STATE - Parser FSM State */
#define PARSER_STAT_FSM_STATE_MASK 0xE0u
/*! Constant S0 - S0 */
#define CONST_PARSER_STAT_FSM_STATE_S0 0x0
/*! Constant S1 - S1 */
#define CONST_PARSER_STAT_FSM_STATE_S1 0x1
/*! Constant S2 - S2 */
#define CONST_PARSER_STAT_FSM_STATE_S2 0x2
/*! Constant S3 - S3 */
#define CONST_PARSER_STAT_FSM_STATE_S3 0x3
/*! Constant S4 - S4 */
#define CONST_PARSER_STAT_FSM_STATE_S4 0x4
/*! Constant S5 - S5 */
#define CONST_PARSER_STAT_FSM_STATE_S5 0x5
/*! Constant S6 - S6 */
#define CONST_PARSER_STAT_FSM_STATE_S6 0x6
/*! Constant S7 - S7 */
#define CONST_PARSER_STAT_FSM_STATE_S7 0x7

/*! Field FSM_DAT_CNT - Parser FSM Data Counter */
#define PARSER_STAT_FSM_DAT_CNT_POS 8
/*! Field FSM_DAT_CNT - Parser FSM Data Counter */
#define PARSER_STAT_FSM_DAT_CNT_MASK 0xFF00u

/*! @} */

/*! \defgroup PCE_CGDMAC Register PCE_CGDMAC - PCE Changed MAC Entry Number */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_CGDMAC 0x11A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_CGDMAC 0x184511A8u

/*! Register Reset Value */
#define PCE_CGDMAC_RST 0x00000000u

/*! Field NUM - PCE Changed MAC Entry Number */
#define PCE_CGDMAC_NUM_POS 0
/*! Field NUM - PCE Changed MAC Entry Number */
#define PCE_CGDMAC_NUM_MASK 0x3FFFu

/*! @} */

/*! \defgroup PCE_TRUNK_CONF Register PCE_TRUNK_CONF - PCE Trunking Distribution Number */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TRUNK_CONF 0x11AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TRUNK_CONF 0x184511ACu

/*! Register Reset Value */
#define PCE_TRUNK_CONF_RST 0x00000000u

/*! Field SA - Source MAC Mask */
#define PCE_TRUNK_CONF_SA_POS 0
/*! Field SA - Source MAC Mask */
#define PCE_TRUNK_CONF_SA_MASK 0x1u
/*! Constant EN - EN */
#define CONST_PCE_TRUNK_CONF_SA_EN 0x0
/*! Constant DIS - DIS */
#define CONST_PCE_TRUNK_CONF_SA_DIS 0x1

/*! Field DA - Destination MAC Mask */
#define PCE_TRUNK_CONF_DA_POS 1
/*! Field DA - Destination MAC Mask */
#define PCE_TRUNK_CONF_DA_MASK 0x2u
/*! Constant EN - EN */
#define CONST_PCE_TRUNK_CONF_DA_EN 0x0
/*! Constant DIS - DIS */
#define CONST_PCE_TRUNK_CONF_DA_DIS 0x1

/*! Field SIP - Source IP Mask */
#define PCE_TRUNK_CONF_SIP_POS 2
/*! Field SIP - Source IP Mask */
#define PCE_TRUNK_CONF_SIP_MASK 0x4u
/*! Constant EN - EN */
#define CONST_PCE_TRUNK_CONF_SIP_EN 0x0
/*! Constant DIS - DIS */
#define CONST_PCE_TRUNK_CONF_SIP_DIS 0x1

/*! Field DIP - Destination IP Mask */
#define PCE_TRUNK_CONF_DIP_POS 3
/*! Field DIP - Destination IP Mask */
#define PCE_TRUNK_CONF_DIP_MASK 0x8u
/*! Constant EN - EN */
#define CONST_PCE_TRUNK_CONF_DIP_EN 0x0
/*! Constant DIS - DIS */
#define CONST_PCE_TRUNK_CONF_DIP_DIS 0x1

/*! @} */

/*! \defgroup PCE_OVERHD Register PCE_OVERHD - PCE Meter Overhead Byte Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_OVERHD 0x11B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_OVERHD 0x184511B0u

/*! Register Reset Value */
#define PCE_OVERHD_RST 0x00000000u

/*! Field OVERHD - PCE Meter Shaper Overhead Byte */
#define PCE_OVERHD_OVERHD_POS 0
/*! Field OVERHD - PCE Meter Shaper Overhead Byte */
#define PCE_OVERHD_OVERHD_MASK 0xFFu

/*! @} */

/*! \defgroup PCE_TFCR_ID Register PCE_TFCR_ID - PCE Flow Engine Common Region Start Index Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TFCR_ID 0x11B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TFCR_ID 0x184511B8u

/*! Register Reset Value */
#define PCE_TFCR_ID_RST 0x00000000u

/*! Field INDEX - PCE Flow Engine Common Region Start Index */
#define PCE_TFCR_ID_INDEX_POS 0
/*! Field INDEX - PCE Flow Engine Common Region Start Index */
#define PCE_TFCR_ID_INDEX_MASK 0x7Fu

/*! @} */

/*! \defgroup PCE_TFCR_NUM Register PCE_TFCR_NUM - PCE Flow Engine Common Region Entry Numbers Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_TFCR_NUM 0x11BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_TFCR_NUM 0x184511BCu

/*! Register Reset Value */
#define PCE_TFCR_NUM_RST 0x00000010u

/*! Field NUMBERS - PCE Flow Engine Common Region Entry Numbers */
#define PCE_TFCR_NUM_NUMBERS_POS 0
/*! Field NUMBERS - PCE Flow Engine Common Region Entry Numbers */
#define PCE_TFCR_NUM_NUMBERS_MASK 0xFFu

/*! @} */

/*! \defgroup PCE_PCTRL_0 Register PCE_PCTRL_0 - PCE Port Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0 0x1200
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0 0x18451200u

/*! Register Reset Value */
#define PCE_PCTRL_0_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2 Register PCE_PCTRL_2 - PCE Port Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2 0x1208
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2 0x18451208u

/*! Register Reset Value */
#define PCE_PCTRL_2_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3 Register PCE_PCTRL_3 - PCE Port Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3 0x120C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3 0x1845120Cu

/*! Register Reset Value */
#define PCE_PCTRL_3_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL Register WOL_CTRL - Wake-on-LAN Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL 0x1210
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL 0x18451210u

/*! Register Reset Value */
#define WOL_CTRL_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID Register PCE_DEFPVID - PCE Default Port VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID 0x1218
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID 0x18451218u

/*! Register Reset Value */
#define PCE_DEFPVID_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER Register PCE_PIER - Parser and Classification Engine Port Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER 0x1220
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER 0x18451220u

/*! Register Reset Value */
#define PCE_PIER_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR Register PCE_PISR - Parser and Classification Engine Port Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR 0x1224
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR 0x18451224u

/*! Register Reset Value */
#define PCE_PISR_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_1 Register PCE_PCTRL_0_1 - PCE Port 1 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_1 0x1228
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_1 0x18451228u

/*! Register Reset Value */
#define PCE_PCTRL_0_1_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_1_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_1_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_1_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_1_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_1_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_1_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_1_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_1_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_1 Register PCE_PCTRL_2_1 - PCE Port 1 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_1 0x1230
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_1 0x18451230u

/*! Register Reset Value */
#define PCE_PCTRL_2_1_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_1_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_1_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_1_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_1_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_1_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_1_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_1_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_1_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_1_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_1_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_1_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_1_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_1_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_1_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_1 Register PCE_PCTRL_3_1 - PCE Port 1 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_1 0x1234
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_1 0x18451234u

/*! Register Reset Value */
#define PCE_PCTRL_3_1_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_1_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_1_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_1_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_1_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_1_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_1_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_1_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_1_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_1 Register WOL_CTRL_1 - Wake-on-LAN Port 1 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_1 0x1238
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_1 0x18451238u

/*! Register Reset Value */
#define WOL_CTRL_1_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_1_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_1_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_1_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_1_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_1 Register PCE_DEFPVID_1 - PCE Default Port 1 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_1 0x1240
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_1 0x18451240u

/*! Register Reset Value */
#define PCE_DEFPVID_1_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_1_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_1_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_1 Register PCE_PIER_1 - Parser and Classification Engine Port 1 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_1 0x1248
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_1 0x18451248u

/*! Register Reset Value */
#define PCE_PIER_1_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_1_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_1_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_1_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_1_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_1_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_1_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_1_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_1_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_1_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_1_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_1_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_1_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_1_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_1_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_1_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_1_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_1_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_1_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_1_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_1_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_1 Register PCE_PISR_1 - Parser and Classification Engine Port 1 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_1 0x124C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_1 0x1845124Cu

/*! Register Reset Value */
#define PCE_PISR_1_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_1_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_1_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_1_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_1_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_1_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_1_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_1_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_1_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_1_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_1_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_1_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_1_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_1_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_1_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_1_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_1_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_1_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_1_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_1_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_1_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_1_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_1_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_2 Register PCE_PCTRL_0_2 - PCE Port 2 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_2 0x1250
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_2 0x18451250u

/*! Register Reset Value */
#define PCE_PCTRL_0_2_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_2_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_2_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_2_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_2_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_2_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_2_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_2_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_2_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_2 Register PCE_PCTRL_2_2 - PCE Port 2 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_2 0x1258
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_2 0x18451258u

/*! Register Reset Value */
#define PCE_PCTRL_2_2_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_2_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_2_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_2_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_2_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_2_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_2_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_2_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_2_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_2_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_2_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_2_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_2_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_2_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_2_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_2 Register PCE_PCTRL_3_2 - PCE Port 2 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_2 0x125C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_2 0x1845125Cu

/*! Register Reset Value */
#define PCE_PCTRL_3_2_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_2_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_2_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_2_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_2_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_2_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_2_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_2_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_2_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_2 Register WOL_CTRL_2 - Wake-on-LAN Port 2 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_2 0x1260
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_2 0x18451260u

/*! Register Reset Value */
#define WOL_CTRL_2_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_2_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_2_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_2_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_2_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_2 Register PCE_DEFPVID_2 - PCE Default Port 2 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_2 0x1268
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_2 0x18451268u

/*! Register Reset Value */
#define PCE_DEFPVID_2_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_2_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_2_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_2 Register PCE_PIER_2 - Parser and Classification Engine Port 2 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_2 0x1270
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_2 0x18451270u

/*! Register Reset Value */
#define PCE_PIER_2_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_2_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_2_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_2_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_2_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_2_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_2_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_2_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_2_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_2_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_2_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_2_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_2_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_2_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_2_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_2_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_2_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_2_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_2_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_2_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_2_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_2 Register PCE_PISR_2 - Parser and Classification Engine Port 2 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_2 0x1274
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_2 0x18451274u

/*! Register Reset Value */
#define PCE_PISR_2_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_2_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_2_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_2_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_2_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_2_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_2_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_2_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_2_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_2_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_2_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_2_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_2_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_2_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_2_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_2_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_2_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_2_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_2_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_2_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_2_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_2_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_2_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_3 Register PCE_PCTRL_0_3 - PCE Port 3 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_3 0x1278
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_3 0x18451278u

/*! Register Reset Value */
#define PCE_PCTRL_0_3_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_3_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_3_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_3_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_3_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_3_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_3_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_3_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_3_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_3 Register PCE_PCTRL_2_3 - PCE Port 3 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_3 0x1280
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_3 0x18451280u

/*! Register Reset Value */
#define PCE_PCTRL_2_3_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_3_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_3_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_3_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_3_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_3_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_3_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_3_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_3_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_3_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_3_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_3_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_3_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_3_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_3_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_3 Register PCE_PCTRL_3_3 - PCE Port 3 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_3 0x1284
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_3 0x18451284u

/*! Register Reset Value */
#define PCE_PCTRL_3_3_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_3_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_3_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_3_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_3_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_3_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_3_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_3_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_3_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_3 Register WOL_CTRL_3 - Wake-on-LAN Port 3 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_3 0x1288
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_3 0x18451288u

/*! Register Reset Value */
#define WOL_CTRL_3_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_3_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_3_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_3_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_3_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_3 Register PCE_DEFPVID_3 - PCE Default Port 3 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_3 0x1290
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_3 0x18451290u

/*! Register Reset Value */
#define PCE_DEFPVID_3_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_3_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_3_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_3 Register PCE_PIER_3 - Parser and Classification Engine Port 3 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_3 0x1298
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_3 0x18451298u

/*! Register Reset Value */
#define PCE_PIER_3_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_3_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_3_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_3_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_3_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_3_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_3_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_3_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_3_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_3_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_3_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_3_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_3_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_3_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_3_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_3_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_3_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_3_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_3_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_3_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_3_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_3 Register PCE_PISR_3 - Parser and Classification Engine Port 3 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_3 0x129C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_3 0x1845129Cu

/*! Register Reset Value */
#define PCE_PISR_3_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_3_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_3_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_3_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_3_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_3_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_3_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_3_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_3_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_3_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_3_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_3_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_3_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_3_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_3_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_3_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_3_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_3_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_3_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_3_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_3_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_3_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_3_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_4 Register PCE_PCTRL_0_4 - PCE Port 4 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_4 0x12A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_4 0x184512A0u

/*! Register Reset Value */
#define PCE_PCTRL_0_4_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_4_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_4_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_4_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_4_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_4_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_4_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_4_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_4_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_4 Register PCE_PCTRL_2_4 - PCE Port 4 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_4 0x12A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_4 0x184512A8u

/*! Register Reset Value */
#define PCE_PCTRL_2_4_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_4_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_4_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_4_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_4_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_4_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_4_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_4_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_4_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_4_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_4_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_4_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_4_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_4_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_4_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_4 Register PCE_PCTRL_3_4 - PCE Port 4 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_4 0x12AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_4 0x184512ACu

/*! Register Reset Value */
#define PCE_PCTRL_3_4_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_4_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_4_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_4_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_4_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_4_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_4_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_4_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_4_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_4 Register WOL_CTRL_4 - Wake-on-LAN Port 4 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_4 0x12B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_4 0x184512B0u

/*! Register Reset Value */
#define WOL_CTRL_4_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_4_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_4_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_4_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_4_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_4 Register PCE_DEFPVID_4 - PCE Default Port 4 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_4 0x12B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_4 0x184512B8u

/*! Register Reset Value */
#define PCE_DEFPVID_4_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_4_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_4_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_4 Register PCE_PIER_4 - Parser and Classification Engine Port 4 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_4 0x12C0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_4 0x184512C0u

/*! Register Reset Value */
#define PCE_PIER_4_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_4_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_4_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_4_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_4_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_4_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_4_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_4_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_4_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_4_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_4_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_4_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_4_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_4_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_4_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_4_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_4_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_4_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_4_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_4_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_4_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_4 Register PCE_PISR_4 - Parser and Classification Engine Port 4 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_4 0x12C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_4 0x184512C4u

/*! Register Reset Value */
#define PCE_PISR_4_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_4_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_4_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_4_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_4_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_4_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_4_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_4_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_4_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_4_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_4_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_4_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_4_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_4_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_4_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_4_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_4_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_4_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_4_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_4_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_4_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_4_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_4_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_5 Register PCE_PCTRL_0_5 - PCE Port 5 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_5 0x12C8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_5 0x184512C8u

/*! Register Reset Value */
#define PCE_PCTRL_0_5_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_5_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_5_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_5_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_5_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_5_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_5_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_5_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_5_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_5 Register PCE_PCTRL_2_5 - PCE Port 5 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_5 0x12D0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_5 0x184512D0u

/*! Register Reset Value */
#define PCE_PCTRL_2_5_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_5_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_5_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_5_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_5_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_5_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_5_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_5_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_5_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_5_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_5_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_5_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_5_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_5_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_5_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_5 Register PCE_PCTRL_3_5 - PCE Port 5 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_5 0x12D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_5 0x184512D4u

/*! Register Reset Value */
#define PCE_PCTRL_3_5_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_5_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_5_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_5_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_5_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_5_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_5_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_5_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_5_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_5 Register WOL_CTRL_5 - Wake-on-LAN Port 5 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_5 0x12D8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_5 0x184512D8u

/*! Register Reset Value */
#define WOL_CTRL_5_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_5_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_5_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_5_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_5_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_5 Register PCE_DEFPVID_5 - PCE Default Port 5 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_5 0x12E0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_5 0x184512E0u

/*! Register Reset Value */
#define PCE_DEFPVID_5_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_5_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_5_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_5 Register PCE_PIER_5 - Parser and Classification Engine Port 5 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_5 0x12E8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_5 0x184512E8u

/*! Register Reset Value */
#define PCE_PIER_5_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_5_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_5_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_5_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_5_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_5_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_5_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_5_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_5_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_5_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_5_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_5_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_5_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_5_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_5_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_5_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_5_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_5_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_5_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_5_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_5_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_5 Register PCE_PISR_5 - Parser and Classification Engine Port 5 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_5 0x12EC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_5 0x184512ECu

/*! Register Reset Value */
#define PCE_PISR_5_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_5_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_5_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_5_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_5_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_5_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_5_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_5_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_5_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_5_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_5_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_5_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_5_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_5_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_5_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_5_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_5_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_5_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_5_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_5_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_5_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_5_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_5_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_6 Register PCE_PCTRL_0_6 - PCE Port 6 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_6 0x12F0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_6 0x184512F0u

/*! Register Reset Value */
#define PCE_PCTRL_0_6_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_6_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_6_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_6_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_6_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_6_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_6_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_6_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_6_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_6 Register PCE_PCTRL_2_6 - PCE Port 6 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_6 0x12F8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_6 0x184512F8u

/*! Register Reset Value */
#define PCE_PCTRL_2_6_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_6_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_6_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_6_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_6_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_6_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_6_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_6_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_6_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_6_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_6_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_6_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_6_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_6_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_6_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_6 Register PCE_PCTRL_3_6 - PCE Port 6 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_6 0x12FC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_6 0x184512FCu

/*! Register Reset Value */
#define PCE_PCTRL_3_6_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_6_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_6_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_6_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_6_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_6_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_6_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_6_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_6_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_6 Register WOL_CTRL_6 - Wake-on-LAN Port 6 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_6 0x1300
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_6 0x18451300u

/*! Register Reset Value */
#define WOL_CTRL_6_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_6_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_6_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_6_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_6_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_6 Register PCE_DEFPVID_6 - PCE Default Port 6 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_6 0x1308
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_6 0x18451308u

/*! Register Reset Value */
#define PCE_DEFPVID_6_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_6_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_6_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_6 Register PCE_PIER_6 - Parser and Classification Engine Port 6 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_6 0x1310
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_6 0x18451310u

/*! Register Reset Value */
#define PCE_PIER_6_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_6_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_6_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_6_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_6_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_6_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_6_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_6_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_6_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_6_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_6_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_6_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_6_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_6_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_6_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_6_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_6_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_6_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_6_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_6_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_6_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_6 Register PCE_PISR_6 - Parser and Classification Engine Port 6 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_6 0x1314
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_6 0x18451314u

/*! Register Reset Value */
#define PCE_PISR_6_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_6_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_6_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_6_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_6_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_6_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_6_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_6_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_6_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_6_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_6_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_6_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_6_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_6_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_6_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_6_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_6_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_6_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_6_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_6_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_6_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_6_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_6_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_7 Register PCE_PCTRL_0_7 - PCE Port 7 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_7 0x1318
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_7 0x18451318u

/*! Register Reset Value */
#define PCE_PCTRL_0_7_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_7_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_7_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_7_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_7_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_7_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_7_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_7_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_7_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_7 Register PCE_PCTRL_2_7 - PCE Port 7 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_7 0x1320
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_7 0x18451320u

/*! Register Reset Value */
#define PCE_PCTRL_2_7_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_7_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_7_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_7_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_7_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_7_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_7_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_7_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_7_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_7_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_7_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_7_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_7_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_7_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_7_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_7 Register PCE_PCTRL_3_7 - PCE Port 7 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_7 0x1324
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_7 0x18451324u

/*! Register Reset Value */
#define PCE_PCTRL_3_7_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_7_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_7_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_7_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_7_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_7_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_7_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_7_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_7_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_7 Register WOL_CTRL_7 - Wake-on-LAN Port 7 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_7 0x1328
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_7 0x18451328u

/*! Register Reset Value */
#define WOL_CTRL_7_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_7_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_7_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_7_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_7_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_7 Register PCE_DEFPVID_7 - PCE Default Port 7 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_7 0x1330
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_7 0x18451330u

/*! Register Reset Value */
#define PCE_DEFPVID_7_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_7_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_7_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_7 Register PCE_PIER_7 - Parser and Classification Engine Port 7 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_7 0x1338
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_7 0x18451338u

/*! Register Reset Value */
#define PCE_PIER_7_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_7_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_7_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_7_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_7_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_7_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_7_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_7_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_7_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_7_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_7_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_7_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_7_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_7_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_7_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_7_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_7_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_7_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_7_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_7_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_7_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_7 Register PCE_PISR_7 - Parser and Classification Engine Port 7 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_7 0x133C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_7 0x1845133Cu

/*! Register Reset Value */
#define PCE_PISR_7_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_7_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_7_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_7_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_7_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_7_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_7_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_7_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_7_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_7_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_7_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_7_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_7_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_7_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_7_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_7_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_7_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_7_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_7_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_7_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_7_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_7_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_7_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_8 Register PCE_PCTRL_0_8 - PCE Port 8 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_8 0x1340
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_8 0x18451340u

/*! Register Reset Value */
#define PCE_PCTRL_0_8_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_8_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_8_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_8_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_8_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_8_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_8_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_8_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_8_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_8 Register PCE_PCTRL_2_8 - PCE Port 8 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_8 0x1348
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_8 0x18451348u

/*! Register Reset Value */
#define PCE_PCTRL_2_8_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_8_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_8_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_8_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_8_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_8_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_8_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_8_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_8_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_8_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_8_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_8_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_8_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_8_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_8_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_8 Register PCE_PCTRL_3_8 - PCE Port 8 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_8 0x134C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_8 0x1845134Cu

/*! Register Reset Value */
#define PCE_PCTRL_3_8_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_8_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_8_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_8_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_8_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_8_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_8_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_8_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_8_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_8 Register WOL_CTRL_8 - Wake-on-LAN Port 8 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_8 0x1350
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_8 0x18451350u

/*! Register Reset Value */
#define WOL_CTRL_8_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_8_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_8_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_8_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_8_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_8 Register PCE_DEFPVID_8 - PCE Default Port 8 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_8 0x1358
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_8 0x18451358u

/*! Register Reset Value */
#define PCE_DEFPVID_8_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_8_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_8_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_8 Register PCE_PIER_8 - Parser and Classification Engine Port 8 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_8 0x1360
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_8 0x18451360u

/*! Register Reset Value */
#define PCE_PIER_8_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_8_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_8_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_8_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_8_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_8_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_8_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_8_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_8_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_8_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_8_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_8_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_8_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_8_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_8_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_8_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_8_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_8_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_8_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_8_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_8_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_8 Register PCE_PISR_8 - Parser and Classification Engine Port 8 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_8 0x1364
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_8 0x18451364u

/*! Register Reset Value */
#define PCE_PISR_8_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_8_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_8_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_8_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_8_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_8_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_8_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_8_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_8_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_8_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_8_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_8_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_8_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_8_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_8_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_8_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_8_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_8_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_8_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_8_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_8_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_8_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_8_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_9 Register PCE_PCTRL_0_9 - PCE Port 9 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_9 0x1368
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_9 0x18451368u

/*! Register Reset Value */
#define PCE_PCTRL_0_9_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_9_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_9_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_9_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_9_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_9_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_9_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_9_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_9_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_9 Register PCE_PCTRL_2_9 - PCE Port 9 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_9 0x1370
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_9 0x18451370u

/*! Register Reset Value */
#define PCE_PCTRL_2_9_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_9_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_9_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_9_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_9_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_9_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_9_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_9_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_9_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_9_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_9_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_9_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_9_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_9_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_9_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_9 Register PCE_PCTRL_3_9 - PCE Port 9 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_9 0x1374
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_9 0x18451374u

/*! Register Reset Value */
#define PCE_PCTRL_3_9_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_9_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_9_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_9_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_9_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_9_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_9_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_9_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_9_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_9 Register WOL_CTRL_9 - Wake-on-LAN Port 9 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_9 0x1378
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_9 0x18451378u

/*! Register Reset Value */
#define WOL_CTRL_9_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_9_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_9_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_9_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_9_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_9 Register PCE_DEFPVID_9 - PCE Default Port 9 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_9 0x1380
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_9 0x18451380u

/*! Register Reset Value */
#define PCE_DEFPVID_9_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_9_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_9_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_9 Register PCE_PIER_9 - Parser and Classification Engine Port 9 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_9 0x1388
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_9 0x18451388u

/*! Register Reset Value */
#define PCE_PIER_9_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_9_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_9_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_9_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_9_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_9_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_9_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_9_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_9_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_9_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_9_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_9_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_9_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_9_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_9_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_9_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_9_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_9_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_9_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_9_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_9_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_9 Register PCE_PISR_9 - Parser and Classification Engine Port 9 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_9 0x138C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_9 0x1845138Cu

/*! Register Reset Value */
#define PCE_PISR_9_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_9_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_9_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_9_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_9_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_9_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_9_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_9_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_9_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_9_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_9_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_9_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_9_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_9_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_9_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_9_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_9_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_9_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_9_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_9_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_9_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_9_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_9_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_10 Register PCE_PCTRL_0_10 - PCE Port 10 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_10 0x1390
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_10 0x18451390u

/*! Register Reset Value */
#define PCE_PCTRL_0_10_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_10_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_10_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_10_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_10_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_10_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_10_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_10_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_10_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_10 Register PCE_PCTRL_2_10 - PCE Port 10 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_10 0x1398
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_10 0x18451398u

/*! Register Reset Value */
#define PCE_PCTRL_2_10_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_10_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_10_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_10_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_10_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_10_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_10_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_10_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_10_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_10_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_10_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_10_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_10_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_10_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_10_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_10 Register PCE_PCTRL_3_10 - PCE Port 10 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_10 0x139C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_10 0x1845139Cu

/*! Register Reset Value */
#define PCE_PCTRL_3_10_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_10_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_10_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_10_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_10_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_10_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_10_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_10_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_10_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_10 Register WOL_CTRL_10 - Wake-on-LAN Port 10 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_10 0x13A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_10 0x184513A0u

/*! Register Reset Value */
#define WOL_CTRL_10_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_10_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_10_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_10_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_10_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_10 Register PCE_DEFPVID_10 - PCE Default Port 10 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_10 0x13A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_10 0x184513A8u

/*! Register Reset Value */
#define PCE_DEFPVID_10_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_10_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_10_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_10 Register PCE_PIER_10 - Parser and Classification Engine Port 10 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_10 0x13B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_10 0x184513B0u

/*! Register Reset Value */
#define PCE_PIER_10_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_10_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_10_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_10_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_10_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_10_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_10_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_10_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_10_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_10_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_10_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_10_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_10_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_10_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_10_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_10_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_10_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_10_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_10_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_10_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_10_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_10 Register PCE_PISR_10 - Parser and Classification Engine Port 10 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_10 0x13B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_10 0x184513B4u

/*! Register Reset Value */
#define PCE_PISR_10_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_10_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_10_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_10_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_10_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_10_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_10_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_10_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_10_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_10_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_10_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_10_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_10_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_10_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_10_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_10_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_10_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_10_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_10_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_10_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_10_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_10_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_10_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_0_11 Register PCE_PCTRL_0_11 - PCE Port 11 Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_0_11 0x13B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_0_11 0x184513B8u

/*! Register Reset Value */
#define PCE_PCTRL_0_11_RST 0x00000000u

/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_11_TVM_POS 5
/*! Field TVM - Transparent VLAN Mode */
#define PCE_PCTRL_0_11_TVM_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_0_11_TVM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_0_11_TVM_EN 0x1

/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_11_IGSTEN_POS 11
/*! Field IGSTEN - Ingress Special Tag Enable */
#define PCE_PCTRL_0_11_IGSTEN_MASK 0x800u
/*! Constant NO - NO */
#define CONST_PCE_PCTRL_0_11_IGSTEN_NO 0x0
/*! Constant YES - YES */
#define CONST_PCE_PCTRL_0_11_IGSTEN_YES 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_2_11 Register PCE_PCTRL_2_11 - PCE Port 11 Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_2_11 0x13C0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_2_11 0x184513C0u

/*! Register Reset Value */
#define PCE_PCTRL_2_11_RST 0x00000000u

/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_11_PCP_POS 4
/*! Field PCP - Enable VLAN PCP to select the Class of Service */
#define PCE_PCTRL_2_11_PCP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_11_PCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_11_PCP_EN 0x1

/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_11_DSCP_POS 5
/*! Field DSCP - Enable DSCP to select the Class of Service */
#define PCE_PCTRL_2_11_DSCP_MASK 0x60u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_11_DSCP_DIS 0x0
/*! Constant UNTAG - UNTAG */
#define CONST_PCE_PCTRL_2_11_DSCP_UNTAG 0x1
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_11_DSCP_EN 0x2
/*! Constant RES - RES */
#define CONST_PCE_PCTRL_2_11_DSCP_RES 0x3

/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_11_SPCP_POS 8
/*! Field SPCP - Enable VLAN STAG PCP and DEI to select the Class of Service */
#define PCE_PCTRL_2_11_SPCP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_2_11_SPCP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_2_11_SPCP_EN 0x1

/*! @} */

/*! \defgroup PCE_PCTRL_3_11 Register PCE_PCTRL_3_11 - PCE Port 11 Control Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PCTRL_3_11 0x13C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PCTRL_3_11 0x184513C4u

/*! Register Reset Value */
#define PCE_PCTRL_3_11_RST 0x00000000u

/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_11_VIO_1_POS 1
/*! Field VIO_1 - Received Error Mirroring Enable */
#define PCE_PCTRL_3_11_VIO_1_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_11_VIO_1_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_11_VIO_1_EN 0x1

/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_11_NEW_FWD_POS 13
/*! Field NEW_FWD - New MAC-Port Association CPU Port Forwarding Enable */
#define PCE_PCTRL_3_11_NEW_FWD_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_PCE_PCTRL_3_11_NEW_FWD_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PCTRL_3_11_NEW_FWD_EN 0x1

/*! @} */

/*! \defgroup WOL_CTRL_11 Register WOL_CTRL_11 - Wake-on-LAN Port 11 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define WOL_CTRL_11 0x13C8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_WOL_CTRL_11 0x184513C8u

/*! Register Reset Value */
#define WOL_CTRL_11_RST 0x00000000u

/*! Field PORT - WoL Enable */
#define WOL_CTRL_11_PORT_POS 0
/*! Field PORT - WoL Enable */
#define WOL_CTRL_11_PORT_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_WOL_CTRL_11_PORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_WOL_CTRL_11_PORT_EN 0x1

/*! @} */

/*! \defgroup PCE_DEFPVID_11 Register PCE_DEFPVID_11 - PCE Default Port 11 VID Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_DEFPVID_11 0x13D0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_DEFPVID_11 0x184513D0u

/*! Register Reset Value */
#define PCE_DEFPVID_11_RST 0x00000000u

/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_11_PVID_POS 0
/*! Field PVID - Default Port VID VID */
#define PCE_DEFPVID_11_PVID_MASK 0xFFFu

/*! @} */

/*! \defgroup PCE_PIER_11 Register PCE_PIER_11 - Parser and Classification Engine Port 11 Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PIER_11 0x13D8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PIER_11 0x184513D8u

/*! Register Reset Value */
#define PCE_PIER_11_RST 0x00000000u

/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_11_LIM_POS 0
/*! Field LIM - Port Limit Alert Interrupt Enable */
#define PCE_PIER_11_LIM_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_LIM_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_LIM_EN 0x1

/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_11_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt Enable */
#define PCE_PIER_11_LOCK_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_LOCK_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_LOCK_EN 0x1

/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_11_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt Enable */
#define PCE_PIER_11_WOL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_WOL_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_WOL_EN 0x1

/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_11_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt Enable */
#define PCE_PIER_11_VLAN_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_VLAN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_VLAN_EN 0x1

/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_11_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt Enable */
#define PCE_PIER_11_PTDRP_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_PTDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_PTDRP_EN 0x1

/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_11_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt Enable */
#define PCE_PIER_11_CLDRP_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_CLDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_CLDRP_EN 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_11_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt Enable */
#define PCE_PIER_11_FRZDRP_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_FRZDRP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_FRZDRP_EN 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_11_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt Enable */
#define PCE_PIER_11_SPFINT_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_SPFINT_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_SPFINT_EN 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_11_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt Enable */
#define PCE_PIER_11_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PIER_11_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PIER_11_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PISR_11 Register PCE_PISR_11 - Parser and Classification Engine Port 11 Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PISR_11 0x13DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PISR_11 0x184513DCu

/*! Register Reset Value */
#define PCE_PISR_11_RST 0x00000000u

/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_11_LIMIT_POS 0
/*! Field LIMIT - Port Limitation Alert Interrupt */
#define PCE_PISR_11_LIMIT_MASK 0x1u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_LIMIT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_LIMIT_INT 0x1

/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_11_LOCK_POS 1
/*! Field LOCK - Port Lock Alert Interrupt */
#define PCE_PISR_11_LOCK_MASK 0x2u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_LOCK_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_LOCK_INT 0x1

/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_11_WOL_POS 2
/*! Field WOL - Wake-on-LAN Interrupt */
#define PCE_PISR_11_WOL_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_WOL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_WOL_INT 0x1

/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_11_VLAN_POS 3
/*! Field VLAN - VLAN Violation Interrupt */
#define PCE_PISR_11_VLAN_MASK 0x8u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_VLAN_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_VLAN_INT 0x1

/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_11_PTDRP_POS 4
/*! Field PTDRP - Port Drop Interrupt */
#define PCE_PISR_11_PTDRP_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_PTDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_PTDRP_INT 0x1

/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_11_CLDRP_POS 5
/*! Field CLDRP - Classification Drop Interrupt */
#define PCE_PISR_11_CLDRP_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_CLDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_CLDRP_INT 0x1

/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_11_FRZDRP_POS 6
/*! Field FRZDRP - MAC Table Freeze Drop Interrupt */
#define PCE_PISR_11_FRZDRP_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_FRZDRP_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_FRZDRP_INT 0x1

/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_11_SPFINT_POS 7
/*! Field SPFINT - Port Spoofing Alert Interrupt */
#define PCE_PISR_11_SPFINT_MASK 0x80u
/*! Constant NOINT - NOINT */
#define CONST_PCE_PISR_11_SPFINT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_PCE_PISR_11_SPFINT_INT 0x1

/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_11_MTEBP_POS 8
/*! Field MTEBP - Metering Based Backpressure Status Change Interrupt */
#define PCE_PISR_11_MTEBP_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_PCE_PISR_11_MTEBP_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PISR_11_MTEBP_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK Register PCE_PTRUNK - PCE Port Trunking Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK 0x1484
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK 0x18451484u

/*! Register Reset Value */
#define PCE_PTRUNK_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_1 Register PCE_PTRUNK_1 - PCE Port 1 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_1 0x148C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_1 0x1845148Cu

/*! Register Reset Value */
#define PCE_PTRUNK_1_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_1_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_1_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_1_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_1_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_1_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_1_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_2 Register PCE_PTRUNK_2 - PCE Port 2 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_2 0x1494
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_2 0x18451494u

/*! Register Reset Value */
#define PCE_PTRUNK_2_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_2_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_2_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_2_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_2_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_2_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_2_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_3 Register PCE_PTRUNK_3 - PCE Port 3 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_3 0x149C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_3 0x1845149Cu

/*! Register Reset Value */
#define PCE_PTRUNK_3_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_3_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_3_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_3_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_3_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_3_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_3_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_4 Register PCE_PTRUNK_4 - PCE Port 4 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_4 0x14A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_4 0x184514A4u

/*! Register Reset Value */
#define PCE_PTRUNK_4_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_4_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_4_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_4_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_4_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_4_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_4_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_5 Register PCE_PTRUNK_5 - PCE Port 5 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_5 0x14AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_5 0x184514ACu

/*! Register Reset Value */
#define PCE_PTRUNK_5_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_5_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_5_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_5_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_5_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_5_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_5_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_6 Register PCE_PTRUNK_6 - PCE Port 6 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_6 0x14B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_6 0x184514B4u

/*! Register Reset Value */
#define PCE_PTRUNK_6_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_6_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_6_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_6_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_6_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_6_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_6_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_7 Register PCE_PTRUNK_7 - PCE Port 7 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_7 0x14BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_7 0x184514BCu

/*! Register Reset Value */
#define PCE_PTRUNK_7_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_7_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_7_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_7_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_7_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_7_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_7_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_8 Register PCE_PTRUNK_8 - PCE Port 8 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_8 0x14C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_8 0x184514C4u

/*! Register Reset Value */
#define PCE_PTRUNK_8_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_8_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_8_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_8_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_8_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_8_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_8_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_9 Register PCE_PTRUNK_9 - PCE Port 9 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_9 0x14CC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_9 0x184514CCu

/*! Register Reset Value */
#define PCE_PTRUNK_9_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_9_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_9_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_9_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_9_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_9_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_9_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_10 Register PCE_PTRUNK_10 - PCE Port 10 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_10 0x14D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_10 0x184514D4u

/*! Register Reset Value */
#define PCE_PTRUNK_10_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_10_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_10_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_10_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_10_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_10_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_10_EN_EN 0x1

/*! @} */

/*! \defgroup PCE_PTRUNK_11 Register PCE_PTRUNK_11 - PCE Port 11 Trunk Register */
/*! @{ */

/*! Register Offset (relative) */
#define PCE_PTRUNK_11 0x14DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_PCE_PTRUNK_11 0x184514DCu

/*! Register Reset Value */
#define PCE_PTRUNK_11_RST 0x00000000u

/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_11_PARTER_POS 0
/*! Field PARTER - Port Trunking Partner Port ID */
#define PCE_PTRUNK_11_PARTER_MASK 0xFu

/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_11_EN_POS 15
/*! Field EN - Port Trunking Enable */
#define PCE_PTRUNK_11_EN_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_PCE_PTRUNK_11_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_PCE_PTRUNK_11_EN_EN 0x1

/*! @} */

/*! \defgroup BM_TXBPFLOW_RMON Register BM_TXBPFLOW_RMON - TX PCE-Bypass Traffic Flow RMON Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define BM_TXBPFLOW_RMON 0x1904
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_BM_TXBPFLOW_RMON 0x18451904u

/*! Register Reset Value */
#define BM_TXBPFLOW_RMON_RST 0x00000000u

/*! Field MSB - TX Traffic Flow CTP Port MSB */
#define BM_TXBPFLOW_RMON_MSB_POS 3
/*! Field MSB - TX Traffic Flow CTP Port MSB */
#define BM_TXBPFLOW_RMON_MSB_MASK 0x1F8u

/*! Field LSB - TX Traffic Flow RMON Counting LSB Configuration */
#define BM_TXBPFLOW_RMON_LSB_POS 9
/*! Field LSB - TX Traffic Flow RMON Counting LSB Configuration */
#define BM_TXBPFLOW_RMON_LSB_MASK 0xE00u

/*! Field MD - TX Traffic Flow RMON Counting Mode */
#define BM_TXBPFLOW_RMON_MD_POS 14
/*! Field MD - TX Traffic Flow RMON Counting Mode */
#define BM_TXBPFLOW_RMON_MD_MASK 0xC000u
/*! Constant GL - GL */
#define CONST_BM_TXBPFLOW_RMON_MD_GL 0x0
/*! Constant LPORT - LPORT */
#define CONST_BM_TXBPFLOW_RMON_MD_LPORT 0x1
/*! Constant CTP - CTP */
#define CONST_BM_TXBPFLOW_RMON_MD_CTP 0x2

/*! @} */

/*! \defgroup FDMA_CTRL Register FDMA_CTRL - Ethernet Switch Fetch DMA Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_CTRL 0x2900
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_CTRL 0x18452900u

/*! Register Reset Value */
#define FDMA_CTRL_RST 0x00000040u

/*! Field LPI_MODE - Low Power Idle Mode */
#define FDMA_CTRL_LPI_MODE_POS 4
/*! Field LPI_MODE - Low Power Idle Mode */
#define FDMA_CTRL_LPI_MODE_MASK 0x70u
/*! Constant DIS - DIS */
#define CONST_FDMA_CTRL_LPI_MODE_DIS 0x0
/*! Constant EN_FORCE - EN_FORCE */
#define CONST_FDMA_CTRL_LPI_MODE_EN_FORCE 0x1
/*! Constant EN_SSB - EN_SSB */
#define CONST_FDMA_CTRL_LPI_MODE_EN_SSB 0x2
/*! Constant RES3 - RES3 */
#define CONST_FDMA_CTRL_LPI_MODE_RES3 0x3
/*! Constant EN_QUEUE - EN_QUEUE */
#define CONST_FDMA_CTRL_LPI_MODE_EN_QUEUE 0x4
/*! Constant RES5 - RES5 */
#define CONST_FDMA_CTRL_LPI_MODE_RES5 0x5
/*! Constant RES6 - RES6 */
#define CONST_FDMA_CTRL_LPI_MODE_RES6 0x6
/*! Constant RES7 - RES7 */
#define CONST_FDMA_CTRL_LPI_MODE_RES7 0x7

/*! @} */

/*! \defgroup FDMA_STETYPE Register FDMA_STETYPE - Special Tag Ethertype Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_STETYPE 0x2904
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_STETYPE 0x18452904u

/*! Register Reset Value */
#define FDMA_STETYPE_RST 0x000088C3u

/*! Field ETYPE - Special Tag Ethertype */
#define FDMA_STETYPE_ETYPE_POS 0
/*! Field ETYPE - Special Tag Ethertype */
#define FDMA_STETYPE_ETYPE_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_VTETYPE Register FDMA_VTETYPE - VLAN Tag Ethertype 1 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_VTETYPE 0x2908
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_VTETYPE 0x18452908u

/*! Register Reset Value */
#define FDMA_VTETYPE_RST 0x000088A8u

/*! Field ETYPE - VLAN Tag Ethertype */
#define FDMA_VTETYPE_ETYPE_POS 0
/*! Field ETYPE - VLAN Tag Ethertype */
#define FDMA_VTETYPE_ETYPE_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_STAT_0 Register FDMA_STAT_0 - FDMA Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_STAT_0 0x290C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_STAT_0 0x1845290Cu

/*! Register Reset Value */
#define FDMA_STAT_0_RST 0x00000000u

/*! Field FSMS - FSM states status */
#define FDMA_STAT_0_FSMS_POS 0
/*! Field FSMS - FSM states status */
#define FDMA_STAT_0_FSMS_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_IER Register FDMA_IER - Fetch DMA Global Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_IER 0x2910
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_IER 0x18452910u

/*! Register Reset Value */
#define FDMA_IER_RST 0x00000000u

/*! Field PCKT - Packet Sent Interrupt Enable */
#define FDMA_IER_PCKT_POS 0
/*! Field PCKT - Packet Sent Interrupt Enable */
#define FDMA_IER_PCKT_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_ISR Register FDMA_ISR - Fetch DMA Global Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_ISR 0x2914
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_ISR 0x18452914u

/*! Register Reset Value */
#define FDMA_ISR_RST 0x00000000u

/*! Field PCKT - Packet Sent Event */
#define FDMA_ISR_PCKT_POS 0
/*! Field PCKT - Packet Sent Event */
#define FDMA_ISR_PCKT_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_PASR Register FDMA_PASR - Fetch DMA Parsing Result Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PASR 0x291C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PASR 0x1845291Cu

/*! Register Reset Value */
#define FDMA_PASR_RST 0x00000000u

/*! Field CPU - Parsing Results to CPU Port */
#define FDMA_PASR_CPU_POS 0
/*! Field CPU - Parsing Results to CPU Port */
#define FDMA_PASR_CPU_MASK 0x3u
/*! Constant NIL - NIL */
#define CONST_FDMA_PASR_CPU_NIL 0x0
/*! Constant FLAG - FLAG */
#define CONST_FDMA_PASR_CPU_FLAG 0x1
/*! Constant ALL - ALL */
#define CONST_FDMA_PASR_CPU_ALL 0x2
/*! Constant RES - Res */
#define CONST_FDMA_PASR_CPU_RES 0x3

/*! Field MPE1 - Parsing Results to CPU Port MPE1 */
#define FDMA_PASR_MPE1_POS 2
/*! Field MPE1 - Parsing Results to CPU Port MPE1 */
#define FDMA_PASR_MPE1_MASK 0xCu
/*! Constant NIL - NIL */
#define CONST_FDMA_PASR_MPE1_NIL 0x0
/*! Constant FLAG - FLAG */
#define CONST_FDMA_PASR_MPE1_FLAG 0x1
/*! Constant ALL - ALL */
#define CONST_FDMA_PASR_MPE1_ALL 0x2
/*! Constant RES - Res */
#define CONST_FDMA_PASR_MPE1_RES 0x3

/*! Field MPE2 - Parsing Results to CPU Port MPE2 */
#define FDMA_PASR_MPE2_POS 4
/*! Field MPE2 - Parsing Results to CPU Port MPE2 */
#define FDMA_PASR_MPE2_MASK 0x30u
/*! Constant NIL - NIL */
#define CONST_FDMA_PASR_MPE2_NIL 0x0
/*! Constant FLAG - FLAG */
#define CONST_FDMA_PASR_MPE2_FLAG 0x1
/*! Constant ALL - ALL */
#define CONST_FDMA_PASR_MPE2_ALL 0x2
/*! Constant RES - RES */
#define CONST_FDMA_PASR_MPE2_RES 0x3

/*! Field MPE3 - Parsing Results to CPU Port MPE3 */
#define FDMA_PASR_MPE3_POS 6
/*! Field MPE3 - Parsing Results to CPU Port MPE3 */
#define FDMA_PASR_MPE3_MASK 0xC0u
/*! Constant NIL - NIL */
#define CONST_FDMA_PASR_MPE3_NIL 0x0
/*! Constant FLAG - FLAG */
#define CONST_FDMA_PASR_MPE3_FLAG 0x1
/*! Constant ALL - ALL */
#define CONST_FDMA_PASR_MPE3_ALL 0x2
/*! Constant RES - RES */
#define CONST_FDMA_PASR_MPE3_RES 0x3

/*! @} */

/*! \defgroup FDMA_IER_1 Register FDMA_IER_1 - Fetch DMA Global Interrupt Enable Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_IER_1 0x2920
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_IER_1 0x18452920u

/*! Register Reset Value */
#define FDMA_IER_1_RST 0x00000000u

/*! Field PCKR - Packet Ready Interrupt Enable */
#define FDMA_IER_1_PCKR_POS 13
/*! Field PCKR - Packet Ready Interrupt Enable */
#define FDMA_IER_1_PCKR_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_FDMA_IER_1_PCKR_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_IER_1_PCKR_EN 0x1

/*! @} */

/*! \defgroup FDMA_ISR_1 Register FDMA_ISR_1 - Fetch DMA Global Interrupt Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_ISR_1 0x2924
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_ISR_1 0x18452924u

/*! Register Reset Value */
#define FDMA_ISR_1_RST 0x00000000u

/*! Field PCKR - Packet is Ready for Transmission */
#define FDMA_ISR_1_PCKR_POS 13
/*! Field PCKR - Packet is Ready for Transmission */
#define FDMA_ISR_1_PCKR_MASK 0x2000u
/*! Constant NOINT - NOINT */
#define CONST_FDMA_ISR_1_PCKR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_FDMA_ISR_1_PCKR_INT 0x1

/*! @} */

/*! \defgroup FDMA_SA_0 Register FDMA_SA_0 - Fetch DMA Source MAC Address 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_SA_0 0x2940
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_SA_0 0x18452940u

/*! Register Reset Value */
#define FDMA_SA_0_RST 0x00000000u

/*! Field ADDR - Source MAC Address Bit 15 to 0 */
#define FDMA_SA_0_ADDR_POS 0
/*! Field ADDR - Source MAC Address Bit 15 to 0 */
#define FDMA_SA_0_ADDR_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_SA_1 Register FDMA_SA_1 - Fetch DMA Source MAC Address 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_SA_1 0x2944
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_SA_1 0x18452944u

/*! Register Reset Value */
#define FDMA_SA_1_RST 0x00000000u

/*! Field ADDR - Source MAC Address Bit 31 to 16 */
#define FDMA_SA_1_ADDR_POS 0
/*! Field ADDR - Source MAC Address Bit 31 to 16 */
#define FDMA_SA_1_ADDR_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_SA_2 Register FDMA_SA_2 - Fetch DMA Source MAC Address 2 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_SA_2 0x2948
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_SA_2 0x18452948u

/*! Register Reset Value */
#define FDMA_SA_2_RST 0x00000000u

/*! Field ADDR - Source MAC Address Bit 47 to 32 */
#define FDMA_SA_2_ADDR_POS 0
/*! Field ADDR - Source MAC Address Bit 47 to 32 */
#define FDMA_SA_2_ADDR_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_ADD0_LSB Register FDMA_DELAYOAM_ADD0_LSB - Fetch DMA Delay OAM Add Compensation 0 LSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_ADD0_LSB 0x2960
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_ADD0_LSB 0x18452960u

/*! Register Reset Value */
#define FDMA_DELAYOAM_ADD0_LSB_RST 0x00000000u

/*! Field COMPLSB - LSB for Add Compensation 0 */
#define FDMA_DELAYOAM_ADD0_LSB_COMPLSB_POS 0
/*! Field COMPLSB - LSB for Add Compensation 0 */
#define FDMA_DELAYOAM_ADD0_LSB_COMPLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_ADD0_MSB Register FDMA_DELAYOAM_ADD0_MSB - Fetch DMA Delay OAM Add Compensation 0 MSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_ADD0_MSB 0x2964
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_ADD0_MSB 0x18452964u

/*! Register Reset Value */
#define FDMA_DELAYOAM_ADD0_MSB_RST 0x00000000u

/*! Field COMPMSB - MSB for Add Compensation 0 */
#define FDMA_DELAYOAM_ADD0_MSB_COMPMSB_POS 0
/*! Field COMPMSB - MSB for Add Compensation 0 */
#define FDMA_DELAYOAM_ADD0_MSB_COMPMSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_ADD1_LSB Register FDMA_DELAYOAM_ADD1_LSB - Fetch DMA Delay OAM Add Compensation 1 LSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_ADD1_LSB 0x2968
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_ADD1_LSB 0x18452968u

/*! Register Reset Value */
#define FDMA_DELAYOAM_ADD1_LSB_RST 0x00000000u

/*! Field COMPLSB - LSB for Add Compensation 1 */
#define FDMA_DELAYOAM_ADD1_LSB_COMPLSB_POS 0
/*! Field COMPLSB - LSB for Add Compensation 1 */
#define FDMA_DELAYOAM_ADD1_LSB_COMPLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_ADD1_MSB Register FDMA_DELAYOAM_ADD1_MSB - Fetch DMA Delay OAM Add Compensation 1 MSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_ADD1_MSB 0x296C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_ADD1_MSB 0x1845296Cu

/*! Register Reset Value */
#define FDMA_DELAYOAM_ADD1_MSB_RST 0x00000000u

/*! Field COMPMSB - MSB for Add Compensation 1 */
#define FDMA_DELAYOAM_ADD1_MSB_COMPMSB_POS 0
/*! Field COMPMSB - MSB for Add Compensation 1 */
#define FDMA_DELAYOAM_ADD1_MSB_COMPMSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_SUB0_LSB Register FDMA_DELAYOAM_SUB0_LSB - Fetch DMA Delay OAM Substract Compensation 0 LSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_SUB0_LSB 0x2970
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_SUB0_LSB 0x18452970u

/*! Register Reset Value */
#define FDMA_DELAYOAM_SUB0_LSB_RST 0x00000000u

/*! Field COMPLSB - LSB for Substract Compensation 0 */
#define FDMA_DELAYOAM_SUB0_LSB_COMPLSB_POS 0
/*! Field COMPLSB - LSB for Substract Compensation 0 */
#define FDMA_DELAYOAM_SUB0_LSB_COMPLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_SUB0_MSB Register FDMA_DELAYOAM_SUB0_MSB - Fetch DMA Delay OAM Substract Compensation 0 MSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_SUB0_MSB 0x2974
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_SUB0_MSB 0x18452974u

/*! Register Reset Value */
#define FDMA_DELAYOAM_SUB0_MSB_RST 0x00000000u

/*! Field COMPMSB - MSB for Substract Compensation 0 */
#define FDMA_DELAYOAM_SUB0_MSB_COMPMSB_POS 0
/*! Field COMPMSB - MSB for Substract Compensation 0 */
#define FDMA_DELAYOAM_SUB0_MSB_COMPMSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_SUB1_LSB Register FDMA_DELAYOAM_SUB1_LSB - Fetch DMA Delay OAM Substract Compensation 1 LSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_SUB1_LSB 0x2978
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_SUB1_LSB 0x18452978u

/*! Register Reset Value */
#define FDMA_DELAYOAM_SUB1_LSB_RST 0x00000000u

/*! Field COMPLSB - LSB for Substract Compensation 1 */
#define FDMA_DELAYOAM_SUB1_LSB_COMPLSB_POS 0
/*! Field COMPLSB - LSB for Substract Compensation 1 */
#define FDMA_DELAYOAM_SUB1_LSB_COMPLSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_SUB1_MSB Register FDMA_DELAYOAM_SUB1_MSB - Fetch DMA Delay OAM Substract Compensation 1 MSB */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_SUB1_MSB 0x297C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_SUB1_MSB 0x1845297Cu

/*! Register Reset Value */
#define FDMA_DELAYOAM_SUB1_MSB_RST 0x00000000u

/*! Field COMPMSB - MSB for Substract Compensation 1 */
#define FDMA_DELAYOAM_SUB1_MSB_COMPMSB_POS 0
/*! Field COMPMSB - MSB for Substract Compensation 1 */
#define FDMA_DELAYOAM_SUB1_MSB_COMPMSB_MASK 0xFFFFu

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE0 Register FDMA_DELAYOAM_TYPE0 - Fetch DMA Delay OAM Type 0 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE0 0x2980
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE0 0x18452980u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE0_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE0_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE0_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE0_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE0_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE0_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE0_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE0_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE0_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE0_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE0_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE0_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE0_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE1 Register FDMA_DELAYOAM_TYPE1 - Fetch DMA Delay OAM Type 1 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE1 0x2984
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE1 0x18452984u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE1_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE1_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE1_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE1_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE1_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE1_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE1_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE1_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE1_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE1_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE1_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE1_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE1_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE2 Register FDMA_DELAYOAM_TYPE2 - Fetch DMA Delay OAM Type 2 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE2 0x2988
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE2 0x18452988u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE2_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE2_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE2_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE2_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE2_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE2_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE2_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE2_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE2_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE2_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE2_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE2_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE2_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE3 Register FDMA_DELAYOAM_TYPE3 - Fetch DMA Delay OAM Type 3 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE3 0x298C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE3 0x1845298Cu

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE3_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE3_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE3_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE3_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE3_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE3_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE3_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE3_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE3_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE3_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE3_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE3_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE3_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE4 Register FDMA_DELAYOAM_TYPE4 - Fetch DMA Delay OAM Type 4 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE4 0x2990
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE4 0x18452990u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE4_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE4_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE4_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE4_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE4_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE4_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE4_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE4_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE4_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE4_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE4_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE4_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE4_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE5 Register FDMA_DELAYOAM_TYPE5 - Fetch DMA Delay OAM Type 5 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE5 0x2994
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE5 0x18452994u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE5_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE5_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE5_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE5_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE5_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE5_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE5_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE5_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE5_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE5_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE5_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE5_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE5_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE6 Register FDMA_DELAYOAM_TYPE6 - Fetch DMA Delay OAM Type 6 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE6 0x2998
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE6 0x18452998u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE6_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE6_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE6_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE6_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE6_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE6_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE6_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE6_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE6_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE6_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE6_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE6_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE6_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE7 Register FDMA_DELAYOAM_TYPE7 - Fetch DMA Delay OAM Type 7 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE7 0x299C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE7 0x1845299Cu

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE7_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE7_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE7_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE7_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE7_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE7_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE7_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE7_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE7_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE7_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE7_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE7_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE7_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE8 Register FDMA_DELAYOAM_TYPE8 - Fetch DMA Delay OAM Type 8 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE8 0x29A0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE8 0x184529A0u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE8_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE8_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE8_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE8_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE8_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE8_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE8_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE8_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE8_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE8_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE8_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE8_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE8_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE9 Register FDMA_DELAYOAM_TYPE9 - Fetch DMA Delay OAM Type 9 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE9 0x29A4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE9 0x184529A4u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE9_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE9_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE9_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE9_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE9_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE9_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE9_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE9_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE9_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE9_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE9_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE9_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE9_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE10 Register FDMA_DELAYOAM_TYPE10 - Fetch DMA Delay OAM Type 10 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE10 0x29A8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE10 0x184529A8u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE10_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE10_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE10_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE10_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE10_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE10_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE10_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE10_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE10_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE10_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE10_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE10_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE10_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE11 Register FDMA_DELAYOAM_TYPE11 - Fetch DMA Delay OAM Type 11 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE11 0x29AC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE11 0x184529ACu

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE11_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE11_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE11_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE11_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE11_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE11_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE11_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE11_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE11_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE11_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE11_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE11_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE11_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE12 Register FDMA_DELAYOAM_TYPE12 - Fetch DMA Delay OAM Type 12 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE12 0x29B0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE12 0x184529B0u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE12_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE12_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE12_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE12_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE12_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE12_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE12_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE12_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE12_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE12_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE12_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE12_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE12_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE13 Register FDMA_DELAYOAM_TYPE13 - Fetch DMA Delay OAM Type 13 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE13 0x29B4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE13 0x184529B4u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE13_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE13_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE13_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE13_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE13_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE13_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE13_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE13_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE13_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE13_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE13_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE13_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE13_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE14 Register FDMA_DELAYOAM_TYPE14 - Fetch DMA Delay OAM Type 14 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE14 0x29B8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE14 0x184529B8u

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE14_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE14_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE14_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE14_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE14_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE14_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE14_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE14_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE14_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE14_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE14_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE14_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE14_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_DELAYOAM_TYPE15 Register FDMA_DELAYOAM_TYPE15 - Fetch DMA Delay OAM Type 15 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_DELAYOAM_TYPE15 0x29BC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_DELAYOAM_TYPE15 0x184529BCu

/*! Register Reset Value */
#define FDMA_DELAYOAM_TYPE15_RST 0x00000000u

/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE15_BYTEOFF_POS 0
/*! Field BYTEOFF - Time Stamp Byte Offset Relative to Ethernet Type Field */
#define FDMA_DELAYOAM_TYPE15_BYTEOFF_MASK 0xFFu

/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE15_COMPTYPE_POS 8
/*! Field COMPTYPE - Compensation Type */
#define FDMA_DELAYOAM_TYPE15_COMPTYPE_MASK 0x300u
/*! Constant ADD0 - ADD0 */
#define CONST_FDMA_DELAYOAM_TYPE15_COMPTYPE_ADD0 0x0
/*! Constant ADD1 - ADD1 */
#define CONST_FDMA_DELAYOAM_TYPE15_COMPTYPE_ADD1 0x1
/*! Constant SUB0 - SUB0 */
#define CONST_FDMA_DELAYOAM_TYPE15_COMPTYPE_SUB0 0x2
/*! Constant SUB1 - SUB1 */
#define CONST_FDMA_DELAYOAM_TYPE15_COMPTYPE_SUB1 0x3

/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE15_PATH_POS 15
/*! Field PATH - Time Stamp Insertion Path */
#define FDMA_DELAYOAM_TYPE15_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_DELAYOAM_TYPE15_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_DELAYOAM_TYPE15_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE0 Register FDMA_LOSSOAM_TYPE0 - Fetch DMA LOSS OAM Type 0 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE0 0x29C0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE0 0x184529C0u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE0_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE0_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE0_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE0_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE0_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE0_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE0_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE0_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE0_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE0_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE0_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE1 Register FDMA_LOSSOAM_TYPE1 - Fetch DMA LOSS OAM Type 1 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE1 0x29C4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE1 0x184529C4u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE1_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE1_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE1_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE1_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE1_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE1_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE1_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE1_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE1_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE1_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE1_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE2 Register FDMA_LOSSOAM_TYPE2 - Fetch DMA LOSS OAM Type 2 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE2 0x29C8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE2 0x184529C8u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE2_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE2_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE2_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE2_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE2_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE2_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE2_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE2_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE2_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE2_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE2_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE3 Register FDMA_LOSSOAM_TYPE3 - Fetch DMA LOSS OAM Type 3 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE3 0x29CC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE3 0x184529CCu

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE3_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE3_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE3_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE3_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE3_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE3_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE3_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE3_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE3_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE3_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE3_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE4 Register FDMA_LOSSOAM_TYPE4 - Fetch DMA LOSS OAM Type 4 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE4 0x29D0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE4 0x184529D0u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE4_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE4_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE4_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE4_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE4_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE4_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE4_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE4_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE4_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE4_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE4_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE5 Register FDMA_LOSSOAM_TYPE5 - Fetch DMA LOSS OAM Type 5 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE5 0x29D4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE5 0x184529D4u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE5_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE5_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE5_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE5_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE5_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE5_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE5_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE5_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE5_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE5_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE5_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE6 Register FDMA_LOSSOAM_TYPE6 - Fetch DMA LOSS OAM Type 6 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE6 0x29D8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE6 0x184529D8u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE6_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE6_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE6_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE6_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE6_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE6_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE6_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE6_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE6_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE6_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE6_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE7 Register FDMA_LOSSOAM_TYPE7 - Fetch DMA LOSS OAM Type 7 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE7 0x29DC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE7 0x184529DCu

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE7_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE7_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE7_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE7_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE7_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE7_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE7_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE7_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE7_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE7_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE7_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE8 Register FDMA_LOSSOAM_TYPE8 - Fetch DMA LOSS OAM Type 8 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE8 0x29E0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE8 0x184529E0u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE8_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE8_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE8_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE8_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE8_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE8_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE8_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE8_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE8_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE8_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE8_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE9 Register FDMA_LOSSOAM_TYPE9 - Fetch DMA LOSS OAM Type 9 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE9 0x29E4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE9 0x184529E4u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE9_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE9_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE9_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE9_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE9_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE9_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE9_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE9_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE9_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE9_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE9_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE10 Register FDMA_LOSSOAM_TYPE10 - Fetch DMA LOSS OAM Type 10 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE10 0x29E8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE10 0x184529E8u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE10_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE10_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE10_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE10_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE10_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE10_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE10_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE10_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE10_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE10_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE10_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE11 Register FDMA_LOSSOAM_TYPE11 - Fetch DMA LOSS OAM Type 11 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE11 0x29EC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE11 0x184529ECu

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE11_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE11_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE11_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE11_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE11_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE11_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE11_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE11_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE11_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE11_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE11_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE12 Register FDMA_LOSSOAM_TYPE12 - Fetch DMA LOSS OAM Type 12 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE12 0x29F0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE12 0x184529F0u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE12_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE12_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE12_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE12_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE12_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE12_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE12_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE12_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE12_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE12_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE12_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE13 Register FDMA_LOSSOAM_TYPE13 - Fetch DMA LOSS OAM Type 13 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE13 0x29F4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE13 0x184529F4u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE13_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE13_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE13_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE13_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE13_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE13_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE13_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE13_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE13_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE13_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE13_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE14 Register FDMA_LOSSOAM_TYPE14 - Fetch DMA LOSS OAM Type 14 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE14 0x29F8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE14 0x184529F8u

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE14_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE14_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE14_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE14_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE14_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE14_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE14_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE14_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE14_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE14_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE14_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_LOSSOAM_TYPE15 Register FDMA_LOSSOAM_TYPE15 - Fetch DMA LOSS OAM Type 15 Configuration */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_LOSSOAM_TYPE15 0x29FC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_LOSSOAM_TYPE15 0x184529FCu

/*! Register Reset Value */
#define FDMA_LOSSOAM_TYPE15_RST 0x00000000u

/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE15_BYTEOFF_POS 0
/*! Field BYTEOFF - Counter Byte Offset Relative to Ethernet Type Field */
#define FDMA_LOSSOAM_TYPE15_BYTEOFF_MASK 0xFFu

/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE15_CNT_TYPE_POS 8
/*! Field CNT_TYPE - Counter Type */
#define FDMA_LOSSOAM_TYPE15_CNT_TYPE_MASK 0x100u
/*! Constant RX - RX */
#define CONST_FDMA_LOSSOAM_TYPE15_CNT_TYPE_RX 0x0
/*! Constant TX - TX */
#define CONST_FDMA_LOSSOAM_TYPE15_CNT_TYPE_TX 0x1

/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE15_PATH_POS 15
/*! Field PATH - Counter Insertion Path */
#define FDMA_LOSSOAM_TYPE15_PATH_MASK 0x8000u
/*! Constant BEF - BEF */
#define CONST_FDMA_LOSSOAM_TYPE15_PATH_BEF 0x0
/*! Constant AFT - AFT */
#define CONST_FDMA_LOSSOAM_TYPE15_PATH_AFT 0x1

/*! @} */

/*! \defgroup FDMA_PCTRL Register FDMA_PCTRL - Ethernet Switch Fetch DMA Port Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL 0x2A00
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL 0x18452A00u

/*! Register Reset Value */
#define FDMA_PCTRL_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0 Register FDMA_PSTAT0 - Ethernet Switch Fetch DMA Port Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0 0x2A08
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0 0x18452A08u

/*! Register Reset Value */
#define FDMA_PSTAT0_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1 Register FDMA_PSTAT1 - Ethernet Switch Fetch DMA Port Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1 0x2A0C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1 0x18452A0Cu

/*! Register Reset Value */
#define FDMA_PSTAT1_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_1 Register FDMA_PCTRL_1 - Ethernet Switch Fetch DMA Port 1 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_1 0x2A18
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_1 0x18452A18u

/*! Register Reset Value */
#define FDMA_PCTRL_1_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_1_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_1_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_1_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_1_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_1_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_1_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_1_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_1_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_1_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_1_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_1_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_1_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_1_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_1_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_1_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_1_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_1 Register FDMA_PSTAT0_1 - Ethernet Switch Fetch DMA Port 1 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_1 0x2A20
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_1 0x18452A20u

/*! Register Reset Value */
#define FDMA_PSTAT0_1_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_1_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_1_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_1_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_1_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_1_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_1_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_1_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_1_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_1 Register FDMA_PSTAT1_1 - Ethernet Switch Fetch DMA Port 1 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_1 0x2A24
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_1 0x18452A24u

/*! Register Reset Value */
#define FDMA_PSTAT1_1_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_1_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_1_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_2 Register FDMA_PCTRL_2 - Ethernet Switch Fetch DMA Port 2 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_2 0x2A30
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_2 0x18452A30u

/*! Register Reset Value */
#define FDMA_PCTRL_2_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_2_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_2_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_2_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_2_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_2_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_2_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_2_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_2_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_2_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_2_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_2_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_2_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_2_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_2_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_2_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_2_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_2 Register FDMA_PSTAT0_2 - Ethernet Switch Fetch DMA Port 2 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_2 0x2A38
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_2 0x18452A38u

/*! Register Reset Value */
#define FDMA_PSTAT0_2_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_2_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_2_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_2_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_2_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_2_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_2_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_2_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_2_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_2 Register FDMA_PSTAT1_2 - Ethernet Switch Fetch DMA Port 2 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_2 0x2A3C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_2 0x18452A3Cu

/*! Register Reset Value */
#define FDMA_PSTAT1_2_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_2_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_2_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_3 Register FDMA_PCTRL_3 - Ethernet Switch Fetch DMA Port 3 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_3 0x2A48
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_3 0x18452A48u

/*! Register Reset Value */
#define FDMA_PCTRL_3_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_3_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_3_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_3_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_3_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_3_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_3_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_3_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_3_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_3_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_3_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_3_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_3_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_3_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_3_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_3_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_3_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_3 Register FDMA_PSTAT0_3 - Ethernet Switch Fetch DMA Port 3 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_3 0x2A50
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_3 0x18452A50u

/*! Register Reset Value */
#define FDMA_PSTAT0_3_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_3_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_3_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_3_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_3_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_3_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_3_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_3_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_3_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_3 Register FDMA_PSTAT1_3 - Ethernet Switch Fetch DMA Port 3 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_3 0x2A54
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_3 0x18452A54u

/*! Register Reset Value */
#define FDMA_PSTAT1_3_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_3_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_3_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_4 Register FDMA_PCTRL_4 - Ethernet Switch Fetch DMA Port 4 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_4 0x2A60
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_4 0x18452A60u

/*! Register Reset Value */
#define FDMA_PCTRL_4_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_4_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_4_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_4_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_4_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_4_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_4_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_4_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_4_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_4_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_4_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_4_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_4_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_4_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_4_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_4_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_4_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_4 Register FDMA_PSTAT0_4 - Ethernet Switch Fetch DMA Port 4 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_4 0x2A68
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_4 0x18452A68u

/*! Register Reset Value */
#define FDMA_PSTAT0_4_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_4_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_4_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_4_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_4_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_4_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_4_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_4_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_4_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_4 Register FDMA_PSTAT1_4 - Ethernet Switch Fetch DMA Port 4 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_4 0x2A6C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_4 0x18452A6Cu

/*! Register Reset Value */
#define FDMA_PSTAT1_4_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_4_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_4_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_5 Register FDMA_PCTRL_5 - Ethernet Switch Fetch DMA Port 5 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_5 0x2A78
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_5 0x18452A78u

/*! Register Reset Value */
#define FDMA_PCTRL_5_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_5_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_5_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_5_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_5_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_5_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_5_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_5_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_5_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_5_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_5_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_5_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_5_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_5_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_5_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_5_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_5_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_5 Register FDMA_PSTAT0_5 - Ethernet Switch Fetch DMA Port 5 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_5 0x2A80
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_5 0x18452A80u

/*! Register Reset Value */
#define FDMA_PSTAT0_5_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_5_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_5_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_5_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_5_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_5_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_5_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_5_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_5_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_5 Register FDMA_PSTAT1_5 - Ethernet Switch Fetch DMA Port 5 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_5 0x2A84
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_5 0x18452A84u

/*! Register Reset Value */
#define FDMA_PSTAT1_5_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_5_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_5_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_6 Register FDMA_PCTRL_6 - Ethernet Switch Fetch DMA Port 6 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_6 0x2A90
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_6 0x18452A90u

/*! Register Reset Value */
#define FDMA_PCTRL_6_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_6_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_6_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_6_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_6_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_6_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_6_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_6_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_6_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_6_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_6_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_6_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_6_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_6_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_6_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_6_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_6_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_6 Register FDMA_PSTAT0_6 - Ethernet Switch Fetch DMA Port 6 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_6 0x2A98
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_6 0x18452A98u

/*! Register Reset Value */
#define FDMA_PSTAT0_6_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_6_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_6_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_6_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_6_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_6_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_6_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_6_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_6_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_6 Register FDMA_PSTAT1_6 - Ethernet Switch Fetch DMA Port 6 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_6 0x2A9C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_6 0x18452A9Cu

/*! Register Reset Value */
#define FDMA_PSTAT1_6_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_6_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_6_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_7 Register FDMA_PCTRL_7 - Ethernet Switch Fetch DMA Port 7 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_7 0x2AA8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_7 0x18452AA8u

/*! Register Reset Value */
#define FDMA_PCTRL_7_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_7_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_7_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_7_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_7_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_7_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_7_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_7_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_7_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_7_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_7_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_7_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_7_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_7_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_7_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_7_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_7_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_7 Register FDMA_PSTAT0_7 - Ethernet Switch Fetch DMA Port 7 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_7 0x2AB0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_7 0x18452AB0u

/*! Register Reset Value */
#define FDMA_PSTAT0_7_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_7_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_7_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_7_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_7_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_7_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_7_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_7_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_7_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_7 Register FDMA_PSTAT1_7 - Ethernet Switch Fetch DMA Port 7 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_7 0x2AB4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_7 0x18452AB4u

/*! Register Reset Value */
#define FDMA_PSTAT1_7_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_7_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_7_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_8 Register FDMA_PCTRL_8 - Ethernet Switch Fetch DMA Port 8 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_8 0x2AC0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_8 0x18452AC0u

/*! Register Reset Value */
#define FDMA_PCTRL_8_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_8_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_8_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_8_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_8_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_8_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_8_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_8_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_8_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_8_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_8_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_8_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_8_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_8_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_8_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_8_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_8_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_8 Register FDMA_PSTAT0_8 - Ethernet Switch Fetch DMA Port 8 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_8 0x2AC8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_8 0x18452AC8u

/*! Register Reset Value */
#define FDMA_PSTAT0_8_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_8_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_8_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_8_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_8_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_8_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_8_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_8_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_8_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_8 Register FDMA_PSTAT1_8 - Ethernet Switch Fetch DMA Port 8 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_8 0x2ACC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_8 0x18452ACCu

/*! Register Reset Value */
#define FDMA_PSTAT1_8_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_8_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_8_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_9 Register FDMA_PCTRL_9 - Ethernet Switch Fetch DMA Port 9 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_9 0x2AD8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_9 0x18452AD8u

/*! Register Reset Value */
#define FDMA_PCTRL_9_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_9_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_9_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_9_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_9_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_9_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_9_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_9_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_9_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_9_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_9_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_9_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_9_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_9_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_9_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_9_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_9_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_9 Register FDMA_PSTAT0_9 - Ethernet Switch Fetch DMA Port 9 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_9 0x2AE0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_9 0x18452AE0u

/*! Register Reset Value */
#define FDMA_PSTAT0_9_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_9_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_9_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_9_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_9_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_9_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_9_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_9_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_9_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_9 Register FDMA_PSTAT1_9 - Ethernet Switch Fetch DMA Port 9 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_9 0x2AE4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_9 0x18452AE4u

/*! Register Reset Value */
#define FDMA_PSTAT1_9_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_9_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_9_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_10 Register FDMA_PCTRL_10 - Ethernet Switch Fetch DMA Port 10 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_10 0x2AF0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_10 0x18452AF0u

/*! Register Reset Value */
#define FDMA_PCTRL_10_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_10_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_10_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_10_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_10_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_10_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_10_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_10_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_10_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_10_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_10_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_10_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_10_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_10_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_10_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_10_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_10_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_10 Register FDMA_PSTAT0_10 - Ethernet Switch Fetch DMA Port 10 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_10 0x2AF8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_10 0x18452AF8u

/*! Register Reset Value */
#define FDMA_PSTAT0_10_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_10_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_10_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_10_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_10_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_10_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_10_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_10_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_10_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_10 Register FDMA_PSTAT1_10 - Ethernet Switch Fetch DMA Port 10 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_10 0x2AFC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_10 0x18452AFCu

/*! Register Reset Value */
#define FDMA_PSTAT1_10_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_10_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_10_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup FDMA_PCTRL_11 Register FDMA_PCTRL_11 - Ethernet Switch Fetch DMA Port 11 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PCTRL_11 0x2B08
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PCTRL_11 0x18452B08u

/*! Register Reset Value */
#define FDMA_PCTRL_11_RST 0x00000009u

/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_11_EN_POS 0
/*! Field EN - FDMA Port Enable */
#define FDMA_PCTRL_11_EN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_11_EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_11_EN_EN 0x1

/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_11_STEN_POS 1
/*! Field STEN - Special Tag Insertion Enable */
#define FDMA_PCTRL_11_STEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_11_STEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_11_STEN_EN 0x1

/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_11_DSCPRM_POS 2
/*! Field DSCPRM - DSCP Re-marking Enable */
#define FDMA_PCTRL_11_DSCPRM_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_11_DSCPRM_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_11_DSCPRM_EN 0x1

/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_11_VLANMOD_POS 3
/*! Field VLANMOD - VLAN Modification Control */
#define FDMA_PCTRL_11_VLANMOD_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_FDMA_PCTRL_11_VLANMOD_DIS 0x0
/*! Constant EN - EN */
#define CONST_FDMA_PCTRL_11_VLANMOD_EN 0x1

/*! @} */

/*! \defgroup FDMA_PSTAT0_11 Register FDMA_PSTAT0_11 - Ethernet Switch Fetch DMA Port 11 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT0_11 0x2B10
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT0_11 0x18452B10u

/*! Register Reset Value */
#define FDMA_PSTAT0_11_RST 0x00000000u

/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_11_PSEG_POS 0
/*! Field PSEG - Port Egress Segment Count */
#define FDMA_PSTAT0_11_PSEG_MASK 0x3Fu

/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_11_POK_POS 14
/*! Field POK - Port Status OK */
#define FDMA_PSTAT0_11_POK_MASK 0x4000u
/*! Constant NOK - NOK */
#define CONST_FDMA_PSTAT0_11_POK_NOK 0x0
/*! Constant OK - OK */
#define CONST_FDMA_PSTAT0_11_POK_OK 0x1

/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_11_PKT_AVAIL_POS 15
/*! Field PKT_AVAIL - Port Egress Packet Available */
#define FDMA_PSTAT0_11_PKT_AVAIL_MASK 0x8000u

/*! @} */

/*! \defgroup FDMA_PSTAT1_11 Register FDMA_PSTAT1_11 - Ethernet Switch Fetch DMA Port 11 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define FDMA_PSTAT1_11 0x2B14
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_FDMA_PSTAT1_11 0x18452B14u

/*! Register Reset Value */
#define FDMA_PSTAT1_11_RST 0x00000000u

/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_11_HDR_PTR_POS 0
/*! Field HDR_PTR - Header Pointer */
#define FDMA_PSTAT1_11_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_CTRL Register SDMA_CTRL - Ethernet Switch Store DMA Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_CTRL 0x2D00
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_CTRL 0x18452D00u

/*! Register Reset Value */
#define SDMA_CTRL_RST 0x00000000u

/*! Field ARBIT - SIMPLE ARBITER FOR PARSER FILLING */
#define SDMA_CTRL_ARBIT_POS 1
/*! Field ARBIT - SIMPLE ARBITER FOR PARSER FILLING */
#define SDMA_CTRL_ARBIT_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_CTRL_ARBIT_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_CTRL_ARBIT_EN 0x1

/*! @} */

/*! \defgroup SDMA_FCTHR1 Register SDMA_FCTHR1 - SDMA Flow Control Threshold 1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_FCTHR1 0x2D04
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_FCTHR1 0x18452D04u

/*! Register Reset Value */
#define SDMA_FCTHR1_RST 0x00000000u

/*! Field THR1 - Threshold 1 */
#define SDMA_FCTHR1_THR1_POS 0
/*! Field THR1 - Threshold 1 */
#define SDMA_FCTHR1_THR1_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_FCTHR2 Register SDMA_FCTHR2 - SDMA Flow Control Threshold 2 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_FCTHR2 0x2D08
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_FCTHR2 0x18452D08u

/*! Register Reset Value */
#define SDMA_FCTHR2_RST 0x00000000u

/*! Field THR2 - Threshold 2 */
#define SDMA_FCTHR2_THR2_POS 0
/*! Field THR2 - Threshold 2 */
#define SDMA_FCTHR2_THR2_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_FCTHR3 Register SDMA_FCTHR3 - SDMA Flow Control Threshold 3 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_FCTHR3 0x2D0C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_FCTHR3 0x18452D0Cu

/*! Register Reset Value */
#define SDMA_FCTHR3_RST 0x000003FFu

/*! Field THR3 - Threshold 3 */
#define SDMA_FCTHR3_THR3_POS 0
/*! Field THR3 - Threshold 3 */
#define SDMA_FCTHR3_THR3_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_FCTHR4 Register SDMA_FCTHR4 - SDMA Flow Control Threshold 4 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_FCTHR4 0x2D10
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_FCTHR4 0x18452D10u

/*! Register Reset Value */
#define SDMA_FCTHR4_RST 0x000003FFu

/*! Field THR4 - Threshold 4 */
#define SDMA_FCTHR4_THR4_POS 0
/*! Field THR4 - Threshold 4 */
#define SDMA_FCTHR4_THR4_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_FCTHR5 Register SDMA_FCTHR5 - SDMA Flow Control Threshold 5 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_FCTHR5 0x2D14
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_FCTHR5 0x18452D14u

/*! Register Reset Value */
#define SDMA_FCTHR5_RST 0x000003FFu

/*! Field THR5 - Threshold 5 */
#define SDMA_FCTHR5_THR5_POS 0
/*! Field THR5 - Threshold 5 */
#define SDMA_FCTHR5_THR5_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_FCTHR6 Register SDMA_FCTHR6 - SDMA Flow Control Threshold 6 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_FCTHR6 0x2D18
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_FCTHR6 0x18452D18u

/*! Register Reset Value */
#define SDMA_FCTHR6_RST 0x000003FFu

/*! Field THR6 - Threshold 6 */
#define SDMA_FCTHR6_THR6_POS 0
/*! Field THR6 - Threshold 6 */
#define SDMA_FCTHR6_THR6_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_FCTHR7 Register SDMA_FCTHR7 - SDMA Flow Control Threshold 7 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_FCTHR7 0x2D1C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_FCTHR7 0x18452D1Cu

/*! Register Reset Value */
#define SDMA_FCTHR7_RST 0x000007FFu

/*! Field THR7 - Threshold 7 */
#define SDMA_FCTHR7_THR7_POS 0
/*! Field THR7 - Threshold 7 */
#define SDMA_FCTHR7_THR7_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_STAT_0 Register SDMA_STAT_0 - SDMA Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_STAT_0 0x2D20
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_STAT_0 0x18452D20u

/*! Register Reset Value */
#define SDMA_STAT_0_RST 0x00000000u

/*! Field DROP - Drop Status */
#define SDMA_STAT_0_DROP_POS 0
/*! Field DROP - Drop Status */
#define SDMA_STAT_0_DROP_MASK 0x3u
/*! Constant NORMAL - NORMAL */
#define CONST_SDMA_STAT_0_DROP_NORMAL 0x0
/*! Constant DROP1 - DROP1 */
#define CONST_SDMA_STAT_0_DROP_DROP1 0x1
/*! Constant DROP2 - DROP2 */
#define CONST_SDMA_STAT_0_DROP_DROP2 0x2
/*! Constant ALL - ALL */
#define CONST_SDMA_STAT_0_DROP_ALL 0x3

/*! Field BPS_PNT - Back Pressure Status */
#define SDMA_STAT_0_BPS_PNT_POS 2
/*! Field BPS_PNT - Back Pressure Status */
#define SDMA_STAT_0_BPS_PNT_MASK 0xCu
/*! Constant NORMAL - NORMAL */
#define CONST_SDMA_STAT_0_BPS_PNT_NORMAL 0x0
/*! Constant EXCEED - EXCEED */
#define CONST_SDMA_STAT_0_BPS_PNT_EXCEED 0x1
/*! Constant CONGESTION - CONGESTION */
#define CONST_SDMA_STAT_0_BPS_PNT_CONGESTION 0x2

/*! Field BPS_FILL - Back Pressure Status */
#define SDMA_STAT_0_BPS_FILL_POS 4
/*! Field BPS_FILL - Back Pressure Status */
#define SDMA_STAT_0_BPS_FILL_MASK 0x70u
/*! Constant NORMAL - NORMAL */
#define CONST_SDMA_STAT_0_BPS_FILL_NORMAL 0x0
/*! Constant NONCONFORM - NONCONFORM */
#define CONST_SDMA_STAT_0_BPS_FILL_NONCONFORM 0x1
/*! Constant PARTIAL - PARTIAL */
#define CONST_SDMA_STAT_0_BPS_FILL_PARTIAL 0x2
/*! Constant ALL - ALL */
#define CONST_SDMA_STAT_0_BPS_FILL_ALL 0x3
/*! Constant CONGESTION - CONGESTION */
#define CONST_SDMA_STAT_0_BPS_FILL_CONGESTION 0x4

/*! @} */

/*! \defgroup SDMA_STAT_1 Register SDMA_STAT_1 - SDMA Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_STAT_1 0x2D24
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_STAT_1 0x18452D24u

/*! Register Reset Value */
#define SDMA_STAT_1_RST 0x00000000u

/*! Field FILL - Buffer Filling Level */
#define SDMA_STAT_1_FILL_POS 0
/*! Field FILL - Buffer Filling Level */
#define SDMA_STAT_1_FILL_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_STAT_2 Register SDMA_STAT_2 - SDMA Status Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_STAT_2 0x2D28
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_STAT_2 0x18452D28u

/*! Register Reset Value */
#define SDMA_STAT_2_RST 0x00000000u

/*! Field FSMS - FSM states status */
#define SDMA_STAT_2_FSMS_POS 0
/*! Field FSMS - FSM states status */
#define SDMA_STAT_2_FSMS_MASK 0xFFFFu

/*! @} */

/*! \defgroup SDMA_IER Register SDMA_IER - SDMA Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_IER 0x2D2C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_IER 0x18452D2Cu

/*! Register Reset Value */
#define SDMA_IER_RST 0x00000000u

/*! Field FERR - Frame Error */
#define SDMA_IER_FERR_POS 13
/*! Field FERR - Frame Error */
#define SDMA_IER_FERR_MASK 0x2000u
/*! Constant DIS - DIS */
#define CONST_SDMA_IER_FERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_IER_FERR_EN 0x1

/*! Field BFULL - Buffer Full */
#define SDMA_IER_BFULL_POS 14
/*! Field BFULL - Buffer Full */
#define SDMA_IER_BFULL_MASK 0x4000u
/*! Constant DIS - DIS */
#define CONST_SDMA_IER_BFULL_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_IER_BFULL_EN 0x1

/*! Field BPEX - Buffer Pointers Exceeded */
#define SDMA_IER_BPEX_POS 15
/*! Field BPEX - Buffer Pointers Exceeded */
#define SDMA_IER_BPEX_MASK 0x8000u
/*! Constant DIS - DIS */
#define CONST_SDMA_IER_BPEX_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_IER_BPEX_EN 0x1

/*! @} */

/*! \defgroup SDMA_ISR Register SDMA_ISR - SDMA Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_ISR 0x2D30
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_ISR 0x18452D30u

/*! Register Reset Value */
#define SDMA_ISR_RST 0x00000000u

/*! Field FERR - Frame Error */
#define SDMA_ISR_FERR_POS 13
/*! Field FERR - Frame Error */
#define SDMA_ISR_FERR_MASK 0x2000u
/*! Constant NOINT - NOINT */
#define CONST_SDMA_ISR_FERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_SDMA_ISR_FERR_INT 0x1

/*! Field BFULL - Buffer Full */
#define SDMA_ISR_BFULL_POS 14
/*! Field BFULL - Buffer Full */
#define SDMA_ISR_BFULL_MASK 0x4000u
/*! Constant NOINT - NOINT */
#define CONST_SDMA_ISR_BFULL_NOINT 0x0
/*! Constant INT - INT */
#define CONST_SDMA_ISR_BFULL_INT 0x1

/*! Field BPEX - Packet Descriptors Exceeded */
#define SDMA_ISR_BPEX_POS 15
/*! Field BPEX - Packet Descriptors Exceeded */
#define SDMA_ISR_BPEX_MASK 0x8000u
/*! Constant NOINT - NOINT */
#define CONST_SDMA_ISR_BPEX_NOINT 0x0
/*! Constant INT - INT */
#define CONST_SDMA_ISR_BPEX_INT 0x1

/*! @} */

/*! \defgroup SDMA_IER_1 Register SDMA_IER_1 - SDMA Interrupt Enable Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_IER_1 0x2D34
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_IER_1 0x18452D34u

/*! Register Reset Value */
#define SDMA_IER_1_RST 0x00000000u

/*! Field CGNBP - Ingress Port Congestion Based Back Pressure Status Change */
#define SDMA_IER_1_CGNBP_POS 0
/*! Field CGNBP - Ingress Port Congestion Based Back Pressure Status Change */
#define SDMA_IER_1_CGNBP_MASK 0xFFFFu

/*! @} */

/*! \defgroup SDMA_ISR_1 Register SDMA_ISR_1 - SDMA Interrupt Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_ISR_1 0x2D38
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_ISR_1 0x18452D38u

/*! Register Reset Value */
#define SDMA_ISR_1_RST 0x00000000u

/*! Field CGNBP - Ingress Port Congested Based Backpressure Status Change */
#define SDMA_ISR_1_CGNBP_POS 0
/*! Field CGNBP - Ingress Port Congested Based Backpressure Status Change */
#define SDMA_ISR_1_CGNBP_MASK 0xFFFFu

/*! @} */

/*! \defgroup SDMA_CGNBP Register SDMA_CGNBP - SDMA Congestion Backpressure Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_CGNBP 0x2D3C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_CGNBP 0x18452D3Cu

/*! Register Reset Value */
#define SDMA_CGNBP_RST 0x00000000u

/*! Field CGNBP - Ingress Port Congestion Based Back Pressure Status */
#define SDMA_CGNBP_CGNBP_POS 0
/*! Field CGNBP - Ingress Port Congestion Based Back Pressure Status */
#define SDMA_CGNBP_CGNBP_MASK 0xFFFFu

/*! @} */

/*! \defgroup SDMA_IER_2 Register SDMA_IER_2 - SDMA Interrupt Enable Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_IER_2 0x2D40
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_IER_2 0x18452D40u

/*! Register Reset Value */
#define SDMA_IER_2_RST 0x00000000u

/*! Field FRX - Frame Received Successfully */
#define SDMA_IER_2_FRX_POS 0
/*! Field FRX - Frame Received Successfully */
#define SDMA_IER_2_FRX_MASK 0xFFFFu

/*! @} */

/*! \defgroup SDMA_ISR_2 Register SDMA_ISR_2 - SDMA Interrupt Status Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_ISR_2 0x2D44
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_ISR_2 0x18452D44u

/*! Register Reset Value */
#define SDMA_ISR_2_RST 0x00000000u

/*! Field FRX - Frame Received Successfully */
#define SDMA_ISR_2_FRX_POS 0
/*! Field FRX - Frame Received Successfully */
#define SDMA_ISR_2_FRX_MASK 0xFFFFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8 Register SDMA_PFCTHR8 - Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8 0x2E00
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8 0x18452E00u

/*! Register Reset Value */
#define SDMA_PFCTHR8_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9 Register SDMA_PFCTHR9 - Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9 0x2E04
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9 0x18452E04u

/*! Register Reset Value */
#define SDMA_PFCTHR9_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_1 Register SDMA_PFCTHR8_1 - Port 1 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_1 0x2E08
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_1 0x18452E08u

/*! Register Reset Value */
#define SDMA_PFCTHR8_1_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_1_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_1_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_1 Register SDMA_PFCTHR9_1 - Port 1 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_1 0x2E0C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_1 0x18452E0Cu

/*! Register Reset Value */
#define SDMA_PFCTHR9_1_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_1_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_1_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_2 Register SDMA_PFCTHR8_2 - Port 2 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_2 0x2E10
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_2 0x18452E10u

/*! Register Reset Value */
#define SDMA_PFCTHR8_2_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_2_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_2_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_2 Register SDMA_PFCTHR9_2 - Port 2 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_2 0x2E14
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_2 0x18452E14u

/*! Register Reset Value */
#define SDMA_PFCTHR9_2_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_2_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_2_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_3 Register SDMA_PFCTHR8_3 - Port 3 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_3 0x2E18
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_3 0x18452E18u

/*! Register Reset Value */
#define SDMA_PFCTHR8_3_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_3_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_3_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_3 Register SDMA_PFCTHR9_3 - Port 3 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_3 0x2E1C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_3 0x18452E1Cu

/*! Register Reset Value */
#define SDMA_PFCTHR9_3_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_3_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_3_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_4 Register SDMA_PFCTHR8_4 - Port 4 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_4 0x2E20
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_4 0x18452E20u

/*! Register Reset Value */
#define SDMA_PFCTHR8_4_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_4_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_4_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_4 Register SDMA_PFCTHR9_4 - Port 4 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_4 0x2E24
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_4 0x18452E24u

/*! Register Reset Value */
#define SDMA_PFCTHR9_4_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_4_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_4_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_5 Register SDMA_PFCTHR8_5 - Port 5 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_5 0x2E28
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_5 0x18452E28u

/*! Register Reset Value */
#define SDMA_PFCTHR8_5_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_5_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_5_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_5 Register SDMA_PFCTHR9_5 - Port 5 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_5 0x2E2C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_5 0x18452E2Cu

/*! Register Reset Value */
#define SDMA_PFCTHR9_5_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_5_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_5_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_6 Register SDMA_PFCTHR8_6 - Port 6 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_6 0x2E30
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_6 0x18452E30u

/*! Register Reset Value */
#define SDMA_PFCTHR8_6_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_6_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_6_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_6 Register SDMA_PFCTHR9_6 - Port 6 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_6 0x2E34
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_6 0x18452E34u

/*! Register Reset Value */
#define SDMA_PFCTHR9_6_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_6_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_6_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_7 Register SDMA_PFCTHR8_7 - Port 7 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_7 0x2E38
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_7 0x18452E38u

/*! Register Reset Value */
#define SDMA_PFCTHR8_7_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_7_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_7_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_7 Register SDMA_PFCTHR9_7 - Port 7 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_7 0x2E3C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_7 0x18452E3Cu

/*! Register Reset Value */
#define SDMA_PFCTHR9_7_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_7_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_7_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_8 Register SDMA_PFCTHR8_8 - Port 8 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_8 0x2E40
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_8 0x18452E40u

/*! Register Reset Value */
#define SDMA_PFCTHR8_8_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_8_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_8_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_8 Register SDMA_PFCTHR9_8 - Port 8 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_8 0x2E44
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_8 0x18452E44u

/*! Register Reset Value */
#define SDMA_PFCTHR9_8_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_8_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_8_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_9 Register SDMA_PFCTHR8_9 - Port 9 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_9 0x2E48
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_9 0x18452E48u

/*! Register Reset Value */
#define SDMA_PFCTHR8_9_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_9_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_9_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_9 Register SDMA_PFCTHR9_9 - Port 9 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_9 0x2E4C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_9 0x18452E4Cu

/*! Register Reset Value */
#define SDMA_PFCTHR9_9_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_9_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_9_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_10 Register SDMA_PFCTHR8_10 - Port 10 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_10 0x2E50
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_10 0x18452E50u

/*! Register Reset Value */
#define SDMA_PFCTHR8_10_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_10_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_10_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_10 Register SDMA_PFCTHR9_10 - Port 10 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_10 0x2E54
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_10 0x18452E54u

/*! Register Reset Value */
#define SDMA_PFCTHR9_10_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_10_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_10_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR8_11 Register SDMA_PFCTHR8_11 - Port 11 Ingress Port Flow Control Threshold 8 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR8_11 0x2E58
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR8_11 0x18452E58u

/*! Register Reset Value */
#define SDMA_PFCTHR8_11_RST 0x00000018u

/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_11_THR8_POS 0
/*! Field THR8 - Threshold 8 */
#define SDMA_PFCTHR8_11_THR8_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PFCTHR9_11 Register SDMA_PFCTHR9_11 - Port 11 Ingress Port Flow Control Threshold 9 Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PFCTHR9_11 0x2E5C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PFCTHR9_11 0x18452E5Cu

/*! Register Reset Value */
#define SDMA_PFCTHR9_11_RST 0x0000001Eu

/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_11_THR9_POS 0
/*! Field THR9 - Threshold 9 */
#define SDMA_PFCTHR9_11_THR9_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_PCTRL Register SDMA_PCTRL - Ethernet Switch Store DMA Port Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL 0x2F00
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL 0x18452F00u

/*! Register Reset Value */
#define SDMA_PCTRL_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO Register SDMA_PRIO - Ethernet Switch Store DMA Port Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO 0x2F04
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO 0x18452F04u

/*! Register Reset Value */
#define SDMA_PRIO_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0 Register SDMA_PSTAT0 - Ethernet Switch Store DMA Port Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0 0x2F08
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0 0x18452F08u

/*! Register Reset Value */
#define SDMA_PSTAT0_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1 Register SDMA_PSTAT1 - Ethernet Switch Store DMA Port Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1 0x2F0C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1 0x18452F0Cu

/*! Register Reset Value */
#define SDMA_PSTAT1_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS Register SDMA_BYPASS - Ethernet Switch Store DMA PCE Bypass Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS 0x2F10
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS 0x18452F10u

/*! Register Reset Value */
#define SDMA_BYPASS_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_1 Register SDMA_PCTRL_1 - Ethernet Switch Store DMA Port 1 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_1 0x2F18
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_1 0x18452F18u

/*! Register Reset Value */
#define SDMA_PCTRL_1_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_1_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_1_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_1_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_1_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_1_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_1_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_1_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_1_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_1_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_1_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_1_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_1_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_1_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_1_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_1_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_1_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_1_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_1_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_1_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_1_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_1_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_1_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_1_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_1_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_1_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_1_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_1_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_1_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_1_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_1_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_1_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_1_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_1_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_1_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_1_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_1_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_1_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_1_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_1_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_1_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_1_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_1_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_1_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_1_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_1_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_1_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_1_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_1_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_1_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_1_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_1_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_1_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_1_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_1_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_1_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_1_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_1 Register SDMA_PRIO_1 - Ethernet Switch Store DMA Port 1 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_1 0x2F1C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_1 0x18452F1Cu

/*! Register Reset Value */
#define SDMA_PRIO_1_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_1_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_1_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_1_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_1_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_1_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_1_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_1_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_1_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_1_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_1_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_1_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_1_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_1_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_1_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_1_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_1_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_1_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_1_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_1_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_1_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_1_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_1_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_1_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_1_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_1_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_1_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_1_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_1_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_1 Register SDMA_PSTAT0_1 - Ethernet Switch Store DMA Port 1 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_1 0x2F20
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_1 0x18452F20u

/*! Register Reset Value */
#define SDMA_PSTAT0_1_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_1_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_1_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_1 Register SDMA_PSTAT1_1 - Ethernet Switch Store DMA Port 1 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_1 0x2F24
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_1 0x18452F24u

/*! Register Reset Value */
#define SDMA_PSTAT1_1_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_1_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_1_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_1 Register SDMA_BYPASS_1 - Ethernet Switch Store DMA PCE Bypass Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_1 0x2F28
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_1 0x18452F28u

/*! Register Reset Value */
#define SDMA_BYPASS_1_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_1_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_1_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_1_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_1_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_1_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_1_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_1_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_1_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_2 Register SDMA_PCTRL_2 - Ethernet Switch Store DMA Port 2 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_2 0x2F30
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_2 0x18452F30u

/*! Register Reset Value */
#define SDMA_PCTRL_2_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_2_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_2_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_2_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_2_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_2_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_2_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_2_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_2_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_2_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_2_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_2_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_2_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_2_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_2_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_2_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_2_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_2_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_2_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_2_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_2_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_2_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_2_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_2_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_2_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_2_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_2_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_2_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_2_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_2_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_2_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_2_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_2_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_2_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_2_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_2_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_2_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_2_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_2_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_2_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_2_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_2_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_2_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_2_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_2_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_2_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_2_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_2_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_2_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_2_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_2_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_2_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_2_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_2_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_2_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_2_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_2_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_2 Register SDMA_PRIO_2 - Ethernet Switch Store DMA Port 2 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_2 0x2F34
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_2 0x18452F34u

/*! Register Reset Value */
#define SDMA_PRIO_2_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_2_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_2_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_2_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_2_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_2_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_2_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_2_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_2_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_2_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_2_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_2_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_2_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_2_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_2_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_2_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_2_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_2_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_2_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_2_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_2_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_2_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_2_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_2_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_2_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_2_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_2_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_2_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_2_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_2 Register SDMA_PSTAT0_2 - Ethernet Switch Store DMA Port 2 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_2 0x2F38
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_2 0x18452F38u

/*! Register Reset Value */
#define SDMA_PSTAT0_2_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_2_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_2_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_2 Register SDMA_PSTAT1_2 - Ethernet Switch Store DMA Port 2 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_2 0x2F3C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_2 0x18452F3Cu

/*! Register Reset Value */
#define SDMA_PSTAT1_2_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_2_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_2_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_2 Register SDMA_BYPASS_2 - Ethernet Switch Store DMA PCE Bypass Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_2 0x2F40
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_2 0x18452F40u

/*! Register Reset Value */
#define SDMA_BYPASS_2_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_2_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_2_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_2_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_2_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_2_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_2_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_2_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_2_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_3 Register SDMA_PCTRL_3 - Ethernet Switch Store DMA Port 3 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_3 0x2F48
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_3 0x18452F48u

/*! Register Reset Value */
#define SDMA_PCTRL_3_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_3_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_3_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_3_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_3_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_3_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_3_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_3_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_3_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_3_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_3_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_3_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_3_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_3_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_3_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_3_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_3_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_3_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_3_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_3_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_3_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_3_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_3_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_3_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_3_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_3_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_3_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_3_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_3_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_3_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_3_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_3_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_3_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_3_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_3_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_3_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_3_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_3_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_3_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_3_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_3_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_3_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_3_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_3_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_3_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_3_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_3_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_3_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_3_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_3_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_3_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_3_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_3_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_3_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_3_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_3_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_3_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_3 Register SDMA_PRIO_3 - Ethernet Switch Store DMA Port 3 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_3 0x2F4C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_3 0x18452F4Cu

/*! Register Reset Value */
#define SDMA_PRIO_3_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_3_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_3_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_3_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_3_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_3_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_3_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_3_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_3_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_3_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_3_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_3_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_3_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_3_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_3_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_3_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_3_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_3_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_3_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_3_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_3_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_3_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_3_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_3_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_3_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_3_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_3_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_3_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_3_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_3 Register SDMA_PSTAT0_3 - Ethernet Switch Store DMA Port 3 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_3 0x2F50
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_3 0x18452F50u

/*! Register Reset Value */
#define SDMA_PSTAT0_3_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_3_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_3_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_3 Register SDMA_PSTAT1_3 - Ethernet Switch Store DMA Port 3 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_3 0x2F54
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_3 0x18452F54u

/*! Register Reset Value */
#define SDMA_PSTAT1_3_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_3_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_3_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_3 Register SDMA_BYPASS_3 - Ethernet Switch Store DMA PCE Bypass Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_3 0x2F58
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_3 0x18452F58u

/*! Register Reset Value */
#define SDMA_BYPASS_3_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_3_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_3_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_3_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_3_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_3_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_3_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_3_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_3_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_4 Register SDMA_PCTRL_4 - Ethernet Switch Store DMA Port 4 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_4 0x2F60
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_4 0x18452F60u

/*! Register Reset Value */
#define SDMA_PCTRL_4_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_4_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_4_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_4_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_4_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_4_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_4_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_4_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_4_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_4_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_4_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_4_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_4_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_4_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_4_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_4_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_4_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_4_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_4_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_4_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_4_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_4_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_4_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_4_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_4_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_4_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_4_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_4_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_4_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_4_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_4_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_4_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_4_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_4_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_4_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_4_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_4_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_4_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_4_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_4_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_4_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_4_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_4_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_4_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_4_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_4_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_4_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_4_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_4_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_4_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_4_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_4_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_4_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_4_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_4_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_4_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_4_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_4 Register SDMA_PRIO_4 - Ethernet Switch Store DMA Port 4 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_4 0x2F64
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_4 0x18452F64u

/*! Register Reset Value */
#define SDMA_PRIO_4_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_4_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_4_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_4_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_4_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_4_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_4_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_4_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_4_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_4_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_4_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_4_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_4_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_4_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_4_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_4_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_4_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_4_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_4_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_4_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_4_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_4_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_4_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_4_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_4_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_4_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_4_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_4_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_4_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_4 Register SDMA_PSTAT0_4 - Ethernet Switch Store DMA Port 4 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_4 0x2F68
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_4 0x18452F68u

/*! Register Reset Value */
#define SDMA_PSTAT0_4_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_4_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_4_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_4 Register SDMA_PSTAT1_4 - Ethernet Switch Store DMA Port 4 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_4 0x2F6C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_4 0x18452F6Cu

/*! Register Reset Value */
#define SDMA_PSTAT1_4_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_4_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_4_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_4 Register SDMA_BYPASS_4 - Ethernet Switch Store DMA PCE Bypass Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_4 0x2F70
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_4 0x18452F70u

/*! Register Reset Value */
#define SDMA_BYPASS_4_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_4_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_4_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_4_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_4_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_4_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_4_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_4_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_4_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_5 Register SDMA_PCTRL_5 - Ethernet Switch Store DMA Port 5 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_5 0x2F78
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_5 0x18452F78u

/*! Register Reset Value */
#define SDMA_PCTRL_5_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_5_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_5_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_5_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_5_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_5_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_5_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_5_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_5_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_5_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_5_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_5_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_5_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_5_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_5_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_5_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_5_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_5_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_5_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_5_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_5_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_5_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_5_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_5_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_5_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_5_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_5_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_5_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_5_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_5_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_5_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_5_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_5_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_5_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_5_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_5_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_5_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_5_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_5_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_5_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_5_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_5_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_5_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_5_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_5_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_5_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_5_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_5_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_5_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_5_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_5_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_5_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_5_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_5_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_5_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_5_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_5_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_5 Register SDMA_PRIO_5 - Ethernet Switch Store DMA Port 5 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_5 0x2F7C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_5 0x18452F7Cu

/*! Register Reset Value */
#define SDMA_PRIO_5_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_5_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_5_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_5_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_5_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_5_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_5_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_5_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_5_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_5_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_5_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_5_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_5_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_5_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_5_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_5_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_5_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_5_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_5_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_5_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_5_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_5_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_5_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_5_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_5_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_5_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_5_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_5_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_5_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_5 Register SDMA_PSTAT0_5 - Ethernet Switch Store DMA Port 5 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_5 0x2F80
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_5 0x18452F80u

/*! Register Reset Value */
#define SDMA_PSTAT0_5_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_5_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_5_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_5 Register SDMA_PSTAT1_5 - Ethernet Switch Store DMA Port 5 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_5 0x2F84
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_5 0x18452F84u

/*! Register Reset Value */
#define SDMA_PSTAT1_5_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_5_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_5_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_5 Register SDMA_BYPASS_5 - Ethernet Switch Store DMA PCE Bypass Register 5 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_5 0x2F88
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_5 0x18452F88u

/*! Register Reset Value */
#define SDMA_BYPASS_5_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_5_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_5_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_5_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_5_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_5_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_5_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_5_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_5_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_6 Register SDMA_PCTRL_6 - Ethernet Switch Store DMA Port 6 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_6 0x2F90
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_6 0x18452F90u

/*! Register Reset Value */
#define SDMA_PCTRL_6_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_6_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_6_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_6_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_6_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_6_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_6_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_6_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_6_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_6_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_6_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_6_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_6_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_6_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_6_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_6_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_6_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_6_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_6_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_6_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_6_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_6_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_6_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_6_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_6_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_6_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_6_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_6_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_6_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_6_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_6_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_6_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_6_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_6_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_6_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_6_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_6_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_6_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_6_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_6_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_6_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_6_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_6_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_6_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_6_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_6_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_6_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_6_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_6_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_6_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_6_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_6_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_6_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_6_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_6_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_6_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_6_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_6 Register SDMA_PRIO_6 - Ethernet Switch Store DMA Port 6 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_6 0x2F94
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_6 0x18452F94u

/*! Register Reset Value */
#define SDMA_PRIO_6_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_6_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_6_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_6_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_6_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_6_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_6_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_6_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_6_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_6_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_6_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_6_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_6_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_6_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_6_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_6_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_6_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_6_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_6_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_6_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_6_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_6_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_6_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_6_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_6_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_6_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_6_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_6_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_6_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_6 Register SDMA_PSTAT0_6 - Ethernet Switch Store DMA Port 6 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_6 0x2F98
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_6 0x18452F98u

/*! Register Reset Value */
#define SDMA_PSTAT0_6_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_6_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_6_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_6 Register SDMA_PSTAT1_6 - Ethernet Switch Store DMA Port 6 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_6 0x2F9C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_6 0x18452F9Cu

/*! Register Reset Value */
#define SDMA_PSTAT1_6_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_6_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_6_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_6 Register SDMA_BYPASS_6 - Ethernet Switch Store DMA PCE Bypass Register 6 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_6 0x2FA0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_6 0x18452FA0u

/*! Register Reset Value */
#define SDMA_BYPASS_6_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_6_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_6_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_6_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_6_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_6_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_6_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_6_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_6_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_7 Register SDMA_PCTRL_7 - Ethernet Switch Store DMA Port 7 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_7 0x2FA8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_7 0x18452FA8u

/*! Register Reset Value */
#define SDMA_PCTRL_7_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_7_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_7_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_7_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_7_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_7_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_7_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_7_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_7_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_7_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_7_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_7_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_7_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_7_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_7_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_7_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_7_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_7_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_7_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_7_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_7_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_7_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_7_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_7_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_7_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_7_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_7_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_7_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_7_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_7_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_7_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_7_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_7_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_7_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_7_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_7_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_7_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_7_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_7_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_7_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_7_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_7_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_7_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_7_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_7_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_7_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_7_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_7_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_7_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_7_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_7_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_7_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_7_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_7_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_7_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_7_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_7_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_7 Register SDMA_PRIO_7 - Ethernet Switch Store DMA Port 7 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_7 0x2FAC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_7 0x18452FACu

/*! Register Reset Value */
#define SDMA_PRIO_7_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_7_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_7_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_7_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_7_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_7_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_7_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_7_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_7_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_7_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_7_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_7_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_7_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_7_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_7_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_7_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_7_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_7_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_7_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_7_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_7_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_7_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_7_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_7_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_7_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_7_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_7_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_7_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_7_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_7 Register SDMA_PSTAT0_7 - Ethernet Switch Store DMA Port 7 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_7 0x2FB0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_7 0x18452FB0u

/*! Register Reset Value */
#define SDMA_PSTAT0_7_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_7_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_7_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_7 Register SDMA_PSTAT1_7 - Ethernet Switch Store DMA Port 7 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_7 0x2FB4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_7 0x18452FB4u

/*! Register Reset Value */
#define SDMA_PSTAT1_7_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_7_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_7_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_7 Register SDMA_BYPASS_7 - Ethernet Switch Store DMA PCE Bypass Register 7 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_7 0x2FB8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_7 0x18452FB8u

/*! Register Reset Value */
#define SDMA_BYPASS_7_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_7_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_7_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_7_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_7_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_7_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_7_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_7_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_7_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_8 Register SDMA_PCTRL_8 - Ethernet Switch Store DMA Port 8 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_8 0x2FC0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_8 0x18452FC0u

/*! Register Reset Value */
#define SDMA_PCTRL_8_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_8_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_8_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_8_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_8_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_8_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_8_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_8_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_8_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_8_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_8_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_8_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_8_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_8_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_8_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_8_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_8_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_8_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_8_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_8_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_8_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_8_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_8_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_8_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_8_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_8_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_8_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_8_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_8_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_8_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_8_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_8_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_8_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_8_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_8_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_8_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_8_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_8_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_8_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_8_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_8_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_8_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_8_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_8_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_8_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_8_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_8_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_8_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_8_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_8_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_8_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_8_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_8_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_8_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_8_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_8_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_8_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_8 Register SDMA_PRIO_8 - Ethernet Switch Store DMA Port 8 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_8 0x2FC4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_8 0x18452FC4u

/*! Register Reset Value */
#define SDMA_PRIO_8_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_8_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_8_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_8_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_8_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_8_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_8_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_8_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_8_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_8_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_8_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_8_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_8_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_8_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_8_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_8_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_8_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_8_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_8_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_8_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_8_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_8_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_8_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_8_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_8_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_8_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_8_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_8_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_8_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_8 Register SDMA_PSTAT0_8 - Ethernet Switch Store DMA Port 8 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_8 0x2FC8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_8 0x18452FC8u

/*! Register Reset Value */
#define SDMA_PSTAT0_8_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_8_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_8_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_8 Register SDMA_PSTAT1_8 - Ethernet Switch Store DMA Port 8 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_8 0x2FCC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_8 0x18452FCCu

/*! Register Reset Value */
#define SDMA_PSTAT1_8_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_8_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_8_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_8 Register SDMA_BYPASS_8 - Ethernet Switch Store DMA PCE Bypass Register 8 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_8 0x2FD0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_8 0x18452FD0u

/*! Register Reset Value */
#define SDMA_BYPASS_8_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_8_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_8_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_8_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_8_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_8_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_8_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_8_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_8_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_9 Register SDMA_PCTRL_9 - Ethernet Switch Store DMA Port 9 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_9 0x2FD8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_9 0x18452FD8u

/*! Register Reset Value */
#define SDMA_PCTRL_9_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_9_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_9_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_9_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_9_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_9_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_9_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_9_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_9_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_9_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_9_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_9_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_9_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_9_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_9_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_9_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_9_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_9_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_9_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_9_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_9_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_9_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_9_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_9_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_9_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_9_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_9_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_9_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_9_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_9_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_9_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_9_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_9_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_9_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_9_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_9_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_9_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_9_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_9_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_9_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_9_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_9_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_9_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_9_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_9_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_9_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_9_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_9_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_9_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_9_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_9_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_9_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_9_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_9_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_9_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_9_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_9_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_9 Register SDMA_PRIO_9 - Ethernet Switch Store DMA Port 9 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_9 0x2FDC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_9 0x18452FDCu

/*! Register Reset Value */
#define SDMA_PRIO_9_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_9_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_9_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_9_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_9_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_9_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_9_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_9_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_9_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_9_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_9_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_9_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_9_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_9_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_9_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_9_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_9_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_9_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_9_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_9_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_9_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_9_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_9_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_9_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_9_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_9_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_9_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_9_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_9_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_9 Register SDMA_PSTAT0_9 - Ethernet Switch Store DMA Port 9 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_9 0x2FE0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_9 0x18452FE0u

/*! Register Reset Value */
#define SDMA_PSTAT0_9_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_9_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_9_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_9 Register SDMA_PSTAT1_9 - Ethernet Switch Store DMA Port 9 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_9 0x2FE4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_9 0x18452FE4u

/*! Register Reset Value */
#define SDMA_PSTAT1_9_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_9_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_9_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_9 Register SDMA_BYPASS_9 - Ethernet Switch Store DMA PCE Bypass Register 9 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_9 0x2FE8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_9 0x18452FE8u

/*! Register Reset Value */
#define SDMA_BYPASS_9_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_9_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_9_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_9_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_9_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_9_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_9_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_9_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_9_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_10 Register SDMA_PCTRL_10 - Ethernet Switch Store DMA Port 10 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_10 0x2FF0
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_10 0x18452FF0u

/*! Register Reset Value */
#define SDMA_PCTRL_10_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_10_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_10_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_10_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_10_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_10_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_10_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_10_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_10_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_10_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_10_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_10_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_10_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_10_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_10_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_10_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_10_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_10_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_10_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_10_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_10_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_10_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_10_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_10_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_10_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_10_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_10_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_10_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_10_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_10_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_10_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_10_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_10_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_10_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_10_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_10_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_10_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_10_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_10_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_10_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_10_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_10_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_10_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_10_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_10_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_10_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_10_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_10_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_10_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_10_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_10_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_10_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_10_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_10_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_10_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_10_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_10_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_10 Register SDMA_PRIO_10 - Ethernet Switch Store DMA Port 10 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_10 0x2FF4
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_10 0x18452FF4u

/*! Register Reset Value */
#define SDMA_PRIO_10_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_10_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_10_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_10_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_10_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_10_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_10_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_10_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_10_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_10_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_10_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_10_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_10_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_10_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_10_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_10_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_10_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_10_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_10_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_10_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_10_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_10_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_10_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_10_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_10_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_10_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_10_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_10_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_10_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_10 Register SDMA_PSTAT0_10 - Ethernet Switch Store DMA Port 10 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_10 0x2FF8
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_10 0x18452FF8u

/*! Register Reset Value */
#define SDMA_PSTAT0_10_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_10_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_10_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_10 Register SDMA_PSTAT1_10 - Ethernet Switch Store DMA Port 10 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_10 0x2FFC
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_10 0x18452FFCu

/*! Register Reset Value */
#define SDMA_PSTAT1_10_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_10_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_10_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_10 Register SDMA_BYPASS_10 - Ethernet Switch Store DMA PCE Bypass Register 10 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_10 0x3000
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_10 0x18453000u

/*! Register Reset Value */
#define SDMA_BYPASS_10_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_10_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_10_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_10_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_10_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_10_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_10_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_10_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_10_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup SDMA_PCTRL_11 Register SDMA_PCTRL_11 - Ethernet Switch Store DMA Port 11 Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PCTRL_11 0x3008
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PCTRL_11 0x18453008u

/*! Register Reset Value */
#define SDMA_PCTRL_11_RST 0x000057D3u

/*! Field PEN - Port Enable */
#define SDMA_PCTRL_11_PEN_POS 0
/*! Field PEN - Port Enable */
#define SDMA_PCTRL_11_PEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_11_PEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_11_PEN_EN 0x1

/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_11_FCEN_POS 1
/*! Field FCEN - Flow Control Enable */
#define SDMA_PCTRL_11_FCEN_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_11_FCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_11_FCEN_EN 0x1

/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_11_MFCEN_POS 2
/*! Field MFCEN - Metering Flow Control Enable */
#define SDMA_PCTRL_11_MFCEN_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_SDMA_PCTRL_11_MFCEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_SDMA_PCTRL_11_MFCEN_EN 0x1

/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_11_PAUFWD_POS 3
/*! Field PAUFWD - Pause Frame Forwarding */
#define SDMA_PCTRL_11_PAUFWD_MASK 0x8u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_11_PAUFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_11_PAUFWD_FWD 0x1

/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_11_FCSFWD_POS 4
/*! Field FCSFWD - Forward FCS Errored Frames */
#define SDMA_PCTRL_11_FCSFWD_MASK 0x10u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_11_FCSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_11_FCSFWD_FWD 0x1

/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_11_FCSIGN_POS 5
/*! Field FCSIGN - Ignore FCS Errors */
#define SDMA_PCTRL_11_FCSIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PCTRL_11_FCSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PCTRL_11_FCSIGN_IGN 0x1

/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_11_USFWD_POS 6
/*! Field USFWD - Forward Undersized Frames */
#define SDMA_PCTRL_11_USFWD_MASK 0x40u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_11_USFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_11_USFWD_FWD 0x1

/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_11_OSFWD_POS 7
/*! Field OSFWD - Forward Oversized Frames */
#define SDMA_PCTRL_11_OSFWD_MASK 0x80u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_11_OSFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_11_OSFWD_FWD 0x1

/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_11_LENFWD_POS 8
/*! Field LENFWD - Forward Length Errored Frames */
#define SDMA_PCTRL_11_LENFWD_MASK 0x100u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_11_LENFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_11_LENFWD_FWD 0x1

/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_11_ALGFWD_POS 9
/*! Field ALGFWD - Forward Alignment Error Frames */
#define SDMA_PCTRL_11_ALGFWD_MASK 0x200u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_11_ALGFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_11_ALGFWD_FWD 0x1

/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_11_PHYEFWD_POS 10
/*! Field PHYEFWD - Forward RX Error Frames */
#define SDMA_PCTRL_11_PHYEFWD_MASK 0x400u
/*! Constant DROP - DROP */
#define CONST_SDMA_PCTRL_11_PHYEFWD_DROP 0x0
/*! Constant FWD - FWD */
#define CONST_SDMA_PCTRL_11_PHYEFWD_FWD 0x1

/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_11_PTHR_POS 11
/*! Field PTHR - Pause Threshold Selection */
#define SDMA_PCTRL_11_PTHR_MASK 0x1800u
/*! Constant THR3 - THR3 */
#define CONST_SDMA_PCTRL_11_PTHR_THR3 0x0
/*! Constant THR4 - THR4 */
#define CONST_SDMA_PCTRL_11_PTHR_THR4 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_11_PTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_11_PTHR_RES 0x3

/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_11_DTHR_POS 13
/*! Field DTHR - Drop Threshold Selection */
#define SDMA_PCTRL_11_DTHR_MASK 0x6000u
/*! Constant THR5 - THR5 */
#define CONST_SDMA_PCTRL_11_DTHR_THR5 0x0
/*! Constant THR6 - THR6 */
#define CONST_SDMA_PCTRL_11_DTHR_THR6 0x1
/*! Constant AUTO - AUTO */
#define CONST_SDMA_PCTRL_11_DTHR_AUTO 0x2
/*! Constant RES - RES */
#define CONST_SDMA_PCTRL_11_DTHR_RES 0x3

/*! @} */

/*! \defgroup SDMA_PRIO_11 Register SDMA_PRIO_11 - Ethernet Switch Store DMA Port 11 Priority Register */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PRIO_11 0x300C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PRIO_11 0x1845300Cu

/*! Register Reset Value */
#define SDMA_PRIO_11_RST 0x00000012u

/*! Field BIT10 - Reserved */
#define SDMA_PRIO_11_BIT10_POS 0
/*! Field BIT10 - Reserved */
#define SDMA_PRIO_11_BIT10_MASK 0x3u
/*! Constant RES0 - RES0 */
#define CONST_SDMA_PRIO_11_BIT10_RES0 0x0
/*! Constant RES1 - RES1 */
#define CONST_SDMA_PRIO_11_BIT10_RES1 0x1
/*! Constant RES2 - RES2 */
#define CONST_SDMA_PRIO_11_BIT10_RES2 0x2
/*! Constant RES3 - RES3 */
#define CONST_SDMA_PRIO_11_BIT10_RES3 0x3

/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_11_USIGN_POS 2
/*! Field USIGN - Ignore Undersized Frames */
#define SDMA_PRIO_11_USIGN_MASK 0x4u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_11_USIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_11_USIGN_IGN 0x1

/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_11_OSIGN_POS 3
/*! Field OSIGN - Ignore Oversized Frames */
#define SDMA_PRIO_11_OSIGN_MASK 0x8u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_11_OSIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_11_OSIGN_IGN 0x1

/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_11_LENIGN_POS 4
/*! Field LENIGN - Ignore Length Errored Frames */
#define SDMA_PRIO_11_LENIGN_MASK 0x10u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_11_LENIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_11_LENIGN_IGN 0x1

/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_11_ALGIGN_POS 5
/*! Field ALGIGN - Ignore Alignment Error Frames */
#define SDMA_PRIO_11_ALGIGN_MASK 0x20u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_11_ALGIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_11_ALGIGN_IGN 0x1

/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_11_PHYEIGN_POS 6
/*! Field PHYEIGN - Ignore PHY Error Frames */
#define SDMA_PRIO_11_PHYEIGN_MASK 0x40u
/*! Constant USE - USE */
#define CONST_SDMA_PRIO_11_PHYEIGN_USE 0x0
/*! Constant IGN - IGN */
#define CONST_SDMA_PRIO_11_PHYEIGN_IGN 0x1

/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_11_MIN_IFG_POS 7
/*! Field MIN_IFG - Minimum IFG,SFD and preamble */
#define SDMA_PRIO_11_MIN_IFG_MASK 0xF80u

/*! @} */

/*! \defgroup SDMA_PSTAT0_11 Register SDMA_PSTAT0_11 - Ethernet Switch Store DMA Port 11 Status Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT0_11 0x3010
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT0_11 0x18453010u

/*! Register Reset Value */
#define SDMA_PSTAT0_11_RST 0x00000000u

/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_11_HDR_PTR_POS 0
/*! Field HDR_PTR - Port Ingress Queue Header Pointer */
#define SDMA_PSTAT0_11_HDR_PTR_MASK 0x3FFu

/*! @} */

/*! \defgroup SDMA_PSTAT1_11 Register SDMA_PSTAT1_11 - Ethernet Switch Store DMA Port 11 Status Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_PSTAT1_11 0x3014
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_PSTAT1_11 0x18453014u

/*! Register Reset Value */
#define SDMA_PSTAT1_11_RST 0x00000000u

/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_11_PPKT_POS 0
/*! Field PPKT - Port Ingress Packet Count */
#define SDMA_PSTAT1_11_PPKT_MASK 0x7FFu

/*! @} */

/*! \defgroup SDMA_BYPASS_11 Register SDMA_BYPASS_11 - Ethernet Switch Store DMA PCE Bypass Register 11 */
/*! @{ */

/*! Register Offset (relative) */
#define SDMA_BYPASS_11 0x3018
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_SDMA_BYPASS_11 0x18453018u

/*! Register Reset Value */
#define SDMA_BYPASS_11_RST 0x00000000u

/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_11_MD_POS 0
/*! Field MD - PCE Bypass Queue Map Mode */
#define SDMA_BYPASS_11_MD_MASK 0x1u
/*! Constant SUBID - SUBID */
#define CONST_SDMA_BYPASS_11_MD_SUBID 0x0
/*! Constant SINGLE - SINGLE */
#define CONST_SDMA_BYPASS_11_MD_SINGLE 0x1

/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_11_NMQID_POS 1
/*! Field NMQID - PCE Bypass Non-Extracted Packet Starting QID */
#define SDMA_BYPASS_11_NMQID_MASK 0x3Eu

/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_11_EXTQID_POS 6
/*! Field EXTQID - PCE Bypass Extracted Packet QID */
#define SDMA_BYPASS_11_EXTQID_MASK 0x7C0u

/*! @} */

/*! \defgroup GSW_PMAC_ISR Register GSW_PMAC_ISR - PMAC Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_ISR 0x3404
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_ISR 0x18453404u

/*! Register Reset Value */
#define GSW_PMAC_ISR_RST 0x00000000u

/*! Field FCSERR - Frame Checksum Error Detected */
#define GSW_PMAC_ISR_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Detected */
#define GSW_PMAC_ISR_FCSERR_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_FCSERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_FCSERR_INT 0x1

/*! Field TOOLONG - Too Long Frame Error Detected */
#define GSW_PMAC_ISR_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Detected */
#define GSW_PMAC_ISR_TOOLONG_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_TOOLONG_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_TOOLONG_INT 0x1

/*! Field TOOSHORT - Too Short Frame Error Detected */
#define GSW_PMAC_ISR_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Detected */
#define GSW_PMAC_ISR_TOOSHORT_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_TOOSHORT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_TOOSHORT_INT 0x1

/*! Field IGCHKERR - Ingress Error Detected */
#define GSW_PMAC_ISR_IGCHKERR_POS 6
/*! Field IGCHKERR - Ingress Error Detected */
#define GSW_PMAC_ISR_IGCHKERR_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_IGCHKERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_IGCHKERR_INT 0x1

/*! @} */

/*! \defgroup GSW_PMAC_IER Register GSW_PMAC_IER - PMAC Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_IER 0x3408
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_IER 0x18453408u

/*! Register Reset Value */
#define GSW_PMAC_IER_RST 0x00000000u

/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define GSW_PMAC_IER_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define GSW_PMAC_IER_FCSERR_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_FCSERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_FCSERR_EN 0x1

/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define GSW_PMAC_IER_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define GSW_PMAC_IER_TOOLONG_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_TOOLONG_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_TOOLONG_EN 0x1

/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define GSW_PMAC_IER_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define GSW_PMAC_IER_TOOSHORT_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_TOOSHORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_TOOSHORT_EN 0x1

/*! Field IGCHKERR - Ingress Error Interrupt Mask */
#define GSW_PMAC_IER_IGCHKERR_POS 6
/*! Field IGCHKERR - Ingress Error Interrupt Mask */
#define GSW_PMAC_IER_IGCHKERR_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_IGCHKERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_IGCHKERR_EN 0x1

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_0 Register GSW_PMAC_CTRL_0 - PMAC Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_0 0x340C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_0 0x1845340Cu

/*! Register Reset Value */
#define GSW_PMAC_CTRL_0_RST 0x00001080u

/*! Field FCS - Transmit FCS Control */
#define GSW_PMAC_CTRL_0_FCS_POS 7
/*! Field FCS - Transmit FCS Control */
#define GSW_PMAC_CTRL_0_FCS_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_FCS_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_FCS_EN 0x1

/*! Field PADEN - Padding Enable */
#define GSW_PMAC_CTRL_0_PADEN_POS 8
/*! Field PADEN - Padding Enable */
#define GSW_PMAC_CTRL_0_PADEN_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_PADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_PADEN_EN 0x1

/*! Field VPADEN - VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_VPADEN_POS 9
/*! Field VPADEN - VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_VPADEN_MASK 0x200u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_VPADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_VPADEN_EN 0x1

/*! Field VPAD2EN - Stacked VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_VPAD2EN_POS 10
/*! Field VPAD2EN - Stacked VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_VPAD2EN_MASK 0x400u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_VPAD2EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_VPAD2EN_EN 0x1

/*! Field APADEN - Automatic VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_APADEN_POS 11
/*! Field APADEN - Automatic VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_APADEN_MASK 0x800u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_APADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_APADEN_EN 0x1

/*! Field FCSEN - FCS Enable Control */
#define GSW_PMAC_CTRL_0_FCSEN_POS 12
/*! Field FCSEN - FCS Enable Control */
#define GSW_PMAC_CTRL_0_FCSEN_MASK 0x1000u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_FCSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_FCSEN_EN 0x1

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_1 Register GSW_PMAC_CTRL_1 - PMAC Control Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_1 0x3410
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_1 0x18453410u

/*! Register Reset Value */
#define GSW_PMAC_CTRL_1_RST 0x00002800u

/*! Field MLEN - Maximum Frame Length Size in byte */
#define GSW_PMAC_CTRL_1_MLEN_POS 0
/*! Field MLEN - Maximum Frame Length Size in byte */
#define GSW_PMAC_CTRL_1_MLEN_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_2 Register GSW_PMAC_CTRL_2 - PMAC Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_2 0x3414
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_2 0x18453414u

/*! Register Reset Value */
#define GSW_PMAC_CTRL_2_RST 0x00000005u

/*! Field LCHKS - Frame Length Check Short Enable */
#define GSW_PMAC_CTRL_2_LCHKS_POS 0
/*! Field LCHKS - Frame Length Check Short Enable */
#define GSW_PMAC_CTRL_2_LCHKS_MASK 0x3u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_2_LCHKS_DIS 0x0
/*! Constant EN_UNTAG - EN_UNTAG */
#define CONST_GSW_PMAC_CTRL_2_LCHKS_EN_UNTAG 0x1
/*! Constant EN_TAG - EN_TAG */
#define CONST_GSW_PMAC_CTRL_2_LCHKS_EN_TAG 0x2
/*! Constant RESERVED - RESERVED */
#define CONST_GSW_PMAC_CTRL_2_LCHKS_RESERVED 0x3

/*! Field LCHKL - Frame Length Check Long Enable */
#define GSW_PMAC_CTRL_2_LCHKL_POS 2
/*! Field LCHKL - Frame Length Check Long Enable */
#define GSW_PMAC_CTRL_2_LCHKL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_2_LCHKL_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_2_LCHKL_EN 0x1

/*! Field TXFIFO - PMAC TX FIFO Available */
#define GSW_PMAC_CTRL_2_TXFIFO_POS 8
/*! Field TXFIFO - PMAC TX FIFO Available */
#define GSW_PMAC_CTRL_2_TXFIFO_MASK 0x100u
/*! Constant FULL - FULL */
#define CONST_GSW_PMAC_CTRL_2_TXFIFO_FULL 0x0
/*! Constant NFULL - NFULL */
#define CONST_GSW_PMAC_CTRL_2_TXFIFO_NFULL 0x1

/*! Field TXFSM - PMAC TX FSM */
#define GSW_PMAC_CTRL_2_TXFSM_POS 9
/*! Field TXFSM - PMAC TX FSM */
#define GSW_PMAC_CTRL_2_TXFSM_MASK 0xE00u
/*! Constant IDLE - IDLE */
#define CONST_GSW_PMAC_CTRL_2_TXFSM_IDLE 0x0
/*! Constant EGREAD - EGREAD */
#define CONST_GSW_PMAC_CTRL_2_TXFSM_EGREAD 0x1
/*! Constant L2HD - L2HD */
#define CONST_GSW_PMAC_CTRL_2_TXFSM_L2HD 0x2
/*! Constant STHD - STHD */
#define CONST_GSW_PMAC_CTRL_2_TXFSM_STHD 0x3
/*! Constant DATA - DATA */
#define CONST_GSW_PMAC_CTRL_2_TXFSM_DATA 0x4

/*! Field TXCHID - PMAC TX CHID */
#define GSW_PMAC_CTRL_2_TXCHID_POS 12
/*! Field TXCHID - PMAC TX CHID */
#define GSW_PMAC_CTRL_2_TXCHID_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_4 Register GSW_PMAC_CTRL_4 - PMAC Control Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_4 0x341C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_4 0x1845341Cu

/*! Register Reset Value */
#define GSW_PMAC_CTRL_4_RST 0x00000000u

/*! Field FLAGEN - Addressing Egress Configuration Table */
#define GSW_PMAC_CTRL_4_FLAGEN_POS 0
/*! Field FLAGEN - Addressing Egress Configuration Table */
#define GSW_PMAC_CTRL_4_FLAGEN_MASK 0x3u
/*! Constant TC - TC */
#define CONST_GSW_PMAC_CTRL_4_FLAGEN_TC 0x0
/*! Constant FLAG - FLAG */
#define CONST_GSW_PMAC_CTRL_4_FLAGEN_FLAG 0x1
/*! Constant MIXED - Mixed */
#define CONST_GSW_PMAC_CTRL_4_FLAGEN_MIXED 0x2

/*! Field RXFIFO - PMAC RX FIFO Available */
#define GSW_PMAC_CTRL_4_RXFIFO_POS 8
/*! Field RXFIFO - PMAC RX FIFO Available */
#define GSW_PMAC_CTRL_4_RXFIFO_MASK 0x100u
/*! Constant EMPTY - EMPTY */
#define CONST_GSW_PMAC_CTRL_4_RXFIFO_EMPTY 0x0
/*! Constant NEMPTY - NEMPTY */
#define CONST_GSW_PMAC_CTRL_4_RXFIFO_NEMPTY 0x1

/*! Field RXFSM - PMAC RX FSM */
#define GSW_PMAC_CTRL_4_RXFSM_POS 9
/*! Field RXFSM - PMAC RX FSM */
#define GSW_PMAC_CTRL_4_RXFSM_MASK 0xE00u
/*! Constant IDLE - IDLE */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_IDLE 0x0
/*! Constant IGCFG - IGCFG */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_IGCFG 0x1
/*! Constant DASA - DASA */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_DASA 0x2
/*! Constant STHD - STHD */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_STHD 0x3
/*! Constant L2HD - L2HD */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_L2HD 0x4
/*! Constant DATA - DATA */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_DATA 0x5
/*! Constant CRC - CRC */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_CRC 0x6
/*! Constant PMAC - PMAC */
#define CONST_GSW_PMAC_CTRL_4_RXFSM_PMAC 0x7

/*! Field RXCHID - PMAC RX CHID */
#define GSW_PMAC_CTRL_4_RXCHID_POS 12
/*! Field RXCHID - PMAC RX CHID */
#define GSW_PMAC_CTRL_4_RXCHID_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_0 Register GSW_PMAC_WMM_0 - PMAC WMM Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_0 0x3420
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_0 0x18453420u

/*! Register Reset Value */
#define GSW_PMAC_WMM_0_RST 0x00000000u

/*! Field WMM0 - WMM Value for traffic class 0 */
#define GSW_PMAC_WMM_0_WMM0_POS 0
/*! Field WMM0 - WMM Value for traffic class 0 */
#define GSW_PMAC_WMM_0_WMM0_MASK 0xFu

/*! Field WMM1 - WMM Value for traffic class 1 */
#define GSW_PMAC_WMM_0_WMM1_POS 4
/*! Field WMM1 - WMM Value for traffic class 1 */
#define GSW_PMAC_WMM_0_WMM1_MASK 0xF0u

/*! Field WMM2 - WMM Value for traffic class 2 */
#define GSW_PMAC_WMM_0_WMM2_POS 8
/*! Field WMM2 - WMM Value for traffic class 2 */
#define GSW_PMAC_WMM_0_WMM2_MASK 0xF00u

/*! Field WMM3 - WMM Value for traffic class 3 */
#define GSW_PMAC_WMM_0_WMM3_POS 12
/*! Field WMM3 - WMM Value for traffic class 3 */
#define GSW_PMAC_WMM_0_WMM3_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_1 Register GSW_PMAC_WMM_1 - PMAC WMM Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_1 0x3424
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_1 0x18453424u

/*! Register Reset Value */
#define GSW_PMAC_WMM_1_RST 0x00000000u

/*! Field WMM4 - WMM Value for traffic class 4 */
#define GSW_PMAC_WMM_1_WMM4_POS 0
/*! Field WMM4 - WMM Value for traffic class 4 */
#define GSW_PMAC_WMM_1_WMM4_MASK 0xFu

/*! Field WMM5 - WMM Value for traffic class 5 */
#define GSW_PMAC_WMM_1_WMM5_POS 4
/*! Field WMM5 - WMM Value for traffic class 5 */
#define GSW_PMAC_WMM_1_WMM5_MASK 0xF0u

/*! Field WMM6 - WMM Value for traffic class 6 */
#define GSW_PMAC_WMM_1_WMM6_POS 8
/*! Field WMM6 - WMM Value for traffic class 6 */
#define GSW_PMAC_WMM_1_WMM6_MASK 0xF00u

/*! Field WMM7 - WMM Value for traffic class 7 */
#define GSW_PMAC_WMM_1_WMM7_POS 12
/*! Field WMM7 - WMM Value for traffic class 7 */
#define GSW_PMAC_WMM_1_WMM7_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_2 Register GSW_PMAC_WMM_2 - PMAC WMM Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_2 0x3428
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_2 0x18453428u

/*! Register Reset Value */
#define GSW_PMAC_WMM_2_RST 0x00000000u

/*! Field WMM8 - WMM Value for traffic class 8 */
#define GSW_PMAC_WMM_2_WMM8_POS 0
/*! Field WMM8 - WMM Value for traffic class 8 */
#define GSW_PMAC_WMM_2_WMM8_MASK 0xFu

/*! Field WMM9 - WMM Value for traffic class 9 */
#define GSW_PMAC_WMM_2_WMM9_POS 4
/*! Field WMM9 - WMM Value for traffic class 9 */
#define GSW_PMAC_WMM_2_WMM9_MASK 0xF0u

/*! Field WMM10 - WMM Value for traffic class 10 */
#define GSW_PMAC_WMM_2_WMM10_POS 8
/*! Field WMM10 - WMM Value for traffic class 10 */
#define GSW_PMAC_WMM_2_WMM10_MASK 0xF00u

/*! Field WMM11 - WMM Value for traffic class 11 */
#define GSW_PMAC_WMM_2_WMM11_POS 12
/*! Field WMM11 - WMM Value for traffic class 11 */
#define GSW_PMAC_WMM_2_WMM11_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_3 Register GSW_PMAC_WMM_3 - PMAC WMM Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_3 0x342C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_3 0x1845342Cu

/*! Register Reset Value */
#define GSW_PMAC_WMM_3_RST 0x00000000u

/*! Field WMM12 - WMM Value for traffic class 12 */
#define GSW_PMAC_WMM_3_WMM12_POS 0
/*! Field WMM12 - WMM Value for traffic class 12 */
#define GSW_PMAC_WMM_3_WMM12_MASK 0xFu

/*! Field WMM13 - WMM Value for traffic class 13 */
#define GSW_PMAC_WMM_3_WMM13_POS 4
/*! Field WMM13 - WMM Value for traffic class 13 */
#define GSW_PMAC_WMM_3_WMM13_MASK 0xF0u

/*! Field WMM14 - WMM Value for traffic class 14 */
#define GSW_PMAC_WMM_3_WMM14_POS 8
/*! Field WMM14 - WMM Value for traffic class 14 */
#define GSW_PMAC_WMM_3_WMM14_MASK 0xF00u

/*! Field WMM15 - WMM Value for traffic class 15 */
#define GSW_PMAC_WMM_3_WMM15_POS 12
/*! Field WMM15 - WMM Value for traffic class 15 */
#define GSW_PMAC_WMM_3_WMM15_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_BSL_LEN0 Register GSW_PMAC_BSL_LEN0 - PMAC BSL Length Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_BSL_LEN0 0x3440
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_BSL_LEN0 0x18453440u

/*! Register Reset Value */
#define GSW_PMAC_BSL_LEN0_RST 0x00000000u

/*! Field LEN0 - Frame Length Threshold for BSL Buffer 0 */
#define GSW_PMAC_BSL_LEN0_LEN0_POS 0
/*! Field LEN0 - Frame Length Threshold for BSL Buffer 0 */
#define GSW_PMAC_BSL_LEN0_LEN0_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_BSL_LEN1 Register GSW_PMAC_BSL_LEN1 - PMAC BSL Length Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_BSL_LEN1 0x3444
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_BSL_LEN1 0x18453444u

/*! Register Reset Value */
#define GSW_PMAC_BSL_LEN1_RST 0x00000000u

/*! Field LEN1 - Frame Length Threshold for BSL Buffer 1 */
#define GSW_PMAC_BSL_LEN1_LEN1_POS 0
/*! Field LEN1 - Frame Length Threshold for BSL Buffer 1 */
#define GSW_PMAC_BSL_LEN1_LEN1_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_BSL_LEN2 Register GSW_PMAC_BSL_LEN2 - PMAC BSL Length Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_BSL_LEN2 0x3448
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_BSL_LEN2 0x18453448u

/*! Register Reset Value */
#define GSW_PMAC_BSL_LEN2_RST 0x00000000u

/*! Field LEN2 - Frame Length Threshold for BSL Buffer 2 */
#define GSW_PMAC_BSL_LEN2_LEN2_POS 0
/*! Field LEN2 - Frame Length Threshold for BSL Buffer 2 */
#define GSW_PMAC_BSL_LEN2_LEN2_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_4 Register GSW_PMAC_TBL_VAL_4 - Table Value Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_4 0x3500
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_4 0x18453500u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_4_RST 0x00000000u

/*! Field VAL4 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_4_VAL4_POS 0
/*! Field VAL4 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_4_VAL4_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_3 Register GSW_PMAC_TBL_VAL_3 - Table Value Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_3 0x3504
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_3 0x18453504u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_3_RST 0x00000000u

/*! Field VAL3 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_3_VAL3_POS 0
/*! Field VAL3 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_3_VAL3_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_2 Register GSW_PMAC_TBL_VAL_2 - Table Value Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_2 0x3508
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_2 0x18453508u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_2_RST 0x00000000u

/*! Field VAL2 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_2_VAL2_POS 0
/*! Field VAL2 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_2_VAL2_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_1 Register GSW_PMAC_TBL_VAL_1 - Table Value Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_1 0x350C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_1 0x1845350Cu

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_1_RST 0x00000000u

/*! Field VAL1 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_1_VAL1_POS 0
/*! Field VAL1 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_1_VAL1_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_0 Register GSW_PMAC_TBL_VAL_0 - Table Value Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_0 0x3510
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_0 0x18453510u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_0_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_0_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_0_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_ADDR Register GSW_PMAC_TBL_ADDR - Table Entry Address Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_ADDR 0x3514
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_ADDR 0x18453514u

/*! Register Reset Value */
#define GSW_PMAC_TBL_ADDR_RST 0x00000000u

/*! Field ADDR - Table Address */
#define GSW_PMAC_TBL_ADDR_ADDR_POS 0
/*! Field ADDR - Table Address */
#define GSW_PMAC_TBL_ADDR_ADDR_MASK 0xFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_CTRL Register GSW_PMAC_TBL_CTRL - Table Access Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_CTRL 0x3518
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_CTRL 0x18453518u

/*! Register Reset Value */
#define GSW_PMAC_TBL_CTRL_RST 0x00000000u

/*! Field ADDR - Lookup Table Address */
#define GSW_PMAC_TBL_CTRL_ADDR_POS 0
/*! Field ADDR - Lookup Table Address */
#define GSW_PMAC_TBL_CTRL_ADDR_MASK 0x7u
/*! Constant BPMAP - BPMAP */
#define CONST_GSW_PMAC_TBL_CTRL_ADDR_BPMAP 0x0
/*! Constant IGCFG - IGCFG */
#define CONST_GSW_PMAC_TBL_CTRL_ADDR_IGCFG 0x1
/*! Constant EGCFG - EGCFG */
#define CONST_GSW_PMAC_TBL_CTRL_ADDR_EGCFG 0x2

/*! Field OPMOD - Lookup Table Access Operation Mode */
#define GSW_PMAC_TBL_CTRL_OPMOD_POS 5
/*! Field OPMOD - Lookup Table Access Operation Mode */
#define GSW_PMAC_TBL_CTRL_OPMOD_MASK 0x20u
/*! Constant RD - RD */
#define CONST_GSW_PMAC_TBL_CTRL_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_GSW_PMAC_TBL_CTRL_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define GSW_PMAC_TBL_CTRL_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define GSW_PMAC_TBL_CTRL_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_GSW_PMAC_TBL_CTRL_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_GSW_PMAC_TBL_CTRL_BAS_BUSY 0x1

/*! @} */

/*! \defgroup GSW_PMAC_ISR_1 Register GSW_PMAC_ISR_1 - PMAC Interrupt Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_ISR_1 0x3604
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_ISR_1 0x18453604u

/*! Register Reset Value */
#define GSW_PMAC_ISR_1_RST 0x00000000u

/*! Field FCSERR - Frame Checksum Error Detected */
#define GSW_PMAC_ISR_1_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Detected */
#define GSW_PMAC_ISR_1_FCSERR_MASK 0x4u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_1_FCSERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_1_FCSERR_INT 0x1

/*! Field TOOLONG - Too Long Frame Error Detected */
#define GSW_PMAC_ISR_1_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Detected */
#define GSW_PMAC_ISR_1_TOOLONG_MASK 0x10u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_1_TOOLONG_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_1_TOOLONG_INT 0x1

/*! Field TOOSHORT - Too Short Frame Error Detected */
#define GSW_PMAC_ISR_1_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Detected */
#define GSW_PMAC_ISR_1_TOOSHORT_MASK 0x20u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_1_TOOSHORT_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_1_TOOSHORT_INT 0x1

/*! Field IGCHKERR - Ingress Error Detected */
#define GSW_PMAC_ISR_1_IGCHKERR_POS 6
/*! Field IGCHKERR - Ingress Error Detected */
#define GSW_PMAC_ISR_1_IGCHKERR_MASK 0x40u
/*! Constant NOINT - NOINT */
#define CONST_GSW_PMAC_ISR_1_IGCHKERR_NOINT 0x0
/*! Constant INT - INT */
#define CONST_GSW_PMAC_ISR_1_IGCHKERR_INT 0x1

/*! @} */

/*! \defgroup GSW_PMAC_IER_1 Register GSW_PMAC_IER_1 - PMAC Interrupt Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_IER_1 0x3608
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_IER_1 0x18453608u

/*! Register Reset Value */
#define GSW_PMAC_IER_1_RST 0x00000000u

/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define GSW_PMAC_IER_1_FCSERR_POS 2
/*! Field FCSERR - Frame Checksum Error Interrupt Mask */
#define GSW_PMAC_IER_1_FCSERR_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_1_FCSERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_1_FCSERR_EN 0x1

/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define GSW_PMAC_IER_1_TOOLONG_POS 4
/*! Field TOOLONG - Too Long Frame Error Interrupt Mask */
#define GSW_PMAC_IER_1_TOOLONG_MASK 0x10u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_1_TOOLONG_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_1_TOOLONG_EN 0x1

/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define GSW_PMAC_IER_1_TOOSHORT_POS 5
/*! Field TOOSHORT - Too Short Frame Error Interrupt Mask */
#define GSW_PMAC_IER_1_TOOSHORT_MASK 0x20u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_1_TOOSHORT_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_1_TOOSHORT_EN 0x1

/*! Field IGCHKERR - Ingress Error Interrupt Mask */
#define GSW_PMAC_IER_1_IGCHKERR_POS 6
/*! Field IGCHKERR - Ingress Error Interrupt Mask */
#define GSW_PMAC_IER_1_IGCHKERR_MASK 0x40u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_IER_1_IGCHKERR_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_IER_1_IGCHKERR_EN 0x1

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_0_1 Register GSW_PMAC_CTRL_0_1 - PMAC Control Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_0_1 0x360C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_0_1 0x1845360Cu

/*! Register Reset Value */
#define GSW_PMAC_CTRL_0_1_RST 0x00001080u

/*! Field FCS - Transmit FCS Control */
#define GSW_PMAC_CTRL_0_1_FCS_POS 7
/*! Field FCS - Transmit FCS Control */
#define GSW_PMAC_CTRL_0_1_FCS_MASK 0x80u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_1_FCS_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_1_FCS_EN 0x1

/*! Field PADEN - Padding Enable */
#define GSW_PMAC_CTRL_0_1_PADEN_POS 8
/*! Field PADEN - Padding Enable */
#define GSW_PMAC_CTRL_0_1_PADEN_MASK 0x100u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_1_PADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_1_PADEN_EN 0x1

/*! Field VPADEN - VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_1_VPADEN_POS 9
/*! Field VPADEN - VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_1_VPADEN_MASK 0x200u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_1_VPADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_1_VPADEN_EN 0x1

/*! Field VPAD2EN - Stacked VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_1_VPAD2EN_POS 10
/*! Field VPAD2EN - Stacked VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_1_VPAD2EN_MASK 0x400u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_1_VPAD2EN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_1_VPAD2EN_EN 0x1

/*! Field APADEN - Automatic VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_1_APADEN_POS 11
/*! Field APADEN - Automatic VLAN Padding Enable */
#define GSW_PMAC_CTRL_0_1_APADEN_MASK 0x800u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_1_APADEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_1_APADEN_EN 0x1

/*! Field FCSEN - FCS Enable Control */
#define GSW_PMAC_CTRL_0_1_FCSEN_POS 12
/*! Field FCSEN - FCS Enable Control */
#define GSW_PMAC_CTRL_0_1_FCSEN_MASK 0x1000u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_0_1_FCSEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_0_1_FCSEN_EN 0x1

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_1_1 Register GSW_PMAC_CTRL_1_1 - PMAC Configuration Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_1_1 0x3610
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_1_1 0x18453610u

/*! Register Reset Value */
#define GSW_PMAC_CTRL_1_1_RST 0x00002800u

/*! Field MLEN - Maximum Frame Length Size in byte */
#define GSW_PMAC_CTRL_1_1_MLEN_POS 0
/*! Field MLEN - Maximum Frame Length Size in byte */
#define GSW_PMAC_CTRL_1_1_MLEN_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_2_1 Register GSW_PMAC_CTRL_2_1 - PMAC Control Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_2_1 0x3614
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_2_1 0x18453614u

/*! Register Reset Value */
#define GSW_PMAC_CTRL_2_1_RST 0x00000005u

/*! Field LCHKS - Frame Length Check Short Enable */
#define GSW_PMAC_CTRL_2_1_LCHKS_POS 0
/*! Field LCHKS - Frame Length Check Short Enable */
#define GSW_PMAC_CTRL_2_1_LCHKS_MASK 0x3u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_2_1_LCHKS_DIS 0x0
/*! Constant EN_UNTAG - EN_UNTAG */
#define CONST_GSW_PMAC_CTRL_2_1_LCHKS_EN_UNTAG 0x1
/*! Constant EN_TAG - EN_TAG */
#define CONST_GSW_PMAC_CTRL_2_1_LCHKS_EN_TAG 0x2
/*! Constant RESERVED - RESERVED */
#define CONST_GSW_PMAC_CTRL_2_1_LCHKS_RESERVED 0x3

/*! Field LCHKL - Frame Length Check Long Enable */
#define GSW_PMAC_CTRL_2_1_LCHKL_POS 2
/*! Field LCHKL - Frame Length Check Long Enable */
#define GSW_PMAC_CTRL_2_1_LCHKL_MASK 0x4u
/*! Constant DIS - DIS */
#define CONST_GSW_PMAC_CTRL_2_1_LCHKL_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PMAC_CTRL_2_1_LCHKL_EN 0x1

/*! Field TXFIFO - PMAC TX FIFO Available */
#define GSW_PMAC_CTRL_2_1_TXFIFO_POS 8
/*! Field TXFIFO - PMAC TX FIFO Available */
#define GSW_PMAC_CTRL_2_1_TXFIFO_MASK 0x100u
/*! Constant FULL - FULL */
#define CONST_GSW_PMAC_CTRL_2_1_TXFIFO_FULL 0x0
/*! Constant NFULL - NFULL */
#define CONST_GSW_PMAC_CTRL_2_1_TXFIFO_NFULL 0x1

/*! Field TXFSM - PMAC TX FSM */
#define GSW_PMAC_CTRL_2_1_TXFSM_POS 9
/*! Field TXFSM - PMAC TX FSM */
#define GSW_PMAC_CTRL_2_1_TXFSM_MASK 0xE00u
/*! Constant IDLE - IDLE */
#define CONST_GSW_PMAC_CTRL_2_1_TXFSM_IDLE 0x0
/*! Constant EGREAD - EGREAD */
#define CONST_GSW_PMAC_CTRL_2_1_TXFSM_EGREAD 0x1
/*! Constant L2HD - L2HD */
#define CONST_GSW_PMAC_CTRL_2_1_TXFSM_L2HD 0x2
/*! Constant STHD - STHD */
#define CONST_GSW_PMAC_CTRL_2_1_TXFSM_STHD 0x3
/*! Constant DATA - DATA */
#define CONST_GSW_PMAC_CTRL_2_1_TXFSM_DATA 0x4

/*! Field TXCHID - PMAC TX CHID */
#define GSW_PMAC_CTRL_2_1_TXCHID_POS 12
/*! Field TXCHID - PMAC TX CHID */
#define GSW_PMAC_CTRL_2_1_TXCHID_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_CTRL_4_1 Register GSW_PMAC_CTRL_4_1 - PMAC Control Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_CTRL_4_1 0x361C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_CTRL_4_1 0x1845361Cu

/*! Register Reset Value */
#define GSW_PMAC_CTRL_4_1_RST 0x00000000u

/*! Field FLAGEN - Addressing Egress Configuration Table */
#define GSW_PMAC_CTRL_4_1_FLAGEN_POS 0
/*! Field FLAGEN - Addressing Egress Configuration Table */
#define GSW_PMAC_CTRL_4_1_FLAGEN_MASK 0x3u
/*! Constant TC - TC */
#define CONST_GSW_PMAC_CTRL_4_1_FLAGEN_TC 0x0
/*! Constant FLAG - FLAG */
#define CONST_GSW_PMAC_CTRL_4_1_FLAGEN_FLAG 0x1
/*! Constant MIXED - Mixed */
#define CONST_GSW_PMAC_CTRL_4_1_FLAGEN_MIXED 0x2

/*! Field RXFIFO - PMAC RX FIFO Available */
#define GSW_PMAC_CTRL_4_1_RXFIFO_POS 8
/*! Field RXFIFO - PMAC RX FIFO Available */
#define GSW_PMAC_CTRL_4_1_RXFIFO_MASK 0x100u
/*! Constant EMPTY - EMPTY */
#define CONST_GSW_PMAC_CTRL_4_1_RXFIFO_EMPTY 0x0
/*! Constant NEMPTY - NEMPTY */
#define CONST_GSW_PMAC_CTRL_4_1_RXFIFO_NEMPTY 0x1

/*! Field RXFSM - PMAC RX FSM */
#define GSW_PMAC_CTRL_4_1_RXFSM_POS 9
/*! Field RXFSM - PMAC RX FSM */
#define GSW_PMAC_CTRL_4_1_RXFSM_MASK 0xE00u
/*! Constant IDLE - IDLE */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_IDLE 0x0
/*! Constant IGCFG - IGCFG */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_IGCFG 0x1
/*! Constant DASA - DASA */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_DASA 0x2
/*! Constant STHD - STHD */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_STHD 0x3
/*! Constant L2HD - L2HD */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_L2HD 0x4
/*! Constant DATA - DATA */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_DATA 0x5
/*! Constant CRC - CRC */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_CRC 0x6
/*! Constant PMAC - PMAC */
#define CONST_GSW_PMAC_CTRL_4_1_RXFSM_PMAC 0x7

/*! Field RXCHID - PMAC RX CHID */
#define GSW_PMAC_CTRL_4_1_RXCHID_POS 12
/*! Field RXCHID - PMAC RX CHID */
#define GSW_PMAC_CTRL_4_1_RXCHID_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_0_1 Register GSW_PMAC_WMM_0_1 - PMAC WMM Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_0_1 0x3620
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_0_1 0x18453620u

/*! Register Reset Value */
#define GSW_PMAC_WMM_0_1_RST 0x00000000u

/*! Field WMM0 - WMM Value for traffic class 0 */
#define GSW_PMAC_WMM_0_1_WMM0_POS 0
/*! Field WMM0 - WMM Value for traffic class 0 */
#define GSW_PMAC_WMM_0_1_WMM0_MASK 0xFu

/*! Field WMM1 - WMM Value for traffic class 1 */
#define GSW_PMAC_WMM_0_1_WMM1_POS 4
/*! Field WMM1 - WMM Value for traffic class 1 */
#define GSW_PMAC_WMM_0_1_WMM1_MASK 0xF0u

/*! Field WMM2 - WMM Value for traffic class 2 */
#define GSW_PMAC_WMM_0_1_WMM2_POS 8
/*! Field WMM2 - WMM Value for traffic class 2 */
#define GSW_PMAC_WMM_0_1_WMM2_MASK 0xF00u

/*! Field WMM3 - WMM Value for traffic class 3 */
#define GSW_PMAC_WMM_0_1_WMM3_POS 12
/*! Field WMM3 - WMM Value for traffic class 3 */
#define GSW_PMAC_WMM_0_1_WMM3_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_1_1 Register GSW_PMAC_WMM_1_1 - PMAC WMM Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_1_1 0x3624
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_1_1 0x18453624u

/*! Register Reset Value */
#define GSW_PMAC_WMM_1_1_RST 0x00000000u

/*! Field WMM4 - WMM Value for traffic class 4 */
#define GSW_PMAC_WMM_1_1_WMM4_POS 0
/*! Field WMM4 - WMM Value for traffic class 4 */
#define GSW_PMAC_WMM_1_1_WMM4_MASK 0xFu

/*! Field WMM5 - WMM Value for traffic class 5 */
#define GSW_PMAC_WMM_1_1_WMM5_POS 4
/*! Field WMM5 - WMM Value for traffic class 5 */
#define GSW_PMAC_WMM_1_1_WMM5_MASK 0xF0u

/*! Field WMM6 - WMM Value for traffic class 6 */
#define GSW_PMAC_WMM_1_1_WMM6_POS 8
/*! Field WMM6 - WMM Value for traffic class 6 */
#define GSW_PMAC_WMM_1_1_WMM6_MASK 0xF00u

/*! Field WMM7 - WMM Value for traffic class 7 */
#define GSW_PMAC_WMM_1_1_WMM7_POS 12
/*! Field WMM7 - WMM Value for traffic class 7 */
#define GSW_PMAC_WMM_1_1_WMM7_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_2_1 Register GSW_PMAC_WMM_2_1 - PMAC WMM Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_2_1 0x3628
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_2_1 0x18453628u

/*! Register Reset Value */
#define GSW_PMAC_WMM_2_1_RST 0x00000000u

/*! Field WMM8 - WMM Value for traffic class 8 */
#define GSW_PMAC_WMM_2_1_WMM8_POS 0
/*! Field WMM8 - WMM Value for traffic class 8 */
#define GSW_PMAC_WMM_2_1_WMM8_MASK 0xFu

/*! Field WMM9 - WMM Value for traffic class 9 */
#define GSW_PMAC_WMM_2_1_WMM9_POS 4
/*! Field WMM9 - WMM Value for traffic class 9 */
#define GSW_PMAC_WMM_2_1_WMM9_MASK 0xF0u

/*! Field WMM10 - WMM Value for traffic class 10 */
#define GSW_PMAC_WMM_2_1_WMM10_POS 8
/*! Field WMM10 - WMM Value for traffic class 10 */
#define GSW_PMAC_WMM_2_1_WMM10_MASK 0xF00u

/*! Field WMM11 - WMM Value for traffic class 11 */
#define GSW_PMAC_WMM_2_1_WMM11_POS 12
/*! Field WMM11 - WMM Value for traffic class 11 */
#define GSW_PMAC_WMM_2_1_WMM11_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_WMM_3_1 Register GSW_PMAC_WMM_3_1 - PMAC WMM Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_WMM_3_1 0x362C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_WMM_3_1 0x1845362Cu

/*! Register Reset Value */
#define GSW_PMAC_WMM_3_1_RST 0x00000000u

/*! Field WMM12 - WMM Value for traffic class 12 */
#define GSW_PMAC_WMM_3_1_WMM12_POS 0
/*! Field WMM12 - WMM Value for traffic class 12 */
#define GSW_PMAC_WMM_3_1_WMM12_MASK 0xFu

/*! Field WMM13 - WMM Value for traffic class 13 */
#define GSW_PMAC_WMM_3_1_WMM13_POS 4
/*! Field WMM13 - WMM Value for traffic class 13 */
#define GSW_PMAC_WMM_3_1_WMM13_MASK 0xF0u

/*! Field WMM14 - WMM Value for traffic class 14 */
#define GSW_PMAC_WMM_3_1_WMM14_POS 8
/*! Field WMM14 - WMM Value for traffic class 14 */
#define GSW_PMAC_WMM_3_1_WMM14_MASK 0xF00u

/*! Field WMM15 - WMM Value for traffic class 15 */
#define GSW_PMAC_WMM_3_1_WMM15_POS 12
/*! Field WMM15 - WMM Value for traffic class 15 */
#define GSW_PMAC_WMM_3_1_WMM15_MASK 0xF000u

/*! @} */

/*! \defgroup GSW_PMAC_BSL_LEN0_1 Register GSW_PMAC_BSL_LEN0_1 - PMAC BSL Length Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_BSL_LEN0_1 0x3640
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_BSL_LEN0_1 0x18453640u

/*! Register Reset Value */
#define GSW_PMAC_BSL_LEN0_1_RST 0x00000000u

/*! Field LEN0 - Frame Length Threshold for BSL Buffer 0 */
#define GSW_PMAC_BSL_LEN0_1_LEN0_POS 0
/*! Field LEN0 - Frame Length Threshold for BSL Buffer 0 */
#define GSW_PMAC_BSL_LEN0_1_LEN0_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_BSL_LEN1_1 Register GSW_PMAC_BSL_LEN1_1 - PMAC BSL Length Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_BSL_LEN1_1 0x3644
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_BSL_LEN1_1 0x18453644u

/*! Register Reset Value */
#define GSW_PMAC_BSL_LEN1_1_RST 0x00000000u

/*! Field LEN1 - Frame Length Threshold for BSL Buffer 1 */
#define GSW_PMAC_BSL_LEN1_1_LEN1_POS 0
/*! Field LEN1 - Frame Length Threshold for BSL Buffer 1 */
#define GSW_PMAC_BSL_LEN1_1_LEN1_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_BSL_LEN2_1 Register GSW_PMAC_BSL_LEN2_1 - PMAC BSL Length Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_BSL_LEN2_1 0x3648
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_BSL_LEN2_1 0x18453648u

/*! Register Reset Value */
#define GSW_PMAC_BSL_LEN2_1_RST 0x00000000u

/*! Field LEN2 - Frame Length Threshold for BSL Buffer 2 */
#define GSW_PMAC_BSL_LEN2_1_LEN2_POS 0
/*! Field LEN2 - Frame Length Threshold for BSL Buffer 2 */
#define GSW_PMAC_BSL_LEN2_1_LEN2_MASK 0x3FFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_4_1 Register GSW_PMAC_TBL_VAL_4_1 - PMAC Table Value Register 4 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_4_1 0x3700
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_4_1 0x18453700u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_4_1_RST 0x00000000u

/*! Field VAL4 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_4_1_VAL4_POS 0
/*! Field VAL4 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_4_1_VAL4_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_3_1 Register GSW_PMAC_TBL_VAL_3_1 - PMAC Table Value Register 3 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_3_1 0x3704
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_3_1 0x18453704u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_3_1_RST 0x00000000u

/*! Field VAL3 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_3_1_VAL3_POS 0
/*! Field VAL3 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_3_1_VAL3_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_2_1 Register GSW_PMAC_TBL_VAL_2_1 - PMAC Table Value Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_2_1 0x3708
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_2_1 0x18453708u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_2_1_RST 0x00000000u

/*! Field VAL2 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_2_1_VAL2_POS 0
/*! Field VAL2 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_2_1_VAL2_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_1_1 Register GSW_PMAC_TBL_VAL_1_1 - PMAC Table Value Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_1_1 0x370C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_1_1 0x1845370Cu

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_1_1_RST 0x00000000u

/*! Field VAL1 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_1_1_VAL1_POS 0
/*! Field VAL1 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_1_1_VAL1_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_VAL_0_1 Register GSW_PMAC_TBL_VAL_0_1 - PMAC Table Value Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_VAL_0_1 0x3710
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_VAL_0_1 0x18453710u

/*! Register Reset Value */
#define GSW_PMAC_TBL_VAL_0_1_RST 0x00000000u

/*! Field VAL0 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_0_1_VAL0_POS 0
/*! Field VAL0 - Data value [15:0] */
#define GSW_PMAC_TBL_VAL_0_1_VAL0_MASK 0xFFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_ADDR_1 Register GSW_PMAC_TBL_ADDR_1 - PMAC Table Address Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_ADDR_1 0x3714
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_ADDR_1 0x18453714u

/*! Register Reset Value */
#define GSW_PMAC_TBL_ADDR_1_RST 0x00000000u

/*! Field ADDR - Table Address */
#define GSW_PMAC_TBL_ADDR_1_ADDR_POS 0
/*! Field ADDR - Table Address */
#define GSW_PMAC_TBL_ADDR_1_ADDR_MASK 0xFFFu

/*! @} */

/*! \defgroup GSW_PMAC_TBL_CTRL_1 Register GSW_PMAC_TBL_CTRL_1 - PMAC Table Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PMAC_TBL_CTRL_1 0x3718
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PMAC_TBL_CTRL_1 0x18453718u

/*! Register Reset Value */
#define GSW_PMAC_TBL_CTRL_1_RST 0x00000000u

/*! Field ADDR - Lookup Table Address */
#define GSW_PMAC_TBL_CTRL_1_ADDR_POS 0
/*! Field ADDR - Lookup Table Address */
#define GSW_PMAC_TBL_CTRL_1_ADDR_MASK 0x7u
/*! Constant BPMAP - BPMAP */
#define CONST_GSW_PMAC_TBL_CTRL_1_ADDR_BPMAP 0x0
/*! Constant IGCFG - IGCFG */
#define CONST_GSW_PMAC_TBL_CTRL_1_ADDR_IGCFG 0x1
/*! Constant EGCFG - EGCFG */
#define CONST_GSW_PMAC_TBL_CTRL_1_ADDR_EGCFG 0x2

/*! Field OPMOD - Lookup Table Access Operation Mode */
#define GSW_PMAC_TBL_CTRL_1_OPMOD_POS 5
/*! Field OPMOD - Lookup Table Access Operation Mode */
#define GSW_PMAC_TBL_CTRL_1_OPMOD_MASK 0x20u
/*! Constant RD - RD */
#define CONST_GSW_PMAC_TBL_CTRL_1_OPMOD_RD 0x0
/*! Constant WR - WR */
#define CONST_GSW_PMAC_TBL_CTRL_1_OPMOD_WR 0x1

/*! Field BAS - Access Busy/Access Start */
#define GSW_PMAC_TBL_CTRL_1_BAS_POS 15
/*! Field BAS - Access Busy/Access Start */
#define GSW_PMAC_TBL_CTRL_1_BAS_MASK 0x8000u
/*! Constant READY - READY */
#define CONST_GSW_PMAC_TBL_CTRL_1_BAS_READY 0x0
/*! Constant BUSY - BUSY */
#define CONST_GSW_PMAC_TBL_CTRL_1_BAS_BUSY 0x1

/*! @} */

/*! \defgroup GSW_INST_SEL Register GSW_INST_SEL - Instance Selection Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_INST_SEL 0x3800
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_INST_SEL 0x18453800u

/*! Register Reset Value */
#define GSW_INST_SEL_RST 0x00000000u

/*! Field INST - Instance Selection */
#define GSW_INST_SEL_INST_POS 0
/*! Field INST - Instance Selection */
#define GSW_INST_SEL_INST_MASK 0x7Fu

/*! @} */

/*! \defgroup GSW_PCE_TCM_CTRL Register GSW_PCE_TCM_CTRL - Three-color Marker Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_CTRL 0x3840
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_CTRL 0x18453840u

/*! Register Reset Value */
#define GSW_PCE_TCM_CTRL_RST 0x00000000u

/*! Field TCMEN - Three-color Marker metering instance enable */
#define GSW_PCE_TCM_CTRL_TCMEN_POS 0
/*! Field TCMEN - Three-color Marker metering instance enable */
#define GSW_PCE_TCM_CTRL_TCMEN_MASK 0x1u
/*! Constant DIS - DIS */
#define CONST_GSW_PCE_TCM_CTRL_TCMEN_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PCE_TCM_CTRL_TCMEN_EN 0x1

/*! Field TEBYP - Te Bucket Check Bypass */
#define GSW_PCE_TCM_CTRL_TEBYP_POS 1
/*! Field TEBYP - Te Bucket Check Bypass */
#define GSW_PCE_TCM_CTRL_TEBYP_MASK 0x2u
/*! Constant DIS - DIS */
#define CONST_GSW_PCE_TCM_CTRL_TEBYP_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PCE_TCM_CTRL_TEBYP_EN 0x1

/*! Field TMOD - Meter Mode */
#define GSW_PCE_TCM_CTRL_TMOD_POS 2
/*! Field TMOD - Meter Mode */
#define GSW_PCE_TCM_CTRL_TMOD_MASK 0x4u
/*! Constant SINGLE - Single */
#define CONST_GSW_PCE_TCM_CTRL_TMOD_SINGLE 0x0
/*! Constant TWO - Two */
#define CONST_GSW_PCE_TCM_CTRL_TMOD_TWO 0x1

/*! Field BLIND - Meter Color Blind */
#define GSW_PCE_TCM_CTRL_BLIND_POS 3
/*! Field BLIND - Meter Color Blind */
#define GSW_PCE_TCM_CTRL_BLIND_MASK 0x8u
/*! Constant DIS - DIS */
#define CONST_GSW_PCE_TCM_CTRL_BLIND_DIS 0x0
/*! Constant EN - EN */
#define CONST_GSW_PCE_TCM_CTRL_BLIND_EN 0x1

/*! @} */

/*! \defgroup GSW_PCE_TCM_STAT Register GSW_PCE_TCM_STAT - Three-color Marker Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_STAT 0x3844
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_STAT 0x18453844u

/*! Register Reset Value */
#define GSW_PCE_TCM_STAT_RST 0x00000000u

/*! Field MTEBP - Metering Based Back Pressure Status */
#define GSW_PCE_TCM_STAT_MTEBP_POS 0
/*! Field MTEBP - Metering Based Back Pressure Status */
#define GSW_PCE_TCM_STAT_MTEBP_MASK 0x1u
/*! Constant NOBP - NOBP */
#define CONST_GSW_PCE_TCM_STAT_MTEBP_NOBP 0x0
/*! Constant BP - BP */
#define CONST_GSW_PCE_TCM_STAT_MTEBP_BP 0x1

/*! Field AL0 - Three-color Marker Alert 0 Status */
#define GSW_PCE_TCM_STAT_AL0_POS 1
/*! Field AL0 - Three-color Marker Alert 0 Status */
#define GSW_PCE_TCM_STAT_AL0_MASK 0x2u
/*! Constant OK - OK */
#define CONST_GSW_PCE_TCM_STAT_AL0_OK 0x0
/*! Constant ALERT - ALERT */
#define CONST_GSW_PCE_TCM_STAT_AL0_ALERT 0x1

/*! Field AL1 - Three-color Marker Alert 1 Status */
#define GSW_PCE_TCM_STAT_AL1_POS 2
/*! Field AL1 - Three-color Marker Alert 1 Status */
#define GSW_PCE_TCM_STAT_AL1_MASK 0x4u
/*! Constant OK - OK */
#define CONST_GSW_PCE_TCM_STAT_AL1_OK 0x0
/*! Constant ALERT - ALERT */
#define CONST_GSW_PCE_TCM_STAT_AL1_ALERT 0x1

/*! @} */

/*! \defgroup GSW_PCE_TCM_CBS Register GSW_PCE_TCM_CBS - Three-color Marker Committed Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_CBS 0x3848
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_CBS 0x18453848u

/*! Register Reset Value */
#define GSW_PCE_TCM_CBS_RST 0x00000000u

/*! Field CBS - Committed Burst Size */
#define GSW_PCE_TCM_CBS_CBS_POS 0
/*! Field CBS - Committed Burst Size */
#define GSW_PCE_TCM_CBS_CBS_MASK 0x3FFu

/*! @} */

/*! \defgroup GSW_PCE_TCM_EBS Register GSW_PCE_TCM_EBS - Three-color Marker Excess Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_EBS 0x384C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_EBS 0x1845384Cu

/*! Register Reset Value */
#define GSW_PCE_TCM_EBS_RST 0x00000000u

/*! Field EBS - Excess/Peak Burst Size */
#define GSW_PCE_TCM_EBS_EBS_POS 0
/*! Field EBS - Excess/Peak Burst Size */
#define GSW_PCE_TCM_EBS_EBS_MASK 0x3FFu

/*! @} */

/*! \defgroup GSW_PCE_TCM_IBS Register GSW_PCE_TCM_IBS - Three-color Marker Instantaneous Burst Size Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_IBS 0x3850
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_IBS 0x18453850u

/*! Register Reset Value */
#define GSW_PCE_TCM_IBS_RST 0x00000000u

/*! Field IBS - Instantaneous Burst Size */
#define GSW_PCE_TCM_IBS_IBS_POS 0
/*! Field IBS - Instantaneous Burst Size */
#define GSW_PCE_TCM_IBS_IBS_MASK 0x3FFu

/*! @} */

/*! \defgroup GSW_PCE_TCM_CIR_MANT Register GSW_PCE_TCM_CIR_MANT - Three-color Marker Constant Information Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_CIR_MANT 0x3854
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_CIR_MANT 0x18453854u

/*! Register Reset Value */
#define GSW_PCE_TCM_CIR_MANT_RST 0x00000000u

/*! Field MANT - Rate Counter Mantissa */
#define GSW_PCE_TCM_CIR_MANT_MANT_POS 0
/*! Field MANT - Rate Counter Mantissa */
#define GSW_PCE_TCM_CIR_MANT_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup GSW_PCE_TCM_CIR_EXP Register GSW_PCE_TCM_CIR_EXP - Three-color Marker Constant Information Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_CIR_EXP 0x3858
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_CIR_EXP 0x18453858u

/*! Register Reset Value */
#define GSW_PCE_TCM_CIR_EXP_RST 0x00000000u

/*! Field EXP - Rate Counter Exponent */
#define GSW_PCE_TCM_CIR_EXP_EXP_POS 0
/*! Field EXP - Rate Counter Exponent */
#define GSW_PCE_TCM_CIR_EXP_EXP_MASK 0xFu
/*! Constant S0 - S0 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S0 0x0
/*! Constant S1 - S1 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S1 0x1
/*! Constant S2 - S2 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S2 0x2
/*! Constant S3 - S3 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S3 0x3
/*! Constant S4 - S4 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S4 0x4
/*! Constant S5 - S5 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S5 0x5
/*! Constant S6 - S6 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S6 0x6
/*! Constant S7 - S7 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S7 0x7
/*! Constant S8 - S8 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S8 0x8
/*! Constant S9 - S9 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S9 0x9
/*! Constant S10 - S10 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S10 0xA
/*! Constant S11 - S11 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S11 0xB
/*! Constant S12 - S12 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S12 0xC
/*! Constant S13 - S13 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S13 0xD
/*! Constant S14 - S14 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S14 0xE
/*! Constant S15 - S15 */
#define CONST_GSW_PCE_TCM_CIR_EXP_EXP_S15 0xF

/*! @} */

/*! \defgroup GSW_PCE_TCM_PIR_MANT Register GSW_PCE_TCM_PIR_MANT - Three-color Marker Peak Information Rate Mantissa Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_PIR_MANT 0x385C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_PIR_MANT 0x1845385Cu

/*! Register Reset Value */
#define GSW_PCE_TCM_PIR_MANT_RST 0x00000000u

/*! Field MANT - Rate Counter Mantissa */
#define GSW_PCE_TCM_PIR_MANT_MANT_POS 0
/*! Field MANT - Rate Counter Mantissa */
#define GSW_PCE_TCM_PIR_MANT_MANT_MASK 0x3FFu

/*! @} */

/*! \defgroup GSW_PCE_TCM_PIR_EXP Register GSW_PCE_TCM_PIR_EXP - Three-color Marker Peak Information Rate Exponent Register */
/*! @{ */

/*! Register Offset (relative) */
#define GSW_PCE_TCM_PIR_EXP 0x3860
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_GSW_PCE_TCM_PIR_EXP 0x18453860u

/*! Register Reset Value */
#define GSW_PCE_TCM_PIR_EXP_RST 0x00000000u

/*! Field EXP - Rate Counter Exponent */
#define GSW_PCE_TCM_PIR_EXP_EXP_POS 0
/*! Field EXP - Rate Counter Exponent */
#define GSW_PCE_TCM_PIR_EXP_EXP_MASK 0xFu
/*! Constant S0 - S0 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S0 0x0
/*! Constant S1 - S1 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S1 0x1
/*! Constant S2 - S2 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S2 0x2
/*! Constant S3 - S3 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S3 0x3
/*! Constant S4 - S4 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S4 0x4
/*! Constant S5 - S5 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S5 0x5
/*! Constant S6 - S6 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S6 0x6
/*! Constant S7 - S7 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S7 0x7
/*! Constant S8 - S8 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S8 0x8
/*! Constant S9 - S9 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S9 0x9
/*! Constant S10 - S10 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S10 0xA
/*! Constant S11 - S11 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S11 0xB
/*! Constant S12 - S12 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S12 0xC
/*! Constant S13 - S13 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S13 0xD
/*! Constant S14 - S14 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S14 0xE
/*! Constant S15 - S15 */
#define CONST_GSW_PCE_TCM_PIR_EXP_EXP_S15 0xF

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_0 Register ETHSW_CTP_STARTID_0 - Ethernet Switch CTP Assignment Start Register Port 0 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_0 0x3A00
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_0 0x18453A00u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_0_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_0_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_0_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_0_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_0_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_0_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_0_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_0_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_0 Register ETHSW_CTP_ENDID_0 - Ethernet Switch CTP Assignment End Register Port 0 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_0 0x3A04
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_0 0x18453A04u

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_0_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_0_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_0_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_1 Register ETHSW_CTP_STARTID_1 - Ethernet Switch CTP Assignment Start Register Port 1 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_1 0x3A08
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_1 0x18453A08u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_1_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_1_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_1_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_1_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_1_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_1_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_1_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_1_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_1 Register ETHSW_CTP_ENDID_1 - Ethernet Switch CTP Assignment End Register Port 1 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_1 0x3A0C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_1 0x18453A0Cu

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_1_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_1_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_1_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_2 Register ETHSW_CTP_STARTID_2 - Ethernet Switch CTP Assignment Start Register Port 2 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_2 0x3A10
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_2 0x18453A10u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_2_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_2_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_2_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_2_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_2_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_2_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_2_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_2_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_2 Register ETHSW_CTP_ENDID_2 - Ethernet Switch CTP Assignment End Register Port 2 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_2 0x3A14
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_2 0x18453A14u

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_2_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_2_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_2_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_3 Register ETHSW_CTP_STARTID_3 - Ethernet Switch CTP Assignment Start Register Port 3 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_3 0x3A18
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_3 0x18453A18u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_3_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_3_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_3_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_3_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_3_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_3_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_3_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_3_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_3 Register ETHSW_CTP_ENDID_3 - Ethernet Switch CTP Assignment End Register Port 3 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_3 0x3A1C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_3 0x18453A1Cu

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_3_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_3_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_3_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_4 Register ETHSW_CTP_STARTID_4 - Ethernet Switch CTP Assignment Start Register Port 4 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_4 0x3A20
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_4 0x18453A20u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_4_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_4_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_4_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_4_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_4_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_4_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_4_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_4_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_4 Register ETHSW_CTP_ENDID_4 - Ethernet Switch CTP Assignment End Register Port 4 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_4 0x3A24
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_4 0x18453A24u

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_4_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_4_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_4_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_5 Register ETHSW_CTP_STARTID_5 - Ethernet SwitchCTP Assignment Start Register Port 5 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_5 0x3A28
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_5 0x18453A28u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_5_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_5_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_5_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_5_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_5_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_5_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_5_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_5_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_5 Register ETHSW_CTP_ENDID_5 - Ethernet Switch CTP Assignment End Register Port 5 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_5 0x3A2C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_5 0x18453A2Cu

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_5_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_5_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_5_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_6 Register ETHSW_CTP_STARTID_6 - Ethernet Switch CTP Assignment Start Register Port 6 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_6 0x3A30
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_6 0x18453A30u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_6_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_6_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_6_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_6_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_6_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_6_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_6_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_6_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_6 Register ETHSW_CTP_ENDID_6 - Ethernet Switch CTP Assignment End Register Port 6 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_6 0x3A34
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_6 0x18453A34u

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_6_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_6_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_6_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_7 Register ETHSW_CTP_STARTID_7 - Ethernet Switch CTP Assignment Start Register Port 7 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_7 0x3A38
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_7 0x18453A38u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_7_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_7_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_7_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_7_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_7_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_7_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_7_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_7_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_7 Register ETHSW_CTP_ENDID_7 - Ethernet Switch CTP Assignment End Register Port 7 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_7 0x3A3C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_7 0x18453A3Cu

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_7_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_7_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_7_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_8 Register ETHSW_CTP_STARTID_8 - Ethernet Switch CTP Assignment Start Register Port 8 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_8 0x3A40
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_8 0x18453A40u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_8_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_8_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_8_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_8_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_8_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_8_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_8_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_8_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_8 Register ETHSW_CTP_ENDID_8 - Ethernet Switch CTP Assignment End Register Port 8 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_8 0x3A44
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_8 0x18453A44u

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_8_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_8_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_8_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_9 Register ETHSW_CTP_STARTID_9 - Ethernet Switch CTP Assignment Start Register Port 9 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_9 0x3A48
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_9 0x18453A48u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_9_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_9_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_9_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_9_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_9_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_9_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_9_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_9_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_9 Register ETHSW_CTP_ENDID_9 - Ethernet Switch CTP Assignment End Register Port 9 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_9 0x3A4C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_9 0x18453A4Cu

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_9_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_9_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_9_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_10 Register ETHSW_CTP_STARTID_10 - Ethernet Switch CTP Assignment Start Register Port 10 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_10 0x3A50
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_10 0x18453A50u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_10_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_10_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_10_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_10_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_10_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_10_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_10_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_10_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_10 Register ETHSW_CTP_ENDID_10 - Ethernet Switch CTP Assignment End Register Port 10 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_10 0x3A54
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_10 0x18453A54u

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_10_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_10_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_10_ENDID_MASK 0x1FFu

/*! @} */

/*! \defgroup ETHSW_CTP_STARTID_11 Register ETHSW_CTP_STARTID_11 - Ethernet Switch CTP Assignment Start Register Port 11 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_STARTID_11 0x3A58
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_STARTID_11 0x18453A58u

/*! Register Reset Value */
#define ETHSW_CTP_STARTID_11_RST 0x00008000u

/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_11_STARTID_POS 0
/*! Field STARTID - CTP Start Port ID */
#define ETHSW_CTP_STARTID_11_STARTID_MASK 0x1FFu

/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_11_MD_POS 14
/*! Field MD - Logical Port Mode */
#define ETHSW_CTP_STARTID_11_MD_MASK 0xC000u
/*! Constant WLAN8 - WLAN8 */
#define CONST_ETHSW_CTP_STARTID_11_MD_WLAN8 0x0
/*! Constant WLAN9 - WLAN9 */
#define CONST_ETHSW_CTP_STARTID_11_MD_WLAN9 0x1
/*! Constant OTHER - Other */
#define CONST_ETHSW_CTP_STARTID_11_MD_OTHER 0x2

/*! @} */

/*! \defgroup ETHSW_CTP_ENDID_11 Register ETHSW_CTP_ENDID_11 - Ethernet Switch CTP Assignment End Register Port 11 */
/*! @{ */

/*! Register Offset (relative) */
#define ETHSW_CTP_ENDID_11 0x3A5C
/*! Register Offset (absolute) for 1st Instance ETHSW_PDI */
#define ETHSW_PDI_ETHSW_CTP_ENDID_11 0x18453A5Cu

/*! Register Reset Value */
#define ETHSW_CTP_ENDID_11_RST 0x00000000u

/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_11_ENDID_POS 0
/*! Field ENDID - CTP End Port ID */
#define ETHSW_CTP_ENDID_11_ENDID_MASK 0x1FFu

/*! @} */

/*! @} */

#endif
