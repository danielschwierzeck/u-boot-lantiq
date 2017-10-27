/*
 *  tsec.h
 *
 *  Driver for the Motorola Triple Speed Ethernet Controller
 *
 *  This software may be used and distributed according to the
 *  terms of the GNU Public License, Version 2, incorporated
 *  herein by reference.
 *
 * Copyright 2004, 2007 Freescale Semiconductor, Inc.
 * (C) Copyright 2003, Motorola, Inc.
 * maintained by Xianghua Xiao (x.xiao@motorola.com)
 * author Andy Fleming
 *
 */

#ifndef __TSEC_H
#define __TSEC_H

#include <net.h>
#include <config.h>
#include <configs/vbg400.h>


#define SYNOP_GMAC_ENHANCED_DESCRIPTOR

#define virt_to_phys(a)	(((unsigned long)(a)) & 0x1fffffff)

/*for running on gmac 2*/
//#define VBG400_GMAC_2

#define GMAC_BASE_ADDR_GMAC1    (0xa7180000 )
#define GMAC_BASE_ADDR          (0xa7040000 )
#define GMAC_DMA_BASE	        (GMAC_BASE_ADDR+0x1000 )
#define GMAC_DMA_BASE_GMAC1     (GMAC_BASE_ADDR_GMAC1+0x1000 )
#define GMAC_DEFAULT_PHY_ADRS	        0

#define TRANSMIT_DESC_SIZE  CFG_TX_ETH_BUFFER          //Tx Descriptors needed in the Descriptor pool/queue
#define RECEIVE_DESC_SIZE   PKTBUFSRX                  //Rx Descriptors needed in the Descriptor pool/queue

#define ETHERNET_HEADER             14  //6 byte Dest addr, 6 byte Src addr, 2 byte length/type
#define ETHERNET_CRC                 4  //Ethernet CRC
#define ETHERNET_EXTRA               2  //Only God knows about this?????
#define ETHERNET_PACKET_COPY       250  // Maximum length when received data is copied on to a new skb
#define ETHERNET_PACKET_EXTRA       18  // Preallocated length for the rx packets is MTU + ETHERNET_PACKET_EXTRA
#define VLAN_TAG                     4  //optional 802.1q VLAN Tag
#define MIN_ETHERNET_PAYLOAD        46  //Minimum Ethernet payload size
#define MAX_ETHERNET_PAYLOAD      1500  //Maximum Ethernet payload size
#define JUMBO_FRAME_PAYLOAD       9000  //Jumbo frame payload size

#define TX_BUF_SIZE        ETHERNET_HEADER + ETHERNET_CRC + MAX_ETHERNET_PAYLOAD + VLAN_TAG


//#define MII_WRITE	1
#define MII_WRITE	2
#define MII_READ	0
#define GmiiCsrClk40    0x3
#define GmiiCsrShift	2

#define MAC_ADDR_LEN 6
// This is the IP's phy address. This is unique address for every MAC in the universe
#define DEFAULT_MAC_ADDRESS {0x00, 0x55, 0x7B, 0xB5, 0x7D, 0xF7}

/* #define TSEC_TIMEOUT 	1000000 */
#define TSEC_TIMEOUT 1000
#define TOUT_LOOP 	1000000

#define PHY_AUTONEGOTIATE_TIMEOUT	5000 /* in ms */

/* MAC register bits */
#define MACCFG1_SOFT_RESET	0x80000000
#define MACCFG1_RESET_RX_MC	0x00080000
#define MACCFG1_RESET_TX_MC	0x00040000
#define MACCFG1_RESET_RX_FUN	0x00020000
#define	MACCFG1_RESET_TX_FUN	0x00010000
#define MACCFG1_LOOPBACK	0x00000100
#define MACCFG1_RX_FLOW		0x00000020
#define MACCFG1_TX_FLOW		0x00000010
#define MACCFG1_SYNCD_RX_EN	0x00000008
#define MACCFG1_RX_EN		0x00000004
#define MACCFG1_SYNCD_TX_EN	0x00000002
#define MACCFG1_TX_EN		0x00000001

#define MACCFG2_INIT_SETTINGS	0x00007205
#define MACCFG2_FULL_DUPLEX	0x00000001
#define MACCFG2_IF              0x00000300
#define MACCFG2_GMII		0x00000200
#define MACCFG2_MII             0x00000100

#define ECNTRL_INIT_SETTINGS	0x00001000
#define ECNTRL_TBI_MODE         0x00000020
#define ECNTRL_R100		0x00000008
#define ECNTRL_SGMII_MODE	0x00000002

#define miim_end -2
#define miim_read -1

#ifndef CFG_TBIPA_VALUE
    #define CFG_TBIPA_VALUE	0x1f
#endif
#define MIIMCFG_INIT_VALUE	0x00000003
#define MIIMCFG_RESET		0x80000000

#define MIIMIND_BUSY            0x00000001
#define MIIMIND_NOTVALID        0x00000004

#define MIIM_CONTROL            0x00
#define MIIM_CONTROL_RESET	0x00009140
#define MIIM_CONTROL_INIT       0x00001140
#define MIIM_CONTROL_RESTART    0x00001340
#define MIIM_ANEN               0x00001000

#define MIIM_CR                 0x00
#define MIIM_CR_RST		0x00008000
#define MIIM_CR_INIT	        0x00001000

#define MIIM_STATUS		0x1
#define MIIM_STATUS_AN_DONE 	0x00000020
#define MIIM_STATUS_LINK	0x0004
#define PHY_BMSR_AUTN_ABLE	0x0008
#define PHY_BMSR_AUTN_COMP	0x0020

#define MIIM_PHYSTAT		0x1
#define MIIM_PHYIR1		0x2
#define MIIM_PHYIR2		0x3

#define MIIM_ANAR		0x4
#define MIIM_ANAR_INIT		0x1e1

#define MIIM_TBI_ANLPBPA	0x5
#define MIIM_TBI_ANLPBPA_HALF	0x00000040
#define MIIM_TBI_ANLPBPA_FULL	0x00000020

#define MIIM_TBI_ANEX		0x6
#define MIIM_TBI_ANEX_NP	0x00000004
#define MIIM_TBI_ANEX_PRX	0x00000002

#define MIIM_GBIT_CONTROL	0x9
#define MIIM_GBIT_CONTROL_INIT	0xe00

#define MIIM_PHYCTL2		0x14
#define MIIM_PHYCTL2_CLKSEL	0x00000400

/* Broadcom BCM54xx -- taken from linux sungem_phy */
#define MIIM_BCM54xx_AUXSTATUS			0x19
#define MIIM_BCM54xx_AUXSTATUS_LINKMODE_MASK	0x0700
#define MIIM_BCM54xx_AUXSTATUS_LINKMODE_SHIFT	8

/* Cicada Auxiliary Control/Status Register */
#define MIIM_CIS8201_AUX_CONSTAT        0x1c
#define MIIM_CIS8201_AUXCONSTAT_INIT    0x0004
#define MIIM_CIS8201_AUXCONSTAT_DUPLEX  0x0020
#define MIIM_CIS8201_AUXCONSTAT_SPEED   0x0018
#define MIIM_CIS8201_AUXCONSTAT_GBIT    0x0010
#define MIIM_CIS8201_AUXCONSTAT_100     0x0008

/* Cicada Extended Control Register 1 */
#define MIIM_CIS8201_EXT_CON1           0x17
#define MIIM_CIS8201_EXTCON1_INIT       0x0000

/* Cicada 8204 Extended PHY Control Register 1 */
#define MIIM_CIS8204_EPHY_CON		0x17
#define MIIM_CIS8204_EPHYCON_INIT	0x0006
#define MIIM_CIS8204_EPHYCON_RGMII	0x1100

/* Cicada 8204 Serial LED Control Register */
#define MIIM_CIS8204_SLED_CON		0x1b
#define MIIM_CIS8204_SLEDCON_INIT	0x1115

#define MIIM_GBIT_CON		0x09
#define MIIM_GBIT_CON_ADVERT	0x0e00

/* Entry for Vitesse VSC8244 regs starts here */
/* Vitesse VSC8244 Auxiliary Control/Status Register */
#define MIIM_VSC8244_AUX_CONSTAT        0x1c
#define MIIM_VSC8244_AUXCONSTAT_INIT    0x0000
#define MIIM_VSC8244_AUXCONSTAT_DUPLEX  0x0020
#define MIIM_VSC8244_AUXCONSTAT_SPEED   0x0018
#define MIIM_VSC8244_AUXCONSTAT_GBIT    0x0010
#define MIIM_VSC8244_AUXCONSTAT_100     0x0008
#define MIIM_CONTROL_INIT_LOOPBACK      0x4000

/* Vitesse VSC8244 Extended PHY Control Register 1 */
#define MIIM_VSC8244_EPHY_CON           0x17
#define MIIM_VSC8244_EPHYCON_INIT       0x0006

/* Vitesse VSC8244 Serial LED Control Register */
#define MIIM_VSC8244_LED_CON            0x1b
#define MIIM_VSC8244_LEDCON_INIT        0xF011

/* 88E1011 PHY Status Register */
#define MIIM_88E1011_PHY_STATUS         0x11
#define MIIM_88E1011_PHYSTAT_SPEED      0xc000
#define MIIM_88E1011_PHYSTAT_GBIT       0x8000
#define MIIM_88E1011_PHYSTAT_100        0x4000
#define MIIM_88E1011_PHYSTAT_DUPLEX     0x2000
#define MIIM_88E1011_PHYSTAT_SPDDONE	0x0800
#define MIIM_88E1011_PHYSTAT_LINK	0x0400

#define MIIM_88E1011_PHY_SCR		0x10
#define MIIM_88E1011_PHY_MDI_X_AUTO	0x0060

/* 88E1111 PHY LED Control Register */
#define MIIM_88E1111_PHY_LED_CONTROL   24
#define MIIM_88E1111_PHY_LED_DIRECT    0x4100
#define MIIM_88E1111_PHY_LED_COMBINE   0x411C

/* 88E1145 Extended PHY Specific Control Register */
#define MIIM_88E1145_PHY_EXT_CR 20
#define MIIM_M88E1145_RGMII_RX_DELAY	0x0080
#define MIIM_M88E1145_RGMII_TX_DELAY	0x0002

#define MIIM_88E1145_PHY_PAGE   29
#define MIIM_88E1145_PHY_CAL_OV 30

/* RTL8211B PHY Status Register */
#define MIIM_RTL8211B_PHY_STATUS	0x11
#define MIIM_RTL8211B_PHYSTAT_SPEED	0xc000
#define MIIM_RTL8211B_PHYSTAT_GBIT	0x8000
#define MIIM_RTL8211B_PHYSTAT_100	0x4000
#define MIIM_RTL8211B_PHYSTAT_DUPLEX	0x2000
#define MIIM_RTL8211B_PHYSTAT_SPDDONE	0x0800
#define MIIM_RTL8211B_PHYSTAT_LINK	0x0400

/* DM9161 Control register values */
#define MIIM_DM9161_CR_STOP	0x0400
#define MIIM_DM9161_CR_RSTAN	0x1200

#define MIIM_DM9161_SCR		0x10
#define MIIM_DM9161_SCR_INIT	0x0610

/* DM9161 Specified Configuration and Status Register */
#define MIIM_DM9161_SCSR	0x11
#define MIIM_DM9161_SCSR_100F	0x8000
#define MIIM_DM9161_SCSR_100H	0x4000
#define MIIM_DM9161_SCSR_10F	0x2000
#define MIIM_DM9161_SCSR_10H	0x1000

/* DM9161 10BT Configuration/Status */
#define MIIM_DM9161_10BTCSR	0x12
#define MIIM_DM9161_10BTCSR_INIT	0x7800

/* LXT971 Status 2 registers */
#define MIIM_LXT971_SR2              0x11  /* Status Register 2  */
#define MIIM_LXT971_SR2_SPEED_MASK 0x4200
#define MIIM_LXT971_SR2_10HDX      0x0000  /*  10 Mbit half duplex selected */
#define MIIM_LXT971_SR2_10FDX      0x0200  /*  10 Mbit full duplex selected */
#define MIIM_LXT971_SR2_100HDX     0x4000  /* 100 Mbit half duplex selected */
#define MIIM_LXT971_SR2_100FDX     0x4200  /* 100 Mbit full duplex selected */

/* DP83865 Control register values */
#define MIIM_DP83865_CR_INIT	0x9200

/* DP83865 Link and Auto-Neg Status Register */
#define MIIM_DP83865_LANR	0x11
#define MIIM_DP83865_SPD_MASK	0x0018
#define MIIM_DP83865_SPD_1000	0x0010
#define MIIM_DP83865_SPD_100	0x0008
#define MIIM_DP83865_DPX_FULL	0x0002

#define MIIM_READ_COMMAND       0x00000001

#define MRBLR_INIT_SETTINGS	PKTSIZE_ALIGN

#define MINFLR_INIT_SETTINGS	0x00000040

#define readl(addr) \
              (((*(volatile unsigned int *)(addr))))
#define writel(b,addr) \
              ((*(volatile unsigned int *)(addr)) = ((b)))


/**********************************************************
 * GMAC registers Map
 * For Pci based system address is BARx + GmacRegisterBase
 * For any other system translation is done accordingly
 **********************************************************/
enum GmacRegisters              
{
  GmacConfig         = 0x0000,    /* Mac config Register                       */
  GmacFrameFilter    = 0x0004,    /* Mac frame filtering controls              */
  GmacHashHigh       = 0x0008,    /* Multi-cast hash table high                */
  GmacHashLow        = 0x000C,    /* Multi-cast hash table low                 */
  GmacGmiiAddr       = 0x0010,    /* GMII address Register(ext. Phy)           */
  GmacGmiiData       = 0x0014,    /* GMII data Register(ext. Phy)              */
  GmacFlowControl    = 0x0018,    /* Flow control Register                     */
  GmacVlan           = 0x001C,    /* VLAN tag Register (IEEE 802.1Q)           */
  
