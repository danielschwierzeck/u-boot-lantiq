/* Copyright (c) 2018, Intel Corporation.
 * DDR info dump application
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <lantiq.h>
#include <asm/addrspace.h>

#define PUB_PGSR0	0xb2000034
#define PUB_DTEDR0	0xb2000230
#define PUB_ZQ0SR	0xb200068C
#define PUB_DX3GSR0 	0xb2000AE0
#define PUB_DX2GSR0 	0xb20009E0
#define PUB_DX1GSR0 	0xb20008E0
#define PUB_DX0GSR0 	0xb20007E0
#define PUB_DX3GSR2 	0xb2000AE8
#define PUB_DX2GSR2 	0xb20009E8
#define PUB_DX1GSR2 	0xb20008E8
#define PUB_DX0GSR2 	0xb20007E8
#define PUB_DX3GSR3 	0xb2000AEC
#define PUB_DX2GSR3 	0xb20009EC
#define PUB_DX1GSR3 	0xb20008EC
#define PUB_DX0GSR3 	0xb20007EC
#define PUB_DX3GCR6 	0xb2000A18
#define PUB_DX2GCR6 	0xb2000918
#define PUB_DX1GCR6 	0xb2000818
#define PUB_DX0GCR6 	0xb2000718
#define PUB_VTDR 	0xb200023C
#define PUB_DX2GCR5 	0xb2000914
#define PUB_DX1GCR5 	0xb2000814
#define PUB_DX0GCR5 	0xb2000714
#define PUB_DX3BDLR0 	0xb2000A40
#define PUB_DX3BDLR1 	0xb2000A44
#define PUB_DX3BDLR2 	0xb2000A48
#define PUB_DX2BDLR0 	0xb2000940
#define PUB_DX2BDLR2 	0xb2000948
#define PUB_DX2BDLR1 	0xb2000944
#define PUB_DX1BDLR0 	0xb2000840
#define PUB_DX1BDLR1 	0xb2000844
#define PUB_DX1BDLR2 	0xb2000848
#define PUB_DX0BDLR0 	0xb2000740
#define PUB_DX0BDLR1 	0xb2000744
#define PUB_DX0BDLR2 	0xb2000748
#define PUB_DX3BDLR3 	0xb2000A50
#define PUB_DX3BDLR4 	0xb2000A54
#define PUB_DX3BDLR5 	0xb2000A58
#define PUB_DX2BDLR3 	0xb2000950
#define PUB_DX2BDLR4 	0xb2000954
#define PUB_DX2BDLR5 	0xb2000958
#define PUB_DX1BDLR3 	0xb2000850
#define PUB_DX1BDLR4 	0xb2000854
#define PUB_DX1BDLR5 	0xb2000858
#define PUB_DX0BDLR3 	0xb2000750
#define PUB_DX0BDLR4 	0xb2000754
#define PUB_DX0BDLR5 	0xb2000758
#define PUB_DTEDR0 	0xb2000230
#define PUB_DX3GCR5	0xb2000A14
#define PUB_DTEDR1 	0xb2000234

/* Dump registers to determine the health of the DDR tuning 
 * based on the statuses of the DDR PHY registers. 
 */
