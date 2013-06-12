/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __VRX200_GPHY_H__
#define __VRX200_GPHY_H__

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

/*
 * Load PHY11G firmware for VRX200 v1.1 to given RAM address
 *
 * Address must be 16k aligned!
 */
extern void ltq_gphy_phy11g_a1x_load(ulong addr);

/*
 * Load PHY11G firmware for VRX200 v1.2 to given RAM address
 *
 * Address must be 16k aligned!
 */
extern void ltq_gphy_phy11g_a2x_load(ulong addr);

/*
 * Load PHY22F firmware for VRX200 v1.1 to given RAM address
 *
 * Address must be 16k aligned!
 */
extern void ltq_gphy_phy22f_a1x_load(ulong addr);

/*
 * Load PHY22F firmware for VRX200 v1.2 to given RAM address
 *
 * Address must be 16k aligned!
 */
extern void ltq_gphy_phy22f_a2x_load(ulong addr);

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
extern void ltq_rcu_gphy_boot(unsigned int id, ulong addr);

#endif /* __VRX200_GPHY_H__ */
