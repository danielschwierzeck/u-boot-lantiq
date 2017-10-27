
/*
 * AMAZON_S internal switch ethernet driver.
 *
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */


#include <common.h>
#include <config.h>
#include <malloc.h>
#include <net.h>
#include <miiphy.h>
#include <asm/addrspace.h>
#include <asm/pinstrap.h>
#include <asm/lq_dma.h>

#ifdef CONFIG_BOOT_FROM_NAND
#include <nand.h>
#endif

#ifdef CONFIG_BOOT_FROM_SPI
#include <spi_flash.h>
#endif



#include <lzma/LzmaTypes.h>
#include <lzma/LzmaDec.h>
#include <lzma/LzmaTools.h>


#define TX_CHAN_NO   1
#define RX_CHAN_NO   0

#define NUM_RX_DESC	PKTBUFSRX
#define NUM_TX_DESC	8
#define MAX_PACKET_SIZE 	1536
#define TOUT_LOOP	100

#ifndef CONFIG_DRIVER_GRX390
#define NO_PHY_PORTS 7
#else
#define NO_PHY_PORTS 8
#endif

#define RGMII 0
#define GMII  1
#define TMII  2
#define MII   3
#define RMII  4
				
#define CONFIG_AR10_SW_PORT(NUM)   CONFIG_AR10_SW_PORT_##NUM

#define MDIO_WRITE_CMD  ((0 << 11)| (1 <<10))
#define MDIO_READ_CMD  ((1 << 11) | (0<<10))

extern void flush_dcache_range(unsigned long start, unsigned long stop);
extern void clean_dcache_range(unsigned long start, unsigned long stop);
extern void invalidate_dcache_range(unsigned long start, unsigned long stop);
extern void flush_dcache(void);
extern void invalidate_dcache(void);
extern void invalidate_icache(void);

extern void mdelay (unsigned long msec);

typedef struct
{
    int on;
	int miimode;
	int miirate;
}ar10_sw_port;


static dma_rx_descriptor_t rx_des_ring[NUM_RX_DESC] __attribute__ ((aligned(32)));
static dma_tx_descriptor_t tx_des_ring[NUM_TX_DESC] __attribute__ ((aligned(32)));
static ar10_sw_port ar10_port[7];
static int tx_num, rx_num;
#if CONFIG_AR10_SW_PORT_2 | CONFIG_AR10_SW_PORT_3 | CONFIG_AR10_SW_PORT_4 | CONFIG_AR10_SW_PORT_5b 
static u8 gphy_fw[65536] __attribute__ ((aligned(32)));
#endif

int ar10_switch_init(struct eth_device *dev, bd_t * bis);
int ar10_switch_send(struct eth_device *dev, volatile void *packet,int length);
int ar10_switch_recv(struct eth_device *dev);
void ar10_switch_halt(struct eth_device *dev);
static void ar10_sw_chip_init();
static void ar10_dma_init(void);
int xway_mii_read(char *devname, unsigned char addr,unsigned char reg, unsigned short *value);
int xway_mii_write(char *devname, unsigned char addr,unsigned char reg, unsigned short value);

u8 phyaddr[6]={0x0,0x01,0x02,0x03,0x04,0x05};

