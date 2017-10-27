#ifndef AR10_H
#define AR10_H

#define AR10_PLATFORM            "AR10"
#define KSEG1 0xa0000000


/***********************************************************************/
/*  Module      :  CSS register address and bits                       */
/***********************************************************************/
#define CSS_BASE   (KSEG1+0x1F800000)
#define CSS_DDR_ECHO_DLL0  (CSS_BASE + 0x1d8)
#define CSS_DDR_ECHO_DLL1  (CSS_BASE + 0x1e0)


/***********************************************************************/
/*  Module      :  WDT register address and bits                       */
/***********************************************************************/

#define BSP_BIU_WDT                           (KSEG1+0x1F880000)

/***Watchdog Timer Control Register ***/
#define BSP_BIU_WDT_CR                   ((volatile u32*)(BSP_BIU_WDT + 0x03F0))


/***********************************************************************/
/*  Module      :  CGU register address and bits                       */
/***********************************************************************/

#define AR10_CGU_BASE_ADDR                             (KSEG1+0x1F103000)

#define AR10_CGU_PLL0_CFG                ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0004))
#define AR10_CGU_PLL1_CFG                ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0008))
#define AR10_CGU_SYS                     ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x000C))
#define AR10_CGU_CLKFSR                  ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0010))
#define AR10_CGU_CLKGSR0                 ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0014))
#define AR10_CGU_CLKGSR0_A               ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0018))
#define AR10_CGU_CLKGSR0_B               ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x001C))
#define AR10_CGU_UPDATE                  ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0020))
#define AR10_CGU_IF_CLK                  ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0024))
#define AR10_CGU_CT1SR                   ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x002C))
#define AR10_CGU_CT_KVAL                 ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0030))
#define AR10_CGU_PCMCR                   ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0034))
#define AR10_EPHY1_CFG                   ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0040))
#define AR10_EPHY2_CFG                   ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0044))
#define AR10_EPHY3_CFG                   ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x0048))
#define AR10_EPHY0_CFG                   ((volatile u32*)(AR10_CGU_BASE_ADDR  + 0x004C))

/***********************************************************************/
/*  Module      :  DMA register address and bits                       */
/***********************************************************************/
#define AR10_DMA_OFFSET 0xBE104100
/***********************************************************************/
#define AR10_DMA_CLC                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0000))
#define AR10_DMA_ID                    ((volatile u32*)(AR10_DMA_OFFSET + 0x0008))
#define AR10_DMA_CTRL                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0010))
#define AR10_DMA_CPOLL                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0014))
#define AR10_DMA_CS                    ((volatile u32*)(AR10_DMA_OFFSET + 0x0018))
#define AR10_DMA_CCTRL                 ((volatile u32*)(AR10_DMA_OFFSET + 0x001C))
#define AR10_DMA_CDBA                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0020))
#define AR10_DMA_CDLEN                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0024))
#define AR10_DMA_CIS                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0028))
#define AR10_DMA_CIE                   ((volatile u32*)(AR10_DMA_OFFSET + 0x002C))
#define AR10_DMA_CGBL                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0030))
#define AR10_DMA_CDPTNRD               ((volatile u32*)(AR10_DMA_OFFSET + 0x0034))
#define AR10_DMA_CDPTNRD1              ((volatile u32*)(AR10_DMA_OFFSET + 0x0038))
#define AR10_DMA_CS1                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0050))
#define AR10_DMA_CCTRL1                ((volatile u32*)(AR10_DMA_OFFSET + 0x0054))
#define AR10_DMA_CDBA1                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0058))
#define AR10_DMA_CDLEN1                ((volatile u32*)(AR10_DMA_OFFSET + 0x005C))
#define AR10_DMA_CIS1                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0060))
#define AR10_DMA_CIE1                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0064))
/*Registers, Port Related Registers*/
#define AR10_DMA_PS                    ((volatile u32*)(AR10_DMA_OFFSET + 0x0040))
#define AR10_DMA_PCTRL                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0044))
#define AR10_DMA_PS1                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0070))
#define AR10_DMA_PCTRL1                ((volatile u32*)(AR10_DMA_OFFSET + 0x0074))
/*Registers, Port Related Registers*/
#define AR10_DMA_IRNEN                 ((volatile u32*)(AR10_DMA_OFFSET + 0x00F4))
#define AR10_DMA_IRNCR                 ((volatile u32*)(AR10_DMA_OFFSET + 0x00F8))
#define AR10_DMA_IRNICR                ((volatile u32*)(AR10_DMA_OFFSET + 0x00FC))


#define BSP_DMA_CLC                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0000))
#define BSP_DMA_ID                    ((volatile u32*)(AR10_DMA_OFFSET + 0x0008))
#define BSP_DMA_CTRL                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0010))
#define BSP_DMA_CPOLL                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0014))
#define BSP_DMA_CS                    ((volatile u32*)(AR10_DMA_OFFSET + 0x0018))
#define BSP_DMA_CCTRL                 ((volatile u32*)(AR10_DMA_OFFSET + 0x001C))
#define BSP_DMA_CDBA                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0020))
#define BSP_DMA_CDLEN                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0024))
#define BSP_DMA_CIS                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0028))
#define BSP_DMA_CIE                   ((volatile u32*)(AR10_DMA_OFFSET + 0x002C))
#define BSP_DMA_CGBL                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0030))
#define BSP_DMA_CDPTNRD               ((volatile u32*)(AR10_DMA_OFFSET + 0x0034))
#define BSP_DMA_CDPTNRD1              ((volatile u32*)(AR10_DMA_OFFSET + 0x0038))
#define BSP_DMA_CS1                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0050))
#define BSP_DMA_CCTRL1                ((volatile u32*)(AR10_DMA_OFFSET + 0x0054))
#define BSP_DMA_CDBA1                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0058))
#define BSP_DMA_CDLEN1                ((volatile u32*)(AR10_DMA_OFFSET + 0x005C))
#define BSP_DMA_CIS1                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0060))
#define BSP_DMA_CIE1                  ((volatile u32*)(AR10_DMA_OFFSET + 0x0064))
/*Registers, Port Related Registers*/
#define BSP_DMA_PS                    ((volatile u32*)(AR10_DMA_OFFSET + 0x0040))
#define BSP_DMA_PCTRL                 ((volatile u32*)(AR10_DMA_OFFSET + 0x0044))
#define BSP_DMA_PS1                   ((volatile u32*)(AR10_DMA_OFFSET + 0x0070))
#define BSP_DMA_PCTRL1                ((volatile u32*)(AR10_DMA_OFFSET + 0x0074))
/*Registers, Port Related Registers*/
#define BSP_DMA_IRNEN                 ((volatile u32*)(AR10_DMA_OFFSET + 0x00F4))
#define BSP_DMA_IRNCR                 ((volatile u32*)(AR10_DMA_OFFSET + 0x00F8))
#define BSP_DMA_IRNICR                ((volatile u32*)(AR10_DMA_OFFSET + 0x00FC))



/***********************************************************************/
/*  Module      :  EBU register address and bits                       */
/***********************************************************************/

#define AR10_EBU                          (0xB6000000)

/***EBU Clock Control Register***/
#define AR10_EBU_CLC                      ((volatile u32*)(AR10_EBU+ 0x0000))
#define AR10_EBU_ID                       ((volatile u32*)(AR10_EBU+ 0x0008))
#define AR10_EBU_CON                      ((volatile u32*)(AR10_EBU+ 0x0010))
#define AR10_EBU_ADDR_SEL_0               ((volatile u32*)(AR10_EBU+ 0x0020))
#define AR10_EBU_ADDR_SEL_1               ((volatile u32*)(AR10_EBU+ 0x0024))
#define AR10_EBU_CON_0                    ((volatile u32*)(AR10_EBU+ 0x0060))
#define AR10_EBU_CON_1                    ((volatile u32*)(AR10_EBU+ 0x0064))
#define AR10_EBU_ECC_ISTAT                ((volatile u32*)(AR10_EBU+ 0x00A0))
#define AR10_EBU_ECC_IEN                  ((volatile u32*)(AR10_EBU+ 0x00A4))
#define AR10_EBU_ECC_INT_OUT              ((volatile u32*)(AR10_EBU+ 0x00A8))
#define AR10_EBU_NAND_CON                 ((volatile u32*)(AR10_EBU+ 0x00B0))
#define AR10_EBU_NAND_WAIT                ((volatile u32*)(AR10_EBU+ 0x00B4))


#define EBU_ADDR_SEL0     (volatile u32*)(AR10_EBU + 0x20)
#define EBU_ADDR_SEL1     (volatile u32*)(AR10_EBU + 0x24)
#define EBU_ADDR_SEL2     (volatile u32*)(AR10_EBU + 0x28)
#define EBU_ADDR_SEL3     (volatile u32*)(AR10_EBU + 0x2C)
#define EBU_CON0          (volatile u32*)(AR10_EBU + 0x60)
#define EBU_CON1          (volatile u32*)(AR10_EBU + 0x64)
#define EBU_CON2          (volatile u32*)(AR10_EBU + 0x68)
#define EBU_CON3          (volatile u32*)(AR10_EBU + 0x6C)
#define EBU_NAND_CON       (volatile u32*)(AR10_EBU + 0xB0)
#define EBU_NAND_WAIT      (volatile u32*)(AR10_EBU + 0xB4)
#define EBU_NAND_ECC0      (volatile u32*)(AR10_EBU + 0xB8)
#define EBU_NAND_ECC_AC    (volatile u32*)(AR10_EBU + 0xBC)


#define EBU_ADDR_SEL_0     (volatile u32*)(AR10_EBU + 0x20)
#define EBU_ADDR_SEL_1     (volatile u32*)(AR10_EBU + 0x24)
#define EBU_CON_0          (volatile u32*)(AR10_EBU + 0x60)
#define EBU_CON_1          (volatile u32*)(AR10_EBU + 0x64)

/***********************************************************************/
/*  Module      :  HSNAND registers                                    */
/***********************************************************************/

#define HSNAND_BASE                       (0xB6000100)

#define BSP_NDAC_CTL1             ((volatile u32*)(HSNAND_BASE + 0x0010))
#define BSP_NDAC_CTL2             ((volatile u32*)(HSNAND_BASE + 0x0014))
#define BSP_INT_Msk_CTL           ((volatile u32*)(HSNAND_BASE + 0x0024))
#define BSP_INT_Sta               ((volatile u32*)(HSNAND_BASE + 0x0028))
#define BSP_MD_CTL                ((volatile u32*)(HSNAND_BASE + 0x0030))
#define BSP_ND_PARA0              ((volatile u32*)(HSNAND_BASE + 0x003C))
#define BSP_ND_ODD_ECC            ((volatile u32*)(HSNAND_BASE + 0x0040))
#define BSP_ND_ODD_ECC1           ((volatile u32*)(HSNAND_BASE + 0x0044))
#define BSP_ND_EVEN_ECC           ((volatile u32*)(HSNAND_BASE + 0x0048))
#define BSP_ND_EVEN_ECC1          ((volatile u32*)(HSNAND_BASE + 0x004C))


/***********************************************************************/
/*  Module      :  GPIO register address and bits                       */
/***********************************************************************/
#define AR10_GPIO                     (0xBE100B00)
#define AR10_GPIO_P0_OUT              ((volatile u32 *)(AR10_GPIO+ 0x0010))
#define AR10_GPIO_P0_IN               ((volatile u32 *)(AR10_GPIO+ 0x0014))
#define AR10_GPIO_P0_DIR              ((volatile u32 *)(AR10_GPIO+ 0x0018))
#define AR10_GPIO_P0_ALTSEL0          ((volatile u32 *)(AR10_GPIO+ 0x001C))
#define AR10_GPIO_P0_ALTSEL1          ((volatile u32 *)(AR10_GPIO+ 0x0020))
#define AR10_GPIO_P0_OD               ((volatile u32 *)(AR10_GPIO+ 0x0024))
#define AR10_GPIO_P0_STOFF            ((volatile u32 *)(AR10_GPIO+ 0x0028))
#define AR10_GPIO_P0_PUDSEL           ((volatile u32 *)(AR10_GPIO+ 0x002C))
#define AR10_GPIO_P0_PUDEN            ((volatile u32 *)(AR10_GPIO+ 0x0030))
#define AR10_GPIO_P3_OD               ((volatile u32 *)(AR10_GPIO+ 0x0034))
#define AR10_GPIO_P3_PUDSEL           ((volatile u32 *)(AR10_GPIO+ 0x0038))
#define AR10_GPIO_P3_PUDEN            ((volatile u32 *)(AR10_GPIO+ 0x003C))
#define AR10_GPIO_P1_OUT              ((volatile u32 *)(AR10_GPIO+ 0x0040))
#define AR10_GPIO_P1_IN               ((volatile u32 *)(AR10_GPIO+ 0x0044))
#define AR10_GPIO_P1_DIR              ((volatile u32 *)(AR10_GPIO+ 0x0048))
#define AR10_GPIO_P1_ALTSEL0          ((volatile u32 *)(AR10_GPIO+ 0x004C))
#define AR10_GPIO_P1_ALTSEL1          ((volatile u32 *)(AR10_GPIO+ 0x0050))
#define AR10_GPIO_P1_OD               ((volatile u32 *)(AR10_GPIO+ 0x0054))
#define AR10_GPIO_P1_STOFF            ((volatile u32 *)(AR10_GPIO+ 0x0058))
#define AR10_GPIO_P1_PUDSEL           ((volatile u32 *)(AR10_GPIO+ 0x005C))
#define AR10_GPIO_P1_PUDEN            ((volatile u32 *)(AR10_GPIO+ 0x0060))
#define AR10_GPIO_P3_ALTSEL1          ((volatile u32 *)(AR10_GPIO+ 0x0064))

#define AR10_GPIO_P2_OUT              ((volatile u32 *)(AR10_GPIO+ 0x0070))
#define AR10_GPIO_P2_IN               ((volatile u32 *)(AR10_GPIO+ 0x0074))
#define AR10_GPIO_P2_DIR              ((volatile u32 *)(AR10_GPIO+ 0x0078))
#define AR10_GPIO_P2_ALTSEL0          ((volatile u32 *)(AR10_GPIO+ 0x007C))
#define AR10_GPIO_P2_ALTSEL1          ((volatile u32 *)(AR10_GPIO+ 0x0080))
#define AR10_GPIO_P2_OD               ((volatile u32 *)(AR10_GPIO+ 0x0084))
#define AR10_GPIO_P2_STOFF            ((volatile u32 *)(AR10_GPIO+ 0x0088))
#define AR10_GPIO_P2_PUDSEL           ((volatile u32 *)(AR10_GPIO+ 0x008C))
#define AR10_GPIO_P2_PUDEN            ((volatile u32 *)(AR10_GPIO+ 0x0090))

#define AR10_GPIO_P3_OUT              ((volatile u32 *)(AR10_GPIO+ 0x00A0))
#define AR10_GPIO_P3_IN               ((volatile u32 *)(AR10_GPIO+ 0x00A4))
#define AR10_GPIO_P3_DIR              ((volatile u32 *)(AR10_GPIO+ 0x00A8))
#define AR10_GPIO_P3_ALTSEL0          ((volatile u32 *)(AR10_GPIO+ 0x00AC))


