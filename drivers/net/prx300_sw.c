/* Copyright (c) 2017, Intel Corporation.
 *
 * PRX300 slim ethernet driver
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <config.h>
#include <malloc.h>
#include <net.h>
#include <miiphy.h>
#include <asm/addrspace.h>
#include <asm/lq_dma.h>
#include <asm/arch/prx300.h>
#include <lantiq.h>

#ifdef CONFIG_LTQ_BOOT_FROM_NAND
#include <nand.h>
#endif

#if defined(CONFIG_LTQ_BOOT_FROM_SPI) \
	|| defined(CONFIG_LTQ_BOOT_FROM_QSPI)
#include <spi.h>
#include <spi_flash.h>
#endif

#include <lzma/LzmaTypes.h>
#include <lzma/LzmaDec.h>
#include <lzma/LzmaTools.h>

#include "lq_microcode.h"
#include "prx300_sw.h"

#define GPHYCDB_FCSI_MODULE_BASE 0x16210080u
#define RCALSTAT 0x20
#define FUSE_REDUND_1 0x74

/* Switch Offset */
#define GPIO_P42	42
#define GPIO_P43	43
#define TX_PORT		0
#define RX_PORT		0
#define TX_CHAN		0
#define RX_CHAN		0

#define NUM_RX_DESC PKTBUFSRX
#define NUM_TX_DESC 8
#define MAX_PACKET_SIZE     1536
#define TOUT_LOOP   100

#define DMA_TX_BASE	(DMA1_TX_MODULE_BASE)
#define DMA_RX_BASE	(DMA1_RX_MODULE_BASE)

#define MDIO_WRITE_CMD	((0 << 11) | (1 << 10))
#define MDIO_READ_CMD  ((1 << 11) | (0 << 10))

#ifdef CONFIG_CACHE_COHERENCE
#define DMA_IOCU_PHYS_OFFSET	0xA0000000
#define NETPHYADDR(a)	((CPHYSADDR(a) | 0x20000000) + DMA_IOCU_PHYS_OFFSET)
#else
#define NETPHYADDR(a)	(CPHYSADDR(a) | 0x20000000)
#endif

#ifdef CONFIG_A1_FIX
#define GPHY_OFFSET_ADDR	0xa0228000
#else
#define GPHY_OFFSET_ADDR	0xa0228000
#endif /* CONFIG_A1_FIX */

#define PCE_TABLE_SIZE		256
#define PCE_PARS_INDEX		0
#define PCE_OP_MODE_ADWR	1
#define INSTR			0
#define IPV6			1
#define LENACCU			2
#define MAC_IFACE		3
#define ANG_EEE			0x1278

#define GPHY_FW_STR_A1		"PRX300 GPHY Firmware A1"
#define GPHY_FW_STR_B0		"PRX300 GPHY Firmware B0"

static _dma_rx_descriptor_t rx_des_ring[NUM_RX_DESC]
		__attribute__ ((aligned(32)));
static _dma_tx_descriptor_t tx_des_ring[NUM_TX_DESC]
		__attribute__ ((aligned(32)));

static int tx_num, rx_num;
extern void prx300_xpcs_init(char **link_mode);
static void ltq_prx300_dma_init(void);
int prx300_eth_initialize(bd_t *bis);
extern unsigned int get_gphy_clk(void);
extern unsigned int ltq_get_cpu_rev(void);

typedef struct {
	int on;
	int miimode;
	int miirate;
} grx500_sw_port;

typedef struct {
	u16 key[21];
	u16 mask[4];
	u16 val[25];
	u16 table;
	u16 table_index;
	u16 op_mode:2;
	u16 extop:1;
	u16 key_format:1;
	u16 type:1;
	u16 valid:1;
	u16 group:4;
} pctbl_prog_t;

static const gsw_pce_tbl_info_t gsw_pce_tbl_info_31[] = {
	{0, 0, 4}, {0, 0, 0}, {1, 0, 1}, {1, 0, 0}, {1, 1, 0}, {1, 1, 0},
	{4, 4, 0}, {4, 4, 0}, {1, 1, 0}, {0, 0, 1}, {0, 0, 1}, {4, 0, 10},
	{0, 0, 2}, {19, 0, 10}, {2, 0, 5}, {22, 0, 18}, {0, 0, 0}, {0, 0, 1},
	{0, 0, 9}, {0, 0, 7}, {0, 0, 18}, {0, 0, 14}, {3, 1, 0}, {3, 1, 0},
	{1, 1, 0}, {0, 0, 10}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {1, 1, 0},
	{4, 0, 6}, {0, 0, 1}
};

static const u32 gsw_pce_tbl_reg_key[] = {
	PCE_TBL_KEY_0_KEY0_OFFSET, PCE_TBL_KEY_1_KEY1_OFFSET,
	PCE_TBL_KEY_2_KEY2_OFFSET, PCE_TBL_KEY_3_KEY3_OFFSET,
	PCE_TBL_KEY_4_KEY4_OFFSET, PCE_TBL_KEY_5_KEY5_OFFSET,
	PCE_TBL_KEY_6_KEY6_OFFSET, PCE_TBL_KEY_7_KEY7_OFFSET,
	PCE_TBL_KEY_8_KEY8_OFFSET, PCE_TBL_KEY_9_KEY9_OFFSET,
	PCE_TBL_KEY_10_KEY10_OFFSET, PCE_TBL_KEY_11_KEY11_OFFSET,
	PCE_TBL_KEY_12_KEY12_OFFSET, PCE_TBL_KEY_13_KEY13_OFFSET,
	PCE_TBL_KEY_14_KEY14_OFFSET, PCE_TBL_KEY_15_KEY15_OFFSET,
	PCE_TBL_KEY_16_KEY16_OFFSET, PCE_TBL_KEY_17_KEY17_OFFSET,
	PCE_TBL_KEY_18_KEY18_OFFSET, PCE_TBL_KEY_19_KEY19_OFFSET,
	PCE_TBL_KEY_20_KEY20_OFFSET, PCE_TBL_KEY_21_KEY21_OFFSET
};

static const u32 gsw_pce_tbl_reg_mask[] = {
	PCE_TBL_MASK_0_MASK0_OFFSET, PCE_TBL_MASK_1_MASK1_OFFSET,
	PCE_TBL_MASK_2_MASK2_OFFSET, PCE_TBL_MASK_3_MASK3_OFFSET
};

static const u32 gsw_pce_tbl_reg_value[] = {
	PCE_TBL_VAL_0_VAL0_OFFSET, PCE_TBL_VAL_1_VAL1_OFFSET,
	PCE_TBL_VAL_2_VAL2_OFFSET, PCE_TBL_VAL_3_VAL3_OFFSET,
	PCE_TBL_VAL_4_VAL4_OFFSET, PCE_TBL_VAL_5_VAL5_OFFSET,
	PCE_TBL_VAL_6_VAL6_OFFSET, PCE_TBL_VAL_7_VAL7_OFFSET,
	PCE_TBL_VAL_8_VAL8_OFFSET, PCE_TBL_VAL_9_VAL9_OFFSET,
	PCE_TBL_VAL_10_VAL10_OFFSET, PCE_TBL_VAL_11_VAL11_OFFSET,
	PCE_TBL_VAL_12_VAL12_OFFSET, PCE_TBL_VAL_13_VAL13_OFFSET,
	PCE_TBL_VAL_14_VAL14_OFFSET, PCE_TBL_VAL_15_VAL15_OFFSET,
	PCE_TBL_VAL_16_VAL16_OFFSET, PCE_TBL_VAL_17_VAL17_OFFSET,
	PCE_TBL_VAL_18_VAL18_OFFSET, PCE_TBL_VAL_19_VAL19_OFFSET,
	PCE_TBL_VAL_20_VAL20_OFFSET, PCE_TBL_VAL_21_VAL21_OFFSET,
	PCE_TBL_VAL_22_VAL22_OFFSET, PCE_TBL_VAL_23_VAL23_OFFSET,
	PCE_TBL_VAL_24_VAL24_OFFSET, PCE_TBL_VAL_25_VAL25_OFFSET
};

#ifdef CONFIG_DEBUG
static void hexdump(unsigned char *buf, unsigned int len)
{
	while (len--) {
		if (len && !(len % 16))
			printf("\n");
		printf("%02x", *buf++);
	}
	printf("\n");
}
#endif

static inline u32 gsw_field_r32(u32 rval, short shift, short size)
{
	return (rval >> shift) & ((1 << size) - 1);
}

static inline u32 gsw_field_w32(u32 rval, short shift, short size, u32 val)
{
	u32 mask;

	mask = ((1 << size) - 1) << shift;
	val = (val << shift) & mask;
	return (rval & ~mask) | val;
}

static inline void gsw_r32_raw(u32 base_addr, short offset, u32 *value)
{
	*value = ltq_r32(base_addr, (offset * 4));
}

static inline void gsw_w32_raw(u32 base_addr, short offset, u32 value)
{
	ltq_w32(base_addr, (offset * 4), value);
}

