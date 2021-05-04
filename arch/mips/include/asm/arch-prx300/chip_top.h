/* Copyright (c) 2017, Intel Corporation.
 * 
 * IAP chip top header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _CHIP_TOP_H
#define _CHIP_TOP_H

/*! \defgroup CHIP_TOP Register File CHIP_TOP - Chip Top-level Registers Description */
/*! @{ */

/*! Base Address of CHIP_TOP */
#define CHIP_TOP_MODULE_BASE 0x16180000u

/*! \defgroup RST_BOOT_INFO Register RST_BOOT_INFO - System boot strap information Register. */
/*! @{ */

/*! Register Offset (relative) */
#define RST_BOOT_INFO 0x0
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RST_BOOT_INFO 0x16180000u

/*! Register Reset Value */
#define RST_BOOT_INFO_RST 0x00000000u

/*! Field BOOT - Boot Select bit 0 ~ 3 */
#define RST_BOOT_INFO_BOOT_POS 0
/*! Field BOOT - Boot Select bit 0 ~ 3 */
#define RST_BOOT_INFO_BOOT_MASK 0xFu
/*! Constant ROM_RES0 - Reserved */
#define CONST_RST_BOOT_INFO_BOOT_ROM_RES0 0x0
/*! Constant ROM_SYSTEST - ROM -> System Test */
#define CONST_RST_BOOT_INFO_BOOT_ROM_SYSTEST 0x1
/*! Constant ROM_UART0_XMODEM - ROM --> UART0 XMODEM */
#define CONST_RST_BOOT_INFO_BOOT_ROM_UART0_XMODEM 0x2
/*! Constant ROM_SPI0_NAND_ECC - ROM --> SPI0 NAND */
#define CONST_RST_BOOT_INFO_BOOT_ROM_SPI0_NAND_ECC 0x3
/*! Constant ROM_UART0 - ROM --> Legacy UART0 W/O EEPROM */
#define CONST_RST_BOOT_INFO_BOOT_ROM_UART0 0x4
/*! Constant ROM_SPI0 - ROM --> SPI NOR */
#define CONST_RST_BOOT_INFO_BOOT_ROM_SPI0 0x5
/*! Constant ROM_RES6 - Reserved */
#define CONST_RST_BOOT_INFO_BOOT_ROM_RES6 0x6
/*! Constant ROM_QSPI_SNOR - ROM --> QSPI Single Bit NOR */
#define CONST_RST_BOOT_INFO_BOOT_ROM_QSPI_SNOR 0x8
/*! Constant ROM_QSPI_QNOR - ROM --> QSPI Quad Bit NOR */
#define CONST_RST_BOOT_INFO_BOOT_ROM_QSPI_QNOR 0xB
/*! Constant ROM_QSPI_QNAND - ROM --> QSPI Quad Bit NAND */
#define CONST_RST_BOOT_INFO_BOOT_ROM_QSPI_QNAND 0xC
/*! Constant ROM_QSPI_SNAND - ROM --> QSPI Single Bit NAND */
#define CONST_RST_BOOT_INFO_BOOT_ROM_QSPI_SNAND 0xD
/*! Constant ROM_PCIE_DUAL - ROM -> PCIe EP */
#define CONST_RST_BOOT_INFO_BOOT_ROM_PCIE_DUAL 0xF

/*! Field ENDIAN - Endianess of the M4KEc CPU Subsystem */
#define RST_BOOT_INFO_ENDIAN_POS 8
/*! Field ENDIAN - Endianess of the M4KEc CPU Subsystem */
#define RST_BOOT_INFO_ENDIAN_MASK 0x100u
/*! Constant LITTLE_ENDIAN - Little Endian */
#define CONST_RST_BOOT_INFO_ENDIAN_LITTLE_ENDIAN 0x0
/*! Constant BIG_ENDIAN - Big Endian */
#define CONST_RST_BOOT_INFO_ENDIAN_BIG_ENDIAN 0x1

/*! Field TEST_MD - Test mode */
#define RST_BOOT_INFO_TEST_MD_POS 16
/*! Field TEST_MD - Test mode */
#define RST_BOOT_INFO_TEST_MD_MASK 0x10000u
/*! Constant EJTAG - EJTAG */
#define CONST_RST_BOOT_INFO_TEST_MD_EJTAG 0x0
/*! Constant JTAG - JTAG */
#define CONST_RST_BOOT_INFO_TEST_MD_JTAG 0x1

/*! @} */

/*! \defgroup PAD_POWER_SUPPLY_SEL Register PAD_POWER_SUPPLY_SEL - Digital PAD Power Supply Selection Register */
/*! @{ */

/*! Register Offset (relative) */
#define PAD_POWER_SUPPLY_SEL 0x4
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PAD_POWER_SUPPLY_SEL 0x16180004u

/*! Register Reset Value */
#define PAD_POWER_SUPPLY_SEL_RST 0x00000000u

/*! Field SEL_1V8_RIGHT1 - Power Supply Selection for GPIO 0 to 5. */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT1_POS 0
/*! Field SEL_1V8_RIGHT1 - Power Supply Selection for GPIO 0 to 5. */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT1_MASK 0x1u
/*! Constant VDD3V3 - 3.3V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT1_VDD3V3 0x0
/*! Constant VDD1V8 - 1.8V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT1_VDD1V8 0x1

/*! Field SEL_1V8_RIGHT2 - Power Supply Selection for GPIO 6 to 9, 12-19, 32-39 */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT2_POS 1
/*! Field SEL_1V8_RIGHT2 - Power Supply Selection for GPIO 6 to 9, 12-19, 32-39 */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT2_MASK 0x2u
/*! Constant VDD3V3 - 3.3V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT2_VDD3V3 0x0
/*! Constant VDD1V8 - 1.8V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT2_VDD1V8 0x1

/*! Field SEL_1V8_TOP1 - Power Supply Selection for GPIO 20 to 27 and OPT_TXEN. */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP1_POS 2
/*! Field SEL_1V8_TOP1 - Power Supply Selection for GPIO 20 to 27 and OPT_TXEN. */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP1_MASK 0x4u
/*! Constant VDD3V3 - 3.3V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP1_VDD3V3 0x0
/*! Constant VDD1V8 - 1.8V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP1_VDD1V8 0x1

/*! Field SEL_1V8_TOP2 - Power Supply Selection for GPIO 10 to 11, 28 to 31 */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP2_POS 3
/*! Field SEL_1V8_TOP2 - Power Supply Selection for GPIO 10 to 11, 28 to 31 */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP2_MASK 0x8u
/*! Constant VDD3V3 - 3.3V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP2_VDD3V3 0x0
/*! Constant VDD1V8 - 1.8V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_TOP2_VDD1V8 0x1

/*! Field SEL_1V8_LEFT - Power Supply Selection for JTAG, UART0, POR, HRST */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_LEFT_POS 4
/*! Field SEL_1V8_LEFT - Power Supply Selection for JTAG, UART0, POR, HRST */
#define PAD_POWER_SUPPLY_SEL_SEL_1V8_LEFT_MASK 0x10u
/*! Constant VDD3V3 - 3.3V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_LEFT_VDD3V3 0x0
/*! Constant VDD1V8 - 1.8V power supply */
#define CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_LEFT_VDD1V8 0x1

/*! @} */

/*! \defgroup GP_STRAP Register GP_STRAP - GPIO Strapping Register */
/*! @{ */

/*! Register Offset (relative) */
#define GP_STRAP 0x1C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_GP_STRAP 0x1618001Cu

/*! Register Reset Value */
#define GP_STRAP_RST 0x00000000u

/*! Field GPIO_SV - GPIO Strapping Value */
#define GP_STRAP_GPIO_SV_POS 0
/*! Field GPIO_SV - GPIO Strapping Value */
#define GP_STRAP_GPIO_SV_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup PPM Register PPM - Protected Platform Mode Register */
/*! @{ */

/*! Register Offset (relative) */
#define PPM 0x28
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PPM 0x16180028u

/*! Register Reset Value */
#define PPM_RST 0x00000000u

/*! Field MPE - MPE enable */
#define PPM_MPE_POS 1
/*! Field MPE - MPE enable */
#define PPM_MPE_MASK 0x2u
/*! Constant NENB - not enabled */
#define CONST_PPM_MPE_NENB 0x0
/*! Constant ENB - MPE function enabled */
#define CONST_PPM_MPE_ENB 0x1

/*! Field PPM - PPM Mode Secure EJTAG Mode Indication */
#define PPM_PPM_POS 2
/*! Field PPM - PPM Mode Secure EJTAG Mode Indication */
#define PPM_PPM_MASK 0x4u
/*! Constant OPEN - Lantiq Secure EJTAG Mode */
#define CONST_PPM_PPM_OPEN 0x0
/*! Constant SEC - secure EJTAG mode via 123 */
#define CONST_PPM_PPM_SEC 0x1

