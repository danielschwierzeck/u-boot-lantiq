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
#include <netdev.h>
#include <asm/mipsregs.h>
#include <mach/grx500.h>
#include <mach/api.h>

DECLARE_GLOBAL_DATA_PTR;

void _machine_restart(void)
{
	REG32(0xb6000010) |= 0x40000000;
}

phys_size_t initdram(int board_type)
{
	unsigned int mem_size = 128;

	if (cpu_is_cps()) {
		mem_size = CONFIG_LANTIQ_DDR_DENSITY_SIZE *
			CONFIG_LANTIQ_DDR_RANKS;

#if 0
		/* reserve and hide memory at the end for boot core */
		mem_size -= CONFIG_LANTIQ_MEMSIZE_BOOTCORE;
#endif
	}

	return mem_size * 1024 * 1024;
}

ulong board_get_usable_ram_top(ulong total_size)
{
	const phys_size_t ram_size_max = 256 * 1024 * 1024;
	ulong ram_top = CONFIG_SYS_SDRAM_BASE;

	if (gd->ram_size > ram_size_max)
		ram_top += ram_size_max;
	else
		ram_top += gd->ram_size;

	return ram_top;
}

#if defined(CONFIG_XRX500_ETH)
int cpu_eth_init(bd_t *bis)
{
	return grx500_eth_initialize(bis);
}
#endif

ulong notrace __weak get_tbclk(void)
{
	return (CONFIG_LANTIQ_CPU_CLK / 2) * 1000 * 1000;
}

int checkboard(void)
{
	if (cpu_is_cps())
		puts("CPU:   InterAptiv\n");
	else
		puts("CPU:   Boot core\n");

#if defined(CONFIG_BOARD_NAME)
	puts("Board: " CONFIG_BOARD_NAME "\n");
#endif

	return 0;
}

int misc_init_r(void)
{
	setenv_hex("bootm_size", 128 * 1024 * 1024);
	setenv_hex("bootm_low", 0xa0000000);

	return 0;
}
