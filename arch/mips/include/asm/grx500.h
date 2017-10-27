#ifndef GRX500_H
#define GRX500_H

#define GRX500_PLATFORM            "GRX500"
#define KSEG1 0xa0000000

/***********************************************************************/
/*  Module      :  CGU register address and bits                       */
/***********************************************************************/
#define CGU_BASE (KSEG1+0x16200000)
#define CGU_PLL0A_CFG0  (CGU_BASE + 0x0004)
#define CGU_PLL0A_CFG1  (CGU_BASE + 0x0008)
#define CGU_PLL0B_CFG0  (CGU_BASE + 0x0034)
#define CGU_PLL0B_CFG1  (CGU_BASE + 0x0038)

#define CGU_CLKGSR0     (CGU_BASE + 0x114)
#define CGU_CLKGCR0_A   (CGU_BASE + 0x118)
#define CGU_CLKGCR0_B   (CGU_BASE + 0x11C)
#define CGU_CLKGSR1     (CGU_BASE + 0x120)
#define CGU_CLKGCR1_A   (CGU_BASE + 0x124)
#define CGU_CLKGCR1_B   (CGU_BASE + 0x128)
#define CGU_CLKGSR2     (CGU_BASE + 0x130)
#define CGU_CLKGCR2_A   (CGU_BASE + 0x134) 
#define CGU_CLKGCR2_B   (CGU_BASE + 0x138) 

#define BSP_CLKGCR1_A   ((volatile u32*)CGU_CLKGCR1_A)

#define CGU_CLKGCR1_A_SPI0_MASK      0x100

/***********************************************************************/
/*  Module      :  Reset Registers		                       */
/***********************************************************************/
#define RESET_BASE_REG	(0xB6000000)
#define RESET_REQ	(volatile u32*)(RESET_BASE_REG + 0x10)
#define RESET_STAT	(volatile u32*)(RESET_BASE_REG + 0x14)
#define RESET_STAT2	(volatile u32*)(RESET_BASE_REG + 0x24)
#define RESET_REQ2	(volatile u32*)(RESET_BASE_REG + 0x48)

/***********************************************************************/
/*  Module      :  GPTC1 register address and bits                       */
/***********************************************************************/
#define GPTC1_BASE_REGISTER				(KSEG1 + 0x16300000)
#define GPT1_CLC						(GPTC1_BASE_REGISTER + 0x0)
#define GPT1_ID 						(GPTC1_BASE_REGISTER + 0x8)
#define GPT1_CON_1_A					(GPTC1_BASE_REGISTER + 0x10)
#define GPT1_CON_1_B					(GPTC1_BASE_REGISTER + 0x14)
#define GPT1_RUN_1_A					(GPTC1_BASE_REGISTER + 0x18)
#define GPT1_RUN_1_B					(GPTC1_BASE_REGISTER + 0x1C)
#define GPT1_RELOAD_1_A					(GPTC1_BASE_REGISTER + 0x20)
#define GPT1_RELOAD_1_B					(GPTC1_BASE_REGISTER + 0x24)
#define GPT1_COUNT_1_A					(GPTC1_BASE_REGISTER + 0x28)
#define GPT1_COUNT_1_B					(GPTC1_BASE_REGISTER + 0x2C)
#define GPT1_CON_2_A					(GPTC1_BASE_REGISTER + 0x30)
#define GPT1_CON_2_B					(GPTC1_BASE_REGISTER + 0x34)
#define GPT1_RUN_2_A					(GPTC1_BASE_REGISTER + 0x38)
#define GPT1_RUN_2_B					(GPTC1_BASE_REGISTER + 0x3C)
#define GPT1_RELOAD_2_A					(GPTC1_BASE_REGISTER + 0x40)
#define GPT1_RELOAD_2_B					(GPTC1_BASE_REGISTER + 0x44)
#define GPT1_COUNT_2_A					(GPTC1_BASE_REGISTER + 0x48)
#define GPT1_COUNT_2_B					(GPTC1_BASE_REGISTER + 0x4C)

/***********************************************************************/
/*  Module      :  GPTC2 register address and bits                       */
/***********************************************************************/
#define GPTC2_BASE_REGISTER			(KSEG1 + 0x16400000)
#define GPT2_CLC						(GPTC2_BASE_REGISTER + 0x0)
#define GPT2_ID 						(GPTC2_BASE_REGISTER + 0x8)
#define GPT2_CON_1_A					(GPTC2_BASE_REGISTER + 0x10)
#define GPT2_CON_1_B					(GPTC2_BASE_REGISTER + 0x14)
#define GPT2_RUN_1_A					(GPTC2_BASE_REGISTER + 0x18)
#define GPT2_RUN_1_B					(GPTC2_BASE_REGISTER + 0x1C)
#define GPT2_RELOAD_1_A					(GPTC2_BASE_REGISTER + 0x20)
#define GPT2_RELOAD_1_B					(GPTC2_BASE_REGISTER + 0x24)
#define GPT2_COUNT_1_A					(GPTC2_BASE_REGISTER + 0x28)
#define GPT2_COUNT_1_B					(GPTC2_BASE_REGISTER + 0x2C)
#define GPT2_CON_2_A					(GPTC2_BASE_REGISTER + 0x30)
#define GPT2_CON_2_B					(GPTC2_BASE_REGISTER + 0x34)
#define GPT2_RUN_2_A					(GPTC2_BASE_REGISTER + 0x38)
#define GPT2_RUN_2_B					(GPTC2_BASE_REGISTER + 0x3C)
#define GPT2_RELOAD_2_A					(GPTC2_BASE_REGISTER + 0x40)
#define GPT2_RELOAD_2_B					(GPTC2_BASE_REGISTER + 0x44)
#define GPT2_COUNT_2_A					(GPTC2_BASE_REGISTER + 0x48)
#define GPT2_COUNT_2_B					(GPTC2_BASE_REGISTER + 0x4C)

/***********************************************************************/
/*  Module      :  GPTC3 register address and bits                       */
/***********************************************************************/
#define GPTC3_BASE_REGISTER			(KSEG1 + 0x16B00000)
#define GPT3_CLC						(GPTC3_BASE_REGISTER + 0x0)
#define GPT3_ID 						(GPTC3_BASE_REGISTER + 0x8)
#define GPT3_CON_1_A					(GPTC3_BASE_REGISTER + 0x10)
#define GPT3_CON_1_B					(GPTC3_BASE_REGISTER + 0x14)
#define GPT3_RUN_1_A					(GPTC3_BASE_REGISTER + 0x18)
#define GPT3_RUN_1_B					(GPTC3_BASE_REGISTER + 0x1C)
#define GPT3_RELOAD_1_A					(GPTC3_BASE_REGISTER + 0x20)
#define GPT3_RELOAD_1_B					(GPTC3_BASE_REGISTER + 0x24)
#define GPT3_COUNT_1_A					(GPTC3_BASE_REGISTER + 0x28)
#define GPT3_COUNT_1_B					(GPTC3_BASE_REGISTER + 0x2C)
#define GPT3_CON_2_A					(GPTC3_BASE_REGISTER + 0x30)
#define GPT3_CON_2_B					(GPTC3_BASE_REGISTER + 0x34)
#define GPT3_RUN_2_A					(GPTC3_BASE_REGISTER + 0x38)
#define GPT3_RUN_2_B					(GPTC3_BASE_REGISTER + 0x3C)
#define GPT3_RELOAD_2_A					(GPTC3_BASE_REGISTER + 0x40)
#define GPT3_RELOAD_2_B					(GPTC3_BASE_REGISTER + 0x44)
#define GPT3_COUNT_2_A					(GPTC3_BASE_REGISTER + 0x48)
#define GPT3_COUNT_2_B					(GPTC3_BASE_REGISTER + 0x4C)

