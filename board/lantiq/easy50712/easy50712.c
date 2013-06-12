/*
 * Copyright (C) 2010 Thomas Langer <thomas.langer@lantiq.com>
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
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
	/* SPI/CS output (low-active) for serial flash */
	gpio_direction_output(22, 1);

	/* EBU.FL_CS1 as output for NAND CE */
	gpio_set_altfunc(23, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* EBU.FL_A23 as output for NAND CLE */
	gpio_set_altfunc(24, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* EBU.FL_A24 as output for NAND ALE */
	gpio_set_altfunc(13, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

	/* enable CLK_OUT2 for external switch */
	gpio_set_altfunc(3, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
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
	/* Deactivate HRST line to release reset of ADM6996I switch */
	ltq_reset_once(LTQ_RESET_HARD, 200000);

	/* ADM6996I needs some time to come out of reset */
	__udelay(50000);

	return switch_device_register(&adm6996i_dev);
}

int spi_cs_is_valid(unsigned int bus, unsigned int cs)
{
	if (bus)
		return 0;

	switch (cs) {
	case 2:
		return 1;
	default:
		return 0;
	}
}

void spi_cs_activate(struct spi_slave *slave)
{
	switch (slave->cs) {
	case 2:
		gpio_set_value(22, 0);
		break;
	default:
		break;
	}
}

void spi_cs_deactivate(struct spi_slave *slave)
{
	switch (slave->cs) {
	case 2:
		gpio_set_value(22, 1);
		break;
	default:
		break;
	}
}
