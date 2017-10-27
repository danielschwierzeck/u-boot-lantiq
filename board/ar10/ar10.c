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
#include <environment.h>
#include <nand.h>
#include <spi_flash.h>
#include <asm/ar10.h>
#include "ddr.h"

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

#ifdef CONFIG_DRIVER_GRX390
#define PPE_SW_WLAN_RFUSE_BASE_ADDRESS  0x1F1073B0 + 0xA0000000
#define NO_OF_FUSES 					6
#define RCU_OFFSET   					0xBF203000
#define RST_REQ      					(RCU_OFFSET + 0x0010)
#define RST_STAT2						(RCU_OFFSET + 0x0024)
#define RST_REQ2                        (RCU_OFFSET + 0x0048)
#endif /* CONFIG_DRIVER_GRX390 */

#ifdef CONFIG_AR10_PROGRAM_AFE_FUSE
/******************************************************************************
 * FOR DFE and AFE
  ******************************************************************************/
#define DFE_BASE_ADDR         0xBE116000
#define mei_dbg_deco_c        (DFE_BASE_ADDR + 0x00000030)
#define mei_fr_arcint_c       (DFE_BASE_ADDR + 0x0000001C)
#define mei_dbg_master_c      (DFE_BASE_ADDR + 0x0000003C)
#define mei_dbg_waddr_c       (DFE_BASE_ADDR + 0x00000024)
#define mei_dbg_raddr_c       (DFE_BASE_ADDR + 0x00000028)
#define mei_dbg_data_c        (DFE_BASE_ADDR + 0x0000002C)

#define AFE_CTRL          0xbf107360

#define ADSL_BASE 0x20000
#define CRI_BASE          ADSL_BASE + 0x11F00
#define CRI_CCR0          CRI_BASE + 0x00
#define CRI_CCR1          CRI_BASE + 0x01*4
#define CRI_UPDCTL        CRI_BASE + 0x0D*4
#define CRI_EVENT0        CRI_BASE + 0x10*4
#define CRI_EVENT1        CRI_BASE + 0x11*4
#define CRI_EVENT2        CRI_BASE + 0x12*4
//#define REG32(addr)          *((volatile u32 *)(addr))
// Register Definitions
#define aux_access 0x0
#define dmp_access 0x1 // or 0x2
#define core_access 0x3

#define iri_i_enable    0x32000
#define sty_smode   0x3c004

#define afe_tcr_0   0x3c0dc
#define afe_addr_addr   0x3c0e8
#define afe_rdata_addr  0x3c0ec
#define afe_wdata_addr  0x3c0f0
#define afe_config  0x3c0f4
#define afe_serial_cfg  0x3c0fc


u32 mei = 0x1;
u32 jtag = 0x0;
u32 dmp_core_access = 0x2;


void mei_master(u32 mode){
  REG32(mei_dbg_master_c) = mode; // MEI as the master
};

void poll_status(void){
  while( (REG32(mei_fr_arcint_c) & 0x20) != 0x20 ){};
};

void mei_dmp_acc(void){
   REG32(mei_dbg_deco_c) = dmp_access;
};

void mei_aux_acc(void)
{
    REG32(mei_dbg_deco_c) = aux_access;
};


u32 ReadARCmem(u32 addr){
   u32 data;
   mei_master(mei);
   mei_dmp_acc();
   REG32(mei_dbg_raddr_c) = addr;
   poll_status();
   data = REG32(mei_dbg_data_c);
   mei_master(jtag);
   return data;
};

void WriteARCmem(u32 addr, u32 data){
   mei_master(mei);
   mei_dmp_acc();
   REG32(mei_dbg_waddr_c) = addr;
   REG32(mei_dbg_data_c) = data;
   poll_status();
   mei_master(jtag);
};

u32 afe_reg_read(u32 addr)
{
    WriteARCmem(CRI_EVENT2,0x20);
    WriteARCmem(afe_addr_addr,addr);
    WriteARCmem(afe_rdata_addr,0x0);
    while((ReadARCmem(CRI_EVENT2)&0x20)!=0x20);
    return(ReadARCmem(afe_rdata_addr));
}

