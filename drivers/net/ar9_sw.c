
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
#include <asm/ar9.h>
#include <asm/addrspace.h>
//#include <asm/pinstrap.h>


#include <asm/amazon_s_sw.h>
#include <asm/amazon_s_dma.h>

#define TANTOS_CHIP_ID 0x2599
#define PHYID_IFX_PHY11G    0x030260D1
#define PHYID_LANTIQ_PHY11G 0xD565A400
#define PHYID_ICPLUS_IP101A 0x02430C54
#define PHYID_VSC_SIMPLIPHY 0x00070421


#define TX_CHAN_NO   1
#define RX_CHAN_NO   0

#define NUM_RX_DESC	PKTBUFSRX
//#define NUM_RX_DESC   16
#define NUM_TX_DESC	8
#define MAX_PACKET_SIZE 	1536
#define TOUT_LOOP	100
//#define PHY0_ADDR       1 /*fixme: set the correct value here*/

#define DMA_WRITE_REG(reg, value) *((volatile u32 *)reg) = (u32)value
#define DMA_READ_REG(reg, value)    value = (u32)*((volatile u32*)reg)

#define SW_WRITE_REG(reg, value)  *((volatile u32*)reg) = (u32)value
#define SW_READ_REG(reg, value)   value = (u32)*((volatile u32*)reg)
#define RGMII_MODE 0
#define MII_MODE 1
#define REV_MII_MODE 2
#define RED_MII_MODE_IC 3  /*Input clock */
#define RGMII_MODE_100MB 4
#define TURBO_REV_MII_MODE 6	/*Turbo Rev Mii mode */
#define RED_MII_MODE_OC 7  /*Output clock */
#define RGMII_MODE_10MB 8

extern void flush_dcache_range(unsigned long start, unsigned long stop);
extern void clean_dcache_range(unsigned long start, unsigned long stop);
extern void invalidate_dcache_range(unsigned long start, unsigned long stop);
extern void flush_dcache(void);
extern void invalidate_dcache(void);
extern void invalidate_icache(void);
extern void mdelay (unsigned long msec);

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

struct mii_port {
	unsigned int  port_num;
	unsigned int  phy_id;
	unsigned char phy_addr;
	unsigned char mode;
};

static struct mii_port port[2] = {{.port_num=0, .phy_id=0, .mode = 0xFF},
                                  {.port_num=1, .phy_id=0, .mode = 0xFF}};

static danube_rx_descriptor_t rx_des_ring[NUM_RX_DESC] __attribute__ ((aligned(8)));
static danube_tx_descriptor_t tx_des_ring[NUM_TX_DESC] __attribute__ ((aligned(8)));
static int tx_num, rx_num;

int amazon_s_switch_init(struct eth_device *dev, bd_t * bis);
int amazon_s_switch_send(struct eth_device *dev, volatile void *packet,int length);
int amazon_s_switch_recv(struct eth_device *dev);
void amazon_s_switch_halt(struct eth_device *dev);
static int amazon_s_sw_chip_init(struct eth_device *dev);
static void amazon_s_dma_init(void);
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
static int update_link_status(struct eth_device *dev, struct mii_port *miiport);
#endif

int ar9_eth_initialize(bd_t * bis)
{
	struct eth_device *dev;

	if (!(dev = (struct eth_device *) malloc (sizeof *dev)))
        {
                printf("Failed to allocate memory\n");
                return 0;
        }
        memset(dev, 0, sizeof(*dev));


	/***************/
	sprintf(dev->name, "amazon_s Switch");
	dev->init = amazon_s_switch_init;
	dev->halt = amazon_s_switch_halt;
	dev->send = amazon_s_switch_send;
	dev->recv = amazon_s_switch_recv;

	amazon_s_sw_chip_init(dev);
	amazon_s_dma_init();

	eth_register(dev);


	return 1;
}