/*! Field PROD_FEAT - Hardware pre-set product features */
#define PPM_PROD_FEAT_POS 3
/*! Field PROD_FEAT - Hardware pre-set product features */
#define PPM_PROD_FEAT_MASK 0x1FFFFFF8u

/*! Field BOOT_CTRL - SECURE BOOT Mode Control */
#define PPM_BOOT_CTRL_POS 30
/*! Field BOOT_CTRL - SECURE BOOT Mode Control */
#define PPM_BOOT_CTRL_MASK 0x40000000u
/*! Constant OPEN - Open Mode */
#define CONST_PPM_BOOT_CTRL_OPEN 0x0
/*! Constant CLOSE - secure boot mode is enabled */
#define CONST_PPM_BOOT_CTRL_CLOSE 0x1

/*! @} */

/*! \defgroup ENDIAN Register ENDIAN - Endian Register for Modules */
/*! @{ */

/*! Register Offset (relative) */
#define ENDIAN 0x4C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ENDIAN 0x1618004Cu

/*! Register Reset Value */
#define ENDIAN_RST 0x00000009u

/*! Field APTV_CORE_END - Set Endian Mode for Cores of interAptiv */
#define ENDIAN_APTV_CORE_END_POS 0
/*! Field APTV_CORE_END - Set Endian Mode for Cores of interAptiv */
#define ENDIAN_APTV_CORE_END_MASK 0x1u
/*! Constant LITTLE - little */
#define CONST_ENDIAN_APTV_CORE_END_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_ENDIAN_APTV_CORE_END_BIG 0x1

/*! Field E123_MB - Set Endian Mode for EIP123 AXI Slave Port */
#define ENDIAN_E123_MB_POS 3
/*! Field E123_MB - Set Endian Mode for EIP123 AXI Slave Port */
#define ENDIAN_E123_MB_MASK 0x8u
/*! Constant LITTLE - little */
#define CONST_ENDIAN_E123_MB_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_ENDIAN_E123_MB_BIG 0x1

/*! Field PCIE0_TA - Set Byte Swapper Mode for PCIe0 AXI TA Port */
#define ENDIAN_PCIE0_TA_POS 4
/*! Field PCIE0_TA - Set Byte Swapper Mode for PCIe0 AXI TA Port */
#define ENDIAN_PCIE0_TA_MASK 0x30u
/*! Constant NOSWAP - No SWAP is done */
#define CONST_ENDIAN_PCIE0_TA_NOSWAP 0x0
/*! Constant MODE1 - Byte SWAP at 32-bit byte boundary */
#define CONST_ENDIAN_PCIE0_TA_MODE1 0x1
/*! Constant MODE2 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE0_TA_MODE2 0x2
/*! Constant MODE3 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE0_TA_MODE3 0x3

/*! Field PCIE0_IA - Set Byte Swapper Mode for PCIe0 AXI IA Port */
#define ENDIAN_PCIE0_IA_POS 6
/*! Field PCIE0_IA - Set Byte Swapper Mode for PCIe0 AXI IA Port */
#define ENDIAN_PCIE0_IA_MASK 0xC0u
/*! Constant NOSWAP - No SWAP is done */
#define CONST_ENDIAN_PCIE0_IA_NOSWAP 0x0
/*! Constant MODE1 - Byte SWAP at 32-bit byte boundary */
#define CONST_ENDIAN_PCIE0_IA_MODE1 0x1
/*! Constant MODE2 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE0_IA_MODE2 0x2
/*! Constant MODE3 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE0_IA_MODE3 0x3

/*! Field PCIE1_TA - Set Byte Swapper Mode for PCIe1 AXI TA Port */
#define ENDIAN_PCIE1_TA_POS 8
/*! Field PCIE1_TA - Set Byte Swapper Mode for PCIe1 AXI TA Port */
#define ENDIAN_PCIE1_TA_MASK 0x300u
/*! Constant NOSWAP - No SWAP is done */
#define CONST_ENDIAN_PCIE1_TA_NOSWAP 0x0
/*! Constant MODE1 - Byte SWAP at 32-bit byte boundary */
#define CONST_ENDIAN_PCIE1_TA_MODE1 0x1
/*! Constant MODE2 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE1_TA_MODE2 0x2
/*! Constant MODE3 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE1_TA_MODE3 0x3

/*! Field PCIE1_IA - Set Byte Swapper Mode for PCIe1 AXI IA Port */
#define ENDIAN_PCIE1_IA_POS 10
/*! Field PCIE1_IA - Set Byte Swapper Mode for PCIe1 AXI IA Port */
#define ENDIAN_PCIE1_IA_MASK 0xC00u
/*! Constant NOSWAP - No SWAP is done */
#define CONST_ENDIAN_PCIE1_IA_NOSWAP 0x0
/*! Constant MODE1 - Byte SWAP at 32-bit byte boundary */
#define CONST_ENDIAN_PCIE1_IA_MODE1 0x1
/*! Constant MODE2 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE1_IA_MODE2 0x2
/*! Constant MODE3 - Byte SWAP at 64-bit byte boundary */
#define CONST_ENDIAN_PCIE1_IA_MODE3 0x3

/*! Field PCIE0_DBI - Set Byte Swapper Mode for PCIe0 DBI */
#define ENDIAN_PCIE0_DBI_POS 12
/*! Field PCIE0_DBI - Set Byte Swapper Mode for PCIe0 DBI */
#define ENDIAN_PCIE0_DBI_MASK 0x1000u
/*! Constant NOSWAP - No SWAP is done */
#define CONST_ENDIAN_PCIE0_DBI_NOSWAP 0x0
/*! Constant MODE1 - Byte SWAP at 32-bit byte boundary */
#define CONST_ENDIAN_PCIE0_DBI_MODE1 0x1

/*! Field PCIE1_DBI - Set Byte Swapper Mode for PCIe1 DBI */
#define ENDIAN_PCIE1_DBI_POS 13
/*! Field PCIE1_DBI - Set Byte Swapper Mode for PCIe1 DBI */
#define ENDIAN_PCIE1_DBI_MASK 0x2000u
/*! Constant NOSWAP - No SWAP is done */
#define CONST_ENDIAN_PCIE1_DBI_NOSWAP 0x0
/*! Constant MODE1 - Byte SWAP at 32-bit byte boundary */
#define CONST_ENDIAN_PCIE1_DBI_MODE1 0x1

/*! Field AHB_RD_4K - AHB master port Read swapper for 4KEc, set by 4KEc endian strapping pin */
#define ENDIAN_AHB_RD_4K_POS 14
/*! Field AHB_RD_4K - AHB master port Read swapper for 4KEc, set by 4KEc endian strapping pin */
#define ENDIAN_AHB_RD_4K_MASK 0x4000u
/*! Constant V0 - no swap */
#define CONST_ENDIAN_AHB_RD_4K_V0 0x0
/*! Constant V1 - swap */
#define CONST_ENDIAN_AHB_RD_4K_V1 0x1

/*! Field AHB_WR_4K - AHB master port write swapper for 4KEc, set by 4KEc endian strapping pin */
#define ENDIAN_AHB_WR_4K_POS 15
/*! Field AHB_WR_4K - AHB master port write swapper for 4KEc, set by 4KEc endian strapping pin */
#define ENDIAN_AHB_WR_4K_MASK 0x8000u
/*! Constant V0 - no swap */
#define CONST_ENDIAN_AHB_WR_4K_V0 0x0
/*! Constant V1 - swap */
#define CONST_ENDIAN_AHB_WR_4K_V1 0x1

/*! @} */

/*! \defgroup NGI_ENDIAN_IA Register NGI_ENDIAN_IA - Endian Register for NGI Agents */
/*! @{ */

/*! Register Offset (relative) */
#define NGI_ENDIAN_IA 0x5C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_NGI_ENDIAN_IA 0x1618005Cu

/*! Register Reset Value */
#define NGI_ENDIAN_IA_RST 0x000FF7F7u

/*! Field IA_APTV - Set Endian Mode for interAptiv Cluster OCP Port */
#define NGI_ENDIAN_IA_IA_APTV_POS 0
/*! Field IA_APTV - Set Endian Mode for interAptiv Cluster OCP Port */
#define NGI_ENDIAN_IA_IA_APTV_MASK 0x1u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_APTV_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_APTV_BIG 0x1

