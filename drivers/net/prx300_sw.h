/* Copyright (c) 2017, Intel Corporation.
 *
 * PRX300_SW header file
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <asm/arch/prx300.h>

#define LEGACY_MAC_BASE				GSWIP_LMAC_MODULE_BASE
#define GSWIP_SS					GSWIP_SS_MODULE_BASE
#define XGMAC_CTRL_REG(idx)			((GSWIP_SS | KSEG1) + (0x1298 + ((idx) * 0x100)))
#define XGMAC_DATA1_REG(idx)		((GSWIP_SS | KSEG1) + (0x1294 + ((idx) * 0x100)))
#define XGMAC_DATA0_REG(idx)		((GSWIP_SS | KSEG1) + (0x1290 + ((idx) * 0x100)))

/* MAC register offsets */
#define MAC_TCR                         0x0000
#define MAC_RCR                         0x0004
#define MAC_PFR                         0x0008
#define MAC_WTR                         0x000c
#define MAC_HTR0                        0x0010
#define MAC_VLANTR                      0x0050
#define MAC_VLANHTR                     0x0058
#define MAC_VLANIR                      0x0060
#define MAC_IVLANIR                     0x0064
#define MAC_RETMR                       0x006c
#define MAC_Q0TFCR                      0x0070
#define MAC_RFCR                        0x0090
#define MAC_RQC0R                       0x00a0
#define MAC_RQC1R                       0x00a4
#define MAC_RQC2R                       0x00a8
#define MAC_RQC3R                       0x00ac
#define MAC_ISR                         0x00b0
#define MAC_IER_R                       0x00b4
#define MAC_RTSR_R                      0x00b8
#define MAC_PMTCSR                      0x00c0
#define MAC_RWKPFR                      0x00c4
#define MAC_LPICSR                      0x00d0
#define MAC_LPITCR                      0x00d4
#define MAC_VR                          0x0110
#define MAC_DR                          0x0114
#define MAC_HWF0R                       0x011c
#define MAC_HWF1R                       0x0120
#define MAC_HWF2R                       0x0124
#define MAC_EXTCFG                      0x0140
#define MAC_GPIOCR                      0x0278
#define MAC_GPIOSR                      0x027c
#define MAC_MACA0HR                     0x0300
#define MAC_MACA0LR                     0x0304
#define MAC_MACA1HR                     0x0308
#define MAC_MACA1LR                     0x030c
#define MAC_RSSCR                       0x0c80
#define MAC_RSSAR                       0x0c88
#define MAC_RSSDR                       0x0c8c
#define MAC_TSCR                        0x0d00
#define MAC_SSIR                        0x0d04
#define MAC_STSR                        0x0d08
#define MAC_STNR                        0x0d0c
#define MAC_STSUR                       0x0d10
#define MAC_STNUR                       0x0d14
#define MAC_TSAR                        0x0d18
#define MAC_TSSR                        0x0d20
#define MAC_TXSNR                       0x0d30
#define MAC_TXSSR                       0x0d34
#define MAC_PTOCTL                      0x0dc0

#define MAC_RCR_ACS_INDEX               1
#define MAC_RCR_ACS_WIDTH               1
#define MAC_RCR_CST_INDEX               2
#define MAC_RCR_CST_WIDTH               1
#define MAC_RCR_DCRCC_INDEX             3
#define MAC_RCR_DCRCC_WIDTH             1
#define MAC_RCR_HDSMS_INDEX             12
#define MAC_RCR_HDSMS_WIDTH             3
#define MAC_RCR_IPC_INDEX               9
#define MAC_RCR_IPC_WIDTH               1
#define MAC_RCR_JE_INDEX                8
#define MAC_RCR_JE_WIDTH                1
#define MAC_RCR_LM_INDEX                10
#define MAC_RCR_LM_WIDTH                1
#define MAC_RCR_RE_INDEX                0
#define MAC_RCR_RE_WIDTH                1
#define MAC_RCR_WD_INDEX                7
#define MAC_RCR_WD_WIDTH				1
#define MAC_RCR_GPSLCE_INDEX            6
#define MAC_RCR_GPSLCE_WIDTH			1
#define MAC_RCR_GPSL_INDEX              16
#define MAC_RCR_GPSL_WIDTH				14

#define MAC_TCR_USS_INDEX               31
#define MAC_TCR_USS_WIDTH               1
#define MAC_TCR_SS_INDEX                29
#define MAC_TCR_SS_WIDTH                2
#define MAC_TCR_TE_INDEX                0
#define MAC_TCR_TE_WIDTH                1
#define MAC_TCR_JD_INDEX                16
#define MAC_TCR_JD_WIDTH				1
#define MAC_TCR_IPG_INDEX               8
#define MAC_TCR_IPG_WIDTH				3
#define MAC_TCR_IFP_INDEX               11
#define MAC_TCR_IFP_WIDTH				1

/* RX THRESHOLD operations */
#define MTL_RX_THRESHOLD_32				0x01
#define MTL_RX_THRESHOLD_64             0x00
#define MTL_RX_THRESHOLD_96             0x02
#define MTL_RX_THRESHOLD_128            0x03
#define MTL_TX_THRESHOLD_32             0x01
#define MTL_TX_THRESHOLD_64             0x00
#define MTL_TX_THRESHOLD_96             0x02
#define MTL_TX_THRESHOLD_128            0x03
#define MTL_TX_THRESHOLD_192            0x04
#define MTL_TX_THRESHOLD_256            0x05
#define MTL_TX_THRESHOLD_384            0x06
#define MTL_TX_THRESHOLD_512            0x07

#define MTL_ETSALG_WRR                  0x00
#define MTL_ETSALG_WFQ                  0x01
#define MTL_ETSALG_DWRR                 0x02
#define MTL_RAA_SP                      0x00
#define MTL_RAA_WSP                     0x01

#define MTL_Q_DISABLED                  0x00
#define MTL_Q_ENABLED                   0x02
#define XGMAC_MAX_JUMBO_PACKET  9018
#define XGMAC_MAX_GPSL                  9000 /* Defualt maximum Gaint Packet Size Limit */
#define XGMAC_MAX_SUPPORTED_MTU 16380
#define PRX300_MAX_MTU					10000

#define MAC_ISR_LSI_INDEX               0
#define MAC_ISR_LSI_WIDTH               1
#define MAC_ISR_SMI_INDEX               1
#define MAC_ISR_SMI_WIDTH               1
#define MAC_ISR_PMTIS_INDEX             4
#define MAC_ISR_PMTIS_WIDTH             1
#define MAC_ISR_LPIIS_INDEX             5
#define MAC_ISR_LPIIS_WIDTH             1
#define MAC_ISR_MMCRXIS_INDEX           9
#define MAC_ISR_MMCRXIS_WIDTH           1
#define MAC_ISR_MMCTXIS_INDEX           10
#define MAC_ISR_MMCTXIS_WIDTH           1
#define MAC_ISR_TSIS_INDEX              12
#define MAC_ISR_TSIS_WIDTH              1
#define MAC_ISR_TXESIS_INDEX            13
#define MAC_ISR_TXESIS_WIDTH            1
#define MAC_ISR_RXESIS_INDEX            14
#define MAC_ISR_RXESIS_WIDTH            1
#define MAC_ISR_GPIIS_INDEX             15
#define MAC_ISR_GPIIS_WIDTH             1
#define MAC_ISR_LS_INDEX                24
#define MAC_ISR_LS_WIDTH                2

#define MAC_IER_TSIE_INDEX              12
#define MAC_IER_TSIE_WIDTH              1
#define MAC_IER_TXESIE_INDEX            13
#define MAC_IER_TXESIE_WIDTH            1
#define MAC_IER_RXESIE_INDEX            14
#define MAC_IER_RXESIE_WIDTH            1
#define MAC_IER_LPIIE_INDEX             5
#define MAC_IER_LPIIE_WIDTH             1
#define MAC_IER_PMTIE_INDEX             4
#define MAC_IER_PMTIE_WIDTH             1