  GmacVersion        = 0x0020,    /* GMAC Core Version Register                */ 
  GmacWakeupAddr     = 0x0028,    /* GMAC wake-up frame filter adrress reg     */ 
  GmacPmtCtrlStatus  = 0x002C,    /* PMT control and status register           */ 
  
  GmacInterruptStatus= 0x0038,	  /* Mac Interrupt ststus register	       */  
  GmacInterruptMask  = 0x003C,	  /* Mac Interrupt Mask register	       */  
 
  GmacAddr0High      = 0x0040,    /* Mac address0 high Register                */
  GmacAddr0Low       = 0x0044,    /* Mac address0 low Register                 */
  GmacAddr1High      = 0x0048,    /* Mac address1 high Register                */
  GmacAddr1Low       = 0x004C,    /* Mac address1 low Register                 */
  GmacAddr2High      = 0x0050,    /* Mac address2 high Register                */
  GmacAddr2Low       = 0x0054,    /* Mac address2 low Register                 */
  GmacAddr3High      = 0x0058,    /* Mac address3 high Register                */
  GmacAddr3Low       = 0x005C,    /* Mac address3 low Register                 */
  GmacAddr4High      = 0x0060,    /* Mac address4 high Register                */
  GmacAddr4Low       = 0x0064,    /* Mac address4 low Register                 */
  GmacAddr5High      = 0x0068,    /* Mac address5 high Register                */
  GmacAddr5Low       = 0x006C,    /* Mac address5 low Register                 */
  GmacAddr6High      = 0x0070,    /* Mac address6 high Register                */
  GmacAddr6Low       = 0x0074,    /* Mac address6 low Register                 */
  GmacAddr7High      = 0x0078,    /* Mac address7 high Register                */
  GmacAddr7Low       = 0x007C,    /* Mac address7 low Register                 */
  GmacAddr8High      = 0x0080,    /* Mac address8 high Register                */
  GmacAddr8Low       = 0x0084,    /* Mac address8 low Register                 */
  GmacAddr9High      = 0x0088,    /* Mac address9 high Register                */
  GmacAddr9Low       = 0x008C,    /* Mac address9 low Register                 */
  GmacAddr10High     = 0x0090,    /* Mac address10 high Register               */
  GmacAddr10Low      = 0x0094,    /* Mac address10 low Register                */
  GmacAddr11High     = 0x0098,    /* Mac address11 high Register               */
  GmacAddr11Low      = 0x009C,    /* Mac address11 low Register                */
  GmacAddr12High     = 0x00A0,    /* Mac address12 high Register               */
  GmacAddr12Low      = 0x00A4,    /* Mac address12 low Register                */
  GmacAddr13High     = 0x00A8,    /* Mac address13 high Register               */
  GmacAddr13Low      = 0x00AC,    /* Mac address13 low Register                */
  GmacAddr14High     = 0x00B0,    /* Mac address14 high Register               */
  GmacAddr14Low      = 0x00B4,    /* Mac address14 low Register                */
  GmacAddr15High     = 0x00B8,    /* Mac address15 high Register               */
  GmacAddr15Low      = 0x00BC,    /* Mac address15 low Register                */
};

/**********************************************************
 * GMAC Network interface registers
 * This explains the Register's Layout
 
 * FES is Read only by default and is enabled only when Tx 
 * Config Parameter is enabled for RGMII/SGMII interface
 * during CoreKit Config.
 
 * DM is Read only with value 1'b1 in Full duplex only Config
 **********************************************************/

/* GmacConfig              = 0x0000,    Mac config Register  Layout */
enum GmacConfigReg      
{ 
                                             /* Bit description                      Bits         R/W   Reset value  */
  GmacTxConfRgmii          = 0x01000000,     /* (TC)Transmit Configuration in RGMII/SGMII/SMII  24  RW       0       */

  GmacWatchdog             = 0x00800000,
  GmacWatchdogDisable      = 0x00800000,     /* (WD)Disable watchdog timer on Rx      23           RW                */
  GmacWatchdogEnable       = 0x00000000,     /* Enable watchdog timer                                        0       */

  GmacJabber               = 0x00400000,
  GmacJabberDisable        = 0x00400000,     /* (JD)Disable jabber timer on Tx        22           RW                */
  GmacJabberEnable         = 0x00000000,     /* Enable jabber timer                                          0       */

  GmacFrameBurst           = 0x00200000,
  GmacFrameBurstEnable     = 0x00200000,     /* (BE)Enable frame bursting during Tx   21           RW                */
  GmacFrameBurstDisable    = 0x00000000,     /* Disable frame bursting                                       0       */
  
  GmacJumboFrame           = 0x00100000,
  GmacJumboFrameEnable     = 0x00100000,     /* (JE)Enable jumbo frame for Tx         20           RW                */
  GmacJumboFrameDisable    = 0x00000000,     /* Disable jumbo frame                                          0       */

  GmacInterFrameGap7       = 0x000E0000,     /* (IFG) Config7 - 40 bit times          19:17        RW                */
  GmacInterFrameGap6       = 0x000C0000,     /* (IFG) Config6 - 48 bit times                                         */
  GmacInterFrameGap5       = 0x000A0000,     /* (IFG) Config5 - 56 bit times                                         */
  GmacInterFrameGap4       = 0x00080000,     /* (IFG) Config4 - 64 bit times                                         */
  GmacInterFrameGap3       = 0x00040000,     /* (IFG) Config3 - 72 bit times                                         */
  GmacInterFrameGap2       = 0x00020000,     /* (IFG) Config2 - 80 bit times                                         */
  GmacInterFrameGap1       = 0x00010000,     /* (IFG) Config1 - 88 bit times                                         */
  GmacInterFrameGap0       = 0x00000000,     /* (IFG) Config0 - 96 bit times                                 000     */
  
  GmacMiiGmii              = 0x00008000,
  GmacSelectMii            = 0x00008000,     /* (PS)Port Select-MII mode              15           RW                */
  GmacSelectGmii           = 0x00000000,     /* GMII mode                                                    0       */

  GmacFESpeed100           = 0x00004000,
  GmacSelectFESpeed100     = 0x00004000,     /*(FES)Fast Ethernet speed 100Mbps       14           RW                */ 
  GmacSelectFESpeed10      = 0x00000000,     /* 10Mbps                                                       0       */ 

  GmacRxOwn                = 0x00002000, 
  GmacDisableRxOwn         = 0x00002000,     /* (DO)Disable receive own packets       13           RW                */
  GmacEnableRxOwn          = 0x00000000,     /* Enable receive own packets                                   0       */
  
  GmacLoopback             = 0x00001000,
  GmacLoopbackOn           = 0x00001000,     /* (LM)Loopback mode for GMII/MII        12           RW                */
  GmacLoopbackOff          = 0x00000000,     /* Normal mode                                                  0       */

  GmacDuplex               = 0x00000800,
  GmacFullDuplex           = 0x00000800,     /* (DM)Full duplex mode                  11           RW                */
  GmacHalfDuplex           = 0x00000000,     /* Half duplex mode                                             0       */

  GmacRxIpcOffload         = 0x00000400,     /*IPC checksum offload		      10           RW        0       */

  GmacRetry                = 0x00000200,
  GmacRetryDisable         = 0x00000200,     /* (DR)Disable Retry                      9           RW                */
  GmacRetryEnable          = 0x00000000,     /* Enable retransmission as per BL                              0       */

  GmacLinkUp               = 0x00000100,     /* (LUD)Link UP                           8           RW                */ 
  GmacLinkDown             = 0x00000100,     /* Link Down                                                    0       */ 
  
  GmacPadCrcStrip          = 0x00000080,
  GmacPadCrcStripEnable    = 0x00000080,     /* (ACS) Automatic Pad/Crc strip enable   7           RW                */
  GmacPadCrcStripDisable   = 0x00000000,     /* Automatic Pad/Crc stripping disable                          0       */
  
  GmacBackoffLimit         = 0x00000060,
  GmacBackoffLimit3        = 0x00000060,     /* (BL)Back-off limit in HD mode          6:5         RW                */
  GmacBackoffLimit2        = 0x00000040,     /*                                                                      */
  GmacBackoffLimit1        = 0x00000020,     /*                                                                      */
  GmacBackoffLimit0        = 0x00000000,     /*                                                              00      */

  GmacDeferralCheck        = 0x00000010,
  GmacDeferralCheckEnable  = 0x00000010,     /* (DC)Deferral check enable in HD mode   4           RW                */
  GmacDeferralCheckDisable = 0x00000000,     /* Deferral check disable                                       0       */
   
  GmacTx                   = 0x00000008,
  GmacTxEnable             = 0x00000008,     /* (TE)Transmitter enable                 3           RW                */
  GmacTxDisable            = 0x00000000,     /* Transmitter disable                                          0       */

  GmacRx                   = 0x00000004,
  GmacRxEnable             = 0x00000004,     /* (RE)Receiver enable                    2           RW                */
  GmacRxDisable            = 0x00000000,     /* Receiver disable                                             0       */
};

/* GmacFrameFilter    = 0x0004,     Mac frame filtering controls Register Layout*/
enum GmacFrameFilterReg 
{
  GmacFilter		   = 0x80000000,
  GmacFilterOff            = 0x80000000,     /* (RA)Receive all incoming packets       31         RW                 */
  GmacFilterOn             = 0x00000000,     /* Receive filtered packets only                                0       */

  GmacHashPerfectFilter	   = 0x00000400,     /*Hash or Perfect Filter enable           10         RW         0       */

  GmacSrcAddrFilter	   = 0x00000200,
  GmacSrcAddrFilterEnable  = 0x00000200,     /* (SAF)Source Address Filter enable       9         RW                 */
  GmacSrcAddrFilterDisable = 0x00000000,     /*                                                              0       */

  GmacSrcInvaAddrFilter    = 0x00000100,
  GmacSrcInvAddrFilterEn   = 0x00000100,     /* (SAIF)Inv Src Addr Filter enable        8         RW                 */
  GmacSrcInvAddrFilterDis  = 0x00000000,     /*                                                              0       */

  GmacPassControl	   = 0x000000C0,
  GmacPassControl3         = 0x000000C0,     /* (PCS)Forwards ctrl frms that pass AF    7:6       RW                 */
  GmacPassControl2         = 0x00000080,     /* Forwards all control frames                                          */
  GmacPassControl1         = 0x00000040,     /* Does not pass control frames                                         */
  GmacPassControl0         = 0x00000000,     /* Does not pass control frames                                 00      */

  GmacBroadcast		   = 0x00000020,
  GmacBroadcastDisable     = 0x00000020,     /* (DBF)Disable Rx of broadcast frames     5         RW                 */
  GmacBroadcastEnable      = 0x00000000,     /* Enable broadcast frames                                      0       */

  GmacMulticastFilter      = 0x00000010,
  GmacMulticastFilterOff   = 0x00000010,     /* (PM) Pass all multicast packets         4         RW                 */
  GmacMulticastFilterOn    = 0x00000000,     /* Pass filtered multicast packets                              0       */

  GmacDestAddrFilter       = 0x00000008,
  GmacDestAddrFilterInv    = 0x00000008,     /* (DAIF)Inverse filtering for DA          3         RW                 */
  GmacDestAddrFilterNor    = 0x00000000,     /* Normal filtering for DA                                      0       */

  GmacMcastHashFilter      = 0x00000004,
  GmacMcastHashFilterOn    = 0x00000004,     /* (HMC)perfom multicast hash filtering    2         RW                 */
  GmacMcastHashFilterOff   = 0x00000000,     /* perfect filtering only                                       0       */

  GmacUcastHashFilter      = 0x00000002,
  GmacUcastHashFilterOn    = 0x00000002,     /* (HUC)Unicast Hash filtering only        1         RW                 */
  GmacUcastHashFilterOff   = 0x00000000,     /* perfect filtering only                                       0       */

  GmacPromiscuousMode      = 0x00000001,
  GmacPromiscuousModeOn    = 0x00000001,     /* Receive all frames                      0         RW                 */
  GmacPromiscuousModeOff   = 0x00000000,     /* Receive filtered packets only                                0       */
};

 
/*GmacGmiiAddr             = 0x0010,    GMII address Register(ext. Phy) Layout          */
enum GmacGmiiAddrReg      
{
  GmiiDevMask              = 0x0000F800,     /* (PA)GMII device address                 15:11     RW         0x00    */
  GmiiDevShift             = 11,
  GmiiRegMask              = 0x000007C0,     /* (GR)GMII register in selected Phy       10:6      RW         0x00    */
  GmiiRegShift             = 6,  
  GmiiCsrClkMask	   = 0x0000001C,     /*CSR Clock bit Mask			 4:2			     */
  GmiiCsrClk5              = 0x00000014,     /* (CR)CSR Clock Range     250-300 MHz      4:2      RW         000     */
  GmiiCsrClk4              = 0x00000010,     /*                         150-250 MHz                                  */
  GmiiCsrClk3              = 0x0000000C,     /*                         35-60 MHz                                    */
  GmiiCsrClk2              = 0x00000008,     /*                         20-35 MHz                                    */
  GmiiCsrClk1              = 0x00000004,     /*                         100-150 MHz                                  */
  GmiiCsrClk0              = 0x00000000,     /*                         60-100 MHz                                   */

  GmiiWrite                = 0x00000002,     /* (GW)Write to register                      1      RW                 */
  GmiiRead                 = 0x00000000,     /* Read from register                                            0      */

  GmiiBusy                 = 0x00000001,     /* (GB)GMII interface is busy                 0      RW          0      */
};

