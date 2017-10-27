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
#include <config.h>
#include <common.h>
#include <command.h>
#include <asm/addrspace.h>
#include <asm/vr9.h>
#include <environment.h>
#include "dsl_address_define.h"
#include <nand.h>
#include <spi_flash.h>

#if !defined(DEBUG_ENABLE_BOOTSTRAP_PRINTF) && defined(CFG_BOOTSTRAP_CODE)                                                                            
#define printf                                                                                                                                        
#endif   

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



phys_size_t initdram(int board_type)
{
	return (1024*1024*CONFIG_IFX_MEMORY_SIZE);
}


int flash_probe(void)
{
   (*BSP_EBU_BUSCON0)=0x1d7ff;  //value from Aikann, should be used on the real chip
   (*BSP_EBU_ADDSEL0) = 0x10000031; //starting address from 0xb0000000
   (*BSP_EBU_NAND_CON)=0;
   return 1;
}

void fpi_dfe_reg_write(u32 offset, u32 data)
{
    REG32(FPIAD(offset)) = data;
}

u32 fpi_dfe_reg_read(u32 offset)
{
    return(REG32(FPIAD(offset)));
}

void afe_reg_write(u32 addr, u32 data)
{
    fpi_dfe_reg_write(V_AFE_SERIAL_ADDR, addr);
    fpi_dfe_reg_write(V_AFE_SERIAL_WDATA, data);
}


unsigned short config_afe(void)
{
     *BSP_PMU_PWDCR &= ~(1<<9); /*turn on afe*/
	 REG32(0xbf20302c) |= 0x40000000;
	 fpi_dfe_reg_write(V_AFE_SERIAL_CFG, 0x90);
	 afe_reg_write(0x324, 0x8402);	 
	 REG32(0xbf20302c) &=~(0x40000000);
     return 0;
}

void show_boot_progress(int arg)
{
  return;
}

void config_dcdc(u8 value)
{
#ifdef CONFIG_ENABLE_DCDC
   u8 inc=0;
   u8 orig=REG8(PDI_DCDC_DIG_REF);
   u8 fuse_value;
  
   fuse_value=(u8)((REG32(0xBF107358) & 0xe0000) >>17);
   REG8(PDI_DCDC_BIAS_VREG) |=(fuse_value & 0xf1); 

   REG8(PDI_DCDC_DUTY_CYCLE_MAX_SAT) = 0x5A;  /*DUTY_CYCLE_SAT_MAX = 90*/ 
   REG8(PDI_DCDC_DUTY_CYCLE_MIN_SAT) = 0x46;  /*DUTY_CYCLE_SAT_MIN = 70*/

   REG8(PDI_DCDC_CONF_TEST_DIG) |=(u8)(1<<5); /*FREEZE_PID=1*/
   
   /*Programming of new coefficients (6 registers a 8 bits)*/
   REG8(PDI_DCDC_PID_HI_B0) = 0x00;
   REG8(PDI_DCDC_PID_LO_B0) = 0x00;
   REG8(PDI_DCDC_PID_HI_B1) = 0xff;
   REG8(PDI_DCDC_PID_LO_B1) = 0xe6;
   REG8(PDI_DCDC_PID_HI_B2) = 0x00;
   REG8(PDI_DCDC_PID_LO_B2) = 0x1b;
#ifdef CONFIG_GRX200
   REG8(PDI_DCDC_NON_OV_DELAY) = 0x5B;
#else
   REG8(PDI_DCDC_NON_OV_DELAY) = 0x8B;
#endif

   REG8(PDI_DCDC_DUTY_CYCLE_MAX_SAT) = 0x6C;     /*DUTY_CYCLE_SAT_MAX = 108 (0x6C)*/
   REG8(PDI_DCDC_DUTY_CYCLE_MIN_SAT) = 0x3C;     /*DUTY_CYCLE_SAT_MIN = 60*/
   REG8(PDI_DCDC_CONF_TEST_DIG) &=(u8)(~(1<<5)); /*FREEZE_PID=0*/
  
   REG8(PDI_DCDC_CLK_SET0) |= 0x40; /*Set bit 6, select PWM*/
   REG8(PDI_DCDC_CLK_SET1) |= 0x20; 
   REG8(PDI_DCDC_PWM0) = 0xF9; // 249 in decimal
   
   if(orig > value) inc=-1;
	 else if(orig <value)	inc=1;
	 else return;
	 while( REG8(PDI_DCDC_DIG_REF)!= value)	
	 {
	 	  mdelay(1);
	 	  REG8(PDI_DCDC_DIG_REF) +=inc; 
	 }
#else  /*turn off DCDC*/
  REG8(PDI_DCDC_CONF_TEST_ANA) = 0x78;
  REG8(PDI_DCDC_CONF_TEST_DIG) = 0x0;
  REG8(PDI_DCDC_GENERAL) = 0x88;
#endif
}

