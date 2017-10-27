/************************************************************************
 *
 *  init_ddr.c
 *
 *  Configuration of Synopsys' DDR3 Controller+PHY
 *
 ************************************************************************/

/************************************************************************
 *  Include files
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "init_ddr.h"

#define asc_puts printf
#define print_u32(A) (printf("%d\n", (A)))
#define print_u16(A) (printf("%d\n", (A)))
#define print_u8(A) (printf("%d\n", (A)))
#define REG32

/************************************************************************
 * typedef Definition
 ************************************************************************/
typedef unsigned char u8;
typedef unsigned int u32;

struct ddr_settings {
	u32 xDDR_TOGCNT1U;
	u32 xDDR_TOGCNT100N;
	u32 xDDR_TREFPRD;
	u32 xDDR_TRAS;
	u32 xDDR_TRC;
	u32 xDDR_TFAW;
	u32 xDDR_TRRD;
	u32 xDDR_TFAW_CFG;
	u32 xDDR_TFAW_CFG_OFF;
	u32 xDDR_TRFC;
	u32 xDDR_TXSNR;
	u32 xDDR_TEFI_MEM_DDR3;
	u32 xDDR_BANKSZ;
	u32 xDDR_TINIT;
	u32 xDDR_TRSTH;
	u32 xDDR_TRSTL;
	u32 xDDR_TRP;
	u32 xDDR_TAL;
	u32 xDDR_TCL;
	u32 xDDR_DFITPHYWRLAT;
	u32 xDDR_DFITRDDATAEN;
	u32 xDDR_TCWL;
	u32 xDDR_TRCD;
	u32 xDDR_TRTP;
	u32 xDDR_TRTW;
	u32 xDDR_TWR;
	u32 xDDR_TWTR;
	u32 xDDR_TEXSR;  
	u32 xDDR_TDQS;   
	u32 xDDR_TCKSRE; 
	u32 xDDR_TCKSRX; 
	u32 xDDR_TMOD;   
	u32 xDDR_TCKE;   
	u32 xDDR_TZQCS;  
	u32 xDDR_TZQCL;  
	u32 xDDR_TZQCSI; 
	u32 xDDR_TCKESR; 
	u32 xDDR_TDPD;   
	u32 xDDR_TREFI_N;
	u32 xDDR_TREFI_C;
	u32 xDDR_TMRD;   
	u32 xDDR_TCCD;   
	u32 xDDR_TDLLK;  
	u32 xDDR_TXPDLL; 
	u32 xDDR_TXP;    
	u32 xDDR_TXSDLL; 
	u32 xDDR_TXSRD;  
	u32 xDDR_TXS;    
	u32 xDDR_DCR;    
	
	u32 xDDR_MR0;   
	u32 xDDR_MR1; 	
	u32 xDDR_MR2;    
	u32 xDDR_MR3;    	
	u32 xDDR_TWLMRD; 	
	u32 xDDR_TWLO;   	
	u32 xDDR_TAOND;  	
	u32 xDDR_TPHYRST;	
	u32 xDDR_TPLLGS; 
	u32 xDDR_TPLLPD; 
	u32 xDDR_TPLLRST;
	u32 xDDR_TPLLLOCK;
	u32 xDDR_TCALON; 	
	u32 xDDR_TCALS;  	
	u32 xDDR_TCALH;  	
	u32 xDDR_TWLDLYS;		
	u32 xDDR_TDINIT0;	
	u32 xDDR_TDINIT1;	
	u32 xDDR_TDINIT2;	
	u32 xDDR_TDINIT3;	

	u32 xMM_DRAMCONFIG;	
	u32 xMM_SWAP0_H;
	u32 xMM_SWAP0_L;
};

void mem_t(struct ddr_settings * ds);
void dfi_t(struct ddr_settings * ds);
void memmax_init(struct ddr_settings * ds);
void fmt_init(void);
void init_ddr(int id);
void seed(u8 lane, u8 seedw, u8 seedr);
void prt_bdl(u8 lane);
int mtest(void);
 
/************************************************************************
 *  Global variables
 ************************************************************************/
 
int gate_ext = 1; 
FILE * fp;
 
/* Defaul Value Assigned for 512MB DDR3 9-9-9 667MHz single rank*/ 
int ddr_type = 3;
int ddr_grade = 6;
int ddr_density = 8;
int ddr_blen = 8;
int ddr_rank = 1;
int ddr_al = 1;
int endianness = 1;
int fcps = 3;
int fsl = 8;
int fngi = 6;
int fcbm = 6;
int fcps2 = 1;
int fdctl = 5;
int fgsw = 5;
int fgswr = 6;
int cgu_pll0a_cfg1 = 0x40403866;		//cpu/ sl/ngi/cbm =  600/200/300/300 MHz
int cgu_pll0b_cfg1 = 0x40401556;		//cpu/ddr/gsw/mii = 1000/250/330/250 MHz		
int sr0[2] = {24, 24};
int sr1[2] = {24, 24};
int g_output = 0;

static char filename[100];

/************************************************************************
 *  Static variables
 ************************************************************************/
static char *Progname = "init_ddr";

/************************************************************************
 *  Static function prototypes
 ************************************************************************/
extern  u32 dl;
static void __delay(void);

static void __prt_wr(char* s, u32 addr, u32 cmd){
	if (g_output == 1) {
		fprintf(fp, "0x%X    0x%X\n%", (addr), (cmd));
	}
}

static void __prt_rd(char* s, u32 addr, u32 read_reg){
	if (g_output == 1) {
		fprintf(fp, "0x%X    0x%X\n%", (addr+1), read_reg);
	}
}
 
static void __delay(void) {
	__prt_wr("", 0x80000000, 0xFFFF);
}