/* GmacGmiiData            = 0x0014,    GMII data Register(ext. Phy) Layout             */
enum GmacGmiiDataReg      
{
  GmiiDataMask             = 0x0000FFFF,     /* (GD)GMII Data                             15:0    RW         0x0000  */
};


/*GmacFlowControl    = 0x0018,    Flow control Register   Layout                  */
enum GmacFlowControlReg  
{                                          
  GmacPauseTimeMask        = 0xFFFF0000,     /* (PT) PAUSE TIME field in the control frame  31:16   RW       0x0000  */
  GmacPauseTimeShift       = 16,
  
  GmacPauseLowThresh	   = 0x00000030,
  GmacPauseLowThresh3      = 0x00000030,     /* (PLT)thresh for pause tmr 256 slot time      5:4    RW               */
  GmacPauseLowThresh2      = 0x00000020,     /*                           144 slot time                              */
  GmacPauseLowThresh1      = 0x00000010,     /*                            28 slot time                              */
  GmacPauseLowThresh0      = 0x00000000,     /*                             4 slot time                       000    */

  GmacUnicastPauseFrame    = 0x00000008,
  GmacUnicastPauseFrameOn  = 0x00000008,     /* (UP)Detect pause frame with unicast addr.     3    RW                */
  GmacUnicastPauseFrameOff = 0x00000000,     /* Detect only pause frame with multicast addr.                   0     */

  GmacRxFlowControl	   = 0x00000004,
  GmacRxFlowControlEnable  = 0x00000004,     /* (RFE)Enable Rx flow control                   2    RW                */
  GmacRxFlowControlDisable = 0x00000000,     /* Disable Rx flow control                                        0     */

  GmacTxFlowControl   	   = 0x00000002,
  GmacTxFlowControlEnable  = 0x00000002,     /* (TFE)Enable Tx flow control                   1    RW                */
  GmacTxFlowControlDisable = 0x00000000,     /* Disable flow control                                           0     */

  GmacFlowControlBackPressure= 0x00000001,
  GmacSendPauseFrame       = 0x00000001,     /* (FCB/PBA)send pause frm/Apply back pressure   0    RW          0     */
};

/**********************************************************
 * GMAC DMA registers
 * For Pci based system address is BARx + GmaDmaBase
 * For any other system translation is done accordingly
 **********************************************************/

enum DmaRegisters             
{
  DmaBusMode        = 0x0000,    /* CSR0 - Bus Mode Register                          */
  DmaTxPollDemand   = 0x0004,    /* CSR1 - Transmit Poll Demand Register              */
  DmaRxPollDemand   = 0x0008,    /* CSR2 - Receive Poll Demand Register               */
  DmaRxBaseAddr     = 0x000C,    /* CSR3 - Receive Descriptor list base address       */
  DmaTxBaseAddr     = 0x0010,    /* CSR4 - Transmit Descriptor list base address      */
  DmaStatus         = 0x0014,    /* CSR5 - Dma status Register                        */
  DmaControl        = 0x0018,    /* CSR6 - Dma Operation Mode Register                */
  DmaInterrupt      = 0x001C,    /* CSR7 - Interrupt enable                           */
  DmaMissedFr       = 0x0020,    /* CSR8 - Missed Frame & Buffer overflow Counter     */
  DmaTxCurrDesc     = 0x0048,    /*      - Current host Tx Desc Register              */ 
  DmaRxCurrDesc     = 0x004C,    /*      - Current host Rx Desc Register              */ 
  DmaTxCurrAddr     = 0x0050,    /* CSR20 - Current host transmit buffer address      */
  DmaRxCurrAddr     = 0x0054,    /* CSR21 - Current host receive buffer address       */
};

/**********************************************************
 * DMA Engine registers Layout
 **********************************************************/

/*DmaBusMode               = 0x0000,    CSR0 - Bus Mode */
enum DmaBusModeReg         
{                                         /* Bit description                                Bits     R/W   Reset value */
  DmaAAL		  		  = 0x04000000,

  DmaUseSeparatePBL       = 0x00800000,   /* (USP) Use separate PBL for Tx and Rx            23      RW                */

  DmaRxBurstLength32      = 0x00400000,   /* (RPBL) programmable Dma burst length = 32      22:17    RW                */
  DmaRxBurstLength16      = 0x00200000,   /* Dma burst length = 16                                                     */
  DmaRxBurstLength8       = 0x00100000,   /* Dma burst length = 8                                                      */
  DmaRxBurstLength4       = 0x00080000,   /* Dma burst length = 4                                                      */
  DmaRxBurstLength2       = 0x00040000,   /* Dma burst length = 2                                                      */
  DmaRxBurstLength1       = 0x00020000,   /* Dma burst length = 1                                                      */
  										  /*                                                                    0x01   */

  DmaFixedBurstEnable     = 0x00010000,   /* (FB)Fixed Burst SINGLE, INCR4, INCR8 or INCR16   16     RW                */
  DmaFixedBurstDisable    = 0x00000000,   /*             SINGLE, INCR                                          0       */

  DmaTxPriorityRatio11    = 0x00000000,   /* (PR)TX:RX DMA priority ratio 1:1                15:14   RW        00      */ 
  DmaTxPriorityRatio21    = 0x00004000,   /* (PR)TX:RX DMA priority ratio 2:1                                          */ 
  DmaTxPriorityRatio31    = 0x00008000,   /* (PR)TX:RX DMA priority ratio 3:1                                          */ 
  DmaTxPriorityRatio41    = 0x0000C000,   /* (PR)TX:RX DMA priority ratio 4:1                                          */ 
  
  DmaBurstLength32        = 0x00002000,   /* (PBL) programmable Dma burst length = 32        13:8    RW                */
  DmaBurstLength16        = 0x00001000,   /* Dma burst length = 16                                                     */
  DmaBurstLength8         = 0x00000800,   /* Dma burst length = 8                                                      */
  DmaBurstLength4         = 0x00000400,   /* Dma burst length = 4                                                      */
  DmaBurstLength2         = 0x00000200,   /* Dma burst length = 2                                                      */
  DmaBurstLength1         = 0x00000100,   /* Dma burst length = 1                                                      */
  DmaBurstLength0         = 0x00000000,   /* Dma burst length = 0                                               0x01   */

  DmaDescriptorSkip16     = 0x00000040,   /* (DSL)Descriptor skip length (no.of dwords)       6:2     RW               */
  DmaDescriptorSkip8      = 0x00000020,   /* between two unchained descriptors                                         */
  DmaDescriptorSkip4      = 0x00000010,   /*                                                                           */
  DmaDescriptorSkip2      = 0x00000008,   /*                                                                           */
  DmaDescriptorSkip1      = 0x00000004,   /*                                                                           */
  DmaDescriptorSkip0      = 0x00000000,   /*                                                                    0x00   */

  DmaArbitRr              = 0x00000000,   /* (DA) DMA RR arbitration                            1     RW         0     */ 
  DmaArbitPr              = 0x00000002,   /* Rx has priority over Tx                                                   */  
  
  DmaResetOn              = 0x00000001,   /* (SWR)Software Reset DMA engine                     0     RW               */
  DmaResetOff             = 0x00000000,   /*                                                                      0    */
};


/*DmaStatus         = 0x0014,    CSR5 - Dma status Register                        */
enum DmaStatusReg         
{ 
  /*Bit 28 27 and 26 indicate whether the interrupt due to PMT GMACMMC or GMAC LINE Remaining bits are DMA interrupts*/                      
  GmacPmtIntr             = 0x10000000,   /* (GPI)Gmac subsystem interrupt                      28     RO       0       */ 
  GmacMmcIntr             = 0x08000000,   /* (GMI)Gmac MMC subsystem interrupt                  27     RO       0       */ 
  GmacLineIntfIntr        = 0x04000000,   /* Line interface interrupt                           26     RO       0       */

  DmaErrorBit2            = 0x02000000,   /* (EB)Error bits 0-data buffer, 1-desc. access       25     RO       0       */
  DmaErrorBit1            = 0x01000000,   /* (EB)Error bits 0-write trnsf, 1-read transfr       24     RO       0       */
  DmaErrorBit0            = 0x00800000,   /* (EB)Error bits 0-Rx DMA, 1-Tx DMA                  23     RO       0       */

  DmaTxState              = 0x00700000,   /* (TS)Transmit process state                         22:20  RO               */
  DmaTxStopped            = 0x00000000,   /* Stopped - Reset or Stop Tx Command issued                         000      */
  DmaTxFetching           = 0x00100000,   /* Running - fetching the Tx descriptor                                       */
  DmaTxWaiting            = 0x00200000,   /* Running - waiting for status                                               */
  DmaTxReading            = 0x00300000,   /* Running - reading the data from host memory                                */
  DmaTxSuspended          = 0x00600000,   /* Suspended - Tx Descriptor unavailabe                                       */
  DmaTxClosing            = 0x00700000,   /* Running - closing Rx descriptor                                            */

  DmaRxState              = 0x000E0000,   /* (RS)Receive process state                         19:17  RO                */
  DmaRxStopped            = 0x00000000,   /* Stopped - Reset or Stop Rx Command issued                         000      */
  DmaRxFetching           = 0x00020000,   /* Running - fetching the Rx descriptor                                       */
  DmaRxWaiting            = 0x00060000,   /* Running - waiting for packet                                               */
  DmaRxSuspended          = 0x00080000,   /* Suspended - Rx Descriptor unavailable                                      */
  DmaRxClosing            = 0x000A0000,   /* Running - closing descriptor                                               */
  DmaRxQueuing            = 0x000E0000,   /* Running - queuing the recieve frame into host memory                       */

  DmaIntNormal            = 0x00010000,   /* (NIS)Normal interrupt summary                     16     RW        0       */
  DmaIntAbnormal          = 0x00008000,   /* (AIS)Abnormal interrupt summary                   15     RW        0       */

  DmaIntEarlyRx           = 0x00004000,   /* Early receive interrupt (Normal)       RW        0       */
  DmaIntBusError          = 0x00002000,   /* Fatal bus error (Abnormal)             RW        0       */
  DmaIntEarlyTx           = 0x00000400,   /* Early transmit interrupt (Abnormal)    RW        0       */
  DmaIntRxWdogTO          = 0x00000200,   /* Receive Watchdog Timeout (Abnormal)    RW        0       */
  DmaIntRxStopped         = 0x00000100,   /* Receive process stopped (Abnormal)     RW        0       */
  DmaIntRxNoBuffer        = 0x00000080,   /* Receive buffer unavailable (Abnormal)  RW        0       */
  DmaIntRxCompleted       = 0x00000040,   /* Completion of frame reception (Normal) RW        0       */
  DmaIntTxUnderflow       = 0x00000020,   /* Transmit underflow (Abnormal)          RW        0       */
  DmaIntRcvOverflow       = 0x00000010,   /* Receive Buffer overflow interrupt      RW        0       */
  DmaIntTxJabberTO        = 0x00000008,   /* Transmit Jabber Timeout (Abnormal)     RW        0       */
  DmaIntTxNoBuffer        = 0x00000004,   /* Transmit buffer unavailable (Normal)   RW        0       */
  DmaIntTxStopped         = 0x00000002,   /* Transmit process stopped (Abnormal)    RW        0       */
  DmaIntTxCompleted       = 0x00000001,   /* Transmit completed (Normal)            RW        0       */
};

/*DmaControl        = 0x0018,     CSR6 - Dma Operation Mode Register                */
enum DmaControlReg        
{ 
  DmaDisableDropTcpCs	  = 0x04000000,   /* (DT) Dis. drop. of tcp/ip CS error frames        26      RW        0       */
  DmaDisablFlushFrames	  = 0x01000000,   /* (DFF) Dis. flush. of rx frames                   24      RW        0       */
  DmaStoreAndForward      = 0x00200000,   /* (SF)Store and forward                            21      RW        0       */
  DmaFlushTxFifo          = 0x00100000,   /* (FTF)Tx FIFO controller is reset to default      20      RW        0       */ 
  
  DmaTxThreshCtrl         = 0x0001C000,   /* (TTC)Controls thre Threh of MTL tx Fifo          16:14   RW                */ 
  DmaTxThreshCtrl16       = 0x0001C000,   /* (TTC)Controls thre Threh of MTL tx Fifo 16       16:14   RW                */ 
  DmaTxThreshCtrl24       = 0x00018000,   /* (TTC)Controls thre Threh of MTL tx Fifo 24       16:14   RW                */ 
  DmaTxThreshCtrl32       = 0x00014000,   /* (TTC)Controls thre Threh of MTL tx Fifo 32       16:14   RW                */ 
  DmaTxThreshCtrl40       = 0x00010000,   /* (TTC)Controls thre Threh of MTL tx Fifo 40       16:14   RW                */   
  DmaTxThreshCtrl256      = 0x0000c000,   /* (TTC)Controls thre Threh of MTL tx Fifo 256      16:14   RW                */   
  DmaTxThreshCtrl192      = 0x00008000,   /* (TTC)Controls thre Threh of MTL tx Fifo 192      16:14   RW                */   
  DmaTxThreshCtrl128      = 0x00004000,   /* (TTC)Controls thre Threh of MTL tx Fifo 128      16:14   RW                */   
  DmaTxThreshCtrl64       = 0x00000000,   /* (TTC)Controls thre Threh of MTL tx Fifo 64       16:14   RW        000     */ 
  
  DmaTxStart              = 0x00002000,   /* (ST)Start/Stop transmission                      13      RW        0       */

