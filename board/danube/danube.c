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
#include <asm/addrspace.h>
//#include <asm/danube.h>
#include <environment.h>
#include <spi_flash.h>

#ifndef CONFIG_ENV_SPI_BUS
# define CONFIG_ENV_SPI_BUS 0
#endif
#ifndef CONFIG_ENV_SPI_CS
# define CONFIG_ENV_SPI_CS      0
#endif
#ifndef CONFIG_ENV_SPI_MAX_HZ
# define CONFIG_ENV_SPI_MAX_HZ  1000000
#endif
#ifndef CONFIG_ENV_SPI_MODE
# define CONFIG_ENV_SPI_MODE    SPI_MODE_3
#endif

#ifdef CONFIG_NOR_FLASH_AUTO
void save_extra_env()
{
   extern flash_info_t flash_info[CFG_MAX_FLASH_BANKS];
   extern xway_flash_partition_map_info flash_map[];
   int i,j,total_db,total_part;
   int mtd_part;
   u32  tmp;
   char strTemp[32], strCommand[128];
   char strimg_addr[32],strimg_size[32],strimg_end[32];
   i=0;
   while(flash_map[i].size !=0){
    	 if(flash_map[i].size == flash_info[0].size>>20) break;
    	 i++;
    }
   total_db = 0;
   mtd_part = -1; 
   total_part = 0;
   for(j=0;j<XWAY_MAX_BLOCK_NUM;j++){
   	     if(strcmp(flash_map[i].block[j].blockName,"")!=0){
   	     	 total_db++;
   	     	 
   	     	 sprintf(strTemp,"data_block%d",j);
   	     	 if(!getenv(strTemp)) setenv(strTemp, flash_map[i].block[j].blockName);
           sprintf(strTemp,"f_%s_addr",flash_map[i].block[j].blockName);
           sprintf(strimg_addr,"0x%08x",flash_map[i].block[j].startAddr);
           if(!getenv(strTemp)) setenv(strTemp,strimg_addr);
           if(flash_map[i].block[j].mtdNum!=mtd_part){
   	     	    mtd_part = flash_map[i].block[j].mtdNum;
   	     	    total_part ++;
   	     	    sprintf(strTemp, "part%d_begin", j);
   	     	    if(!getenv(strTemp)) setenv(strTemp,strimg_addr);	
   	     	 }
           
           	sprintf(strTemp,"f_%s_size",flash_map[i].block[j].blockName);
            sprintf(strimg_size,"0x%08x",flash_map[i].block[j].sizeBytes);
            if(!getenv(strTemp)) setenv(strTemp,strimg_size);
            sprintf(strTemp,"f_%s_end",flash_map[i].block[j].blockName);
            sprintf(strimg_end,"0x%08x", flash_map[i].block[j].startAddr + flash_map[i].block[j].sizeBytes - 1);
            if(!getenv(strTemp)) setenv(strTemp,strimg_end);
             	
            if(strcmp(flash_map[i].block[j].blockName,"ubootconfig")==0) {
           	   sprintf(strCommand,"prot off 0x%08x %s;erase 0x%08x %s 1",\
           	           flash_map[i].block[j].startAddr,strimg_end,\
           	           flash_map[i].block[j].startAddr,strimg_end);
           	   sprintf(strTemp,"reset_uboot_config");
           	   if(!getenv(strTemp)) setenv(strTemp,strCommand);        
           	
            }
            
                       
        }
    } 
    sprintf(strTemp, "%d", total_db);
    if(!getenv(strTemp)) setenv("total_db", strTemp);
    sprintf(strTemp, "%d", total_part);
    if(!getenv(strTemp)) setenv("total_part", strTemp);
    sprintf(strTemp, "0x%08x", 0xb0000000 + flash_info[0].size);
    if(!getenv(strTemp)) setenv("flash_end", strTemp);
    sprintf(strTemp, "mtdparts");
    if(!getenv(strTemp)) setenv(strTemp,flash_map[i].mtdparts);	
    	
   return;
}

#endif

#ifdef CONFIG_NAND_FLASH
void nand_gpio_init(void)
{
    //Set GPIO23 to be Flash CS1;
	*DANUBE_GPIO_P1_ALTSEL0 = *DANUBE_GPIO_P1_ALTSEL0 | (1<<7) | (1<<8);
	*DANUBE_GPIO_P1_ALTSEL1 = *DANUBE_GPIO_P1_ALTSEL1 & ~(1<<7) & ~ (1<<8);
	*DANUBE_GPIO_P1_DIR = *DANUBE_GPIO_P1_DIR | (1<<7) | (1<<8);
	*DANUBE_GPIO_P1_OD = *DANUBE_GPIO_P1_OD | (1<<7) | (1<<8) ;
	(*DANUBE_GPIO_P0_ALTSEL0) = (*DANUBE_GPIO_P0_ALTSEL0) | (1<<13);
	//Set GPIO 13 to ND_ALE
	(*DANUBE_GPIO_P0_ALTSEL1) = (*DANUBE_GPIO_P0_ALTSEL1) &  ~(1<<13);
	(*DANUBE_GPIO_P0_OD) = (*DANUBE_GPIO_P0_OD) | (1<<13) ;
	(*DANUBE_GPIO_P0_DIR) =	(*DANUBE_GPIO_P0_DIR) | (1<<13) ; // set GPIO 13 to output
																			
    return;
}