int amazon_s_switch_init(struct eth_device *dev, bd_t * bis)
{
	int i;

	tx_num=0;
	rx_num=0;

		/* Reset DMA
		 */
//	serial_puts("i \n\0");

       *AMAZON_S_DMA_CS=RX_CHAN_NO;
       *AMAZON_S_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
       *AMAZON_S_DMA_CPOLL= 0x80000040;
       /*set descriptor base*/
       *AMAZON_S_DMA_CDBA=(u32)rx_des_ring;
       *AMAZON_S_DMA_CDLEN=NUM_RX_DESC;
       *AMAZON_S_DMA_CIE = 0;
       *AMAZON_S_DMA_CCTRL=0x30000;

       *AMAZON_S_DMA_CS=TX_CHAN_NO;
       *AMAZON_S_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
       *AMAZON_S_DMA_CPOLL= 0x80000040;
       *AMAZON_S_DMA_CDBA=(u32)tx_des_ring;
       *AMAZON_S_DMA_CDLEN=NUM_TX_DESC;
       *AMAZON_S_DMA_CIE = 0;
       *AMAZON_S_DMA_CCTRL=0x30100;

	for(i=0;i < NUM_RX_DESC; i++)
	{
		danube_rx_descriptor_t * rx_desc = (danube_rx_descriptor_t *)KSEG1ADDR(&rx_des_ring[i]);
		rx_desc->status.word=0;
		rx_desc->status.field.OWN=1;
		rx_desc->status.field.DataLen=PKTSIZE_ALIGN;   /* 1536  */
		rx_desc->DataPtr=(u32)KSEG1ADDR(NetRxPackets[i]);
	    invalidate_dcache_range((u32)&rx_des_ring[i],(u32)&rx_des_ring[i]+8);
	}

	for(i=0;i < NUM_TX_DESC; i++)
	{
		danube_tx_descriptor_t * tx_desc = (danube_tx_descriptor_t *)KSEG1ADDR(&tx_des_ring[i]);
		memset(tx_desc, 0, sizeof(tx_des_ring[0]));
	}
		/* turn on DMA rx & tx channel
		 */
	 *AMAZON_S_DMA_CS=RX_CHAN_NO;
	 *AMAZON_S_DMA_CCTRL|=1;/*reset and turn on the channel*/


#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
	if (port[0].phy_id != 0) {
		update_link_status(dev, &port[0]);
	}
	if (port[1].phy_id != 0) {
		update_link_status(dev, &port[1]);
	}
#endif

	return 0;
}

void amazon_s_switch_halt(struct eth_device *dev)
{
        int i;
        for(i=0;i<8;i++)
	{
	   *AMAZON_S_DMA_CS=i;
	   *AMAZON_S_DMA_CCTRL&=~1;/*stop the dma channel*/
	}
//	udelay(1000000);
}

int amazon_s_switch_send(struct eth_device *dev, volatile void *packet,int length)
{

	int                    	i;
	int 		 	res = -1;
	danube_tx_descriptor_t * tx_desc= (danube_tx_descriptor_t *)KSEG1ADDR(&tx_des_ring[tx_num]);

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
	
    flush_dcache_range((u32)packet,(u32)packet+(u32)tx_desc->status.field.DataLen);	
	asm("SYNC");

	tx_desc->status.field.OWN=1;

	res=length;
	tx_num++;
        if(tx_num==NUM_TX_DESC) tx_num=0;
	*AMAZON_S_DMA_CS=TX_CHAN_NO;

	if(!(*AMAZON_S_DMA_CCTRL & 1))
	*AMAZON_S_DMA_CCTRL|=1;

Done:
	return res;
}