/***********************************************************************/
/*  Module      :  LEDC register address and bits                       */
/***********************************************************************/
#define LED_BASE_REGISTER				(KSEG1 + 0x16D00000)
#define LED_BLINK_H8_0					(LED_BASE_REGISTER + 0x0)
#define LED_BLINK_H8_1					(LED_BASE_REGISTER + 0x4)
#define DUTY_CYCLE_0					(LED_BASE_REGISTER + 0x8)
#define DUTY_CYCLE_1					(LED_BASE_REGISTER + 0xC)
#define DUTY_CYCLE_2					(LED_BASE_REGISTER + 0x10)
#define DUTY_CYCLE_3					(LED_BASE_REGISTER + 0x14)
#define DUTY_CYCLE_4					(LED_BASE_REGISTER + 0x18)
#define DUTY_CYCLE_5					(LED_BASE_REGISTER + 0x1C)
#define DUTY_CYCLE_6					(LED_BASE_REGISTER + 0x20)
#define DUTY_CYCLE_7					(LED_BASE_REGISTER + 0x24)
#define DUTY_CYCLE_8					(LED_BASE_REGISTER + 0x28)
#define DUTY_CYCLE_9					(LED_BASE_REGISTER + 0x2C)
#define DUTY_CYCLE_10					(LED_BASE_REGISTER + 0x30)
#define DUTY_CYCLE_11					(LED_BASE_REGISTER + 0x34)
#define DUTY_CYCLE_12					(LED_BASE_REGISTER + 0x38)
#define DUTY_CYCLE_13					(LED_BASE_REGISTER + 0x3C)
#define DUTY_CYCLE_14					(LED_BASE_REGISTER + 0x40)
#define DUTY_CYCLE_15					(LED_BASE_REGISTER + 0x44)
#define DUTY_CYCLE_16					(LED_BASE_REGISTER + 0x48)
#define DUTY_CYCLE_17					(LED_BASE_REGISTER + 0x4C)
#define DUTY_CYCLE_18					(LED_BASE_REGISTER + 0x50)
#define DUTY_CYCLE_19					(LED_BASE_REGISTER + 0x54)
#define DUTY_CYCLE_20					(LED_BASE_REGISTER + 0x58)
#define DUTY_CYCLE_21					(LED_BASE_REGISTER + 0x5C)
#define DUTY_CYCLE_22					(LED_BASE_REGISTER + 0x60)
#define DUTY_CYCLE_23					(LED_BASE_REGISTER + 0x64)
#define DUTY_CYCLE_24					(LED_BASE_REGISTER + 0x68)
#define DUTY_CYCLE_25					(LED_BASE_REGISTER + 0x6C)
#define DUTY_CYCLE_26					(LED_BASE_REGISTER + 0x70)
#define DUTY_CYCLE_27					(LED_BASE_REGISTER + 0x74)
#define DUTY_CYCLE_28					(LED_BASE_REGISTER + 0x78)
#define DUTY_CYCLE_29					(LED_BASE_REGISTER + 0x7C)
#define DUTY_CYCLE_30					(LED_BASE_REGISTER + 0x80)
#define DUTY_CYCLE_31					(LED_BASE_REGISTER + 0x84)
#define SSO_CON0						(LED_BASE_REGISTER + 0x2B0)
#define SSO_CON1						(LED_BASE_REGISTER + 0x2B4)
#define SSO_CPU0						(LED_BASE_REGISTER + 0x2B8)
#define SSO_CPU1						(LED_BASE_REGISTER + 0x2BC)
#define SSO_AR							(LED_BASE_REGISTER + 0x2C0)
#define SSO_CON2						(LED_BASE_REGISTER + 0x2C4)
#define SSO_CON3						(LED_BASE_REGISTER + 0x2C8)

/***********************************************************************/
/*  Module      :  GPIO register address and bits                       */
/***********************************************************************/
#define GPIO_FUNCTION_BASE           (KSEG1 + 0x16C00000)
#define GPIO_FUNCTION_OUT_0          (GPIO_FUNCTION_BASE + 0x0  )   
#define GPIO_FUNCTION_IN_0           (GPIO_FUNCTION_BASE + 0x4  )
#define GPIO_FUNCTION_DIR_0          (GPIO_FUNCTION_BASE + 0x8  )
#define GPIO_FUNCTION_EXINTCR00      (GPIO_FUNCTION_BASE + 0x18 )
#define GPIO_FUNCTION_EXINTCR01      (GPIO_FUNCTION_BASE + 0x1C )
#define GPIO_FUNCTION_IRNCR_0        (GPIO_FUNCTION_BASE + 0x20 )
#define GPIO_FUNCTION_IRNICR_0       (GPIO_FUNCTION_BASE + 0x24 )
#define GPIO_FUNCTION_IRNEN_0        (GPIO_FUNCTION_BASE + 0x28 )
#define GPIO_FUNCTION_IRNCFG_0       (GPIO_FUNCTION_BASE + 0x2C )
#define GPIO_FUNCTION_IRNENSET_0     (GPIO_FUNCTION_BASE + 0x30 )
#define GPIO_FUNCTION_IRNENCLR_0     (GPIO_FUNCTION_BASE + 0x34 )
#define GPIO_FUNCTION_OUTSET_0       (GPIO_FUNCTION_BASE + 0x40 )
#define GPIO_FUNCTION_OUTCLR_0       (GPIO_FUNCTION_BASE + 0x44 )
#define GPIO_FUNCTION_DIRSET_0       (GPIO_FUNCTION_BASE + 0x48 )
#define GPIO_FUNCTION_DIRCLR_0       (GPIO_FUNCTION_BASE + 0x4C )
#define GPIO_FUNCTION_OUT_1          (GPIO_FUNCTION_BASE + 0x100)
#define GPIO_FUNCTION_IN_1           (GPIO_FUNCTION_BASE + 0x104)
#define GPIO_FUNCTION_DIR_1          (GPIO_FUNCTION_BASE + 0x108)
#define GPIO_FUNCTION_EXINTCR10      (GPIO_FUNCTION_BASE + 0x118)
#define GPIO_FUNCTION_EXINTCR11      (GPIO_FUNCTION_BASE + 0x11C)                  
#define GPIO_FUNCTION_IRNCR_1        (GPIO_FUNCTION_BASE + 0x120)
#define GPIO_FUNCTION_IRNICR_1       (GPIO_FUNCTION_BASE + 0x124)
#define GPIO_FUNCTION_IRNEN_1        (GPIO_FUNCTION_BASE + 0x128)
#define GPIO_FUNCTION_IRNCFG_1       (GPIO_FUNCTION_BASE + 0x12C)
#define GPIO_FUNCTION_IRNENSET_1     (GPIO_FUNCTION_BASE + 0x130)
#define GPIO_FUNCTION_IRNENCLR_1     (GPIO_FUNCTION_BASE + 0x134)
#define GPIO_FUNCTION_OUTSET_1       (GPIO_FUNCTION_BASE + 0x140)
#define GPIO_FUNCTION_OUTCLR_1       (GPIO_FUNCTION_BASE + 0x144)
#define GPIO_FUNCTION_DIRSET_1       (GPIO_FUNCTION_BASE + 0x148)
#define GPIO_FUNCTION_DIRCLR_1       (GPIO_FUNCTION_BASE + 0x14C)



