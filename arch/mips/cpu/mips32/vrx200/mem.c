/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/spl.h>
#include <asm/lantiq/cpu.h>
#include <asm/lantiq/mem.h>

/* Must be configured in BOARDDIR */
#include <ddr_settings.h>

#if defined(CONFIG_SYS_DRAM_PROBE)
#define mc_sdram_probe_enable		1
#else
#define mc_sdram_probe_enable		0
#endif

#define CCS_AHBM_CR_BURST_EN		(1 << 2)
#define CCS_FPIM_CR_BURST_EN		(1 << 1)

#define CCR03_EIGHT_BANK_MODE		(1 << 0)
#define CCR07_START			(1 << 8)
#define CCR08_CS_MAP_SHIFT		24
#define CCR08_CS_MAP_MASK		(0x3 << CCR08_CS_MAP_SHIFT)
#define CCR11_COLUMN_SIZE_SHIFT		24
#define CCR11_COLUMN_SIZE_MASK		(0x7 << CCR11_COLUMN_SIZE_SHIFT)
#define CCR11_COLUMN_SIZE_10		(2 << CCR11_COLUMN_SIZE_SHIFT)
#define CCR11_ADDR_PINS_MASK		0x7
#define CCR15_MAX_COL_REG_SHIFT		24
#define CCR15_MAX_COL_REG_MASK		(0xF << CCR15_MAX_COL_REG_SHIFT)
#define CCR16_MAX_ROW_REG_MASK		0xF
#define CCR39_DLL_RD_DQ_DEL_NM_SHIFT	8
#define CCR39_DLL_RD_DQ_DEL_NM_MASK	(0xFF << CCR43_DLL_WR_DQ_DEL_NM_SHIFT)
#define CCR43_DLL_WR_DQ_DEL_NM_SHIFT	8
#define CCR43_DLL_WR_DQ_DEL_NM_MASK	(0xFF << CCR43_DLL_WR_DQ_DEL_NM_SHIFT)
#define CCR47_DLL_LOCK_IND		1

#define DEFAULT_GATE_ECHO_DLL		0x24

struct mc_global_regs {
	u32 rsvd0[0x100];
	u32 ddr_gsr0;		/* DDR SDRAM controller global status 0 */
	u32 rsvd1;
	u32 ddr_gcr0;		/* DDR SDRAM controller global control 0 */
	u32 rsvd2;
	u32 ddr_gcr1;		/* DDR SDRAM controller global control 1 */
	u32 rsvd3;
	u32 ddr_prio_ti;	/* DDR SDRAM controller priority of transaction initiator */
	u32 rsvd4;
	u32 ddr_echo_dll0;	/* DDR SDRAM controller echo gate DLL0 control */
	u32 rsvd5;
	u32 ddr_echo_dll1;	/* DDR SDRAM controller echo gate DLL1 control */
	u32 rsvd6;
	u32 ccs;		/* undocumented */
};

static struct mc_global_regs *mc_global_regs =
	(void *) CKSEG1ADDR(LTQ_MC_GLOBAL_BASE);
static void *mc_ddr_base = (void *) CKSEG1ADDR(LTQ_MC_DDR_BASE);
static void *bootrom_base = (void *) CKSEG1ADDR(LTQ_BOOTROM_BASE);

static __always_inline
u32 mc_ccr_read(u32 index)
{
	return ltq_readl(mc_ddr_base + LTQ_MC_DDR_CCR_OFFSET(index));
}

static __always_inline
void mc_ccr_write(u32 index, u32 val)
{
	ltq_writel(mc_ddr_base + LTQ_MC_DDR_CCR_OFFSET(index), val);
}

static __always_inline
void mc_ccr_dump(u32 index)
{
	const void *addr = (void *)(mc_ddr_base +
		LTQ_MC_DDR_CCR_OFFSET(index));
	spl_debug("CCR%02u: 0x%p = 0x%08x\n", index, addr, ltq_readl(addr));
}

static __always_inline
u32 bootrom_readl(u32 offset)
{
	return ltq_readl(bootrom_base + offset);
}

