/* Copyright (c) 2017, Intel Corporation.
 * 
 * QSPI controller header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _QSPI_H
#define _QSPI_H

/*! \defgroup QSPI Register File QSPI - QSPI Registers */
/*! @{ */

/*! Base Address of QSPI */
#define QSPI_MODULE_BASE 0x19300000u

/*! \defgroup CONFIG_REG Register CONFIG_REG - config_reg */
/*! @{ */

/*! Register Offset (relative) */
#define CONFIG_REG 0x0
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_CONFIG_REG 0x19300000u

/*! Register Reset Value */
#define CONFIG_REG_RST 0x80780081u

/*! Field ENB_SPI_FLD - enb_spi_fld */
#define CONFIG_REG_ENB_SPI_FLD_POS 0
/*! Field ENB_SPI_FLD - enb_spi_fld */
#define CONFIG_REG_ENB_SPI_FLD_MASK 0x1u

/*! Field SEL_CLK_POL_FLD - sel_clk_pol_fld */
#define CONFIG_REG_SEL_CLK_POL_FLD_POS 1
/*! Field SEL_CLK_POL_FLD - sel_clk_pol_fld */
#define CONFIG_REG_SEL_CLK_POL_FLD_MASK 0x2u

/*! Field SEL_CLK_PHASE_FLD - sel_clk_phase_fld */
#define CONFIG_REG_SEL_CLK_PHASE_FLD_POS 2
/*! Field SEL_CLK_PHASE_FLD - sel_clk_phase_fld */
#define CONFIG_REG_SEL_CLK_PHASE_FLD_MASK 0x4u

/*! Field PHY_MODE_ENABLE_FLD - phy_mode_enable_fld */
#define CONFIG_REG_PHY_MODE_ENABLE_FLD_POS 3
/*! Field PHY_MODE_ENABLE_FLD - phy_mode_enable_fld */
#define CONFIG_REG_PHY_MODE_ENABLE_FLD_MASK 0x8u

/*! Field HOLD_PIN_FLD - hold_pin_fld */
#define CONFIG_REG_HOLD_PIN_FLD_POS 4
/*! Field HOLD_PIN_FLD - hold_pin_fld */
#define CONFIG_REG_HOLD_PIN_FLD_MASK 0x10u

/*! Field RESET_PIN_FLD - reset_pin_fld */
#define CONFIG_REG_RESET_PIN_FLD_POS 5
/*! Field RESET_PIN_FLD - reset_pin_fld */
#define CONFIG_REG_RESET_PIN_FLD_MASK 0x20u

/*! Field RESET_CFG_FLD - reset_cfg_fld */
#define CONFIG_REG_RESET_CFG_FLD_POS 6
/*! Field RESET_CFG_FLD - reset_cfg_fld */
#define CONFIG_REG_RESET_CFG_FLD_MASK 0x40u

/*! Field ENB_DIR_ACC_CTLR_FLD - enb_dir_acc_ctlr_fld */
#define CONFIG_REG_ENB_DIR_ACC_CTLR_FLD_POS 7
/*! Field ENB_DIR_ACC_CTLR_FLD - enb_dir_acc_ctlr_fld */
#define CONFIG_REG_ENB_DIR_ACC_CTLR_FLD_MASK 0x80u

/*! Field ENB_LEGACY_IP_MODE_FLD - enb_legacy_ip_mode_fld */
#define CONFIG_REG_ENB_LEGACY_IP_MODE_FLD_POS 8
/*! Field ENB_LEGACY_IP_MODE_FLD - enb_legacy_ip_mode_fld */
#define CONFIG_REG_ENB_LEGACY_IP_MODE_FLD_MASK 0x100u

/*! Field PERIPH_SEL_DEC_FLD - periph_sel_dec_fld */
#define CONFIG_REG_PERIPH_SEL_DEC_FLD_POS 9
/*! Field PERIPH_SEL_DEC_FLD - periph_sel_dec_fld */
#define CONFIG_REG_PERIPH_SEL_DEC_FLD_MASK 0x200u

/*! Field PERIPH_CS_LINES_FLD - periph_cs_lines_fld */
#define CONFIG_REG_PERIPH_CS_LINES_FLD_POS 10
/*! Field PERIPH_CS_LINES_FLD - periph_cs_lines_fld */
#define CONFIG_REG_PERIPH_CS_LINES_FLD_MASK 0x3C00u

/*! Field WR_PROT_FLASH_FLD - wr_prot_flash_fld */
#define CONFIG_REG_WR_PROT_FLASH_FLD_POS 14
/*! Field WR_PROT_FLASH_FLD - wr_prot_flash_fld */
#define CONFIG_REG_WR_PROT_FLASH_FLD_MASK 0x4000u

/*! Field ENB_DMA_IF_FLD - enb_dma_if_fld */
#define CONFIG_REG_ENB_DMA_IF_FLD_POS 15
/*! Field ENB_DMA_IF_FLD - enb_dma_if_fld */
#define CONFIG_REG_ENB_DMA_IF_FLD_MASK 0x8000u

/*! Field ENB_AHB_ADDR_REMAP_FLD - enb_ahb_addr_remap_fld */
#define CONFIG_REG_ENB_AHB_ADDR_REMAP_FLD_POS 16
/*! Field ENB_AHB_ADDR_REMAP_FLD - enb_ahb_addr_remap_fld */
#define CONFIG_REG_ENB_AHB_ADDR_REMAP_FLD_MASK 0x10000u

/*! Field ENTER_XIP_MODE_FLD - enter_xip_mode_fld */
#define CONFIG_REG_ENTER_XIP_MODE_FLD_POS 17
/*! Field ENTER_XIP_MODE_FLD - enter_xip_mode_fld */
#define CONFIG_REG_ENTER_XIP_MODE_FLD_MASK 0x20000u

/*! Field ENTER_XIP_MODE_IMM_FLD - enter_xip_mode_imm_fld */
#define CONFIG_REG_ENTER_XIP_MODE_IMM_FLD_POS 18
/*! Field ENTER_XIP_MODE_IMM_FLD - enter_xip_mode_imm_fld */
#define CONFIG_REG_ENTER_XIP_MODE_IMM_FLD_MASK 0x40000u

/*! Field MSTR_BAUD_DIV_FLD - mstr_baud_div_fld */
#define CONFIG_REG_MSTR_BAUD_DIV_FLD_POS 19
/*! Field MSTR_BAUD_DIV_FLD - mstr_baud_div_fld */
#define CONFIG_REG_MSTR_BAUD_DIV_FLD_MASK 0x780000u

/*! Field ENABLE_AHB_DECODER_FLD - enable_ahb_decoder_fld */
#define CONFIG_REG_ENABLE_AHB_DECODER_FLD_POS 23
/*! Field ENABLE_AHB_DECODER_FLD - enable_ahb_decoder_fld */
#define CONFIG_REG_ENABLE_AHB_DECODER_FLD_MASK 0x800000u

/*! Field ENABLE_DTR_PROTOCOL_FLD - enable_dtr_protocol_fld */
#define CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD_POS 24
/*! Field ENABLE_DTR_PROTOCOL_FLD - enable_dtr_protocol_fld */
#define CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD_MASK 0x1000000u

/*! Field PIPELINE_PHY_FLD - pipeline_phy_fld */
#define CONFIG_REG_PIPELINE_PHY_FLD_POS 25
/*! Field PIPELINE_PHY_FLD - pipeline_phy_fld */
#define CONFIG_REG_PIPELINE_PHY_FLD_MASK 0x2000000u

/*! Field CONFIG_RESV2_FLD - config_resv2_fld */
#define CONFIG_REG_CONFIG_RESV2_FLD_POS 26
/*! Field CONFIG_RESV2_FLD - config_resv2_fld */
#define CONFIG_REG_CONFIG_RESV2_FLD_MASK 0x7C000000u

/*! Field IDLE_FLD - idle_fld */
#define CONFIG_REG_IDLE_FLD_POS 31
/*! Field IDLE_FLD - idle_fld */
#define CONFIG_REG_IDLE_FLD_MASK 0x80000000u

/*! @} */

/*! \defgroup DEV_INSTR_RD_CONFIG_REG Register DEV_INSTR_RD_CONFIG_REG - dev_instr_rd_config_reg */
/*! @{ */

/*! Register Offset (relative) */
#define DEV_INSTR_RD_CONFIG_REG 0x4
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_DEV_INSTR_RD_CONFIG_REG 0x19300004u

/*! Register Reset Value */
#define DEV_INSTR_RD_CONFIG_REG_RST 0x00000003u

/*! Field RD_OPCODE_NON_XIP_FLD - rd_opcode_non_xip_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_POS 0
/*! Field RD_OPCODE_NON_XIP_FLD - rd_opcode_non_xip_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_MASK 0xFFu

/*! Field INSTR_TYPE_FLD - instr_type_fld */
#define DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD_POS 8
/*! Field INSTR_TYPE_FLD - instr_type_fld */
#define DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD_MASK 0x300u

/*! Field DDR_EN_FLD - ddr_en_fld */
#define DEV_INSTR_RD_CONFIG_REG_DDR_EN_FLD_POS 10
/*! Field DDR_EN_FLD - ddr_en_fld */
#define DEV_INSTR_RD_CONFIG_REG_DDR_EN_FLD_MASK 0x400u

/*! Field RD_INSTR_RESV1_FLD - rd_instr_resv1_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV1_FLD_POS 11
/*! Field RD_INSTR_RESV1_FLD - rd_instr_resv1_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV1_FLD_MASK 0x800u

/*! Field ADDR_XFER_TYPE_STD_MODE_FLD - addr_xfer_type_std_mode_fld */
#define DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_POS 12
/*! Field ADDR_XFER_TYPE_STD_MODE_FLD - addr_xfer_type_std_mode_fld */
#define DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK 0x3000u

/*! Field RD_INSTR_RESV2_FLD - rd_instr_resv2_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV2_FLD_POS 14
/*! Field RD_INSTR_RESV2_FLD - rd_instr_resv2_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV2_FLD_MASK 0xC000u

/*! Field DATA_XFER_TYPE_EXT_MODE_FLD - data_xfer_type_ext_mode_fld */
#define DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_POS 16
/*! Field DATA_XFER_TYPE_EXT_MODE_FLD - data_xfer_type_ext_mode_fld */
#define DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK 0x30000u

/*! Field RD_INSTR_RESV3_FLD - rd_instr_resv3_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV3_FLD_POS 18
/*! Field RD_INSTR_RESV3_FLD - rd_instr_resv3_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV3_FLD_MASK 0xC0000u

/*! Field MODE_BIT_ENABLE_FLD - mode_bit_enable_fld */
#define DEV_INSTR_RD_CONFIG_REG_MODE_BIT_ENABLE_FLD_POS 20
/*! Field MODE_BIT_ENABLE_FLD - mode_bit_enable_fld */
#define DEV_INSTR_RD_CONFIG_REG_MODE_BIT_ENABLE_FLD_MASK 0x100000u

