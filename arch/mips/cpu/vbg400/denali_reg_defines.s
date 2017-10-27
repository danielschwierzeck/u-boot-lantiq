#ifdef mt47h64m8_25e
#ifdef ddr_clk_160

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = CTL
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 170
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 1
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 0
## ********************************************************************
## Memory: mt47h64m8_25e.xml
## ********************************************************************


.equ               DENALI_CTL_00_DATA ,0b00000000000000000000010000000000 ##0000000000000000 version(RD) 0000_0100 dram_class(RW) 0000000_0 start(RW) 
.equ               DENALI_CTL_01_DATA ,0b00000000000000000000000000000000 ##000000000000000_0 max_cs_reg(RD) 0000_0000 max_col_reg(RD) 0000_0000 max_row_reg(RD) 
.equ               DENALI_CTL_02_DATA ,0b00000010000000000000000000100010 ##0000_0010 initaref(RW) 000000000000000000100010 tinit(RW) 
.equ               DENALI_CTL_03_DATA ,0b00000010000000100000001100001000 ##000_00010 tccd(RW) 00000_010 tbst_int_interval(RW) 0000_0011 wrlat(RW) 0000_1000 caslat_lin(RW) 
.equ               DENALI_CTL_04_DATA ,0b00000010000010000000101000000010 ##0000_0010 twtr(RW) 00001000 tras_min(RW) 00001010 trc(RW) 00000010 trrd(RW) 
.equ               DENALI_CTL_05_DATA ,0b00000011000000100000001000000011 ##00000011 tmod(RW) 000_00010 tmrd(RW) 00000_010 trtp(RW) 0000_0011 trp(RW) 
.equ               DENALI_CTL_06_DATA ,0b00000011000000110010111001101101 ##000_00011 tckesr(RW) 00000_011 tcke(RW) 0010111001101101 tras_max(RW) 
.equ               DENALI_CTL_07_DATA ,0b00000001000000010000000000000000 ##0000000_1 tras_lockout(RW) 0000000_1 concurrentap(RW) 0000000_0 ap(RW) 0000000_0 writeinterp(RW) 
.equ               DENALI_CTL_08_DATA ,0b00000000000001100000001100000011 ##00000000000_00110 tdal(RW) 000_00011 twr_int(RW) 00000011 trcd_int(RW) 
.equ               DENALI_CTL_09_DATA ,0b00000010000000000000000011001000 ##00000_010 bstlen(RW_D) 0000000_0 no_cmd_init(RW) 0000000011001000 tdll(RW) 
.equ               DENALI_CTL_10_DATA ,0b00000011000000000100010000000000 ##0000_0011 trp_ab(RW) 0000000001000100 tcpd(RW) 00_000000 tfaw(RW) 
.equ               DENALI_CTL_11_DATA ,0b00000001000000000000000000000000 ##0000000_1 tref_enable(RW) 0000000_0 auto_refresh_mode(RW) 0000000_0 arefresh(WR) 0000000_0 reg_dimm_enable(RW) 
.equ               DENALI_CTL_12_DATA ,0b00000100110110000000000000010010 ##00_00010011011000 tref(RW) 000000_0000010010 trfc(RW) 
.equ               DENALI_CTL_13_DATA ,0b00000000000000100000000000000000 ##0000000000000010 tpdex(RW) 0000000_0 power_down(RW) 00000000
.equ               DENALI_CTL_14_DATA ,0b00000000000101000000000011001000 ##0000000000010100 txsnr(RW) 0000000011001000 txsr(RW) 
.equ               DENALI_CTL_15_DATA ,0b00000001000000000000000000000000 ##0000000_1 enable_quick_srefresh(RW) 0000000_0 srefresh_exit_no_refresh(RW) 0000000_0 pwrup_srefresh_exit(RW) 0000000_0 srefresh(RW+) 
.equ               DENALI_CTL_16_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_power_down_cnt(RW) 000_00000 lowpower_control(RW) 00000_000 cke_delay(RW) 
.equ               DENALI_CTL_17_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_external_cnt(RW) 0000000000000000 lowpower_self_refresh_cnt(RW) 
.equ               DENALI_CTL_18_DATA ,0b00000000000000000000000000000000 ##0000000_0 lowpower_refresh_enable(RW) 0000000000000000 lowpower_internal_cnt(RW) 000_00000 lowpower_auto_enable(RW) 
.equ               DENALI_CTL_19_DATA ,0b00000000000000000000001100000011 ##00000000000000000000_0011 cksrx(RW) 0000_0011 cksre(RW) 
.equ               DENALI_CTL_20_DATA ,0b00000000000000000000000000000000 ##000000_00000000000000000000000000 write_modereg(RW+) 
.equ               DENALI_CTL_21_DATA ,0b00000000000001000100001000000000 ##0000000000_00010001000010 mr0_data_0(RW) 00000000 mrw_status(RD) 
.equ               DENALI_CTL_22_DATA ,0b00000000000000000000010001000000 ##00_00000000000000 mr2_data_0(RW) 00_00010001000000 mr1_data_0(RW) 
.equ               DENALI_CTL_23_DATA ,0b00000000000000000000000000000000 ##00_00000000000000 mr3_data_0(RW) 00_00000000000000 mrsingle_data_0(RW) 
.equ               DENALI_CTL_24_DATA ,0b00001010000000100000000000000000 ##0000_1010 aprebit(RW_D) 00000_010 column_size(RW) 00000_000 addr_pins(RW) 0000000_0 eight_bank_mode(RW) 
.equ               DENALI_CTL_25_DATA ,0b00000001000000010000101000001010 ##0000000_1 bank_split_en(RW) 0000000_1 addr_cmp_en(RW) 000_01010 command_age_count(RW) 000_01010 age_count(RW) 
.equ               DENALI_CTL_26_DATA ,0b00000001000000010000000100000001 ##0000000_1 swap_en(RW) 0000000_1 rw_same_en(RW) 0000000_1 priority_en(RW) 0000000_1 placement_en(RW) 
.equ               DENALI_CTL_27_DATA ,0b00000000000000000000000100000000 ##00000_000 q_fullness(RW) 0000000_0 fast_write(RW) 0000000_1 reduc(RW) 0000000_0 inhibit_dram_cmd(RW) 
.equ               DENALI_CTL_28_DATA ,0b00000000000000000000000100000000 ##0000_000000000000 int_status(RD) 0000000_1 resync_dll_per_aref_en(RW) 0000000_0 resync_dll(WR) 
.equ               DENALI_CTL_29_DATA ,0b00000000000000000000000000000000 ##0000_000000000000 int_mask(RW) 00000_00000000000 int_ack(WR) 
.equ               DENALI_CTL_30_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 out_of_range_addr(RD) 
.equ               DENALI_CTL_31_DATA ,0b00000000000000000000000000000000 ##000000000_0000000 out_of_range_source_id(RD) 00_000000 out_of_range_type(RD) 00_000000 out_of_range_length(RD) 
.equ               DENALI_CTL_32_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 port_cmd_error_addr(RD) 
.equ               DENALI_CTL_33_DATA ,0b00000000000000000000000000000000 ##00000_000 port_data_error_type(RD) 0_0000000 port_data_error_id(RD) 0000_0000 port_cmd_error_type(RD) 0_0000000 port_cmd_error_id(RD) 
.equ               DENALI_CTL_34_DATA ,0b00000001000000000000000000000000 ##00000_001 r2w_samecs_dly(RW) 00000_000 r2r_samecs_dly(RW) 0000_0000 add_odt_clk_w2r_samecs(RW) 0000_0000 add_odt_clk_r2w_samecs(RW) 
.equ               DENALI_CTL_35_DATA ,0b00000000000000000000000000000000 ##000_00000 ocd_adjust_pup_cs_0(RW) 000_00000 ocd_adjust_pdn_cs_0(RW) 00000_000 w2w_samecs_dly(RW) 00000_000 w2r_samecs_dly(RW) 
.equ               DENALI_CTL_36_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb1_rdlen(RW) 0000_1111 ahb1_wrlen(RW) 0000_1111 ahb0_rdlen(RW) 0000_1111 ahb0_wrlen(RW) 
.equ               DENALI_CTL_37_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb3_rdlen(RW) 0000_1111 ahb3_wrlen(RW) 0000_1111 ahb2_rdlen(RW) 0000_1111 ahb2_wrlen(RW) 
.equ               DENALI_CTL_38_DATA ,0b00000000000000010000111100001111 ##0000000000000001 axi0_en_size_lt_width_instr(RW) 0000_1111 ahb4_rdlen(RW) 0000_1111 ahb4_wrlen(RW) 
.equ               DENALI_CTL_39_DATA ,0b00000000000000000000001100000011 ##00000000000000_00 axi0_fifo_type_reg(RW) 00000_011 axi0_w_priority(RW) 00000_011 axi0_r_priority(RW) 
.equ               DENALI_CTL_40_DATA ,0b00000011000000110000000000000001 ##00000_011 axi1_w_priority(RW) 00000_011 axi1_r_priority(RW) 0000000000000001 axi1_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_41_DATA ,0b00000010000000000000000100000000 ##00000_010 axi2_r_priority(RW) 0000000000000001 axi2_en_size_lt_width_instr(RW) 000000_00 axi1_fifo_type_reg(RW) 
.equ               DENALI_CTL_42_DATA ,0b00000000000000010000000000000010 ##0000000000000001 axi3_en_size_lt_width_instr(RW) 000000_00 axi2_fifo_type_reg(RW) 00000_010 axi2_w_priority(RW) 
.equ               DENALI_CTL_43_DATA ,0b00000000000000000000001100000011 ##00000000000000_00 axi3_fifo_type_reg(RW) 00000_011 axi3_w_priority(RW) 00000_011 axi3_r_priority(RW) 
.equ               DENALI_CTL_44_DATA ,0b00000011000000110000000000000001 ##00000_011 axi4_w_priority(RW) 00000_011 axi4_r_priority(RW) 0000000000000001 axi4_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_45_DATA ,0b00000010000000000000000100000000 ##00000_010 axi5_r_priority(RW) 0000000000000001 axi5_en_size_lt_width_instr(RW) 000000_00 axi4_fifo_type_reg(RW) 
.equ               DENALI_CTL_46_DATA ,0b00000000000000000000000000000010 ##00000_000 weighted_round_robin_weight_sharing(RW) 0000000_0 weighted_round_robin_latency_control(RW) 000000_00 axi5_fifo_type_reg(RW) 00000_010 axi5_w_priority(RW) 
.equ               DENALI_CTL_47_DATA ,0b00000001000000010000000100000000 ##0000_0001 axi0_priority2_relative_priority(RW) 0000_0001 axi0_priority1_relative_priority(RW) 0000_0001 axi0_priority0_relative_priority(RW) 0000_0000 wrr_param_value_err(RD) 
.equ               DENALI_CTL_48_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi0_priority6_relative_priority(RW) 0000_0001 axi0_priority5_relative_priority(RW) 0000_0001 axi0_priority4_relative_priority(RW) 0000_0001 axi0_priority3_relative_priority(RW) 
.equ               DENALI_CTL_49_DATA ,0b00000000011001000000000000000001 ##000000_0001100100 axi0_priority_relax(RW) 00000_000 axi0_port_ordering(RW) 0000_0001 axi0_priority7_relative_priority(RW) 
.equ               DENALI_CTL_50_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority3_relative_priority(RW) 0000_0001 axi1_priority2_relative_priority(RW) 0000_0001 axi1_priority1_relative_priority(RW) 0000_0001 axi1_priority0_relative_priority(RW) 
.equ               DENALI_CTL_51_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority7_relative_priority(RW) 0000_0001 axi1_priority6_relative_priority(RW) 0000_0001 axi1_priority5_relative_priority(RW) 0000_0001 axi1_priority4_relative_priority(RW) 
.equ               DENALI_CTL_52_DATA ,0b00000001000000000110010000000001 ##0000_0001 axi2_priority0_relative_priority(RW) 000000_0001100100 axi1_priority_relax(RW) 00000_001 axi1_port_ordering(RW) 
.equ               DENALI_CTL_53_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi2_priority4_relative_priority(RW) 0000_0001 axi2_priority3_relative_priority(RW) 0000_0001 axi2_priority2_relative_priority(RW) 0000_0001 axi2_priority1_relative_priority(RW) 
.equ               DENALI_CTL_54_DATA ,0b00000010000000010000000100000001 ##00000_010 axi2_port_ordering(RW) 0000_0001 axi2_priority7_relative_priority(RW) 0000_0001 axi2_priority6_relative_priority(RW) 0000_0001 axi2_priority5_relative_priority(RW) 
.equ               DENALI_CTL_55_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi3_priority1_relative_priority(RW) 0000_0001 axi3_priority0_relative_priority(RW) 000000_0001100100 axi2_priority_relax(RW) 
.equ               DENALI_CTL_56_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi3_priority5_relative_priority(RW) 0000_0001 axi3_priority4_relative_priority(RW) 0000_0001 axi3_priority3_relative_priority(RW) 0000_0001 axi3_priority2_relative_priority(RW) 
.equ               DENALI_CTL_57_DATA ,0b00000000000000110000000100000001 ##0000000000000_011 axi3_port_ordering(RW) 0000_0001 axi3_priority7_relative_priority(RW) 0000_0001 axi3_priority6_relative_priority(RW) 
.equ               DENALI_CTL_58_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi4_priority1_relative_priority(RW) 0000_0001 axi4_priority0_relative_priority(RW) 000000_0001100100 axi3_priority_relax(RW) 
.equ               DENALI_CTL_59_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi4_priority5_relative_priority(RW) 0000_0001 axi4_priority4_relative_priority(RW) 0000_0001 axi4_priority3_relative_priority(RW) 0000_0001 axi4_priority2_relative_priority(RW) 
.equ               DENALI_CTL_60_DATA ,0b00000000000001000000000100000001 ##0000000000000_100 axi4_port_ordering(RW) 0000_0001 axi4_priority7_relative_priority(RW) 0000_0001 axi4_priority6_relative_priority(RW) 
.equ               DENALI_CTL_61_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi5_priority1_relative_priority(RW) 0000_0001 axi5_priority0_relative_priority(RW) 000000_0001100100 axi4_priority_relax(RW) 
.equ               DENALI_CTL_62_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi5_priority5_relative_priority(RW) 0000_0001 axi5_priority4_relative_priority(RW) 0000_0001 axi5_priority3_relative_priority(RW) 0000_0001 axi5_priority2_relative_priority(RW) 
.equ               DENALI_CTL_63_DATA ,0b00000000000001010000000100000001 ##0000000000000_101 axi5_port_ordering(RW) 0000_0001 axi5_priority7_relative_priority(RW) 0000_0001 axi5_priority6_relative_priority(RW) 
.equ               DENALI_CTL_64_DATA ,0b00000000000000000000000001100100 ##000000000000000_0 cke_status(RD) 000000_0001100100 axi5_priority_relax(RW) 
.equ               DENALI_CTL_65_DATA ,0b00000000000000000000000000000000 ##0000_0000 tdfi_phy_wrlat(RD) 00000000 dll_rst_adj_dly(RW) 0000000000000000 dll_rst_delay(RW) 
.equ               DENALI_CTL_66_DATA ,0b00000000000000000000011000000000 ##0000000_0 dram_clk_disable(RW) 0000_0000 tdfi_rddata_en(RD) 0000_0110 tdfi_phy_rdlat(RW_D) 0_0000000 update_error_status(RD) 
.equ               DENALI_CTL_67_DATA ,0b00000000000001001101100000000000 ##0000000000_00010011011000 tdfi_ctrlupd_max(RW) 0000_0000 tdfi_ctrlupd_min(RD) 
.equ               DENALI_CTL_68_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type1(RW) 0000001000000000 tdfi_phyupd_type0(RW) 
.equ               DENALI_CTL_69_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type3(RW) 0000001000000000 tdfi_phyupd_type2(RW) 
.equ               DENALI_CTL_70_DATA ,0b00000000000000000000010011011000 ##000000000000000000_00010011011000 tdfi_phyupd_resp(RW) 
.equ               DENALI_CTL_71_DATA ,0b00000000000000000001100000111000 ##00000000000000000001100000111000 tdfi_ctrlupd_interval(RW) 
.equ               DENALI_CTL_72_DATA ,0b00000000000000100000001100000100 ##00000_000 tdfi_dram_clk_disable(RW) 0000_0010 tdfi_ctrl_delay(RW_D) 0000_0011 wrlat_adj(RW) 0000_0100 rdlat_adj(RW) 
.equ               DENALI_CTL_73_DATA ,0b00000000000000000000000100000001 ##00000000000000000000000_1 odt_alt_en(RW) 0000_0001 tdfi_dram_clk_enable(RW) 

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = PHY
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 170
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 1
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 0
## ********************************************************************
## Memory: mt47h64m8_25e.xml
## ********************************************************************


