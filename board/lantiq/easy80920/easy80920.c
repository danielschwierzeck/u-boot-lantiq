/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <spi.h>
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
	/* SPI CS 0.4 to serial flash */
	gpio_direction_output(10, 1);

	/* EBU.FL_CS1 as output for NAND CE */
	gpio_set_altfunc(23, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* EBU.FL_A23 as output for NAND CLE */
	gpio_set_altfunc(24, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* EBU.FL_A24 as output for NAND ALE */
	gpio_set_altfunc(13, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* GPIO 3.0 as input for NAND Ready Busy */
	gpio_set_altfunc(48, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_IN);
	/* GPIO 3.1 as output for NAND Read */
	gpio_set_altfunc(49, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
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
	/* GMAC0: external Lantiq PEF7071 10/100/1000 PHY for LAN port 0 */
	{ 0, 0x0, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII },
	/* GMAC1: external Lantiq PEF7071 10/100/1000 PHY for LAN port 1 */
	{ 1, 0x1, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII },
	/* GMAC2: internal GPHY0 with 10/100/1000 firmware for LAN port 2 */
	{ 2, 0x11, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC3: unused */
	{ 3, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC4: internal GPHY1 with 10/100/1000 firmware for LAN port 3 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: external Lantiq PEF7071 10/100/1000 PHY for WANoE port */
	{ 5, 0x5, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t * bis)
{
	const enum ltq_gphy_clk clk = LTQ_GPHY_CLK_25MHZ_PLL0;
	const ulong fw_addr = 0x80FF0000;

	ltq_gphy_phy11g_a1x_load(fw_addr);

	ltq_cgu_gphy_clk_src(clk);

	ltq_rcu_gphy_boot(0, fw_addr);
	ltq_rcu_gphy_boot(1, fw_addr);

	return ltq_eth_initialize(&eth_board_config);
}

int spi_cs_is_valid(unsigned int bus, unsigned int cs)
{
	if (bus)
		return 0;

	if (cs == 4)
		return 1;

	return 0;
}

void spi_cs_activate(struct spi_slave *slave)
{
	switch (slave->cs) {
	case 4:
		gpio_set_value(10, 0);
		break;
	default:
		break;
	}
}

void spi_cs_deactivate(struct spi_slave *slave)
{
	switch (slave->cs) {
	case 4:
		gpio_set_value(10, 1);
		break;
	default:
		break;
	}
}