/*! Field IA_PONIP - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PONIP_POS 1
/*! Field IA_PONIP - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PONIP_MASK 0x2u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_PONIP_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_PONIP_BIG 0x1

/*! Field IA_E123WR - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_E123WR_POS 2
/*! Field IA_E123WR - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_E123WR_MASK 0x4u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_E123WR_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_E123WR_BIG 0x1

/*! Field IA_DMA4 - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA4_POS 4
/*! Field IA_DMA4 - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA4_MASK 0x10u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA4_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA4_BIG 0x1

/*! Field IA_DMA2TXRX - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA2TXRX_POS 5
/*! Field IA_DMA2TXRX - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA2TXRX_MASK 0x20u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA2TXRX_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA2TXRX_BIG 0x1

/*! Field IA_DMA0 - Set Endian Mode for IA DMA0 */
#define NGI_ENDIAN_IA_IA_DMA0_POS 6
/*! Field IA_DMA0 - Set Endian Mode for IA DMA0 */
#define NGI_ENDIAN_IA_IA_DMA0_MASK 0x40u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA0_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA0_BIG 0x1

/*! Field IA_DMA1TXRX - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA1TXRX_POS 7
/*! Field IA_DMA1TXRX - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA1TXRX_MASK 0x80u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA1TXRX_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA1TXRX_BIG 0x1

/*! Field IA_DMA3TXRX - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA3TXRX_POS 8
/*! Field IA_DMA3TXRX - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA3TXRX_MASK 0x100u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA3TXRX_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA3TXRX_BIG 0x1

/*! Field IA_GPHY - Set Endian Mode for IA */
#define NGI_ENDIAN_IA_IA_GPHY_POS 9
/*! Field IA_GPHY - Set Endian Mode for IA */
#define NGI_ENDIAN_IA_IA_GPHY_MASK 0x200u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_GPHY_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_GPHY_BIG 0x1

/*! Field IA_ACA - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_ACA_POS 10
/*! Field IA_ACA - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_ACA_MASK 0x400u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_ACA_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_ACA_BIG 0x1

/*! Field IA_PCI1ERW - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PCI1ERW_POS 12
/*! Field IA_PCI1ERW - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PCI1ERW_MASK 0x1000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_PCI1ERW_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_PCI1ERW_BIG 0x1

/*! Field IA_PCE0ERW - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PCE0ERW_POS 13
/*! Field IA_PCE0ERW - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PCE0ERW_MASK 0x2000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_PCE0ERW_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_PCE0ERW_BIG 0x1

/*! Field IA_MPE - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_MPE_POS 14
/*! Field IA_MPE - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_MPE_MASK 0x4000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_MPE_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_MPE_BIG 0x1

/*! Field IA_MO2 - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_MO2_POS 15
/*! Field IA_MO2 - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_MO2_MASK 0x8000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_MO2_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_MO2_BIG 0x1

/*! Field IA_DMA1DES - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA1DES_POS 16
/*! Field IA_DMA1DES - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA1DES_MASK 0x10000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA1DES_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA1DES_BIG 0x1

/*! Field IA_DMA2DES - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA2DES_POS 17
/*! Field IA_DMA2DES - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA2DES_MASK 0x20000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA2DES_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA2DES_BIG 0x1

/*! Field IA_DMA3DES - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA3DES_POS 18
/*! Field IA_DMA3DES - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_DMA3DES_MASK 0x40000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_DMA3DES_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_DMA3DES_BIG 0x1

/*! Field IA_PPV4 - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PPV4_POS 19
/*! Field IA_PPV4 - Set Endian Mode for IA. */
#define NGI_ENDIAN_IA_IA_PPV4_MASK 0x80000u
/*! Constant LITTLE - little */
#define CONST_NGI_ENDIAN_IA_IA_PPV4_LITTLE 0x0
/*! Constant BIG - big */
#define CONST_NGI_ENDIAN_IA_IA_PPV4_BIG 0x1

/*! @} */

/*! \defgroup RXI_DW0 Register RXI_DW0 - Receive Ingress Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXI_DW0 0x60
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXI_DW0 0x16180060u

/*! Register Reset Value */
#define RXI_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define RXI_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define RXI_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define RXI_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define RXI_DW0_BYTEOFF_MASK 0x1800000u

/*! Field EOP - End of Packet */
#define RXI_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define RXI_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define RXI_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define RXI_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define RXI_DW0_C_POS 30
/*! Field C - Complete */
#define RXI_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define RXI_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define RXI_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup RXI_DW1 Register RXI_DW1 - Receive Ingress Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXI_DW1 0x64
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXI_DW1 0x16180064u

/*! Register Reset Value */
#define RXI_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define RXI_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define RXI_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup RXI_SH_DW0 Register RXI_SH_DW0 - Receive Ingress Shadow Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXI_SH_DW0 0x68
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXI_SH_DW0 0x16180068u

/*! Register Reset Value */
#define RXI_SH_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define RXI_SH_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define RXI_SH_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define RXI_SH_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define RXI_SH_DW0_BYTEOFF_MASK 0x1800000u

/*! Field EOP - End of Packet */
#define RXI_SH_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define RXI_SH_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define RXI_SH_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define RXI_SH_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define RXI_SH_DW0_C_POS 30
/*! Field C - Complete */
#define RXI_SH_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define RXI_SH_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define RXI_SH_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup RXI_SH_DW1 Register RXI_SH_DW1 - Receive Ingress Shadow Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXI_SH_DW1 0x6C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXI_SH_DW1 0x1618006Cu

/*! Register Reset Value */
#define RXI_SH_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define RXI_SH_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define RXI_SH_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup TXI_DW0 Register TXI_DW0 - Transmit Ingress Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXI_DW0 0x70
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXI_DW0 0x16180070u

/*! Register Reset Value */
#define TXI_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define TXI_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define TXI_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define TXI_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define TXI_DW0_BYTEOFF_MASK 0x1800000u

/*! Field EOP - End of Packet */
#define TXI_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define TXI_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define TXI_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define TXI_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define TXI_DW0_C_POS 30
/*! Field C - Complete */
#define TXI_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define TXI_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define TXI_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup TXI_DW1 Register TXI_DW1 - Transmit Ingress Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXI_DW1 0x74
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXI_DW1 0x16180074u

/*! Register Reset Value */
#define TXI_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define TXI_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define TXI_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup TXI_SH_DW0 Register TXI_SH_DW0 - Transmit Ingress Shadow Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXI_SH_DW0 0x78
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXI_SH_DW0 0x16180078u

/*! Register Reset Value */
#define TXI_SH_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define TXI_SH_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define TXI_SH_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define TXI_SH_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define TXI_SH_DW0_BYTEOFF_MASK 0xF800000u

/*! Field EOP - End of Packet */
#define TXI_SH_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define TXI_SH_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define TXI_SH_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define TXI_SH_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define TXI_SH_DW0_C_POS 30
/*! Field C - Complete */
#define TXI_SH_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define TXI_SH_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define TXI_SH_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup TXI_SH_DW1 Register TXI_SH_DW1 - Transmit Ingress Shadow Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXI_SH_DW1 0x7C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXI_SH_DW1 0x1618007Cu

/*! Register Reset Value */
#define TXI_SH_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define TXI_SH_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define TXI_SH_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup RXE_DW0 Register RXE_DW0 - Receive Egress Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXE_DW0 0x80
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXE_DW0 0x16180080u

/*! Register Reset Value */
#define RXE_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define RXE_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define RXE_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define RXE_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define RXE_DW0_BYTEOFF_MASK 0x1800000u

/*! Field EOP - End of Packet */
#define RXE_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define RXE_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define RXE_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define RXE_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define RXE_DW0_C_POS 30
/*! Field C - Complete */
#define RXE_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define RXE_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define RXE_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup RXE_DW1 Register RXE_DW1 - Receive Egress Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXE_DW1 0x84
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXE_DW1 0x16180084u

/*! Register Reset Value */
#define RXE_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define RXE_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define RXE_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup RXE_SH_DW0 Register RXE_SH_DW0 - Receive Egress Shadow Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXE_SH_DW0 0x88
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXE_SH_DW0 0x16180088u

/*! Register Reset Value */
#define RXE_SH_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define RXE_SH_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define RXE_SH_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define RXE_SH_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define RXE_SH_DW0_BYTEOFF_MASK 0x1800000u

/*! Field EOP - End of Packet */
#define RXE_SH_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define RXE_SH_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define RXE_SH_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define RXE_SH_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define RXE_SH_DW0_C_POS 30
/*! Field C - Complete */
#define RXE_SH_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define RXE_SH_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define RXE_SH_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup RXE_SH_DW1 Register RXE_SH_DW1 - Receive Egress Shadow Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define RXE_SH_DW1 0x8C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_RXE_SH_DW1 0x1618008Cu

