/*
 * AMAZON_S internal switch ethernet driver.
 *
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <malloc.h>
#include <net.h>
#include <miiphy.h>
#include <firmware.h>
#include <asm/addrspace.h>
#include <asm/mipsregs.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <mach/grx500.h>
#include <mach/lq_dma.h>
#include <mach/api.h>
#include <watchdog.h>
#include <console.h>

#include "lq_microcode.h"

/* Switch Offset */
#define TX_PORT 0
#define RX_PORT 0
#define TX_CHAN 0
#define RX_CHAN 0

#define NUM_RX_DESC PKTBUFSRX
#define NUM_TX_DESC 8
#define MAX_PACKET_SIZE 1536
#define TOUT_LOOP 100

#define DMA_TX_BASE DMA2_TX_MODULE_BASE
#define DMA_RX_BASE DMA2_RX_MODULE_BASE

#define MDIO_WRITE_CMD		BIT(10)
#define MDIO_READ_CMD		BIT(11)

#define NETPHYADDR(a) (CPHYSADDR(a) | 0x20000000)

#define GPHY2_RESET (1 << 29)
#define GPHY2_RST_STAT (1 << 28)

#define GPHY3_RESET (1 << 28)
#define GPHY3_RST_STAT (1 << 23)

#define GPHY4_RESET (1 << 26)
#define GPHY4_RST_STAT (1 << 22)

#define GPHY5_RESET (1 << 25)
#define GPHY5_RST_STAT (1 << 25)

#define GPHY6F_RESET (1 << 31)
#define GPHY6F_RST_STAT 0

#define GPHY_FW_NAME "intel/xrx550/phy11g_a21.bin"

#define GPHY_RESET_REQ                                                         \
	GPHY6F_RESET | GPHY2_RESET | GPHY3_RESET | GPHY4_RESET | GPHY5_RESET

#define GPHY_RESET_STAT                                                        \
	GPHY6F_RST_STAT | GPHY2_RST_STAT | GPHY3_RST_STAT | GPHY4_RST_STAT |   \
		GPHY5_RST_STAT

#define GPHY_ALIGN 16 * 1024

#define NUM_GSWL_PHY 4

static struct dma_rx_desc *rx_desc_base;
static struct dma_tx_desc *tx_desc_base;
static const size_t rx_desc_size = ALIGN(NUM_RX_DESC * sizeof(struct dma_rx_desc), ARCH_DMA_MINALIGN);
static const size_t tx_desc_size = ALIGN(NUM_TX_DESC * sizeof(struct dma_tx_desc), ARCH_DMA_MINALIGN);
static int tx_num, rx_num;
static pce_table_prog_t tbl_entry;

struct ltq_eth_priv {
	struct mii_dev *bus;
	struct eth_device *dev;
	struct phy_device *phymap[NUM_GSWL_PHY];
	int rx_num;
	int tx_num;
};

static struct dma_rx_desc *get_rx_desc(unsigned int num)
{
	if (num < NUM_RX_DESC)
		return (struct dma_rx_desc *)KSEG1ADDR(&rx_desc_base[num]);

	return NULL;
}

static struct dma_tx_desc *get_tx_desc(unsigned int num)
{
	if (num < NUM_TX_DESC)
		return (struct dma_tx_desc *)KSEG1ADDR(&tx_desc_base[num]);

	return NULL;
}

static inline bool ltq_mdio_is_busy(void)
{
	return REG32(GSWIP_TOP_L_MDIO_CTRL) & BIT(12);
}

static inline void ltq_mdio_poll(void)
{
	while (ltq_mdio_is_busy())
		cpu_relax();
}

static int ltq_mdio_read(struct mii_dev *bus, int phyad, int devad,
				 int regad)
{
	int retval;

	ltq_mdio_poll();
	REG32(GSWIP_TOP_L_MDIO_CTRL) = MDIO_READ_CMD | (phyad << 5) | regad;
	mdelay(10);
	retval = REG32(GSWIP_TOP_L_MDIO_READ);

	debug("%s: phyad %x, regad %x, val %x\n",
		__func__, phyad, regad, retval);

	return retval;
}

static int ltq_mdio_write(struct mii_dev *bus, int phyad, int devad,
					int regad, u16 val)
{
	debug("%s: phyad %x, regad %x, val %x\n",
		__func__, phyad, regad, val);

	ltq_mdio_poll();
	REG32(GSWIP_TOP_L_MDIO_WRITE) = val;
	REG32(GSWIP_TOP_L_MDIO_CTRL) = MDIO_WRITE_CMD | phyad << 5 | regad;
	ltq_mdio_poll();

	return 0;
}

