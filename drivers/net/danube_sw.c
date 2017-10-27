/*
 * DANUBE internal switch ethernet driver.
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

#include <malloc.h>
#include <net.h>
#include <config.h>
#include <asm/addrspace.h>
#include <asm/pinstrap.h>
#include <asm/ifx_tantos.h>  

#define MII_MODE 1
#define REV_MII_MODE 2

#define TX_CHAN_NO   7
#define RX_CHAN_NO   6

#define NUM_RX_DESC	PKTBUFSRX                  
#define NUM_TX_DESC	8
#define MAX_PACKET_SIZE 	1536
#define TOUT_LOOP	100
#define PHY0_ADDR       1 /*fixme: set the correct value here*/ 

#define DMA_WRITE_REG(reg, value) *((volatile u32 *)reg) = (u32)value
#define DMA_READ_REG(reg, value)    value = (u32)*((volatile u32*)reg)

#define SW_WRITE_REG(reg, value)  *((volatile u32*)reg) = (u32)value  	
#define SW_READ_REG(reg, value)   value = (u32)*((volatile u32*)reg)
#define TANTOS_CHIP_ID 0x2599

typedef struct
{
	union
	{
		struct
		{
			volatile u32 OWN                 :1;
			volatile u32 C	                 :1;
			volatile u32 Sop                 :1;
			volatile u32 Eop	         :1;
			volatile u32 reserved		 :3;
			volatile u32 Byteoffset		 :2; 
			volatile u32 reserve             :7;
			volatile u32 DataLen             :16;
		}field;

		volatile u32 word;
	}status;
	
	volatile u32 DataPtr;
} danube_rx_descriptor_t;

typedef struct
{
	union
	{
		struct
		{
			volatile u32 OWN                 :1;
			volatile u32 C	                 :1;
			volatile u32 Sop                 :1;
			volatile u32 Eop	         :1;
			volatile u32 Byteoffset		 :5; 
			volatile u32 reserved            :7;
			volatile u32 DataLen             :16;
		}field;

		volatile u32 word;
	}status;
	
	volatile u32 DataPtr;
} danube_tx_descriptor_t;




static danube_rx_descriptor_t rx_des_ring[NUM_RX_DESC] __attribute__ ((aligned(16)));
static danube_tx_descriptor_t tx_des_ring[NUM_TX_DESC] __attribute__ ((aligned(16)));
static int tx_num, rx_num;

int danube_switch_init(struct eth_device *dev, bd_t * bis);
int danube_switch_send(struct eth_device *dev, volatile void *packet,int length);
int danube_switch_recv(struct eth_device *dev);
void danube_switch_halt(struct eth_device *dev);
static void danube_init_switch_chip(void);
static void danube_dma_init(void);

static unsigned int smi_read(unsigned int addr);  
static int smi_write(unsigned int addr, unsigned int dat);  


int danube_eth_init(bd_t * bis)
{
	struct eth_device *dev;
    int i;

	if (!(dev = (struct eth_device *) malloc (sizeof *dev)))
	{
		printf("Failed to allocate memory\n");
		return 0;
	}
	memset(dev, 0, sizeof(*dev));

	danube_dma_init();
	danube_init_switch_chip();
        
       
	sprintf(dev->name, "danube Switch");
	dev->init = danube_switch_init;
	dev->halt = danube_switch_halt;
	dev->send = danube_switch_send;
	dev->recv = danube_switch_recv;

	eth_register(dev);

	return 1;
}
static int smi_write(unsigned int addr, unsigned int dat)
{
 
   *DANUBE_PPE32_ETOP_MDIO_ACC = ((addr<<16)&0x3ff0000)|dat|0x80000000;
   while ((*DANUBE_PPE32_ETOP_MDIO_ACC )&0x80000000){};
   return 0;
 
}
static unsigned int smi_read(unsigned int addr)
{
   addr=(addr<<16)&0x3ff0000;
   *DANUBE_PPE32_ETOP_MDIO_ACC =(0xC0000000|addr);
   while ((*DANUBE_PPE32_ETOP_MDIO_ACC)&0x80000000){};
   return ((*DANUBE_PPE32_ETOP_MDIO_ACC)&0x0FFFF);
}
	

