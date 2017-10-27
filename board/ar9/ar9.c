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
#include <asm/ar9.h>
#include <environment.h>
#include <nand.h>
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


#ifdef CONFIG_NAND_FLASH
void nand_gpio_init(void)
{
  *AMAZON_S_GPIO_P1_ALTSEL0 = *AMAZON_S_GPIO_P1_ALTSEL0 | (1<<7) | (1<<8);
  *AMAZON_S_GPIO_P1_ALTSEL1 = *AMAZON_S_GPIO_P1_ALTSEL1 & ~(1<<7) & ~ (1<<8);
  *AMAZON_S_GPIO_P1_DIR = *AMAZON_S_GPIO_P1_DIR | (1<<7) | (1<<8);
  *AMAZON_S_GPIO_P1_OD = *AMAZON_S_GPIO_P1_OD | (1<<7) | (1<<8) ;
  (*AMAZON_S_GPIO_P0_ALTSEL0) = (*AMAZON_S_GPIO_P0_ALTSEL0) | (1<<13); //Set GPIO 13 to ND_ALE
  (*AMAZON_S_GPIO_P0_ALTSEL1) = (*AMAZON_S_GPIO_P0_ALTSEL1)  & ~(1<<13);
  (*AMAZON_S_GPIO_P0_OD) = (*AMAZON_S_GPIO_P0_OD) | (1<<13) ;
  (*AMAZON_S_GPIO_P0_DIR) = (*AMAZON_S_GPIO_P0_DIR) | (1<<13) ; //set GPIO 13 to output
   //USE GPIO48 and 49 for FL_RD and
   //and NAND_READY
  *AMAZON_S_GPIO_P3_ALTSEL0 = *AMAZON_S_GPIO_P3_ALTSEL0 | (3<<0) ;
  *AMAZON_S_GPIO_P3_ALTSEL1 = *AMAZON_S_GPIO_P3_ALTSEL1 & ~(3<<0);
  *AMAZON_S_GPIO_P3_DIR     = *AMAZON_S_GPIO_P3_DIR | (1<<1);
  *AMAZON_S_GPIO_P3_DIR     = *AMAZON_S_GPIO_P3_DIR & ~(1<<0);
  *AMAZON_S_GPIO_P3_OD      = *AMAZON_S_GPIO_P3_OD | (1<<1);

  /*pull up GPIO 48 for ready signal*/
  *AMAZON_S_GPIO_P3_PUDSEL = *AMAZON_S_GPIO_P3_PUDSEL | 1;
  *AMAZON_S_GPIO_P3_PUDEN  = *AMAZON_S_GPIO_P3_PUDEN | 1;

}
#endif


#ifdef CONFIG_LANTIQ_SPI

#define BIT(X)       (1 << (X))
#define SPI_MODULO   16
#define SPI_CS4     (10 & 0xF)  /* P0.10 */
#define SPI_DIN     (16 & 0xF)  /* P1.0 */
#define SPI_DOUT    (17 & 0xF)  /* P1.1 */
#define SPI_CLK     (18 & 0xF)  /* P1.2 */

int spi_gpio_init(unsigned int cs)
{
     /* SSC0 Ports */
	 /* P0.10 as CS4 for flash or eeprom depends on jumper */
	 /* P0.10 ALT0= 0, ALT1=1, DIR=1 */
	 *(AMAZON_S_GPIO_P0_DIR)     |= BIT(SPI_CS4);
	 *(AMAZON_S_GPIO_P0_ALTSEL0) &= ~ BIT(SPI_CS4);
	 *(AMAZON_S_GPIO_P0_ALTSEL1) |= BIT(SPI_CS4);
	 *(AMAZON_S_GPIO_P0_OD)      |= BIT(SPI_CS4);

	 /* p1.0 SPI_DIN, p1.1 SPI_DOUT, p1.2 SPI_CLK */
	 *(AMAZON_S_GPIO_P1_DIR)      = ((*AMAZON_S_GPIO_P1_DIR)| BIT(SPI_DOUT) | BIT(SPI_CLK))&(~ BIT(SPI_DIN));
	 *(AMAZON_S_GPIO_P1_ALTSEL0) |= (BIT(SPI_DOUT) | BIT(SPI_CLK) | BIT(SPI_DIN));
	 *(AMAZON_S_GPIO_P1_ALTSEL1) &= ~(BIT(SPI_DOUT) | BIT(SPI_CLK) | BIT(SPI_DIN));
	 *(AMAZON_S_GPIO_P1_OD)      |= (BIT(SPI_DOUT) | BIT(SPI_CLK));
	  return 1;
}
#endif
																  