/*! Register Reset Value */
#define RXE_SH_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define RXE_SH_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define RXE_SH_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup TXE_DW0 Register TXE_DW0 - Transmit Egress Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXE_DW0 0x90
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXE_DW0 0x16180090u

/*! Register Reset Value */
#define TXE_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define TXE_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define TXE_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define TXE_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define TXE_DW0_BYTEOFF_MASK 0xF800000u

/*! Field EOP - End of Packet */
#define TXE_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define TXE_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define TXE_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define TXE_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define TXE_DW0_C_POS 30
/*! Field C - Complete */
#define TXE_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define TXE_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define TXE_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup TXE_DW1 Register TXE_DW1 - Transmit Egress Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXE_DW1 0x94
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXE_DW1 0x16180094u

/*! Register Reset Value */
#define TXE_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define TXE_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define TXE_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup TXE_SH_DW0 Register TXE_SH_DW0 - Transmit Egress Shadow Descriptor DW0 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXE_SH_DW0 0x98
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXE_SH_DW0 0x16180098u

/*! Register Reset Value */
#define TXE_SH_DW0_RST 0x00000000u

/*! Field DATALEN - Data Length */
#define TXE_SH_DW0_DATALEN_POS 0
/*! Field DATALEN - Data Length */
#define TXE_SH_DW0_DATALEN_MASK 0xFFFFu

/*! Field BYTEOFF - Byte Offset */
#define TXE_SH_DW0_BYTEOFF_POS 23
/*! Field BYTEOFF - Byte Offset */
#define TXE_SH_DW0_BYTEOFF_MASK 0xF800000u

/*! Field EOP - End of Packet */
#define TXE_SH_DW0_EOP_POS 28
/*! Field EOP - End of Packet */
#define TXE_SH_DW0_EOP_MASK 0x10000000u

/*! Field SOP - Start of Packet */
#define TXE_SH_DW0_SOP_POS 29
/*! Field SOP - Start of Packet */
#define TXE_SH_DW0_SOP_MASK 0x20000000u

/*! Field C - Complete */
#define TXE_SH_DW0_C_POS 30
/*! Field C - Complete */
#define TXE_SH_DW0_C_MASK 0x40000000u

/*! Field OWN - Ownership */
#define TXE_SH_DW0_OWN_POS 31
/*! Field OWN - Ownership */
#define TXE_SH_DW0_OWN_MASK 0x80000000u

/*! @} */

/*! \defgroup TXE_SH_DW1 Register TXE_SH_DW1 - Transmit Egress Shadow Descriptor DW1 Register */
/*! @{ */

/*! Register Offset (relative) */
#define TXE_SH_DW1 0x9C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_TXE_SH_DW1 0x1618009Cu

/*! Register Reset Value */
#define TXE_SH_DW1_RST 0x00000000u

/*! Field DATAPTR - Data Pointer */
#define TXE_SH_DW1_DATAPTR_POS 0
/*! Field DATAPTR - Data Pointer */
#define TXE_SH_DW1_DATAPTR_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup PCM_EG_CH_SEL Register PCM_EG_CH_SEL - PCM Egress Channel Select */
/*! @{ */

/*! Register Offset (relative) */
#define PCM_EG_CH_SEL 0xA0
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PCM_EG_CH_SEL 0x161800A0u

/*! Register Reset Value */
#define PCM_EG_CH_SEL_RST 0x00000000u

/*! Field CH_SEL - PCM Egress Channel Select */
#define PCM_EG_CH_SEL_CH_SEL_POS 0
/*! Field CH_SEL - PCM Egress Channel Select */
#define PCM_EG_CH_SEL_CH_SEL_MASK 0x3u
/*! Constant CH4 - select first 4 ch */
#define CONST_PCM_EG_CH_SEL_CH_SEL_CH4 0x0
/*! Constant CH8 - select first 8 ch */
#define CONST_PCM_EG_CH_SEL_CH_SEL_CH8 0x1
/*! Constant CH16 - select first 16 ch */
#define CONST_PCM_EG_CH_SEL_CH_SEL_CH16 0x2

/*! @} */

/*! \defgroup PCM_IG_CH_SEL Register PCM_IG_CH_SEL - PCM Ingress Channel Select */
/*! @{ */

/*! Register Offset (relative) */
#define PCM_IG_CH_SEL 0xA4
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PCM_IG_CH_SEL 0x161800A4u

/*! Register Reset Value */
#define PCM_IG_CH_SEL_RST 0x00000000u

/*! Field CH_SEL - PCM Ingress Channel Select */
#define PCM_IG_CH_SEL_CH_SEL_POS 0
/*! Field CH_SEL - PCM Ingress Channel Select */
#define PCM_IG_CH_SEL_CH_SEL_MASK 0x3u
/*! Constant CH4 - select first 4 ch */
#define CONST_PCM_IG_CH_SEL_CH_SEL_CH4 0x0
/*! Constant CH8 - select first 8 ch */
#define CONST_PCM_IG_CH_SEL_CH_SEL_CH8 0x1
/*! Constant CH16 - select first 16 ch */
#define CONST_PCM_IG_CH_SEL_CH_SEL_CH16 0x2

/*! @} */

/*! \defgroup FCC_IRNEN Register FCC_IRNEN - FCC Interrupt Node Enable Register */
/*! @{ */

/*! Register Offset (relative) */
#define FCC_IRNEN 0xF4
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_FCC_IRNEN 0x161800F4u

/*! Register Reset Value */
#define FCC_IRNEN_RST 0x00000000u

/*! Field PCM_E - PCM Egress Interrupt Request Enable */
#define FCC_IRNEN_PCM_E_POS 1
/*! Field PCM_E - PCM Egress Interrupt Request Enable */
#define FCC_IRNEN_PCM_E_MASK 0x2u
/*! Constant DISABLED - Disabled */
#define CONST_FCC_IRNEN_PCM_E_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_FCC_IRNEN_PCM_E_ENABLED 0x1

/*! Field PCM_I - PCM Ingress Interrupt Request Enable */
#define FCC_IRNEN_PCM_I_POS 2
/*! Field PCM_I - PCM Ingress Interrupt Request Enable */
#define FCC_IRNEN_PCM_I_MASK 0x4u
/*! Constant DISABLED - Disabled */
#define CONST_FCC_IRNEN_PCM_I_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_FCC_IRNEN_PCM_I_ENABLED 0x1

/*! Field E_EOP - PCM Egress End of Packet Interrupt Request Enable */
#define FCC_IRNEN_E_EOP_POS 3
/*! Field E_EOP - PCM Egress End of Packet Interrupt Request Enable */
#define FCC_IRNEN_E_EOP_MASK 0x8u
/*! Constant DISABLED - Disabled */
#define CONST_FCC_IRNEN_E_EOP_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_FCC_IRNEN_E_EOP_ENABLED 0x1

/*! Field I_EOP - PCM Ingress End of Packet Interrupt Request Enable */
#define FCC_IRNEN_I_EOP_POS 4
/*! Field I_EOP - PCM Ingress End of Packet Interrupt Request Enable */
#define FCC_IRNEN_I_EOP_MASK 0x10u
/*! Constant DISABLED - Disabled */
#define CONST_FCC_IRNEN_I_EOP_DISABLED 0x0
/*! Constant ENABLED - Enabled */
#define CONST_FCC_IRNEN_I_EOP_ENABLED 0x1

/*! @} */

/*! \defgroup FCC_IRNCR Register FCC_IRNCR - FCC Interrupt Node Control Register */
/*! @{ */

/*! Register Offset (relative) */
#define FCC_IRNCR 0xF8
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_FCC_IRNCR 0x161800F8u

/*! Register Reset Value */
#define FCC_IRNCR_RST 0x00000000u

/*! Field PCM_E - PCM Egress Interrupt Clear */
#define FCC_IRNCR_PCM_E_POS 1
/*! Field PCM_E - PCM Egress Interrupt Clear */
#define FCC_IRNCR_PCM_E_MASK 0x2u
/*! Constant NO_EFFECT - no effect */
#define CONST_FCC_IRNCR_PCM_E_NO_EFFECT 0x0
/*! Constant CLEAR - Clear */
#define CONST_FCC_IRNCR_PCM_E_CLEAR 0x1

/*! Field PCM_I - PCM Ingress Interrupt Clear */
#define FCC_IRNCR_PCM_I_POS 2
/*! Field PCM_I - PCM Ingress Interrupt Clear */
#define FCC_IRNCR_PCM_I_MASK 0x4u
/*! Constant NO_EFFECT - no effect */
#define CONST_FCC_IRNCR_PCM_I_NO_EFFECT 0x0
/*! Constant CLEAR - Clear */
#define CONST_FCC_IRNCR_PCM_I_CLEAR 0x1

