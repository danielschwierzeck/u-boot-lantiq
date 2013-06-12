/*
 * Copyright (C) 2012-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <linux/mtd/nand.h>
#include <linux/compiler.h>
#include <asm/arch/soc.h>
#include <asm/arch/nand.h>
#include <asm/lantiq/io.h>

#define NAND_CON_ECC_ON		(1 << 31)
#define NAND_CON_LATCH_PRE	(1 << 23)
#define NAND_CON_LATCH_WP	(1 << 22)
#define NAND_CON_LATCH_SE	(1 << 21)
#define NAND_CON_LATCH_CS	(1 << 20)
#define NAND_CON_LATCH_CLE	(1 << 19)
#define NAND_CON_LATCH_ALE	(1 << 18)
#define NAND_CON_OUT_CS1	(1 << 10)
#define NAND_CON_IN_CS1		(1 << 8)
#define NAND_CON_PRE_P		(1 << 7)
#define NAND_CON_WP_P		(1 << 6)
#define NAND_CON_SE_P		(1 << 5)
#define NAND_CON_CS_P		(1 << 4)
#define NAND_CON_CLE_P		(1 << 3)
#define NAND_CON_ALE_P		(1 << 2)
#define NAND_CON_CSMUX		(1 << 1)
#define NAND_CON_NANDM		(1 << 0)

#define NAND_WAIT_WR_C		(1 << 3)
#define NAND_WAIT_RDBY		(1 << 0)

#define NAND_CMD_ALE		(1 << 2)
#define NAND_CMD_CLE		(1 << 3)
#define NAND_CMD_CS		(1 << 4)
#define NAND_CMD_SE		(1 << 5)
#define NAND_CMD_WP		(1 << 6)
#define NAND_CMD_PRE		(1 << 7)

struct ltq_nand_regs {
	__be32	con;		/* NAND controller control */
	__be32	wait;		/* NAND Flash Device RD/BY State */
	__be32	ecc0;		/* NAND Flash ECC Register 0 */
	__be32	ecc_ac;		/* NAND Flash ECC Register address counter */
	__be32	ecc_cr;		/* NAND Flash ECC Comparison */
};

static struct ltq_nand_regs *ltq_nand_regs =
	(struct ltq_nand_regs *) CKSEG1ADDR(LTQ_EBU_NAND_BASE);

static void ltq_nand_wait_ready(void)
{
	while ((ltq_readl(&ltq_nand_regs->wait) & NAND_WAIT_WR_C) == 0)
		;
}

static int ltq_nand_dev_ready(struct mtd_info *mtd)
{
	u32 data = ltq_readl(&ltq_nand_regs->wait);
	return data & NAND_WAIT_RDBY;
}

static void ltq_nand_select_chip(struct mtd_info *mtd, int chip)
{
	if (chip == 0) {
		ltq_setbits(&ltq_nand_regs->con, NAND_CON_NANDM);
		ltq_setbits(&ltq_nand_regs->con, NAND_CON_LATCH_CS);
	} else {
		ltq_clrbits(&ltq_nand_regs->con, NAND_CON_LATCH_CS);
		ltq_clrbits(&ltq_nand_regs->con, NAND_CON_NANDM);
	}
}

static void ltq_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
	struct nand_chip *chip = mtd->priv;
	unsigned long addr = (unsigned long) chip->IO_ADDR_W;

	if (ctrl & NAND_CTRL_CHANGE) {
		if (ctrl & NAND_ALE)
			addr |= NAND_CMD_ALE;
		else
			addr &= ~NAND_CMD_ALE;

		if (ctrl & NAND_CLE)
			addr |= NAND_CMD_CLE;
		else
			addr &= ~NAND_CMD_CLE;

		chip->IO_ADDR_W = (void __iomem *) addr;
	}

	if (cmd != NAND_CMD_NONE) {
		writeb(cmd, chip->IO_ADDR_W);
		ltq_nand_wait_ready();
	}
}

int ltq_nand_init(struct nand_chip *nand)
{
	/* Enable NAND, set NAND CS to EBU CS1, enable EBU CS mux */
	ltq_writel(&ltq_nand_regs->con, NAND_CON_OUT_CS1 | NAND_CON_IN_CS1 |
		NAND_CON_PRE_P | NAND_CON_WP_P | NAND_CON_SE_P |
		NAND_CON_CS_P | NAND_CON_CSMUX);

	nand->dev_ready = ltq_nand_dev_ready;
	nand->select_chip = ltq_nand_select_chip;
	nand->cmd_ctrl = ltq_nand_cmd_ctrl;

	nand->chip_delay = 30;
	nand->options = 0;
	nand->ecc.mode = NAND_ECC_SOFT;

	/* Enable CS bit in address offset */
	nand->IO_ADDR_R = nand->IO_ADDR_R + NAND_CMD_CS;
	nand->IO_ADDR_W = nand->IO_ADDR_W + NAND_CMD_CS;

	return 0;
}

__weak int board_nand_init(struct nand_chip *chip)
{
	return ltq_nand_init(chip);
}