/***********************************************************************/
/*  Module      :  SSIO register address and bits                       */
/***********************************************************************/
#define AR10_SSIO_BASE_ADDR             (KSEG1+0x1E100B00)
#define AR10_LED_CON0                   ((volatile u32*)(AR10_SSIO_BASE_ADDR + 0x00B0))
#define AR10_LED_CON1                   ((volatile u32*)(AR10_SSIO_BASE_ADDR + 0x00B4))
#define AR10_LED_CPU0                   ((volatile u32*)(AR10_SSIO_BASE_ADDR + 0x00B8))
#define AR10_LED_CPU1                   ((volatile u32*)(AR10_SSIO_BASE_ADDR + 0x00BC))
#define AR10_LED_AR                     ((volatile u32*)(AR10_SSIO_BASE_ADDR + 0x00C0))

/***********************************************************************/
/*  Module      :  PMU register address and bits                       */
/***********************************************************************/
#define AR10_PMU_BASE_ADDR 				      (KSEG1+0x1F102000)

#define AR10_PMU_PWDCR                   ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x001c))
#define AR10_PMU_PWDCR1                  ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0024))
#define AR10_PMU_PWDSR                   ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0020))
#define AR10_PMU_PWDSR1                  ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0028))


#define AR10_PMU_CLKGSR1                ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0020))
#define AR10_PMU_CLKGCR1_A              ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0024))
#define AR10_PMU_CLKGCR1_B			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0028))
#define AR10_PMU_CLKGSR2                ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0030))
#define AR10_PMU_CLKGCR2_A              ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0034))
#define AR10_PMU_CLKGCR2_B			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0038))

#define BSP_CLKGCR1_A                     ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0020))

#define AR10_PMU_ANALOG_SR			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0040))
#define AR10_PMU_ANALOGCR_A			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0044))
#define AR10_PMU_ANALOGCR_B			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0048))

#define AR10_PMU_PWGCSR   			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0100))
#define AR10_PMU_RD       			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0104))
#define AR10_PMU_POD       			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0108))
#define AR10_PMU_PD_SEL   			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x010C))
#define AR10_PMU_WKUP_LOC  			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0200))
#define AR10_PMU_PD_WKUP_EN			        ((volatile u32*)(AR10_PMU_BASE_ADDR + 0x0204))

/***PM Global Enable Register 0 ***/
#define BSP_PMU_USB0_PHY        (1 << 0)
#define BSP_PMU_FPIS            (1 << 1)
#define BSP_PMU_DFEV0           (1 << 2)
#define BSP_PMU_DEV1            (1 << 3)
#define BSP_PMU_PCI             (1 << 4)
#define BSP_PMU_DMA             (1 << 5)
#define BSP_PMU_USB0            (1 << 6)
#define BSP_PMU_USIF            (1 << 7)
#define BSP_PMU_SPI             (1 << 8)
#define BSP_PMU_DSL             (1 << 9)
#define BSP_PMU_EBU             (1 << 10)
#define BSP_PMU_LEDC            (1 << 11)
#define BSP_PMU_GPTC            (1 << 12)
#define BSP_PMU_AHBS            (1 << 13)
#define BSP_PMU_FPIM            (1 << 14)
#define BSP_PMU_AHBM            (1 << 15)
#define BSP_PMU_SDIO            (1 << 16)
#define BSP_PMU_UART1           (1 << 17)
#define BSP_PMU_PPE_QSB         (1 << 18)
#define BSP_PMU_SSL01           (1 << 19)
#define BSP_PMU_DEU             (1 << 20)
#define BSP_PMU_PPE_TC          (1 << 21)
#define BSP_PMU_PPE_EMA         (1 << 22)
#define BSP_PMU_PPE_DPLUS       (1 << 23)
#define BSP_PMU_PPE_DPSS        (1 << 24)
#define BSP_PMU_TDM             (1 << 25)
#define BSP_PMU_USB1_PHY        (1 << 26)
#define BSP_PMU_USB1            (1 << 27)
#define BSP_PMU_SWITCH          (1 << 28)
#define BSP_PMU_PPE_TOP         (1 << 29)
#define BSP_PMU_GPHY            (1 << 30)
#define BSP_PMU_PCIE0_EN        (1 << 31)



/***********************************************************************/
/*  Module      :  RCU register address and bits                       */
/***********************************************************************/
#define AR10_RCU_BASE_ADDR 		(0xBF203000)

/*Reset related Register Description*/
#define AR10_RCU_RST_REQ              ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0010))
#define AR10_RCU_RST_STAT             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0014))
#define AR10_RCU_RST_STAT2            ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0024))
#define AR10_RCU_RST_REQ2             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0048))

/*Configuration related Register Description*/
#define AR10_RCU_USB0_CFG             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0018))
#define AR10_RCU_GP_STRAP             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x001C))
#define AR10_RCU_RST_PPM              ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0028))
#define AR10_RCU_RST_PPE_CONF         ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x002C))
#define AR10_RCU_RST_PCIEPHY1_CON     ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0030))
#define AR10_RCU_USB1_Cfg             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0034))
#define AR10_RCU_USB_ANA_CFG1A        ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0038))
#define AR10_RCU_USB_ANA_CFG1B        ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x003C))
#define AR10_RCU_ENDIAN               ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x004C))
#define AR10_RCU_PCIPH2_CON           ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x005C))

/*PCM DMA FCC Registers*/
#define AR10_RCU_PCM_FCC_CFG          ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0060))


/*Module Base Address Configuration*/
#define AR10_RCU_GFS_ADD0             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0020))
#define AR10_RCU_GCC                  ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0040))
#define AR10_RCU_GFS_ADD1             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x0058))
#define AR10_RCU_GFS_ADD2             ((volatile u32*)(AR10_RCU_BASE_ADDR + 0x00AC))

/***************************************************************************/
/* Module     : Debug unit                                                 */
/***************************************************************************/
#define AR10_DEBUG_BASE_ADDR    (0xBF203200)

#define AR10_RCU_GFS_ADD3       ((volatile u32*)(AR10_DEBUG_BASE_ADDR + 0x0064))


/* AR10 GPORT SWITCH Register */
#define AR10_SWITCH	  		(0xBE108000)

#define AR10_SWITCH_PS	  		(AR10_SWITCH + 0x000)
#define AR10_SWITCH_P0_CTL		(AR10_SWITCH + 0x004)
#define AR10_SWITCH_P1_CTL		(AR10_SWITCH + 0x008)
#define AR10_SWITCH_P2_CTL		(AR10_SWITCH + 0x00C)
#define AR10_SWITCH_P0_VLAN		(AR10_SWITCH + 0x010)
#define AR10_SWITCH_P1_VLAN		(AR10_SWITCH + 0x014)
#define AR10_SWITCH_P2_VLAN		(AR10_SWITCH + 0x018)
#define AR10_SWITCH_P0_INCTL		(AR10_SWITCH + 0x020)
#define AR10_SWITCH_P1_INCTL		(AR10_SWITCH + 0x024)
#define AR10_SWITCH_P2_INCTL		(AR10_SWITCH + 0x028)
#define AR10_SWITCH_DF_PORTMAP		(AR10_SWITCH + 0x02C)
#define AR10_SWITCH_P0_ECS_Q32		(AR10_SWITCH + 0x030)
#define AR10_SWITCH_P0_ECS_Q10		(AR10_SWITCH + 0x034)
#define AR10_SWITCH_P0_ECW_Q32		(AR10_SWITCH + 0x038)
#define AR10_SWITCH_P0_ECW_Q10		(AR10_SWITCH + 0x03C)
#define AR10_SWITCH_P1_ECS_Q32		(AR10_SWITCH + 0x040)
#define AR10_SWITCH_P1_ECS_Q10		(AR10_SWITCH + 0x044)
#define AR10_SWITCH_P1_ECW_Q32		(AR10_SWITCH + 0x048)
#define AR10_SWITCH_P1_ECW_Q10		(AR10_SWITCH + 0x04C)
#define AR10_SWITCH_P2_ECS_Q32		(AR10_SWITCH + 0x050)
#define AR10_SWITCH_P2_ECS_Q10		(AR10_SWITCH + 0x054)
#define AR10_SWITCH_P2_ECW_Q32		(AR10_SWITCH + 0x058)
#define AR10_SWITCH_P2_ECW_Q10		(AR10_SWITCH + 0x05C)
#define AR10_SWITCH_INT_ENA		(AR10_SWITCH + 0x060)
#define AR10_SWITCH_INT_ST		(AR10_SWITCH + 0x064)
#define AR10_SWITCH_GCTL0		(AR10_SWITCH + 0x068)
#define AR10_SWITCH_GCTL1		(AR10_SWITCH + 0x06C)
#define AR10_SWITCH_ARP			(AR10_SWITCH + 0x070)
#define AR10_SWITCH_STRM_CTL		(AR10_SWITCH + 0x074)
#define AR10_SWITCH_RGMII_CTL		(AR10_SWITCH + 0x078)
#define AR10_SWITCH_1P_PRT		(AR10_SWITCH + 0x07C)
#define AR10_SWITCH_GBKT_SZBS		(AR10_SWITCH + 0x080)
#define AR10_SWITCH_GBKT_SZEBS		(AR10_SWITCH + 0x084)
#define AR10_SWITCH_BF_TH		(AR10_SWITCH + 0x088)
#define AR10_SWITCH_PMAC_HD_CTL		(AR10_SWITCH + 0x08C)
#define AR10_SWITCH_PMAC_SA1		(AR10_SWITCH + 0x090)
#define AR10_SWITCH_PMAC_SA2		(AR10_SWITCH + 0x094)
#define AR10_SWITCH_PMAC_DA1		(AR10_SWITCH + 0x098)
#define AR10_SWITCH_PMAC_DA2		(AR10_SWITCH + 0x09C)
#define AR10_SWITCH_PMAC_VLAN		(AR10_SWITCH + 0x0A0)
#define AR10_SWITCH_PMAC_TX_IPG		(AR10_SWITCH + 0x0A4)
#define AR10_SWITCH_PMAC_RX_IPG		(AR10_SWITCH + 0x0A8)
#define AR10_SWITCH_ADR_TB_CTL0		(AR10_SWITCH + 0x0AC)
#define AR10_SWITCH_ADR_TB_CTL1		(AR10_SWITCH + 0x0B0)
#define AR10_SWITCH_ADR_TB_CTL2		(AR10_SWITCH + 0x0B4)
#define AR10_SWITCH_ADR_TB_ST0		(AR10_SWITCH + 0x0B8)
#define AR10_SWITCH_ADR_TB_ST1		(AR10_SWITCH + 0x0BC)
#define AR10_SWITCH_ADR_TB_ST2		(AR10_SWITCH + 0x0C0)
#define AR10_SWITCH_RMON_CTL		(AR10_SWITCH + 0x0C4)
#define AR10_SWITCH_RMON_ST		(AR10_SWITCH + 0x0C8)
#define AR10_SWITCH_MDIO_CTL		(AR10_SWITCH + 0x0CC)
#define AR10_SWITCH_MDIO_DATA		(AR10_SWITCH + 0x0D0)
#define AR10_SWITCH_TP_FLT_ACT		(AR10_SWITCH + 0x0D4)
#define AR10_SWITCH_PRTCL_FLT_ACT	(AR10_SWITCH + 0x0D8)
#define AR10_SWITCH_P0_PCDU_CTRL		(AR10_SWITCH + 0x0E4)
#define AR10_SWITCH_P1_PCDU_CTRL		(AR10_SWITCH + 0x0E8)
#define AR10_SWITCH_VLAN_FLT0		(AR10_SWITCH + 0x100)
#define AR10_SWITCH_VLAN_FLT1		(AR10_SWITCH + 0x104)
#define AR10_SWITCH_VLAN_FLT2		(AR10_SWITCH + 0x108)
#define AR10_SWITCH_VLAN_FLT3		(AR10_SWITCH + 0x10C)
#define AR10_SWITCH_VLAN_FLT4		(AR10_SWITCH + 0x110)
#define AR10_SWITCH_VLAN_FLT5		(AR10_SWITCH + 0x114)
#define AR10_SWITCH_VLAN_FLT6		(AR10_SWITCH + 0x118)
#define AR10_SWITCH_VLAN_FLT7		(AR10_SWITCH + 0x11C)
#define AR10_SWITCH_VLAN_FLT8		(AR10_SWITCH + 0x120)
#define AR10_SWITCH_VLAN_FLT9		(AR10_SWITCH + 0x124)
#define AR10_SWITCH_VLAN_FLT10		(AR10_SWITCH + 0x128)
#define AR10_SWITCH_VLAN_FLT11		(AR10_SWITCH + 0x12C)
#define AR10_SWITCH_VLAN_FLT12		(AR10_SWITCH + 0x130)
#define AR10_SWITCH_VLAN_FLT13		(AR10_SWITCH + 0x134)
#define AR10_SWITCH_VLAN_FLT14		(AR10_SWITCH + 0x138)
#define AR10_SWITCH_VLAN_FLT15		(AR10_SWITCH + 0x13C)
#define AR10_SWITCH_TP_FLT10		(AR10_SWITCH + 0x140)
#define AR10_SWITCH_TP_FLT32		(AR10_SWITCH + 0x144)
#define AR10_SWITCH_TP_FLT54		(AR10_SWITCH + 0x148)
#define AR10_SWITCH_TP_FLT76		(AR10_SWITCH + 0x14C)
#define AR10_SWITCH_DFSRV_MAP0		(AR10_SWITCH + 0x150)
#define AR10_SWITCH_DFSRV_MAP1		(AR10_SWITCH + 0x154)
#define AR10_SWITCH_DFSRV_MAP2		(AR10_SWITCH + 0x158)
#define AR10_SWITCH_DFSRV_MAP3		(AR10_SWITCH + 0x15C)
#define AR10_SWITCH_TCP_PF0		(AR10_SWITCH + 0x160)
#define AR10_SWITCH_TCP_PF1		(AR10_SWITCH + 0x164)
#define AR10_SWITCH_TCP_PF2		(AR10_SWITCH + 0x168)
#define AR10_SWITCH_TCP_PF3		(AR10_SWITCH + 0x16C)
#define AR10_SWITCH_TCP_PF4		(AR10_SWITCH + 0x170)
#define AR10_SWITCH_TCP_PF5		(AR10_SWITCH + 0x174)
#define AR10_SWITCH_TCP_PF6		(AR10_SWITCH + 0x178)
#define AR10_SWITCH_TCP_PF7		(AR10_SWITCH + 0x17C)
#define AR10_SWITCH_RA_03_00		(AR10_SWITCH + 0x180)
#define AR10_SWITCH_RA_07_04		(AR10_SWITCH + 0x184)
#define AR10_SWITCH_RA_0B_08		(AR10_SWITCH + 0x188)
#define AR10_SWITCH_RA_0F_0C		(AR10_SWITCH + 0x18C)
#define AR10_SWITCH_RA_13_10		(AR10_SWITCH + 0x190)
#define AR10_SWITCH_RA_17_14		(AR10_SWITCH + 0x194)
#define AR10_SWITCH_RA_1B_18		(AR10_SWITCH + 0x198)
#define AR10_SWITCH_RA_1F_1C		(AR10_SWITCH + 0x19C)
#define AR10_SWITCH_RA_23_20		(AR10_SWITCH + 0x1A0)
#define AR10_SWITCH_RA_27_24		(AR10_SWITCH + 0x1A4)
#define AR10_SWITCH_RA_2B_28		(AR10_SWITCH + 0x1A8)
#define AR10_SWITCH_RA_2F_2C		(AR10_SWITCH + 0x1AC)
#define AR10_SWITCH_F0			(AR10_SWITCH + 0x1B0)
#define AR10_SWITCH_F1			(AR10_SWITCH + 0x1B4)