#define GPIO_PAD_CTRL_BASE (KSEG1 + 0x16C80000)
#define GPIO_PAD_CTRL_PORTMUXC0      (GPIO_PAD_CTRL_BASE + 0x0)   
#define GPIO_PAD_CTRL_PORTMUXC1      (GPIO_PAD_CTRL_BASE + 0x04)  
#define GPIO_PAD_CTRL_PORTMUXC2      (GPIO_PAD_CTRL_BASE + 0x08)  
#define GPIO_PAD_CTRL_PORTMUXC3      (GPIO_PAD_CTRL_BASE + 0x0C)  
#define GPIO_PAD_CTRL_PORTMUXC4      (GPIO_PAD_CTRL_BASE + 0x10) 
#define GPIO_PAD_CTRL_PORTMUXC5      (GPIO_PAD_CTRL_BASE + 0x14) 
#define GPIO_PAD_CTRL_PORTMUXC6      (GPIO_PAD_CTRL_BASE + 0x18) 
#define GPIO_PAD_CTRL_PORTMUXC7      (GPIO_PAD_CTRL_BASE + 0x1C) 
#define GPIO_PAD_CTRL_PORTMUXC8      (GPIO_PAD_CTRL_BASE + 0x20) 
#define GPIO_PAD_CTRL_PORTMUXC9      (GPIO_PAD_CTRL_BASE + 0x24) 
#define GPIO_PAD_CTRL_PORTMUXC10     (GPIO_PAD_CTRL_BASE + 0x28) 
#define GPIO_PAD_CTRL_PORTMUXC11     (GPIO_PAD_CTRL_BASE + 0x2C) 
#define GPIO_PAD_CTRL_PORTMUXC12     (GPIO_PAD_CTRL_BASE + 0x30) 
#define GPIO_PAD_CTRL_PORTMUXC13     (GPIO_PAD_CTRL_BASE + 0x34) 
#define GPIO_PAD_CTRL_PORTMUXC14     (GPIO_PAD_CTRL_BASE + 0x38) 
#define GPIO_PAD_CTRL_PORTMUXC15     (GPIO_PAD_CTRL_BASE + 0x3C) 
#define GPIO_PAD_CTRL_PORTMUXC16     (GPIO_PAD_CTRL_BASE + 0x40) 
#define GPIO_PAD_CTRL_PORTMUXC17     (GPIO_PAD_CTRL_BASE + 0x44) 
#define GPIO_PAD_CTRL_PORTMUXC18     (GPIO_PAD_CTRL_BASE + 0x48) 
#define GPIO_PAD_CTRL_PORTMUXC19     (GPIO_PAD_CTRL_BASE + 0x4C) 
#define GPIO_PAD_CTRL_PORTMUXC20     (GPIO_PAD_CTRL_BASE + 0x50) 
#define GPIO_PAD_CTRL_PORTMUXC21     (GPIO_PAD_CTRL_BASE + 0x54) 
#define GPIO_PAD_CTRL_PORTMUXC22     (GPIO_PAD_CTRL_BASE + 0x58) 
#define GPIO_PAD_CTRL_PORTMUXC23     (GPIO_PAD_CTRL_BASE + 0x5C) 
#define GPIO_PAD_CTRL_PORTMUXC24     (GPIO_PAD_CTRL_BASE + 0x60) 
#define GPIO_PAD_CTRL_PORTMUXC25     (GPIO_PAD_CTRL_BASE + 0x64) 
#define GPIO_PAD_CTRL_PORTMUXC26     (GPIO_PAD_CTRL_BASE + 0x68) 
#define GPIO_PAD_CTRL_PORTMUXC27     (GPIO_PAD_CTRL_BASE + 0x6C) 
#define GPIO_PAD_CTRL_PORTMUXC28     (GPIO_PAD_CTRL_BASE + 0x70) 
#define GPIO_PAD_CTRL_PORTMUXC29     (GPIO_PAD_CTRL_BASE + 0x74) 
#define GPIO_PAD_CTRL_PORTMUXC30     (GPIO_PAD_CTRL_BASE + 0x78) 
#define GPIO_PAD_CTRL_PORTMUXC31     (GPIO_PAD_CTRL_BASE + 0x7C) 
#define GPIO_PAD_CTRL_PUEN_0         (GPIO_PAD_CTRL_BASE + 0x80) 
#define GPIO_PAD_CTRL_PDEN_0         (GPIO_PAD_CTRL_BASE + 0x84) 
#define GPIO_PAD_CTRL_SRC_0          (GPIO_PAD_CTRL_BASE + 0x88) 
#define GPIO_PAD_CTRL_DCC_0          (GPIO_PAD_CTRL_BASE + 0x8C) 
#define GPIO_PAD_CTRL_DCC_1          (GPIO_PAD_CTRL_BASE + 0x90) 
#define GPIO_PAD_CTRL_OD_0           (GPIO_PAD_CTRL_BASE + 0x94 ) 
#define GPIO_PAD_CTRL_AVAIL_0        (GPIO_PAD_CTRL_BASE + 0x98 )
#define GPIO_PAD_CTRL_PORTMUXC32     (GPIO_PAD_CTRL_BASE + 0x100)
#define GPIO_PAD_CTRL_PORTMUXC33     (GPIO_PAD_CTRL_BASE + 0x104)
#define GPIO_PAD_CTRL_PORTMUXC34     (GPIO_PAD_CTRL_BASE + 0x108)
#define GPIO_PAD_CTRL_PORTMUXC35     (GPIO_PAD_CTRL_BASE + 0x10C)
#define GPIO_PAD_CTRL_PORTMUXC36     (GPIO_PAD_CTRL_BASE + 0x110)
#define GPIO_PAD_CTRL_PORTMUXC37     (GPIO_PAD_CTRL_BASE + 0x114)
#define GPIO_PAD_CTRL_PORTMUXC38     (GPIO_PAD_CTRL_BASE + 0x118)
#define GPIO_PAD_CTRL_PORTMUXC39     (GPIO_PAD_CTRL_BASE + 0x11C)
#define GPIO_PAD_CTRL_PORTMUXC40     (GPIO_PAD_CTRL_BASE + 0x120)
#define GPIO_PAD_CTRL_PORTMUXC41     (GPIO_PAD_CTRL_BASE + 0x124)
#define GPIO_PAD_CTRL_PORTMUXC42     (GPIO_PAD_CTRL_BASE + 0x128)
#define GPIO_PAD_CTRL_PORTMUXC43     (GPIO_PAD_CTRL_BASE + 0x12C)
#define GPIO_PAD_CTRL_PORTMUXC44     (GPIO_PAD_CTRL_BASE + 0x130)
#define GPIO_PAD_CTRL_PORTMUXC45     (GPIO_PAD_CTRL_BASE + 0x134)
#define GPIO_PAD_CTRL_PORTMUXC46     (GPIO_PAD_CTRL_BASE + 0x138)
#define GPIO_PAD_CTRL_PORTMUXC47     (GPIO_PAD_CTRL_BASE + 0x13C)
#define GPIO_PAD_CTRL_PORTMUXC48     (GPIO_PAD_CTRL_BASE + 0x140)
#define GPIO_PAD_CTRL_PORTMUXC49     (GPIO_PAD_CTRL_BASE + 0x144)
#define GPIO_PAD_CTRL_PORTMUXC50     (GPIO_PAD_CTRL_BASE + 0x148)
#define GPIO_PAD_CTRL_PORTMUXC51     (GPIO_PAD_CTRL_BASE + 0x14C)
#define GPIO_PAD_CTRL_PORTMUXC52     (GPIO_PAD_CTRL_BASE + 0x150)
#define GPIO_PAD_CTRL_PORTMUXC53     (GPIO_PAD_CTRL_BASE + 0x154)
#define GPIO_PAD_CTRL_PORTMUXC54     (GPIO_PAD_CTRL_BASE + 0x158)
#define GPIO_PAD_CTRL_PORTMUXC55     (GPIO_PAD_CTRL_BASE + 0x15C)
#define GPIO_PAD_CTRL_PORTMUXC56     (GPIO_PAD_CTRL_BASE + 0x160)
#define GPIO_PAD_CTRL_PORTMUXC57     (GPIO_PAD_CTRL_BASE + 0x164)
#define GPIO_PAD_CTRL_PORTMUXC58     (GPIO_PAD_CTRL_BASE + 0x168)
#define GPIO_PAD_CTRL_PORTMUXC59     (GPIO_PAD_CTRL_BASE + 0x16C)
#define GPIO_PAD_CTRL_PORTMUXC60     (GPIO_PAD_CTRL_BASE + 0x170)
#define GPIO_PAD_CTRL_PORTMUXC61     (GPIO_PAD_CTRL_BASE + 0x174)
#define GPIO_PAD_CTRL_PUEN_1         (GPIO_PAD_CTRL_BASE + 0x180)
#define GPIO_PAD_CTRL_PDEN_1         (GPIO_PAD_CTRL_BASE + 0x184)
#define GPIO_PAD_CTRL_SRC_1          (GPIO_PAD_CTRL_BASE + 0x188)
#define GPIO_PAD_CTRL_DCC_2          (GPIO_PAD_CTRL_BASE + 0x18C)
#define GPIO_PAD_CTRL_DCC_3          (GPIO_PAD_CTRL_BASE + 0x190)
#define GPIO_PAD_CTRL_OD_1           (GPIO_PAD_CTRL_BASE + 0x194)
#define GPIO_PAD_CTRL_AVAIL_1        (GPIO_PAD_CTRL_BASE + 0x198)