int check_pll1_lock(void)
{
   int result = 0;/*0 fail, 1 success*/
   int i;
#ifdef CONFIG_VR9_CRYSTAL_25M
   u32 pll1_value[4]={0x984E6785,0x984E63C1,0x984E6B09,0x984E6F4D};
   int LOOP = 4;
#elif CONFIG_VR9_CRYSTAL_36M
   u32 pll1_value[5]={0x9BA66545,0x9BA66809,0x9BA66ACD,0x9BA66D91,0x9BA67015};    
   int LOOP = 5;

#endif
   for(i=0;i<LOOP;i++){
     if(!(*BSP_PLL1_CFG & 0x2)) {
	     if(i==LOOP-1) {
               result = 0;
			   printf("PLL1 lock failed!\n");
			   break;
		               }
	     *BSP_PLL1_CFG &=~1;  /*disable PLL1*/
		 *BSP_CGU_UPDATE |=1;
		 *BSP_PLL1_CFG = pll1_value[i];
		 *BSP_CGU_UPDATE |=1;
		 mdelay(1);
		 //printf("i=%d,PLL1_CFG=%08x\n",i,*BSP_PLL1_CFG);
		 
	     }
     else{
	         if((i!=0) && (i!= LOOP-1)){
                  i=LOOP-2;
				  *BSP_PLL1_CFG = pll1_value[LOOP-1];
				  *BSP_CGU_UPDATE |=1;
				  mdelay(1);
				  //printf("2. i=%d,PLL1_CFG=%08x\n",i,*BSP_PLL1_CFG);
                }else{
                 result = 1;
			     break;
                }
	      }/*if(!(*BSP_PLL1_CFG & 0x2))*/
	 }/*for(i=0;i<LOOP;i++)*/
   return result;
}

int checkboard (void)
{

    printf("CLOCK CPU %dM RAM %dM\n",CPU_CLOCK_RATE/1000000,RAM_CLOCK_RATE/1000000);
#ifdef CONFIG_LTQ_SECURE_BOOT
    printf("secure boot\n");
#endif
	config_afe();
#ifdef CONFIG_VR9_CRYSTAL_25M	
	REG8(0xbf106b00)=0x3;
#endif	
   
    *EBU_ADDR_SEL_0 = 0x10000031; /*has to do this or nand probing will hang*/
    *EBU_CON0 = CONFIG_EBU_BUSCON0;

#ifndef CONFIG_VR9_CPU_393M_RAM_196M
    if(!check_pll1_lock()) return 1;
	
#endif
  
   config_dcdc(0x7f);

#ifdef CONFIG_GRX200 /*power gate DEF for GRX mode*/
   REG32(BSP_PMU_PWCSR) = 0x31b ;
#endif
	return 0;
}


#ifdef CONFIG_NAND_FLASH
void nand_gpio_init(void)
{
	  *BSP_GPIO_P3_DIR=0x2;
    *BSP_GPIO_P3_ALTSEL0=0x3;
    *BSP_GPIO_P3_ALTSEL1=0x0;
    *BSP_GPIO_P3_OD=0x3;
    
    /* set GPIO pins for NAND */
    /* P0.13 FL_A24 01:output*/
    /* P1.8 FL_A23 01:output*/
    *BSP_GPIO_P0_ALTSEL0 |= 0x2000;
    *BSP_GPIO_P0_ALTSEL1 &= (~0x2000);
    *BSP_GPIO_P0_DIR |= (0x2000);
    *BSP_GPIO_P1_ALTSEL0 |= 0x100;
    *BSP_GPIO_P1_ALTSEL1 &= (~0x100);
    *BSP_GPIO_P1_DIR |= (0x100);
    
    /*Set GPIO7 as general GPIO output instead of parking at CFRAME*/ 
    *BSP_GPIO_P0_ALTSEL0 &=(~0x80);
    *BSP_GPIO_P0_ALTSEL1 &=(~0x80);
    *BSP_GPIO_P0_DIR |= (0x80);
    *BSP_GPIO_P0_DIR |= (0x80);
    
}
#endif



#ifdef CONFIG_LANTIQ_SPI