int gsw_pce_table_write(pctbl_prog_t *ptdata)
{
	int i, j;
	unsigned int num_key, num_mask, num_val;
	u32 ctrlval;
	u32 base_addr = (u32)(ETHSW_PDI_MODULE_BASE);

	do {
		gsw_r32_raw(base_addr, PCE_TBL_CTRL_BAS_OFFSET, &ctrlval);
	} while (gsw_field_r32(ctrlval, PCE_TBL_CTRL_BAS_SHIFT,
				PCE_TBL_CTRL_BAS_SIZE));

	gsw_w32_raw(base_addr, PCE_TBL_ADDR_ADDR_OFFSET, ptdata->table_index);

	num_key = gsw_pce_tbl_info_31[ptdata->table].num_key;
	num_mask = gsw_pce_tbl_info_31[ptdata->table].num_mask;
	num_val = gsw_pce_tbl_info_31[ptdata->table].num_val;

	/*TABLE ADDRESS*/
	ctrlval = gsw_field_w32(ctrlval, PCE_TBL_CTRL_ADDR_SHIFT,
				PCE_TBL_CTRL_ADDR_SIZE, ptdata->table);
	ctrlval = gsw_field_w32(ctrlval, PCE_TBL_CTRL_OPMOD_SHIFT,
				PCE_TBL_CTRL_OPMOD_SIZE, PCE_OP_MODE_ADWR);

	/*KEY REG*/
	j = num_key;
	if (ptdata->key_format)
		j *= 4;

	for (i = 0; i < j; i++)
		gsw_w32_raw(base_addr,
				gsw_pce_tbl_reg_key[i], ptdata->key[i]);

	/*MASK REG*/
	j = num_mask;
	for (i = 0; i < j; i++)
		gsw_w32_raw(base_addr,
				gsw_pce_tbl_reg_mask[i], ptdata->mask[i]);

	/*VAL REG*/
	j = num_val;
	for (i = 0; i < j; i++)
		gsw_w32_raw(base_addr,
				gsw_pce_tbl_reg_value[i], ptdata->val[i]);

	ctrlval = gsw_field_w32(ctrlval, PCE_TBL_CTRL_KEYFORM_SHIFT,
				PCE_TBL_CTRL_KEYFORM_SIZE,
				ptdata->key_format);
	ctrlval = gsw_field_w32(ctrlval, PCE_TBL_CTRL_TYPE_SHIFT,
				PCE_TBL_CTRL_TYPE_SIZE, ptdata->type);
	ctrlval = gsw_field_w32(ctrlval, PCE_TBL_CTRL_VLD_SHIFT,
				PCE_TBL_CTRL_VLD_SIZE, ptdata->valid);
	ctrlval = gsw_field_w32(ctrlval, PCE_TBL_CTRL_GMAP_SHIFT,
				PCE_TBL_CTRL_GMAP_SIZE, ptdata->group);
	ctrlval = gsw_field_w32(ctrlval, PCE_TBL_CTRL_BAS_SHIFT,
				PCE_TBL_CTRL_BAS_SIZE, 1);
	gsw_w32_raw(base_addr, PCE_TBL_CTRL_BAS_OFFSET, ctrlval);

	do {
		gsw_r32_raw(base_addr, PCE_TBL_CTRL_BAS_OFFSET, &ctrlval);
	} while (gsw_field_r32(ctrlval, PCE_TBL_CTRL_BAS_SHIFT,
				PCE_TBL_CTRL_BAS_SIZE));

	gsw_w32_raw(base_addr, PCE_TBL_CTRL_ADDR_OFFSET, 0);

	return 0;
}

static void prx300_switch_enable(unsigned int total_ports)
{
	int i;
	u32 reg;

	for (i = 0; i < total_ports; i++) {
		ltq_w32(ETHSW_PDI_MODULE_BASE, FDMA_PCTRL + (i * 0x18),
			(ltq_r32(ETHSW_PDI_MODULE_BASE,
			FDMA_PCTRL + (i * 0x18)) & ~(FDMA_PCTRL_EN_MASK)) | 1);
		ltq_w32(ETHSW_PDI_MODULE_BASE, SDMA_PCTRL + (i * 0x18),
			(ltq_r32(ETHSW_PDI_MODULE_BASE,
			SDMA_PCTRL + (i * 0x18)) & ~(SDMA_PCTRL_PEN_POS)) | 1);
		ltq_w32(ETHSW_PDI_MODULE_BASE, BM_PCFG + (i * 0x8), 0x1);
	}

	reg = ltq_r32(GSWIP_SS_MODULE_BASE, GSWIP_CFG);
	reg |= (1 << GSWIP_CFG_CORE_SE_POS);
	ltq_w32(GSWIP_SS_MODULE_BASE, GSWIP_CFG, reg);
}

void prx300_load_microcode(unsigned int num_ports)
{
	int i, j;
	pctbl_prog_t tbl_entry;
	u32 base_addr = (u32)(ETHSW_PDI_MODULE_BASE | KSEG1);

	/* Disable all physical port  */
	for (j = 0; j < num_ports; j++) {
		gsw_w32(base_addr, (FDMA_PCTRL_EN_OFFSET + (j * 0x6)),
			FDMA_PCTRL_EN_SHIFT, FDMA_PCTRL_EN_SIZE, 0);
		gsw_w32(base_addr, (SDMA_PCTRL_PEN_OFFSET + (j * 0x6)),
			SDMA_PCTRL_PEN_SHIFT, SDMA_PCTRL_PEN_SIZE, 0);
	}

	gsw_w32(base_addr, PCE_GCTRL_0_MC_VALID_OFFSET,
		PCE_GCTRL_0_MC_VALID_SHIFT, PCE_GCTRL_0_MC_VALID_SIZE, 0x0);

	for (i = 0; i < PCE_TABLE_SIZE; i++) {
		memset(&tbl_entry, 0, sizeof(pctbl_prog_t));
		tbl_entry.val[3] = pce_mc_max_ifx_tag_m_30[i].val_3;
		tbl_entry.val[2] = pce_mc_max_ifx_tag_m_30[i].val_2;
		tbl_entry.val[1] = pce_mc_max_ifx_tag_m_30[i].val_1;
		tbl_entry.val[0] = pce_mc_max_ifx_tag_m_30[i].val_0;
		tbl_entry.table_index = i;
		tbl_entry.table = PCE_PARS_INDEX;
		gsw_pce_table_write(&tbl_entry);
	}

	gsw_w32(base_addr, PCE_GCTRL_0_MC_VALID_OFFSET,
		PCE_GCTRL_0_MC_VALID_SHIFT, PCE_GCTRL_0_MC_VALID_SIZE, 0x1);

	/* Enable RMON Counter for all ports */
	for (j = 0; j < num_ports; j++) {
		gsw_w32(base_addr, (BM_PCFG_CNTEN_OFFSET + (j * 0x2)),
			BM_PCFG_CNTEN_SHIFT, BM_PCFG_CNTEN_SIZE, 1);
	}

	gsw_w32(base_addr, BM_QUEUE_GCTRL_GL_MOD_OFFSET,
		BM_QUEUE_GCTRL_GL_MOD_SHIFT, 2, 0);
}

static inline u32 LMAC_RGRD(u32 reg)
{
	u32 reg_val;

	reg_val = ltq_r32(LEGACY_MAC_BASE, reg);
	return reg_val;
}

static inline void LMAC_RGWR(u32 reg, u32 val)
{
	ltq_w32(LEGACY_MAC_BASE, reg, val);
}

static inline u32 GSWSS_RGRD(u32 reg)
{
	u32 reg_val;

	reg_val = ltq_r32(GSWIP_SS, reg);
	return reg_val;
}

static inline void GSWSS_RGWR(u32 reg, u32 val)
{
	ltq_w32(GSWIP_SS, reg, val);
}

static inline u32 XGMAC_RGRD(struct mac_prv_data *pdata, u16 reg)
{
	u32 reg_val;

	writel((0x8000 | reg), (u32 *)pdata->xgmac_ctrl_reg)
		;
	while (1) {
		if ((readl((u32 *)pdata->xgmac_ctrl_reg) & 0x8000) == 0)
			break;
	}

	reg_val = ((readl((u32 *)pdata->xgmac_data1_reg) << 16) |
				(readl((u32 *) pdata->xgmac_data0_reg)));

	return reg_val;
}

static inline void XGMAC_RGWR(struct mac_prv_data *pdata, u16 reg, u32 val)
{
	writel(((val & 0xFFFF0000) >> 16), (u32 *)pdata->xgmac_data1_reg);
	writel((val & 0x0000FFFF), (u32 *)pdata->xgmac_data0_reg);
	writel((0xC000 | reg), (u32 *)pdata->xgmac_ctrl_reg);

	while (1) {
		if ((readl((u32 *)pdata->xgmac_ctrl_reg) & 0x8000) == 0)
			break;
	}
}

void mdio_set_clause(struct mac_prv_data *pdata,
				u32 clause, u32 phy_id)
{
	u32 mdio_c22p = 0;

	mdio_c22p = XGMAC_RGRD(pdata, MDIO_C22P);
	SET_BITS(mdio_c22p, phy_id, MDIO_CL22P_PORT0_WIDTH, clause);
	/* Select port 0, 1, 2 and 3 as Clause 22/45 ports */
	XGMAC_RGWR(pdata, MDIO_C22P, mdio_c22p);
}

int mdio_get_clause(struct mac_prv_data *pdata, u32 phy_id)
{
	u32 mdio_c22p = 0;
	int clause;

	mdio_c22p = XGMAC_RGRD(pdata, MDIO_C22P);

	clause = GET_BITS(mdio_c22p, phy_id, MDIO_CL22P_PORT0_WIDTH);

	return clause;
}

int mdio_read(struct mac_prv_data *pdata,
			 int dev_addr,
			 int phy_id,
			 int phy_reg,
			 u32 *phy_reg_data)
{
	u32 mdio_sccdr = 0;
	u32 mdio_scar = 0;
	u32 clause;

	if (dev_addr == MDIO_DEVAD_NONE) {
		dev_addr = (phy_reg >> 16) & 0x1f;
		clause = 0; /* clause 22 */
	} else {
		clause = 1; /* clause 45 */
	}

	debug("Reading from dev=%08x, clause=%d, id=0x%08x, register=0x%08x\n",
		dev_addr, clause ? 22 : 45, phy_id, phy_reg);

	if (clause != mdio_get_clause(pdata, pdata->mac_idx))
		mdio_set_clause(pdata, clause, pdata->mac_idx);

	/* wait for any previous MDIO read/write operation to complete */
	while (1) {
		if (XGMAC_RGRD_BITS(pdata, MDIO_SCCDR, BUSY) == 0)
			break;
	}

	/* initiate the MDIO read operation by updating desired bits */
	/* PA - phy address/id (0 - 31) */
	/* RA - phy register offset */

	mdio_scar = XGMAC_RGRD(pdata, MDIO_SCAR);

	XGMAC_SET_BITS(mdio_scar, MDIO_SCAR, DA, dev_addr);
	XGMAC_SET_BITS(mdio_scar, MDIO_SCAR, PA, phy_id);
	XGMAC_SET_BITS(mdio_scar, MDIO_SCAR, RA, phy_reg);

	XGMAC_RGWR(pdata, MDIO_SCAR, mdio_scar);

	mdio_sccdr = XGMAC_RGRD(pdata, MDIO_SCCDR);

	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, BUSY, 1);
	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, SADDR, 0);
	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, CMD, 3);
	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, SDATA, 0);

	XGMAC_RGWR(pdata, MDIO_SCCDR, mdio_sccdr);
	udelay(10);

	/* wait for MDIO read operation to complete */
	while (1) {
		if (XGMAC_RGRD_BITS(pdata, MDIO_SCCDR, BUSY) == 0)
			break;
	}

	/* read the data */
	mdio_sccdr = XGMAC_RGRD(pdata, MDIO_SCCDR);
	*phy_reg_data = XGMAC_GET_BITS(mdio_sccdr, MDIO_SCCDR, SDATA);

	return 0;
}