/*! @} */

/*! \defgroup FCC_IRNST Register FCC_IRNST - FCC Interrupt Node Status Register */
/*! @{ */

/*! Register Offset (relative) */
#define FCC_IRNST 0xFC
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_FCC_IRNST 0x161800FCu

/*! Register Reset Value */
#define FCC_IRNST_RST 0x00000000u

/*! Field PCM_E - PCM Egress Interrupt Clear */
#define FCC_IRNST_PCM_E_POS 1
/*! Field PCM_E - PCM Egress Interrupt Clear */
#define FCC_IRNST_PCM_E_MASK 0x2u
/*! Constant NO_INTERRUPT - no interrupt */
#define CONST_FCC_IRNST_PCM_E_NO_INTERRUPT 0x0
/*! Constant PENDING_INTERRUPT - Pending Interrupt */
#define CONST_FCC_IRNST_PCM_E_PENDING_INTERRUPT 0x1

/*! Field PCM_I - PCM Ingress Interrupt Status */
#define FCC_IRNST_PCM_I_POS 2
/*! Field PCM_I - PCM Ingress Interrupt Status */
#define FCC_IRNST_PCM_I_MASK 0x4u
/*! Constant NO_INTERRUPT - no interrupt */
#define CONST_FCC_IRNST_PCM_I_NO_INTERRUPT 0x0
/*! Constant PENDING_INTERRUPT - Pending Interrupt */
#define CONST_FCC_IRNST_PCM_I_PENDING_INTERRUPT 0x1

/*! @} */

/*! \defgroup PVT_SENSOR_0 Register PVT_SENSOR_0 - Temperature voltage process sensor control */
/*! @{ */

/*! Register Offset (relative) */
#define PVT_SENSOR_0 0x100
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PVT_SENSOR_0 0x16180100u

/*! Register Reset Value */
#define PVT_SENSOR_0_RST 0x03000008u

/*! Field SOC - PVT sensor output data conversion start */
#define PVT_SENSOR_0_SOC_POS 0
/*! Field SOC - PVT sensor output data conversion start */
#define PVT_SENSOR_0_SOC_MASK 0x1u
/*! Constant NC - no operation */
#define CONST_PVT_SENSOR_0_SOC_NC 0x0
/*! Constant SOC - starts the data conversion */
#define CONST_PVT_SENSOR_0_SOC_SOC 0x1

/*! Field AUTOT_EN - Automatic temperature measurement enable */
#define PVT_SENSOR_0_AUTOT_EN_POS 1
/*! Field AUTOT_EN - Automatic temperature measurement enable */
#define PVT_SENSOR_0_AUTOT_EN_MASK 0x2u
/*! Constant DIS - Disable auto temperature measurement */
#define CONST_PVT_SENSOR_0_AUTOT_EN_DIS 0x0
/*! Constant EN - Enable auto temperature measurement */
#define CONST_PVT_SENSOR_0_AUTOT_EN_EN 0x1

/*! Field VSAMPLE - Voltage Sampling Mode */
#define PVT_SENSOR_0_VSAMPLE_POS 2
/*! Field VSAMPLE - Voltage Sampling Mode */
#define PVT_SENSOR_0_VSAMPLE_MASK 0x4u
/*! Constant NV - Not Voltage mode */
#define CONST_PVT_SENSOR_0_VSAMPLE_NV 0x0
/*! Constant V - Voltage Sample mode */
#define CONST_PVT_SENSOR_0_VSAMPLE_V 0x1

/*! Field TSOVH_INT_EN - Enable the TS overheat interrupt */
#define PVT_SENSOR_0_TSOVH_INT_EN_POS 3
/*! Field TSOVH_INT_EN - Enable the TS overheat interrupt */
#define PVT_SENSOR_0_TSOVH_INT_EN_MASK 0x8u
/*! Constant DIS */
#define CONST_PVT_SENSOR_0_TSOVH_INT_EN_DIS 0x0
/*! Constant EN */
#define CONST_PVT_SENSOR_0_TSOVH_INT_EN_EN 0x1

/*! Field PSAMPLE_PN - Process PN Sampling Mode */
#define PVT_SENSOR_0_PSAMPLE_PN_POS 4
/*! Field PSAMPLE_PN - Process PN Sampling Mode */
#define PVT_SENSOR_0_PSAMPLE_PN_MASK 0x30u
/*! Constant B - P and N Average */
#define CONST_PVT_SENSOR_0_PSAMPLE_PN_B 0x0
/*! Constant N - N device */
#define CONST_PVT_SENSOR_0_PSAMPLE_PN_N 0x1
/*! Constant P - P device */
#define CONST_PVT_SENSOR_0_PSAMPLE_PN_P 0x2

/*! Field PSAMPLE_CNR - Process Corner Sampling Mode */
#define PVT_SENSOR_0_PSAMPLE_CNR_POS 6
/*! Field PSAMPLE_CNR - Process Corner Sampling Mode */
#define PVT_SENSOR_0_PSAMPLE_CNR_MASK 0xC0u
/*! Constant T - Temperature sensor mode together with VSAMLE is 0 */
#define CONST_PVT_SENSOR_0_PSAMPLE_CNR_T 0x0
/*! Constant LP - LVT device */
#define CONST_PVT_SENSOR_0_PSAMPLE_CNR_LP 0x1
/*! Constant HP - HVT device */
#define CONST_PVT_SENSOR_0_PSAMPLE_CNR_HP 0x2
/*! Constant S - SVT */
#define CONST_PVT_SENSOR_0_PSAMPLE_CNR_S 0x3

/*! Field INT_LVL_ON - Temperature code for Interrupt assertion */
#define PVT_SENSOR_0_INT_LVL_ON_POS 16
/*! Field INT_LVL_ON - Temperature code for Interrupt assertion */
#define PVT_SENSOR_0_INT_LVL_ON_MASK 0x3FF0000u

/*! @} */

/*! \defgroup PVT_SENSOR_DATA_0 Register PVT_SENSOR_DATA_0 - sensor read out */
/*! @{ */

/*! Register Offset (relative) */
#define PVT_SENSOR_DATA_0 0x104
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PVT_SENSOR_DATA_0 0x16180104u

/*! Register Reset Value */
#define PVT_SENSOR_DATA_0_RST 0x02C00000u

/*! Field PVT_CODE - sensor output code */
#define PVT_SENSOR_DATA_0_PVT_CODE_POS 0
/*! Field PVT_CODE - sensor output code */
#define PVT_SENSOR_DATA_0_PVT_CODE_MASK 0x3FFu

/*! Field INT_LVL_OFF - Temperature code for Interrupt De-assertion */
#define PVT_SENSOR_DATA_0_INT_LVL_OFF_POS 16
/*! Field INT_LVL_OFF - Temperature code for Interrupt De-assertion */
#define PVT_SENSOR_DATA_0_INT_LVL_OFF_MASK 0x3FF0000u

/*! Field TS_DV - Converted Data Available */
#define PVT_SENSOR_DATA_0_TS_DV_POS 31
/*! Field TS_DV - Converted Data Available */
#define PVT_SENSOR_DATA_0_TS_DV_MASK 0x80000000u
/*! Constant NV - data conversion is not ready */
#define CONST_PVT_SENSOR_DATA_0_TS_DV_NV 0x0
/*! Constant EOC - Data conversion is done, available for read */
#define CONST_PVT_SENSOR_DATA_0_TS_DV_EOC 0x1

/*! @} */

/*! \defgroup PVT_SENSOR_TBITS_0 Register PVT_SENSOR_TBITS_0 */
/*! @{ */

/*! Register Offset (relative) */
#define PVT_SENSOR_TBITS_0 0x108
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PVT_SENSOR_TBITS_0 0x16180108u

/*! Register Reset Value */
#define PVT_SENSOR_TBITS_0_RST 0x00000000u

/*! Field PVT_TRMBITS - these bits control and configuration of PVT for Trim purpose */
#define PVT_SENSOR_TBITS_0_PVT_TRMBITS_POS 0
/*! Field PVT_TRMBITS - these bits control and configuration of PVT for Trim purpose */
#define PVT_SENSOR_TBITS_0_PVT_TRMBITS_MASK 0x1Fu

/*! @} */

/*! \defgroup PVT_SENSOR_1 Register PVT_SENSOR_1 - Temperature voltage process sensor control */
/*! @{ */

/*! Register Offset (relative) */
#define PVT_SENSOR_1 0x110
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PVT_SENSOR_1 0x16180110u

/*! Register Reset Value */
#define PVT_SENSOR_1_RST 0x03000008u

