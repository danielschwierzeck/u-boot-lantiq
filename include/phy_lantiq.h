/*
 * Copyright (C) 2015-2020 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __PHY_LANTIQ_H__
#define __PHY_LANTIQ_H__

#include <phy.h>

#define LTQ_PHY_MMD_LED0H	0x1e2
#define LTQ_PHY_MMD_LED0L	0x1e3
#define LTQ_PHY_MMD_LED1H	0x1e4
#define LTQ_PHY_MMD_LED1L	0x1e5
#define LTQ_PHY_MMD_LED2H	0x1e6
#define LTQ_PHY_MMD_LED2L	0x1e7

int ltq_phy_mmd_read(struct phy_device *phydev, u16 regnum);
int ltq_phy_mmd_write(struct phy_device *phydev, u16 regnum, u16 val);

int ltq_phy_board_init(struct phy_device *phydev);

#endif /* __PHY_LANTIQ_H__ */