/* AR10 SWITCH Register */
#define AR10_ETHSW_SS_BASE_ADDR                  (0xBE108000)



#define AR10_ETHSW_TOP   (AR10_ETHSW_SS_BASE_ADDR+( 0xC40 * 4) )

#define AR10_ETHSW_MAC   (AR10_ETHSW_SS_BASE_ADDR+(0x900*4))


#define AR10_ETHSW_SWRES         (AR10_ETHSW_SS_BASE_ADDR )
/*Hardware reset, reset all HW modules except for register settings  */
#define AR10_ETHSW_SWRES_R1      0x1     /*Bit< 1 >*/
/*Reset all registers */
#define AR10_ETHSW_SWRES_R0      0x0     /*Bit< 0 >*/

#define AR10_ETHSW_CLK           (AR10_ETHSW_SS_BASE_ADDR+ (0x1 * 4) )

#define AR10_ETHSW_BM_RAM_VAL_3  (AR10_ETHSW_SS_BASE_ADDR+ (0x40 * 4) )
#define AR10_ETHSW_BM_RAM_VAL_2  (AR10_ETHSW_SS_BASE_ADDR+ (0x41 * 4) )
#define AR10_ETHSW_BM_RAM_VAL_1  (AR10_ETHSW_SS_BASE_ADDR+ (0x42 * 4) )
#define AR10_ETHSW_BM_RAM_VAL_0  (AR10_ETHSW_SS_BASE_ADDR+ (0x43 * 4) )
#define AR10_ETHSW_BM_RAM_ADDR   (AR10_ETHSW_SS_BASE_ADDR+ (0x44 * 4) )
#define AR10_ETHSW_BM_RAM_CTRL   (AR10_ETHSW_SS_BASE_ADDR+ (0x45 * 4) )

#define AR10_ETHSW_BM_FSQM_GCTRL (AR10_ETHSW_SS_BASE_ADDR+ (0x46 * 4) )
#define AR10_ETHSW_BM_CONS_SEG   (AR10_ETHSW_SS_BASE_ADDR+ (0x47 * 4) )
#define AR10_ETHSW_BM_CONS_PKT   (AR10_ETHSW_SS_BASE_ADDR+ (0x48 * 4) )

#define AR10_ETHSW_BM_GCTRL      (AR10_ETHSW_SS_BASE_ADDR+ (0x49 * 4) )
#define AR10_ETHSW_BM_GCTRL_R_SRES(val)  ((val & 0x1 ) << 4 )
#define AR10_ETHSW_BM_QUEUE_GCTRL      (AR10_ETHSW_SS_BASE_ADDR+ (0x4A * 4) )

/*Buffer manager per port registrs*/
#define AR10_ETHSW_BM_PCFG       (AR10_ETHSW_SS_BASE_ADDR+ (0x80 * 4) )
#define AR10_ETHSW_BM_PCFG_CNTEN(val)    (((val & 0x1) << 0 ) )
#define AR10_ETHSW_BM_RMON_CTRL  (AR10_ETHSW_SS_BASE_ADDR+ (0x81 * 4) )

/*Rate shaper */

#define AR10_ETHSW_BM_QUEUE_PQM_DP        (AR10_ETHSW_SS_BASE_ADDR+ (0x100 * 4) )
#define AR10_ETHSW_BM_QUEUE_PQM_RS        (AR10_ETHSW_SS_BASE_ADDR+ (0x101 * 4) )
#define AR10_ETHSW_BM_SHAPER_RS_CTRL      (AR10_ETHSW_SS_BASE_ADDR+ (0x140 * 4) )
#define AR10_ETHSW_BM_SHAPER_RS_CBS       (AR10_ETHSW_SS_BASE_ADDR+ (0x141 * 4) )
#define AR10_ETHSW_BM_SHAPER_RS_IBS       (AR10_ETHSW_SS_BASE_ADDR+ (0x142 * 4) )
#define AR10_ETHSW_BM_SHAPER_RS_CIR_EXP   (AR10_ETHSW_SS_BASE_ADDR+ (0x143 * 4) )
#define AR10_ETHSW_BM_SHAPER_RS_CIR_MANT   (AR10_ETHSW_SS_BASE_ADDR+ (0x144 * 4) )

/* Metering */


#define AR10_ETHSW_PCE_TCM_CTRL          (AR10_ETHSW_SS_BASE_ADDR+(0x580*4))

#define AR10_ETHSW_PCE_TCM_STAT              (AR10_ETHSW_SS_BASE_ADDR+(0x581*4))
#define AR10_ETHSW_PCE_TCM_CBS      (AR10_ETHSW_SS_BASE_ADDR+(0x582*4))
#define AR10_ETHSW_PCE_TCM_EBS      (AR10_ETHSW_SS_BASE_ADDR+(0x583*4))
#define AR10_ETHSW_PCE_TCM_IBS      (AR10_ETHSW_SS_BASE_ADDR+(0x584*4))
#define AR10_ETHSW_PCE_TCM_CIR_MANT  (AR10_ETHSW_SS_BASE_ADDR+(0x585*4))
#define AR10_ETHSW_PCE_TCM_CIR_EXP   (AR10_ETHSW_SS_BASE_ADDR+(0x586*4))


/*WRED */
#define AR10_ETHSW_BM_WRED_RTH_0         (AR10_ETHSW_SS_BASE_ADDR+(0x04B*4))
#define AR10_ETHSW_BM_WRED_RTH_1         (AR10_ETHSW_SS_BASE_ADDR+(0x04C*4))
#define AR10_ETHSW_BM_WRED_YTH_0         (AR10_ETHSW_SS_BASE_ADDR+(0x04D*4))
#define AR10_ETHSW_BM_WRED_YTH_1         (AR10_ETHSW_SS_BASE_ADDR+(0x04E*4))
#define AR10_ETHSW_BM_WRED_GTH_0         (AR10_ETHSW_SS_BASE_ADDR+(0x04F*4))
#define AR10_ETHSW_BM_WRED_GTH_1         (AR10_ETHSW_SS_BASE_ADDR+(0x050*4))

/* MAC frame length register*/
#define AR10_ETHSW_MAC_FLEN      ( AR10_ETHSW_SS_BASE_ADDR + (0x8C5 *4))
/* fetch DMA port control */
#define AR10_ETHSW_FDMA_PCTRL_6          ( AR10_ETHSW_SS_BASE_ADDR + (0xAA4 *4))

/* SDMA registers */
#define AR10_ETHSW_SDMA_CTRL    ( AR10_ETHSW_SS_BASE_ADDR + (0xB40 *4))
#define AR10_ETHSW_SDMA_FCTHR1    ( AR10_ETHSW_SS_BASE_ADDR + (0xB41 *4))
#define AR10_ETHSW_SDMA_FCTHR2    ( AR10_ETHSW_SS_BASE_ADDR + (0xB42 *4))
#define AR10_ETHSW_SDMA_FCTHR3    ( AR10_ETHSW_SS_BASE_ADDR + (0xB43 *4))
#define AR10_ETHSW_SDMA_FCTHR4    ( AR10_ETHSW_SS_BASE_ADDR + (0xB44 *4))
#define AR10_ETHSW_SDMA_FCTHR5    ( AR10_ETHSW_SS_BASE_ADDR + (0xB45 *4))
#define AR10_ETHSW_SDMA_FCTHR6    ( AR10_ETHSW_SS_BASE_ADDR + (0xB46 *4))
#define AR10_ETHSW_SDMA_FCTHR7    ( AR10_ETHSW_SS_BASE_ADDR + (0xB47 *4))
#define AR10_ETHSW_SDMA_STAT0    ( AR10_ETHSW_SS_BASE_ADDR + (0xB48 *4))
#define AR10_ETHSW_SDMA_STAT1    ( AR10_ETHSW_SS_BASE_ADDR + (0xB49 *4))
#define AR10_ETHSW_SDMA_STAT2    ( AR10_ETHSW_SS_BASE_ADDR + (0xB4A *4))




/* Port Map Register */
#define AR10_ETHSW_PCE_PMAP_1    ( AR10_ETHSW_SS_BASE_ADDR + (0x453 *4))
#define AR10_ETHSW_PCE_PMAP_2    ( AR10_ETHSW_SS_BASE_ADDR + (0x454 *4))
#define AR10_ETHSW_PCE_PMAP_3    ( AR10_ETHSW_SS_BASE_ADDR + (0x455 *4))
#define AR10_ETHSW_PCE_GCTRL_0   ( AR10_ETHSW_SS_BASE_ADDR + (0x456 *4))
#define AR10_ETHSW_PCE_GCTRL_1   ( AR10_ETHSW_SS_BASE_ADDR + (0x457 *4))

/*Ethernet MAC registers */
/*MAC port status register*/
#define AR10_ETHSW_MAC_PSTAT     ( AR10_ETHSW_MAC  )
/*MAC interrupt status register*/
#define AR10_ETHSW_MAC_PISR      ( AR10_ETHSW_MAC+(0x1 *4 ))
/*MAC Interrupt enable reisgter */
#define AR10_ETHSW_MAC_PIER      ( AR10_ETHSW_MAC+(0x2 *4 ))
/*MAC control registers */
#define AR10_ETHSW_MAC_CTRL_0    ( AR10_ETHSW_MAC+(0x3 *4))
#define AR10_ETHSW_MAC_CTRL_1    ( AR10_ETHSW_MAC+(0x4 *4))
#define AR10_ETHSW_MAC_CTRL_2    ( AR10_ETHSW_MAC+(0x5 *4))
#define AR10_ETHSW_MAC_CTRL_3    ( AR10_ETHSW_MAC+(0x6 *4))
#define AR10_ETHSW_MAC_CTRL_4    ( AR10_ETHSW_MAC+(0x7 *4))
#define AR10_ETHSW_MAC_CTRL_5    ( AR10_ETHSW_MAC+(0x8 *4))
#define AR10_ETHSW_MAC_CTRL_6    ( AR10_ETHSW_MAC+(0x9 *4))

/*G<II/MII interface mode selection */
#define AR10_ETHSW_MAC_CTRL_GMII         0   /* <1:0>  interface mode selection */
#define AR10_ETHSW_MAC_CTRL_GMII_AUTO            0
#define AR10_ETHSW_MAC_CTRL_GMII_MII             1 /*MII/RMII interface mode at 10, 100 or 200 Mbit/s */
#define AR10_ETHSW_MAC_CTRL_GMII_GMII            2       /* GMII/RGMII interface mode at 1000 Mbit/s */

/*Full duplex control */
#define AR10_ETHSW_MAC_CTRL_FDUP         2 /*<3:2> full duplex control */
#define AR10_ETHSW_MAC_CTRL_FDUP_AUTO    0
#define AR10_ETHSW_MAC_CTRL_FDUP_EN      1
#define AR10_ETHSW_MAC_CTRL_FDUP_DIS     3

#define AR10_ETHSW_MAC_CTRL_FCON         4 /*<6:4> Flow control mode*/
#define AR10_ETHSW_MAC_CTRL_AUTO         0
#define AR10_ETHSW_MAC_CTRL_RX           1  /*Rx only */
#define AR10_ETHSW_MAC_CTRL_TX           2 /*Tx only */
#define AR10_ETHSW_MAC_CTRL_RXTX         3       /*Rx and Tx  */
#define AR10_ETHSW_MAC_CTRL_NONE         4       /*Disable*/

#define AR10_ETHSW_MAC_CTRL_FCS          7 /*<7> Tx Frame checksum generation */


/*MAC Rx/Tx buffer status register */
#define AR10_ETHSW_MAC_BUFST     ( AR10_ETHSW_MAC+(0xA *4))
/*MAC test enable register */
#define AR10_ETHSW_MAC_TESTEN    ( AR10_ETHSW_MAC+(0xB *4))

/*ETHSW_MDIO_PDI Registers*/
#define AR10_ETHSW_GLOB_CTRL             (AR10_ETHSW_TOP+0)
#define GLOB_CTRL_SE    15      /*Global switch macro enable*/
#define GLOB_CTRL_HWRES 1       /*Global Hardware reset */
#define GLOB_CTRL_SWRES 0       /*Global Software reset */

/*Switch Parse and Classification Engine registers*/
#define AR10_ETHSW_PCE_PCTRL_0           (AR10_ETHSW_SS_BASE_ADDR+(0x480*4))
#define AR10_ETHSW_PCE_PCTRL_1           (AR10_ETHSW_SS_BASE_ADDR+(0x481*4))
#define AR10_ETHSW_PCE_PCTRL_2           (AR10_ETHSW_SS_BASE_ADDR+(0x482*4))
#define AR10_ETHSW_PCE_PCTRL_3           (AR10_ETHSW_SS_BASE_ADDR+(0x483*4))
#define AR10_ETHSW_PCE_WOL_CTRL          (AR10_ETHSW_SS_BASE_ADDR+(0x484*4))
#define AR10_ETHSW_PCE_VCTRL             (AR10_ETHSW_SS_BASE_ADDR+(0x485*4))
#define AR10_ETHSW_PCE_DEFPVID           (AR10_ETHSW_SS_BASE_ADDR+(0x486*4))
#define AR10_ETHSW_PCE_PSTAT             (AR10_ETHSW_SS_BASE_ADDR+(0x487*4))
#define AR10_ETHSW_PCE_PIER              (AR10_ETHSW_SS_BASE_ADDR+(0x488*4))
#define AR10_ETHSW_PCE_PISR              (AR10_ETHSW_SS_BASE_ADDR+(0x489*4))

//#define AR10_ETHSW_SDMA_CTRL             (AR10_ETHSW_SS_BASE_ADDR+(0xB40*4))
//#define AR10_ETHSW_SDMA_FCTHR5           (AR10_ETHSW_SS_BASE_ADDR+(0xB45*4))
//#define AR10_ETHSW_SDMA_FCTHR6           (AR10_ETHSW_SS_BASE_ADDR+(0xB46*4))
#define AR10_ETHSW_FDMA_PCTRL_3          (AR10_ETHSW_SS_BASE_ADDR+(0xA92*4))
#define AR10_ETHSW_MDIO_CTRL             ( AR10_ETHSW_TOP + (0x8 * 4))
#define AR10_ETHSW_MDIO_READ             ( AR10_ETHSW_TOP + (0x9 * 4))
#define AR10_ETHSW_MDIO_WRITE            ( AR10_ETHSW_TOP + (0xa * 4))

