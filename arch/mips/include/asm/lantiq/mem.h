/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2014 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#ifndef __LANTIQ_MEM_H__
#define __LANTIQ_MEM_H__

#include <asm/io.h>

int ltq_mem_test_data_bus(phys_size_t dram_size);
int ltq_mem_test_address_bus(phys_size_t dram_size);
int ltq_mem_test_device(phys_addr_t addr, phys_size_t size);
int ltq_mem_test_tune(phys_size_t dram_size, unsigned int slice, int quick);

static inline void sdram_uc_writeb(u32 offset, u8 val)
{
	__raw_writeb(val, (void *)(CONFIG_SYS_SDRAM_BASE_UC + offset));
}

static inline void sdram_uc_writew(u32 offset, u16 val)
{
	__raw_writew(val, (void *)(CONFIG_SYS_SDRAM_BASE_UC + offset));
}

static inline void sdram_uc_writel(phys_addr_t offset, u32 val)
{
	__raw_writel(val, (void *)(CONFIG_SYS_SDRAM_BASE_UC + offset));
}

static inline void sdram_writeb(u32 offset, u8 val)
{
	__raw_writeb(val, (void *)(CONFIG_SYS_SDRAM_BASE + offset));
}

static inline void sdram_writew(u32 offset, u16 val)
{
	__raw_writew(val, (void *)(CONFIG_SYS_SDRAM_BASE + offset));
}

static inline void sdram_writel(phys_addr_t offset, u32 val)
{
	__raw_writel(val, (void *)(CONFIG_SYS_SDRAM_BASE + offset));
}

static inline u8 sdram_uc_readb(u32 offset)
{
	return __raw_readb((void *)(CONFIG_SYS_SDRAM_BASE_UC + offset));
}

static inline u16 sdram_uc_readw(u32 offset)
{
	return __raw_readw((void *)(CONFIG_SYS_SDRAM_BASE_UC + offset));
}

static inline u32 sdram_uc_readl(phys_addr_t offset)
{
	return __raw_readl((void *)(CONFIG_SYS_SDRAM_BASE_UC + offset));
}

static inline u8 sdram_readb(u32 offset)
{
	return __raw_readb((void *)(CONFIG_SYS_SDRAM_BASE + offset));
}

static inline u16 sdram_readw(u32 offset)
{
	return __raw_readw((void *)(CONFIG_SYS_SDRAM_BASE + offset));
}

static inline u32 sdram_readl(phys_addr_t offset)
{
	return __raw_readl((void *)(CONFIG_SYS_SDRAM_BASE + offset));
}

static inline void sdram_flush_dcache_line(phys_addr_t offset,
						unsigned long dcache_lsize)
{
	phys_addr_t addr = CONFIG_SYS_SDRAM_BASE + offset;
	flush_dcache_range(addr, addr + dcache_lsize - 1);
}

static inline void cpu_sync(void)
{
	__asm__ __volatile__(			\
		".set	push\n\t"		\
		".set	noreorder\n\t"		\
		".set	mips2\n\t"		\
		"sync\n\t"			\
		".set	pop"			\
		: /* no output */		\
		: /* no input */		\
		: "memory");
}

enum mc_tune_state {
	MC_TUNE_INVALID,
	MC_TUNE_VALID,
	MC_TUNE_VALID_STORED,
};

#define MC_TUNE_MAGIC	0x4d435455

struct mc_tune_cfg {
	u32 magic;
	u32 crc;
	u8 state;
	u8 gate_echo_dll_l;
	u8 gate_echo_dll_u;
	u8 write_dqs_delay_l;
	u8 write_dqs_delay_u;
	u8 read_dqs_delay_l;
	u8 read_dqs_delay_u;
};

static inline struct mc_tune_cfg *mc_tune_data(void)
{
	return (struct mc_tune_cfg *)CONFIG_SPL_MC_TUNE_BASE;
}

void mc_tune_dump(const struct mc_tune_cfg *cfg);
int mc_tune_perform(struct mc_tune_cfg *cfg);
void mc_tune_apply(const struct mc_tune_cfg *cfg);
int mc_tune_check(const struct mc_tune_cfg *cfg);
int mc_tune_load_ram(struct mc_tune_cfg *cfg);
void mc_tune_store_ram(struct mc_tune_cfg *cfg);

#if defined(CONFIG_LTQ_SPL_MC_TUNE)
int mc_tune_store_flash(void);
#else
static inline int mc_tune_store_flash(void)
{
	return 0;
}
#endif

#endif /* __LANTIQ_MEM_H__ */