/*! Field SOC - PVT sensor output data conversion start */
#define PVT_SENSOR_1_SOC_POS 0
/*! Field SOC - PVT sensor output data conversion start */
#define PVT_SENSOR_1_SOC_MASK 0x1u
/*! Constant NC - no operation */
#define CONST_PVT_SENSOR_1_SOC_NC 0x0
/*! Constant SOC - starts the data conversion */
#define CONST_PVT_SENSOR_1_SOC_SOC 0x1

/*! Field AUTOT_EN - Automatic temperature measurement enable */
#define PVT_SENSOR_1_AUTOT_EN_POS 1
/*! Field AUTOT_EN - Automatic temperature measurement enable */
#define PVT_SENSOR_1_AUTOT_EN_MASK 0x2u
/*! Constant DIS - Disable auto temperature measurement */
#define CONST_PVT_SENSOR_1_AUTOT_EN_DIS 0x0
/*! Constant EN - Enable auto temperature measurement */
#define CONST_PVT_SENSOR_1_AUTOT_EN_EN 0x1

/*! Field VSAMPLE - Voltage Sampling Mode */
#define PVT_SENSOR_1_VSAMPLE_POS 2
/*! Field VSAMPLE - Voltage Sampling Mode */
#define PVT_SENSOR_1_VSAMPLE_MASK 0x4u
/*! Constant NV - Not Voltage mode */
#define CONST_PVT_SENSOR_1_VSAMPLE_NV 0x0
/*! Constant V - Voltage Sample mode */
#define CONST_PVT_SENSOR_1_VSAMPLE_V 0x1

/*! Field TSOVH_INT_EN - Enable the TS overheat interrupt */
#define PVT_SENSOR_1_TSOVH_INT_EN_POS 3
/*! Field TSOVH_INT_EN - Enable the TS overheat interrupt */
#define PVT_SENSOR_1_TSOVH_INT_EN_MASK 0x8u
/*! Constant DIS */
#define CONST_PVT_SENSOR_1_TSOVH_INT_EN_DIS 0x0
/*! Constant EN */
#define CONST_PVT_SENSOR_1_TSOVH_INT_EN_EN 0x1

/*! Field PSAMPLE_PN - Process PN Sampling Mode */
#define PVT_SENSOR_1_PSAMPLE_PN_POS 4
/*! Field PSAMPLE_PN - Process PN Sampling Mode */
#define PVT_SENSOR_1_PSAMPLE_PN_MASK 0x30u
/*! Constant B - P and N Average */
#define CONST_PVT_SENSOR_1_PSAMPLE_PN_B 0x0
/*! Constant N - N device */
#define CONST_PVT_SENSOR_1_PSAMPLE_PN_N 0x1
/*! Constant P - P device */
#define CONST_PVT_SENSOR_1_PSAMPLE_PN_P 0x2

/*! Field PSAMPLE_CNR - Process Corner Sampling Mode */
#define PVT_SENSOR_1_PSAMPLE_CNR_POS 6
/*! Field PSAMPLE_CNR - Process Corner Sampling Mode */
#define PVT_SENSOR_1_PSAMPLE_CNR_MASK 0xC0u
/*! Constant T - Temperature sensor mode together with VSAMLE is 0 */
#define CONST_PVT_SENSOR_1_PSAMPLE_CNR_T 0x0
/*! Constant LP - LVT device */
#define CONST_PVT_SENSOR_1_PSAMPLE_CNR_LP 0x1
/*! Constant HP - HVT device */
#define CONST_PVT_SENSOR_1_PSAMPLE_CNR_HP 0x2
/*! Constant S - SVT */
#define CONST_PVT_SENSOR_1_PSAMPLE_CNR_S 0x3

/*! Field INT_LVL_ON - Temperature code for Interrupt assertion */
#define PVT_SENSOR_1_INT_LVL_ON_POS 16
/*! Field INT_LVL_ON - Temperature code for Interrupt assertion */
#define PVT_SENSOR_1_INT_LVL_ON_MASK 0x3FF0000u

/*! @} */

/*! \defgroup PVT_SENSOR_DATA_1 Register PVT_SENSOR_DATA_1 - sensor read out */
/*! @{ */

/*! Register Offset (relative) */
#define PVT_SENSOR_DATA_1 0x114
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PVT_SENSOR_DATA_1 0x16180114u

/*! Register Reset Value */
#define PVT_SENSOR_DATA_1_RST 0x02C00000u

/*! Field PVT_CODE - sensor output code */
#define PVT_SENSOR_DATA_1_PVT_CODE_POS 0
/*! Field PVT_CODE - sensor output code */
#define PVT_SENSOR_DATA_1_PVT_CODE_MASK 0x3FFu

/*! Field INT_LVL_OFF - Temperature code for Interrupt De-assertion */
#define PVT_SENSOR_DATA_1_INT_LVL_OFF_POS 16
/*! Field INT_LVL_OFF - Temperature code for Interrupt De-assertion */
#define PVT_SENSOR_DATA_1_INT_LVL_OFF_MASK 0x3FF0000u

/*! Field TS_DV - Converted Data Available */
#define PVT_SENSOR_DATA_1_TS_DV_POS 31
/*! Field TS_DV - Converted Data Available */
#define PVT_SENSOR_DATA_1_TS_DV_MASK 0x80000000u
/*! Constant NV - data conversion is not ready */
#define CONST_PVT_SENSOR_DATA_1_TS_DV_NV 0x0
/*! Constant EOC - Data conversion is done, available for read */
#define CONST_PVT_SENSOR_DATA_1_TS_DV_EOC 0x1

/*! @} */

/*! \defgroup PVT_SENSOR_TBITS_1 Register PVT_SENSOR_TBITS_1 */
/*! @{ */

/*! Register Offset (relative) */
#define PVT_SENSOR_TBITS_1 0x118
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_PVT_SENSOR_TBITS_1 0x16180118u

/*! Register Reset Value */
#define PVT_SENSOR_TBITS_1_RST 0x00000000u

/*! Field PVT_TRMBITS - these bits control and configuration of PVT for Trim purpose */
#define PVT_SENSOR_TBITS_1_PVT_TRMBITS_POS 0
/*! Field PVT_TRMBITS - these bits control and configuration of PVT for Trim purpose */
#define PVT_SENSOR_TBITS_1_PVT_TRMBITS_MASK 0x1Fu

/*! @} */

/*! \defgroup IFMUX_CFG Register IFMUX_CFG - configure internal and external pin mux for debugging */
/*! @{ */

/*! Register Offset (relative) */
#define IFMUX_CFG 0x120
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_IFMUX_CFG 0x16180120u

/*! Register Reset Value */
#define IFMUX_CFG_RST 0x00C00000u

/*! Field WAN_MUX - WAN Interface Selection */
#define IFMUX_CFG_WAN_MUX_POS 0
/*! Field WAN_MUX - WAN Interface Selection */
#define IFMUX_CFG_WAN_MUX_MASK 0x1u
/*! Constant PON - PON Mode */
#define CONST_IFMUX_CFG_WAN_MUX_PON 0x0
/*! Constant AON - AON Mode */
#define CONST_IFMUX_CFG_WAN_MUX_AON 0x1

/*! Field LAN_MUX - LAN Interface Selection */
#define IFMUX_CFG_LAN_MUX_POS 1
/*! Field LAN_MUX - LAN Interface Selection */
#define IFMUX_CFG_LAN_MUX_MASK 0x2u
/*! Constant GPHY - GPHY Mode */
#define CONST_IFMUX_CFG_LAN_MUX_GPHY 0x0
/*! Constant XPCS1 - Serdes Mode */
#define CONST_IFMUX_CFG_LAN_MUX_XPCS1 0x1

/*! Field CPHY_MODE - ComboPHY Mode */
#define IFMUX_CFG_CPHY_MODE_POS 2
/*! Field CPHY_MODE - ComboPHY Mode */
#define IFMUX_CFG_CPHY_MODE_MASK 0x1Cu
/*! Constant MODE0 - Dual PCIe with single lane */
#define CONST_IFMUX_CFG_CPHY_MODE_MODE0 0x0
/*! Constant MODE1 - Single PCIe with dual lane */
#define CONST_IFMUX_CFG_CPHY_MODE_MODE1 0x1
/*! Constant MODE2 - RXAUI */
#define CONST_IFMUX_CFG_CPHY_MODE_MODE2 0x2
/*! Constant MODE3 - Dual XFI with single lane */
#define CONST_IFMUX_CFG_CPHY_MODE_MODE3 0x3
/*! Constant MODE4 - XFI and PCIe mixed mode */
#define CONST_IFMUX_CFG_CPHY_MODE_MODE4 0x4
/*! Constant MODE5 - PCIe and XFI mixed mode */
#define CONST_IFMUX_CFG_CPHY_MODE_MODE5 0x5