/*!
* \brief This sequence is used to write into phy registers
*/
int mdio_write(struct mac_prv_data *pdata,
			 int dev_addr,
			 int phy_id,
			 int phy_reg,
			 u32 phy_reg_data)
{

	u32 mdio_sccdr = 0;
	u32 mdio_scar = 0;
	u32 clause;

	/* wait for any previous MDIO read/write operation to complete */
	while (1) {
		if (XGMAC_RGRD_BITS(pdata, MDIO_SCCDR, BUSY) == 0)
			break;
	}

	if (dev_addr == MDIO_DEVAD_NONE) {
		dev_addr = (phy_reg >> 16) & 0x1f;
		clause = 0; /* clause 22 */
	} else {
		clause = 1; /* clause 45 */
	}

	debug("Writing to dev=%08x, id=0x%08x, register=0x%08x, data=0x%04x\n",
		dev_addr, phy_id, phy_reg, phy_reg_data);

	if (clause != mdio_get_clause(pdata, pdata->mac_idx))
		mdio_set_clause(pdata, clause, pdata->mac_idx);

	mdio_scar = XGMAC_RGRD(pdata, MDIO_SCAR);

	XGMAC_SET_BITS(mdio_scar, MDIO_SCAR, DA, dev_addr);
	XGMAC_SET_BITS(mdio_scar, MDIO_SCAR, PA, phy_id);
	XGMAC_SET_BITS(mdio_scar, MDIO_SCAR, RA, phy_reg);

	XGMAC_RGWR(pdata, MDIO_SCAR, mdio_scar);

	mdio_sccdr = XGMAC_RGRD(pdata, MDIO_SCCDR);

	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, SDATA, phy_reg_data);
	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, BUSY, 1);
	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, SADDR, 0);
	XGMAC_SET_BITS(mdio_sccdr, MDIO_SCCDR, CMD, 1);

	XGMAC_RGWR(pdata, MDIO_SCCDR, mdio_sccdr);

	/* wait for MDIO read operation to complete */
	while (1) {
		if (XGMAC_RGRD_BITS(pdata, MDIO_SCCDR, BUSY) == 0)
			break;
	}

	return 0;
}

int prx300_mdio_read(struct mii_dev *bus, int phy_addr, int dev_addr,
			int reg_addr)
{
	int ret;
	u32 data;
	struct mac_prv_data *pdata;

	if (!strncmp(bus->name, "mdio0", 8)) {
		pdata = &xgmac_prv_data[0];
	} else if (!strncmp(bus->name, "mdio1", 8)) {
		pdata = &xgmac_prv_data[1];
	} else {
		printf("Wrong devname: %s\n", bus->name);
		return -EINVAL;
	}

	ret = mdio_read(pdata, dev_addr, phy_addr, reg_addr, &data);
	if (ret)
		return ret;

	return (int)data;
}

int prx300_mdio_write(struct mii_dev *bus, int phy_addr, int dev_addr,
			int reg_addr, u16 data)
{
	struct mac_prv_data *pdata;

	if (!strncmp(bus->name, "mdio0", 8)) {
		pdata = &xgmac_prv_data[0];
	} else if (!strncmp(bus->name, "mdio1", 8)) {
		pdata = &xgmac_prv_data[1];
	} else {
		printf("Wrong devname: %s\n", bus->name);
		return -EINVAL;
	}

	mdio_write(pdata, dev_addr, phy_addr, reg_addr, data);
	return 0;
}

int prx300_mdio_init(struct eth_device *dev, char *mdio_name)
{
	int ret;
	struct mii_dev *bus;

	bus = mdio_alloc();
	if (!bus) {
		printf("Error allocating mdio\n");
		return -ENOMEM;
	}

	bus->read = prx300_mdio_read;
	bus->write = prx300_mdio_write;
	strlcpy(bus->name, mdio_name, 6);

	ret = mdio_register(bus);
	if (ret) {
		printf("mdio register failed\n");
		free(bus);
		return -EINVAL;
	}

	return 0;
}

static void xgmac_config_std_pkt(struct mac_prv_data *pdata)
{
	u32 mac_rcr;

	mac_rcr = XGMAC_RGRD(pdata, MAC_RCR);

	XGMAC_SET_BITS(mac_rcr, MAC_RCR, JE, 0);
	XGMAC_SET_BITS(mac_rcr, MAC_RCR, WD, 0);
	XGMAC_SET_BITS(mac_rcr, MAC_RCR, GPSLCE, 0);
	XGMAC_RGWR_BITS(pdata, MAC_TCR, JD, 0);

	XGMAC_RGWR(pdata, MAC_RCR, mac_rcr);
}

static int xgmac_set_mac_int(struct mac_prv_data *pdata, u32 val)
{
	u32 mac_ier = 0;

	/* Enable Timestamp interrupt */
	if (val & MASK(MAC_IER, TSIE))
		XGMAC_SET_BITS(mac_ier, MAC_IER, TSIE, val);

	/* Enable LPI interrupt (EEE) */
	if (val & MASK(MAC_IER, LPIIE))
		XGMAC_SET_BITS(mac_ier, MAC_IER, LPIIE, val);

	/* Enable transmit error status interrupt */
	if (val & MASK(MAC_IER, TXESIE))
		XGMAC_SET_BITS(mac_ier, MAC_IER, TXESIE, val);

	/* Enable recieve error status interrupt */
	if (val & MASK(MAC_IER, RXESIE))
		XGMAC_SET_BITS(mac_ier, MAC_IER, RXESIE, val);

	/* Enable power management interrupt */
	if (val & MASK(MAC_IER, PMTIE))
		XGMAC_SET_BITS(mac_ier, MAC_IER, PMTIE, val);

	XGMAC_RGWR(pdata, MAC_IER, mac_ier);

	if (val) {
		/* Enable all counter interrupts */
		XGMAC_RGWR_BITS(pdata, MMC_RIER, ALL_INTERRUPTS, 0xffffffff);
		XGMAC_RGWR_BITS(pdata, MMC_TIER, ALL_INTERRUPTS, 0xffffffff);
	} else {
		/* Disable all counter interrupts */
		XGMAC_RGWR_BITS(pdata, MMC_RIER, ALL_INTERRUPTS, 0);
		XGMAC_RGWR_BITS(pdata, MMC_TIER, ALL_INTERRUPTS, 0);
	}

	return 0;
}

static int xgmac_set_extcfg(struct mac_prv_data *pdata, u32 val)
{
	u32 mac_extcfg;

	mac_extcfg = XGMAC_RGRD(pdata, MAC_EXTCFG);

	if (XGMAC_GET_BITS(mac_extcfg, MAC_EXTCFG, SBDIOEN) != val) {
		debug("XGMAC %d: MAC Extended CFG SBDIOEN: %s\n",
				pdata->mac_idx, val ? "ENABLED" : "DISABLED");

		XGMAC_SET_BITS(mac_extcfg, MAC_EXTCFG, SBDIOEN, val);

		XGMAC_RGWR(pdata, MAC_EXTCFG, mac_extcfg);
	}

	return 0;
}

static int xgmac_disable_rx_vlan_filtering(struct mac_prv_data *pdata)
{
	if (XGMAC_RGRD_BITS(pdata, MAC_PFR, VTFE) != 0) {
		debug("XGMAC %d: Disabling VLAN filtering\n", pdata->mac_idx);
		/* Disable VLAN filtering */
		XGMAC_RGWR_BITS(pdata, MAC_PFR, VTFE, 0);
	}

	return 0;
}

/*	MAC_PFR:
 *	The MAC Packet Filter register contains the filter controls for
 *	receiving packets. Some of the controls from
 *	this register go to the address check block of the MAC which
 *	performs the first level of address filtering. The
 *	second level of filtering is performed on the incoming packet
 *	based on other controls such as Pass Bad
 *	Packets and Pass Control Packets.
 *
 *	PR:
 *	Promiscuous Mode
 *	When this bit is set, the Address Filtering module
 *	passes all incoming packets irrespective of the
 *	destination or source address. The SA or DA Filter Fails status
 *	bits of the Rx Status Word are always cleared when PR is set.
 */
static int xgmac_set_promiscuous_mode(struct mac_prv_data *pdata, u32 val)
{
	if (XGMAC_RGRD_BITS(pdata, MAC_PFR, PR) != val) {
		debug("XGMAC %d: %s promiscuous mode\n",
			pdata->mac_idx,  val ? "Entering" : "Leaving");
		XGMAC_RGWR_BITS(pdata, MAC_PFR, PR, val);
	}

	/* Hardware will still perform VLAN filtering in promiscuous mode */
	xgmac_disable_rx_vlan_filtering(pdata);

	return 0;
}

/*	PM:
 *	Pass All Multicast
 *	When this bit is set, it indicates that all received
 *	packets with a multicast destination address
 *	(first bit in the destination address field is '1') are passed.
 *	When this bit is reset, filtering of multicast packet
 *	depends on HMC bit.
 */
static int xgmac_set_all_multicast_mode(struct mac_prv_data *pdata, u32 val)
{
	if (XGMAC_RGRD_BITS(pdata, MAC_PFR, PM) != val) {
		debug("XGMAC %d: %s allmulti mode\n",
				pdata->mac_idx,
				val ? "Entering" : "Leaving");
		XGMAC_RGWR_BITS(pdata, MAC_PFR, PM, val);
	}

	return 0;
}