static __always_inline
void bootrom_writel(u32 offset, u32 val)
{
	ltq_writel(bootrom_base + offset, val);
}

static __always_inline
void mc_ddr_echo_dll_writel(unsigned int slice, unsigned int delay)
{
	if (slice)
		ltq_writel(&mc_global_regs->ddr_echo_dll1, delay);
	else
		ltq_writel(&mc_global_regs->ddr_echo_dll0, delay);
}

static __always_inline
void mc_halt(void)
{
	/*
	 * Create multiple dummy accesses to ROM space to ensure the MIPS to
	 * Xbar path is cleared of pending DDR SDRAM transactions.
	 */
	bootrom_writel(0, bootrom_readl(4));
	bootrom_writel(4, bootrom_readl(8));
	bootrom_writel(8, bootrom_readl(0));

	/* Stop memory controller */
	mc_ccr_write(7, MC_CCR07_VALUE & ~CCR07_START);
}

static __always_inline
void mc_start(void)
{
	/* Start initialization sequence */
	mc_ccr_write(7, MC_CCR07_VALUE | CCR07_START);

	/* Wait until DLL0 has locked */
	while (!(mc_ccr_read(47) & CCR47_DLL_LOCK_IND))
		;

	/* Wait until DLL1 has locked */
	while (!(mc_ccr_read(48) & CCR47_DLL_LOCK_IND))
		;
}

static __always_inline
void mc_init(void)
{
	u32 ccr03 = MC_CCR03_VALUE;
	u32 ccr11 = MC_CCR11_VALUE;

	/*
	 * Initial probe settings are 8-bank mode enabled, 14 use address
	 * row bits, 10 used column address bits.
	 */
	if (mc_sdram_probe_enable) {
		ccr03 |= CCR03_EIGHT_BANK_MODE;
		ccr11 &= ~(CCR11_COLUMN_SIZE_MASK | CCR11_ADDR_PINS_MASK);
		ccr11 |= CCR11_COLUMN_SIZE_10;
	}

	/* Init MC DDR CCR registers with values from ddr_settings.h */
	mc_ccr_write(0, MC_CCR00_VALUE);
	mc_ccr_write(1, MC_CCR01_VALUE);
	mc_ccr_write(2, MC_CCR02_VALUE);
	mc_ccr_write(3, ccr03);
	mc_ccr_write(4, MC_CCR04_VALUE);
	mc_ccr_write(5, MC_CCR05_VALUE);
	mc_ccr_write(6, MC_CCR06_VALUE);
	mc_ccr_write(8, MC_CCR08_VALUE);
	mc_ccr_write(9, MC_CCR09_VALUE);

	mc_ccr_write(10, MC_CCR10_VALUE);
	mc_ccr_write(11, ccr11);
	mc_ccr_write(12, MC_CCR12_VALUE);
	mc_ccr_write(13, MC_CCR13_VALUE);
	mc_ccr_write(14, MC_CCR14_VALUE);
	mc_ccr_write(15, MC_CCR15_VALUE);
	mc_ccr_write(16, MC_CCR16_VALUE);
	mc_ccr_write(17, MC_CCR17_VALUE);
	mc_ccr_write(18, MC_CCR18_VALUE);
	mc_ccr_write(19, MC_CCR19_VALUE);

	mc_ccr_write(20, MC_CCR20_VALUE);
	mc_ccr_write(21, MC_CCR21_VALUE);
	mc_ccr_write(22, MC_CCR22_VALUE);
	mc_ccr_write(23, MC_CCR23_VALUE);
	mc_ccr_write(24, MC_CCR24_VALUE);
	mc_ccr_write(25, MC_CCR25_VALUE);
	mc_ccr_write(26, MC_CCR26_VALUE);
	mc_ccr_write(27, MC_CCR27_VALUE);
	mc_ccr_write(28, MC_CCR28_VALUE);
	mc_ccr_write(29, MC_CCR29_VALUE);

	mc_ccr_write(30, MC_CCR30_VALUE);
	mc_ccr_write(31, MC_CCR31_VALUE);
	mc_ccr_write(32, MC_CCR32_VALUE);
	mc_ccr_write(33, MC_CCR33_VALUE);
	mc_ccr_write(34, MC_CCR34_VALUE);
	mc_ccr_write(35, MC_CCR35_VALUE);
	mc_ccr_write(36, MC_CCR36_VALUE);
	mc_ccr_write(37, MC_CCR37_VALUE);
	mc_ccr_write(38, MC_CCR38_VALUE);
	mc_ccr_write(39, MC_CCR39_VALUE);

	mc_ccr_write(40, MC_CCR40_VALUE);
	mc_ccr_write(41, MC_CCR41_VALUE);
	mc_ccr_write(42, MC_CCR42_VALUE);
	mc_ccr_write(43, MC_CCR43_VALUE);
	mc_ccr_write(44, MC_CCR44_VALUE);
	mc_ccr_write(45, MC_CCR45_VALUE);
	mc_ccr_write(46, MC_CCR46_VALUE);

	mc_ccr_write(52, MC_CCR52_VALUE);
	mc_ccr_write(53, MC_CCR53_VALUE);
	mc_ccr_write(54, MC_CCR54_VALUE);
	mc_ccr_write(55, MC_CCR55_VALUE);
	mc_ccr_write(56, MC_CCR56_VALUE);
	mc_ccr_write(57, MC_CCR57_VALUE);
	mc_ccr_write(58, MC_CCR58_VALUE);
	mc_ccr_write(59, MC_CCR59_VALUE);

	mc_ccr_write(60, MC_CCR60_VALUE);
	mc_ccr_write(61, MC_CCR61_VALUE);

	/* Set initial values for gate echo DLL */
	mc_ddr_echo_dll_writel(0, DEFAULT_GATE_ECHO_DLL);
	mc_ddr_echo_dll_writel(1, DEFAULT_GATE_ECHO_DLL);

	/* Disable bursts between FPI Master bus and XBAR bus */
	ltq_writel(&mc_global_regs->ccs, CCS_AHBM_CR_BURST_EN);
}