#endif

#ifdef CONFIG_LANTIQ_SPI
#define BIT(X)       (1 << (X))
#define SPI_MODULO   16
#define SPI_CS4     (10 & 0xF)  /* P0.10 */
#define SPI_DIN     (16 & 0xF)  /* P1.0 */
#define SPI_DOUT    (17 & 0xF)  /* P1.1 */
#define SPI_CLK     (18 & 0xF)  /* P1.2 */

typedef struct spi_cs_gpio{
   u8 port;
   u8 pin;
   u8 dir;
   u8 alt0;
   u8 alt1;
};

int spi_gpio_init(unsigned int cs)
{
	   struct spi_cs_gpio cs_gpio[5]={
                {0, 15, 1, 0, 1},
				{1, 6,  1, 0, 1},
				{0, 13, 1, 1, 0},
				{0, 10, 1, 1, 0},
				{0, 9,  1, 1, 0}
				};
	  if(cs<0 || cs>5) return 0; /*cs pin out of range*/          
	
      if(cs_gpio[cs].port == 0)
	  {
        *(DANUBE_GPIO_P0_DIR)     |= BIT(cs_gpio[cs].pin);
		*(DANUBE_GPIO_P0_ALTSEL0) = (*(DANUBE_GPIO_P0_ALTSEL0) & ~BIT(cs_gpio[cs].alt0))|BIT(cs_gpio[cs].alt0);
		*(DANUBE_GPIO_P0_ALTSEL1) = (*(DANUBE_GPIO_P0_ALTSEL1) & ~BIT(cs_gpio[cs].alt1))|BIT(cs_gpio[cs].alt1);
		*(DANUBE_GPIO_P0_OD)      |= BIT(cs_gpio[cs].pin);
	  }
	  else
	  {
	    *(DANUBE_GPIO_P1_DIR)     |= BIT(cs_gpio[cs].pin);
	    *(DANUBE_GPIO_P1_ALTSEL0) = (*(DANUBE_GPIO_P1_ALTSEL0) & ~BIT(cs_gpio[cs].alt0))|BIT(cs_gpio[cs].alt0);
		*(DANUBE_GPIO_P1_ALTSEL1) = (*(DANUBE_GPIO_P1_ALTSEL1) & ~BIT(cs_gpio[cs].alt1))|BIT(cs_gpio[cs].alt1);
		*(DANUBE_GPIO_P1_OD)      |= BIT(cs_gpio[cs].pin);
										
	  }
	  /* p1.0 SPI_DIN, p1.1 SPI_DOUT, p1.2 SPI_CLK */
	  *(DANUBE_GPIO_P1_DIR)      = ((*DANUBE_GPIO_P1_DIR)| BIT(SPI_DOUT) | BIT(SPI_CLK))&(~BIT(SPI_DIN));
	  *(DANUBE_GPIO_P1_ALTSEL0) |= (BIT(SPI_DOUT) | BIT(SPI_CLK) | BIT(SPI_DIN));
	  *(DANUBE_GPIO_P1_ALTSEL1) &= ~(BIT(SPI_DOUT) | BIT(SPI_CLK) | BIT(SPI_DIN));
	  *(DANUBE_GPIO_P1_OD)      |= (BIT(SPI_DOUT) | BIT(SPI_CLK));
#if 0
         *(DANUBE_GPIO_P0_DIR) = (*DANUBE_GPIO_P0_DIR)|(0xAE00);
		 *(DANUBE_GPIO_P0_ALTSEL0) = (((*DANUBE_GPIO_P0_ALTSEL0)|(0x8000)) & (~(0x2E00)));
		 *(DANUBE_GPIO_P0_ALTSEL1) = (((*DANUBE_GPIO_P0_ALTSEL1)&(~0x8000)) & (~(0x2E00)) );
		 *(DANUBE_GPIO_P0_OD) = (*DANUBE_GPIO_P0_OD)|0xAE00;

		  /* p1.6 SPI_CS2(SFLASH), p1.0 SPI_DIN, p1.1
		 * SPI_DOUT, p1.2 SPI_CLK */
		 *(DANUBE_GPIO_P1_DIR) =  ((*DANUBE_GPIO_P1_DIR)|(0x46))&(~1);
		 *(DANUBE_GPIO_P1_ALTSEL0) = ((*DANUBE_GPIO_P1_ALTSEL0)|(0x47));
		 *(DANUBE_GPIO_P1_ALTSEL1) = (*DANUBE_GPIO_P1_ALTSEL1)&(~0x47);
		 *(DANUBE_GPIO_P1_OD) = (*DANUBE_GPIO_P1_OD)|0x0046;
#endif     
     return 1;
}
#endif

