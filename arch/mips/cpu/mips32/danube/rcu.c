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

#define LTQ_RCU_RD_SRST		(1 << 30)	/* Global SW Reset */
#define LTQ_RCU_RD_MC		(1 << 14)	/* Memory Controller */
#define LTQ_RCU_RD_PCI		(1 << 13)	/* PCI core */
#define LTQ_RCU_RD_DFE_AFE	(1 << 12)	/* Voice DFE/AFE */
#define LTQ_RCU_RD_DSL_AFE	(1 << 11)	/* DSL AFE */
#define LTQ_RCU_RD_SDIO		(1 << 10)	/* SDIO core */
#define LTQ_RCU_RD_DMA		(1 << 9)	/* DMA core */
#define LTQ_RCU_RD_PPE		(1 << 8)	/* PPE core */
#define LTQ_RCU_RD_ARC_DFE	(1 << 7)	/* ARC/DFE core */
#define LTQ_RCU_RD_AHB		(1 << 6)	/* AHB bus */
#define LTQ_RCU_RD_ENET_MAC1	(1 << 5)	/* Ethernet MAC1 */
#define LTQ_RCU_RD_USB		(1 << 4)	/* USB and Phy core */
#define LTQ_RCU_RD_CPU1		(1 << 3)	/* CPU1 subsystem */
#define LTQ_RCU_RD_FPI		(1 << 2)	/* FPI bus */
#define LTQ_RCU_RD_CPU0		(1 << 1)	/* CPU0 subsystem */
#define LTQ_RCU_RD_HRST		(1 << 0)	/* HW reset via HRST pin */

#define LTQ_RCU_STAT_BOOT_SHIFT		18
#define LTQ_RCU_STAT_BOOT_MASK		(0x7 << LTQ_RCU_STAT_BOOT_SHIFT)

struct ltq_rcu_regs {
	u32	rsvd0[4];
	u32	req;		/* Reset request */
	u32	stat;		/* Reset status */
	u32	usb_cfg;	/* USB configure */
	u32	rsvd1[2];
	u32	pci_rdy;	/* PCI boot ready */
};

static struct ltq_rcu_regs *ltq_rcu_regs =
	(struct ltq_rcu_regs *) CKSEG1ADDR(LTQ_RCU_BASE);

u32 ltq_reset_map(enum ltq_reset_modules module)
{
	u32 val;

	switch (module) {
	case LTQ_RESET_CORE:
	case LTQ_RESET_SOFT:
		val = LTQ_RCU_RD_SRST | LTQ_RCU_RD_CPU1;
		break;
	case LTQ_RESET_DMA:
		val = LTQ_RCU_RD_DMA;
		break;
	case LTQ_RESET_ETH:
		val = LTQ_RCU_RD_PPE;
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
		return BOOT_NOR;
	case 2:
		return BOOT_MII0;
	case 3:
		return BOOT_PCI;
	case 4:
		return BOOT_UART;
	case 5:
		return BOOT_SPI;
	case 6:
		return BOOT_NAND;
	case 7:
		return BOOT_RMII0;
	default:
		return BOOT_UNKNOWN;
	}
}
