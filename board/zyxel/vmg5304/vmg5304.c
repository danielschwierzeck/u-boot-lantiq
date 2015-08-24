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
	gpio_direction_input(1);
	/* GPIO button WPS enable (low-active) */
	gpio_direction_input(2);
	/* GPIO button board reset (low-active) */
	gpio_direction_input(7);

	/* LED WPS */
	gpio_direction_output(9, 0);
	/* LED WLAN */
	gpio_direction_output(11, 0);
	/* LED Internet green */
	gpio_direction_output(12, 0);
	/* LED Power red */
	gpio_direction_output(15, 1);
	/* LED Power green */
	gpio_direction_output(33, 1);

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

	/* LEDC/LED_ST for LED shift register */
	gpio_set_altfunc(4, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* LEDC/LED_D for LED shift register */
	gpio_set_altfunc(5, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* LEDC/LED_SH for LED shift register */
	gpio_set_altfunc(6, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
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

static const struct ltq_eth_port_config eth_port_config[] = {
	/* GMAC0: unused */
	{ 0, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC1: unused */
	{ 1, 0x1, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC4: internal GPHY0 with 10/100/1000 firmware for LAN port 1 */
	{ 2, 0x11, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC3: unused */
	{ 3, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC4: internal GPHY1 with 10/100/1000 firmware for LAN port 2 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: unused */
	{ 5, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t * bis)
{
	const enum ltq_gphy_clk clk = LTQ_GPHY_CLK_25MHZ_PLL0;
	const ulong fw_ge_addr = 0x80FE0000;

	ltq_gphy_phy11g_a2x_load(fw_ge_addr);

	ltq_cgu_gphy_clk_src(clk);
	ltq_rcu_gphy_boot(0, fw_ge_addr);
	ltq_rcu_gphy_boot(1, fw_ge_addr);

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
