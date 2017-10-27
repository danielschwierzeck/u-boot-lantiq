#include <config.h>
#include <common.h>
#include <command.h>
#include <asm/addrspace.h>
#include <asm/ar9.h>
#include <environment.h>
#include <nand.h>


#define MC_MODUL_BASE       0xBF800000
#define MC_ERRCAUSE     MC_MODUL_BASE+0x0010
#define MC_ERRADDR      MC_MODUL_BASE+0x0020
#define MC_CON            MC_MODUL_BASE+0x0060
#define MC_SRAM_ENABLE      0x00000004
#define MC_SDRAM_ENABLE     0x00000002
#define MC_DDRRAM_ENABLE    0x00000001
#define MC_DDR_MODUL_BASE   0xBF801000

#define MC_DC03     MC_DDR_MODUL_BASE+0x0030
#define MC_DC15   MC_DDR_MODUL_BASE+0x00F0
#define MC_DC21     MC_DDR_MODUL_BASE+0x0150
#define MC_DC22     MC_DDR_MODUL_BASE+0x0160
#define MC_DC24     MC_DDR_MODUL_BASE+0x0180

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
									  

void *malloc(unsigned int size)
{
   
    return NULL;
}

static void nand_read_page(u32 page_addr, u32 dest_addr)
{
   int i;
   u8 *tmp;
   u8 col_addr_num;
     u8 page_addr_num;

   if(CONFIG_NAND_PAGE_SIZE<=0x200){
     col_addr_num=1;

     if(CONFIG_NAND_FLASH_SIZE<32){
        page_addr_num=2;
      }else
        page_addr_num=3;
   }else{
     col_addr_num=2;

     if(CONFIG_NAND_FLASH_SIZE<128){
          page_addr_num=2;
      }else{
        page_addr_num=3;
      }
   }
   NAND_CE_SET;

   NAND_SETCLE;
   NAND_WRITE(WRITE_CMD,0);
   NAND_CLRCLE;
   NAND_SETALE;
   for(i=0;i<col_addr_num;i++){
    NAND_WRITE(WRITE_ADDR,0);
  }
   for(i=0;i<page_addr_num;i++){
     NAND_WRITE(WRITE_ADDR,(u8)((page_addr>>(i*8)) & 0xff ));
   }
   NAND_CLRALE;

   NAND_SETCLE;
   if(CONFIG_NAND_PAGE_SIZE>0x200){
     NAND_WRITE(WRITE_CMD,0x30);
   }
  NAND_CLRCLE;
  while(!NAND_READY){}

   /* Read page */
   tmp = (u8*)dest_addr;
   for (i = 0; i < CONFIG_NAND_PAGE_SIZE; i++)
   {
     NAND_READ(READ_DATA, *tmp++);
   }
   NAND_CE_CLEAR;

   while(!NAND_READY){}
}

void nand_spl_init(void)
{
	ulong  buffer[6];
  u8    page_buf[CONFIG_NAND_PAGE_SIZE];
  ulong ddr_magic=0x88888888;
  ulong erase_addr1=0, erase_addr2=0;
  ulong  ecc;
  int i;
  
  erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR;
  erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;

  serial_init();

  buffer[0] = 0;

  asm("sync");
  nand_read_page(((IFX_CFG_FLASH_DDR_CFG_END_ADDR+1)/CONFIG_NAND_PAGE_SIZE)-1,page_buf);
  asm("sync");
  
  for(i=0;i<6;i++){
    buffer[i] = *(volatile u32*)(page_buf+CONFIG_NAND_PAGE_SIZE-24+i*4); /*last 24 bytes of 16k bytes*/
  }
  if(buffer[0]==ddr_magic)
       {
             ecc=buffer[1]^buffer[2]^buffer[3]^buffer[4];
               if(ecc!=buffer[5]){
                  REG32(0xBe1a7f20)=0xff;
                }else{
                    REG32(0xBe1a7f20)=0;
                }
         }
     else{
        REG32(0xBe1a7f20)=0xff;
    }

        /* Clear Error log registers */
        REG32(MC_ERRCAUSE)= 0;
        REG32(MC_ERRADDR) = 0;
      asm("sync");
        /* Enable DDR module in memory controller */
        REG32(MC_CON)= REG32(MC_CON)|MC_DDRRAM_ENABLE;
        asm("sync");
        if(REG32(0xBe1a7f20)==0xff){
          REG32(MC_DC21)= 0;
          REG32(MC_DC22)=0;
        }else{
          REG32(MC_DC15)= buffer[1];
          REG32(MC_DC21)= buffer[2];
        REG32(MC_DC22)= buffer[3];
          REG32(MC_DC24)= buffer[4];
      }
      asm("sync");
        REG32(MC_DC03) = 0x00000100;
      while((REG32(0xbf800070)& 0x08)!=0x08);

     asm("sync");
     tune_ddr();
     
	 asm("sync");
     nand_boot();
	
}
