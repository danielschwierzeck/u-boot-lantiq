/*
 * Copyright (C) 2015-2016 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __XRX300_SWITCH_H__
#define __XRX300_SWITCH_H__

/* Switch core registers */
struct ar10_switch_core_regs {
	u32 swres;		/* switch reset control */
	u32 rsvd0[0x2];
	u32 ssb_mode;		/* Shared segment buffer mode */
	u32 ssb_addr;		/* Shared segment buffer address */
	u32 ssb_data;		/* Shared segment buffer data */
	/* TODO: implement registers */
	u32 rsvd1[0x39];
};

/* Switch buffer management registers */
struct ar10_switch_bm_regs {
	struct bm_core {
		u32 ram_val4;	/* RAM value 3 */
		u32 ram_val3;	/* RAM value 3 */
		u32 ram_val2;	/* RAM value 2 */
		u32 ram_val1;	/* RAM value 1 */
		u32 ram_val0;	/* RAM value 0 */
		u32 ram_addr;	/* RAM address */
		u32 ram_ctrl;	/* RAM access control */
		u32 fsqm_gctrl;	/* Free segment queue global control */
		u32 cons_sel;	/* Number of consumed segments */
		u32 cons_pkt;	/* Number of consumed packet pointers */
		u32 gctrl;	/* Global control */
		u32 queue_gctrl;/* Queue manager global control */
		/* TODO: implement registers */
		u32 rsvd0[0x35];
	} core;

	struct bm_port {
		u32 pcfg;	/* Port config */
		u32 rmon_ctrl;	/* RMON control */
	} port[13];

	u32 rsvd0[0x66];

	struct bm_queue {
		u32 rsvd0;
		u32 pqm_rs;	/* Packet queue manager rate shape assignment */
	} queue[32];

	struct bm_shaper {
		u32 ctrl;	/* Rate shaper control */
		u32 cbs;	/* Rate shaper committed burst size */
		u32 ibs;	/* Rate shaper instantaneous burst size */
		u32 cir_ext;	/* Rate shaper rate exponent */
		u32 cir_mant;	/* Rate shaper rate mantissa */
	} shaper[16];

	u32 rsvd1[0x2a8];
};

/* Switch parser and classification engine registers */
struct ar10_switch_pce_regs {
	struct pce_core {
		u32 tbl_key[16];/* Table key data */
		u32 tbl_mask;	/* Table mask */
		u32 tbl_val[5];	/* Table value */
		u32 tbl_addr;	/* Table entry address */
		u32 tbl_ctrl;	/* Table access control */
		u32 tbl_stat;	/* Table general status */
		u32 age_0;	/* Aging counter config 0 */
		u32 age_1;	/* Aging counter config 1 */
		u32 pmap_1;	/* Port map (monitoring) */
		u32 pmap_2;	/* Port map (multicast) */
		u32 pmap_3;	/* Port map (unknown unicast) */
		u32 gctrl_0;	/* Global control 0 */
		u32 gctrl_1;	/* Global control 1 */
		u32 tcm_gctrl;	/* Three-color marker global control */
		u32 igmp_ctrl;	/* IGMP control */
		u32 igmp_drpm;	/* IGMP default router port map */
		u32 igmp_age_0;	/* IGMP aging 0 */
		u32 igmp_age_1;	/* IGMP aging 1 */
		u32 igmp_stat;	/* IGMP status */
		u32 wol_gctrl;	/* Wake-on-LAN control */
		u32 wol_da_0;	/* Wake-on-LAN destination address 0 */
		u32 wol_da_1;	/* Wake-on-LAN destination address 1 */
		u32 wol_da_2;	/* Wake-on-LAN destination address 2 */
		u32 wol_pw_0;	/* Wake-on-LAN password 0 */
		u32 wol_pw_1;	/* Wake-on-LAN password 1 */
		u32 wol_pw_2;	/* Wake-on-LAN password 2 */
		u32 ier_0;	/* PCE global interrupt enable 0 */
		u32 ier_1;	/* PCE global interrupt enable 1 */
		u32 isr_0;	/* PCE global interrupt status 0 */
		u32 isr_1;	/* PCE global interrupt status 1 */
		u32 parser_stat;/* Parser status */
		u32 rsvd0[0x6];
	} core;

