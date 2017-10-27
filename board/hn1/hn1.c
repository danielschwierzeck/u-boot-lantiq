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

  /* Updated for HN1 by Andrei Toma */ 

#include <config.h>
#include <common.h>
#include <command.h>
#include <asm/addrspace.h>
#include <asm/hn1.h>
#include <environment.h>
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

#ifdef CONFIG_SF_DEFAULT_SPEED
#define CONFIG_ENV_SPI_MAX_HZ  CONFIG_SF_DEFAULT_SPEED
#else
#define CONFIG_ENV_SPI_MAX_HZ  1000000
#endif

#ifndef CONFIG_ENV_SPI_MODE
# define CONFIG_ENV_SPI_MODE    SPI_MODE_3
#endif

extern void mdelay (unsigned long msec);

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


void show_boot_progress(int arg)
{
  return;
}

void displayMemory8bit(u32 startAddress)
{
    int i;

    printf("--MEM DUMP---");
    for(i=0; i<0x24; i++)
    {
        if ((i&0x7)==0)
            printf("\n%08x:", (startAddress+i));
        printf(" %02x", REG8(startAddress+i));
    }
    printf("\n-------------\n");
}

void config_dcdc(u8 value)
{
    u8 orig;
    int i;
    int adjCount;

    //AT note: In HNX176 first silicon, is a HW issue when you try to read the registers located at offsets N*4-1.
    //For these registers the WRITE operation is OK, but the READ operation returns allways zero,
    //so the read-modify-write opperations will not work correctly.

    //displayMemory8bit(PDI_DCDC_BASE);

    REG8(PDI_DCDC_DUTY_CYCLE_MAX_SAT) = 0x5A;  //DUTY_CYCLE_SAT_MAX = 90
    REG8(PDI_DCDC_DUTY_CYCLE_MIN_SAT) = 0x46;  //DUTY_CYCLE_SAT_MIN = 70

    REG8(PDI_DCDC_CONF_TEST_DIG) |=(u8)(1<<5); //FREEZE_PID=1

    //Programming of new coefficients (6 registers a 8 bits)
    if (((REG32(BSP_RCU_GP_STRAP))& (1<<13))!=0)
    {
        printf("\nUse Lantiq third-party AFE.\n");
        REG8(PDI_DCDC_PID_HI_B0) = 0x03;
        REG8(PDI_DCDC_PID_LO_B0) = 0x66;
        REG8(PDI_DCDC_PID_HI_B1) = 0xf9;
        REG8(PDI_DCDC_PID_LO_B1_WO) = 0x20;
        REG8(PDI_DCDC_PID_HI_B2) = 0x03;
        REG8(PDI_DCDC_PID_LO_B2) = 0x7c;

        REG8(PDI_DCDC_CLK_SET0) = 0x12;     //CLK_SET0.clk_sel_pwm=0 ; CLK_SET0.mdll_m=0x12
    }
    else
    {
        printf("\nUse Lantiq VR9 AFE.\n");
        REG8(PDI_DCDC_PID_HI_B0) = 0x02;
        REG8(PDI_DCDC_PID_LO_B0) = 0x8d;
        REG8(PDI_DCDC_PID_HI_B1) = 0xfa;
        REG8(PDI_DCDC_PID_LO_B1_WO) = 0xd3;
        REG8(PDI_DCDC_PID_HI_B2) = 0x02;
        REG8(PDI_DCDC_PID_LO_B2) = 0xa2;

        REG8(PDI_DCDC_CLK_SET0) = 0x52;     //CLK_SET0.clk_sel_pwm=1 ; CLK_SET0.mdll_m=0x12
    }
    REG8(PDI_DCDC_MDLL_DEVIDER_WO) = 0x00;     //MDLL_DEVIDER.divider = 00 (divide by 1)

    //For GRX200 use 0x5B, for VRX200 use 0x8B
    //FixMe: For HNX176 should use the reset value =0x47?
    REG8(PDI_DCDC_NON_OV_DELAY_WO) = 0x8B;

    REG8(PDI_DCDC_DUTY_CYCLE_MAX_SAT) = 0x6C;     //DUTY_CYCLE_SAT_MAX = 108 (0x6C)
    REG8(PDI_DCDC_DUTY_CYCLE_MIN_SAT) = 0x3C;     //DUTY_CYCLE_SAT_MIN = 60

    REG8(PDI_DCDC_CONF_TEST_DIG) &=(u8)(~(1<<5)); //FREEZE_PID=0

    REG8(PDI_DCDC_CLK_SET0) |= 0x40; // Set bit 6, select PWM
    //FixMe: Do we need this? HNX176 SAS say that the field is reserved and undefined
    //REG8(PDI_DCDC_CLK_SET1_WO) |= 0x20;
    //FixMe: Do we need this? HNX176 SAS say that should't be programmed
    REG8(PDI_DCDC_PWM0) = 0xF9; // 249 in decimal

    //orig=REG8(PDI_DCDC_DIG_REF_WO);
    orig = 0x7F;    // Use the reset value. It cannot be read from the PDI_DCDC_DIG_REF_WO register
    if (orig >= value)
        adjCount = orig - value;
    else
        adjCount = value - orig;

    printf("Start DCDC for Core voltage adjustements: ");
    for (i=0; i<adjCount; i++)
    {
        printf(".");
        mdelay(1);
        if (orig >= value)
            REG8(PDI_DCDC_DIG_REF_WO) = orig - i;
        else
            REG8(PDI_DCDC_DIG_REF_WO) = orig + i;
    }

    //displayMemory8bit(PDI_DCDC_BASE);

    printf(" Done.\n");
}

