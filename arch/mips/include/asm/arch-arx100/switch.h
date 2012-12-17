/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 *   Copyright (C) 2012 Daniel Schwierzeck <daniel.schwierzeck@googlemail.com>
 */

#ifndef __ARX100_SWITCH_H__
#define __ARX100_SWITCH_H__

struct ar9_switch_regs {
	__be32	ps;		/* Port status*/
	__be32	p0_ctl;		/* Port 0 control */
	__be32	p1_ctl;		/* Port 1 control */
	__be32	p2_ctl;		/* Port 2 control */
	__be32	p0_vlan;	/* Port 0 VLAN control */
	__be32	p1_vlan;	/* Port 1 VLAN control */
	__be32	p2_vlan;	/* Port 2 VLAN control */
	__be32	p0_inctl;	/* Port 0 ingress control */
	__be32	p1_inctl;	/* Port 1 ingress control */
	__be32	p2_inctl;	/* Port 2 ingress control */
	u32	rsvd0[16];
	__be32	sw_gctl0;	/* Switch global control 0 */
	__be32	sw_gctl1;	/* Switch global control 1 */
	__be32	arp;		/* ARP/RARP */
	__be32	strm_ctl;	/* Storm control */
	__be32	rgmii_ctl;	/* RGMII/GMII port control */
	u32	rsvd1[4];
	__be32	pmac_hd_ctl;	/* PMAC header control */
	u32	rsvd2[15];
	__be32	mdio_ctrl;	/* MDIO indirect access control */
	__be32	mdio_data;	/* MDIO indirect read data */
};

#define BUILD_CHECK_AR9_REG(name, offset)	\
	BUILD_BUG_ON(offsetof(struct ar9_switch_regs, name) != (offset))

static inline void build_check_ar9_registers(void)
{
	BUILD_CHECK_AR9_REG(sw_gctl0, 0x68);
	BUILD_CHECK_AR9_REG(rgmii_ctl, 0x78);
	BUILD_CHECK_AR9_REG(pmac_hd_ctl, 0x8c);
	BUILD_CHECK_AR9_REG(mdio_ctrl, 0xcc);
	BUILD_CHECK_AR9_REG(mdio_data, 0xd0);
}

#define P0_CTL_FLP		(1 << 18)
#define P0_CTL_FLD		(1 << 17)

#define SW_GCTL0_SE		(1 << 31)

#define RGMII_CTL_P1_SHIFT	10
#define RGMII_CTL_P1_MASK	(0x3FF << RGMII_CTL_P1_SHIFT)
#define RGMII_CTL_P0_MASK	0x3FF
#define RGMII_CTL_P0IS_SHIFT	8
#define RGMII_CTL_P0IS_RGMII	(0x0 << RGMII_CTL_P0IS_SHIFT)
#define RGMII_CTL_P0IS_MII	(0x1 << RGMII_CTL_P0IS_SHIFT)
#define RGMII_CTL_P0IS_REVMII	(0x2 << RGMII_CTL_P0IS_SHIFT)
#define RGMII_CTL_P0IS_RMII	(0x3 << RGMII_CTL_P0IS_SHIFT)
#define RGMII_CTL_P0RDLY_SHIFT	6
#define RGMII_CTL_P0RDLY_0_0	(0x0 << RGMII_CTL_P0RDLY_SHIFT)
#define RGMII_CTL_P0RDLY_1_5	(0x1 << RGMII_CTL_P0RDLY_SHIFT)
#define RGMII_CTL_P0RDLY_1_75	(0x2 << RGMII_CTL_P0RDLY_SHIFT)
#define RGMII_CTL_P0RDLY_2_0	(0x3 << RGMII_CTL_P0RDLY_SHIFT)
#define RGMII_CTL_P0TDLY_SHIFT	4
#define RGMII_CTL_P0TDLY_0_0	(0x0 << RGMII_CTL_P0TDLY_SHIFT)
#define RGMII_CTL_P0TDLY_1_5	(0x1 << RGMII_CTL_P0TDLY_SHIFT)
#define RGMII_CTL_P0TDLY_1_75	(0x2 << RGMII_CTL_P0TDLY_SHIFT)
#define RGMII_CTL_P0TDLY_2_0	(0x3 << RGMII_CTL_P0TDLY_SHIFT)
#define RGMII_CTL_P0SPD_SHIFT	2
#define RGMII_CTL_P0SPD_10	(0x0 << RGMII_CTL_P0SPD_SHIFT)
#define RGMII_CTL_P0SPD_100	(0x1 << RGMII_CTL_P0SPD_SHIFT)
#define RGMII_CTL_P0SPD_1000	(0x2 << RGMII_CTL_P0SPD_SHIFT)
#define RGMII_CTL_P0DUP_FULL	(1 << 1)
#define RGMII_CTL_P0FCE_EN	(1 << 0)

#define PMAC_HD_CTL_AC		(1 << 18)

#define MDIO_CTRL_WD_SHIFT	16
#define MDIO_CTRL_MBUSY		(1 << 15)
#define MDIO_CTRL_OP_READ	(1 << 11)
#define MDIO_CTRL_OP_WRITE	(1 << 10)
#define MDIO_CTRL_PHYAD_SHIFT	5
#define MDIO_CTRL_PHYAD_MASK	(0x1f << MDIO_CTRL_PHYAD_SHIFT)
#define MDIO_CTRL_REGAD_MASK	0x1f

#endif /* __ARX100_SWITCH_H__ */