static __always_inline
void mc_sdram_probe(void)
{
	u32 ccr03 = MC_CCR03_VALUE;
	u32 ccr11 = MC_CCR11_VALUE;
	u32 val;

	/*
	 * Eight bank mode test:
	 * - store a 1 at offset 0
	 * - store a 0 at offset 2^13 (bit 2 in bank select address BA[3])
	 * - load value at offset 0
	 * - if that value is 0, the eight bank mode must be disabled
	 */
	sdram_uc_writel(0, 1);
	sdram_uc_writel(1 << 13, 0);
	val = sdram_uc_readl(0);
	if (!val)
		ccr03 &= ~CCR03_EIGHT_BANK_MODE;

	/*
	 * Row address test:
	 * - store a 0 at offset 0
	 * - store a 1 at offset 2^27 (bit 13 of row address RA[14])
	 * - store a 2 at offset 2^26 (bit 12 of row address RA[14])
	 * - load value at offset 0
	 * - value indicates the useable row address bits
	 */
	sdram_uc_writel(0, 0);
	sdram_uc_writel(1 << 27, 1);
	sdram_uc_writel(1 << 26, 2);
	val = sdram_uc_readl(0);
	ccr11 += val;

	/*
	 * Column address test:
	 * - store a 0 at offset 0
	 * - store a 1 at offset 2^10 (bit 9 of column address CA[10])
	 * - store a 2 at offset 2^9 (bit 8 of column address CA[10])
	 * - load value at offset 0
	 * - value indicates the useable column address bits
	 */
	sdram_uc_writel(0, 0);
	sdram_uc_writel(1 << 10, 1);
	sdram_uc_writel(1 << 9, 2);
	val = sdram_uc_readl(0);
	ccr11 += val << CCR11_COLUMN_SIZE_SHIFT;

	mc_halt();
	mc_ccr_write(3, ccr03);
	mc_ccr_write(11, ccr11);
	mc_start();
}

void ltq_mem_init(void)
{
	mc_halt();
	mc_init();
	mc_start();

	if (mc_sdram_probe_enable)
		mc_sdram_probe();
}