u16 afe_reg_write(u32 addr,u32 data)
{
    WriteARCmem(afe_addr_addr,addr);
    WriteARCmem(afe_wdata_addr,data);
    while((ReadARCmem(CRI_EVENT2)&0x20)!=0x20);
    return 0;
}


u32 ReadARCreg(u32 addr)
{
    u32 data;
    mei_master(mei);
    mei_aux_acc();
    REG32(mei_dbg_raddr_c) = addr;
    poll_status();
    data = REG32(mei_dbg_data_c);
    mei_master(jtag);
    return data;
};

void WriteARCreg(u32 addr, u32 data)
{
    mei_master(mei);
    mei_aux_acc();
    REG32(mei_dbg_waddr_c) = addr;
    REG32(mei_dbg_data_c) = data;
    poll_status();
    mei_master(jtag);
};


u16 enable_afe()
{
    u32 read_data,i;
    REG32(AR10_PMU_PWDCR) &=0xffffffdf;
	REG32(AR10_PMU_PWDCR1) |=0x10e00220;

	REG32(AR10_PMU_PWDCR) &=0xfffffddf;
 
    WriteARCreg(CRI_CCR0, 0x10);

	WriteARCmem(0x32010, 0xf);

    //asc_puts("Enabling AFE....\n");
    /* Start the clock */
    WriteARCmem(CRI_UPDCTL, 0x08);
    
	WriteARCmem(CRI_CCR0, 0x14);
    WriteARCmem(CRI_CCR1, 0x500);
    WriteARCmem(afe_config,0x01c8);
    WriteARCmem(afe_serial_cfg,0x6); 
    WriteARCmem(afe_tcr_0,0x5);
    //Take afe out of reset
    WriteARCmem(afe_config,0x0c0);
    return(0);

}

void config_afe(void)
{
    u32 bias, bgp, dac_ftrim;
    u32 ldo, data;

    /*to make sure that AFE hard-macro registers are not reset upon soft reset*/
    REG32(AR10_RCU_RST_PPE_CONF)= (REG32(AR10_RCU_RST_PPE_CONF) & ~0x1e)|0x18;

    enable_afe();
   
	/*get BIAS & BGP from AFE_CTRL register*/
    dac_ftrim = (REG32(AFE_CTRL)>>8) & 0x0f;
	bias = REG32(AFE_CTRL)&0x1f;
    bgp  = (REG32(AFE_CTRL)>>5) & 0x7;
    /*write to BIAS_TRIM*/
	data = bias | (bgp<<8);
	afe_reg_write(0x31, data);

    data = afe_reg_read(0x28);
	data = (data & ~(0x0f))|(dac_ftrim);
	afe_reg_write(0x28, data);

    /*get 3 LDO bits from fuse string*/
	ldo = (REG32(0xBF1073A4)>>16) & 0x7;
    
	/*write to afe reg offset 0x0e, bit 12 to 14*/
    data = afe_reg_read(0x0e);
    data = (data & ~(0x7<<12))|(ldo<<12);
    afe_reg_write(0x0e, data);

}
#endif 


/**********************************************************************************/

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
     return 1;
}


void show_boot_progress(int arg)
{
  return;
}

void config_dcdc()
{
   REG8(DCDC_2V5_BASE+DCDC_PWM0_OFFSET)=0x8f;
}

