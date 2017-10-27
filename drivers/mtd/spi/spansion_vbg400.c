/*
 * Copyright (C) 2009 Freescale Semiconductor, Inc.
 *
 * Author: Mingkai Hu (Mingkai.hu@freescale.com)
 * Based on stmicro.c by Wolfgang Denk (wd@denx.de),
 * TsiChung Liew (Tsi-Chung.Liew@freescale.com),
 * and  Jason McMullan (mcmullan@netapp.com)
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <malloc.h>
#include <spi_flash.h>

#include "spi_flash_internal.h"

//#define VBG400_TEST_WRITE

//#define VBG400_DEBUG_SPI
#ifdef VBG400_DEBUG_SPI
#define printf_spi(fmt, args...) do { printf("%s(): ", __func__); printf(fmt, ##args); } while (0)
#else
#define printf_spi(fmt, args...)
#endif

//extern flash_info_t	flash_info[CFG_MAX_FLASH_BANKS]; /* info for FLASH chips	*/

unsigned long start_sect[CONFIG_SYS_MAX_FLASH_SECT];   /* virtual sector start address */

unsigned char ManufacturerId;
unsigned char MemoryType;
unsigned char MemoryCapacity;

#define FLASH_MAN_S25FL064A 0x00000001
#define FLASH_BLOCK_SIZE    0x00010000

/*flash commands/data*/
#define WR_DUMMY        0x0
#define CMD_WR          0x02	/* Page Program */
#define CMD_RD          0x03	/* Read Data Bytes */
#define CMD_WR_DISABLE  0x04	/* Write Disable */
#define CMD_RDSR        0x05	/* Read Status Register */
#define CMD_WR_ENABLE   0x06	/* Write Enable */
#define CMD_RD_CHIP_ID  0x9F    /* Read chip ID */
#define CMD_SECT_ERASE  0xD8	/* Sector Erase */
#define SET_NEW_WR_CYCLE    0x0100
/*other commands:
#define CMD_WRSR        0x01	- Write Status Register
#define CMD_FAST_READ   0x0b	- Read Data Bytes at Higher Speed
#define CMD_READID      0x90    - Read Manufacture ID and Device ID
#define CMD_RES         0xab    - Release from DP, and Read Signature
#define CMD_DP          0xb9    - Deep Power-down
#define CMD_BULK_ERASE  0xC7    - Bulk erase
*/

static void wait_ready(void);
static unsigned int* vbg400SpiReadAddr = (unsigned int*)VBG400_SPI_READ_ADDR;
static unsigned int* vbg400SpiWriteAddr = (unsigned int*)VBG400_SPI_WR_ADDR;

#define VBG400_FLASH_WAIT_MTD \
for (k=0; k<500; k++) {;}

#define VBG400_FLASH_WAIT_LONG_MTD \
for (k=0; k<500; k++) {;}

#define WRITE_FLASH_MTD(x) \
    *vbg400SpiWriteAddr = x; \
    wait_ready();


#define SPSN_ID_S25FL008A	0x0213
#define SPSN_ID_S25FL016A	0x0214
#define SPSN_ID_S25FL032A	0x0215
#define SPSN_ID_S25FL064A	0x0216
#define MX_ID_MX25L6406E	0x2017
#define SPSN_ID_S25FL128P	0x2018
#define SPSN_EXT_ID_S25FL128P_256KB	0x0300
#define SPSN_EXT_ID_S25FL128P_64KB	0x0301

#define SPANSION_SR_WIP		(1 << 0)	/* Write-in-Progress */

struct spansion_spi_flash_params {
	u16 idcode1;
	u16 idcode2;
	u16 page_size;
	u16 pages_per_sector;
	u16 nr_sectors;
	const char *name;
};

struct spansion_spi_flash {
	struct spi_flash flash;
	const struct spansion_spi_flash_params *params;
};

#define VBG400_DUMMY_COMPILATION
#ifdef VBG400_DUMMY_COMPILATION
/* DUummy - to compile lq_spi.c */
int spi_gpio_init(unsigned int cs)
{
return 0;
}

//#define F_SSC_CLK  5
#endif

static inline struct spansion_spi_flash *to_spansion_spi_flash(struct spi_flash
							     *flash)
{
	return container_of(flash, struct spansion_spi_flash, flash);
}