#define MAC_LPICSR_LPITXEN_INDEX        16
#define MAC_LPICSR_LPITXEN_WIDTH        1
#define MAC_LPICSR_LPIATE_INDEX         20
#define MAC_LPICSR_LPIATE_WIDTH         1
#define MAC_LPICSR_LPITXA_INDEX         19
#define MAC_LPICSR_LPITXA_WIDTH         1
#define MAC_LPICSR_PLS_INDEX            17
#define MAC_LPICSR_PLS_WIDTH            1
#define MAC_LPITCR_LST_INDEX            16
#define MAC_LPITCR_LST_WIDTH            10
#define MAC_LPITCR_TWT_INDEX            0
#define MAC_LPITCR_TWT_WIDTH            16

#define MAC_MACA1HR_AE_INDEX            31
#define MAC_MACA1HR_AE_WIDTH            1

#define MAC_PFR_PM_INDEX                4
#define MAC_PFR_PM_WIDTH                1
#define MAC_PFR_PR_INDEX                0
#define MAC_PFR_PR_WIDTH                1
#define MAC_PFR_VTFE_INDEX              16
#define MAC_PFR_VTFE_WIDTH              1
#define MAC_PFR_RA_INDEX                31
#define MAC_PFR_RA_WIDTH                1


/* MTL queue register entry bit positions and sizes */
#define MTL_Q_RQMPOCR_MISCNTOVF_INDEX	31
#define MTL_Q_RQMPOCR_MISCNTOVF_WIDTH	 1
#define MTL_Q_RQMPOCR_MISPKTCNT_INDEX	16
#define MTL_Q_RQMPOCR_MISPKTCNT_WIDTH	11
#define MTL_Q_RQMPOCR_OVFCNTOVF_INDEX	15
#define MTL_Q_RQMPOCR_OVFCNTOVF_WIDTH	 1
#define MTL_Q_RQMPOCR_OVFPKTCNT_INDEX	 0
#define MTL_Q_RQMPOCR_OVFPKTCNT_WIDTH	11

#define MTL_Q_TQUR_UFCNTOVF_INDEX		15
#define MTL_Q_TQUR_UFCNTOVF_WIDTH		1
#define MTL_Q_TQUR_UFPKTCNT_INDEX		0
#define MTL_Q_TQUR_UFPKTCNT_WIDTH		11

#define MTL_Q_RQDR_PRXQ_INDEX           16
#define MTL_Q_RQDR_PRXQ_WIDTH           14
#define MTL_Q_RQDR_RXQSTS_INDEX         4
#define MTL_Q_RQDR_RXQSTS_WIDTH         2
#define MTL_Q_RQFCR_RFA_INDEX           1
#define MTL_Q_RQFCR_RFA_WIDTH           6
#define MTL_Q_RQFCR_RFD_INDEX           17
#define MTL_Q_RQFCR_RFD_WIDTH           6
#define MTL_Q_RQOMR_EHFC_INDEX          7
#define MTL_Q_RQOMR_EHFC_WIDTH          1
#define MTL_Q_RQOMR_RQS_INDEX           16
#define MTL_Q_RQOMR_RQS_WIDTH           9
#define MTL_Q_RQOMR_RSF_INDEX           5
#define MTL_Q_RQOMR_RSF_WIDTH           1
#define MTL_Q_RQOMR_RTC_INDEX           0
#define MTL_Q_RQOMR_RTC_WIDTH           2
#define MTL_Q_RQOMR_FUP_INDEX           3
#define MTL_Q_RQOMR_FUP_WIDTH           1
#define MTL_Q_RQOMR_FEF_INDEX           4
#define MTL_Q_RQOMR_FEF_WIDTH           1

#define MTL_Q_RQDG_PRXQ_INDEX           16
#define MTL_Q_RQDG_PRXQ_WIDTH           14
#define MTL_Q_RQDG_RXQSTS_INDEX         4
#define MTL_Q_RQDG_RXQSTS_WIDTH         2
#define MTL_Q_RQDG_RRCSTS_INDEX         1
#define MTL_Q_RQDG_RRCSTS_WIDTH         2

#define MTL_Q_TQOMR_FTQ_INDEX           0
#define MTL_Q_TQOMR_FTQ_WIDTH           1
#define MTL_Q_TQOMR_Q2TCMAP_INDEX       8
#define MTL_Q_TQOMR_Q2TCMAP_WIDTH       3
#define MTL_Q_TQOMR_TQS_INDEX           16
#define MTL_Q_TQOMR_TQS_WIDTH           10
#define MTL_Q_TQOMR_TSF_INDEX           1
#define MTL_Q_TQOMR_TSF_WIDTH           1
#define MTL_Q_TQOMR_TTC_INDEX           4
#define MTL_Q_TQOMR_TTC_WIDTH           3
#define MTL_Q_TQOMR_TXQEN_INDEX         2
#define MTL_Q_TQOMR_TXQEN_WIDTH         2

#define MTL_Q_TQDG_TXQSTS_INDEX         4
#define MTL_Q_TQDG_TXQSTS_WIDTH         1
#define MTL_Q_TQDG_TRCSTS_INDEX         1
#define MTL_Q_TQDG_TRCSTS_WIDTH         2

#define MTL_Q_IER_TXUIE_INDEX			0
#define MTL_Q_IER_TXUIE_WIDTH			1
#define MTL_Q_IER_ABPSIE_INDEX			1
#define MTL_Q_IER_ABPSIE_WIDTH			1
#define MTL_Q_IER_RXOIE_INDEX			16
#define MTL_Q_IER_RXOIE_WIDTH			1

#define MTL_Q_ISR_TXUNFIS_INDEX			0
#define MTL_Q_ISR_TXUNFIS_WIDTH			1
#define MTL_Q_ISR_ABPSIS_INDEX			1
#define MTL_Q_ISR_ABPSIS_WIDTH			1
#define MTL_Q_ISR_RXOVFIS_INDEX			16
#define MTL_Q_ISR_RXOVFIS_WIDTH			1

/* MMC register offsets */
#define MMC_CR                          0x0800
#define MMC_RISR                        0x0804
#define MMC_TISR                        0x0808
#define MMC_RIER                        0x080c
#define MMC_TIER                        0x0810

#define MMC_TXOCTETCOUNT_GB_LO          0x0814
#define MMC_TXOCTETCOUNT_GB_HI          0x0818
#define MMC_TXFRAMECOUNT_GB_LO          0x081c
#define MMC_TXFRAMECOUNT_GB_HI          0x0820
#define MMC_TXBROADCASTFRAMES_G_LO      0x0824
#define MMC_TXBROADCASTFRAMES_G_HI      0x0828
#define MMC_TXMULTICASTFRAMES_G_LO      0x082c
#define MMC_TXMULTICASTFRAMES_G_HI      0x0830
#define MMC_TX64OCTETS_GB_LO            0x0834
#define MMC_TX64OCTETS_GB_HI            0x0838
#define MMC_TX65TO127OCTETS_GB_LO       0x083c
#define MMC_TX65TO127OCTETS_GB_HI       0x0840
#define MMC_TX128TO255OCTETS_GB_LO      0x0844
#define MMC_TX128TO255OCTETS_GB_HI      0x0848
#define MMC_TX256TO511OCTETS_GB_LO      0x084c
#define MMC_TX256TO511OCTETS_GB_HI      0x0850
#define MMC_TX512TO1023OCTETS_GB_LO     0x0854
#define MMC_TX512TO1023OCTETS_GB_HI     0x0858
#define MMC_TX1024TOMAXOCTETS_GB_LO     0x085c
#define MMC_TX1024TOMAXOCTETS_GB_HI     0x0860
#define MMC_TXUNICASTFRAMES_GB_LO       0x0864
#define MMC_TXUNICASTFRAMES_GB_HI       0x0868
#define MMC_TXMULTICASTFRAMES_GB_LO     0x086c
#define MMC_TXMULTICASTFRAMES_GB_HI     0x0870
#define MMC_TXBROADCASTFRAMES_GB_LO     0x0874
#define MMC_TXBROADCASTFRAMES_GB_HI     0x0878
#define MMC_TXUNDERFLOWERROR_LO         0x087c
#define MMC_TXUNDERFLOWERROR_HI         0x0880
#define MMC_TXOCTETCOUNT_G_LO           0x0884
#define MMC_TXOCTETCOUNT_G_HI           0x0888
#define MMC_TXFRAMECOUNT_G_LO           0x088c
#define MMC_TXFRAMECOUNT_G_HI           0x0890
#define MMC_TXPAUSEFRAMES_LO            0x0894
#define MMC_TXPAUSEFRAMES_HI            0x0898
#define MMC_TXVLANFRAMES_G_LO           0x089c
#define MMC_TXVLANFRAMES_G_HI           0x08a0