void config_mdio_gpio()
{
	  /*GPIO 42, MDIO used as output*/
	  /*GPIO 43, MDC used as output */
    *AR10_GPIO_P2_ALTSEL0 |= 0xc00;
    *AR10_GPIO_P2_ALTSEL1 &= ~(0xc00);
    *AR10_GPIO_P2_DIR     |= 0xc00;
    *AR10_GPIO_P2_OD      |= 0xc00;
#ifdef CONFIG_AR10_EXTERNAL_GPHY_INTERNAL    
    /*do the following for external phy using internal 25Mhz clock*/
	/*Since this piece of code won't affect the external phy using external 36Mhz crystal clock*/
	/*So user can keep it for both senarios as default unless GPIO3 is used for other purposes*/
	/*configure GPIO3, output 25Mhz clock*/
	*AR10_GPIO_P0_DIR      |= 0x08;
	*AR10_GPIO_P0_ALTSEL0  |= 0x08;
	*AR10_GPIO_P0_ALTSEL1  &=~(0x08);
	*AR10_GPIO_P0_OD       |= 0x08;

    /*fixme, the address of DRV_STRENGTH_REG_0 is not consistant with the AR10 spec*/
    REG32(0xbf2030b0) = 0x20;
	/*******************************************/
#endif	
}
	
	
void config_phy_led()
{
#if 0	 
	  /*GPIO 5, EPHY0_LED0*/
	  *AR10_GPIO_P0_DIR     |= 1<<5;
	  *AR10_GPIO_P0_ALTSEL0 &=~(1<<5);
    *AR10_GPIO_P0_ALTSEL1 |= 1<<5;
    
    /*GPIO 8, EPHY0_LED1*/
	  *AR10_GPIO_P0_DIR     &= ~(1<<8);
	  *AR10_GPIO_P0_ALTSEL0 |=1<<8;
    *AR10_GPIO_P0_ALTSEL1 |=1<<8;
    
    /*GPIO 14, EPHY1_LED0*/
	  *AR10_GPIO_P0_DIR     |= 1<<14;
	  *AR10_GPIO_P0_ALTSEL0 |= 1<<14;
    *AR10_GPIO_P0_ALTSEL1 |= 1<<14;
    
    /*GPIO 19, EPHY1_LED1*/
	  *AR10_GPIO_P1_DIR     |= 1<<3;
	  *AR10_GPIO_P1_ALTSEL0 |= 1<<3;
    *AR10_GPIO_P1_ALTSEL1 |= 1<<3;
#endif
     int i;

     *AR10_GPIO_P0_DIR |= 0x070;
     *AR10_GPIO_P0_ALTSEL0 |= 0x70;
     *AR10_GPIO_P0_ALTSEL1 &= ~0x70;
     *AR10_GPIO_P0_OD |= 0x70;
#ifdef CONFIG_DRIVER_GRX390
     *AR10_LED_CON1 = 0x81A381ff;
#else
	 *AR10_LED_CON1 = 0x81A001ff;
#endif	 
	 *AR10_LED_CON0 = 0x3C000000;

     for(i=0;i<6;i++)
     {
     /*For LED0    (SPEED/LINK INDICATION ONLY)*/
     REG32(AR10_ETHSW_MDC_CFG_0)=0x0;
     xway_mii_write(NULL,phyaddr[i],0xd,0x1F);
     xway_mii_write(NULL,phyaddr[i],0xe,0x1e2);
     xway_mii_write(NULL,phyaddr[i],0xd,0x401f);
     xway_mii_write(NULL,phyaddr[i],0xe,0x42);
	 REG32(AR10_ETHSW_MDC_CFG_0)=0x3f;

     REG32(AR10_ETHSW_MDC_CFG_0)=0x0;
     xway_mii_write(NULL,phyaddr[i],0xd,0x1F);
     xway_mii_write(NULL,phyaddr[i],0xe,0x1e3);
     xway_mii_write(NULL,phyaddr[i],0xd,0x401f);
     xway_mii_write(NULL,phyaddr[i],0xe,0x10);
     REG32(AR10_ETHSW_MDC_CFG_0)=0x3f;

     /*For LED1 (DATA TRAFFIC INDICATION ONLY)*/
     REG32(AR10_ETHSW_MDC_CFG_0)=0x0;
     xway_mii_write(NULL,phyaddr[i],0xd,0x1f);
     xway_mii_write(NULL,phyaddr[i],0xe,0x1e4);
     xway_mii_write(NULL,phyaddr[i],0xd,0x401f);
     xway_mii_write(NULL,phyaddr[i],0xe,0x70);
     REG32(AR10_ETHSW_MDC_CFG_0)=0x3f;

     REG32(AR10_ETHSW_MDC_CFG_0)=0x0;
     xway_mii_write(NULL,phyaddr[i],0xd,0x1f);
     xway_mii_write(NULL,phyaddr[i],0xe,0x1e5);
     xway_mii_write(NULL,phyaddr[i],0xd,0x401f);
     xway_mii_write(NULL,phyaddr[i],0xe,0x03);
     REG32(AR10_ETHSW_MDC_CFG_0)=0x3f;
     }

}	
	