static phys_size_t mc_sdram_size(void)
{
	unsigned int max_col_reg, max_row_reg, column_size, addr_pins;
	unsigned int banks, cs_map;
	phys_size_t size;

	banks = (mc_ccr_read(3) & CCR03_EIGHT_BANK_MODE) ? 8 : 4;

	cs_map = (mc_ccr_read(8) & CCR08_CS_MAP_MASK) >>
		CCR08_CS_MAP_SHIFT;

	column_size = (mc_ccr_read(11) & CCR11_COLUMN_SIZE_MASK) >>
		CCR11_COLUMN_SIZE_SHIFT;

	addr_pins = mc_ccr_read(11) & CCR11_ADDR_PINS_MASK;

	max_col_reg = (mc_ccr_read(15) & CCR15_MAX_COL_REG_MASK) >>
		CCR15_MAX_COL_REG_SHIFT;

	max_row_reg = mc_ccr_read(16) & CCR16_MAX_ROW_REG_MASK;

	/*
	 * size (bytes) = 2 ^ rowsize * 2 ^ colsize * banks * chipselects
	 *                 * datawidth (bytes)
	 */
	size = (2 << (max_col_reg - column_size - 1)) *
		(2 << (max_row_reg - addr_pins - 1)) * banks * cs_map * 2;

	return size;
}

static void test_dump(const u8 *buf, unsigned int start, unsigned int stop)
{
	unsigned int i;

	for (i = start; i < stop; i++) {
		if (buf[i])
			putc('1');
		else
			putc('0');

		if (i % 16 == 15)
			putc('\n');
		else
			putc(' ');
	}
}

static __always_inline void mc_rd_dq_writel(unsigned int slice,
						unsigned int delay)
{
	unsigned int offset = 39 + slice;
	u32 val;

	val = mc_ccr_read(offset);
	val &= ~CCR39_DLL_RD_DQ_DEL_NM_MASK;
	val |= delay << CCR39_DLL_RD_DQ_DEL_NM_SHIFT;
	mc_ccr_write(offset, val);
}

static __always_inline void mc_wr_dq_writel(unsigned int slice,
						unsigned int delay)
{
	unsigned int offset = 43 + slice;
	u32 val;

	val = mc_ccr_read(offset);
	val &= ~CCR43_DLL_WR_DQ_DEL_NM_MASK;
	val |= delay << CCR43_DLL_WR_DQ_DEL_NM_SHIFT;
	mc_ccr_write(offset, val);
}

