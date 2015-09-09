/*
 * Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/nand.h>
#include <asm/arch/switch.h>

#define RCU_REQ_GPHY0		(1 << 31)	/* GPHY0 */
#define RCU_REQ_SRST		(1 << 30)	/* Global SW Reset */
#define RCU_REQ_GPHY1		(1 << 29)	/* GPHY1 */
#define RCU_REQ_GPHY2		(1 << 28)	/* GPHY2 */
#define RCU_REQ_PCIE2		(1 << 27)	/* PCIE2 core */
#define RCU_REQ_LDO_PD		(1 << 26)	/* Power down linear regulator */
#define RCU_REQ_ENDINIT		(1 << 25)	/* Enable FPI slave bus access */
#define RCU_REQ_WLAN		(1 << 24)	/* WLAN */
#define RCU_REQ_PCIE1		(1 << 22)	/* PCIE1 core */
#define RCU_REQ_ETHSW		(1 << 21)	/* Ethernet switch */
#define RCU_REQ_TDM		(1 << 19)	/* TDM */
#define RCU_REQ_NMI_PLL1	(1 << 18)	/* Enable NMI of PLL1 */
#define RCU_REQ_BB_SPI_EN	(1 << 17)	/* Enable baseband CPU SPI */
#define RCU_REQ_HSNAND		(1 << 16)	/* HSNAND controller */
#define RCU_REQ_NMI_PLL0	(1 << 15)	/* Enable NMI of PLL0 */
#define RCU_REQ_XBAR		(1 << 14)	/* Crossbar */
#define RCU_REQ_PCIE2_PHY	(1 << 13)	/* PCIE2 PHY */
#define RCU_REQ_PCIE1_PHY	(1 << 12)	/* PCIE1 PHY */
#define RCU_REQ_BB_UART_EN	(1 << 11)	/* Enable baseband CPU UART */
#define RCU_REQ_GPHY3		(1 << 10)	/* GPHY3 */
#define RCU_REQ_DMA		(1 << 9)	/* DMA core */
#define RCU_REQ_PPE		(1 << 8)	/* PPE core */
#define RCU_REQ_NMI_PLL2	(1 << 7)	/* Enable NMI of PLL2 */
#define RCU_REQ_AHB		(1 << 6)	/* AHB bus */
#define RCU_REQ_HRST_CFG	(1 << 5)	/* HW reset configuration */
#define RCU_REQ_USB0		(1 << 4)	/* USB0 core and PHY */
#define RCU_REQ_USB1		(1 << 3)	/* USB1 core and PHY */
#define RCU_REQ_FPI		(1 << 2)	/* FPI bus */
#define RCU_REQ_CPU		(1 << 1)	/* CPU subsystem */
#define RCU_REQ_HRST		(1 << 0)	/* HW reset via HRST pin */
#define RCU_REQ2_PCIE3_PHY	(1 << 29)	/* PCIE3 PHY */
#define RCU_REQ2_PCIE3		(1 << 28)	/* PCIE3 core */
#define RCU_REQ2_PHY3		(1 << 27)	/* PHY3 */
#define RCU_REQ2_P2D		(1 << 26)	/* PMAC to DPlus module */
#define RCU_REQ2_D2P		(1 << 25)	/* DPlus to PMAC module */
#define RCU_REQ2_FUSE		(1 << 23)	/* FUSE bits */
#define RCU_REQ2_MFPI2		(1 << 22)	/* Master FPI bus 2 */
#define RCU_REQ2_MFPI1		(1 << 21)	/* Master FPI bus 1 */
#define RCU_REQ2_SAHB3		(1 << 20)	/* Slave AHB bus 3 */
#define RCU_REQ2_SAHB2		(1 << 19)	/* Slave AHB bus 2 */
#define RCU_REQ2_SAHB1		(1 << 18)	/* Slave AHB bus 1 */
#define RCU_REQ2_TEMPS		(1 << 12)	/* Temperature sensor */
#define RCU_REQ2_WLAN_CG	(1 << 9)	/* WLAN clock generation */
#define RCU_REQ2_PHY2		(1 << 8)	/* PHY2 */
#define RCU_REQ2_PHY0		(1 << 7)	/* PHY0 */
#define RCU_REQ2_PHY1		(1 << 6)	/* PHY1 */
#define RCU_REQ2_USB1_PHY	(1 << 5)	/* USB1 PHY */
#define RCU_REQ2_USB0_PHY	(1 << 4)	/* USB0 PHY */
#define RCU_REQ2_SLIC		(1 << 0)	/* SLIC1 and SLIC2 */

#define RCU_STAT_GPIOLATCH_SHIFT	18	/* GPIOs 36, 17, 15 */
#define RCU_STAT_GPIOLATCH_MASK		(0x7 << RCU_STAT_GPIOLATCH_SHIFT)
#define RCU_STAT_BOOTMODE0		(1 << 17)
#define RCU_STAT2_WLAN_HW		(1 << 9)

