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
#include <config.h>
#include <malloc.h>
#include <net.h>
#include <miiphy.h>
#include <asm/addrspace.h>
#include <asm/pinstrap.h>
#include <asm/lq_dma.h>

#ifdef CONFIG_BOOT_FROM_NAND
#include <nand.h>
#endif

#ifdef CONFIG_BOOT_FROM_SPI
#include <spi_flash.h>
#endif

#include "lq_microcode.h"

#include <lzma/LzmaTypes.h>
#include <lzma/LzmaDec.h>
#include <lzma/LzmaTools.h>

/* Switch Offset */
#define GPIO_P42	42
#define GPIO_P43	43
#define TX_PORT		0	
#define RX_PORT		0
#define TX_CHAN 	0
#define RX_CHAN		0

#define NUM_RX_DESC PKTBUFSRX
#define NUM_TX_DESC 8
#define MAX_PACKET_SIZE     1536
#define TOUT_LOOP   100

#ifdef CONFIG_NETWORK_VIA_WAN
#define DMA_TX_BASE	DMA1_TX_MODULE_BASE
#define DMA_RX_BASE	DMA1_RX_MODULE_BASE
#else
#define DMA_TX_BASE DMA2_TX_MODULE_BASE
#define DMA_RX_BASE DMA2_RX_MODULE_BASE
#endif /* CONFIG_NETWORK_VIA_WAN */ 

#define MDIO_WRITE_CMD  ((0 << 11)| (1 <<10))
#define MDIO_READ_CMD  ((1 << 11) | (0<<10))

#ifdef CONFIG_CACHE_COHERENCE
#define DMA_IOCU_PHYS_OFFSET	0xA0000000
#define NETPHYADDR(a)	(CPHYSADDR(a) | 0x20000000) + DMA_IOCU_PHYS_OFFSET
#else
#define NETPHYADDR(a)	(CPHYSADDR(a) | 0x20000000)
#endif

#if defined(CONFIG_GRX500_PHY2)
#define	GPHY2_RESET		(1 << 29)
#define GPHY2_RST_STAT	(1 << 28) 
#else
#define GPHY2_RESET 	0
#define GPHY2_RST_STAT	0 
#endif

#if defined(CONFIG_GRX500_PHY3)
#define GPHY3_RESET 	(1 << 28)
#define GPHY3_RST_STAT	(1 << 23) 
#else
#define GPHY3_RESET 	0
#define GPHY3_RST_STAT	0 
#endif

#if defined(CONFIG_GRX500_PHY4)
#define GPHY4_RESET 	(1 << 26)
#define GPHY4_RST_STAT	(1 << 22) 
#else
#define GPHY4_RESET 	0
#define GPHY4_RST_STAT	0 
#endif

#if defined(CONFIG_GRX500_PHY5)
#define GPHY5_RESET 	(1 << 25)
#define GPHY5_RST_STAT	(1 << 25) 
#else
#define GPHY5_RESET 	0
#define GPHY5_RST_STAT	0 
#endif

#if defined(CONFIG_GRX500_PHY6F)
#define GPHY6F_RESET 	(1 << 31)
#define GPHY6F_RST_STAT	(1 << 30) 
#else
#define GPHY6F_RESET 	(1 << 31)
#define GPHY6F_RST_STAT	0
#endif

#define GPHY_RESET_REQ	GPHY6F_RESET | GPHY2_RESET | GPHY3_RESET | \
						GPHY4_RESET | GPHY5_RESET

#define GPHY_RESET_STAT GPHY6F_RST_STAT | GPHY2_RST_STAT | GPHY3_RST_STAT | \
		GPHY4_RST_STAT | GPHY5_RST_STAT

static _dma_rx_descriptor_t rx_des_ring[NUM_TX_DESC] __attribute__ ((aligned(32)));
static _dma_tx_descriptor_t tx_des_ring[NUM_TX_DESC] __attribute__ ((aligned(32)));
static int tx_num, rx_num;
pce_table_prog_t tbl_entry;

extern void flush_dcache_range(unsigned long start, unsigned long stop);
extern void clean_dcache_range(unsigned long start, unsigned long stop);
extern void invalidate_dcache_range(unsigned long start, unsigned long stop);
extern void flush_dcache(void);
extern void invalidate_dcache(void);
extern void invalidate_icache(void);
extern void mdelay (unsigned long msec);

static void ltq_grx500_dma_init(void);
int grx500_eth_initialize(bd_t * bis);

typedef struct {
    int on;
    int miimode;
    int miirate;
} grx500_sw_port;

static void hexdump(unsigned char *buf, unsigned int len)
{
    while (len--) {
		if (len && !(len%16))
			printf("\n");
        printf("%02x", *buf++);
	}
        printf("\n");
}

int xway_mii_read(char *devname, unsigned char addr,unsigned char reg, unsigned short *value)
{
    u16 i=0;
	while(REG32(GSWIP_TOP_L_MDIO_CTRL) & 0x1000);
	REG32(GSWIP_TOP_L_MDIO_CTRL) = MDIO_READ_CMD | (((u32)addr)<<5) | ((u32)reg) | 0x1000;
	while(REG32(GSWIP_TOP_L_MDIO_CTRL) & 0x1000) {
		i++;
    	if( i > 0x7fff) {
			printf("MDIO access time out!\n");
			break;
		}
    }
	asm("sync");
	mdelay(100);
    *value = (u16)(REG32(GSWIP_TOP_L_MDIO_READ));
    return 0;
}