/*! Field RD_INSTR_RESV4_FLD - rd_instr_resv4_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV4_FLD_POS 21
/*! Field RD_INSTR_RESV4_FLD - rd_instr_resv4_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV4_FLD_MASK 0xE00000u

/*! Field DUMMY_RD_CLK_CYCLES_FLD - dummy_rd_clk_cycles_fld */
#define DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_POS 24
/*! Field DUMMY_RD_CLK_CYCLES_FLD - dummy_rd_clk_cycles_fld */
#define DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_MASK 0x1F000000u

/*! Field RD_INSTR_RESV5_FLD - rd_instr_resv5_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV5_FLD_POS 29
/*! Field RD_INSTR_RESV5_FLD - rd_instr_resv5_fld */
#define DEV_INSTR_RD_CONFIG_REG_RD_INSTR_RESV5_FLD_MASK 0xE0000000u

/*! @} */

/*! \defgroup DEV_INSTR_WR_CONFIG_REG Register DEV_INSTR_WR_CONFIG_REG - dev_instr_wr_config_reg */
/*! @{ */

/*! Register Offset (relative) */
#define DEV_INSTR_WR_CONFIG_REG 0x8
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_DEV_INSTR_WR_CONFIG_REG 0x19300008u

/*! Register Reset Value */
#define DEV_INSTR_WR_CONFIG_REG_RST 0x00000002u

/*! Field WR_OPCODE_FLD - wr_opcode_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_POS 0
/*! Field WR_OPCODE_FLD - wr_opcode_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_MASK 0xFFu

/*! Field WEL_DIS_FLD - wel_dis_fld */
#define DEV_INSTR_WR_CONFIG_REG_WEL_DIS_FLD_POS 8
/*! Field WEL_DIS_FLD - wel_dis_fld */
#define DEV_INSTR_WR_CONFIG_REG_WEL_DIS_FLD_MASK 0x100u

/*! Field WR_INSTR_RESV1_FLD - wr_instr_resv1_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV1_FLD_POS 9
/*! Field WR_INSTR_RESV1_FLD - wr_instr_resv1_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV1_FLD_MASK 0xE00u

/*! Field ADDR_XFER_TYPE_STD_MODE_FLD - addr_xfer_type_std_mode_fld */
#define DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_POS 12
/*! Field ADDR_XFER_TYPE_STD_MODE_FLD - addr_xfer_type_std_mode_fld */
#define DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK 0x3000u

/*! Field WR_INSTR_RESV2_FLD - wr_instr_resv2_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV2_FLD_POS 14
/*! Field WR_INSTR_RESV2_FLD - wr_instr_resv2_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV2_FLD_MASK 0xC000u

/*! Field DATA_XFER_TYPE_EXT_MODE_FLD - data_xfer_type_ext_mode_fld */
#define DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_POS 16
/*! Field DATA_XFER_TYPE_EXT_MODE_FLD - data_xfer_type_ext_mode_fld */
#define DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK 0x30000u

/*! Field WR_INSTR_RESV3_FLD - wr_instr_resv3_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV3_FLD_POS 18
/*! Field WR_INSTR_RESV3_FLD - wr_instr_resv3_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV3_FLD_MASK 0xFC0000u

/*! Field DUMMY_WR_CLK_CYCLES_FLD - dummy_wr_clk_cycles_fld */
#define DEV_INSTR_WR_CONFIG_REG_DUMMY_WR_CLK_CYCLES_FLD_POS 24
/*! Field DUMMY_WR_CLK_CYCLES_FLD - dummy_wr_clk_cycles_fld */
#define DEV_INSTR_WR_CONFIG_REG_DUMMY_WR_CLK_CYCLES_FLD_MASK 0x1F000000u

/*! Field WR_INSTR_RESV4_FLD - wr_instr_resv4_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV4_FLD_POS 29
/*! Field WR_INSTR_RESV4_FLD - wr_instr_resv4_fld */
#define DEV_INSTR_WR_CONFIG_REG_WR_INSTR_RESV4_FLD_MASK 0xE0000000u

/*! @} */

/*! \defgroup DEV_DELAY_REG Register DEV_DELAY_REG - dev_delay_reg */
/*! @{ */

/*! Register Offset (relative) */
#define DEV_DELAY_REG 0xC
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_DEV_DELAY_REG 0x1930000Cu

/*! Register Reset Value */
#define DEV_DELAY_REG_RST 0x00000000u

/*! Field D_INIT_FLD - d_init_fld */
#define DEV_DELAY_REG_D_INIT_FLD_POS 0
/*! Field D_INIT_FLD - d_init_fld */
#define DEV_DELAY_REG_D_INIT_FLD_MASK 0xFFu

/*! Field D_AFTER_FLD - d_after_fld */
#define DEV_DELAY_REG_D_AFTER_FLD_POS 8
/*! Field D_AFTER_FLD - d_after_fld */
#define DEV_DELAY_REG_D_AFTER_FLD_MASK 0xFF00u

/*! Field D_BTWN_FLD - d_btwn_fld */
#define DEV_DELAY_REG_D_BTWN_FLD_POS 16
/*! Field D_BTWN_FLD - d_btwn_fld */
#define DEV_DELAY_REG_D_BTWN_FLD_MASK 0xFF0000u

/*! Field D_NSS_FLD - d_nss_fld */
#define DEV_DELAY_REG_D_NSS_FLD_POS 24
/*! Field D_NSS_FLD - d_nss_fld */
#define DEV_DELAY_REG_D_NSS_FLD_MASK 0xFF000000u

/*! @} */

/*! \defgroup RD_DATA_CAPTURE_REG Register RD_DATA_CAPTURE_REG - rd_data_capture_reg */
/*! @{ */

/*! Register Offset (relative) */
#define RD_DATA_CAPTURE_REG 0x10
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_RD_DATA_CAPTURE_REG 0x19300010u

/*! Register Reset Value */
#define RD_DATA_CAPTURE_REG_RST 0x00000001u

/*! Field BYPASS_FLD - bypass_fld */
#define RD_DATA_CAPTURE_REG_BYPASS_FLD_POS 0
/*! Field BYPASS_FLD - bypass_fld */
#define RD_DATA_CAPTURE_REG_BYPASS_FLD_MASK 0x1u

/*! Field DELAY_FLD - delay_fld */
#define RD_DATA_CAPTURE_REG_DELAY_FLD_POS 1
/*! Field DELAY_FLD - delay_fld */
#define RD_DATA_CAPTURE_REG_DELAY_FLD_MASK 0x1Eu

/*! Field SAMPLE_EDGE_SEL_FLD - sample_edge_sel_fld */
#define RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD_POS 5
/*! Field SAMPLE_EDGE_SEL_FLD - sample_edge_sel_fld */
#define RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD_MASK 0x20u

/*! Field RD_DATA_RESV1_FLD - rd_data_resv1_fld */
#define RD_DATA_CAPTURE_REG_RD_DATA_RESV1_FLD_POS 6
/*! Field RD_DATA_RESV1_FLD - rd_data_resv1_fld */
#define RD_DATA_CAPTURE_REG_RD_DATA_RESV1_FLD_MASK 0xFFC0u

/*! Field DDR_READ_DELAY_FLD - DDR_read_delay_fld */
#define RD_DATA_CAPTURE_REG_DDR_READ_DELAY_FLD_POS 16
/*! Field DDR_READ_DELAY_FLD - DDR_read_delay_fld */
#define RD_DATA_CAPTURE_REG_DDR_READ_DELAY_FLD_MASK 0xF0000u

/*! Field RD_DATA_RESV3_FLD - rd_data_resv3_fld */
#define RD_DATA_CAPTURE_REG_RD_DATA_RESV3_FLD_POS 20
/*! Field RD_DATA_RESV3_FLD - rd_data_resv3_fld */
#define RD_DATA_CAPTURE_REG_RD_DATA_RESV3_FLD_MASK 0xFFF00000u

/*! @} */

/*! \defgroup DEV_SIZE_CONFIG_REG Register DEV_SIZE_CONFIG_REG - dev_size_config_reg */
/*! @{ */

/*! Register Offset (relative) */
#define DEV_SIZE_CONFIG_REG 0x14
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_DEV_SIZE_CONFIG_REG 0x19300014u

/*! Register Reset Value */
#define DEV_SIZE_CONFIG_REG_RST 0x00101002u

/*! Field NUM_ADDR_BYTES_FLD - num_addr_bytes_fld */
#define DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD_POS 0
/*! Field NUM_ADDR_BYTES_FLD - num_addr_bytes_fld */
#define DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD_MASK 0xFu

/*! Field BYTES_PER_DEVICE_PAGE_FLD - bytes_per_device_page_fld */
#define DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD_POS 4
/*! Field BYTES_PER_DEVICE_PAGE_FLD - bytes_per_device_page_fld */
#define DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD_MASK 0xFFF0u

/*! Field BYTES_PER_SUBSECTOR_FLD - bytes_per_subsector_fld */
#define DEV_SIZE_CONFIG_REG_BYTES_PER_SUBSECTOR_FLD_POS 16
/*! Field BYTES_PER_SUBSECTOR_FLD - bytes_per_subsector_fld */
#define DEV_SIZE_CONFIG_REG_BYTES_PER_SUBSECTOR_FLD_MASK 0x1F0000u

/*! Field MEM_SIZE_ON_CS0_FLD - mem_size_on_cs0_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS0_FLD_POS 21
/*! Field MEM_SIZE_ON_CS0_FLD - mem_size_on_cs0_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS0_FLD_MASK 0x600000u

/*! Field MEM_SIZE_ON_CS1_FLD - mem_size_on_cs1_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS1_FLD_POS 23
/*! Field MEM_SIZE_ON_CS1_FLD - mem_size_on_cs1_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS1_FLD_MASK 0x1800000u

/*! Field MEM_SIZE_ON_CS2_FLD - mem_size_on_cs2_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS2_FLD_POS 25
/*! Field MEM_SIZE_ON_CS2_FLD - mem_size_on_cs2_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS2_FLD_MASK 0x6000000u

/*! Field MEM_SIZE_ON_CS3_FLD - mem_size_on_cs3_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS3_FLD_POS 27
/*! Field MEM_SIZE_ON_CS3_FLD - mem_size_on_cs3_fld */
#define DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS3_FLD_MASK 0x18000000u

/*! Field DEV_SIZE_RESV_FLD - dev_size_resv_fld */
#define DEV_SIZE_CONFIG_REG_DEV_SIZE_RESV_FLD_POS 29
/*! Field DEV_SIZE_RESV_FLD - dev_size_resv_fld */
#define DEV_SIZE_CONFIG_REG_DEV_SIZE_RESV_FLD_MASK 0xE0000000u

/*! @} */

/*! \defgroup SRAM_PARTITION_CFG_REG Register SRAM_PARTITION_CFG_REG - sram_partition_cfg_reg */
/*! @{ */

/*! Register Offset (relative) */
#define SRAM_PARTITION_CFG_REG 0x18
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_SRAM_PARTITION_CFG_REG 0x19300018u