#ifdef CONFIG_DEBUG
static void debug_dma_reg(char *dir, int chan, int port, u32 base)
{
	printf("%s DMA reg dump\n", dir);
	REG32(base + DMA_CS) = chan;
	printf("DMA_CPOLL: %08x\n", REG32(base + DMA_CPOLL));
	printf("DMA_CDBA: %08x\n", REG32(base + DMA_CDBA));
	printf("DMA_CDLEN: %08x\n", REG32(base + DMA_CDLEN));
	printf("DMA_CIE: %08x\n", REG32(base + DMA_CIE));
	printf("DMA_CCTRL: %08x\n", REG32(base + DMA_CCTRL));
	printf("DMA_IRNEN: %08x\n", REG32(base + DMA_IRNEN));
	printf("DMA_IRNCR: %08x\n", REG32(base + DMA_IRNCR));
	printf("DMA_CTRL: %08x\n", REG32(base + DMA_CTRL));
	printf("DMA_CDPTNRD : %08x\n", REG32(base + DMA_CDPTNRD));

	REG32(base + DMA_PS) = port;
	printf("DMA_PCTRL: %08x\n", REG32(base + DMA_PCTRL));
}
#endif

static int xwayflow_pce_table_write(u32 base_addr, void *pDevCtx,
			     pce_table_prog_t *pData)
{
	u32 value;

	do {
		gsw_r32(base_addr, PCE_TBL_CTRL_BAS_OFFSET,
			PCE_TBL_CTRL_BAS_SHIFT, PCE_TBL_CTRL_BAS_SIZE, &value);
	} while (value);

	gsw_w32(base_addr, PCE_TBL_ADDR_ADDR_OFFSET, PCE_TBL_ADDR_ADDR_SHIFT,
		PCE_TBL_ADDR_ADDR_SIZE, pData->table_index);
	value = pData->table;
	gsw_w32(base_addr, PCE_TBL_CTRL_ADDR_OFFSET, PCE_TBL_CTRL_ADDR_SHIFT,
		PCE_TBL_CTRL_ADDR_SIZE, value);
	gsw_w32(base_addr, PCE_TBL_CTRL_OPMOD_OFFSET, PCE_TBL_CTRL_OPMOD_SHIFT,
		PCE_TBL_CTRL_OPMOD_SIZE, TABLE_ACCESS_OP_MODE_ADWR);
	gsw_w32(base_addr, PCE_TBL_KEY_15_KEY15_OFFSET,
		PCE_TBL_KEY_15_KEY15_SHIFT, PCE_TBL_KEY_15_KEY15_SIZE,
		pData->key[15]);
	gsw_w32(base_addr, PCE_TBL_KEY_14_KEY14_OFFSET,
		PCE_TBL_KEY_14_KEY14_SHIFT, PCE_TBL_KEY_14_KEY14_SIZE,
		pData->key[14]);
	gsw_w32(base_addr, PCE_TBL_KEY_13_KEY13_OFFSET,
		PCE_TBL_KEY_13_KEY13_SHIFT, PCE_TBL_KEY_13_KEY13_SIZE,
		pData->key[13]);
	gsw_w32(base_addr, PCE_TBL_KEY_12_KEY12_OFFSET,
		PCE_TBL_KEY_12_KEY12_SHIFT, PCE_TBL_KEY_12_KEY12_SIZE,
		pData->key[12]);
	gsw_w32(base_addr, PCE_TBL_KEY_11_KEY11_OFFSET,
		PCE_TBL_KEY_11_KEY11_SHIFT, PCE_TBL_KEY_11_KEY11_SIZE,
		pData->key[11]);
	gsw_w32(base_addr, PCE_TBL_KEY_10_KEY10_OFFSET,
		PCE_TBL_KEY_10_KEY10_SHIFT, PCE_TBL_KEY_10_KEY10_SIZE,
		pData->key[10]);
	gsw_w32(base_addr, PCE_TBL_KEY_9_KEY9_OFFSET, PCE_TBL_KEY_9_KEY9_SHIFT,
		PCE_TBL_KEY_9_KEY9_SIZE, pData->key[9]);
	gsw_w32(base_addr, PCE_TBL_KEY_8_KEY8_OFFSET, PCE_TBL_KEY_8_KEY8_SHIFT,
		PCE_TBL_KEY_8_KEY8_SIZE, pData->key[8]);
	gsw_w32(base_addr, PCE_TBL_KEY_7_KEY7_OFFSET, PCE_TBL_KEY_7_KEY7_SHIFT,
		PCE_TBL_KEY_7_KEY7_SIZE, pData->key[7]);
	gsw_w32(base_addr, PCE_TBL_KEY_6_KEY6_OFFSET, PCE_TBL_KEY_6_KEY6_SHIFT,
		PCE_TBL_KEY_6_KEY6_SIZE, pData->key[6]);
	gsw_w32(base_addr, PCE_TBL_KEY_5_KEY5_OFFSET, PCE_TBL_KEY_5_KEY5_SHIFT,
		PCE_TBL_KEY_5_KEY5_SIZE, pData->key[5]);
	gsw_w32(base_addr, PCE_TBL_KEY_4_KEY4_OFFSET, PCE_TBL_KEY_4_KEY4_SHIFT,
		PCE_TBL_KEY_4_KEY4_SIZE, pData->key[4]);
	gsw_w32(base_addr, PCE_TBL_KEY_3_KEY3_OFFSET, PCE_TBL_KEY_3_KEY3_SHIFT,
		PCE_TBL_KEY_3_KEY3_SIZE, pData->key[3]);
	gsw_w32(base_addr, PCE_TBL_KEY_2_KEY2_OFFSET, PCE_TBL_KEY_2_KEY2_SHIFT,
		PCE_TBL_KEY_2_KEY2_SIZE, pData->key[2]);
	gsw_w32(base_addr, PCE_TBL_KEY_1_KEY1_OFFSET, PCE_TBL_KEY_1_KEY1_SHIFT,
		PCE_TBL_KEY_1_KEY1_SIZE, pData->key[1]);
	gsw_w32(base_addr, PCE_TBL_KEY_0_KEY0_OFFSET, PCE_TBL_KEY_0_KEY0_SHIFT,
		PCE_TBL_KEY_0_KEY0_SIZE, pData->key[0]);
	gsw_w32(base_addr, PCE_TBL_MASK_0_MASK0_OFFSET,
		PCE_TBL_MASK_0_MASK0_SHIFT, PCE_TBL_MASK_0_MASK0_SIZE,
		pData->mask[0]);
	gsw_w32(base_addr, PCE_TBL_MASK_1_MASK1_OFFSET,
		PCE_TBL_MASK_1_MASK1_SHIFT, PCE_TBL_MASK_1_MASK1_SIZE,
		pData->mask[1]);
	gsw_w32(base_addr, PCE_TBL_MASK_2_MASK2_OFFSET,
		PCE_TBL_MASK_2_MASK2_SHIFT, PCE_TBL_MASK_2_MASK2_SIZE,
		pData->mask[2]);
	gsw_w32(base_addr, PCE_TBL_MASK_3_MASK3_OFFSET,
		PCE_TBL_MASK_3_MASK3_SHIFT, PCE_TBL_MASK_3_MASK3_SIZE,
		pData->mask[3]);

	gsw_w32(base_addr, PCE_TBL_VAL_15_VAL15_OFFSET,
		PCE_TBL_VAL_15_VAL15_SHIFT, PCE_TBL_VAL_15_VAL15_SIZE,
		pData->val[15]);
	gsw_w32(base_addr, PCE_TBL_VAL_14_VAL14_OFFSET,
		PCE_TBL_VAL_14_VAL14_SHIFT, PCE_TBL_VAL_14_VAL14_SIZE,
		pData->val[14]);
	gsw_w32(base_addr, PCE_TBL_VAL_13_VAL13_OFFSET,
		PCE_TBL_VAL_13_VAL13_SHIFT, PCE_TBL_VAL_13_VAL13_SIZE,
		pData->val[13]);
	gsw_w32(base_addr, PCE_TBL_VAL_12_VAL12_OFFSET,
		PCE_TBL_VAL_12_VAL12_SHIFT, PCE_TBL_VAL_12_VAL12_SIZE,
		pData->val[12]);
	gsw_w32(base_addr, PCE_TBL_VAL_11_VAL11_OFFSET,
		PCE_TBL_VAL_11_VAL11_SHIFT, PCE_TBL_VAL_11_VAL11_SIZE,
		pData->val[11]);
	gsw_w32(base_addr, PCE_TBL_VAL_10_VAL10_OFFSET,
		PCE_TBL_VAL_10_VAL10_SHIFT, PCE_TBL_VAL_10_VAL10_SIZE,
		pData->val[10]);
	gsw_w32(base_addr, PCE_TBL_VAL_9_VAL9_OFFSET, PCE_TBL_VAL_9_VAL9_SHIFT,
		PCE_TBL_VAL_9_VAL9_SIZE, pData->val[9]);
	gsw_w32(base_addr, PCE_TBL_VAL_8_VAL8_OFFSET, PCE_TBL_VAL_8_VAL8_SHIFT,
		PCE_TBL_VAL_8_VAL8_SIZE, pData->val[8]);
	gsw_w32(base_addr, PCE_TBL_VAL_7_VAL7_OFFSET, PCE_TBL_VAL_7_VAL7_SHIFT,
		PCE_TBL_VAL_7_VAL7_SIZE, pData->val[7]);
	gsw_w32(base_addr, PCE_TBL_VAL_6_VAL6_OFFSET, PCE_TBL_VAL_6_VAL6_SHIFT,
		PCE_TBL_VAL_6_VAL6_SIZE, pData->val[6]);
	gsw_w32(base_addr, PCE_TBL_VAL_5_VAL5_OFFSET, PCE_TBL_VAL_5_VAL5_SHIFT,
		PCE_TBL_VAL_5_VAL5_SIZE, pData->val[5]);
	gsw_w32(base_addr, PCE_TBL_VAL_4_VAL4_OFFSET, PCE_TBL_VAL_4_VAL4_SHIFT,
		PCE_TBL_VAL_4_VAL4_SIZE, pData->val[4]);
	gsw_w32(base_addr, PCE_TBL_VAL_3_VAL3_OFFSET, PCE_TBL_VAL_3_VAL3_SHIFT,
		PCE_TBL_VAL_3_VAL3_SIZE, pData->val[3]);
	gsw_w32(base_addr, PCE_TBL_VAL_2_VAL2_OFFSET, PCE_TBL_VAL_2_VAL2_SHIFT,
		PCE_TBL_VAL_2_VAL2_SIZE, pData->val[2]);
	gsw_w32(base_addr, PCE_TBL_VAL_1_VAL1_OFFSET, PCE_TBL_VAL_1_VAL1_SHIFT,
		PCE_TBL_VAL_1_VAL1_SIZE, pData->val[1]);
	gsw_w32(base_addr, PCE_TBL_VAL_0_VAL0_OFFSET, PCE_TBL_VAL_0_VAL0_SHIFT,
		PCE_TBL_VAL_0_VAL0_SIZE, pData->val[0]);
	gsw_w32(base_addr, PCE_TBL_CTRL_KEYFORM_OFFSET,
		PCE_TBL_CTRL_KEYFORM_SHIFT, PCE_TBL_CTRL_KEYFORM_SIZE,
		pData->key_format);
	gsw_w32(base_addr, PCE_TBL_CTRL_TYPE_OFFSET, PCE_TBL_CTRL_TYPE_SHIFT,
		PCE_TBL_CTRL_TYPE_SIZE, pData->type);
	gsw_w32(base_addr, PCE_TBL_CTRL_VLD_OFFSET, PCE_TBL_CTRL_VLD_SHIFT,
		PCE_TBL_CTRL_VLD_SIZE, pData->valid);
	gsw_w32(base_addr, PCE_TBL_CTRL_GMAP_OFFSET, PCE_TBL_CTRL_GMAP_SHIFT,
		PCE_TBL_CTRL_GMAP_SIZE, pData->group);
	gsw_w32(base_addr, PCE_TBL_CTRL_BAS_OFFSET, PCE_TBL_CTRL_BAS_SHIFT,
		PCE_TBL_CTRL_BAS_SIZE, GSW_TRUE);
	do {
		gsw_r32(base_addr, PCE_TBL_CTRL_BAS_OFFSET,
			PCE_TBL_CTRL_BAS_SHIFT, PCE_TBL_CTRL_BAS_SIZE, &value);
	} while (value != 0);
	gsw_r32(base_addr, PCE_TBL_CTRL_BAS_OFFSET, 0, 15, &value);
	return 0;
}

