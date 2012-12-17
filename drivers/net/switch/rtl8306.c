/*
 * Based on OpenWRT linux driver
 *
 * Copyright (C) 2011-2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 * Copyright (C) 2009 Felix Fietkau <nbd@openwrt.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <switch.h>
#include <miiphy.h>

#define RTL8306_REG_PAGE		16
#define RTL8306_REG_PAGE_LO		(1 << 15)
#define RTL8306_REG_PAGE_HI		(1 << 1) /* inverted */
#define RTL8306_CHIPID			0x5988

#define RTL8306_NUM_VLANS		16
#define RTL8306_NUM_PORTS		6
#define RTL8306_PORT_CPU		5
#define RTL8306_NUM_PAGES		4
#define RTL8306_NUM_REGS		32

#define RTL_VLAN_REGOFS(name) \
	(RTL_REG_VLAN1_##name - RTL_REG_VLAN0_##name)

#define RTL_PORT_REGOFS(name) \
	(RTL_REG_PORT1_##name - RTL_REG_PORT0_##name)

#define RTL_PORT_REG(id, reg) \
	(RTL_REG_PORT0_##reg + (id * RTL_PORT_REGOFS(reg)))

#define RTL_VLAN_REG(id, reg) \
	(RTL_REG_VLAN0_##reg + (id * RTL_VLAN_REGOFS(reg)))

enum {
	RTL_TYPE_S,
	RTL_TYPE_SD,
	RTL_TYPE_SDM,
};

struct rtl_reg {
	int page;
	int phy;
	int reg;
	int bits;
	int shift;
	int inverted;
};

enum rtl_regidx {
	RTL_REG_CHIPID,
	RTL_REG_CHIPVER,
	RTL_REG_CHIPTYPE,
	RTL_REG_CPUPORT,

	RTL_REG_EN_CPUPORT,
	RTL_REG_EN_TAG_OUT,
	RTL_REG_EN_TAG_CLR,
	RTL_REG_EN_TAG_IN,
	RTL_REG_TRAP_CPU,
	RTL_REG_TRUNK_PORTSEL,
	RTL_REG_EN_TRUNK,
	RTL_REG_RESET,
	RTL_REG_PHY_RESET,
	RTL_REG_CPU_LINKUP,

	RTL_REG_VLAN_ENABLE,
	RTL_REG_VLAN_FILTER,
	RTL_REG_VLAN_TAG_ONLY,
	RTL_REG_VLAN_TAG_AWARE,
#define RTL_VLAN_ENUM(id) \
	RTL_REG_VLAN##id##_VID, \
	RTL_REG_VLAN##id##_PORTMASK
	RTL_VLAN_ENUM(0),
	RTL_VLAN_ENUM(1),
	RTL_VLAN_ENUM(2),
	RTL_VLAN_ENUM(3),
	RTL_VLAN_ENUM(4),
	RTL_VLAN_ENUM(5),
	RTL_VLAN_ENUM(6),
	RTL_VLAN_ENUM(7),
	RTL_VLAN_ENUM(8),
	RTL_VLAN_ENUM(9),
	RTL_VLAN_ENUM(10),
	RTL_VLAN_ENUM(11),
	RTL_VLAN_ENUM(12),
	RTL_VLAN_ENUM(13),
	RTL_VLAN_ENUM(14),
	RTL_VLAN_ENUM(15),
#define RTL_PORT_ENUM(id) \
	RTL_REG_PORT##id##_PVID, \
	RTL_REG_PORT##id##_NULL_VID_REPLACE, \
	RTL_REG_PORT##id##_NON_PVID_DISCARD, \
	RTL_REG_PORT##id##_VID_INSERT, \
	RTL_REG_PORT##id##_TAG_INSERT, \
	RTL_REG_PORT##id##_LINK, \
	RTL_REG_PORT##id##_SPEED, \
	RTL_REG_PORT##id##_NWAY, \
	RTL_REG_PORT##id##_NRESTART, \
	RTL_REG_PORT##id##_DUPLEX, \
	RTL_REG_PORT##id##_RXEN, \
	RTL_REG_PORT##id##_TXEN, \
	RTL_REG_PORT##id##_LRNEN
	RTL_PORT_ENUM(0),
	RTL_PORT_ENUM(1),
	RTL_PORT_ENUM(2),
	RTL_PORT_ENUM(3),
	RTL_PORT_ENUM(4),
	RTL_PORT_ENUM(5),
};

static const struct rtl_reg rtl_regs[] = {
	[RTL_REG_CHIPID]         = { 0, 4, 30, 16,  0, 0 },
	[RTL_REG_CHIPVER]        = { 0, 4, 31,  8,  0, 0 },
	[RTL_REG_CHIPTYPE]       = { 0, 4, 31,  2,  8, 0 },

	/* CPU port number */
	[RTL_REG_CPUPORT]        = { 2, 4, 21,  3,  0, 0 },
	/* Enable CPU port function */
	[RTL_REG_EN_CPUPORT]     = { 3, 2, 21,  1, 15, 1 },
	/* Enable CPU port tag insertion */
	[RTL_REG_EN_TAG_OUT]     = { 3, 2, 21,  1, 12, 0 },
	/* Enable CPU port tag removal */
	[RTL_REG_EN_TAG_CLR]     = { 3, 2, 21,  1, 11, 0 },
	/* Enable CPU port tag checking */
	[RTL_REG_EN_TAG_IN]      = { 0, 4, 21,  1,  7, 0 },
	[RTL_REG_EN_TRUNK]       = { 0, 0, 19,  1, 11, 1 },
	[RTL_REG_TRUNK_PORTSEL]  = { 0, 0, 16,  1,  6, 1 },
	[RTL_REG_RESET]          = { 0, 0, 16,  1, 12, 0 },
	[RTL_REG_PHY_RESET]	 = { 0, 0,  0,  1, 15, 0 },
	[RTL_REG_CPU_LINKUP]	 = { 0, 6, 22,  1, 15, 0 },
	[RTL_REG_TRAP_CPU]       = { 3, 2, 22,  1,  6, 0 },

	[RTL_REG_VLAN_TAG_ONLY]  = { 0, 0, 16,  1,  8, 1 },
	[RTL_REG_VLAN_FILTER]    = { 0, 0, 16,  1,  9, 1 },
	[RTL_REG_VLAN_TAG_AWARE] = { 0, 0, 16,  1, 10, 1 },
	[RTL_REG_VLAN_ENABLE]    = { 0, 0, 18,  1,  8, 1 },

#define RTL_VLAN_REGS(id, phy, page, regofs) \
	[RTL_REG_VLAN##id##_VID] = { page, phy, 25 + regofs, 12, 0, 0 }, \
	[RTL_REG_VLAN##id##_PORTMASK] = { page, phy, 24 + regofs, 6, 0, 0 }
	RTL_VLAN_REGS( 0, 0, 0, 0),
	RTL_VLAN_REGS( 1, 1, 0, 0),
	RTL_VLAN_REGS( 2, 2, 0, 0),
	RTL_VLAN_REGS( 3, 3, 0, 0),
	RTL_VLAN_REGS( 4, 4, 0, 0),
	RTL_VLAN_REGS( 5, 0, 1, 2),
	RTL_VLAN_REGS( 6, 1, 1, 2),
	RTL_VLAN_REGS( 7, 2, 1, 2),
	RTL_VLAN_REGS( 8, 3, 1, 2),
	RTL_VLAN_REGS( 9, 4, 1, 2),
	RTL_VLAN_REGS(10, 0, 1, 4),
	RTL_VLAN_REGS(11, 1, 1, 4),
	RTL_VLAN_REGS(12, 2, 1, 4),
	RTL_VLAN_REGS(13, 3, 1, 4),
	RTL_VLAN_REGS(14, 4, 1, 4),
	RTL_VLAN_REGS(15, 0, 1, 6),

#define REG_PORT_SETTING(port, phy) \
	[RTL_REG_PORT##port##_SPEED] = { 0, phy, 0, 1, 13, 0 }, \
	[RTL_REG_PORT##port##_NWAY] = { 0, phy, 0, 1, 12, 0 }, \
	[RTL_REG_PORT##port##_NRESTART] = { 0, phy, 0, 1, 9, 0 }, \
	[RTL_REG_PORT##port##_DUPLEX] = { 0, phy, 0, 1, 8, 0 }, \
	[RTL_REG_PORT##port##_TXEN] = { 0, phy, 24, 1, 11, 0 }, \
	[RTL_REG_PORT##port##_RXEN] = { 0, phy, 24, 1, 10, 0 }, \
	[RTL_REG_PORT##port##_LRNEN] = { 0, phy, 24, 1, 9, 0 }, \
	[RTL_REG_PORT##port##_LINK] = { 0, phy, 1, 1, 2, 0 }, \
	[RTL_REG_PORT##port##_NULL_VID_REPLACE] = { 0, phy, 22, 1, 12, 0 }, \
	[RTL_REG_PORT##port##_NON_PVID_DISCARD] = { 0, phy, 22, 1, 11, 0 }, \
	[RTL_REG_PORT##port##_VID_INSERT] = { 0, phy, 22, 2, 9, 0 }, \
	[RTL_REG_PORT##port##_TAG_INSERT] = { 0, phy, 22, 2, 0, 0 }

	REG_PORT_SETTING(0, 0),
	REG_PORT_SETTING(1, 1),
	REG_PORT_SETTING(2, 2),
	REG_PORT_SETTING(3, 3),
	REG_PORT_SETTING(4, 4),
	REG_PORT_SETTING(5, 6),

#define REG_PORT_PVID(phy, page, regofs) \
	{ page, phy, 24 + regofs, 4, 12, 0 }
	[RTL_REG_PORT0_PVID] = REG_PORT_PVID(0, 0, 0),
	[RTL_REG_PORT1_PVID] = REG_PORT_PVID(1, 0, 0),
	[RTL_REG_PORT2_PVID] = REG_PORT_PVID(2, 0, 0),
	[RTL_REG_PORT3_PVID] = REG_PORT_PVID(3, 0, 0),
	[RTL_REG_PORT4_PVID] = REG_PORT_PVID(4, 0, 0),
	[RTL_REG_PORT5_PVID] = REG_PORT_PVID(0, 1, 2),
};

static void rtl_set_page(struct mii_dev *bus, unsigned int page)
{
	u16 pgsel;

	BUG_ON(page > RTL8306_NUM_PAGES);

	pgsel = bus->read(bus, 0, MDIO_DEVAD_NONE, RTL8306_REG_PAGE);
	pgsel &= ~(RTL8306_REG_PAGE_LO | RTL8306_REG_PAGE_HI);

	if (page & (1 << 0))
		pgsel |= RTL8306_REG_PAGE_LO;

	if (!(page & (1 << 1))) /* bit is inverted */
		pgsel |= RTL8306_REG_PAGE_HI;

	bus->write(bus, 0, MDIO_DEVAD_NONE, RTL8306_REG_PAGE, pgsel);

}

static __maybe_unused int rtl_w16(struct mii_dev *bus, unsigned int page, unsigned int phy,
			unsigned int reg, u16 val)
{
	rtl_set_page(bus, page);

	bus->write(bus, phy, MDIO_DEVAD_NONE, reg, val);
	bus->read(bus, phy, MDIO_DEVAD_NONE, reg); /* flush */

	return 0;
}

static int rtl_r16(struct mii_dev *bus, unsigned int page, unsigned int phy,
			unsigned int reg)
{
	rtl_set_page(bus, page);

	return bus->read(bus, phy, MDIO_DEVAD_NONE, reg);
}

static u16 rtl_rmw(struct mii_dev *bus, unsigned int page, unsigned int phy,
			unsigned int reg, u16 mask, u16 val)
{
	u16 r;

	rtl_set_page(bus, page);

	r = bus->read(bus, phy, MDIO_DEVAD_NONE, reg);
	r &= ~mask;
	r |= val;
	bus->write(bus, phy, MDIO_DEVAD_NONE, reg, r);

	return bus->read(bus, phy, MDIO_DEVAD_NONE, reg); /* flush */
}

static int rtl_get(struct mii_dev *bus, enum rtl_regidx s)
{
	const struct rtl_reg *r = &rtl_regs[s];
	u16 val;

	BUG_ON(s >= ARRAY_SIZE(rtl_regs));

	if (r->bits == 0) /* unimplemented */
		return 0;

	val = rtl_r16(bus, r->page, r->phy, r->reg);

	if (r->shift > 0)
		val >>= r->shift;

	if (r->inverted)
		val = ~val;

	val &= (1 << r->bits) - 1;

	return val;
}

static __maybe_unused int rtl_set(struct mii_dev *bus, enum rtl_regidx s, unsigned int val)
{
	const struct rtl_reg *r = &rtl_regs[s];
	u16 mask = 0xffff;

	BUG_ON(s >= ARRAY_SIZE(rtl_regs));

	if (r->bits == 0) /* unimplemented */
		return 0;

	if (r->shift > 0)
		val <<= r->shift;

	if (r->inverted)
		val = ~val;

	if (r->bits != 16) {
		mask = (1 << r->bits) - 1;
		mask <<= r->shift;
	}

	val &= mask;

	return rtl_rmw(bus, r->page, r->phy, r->reg, mask, val);
}

static void rtl_port_set_enable(struct switch_device *dev, int port, int enabled)
{
	struct mii_dev *bus = dev->bus;
	
	rtl_set(bus, RTL_PORT_REG(port, RXEN), enabled);
	rtl_set(bus, RTL_PORT_REG(port, TXEN), enabled);
	
	if ((port >= 5) || !enabled)
		return;
	
	/* Restart autonegotiation if enabled */
	rtl_set(bus, RTL_PORT_REG(port, NRESTART), 1);
}

static int rtl8306_probe(struct switch_device *dev)
{
	struct mii_dev *bus = dev->bus;
	unsigned int chipid, chipver, chiptype;

	chipid = rtl_get(bus, RTL_REG_CHIPID);
	chipver = rtl_get(bus, RTL_REG_CHIPVER);
	chiptype = rtl_get(bus, RTL_REG_CHIPTYPE);

	debug("%s: chipid %x, chipver %x, chiptype %x\n",
		__func__, chipid, chipver, chiptype);

	if (chipid == RTL8306_CHIPID)
		return 0;

	return 1;
}

static void rtl8306_setup(struct switch_device *dev)
{
	struct mii_dev *bus = dev->bus;
	int cpu_mask = (1 << dev->cpu_port);
	int i;
	int trunk_en, trunk_psel;
	int phy_nway, phy_speed, phy_dup;

	rtl_set(bus, RTL_REG_VLAN_ENABLE, 0);
	rtl_set(bus, RTL_REG_VLAN_FILTER, 0);
	rtl_set(bus, RTL_REG_EN_TRUNK, 0);
	rtl_set(bus, RTL_REG_TRUNK_PORTSEL, 0);

	/* Initialize cpu port settings */
	rtl_set(bus, RTL_REG_CPUPORT, dev->cpu_port);
	rtl_set(bus, RTL_REG_EN_CPUPORT, 1);

	rtl_set(bus, RTL_REG_EN_TAG_OUT, 0);
	rtl_set(bus, RTL_REG_EN_TAG_IN, 0);
	rtl_set(bus, RTL_REG_EN_TAG_CLR, 0);

	/* Reset all vlans */
	for (i = 0; i < RTL8306_NUM_VLANS; i++) {
		rtl_set(bus, RTL_VLAN_REG(i, VID), i);
		rtl_set(bus, RTL_VLAN_REG(i, PORTMASK), 0);
	}
	
	/* Default to port isolation */
	for (i = 0; i < RTL8306_NUM_PORTS; i++) {
		unsigned long mask;
		
		if ((1 << i) == cpu_mask)
			mask = ((1 << RTL8306_NUM_PORTS) - 1) & ~cpu_mask; /* all bits set */
		else
			mask = cpu_mask | (1 << i);

		rtl_set(bus, RTL_VLAN_REG(i, PORTMASK), mask);
		rtl_set(bus, RTL_PORT_REG(i, PVID), i);
		rtl_set(bus, RTL_PORT_REG(i, NULL_VID_REPLACE), 1);
		rtl_set(bus, RTL_PORT_REG(i, VID_INSERT), 1);
		rtl_set(bus, RTL_PORT_REG(i, TAG_INSERT), 3);
	}

	/* PHY save */
	phy_nway = rtl_get(bus, RTL_PORT_REG(5, NWAY));
	phy_speed = rtl_get(bus, RTL_PORT_REG(5, SPEED));
	phy_dup = rtl_get(bus, RTL_PORT_REG(5, DUPLEX));

	/* Disable RX/TX from PHYs */
	for (i = 0; i < RTL8306_NUM_PORTS - 1; i++) {
		rtl_port_set_enable(dev, i, 0);
	}

	/* Save trunking status */
	trunk_en = rtl_get(bus, RTL_REG_EN_TRUNK);
	trunk_psel = rtl_get(bus, RTL_REG_TRUNK_PORTSEL);

	/*
	 * Trunk port 3 and 4
	 * Big WTF, but RealTek seems to do it
	 */
	rtl_set(bus, RTL_REG_EN_TRUNK, 1);
	rtl_set(bus, RTL_REG_TRUNK_PORTSEL, 1);

	rtl_set(bus, RTL_REG_RESET, 1);

	/* Wait for the reset to complete, but don't wait for too long */
	for (i = 0; i < 10; i++) {
		if (rtl_get(bus, RTL_REG_RESET) == 0)
			break;

		__udelay(1000);
	}

	/* Enable RX/TX from PHYs */
	for (i = 0; i < RTL8306_NUM_PORTS - 1; i++) {
		rtl_port_set_enable(dev, i, 1);
	}

	/* Restore trunking settings */
	rtl_set(bus, RTL_REG_EN_TRUNK, trunk_en);
	rtl_set(bus, RTL_REG_TRUNK_PORTSEL, trunk_psel);

	/* PHY restore */
	rtl_set(bus, RTL_PORT_REG(5, NWAY), phy_nway);
	rtl_set(bus, RTL_PORT_REG(5, SPEED), phy_speed);
	rtl_set(bus, RTL_PORT_REG(5, DUPLEX), phy_dup);

	rtl_set(bus, RTL_REG_CPU_LINKUP, 1);
}

static struct switch_driver rtl8306_drv = {
	.name = "rtl8306",
};

void switch_rtl8306_init(void)
{
	/* For archs with manual relocation */
	rtl8306_drv.probe = rtl8306_probe;
	rtl8306_drv.setup = rtl8306_setup;

	switch_driver_register(&rtl8306_drv);
}