/*! Register Reset Value */
#define SRAM_PARTITION_CFG_REG_RST 0x00000080u

/*! Field ADDR_FLD - addr_fld */
#define SRAM_PARTITION_CFG_REG_ADDR_FLD_POS 0
/*! Field ADDR_FLD - addr_fld */
#define SRAM_PARTITION_CFG_REG_ADDR_FLD_MASK 0xFFu

/*! Field SRAM_PARTITION_RESV_FLD - sram_partition_resv_fld */
#define SRAM_PARTITION_CFG_REG_SRAM_PARTITION_RESV_FLD_POS 8
/*! Field SRAM_PARTITION_RESV_FLD - sram_partition_resv_fld */
#define SRAM_PARTITION_CFG_REG_SRAM_PARTITION_RESV_FLD_MASK 0xFFFFFF00u

/*! @} */

/*! \defgroup IND_AHB_ADDR_TRIGGER_REG Register IND_AHB_ADDR_TRIGGER_REG - ind_AHB_addr_trigger_reg */
/*! @{ */

/*! Register Offset (relative) */
#define IND_AHB_ADDR_TRIGGER_REG 0x1C
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_IND_AHB_ADDR_TRIGGER_REG 0x1930001Cu

/*! Register Reset Value */
#define IND_AHB_ADDR_TRIGGER_REG_RST 0x00000000u

/*! Field ADDR_FLD - addr_fld */
#define IND_AHB_ADDR_TRIGGER_REG_ADDR_FLD_POS 0
/*! Field ADDR_FLD - addr_fld */
#define IND_AHB_ADDR_TRIGGER_REG_ADDR_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup DMA_PERIPH_CONFIG_REG Register DMA_PERIPH_CONFIG_REG - dma_periph_config_reg */
/*! @{ */

/*! Register Offset (relative) */
#define DMA_PERIPH_CONFIG_REG 0x20
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_DMA_PERIPH_CONFIG_REG 0x19300020u

/*! Register Reset Value */
#define DMA_PERIPH_CONFIG_REG_RST 0x00000000u

/*! Field NUM_SINGLE_REQ_BYTES_FLD - num_single_req_bytes_fld */
#define DMA_PERIPH_CONFIG_REG_NUM_SINGLE_REQ_BYTES_FLD_POS 0
/*! Field NUM_SINGLE_REQ_BYTES_FLD - num_single_req_bytes_fld */
#define DMA_PERIPH_CONFIG_REG_NUM_SINGLE_REQ_BYTES_FLD_MASK 0xFu

/*! Field DMA_PERIPH_RESV1_FLD - dma_periph_resv1_fld */
#define DMA_PERIPH_CONFIG_REG_DMA_PERIPH_RESV1_FLD_POS 4
/*! Field DMA_PERIPH_RESV1_FLD - dma_periph_resv1_fld */
#define DMA_PERIPH_CONFIG_REG_DMA_PERIPH_RESV1_FLD_MASK 0xF0u

/*! Field NUM_BURST_REQ_BYTES_FLD - num_burst_req_bytes_fld */
#define DMA_PERIPH_CONFIG_REG_NUM_BURST_REQ_BYTES_FLD_POS 8
/*! Field NUM_BURST_REQ_BYTES_FLD - num_burst_req_bytes_fld */
#define DMA_PERIPH_CONFIG_REG_NUM_BURST_REQ_BYTES_FLD_MASK 0xF00u

/*! Field DMA_PERIPH_RESV2_FLD - dma_periph_resv2_fld */
#define DMA_PERIPH_CONFIG_REG_DMA_PERIPH_RESV2_FLD_POS 12
/*! Field DMA_PERIPH_RESV2_FLD - dma_periph_resv2_fld */
#define DMA_PERIPH_CONFIG_REG_DMA_PERIPH_RESV2_FLD_MASK 0xFFFFF000u

/*! @} */

/*! \defgroup REMAP_ADDR_REG Register REMAP_ADDR_REG - remap_addr_reg */
/*! @{ */

/*! Register Offset (relative) */
#define REMAP_ADDR_REG 0x24
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_REMAP_ADDR_REG 0x19300024u

/*! Register Reset Value */
#define REMAP_ADDR_REG_RST 0x00000000u

/*! Field VALUE_FLD - value_fld */
#define REMAP_ADDR_REG_VALUE_FLD_POS 0
/*! Field VALUE_FLD - value_fld */
#define REMAP_ADDR_REG_VALUE_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup MODE_BIT_CONFIG_REG Register MODE_BIT_CONFIG_REG - mode_bit_config_reg */
/*! @{ */

/*! Register Offset (relative) */
#define MODE_BIT_CONFIG_REG 0x28
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_MODE_BIT_CONFIG_REG 0x19300028u

/*! Register Reset Value */
#define MODE_BIT_CONFIG_REG_RST 0x00000000u

/*! Field MODE_FLD - mode_fld */
#define MODE_BIT_CONFIG_REG_MODE_FLD_POS 0
/*! Field MODE_FLD - mode_fld */
#define MODE_BIT_CONFIG_REG_MODE_FLD_MASK 0xFFu

/*! Field MODE_RESV_FLD - mode_resv_fld */
#define MODE_BIT_CONFIG_REG_MODE_RESV_FLD_POS 8
/*! Field MODE_RESV_FLD - mode_resv_fld */
#define MODE_BIT_CONFIG_REG_MODE_RESV_FLD_MASK 0xFFFFFF00u

/*! @} */

/*! \defgroup SRAM_FILL_REG Register SRAM_FILL_REG - sram_fill_reg */
/*! @{ */

/*! Register Offset (relative) */
#define SRAM_FILL_REG 0x2C
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_SRAM_FILL_REG 0x1930002Cu

/*! Register Reset Value */
#define SRAM_FILL_REG_RST 0x00000000u

/*! Field SRAM_FILL_INDAC_READ_FLD - sram_fill_indac_read_fld */
#define SRAM_FILL_REG_SRAM_FILL_INDAC_READ_FLD_POS 0
/*! Field SRAM_FILL_INDAC_READ_FLD - sram_fill_indac_read_fld */
#define SRAM_FILL_REG_SRAM_FILL_INDAC_READ_FLD_MASK 0xFFFFu

/*! Field SRAM_FILL_INDAC_WRITE_FLD - sram_fill_indac_write_fld */
#define SRAM_FILL_REG_SRAM_FILL_INDAC_WRITE_FLD_POS 16
/*! Field SRAM_FILL_INDAC_WRITE_FLD - sram_fill_indac_write_fld */
#define SRAM_FILL_REG_SRAM_FILL_INDAC_WRITE_FLD_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup TX_THRESH_REG Register TX_THRESH_REG - tx_thresh_reg */
/*! @{ */

/*! Register Offset (relative) */
#define TX_THRESH_REG 0x30
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_TX_THRESH_REG 0x19300030u

/*! Register Reset Value */
#define TX_THRESH_REG_RST 0x00000001u

/*! Field LEVEL_FLD - level_fld */
#define TX_THRESH_REG_LEVEL_FLD_POS 0
/*! Field LEVEL_FLD - level_fld */
#define TX_THRESH_REG_LEVEL_FLD_MASK 0x1Fu

/*! Field TX_THRESH_RESV_FLD - tx_thresh_resv_fld */
#define TX_THRESH_REG_TX_THRESH_RESV_FLD_POS 5
/*! Field TX_THRESH_RESV_FLD - tx_thresh_resv_fld */
#define TX_THRESH_REG_TX_THRESH_RESV_FLD_MASK 0xFFFFFFE0u

/*! @} */

/*! \defgroup RX_THRESH_REG Register RX_THRESH_REG - rx_thresh_reg */
/*! @{ */

/*! Register Offset (relative) */
#define RX_THRESH_REG 0x34
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_RX_THRESH_REG 0x19300034u

/*! Register Reset Value */
#define RX_THRESH_REG_RST 0x00000001u

/*! Field LEVEL_FLD - level_fld */
#define RX_THRESH_REG_LEVEL_FLD_POS 0
/*! Field LEVEL_FLD - level_fld */
#define RX_THRESH_REG_LEVEL_FLD_MASK 0x1Fu

/*! Field RX_THRESH_RESV_FLD - rx_thresh_resv_fld */
#define RX_THRESH_REG_RX_THRESH_RESV_FLD_POS 5
/*! Field RX_THRESH_RESV_FLD - rx_thresh_resv_fld */
#define RX_THRESH_REG_RX_THRESH_RESV_FLD_MASK 0xFFFFFFE0u

/*! @} */

/*! \defgroup WRITE_COMPLETION_CTRL_REG Register WRITE_COMPLETION_CTRL_REG - write_completion_ctrl_reg */
/*! @{ */

/*! Register Offset (relative) */
#define WRITE_COMPLETION_CTRL_REG 0x38
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_WRITE_COMPLETION_CTRL_REG 0x19300038u

/*! Register Reset Value */
#define WRITE_COMPLETION_CTRL_REG_RST 0x00010005u

/*! Field OPCODE_FLD - opcode_fld */
#define WRITE_COMPLETION_CTRL_REG_OPCODE_FLD_POS 0
/*! Field OPCODE_FLD - opcode_fld */
#define WRITE_COMPLETION_CTRL_REG_OPCODE_FLD_MASK 0xFFu

/*! Field POLLING_BIT_INDEX_FLD - polling_bit_index_fld */
#define WRITE_COMPLETION_CTRL_REG_POLLING_BIT_INDEX_FLD_POS 8
/*! Field POLLING_BIT_INDEX_FLD - polling_bit_index_fld */
#define WRITE_COMPLETION_CTRL_REG_POLLING_BIT_INDEX_FLD_MASK 0x700u

/*! Field WR_COMP_CTRL_RESV1_FLD - wr_comp_ctrl_resv1_fld */
#define WRITE_COMPLETION_CTRL_REG_WR_COMP_CTRL_RESV1_FLD_POS 11
/*! Field WR_COMP_CTRL_RESV1_FLD - wr_comp_ctrl_resv1_fld */
#define WRITE_COMPLETION_CTRL_REG_WR_COMP_CTRL_RESV1_FLD_MASK 0x1800u

/*! Field POLLING_POLARITY_FLD - polling_polarity_fld */
#define WRITE_COMPLETION_CTRL_REG_POLLING_POLARITY_FLD_POS 13
/*! Field POLLING_POLARITY_FLD - polling_polarity_fld */
#define WRITE_COMPLETION_CTRL_REG_POLLING_POLARITY_FLD_MASK 0x2000u

/*! Field DISABLE_POLLING_FLD - disable_polling_fld */
#define WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD_POS 14
/*! Field DISABLE_POLLING_FLD - disable_polling_fld */
#define WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD_MASK 0x4000u

/*! Field ENABLE_POLLING_EXP_FLD - enable_polling_exp_fld */
#define WRITE_COMPLETION_CTRL_REG_ENABLE_POLLING_EXP_FLD_POS 15
/*! Field ENABLE_POLLING_EXP_FLD - enable_polling_exp_fld */
#define WRITE_COMPLETION_CTRL_REG_ENABLE_POLLING_EXP_FLD_MASK 0x8000u

