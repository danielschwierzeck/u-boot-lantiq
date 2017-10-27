##############################################################
##
## Metalink L.T.D. (c) Copyright 2006.
## Metalink Confidential Proprietary.
##
## $Author: amir $
## $Date: Wed Jul  6 13:31:17 2011 $
##
## $Aliases:  $
##
## $Log: start_clock.s.rca $
## 
##  Revision: 1.3.1.3.1.17.1.6 Wed Jul  6 13:31:17 2011 amir
##  Modified BBCPU system I/F base address from NPU side
## 
##  Revision: 1.3.1.3.1.17.1.5 Sun Apr  3 10:04:30 2011 amir
##  Modified PLL activation sequence. New sequence is:
##  1. Release PLL power down control
##  2. Wait for PLL lock - either by PLL lock indication or by a timer (wait duration is according to efuse)
##  3. Only when PLL is locked, enable PLL's outputs
##  4. Set the clock switch in clkgen module to move from XO to PLL
## 
##  Revision: 1.3.1.3.1.17.1.4 Mon Mar 21 16:54:34 2011 amir
##  Code now polls a bit in efuse array to decide if to poll pll delay indication (default)
##  or to wait a preconfigured time until PLL lock should be done (efuse bit is "1")
## 
##  Revision: 1.3.1.3.1.17.1.3 Sun Mar 13 08:37:52 2011 amir
##  Added a copy routine from efuse to PLL controls
##  Modified delay loop time to be variable, according to a value stored in efuse
## 
##  Revision: 1.3.1.3.1.17.1.2 Wed Mar  2 14:00:07 2011 oren_a
##  1. added reduced freq mode config
##  2. increased pll lock time to 1ms
## 
##  Revision: 1.3.1.3.1.17.1.1 Tue Jan 18 11:57:53 2011 michaelk
##  *** empty comment string ***
## 
##  Revision: 1.3.1.3.1.17 Fri Oct 22 09:58:07 2010 oren_a
##  added seperate_mac_phy_clk_equ
## 
##  Revision: 1.3.1.3.1.16 Sun Oct 17 16:37:35 2010 oren_a
##  *** empty comment string ***
## 
##  Revision: 1.3.1.3.1.15 Sun Sep 26 18:03:27 2010 oren_a
##  changed PLL_LOCK_TIME_IN_US to 30us in short_lock_delay mode
## 
##  Revision: 1.3.1.3.1.14 Wed Sep 22 13:15:57 2010 oren_a
##  changed PLL_LOCK_TIME_IN_US in short_lock_delay mode to 150us due to AFE model change
## 
##  Revision: 1.3.1.3.1.13 Tue Sep 21 13:06:06 2010 oren_a
##  fixed divider values
## 
##  Revision: 1.3.1.3.1.12 Thu Sep  2 16:15:24 2010 oren_a
##  removed fast mode checking for fast_clock_in_boot mode
## 
##  Revision: 1.3.1.3.1.11 Wed Sep  1 11:04:32 2010 michaelk
##  updated timer
## 
##  Revision: 1.3.1.3.1.10 Tue Aug 31 18:37:53 2010 michaelk
##  aded timer interupt disable
## 
##  Revision: 1.3.1.3.1.9 Wed Aug 25 18:39:37 2010 oren_a
##  fixed short pll delay and mac clock 320MHz
## 
##  Revision: 1.3.1.3.1.8 Tue Aug 10 12:09:34 2010 oren_a
##  wait for PLL lock with HW timer
## 
##  Revision: 1.3.1.3.1.7 Tue Aug 10 10:01:48 2010 oren_a
##  changes pll lock time calculations
## 
##  Revision: 1.3.1.3.1.6 Thu Aug  5 13:41:13 2010 oren_a
##  changes for new AFE PLL
## 
##  Revision: 1.3.1.3.1.5 Wed Jul 21 18:50:14 2010 michaelk
##  fixed clk mux
## 
##  Revision: 1.3.1.3.1.4 Sun Jul 18 08:44:41 2010 amir
##  Added SW reset to the phy as part of the seperate_mac_phy_clks sequence
## 
##  Revision: 1.3.1.3.1.3 Sun Jul 18 08:38:37 2010 oren_a
##  added seperate phy and mac clock define
## 
##  Revision: 1.3.1.3.1.2 Wed Jun 30 15:45:57 2010 oren_a
##  added fast_clock_in_boot define
## 
##  Revision: 1.3.1.3.1.1 Sun May  2 08:25:08 2010 oren_a
##  changes for gen3.5 fast/slow clock
## 
##  Revision: 1.3.1.3 Tue Jan 27 16:16:46 2009 oren_a
##  fixed PLL lock time wait
## 
##  Revision: 1.3.1.2 Wed Dec 24 19:11:49 2008 michaelk
##  change jal to bal
## 
##  Revision: 1.3.1.1 Thu Aug 28 16:25:47 2008 amir
##  Now compatible with Erylus initializations
## 
##  Revision: 1.3 Tue Nov 27 14:07:12 2007 arikc
##  delete rxtd equ file
## 
##  Revision: 1.2 Thu Aug 16 20:38:24 2007 ronen
##  this start clock should used from the Upper cpu 
##  because the base address is for the system interface unit 
##  accessing from Upper
##  add 60 Usec delay waiting for Pll Lock
##  changed the pll write order
##  first write the pll parameters and then activate the PLL
##      
## Spec. Reference:
## ----------------
## 
## Description:
## ------------
##
##############################################################
	