	u32 rsvd0[0x10];

	struct pce_port {
		u32 pctrl_0;	/* Port control 0 */
		u32 pctrl_1;	/* Port control 1 */
		u32 pctrl_2;	/* Port control 2 */
		u32 pctrl_3;	/* Port control 3 */
		u32 wol_ctrl;	/* Wake-on-LAN control */
		u32 vlan_ctrl;	/* VLAN control */
		u32 def_pvid;	/* Default port VID */
		u32 pstat;	/* Port status */
		u32 pier;	/* Interrupt enable */
		u32 pisr;	/* Interrupt status */
	} port[13];

	u32 rsvd1[0x7e];

	struct pce_meter {
		/* TODO: implement registers */
		u32 rsvd0[0x7];
	} meter[8];

	u32 rsvd2[0x308];
};

static inline unsigned int to_pce_tbl_key_id(unsigned int id)
{
	BUG_ON(id > 15);

	return 15 - id;
}

static inline unsigned int to_pce_tbl_value_id(unsigned int id)
{
	BUG_ON(id > 4);

	return 4 - id;
}

/* Switch ethernet MAC registers */
struct ar10_switch_mac_regs {
	struct mac_core {
		u32 test;		/* MAC test */
		u32 pfad_cfg;		/* Pause frame source address config */
		u32 pfsa_0;		/* Pause frame source address 0 */
		u32 pfsa_1;		/* Pause frame source address 1 */
		u32 pfsa_2;		/* Pause frame source address 2 */
		u32 flen;		/* Frame length */
		u32 vlan_etype_0;	/* VLAN ethertype 0 */
		u32 vlan_etype_1;	/* VLAN ethertype 1 */
		u32 ier;		/* Interrupt enable */
		u32 isr;		/* Interrupt status */
		u32 rsvd0[0x36];
	} core;

	struct mac_port {
		u32 pstat;		/* Port status */
		u32 pisr;		/* Interrupt status */
		u32 pier;		/* Interrupt enable */
		u32 ctrl_0;		/* Control 0 */
		u32 ctrl_1;		/* Control 1 */
		u32 ctrl_2;		/* Control 2 */
		u32 ctrl_3;		/* Control 3 */
		u32 ctrl_4;		/* Control 4 */
		u32 ctrl_5;		/* Control 5 */
		u32 lpitimer0;		/* LPI timer 0 */
		u32 lpitimer1;		/* LPI timer 1 */
		u32 testen;		/* Test enable */
	} port[13];

	u32 rsvd0[0xa4];
};

/* Switch Fetch DMA registers */
struct ar10_switch_fdma_regs {
	struct fdma_core {
		u32 ctrl;		/* FDMA control */
		u32 stetype;		/* Special tag ethertype control */
		u32 vtetype;		/* VLAN tag ethertype control */
		u32 stat;		/* FDMA status */
		u32 ier;		/* FDMA interrupt enable */
		u32 isr;		/* FDMA interrupt status */
	} core;

	u32 rsvd0[0x3a];

	struct fdma_port {
		u32 pctrl;		/* Port control */
		u32 prio;		/* Port priority */
		u32 pstat_0;		/* Port status 0 */
		u32 pstat_1;		/* Port status 1 */
		u32 tstamp_0;		/* Egress time stamp 0 */
		u32 tstamp_1;		/* Egress time stamp 1 */
	} port[13];

	u32 rsvd1[0x72];
};

/* Switch Store DMA registers */
struct ar10_switch_sdma_regs {
	struct sdma_core {
		u32 ctrl;		/* SDMA Control */
		u32 fcthr_1;		/* Flow control threshold 1 */
		u32 rsvd0;
		u32 fcthr_3;		/* Flow control threshold 3 */
		u32 fcthr_4;		/* Flow control threshold 4 */
		u32 fcthr_5;		/* Flow control threshold 5 */
		u32 fcthr_6;		/* Flow control threshold 6 */
		u32 fcthr_7;		/* Flow control threshold 7 */
		u32 stat_0;		/* SDMA status 0 */
		u32 stat_1;		/* SDMA status 1 */
		u32 stat_2;		/* SDMA status 2 */
		u32 ier;		/* SDMA interrupt enable */
		u32 isr;		/* SDMA interrupt status */
	} core;

