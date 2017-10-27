/**************************************************************************
 * Definition of SoC specific address mapping                             *
 **************************************************************************/
//Use address registers uncached otherwise exception with exception code 2
//#define PUB_BASE     0x12000000
#define PUB_BASE       0xb2000000
//#define uPCTL_BASE   0x12100000
#define uPCTL_BASE     0xb2100000
//#define MEMAX_BASE   0x12200000
#define MEMAX_BASE     0xb2200000
#define DDR3_1_BASE    0x20000000
#define DDR3_2_BASE    0x40000000

/**************************************************************************
 * Definition of DDR3 controller/phy  specific address mapping            *
 **************************************************************************/
#define DFILPCFG0_REG_addr 	 	(0x000002f0 + uPCTL_BASE)
#define DFISTCFG0_REG_addr 	 	(0x000002c4 + uPCTL_BASE)
#define DFISTCFG1_REG_addr 	 	(0x000002c8 + uPCTL_BASE)
#define DFISTCFG2_REG_addr 	 	(0x000002d8 + uPCTL_BASE)
#define DFISTSTAT0_REG_addr 	(0x000002c0 + uPCTL_BASE)
#define DFITPHYRDLAT_REG_addr 	(0x00000264 + uPCTL_BASE)
#define DFITPHYWRLAT_REG_addr 	(0x00000254 + uPCTL_BASE)
#define DFITPHYWRDATALAT_REG_addr 	(0x00000258 + uPCTL_BASE)
#define DFITRDDATAEN_REG_addr 	(0x00000260 + uPCTL_BASE)
#define DFIUPDCFG_REG_addr 	 	(0x00000290 + uPCTL_BASE)
#define ECCCFG_REG_addr 	 	(0x00000180 + uPCTL_BASE)
#define EFI_MEM_DDR3_REG_addr 	(0x00000148 + uPCTL_BASE)
#define DFITCTRLDELAY_REG_addr 	(0x00000240 + uPCTL_BASE)
#define DFITDRAMCLKEN_REG_addr 	(0x000002d0 + uPCTL_BASE)
#define DFITPHYWRDATA_REG_addr 	(0x00000250 + uPCTL_BASE)
#define DFITCTRLUPDMAX_REG_addr (0x00000284 + uPCTL_BASE)
#define DFITDRAMCLKDIS_REG_addr (0x000002d4 + uPCTL_BASE)

#define DFIODTCFG_REG_addr      (0x00000244 + uPCTL_BASE)
#define DFIODTCFG1_REG_addr     (0x00000248 + uPCTL_BASE)
#define DFIODTRANKMAP_REG_addr  (0x0000024c + uPCTL_BASE)


#define MCFG1_REG_addr 	 		(0x0000007c + uPCTL_BASE)
#define MCFG_REG_addr 	 		(0x00000080 + uPCTL_BASE)
#define MCMD_REG_addr 	 		(0x00000040 + uPCTL_BASE)
#define POWCTL_REG_addr 	 	(0x00000044 + uPCTL_BASE)
#define POWSTAT_REG_addr 	 	(0x00000048 + uPCTL_BASE)
#define CMDSTAT_REG_addr 	 	(0x0000004C + uPCTL_BASE)
#define CMDSTATEN_REG_addr 	 	(0x00000050 + uPCTL_BASE)
#define PPCFG_REG_addr 	 		(0x00000084 + uPCTL_BASE)

#define PUB_RIDR_REG_addr 	 	(0x00000000 + PUB_BASE)
#define PUB_PLLCR_REG_addr 	 	(0x00000018 + PUB_BASE)
#define PUB_DCR_REG_addr 	 	(0x00000044 + PUB_BASE)
#define PUB_DTPR0_REG_addr 	 	(0x00000048 + PUB_BASE)
#define PUB_DTPR1_REG_addr 	 	(0x0000004c + PUB_BASE)
#define PUB_DTPR2_REG_addr 	 	(0x00000050 + PUB_BASE)

#define PUB_DX0LCDLR0_REG_addr  (0x000001e0 + PUB_BASE)
#define PUB_DX0LCDLR1_REG_addr  (0x000001e4 + PUB_BASE)
#define PUB_DX0LCDLR2_REG_addr  (0x000001e8 + PUB_BASE)