int danube_switch_init(struct eth_device *dev, bd_t * bis)
{
	int i;
	int datalen, cache_linesize;
	tx_num=0;
	rx_num=0;
	
		/* Reset DMA 
		 */
//	serial_puts("i \n\0");

       *DANUBE_DMA_CS=RX_CHAN_NO;
       *DANUBE_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
       *DANUBE_DMA_CPOLL= 0x80000040;
       /*set descriptor base*/
       *DANUBE_DMA_CDBA=(u32)rx_des_ring;
       *DANUBE_DMA_CDLEN=NUM_RX_DESC;
       *DANUBE_DMA_CIE = 0;
       *DANUBE_DMA_CCTRL=0x30000;
	 	
       *DANUBE_DMA_CS=TX_CHAN_NO;
       *DANUBE_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
       *DANUBE_DMA_CPOLL= 0x80000040;
       *DANUBE_DMA_CDBA=(u32)tx_des_ring;
       *DANUBE_DMA_CDLEN=NUM_TX_DESC;  
       *DANUBE_DMA_CIE = 0;
       *DANUBE_DMA_CCTRL=0x30100;


	
	asm("sync");
	
	
	for(i=0;i < NUM_RX_DESC; i++)
	{
		danube_rx_descriptor_t * rx_desc = KSEG1ADDR(&rx_des_ring[i]);
		rx_desc->status.word=0;	
		rx_desc->status.field.OWN=1;
		rx_desc->status.field.DataLen=PKTSIZE_ALIGN;   /* 1536  */	
		rx_desc->DataPtr=(u32)KSEG1ADDR(NetRxPackets[i]);
	  memcpy((u8*)&rx_des_ring[i],rx_desc,8);
	}
  for(i=0;i < NUM_TX_DESC; i++)
	{
		danube_tx_descriptor_t * tx_desc = KSEG1ADDR(&tx_des_ring[i]);
		memset(tx_desc, 0, sizeof(tx_des_ring[0]));
	}
		/* turn on DMA rx & tx channel
		 */
	 *DANUBE_DMA_CS=RX_CHAN_NO;
	 *DANUBE_DMA_CCTRL|=1;/*reset and turn on the channel*/


	
	return 1;
}

void danube_switch_halt(struct eth_device *dev)
{
        int i; 
        for(i=0;i<8;i++)
	{
	   *DANUBE_DMA_CS=i;
	   *DANUBE_DMA_CCTRL&=~1;/*stop the dma channel*/
	}
//	udelay(1000000);
}

int danube_switch_send(struct eth_device *dev, volatile void *packet,int length)
{

	int                    	i;
	int 		 	res = -1;
	int datalen, cache_linesize;
	danube_tx_descriptor_t * tx_desc= KSEG1ADDR(&tx_des_ring[tx_num]);
	
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
	
	tx_desc->DataPtr = (u32)KSEG1ADDR(packet);
	
	if(length<60)
		tx_desc->status.field.DataLen = 60;
	else
		tx_desc->status.field.DataLen = (u32)length;	
	
	
	cache_linesize = dcache_linesize_mips32() ;
	
	datalen = cache_linesize *((tx_desc->status.field.DataLen/cache_linesize)+1);
	
	dcache_writeback_invalidate(datalen, cache_linesize, packet );
	
	tx_desc->status.field.OWN=1;
			 	
	res=length;
	tx_num++;
        if(tx_num==NUM_TX_DESC) tx_num=0;
	*DANUBE_DMA_CS=TX_CHAN_NO;
	  
	if(!(*DANUBE_DMA_CCTRL & 1))
	*DANUBE_DMA_CCTRL|=1;
        
Done:
	return res;
}