#define RCU_GP_STRAP_ECC_4BYTE	(1 << 25)
#define RCU_GP_STRAP_ECC_OFF	(1 << 23)
#define RCU_GP_STRAP_BOOTMODE3	(1 << 19)
#define RCU_GP_STRAP_BOOTMODE2	(1 << 14)
#define RCU_GP_STRAP_ECC_NO_OOB	(1 << 6)
#define RCU_GP_STRAP_NAND_BE	(1 << 4)
#define RCU_GP_STRAP_BOOTMODE1	(1 << 3)

#define RFUSE_CNT		6
#define RFUSE_SWITCH		(0x3 << 17)

struct ltq_rcu_regs {
	u32	rsvd0[4];
	u32	req;		/* Reset request */
	u32	stat;		/* Reset status */
	u32	usb0_cfg;	/* USB0 config */
	u32	gp_strap;	/* GPIO strapping */
	u32	gfs_add0;	/* GPHY0 firmware base address */
	u32	stat2;		/* Reset status 2 */
	u32	ppm;		/* Protected platform mode */
	u32	ppe_conf;	/* PPE ethernet config */
	u32	pciephy1_con;	/* PCIE1 PHY config */
	u32	usb1_cfg;	/* USB1 config */
	u32	usb_ana_cfg1a;	/* USB analog config 1a */
	u32	usb_ana_cfg1b;	/* USB analog config 1b */
	u32	gcc;		/* General CPU config */
	u32	gfmdio_add;	/* GPHY MDIO address */
	u32	req2;		/* Reset request 2 */
	u32	endian;		/* Endianess config */
	u32	pcie_cfg_pwr;	/* PCIE power config */
	u32	pcie1_cfg_pwr;	/* PCIE1 power config */
	u32	gfs_add1;	/* GPHY1 firmware base address */
	u32	pciephy2_con;	/* PCIE2 PHY config */
	u32	rsvd1[19];
	u32	gfs_add2;	/* GPHY2 firmware base address */
};

struct ltq_rcu2_regs {
	u32	rsvd0[24];
	u32	pciephy3_con;	/* PCIE3 PHY config */
	u32	gfs_add3;	/* GPHY3 firmware base address */
	u32	gf3mdio_add;	/* GPHY3 MDIO address */
	u32	pcie3_cfg_pwr;	/* PCIE3 power config */
};

static struct ltq_rcu_regs *ltq_rcu_regs =
	(struct ltq_rcu_regs *) CKSEG1ADDR(LTQ_RCU_BASE);

static struct ltq_rcu2_regs *ltq_rcu2_regs =
	(struct ltq_rcu2_regs *) CKSEG1ADDR(LTQ_RCU2_BASE);

u32 ltq_reset_map(enum ltq_reset_modules module)
{
	u32 val;

	switch (module) {
	case LTQ_RESET_SOFT:
		val = RCU_REQ_SRST;
		break;
	case LTQ_RESET_CORE:
		val = RCU_REQ_SRST | RCU_REQ_CPU | RCU_REQ_GPHY3 |
			RCU_REQ_GPHY2 | RCU_REQ_GPHY1 | RCU_REQ_GPHY0;
		break;
	case LTQ_RESET_DMA:
		val = RCU_REQ_DMA;
		break;
	case LTQ_RESET_ETH:
		val = RCU_REQ_PPE | RCU_REQ_ETHSW;
		break;
	case LTQ_RESET_PHY:
		val = RCU_REQ_GPHY3 | RCU_REQ_GPHY2 | RCU_REQ_GPHY1 |
			RCU_REQ_GPHY0;
		break;
	case LTQ_RESET_HARD:
		val = RCU_REQ_HRST;
		break;
	default:
		val = 0;
		break;
	}

	return val;
}

int ltq_reset_activate(enum ltq_reset_modules module)
{
	u32 val;

	val = ltq_reset_map(module);
	if (unlikely(!val))
		return 1;

	ltq_setbits(&ltq_rcu_regs->req, val);

	return 0;
}

int ltq_reset_deactivate(enum ltq_reset_modules module)
{
	u32 val;

	val = ltq_reset_map(module);
	if (unlikely(!val))
		return 1;

	ltq_clrbits(&ltq_rcu_regs->req, val);

	return 0;
}

enum ltq_boot_select ltq_boot_select(void)
{
	u32 stat, gp_strap;
	unsigned int bootstrap;

	stat = ltq_readl(&ltq_rcu_regs->stat);
	gp_strap = ltq_readl(&ltq_rcu_regs->gp_strap);