#define MMC_RXFRAMECOUNT_GB_LO          0x0900
#define MMC_RXFRAMECOUNT_GB_HI          0x0904
#define MMC_RXOCTETCOUNT_GB_LO          0x0908
#define MMC_RXOCTETCOUNT_GB_HI          0x090c
#define MMC_RXOCTETCOUNT_G_LO           0x0910
#define MMC_RXOCTETCOUNT_G_HI           0x0914
#define MMC_RXBROADCASTFRAMES_G_LO      0x0918
#define MMC_RXBROADCASTFRAMES_G_HI      0x091c
#define MMC_RXMULTICASTFRAMES_G_LO      0x0920
#define MMC_RXMULTICASTFRAMES_G_HI      0x0924
#define MMC_RXCRCERROR_LO               0x0928
#define MMC_RXCRCERROR_HI               0x092c
#define MMC_RXRUNTERROR                 0x0930
#define MMC_RXJABBERERROR               0x0934
#define MMC_RXUNDERSIZE_G               0x0938
#define MMC_RXOVERSIZE_G                0x093c
#define MMC_RX64OCTETS_GB_LO            0x0940
#define MMC_RX64OCTETS_GB_HI            0x0944
#define MMC_RX65TO127OCTETS_GB_LO       0x0948
#define MMC_RX65TO127OCTETS_GB_HI       0x094c
#define MMC_RX128TO255OCTETS_GB_LO      0x0950
#define MMC_RX128TO255OCTETS_GB_HI      0x0954
#define MMC_RX256TO511OCTETS_GB_LO      0x0958
#define MMC_RX256TO511OCTETS_GB_HI      0x095c
#define MMC_RX512TO1023OCTETS_GB_LO     0x0960
#define MMC_RX512TO1023OCTETS_GB_HI     0x0964
#define MMC_RX1024TOMAXOCTETS_GB_LO     0x0968
#define MMC_RX1024TOMAXOCTETS_GB_HI     0x096c
#define MMC_RXUNICASTFRAMES_G_LO        0x0970
#define MMC_RXUNICASTFRAMES_G_HI        0x0974
#define MMC_RXLENGTHERROR_LO            0x0978
#define MMC_RXLENGTHERROR_HI            0x097c
#define MMC_RXOUTOFRANGETYPE_LO         0x0980
#define MMC_RXOUTOFRANGETYPE_HI         0x0984
#define MMC_RXPAUSEFRAMES_LO            0x0988
#define MMC_RXPAUSEFRAMES_HI            0x098c
#define MMC_RXFIFOOVERFLOW_LO           0x0990
#define MMC_RXFIFOOVERFLOW_HI           0x0994
#define MMC_RXVLANFRAMES_GB_LO          0x0998
#define MMC_RXVLANFRAMES_GB_HI          0x099c
#define MMC_RXWATCHDOGERROR             0x09a0

/* MMC register entry bit positions and sizes */
#define MMC_CR_CR_INDEX                         0
#define MMC_CR_CR_WIDTH                         1
#define MMC_CR_CSR_INDEX                        1
#define MMC_CR_CSR_WIDTH                        1
#define MMC_CR_ROR_INDEX                        2
#define MMC_CR_ROR_WIDTH                        1
#define MMC_CR_MCF_INDEX                        3
#define MMC_CR_MCF_WIDTH                        1
#define MMC_CR_MCT_INDEX                        4
#define MMC_CR_MCT_WIDTH                        2

#define MMC_RIER_ALL_INTERRUPTS_INDEX           0
#define MMC_RIER_ALL_INTERRUPTS_WIDTH           23
#define MMC_RISR_RXFRAMECOUNT_GB_INDEX          0
#define MMC_RISR_RXFRAMECOUNT_GB_WIDTH          1
#define MMC_RISR_RXOCTETCOUNT_GB_INDEX          1
#define MMC_RISR_RXOCTETCOUNT_GB_WIDTH          1
#define MMC_RISR_RXOCTETCOUNT_G_INDEX           2
#define MMC_RISR_RXOCTETCOUNT_G_WIDTH           1
#define MMC_RISR_RXBROADCASTFRAMES_G_INDEX      3
#define MMC_RISR_RXBROADCASTFRAMES_G_WIDTH      1
#define MMC_RISR_RXMULTICASTFRAMES_G_INDEX      4
#define MMC_RISR_RXMULTICASTFRAMES_G_WIDTH      1
#define MMC_RISR_RXCRCERROR_INDEX               5
#define MMC_RISR_RXCRCERROR_WIDTH               1
#define MMC_RISR_RXRUNTERROR_INDEX              6
#define MMC_RISR_RXRUNTERROR_WIDTH              1
#define MMC_RISR_RXJABBERERROR_INDEX            7
#define MMC_RISR_RXJABBERERROR_WIDTH            1
#define MMC_RISR_RXUNDERSIZE_G_INDEX            8
#define MMC_RISR_RXUNDERSIZE_G_WIDTH            1
#define MMC_RISR_RXOVERSIZE_G_INDEX             9
#define MMC_RISR_RXOVERSIZE_G_WIDTH             1
#define MMC_RISR_RX64OCTETS_GB_INDEX            10
#define MMC_RISR_RX64OCTETS_GB_WIDTH            1
#define MMC_RISR_RX65TO127OCTETS_GB_INDEX       11
#define MMC_RISR_RX65TO127OCTETS_GB_WIDTH       1
#define MMC_RISR_RX128TO255OCTETS_GB_INDEX      12
#define MMC_RISR_RX128TO255OCTETS_GB_WIDTH      1
#define MMC_RISR_RX256TO511OCTETS_GB_INDEX      13
#define MMC_RISR_RX256TO511OCTETS_GB_WIDTH      1
#define MMC_RISR_RX512TO1023OCTETS_GB_INDEX     14
#define MMC_RISR_RX512TO1023OCTETS_GB_WIDTH     1
#define MMC_RISR_RX1024TOMAXOCTETS_GB_INDEX     15
#define MMC_RISR_RX1024TOMAXOCTETS_GB_WIDTH     1
#define MMC_RISR_RXUNICASTFRAMES_G_INDEX        16
#define MMC_RISR_RXUNICASTFRAMES_G_WIDTH        1
#define MMC_RISR_RXLENGTHERROR_INDEX            17
#define MMC_RISR_RXLENGTHERROR_WIDTH            1
#define MMC_RISR_RXOUTOFRANGETYPE_INDEX         18
#define MMC_RISR_RXOUTOFRANGETYPE_WIDTH         1
#define MMC_RISR_RXPAUSEFRAMES_INDEX            19
#define MMC_RISR_RXPAUSEFRAMES_WIDTH            1
#define MMC_RISR_RXFIFOOVERFLOW_INDEX           20
#define MMC_RISR_RXFIFOOVERFLOW_WIDTH           1
#define MMC_RISR_RXVLANFRAMES_GB_INDEX          21
#define MMC_RISR_RXVLANFRAMES_GB_WIDTH          1
#define MMC_RISR_RXWATCHDOGERROR_INDEX          22
#define MMC_RISR_RXWATCHDOGERROR_WIDTH          1

#define MMC_TIER_ALL_INTERRUPTS_INDEX           0
#define MMC_TIER_ALL_INTERRUPTS_WIDTH           18

