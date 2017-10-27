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
#include <asm/addrspace.h>
#include <asm/yamon.h>
#include <asm/types.h>
#include <asm/mipsregs.h>
#include <asm/cacheops.h>
#include <asm/cpu.h>

typedef unsigned long ulong;

#define cache_op(op,addr)						\
	__asm__ __volatile__(						\
	"	.set	push					\n"	\
	"	.set	noreorder				\n"	\
	"	.set	mips3\n\t				\n"	\
	"	cache	%0, %1					\n"	\
	"	.set	pop					\n"	\
	:								\
	: "i" (op), "R" (*(unsigned char *)(addr)))

u32 get_cpu_id()
{  
   u32 config = read_c0_prid();
   return ((config>>8) & 0xff);

}

u32 icache_lines()
{
   /* I-cache lines
    * Calculated as associativity * sets per way
	*/

   u32 config,associativity,sets;
   config = read_c0_config1();
   associativity = 1+ ((config & M_Config1IA) >> S_Config1IA);
   sets = (1<<((config & M_Config1IS) >> S_Config1IS)) * 64;
   return (associativity * sets);
}

u32 icache_line_size()
{
    u32 config, line_size;
    config=read_c0_config1();
    line_size= 0x02 <<((config & M_Config1IL) >> (S_Config1IL));
    return line_size;
}
									  

u32 dcache_lines()
{
   /* I-cache lines
    * Calculated as associativity * sets per way
	*/

   u32 config,associativity,sets;
   config = read_c0_config1();
   associativity = 1+ ((config & M_Config1DA) >> S_Config1DA);
   sets = (1<<((config & M_Config1DS) >> S_Config1DS)) * 64;
   return (associativity * sets);
}

u32 dcache_line_size()
{
    u32 config, line_size;
    config=read_c0_config1();
    line_size= 0x02 <<((config & M_Config1DL) >> (S_Config1DL));
    return line_size;
}
										  
u32 scache_lines() 
{
    u32 config, config2, associativity, sets, tmp;
	u32 cpu_id = get_cpu_id();

    if (cpu_id == CPU_4KEC)
        return 0;
 
	/* check the existance of config2 */
    config = read_c0_config1();
    if (!(config & MIPS_CONF_M)) 
        return 0;

    config2 = read_c0_config2();
    /* check if L2 cache is activated */
    if (!(config2 & (1 << 12)))
        return 0;

    tmp = (config2 >> 8) & 0x0f;
    if (0 <= tmp && tmp <= 9)
        sets = 64 << tmp;
    else
        return 0;

    tmp = (config2 >> 0) & 0x0f;
    if (0 <= tmp && tmp <= 7)
        associativity = tmp + 1;
    else
        return 0;

     return associativity * sets;
    
}

u32 scache_linesize()
{
    u32 config, config2, linesize;
	u32 cpu_id = get_cpu_id();
	u32 tmp;

    if (cpu_id == CPU_4KEC)
        return 0;

	/* check the existance of config2 reg */ 
    config = read_c0_config1();
    if (!(config & MIPS_CONF_M)) 
        return 0;

    config2 = read_c0_config2();
    tmp = (config2 >> 4) & 0x0f;
    if (0 < tmp && tmp <= 7)
        linesize = 2 << tmp;
    else 
        return 0;
    
    return linesize; 
}


void init_icache()
{
    u32 lsize = icache_line_size();
    u32 start_addr  = KSEG0;
	u32 aend  = KSEG0  + (icache_lines()*lsize);
	u32 cpu_id = get_cpu_id();    
    u32 addr;
 
	write_c0_taglo(0); 
	//write_c0_taghi(0); /*not applicable to 4kec, 24kec and 34kc, will add if it is needed in the future*/
    for(addr=start_addr;addr<aend; addr+=lsize){
        cache_op(Index_Store_Tag_I, addr);
	}
}


void lock_icache()
{
    u32 lsize = icache_line_size();
    u32 start_addr  = 0x9fc00000;
    u32 aend  = 0x9fc00000 + (icache_lines()*lsize);
    u32 cpu_id = get_cpu_id();
    u32 addr;

    for(addr=start_addr;addr<=aend; addr+=lsize){
	       cache_op(ICACHE_ADDR_FETCH_LOCK, addr);
      }
}