static u32 gsw_micro_code_dl_30(u32 base_addr)
{
	u8 i = 0;

	gsw_w32(base_addr, PCE_GCTRL_0_MC_VALID_OFFSET,
		PCE_GCTRL_0_MC_VALID_SHIFT, PCE_GCTRL_0_MC_VALID_SIZE, 0x0);

	/* Download the microcode  */
	for (i = 0; i < 150; i++) {
		memset(&tbl_entry, 0, sizeof(tbl_entry));
		tbl_entry.val[3] = pce_mc_max_ifx_tag_m_30[i].val_3;
		tbl_entry.val[2] = pce_mc_max_ifx_tag_m_30[i].val_2;
		tbl_entry.val[1] = pce_mc_max_ifx_tag_m_30[i].val_1;
		tbl_entry.val[0] = pce_mc_max_ifx_tag_m_30[i].val_0;
		tbl_entry.table_index = i;
		tbl_entry.table = 0;
#if 0
		debug("\n %2d v3: %8x v2: %8x v1: %8x v0: %8x", i,
		      tbl_entry.val[3], tbl_entry.val[2], tbl_entry.val[1],
		      tbl_entry.val[0]);
#endif
		xwayflow_pce_table_write(base_addr, NULL, &tbl_entry);
	}

	gsw_w32(base_addr, PCE_GCTRL_0_MC_VALID_OFFSET,
		PCE_GCTRL_0_MC_VALID_SHIFT, PCE_GCTRL_0_MC_VALID_SIZE, 0x1);

	return 0;
}