#define AR10_ETHSW_MDC_CFG_0             ( AR10_ETHSW_TOP + (0xb  * 4))
#define AR10_ETHSW_CFG_0_PEN_0           0       /*Polling state machine enable */
#define AR10_ETHSW_CFG_0_PEN_1           1       /*Polling state machine enable */
#define AR10_ETHSW_CFG_0_PEN_2           2       /*Polling state machine enable */
#define AR10_ETHSW_CFG_0_PEN_3           3       /*Polling state machine enable */
#define AR10_ETHSW_CFG_0_PEN_4           4       /*Polling state machine enable */
#define AR10_ETHSW_CFG_0_PEN_5           5       /*Polling state machine enable */

#define AR10_ETHSW_MDC_CFG_1             ( AR10_ETHSW_TOP  + (0xc * 4))
#define AR10_ETHSW_CFG_1_RES             15      /*MDIO Hardware Reset*/
#define AR10_ETHSW_CFG_1_MCEN            8       /*MDC clock enable*/
#define AR10_ETHSW_CFG_1_FREQ            0       /*MDIO interface clock rate*/

#define AR10_ETHSW_PHY_ADDR_5            ( AR10_ETHSW_TOP  + (0x10 * 4))
#define AR10_ETHSW_PHY_ADDR_4            ( AR10_ETHSW_TOP  + (0x11 * 4))
#define AR10_ETHSW_PHY_ADDR_3            ( AR10_ETHSW_TOP  + (0x12 * 4))
#define AR10_ETHSW_PHY_ADDR_2            ( AR10_ETHSW_TOP  + (0x13 * 4))
#define AR10_ETHSW_PHY_ADDR_1            ( AR10_ETHSW_TOP  + (0x14 * 4))
#define AR10_ETHSW_PHY_ADDR_0            ( AR10_ETHSW_TOP  + (0x15 * 4))

#define AR10_ETHSW_MDIO_STAT_0           ( AR10_ETHSW_TOP  + (0x16 * 4))
#define AR10_ETHSW_MDIO_STAT_1           ( AR10_ETHSW_TOP  + (0x17 * 4))
#define AR10_ETHSW_MDIO_STAT_2           ( AR10_ETHSW_TOP  + (0x18 * 4))
#define AR10_ETHSW_MDIO_STAT_3           ( AR10_ETHSW_TOP  + (0x19 * 4))
#define AR10_ETHSW_MDIO_STAT_4           ( AR10_ETHSW_TOP  + (0x1A * 4))
#define AR10_ETHSW_MDIO_STAT_5           ( AR10_ETHSW_TOP  + (0x1B * 4))

#define AR10_ETHSW_ANEG_EEE_0            ( AR10_ETHSW_TOP  + (0x1C * 4))
#define AR10_ETHSW_ANEG_EEE_1            ( AR10_ETHSW_TOP  + (0x1D * 4))
#define AR10_ETHSW_ANEG_EEE_2            ( AR10_ETHSW_TOP  + (0x1E * 4))
#define AR10_ETHSW_ANEG_EEE_3            ( AR10_ETHSW_TOP  + (0x1F * 4))
#define AR10_ETHSW_ANEG_EEE_4            ( AR10_ETHSW_TOP  + (0x20 * 4))
#define AR10_ETHSW_ANEG_EEE_5            ( AR10_ETHSW_TOP  + (0x21 * 4))



/*ETHSW_MII_PDI Registers*/
#define AR10_ETHSW_MII_CFG_0             ( AR10_ETHSW_TOP + (0x36 * 4))
#define AR10_ETHSW_PCDU_0                ( AR10_ETHSW_TOP + (0x37 * 4))
#define AR10_ETHSW_MII_CFG_1             ( AR10_ETHSW_TOP + (0x38 * 4))
#define AR10_ETHSW_PCDU_1                ( AR10_ETHSW_TOP + (0x39 * 4))
#define AR10_ETHSW_MII_CFG_2             ( AR10_ETHSW_TOP + (0x3a * 4))
#define AR10_ETHSW_MII_CFG_3             ( AR10_ETHSW_TOP + (0x3c * 4))
#define AR10_ETHSW_MII_CFG_4             ( AR10_ETHSW_TOP + (0x3e * 4))
#define AR10_ETHSW_MII_CFG_5             ( AR10_ETHSW_TOP + (0x40 * 4))
#define AR10_ETHSW_PCDU_5                ( AR10_ETHSW_TOP + (0x41 * 4))

#define AR10_ETHSW_MII_CFG_RES           15      /*Hardware reset */
#define AR10_ETHSW_MII_CFG_EN            14      /*xMII interface enable*/
#define AR10_ETHSW_MII_CFG_RMII          7       /* RMII Ref clock direction input(0)/output(1) */
#define AR10_ETHSW_MII_CFG_MIIRATE       4       /*<6:4> xMII port interface clock rate bit position*/
#define AR10_ETHSW_MII_CFG_MIIRATE_M2P5  0x0     /*xMII port interface clock rate 2.5MHz */
#define AR10_ETHSW_MII_CFG_MIIRATE_M25   0x1     /*xMII port interface clock rate 25MHz */
#define AR10_ETHSW_MII_CFG_MIIRATE_M125  0x2     /*xMII port interface clock rate 125MHz */
#define AR10_ETHSW_MII_CFG_MIIRATE_M50   0x3     /*xMII port interface clock rate 50MHz */
#define AR10_ETHSW_MII_CFG_MIIRATE_AUTO  0x4     /*xMII port interface clock rate, speed used from autopolling */

#define AR10_ETHSW_MII_CFG_MIIMODE       0x0     /*<3:0> xMII  interface mode */
#define AR10_ETHSW_MII_CFG_MIIMODE_MIIM  0x0     /*MII MAC mode */
#define AR10_ETHSW_MII_CFG_MIIMODE_MIIP  0x1     /*MII PHY  mode */
#define AR10_ETHSW_MII_CFG_MIIMODE_RMIIM 0x2     /*RMII MAC mode */
#define AR10_ETHSW_MII_CFG_MIIMODE_RMIIP 0x3     /*RMII PHY mode */
#define AR10_ETHSW_MII_CFG_MIIMODE_RGMII 0x4     /*RGMII mode */

#define AR10_ETHSW_PCDU_RXSEL_CLK        12      /*<13:12>input clock selection for Receive PCDU */
#define AR10_ETHSW_PCDU_RXSEL_CLK_AUTO   0x0     /*Auto, selection of input clock depends on speed*/
#define AR10_ETHSW_PCDU_RXSEL_CLK_RXCLK  0x1     /*input clock is RXCLK*/
#define AR10_ETHSW_PCDU_RXSEL_CLK_CLKREF 0x2     /*input clock is CLKREF (125MHz)*/

#define AR10_ETHSW_PCDU_RXINIT   11      /*Reset of Receive PCDU*/
#define AR10_ETHSW_PCDU_RXPD     10      /*Power down of Receive PCDU*/
#define AR10_ETHSW_PCDU_RXDLY    7       /*<9:7> Configure receive clock delay*/


#define AR10_ETHSW_PCDU_TXSEL_CLK        5       /*<6:5>input clock selection for Transmit PCDU */
#define AR10_ETHSW_PCDU_TXSEL_CLK_AUTO   0x0     /*Auto, selection of input clock depends on speed*/
#define AR10_ETHSW_PCDU_TXSEL_CLK_RXCLK  0x1     /*input clock is TXCLK*/
#define AR10_ETHSW_PCDU_TXSEL_CLK_CLKREF 0x2     /*input clock is CLKREF (125MHz)*/

#define AR10_ETHSW_PCDU_TXINIT   4       /*Reset of Transmit PCDU*/
#define AR10_ETHSW_PCDU_TXPD     3       /*Power down of Transmit PCDU*/
#define AR10_ETHSW_PCDU_TXDLY    0       /*<2:0> Configure receive clock delay*/

/*ETHSW_PMAC_PDI Registers*/
#define AR10_ETHSW_PMAC_HD_CTL           ( AR10_ETHSW_TOP + (0x82 * 4))
#define AR10_ETHSW_PMAC_HD_CTL_RST       8  /* Remove special tag */
#define AR10_ETHSW_PMAC_HD_CTL_AST       7  /* Add special tag */
#define AR10_ETHSW_PMAC_HD_CTL_RXSH      6  /* Add status header from DMA to PMAC */
#define AR10_ETHSW_PMAC_HD_CTL_RL2       5  /* Remove Layer 2 header */
#define AR10_ETHSW_PMAC_HD_CTL_RC        4  /* Remove CRC  for packets from PMAC to DMA*/
#define AR10_ETHSW_PMAC_HD_CTL_AS        3  /* Add status header from PMAC to DMA*/
#define AR10_ETHSW_PMAC_HD_CTL_AC        2  /* Add  CRC  for packets from DMA to PMAC*/
#define AR10_ETHSW_PMAC_HD_CTL_TAG       1  /* Add  Tag, enable the VLAN tag to packets comming from DMA to PMAC and going to the switch */
#define AR10_ETHSW_PMAC_HD_CTL_ADD       0  /* Add  header  tag for packets comming from DMA to PMAC and going to the swicth*/

#define AR10_ETHSW_PMAC_TL               ( AR10_ETHSW_TOP + (0x83 * 4))
#define AR10_ETHSW_PMAC_SA1              ( AR10_ETHSW_TOP + (0x84 * 4))
#define AR10_ETHSW_PMAC_SA2              ( AR10_ETHSW_TOP + (0x85 * 4))
#define AR10_ETHSW_PMAC_SA3              ( AR10_ETHSW_TOP + (0x86 * 4))
#define AR10_ETHSW_PMAC_DA1              ( AR10_ETHSW_TOP + (0x87 * 4))
#define AR10_ETHSW_PMAC_DA2              ( AR10_ETHSW_TOP + (0x88 * 4))
#define AR10_ETHSW_PMAC_DA3              ( AR10_ETHSW_TOP + (0x89 * 4))
#define AR10_ETHSW_PMAC_VLAN             ( AR10_ETHSW_TOP + (0x8a * 4))
#define AR10_ETHSW_PMAC_VLAN_PRI         13      /*<15:13> VLAN priority */
#define AR10_ETHSW_PMAC_VLAN_CFI         12      /* CFI of the interserted VLAN tag */
#define AR10_ETHSW_PMAC_VLAN_VLAN_ID     0       /* <11:0> VLAN id */

#define AR10_ETHSW_PMAC_RX_IPG           ( AR10_ETHSW_TOP + (0x8b * 4))
#define AR10_ETHSW_PMAC_ST_ETYPE         ( AR10_ETHSW_TOP + (0x8c * 4))
#define AR10_ETHSW_PMAC_EWAN             ( AR10_ETHSW_TOP + (0x8d * 4))

#define DCDC_1V0_BASE                 0xBF106A00
#define DCDC_1V8_BASE                 0xBF106C00
#define DCDC_2V5_BASE                 0xBF106E00
#define DCDC_PWM0_OFFSET              0x24

#define PPE32_BASE  0xBE180000
#define PPE32_DEBUG_BREAK_TRACE_REG   PPE32_BASE + (0x0000 * 4)
#define PPE32_INT_MASK_STATUS_REG     PPE32_BASE + (0x0030 * 4)
#define PPE32_INT_RESOURCE_REG        PPE32_BASE + (0x0040 * 4)
#define PPE32_CDM_CODE_MEM_B0         PPE32_BASE + (0x1000 * 4)
#define PPE32_CDM_CODE_MEM_B1         PPE32_BASE + (0x2000 * 4)
#define PPE32_DATA_MEM_MAP_REG_BASE   PPE32_BASE + (0x4000 * 4)

#define PPE32_SLEEP                      PPE32_DATA_MEM_MAP_REG_BASE + (0x0010 * 4)
#define PPE32_SRST                       PPE32_DATA_MEM_MAP_REG_BASE + (0x0020 * 4)
#define PPE32_PP32_CFG                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0030 * 4)
#define PPE32_CDM_CFG                    PPE32_DATA_MEM_MAP_REG_BASE + (0x0100 * 4)
#define PPE32_MBOX_IGU0_ISRS             PPE32_DATA_MEM_MAP_REG_BASE + (0x0200 * 4)
#define PPE32_MBOX_IGU0_ISRC             PPE32_DATA_MEM_MAP_REG_BASE + (0x0201 * 4)
#define PPE32_MBOX_IGU0_ISR              PPE32_DATA_MEM_MAP_REG_BASE + (0x0202 * 4)
#define PPE32_MBOX_IGU0_IER              PPE32_DATA_MEM_MAP_REG_BASE + (0x0203 * 4)
#define PPE32_MBOX_IGU1_ISRS             PPE32_DATA_MEM_MAP_REG_BASE + (0x0204 * 4)
#define PPE32_MBOX_IGU1_ISRC             PPE32_DATA_MEM_MAP_REG_BASE + (0x0205 * 4)
#define PPE32_MBOX_IGU1_ISR              PPE32_DATA_MEM_MAP_REG_BASE + (0x0206 * 4)
#define PPE32_MBOX_IGU1_IER              PPE32_DATA_MEM_MAP_REG_BASE + (0x0207 * 4)
#define PPE32_MBOX_IGU2_ISRS             PPE32_DATA_MEM_MAP_REG_BASE + (0x0210 * 4)
#define PPE32_MBOX_IGU2_ISRC             PPE32_DATA_MEM_MAP_REG_BASE + (0x0211 * 4)
#define PPE32_MBOX_IGU2_ISR              PPE32_DATA_MEM_MAP_REG_BASE + (0x0212 * 4)
#define PPE32_MBOX_IGU2_IER              PPE32_DATA_MEM_MAP_REG_BASE + (0x0213 * 4)
#define PPE32_MBOX_IGU3_ISRS             PPE32_DATA_MEM_MAP_REG_BASE + (0x0214 * 4)
#define PPE32_MBOX_IGU3_ISRC             PPE32_DATA_MEM_MAP_REG_BASE + (0x0215 * 4)
#define PPE32_MBOX_IGU3_ISR              PPE32_DATA_MEM_MAP_REG_BASE + (0x0216 * 4)
#define PPE32_MBOX_IGU3_IER              PPE32_DATA_MEM_MAP_REG_BASE + (0x0217 * 4)
#define PPE32_MBOX_IGU4_ISRS             PPE32_DATA_MEM_MAP_REG_BASE + (0x0218 * 4)
#define PPE32_MBOX_IGU4_ISRC             PPE32_DATA_MEM_MAP_REG_BASE + (0x0219 * 4)
#define PPE32_MBOX_IGU4_ISR              PPE32_DATA_MEM_MAP_REG_BASE + (0x021A * 4)
#define PPE32_MBOX_IGU4_IER              PPE32_DATA_MEM_MAP_REG_BASE + (0x021B * 4)
#define PPE32_SB_MST_PRI0                PPE32_DATA_MEM_MAP_REG_BASE + (0x0300 * 4)
#define PPE32_SB_MST_PRI1                PPE32_DATA_MEM_MAP_REG_BASE + (0x0301 * 4)
#define PPE32_SB_MST_PRI2                PPE32_DATA_MEM_MAP_REG_BASE + (0x0302 * 4)
#define PPE32_SB_MST_PRI3                PPE32_DATA_MEM_MAP_REG_BASE + (0x0303 * 4)
#define PPE32_SB_MST_SEL                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0304 * 4)
#define PPE32_RFBI_CFG                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0400 * 4)
#define PPE32_RBA_CFG0                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0404 * 4)
#define PPE32_RBA_CFG1                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0405 * 4)
#define PPE32_RCA_CFG0                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0408 * 4)
#define PPE32_RCA_CFG1                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0409 * 4)
#define PPE32_RDES_CFG0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x040C * 4)
#define PPE32_RDES_CFG1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x040D * 4)
#define PPE32_SFSM_STATE0                PPE32_DATA_MEM_MAP_REG_BASE + (0x0410 * 4)
#define PPE32_SFSM_STATE1                PPE32_DATA_MEM_MAP_REG_BASE + (0x0411 * 4)
#define PPE32_SFSM_DBA0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0412 * 4)
#define PPE32_SFSM_DBA1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0413 * 4)
#define PPE32_SFSM_CBA0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0414 * 4)
#define PPE32_SFSM_CBA1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0415 * 4)
#define PPE32_SFSM_CFG0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0416 * 4)
#define PPE32_SFSM_CFG1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0417 * 4)
#define PPE32_SFSM_PGCNT0                PPE32_DATA_MEM_MAP_REG_BASE + (0x041C * 4)
#define PPE32_SFSM_PGCNT1                PPE32_DATA_MEM_MAP_REG_BASE + (0x041D * 4)