	u32 rsvd0[0x73];

	struct sdma_port {
		u32 pctrl;		/* Port control */
		u32 prio;		/* Port priority */
		u32 pstat_0;		/* Port status 0 */
		u32 pstat_1;		/* Port status 1 */
		u32 tstamp_0;		/* Ingress time stamp 0 */
		u32 tstamp_1;		/* Ingress time stamp 1 */
	} port[13];

	u32 rsvd1[0x32];
};

/* Switch MDIO control and status registers */
struct ar10_switch_mdio_regs {
	u32 glob_ctrl;		/* Global control 0 */
	u32 rsvd0[7];
	u32 mdio_ctrl;		/* MDIO control */
	u32 mdio_read;		/* MDIO read data */
	u32 mdio_write;		/* MDIO write data */
	u32 mdc_cfg_0;		/* MDC clock configuration 0 */
	u32 mdc_cfg_1;		/* MDC clock configuration 1 */
	u32 rsvd1[0x3];
	u32 phy_addr[6];	/* PHY address port 5..0 */
	u32 mdio_stat[6];	/* MDIO PHY polling status port 0..5 */
	u32 aneg_eee[6];	/* EEE auto-neg overrides port 0..5 */
	u32 rsvd2[0x14];
};

static inline unsigned int to_mdio_phyaddr_id(unsigned int id)
{
	BUG_ON(id > 5);

	return 5 - id;
}

/* Switch xMII control registers */
struct ar10_switch_mii_regs {
	u32 mii_cfg0;		/* xMII port 0 configuration */
	u32 pcdu0;		/* Port 0 clock delay configuration */
	u32 rsvd0[0x4];
	u32 mii_cfg3;		/* xMII port 3 configuration */
	u32 rsvd1[0x3];
	u32 mii_cfg5;		/* xMII port 5 configuration */
	u32 pcdu5;		/* Port 5 clock delay configuration */
	u32 rsvd2[0x14];
	u32 rxb_ctl_0;		/* Port 0 receive buffer control */
	u32 rsvd3[0x4];
	u32 rxb_ctl_5;		/* Port 5 receive buffer control */
	u32 rsvd4[0x26];
};

/* Switch Pseudo-MAC registers */
struct ar10_switch_pmac_regs {
	u32 hd_ctl;		/* PMAC header control */
	u32 tl;			/* PMAC type/length */
	u32 sa1;		/* PMAC source address 1 */
	u32 sa2;		/* PMAC source address 2 */
	u32 sa3;		/* PMAC source address 3 */
	u32 da1;		/* PMAC destination address 1 */
	u32 da2;		/* PMAC destination address 2 */
	u32 da3;		/* PMAC destination address 3 */
	u32 vlan;		/* PMAC VLAN */
	u32 rx_ipg;		/* PMAC interpacket gap in RX direction */
	u32 st_etype;		/* PMAC special tag ethertype */
	u32 ewan;		/* PMAC ethernet WAN group */
	u32 ctl;		/* PMAC control */
	u32 rsvd0[0x2];
};

struct ar10_switch_regs {
	struct ar10_switch_core_regs core;
	struct ar10_switch_bm_regs bm;
	struct ar10_switch_pce_regs pce;
	struct ar10_switch_mac_regs mac;
	struct ar10_switch_fdma_regs fdma;
	struct ar10_switch_sdma_regs sdma;
	struct ar10_switch_mdio_regs mdio;
	struct ar10_switch_mii_regs mii;
	struct ar10_switch_pmac_regs pmac;
};

static inline void *to_pce_tbl_key(struct ar10_switch_regs *regs,
						unsigned int id)
{
	return &regs->pce.core.tbl_key[to_pce_tbl_key_id(id)];
}