int checkboard (void)
{
	#ifdef CONFIG_DEBUG
	printf("%s %s\n", __func__, __FILE__);
	#endif
    printf("CLOCK CPU %dM RAM %dM\n",CPU_CLOCK_RATE/1000000,RAM_CLOCK_RATE/1000000);

    *EBU_ADDR_SEL_0 = 0x10000031; /*has to do this or nand probing will hang*/
    *EBU_CON0 = CONFIG_EBU_BUSCON0;

	#ifdef CONFIG_DEBUG
    printf("finished %s %s\n", __func__, __FILE__);
	#endif
    return 0;
}


#ifdef CONFIG_NAND_FLASH
void nand_gpio_init(void)
{
	#ifdef CONFIG_DEBUG
	printf("%s %s\n", __func__, __FILE__);
	#endif
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
    
	//AT: FixMe Is this needed for HN1? in UGw4.3.1 was not present
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
    #ifdef CONFIG_DEBUG
	printf("%s %s\n", __func__, __FILE__);
    #endif
//	/* old version from VR9 */
//   /* enable SSC1 */
//        //*DANUBE_PMU_PM_GEN |= DANUBE_PMU_PM_GEN_EN11;
//
//        /* SSC1 Ports */
//        /* p0.15 SPI_CS1(EEPROM), P0.13 SPI_CS3, P0.9 SPI_CS5, P0.10 SPI_CS4, P0.11 SPI_CS6 */
//        /* Set p0.10 to alternative 01, others to 00 (In/OUT)*/
//        *(BSP_GPIO_P0_DIR) = (*BSP_GPIO_P0_DIR)|(0xAE00);
//
//        *(BSP_GPIO_P0_ALTSEL0) = (((*BSP_GPIO_P0_ALTSEL0)&(~0x0400)) & (~(0xAA00)));
//        *(BSP_GPIO_P0_ALTSEL1) = (((*BSP_GPIO_P0_ALTSEL1)|(0x0400)) & (~(0xAA00)) );
//
//        *(BSP_GPIO_P0_OD) = (*BSP_GPIO_P0_OD)|0xAE00;
//
//        /* p1.6 SPI_CS2(SFLASH), p1.0 SPI_DIN, p1.1 SPI_DOUT, p1.2 SPI_CLK */
//        *(BSP_GPIO_P1_DIR) = ((*BSP_GPIO_P1_DIR)|(0x46))&(~1);
//        *(BSP_GPIO_P1_ALTSEL0) = ((*BSP_GPIO_P1_ALTSEL0)|(0x47));
//        *(BSP_GPIO_P1_ALTSEL1) = (*BSP_GPIO_P1_ALTSEL1)&(~0x47);
//        *(BSP_GPIO_P1_OD) = (*BSP_GPIO_P1_OD)|0x0046;

    u32 regVal;

    // Read B13 of RCU_RST to find the operation mode.
    regVal = (*BSP_RCU_RST_SR) & (1<<13);

    if (regVal == 0)
    {
        // The mapping of the signals is the same as it was for VR9
        /* SSC1 Ports */
        /* p0.15 SPI_CS1(EEPROM), P0.13 SPI_CS3, P0.9 SPI_CS5, P0.10 SPI_CS4, P0.11 SPI_CS6 */
        /* Set p0.10 to alternative 01, others to 00 (In/OUT)*/
        *(BSP_GPIO_P0_DIR) = (*BSP_GPIO_P0_DIR)|(0xAE00);

//        *(BSP_GPIO_P0_ALTSEL0) = (((*BSP_GPIO_P0_ALTSEL0)&(~0x0400)) & (~(0xAA00)));
//        *(BSP_GPIO_P0_ALTSEL1) = (((*BSP_GPIO_P0_ALTSEL1)|(0x0400)) & (~(0xAA00)) );

        //p0.15=CS1=(1,0)   p0.13=CS3=(0,1)   p0.11=CS6=(1,1)   p0.10=CS4=(0,1)   p0.9=CS5=(0,1)
        *(BSP_GPIO_P0_ALTSEL0) = ((((((*BSP_GPIO_P0_ALTSEL0) |( (0x8000))) &(~(0x2000))) |( (0x0800))) &(~(0x0400))) &(~(0x0200)));
        *(BSP_GPIO_P0_ALTSEL1) = ((((((*BSP_GPIO_P0_ALTSEL1) &(~(0x8000))) |( (0x2000))) |( (0x0800))) |( (0x0400))) |( (0x0200)));

        *(BSP_GPIO_P0_OD) = (*BSP_GPIO_P0_OD)|0xAE00;

        /* p1.6 SPI_CS2(SFLASH), p1.0 SPI_DIN, p1.1 SPI_DOUT, p1.2 SPI_CLK */
        *(BSP_GPIO_P1_DIR) = ((*BSP_GPIO_P1_DIR)|(0x46))&(~1);
        *(BSP_GPIO_P1_ALTSEL0) = ((*BSP_GPIO_P1_ALTSEL0)|(0x47));
        *(BSP_GPIO_P1_ALTSEL1) = (*BSP_GPIO_P1_ALTSEL1)&(~0x47);
        *(BSP_GPIO_P1_OD) = (*BSP_GPIO_P1_OD)|0x0046;
    }
    else
    {
        // The new mapping uses P3.0 as SPI_DOUT, P3.1 as SPI_DIN and P0.13 as SPI_CS3.
        //The rest of the signals are selected to go out using the P3.2 out, alternate function 1

        //P0.13 is SPI_CS3. Alternate function 2 ="0,1". Direction=output.
        *(BSP_GPIO_P0_ALTSEL0) =  (*BSP_GPIO_P0_ALTSEL0)&(~0x2000);
        *(BSP_GPIO_P0_ALTSEL1) =  (*BSP_GPIO_P0_ALTSEL1)| (0x2000);
        *(BSP_GPIO_P0_DIR)     =  (*BSP_GPIO_P0_DIR)    | (0x2000);
        *(BSP_GPIO_P1_OD)      =  (*BSP_GPIO_P1_OD)     | (0x2000);

        //P3.0 is SPI_DOUT. Alternate function 2 ="0,1". Direction=output.
        *(BSP_GPIO_P3_ALTSEL0)    =  (*BSP_GPIO_P3_ALTSEL0)&(~0x0001);
        *(BSP_GPIO_P3_ALTSEL1)    =  (*BSP_GPIO_P3_ALTSEL1)| (0x0001);
        *(BSP_GPIO_P3_DIR)        =  (*BSP_GPIO_P3_DIR)    | (0x0001);
        *(BSP_GPIO_P3_OD)         =  (*BSP_GPIO_P3_OD)     | (0x0001);

        //P3.1 is SPI_DIN. Alternate function 2 ="0,1". Direction=input.
        *(BSP_GPIO_P3_ALTSEL0)    =  (*BSP_GPIO_P3_ALTSEL0)&(~0x0002);
        *(BSP_GPIO_P3_ALTSEL1)    =  (*BSP_GPIO_P3_ALTSEL1)| (0x0002);
        *(BSP_GPIO_P3_DIR)        =  (*BSP_GPIO_P3_DIR)    &(~0x0002);
        *(BSP_GPIO_P3_OD)         =  (*BSP_GPIO_P3_OD)     | (0x0002);

        //P3.2 is for SPI_CLK, SPI_CS1, SPI_CS2, SPI_CS4, SPI_CS5_SPI_CS6. Alternate function 1 ="1,0". Direction=output.
        *(BSP_GPIO_P3_ALTSEL0)    =  (*BSP_GPIO_P3_ALTSEL0)| (0x0004);
        *(BSP_GPIO_P3_ALTSEL1)    =  (*BSP_GPIO_P3_ALTSEL1)&(~0x0004);
        *(BSP_GPIO_P3_DIR)        =  (*BSP_GPIO_P3_DIR)    | (0x0004);
        *(BSP_GPIO_P3_OD)         =  (*BSP_GPIO_P3_OD)     | (0x0004);
    }

    #ifdef CONFIG_DEBUG
    {
        if (regVal == 0)
            printf("Mode 0 \n");
        else
            printf("Mode 1 \n");
    }
    #endif


	return 1;
}
#endif