#ifdef CONFIG_TUNE_DDR
#ifdef CONFIG_BOOT_FROM_NOR
void save_ddr_param(void)
{
     int rcode;
	 ulong   ddr_magic=0x88888888;
	 ulong erase_addr1=0, erase_addr2=0;
	 volatile ulong* ptr=IFX_CFG_FLASH_DDR_CFG_START_ADDR;
	 ulong  ecc;
	 ulong  buffer[6];
	 erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR; 
	 erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;
	 if(*(u32*)0xbe1a5f20!=0x2)  /*0xBE1A5F20 contains the tuning status*/
	    {
		    /*no new parameter, return immediately*/
		    return;
	    }
#if 0	 
	 if(*ptr==ddr_magic)
	     {
		     ecc=(*(ptr+1))^(*(ptr+2))^(*(ptr+3))^(*(ptr+4));
			 if(ecc==*(ptr+5)) return; /*already tuned, return then*/
		 }
#endif		 
     if(flash_sect_protect (0, erase_addr1, erase_addr2-1))
	     {
		      printf("protect off error!\n");
		 }
									 
     if (flash_sect_erase (erase_addr1, erase_addr2-1))
	     {
		       printf("erase error!\n");
		 }
									  
	 rcode = flash_sect_erase(erase_addr1, erase_addr2-1);

    
     memcpy ((u8*)buffer,&ddr_magic,4);
	 memcpy ((u8*)(buffer+1),(u8*)0xbe1a5f10,16);
	 ecc=(*(u32*)0xbe1a5f10)^(*(u32*)0xbe1a5f14)^(*(u32*)0xbe1a5f18)^(*(u32*)0xbe1a5f1c);
	 memcpy ((u8*)(buffer+5),&ecc,4);

	 flash_write((char *)buffer, IFX_CFG_FLASH_DDR_CFG_START_ADDR, 24);/*one magic word,4 parameters,1cc,24bytes*/

	 //(void) flash_sect_protect (1, erase_addr1, erase_addr2-1);
										
     return;
}
#elif CONFIG_BOOT_FROM_NAND
void save_ddr_param(void)
{
	 return;
}
#elif CONFIG_BOOT_FROM_SPI
void save_ddr_param(void)
{
	 int rcode;
	 ulong   ddr_magic=0x88888888;
	 ulong erase_addr1=0, erase_addr2=0;
	 volatile ulong* ptr=IFX_CFG_FLASH_DDR_CFG_START_ADDR;
	 ulong  ecc;
	 ulong  buffer[6];
	 static struct spi_flash *flash_spi;
	 flash_spi = spi_flash_probe(CONFIG_ENV_SPI_BUS, CONFIG_ENV_SPI_CS,
            CONFIG_ENV_SPI_MAX_HZ, CONFIG_ENV_SPI_MODE);
	
	 erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR; 
	 erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;
	 if(*(u32*)0xbe1a5f20!=0x2)  /*0xBE1A5F20 contains the tuning status*/
	    {
		    /*no new parameter, return immediately*/
		    return;
	    }
	 
	 memcpy ((u8*)buffer,&ddr_magic,4);
	 memcpy ((u8*)(buffer+1),(u8*)0xbe1a5f10,16);
	 ecc=(*(u32*)0xbe1a5f10)^(*(u32*)0xbe1a5f14)^(*(u32*)0xbe1a5f18)^(*(u32*)0xbe1a5f1c);
	 memcpy ((u8*)(buffer+5),&ecc,4);  
	 spi_flash_write(flash_spi, erase_addr1, 24, (char *)buffer);   
	 printf("saved ddr param in flash!\n");    
	    
   return;
}
#endif
#endif


phys_size_t initdram(int board_type)
{
    return (1024*1024*CONFIG_IFX_MEMORY_SIZE);
}
	

int checkboard (void)
{
	return 0;
}

int board_eth_init(bd_t *bis)
{
   if (danube_eth_init(bis)<0)
            return -1;

    return 0;
}
						 
int board_early_init_f(void)
{
       (*EBU_ADDR_SEL_0) = CONFIG_EBU_ADDSEL0;
       (*EBU_CON_0) = CONFIG_EBU_BUSCON0;
	   return 0;
}
				   