static inline void *to_pce_tbl_value(struct ar10_switch_regs *regs,
						unsigned int id)
{
	return &regs->pce.core.tbl_val[to_pce_tbl_value_id(id)];
}

static inline void *to_mac_ctrl(struct ar10_switch_regs *regs,
					unsigned int id, unsigned int ctrl)
{
	struct mac_port *mac = &regs->mac.port[id];

	switch (ctrl) {
	case 0:
		return &mac->ctrl_0;
	case 1:
		return &mac->ctrl_1;
	case 2:
		return &mac->ctrl_2;
	case 3:
		return &mac->ctrl_3;
	case 4:
		return &mac->ctrl_4;
	case 5:
		return &mac->ctrl_5;
	default:
		return NULL;
	}
}

static inline void *to_mdio_phyaddr(struct ar10_switch_regs *regs,
					unsigned int id)
{
	return &regs->mdio.phy_addr[to_mdio_phyaddr_id(id)];
}

static inline void *to_mii_miicfg(struct ar10_switch_regs *regs,
					unsigned int id)
{
	switch (id) {
	case 0:
		return &regs->mii.mii_cfg0;
	case 3:
		return &regs->mii.mii_cfg3;
	case 5:
		return &regs->mii.mii_cfg5;
	default:
		return NULL;
	}
}

static inline void *to_mii_pcdu(struct ar10_switch_regs *regs,
					unsigned int id)
{
	switch (id) {
	case 0:
		return &regs->mii.pcdu0;
	case 5:
		return &regs->mii.pcdu5;
	default:
		return NULL;
	}
}

#define AR10_SWITCH_REG_OFFSET(reg)	(4 * (reg))

#define BUILD_CHECK_AR10_REG(name, offset)	\
	BUILD_BUG_ON(offsetof(struct ar10_switch_regs, name) != (4 * offset))

static inline void build_check_ar10_registers(void)
{
	BUILD_CHECK_AR10_REG(core, 0x0);
	BUILD_CHECK_AR10_REG(core.ssb_mode, 0x3);
	BUILD_CHECK_AR10_REG(bm.core, 0x3f);
	BUILD_CHECK_AR10_REG(bm.core.queue_gctrl, 0x4a);
	BUILD_CHECK_AR10_REG(bm.port[0], 0x80);
	BUILD_CHECK_AR10_REG(bm.queue, 0x100);
	BUILD_CHECK_AR10_REG(bm.shaper, 0x140);
	BUILD_CHECK_AR10_REG(pce.core, 0x438);
	BUILD_CHECK_AR10_REG(pce.core.tbl_ctrl, 0x44f);
	BUILD_CHECK_AR10_REG(pce.core.parser_stat, 0x469);
	BUILD_CHECK_AR10_REG(pce.port[0], 0x480);
	BUILD_CHECK_AR10_REG(pce.meter[0], 0x580);
	BUILD_CHECK_AR10_REG(mac.core, 0x8c0);
	BUILD_CHECK_AR10_REG(mac.port[0].pstat, 0x900);
	BUILD_CHECK_AR10_REG(mac.port[0].ctrl_0, 0x903);
	BUILD_CHECK_AR10_REG(mac.port[1].pstat, 0x90c);
	BUILD_CHECK_AR10_REG(mac.port[1].ctrl_0, 0x90f);
	BUILD_CHECK_AR10_REG(mac.port[2].pstat, 0x918);
	BUILD_CHECK_AR10_REG(mac.port[2].ctrl_0, 0x91b);
	BUILD_CHECK_AR10_REG(fdma.core, 0xa40);
	BUILD_CHECK_AR10_REG(fdma.port[0], 0xa80);
	BUILD_CHECK_AR10_REG(sdma.core, 0xb40);
	BUILD_CHECK_AR10_REG(sdma.port[0], 0xbc0);
	BUILD_CHECK_AR10_REG(mdio, 0xc40);
	BUILD_CHECK_AR10_REG(mii.mii_cfg0, (0xc40 + 0x36));
	BUILD_CHECK_AR10_REG(mii.mii_cfg3, (0xc40 + 0x3c));
	BUILD_CHECK_AR10_REG(mii.mii_cfg5, (0xc40 + 0x40));
	BUILD_CHECK_AR10_REG(mii.rxb_ctl_0, (0xc40 + 0x56));
	BUILD_CHECK_AR10_REG(mii.rxb_ctl_5, (0xc40 + 0x5b));
	BUILD_CHECK_AR10_REG(pmac, (0xc40 + 0x82));
}