/*! Field POLL_COUNT_FLD - poll_count_fld */
#define WRITE_COMPLETION_CTRL_REG_POLL_COUNT_FLD_POS 16
/*! Field POLL_COUNT_FLD - poll_count_fld */
#define WRITE_COMPLETION_CTRL_REG_POLL_COUNT_FLD_MASK 0xFF0000u

/*! Field POLL_REP_DELAY_FLD - poll_rep_delay_fld */
#define WRITE_COMPLETION_CTRL_REG_POLL_REP_DELAY_FLD_POS 24
/*! Field POLL_REP_DELAY_FLD - poll_rep_delay_fld */
#define WRITE_COMPLETION_CTRL_REG_POLL_REP_DELAY_FLD_MASK 0xFF000000u

/*! @} */

/*! \defgroup NO_OF_POLLS_BEF_EXP_REG Register NO_OF_POLLS_BEF_EXP_REG - no_of_polls_bef_exp_reg */
/*! @{ */

/*! Register Offset (relative) */
#define NO_OF_POLLS_BEF_EXP_REG 0x3C
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_NO_OF_POLLS_BEF_EXP_REG 0x1930003Cu

/*! Register Reset Value */
#define NO_OF_POLLS_BEF_EXP_REG_RST 0xFFFFFFFFu

/*! Field NO_OF_POLLS_BEF_EXP_FLD - no_of_polls_bef_exp_fld */
#define NO_OF_POLLS_BEF_EXP_REG_NO_OF_POLLS_BEF_EXP_FLD_POS 0
/*! Field NO_OF_POLLS_BEF_EXP_FLD - no_of_polls_bef_exp_fld */
#define NO_OF_POLLS_BEF_EXP_REG_NO_OF_POLLS_BEF_EXP_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup IRQ_STATUS_REG Register IRQ_STATUS_REG - irq_status_reg */
/*! @{ */

/*! Register Offset (relative) */
#define IRQ_STATUS_REG 0x40
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_IRQ_STATUS_REG 0x19300040u

/*! Register Reset Value */
#define IRQ_STATUS_REG_RST 0x00000000u

/*! Field MODE_M_FAIL_FLD - mode_m_fail_fld */
#define IRQ_STATUS_REG_MODE_M_FAIL_FLD_POS 0
/*! Field MODE_M_FAIL_FLD - mode_m_fail_fld */
#define IRQ_STATUS_REG_MODE_M_FAIL_FLD_MASK 0x1u

/*! Field UNDERFLOW_DET_FLD - underflow_det_fld */
#define IRQ_STATUS_REG_UNDERFLOW_DET_FLD_POS 1
/*! Field UNDERFLOW_DET_FLD - underflow_det_fld */
#define IRQ_STATUS_REG_UNDERFLOW_DET_FLD_MASK 0x2u

/*! Field INDIRECT_OP_DONE_FLD - indirect_op_done_fld */
#define IRQ_STATUS_REG_INDIRECT_OP_DONE_FLD_POS 2
/*! Field INDIRECT_OP_DONE_FLD - indirect_op_done_fld */
#define IRQ_STATUS_REG_INDIRECT_OP_DONE_FLD_MASK 0x4u

/*! Field INDIRECT_READ_REJECT_FLD - indirect_read_reject_fld */
#define IRQ_STATUS_REG_INDIRECT_READ_REJECT_FLD_POS 3
/*! Field INDIRECT_READ_REJECT_FLD - indirect_read_reject_fld */
#define IRQ_STATUS_REG_INDIRECT_READ_REJECT_FLD_MASK 0x8u

/*! Field PROT_WR_ATTEMPT_FLD - prot_wr_attempt_fld */
#define IRQ_STATUS_REG_PROT_WR_ATTEMPT_FLD_POS 4
/*! Field PROT_WR_ATTEMPT_FLD - prot_wr_attempt_fld */
#define IRQ_STATUS_REG_PROT_WR_ATTEMPT_FLD_MASK 0x10u

/*! Field ILLEGAL_ACCESS_DET_FLD - illegal_access_det_fld */
#define IRQ_STATUS_REG_ILLEGAL_ACCESS_DET_FLD_POS 5
/*! Field ILLEGAL_ACCESS_DET_FLD - illegal_access_det_fld */
#define IRQ_STATUS_REG_ILLEGAL_ACCESS_DET_FLD_MASK 0x20u

/*! Field INDIRECT_XFER_LEVEL_BREACH_FLD - indirect_xfer_level_breach_fld */
#define IRQ_STATUS_REG_INDIRECT_XFER_LEVEL_BREACH_FLD_POS 6
/*! Field INDIRECT_XFER_LEVEL_BREACH_FLD - indirect_xfer_level_breach_fld */
#define IRQ_STATUS_REG_INDIRECT_XFER_LEVEL_BREACH_FLD_MASK 0x40u

/*! Field RECV_OVERFLOW_FLD - recv_overflow_fld */
#define IRQ_STATUS_REG_RECV_OVERFLOW_FLD_POS 7
/*! Field RECV_OVERFLOW_FLD - recv_overflow_fld */
#define IRQ_STATUS_REG_RECV_OVERFLOW_FLD_MASK 0x80u

/*! Field TX_FIFO_NOT_FULL_FLD - tx_fifo_not_full_fld */
#define IRQ_STATUS_REG_TX_FIFO_NOT_FULL_FLD_POS 8
/*! Field TX_FIFO_NOT_FULL_FLD - tx_fifo_not_full_fld */
#define IRQ_STATUS_REG_TX_FIFO_NOT_FULL_FLD_MASK 0x100u

/*! Field TX_FIFO_FULL_FLD - tx_fifo_full_fld */
#define IRQ_STATUS_REG_TX_FIFO_FULL_FLD_POS 9
/*! Field TX_FIFO_FULL_FLD - tx_fifo_full_fld */
#define IRQ_STATUS_REG_TX_FIFO_FULL_FLD_MASK 0x200u

/*! Field RX_FIFO_NOT_EMPTY_FLD - rx_fifo_not_empty_fld */
#define IRQ_STATUS_REG_RX_FIFO_NOT_EMPTY_FLD_POS 10
/*! Field RX_FIFO_NOT_EMPTY_FLD - rx_fifo_not_empty_fld */
#define IRQ_STATUS_REG_RX_FIFO_NOT_EMPTY_FLD_MASK 0x400u

/*! Field RX_FIFO_FULL_FLD - rx_fifo_full_fld */
#define IRQ_STATUS_REG_RX_FIFO_FULL_FLD_POS 11
/*! Field RX_FIFO_FULL_FLD - rx_fifo_full_fld */
#define IRQ_STATUS_REG_RX_FIFO_FULL_FLD_MASK 0x800u

/*! Field INDRD_SRAM_FULL_FLD - indrd_sram_full_fld */
#define IRQ_STATUS_REG_INDRD_SRAM_FULL_FLD_POS 12
/*! Field INDRD_SRAM_FULL_FLD - indrd_sram_full_fld */
#define IRQ_STATUS_REG_INDRD_SRAM_FULL_FLD_MASK 0x1000u

/*! Field POLL_EXP_INT_FLD - poll_exp_int_fld */
#define IRQ_STATUS_REG_POLL_EXP_INT_FLD_POS 13
/*! Field POLL_EXP_INT_FLD - poll_exp_int_fld */
#define IRQ_STATUS_REG_POLL_EXP_INT_FLD_MASK 0x2000u

/*! Field STIG_REQ_INT_FLD - stig_req_int_fld */
#define IRQ_STATUS_REG_STIG_REQ_INT_FLD_POS 14
/*! Field STIG_REQ_INT_FLD - stig_req_int_fld */
#define IRQ_STATUS_REG_STIG_REQ_INT_FLD_MASK 0x4000u

/*! Field IRQ_STAT_RESV_FLD - irq_stat_resv_fld */
#define IRQ_STATUS_REG_IRQ_STAT_RESV_FLD_POS 15
/*! Field IRQ_STAT_RESV_FLD - irq_stat_resv_fld */
#define IRQ_STATUS_REG_IRQ_STAT_RESV_FLD_MASK 0xFFFF8000u

/*! @} */

/*! \defgroup IRQ_MASK_REG Register IRQ_MASK_REG - irq_mask_reg */
/*! @{ */

/*! Register Offset (relative) */
#define IRQ_MASK_REG 0x44
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_IRQ_MASK_REG 0x19300044u

/*! Register Reset Value */
#define IRQ_MASK_REG_RST 0x00000000u

/*! Field MODE_M_FAIL_MASK_FLD - mode_m_fail_mask_fld */
#define IRQ_MASK_REG_MODE_M_FAIL_MASK_FLD_POS 0
/*! Field MODE_M_FAIL_MASK_FLD - mode_m_fail_mask_fld */
#define IRQ_MASK_REG_MODE_M_FAIL_MASK_FLD_MASK 0x1u

/*! Field UNDERFLOW_DET_MASK_FLD - underflow_det_mask_fld */
#define IRQ_MASK_REG_UNDERFLOW_DET_MASK_FLD_POS 1
/*! Field UNDERFLOW_DET_MASK_FLD - underflow_det_mask_fld */
#define IRQ_MASK_REG_UNDERFLOW_DET_MASK_FLD_MASK 0x2u

/*! Field INDIRECT_OP_DONE_MASK_FLD - indirect_op_done_mask_fld */
#define IRQ_MASK_REG_INDIRECT_OP_DONE_MASK_FLD_POS 2
/*! Field INDIRECT_OP_DONE_MASK_FLD - indirect_op_done_mask_fld */
#define IRQ_MASK_REG_INDIRECT_OP_DONE_MASK_FLD_MASK 0x4u

/*! Field INDIRECT_READ_REJECT_MASK_FLD - indirect_read_reject_mask_fld */
#define IRQ_MASK_REG_INDIRECT_READ_REJECT_MASK_FLD_POS 3
/*! Field INDIRECT_READ_REJECT_MASK_FLD - indirect_read_reject_mask_fld */
#define IRQ_MASK_REG_INDIRECT_READ_REJECT_MASK_FLD_MASK 0x8u

/*! Field PROT_WR_ATTEMPT_MASK_FLD - prot_wr_attempt_mask_fld */
#define IRQ_MASK_REG_PROT_WR_ATTEMPT_MASK_FLD_POS 4
/*! Field PROT_WR_ATTEMPT_MASK_FLD - prot_wr_attempt_mask_fld */
#define IRQ_MASK_REG_PROT_WR_ATTEMPT_MASK_FLD_MASK 0x10u

/*! Field ILLEGAL_ACCESS_DET_MASK_FLD - illegal_access_det_mask_fld */
#define IRQ_MASK_REG_ILLEGAL_ACCESS_DET_MASK_FLD_POS 5
/*! Field ILLEGAL_ACCESS_DET_MASK_FLD - illegal_access_det_mask_fld */
#define IRQ_MASK_REG_ILLEGAL_ACCESS_DET_MASK_FLD_MASK 0x20u