	bootstrap = !!(stat & RCU_STAT_BOOTMODE0);
	bootstrap |= !!(gp_strap & RCU_GP_STRAP_BOOTMODE1) << 1;
	bootstrap |= !!(gp_strap & RCU_GP_STRAP_BOOTMODE2) << 2;
	bootstrap |= !!(gp_strap & RCU_GP_STRAP_BOOTMODE3) << 3;

	switch (bootstrap) {
	case 0x2:
		return BOOT_UART_NO_EEPROM;
	case 0x4:
		return BOOT_UART;
	case 0x5:
		return BOOT_SPI;
	case 0x6:
		return BOOT_NAND;
	case 0x8:
		return BOOT_NAND_SAMSUNG_2K;
	case 0x9:
		return BOOT_NAND_SAMSUNG_1K;
	case 0xa:
		return BOOT_HSNAND_SAMSUNG_2K;
	case 0xb:
		return BOOT_HSNAND_SAMSUNG_1K;
	case 0xe:
		return BOOT_HSNAND_ONFI;
	default:
		return BOOT_UNKNOWN;
	}
}

unsigned int ltq_boot_hsnand_info(void)
{
	u32 gp_strap;
	enum ltq_boot_select boot_sel;
	unsigned int flags = 0;

	gp_strap = ltq_readl(&ltq_rcu_regs->gp_strap);
	boot_sel = ltq_boot_select();

	if (gp_strap & RCU_GP_STRAP_ECC_4BYTE)
		flags |= HSNAND_ECC_4BYTE;

	if (gp_strap & RCU_GP_STRAP_ECC_OFF)
		flags |= HSNAND_ECC_OFF;

	if (gp_strap & RCU_GP_STRAP_ECC_NO_OOB)
		flags |= HSNAND_ECC_NO_OOB;

	if (gp_strap & RCU_GP_STRAP_NAND_BE)
		flags |= HSNAND_BIG_ENDIAN;

	switch (boot_sel) {
	case BOOT_HSNAND_SAMSUNG_2K:
		flags |= HSNAND_SAMSUNG_2K;
		break;
	case BOOT_HSNAND_SAMSUNG_1K:
		flags |= HSNAND_SAMSUNG_1K;
		break;
	case BOOT_HSNAND_ONFI:
		flags |= HSNAND_ONFI;
		break;
	default:
		break;
	}

	return flags;
}

void ltq_rcu_gphy_boot(unsigned int id, const void *addr)
{
	u32 module;
	void *gfs_add;

	switch (id) {
	case 0:
		module = RCU_REQ_GPHY0;
		gfs_add = &ltq_rcu_regs->gfs_add0;
		break;
	case 1:
		module = RCU_REQ_GPHY1;
		gfs_add = &ltq_rcu_regs->gfs_add1;
		break;
	case 2:
		module = RCU_REQ_GPHY2;
		gfs_add = &ltq_rcu_regs->gfs_add2;
		break;
	case 3:
		module = RCU_REQ_GPHY3;
		gfs_add = &ltq_rcu2_regs->gfs_add3;
		break;
	default:
		BUG();
	}

	/* Stop and reset GPHY */
	ltq_setbits(&ltq_rcu_regs->req, module);

	/* Configure firmware and boot address */
	ltq_writel(gfs_add, CPHYSADDR((ulong)addr));

	/* Start GPHY by releasing reset */
	ltq_clrbits(&ltq_rcu_regs->req, module);
}

void __weak switch_mem_fix(u32 mem_id, u32 rar0_1, u32 addr)
{
}

static const void *to_rfuse_addr(unsigned int index)
{
	return (const void *)(CKSEG1ADDR(LTQ_PPE_SW_WLAN_RFUSE_BASE) +
		4 * index);
}

void ltq_reset_switch_mem_repair(void)
{
	unsigned int i;
	u32 rfuse_bits;

	/* bring WLAN on-chip module out of reset state */
	ltq_clrbits(&ltq_rcu_regs->req, RCU_REQ_WLAN);
	ltq_clrbits(&ltq_rcu_regs->req2, RCU_REQ2_WLAN_CG);

	while (ltq_readl(&ltq_rcu_regs->stat2) & RCU_STAT2_WLAN_HW)
		;

	/* enable read of fuse bits */
	ltq_setbits(&ltq_rcu_regs->req2, RCU_REQ2_FUSE);

	for (i = 0; i < RFUSE_CNT; i++) {
		rfuse_bits = ltq_readl(to_rfuse_addr(i));

		if (rfuse_bits & RFUSE_SWITCH)
			switch_mem_fix((rfuse_bits >> 14) & 0xf,
				(rfuse_bits >> 13) & 0x1, rfuse_bits & 0x1fff);
	}

	/* disable read of fuse bits */
	ltq_clrbits(&ltq_rcu_regs->req2, RCU_REQ2_FUSE);
}