int checkboard (void)
{

    printf("CLOCK CPU %dM RAM %dM\n",CPU_CLOCK_RATE/1000000,RAM_CLOCK_RATE/1000000);
#ifdef CONFIG_AR10_DDR_8BIT
    printf("8 Bit RAM\n");
#else
    printf("16 Bit RAM\n");
#endif
  
    //*AR10_PMU_CLKGCR1_A |= ((1<<10)|(1<<5)) ; /*power up EBU*/ 
    REG32(0xBF102024) = REG32(0xBF102020) | 0x00000400; //writing 1 in the PMU_CLKGCR1_A_ADDR[10]
	REG32(0xBF102024) = REG32(0xBF102020) | 0x00000020; //writing 1 in the PMU_CLKGCR1_A_ADDR[5]
		
	*AR10_EBU_CLC = 0;
    *AR10_EBU_ADDR_SEL_0 = 0x10000011;
    *AR10_EBU_ADDR_SEL_1 = 0x14000021;  
#ifdef CONFIG_AR10_PROGRAM_AFE_FUSE
    config_afe();
#endif

#ifdef CONFIG_AR10_DCDC_2V5_PWM0    
	config_dcdc();
#endif	

#ifdef CONFIG_DRIVER_GRX390
    // disable dying gasp for grx390
    REG32(AR10_RCU_USB1_Cfg) &= ~(1 << 3);
    //set to 2.5V regulator output
    REG32(AR10_RCU_USB1_Cfg) |= (1 << 6);
#else 
	if ((REG32(AR10_CHIPID) & 0x1)) {
		REG32(AR10_PMU_CLKGCR1_B) |= (1 << 26);
		REG32(AR10_PMU_CLKGCR2_B) |= (0x4e000000);
		REG32(AR10_PMU_ANALOGCR_B) |= (1 << 10);
	} 
#endif

#ifdef CONFIG_DRIVER_GRX390 
	switch_mem_repair();
#endif

    return 0;
}


#ifdef CONFIG_NAND_FLASH
void nand_gpio_init(void)
{
	 /* GPIO 13 NAND_ALE*/
	 *AR10_GPIO_P0_DIR     |= 1 << 13;
	 *AR10_GPIO_P0_ALTSEL0 |= 1 << 13;
	 *AR10_GPIO_P0_ALTSEL1 &= ~(1 << 13);
	 *AR10_GPIO_P0_OD      |= 1 << 13;
	
	 /*GPIO 24 NAND_CLE */
	 *AR10_GPIO_P1_DIR     |= 1 << 8;
	 *AR10_GPIO_P1_ALTSEL0 |= 1 << 8;
	 *AR10_GPIO_P1_ALTSEL1 &= ~(1 << 8);
	 *AR10_GPIO_P1_OD      |= 1 << 8;
	 
	 /*GPIO 48, NAND Ready_Busy*/
	 /*GPIO 49, NAND_RD*/
	 /*GPIO 50, NAND_D1*/
	 /*GPIO 51, NAND_D0*/
	 /*GPIO 52, NAND_D2*/
	 /*GPIO 53, NAND_D2*/
	 /*GPIO 54, NAND_D6*/
	 /*GPIO 55, NAND_D5*/
	 /*GPIO 56, NAND_D5*/
	 /*GPIO 57, NAND_D3*/
	 /*GPIO 59, NAND_WR*/
	 /*GPIO 60, NAND_WP*/
	 /*GPIO 61, NAND_SE*/
	 *AR10_GPIO_P3_DIR     = 0x3ffe;
	 *AR10_GPIO_P3_ALTSEL0 = 0x3fff;
	 *AR10_GPIO_P3_ALTSEL1 = 0;
	 *AR10_GPIO_P3_OD      = 0x3ffe;
#ifdef CONFIG_NAND_CS0
    /*GPIO 58, NAND_CS*/
     *AR10_GPIO_P3_DIR     |= 1<<10;
	 *AR10_GPIO_P3_ALTSEL0 |= 1<<10;
	 *AR10_GPIO_P3_ALTSEL1 &= ~( 1<<10 );
#else
    /*GPIO 23, NAND_CS1*/
   *AR10_GPIO_P1_DIR     |= 1 << 7;
	 *AR10_GPIO_P1_ALTSEL0 |= 1 << 7;
	 *AR10_GPIO_P1_ALTSEL1 &= ~(1 << 7); 
#endif
}
#endif



#ifdef CONFIG_LANTIQ_SPI