#define PPE32_FFSM_DBA0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0508 * 4)
#define PPE32_FFSM_DBA1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0509 * 4)
#define PPE32_FFSM_CFG0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x050A * 4)
#define PPE32_FFSM_CFG1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x050B * 4)
#define PPE32_FFSM_IDLE_HEAD_BC0         PPE32_DATA_MEM_MAP_REG_BASE + (0x050E * 4)
#define PPE32_FFSM_IDLE_HEAD_BC1         PPE32_DATA_MEM_MAP_REG_BASE + (0x050F * 4)
#define PPE32_FFSM_PGCNG0                PPE32_DATA_MEM_MAP_REG_BASE + (0x0514 * 4)
#define PPE32_FFSM_PGCNG1                PPE32_DATA_MEM_MAP_REG_BASE + (0x0515 * 4)
#define PPE32_ETOP_MDIO_CFG              PPE32_DATA_MEM_MAP_REG_BASE + (0x0600 * 4)
#define PPE32_ETOP_MDIO_ACC              PPE32_DATA_MEM_MAP_REG_BASE + (0x0601 * 4)
#define PPE32_ETOP_CFG                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0602 * 4)
#define PPE32_ETOP_IG_VLAN_COS           PPE32_DATA_MEM_MAP_REG_BASE + (0x0603 * 4)
#define PPE32_ETOP_IG_DSCP_COS3          PPE32_DATA_MEM_MAP_REG_BASE + (0x0604 * 4)
#define PPE32_ETOP_IG_DSCP_COS2          PPE32_DATA_MEM_MAP_REG_BASE + (0x0605 * 4)
#define PPE32_ETOP_IG_DSCP_COS1          PPE32_DATA_MEM_MAP_REG_BASE + (0x0606 * 4)
#define PPE32_ETOP_IG_DSCP_COS0          PPE32_DATA_MEM_MAP_REG_BASE + (0x0607 * 4)
#define PPE32_ETOP_IG_PLEN_CTRL          PPE32_DATA_MEM_MAP_REG_BASE + (0x0608 * 4)
#define PPE32_ETOP_ISR                   PPE32_DATA_MEM_MAP_REG_BASE + (0x060A * 4)
#define PPE32_ETOP_IER                   PPE32_DATA_MEM_MAP_REG_BASE + (0x060B * 4)
#define PPE32_ETOP_VPID                  PPE32_DATA_MEM_MAP_REG_BASE + (0x060C * 4)
#define PPE32_ENET_0                     PPE32_DATA_MEM_MAP_REG_BASE + (0x0610 * 4)
#define PPE32_ENET_1                     PPE32_DATA_MEM_MAP_REG_BASE + (0x0650 * 4)
#define PPE32_ENET0_MAC_CFG              PPE32_DATA_MEM_MAP_REG_BASE + (0x0610 * 4)
#define PPE32_ENET0S_DBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0612 * 4)
#define PPE32_ENET0S_CBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0613 * 4)
#define PPE32_ENET0S_CFG                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0614 * 4)
#define PPE32_ENET0S_PGCNT               PPE32_DATA_MEM_MAP_REG_BASE + (0x0615 * 4)
#define PPE32_ENET0S_PKTCNT              PPE32_DATA_MEM_MAP_REG_BASE + (0x0616 * 4)
#define PPE32_ENET0S_BUF_CTRL            PPE32_DATA_MEM_MAP_REG_BASE + (0x0617 * 4)
#define PPE32_ENET0S_COS_CFG             PPE32_DATA_MEM_MAP_REG_BASE + (0x0618 * 4)
#define PPE32_ENET0S_IGDROP              PPE32_DATA_MEM_MAP_REG_BASE + (0x0619 * 4)
#define PPE32_ENET0S_IGERR               PPE32_DATA_MEM_MAP_REG_BASE + (0x061A * 4)
#define PPE32_ENET0S_MAC_DA0             PPE32_DATA_MEM_MAP_REG_BASE + (0x061B * 4)
#define PPE32_ENET0S_MAC_DA1             PPE32_DATA_MEM_MAP_REG_BASE + (0x061C * 4)
#define PPE32_ENET0F_DBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0630 * 4)
#define PPE32_ENET0F_CBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0631 * 4)
#define PPE32_ENET0F_CFG                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0632 * 4)
#define PPE32_ENET0F_PGCNT               PPE32_DATA_MEM_MAP_REG_BASE + (0x0633 * 4)
#define PPE32_ENET0F_PKTCNT              PPE32_DATA_MEM_MAP_REG_BASE + (0x0634 * 4)
#define PPE32_ENET0F_HFCTRL              PPE32_DATA_MEM_MAP_REG_BASE + (0x0635 * 4)
#define PPE32_ENET0F_TXCTRL              PPE32_DATA_MEM_MAP_REG_BASE + (0x0636 * 4)
#define PPE32_ENET0F_VLCOS0              PPE32_DATA_MEM_MAP_REG_BASE + (0x0638 * 4)
#define PPE32_ENET0F_VLCOS1              PPE32_DATA_MEM_MAP_REG_BASE + (0x0639 * 4)
#define PPE32_ENET0F_VLCOS2              PPE32_DATA_MEM_MAP_REG_BASE + (0x063A * 4)
#define PPE32_ENET0F_VLCOS3              PPE32_DATA_MEM_MAP_REG_BASE + (0x063B * 4)
#define PPE32_ENET0F_EGCOL               PPE32_DATA_MEM_MAP_REG_BASE + (0x063C * 4)
#define PPE32_ENET0F_EGDROP              PPE32_DATA_MEM_MAP_REG_BASE + (0x063D * 4)
#define PPE32_DMRX_DBA			 PPE32_DATA_MEM_MAP_REG_BASE + (0x0612 * 4)
#define PPE32_DMRX_CBA			 PPE32_DATA_MEM_MAP_REG_BASE + (0x0613 * 4)
#define PPE32_DMRX_CFG           PPE32_DATA_MEM_MAP_REG_BASE + (0x0614 * 4)
#define PPE32_DSRX_DB			 PPE32_DATA_MEM_MAP_REG_BASE + (0x0710 * 4)
#define PPE32_DSRX_CB			 PPE32_DATA_MEM_MAP_REG_BASE + (0x0711 * 4)
#define PPE32_DSRX_CFG                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0712 * 4)

// #define PPE32_ENET1_MAC_CFG              PPE32_DATA_MEM_MAP_REG_BASE + (0x0650 * 4)
// #define PPE32_ENET1S_DBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0652 * 4)
// #define PPE32_ENET1S_CBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0653 * 4)
// #define PPE32_ENET1S_CFG                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0654 * 4)
// #define PPE32_ENET1S_PGCNT               PPE32_DATA_MEM_MAP_REG_BASE + (0x0655 * 4)
// #define PPE32_ENET1S_PKTCNT              PPE32_DATA_MEM_MAP_REG_BASE + (0x0656 * 4)
// #define PPE32_ENET1S_BUF_CTRL            PPE32_DATA_MEM_MAP_REG_BASE + (0x0657 * 4)
// #define PPE32_ENET1S_COS_CFG             PPE32_DATA_MEM_MAP_REG_BASE + (0x0658 * 4)
// #define PPE32_ENET1S_IGDROP              PPE32_DATA_MEM_MAP_REG_BASE + (0x0659 * 4)
// #define PPE32_ENET1S_IGERR               PPE32_DATA_MEM_MAP_REG_BASE + (0x065A * 4)
// #define PPE32_ENET1S_MAC_DA0             PPE32_DATA_MEM_MAP_REG_BASE + (0x065B * 4)
// #define PPE32_ENET1S_MAC_DA1             PPE32_DATA_MEM_MAP_REG_BASE + (0x065C * 4)
// #define PPE32_ENET1F_DBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0670 * 4)
// #define PPE32_ENET1F_CBA                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0671 * 4)
// #define PPE32_ENET1F_CFG                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0672 * 4)
// #define PPE32_ENET1F_PGCNT               PPE32_DATA_MEM_MAP_REG_BASE + (0x0673 * 4)
// #define PPE32_ENET1F_PKTCNT              PPE32_DATA_MEM_MAP_REG_BASE + (0x0674 * 4)
// #define PPE32_ENET1F_HFCTRL              PPE32_DATA_MEM_MAP_REG_BASE + (0x0675 * 4)
// #define PPE32_ENET1F_TXCTRL              PPE32_DATA_MEM_MAP_REG_BASE + (0x0676 * 4)
// #define PPE32_ENET1F_VLCOS0              PPE32_DATA_MEM_MAP_REG_BASE + (0x0678 * 4)
// #define PPE32_ENET1F_VLCOS1              PPE32_DATA_MEM_MAP_REG_BASE + (0x0679 * 4)
// #define PPE32_ENET1F_VLCOS2              PPE32_DATA_MEM_MAP_REG_BASE + (0x067A * 4)
// #define PPE32_ENET1F_VLCOS3              PPE32_DATA_MEM_MAP_REG_BASE + (0x067B * 4)
// #define PPE32_ENET1F_EGCOL               PPE32_DATA_MEM_MAP_REG_BASE + (0x067C * 4)
// #define PPE32_ENET1F_EGDROP              PPE32_DATA_MEM_MAP_REG_BASE + (0x067D * 4)

#define PPE32_DPLUS_TXDB                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0700 * 4)
#define PPE32_DPLUS_TXCB                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0701 * 4)
#define PPE32_DPLUS_TXCFG                PPE32_DATA_MEM_MAP_REG_BASE + (0x0702 * 4)
#define PPE32_DPLUS_TXPGCNT              PPE32_DATA_MEM_MAP_REG_BASE + (0x0703 * 4)
#define PPE32_DPLUS_RXDB                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0710 * 4)
#define PPE32_DPLUS_RXCB                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0711 * 4)
#define PPE32_DPLUS_RXCFG                PPE32_DATA_MEM_MAP_REG_BASE + (0x0712 * 4)
#define PPE32_DPLUS_RXPGCNT              PPE32_DATA_MEM_MAP_REG_BASE + (0x0713 * 4)
#define PPE32_BMC_CFG0                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0800 * 4)
#define PPE32_BMC_POLY0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0801 * 4)
#define PPE32_BMC_CFG1                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0802 * 4)
#define PPE32_BMC_CRC0                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0803 * 4)
#define PPE32_BMC_POLY1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0804 * 4)
#define PPE32_BMC_CRC1                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0805 * 4)
#define PPE32_BMC_CMD3                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0806 * 4)
#define PPE32_BMC_CMD2                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0807 * 4)
#define PPE32_BMC_CMD1                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0808 * 4)
#define PPE32_BMC_CMD0                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0809 * 4)
#define PPE32_SLL_CMD1                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0900 * 4)
#define PPE32_SLL_CMD0                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0901 * 4)
#define PPE32_SLL_KEY0                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0910 * 4)
#define PPE32_SLL_KEY1                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0911 * 4)
#define PPE32_SLL_KEY2                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0912 * 4)
#define PPE32_SLL_KEY3                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0913 * 4)
#define PPE32_SLL_KEY4                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0914 * 4)
#define PPE32_SLL_KEY5                   PPE32_DATA_MEM_MAP_REG_BASE + (0x0915 * 4)
#define PPE32_SLL_RESULT                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0920 * 4)
#define PPE32_SLL1_CMD1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B00 * 4)
#define PPE32_SLL1_CMD0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B01 * 4)
#define PPE32_SLL1_KEY0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B10 * 4)
#define PPE32_SLL1_KEY1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B11 * 4)
#define PPE32_SLL1_KEY2                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B12 * 4)
#define PPE32_SLL1_KEY3                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B13 * 4)
#define PPE32_SLL1_KEY4                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B14 * 4)
#define PPE32_SLL1_KEY5                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B15 * 4)
#define PPE32_SLL1_RESULT                PPE32_DATA_MEM_MAP_REG_BASE + (0x0B20 * 4)
#define PPE32_EMA_CMDCFG                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0A00 * 4)
#define PPE32_EMA_DATACFG                PPE32_DATA_MEM_MAP_REG_BASE + (0x0A01 * 4)
#define PPE32_EMA_CMDCNT                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0A02 * 4)
#define PPE32_EMA_DATACNT                PPE32_DATA_MEM_MAP_REG_BASE + (0x0A03 * 4)
#define PPE32_EMA_ISR                    PPE32_DATA_MEM_MAP_REG_BASE + (0x0A04 * 4)
#define PPE32_EMA_IER                    PPE32_DATA_MEM_MAP_REG_BASE + (0x0A05 * 4)
#define PPE32_EMA_CFG                    PPE32_DATA_MEM_MAP_REG_BASE + (0x0A06 * 4)
#define PPE32_EMA_SUBID                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0A07 * 4)

// #define PPE32_UTP_TXCA0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B00 * 4)
// #define PPE32_UTP_TXCA1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B01 * 4)
// #define PPE32_UTP_TXNA0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B02 * 4)
// #define PPE32_UTP_TXNA1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B03 * 4)
// #define PPE32_UTP_RXCA0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B10 * 4)
// #define PPE32_UTP_RXCA1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B11 * 4)
// #define PPE32_UTP_RXNA0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B12 * 4)
// #define PPE32_UTP_RXNA1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0B13 * 4)
// #define PPE32_UTP_CFG                    PPE32_DATA_MEM_MAP_REG_BASE + (0x0B20 * 4)
// #define PPE32_UTP_ISR                    PPE32_DATA_MEM_MAP_REG_BASE + (0x0B30 * 4)
// #define PPE32_UTP_IER                    PPE32_DATA_MEM_MAP_REG_BASE + (0x0B31 * 4)

