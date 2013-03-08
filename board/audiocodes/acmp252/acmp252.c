/*
 * Copyright (C) 2013 Daniel Golle <daniel.golle@gmail.com>
 * Copyright (C) 2011 Luka Perkov <luka@openwrt.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <switch.h>
#include <asm/gpio.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/chipid.h>

static void gpio_init(void)
{
	/* Activate reset line of ADM6996I switch */
	gpio_direction_output(19, 0);
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
	/* MAC0: Lantiq ADM6996I switch */
	{ 0, 0x0, LTQ_ETH_PORT_SWITCH, PHY_INTERFACE_MODE_RMII },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t *bis)
{
	return ltq_eth_initialize(&eth_board_config);
}

static struct switch_device adm6996i_dev = {
	.name = "adm6996i",
	.cpu_port = 5,
	.port_mask = 0xF,
};

int board_switch_init(void)
{
	/* Deactivate reset line of ADM6996I switch */
	gpio_set_value(19, 1);

	/* ADM6996I needs some time to come out of reset */
	__udelay(50000);

	return switch_device_register(&adm6996i_dev);
}