/*
	Version 1.1 (1/2/2006)
	Standard Clocks init
	This starts the clocks on the hyperionII chip
	This function can be called with include dirrective.
	
	
		
*/	
	/* RXTD equ file */
	
        /* System Interface EQU file */

        .equ    PLL_LOCK_TIME_IN_US,                            1000 
        .equ    PLL_LOCK_TIME_IN_US_rstq1,                      1200 
        .equ    PLL_LOCK_TIME_IN_US_rstq2,                      1600 
        .equ    PLL_LOCK_TIME_IN_US_rstq3,                      2400 
        .equ    MAC_CLOCK_FREQ_IN_MHZ,                          36
        .equ    FAST_CLK_DIV,                                   2

        .equ	sys_if_base_address,				0xa6298000
        .equ    rxtd_base_address,                              0xa630
        .equ	ht_ext_base,		                        0xa62f

        /* if during boot there is 300MHz clock */

        /* for fast simulation will not wait 1000us for PLL lock */
        /* for fast simulation will not wait 1000us for PLL lock */


        .equ	secure_write_addr,				(0x1A << 2)     

        .equ	pll_mul_div_addr,				(0x10 << 2)
        .equ	pll_n_field,					0
        .equ	pll_refdiv_field,				9
        
        .equ	pll_control_reg,				(0x11 << 2 )
        .equ	pll_control_pll_off_field,			3
        .equ	pll_control_pll_bypass_field,			4
        .equ	pll_control_pll_refdly_field,			0
        
	.equ    pll_param_reg,                                  (0x14 << 2)
	.equ    pll_param_vco_cal_field,                        9
	.equ    pll_param_vco_field,                            4 
	.equ    pll_param_filter_field,                         2
	.equ    pll_param_pllcp_field,                          0
	
	
        .equ	cpu_clk_select_reg,				(0x16 << 2)
        .equ	phy_clk_select_mac_reg,				(0x2f << 2)
	.equ	mac2phy_rst_reg,				(0x45 << 2)    
        .equ	cpu_clock_gen_reg,				(0x1e << 2)     
        .equ	cpu_clock_gen_cpu_phy_div_enable_field,		5
        .equ	cpu_clock_gen_cpu_phy_div_field,		3
        .equ	cpu_clock_gen_modem_pre_div_field,		2
        .equ	cpu_clock_gen_modem_xo_sel_field,		1
        .equ	cpu_clock_gen_lvds_xo_sel_field,		0

	.equ	digital_lpbk_reg,				( 0x25 << 2)
        .equ	digital_lpbk_rx0_polarity_sel_field,		0
        .equ	digital_lpbk_rx1_polarity_sel_field_field,	1 
        .equ	digital_lpbk_rx2_polarity_sel_field_field,	2 
        .equ	digital_lpbk_tx0_polarity_sel_field,		3 
        .equ	digital_lpbk_tx1_polarity_sel_field,		4 
        .equ	digital_lpbk_ch0_lpbk_clk_src_field,		5 
        .equ	digital_lpbk_ch1_lpbk_clk_src_field,		6 
        .equ	digital_lpbk_rx0_lpbk_select_field,		7
        .equ	digital_lpbk_rx1_lpbk_select_field,		9
        .equ	digital_lpbk_rx2_lpbk_select_field,		11
        .equ	digital_lpbk_rx_aux_polarity_sel_field,		13


        .equ	pll_en_div_reg,                                 (0x10 << 2)
        .equ	mac_clk_div_d2a_field,                          0
        .equ	mac_clk_en_d2a_field,                           3
        .equ	tbus_clk_div_d2a_field,                         4
        .equ	tbus_clk_en_d2a_field,                          7
        .equ	phy_clk_div_d2a_field,                          8
        .equ	phy_clk_en_d2a_field,                           11
        .equ	adc_clk_div_d2a_field,                          12
        .equ	adc_clk_en_d2a_field,                           15