#define BM_GCTRL_F_SRES		1

#define MAC_CTRL0_BM		(1 << 12)
#define MAC_CTRL0_APADEN	(1 << 11)
#define MAC_CTRL0_VPAD2EN	(1 << 10)
#define MAC_CTRL0_VPADEN	(1 << 9)
#define MAC_CTRL0_PADEN		(1 << 8)
#define MAC_CTRL0_FCS		(1 << 7)
#define MAC_CTRL0_FCON_SHIFT	4
#define MAC_CTRL0_FCON_AUTO	(0x0 << MAC_CTRL0_FCON_SHIFT)
#define MAC_CTRL0_FCON_RX	(0x1 << MAC_CTRL0_FCON_SHIFT)
#define MAC_CTRL0_FCON_TX	(0x2 << MAC_CTRL0_FCON_SHIFT)
#define MAC_CTRL0_FCON_RXTX	(0x3 << MAC_CTRL0_FCON_SHIFT)
#define MAC_CTRL0_FCON_NONE	(0x4 << MAC_CTRL0_FCON_SHIFT)
#define MAC_CTRL0_FDUP_SHIFT	2
#define MAC_CTRL0_FDUP_AUTO	(0x0 << MAC_CTRL0_FDUP_SHIFT)
#define MAC_CTRL0_FDUP_EN	(0x1 << MAC_CTRL0_FDUP_SHIFT)
#define MAC_CTRL0_FDUP_DIS	(0x3 << MAC_CTRL0_FDUP_SHIFT)
#define MAC_CTRL0_GMII_AUTO	0x0
#define MAC_CTRL0_GMII_MII	0x1
#define MAC_CTRL0_GMII_GMII	0x2
#define MAC_CTRL0_GMII_GMII_2G	0x3

#define MAC_CTRL1_DEFERMODE	(1 << 15)
#define MAC_CTRL1_SHORTPRE	(1 << 8)

#define MAC_CTRL2_MLEN		(1 << 3)
#define MAC_CTRL2_LCHKL		(1 << 2)
#define MAC_CTRL2_LCHKS_DIS	0x0
#define MAC_CTRL2_LCHKS_UNTAG	0x1
#define MAC_CTRL2_LCHKS_TAG	0x2

#define PHY_ADDR_LNKST_SHIFT	13
#define PHY_ADDR_LNKST_AUTO	(0x0 << PHY_ADDR_LNKST_SHIFT)
#define PHY_ADDR_LNKST_UP	(0x1 << PHY_ADDR_LNKST_SHIFT)
#define PHY_ADDR_LNKST_DOWN	(0x2 << PHY_ADDR_LNKST_SHIFT)
#define PHY_ADDR_SPEED_SHIFT	11
#define PHY_ADDR_SPEED_M10	(0x0 << PHY_ADDR_SPEED_SHIFT)
#define PHY_ADDR_SPEED_M100	(0x1 << PHY_ADDR_SPEED_SHIFT)
#define PHY_ADDR_SPEED_G1	(0x2 << PHY_ADDR_SPEED_SHIFT)
#define PHY_ADDR_SPEED_AUTO	(0x3 << PHY_ADDR_SPEED_SHIFT)
#define PHY_ADDR_FDUP_SHIFT	9
#define PHY_ADDR_FDUP_AUTO	(0x0 << PHY_ADDR_FDUP_SHIFT)
#define PHY_ADDR_FDUP_EN	(0x1 << PHY_ADDR_FDUP_SHIFT)
#define PHY_ADDR_FDUP_DIS	(0x3 << PHY_ADDR_FDUP_SHIFT)
#define PHY_ADDR_FCONTX_SHIFT	7
#define PHY_ADDR_FCONTX_AUTO	(0x0 << PHY_ADDR_FCONTX_SHIFT)
#define PHY_ADDR_FCONTX_EN	(0x1 << PHY_ADDR_FCONTX_SHIFT)
#define PHY_ADDR_FCONTX_DIS	(0x3 << PHY_ADDR_FCONTX_SHIFT)
#define PHY_ADDR_FCONRX_SHIFT	5
#define PHY_ADDR_FCONRX_AUTO	(0x0 << PHY_ADDR_FCONRX_SHIFT)
#define PHY_ADDR_FCONRX_EN	(0x1 << PHY_ADDR_FCONRX_SHIFT)
#define PHY_ADDR_FCONRX_DIS	(0x3 << PHY_ADDR_FCONRX_SHIFT)