int xway_mii_read(char *devname, unsigned char addr,unsigned char reg, unsigned short *value)
{
        u16 i=0;
        while(REG32(AR10_ETHSW_MDIO_CTRL) & 0x1000);
        REG32(AR10_ETHSW_MDIO_CTRL) = MDIO_READ_CMD | (((u32)addr)<<5) | ((u32)reg)|0x1000 ;
        while(REG32(AR10_ETHSW_MDIO_CTRL) & 0x1000)
        {
        	i++;
        	if(i>0x7fff)
        	{
        		  printf("MDIO access time out!\n");
        		  break;
        	}
        }
        *value = (u16)(REG32(AR10_ETHSW_MDIO_READ));
        return 0;
}

int xway_mii_write(char *devname, unsigned char addr,unsigned char reg, unsigned short value)
{
        u16 i=0;
        
        REG32(AR10_ETHSW_MDIO_WRITE)= value;
        while(REG32(AR10_ETHSW_MDIO_CTRL) & 0x1000);
        REG32(AR10_ETHSW_MDIO_CTRL) =  MDIO_WRITE_CMD | (((u32)addr)<<5) | ((u32)reg)|0x1000 ;
        while(REG32(AR10_ETHSW_MDIO_CTRL) & 0x1000)
        {
        	i++;
        	if(i>0x7fff)
        	{
        		  printf("MDIO access time out!\n");
        		  break;
        	}
        }
        return 0; 
}
					


int ar10_eth_initialize(bd_t * bis)
{
	struct eth_device *dev;

	if (!(dev = (struct eth_device *) malloc (sizeof *dev)))
        {
                printf("Failed to allocate memory\n");
                return 0;
        }
        memset(dev, 0, sizeof(*dev));

        asm("sync");
        ar10_sw_chip_init();
        asm("sync");
	/***************/
	sprintf(dev->name, "ar10 Switch");
	dev->init = ar10_switch_init;
	dev->halt = ar10_switch_halt;
	dev->send = ar10_switch_send;
	dev->recv = ar10_switch_recv;

	eth_register(dev);


	return 1;
}

int ar10_switch_init(struct eth_device *dev, bd_t * bis)
{
	int i;
	tx_num=0;
	rx_num=0;

		/* Reset DMA
		 */

    *AR10_DMA_CS=RX_CHAN_NO;
    *AR10_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
	  while(*AR10_DMA_CCTRL & 0x2);
	  *AR10_DMA_CPOLL= 0x80000040;
    /*set descriptor base*/
    *AR10_DMA_CDBA=(u32)rx_des_ring & 0x0ffffff0;
    *AR10_DMA_CDLEN=NUM_RX_DESC;
    *AR10_DMA_CIE = 0;
    *AR10_DMA_CCTRL=0x30000;

    *AR10_DMA_CS=TX_CHAN_NO;
    *AR10_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
    while(*AR10_DMA_CCTRL & 0x2);
	*AR10_DMA_CPOLL= 0x80000040;
    *AR10_DMA_CDBA=(u32)tx_des_ring & 0x0ffffff0;
    *AR10_DMA_CDLEN=NUM_TX_DESC;
    *AR10_DMA_CIE = 0;
    *AR10_DMA_CCTRL=0x30100;


    
	for(i=0;i < NUM_RX_DESC; i++)
	{
		dma_rx_descriptor_t * rx_desc = KSEG1ADDR(&rx_des_ring[i]);
		rx_desc->status.word=0;
		rx_desc->status.field.OWN=1;
		rx_desc->status.field.DataLen=PKTSIZE_ALIGN;   /* 1536  */
		rx_desc->DataPtr=(u32)NetRxPackets[i] & 0x0ffffff0;
        invalidate_dcache_range((u32)&rx_des_ring[i],(u32)&rx_des_ring[i]+8);
    }

	for(i=0;i < NUM_TX_DESC; i++)
	{
		dma_tx_descriptor_t * tx_desc = KSEG1ADDR(&tx_des_ring[i]);
		memset(tx_desc, 0, sizeof(tx_des_ring[0]));
	}
		/* turn on DMA rx & tx channel
		 */
    *AR10_DMA_CS=RX_CHAN_NO;
    *AR10_DMA_CCTRL|=1;/*reset and turn on the channel*/
	return 0;
}