static void ltq_dma_rx_chan_enable(void)
{
	debug("%s:\n", __func__);

	REG32(DMA_RX_BASE + DMA_CS) = RX_CHAN;
	ltq_dma_w32_mask(0, (1 << DMA_CCTRL_ON_OFF_POS), DMA_RX_BASE + DMA_CCTRL);
}

static void ltq_dma_rx_chan_reset(void)
{
	debug("%s:\n", __func__);

	REG32(DMA_RX_BASE + DMA_CS) = RX_CHAN;
	ltq_dma_w32_mask((1 << DMA_CCTRL_ON_OFF_POS), 0, DMA_RX_BASE + DMA_CCTRL);

	memset(rx_desc_base, 0, rx_desc_size);
	flush_dcache_range((ulong)rx_desc_base, (ulong)rx_desc_base + rx_desc_size);

	ltq_dma_w32_mask(0, (1 << DMA_CCTRL_RST_POS), DMA_RX_BASE + DMA_CCTRL);
}

static void ltq_dma_rx_chan_init(void)
{
	debug("%s:\n", __func__);

	rx_desc_base = memalign(ARCH_DMA_MINALIGN, rx_desc_size);
	if (!rx_desc_base) {
		debug("failed to alloc rx_desc_ring\n");
		return;
	}

	memset(rx_desc_base, 0, rx_desc_size);
	flush_dcache_range((ulong)rx_desc_base, (ulong)rx_desc_base + rx_desc_size);

	REG32(DMA_RX_BASE + DMA_CS) = RX_CHAN;
	REG32(DMA_RX_BASE + DMA_CDBA) = CPHYSADDR(rx_desc_base);
	REG32(DMA_RX_BASE + DMA_CDLEN) = NUM_RX_DESC;
	REG32(DMA_RX_BASE + DMA_CIE) = 0;

	debug("%s: rx_desc_base %p, rx_desc_size %x, cdba %08x\n", __func__,
		rx_desc_base, rx_desc_size, REG32(DMA_RX_BASE + DMA_CDBA));

	/* Reset channel */
	REG32(DMA_RX_BASE + DMA_CCTRL) = 0x10000 | BIT(DMA_CCTRL_RST_POS);

	while (REG32(DMA_RX_BASE + DMA_CCTRL) & BIT(DMA_CCTRL_RST_POS))
		cpu_relax();
}