#define MII_CFG_RES		(1 << 15)
#define MII_CFG_EN		(1 << 14)
#define MII_CFG_LDCLKDIS	(1 << 12)
#define MII_CFG_MIIRATE_SHIFT	4
#define MII_CFG_MIIRATE_MASK	(0x7 << MII_CFG_MIIRATE_SHIFT)
#define MII_CFG_MIIRATE_M2P5	(0x0 << MII_CFG_MIIRATE_SHIFT)
#define MII_CFG_MIIRATE_M25	(0x1 << MII_CFG_MIIRATE_SHIFT)
#define MII_CFG_MIIRATE_M125	(0x2 << MII_CFG_MIIRATE_SHIFT)
#define MII_CFG_MIIRATE_M50	(0x3 << MII_CFG_MIIRATE_SHIFT)
#define MII_CFG_MIIRATE_AUTO	(0x4 << MII_CFG_MIIRATE_SHIFT)
#define MII_CFG_MIIMODE_MASK	0xf
#define MII_CFG_MIIMODE_MIIP	0x0
#define MII_CFG_MIIMODE_MIIM	0x1
#define MII_CFG_MIIMODE_RMIIP	0x2
#define MII_CFG_MIIMODE_RMIIM	0x3
#define MII_CFG_MIIMODE_RGMII	0x4

#define PCDU_RXDLY_SHIFT	7
#define PCDU_RXDLY_MASK		(0x7 << PCDU_RXDLY_SHIFT)
#define PCDU_TXDLY_MASK		0x7

#define PMAC_HD_CTL_FC		(1 << 10)
#define PMAC_HD_CTL_CCRC	(1 << 9)
#define PMAC_HD_CTL_RST		(1 << 8)
#define PMAC_HD_CTL_AST		(1 << 7)
#define PMAC_HD_CTL_RXSH	(1 << 6)
#define PMAC_HD_CTL_RC		(1 << 4)
#define PMAC_HD_CTL_AS		(1 << 3)
#define PMAC_HD_CTL_AC		(1 << 2)

#define PCE_PCTRL_0_IGSTEN	(1 << 11)

#define FDMA_PCTRL_STEN		(1 << 1)
#define FDMA_PCTRL_EN		(1 << 0)

#define SDMA_PCTRL_EN		(1 << 0)

#define MDIO_GLOB_CTRL_SE	(1 << 15)

#define MDIO_MDC_CFG1_RES	(1 << 15)
#define MDIO_MDC_CFG1_MCEN	(1 << 8)

#define MDIO_CTRL_MBUSY		(1 << 12)
#define MDIO_CTRL_OP_READ	(1 << 11)
#define MDIO_CTRL_OP_WRITE	(1 << 10)
#define MDIO_CTRL_PHYAD_SHIFT	5
#define MDIO_CTRL_PHYAD_MASK	(0x1f << MDIO_CTRL_PHYAD_SHIFT)
#define MDIO_CTRL_REGAD_MASK	0x1f

void ltq_reset_switch_mem_repair(void);
void switch_mem_fix(u32 mem_id, u32 rar0_1, u32 addr);

#endif /* __XRX300_SWITCH_H__ */