static void setup_ddr(struct ddr_settings *ds) {
	/* DDR2 */
	if ((ddr_type)==2) {
		if ((ddr_grade)<2) {	  							//f=200MHz, tCK=5nS, 3-3-3 
			ds->xDDR_TOGCNT1U      = 100;		 			// 100*2*5=1uS (based on n_clk)
			ds->xDDR_TOGCNT100N    = 10; 					//  10*2*5=100nS 
			ds->xDDR_TREFPRD       = 14080; 				//9*7800/5=28080
			ds->xDDR_TRAS          = 8;						//min=40nS
			ds->xDDR_TRC           = 11;					//min=55nS
			ds->xDDR_TFAW          = ((ddr_density)<2)?(8):((ddr_density)%2==0)?(10):(8);		//tFAW=37.5-50nS
			ds->xDDR_TRRD          = 2;																	//10nS all cases
			ds->xDDR_TFAW_CFG      = 5;
			ds->xDDR_TFAW_CFG_OFF  = ((ddr_density)<2)?(2):((ddr_density)%2==0)?(0):(2);
			ds->xDDR_TRFC          = ((ddr_density)<2)?(15):((ddr_density)<4)?(21):((ddr_density)<6)?(26):((ddr_density)<8)?(39):(66);
			ds->xDDR_TXSNR         = ((ddr_density)<2)?(17):((ddr_density)<4)?(23):((ddr_density)<6)?(28):((ddr_density)<8)?(41):(68);
		} else 
		if ((ddr_grade)<4) {	  							//f=266MHz, tCK=3.75nS, 4-4-4 
			ds->xDDR_TOGCNT1U      = 133;		 			// 133*2*3.75=1uS (based on n_clk)
			ds->xDDR_TOGCNT100N    = 13; 					//  13*2*3.75=100nS 
			ds->xDDR_TREFPRD       = 18720; 				//9*7800/3.75=18720
			ds->xDDR_TRAS          = 12;					//min=45nS
			ds->xDDR_TRC           = 16;  					//min=60nS
			ds->xDDR_TFAW          = ((ddr_density)<2)?(10):((ddr_density)%2==0)?(14):(10);	//tFAW=37.5-50nS
			ds->xDDR_TRRD          = ((ddr_density)<2)?(2):((ddr_density)%2==0)?(3):(2);		//7.5-10nS, page always 1K for 256Mb         
			ds->xDDR_TFAW_CFG      = 5;
			ds->xDDR_TFAW_CFG_OFF  = ((ddr_density)<2)?(0):((ddr_density)%2==0)?(1):(0);       
			ds->xDDR_TRFC          = ((ddr_density)<2)?(20):((ddr_density)<4)?(28):((ddr_density)<6)?(34):((ddr_density)<8)?(52):(88);
			ds->xDDR_TXSNR         = ((ddr_density)<2)?(23):((ddr_density)<4)?(31):((ddr_density)<6)?(37):((ddr_density)<8)?(55):(91);
		} else
		if ((ddr_grade)<6) {	 	  						//f=333MHz, tCK=3nS, 4-4-4/5-5-5 
			ds->xDDR_TOGCNT1U      = 167;		 			// 167*2*3=1uS (based on n_clk)
			ds->xDDR_TOGCNT100N    = 17 ;					//  17*2*3=100nS 
			ds->xDDR_TREFPRD       = 23400; 				//9*7800/3=23400
			ds->xDDR_TRAS          = 15;					//min=45nS
			ds->xDDR_TRC           = 19+(((ddr_grade))-4);	//min=57(4-4-4)/60nS(5-5-5)
			ds->xDDR_TFAW          = ((ddr_density)<2)?(13):((ddr_density)%2==0)?(17):(13);	//tFAW=37.5-50nS
			ds->xDDR_TRRD          = ((ddr_density)<2)?(3):((ddr_density)%2==0)?(4):(3);		//7.5-10nS, page always 1K for 256Mb
			ds->xDDR_TFAW_CFG      = 5;
			ds->xDDR_TFAW_CFG_OFF  = ((ddr_density)<2)?(2):((ddr_density)%2==0)?(3):(2);       
			ds->xDDR_TRFC          = ((ddr_density)<2)?(25):((ddr_density)<4)?(35):((ddr_density)<6)?(43):((ddr_density)<8)?(65):(109);
			ds->xDDR_TXSNR         = ((ddr_density)<2)?(29):((ddr_density)<4)?(39):((ddr_density)<6)?(47):((ddr_density)<8)?(69):(113);
		} else 
		if ((ddr_grade)<8) {	 	  						//f=400MHz, tCK=2.5nS, 5-5-5/6-6-6 
			ds->xDDR_TOGCNT1U      = 200;		 			// 200 *2*2.5=1uS (based on n_clk)
			ds->xDDR_TOGCNT100N    = 20; 					//  20 *2*2.5=100nS 
			ds->xDDR_TREFPRD       = 28080; 				//9*7800/2.5=28080
			ds->xDDR_TRAS          = 18;					//min=45nS
			ds->xDDR_TRC           = 23+(((ddr_grade))-6);	//min=57.5(5-5-5)/60nS(6-6-6)
			ds->xDDR_TFAW          = ((ddr_density)<2)?(14):((ddr_density)%2==0)?(18):(14);	//tFAW=35-45nS
			ds->xDDR_TRRD          = ((ddr_density)<2)?(3):((ddr_density)%2==0)?(4):(3);		//7.5-10nS, page always 1K for 256Mb         
			ds->xDDR_TFAW_CFG      = 5;
			ds->xDDR_TFAW_CFG_OFF  = ((ddr_density)<2)?(1):((ddr_density)%2==0)?(2):(1);          
			ds->xDDR_TRFC          = ((ddr_density)<2)?(30):((ddr_density)<4)?(42):((ddr_density)<6)?(51):((ddr_density)<8)?(78):(131);
			ds->xDDR_TXSNR         = ((ddr_density)<2)?(34):((ddr_density)<4)?(46):((ddr_density)<6)?(55):((ddr_density)<8)?(82):(135);
		} else {
			 				 	  							//f=533MHz, tCK=1.87nS, 7-7-7 
			ds->xDDR_TOGCNT1U      = 267;		 			// 268*2*1.876=1uS (based on n_clk)
			ds->xDDR_TOGCNT100N    = 27; 					//  27*2*1.876=100nS 
			ds->xDDR_TREFPRD       = 37416; 				//9*7800/1.876=37540
			ds->xDDR_TRAS          = 24;					//min=45nS
			ds->xDDR_TRC           = 31;  					//min=58.125nS				
			ds->xDDR_TFAW          = ((ddr_density)<2)?(19):((ddr_density)%2==0)?(24):(19);	//tFAW=35-45nS
			ds->xDDR_TRRD          = ((ddr_density)<2)?(4):((ddr_density)%2==0)?(6):(4);		//7.5-10nS, page always 1K for 256Mb        
			ds->xDDR_TFAW_CFG      = ((ddr_density)<2)?(5):((ddr_density)%2==0)?(4):(5);
			ds->xDDR_TFAW_CFG_OFF  = ((ddr_density)<2)?(1):((ddr_density)%2==0)?(0):(1);     
			ds->xDDR_TRFC          = ((ddr_density)<2)?(40):((ddr_density)<4)?(57):((ddr_density)<6)?(68):((ddr_density)<8)?(102):(175);
			ds->xDDR_TXSNR         = ((ddr_density)<2)?(46):((ddr_density)<4)?(63):((ddr_density)<6)?(74):((ddr_density)<8)?(108):(181);
		}

		ds->xDDR_TEFI_MEM_DDR3 = 0;
		ds->xDDR_BANKSZ        = ((ddr_density)<4)?(4):(8);
		ds->xDDR_TINIT         = 200;     
		ds->xDDR_TRSTH         = 0;
		ds->xDDR_TRSTL         = 0;
		ds->xDDR_TAL           = (ddr_al);			
		ds->xDDR_TCL           = ((ddr_grade)<2)?(3):((ddr_grade)<4)?(4):((ddr_grade)<6)?((ddr_grade)):((ddr_grade)<8)?(((ddr_grade))-(1)):(7);
		ds->xDDR_TRP           = ((ds->xDDR_BANKSZ)==8)?((1<<16)+(ds->xDDR_TCL)):(ds->xDDR_TCL);

		ds->xDDR_TCWL          = ((ds->xDDR_TCL)-(1));

		ds->xDDR_DFITPHYWRLAT  = (((((ds->xDDR_TCWL)+(ds->xDDR_TAL))-(1))>>1)-(1));
		ds->xDDR_DFITRDDATAEN  = (((((ds->xDDR_TCWL)+(ds->xDDR_TAL)))>>1)-(1));

		ds->xDDR_TRCD          = (ds->xDDR_TCL);
		ds->xDDR_TRTP          = ((ddr_grade)<2)?(2):((ddr_grade)<4)?(2):((ddr_grade)<6)?(3):((ddr_grade)<9)?(3):(4);
		ds->xDDR_TRTW          = 4; 	
		ds->xDDR_TWR           = ((ddr_grade)<2)?(3):((ddr_grade)<4)?(4):((ddr_grade)<6)?(5):((ddr_grade)<9)?(6):(8);
		ds->xDDR_TWTR          = (ds->xDDR_TRTP);
		ds->xDDR_TEXSR         = 200;
		ds->xDDR_TDQS          = 5;
		ds->xDDR_TCKSRE        = 0;
		ds->xDDR_TCKSRX        = 0;
		ds->xDDR_TMOD          = 0;
		ds->xDDR_TCKE          = 3;
		ds->xDDR_TZQCS         = 0;
		ds->xDDR_TZQCL         = 0;
		ds->xDDR_TZQCSI        = 0;
		ds->xDDR_TCKESR        = 0;
		ds->xDDR_TDPD          = 0;
		ds->xDDR_TREFI_N       = 2;
		ds->xDDR_TREFI_C       = (78*(ds->xDDR_TREFI_N));
		ds->xDDR_TMRD          = 2;
		ds->xDDR_TCCD          = 4;
		ds->xDDR_TDLLK         = 512;
		ds->xDDR_TXPDLL        = ((ddr_grade)<2)?(5):((ddr_grade)<4)?(7):((ddr_grade)<6)?(8):((ddr_grade)<9)?(10):(13);
		ds->xDDR_TXP           = 2;
		ds->xDDR_TXSDLL        = 3;
		ds->xDDR_TXSRD         = 200;
		ds->xDDR_TXS           = (ds->xDDR_TXSRD);
		ds->xDDR_DCR           = 0x1000040a;
		ds->xDDR_MR0           = (((ddr_blen)==8)?(3):(2)) + ((ds->xDDR_TCL)<<4) + (((ds->xDDR_TWR)-1)<<9) + (0x100);

		if ((ddr_grade)<6)
			ds->xDDR_MR1       = (((ddr_al)<<3) + (0x04));		//  75Ohm, full drive
		else
			ds->xDDR_MR1       = (((ddr_al)<<3) + (0x40));		// 150Ohm, full drive

		ds->xDDR_MR2           = 0;
		ds->xDDR_MR3           = 0;

		ds->xDDR_TWLMRD        = 0;
		ds->xDDR_TWLO          = 0;
		ds->xDDR_TAOND         = 0;

		ds->xDDR_TPHYRST       = 16;
		ds->xDDR_TPLLPD        = ((ddr_grade)<2)?(100):((ddr_grade)<4)?(133):((ddr_grade)<6)?(167):((ddr_grade)<8)?(200):(266); //1uS
		ds->xDDR_TPLLGS        = (4*(ds->xDDR_TPLLPD));
		ds->xDDR_TPLLRST       = (3*(ds->xDDR_TPLLPD));
		ds->xDDR_TPLLLOCK      = (100*(ds->xDDR_TPLLPD));

		ds->xDDR_TCALON 	   = 15;
		ds->xDDR_TCALS         = 15;
		ds->xDDR_TCALH         = 15;
		ds->xDDR_TWLDLYS       = 16;
	
		ds->xDDR_TDINIT0       = (1000*(ds->xDDR_TPLLPD));
		ds->xDDR_TDINIT1       = ((ds->xDDR_TRFC)+(10));
		ds->xDDR_TDINIT2       = (400*(ds->xDDR_TPLLPD));
		ds->xDDR_TDINIT3       = (2*(ds->xDDR_TPLLPD));

		ds->xMM_DRAMCONFIG     = (0x100c0020)+(((ddr_blen)==8)?(0x100):(0))+(((ds->xDDR_BANKSZ)==8)?(1):(0));

		if (ddr_rank==1) {
			ds->xMM_SWAP0_H    = ((ddr_density)<1)?(0x0011634c):((ddr_density)<3)?(0x00000117):((ddr_density)<4)?(0x000000d9):(0);
			ds->xMM_SWAP0_L    = ((ddr_density)<1)?(0x016c420a):((ddr_density)<3)?(0x0d30324b):((ddr_density)<4)?(0x0f30324b):
                          			((ddr_density)<5)?(0x0461128b):((ddr_density)<7)?(0x0369228b):((ddr_density)<9)?(0x0001528b):(0x01fd428b);
		} else {
			ds->xMM_SWAP0_H    = ((ddr_density)<1)?(0x0011634c):((ddr_density)<3)?(0x00000117):((ddr_density)<4)?(0x000000d9):(0);
			ds->xMM_SWAP0_L    = ((ddr_density)<1)?(0x016c420a):((ddr_density)<3)?(0x0d30324b):((ddr_density)<4)?(0x0f30324b):
                          			((ddr_density)<5)?(0x0461128b):((ddr_density)<7)?(0x0369228b):(0x0001528b);    
		}
	} else {
	/* DDR3 */

/************************
*  ONLY FOR ddr_type 3  *
************************/
		if ((ddr_grade)<2){ 	  							//f=400MHz, tCK=2.5nS, 5-5-5/6-6-6 
			ds->xDDR_TOGCNT1U      = 200;		 			// 200*2*2.5=1uS		(based on n_clk)
			ds->xDDR_TOGCNT100N    = 20; 					//  20*2*2.5=100nS 
			ds->xDDR_TEFI_MEM_DDR3 = 3120;					//7800  /2.5=3120
			ds->xDDR_TREFPRD       = 28080; 				//9*7800/2.5=28080
			ds->xDDR_TRAS          = 15;
			ds->xDDR_TRC           = (20)+((ddr_grade));
			ds->xDDR_TFAW          = ((ddr_density)%2==0)?(20):(16);							//tFAW=40-50nS
			ds->xDDR_TRRD          = 4;																//10nS all sizes
			ds->xDDR_TFAW_CFG      = ((ddr_density)%2==0)?(5):(4);							
			ds->xDDR_TFAW_CFG_OFF  = 0;
			ds->xDDR_TRFC          = ((ddr_density)<4)?(36):((ddr_density)<6)?(44):((ddr_density)<8)?(64):((ddr_density)<10)?(104):(140);
			ds->xDDR_TXS           = ((ddr_density)<4)?(40):((ddr_density)<6)?(48):((ddr_density)<8)?(68):((ddr_density)<10)?(108):(144);
		} else	
		if ((ddr_grade)<5){		  							//f=533MHz, tCK=1.87nS, 7-7-7/8-8-8 
			ds->xDDR_TOGCNT1U      = 267;		 			// 268*2*1.876=1uS		(based on n_clk)
			ds->xDDR_TOGCNT100N    = 27; 					//  27*2*1.876=100nS 
			ds->xDDR_TEFI_MEM_DDR3 = 4157;					//7800  /1.876=4172
			ds->xDDR_TREFPRD       = 37416; 				//9*7800/1.876=37540
			ds->xDDR_TRAS          = 20;
			ds->xDDR_TRC           = (26)+((ddr_grade)-2);
			ds->xDDR_TFAW          = ((ddr_density)>9)?(27):((ddr_density)%2==0)?(27):(20);	//tFAW=37.5-50nS
			ds->xDDR_TRRD          = ((ddr_density)>9)?(6):((ddr_density)%2==0)?(6):(4);		//7.5-10nS, page always 2K for 8Gb
			ds->xDDR_TFAW_CFG      = 5;
			ds->xDDR_TFAW_CFG_OFF  = ((ddr_density)>9)?(3):((ddr_density)%2==0)?(3):(0);
			ds->xDDR_TRFC          = ((ddr_density)<4)?(48):((ddr_density)<6)?(59): ((ddr_density)<8)?(86):((ddr_density)<10)?(139):(187);
			ds->xDDR_TXS           = ((ddr_density)<4)?(54):((ddr_density)<6)?(65): ((ddr_density)<8)?(72):((ddr_density)<10)?(145):(193);
		} else 
		if ((ddr_grade)<8){	 	  							//f=667MHz, tCK=1.5nS, 9-9-9/10-10-10 
			ds->xDDR_TOGCNT1U      = 333;		 			// 333*2*1.5=1uS 		(based on n_clk)
			ds->xDDR_TOGCNT100N    = 33; 					//  33*2*1.5=100nS 
			ds->xDDR_TEFI_MEM_DDR3 = 5208;					//7800  /1.5=5208
			ds->xDDR_TREFPRD       = 46800 ;				//9*7800/1.5=46800
			ds->xDDR_TRAS          = 24;
			ds->xDDR_TRC           = (32)+((ddr_grade)-5);
			ds->xDDR_TFAW          = ((ddr_density)>9)?(30):((ddr_density)%2==0)?(30):(20);	//tFAW=30-45nS
			ds->xDDR_TRRD          = ((ddr_density)>9)?(5):((ddr_density)%2==0)?(5):(4);	//6-7.5nS, page always 2K for 8Gb
			ds->xDDR_TFAW_CFG      = ((ddr_density)>9)?(6):((ddr_density)%2==0)?(6):(5);
			ds->xDDR_TFAW_CFG_OFF  = 0;
			ds->xDDR_TRFC          = ((ddr_density)<4)?(60):((ddr_density)<6)?(74):((ddr_density)<8)?(107):((ddr_density)<10)?(174):(234);
			ds->xDDR_TXS           = ((ddr_density)<4)?(66):((ddr_density)<6)?(80):((ddr_density)<8)?(113):((ddr_density)<10)?(180):(240);
		} else {
			 				 	  							//f=800MHz, tCK=1.25nS, 10-10-10/11-11-11 
			ds->xDDR_TOGCNT1U      = 400;		 			//400  *2*1.25=1uS 		(based on n_clk)
			ds->xDDR_TOGCNT100N    = 40; 					// 40  *2*1.25=100nS 
			ds->xDDR_TEFI_MEM_DDR3 = 6240;					//7800   /1.25=6240
			ds->xDDR_TREFPRD       = 56160; 				//9*7800 /1.25=56160
			ds->xDDR_TRAS          = 28;
			ds->xDDR_TRC           = (37)+((ddr_grade)-8);
			ds->xDDR_TFAW          = ((ddr_density)>9)?(32):((ddr_density)%2==0)?(32):(24);	//tFAW=30-40nS
			ds->xDDR_TRRD          = ((ddr_density)>9)?(6):((ddr_density)%2==0)?(6):(5);	//6-7.5nS, page always 2K for 8Gb
			ds->xDDR_TFAW_CFG      = ((ddr_density)>9)?(6):((ddr_density)%2==0)?(6):(5);
			ds->xDDR_TFAW_CFG_OFF  = ((ddr_density)>9)?(4):((ddr_density)%2==0)?(4):(1);
			ds->xDDR_TRFC          = ((ddr_density)<4)?(72):((ddr_density)<6)?(88):((ddr_density)<8)?(128):((ddr_density)<10)?(208):(280);
			ds->xDDR_TXS           = ((ddr_density)<4)?(80):((ddr_density)<6)?(96):((ddr_density)<8)?(136):((ddr_density)<10)?(216):(288);
		}

		ds->xDDR_BANKSZ        = 8;

		ds->xDDR_TINIT         = 200;      
		ds->xDDR_TRSTH         = 500;  
		ds->xDDR_TRSTL         = ((ddr_grade)<2)?(42):((ddr_grade)<5)?(55):((ddr_grade)<8)?(68):(82);	//100nS + 2CK
		ds->xDDR_TCL           = ((ddr_grade)<2)?(((ddr_grade))+5):((ddr_grade)<5)?(((ddr_grade))+4):((ddr_grade)<8)?
                          			(((ddr_grade))+3):(((ddr_grade))+1);
		ds->xDDR_TAL           = ((ddr_al)>0)?((ds->xDDR_TCL)-(ddr_al)):(0); 
		ds->xDDR_TRP           = (ds->xDDR_TCL);

		ds->xDDR_TCWL          = ((ddr_grade)<2)?(5):((ddr_grade)<5)?(6):((ddr_grade)<8)?(7):(8);
                         	
		ds->xDDR_DFITPHYWRLAT  = (((((ds->xDDR_TCWL)+(ds->xDDR_TAL))-(1))>>1)-(1));
		ds->xDDR_DFITRDDATAEN  = ((ddr_al)>0)?((ds->xDDR_TCL)-(ddr_al)-(1)):							
                          			(((ddr_grade)<3)?(1):((ddr_grade)<6)?(2):((ddr_grade)<10)?(3):(4));	

		ds->xDDR_TRCD          = (ds->xDDR_TCL);
		ds->xDDR_TRTP          = ((ddr_grade)<2)?(4):((ddr_grade)<5)?(5):((ddr_grade)<8)?(5):(6);	
		ds->xDDR_TRTW          = 4;
		ds->xDDR_TWR           = ((ddr_grade)<2)?(6):((ddr_grade)<5)?(8):((ddr_grade)<8)?(10):(12);	
		ds->xDDR_TWTR          = (ds->xDDR_TRTP);
		ds->xDDR_TEXSR         = 512;
		ds->xDDR_TDQS          = 5;
		ds->xDDR_TCKSRE        = ((ddr_grade)<2)?(5):((ddr_grade)<5)?(6):((ddr_grade)<8)?(7):(8);	
		ds->xDDR_TCKSRX        = (ds->xDDR_TCKSRE);
		ds->xDDR_TMOD          = 12;																
		ds->xDDR_TCKE          = ((ddr_grade)<2)?(3):((ddr_grade)<5)?(4):((ddr_grade)<8)?(4):(4);	
		ds->xDDR_TZQCS         = 64;
		ds->xDDR_TZQCL         = 512;
		ds->xDDR_TZQCSI        = 5;
		ds->xDDR_TCKESR        = ((ds->xDDR_TCKE)+(1));
		ds->xDDR_TDPD          = 0;
		ds->xDDR_TREFI_N       = 2;
		ds->xDDR_TREFI_C       = (78*(ds->xDDR_TREFI_N));
		ds->xDDR_TMRD          = 4;
		ds->xDDR_TCCD          = 4;
		ds->xDDR_TDLLK         = 512;
		ds->xDDR_TXPDLL        = ((ddr_grade)<2)?(10):((ddr_grade)<5)?(13):((ddr_grade)<8)?(16):(20);
		ds->xDDR_TXP           = ((ddr_grade)<2)?(3):((ddr_grade)<5)?(5):((ddr_grade)<8)?(4):(5);	
		ds->xDDR_TXSDLL        = (ds->xDDR_TDLLK);
		ds->xDDR_DCR           = 0x1000040b;                        
		ds->xDDR_MR0           = (((ddr_blen)==8)?(0):((ddr_blen)==4)?(0):(1)) + 
                          			(((ds->xDDR_TCL)<=11)?(((ds->xDDR_TCL)-4)<<4):((((ds->xDDR_TCL)-11)<<4) + (4))) + ((1)<<8) + 
                          			(((ds->xDDR_TWR)<= 8)?(((ds->xDDR_TWR)-4)<<9):(((ds->xDDR_TWR)>>1)<<9));
 
		if ((ddr_grade)<8) {
			ds->xDDR_MR1	   = (((ddr_al)<<3) + (0x46));											//ODS=34 Ohm, Rtt=34hm (667MHz)
			ds->xDDR_MR2	   = ((((ds->xDDR_TCWL)-5)<<3) + (0x200));								//Dyn ODT Rtt = 60 Ohm  
		} else {                        
			ds->xDDR_MR1	   = (((ddr_al)<<3) + (0x44));											//ODS=40 Ohm, Rtt=40 Ohm (800MHz)
			ds->xDDR_MR2	   = ((((ds->xDDR_TCWL)-5)<<3) + (0x400));								//Dyn ODT Rtt = 120 Ohm
		}

		ds->xDDR_MR3           = 0;

		ds->xDDR_TWLMRD        = 40;
		ds->xDDR_TWLO          = 8;
		ds->xDDR_TAOND         = 0;

		ds->xDDR_TPHYRST       = 16	;
		ds->xDDR_TPLLPD        = ((ddr_grade)<2)?(200):((ddr_grade)<5)?(266):((ddr_grade)<8)?(333):(400);
		ds->xDDR_TPLLGS        = (4*(ds->xDDR_TPLLPD));
		ds->xDDR_TPLLRST       = (3*(ds->xDDR_TPLLPD));
		ds->xDDR_TPLLLOCK      = (100*(ds->xDDR_TPLLPD));

		ds->xDDR_TCALON 	   = 15;			
		ds->xDDR_TCALS         = 15;
		ds->xDDR_TCALH         = 15;
		ds->xDDR_TWLDLYS       = 16;
	
		ds->xDDR_TDINIT0       = (1000*(ds->xDDR_TPLLPD));
		ds->xDDR_TDINIT1       = (ds->xDDR_TRFC)+(10);
		ds->xDDR_TDINIT2       = (400*(ds->xDDR_TPLLPD));
		ds->xDDR_TDINIT3       = (2*(ds->xDDR_TPLLPD));

		ds->xMM_DRAMCONFIG     = (0x100c0030)+(((ddr_blen)==8)?(0x100):(0))+(((ds->xDDR_BANKSZ)==8)?(1):(0));

		if ((ddr_rank)==1) {
			ds->xMM_SWAP0_H    = 0;
			ds->xMM_SWAP0_L    = ((ddr_density)<3)?(0x0559028b):((ddr_density)<5)?(0x0461128b):((ddr_density)<7)?
						  			(0x0369228b):((ddr_density)<9)?(0x01528b):(0x01fd428b);
		} else {
			ds->xMM_SWAP0_H    = 0;
			ds->xMM_SWAP0_L    = ((ddr_density)<3)?(0x0559028b):((ddr_density)<5)?(0x0461128b):((ddr_density)<7)?
								  (0x0369228b):(0x01528b);
		}
	}
}