int xway_mii_write(char *devname, unsigned char addr,unsigned char reg, unsigned short value)
{
	u16 i=0;
	REG32(GSWIP_TOP_L_MDIO_WRITE)= value;
    while(REG32(GSWIP_TOP_L_MDIO_CTRL) & 0x1000);
    REG32(GSWIP_TOP_L_MDIO_CTRL) =  MDIO_WRITE_CMD | (((u32)addr)<<5) | ((u32)reg) | 0x1000;
    while(REG32(GSWIP_TOP_L_MDIO_CTRL) & 0x1000) {
    	i++;
	    if(i>0x7fff) {
        	printf("MDIO access time out!\n");
            break;
        }
    }
    return 0;
}

int xway_gphy_mmd_write_l(unsigned char gphy_number, unsigned char dev_addr, unsigned char reg_addr,
						unsigned char value) 
{
	xway_mii_write(NULL, gphy_number, 0x0d, dev_addr);
	xway_mii_write(NULL, gphy_number, 0x0e, reg_addr);
	xway_mii_write(NULL, gphy_number, 0x0d, ((1 << 14) | dev_addr));
	xway_mii_write(NULL, gphy_number, 0x0e, value);

}

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

int xwayflow_pce_table_write(u32 base_addr, void *pDevCtx, pce_table_prog_t *pData)
{
	u32 value,i=0;
	do {
		gsw_r32(base_addr, PCE_TBL_CTRL_BAS_OFFSET,  \
				PCE_TBL_CTRL_BAS_SHIFT, PCE_TBL_CTRL_BAS_SIZE, &value);
	} while (value);
	gsw_w32(base_addr, PCE_TBL_ADDR_ADDR_OFFSET,          \
			PCE_TBL_ADDR_ADDR_SHIFT, PCE_TBL_ADDR_ADDR_SIZE, pData->table_index);
	value = pData->table;
	gsw_w32(base_addr, PCE_TBL_CTRL_ADDR_OFFSET,            \
			PCE_TBL_CTRL_ADDR_SHIFT, PCE_TBL_CTRL_ADDR_SIZE, value);
	gsw_w32(base_addr, PCE_TBL_CTRL_OPMOD_OFFSET,       \
			PCE_TBL_CTRL_OPMOD_SHIFT, PCE_TBL_CTRL_OPMOD_SIZE, TABLE_ACCESS_OP_MODE_ADWR);
	gsw_w32(base_addr, PCE_TBL_KEY_15_KEY15_OFFSET,            \
			PCE_TBL_KEY_15_KEY15_SHIFT, PCE_TBL_KEY_15_KEY15_SIZE, pData->key[15]);
	gsw_w32(base_addr, PCE_TBL_KEY_14_KEY14_OFFSET,            \
			PCE_TBL_KEY_14_KEY14_SHIFT, PCE_TBL_KEY_14_KEY14_SIZE, pData->key[14]);
	gsw_w32(base_addr, PCE_TBL_KEY_13_KEY13_OFFSET,            \
			PCE_TBL_KEY_13_KEY13_SHIFT, PCE_TBL_KEY_13_KEY13_SIZE, pData->key[13]);
	gsw_w32(base_addr, PCE_TBL_KEY_12_KEY12_OFFSET,            \
			PCE_TBL_KEY_12_KEY12_SHIFT, PCE_TBL_KEY_12_KEY12_SIZE, pData->key[12]);
	gsw_w32(base_addr, PCE_TBL_KEY_11_KEY11_OFFSET,            \
			PCE_TBL_KEY_11_KEY11_SHIFT, PCE_TBL_KEY_11_KEY11_SIZE, pData->key[11]);
	gsw_w32(base_addr, PCE_TBL_KEY_10_KEY10_OFFSET,            \
			PCE_TBL_KEY_10_KEY10_SHIFT, PCE_TBL_KEY_10_KEY10_SIZE, pData->key[10]);
	gsw_w32(base_addr, PCE_TBL_KEY_9_KEY9_OFFSET,            \
			PCE_TBL_KEY_9_KEY9_SHIFT, PCE_TBL_KEY_9_KEY9_SIZE, pData->key[9]);
	gsw_w32(base_addr, PCE_TBL_KEY_8_KEY8_OFFSET,            \
			PCE_TBL_KEY_8_KEY8_SHIFT, PCE_TBL_KEY_8_KEY8_SIZE, pData->key[8]);
	gsw_w32(base_addr, PCE_TBL_KEY_7_KEY7_OFFSET,            \
			PCE_TBL_KEY_7_KEY7_SHIFT, PCE_TBL_KEY_7_KEY7_SIZE, pData->key[7]);
	gsw_w32(base_addr, PCE_TBL_KEY_6_KEY6_OFFSET,            \
			PCE_TBL_KEY_6_KEY6_SHIFT, PCE_TBL_KEY_6_KEY6_SIZE, pData->key[6]);
	gsw_w32(base_addr, PCE_TBL_KEY_5_KEY5_OFFSET,            \
			PCE_TBL_KEY_5_KEY5_SHIFT, PCE_TBL_KEY_5_KEY5_SIZE, pData->key[5]);
	gsw_w32(base_addr, PCE_TBL_KEY_4_KEY4_OFFSET,            \
			PCE_TBL_KEY_4_KEY4_SHIFT, PCE_TBL_KEY_4_KEY4_SIZE, pData->key[4]);
	gsw_w32(base_addr, PCE_TBL_KEY_3_KEY3_OFFSET,            \
			PCE_TBL_KEY_3_KEY3_SHIFT, PCE_TBL_KEY_3_KEY3_SIZE, pData->key[3]);
	gsw_w32(base_addr, PCE_TBL_KEY_2_KEY2_OFFSET,            \
			PCE_TBL_KEY_2_KEY2_SHIFT, PCE_TBL_KEY_2_KEY2_SIZE, pData->key[2]);
	gsw_w32(base_addr, PCE_TBL_KEY_1_KEY1_OFFSET,            \
			PCE_TBL_KEY_1_KEY1_SHIFT, PCE_TBL_KEY_1_KEY1_SIZE, pData->key[1]);
	gsw_w32(base_addr, PCE_TBL_KEY_0_KEY0_OFFSET,            \
			PCE_TBL_KEY_0_KEY0_SHIFT, PCE_TBL_KEY_0_KEY0_SIZE, pData->key[0]);
	gsw_w32(base_addr, PCE_TBL_MASK_0_MASK0_OFFSET,  \
			PCE_TBL_MASK_0_MASK0_SHIFT, PCE_TBL_MASK_0_MASK0_SIZE, pData->mask[0]);
	gsw_w32(base_addr, PCE_TBL_MASK_1_MASK1_OFFSET,  \
			PCE_TBL_MASK_1_MASK1_SHIFT, PCE_TBL_MASK_1_MASK1_SIZE, pData->mask[1]);
	gsw_w32(base_addr, PCE_TBL_MASK_2_MASK2_OFFSET,  \
			PCE_TBL_MASK_2_MASK2_SHIFT, PCE_TBL_MASK_2_MASK2_SIZE, pData->mask[2]);
	gsw_w32(base_addr, PCE_TBL_MASK_3_MASK3_OFFSET,  \
			PCE_TBL_MASK_3_MASK3_SHIFT, PCE_TBL_MASK_3_MASK3_SIZE, pData->mask[3]);

	gsw_w32(base_addr, PCE_TBL_VAL_15_VAL15_OFFSET,          \
			PCE_TBL_VAL_15_VAL15_SHIFT, PCE_TBL_VAL_15_VAL15_SIZE, pData->val[15]);
	gsw_w32(base_addr, PCE_TBL_VAL_14_VAL14_OFFSET,          \
			PCE_TBL_VAL_14_VAL14_SHIFT, PCE_TBL_VAL_14_VAL14_SIZE, pData->val[14]);
	gsw_w32(base_addr, PCE_TBL_VAL_13_VAL13_OFFSET,          \
			PCE_TBL_VAL_13_VAL13_SHIFT, PCE_TBL_VAL_13_VAL13_SIZE, pData->val[13]);
	gsw_w32(base_addr, PCE_TBL_VAL_12_VAL12_OFFSET,          \
			PCE_TBL_VAL_12_VAL12_SHIFT, PCE_TBL_VAL_12_VAL12_SIZE, pData->val[12]);
	gsw_w32(base_addr, PCE_TBL_VAL_11_VAL11_OFFSET,          \
			PCE_TBL_VAL_11_VAL11_SHIFT, PCE_TBL_VAL_11_VAL11_SIZE, pData->val[11]);
	gsw_w32(base_addr, PCE_TBL_VAL_10_VAL10_OFFSET,          \
			PCE_TBL_VAL_10_VAL10_SHIFT, PCE_TBL_VAL_10_VAL10_SIZE, pData->val[10]);
	gsw_w32(base_addr, PCE_TBL_VAL_9_VAL9_OFFSET,          \
			PCE_TBL_VAL_9_VAL9_SHIFT, PCE_TBL_VAL_9_VAL9_SIZE, pData->val[9]);
	gsw_w32(base_addr, PCE_TBL_VAL_8_VAL8_OFFSET,          \
			PCE_TBL_VAL_8_VAL8_SHIFT, PCE_TBL_VAL_8_VAL8_SIZE, pData->val[8]);
	gsw_w32(base_addr, PCE_TBL_VAL_7_VAL7_OFFSET,          \
			PCE_TBL_VAL_7_VAL7_SHIFT, PCE_TBL_VAL_7_VAL7_SIZE, pData->val[7]);
	gsw_w32(base_addr, PCE_TBL_VAL_6_VAL6_OFFSET,          \
			PCE_TBL_VAL_6_VAL6_SHIFT, PCE_TBL_VAL_6_VAL6_SIZE, pData->val[6]);
	gsw_w32(base_addr, PCE_TBL_VAL_5_VAL5_OFFSET,          \
			PCE_TBL_VAL_5_VAL5_SHIFT, PCE_TBL_VAL_5_VAL5_SIZE, pData->val[5]);
	gsw_w32(base_addr, PCE_TBL_VAL_4_VAL4_OFFSET,          \
			PCE_TBL_VAL_4_VAL4_SHIFT, PCE_TBL_VAL_4_VAL4_SIZE, pData->val[4]);
	gsw_w32(base_addr, PCE_TBL_VAL_3_VAL3_OFFSET,          \
			PCE_TBL_VAL_3_VAL3_SHIFT, PCE_TBL_VAL_3_VAL3_SIZE, pData->val[3]);
	gsw_w32(base_addr, PCE_TBL_VAL_2_VAL2_OFFSET,          \
			PCE_TBL_VAL_2_VAL2_SHIFT, PCE_TBL_VAL_2_VAL2_SIZE, pData->val[2]);
	gsw_w32(base_addr, PCE_TBL_VAL_1_VAL1_OFFSET,          \
			PCE_TBL_VAL_1_VAL1_SHIFT, PCE_TBL_VAL_1_VAL1_SIZE, pData->val[1]);
	gsw_w32(base_addr, PCE_TBL_VAL_0_VAL0_OFFSET,          \
			PCE_TBL_VAL_0_VAL0_SHIFT, PCE_TBL_VAL_0_VAL0_SIZE, pData->val[0]);
	gsw_w32(base_addr, PCE_TBL_CTRL_KEYFORM_OFFSET,	\
			PCE_TBL_CTRL_KEYFORM_SHIFT, PCE_TBL_CTRL_KEYFORM_SIZE, pData->key_format);
	gsw_w32(base_addr, PCE_TBL_CTRL_TYPE_OFFSET,              \
			PCE_TBL_CTRL_TYPE_SHIFT, PCE_TBL_CTRL_TYPE_SIZE, pData->type);
	gsw_w32(base_addr, PCE_TBL_CTRL_VLD_OFFSET,                \
			PCE_TBL_CTRL_VLD_SHIFT, PCE_TBL_CTRL_VLD_SIZE, pData->valid);
	gsw_w32(base_addr, PCE_TBL_CTRL_GMAP_OFFSET,           \
			PCE_TBL_CTRL_GMAP_SHIFT, PCE_TBL_CTRL_GMAP_SIZE, pData->group);
	gsw_w32(base_addr, PCE_TBL_CTRL_BAS_OFFSET,                \
			PCE_TBL_CTRL_BAS_SHIFT, PCE_TBL_CTRL_BAS_SIZE, GSW_TRUE);
	do {
		gsw_r32(base_addr, PCE_TBL_CTRL_BAS_OFFSET,  \
				PCE_TBL_CTRL_BAS_SHIFT, PCE_TBL_CTRL_BAS_SIZE, &value);
	} while (value != 0);
	gsw_r32(base_addr, PCE_TBL_CTRL_BAS_OFFSET, 0, 15, &value);
	return 0;
}