void ar10_switch_halt(struct eth_device *dev)
{
    int i;
        for(i=0;i<8;i++)
	{
	   *AR10_DMA_CS=i;
	   *AR10_DMA_CCTRL&=~1;/*stop the dma channel*/
	}
}

int ar10_switch_send(struct eth_device *dev, volatile void *packet,int length)
{

	int                 	i;
	int 		 	res = -1;
	dma_tx_descriptor_t * tx_desc= KSEG1ADDR(&tx_des_ring[tx_num]);

	if (length <= 0)
	{
		printf ("%s: bad packet size: %d\n", dev->name, length);
		goto Done;
	}

	for(i=0; tx_desc->status.field.OWN==1; i++)
	{
		if(i>=TOUT_LOOP)
		{
			printf("NO Tx Descriptor...");
			goto Done;
		}
	}

	//serial_putc('s');

	tx_desc->status.field.Sop=1;
	tx_desc->status.field.Eop=1;
	tx_desc->status.field.C=0;
	//tx_desc->DataPtr = (u32)KSEG1ADDR(packet);
	tx_desc->DataPtr = (u32)packet & 0x0ffffff0;
        if(length<60)
		tx_desc->status.field.DataLen = 60;
	else
		tx_desc->status.field.DataLen = (u32)length;
	flush_dcache_range(packet,packet+tx_desc->status.field.DataLen);
	asm("SYNC");

	tx_desc->status.field.OWN=1;

	res=length;
	tx_num++;
        if(tx_num==NUM_TX_DESC) tx_num=0;
	*AR10_DMA_CS=TX_CHAN_NO;

	if(!(*AR10_DMA_CCTRL & 1))
	*AR10_DMA_CCTRL|=1;

Done:
	return res;
}

int ar10_switch_recv(struct eth_device *dev)
{

	int                    length  = 0;
	dma_rx_descriptor_t * rx_desc;
	for (;;)
	{
	        rx_desc = KSEG1ADDR(&rx_des_ring[rx_num]);
               

		if ((rx_desc->status.field.C == 0) || (rx_desc->status.field.OWN == 1))
		{
                        //printf("@");
                        break;
                        //continue;
		}

                
		length = rx_desc->status.field.DataLen;
		if (length)
		{
			invalidate_dcache_range((u32)NetRxPackets[rx_num], (u32)NetRxPackets[rx_num]+rx_desc->status.field.DataLen);
			NetReceive((void*)KSEG1ADDR(NetRxPackets[rx_num]), length - 4);
		}
		else
		{
			printf("Zero length!!!\n");
		}
		rx_desc->status.field.Sop=0;
		rx_desc->status.field.Eop=0;
		rx_desc->status.field.C=0;
		rx_desc->status.field.DataLen=PKTSIZE_ALIGN;
		rx_desc->status.field.OWN=1;
		rx_num++;
		if(rx_num==NUM_RX_DESC) rx_num=0;

	}
	return length;
}


static void ar10_dma_init(void)
{
	  *AR10_PMU_PWDCR &=~(BSP_PMU_DMA);/*enable DMA from PMU*/

    /* Reset DMA
		 */
    
	//*AR10_DMA_CTRL|=1;
    *AR10_DMA_IRNEN=0;/*disable all the interrupts first*/
    
    /* Clear Interrupt Status Register
	*/
    *AR10_DMA_IRNCR=0xfffff;
    /*disable all the dma interrupts*/
    *AR10_DMA_IRNEN=0;
	/*disable channel 0 and channel 1 interrupts*/
    
    *AR10_DMA_CS=RX_CHAN_NO;
    *AR10_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
    *AR10_DMA_CPOLL= 0x80000040;
     /*set descriptor base*/
    *AR10_DMA_CDBA=(u32)rx_des_ring;
    *AR10_DMA_CDLEN=NUM_RX_DESC;
    *AR10_DMA_CIE = 0;
    *AR10_DMA_CCTRL=0x30000;

    *AR10_DMA_CS=TX_CHAN_NO;
    *AR10_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
    *AR10_DMA_CPOLL= 0x80000040;
    *AR10_DMA_CDBA=(u32)tx_des_ring;
    *AR10_DMA_CDLEN=NUM_TX_DESC;
    *AR10_DMA_CIE = 0;
    *AR10_DMA_CCTRL=0x30100;

       
     /*enable the poll function and set the poll counter*/
     //*AMAZON_S_DMA_CPOLL=AMAZON_S_DMA_POLL_EN | (AMAZON_S_DMA_POLL_COUNT<<4);
     /*set port properties, enable endian conversion for switch*/
     __asm__("sync");
    *AR10_DMA_PS=0;
	  *AR10_DMA_PCTRL=0x1f3c;
    __asm__("sync");
    //return;

}