.equ               DENALI_PHY_00_DATA, 0b00000000000100010001000100000000 ##00000000000100010001000100000000 phy_pad_ctrl_reg_0(RW) 
.equ               DENALI_PHY_01_DATA, 0b11110011000000010011101000100111 ##11110011000000010011101000100111 den_phy_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_02_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_03_DATA, 0b11110011000000010011101000100111 ##11110011000000010011101000100111 den_phy_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_04_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_05_DATA, 0b00000000000000000010101000000100 ##00000000000000000010101000000100 den_phy_ctrl_reg_2(RW) 
.equ               DENALI_PHY_06_DATA, 0b00100000000010000001111001100100 ##00100000000010000001111001100100 phy_dll_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_07_DATA, 0b00000001000010000001111100001110 ##00000001000010000001111100001110 phy_dll_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_08_DATA, 0b00100000000010000001111001100100 ##00100000000010000001111001100100 phy_dll_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_09_DATA, 0b00000001000010000001111100001110 ##00000001000010000001111100001110 phy_dll_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_10_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_0(RD) 
.equ               DENALI_PHY_11_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_0(RD) 
.equ               DENALI_PHY_12_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_0(RD) 
.equ               DENALI_PHY_13_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_1(RD) 
.equ               DENALI_PHY_14_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_1(RD) 
.equ               DENALI_PHY_15_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_1(RD) 
#else ##ddr_clk_160

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = CTL
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 250
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 1
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 1
## ********************************************************************
## Memory: mt47h64m8_25e.xml
## ********************************************************************


.equ               DENALI_CTL_00_DATA ,0b00000000000000000000010000000000 ##0000000000000000 version(RD) 0000_0100 dram_class(RW) 0000000_0 start(RW) 
.equ               DENALI_CTL_01_DATA ,0b00000000000000000000000000000000 ##000000000000000_0 max_cs_reg(RD) 0000_0000 max_col_reg(RD) 0000_0000 max_row_reg(RD) 
.equ               DENALI_CTL_02_DATA ,0b00000010000000000000000000110010 ##0000_0010 initaref(RW) 000000000000000000110010 tinit(RW) 
.equ               DENALI_CTL_03_DATA ,0b00000010000000100000001100001000 ##000_00010 tccd(RW) 00000_010 tbst_int_interval(RW) 0000_0011 wrlat(RW) 0000_1000 caslat_lin(RW) 
.equ               DENALI_CTL_04_DATA ,0b00000010000011000000111000000010 ##0000_0010 twtr(RW) 00001100 tras_min(RW) 00001110 trc(RW) 00000010 trrd(RW) 
.equ               DENALI_CTL_05_DATA ,0b00000011000000100000001000000100 ##00000011 tmod(RW) 000_00010 tmrd(RW) 00000_010 trtp(RW) 0000_0100 trp(RW) 
.equ               DENALI_CTL_06_DATA ,0b00000011000000110100010001011100 ##000_00011 tckesr(RW) 00000_011 tcke(RW) 0100010001011100 tras_max(RW) 
.equ               DENALI_CTL_07_DATA ,0b00000001000000010000000000000000 ##0000000_1 tras_lockout(RW) 0000000_1 concurrentap(RW) 0000000_0 ap(RW) 0000000_0 writeinterp(RW) 
.equ               DENALI_CTL_08_DATA ,0b00000000000010000000010000000100 ##00000000000_01000 tdal(RW) 000_00100 twr_int(RW) 00000100 trcd_int(RW) 
.equ               DENALI_CTL_09_DATA ,0b00000010000000000000000011001000 ##00000_010 bstlen(RW_D) 0000000_0 no_cmd_init(RW) 0000000011001000 tdll(RW) 
.equ               DENALI_CTL_10_DATA ,0b00000100000000000110010000000000 ##0000_0100 trp_ab(RW) 0000000001100100 tcpd(RW) 00_000000 tfaw(RW) 
.equ               DENALI_CTL_11_DATA ,0b00000001000000000000000000000000 ##0000000_1 tref_enable(RW) 0000000_0 auto_refresh_mode(RW) 0000000_0 arefresh(WR) 0000000_0 reg_dimm_enable(RW) 
.equ               DENALI_CTL_12_DATA ,0b00000111010010110000000000011011 ##00_00011101001011 tref(RW) 000000_0000011011 trfc(RW) 
.equ               DENALI_CTL_13_DATA ,0b00000000000000100000000000000000 ##0000000000000010 tpdex(RW) 0000000_0 power_down(RW) 00000000
.equ               DENALI_CTL_14_DATA ,0b00000000000111010000000011001000 ##0000000000011101 txsnr(RW) 0000000011001000 txsr(RW) 
.equ               DENALI_CTL_15_DATA ,0b00000001000000000000000000000000 ##0000000_1 enable_quick_srefresh(RW) 0000000_0 srefresh_exit_no_refresh(RW) 0000000_0 pwrup_srefresh_exit(RW) 0000000_0 srefresh(RW+) 
.equ               DENALI_CTL_16_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_power_down_cnt(RW) 000_00000 lowpower_control(RW) 00000_000 cke_delay(RW) 
.equ               DENALI_CTL_17_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_external_cnt(RW) 0000000000000000 lowpower_self_refresh_cnt(RW) 
.equ               DENALI_CTL_18_DATA ,0b00000000000000000000000000000000 ##0000000_0 lowpower_refresh_enable(RW) 0000000000000000 lowpower_internal_cnt(RW) 000_00000 lowpower_auto_enable(RW) 
.equ               DENALI_CTL_19_DATA ,0b00000000000000000000001100000011 ##00000000000000000000_0011 cksrx(RW) 0000_0011 cksre(RW) 
.equ               DENALI_CTL_20_DATA ,0b00000000000000000000000000000000 ##000000_00000000000000000000000000 write_modereg(RW+) 
.equ               DENALI_CTL_21_DATA ,0b00000000000001100100001000000000 ##0000000000_00011001000010 mr0_data_0(RW) 00000000 mrw_status(RD) 
.equ               DENALI_CTL_22_DATA ,0b00000000000000000000010001000000 ##00_00000000000000 mr2_data_0(RW) 00_00010001000000 mr1_data_0(RW) 
.equ               DENALI_CTL_23_DATA ,0b00000000000000000000000000000000 ##00_00000000000000 mr3_data_0(RW) 00_00000000000000 mrsingle_data_0(RW) 
.equ               DENALI_CTL_24_DATA ,0b00001010000000100000000000000000 ##0000_1010 aprebit(RW_D) 00000_010 column_size(RW) 00000_000 addr_pins(RW) 0000000_0 eight_bank_mode(RW) 
.equ               DENALI_CTL_25_DATA ,0b00000001000000010000101000001010 ##0000000_1 bank_split_en(RW) 0000000_1 addr_cmp_en(RW) 000_01010 command_age_count(RW) 000_01010 age_count(RW) 
.equ               DENALI_CTL_26_DATA ,0b00000001000000010000000100000001 ##0000000_1 swap_en(RW) 0000000_1 rw_same_en(RW) 0000000_1 priority_en(RW) 0000000_1 placement_en(RW) 
.equ               DENALI_CTL_27_DATA ,0b00000000000000000000000100000000 ##00000_000 q_fullness(RW) 0000000_0 fast_write(RW) 0000000_1 reduc(RW) 0000000_0 inhibit_dram_cmd(RW) 
.equ               DENALI_CTL_28_DATA ,0b00000000000000000000000100000000 ##0000_000000000000 int_status(RD) 0000000_1 resync_dll_per_aref_en(RW) 0000000_0 resync_dll(WR) 
.equ               DENALI_CTL_29_DATA ,0b00000000000000000000000000000000 ##0000_000000000000 int_mask(RW) 00000_00000000000 int_ack(WR) 
.equ               DENALI_CTL_30_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 out_of_range_addr(RD) 
.equ               DENALI_CTL_31_DATA ,0b00000000000000000000000000000000 ##000000000_0000000 out_of_range_source_id(RD) 00_000000 out_of_range_type(RD) 00_000000 out_of_range_length(RD) 
.equ               DENALI_CTL_32_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 port_cmd_error_addr(RD) 
.equ               DENALI_CTL_33_DATA ,0b00000000000000000000000000000000 ##00000_000 port_data_error_type(RD) 0_0000000 port_data_error_id(RD) 0000_0000 port_cmd_error_type(RD) 0_0000000 port_cmd_error_id(RD) 
.equ               DENALI_CTL_34_DATA ,0b00000001000000000000000000000000 ##00000_001 r2w_samecs_dly(RW) 00000_000 r2r_samecs_dly(RW) 0000_0000 add_odt_clk_w2r_samecs(RW) 0000_0000 add_odt_clk_r2w_samecs(RW) 
.equ               DENALI_CTL_35_DATA ,0b00000000000000000000000000000000 ##000_00000 ocd_adjust_pup_cs_0(RW) 000_00000 ocd_adjust_pdn_cs_0(RW) 00000_000 w2w_samecs_dly(RW) 00000_000 w2r_samecs_dly(RW) 
.equ               DENALI_CTL_36_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb1_rdlen(RW) 0000_1111 ahb1_wrlen(RW) 0000_1111 ahb0_rdlen(RW) 0000_1111 ahb0_wrlen(RW) 
.equ               DENALI_CTL_37_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb3_rdlen(RW) 0000_1111 ahb3_wrlen(RW) 0000_1111 ahb2_rdlen(RW) 0000_1111 ahb2_wrlen(RW) 
.equ               DENALI_CTL_38_DATA ,0b00000000000000010000111100001111 ##0000000000000001 axi0_en_size_lt_width_instr(RW) 0000_1111 ahb4_rdlen(RW) 0000_1111 ahb4_wrlen(RW) 
.equ               DENALI_CTL_39_DATA ,0b00000000000000110000001100000011 ##00000000000000_11 axi0_fifo_type_reg(RW) 00000_011 axi0_w_priority(RW) 00000_011 axi0_r_priority(RW) 
.equ               DENALI_CTL_40_DATA ,0b00000011000000110000000000000001 ##00000_011 axi1_w_priority(RW) 00000_011 axi1_r_priority(RW) 0000000000000001 axi1_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_41_DATA ,0b00000010000000000000000100000011 ##00000_010 axi2_r_priority(RW) 0000000000000001 axi2_en_size_lt_width_instr(RW) 000000_11 axi1_fifo_type_reg(RW) 
.equ               DENALI_CTL_42_DATA ,0b00000000000000010000001100000010 ##0000000000000001 axi3_en_size_lt_width_instr(RW) 000000_11 axi2_fifo_type_reg(RW) 00000_010 axi2_w_priority(RW) 
.equ               DENALI_CTL_43_DATA ,0b00000000000000110000001100000011 ##00000000000000_11 axi3_fifo_type_reg(RW) 00000_011 axi3_w_priority(RW) 00000_011 axi3_r_priority(RW) 
.equ               DENALI_CTL_44_DATA ,0b00000011000000110000000000000001 ##00000_011 axi4_w_priority(RW) 00000_011 axi4_r_priority(RW) 0000000000000001 axi4_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_45_DATA ,0b00000010000000000000000100000011 ##00000_010 axi5_r_priority(RW) 0000000000000001 axi5_en_size_lt_width_instr(RW) 000000_11 axi4_fifo_type_reg(RW) 
.equ               DENALI_CTL_46_DATA ,0b00000000000000000000001100000010 ##00000_000 weighted_round_robin_weight_sharing(RW) 0000000_0 weighted_round_robin_latency_control(RW) 000000_11 axi5_fifo_type_reg(RW) 00000_010 axi5_w_priority(RW) 
.equ               DENALI_CTL_47_DATA ,0b00000001000000010000000100000000 ##0000_0001 axi0_priority2_relative_priority(RW) 0000_0001 axi0_priority1_relative_priority(RW) 0000_0001 axi0_priority0_relative_priority(RW) 0000_0000 wrr_param_value_err(RD) 
.equ               DENALI_CTL_48_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi0_priority6_relative_priority(RW) 0000_0001 axi0_priority5_relative_priority(RW) 0000_0001 axi0_priority4_relative_priority(RW) 0000_0001 axi0_priority3_relative_priority(RW) 
.equ               DENALI_CTL_49_DATA ,0b00000000011001000000000000000001 ##000000_0001100100 axi0_priority_relax(RW) 00000_000 axi0_port_ordering(RW) 0000_0001 axi0_priority7_relative_priority(RW) 
.equ               DENALI_CTL_50_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority3_relative_priority(RW) 0000_0001 axi1_priority2_relative_priority(RW) 0000_0001 axi1_priority1_relative_priority(RW) 0000_0001 axi1_priority0_relative_priority(RW) 
.equ               DENALI_CTL_51_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority7_relative_priority(RW) 0000_0001 axi1_priority6_relative_priority(RW) 0000_0001 axi1_priority5_relative_priority(RW) 0000_0001 axi1_priority4_relative_priority(RW) 
.equ               DENALI_CTL_52_DATA ,0b00000001000000000110010000000001 ##0000_0001 axi2_priority0_relative_priority(RW) 000000_0001100100 axi1_priority_relax(RW) 00000_001 axi1_port_ordering(RW) 
.equ               DENALI_CTL_53_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi2_priority4_relative_priority(RW) 0000_0001 axi2_priority3_relative_priority(RW) 0000_0001 axi2_priority2_relative_priority(RW) 0000_0001 axi2_priority1_relative_priority(RW) 
.equ               DENALI_CTL_54_DATA ,0b00000010000000010000000100000001 ##00000_010 axi2_port_ordering(RW) 0000_0001 axi2_priority7_relative_priority(RW) 0000_0001 axi2_priority6_relative_priority(RW) 0000_0001 axi2_priority5_relative_priority(RW) 
.equ               DENALI_CTL_55_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi3_priority1_relative_priority(RW) 0000_0001 axi3_priority0_relative_priority(RW) 000000_0001100100 axi2_priority_relax(RW) 
.equ               DENALI_CTL_56_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi3_priority5_relative_priority(RW) 0000_0001 axi3_priority4_relative_priority(RW) 0000_0001 axi3_priority3_relative_priority(RW) 0000_0001 axi3_priority2_relative_priority(RW) 
.equ               DENALI_CTL_57_DATA ,0b00000000000000110000000100000001 ##0000000000000_011 axi3_port_ordering(RW) 0000_0001 axi3_priority7_relative_priority(RW) 0000_0001 axi3_priority6_relative_priority(RW) 
.equ               DENALI_CTL_58_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi4_priority1_relative_priority(RW) 0000_0001 axi4_priority0_relative_priority(RW) 000000_0001100100 axi3_priority_relax(RW) 
.equ               DENALI_CTL_59_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi4_priority5_relative_priority(RW) 0000_0001 axi4_priority4_relative_priority(RW) 0000_0001 axi4_priority3_relative_priority(RW) 0000_0001 axi4_priority2_relative_priority(RW) 
.equ               DENALI_CTL_60_DATA ,0b00000000000001000000000100000001 ##0000000000000_100 axi4_port_ordering(RW) 0000_0001 axi4_priority7_relative_priority(RW) 0000_0001 axi4_priority6_relative_priority(RW) 
.equ               DENALI_CTL_61_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi5_priority1_relative_priority(RW) 0000_0001 axi5_priority0_relative_priority(RW) 000000_0001100100 axi4_priority_relax(RW) 
.equ               DENALI_CTL_62_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi5_priority5_relative_priority(RW) 0000_0001 axi5_priority4_relative_priority(RW) 0000_0001 axi5_priority3_relative_priority(RW) 0000_0001 axi5_priority2_relative_priority(RW) 
.equ               DENALI_CTL_63_DATA ,0b00000000000001010000000100000001 ##0000000000000_101 axi5_port_ordering(RW) 0000_0001 axi5_priority7_relative_priority(RW) 0000_0001 axi5_priority6_relative_priority(RW) 
.equ               DENALI_CTL_64_DATA ,0b00000000000000000000000001100100 ##000000000000000_0 cke_status(RD) 000000_0001100100 axi5_priority_relax(RW) 
.equ               DENALI_CTL_65_DATA ,0b00000000000000000000000000000000 ##0000_0000 tdfi_phy_wrlat(RD) 00000000 dll_rst_adj_dly(RW) 0000000000000000 dll_rst_delay(RW) 
.equ               DENALI_CTL_66_DATA ,0b00000000000000000000011100000000 ##0000000_0 dram_clk_disable(RW) 0000_0000 tdfi_rddata_en(RD) 0000_0111 tdfi_phy_rdlat(RW_D) 0_0000000 update_error_status(RD) 
.equ               DENALI_CTL_67_DATA ,0b00000000000001110100101100000000 ##0000000000_00011101001011 tdfi_ctrlupd_max(RW) 0000_0000 tdfi_ctrlupd_min(RD) 
.equ               DENALI_CTL_68_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type1(RW) 0000001000000000 tdfi_phyupd_type0(RW) 
.equ               DENALI_CTL_69_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type3(RW) 0000001000000000 tdfi_phyupd_type2(RW) 
.equ               DENALI_CTL_70_DATA ,0b00000000000000000000011101001011 ##000000000000000000_00011101001011 tdfi_phyupd_resp(RW) 
.equ               DENALI_CTL_71_DATA ,0b00000000000000000010010001110111 ##00000000000000000010010001110111 tdfi_ctrlupd_interval(RW) 
.equ               DENALI_CTL_72_DATA ,0b00000000000000100000001100000100 ##00000_000 tdfi_dram_clk_disable(RW) 0000_0010 tdfi_ctrl_delay(RW_D) 0000_0011 wrlat_adj(RW) 0000_0100 rdlat_adj(RW) 
.equ               DENALI_CTL_73_DATA ,0b00000000000000000000000100000001 ##00000000000000000000000_1 odt_alt_en(RW) 0000_0001 tdfi_dram_clk_enable(RW) 

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = PHY
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 250
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 1
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 1
## ********************************************************************
## Memory: mt47h64m8_25e.xml
## ********************************************************************


