/*
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
#include <command.h>
//#include <malloc.h>
#include <stdio_dev.h>
#include <timestamp.h>
#include <version.h>
#include <net.h>
#include <environment.h>

#include <lzma/LzmaTypes.h>
#include <lzma/LzmaDec.h>
#include <lzma/LzmaTools.h>


DECLARE_GLOBAL_DATA_PTR;

#define	TOTAL_MALLOC_LEN	CONFIG_SYS_MALLOC_LEN

#undef DEBUG

#define REG32(addr)           *((volatile u32 *)(addr))

extern ulong uboot_end_data;
extern ulong uboot_end;


static ulong mem_malloc_start;
static ulong mem_malloc_end;
static ulong mem_malloc_brk;



/*
 * The Malloc area is immediately below the monitor copy in DRAM
 */
void mem_malloc_init(ulong start, ulong size)
{
	 mem_malloc_end = start + size;
   mem_malloc_start = start;
   mem_malloc_brk = start;

   memset ((void *) mem_malloc_start,
        0,
       mem_malloc_end - mem_malloc_start);
	  
}

void *malloc(unsigned int size)
{
    if(size < (mem_malloc_end - mem_malloc_start))
    {
        mem_malloc_start += size;
        return (void *)(mem_malloc_start - size);
    }
    return NULL;
}

void *realloc(void *src,unsigned int size)
{
    return NULL;
}

void free(void *src)
{
    return;
}

void *sbrk (ptrdiff_t increment)
{
    ulong old = mem_malloc_brk;
    ulong new = old + increment;

    if ((new < mem_malloc_start) || (new > mem_malloc_end)) {
        return (NULL);
    }
    mem_malloc_brk = new;
    return ((void *) old);
}



static int init_func_ram (void)
{
	
	gd->ram_size =(1024*1024*CONFIG_IFX_MEMORY_SIZE);
    return (0);

}


int checkboard (void)
{
     ulong addr, addr_sp;
    
#ifdef CONFIG_TUNE_DDR
  #ifdef CONFIG_BOOT_FROM_NOR
   if(REG32(CONFIG_TUNING_STATUS)==0x0 ||REG32(CONFIG_TUNING_STATUS)==0x1 || REG32(CONFIG_TUNING_STATUS)==0x2){
       return 0; /*already tuned, return*/
    }
   else{
   /*not tuned, ddr need to be tuned*/
   addr_sp=CONFIG_TUNING_SP;
   addr=CONFIG_DDR_TUNING_TEXT_BASE;
   relocate_code (addr_sp, 0, addr);
  }
 #endif
#endif

     return 0;
}


/*
 * Breath some life into the board...
 *
 * The first part of initialization is running from Flash memory;
 * its main purpose is to initialize the RAM so that we
 * can relocate the monitor code to RAM.
 */

/*
 * All attempts to come up with a "common" initialization sequence
 * that works for all boards and architectures failed: some of the
 * requirements are just _too_ different. To get rid of the resulting
 * mess of board dependend #ifdef'ed code we now make the whole
 * initialization sequence configurable to the user.
 *
 * The requirements for any new initalization function is simple: it
 * receives a pointer to the "global data" structure as it's only
 * argument, and returns an integer return code, where 0 means
 * "continue" and != 0 means "fatal error, hang the system".
 */
typedef int (init_fnc_t) (void);

init_fnc_t *init_sequence[] = {
	init_func_ram,
	checkboard,
	NULL,
};


