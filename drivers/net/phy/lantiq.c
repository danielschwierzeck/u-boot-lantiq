/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#define DEBUG

#include <common.h>
#include <miiphy.h>

#define ADVERTIZE_MPD		(1 << 10)

DECLARE_GLOBAL_DATA_PTR;

/*
 * Update link status.
 *
 * Based on genphy_update_link in phylib.c
 */
static int ltq_phy_update_link(struct phy_device *phydev)
{
	unsigned int mii_reg;

	mii_reg = phy_read(phydev, MDIO_DEVAD_NONE, MII_BMSR);

	/*
	 * If we already saw the link up, and it hasn't gone down, then
	 * we don't need to wait for autoneg again
	 */
	if (phydev->link && mii_reg & BMSR_LSTATUS)
		return 0;

	if ((mii_reg & BMSR_ANEGCAPABLE) && !(mii_reg & BMSR_ANEGCOMPLETE)) {
		phydev->link = 0;
		return 0;
	} else {
		/* Read the link a second time to clear the latched state */
		mii_reg = phy_read(phydev, MDIO_DEVAD_NONE, MII_BMSR);

		if (mii_reg & BMSR_LSTATUS)
			phydev->link = 1;
		else
			phydev->link = 0;
	}

	return 0;
}

/*
 * Update speed and duplex.
 *
 * Based on genphy_parse_link in phylib.c
 */
static int ltq_phy_parse_link(struct phy_device *phydev)
{
	unsigned int mii_reg;

	mii_reg = phy_read(phydev, MDIO_DEVAD_NONE, MII_BMSR);

	/* We're using autonegotiation */
	if (mii_reg & BMSR_ANEGCAPABLE) {
		u32 lpa = 0;
		u32 gblpa = 0;

		/* Check for gigabit capability */
		if (mii_reg & BMSR_ERCAP) {
			/* We want a list of states supported by
			 * both PHYs in the link
			 */
			gblpa = phy_read(phydev, MDIO_DEVAD_NONE, MII_STAT1000);
			gblpa &= phy_read(phydev,
					MDIO_DEVAD_NONE, MII_CTRL1000) << 2;
		}

		/* Set the baseline so we only have to set them
		 * if they're different
		 */
		phydev->speed = SPEED_10;
		phydev->duplex = DUPLEX_HALF;

		/* Check the gigabit fields */
		if (gblpa & (PHY_1000BTSR_1000FD | PHY_1000BTSR_1000HD)) {
			phydev->speed = SPEED_1000;

			if (gblpa & PHY_1000BTSR_1000FD)
				phydev->duplex = DUPLEX_FULL;

			/* We're done! */
			return 0;
		}

		lpa = phy_read(phydev, MDIO_DEVAD_NONE, MII_ADVERTISE);
		lpa &= phy_read(phydev, MDIO_DEVAD_NONE, MII_LPA);

		if (lpa & (LPA_100FULL | LPA_100HALF)) {
			phydev->speed = SPEED_100;

			if (lpa & LPA_100FULL)
				phydev->duplex = DUPLEX_FULL;

		} else if (lpa & LPA_10FULL)
			phydev->duplex = DUPLEX_FULL;
	} else {
		u32 bmcr = phy_read(phydev, MDIO_DEVAD_NONE, MII_BMCR);

		phydev->speed = SPEED_10;
		phydev->duplex = DUPLEX_HALF;

		if (bmcr & BMCR_FULLDPLX)
			phydev->duplex = DUPLEX_FULL;

		if (bmcr & BMCR_SPEED1000)
			phydev->speed = SPEED_1000;
		else if (bmcr & BMCR_SPEED100)
			phydev->speed = SPEED_100;
	}

	return 0;
}

static int ltq_phy_config(struct phy_device *phydev)
{
	u16 val;

	/* Advertise as Multi-port device */
	val = phy_read(phydev, MDIO_DEVAD_NONE, MII_CTRL1000);
	val |= ADVERTIZE_MPD;
	phy_write(phydev, MDIO_DEVAD_NONE, MII_CTRL1000, val);

	genphy_config_aneg(phydev);

	return 0;
}