int dump_ddr_status(void)
{
	u32 x3, x2, x1, x0;
	/* BDL: bit delay line, LCDL: local calibrated delay line */
	u32 dtwbmax, dtwbmin, dtwlmax, dtwlmin;
	/* BDL: bit delay line, LCDL: local calibrated delay line */
	u32 dtrbmax, dtrbmin, dtrlmax, dtrlmin;

	x0 = REG32(PUB_PGSR0);
	printf("\n\tPGSR0:                            ");
	printf("%08x",x0);	/*Status of PIR execution */
	
	/* It is difficult to visualise this series of printfs statements
 	 * but it is something that the hardware guys use to
 	 * determine the status of the ddr tuning done in bootrom.
 	 * Hence, we shall stick to this so that it is easier to get 
 	 * support and feedback.
 	 */
	x0 = REG32(PUB_ZQ0SR);	/* Impedance Calibration done/error? */
	printf("\n\tPUB_ZQ0SR                         ");
	printf("%08x",x0);		
	printf("\n\t  PD/PU Drive Saturated?          ");
	printf("%08x",(x0>>11)&1);
	printf("/");
	printf("%08x",(x0>>10)&1);
	printf("\n\t  Z Calib Done/Error?             ");
	printf("%08x",(x0>>9)&1);
	printf("/");
	printf("%08x",(x0>>8)&1);
	printf("\n\t  OPU/OPD - ZPU/ZPU?              ");
	printf("%08x",(x0>>6)&3);
	printf("/");
	printf("%08x",(x0>>4)&3);
	printf(" - ");
	printf("%08x",(x0>>2)&3);
	printf("/");
	printf("%08x",x0&3);												

	x3 = REG32(PUB_DX3GSR0); /* RD QDS gating period [25:17], PLL locked[16] */
	x2 = REG32(PUB_DX2GSR0); /* WR QDS gating period [15:07] */
	x1 = REG32(PUB_DX1GSR0); /* WLCAL[4], GQDSCAL[3] */
	x0 = REG32(PUB_DX0GSR0); /* RQDSNCAL[2], RQDSCAL[1], WQDCAL[0]REG32(PUB_DX3GSR0); */

	printf("\n\tDX[3:0]GSR0                       ");
	printf("%08x",x3);
	printf(" ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0);
	printf("\n\t       DPLOCK                     ");
	printf("%02x",(x3>>16)&1);
	printf(" ");
	printf("%02x",(x2>>16)&1);
	printf(" ");
	printf("%02x",(x1>>16)&1);
	printf(" ");
	printf("%02x",(x0>>16)&1);
	printf("\n\t       WLDQ                       ");
	printf("%02x",(x3>>30)&1);
	printf(" ");
	printf("%02x",(x2>>30)&1);
	printf(" ");
	printf("%02x",(x1>>30)&1);
	printf(" ");
	printf("%02x",(x0>>30)&1);
	printf("\n\t       WLWN                       ");
	printf("%02x",(x3>>26)&1);
	printf(" ");
	printf("%02x",(x2>>26)&1);
	printf(" ");
	printf("%02x",(x1>>26)&1);
	printf(" ");
	printf("%02x",(x0>>26)&1);
	printf("\n\t       WLERR                      ");
	printf("%02x",(x3>> 6)&1);
	printf(" ");
	printf("%02x",(x2>> 6)&1);
	printf(" ");
	printf("%02x",(x1>> 6)&1);
	printf(" ");
	printf("%02x",(x0>> 6)&1);
	printf("\n\t       *WLCAL                     ");
	printf("%02x",(x3>> 4)&1);
	printf(" ");
	printf("%02x",(x2>> 4)&1);
	printf(" ");
	printf("%02x",(x1>> 4)&1);
	printf(" ");
	printf("%02x",(x0>> 4)&1);
	printf("\n\t       *RDQS_GATE_CAL             ");
	printf("%02x",(x3>> 3)&1);
	printf(" ");
	printf("%02x",(x2>> 3)&1);
	printf(" ");
	printf("%02x",(x1>> 3)&1);
	printf(" ");
	printf("%02x",(x0>> 3)&1);
	printf("\n\t       *RDQS_N_CAL                ");
	printf("%02x",(x3>> 2)&1);
	printf(" ");
	printf("%02x",(x2>> 2)&1);
	printf(" ");
	printf("%02x",(x1>> 2)&1);
	printf(" ");
	printf("%02x",(x0>> 2)&1);
	printf("\n\t       *RDQS_CAL                  ");
	printf("%02x",(x3>> 1)&1);
	printf(" ");
	printf("%02x",(x2>> 1)&1);
	printf(" ");
	printf("%02x",(x1>> 1)&1);
	printf(" ");
	printf("%02x",(x0>> 1)&1);
	printf("\n\t       *WDQS_CAL                  ");
	printf("%02x",(x3    )&1);
	printf(" ");
	printf("%02x",(x2    )&1);
	printf(" ");
	printf("%02x",(x1    )&1);
	printf(" ");
	printf("%02x",(x0    )&1);
	printf("\n\t       GDQSPRD                    ");
	printf("%02x",(x3>>17)&0x1ff);
	printf(" ");
	printf("%02x",(x2>>17)&0x1ff);
	printf(" ");
	printf("%02x",(x1>>17)&0x1ff);
	printf(" ");
	printf("%02x",(x0>>17)&0x1ff);
	printf("\n\t       WLPRD                      ");
	printf("%02x",(x3>> 7)&0x1ff);
	printf(" ");
	printf("%02x",(x2>> 7)&0x1ff);
	printf(" ");
	printf("%02x",(x1>> 7)&0x1ff);
	printf(" ");
	printf("%02x",(x0>> 7)&0x1ff);

	/*Read DQS gating period [31:23], static read error[20] */
	x3 = REG32(PUB_DX3GSR2); /* WR eye centering warning[7], error[6] */
	x2 = REG32(PUB_DX2GSR2); /* RD eye centering warning[5], error[4] */
	x1 = REG32(PUB_DX1GSR2); /* WR bit deskew warning[3], error[2] */
	x0 = REG32(PUB_DX0GSR2); /* RD bit deskew warning[1], error[0] */
	
	printf("\n\tDX[3:0]GSR2                       ");
	printf("%08x",x3);
	printf(" ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0);
	printf("\n\t       GSDQSPRD                   ");
	printf("%02x",(x3>>23)&0x1ff);
	printf(" ");
	printf("%02x",(x2>>23)&0x1ff);
	printf(" ");
	printf("%02x",(x1>>23)&0x1ff);
	printf(" ");
	printf("%02x",(x0>>23)&0x1ff);
	printf("\n\t       DBDQ                       ");
	printf("%02x",(x3>>12)&0xff);
	printf(" ");
	printf("%02x",(x2>>12)&0xff);
	printf(" ");
	printf("%02x",(x1>>12)&0xff);
	printf(" ");
	printf("%02x",(x0>>12)&0xff);
	printf("\n\t       W_EYE_WN                   ");
	printf("%02x",(x3>> 7)&1);
	printf(" ");
	printf("%02x",(x2>> 7)&1);
	printf(" ");
	printf("%02x",(x1>> 7)&1);
	printf(" ");
	printf("%02x",(x0>> 7)&1);
	printf("\n\t       W_EYE_ERR                  ");
	printf("%02x",(x3>> 6)&1);
	printf(" ");
	printf("%02x",(x2>> 6)&1);
	printf(" ");
	printf("%02x",(x1>> 6)&1);
	printf(" ");
	printf("%02x",(x0>> 6)&1);
	printf("\n\t       R_EYE_WN                   ");
	printf("%02x",(x3>> 5)&1);
	printf(" ");
	printf("%02x",(x2>> 5)&1);
	printf(" ");
	printf("%02x",(x1>> 5)&1);
	printf(" ");
	printf("%02x",(x0>> 5)&1);
	printf("\n\t       R_EYE_ERR                  ");
	printf("%02x",(x3>> 4)&1);
	printf(" ");
	printf("%02x",(x2>> 4)&1);
	printf(" ");
	printf("%02x",(x1>> 4)&1);
	printf(" ");
	printf("%02x",(x0>> 4)&1);
	printf("\n\t       WB_DSKW_WN                 ");
	printf("%02x",(x3>> 3)&1);
	printf(" ");
	printf("%02x",(x2>> 3)&1);
	printf(" ");
	printf("%02x",(x1>> 3)&1);
	printf(" ");
	printf("%02x",(x0>> 3)&1);
	printf("\n\t       WB_DSKW_ERR                ");
	printf("%02x",(x3>> 2)&1);
	printf(" ");
	printf("%02x",(x2>> 2)&1);
	printf(" ");
	printf("%02x",(x1>> 2)&1);
	printf(" ");
	printf("%02x",(x0>> 2)&1);
	printf("\n\t       RB_DSKW_WN                 ");
	printf("%02x",(x3>> 1)&1);
	printf(" ");
	printf("%02x",(x2>> 1)&1);
	printf(" ");
	printf("%02x",(x1>> 1)&1);
	printf(" ");
	printf("%02x",(x0>> 1)&1);
	printf("\n\t       RB_DSKW_ERR                ");
	printf("%02x",(x3    )&1);
	printf(" ");
	printf("%02x",(x2    )&1);
	printf(" ");
	printf("%02x",(x1    )&1);
	printf(" ");
	printf("%02x",(x0    )&1);

	x3 = REG32(PUB_DX3GSR3); /* Vref Training [26:24], [23:20], [19:16], [15:12], [11:8] */
	x2 = REG32(PUB_DX2GSR3); /* Static Read Delay Pass Count [1:0] */
	x1 = REG32(PUB_DX1GSR3);
	x0 = REG32(PUB_DX0GSR3);
	printf("\n\tDX[3:0]GSR3                       ");
	printf("%08x",x3);
	printf(" ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0);
	printf("\n\t       ESTAT                      ");
	printf("%02x",(x3>>24)&3);
	printf(" ");
	printf("%02x",(x2>>24)&3);
	printf(" ");
	printf("%02x",(x1>>24)&3);
	printf(" ");
	printf("%02x",(x0>>24)&3);
	printf("\n\t       DVWRN                      ");
	printf("%02x",(x3>>20)&1);
	printf(" ");
	printf("%02x",(x2>>20)&1);
	printf(" ");
	printf("%02x",(x1>>20)&1);
	printf(" ");
	printf("%02x",(x0>>20)&1);
	printf("\n\t       DVERR                      ");
	printf("%02x",(x3>>16)&1);
	printf(" ");
	printf("%02x",(x2>>16)&1);
	printf(" ");
	printf("%02x",(x1>>16)&1);
	printf(" ");
	printf("%02x",(x0>>16)&1);
	printf("\n\t       HVWRN                      ");
	printf("%02x",(x3>>12)&1);
	printf(" ");
	printf("%02x",(x2>>12)&1);
	printf(" ");
	printf("%02x",(x1>>12)&1);
	printf(" ");
	printf("%02x",(x0>>12)&1);
	printf("\n\t       HVERR                      ");
	printf("%02x",(x3>>8)&1);
	printf(" ");
	printf("%02x",(x2>>8)&1);
	printf(" ");
	printf("%02x",(x1>>8)&1);
	printf(" ");
	printf("%02x",(x0>>8)&1);
	printf("\n\t       SRDPC                      ");
	printf("%02x",(x3)&3);
	printf(" ");
	printf("%02x",(x2)&3);
	printf(" ");
	printf("%02x",(x1)&3);
	printf(" ");
	printf("%02x",(x0)&3);


	printf("\n\tDX[3:0] DVREF (Max/Min)           ");
	printf("%08x",REG32(PUB_DX3GCR6) & 0x3f);
	printf(" ");		
	printf("%08x",REG32(PUB_DX2GCR6) & 0x3f);
	printf(" ");
	printf("%08x",REG32(PUB_DX1GCR6) & 0x3f);
	printf(" ");
	printf("%08x",REG32(PUB_DX0GCR6) & 0x3f);
	printf(" (");
	printf("%02x",(REG32(PUB_VTDR)>>8) & 0xff);
	printf("/");
	printf("%02x",(REG32(PUB_VTDR)>>0) & 0xff);
	printf(")");

	printf("\n\tDX[3:0] HVREF (Max/Min)           ");
	printf("%08x",REG32(PUB_DX3GCR5) & 0x3f);
	printf(" ");
	printf("%08x",REG32(PUB_DX2GCR5) & 0x3f);
	printf(" ");
	printf("%08x",REG32(PUB_DX1GCR5) & 0x3f);
	printf(" ");
	printf("%08x",REG32(PUB_DX0GCR5) & 0x3f);
	printf(" (");
	printf("%02x",(REG32(PUB_VTDR)>>24) & 0xff);
	printf("/");
	printf("%02x",(REG32(PUB_VTDR)>>16) & 0xff);
	printf(")");

	printf("\n\tWrite Bit Delay:");
	x0 = REG32(PUB_DX3BDLR0); 
	x1 = REG32(PUB_DX3BDLR1);
	x2 = REG32(PUB_DX3BDLR2);
	printf("\n\t  DX3BDLR[2:0] d[7:0] en/dqs/dm   ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	x0 = REG32(PUB_DX2BDLR0); 
	x1 = REG32(PUB_DX2BDLR1);
	x2 = REG32(PUB_DX2BDLR2);
	printf("\n\t  DX2BDLR[2:0] d[7:0] en/dqs/dm   ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	x0 = REG32(PUB_DX1BDLR0); 
	x1 = REG32(PUB_DX1BDLR1);
	x2 = REG32(PUB_DX1BDLR2);
	printf("\n\t  DX1BDLR[2:0] d[7:0] en/dqs/dm   ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	x0 = REG32(PUB_DX0BDLR0); 
	x1 = REG32(PUB_DX0BDLR1);
	x2 = REG32(PUB_DX0BDLR2);
	printf("\n\t  DX0BDLR[2:0] d[7:0] en/dqs/dm   ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	printf("\n\tRead Bit Delay:");
	x0 = REG32(PUB_DX3BDLR3); 
	x1 = REG32(PUB_DX3BDLR4);
	x2 = REG32(PUB_DX3BDLR5);

	printf("\n\t  DX3BDLR[5:3] d[7:0] dqsn/dqs/dm ");	
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	x0 = REG32(PUB_DX2BDLR3); 
	x1 = REG32(PUB_DX2BDLR4);
	x2 = REG32(PUB_DX2BDLR5);
	printf("\n\t  DX2BDLR[5:3] d[7:0] dqsn/dqs/dm ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	x0 = REG32(PUB_DX1BDLR3); 
	x1 = REG32(PUB_DX1BDLR4);
	x2 = REG32(PUB_DX1BDLR5);
	printf("\n\t  DX1BDLR[5:3] d[7:0] dqsn/dqs/dm ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	x0 = REG32(PUB_DX0BDLR3); 
	x1 = REG32(PUB_DX0BDLR4);
	x2 = REG32(PUB_DX0BDLR5);
	printf("\n\t  DX0BDLR[5:3] d[7:0] dqsn/dqs/dm ");
	printf("%08x",x2);
	printf(" ");
	printf("%08x",x1);
	printf(" ");
	printf("%08x",x0); 
	printf("   ");
	printf("%02x",(x1>>24)&0x3F);
	printf(" ");
	printf("%02x",(x1>>16)&0x3F);
	printf(" ");
	printf("%02x",(x1>>8)&0x3F);
	printf(" ");
	printf("%02x",(x1)&0x3F);
	printf(" ");
	printf("%02x",(x0>>24)&0x3F);
	printf(" ");
	printf("%02x",(x0>>16)&0x3F);
	printf(" ");
	printf("%02x",(x0>>8)&0x3F);
	printf(" ");
	printf("%02x",(x0)&0x3F);
	printf("   ");
	printf("%02x",(x2>>16)&0x3F);
	printf("/");
	printf("%02x",(x2>>8)&0x3F);
	printf("/");
	printf("%02x",(x2)&0x3F);

	x0 = REG32(PUB_DTEDR0);
	dtwbmax = (x0>>24)&0x3f;
	dtwbmin = (x0>>18)&0x3f;
	dtwlmax = (x0>>9)&0x1ff;
	dtwlmin = (x0>>0)&0x1ff;
	
	printf("\n\tDTEDR0                            ");
	printf("%08x",dtwbmax);
	printf(" ");
	printf("%08x",dtwbmin);
	printf(" ");
	printf("%08x",dtwlmax);
	printf(" ");
	printf("%08x",dtwlmin);
	printf("\n\t  WDQS Center                     ");
	printf("%08x",((dtwlmax+dtwbmax)+(dtwlmin-dtwbmin))/2);
	
	x0 = REG32(PUB_DTEDR1);
	dtrbmax = (x0>>24)&0x3f;
	dtrbmin = (x0>>18)&0x3f;
	dtrlmax = (x0>>9)&0x1ff;
	dtrlmin = (x0>>0)&0x1ff;
	
	printf("\n\tDTEDR1                            ");
	printf("%08x",dtrbmax);
	printf(" ");
	printf("%08x",dtrbmin);
	printf(" ");
	printf("%08x",dtrlmax);
	printf(" ");
	printf("%08x",dtrlmin);
	printf("\n\t  RDQS Center                     ");
	printf("%08x",((dtrlmax+dtrbmax)+(dtrlmin-dtrbmin))/2);

	return 0;
}
