
/*
 * HN1 internal switch ethernet driver.
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
#include <asm/hn1.h>
#include <asm/addrspace.h>
#include <asm/pinstrap.h>

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

#define NUM_RX_DESC	PKTBUFSRX	//AT: this is defined as 32 in net.h
#define NUM_TX_DESC	NUM_RX_DESC //AT: was 8
#define MAX_PACKET_SIZE 	1536
#define TOUT_LOOP	100


#define RGMII 0
#define GMII  1
#define TMII  2
#define MII   3
#define RMII  4
				
#define CONFIG_HN1_SW_PORT(NUM)   CONFIG_HN1_SW_PORT_##NUM

#define MDIO_WRITE_CMD  ((0 << 11)| (1 <<10))
#define MDIO_READ_CMD  ((1 << 11) | (0<<10))

//Enable this definition to speed up configuration or to configure in specific mode needed just for emulation
#ifdef CONFIG_FASTER_UART
#define RUN_ON_EMULATOR 1
#endif

#ifdef RUN_ON_EMULATOR
#define MS1 1
#define MS100 1
#define MS200 2
#else
#define MS1 1
#define MS100 100
#define MS200 200
#endif

//Enable this definition to diplay the packets' content
#ifdef CONFIG_DEBUG
#define DISPLAY_DATA_PACKETS
#endif

#ifndef CONFIG_HN1_SW_PORT_0a
#undef CONFIG_USE_TANTOS_SWITCH
#endif

extern int dcache_linesize_mips32(void);
extern void dcache_writeback_invalidate(u32 size, u32  dcache_line_size, u32 start_addr);
extern void dcache_hit_invalidate(u32 size, u32  dcache_line_size, u32 start_addr);
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
} dma_rx_descriptor_t;

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
} dma_tx_descriptor_t;

typedef struct
{
    int on;
	int miimode;
	int miirate;
}hn1_sw_port;


static dma_rx_descriptor_t rx_des_ring[NUM_RX_DESC] __attribute__ ((aligned(8)));
static dma_tx_descriptor_t tx_des_ring[NUM_TX_DESC] __attribute__ ((aligned(8)));
static hn1_sw_port hn1_port[4];
static int tx_num, rx_num;
#if CONFIG_HN1_SW_PORT_1 | CONFIG_HN1_SW_PORT_0b 
static u8 gphy_fw[65536] __attribute__ ((aligned(32)));
#endif

int hn1_switch_init(struct eth_device *dev, bd_t * bis);
int hn1_switch_send(struct eth_device *dev, volatile void *packet,int length);
int hn1_switch_recv(struct eth_device *dev);
void hn1_switch_halt(struct eth_device *dev);
void hn1_sw_chip_init();
void hn1_dma_init(void);

void config_mdio_gpio();
void config_port();

u16 vr9_mdio_read(u8 phyaddr, u8 phyreg)
{
    u16 i=0;

    //printf("%s %s start \n", __func__, __FILE__);
    while(REG32(VR9_ETHSW_MDIO_CTRL) & 0x1000);
    REG32(VR9_ETHSW_MDIO_CTRL) = MDIO_READ_CMD | (((u32)phyaddr)<<5) | ((u32) phyreg)|0x1000 ;
    while(REG32(VR9_ETHSW_MDIO_CTRL) & 0x1000)
    {
        i++;
        if(i>0x7fff)
        {
            printf("MDIO access time out!\n");
            break;
        }
    }
    //printf("%s %s finish \n", __func__, __FILE__);
    return((u16) (REG32(VR9_ETHSW_MDIO_READ)));
}

void vr9_mdio_write(u8 phyaddr, u8 phyreg, u16 data)
{
    u16 i=0;

    //printf("%s %s start \n", __func__, __FILE__);
    REG32(VR9_ETHSW_MDIO_WRITE)= data;
    while(REG32(VR9_ETHSW_MDIO_CTRL) & 0x1000);
    REG32(VR9_ETHSW_MDIO_CTRL) =  MDIO_WRITE_CMD | (((u32)phyaddr)<<5) | ((u32) phyreg)|0x1000 ;
    while(REG32(VR9_ETHSW_MDIO_CTRL) & 0x1000)
    {
        i++;
        if(i>0x7fff)
        {
            printf("MDIO access time out!\n");
            break;
        }
    }
    //printf("%s %s finish \n", __func__, __FILE__);
}

#ifdef CONFIG_USE_TANTOS_SWITCH
u16 tantos_read_mdio(unsigned int tRegAddr )
{
    unsigned int phyAddr, regAddr;

    if (tRegAddr >= 0x200)
    {
        return (0xff);
    }

    regAddr = tRegAddr & 0x1f;          //5-bits regAddr
    phyAddr = (tRegAddr>>5) & 0x1f;     //5-bits phyAddr

    return (vr9_mdio_read(phyAddr, regAddr));
}

void tantos_write_mdio(unsigned int tRegAddr, unsigned int data)
{
    unsigned int phyAddr, regAddr;

    if (tRegAddr >= 0x200)
    {
        return;
    }

    regAddr = tRegAddr & 0x1f;          //5-bits regAddr
    phyAddr = (tRegAddr>>5) & 0x1f;     //5-bits phyAddr

    return (vr9_mdio_write(phyAddr, regAddr, data));
}
#endif

int hn1_eth_initialize(bd_t * bis)
{
	struct eth_device *dev;

	//printf("%s %s start \n", __func__, __FILE__);

	if (!(dev = (struct eth_device *) malloc (sizeof *dev)))
    {
        printf("Failed to allocate memory\n");
        return 0;
    }
    memset(dev, 0, sizeof(*dev));

    asm("sync");
    hn1_sw_chip_init();
    asm("sync");

    /***************/
	sprintf(dev->name, "hn1 Switch");
	dev->init = hn1_switch_init;
	dev->halt = hn1_switch_halt;
	dev->send = hn1_switch_send;
	dev->recv = hn1_switch_recv;

	eth_register(dev);

	//printf("%s %s finish \n", __func__, __FILE__);
	return 1;
}