static void ltq_dma_rx_dma_init(void)
{
	debug("%s:\n", __func__);
#if 0
	/* Reset DMA */
	ltq_dma_w32_mask(0, BIT(DMA_CTRL_RST_POS), DMA_RX_BASE + DMA_CTRL);
	sync();
#endif

	/* Disable and clear all interrupts */
	ltq_dma_w32_mask((1 << (RX_CHAN & 0x1f)), 0, DMA_RX_BASE + DMA_IRNEN);
	ltq_dma_w32_mask(0, (1 << (RX_CHAN & 0x1f)), DMA_RX_BASE + DMA_IRNCR);

	/* Enable desciptor polling */
	REG32(DMA_RX_BASE + DMA_CPOLL) = BIT(DMA_CPOLL_EN_POS) | (0x18 << DMA_CPOLL_CNT_POS);

	/* Init port */
	REG32(DMA_RX_BASE + DMA_PS) = RX_PORT;
	REG32(DMA_RX_BASE + DMA_PCTRL) = 0x1f28;
}

static void ltq_dma_tx_chan_enable(void)
{
	debug("%s:\n", __func__);

	REG32(DMA_TX_BASE + DMA_CS) = TX_CHAN;
	ltq_dma_w32_mask(0, (1 << DMA_CCTRL_ON_OFF_POS), DMA_TX_BASE + DMA_CCTRL);
}

static void ltq_dma_tx_chan_reset(void)
{
	debug("%s:\n", __func__);

	REG32(DMA_TX_BASE + DMA_CS) = TX_CHAN;
	ltq_dma_w32_mask((1 << DMA_CCTRL_ON_OFF_POS), 0, DMA_TX_BASE + DMA_CCTRL);

	memset(tx_desc_base, 0, tx_desc_size);
	flush_dcache_range((ulong)tx_desc_base, (ulong)tx_desc_base + tx_desc_size);

	ltq_dma_w32_mask(0, (1 << DMA_CCTRL_RST_POS), DMA_TX_BASE + DMA_CCTRL);
}

static void ltq_dma_tx_chan_init(void)
{
	debug("%s:\n", __func__);

	tx_desc_base = memalign(ARCH_DMA_MINALIGN, tx_desc_size);
	if (!tx_desc_base) {
		debug("failed to alloc tx_desc_ring\n");
		return;
	}

	memset(tx_desc_base, 0, tx_desc_size);
	flush_dcache_range((ulong)tx_desc_base, (ulong)tx_desc_base + tx_desc_size);

	REG32(DMA_TX_BASE + DMA_CS) = TX_CHAN;
	REG32(DMA_TX_BASE + DMA_CDBA) = CPHYSADDR(tx_desc_base);
	REG32(DMA_TX_BASE + DMA_CDLEN) = NUM_TX_DESC;
	REG32(DMA_TX_BASE + DMA_CIE) = 0;

	debug("%s: tx_desc_base %p, tx_desc_size %x, cdba %08x\n", __func__,
		tx_desc_base, tx_desc_size, REG32(DMA_TX_BASE + DMA_CDBA));

	/* Reset channel */
	REG32(DMA_TX_BASE + DMA_CCTRL) = 0x10100 | BIT(DMA_CCTRL_RST_POS);

	while (REG32(DMA_TX_BASE + DMA_CCTRL) & BIT(DMA_CCTRL_RST_POS))
		cpu_relax();
}