static int ltq_phy_startup(struct phy_device *phydev)
{
	/*
	 * Update PHY status immediately without any delays as genphy_startup
	 * does because VRX200 switch needs to be configured dependent
	 * on this information.
	 */
	ltq_phy_update_link(phydev);
	ltq_phy_parse_link(phydev);

	debug("ltq_phy: addr %d, link %d, speed %d, duplex %d\n",
		phydev->addr, phydev->link, phydev->speed, phydev->duplex);

	return 0;
}

static struct phy_driver xrx_11g_13_driver = {
	.name = "Lantiq XWAY XRX PHY11G v1.3 and earlier",
	.uid = 0x030260D0,
	.mask = 0xFFFFFFF0,
	.features = PHY_GBIT_FEATURES,
	.config = ltq_phy_config,
	.startup = ltq_phy_startup,
	.shutdown = genphy_shutdown,
};

static struct phy_driver xrx_11g_14_driver = {
	.name = "Lantiq XWAY XRX PHY11G v1.4 and later",
	.uid = 0xd565a408,
	.mask = 0xFFFFFFF8,
	.features = PHY_GBIT_FEATURES,
	.config = ltq_phy_config,
	.startup = ltq_phy_startup,
	.shutdown = genphy_shutdown,
};

static struct phy_driver xrx_22f_14_driver = {
	.name = "Lantiq XWAY XRX PHY22F v1.4 and later",
	.uid = 0xd565a418,
	.mask = 0xFFFFFFF8,
	.features = PHY_BASIC_FEATURES,
	.config = ltq_phy_config,
	.startup = ltq_phy_startup,
	.shutdown = genphy_shutdown,
};

static struct phy_driver pef7071_driver = {
	.name = "Lantiq XWAY PEF7071",
	.uid = 0xd565a400,
	.mask = 0xFFFFFFFF,
	.features = PHY_GBIT_FEATURES,
	.config = ltq_phy_config,
	.startup = ltq_phy_startup,
	.shutdown = genphy_shutdown,
};

static struct phy_driver xrx_genphy_driver = {
	.name = "Generic PHY at Lantiq XWAY XRX switch",
	.uid = 0,
	.mask = 0,
	.features = 0,
	.config = genphy_config,
	.startup = ltq_phy_startup,
	.shutdown = genphy_shutdown,
};

int phy_lantiq_init(void)
{
#ifdef CONFIG_NEEDS_MANUAL_RELOC
	xrx_11g_13_driver.config = ltq_phy_config;
	xrx_11g_13_driver.startup = ltq_phy_startup;
	xrx_11g_13_driver.shutdown = genphy_shutdown;
	xrx_11g_13_driver.name += gd->reloc_off;

	xrx_11g_14_driver.config = ltq_phy_config;
	xrx_11g_14_driver.startup = ltq_phy_startup;
	xrx_11g_14_driver.shutdown = genphy_shutdown;
	xrx_11g_14_driver.name += gd->reloc_off;

	xrx_22f_14_driver.config = ltq_phy_config;
	xrx_22f_14_driver.startup = ltq_phy_startup;
	xrx_22f_14_driver.shutdown = genphy_shutdown;
	xrx_22f_14_driver.name += gd->reloc_off;

	pef7071_driver.config = ltq_phy_config;
	pef7071_driver.startup = ltq_phy_startup;
	pef7071_driver.shutdown = genphy_shutdown;
	pef7071_driver.name += gd->reloc_off;

	xrx_genphy_driver.config = genphy_config;
	xrx_genphy_driver.startup = ltq_phy_startup;
	xrx_genphy_driver.shutdown = genphy_shutdown;
	xrx_genphy_driver.name += gd->reloc_off;
#endif

	phy_register(&xrx_11g_13_driver);
	phy_register(&xrx_11g_14_driver);
	phy_register(&xrx_22f_14_driver);
	phy_register(&pef7071_driver);
	phy_register(&xrx_genphy_driver);

	return 0;
}