/***** functions ******/
void seed(u8 lane, u8 seedw, u8 seedr){
	u32 xw, xr, x2;
	u32 cmd;
	xw = (seedw<<24) + (seedw<<18) + (seedw<<12) + (seedw<<6) + seedw; 
	x2 = (seedr<<18) + (seedr<<12) + (seedw<<6) + seedw; 
	xr = (seedr<<24) + (seedr<<18) + (seedr<<12) + (seedr<<6) + seedr; 
	
	if (lane==0){
		cmd = xw;
		__prt_wr("PUB_DX0BDLR0", PUB_DX0BDLR0_REG_addr, cmd);
		cmd = xw;
		__prt_wr("PUB_DX0BDLR1", PUB_DX0BDLR1_REG_addr, cmd);
		cmd = x2;
		__prt_wr("PUB_DX0BDLR2", PUB_DX0BDLR2_REG_addr, cmd);
		cmd = xr;
		__prt_wr("PUB_DX0BDLR3", PUB_DX0BDLR3_REG_addr, cmd);
		cmd = xr;
		__prt_wr("PUB_DX0BDLR4", PUB_DX0BDLR4_REG_addr, cmd);
	} else {
		cmd = xw;
		__prt_wr("PUB_DX1BDLR0", PUB_DX1BDLR0_REG_addr, cmd);
		cmd = xw;   
		__prt_wr("PUB_DX1BDLR1", PUB_DX1BDLR1_REG_addr, cmd);
		cmd = x2;  
		__prt_wr("PUB_DX1BDLR2", PUB_DX1BDLR2_REG_addr, cmd);
		cmd = xr;
		__prt_wr("PUB_DX1BDLR3", PUB_DX1BDLR3_REG_addr, cmd);
		cmd = xr;
		__prt_wr("PUB_DX1BDLR4", PUB_DX1BDLR4_REG_addr, cmd);
	}	
}

