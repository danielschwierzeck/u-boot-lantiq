		
	/* System interface register map */
   .equ  gclk_addr        ,   0x00 << 2
   .equ  sw_rst_addr      ,   0x01 << 2
   .equ  spare_addr       ,   0x02 << 2

 	.equ	wr_addr,          	0x00000003<<2
	.equ	rd_addr,          	0x00000004<<2
	.equ	divr_addr,        	0x00000005<<2
	.equ	fwl_addr,         	0x00000006<<2
	.equ	int_reg_addr,     	0x00000007<<2
	.equ	cont_addr,        	0x00000008<<2
	.equ	noise_cnt_addr,   	0x00000009<<2
	.equ	idle_max_addr,    	0x0000000a<<2
	.equ	count_fif_addr,   	0x0000000b<<2
	.equ	int_mode_addr,    	0x0000000c<<2
	
	.equ	pll_mul_addr,     	0x00000010<<2
	.equ	pll_div_addr,     	0x00000011<<2
	.equ	pll_ctrl_addr,    	0x00000012<<2
	.equ	sys_clk_divr_a,		0x00000013<<2
	.equ	sys_clk_sw_add,		0x00000014<<2
	.equ	wakeup_tmr_cnt,		0x00000015<<2
	.equ	wakeup_tmr_ena,		0x00000016<<2

	.equ	sys_info_addr,    	0x00000018<<2
	.equ	sys_cfg_addr,     	0x00000019<<2
	.equ	secure_wr_addr,   	0x0000001a<<2
	.equ	rst_ex_cpu_add,   	0x0000001b<<2

	.equ	gpio_oen_addr,    	0x00000020<<2
	.equ	gpio_dat_addr,    	0x00000021<<2
	.equ	gpio_stb_len_a,		0x00000022<<2
	
	.equ	mspi_cfg_addr,    	0x00000030<<2
	.equ	mspi_wdat_addr,   	0x00000031<<2
	.equ	mspi_rdat_addr,   	0x00000032<<2

	.equ	boot_sw_ctr_addr, 	0x00000040<<2
	.equ	int_sw_ctr_addr,  	0x00000041<<2
	.equ	swdog_mask_addr,  	0x00000042<<2
	.equ	sw_ctr_addr,      	0x00000043<<2
	.equ	sw_rst_cnt_addr,  	0x00000044<<2

   .equ    spi_write_addr   , 0x48 << 2
   .equ    spi_read_addr    , 0x49 << 2

 	.equ	irq_mask_addr,    	0x00000050<<2
	.equ	irq_sec_rf_addr,  	0x00000051<<2  
	.equ	irq_map_00_addr,  	0x00000052<<2
	.equ	irq_map_01_addr,  	0x00000053<<2
	.equ	irq_map_02_addr,  	0x00000054<<2
	.equ	irq_map_03_addr,  	0x00000055<<2
	.equ	irq_map_04_addr,  	0x00000056<<2
	.equ	irq_map_05_addr,  	0x00000057<<2
	.equ	irq_mapped_addr,  	0x00000058<<2
	.equ	irq_status_addr,  	0x00000059<<2
	.equ	irq_inter_cpu_ad, 	0x0000005a<<2
	.equ	irq_to_host_addr, 	0x0000005b<<2

	.equ	t0_max_cnt_addr,  	0x060<<2
	.equ	t1_max_cnt_addr,  	0x061<<2
	.equ	t2_max_cnt_addr,  	0x00000062<<2
	.equ	t3_max_cnt_addr,  	0x00000063<<2
	.equ	t0_ctr_addr,      	0x00000064<<2
	.equ	t1_ctr_addr,      	0x00000065<<2
	.equ	t2_ctr_addr,      	0x00000066<<2
	.equ	t3_ctr_addr,      	0x00000067<<2
	.equ	timers_status,    	0x00000068<<2
	.equ	timers_cfg_addr,  	0x00000069<<2	  
   .equ  t2_prescaler_add,    0x0000006a<<2
   .equ  t3_prescaler_add,    0x0000006b<<2

	.equ	ic_hit_addr,      	0x00000070<<2
	.equ	ic_miss_addr,     	0x00000071<<2
	.equ	dc_hit_addr,      	0x00000072<<2
	.equ	dc_miss_addr,     	0x00000073<<2