/*! Field INDIRECT_XFER_LEVEL_BREACH_MASK_FLD - indirect_xfer_level_breach_mask_fld */
#define IRQ_MASK_REG_INDIRECT_XFER_LEVEL_BREACH_MASK_FLD_POS 6
/*! Field INDIRECT_XFER_LEVEL_BREACH_MASK_FLD - indirect_xfer_level_breach_mask_fld */
#define IRQ_MASK_REG_INDIRECT_XFER_LEVEL_BREACH_MASK_FLD_MASK 0x40u

/*! Field RECV_OVERFLOW_MASK_FLD - recv_overflow_mask_fld */
#define IRQ_MASK_REG_RECV_OVERFLOW_MASK_FLD_POS 7
/*! Field RECV_OVERFLOW_MASK_FLD - recv_overflow_mask_fld */
#define IRQ_MASK_REG_RECV_OVERFLOW_MASK_FLD_MASK 0x80u

/*! Field TX_FIFO_NOT_FULL_MASK_FLD - tx_fifo_not_full_mask_fld */
#define IRQ_MASK_REG_TX_FIFO_NOT_FULL_MASK_FLD_POS 8
/*! Field TX_FIFO_NOT_FULL_MASK_FLD - tx_fifo_not_full_mask_fld */
#define IRQ_MASK_REG_TX_FIFO_NOT_FULL_MASK_FLD_MASK 0x100u

/*! Field TX_FIFO_FULL_MASK_FLD - tx_fifo_full_mask_fld */
#define IRQ_MASK_REG_TX_FIFO_FULL_MASK_FLD_POS 9
/*! Field TX_FIFO_FULL_MASK_FLD - tx_fifo_full_mask_fld */
#define IRQ_MASK_REG_TX_FIFO_FULL_MASK_FLD_MASK 0x200u

/*! Field RX_FIFO_NOT_EMPTY_MASK_FLD - rx_fifo_not_empty_mask_fld */
#define IRQ_MASK_REG_RX_FIFO_NOT_EMPTY_MASK_FLD_POS 10
/*! Field RX_FIFO_NOT_EMPTY_MASK_FLD - rx_fifo_not_empty_mask_fld */
#define IRQ_MASK_REG_RX_FIFO_NOT_EMPTY_MASK_FLD_MASK 0x400u

/*! Field RX_FIFO_FULL_MASK_FLD - rx_fifo_full_mask_fld */
#define IRQ_MASK_REG_RX_FIFO_FULL_MASK_FLD_POS 11
/*! Field RX_FIFO_FULL_MASK_FLD - rx_fifo_full_mask_fld */
#define IRQ_MASK_REG_RX_FIFO_FULL_MASK_FLD_MASK 0x800u

/*! Field INDRD_SRAM_FULL_MASK_FLD - indrd_sram_full_mask_fld */
#define IRQ_MASK_REG_INDRD_SRAM_FULL_MASK_FLD_POS 12
/*! Field INDRD_SRAM_FULL_MASK_FLD - indrd_sram_full_mask_fld */
#define IRQ_MASK_REG_INDRD_SRAM_FULL_MASK_FLD_MASK 0x1000u

/*! Field POLL_EXP_INT_MASK_FLD - poll_exp_int_mask_fld */
#define IRQ_MASK_REG_POLL_EXP_INT_MASK_FLD_POS 13
/*! Field POLL_EXP_INT_MASK_FLD - poll_exp_int_mask_fld */
#define IRQ_MASK_REG_POLL_EXP_INT_MASK_FLD_MASK 0x2000u

/*! Field STIG_REQ_MASK_FLD - stig_req_mask_fld */
#define IRQ_MASK_REG_STIG_REQ_MASK_FLD_POS 14
/*! Field STIG_REQ_MASK_FLD - stig_req_mask_fld */
#define IRQ_MASK_REG_STIG_REQ_MASK_FLD_MASK 0x4000u

/*! Field IRQ_MASK_RESV_FLD - irq_mask_resv_fld */
#define IRQ_MASK_REG_IRQ_MASK_RESV_FLD_POS 15
/*! Field IRQ_MASK_RESV_FLD - irq_mask_resv_fld */
#define IRQ_MASK_REG_IRQ_MASK_RESV_FLD_MASK 0xFFFF8000u

/*! @} */

/*! \defgroup LOWER_WR_PROT_REG Register LOWER_WR_PROT_REG - lower_wr_prot_reg */
/*! @{ */

/*! Register Offset (relative) */
#define LOWER_WR_PROT_REG 0x50
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_LOWER_WR_PROT_REG 0x19300050u

/*! Register Reset Value */
#define LOWER_WR_PROT_REG_RST 0x00000000u

/*! Field SUBSECTOR_FLD - subsector_fld */
#define LOWER_WR_PROT_REG_SUBSECTOR_FLD_POS 0
/*! Field SUBSECTOR_FLD - subsector_fld */
#define LOWER_WR_PROT_REG_SUBSECTOR_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup UPPER_WR_PROT_REG Register UPPER_WR_PROT_REG - upper_wr_prot_reg */
/*! @{ */

/*! Register Offset (relative) */
#define UPPER_WR_PROT_REG 0x54
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_UPPER_WR_PROT_REG 0x19300054u

/*! Register Reset Value */
#define UPPER_WR_PROT_REG_RST 0x00000000u

/*! Field SUBSECTOR_FLD - subsector_fld */
#define UPPER_WR_PROT_REG_SUBSECTOR_FLD_POS 0
/*! Field SUBSECTOR_FLD - subsector_fld */
#define UPPER_WR_PROT_REG_SUBSECTOR_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup WR_PROT_CTRL_REG Register WR_PROT_CTRL_REG - wr_prot_ctrl_reg */
/*! @{ */

/*! Register Offset (relative) */
#define WR_PROT_CTRL_REG 0x58
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_WR_PROT_CTRL_REG 0x19300058u

/*! Register Reset Value */
#define WR_PROT_CTRL_REG_RST 0x00000000u

/*! Field INV_FLD - inv_fld */
#define WR_PROT_CTRL_REG_INV_FLD_POS 0
/*! Field INV_FLD - inv_fld */
#define WR_PROT_CTRL_REG_INV_FLD_MASK 0x1u

/*! Field ENB_FLD - enb_fld */
#define WR_PROT_CTRL_REG_ENB_FLD_POS 1
/*! Field ENB_FLD - enb_fld */
#define WR_PROT_CTRL_REG_ENB_FLD_MASK 0x2u

/*! Field WR_PROT_CTRL_RESV_FLD - wr_prot_ctrl_resv_fld */
#define WR_PROT_CTRL_REG_WR_PROT_CTRL_RESV_FLD_POS 2
/*! Field WR_PROT_CTRL_RESV_FLD - wr_prot_ctrl_resv_fld */
#define WR_PROT_CTRL_REG_WR_PROT_CTRL_RESV_FLD_MASK 0xFFFFFFFCu

/*! @} */

/*! \defgroup INDIRECT_READ_XFER_CTRL_REG Register INDIRECT_READ_XFER_CTRL_REG - indirect_read_xfer_ctrl_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_READ_XFER_CTRL_REG 0x60
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_READ_XFER_CTRL_REG 0x19300060u

/*! Register Reset Value */
#define INDIRECT_READ_XFER_CTRL_REG_RST 0x00000000u

/*! Field START_FLD - start_fld */
#define INDIRECT_READ_XFER_CTRL_REG_START_FLD_POS 0
/*! Field START_FLD - start_fld */
#define INDIRECT_READ_XFER_CTRL_REG_START_FLD_MASK 0x1u

/*! Field CANCEL_FLD - cancel_fld */
#define INDIRECT_READ_XFER_CTRL_REG_CANCEL_FLD_POS 1
/*! Field CANCEL_FLD - cancel_fld */
#define INDIRECT_READ_XFER_CTRL_REG_CANCEL_FLD_MASK 0x2u

/*! Field RD_STATUS_FLD - rd_status_fld */
#define INDIRECT_READ_XFER_CTRL_REG_RD_STATUS_FLD_POS 2
/*! Field RD_STATUS_FLD - rd_status_fld */
#define INDIRECT_READ_XFER_CTRL_REG_RD_STATUS_FLD_MASK 0x4u

/*! Field SRAM_FULL_FLD - sram_full_fld */
#define INDIRECT_READ_XFER_CTRL_REG_SRAM_FULL_FLD_POS 3
/*! Field SRAM_FULL_FLD - sram_full_fld */
#define INDIRECT_READ_XFER_CTRL_REG_SRAM_FULL_FLD_MASK 0x8u

/*! Field RD_QUEUED_FLD - rd_queued_fld */
#define INDIRECT_READ_XFER_CTRL_REG_RD_QUEUED_FLD_POS 4
/*! Field RD_QUEUED_FLD - rd_queued_fld */
#define INDIRECT_READ_XFER_CTRL_REG_RD_QUEUED_FLD_MASK 0x10u

/*! Field IND_OPS_DONE_STATUS_FLD - ind_ops_done_status_fld */
#define INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_POS 5
/*! Field IND_OPS_DONE_STATUS_FLD - ind_ops_done_status_fld */
#define INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_MASK 0x20u

/*! Field NUM_IND_OPS_DONE_FLD - num_ind_ops_done_fld */
#define INDIRECT_READ_XFER_CTRL_REG_NUM_IND_OPS_DONE_FLD_POS 6
/*! Field NUM_IND_OPS_DONE_FLD - num_ind_ops_done_fld */
#define INDIRECT_READ_XFER_CTRL_REG_NUM_IND_OPS_DONE_FLD_MASK 0xC0u

/*! Field INDIR_RD_XFER_RESV_FLD - indir_rd_xfer_resv_fld */
#define INDIRECT_READ_XFER_CTRL_REG_INDIR_RD_XFER_RESV_FLD_POS 8
/*! Field INDIR_RD_XFER_RESV_FLD - indir_rd_xfer_resv_fld */
#define INDIRECT_READ_XFER_CTRL_REG_INDIR_RD_XFER_RESV_FLD_MASK 0xFFFFFF00u

/*! @} */

/*! \defgroup INDIRECT_READ_XFER_WATERMARK_REG Register INDIRECT_READ_XFER_WATERMARK_REG - indirect_read_xfer_watermark_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_READ_XFER_WATERMARK_REG 0x64
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_READ_XFER_WATERMARK_REG 0x19300064u

/*! Register Reset Value */
#define INDIRECT_READ_XFER_WATERMARK_REG_RST 0x00000000u

/*! Field LEVEL_FLD - level_fld */
#define INDIRECT_READ_XFER_WATERMARK_REG_LEVEL_FLD_POS 0
/*! Field LEVEL_FLD - level_fld */
#define INDIRECT_READ_XFER_WATERMARK_REG_LEVEL_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup INDIRECT_READ_XFER_START_REG Register INDIRECT_READ_XFER_START_REG - indirect_read_xfer_start_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_READ_XFER_START_REG 0x68
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_READ_XFER_START_REG 0x19300068u

