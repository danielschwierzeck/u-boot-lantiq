/*****************************************************************************
 * Amazon-S uboot
 * Copyright (c) 2008, Infineon Technologies AG, All rights reserved
 * IFAP DC COM SD
 *****************************************************************************/
#ifndef __IFX_SSC_H
#define __IFX_SSC_H

/***********************************************************************/
/*  Module      :  SSC1 register address and bits                      */
/***********************************************************************/
#ifdef CONFIG_LANTIQ_UBOOT_grx500
#define IFX_SPI_BASE        (0xb6800000)
#else
#define IFX_SPI_BASE        (0xbe100800)
#endif
#define SPI_CLC             ((volatile u32*)(IFX_SPI_BASE+0x0000))
#define SPI_PISEL           ((volatile u32*)(IFX_SPI_BASE+0x0004))
#define SPI_ID              ((volatile u32*)(IFX_SPI_BASE+0x0008))
#define SPI_CON             ((volatile u32*)(IFX_SPI_BASE+0x0010))
#define SPI_STAT            ((volatile u32*)(IFX_SPI_BASE+0x0014))
#define SPI_WHBSTATE        ((volatile u32*)(IFX_SPI_BASE+0x0018))
#define SPI_TB              ((volatile u32*)(IFX_SPI_BASE+0x0020))
#define SPI_RB              ((volatile u32*)(IFX_SPI_BASE+0x0024))
#define SPI_RXFCON          ((volatile u32*)(IFX_SPI_BASE+0x0030))
#define SPI_TXFCON          ((volatile u32*)(IFX_SPI_BASE+0x0034))
#define SPI_FSTAT           ((volatile u32*)(IFX_SPI_BASE+0x0038))
#define SPI_BRT             ((volatile u32*)(IFX_SPI_BASE+0x0040))
#define SPI_BRSTAT          ((volatile u32*)(IFX_SPI_BASE+0x0044))
#define SPI_SFCON           ((volatile u32*)(IFX_SPI_BASE+0x0060))
#define SPI_SFSTAT          ((volatile u32*)(IFX_SPI_BASE+0x0064))
#define SPI_GPOCON          ((volatile u32*)(IFX_SPI_BASE+0x0070))
#define SPI_GPOSTAT         ((volatile u32*)(IFX_SPI_BASE+0x0074))
#define SPI_FGPO            ((volatile u32*)(IFX_SPI_BASE+0x0078))
#define SPI_RXREQ           ((volatile u32*)(IFX_SPI_BASE+0x0080))
#define SPI_RXCNT           ((volatile u32*)(IFX_SPI_BASE+0x0084))
#define SPI_DMACON          ((volatile u32*)(IFX_SPI_BASE+0x00ec))
#define SPI_IRNEN           ((volatile u32*)(IFX_SPI_BASE+0x00f4))
#define SPI_IRNICR          ((volatile u32*)(IFX_SPI_BASE+0x00f8))
#define SPI_IRNCR           ((volatile u32*)(IFX_SPI_BASE+0x000c))


/*control bits in SPI_CON*/
#define SPI_CON_RUEN            (1 << 12)
#define SPI_CON_TUEN            (1 << 11)
#define SPI_CON_AEN             (1 << 10)
#define SPI_CON_REN             (1 << 9)
#define SPI_CON_TEN             (1 << 8)
#define SPI_CON_LB              (1 << 7)
#define SPI_CON_PO              (1 << 6)
#define SPI_CON_PH              (1 << 5)
#define SPI_CON_HB              (1 << 4)
#define SPI_CON_BM(value)       (((( 1 << 5) - 1) & (value)) << 16)
#define SPI_CON_RX_OFF          (1 << 1)
#define SPI_CON_TX_OFF          (1 << 0)


/*control bits in SPI_STAT*/
#define SPI_STAT_EN         (1 << 0)
#define SPI_STAT_MS         (1 << 1)
#define SPI_STAT_BSY        (1 << 13)
#define SPI_STAT_RUE        (1 << 12)
#define SPI_STAT_TUE        (1 << 11)
#define SPI_STAT_AE         (1 << 10)
#define SPI_STAT_RE         (1 << 9)
#define SPI_STAT_TE         (1 << 8)
#define SPI_STAT_BC(value)  (((( 1 << 5) - 1) & (value)) << 16)

/***SSC Receive FIFO Control Register***/
#define SPI_RXFCON_RXFITL(value) (((( 1 << 6) - 1) & (value)) << 8)
#define SPI_RXFCON_RXTMEN    (1 << 2)
#define SPI_RXFCON_RXFLU     (1 << 1)
#define SPI_RXFCON_RXFEN     (1 << 0)
/***SSC Transmit FIFO Control Register***/
#define SPI_TXFCON_RXFITL(value) (((( 1 << 6) - 1) & (value)) << 8)
#define SPI_TXFCON_TXTMEN    (1 << 2)
#define SPI_TXFCON_TXFLU     (1 << 1)
#define SPI_TXFCON_TXFEN     (1 << 0)

/***SSC FIFO Status Register***/
#define SPI_FSTAT_TXFFL(value)   (((( 1 << 6) - 1) & (value)) << 8)
#define SPI_FSTAT_RXFFL(value)   (((( 1 << 6) - 1) & (value)) << 0)



#define DATA_WIDTH	         8
#define RXFIFO_SIZE          8
#define TXFIFO_SIZE          8

#define SFLASH_BAUDRATE	     2000000

enum {
    IFX_SSC_CS1 = 0, 
    IFX_SSC_CS2,
    IFX_SSC_CS3,
    IFX_SSC_CS4,
    IFX_SSC_CS5,
    IFX_SSC_CS6,
    IFX_SSC_CS7,
};

static inline void
ssc_cs_set(unsigned char bit)
{
    *SPI_FGPO = (1<<(bit+8));
}

static inline void ssc_cs_clr(unsigned char bit)
{
    *SPI_FGPO = (1<<(bit));
}

static inline void
ssc_sync(void)
{
    while(((*SPI_STAT) & SPI_STAT_BSY) == SPI_STAT_BSY);
}

static inline void ssc_tx_only(void)
{
    ssc_sync();
	/* change to TX only mode */
    *SPI_CON = ((*SPI_CON) & (~SPI_CON_TX_OFF)) | SPI_CON_RX_OFF;
}

static inline void ssc_rx_only(void)
{
    ssc_sync();
    /* change to RX only mode */
    *SPI_CON = ((*SPI_CON) & (~SPI_CON_RX_OFF)) | SPI_CON_TX_OFF;
	/* flush RX */
	*SPI_RXFCON = (*SPI_RXFCON) | SPI_RXFCON_RXFLU;
}

static inline void ssc_tx_rx(void)
{
    ssc_sync();
    /* change to TXRX */
    *SPI_CON = ((*SPI_CON) & ~(SPI_CON_RX_OFF))| SPI_CON_TX_OFF;
    /* flush RX */
    *SPI_RXFCON = (*SPI_RXFCON) | SPI_RXFCON_RXFLU;
}

static inline int ssc_write(unsigned char uc_value)
{
    ssc_sync();
	*SPI_TB = (u32)uc_value;
	ssc_sync();
	return 0;
}

static inline u8	ssc_read(void)
{
    ssc_sync();
    *SPI_RXREQ = 1;
    /* poll RIR */
    while((SPI_FSTAT_RXFFL(*SPI_FSTAT)) == 0) { };
	return (u8)(*SPI_RB);
}
	
extern int ssc_init(u32 baudrate);

#endif /* __IFX_SSC_H */