static const struct spansion_spi_flash_params spansion_spi_flash_table[] = {
	{
		.idcode1 = SPSN_ID_S25FL064A,
		.idcode2 = 0,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 128,
		.name = "S25FL064A",
	},
	{
		.idcode1 = MX_ID_MX25L6406E,
		.idcode2 = 0,
		.page_size = 256,
		.pages_per_sector = 256,
		.nr_sectors = 128,
		.name = "MX25L6406E",
	},
};

//#define VBG400_VLSI_BUSY_BIT_BUG    
static void wait_ready(void)
{
    int i=0;
    
#ifdef VBG400_VLSI_BUSY_BIT_BUG    
    __udelay(10000);
#endif    
    while (((*vbg400SpiReadAddr) & 0x0100) == 0x0) {
        // VBG400_FLASH_WAIT_MTD;
        if (i > /*255*/500) {
            printf("timeout in wait_ready\n");
            return;
        }
        i++;
    }
}

//#define VBG400_TIMER_SET_MILI

/* TODO: Add T.O and error when occur
*/
static int read_status_ready(unsigned long timeout)
{
	int ret = -1;
    unsigned int val;
#ifdef VBG400_TIMER_SET_MILI
	unsigned long timebase;
    
	timebase = get_timer(0);
	do {
#else
redo:
#endif
        WRITE_FLASH_MTD(CMD_RDSR);
        WRITE_FLASH_MTD(WR_DUMMY);
        val = *vbg400SpiReadAddr;
        WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
#ifdef VBG400_TIMER_SET_MILI
        /*1 = Device Busy. A Write Status Register, program, or erase operation is in progress*/
        if (((0xFF & val) & 0x01) == 0x0)
          	ret = 0;
#else
        if (((0xFF & val) & 0x01) == 0x01)
         	goto redo;
        ret = 0;
#endif
#ifdef VBG400_TIMER_SET_MILI
	} while ((get_timer(timebase) < timeout) && (ret != 0));
#endif
    return ret;
}


size_t get_data_from_flash(u32 *src, size_t *cnt, void **addr, ulong src_end)
{
    ulong mode_reg;
    size_t cnt_tmp = *cnt;
    int inc = 0;
    int i;

    printf_spi("cnt_tmp = 0x%08x, *addr = 0x%08x, *src = 0x%lx, src_end = 0x%lx\n",cnt_tmp, *addr, *src, src_end);

    if ((src_end >= VBG400_SPI_PAGE_END) && (*src < VBG400_SPI_PAGE_END))
    {
        /*page swap on operation required*/
        printf_spi("page swap on operation required\n");
	    cnt_tmp = VBG400_SPI_PAGE_END - *src;
        printf_spi("new cnt_tmp = 0x%08x, \n",cnt_tmp);
    } else if (*src >= VBG400_SPI_PAGE_END)
    {
        /*page 1 required*/
        printf_spi("page 1 required, inc=%d\n",inc);
        inc++;
	    mode_reg = *(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) & VBG400_SPI_MODE_CLEAR_PAGE_BITS;
	    *(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) = (inc<<VBG400_SPI_MODE_SHIFT_PAGE_BITS) | mode_reg;
	     *src = CFG_FLASH_BASE_HW + (*src & 0x00FFFFFF);
        printf_spi("page 1 required, reg = 0x%x\n",*(volatile unsigned long *)(VBG400_SPI_MODE_ADDR));
        printf_spi("new src = 0x%08x\n",*src);
    }
	for (i=0; i<(cnt_tmp/4); i++) {
	    /*copy from flash*/
	    **((ulong **)addr) = **((ulong **)src);
	    if (i < 12)
            printf_spi("val = 0x%08x\n",(u32)(**((ulong **)addr)));
	    *addr = (uchar*)*addr+4;
	    *src = *src + 4;
	}
    *cnt = *cnt - cnt_tmp;

	return *cnt;
}

 /*
 * Copy memory from flash to mem, returns:
 * params:
 * src - address in flash
 * addr - ptr to memory
 * return:
 * 0 - OK
 * !0 - error
 */