  DmaRxFlowCtrlDeact      = 0x00001800,   /* (RFD)Rx flow control deact. threhold             12:11   RW                 */ 
  DmaRxFlowCtrlDeact1K    = 0x00000000,   /* (RFD)Rx flow control deact. threhold (1kbytes)   12:11   RW        00       */ 
  DmaRxFlowCtrlDeact2K    = 0x00000800,   /* (RFD)Rx flow control deact. threhold (2kbytes)   12:11   RW                 */ 
  DmaRxFlowCtrlDeact3K    = 0x00001000,   /* (RFD)Rx flow control deact. threhold (3kbytes)   12:11   RW                 */ 
  DmaRxFlowCtrlDeact4K    = 0x00001800,   /* (RFD)Rx flow control deact. threhold (4kbytes)   12:11   RW                 */ 	
  
  DmaRxFlowCtrlAct        = 0x00001800,   /* (RFA)Rx flow control Act. threhold               12:11   RW                 */ 
  DmaRxFlowCtrlAct1K      = 0x00000000,   /* (RFA)Rx flow control Act. threhold (1kbytes)     12:11   RW        00       */ 
  DmaRxFlowCtrlAct2K      = 0x00000800,   /* (RFA)Rx flow control Act. threhold (2kbytes)     12:11   RW                 */ 
  DmaRxFlowCtrlAct3K      = 0x00001000,   /* (RFA)Rx flow control Act. threhold (3kbytes)     12:11   RW                 */ 
  DmaRxFlowCtrlAct4K      = 0x00001800,   /* (RFA)Rx flow control Act. threhold (4kbytes)     12:11   RW                 */ 	
  
  DmaEnHwFlowCtrl         = 0x00010000,   /* (EFC)Enable HW flow control                      8       RW                 */ 
  DmaDisHwFlowCtrl        = 0x00000000,   /* Disable HW flow control                                            0        */ 
        
  DmaFwdErrorFrames       = 0x00000080,   /* (FEF)Forward error frames                        7       RW        0       */
  DmaFwdUnderSzFrames     = 0x00000040,   /* (FUF)Forward undersize frames                    6       RW        0       */
  DmaTxSecondFrame        = 0x00000004,   /* (OSF)Operate on second frame                     4       RW        0       */
  DmaRxStart              = 0x00000002,   /* (SR)Start/Stop reception                         1       RW        0       */
};


/*DmaInterrupt      = 0x001C,    CSR7 - Interrupt enable Register Layout     */
enum  DmaInterruptReg
{                     
  DmaIeNormal            = DmaIntNormal     ,   /* Normal interrupt enable                 RW        0       */
  DmaIeAbnormal          = DmaIntAbnormal   ,   /* Abnormal interrupt enable               RW        0       */

  DmaIeEarlyRx           = DmaIntEarlyRx    ,   /* Early receive interrupt enable          RW        0       */
  DmaIeBusError          = DmaIntBusError   ,   /* Fatal bus error enable                  RW        0       */
  DmaIeEarlyTx           = DmaIntEarlyTx    ,   /* Early transmit interrupt enable         RW        0       */
  DmaIeRxWdogTO          = DmaIntRxWdogTO   ,   /* Receive Watchdog Timeout enable         RW        0       */
  DmaIeRxStopped         = DmaIntRxStopped  ,   /* Receive process stopped enable          RW        0       */
  DmaIeRxNoBuffer        = DmaIntRxNoBuffer ,   /* Receive buffer unavailable enable       RW        0       */
  DmaIeRxCompleted       = DmaIntRxCompleted,   /* Completion of frame reception enable    RW        0       */
  DmaIeTxUnderflow       = DmaIntTxUnderflow,   /* Transmit underflow enable               RW        0       */

  DmaIeRxOverflow        = DmaIntRcvOverflow,   /* Receive Buffer overflow interrupt       RW        0       */
  DmaIeTxJabberTO        = DmaIntTxJabberTO ,   /* Transmit Jabber Timeout enable          RW        0       */
  DmaIeTxNoBuffer        = DmaIntTxNoBuffer ,   /* Transmit buffer unavailable enable      RW        0       */
  DmaIeTxStopped         = DmaIntTxStopped  ,   /* Transmit process stopped enable         RW        0       */
  DmaIeTxCompleted       = DmaIntTxCompleted,   /* Transmit completed enable               RW        0       */
};




/**********************************************************
 * DMA Engine descriptors
 **********************************************************/

/*
DmaRxBaseAddr     = 0x000C,   CSR3 - Receive Descriptor list base address       
DmaRxBaseAddr is the pointer to the first Rx Descriptors. the Descriptor format in Little endian with a
32 bit Data bus is as shown below 

Similarly 
DmaTxBaseAddr     = 0x0010,  CSR4 - Transmit Descriptor list base address
DmaTxBaseAddr is the pointer to the first Rx Descriptors. the Descriptor format in Little endian with a
32 bit Data bus is as shown below
                  --------------------------------------------------------------------
    RDES0/TDES0  |OWN (31)| Status                                                   |
 		  --------------------------------------------------------------------
    RDES1/TDES1  | Control Bits | Byte Count Buffer 2 | Byte Count Buffer 1          |
		  --------------------------------------------------------------------
    RDES2/TDES2  |  Buffer 1 Address                                                 |
		  --------------------------------------------------------------------
    RDES3/TDES3  |  Buffer 2 Address / Next Descriptor Address                       |
		  --------------------------------------------------------------------
OR in case of enhanced descriptor
          --------------------------------------------------------------------
    RDES0/TDES0  |OWN (31)| Control Bits | Reserved | Control Bits | Status          |
 		  --------------------------------------------------------------------
    RDES1/TDES1  | Reserved | Byte Count Buffer 2 | Reserved | Byte Count Buffer 1   |
		  --------------------------------------------------------------------
    RDES2/TDES2  |  Buffer 1 Address                                                 |
		  --------------------------------------------------------------------
    RDES3/TDES3  |  Buffer 2 Address / Next Descriptor Address                       |
		  --------------------------------------------------------------------

*/


enum DmaDescriptorStatus    /* status word of DMA descriptor */
{
  DescOwnByDma          = 0x80000000,   /* (OWN)Descriptor is owned by DMA engine             31      RW    */
#ifdef SYNOP_GMAC_ENHANCED_DESCRIPTOR
  DescTxIntEnable       = 0x40000000,   /* (IC)Tx - interrupt on completion                   30     		*/
  DescTxLast            = 0x20000000,   /* (LS)Tx - Last segment of the frame                 29     		*/
  DescTxFirst           = 0x10000000,   /* (FS)Tx - First segment of the frame                28    		*/
  DescTxDisableCrc      = 0x08000000,   /* (DC)Tx - Add CRC disabled (first segment only)     27    		*/
  DescTxDisablePadd  	= 0x04000000,   /* (DP)disable padding, added by - reyaz              26    		*/
  DescTxTsEnabled	  	= 0x02000000,   /* (TTSE)Tx timestamp enable                          25    		*/
  DescTxChecksumCtrl    = 0x00c00000,   /* (CIC)Tx - Checksum insertion control            23:22 			*/
  DescTxChecksumDis     = 0,
  DescTxChecksumHdrOnly = 1,
  DescTxChecksumEnb     = 2,
  DescTxChecksumFull    = 3,
  DescTxEndOfRing	  	= 0x00200000,   /* (TER)Tx End of descriptors ring                    21    		*/
  DescTxSecondAddrCh  	= 0x00100000,   /* (TCH)Tx Second address chained                     20    		*/
#endif  
  DescTxTsStatus	  	= 0x00020000,   /* (TTSS)Tx timestamp status                          17    		*/
  DescTxIpv4ChkError    = 0x00010000,   /* (IHE) Tx Ip header error                           16			*/
  DescTxErrSummary      = 0x00008000,   /* (ES)Tx - Transmit error summary                    15    		*/
  DescTxTimeout         = 0x00004000,   /* (JT)Tx - Transmit jabber timeout                   14    		*/
  DescTxFrameFlushed    = 0x00002000,   /* (FF)Tx - DMA/MTL flushed the frame due to SW flush 13    		*/
  DescTxPayChkError     = 0x00001000,   /* (PCE) Tx Payload checksum Error                    12    		*/
  DescTxLostCarrier     = 0x00000800,   /* (LC)Tx - carrier lost during tramsmission          11    		*/
  DescTxNoCarrier       = 0x00000400,   /* (NC)Tx - no carrier signal from the tranceiver     10    		*/
  DescTxLateCollision   = 0x00000200,   /* (LC)Tx - transmission aborted due to collision      9    		*/
  DescTxExcCollisions   = 0x00000100,   /* (EC)Tx - transmission aborted after 16 collisions   8    		*/
  DescTxVLANFrame       = 0x00000080,   /* (VF)Tx - VLAN-type frame                            7    		*/
  DescTxCollMask        = 0x00000078,   /* (CC)Tx - Collision count                          6:3  			*/
  DescTxCollShift       = 3,
  DescTxExcDeferral     = 0x00000004,   /* (ED)Tx - excessive deferral                         2   			*/
  DescTxUnderflow       = 0x00000002,   /* (UF)Tx - late data arrival from the memory          1   			*/
  DescTxDeferred        = 0x00000001,   /* (DB)Tx - frame transmision deferred                 0   			*/

  DescDAFilterFail      = 0x40000000,   /* (AFM)Rx - DA Filter Fail for the rx frame           30    		*/
  DescFrameLengthMask   = 0x3FFF0000,   /* (FL)Receive descriptor frame length              29:16   		*/
  DescFrameLengthShift  = 16,
  DescError             = 0x00008000,   /* (ES)Error summary bit  - OR of the follo. bits:     15    		*/
					/*  DE || OE || IPC || LC || RWT || RE || CE */
  DescRxTruncated       = 0x00004000,   /* (DE)Rx - no more descriptors for receive frame      14   		*/
  DescSAFilterFail      = 0x00002000,   /* (SAF)Rx - SA Filter Fail for the received frame     13    		*/
  DescRxLengthError 	= 0x00001000,   /* (LE)Rx - frm size not matching with len field       12    		*/
  DescRxDamaged         = 0x00000800,   /* (OE)Rx - frm was damaged due to buffer overflow     11   		*/
  DescRxVLANTag         = 0x00000400,   /* (VLAN)Rx - received frame is a VLAN frame           10    		*/
  DescRxFirst           = 0x00000200,   /* (FS)Rx - first descriptor of the frame               9    		*/
  DescRxLast            = 0x00000100,   /* (LS)Rx - last descriptor of the frame                8   		*/
  DescRxLongFrame       = 0x00000080,   /* (Giant Frame)Rx - frame is longer than 1518/1522     7   		*/
  DescRxIpv4ChkError    = 0x00000080,   /* (IPC CS ERROR)Rx - Ipv4 header checksum error        7    		*/
  DescRxCollision       = 0x00000040,   /* (LC)Rx - late collision occurred during reception    6    		*/
  DescRxFrameEther      = 0x00000020,   /* (FT)Rx - Frame type - Ethernet, otherwise 802.3      5   		*/
  DescRxWatchdog        = 0x00000010,   /* (RWT)Rx - watchdog timer expired during reception    4    		*/
  DescRxMiiError        = 0x00000008,   /* (RE)Rx - error reported by MII interface             3   		*/
  DescRxDribbling       = 0x00000004,   /* (DE)Rx - frame contains non int multiple of 8 bits   2   		*/
  DescRxCrc             = 0x00000002,   /* (CE)Rx - CRC error                                   1   		*/
  DescRxPayChkError     = 0x00000001,   /* ()  Rx - Rx Payload Checksum Error                   0   		*/
  DescRxMacMatch        = 0x00000001,   /* (RX MAC Address) Rx mac address reg(1 to 15)match    0   		*/
};
/*
This explains the RDES1/TDES1 bits layout
		  --------------------------------------------------------------------
    RDES1/TDES1  | Control Bits | Byte Count Buffer 2 | Byte Count Buffer 1  |
		  --------------------------------------------------------------------
OR in case of ehanced descriptor
		  --------------------------------------------------------------------
    RDES1/TDES1  | CTRL (31) | Reserved | Control Bits | Byte Count Buffer 1 |
		  --------------------------------------------------------------------
*/
enum DmaDescriptorLength    /* length word of DMA descriptor */
{
//  DescTxIntEnable       = 0x80000000,   /* (IC)Tx - interrupt on completion                    31  			*/
#ifdef SYNOP_GMAC_ENHANCED_DESCRIPTOR
  DescSize2Mask         = 0x2FFF0000,   /* (BS2) Buffer 2 size                              28:16  			*/
  DescSize2Shift        = 16,
  DescEndOfRing         = 0x00008000,   /* (RER)End of Rx descriptors ring                     15   		*/
  DescChain             = 0x00004000,   /* (RCH)Second buffer address is chain address         14  			*/
  DescSize1Mask         = 0x00001FFF,   /* (BS1) Buffer 1 size                               12:0  			*/
  DescSize1Shift        = 0,
#else
  DescTxLast            = 0x40000000,   /* (LS)Tx - Last segment of the frame                  30   		*/
  DescTxFirst           = 0x20000000,   /* (FS)Tx - First segment of the frame                 29   		*/
  DescTxDisableCrc      = 0x04000000,   /* (DC)Tx - Add CRC disabled (first segment only)      26   		*/
  DescEndOfRing         = 0x02000000,   /* (TER)End of descriptors ring                        25   		*/
  DescChain             = 0x01000000,   /* (TCH)Second buffer address is chain address         24  			*/
  DescTxDisablePadd	    = 0x00800000,   /* (DP)disable padding, added by - reyaz               23  			*/
  DescSize2Mask         = 0x003FF800,   /* (TBS2) Buffer 2 size                             21:11  			*/
  DescSize2Shift        = 11,
  DescSize1Mask         = 0x000007FF,   /* (TBS1) Buffer 1 size                              10:0  			*/
  DescSize1Shift        = 0,