void init_dcache()
{
     u32 lsize = dcache_line_size();
	 u32 start_addr  = 0x9fc00000;
	 u32 aend  = 0x9fc00000 + (dcache_lines()*lsize);
	 u32 cpu_id = get_cpu_id();
	 u32 addr;

     write_c0_dtaglo(0);
    //write_c0_taghi(0); /*not applicable to 4kec, 24kec and 34kc, will add if it is needed in the future*/
    for(addr=start_addr;addr<aend; addr+=lsize){
        cache_op(Index_Store_Tag_D, addr);
     }
}

void lock_dcache()
{
    u32 lsize = dcache_line_size();
    u32 start_addr  = 0x9fc00000;
    u32 aend  = 0x9fc00000 + (dcache_lines()*lsize);
    u32 cpu_id = get_cpu_id();
    u32 addr;

    for(addr=start_addr;addr<=aend; addr+=lsize){
    	cache_op(DCACHE_ADDR_FETCH_LOCK, addr);
	}
}
								 
void init_scache()
{
	u32 cpu_id = get_cpu_id();    
    u32 lsize = scache_linesize();
    u32 start_addr = 0x80000000;
    u32 aend = 0x80000000 + (scache_lines() * lsize);
	u32 addr;

    if (cpu_id == CPU_4KEC)
        return;

    write_c0_staglo(0);
    for (addr = start_addr; addr < aend; addr += lsize)
        cache_op(Index_Store_Tag_SD, addr);

}

void flush_cache(ulong start_addr, ulong size)
{
	unsigned long lsize = dcache_line_size();
	unsigned long addr = start_addr & ~(lsize - 1);
	unsigned long aend = (start_addr + size - 1) & ~(lsize - 1);
	u32 cpu_id = get_cpu_id();    

	while (1) {
		if (cpu_id == CPU_INTERAPTIV) 
			cache_op(Hit_Writeback_Inv_SD, addr);
		cache_op(Hit_Writeback_Inv_D, addr);
		cache_op(Hit_Invalidate_I, addr);
		if (addr == aend)
			break;
		addr += lsize;
	}
}

void flush_dcache_range(ulong start_addr, ulong stop)
{
	unsigned long lsize = dcache_line_size();
	unsigned long addr = start_addr & ~(lsize - 1);
	unsigned long aend = (stop - 1) & ~(lsize - 1);

	while (1) {
		cache_op(Hit_Writeback_Inv_D, addr);
		if (addr == aend)
			break;
		addr += lsize;
	}
}

void flush_scache_range(ulong start_addr, ulong stop)
{
	unsigned long lsize = scache_linesize();
	unsigned long addr = start_addr & ~(lsize - 1);
	unsigned long aend = (stop - 1) & ~(lsize - 1);
	u32 cpu_id = get_cpu_id();    

	if (cpu_id == CPU_4KEC)
		return;

	while (1) {
		cache_op(Hit_Writeback_Inv_SD, addr);
		if (addr == aend)
			break;
		addr += lsize;
	}
}

void invalidate_dcache_range(ulong start_addr, ulong stop)
{
	unsigned long lsize = dcache_line_size();
	unsigned long addr = start_addr & ~(lsize - 1);
	unsigned long aend = (stop - 1) & ~(lsize - 1);

	while (1) {
		cache_op(Hit_Invalidate_D, addr);
		if (addr == aend)
			break;
		addr += lsize;
	}
}

void invalidate_scache_range(ulong start_addr, ulong stop)
{
	unsigned long lsize = scache_linesize();
	unsigned long addr = start_addr & ~(lsize - 1);
	unsigned long aend = (stop - 1) & ~(lsize - 1);
	u32 cpu_id = get_cpu_id();    
	
	if (cpu_id == CPU_4KEC)
		return;

	while (1) {
		cache_op(Hit_Invalidate_SD, addr);
		if (addr == aend)
			break;
		addr += lsize;
	}
}

void write_one_tlb(int index, u32 pagemask, u32 hi, u32 low0, u32 low1)
{
	write_c0_entrylo0(low0);
	write_c0_pagemask(pagemask);
	write_c0_entrylo1(low1);
	write_c0_entryhi(hi);
	write_c0_index(index);
	tlb_write_indexed();
}

