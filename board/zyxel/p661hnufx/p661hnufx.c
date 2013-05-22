/*
 * Copyright (C) 2013-2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <switch.h>
#include <spi.h>
#include <asm/gpio.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/chipid.h>

static void gpio_init(void)
{
	/* Enable CLKOUT2 25 MHz for switch */
	gpio_set_altfunc(3, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

	/* Switch reset */
	gpio_direction_output(55, 1);

	/* SPI CS 0.4 to serial flash */
	gpio_direction_output(10, 1);
}

int board_early_init_f(void)
{
	gpio_init();

	return 0;
}

int checkboard(void)
{
	puts("Board: " CONFIG_BOARD_NAME "\n");
	ltq_chip_print_info();

	return 0;
}

static const struct ltq_eth_port_config eth_port_config[] = {
	/* MAC0: Lantiq Tantos switch */
	{ 0, 0x0, LTQ_ETH_PORT_SWITCH, PHY_INTERFACE_MODE_RMII },
	/* MAC1: unused */
	{ 1, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t *bis)
{
	return ltq_eth_initialize(&eth_board_config);
}

static struct switch_device psb697x_dev = {
	.name = "psb697x",
	.cpu_port = 5,
	.port_mask = 0xF,
};

int board_switch_init(void)
{
	printf("%s\n", __func__);

	gpio_set_value(55, 0);
	__udelay(50000);
	gpio_set_value(55, 1);

	return switch_device_register(&psb697x_dev);
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
