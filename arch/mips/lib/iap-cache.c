/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, <wd@denx.de>
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
#include <asm/types.h>
#include <asm/addrspace.h>
#include <asm/mipsregs.h>
#include <asm/cacheops.h>
#include <asm/cpu.h>
#include <linux/types.h>
#include <linux/stringify.h>
#include <linux/kernel.h>
#include <mach/grx500.h>

static inline void instruction_hazard_barrier(void)
{
	unsigned long tmp;

	asm volatile(
	__stringify(la) "\t%0, 1f\n"
	"	jr.hb	%0\n"
	"1:	.insn"
	: "=&r"(tmp));
}

#define sync() asm volatile ("sync" ::: "memory")

#define cache_op(op, addr)				\
	__asm__ __volatile__(				\
		"	.set	push		\n"	\
		"	.set	noreorder	\n"	\
		"	.set	mips3\n\t	\n"	\
		"	cache	%0, %1		\n"	\
		"	.set	pop		\n"	\
		:					\
		: "i"(op), "R"(*(unsigned char *)(addr)))

#define cache_loop(start, end, lsize, ops...) do {			\
	const void *addr = (const void *)(start & ~(lsize - 1));	\
	const void *aend = (const void *)((end - 1) & ~(lsize - 1));	\
	const unsigned int cache_ops[] = { ops };			\
	unsigned int i;							\
									\
	if (!lsize)							\
		break;							\
									\
	for (; addr <= aend; addr += lsize) {				\
		for (i = 0; i < ARRAY_SIZE(cache_ops); i++)		\
			mips_cache(cache_ops[i], addr);			\
	}								\
} while (0)

static unsigned long icache_line_size(void)
{
	const unsigned long conf1 = read_c0_config1();
	const unsigned long line_size = (conf1 & MIPS_CONF1_IL) >> MIPS_CONF1_IL_SHF;

	return line_size ? (2 << line_size) : 0;
}

static unsigned long dcache_line_size(void)
{
	const unsigned long conf1 = read_c0_config1();
	const unsigned long line_size = (conf1 & MIPS_CONF1_DL) >> MIPS_CONF1_DL_SHF;

	return line_size ? (2 << line_size) : 0;
}

static unsigned long scache_line_size(void)
{
	u32 conf2, line_size;

	if (!cpu_is_cps())
		return 0;

	if (!(read_c0_config1() & MIPS_CONF_M))
		return 0;

	conf2 = read_c0_config2();
	line_size = (conf2 & MIPS_CONF2_SL) >> MIPS_CONF2_SL_SHF;

	return line_size ? (2 << line_size) : 0;
}

void flush_cache(ulong start_addr, ulong size)
{
	unsigned long ilsize = icache_line_size();
	unsigned long lsize = dcache_line_size();
	unsigned long slsize = scache_line_size();

	debug("%s: %08lx - %08lx\n", __func__, start_addr, start_addr + size);

	/* aend will be miscalculated when size is zero, so we return here */
	if (size == 0)
		return;

	if ((ilsize == lsize) && !slsize) {
		/* flush I-cache & D-cache simultaneously */
		cache_loop(start_addr, start_addr + size, ilsize,
			   HIT_WRITEBACK_INV_D, HIT_INVALIDATE_I);
		goto ops_done;
	}

	/* flush D-cache */
	cache_loop(start_addr, start_addr + size, lsize, HIT_WRITEBACK_INV_D);

	/* flush L2 cache */
	cache_loop(start_addr, start_addr + size, slsize, HIT_WRITEBACK_INV_SD);

	/* flush I-cache */
	cache_loop(start_addr, start_addr + size, ilsize, HIT_INVALIDATE_I);

ops_done:
	/* ensure cache ops complete before any further memory accesses */
	sync();

	/* ensure the pipeline doesn't contain now-invalid instructions */
	instruction_hazard_barrier();
}

void flush_dcache_range(ulong start_addr, ulong stop)
{
	unsigned long lsize = dcache_line_size();
	unsigned long slsize = scache_line_size();

	debug("%s: %08lx - %08lx\n", __func__, start_addr, stop);

	/* aend will be miscalculated when size is zero, so we return here */
	if (start_addr == stop)
		return;

	cache_loop(start_addr, stop, lsize, HIT_WRITEBACK_INV_D);

	/* flush L2 cache */
	cache_loop(start_addr, stop, slsize, HIT_WRITEBACK_INV_SD);

	/* ensure cache ops complete before any further memory accesses */
	sync();
}

void invalidate_dcache_range(ulong start_addr, ulong stop)
{
	unsigned long lsize = dcache_line_size();
	unsigned long slsize = scache_line_size();

	debug("%s: %08lx - %08lx\n", __func__, start_addr, stop);

	/* aend will be miscalculated when size is zero, so we return here */
	if (start_addr == stop)
		return;

	/* invalidate L2 cache */
	cache_loop(start_addr, stop, slsize, HIT_INVALIDATE_SD);

	cache_loop(start_addr, stop, lsize, HIT_INVALIDATE_D);

	/* ensure cache ops complete before any further memory accesses */
	sync();
}