  DescTxCisMask  	    = 0x18000000,   /* Tx checksum offloading control mask			    28:27			*/
  DescTxCisBypass	    = 0x00000000,   /* Checksum bypass								                    */
  DescTxCisIpv4HdrCs	= 0x08000000,   /* IPv4 header checksum								                */
  DescTxCisTcpOnlyCs    = 0x10000000,/* TCP/UDP/ICMP checksum. Pseudo header checksum is assumed to be present */
  DescTxCisTcpPseudoCs  = 0x18000000,/* TCP/UDP/ICMP checksum fully in hardware including pseudo header		*/
#endif
};

/**********************************************************
 * DMA engine interrupt handling functions
 **********************************************************/
 
 enum synopGMACDmaIntEnum  /* Intrerrupt types */
{
  synopGMACDmaRxNormal   = 0x01,   /* normal receiver interrupt */
  synopGMACDmaRxAbnormal = 0x02,   /* abnormal receiver interrupt */
  synopGMACDmaRxStopped  = 0x04,   /* receiver stopped */
  synopGMACDmaTxNormal   = 0x08,   /* normal transmitter interrupt */
  synopGMACDmaTxAbnormal = 0x10,   /* abnormal transmitter interrupt */
  synopGMACDmaTxStopped  = 0x20,   /* transmitter stopped */
  synopGMACDmaError      = 0x80,   /* Dma engine error */
};


/**********************************************************
 * Initial register values
 **********************************************************/
enum InitialRegisters
{
   /* Full-duplex mode with perfect filter on */
  GmacConfigInitFdx1000   = GmacWatchdogEnable | GmacJabberEnable         | GmacFrameBurstEnable | GmacJumboFrameDisable
                          | GmacSelectGmii     | GmacEnableRxOwn          | GmacLoopbackOff
                          | GmacFullDuplex     | GmacRetryEnable          | GmacPadCrcStripDisable
                          | GmacBackoffLimit0  | GmacDeferralCheckDisable | GmacTxEnable          | GmacRxEnable,
  
  /* Full-duplex mode with perfect filter on */
  GmacConfigInitFdx110    = GmacWatchdogEnable | GmacJabberEnable         | GmacFrameBurstEnable  | GmacJumboFrameDisable
                          | GmacSelectMii      | GmacEnableRxOwn          | GmacLoopbackOff
                          | GmacFullDuplex     | GmacRetryEnable          | GmacPadCrcStripDisable
                          | GmacBackoffLimit0  | GmacDeferralCheckDisable | GmacTxEnable          | GmacRxEnable,

   /* Full-duplex mode */
   // CHANGED: Pass control config, dest addr filter normal, added source address filter, multicast & unicast 
   // Hash filter. 
   /*                        = GmacFilterOff         | GmacPassControlOff | GmacBroadcastEnable */
   GmacFrameFilterInitFdx = GmacFilterOn          | GmacPassControl0   | GmacBroadcastEnable |  GmacSrcAddrFilterDisable
                           | GmacMulticastFilterOn | GmacDestAddrFilterNor | GmacMcastHashFilterOff
                          | GmacPromiscuousModeOff | GmacUcastHashFilterOff,
   
   /* Full-duplex mode */
   GmacFlowControlInitFdx = GmacUnicastPauseFrameOff | GmacRxFlowControlEnable | GmacTxFlowControlEnable,

   /* Full-duplex mode */
   GmacGmiiAddrInitFdx    = GmiiCsrClk2,


   /* Half-duplex mode with perfect filter on */
   // CHANGED: Removed Endian configuration, added single bit config for PAD/CRC strip,   			  
   /*| GmacSelectMii      | GmacLittleEndian         | GmacDisableRxOwn      | GmacLoopbackOff*/
   GmacConfigInitHdx1000  = GmacWatchdogEnable | GmacJabberEnable         | GmacFrameBurstEnable  | GmacJumboFrameDisable
                          | GmacSelectGmii     | GmacDisableRxOwn         | GmacLoopbackOff
                          | GmacHalfDuplex     | GmacRetryEnable          | GmacPadCrcStripDisable   
                          | GmacBackoffLimit0  | GmacDeferralCheckDisable | GmacTxEnable          | GmacRxEnable,

   /* Half-duplex mode with perfect filter on */
   GmacConfigInitHdx110   = GmacWatchdogEnable | GmacJabberEnable         | GmacFrameBurstEnable  | GmacJumboFrameDisable
                          | GmacSelectMii      | GmacDisableRxOwn         | GmacLoopbackOff
                          | GmacHalfDuplex     | GmacRetryEnable          | GmacPadCrcStripDisable 
                          | GmacBackoffLimit0  | GmacDeferralCheckDisable | GmacTxEnable          | GmacRxEnable,

   /* Half-duplex mode */
   GmacFrameFilterInitHdx = GmacFilterOn          | GmacPassControl0        | GmacBroadcastEnable | GmacSrcAddrFilterDisable
                          | GmacMulticastFilterOn | GmacDestAddrFilterNor   | GmacMcastHashFilterOff
                          | GmacUcastHashFilterOff| GmacPromiscuousModeOff,

   /* Half-duplex mode */
   GmacFlowControlInitHdx = GmacUnicastPauseFrameOff | GmacRxFlowControlDisable | GmacTxFlowControlDisable,

   /* Half-duplex mode */
   GmacGmiiAddrInitHdx    = GmiiCsrClk2,



   /**********************************************
   *DMA configurations
   **********************************************/

  DmaBusModeInit         = DmaFixedBurstEnable |   DmaBurstLength8   | DmaDescriptorSkip2       | DmaResetOff,
//   DmaBusModeInit         = DmaFixedBurstEnable |   DmaBurstLength8   | DmaDescriptorSkip4       | DmaResetOff,
   
   /* 1000 Mb/s mode */
   DmaControlInit1000     = DmaStoreAndForward,//       | DmaTxSecondFrame ,

   /* 100 Mb/s mode */
   DmaControlInit100      = DmaStoreAndForward,
   
   /* 10 Mb/s mode */
   DmaControlInit10       = DmaStoreAndForward,

  /* Interrupt groups */
  DmaIntErrorMask         = DmaIntBusError,           /* Error */
  DmaIntRxAbnMask         = DmaIntRxNoBuffer,         /* receiver abnormal interrupt */
  DmaIntRxNormMask        = DmaIntRxCompleted,        /* receiver normal interrupt   */
  DmaIntRxStoppedMask     = DmaIntRxStopped,          /* receiver stopped */
  DmaIntTxAbnMask         = DmaIntTxUnderflow,        /* transmitter abnormal interrupt */
  DmaIntTxNormMask        = DmaIntTxCompleted,        /* transmitter normal interrupt */
  DmaIntTxStoppedMask     = DmaIntTxStopped,          /* transmitter stopped */

  DmaIntEnable            = DmaIeNormal     | DmaIeAbnormal    | DmaIntErrorMask
                          | DmaIntRxAbnMask | DmaIntRxNormMask | DmaIntRxStoppedMask
                          | DmaIntTxAbnMask | DmaIntTxNormMask | DmaIntTxStoppedMask,
  DmaIntDisable           = 0,
};


/**********************************************************
 * Mac Management Counters (MMC)
 **********************************************************/

enum MMC_ENABLE
{
	GmacMmcCntrl			= 0x0100,	/* mmc control for operating mode of MMC						*/
	GmacMmcIntrRx			= 0x0104,	/* maintains interrupts generated by rx counters					*/
	GmacMmcIntrTx			= 0x0108,	/* maintains interrupts generated by tx counters					*/
	GmacMmcIntrMaskRx		= 0x010C,	/* mask for interrupts generated from rx counters					*/
	GmacMmcIntrMaskTx		= 0x0110,	/* mask for interrupts generated from tx counters					*/
};
enum MMC_TX
{
	GmacMmcTxOctetCountGb		= 0x0114,	/*Bytes Tx excl. of preamble and retried bytes     (Good or Bad)			*/
	GmacMmcTxFrameCountGb		= 0x0118,	/*Frames Tx excl. of retried frames	           (Good or Bad)			*/
	GmacMmcTxBcFramesG		= 0x011C,	/*Broadcast Frames Tx 				   (Good)				*/
	GmacMmcTxMcFramesG		= 0x0120,	/*Multicast Frames Tx				   (Good)				*/
	
	GmacMmcTx64OctetsGb		= 0x0124,	/*Tx with len 64 bytes excl. of pre and retried    (Good or Bad)			*/
	GmacMmcTx65To127OctetsGb	= 0x0128,	/*Tx with len >64 bytes <=127 excl. of pre and retried    (Good or Bad)			*/
	GmacMmcTx128To255OctetsGb	= 0x012C,	/*Tx with len >128 bytes <=255 excl. of pre and retried   (Good or Bad)			*/
	GmacMmcTx256To511OctetsGb	= 0x0130,	/*Tx with len >256 bytes <=511 excl. of pre and retried   (Good or Bad)			*/
	GmacMmcTx512To1023OctetsGb	= 0x0134,	/*Tx with len >512 bytes <=1023 excl. of pre and retried  (Good or Bad)			*/
	GmacMmcTx1024ToMaxOctetsGb	= 0x0138,	/*Tx with len >1024 bytes <=MaxSize excl. of pre and retried (Good or Bad)		*/
	
	GmacMmcTxUcFramesGb		= 0x013C,	/*Unicast Frames Tx 					 (Good or Bad)			*/
	GmacMmcTxMcFramesGb		= 0x0140,	/*Multicast Frames Tx				   (Good and Bad)			*/
	GmacMmcTxBcFramesGb		= 0x0144,	/*Broadcast Frames Tx 				   (Good and Bad)			*/
	GmacMmcTxUnderFlowError		= 0x0148,	/*Frames aborted due to Underflow error							*/
	GmacMmcTxSingleColG		= 0x014C,	/*Successfully Tx Frames after singel collision in Half duplex mode			*/
	GmacMmcTxMultiColG		= 0x0150,	/*Successfully Tx Frames after more than singel collision in Half duplex mode		*/
	GmacMmcTxDeferred		= 0x0154,	/*Successfully Tx Frames after a deferral in Half duplex mode				*/
	GmacMmcTxLateCol		= 0x0158,	/*Frames aborted due to late collision error						*/
	GmacMmcTxExessCol		= 0x015C,	/*Frames aborted due to excessive (16) collision errors					*/
	GmacMmcTxCarrierError		= 0x0160,	/*Frames aborted due to carrier sense error (No carrier or Loss of carrier)		*/
	GmacMmcTxOctetCountG		= 0x0164,	/*Bytes Tx excl. of preamble and retried bytes     (Good) 				*/
	GmacMmcTxFrameCountG		= 0x0168,	/*Frames Tx 				           (Good)				*/
	GmacMmcTxExessDef		= 0x016C,	/*Frames aborted due to excessive deferral errors (deferred for more than 2 max-sized frame times)*/
	
	GmacMmcTxPauseFrames		= 0x0170,	/*Number of good pause frames Tx.							*/
	GmacMmcTxVlanFramesG		= 0x0174,	/*Number of good Vlan frames Tx excl. retried frames					*/
};
enum MMC_RX
{
	GmacMmcRxFrameCountGb		= 0x0180,	/*Frames Rx 				           (Good or Bad)			*/
	GmacMmcRxOctetCountGb		= 0x0184,	/*Bytes Rx excl. of preamble and retried bytes     (Good or Bad)			*/
	GmacMmcRxOctetCountG		= 0x0188,	/*Bytes Rx excl. of preamble and retried bytes     (Good) 				*/
	GmacMmcRxBcFramesG		= 0x018C,	/*Broadcast Frames Rx 				   (Good)				*/
	GmacMmcRxMcFramesG		= 0x0190,	/*Multicast Frames Rx				   (Good)				*/
	
	GmacMmcRxCrcError		= 0x0194,	/*Number of frames received with CRC error						*/
	GmacMmcRxAlignError		= 0x0198,	/*Number of frames received with alignment (dribble) error. Only in 10/100mode		*/
	GmacMmcRxRuntError		= 0x019C,	/*Number of frames received with runt (<64 bytes and CRC error) error			*/
	GmacMmcRxJabberError		= 0x01A0,	/*Number of frames rx with jabber (>1518/1522 or >9018/9022 and CRC) 			*/
	GmacMmcRxUnderSizeG		= 0x01A4,	/*Number of frames received with <64 bytes without any error				*/
	GmacMmcRxOverSizeG		= 0x01A8,	/*Number of frames received with >1518/1522 bytes without any error			*/
	
	GmacMmcRx64OctetsGb		= 0x01AC,	/*Rx with len 64 bytes excl. of pre and retried    (Good or Bad)			*/
	GmacMmcRx65To127OctetsGb	= 0x01B0,	/*Rx with len >64 bytes <=127 excl. of pre and retried    (Good or Bad)			*/
	GmacMmcRx128To255OctetsGb	= 0x01B4,	/*Rx with len >128 bytes <=255 excl. of pre and retried   (Good or Bad)			*/
	GmacMmcRx256To511OctetsGb	= 0x01B8,	/*Rx with len >256 bytes <=511 excl. of pre and retried   (Good or Bad)			*/
	GmacMmcRx512To1023OctetsGb	= 0x01BC,	/*Rx with len >512 bytes <=1023 excl. of pre and retried  (Good or Bad)			*/
	GmacMmcRx1024ToMaxOctetsGb	= 0x01C0,	/*Rx with len >1024 bytes <=MaxSize excl. of pre and retried (Good or Bad)		*/
	
	GmacMmcRxUcFramesG		= 0x01C4,	/*Unicast Frames Rx 					 (Good)				*/
	GmacMmcRxLengthError		= 0x01C8,	/*Number of frames received with Length type field != frame size			*/
	GmacMmcRxOutOfRangeType		= 0x01CC,	/*Number of frames received with length field != valid frame size			*/
	