## MAC Clock Div
        .equ    mac_clk_div_d2a_320MHz,                         4
        .equ    mac_clk_div_d2a_480MHz,                         0
        .equ    mac_clk_div_d2a_240MHz,                         1
        .equ    mac_clk_div_d2a_80MHz,                          6
        .equ    mac_clk_div_d2a_120MHz,                         2
        .equ    mac_clk_div_d2a_160MHz,                         5
        .equ    mac_clk_div_d2a_40MHz,                          7
        .equ    mac_clk_div_d2a_60MHz,                          3

## Phy Clock Div
        .equ    phy_clk_div_d2a_240MHz,                         0
        .equ    phy_clk_div_d2a_480MHz,                         1
        .equ    phy_clk_div_d2a_60MHz,                          2
        .equ    phy_clk_div_d2a_120MHz,                         3


        .equ    pll_ctl_reg,                                    (0x12 << 2)
        .equ    bbpll_config_d2a_field,                         0
        .equ    bbpll_pup_d2a_field,                            8
        .equ    bbpll_ldodis_d2a_field,                         9
        .equ    bbpll_rstq_cnt_d2a_field,                       10
        .equ    fcsi_ldo_pd_d2a_field,                          13

	.equ	pll_lock_reg,					0x14<<2
        .equ    not_in_cached_value,                            0
        .equ    in_cached_value,                                1


        .equ 	 tmr_prescale_addr,                             0x0e << 2
        .equ 	 tmr_enable_addr,                               0x0f << 2
	.equ 	 tmr_disable_addr,                              0x3c << 2 
        .equ     mac_ht_extensions_tmr_irq ,                   ( 0x0034 )
        .equ 	 tmr_00_init_addr,                              0x10 << 2 
        .equ 	 tmr_00_cnt_addr,                               0x20 << 2

	/***************************************************/
	/* Clock Manipulation 240 (default), 160 ,120 MHz  */
	/***************************************************/
	

	.equ	sys_clk_fast_divider_reg,	(0x13 << 2)
        .equ	pll_clk_sel_reg,	        (0x2f << 2)
	
	.equ    fast_mode_mac_div           , mac_clk_div_d2a_480MHz 
	.equ    slow_mode_mac_div           , mac_clk_div_d2a_240MHz 
        .equ    seperate_mac_phy_clks_equ, 0


	.equ	SHARED_REG_BASE,	0xa71c0000

	.equ    EFUSE_DATA,		0x0120
	.equ    EFUSE_ADDRESS,          0x0124
	.equ    EFUSE_CONTROL,          0x0128
	.equ    EFUSE_STATUS,           0x012c
	.equ    EFUSE_TIMER_CONFIG1,    0x0130
	.equ    EFUSE_TIMER_CONFIG2,    0x0134

	.equ	EFUSE_BUSY,		0x1
	
        /* PLL configuration*/

        li     $10,sys_if_base_address


	

	/* Modify the MAC clock divider field */
	li	$4,0xa7000000
	lw	$3,0x0060($4)
	li	$4,0x1<<19 /* CPU fast mode indication @ NPU system I/F */

	/* Store fast mode indication in $4: 1 = fast mode, 0 = slow mode */
	and	$3,$3,$4
	srl	$4,$3,19

	
        /* PLL turning on + PLL config */
	
	/* Read offsets 50,51 from efuse array */
	
	/* Verify efuse control machine is not busy */
	li	$5,SHARED_REG_BASE