static int spansion_read_fast (struct spi_flash *flash, u32 src, size_t cnt, void *addr)
{
    int res=0;
    //unsigned long tomem;    
    ulong ubootaddr;    
    int useSw = 0;
    ulong mode_reg;
    ulong src_end;
    //static int page_change=1;
//    flash_info_t *info = &flash_info[0];
    
    printf_spi("in spansion_read_fast, src = 0x%08x, addr = 0x%08x, cnt = %ld\n",(u32)src,(u32)addr,(long)cnt);
    if (src > IFX_CFG_FLASH_END_ADDR) {
        printf("spansion_read_fast Error - 0x%08x is not address in flash\n",(u32)src);
        return 1;
    }
	
    if ((src & 0x00000003) || (cnt & 0x00000003)) {/*use SW mode if not aligned to 4 address given on command, else SW mode.
                            example of HW: "dbgread 12 0x00000002",
                            example of SW: "dbgread 12" or "dbgread 12 0x00000000"*/
        useSw = 1;
        printf_spi("set useSw\n");
        printf_spi("SW MODE READ\n");
	}
	else {
	    /* Configure FLASH to be in HW mode */
	    ubootaddr = (*(volatile unsigned long *)(VBG400_SPI_MODE_ADDR)) ;
        printf_spi("HW MODE READ\n");
        printf_spi("ubootaddr before= 0x%08lx\n",ubootaddr);
	    ubootaddr &= (~VBG400_SPI_MODE_SW_BIT);
        printf_spi("ubootaddr = 0x%08lx\n",ubootaddr);
	    *(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) = ubootaddr;
    }
    if (useSw==0) {
        //printf_spi("src before = 0x%08lx\n",src);
        printf_spi("src before = 0x%08x\n",src);
        src &= 0x00FFFFFF;
        printf_spi("src mid = 0x%08x\n",src);
        src += CFG_FLASH_BASE_HW;
        printf_spi("src end = 0x%08x\n",src);
        src_end = cnt+src;
        //cnt = cnt/4;
        /*
        * in HW mode flash
        * ! assuming flash max size 8M
        */
    printf_spi("call get_data_from_flash: cnt = 0x%08x, src_end = 0x%08x\n",cnt, src_end);
    while (cnt > 0)
    {
        printf_spi("in loop: addr = 0x%08x\n",(u32)(addr));
        cnt = get_data_from_flash(&src, &cnt, &addr, src_end);
        printf_spi("ret get_data_from_flash: cnt = 0x%08x, addr = 0x%08x\n",cnt,(u32)(addr));
    }
    
    }

    if (useSw==0) {
	    /* Configure FLASH to be in Software mode */
	    *(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) |= VBG400_SPI_MODE_SW_BIT;
        /*clear page field*/
		mode_reg = *(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) & VBG400_SPI_MODE_CLEAR_PAGE_BITS;
		*(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) = mode_reg | mode_reg;
        printf_spi("clear page field: reg = 0x%08x\n",(u32)*(volatile unsigned long *)(VBG400_SPI_MODE_ADDR));
    }
    printf_spi("end\n");

    return (res);
}

#define VBG400_VERIFY_WRITE

#define VBG400_PARTIAL_SUPPORT

/*-----------------------------------------------------------------------
 * Copy memory to flash, returns:
 * params:
 * src - ptr to memory
 * addr - address in flash
 * 0 - OK
 * !0 - write timeout
 */