static void ltq_dma_tx_dma_init(void)
{
	debug("%s:\n", __func__);

#if 0
	/* Reset DMA */
	ltq_dma_w32_mask(0, BIT(DMA_CTRL_RST_POS), DMA_TX_BASE + DMA_CTRL);
	sync();
#endif
	REG32(DMA_TX_BASE + DMA_CTRL) = 0x80040200;

	/* Disable and clear all interrupts */
	ltq_dma_w32_mask((1 << (TX_CHAN & 0x1f)), 0, DMA_TX_BASE + DMA_IRNEN);
	ltq_dma_w32_mask(0, (1 << (TX_CHAN & 0x1f)), DMA_TX_BASE + DMA_IRNCR);

	/* Enable desciptor polling */
	REG32(DMA_TX_BASE + DMA_CPOLL) = BIT(DMA_CPOLL_EN_POS) | (0x18 << DMA_CPOLL_CNT_POS);

	/* Init port */
	REG32(DMA_TX_BASE + DMA_PS) = RX_PORT;
	REG32(DMA_TX_BASE + DMA_PCTRL) = 0x1f28;
}

static int ltq_grx500_phy_startup(struct eth_device *dev)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct phy_device *phydev;
	int i, j;

	printf("Waiting for PHY link\n");
	for (j = 0; j < 2000; j++) {
		for (i = 0; i < NUM_GSWL_PHY; i++) {
			WATCHDOG_RESET();

			phydev = priv->phymap[i];
			if (!phydev)
				continue;

			phy_startup(phydev);
			if (phydev->link) {
				printf("Using PHY at addr %d, speed %d, duplex %d\n",
					phydev->addr, phydev->speed,
					phydev->duplex);
				return 0;
			}
		}

		if (ctrlc())
			return -1;

		udelay(100);
	}
	return -1;
}

static int ltq_grx500_switch_init(struct eth_device *dev, bd_t *bis)
{
	int i, err;

	tx_num = 0;
	rx_num = 0;

	err = ltq_grx500_phy_startup(dev);
	if (err) {
		puts("No PHY link found\n");
		return -1;
	}

	for (i = 0; i < NUM_RX_DESC; i++) {
		struct dma_rx_desc *rx_desc = get_rx_desc(i);
		void *packet = net_rx_packets[i];
		const u32 dma_addr = CPHYSADDR(packet);
		const u32 offset = dma_addr % 16;

		debug("%s: i %d, rx_desc %p, packet %p, length %u, dma_addr %08x, offset %u\n",
			__func__, i, rx_desc, packet, PKTSIZE_ALIGN, dma_addr, offset);

		rx_desc->DW0.all = 0;
		rx_desc->DW1.all = 0;
		rx_desc->DW2.field.address = dma_addr - offset;
		rx_desc->DW3.all = 0;
		rx_desc->DW3.field.byteoffset = offset;
		rx_desc->DW3.field.datalen = PKTSIZE_ALIGN;
		wmb();
		rx_desc->DW3.field.own = 1;
	}

	ltq_dma_rx_chan_enable();
	ltq_dma_tx_chan_enable();

	return 0;
}

static void ltq_grx500_switch_halt(struct eth_device *dev)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct phy_device *phydev;
	int i;

	ltq_dma_rx_chan_reset();
	ltq_dma_tx_chan_reset();

	for (i = 0; i < NUM_GSWL_PHY; i++) {
		phydev = priv->phymap[i];
		if (!phydev)
			continue;

		phy_shutdown(phydev);
		phydev->link = 0;
	}
}

static int ltq_grx500_switch_send(struct eth_device *dev, void *packet,
				  int length)
{
	const u32 dma_addr = CPHYSADDR(packet);
	const u32 offset = dma_addr % 16;
	struct dma_tx_desc *tx_desc = get_tx_desc(tx_num);
	int i = 0;

	debug_cond(DEBUG_DEV_PKT, "%s: tx_num %d, tx_desc %p, packet %p, length %u, dma_addr %08x, offset %u\n",
		__func__, tx_num, tx_desc, packet, length, dma_addr, offset);

	while (tx_desc->DW3.field.own == 1) {
		if (i++ > 100) {
			puts("No free TX descriptor\n");
			return -EBUSY;
		}
	}

	if (length < 60)
		length = 60;

	flush_dcache_range((ulong)packet, (ulong)packet + length);

	tx_desc->DW0.all = 0;
	tx_desc->DW1.all = 0;
	tx_desc->DW2.field.address = dma_addr - offset;
	tx_desc->DW3.all = 0;
	tx_desc->DW3.field.sop = 1;
	tx_desc->DW3.field.eop = 1;
	tx_desc->DW3.field.byteoffset = offset;
	tx_desc->DW3.field.datalen = length;
	wmb();
	tx_desc->DW3.field.own = 1;

	tx_num = (tx_num + 1) % NUM_TX_DESC;

	return 0;
}

