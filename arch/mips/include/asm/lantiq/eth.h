/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LANTIQ_ETH_H__
#define __LANTIQ_ETH_H__

#include <phy.h>

enum LTQ_ETH_PORT_FLAGS {
	LTQ_ETH_PORT_NONE	= 0,
	LTQ_ETH_PORT_PHY	= 1,
	LTQ_ETH_PORT_SWITCH	= (1 << 1),
	LTQ_ETH_PORT_MAC	= (1 << 2),
};

struct ltq_eth_port_config {
	u8 num;
	u8 phy_addr;
	u16 flags;
	phy_interface_t phy_if;
	u8 rgmii_rx_delay;
	u8 rgmii_tx_delay;
};

struct ltq_eth_board_config {
	const struct ltq_eth_port_config *ports;
	int num_ports;
};

extern int ltq_eth_initialize(const struct ltq_eth_board_config *board_config);

#endif /* __LANTIQ_ETH_H__ */