/*! Register Reset Value */
#define INDIRECT_READ_XFER_START_REG_RST 0x00000000u

/*! Field ADDR_FLD - addr_fld */
#define INDIRECT_READ_XFER_START_REG_ADDR_FLD_POS 0
/*! Field ADDR_FLD - addr_fld */
#define INDIRECT_READ_XFER_START_REG_ADDR_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup INDIRECT_READ_XFER_NUM_BYTES_REG Register INDIRECT_READ_XFER_NUM_BYTES_REG - indirect_read_xfer_num_bytes_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_READ_XFER_NUM_BYTES_REG 0x6C
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_READ_XFER_NUM_BYTES_REG 0x1930006Cu

/*! Register Reset Value */
#define INDIRECT_READ_XFER_NUM_BYTES_REG_RST 0x00000000u

/*! Field VALUE_FLD - value_fld */
#define INDIRECT_READ_XFER_NUM_BYTES_REG_VALUE_FLD_POS 0
/*! Field VALUE_FLD - value_fld */
#define INDIRECT_READ_XFER_NUM_BYTES_REG_VALUE_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup INDIRECT_WRITE_XFER_CTRL_REG Register INDIRECT_WRITE_XFER_CTRL_REG - indirect_write_xfer_ctrl_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_WRITE_XFER_CTRL_REG 0x70
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_WRITE_XFER_CTRL_REG 0x19300070u

/*! Register Reset Value */
#define INDIRECT_WRITE_XFER_CTRL_REG_RST 0x00000000u

/*! Field START_FLD - start_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_START_FLD_POS 0
/*! Field START_FLD - start_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_START_FLD_MASK 0x1u

/*! Field CANCEL_FLD - cancel_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_CANCEL_FLD_POS 1
/*! Field CANCEL_FLD - cancel_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_CANCEL_FLD_MASK 0x2u

/*! Field WR_STATUS_FLD - wr_status_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_WR_STATUS_FLD_POS 2
/*! Field WR_STATUS_FLD - wr_status_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_WR_STATUS_FLD_MASK 0x4u

/*! Field INDIR_WR_XFER_RESV1_FLD - indir_wr_xfer_resv1_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_INDIR_WR_XFER_RESV1_FLD_POS 3
/*! Field INDIR_WR_XFER_RESV1_FLD - indir_wr_xfer_resv1_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_INDIR_WR_XFER_RESV1_FLD_MASK 0x8u

/*! Field WR_QUEUED_FLD - wr_queued_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_WR_QUEUED_FLD_POS 4
/*! Field WR_QUEUED_FLD - wr_queued_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_WR_QUEUED_FLD_MASK 0x10u

/*! Field IND_OPS_DONE_STATUS_FLD - ind_ops_done_status_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_POS 5
/*! Field IND_OPS_DONE_STATUS_FLD - ind_ops_done_status_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_MASK 0x20u

/*! Field NUM_IND_OPS_DONE_FLD - num_ind_ops_done_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_NUM_IND_OPS_DONE_FLD_POS 6
/*! Field NUM_IND_OPS_DONE_FLD - num_ind_ops_done_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_NUM_IND_OPS_DONE_FLD_MASK 0xC0u

/*! Field INDIR_WR_XFER_RESV2_FLD - indir_wr_xfer_resv2_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_INDIR_WR_XFER_RESV2_FLD_POS 8
/*! Field INDIR_WR_XFER_RESV2_FLD - indir_wr_xfer_resv2_fld */
#define INDIRECT_WRITE_XFER_CTRL_REG_INDIR_WR_XFER_RESV2_FLD_MASK 0xFFFFFF00u

/*! @} */

/*! \defgroup INDIRECT_WRITE_XFER_WATERMARK_REG Register INDIRECT_WRITE_XFER_WATERMARK_REG - indirect_write_xfer_watermark_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_WRITE_XFER_WATERMARK_REG 0x74
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_WRITE_XFER_WATERMARK_REG 0x19300074u

/*! Register Reset Value */
#define INDIRECT_WRITE_XFER_WATERMARK_REG_RST 0xFFFFFFFFu

/*! Field LEVEL_FLD - level_fld */
#define INDIRECT_WRITE_XFER_WATERMARK_REG_LEVEL_FLD_POS 0
/*! Field LEVEL_FLD - level_fld */
#define INDIRECT_WRITE_XFER_WATERMARK_REG_LEVEL_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup INDIRECT_WRITE_XFER_START_REG Register INDIRECT_WRITE_XFER_START_REG - indirect_write_xfer_start_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_WRITE_XFER_START_REG 0x78
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_WRITE_XFER_START_REG 0x19300078u

/*! Register Reset Value */
#define INDIRECT_WRITE_XFER_START_REG_RST 0x00000000u

/*! Field ADDR_FLD - addr_fld */
#define INDIRECT_WRITE_XFER_START_REG_ADDR_FLD_POS 0
/*! Field ADDR_FLD - addr_fld */
#define INDIRECT_WRITE_XFER_START_REG_ADDR_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup INDIRECT_WRITE_XFER_NUM_BYTES_REG Register INDIRECT_WRITE_XFER_NUM_BYTES_REG - indirect_write_xfer_num_bytes_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_WRITE_XFER_NUM_BYTES_REG 0x7C
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_WRITE_XFER_NUM_BYTES_REG 0x1930007Cu

/*! Register Reset Value */
#define INDIRECT_WRITE_XFER_NUM_BYTES_REG_RST 0x00000000u

/*! Field VALUE_FLD - value_fld */
#define INDIRECT_WRITE_XFER_NUM_BYTES_REG_VALUE_FLD_POS 0
/*! Field VALUE_FLD - value_fld */
#define INDIRECT_WRITE_XFER_NUM_BYTES_REG_VALUE_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup INDIRECT_TRIGGER_ADDR_RANGE_REG Register INDIRECT_TRIGGER_ADDR_RANGE_REG - indirect_trigger_addr_range_reg */
/*! @{ */

/*! Register Offset (relative) */
#define INDIRECT_TRIGGER_ADDR_RANGE_REG 0x80
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_INDIRECT_TRIGGER_ADDR_RANGE_REG 0x19300080u

/*! Register Reset Value */
#define INDIRECT_TRIGGER_ADDR_RANGE_REG_RST 0x00000004u

/*! Field IND_RANGE_WIDTH_FLD - ind_range_width_fld */
#define INDIRECT_TRIGGER_ADDR_RANGE_REG_IND_RANGE_WIDTH_FLD_POS 0
/*! Field IND_RANGE_WIDTH_FLD - ind_range_width_fld */
#define INDIRECT_TRIGGER_ADDR_RANGE_REG_IND_RANGE_WIDTH_FLD_MASK 0xFu

/*! Field IND_RANGE_RESV1_FLD - ind_range_resv1_fld */
#define INDIRECT_TRIGGER_ADDR_RANGE_REG_IND_RANGE_RESV1_FLD_POS 4
/*! Field IND_RANGE_RESV1_FLD - ind_range_resv1_fld */
#define INDIRECT_TRIGGER_ADDR_RANGE_REG_IND_RANGE_RESV1_FLD_MASK 0xFFFFFFF0u

/*! @} */

/*! \defgroup FLASH_COMMAND_CTRL_MEM_REG Register FLASH_COMMAND_CTRL_MEM_REG - flash_command_ctrl_mem_reg */
/*! @{ */

/*! Register Offset (relative) */
#define FLASH_COMMAND_CTRL_MEM_REG 0x8C
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_FLASH_COMMAND_CTRL_MEM_REG 0x1930008Cu

/*! Register Reset Value */
#define FLASH_COMMAND_CTRL_MEM_REG_RST 0x00000000u

/*! Field TRIGGER_MEM_BANK_REQ_FLD - trigger_mem_bank_req_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_TRIGGER_MEM_BANK_REQ_FLD_POS 0
/*! Field TRIGGER_MEM_BANK_REQ_FLD - trigger_mem_bank_req_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_TRIGGER_MEM_BANK_REQ_FLD_MASK 0x1u

/*! Field MEM_BANK_REQ_IN_PROGRESS_FLD - mem_bank_req_in_progress_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_MEM_BANK_REQ_IN_PROGRESS_FLD_POS 1
/*! Field MEM_BANK_REQ_IN_PROGRESS_FLD - mem_bank_req_in_progress_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_MEM_BANK_REQ_IN_PROGRESS_FLD_MASK 0x2u

/*! Field FLASH_COMMAND_CTRL_MEM_RESV3_FLD - flash_command_ctrl_mem_resv3_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_FLASH_COMMAND_CTRL_MEM_RESV3_FLD_POS 2
/*! Field FLASH_COMMAND_CTRL_MEM_RESV3_FLD - flash_command_ctrl_mem_resv3_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_FLASH_COMMAND_CTRL_MEM_RESV3_FLD_MASK 0xFCu

/*! Field MEM_BANK_READ_DATA_FLD - mem_bank_read_data_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_MEM_BANK_READ_DATA_FLD_POS 8
/*! Field MEM_BANK_READ_DATA_FLD - mem_bank_read_data_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_MEM_BANK_READ_DATA_FLD_MASK 0xFF00u

/*! Field NB_OF_STIG_READ_BYTES_FLD - nb_of_stig_read_bytes_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_NB_OF_STIG_READ_BYTES_FLD_POS 16
/*! Field NB_OF_STIG_READ_BYTES_FLD - nb_of_stig_read_bytes_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_NB_OF_STIG_READ_BYTES_FLD_MASK 0x70000u

/*! Field FLASH_COMMAND_CTRL_MEM_RESV2_FLD - flash_command_ctrl_mem_resv2_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_FLASH_COMMAND_CTRL_MEM_RESV2_FLD_POS 19
/*! Field FLASH_COMMAND_CTRL_MEM_RESV2_FLD - flash_command_ctrl_mem_resv2_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_FLASH_COMMAND_CTRL_MEM_RESV2_FLD_MASK 0x80000u

/*! Field MEM_BANK_ADDR_FLD - mem_bank_addr_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_MEM_BANK_ADDR_FLD_POS 20
/*! Field MEM_BANK_ADDR_FLD - mem_bank_addr_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_MEM_BANK_ADDR_FLD_MASK 0x1FF00000u

/*! Field FLASH_COMMAND_CTRL_MEM_RESV1_FLD - flash_command_ctrl_mem_resv1_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_FLASH_COMMAND_CTRL_MEM_RESV1_FLD_POS 29
/*! Field FLASH_COMMAND_CTRL_MEM_RESV1_FLD - flash_command_ctrl_mem_resv1_fld */
#define FLASH_COMMAND_CTRL_MEM_REG_FLASH_COMMAND_CTRL_MEM_RESV1_FLD_MASK 0xE0000000u

/*! @} */

/*! \defgroup FLASH_CMD_CTRL_REG Register FLASH_CMD_CTRL_REG - flash_cmd_ctrl_reg */
/*! @{ */

/*! Register Offset (relative) */
#define FLASH_CMD_CTRL_REG 0x90
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_FLASH_CMD_CTRL_REG 0x19300090u

