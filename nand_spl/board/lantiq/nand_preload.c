#include <common.h>


static void read_page(u32 page_addr, u32 dest_addr)
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
   NAND_WRITE(WRITE_CMD,0);
   IFX_NAND_CTL_SETALE;
   for(i=0;i<col_addr_num;i++){
    NAND_WRITE(WRITE_ADDR,0);
  }
   for(i=0;i<page_addr_num;i++){
   	 NAND_WRITE(WRITE_ADDR,(u8)((page_addr>>(i*8)) & 0xff ));
   } 
   IFX_NAND_CTL_CLRALE;
   
   if(CONFIG_NAND_PAGE_SIZE>0x200){
     NAND_WRITE(WRITE_CMD,0x30);
   } 
   
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

#define FILE_SIZE CONFIG_NAND_SPL_BLOCK_SIZE
#define STARTING_ADDRESS CONFIG_NAND_PRELOAD_TEXT_BASE+0x200

void nand_init(void)
{
   int i;
   for(i=0;i<(FILE_SIZE/CONFIG_NAND_PAGE_SIZE+1);i++){    
    read_page(i,STARTING_ADDRESS+CONFIG_NAND_PAGE_SIZE*i);   	 
   }

   // jump start
   void (*start)(void);
   
  
   start = (void *)CONFIG_NAND_SPL_TEXT_BASE;
   start();

}