u32 gsw_micro_code_dl_30(u32 base_addr)
{
    u8 i = 0;
 
    gsw_w32(base_addr, PCE_GCTRL_0_MC_VALID_OFFSET,   \
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
        debug("\n %2d v3: %8x v2: %8x v1: %8x v0: %8x", i, tbl_entry.val[3], tbl_entry.val[2], tbl_entry.val[1], tbl_entry.val[0]);
        xwayflow_pce_table_write(base_addr, NULL, &tbl_entry);
    }   
        
    gsw_w32(base_addr, PCE_GCTRL_0_MC_VALID_OFFSET,   \
            PCE_GCTRL_0_MC_VALID_SHIFT, PCE_GCTRL_0_MC_VALID_SIZE, 0x1);

#ifdef DEBUG
    for (i = 0; i < 150; i++)
    {
        tbl_entry.table_index = i;
        tbl_entry.table = 0;

        xwayflow_pce_table_read(NULL, &tbl_entry);

        printf("\n %2d v3: %8x v2: %8x v1: %8x v0: %8x", i, tbl_entry.val[3], tbl_entry.val[2], tbl_entry.val[1], tbl_entry.val[0]);
    }
    print("\n\t");
#endif
}

static int ltq_grx500_switch_init(struct eth_device *dev, bd_t * bis)
{
	int i;

	tx_num = 0;
	rx_num = 0;

	ltq_dma_w32_mask(0, (1 << DMA_CTRL_RST_POS), DMA_RX_BASE + DMA_CTRL);
    REG32(DMA_RX_BASE + DMA_PS) = RX_PORT;
    REG32(DMA_RX_BASE + DMA_PCTRL) = 0x1f28;
	
	REG32(DMA_RX_BASE + DMA_CS) = RX_CHAN;
	REG32(DMA_RX_BASE + DMA_CCTRL) = 0x2;
	while (REG32(DMA_RX_BASE + DMA_CCTRL) & 0x2) {};
	REG32(DMA_RX_BASE + DMA_CPOLL) = 0x80000180;
    REG32(DMA_RX_BASE + DMA_CDBA) = CPHYSADDR((u32)rx_des_ring) | 0x20000000;
    REG32(DMA_RX_BASE + DMA_CDLEN) = NUM_RX_DESC;	
	REG32(DMA_RX_BASE + DMA_CIE) = 0;
	REG32(DMA_RX_BASE + DMA_CCTRL) = 0x10000;

    ltq_dma_w32_mask((1 << (TX_CHAN & 0x1f)), 0, DMA_TX_BASE + DMA_IRNEN);
	REG32(DMA_TX_BASE + DMA_PS) = TX_PORT;
    REG32(DMA_TX_BASE + DMA_PCTRL) = 0x1f28;

	REG32(DMA_TX_BASE + DMA_CS) = TX_CHAN;
	REG32(DMA_TX_BASE + DMA_CCTRL) = 0x2;
	while (REG32(DMA_TX_BASE + DMA_CCTRL) & 0x2) {};
	REG32(DMA_TX_BASE + DMA_CPOLL) = 0x80000180;
	REG32(DMA_TX_BASE + DMA_CDBA) = CPHYSADDR((u32)tx_des_ring) | 0x20000000;
	REG32(DMA_TX_BASE + DMA_CDLEN) = NUM_TX_DESC;
	REG32(DMA_TX_BASE + DMA_CIE) = 0;
	REG32(DMA_TX_BASE + DMA_CCTRL) = 0x10100;
	REG32(DMA_TX_BASE + DMA_CTRL) = 0x80040200;

	for (i = 0; i < NUM_TX_DESC; i++) {
		_dma_tx_descriptor_t *tx_desc = (_dma_tx_descriptor_t *)KSEG1ADDR(&tx_des_ring[i]);
		memset(tx_desc, 0, sizeof(tx_des_ring[0]));
		//tx_desc->DW0.all = 0;
        //tx_desc->DW1.all = 0;
        //tx_desc->DW3.all = 0x5C4A006E;
        tx_desc->DW3.field.byteoffset = 0;
	}
	for (i = 0; i < NUM_RX_DESC; i++) {
		_dma_rx_descriptor_t *rx_desc = (_dma_rx_descriptor_t *) KSEG1ADDR(&rx_des_ring[i]);
        rx_desc->DW0.all = 0;
        rx_desc->DW1.all = 0;
        rx_desc->DW3.all = 0xC8721234;
        rx_desc->DW3.field.byteoffset = 0;
        rx_desc->DW3.field.own = 1;
		rx_desc->DW3.field.datalen = (u16) PKTSIZE_ALIGN;
		rx_desc->DW2.all = ((CPHYSADDR((u32) NetRxPackets[i])) | 0x20000000) & 0xfffffff8;
		invalidate_dcache_range((u32)&rx_des_ring[i],(u32)&rx_des_ring[i]+8);
	}

	/* switch on rx chan */
    ltq_dma_w32(RX_CHAN, DMA_RX_BASE + DMA_CS);
	ltq_dma_w32_mask(0, (1 << DMA_CCTRL_ON_OFF_POS),
        DMA_RX_BASE +  DMA_CCTRL);

	return 0;
}

