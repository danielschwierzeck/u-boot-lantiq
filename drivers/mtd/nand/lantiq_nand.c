/*
 * Copyright (C) 2012-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <nand.h>
#include <linux/compiler.h>
#include <linux/mtd/nand_ecc.h>
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
#define NAND_CON_LATCH_SHIFT	18
#define NAND_CON_LATCH_ALL	(NAND_CON_LATCH_PRE | NAND_CON_LATCH_WP | \
				NAND_CON_LATCH_SE | NAND_CON_LATCH_CS | \
				NAND_CON_LATCH_ALE << NAND_CON_LATCH_SHIFT)

#define NAND_WAIT_WR_C		(1 << 3)
#define NAND_WAIT_RD_E		(1 << 2)
#define NAND_WAIT_BY_E		(1 << 1)
#define NAND_WAIT_RDBY		(1 << 0)
#define NAND_WAIT_READY		(NAND_WAIT_RD_E | NAND_WAIT_BY_E | NAND_WAIT_RDBY)

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
	return (data & NAND_WAIT_READY) == NAND_WAIT_READY;
}

static void ltq_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
	struct nand_chip *chip = mtd->priv;
	unsigned long addr_w = (unsigned long) chip->IO_ADDR_W;
	unsigned long addr_r = (unsigned long) chip->IO_ADDR_R;

	if (ctrl & NAND_CTRL_CHANGE) {
		if (ctrl & NAND_NCE) {
			addr_w |= NAND_CMD_CS;
			addr_r |= NAND_CMD_CS;
		} else {
			addr_w &= ~NAND_CMD_CS;
			addr_r &= ~NAND_CMD_CS;
		}

		if (ctrl & NAND_ALE)
			addr_w |= NAND_CMD_ALE;
		else
			addr_w &= ~NAND_CMD_ALE;

		if (ctrl & NAND_CLE)
			addr_w |= NAND_CMD_CLE;
		else
			addr_w &= ~NAND_CMD_CLE;

		chip->IO_ADDR_W = (void __iomem *) addr_w;
		chip->IO_ADDR_R = (void __iomem *) addr_r;
	}

	if (cmd != NAND_CMD_NONE) {
		writeb(cmd, chip->IO_ADDR_W);
		ltq_nand_wait_ready();
	}
}

static void ltq_nand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
	int i;
	struct nand_chip *chip = mtd->priv;

	for (i = 0; i < len; i++)
		buf[i] = readb(chip->IO_ADDR_R);
}

int ltq_nand_init(struct nand_chip *nand)
{
	/* Enable NAND, set NAND CS to EBU CS1, enable EBU CS mux */
	ltq_writel(&ltq_nand_regs->con, NAND_CON_LATCH_ALL |
#ifndef CONFIG_LTQ_SUPPORT_NAND_FLASH_CS0
		NAND_CON_OUT_CS1 | NAND_CON_IN_CS1 |
#endif
		NAND_CON_PRE_P | NAND_CON_WP_P |
		NAND_CON_SE_P | NAND_CON_CS_P | NAND_CON_CSMUX | NAND_CON_NANDM);

	nand->dev_ready = ltq_nand_dev_ready;
	nand->cmd_ctrl = ltq_nand_cmd_ctrl;
	nand->read_buf = ltq_nand_read_buf;

	nand->ecc.mode = NAND_ECC_SOFT;

#ifdef CONFIG_SYS_NAND_USE_FLASH_BBT
	nand->bbt_options |= NAND_BBT_USE_FLASH;
#endif

	return 0;
}

__weak int board_nand_init(struct nand_chip *chip)
{
	return ltq_nand_init(chip);
}

#if defined(CONFIG_SYS_BOOT_NANDSPL) && defined(CONFIG_SPL_BUILD)
#define ECCSIZE		256
#define ECCBYTES	3
#define ECCSTEPS	(CONFIG_SYS_NAND_PAGE_SIZE / ECCSIZE)
#define ECCTOTAL	(ECCSTEPS * ECCBYTES)

#if (CONFIG_SYS_NAND_OOBSIZE == 16)
static const u8 spl_nand_eccpos[] = {
	0, 1, 2, 3, 6, 7,
};
#elif (CONFIG_SYS_NAND_OOBSIZE == 64)
static const u8 spl_nand_eccpos[] = {
	40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
};
#else
#error "unsupported NAND OOB size"
#endif

static noinline void spl_nand_write(unsigned int cmd, unsigned int addr)
{
	unsigned long base_addr = CONFIG_SYS_NAND_BASE + NAND_CMD_CS;
	void __iomem *io_addr = (void __iomem *)(base_addr + addr);
	ltq_writeb(io_addr, cmd);
	ltq_nand_wait_ready();
}