/*! Register Reset Value */
#define FLASH_CMD_CTRL_REG_RST 0x00000000u

/*! Field CMD_EXEC_FLD - cmd_exec_fld */
#define FLASH_CMD_CTRL_REG_CMD_EXEC_FLD_POS 0
/*! Field CMD_EXEC_FLD - cmd_exec_fld */
#define FLASH_CMD_CTRL_REG_CMD_EXEC_FLD_MASK 0x1u

/*! Field CMD_EXEC_STATUS_FLD - cmd_exec_status_fld */
#define FLASH_CMD_CTRL_REG_CMD_EXEC_STATUS_FLD_POS 1
/*! Field CMD_EXEC_STATUS_FLD - cmd_exec_status_fld */
#define FLASH_CMD_CTRL_REG_CMD_EXEC_STATUS_FLD_MASK 0x2u

/*! Field STIG_MEM_BANK_EN_FLD - stig_mem_bank_en_fld */
#define FLASH_CMD_CTRL_REG_STIG_MEM_BANK_EN_FLD_POS 2
/*! Field STIG_MEM_BANK_EN_FLD - stig_mem_bank_en_fld */
#define FLASH_CMD_CTRL_REG_STIG_MEM_BANK_EN_FLD_MASK 0x4u

/*! Field FLASH_CMD_CTRL_RESV1_FLD - flash_cmd_ctrl_resv1_fld */
#define FLASH_CMD_CTRL_REG_FLASH_CMD_CTRL_RESV1_FLD_POS 3
/*! Field FLASH_CMD_CTRL_RESV1_FLD - flash_cmd_ctrl_resv1_fld */
#define FLASH_CMD_CTRL_REG_FLASH_CMD_CTRL_RESV1_FLD_MASK 0x78u

/*! Field NUM_DUMMY_CYCLES_FLD - num_dummy_cycles_fld */
#define FLASH_CMD_CTRL_REG_NUM_DUMMY_CYCLES_FLD_POS 7
/*! Field NUM_DUMMY_CYCLES_FLD - num_dummy_cycles_fld */
#define FLASH_CMD_CTRL_REG_NUM_DUMMY_CYCLES_FLD_MASK 0xF80u

/*! Field NUM_WR_DATA_BYTES_FLD - num_wr_data_bytes_fld */
#define FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD_POS 12
/*! Field NUM_WR_DATA_BYTES_FLD - num_wr_data_bytes_fld */
#define FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD_MASK 0x7000u

/*! Field ENB_WRITE_DATA_FLD - enb_write_data_fld */
#define FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD_POS 15
/*! Field ENB_WRITE_DATA_FLD - enb_write_data_fld */
#define FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD_MASK 0x8000u

/*! Field NUM_ADDR_BYTES_FLD - num_addr_bytes_fld */
#define FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD_POS 16
/*! Field NUM_ADDR_BYTES_FLD - num_addr_bytes_fld */
#define FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD_MASK 0x30000u

/*! Field ENB_MODE_BIT_FLD - enb_mode_bit_fld */
#define FLASH_CMD_CTRL_REG_ENB_MODE_BIT_FLD_POS 18
/*! Field ENB_MODE_BIT_FLD - enb_mode_bit_fld */
#define FLASH_CMD_CTRL_REG_ENB_MODE_BIT_FLD_MASK 0x40000u

/*! Field ENB_COMD_ADDR_FLD - enb_comd_addr_fld */
#define FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD_POS 19
/*! Field ENB_COMD_ADDR_FLD - enb_comd_addr_fld */
#define FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD_MASK 0x80000u

/*! Field NUM_RD_DATA_BYTES_FLD - num_rd_data_bytes_fld */
#define FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD_POS 20
/*! Field NUM_RD_DATA_BYTES_FLD - num_rd_data_bytes_fld */
#define FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD_MASK 0x700000u

/*! Field ENB_READ_DATA_FLD - enb_read_data_fld */
#define FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD_POS 23
/*! Field ENB_READ_DATA_FLD - enb_read_data_fld */
#define FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD_MASK 0x800000u

/*! Field CMD_OPCODE_FLD - cmd_opcode_fld */
#define FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD_POS 24
/*! Field CMD_OPCODE_FLD - cmd_opcode_fld */
#define FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD_MASK 0xFF000000u

/*! @} */

/*! \defgroup FLASH_CMD_ADDR_REG Register FLASH_CMD_ADDR_REG - flash_cmd_addr_reg */
/*! @{ */

/*! Register Offset (relative) */
#define FLASH_CMD_ADDR_REG 0x94
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_FLASH_CMD_ADDR_REG 0x19300094u

/*! Register Reset Value */
#define FLASH_CMD_ADDR_REG_RST 0x00000000u

/*! Field ADDR_FLD - addr_fld */
#define FLASH_CMD_ADDR_REG_ADDR_FLD_POS 0
/*! Field ADDR_FLD - addr_fld */
#define FLASH_CMD_ADDR_REG_ADDR_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup FLASH_RD_DATA_LOWER_REG Register FLASH_RD_DATA_LOWER_REG - flash_rd_data_lower_reg */
/*! @{ */

/*! Register Offset (relative) */
#define FLASH_RD_DATA_LOWER_REG 0xA0
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_FLASH_RD_DATA_LOWER_REG 0x193000A0u

/*! Register Reset Value */
#define FLASH_RD_DATA_LOWER_REG_RST 0x00000000u

/*! Field DATA_FLD - data_fld */
#define FLASH_RD_DATA_LOWER_REG_DATA_FLD_POS 0
/*! Field DATA_FLD - data_fld */
#define FLASH_RD_DATA_LOWER_REG_DATA_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup FLASH_RD_DATA_UPPER_REG Register FLASH_RD_DATA_UPPER_REG - flash_rd_data_upper_reg */
/*! @{ */

/*! Register Offset (relative) */
#define FLASH_RD_DATA_UPPER_REG 0xA4
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_FLASH_RD_DATA_UPPER_REG 0x193000A4u

/*! Register Reset Value */
#define FLASH_RD_DATA_UPPER_REG_RST 0x00000000u

/*! Field DATA_FLD - data_fld */
#define FLASH_RD_DATA_UPPER_REG_DATA_FLD_POS 0
/*! Field DATA_FLD - data_fld */
#define FLASH_RD_DATA_UPPER_REG_DATA_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup FLASH_WR_DATA_LOWER_REG Register FLASH_WR_DATA_LOWER_REG - flash_wr_data_lower_reg */
/*! @{ */

/*! Register Offset (relative) */
#define FLASH_WR_DATA_LOWER_REG 0xA8
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_FLASH_WR_DATA_LOWER_REG 0x193000A8u

/*! Register Reset Value */
#define FLASH_WR_DATA_LOWER_REG_RST 0x00000000u

/*! Field DATA_FLD - data_fld */
#define FLASH_WR_DATA_LOWER_REG_DATA_FLD_POS 0
/*! Field DATA_FLD - data_fld */
#define FLASH_WR_DATA_LOWER_REG_DATA_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup FLASH_WR_DATA_UPPER_REG Register FLASH_WR_DATA_UPPER_REG - flash_wr_data_upper_reg */
/*! @{ */

/*! Register Offset (relative) */
#define FLASH_WR_DATA_UPPER_REG 0xAC
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_FLASH_WR_DATA_UPPER_REG 0x193000ACu

/*! Register Reset Value */
#define FLASH_WR_DATA_UPPER_REG_RST 0x00000000u

/*! Field DATA_FLD - data_fld */
#define FLASH_WR_DATA_UPPER_REG_DATA_FLD_POS 0
/*! Field DATA_FLD - data_fld */
#define FLASH_WR_DATA_UPPER_REG_DATA_FLD_MASK 0xFFFFFFFFu

/*! @} */

/*! \defgroup POLLING_FLASH_STATUS_REG Register POLLING_FLASH_STATUS_REG - polling_flash_status_reg */
/*! @{ */

/*! Register Offset (relative) */
#define POLLING_FLASH_STATUS_REG 0xB0
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_POLLING_FLASH_STATUS_REG 0x193000B0u

/*! Register Reset Value */
#define POLLING_FLASH_STATUS_REG_RST 0x00000000u

/*! Field DEVICE_STATUS_FLD - device_status_fld */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_FLD_POS 0
/*! Field DEVICE_STATUS_FLD - device_status_fld */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_FLD_MASK 0xFFu

/*! Field DEVICE_STATUS_VALID_FLD - device_status_valid_fld */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_VALID_FLD_POS 8
/*! Field DEVICE_STATUS_VALID_FLD - device_status_valid_fld */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_VALID_FLD_MASK 0x100u

/*! Field DEVICE_STATUS_RSVD_FLD1 - device_status_rsvd_fld1 */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_RSVD_FLD1_POS 9
/*! Field DEVICE_STATUS_RSVD_FLD1 - device_status_rsvd_fld1 */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_RSVD_FLD1_MASK 0xFE00u

/*! Field DEVICE_STATUS_NB_DUMMY - device_status_nb_dummy */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_NB_DUMMY_POS 16
/*! Field DEVICE_STATUS_NB_DUMMY - device_status_nb_dummy */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_NB_DUMMY_MASK 0xF0000u

/*! Field DEVICE_STATUS_RSVD_FLD2 - device_status_rsvd_fld2 */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_RSVD_FLD2_POS 20
/*! Field DEVICE_STATUS_RSVD_FLD2 - device_status_rsvd_fld2 */
#define POLLING_FLASH_STATUS_REG_DEVICE_STATUS_RSVD_FLD2_MASK 0xFFF00000u

/*! @} */

/*! \defgroup PHY_CONFIGURATION_REG Register PHY_CONFIGURATION_REG - phy_configuration_reg */
/*! @{ */

/*! Register Offset (relative) */
#define PHY_CONFIGURATION_REG 0xB4
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_PHY_CONFIGURATION_REG 0x193000B4u

/*! Register Reset Value */
#define PHY_CONFIGURATION_REG_RST 0x40000000u