	GmacMmcRxPauseFrames		= 0x01D0,	/*Number of good pause frames Rx.							*/
	GmacMmcRxFifoOverFlow		= 0x01D4,	/*Number of missed rx frames due to FIFO overflow					*/
	GmacMmcRxVlanFramesGb		= 0x01D8,	/*Number of good Vlan frames Rx 							*/
	
	GmacMmcRxWatchdobError		= 0x01DC,	/*Number of frames rx with error due to watchdog timeout error				*/
};
enum MMC_IP_RELATED
{
	GmacMmcRxIpcIntrMask		= 0x0200,	/*Maintains the mask for interrupt generated from rx IPC statistic counters 		*/
	GmacMmcRxIpcIntr		= 0x0208,	/*Maintains the interrupt that rx IPC statistic counters generate			*/
	
	GmacMmcRxIpV4FramesG		= 0x0210,	/*Good IPV4 datagrams received								*/
	GmacMmcRxIpV4HdrErrFrames	= 0x0214,	/*Number of IPV4 datagrams received with header errors					*/
	GmacMmcRxIpV4NoPayFrames	= 0x0218,	/*Number of IPV4 datagrams received which didnot have TCP/UDP/ICMP payload		*/
	GmacMmcRxIpV4FragFrames		= 0x021C,	/*Number of IPV4 datagrams received with fragmentation					*/
	GmacMmcRxIpV4UdpChkDsblFrames	= 0x0220,	/*Number of IPV4 datagrams received that had a UDP payload checksum disabled		*/
	
	GmacMmcRxIpV6FramesG		= 0x0224,	/*Good IPV6 datagrams received								*/
	GmacMmcRxIpV6HdrErrFrames	= 0x0228,	/*Number of IPV6 datagrams received with header errors					*/
	GmacMmcRxIpV6NoPayFrames	= 0x022C,	/*Number of IPV6 datagrams received which didnot have TCP/UDP/ICMP payload		*/
	
	GmacMmcRxUdpFramesG		= 0x0230,	/*Number of good IP datagrams with good UDP payload					*/
	GmacMmcRxUdpErrorFrames		= 0x0234,	/*Number of good IP datagrams with UDP payload having checksum error			*/
	
	GmacMmcRxTcpFramesG		= 0x0238,	/*Number of good IP datagrams with good TDP payload					*/
	GmacMmcRxTcpErrorFrames		= 0x023C,	/*Number of good IP datagrams with TCP payload having checksum error			*/

	GmacMmcRxIcmpFramesG		= 0x0240,	/*Number of good IP datagrams with good Icmp payload					*/
	GmacMmcRxIcmpErrorFrames	= 0x0244,	/*Number of good IP datagrams with Icmp payload having checksum error			*/
	
	GmacMmcRxIpV4OctetsG		= 0x0250,	/*Good IPV4 datagrams received excl. Ethernet hdr,FCS,Pad,Ip Pad bytes			*/
	GmacMmcRxIpV4HdrErrorOctets	= 0x0254,	/*Number of bytes in IPV4 datagram with header errors					*/
	GmacMmcRxIpV4NoPayOctets	= 0x0258,	/*Number of bytes in IPV4 datagram with no TCP/UDP/ICMP payload				*/
	GmacMmcRxIpV4FragOctets		= 0x025C,	/*Number of bytes received in fragmented IPV4 datagrams 				*/
	GmacMmcRxIpV4UdpChkDsblOctets	= 0x0260,	/*Number of bytes received in UDP segment that had UDP checksum disabled		*/
	
	GmacMmcRxIpV6OctetsG		= 0x0264,	/*Good IPV6 datagrams received excl. Ethernet hdr,FCS,Pad,Ip Pad bytes			*/
	GmacMmcRxIpV6HdrErrorOctets	= 0x0268,	/*Number of bytes in IPV6 datagram with header errors					*/
	GmacMmcRxIpV6NoPayOctets	= 0x026C,	/*Number of bytes in IPV6 datagram with no TCP/UDP/ICMP payload				*/
	
	GmacMmcRxUdpOctetsG		= 0x0270,	/*Number of bytes in IP datagrams with good UDP payload					*/
	GmacMmcRxUdpErrorOctets		= 0x0274,	/*Number of bytes in IP datagrams with UDP payload having checksum error		*/
	
	GmacMmcRxTcpOctetsG		= 0x0278,	/*Number of bytes in IP datagrams with good TDP payload					*/
	GmacMmcRxTcpErrorOctets		= 0x027C,	/*Number of bytes in IP datagrams with TCP payload having checksum error		*/
	
	GmacMmcRxIcmpOctetsG		= 0x0280,	/*Number of bytes in IP datagrams with good Icmp payload				*/
	GmacMmcRxIcmpErrorOctets	= 0x0284,	/*Number of bytes in IP datagrams with Icmp payload having checksum error		*/
};


enum MMC_CNTRL_REG_BIT_DESCRIPTIONS
{
	GmacMmcCounterFreeze		= 0x00000008,		/* when set MMC counters freeze to current value				*/
	GmacMmcCounterResetOnRead	= 0x00000004,		/* when set MMC counters will be reset to 0 after read				*/
	GmacMmcCounterStopRollover	= 0x00000002,		/* when set counters will not rollover after max value				*/
	GmacMmcCounterReset		= 0x00000001,		/* when set all counters wil be reset (automatically cleared after 1 clk)	*/
	
};

enum MMC_RX_INTR_MASK_AND_STATUS_BIT_DESCRIPTIONS
{
	GmacMmcRxWDInt			= 0x00800000,		/* set when rxwatchdog error reaches half of max value				*/
	GmacMmcRxVlanInt		= 0x00400000,		/* set when GmacMmcRxVlanFramesGb counter reaches half of max value		*/
	GmacMmcRxFifoOverFlowInt	= 0x00200000,		/* set when GmacMmcRxFifoOverFlow counter reaches half of max value		*/
	GmacMmcRxPauseFrameInt		= 0x00100000,		/* set when GmacMmcRxPauseFrames counter reaches half of max value		*/
	GmacMmcRxOutOfRangeInt		= 0x00080000,		/* set when GmacMmcRxOutOfRangeType counter reaches half of max value		*/
	GmacMmcRxLengthErrorInt		= 0x00040000,		/* set when GmacMmcRxLengthError counter reaches half of max value		*/
	GmacMmcRxUcFramesInt		= 0x00020000,		/* set when GmacMmcRxUcFramesG counter reaches half of max value		*/
	GmacMmcRx1024OctInt		= 0x00010000,		/* set when GmacMmcRx1024ToMaxOctetsGb counter reaches half of max value	*/
	GmacMmcRx512OctInt		= 0x00008000,		/* set when GmacMmcRx512To1023OctetsGb counter reaches half of max value	*/
	GmacMmcRx256OctInt		= 0x00004000,		/* set when GmacMmcRx256To511OctetsGb counter reaches half of max value		*/
	GmacMmcRx128OctInt		= 0x00002000,		/* set when GmacMmcRx128To255OctetsGb counter reaches half of max value		*/
	GmacMmcRx65OctInt		= 0x00001000,		/* set when GmacMmcRx65To127OctetsG counter reaches half of max value		*/
	GmacMmcRx64OctInt		= 0x00000800,		/* set when GmacMmcRx64OctetsGb counter reaches half of max value		*/
	GmacMmcRxOverSizeInt		= 0x00000400,		/* set when GmacMmcRxOverSizeG counter reaches half of max value		*/
	GmacMmcRxUnderSizeInt		= 0x00000200,		/* set when GmacMmcRxUnderSizeG counter reaches half of max value		*/
	GmacMmcRxJabberErrorInt		= 0x00000100,		/* set when GmacMmcRxJabberError counter reaches half of max value		*/
	GmacMmcRxRuntErrorInt		= 0x00000080,		/* set when GmacMmcRxRuntError counter reaches half of max value		*/
	GmacMmcRxAlignErrorInt		= 0x00000040,		/* set when GmacMmcRxAlignError counter reaches half of max value		*/
	GmacMmcRxCrcErrorInt		= 0x00000020,		/* set when GmacMmcRxCrcError counter reaches half of max value			*/
	GmacMmcRxMcFramesInt		= 0x00000010,		/* set when GmacMmcRxMcFramesG counter reaches half of max value		*/
	GmacMmcRxBcFramesInt		= 0x00000008,		/* set when GmacMmcRxBcFramesG counter reaches half of max value		*/
	GmacMmcRxOctetGInt		= 0x00000004,		/* set when GmacMmcRxOctetCountG counter reaches half of max value		*/
	GmacMmcRxOctetGbInt		= 0x00000002,		/* set when GmacMmcRxOctetCountGb counter reaches half of max value		*/
	GmacMmcRxFrameInt		= 0x00000001,		/* set when GmacMmcRxFrameCountGb counter reaches half of max value		*/
};

enum MMC_TX_INTR_MASK_AND_STATUS_BIT_DESCRIPTIONS
{

	GmacMmcTxVlanInt		= 0x01000000,		/* set when GmacMmcTxVlanFramesG counter reaches half of max value		*/
	GmacMmcTxPauseFrameInt		= 0x00800000,		/* set when GmacMmcTxPauseFrames counter reaches half of max value		*/
	GmacMmcTxExessDefInt		= 0x00400000,		/* set when GmacMmcTxExessDef counter reaches half of max value			*/
	GmacMmcTxFrameInt		= 0x00200000,		/* set when GmacMmcTxFrameCount counter reaches half of max value		*/
	GmacMmcTxOctetInt		= 0x00100000,		/* set when GmacMmcTxOctetCountG counter reaches half of max value		*/
	GmacMmcTxCarrierErrorInt	= 0x00080000,		/* set when GmacMmcTxCarrierError counter reaches half of max value		*/
	GmacMmcTxExessColInt		= 0x00040000,		/* set when GmacMmcTxExessCol counter reaches half of max value			*/
	GmacMmcTxLateColInt		= 0x00020000,		/* set when GmacMmcTxLateCol counter reaches half of max value			*/
	GmacMmcTxDeferredInt		= 0x00010000,		/* set when GmacMmcTxDeferred counter reaches half of max value			*/
	GmacMmcTxMultiColInt		= 0x00008000,		/* set when GmacMmcTxMultiColG counter reaches half of max value		*/
	GmacMmcTxSingleCol		= 0x00004000,		/* set when GmacMmcTxSingleColG	counter reaches half of max value		*/
	GmacfalseMmcTxUnderFlowErrorInt	= 0x00002000,		/* set when GmacMmcTxUnderFlowError counter reaches half of max value		*/
	GmacMmcTxBcFramesGbInt 		= 0x00001000,		/* set when GmacMmcTxBcFramesGb	counter reaches half of max value		*/
	GmacMmcTxMcFramesGbInt 		= 0x00000800,		/* set when GmacMmcTxMcFramesGb	counter reaches half of max value		*/
	GmacMmcTxUcFramesInt 		= 0x00000400,		/* set when GmacMmcTxUcFramesGb counter reaches half of max value		*/
	GmacMmcTx1024OctInt 		= 0x00000200,		/* set when GmacMmcTx1024ToMaxOctetsGb counter reaches half of max value	*/
	GmacMmcTx512OctInt 		= 0x00000100,		/* set when GmacMmcTx512To1023OctetsGb counter reaches half of max value	*/
	GmacMmcTx256OctInt 		= 0x00000080,		/* set when GmacMmcTx256To511OctetsGb counter reaches half of max value		*/
	GmacMmcTx128OctInt 		= 0x00000040,		/* set when GmacMmcTx128To255OctetsGb counter reaches half of max value		*/
	GmacMmcTx65OctInt 		= 0x00000020,		/* set when GmacMmcTx65To127OctetsGb counter reaches half of max value		*/
	GmacMmcTx64OctInt 		= 0x00000010,		/* set when GmacMmcTx64OctetsGb	counter reaches half of max value		*/
	GmacMmcTxMcFramesInt 		= 0x00000008,		/* set when GmacMmcTxMcFramesG counter reaches half of max value		*/
	GmacMmcTxBcFramesInt 		= 0x00000004,		/* set when GmacMmcTxBcFramesG counter reaches half of max value		*/
	GmacfalseMmcTxFrameGbInt 		= 0x00000002,		/* set when GmacMmcTxFrameCountGb counter reaches half of max value		*/
	GmacMmcTxOctetGbInt 		= 0x00000001,		/* set when GmacMmcTxOctetCountGb counter reaches half of max value		*/
	
};





#ifndef CONFIG_VBG400_CHIPIT

/*
*** TODO: fill database with Reversed Mode Data (Reversed mode not supported at this stage)
*/

/*************************************************************************************
** These definitions are for the shared register configuration (clock and delay configuration)
*/

/****************************************************************
* REG:
* GEN3_SHRD_GMAC_MODE_REG:
*
* rgmii read default = 0xc00c4c1c
*   gmac1_div_clk_src_sel	    000c0000 = default = c
*   reserve                     00300000 = default = 0
*   gmac1_inv_phy_clk_tx_out    00400000 = default = 0
*/