static int gswss_set_speed(u32 mac_idx, u8 speed)
{
	u16 phy_mode = 0;
	u8 speed_msb = 0, speed_lsb = 0;

	phy_mode = GSWSS_RGRD(PHY_MODE(mac_idx));

	speed_msb = GET_BITS(speed, 2, 1);
	speed_lsb = GET_BITS(speed, 0, 2);

	if (speed == SPEED_10M)
		debug("\tGSWSS: SPEED\t10 Mbps\n");
	else if (speed == SPEED_100M)
		debug("\tGSWSS: SPEED\t100 Mbps\n");
	else if (speed == SPEED_1G)
		debug("\tGSWSS: SPEED\t1 Gbps\n");
	else if (speed == SPEED_10G)
		debug("\tGSWSS: SPEED\t10 Gbps\n");
	else if (speed == SPEED_2G5)
		debug("\tGSWSS: SPEED\t2.5 Gbps\n");
	else if (speed == SPEED_5G)
		debug("\tGSWSS: SPEED\t5 Gbps\n");
	else if (speed == SPEED_FLEX)
		debug("\tGSWSS: SPEED\tRESERVED\n");
	else if (speed == SPEED_AUTO)
		debug("\tGSWSS: SPEED\tautomatic mode detection by GPHY/XPCS link information outputs\n");

	GSWSS_SET_BITS(phy_mode, PHY_MODE, SPEEDMSB, speed_msb);
	GSWSS_SET_BITS(phy_mode, PHY_MODE, SPEEDLSB, speed_lsb);

	GSWSS_RGWR(PHY_MODE(mac_idx), phy_mode);

	return 0;
}

static int xgmac_set_xgmii_speed(struct mac_prv_data *pdata)
{
	u32 mac_tcr = XGMAC_RGRD(pdata, MAC_TCR);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, USS) != 0)
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, USS, 0);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, SS) != 0) {
		debug("XGMAC %d: Setting SPEED to XGMII 10G\n",
			pdata->mac_idx);
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, SS, 0);
	}

	XGMAC_RGWR(pdata, MAC_TCR, mac_tcr);
	return 0;
}

static int gswss_set_2G5_intf(u32 mac_idx, u32 macif)
{
	u32 mac_if_cfg;
	int ret = 0;

	mac_if_cfg = GSWSS_RGRD(MAC_IF_CFG(mac_idx));

	if (macif == XGMAC_GMII) {
		debug("GSWSS: MACIF Configured to 2.5G with XGMAC_GMII\n");
		GSWSS_SET_BITS(mac_if_cfg, MAC_IF_CFG, CFG2G5, 0);
	} else if (macif == XGMAC_XGMII) {
		debug("GSWSS: MACIF Configured to 2.5G with XGMAC_XGMII\n");
		GSWSS_SET_BITS(mac_if_cfg, MAC_IF_CFG, CFG2G5, 1);
	} else {
		debug("GSWSS: MACIF Configured to 2.5G Wrong Value\n");
	}

	GSWSS_RGWR(MAC_IF_CFG(mac_idx), mac_if_cfg);

	return ret;
}

static int xgmac_set_gmii_2500_speed(struct mac_prv_data *pdata)
{
	u32 mac_tcr = XGMAC_RGRD(pdata, MAC_TCR);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, USS) != 0)
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, USS, 0);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, SS) != 0x2) {
		debug("XGMAC %d: Setting SPEED to GMII 2.5G\n",
			pdata->mac_idx);
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, SS, 0x2);
	}

	XGMAC_RGWR(pdata, MAC_TCR, mac_tcr);
	return 0;
}

static int xgmac_set_xgmii_2500_speed(struct mac_prv_data *pdata)
{
	u32 mac_tcr = XGMAC_RGRD(pdata, MAC_TCR);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, USS) != 1)
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, USS, 1);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, SS) != 0x2) {
		debug("XGMAC %d: Setting SPEED to XGMII 2.5G\n",
			pdata->mac_idx);
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, SS, 0x2);
	}

	XGMAC_RGWR(pdata, MAC_TCR, mac_tcr);
	return 0;
}

static int gswss_set_1g_intf(u32 mac_idx, u32 macif)
{
	u32 mac_if_cfg;
	int ret = 0;

	mac_if_cfg = GSWSS_RGRD(MAC_IF_CFG(mac_idx));

	if (macif == LMAC_GMII) {
		debug("GSWSS: MACIF Configured to CFG1G with LMAC_GMII\n");
		GSWSS_SET_BITS(mac_if_cfg, MAC_IF_CFG, CFG1G, 0);
	} else if (macif == XGMAC_GMII) {
		debug("GSWSS: MACIF Configured to CFG1G with XGMAC_GMII\n");
		GSWSS_SET_BITS(mac_if_cfg, MAC_IF_CFG, CFG1G, 1);
	} else {
		debug("GSWSS: MACIF Configured to 1G Wrong Value\n");
	}

	GSWSS_RGWR(MAC_IF_CFG(mac_idx), mac_if_cfg);

	return ret;
}

static int xgmac_set_gmii_speed(struct mac_prv_data *pdata)
{
	u32 mac_tcr = XGMAC_RGRD(pdata, MAC_TCR);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, USS) != 0)
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, USS, 0);

	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, SS) != 0x3) {
		debug("XGMAC %d: Setting SPEED to GMII 1G\n", pdata->mac_idx);
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, SS, 0x3);
	}

	XGMAC_RGWR(pdata, MAC_TCR, mac_tcr);

	return 0;
}

static int gswss_set_fe_intf(u32 mac_idx, u32 macif)
{
	u32 mac_if_cfg;
	int ret = 0;

	mac_if_cfg = GSWSS_RGRD(MAC_IF_CFG(mac_idx));

	if (macif == LMAC_MII) {
		debug("GSWSS: MACIF Configured to CFGFE with LMAC_MII\n");
		GSWSS_SET_BITS(mac_if_cfg, MAC_IF_CFG, CFGFE, 0);
	} else if (macif == XGMAC_GMII) {
		debug("GSWSS: MACIF Configured to CFGFE with XGMAC_GMII\n");
		GSWSS_SET_BITS(mac_if_cfg, MAC_IF_CFG, CFGFE, 1);
	} else {
		debug("GSWSS: MACIF Configured to CFGFE Wrong Value\n");
	}

	GSWSS_RGWR(MAC_IF_CFG(mac_idx), mac_if_cfg);

	return ret;
}

static int lmac_set_intf_mode(struct mac_prv_data *pdata, u32 val)
{
	u32 mac_ctrl0 = LMAC_RGRD(MAC_CTRL0(pdata->mac_idx));

	if (LMAC_GET_BITS(mac_ctrl0, MAC_CTRL0, GMII) != val) {
		if (val == 0)
			debug("LMAC %d: Intf mode set to : AUTO\n",
				pdata->mac_idx);
		else if (val == 1)
			debug("LMAC %d: Intf mode set to : MII"
				"(10/100/200 Mbps)\n", pdata->mac_idx);
		else if (val == 2)
			debug("LMAC %d: Intf mode set to : GMII"
				"(1000 Mbps)\n", pdata->mac_idx);
		else if (val == 3)
			debug("LMAC %d: Intf mode set to : GMII_2G"
				"(2000 Mbps)\n", pdata->mac_idx);

		LMAC_SET_BITS(mac_ctrl0, MAC_CTRL0, GMII, val);

		LMAC_RGWR(MAC_CTRL0(pdata->mac_idx), mac_ctrl0);
	}

	return 0;
}


static int mac_set_physpeed(struct mac_prv_data *pdata, u32 phy_speed,
				char *link_mode)
{
	xgmac_set_extcfg(pdata, 1);

	switch (phy_speed) {
	case SPEED_MAC_AUTO:
		gswss_set_speed(pdata->mac_idx, SPEED_AUTO);
		/* for 2.5G, we set MAC_CFG to XGMAC_GMII */
		if (!strcmp(link_mode, "2P5G_SGMII_MODE")) {
			gswss_set_fe_intf(pdata->mac_idx, XGMAC_GMII);
			gswss_set_1g_intf(pdata->mac_idx, XGMAC_GMII);
		}
		break;

	case SPEED_XGMAC_10G:
		gswss_set_speed(pdata->mac_idx, SPEED_10G);
		xgmac_set_xgmii_speed(pdata);
		break;

	case SPEED_GMII_25G:
		gswss_set_speed(pdata->mac_idx, SPEED_2G5);
		gswss_set_2G5_intf(pdata->mac_idx, XGMAC_GMII);
		xgmac_set_gmii_2500_speed(pdata);
		break;

	case SPEED_XGMII_25G:
		gswss_set_speed(pdata->mac_idx, SPEED_2G5);
		gswss_set_2G5_intf(pdata->mac_idx, XGMAC_XGMII);
		xgmac_set_xgmii_2500_speed(pdata);
		break;

	case SPEED_XGMAC_1G:
		gswss_set_speed(pdata->mac_idx, SPEED_1G);
		gswss_set_1g_intf(pdata->mac_idx, XGMAC_GMII);
		xgmac_set_gmii_speed(pdata);
		xgmac_set_extcfg(pdata, 1);
		break;

	case SPEED_XGMAC_10M:
		gswss_set_speed(pdata->mac_idx, SPEED_10M);

	case SPEED_XGMAC_100M:
		if (phy_speed != SPEED_XGMAC_10M)
			gswss_set_speed(pdata->mac_idx, SPEED_100M);

		gswss_set_fe_intf(pdata->mac_idx, XGMAC_GMII);
		gswss_set_1g_intf(pdata->mac_idx, XGMAC_GMII);
		xgmac_set_gmii_speed(pdata);
		break;

	case SPEED_LMAC_10M:
		gswss_set_speed(pdata->mac_idx, SPEED_10M);

	case SPEED_LMAC_100M:
		if (phy_speed != SPEED_LMAC_10M)
			gswss_set_speed(pdata->mac_idx, SPEED_100M);

		gswss_set_fe_intf(pdata->mac_idx, LMAC_MII);
		lmac_set_intf_mode(pdata, 1);
		break;

	case SPEED_LMAC_1G:
		gswss_set_speed(pdata->mac_idx, SPEED_1G);
		gswss_set_1g_intf(pdata->mac_idx, LMAC_GMII);
		lmac_set_intf_mode(pdata, 2);
		break;

	default:
		break;
	}

	return 0;
}

