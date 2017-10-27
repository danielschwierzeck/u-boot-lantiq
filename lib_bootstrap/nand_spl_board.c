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


#define	TOTAL_MALLOC_LEN	CONFIG_SYS_MALLOC_LEN

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



void uncompress(void)
{
	 ulong   addr;
   ulong   data, len, checksum;
   ulong  *len_ptr;
   unsigned int destLen;
   image_header_t header;
   image_header_t *hdr = &header;
   int (*fn)();
	 
	 mem_malloc_init(0x82000000-TOTAL_MALLOC_LEN, TOTAL_MALLOC_LEN);
	 addr = (char *)(CONFIG_BOOTSTRAP_TEXT_BASE+10240); /*10k bytes for lzma uncompression code*/
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
   

   lzma_inflate ((unsigned char *)data, len, (unsigned char*)ntohl(hdr->ih_load), &destLen);
									
   fn = ntohl(hdr->ih_load);

   (*fn)();

    hang ();   
	
	 return;
}


void hang(void)
{
	
	 for(;;);
}