.equ               DENALI_PHY_00_DATA, 0b00000000000100010001000100000000 ##00000000000100010001000100000000 phy_pad_ctrl_reg_0(RW) 
.equ               DENALI_PHY_01_DATA, 0b11110100000000010100101100110111 ##11110100000000010100101100110111 den_phy_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_02_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_03_DATA, 0b11110100000000010100101100110111 ##11110100000000010100101100110111 den_phy_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_04_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_05_DATA, 0b00000000000000000010101000000101 ##00000000000000000010101000000101 den_phy_ctrl_reg_2(RW) 
.equ               DENALI_PHY_06_DATA, 0b00100000000001010001110101000100 ##00100000000001010001110101000100 phy_dll_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_07_DATA, 0b00000001000001010001111100001001 ##00000001000001010001111100001001 phy_dll_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_08_DATA, 0b00100000000001010001110101000100 ##00100000000001010001110101000100 phy_dll_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_09_DATA, 0b00000001000001010001111100001001 ##00000001000001010001111100001001 phy_dll_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_10_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_0(RD) 
.equ               DENALI_PHY_11_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_0(RD) 
.equ               DENALI_PHY_12_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_0(RD) 
.equ               DENALI_PHY_13_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_1(RD) 
.equ               DENALI_PHY_14_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_1(RD) 
.equ               DENALI_PHY_15_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_1(RD) 
#endif ##ddr_clk_160
#else ##mt47h64m8_25e
#ifdef k4t51163qj_f8
#ifdef ddr_clk_160

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = CTL
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 170
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 0
## ********************************************************************
## Memory: k4t51163qj_f8.xml
## ********************************************************************