static int spansion_write (struct spi_flash *flash, u32 addr, size_t cnt, const void *src)
{
    int res=0;
    ulong i;
    //uchar data;
#if 0
    unsigned int val;
#endif
#ifdef VBG400_VERIFY_WRITE
    ulong checksum_src = 0;
    ulong checksum_flash = 0;
    ulong addr_in_flash = 0;
    ulong addr_in_cnt = 0;
    int print = 0;
#endif
    //unsigned char val1;
    //ulong addr_ref;
//    flash_info_t *info = &flash_info[0];

#ifdef VBG400_TEST_WRITE
    printf("in spansion_write: src = 0x%08lx, addr = 0x%08lx, cnt = %ld\n",(ulong)src,(ulong)addr,(long)cnt);
    for (i=0;i<10;i++) {
      printf("*src=0x%x ",*((uchar*)src+i));
    }
    printf("spansion_write: VBG400_TEST_WRITE- skip write\n");
    return res;
#endif
	/* write to the flash */
    /*write handling:============================
    */
	addr = addr&0x00FFFFFF;
#ifdef VBG400_VERIFY_WRITE
	addr_in_flash = addr;
	addr_in_cnt   = cnt;
#endif
	cnt +=addr;
    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
    printf_spi("addr = 0x%08x, src = 0x%08lx\n",addr,(ulong)((uchar*)src));
    printf_spi("\n ");
    printf("! Please wait (may take some minutes)\n ");
    //addr_ref = addr +50;
    do {
        WRITE_FLASH_MTD(CMD_WR_ENABLE);
        WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
        WRITE_FLASH_MTD(CMD_WR);
        WRITE_FLASH_MTD((addr>>16)&0xFF);
        WRITE_FLASH_MTD((addr>>8)&0xFF);
        WRITE_FLASH_MTD(addr&0xFF);
        for (i = addr;	i < cnt; i++,addr++,(uchar*)src++) {
            //data = *(uchar*)src;
            //printf("i = %d, data = 0x%x. ",i,data);
#ifdef VBG400_VERIFY_WRITE
            checksum_src ^= *(uchar*)src;
            //printf("new page,i = %d, addr = 0x%08lx, checksum_src = 0x%08lx. \n",i,addr,checksum_src);
#endif
            //if (i<addr_ref) {
            //    val1 = *(uchar*)src;
            //    printf("i = %d, val = 0x%x\n",i,val1);
            //}
            WRITE_FLASH_MTD(*(uchar*)src);
            if ((i != 0 ) && ((i&0xFF) == 0xFF)) {
                addr+=1;
                //(uchar*)src+=1;
                src = (uchar*)src+1;
                //printf("new page,i = %d, addr = 0x%08lx, src = 0x%08lx. \n",i,addr,(uchar*)src);
                break;
            }
        }
        /*Write "1" in order to negate CS at tne end
          of the transaction:                       */
        WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
        if(read_status_ready(SPI_FLASH_PROG_TIMEOUT) != 0) {
	        printf ("spansion_write: ERR_TIMOUT\n");
            res = -1;
        }
        //VBG400_FLASH_WAIT_LONG_MTD
    } while (i < cnt);
    printf_spi("last page, i = %lu, addr = 0x%08x, src = 0x%p \n",i,addr,(uchar*)src);

#ifdef VBG400_VERIFY_WRITE
    printf("verify read, addr_in_flash = 0x%08lx, addr_in_ddr = 0x%08lx\n",addr_in_flash,addr_in_cnt);
    printf("please wait...\n");
    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
    WRITE_FLASH_MTD(CMD_RD);
    WRITE_FLASH_MTD((addr_in_flash>>16)&0xFF);
    WRITE_FLASH_MTD((addr_in_flash>>8)&0xFF);
    WRITE_FLASH_MTD(addr_in_flash&0xFF);

    for (i=0; i<addr_in_cnt; i++) {
        WRITE_FLASH_MTD(WR_DUMMY);
#if 0 //for debug
        val = *vbg400SpiReadAddr;
        checksum_flash ^= val;
        printf("i = %d, val = 0x%x, checksum_flash = 0x%08lx\n",i,(unsigned char)val,checksum_flash);
#else
        checksum_flash ^= *vbg400SpiReadAddr;
#endif
        print++;
        if (print == 0x500) {
            printf(".");
            print = 0;
        }
    }
    printf("\n");
    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
    printf_spi("checksum_src = 0x%08lx, checksum_flash = 0x%08lx\n",checksum_src,checksum_flash);
    if (checksum_src == checksum_flash) {
      printf("verify read is ok :-) \n");
    }
    else {
      res = -1/*ERR_PROG_ERROR*/;
      printf("error in verify read :-( \n");
    }
#endif

    printf_spi("status ready\n");

    return (res);
}

#ifdef VBG400_PARTIAL_SUPPORT
/*-----------------------------------------------------------------------
 * Copy memory to flash, returns:
 * params:
 * buf - ptr to memory
 * offset - address in flash
 * 0 - OK
 * !0 - write timeout
 */