static int ltq_grx500_switch_recv_packet(struct eth_device *dev, void *packet)
{
	struct dma_rx_desc *rx_desc = get_rx_desc(rx_num);
	unsigned int length;

	/* descriptor owned by HW, retry later */
	if (rx_desc->DW3.field.own == 1)
		return -EAGAIN;

	/* transfer not yet completed by HW, retry later */
	if (rx_desc->DW3.field.c == 0)
		return -EAGAIN;

	rmb();
	length = rx_desc->DW3.field.datalen;

	debug_cond(DEBUG_DEV_PKT, "%s: rx_num %d, rx_desc %p, packet %p, length %u\n",
		__func__, rx_num, rx_desc, packet, length);

	/* zero length transfer, don't process packet but release descriptor */
	if (!length)
		return 0;

	invalidate_dcache_range((ulong)packet, (ulong)packet + PKTSIZE_ALIGN);

	return length;
}

static void ltq_grx500_switch_free_packet(struct eth_device *dev, void *packet)
{
	struct dma_rx_desc *rx_desc = get_rx_desc(rx_num);
	const u32 dma_addr = CPHYSADDR(packet);
	const u32 offset = dma_addr % 16;

	debug_cond(DEBUG_DEV_PKT, "%s: rx_num %d, rx_desc %p, packet %p\n",
		__func__, rx_num, rx_desc, packet);

	rx_desc->DW0.all = 0;
	rx_desc->DW1.all = 0;
	rx_desc->DW2.field.address = dma_addr - offset;
	rx_desc->DW3.all = 0;
	rx_desc->DW3.field.byteoffset = offset;
	rx_desc->DW3.field.datalen = PKTSIZE_ALIGN;
	wmb();
	rx_desc->DW3.field.own = 1;

	rx_num = (rx_num + 1) % NUM_RX_DESC;
}

static int ltq_grx500_switch_recv(struct eth_device *dev)
{
	int ret, i;

	for (i = 0; i < 32; i++) {
		void *packet = net_rx_packets[rx_num];

		ret = ltq_grx500_switch_recv_packet(dev, packet);
		if (ret > 0)
			net_process_received_packet(packet, ret);

		if (ret >= 0)
			ltq_grx500_switch_free_packet(dev, packet);

		if (ret <= 0)
			break;
	}

	if (ret == -EAGAIN)
		ret = 0;

	return ret;
}

static void GSW_RMON_Enable(u32 base_addr)
{
	int i;

	for (i = 1; i <= 15; i++) {
		/* enable RMON counters */
		REG32(base_addr + GSW_BM_PCFG(i)) = 0x1;
	}
}

static void mdio_init(void)
{
	REG32(GSW_L_MDC_CFG_0) = 0x0;
	REG32(GSW_L_MDC_CFG_1) = 0x800f;

	udelay(100);

	REG32(GSW_L_MDC_CFG_1) = 0x0;
}

