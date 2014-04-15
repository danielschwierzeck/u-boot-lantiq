/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/gpio.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/chipid.h>
#include <asm/lantiq/cpu.h>
#include <asm/arch/gphy.h>

#if defined(CONFIG_SPL_BUILD)
#define do_gpio_init	1
#define do_pll_init	1
#define do_dcdc_init	0
#elif defined(CONFIG_SYS_BOOT_RAM)
#define do_gpio_init	1
#define do_pll_init	0
#define do_dcdc_init	1
#elif defined(CONFIG_SYS_BOOT_NOR)
#define do_gpio_init	1
#define do_pll_init	1
#define do_dcdc_init	1
#else
#define do_gpio_init	0
#define do_pll_init	0
#define do_dcdc_init	1
#endif

static void gpio_init(void)
{
	/* Turn on power and alarm LEDs */
	
	gpio_direction_output(14, 1);
	gpio_direction_output(15, 1);
	
	gpio_set_value(14, 0);
	gpio_set_value(15, 0);
	
/* EBU.FL_A23 as output for NOR flash */

	gpio_set_altfunc(24, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

/* EBU.FL_A24 as output for NOR flash */
	gpio_set_altfunc(13, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

/* EBU.FL_A25 as output for NOR flash */
	gpio_set_altfunc(31, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

}

int board_early_init_f(void)
{
	if (do_gpio_init)
		gpio_init();

	if (do_pll_init)
		ltq_pll_init();

	if (do_dcdc_init)
		ltq_dcdc_init(0x7F);

	return 0;
}

int checkboard(void)
{
	puts("Board: " CONFIG_BOARD_NAME "\n");
	ltq_chip_print_info();

	return 0;
}

static const struct ltq_eth_port_config eth_port_config[] = {
	/* GMAC0: external Lantiq PEF7071 v1.5 10/100/1000 PHY for LAN port 0 */
	{ 0, 0x0,  LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII },
	/* GMAC1: internal GPHY1 with 10/100/1000 firmware for LAN port 1 */
	{ 2, 0x11, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
	/* GMAC3: internal GPHY1 with 10/100/1000 firmware for LAN port 2 */
	{ 3, 0x12, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
	/* GMAC4: internal GPHY1 with 10/100/1000 firmware for LAN port 3 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
	/* GMAC5: internal GPHY1 with 10/100/1000 firmware for LAN port 4 */
	{ 5, 0x14, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t * bis)
{
	const enum ltq_gphy_clk clk = LTQ_GPHY_CLK_25MHZ_PLL0;
	const ulong fw_addr = 0x80FE0000;

	switch ( ltq_chip_version_get() ) {
		
		case 1:
				ltq_gphy_phy22f_a1x_load(fw_addr);
				break;
				
		case 2:
				ltq_gphy_phy22f_a2x_load(fw_addr);
				break;
			
		}

	ltq_cgu_gphy_clk_src(clk);

	ltq_rcu_gphy_boot(0, fw_addr);
	ltq_rcu_gphy_boot(1, fw_addr);

	return ltq_eth_initialize(&eth_board_config);
}