static int gswss_set_linkstatus(u32 mac_idx, u8 linkst)
{
	u16 phy_mode = 0;

	phy_mode = GSWSS_RGRD(PHY_MODE(mac_idx));

	if (GSWSS_GET_BITS(phy_mode, PHY_MODE, LINKST) != linkst) {
		if (linkst == 0)
			debug("\tGSWSS: LINK STS: Automatic mode detection"
				" by GPHY/XPCS link information outputs\n");
		else if (linkst == 1)
			debug("\tGSWSS: LINK STS: the link"
				" status is forced UP\n");
		else if (linkst == 2)
			debug("\tGSWSS: LINK STS: the link"
				" status is forced DOWN\n");
		else if (linkst == 3)
			debug("\tGSWSS: LINK STS: Reserved\n");

		GSWSS_SET_BITS(phy_mode, PHY_MODE, LINKST, linkst);
		GSWSS_RGWR(PHY_MODE(mac_idx), phy_mode);
	}

	return 0;
}

static int mac_set_linksts(struct mac_prv_data *pdata, u8 linksts)
{
	if (linksts == GSW_PORT_LINK_UP)
		gswss_set_linkstatus(pdata->mac_idx, 1);
	else if (linksts == GSW_PORT_LINK_DOWN)
		gswss_set_linkstatus(pdata->mac_idx, 2);
	else
		gswss_set_linkstatus(pdata->mac_idx, 0); // Auto

	return 0;
}

static int gswss_set_duplex_mode(u32 mac_idx, u32 val)
{
	u16 phy_mode = 0;

	phy_mode = GSWSS_RGRD(PHY_MODE(mac_idx));

	if (GSWSS_GET_BITS(phy_mode, PHY_MODE, FDUP) != val) {

		if (val == MAC_AUTO_DPLX)
			debug("\tGSWSS: Duplex mode set: Automatic"
				" mode detection by GPHY/XPCS link"
				" information outputs\n");
		else if (val == MAC_FULL_DPLX)
			debug("\tGSWSS: Duplex mode set: Full Duplex\n");
		else if (val == MAC_RES_DPLX)
			debug("\tGSWSS: Duplex mode set: Reserved\n");
		else if (val == MAC_HALF_DPLX)
			debug("\tGSWSS: Duplex mode set: Half Duplex\n");

		GSWSS_SET_BITS(phy_mode, PHY_MODE, FDUP, val);
		GSWSS_RGWR(PHY_MODE(mac_idx), phy_mode);
	}

	return 0;
}

static int lmac_set_duplex_mode(struct mac_prv_data *pdata, u32 val)
{
	u32 mac_ctrl0 = LMAC_RGRD(MAC_CTRL0(pdata->mac_idx));

	if (LMAC_GET_BITS(mac_ctrl0, MAC_CTRL0, FDUP) != val) {
		if (val == 0)
			debug("LMAC %d: FDUP mode set to : AUTO\n",
				pdata->mac_idx);
		else if (val == 1)
			debug("LMAC %d: FDUP mode set to : Full Duplex Mode\n",
				pdata->mac_idx);
		else if (val == 2)
			debug("LMAC %d: FDUP mode set to : Reserved\n",
				pdata->mac_idx);
		else if (val == 3)
			debug("LMAC %d: FDUP mode set to : Half Duplex Mode\n",
				pdata->mac_idx);

		LMAC_SET_BITS(mac_ctrl0, MAC_CTRL0, FDUP, val);
		LMAC_RGWR(MAC_CTRL0(pdata->mac_idx), mac_ctrl0);
	}

	return 0;
}

static int mac_set_duplex(struct mac_prv_data *pdata, u32 val)
{
	if (val == GSW_DUPLEX_FULL)
		val = MAC_FULL_DPLX;
	else if (val == GSW_DUPLEX_HALF)
		val = MAC_HALF_DPLX;
	else
		val = MAC_AUTO_DPLX;

	gswss_set_duplex_mode(pdata->mac_idx, val);
	lmac_set_duplex_mode(pdata, val);

	return 0;
}

/*	LPIATE: LPI Auto Timer Enable
 *	This bit controls the automatic entry of the
 *	MAC Transmitter into and exit out
 *	of the LPI state. When LPIATE, LPITXA and
 *	LPITXEN bits are set, the MAC
 *	Transmitter will enter LPI state only when the complete MAC
 *	TX data path is IDLE for a period indicated by
 *	the MAC_LPI_Auto_Entry_Timer register.
 *	After entering LPI state, if the data path becomes
 *	non-IDLE (due to a new packet being accepted
 *	for transmission), the Transmitter will exit LPI state
 *	but will not clear LPITXEN bit. This enables the re-entry
 *	into LPI state when it is IDLE again.
 *	When LPIATE is 0, the LPI Auto timer is disabled and MAC
 *	Transmitter will enter LPI state based on the settings
 *	of LPITXA and LPITXEN bit descriptions.
 *
 *	LPITXA: LPI Tx Automate
 *	This bit controls the behavior of the MAC when it is
 *	entering or coming out of the LPI mode on the Transmit side.
 *	This bit is not functional in the XGMAC-CORE configurations in which
 *	the Tx clock gating is done during the LPI mode.
 *	If the LPITXA and LPITXEN bits are set to 1, the
 *	MAC enters the LPI mode only after all outstanding
 *	packets (in the core) and pending packets (in the
 *	application interface) have been transmitted.
 *	The MAC comes out of the LPI mode when the application
 *	presents any packet for transmission or the application issues
 *	a Tx FIFO Flush command. In addition, the MAC
 *	automatically clears the LPITXEN bit when it exits
 *	the LPI state. If Tx FIFO Flush is set in the
 *	FTQ bit of MTL_TxQ0_Operation_Mode register, when
 *	the MAC is in the LPI mode, it exits the LPI mode.
 *	When this bit is 0, the LPITXEN bit directly controls
 *	behavior of the MAC when it is entering or coming out of the LPI mode.
*/
static int xgmac_set_mac_lpitx(struct mac_prv_data *pdata, u32 val)
{
	u32 lpiate;

	lpiate = XGMAC_RGRD(pdata, MAC_LPICSR);

	if (XGMAC_GET_BITS(lpiate, MAC_LPICSR, LPIATE) != val) {
		debug("XGMAC %d: LPIATE: %s\n",
			pdata->mac_idx, val ? "ENABLED" : "DISABLED");
		XGMAC_SET_BITS(lpiate, MAC_LPICSR, LPIATE, val);
	}

	if (XGMAC_GET_BITS(lpiate, MAC_LPICSR, LPITXA) != val) {
		debug("XGMAC %d: LPITXA: %s\n",
			pdata->mac_idx, val ? "ENABLED" : "DISABLED");
		XGMAC_SET_BITS(lpiate, MAC_LPICSR, LPITXA, val);
	}

	XGMAC_RGWR(pdata, MAC_LPICSR, lpiate);

	return 0;
}

int xgmac_powerdown(struct mac_prv_data *pdata)
{
	u32 mac_tcr = XGMAC_RGRD(pdata, MAC_TCR);
	u32 mac_rcr = XGMAC_RGRD(pdata, MAC_RCR);
	u32 mac_pfr = XGMAC_RGRD(pdata, MAC_PFR);

	/* Disable MAC Tx */
	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, TE) != 0) {
		debug("XGMAC %d: MAC TX: DISABLED\n", pdata->mac_idx);
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, TE, 0);
		XGMAC_RGWR(pdata, MAC_TCR, mac_tcr);
	}

	/* Disable MAC Rx */
	if (XGMAC_GET_BITS(mac_rcr, MAC_RCR, RE) != 0) {
		debug("XGMAC %d: MAC RX: DISABLED\n", pdata->mac_idx);
		XGMAC_SET_BITS(mac_rcr, MAC_RCR, RE, 0);
		XGMAC_RGWR(pdata, MAC_RCR, mac_rcr);
	}

	/* Disable MAC Filter Rx All */
	if (XGMAC_GET_BITS(mac_pfr, MAC_PFR, RA) != 0) {
		debug("XGMAC %d: MAC Filter Receive All: DISABLED\n",
			pdata->mac_idx);
		XGMAC_SET_BITS(mac_pfr, MAC_PFR, RA, 0);
		XGMAC_RGWR(pdata, MAC_PFR, mac_pfr);
	}

	return 0;
}

static int xgmac_powerup(struct mac_prv_data *pdata)
{
	u32 mac_tcr = XGMAC_RGRD(pdata, MAC_TCR);
	u32 mac_rcr = XGMAC_RGRD(pdata, MAC_RCR);
	u32 mac_pfr = XGMAC_RGRD(pdata, MAC_PFR);

	/* Enable MAC Tx */
	if (XGMAC_GET_BITS(mac_tcr, MAC_TCR, TE) != 1) {
		debug("XGMAC %d: MAC TX: ENABLED\n", pdata->mac_idx);
		XGMAC_SET_BITS(mac_tcr, MAC_TCR, TE, 1);
		XGMAC_RGWR(pdata, MAC_TCR, mac_tcr);
	}

	/* Enable MAC Rx */
	if (XGMAC_GET_BITS(mac_rcr, MAC_RCR, RE) != 1) {
		debug("XGMAC %d: MAC RX: ENABLED\n", pdata->mac_idx);
		XGMAC_SET_BITS(mac_rcr, MAC_RCR, RE, 1);
		XGMAC_RGWR(pdata, MAC_RCR, mac_rcr);
	}

	/* Enable MAC Filter Rx All */
	if (XGMAC_GET_BITS(mac_pfr, MAC_PFR, RA) != 1) {
		debug("XGMAC %d: MAC Filter Recieve All: ENABLED\n",
			pdata->mac_idx);
		XGMAC_SET_BITS(mac_pfr, MAC_PFR, RA, 1);
		XGMAC_RGWR(pdata, MAC_PFR, mac_pfr);
	}

	return 0;
}