#define MMC_TISR_TXOCTETCOUNT_GB_INDEX          0
#define MMC_TISR_TXOCTETCOUNT_GB_WIDTH          1
#define MMC_TISR_TXFRAMECOUNT_GB_INDEX          1
#define MMC_TISR_TXFRAMECOUNT_GB_WIDTH          1
#define MMC_TISR_TXBROADCASTFRAMES_G_INDEX      2
#define MMC_TISR_TXBROADCASTFRAMES_G_WIDTH      1
#define MMC_TISR_TXMULTICASTFRAMES_G_INDEX      3
#define MMC_TISR_TXMULTICASTFRAMES_G_WIDTH      1
#define MMC_TISR_TX64OCTETS_GB_INDEX            4
#define MMC_TISR_TX64OCTETS_GB_WIDTH            1
#define MMC_TISR_TX65TO127OCTETS_GB_INDEX       5
#define MMC_TISR_TX65TO127OCTETS_GB_WIDTH       1
#define MMC_TISR_TX128TO255OCTETS_GB_INDEX      6
#define MMC_TISR_TX128TO255OCTETS_GB_WIDTH      1
#define MMC_TISR_TX256TO511OCTETS_GB_INDEX      7
#define MMC_TISR_TX256TO511OCTETS_GB_WIDTH      1
#define MMC_TISR_TX512TO1023OCTETS_GB_INDEX     8
#define MMC_TISR_TX512TO1023OCTETS_GB_WIDTH     1
#define MMC_TISR_TX1024TOMAXOCTETS_GB_INDEX     9
#define MMC_TISR_TX1024TOMAXOCTETS_GB_WIDTH     1
#define MMC_TISR_TXUNICASTFRAMES_GB_INDEX       10
#define MMC_TISR_TXUNICASTFRAMES_GB_WIDTH       1
#define MMC_TISR_TXMULTICASTFRAMES_GB_INDEX     11
#define MMC_TISR_TXMULTICASTFRAMES_GB_WIDTH     1
#define MMC_TISR_TXBROADCASTFRAMES_GB_INDEX     12
#define MMC_TISR_TXBROADCASTFRAMES_GB_WIDTH     1
#define MMC_TISR_TXUNDERFLOWERROR_INDEX         13
#define MMC_TISR_TXUNDERFLOWERROR_WIDTH         1
#define MMC_TISR_TXOCTETCOUNT_G_INDEX           14
#define MMC_TISR_TXOCTETCOUNT_G_WIDTH           1
#define MMC_TISR_TXFRAMECOUNT_G_INDEX           15
#define MMC_TISR_TXFRAMECOUNT_G_WIDTH           1
#define MMC_TISR_TXPAUSEFRAMES_INDEX            16
#define MMC_TISR_TXPAUSEFRAMES_WIDTH            1
#define MMC_TISR_TXVLANFRAMES_G_INDEX           17
#define MMC_TISR_TXVLANFRAMES_G_WIDTH           1

#define MAC_IF_CFG_ADAP_RES_INDEX	15
#define MAC_IF_CFG_ADAP_RES_WIDTH	1
#define MAC_IF_CFG_LMAC_RES_INDEX	14
#define MAC_IF_CFG_LMAC_RES_WIDTH	1
#define MAC_IF_CFG_XGMAC_RES_INDEX	13
#define MAC_IF_CFG_XGMAC_RES_WIDTH	1
#define MAC_IF_CFG_MAC_EN_INDEX	    12
#define MAC_IF_CFG_MAC_EN_WIDTH	    1
#define MAC_IF_CFG_CFG1G_INDEX		1
#define MAC_IF_CFG_CFG1G_WIDTH		1
#define MAC_IF_CFG_CFGFE_INDEX		2
#define MAC_IF_CFG_CFGFE_WIDTH		1
#define MAC_IF_CFG_CFG2G5_INDEX		0
#define MAC_IF_CFG_CFG2G5_WIDTH		1

#define MAC_CTRL0_GMII_INDEX      0
#define MAC_CTRL0_GMII_WIDTH      2
#define MAC_CTRL0_FDUP_INDEX      2
#define MAC_CTRL0_FDUP_WIDTH      2
#define MAC_CTRL0_FCON_INDEX      4
#define MAC_CTRL0_FCON_WIDTH      2
#define MAC_CTRL0_FCS_INDEX       7
#define MAC_CTRL0_FCS_WIDTH       1
#define MAC_CTRL0_PADEN_INDEX     8
#define MAC_CTRL0_PADEN_WIDTH     1
#define MAC_CTRL0_VPADEN_INDEX    9
#define MAC_CTRL0_VPADEN_WIDTH    1
#define MAC_CTRL0_VPAD2EN_INDEX   10
#define MAC_CTRL0_VPAD2EN_WIDTH   1
#define MAC_CTRL0_APADEN_INDEX    11
#define MAC_CTRL0_APADEN_WIDTH    1
#define MAC_PSTAT(idx)			(0x400 + (idx * (0x30)))
#define MAC_PISR(idx)			(0x404 + (idx * (0x30)))
#define MAC_PIER(idx)			(0x408 + (idx * (0x30)))
#define MAC_CTRL0(idx)			(0x40C + (idx * (0x30)))
#define MAC_CTRL1(idx)			(0x410 + (idx * (0x30)))
#define MAC_CTRL2(idx)			(0x414 + (idx * (0x30)))
#define MAC_CTRL3(idx)			(0x418 + (idx * (0x30)))
#define MAC_CTRL4(idx)			(0x41C + (idx * (0x30)))
#define MAC_CTRL5(idx)			(0x420 + (idx * (0x30)))
#define MAC_TESTEN(idx)			(0x42C + (idx * (0x30)))
#define MAC_LPITIMER0(idx)		(0x424 + (idx * (0x30)))
#define MAC_LPITIMER1(idx)		(0x428 + (idx * (0x30)))
#define MAC_IF_CFG(idx)			(0x1200 + (idx * (0x100)))
#define MAC_OP_CFG(idx)			(0x1204 + (idx * (0x100)))
#define MAC_MTU_CFG(idx)		(0x1208 + (idx * (0x100)))
#define MAC_GINT_CFG(idx)		(0x120C + (idx * (0x100)))

#define PHY_MODE_FCONRX_INDEX		5
#define PHY_MODE_FCONRX_WIDTH		2
#define PHY_MODE_FCONTX_INDEX		7
#define PHY_MODE_FCONTX_WIDTH		2
#define PHY_MODE_FDUP_INDEX			9
#define PHY_MODE_FDUP_WIDTH			2
#define PHY_MODE_SPEEDLSB_INDEX		11
#define PHY_MODE_SPEEDLSB_WIDTH		2
#define PHY_MODE_LINKST_INDEX		13
#define PHY_MODE_LINKST_WIDTH		2
#define PHY_MODE_SPEEDMSB_INDEX		15
#define PHY_MODE_SPEEDMSB_WIDTH		1

#define PHY_STAT_TXPAUEN_INDEX		0
#define PHY_STAT_TXPAUEN_WIDTH		1
#define PHY_STAT_RXPAUEN_INDEX		1
#define PHY_STAT_RXPAUEN_WIDTH		1
#define PHY_STAT_FDUP_INDEX			2
#define PHY_STAT_FDUP_WIDTH			1
#define PHY_STAT_SPEEDLSB_INDEX		3
#define PHY_STAT_SPEEDLSB_WIDTH		2
#define PHY_STAT_LSTAT_INDEX		5
#define PHY_STAT_LSTAT_WIDTH		1
#define PHY_STAT_EEECAP_INDEX		7
#define PHY_STAT_EEECAP_WIDTH		1
#define PHY_STAT_CLKSTOPCAP_INDEX	8
#define PHY_STAT_CLKSTOPCAP_WIDTH	1
#define PHY_STAT_SPEEDMSB_INDEX		11
#define PHY_STAT_SPEEDMSB_WIDTH		1

/* XGMAC MDIO */ 
#define MDIO_C_45	0
#define MDIO_C_22	1

#define MDIO_SCAR		0x200
#define MDIO_SCCDR		0x204
#define MDIO_CWAR		0x208
#define MDIO_CWDR		0x20C
#define MDIO_CSPE		0x210
#define MDIO_ISR		0x214
#define MDIO_IER		0x218
#define MDIO_PSR		0x21C
#define MDIO_C22P		0x220
#define MDIO_DIUR(port)	(0x230 + (port * 0x10))
#define MDIO_LSR(port)	(0x234 + (port * 0x10))
#define MDIO_ASR(port)	(0x238 + (port * 0x10))