static int spansion_write_partial(struct spi_flash *flash, u32 offset, size_t len, const void *buf)
{
        int ret;
        struct spansion_spi_flash *spsn_tmp = to_spansion_spi_flash(flash);
        unsigned long byte_addr;
        unsigned long sect_addr;
        unsigned long sector_size;
        unsigned char *sect_buf = NULL;
        int f_start_partial=0;
        int f_end_partial=0;
        int f_malloc=0;
        int total_sect_num=0;    
            
        int i;

	    printf_spi("spansion_write_partial: virtual offset = 0x%08x, len = 0x%08x\n",offset,len);
	    
	    sector_size = spsn_tmp->params->page_size * spsn_tmp->params->pages_per_sector;
	    printf_spi("sector_size = 0x%08lx\n",sector_size);
        
        byte_addr = offset % spsn_tmp->params->page_size;
	    printf_spi("byte_addr = 0x%08lx\n",byte_addr);
        
        if( (offset % sector_size)!=0 ) f_start_partial = 1;
        if( ( (offset + len ) % sector_size)!=0 ) f_end_partial = 1;
        printf_spi("f_start_partial=%d,f_end_partial=%d\n",f_start_partial,f_end_partial);
        
        total_sect_num = (offset + len -1) / sector_size - offset / sector_size + 1; 
        printf_spi("total_sect_num=%d\n",total_sect_num);
           
        sect_addr = offset / sector_size;         
        sect_buf = (unsigned char *)buf;
	    printf_spi("sect_addr = 0x%08lx, sect_buf = 0x%p\n",sect_addr,sect_buf);
        
        for(i=0; i<total_sect_num; i++){
             if((f_start_partial && i==0) || (f_end_partial && total_sect_num ==1)) {
                 printf_spi("f_start_partial ....\n");
                 sect_buf=0;
                 //sect_buf = malloc(sizeof(sector_size));
                 sect_buf=(uchar *)calloc(sector_size, sizeof(char));
                 if(!sect_buf) {
                    printf("cannot allocate memory!\n");
                    ret = -1;
                    break;
                  }
                 spsn_tmp->flash.read(flash, ((sect_addr + i) * sector_size), sector_size, sect_buf);
                 memcpy(sect_buf + (offset % sector_size), buf, \
                        min((sector_size-(offset % sector_size)),len));
                 f_malloc = 1;
                 
              }else if(f_end_partial && i == total_sect_num -1 && i!=0){
                 printf_spi("f_end_partial....\n");
                 //sect_buf = malloc(sizeof(sector_size));
                 sect_buf=(uchar *)calloc(sector_size, sizeof(char));
                 if(!sect_buf) {
                    debug("cannot allocate memory!\n");
                    ret = -1;
                    break;
                  }
                 spsn_tmp->flash.read(flash, ((sect_addr + i) * sector_size), sector_size, sect_buf);
                 memcpy(sect_buf,buf+i*sector_size-(offset % sector_size), (offset+len) % sector_size);
                 f_malloc=1;   
              } 
             spsn_tmp->flash.erase(flash, ((sect_addr + i) * sector_size), sector_size);  
             ret=spansion_write(flash, ((sect_addr + i) * sector_size), sector_size, sect_buf);
             if(f_malloc) {
                 free(sect_buf);
                 f_malloc=0;
             }
             if (ret != 0) {
                printf("Error in write handler, return !\n");
                return ret;
            }
             sect_buf = (unsigned char *)(buf + (i+1)*sector_size - (offset % sector_size));
        }
        return ret;
}
#endif //VBG400_PARTIAL_SUPPORT


void set_address(const struct spansion_spi_flash_params *params)
{
    int i;
	unsigned long block_size = params->page_size * params->pages_per_sector;

	for (i = 0; i < params->nr_sectors; i++) {
	    start_sect[i] = i * block_size/*FLASH_BLOCK_SIZE*/;
        printf_spi("set_address: start_sect[%i] = 0x%08lx\n",i, start_sect[i]);
	}
}


void flash_get_first_last(const struct spansion_spi_flash_params *params, int* s_first, int* s_last, u32 offset, size_t len, unsigned long sector_size)
{
    int i;
    
    *s_first = -1;
    *s_last = -1;

    /*printf_spi*/printf("SF: Detected %s with page size %u, nr_sectors=%u\n",
	      params->name, params->page_size, params->nr_sectors);
    /*printf_spi*/printf("flash_get_first_last: sector_count = %d, sector_size = %ld\n",params->nr_sectors, sector_size);
    
    if ((offset+len-1) > (start_sect[params->nr_sectors-1]+sector_size)) {
        printf("flash_get_first_last: error target address outside flash \n");
        return;
    }
    
    /*last sector handling*/
    if (offset == start_sect[params->nr_sectors-1]) {
       /*printf_spi*/printf("flash_get_first_last: offset is last sector\n");
       *s_first = params->nr_sectors-1;
       *s_last = params->nr_sectors-1;
       return;
    }
    for (i = 0; i < params->nr_sectors; i++) {
        //printf_spi("flash_get_first_last: start_sect[%d] = 0x%08lx\n",i,start_sect[i]);
        //printf_spi("(offset+len-1) = 0x%08x, (start_sect[%d]+sector_size) = 0x%08lx\n",(offset+len-1),i,(start_sect[i]+sector_size));
        if ((*s_first == -1) &&
            (offset >= start_sect[i]) &&
                (offset < start_sect[i+1]))
            *s_first = i;
        
        if ((*s_last == -1) &&
                ((offset+len) >= start_sect[i]) &&
                    ((offset+len-1) < (start_sect[i]+sector_size)))
            *s_last = i;
    }
}