/* fields mask definitions for gen3_gmac_mode_reg */
#define GMAC_MODE_GMAC0_SEL_CLK_SWITCH_MASK         0x00000003
#define GMAC_MODE_GMAC0_DIV_CLK_SRC_SEL_MASK        0x0000000C
#define GMAC_MODE_GMAC0_PHY_CLK_REF_OE_N_MASK       0x00000010
#define GMAC_MODE_RESERVED_MASK                     0x00000020
#define GMAC_MODE_GMAC0_INV_PHY_CLK_TX_OUT_MASK     0x00000040
#define GMAC_MODE_GMAC0_PHY_INTERFACE_SELMASK       0x00000380
#define GMAC_MODE_GMAC0_PHY_CLK_RX_OE_N_MASK        0x00000400
#define GMAC_MODE_GMAC0_PHY_CLK_TX_OE_N_MASK        0x00000800
#define GMAC_MODE_GMAC0_USE_EXT_PHY_CLK_TX_MASK     0x00001000
#define GMAC_MODE_GMII_MODE_MASK                    0x00002000
#define GMAC_MODE_PHY_CLK_REF_OE_N_MASK             0x00004000
#define GMAC_MODE_RESERVED_MASK_1                   0x00008000
#define GMAC_MODE_GMAC1_SEL_CLK_SWITCH_MASK         0x00030000
#define GMAC_MODE_GMAC1_DIV_CLK_SRC_SEL_MASK        0x000c0000
#define GMAC_MODE_RESERVED_MASK_2                   0x00300000
#define GMAC_MODE_GMAC1_INV_PHY_CLK_TX_OUT_MASK     0x00400000
#define GMAC_MODE_GMAC1_PHY_INTERFACE_SEL_MASK      0x01800000
#define GMAC_MODE_GMAC1_PHY_CLK_RX_OE_N_MASK        0x02000000
#define GMAC_MODE_GMAC1_PHY_CLK_TX_OE_N_MASK        0x04000000
#define GMAC_MODE_GMAC_SMA_LP_MASK                  0x08000000
#define GMAC_MODE_GMAC1_MSTR_SMA_MASK               0x10000000
#define GMAC_MODE_GMAC_REVMII_SYNPS_MASK            0x20000000
#define GMAC_MODE_GMAC0_REF_CLK_SEL_MASK            0x40000000
#define GMAC_MODE_GMAC1_REF_CLK_SEL_MASK            0x80000000

/*Reg MASK: registers are shared betwenn gma0/gma1,
* so there are two different mask definitions according gmac index:
*/
#define GMAC_MODE_REG_GMAC0_MASK    (GMAC_MODE_GMAC0_SEL_CLK_SWITCH_MASK |\
                                    GMAC_MODE_GMAC0_DIV_CLK_SRC_SEL_MASK |\
                                    GMAC_MODE_GMAC0_PHY_CLK_REF_OE_N_MASK |\
                                    GMAC_MODE_GMAC0_INV_PHY_CLK_TX_OUT_MASK |\
                                    GMAC_MODE_GMAC0_PHY_INTERFACE_SELMASK |\
                                    GMAC_MODE_GMAC0_PHY_CLK_RX_OE_N_MASK |\
                                    GMAC_MODE_GMAC0_PHY_CLK_TX_OE_N_MASK |\
                                    GMAC_MODE_GMAC0_USE_EXT_PHY_CLK_TX_MASK |\
                                    GMAC_MODE_GMII_MODE_MASK |\
                                    GMAC_MODE_PHY_CLK_REF_OE_N_MASK |\
                                    GMAC_MODE_GMAC_SMA_LP_MASK |\
                                    GMAC_MODE_GMAC_REVMII_SYNPS_MASK |\
                                    GMAC_MODE_GMAC0_REF_CLK_SEL_MASK)

#if 1
#define GMAC_MODE_REG_GMAC1_MASK    (GMAC_MODE_GMAC1_SEL_CLK_SWITCH_MASK |\
                                    GMAC_MODE_GMAC1_DIV_CLK_SRC_SEL_MASK |\
                                    GMAC_MODE_GMAC1_INV_PHY_CLK_TX_OUT_MASK |\
                                    GMAC_MODE_GMAC1_PHY_INTERFACE_SEL_MASK |\
                                    GMAC_MODE_GMAC1_PHY_CLK_RX_OE_N_MASK |\
                                    GMAC_MODE_GMAC1_PHY_CLK_TX_OE_N_MASK |\
                                    GMAC_MODE_GMAC_SMA_LP_MASK |\
                                    GMAC_MODE_GMAC1_MSTR_SMA_MASK |\
                                    GMAC_MODE_GMAC_REVMII_SYNPS_MASK |\
                                    GMAC_MODE_GMAC1_REF_CLK_SEL_MASK)
#else
#define GMAC_MODE_REG_GMAC1_MASK    (GMAC_MODE_GMII_MODE_MASK |\
                                    GMAC_MODE_PHY_CLK_REF_OE_N_MASK |\
                                    GMAC_MODE_GMAC1_SEL_CLK_SWITCH_MASK |\
                                    GMAC_MODE_GMAC1_DIV_CLK_SRC_SEL_MASK |\
                                    GMAC_MODE_GMAC1_INV_PHY_CLK_TX_OUT_MASK |\
                                    GMAC_MODE_GMAC1_PHY_INTERFACE_SEL_MASK |\
                                    GMAC_MODE_GMAC1_PHY_CLK_RX_OE_N_MASK |\
                                    GMAC_MODE_GMAC1_PHY_CLK_TX_OE_N_MASK |\
                                    GMAC_MODE_GMAC_SMA_LP_MASK |\
                                    GMAC_MODE_GMAC1_MSTR_SMA_MASK |\
                                    GMAC_MODE_GMAC_REVMII_SYNPS_MASK |\
                                    GMAC_MODE_GMAC1_REF_CLK_SEL_MASK)
#endif
/*Reg DATA is Interface & Speed related, so there are many options:
*/
#define GMAC_MODE_REG_MII_10M_DATA          0xC0004C10
#define GMAC_MODE_REG_MII_10M_GMAC1_DATA          0/*not legal interface*/
#define GMAC_MODE_REG_MII_100M_DATA         0xC0004C10
#define GMAC_MODE_REG_MII_100M_GMAC1_DATA          0/*not legal interface*/
#define GMAC_MODE_REG_GMII_1000M_DATA       0xC0004c50
#define GMAC_MODE_REG_GMII_1000M_GMAC1_DATA       0/*not legal interface*/
#define GMAC_MODE_REG_RGMII_10M_DATA        0xC0004491
#define GMAC_MODE_REG_RGMII_10M_GMAC1_DATA        0xD2814491
#define GMAC_MODE_REG_RGMII_100M_DATA       0xC0004492
#define GMAC_MODE_REG_RGMII_100M_GMAC1_DATA       0xD2820000
#define GMAC_MODE_REG_RGMII_1000M_DATA      0xC0004490
#define GMAC_MODE_REG_RGMII_1000M_GMAC1_DATA      0xD2800000
#define GMAC_MODE_REG_RMII_10M_DATA         0xC0004C10
#define GMAC_MODE_REG_RMII_10M_GMAC1_DATA         0x07000000
#define GMAC_MODE_REG_RMII_100M_DATA        0xC0004C10
#define GMAC_MODE_REG_RMII_100M_GMAC1_DATA        0x07000000
/*the next is conditionaly used in the handlers:*/
#define GMAC_MODE_REG_SMA_MASTER_GMAC0_FIELD    0x0
#define GMAC_MODE_REG_SMA_MASTER_GMAC1_FIELD    0x10000000
#define GMAC_MODE_REG_SMA_MASTER_REVERSED_FIELD 0x18000000
#define GMAC_MODE_REG_SMA_MASTER_REVERSED_FIELD_MASK 0xE7FFFFFF

/**** Reversed ****************************
*/
#define GMAC_MODE_REG_MII_10M_R_DATA        0//TODO
#define GMAC_MODE_REG_MII_10M_R_GMAC1_DATA        0/*not legal interface*/
#define GMAC_MODE_REG_MII_100M_R_DATA       0//TODO
#define GMAC_MODE_REG_MII_100M_R_GMAC1_DATA       0/*not legal interface*/
#define GMAC_MODE_REG_GMII_1000M_R_DATA     0//TODO
#define GMAC_MODE_REG_GMII_1000M_R_GMAC1_DATA     0/*not legal interface*/
#define GMAC_MODE_REG_RGMII_10M_R_DATA      0//TODO
#define GMAC_MODE_REG_RGMII_10M_R_GMAC1_DATA      0/*not legal interface*/
#define GMAC_MODE_REG_RGMII_100M_R_DATA     0//TODO
#define GMAC_MODE_REG_RGMII_100M_R_GMAC1_DATA     0/*not legal interface*/
#define GMAC_MODE_REG_RGMII_1000M_R_DATA    0//TODO
#define GMAC_MODE_REG_RGMII_1000M_R_GMAC1_DATA    0/*not legal interface*/
#define GMAC_MODE_REG_RMII_10M_R_DATA       0//TODO
#define GMAC_MODE_REG_RMII_10M_R_GMAC1_DATA       0/*not legal interface*/
#define GMAC_MODE_REG_RMII_100M_R_DATA      0//TODO
#define GMAC_MODE_REG_RMII_100M_R_GMAC1_DATA      0/*not legal interface*/

/****************************************************************
*  REG:
*  GEN3_SHRD_GMAC_DIV_RATIO_REG:

* rgmii read default = 0x00000000
*/

/* fields mask definitions for gen3_gmac_mode2_reg */
#define GMAC_DIV_RATIO_GMAC0_DIV_RATIO_MASK             0x7F
#define GMAC_DIV_RATIO_GMAC0_INV_PHY_CLK_RX_MASK        0x08
#define GMAC_DIV_RATIO_GMAC1_DIV_RATIO_MASK             0x7F00
#define GMAC_DIV_RATIO_GMAC1_INV_PHY_CLK_RX_MASK        0x8000
#define GMAC_DIV_RATIO_GMAC0_CDIV_ENABLE_MASK           0x30000
#define GMAC_DIV_RATIO_GMAC1_CDIV_ENABLE_MASK           0xC0000

/*Reg MASK is GMAC related, so there are two different mask definitions:
*/
#define GMAC_DIV_RATIO_REG_GMAC0_MASK       (GMAC_DIV_RATIO_GMAC0_DIV_RATIO_MASK |\
                                            GMAC_DIV_RATIO_GMAC0_INV_PHY_CLK_RX_MASK |\
                                            GMAC_DIV_RATIO_GMAC0_CDIV_ENABLE_MASK)
                                            
#define GMAC_DIV_RATIO_REG_GMAC1_MASK       (GMAC_DIV_RATIO_GMAC1_DIV_RATIO_MASK |\
                                            GMAC_DIV_RATIO_GMAC1_INV_PHY_CLK_RX_MASK |\
                                            GMAC_DIV_RATIO_GMAC1_CDIV_ENABLE_MASK)

/*Reg DATA is Interface & Speed related, so there are many options:
*/
#define GMAC_DIV_RATIO_REG_MII_10M_DATA       0
#define GMAC_DIV_RATIO_REG_MII_10M_GMAC1_DATA       0/*not legal interface*/       
#define GMAC_DIV_RATIO_REG_MII_100M_DATA      0
#define GMAC_DIV_RATIO_REG_MII_100M_GMAC1_DATA      0/*not legal interface*/      
#define GMAC_DIV_RATIO_REG_GMII_1000M_DATA    0
#define GMAC_DIV_RATIO_REG_GMII_1000M_GMAC1_DATA    0/*not legal interface*/    
#define GMAC_DIV_RATIO_REG_RGMII_10M_DATA     0x00020031
#define GMAC_DIV_RATIO_REG_RGMII_10M_GMAC1_DATA     0x000a3131     
#define GMAC_DIV_RATIO_REG_RGMII_100M_DATA    0x00010000
#define GMAC_DIV_RATIO_REG_RGMII_100M_GMAC1_DATA    0x00050000
#define GMAC_DIV_RATIO_REG_RGMII_1000M_DATA   0
#define GMAC_DIV_RATIO_REG_RGMII_1000M_GMAC1_DATA   0x0   
#define GMAC_DIV_RATIO_REG_RMII_10M_DATA      0
#define GMAC_DIV_RATIO_REG_RMII_10M_GMAC1_DATA      0x0      
#define GMAC_DIV_RATIO_REG_RMII_100M_DATA     0
#define GMAC_DIV_RATIO_REG_RMII_100M_GMAC1_DATA     0x0     

/**** Reversed ****************************
*/
#define GMAC_DIV_RATIO_REG_MII_10M_R_DATA     0//TODO
#define GMAC_DIV_RATIO_REG_MII_10M_R_GMAC1_DATA         0/*not legal interface*/
#define GMAC_DIV_RATIO_REG_MII_100M_R_DATA    0//TODO
#define GMAC_DIV_RATIO_REG_MII_100M_R_GMAC1_DATA        0/*not legal interface*/
#define GMAC_DIV_RATIO_REG_GMII_1000M_R_DATA  0//TODO
#define GMAC_DIV_RATIO_REG_GMII_1000M_R_GMAC1_DATA      0/*not legal interface*/
#define GMAC_DIV_RATIO_REG_RGMII_10M_R_DATA   0//TODO
#define GMAC_DIV_RATIO_REG_RGMII_10M_R_GMAC1_DATA       0/*not legal interface*/
#define GMAC_DIV_RATIO_REG_RGMII_100M_R_DATA  0//TODO
#define GMAC_DIV_RATIO_REG_RGMII_100M_R_GMAC1_DATA      0/*not legal interface*/
#define GMAC_DIV_RATIO_REG_RGMII_1000M_R_DATA 0//TODO
#define GMAC_DIV_RATIO_REG_RGMII_1000M_R_GMAC1_DATA     0/*not legal interface*/
#define GMAC_DIV_RATIO_REG_RMII_10M_R_DATA    0//TODO
#define GMAC_DIV_RATIO_REG_RMII_10M_R_GMAC1_DATA        0/*not legal interface*/
#define GMAC_DIV_RATIO_REG_RMII_100M_R_DATA   0//TODO
#define GMAC_DIV_RATIO_REG_RMII_100M_R_GMAC1_DATA       0/*not legal interface*/

/****************************************************************
*  REG:
*  GEN3_SHRD_GMAC_DLY_PGM_REG:
*/