/***********************************************************************/
/*  Module      :  DMA0 register address and bits                       */
/***********************************************************************/

//! Base Address of DMA0
#define DMA0_MODULE_BASE		(KSEG1+0x16E00000)

/***********************************************************************/
/*  Module      :  DMA1TX register address and bits                     */
/***********************************************************************/
//! Base Address of DMA1_TX
#define DMA1_TX_MODULE_BASE 		(KSEG1+0x1A100000)

/***********************************************************************/
/*  Module      :  DMA2TX register address and bits                     */
/***********************************************************************/
//! Base Address of DMA1_RX
#define DMA1_RX_MODULE_BASE 		(KSEG1+0x1A200000)

/***********************************************************************/
/*  Module      :  DMA2TX register address and bits                     */
/***********************************************************************/
//! Base Address of DMA2_TX
#define DMA2_TX_MODULE_BASE 		(KSEG1+0x1C100000)

/***********************************************************************/
/*  Module      :  DMA2RX register address and bits                     */
/***********************************************************************/
//! Base Address of DMA2_RX
#define DMA2_RX_MODULE_BASE 		(KSEG1+0x1C200000)

/***********************************************************************/
/*  Module      :  DMA register offset address and bits                */
/***********************************************************************/
#define DMA_CLC 			0x0
#define	DMA_ID				0x8
#define DMA_CTRL			0x10
#define	DMA_CPOLL 			0x14
#define DMA_CS 				0x18
#define DMA_CCTRL 			0x1C
#define DMA_CDBA 			0x20
#define DMA_CDLEN 			0x24
#define DMA_CIS 			0x28
#define DMA_CIE 			0x2C
#define DMA_CGBL 			0x30
#define DMA_CDPTNRD 		0x34
#define DMA_PS 				0x40
#define DMA_PCTRL 			0x44
#define DMA_CS1				0x50
#define DMA_CCTRL1 			0x54
#define DMA_CDBA1 			0x58
#define DMA_CDLEN1 			0x5C
#define DMA_CIS1 			0x60
#define DMA_CIE1 			0x64
#define DMA_PS1 			0x70
#define DMA_PCTRL1 			0x74
#define DMA_CPDCNT 			0x80
#define DMA_CPDCNT1 		0x84
#define DMA_CS2 			0x90
#define DMA_CCTRL2 			0x94
#define DMA_CDBA2 			0x98
#define DMA_CDLEN2 			0x9C
#define DMA_CIS2 			0xA0
#define DMA_CIE2 			0xA4
#define DMA_CDPTNRD2 		0xAC
#define DMA_PS2 			0xB0
#define DMA_PCTRL2			0xB4
#define DMA_CS3 			0xC0
#define DMA_CCTRL3 			0xC4
#define DMA_CDBA3 			0xC8
#define DMA_CDLEN3 			0xCC
#define DMA_CIS3 			0xD0
#define DMA_CIE3 			0xD4
#define DMA_CDPTNRD3 		0xDC
#define DMA_PS3 			0xE0
#define DMA_PCTRL3 			0xE4
#define DMA_IRNEN1 			0xE8
#define DMA_IRNCR1 			0xEC
#define DMA_IRNICR1 		0xF0
#define DMA_IRNEN 			0xF4
#define DMA_IRNCR 			0xF8
#define DMA_IRNICR 			0xFC