#ifdef CONFIG_TUNE_DDR
#if defined(CONFIG_BOOT_FROM_NAND)
extern nand_info_t nand_info[]; 
//extern int nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t * retlen, const u_char * buf);

void save_ddr_param(void)
{   
	   ulong   ddr_magic=0x88888888;
	   ulong erase_addr1=0, erase_addr2=0;
	   ulong  ecc;
	   ulong  buffer[6];
	   erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR; 
	   erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;
	   nand_info_t *nand;
	   nand_write_options_t opts;
	   nand = &nand_info[0];
	   u64 srcLen=24;
       
       #ifdef CONFIG_DEBUG
       printf("%s %s\n", __func__, __FILE__);
       #endif

	   if(*(u32*)0xBF28FF20!=0x2)  /*0xBE1A5F20 contains the tuning status*/
	    {
		    /*no new parameter, return immediately*/
		    return;
	    }
	   memcpy ((u8*)buffer,&ddr_magic,4);
	   memcpy ((u8*)(buffer+1),(u8*)0xBF401270,4);
	   memcpy ((u8*)(buffer+2),(u8*)0xBF401280,4);
	   memcpy ((u8*)(buffer+3),(u8*)0xBF4012B0,4);
	   memcpy ((u8*)(buffer+4),(u8*)0xBF4012C0,4);
	   ecc=(*(u32*)0xBF401270)^(*(u32*)0xBF401280)^(*(u32*)0xBF4012B0)^(*(u32*)0xBF4012C0);
	   memcpy ((u8*)(buffer+5),&ecc,4); 
	   
	   nand_write_partial(&nand_info[0], IFX_CFG_FLASH_DDR_CFG_START_ADDR, &srcLen, (u_char*)buffer);
	   return;
}
#else /*BOOT from SPI*/
void save_ddr_param(void)
{
	 ulong   ddr_magic=0x88888888;
	 ulong erase_addr1=0, erase_addr2=0;
	 ulong  ecc;
	 ulong  buffer[6];
	 static struct spi_flash *flash_spi;
	 flash_spi = spi_flash_probe(CONFIG_ENV_SPI_BUS, CONFIG_ENV_SPI_CS,
            CONFIG_ENV_SPI_MAX_HZ, CONFIG_ENV_SPI_MODE);
	
	 erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR; 
	 erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;

     #ifdef CONFIG_DEBUG
     printf("%s %s\n", __func__, __FILE__);
     #endif
	 
	 if(*(u32*)0xBF28FF20!=0x2)   /*0xBE1A5F20 contains the tuning status*/
	    {
		    /*no new parameter, return immediately*/
#ifdef CONFIG_FASTER_UART
	        printf("Skip to update ddr param in flash.\n");
			printf("Addr=BF28FF20 Val=%x \n", (*(u32*)0xBF28FF20) );
			printf("Addr=BF28FF10 Val=%x \n", (*(u32*)0xBF28FF10) );
			printf("Addr=BF28FF14 Val=%x \n", (*(u32*)0xBF28FF14) );
			printf("Addr=BF28FF18 Val=%x \n", (*(u32*)0xBF28FF18) );
			printf("Addr=BF28FF1C Val=%x \n", (*(u32*)0xBF28FF1C) );
#endif
		    return;
	    }
	 
	 memcpy ((u8*)buffer,&ddr_magic,4);
	 memcpy ((u8*)(buffer+1),(u8*)0xBF401270,4);
	 memcpy ((u8*)(buffer+2),(u8*)0xBF401280,4);
	 memcpy ((u8*)(buffer+3),(u8*)0xBF4012B0,4);
	 memcpy ((u8*)(buffer+4),(u8*)0xBF4012C0,4);
	 ecc=(*(u32*)0xBF401270)^(*(u32*)0xBF401280)^(*(u32*)0xBF4012B0)^(*(u32*)0xBF4012C0);
	 memcpy ((u8*)(buffer+5),&ecc,4);
 
	 spi_flash_write(flash_spi, erase_addr1, 24, (char *)buffer);   
	 printf("saved ddr param in flash!\n");    
	    
     return;
}
#endif
#endif

extern int hn1_eth_initialize(bd_t * bis);

int board_eth_init(bd_t *bis)
{
   if (hn1_eth_initialize(bis)<0)
             return -1;

	return 0;
}
						 
