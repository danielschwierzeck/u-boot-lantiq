/*
 * Copyright (C) 2011-2015 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <spi.h>
#include <asm/gpio.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/chipid.h>
#include <asm/lantiq/cpu.h>
#include <asm/lantiq/mem.h>
#include <asm/arch/gphy.h>

#if defined(CONFIG_SPL_BUILD)
#define do_gpio_init	1
#define do_pll_init	1
#define do_dcdc_init	0
#elif defined(CONFIG_SYS_BOOT_RAM)
#define do_gpio_init	1
#define do_pll_init	0
#define do_dcdc_init	1
#else
#define do_gpio_init	0
#define do_pll_init	0
#define do_dcdc_init	1
#endif

static inline void gpio_init(void)
{
	/* GPIO button WLAN enable (low-active) */
	gpio_direction_input(45);
	/* GPIO button WPS enable (low-active) */
	gpio_direction_input(46);
	/* GPIO button board reset (low-active) */
	gpio_direction_input(47);

	/* LED Power green */
	gpio_direction_output(3, 1);
	/* LED FXO green */
	gpio_direction_output(14, 0);
	/* LED Power red */
	gpio_direction_output(19, 0);
	/* LED Info green */
	gpio_direction_output(20, 1);
	/* LED Info red */
	gpio_direction_output(21, 1);
	/* LED Internet green */
	gpio_direction_output(27, 1);
	/* LED Internet red */
	gpio_direction_output(28, 1);
	/* LED WLAN green */
	gpio_direction_output(29, 1);
	/* LED WPS green */
	gpio_direction_output(30, 1);
	/* LED USB2 green */
	gpio_direction_output(32, 1);

	/* SPI CS 0.4 to serial flash */
	gpio_direction_output(10, 1);

	/* SPI CS 1.0 to ISAC-SX */
	gpio_direction_output(39, 1);
	/* SPI CS 1.1 to IPAC-X FXO */
	gpio_direction_output(22, 1);

	/* USB port0 power enable, disabled at startup */
	gpio_direction_output(41, 0);
	/* USB port1 power enable, disabled at startup */
	gpio_direction_output(33, 0);

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

	/* LEDC/LED_ST for LED shift register */
	gpio_set_altfunc(4, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* LEDC/LED_D for LED shift register */
	gpio_set_altfunc(5, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* LEDC/LED_SH for LED shift register */
	gpio_set_altfunc(6, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

	/* Ralink iNIC WLAN reset, low-active, asserted at startup */
	gpio_direction_output(15, 0);
	/* Ralink iNIC WLAN power, disabled at startup */
	gpio_direction_output(37, 0);

	/* TDM/FSC as input, internal pull-up */
	gpio_direction_input(0);
	gpio_set_pull(0, GPIO_PULL_UP);
	/* TDM/DCL as input, internal pull-up */
	gpio_direction_input(40);
	gpio_set_pull(40, GPIO_PULL_UP);
	/* TDM/DI as input */
	gpio_direction_input(26);
	/* TDM/DO as input */
	gpio_direction_input(25);
}

int board_early_init_f(void)
{
	if (do_gpio_init) {
		ltq_gpio_init();
		gpio_init();
	}

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

int misc_init_r(void)
{
	return mc_tune_store_flash();
}

static const struct ltq_eth_port_config eth_port_sl4501[] = {
	/* GMAC0: unused */
	{ 0, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC1: unused */
	{ 1, 0x1, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC2: internal GPHY0 with 10/100/1000 firmware for LAN port 1 */
	{ 2, 0x11, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC3: unused */
	{ 3, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC4: internal GPHY0 with 10/100/1000 firmware for LAN port 2 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: Ralink iNIC */
	{ 5, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_sl4501 = {
	.ports = eth_port_sl4501,
	.num_ports = ARRAY_SIZE(eth_port_sl4501),
};

static const struct ltq_eth_port_config eth_port_sl5501[] = {
	/* GMAC0: external Lantiq PEF7071 10/100/1000 PHY for WANoE port */
	{ 0, 0x0, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII, 0, 0, 1 },
	/* GMAC1: external Lantiq PEF7071 10/100/1000 PHY for LAN port 3/4 */
	{ 1, 0x1, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII },
	/* GMAC2: internal GPHY1 with 10/100 firmware for LAN port 1/2 */
	{ 2, 0x11, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
	/* GMAC3: internal GPHY0 with 10/100 firmware for LAN port 1/2 */
	{ 3, 0x12, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
	/* GMAC4: internal GPHY0 with 10/100/1000 firmware for LAN port 3/4 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: Ralink iNIC */
	{ 5, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_sl5501 = {
	.ports = eth_port_sl5501,
	.num_ports = ARRAY_SIZE(eth_port_sl5501),
};

static const struct ltq_eth_port_config eth_port_sl6501[] = {
	/* GMAC0: unused */
	{ 0, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC1: external Lantiq PEF7071 10/100/1000 PHY for LAN port 3/4 */
	{ 1, 0x1, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII },
	/* GMAC2: internal GPHY1 with 10/100 firmware for LAN port 1/2 */
	{ 2, 0x11, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
	/* GMAC3: internal GPHY0 with 10/100 firmware for LAN port 1/2 */
	{ 3, 0x12, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_MII },
	/* GMAC4: internal GPHY0 with 10/100/1000 firmware for LAN port 3/4 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: Ralink iNIC */
	{ 5, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_sl6501 = {
	.ports = eth_port_sl6501,
	.num_ports = ARRAY_SIZE(eth_port_sl6501),
};

static const struct ltq_eth_port_config eth_port_compat[] = {
	/* GMAC0: unused */
	{ 0, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC1: unused */
	{ 1, 0x1, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC2: unused */
	{ 2, 0x11, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC3: unused */
	{ 3, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC4: internal GPHY0 with 10/100/1000 firmware for LAN port 2 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: Ralink iNIC */
	{ 5, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_compat = {
	.ports = eth_port_compat,
	.num_ports = ARRAY_SIZE(eth_port_compat),
};

int board_eth_init(bd_t * bis)
{
	const enum ltq_gphy_clk clk = LTQ_GPHY_CLK_25MHZ_PLL0;
	const ulong fw_ge_addr = 0x80FE0000;
	const ulong fw_fe_addr = 0x80FF0000;
	unsigned int base_platform = 0;

	ltq_gphy_phy11g_a2x_load(fw_ge_addr);
	ltq_gphy_phy22f_a2x_load(fw_fe_addr);

	ltq_cgu_gphy_clk_src(clk);

	switch (base_platform) {
	case 425:
		ltq_rcu_gphy_boot(0, fw_ge_addr);
		ltq_rcu_gphy_boot(1, fw_ge_addr);
		return ltq_eth_initialize(&eth_board_sl4501);
	case 420:
		ltq_rcu_gphy_boot(0, fw_fe_addr);
		ltq_rcu_gphy_boot(1, fw_ge_addr);
		return ltq_eth_initialize(&eth_board_sl5501);
	case 424:
		ltq_rcu_gphy_boot(0, fw_fe_addr);
		ltq_rcu_gphy_boot(1, fw_ge_addr);
		return ltq_eth_initialize(&eth_board_sl6501);
	default:
		ltq_rcu_gphy_boot(1, fw_ge_addr);
		return ltq_eth_initialize(&eth_board_compat);
	}
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
	int gpio = -1;

	/* Serial flash at bus 0 (SPI) */
	if (slave->bus == 0 && slave->cs == 4)
		gpio = 10;

	if (gpio >= 0)
		gpio_set_value(gpio, 0);
}

void spi_cs_deactivate(struct spi_slave *slave)
{
	int gpio = -1;

	/* Serial flash at bus 0 (SPI) */
	if (slave->bus == 0 && slave->cs == 4)
		gpio = 10;

	if (gpio >= 0)
		gpio_set_value(gpio, 1);
}
