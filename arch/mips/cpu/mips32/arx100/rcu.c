/*
 * Copyright (C) 2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/cpu.h>
#include <asm/arch/soc.h>

#define LTQ_RCU_RD_SRST		(1 << 30)	/* Global SW Reset */
#define LTQ_RCU_RD_USB1		(1 << 28)	/* USB1 MAC and PHY */
#define LTQ_RCU_RD_REG25_PD	(1 << 26)	/* Power down 2.5V regulator */
#define LTQ_RCU_RD_PPE_ATM_TC	(1 << 22)	/* PPE ATM TC */
#define LTQ_RCU_RD_ETHSW	(1 << 21)	/* Ethernet switch */
#define LTQ_RCU_RD_DSP_DEN	(1 << 20)	/* Enable DSP JTAG */
#define LTQ_RCU_RD_TDM		(1 << 19)	/* TDM module interface */
#define LTQ_RCU_RD_MC		(1 << 14)	/* Memory Controller */
#define LTQ_RCU_RD_PCI		(1 << 13)	/* PCI core */
#define LTQ_RCU_RD_SDIO		(1 << 10)	/* SDIO core */
#define LTQ_RCU_RD_DMA		(1 << 9)	/* DMA core */
#define LTQ_RCU_RD_PPE		(1 << 8)	/* PPE core */
#define LTQ_RCU_RD_ARC_DFE	(1 << 7)	/* ARC/DFE core */
#define LTQ_RCU_RD_AHB		(1 << 6)	/* AHB bus */
#define LTQ_RCU_RD_USB		(1 << 4)	/* USB and Phy core */
#define LTQ_RCU_RD_FPI		(1 << 2)	/* FPI bus */
#define LTQ_RCU_RD_CPU0		(1 << 1)	/* CPU0 subsystem */
#define LTQ_RCU_RD_HRST		(1 << 0)	/* HW reset via HRST pin */

#define LTQ_RCU_STAT_BOOT_SHIFT		17
#define LTQ_RCU_STAT_BOOT_MASK		(0xf << LTQ_RCU_STAT_BOOT_SHIFT)

struct ltq_rcu_regs {
	u32	rsvd0[4];
	__be32	req;		/* Reset request */
	__be32	stat;		/* Reset status */
	__be32	usb0_cfg;	/* USB0 config */
	u32	rsvd1[2];
	__be32	pci_rdy;	/* PCI boot ready */
	__be32	ppe_conf;	/* PPE config */
	u32	rsvd2;
	__be32	usb1_cfg;	/* USB1 config */
};

static struct ltq_rcu_regs *ltq_rcu_regs =
	(struct ltq_rcu_regs *) CKSEG1ADDR(LTQ_RCU_BASE);

u32 ltq_reset_map(enum ltq_reset_modules module)
{
	u32 val;

	switch (module) {
	case LTQ_RESET_CORE:
	case LTQ_RESET_SOFT:
		val = LTQ_RCU_RD_SRST | LTQ_RCU_RD_CPU0;
		break;
	case LTQ_RESET_DMA:
		val = LTQ_RCU_RD_DMA;
		break;
	case LTQ_RESET_ETH:
		val = LTQ_RCU_RD_PPE | LTQ_RCU_RD_ETHSW;
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

	stat = ltq_readl(&ltq_rcu_regs->stat);
	bootstrap = (stat & LTQ_RCU_STAT_BOOT_MASK) >> LTQ_RCU_STAT_BOOT_SHIFT;

	switch (bootstrap) {
	case 0:
		return BOOT_NOR_NO_BOOTROM;
	case 1:
		return BOOT_RGMII0;
	case 2:
		return BOOT_NOR;
	case 3:
		return BOOT_MII0;
	case 5:
		return BOOT_RMII0;
	case 6:
		return BOOT_PCI;
	case 8:
		return BOOT_UART;
	case 10:
		return BOOT_SPI;
	default:
		return BOOT_UNKNOWN;
	}
}