.equ               DENALI_CTL_00_DATA ,0b00000000000000000000010000000000 ##0000000000000000 version(RD) 0000_0100 dram_class(RW) 0000000_0 start(RW) 
.equ               DENALI_CTL_01_DATA ,0b00000000000000000000000000000000 ##000000000000000_0 max_cs_reg(RD) 0000_0000 max_col_reg(RD) 0000_0000 max_row_reg(RD) 
.equ               DENALI_CTL_02_DATA ,0b00000010000000000000000000100010 ##0000_0010 initaref(RW) 000000000000000000100010 tinit(RW) 
.equ               DENALI_CTL_03_DATA ,0b00000010000000100000001100001000 ##000_00010 tccd(RW) 00000_010 tbst_int_interval(RW) 0000_0011 wrlat(RW) 0000_1000 caslat_lin(RW) 
.equ               DENALI_CTL_04_DATA ,0b00000010000010000000101000000010 ##0000_0010 twtr(RW) 00001000 tras_min(RW) 00001010 trc(RW) 00000010 trrd(RW) 
.equ               DENALI_CTL_05_DATA ,0b00000011000000100000001000000011 ##00000011 tmod(RW) 000_00010 tmrd(RW) 00000_010 trtp(RW) 0000_0011 trp(RW) 
.equ               DENALI_CTL_06_DATA ,0b00000011000000110010111001101101 ##000_00011 tckesr(RW) 00000_011 tcke(RW) 0010111001101101 tras_max(RW) 
.equ               DENALI_CTL_07_DATA ,0b00000001000000010000000000000000 ##0000000_1 tras_lockout(RW) 0000000_1 concurrentap(RW) 0000000_0 ap(RW) 0000000_0 writeinterp(RW) 
.equ               DENALI_CTL_08_DATA ,0b00000000000001100000001100000011 ##00000000000_00110 tdal(RW) 000_00011 twr_int(RW) 00000011 trcd_int(RW) 
.equ               DENALI_CTL_09_DATA ,0b00000010000000000000000011001000 ##00000_010 bstlen(RW_D) 0000000_0 no_cmd_init(RW) 0000000011001000 tdll(RW) 
.equ               DENALI_CTL_10_DATA ,0b00000011000000000100010000001000 ##0000_0011 trp_ab(RW) 0000000001000100 tcpd(RW) 00_001000 tfaw(RW) 
.equ               DENALI_CTL_11_DATA ,0b00000001000000000000000000000000 ##0000000_1 tref_enable(RW) 0000000_0 auto_refresh_mode(RW) 0000000_0 arefresh(WR) 0000000_0 reg_dimm_enable(RW) 
.equ               DENALI_CTL_12_DATA ,0b00000100110110000000000000010010 ##00_00010011011000 tref(RW) 000000_0000010010 trfc(RW) 
.equ               DENALI_CTL_13_DATA ,0b00000000000000110000000000000000 ##0000000000000011 tpdex(RW) 0000000_0 power_down(RW) 00000000
.equ               DENALI_CTL_14_DATA ,0b00000000000101000000000011001000 ##0000000000010100 txsnr(RW) 0000000011001000 txsr(RW) 
.equ               DENALI_CTL_15_DATA ,0b00000001000000000000000000000000 ##0000000_1 enable_quick_srefresh(RW) 0000000_0 srefresh_exit_no_refresh(RW) 0000000_0 pwrup_srefresh_exit(RW) 0000000_0 srefresh(RW+) 
.equ               DENALI_CTL_16_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_power_down_cnt(RW) 000_00000 lowpower_control(RW) 00000_000 cke_delay(RW) 
.equ               DENALI_CTL_17_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_external_cnt(RW) 0000000000000000 lowpower_self_refresh_cnt(RW) 
.equ               DENALI_CTL_18_DATA ,0b00000000000000000000000000000000 ##0000000_0 lowpower_refresh_enable(RW) 0000000000000000 lowpower_internal_cnt(RW) 000_00000 lowpower_auto_enable(RW) 
.equ               DENALI_CTL_19_DATA ,0b00000000000000000000001100000011 ##00000000000000000000_0011 cksrx(RW) 0000_0011 cksre(RW) 
.equ               DENALI_CTL_20_DATA ,0b00000000000000000000000000000000 ##000000_00000000000000000000000000 write_modereg(RW+) 
.equ               DENALI_CTL_21_DATA ,0b00000000000001000100001000000000 ##0000000000_00010001000010 mr0_data_0(RW) 00000000 mrw_status(RD) 
.equ               DENALI_CTL_22_DATA ,0b00000000000000000000010001000010 ##00_00000000000000 mr2_data_0(RW) 00_00010001000000 mr1_data_0(RW) 
.equ               DENALI_CTL_23_DATA ,0b00000000000000000000000000000000 ##00_00000000000000 mr3_data_0(RW) 00_00000000000000 mrsingle_data_0(RW) 
.equ               DENALI_CTL_24_DATA ,0b00001010000000100000000100000000 ##0000_1010 aprebit(RW_D) 00000_010 column_size(RW) 00000_001 addr_pins(RW) 0000000_0 eight_bank_mode(RW) 
.equ               DENALI_CTL_25_DATA ,0b00000001000000010000101000001010 ##0000000_1 bank_split_en(RW) 0000000_1 addr_cmp_en(RW) 000_01010 command_age_count(RW) 000_01010 age_count(RW) 
.equ               DENALI_CTL_26_DATA ,0b00000001000000010000000100000001 ##0000000_1 swap_en(RW) 0000000_1 rw_same_en(RW) 0000000_1 priority_en(RW) 0000000_1 placement_en(RW) 
.equ               DENALI_CTL_27_DATA ,0b00000000000000000000000000000000 ##00000_000 q_fullness(RW) 0000000_0 fast_write(RW) 0000000_0 reduc(RW) 0000000_0 inhibit_dram_cmd(RW) 
.equ               DENALI_CTL_28_DATA ,0b00000000000000000000000100000000 ##0000_000000000000 int_status(RD) 0000000_1 resync_dll_per_aref_en(RW) 0000000_0 resync_dll(WR) 
.equ               DENALI_CTL_29_DATA ,0b00000000000000000000000000000000 ##0000_000000000000 int_mask(RW) 00000_00000000000 int_ack(WR) 
.equ               DENALI_CTL_30_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 out_of_range_addr(RD) 
.equ               DENALI_CTL_31_DATA ,0b00000000000000000000000000000000 ##000000000_0000000 out_of_range_source_id(RD) 00_000000 out_of_range_type(RD) 00_000000 out_of_range_length(RD) 
.equ               DENALI_CTL_32_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 port_cmd_error_addr(RD) 
.equ               DENALI_CTL_33_DATA ,0b00000000000000000000000000000000 ##00000_000 port_data_error_type(RD) 0_0000000 port_data_error_id(RD) 0000_0000 port_cmd_error_type(RD) 0_0000000 port_cmd_error_id(RD) 
.equ               DENALI_CTL_34_DATA ,0b00000001000000000000000000000000 ##00000_001 r2w_samecs_dly(RW) 00000_000 r2r_samecs_dly(RW) 0000_0000 add_odt_clk_w2r_samecs(RW) 0000_0000 add_odt_clk_r2w_samecs(RW) 
.equ               DENALI_CTL_35_DATA ,0b00000000000000000000000000000000 ##000_00000 ocd_adjust_pup_cs_0(RW) 000_00000 ocd_adjust_pdn_cs_0(RW) 00000_000 w2w_samecs_dly(RW) 00000_000 w2r_samecs_dly(RW) 
.equ               DENALI_CTL_36_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb1_rdlen(RW) 0000_1111 ahb1_wrlen(RW) 0000_1111 ahb0_rdlen(RW) 0000_1111 ahb0_wrlen(RW) 
.equ               DENALI_CTL_37_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb3_rdlen(RW) 0000_1111 ahb3_wrlen(RW) 0000_1111 ahb2_rdlen(RW) 0000_1111 ahb2_wrlen(RW) 
.equ               DENALI_CTL_38_DATA ,0b00000000000000010000111100001111 ##0000000000000001 axi0_en_size_lt_width_instr(RW) 0000_1111 ahb4_rdlen(RW) 0000_1111 ahb4_wrlen(RW) 
.equ               DENALI_CTL_39_DATA ,0b00000000000000000000001100000011 ##00000000000000_00 axi0_fifo_type_reg(RW) 00000_011 axi0_w_priority(RW) 00000_011 axi0_r_priority(RW) 
.equ               DENALI_CTL_40_DATA ,0b00000011000000110000000000000001 ##00000_011 axi1_w_priority(RW) 00000_011 axi1_r_priority(RW) 0000000000000001 axi1_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_41_DATA ,0b00000010000000000000000100000000 ##00000_010 axi2_r_priority(RW) 0000000000000001 axi2_en_size_lt_width_instr(RW) 000000_00 axi1_fifo_type_reg(RW) 
.equ               DENALI_CTL_42_DATA ,0b00000000000000010000000000000010 ##0000000000000001 axi3_en_size_lt_width_instr(RW) 000000_00 axi2_fifo_type_reg(RW) 00000_010 axi2_w_priority(RW) 
.equ               DENALI_CTL_43_DATA ,0b00000000000000000000001100000011 ##00000000000000_00 axi3_fifo_type_reg(RW) 00000_011 axi3_w_priority(RW) 00000_011 axi3_r_priority(RW) 
.equ               DENALI_CTL_44_DATA ,0b00000011000000110000000000000001 ##00000_011 axi4_w_priority(RW) 00000_011 axi4_r_priority(RW) 0000000000000001 axi4_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_45_DATA ,0b00000010000000000000000100000000 ##00000_010 axi5_r_priority(RW) 0000000000000001 axi5_en_size_lt_width_instr(RW) 000000_00 axi4_fifo_type_reg(RW) 
.equ               DENALI_CTL_46_DATA ,0b00000000000000000000000000000010 ##00000_000 weighted_round_robin_weight_sharing(RW) 0000000_0 weighted_round_robin_latency_control(RW) 000000_00 axi5_fifo_type_reg(RW) 00000_010 axi5_w_priority(RW) 
.equ               DENALI_CTL_47_DATA ,0b00000001000000010000000100000000 ##0000_0001 axi0_priority2_relative_priority(RW) 0000_0001 axi0_priority1_relative_priority(RW) 0000_0001 axi0_priority0_relative_priority(RW) 0000_0000 wrr_param_value_err(RD) 
.equ               DENALI_CTL_48_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi0_priority6_relative_priority(RW) 0000_0001 axi0_priority5_relative_priority(RW) 0000_0001 axi0_priority4_relative_priority(RW) 0000_0001 axi0_priority3_relative_priority(RW) 
.equ               DENALI_CTL_49_DATA ,0b00000000011001000000000000000001 ##000000_0001100100 axi0_priority_relax(RW) 00000_000 axi0_port_ordering(RW) 0000_0001 axi0_priority7_relative_priority(RW) 
.equ               DENALI_CTL_50_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority3_relative_priority(RW) 0000_0001 axi1_priority2_relative_priority(RW) 0000_0001 axi1_priority1_relative_priority(RW) 0000_0001 axi1_priority0_relative_priority(RW) 
.equ               DENALI_CTL_51_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority7_relative_priority(RW) 0000_0001 axi1_priority6_relative_priority(RW) 0000_0001 axi1_priority5_relative_priority(RW) 0000_0001 axi1_priority4_relative_priority(RW) 
.equ               DENALI_CTL_52_DATA ,0b00000001000000000110010000000001 ##0000_0001 axi2_priority0_relative_priority(RW) 000000_0001100100 axi1_priority_relax(RW) 00000_001 axi1_port_ordering(RW) 
.equ               DENALI_CTL_53_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi2_priority4_relative_priority(RW) 0000_0001 axi2_priority3_relative_priority(RW) 0000_0001 axi2_priority2_relative_priority(RW) 0000_0001 axi2_priority1_relative_priority(RW) 
.equ               DENALI_CTL_54_DATA ,0b00000010000000010000000100000001 ##00000_010 axi2_port_ordering(RW) 0000_0001 axi2_priority7_relative_priority(RW) 0000_0001 axi2_priority6_relative_priority(RW) 0000_0001 axi2_priority5_relative_priority(RW) 
.equ               DENALI_CTL_55_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi3_priority1_relative_priority(RW) 0000_0001 axi3_priority0_relative_priority(RW) 000000_0001100100 axi2_priority_relax(RW) 
.equ               DENALI_CTL_56_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi3_priority5_relative_priority(RW) 0000_0001 axi3_priority4_relative_priority(RW) 0000_0001 axi3_priority3_relative_priority(RW) 0000_0001 axi3_priority2_relative_priority(RW) 
.equ               DENALI_CTL_57_DATA ,0b00000000000000110000000100000001 ##0000000000000_011 axi3_port_ordering(RW) 0000_0001 axi3_priority7_relative_priority(RW) 0000_0001 axi3_priority6_relative_priority(RW) 
.equ               DENALI_CTL_58_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi4_priority1_relative_priority(RW) 0000_0001 axi4_priority0_relative_priority(RW) 000000_0001100100 axi3_priority_relax(RW) 
.equ               DENALI_CTL_59_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi4_priority5_relative_priority(RW) 0000_0001 axi4_priority4_relative_priority(RW) 0000_0001 axi4_priority3_relative_priority(RW) 0000_0001 axi4_priority2_relative_priority(RW) 
.equ               DENALI_CTL_60_DATA ,0b00000000000001000000000100000001 ##0000000000000_100 axi4_port_ordering(RW) 0000_0001 axi4_priority7_relative_priority(RW) 0000_0001 axi4_priority6_relative_priority(RW) 
.equ               DENALI_CTL_61_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi5_priority1_relative_priority(RW) 0000_0001 axi5_priority0_relative_priority(RW) 000000_0001100100 axi4_priority_relax(RW) 
.equ               DENALI_CTL_62_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi5_priority5_relative_priority(RW) 0000_0001 axi5_priority4_relative_priority(RW) 0000_0001 axi5_priority3_relative_priority(RW) 0000_0001 axi5_priority2_relative_priority(RW) 
.equ               DENALI_CTL_63_DATA ,0b00000000000001010000000100000001 ##0000000000000_101 axi5_port_ordering(RW) 0000_0001 axi5_priority7_relative_priority(RW) 0000_0001 axi5_priority6_relative_priority(RW) 
.equ               DENALI_CTL_64_DATA ,0b00000000000000000000000001100100 ##000000000000000_0 cke_status(RD) 000000_0001100100 axi5_priority_relax(RW) 
.equ               DENALI_CTL_65_DATA ,0b00000000000000000000000000000000 ##0000_0000 tdfi_phy_wrlat(RD) 00000000 dll_rst_adj_dly(RW) 0000000000000000 dll_rst_delay(RW) 
.equ               DENALI_CTL_66_DATA ,0b00000000000000000000011000000000 ##0000000_0 dram_clk_disable(RW) 0000_0000 tdfi_rddata_en(RD) 0000_0110 tdfi_phy_rdlat(RW_D) 0_0000000 update_error_status(RD) 
.equ               DENALI_CTL_67_DATA ,0b00000000000001001101100000000000 ##0000000000_00010011011000 tdfi_ctrlupd_max(RW) 0000_0000 tdfi_ctrlupd_min(RD) 
.equ               DENALI_CTL_68_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type1(RW) 0000001000000000 tdfi_phyupd_type0(RW) 
.equ               DENALI_CTL_69_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type3(RW) 0000001000000000 tdfi_phyupd_type2(RW) 
.equ               DENALI_CTL_70_DATA ,0b00000000000000000000010011011000 ##000000000000000000_00010011011000 tdfi_phyupd_resp(RW) 
.equ               DENALI_CTL_71_DATA ,0b00000000000000000001100000111000 ##00000000000000000001100000111000 tdfi_ctrlupd_interval(RW) 
.equ               DENALI_CTL_72_DATA ,0b00000000000000100000001100000100 ##00000_000 tdfi_dram_clk_disable(RW) 0000_0010 tdfi_ctrl_delay(RW_D) 0000_0011 wrlat_adj(RW) 0000_0100 rdlat_adj(RW) 
.equ               DENALI_CTL_73_DATA ,0b00000000000000000000000100000001 ##00000000000000000000000_1 odt_alt_en(RW) 0000_0001 tdfi_dram_clk_enable(RW) 

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = PHY
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 170
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 0
## ********************************************************************
## Memory: k4t51163qj_f8.xml
## ********************************************************************


.equ               DENALI_PHY_00_DATA, 0b00000000000100010001000100000000 ##00000000000100010001000100000000 phy_pad_ctrl_reg_0(RW) 
.equ               DENALI_PHY_01_DATA, 0b11110011000000010011101000100111 ##11110011000000010011101000100111 den_phy_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_02_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_03_DATA, 0b11110011000000010011101000100111 ##11110011000000010011101000100111 den_phy_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_04_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_05_DATA, 0b00000000000000000010101000000100 ##00000000000000000010101000000100 den_phy_ctrl_reg_2(RW) 
.equ               DENALI_PHY_06_DATA, 0b10100000000010000001111001100100 ##00100000000010000001111001100100 phy_dll_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_07_DATA, 0b00000001000010000001111100001110 ##00000001000010000001111100001110 phy_dll_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_08_DATA, 0b10100000000010000001111001100100 ##00100000000010000001111001100100 phy_dll_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_09_DATA, 0b00000001000010000001111100001110 ##00000001000010000001111100001110 phy_dll_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_10_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_0(RD) 
.equ               DENALI_PHY_11_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_0(RD) 
.equ               DENALI_PHY_12_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_0(RD) 
.equ               DENALI_PHY_13_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_1(RD) 
.equ               DENALI_PHY_14_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_1(RD) 
.equ               DENALI_PHY_15_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_1(RD) 
#else ##ddr_clk_160

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = CTL
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 250
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 1
## ********************************************************************
## Memory: k4t51163qj_f8.xml
## ********************************************************************