int spi_gpio_init(unsigned int cs)
{
   /* enable SSC1 */
        //*DANUBE_PMU_PM_GEN |= DANUBE_PMU_PM_GEN_EN11;

        /* SSC1 Ports */
        /* p0.15 SPI_CS1(EEPROM), P0.13 SPI_CS3, P0.9 SPI_CS5, P0.10 SPI_CS4, P0.11 SPI_CS6 */
        /* Set p0.10 to alternative 01, others to 00 (In/OUT)*/
        *(BSP_GPIO_P0_DIR) = (*BSP_GPIO_P0_DIR)|(0xAE00);

        *(BSP_GPIO_P0_ALTSEL0) = (((*BSP_GPIO_P0_ALTSEL0)&(~0x0400)) & (~(0xAA00)));
        *(BSP_GPIO_P0_ALTSEL1) = (((*BSP_GPIO_P0_ALTSEL1)|(0x0400)) & (~(0xAA00)) );

        *(BSP_GPIO_P0_OD) = (*BSP_GPIO_P0_OD)|0xAE00;

        /* p1.6 SPI_CS2(SFLASH), p1.0 SPI_DIN, p1.1 SPI_DOUT, p1.2 SPI_CLK */
        *(BSP_GPIO_P1_DIR) = ((*BSP_GPIO_P1_DIR)|(0x46))&(~1);
        *(BSP_GPIO_P1_ALTSEL0) = ((*BSP_GPIO_P1_ALTSEL0)|(0x47));
        *(BSP_GPIO_P1_ALTSEL1) = (*BSP_GPIO_P1_ALTSEL1)&(~0x47);
        *(BSP_GPIO_P1_OD) = (*BSP_GPIO_P1_OD)|0x0046;

	 return 1;																					 
}
#endif

#ifdef CONFIG_TUNE_DDR

#define DDR_OFFSET     0xbf401000
#define DDR_CCR39      (DDR_OFFSET + 0x0270 )
#define DDR_CCR40      (DDR_OFFSET + 0x0280 )
#define DDR_CCR43      (DDR_OFFSET + 0x02B0 )
#define DDR_CCR44      (DDR_OFFSET + 0x02C0 )
int get_tuned_param(ulong* buffer)
{
    int    ret= 1;
    ulong  ddr_magic=0x88888888;
    ulong  ecc;

    if (REG32(CONFIG_TUNING_STATUS)!=0x2) {
         ret = 0;
         goto EXIT;
    }

    buffer[0]= ddr_magic;
    buffer[1]= REG32(DDR_CCR39);
    buffer[2]= REG32(DDR_CCR40);
    buffer[3]= REG32(DDR_CCR43);
    buffer[4]= REG32(DDR_CCR44);
    buffer[5]= REG32(CSS_DDR_ECHO_DLL0);
    buffer[6]= REG32(CSS_DDR_ECHO_DLL1);
    buffer[7]= buffer[1]^buffer[2]^buffer[3]^buffer[4]^buffer[5]^buffer[6];
EXIT:
    return ret;
}


#ifdef CONFIG_BOOT_FROM_NOR
void save_ddr_param(void)
{
         int rcode;
	 ulong erase_addr1=0, erase_addr2=0;
	 ulong  buffer[8];
	 erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR; 
	 erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;
  
         if(!get_tuned_param(&buffer)) return; 

         if(flash_sect_protect (0, erase_addr1, erase_addr2-1))
         {
	      printf("protect off error!\n");
	 }
									 
         if (flash_sect_erase (erase_addr1, erase_addr2-1))
         {
	       printf("erase error!\n");
	 }
	 rcode = flash_sect_erase(erase_addr1, erase_addr2-1);
    

	 flash_write((char *)buffer, IFX_CFG_FLASH_DDR_CFG_START_ADDR, 32);

	 //(void) flash_sect_protect (1, erase_addr1, erase_addr2-1);
										
     return;
}
#elif defined(CONFIG_BOOT_FROM_NAND)
extern nand_info_t nand_info[]; 
//extern int nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t * retlen, const u_char * buf);

void save_ddr_param(void)
{   
	   ulong  buffer[8];
	   nand_info_t *nand=&nand_info[0];
	   u64 srcLen=32;
           if(!get_tuned_param(&buffer)) return; 
	   nand_write_partial(&nand_info[0], IFX_CFG_FLASH_DDR_CFG_START_ADDR, &srcLen, (u_char*)buffer);
	   printf("saved ddr param in flash!\n");
           return;
}
#else /*BOOT from SPI*/
void save_ddr_param(void)
{
	 ulong  buffer[8];
	 static struct spi_flash *flash_spi;
	 flash_spi = spi_flash_probe(CONFIG_ENV_SPI_BUS, CONFIG_ENV_SPI_CS,
            CONFIG_ENV_SPI_MAX_HZ, CONFIG_ENV_SPI_MODE);
         if(!get_tuned_param(&buffer)) return;	
	 spi_flash_write(flash_spi, IFX_CFG_FLASH_DDR_CFG_START_ADDR, 32, (char *)buffer);   
	 printf("saved ddr param in flash!\n");    
	    
	 return; 
}
#endif
#endif

extern int vr9_eth_initialize(bd_t * bis);

int board_eth_init(bd_t *bis)
{
   if (vr9_eth_initialize(bis)<0)
             return -1;

	return 0;
}
						 