int hn1_switch_init(struct eth_device *dev, bd_t * bis)
{
	int i;
	tx_num=0;
	rx_num=0;

    /* Reset DMA
     */
	//printf("%s %s start \n", __func__, __FILE__);
    *BSP_DMA_CS=RX_CHAN_NO;
    *BSP_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
    *BSP_DMA_CPOLL= 0x80000040;
    /*set descriptor base*/
    *BSP_DMA_CDBA=(u32)rx_des_ring;
    *BSP_DMA_CDLEN=NUM_RX_DESC;
    *BSP_DMA_CIE = 0;
    *BSP_DMA_CCTRL=0x30000;

    *BSP_DMA_CS=TX_CHAN_NO;
    *BSP_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
    *BSP_DMA_CPOLL= 0x80000040;
    *BSP_DMA_CDBA=(u32)tx_des_ring;
    *BSP_DMA_CDLEN=NUM_TX_DESC;
    *BSP_DMA_CIE = 0;
    *BSP_DMA_CCTRL=0x30100;

	for(i=0;i < NUM_RX_DESC; i++)
	{
		dma_rx_descriptor_t * rx_desc = (dma_rx_descriptor_t *)(KSEG1ADDR(&rx_des_ring[i]));
		rx_desc->status.word=0;
		rx_desc->status.field.OWN=1;
		rx_desc->status.field.DataLen=PKTSIZE_ALIGN;   /* 1536  */
		rx_desc->DataPtr=(u32)NetRxPackets[i] & 0x0ffffff0;
	}

	for(i=0;i < NUM_TX_DESC; i++)
	{
		dma_tx_descriptor_t * tx_desc = (dma_tx_descriptor_t *)(KSEG1ADDR(&tx_des_ring[i]));
		memset(tx_desc, 0, sizeof(tx_des_ring[0]));
	}
		/* turn on DMA rx & tx channel
		 */
    *BSP_DMA_CS=RX_CHAN_NO;
    *BSP_DMA_CCTRL|=1;/*reset and turn on the channel*/
    //printf("%s %s finish \n", __func__, __FILE__);
	return 0;
}

void hn1_switch_halt(struct eth_device *dev)
{
    int i;

    //printf("%s %s start \n", __func__, __FILE__);
    for(i=0;i<8;i++)
	{
	   *BSP_DMA_CS=i;
	   *BSP_DMA_CCTRL&=~1;/*stop the dma channel*/
	}
    //printf("%s %s finish \n", __func__, __FILE__);
}

int hn1_switch_send(struct eth_device *dev, volatile void *packet,int length)
{
	int i;
	int res = -1;
    int datalen, cache_linesize;
	dma_tx_descriptor_t * tx_desc= (dma_tx_descriptor_t *)(KSEG1ADDR(&tx_des_ring[tx_num]));
	int lengthInitial;

	//printf("%s %s start \n", __func__, __FILE__);
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

	//serial_putc('T');

	tx_desc->status.field.Sop=1;
	tx_desc->status.field.Eop=1;
	tx_desc->status.field.C=0;
	tx_desc->DataPtr = (u32)packet & 0x0ffffff0;

	lengthInitial = length;
	if(length<60)
		tx_desc->status.field.DataLen = 60;
	else
		tx_desc->status.field.DataLen = (u32)length;

	cache_linesize = dcache_linesize_mips32() ;
	datalen = cache_linesize *((tx_desc->status.field.DataLen/cache_linesize)+1);
    dcache_writeback_invalidate(datalen, cache_linesize, (u32)packet );
	asm("SYNC");

    #ifdef DISPLAY_DATA_PACKETS
    {
        u32 * dataTx;
        u32 i;
        printf("\n\nTx pkt length = %d\n", lengthInitial);
        printf("tx_num = %d\n", tx_num);
        printf("(packet)=0x%08x\n" , (u32)( packet));
        printf("(&packet)=0x%08x\n", (u32)(&packet));
        dataTx = (u32 *)(packet);

        for (i=0; i<lengthInitial/4; i++)
        {
            printf("0x%08x ", dataTx[i]);
            if ((i&3)==3)
                printf("\n");
        }
        printf("\n");
        asm("SYNC");
    }
    #endif

	tx_desc->status.field.OWN=1;

	res=length;
	tx_num++;
    if(tx_num==NUM_TX_DESC) tx_num=0;
	*BSP_DMA_CS=TX_CHAN_NO;

	if(!(*BSP_DMA_CCTRL & 1))
	*BSP_DMA_CCTRL|=1;

Done:
    //printf("%s %s finish \n", __func__, __FILE__);
	return res;
}