#define DMA_CTRL_RST_POS		0
#define DMA_PCTRL_GPC_POS		16
#define	DMA_PCTRL_TXWGT_POS		12
#define DMA_PCTRL_TXENDI_POS	10
#define DMA_PCTRL_RXENDI_POS	8
#define DMA_PCTRL_PDEN_POS		6
#define	DMA_PCTRL_TXBL_POS		4
#define DMA_PCTRL_RXBL_POS		2
#define DMA_CCTRL_DIR_POS		8
#define DMA_CCTRL_ON_OFF_POS	0
#define DMA_CCTRL_RST_POS		1
#define DMA_CCTRL_CLASS_MASK	0xE00
#define DMA_CCTRL_CLASSH_MASK	0xC0000
#define DMA_CPOLL_EN_POS		31
#define DMA_CPOLL_CNT_POS		4

#define DMA_CTRL_PKTARB_MASK 	0x80000000
#define DMA_CTRL_MBRSTARB_MASK 	0x40000000
#define DMA_CTRL_SK_CH_MASK 	0x40
#define DMA_CTRL_DS_FOD_MASK 	0x80
#define DMA_CTRL_DRB_MASK 		0x100
#define DMA_CTRL_ENBE_MASK 		0x200



/***********************************************************************/
/*  Module      :  EBU register address and bits                       */
/***********************************************************************/

#define EBU_BASE            (KSEG1+0x16F00000)

#define EBU_CLC             (volatile u32*)(EBU_BASE + 0x0  ) 
#define EBU_ID              (volatile u32*)(EBU_BASE + 0x8  ) 
#define EBU_CON             (volatile u32*)(EBU_BASE + 0x10 )
#define EBU_ADDR_SEL_0      (volatile u32*)(EBU_BASE + 0x20 ) 
#define EBU_ADDR_SEL_1      (volatile u32*)(EBU_BASE + 0x24 ) 
#define EBU_ADDR_SEL_2      (volatile u32*)(EBU_BASE + 0x28 )
#define EBU_ADDR_SEL_3      (volatile u32*)(EBU_BASE + 0x2C )
#define EBU_CON_0           (volatile u32*)(EBU_BASE + 0x60 ) 
#define EBU_CON_1           (volatile u32*)(EBU_BASE + 0x64 )
#define EBU_CON_2           (volatile u32*)(EBU_BASE + 0x68 ) 
#define EBU_CON_3           (volatile u32*)(EBU_BASE + 0x6C )
#define EBU_EMU_ADDR        (volatile u32*)(EBU_BASE + 0x80 )
#define EBU_EMU_CON         (volatile u32*)(EBU_BASE + 0x88 )
#define EBU_SYN_CON         (volatile u32*)(EBU_BASE + 0x8C )
#define EBU_ECC_ISTAT       (volatile u32*)(EBU_BASE + 0xA0 )
#define EBU_ECC_IEN         (volatile u32*)(EBU_BASE + 0xA4 )
#define EBU_ECC_INT_OUT     (volatile u32*)(EBU_BASE + 0xA8 ) 
#define EBU_NAND_CON        (volatile u32*)(EBU_BASE + 0xB0 ) 
#define EBU_NAND_WAIT       (volatile u32*)(EBU_BASE + 0xB4 )
#define EBU_NAND_ECC0       (volatile u32*)(EBU_BASE + 0xB8 ) 
#define EBU_NAND_ECC_AC     (volatile u32*)(EBU_BASE + 0xBC ) 
#define EBU_NAND_ECC_CR     (volatile u32*)(EBU_BASE + 0xC0 ) 
#define EBU_SYN_CON1        (volatile u32*)(EBU_BASE + 0xC4 ) 



/***********************************************************************/
/*  Module      :  DMA register address and bits                       */
/***********************************************************************/
#define BSP_DMA_OFFSET 0xB6e00000
/***********************************************************************/
#define BSP_DMA_CLC                   ((volatile u32*)(BSP_DMA_OFFSET + 0x0000))
#define BSP_DMA_ID                    ((volatile u32*)(BSP_DMA_OFFSET + 0x0008))
#define BSP_DMA_CTRL                  ((volatile u32*)(BSP_DMA_OFFSET + 0x0010))

#define BSP_DMA_PS                    ((volatile u32*)(BSP_DMA_OFFSET + 0x0040))
#define BSP_DMA_PCTRL                 ((volatile u32*)(BSP_DMA_OFFSET + 0x0044))
#define BSP_DMA_IRNEN                 ((volatile u32*)(BSP_DMA_OFFSET + 0x00F4))
#define BSP_DMA_IRNCR                 ((volatile u32*)(BSP_DMA_OFFSET + 0x00F8))
#define BSP_DMA_IRNICR                ((volatile u32*)(BSP_DMA_OFFSET + 0x00FC))

#define BSP_DMA_CS                    ((volatile u32*)(BSP_DMA_OFFSET + 0x0018))
#define BSP_DMA_CCTRL                 ((volatile u32*)(BSP_DMA_OFFSET + 0x001C))
#define BSP_DMA_CDBA                  ((volatile u32*)(BSP_DMA_OFFSET + 0x0020))
#define BSP_DMA_CGBL                  ((volatile u32*)(BSP_DMA_OFFSET + 0x0030))
#define BSP_DMA_CIE                   ((volatile u32*)(BSP_DMA_OFFSET + 0x002C))
#define BSP_DMA_CIS                   ((volatile u32*)(BSP_DMA_OFFSET + 0x0028))
#define BSP_DMA_CDLEN                 ((volatile u32*)(BSP_DMA_OFFSET + 0x0024))
#define BSP_DMA_CPOLL                 ((volatile u32*)(BSP_DMA_OFFSET + 0x0014))


/***********************************************************************/
/*  Module      :  HSNAND registers                                    */
/***********************************************************************/

#define HSNAND_BASE                       (0xB7000000)

#define BSP_NDAC_CTL1             ((volatile u32*)(HSNAND_BASE + 0x0110))
#define BSP_NDAC_CTL2             ((volatile u32*)(HSNAND_BASE + 0x0114))
#define BSP_INT_Msk_CTL           ((volatile u32*)(HSNAND_BASE + 0x0124))
#define BSP_INT_Sta               ((volatile u32*)(HSNAND_BASE + 0x0128))
#define BSP_MD_CTL                ((volatile u32*)(HSNAND_BASE + 0x0130))
#define BSP_ND_PARA0              ((volatile u32*)(HSNAND_BASE + 0x013C))
#define BSP_ND_ODD_ECC            ((volatile u32*)(HSNAND_BASE + 0x0140))
#define BSP_ND_ODD_ECC1           ((volatile u32*)(HSNAND_BASE + 0x0144))
#define BSP_ND_EVEN_ECC           ((volatile u32*)(HSNAND_BASE + 0x0148))
#define BSP_ND_EVEN_ECC1          ((volatile u32*)(HSNAND_BASE + 0x014C))
#define BSP_ND_CMSG_0             ((volatile u32*)(HSNAND_BASE + 0x0150))
#define BSP_ND_CMSG_1             ((volatile u32*)(HSNAND_BASE + 0x0154))