#define PPE32_QSB_RELOG                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0C00 * 4)
#define PPE32_QSB_EMIT0                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0C01 * 4)
#define PPE32_QSB_EMIT1                  PPE32_DATA_MEM_MAP_REG_BASE + (0x0C02 * 4)
#define PPE32_DREG_A_VERSION             PPE32_DATA_MEM_MAP_REG_BASE + (0x0D00 * 4)
#define PPE32_DREG_A_CFG                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0D01 * 4)
#define PPE32_DREG_AT_CTRL               PPE32_DATA_MEM_MAP_REG_BASE + (0x0D02 * 4)
#define PPE32_DREG_AT_CB_CFG0            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D03 * 4)
#define PPE32_DREG_AT_CB_CFG1            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D04 * 4)
#define PPE32_DREG_AR_CTRL               PPE32_DATA_MEM_MAP_REG_BASE + (0x0D08 * 4)
#define PPE32_DREG_AR_CB_CFG0            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D09 * 4)
#define PPE32_DREG_AR_CB_CFG1            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D0A * 4)
#define PPE32_DREG_A_UTPCFG              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D0E * 4)
#define PPE32_DREG_A_STATUS              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D0F * 4)
#define PPE32_DREG_AT_CFG0               PPE32_DATA_MEM_MAP_REG_BASE + (0x0D20 * 4)
#define PPE32_DREG_AT_CFG1               PPE32_DATA_MEM_MAP_REG_BASE + (0x0D21 * 4)
#define PPE32_DREG_AT_FB_SIZE0           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D22 * 4)
#define PPE32_DREG_AT_FB_SIZE1           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D23 * 4)
#define PPE32_DREG_AT_CELL0              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D24 * 4)
#define PPE32_DREG_AT_CELL1              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D25 * 4)
#define PPE32_DREG_AT_IDLE_CNT0          PPE32_DATA_MEM_MAP_REG_BASE + (0x0D26 * 4)
#define PPE32_DREG_AT_IDLE_CNT1          PPE32_DATA_MEM_MAP_REG_BASE + (0x0D27 * 4)
#define PPE32_DREG_AT_IDLE0              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D28 * 4)
#define PPE32_DREG_AT_IDLE1              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D29 * 4)
#define PPE32_DREG_AR_CFG0               PPE32_DATA_MEM_MAP_REG_BASE + (0x0D60 * 4)
#define PPE32_DREG_AR_CFG1               PPE32_DATA_MEM_MAP_REG_BASE + (0x0D61 * 4)
#define PPE32_DREG_AR_FB_STAT0           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D62 * 4)
#define PPE32_DREG_AR_FB_STAT1           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D63 * 4)
#define PPE32_DREG_AR_FB_END0            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D64 * 4)
#define PPE32_DREG_AR_FB_END1            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D65 * 4)
#define PPE32_DREG_AR_ATM_STAT0          PPE32_DATA_MEM_MAP_REG_BASE + (0x0D66 * 4)
#define PPE32_DREG_AR_ATM_STAT1          PPE32_DATA_MEM_MAP_REG_BASE + (0x0D67 * 4)
#define PPE32_DREG_AR_CELL0              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D68 * 4)
#define PPE32_DREG_AR_CELL1              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D69 * 4)
#define PPE32_DREG_AR_IDLE_CNT0          PPE32_DATA_MEM_MAP_REG_BASE + (0x0D6A * 4)
#define PPE32_DREG_AR_IDLE_CNT1          PPE32_DATA_MEM_MAP_REG_BASE + (0x0D6B * 4)
#define PPE32_DREG_AR_AIIDLE_CNT0        PPE32_DATA_MEM_MAP_REG_BASE + (0x0D6C * 4)
#define PPE32_DREG_AR_AIIDLE_CNT1        PPE32_DATA_MEM_MAP_REG_BASE + (0x0D6D * 4)
#define PPE32_DREG_AR_BE_CNT0            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D6E * 4)
#define PPE32_DREG_AR_BE_CNT1            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D6F * 4)
#define PPE32_DREG_AR_HEC_CNT0           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D70 * 4)
#define PPE32_DREG_AR_HEC_CNT1           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D71 * 4)
#define PPE32_DREG_AR_CD_CNT0            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D72 * 4)
#define PPE32_DREG_AR_CD_CNT1            PPE32_DATA_MEM_MAP_REG_BASE + (0x0D73 * 4)
#define PPE32_DREG_AR_IDLE0              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D74 * 4)
#define PPE32_DREG_AR_IDLE1              PPE32_DATA_MEM_MAP_REG_BASE + (0x0D75 * 4)
#define PPE32_DREG_AR_DELIN0             PPE32_DATA_MEM_MAP_REG_BASE + (0x0D76 * 4)
#define PPE32_DREG_AR_DELIN1             PPE32_DATA_MEM_MAP_REG_BASE + (0x0D77 * 4)
#define PPE32_DREG_RESV0                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0D78 * 4)
#define PPE32_DREG_RESV1                 PPE32_DATA_MEM_MAP_REG_BASE + (0x0D79 * 4)
#define PPE32_DREG_RX_MIB_CMD0           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D80 * 4)
#define PPE32_DREG_RX_MIB_CMD1           PPE32_DATA_MEM_MAP_REG_BASE + (0x0D81 * 4)
#define PPE32_DREG_AR_OVDROP_CNT0        PPE32_DATA_MEM_MAP_REG_BASE + (0x0D98 * 4)
#define PPE32_DREG_AR_OVDROP_CNT1        PPE32_DATA_MEM_MAP_REG_BASE + (0x0D99 * 4)

#define PPE32_CDM_PRIV_DATA_MEM_B1    PPE32_BASE + (0x5000 * 4)
#define PPE32_PPM_INT_UNIT            PPE32_BASE + (0x6000 * 4)
#define PPE32_PPM_TIMER0              PPE32_BASE + (0x6100 * 4)
#define PPE32_PPM_TASK_INDEP_REG      PPE32_BASE + (0x6200 * 4)
#define PPE32_PPS_BRK                 PPE32_BASE + (0x6300 * 4)
#define PPE32_PPM_TIMER1              PPE32_BASE + (0x6400 * 4)
#define PPE32_SB_RAM_B0	              PPE32_BASE + (0x8000 * 4) 
#define PPE32_SB_RAM_B1               PPE32_BASE + (0x8800 * 4)
#define PPE32_SB_RAM_B2               PPE32_BASE + (0x9000 * 4)
#define PPE32_SB_RAM_B3               PPE32_BASE + (0x9800 * 4)
#define PPE32_SB_DFEMEM_START         PPE32_BASE + (0xA000 * 4)
#define PPE32_SB_DFEMEM_END           PPE32_BASE + (0xABFF * 4)
#define PPE32_QSB_CFG_REG             PPE32_BASE + (0xC000 * 4)

#define PPE32_DATA_MEM_INT               0x0000
#define PPE32_CMD_PRIV_DATA_MEM_B1_INT   0x1000
#define PPE32_SB_RAM_B0_INT              0x2000
#define PPE32_SB_RAM_B1_INT              0x2800
#define PPE32_SB_RAM_B2_INT              0x3000
#define PPE32_SB_RAM_B3_INT              0x3800
#define PPE32_SB_DFEMEM_INT              0x4000  
//PROGRAMMED BY MIPS - QSB REGBANK
#define MIPS_QSB_ICDV_REG            PPE32_BASE + (0xC007 * 4)
#define MIPS_QSB_SBL_REG             PPE32_BASE + (0xC009 * 4)
#define MIPS_QSB_CFG_REG             PPE32_BASE + (0xC00A * 4)
#define MIPS_QSB_RTM_REG             PPE32_BASE + (0xC00B * 4)
#define MIPS_QSB_RTD_REG             PPE32_BASE + (0xC00C * 4)
#define MIPS_QSB_RAMAC_REG           PPE32_BASE + (0xC00D * 4)
#define MIPS_QSB_ISTAT_REG           PPE32_BASE + (0xC00E * 4)
#define MIPS_QSB_IMR_REG             PPE32_BASE + (0xC00F * 4)
#define MIPS_QSB_SCR_REG             PPE32_BASE + (0xC010 * 4)

/***********************************************************************/
/*  Module      :  CHIPID register address and bits                    */
/***********************************************************************/
#define AR10_CHIPID_BASE     		0xBF107340
#define AR10_MPS_MANID				AR10_CHIPID_BASE
#define AR10_MPS_CHIPID				(AR10_CHIPID_BASE + 0x4)
#define AR10_CHIPID   				(AR10_CHIPID_BASE + 0x8) 
#define AR10_ID_CFG					(AR10_CHIPID_BASE + 0x10)

/***********************************************************************/
/*  Module      :  Cross Bar register address and bits                       */
/***********************************************************************/

#define AR10_CSS                          (0xBF400000)
/***********************************************************************/

/***CSS Control***/
#define AR10_CSS_AL_CONTROL                      ((volatile u32*)(AR10_CSS + 0x0430))


/***********************************************************************/
/*  Module      :  Cross Bar register address and bits                       */
/***********************************************************************/

#define AR10_ICU_BASE                     (0xBF880200)
/***********************************************************************/

#define AR10_ICU_IM3_ISR                  ((volatile u32*)(AR10_ICU_BASE + 0x0078))



#define AR10_REG32(addr)                 *((volatile u32 *)(addr))
#define AR10_REG16(addr)                 *((volatile u16 *)(addr))
#define AR10_REG8(addr)                  *((volatile u8 *)(addr))
#define REG32(addr)                 *((volatile u32 *)(addr))
#define REG16(addr)                 *((volatile u16 *)(addr))
#define REG8(addr)                  *((volatile u8 *)(addr))
/***********************************************************************/

/************************************************************************/
/*	Module		:	Switch PDI registers								*/
/************************************************************************/

#define ADDR_BASE_ETHSW_PDI 0xBE108000    //Need to be modified as per the User Requirements
#define ADDR_MULT_ETHSW_PDI 4    //Need to be modified as per the User Requirements
#define ADDR_MACRO_ETHSW_PDI(a) (a)  //Need to be modified as per User Requirements

//***********************************************************
//Register File Address
//***********************************************************

  //Register File : ETHSW_TOP_PDI
  //This chapter provides the registers that are needed to control the toplevel functions of the Ethernet switch module.
# define ADR_ETHSW_TOP_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x000)))

  //Register File : ETHSW_BM_PDI
  //This chapter provides the common registers that are needed to control the Ethernet Switch Buffer Manager.
# define ADR_ETHSW_BM_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x040)))

  //Register File : ETHSW_BM_PORT_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x080)))

  //Register File : ETHSW_BM_PORT_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x082)))

  //Register File : ETHSW_BM_PORT_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x084)))

  //Register File : ETHSW_BM_PORT_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x086)))

  //Register File : ETHSW_BM_PORT_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x088)))

  //Register File : ETHSW_BM_PORT_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08A)))

  //Register File : ETHSW_BM_PORT_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08C)))

  //Register File : ETHSW_BM_QUEUE_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x100)))

  //Register File : ETHSW_BM_QUEUE_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x102)))

  //Register File : ETHSW_BM_QUEUE_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x104)))

  //Register File : ETHSW_BM_QUEUE_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x106)))

  //Register File : ETHSW_BM_QUEUE_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x108)))

  //Register File : ETHSW_BM_QUEUE_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10A)))

  //Register File : ETHSW_BM_QUEUE_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10C)))

  //Register File : ETHSW_BM_QUEUE_PDI_7
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10E)))

  //Register File : ETHSW_BM_QUEUE_PDI_8
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x110)))

  //Register File : ETHSW_BM_QUEUE_PDI_9
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x112)))

  //Register File : ETHSW_BM_QUEUE_PDI_10
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x114)))

  //Register File : ETHSW_BM_QUEUE_PDI_11
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x116)))

  //Register File : ETHSW_BM_QUEUE_PDI_12
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x118)))

  //Register File : ETHSW_BM_QUEUE_PDI_13
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_13	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11A)))

  //Register File : ETHSW_BM_QUEUE_PDI_14
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_14	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11C)))

  //Register File : ETHSW_BM_QUEUE_PDI_15
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_15	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11E)))

  //Register File : ETHSW_BM_QUEUE_PDI_16
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_16	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x120)))

  //Register File : ETHSW_BM_QUEUE_PDI_17
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_17	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x122)))

  //Register File : ETHSW_BM_QUEUE_PDI_18
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_18	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x124)))

  //Register File : ETHSW_BM_QUEUE_PDI_19
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_19	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x126)))

  //Register File : ETHSW_BM_QUEUE_PDI_20
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_20	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x128)))

  //Register File : ETHSW_BM_QUEUE_PDI_21
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_21	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12A)))

  //Register File : ETHSW_BM_QUEUE_PDI_22
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_22	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12C)))

  //Register File : ETHSW_BM_QUEUE_PDI_23
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_23	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12E)))

  //Register File : ETHSW_BM_QUEUE_PDI_24
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_24	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x130)))

  //Register File : ETHSW_BM_QUEUE_PDI_25
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_25	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x132)))

  //Register File : ETHSW_BM_QUEUE_PDI_26
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_26	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x134)))

  //Register File : ETHSW_BM_QUEUE_PDI_27
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_27	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x136)))

  //Register File : ETHSW_BM_QUEUE_PDI_28
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_28	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x138)))

  //Register File : ETHSW_BM_QUEUE_PDI_29
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_29	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13A)))

  //Register File : ETHSW_BM_QUEUE_PDI_30
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_30	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13C)))

  //Register File : ETHSW_BM_QUEUE_PDI_31
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_31	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13E)))

  //Register File : ETHSW_BM_SHAPER_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x140)))

  //Register File : ETHSW_BM_SHAPER_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x145)))

  //Register File : ETHSW_BM_SHAPER_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14A)))

  //Register File : ETHSW_BM_SHAPER_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14F)))

  //Register File : ETHSW_BM_SHAPER_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x154)))

  //Register File : ETHSW_BM_SHAPER_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x159)))

  //Register File : ETHSW_BM_SHAPER_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15E)))

  //Register File : ETHSW_BM_SHAPER_PDI_7
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x163)))

  //Register File : ETHSW_BM_SHAPER_PDI_8
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x168)))

  //Register File : ETHSW_BM_SHAPER_PDI_9
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16D)))

  //Register File : ETHSW_BM_SHAPER_PDI_10
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x172)))

  //Register File : ETHSW_BM_SHAPER_PDI_11
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x177)))

  //Register File : ETHSW_BM_SHAPER_PDI_12
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17C)))

  //Register File : ETHSW_BM_SHAPER_PDI_13
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_13	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x181)))

  //Register File : ETHSW_BM_SHAPER_PDI_14
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_14	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x186)))

  //Register File : ETHSW_BM_SHAPER_PDI_15
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_15	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18B)))

  //Register File : ETHSW_PCE_PDI
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x440)))

  //Register File : ETHSW_PCE_PORT_PDI_0
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x480)))

  //Register File : ETHSW_PCE_PORT_PDI_1
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48A)))

  //Register File : ETHSW_PCE_PORT_PDI_2
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x494)))

  //Register File : ETHSW_PCE_PORT_PDI_3
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49E)))

  //Register File : ETHSW_PCE_PORT_PDI_4
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A8)))

  //Register File : ETHSW_PCE_PORT_PDI_5
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B2)))

  //Register File : ETHSW_PCE_PORT_PDI_6
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BC)))

  //Register File : ETHSW_PCE_PORT_PDI_7
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C6)))

  //Register File : ETHSW_PCE_PORT_PDI_8
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D0)))

  //Register File : ETHSW_PCE_PORT_PDI_9
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DA)))

  //Register File : ETHSW_PCE_PORT_PDI_10
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E4)))

  //Register File : ETHSW_PCE_PORT_PDI_11
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EE)))

  //Register File : ETHSW_PCE_METER_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x580)))

  //Register File : ETHSW_PCE_METER_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x587)))

  //Register File : ETHSW_PCE_METER_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58E)))

  //Register File : ETHSW_PCE_METER_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x595)))

  //Register File : ETHSW_PCE_METER_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59C)))

  //Register File : ETHSW_PCE_METER_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A3)))

  //Register File : ETHSW_PCE_METER_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AA)))

  //Register File : ETHSW_PCE_METER_PDI_7
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B1)))

  //Register File : ETHSW_MACS_TOP_PDI
  //Not Specified
