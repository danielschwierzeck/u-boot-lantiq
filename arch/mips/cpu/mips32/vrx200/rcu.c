/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/cpu.h>
#include <asm/arch/soc.h>

#define LTQ_RCU_RD_GPHY0	(1 << 31)	/* GPHY0 */
#define LTQ_RCU_RD_SRST		(1 << 30)	/* Global SW Reset */
#define LTQ_RCU_RD_GPHY1	(1 << 29)	/* GPHY1 */
#define LTQ_RCU_RD_ENMIP2	(1 << 28)	/* Enable NMI of PLL2 */
#define LTQ_RCU_RD_REG25_PD	(1 << 26)	/* Power down 2.5V regulator */
#define LTQ_RCU_RD_ENDINIT	(1 << 25)	/* FPI slave bus access */
#define LTQ_RCU_RD_PPE_ATM_TC	(1 << 23)	/* PPE ATM TC */
#define LTQ_RCU_RD_PCIE		(1 << 22)	/* PCI-E core */
#define LTQ_RCU_RD_ETHSW	(1 << 21)	/* Ethernet switch */
#define LTQ_RCU_RD_DSP_DEN	(1 << 20)	/* Enable DSP JTAG */
#define LTQ_RCU_RD_TDM		(1 << 19)	/* TDM module interface */
#define LTQ_RCU_RD_ENMIP1	(1 << 18)	/* Enable NMI of PLL1 */
#define LTQ_RCU_RD_SWBCK	(1 << 17)	/* Switch backward compat */
#define LTQ_RCU_RD_HSNAND	(1 << 16)	/* HSNAND controller */
#define LTQ_RCU_RD_ENMIP0	(1 << 15)	/* Enable NMI of PLL0 */
#define LTQ_RCU_RD_MC		(1 << 14)	/* Memory Controller */
#define LTQ_RCU_RD_PCI		(1 << 13)	/* PCI core */
#define LTQ_RCU_RD_PCIE_PHY	(1 << 12)	/* PCI-E Phy */
#define LTQ_RCU_RD_DFE_CORE	(1 << 11)	/* DFE core */
#define LTQ_RCU_RD_SDIO		(1 << 10)	/* SDIO core */
#define LTQ_RCU_RD_DMA		(1 << 9)	/* DMA core */
#define LTQ_RCU_RD_PPE		(1 << 8)	/* PPE core */
#define LTQ_RCU_RD_DFE		(1 << 7)	/* DFE core */
#define LTQ_RCU_RD_AHB		(1 << 6)	/* AHB bus */
#define LTQ_RCU_RD_HRST_CFG	(1 << 5)	/* HW reset configuration */
#define LTQ_RCU_RD_USB		(1 << 4)	/* USB and Phy core */
#define LTQ_RCU_RD_PPE_DSP	(1 << 3)	/* PPE DSP interface */
#define LTQ_RCU_RD_FPI		(1 << 2)	/* FPI bus */
#define LTQ_RCU_RD_CPU		(1 << 1)	/* CPU subsystem */
#define LTQ_RCU_RD_HRST		(1 << 0)	/* HW reset via HRST pin */

#define LTQ_RCU_STAT_BOOT_SHIFT		17
#define LTQ_RCU_STAT_BOOT_MASK		(0xF << LTQ_RCU_STAT_BOOT_SHIFT)
#define LTQ_RCU_STAT_BOOT_H		(1 << 12)

#define LTQ_RCU_GP_STRAP_CLOCKSOURCE	(1 << 15)

struct ltq_rcu_regs {
	u32	rsvd0[4];
	u32	req;		/* Reset request */
	u32	stat;		/* Reset status */
	u32	usb0_cfg;	/* USB0 configure */
	u32	gp_strap;	/* GPIO strapping */
	u32	gfs_add0;	/* GPHY0 firmware base addr */
	u32	stat2;		/* SLIC and USB reset status */
	u32	pci_rdy;	/* PCI boot ready */
	u32	ppe_conf;	/* PPE ethernet config */
	u32	pcie_phy_con;	/* PCIE PHY config/status */
	u32	usb1_cfg;	/* USB1 configure */
	u32	usb_ana_cfg1a;	/* USB analog config 1a */
	u32	usb_ana_cfg1b;	/* USB analog config 1b */
	u32	rsvd1;
	u32	gf_mdio_add;	/* GPHY0/1 MDIO address */
	u32	req2;		/* SLIC and USB reset request */
	u32	ahb_endian;	/* AHB bus endianess */
	u32	rsvd2[4];
	u32	gcc;		/* General CPU config */
	u32	rsvd3;
	u32	gfs_add1;	/* GPHY1 firmware base addr */
};

static struct ltq_rcu_regs *ltq_rcu_regs =
	(struct ltq_rcu_regs *) CKSEG1ADDR(LTQ_RCU_BASE);

u32 ltq_reset_map(enum ltq_reset_modules module)
{
	u32 val;

	switch (module) {
	case LTQ_RESET_CORE:
	case LTQ_RESET_SOFT:
		val = LTQ_RCU_RD_SRST | LTQ_RCU_RD_CPU | LTQ_RCU_RD_ENMIP2 |
			LTQ_RCU_RD_GPHY1 | LTQ_RCU_RD_GPHY0;
		break;
	case LTQ_RESET_DMA:
		val = LTQ_RCU_RD_DMA;
		break;
	case LTQ_RESET_ETH:
		val = LTQ_RCU_RD_PPE | LTQ_RCU_RD_ETHSW;
		break;
	case LTQ_RESET_PHY:
		val = LTQ_RCU_RD_GPHY1 | LTQ_RCU_RD_GPHY0;
		break;
	case LTQ_RESET_HARD:
		val = LTQ_RCU_RD_HRST;
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
	u32 stat;
	unsigned int bootstrap;

	/*
	 * Boot select value is built from bits 20-17 and bit 12.
	 * The bit sequence is read as 4-2-1-0-3.
	 */
	stat = ltq_readl(&ltq_rcu_regs->stat);
	bootstrap = ((stat & LTQ_RCU_STAT_BOOT_H) << 4) |
		((stat & LTQ_RCU_STAT_BOOT_MASK) >> LTQ_RCU_STAT_BOOT_SHIFT);

	switch (bootstrap) {
	case 0:
		return BOOT_NOR_NO_BOOTROM;
	case 1:
		return BOOT_RGMII1;
	case 2:
		return BOOT_NOR;
	case 4:
		return BOOT_UART_NO_EEPROM;
	case 6:
		return BOOT_PCI;
	case 8:
		return BOOT_UART;
	case 10:
		return BOOT_SPI;
	case 12:
		return BOOT_NAND;
	default:
		return BOOT_UNKNOWN;
	}
}

void ltq_rcu_gphy_boot(unsigned int id, ulong addr)
{
	u32 module;
	void *gfs_add;

	switch (id) {
	case 0:
		module = LTQ_RCU_RD_GPHY0;
		gfs_add = &ltq_rcu_regs->gfs_add0;
		break;
	case 1:
		module = LTQ_RCU_RD_GPHY1;
		gfs_add = &ltq_rcu_regs->gfs_add1;
		break;
	default:
		BUG();
	}

	/* Stop and reset GPHY */
	ltq_setbits(&ltq_rcu_regs->req, module);

	/* Configure firmware and boot address */
	ltq_writel(gfs_add, CPHYSADDR(addr & 0xFFFFC000));

	/* Start GPHY by releasing reset */
	ltq_clrbits(&ltq_rcu_regs->req, module);
}