.equ               DENALI_CTL_00_DATA ,0b00000000000000000000010000000000 ##0000000000000000 version(RD) 0000_0100 dram_class(RW) 0000000_0 start(RW) 
.equ               DENALI_CTL_01_DATA ,0b00000000000000000000000000000000 ##000000000000000_0 max_cs_reg(RD) 0000_0000 max_col_reg(RD) 0000_0000 max_row_reg(RD) 
.equ               DENALI_CTL_02_DATA ,0b00000010000000000000000000110010 ##0000_0010 initaref(RW) 000000000000000000110010 tinit(RW) 
.equ               DENALI_CTL_03_DATA ,0b00000010000000100000001100001000 ##000_00010 tccd(RW) 00000_010 tbst_int_interval(RW) 0000_0011 wrlat(RW) 0000_1000 caslat_lin(RW) 
.equ               DENALI_CTL_04_DATA ,0b00000010000011000000111100000011 ##0000_0010 twtr(RW) 00001100 tras_min(RW) 00001111 trc(RW) 00000011 trrd(RW) 
.equ               DENALI_CTL_05_DATA ,0b00000011000000100000001000000100 ##00000011 tmod(RW) 000_00010 tmrd(RW) 00000_010 trtp(RW) 0000_0100 trp(RW) 
.equ               DENALI_CTL_06_DATA ,0b00000011000000110100010001011100 ##000_00011 tckesr(RW) 00000_011 tcke(RW) 0100010001011100 tras_max(RW) 
.equ               DENALI_CTL_07_DATA ,0b00000001000000010000000000000000 ##0000000_1 tras_lockout(RW) 0000000_1 concurrentap(RW) 0000000_0 ap(RW) 0000000_0 writeinterp(RW) 
.equ               DENALI_CTL_08_DATA ,0b00000000000010000000010000000100 ##00000000000_01000 tdal(RW) 000_00100 twr_int(RW) 00000100 trcd_int(RW) 
.equ               DENALI_CTL_09_DATA ,0b00000010000000000000000011001000 ##00000_010 bstlen(RW_D) 0000000_0 no_cmd_init(RW) 0000000011001000 tdll(RW) 
.equ               DENALI_CTL_10_DATA ,0b00000100000000000110010000001100 ##0000_0100 trp_ab(RW) 0000000001100100 tcpd(RW) 00_001100 tfaw(RW) 
.equ               DENALI_CTL_11_DATA ,0b00000001000000000000000000000000 ##0000000_1 tref_enable(RW) 0000000_0 auto_refresh_mode(RW) 0000000_0 arefresh(WR) 0000000_0 reg_dimm_enable(RW) 
.equ               DENALI_CTL_12_DATA ,0b00000111010010110000000000011011 ##00_00011101001011 tref(RW) 000000_0000011011 trfc(RW) 
.equ               DENALI_CTL_13_DATA ,0b00000000000000110000000000000000 ##0000000000000011 tpdex(RW) 0000000_0 power_down(RW) 00000000
.equ               DENALI_CTL_14_DATA ,0b00000000000111010000000011001000 ##0000000000011101 txsnr(RW) 0000000011001000 txsr(RW) 
.equ               DENALI_CTL_15_DATA ,0b00000001000000000000000000000000 ##0000000_1 enable_quick_srefresh(RW) 0000000_0 srefresh_exit_no_refresh(RW) 0000000_0 pwrup_srefresh_exit(RW) 0000000_0 srefresh(RW+) 
.equ               DENALI_CTL_16_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_power_down_cnt(RW) 000_00000 lowpower_control(RW) 00000_000 cke_delay(RW) 
.equ               DENALI_CTL_17_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_external_cnt(RW) 0000000000000000 lowpower_self_refresh_cnt(RW) 
.equ               DENALI_CTL_18_DATA ,0b00000000000000000000000000000000 ##0000000_0 lowpower_refresh_enable(RW) 0000000000000000 lowpower_internal_cnt(RW) 000_00000 lowpower_auto_enable(RW) 
.equ               DENALI_CTL_19_DATA ,0b00000000000000000000001100000011 ##00000000000000000000_0011 cksrx(RW) 0000_0011 cksre(RW) 
.equ               DENALI_CTL_20_DATA ,0b00000000000000000000000000000000 ##000000_00000000000000000000000000 write_modereg(RW+) 
.equ               DENALI_CTL_21_DATA ,0b00000000000001100100001000000000 ##0000000000_00011001000010 mr0_data_0(RW) 00000000 mrw_status(RD) 
.equ               DENALI_CTL_22_DATA ,0b00000000000000000000010001000010 ##00_00000000000000 mr2_data_0(RW) 00_00010001000000 mr1_data_0(RW) 
.equ               DENALI_CTL_23_DATA ,0b00000000000000000000000000000000 ##00_00000000000000 mr3_data_0(RW) 00_00000000000000 mrsingle_data_0(RW) 
.equ               DENALI_CTL_24_DATA ,0b00001010000000100000000100000000 ##0000_1010 aprebit(RW_D) 00000_010 column_size(RW) 00000_001 addr_pins(RW) 0000000_0 eight_bank_mode(RW) 
.equ               DENALI_CTL_25_DATA ,0b00000001000000010000101000001010 ##0000000_1 bank_split_en(RW) 0000000_1 addr_cmp_en(RW) 000_01010 command_age_count(RW) 000_01010 age_count(RW) 
.equ               DENALI_CTL_26_DATA ,0b00000001000000010000000100000001 ##0000000_1 swap_en(RW) 0000000_1 rw_same_en(RW) 0000000_1 priority_en(RW) 0000000_1 placement_en(RW) 
.equ               DENALI_CTL_27_DATA ,0b00000000000000000000000000000000 ##00000_000 q_fullness(RW) 0000000_0 fast_write(RW) 0000000_0 reduc(RW) 0000000_0 inhibit_dram_cmd(RW) 
.equ               DENALI_CTL_28_DATA ,0b00000000000000000000000100000000 ##0000_000000000000 int_status(RD) 0000000_1 resync_dll_per_aref_en(RW) 0000000_0 resync_dll(WR) 
.equ               DENALI_CTL_29_DATA ,0b00000000000000000000000000000000 ##0000_000000000000 int_mask(RW) 00000_00000000000 int_ack(WR) 
.equ               DENALI_CTL_30_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 out_of_range_addr(RD) 
.equ               DENALI_CTL_31_DATA ,0b00000000000000000000000000000000 ##000000000_0000000 out_of_range_source_id(RD) 00_000000 out_of_range_type(RD) 00_000000 out_of_range_length(RD) 
.equ               DENALI_CTL_32_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 port_cmd_error_addr(RD) 
.equ               DENALI_CTL_33_DATA ,0b00000000000000000000000000000000 ##00000_000 port_data_error_type(RD) 0_0000000 port_data_error_id(RD) 0000_0000 port_cmd_error_type(RD) 0_0000000 port_cmd_error_id(RD) 
.equ               DENALI_CTL_34_DATA ,0b00000001000000000000000000000000 ##00000_001 r2w_samecs_dly(RW) 00000_000 r2r_samecs_dly(RW) 0000_0000 add_odt_clk_w2r_samecs(RW) 0000_0000 add_odt_clk_r2w_samecs(RW) 
.equ               DENALI_CTL_35_DATA ,0b00000000000000000000000000000000 ##000_00000 ocd_adjust_pup_cs_0(RW) 000_00000 ocd_adjust_pdn_cs_0(RW) 00000_000 w2w_samecs_dly(RW) 00000_000 w2r_samecs_dly(RW) 
.equ               DENALI_CTL_36_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb1_rdlen(RW) 0000_1111 ahb1_wrlen(RW) 0000_1111 ahb0_rdlen(RW) 0000_1111 ahb0_wrlen(RW) 
.equ               DENALI_CTL_37_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb3_rdlen(RW) 0000_1111 ahb3_wrlen(RW) 0000_1111 ahb2_rdlen(RW) 0000_1111 ahb2_wrlen(RW) 
.equ               DENALI_CTL_38_DATA ,0b00000000000000010000111100001111 ##0000000000000001 axi0_en_size_lt_width_instr(RW) 0000_1111 ahb4_rdlen(RW) 0000_1111 ahb4_wrlen(RW) 
.equ               DENALI_CTL_39_DATA ,0b00000000000000110000001100000011 ##00000000000000_11 axi0_fifo_type_reg(RW) 00000_011 axi0_w_priority(RW) 00000_011 axi0_r_priority(RW) 
.equ               DENALI_CTL_40_DATA ,0b00000011000000110000000000000001 ##00000_011 axi1_w_priority(RW) 00000_011 axi1_r_priority(RW) 0000000000000001 axi1_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_41_DATA ,0b00000010000000000000000100000011 ##00000_010 axi2_r_priority(RW) 0000000000000001 axi2_en_size_lt_width_instr(RW) 000000_11 axi1_fifo_type_reg(RW) 
.equ               DENALI_CTL_42_DATA ,0b00000000000000010000001100000010 ##0000000000000001 axi3_en_size_lt_width_instr(RW) 000000_11 axi2_fifo_type_reg(RW) 00000_010 axi2_w_priority(RW) 
.equ               DENALI_CTL_43_DATA ,0b00000000000000110000001100000011 ##00000000000000_11 axi3_fifo_type_reg(RW) 00000_011 axi3_w_priority(RW) 00000_011 axi3_r_priority(RW) 
.equ               DENALI_CTL_44_DATA ,0b00000011000000110000000000000001 ##00000_011 axi4_w_priority(RW) 00000_011 axi4_r_priority(RW) 0000000000000001 axi4_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_45_DATA ,0b00000010000000000000000100000011 ##00000_010 axi5_r_priority(RW) 0000000000000001 axi5_en_size_lt_width_instr(RW) 000000_11 axi4_fifo_type_reg(RW) 
.equ               DENALI_CTL_46_DATA ,0b00000000000000000000001100000010 ##00000_000 weighted_round_robin_weight_sharing(RW) 0000000_0 weighted_round_robin_latency_control(RW) 000000_11 axi5_fifo_type_reg(RW) 00000_010 axi5_w_priority(RW) 
.equ               DENALI_CTL_47_DATA ,0b00000001000000010000000100000000 ##0000_0001 axi0_priority2_relative_priority(RW) 0000_0001 axi0_priority1_relative_priority(RW) 0000_0001 axi0_priority0_relative_priority(RW) 0000_0000 wrr_param_value_err(RD) 
.equ               DENALI_CTL_48_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi0_priority6_relative_priority(RW) 0000_0001 axi0_priority5_relative_priority(RW) 0000_0001 axi0_priority4_relative_priority(RW) 0000_0001 axi0_priority3_relative_priority(RW) 
.equ               DENALI_CTL_49_DATA ,0b00000000011001000000000000000001 ##000000_0001100100 axi0_priority_relax(RW) 00000_000 axi0_port_ordering(RW) 0000_0001 axi0_priority7_relative_priority(RW) 
.equ               DENALI_CTL_50_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority3_relative_priority(RW) 0000_0001 axi1_priority2_relative_priority(RW) 0000_0001 axi1_priority1_relative_priority(RW) 0000_0001 axi1_priority0_relative_priority(RW) 
.equ               DENALI_CTL_51_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority7_relative_priority(RW) 0000_0001 axi1_priority6_relative_priority(RW) 0000_0001 axi1_priority5_relative_priority(RW) 0000_0001 axi1_priority4_relative_priority(RW) 
.equ               DENALI_CTL_52_DATA ,0b00000001000000000110010000000001 ##0000_0001 axi2_priority0_relative_priority(RW) 000000_0001100100 axi1_priority_relax(RW) 00000_001 axi1_port_ordering(RW) 
.equ               DENALI_CTL_53_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi2_priority4_relative_priority(RW) 0000_0001 axi2_priority3_relative_priority(RW) 0000_0001 axi2_priority2_relative_priority(RW) 0000_0001 axi2_priority1_relative_priority(RW) 
.equ               DENALI_CTL_54_DATA ,0b00000010000000010000000100000001 ##00000_010 axi2_port_ordering(RW) 0000_0001 axi2_priority7_relative_priority(RW) 0000_0001 axi2_priority6_relative_priority(RW) 0000_0001 axi2_priority5_relative_priority(RW) 
.equ               DENALI_CTL_55_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi3_priority1_relative_priority(RW) 0000_0001 axi3_priority0_relative_priority(RW) 000000_0001100100 axi2_priority_relax(RW) 
.equ               DENALI_CTL_56_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi3_priority5_relative_priority(RW) 0000_0001 axi3_priority4_relative_priority(RW) 0000_0001 axi3_priority3_relative_priority(RW) 0000_0001 axi3_priority2_relative_priority(RW) 
.equ               DENALI_CTL_57_DATA ,0b00000000000000110000000100000001 ##0000000000000_011 axi3_port_ordering(RW) 0000_0001 axi3_priority7_relative_priority(RW) 0000_0001 axi3_priority6_relative_priority(RW) 
.equ               DENALI_CTL_58_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi4_priority1_relative_priority(RW) 0000_0001 axi4_priority0_relative_priority(RW) 000000_0001100100 axi3_priority_relax(RW) 
.equ               DENALI_CTL_59_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi4_priority5_relative_priority(RW) 0000_0001 axi4_priority4_relative_priority(RW) 0000_0001 axi4_priority3_relative_priority(RW) 0000_0001 axi4_priority2_relative_priority(RW) 
.equ               DENALI_CTL_60_DATA ,0b00000000000001000000000100000001 ##0000000000000_100 axi4_port_ordering(RW) 0000_0001 axi4_priority7_relative_priority(RW) 0000_0001 axi4_priority6_relative_priority(RW) 
.equ               DENALI_CTL_61_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi5_priority1_relative_priority(RW) 0000_0001 axi5_priority0_relative_priority(RW) 000000_0001100100 axi4_priority_relax(RW) 
.equ               DENALI_CTL_62_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi5_priority5_relative_priority(RW) 0000_0001 axi5_priority4_relative_priority(RW) 0000_0001 axi5_priority3_relative_priority(RW) 0000_0001 axi5_priority2_relative_priority(RW) 
.equ               DENALI_CTL_63_DATA ,0b00000000000001010000000100000001 ##0000000000000_101 axi5_port_ordering(RW) 0000_0001 axi5_priority7_relative_priority(RW) 0000_0001 axi5_priority6_relative_priority(RW) 
.equ               DENALI_CTL_64_DATA ,0b00000000000000000000000001100100 ##000000000000000_0 cke_status(RD) 000000_0001100100 axi5_priority_relax(RW) 
.equ               DENALI_CTL_65_DATA ,0b00000000000000000000000000000000 ##0000_0000 tdfi_phy_wrlat(RD) 00000000 dll_rst_adj_dly(RW) 0000000000000000 dll_rst_delay(RW) 
.equ               DENALI_CTL_66_DATA ,0b00000000000000000000011100000000 ##0000000_0 dram_clk_disable(RW) 0000_0000 tdfi_rddata_en(RD) 0000_0111 tdfi_phy_rdlat(RW_D) 0_0000000 update_error_status(RD) 
.equ               DENALI_CTL_67_DATA ,0b00000000000001110100101100000000 ##0000000000_00011101001011 tdfi_ctrlupd_max(RW) 0000_0000 tdfi_ctrlupd_min(RD) 
.equ               DENALI_CTL_68_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type1(RW) 0000001000000000 tdfi_phyupd_type0(RW) 
.equ               DENALI_CTL_69_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type3(RW) 0000001000000000 tdfi_phyupd_type2(RW) 
.equ               DENALI_CTL_70_DATA ,0b00000000000000000000011101001011 ##000000000000000000_00011101001011 tdfi_phyupd_resp(RW) 
.equ               DENALI_CTL_71_DATA ,0b00000000000000000010010001110111 ##00000000000000000010010001110111 tdfi_ctrlupd_interval(RW) 
.equ               DENALI_CTL_72_DATA ,0b00000000000000100000001100000100 ##00000_000 tdfi_dram_clk_disable(RW) 0000_0010 tdfi_ctrl_delay(RW_D) 0000_0011 wrlat_adj(RW) 0000_0100 rdlat_adj(RW) 
.equ               DENALI_CTL_73_DATA ,0b00000000000000000000000100000001 ##00000000000000000000000_1 odt_alt_en(RW) 0000_0001 tdfi_dram_clk_enable(RW) 

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = PHY
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 250
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 1
## ********************************************************************
## Memory: k4t51163qj_f8.xml
## ********************************************************************