int danube_switch_recv(struct eth_device *dev)
{
  
	int                    length  = 0;
  int datalen, cache_linesize;
	danube_rx_descriptor_t * rx_desc;
        int anchor_num=0;
	int i;
	
	for (;;)
	{
		   
	        rx_desc = KSEG1ADDR(&rx_des_ring[rx_num]);

	        if ((rx_desc->status.field.C == 0) || (rx_desc->status.field.OWN == 1))
		{
		   break;
		}
		
                
		length = rx_desc->status.field.DataLen;
		if (length)
		{	
	
		     cache_linesize = dcache_linesize_mips32() ;
			
			 datalen = cache_linesize*((rx_desc->status.field.DataLen/cache_linesize)+1);
	   
			 dcache_hit_invalidate(datalen,cache_linesize, NetRxPackets[rx_num]);
		  
			NetReceive((void*)KSEG1ADDR(NetRxPackets[rx_num]), length - 4);
			
		//	serial_putc('*');
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


static void danube_init_switch_chip()
{
        int i;
        /*get and set mac address for MAC*/
        static unsigned char addr[6];
        char *tmp,*end; 
	tmp = getenv ("ethaddr");
	if (NULL == tmp) {
		printf("Can't get environment ethaddr!!!\n");
	//	return NULL;
	} else {
		printf("ethaddr=%s\n", tmp);
	}
        *DANUBE_PMU_PWDCR = *DANUBE_PMU_PWDCR & 0xFFFFEFDF;
        
        *DANUBE_PPE32_ETOP_MDIO_CFG &= ~0x6;

        /*set mac to be working in reverse MII mode for both MII0 and MII1*/
        *DANUBE_PPE32_ETOP_CFG = 0x152;

        *DANUBE_PPE32_ETOP_IG_PLEN_CTRL = 0x4005ee; // set packetlen.
        *ENET_MAC_CFG|=1<<11;/*enable the crc*/

        /*reset external switch*/
	    *DANUBE_RCU_RST_REQ |=1;
	    mdelay(800);
        *DANUBE_RCU_RST_REQ &=(unsigned long)~1;
        mdelay(10);
       
	    if(smi_read(TANTOS_REG_CI1)==TANTOS_CHIP_ID){
		  /*Wehn WAIT_INIT is enabled, this bit allows the CPU to control */
		  /*the TANTOS enable or disable.The default is disable and the   */
		  /*TANTOS will wait for the CPU to enable this bit               */
		  /*easy50712 V3.0 board WAIT_INIT is 0,                          */
		  /*TANTOS will start to operate after EEPROM loading is done     */
		  /*Need to uncomment the following sentence if WAIT_INIT is 1    */
		  //smi_write(TANTOS_REG_SGC2,0x8000);


          /*port 5 force link up*/
		  /*The spec says that when using MAC to MAC connection, the bit  */
		  /*of relative port must be enalbe to ensure this port can       */
		  /* receive and transmit normally                                */
		  smi_write(TANTOS_REG_P5BCTL, 0x4);
	      /*port 6 force link up*/
	      smi_write(TANTOS_REG_P6BCTL, 0x4);
		}else{
		  /*patch for ADM6996*/
          smi_write(0x12, 0x3602);
		}  
    	return;
}


static void danube_dma_init(void)
{
        int i;
//	serial_puts("d \n\0");

    *DANUBE_PMU_PWDCR &=~(1<<DANUBE_PMU_DMA_SHIFT);/*enable DMA from PMU*/
		/* Reset DMA 
		 */
	*DANUBE_DMA_CTRL|=1; 
        *DANUBE_DMA_IRNEN=0;/*disable all the interrupts first*/

	/* Clear Interrupt Status Register 		 
	*/
	*DANUBE_DMA_IRNCR=0xfffff;
	/*disable all the dma interrupts*/
	*DANUBE_DMA_IRNEN=0;
	/*disable channel 0 and channel 1 interrupts*/
	
	  *DANUBE_DMA_CS=RX_CHAN_NO;
	  *DANUBE_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
          *DANUBE_DMA_CPOLL= 0x80000040;
          /*set descriptor base*/
          *DANUBE_DMA_CDBA=(u32)rx_des_ring;
          *DANUBE_DMA_CDLEN=NUM_RX_DESC;
          *DANUBE_DMA_CIE = 0;
          *DANUBE_DMA_CCTRL=0x30000;
	 	
	*DANUBE_DMA_CS=TX_CHAN_NO;
	*DANUBE_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
        *DANUBE_DMA_CPOLL= 0x80000040;
	*DANUBE_DMA_CDBA=(u32)tx_des_ring;
        *DANUBE_DMA_CDLEN=NUM_TX_DESC;  
	*DANUBE_DMA_CIE = 0;
	*DANUBE_DMA_CCTRL=0x30100;
	/*enable the poll function and set the poll counter*/
	//*DANUBE_DMA_CPOLL=DANUBE_DMA_POLL_EN | (DANUBE_DMA_POLL_COUNT<<4);
	/*set port properties, enable endian conversion for switch*/
	*DANUBE_DMA_PS=0;
	*DANUBE_DMA_PCTRL|=0xf<<8;/*enable 32 bit endian conversion*/

	return;
}