void mem_t(struct ddr_settings * ds){
    u32 cmd;
    cmd = (0x80000000 + (((ds->xDDR_TREFI_N)-1)<<16) + (ds->xDDR_TREFI_C));	
    __prt_wr("TREFI", TREFI_REG_addr, cmd);			
    cmd = (ds->xDDR_TMRD);
    __prt_wr("TMRD", TMRD_REG_addr, cmd);
    cmd = (ds->xDDR_TRFC);
    __prt_wr("TRFC", TRFC_REG_addr, cmd);
    cmd = (ds->xDDR_TRP);
    __prt_wr("TRP", TRP_REG_addr, cmd);
    cmd = (ds->xDDR_TAL);
    __prt_wr("TAL", TAL_REG_addr, cmd);
    cmd = (ds->xDDR_TCL);
    __prt_wr("TCL", TCL_REG_addr, cmd);
    cmd = (ds->xDDR_TCWL);
    __prt_wr("TCWL", TCWL_REG_addr, cmd);
    cmd = (ds->xDDR_TRAS);
    __prt_wr("TRAS", TRAS_REG_addr, cmd);
    cmd = (ds->xDDR_TRC);
    __prt_wr("TRC", TRC_REG_addr, cmd);
    cmd = (ds->xDDR_TRCD);
    __prt_wr("TRCD", TRCD_REG_addr, cmd);
    cmd = (ds->xDDR_TRRD);
    __prt_wr("TRRD", TRRD_REG_addr, cmd);
    cmd = (ds->xDDR_TRTP);
    __prt_wr("TRTP", TRTP_REG_addr, cmd);
    cmd = (ds->xDDR_TRTW);
    __prt_wr("TRTW", TRTW_REG_addr, cmd);
    cmd = (ds->xDDR_TWR);
    __prt_wr("TWR", TWR_REG_addr, cmd);
    cmd = (ds->xDDR_TWTR);
    __prt_wr("TWTR", TWTR_REG_addr, cmd);
    cmd = (ds->xDDR_TEXSR);
    __prt_wr("TEXSR", TEXSR_REG_addr, cmd);
    cmd = (ds->xDDR_TXP);
    __prt_wr("TXP", TXP_REG_addr, cmd);
    cmd = (ds->xDDR_TDQS);
    __prt_wr("TDQS", TDQS_REG_addr, cmd);
    cmd = (ds->xDDR_TCKSRE);
    __prt_wr("TCKSRE", TCKSRE_REG_addr, cmd);
    cmd = (ds->xDDR_TCKSRX);
    __prt_wr("TCKSRX", TCKSRX_REG_addr, cmd);
    cmd = (ds->xDDR_TMOD);
    __prt_wr("TMOD", TMOD_REG_addr, cmd);
    cmd = (ds->xDDR_TCKE);
    __prt_wr("TCKE", TCKE_REG_addr, cmd);
    cmd = (ds->xDDR_TZQCS);
    __prt_wr("TZQCS", TZQCS_REG_addr, cmd);
    cmd = (ds->xDDR_TZQCL);
    __prt_wr("TZQCL", TZQCL_REG_addr, cmd);
    cmd = (ds->xDDR_TXPDLL);
    __prt_wr("TXPDLL", TXPDLL_REG_addr, cmd);
    cmd = (ds->xDDR_TZQCSI);
    __prt_wr("TZQCSI", TZQCSI_REG_addr, cmd);
    cmd = (ds->xDDR_TCKESR);
    __prt_wr("TCKESR", TCKESR_REG_addr, cmd);
    cmd = (ds->xDDR_TDPD);
    __prt_wr("TDPD", TDPD_REG_addr, cmd);
    cmd = (ds->xDDR_TEFI_MEM_DDR3);
    __prt_wr("EFI_MEM_DDR3", EFI_MEM_DDR3_REG_addr, cmd);
} 
 