/*! Field REFRES_DIS_P0 - Disable LAN Serdes 0 */
#define IFMUX_CFG_REFRES_DIS_P0_POS 8
/*! Field REFRES_DIS_P0 - Disable LAN Serdes 0 */
#define IFMUX_CFG_REFRES_DIS_P0_MASK 0x100u
/*! Constant ENABLED - Enabled */
#define CONST_IFMUX_CFG_REFRES_DIS_P0_ENABLED 0x0
/*! Constant DISABLED - Disabled */
#define CONST_IFMUX_CFG_REFRES_DIS_P0_DISABLED 0x1

/*! Field REFRES_DIS_P1 - Disable LAN Serdes 1 */
#define IFMUX_CFG_REFRES_DIS_P1_POS 9
/*! Field REFRES_DIS_P1 - Disable LAN Serdes 1 */
#define IFMUX_CFG_REFRES_DIS_P1_MASK 0x200u
/*! Constant ENABLED - Enabled */
#define CONST_IFMUX_CFG_REFRES_DIS_P1_ENABLED 0x0
/*! Constant DISABLED - Disabled */
#define CONST_IFMUX_CFG_REFRES_DIS_P1_DISABLED 0x1

/*! Field UART0_SEL - Select UART0 Pin Mux */
#define IFMUX_CFG_UART0_SEL_POS 12
/*! Field UART0_SEL - Select UART0 Pin Mux */
#define IFMUX_CFG_UART0_SEL_MASK 0x3000u
/*! Constant ASC0_U - ASC0 */
#define CONST_IFMUX_CFG_UART0_SEL_ASC0_U 0x0
/*! Constant TEP_U - TEP UART */
#define CONST_IFMUX_CFG_UART0_SEL_TEP_U 0x1
/*! Constant PON_U0 - UART0 inside PON sub system */
#define CONST_IFMUX_CFG_UART0_SEL_PON_U0 0x2
/*! Constant GPHY - UART inside GPHY */
#define CONST_IFMUX_CFG_UART0_SEL_GPHY 0x3

/*! Field NMI_PLL0A - PLL0A Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL0A_POS 15
/*! Field NMI_PLL0A - PLL0A Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL0A_MASK 0x8000u
/*! Constant DISABLE - Disabled */
#define CONST_IFMUX_CFG_NMI_PLL0A_DISABLE 0x0
/*! Constant ENABLE - Enabled */
#define CONST_IFMUX_CFG_NMI_PLL0A_ENABLE 0x1

/*! Field NMI_PLL0B - PLL0B Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL0B_POS 16
/*! Field NMI_PLL0B - PLL0B Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL0B_MASK 0x10000u
/*! Constant DISABLE - Disabled */
#define CONST_IFMUX_CFG_NMI_PLL0B_DISABLE 0x0
/*! Constant ENABLE - Enabled */
#define CONST_IFMUX_CFG_NMI_PLL0B_ENABLE 0x1

/*! Field NMI_PLL1 - PLL1 Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL1_POS 17
/*! Field NMI_PLL1 - PLL1 Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL1_MASK 0x20000u
/*! Constant DISABLE - Disabled */
#define CONST_IFMUX_CFG_NMI_PLL1_DISABLE 0x0
/*! Constant ENABLE - Enabled */
#define CONST_IFMUX_CFG_NMI_PLL1_ENABLE 0x1

/*! Field NMI_PLL2 - PLL2 Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL2_POS 18
/*! Field NMI_PLL2 - PLL2 Lock to NMI of Boot CPU */
#define IFMUX_CFG_NMI_PLL2_MASK 0x40000u
/*! Constant DISABLE - Disabled */
#define CONST_IFMUX_CFG_NMI_PLL2_DISABLE 0x0
/*! Constant ENABLE - Enabled */
#define CONST_IFMUX_CFG_NMI_PLL2_ENABLE 0x1

/*! Field PCI0_RCLK_DIS - Disable PCIe 0 Ref_CLK */
#define IFMUX_CFG_PCI0_RCLK_DIS_POS 22
/*! Field PCI0_RCLK_DIS - Disable PCIe 0 Ref_CLK */
#define IFMUX_CFG_PCI0_RCLK_DIS_MASK 0x400000u
/*! Constant EN - Enabled */
#define CONST_IFMUX_CFG_PCI0_RCLK_DIS_EN 0x0
/*! Constant DIS - Disabled the ref clk pad */
#define CONST_IFMUX_CFG_PCI0_RCLK_DIS_DIS 0x1

/*! Field PCI1_RCLK_DIS - Disable PCIe 1 Ref_CLK */
#define IFMUX_CFG_PCI1_RCLK_DIS_POS 23
/*! Field PCI1_RCLK_DIS - Disable PCIe 1 Ref_CLK */
#define IFMUX_CFG_PCI1_RCLK_DIS_MASK 0x800000u
/*! Constant EN - Enabled */
#define CONST_IFMUX_CFG_PCI1_RCLK_DIS_EN 0x0
/*! Constant DIS - Disabled the ref clk pad */
#define CONST_IFMUX_CFG_PCI1_RCLK_DIS_DIS 0x1

/*! Field ADDR_MAP_MODE - Address Mapping Mode */
#define IFMUX_CFG_ADDR_MAP_MODE_POS 24
/*! Field ADDR_MAP_MODE - Address Mapping Mode */
#define IFMUX_CFG_ADDR_MAP_MODE_MASK 0x1000000u
/*! Constant RC - RC Mode Mapping */
#define CONST_IFMUX_CFG_ADDR_MAP_MODE_RC 0x0
/*! Constant EP - EP Mode Mapping */
#define CONST_IFMUX_CFG_ADDR_MAP_MODE_EP 0x1

/*! @} */

/*! \defgroup ROM_EJTAG Register ROM_EJTAG - ROM to Enable EJTAG */
/*! @{ */

/*! Register Offset (relative) */
#define ROM_EJTAG 0x124
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ROM_EJTAG 0x16180124u

/*! Register Reset Value */
#define ROM_EJTAG_RST 0x00000001u

/*! Field EJTAG - ROM to enable EJTAG path */
#define ROM_EJTAG_EJTAG_POS 0
/*! Field EJTAG - ROM to enable EJTAG path */
#define ROM_EJTAG_EJTAG_MASK 0x1u
/*! Constant EN - Enabled */
#define CONST_ROM_EJTAG_EJTAG_EN 0x0
/*! Constant DIS - disabled , no EJTAG during BootROM phase */
#define CONST_ROM_EJTAG_EJTAG_DIS 0x1

/*! @} */

/*! \defgroup OEM_C Register OEM_C - OEM to Close Production Test OTP Bit */
/*! @{ */

/*! Register Offset (relative) */
#define OEM_C 0x128
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_OEM_C 0x16180128u

/*! Register Reset Value */
#define OEM_C_RST 0x00000000u

/*! Field TEP_EJ_SO - Bypass TEP EJTAG */
#define OEM_C_TEP_EJ_SO_POS 0
/*! Field TEP_EJ_SO - Bypass TEP EJTAG */
#define OEM_C_TEP_EJ_SO_MASK 0x1u
/*! Constant IN - TEP EJTAG is in Chain */
#define CONST_OEM_C_TEP_EJ_SO_IN 0x0
/*! Constant OUT - TEP EJTAG is out of Chain */
#define CONST_OEM_C_TEP_EJ_SO_OUT 0x1

/*! Field SEJTAG - Secure EJTAG Mode */
#define OEM_C_SEJTAG_POS 1
/*! Field SEJTAG - Secure EJTAG Mode */
#define OEM_C_SEJTAG_MASK 0x2u
/*! Constant OPEN - EJTAG is open */
#define CONST_OEM_C_SEJTAG_OPEN 0x0
/*! Constant SECU - EJTAG is Secure */
#define CONST_OEM_C_SEJTAG_SECU 0x1

/*! Field OTP_PGM_STA - OTP Program Status */
#define OEM_C_OTP_PGM_STA_POS 29
/*! Field OTP_PGM_STA - OTP Program Status */
#define OEM_C_OTP_PGM_STA_MASK 0x60000000u
/*! Constant NOR - No Response */
#define CONST_OEM_C_OTP_PGM_STA_NOR 0x0
/*! Constant PASS */
#define CONST_OEM_C_OTP_PGM_STA_PASS 0x1
/*! Constant REV - reserved. */
#define CONST_OEM_C_OTP_PGM_STA_REV 0x2
/*! Constant FAIL - Programming failed */
#define CONST_OEM_C_OTP_PGM_STA_FAIL 0x3