.equ               DENALI_PHY_00_DATA, 0b00000000000100010001000100000000 ##00000000000100010001000100000000 phy_pad_ctrl_reg_0(RW) 
.equ               DENALI_PHY_01_DATA, 0b11110100000000010100101100110111 ##11110100000000010100101100110111 den_phy_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_02_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_03_DATA, 0b11110100000000010100101100110111 ##11110100000000010100101100110111 den_phy_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_04_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_05_DATA, 0b00000000000000000010101000000101 ##00000000000000000010101000000101 den_phy_ctrl_reg_2(RW) 
.equ               DENALI_PHY_06_DATA, 0b01100000000001010001111001000100 ##00100000000001010001111001000100 phy_dll_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_07_DATA, 0b00000001000001010001111100001001 ##00000001000001010001111100001001 phy_dll_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_08_DATA, 0b01100000000001010001111001000100 ##00100000000001010001111001000100 phy_dll_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_09_DATA, 0b00000001000001010001111100001001 ##00000001000001010001111100001001 phy_dll_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_10_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_0(RD) 
.equ               DENALI_PHY_11_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_0(RD) 
.equ               DENALI_PHY_12_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_0(RD) 
.equ               DENALI_PHY_13_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_1(RD) 
.equ               DENALI_PHY_14_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_1(RD) 
.equ               DENALI_PHY_15_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_1(RD) 
#endif ##ddr_clk_160
#else  ##k4t51163qj_f8
#ifdef ddr_clk_160

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = CTL
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 170
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 0
## ********************************************************************
## Memory: mt47h32m16_25e.xml
## ********************************************************************


.equ               DENALI_CTL_00_DATA ,0b00000000000000000000010000000000 ##0000000000000000 version(RD) 0000_0100 dram_class(RW) 0000000_0 start(RW) 
.equ               DENALI_CTL_01_DATA ,0b00000000000000000000000000000000 ##000000000000000_0 max_cs_reg(RD) 0000_0000 max_col_reg(RD) 0000_0000 max_row_reg(RD) 
.equ               DENALI_CTL_02_DATA ,0b00000010000000000000000000100010 ##0000_0010 initaref(RW) 000000000000000000100010 tinit(RW) 
.equ               DENALI_CTL_03_DATA ,0b00000010000000100000001100001000 ##000_00010 tccd(RW) 00000_010 tbst_int_interval(RW) 0000_0011 wrlat(RW) 0000_1000 caslat_lin(RW) 
.equ               DENALI_CTL_04_DATA ,0b00000010000010000000101000000010 ##0000_0010 twtr(RW) 00001000 tras_min(RW) 00001010 trc(RW) 00000010 trrd(RW) 
.equ               DENALI_CTL_05_DATA ,0b00000011000000100000001000000011 ##00000011 tmod(RW) 000_00010 tmrd(RW) 00000_010 trtp(RW) 0000_0011 trp(RW) 
.equ               DENALI_CTL_06_DATA ,0b00000011000000110010111001101101 ##000_00011 tckesr(RW) 00000_011 tcke(RW) 0010111001101101 tras_max(RW) 
.equ               DENALI_CTL_07_DATA ,0b00000001000000010000000000000000 ##0000000_1 tras_lockout(RW) 0000000_1 concurrentap(RW) 0000000_0 ap(RW) 0000000_0 writeinterp(RW) 
.equ               DENALI_CTL_08_DATA ,0b00000000000001100000001100000011 ##00000000000_00110 tdal(RW) 000_00011 twr_int(RW) 00000011 trcd_int(RW) 
.equ               DENALI_CTL_09_DATA ,0b00000010000000000000000011001000 ##00000_010 bstlen(RW_D) 0000000_0 no_cmd_init(RW) 0000000011001000 tdll(RW) 
.equ               DENALI_CTL_10_DATA ,0b00000011000000000100010000000000 ##0000_0011 trp_ab(RW) 0000000001000100 tcpd(RW) 00_000000 tfaw(RW) 
.equ               DENALI_CTL_11_DATA ,0b00000001000000000000000000000000 ##0000000_1 tref_enable(RW) 0000000_0 auto_refresh_mode(RW) 0000000_0 arefresh(WR) 0000000_0 reg_dimm_enable(RW) 
.equ               DENALI_CTL_12_DATA ,0b00000100110110000000000000010010 ##00_00010011011000 tref(RW) 000000_0000010010 trfc(RW) 
.equ               DENALI_CTL_13_DATA ,0b00000000000000100000000000000000 ##0000000000000010 tpdex(RW) 0000000_0 power_down(RW) 00000000
.equ               DENALI_CTL_14_DATA ,0b00000000000101000000000011001000 ##0000000000010100 txsnr(RW) 0000000011001000 txsr(RW) 
.equ               DENALI_CTL_15_DATA ,0b00000001000000000000000000000000 ##0000000_1 enable_quick_srefresh(RW) 0000000_0 srefresh_exit_no_refresh(RW) 0000000_0 pwrup_srefresh_exit(RW) 0000000_0 srefresh(RW+) 
.equ               DENALI_CTL_16_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_power_down_cnt(RW) 000_00000 lowpower_control(RW) 00000_000 cke_delay(RW) 
.equ               DENALI_CTL_17_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_external_cnt(RW) 0000000000000000 lowpower_self_refresh_cnt(RW) 
.equ               DENALI_CTL_18_DATA ,0b00000000000000000000000000000000 ##0000000_0 lowpower_refresh_enable(RW) 0000000000000000 lowpower_internal_cnt(RW) 000_00000 lowpower_auto_enable(RW) 
.equ               DENALI_CTL_19_DATA ,0b00000000000000000000001100000011 ##00000000000000000000_0011 cksrx(RW) 0000_0011 cksre(RW) 
.equ               DENALI_CTL_20_DATA ,0b00000000000000000000000000000000 ##000000_00000000000000000000000000 write_modereg(RW+) 
.equ               DENALI_CTL_21_DATA ,0b00000000000001000100001000000000 ##0000000000_00010001000010 mr0_data_0(RW) 00000000 mrw_status(RD) 
.equ               DENALI_CTL_22_DATA ,0b00000000000000000000010001000000 ##00_00000000000000 mr2_data_0(RW) 00_00010001000000 mr1_data_0(RW) 
.equ               DENALI_CTL_23_DATA ,0b00000000000000000000000000000000 ##00_00000000000000 mr3_data_0(RW) 00_00000000000000 mrsingle_data_0(RW) 
.equ               DENALI_CTL_24_DATA ,0b00001010000000100000000100000000 ##0000_1010 aprebit(RW_D) 00000_010 column_size(RW) 00000_001 addr_pins(RW) 0000000_0 eight_bank_mode(RW) 
.equ               DENALI_CTL_25_DATA ,0b00000001000000010000101000001010 ##0000000_1 bank_split_en(RW) 0000000_1 addr_cmp_en(RW) 000_01010 command_age_count(RW) 000_01010 age_count(RW) 
.equ               DENALI_CTL_26_DATA ,0b00000001000000010000000100000001 ##0000000_1 swap_en(RW) 0000000_1 rw_same_en(RW) 0000000_1 priority_en(RW) 0000000_1 placement_en(RW) 
.equ               DENALI_CTL_27_DATA ,0b00000000000000000000000000000000 ##00000_000 q_fullness(RW) 0000000_0 fast_write(RW) 0000000_0 reduc(RW) 0000000_0 inhibit_dram_cmd(RW) 
.equ               DENALI_CTL_28_DATA ,0b00000000000000000000000100000000 ##0000_000000000000 int_status(RD) 0000000_1 resync_dll_per_aref_en(RW) 0000000_0 resync_dll(WR) 
.equ               DENALI_CTL_29_DATA ,0b00000000000000000000000000000000 ##0000_000000000000 int_mask(RW) 00000_00000000000 int_ack(WR) 
.equ               DENALI_CTL_30_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 out_of_range_addr(RD) 
.equ               DENALI_CTL_31_DATA ,0b00000000000000000000000000000000 ##000000000_0000000 out_of_range_source_id(RD) 00_000000 out_of_range_type(RD) 00_000000 out_of_range_length(RD) 
.equ               DENALI_CTL_32_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 port_cmd_error_addr(RD) 
.equ               DENALI_CTL_33_DATA ,0b00000000000000000000000000000000 ##00000_000 port_data_error_type(RD) 0_0000000 port_data_error_id(RD) 0000_0000 port_cmd_error_type(RD) 0_0000000 port_cmd_error_id(RD) 
.equ               DENALI_CTL_34_DATA ,0b00000001000000000000000000000000 ##00000_001 r2w_samecs_dly(RW) 00000_000 r2r_samecs_dly(RW) 0000_0000 add_odt_clk_w2r_samecs(RW) 0000_0000 add_odt_clk_r2w_samecs(RW) 
.equ               DENALI_CTL_35_DATA ,0b00000000000000000000000000000000 ##000_00000 ocd_adjust_pup_cs_0(RW) 000_00000 ocd_adjust_pdn_cs_0(RW) 00000_000 w2w_samecs_dly(RW) 00000_000 w2r_samecs_dly(RW) 
.equ               DENALI_CTL_36_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb1_rdlen(RW) 0000_1111 ahb1_wrlen(RW) 0000_1111 ahb0_rdlen(RW) 0000_1111 ahb0_wrlen(RW) 
.equ               DENALI_CTL_37_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb3_rdlen(RW) 0000_1111 ahb3_wrlen(RW) 0000_1111 ahb2_rdlen(RW) 0000_1111 ahb2_wrlen(RW) 
.equ               DENALI_CTL_38_DATA ,0b00000000000000010000111100001111 ##0000000000000001 axi0_en_size_lt_width_instr(RW) 0000_1111 ahb4_rdlen(RW) 0000_1111 ahb4_wrlen(RW) 
.equ               DENALI_CTL_39_DATA ,0b00000000000000000000001100000011 ##00000000000000_00 axi0_fifo_type_reg(RW) 00000_011 axi0_w_priority(RW) 00000_011 axi0_r_priority(RW) 
.equ               DENALI_CTL_40_DATA ,0b00000011000000110000000000000001 ##00000_011 axi1_w_priority(RW) 00000_011 axi1_r_priority(RW) 0000000000000001 axi1_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_41_DATA ,0b00000010000000000000000100000000 ##00000_010 axi2_r_priority(RW) 0000000000000001 axi2_en_size_lt_width_instr(RW) 000000_00 axi1_fifo_type_reg(RW) 
.equ               DENALI_CTL_42_DATA ,0b00000000000000010000000000000010 ##0000000000000001 axi3_en_size_lt_width_instr(RW) 000000_00 axi2_fifo_type_reg(RW) 00000_010 axi2_w_priority(RW) 
.equ               DENALI_CTL_43_DATA ,0b00000000000000000000001100000011 ##00000000000000_00 axi3_fifo_type_reg(RW) 00000_011 axi3_w_priority(RW) 00000_011 axi3_r_priority(RW) 
.equ               DENALI_CTL_44_DATA ,0b00000011000000110000000000000001 ##00000_011 axi4_w_priority(RW) 00000_011 axi4_r_priority(RW) 0000000000000001 axi4_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_45_DATA ,0b00000010000000000000000100000000 ##00000_010 axi5_r_priority(RW) 0000000000000001 axi5_en_size_lt_width_instr(RW) 000000_00 axi4_fifo_type_reg(RW) 
.equ               DENALI_CTL_46_DATA ,0b00000000000000000000000000000010 ##00000_000 weighted_round_robin_weight_sharing(RW) 0000000_0 weighted_round_robin_latency_control(RW) 000000_00 axi5_fifo_type_reg(RW) 00000_010 axi5_w_priority(RW) 
.equ               DENALI_CTL_47_DATA ,0b00000001000000010000000100000000 ##0000_0001 axi0_priority2_relative_priority(RW) 0000_0001 axi0_priority1_relative_priority(RW) 0000_0001 axi0_priority0_relative_priority(RW) 0000_0000 wrr_param_value_err(RD) 
.equ               DENALI_CTL_48_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi0_priority6_relative_priority(RW) 0000_0001 axi0_priority5_relative_priority(RW) 0000_0001 axi0_priority4_relative_priority(RW) 0000_0001 axi0_priority3_relative_priority(RW) 
.equ               DENALI_CTL_49_DATA ,0b00000000011001000000000000000001 ##000000_0001100100 axi0_priority_relax(RW) 00000_000 axi0_port_ordering(RW) 0000_0001 axi0_priority7_relative_priority(RW) 
.equ               DENALI_CTL_50_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority3_relative_priority(RW) 0000_0001 axi1_priority2_relative_priority(RW) 0000_0001 axi1_priority1_relative_priority(RW) 0000_0001 axi1_priority0_relative_priority(RW) 
.equ               DENALI_CTL_51_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority7_relative_priority(RW) 0000_0001 axi1_priority6_relative_priority(RW) 0000_0001 axi1_priority5_relative_priority(RW) 0000_0001 axi1_priority4_relative_priority(RW) 
.equ               DENALI_CTL_52_DATA ,0b00000001000000000110010000000001 ##0000_0001 axi2_priority0_relative_priority(RW) 000000_0001100100 axi1_priority_relax(RW) 00000_001 axi1_port_ordering(RW) 
.equ               DENALI_CTL_53_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi2_priority4_relative_priority(RW) 0000_0001 axi2_priority3_relative_priority(RW) 0000_0001 axi2_priority2_relative_priority(RW) 0000_0001 axi2_priority1_relative_priority(RW) 
.equ               DENALI_CTL_54_DATA ,0b00000010000000010000000100000001 ##00000_010 axi2_port_ordering(RW) 0000_0001 axi2_priority7_relative_priority(RW) 0000_0001 axi2_priority6_relative_priority(RW) 0000_0001 axi2_priority5_relative_priority(RW) 
.equ               DENALI_CTL_55_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi3_priority1_relative_priority(RW) 0000_0001 axi3_priority0_relative_priority(RW) 000000_0001100100 axi2_priority_relax(RW) 
.equ               DENALI_CTL_56_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi3_priority5_relative_priority(RW) 0000_0001 axi3_priority4_relative_priority(RW) 0000_0001 axi3_priority3_relative_priority(RW) 0000_0001 axi3_priority2_relative_priority(RW) 
.equ               DENALI_CTL_57_DATA ,0b00000000000000110000000100000001 ##0000000000000_011 axi3_port_ordering(RW) 0000_0001 axi3_priority7_relative_priority(RW) 0000_0001 axi3_priority6_relative_priority(RW) 
.equ               DENALI_CTL_58_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi4_priority1_relative_priority(RW) 0000_0001 axi4_priority0_relative_priority(RW) 000000_0001100100 axi3_priority_relax(RW) 
.equ               DENALI_CTL_59_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi4_priority5_relative_priority(RW) 0000_0001 axi4_priority4_relative_priority(RW) 0000_0001 axi4_priority3_relative_priority(RW) 0000_0001 axi4_priority2_relative_priority(RW) 
.equ               DENALI_CTL_60_DATA ,0b00000000000001000000000100000001 ##0000000000000_100 axi4_port_ordering(RW) 0000_0001 axi4_priority7_relative_priority(RW) 0000_0001 axi4_priority6_relative_priority(RW) 
.equ               DENALI_CTL_61_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi5_priority1_relative_priority(RW) 0000_0001 axi5_priority0_relative_priority(RW) 000000_0001100100 axi4_priority_relax(RW) 
.equ               DENALI_CTL_62_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi5_priority5_relative_priority(RW) 0000_0001 axi5_priority4_relative_priority(RW) 0000_0001 axi5_priority3_relative_priority(RW) 0000_0001 axi5_priority2_relative_priority(RW) 
.equ               DENALI_CTL_63_DATA ,0b00000000000001010000000100000001 ##0000000000000_101 axi5_port_ordering(RW) 0000_0001 axi5_priority7_relative_priority(RW) 0000_0001 axi5_priority6_relative_priority(RW) 
.equ               DENALI_CTL_64_DATA ,0b00000000000000000000000001100100 ##000000000000000_0 cke_status(RD) 000000_0001100100 axi5_priority_relax(RW) 
.equ               DENALI_CTL_65_DATA ,0b00000000000000000000000000000000 ##0000_0000 tdfi_phy_wrlat(RD) 00000000 dll_rst_adj_dly(RW) 0000000000000000 dll_rst_delay(RW) 
.equ               DENALI_CTL_66_DATA ,0b00000000000000000000011000000000 ##0000000_0 dram_clk_disable(RW) 0000_0000 tdfi_rddata_en(RD) 0000_0110 tdfi_phy_rdlat(RW_D) 0_0000000 update_error_status(RD) 
.equ               DENALI_CTL_67_DATA ,0b00000000000001001101100000000000 ##0000000000_00010011011000 tdfi_ctrlupd_max(RW) 0000_0000 tdfi_ctrlupd_min(RD) 
.equ               DENALI_CTL_68_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type1(RW) 0000001000000000 tdfi_phyupd_type0(RW) 
.equ               DENALI_CTL_69_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type3(RW) 0000001000000000 tdfi_phyupd_type2(RW) 
.equ               DENALI_CTL_70_DATA ,0b00000000000000000000010011011000 ##000000000000000000_00010011011000 tdfi_phyupd_resp(RW) 
.equ               DENALI_CTL_71_DATA ,0b00000000000000000001100000111000 ##00000000000000000001100000111000 tdfi_ctrlupd_interval(RW) 
.equ               DENALI_CTL_72_DATA ,0b00000000000000100000001100000100 ##00000_000 tdfi_dram_clk_disable(RW) 0000_0010 tdfi_ctrl_delay(RW_D) 0000_0011 wrlat_adj(RW) 0000_0100 rdlat_adj(RW) 
.equ               DENALI_CTL_73_DATA ,0b00000000000000000000000100000001 ##00000000000000000000000_1 odt_alt_en(RW) 0000_0001 tdfi_dram_clk_enable(RW) 

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = PHY
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 170
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 0
## ********************************************************************
## Memory: mt47h32m16_25e.xml
## ********************************************************************