# define ADR_ETHSW_MACS_TOP_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C0)))

  //Register File : ETHSW_MAC_PDI_0
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x900)))

  //Register File : ETHSW_MAC_PDI_1
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90C)))

  //Register File : ETHSW_MAC_PDI_2
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x918)))

  //Register File : ETHSW_MAC_PDI_3
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x924)))

  //Register File : ETHSW_MAC_PDI_4
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x930)))

  //Register File : ETHSW_MAC_PDI_5
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93C)))

  //Register File : ETHSW_MAC_PDI_6
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x948)))

  //Register File : ETHSW_FDMA_PDI
  //This chapter provides the registers that are needed to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA40)))

  //Register File : ETHSW_FDMA_PORT_PDI_0
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA80)))

  //Register File : ETHSW_FDMA_PORT_PDI_1
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA86)))

  //Register File : ETHSW_FDMA_PORT_PDI_2
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8C)))

  //Register File : ETHSW_FDMA_PORT_PDI_3
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA92)))

  //Register File : ETHSW_FDMA_PORT_PDI_4
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA98)))

  //Register File : ETHSW_FDMA_PORT_PDI_5
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9E)))

  //Register File : ETHSW_FDMA_PORT_PDI_6
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA4)))

  //Register File : ETHSW_SDMA_PDI
  //This chapter provides the registers that are needed to globally control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB40)))

  //Register File : ETHSW_SDMA_PORT_PDI_0
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC0)))

  //Register File : ETHSW_SDMA_PORT_PDI_1
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC6)))

  //Register File : ETHSW_SDMA_PORT_PDI_2
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCC)))

  //Register File : ETHSW_SDMA_PORT_PDI_3
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD2)))

  //Register File : ETHSW_SDMA_PORT_PDI_4
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD8)))

  //Register File : ETHSW_SDMA_PORT_PDI_5
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDE)))

  //Register File : ETHSW_SDMA_PORT_PDI_6
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE4)))


//***********************************************************
//Register Address 
//***********************************************************

  //Register : ETHSW_SWRES
  //This register controls software reset functions of reset of configuration setting and RAM contents pointers, reset of HW without configuration setting and RAM contents pointers.
# define ADR_ETHSW_TOP_PDI_ETHSW_SWRES	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x000)))

  //Register : ETHSW_CLK
  //This register controls clock gating and frequency dividing functions of the Ethernet switch.
# define ADR_ETHSW_TOP_PDI_ETHSW_CLK	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x001)))

  //Register : ETHSW_DBG
  //This register controls the debug functions of the Ethernet switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_DBG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x002)))

  //Register : ETHSW_SSB_MODE
  //This register is used to access memory locations in the shared segment buffer.
  //It provides the access mode and the MSB part of the target address.
# define ADR_ETHSW_TOP_PDI_ETHSW_SSB_MODE	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x003)))

  //Register : ETHSW_SSB_ADDR
  //This register is used to access memory locations in the shared segment buffer.
  //It provides the LSB part of the target address.
# define ADR_ETHSW_TOP_PDI_ETHSW_SSB_ADDR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x004)))

  //Register : ETHSW_SSB_DATA
  //This register is used to access memory locations in the shared segment buffer.
  //It provides the 16 data bits to be read from or written to the target location.
# define ADR_ETHSW_TOP_PDI_ETHSW_SSB_DATA	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x005)))

  //Register : ETHSW_CAP_0
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x006)))

  //Register : ETHSW_CAP_1
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x007)))

  //Register : ETHSW_CAP_2
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x008)))

  //Register : ETHSW_CAP_3
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x009)))

  //Register : ETHSW_CAP_4
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00A)))

  //Register : ETHSW_CAP_5
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00B)))

  //Register : ETHSW_CAP_6
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00C)))

  //Register : ETHSW_CAP_7
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00D)))

  //Register : ETHSW_CAP_8
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00E)))

  //Register : ETHSW_CAP_9
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00F)))

  //Register : ETHSW_CAP_10
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x010)))

  //Register : ETHSW_CAP_11
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x011)))

  //Register : ETHSW_CAP_12
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x012)))

  //Register : ETHSW_VERSION
  //This register is used to indicate the implemented design version of the macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_VERSION	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x013)))

  //Register : ETHSW_IER
  //This register is used to enable or disable individual interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
  //There are global enable bits for interrupts generated by BM, PCE, SDMA, and MAC in addition to individual enable bits the related modules. To enable an interrupt, it must be enabled on module and top level.
# define ADR_ETHSW_TOP_PDI_ETHSW_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x014)))

  //Register : ETHSW_ISR
  //This register provides global interrupt status information.
  //If an interrupt is indicated for a block, the interrupt source can be read from the interrupt status register(s) located in the related submodule.
# define ADR_ETHSW_TOP_PDI_ETHSW_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x015)))

  //Register : ETHSW_SPARE_0
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x016)))

  //Register : ETHSW_SPARE_1
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x017)))

  //Register : ETHSW_SPARE_2
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x018)))

  //Register : ETHSW_SPARE_3
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x019)))

  //Register : ETHSW_SPARE_4
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01A)))

  //Register : ETHSW_SPARE_5
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01B)))

  //Register : ETHSW_SPARE_6
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01C)))

  //Register : ETHSW_SPARE_7
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01D)))

  //Register : ETHSW_SPARE_8
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01E)))

  //Register : ETHSW_SPARE_9
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01F)))

  //Register : ETHSW_SPARE_10
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x020)))

  //Register : ETHSW_SPARE_11
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x021)))

  //Register : ETHSW_SPARE_12
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x022)))

  //Register : ETHSW_SPARE_13
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_13	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x023)))

  //Register : ETHSW_SPARE_14
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_14	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x024)))

  //Register : ETHSW_SPARE_15
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_15	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x025)))

  //Register : BM_RAM_VAL_3
  //This register provides the value part 3 ("Bit [63:48]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x040)))

  //Register : BM_RAM_VAL_2
  //This register provides the value part 2 ("Bit [47:32]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x041)))

  //Register : BM_RAM_VAL_1
  //This register provides the value part 1 ("Bit [31:16]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x042)))

  //Register : BM_RAM_VAL_0
  //This register provides the value part 0 ("Bit [15:0]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x043)))

  //Register : BM_RAM_ADDR
  //This register provides the address of an entry within a selected table to be accessed.
# define ADR_ETHSW_BM_PDI_BM_RAM_ADDR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x044)))

  //Register : BM_RAM_CTRL
  //This register is used to handle the access to multiple RAMs.
# define ADR_ETHSW_BM_PDI_BM_RAM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x045)))

  //Register : BM_FSQM_GCTRL
  //This register is used to configure the Free Segment Queue Manager (FSQM).
# define ADR_ETHSW_BM_PDI_BM_FSQM_GCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x046)))

  //Register : BM_CONS_SEG
  //This register contains the number of consumed segments.
# define ADR_ETHSW_BM_PDI_BM_CONS_SEG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x047)))

  //Register : BM_CONS_PKT
  //This register contains the number of consumed packet pointers.
# define ADR_ETHSW_BM_PDI_BM_CONS_PKT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x048)))

  //Register : BM_GCTRL
  //This register is used to initialize parts of the Buffer Manager.
  //The reset bits are set by software to initialize the related circuit and must be reset by software to enable the function again.
# define ADR_ETHSW_BM_PDI_BM_GCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x049)))

  //Register : BM_QUEUE_GCTRL
  //This register is used to configure the Queue Manager.
# define ADR_ETHSW_BM_PDI_BM_QUEUE_GCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04A)))

  //Register : BM_WRED_RTH_0
  //This register is used to provide the WRED threshold values for frames marked "red".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_RTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04B)))

  //Register : BM_WRED_RTH_1
  //This register is used to provide the WRED threshold values for frames marked "red".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_RTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04C)))

  //Register : BM_WRED_YTH_0
  //This register is used to provide the WRED threshold values for frames marked "yellow".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_YTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04D)))

  //Register : BM_WRED_YTH_1
  //This register is used to provide the WRED threshold values for frames marked "yellow".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_YTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04E)))

  //Register : BM_WRED_GTH_0
  //This register is used to provide the WRED threshold values for frames marked "green".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_GTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04F)))

  //Register : BM_WRED_GTH_1
  //This register is used to provide the WRED threshold values for frames marked "green".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_GTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x050)))

  //Register : BM_DROP_GTH_0
  //This register is used to configure the thresholds regarding available packet pointer for packet ACM drop.
  //ACM drop is done if number of consumed packet pointer for a red marked packet is above THR_FQ threshold value.
# define ADR_ETHSW_BM_PDI_BM_DROP_GTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x051)))

  //Register : BM_DROP_GTH_1
  //This register is used to configure the thresholds regarding available packet pointer for packet ACM drop.
  //ACM drop is done if number of consumed packet pointer for a yellow marked packet is above THY_FQ threshold value.
# define ADR_ETHSW_BM_PDI_BM_DROP_GTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x052)))

  //Register : BM_DROP_GTH_2
  //This register is used to configure the thresholds regarding available packet pointer for packet ACM drop.
  //ACM drop is done if number of consumed packet pointer for a green marked packet is above THG_FQ threshold value.
# define ADR_ETHSW_BM_PDI_BM_DROP_GTH_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x053)))

  //Register : BM_IER
  //This register is used to enable or disable global BM interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_BM_PDI_BM_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x054)))

  //Register : BM_ISR
  //This register provides interrupt status summary of all port-related BM interrupts (see the BM_PISR_n registers) and interrupts that are related to the buffer manager's toplevel.
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
# define ADR_ETHSW_BM_PDI_BM_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x055)))

  //Register : BM_CISEL
  //RMON Counter event interrupts can be enabled for a single port only. This register is used to select the port to be observed.
# define ADR_ETHSW_BM_PDI_BM_CISEL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x056)))

  //Register : BM_DEBUG_CTRL
  //This register is used to configure the debug multiplexer.
# define ADR_ETHSW_BM_PDI_BM_DEBUG_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x057)))

  //Register : BM_DEBUG_VAL
  //This register is used to read data for debugging issues.
# define ADR_ETHSW_BM_PDI_BM_DEBUG_VAL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x058)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_0_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x080)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_0_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x081)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_1_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x082)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_1_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x083)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_2_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x084)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_2_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x085)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_3_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x086)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_3_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x087)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_4_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x088)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_4_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x089)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_5_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08A)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_5_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08B)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_6_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08C)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_6_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_0_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x100)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_0_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x101)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_1_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x102)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_1_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x103)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_2_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x104)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_2_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x105)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_3_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x106)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_3_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x107)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_4_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x108)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_4_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x109)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_5_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_5_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_6_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_6_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_7_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_7_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10F)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_8_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x110)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_8_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x111)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_9_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x112)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_9_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x113)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_10_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x114)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_10_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x115)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_11_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x116)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_11_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x117)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_12_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x118)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_12_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x119)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_13_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_13_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_14_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_14_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_15_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_15_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11F)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_16_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x120)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_16_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x121)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_17_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x122)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_17_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x123)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_18_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x124)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_18_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x125)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_19_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x126)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_19_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x127)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_20_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x128)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_20_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x129)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_21_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_21_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_22_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_22_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_23_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_23_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12F)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_24_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x130)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_24_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x131)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_25_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x132)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_25_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x133)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_26_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x134)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_26_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x135)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_27_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x136)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_27_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x137)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_28_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x138)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_28_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x139)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_29_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_29_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_30_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_30_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_31_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_31_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13F)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x140)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x141)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x142)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x143)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x144)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x145)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x146)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x147)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x148)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x149)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14A)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14B)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14C)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14D)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14E)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14F)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x150)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x151)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x152)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x153)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x154)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x155)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x156)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x157)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x158)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x159)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15A)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15B)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15C)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15D)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15E)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15F)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x160)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x161)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x162)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x163)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x164)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x165)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x166)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x167)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x168)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x169)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16A)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16B)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16C)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16D)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16E)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16F)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x170)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x171)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x172)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x173)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x174)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x175)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x176)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x177)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x178)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x179)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17A)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17B)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17C)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17D)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17E)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17F)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x180)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x181)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x182)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x183)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x184)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x185)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x186)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x187)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x188)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x189)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18A)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18B)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18C)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18D)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18E)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18F)))

  //Register : PCE_TBL_KEY_7
  //This register provides the data ("key") to a selected table at the selected address (Bit [127:112]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x440)))

  //Register : PCE_TBL_KEY_6
  //This register provides the data ("key") to a selected table at the selected address (Bit [111:96]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x441)))

  //Register : PCE_TBL_KEY_5
  //This register provides the data ("key") to a selected table at the selected address (Bit [95:80]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x442)))

  //Register : PCE_TBL_KEY_4
  //This register provides the data ("key") to a selected table at the selected address (Bit [79:64]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x443)))

  //Register : PCE_TBL_KEY_3
  //This register provides the data ("key") to a selected table at the selected address (Bit [63:48]).
  //This register is used to access the traffic flow table, the MAC bridging table, and the IP Destination/Source Address tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x444)))

  //Register : PCE_TBL_KEY_2
  //This register provides the data ("key") to a selected table at the selected address (Bit [47:32]).
  //This register is used to access the traffic flow table, the MAC bridging table, the MAC Source/Destination Address table, and the IP Destination/Source Address tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x445)))

  //Register : PCE_TBL_KEY_1
  //This register provides the data ("key") to a selected table at the selected address (Bit [31:16]).
  //This register is used to access the traffic flow table, the MAC bridging table, the MAC Source/Destination Address table, the multicast HW/SW tables, and the IP Destination/Source Address tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x446)))

  //Register : PCE_TBL_KEY_0
  //This register provides the data ("key") to a selected table at the selected address (Bit [15:0]).
  //This register is used to access any of the tables that provides a key.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x447)))

  //Register : PCE_TBL_MASK_0
  //This register provides the mask associated with an entry to be written.
  //This register is also used as forth data register for parser microcode accesses.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_MASK_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x448)))

  //Register : PCE_TBL_VAL_4
  //This register provides the value that is associated with the key (Bit [79:64]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x449)))

  //Register : PCE_TBL_VAL_3
  //This register provides the value that is associated with the key (Bit [63:48]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44A)))

  //Register : PCE_TBL_VAL_2
  //This register provides the value that is associated with the key ("Bit [47:32]").
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44B)))

  //Register : PCE_TBL_VAL_1
  //This register provides the value that is associated with the key (Bit [31:16]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44C)))

  //Register : PCE_TBL_VAL_0
  //This register provides the value that is associated with the key (Bit [15:0]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44D)))

  //Register : PCE_TBL_ADDR
  //This register provides the address within a selected table to be written to ("tbl_entry_addr_wrd").