static void ltq_grx500_switch_halt(struct eth_device *dev)
{
	int i = 0;

    ltq_dma_w32(RX_CHAN, DMA_RX_BASE + DMA_CS);
    ltq_dma_w32_mask((1 << DMA_CCTRL_ON_OFF_POS), 0,
        DMA_RX_BASE +  DMA_CCTRL);

	while ((REG32(DMA_RX_BASE + DMA_CCTRL) & 0x1)) {
		i++;
		if (i > 10000) {
			printf("failed resetting rx chan\n");
			break;
		}
	}

	i = 0;

	/* turn off both tx/rx chan */
    ltq_dma_w32(TX_CHAN, DMA_TX_BASE + DMA_CS);
    ltq_dma_w32_mask((1 << DMA_CCTRL_ON_OFF_POS), 0,
        DMA_TX_BASE +  DMA_CCTRL);

	while ((REG32(DMA_TX_BASE + DMA_CCTRL) & 0x1)) {
		i++;
		if (i > 10000) {
			printf("failed resetting tx chan\n");
			break;
		}
	}
}

static int ltq_grx500_switch_send(struct eth_device *dev, 
						volatile void *packet, int length)
{
	int i, res = -1;
	_dma_tx_descriptor_t *tx_desc = 
			(_dma_tx_descriptor_t *)KSEG1ADDR(&tx_des_ring[tx_num]);
    
	if (length <= 0) {
        printf ("%s: bad packet size: %d\n", dev->name, length);
        goto Done;
    }

    for(i = 0; tx_desc->DW3.field.own == 1; i++) {
        if (i >= TOUT_LOOP) {
            printf("NO Tx Descriptor...");
            goto Done;
        }
    }

	//serial_putc('s');
	tx_desc->DW0.all = 0;
	tx_desc->DW1.all = 0;
	tx_desc->DW3.all = 0;
    tx_desc->DW3.field.sop = 1;
    tx_desc->DW3.field.eop = 1;
    tx_desc->DW3.field.c = 0;
    tx_desc->DW3.field.byteoffset = 0;
	if (length < 60)
		tx_desc->DW3.field.datalen = 60;
	else
		tx_desc->DW3.field.datalen = (u16) length;
    
    tx_desc->DW2.all = ((CPHYSADDR((u32) packet)) | 0x20000000) & 0xfffffff8;
    
	asm("SYNC");
	flush_dcache_range((u32)packet, (u32) packet + tx_desc->DW3.field.datalen);
    asm("SYNC");
	flush_scache_range((u32)packet, (u32) packet + tx_desc->DW3.field.datalen);
	asm("SYNC");

	tx_desc->DW3.field.own = 1;

	res = length;
	tx_num++;
	if (tx_num == NUM_TX_DESC) tx_num = 0;

	/* switch on tx chan */	
    ltq_dma_w32(TX_CHAN, DMA_TX_BASE + DMA_CS);
    ltq_dma_w32_mask(0, (1 << DMA_CCTRL_ON_OFF_POS),
        DMA_TX_BASE +  DMA_CCTRL);
	
Done:
	return res;
}