int spi_gpio_init(unsigned int cs)
{

    *AR10_PMU_CLKGCR1_A |=1<<8;
     
	 /*p0.15 SPI_CS1*/
	 *(AR10_GPIO_P0_DIR) |= 1<<15;
	 *(AR10_GPIO_P0_ALTSEL0) |=1<<15;
	 *(AR10_GPIO_P0_ALTSEL1) &=~(1<<15);

     /*P1.0 SPI_DIN*/
	 *(AR10_GPIO_P1_DIR) &=~1;
	 *(AR10_GPIO_P1_ALTSEL0) |=1;
	 *(AR10_GPIO_P1_ALTSEL1) &=~1;

     /*P1.1 SPI_DOUT*/
	 *(AR10_GPIO_P1_DIR) |=1<<1;
	 *(AR10_GPIO_P1_ALTSEL0) |=1<<1;
	 *(AR10_GPIO_P1_ALTSEL1) &=~(1<<1);
			   
     /*P1.2 SPI_CLK*/
	 *(AR10_GPIO_P1_DIR) |=1<<2;
	 *(AR10_GPIO_P1_ALTSEL0) |=1<<2;
	 *(AR10_GPIO_P1_ALTSEL1) &=~(1<<2);
			   
     *AR10_GPIO_P0_OD = (*AR10_GPIO_P0_OD)|0xa000;
	 *AR10_GPIO_P1_OD = (*AR10_GPIO_P1_OD)|0x0047;
	 *AR10_GPIO_P0_OUT = (*AR10_GPIO_P0_OUT)|0x2000;
			 
	 return 1;																					 
}
#endif

#ifdef CONFIG_AR10_LIF_DETECTION 
void detect_lif(void)
{
     u32 lif_type=0;
		 u32 dir, alt0, alt1;
     char lif_type_string[]="LIF_TYPE";
		 char buf[32];
		 dir=*(AR10_GPIO_P0_DIR);
		 alt0=*(AR10_GPIO_P0_ALTSEL0);
		 alt1=*(AR10_GPIO_P0_ALTSEL1);
		 *(AR10_GPIO_P0_DIR) &=~(1<<10);
		 *(AR10_GPIO_P0_ALTSEL0) &=~(1<<10);
		 *(AR10_GPIO_P0_ALTSEL1) &=~(1<<10);
     lif_type = (*(AR10_GPIO_P0_IN) >> 10) & 0x1;
     *(AR10_GPIO_P0_DIR)=dir;
		 *(AR10_GPIO_P0_ALTSEL0)=alt0;
     *(AR10_GPIO_P0_ALTSEL1)=alt1;

		 dir=*(AR10_GPIO_P3_DIR);
		 alt0=*(AR10_GPIO_P3_ALTSEL0);
		 alt1=*(AR10_GPIO_P3_ALTSEL1);
	   *(AR10_GPIO_P3_DIR) &=~(1<<10);
	   *(AR10_GPIO_P3_ALTSEL0) &=~(1<<10);
	   *(AR10_GPIO_P3_ALTSEL1) &=~(1<<10); 
     lif_type |= ((*(AR10_GPIO_P3_IN) >> 10 ) & 0x1)<<1;
		 *(AR10_GPIO_P3_DIR)=dir;
     *(AR10_GPIO_P3_ALTSEL0)=alt0;
     *(AR10_GPIO_P3_ALTSEL1)=alt1;
     printf("lif_type=%d\n",lif_type);
     sprintf(buf, "%d", lif_type);
		 setenv(lif_type_string, buf);
} 
#endif

#ifdef CONFIG_TUNE_DDR

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
    buffer[1]= REG32(0xBE1A7F10);
    buffer[2]= REG32(0xBE1A7F14);
    buffer[3]= REG32(0xBE1A7F18);
    buffer[4]= REG32(0xBE1A7F1C);
    buffer[5]= REG32(CSS_DDR_ECHO_DLL0);
    buffer[6]= REG32(CSS_DDR_ECHO_DLL1);
    buffer[7]= buffer[1]^buffer[2]^buffer[3]^buffer[4]^buffer[5]^buffer[6];
EXIT:
    return ret;
}

#if defined(CONFIG_BOOT_FROM_NAND)
extern nand_info_t nand_info[]; 
//extern int nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t * retlen, const u_char * buf);