void dfi_t(struct ddr_settings * ds){	
	u32 cmd;
    cmd = ds->xDDR_DFITPHYWRLAT;
    __prt_wr("DFITPHYWRLAT", DFITPHYWRLAT_REG_addr, cmd);
    cmd = ds->xDDR_DFITRDDATAEN;
    __prt_wr("DFITRDDATAEN", DFITRDDATAEN_REG_addr, cmd);
    cmd = 0x00000001;    	//1  
    __prt_wr("DFITPHYWRDATA", DFITPHYWRDATA_REG_addr, cmd);
    cmd = 0x00000003;		//3
    __prt_wr("DFITPHYWRDATALAT", DFITPHYWRDATALAT_REG_addr, cmd);
    cmd = 0x0000000f;   	//f
    __prt_wr("DFITPHYRDLAT", DFITPHYRDLAT_REG_addr, cmd);
    cmd = 0x00000002;
    __prt_wr("DFITDRAMCLKDIS", DFITDRAMCLKDIS_REG_addr, cmd);
    cmd = 0x00000002;   
    __prt_wr("DFITDRAMCLKEN", DFITDRAMCLKEN_REG_addr, cmd);
    cmd = 0x00000003;		//2
    __prt_wr("DFITCTRLDELAY", DFITCTRLDELAY_REG_addr, cmd);
	
//TRI activate ODT from CTRL
	
	cmd = (ddr_rank==1)?0x08:0x0808;		//Enable ODT for rank 0 and 1 when a write access on this rank
	__prt_wr("DFIODTCFG", DFIODTCFG_REG_addr, cmd);
	
	if (ddr_type==2) { 
		if ((ddr_grade)<9)							//All DDR2 except DDR2-1066
			cmd = 0x06060000 + (((ds->xDDR_TCL)+(ds->xDDR_TAL)-3)<<8) +	((ds->xDDR_TCWL)+(ds->xDDR_TAL)-3);	
		else
			cmd = 0x07070000 + (((ds->xDDR_TCL)+(ds->xDDR_TAL)-4)<<8) + ((ds->xDDR_TCWL)+(ds->xDDR_TAL)-4);	
	} else {
		cmd = 0x06060000 + (((ds->xDDR_TCL)-(ds->xDDR_TCWL))<<8);	
	}

	__prt_wr("DFIODTCFG1", DFIODTCFG1_REG_addr, cmd);	

	cmd = (ddr_rank==1)?0x01:0x21;			//dfi_odt[x] will be asserted to terminate rank x (x=1,2)
	__prt_wr("DFIODTRANKMAP", DFIODTRANKMAP_REG_addr, cmd);	
	    
    cmd = 0x00000040;
    __prt_wr("DFITCTRLUPDMAX", DFITCTRLUPDMAX_REG_addr, cmd);
}

void memmax_init(struct ddr_settings * ds) {
	u32 cmd;
	if (endianness == 1) {
		//BIG_ENDIAN
		cmd = ds->xMM_DRAMCONFIG;	
		__prt_wr("MM_DRAMCONFIG", 0xb2200004, cmd);	
		cmd = ds->xMM_SWAP0_H;	
		__prt_wr("MM_SWAP0_H", 0xb2200120, cmd); 
		cmd = ds->xMM_SWAP0_L;		
		__prt_wr("MM_SWAP0_L", 0xb2200124, cmd);
	} else {
		cmd = ds->xMM_DRAMCONFIG;	
		__prt_wr("MM_DRAMCONFIG", 0xb2200000, cmd);	
		cmd = ds->xMM_SWAP0_H;	
		__prt_wr("MM_SWAP0_H", 0xb2200124, cmd); 	
		cmd = ds->xMM_SWAP0_L;		
		__prt_wr("MM_SWAP0_L", 0xb2200120, cmd); 
	}
}

void fmt_init(void) {
	u32 cmd;
	cmd = 0xf8002000;		//FMT0 0x80000000/0xa0000000 > 0x20000000 (128MB DRAM )
	__prt_wr("FMT_0", 0xb49001d0, cmd); 
	cmd = 0xf8002800;		//FMT1 0x88000000/0xa8000000 > 0x28000000 (128MB DRAM )
	__prt_wr("FMT_1", 0xb49001d4, cmd); 
	cmd = 0xfe00a000;		//FMT2 0x90000000/0xb0000000 > 0xa0000000 ( 32MB IOCU1)
	__prt_wr("FMT_2", 0xb49001d8, cmd); 
}

void syntax(void)
{
    printf("Syntax: %s [options]\n", Progname);
    printf("Options:\n");
    printf("  -h        Display this (help) information\n");
    printf("  --help    Display this (help) information\n");
	printf("  -type  DDR type (3)\n");
	printf("            2: DDR2\n");	
	printf("            3: DDR3\n\n");
	printf("  -grade (6)\n");
	printf("            DDR2#           \t  DDR3#\n");
	printf("            0: 200MHz @ CL=3\t  0: 400MHz @ CL=5  \n");	
	printf("            2: 266MHz @ CL=4\t  1: 400MHz @ CL=6  \n");
	printf("            4: 333MHz @ CL=4\t  2: 533MHz @ CL=6  \n");	
	printf("            5: 333MHz @ CL=5\t  3: 533MHz @ CL=7  \n");	
	printf("            6: 400MHz @ CL=5\t  4: 533MHz @ CL=8  \n");
	printf("            7: 400MHz @ CL=6\t  5: 667MHz @ CL=8  \n");	
	printf("            9: 533MHz @ CL=7\t  6: 667MHz @ CL=9  \n");	
	printf("                            \t  7: 667MHz @ CL=10 \n");
	printf("                            \t  8: 800MHz @ CL=9  \n");
	printf("                            \t  9: 800MHz @ CL=10 \n");	
	printf("                            \t  10: 800MHz @ CL=11\n\n");

	printf("  -density (8)\n");	
	printf("            DDR2#           \t  DDR3#\n");	
	printf("            0: 16Mx16	    \t  2: 32Mx16  \n");	
	printf("            1: 32Mx8	    \t  3: 64Mx8   \n");	
	printf("            2: 32Mx16	    \t  4: 64Mx16  \n");
	printf("            3: 64Mx8	    \t  5: 128Mx8  \n");	
	printf("            4: 64Mx16	    \t  6: 128Mx16 \n");	
	printf("            5: 128Mx8	    \t  7: 256Mx8  \n");
	printf("            6: 128Mx16      \t  8: 256Mx16 \n");
	printf("            7: 256Mx8	    \t  9: 512Mx8  \n");	
	printf("            8: 256Mx16      \t  10: 512Mx16\n");
	printf("            9: 512Mx8\n\n");

	printf("  -bl    burst length (8)\n");	
	printf("            4: Burst chop 4   \n");	
	printf("            8: Burst length 8 \n\n");	
	printf("  -al    additive latency (1)\n");	
	printf("            DDR2#           \t  DDR3#\n");	
	printf("            0: AL=0         \t  0: no AL\n");	
	printf("            1: AL=1         \t  1: AL=CL-1\n");	
	printf("            2: AL=2         \t  2: AL=CL-2\n");	
	printf("            3: AL=3\n");
	printf("            4: AL=4\n");
	printf("            5: AL=5\n");
	printf("            6: AL=6\n\n");

	printf("  -rank  (1)\n");	
	printf("            1: CS0 only\n");	
	printf("            2: CS0, CS1\n\n");	

	printf("  -sr0   pre-seed rank 0 (24 24)\n");	
	printf("  -sr1   pre-seed rank 1 (24 24)\n");		
	printf("            Valid value: 0 .. 63\n\n");	

	printf("  -endian (1)\n");	
	printf("            0: Little endian\n");
	printf("            1: Big endian\n\n");
	
	printf("  -o     output file name\n");
	printf("\t without -o arg, there will not be any output file generated\n\n");	
	
	printf("  -fcps  CPS frequency (3)\n");
	printf("  -fsl   Share Link frequency (8)\n");		
	printf("  -fngi  NGI/TEP frequency (6)\n");	
	printf("  -fcbm  CBM frequency (6)\n");	
	printf("            0:  2400MHz     \t  1: 1200MHz\n");	
	printf("            2:   800MHz     \t  3:  600MHz\n");
	printf("            4:   480MHz     \t  5:  400MHz\n");
	printf("            6:   300MHz     \t  7:  240MHz\n");
	printf("            8:   200MHz     \t  9:  150MHz\n");
	printf("            10:  120MHz     \t  11: 100MHz\n"); 
	printf("            12:   75MHz     \t  13:  60MHz\n");
	printf("            14:   50MHz     \t  15:  37.5MHz\n");
	printf("            16: 1000MHz (cps only) \n\n");	

	printf("  -fcps2 CPS Frequency alternative(1)\n");			
	printf("  -fdctl DDR Controller frequency (5)\n");		
	printf("  -fgsw  GSWIP-L frequency (5)\n");	
	printf("  -fgswr GSWIP-R/MII frequency (6)\n");		
	printf("            0:  2000MHz     \t  1: 1000MHz\n");	
	printf("            2:   666MHz     \t  3:  500MHz\n");	
	printf("            4:   400MHz     \t  5:  333MHz\n");
	printf("            6:   250MHz     \t  7:  200MHz\n");
	printf("            8:   166MHz     \t  9:  125MHz\n");
	printf("            10:	 100MHz     \t  11:  83MHz\n"); 
	printf("            12:  62.5MHz    \t  13:  50MHz\n");
	printf("            14:  41.6MHz    \t  15:  51.25MHz\n\n");	
	
	printf("Example: ./init_ddr -h\n");
	printf("         ./init_ddr -type 3 -grade 6 -density 8 -rank 1 -bl 8 -al 1 -endian 1 -sr0 20 20 -sr1 20 20 -fcps 3 -fsl 8 -fngi 6 -fcbm 6 -fcps2 1 -fdctl 5 -fgsw 5 -fgswr 6 -o ddr.conf\n");
	printf("         ./init_ddr -type 3 -grade 10 -density 8 -rank 1 -bl 8 -al 1 -endian 1 -sr0 20 20 -sr1 20 20 -fcps 2 -fsl 8 -fngi 6 -fcbm 6 -fcps2 1 -fdctl 4 -fgsw 5 -fgswr 6 -o ddr.conf\n");

	printf("\n");			
}