#define PUB_DX1LCDLR0_REG_addr  (0x00000220 + PUB_BASE)
#define PUB_DX1LCDLR1_REG_addr  (0x00000224 + PUB_BASE)
#define PUB_DX1LCDLR2_REG_addr  (0x00000228 + PUB_BASE)

#define PUB_DSGCR_REG_addr      (0x00000040 + PUB_BASE)
#define PUB_MR0_REG_addr 	 	(0x00000054 + PUB_BASE)
#define PUB_MR1_REG_addr 	 	(0x00000058 + PUB_BASE)
#define PUB_MR2_REG_addr 	 	(0x0000005c + PUB_BASE)
#define PUB_MR3_REG_addr 	 	(0x00000060 + PUB_BASE)
#define PUB_PGCR0_REG_addr 	 	(0x00000008 + PUB_BASE)
#define PUB_PGCR1_REG_addr 	 	(0x0000000c + PUB_BASE)
#define PUB_PGCR2_REG_addr 	 	(0x0000008c + PUB_BASE)
#define PUB_PGSR0_REG_addr 	 	(0x00000010 + PUB_BASE)
#define PUB_PGSR1_REG_addr 	 	(0x00000014 + PUB_BASE)
#define PUB_PIR_REG_addr 	 	(0x00000004 + PUB_BASE)
#define PUB_PTR0_REG_addr 	 	(0x0000001c + PUB_BASE)
#define PUB_PTR1_REG_addr 	 	(0x00000020 + PUB_BASE)
#define PUB_PTR2_REG_addr 	 	(0x00000024 + PUB_BASE)
#define PUB_PTR3_REG_addr 	 	(0x00000028 + PUB_BASE)
#define PUB_PTR4_REG_addr 	 	(0x0000002c + PUB_BASE)
#define PUB_GX0GTR_REG_addr	 	(0x000001f0 + PUB_BASE)
#define PUB_GX1GTR_REG_addr	 	(0x00000230 + PUB_BASE)
#define PUB_GX2GTR_REG_addr	 	(0x00000270 + PUB_BASE)
#define PUB_GX3GTR_REG_addr	 	(0x000002b0 + PUB_BASE)

#define PUB_DX0GCR_REG_addr	 	(0x000001c0 + PUB_BASE)
#define PUB_DX0GSR0_REG_addr	(0x000001c4 + PUB_BASE)
#define PUB_DX0GSR1_REG_addr	(0x000001c8 + PUB_BASE)
#define PUB_DX0GSR2_REG_addr	(0x000001f4 + PUB_BASE)
#define PUB_DX0GTR_REG_addr		(0x000001f0 + PUB_BASE)
#define PUB_DX0MDLR_REG_addr	(0x000001ec + PUB_BASE)

#define PUB_DX0BDLR0_REG_addr	(0x000001cc + PUB_BASE)
#define PUB_DX0BDLR1_REG_addr	(0x000001d0 + PUB_BASE)
#define PUB_DX0BDLR2_REG_addr	(0x000001d4 + PUB_BASE)
#define PUB_DX0BDLR3_REG_addr	(0x000001d8 + PUB_BASE)
#define PUB_DX0BDLR4_REG_addr	(0x000001dc + PUB_BASE)

#define PUB_DX1GCR_REG_addr	 	(0x00000200 + PUB_BASE)
#define PUB_DX1GSR0_REG_addr	(0x00000204 + PUB_BASE)
#define PUB_DX1GSR1_REG_addr	(0x00000208 + PUB_BASE)
#define PUB_DX1GSR2_REG_addr	(0x00000234 + PUB_BASE)
#define PUB_DX1GTR_REG_addr		(0x00000230 + PUB_BASE)
#define PUB_DX1MDLR_REG_addr	(0x0000022c + PUB_BASE)

#define PUB_DX1BDLR0_REG_addr	(0x0000020c + PUB_BASE)
#define PUB_DX1BDLR1_REG_addr	(0x00000210 + PUB_BASE)
#define PUB_DX1BDLR2_REG_addr	(0x00000214 + PUB_BASE)
#define PUB_DX1BDLR3_REG_addr	(0x00000218 + PUB_BASE)
#define PUB_DX1BDLR4_REG_addr	(0x0000021c + PUB_BASE)

#define PUB_DXCCR_REG_addr	 	(0x0000003c + PUB_BASE)
#define PUB_DTCR_REG_addr	 	(0x00000068 + PUB_BASE)