int mc_tune_perform(struct mc_tune_cfg *cfg)
{
	const phys_size_t sdram_size = mc_sdram_size();
	const unsigned int read_max_q = 0x2b;
	const unsigned int read_min_q = 0x15;
	const unsigned int read_max = 0x3f;
	const unsigned int read_min = 0x00;
	const unsigned int write_q = 0x55;
	const unsigned int write_max = 0x7f;
	const unsigned int write_min = 0x40;
	const unsigned int echo_dll_size = 0x80;
	const unsigned int echo_dll_init = 0x20;
	unsigned int i, dq;
	unsigned int read_dq_l, read_dq_u, write_dq_l, write_dq_u;
	unsigned int echo_dll_l, echo_dll_u;
	unsigned int min_l, max_l, min_u, max_u;
	u8 test_u[128], test_l[128];
	int ret;

#if 0
	mc_ccr_dump(3);
	mc_ccr_dump(11);
	mc_ccr_dump(39);
	mc_ccr_dump(40);
	mc_ccr_dump(43);
	mc_ccr_dump(44);
	mc_ccr_dump(53);
	mc_ccr_dump(54);
#endif

	mc_ddr_echo_dll_writel(0, echo_dll_init);
	mc_ddr_echo_dll_writel(1, echo_dll_init);

	/* initial read DQ delay tuning */
	min_l = read_max_q;
	max_l = read_min_q;
	min_u = read_max_q;
	max_u = read_min_q;

	for (i = 0; i < 15; i++) {
		mc_halt();
		mc_wr_dq_writel(0, write_q + i);
		mc_wr_dq_writel(1, write_q + i);

		for (dq = read_min_q; dq < read_max_q; dq++) {
			mc_halt();
			mc_rd_dq_writel(0, dq);
			mc_rd_dq_writel(1, dq);
			mc_start();
			__udelay(100);

			ret = ltq_mem_test_tune(sdram_size, 0, 1);
			if (ret == 0) {
				if (min_l > dq)
					min_l = dq;

				if (max_l < dq)
					max_l = dq;
			}

			ret = ltq_mem_test_tune(sdram_size, 1, 1);
			if (ret == 0) {
				if (min_u > dq)
					min_u = dq;

				if (max_u < dq)
					max_u = dq;
			}
		}
	}

	if (max_l > min_l) {
		read_dq_l = (min_l + max_l) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable initial read DQS delay for slice #0\n");
		goto err;
	}

	if (max_u > min_u) {
		read_dq_u = (min_u + max_u) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable initial read DQS delay for slice #1\n");
		goto err;
	}

	/* gate echo DLL tuning */
	min_l = echo_dll_size;
	max_l = 0;
	min_u = echo_dll_size;
	max_u = 0;

	if (spl_mc_tune_debug) {
		memset(test_l, 0, sizeof(test_l));
		memset(test_u, 0, sizeof(test_u));
	}

	for (i = 0; i < echo_dll_size; i++) {
		mc_ddr_echo_dll_writel(0, i);
		mc_ddr_echo_dll_writel(1, i);
		cpu_sync();

		ret = ltq_mem_test_tune(sdram_size, 0, 0);
		if (ret == 0) {
			if (min_l > i)
				min_l = i;

			if (max_l < i)
				max_l = i;

			if (spl_mc_tune_debug)
				test_l[i] = 1;
		}

		ret = ltq_mem_test_tune(sdram_size, 1, 0);
		if (ret == 0) {
			if (min_u > i)
				min_u = i;

			if (max_u < i)
				max_u = i;

			if (spl_mc_tune_debug)
				test_u[i] = 1;
		}
	}

	if (max_l > min_l) {
		echo_dll_l = (min_l + max_l) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable echo DLL delay for slice #0\n");
		goto err;
	}

	if (max_u > min_u) {
		echo_dll_u = (min_u + max_u) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable echo DLL delay for slice #1\n");
		goto err;
	}

	if (spl_mc_tune_debug) {
		printf("\nEcho DLL delay slice 0: %02x\n", echo_dll_l);
		test_dump(test_l, 0, echo_dll_size);
		printf("\nEcho DLL delay slice 1: %02x\n", echo_dll_u);
		test_dump(test_u, 0, echo_dll_size);
	}

	mc_ddr_echo_dll_writel(0, echo_dll_l);
	mc_ddr_echo_dll_writel(1, echo_dll_u);
	cpu_sync();

	/* write data eye tuning */
	min_l = write_max;
	max_l = write_min;
	min_u = write_max;
	max_u = write_min;

	if (spl_mc_tune_debug) {
		memset(test_l, 0, sizeof(test_l));
		memset(test_u, 0, sizeof(test_u));
	}

	mc_halt();
	mc_rd_dq_writel(0, read_dq_l);
	mc_rd_dq_writel(1, read_dq_u);

	for (dq = write_min; dq < write_max; dq++) {
		mc_halt();
		mc_wr_dq_writel(0, dq);
		mc_wr_dq_writel(1, dq);
		mc_start();
		__udelay(100);

		ret = ltq_mem_test_tune(sdram_size, 0, 0);
		if (ret == 0) {
			if (min_l > dq)
				min_l = dq;

			if (max_l < dq)
				max_l = dq;

			if (spl_mc_tune_debug)
				test_l[dq] = 1;
		}

		ret = ltq_mem_test_tune(sdram_size, 1, 0);
		if (ret == 0) {
			if (min_u > dq)
				min_u = dq;

			if (max_u < dq)
				max_u = dq;

			if (spl_mc_tune_debug)
				test_u[dq] = 1;
		}
	}

	if (max_l > min_l) {
		write_dq_l = (min_l + max_l) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable write DQS delay for slice #0\n");
		goto err;
	}

	if (max_u > min_u) {
		write_dq_u = (min_u + max_u) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable write DQS delay for slice #1\n");
		goto err;
	}

	if (spl_mc_tune_debug) {
		printf("\nWrite DQ delay slice 0: %02x\n", write_dq_l);
		test_dump(test_l, write_min, write_max + 1);
		printf("\nWrite DQ delay slice 1: %02x\n", write_dq_u);
		test_dump(test_u, write_min, write_max + 1);
	}

	/* read data eye tuning */
	min_l = read_max;
	max_l = read_min;
	min_u = read_max;
	max_u = read_min;

	if (spl_mc_tune_debug) {
		memset(test_l, 0, sizeof(test_l));
		memset(test_u, 0, sizeof(test_u));
	}

	mc_halt();
	mc_wr_dq_writel(0, write_dq_l);
	mc_wr_dq_writel(1, write_dq_u);

	for (dq = read_min_q; dq < read_max_q; dq++) {
		mc_halt();
		mc_rd_dq_writel(0, dq);
		mc_rd_dq_writel(1, dq);
		mc_start();
		__udelay(100);

		ret = ltq_mem_test_tune(sdram_size, 0, 0);
		if (ret == 0) {
			if (min_l > dq)
				min_l = dq;

			if (max_l < dq)
				max_l = dq;

			if (spl_mc_tune_debug)
				test_l[dq] = 1;
		}

		ret = ltq_mem_test_tune(sdram_size, 1, 0);
		if (ret == 0) {
			if (min_u > dq)
				min_u = dq;

			if (max_u < dq)
				max_u = dq;

			if (spl_mc_tune_debug)
				test_u[dq] = 1;
		}
	}

	if (max_l > min_l) {
		read_dq_l = (min_l + max_l) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable read DQS delay for slice #0\n");
		goto err;
	}

	if (max_u > min_u) {
		read_dq_u = (min_u + max_u) >> 1;
	} else {
		spl_puts("MEM: failed to determine a suitable read DQS delay for slice #1\n");
		goto err;
	}

	if (spl_mc_tune_debug) {
		printf("\nRead DQ delay slice 0: %02x\n", read_dq_l);
		test_dump(test_l, read_min, read_max + 1);
		printf("\nRead DQ delay slice 1: %02x\n", read_dq_u);
		test_dump(test_u, read_min, read_max + 1);
	}

	mc_halt();
	mc_rd_dq_writel(0, read_dq_l);
	mc_rd_dq_writel(1, read_dq_u);
	mc_start();

	cfg->gate_echo_dll_l = echo_dll_l;
	cfg->gate_echo_dll_u = echo_dll_u;
	cfg->write_dqs_delay_l = write_dq_l;
	cfg->write_dqs_delay_u = write_dq_u;
	cfg->read_dqs_delay_l = read_dq_l;
	cfg->read_dqs_delay_u = read_dq_u;
	cfg->state = MC_TUNE_VALID;

	return 0;

err:
	/* restore original values */
	cfg->state = MC_TUNE_INVALID;
	mc_halt();
	mc_ccr_write(39, MC_CCR39_VALUE);
	mc_ccr_write(40, MC_CCR40_VALUE);
	mc_ccr_write(43, MC_CCR43_VALUE);
	mc_ccr_write(44, MC_CCR44_VALUE);
	mc_ddr_echo_dll_writel(0, DEFAULT_GATE_ECHO_DLL);
	mc_ddr_echo_dll_writel(1, DEFAULT_GATE_ECHO_DLL);
	mc_start();

	return 1;
}

void mc_tune_apply(const struct mc_tune_cfg *cfg)
{
	mc_halt();
	mc_ddr_echo_dll_writel(0, cfg->gate_echo_dll_l);
	mc_ddr_echo_dll_writel(1, cfg->gate_echo_dll_u);
	mc_wr_dq_writel(0, cfg->write_dqs_delay_l);
	mc_wr_dq_writel(1, cfg->write_dqs_delay_u);
	mc_rd_dq_writel(0, cfg->read_dqs_delay_l);
	mc_rd_dq_writel(1, cfg->read_dqs_delay_u);
	mc_start();
}

phys_size_t initdram(int board_type)
{
	return mc_sdram_size();
}