void parse_args1(int argc, char *argv[])
{
	int i;
	u32 x;
	char *str;
	if (argc >= 2) {
		for (i=1; i<argc; i++) {
			str = argv[i];
			if (strcmp(str, "-h") == 0 || strcmp(str, "--help") == 0) {
				syntax();
				return;					
			}
			else if (strcmp(str, "-type") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x!=2 && x!=3){
						printf("Incorrect type input\n");
						return;
					}
					ddr_type = x;
				}
			}
			else if (strcmp(str, "-grade") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if ((ddr_type==2 && x!=0 && x!=2 && x!=4 && x!=5 && x!=6 && x!=7 && x!=9) ||
						(ddr_type==3 && x>10)) {
						printf("Incorrect grade input\n");
						return;
					}
					ddr_grade = x;			
				}
			}
			else if (strcmp(str, "-rank") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x!=1 && x!=2){
						printf("Incorrect rank input\n");
						return;
					}
					ddr_rank = x;
				}
			}	
					
			else if (strcmp(str, "-density") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if ((ddr_type==2 && x>9 ) ||
						(ddr_type==3 && (x>10 || x<2))) {
						printf("Incorrect density input\n");
						return;
					}
					ddr_density = x;
				}		
			}	
			else if (strcmp(str, "-bl") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x!=4 && x!=8){
						printf("Incorrect BL input x=%d\n", x);
						return;
					}
					ddr_blen = x;
				}
			}
			else if (strcmp(str, "-al") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if ((ddr_type==2 && x>6) ||
						(ddr_type==3 && x>2)) {
						printf("Incorrect AL input\n");
						return;
					}
					ddr_al = x;
				}
			}	
			else if (strcmp(str, "-endian") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>1){
						printf("Incorrect endian input\n");
						return;
					}
					endianness = x;
				}
			}		
			else if (strcmp(str, "-o") == 0) {
				g_output = 1;
				i++;
				strncpy(filename, argv[i], strlen(argv[i]));
			}	
			else if (strcmp(str, "-fcps") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>17) {
						printf("Incorrect CPS frequency input\n");
						return;
					}
					fcps = x;
				}
			}
			else if (strcmp(str, "-fsl") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>16) {
						printf("Incorrect Share Link frequency input\n");
						return;
					}
					fsl = x;
				}
			}
			else if (strcmp(str, "-fngi") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>16) {
						printf("Incorrect NGI frequency input\n");
						return;
					}
					fngi = x;
				}
			}	
			else if (strcmp(str, "-fcbm") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>16) {
						printf("Incorrect CBM frequency input\n");
						return;
					}
					fcbm = x;
				}
			}		
			else if (strcmp(str, "-fcps2") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>16) {
						printf("Incorrect alternative CPS frequency input\n");
						return;
					}
					fcps2 = x;
				}
			}
			else if (strcmp(str, "-fdctl") == 0) {
				if (i == argc - 1) 
					syntax();
					else {
					i++;
					x = atoi(argv[i]);
					if (x>16) {
						printf("Incorrect DDR Ctrl frequency input\n");
						return;
					}
					fdctl = x;
				}
			}
			else if (strcmp(str, "-fgsw") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>16) {
						printf("Incorrect GSW frequency input\n");
						return;
					}
					fgsw = x;
				}
			}	
			else if (strcmp(str, "-fgswr") == 0) {
				if (i == argc - 1) 
					syntax();
				else {
					i++;
					x = atoi(argv[i]);
					if (x>16) {
						printf("Incorrect GSW-R frequency input\n");
						return;
					}
					fgswr = x;
				}
			}	
			else if (strcmp(str, "-sr0") == 0) {
				if ((i == argc-1) || (i == argc-2)) 
					syntax();
				else {
					i++;
					if (atoi(argv[i])>63 || atoi(argv[i+1])>63) {
						printf("Incorrect Pre-seed Rank 0 input\n");
						return;
					}
					sr0[0] = atoi(argv[i]);
					i++;
					sr0[1] = atoi(argv[i]);		
				}
			}	
			else if (strcmp(str, "-sr1") == 0) {
				if ((i == argc-1) || (i == argc-2)) 
					syntax();
				else {
					i++;
					if (atoi(argv[i])>63 || atoi(argv[i+1])>63) {
						printf("Incorrect Pre-seed Rank 1 input\n");
						return;
					}
					sr1[0] = atoi(argv[i]);
					i++;
					sr1[1] = atoi(argv[i]);		
				}
			}
			else {
				printf("Invalid input\n");
				return;
			}
		}
	} 
	else if (argc == 1)
		syntax();

	printf("Summary: \n");
	printf("\tType:%d Grade:%d Density:%d BL:%d AL:%d Rank:%d Endian:%d SR0:%d %d SR1:%d %d\n", 
	ddr_type, ddr_grade, ddr_density, ddr_blen, ddr_al, ddr_rank, endianness, sr0[0], sr0[1], sr1[0], sr1[1]);	

	if (fcps < 16) { 
		cgu_pll0a_cfg1 = 0x40400000 + (fcps <<12) + (fsl <<8) + (fngi<<4) + (fcbm );
	} else {
		cgu_pll0a_cfg1 = 0x60400000 + (   3<<12)  + (fsl <<8) + (fngi<<4) + (fcbm );
	}
	cgu_pll0b_cfg1 = 0x40400000 + (fcps2<<12) + (fdctl<<8) + (fgsw<<4) + (fgswr);	
	printf("\tcgu_pll0a_cfg1: 0x%08x\n", cgu_pll0a_cfg1);
	printf("\tcgu_pll0b_cfg1: 0x%08x\n", cgu_pll0b_cfg1);
	if (g_output)
		printf("\tdram.conf generated\n");	
	else
		printf("\tOutput disabled\n");

}

/************************************************************************
 *  Implementation : Public functions
 ************************************************************************/
