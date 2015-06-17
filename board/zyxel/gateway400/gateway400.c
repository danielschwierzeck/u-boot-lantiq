/*
 * Copyright (C) 2011-2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
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
	/* GPIO button board reset (low-active) */
	gpio_direction_input(46);

	/* SPI CS 0.4 to serial flash */
	gpio_direction_output(10, 1);

	/* SPI CS 1.0..1.3 to ISAC-SX 0..3 */
	gpio_direction_output(39, 1);
	gpio_direction_output(32, 1);
	gpio_direction_output(34, 1);
	gpio_direction_output(22, 1);

	/* Atheros AR8031 10/100/1000 PHY reset line */
	gpio_direction_output(15, 1);

	/* SPI CS 1.4 to PLL ZL30342 */
	gpio_direction_output(37, 1);

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

	/* PCM DCL/FSC input/output switch -> default output */
	gpio_direction_output(47, 1);

	/* High output for supervisor */
	gpio_direction_output(8, 1);
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
	/* enable CLKOUT0 for Supervisor */
	gpio_set_altfunc(8, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

	return mc_tune_store_flash();
}

static const struct ltq_eth_port_config eth_port_config[] = {
	/* GMAC0: Lantiq S-VIP */
	{ 0, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC1: unused */
	{ 1, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC2: internal GPHY0 with 10/100/1000 firmware for LAN port 0 */
	{ 2, 0x11, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC3: unused */
	{ 3, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC4: internal GPHY1 with 10/100/1000 firmware for LAN port 1 */
	{ 4, 0x13, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: external Atheros AR8031 10/100/1000 PHY for WANoE port */
	{ 5, 0x0, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_RGMII, 0, 3, 1 },
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
	/* Serial flash at bus 0 (SPI) */
	if (bus == 0 && cs == 4)
		return 1;

	/* ISAC-SX 0..3 at bus 1 (USIF) */
	if (bus == 1 && cs < 4)
		return 1;

	return 0;
}

void spi_cs_activate(struct spi_slave *slave)
{
	int gpio = -1;

	/* Serial flash at bus 0 (SPI) */
	if (slave->bus == 0 && slave->cs == 4)
		gpio = 10;

	else if (slave->bus == 1) {
		switch (slave->cs) {
		case 0:		/* ISAC-SX 0 */
			gpio = 39;
			break;
		case 1:		/* ISAC-SX 1 */
			gpio = 32;
			break;
		case 2:		/* ISAC-SX 2 */
			gpio = 34;
			break;
		case 3:		/* ISAC-SX 3 */
			gpio = 22;
			break;
		default:
			break;
		}
	}

	if (gpio >= 0)
		gpio_set_value(gpio, 0);
}

void spi_cs_deactivate(struct spi_slave *slave)
{
	int gpio = -1;

	/* Serial flash at bus 0 (SPI) */
	if (slave->bus == 0 && slave->cs == 4)
		gpio = 10;

	else if (slave->bus == 1) {
		switch (slave->cs) {
		case 0:		/* ISAC-SX 0 */
			gpio = 39;
			break;
		case 1:		/* ISAC-SX 1 */
			gpio = 32;
			break;
		case 2:		/* ISAC-SX 2 */
			gpio = 34;
			break;
		case 3:		/* ISAC-SX 3 */
			gpio = 22;
			break;
		default:
			break;
		}
	}

	if (gpio >= 0)
		gpio_set_value(gpio, 1);
}