#define MDIO_SCAR_DA_INDEX	21
#define MDIO_SCAR_DA_WIDTH	 5
#define MDIO_SCAR_PA_INDEX	16
#define MDIO_SCAR_PA_WIDTH	 5
#define MDIO_SCAR_RA_INDEX	 0
#define MDIO_SCAR_RA_WIDTH	16	// Clause 22 (only lower 5 bits are used)

#define MDIO_SCCDR_BUSY_INDEX	22
#define MDIO_SCCDR_BUSY_WIDTH	1
#define MDIO_SCCDR_CR_INDEX		19
#define MDIO_SCCDR_CR_WIDTH		3
#define MDIO_SCCDR_SADDR_INDEX	18
#define MDIO_SCCDR_SADDR_WIDTH	1
#define MDIO_SCCDR_CMD_INDEX	16
#define MDIO_SCCDR_CMD_WIDTH	2
#define MDIO_SCCDR_SDATA_INDEX	0
#define MDIO_SCCDR_SDATA_WIDTH	16

#define MDIO_CWAR_CWB_INDEX			22
#define MDIO_CWAR_CWB_WIDTH			1
#define MDIO_CWAR_CPRT_INDEX		21
#define MDIO_CWAR_CPRT_WIDTH		1
#define MDIO_CWAR_CADDR_INDEX		16
#define MDIO_CWAR_CADDR_WIDTH		5
#define MDIO_CWAR_CREGADDR_INDEX	0
#define MDIO_CWAR_CREGADDR_WIDTH	16

#define MDIO_CWDR_CDATA_INDEX		0
#define MDIO_CWDR_CDATA_WIDTH		16

#define MDIO_CSPE_PORT3_INDEX		3
#define MDIO_CSPE_PORT3_WIDTH		1
#define MDIO_CSPE_PORT2_INDEX		2
#define MDIO_CSPE_PORT2_WIDTH		1
#define MDIO_CSPE_PORT1_INDEX		1
#define MDIO_CSPE_PORT1_WIDTH		1
#define MDIO_CSPE_PORT0_INDEX		0
#define MDIO_CSPE_PORT0_WIDTH		1

#define MDIO_ISR_CWCOMPINT_INDEX	13
#define MDIO_ISR_CWCOMPINT_WIDTH	1
#define MDIO_ISR_SNGLCOMPINT_INDEX	12
#define MDIO_ISR_SNGLCOMPINT_WIDTH	1
#define MDIO_ISR_PRT3ALINT_INDEX	11
#define MDIO_ISR_PRT3ALINT_WIDTH	1
#define MDIO_ISR_PRT2ALINT_INDEX	10
#define MDIO_ISR_PRT2ALINT_WIDTH	1
#define MDIO_ISR_PRT1ALINT_INDEX	9
#define MDIO_ISR_PRT1ALINT_WIDTH	1
#define MDIO_ISR_PRT0ALINT_INDEX	8
#define MDIO_ISR_PRT0ALINT_WIDTH	1
#define MDIO_ISR_PRT3LSINT_INDEX	7
#define MDIO_ISR_PRT3LSINT_WIDTH	1
#define MDIO_ISR_PRT2LSINT_INDEX	6
#define MDIO_ISR_PRT2LSINT_WIDTH	1
#define MDIO_ISR_PRT1LSINT_INDEX	5
#define MDIO_ISR_PRT1LSINT_WIDTH	1
#define MDIO_ISR_PRT0LSINT_INDEX	4
#define MDIO_ISR_PRT0LSINT_WIDTH	1
#define MDIO_ISR_PRT3CONINT_INDEX	3
#define MDIO_ISR_PRT3CONINT_WIDTH	1
#define MDIO_ISR_PRT2CONINT_INDEX	2
#define MDIO_ISR_PRT2CONINT_WIDTH	1
#define MDIO_ISR_PRT1CONINT_INDEX	1
#define MDIO_ISR_PRT1CONINT_WIDTH	1
#define MDIO_ISR_PRT0CONINT_INDEX	0
#define MDIO_ISR_PRT0CONINT_WIDTH	1

#define MDIO_IER_CWCOMPIE_INDEX		13
#define MDIO_IER_CWCOMPIE_WIDTH		1
#define MDIO_IER_SNGLCOMPIE_INDEX	12
#define MDIO_IER_SNGLCOMPIE_WIDTH	1
#define MDIO_IER_PRT3ALIE_INDEX		11
#define MDIO_IER_PRT3ALIE_WIDTH		1
#define MDIO_IER_PRT2ALIE_INDEX		10
#define MDIO_IER_PRT2ALIE_WIDTH		1
#define MDIO_IER_PRT1ALIE_INDEX		9
#define MDIO_IER_PRT1ALIE_WIDTH		1
#define MDIO_IER_PRT0ALIE_INDEX		8
#define MDIO_IER_PRT0ALIE_WIDTH		1
#define MDIO_IER_PRT3LSIE_INDEX		7
#define MDIO_IER_PRT3LSIE_WIDTH		1
#define MDIO_IER_PRT2LSIE_INDEX		6
#define MDIO_IER_PRT2LSIE_WIDTH		1
#define MDIO_IER_PRT1LSIE_INDEX		5
#define MDIO_IER_PRT1LSIE_WIDTH		1
#define MDIO_IER_PRT0LSIE_INDEX		4
#define MDIO_IER_PRT0LSIE_WIDTH		1
#define MDIO_IER_PRT3CONIE_INDEX	3
#define MDIO_IER_PRT3CONIE_WIDTH	1
#define MDIO_IER_PRT2CONIE_INDEX	2
#define MDIO_IER_PRT2CONIE_WIDTH	1
#define MDIO_IER_PRT1CONIE_INDEX	1
#define MDIO_IER_PRT1CONIE_WIDTH	1
#define MDIO_IER_PRT0CONIE_INDEX	0
#define MDIO_IER_PRT0CONIE_WIDTH	1

#define MDIO_PSR_PORT3CON_INDEX		3
#define MDIO_PSR_PORT3CON_WIDTH		1
#define MDIO_PSR_PORT2CON_INDEX		2
#define MDIO_PSR_PORT2CON_WIDTH		1
#define MDIO_PSR_PORT1CON_INDEX		1
#define MDIO_PSR_PORT1CON_WIDTH		1
#define MDIO_PSR_PORT0CON_INDEX		0
#define MDIO_PSR_PORT0CON_WIDTH		1

#define MDIO_CL22P_PORT3_INDEX		3
#define MDIO_CL22P_PORT3_WIDTH		1
#define MDIO_CL22P_PORT2_INDEX		2
#define MDIO_CL22P_PORT2_WIDTH		1
#define MDIO_CL22P_PORT1_INDEX		1
#define MDIO_CL22P_PORT1_WIDTH		1
#define MDIO_CL22P_PORT0_INDEX		0
#define MDIO_CL22P_PORT0_WIDTH		1

#define MDIO_DIUR_PVSD2_INDEX		31
#define MDIO_DIUR_PVSD2_WIDTH		1
#define MDIO_DIUR_PVSD1_INDEX		30
#define MDIO_DIUR_PVSD1_WIDTH		1
#define MDIO_DIUR_PTC_INDEX			6
#define MDIO_DIUR_PTC_WIDTH			1
#define MDIO_DIUR_PDTEXS_INDEX		5
#define MDIO_DIUR_PDTEXS_WIDTH		1
#define MDIO_DIUR_PPHYXS_INDEX		4
#define MDIO_DIUR_PPHYXS_WIDTH		1
#define MDIO_DIUR_PPCS_INDEX		3
#define MDIO_DIUR_PPCS_WIDTH		1
#define MDIO_DIUR_PWIS_INDEX		2
#define MDIO_DIUR_PWIS_WIDTH		1
#define MDIO_DIUR_PPMDPMA_INDEX		1
#define MDIO_DIUR_PPMDPMA_WIDTH		1