int hn1_switch_recv(struct eth_device *dev)
{

	int length  = 0;
	dma_rx_descriptor_t * rx_desc;
	int datalen, cache_linesize;

	//printf("%s %s start \n", __func__, __FILE__);
	for (;;)
	{
	    rx_desc = (dma_rx_descriptor_t *)(KSEG1ADDR(&rx_des_ring[rx_num]));

		if ((rx_desc->status.field.C == 0) || (rx_desc->status.field.OWN == 1))
		{
		    //serial_putc("-");
            //printf("C=%d OWN=%d \n", rx_desc->status.field.C, rx_desc->status.field.OWN);
            break;
		}

		length = rx_desc->status.field.DataLen;
		if (length)
		{
            cache_linesize = dcache_linesize_mips32() ;
	        datalen = cache_linesize *((rx_desc->status.field.DataLen/cache_linesize)+1);
            dcache_hit_invalidate(datalen, cache_linesize, (u32)NetRxPackets[rx_num] );

            #ifdef DISPLAY_DATA_PACKETS
            //  Enable this just to check pkts content, otherwise it will break real-time
            {
                u32 * dataRecv;
                u32 i;

                dataRecv = (u32 *)(NetRxPackets[rx_num]);

                // Don't display broadcast packets
                //if ( (dataRecv[0] != 0xFFFFFFFF) && (((dataRecv[1]>>16)&0xFFFF) != 0xFFFF) )
                {
                    printf("\n\nRx pkt length = %d\n", length);
                    //printf("rx_num = %d\n", rx_num);
                    for (i=0; i<length/4; i++)
                    {
                        printf("%08x ", dataRecv[i]);
                        if ((i&3)==3)
                            printf("\n");
                    }
                    printf("\n");
                }
            }
            #endif

			NetReceive((void*)KSEG1ADDR(NetRxPackets[rx_num]), length - 4);
			//serial_putc('R');
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

	//printf("%s %s finish \n", __func__, __FILE__);
	return length;
}


void hn1_dma_init(void)
{
    //printf("%s %s start \n", __func__, __FILE__);
    *BSP_PMU_PWDCR &=~(BSP_PMU_DMA);/*enable DMA from PMU*/

    /* Reset DMA
    */
    *BSP_DMA_CTRL|=1;
    *BSP_DMA_IRNEN=0;/*disable all the interrupts first*/

    /* Clear Interrupt Status Register
	*/
    *BSP_DMA_IRNCR=0xfffff;
    /*disable all the dma interrupts*/
    *BSP_DMA_IRNEN=0;
	/*disable channel 0 and channel 1 interrupts*/
    
    *BSP_DMA_CS=RX_CHAN_NO;
    *BSP_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
    *BSP_DMA_CPOLL= 0x80000040;
    // Specify the address of the first descriptor
    *BSP_DMA_CDBA=(u32)rx_des_ring;
	// Use NUM descriptors
    *BSP_DMA_CDLEN=NUM_RX_DESC;
	// Disable all possible interrupts
    *BSP_DMA_CIE = 0;
	// bit0 = 0 for channel OFF; bit8 = 0 for rx direction; TXWGT=3
    *BSP_DMA_CCTRL=0x30000;

    *BSP_DMA_CS=TX_CHAN_NO;
    *BSP_DMA_CCTRL=0x2;/*fix me, need to reset this channel first?*/
    *BSP_DMA_CPOLL= 0x80000040;
    *BSP_DMA_CDBA=(u32)tx_des_ring;
    *BSP_DMA_CDLEN=NUM_TX_DESC;
    *BSP_DMA_CIE = 0;
	// bit0 = 0 for channel OFF; bit8 = 0 for tx direction; TXWGT=3
    *BSP_DMA_CCTRL=0x30100;
	
     /*enable the poll function and set the poll counter*/
     //*AMAZON_S_DMA_CPOLL=AMAZON_S_DMA_POLL_EN | (AMAZON_S_DMA_POLL_COUNT<<4);
     /*set port properties, enable endian conversion for switch*/
     __asm__("sync");
    *BSP_DMA_PS=0;
    //*BSP_DMA_PCTRL = 0x1f28;
	// AT: same endianess TX and RX, burst length = 4 words, packet drop enabled
    *BSP_DMA_PCTRL = 0x1f68;/*fix me, should I enable dma drop?*/
	//*BSP_DMA_PCTRL|=0xf<<8;/*enable 32 bit endian conversion*/
    //*BSP_DMA_PCTRL=0x1f14;
    __asm__("sync");

    //printf("%s %s finish \n", __func__, __FILE__);
    return;
}


void config_mdio_gpio()
{
    //printf("%s %s start \n", __func__, __FILE__);

    //P2.12 : MDIO used as output. Function1 = "1,0"
    //P2.13 : MDC used as output. Function1 = "1,0"
    *BSP_GPIO_P2_ALTSEL0 = *BSP_GPIO_P2_ALTSEL0 | (0x3000);
    *BSP_GPIO_P2_ALTSEL1 = *BSP_GPIO_P2_ALTSEL1 & ~(0x3000);
    *BSP_GPIO_P2_DIR     |= 0x3000;
    *BSP_GPIO_P2_OD      |= 0x3000;

    //printf("%s %s finish \n", __func__, __FILE__);
}

void config_port()
{
    int i;

    //printf("%s %s start \n", __func__, __FILE__);

    for(i=0;i<4;i++)
        hn1_port[i].on=0;

#ifdef CONFIG_HN1_SW_PORT_0a
    //printf("CONFIG_HN1_SW_PORT_0a \n");
    hn1_port[0].on=1;
    hn1_port[0].miimode=CONFIG_HN1_SW_PORT0a_MIIMODE;
    hn1_port[0].miirate=CONFIG_HN1_SW_PORT0a_MIIRATE;
    #ifdef RUN_ON_EMULATOR
    {
        // For emulation on Palladium we have to force the xMII Port Interface Clock Rate to 125MHz, instead of AUTO.
        //Without this the emulation sets the clock to 10Mbps
        printf("FIXME: Set interface clock rate to 125MHz for Port_0a\n");
        hn1_port[0].miirate=2;
    }
    #endif
    #ifdef CONFIG_USE_TANTOS_SWITCH
    {
        // For Tantos we have to force the xMII Port Interface Clock Rate to 125MHz, instead of AUTO.
        //printf("Port 0a: In MII_CFG_0 set interface clock rate to 125MHz\n");
        hn1_port[0].miirate=2;
    }
    #endif
#endif
#ifdef CONFIG_HN1_SW_PORT_0b
    //printf("CONFIG_HN1_SW_PORT_0b \n");
    hn1_port[0].on=1;
    hn1_port[0].miimode=CONFIG_HN1_SW_PORT0b_MIIMODE;
    hn1_port[0].miirate=CONFIG_HN1_SW_PORT0b_MIIRATE;
#endif
#ifdef CONFIG_HN1_SW_PORT_1
    //printf("CONFIG_HN1_SW_PORT_1 \n");
    hn1_port[1].on=1;
    hn1_port[1].miimode=CONFIG_HN1_SW_PORT1_MIIMODE;
    hn1_port[1].miirate=CONFIG_HN1_SW_PORT1_MIIRATE;
#endif
											  
    //printf("%s %s finish \n", __func__, __FILE__);
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
          if(strncmp(pimg_header->ih_name, "GPHY_FW_PHY11G_A1X", sizeof(pimg_header->ih_name)) == 0){
                  fw_version = 1;
				  fw_type = 1;
		  }else if(strncmp(pimg_header->ih_name, "GPHY_FW_PHY22F_A1X", sizeof(pimg_header->ih_name)) == 0){
                  fw_version = 1;
				  fw_type = 0;
		  }else if(strncmp(pimg_header->ih_name, "GPHY_FW_PHY22F_A2X", sizeof(pimg_header->ih_name)) == 0){
		          fw_version = 2;
		          fw_type = 1;
		  }else if(strncmp(pimg_header->ih_name, "GPHY_FW_PHY11G_A2X", sizeof(pimg_header->ih_name)) == 0){
		          fw_version = 2;
		          fw_type = 0;
		  }
  
		  if(((REG32(BSP_MPS_CHIPID)>>28) & 0x7) == fw_version){ 
#ifdef CONFIG_HN1_SW_PORT1_GMII
               if(fw_type == 1){    
                    image_start = (u8*)pimg_header+sizeof(image_header_t);
					image_len = pimg_header->ih_size;
					memcpy((u8*)dst, image_start, image_len);
					result = 0;
					goto exit;
			   }
#elif CONFIG_HN1_SW_PORT_0b
               if(fw_type == 0){
                    image_start = (u8*)pimg_header+sizeof(image_header_t);
					image_len = pimg_header->ih_size;
				    memcpy((u8*)dst, image_start, image_len);		
					result = 0;
					goto exit;
			   }
#endif
           }                 
		  pimg_header = (u8*)pimg_header+sizeof(image_header_t)+(pimg_header->ih_size);
	      break;
		 
	  }
	 }
    	
exit:	 
     return result;
}


