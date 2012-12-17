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

#ifndef __VR9_SWITCH_H__
#define __VR9_SWITCH_H__

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
	u32	rsvd0[41];
	__be32	mdio_ctrl;	/* MDIO indirect access control */
	__be32	mdio_data;	/* MDIO indirect read data */
};

#define BUILD_CHECK_AR9_REG(name, offset)	\
	BUILD_BUG_ON(offsetof(struct ar9_switch_regs, name) != (offset))

static inline void build_check_ar9_registers(void)
{
	BUILD_CHECK_AR9_REG(mdio_ctrl, 0xcc);
	BUILD_CHECK_AR9_REG(mdio_data, 0xd0);
}

#define MDIO_CTRL_WD_SHIFT	16
#define MDIO_CTRL_MBUSY		(1 << 15)
#define MDIO_CTRL_OP_READ	(1 << 11)
#define MDIO_CTRL_OP_WRITE	(1 << 10)
#define MDIO_CTRL_PHYAD_SHIFT	5
#define MDIO_CTRL_PHYAD_MASK	(0x1f << MDIO_CTRL_PHYAD_SHIFT)
#define MDIO_CTRL_REGAD_MASK	0x1f

#endif