void config_port()
{
      int i;
	  for(i=0;i<7;i++)
	    ar10_port[i].on=0;

#ifdef CONFIG_AR10_SW_PORT_0
        ar10_port[0].on=1;
        ar10_port[0].miimode=CONFIG_AR10_SW_PORT0_MIIMODE;
        ar10_port[0].miirate=CONFIG_AR10_SW_PORT0_MIIRATE;
#endif
#ifdef CONFIG_AR10_SW_PORT_1
        ar10_port[1].on=1;
		ar10_port[1].miimode=CONFIG_AR10_SW_PORT1_MIIMODE;
		ar10_port[1].miirate=CONFIG_AR10_SW_PORT1_MIIRATE;
#endif
#ifdef CONFIG_AR10_SW_PORT_2
	    ar10_port[2].on=1;
		ar10_port[2].miimode=CONFIG_AR10_SW_PORT2_MIIMODE;
		ar10_port[2].miirate=CONFIG_AR10_SW_PORT2_MIIRATE;
#endif
#ifndef CONFIG_DRIVER_GRX390
#ifdef CONFIG_AR10_SW_PORT_3
        ar10_port[3].on=1;
		ar10_port[3].miimode=CONFIG_AR10_SW_PORT3_MIIMODE;
		ar10_port[3].miirate=CONFIG_AR10_SW_PORT3_MIIRATE;
#endif
#else
#ifdef CONFIG_GRX390_SW_PORT_3a
        ar10_port[3].on=1;
		ar10_port[3].miimode=CONFIG_GRX390_SW_PORT3a_MIIMODE;
		ar10_port[3].miirate=CONFIG_GRX390_SW_PORT3a_MIIRATE;
#endif
#ifdef CONFIG_GRX390_SW_PORT_3b
        ar10_port[3].on=1;
		ar10_port[3].miimode=CONFIG_GRX390_SW_PORT3b_MIIMODE;
		ar10_port[3].miirate=CONFIG_GRX390_SW_PORT3b_MIIRATE;
#endif
#endif /* CONFIG_DRIVER_GRX390 */
#ifdef CONFIG_AR10_SW_PORT_4
	    ar10_port[4].on=1;
		ar10_port[4].miimode=CONFIG_AR10_SW_PORT4_MIIMODE;
		ar10_port[4].miirate=CONFIG_AR10_SW_PORT4_MIIRATE;
#endif
#ifdef CONFIG_AR10_SW_PORT_5a
        ar10_port[5].on=1;
		ar10_port[5].miimode=CONFIG_AR10_SW_PORT5a_MIIMODE;
		ar10_port[5].miirate=CONFIG_AR10_SW_PORT5a_MIIRATE;
#endif
#ifdef CONFIG_AR10_SW_PORT_5b
	    ar10_port[5].on=1;
		ar10_port[5].miimode=CONFIG_AR10_SW_PORT5b_MIIMODE;
		ar10_port[5].miirate=CONFIG_AR10_SW_PORT5b_MIIRATE;
#endif
											  

    return;
}