void hn1_sw_chip_init()
{
    int i,num;
    u32 fw_addr,fw_src_addr;
    u32 regValue;

#ifdef CONFIG_ENABLE_CORE_DCDC
    if(1)
    {
        // 0x7f for 0.998V; 0x85 for 1.045V;    0x88 for 1.068V;    0x8C for 1.100V;
        config_dcdc(0x88);
    }
    else
    {
        printf("\nFIXME: CONFIG_ENABLE_CORE_DCDC is defined but the actual configuration is skipped.\n"); 
    }
#endif

    //printf("%s %s start \n", __func__, __FILE__);
#if (CONFIG_HN1_SW_PORT_0b | CONFIG_HN1_SW_PORT_1)
#ifdef CONFIG_HN1_GPHY_DEBUG

    /*GPHY0_UTX*/
    REG32(BSP_GPIO_P0_ALTSEL0)|=1<<13;
    REG32(BSP_GPIO_P0_ALTSEL1)|=1<<13;
    REG32(BSP_GPIO_P0_DIR)|=1<<13;

    /*GJTAG_sel*/
    REG32(BSP_GPIO_P1_ALTSEL0)|=1;
    REG32(BSP_GPIO_P1_ALTSEL1)|=1;
    REG32(BSP_GPIO_P1_DIR)&=~1;

    /*GPHY0 TDI P2.0*/
    REG32(BSP_GPIO_P2_ALTSEL0) &=~1;
    REG32(BSP_GPIO_P2_ALTSEL1)|=1;
    REG32(BSP_GPIO_P2_DIR)&=~1;

    /*GPHY0 TDO P2.1*/
    REG32(BSP_GPIO_P2_ALTSEL0) &=~(1<<1);
    REG32(BSP_GPIO_P2_ALTSEL1)|=1<<1;
    REG32(BSP_GPIO_P2_DIR) |=1<<1;
    REG32(BSP_GPIO_P2_OD) &=~(1<<1); /*to be checked, affecting debugging speed*/

    /*GPHY0 TMS, P2.9*/
    REG32(BSP_GPIO_P2_ALTSEL0) |=1<<9;
    REG32(BSP_GPIO_P2_ALTSEL1)|=1<<9;
    REG32(BSP_GPIO_P2_DIR) &=~(1<<9);

    /*GPHY0 TCK, P2.8*/
    REG32(BSP_GPIO_P2_ALTSEL0) |=1<<8;
    REG32(BSP_GPIO_P2_ALTSEL1)|=1<<8;
    REG32(BSP_GPIO_P2_DIR) &=~(1<<8);

#if 0
    /*Configure LEDs for GPHY0*/
    /*gpio2, p0.2, gphy0 led 2*/
    REG32(BSP_GPIO_P0_ALTSEL0)|=1<<2;
    REG32(BSP_GPIO_P0_ALTSEL1)|=1<<2;
    REG32(BSP_GPIO_P0_DIR)|=1<<2;
    REG32(BSP_GPIO_P0_DIR)|=1<<2;

    /*gpio5, p0.5, gph0 led0*/
    REG32(BSP_GPIO_P0_ALTSEL0)&=~(1<<5);
    REG32(BSP_GPIO_P0_ALTSEL1)|=1<<5;
    REG32(BSP_GPIO_P0_DIR)|=1<<5;
    REG32(BSP_GPIO_P0_DIR)|=1<<5;
    
    /*gpio7, p0.7, gph0 led1*/
    REG32(BSP_GPIO_P0_ALTSEL0)|=1<<7;
    REG32(BSP_GPIO_P0_ALTSEL1)|=1<<7;
    REG32(BSP_GPIO_P0_DIR)|=1<<7;
    REG32(BSP_GPIO_P0_DIR)|=1<<7;
#endif
#endif

#ifdef CONFIG_GPHY_LED_GPIO		
//AT: this definition in not defined for HN1 but exist in VR9
    /*GPIO 5 , 7 , 44 , 45 config as GPHY LED , and GPIO7 is CFRAME pin*/ 
    *BSP_GPIO_P0_ALTSEL0 &= (~0x20);
    *BSP_GPIO_P0_ALTSEL1 |= (0x20);
    *BSP_GPIO_P0_DIR |= (0x20);
    *BSP_GPIO_P0_OD |= (0x20);
    *BSP_GPIO_P0_ALTSEL0 |=0x80;
    *BSP_GPIO_P0_ALTSEL1 |=0x80;
    *BSP_GPIO_P0_DIR |= (0x80);
    *BSP_GPIO_P0_DIR |= (0x80);

    *BSP_GPIO_P2_ALTSEL0 |= (0x1000);
    *BSP_GPIO_P2_ALTSEL1 |= (0x1000);
    *BSP_GPIO_P2_DIR |= (0x1000);
    *BSP_GPIO_P2_OD |= (0x1000);
    *BSP_GPIO_P2_ALTSEL0 &=(~0x2000);
    *BSP_GPIO_P2_ALTSEL1 |=0x2000;
    *BSP_GPIO_P2_DIR |= (0x2000);
    *BSP_GPIO_P2_DIR |= (0x2000);  
#else	 /*CONFIG_GPHY_SHIFT_REGISTER*/											    
    /*Enable led for gphy link status*/
    REG32(BSP_GPIO_P0_DIR)     = (REG32(BSP_GPIO_P0_DIR))    |( 0x70);
    REG32(BSP_GPIO_P0_ALTSEL0) = (REG32(BSP_GPIO_P0_ALTSEL0))|( 0x70);
    REG32(BSP_GPIO_P0_ALTSEL1) = (REG32(BSP_GPIO_P0_ALTSEL1))&(~0x70);
    REG32(BSP_GPIO_P0_OD)      = (REG32(BSP_GPIO_P0_OD))     |( 0x70);

    REG32(BSP_LED_CON1) = 0x81a38007; // all LEDs enable, software update mode, FPI clock for shifting, no delay
    REG32(BSP_LED_CON0) = 0x3f000000; // software update
#endif
#endif  //matches #if (CONFIG_HN1_SW_PORT_0b | CONFIG_HN1_SW_PORT_1)

#if (CONFIG_HN1_SW_PORT_0b | CONFIG_HN1_SW_PORT_1 | CONFIG_HN1_SW_PORT_0a)
    asm("sync");
    /*Turn ON ephy, switch in PMU*/
    /*Keep ON HN1 bulk shared memory. DMA is turn ON  later*/
    REG32(BSP_PMU_PWDCR) = 0x061590be;
    mdelay(MS100);
    REG32(BSP_RCU_RST_REQ) = 0xa0200300;

    mdelay(MS100);

    /*Turn ON switch macro*/
    REG32(VR9_ETHSW_GLOB_CTRL) |= (1<<15);
    
    regValue = REG32(BSP_IF_CLK);
    regValue = regValue & 0xFFFFFFE3;
    // Check b13 of RCU to identify the crystal clock setting
    if (((REG32(BSP_RCU_GP_STRAP))& (1<<13))==0)
    {
        //b13 is 0 ("37.5MHz")
        regValue = regValue | 0x8;
    }
    else
    {
        //b13 is 1 ("25MHz")
        regValue = regValue | 0x4;
    }
    REG32(BSP_IF_CLK)= regValue;
#endif  //matches #if (CONFIG_HN1_SW_PORT_0b | CONFIG_HN1_SW_PORT_1 | CONFIG_HN1_SW_PORT_0a)
	
#if (CONFIG_HN1_SW_PORT_0b | CONFIG_HN1_SW_PORT_1)
    /*gphy0 config for 25Mhz input clock only*/
    REG32(BSP_GPHY0_Cfg)=0x1fe70000;
    mdelay(MS1);
    asm("sync");
	
    fw_addr=0xa0200000;

    printf("Copy GPHY fw to addr=%08x",fw_addr);
#ifndef RUN_ON_EMULATOR
// In UGW5.1
//    memcpy((u8 *)fw_addr, (u8 *)CONFIG_HN1_GPHY_FW_ADDR, 65536);

// In UGW5.2
#ifdef CONFIG_HN1_GPHY_FW_EMBEDDED	  
    fw_src_addr = CONFIG_HN1_GPHY_FW_ADDR;
#endif	 

#ifdef CONFIG_HN1_EXTERN_GPHY_FW_ADDR
    // We need to determine the jumper position that indicates the bootROM boot mode.
    // If we boot in UART mode than we done't have to read the GPHY FW from flash because it was already uploaded over UART in DDR.
    // Otherwise, we have to read the GPHY FW directly from the Flash memory.
    /* read config from RST_SR bits[20:17] */
    regValue = ((*BSP_RCU_RST_SR) >> 17) & 0xF;
    regValue = (regValue >> 1) | ((regValue & 0x1) << 3); // new bit 17 is MSB

    if ((*BSP_RCU_RST_SR) & (0x1 << 12) ) // new bit 12 is MSB
    {
        regValue |= 0x10; // bit 4 in bootrom.config
    }
    if ((regValue != 4) && (regValue != 2))
    {
        printf(" Use GPHY FW from FLASH memory ");
        #ifdef CONFIG_BOOT_FROM_NAND
        {
            nand_info_t *nand = &nand_info[0];
            u64 size=65536;
            fw_src_addr = 0xa0120000;
           nand_read_skip_bad(nand, (getenv("gphy_fw_addr")?simple_strtoul((char *)getenv("gphy_fw_addr"),NULL,16):CONFIG_HN1_EXTERN_GPHY_FW_ADDR), &size,(u_char *)fw_src_addr);
        }
        #elif defined(CONFIG_BOOT_FROM_SPI)
        {
            static struct spi_flash *flash;
            fw_src_addr = 0xa0110000;
            flash = spi_flash_probe(0, CONFIG_ENV_SPI_CS,
                             CONFIG_SF_DEFAULT_SPEED, CONFIG_SF_DEFAULT_MODE);
            spi_flash_read(flash, (getenv("gphy_fw_addr")?simple_strtoul((char *)getenv("gphy_fw_addr"),NULL,16):CONFIG_HN1_EXTERN_GPHY_FW_ADDR), 65536, (void*)fw_src_addr);					 
        }
        #endif
    }
    else
    {
        printf(" Use GPHY FW from DDR memory ");
    }
#endif

    if(get_gphy_firmware(fw_addr,fw_src_addr))
    {
        printf("cannnot find gphy firmware!\n");
    }
    else
    {
        printf("...Done\n");
    }
#endif
	
    mdelay(MS100);
    //{
    //    for (i=0; i<32; i++)
    //        printf("Addr=%x Value=%x\n",(fw_addr+4*i), REG32((fw_addr+4*i)));
    //}
    /* step - 1 */
    /* program fw base address */
    // Set 'GPHY0 Firmware Base Address Register' of the RCU
    REG32(BSP_GPHY_FW_ADD0) = 0x200000;  // address inside DDR1/2
	  
    // Set 'Reset Request Register' of the RCU to Request Reset for GPHY0
    REG32(BSP_RCU_RST_REQ) = 0x80000021;

    mdelay(MS100);
    /* step - 2 */
    // Bring GPHY-0/GFS-0 out of reset
#ifdef CONFIG_POWER_DOWN_REGULATOR
#if 1
    *BSP_RCU_RST_REQ = 0x04000000;
#else
    printf("FIXME: Skip CONFIG_POWER_DOWN_REGULATOR!\n");
    *BSP_RCU_RST_REQ = 0x0;
#endif
#else
    *BSP_RCU_RST_REQ = 0x0;
#endif	  

    mdelay(MS200); /*wait 100 or 200ms*/

    REG32(BSP_SWITCH_PMAC_RX_IPG) = 0x8b;
#endif  //matches #if (CONFIG_HN1_SW_PORT_0b | CONFIG_HN1_SW_PORT_1)

#if defined(CONFIG_USE_TANTOS_SWITCH) || defined(CONFIG_HN1_SW_PORT_0a)
    /*Enable PHY polling for each port*/
    REG32(VR9_ETHSW_MDC_CFG_0)=0x03;
#else
    //Enable PHY polling only to port 1
    REG32(VR9_ETHSW_MDC_CFG_0)=0x02;
#endif

    /*2.5 MHz MDIO clock*/
    REG32(VR9_ETHSW_MDC_CFG_1)=0x00008109;

    udelay(100);
/**************************************************/	  
/***********configure phy now**********************/
/**************************************************/
    asm("sync");
    /* Configure mdio gpio. This is needed for external gphy only*/
    config_mdio_gpio();

    /* Configure port 1 phy address and auto-polling mode */
    REG32(VR9_ETHSW_PHY_ADDR_1) = 0x1811;

#ifdef CONFIG_HN1_SW_PORT_0b    
    REG32(VR9_ETHSW_PHY_ADDR_0) = 0x1812;  
#elif CONFIG_HN1_SW_PORT_0a
    #ifdef RUN_ON_EMULATOR
    {
        //For emulation on Palladium we need to force
        // Force [LINKST  => 01  ; up], [SPEED => 10   ; 1GB], [FDUP    => 01   ; full duplex]
        printf("FIXME: For Port_0a force LINKST=up, SPEED=1GB, FDUP=full duplex\n");
        REG32(VR9_ETHSW_PHY_ADDR_0) &= 0x01FF;
        REG32(VR9_ETHSW_PHY_ADDR_0) |= 0x3200;
    }
    #else
    {
        #ifdef CONFIG_USE_TANTOS_SWITCH
        // Force [LINKST  => 01  ; up], [SPEED => 10   ; 1GB], [FDUP    => 01   ; full duplex]
        //printf("Port 0a: In PHY_ADDR_0 force LINKST=up, SPEED=1GB, FDUP=full duplex\n");
        REG32(VR9_ETHSW_PHY_ADDR_0) &= 0x01FF;
        REG32(VR9_ETHSW_PHY_ADDR_0) |= 0x3200;

        //printf("Port 0a: In PHY_ADDR_0 force FCONTX=enable, FCONRX=enable\n");
        // Enable flow control in TX and RX
        REG32(VR9_ETHSW_PHY_ADDR_0) &= 0xFE1F;
        REG32(VR9_ETHSW_PHY_ADDR_0) |= 0x00A0;
        //printf("Port 0a: PHY_ADDR_0: value 0x%08x\n", REG32(VR9_ETHSW_PHY_ADDR_0));

        #else
        REG32(VR9_ETHSW_PHY_ADDR_0) = 0x1800;
        #endif
    }
    #endif
#endif  

/*****Set mdio registers*****************/
    vr9_mdio_write(0x11,0xd,0x1F);
    vr9_mdio_write(0x11,0xe,0x1FF);
    vr9_mdio_write(0x11,0xd,0x401F);
    vr9_mdio_write(0x11,0xe,0x1);
    vr9_mdio_write(0x11,0x14,0x8106);
    vr9_mdio_write(0x11,0x0,0x8000);

    #ifndef CONFIG_USE_TANTOS_SWITCH
	{
	    vr9_mdio_write(0x0,0x14,0x102);
		vr9_mdio_write(0x0,0x9,0x700);
	}
    #else
	{
		//AT: send 2 extra settings to TANTOS based on suggestions from Marc Schlossmann
		printf("MDIO: Configure TANTOS");
		//printf("Before write: regAddr=0x%04x regVal=0x%04x\n", 0xa1, tantos_read_mdio(0xa1));
		//printf("Before write: regAddr=0x%04x regVal=0x%04x\n", 0xf5, tantos_read_mdio(0xf5));
	    tantos_write_mdio(0xa1, 0x0004);
	    tantos_write_mdio(0xf5, 0x00B0);
        //printf("After write: regAddr=0x%04x regVal=0x%04x\n", 0xa1, tantos_read_mdio(0xa1));
        //printf("After write: regAddr=0x%04x regVal=0x%04x\n", 0xf5, tantos_read_mdio(0xf5));
        printf("...Done\n");

	}
    #endif
    
    vr9_mdio_write(0x11,0x9,0x700);
/**************************************/
/*end of phy configuration*************/
/**************************************/

/*************************************/
/***mac configuration now*************/
/*************************************/
    config_port();

    for(num=0;num<4;num++)
    {
        if(hn1_port[num].on)
        {
            //AT: Note1: HN1 has only VR9_ETHSW_MII_CFG_0 (only for the Port0).
            //AT: Note2: The selection between Port0a and Port0b is done by programming the MIIMODE: if RGMII then use external Port0a,
            //otherwise use Port0b
            printf("Init port%d: ",num);

            if (num!=1)
            {
                /*Hardware reset */
                REG32(VR9_ETHSW_MII_CFG_0 + ( num * 8)) |= (1<<VR9_ETHSW_MII_CFG_RES);
                for (i=0; i<100;i++)
                    udelay(10);

                /*Set xMII port interface clock rate */
                REG32(VR9_ETHSW_MII_CFG_0 + ( num * 8)) &= ~(0x7<<VR9_ETHSW_MII_CFG_MIIRATE);
                REG32(VR9_ETHSW_MII_CFG_0 + ( num * 8)) |= ((hn1_port[num].miirate & 0x7)<<VR9_ETHSW_MII_CFG_MIIRATE);

                /*Set xMII port interface mode */
                REG32(VR9_ETHSW_MII_CFG_0 + ( num * 8)) &= ~(0xf<<VR9_ETHSW_MII_CFG_MIIMODE);
                REG32(VR9_ETHSW_MII_CFG_0 + ( num * 8)) |= ((hn1_port[num].miimode & 0xf)<<VR9_ETHSW_MII_CFG_MIIMODE);

                switch (hn1_port[num].miimode)
                {
                    case 0:
                        printf("MII PHY mode, connected to external MAC\n");
                        break;
                    case 1:
                        printf("MII MAC mode, connected to external PHY\n");
                        break;
                    case 2:
                        printf("RMII PHY mode, connected to external MAC\n");
                        break;
                    case 3:
                        printf("RMII MAC mode, connected to external PHY\n");
                        break;
                    case 4:
                        printf("RGMII MAC mode, connected to external PHY\n");
                        break;
                    case 5:
                        printf("MII MAC mode, connected to internal PHY\n");
                        break;
                    default:
                        printf("Unsupported mode! Val=%d\n", hn1_port[num].miimode);
                }

                /*Set xMII port interface enable*/
                REG32(VR9_ETHSW_MII_CFG_0 + ( num * 8)) |= (1<<VR9_ETHSW_MII_CFG_EN);
            }
            else
            {
                //hn1_port[num].miimode is ignored; always use GMII
                //hn1_port[num].miirate is ignored;

                printf("GMII MAC mode, connected to internal PHY\n");
            }

            if (num==0)
            {
                #ifdef CONFIG_USE_TANTOS_SWITCH
                //Force [FCON  => 011 ; RXTX], [FDUP => 01 ; full-duplex], [GMII => 10 ; 1000Mbps]
                //printf("Port 0a: MAC_CTRL_0: Force FCON=RXTX, FDUP=full-duplex, GMII=1000Mbps\n");
                REG32(VR9_ETHSW_MAC_CTRL_0 + ( num * 0x30))= 0x01B6;
                //printf("Port 0a: MAC_CTRL_0: value =0x%08x\n", REG32(VR9_ETHSW_MAC_CTRL_0 + ( num * 0x30)));
                #else
                /* Auto MII/GMII interface selection, enable padding*/
                REG32(VR9_ETHSW_MAC_CTRL_0 + ( num * 0x30))= 0x180;
                #endif
            }
            else
            {
                /* Auto MII/GMII interface selection, enable padding*/
                REG32(VR9_ETHSW_MAC_CTRL_0 + ( num * 0x30))= 0x180;

                /*JUMBO configured value, including any number of VLAN tags*/
                REG32(VR9_ETHSW_MAC_CTRL_2 + ( num * 0x30))= 0x0d;
            }
        }
    }

    asm("sync");
	
    // AT: Enable the adding of the CRC to packets coming from DMA to PMAC and going to the switch.
    REG32(VR9_ETHSW_PMAC_HD_CTL) |= (0x1 << 2);	//ADD CRC for packets from DMA to PMAC

    // AT: This setting was not needed for VR9 but was used on HN1 bootROM
    // AT: Enable the removal of the CRC for packets from PMAC to DMA
    // AT: Eliminate the setting because the code that processes the pkt takes that in account
    //REG32(VR9_ETHSW_PMAC_HD_CTL) |= (0x1 << 4); //REMOVE CRC for packets from PMAC to DMA
		
    /*To avoid the packet drop issue, please set the TXDLY bits of PCDU0 to 1.*/
    REG32(VR9_ETHSW_PCDU_0)=(REG32(VR9_ETHSW_PCDU_0) & (~0x7)) | 0x1;
#if defined(CONFIG_USE_TANTOS_SWITCH) && defined(CONFIG_HN1_SW_PORT_0a)
    /*Based on LAB observations the TXDLY and RXDLY bits of the PCDU0 has to be set to 3 */
    REG32(VR9_ETHSW_PCDU_0)= 0x183;
#elif defined(CONFIG_HN1_SW_PORT_0a)
    REG32(VR9_ETHSW_PCDU_0)= 0x00;
#endif

#ifdef CONFIG_USE_TANTOS_SWITCH
    //AT:
    //printf("TANTOS: Port5 state value = 0x%08x\n", tantos_read_mdio(0xA0));
    if (((tantos_read_mdio(0xA0))&0x01) == 0)
        printf("TANTOS: Link Down\n");
    else
        printf("TANTOS: Link Up\n");
    if (((tantos_read_mdio(0xA0))&0x04) == 0)
    {
        if (((tantos_read_mdio(0xA0))&0x02) == 0)
            printf("TANTOS: Speed 10Mbps\n");
        else
            printf("TANTOS: Speed 100Mbps\n");
    }
    else
        printf("TANTOS: Speed 1000Mbps\n");
    if (((tantos_read_mdio(0xA0))&0x08) == 0)
        printf("TANTOS: Half-Duplex\n");
    else
        printf("TANTOS: Full-Duplex\n");
    if (((tantos_read_mdio(0xA0))&0x10) == 0)
        printf("TANTOS: Flow control disabled\n");
    else
        printf("TANTOS: Flow control enabled\n");
#endif

#if (CONFIG_HN1_SW_PORT_0b | CONFIG_HN1_SW_PORT_1)
    //AT: Set and reset GPHY0 field of RST_REQ2 register of RCU
    printf("Reset internal PHY");
    #ifndef RUN_ON_EMULATOR
    REG32(BSP_RCU_RST_REQ2) = 0x80;
    mdelay(MS200);
    REG32(BSP_RCU_RST_REQ2) = 0x0;
    mdelay(MS200);
    #endif
    printf("...Done\n");
    asm("sync");

    #ifdef CONFIG_HN1_SW_PORT_0b
        printf("Internal phy(FE) firmware version: 0x%04x\n",vr9_mdio_read(0x11, 0x1e));
    #else
        printf("Internal phy(GE) firmware version: 0x%04x\n",vr9_mdio_read(0x11, 0x1e));
    #endif
#endif

//    printf("Read version of all MDIO attached devices: \n");
//    for (i=0; i<0x20; i++)
//    {
//        printf("Phy Address=0x%04x Version=0x%04x\n", i, vr9_mdio_read(i, 0x1e));
//        mdelay(MS100);
//    }

    hn1_dma_init();

    //printf("%s %s finish \n", __func__, __FILE__);
}