#ifdef CONFIG_PRX300_GSWIP_CORE
static void mac_reset(struct eth_device *dev)
{
	struct mac_prv_data *pdata = (struct mac_prv_data *)dev->priv;
	struct mac_prv_data *pmac_2_data = (pdata + 2);
	u64 timeout = 0xFFFFFFFFFFFF;

	if (pmac_2_data->mac_reset_complete)
		return;

	/* Poll the link status to see if the link is up but we do
	 * not want the sys to hang if cable is unplugged.
	 * This is to prevent a long mdelay before doing the mac reset.
	 */
	while ((ltq_r32(GSWIP_SS_MODULE_BASE, PHY_STAT_4)
				& PHY_STAT_4_LSTAT_MASK) == 0) {
		timeout--;
		if (timeout == 0)
			break;
	}

	udelay(100);
	/* POWER OFF MAC Tx/Rx */
	xgmac_powerdown(pmac_2_data);
	udelay(200);
	/* POWER ON MAC Tx/Rx */
	xgmac_powerup(pmac_2_data);
	mdelay(300);

	pmac_2_data->mac_reset_complete = 1;
}
#endif /* CONFIG_PRX300_GSWIP_CORE */

static void prx300_mac_init(struct mac_prv_data *pdata,
				char *link_mode)
{
	if (link_mode == NULL) {
		printf("Error: link mode not set\n");
		return;
	}

	/* set mtu */
	if (ltq_r32(GSWIP_SS, MAC2_MTU_CFG
			+ (pdata->mac_idx * 0x100)) != pdata->mtu)
		ltq_w32(GSWIP_SS, MAC2_MTU_CFG
			+ (pdata->mac_idx * 0x100), pdata->mtu);

	xgmac_config_std_pkt(pdata);

	/* Enable MAC interrupts */
	xgmac_set_mac_int(pdata, pdata->enable_mac_int);

	/* Configure RWK filter frames */
	/* populate_filter_frames(pdata); */

	xgmac_set_extcfg(pdata, 1);

	/* Program Promisc mode and All multicast mode */
	xgmac_set_promiscuous_mode(pdata, pdata->promisc_mode);

	/* Program All multicast mode */
	xgmac_set_all_multicast_mode(pdata, pdata->all_mcast_mode);

	/* Configure MAC Speed to 10/2.5/1 G */
	mac_set_physpeed(pdata, pdata->phy_speed, link_mode);

	/* Set the link status as UP */
	if (pdata->phy_speed == SPEED_MAC_AUTO)
		mac_set_linksts(pdata, 3); /* auto */
	else
		mac_set_linksts(pdata, GSW_PORT_LINK_UP);

	/* Set the Duplex as Full Duplex */
	if (pdata->phy_speed == SPEED_MAC_AUTO)
		mac_set_duplex(pdata, 3); /* auto */
	else
		mac_set_duplex(pdata, GSW_DUPLEX_FULL);

	/* Set LPI TX Automate and LPI Auto Timer Enable
	 * to overcome packet-drop issue
	 */
	xgmac_set_mac_lpitx(pdata, 1);

	/* POWER ON MAC Tx/Rx */
	xgmac_powerup(pdata);

	/* Force disable EEE mode for 2.5G link */
	if (!strcmp(link_mode, "2P5G_SGMII_MODE"))
		ltq_w32(GSWIP_SS,
			ANG_EEE + (pdata->mac_idx * 0x100),
			CONST_ANEG_EEE_4_EEE_CAPABLE_DIS);

	pdata->mac_reset_complete = 0;
}

static int ltq_prx300_mtn_switch_init(struct eth_device *dev, bd_t *bis)
{
	int i;

	tx_num = 0;
	rx_num = 0;

	ltq_dma_w32_mask(0, (1 << DMA_CTRL_RST_POS),
			(DMA_RX_BASE | KSEG1) + DMA_CTRL);
	ltq_w32(DMA_RX_BASE, DMA_PS, RX_PORT);
	ltq_w32(DMA_RX_BASE, DMA_PCTRL, 0x1528);

	ltq_w32(DMA_RX_BASE, DMA_CS, RX_CHAN);
	ltq_w32(DMA_RX_BASE, DMA_CCTRL, 0x2);

	while (ltq_r32(DMA_RX_BASE,  DMA_CCTRL) & 0x2)
		;

	ltq_w32(DMA_RX_BASE, DMA_CPOLL, 0x80000180);
	ltq_w32(DMA_RX_BASE, DMA_CDBA,
		CPHYSADDR((u32)rx_des_ring) | 0x20000000);
	ltq_w32(DMA_RX_BASE, DMA_CDLEN, NUM_RX_DESC);
	ltq_w32(DMA_RX_BASE, DMA_CIE, 0);
	ltq_w32(DMA_RX_BASE, DMA_CCTRL, 0x10000);

	ltq_dma_w32_mask((1 << (TX_CHAN & 0x1f)), 0,
			(DMA_TX_BASE | KSEG1) + DMA_IRNEN);
	ltq_w32(DMA_TX_BASE, DMA_PS, TX_PORT);
	ltq_w32(DMA_TX_BASE, DMA_PCTRL, 0x1528);

	ltq_w32(DMA_TX_BASE, DMA_CS, TX_CHAN);
	ltq_w32(DMA_TX_BASE, DMA_CCTRL, 0x2);

	while (ltq_r32(DMA_TX_BASE, DMA_CCTRL) & 0x2)
		;

	ltq_w32(DMA_TX_BASE, DMA_CPOLL, 0x80000180);
	ltq_w32(DMA_TX_BASE, DMA_CDBA,
			CPHYSADDR((u32)tx_des_ring) | 0x20000000);
	ltq_w32(DMA_TX_BASE, DMA_CDLEN, NUM_TX_DESC);
	ltq_w32(DMA_TX_BASE, DMA_CIE, 0);
	ltq_w32(DMA_TX_BASE, DMA_CCTRL, 0x10100);
	ltq_w32(DMA_TX_BASE, DMA_CTRL, 0x80040200);

	for (i = 0; i < NUM_TX_DESC; i++) {
		_dma_tx_descriptor_t *tx_desc =
			(_dma_tx_descriptor_t *)KSEG1ADDR(&tx_des_ring[i]);
		memset(tx_desc, 0, sizeof(tx_des_ring[0]));
		tx_desc->DW3.field.byteoffset = 0;
	}

	for (i = 0; i < NUM_RX_DESC; i++) {
		_dma_rx_descriptor_t *rx_desc =
			(_dma_rx_descriptor_t *)KSEG1ADDR(&rx_des_ring[i]);
		rx_desc->DW0.all = 0;
		rx_desc->DW1.all = 0;
		rx_desc->DW3.all = 0xC8721234;
		rx_desc->DW3.field.byteoffset = 0;
		rx_desc->DW3.field.own = 1;
		rx_desc->DW3.field.datalen = (u16)PKTSIZE_ALIGN;
		rx_desc->DW2.all =
			((CPHYSADDR((u32)net_rx_packets[i])) |
				0x20000000) & 0xfffffff8;
		invalidate_dcache_range((u32)&rx_des_ring[i],
				(u32)(&rx_des_ring[i] + sizeof(rx_des_ring[0])));
	}

	/* switch on rx chan */
	ltq_dma_w32(RX_CHAN, (DMA_RX_BASE | KSEG1) + DMA_CS);
	ltq_dma_w32_mask(0, (1 << DMA_CCTRL_ON_OFF_POS),
			(DMA_RX_BASE | KSEG1) + DMA_CCTRL);

#ifdef CONFIG_PRX300_GSWIP_CORE
	/* work around for 2.5G
	 * this is placed here as we do not
	 * want a long delay in the init sequence
	 * as the GPHY needs to be linked before
	 * we can apply the workaround
	 */
	mac_reset(dev);
#endif

	return 0;
}

static void ltq_prx300_mtn_switch_halt(struct eth_device *dev)
{
	int i = 0;

	ltq_dma_w32(RX_CHAN, (DMA_RX_BASE | KSEG1) + DMA_CS);
	ltq_dma_w32_mask((1 << DMA_CCTRL_ON_OFF_POS), 0,
			(DMA_RX_BASE | KSEG1) + DMA_CCTRL);

	while ((ltq_r32(DMA_RX_BASE, DMA_CCTRL) & 0x1)) {
		i++;
		if (i > 10000) {
			printf("failed resetting rx chan\n");
			break;
		}
	}

	i = 0;

	/* turn off both tx/rx chan */
	ltq_dma_w32(TX_CHAN, (DMA_TX_BASE | KSEG1) + DMA_CS);
	ltq_dma_w32_mask((1 << DMA_CCTRL_ON_OFF_POS), 0,
			(DMA_TX_BASE | KSEG1) +  DMA_CCTRL);

	while ((ltq_r32(DMA_TX_BASE, DMA_CCTRL) & 0x1)) {
		i++;
		if (i > 10000) {
			printf("failed resetting tx chan\n");
			break;
		}
	}
}

static int ltq_prx300_mtn_switch_send(struct eth_device *dev,
			void *packet, int length)
{
	int i, res = -1;
	_dma_tx_descriptor_t *tx_desc =
			(_dma_tx_descriptor_t *)KSEG1ADDR(&tx_des_ring[tx_num]);

	if (length <= 0) {
		printf("%s: bad packet size: %d\n", dev->name, length);
		goto Done;
	}

	for (i = 0; tx_desc->DW3.field.own == 1; i++) {
		if (i >= TOUT_LOOP) {
			printf("NO Tx Descriptor...");
			goto Done;
		}
	}

	/* serial_putc('s'); */
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

	tx_desc->DW2.all = ((CPHYSADDR((u32) packet)) |
			0x20000000) & 0xfffffff8;
	asm("SYNC");
	flush_dcache_range((u32)packet,
				(u32) packet + tx_desc->DW3.field.datalen);
	asm("SYNC");
	flush_scache_range((u32)packet,
				(u32) packet + tx_desc->DW3.field.datalen);
	asm("SYNC");

	tx_desc->DW3.field.own = 1;

	res = length;
	tx_num++;
	if (tx_num == NUM_TX_DESC)
		tx_num = 0;

	/* switch on tx chan */
	ltq_dma_w32(TX_CHAN, (DMA_TX_BASE | KSEG1) + DMA_CS);
	ltq_dma_w32_mask(0, (1 << DMA_CCTRL_ON_OFF_POS),
			(DMA_TX_BASE | KSEG1) +  DMA_CCTRL);

Done:
	return res;
}