# define ADR_ETHSW_PCE_PDI_PCE_TBL_ADDR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44E)))

  //Register : PCE_TBL_CTRL
  //This register is used to handle the access to multiple look-up tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44F)))

  //Register : PCE_TBL_STAT
  //This register is used to handle the access to multiple look-up tables. It indicates the filling level (empty or full) and ongoing accesses.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x450)))

  //Register : PCE_AGE_0
  //This register is used to configure the MAC table aging counter's exponent values.
  //The aging time is calculated from PCE_AGE_0.EXP and PCE_AGE_1.MANT according to the formula:
  //Aging Time = (MANT+1) x 2^(EXP+1) x 1.31 ms
  //For a default aging time of 300 s the values of MANT = 0xDF85 and EXP = 0x10 are selected.
# define ADR_ETHSW_PCE_PDI_PCE_AGE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x451)))

  //Register : PCE_AGE_1
  //This register is used to configure the MAC table aging counter's mantissa value.
  //Aging Time = (MANT+1) x 2^(EXP+1) x 1.31 ms
# define ADR_ETHSW_PCE_PDI_PCE_AGE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x452)))

  //Register : PCE_PMAP_1
  //This register is used to define the handling of monitored ports.
# define ADR_ETHSW_PCE_PDI_PCE_PMAP_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x453)))

  //Register : PCE_PMAP_2
  //This register is used to define default port maps for multicast frames.
# define ADR_ETHSW_PCE_PDI_PCE_PMAP_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x454)))

  //Register : PCE_PMAP_3
  //This register is used to define the default port map for unknown unicast frames.
# define ADR_ETHSW_PCE_PDI_PCE_PMAP_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x455)))

  //Register : PCE_GCTRL_0
  //This register is used to provide global control settings.
# define ADR_ETHSW_PCE_PDI_PCE_GCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x456)))

  //Register : PCE_GCTRL_1
  //This register is used to provide global control settings.
# define ADR_ETHSW_PCE_PDI_PCE_GCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x457)))

  //Register : PCE_TCM_GLOB_CTRL
  //This register is used to configure general srTCM setting).
# define ADR_ETHSW_PCE_PDI_PCE_TCM_GLOB_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x458)))

  //Register : PCE_IGMP_CTRL
  //This register is used to configure the IGMP function.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x459)))

  //Register : PCE_IGMP_DRPM
  //This register is used to configure the IGMP port map.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_DRPM	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45A)))

  //Register : PCE_IGMP_AGE_0
  //This register is used to configure the IGMP group aging time.
  //The aging time is calculated from PCE_IGMP_AGE_0.EXP and PCE_IGMP_AGE_1.MANT according to the formula:
  //Aging Time = (MANT+1) x 2^(EXP+8+1) x 40 ns
  //For a default aging time of about 100 ms the values of MANT = 0x98 and EXP = 0x05 are selected.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_AGE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45B)))

  //Register : PCE_IGMP_AGE_1
  //This register is used to configure the IGMP snooped router port aging time.
  //This timer uses the programmed Group Aging time to increment. If the timer expires and no query or router advertisement messages are snooped on a port, the port is removed from the snooped router port map.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_AGE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45C)))

  //Register : PCE_IGMP_STAT
  //This register is used to indicate IGMP status information.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45D)))

  //Register : WOL_GLB_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function globally.
# define ADR_ETHSW_PCE_PDI_WOL_GLB_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45E)))

  //Register : WOL_DA_0
  //This register provides the lower two byte of the WoL MAC destination address.
# define ADR_ETHSW_PCE_PDI_WOL_DA_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45F)))

  //Register : WOL_DA_1
  //This register provides the medium two byte of the WoL MAC destination address.
# define ADR_ETHSW_PCE_PDI_WOL_DA_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x460)))

  //Register : WOL_DA_2
  //This register provides the higher two byte of the WoL MAC destination address.
# define ADR_ETHSW_PCE_PDI_WOL_DA_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x461)))

  //Register : WOL_PW_0
  //This register provides the lower two byte of the WoL password.
# define ADR_ETHSW_PCE_PDI_WOL_PW_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x462)))

  //Register : WOL_PW_1
  //This register provides the medium two byte of the WoL password.
# define ADR_ETHSW_PCE_PDI_WOL_PW_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x463)))

  //Register : WOL_PW_2
  //This register provides the higher two byte of the WoL password.
# define ADR_ETHSW_PCE_PDI_WOL_PW_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x464)))

  //Register : PCE_IER_0
  //This register is used to enable or disable global PCE interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PDI_PCE_IER_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x465)))

  //Register : PCE_IER_1
  //This register is used to enable or disable global PCE interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PDI_PCE_IER_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x466)))

  //Register : PCE_ISR_0
  //This register provides interrupt status summary of all port-related PCE interrupts (see the PCE_PISR_n registers).
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
  //There is no global PCE interrupt enable register, this is covered by the port-related interrupt enable registers (see PCE_PIEN_n).
# define ADR_ETHSW_PCE_PDI_PCE_ISR_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x467)))

  //Register : PCE_ISR_1
  //This register provides interrupt status summary of all port-related PCE interrupts (see the PCE_PISR_n registers).
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
  //There is no global PCE interrupt enable register, this is covered by the port-related interrupt enable registers (see PCE_PIEN_n).
# define ADR_ETHSW_PCE_PDI_PCE_ISR_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x468)))

  //Register : PARSER_STAT
  //This register provides information of the parser's status which can be used for debugging.
# define ADR_ETHSW_PCE_PDI_PARSER_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x469)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x480)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x481)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x482)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x483)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_0_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x484)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x485)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x486)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x487)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x488)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x489)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48A)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48B)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48C)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48D)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_1_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48E)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48F)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x490)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x491)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x492)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x493)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x494)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x495)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x496)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x497)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_2_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x498)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x499)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49A)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49B)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49C)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49D)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49E)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49F)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A0)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A1)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_3_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A2)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A3)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A4)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A5)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A6)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A7)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A8)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A9)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AA)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AB)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_4_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AC)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AD)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AE)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AF)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B0)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B1)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B2)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B3)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B4)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B5)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_5_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B6)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B7)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B8)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B9)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BA)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BB)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BC)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BD)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BE)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BF)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_6_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C0)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C1)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C2)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C3)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C4)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C5)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C6)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C7)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C8)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C9)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_7_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CA)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CB)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CC)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CD)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CE)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CF)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D0)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D1)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D2)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D3)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_8_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D4)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D5)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D6)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D7)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D8)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D9)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DA)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DB)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DC)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DD)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_9_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DE)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DF)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E0)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E1)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E2)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E3)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E4)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E5)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E6)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E7)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_10_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E8)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E9)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EA)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EB)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EC)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4ED)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EE)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EF)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F0)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F1)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_11_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F2)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F3)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F4)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F5)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F6)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F7)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x580)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x581)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x582)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x583)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x584)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x585)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x586)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x587)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x588)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x589)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58A)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58B)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58C)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58D)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58E)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58F)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x590)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x591)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x592)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x593)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x594)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x595)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x596)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x597)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x598)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x599)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59A)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59B)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59C)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59D)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59E)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59F)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A0)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A1)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A2)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A3)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A4)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A5)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A6)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A7)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A8)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A9)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AA)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AB)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AC)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AD)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AE)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AF)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B0)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B1)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B2)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B3)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B4)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B5)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B6)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B7)))

  //Register : MAC_TEST
  //This register is used to select test functions.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_TEST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C0)))

  //Register : MAC_PFAD_CFG
  //This register is used to configure if a common MAC source address is used for transmitted Pause frames on all Ethernet ports or if individual addresses are used.
  //The MAC source address is defined by registers MAC_PFSA_0, MAC_PFSA_1, and MAC_PFSA_2.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFAD_CFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C1)))

  //Register : MAC_PFSA_0
  //This register is used to configure the Pause frame source address.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFSA_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C2)))

  //Register : MAC_PFSA_1
  //This register is used to configure the Pause frame source address.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFSA_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C3)))

  //Register : MAC_PFSA_2
  //This register is used to configure the Pause frame source address.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFSA_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C4)))

  //Register : MAC_FLEN
  //This register is used to configure the maximum frame length for Jumbo frames.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_FLEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C5)))

  //Register : MAC_VLAN_ETYPE_0
  //This register is used to configure the Ethertype to detect an outer VLAN tag.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_VLAN_ETYPE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C6)))

  //Register : MAC_VLAN_ETYPE_1
  //This register is used to configure the Ethertype to detect an inner VLAN tag.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_VLAN_ETYPE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C7)))

  //Register : MAC_IER
  //This register is used to enable or disable all MAC interrupts per port.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C8)))

  //Register : MAC_ISR
  //This register collects the interrupt status information that is provided per port.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C9)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_0_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x900)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_0_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x901)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_0_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x902)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x903)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x904)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x905)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x906)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x907)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x908)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x909)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_0_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90A)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_0_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90B)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_1_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90C)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_1_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90D)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_1_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90E)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90F)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x910)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x911)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x912)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x913)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x914)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x915)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_1_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x916)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_1_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x917)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_2_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x918)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_2_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x919)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_2_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91A)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91B)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91C)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91D)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91E)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91F)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x920)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x921)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_2_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x922)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_2_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x923)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_3_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x924)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_3_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x925)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_3_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x926)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x927)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x928)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x929)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92A)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92B)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92C)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92D)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_3_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92E)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_3_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92F)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_4_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x930)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_4_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x931)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_4_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x932)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x933)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x934)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x935)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x936)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x937)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x938)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x939)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_4_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93A)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_4_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93B)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_5_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93C)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_5_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93D)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_5_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93E)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93F)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x940)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x941)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x942)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x943)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x944)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x945)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_5_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x946)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_5_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x947)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_6_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x948)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_6_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x949)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_6_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94A)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94B)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94C)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94D)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94E)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94F)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x950)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x951)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_6_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x952)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_6_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x953)))

  //Register : FDMA_CTRL
  //This register controls global functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PDI_FDMA_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA40)))

  //Register : FDMA_STETYPE
  //This register defines the Ethertype value to be used for egress frames that shall carry the special tag.
# define ADR_ETHSW_FDMA_PDI_FDMA_STETYPE	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA41)))

  //Register : FDMA_VTETYPE
  //This register defines the Ethertype value to be used for egress frames that shall carry a VLAN tag.
# define ADR_ETHSW_FDMA_PDI_FDMA_VTETYPE	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA42)))

  //Register : FDMA_STAT_0
  //This register displays status information of the Fetch DMA.
# define ADR_ETHSW_FDMA_PDI_FDMA_STAT_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA43)))

  //Register : FDMA_IER
  //This register is used to enable or disable global FDMA interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_FDMA_PDI_FDMA_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA44)))

  //Register : FDMA_ISR
  //This register provides interrupt status summary of all port-related FDMA interrupts (see the FDMA_PISR_n registers).
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
# define ADR_ETHSW_FDMA_PDI_FDMA_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA45)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA80)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA81)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA82)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA83)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA84)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA85)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA86)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA87)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA88)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA89)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8A)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8B)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8C)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8D)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8E)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8F)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA90)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA91)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA92)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA93)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA94)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA95)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA96)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA97)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA98)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA99)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9A)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9B)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9C)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9D)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9E)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9F)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA0)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA1)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA2)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA3)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA4)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA5)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA6)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA7)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA8)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA9)))

  //Register : SDMA_CTRL
  //This register controls global functions of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB40)))

  //Register : SDMA_FCTHR1
  //This register indicates the value of THR1, used to stop the back-pressure (flow control) .
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 1 standard MTU for 7 ports is available before the flow control generated again.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB41)))

  //Register : SDMA_FCTHR2
  //This register indicates the value of THR2, used to start the back-pressure (flow control) for non-conforming ports.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 2 standard MTUs for 7 ports are available for the flow control latency.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB42)))

  //Register : SDMA_FCTHR3
  //This register indicates the value of THR3, used to start the back-pressure (flow control) for all ports that use this threshold.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 2 standard MTUs for 7 ports are available for the flow control latency.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB43)))

  //Register : SDMA_FCTHR4
  //This register indicates the value of THR4, used to start the back-pressure (flow control) for all ports that use this threshold.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 2 standard MTUs for 7 ports are available for the flow control latency.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB44)))

  //Register : SDMA_FCTHR5
  //This register indicates the value of THR5, used to control the tail drop function if the frame buffer is full.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting assumes tail-drop when buffer is full.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB45)))

  //Register : SDMA_FCTHR6
  //This register indicates the value of THR6, used to control the tail drop function if the frame buffer is full.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting assumes tail-drop when buffer is full.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB46)))

  //Register : SDMA_FCTHR7
  //This register indicates the value of THR7, used to control the tail drop function if the number of available pointers (packet descriptors) is less than this threshold.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting assumes tail-drop when buffer is full.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB47)))

  //Register : SDMA_STAT_0
  //This register displays status information of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_STAT_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB48)))

  //Register : SDMA_STAT_1
  //This register displays status information of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_STAT_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB49)))

  //Register : SDMA_STAT_2
  //This register displays status information of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_STAT_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB4A)))

  //Register : SDMA_IER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_SDMA_PDI_SDMA_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB4B)))

  //Register : SDMA_ISR
  //This register indicates interrupts caused by the Store DMA.
  //An interrupt status bit is cleared by writing a 1 to the related bit position, multiple bits can be cleared by a single write access.
# define ADR_ETHSW_SDMA_PDI_SDMA_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB4C)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC0)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC1)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC2)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC3)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC4)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC5)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC6)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC7)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC8)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC9)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCA)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCB)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCC)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCD)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCE)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCF)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD0)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD1)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD2)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD3)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD4)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD5)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD6)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD7)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD8)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD9)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDA)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDB)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDC)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDD)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDE)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDF)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE0)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE1)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE2)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE3)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE4)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE5)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE6)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE7)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE8)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE9)))

#endif //AR10_H 
