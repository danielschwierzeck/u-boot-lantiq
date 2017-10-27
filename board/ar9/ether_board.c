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
#include <version.h>
#include <environment.h>


DECLARE_GLOBAL_DATA_PTR;


/*
 * Begin and End of memory area for malloc(), and current "brk"
 */

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

void * calloc(
    size_t nelem,
    size_t size)
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


static int init_baudrate (void)
{

	gd->baudrate = CONFIG_BAUDRATE;

	return (0);
}

								

void ether_board_init(void)
{

   gd_t gd_data, *id;
   bd_t *bd;
   ulong *s;
   int i;
   volatile u32 *addr = (volatile u32 *)0xa0100000;
   volatile u8* src=0xbfc00000;
   volatile u8* dst=0xa0100000;
   volatile u16* p=0xa0100000;
   serial_init();
	 
   asm("sync");
   
   mem_malloc_init(0xbe1a4000-0x400, 0x400); /*reserve 1k byte space*/
	 
   
   asm("sync");
   tune_ddr();
   for(i=0;i<16384;i++){
    	*dst=*src;
    	dst++;
    	src++;
    }
    
   for(i=0;i<16384/2;i++){
     if(*p==0xbfc0)*p=0xa010;
     p++;
   }
  
  
   addr=(volatile u32 *)0xa0104000;
   addr[0]=0x240f0000;
   addr[1]=0x24180001;
   addr[2]=0x3c190003;
   addr[3]=0x3739fff0;
   addr[4]=0x15f9ffff;
   addr[5]=0x01f87821;
  
   src=0xa01039fc;
   dst=0xa0104018;
    
   for(i=0;i<20;i++){
    	*dst=*src;
    	dst++;
    	src++;
    }
   
   addr=(volatile u32 *)0xa010402C;
   addr[0]=0x3c1aa010;
   addr[1]=0x375a3a10;
   addr[2]=0x03400008;
   addr[3]=0x00000000;
   
   addr=(volatile u32 *)0xa01039fc;
   addr[0]=0x3c1aa010;
   addr[1]=0x375a4000;
   addr[2]=0x03400008;
   addr[3]=0x00000000;

#if 1
   /*fix checksum problem*/
   addr=(volatile u32 *)0xa01028e8;
   addr[0]=0x3c0fa040;
   addr[1]=0x01e00008;
   addr[2]=0x00000000;
#endif
    return;  

}