.equ               DENALI_PHY_00_DATA, 0b00000000000100010001000100000000 ##00000000000100010001000100000000 phy_pad_ctrl_reg_0(RW) 
.equ               DENALI_PHY_01_DATA, 0b11110011000000010011101000100111 ##11110011000000010011101000100111 den_phy_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_02_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_03_DATA, 0b11110011000000010011101000100111 ##11110011000000010011101000100111 den_phy_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_04_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_05_DATA, 0b00000000000000000010101000000100 ##00000000000000000010101000000100 den_phy_ctrl_reg_2(RW) 
.equ               DENALI_PHY_06_DATA, 0b00100000000010000001111001100100 ##00100000000010000001111001100100 phy_dll_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_07_DATA, 0b00000001000010000001111100001110 ##00000001000010000001111100001110 phy_dll_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_08_DATA, 0b00100000000010000001111001100100 ##00100000000010000001111001100100 phy_dll_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_09_DATA, 0b00000001000010000001111100001110 ##00000001000010000001111100001110 phy_dll_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_10_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_0(RD) 
.equ               DENALI_PHY_11_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_0(RD) 
.equ               DENALI_PHY_12_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_0(RD) 
.equ               DENALI_PHY_13_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_1(RD) 
.equ               DENALI_PHY_14_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_1(RD) 
.equ               DENALI_PHY_15_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_1(RD) 
#else ##ddr_clk_160

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = CTL
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 250
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 1
## ********************************************************************
## Memory: mt47h32m16_25e.xml
## ********************************************************************