#define MDIO_LSR_PVSD2_INDEX		31
#define MDIO_LSR_PVSD2_WIDTH		1
#define MDIO_LSR_PVSD1_INDEX		30
#define MDIO_LSR_PVSD1_WIDTH		1
#define MDIO_LSR_PTC_INDEX			6
#define MDIO_LSR_PTC_WIDTH			1
#define MDIO_LSR_PDTEXS_INDEX		5
#define MDIO_LSR_PDTEXS_WIDTH		1
#define MDIO_LSR_PPHYXS_INDEX		4
#define MDIO_LSR_PPHYXS_WIDTH		1
#define MDIO_LSR_PPCS_INDEX			3
#define MDIO_LSR_PPCS_WIDTH			1
#define MDIO_LSR_PWIS_INDEX			2
#define MDIO_LSR_PWIS_WIDTH			1
#define MDIO_LSR_PPMDPMA_INDEX		1
#define MDIO_LSR_PPMDPMA_WIDTH		1

#define MDIO_ASR_PVSD2_INDEX		31
#define MDIO_ASR_PVSD2_WIDTH		1
#define MDIO_ASR_PVSD1_INDEX		30
#define MDIO_ASR_PVSD1_WIDTH		1
#define MDIO_ASR_PTC_INDEX			6
#define MDIO_ASR_PTC_WIDTH			1
#define MDIO_ASR_PDTEXS_INDEX		5
#define MDIO_ASR_PDTEXS_WIDTH		1
#define MDIO_ASR_PPHYXS_INDEX		4
#define MDIO_ASR_PPHYXS_WIDTH		1
#define MDIO_ASR_PPCS_INDEX			3
#define MDIO_ASR_PPCS_WIDTH			1
#define MDIO_ASR_PWIS_INDEX			2
#define MDIO_ASR_PWIS_WIDTH			1
#define MDIO_ASR_PPMDPMA_INDEX		1
#define MDIO_ASR_PPMDPMA_WIDTH		1

#define MAC_EXTCFG_SBDIOEN_INDEX		8
#define MAC_EXTCFG_SBDIOEN_WIDTH		1

#define GET_BITS(var, _index, _width)                                  \
	(((var) >> (_index)) & ((0x1 << (_width)) - 1))

#define SET_BITS(var, _index, _width, _val)                            \
	do {                                                                    \
		(var) &= ~(((0x1 << (_width)) - 1) << (_index));               \
		(var) |= (((_val) & ((0x1 << (_width)) - 1)) << (_index));     \
	} while (0)