#define PUB_DTDR0_REG_addr	 	(0x0000007c + PUB_BASE)
#define PUB_DTDR1_REG_addr	 	(0x00000080 + PUB_BASE)
#define PUB_DTEDR0_REG_addr	 	(0x00000084 + PUB_BASE)
#define PUB_DTEDR1_REG_addr	 	(0x00000088 + PUB_BASE)

#define PUB_ZQ0CR0_REG_addr	 	(0x00000180 + PUB_BASE)
#define PUB_ZQ0CR1_REG_addr	 	(0x00000184 + PUB_BASE)
#define PUB_ZQ1CR0_REG_addr	 	(0x00000190 + PUB_BASE)
#define PUB_ZQ1CR1_REG_addr	 	(0x00000194 + PUB_BASE)

#define PUB_ACMDLR 				(0x00000030 + PUB_BASE)
#define PUB_ACBDLR 				(0x00000034 + PUB_BASE)
#define PUB_ACIOCR 				(0x00000038 + PUB_BASE)

#define SCFG_REG_addr 	 		(0x00000000 + uPCTL_BASE)
#define SCTL_REG_addr 	 		(0x00000004 + uPCTL_BASE)
#define STAT_REG_addr 	 		(0x00000008 + uPCTL_BASE)
#define TAL_REG_addr 			(0x000000e4 + uPCTL_BASE)
#define TCKESR_REG_addr  		(0x00000140 + uPCTL_BASE)
#define TCKE_REG_addr 	 		(0x0000012c + uPCTL_BASE)
#define TCKSRE_REG_addr  		(0x00000124 + uPCTL_BASE)
#define TCKSRX_REG_addr  		(0x00000128 + uPCTL_BASE)
#define TCL_REG_addr 	 		(0x000000e8 + uPCTL_BASE)
#define TCWL_REG_addr 	 		(0x000000ec + uPCTL_BASE)
#define TDPD_REG_addr 	 		(0x00000144 + uPCTL_BASE)
#define TDQS_REG_addr 	 		(0x00000120 + uPCTL_BASE)
#define TEXSR_REG_addr 	 		(0x0000010c + uPCTL_BASE)
#define TINIT_REG_addr 	 		(0x000000c4 + uPCTL_BASE)
#define TMOD_REG_addr 	 		(0x00000130 + uPCTL_BASE)
#define TMRD_REG_addr 	 		(0x000000d4 + uPCTL_BASE)
#define TOGCNT100N_REG_addr  	(0x000000cc + uPCTL_BASE)
#define TOGCNT1U_REG_addr 	 	(0x000000c0 + uPCTL_BASE)
#define TRAS_REG_addr 	 		(0x000000f0 + uPCTL_BASE)
#define TRCD_REG_addr 	 		(0x000000f8 + uPCTL_BASE)
#define TRC_REG_addr 	 		(0x000000f4 + uPCTL_BASE)
#define TREFI_REG_addr 	 		(0x000000d0 + uPCTL_BASE)
#define TRFC_REG_addr 	 		(0x000000d8 + uPCTL_BASE)
#define TRP_REG_addr 	 		(0x000000dc + uPCTL_BASE)
#define TRRD_REG_addr 	 		(0x000000fc + uPCTL_BASE)
#define TRSTH_REG_addr 	 		(0x000000c8 + uPCTL_BASE)
#define TRSTL_REG_addr 	 		(0x00000134 + uPCTL_BASE)
#define TRTP_REG_addr 	 		(0x00000100 + uPCTL_BASE)
#define TRTW_REG_addr 	 		(0x000000e0 + uPCTL_BASE)
#define TWR_REG_addr 	 		(0x00000104 + uPCTL_BASE)
#define TWTR_REG_addr 	 		(0x00000108 + uPCTL_BASE)
#define TXPDLL_REG_addr  		(0x00000114 + uPCTL_BASE)
#define TXP_REG_addr 	 		(0x00000110 + uPCTL_BASE)
#define TZQCL_REG_addr 	 		(0x00000138 + uPCTL_BASE)
#define TZQCSI_REG_addr  		(0x0000011c + uPCTL_BASE)
#define TZQCS_REG_addr 	 		(0x00000118 + uPCTL_BASE)