phys_size_t initdram(int board_type)
{
    return (1024*1024*CONFIG_IFX_MEMORY_SIZE);
}
	


int checkboard (void)
{
        printf("CLOCK CPU %dM RAM %dM\n",CPU_CLOCK_RATE/1000000,RAM_CLOCK_RATE/1000000);
        return 0;
}


int board_early_init_f(void)
{
        (*AMAZON_S_EBU_ADDSEL0) = CONFIG_EBU_ADDSEL0;
        (*AMAZON_S_EBU_BUSCON0) = CONFIG_EBU_BUSCON0;
		
   return 0;
}
																		


int board_eth_init(bd_t *bis)
{
   if (ar9_eth_initialize(bis)<0)
                   return -1;
				   
   return 0;
}

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
     if(*(u32*)0xbe1a7f20!=0x2)  /*0xBE1A5F20 contains the tuning status*/
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
     memcpy ((u8*)(buffer+1),(u8*)0xbe1a7f10,16);
     ecc=(*(u32*)0xbe1a7f10)^(*(u32*)0xbe1a7f14)^(*(u32*)0xbe1a7f18)^(*(u32*)0xbe1a7f1c);
     memcpy ((u8*)(buffer+5),&ecc,4);

     flash_write((char *)buffer, IFX_CFG_FLASH_DDR_CFG_START_ADDR, 24);/*one magic word,4 parameters,1cc,24bytes*/

     //(void) flash_sect_protect (1, erase_addr1, erase_addr2-1);

     return;
}
#elif defined(CONFIG_BOOT_FROM_NAND)
//extern nand_info_t nand_info[];
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
       u64 srcLen=24;
       //nand_info_t *nand;
       //nand_write_options_t opts;
       //nand = &nand_info[0];
       if(*(u32*)0xbe1a7f20!=0x2)  /*0xBE1A5F20 contains the tuning status*/
        {
            /*no new parameter, return immediately*/
            return;
        }
       memcpy ((u8*)buffer,&ddr_magic,4);
       memcpy ((u8*)(buffer+1),(u8*)0xbe1a7f10,4);
       memcpy ((u8*)(buffer+2),(u8*)0xbe1a7f14,4);
       memcpy ((u8*)(buffer+3),(u8*)0xbe1a7f18,4);
       memcpy ((u8*)(buffer+4),(u8*)0xbe1a7f1c,4);
       ecc=(*(u32*)0xbe1a7f10)^(*(u32*)0xbe1a7f14)^(*(u32*)0xbe1a7f18)^(*(u32*)0xbe1a7f1c);
       memcpy ((u8*)(buffer+5),&ecc,4);

       printf("save ddr parameters to flash..\n");
       nand_write_partial(&nand_info[0], IFX_CFG_FLASH_DDR_CFG_START_ADDR, &srcLen, (u_char*)buffer);

     return;
}
#elif defined(CONFIG_BOOT_FROM_SPI)
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
     if(*(u32*)0xbe1a7f20!=0x2)  /*0xBE1A5F20 contains the tuning status*/
        {
            /*no new parameter, return immediately*/
            return;
        }

     memcpy ((u8*)buffer,&ddr_magic,4);
     memcpy ((u8*)(buffer+1),(u8*)0xbe1a7f10,16);
     ecc=(*(u32*)0xbe1a7f10)^(*(u32*)0xbe1a7f14)^(*(u32*)0xbe1a7f18)^(*(u32*)0xbe1a7f1c);
     memcpy ((u8*)(buffer+5),&ecc,4);
     spi_flash_write(flash_spi, erase_addr1, 24, (char *)buffer);
     printf("saved ddr param in flash!\n");

   return;
}
#else
void save_ddr_param(void)
{
   return;
}
#endif
#endif

