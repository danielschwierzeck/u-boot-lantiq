
  /* load all modelled registers names... */
  .equ    gmac_15_intr_mask_reg         , 0x003c  
  .equ    gmac_07_intr_en_reg           , 0x101c  
  .equ    gmac_06_op_mode_reg           , 0x1018  
  .equ    gmac_00_config_reg            , 0x0000  
  .equ    gmac_03_rx_desc_list_addr_reg , 0x100c  
  .equ    gmac_04_tx_desc_list_addr_reg , 0x1010  
  .equ    gmac_01_tx_poll_demand_reg    , 0x1004
  .equ    gmac_02_rx_poll_demand_reg    , 0x1008
  .equ    gmac_01_mac_frame_filter_reg  , 0x0004
  .equ    gmac_14_intr_status_reg       , 0x0038
  .equ    gmac_54_srgmii_status_reg     , 0x00d8
  .equ    gmac_05_dma_status_reg        , 0x1014
  .equ    gmac_00_bus_mode_reg          , 0x1000

  .equ    pci_csr_00_reg                , 0x0000
  .equ    pci_csr_01_crp_wr_dat_reg     , 0x0004
  .equ    pci_csr_02_crp_rd_dat_reg     , 0x0008
  .equ    pci_csr_03_pci_cfgio_addr_reg , 0x000c
  .equ    pci_csr_04_reg                , 0x0010
  .equ    pci_csr_05_cfgio_wr_dat_reg   , 0x0014
  .equ    pci_csr_06_cfgio_rd_dat_reg   , 0x0018

  .equ    dmac_ctrl_reg                 , 0x0040  
  .equ    dmac_proc_a_int_status_reg    , 0x0000
  .equ    dmac_proc_a_raw_int_status_reg, 0x0001 
  .equ    dmac_proc_a_int_mask_reg      , 0x0002
  .equ    dmac_proc_a_int_clr_reg       , 0x0003   
  .equ    dmac_proc_b_int_status_reg    , 0x0010
  .equ    dmac_proc_b_raw_int_status_reg, 0x0011 
  .equ    dmac_proc_b_int_mask_reg      , 0x0012
  .equ    dmac_proc_b_int_clr_reg       , 0x0013    
  .equ    dmac_ch0_ctrl_reg             , 0x0020
  .equ    dmac_ch0_config_reg           , 0x0021
  .equ    dmac_ch0_src_type_reg         , 0x0022  
  .equ    dmac_ch0_src_addr_reg         , 0x0023  
  .equ    dmac_ch0_src_descrpt_reg      , 0x0024
  .equ    dmac_ch0_src_ll_strt_ptr_reg  , 0x0025
  .equ    dmac_ch0_src_ll_buf_addr_reg  , 0x0026
  .equ    dmac_ch0_src_ll_nxt_descrpt_reg , 0x0027
  .equ    dmac_ch0_src_ll_ctrl_reg      , 0x0028
  .equ    dmac_ch0_dest_type_reg        , 0x0029
  .equ    dmac_ch0_dest_addr_reg        , 0x002a  
  .equ    dmac_ch0_dest_descript_reg    , 0x002b
  .equ    dmac_ch0_dest_ll_strt_ptr_reg , 0x002c
  .equ    dmac_ch0_dest_ll_buf_addr_reg , 0x002d
  .equ    dmac_ch0_dest_ll_nxt_descrpt_reg , 0x002e
  .equ    dmac_ch0_dest_ll_ctrl_reg     , 0x002f

  .equ    gen3_shrd_basic_mode_config_reg , 0x0000
  .equ    gen3_shrd_safety_reg          , 0x0074
  .equ    gen3_shrd_clock_enable_reg    , 0x000c
  .equ    gen3_shrd_soft_reset_reg      , 0x0008