poll_efuse_machine_busy:	
	lw	$13,EFUSE_STATUS($5)
	andi	$13,EFUSE_BUSY
	bne	$13,$0,poll_efuse_machine_busy
/*nop*/
	/* Write address to read from */
	li	$13,0x32<<3
	sw	$13,EFUSE_ADDRESS($5)
	/* Set READ bit - also triggers machine operation */
	sw	$0,EFUSE_CONTROL($5)
	
	/* Wait for machine ready */
wait_if_busy:	
	lw	$13,EFUSE_STATUS($5)
	andi	$13,EFUSE_BUSY
	bne	$13,$0,wait_if_busy
/*nop*/

	/* Load read data into $12 */
	lw	$12,EFUSE_DATA($5)

	/* Write address to read from */
	li	$13,0x33<<3
	sw	$13,EFUSE_ADDRESS($5)
	/* Set READ bit - also triggers machine operation */
	sw	$0,EFUSE_CONTROL($5)
	
	/* Wait for machine ready */
wait_if_busy2:	
	lw	$13,EFUSE_STATUS($5)
	andi	$13,EFUSE_BUSY
	bne	$13,$0,wait_if_busy2
/*nop*/

	/* Load read data into $12 */
	lw	$13,EFUSE_DATA($5)
	andi	$14,$13,0x8 /* $14 will hold bit[3] which is "1" if we have a delay loop for PLL lock of "0" if we want to rely on PLL lock indication */
	andi	$13,0x7
	or	$5,$13,$0 /* Copy RST_Q to $5 */
	sll	$13,10
	or	$12,$12,$13
	li	$13,0xffffe300
	
        lw      $2, pll_ctl_reg($10)
	and	$2,$2,$13
        li      $3, ( 1 << bbpll_pup_d2a_field)
        or      $2,$3,$2
	or	$2,$2,$12
        bal     secure_write
        sw      $2, pll_ctl_reg($10)

	li	$13,(MAC_CLOCK_FREQ_IN_MHZ - 1)
	beq	$4,$0,fast_mode_delay_continue
/*nop*/
	/* If fast mode, override prev. value */
	li	$13,(MAC_CLOCK_FREQ_IN_MHZ/FAST_CLK_DIV - 1)
fast_mode_delay_continue:
	bne	$14,$0,do_pll_delay_loop
/*nop*/

#/*start endless loop*/
#		nop
#endless1:
#        b  endless1
#		nop
#/*end loop*/

pll_lock_poll_loop:
	lw	$2,pll_lock_reg($10)
	beq	$2,$0,pll_lock_poll_loop
/*nop*/
	b	configure_pll_clocks

do_pll_delay_loop:
        bal     power_up_delay        
configure_pll_clocks:
        /* Update the AFE clock according to equ algo_afe_clock_freq_div*/
	/* Updated to Feronia V32 */
        /* for 80MHz algo_afe_clock_freq_div = 6  */ 
        /* for 40MHz algo_afe_clock_freq_div = 12 */
        /* Configuring the PLL clocks (0(AFE)=80M, 1(LVDS)= 480M, 2(PHY)=240M, 3(MAC)=160M) */
        lw      $2, pll_en_div_reg($10)
	/* We need to modify MAC clock divider's default value value set epending on fast mode and mac freq */
	beq	$4,$0,set_slow_mode_mac_divider
/*nop*/
	li	$3,0xfffffff8
	/*$2 holds: see Emerald Env, addr 40, mac_clk_div_d2a= bits 0,1,2. Clear 3 litle bits in reg $2*/
	and	$2,$2,$3