#define XGMAC_GET_BITS(var, prefix, field)                           \
	GET_BITS((var),                                                \
		 prefix##_##field##_INDEX,                            \
		 prefix##_##field##_WIDTH)

#define XGMAC_SET_BITS(var, prefix, field, _val)                     \
	SET_BITS((var),                                                \
		 prefix##_##field##_INDEX,                            \
		 prefix##_##field##_WIDTH, (_val))

#define XGMAC_RGRD_BITS(pdata, reg, field)                         \
	GET_BITS(XGMAC_RGRD(pdata, reg),                          \
		 reg##_##field##_INDEX,                               \
		 reg##_##field##_WIDTH)

#define XGMAC_RGWR_BITS(pdata, reg, field, _val)                  \
	do {                                                                    \
		u32 reg_val = XGMAC_RGRD(pdata, reg);                \
		SET_BITS(reg_val,                                               \
			 reg##_##field##_INDEX,                               \
			 reg##_##field##_WIDTH, (_val));                      \
		XGMAC_RGWR(pdata, reg, reg_val);                         \
	} while (0)

#define MASK(reg, field) 			(1 << reg##_##field##_INDEX)

#define GSWSS_GET_BITS(var, prefix, field)                           \
	GET_BITS((var),                                                \
		 prefix##_##field##_INDEX,                            \
		 prefix##_##field##_WIDTH)

#define GSWSS_SET_BITS(var, prefix, field, _val)                     \
	SET_BITS((var),                                                \
		 prefix##_##field##_INDEX,                            \
		 prefix##_##field##_WIDTH, (_val))

#define GSWSS_RGRD_BITS(reg, field)                         \
	GET_BITS(GSWSS_RGRD(reg),                          \
		 reg##_##field##_INDEX,                               \
		 reg##_##field##_WIDTH)

#define GSWSS_RGWR_BITS(reg, field, val)                  \
	do {                                                                    \
		u32 reg_val = GSWSS_RGRD(reg);                \
		SET_BITS(reg_val,                                               \
			 reg##_##field##_INDEX,                               \
			 reg##_##field##_WIDTH, (val));                      \
		GSWSS_RGWR(reg, reg_val);                         \
	} while (0)

#define LMAC_RGRD_BITS(reg, field)                         \
	GET_BITS(LMAC_RGRD(reg),                          \
		 reg##_##field##_INDEX,                               \
		 reg##_##field##_WIDTH)

#define LMAC_RGWR_BITS(reg, field, val)                  \
	do {                                                                    \
		u32 reg_val = LMAC_RGRD(reg);                \
		SET_BITS(reg_val,                                               \
			 reg##_##field##_INDEX,                               \
			 reg##_##field##_WIDTH, (val));                      \
		LMAC_RGWR(reg, reg_val);                         \
	} while (0)

#define LMAC_GET_BITS(var, prefix, field)                           \
	GET_BITS((var), 											   \
		 prefix##_##field##_INDEX,							  \
		 prefix##_##field##_WIDTH)

#define LMAC_SET_BITS(var, prefix, field, _val)                     \
	SET_BITS((var), 											   \
		 prefix##_##field##_INDEX,							  \
		 prefix##_##field##_WIDTH, (_val))

#define MAC_TXTS_0(idx)			(0x1250 + (idx * (0x100)))
#define MAC_TXTS_1(idx)			(0x1254 + (idx * (0x100)))
#define MAC_TXTS_2(idx)			(0x1258 + (idx * (0x100)))
#define MAC_TXTS_3(idx)			(0x125C + (idx * (0x100)))
#define MAC_TXTS_CIC(idx)		(0x1260 + (idx * (0x100)))
#define MAC_TXTS_ACC(idx)		(0x1264 + (idx * (0x100)))
#define PHY_MODE(idx)			(0x1270 + (idx * (0x100)))
#define PHY_STAT(idx)			(0x1274 + (idx * (0x100)))

/* PTP Clock in Mhz */
#define PTP_CLK					 500

/** \brief Ethernet port duplex status.
    Used by \ref GSW_portLinkCfg_t. */
typedef enum
{
	/** Port operates in full-duplex mode */
	GSW_DUPLEX_FULL	= 0,
	/** Port operates in half-duplex mode */
	GSW_DUPLEX_HALF	= 1
} GSW_portDuplex_t;

/** \brief Force the MAC and PHY link modus.
    Used by \ref GSW_portLinkCfg_t. */
typedef enum
{
	/** Link up. Any connected LED
	   still behaves based on the real PHY status. */
	GSW_PORT_LINK_UP	= 0,
	/** Link down. */
	GSW_PORT_LINK_DOWN	= 1
} GSW_portLink_t;

typedef enum {
	MAC_AUTO_DPLX = 0,
	MAC_FULL_DPLX,
	MAC_RES_DPLX,
	MAC_HALF_DPLX,
} MAC_DUPLEX;

typedef enum {
	SPEED_10M = 0,
	SPEED_100M,
	SPEED_1G,
	SPEED_10G,
	SPEED_2G5,
	SPEED_5G,
	SPEED_FLEX,
	SPEED_AUTO
} SPEED_CFG;

typedef enum {
	SPEED_LMAC_10M = 0,
	SPEED_LMAC_100M,
	SPEED_LMAC_200M,
	SPEED_LMAC_1G,
	SPEED_XGMAC_10M,
	SPEED_XGMAC_100M,
	SPEED_XGMAC_1G,
	SPEED_XGMII_25G,
	SPEED_XGMAC_5G,
	SPEED_XGMAC_10G,
	SPEED_GMII_25G,
	SPEED_MAC_AUTO,
} SPEED_MAC_CFG;

struct xgmac_mmc_stats {
	/* Tx Stats */
	u32 txoctetcount_gb;
	u32 txframecount_gb;
	u32 txbroadcastframes_g;
	u32 txmulticastframes_g;
	u32 tx64octets_gb;
	u32 tx65to127octets_gb;
	u32 tx128to255octets_gb;
	u32 tx256to511octets_gb;
	u32 tx512to1023octets_gb;
	u32 tx1024tomaxoctets_gb;
	u32 txunicastframes_gb;
	u32 txmulticastframes_gb;
	u32 txbroadcastframes_gb;
	u32 txunderflowerror;
	u32 txoctetcount_g;
	u32 txframecount_g;
	u32 txpauseframes;
	u32 txvlanframes_g;

	/* Rx Stats */
	u32 rxframecount_gb;
	u32 rxoctetcount_gb;
	u32 rxoctetcount_g;
	u32 rxbroadcastframes_g;
	u32 rxmulticastframes_g;
	u32 rxcrcerror;
	u32 rxrunterror;
	u32 rxjabbererror;
	u32 rxundersize_g;
	u32 rxoversize_g;
	u32 rx64octets_gb;
	u32 rx65to127octets_gb;
	u32 rx128to255octets_gb;
	u32 rx256to511octets_gb;
	u32 rx512to1023octets_gb;
	u32 rx1024tomaxoctets_gb;
	u32 rxunicastframes_g;
	u32 rxlengtherror;
	u32 rxoutofrangetype;
	u32 rxpauseframes;
	u32 rxfifooverflow;
	u32 rxvlanframes_gb;
	u32 rxwatchdogerror;
};

struct hwtstamp_config {
	int flags;
	int tx_type;
	int rx_filter;
};

typedef enum {
	LMAC_MII = 0,
	LMAC_GMII,
	XGMAC_GMII,
	XGMAC_XGMII,
} if_mode;

/** \brief Ethernet port speed mode.
    For certain generations of GSWIP, a port might support only a subset of the possible settings.
    Used by \ref GSW_portLinkCfg_t. */
typedef enum
{
	/** 10 Mbit/s */
	GSW_PORT_SPEED_10	= 10,
	/** 100 Mbit/s */
	GSW_PORT_SPEED_100	= 100,
	/** 200 Mbit/s */
	GSW_PORT_SPEED_200	= 200,
	/** 1000 Mbit/s */
	GSW_PORT_SPEED_1000	= 1000,
	/** 2.5 Gbit/s */
	GSW_PORT_SPEED_25000	= 25000,
	/** 10 Gbit/s */
	GSW_PORT_SPEED_100000= 100000,
} GSW_portSpeed_t;

/* This structure contains flags that indicate what hardware features
 * or configurations are present in the device.
 */
struct xgmac_hw_features {
	/* HW Version */ 
	u32 version;

	/* HW Feature Register0 */
	u32 gmii;              /* 1000 Mbps support */
	u32 vlhash;            /* VLAN Hash Filter */
	u32 sma;               /* SMA(MDIO) Interface */
	u32 rwk;               /* PMT remote wake-up packet */
	u32 mgk;               /* PMT magic packet */
	u32 mmc;               /* RMON module */
	u32 aoe;               /* ARP Offload */
	u32 ts;                /* IEEE 1588-2008 Advanced Timestamp */
	u32 eee;               /* Energy Efficient Ethernet */
	u32 tx_coe;            /* Tx Checksum Offload */
	u32 rx_coe;            /* Rx Checksum Offload */
	u32 addn_mac;          /* Additional MAC Addresses */
	u32 ts_src;            /* Timestamp Source */
	u32 sa_vlan_ins;       /* Source Address or VLAN Insertion */
	u32 vxn;                                /* VxLAN/NVGRE Support */
	u32 ediffc;                     /* Different Descriptor Cache */
	u32 edma;                               /* Enhanced DMA */

	/* HW Feature Register1 */
	u32 rx_fifo_size;      /* MTL Receive FIFO Size */
	u32 tx_fifo_size;      /* MTL Transmit FIFO Size */
	u32 osten;                      /* One-Step Timestamping Enable */
	u32 ptoen;                      /* PTP Offload Enable */
	u32 adv_ts_hi;         /* Advance Timestamping High Word */
	u32 dma_width;         /* DMA width */
	u32 dcb;               /* DCB Feature */
	u32 sph;               /* Split Header Feature */
	u32 tso;               /* TCP Segmentation Offload */
	u32 dma_debug;         /* DMA Debug Registers */
	u32 rss;               /* Receive Side Scaling */
	u32 tc_cnt;            /* Number of Traffic Classes */
	u32 hash_table_size;   /* Hash Table Size */
	u32 l3l4_filter_num;   /* Number of L3-L4 Filters */
	/* HW Feature Register2 */
	u32 rx_q_cnt;          /* Number of MTL Receive Queues */
	u32 tx_q_cnt;          /* Number of MTL Transmit Queues */
	u32 rx_ch_cnt;         /* Number of DMA Receive Channels */
	u32 tx_ch_cnt;         /* Number of DMA Transmit Channels */
	u32 pps_out_num;       /* Number of PPS outputs */
	u32 aux_snap_num;      /* Number of Aux snapshot inputs */
};

struct ptp_flags {
	u32 ptp_rx_en;
	u32 ptp_tx_en;
};

struct mac_prv_data {
	/* XGMAC registers for indirect accessing */
	u32 xgmac_ctrl_reg;
	u32 xgmac_data0_reg;
	u32 xgmac_data1_reg;

	/* Index to point XGMAC 2/3/4 */
	u32 mac_idx;

	/* TX/RX Queues supported by HW */
	u32 tx_q_count;
	u32 rx_q_count;

	/* Tx settings */
	u32 tx_sf_mode;
	u32 tx_threshold;

	/* Rx settings */
	u32 rx_sf_mode;
	u32 rx_threshold;

	/* Flow control settings */
	u32 pause_autoneg;
	u32 tx_pause;
	u32 rx_pause;
	u32 pause_time;
	u32 pause_frm_enable;

	u32 mac_en;

	/* MAC Addr */
	u8 mac_addr[6];

	/* Rmon related settings */
	struct xgmac_mmc_stats mmc_stats;
	u32 rmon_reset;

	/* Timestamp support */
	struct hwtstamp_config tstamp_config;
	struct ptp_flags ptp_flgs;
	u32 def_addend;
	u32 tstamp_addend;
	u64 tx_tstamp;
	u32 sec;
	u32 nsec;
	u32 one_nsec_accuracy;
	u32 two_step;

#if 0
	#if defined(KERNEL_MODE) && KERNEL_MODE
	/* will be pointing to skb which is
	queued for transmission and device
	will take timesstamp for this skb */
	struct device *dev;
	struct sk_buff *ptp_tx_skb;
	struct work_struct ptp_tx_work;
	struct ptp_clock_info ptp_clk_info;
	spinlock_t ptp_lock;
	struct ptp_clock *ptp_clock;
	u32 ptp_tx_init;
	#endif
#endif

	u32 snaptype;
	u32 tsmstrena;
	u32 tsevntena;
	u32 ttse;
	u32 ostc;
	u32 ostc_avail;

	/* Hardware features of the device */
	struct xgmac_hw_features hw_feat;

	/* MAC rx mode */
	u32 promisc_mode;
	u32 all_mcast_mode;

	u32 rfa;
	u32 rfd;

	u32 tx_mtl_alg;
	u32 rx_mtl_alg;

	u32 mtu;

	u32 rx_checksum_offload;

	/* Reg Read/Write */
	u32 reg_off;
	u32 reg_val;

	/* Phy status */
	u32 phy_speed;
	u32 phymode_speed;
	u32 phy_link;
	u32 phy_mode;

	/* Loopback */
	u32 loopback;

	/* EEE mode */
	u32 eee_enable;
	u32 twt;
	u32 lst;
	u32 lpitxa;

	/* CRC stripping */
	u32 crc_strip;
	u32 crc_strip_type;
	u32 padcrc_strip;

	/* Debug Mode */
	u32 dbg_en;
	u32 dbg_pktie;
	u32 dbg_rst_sel;
	u32 dbg_rst_all;
	u32 dbg_pktstate;
	u32 dbg_data;
	u32 dbg_mode;
	u32 dbg_byteen;

	/* Forward Error paackets */
	u32 fef;
	u32 fup;

	/* interrupts */
	u32 enable_mac_int;
	u32 enable_mtl_int;

	/* IPG */
	u32 ipg;

	/* PMT */
	u32 magic_pkt_en;
	u32 rwk_pkt_en;
	u32 rwk_filter_values[8];
	u32 rwk_filter_length;
	u32 gucast;

	u32 extcfg;

	u32 set_all;
	u32 duplex_mode;

	u32 init_val;

	u32 jd;
	u32 wd;

	u32 linksts;

	u32 fcsgen;

	u32 mdio_cl;
	u32 dev_adr;
	u32 phy_id;
	u32 phy_reg;
	u32 phy_reg_st;
	u32 phy_reg_end;
	u32 phy_data;
	u32 mdio_int;

	u32 ptp_clk;

	u8 mac_reset_complete;

	//struct mac_ops mac_op;
};

/* xgmac_priv data default values for xgmac module 2*/
struct mac_prv_data xgmac_prv_data[3] = {
	{
		.mac_idx          = 0,
		.xgmac_ctrl_reg 	= XGMAC_CTRL_REG(0),
		.xgmac_data0_reg 	= XGMAC_DATA0_REG(0),
		.xgmac_data1_reg 	= XGMAC_DATA1_REG(0),
		.tx_q_count         = 1,
		.rx_q_count         = 1,
		.tx_sf_mode 		= 0,
		.tx_threshold 		= MTL_TX_THRESHOLD_64,
		.rx_sf_mode 		= 0,
		.rx_threshold	    = MTL_RX_THRESHOLD_64,
		.mac_addr			= {0x00, 0x00, 0x94, 0x00, 0x00, 0x08},
		.tstamp_addend      = 0,
		.tx_tstamp			= 0,
		.phy_speed			= SPEED_MAC_AUTO,
		.promisc_mode		= 1,
		.all_mcast_mode		= 1,
		.rfa 				= 2,
		.rfd 				= 4,
		.tx_mtl_alg 		= MTL_ETSALG_WRR,
		.rx_mtl_alg 		= MTL_RAA_SP,
		.mtu 				= PRX300_MAX_MTU,
		.pause_time 		= 0xFFFF,
		.rx_checksum_offload = 1,
		.pause_frm_enable	= 1,
		.rmon_reset			= 1,
		.loopback           = 0,
		.eee_enable         = 1,
		.lst                = 1000,
		.twt                = 0,
		.lpitxa             = 0,
		.crc_strip          = 0,
		.crc_strip_type     = 0,
		.padcrc_strip       = 0,
		.rmon_reset         = 1,
		.fup                = 1,
		.fef                = 1,
		.mac_en             = 1,
		.ipg                = 0,
		.enable_mac_int     = MASK(MAC_IER, TSIE) | MASK(MAC_IER, TXESIE) | MASK(MAC_IER, RXESIE) | MASK(MAC_IER, LPIIE) | MASK(MAC_IER, PMTIE),
		.enable_mtl_int     = MASK(MTL_Q_IER, TXUIE) | MASK(MTL_Q_IER, ABPSIE) | MASK(MTL_Q_IER, RXOIE),
		.def_addend 		= 0x19999999, /* Calc as (2^32 * 50Mhz)/ 500Mhz */
		.sec                = 0,
		.nsec               = 0,
		.ptp_clk            = PTP_CLK,
		.one_nsec_accuracy  = 0,
	},
	/* xgmac_priv data default values xgmac module 3*/
	{
		.mac_idx			= 1,
		.xgmac_ctrl_reg 	= XGMAC_CTRL_REG(1),
		.xgmac_data0_reg 	= XGMAC_DATA0_REG(1),
		.xgmac_data1_reg 	= XGMAC_DATA1_REG(1),
		.tx_q_count 		= 1,
		.rx_q_count 		= 1,
		.tx_sf_mode 		= 0,
		.tx_threshold 		= MTL_TX_THRESHOLD_64,
		.rx_sf_mode 		= 0,
		.rx_threshold	    = MTL_RX_THRESHOLD_64,
		.mac_addr			= {0x00, 0x00, 0x94, 0x00, 0x00, 0x05},
		.tstamp_addend      = 0,
		.tx_tstamp			= 0,
		.phy_speed			= SPEED_MAC_AUTO,
		.promisc_mode		= 1,
		.all_mcast_mode		= 1,
		.rfa 				= 2,
		.rfd 				= 4,
		.tx_mtl_alg 		= MTL_ETSALG_WRR,
		.rx_mtl_alg 		= MTL_RAA_SP,
		.mtu 				= PRX300_MAX_MTU,
		.pause_time 		= 0xFFFF,
		.rx_checksum_offload = 1,
		.pause_frm_enable	= 1,
		.rmon_reset			= 1,
		.loopback           = 0,
		.eee_enable         = 1,
		.lst                = 1000,
		.twt                = 0,
		.lpitxa             = 0,
		.crc_strip			= 0,
		.crc_strip_type 	= 0,
		.padcrc_strip		= 0,
		.rmon_reset 		= 1,
		.fup				= 1,
		.fef				= 1,
		.mac_en 			= 1,
		.ipg				= 0,
		.enable_mac_int 	= MASK(MAC_IER, TSIE) | MASK(MAC_IER, TXESIE) | MASK(MAC_IER, RXESIE) | MASK(MAC_IER, LPIIE) | MASK(MAC_IER, PMTIE),
		.enable_mtl_int 	= MASK(MTL_Q_IER, TXUIE) | MASK(MTL_Q_IER, ABPSIE) | MASK(MTL_Q_IER, RXOIE),
		.def_addend		    = 0x19999999, /* Calc as (2^32 * 50Mhz)/ 500Mhz */
		.sec				= 0,
		.nsec				= 0,
		.ptp_clk            = PTP_CLK,
		.one_nsec_accuracy	= 0,

	},
	/* xgmac_priv data default values xgmac module 4*/
	{
		.mac_idx			= 2,
		.xgmac_ctrl_reg 	= XGMAC_CTRL_REG(2),
		.xgmac_data0_reg 	= XGMAC_DATA0_REG(2),
		.xgmac_data1_reg 	= XGMAC_DATA1_REG(2),
		.tx_q_count 		= 1,
		.rx_q_count 		= 1,
		.tx_sf_mode 		= 0,
		.tx_threshold 		= MTL_TX_THRESHOLD_64,
		.rx_sf_mode 		= 0,
		.rx_threshold	    = MTL_RX_THRESHOLD_64,
		.mac_addr			= {0x00, 0x00, 0x94, 0x00, 0x00, 0x06},
		.tstamp_addend      = 0,
		.tx_tstamp			= 0,
		.phy_speed			= SPEED_MAC_AUTO,
		.promisc_mode		= 1,
		.all_mcast_mode		= 1,
		.rfa 				= 2,
		.rfd 				= 4,
		.tx_mtl_alg 		= MTL_ETSALG_WRR,
		.rx_mtl_alg 		= MTL_RAA_SP,
		.mtu 				= PRX300_MAX_MTU,
		.pause_time 		= 0xFFFF,
		.rx_checksum_offload = 1,
		.pause_frm_enable	= 1,
		.rmon_reset			= 1,
		.loopback           = 0,
		.eee_enable         = 1,
		.lst                = 1000,
		.twt                = 0,
		.lpitxa             = 0,
		.crc_strip			= 0,
		.crc_strip_type 	= 0,
		.padcrc_strip		= 0,
		.rmon_reset 		= 1,
		.fup				= 1,
		.fef				= 1,
		.mac_en 			= 1,
		.ipg                = 0,
		.enable_mac_int     = MASK(MAC_IER, TSIE) | MASK(MAC_IER, TXESIE) | MASK(MAC_IER, RXESIE) | MASK(MAC_IER, LPIIE) | MASK(MAC_IER, PMTIE),
		.enable_mtl_int     = MASK(MTL_Q_IER, TXUIE) | MASK(MTL_Q_IER, ABPSIE) | MASK(MTL_Q_IER, RXOIE),
		.def_addend 		= 0x19999999, /* Calc as (2^32 * 50Mhz)/ 500Mhz */
		.sec				= 0,
		.nsec				= 0,
		.ptp_clk            = PTP_CLK,
		.one_nsec_accuracy  = 0,
	}
};