/***obtain lzma compressed gphy firmware from src address***/
/** return value: 0 success, 1 fail*************************/
int get_gphy_firmware(u32 dst, u32 src)
{
     int result = 1;
     int srcLen;
	 u8* load = (unsigned char*)0xa0140000;
	 ulong unc_len = 0;
	 u8* image_start = NULL;
	 ulong image_len = 0;
     image_header_t *pimg_header = NULL;
	 int fw_version = 1; /*1->version 1; 2->version 2*/
	 int fw_type = 0; /*0 FE, 1 GE*/

     char* ep;

    
	 if (((ep = getenv("raw_gphy_fw")) != NULL) && (strcmp(ep, "yes") == 0)) {
         memcpy(dst,src,65536);
         result = 0;
		 goto exit;
	 }

     pimg_header = (image_header_t *)src;	
     while(1){ 
	    if(pimg_header->ih_magic != IH_MAGIC){
              printf("bad image magic number\n");
              result = 1;
              break;

	     }
	 switch(pimg_header->ih_type){
	   case IH_TYPE_MULTI:
         image_start = (u8*)pimg_header+sizeof(image_header_t)+8;
	     image_len = pimg_header->ih_size; 

	     if(lzmaBuffToBuffDecompress(load, &unc_len,image_start, image_len)){
			 printf("gphy image name incorrect...\n");
		     result = 1;
		     goto exit;
		     }
		  pimg_header = (image_header_t *)load;  
	    break;
      
	   case IH_TYPE_FIRMWARE:
		  if(strncmp(pimg_header->ih_name, "VR9 V1.2 GPHY GE", sizeof(pimg_header->ih_name)) == 0){
		          fw_type = 1;
		  }else if(strncmp(pimg_header->ih_name, "VR9 V1.2 GPHY FE", sizeof(pimg_header->ih_name)) == 0){
		          fw_type = 0;
		  }
    
#ifdef CONFIG_AR10_SW_PORT2_GMII
               if(fw_type == 1){    
                    image_start = (u8*)pimg_header+sizeof(image_header_t);
					image_len = pimg_header->ih_size;
					memcpy((u8*)dst, image_start, image_len);
					result = 0;
					goto exit;
			   }
#elif CONFIG_AR10_SW_PORT2_MII
          if(fw_type == 0){
                    image_start = (u8*)pimg_header+sizeof(image_header_t);
					image_len = pimg_header->ih_size;
				    memcpy((u8*)dst, image_start, image_len);		
					result = 0;
					goto exit;
			   }
#endif
      pimg_header = (u8*)pimg_header+sizeof(image_header_t)+(pimg_header->ih_size);
	      break;
		 
	  }
	 }
    	
exit:	 
     return result;
}