#define I2C_BASE_ADDR			(KSEG1+0x16A00000)
#define I2C_CLC					((volatile u32*)(I2C_BASE_ADDR + 0x0000))
#define I2C_ID					((volatile u32*)(I2C_BASE_ADDR + 0x0008))
#define I2C_RUN_CTRL			((volatile u32*)(I2C_BASE_ADDR + 0X0010))
#define I2C_ENDD_CTRL			((volatile u32*)(I2C_BASE_ADDR + 0x0014))
#define I2C_FDIV_CFG			((volatile u32*)(I2C_BASE_ADDR + 0x0018))
#define I2C_FDIV_HIGH_CFG		((volatile u32*)(I2C_BASE_ADDR + 0x001C))
#define I2C_ADDR_CFG			((volatile u32*)(I2C_BASE_ADDR + 0x0020))
#define I2C_BUS_STAT			((volatile u32*)(I2C_BASE_ADDR + 0x0024))
#define I2C_FIFO_CFG			((volatile u32*)(I2C_BASE_ADDR + 0x0028))
#define I2C_MRPS_CTRL			((volatile u32*)(I2C_BASE_ADDR + 0x002C))
#define I2C_RPS_STAT			((volatile u32*)(I2C_BASE_ADDR + 0x0030))
#define I2C_TPS_CTRL			((volatile u32*)(I2C_BASE_ADDR + 0x0034))
#define I2C_FFS_STAT			((volatile u32*)(I2C_BASE_ADDR + 0x0038))
#define I2C_TIM_CFG				((volatile u32*)(I2C_BASE_ADDR + 0x0040))
#define I2C_ERR_IRQSM 			((volatile u32*)(I2C_BASE_ADDR + 0x0060))
#define I2C_ERR_IRQSS			((volatile u32*)(I2C_BASE_ADDR + 0x0064))
#define I2C_ERR_IRQSC			((volatile u32*)(I2C_BASE_ADDR + 0x0068))
#define I2C_P_IRQSM				((volatile u32*)(I2C_BASE_ADDR + 0x0070))
#define I2C_P_IRQSS				((volatile u32*)(I2C_BASE_ADDR + 0x0074))
#define I2C_P_IRQSC				((volatile u32*)(I2C_BASE_ADDR + 0x0078))
#define I2C_RIS					((volatile u32*)(I2C_BASE_ADDR + 0x0080))
#define I2C_IMSC				((volatile u32*)(I2C_BASE_ADDR + 0x0084))
#define I2C_MIS 				((volatile u32*)(I2C_BASE_ADDR + 0x0088))
#define I2C_ICR					((volatile u32*)(I2C_BASE_ADDR + 0x008C))
#define I2C_ISR					((volatile u32*)(I2C_BASE_ADDR + 0x0090))
#define I2C_DMAE				((volatile u32*)(I2C_BASE_ADDR + 0x0094))
#define I2C_TXD					((volatile u32*)(I2C_BASE_ADDR + 0x8000))
#define I2C_RXD 				((volatile u32*)(I2C_BASE_ADDR + 0xC000))
                                                         

/***********************************************************************/
/*  Module      :  Switch register address and bits                     */
/***********************************************************************/
#define GSW_BASE_ADDR					(KSEG1+0x1C000000)
#define GSW_R_BASE_ADDR					(KSEG1+0x1A000000)
#define GSW_TOP_LVL_OFFSET     			(0x00003C00)

#define GSW_BM_PCFG(i)         			((0x080 + (0x2 * i)) * 4)

#define GSWIP_TOP_L_MODULE_BASE 		(KSEG1+0x1C003C00)
#define GSWIP_L_TOP_BASE_ADDR			GSWIP_TOP_L_MODULE_BASE
#define GSWIP_L_GLOB_CTRL        		((volatile u32*)(GSWIP_L_TOP_BASE_ADDR))
#define GSWIP_TOP_L_MDIO_CTRL			((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0010))
#define GSWIP_TOP_L_MDIO_READ			((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0014))
#define GSWIP_TOP_L_MDIO_WRITE			((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0018))
#define GSW_L_MDC_CFG_0					((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x001C))
#define GSW_L_MDC_CFG_1					((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0020))
#define GSWIP_L_MII_CFG1         		((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0024))
#define GSWIP_L_PHY_ADDR(i)    			((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0110 + (i-1)*0x10))
#define GSWIP_TOP_L_GPHY2_CFG(i)		((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0220 + (i-1)*0x10))
#define GSWIP_TOP_L_GPHY_BFDEV(i)		((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0224 + (i-1)*0x10))
#define GSWIP_TOP_L_GPHY_LBADR(i)		((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x0228 + (i-1)*0x10))
#define GSWIP_TOP_L_GPHY_MBADR(i)		((volatile u32*)(GSWIP_L_TOP_BASE_ADDR + 0x022C + (i-1)*0x10))

#define GSWIP_L_MODULE_BASE 			(KSEG1+0x1C000000)
#define GSW_L_BASE_ADDR					GSWIP_L_MODULE_BASE
#define GSWIP_L_MAC_CTRL(i)    			((volatile u32*)(GSWIP_L_MODULE_BASE + 0x243C + (i-1)*0x30))
#define GSWIP_L_BM_PCFG(i)     			((volatile u32*)(GSWIP_L_MODULE_BASE + 0x0200 + (i-1)*0x30))

#define GSWIP_TOP_R_MODULE_BASE 		(KSEG1+0x1A003C00)
#define GSWIP_TOP_R_MDC_CFG_0_R			((volatile u32*)(GSWIP_TOP_R_MODULE_BASE + 0x001C))
#define GSWIP_TOP_R_MDC_CFG_1_R			((volatile u32*)(GSWIP_TOP_R_MODULE_BASE + 0x0020))

#define GSW_R_MAC_CTRL_0(i)      		((0x8F7 + (0xC * i)) * 4) //MAC Control Register 0
#define GSW_R_MDC_CFG_0					((volatile u32*)(GSWIP_TOP_R_MODULE_BASE + 0x001C))
#define GSW_R_MDC_CFG_1					((volatile u32*)(GSWIP_TOP_R_MODULE_BASE + 0x0020))
#define GSW_PMAC_TBL_VAL_4				(0xD40 * 4)
#define GSW_PMAC_TBL_VAL_3				(0xD41 * 4)
#define GSW_PMAC_TBL_VAL_2				(0xD42 * 4)
#define GSW_PMAC_TBL_VAL_1				(0xD43 * 4)
#define GSW_PMAC_TBL_VAL_0				(0xD44 * 4)
#define GSW_PMAC_TBL_ADDR				(0xD45 * 4)
#define GSW_PMAC_TBL_CTRL				(0xD46 * 4)
#define PCE_PMAP_3						(0x455 * 4)
#define PCE_PMAP_2						(0x454 * 4)
#define GSW_FDMA_PCTRL(i)       		((0xA80 + (0x6 * i)) * 4)
#define GSW_PCE_PCTRL_0(i)     			((0x480 + (0xA * i)) * 4)


