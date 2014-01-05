/*
 * Copyright (C) 2003 Wolfgang Denk Engineering, <wd@denx.de>
 * Copyright (C) 2014 Antonios Vamporakis, <ant@area128.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/io.h>

#define FILE_SIZE 		CONFIG_SYS_NAND_U_BOOT_OFFS
#define STARTING_ADDRESS	CONFIG_SPL_TEXT_BASE
#define PAGE_SIZE		CONFIG_SYS_NAND_PAGE_SIZE
#define NAND_SIZE		(CONFIG_SYS_NAND_SIZE >> 20) /* in MB */

/* NAND controller control */
#define LTQ_EBU_NAND_CON	(LTQ_EBU_NAND_BASE | KSEG1)
/* NAND Flash Device RD/BY State */
#define LTQ_EBU_NAND_WAIT	((LTQ_EBU_NAND_BASE | KSEG1) + 0x04)

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
#define NAND_READY		(ltq_readl(LTQ_EBU_NAND_WAIT) & NAND_WAIT_RDBY)

#define NAND_CMD_ALE		(1 << 2)
#define NAND_CMD_CLE		(1 << 3)
#define NAND_CMD_CS		(1 << 4)
#define NAND_CMD_SE		(1 << 5)
#define NAND_CMD_WP		(1 << 6)
#define NAND_CMD_PRE		(1 << 7)

#define NAND_WRITE_CMD		(NAND_CMD_CS | NAND_CMD_CLE)
#define NAND_WRITE_ADDR		(NAND_CMD_CS | NAND_CMD_ALE)
#define NAND_READ_DATA		(NAND_CMD_CS)

#define NAND_BASE		CONFIG_SYS_NAND_BASE
#define NAND_WRITE(addr, val)	ltq_writeb(NAND_BASE | (addr), val); \
					while((ltq_readl(LTQ_EBU_NAND_WAIT) & NAND_WAIT_WR_C) == 0);

#define NAND_READ(addr, val)	val = ltq_readb(NAND_BASE | (addr))

static void read_page(u32 page_addr, u32 dest_addr)
{
	int i;
	u8 *tmp;
	u8 col_addr_num;
	u8 page_addr_num;

	if (PAGE_SIZE <= 0x200) {
		col_addr_num = 1;
		
		if (NAND_SIZE < 32) {
			page_addr_num = 2;
		} else {
			page_addr_num = 3;
		}
	} else {
		col_addr_num = 2;
		
		if (NAND_SIZE < 128){
			page_addr_num = 2;
		} else {
			page_addr_num = 3;
		}
	}

	NAND_WRITE(NAND_WRITE_CMD, 0);
	ltq_setbits(LTQ_EBU_NAND_CON, NAND_CON_LATCH_ALE);

	for (i = 0; i < col_addr_num; i++) {
		NAND_WRITE(NAND_WRITE_ADDR, 0);
	}

	for (i = 0; i < page_addr_num; i++) {
		NAND_WRITE(NAND_WRITE_ADDR, (u8)((page_addr >> (i * 8)) & 0xff));
	}

	ltq_clrbits(LTQ_EBU_NAND_CON, NAND_CON_LATCH_ALE);

	if (PAGE_SIZE > 0x200) {
		NAND_WRITE(NAND_WRITE_CMD, 0x30);
	}

	while (!NAND_READY) {}

	/* Read page */
	tmp = (u8*) dest_addr;
	for (i = 0; i < PAGE_SIZE; i++) {
		NAND_READ(NAND_READ_DATA, *tmp++);
	}

	while (!NAND_READY) {}
}

void main(void)
{
	int i;

	ltq_writel(LTQ_EBU_NAND_CON, NAND_CON_OUT_CS1 | NAND_CON_IN_CS1 |
		NAND_CON_PRE_P | NAND_CON_WP_P | NAND_CON_SE_P |
		NAND_CON_CS_P | NAND_CON_CSMUX | NAND_CON_LATCH_PRE |
		NAND_CON_LATCH_WP | NAND_CON_LATCH_SE | NAND_CON_LATCH_CS |
		NAND_CON_LATCH_ALE | NAND_CON_NANDM);

	for (i = 0; i < (FILE_SIZE / PAGE_SIZE + 1); i++) {
		read_page(i + 1, STARTING_ADDRESS + (PAGE_SIZE * i));
	}

	ltq_clrbits(LTQ_EBU_NAND_CON, NAND_CON_LATCH_CS);
	
	// jump start
	void (*start)(void);

	start = (void *)STARTING_ADDRESS;
	start();
}