/*! Field OEM_C - OEM Close Production Test OTP Bit */
#define OEM_C_OEM_C_POS 31
/*! Field OEM_C - OEM Close Production Test OTP Bit */
#define OEM_C_OEM_C_MASK 0x80000000u
/*! Constant OPEN - Allow more production test run */
#define CONST_OEM_C_OEM_C_OPEN 0x0
/*! Constant CLSD - No more production test run */
#define CONST_OEM_C_OEM_C_CLSD 0x1

/*! @} */

/*! \defgroup SPE_DBG_OUTPUT Register SPE_DBG_OUTPUT - Debug Output Ports from Secure Platform Engine */
/*! @{ */

/*! Register Offset (relative) */
#define SPE_DBG_OUTPUT 0x12C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_SPE_DBG_OUTPUT 0x1618012Cu

/*! Register Reset Value */
#define SPE_DBG_OUTPUT_RST 0x00000000u

/*! Field DBG_PORT - debug port output signal from secure platform engine */
#define SPE_DBG_OUTPUT_DBG_PORT_POS 0
/*! Field DBG_PORT - debug port output signal from secure platform engine */
#define SPE_DBG_OUTPUT_DBG_PORT_MASK 0xFFu

/*! @} */

/*! \defgroup ANTI_RLBK_VER_0 Register ANTI_RLBK_VER_0 - Register to store anti-rollback version ID from OTP */
/*! @{ */

/*! Register Offset (relative) */
#define ANTI_RLBK_VER_0 0x130
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ANTI_RLBK_VER_0 0x16180130u

/*! Register Reset Value */
#define ANTI_RLBK_VER_0_RST 0x00000000u

/*! Field MINI_VER - Minimum Rollback Version ID */
#define ANTI_RLBK_VER_0_MINI_VER_POS 0
/*! Field MINI_VER - Minimum Rollback Version ID */
#define ANTI_RLBK_VER_0_MINI_VER_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ANTI_RLBK_VER_1 Register ANTI_RLBK_VER_1 - Register to store anti-rollback version ID from OTP */
/*! @{ */

/*! Register Offset (relative) */
#define ANTI_RLBK_VER_1 0x134
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ANTI_RLBK_VER_1 0x16180134u

/*! Register Reset Value */
#define ANTI_RLBK_VER_1_RST 0x00000000u

/*! Field MINI_VER - Minimum Rollback Version ID */
#define ANTI_RLBK_VER_1_MINI_VER_POS 0
/*! Field MINI_VER - Minimum Rollback Version ID */
#define ANTI_RLBK_VER_1_MINI_VER_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup SCRM_KEY_WR Register SCRM_KEY_WR - Write only register for scramble key */
/*! @{ */

/*! Register Offset (relative) */
#define SCRM_KEY_WR 0x138
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_SCRM_KEY_WR 0x16180138u

/*! Register Reset Value */
#define SCRM_KEY_WR_RST 0x00000000u

/*! Field SCRM_KEY - Write only scramble key */
#define SCRM_KEY_WR_SCRM_KEY_POS 0
/*! Field SCRM_KEY - Write only scramble key */
#define SCRM_KEY_WR_SCRM_KEY_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup XBAR0_BASE Register XBAR0_BASE - Base Address Register for XBAR */
/*! @{ */

/*! Register Offset (relative) */
#define XBAR0_BASE 0x200
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_XBAR0_BASE 0x16180200u

/*! Register Reset Value */
#define XBAR0_BASE_RST 0x14000000u

/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR0_BASE_BASE_POS 16
/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR0_BASE_BASE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup XBAR1_BASE Register XBAR1_BASE - Base Address Register for XBAR */
/*! @{ */

/*! Register Offset (relative) */
#define XBAR1_BASE 0x204
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_XBAR1_BASE 0x16180204u

/*! Register Reset Value */
#define XBAR1_BASE_RST 0x18000000u

/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR1_BASE_BASE_POS 16
/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR1_BASE_BASE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup XBAR2_BASE Register XBAR2_BASE - Base Address Register for XBAR */
/*! @{ */

/*! Register Offset (relative) */
#define XBAR2_BASE 0x208
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_XBAR2_BASE 0x16180208u

/*! Register Reset Value */
#define XBAR2_BASE_RST 0x18800000u

/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR2_BASE_BASE_POS 16
/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR2_BASE_BASE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup XBAR4_BASE Register XBAR4_BASE - Base Address Register for XBAR */
/*! @{ */

/*! Register Offset (relative) */
#define XBAR4_BASE 0x210
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_XBAR4_BASE 0x16180210u

/*! Register Reset Value */
#define XBAR4_BASE_RST 0x16000000u

/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR4_BASE_BASE_POS 16
/*! Field BASE - Upper 16 bits Base Address for XBAR */
#define XBAR4_BASE_BASE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup ECO_SPARE_0 Register ECO_SPARE_0 - ECO Spare Register 0 */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_0 0x240
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_0 0x16180240u

/*! Register Reset Value */
#define ECO_SPARE_0_RST 0x00000000u

/*! Field ECO - Spare register */
#define ECO_SPARE_0_ECO_POS 0
/*! Field ECO - Spare register */
#define ECO_SPARE_0_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ECO_SPARE_1 Register ECO_SPARE_1 - ECO Spare Register 1 */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_1 0x244
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_1 0x16180244u

/*! Register Reset Value */
#define ECO_SPARE_1_RST 0x00000000u

/*! Field ECO - Spare register */
#define ECO_SPARE_1_ECO_POS 0
/*! Field ECO - Spare register */
#define ECO_SPARE_1_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ECO_SPARE_2 Register ECO_SPARE_2 - ECO Spare Register 2 */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_2 0x248
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_2 0x16180248u

/*! Register Reset Value */
#define ECO_SPARE_2_RST 0x00000000u

/*! Field ECO - Spare register */
#define ECO_SPARE_2_ECO_POS 0
/*! Field ECO - Spare register */
#define ECO_SPARE_2_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ECO_SPARE_3 Register ECO_SPARE_3 - spare register for ECO */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_3 0x24C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_3 0x1618024Cu

/*! Register Reset Value */
#define ECO_SPARE_3_RST 0x00000000u

/*! Field ECO - Spare register */
#define ECO_SPARE_3_ECO_POS 0
/*! Field ECO - Spare register */
#define ECO_SPARE_3_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ECO_SPARE_4 Register ECO_SPARE_4 - spare register for ECO */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_4 0x250
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_4 0x16180250u

/*! Register Reset Value */
#define ECO_SPARE_4_RST 0x00000000u

/*! Field ECO - ECO bits */
#define ECO_SPARE_4_ECO_POS 0
/*! Field ECO - ECO bits */
#define ECO_SPARE_4_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ECO_SPARE_5 Register ECO_SPARE_5 - spare register for ECO */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_5 0x254
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_5 0x16180254u

/*! Register Reset Value */
#define ECO_SPARE_5_RST 0x00000000u

/*! Field ECO - ECO bits */
#define ECO_SPARE_5_ECO_POS 0
/*! Field ECO - ECO bits */
#define ECO_SPARE_5_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ECO_SPARE_6 Register ECO_SPARE_6 - spare register for ECO */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_6 0x258
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_6 0x16180258u

/*! Register Reset Value */
#define ECO_SPARE_6_RST 0x00000000u

/*! Field ECO - ECO bits */
#define ECO_SPARE_6_ECO_POS 0
/*! Field ECO - ECO bits */
#define ECO_SPARE_6_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup ECO_SPARE_7 Register ECO_SPARE_7 - spare register for ECO */
/*! @{ */

/*! Register Offset (relative) */
#define ECO_SPARE_7 0x25C
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_ECO_SPARE_7 0x1618025Cu

/*! Register Reset Value */
#define ECO_SPARE_7_RST 0x00000000u

/*! Field ECO - ECO bits */
#define ECO_SPARE_7_ECO_POS 0
/*! Field ECO - ECO bits */
#define ECO_SPARE_7_ECO_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup REG_AFI Register REG_AFI */
/*! @{ */

/*! Register Offset (relative) */
#define REG_AFI 0x400
/*! Register Offset (absolute) for 1st Instance CHIP_TOP */
#define CHIP_TOP_REG_AFI 0x16180400u

/*! Register Reset Value */
#define REG_AFI_RST 0x00000000u

/*! Field AFI - AFI Contents */
#define REG_AFI_AFI_POS 0
/*! Field AFI - AFI Contents */
#define REG_AFI_AFI_MASK 0xFFFFFFFFu

/*! @} */

/*! @} */

#endif