static int ltq_grx500_switch_recv(struct eth_device *dev)
{

	int length = 0;
	_dma_rx_descriptor_t *rx_desc;

	for (;;) {
		rx_desc = (_dma_rx_descriptor_t *)KSEG1ADDR(&rx_des_ring[rx_num]);
		if ((rx_desc->DW3.field.c == 0) || (rx_desc->DW3.field.own == 1)) {
			//printf("@");
			break;
		}
		length = rx_desc->DW3.field.datalen;
		if (length) {
			invalidate_scache_range((u32)NetRxPackets[rx_num], 
					(u32)NetRxPackets[rx_num] + rx_desc->DW3.field.datalen);
			invalidate_dcache_range((u32)NetRxPackets[rx_num], 
					(u32)NetRxPackets[rx_num] + rx_desc->DW3.field.datalen);
			NetReceive((void*)KSEG1ADDR(NetRxPackets[rx_num]), length);
		} else {
			printf("Zero length rcv!\n");
		}
		
		rx_desc->DW3.all = 0;
		rx_desc->DW3.field.sop = 0;
        rx_desc->DW3.field.eop = 0;
        rx_desc->DW3.field.c = 0;
		rx_desc->DW3.field.byteoffset = 0;
        rx_desc->DW3.field.datalen = PKTSIZE_ALIGN;
        rx_desc->DW3.field.own = 1;
		rx_num++;
		if (rx_num == NUM_RX_DESC) rx_num = 0;
	}

	return length;
}

void config_mdio_gpio(void)
{
	u32 wr_one = (1 << (42 - 32));

	/* Configure GPIO port 42 */
	REG32(GPIO_PAD_CTRL_PORTMUXC42) = 0x1;
	REG32(GPIO_FUNCTION_DIR_1) |= wr_one;
	REG32(GPIO_PAD_CTRL_OD_1) |= wr_one;

	wr_one = (1 << (43 - 32));

	/* Configure GPIO port 43 */
    REG32(GPIO_PAD_CTRL_PORTMUXC43) = 0x1;
    REG32(GPIO_FUNCTION_DIR_1) |= wr_one;
	REG32(GPIO_PAD_CTRL_OD_1) |= wr_one;

}