static void ar10_sw_chip_init()
{
    int i,num,port;
	  u32 fw_addr,gphy_reset_value,fw_src_addr; 
	  u8 interface_mode;
   	unsigned short mdio_value;
	       
/**************************************************/
/***********configure phy now**********************/
/**************************************************/
     /*gpio configuration for exteranl phy*/
     /*for external phy, this is all that needs to be done*/
     config_mdio_gpio(); 
    
    
    /*****************************/
    /*initialize internal phy now*/
    /*****************************/ 
     
    /*reset ephy*/
#ifdef CONFIG_DRIVER_GRX390
     *AR10_RCU_RST_REQ = 0xb0000421;
#else
	 *AR10_RCU_RST_REQ = 0xb0000021;
#endif     
	 mdelay(100);

	/*configure clock for internal phy*/
     REG32(AR10_CGU_IF_CLK) &= ~(0x0000001c);

#ifdef CONFIG_AR10_GPHY_CLK_25M     
	 REG32(AR10_CGU_IF_CLK) |=  (0x00000008);
     /*configure boot option for internal phy, enable FE/GE capability*/

     *AR10_EPHY0_CFG = 0x1fe70000;
     *AR10_EPHY1_CFG = 0x1fe70000;
     *AR10_EPHY2_CFG = 0x1fe70000;
	 
#if defined(CONFIG_DRIVER_GRX390) && defined(CONFIG_AR10_SW_PORT2_GMII) 	 
	 *AR10_EPHY3_CFG = 0x1fe70000;
#endif	 

	 printf("internal phy using 25Mhz clock\n");
	
#else /*36Mhz*/
     REG32(AR10_CGU_IF_CLK) |=  (0x00000004);
     *AR10_EPHY0_CFG = 0x1fdb20c5;
	 *AR10_EPHY1_CFG = 0x1fdb20c5;
	 *AR10_EPHY2_CFG = 0x1fdb20c5;
#if defined(CONFIG_DRIVER_GRX390) && defined(CONFIG_AR10_SW_PORT2_GMII)
     *AR10_EPHY3_CFG = 0x1fdb20c5;
#endif	 
	 printf("internal phy using 36Mhz clock\n");
#endif

#ifdef CONFIG_DRIVER_GRX390
#ifdef CONFIG_DISABLE_SINGLE_ENDED_CLK_GPHY2
       REG32(AR10_EPHY2_CFG) |= (1 << 22);
#else
       REG32(AR10_EPHY2_CFG) &= ~(1 << 22);
#endif
#endif

     mdelay(1);
     asm("sync");
     

     /*set gphy firmware address*/
     fw_addr=0xa0200000;
     asm("sync");
#ifdef CONFIG_AR10_GPHY_FW_EMBEDDED	  
      fw_src_addr = CONFIG_AR10_GPHY_FW_ADDR;
#endif	 
#ifdef CONFIG_AR10_EXTERN_GPHY_FW_ADDR
 #ifdef CONFIG_BOOT_FROM_NAND
      {
	     nand_info_t *nand = &nand_info[0];
	     u64 size=65536;
	     fw_src_addr = 0xa0120000;
       nand_read_skip_bad(nand, (getenv("gphy_fw_addr")?simple_strtoul((char *)getenv("gphy_fw_addr"),NULL,16):CONFIG_AR10_EXTERN_GPHY_FW_ADDR), &size,(u_char *)fw_src_addr);
      }
 #else /*CONFIG_BOOT_FROM_SPI*/
      {
        static struct spi_flash *flash;
		  fw_src_addr = 0xa0110000;
	    flash = spi_flash_probe(0, CONFIG_ENV_SPI_CS,
			             CONFIG_SF_DEFAULT_SPEED, CONFIG_SF_DEFAULT_MODE);
	    spi_flash_read(flash, (getenv("gphy_fw_addr")?simple_strtoul((char *)getenv("gphy_fw_addr"),NULL,16):CONFIG_AR10_EXTERN_GPHY_FW_ADDR), 65536, (void*)fw_src_addr);					 

	  }
 #endif 
#endif

     asm("sync");
     if(get_gphy_firmware(fw_addr,fw_src_addr)){
	           printf("cannnot find gphy firmware!\n");
	    }

     asm("sync");
     /* step - 1 */
     /* program fw base address */
     REG32(AR10_RCU_GFS_ADD0) = 0x200000;  
     REG32(AR10_RCU_GFS_ADD1) = 0x200000;  
     REG32(AR10_RCU_GFS_ADD2) = 0x200000;
#if defined(CONFIG_DRIVER_GRX390) && defined(CONFIG_AR10_SW_PORT2_GMII)    
	 REG32(AR10_RCU_GFS_ADD3) = 0x200000; 
#endif         
     /* step - 2 */
     // Bring GPHY-0/GFS-0 GPHY-1/GFS-1 out of reset
	 // in GRX390 mii mode , we do not bring the GPHY3 
	 // out of reset when in mii mode
#if defined(CONFIG_DRIVER_GRX390) && defined(CONFIG_AR10_SW_PORT2_GMII)
     REG32(AR10_RCU_RST_REQ) &= 0x4FFFFBFE; // 31st,29th, 28th, 0th bit for gphy rst
#else
	 REG32(AR10_RCU_RST_REQ) &= 0x4FFFFFFE; // 31st,29th, 28th bit for gphy rst
#endif
      
#if defined(CONFIG_DRIVER_GRX390) && defined(CONFIG_AR10_SW_PORT2_GMII)
     /*wait till two GPHYs/GFSs are out of reset*/
     while( *AR10_RCU_RST_STAT & 0x50002400 );
#else
     /*wait till two GPHYs/GFSs are out of reset*/
     while( *AR10_RCU_RST_STAT & 0x50002000 );
#endif

      mdelay(100);
      //while (!(*AR10_ICU_IM3_ISR & 0x40060000));
      /* step - 3 */
      
	  //GRX390 disable GPHY3 clk in mii mode
#if defined(CONFIG_DRIVER_GRX390) && defined(CONFIG_AR10_SW_PORT2_GMII)
     /*Enable clocks to the module*/
     REG32(AR10_PMU_CLKGCR1_A) |= 0xE4000000;

#else
      /*Enable clocks to the module*/
      REG32(AR10_PMU_CLKGCR1_A) |= 0xE0000000;
#endif
      config_phy_led();

#ifdef CONFIG_CMD_MII
      miiphy_register("AR10 SWITCH", xway_mii_read, xway_mii_write);
#endif

/**************************************/
/*end of phy configuration*************/
/**************************************/

    
	  /*Turn on switch macro*/  
    REG32(AR10_ETHSW_GLOB_CTRL) |= (1<<15);
   
   config_port();
   
   for(num=0;num<NO_PHY_PORTS;num++){
    if(ar10_port[num].on){
     
     REG32(AR10_ETHSW_MII_CFG_0 + ( port * 8)) |= (1<<AR10_ETHSW_MII_CFG_RES);  /*Hardware reset */
     for (i=0; i<100;i++)
     udelay(10);

     /*MAC setting, hard coded*/
     if(ar10_port[num].miirate == 4){
        /*auto-polling mode*/	
        REG16(AR10_ETHSW_MAC_CTRL_0 + ( num * 0x30))= 0x180; /*auto MII/GMII interface selection, enable padding*/
     }else{
     	  REG32(AR10_ETHSW_MAC_CTRL_0 + ( num * 0x30)) = 0x1c4; /*no flow control, full duplex, RGMII at 1000 Mbit/s*/     	  
     }
     
     
     /*MII setting*/
     /* set xMII port interface clock rate */
     REG32(AR10_ETHSW_MII_CFG_0 + ( num * 8)) &= ~0x3f;
     REG32(AR10_ETHSW_MII_CFG_0 + ( num * 8)) |= ((ar10_port[num].miirate & 0x7)<<AR10_ETHSW_MII_CFG_MIIRATE) |
                                                 ((ar10_port[num].miimode & 0xf)<<AR10_ETHSW_MII_CFG_MIIMODE) |
                                                 (1<<AR10_ETHSW_MII_CFG_EN);

     
     /*phy setting*/
     if(ar10_port[num].miirate == 4){
        /*auto-polling mode*/	
         REG32(AR10_ETHSW_MDC_CFG_0) |=1<<num;
     }else{
     	  /*disable auto polling mode for phy*/
     	   REG32(AR10_ETHSW_MDC_CFG_0) &=~(1<<num);
     	   REG32(AR10_ETHSW_PHY_ADDR_0- (num *4)) &= ~(0x1f<<11);//Modified by Aik Ann for Rel29p1
         REG32(AR10_ETHSW_PHY_ADDR_0- (num *4)) |= (0x2<<11); // 1G data rate
         REG32(AR10_ETHSW_PHY_ADDR_0- (num *4)) |= (1<<13);// Link Up
     }
     
     }
    }
     REG32(AR10_ETHSW_PMAC_HD_CTL) |= (1<<2);
     
	 /*Force clk stop capability*/

     REG32(AR10_ETHSW_ANEG_EEE_0) = 0x0C;
     REG32(AR10_ETHSW_ANEG_EEE_1) = 0x0C;
     REG32(AR10_ETHSW_ANEG_EEE_2) = 0x0C;
     REG32(AR10_ETHSW_ANEG_EEE_3) = 0x0C;
     REG32(AR10_ETHSW_ANEG_EEE_4) = 0x0C;
     REG32(AR10_ETHSW_ANEG_EEE_5) = 0x0C;


     /*to avoid switch CRC issue under high temperature*/
	 /* set PCDU port 0 and 5 RX to '0' to avoid CRC issues */
     REG32(AR10_ETHSW_PCDU_0) = 0xc001;
	 REG32(AR10_ETHSW_PCDU_5) = 0xc001;

#if 0
     /*Polarity inversion for B&D ports for certain phys*/
     xway_mii_write(NULL,phyaddr[1],0x13,0xa0);
	 xway_mii_write(NULL,phyaddr[2],0x13,0xa0);
     xway_mii_write(NULL,phyaddr[4],0x13,0xa0);
#endif
     asm("sync");  
    
     xway_mii_read(NULL, 0x4, 0x1e, &mdio_value);    
     printf("Internal phy firmware version: 0x%04x\n",mdio_value);      
	
	ar10_dma_init();
}



