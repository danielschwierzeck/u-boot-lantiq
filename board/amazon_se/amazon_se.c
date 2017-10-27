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
#include <asm/amazon_se.h>
#include <environment.h>


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
        /* Configure EBU */
    //Set GPIO11 for FL_CS1 & GPIO12 for FL_A23/NAND_ALE
    *AMAZON_SE_GPIO_P0_ALTSEL0 = *AMAZON_SE_GPIO_P0_ALTSEL0 | (0x3<<11) ;
    *AMAZON_SE_GPIO_P0_ALTSEL1 = *AMAZON_SE_GPIO_P0_ALTSEL1 & ~(0x3<<11);
    *AMAZON_SE_GPIO_P0_DIR = *AMAZON_SE_GPIO_P0_DIR | (0x3<<11) ;
    *AMAZON_SE_GPIO_P0_OD = *AMAZON_SE_GPIO_P0_OD | (0x3<<11)  ;
   
    //Set  GPIO14 for NAND_CLE
    (*AMAZON_SE_GPIO_P0_ALTSEL0) = (*AMAZON_SE_GPIO_P0_ALTSEL0) | (1<<14);
    (*AMAZON_SE_GPIO_P0_ALTSEL1) = (*AMAZON_SE_GPIO_P0_ALTSEL1) & ~(1<<14);
    (*AMAZON_SE_GPIO_P0_OD) = (*AMAZON_SE_GPIO_P0_OD) | (1<<14) ;
    (*AMAZON_SE_GPIO_P0_DIR) = (*AMAZON_SE_GPIO_P0_DIR) | (1<<14) ;
    
    //Set  GPIO19(p1.3) for NAND_WR_N
    (*AMAZON_SE_GPIO_P1_ALTSEL0) = (*AMAZON_SE_GPIO_P1_ALTSEL0) | (1<<3);
    (*AMAZON_SE_GPIO_P1_ALTSEL1) = (*AMAZON_SE_GPIO_P1_ALTSEL1) & ~(1<<3);
    (*AMAZON_SE_GPIO_P1_OD) = (*AMAZON_SE_GPIO_P1_OD) | (1<<3) ;
    (*AMAZON_SE_GPIO_P1_DIR) = (*AMAZON_SE_GPIO_P1_DIR) | (1<<3) ;

    //Set GPIO 20(p1.4)  NAND_RD_busy input
    *AMAZON_SE_GPIO_P1_ALTSEL0 = *AMAZON_SE_GPIO_P1_ALTSEL0 | (1<<4);
    *AMAZON_SE_GPIO_P1_ALTSEL1 = *AMAZON_SE_GPIO_P1_ALTSEL1 & ~(1<<4);
    *AMAZON_SE_GPIO_P1_OD = (*AMAZON_SE_GPIO_P1_OD) | (1<<4) ;
    *AMAZON_SE_GPIO_P1_DIR = (*AMAZON_SE_GPIO_P1_DIR) & ~(1<<4) ;

    //Set GPIO 29(p1.13)  NAND_RD_N input
    *AMAZON_SE_GPIO_P1_ALTSEL0 = *AMAZON_SE_GPIO_P1_ALTSEL0 | (1<<13);
    *AMAZON_SE_GPIO_P1_ALTSEL1 = *AMAZON_SE_GPIO_P1_ALTSEL1 & ~(1<<13);
    *AMAZON_SE_GPIO_P1_OD = (*AMAZON_SE_GPIO_P1_OD) | (1<<13) ;
    *AMAZON_SE_GPIO_P1_DIR = (*AMAZON_SE_GPIO_P1_DIR) | (1<<13);

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
#if 0
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
#endif
        *(AMAZON_SE_GPIO_P0_DIR) = (((*AMAZON_SE_GPIO_P0_DIR)|(0x0780)) & (~(0x0100)));
        *(AMAZON_SE_GPIO_P0_ALTSEL0) = (((*AMAZON_SE_GPIO_P0_ALTSEL0)|(0x0780)) & (~(0x0000)));
        *(AMAZON_SE_GPIO_P0_ALTSEL1) = (((*AMAZON_SE_GPIO_P0_ALTSEL1)|(0x0780)) & (~(0x0780)));
        *(AMAZON_SE_GPIO_P0_OD) = (*AMAZON_SE_GPIO_P0_OD)|(0x0680);


       return 1;
}
#endif

phys_size_t initdram(int board_type)
{
	return (1024*1024*CONFIG_IFX_MEMORY_SIZE);
}

int checkboard (void)
{
	return 0;
}

extern int amazon_se_eth_init(bd_t *bis);

int board_eth_init(bd_t *bis)
{
   if (amazon_se_eth_init(bis)<0)
                      return -1;
     return 0;
}


int board_early_init_f(void)
{
        (*AMAZON_SE_EBU_ADDSEL0) = CONFIG_EBU_ADDSEL0;
		(*AMAZON_SE_EBU_BUSCON0) = CONFIG_EBU_BUSCON0;

		return 0;
}
				   