/* fields mask definitions for gen3_gmac_dly_pgm */
#define GMAC_DLY_PGM_GMAC0_DELAY_PHY_CLOCK_RX_MASK             0x7F
#define GMAC_DLY_PGM_GMAC0_DELAY_PHY_CLOCK_TX_MASK             0x7F00
#define GMAC_DLY_PGM_GMAC1_DELAY_PHY_CLOCK_RX_MASK             0x7F0000
#define GMAC_DLY_PGM_GMAC1_DELAY_PHY_CLOCK_TX_MASK             0x7F000000

/*Reg MASK is GMAC related, so there are two different mask definitions:
*/
/*For gmac0/1_dly_phy_clk_tx value already in place (RGMII), do not clear it,
For the rest of interface modes this field can be ignored. clk_rx field is not important.  */
#define GMAC_DLY_PGM_REG_GMAC0_MASK    (GMAC_DLY_PGM_GMAC0_DELAY_PHY_CLOCK_RX_MASK)

#define GMAC_DLY_PGM_REG_GMAC1_MASK    (GMAC_DLY_PGM_GMAC1_DELAY_PHY_CLOCK_RX_MASK)

/*Reg DATA is done dynamically:
  - therefore same value = 0 for both mac0 and mac1
*/
#define GMAC_DLY_PGM_REG_MII_10M_DATA       0
#define GMAC_DLY_PGM_REG_MII_10M_GMAC1_DATA       0
#define GMAC_DLY_PGM_REG_MII_100M_DATA      0
#define GMAC_DLY_PGM_REG_MII_100M_GMAC1_DATA      0
#define GMAC_DLY_PGM_REG_GMII_1000M_DATA    0
#define GMAC_DLY_PGM_REG_GMII_1000M_GMAC1_DATA    0
#define GMAC_DLY_PGM_REG_RGMII_10M_DATA     0
#define GMAC_DLY_PGM_REG_RGMII_10M_GMAC1_DATA     0
#define GMAC_DLY_PGM_REG_RGMII_100M_DATA    0
#define GMAC_DLY_PGM_REG_RGMII_100M_GMAC1_DATA    0
#define GMAC_DLY_PGM_REG_RGMII_1000M_DATA   0
#define GMAC_DLY_PGM_REG_RGMII_1000M_GMAC1_DATA   0
#define GMAC_DLY_PGM_REG_RMII_10M_DATA      0
#define GMAC_DLY_PGM_REG_RMII_10M_GMAC1_DATA      0
#define GMAC_DLY_PGM_REG_RMII_100M_DATA     0
#define GMAC_DLY_PGM_REG_RMII_100M_GMAC1_DATA     0

/**** Reversed ****************************
*/
#define GMAC_DLY_PGM_REG_MII_10M_R_DATA     0//TODO
#define GMAC_DLY_PGM_REG_MII_10M_R_GMAC1_DATA     0/*not legal interface*/
#define GMAC_DLY_PGM_REG_MII_100M_R_DATA    0//TODO
#define GMAC_DLY_PGM_REG_MII_100M_R_GMAC1_DATA    0/*not legal interface*/
#define GMAC_DLY_PGM_REG_GMII_1000M_R_DATA  0//TODO
#define GMAC_DLY_PGM_REG_GMII_1000M_R_GMAC1_DATA  0/*not legal interface*/
#define GMAC_DLY_PGM_REG_RGMII_10M_R_DATA   0//TODO
#define GMAC_DLY_PGM_REG_RGMII_10M_R_GMAC1_DATA   0/*not legal interface*/
#define GMAC_DLY_PGM_REG_RGMII_100M_R_DATA  0//TODO
#define GMAC_DLY_PGM_REG_RGMII_100M_R_GMAC1_DATA  0/*not legal interface*/
#define GMAC_DLY_PGM_REG_RGMII_1000M_R_DATA 0//TODO
#define GMAC_DLY_PGM_REG_RGMII_1000M_R_GMAC1_DATA 0/*not legal interface*/
#define GMAC_DLY_PGM_REG_RMII_10M_R_DATA    0//TODO
#define GMAC_DLY_PGM_REG_RMII_10M_R_GMAC1_DATA    0/*not legal interface*/
#define GMAC_DLY_PGM_REG_RMII_100M_R_DATA   0//TODO
#define GMAC_DLY_PGM_REG_RMII_100M_R_GMAC1_DATA   0/*not legal interface*/



enum interfaceMode
{
#ifdef VBG400_SEPERATE_MII_GMII
    INTERFACE_MII = 0,    
    INTERFACE_GMII = 1,    
    INTERFACE_RGMII = 2,    
    INTERFACE_RMII = 3,    
    INTERFACE_MII_R = 4,    
    INTERFACE_GMII_R = 5,    
    INTERFACE_RGMII_R = 6,    
    INTERFACE_RMII_R = 7,    
#else
    INTERFACE_MII_GMII = 0,    
    INTERFACE_RGMII = 1,    
    INTERFACE_RMII = 2,    
    INTERFACE_MII_GMII_R = 3,    
    INTERFACE_RGMII_R = 4,    
    INTERFACE_RMII_R = 5,    
#endif
};

enum phy_speed
{
    SPEED_10M = 0,    
    SPEED_100M = 1,    
    SPEED_1000M = 2,    
};

enum mac_reversed
{
    MAC_NORMAL = 0,    
    MAC_REVERSED = 1,    
};

enum mac_index
{
    INDEX_GMAC0 = 0,    
    INDEX_GMAC1 = 1,    
#ifdef VBG400_SUPPORT_INTERFACE_REVERSED
    INDEX_GMACS_BOTH = 2,
#endif
};

enum mac_clk
{
    USE_CLK_OTHER = 0,    
    USE_CLK_PLL2 = 1,    
};

#endif //CONFIG_VBG400_CHIPIT


/*
 * The Low level function to read register contents from Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * \return  Returns the register contents
 */
static u32 __inline__ synopGMACReadReg(u32 *RegBase, u32 RegOffset)
{
  u32 addr = (u32)RegBase + RegOffset;
  u32 data = readl((void *)addr);
  //printf("%s[%d] !! Addr = 0x%08x RegData = 0x%08x\n", __FUNCTION__, __LINE__, addr, data );
  return data;

}

/*
 * The Low level function to write to a register in Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Data to be written
 * \return  void
 */
static void  __inline__ synopGMACWriteReg(u32 *RegBase, u32 RegOffset, u32 RegData)
{
  u32 addr = (u32)RegBase + RegOffset;
  //printf("%s[%d] !! Addr = 0x%08x RegData = 0x%08x\n", __FUNCTION__, __LINE__, addr, RegData );
  writel(RegData,(void *)addr);
  return;
}

/*
 * The Low level function to set bits of a register in Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Bit mask to set bits to logical 1
 * \return  void
 */
static void __inline__ synopGMACSetBits(u32 *RegBase, u32 RegOffset, u32 BitPos)
{
  u32 addr = (u32)RegBase + RegOffset;
  u32 data = readl((void *)addr);
  data |= BitPos;
  //printf("%s[%d] !!! Addr = 0x%08x RegData = 0x%08x\n", __FUNCTION__, __LINE__, addr, data );
  writel(data,(void *)addr);
  return;
}


/*
 * The Low level function to clear bits of a register in Hardware.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Bit mask to clear bits to logical 0
 * \return  void
 */
static void __inline__ synopGMACClearBits(u32 *RegBase, u32 RegOffset, u32 BitPos)
{
  u32 addr = (u32)RegBase + RegOffset;
  u32 data = readl((void *)addr);
  data &= (~BitPos);
  //printf("%s[%d] !!! Addr = 0x%08x RegData = 0x%08x\n", __FUNCTION__, __LINE__, addr, data );
  writel(data,(void *)addr);
  return;
}

/*
 * The Low level function to Check the setting of the bits.
 *
 * @param[in] pointer to the base of register map
 * @param[in] Offset from the base
 * @param[in] Bit mask to set bits to logical 1
 * \return  returns TRUE if set to '1' returns FALSE if set to '0'. Result undefined there are no bit set in the BitPos argument.
 *
 */
static int __inline__ synopGMACCheckBits(u32 *RegBase, u32 RegOffset, u32 BitPos)
{
  u32 addr = (u32)RegBase + RegOffset;
  u32 data = readl((void *)addr);
  data &= BitPos;
  if(data)  return 1;
  else      return 0;

}


typedef int bool;
enum synopGMAC_boolean
 {
    false = 0,
    true = 1
 };

typedef struct gphy
{
	uint	res000[4];  /* skip it */
	uint	addReg;
	uint	dataReg;
}gphy_t;

/*
DMA Descriptor Structure
The structure is common for both receive and transmit descriptors
The descriptor is of 4 words, but our structrue contains 6 words where
last two words are to hold the virtual address of the network buffer pointers
for driver's use
*/
typedef struct DmaDescStruct    
{                               
  u32   status;         /* Status 									*/
  u32   length;         /* Buffer 1  and Buffer 2 length 						*/
  u32   buffer1;        /* Network Buffer 1 pointer (Dma-able) 							*/
  u32   buffer2;        /* Network Buffer 2 pointer or next descriptor pointer (Dma-able)in chain structure 	*/
} DmaDesc;

enum DescMode
{
	RINGMODE	= 0x00000001,
	CHAINMODE	= 0x00000002,
};

enum BufferMode
{
	SINGLEBUF	= 0x00000001,
	DUALBUF		= 0x00000002,
};


/* synopGMAC device data */

typedef struct GMACDeviceStruct      
{
  u32 MacBase; 		         /* base address of MAC registers         */
  u32 DmaBase;         		 /* base address of DMA registers         */
  u32 PhyBase;          	 /* PHY device address on MII interface   */
  u32 Version;	                 /* Gmac Revision version	          */		

  u32 TxDescDma;		 /* Dma-able address of first tx descriptor either in ring or chain mode, this is used by the GMAC device*/
  u32  RxDescDma; 	 /* Dma-albe address of first rx descriptor either in ring or chain mode, this is used by the GMAC device*/ 
  DmaDesc *TxDesc;               /* start address of TX descriptors ring or chain, this is used by the driver  */
  DmaDesc *RxDesc;               /* start address of RX descriptors ring or chain, this is used by the driver  */  
  
  u32  RxDescCount;              /* number of rx descriptors in the tx descriptor queue/pool */
  u32  TxDescCount;              /* number of tx descriptors in the rx descriptor queue/pool */
  
  u32  TxBusy;                   /* index of the tx descriptor owned by DMA, is obtained by synopGMAC_get_tx_qptr()                */
  u32  TxNext;                   /* index of the tx descriptor next available with driver, given to DMA by synopGMAC_set_tx_qptr() */
  u32  RxBusy;                   /* index of the rx descriptor owned by DMA, obtained by synopGMAC_get_rx_qptr()                   */
  u32  RxNext;                   /* index of the rx descriptor next available with driver, given to DMA by synopGMAC_set_rx_qptr() */

  DmaDesc * TxBusyDesc;          /* Tx Descriptor address corresponding to the index TxBusy */
  DmaDesc * TxNextDesc;          /* Tx Descriptor address corresponding to the index TxNext */
  DmaDesc * RxBusyDesc;          /* Rx Descriptor address corresponding to the index TxBusy */
  DmaDesc * RxNextDesc;          /* Rx Descriptor address corresponding to the index RxNext */

  /*Phy related stuff*/
  u32 ClockDivMdc;		/* Clock divider value programmed in the hardware           */
  /* The status of the link */
  u32 LinkState;		/* Link status as reported by the Marvel Phy                */
  u32 DuplexMode;               /* Duplex mode of the Phy				    */
  u32 Speed;			/* Speed of the Phy					    */
  u32 LoopBackMode; 		/* Loopback status of the Phy				    */
  
} GMACdevice;

#define TSEC_GIGABIT (1)

/* This flag currently only has
 * meaning if we're using the eTSEC */
#define TSEC_REDUCED (1 << 1)

struct tsec_private {
	volatile GMACdevice *gmacRegs;
#ifndef CONFIG_VBG400_CHIPIT
	volatile gphy_t *phyregsSmaMaster;
#endif
	volatile gphy_t *phyregs;
	struct phy_info *phyinfo;
	unsigned int phyaddr;
	u32 flags;
	uint link;
	uint duplexity;
	uint speed;
	u8 broadcast[6];
};


/*
 * struct phy_cmd:  A command for reading or writing a PHY register
 *
 * mii_reg:  The register to read or write
 *
 * mii_data:  For writes, the value to put in the register.
 * 	A value of -1 indicates this is a read.
 *
 * funct: A function pointer which is invoked for each command.
 * 	For reads, this function will be passed the value read
 *	from the PHY, and process it.
 *	For writes, the result of this function will be written
 *	to the PHY register
 */
struct phy_cmd {
    uint mii_reg;
    uint mii_data;
    uint (*funct) (uint mii_reg, struct tsec_private* priv);
};

/* struct phy_info: a structure which defines attributes for a PHY
 *
 * id will contain a number which represents the PHY.  During
 * startup, the driver will poll the PHY to find out what its
 * UID--as defined by registers 2 and 3--is.  The 32-bit result
 * gotten from the PHY will be shifted right by "shift" bits to
 * discard any bits which may change based on revision numbers
 * unimportant to functionality
 *
 * The struct phy_cmd entries represent pointers to an arrays of
 * commands which tell the driver what to do to the PHY.
 */
struct phy_info {
    uint id;
    char *name;
    uint shift;
    /* Called to configure the PHY, and modify the controller
     * based on the results */
    struct phy_cmd *config;

    /* Called when starting up the controller */
    struct phy_cmd *startup;

    /* Called when bringing down the controller */
    struct phy_cmd *shutdown;
};

#endif /* __TSEC_H */