static noinline void spl_nand_command(int block, int page, unsigned int cmd)
{
	int page_addr = page + block * CONFIG_SYS_NAND_PAGE_COUNT;

	/* command latch cycle */
	spl_nand_write(cmd, NAND_CMD_CLE);

	/* column address */
	spl_nand_write(0, NAND_CMD_ALE);
#if (CONFIG_SYS_NAND_PAGE_SIZE > 512)
	spl_nand_write(0, NAND_CMD_ALE);
#endif

	/* row address */
	spl_nand_write(page_addr & 0xff, NAND_CMD_ALE);
	spl_nand_write((page_addr >> 8) & 0xff, NAND_CMD_ALE);

#if (CONFIG_SYS_NAND_PAGE_SIZE <= 512) && defined(CONFIG_SYS_NAND_4_ADDR_CYCLE)
	/* One more address cycle for devices > 32MiB */
	spl_nand_write((page_addr >> 16) & 0x0f, NAND_CMD_ALE);
#endif
#if (CONFIG_SYS_NAND_PAGE_SIZE > 512) && defined(CONFIG_SYS_NAND_5_ADDR_CYCLE)
	/* One more address cycle for devices > 128MiB */
	spl_nand_write((page_addr >> 16) & 0x0f, NAND_CMD_ALE);
#endif

#if (CONFIG_SYS_NAND_PAGE_SIZE > 512)
	spl_nand_write(NAND_CMD_READSTART, NAND_CMD_CLE);
#endif

	while ((ltq_readl(&ltq_nand_regs->wait) & NAND_WAIT_READY) != NAND_WAIT_READY)
		;
}

static noinline void spl_nand_read_buf(u8 *buf, unsigned int len)
{
	void __iomem *io_addr = (void __iomem *)(CONFIG_SYS_NAND_BASE + NAND_CMD_CS);
	unsigned int i;

	for (i = 0; i < len; i++)
		buf[i] = ltq_readb(io_addr);
}

static noinline int spl_nand_read_page(int block, int page, void *dst)
{
	u8 ecc_calc[ECCTOTAL];
	u8 ecc_code[ECCTOTAL];
	u8 oob_data[CONFIG_SYS_NAND_OOBSIZE];
	int i;
	int eccsize = ECCSIZE;
	int eccbytes = ECCBYTES;
	int eccsteps = ECCSTEPS;
	u8 *p = dst;

	spl_nand_command(block, page, NAND_CMD_READ0);
	spl_nand_read_buf(p, CONFIG_SYS_NAND_PAGE_SIZE);
	spl_nand_read_buf(oob_data, CONFIG_SYS_NAND_OOBSIZE);

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize)
		nand_calculate_ecc(NULL, p, &ecc_calc[i]);

	for (i = 0; i < ECCTOTAL; i++)
		ecc_code[i] = oob_data[spl_nand_eccpos[i]];

	eccsteps = ECCSTEPS;
	p = dst;

	for (i = 0 ; eccsteps; eccsteps--, i += eccbytes, p += eccsize)
		nand_correct_data(NULL, p, &ecc_code[i], &ecc_calc[i]);

	return 0;
}

int nand_spl_load_image(uint32_t offs, unsigned int size, void *dst)
{
	unsigned int block = offs / CONFIG_SYS_NAND_BLOCK_SIZE;
	unsigned int lastblock = (offs + size - 1) / CONFIG_SYS_NAND_BLOCK_SIZE;
	unsigned int page = (offs % CONFIG_SYS_NAND_BLOCK_SIZE) /
					CONFIG_SYS_NAND_PAGE_SIZE;
	unsigned int cnt = 0;

	while (block <= lastblock) {
		while (page < CONFIG_SYS_NAND_PAGE_COUNT) {
			spl_nand_read_page(block, page, dst);
			dst += CONFIG_SYS_NAND_PAGE_SIZE;
			page++;

			cnt += CONFIG_SYS_NAND_PAGE_SIZE;
			if (cnt >= size)
				return 0;
		}
		page = 0;
		block++;
	}

	return 0;
}

void nand_init(void)
{
	/* Enable NAND, set NAND CS to EBU CS1, enable EBU CS mux */
	ltq_writel(&ltq_nand_regs->con, NAND_CON_LATCH_ALL |
#ifndef CONFIG_LTQ_SUPPORT_NAND_FLASH_CS0
		NAND_CON_OUT_CS1 | NAND_CON_IN_CS1 |
#endif
		NAND_CON_PRE_P | NAND_CON_WP_P |
		NAND_CON_SE_P | NAND_CON_CS_P | NAND_CON_CSMUX | NAND_CON_NANDM);
}
#endif