static int flash_serial_sect_erase(ulong addr)
{    
    printf_spi("sector erase, please wait, addr = 0x%08lx\n",addr);

    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
    WRITE_FLASH_MTD(CMD_WR_ENABLE);
    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
    WRITE_FLASH_MTD(CMD_SECT_ERASE);
    WRITE_FLASH_MTD((addr & 0x00FF0000)>>16);
    WRITE_FLASH_MTD((addr & 0x0000FF00)>>8);
    WRITE_FLASH_MTD(addr & 0x000000FF);
    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);

    if(read_status_ready(SPI_FLASH_SECTOR_ERASE_TIMEOUT) != 0) {
	    printf ("flash_serial_sect_erase: ERR_TIMOUT\n");
        return -1;
    }

    WRITE_FLASH_MTD(CMD_WR_DISABLE);
    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
    
    return 0;
}


int	spansion_erase (struct spi_flash *flash, u32 offset, size_t len)
{
#ifdef TODO_HANDLE_PROTECTION
	int prot;
#endif
	int sect;
	int rcode = 0;
    int s_first;
    int s_last;
	unsigned long sector_size;
	struct spansion_spi_flash *spsn_tmp = to_spansion_spi_flash(flash);

    /*printf_spi*/printf("spansion_erase: offset = 0x%08x, len = %d\n",offset,len);
	sector_size = spsn_tmp->params->page_size * spsn_tmp->params->pages_per_sector;

	flash_get_first_last(spsn_tmp->params, &s_first, &s_last, offset, len, sector_size);
	if (offset > start_sect[spsn_tmp->params->nr_sectors-1]) {
		printf("SF: Erase offset address error, spsn_tmp->params->nr_sectors = %d\n",spsn_tmp->params->nr_sectors);
		return -1;
	}
    
    /* TODO- fix driver for 'none sector alighned' storage. Address may be non sector aligned.
    */
	if ((offset & 0x00FFFFFF) % sector_size) { //Note- fix length if it part of flash section. TODELETE !
		printf("SF: Erase offset not multiple of sector size\n");
		return -1;
	}
	
	if (len % sector_size) {
		printf("SF: Erase length not multiple of sector size\n");
		return -1;
    }

    /*printf_spi*/printf("spansion_erase: s_first = %d, s_last = %d\n",s_first,s_last);
	if (s_first < 0 || s_last < 0 || (s_last < s_first)) {
        printf("spansion_erase: error evaluate sections\n");
        return 1;
    }

#ifdef TODO_HANDLE_PROTECTION
	prot = 0;
	for (sect=s_first; sect<=s_last; ++sect) {
		if (info->protect[sect]) {
			prot++;
		}
	}

	if (prot) {
		printf ("- Warning: %d protected sectors will not be erased!\n",
			prot);
	} else {
		printf ("\n");
	}
#endif
	/* Start erase on unprotected sectors */
	for (sect = s_first; sect<=s_last && rcode == 0; sect++) {
        /*TODO- handle protection ! */
        /*printf_spi*/printf("erase sect = %d\n",sect);
        /* erase sector */
#ifndef VBG400_TEST_WRITE
        if(flash_serial_sect_erase(start_sect[sect]) != 0)
            return 1;
#else
        printf("VBG400_TEST_WRITE: skip erase 0x%08x\n",start_sect[sect]);
#endif
    }
    return 0;
}

struct spansion_spi_flash *spsn = 0;

struct spi_flash *spi_flash_probe_spansion(struct spi_slave *spi, u8 *idcode)
{
	const struct spansion_spi_flash_params *params;
	unsigned int i;
	unsigned short jedec, ext_jedec;