int main(int argc, char *argv[])
{
	u8 n, max, min, p0, p1;
	u32 i, rank, dxreg, x0, x1, cmd, read_reg = 0;
	struct ddr_settings  ds;
 	
	parse_args1(argc, argv);
	
	fp = fopen(filename, "w+");
	if (!fp) {
		syntax();
		return 0;
	}
	
	setup_ddr(&ds);
 
	// BIG_ENDIAN
	if (endianness == 1)
		cmd = 0xdfffff;	
	else 
		cmd = 0x200000; 
	__prt_wr("NGI_ENDIAN", 0xb608005c, cmd);
	
	__delay();

	for (i=0; i<16; i++){
	    cmd = 0x0014a315;
	    __prt_wr("PUB_RIDR", PUB_RIDR_REG_addr, cmd);
    }
      
	if (ddr_type == 2 || gate_ext != 1)      
		cmd = 0xf004641f;
	else
		cmd = 0xf004645f;
    __prt_wr("PUB_DSGCR", PUB_DSGCR_REG_addr, cmd);
    
	/*MEMMAX, FMT initialization*/
    memmax_init(&ds);
    fmt_init(); 
    
	/*uPCTL initialization*/
	// s1
	cmd = (ds.xDDR_TOGCNT1U);
	__prt_wr("TOGCNT1U", TOGCNT1U_REG_addr, cmd);
	cmd = (ds.xDDR_TINIT);
	__prt_wr("TINIT", TINIT_REG_addr, cmd);
	cmd = (ds.xDDR_TOGCNT100N);
	__prt_wr("TOGCNT100N", TOGCNT100N_REG_addr, cmd);
	cmd = (ds.xDDR_TRSTH);		
	__prt_wr("TRSTH", TRSTH_REG_addr, cmd);
	cmd = (ds.xDDR_TRSTL);		
	__prt_wr("TRSTL", TRSTL_REG_addr, cmd);

	// s2	
	cmd = ((((ds.xDDR_TFAW_CFG)-4)<<18) + (((ddr_type)-2)<<5) + ((ddr_blen==8)?(1):(0)));
	__prt_wr("MCFG", MCFG_REG_addr, cmd);
	cmd = ((ds.xDDR_TFAW_CFG_OFF)<<8);
	__prt_wr("MCFG1", MCFG1_REG_addr, cmd);
  
	/*PHY powered up & initialization*/	 
	// s3
	cmd = (ds.xDDR_DCR); 
	__prt_wr("PUB_DCR", PUB_DCR_REG_addr, cmd);
	cmd = (ds.xDDR_MR0);				
	__prt_wr("PUB_MR0", PUB_MR0_REG_addr, cmd);
	cmd = (ds.xDDR_MR1);				
	__prt_wr("PUB_MR1", PUB_MR1_REG_addr, cmd);
	cmd = (ds.xDDR_MR2);				
	__prt_wr("PUB_MR2", PUB_MR2_REG_addr, cmd);
	cmd = (ds.xDDR_MR3);
	__prt_wr("PUB_MR3", PUB_MR3_REG_addr, cmd);
	cmd = ((ds.xDDR_TRC)<<26) + ((ds.xDDR_TRRD)<<22) + ((ds.xDDR_TRAS)<<16) + ((ds.xDDR_TRCD)<<12) + 
                                ((ds.xDDR_TCL)<<8)  + ((ds.xDDR_TWTR)<<4)  + (ds.xDDR_TRTP);     	
                                //TRP always = TCL                               
	__prt_wr("PUB_DTPR0", PUB_DTPR0_REG_addr, cmd);
	cmd = ((ds.xDDR_TAOND)<<30) + ((((ddr_type)==2)?(8):(ds.xDDR_TWLO))<<26) + 
   									  ((((ddr_type)==2)?(40):(ds.xDDR_TWLMRD))<<20) + ((ds.xDDR_TRFC)<<11) + 
									  ((ds.xDDR_TFAW)<<5) + 
   									  ((((ddr_type)==2)?(4):((ds.xDDR_TMOD)-12))<<2) + (((ddr_type)==2)?
									  (ds.xDDR_TMRD):((ds.xDDR_TMRD)-4));
   								//Some unused in DDR2, keep default
	__prt_wr("PUB_DTPR1", PUB_DTPR1_REG_addr, cmd);
	
	cmd = (((ds.xDDR_TCCD)>4)?(1<<31):(0)) + ((ds.xDDR_TDLLK)<<19) + ((ds.xDDR_TCKE)<<15) + 
   								 	  ((ds.xDDR_TXP)<<10) + (ds.xDDR_TXS) + (1<<30); 
	__prt_wr("PUB_DTPR2", PUB_DTPR2_REG_addr, cmd);
   
	cmd = (((ddr_type)==2)?(0x00f00000):(0x00f80000)) + (ds.xDDR_TREFPRD);
   								//DDR3 uses Fixed Latency				
	__prt_wr("PUB_PGCR2", PUB_PGCR2_REG_addr, cmd);

	cmd = (ds.xDDR_TPHYRST) + ((ds.xDDR_TPLLGS)<<6) + ((ds.xDDR_TPLLPD)<<21);
	__prt_wr("PUB_PTR0", PUB_PTR0_REG_addr, cmd);
	cmd = (ds.xDDR_TPLLRST) + ((ds.xDDR_TPLLLOCK)<<16);					
	__prt_wr("PUB_PTR1", PUB_PTR1_REG_addr, cmd);
	cmd = (ds.xDDR_TCALON) + ((ds.xDDR_TCALS)<<5) + ((ds.xDDR_TCALH)<<10) + ((ds.xDDR_TWLDLYS)<<15);
	__prt_wr("PUB_PTR2", PUB_PTR2_REG_addr, cmd);
   
	/* PHY Default, support 2 ranks */  

	if (ddr_type == 2 || gate_ext != 1)
		cmd  = 0x44181224;
	else
		cmd  = 0x44181ee4;
	__prt_wr("PUB_DXCCR_REG_addr", PUB_DXCCR_REG_addr, cmd);
	cmd = 0x7c001e81;
	__prt_wr("PUB_DX0GCR_REG_addr", PUB_DX0GCR_REG_addr, cmd);
	cmd = 0x7c001e81;
	__prt_wr("PUB_DX1GCR_REG_addr", PUB_DX1GCR_REG_addr, cmd);

	if (ddr_type == 2)
		if (ddr_grade < 6) {
			cmd = 0x104b;	//Rodt(Rtt) = 75 Ohm, Rods(output drive) = 40 Ohm - <=333MHz
			__prt_wr("PUB_ZQ0CR1", PUB_ZQ0CR1_REG_addr, cmd);
		}
		else {
			cmd = 0x101b;	//Rodt(Rtt) = 150 Ohm, Rods(output drive) = 40 Ohm - >=400MHz
			__prt_wr("PUB_ZQ0CR1", PUB_ZQ0CR1_REG_addr, cmd);
		}
	else {
		//GATE_EXT or OTHERS
		cmd = 0x105d;
		__prt_wr("PUB_ZQ0CR1", PUB_ZQ0CR1_REG_addr, cmd);
	}

	/* PUB PHY initialization page 51 */
	// - At reset, the PHY moves into the PLL initialization lock phase. This phase may be 
	//   bypassed at any time by writing a '1' to the PLL initialization bypass register bit (PIR[LOCKBYP]). 
	// - In parallel to PLL initialization, the impedance calibration phase also starts at reset de-assertion. This 
	//   phase can also be bypassed by writing a '1' to bit PIR[ZCALBYP]
	// - Once the PLL is initialized, the delay calibration phase starts. This phase can also be bypassed by 
	//   writing a '1' to bit PIR[DCALBYP]. 
	// - Special to emulation: set DCALBYP (Digital Delay Line Calibration) and ZCALBYP (Impedance Calibration) so 
	//   that calibration of data delay lines and termination resistor is skipped
	// - Since the clocks to the PHY are not stable until after the PLL is locked and the delay lines are 
	//   calibrated, the initialization phase waits a few programmable clock cycles in the PHY initialization 
	//   reset phase before de-asserting the reset to the PHY.   
   
	read_reg = 0;
	__prt_rd("PUB_PIR", PUB_PIR_REG_addr, read_reg);			//default = 0

	// Wait until the lower 4 bits are set:
	// Bit 0: IDONE: PHY initialization done
	// Bit 1: PLDONE: PLL lock done
	// Bit 2: DCDONE: Digital Delay Line calibration done 
	// Bit 3: ZCDONE: Impedance Calibration done
	// Bit 4: DIDONE: DRAM Initialization Done
	// Bit 20: ZCERR : Impedance Calibration Error
	// Bit 28: PLDONE_CHN 0: PLL Lock Done channel 0
	// Bit 29: PLDONE_CHN 1: PLL Lock Done channel 1
	// Bit 31: APLOCK: AC PLL has locked
	// There are the following value transitions in Synopsys' DDR3 reference simulation with behavioral 
	// PHY model: 
	// 0x00000000 => 0x30000002 => 0xb0000002 => 0xb0000006 => 0xb000000e => 0xb000000f

	// s4
         // In emulation ZCERR (Impedance Calibration Error) bit (bit#20) is set although in case
         // a) Z calibration is not bypassed: Z calibration state machine finishs (Z_DONE), but the
         //    previously set ZCERR is not reset. 
         // b) Z calibration is bypassed: Z_DONE is directly set by bypassing the calibration state 
         //    machine, nethertheless ZCERR is set as before. In reference simulation (with encrypted 
         //    PHY model) ZCERR it is not set. To be clarified
    read_reg = 0xb000000f;
    __prt_rd("PUB_PGSR0", PUB_PGSR0_REG_addr, read_reg);

	//DATX8 Local Calibrated Delay Line Register 2 (DXnLCDLR2)
	//[7:0]   R0DQSGD    Rank 0 Read DQS Gating Delay: Rank 0 delay select for the read DQS gating (DQSG) LCDL
	//[15:8]  R1DQSGD    Rank 1 Read DQS Gating Delay: Rank 1 delay select for the read DQS gating (DQSG) LCDL
	cmd = 0x6e6e;
	__prt_wr("PUB_DX0LCDLR2", PUB_DX0LCDLR2_REG_addr, cmd);
	cmd = 0x6e6e;
	__prt_wr("PUB_DX1LCDLR2", PUB_DX1LCDLR2_REG_addr, cmd);

	// PIR = PHY initialization register
	// Bit  0: INIT 1    => Triggers DDR initialization (PHY, DDR, ... depending on the other bit settings)
	// Bit 18: CTLDINT 1 => Controller DRAM initialization, performed by DRAM controller
	cmd = 0x00040001;
	__prt_wr("PUB_PIR", PUB_PIR_REG_addr, cmd);
 
	// Wait on initialized DRAM
    read_reg = 0xb000001f; 
    __prt_rd("PUB_PGSR0", PUB_PGSR0_REG_addr, read_reg);

	/*Memory powered up*/  
	// s5
	read_reg = 0x00000001; 
    __prt_rd("DFISTSTAT0", DFISTSTAT0_REG_addr, read_reg);

	// s6
	cmd = 0x00000001;
	__prt_wr("POWCTL", POWCTL_REG_addr, cmd);
	// wait on memory power-on sequence finished.
    read_reg = 0x00000001; 
     __prt_rd("POWSTAT", POWSTAT_REG_addr, read_reg);
      
	/*Memory initialization*/   
	// s7
	mem_t(&ds);

	cmd = 0x00004780;																
	__prt_wr("SCFG", SCFG_REG_addr, cmd);

	// s8
	dfi_t(&ds);		
	cmd = 0x00000007;
	__prt_wr("DFIUPDCFG", DFIUPDCFG_REG_addr, cmd);

	// s9
	// Memory command register:
	// bit 31: start command (is reset by uPCTL when command executed)
	// bit 27:24: command additional delay
	// bit 23:20: rank select (1111 means broadcast)
		
	cmd = 0x86f00000;		//Deselect
	__prt_wr("MCMD", MCMD_REG_addr, cmd);
    read_reg = cmd&0x7fffffff; 
    __prt_rd("MCMD", MCMD_REG_addr, read_reg);
	__delay();
	
    if ((ddr_type)==2) {
		cmd = 0x80f00001;	//PreA
		__prt_wr("MCMD", MCMD_REG_addr, cmd);
		read_reg = cmd & 0x7fffffff; 
		__prt_rd("MCMD", MCMD_REG_addr, read_reg); 
		__delay();		   
    }

	cmd = (0x80f40003 | ((ds.xDDR_MR2)<<4));	
	__prt_wr("MCMD", MCMD_REG_addr, cmd);
    read_reg = cmd & 0x7fffffff; 
    __prt_rd("MCMD", MCMD_REG_addr, read_reg);
	__delay();
	
	cmd = (0x80f60003 | ((ds.xDDR_MR3)<<4));
	__prt_wr("MCMD", MCMD_REG_addr, cmd);
    read_reg = cmd & 0x7fffffff; 
    __prt_rd("MCMD", MCMD_REG_addr, read_reg);
	__delay();
   
	cmd = (0x80f20003 | ((ds.xDDR_MR1)<<4));				//PLL enabled by pre-defined
	__prt_wr("MCMD", MCMD_REG_addr, cmd);
    read_reg = cmd & 0x7fffffff; 
    __prt_rd("MCMD", MCMD_REG_addr, read_reg);
	__delay();

	cmd = (0x80f00003 | ((ds.xDDR_MR0)<<4));				//PLL reset=1 by pre-defined
	__prt_wr("MCMD", MCMD_REG_addr, cmd);
    read_reg = cmd & 0x7fffffff; 
    __prt_rd("MCMD", MCMD_REG_addr, read_reg);
	__delay();
	
    if  ((ddr_type)==2) {
		cmd = 0x80f00001;	//PreA
		__prt_wr("MCMD", MCMD_REG_addr, cmd);
		read_reg = cmd & 0x7fffffff; 
		__prt_rd("MCMD", MCMD_REG_addr, read_reg);    
		__delay();
		
		cmd = 0x80f00002;	//Refresh
		__prt_wr("MCMD", MCMD_REG_addr, cmd);
		read_reg = cmd & 0x7fffffff; REG32(MCMD_REG_addr);
		__prt_rd("MCMD", MCMD_REG_addr, read_reg);
		__delay();
		
		cmd = 0x80f00002;	//Refresh
		__prt_wr("MCMD", MCMD_REG_addr, cmd);
			read_reg = cmd & 0x7fffffff;
			__prt_rd("MCMD", MCMD_REG_addr, read_reg);
        __delay();  
	   
		cmd = (0x80f00003 | (((ds.xDDR_MR0)&(~0x100))<<4)); 	//PLL reset=0, for timing programming
		__prt_wr("MCMD", MCMD_REG_addr, cmd);
		read_reg = cmd & 0x7fffffff;
		__prt_rd("MCMD", MCMD_REG_addr, read_reg);  
		__delay();	
	   
		cmd = (0x80f20003 | ((ds.xDDR_MR1)<<4));				//OCD
		__prt_wr("MCMD", MCMD_REG_addr, cmd);
		read_reg = cmd & 0x7fffffff; 
		__prt_rd("MCMD", MCMD_REG_addr, read_reg);
		__delay();
	}

	cmd = 0x80f00005;		//ZQ Calibration Long
	__prt_wr("MCMD", MCMD_REG_addr, cmd);
      read_reg = cmd & 0x7fffffff;
      __prt_rd("MCMD", MCMD_REG_addr, read_reg);
	__delay(); 

	// s10 
	cmd = 0x80f0000a;		//DFI Controller Update
	__prt_wr("MCMD", MCMD_REG_addr, cmd);
    read_reg = cmd & 0x7fffffff; 
    __prt_rd("MCMD", MCMD_REG_addr, read_reg);
	__delay();
   
	/*Move uPCTL into config status*/   
	// s11
	// operational state control register 
	// bits(2:0) = 1: move to cfg state
	cmd = 0x00000001;
	__prt_wr("SCTL", SCTL_REG_addr, cmd);
    read_reg = 0x00000001; 
    __prt_rd("STAT", STAT_REG_addr, read_reg);
      
	/*Refine configuration*/   
	// s12	
	cmd = 0x00000000; 
	__prt_wr("PPCFG", PPCFG_REG_addr, cmd);	
	cmd = 0x00000007;	
	__prt_wr("DFISTCFG0", DFISTCFG0_REG_addr, cmd);
	cmd = 0x00000003;
	__prt_wr("DFISTCFG1", DFISTCFG1_REG_addr, cmd);
	cmd = 0x00000000;
	__prt_wr("DFISTCFG2", DFISTCFG2_REG_addr, cmd);
	cmd = 0x00070101; 
	__prt_wr("DFILPCFG0", DFILPCFG0_REG_addr, cmd);
	cmd = 0x00000000;
	__prt_wr("ECCCFG", ECCCFG_REG_addr, cmd);	
	cmd = 0x00000003;
	__prt_wr("DFIUPDCFG", DFIUPDCFG_REG_addr, cmd);

	// s13
	cmd = 0x00000001;
	__prt_wr("CMDSTATEN", CMDSTATEN_REG_addr, cmd);
    read_reg = 0x00000001; 
    __prt_rd("CMDSTAT", CMDSTAT_REG_addr, read_reg);

	/* Move uPCTL into access state */
    // s16
    cmd = 0x00000002;     
    __prt_wr("SCTL", SCTL_REG_addr, cmd);
	read_reg = 0x00000003; 
    __prt_rd("STAT", STAT_REG_addr, read_reg);
  
/****************************/
/*  Clock Change Procedure  */
/****************************/

	// Issue sleep command to controller to low power state
    cmd = 0x00000003;     
    __prt_wr("SCTL", SCTL_REG_addr, cmd);
	read_reg = 0x00000045; 
	__prt_rd("STAT", STAT_REG_addr, read_reg);  

	// change DDR clock freq 
	cmd = cgu_pll0a_cfg1;
	__prt_wr("PLL0A_CFG1", 0xb6200008, cmd);
	cmd = cgu_pll0b_cfg1;	
	__prt_wr("PLL0B_CFG1", 0xb6200038, cmd);
	__delay();
	
	// issue pll reset
    cmd = 0x40000000;
    __prt_wr("PUB_PLLCR", PUB_PLLCR_REG_addr, cmd);
   	__delay();  
    cmd = 0x0001c000;	
    __prt_wr("PUB_PLLCR", PUB_PLLCR_REG_addr, cmd);	

	//clear status bits pgsr resgister bits
   	cmd = 0x08000000; 
   	__prt_wr("PUB_PIR", PUB_PIR_REG_addr, cmd);	

	read_reg = 0xb0000017; 
	__prt_rd("PUB_PGSR0", PUB_PGSR0_REG_addr, read_reg); 
	__delay();
			
	/*
		PIR[0] Initialization Trigger
		PIR[1] Impedance Calibration: impedance calibration performed in parallel with PHY initialization 
				(PLL initialization + DDL calibration + PHY reset).
	 	PIR[4] PLL Initialization: Executes the PLL initialization, including driving of PLL power-down, 
	 			reset and gear shift pins, and then waiting for the PHY PLLs to lock.
	 	PIR[5] Digital Delay Line (DDL) Calibration: Performs PHY DL & VT calibration .		
	*/
	cmd = 0x00000033; 	
   	__prt_wr("PUB_PIR", PUB_PIR_REG_addr, cmd);
	read_reg = 0xb000001f; 
	__prt_rd("PUB_PGSR0", PUB_PGSR0_REG_addr, read_reg);         	
	
	// move upctl to power up state
	cmd = 0x00000004;     
    __prt_wr("SCTL", SCTL_REG_addr, cmd);
	read_reg = 0x00000003; 
	__prt_rd("STAT", STAT_REG_addr, read_reg);
	__delay(); 

	/*******************************************************
	*   TRAINING STARTS                                    *
	*******************************************************/

	//move upctl to config state
	cmd = 0x00000001;     
    __prt_wr("SCTL", SCTL_REG_addr, cmd);
	read_reg = 0x00000001; 
	__prt_rd("STAT", STAT_REG_addr, read_reg);
	__delay();
	
	for (rank=0; rank<ddr_rank; rank++) {	
		if (ddr_type == 2)	
			cmd = 0x90007887 | (((ddr_rank)==2?3:1)<<24) | (rank<<4);
		else {
			if ((ddr_grade)>5)
				cmd = 0x900035c7 | (((ddr_rank)==2?3:1)<<24) | (rank<<4);	
							//def=0x93003587 high freq uses 1/4CK 0x910035c7
			else
				cmd = 0x900078c7 | (((ddr_rank)==2?3:1)<<24) | (rank<<4);	
							//def=0x93003587 low freq uses margin override
		}
		__prt_wr("PUB_DTCR", PUB_DTCR_REG_addr, cmd);

		//clear status bits pgsr resgister bits
    	cmd = 0x08000000;
    	__prt_wr("PUB_PIR", PUB_PIR_REG_addr, cmd);
		read_reg = 0xb0000017; 
		__prt_rd("PUB_PGSR0", PUB_PGSR0_REG_addr, read_reg);
		__delay();

		seed(0, (rank==0)?sr0[0]:sr1[0], 0);	
		seed(1, (rank==0)?sr0[1]:sr1[1], 0);	

		if (ddr_type == 2) {
			cmd = 0xf401; 
			__prt_wr("PUB_PIR", PUB_PIR_REG_addr, cmd);
			read_reg = 0xb0000f57;          
			__prt_rd("PUB_PGSR0", PUB_PGSR0_REG_addr, read_reg);
		}
		else  {
			cmd = 0xfe01;
			__prt_wr("PUB_PIR", PUB_PIR_REG_addr, cmd);
			read_reg = 0xb0000ff7; 
			__prt_rd("PUB_PGSR0", PUB_PGSR0_REG_addr, read_reg);
		}
	}
	
	//move upctl back to access state
	cmd = 0x2;     
    __prt_wr("SCTL", SCTL_REG_addr, cmd);
    read_reg = 0x3; 
	__prt_rd("STAT", STAT_REG_addr, read_reg);

	fclose(fp);
	
	return 0;
}
