/*
 * Copyright (C) 2015-2016 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __XRX330_GPHY_H__
#define __XRX330_GPHY_H__

enum ltq_gphy_clk {
	/* XTAL 36 MHz input */
	LTQ_GPHY_CLK_36MHZ_XTAL = 1,
	/* 25 MHz from PLL0 with divider */
	LTQ_GPHY_CLK_25MHZ_PLL0 = 2,
	/* derived from PLL2 output (XTAL is 36 MHz) */
	LTQ_GPHY_CLK_24MHZ_PLL2 = 3,
	/* 25 MHz Clock from Pin GPIO3 */
	LTQ_GPHY_CLK_25MHZ_GPIO3 = 4,
};

#define LTQ_GPHY_FW_ALIGN	16 * 1024
#define LTQ_GPHY_FW_SIZE	64 * 1024

extern void *ltq_gphy_alloc(void);

/*
 * Load PHY11G firmware for xRX300 to given RAM address
 *
 * Address must be 16k aligned!
 */
extern void ltq_gphy_phy11g_a21_load(void *addr);

/*
 * Load PHY22F firmware for xRX300 to given RAM address
 *
 * Address must be 16k aligned!
 */
extern void ltq_gphy_phy22f_a21_load(void *addr);

/*
 * Set clock source of internal GPHYs
 *
 * According registers resides in CGU address space. Thus this function
 * is implemented by the CGU driver.
 */
extern void ltq_cgu_gphy_clk_src(enum ltq_gphy_clk clk);

/*
 * Boot internal GPHY with id from given RAM address
 *
 * According registers resides in RCU address space. Thus this function
 * is implemented by the RCU driver.
 */
extern void ltq_rcu_gphy_boot(unsigned int id, void *addr);

#endif /* __XRX330_GPHY_H__ */