    printf_spi("printf - spi_flash_probe_spansion\n");
#if 0
	if (spsn) {
	    printf("spi_flash_probe_spansion\n");
	    printf("idcode1 = 0x%04x, idcode2 = 0x%04x\n",spsn->params->idcode1,spsn->params->idcode2);
	    //jedec = idcode[1] << 8 | idcode[2];
	    //ext_jedec = idcode[3] << 8 | idcode[4];
        //if ((spsn->params->idcode1) == jedec && (spsn->params->idcode2 == ext_jedec)) {
	    //    printf("spi_flash_probe_spansion: spansion flash probe done already\n");
	    //    return &spsn->flash;
        //}
    }
	
#endif
	printf_spi("spi_flash_probe_spansion:  idcode %02x %02x %02x %02x %02x\n", idcode[0],
			idcode[1], idcode[2], idcode[3], idcode[4]);
	jedec = idcode[1] << 8 | idcode[2];
	ext_jedec = idcode[3] << 8 | idcode[4];
	printf_spi("spi_flash_probe_spansion: jedec = 0x%x, ext_jedec = 0x%x\n",jedec,ext_jedec);

	for (i = 0; i < ARRAY_SIZE(spansion_spi_flash_table); i++) {
		params = &spansion_spi_flash_table[i];
		if (params->idcode1 == jedec) {
			if (params->idcode2 == ext_jedec) {
	            printf("flash found in array, name %s\n",params->name);
				break;
            }
		}
	}

	if (i == ARRAY_SIZE(spansion_spi_flash_table)) {
		//debug("SF: Unsupported SPANSION ID %04x %04x\n", jedec, ext_jedec);
		printf("SF: Unsupported SPANSION ID %04x %04x\n", jedec, ext_jedec);
		return NULL;
	}

	spsn = malloc(sizeof(struct spansion_spi_flash));
	if (!spsn) {
		printf("SF: Failed to allocate memory\n");
		return NULL;
	}
	spsn->params = params;
	spsn->flash.spi = spi;
	spsn->flash.name = params->name;

#ifdef VBG400_PARTIAL_SUPPORT
	spsn->flash.write = spansion_write_partial;
#else
	spsn->flash.write = spansion_write;
#endif
	spsn->flash.erase = spansion_erase;
	spsn->flash.read = spansion_read_fast;
	spsn->flash.size = params->page_size * params->pages_per_sector
	    * params->nr_sectors;

    printf_spi("SF: Detected %s with page size %u, total %u bytes, nr_sectors=%u\n",
	      params->name, params->page_size, spsn->flash.size, params->nr_sectors);

    set_address(spsn->params);

	return &spsn->flash;
}


int spi_flash_cmd(struct spi_slave *spi, u8 cmd, void *response, size_t len)
{
    ulong mode_reg;    
    printf_spi("in spi_flash_cmd\n");
    /* spi_slave* spi - dummy ptr - not in use for vbg400
    */
    /**************** Change to SW mode in order to read ID ****************/
	*(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) |= VBG400_SPI_MODE_SW_BIT;
    /*clear page field*/
	mode_reg = *(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) & VBG400_SPI_MODE_CLEAR_PAGE_BITS;
	*(volatile unsigned long *)(VBG400_SPI_MODE_ADDR) = mode_reg /*| mode_reg*/;
    printf_spi("clear page field: reg = 0x%08x\n",(u32)*(volatile unsigned long *)(VBG400_SPI_MODE_ADDR));
    /************************  END ******************************************/

    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);
    /*read manufacturer*/
    WRITE_FLASH_MTD(CMD_RD_CHIP_ID);
    WRITE_FLASH_MTD(WR_DUMMY);
    /*ManufacturerId*/*(u8*)response = *vbg400SpiReadAddr;
    WRITE_FLASH_MTD(WR_DUMMY);
    /*MemoryType*/*(((u8*)response)+1) = *vbg400SpiReadAddr;
    WRITE_FLASH_MTD(WR_DUMMY);
    /*MemoryCapacity*/*(((u8*)response)+2) = *vbg400SpiReadAddr;
    /*clear rest of array - do not remove*/
    *(((u8*)response)+3) = 0;
    *(((u8*)response)+4) = 0;
    
    printf_spi("ManufacturerId = 0x%x\n",*(u8*)response);
    printf_spi("MemoryType = 0x%x\n",*(((u8*)response)+1));
    printf_spi("MemoryCapacity = 0x%x\n",*(((u8*)response)+2));
    WRITE_FLASH_MTD(SET_NEW_WR_CYCLE);

	return 0;
}