void GSW_RMON_Enable(u32 base_addr) 
{
    int i;

    for (i = 1; i <= 15; i++)
    {
        /* enable RMON counters */
		REG32(base_addr + GSW_BM_PCFG(i)) = 0x1;
    }
}

static void ltq_grx500_dma_init(void)
{
	u32 tmp_reg, reg = 0;

	/* configure rx */
	ltq_dma_w32_mask(0, (1 << DMA_CTRL_RST_POS), DMA_RX_BASE + DMA_CTRL);
    REG32(DMA_RX_BASE + DMA_PS) = RX_PORT;
    REG32(DMA_RX_BASE + DMA_PCTRL) = 0x1f28;

	REG32(DMA_RX_BASE + DMA_CS) = RX_CHAN;
	//REG32(DMA_RX_BASE + DMA_CCTRL) = 0x2;
	//while (REG32(DMA_RX_BASE + DMA_CCTRL) & 0x2) {};
	REG32(DMA_RX_BASE + DMA_CPOLL) = 0x80000180;
    REG32(DMA_RX_BASE + DMA_CDBA) = CPHYSADDR((u32)rx_des_ring) | 0x20000000;
    REG32(DMA_RX_BASE + DMA_CDLEN) = NUM_RX_DESC;	
	REG32(DMA_RX_BASE + DMA_CIE) = 0;
	REG32(DMA_RX_BASE + DMA_CCTRL) = 0x10000;
    ltq_dma_w32_mask((1 << (RX_CHAN & 0x1f)), 0, DMA_RX_BASE + DMA_IRNEN);
    ltq_dma_w32_mask(0, (1 << (RX_CHAN & 0x1f)), DMA_RX_BASE + DMA_IRNCR);

	/* configure tx */
	ltq_dma_w32_mask(0, (1 << DMA_CTRL_RST_POS), DMA_TX_BASE + DMA_CTRL);
	REG32(DMA_TX_BASE + DMA_PS) = TX_PORT;
    REG32(DMA_TX_BASE + DMA_PCTRL) = 0x1f28;
	
	REG32(DMA_TX_BASE + DMA_CS) = TX_CHAN;
	//REG32(DMA_TX_BASE + DMA_CCTRL) = 0x2;
	//while (REG32(DMA_TX_BASE + DMA_CCTRL) & 0x2) {};
	REG32(DMA_TX_BASE + DMA_CPOLL) = 0x80000180;
	REG32(DMA_TX_BASE + DMA_CDBA) = CPHYSADDR((u32)tx_des_ring) | 0x20000000;
	REG32(DMA_TX_BASE + DMA_CDLEN) = NUM_TX_DESC;
	REG32(DMA_TX_BASE + DMA_CIE) = 0;
	REG32(DMA_TX_BASE + DMA_CCTRL) = 0x10100;
    ltq_dma_w32_mask((1 << (TX_CHAN & 0x1f)), 0, DMA_TX_BASE + DMA_IRNEN);
    ltq_dma_w32_mask(0, (1 << (TX_CHAN & 0x1f)), DMA_TX_BASE + DMA_IRNCR);
}

int get_gphy_firmware(u32 dst, u32 src)
{
     int result = 1;
     int srcLen;
     u8* load = (unsigned char*)0xa0140000;
     ulong unc_len = 0;
     u8* image_start = NULL;
     ulong image_len = 0;
     image_header_t *pimg_header = NULL;

     int fw_version = 1; /*1->version 1; 2->version 2*/
     int fw_type = 0; /*0 FE, 1 GE*/
     char* ep;

	if (((ep = getenv("raw_gphy_fw")) != NULL) && (strcmp(ep, "yes") == 0)) {
         memcpy(dst,src,65536);
         result = 0;
         goto exit;
    }

    pimg_header = (image_header_t *)src;
    while (1) {
        if (pimg_header->ih_magic != IH_MAGIC){
    	   	printf("bad image magic number\n");
       		result = 1;
    		break;
		}
		switch(pimg_header->ih_type) {
       		case IH_TYPE_MULTI:
			printf("multi type\n");
    	    image_start = (u8*)pimg_header+sizeof(image_header_t)+8;
       		image_len = pimg_header->ih_size;

    	    if (lzmaBuffToBuffDecompress(load, &unc_len,image_start, image_len)) {
        		printf("gphy image name incorrect...\n");
            	result = 1;
            	goto exit;
        	}
     	    pimg_header = (image_header_t *)load;
     	    break;

       		case IH_TYPE_FIRMWARE:
        	if(strncmp(pimg_header->ih_name, "GRX500 V1.1 GPHY BE", sizeof(pimg_header->ih_name)) == 0) 
        		fw_type = 1;

#if 1 // TODO: tmp fix
        	if(fw_type == 1) {
            	image_start = (u8*)pimg_header+sizeof(image_header_t);
            	image_len = pimg_header->ih_size;
            	memcpy((u8*)dst, image_start, image_len);
            	result = 0;
        		goto exit;
        	}
#elif CONFIG_GRX500_SW_PORT2_MII
			if(fw_type == 0) {
        		image_start = (u8*)pimg_header+sizeof(image_header_t);
          		image_len = pimg_header->ih_size;
	            memcpy((u8*)dst, image_start, image_len);
    	        result = 0;
        	    goto exit;
        	}
#endif		
			pimg_header = (u8*)pimg_header+sizeof(image_header_t)+(pimg_header->ih_size);
        	break;
		}
	}

exit:
	return result;

}