void board_init_f(ulong bootflag)
{
	gd_t gd_data, *id;
	bd_t *bd;
	init_fnc_t **init_fnc_ptr;
	ulong addr, addr_sp, len = (ulong)&uboot_end - CONFIG_BOOTSTRAP_TEXT_BASE;
	ulong *s;

	/* Pointer is writable since we allocated a register for it.
	 */
	gd = &gd_data;
	/* compiler optimization barrier needed for GCC >= 3.4 */
	__asm__ __volatile__("": : :"memory");

	memset ((void *)gd, 0, sizeof (gd_t));

	for (init_fnc_ptr = init_sequence; *init_fnc_ptr; ++init_fnc_ptr) {
		if ((*init_fnc_ptr)() != 0) {
			hang();
		}
	}

	/*
	 * Now that we have DRAM mapped and working, we can
	 * relocate the code and continue running from DRAM.
	 */
	addr = CONFIG_SYS_SDRAM_BASE + gd->ram_size;

	/* We can reserve some RAM "on top" here.
	 */

	/* round down to next 4 kB limit.
	 */
	addr &= ~(4096 - 1);
	debug ("Top of RAM usable for U-Boot at: %08lx\n", addr);

	/* Reserve memory for U-Boot code, data & bss
	 * round down to next 64 kB limit
	 */
	addr -= len;
	addr &= ~(64 * 1024 - 1);
    
	debug ("Reserving %ldk for U-Boot at: %08lx\n", len >> 10, addr);

	 /* Reserve memory for malloc() arena.
	 */
	addr_sp = addr - TOTAL_MALLOC_LEN;
	debug ("Reserving %dk for malloc() at: %08lx\n",
			TOTAL_MALLOC_LEN >> 10, addr_sp);

	/*
	 * (permanently) allocate a Board Info struct
	 * and a permanent copy of the "global" data
	 */
	addr_sp -= sizeof(bd_t);
	bd = (bd_t *)addr_sp;
	gd->bd = bd;
	debug ("Reserving %zu Bytes for Board Info at: %08lx\n",
			sizeof(bd_t), addr_sp);

	addr_sp -= sizeof(gd_t);
	id = (gd_t *)addr_sp;
	debug ("Reserving %zu Bytes for Global Data at: %08lx\n",
			sizeof (gd_t), addr_sp);

	/* Reserve memory for boot params.
	 */
	addr_sp -= CONFIG_SYS_BOOTPARAMS_LEN;
	bd->bi_boot_params = addr_sp;
	debug ("Reserving %dk for boot params() at: %08lx\n",
			CONFIG_SYS_BOOTPARAMS_LEN >> 10, addr_sp);

	/*
	 * Finally, we set up a new (bigger) stack.
	 *
	 * Leave some safety gap for SP, force alignment on 16 byte boundary
	 * Clear initial stack frame
	 */
	addr_sp -= 16;
	addr_sp &= ~0xF;
	s = (ulong *)addr_sp;
	*s-- = 0;
	*s-- = 0;
	addr_sp = (ulong)s;
	debug ("Stack Pointer at: %08lx\n", addr_sp);

	/*
	 * Save local variables to board info struct
	 */
	bd->bi_memstart	= CONFIG_SYS_SDRAM_BASE;	/* start of  DRAM memory */
	bd->bi_memsize	= gd->ram_size;		/* size  of  DRAM memory in bytes */
	bd->bi_baudrate	= gd->baudrate;		/* Console Baudrate */

	memcpy (id, (void *)gd, sizeof (gd_t));

	relocate_code (addr_sp, id, addr);

	/* NOTREACHED - relocate_code() does not return */
}
/************************************************************************
 *
 * This is the next part if the initialization sequence: we are now
 * running from RAM and have a "normal" C environment, i. e. global
 * data can be written, BSS has been cleared, the stack size in not
 * that critical any more, etc.
 *
 ************************************************************************
 */

void board_init_r (gd_t *id, ulong dest_addr)
{
	 ulong   addr;
   ulong   data, len, checksum;
   ulong  *len_ptr;
   unsigned int destLen;
   image_header_t header;
   image_header_t *hdr = &header;
   int (*fn)();
	 
	 mem_malloc_init(dest_addr-TOTAL_MALLOC_LEN, TOTAL_MALLOC_LEN);
	 addr = (char *)(CONFIG_BOOTSTRAP_TEXT_BASE + ((ulong)&uboot_end_data - dest_addr));
   memmove (&header, (char *)addr, sizeof(image_header_t));
   
	 if (ntohl(hdr->ih_magic) != IH_MAGIC) {
        return;
    }

   data = (ulong)&header;
   len  = sizeof(image_header_t);

   checksum = ntohl(hdr->ih_hcrc);
   hdr->ih_hcrc = 0;
   asm("sync");
   if (crc32 (0, (char *)data, len) != checksum) {
        return;
    }

   asm("sync");

   data = addr + sizeof(image_header_t);

   asm("sync");

   len  = ntohl(hdr->ih_size);
   asm("sync");

   len_ptr = (ulong *)data;
   asm("sync");

   destLen = 0x0; 
   
/*    
   int ret = lzmaBuffToBuffDecompress(
                    (char*)ntohl(hdr->ih_load),
                    &destLen, (char *)data, len);
*/
   lzma_inflate ((unsigned char *)data, len, (unsigned char*)ntohl(hdr->ih_load), &destLen);
									
   fn = ntohl(hdr->ih_load);

   (*fn)();

    hang ();
	
						   
}


void hang(void)
{
	
	 for(;;);
}