int amazon_s_switch_recv(struct eth_device *dev)
{

	int                    length  = 0;

	danube_rx_descriptor_t * rx_desc;
	for (;;)
	{
	        rx_desc = (danube_rx_descriptor_t *)KSEG1ADDR(&rx_des_ring[rx_num]);
               

		if ((rx_desc->status.field.C == 0) || (rx_desc->status.field.OWN == 1))
		{
                        //printf("@");
                        break;
                        //continue;
		}

                
		length = rx_desc->status.field.DataLen;
		if (length)
		{
			invalidate_dcache_range((u32)NetRxPackets[rx_num], (u32)NetRxPackets[rx_num]+length);
			NetReceive((void*)KSEG1ADDR(NetRxPackets[rx_num]), length - 4);
			//serial_putc('*');
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

void configure_sw_port(u8 port, u8 mode)
{
	if(port)
	{
		if (mode  == MII_MODE) //MII mode
		{
			*AMAZON_S_GPIO_P2_ALTSEL0 = *AMAZON_S_GPIO_P2_ALTSEL0 | (0xf000);
			*AMAZON_S_GPIO_P2_ALTSEL1 = *AMAZON_S_GPIO_P2_ALTSEL1 & ~(0xf000);
			*AMAZON_S_GPIO_P2_DIR = (*AMAZON_S_GPIO_P2_DIR & ~(0xf000)) | 0x2000;
			*AMAZON_S_GPIO_P2_OD = *AMAZON_S_GPIO_P2_OD | 0x2000;
			// Pull-Down for Rx_ERR pin since it is probably not connected 
			*AMAZON_S_GPIO_P2_PUDSEL = *AMAZON_S_GPIO_P2_PUDSEL & ~(0x4000);
			*AMAZON_S_GPIO_P2_PUDEN = *AMAZON_S_GPIO_P2_PUDEN | 0x4000;
		}
		else if(mode == REV_MII_MODE || mode == RED_MII_MODE_IC) //Rev Mii mode
		{
			*AMAZON_S_GPIO_P2_ALTSEL0 = *AMAZON_S_GPIO_P2_ALTSEL0 | (0xf000);
			*AMAZON_S_GPIO_P2_ALTSEL1 = *AMAZON_S_GPIO_P2_ALTSEL1 & ~(0xf000);
			*AMAZON_S_GPIO_P2_DIR = (*AMAZON_S_GPIO_P2_DIR | (0xf000)) & ~0x2000;
			*AMAZON_S_GPIO_P2_OD = *AMAZON_S_GPIO_P2_OD | 0xd000;
		}
	}
	else //Port 0
	{
		if (mode  == MII_MODE) //MII mode
		{
			*AMAZON_S_GPIO_P2_ALTSEL0 = *AMAZON_S_GPIO_P2_ALTSEL0 | (0x0303);
			*AMAZON_S_GPIO_P2_ALTSEL1 = *AMAZON_S_GPIO_P2_ALTSEL1 & ~(0x0303);
			*AMAZON_S_GPIO_P2_DIR = (*AMAZON_S_GPIO_P2_DIR & ~(0x0303)) | 0x0100;
			*AMAZON_S_GPIO_P2_OD = *AMAZON_S_GPIO_P2_OD | 0x0100;
			// Pull-Down for Rx_ERR pin since it is probably not connected 
			*AMAZON_S_GPIO_P2_PUDSEL = *AMAZON_S_GPIO_P2_PUDSEL & ~(0x0200);
			*AMAZON_S_GPIO_P2_PUDEN = *AMAZON_S_GPIO_P2_PUDEN | 0x0200;
		}
		else if(mode == REV_MII_MODE || mode == TURBO_REV_MII_MODE) //Rev Mii mode
		{
			*AMAZON_S_GPIO_P2_ALTSEL0 = *AMAZON_S_GPIO_P2_ALTSEL0 | (0x0303);
			*AMAZON_S_GPIO_P2_ALTSEL1 = *AMAZON_S_GPIO_P2_ALTSEL1 & ~(0x0303);
			*AMAZON_S_GPIO_P2_DIR = (*AMAZON_S_GPIO_P2_DIR | (0x0303)) & ~0x0100;
			*AMAZON_S_GPIO_P2_OD = *AMAZON_S_GPIO_P2_OD | 0x0203;
		}
	}
}

/*
  Call this function to place either MAC port 0 or 1 into working mode.
  Parameters:
  port - select ports 0 or 1.
  state of interface : state
  0: RGMII
  1: MII
  2: Rev MII
  3: Reduce MII (input clock)
  4: RGMII 100mb
  5: Reserve
  6: Turbo Rev MII
  7: Reduce MII (output clock)
*/
void enable_sw_port(u8 port, u8 state)
{
    if (port == 0)
    {
  	REG32(AMAZON_S_SW_RGMII_CTL) &= 0xffcffc0e ; 
//#if AR9_REFBOARD_TANTOS
	REG32(0xbf20302c) &= 0xffff81ff;
	REG32(0xbf20302c) |= 4<<9 ; 
//#endif
  	REG32(AMAZON_S_SW_RGMII_CTL) |= ((u32)(state &0x3))<<8;
	if((state &0x3) == 0)
	{
		REG32(AMAZON_S_SW_RGMII_CTL) &= 0xfffffff3;
		if(state == RGMII_MODE_100MB)
			REG32(AMAZON_S_SW_RGMII_CTL) |= 0x4;
		else
			REG32(AMAZON_S_SW_RGMII_CTL) |= 0x8;		
	}		
	if(state == TURBO_REV_MII_MODE)
  		REG32(AMAZON_S_SW_RGMII_CTL) |= ((u32) (1<<20));
	if(state == RED_MII_MODE_OC)
  		REG32(AMAZON_S_SW_RGMII_CTL) |= ((u32) (1<<21));
	 
		REG32(AMAZON_S_SW_P0_CTL) |= 0x40001;  // force link up
    }
  //  *AMAZON_S_PPE32_ETOP_CFG = *AMAZON_S_PPE32_ETOP_CFG & 0xfffffffe;
    else
    {
  	REG32(AMAZON_S_SW_RGMII_CTL) &= 0xff303fff ; 
  	REG32(AMAZON_S_SW_RGMII_CTL) |= ((u32)(state &0x3))<<18;
	if((state &0x3) == 0)
	{
		REG32(AMAZON_S_SW_RGMII_CTL) &= 0xffffcfff;
		if(state == RGMII_MODE_100MB)
			REG32(AMAZON_S_SW_RGMII_CTL) |= 0x1000;
		else
			REG32(AMAZON_S_SW_RGMII_CTL) |= 0x2000;		
	}		
	if(state == TURBO_REV_MII_MODE)
  		REG32(AMAZON_S_SW_RGMII_CTL) |= ((u32) (1<<22));
	if(state == RED_MII_MODE_OC)
  		REG32(AMAZON_S_SW_RGMII_CTL) |= ((u32) (1<<23));
		REG32(AMAZON_S_SW_P1_CTL) |= 0x40001;  // force link up
    }
}

int xway_mii_read(char *devname, unsigned char addr,
													unsigned char reg, unsigned short *value)
{
	int i;
	while(REG32(AMAZON_S_SW_MDIO_CTL) & 0x8000);
	udelay(4000);
	REG32(AMAZON_S_SW_MDIO_CTL) = 0x8000| 0x2<<10 | ((addr & 0x1f) << 5) | (reg&0x1f); /*0x10=MDIO_OP_READ*/
	while(REG32(AMAZON_S_SW_MDIO_CTL) & 0x8000);
//	*value = (u16) (REG32(AMAZON_S_SW_MDIO_DATA));
	/* should not be needed, but without this, sometimes old data is read!? */
        udelay(4000);
	*value = (u16) (REG32(AMAZON_S_SW_MDIO_DATA));
	REG32(AMAZON_S_SW_MDIO_DATA) = 0xFFFF;
	return 0;
}

int xway_mii_write(char *devname, unsigned char addr,
													unsigned char reg, unsigned short value)
{
	int i;
	while(REG32(AMAZON_S_SW_MDIO_CTL) & 0x8000);
	/* should not be needed, but without this, sometimes write fails!? */
	udelay(4000);
	REG32(AMAZON_S_SW_MDIO_CTL) = 0x8000| (((u32) value)<<16) | 0x01<<10 | ((addr & 0x1f) << 5) | (reg&0x1f); /*0x01=MDIO_OP_WRITE*/
	udelay(4000);
	asm("sync");
	return 0;
}

void pci_reset(void)
{
        int i,j;
#define AR9_V1_PCI_RST_FIX 1
#if AR9_V1_PCI_RST_FIX // 5th June 2008 Add GPIO19 to control EJTAG_TRST
	*AMAZON_S_GPIO_P1_ALTSEL0 = *AMAZON_S_GPIO_P1_ALTSEL0 & ~0x8;
	*AMAZON_S_GPIO_P1_ALTSEL1 = *AMAZON_S_GPIO_P1_ALTSEL1 & ~0x8;
	*AMAZON_S_GPIO_P1_DIR = *AMAZON_S_GPIO_P1_DIR | 0x8;
	*AMAZON_S_GPIO_P1_OD = *AMAZON_S_GPIO_P1_OD | 0x8;
	*AMAZON_S_GPIO_P1_OUT = *AMAZON_S_GPIO_P1_OUT | 0x8;
	*AMAZON_S_GPIO_P0_ALTSEL0 = *AMAZON_S_GPIO_P0_ALTSEL0 & ~0x4000;
	*AMAZON_S_GPIO_P0_ALTSEL1 = *AMAZON_S_GPIO_P0_ALTSEL1 & ~0x4000;
	*AMAZON_S_GPIO_P0_DIR = *AMAZON_S_GPIO_P0_DIR | 0x4000;
	*AMAZON_S_GPIO_P0_OD = *AMAZON_S_GPIO_P0_OD | 0x4000;
	for(j=0;j<5;j++)
	{
		*AMAZON_S_GPIO_P0_OUT = *AMAZON_S_GPIO_P0_OUT & ~0x4000;
		for(i=0;i<0x10000;i++);
		*AMAZON_S_GPIO_P0_OUT = *AMAZON_S_GPIO_P0_OUT | 0x4000;
		for(i=0;i<0x10000;i++);
	}
	*AMAZON_S_GPIO_P0_DIR = *AMAZON_S_GPIO_P0_DIR &  ~0x4000;
	*AMAZON_S_GPIO_P1_DIR = *AMAZON_S_GPIO_P1_DIR &  ~0x8;
#endif
}

static int amazon_s_sw_chip_init(struct eth_device *dev)
{
	unsigned short mdio_value;
	int probe_phyad = 0, i;
	unsigned int phy_id;
	unsigned char mode;

	pci_reset(); /* TODO: PCI code should not be here */
	
#ifdef CLK_OUT2_25MHZ
	/* Configure GPIO3 for CLK25_OUT */
	*AMAZON_S_CGU_IFCCR &= ~(3<<10);
	*AMAZON_S_GPIO_P0_ALTSEL0 = *AMAZON_S_GPIO_P0_ALTSEL0 | (1<<3);
	*AMAZON_S_GPIO_P0_ALTSEL1 = *AMAZON_S_GPIO_P0_ALTSEL1 & ~(1<<3);
	*AMAZON_S_GPIO_P0_DIR = *AMAZON_S_GPIO_P0_DIR  | (1<<3);
	*AMAZON_S_GPIO_P0_OD = *AMAZON_S_GPIO_P0_OD | (1<<3);
#endif

	/* Configure GPIO32 for external PHY reset */
	*AMAZON_S_GPIO_P2_ALTSEL0 = *AMAZON_S_GPIO_P2_ALTSEL0 & ~(1<<0);
	*AMAZON_S_GPIO_P2_ALTSEL1 = *AMAZON_S_GPIO_P2_ALTSEL1 & ~(1<<0);
	*AMAZON_S_GPIO_P2_DIR = *AMAZON_S_GPIO_P2_DIR  | (1<<0);
	*AMAZON_S_GPIO_P2_OD = *AMAZON_S_GPIO_P2_OD | (1<<0);
        
	/* Configure GPIO55 for TANTOS reset */
	*AMAZON_S_GPIO_P3_OD |=(1<<7);
	*AMAZON_S_GPIO_P3_DIR |= (1<<7);
	*AMAZON_S_GPIO_P3_ALTSEL0 &=~(1<<7);
	*AMAZON_S_GPIO_P3_ALTSEL1 &=~(1<<7);

#ifdef CONFIG_MII
	/* Configure GPIO42/43 for MDIO interface */
	*AMAZON_S_GPIO_P2_ALTSEL0 = *AMAZON_S_GPIO_P2_ALTSEL0 | (0xc00);
	*AMAZON_S_GPIO_P2_ALTSEL1 = *AMAZON_S_GPIO_P2_ALTSEL1 & ~(0xc00);
	*AMAZON_S_GPIO_P2_DIR = *AMAZON_S_GPIO_P2_DIR  | 0xc00;
	*AMAZON_S_GPIO_P2_OD = *AMAZON_S_GPIO_P2_OD | 0xc00;
#endif

	/* reset PHY and TANTOS */
	*AMAZON_S_GPIO_P2_OUT &= ~(1<<0);
	*AMAZON_S_GPIO_P3_OUT &= ~(1<<7);
	asm("sync");
	udelay(100);
	/* release PHY reset */
	*AMAZON_S_GPIO_P2_OUT |= (1<<0);
 	asm("sync");
	mdelay(100);
	/* release TANTOS reset */
	*AMAZON_S_GPIO_P3_OUT |= (1<<7);
	asm("sync");
	mdelay(200);

	/*enable DMA and disable usb*/
	*AMAZON_S_PMU_PWDCR = (*AMAZON_S_PMU_PWDCR & 0xEFFBDFDF) | 0x41; /* TODO: USB code should not be here */
	REG32(AMAZON_S_RCU_REQ) |= (0x3<<8) ;

	/* Enable the embedded ethernet switch */
	REG32(AMAZON_S_SW_P0_CTL) |= 0x400000; //disable mdio polling for tantos
	REG32(AMAZON_S_SW_P1_CTL) |= 0x400000; //disable mdio polling for tantos
	REG32(AMAZON_S_SW_P2_CTL) |= 0x40001;  // force link up
	REG32(AMAZON_S_SW_PMAC_HD_CTL) |= 0x40000; //enable CRC
	REG32(AMAZON_S_SW_GCTL0) |= 0x80000000;

//	port[0].port_num = 0;
//	port[1].port_num = 1;

#ifndef CONFIG_MII /* fixed (RG)MII configuration */
	port[1].phy_addr = 0;
	port[1].phy_id = 0xFFFFFFFF;
	port[1].mode = RGMII_MODE;
#else

	//printf("register MIIPHY\n");
	miiphy_register(dev->name, xway_mii_read, xway_mii_write);

	/* probe for TANTOS Chip ID register */
	xway_mii_read(dev->name, 8, 1, &mdio_value);
	//printf("probe for TANTOS: Chip ID %04X\n", mdio_value);

	if (mdio_value == TANTOS_CHIP_ID) {

		port[0].phy_addr = 0;
		port[0].phy_id = TANTOS_CHIP_ID;

		/* read TANTOS GSHS register to detect port 6 (RG)MII configuration */
		xway_mii_read(dev->name, 8, 2, &mdio_value);
		switch ((mdio_value & 0x30) >> 4) {
			case 0:
				/* TANTOS Port 6 is MII, so we want to be REV_MII */
				port[0].mode = REV_MII_MODE;
				break;
			case 1:
				/* TANTOS Port 6 is REV_MII, so we want to be MII */
				port[0].mode = MII_MODE;
				break;
			case 3:
			default:
				port[0].mode = RGMII_MODE;
				break;
		}

		/* TANTOS per definition connected to Port 0 in RGMII mode */
		printf("TANTOS_CHIP_ID@0-f, ");
		xway_mii_write(dev->name, 5, 1, 0x0004); /* port 5 force link up */
		xway_mii_write(dev->name, 6, 1, 0x0004); /* port 6 force link up */
		if (port[0].mode == RGMII_MODE) {
			xway_mii_write(dev->name, 7, 0x15, 0x0BBB); /* port 4-6 duplex mode,
		                                   flow control enable, 1000Mbit/s */
		}
		else {
			xway_mii_write(dev->name, 7, 0x15, 0x0777); /* port 4-6 duplex mode,
		                                   flow control enable, 100Mbit/s */
		}

		REG32(AMAZON_S_SW_P0_CTL) |= 0x40001;  // force link up

		probe_phyad = 16;
	}

	/* Note: Even PHY address gets assigned to port 0,
	   odd PHY address gets assigned to port 1 !       */
	for ( ; probe_phyad < 32; probe_phyad++)
	{
		xway_mii_read(dev->name, probe_phyad, 2, &mdio_value);
		phy_id = (mdio_value << 16);
		xway_mii_read(dev->name, probe_phyad, 3, &mdio_value);
		phy_id |= mdio_value;
		//printf("  %2d  %08X\n", probe_phyad, phy_id);

		switch (phy_id)
		{
		case PHYID_LANTIQ_PHY11G:
			printf("PHYID_LANTIQ_PHY11G@%x, ", probe_phyad);
			mode = RGMII_MODE;
			xway_mii_read(dev->name, probe_phyad, 0x1E, &mdio_value);/*check firmware version*/
			if(mdio_value == 0x8301){
                xway_mii_read(dev->name, probe_phyad, 0x09, &mdio_value);
				mdio_value |=1<<10;/*MSPT*/
                xway_mii_write(dev->name, probe_phyad, 0x09, mdio_value); 
			}
			xway_mii_write(dev->name, probe_phyad, 0x0D, 0x001f);
			xway_mii_write(dev->name, probe_phyad, 0x0E, 0x0fc6);
			xway_mii_write(dev->name, probe_phyad, 0x0D, 0x401f);
			xway_mii_write(dev->name, probe_phyad, 0x0E, 0x0052);
			xway_mii_write(dev->name, probe_phyad, 0x0D, 0x0000);
			break;

		case PHYID_IFX_PHY11G:
			printf("PHYID_IFX_PHY11G@%x, ", probe_phyad);
			mode = RGMII_MODE;
			break;

		case PHYID_VSC_SIMPLIPHY:
			printf("PHYID_VSC_SIMPLIPHY@%x, ", probe_phyad);
			mode = RGMII_MODE;
			break;

//		case PHYID_ICPLUS_IP101A:
//			printf("PHYID_ICPLUS_IP101A@%x, ", probe_phyad);
//			mode = MII_MODE;
//			break;

		default:
			mode = 0xFF;
		}

		if (mode != 0xFF) {
			port[probe_phyad%2].phy_addr = probe_phyad;
			port[probe_phyad%2].phy_id = phy_id;
			port[probe_phyad%2].mode = mode;
		}

	}
#endif

	if (port[0].phy_id != 0) {
		configure_sw_port(0, port[0].mode);
		enable_sw_port(0, port[0].mode);
	}
	if (port[1].phy_id != 0) {
		configure_sw_port(1, port[1].mode);
		enable_sw_port(1, port[1].mode);
	}
	else if (port[0].phy_id == 0) { /* hack for SuperVB */
		configure_sw_port(1, MII_MODE);
		enable_sw_port(1, MII_MODE);
	}
	return 0;
}


static void amazon_s_dma_init(void)
{
//	serial_puts("d \n\0");
        *AMAZON_S_PMU_PWDCR &=~(1<<AMAZON_S_PMU_DMA_SHIFT);/*enable DMA from PMU*/
		/* Reset DMA
		 */
	*AMAZON_S_DMA_CTRL|=1;
        *AMAZON_S_DMA_IRNEN=0;/*disable all the interrupts first*/

	/* Clear Interrupt Status Register
	*/
	*AMAZON_S_DMA_IRNCR=0xfffff;
	/*disable all the dma interrupts*/
	*AMAZON_S_DMA_IRNEN=0;
	/*disable channel 0 and channel 1 interrupts*/

	  *AMAZON_S_DMA_CS=RX_CHAN_NO;
	  *AMAZON_S_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
          *AMAZON_S_DMA_CPOLL= 0x80000040;
          /*set descriptor base*/
          *AMAZON_S_DMA_CDBA=(u32)rx_des_ring;
          *AMAZON_S_DMA_CDLEN=NUM_RX_DESC;
          *AMAZON_S_DMA_CIE = 0;
          *AMAZON_S_DMA_CCTRL=0x30000;

	*AMAZON_S_DMA_CS=TX_CHAN_NO;
	*AMAZON_S_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
        *AMAZON_S_DMA_CPOLL= 0x80000040;
	*AMAZON_S_DMA_CDBA=(u32)tx_des_ring;
        *AMAZON_S_DMA_CDLEN=NUM_TX_DESC;
	*AMAZON_S_DMA_CIE = 0;
	*AMAZON_S_DMA_CCTRL=0x30100;
	/*enable the poll function and set the poll counter*/
	//*AMAZON_S_DMA_CPOLL=AMAZON_S_DMA_POLL_EN | (AMAZON_S_DMA_POLL_COUNT<<4);
	/*set port properties, enable endian conversion for switch*/
	__asm__("sync");
         *AMAZON_S_DMA_PS=0;
        //*AMAZON_S_DMA_PCTRL = 0x1f28;
        *(volatile u32*)0xbe104144=0x1f28;
	//*AMAZON_S_DMA_PCTRL|=0xf<<8;/*enable 32 bit endian conversion*/
        //*AMAZON_S_DMA_PCTRL=0x1f14;
        __asm__("sync");
	return;
}

#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
static int update_link_status(struct eth_device *dev, struct mii_port *miiport)
{
	u32 regRgmiiCtl = REG32(AMAZON_S_SW_RGMII_CTL);
	int port_shift;

	if (miiport->phy_id == TANTOS_CHIP_ID) {
		return 0;
	}
	if (miiport->port_num == 0) { /* Port 0 */
		port_shift = 0;
	}
	else {
		port_shift = 10;
	}
	regRgmiiCtl &= ~(0xF << port_shift);

#if 0
	/* Check for link.
	 */
	if (miiphy_link(dev->name, miiport->phy_addr) == 0) {
		goto Fail;
	}
#endif
	if (miiphy_duplex(dev->name, miiport->phy_addr) == FULL) {
		regRgmiiCtl |= (0x2 << port_shift);
	}

	switch (miiphy_speed(dev->name, miiport->phy_addr)) {
		case _1000BASET:
			regRgmiiCtl |= (0x8 << port_shift);
			break;
		case _100BASET:
			regRgmiiCtl |= (0x4 << port_shift);
			break;
		default /* _10BASET */:
			break;
	}

	REG32(AMAZON_S_SW_RGMII_CTL) = regRgmiiCtl;

	return 0;
#if 0
Fail:
	//printf("no link on MII port % (phy_addr %d)!\n", miiport->port_num, miiport->phy_addr);
	return -1;
#endif
}
#endif