void mdio_init(void) 
{
	REG32(GSW_L_MDC_CFG_0) = 0x0;
	REG32(GSWIP_TOP_R_MDC_CFG_0_R) = 0x0;
	REG32(GSW_L_MDC_CFG_1) = 0x800f;
	REG32(GSWIP_TOP_R_MDC_CFG_1_R) = 0x800f;

	udelay(100);

	REG32(GSW_L_MDC_CFG_1) = 0x0;
	REG32(GSWIP_TOP_R_MDC_CFG_1_R) = 0x0;
	
	config_mdio_gpio();
}

void gphy_config_gpio(void)
{
	u32 wr_one = (0x1 << 22);
	int i;

	/* port 22 func 3, out dir */
    REG32(GPIO_PAD_CTRL_PORTMUXC22) = 0x3;
    REG32(GPIO_FUNCTION_DIR_0) |= wr_one;
    REG32(GPIO_PAD_CTRL_OD_0) |= wr_one;
}

void ltq_grx500_sw_chip_init(void)
{
    u8 i = 0;
	unsigned short mdio_value;
	u32 write_data;
	u32 fw_addr, fw_phy_addr, fw_src_addr;
	u32 fw_base_l, fw_base_h;
	u32 reset_req = GPHY_RESET_REQ;
	u32 reset_stat = GPHY_RESET_STAT;

	/* Start of GPHY FW Initialization */
	mdio_init();

	fw_addr = 0xa0300000;
	fw_phy_addr = CPHYSADDR(fw_addr) | 0x20000000;
	asm("sync");

#ifdef CONFIG_GRX500_GPHY_FW_EMBEDDED
	fw_src_addr = CONFIG_GRX500_GPHY_FW_ADDR;
#endif

#ifdef CONFIG_GRX500_EXTERN_GPHY_FW_ADDR
	#ifdef CONFIG_BOOT_FROM_NAND
	{
		nand_info_t *nand = &nand_info[0];
		u64 size=65536;
		fw_src_addr = 0xa0220000;
		nand_read_skip_bad(nand,(getenv("gphy_fw_addr") ? 
				simple_strtoul((char *)getenv("gphy_fw_addr"),NULL,16) : CONFIG_GRX500_EXTERN_GPHY_FW_ADDR), &size,(u_char *)fw_src_addr);
	}
	#else
	{
        static struct spi_flash *flash;
        fw_src_addr = 0xa0220000;
        flash = spi_flash_probe(0, CONFIG_ENV_SPI_CS,
                         CONFIG_SF_DEFAULT_SPEED, CONFIG_SF_DEFAULT_MODE);
		spi_flash_read(flash, (getenv("gphy_fw_addr") ? 
				simple_strtoul((char *)getenv("gphy_fw_addr"),NULL,16):CONFIG_GRX500_EXTERN_GPHY_FW_ADDR), 65536, (void*)fw_src_addr);  
	}
	#endif // CONFIG_BOOT_FROM_NAND
#endif	// CONFIG_GRX500_GPHY_FW_EMBEDDED

	asm("sync");
	if (get_gphy_firmware(fw_addr, fw_src_addr)) {
		printf("cannot find gphy firmware!!\n");
	} 
	
	asm("sync");
	fw_base_l = fw_phy_addr & 0xFFFF;
	fw_base_h = (fw_phy_addr >> 16) & 0xFFFF; 
	
	/* Reset GPHY (GPHY2, GPHY3, GPHY4, GPHY5, GPHY6F) */
	*RESET_REQ = reset_req;
	asm("sync");
	mdelay(100);

	/* cfg gphy gpio */
	gphy_config_gpio();

#if defined(CONFIG_GRX500_PHY2)
	/* Init GPHY2 */
	//REG32(RESET_REQ) |= 0x20000000;
	REG32(GSWIP_TOP_L_GPHY_BFDEV(1)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(1)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(1)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(1)) = fw_base_l;
	//REG32(RESET_REQ) &= ~(0x20000000);
#endif
		
#if defined(CONFIG_GRX500_PHY3)
	/* Init GPHY3 */	
	//REG32(RESET_REQ) |= 0x10000000;
	REG32(GSWIP_TOP_L_GPHY_BFDEV(2)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(2)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(2)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(2)) = fw_base_l;
	//REG32(RESET_REQ) &= ~(0x10000000);
#endif

#if defined(CONFIG_GRX500_PHY5)
	/* Init GPHY5 -- done before GPHY4, intentionally */
	//REG32(RESET_REQ) |= 0x02000000;
	REG32(GSWIP_TOP_L_GPHY_BFDEV(4)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(4)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(4)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(4)) = fw_base_l;
	//REG32(RESET_REQ) &= ~(0x02000000);
	xway_mii_write(NULL, 0x5, 0x9, 0x1300);
#endif

#if defined(CONFIG_GRX500_PHY4)
	/* Init GPHY4 */
	//REG32(RESET_REQ) |= 0x04000000;
	REG32(GSWIP_TOP_L_GPHY_BFDEV(3)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(3)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(3)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(3)) = fw_base_l;
	//REG32(RESET_REQ) &= ~(0x04000000);
#endif

	/* By default, GPHY6 registers below MUST be configured,
     * otherwise WAN port will not work in kernel. 
	 * However, if we do not intend to enable PHY6 for some reason,
	 * we do not bring PHY6 out of reset. 
	 * Init GPHY6 
	*/
	//REG32(RESET_REQ) |= 0x80000000;
	REG32(GSWIP_TOP_L_GPHY_BFDEV(5)) = 0x51EC;
	REG32(GSWIP_TOP_L_GPHY2_CFG(5)) = 0x3;
	REG32(GSWIP_TOP_L_GPHY_MBADR(5)) = fw_base_h;
	REG32(GSWIP_TOP_L_GPHY_LBADR(5)) = fw_base_l;
	//REG32(RESET_REQ) &= ~(0x80000000);

#if !defined(CONFIG_GRX500_PHY6F)
	reset_req &= ~(GPHY6F_RESET);
#endif
	
	/* bring out GPHY out of reset */
	REG32(RESET_REQ) &= ~(reset_req);

	//printf("waiting for reset\n");
	while (*RESET_STAT & reset_stat);

	asm("sync");
	mdelay(100);

#ifdef CONFIG_CMD_MII
	miiphy_register("GRX500 SWITCH", xway_mii_read, xway_mii_write);
#endif // CONFIG_CMD_MII

	/* End of GPHY FW Initialization */

#if defined(CONFIG_NETWORK_VIA_LAN)
	REG32(GSW_BASE_ADDR) = 0x1;
    do {
        debug("\n Wait for reset");
    } while (REG32(GSW_BASE_ADDR) == 0x1);

    //Global Switch Macro Enable - GLOB_CTRL - Global Control Register
	REG32(GSW_BASE_ADDR + GSW_TOP_LVL_OFFSET) = 0x8000;
   
	/* from gswip_l() */
	for (i = 0; i < 5; i++) {
        /* PHY_ADDR_1 to PHY_ADDR_6 */
        //REG32(GSW_BASE_ADDR + GSW_TOP_LVL_OFFSET + (0x44 + 4 * i) * 4) = 0x3201 + i;
		REG32(GSW_BASE_ADDR + GSW_TOP_LVL_OFFSET + (0x44 + 4 * i) * 4) = 0x1801 + i;
        /* MAC_CTRL_0_1 to MAC_CTRL_0_6 */
		//REG32(GSW_BASE_ADDR + (0x903 + 12 * i) * 4) = 0x182;
		//REG32(GSW_BASE_ADDR + (0x903 + 12 * i) * 4) = 0x180;
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

#endif /* CONFIG_NETWORK_VIA_LAN */

#if defined(CONFIG_NETWORK_VIA_WAN)

	REG32(GSW_R_BASE_ADDR) = 0x1;
    do {
        debug("\n Wait for reset");
    } while (REG32(GSW_R_BASE_ADDR) == 0x1);
       
	REG32(GSW_R_BASE_ADDR + GSW_TOP_LVL_OFFSET) = 0x8000; 

	/* PHY_ADDR_F */
    //REG32(GSW_R_BASE_ADDR + GSW_TOP_LVL_OFFSET + 0x110) = 0x3201;
	REG32(GSW_R_BASE_ADDR + GSW_TOP_LVL_OFFSET + 0x110) = 0x1801;
    /* MAC_CTRL_0_1 */
    REG32(GSW_R_BASE_ADDR + GSW_R_MAC_CTRL_0(1)) = 0x1C0;
	//REG32(GSW_R_BASE_ADDR + GSW_R_MAC_CTRL_0(1)) = 0x180;	

	REG32(GSW_R_MDC_CFG_0) = 0x07e;		

	/* Disable Autoneg */
    REG32(GSW_R_BASE_ADDR + GSW_PMAC_CTRL_4) = 0x0;
    REG32(GSW_R_BASE_ADDR + GSW_PMAC_CTRL_2) = 0x4;

	for (i = 0; i <= 14; i++) {
        REG32(GSW_R_BASE_ADDR + GSW_PCE_PCTRL_0(i)) |= (1<<11);
    }

	/* Set the port mapping rule, configure to port map
	 * to the DMA class (class 0) not DMA channel 
     */
	REG32(GSW_R_BASE_ADDR + GSW_PMAC_TBL_ADDR) = 0; 

    REG32(GSW_R_BASE_ADDR + GSW_PMAC_TBL_VAL_4) = 0x52; 
    REG32(GSW_R_BASE_ADDR + GSW_PMAC_TBL_VAL_3) = 0x8000;	//port 15
    REG32(GSW_R_BASE_ADDR + GSW_PMAC_TBL_VAL_2) = 0x0;  	//redirect enable 
    REG32(GSW_R_BASE_ADDR + GSW_PMAC_TBL_VAL_1) = 0xA0;
    REG32(GSW_R_BASE_ADDR + GSW_PMAC_TBL_VAL_0) = 0;		//pmac byte 0 and byte 1

	REG32(GSW_R_BASE_ADDR + GSW_PMAC_TBL_CTRL) = 0x8021;

	REG32(GSW_R_BASE_ADDR + PCE_PMAP_3) = 0x8001; //unknown unicast forward to CPU  
    REG32(GSW_R_BASE_ADDR + PCE_PMAP_2) = 0x8001; //unknown multicast forward to CPU

    // Enable RMON Counters for all Ports
    GSW_RMON_Enable(GSW_R_BASE_ADDR);
	gsw_micro_code_dl_30(GSW_R_BASE_ADDR);

#endif /* CONFIG_NETWORK_VIA_WAN */

	ltq_grx500_dma_init();

	xway_mii_read(NULL, 0x4, 0x1e, &mdio_value);
	printf("Internal phy firmware version: 0x%04x\n", mdio_value);

}

int grx500_eth_initialize(bd_t * bis)
{
	struct eth_device *dev;

	dev = (struct eth_device *) malloc(sizeof(struct eth_device));
	if (!dev) {
		printf("Failed to allocate initialized switch mem\n");
		return 0;
	}

	memset(dev, 0, sizeof(*dev));
        asm("sync");
	ltq_grx500_sw_chip_init();
	asm("sync");

	sprintf(dev->name, "GRX500 Switch");
	dev->init = ltq_grx500_switch_init;
	dev->halt = ltq_grx500_switch_halt;
	dev->send = ltq_grx500_switch_send;
	dev->recv = ltq_grx500_switch_recv;

	eth_register(dev);

	return 1;

}

