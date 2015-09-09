/*
 * Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <phy_lantiq.h>
#include <asm/gpio.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/chipid.h>
#include <asm/lantiq/cpu.h>
#include <asm/lantiq/mem.h>
#include <asm/arch/gphy.h>

#if defined(CONFIG_SPL_BUILD) || defined(CONFIG_SYS_BOOT_RAM)
#define do_gpio_init	1
#else
#define do_gpio_init	0
#endif

static void gpio_init(void)
{
	/* GPIO button board reset (low-active) */
	gpio_direction_input(3);
	/* GPIO button WLAN enable (low-active) */
	gpio_direction_input(42);
	/* GPIO button WPS enable (low-active) */
	gpio_direction_input(43);
	/* GPIO button DECT paging (low-active) */
	gpio_direction_input(61);

	/* IPAC-X interrupt */
	gpio_direction_input(1);
	gpio_set_pull(1, GPIO_PULL_UP);
	/* IPAC-X CS */
	gpio_direction_output(15, 1);

	/* SLIC reset (low-active) */
	gpio_direction_output(0, 0);
	/* SLIC CLK */
	gpio_direction_output(8, 1);
	/* SLIC TX */
	gpio_direction_output(34, 1);
	/* SLIC RX */
	gpio_direction_output(35, 1);
	/* SLIC CLK0_GNT */
	gpio_direction_output(36, 1);

	/* SPI DIN */
	gpio_direction_input(16);
	gpio_set_pull(16, GPIO_PULL_UP);
	/* SPI DOUT */
	gpio_direction_output(17, 1);
	/* SPI CLK */
	gpio_direction_output(18, 1);

	/* COSIC CS */
	gpio_direction_output(14, 1);
	/* COSIC CLK */
	gpio_direction_output(19, 1);
	/* COSIC DOUT */
	gpio_direction_output(10, 1);
	/* COSIC interrupt */
	gpio_direction_input(9);
	gpio_set_pull(9, GPIO_PULL_UP);
	/* COSIC DIN */
	gpio_direction_input(11);
	gpio_set_pull(11, GPIO_PULL_UP);

	/* NAND CS1 */
	gpio_set_altfunc(23, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND CLE */
	gpio_set_altfunc(24, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND ALE */
	gpio_set_altfunc(13, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND RDBY */
	gpio_set_altfunc(48, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_IN);
	/* NAND RE */
	gpio_set_altfunc(49, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND WE */
	gpio_set_altfunc(59, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND WP */
	gpio_set_altfunc(60, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[1] */
	gpio_set_altfunc(50, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[0] */
	gpio_set_altfunc(51, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[2] */
	gpio_set_altfunc(52, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[7] */
	gpio_set_altfunc(53, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[6] */
	gpio_set_altfunc(54, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[5] */
	gpio_set_altfunc(55, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[4] */
	gpio_set_altfunc(56, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* NAND Data[3] */
	gpio_set_altfunc(57, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

	/* LEDC/LED_ST for LED shift register */
	gpio_set_altfunc(4, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* LEDC/LED_D for LED shift register */
	gpio_set_altfunc(5, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* LEDC/LED_SH for LED shift register */
	gpio_set_altfunc(6, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

	/* TDM/FSC as input, internal pull-up */
	gpio_direction_input(58);
	gpio_set_pull(58, GPIO_PULL_UP);
	/* TDM/DCL as input, internal pull-up */
	gpio_direction_input(27);
	gpio_set_pull(27, GPIO_PULL_UP);
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
#if 0
	return mc_tune_store_flash();
#else
	return 0;
#endif
}

int ltq_phy_board_init(struct phy_device *phydev)
{
	/* LED0 */
	ltq_phy_mmd_write(phydev, LTQ_PHY_MMD_LED0H, 0x0);
	ltq_phy_mmd_write(phydev, LTQ_PHY_MMD_LED0L, 0x0);
	/* LED1 */
	ltq_phy_mmd_write(phydev, LTQ_PHY_MMD_LED1H, 0x70);
	ltq_phy_mmd_write(phydev, LTQ_PHY_MMD_LED1L, 0x03);
	/* LED2 */
	ltq_phy_mmd_write(phydev, LTQ_PHY_MMD_LED2H, 0x0);
	ltq_phy_mmd_write(phydev, LTQ_PHY_MMD_LED2L, 0x0);

	return 0;
}

static const struct ltq_eth_port_config eth_port_config[] = {
	/* GMAC0: Quantenna QSR1000 5G WiFi at xMII0 */
	{ 0, 0x0, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
	/* GMAC1: internal GPHY2 with 1000 firmware for LAN port ? */
	{ 1, 0x1, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC2: internal GPHY0 with 1000 firmware for LAN port ? */
	{ 2, 0x2, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC3: internal GPHY3 with 1000 firmware for LAN port ? */
	{ 3, 0x3, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC4: internal GPHY1 with 1000 firmware for LAN port ? */
	{ 4, 0x4, LTQ_ETH_PORT_PHY, PHY_INTERFACE_MODE_GMII },
	/* GMAC5: Mediatek M7620A 2.4G WiFi at xMII1 */
	{ 5, 0x14, LTQ_ETH_PORT_NONE, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t * bis)
{
	const enum ltq_gphy_clk clk = LTQ_GPHY_CLK_25MHZ_PLL0;
	void *fw_addr;

	fw_addr = ltq_gphy_alloc();
	if (!fw_addr)
		return -1;

	ltq_gphy_phy11g_a21_load(fw_addr);

	ltq_cgu_gphy_clk_src(clk);

	ltq_rcu_gphy_boot(0, fw_addr);
	ltq_rcu_gphy_boot(1, fw_addr);
	ltq_rcu_gphy_boot(2, fw_addr);
	ltq_rcu_gphy_boot(3, fw_addr);

	return ltq_eth_initialize(&eth_board_config);
}