set_fast_mode_mac_divider:	
        li	$3,(fast_mode_mac_div   << mac_clk_div_d2a_field)
        b       set_mac_clock_div        
set_slow_mode_mac_divider:	
        li	$3,(slow_mode_mac_div   << mac_clk_div_d2a_field)
set_mac_clock_div:
	or	$2,$2,$3
        li      $3, ((1 << adc_clk_en_d2a_field) | (1 << phy_clk_en_d2a_field) | (1 << tbus_clk_en_d2a_field) | (1 << mac_clk_en_d2a_field))
        or      $2,$3,$2
        bal     secure_write
        sw      $2, pll_en_div_reg($10)

switch_to_pll:	
        /*Select fast clock (sel=2) */
        bal     secure_write
	li	$2,0x00000002
        sw      $2, cpu_clk_select_reg($10)

        /* check if need to seperate the mac and phy clocks */
        li      $2,seperate_mac_phy_clks_equ
        beq     $2,$0,phy_mac_synchronized
/*nop*/
        
        /* sepearte mac and phy */
        /* Start Phy clock*/
        lw      $2, cpu_clock_gen_reg($10)
        ori     $2, $2, ( 1 << cpu_clock_gen_cpu_phy_div_enable_field)
        sw      $2, cpu_clock_gen_reg($10)

	/* Hold the phy in reset before changing the clock mux */
	bal	secure_write
	sw	$0,mac2phy_rst_reg($10)
	
        /* Select PHY clock from PHY not MAC */
        li      $2, 0x0
        sw      $2, phy_clk_select_mac_reg($10)

	/* Release Phy from reset */
	bal	secure_write
        li      $2, 0x1
	sw	$2,mac2phy_rst_reg($10)
	
phy_mac_synchronized:
        li      $9, rxtd_base_address
	        
	b	std_init_cont

##************************************************************ 	
##  
##************************************************************ 
secure_write:
        li      $12, 0x0000aaaa
        sw      $12, secure_write_addr($10)
        li      $12, 0x00005555
        sw      $12, secure_write_addr($10)
        jr	$31

##************************************************************ 
##  
##************************************************************ 
power_up_delay:

	/* Enable GCLK to HT Extensions units */	
	lui	$20,ht_ext_base
	li	$11,0x000000ff
	sw	$11,0x0000($20)

	/* Cofigure prescaler */
        srl     $14,$13,1       # load to $14 prescaler value for reduced freq (half of $13)
        sll     $14,$14,16      # reduced freq value resides in upper 16ms      # reduced freq value resides in upper 16msbb
        or      $13,$14,$13
	sw	$13,tmr_prescale_addr($20)

        /* Configure all timers */
        li	$11,PLL_LOCK_TIME_IN_US
	/* We start with 1000us. Then, we decrement $5 which is rst_q and increase lock time accordingly */
	beq	$5,$0,do_configure
/*nop*/
	addiu	$5,-1
	li	$11,PLL_LOCK_TIME_IN_US_rstq1
	beq	$5,$0,do_configure
/*nop*/
	addiu	$5,-1
	li	$11,PLL_LOCK_TIME_IN_US_rstq2
	beq	$5,$0,do_configure
/*nop*/
	li	$11,PLL_LOCK_TIME_IN_US_rstq3	
do_configure:		
        sw	$11,tmr_00_init_addr($20)

        /* Enable timer 0 */
	li	$11,0x00000001
	sw	$11,tmr_enable_addr($20)
        
wait_timer_expired:
        lw      $11,tmr_00_cnt_addr($20)
        bne     $11,$0,wait_timer_expired
/*nop*/
         /* clear  timer irq 0 */
	li	$11,0x00000001
	sw	$11,mac_ht_extensions_tmr_irq($20)
         /* disable GCLK to HT Extensions units */	
	li	$11,0x00000000
	sw	$11,0x0000($20)
        jr      $31                

##************************************************************ 
##  
##************************************************************ 
std_init_cont:

	nop
	nop
	nop
	nop
	nop
	