void save_ddr_param(void)
{   
	   ulong  buffer[8];
	   u64 srcLen=32;
#ifdef CONFIG_AR10_LIF_DETECTION       
	    detect_lif(); 
#endif	   
           if(!get_tuned_param(&buffer)) return;
           nand_write_partial(&nand_info[0], IFX_CFG_FLASH_DDR_CFG_START_ADDR, &srcLen,(u_char*)buffer);
	   return;
}
#else /*BOOT from SPI*/
void save_ddr_param(void)
{
	 ulong  buffer[8];
	 static struct spi_flash *flash_spi;
#ifdef CONFIG_AR10_LIF_DETECTION       
	    detect_lif(); 
#endif	
	 if(!get_tuned_param(&buffer)) return;
	 flash_spi = spi_flash_probe(CONFIG_ENV_SPI_BUS, CONFIG_ENV_SPI_CS,
            CONFIG_ENV_SPI_MAX_HZ, CONFIG_ENV_SPI_MODE);
	 spi_flash_write(flash_spi, IFX_CFG_FLASH_DDR_CFG_START_ADDR, IFX_CFG_FLASH_DDR_CFG_SIZE, (char *)buffer);   
	 printf("saved ddr param in flash!\n");    
	    

	 return; 
}
#endif
#endif


int board_eth_init(bd_t *bis)
{
   if (ar10_eth_initialize(bis)<0)
             return -1;

	return 0;
}

/* Fix memory locations in switch */
#ifdef CONFIG_DRIVER_GRX390
int switch_mem_repair(void)
{
	int i;
	u32 read_fuse_bits;

	REG32(RST_REQ) = (REG32(RST_REQ) & 0xFEFFFFFF); // setting bit 24 to 0, wlan hardware reset
	REG32(RST_REQ2) = (REG32(RST_REQ2) & 0xFFFFFDFF); // setting bit 9 to 0, wlan mips reset

	while((REG32(RST_STAT2) | 0xfffffdff) !=  0xfffffdff); //waiting for wlan to come out of reset

	//Assert Fuse_en- check
	REG32(RST_REQ2) = (REG32(RST_REQ2) | 0x00800000); //Set fuse_en bit in RCU

	for (i = 0; i < NO_OF_FUSES; i++) {
		read_fuse_bits = (REG32(PPE_SW_WLAN_RFUSE_BASE_ADDRESS + i * 0x4) & 0x0007FFFF); //Read Least significant 19 bits
		/* only fix the switch mem */	
		if (read_fuse_bits & 0x00060000) {
			update_switch_mem_locations(((read_fuse_bits >> 14) & 0x0000000F), 
                    ((read_fuse_bits >> 13)  & 0x00000001), (read_fuse_bits & 0x00001FFF)); //Switch Address width [12:0]
		}
	}//End for loop

	REG32(RST_REQ2) = (REG32(RST_REQ2) & 0xFF7FFFFF); //deassert fuse_en bit in RCU			

}

void update_switch_mem_locations(u32 mem_id, u32 rar0_1, u32 addr)
{
	u16 rar_addr;
	int i;
	addr = addr | 0x2000;                   //Setting valid marker bit
		switch(mem_id){
		case(0x9):
			if(rar0_1) rar_addr = 8;        //SSB0, RAR1
			else rar_addr = 0;              //SSB0, RAR0
			break;

		case(0xA):
			if(rar0_1) rar_addr = 10;       //SSB1, RAR1
			else rar_addr = 2;              //SSB1, RAR0
			break;

		case(0xB):
			if(rar0_1) rar_addr = 12;       //SSB2, RAR1
			else rar_addr = 4;              //SSB2, RAR0
			break;

		case(0xC):
			if(rar0_1) rar_addr = 14;       //SSB3, RAR1
			else rar_addr = 6;              //SSB3, RAR0
			break;

		default: 
			break;
	}

	printf("Memory fix at location 0x%08x to location 0x%08x\n",
				addr, rar_addr);

	REG32(ADR_ETHSW_TOP_PDI_ETHSW_SSB_DATA) = addr;			//Faulty address to be written onto RAR
	REG32(ADR_ETHSW_TOP_PDI_ETHSW_SSB_ADDR) = rar_addr;		//Address of RAR 
	REG32(ADR_ETHSW_TOP_PDI_ETHSW_SSB_MODE) = 0x01;     	//Write command, upper four bits of addr are zero
	while(REG32(ADR_ETHSW_TOP_PDI_ETHSW_SSB_MODE) != 0x0);	//self clear register. CLears just before executing transaction.
}
#endif /* CONFIG_DRIVER_GRX390 */