/*! Field PHY_CONFIG_RX_DLL_DELAY_FLD - phy_config_rx_dll_delay_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RX_DLL_DELAY_FLD_POS 0
/*! Field PHY_CONFIG_RX_DLL_DELAY_FLD - phy_config_rx_dll_delay_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RX_DLL_DELAY_FLD_MASK 0x7Fu

/*! Field PHY_CONFIG_RESV1_FLD - phy_config_resv1_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESV1_FLD_POS 7
/*! Field PHY_CONFIG_RESV1_FLD - phy_config_resv1_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESV1_FLD_MASK 0xFF80u

/*! Field PHY_CONFIG_TX_DLL_DELAY_FLD - phy_config_tx_dll_delay_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_TX_DLL_DELAY_FLD_POS 16
/*! Field PHY_CONFIG_TX_DLL_DELAY_FLD - phy_config_tx_dll_delay_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_TX_DLL_DELAY_FLD_MASK 0x7F0000u

/*! Field PHY_CONFIG_RESV2_FLD - phy_config_resv2_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESV2_FLD_POS 23
/*! Field PHY_CONFIG_RESV2_FLD - phy_config_resv2_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESV2_FLD_MASK 0x1F800000u

/*! Field PHY_CONFIG_RX_DLL_BYPASS_FLD - phy_config_rx_dll_bypass_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RX_DLL_BYPASS_FLD_POS 29
/*! Field PHY_CONFIG_RX_DLL_BYPASS_FLD - phy_config_rx_dll_bypass_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RX_DLL_BYPASS_FLD_MASK 0x20000000u

/*! Field PHY_CONFIG_RESET_FLD - phy_config_reset_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESET_FLD_POS 30
/*! Field PHY_CONFIG_RESET_FLD - phy_config_reset_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESET_FLD_MASK 0x40000000u

/*! Field PHY_CONFIG_RESYNC_FLD - phy_config_resync_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESYNC_FLD_POS 31
/*! Field PHY_CONFIG_RESYNC_FLD - phy_config_resync_fld */
#define PHY_CONFIGURATION_REG_PHY_CONFIG_RESYNC_FLD_MASK 0x80000000u

/*! @} */

/*! \defgroup PHY_MASTER_CONTROL_REG Register PHY_MASTER_CONTROL_REG - phy_master_control_reg */
/*! @{ */

/*! Register Offset (relative) */
#define PHY_MASTER_CONTROL_REG 0xB8
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_PHY_MASTER_CONTROL_REG 0x193000B8u

/*! Register Reset Value */
#define PHY_MASTER_CONTROL_REG_RST 0x00800000u

/*! Field PHY_MASTER_INITIAL_DELAY_FLD - phy_master_initial_delay_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_INITIAL_DELAY_FLD_POS 0
/*! Field PHY_MASTER_INITIAL_DELAY_FLD - phy_master_initial_delay_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_INITIAL_DELAY_FLD_MASK 0x7Fu

/*! Field PHY_MASTER_CONTROL_RESV1_FLD - phy_master_control_resv1_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_CONTROL_RESV1_FLD_POS 7
/*! Field PHY_MASTER_CONTROL_RESV1_FLD - phy_master_control_resv1_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_CONTROL_RESV1_FLD_MASK 0xFF80u

/*! Field PHY_MASTER_NB_INDICATIONS_FLD - phy_master_nb_indications_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_NB_INDICATIONS_FLD_POS 16
/*! Field PHY_MASTER_NB_INDICATIONS_FLD - phy_master_nb_indications_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_NB_INDICATIONS_FLD_MASK 0x70000u

/*! Field PHY_MASTER_CONTROL_RESV2_FLD - phy_master_control_resv2_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_CONTROL_RESV2_FLD_POS 19
/*! Field PHY_MASTER_CONTROL_RESV2_FLD - phy_master_control_resv2_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_CONTROL_RESV2_FLD_MASK 0x80000u

/*! Field PHY_MASTER_PHASE_DETECT_SELECTOR_FLD - phy_master_phase_detect_selector_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_PHASE_DETECT_SELECTOR_FLD_POS 20
/*! Field PHY_MASTER_PHASE_DETECT_SELECTOR_FLD - phy_master_phase_detect_selector_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_PHASE_DETECT_SELECTOR_FLD_MASK 0x700000u

/*! Field PHY_MASTER_BYPASS_MODE_FLD - phy_master_bypass_mode_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_BYPASS_MODE_FLD_POS 23
/*! Field PHY_MASTER_BYPASS_MODE_FLD - phy_master_bypass_mode_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_BYPASS_MODE_FLD_MASK 0x800000u

/*! Field PHY_MASTER_LOCK_MODE_FLD - phy_master_lock_mode_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_LOCK_MODE_FLD_POS 24
/*! Field PHY_MASTER_LOCK_MODE_FLD - phy_master_lock_mode_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_LOCK_MODE_FLD_MASK 0x1000000u

/*! Field PHY_MASTER_CONTROL_RESV3_FLD - phy_master_control_resv3_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_CONTROL_RESV3_FLD_POS 25
/*! Field PHY_MASTER_CONTROL_RESV3_FLD - phy_master_control_resv3_fld */
#define PHY_MASTER_CONTROL_REG_PHY_MASTER_CONTROL_RESV3_FLD_MASK 0xFE000000u

/*! @} */

/*! \defgroup DLL_OBSERVABLE_LOWER_REG Register DLL_OBSERVABLE_LOWER_REG - dll_observable_lower_reg */
/*! @{ */

/*! Register Offset (relative) */
#define DLL_OBSERVABLE_LOWER_REG 0xBC
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_DLL_OBSERVABLE_LOWER_REG 0x193000BCu

/*! Register Reset Value */
#define DLL_OBSERVABLE_LOWER_REG_RST 0x00000000u

/*! Field DLL_OBSERVABLE_LOWER_DLL_LOCK_FLD - dll_observable_lower_dll_lock_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_DLL_LOCK_FLD_POS 0
/*! Field DLL_OBSERVABLE_LOWER_DLL_LOCK_FLD - dll_observable_lower_dll_lock_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_DLL_LOCK_FLD_MASK 0x1u

/*! Field DLL_OBSERVABLE_LOWER_LOCK_MODE_FLD - dll_observable_lower_lock_mode_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOCK_MODE_FLD_POS 1
/*! Field DLL_OBSERVABLE_LOWER_LOCK_MODE_FLD - dll_observable_lower_lock_mode_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOCK_MODE_FLD_MASK 0x6u

/*! Field DLL_OBSERVABLE_LOWER_UNLOCK_COUNTER_FLD - dll_observable_lower_unlock_counter_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_UNLOCK_COUNTER_FLD_POS 3
/*! Field DLL_OBSERVABLE_LOWER_UNLOCK_COUNTER_FLD - dll_observable_lower_unlock_counter_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_UNLOCK_COUNTER_FLD_MASK 0xF8u

/*! Field DLL_OBSERVABLE_LOWER_LOCK_VALUE_FLD - dll_observable_lower_lock_value_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOCK_VALUE_FLD_POS 8
/*! Field DLL_OBSERVABLE_LOWER_LOCK_VALUE_FLD - dll_observable_lower_lock_value_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOCK_VALUE_FLD_MASK 0x7F00u

/*! Field DLL_OBSERVABLE_LOWER_LOOPBACK_LOCK_FLD - dll_observable_lower_loopback_lock_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOOPBACK_LOCK_FLD_POS 15
/*! Field DLL_OBSERVABLE_LOWER_LOOPBACK_LOCK_FLD - dll_observable_lower_loopback_lock_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOOPBACK_LOCK_FLD_MASK 0x8000u

/*! Field DLL_OBSERVABLE_LOWER_DLL_LOCK_DEC_FLD - dll_observable_lower_dll_lock_dec_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_DLL_LOCK_DEC_FLD_POS 16
/*! Field DLL_OBSERVABLE_LOWER_DLL_LOCK_DEC_FLD - dll_observable_lower_dll_lock_dec_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_DLL_LOCK_DEC_FLD_MASK 0xFF0000u

/*! Field DLL_OBSERVABLE_LOWER_DLL_LOCK_INC_FLD - dll_observable_lower_dll_lock_inc_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_DLL_LOCK_INC_FLD_POS 24
/*! Field DLL_OBSERVABLE_LOWER_DLL_LOCK_INC_FLD - dll_observable_lower_dll_lock_inc_fld */
#define DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_DLL_LOCK_INC_FLD_MASK 0xFF000000u

/*! @} */

/*! \defgroup DLL_OBSERVABLE_UPPER_REG Register DLL_OBSERVABLE_UPPER_REG - dll_observable_upper_reg */
/*! @{ */

/*! Register Offset (relative) */
#define DLL_OBSERVABLE_UPPER_REG 0xC0
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_DLL_OBSERVABLE_UPPER_REG 0x193000C0u

/*! Register Reset Value */
#define DLL_OBSERVABLE_UPPER_REG_RST 0x00000000u

/*! Field DLL_OBSERUDEC - dll_observable__upper_rx_decoder_output_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERUDEC_POS 0
/*! Field DLL_OBSERUDEC - dll_observable__upper_rx_decoder_output_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERUDEC_MASK 0x7Fu

/*! Field DLL_OBSERVABLE_UPPER_RESV1_FLD - dll_observable_upper_resv1_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE_UPPER_RESV1_FLD_POS 7
/*! Field DLL_OBSERVABLE_UPPER_RESV1_FLD - dll_observable_upper_resv1_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE_UPPER_RESV1_FLD_MASK 0xFF80u

/*! Field DLL_OBSERVABLE_UPPER_TX_DECODER_OUTPUT_FLD - dll_observable_upper_tx_decoder_output_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE_UPPER_TX_DECODER_OUTPUT_FLD_POS 16
/*! Field DLL_OBSERVABLE_UPPER_TX_DECODER_OUTPUT_FLD - dll_observable_upper_tx_decoder_output_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE_UPPER_TX_DECODER_OUTPUT_FLD_MASK 0x7F0000u

/*! Field DLL_OBSERVABLE_UPPER_RESV2_FLD - dll_observable_upper_resv2_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE_UPPER_RESV2_FLD_POS 23
/*! Field DLL_OBSERVABLE_UPPER_RESV2_FLD - dll_observable_upper_resv2_fld */
#define DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE_UPPER_RESV2_FLD_MASK 0xFF800000u

/*! @} */

/*! \defgroup MODULE_ID_REG Register MODULE_ID_REG - module_id_reg */
/*! @{ */

/*! Register Offset (relative) */
#define MODULE_ID_REG 0xFC
/*! Register Offset (absolute) for 1st Instance QSPI */
#define QSPI_MODULE_ID_REG 0x193000FCu

/*! Register Reset Value */
#define MODULE_ID_REG_RST 0x00000302u

/*! Field CONF_FLD - conf_fld */
#define MODULE_ID_REG_CONF_FLD_POS 0
/*! Field CONF_FLD - conf_fld */
#define MODULE_ID_REG_CONF_FLD_MASK 0x3u

/*! Field MODULE_ID_RESV_FLD - module_id_resv_fld */
#define MODULE_ID_REG_MODULE_ID_RESV_FLD_POS 2
/*! Field MODULE_ID_RESV_FLD - module_id_resv_fld */
#define MODULE_ID_REG_MODULE_ID_RESV_FLD_MASK 0xFCu

/*! Field MODULE_ID_FLD - module_id_fld */
#define MODULE_ID_REG_MODULE_ID_FLD_POS 8
/*! Field MODULE_ID_FLD - module_id_fld */
#define MODULE_ID_REG_MODULE_ID_FLD_MASK 0xFFFF00u

/*! Field FIX_PATCH_FLD - fix_patch_fld */
#define MODULE_ID_REG_FIX_PATCH_FLD_POS 24
/*! Field FIX_PATCH_FLD - fix_patch_fld */
#define MODULE_ID_REG_FIX_PATCH_FLD_MASK 0xFF000000u

/*! @} */

/*! @} */

#endif