static int ltq_prx300_mtn_switch_recv(struct eth_device *dev)
{

	int length = 0;
	_dma_rx_descriptor_t *rx_desc;

	for (;;) {
		rx_desc = (_dma_rx_descriptor_t *)
				KSEG1ADDR(&rx_des_ring[rx_num]);

		if ((rx_desc->DW3.field.c == 0) ||
			(rx_desc->DW3.field.own == 1))
			break;

		length = rx_desc->DW3.field.datalen;
		if (length) {
			invalidate_scache_range((u32)net_rx_packets[rx_num],
						(u32)net_rx_packets[rx_num]
						+ rx_desc->DW3.field.datalen);
			invalidate_dcache_range((u32)net_rx_packets[rx_num],
						(u32)net_rx_packets[rx_num]
						+ rx_desc->DW3.field.datalen);
			net_process_received_packet((void *)KSEG1ADDR(
						net_rx_packets[rx_num]),
						length);
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

		if (rx_num == NUM_RX_DESC)
			rx_num = 0;
	}

	return length;
}

static void ltq_prx300_dma_init(void)
{
	u32 reg;

	/* check and enable clk for dma1 */
	reg = ltq_r32(CGU_MODULE_BASE, GGU_CLKGSR1);
	if ((reg & GGU_CLKGSR1_SWITCH_MASK) == 0)
		reg |= GGU_CLKGSR1_SWITCH_MASK;

	ltq_w32(CGU_MODULE_BASE, CGU_CLKGCR1_A, reg);

	/* configure rx */
	ltq_dma_w32_mask(0, (1 << DMA_CTRL_RST_POS),
			(DMA_RX_BASE | KSEG1) + DMA_CTRL);
	ltq_w32(DMA_RX_BASE, DMA_PS, RX_PORT);
	ltq_w32(DMA_RX_BASE, DMA_PCTRL, 0x1528);

	ltq_w32(DMA_RX_BASE, DMA_CS, RX_CHAN);

	ltq_w32(DMA_RX_BASE, DMA_CPOLL, 0x80000180);
	ltq_w32(DMA_RX_BASE,
		DMA_CDBA, CPHYSADDR((u32)rx_des_ring) | 0x20000000);
	ltq_w32(DMA_RX_BASE, DMA_CDLEN, NUM_RX_DESC);
	ltq_w32(DMA_RX_BASE, DMA_CIE, 0);
	ltq_w32(DMA_RX_BASE, DMA_CCTRL, 0x10000);
	ltq_dma_w32_mask((1 << (RX_CHAN & 0x1f)), 0,
			(DMA_RX_BASE | KSEG1) + DMA_IRNEN);
	ltq_dma_w32_mask(0, (1 << (RX_CHAN & 0x1f)),
			(DMA_RX_BASE | KSEG1) + DMA_IRNCR);

	/* configure tx */
	ltq_dma_w32_mask(0, (1 << DMA_CTRL_RST_POS),
			(DMA_TX_BASE | KSEG1) + DMA_CTRL);
	ltq_w32(DMA_TX_BASE, DMA_PS, TX_PORT);
	ltq_w32(DMA_TX_BASE, DMA_PCTRL, 0x1528);

	ltq_w32(DMA_TX_BASE, DMA_CS, TX_CHAN);

	ltq_w32(DMA_TX_BASE, DMA_CPOLL, 0x80000180);
	ltq_w32(DMA_TX_BASE, DMA_CDBA,
			CPHYSADDR((u32)tx_des_ring) | 0x20000000);
	ltq_w32(DMA_TX_BASE, DMA_CDLEN, NUM_TX_DESC);
	ltq_w32(DMA_TX_BASE, DMA_CIE, 0);
	ltq_w32(DMA_TX_BASE, DMA_CCTRL, 0x10100);
	ltq_dma_w32_mask((1 << (TX_CHAN & 0x1f)), 0,
			(DMA_TX_BASE | KSEG1) + DMA_IRNEN);
	ltq_dma_w32_mask(0, (1 << (TX_CHAN & 0x1f)),
			(DMA_TX_BASE | KSEG1) + DMA_IRNCR);
}

static void prx300_mac_config(char **link_mode)
{
	int i;
	struct mac_prv_data *pdata = &xgmac_prv_data[0];

	for (i = 0; i < MAC_IFACE; i++)
		prx300_mac_init(&pdata[i], link_mode[i]);
}

#ifdef CONFIG_PRX300_GSWIP_CORE
static void dump_internal_phy_fw_version(void)
{
	u32 mdio_value;
	struct mac_prv_data *pdata = &xgmac_prv_data[1];

	/* Issue workaround for A11 chip. Otherwise no link-up seen */
	mdio_write(pdata, 0, 0x1f, 0, 0x8040);
	/* read gphy firmware value */
	mdio_read(pdata, MDIO_DEVAD_NONE, 0x1f, 0x1e, &mdio_value);

	printf("Internal GPHY firmware version: 0x%04x\n",
		mdio_value & 0xffff);
}

int get_gphy_firmware(u32 dst, u32 src)
{
	int result = 1;
	int fw_type = 0;
	char *ep;
	char gphy_fw_name[32];
	u8 *load = (unsigned char *) 0xa0140000;
	u8 *image_start = NULL;
	ulong unc_len = 0x40000; /* set uncompress len to 256k */
	ulong image_len = 0;
	image_header_t *pimg_header = NULL;

	ep = getenv("raw_gphy_fw");

	if ((ep != NULL) && (strcmp(ep, "yes") == 0)) {
		memcpy((u32 *) dst, (u32 *) src, 65536);
		result = 0;
		goto exit;
	}

	if (ltq_get_cpu_rev() == 0)
		snprintf(gphy_fw_name, sizeof(GPHY_FW_STR_A1),
					GPHY_FW_STR_A1);
	else
		snprintf(gphy_fw_name, sizeof(GPHY_FW_STR_B0),
					GPHY_FW_STR_B0);

	pimg_header = (image_header_t *) src;
	while (1) {
		if (pimg_header->ih_magic != IH_MAGIC) {
			printf("bad image magic number\n");
			result = 1;
			break;
		}

		switch (pimg_header->ih_type) {
		case IH_TYPE_MULTI:
			printf("multi type\n");
			image_start = (u8 *)pimg_header
					+ sizeof(image_header_t) + 8;
			image_len = pimg_header->ih_size;

			if (lzmaBuffToBuffDecompress(load, (SizeT *)&unc_len,
					(unsigned char *)image_start,
					image_len)) {
				printf("gphy decompress error\n");
				result = 1;
				goto exit;
			}
			pimg_header = (image_header_t *)load;
			break;

		case IH_TYPE_FIRMWARE:
			if (strncmp((const char *)pimg_header->ih_name,
					gphy_fw_name,
					sizeof(pimg_header->ih_name)) == 0)
				fw_type = 1;

			if (fw_type == 1) {
				image_start = (u8 *)pimg_header
						+ sizeof(image_header_t);
				image_len = pimg_header->ih_size;
				memcpy((u8 *)dst, image_start, image_len);
				result = 0;
				goto exit;
			}
			pimg_header = (image_header_t *)((u32)pimg_header
					+ sizeof(image_header_t)
					+ (pimg_header->ih_size));
			break;
		}
	}

exit:
	return result;
}
#endif

void configure_mac(struct mac_prv_data *pdata)
{
	mdio_write(pdata, 0, 0x1f, 0, 0x4040);
        REG32(0xb8441498) = 0x8000;
        REG32(0xb6180120) = 0xc0000D;
        mdio_write(pdata, 0, 0x1f, 0, 0x9040);
        mdelay(600);
}

#ifdef CONFIG_PRX300_GSWIP_CORE
static int initialize_internal_phy(struct mac_prv_data *pdata)
{
	unsigned int gphy_clk;
	u32 fw_dst_addr, fw_phy_addr, fw_src_addr;
	u32 reg;
	u32 rcm_rcal_val;
	u32 rcal_fuse_val;

	if (ltq_get_cpu_rev() == 0){
		/*FOR A1 */
		rcal_fuse_val = ltq_r32(LTQ_CHIPID , FUSE_REDUND_1)>>28;
	} else {
		/*FOR B0 */
		rcal_fuse_val =  ltq_r32(LTQ_CHIPID , FUSE_REDUND_1)>>28;
		if (rcal_fuse_val == 0){
			rcal_fuse_val = ltq_r32(GPHYCDB_FCSI_MODULE_BASE,RCALSTAT);
			rcal_fuse_val = (rcal_fuse_val & 0xF);
		}
	}

	rcm_rcal_val = (0x10 << 4) | (rcal_fuse_val & 0xf);

	/* Allocate an address that is not used which is 128KB aligned.
	 * Somewhere > 16MB should be safe, upper mem used
	 * by U-boot, lower mem use for SPL
	 * This is to prevent long wait delays for the FW
	 * to be loaded completely by the PHY. This memory is usable
	 * after PHY is loaded successfully.
	 */
	fw_dst_addr = 0xA1000000;
	fw_phy_addr = CPHYSADDR(fw_dst_addr);
	asm("sync");

#ifdef CONFIG_PRX300_GPHY_FW_EMBEDDED
	fw_src_addr = CONFIG_PRX300_GPHY_FW_ADDR;
#endif

#ifdef CONFIG_PRX300_EXTERN_GPHY_FW_ADDR
	#ifdef CONFIG_LTQ_BOOT_FROM_NAND
	{
		struct mtd_info *nand = nand_info[0];
		size_t size = 131072;

		fw_src_addr = GPHY_OFFSET_ADDR;
		nand_read_skip_bad(nand, (getenv("gphy_fw_addr") ?
				simple_strtoul((char *)
					getenv("gphy_fw_addr"), NULL, 16) :
				CONFIG_PRX300_EXTERN_GPHY_FW_ADDR),
				&size, NULL, nand->size,
				(u_char *)fw_src_addr);
	}
	#else
	{
		static struct spi_flash *flash;

		fw_src_addr = GPHY_OFFSET_ADDR;
		flash = spi_flash_probe(0, CONFIG_ENV_SPI_CS,
				CONFIG_SF_DEFAULT_SPEED,
				CONFIG_SF_DEFAULT_MODE);
		spi_flash_read(flash, (getenv("gphy_fw_addr") ?
				simple_strtoul((char *)getenv("gphy_fw_addr"),
				NULL, 16) :
				CONFIG_PRX300_EXTERN_GPHY_FW_ADDR),
				65536, (void *)fw_src_addr);
	}
	#endif /* CONFIG_LTQ_BOOT_FROM_NAND */
#endif	/* CONFIG_PRX300_GPHY_FW_EMBEDDED */
	asm("sync");
	if (get_gphy_firmware(fw_dst_addr, fw_src_addr)) {
		printf("cannot find gphy firmware!!\n");
		return -EINVAL;
	}

	/* LAN_MUX to GPHY */
	ltq_w32(CHIP_TOP_MODULE_BASE, IFMUX_CFG,
		(ltq_r32(CHIP_TOP_MODULE_BASE, IFMUX_CFG) & ~(IFMUX_CFG_LAN_MUX_MASK)));
	/* GPHY & CDB reset */
	ltq_w32(RCU_MODULE_BASE, RST_REQ,
		ltq_r32(RCU_MODULE_BASE, RST_REQ) | (1 << RST_REQ_GPHY_POS));
	udelay(500);

	ltq_w32(RCU_MODULE_BASE, RST_REQ2,
		ltq_r32(RCU_MODULE_BASE, RST_REQ2) |
			((1 << RST_REQ2_GPHY_PWR_DOWN_POS) |
			(1 << RST_REQ2_GPHY_CDB_POS)));
	udelay(400);
	/* release CDB reset */
	ltq_w32(RCU_MODULE_BASE, RST_REQ2,
		ltq_r32(RCU_MODULE_BASE, RST_REQ2) & ~(RST_REQ2_GPHY_CDB_MASK));

	/* For 25Mhz settings, no matter the VCO value, we will use the default
 	 * register settings to configure the GPHY CDB clk.
 	 * At 40Mhz, we have to configure this accordingly.
 	 */
	gphy_clk = get_gphy_clk() / 1000000;
	if (gphy_clk > 25) {
		/* GPHY CDB clock change to 40MHz with FB_DIV=0x145(325)
		 * REF_DIV=4
		 */
		ltq_w32(GPHY_CDB_PDI_MODULE_BASE, GPHY_CDB_PDI_PLL_CFG0, 0x145B);
		ltq_w32(GPHY_CDB_PDI_MODULE_BASE, GPHY_CDB_PDI_PLL_CFG2, 0x0400);
		ltq_w32(GPHY_CDB_PDI_MODULE_BASE, GPHY_CDB_PDI_PLL_MISC, 0x6000);
	}
	mdelay(100);

	/* GPHY FW address */
	ltq_w32(CGU_MODULE_BASE, GPHY_FCR, fw_phy_addr);

	if (gphy_clk > 25) {
		/* CDB Pll lock 40MHz */
		while (!((ltq_r32(GPHY_CDB_PDI_MODULE_BASE,
				GPHY_CDB_PDI_PLL_CFG0) & 0xffff) == 0x145b));
	} else {
		/* CDB Pll lock 25MHz */
		while (!((ltq_r32(GPHY_CDB_PDI_MODULE_BASE,
				GPHY_CDB_PDI_PLL_CFG0) & 0xffff) == 0x082b));
	}

	/* gpio mapping configurations */
	reg = 0x4000;
	/* MDIO chip ID value to prx300 */
	reg |= (0xd << 16);
	/* MDIO address */
	reg |= (0x1f << 24);
	/* interrupt polarity configurations */
	reg |= (1 << 29);
	/* program lo register */
	ltq_w32(CGU_MODULE_BASE, GPHY0_GPS0, reg);
	ltq_w32(CGU_MODULE_BASE, GPHY0_GPS1, rcm_rcal_val);
	ltq_w32(RCU_MODULE_BASE, RST_REQ, (ltq_r32(RCU_MODULE_BASE, RST_REQ) | (RST_REQ_GPHY_MASK))   );
	udelay(100);

	/* GPHY Reset ? already reset
	 * ltq_w32(RCU_MODULE_BASE, RST_REQ,
	 *	ltq_r32(RCU_MODULE_BASE, RST_REQ) | (1 << RST_REQ_GPHY_POS));
	 */
	/* GPHY out of reset */
	ltq_w32(RCU_MODULE_BASE, RST_REQ,
		(ltq_r32(RCU_MODULE_BASE, RST_REQ) & ~(RST_REQ_GPHY_MASK)));

	asm("sync");
	udelay(500);

	/* GPHY Power on */
	ltq_w32(RCU_MODULE_BASE, RST_REQ2,
		ltq_r32(RCU_MODULE_BASE, RST_REQ2) & ~(1 << RST_REQ2_GPHY_PWR_DOWN_POS));

	asm("sync");
	udelay(500);

	return 0;
}
#else
static void initialize_aquantia_phy(struct mac_prv_data *pdata,
					char **link_mode)
{
	/* configure reset for xpcs and phy */
	ltq_w32(RCU_MODULE_BASE, RST_REQ,
		ltq_r32(RCU_MODULE_BASE, RST_REQ) |
			(RST_REQ_PHY1_MASK |
			RST_REQ_PHY0_MASK | RST_REQ_XPCS0_MASK |
			RST_REQ_XPCS1_MASK | RST_REQ_XPCS2_MASK |
			RST_REQ_CPHYSS_MASK));

	ltq_w32(RCU_MODULE_BASE, RST_REQ,
		ltq_r32(RCU_MODULE_BASE, RST_REQ) & ~RST_REQ_CPHYSS_MASK);

	ltq_w32(RCU_MODULE_BASE, RST_REQ,
		ltq_r32(RCU_MODULE_BASE, RST_REQ) &
			~(RST_REQ_PHY1_MASK | RST_REQ_PHY0_MASK));

	ltq_w32(RCU_MODULE_BASE, RST_REQ,
		ltq_r32(RCU_MODULE_BASE, RST_REQ) &
			~(RST_REQ_XPCS0_MASK | RST_REQ_XPCS1_MASK));

	/* Configure MUX */
	/* bit	 0: 0 - PON WAN
	 *	    1 - ETH WAN
	 *	 1: 0 - Internal GPHY MAC4
	 *	    1 - SFP MAC4
	 *     2~4: 0 - Dual PCIe with single lane each
	 *	    1 - Single PCIe with dual lane
	 *	    2 - RXAUI
	 *	    3 - Dual XFI with single lane each
	 *	    4 - XPCS0 (XGMAC3) XFI, PCIe1 single lane
	 *	    5 - PCIe0 single lane, XPCS1 (XGMAC4) XFI
	 */
	ltq_w32(CHIP_TOP_MODULE_BASE, IFMUX_CFG,
		((ltq_r32(CHIP_TOP_MODULE_BASE, IFMUX_CFG) & ~0x1C) | 0xF));

	/* XPCS Init for lan0 & lan1 */
	prx300_xpcs_init(&link_mode[1]);

}
#endif /* CONFIG_PRX300_GSWIP_CORE */

void ltq_prx300_sw_init(void)
{
	unsigned int num_ports, vports, total_ports;
	struct mac_prv_data *pdata = &xgmac_prv_data[0];
	char *link_mode[3] = {
		"1G_XAUI_MODE",
		"1G_XAUI_MODE",
		"1G_XAUI_MODE",
	};

#ifdef CONFIG_PRX300_GSWIP_CORE
	int ret = 0;

	ret = initialize_internal_phy(pdata);
	if (ret)
		return;
#else
	link_mode[1] = getenv("lan0-xpcs-mode");
	if (link_mode[1] == NULL) {
		link_mode[1] = "1G_XAUI_MODE";
	}

	link_mode[2] = getenv("lan1-xpcs-mode");
	if (link_mode[2] == NULL) {
		link_mode[2] = "1G_XAUI_MODE";
	}

	initialize_aquantia_phy(pdata, link_mode);
#endif /* CONFIG_PRX300_GSWIP_CORE */

	/* Put GWIP in reset */
	ltq_w32(RCU_MODULE_BASE, RST_REQ,
		(ltq_r32(RCU_MODULE_BASE, RST_REQ) & ~(RST_REQ_GSWIP_MASK)));

	num_ports = (ltq_r32(ETHSW_PDI_MODULE_BASE, ETHSW_CAP_1) & 0xF);
	vports = (ltq_r32(ETHSW_PDI_MODULE_BASE, ETHSW_CAP_1) & 0xF0);
	total_ports = num_ports + vports;

	/* mac set & reset needed ?
 	 * KIV, test on diff boards and decide
 	 * new code added for Internal GPHY link
	 * configure_mac(pdata);
	 */

	/* microcode init */
	prx300_load_microcode(num_ports);
	/* mac init */
	prx300_mac_config(link_mode);
	/* enable switch */
	prx300_switch_enable(total_ports);
	/* Init DMA */
	ltq_prx300_dma_init();

}

static int register_eth_iface(void)
{
	int i;
	char mdio_name[6];
	struct mac_prv_data *pdata = &xgmac_prv_data[0];
	struct eth_device *dev;

	dev = (struct eth_device *)
			malloc(sizeof(struct eth_device));
	if (!dev) {
		printf("Failed to allocate initialized switch mem\n");
		return -EINVAL;
	}

	memset(dev, 0, sizeof(struct eth_device));
	dev->priv = pdata;

	snprintf(dev->name, sizeof(dev->name), "prx300-eth");

	dev->init = ltq_prx300_mtn_switch_init;
	dev->halt = ltq_prx300_mtn_switch_halt;
	dev->send = ltq_prx300_mtn_switch_send;
	dev->recv = ltq_prx300_mtn_switch_recv;

	eth_register(dev);

	/* we only register the two mdio iface */
	for (i = 0; i < 2; i++) {
		snprintf(mdio_name, sizeof(mdio_name) / sizeof(char),
				"mdio%d", i);
		prx300_mdio_init(dev, mdio_name);
	}

#ifdef CONFIG_PRX300_GSWIP_CORE
	dump_internal_phy_fw_version();
#endif

	return 0;
}

int prx300_eth_initialize(bd_t *bis)
{
	int ret = 0;

	ltq_prx300_sw_init();
	ret = register_eth_iface();

	return ret;
}