//ETHSW_PMAC:                  
#define GSW_PMAC_ISR           (0xD01 * 4) //PMAC Interrupt Status Register 
#define GSW_PMAC_IER           (0xD02 * 4) //PMAC Interrupt Enable Register 
#define GSW_PMAC_CTRL_0        (0xD03 * 4) //PMAC Control Register 0 
#define GSW_PMAC_CTRL_2        (0xD05 * 4) //PMAC Control Register 2 
#define GSW_PMAC_CTRL_3        (0xD06 * 4) //PMAC Control Register 3 
#define GSW_PMAC_CTRL_4        (0xD07 * 4) //PMAC Control Register 4
#define GSW_PMAC_TBL_VAL_4     (0xD40 * 4) //Table Value Register 4    
#define GSW_PMAC_TBL_VAL_3     (0xD41 * 4) //Table Value Register 3     
#define GSW_PMAC_TBL_VAL_2     (0xD42 * 4) //Table Value Register 2     
#define GSW_PMAC_TBL_VAL_1     (0xD43 * 4) //Table Value Register 1     
#define GSW_PMAC_TBL_VAL_0     (0xD44 * 4) //Table Value Register 0     
#define GSW_PMAC_TBL_ADDR      (0xD45 * 4) //Table Entry Address Register     
#define GSW_PMAC_TBL_CTRL      (0xD46 * 4) //Table Access Control Register 

/* Description: 'Access Request' */
#define PCE_GCTRL_0_MC_VALID_OFFSET 0x456  
#define PCE_GCTRL_0_MC_VALID_SHIFT  3
#define PCE_GCTRL_0_MC_VALID_SIZE   1  