.equ               DENALI_CTL_00_DATA ,0b00000000000000000000010000000000 ##0000000000000000 version(RD) 0000_0100 dram_class(RW) 0000000_0 start(RW) 
.equ               DENALI_CTL_01_DATA ,0b00000000000000000000000000000000 ##000000000000000_0 max_cs_reg(RD) 0000_0000 max_col_reg(RD) 0000_0000 max_row_reg(RD) 
.equ               DENALI_CTL_02_DATA ,0b00000010000000000000000000110010 ##0000_0010 initaref(RW) 000000000000000000110010 tinit(RW) 
.equ               DENALI_CTL_03_DATA ,0b00000010000000100000001100001000 ##000_00010 tccd(RW) 00000_010 tbst_int_interval(RW) 0000_0011 wrlat(RW) 0000_1000 caslat_lin(RW) 
.equ               DENALI_CTL_04_DATA ,0b00000010000011000000111000000011 ##0000_0010 twtr(RW) 00001100 tras_min(RW) 00001110 trc(RW) 00000011 trrd(RW) 
.equ               DENALI_CTL_05_DATA ,0b00000011000000100000001000000100 ##00000011 tmod(RW) 000_00010 tmrd(RW) 00000_010 trtp(RW) 0000_0100 trp(RW) 
.equ               DENALI_CTL_06_DATA ,0b00000011000000110100010001011100 ##000_00011 tckesr(RW) 00000_011 tcke(RW) 0100010001011100 tras_max(RW) 
.equ               DENALI_CTL_07_DATA ,0b00000001000000010000000000000000 ##0000000_1 tras_lockout(RW) 0000000_1 concurrentap(RW) 0000000_0 ap(RW) 0000000_0 writeinterp(RW) 
.equ               DENALI_CTL_08_DATA ,0b00000000000010000000010000000100 ##00000000000_01000 tdal(RW) 000_00100 twr_int(RW) 00000100 trcd_int(RW) 
.equ               DENALI_CTL_09_DATA ,0b00000010000000000000000011001000 ##00000_010 bstlen(RW_D) 0000000_0 no_cmd_init(RW) 0000000011001000 tdll(RW) 
.equ               DENALI_CTL_10_DATA ,0b00000100000000000110010000000000 ##0000_0100 trp_ab(RW) 0000000001100100 tcpd(RW) 00_000000 tfaw(RW) 
.equ               DENALI_CTL_11_DATA ,0b00000001000000000000000000000000 ##0000000_1 tref_enable(RW) 0000000_0 auto_refresh_mode(RW) 0000000_0 arefresh(WR) 0000000_0 reg_dimm_enable(RW) 
.equ               DENALI_CTL_12_DATA ,0b00000111010010110000000000011011 ##00_00011101001011 tref(RW) 000000_0000011011 trfc(RW) 
.equ               DENALI_CTL_13_DATA ,0b00000000000000100000000000000000 ##0000000000000010 tpdex(RW) 0000000_0 power_down(RW) 00000000
.equ               DENALI_CTL_14_DATA ,0b00000000000111010000000011001000 ##0000000000011101 txsnr(RW) 0000000011001000 txsr(RW) 
.equ               DENALI_CTL_15_DATA ,0b00000001000000000000000000000000 ##0000000_1 enable_quick_srefresh(RW) 0000000_0 srefresh_exit_no_refresh(RW) 0000000_0 pwrup_srefresh_exit(RW) 0000000_0 srefresh(RW+) 
.equ               DENALI_CTL_16_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_power_down_cnt(RW) 000_00000 lowpower_control(RW) 00000_000 cke_delay(RW) 
.equ               DENALI_CTL_17_DATA ,0b00000000000000000000000000000000 ##0000000000000000 lowpower_external_cnt(RW) 0000000000000000 lowpower_self_refresh_cnt(RW) 
.equ               DENALI_CTL_18_DATA ,0b00000000000000000000000000000000 ##0000000_0 lowpower_refresh_enable(RW) 0000000000000000 lowpower_internal_cnt(RW) 000_00000 lowpower_auto_enable(RW) 
.equ               DENALI_CTL_19_DATA ,0b00000000000000000000001100000011 ##00000000000000000000_0011 cksrx(RW) 0000_0011 cksre(RW) 
.equ               DENALI_CTL_20_DATA ,0b00000000000000000000000000000000 ##000000_00000000000000000000000000 write_modereg(RW+) 
.equ               DENALI_CTL_21_DATA ,0b00000000000001100100001000000000 ##0000000000_00011001000010 mr0_data_0(RW) 00000000 mrw_status(RD) 
.equ               DENALI_CTL_22_DATA ,0b00000000000000000000010001000000 ##00_00000000000000 mr2_data_0(RW) 00_00010001000000 mr1_data_0(RW) 
.equ               DENALI_CTL_23_DATA ,0b00000000000000000000000000000000 ##00_00000000000000 mr3_data_0(RW) 00_00000000000000 mrsingle_data_0(RW) 
.equ               DENALI_CTL_24_DATA ,0b00001010000000100000000100000000 ##0000_1010 aprebit(RW_D) 00000_010 column_size(RW) 00000_001 addr_pins(RW) 0000000_0 eight_bank_mode(RW) 
.equ               DENALI_CTL_25_DATA ,0b00000001000000010000101000001010 ##0000000_1 bank_split_en(RW) 0000000_1 addr_cmp_en(RW) 000_01010 command_age_count(RW) 000_01010 age_count(RW) 
.equ               DENALI_CTL_26_DATA ,0b00000001000000010000000100000001 ##0000000_1 swap_en(RW) 0000000_1 rw_same_en(RW) 0000000_1 priority_en(RW) 0000000_1 placement_en(RW) 
.equ               DENALI_CTL_27_DATA ,0b00000000000000000000000000000000 ##00000_000 q_fullness(RW) 0000000_0 fast_write(RW) 0000000_0 reduc(RW) 0000000_0 inhibit_dram_cmd(RW) 
.equ               DENALI_CTL_28_DATA ,0b00000000000000000000000100000000 ##0000_000000000000 int_status(RD) 0000000_1 resync_dll_per_aref_en(RW) 0000000_0 resync_dll(WR) 
.equ               DENALI_CTL_29_DATA ,0b00000000000000000000000000000000 ##0000_000000000000 int_mask(RW) 00000_00000000000 int_ack(WR) 
.equ               DENALI_CTL_30_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 out_of_range_addr(RD) 
.equ               DENALI_CTL_31_DATA ,0b00000000000000000000000000000000 ##000000000_0000000 out_of_range_source_id(RD) 00_000000 out_of_range_type(RD) 00_000000 out_of_range_length(RD) 
.equ               DENALI_CTL_32_DATA ,0b00000000000000000000000000000000 ##00_000000000000000000000000000000 port_cmd_error_addr(RD) 
.equ               DENALI_CTL_33_DATA ,0b00000000000000000000000000000000 ##00000_000 port_data_error_type(RD) 0_0000000 port_data_error_id(RD) 0000_0000 port_cmd_error_type(RD) 0_0000000 port_cmd_error_id(RD) 
.equ               DENALI_CTL_34_DATA ,0b00000001000000000000000000000000 ##00000_001 r2w_samecs_dly(RW) 00000_000 r2r_samecs_dly(RW) 0000_0000 add_odt_clk_w2r_samecs(RW) 0000_0000 add_odt_clk_r2w_samecs(RW) 
.equ               DENALI_CTL_35_DATA ,0b00000000000000000000000000000000 ##000_00000 ocd_adjust_pup_cs_0(RW) 000_00000 ocd_adjust_pdn_cs_0(RW) 00000_000 w2w_samecs_dly(RW) 00000_000 w2r_samecs_dly(RW) 
.equ               DENALI_CTL_36_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb1_rdlen(RW) 0000_1111 ahb1_wrlen(RW) 0000_1111 ahb0_rdlen(RW) 0000_1111 ahb0_wrlen(RW) 
.equ               DENALI_CTL_37_DATA ,0b00001111000011110000111100001111 ##0000_1111 ahb3_rdlen(RW) 0000_1111 ahb3_wrlen(RW) 0000_1111 ahb2_rdlen(RW) 0000_1111 ahb2_wrlen(RW) 
.equ               DENALI_CTL_38_DATA ,0b00000000000000010000111100001111 ##0000000000000001 axi0_en_size_lt_width_instr(RW) 0000_1111 ahb4_rdlen(RW) 0000_1111 ahb4_wrlen(RW) 
.equ               DENALI_CTL_39_DATA ,0b00000000000000110000001100000011 ##00000000000000_11 axi0_fifo_type_reg(RW) 00000_011 axi0_w_priority(RW) 00000_011 axi0_r_priority(RW) 
.equ               DENALI_CTL_40_DATA ,0b00000011000000110000000000000001 ##00000_011 axi1_w_priority(RW) 00000_011 axi1_r_priority(RW) 0000000000000001 axi1_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_41_DATA ,0b00000010000000000000000100000011 ##00000_010 axi2_r_priority(RW) 0000000000000001 axi2_en_size_lt_width_instr(RW) 000000_11 axi1_fifo_type_reg(RW) 
.equ               DENALI_CTL_42_DATA ,0b00000000000000010000001100000010 ##0000000000000001 axi3_en_size_lt_width_instr(RW) 000000_11 axi2_fifo_type_reg(RW) 00000_010 axi2_w_priority(RW) 
.equ               DENALI_CTL_43_DATA ,0b00000000000000110000001100000011 ##00000000000000_11 axi3_fifo_type_reg(RW) 00000_011 axi3_w_priority(RW) 00000_011 axi3_r_priority(RW) 
.equ               DENALI_CTL_44_DATA ,0b00000011000000110000000000000001 ##00000_011 axi4_w_priority(RW) 00000_011 axi4_r_priority(RW) 0000000000000001 axi4_en_size_lt_width_instr(RW) 
.equ               DENALI_CTL_45_DATA ,0b00000010000000000000000100000011 ##00000_010 axi5_r_priority(RW) 0000000000000001 axi5_en_size_lt_width_instr(RW) 000000_11 axi4_fifo_type_reg(RW) 
.equ               DENALI_CTL_46_DATA ,0b00000000000000000000001100000010 ##00000_000 weighted_round_robin_weight_sharing(RW) 0000000_0 weighted_round_robin_latency_control(RW) 000000_11 axi5_fifo_type_reg(RW) 00000_010 axi5_w_priority(RW) 
.equ               DENALI_CTL_47_DATA ,0b00000001000000010000000100000000 ##0000_0001 axi0_priority2_relative_priority(RW) 0000_0001 axi0_priority1_relative_priority(RW) 0000_0001 axi0_priority0_relative_priority(RW) 0000_0000 wrr_param_value_err(RD) 
.equ               DENALI_CTL_48_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi0_priority6_relative_priority(RW) 0000_0001 axi0_priority5_relative_priority(RW) 0000_0001 axi0_priority4_relative_priority(RW) 0000_0001 axi0_priority3_relative_priority(RW) 
.equ               DENALI_CTL_49_DATA ,0b00000000011001000000000000000001 ##000000_0001100100 axi0_priority_relax(RW) 00000_000 axi0_port_ordering(RW) 0000_0001 axi0_priority7_relative_priority(RW) 
.equ               DENALI_CTL_50_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority3_relative_priority(RW) 0000_0001 axi1_priority2_relative_priority(RW) 0000_0001 axi1_priority1_relative_priority(RW) 0000_0001 axi1_priority0_relative_priority(RW) 
.equ               DENALI_CTL_51_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi1_priority7_relative_priority(RW) 0000_0001 axi1_priority6_relative_priority(RW) 0000_0001 axi1_priority5_relative_priority(RW) 0000_0001 axi1_priority4_relative_priority(RW) 
.equ               DENALI_CTL_52_DATA ,0b00000001000000000110010000000001 ##0000_0001 axi2_priority0_relative_priority(RW) 000000_0001100100 axi1_priority_relax(RW) 00000_001 axi1_port_ordering(RW) 
.equ               DENALI_CTL_53_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi2_priority4_relative_priority(RW) 0000_0001 axi2_priority3_relative_priority(RW) 0000_0001 axi2_priority2_relative_priority(RW) 0000_0001 axi2_priority1_relative_priority(RW) 
.equ               DENALI_CTL_54_DATA ,0b00000010000000010000000100000001 ##00000_010 axi2_port_ordering(RW) 0000_0001 axi2_priority7_relative_priority(RW) 0000_0001 axi2_priority6_relative_priority(RW) 0000_0001 axi2_priority5_relative_priority(RW) 
.equ               DENALI_CTL_55_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi3_priority1_relative_priority(RW) 0000_0001 axi3_priority0_relative_priority(RW) 000000_0001100100 axi2_priority_relax(RW) 
.equ               DENALI_CTL_56_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi3_priority5_relative_priority(RW) 0000_0001 axi3_priority4_relative_priority(RW) 0000_0001 axi3_priority3_relative_priority(RW) 0000_0001 axi3_priority2_relative_priority(RW) 
.equ               DENALI_CTL_57_DATA ,0b00000000000000110000000100000001 ##0000000000000_011 axi3_port_ordering(RW) 0000_0001 axi3_priority7_relative_priority(RW) 0000_0001 axi3_priority6_relative_priority(RW) 
.equ               DENALI_CTL_58_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi4_priority1_relative_priority(RW) 0000_0001 axi4_priority0_relative_priority(RW) 000000_0001100100 axi3_priority_relax(RW) 
.equ               DENALI_CTL_59_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi4_priority5_relative_priority(RW) 0000_0001 axi4_priority4_relative_priority(RW) 0000_0001 axi4_priority3_relative_priority(RW) 0000_0001 axi4_priority2_relative_priority(RW) 
.equ               DENALI_CTL_60_DATA ,0b00000000000001000000000100000001 ##0000000000000_100 axi4_port_ordering(RW) 0000_0001 axi4_priority7_relative_priority(RW) 0000_0001 axi4_priority6_relative_priority(RW) 
.equ               DENALI_CTL_61_DATA ,0b00000001000000010000000001100100 ##0000_0001 axi5_priority1_relative_priority(RW) 0000_0001 axi5_priority0_relative_priority(RW) 000000_0001100100 axi4_priority_relax(RW) 
.equ               DENALI_CTL_62_DATA ,0b00000001000000010000000100000001 ##0000_0001 axi5_priority5_relative_priority(RW) 0000_0001 axi5_priority4_relative_priority(RW) 0000_0001 axi5_priority3_relative_priority(RW) 0000_0001 axi5_priority2_relative_priority(RW) 
.equ               DENALI_CTL_63_DATA ,0b00000000000001010000000100000001 ##0000000000000_101 axi5_port_ordering(RW) 0000_0001 axi5_priority7_relative_priority(RW) 0000_0001 axi5_priority6_relative_priority(RW) 
.equ               DENALI_CTL_64_DATA ,0b00000000000000000000000001100100 ##000000000000000_0 cke_status(RD) 000000_0001100100 axi5_priority_relax(RW) 
.equ               DENALI_CTL_65_DATA ,0b00000000000000000000000000000000 ##0000_0000 tdfi_phy_wrlat(RD) 00000000 dll_rst_adj_dly(RW) 0000000000000000 dll_rst_delay(RW) 
.equ               DENALI_CTL_66_DATA ,0b00000000000000000000011100000000 ##0000000_0 dram_clk_disable(RW) 0000_0000 tdfi_rddata_en(RD) 0000_0111 tdfi_phy_rdlat(RW_D) 0_0000000 update_error_status(RD) 
.equ               DENALI_CTL_67_DATA ,0b00000000000001110100101100000000 ##0000000000_00011101001011 tdfi_ctrlupd_max(RW) 0000_0000 tdfi_ctrlupd_min(RD) 
.equ               DENALI_CTL_68_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type1(RW) 0000001000000000 tdfi_phyupd_type0(RW) 
.equ               DENALI_CTL_69_DATA ,0b00000010000000000000001000000000 ##0000001000000000 tdfi_phyupd_type3(RW) 0000001000000000 tdfi_phyupd_type2(RW) 
.equ               DENALI_CTL_70_DATA ,0b00000000000000000000011101001011 ##000000000000000000_00011101001011 tdfi_phyupd_resp(RW) 
.equ               DENALI_CTL_71_DATA ,0b00000000000000000010010001110111 ##00000000000000000010010001110111 tdfi_ctrlupd_interval(RW) 
.equ               DENALI_CTL_72_DATA ,0b00000000000000100000001100000100 ##00000_000 tdfi_dram_clk_disable(RW) 0000_0010 tdfi_ctrl_delay(RW_D) 0000_0011 wrlat_adj(RW) 0000_0100 rdlat_adj(RW) 
.equ               DENALI_CTL_73_DATA ,0b00000000000000000000000100000001 ##00000000000000000000000_1 odt_alt_en(RW) 0000_0001 tdfi_dram_clk_enable(RW) 

/******************************************************************
 * COPYRIGHT (c) 2000 Denali Software, Inc.  All rights reserved. *
 * -------------------------------------------------------------- *
 * This code is proprietary and confidential information of       *
 * Denali Software. It may not be reproduced, used or transmitted *
 * in any form whatsoever without the express and written         *
 * permission of Denali Software.                                 *
 ******************************************************************
 ******************************************************************
 *                                                                 
 *   Module:         regconfig.h
 *   Documentation:  Register programming header file
 *
 ******************************************************************
 ******************************************************************/

/*****************************************************************
 * WARNING:  This file was automatically generated.  Manual
 * editing may result in undetermined behavior, and may be in
 * violation of the Denali Support Agreement.
 *****************************************************************/



## ********************************************************************
## Option: IP Mode                      = PHY
## Option: Burst Length                  = 4
## Option: CAS Latency                   = 4
## Option: Simulation MHz                = 250
## Option: Auto Precharge Mode     (0/1) = 0
## Option: DLL Bypass Mode         (0/1) = 0
## Option: Half-Memory Support     (0/1) = 0
## Option: Registered Dimm Support (0/1) = 0
## Option: SYNCRONIOUS 0/1 = 1
## ********************************************************************
## Memory: mt47h32m16_25e.xml
## ********************************************************************


.equ               DENALI_PHY_00_DATA, 0b00000000000100010001000100000000 ##00000000000100010001000100000000 phy_pad_ctrl_reg_0(RW) 
.equ               DENALI_PHY_01_DATA, 0b11110100000000010100101100110111 ##11110100000000010100101100110111 den_phy_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_02_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_03_DATA, 0b11110100000000010100101100110111 ##11110100000000010100101100110111 den_phy_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_04_DATA, 0b00100100110000000000001011000000 ##00100100110000000000001011000000 den_phy_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_05_DATA, 0b00000000000000000010101000000101 ##00000000000000000010101000000101 den_phy_ctrl_reg_2(RW) 
.equ               DENALI_PHY_06_DATA, 0b00100000000001010001110101000100 ##00100000000001010001110101000100 phy_dll_ctrl_reg_0_0(RW) 
.equ               DENALI_PHY_07_DATA, 0b00000001000001010001111100001001 ##00000001000001010001111100001001 phy_dll_ctrl_reg_1_0(RW) 
.equ               DENALI_PHY_08_DATA, 0b00100000000001010001110101000100 ##00100000000001010001110101000100 phy_dll_ctrl_reg_0_1(RW) 
.equ               DENALI_PHY_09_DATA, 0b00000001000001010001111100001001 ##00000001000001010001111100001001 phy_dll_ctrl_reg_1_1(RW) 
.equ               DENALI_PHY_10_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_0(RD) 
.equ               DENALI_PHY_11_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_0(RD) 
.equ               DENALI_PHY_12_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_0(RD) 
.equ               DENALI_PHY_13_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 den_phy_obs_reg_0_1(RD) 
.equ               DENALI_PHY_14_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_0_1(RD) 
.equ               DENALI_PHY_15_DATA, 0b00000000000000000000000000000000 ##00000000000000000000000000000000 phy_dll_obs_reg_1_1(RD) 
#endif ##ddr_clk_160
#endif ##k4t51163qj_f8
#endif ##mt47h64m8_25e