static void ltq_grx500_sw_chip_init(void)
{
	u8 i = 0;
	u32 fw_phy_addr;
	u32 fw_base_l, fw_base_h;
	u32 reset_req = GPHY_RESET_REQ;
	u32 reset_stat = GPHY_RESET_STAT;
	struct firmware gphy_fw;
	int err;
	void *fw_addr_p;

	/* Start of GPHY FW Initialization */
	mdio_init();

	err = request_firmware(&gphy_fw, GPHY_FW_NAME);
	if (err) {
		puts("failed to load GPHY firmware\n");
		return;
	}

	fw_addr_p = memalign(GPHY_ALIGN, gphy_fw.size);
	if (!fw_addr_p) {
		puts("failed to alloc GPHY memory\n");
		return;
	}

	memcpy(fw_addr_p, gphy_fw.data, gphy_fw.size);

	flush_cache((ulong)fw_addr_p, gphy_fw.size);

	fw_phy_addr = CPHYSADDR(fw_addr_p);
	debug("%s: fw_addr_p %p, fw_phy_addr %08x\n", __func__, fw_addr_p, fw_phy_addr);
	fw_base_l = fw_phy_addr & 0xFFFF;
	fw_base_h = (fw_phy_addr >> 16) & 0xFFFF;

	/* Reset GPHY (GPHY2, GPHY3, GPHY4, GPHY5, GPHY6F) */
	*RESET_REQ = reset_req;
	mdelay(100);

	/* Init GPHY2 */
	REG32(GSWIP_TOP_L_GPHY_BFDEV(1)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(1)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(1)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(1)) = fw_base_l;

	/* Init GPHY3 */
	REG32(GSWIP_TOP_L_GPHY_BFDEV(2)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(2)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(2)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(2)) = fw_base_l;

	/* Init GPHY5 -- done before GPHY4, intentionally */
	REG32(GSWIP_TOP_L_GPHY_BFDEV(4)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(4)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(4)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(4)) = fw_base_l;
	ltq_mdio_write(NULL, 0x5, MDIO_DEVAD_NONE, 0x9, 0x1300);

	/* Init GPHY4 */
	REG32(GSWIP_TOP_L_GPHY_BFDEV(3)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(3)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(3)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(3)) = fw_base_l;

	/* By default, GPHY6 registers below MUST be configured,
	 * otherwise WAN port will not work in kernel.
	 * However, if we do not intend to enable PHY6 for some reason,
	 * we do not bring PHY6 out of reset.
	 * Init GPHY6
	*/
	REG32(GSWIP_TOP_L_GPHY_BFDEV(5)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(5)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(5)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(5)) = fw_base_l;

	reset_req &= ~(GPHY6F_RESET);
	/* bring out GPHY out of reset */
	REG32(RESET_REQ) &= ~(reset_req);

	//printf("waiting for reset\n");
	while (*RESET_STAT & reset_stat)
		;

	mdelay(100);
	/* End of GPHY FW Initialization */

	REG32(GSW_BASE_ADDR) = 0x1;
	do {
		debug("Wait for reset\n");
	} while (REG32(GSW_BASE_ADDR) == 0x1);

	//Global Switch Macro Enable - GLOB_CTRL - Global Control Register
	REG32(GSW_BASE_ADDR + GSW_TOP_LVL_OFFSET) = 0x8000;

	/* from gswip_l() */
	for (i = 0; i < 5; i++) {
		/* PHY_ADDR_1 to PHY_ADDR_6 */
		REG32(GSW_BASE_ADDR + GSW_TOP_LVL_OFFSET + (0x44 + 4 * i) * 4) =
			0x1801 + i;
		/* MAC_CTRL_0_1 to MAC_CTRL_0_6 */
		REG32(GSW_BASE_ADDR + (0x903 + 12 * i) * 4) = 0x1C0;
	}

	/* AUTO-Polling Mode */
	REG32(GSW_L_MDC_CFG_0) = 0x07e;

	//Disable Autoneg
	REG32(GSW_BASE_ADDR + GSW_PMAC_CTRL_4) = 0x0;
	REG32(GSW_BASE_ADDR + GSW_PMAC_CTRL_2) = 0x4;

	// Enable RMON Counters for all Ports
	GSW_RMON_Enable(GSW_BASE_ADDR);
	gsw_micro_code_dl_30(GSW_BASE_ADDR);

	ltq_dma_rx_dma_init();
	ltq_dma_rx_chan_init();
	ltq_dma_tx_dma_init();
	ltq_dma_tx_chan_init();
}

static void ltq_grx500_port_init(struct ltq_eth_priv *priv, int i)
{
	struct phy_device *phydev;

	phydev = phy_connect(priv->bus, i + 2, priv->dev, PHY_INTERFACE_MODE_GMII);
	if (phydev)
		phy_config(phydev);

	priv->phymap[i] = phydev;
}

int grx500_eth_initialize(bd_t *bis)
{
	struct eth_device *dev;
	struct mii_dev *bus;
	struct ltq_eth_priv *priv;
	int ret, i;

	ltq_grx500_sw_chip_init();

	dev = calloc(1, sizeof(struct eth_device));
	if (!dev)
		return -1;

	priv = calloc(1, sizeof(struct ltq_eth_priv));
	if (!priv)
		return -1;

	bus = mdio_alloc();
	if (!bus)
		return -1;

	sprintf(dev->name, "grx550-eth");
	dev->priv = priv;
	dev->init = ltq_grx500_switch_init;
	dev->halt = ltq_grx500_switch_halt;
	dev->send = ltq_grx500_switch_send;
	dev->recv = ltq_grx500_switch_recv;

	sprintf(bus->name, "grx550-mdio");
	bus->read = ltq_mdio_read;
	bus->write = ltq_mdio_write;
	bus->priv = priv;

	priv->bus = bus;
	priv->dev = dev;

	ret = mdio_register(bus);
	if (ret)
		return -1;

	ret = eth_register(dev);
	if (ret)
		return -1;

	for (i = 0; i < 4; i++)
		ltq_grx500_port_init(priv, i);

	return 0;
}