/* --------------------------------------------------- */
/* Register: 'Table Mask Write Register3' (LTQ_GSWIP_3_0) */
/* Bit: 'MASK3' */
/* Description: 'Mask Pattern [15:0]' */
#define PCE_TBL_MASK_3_MASK3_OFFSET		0x42A
#define PCE_TBL_MASK_3_MASK3_SHIFT		0
#define PCE_TBL_MASK_3_MASK3_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Mask Write Register2' (LTQ_GSWIP_3_0) */
/* Bit: 'MASK2' */
/* Description: 'Mask Pattern [15:0]' */
#define PCE_TBL_MASK_2_MASK2_OFFSET		0x42B
#define PCE_TBL_MASK_2_MASK2_SHIFT		0
#define PCE_TBL_MASK_2_MASK2_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Mask Write Register1' (LTQ_GSWIP_3_0) */
/* Bit: 'MASK1' */
/* Description: 'Mask Pattern [15:0]' */
#define PCE_TBL_MASK_1_MASK1_OFFSET		0x42C
#define PCE_TBL_MASK_1_MASK1_SHIFT		0
#define PCE_TBL_MASK_1_MASK1_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register15' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL15' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_15_VAL15_OFFSET		0x42D
#define PCE_TBL_VAL_15_VAL15_SHIFT		0
#define PCE_TBL_VAL_15_VAL15_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register14' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL14' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_14_VAL14_OFFSET		0x42E
#define PCE_TBL_VAL_14_VAL14_SHIFT		0
#define PCE_TBL_VAL_14_VAL14_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register13' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL13' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_13_VAL13_OFFSET		0x42F
#define PCE_TBL_VAL_13_VAL13_SHIFT		0
#define PCE_TBL_VAL_13_VAL13_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register12' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL12' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_12_VAL12_OFFSET		0x430
#define PCE_TBL_VAL_12_VAL12_SHIFT		0
#define PCE_TBL_VAL_12_VAL12_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register11' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL11' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_11_VAL11_OFFSET		0x431
#define PCE_TBL_VAL_11_VAL11_SHIFT		0
#define PCE_TBL_VAL_11_VAL11_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register10' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL10' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_10_VAL10_OFFSET		0x432
#define PCE_TBL_VAL_10_VAL10_SHIFT		0
#define PCE_TBL_VAL_10_VAL10_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register9' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL9' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_9_VAL9_OFFSET		0x433
#define PCE_TBL_VAL_9_VAL9_SHIFT		0
#define PCE_TBL_VAL_9_VAL9_SIZE			16
/* --------------------------------------------------- */
/* Register: 'Table Value Register8' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL8' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_8_VAL8_OFFSET		0x434
#define PCE_TBL_VAL_8_VAL8_SHIFT		0
#define PCE_TBL_VAL_8_VAL8_SIZE			16
/* --------------------------------------------------- */
/* Register: 'Table Value Register7' (LTQ_GSWIP_3_0)*/
/* Bit: 'VAL7' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_7_VAL7_OFFSET		0x435
#define PCE_TBL_VAL_7_VAL7_SHIFT		0
#define PCE_TBL_VAL_7_VAL7_SIZE			16
/* --------------------------------------------------- */
/* Register: 'Table Value Register6' */
/* Bit: 'VAL6' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_6_VAL6_OFFSET		0x436
#define PCE_TBL_VAL_6_VAL6_SHIFT		0
#define PCE_TBL_VAL_6_VAL6_SIZE			16
/* --------------------------------------------------- */
/* Register: 'Table Value Register5' */
/* Bit: 'VAL5' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_5_VAL5_OFFSET		0x437
#define PCE_TBL_VAL_5_VAL5_SHIFT		0
#define PCE_TBL_VAL_5_VAL5_SIZE			16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 15' */
/* Bit: 'KEY15' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_15_KEY15_OFFSET	0x438
#define PCE_TBL_KEY_15_KEY15_SHIFT	0
#define PCE_TBL_KEY_15_KEY15_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 14' */
/* Bit: 'KEY14' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_14_KEY14_OFFSET	0x439
#define PCE_TBL_KEY_14_KEY14_SHIFT	0
#define PCE_TBL_KEY_14_KEY14_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 13' */
/* Bit: 'KEY13' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_13_KEY13_OFFSET	0x43A
#define PCE_TBL_KEY_13_KEY13_SHIFT	0
#define PCE_TBL_KEY_13_KEY13_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 12' */
/* Bit: 'KEY12' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_12_KEY12_OFFSET	0x43B
#define PCE_TBL_KEY_12_KEY12_SHIFT	0
#define PCE_TBL_KEY_12_KEY12_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 11' */
/* Bit: 'KEY11' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_11_KEY11_OFFSET	0x43C
#define PCE_TBL_KEY_11_KEY11_SHIFT	0
#define PCE_TBL_KEY_11_KEY11_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 10' */
/* Bit: 'KEY10' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_10_KEY10_OFFSET	0x43D
#define PCE_TBL_KEY_10_KEY10_SHIFT	0
#define PCE_TBL_KEY_10_KEY10_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 9' */
/* Bit: 'KEY9' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_9_KEY9_OFFSET	0x43E
#define PCE_TBL_KEY_9_KEY9_SHIFT	0
#define PCE_TBL_KEY_9_KEY9_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 8' */
/* Bit: 'KEY8' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_8_KEY8_OFFSET	0x43F
#define PCE_TBL_KEY_8_KEY8_SHIFT	0
#define PCE_TBL_KEY_8_KEY8_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 7' */
/* Bit: 'KEY7' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_7_KEY7_OFFSET	0x440
#define PCE_TBL_KEY_7_KEY7_SHIFT	0
#define PCE_TBL_KEY_7_KEY7_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 6' */
/* Bit: 'KEY6' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_6_KEY6_OFFSET	0x441
#define PCE_TBL_KEY_6_KEY6_SHIFT	0
#define PCE_TBL_KEY_6_KEY6_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 5' */
/* Bit: 'KEY5' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_5_KEY5_OFFSET	0x442
#define PCE_TBL_KEY_5_KEY5_SHIFT	0
#define PCE_TBL_KEY_5_KEY5_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 4' */
/* Bit: 'KEY4' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_4_KEY4_OFFSET	0x443
#define PCE_TBL_KEY_4_KEY4_SHIFT	0
#define PCE_TBL_KEY_4_KEY4_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 3' */
/* Bit: 'KEY3' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_3_KEY3_OFFSET	0x444
#define PCE_TBL_KEY_3_KEY3_SHIFT	0
#define PCE_TBL_KEY_3_KEY3_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 2' */
/* Bit: 'KEY2' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_2_KEY2_OFFSET	0x445
#define PCE_TBL_KEY_2_KEY2_SHIFT	0
#define PCE_TBL_KEY_2_KEY2_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 1' */
/* Bit: 'KEY1' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_1_KEY1_OFFSET	0x446
#define PCE_TBL_KEY_1_KEY1_SHIFT	0
#define PCE_TBL_KEY_1_KEY1_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Key Data 0' */
/* Bit: 'KEY0' */
/* Description: 'Key Value[15:0]' */
#define PCE_TBL_KEY_0_KEY0_OFFSET	0x447
#define PCE_TBL_KEY_0_KEY0_SHIFT	0
#define PCE_TBL_KEY_0_KEY0_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Mask Write Register0' */
/* Bit: 'MASK0' */
/* Description: 'Mask Pattern [15:0]' */
#define PCE_TBL_MASK_0_MASK0_OFFSET	0x448
#define PCE_TBL_MASK_0_MASK0_SHIFT	0
#define PCE_TBL_MASK_0_MASK0_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register4' */
/* Bit: 'VAL4' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_4_VAL4_OFFSET	0x449
#define PCE_TBL_VAL_4_VAL4_SHIFT	0
#define PCE_TBL_VAL_4_VAL4_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register3' */
/* Bit: 'VAL3' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_3_VAL3_OFFSET	0x44A
#define PCE_TBL_VAL_3_VAL3_SHIFT	0
#define PCE_TBL_VAL_3_VAL3_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register2' */
/* Bit: 'VAL2' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_2_VAL2_OFFSET	0x44B
#define PCE_TBL_VAL_2_VAL2_SHIFT	0
#define PCE_TBL_VAL_2_VAL2_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register1' */
/* Bit: 'VAL1' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_1_VAL1_OFFSET	0x44C
#define PCE_TBL_VAL_1_VAL1_SHIFT	0
#define PCE_TBL_VAL_1_VAL1_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Value Register0' */
/* Bit: 'VAL0' */
/* Description: 'Data value [15:0]' */
#define PCE_TBL_VAL_0_VAL0_OFFSET	0x44D
#define PCE_TBL_VAL_0_VAL0_SHIFT	0
#define PCE_TBL_VAL_0_VAL0_SIZE		16
/* --------------------------------------------------- */
/* Register: 'Table Entry AddressRegister' */
/* Bit: 'ADDR' */
/* Description: 'Table Address' */
#define PCE_TBL_ADDR_ADDR_OFFSET	0x44E
#define PCE_TBL_ADDR_ADDR_SHIFT		0
#define PCE_TBL_ADDR_ADDR_SIZE		12
/* --------------------------------------------------- */
/* Register: 'Table Access ControlRegister' */
/* Bit: 'BAS' */
/* Description: 'Access Busy/Access Start' */
#define PCE_TBL_CTRL_BAS_OFFSET	0x44F
#define PCE_TBL_CTRL_BAS_SHIFT	15
#define PCE_TBL_CTRL_BAS_SIZE		1
/* Bit: 'EXTOP' */
/* Description: 'Lookup Table Access Extended Operation Mode' */
#define PCE_TBL_CTRL_EXTOP_OFFSET	0x44F
#define PCE_TBL_CTRL_EXTOP_SHIFT	14
#define PCE_TBL_CTRL_EXTOP_SIZE		1
/* Bit: 'TYPE' */
/* Description: 'Lookup Entry Type' */
#define PCE_TBL_CTRL_TYPE_OFFSET	0x44F
#define PCE_TBL_CTRL_TYPE_SHIFT		13
#define PCE_TBL_CTRL_TYPE_SIZE		1
/* Bit: 'VLD' */
/* Description: 'Lookup Entry Valid' */
#define PCE_TBL_CTRL_VLD_OFFSET	0x44F
#define PCE_TBL_CTRL_VLD_SHIFT	12
#define PCE_TBL_CTRL_VLD_SIZE		1
/* Bit: 'KEYFORM' */
/* Description: 'Key Format' */
#define PCE_TBL_CTRL_KEYFORM_OFFSET	0x44F
#define PCE_TBL_CTRL_KEYFORM_SHIFT	11
#define PCE_TBL_CTRL_KEYFORM_SIZE		1
/* Bit: 'GMAP' */
/* Description: 'Group Map' */
#define PCE_TBL_CTRL_GMAP_OFFSET	0x44F
#define PCE_TBL_CTRL_GMAP_SHIFT		7
#define PCE_TBL_CTRL_GMAP_SIZE		4
/* Bit: 'OPMOD' */
/* Description: 'Lookup Table Access Operation Mode' */
#define PCE_TBL_CTRL_OPMOD_OFFSET	0x44F
#define PCE_TBL_CTRL_OPMOD_SHIFT	5
#define PCE_TBL_CTRL_OPMOD_SIZE		2
/* Bit: 'ADDR' */
/* Description: 'Lookup Table Address' */
#define PCE_TBL_CTRL_ADDR_OFFSET	0x44F
#define PCE_TBL_CTRL_ADDR_SHIFT		0
#define PCE_TBL_CTRL_ADDR_SIZE		5



#define REG32(addr)                 *((volatile u32 *)(addr))                   
#define REG16(addr)                 *((volatile u16 *)(addr))                   
#define REG8(addr)                  *((volatile u8 *)(addr))                    
#define ltq_dma_r32(x)           REG32((x))
#define ltq_dma_w32(x, y)       (REG32((y)) = (x))
#define ltq_dma_w32_mask(clear, set, reg)   \
    ltq_dma_w32((ltq_dma_r32(reg) & ~(clear)) | (set), reg)

/***********************************************************************/       
#endif //GRX500_H                                                                 
