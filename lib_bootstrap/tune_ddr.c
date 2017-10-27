/*****************************************************************************
 * CPE Chip Rev1 DDR TUNING
 * Support : Danube, ARX, VRX & HNX Platform
 *
 * IFAP DC COM SD
 * 10June2011	Andrei Toma Change rev to 03.d after adding support for HN1
 *****************************************************************************/
#include <config.h>
#include <common.h>
#include <command.h>
#include <asm/addrspace.h>

#ifdef CONFIG_LANTIQ_UBOOT_ar9
#define ARX_CHIP
#include <asm/ar9.h>
#elif defined(CONFIG_LANTIQ_UBOOT_danube)
#define DANUBE_CHIP
#elif defined(CONFIG_LANTIQ_UBOOT_vr9)
#define VRX_CHIP
#elif defined(CONFIG_LANTIQ_UBOOT_ar10)
#define VRX_CHIP
#elif defined(CONFIG_LANTIQ_UBOOT_hn1)
#include <asm/hn1.h>
#define HNX_CHIP
#endif

#define asc_puts serial_puts
#define asc_putc serial_putc

u8 mode;
u8 cur_state=0;
u32 ddrsize,chipid;


//;boot_data bootrom;
#define DEBUGMODE 0         // debug mode will display more info of auto-tuning result

#ifdef ARX_CHIP // ARX CHIP
#define READMIN 0
#define READMAX 0x3f
#define READMIN_Q 0x1
#define READMAX_Q 0x20
#define DQSOUTSHIFT 0x68
#define WRITEDQS_Q 0x3e
#define WRITEMIN 0x27
#define WRITEMAX 0x67
#define MC_START 0xbf801030
#define REG01   0xBE1A7F10
#define REG02   0xBE1A7F14
#define REG03   0xBE1A7F18
#define REG04   0xBE1A7F1C
#define STATUS  0xBE1A7F20
#endif

#ifdef DANUBE_CHIP // DANUBE CHIP
#define READMIN 0
#define READMAX 0x3f
#define READMIN_Q 0x1
#define READMAX_Q 0x20
#define DQSOUTSHIFT 0x64
#define WRITEDQS_Q 0x3e
#define WRITEMIN 0x24
#define WRITEMAX 0x64
#define MC_START 0xbf801030
#define REG01   0xBE1A5F10
#define REG02   0xBE1A5F14
#define REG03   0xBE1A5F18
#define REG04   0xBE1A5F1C
#define STATUS  0xBE1A5F20
#endif


#if defined(VRX_CHIP) || defined(HNX_CHIP) // VRX or HNX CHIPs
  #ifdef CONFIG_LANTIQ_UBOOT_ar10
    #define READMIN 		0
    #define READMAX 		0x3f
    #define READMIN_Q 		0x15
    #define READMAX_Q 		0x2b
    #define WRITEDQS_Q 		0x1f
    #define WRITEMIN 		0x00
    #define WRITEMAX 		0x3f
    #define MC_START 		0xbf801000 //DDR_CCR00  start bit address
    #define REG01   		0xBE1A7F10 //PPE SB buffer address 
    #define REG02   		0xBE1A7F14 //PPE SB buffer address
    #define REG03   		0xBE1A7F18 //PPE SB buffer address
    #define REG04   		0xBE1A7F1C //PPE SB buffer address
    #define REG05   		0xBE1A7F20 //PPE SB buffer address
    #define REG06   		0xBE1A7F24 //PPE SB buffer address
    #define STATUS  		0xBE1A7F2C //PPE SB buffer address
  #else
    #define READMIN 0
    #define READMAX 0x3f
    #define READMIN_Q 0x15
    #define READMAX_Q 0x2b
    #define WRITEDQS_Q 0x55
    #define WRITEMIN 0x40
    #define WRITEMAX 0x7f
    #define MC_START     0xbf401070
    #if defined(HNX_CHIP)
      #define REG01   0xBF28FF10
      #define REG02   0xBF28FF14
      #define REG03   0xBF28FF18
      #define REG04   0xBF28FF1C
      #define REG05   0xBF28FF20
      #define REG06   0xBF28FF24
      #define STATUS  0xBF28FF2C
    #else
      #define REG01   0xBE22FF10
      #define REG02   0xBE22FF14
      #define REG03   0xBE22FF18
      #define REG04   0xBE22FF1C
      #define REG05   0xBE22FF20
      #define REG06   0xBE22FF24
      #define STATUS  0xBE22FF2C
	#endif
  #endif
#endif




#ifdef CONFIG_LANTIQ_UBOOT_ar10
  #define MC_RD_SLICE0  	0xBF801460     // RD DATA SLICE#0
	#define MC_RD_SLICE1  	0xBF801480     // RD DATA SLICE#1
	#define MC_WR_SLICE0  	0xBF801470     // WR DATA SLICE#0
	#define MC_WR_SLICE1  	0xBF801490     // WR DATA SLICE#1
	#define MC_DLL_SLICE0 	0xBF8014B0     // DLL LOCKED SLICE#0
	#define MC_DLL_SLICE1 	0xBF8014E0     // DLL LOCKED SLICE#1
	#define MC_INT_STAT     0xBF801250
	#define DDR_ECHO_DLL0   0xBF8001D8
	#define DDR_ECHO_DLL1   0xBF8001E0
#else
  /* VRX Memory controller register for data-eye tuning */
  #define MC_RD_SLICE0    0xBF401270
  #define MC_RD_SLICE1    0xBF401280
  #define MC_WR_SLICE0    0xBF4012B0
  #define MC_WR_SLICE1    0xBF4012C0
  #define MC_DLL_SLICE0   0xBF4012F0
  #define MC_DLL_SLICE1   0xBF401300
  #define MC_INT_STAT     0xBF401160
  #define DDR_ECHO_DLL0   0xBF400420
  #define DDR_ECHO_DLL1   0xBF400428
#endif

  



/* ARX & Danube Memory controller register for data-eye tuning */
#define MC_STAT  0xBF800070     // DLL lock status
#define MC_DC15	 0xBF8010F0     // WRITE DQS
#define MC_DC21	 0xBF801150     // Data Slice 0
#define MC_DC22	 0xBF801160     // Data Slice 1
#define MC_DC24	 0xBF801180     // DQS Out Shift

// Declare a reference to the global pointer
extern unsigned int _gp;

//extern void cache_enable();
//extern u32 dma_memcopy_test();

#ifdef ARX_CHIP
/******************************************************************************
 * Local routines
 ******************************************************************************/

#define DFE_BASE_ADDR         0xBE116000
#define mei_dbg_deco_c        (DFE_BASE_ADDR + 0x00000030)
#define mei_fr_arcint_c       (DFE_BASE_ADDR + 0x0000001C)
#define mei_dbg_master_c      (DFE_BASE_ADDR + 0x0000003C)
#define mei_dbg_waddr_c       (DFE_BASE_ADDR + 0x00000024)
#define mei_dbg_raddr_c       (DFE_BASE_ADDR + 0x00000028)
#define mei_dbg_data_c        (DFE_BASE_ADDR + 0x0000002C)

#define ADSL_BASE 0x20000
#define CRI_BASE          ADSL_BASE + 0x11F00
#define CRI_CCR0          CRI_BASE + 0x00
#define CRI_CCR1          CRI_BASE + 0x01*4
#define CRI_UPDCTL        CRI_BASE + 0x0D*4
#define CRI_EVENT0        CRI_BASE + 0x10*4
#define CRI_EVENT1        CRI_BASE + 0x11*4
#define CRI_EVENT2        CRI_BASE + 0x12*4
//#define REG32(addr)		   *((volatile u32 *)(addr))
// Register Definitions
#define aux_access 0x0
#define dmp_access 0x1 // or 0x2
#define core_access 0x3

#define iri_i_enable	0x32000
#define sty_smode	0x3c004

#define afe_tcr_0	0x3c0dc
#define afe_addr_addr	0x3c0e8
#define afe_rdata_addr	0x3c0ec
#define afe_wdata_addr	0x3c0f0
#define afe_config	0x3c0f4
#define afe_serial_cfg	0x3c0fc


u32 mei = 0x1;
u32 jtag = 0x0;
u32 dmp_core_access = 0x2;

void mei_master(u32 mode){
  REG32(mei_dbg_master_c) = mode; // MEI as the master
};

void poll_status(void){
  while( (REG32(mei_fr_arcint_c) & 0x20) != 0x20 ){};
};

void mei_dmp_acc(void){
  REG32(mei_dbg_deco_c) = dmp_access;
};

u32 ReadARCmem(u32 addr){
  u32 data;
  mei_master(mei);
  mei_dmp_acc();
  REG32(mei_dbg_raddr_c) = addr;
  poll_status();
  data = REG32(mei_dbg_data_c);
  mei_master(jtag);
  return data;
};

void WriteARCmem(u32 addr, u32 data){
  mei_master(mei);
  mei_dmp_acc();
  REG32(mei_dbg_waddr_c) = addr;
  REG32(mei_dbg_data_c) = data;
  poll_status();
  mei_master(jtag);
};

u32 afe_reg_read(u32 addr)
{
	WriteARCmem(CRI_EVENT2,0x20);
	WriteARCmem(afe_addr_addr,addr);
	WriteARCmem(afe_rdata_addr,0x0);
	while((ReadARCmem(CRI_EVENT2)&0x20)!=0x20);
	return(ReadARCmem(afe_rdata_addr));
}

u16 afe_reg_write(u32 addr,u32 data)
{
	WriteARCmem(afe_addr_addr,addr);
	WriteARCmem(afe_wdata_addr,data);
	while((ReadARCmem(CRI_EVENT2)&0x20)!=0x20);
	return 0;
}

u16 enable_afe()
{	
	u32	read_data,i;

	read_data = REG32(0xbf10201c);
	REG32(0xbf10201c) = read_data & 0xffff7dbe;
	//asc_puts("Enabling AFE....\n");
	/* Start the clock */
	WriteARCmem(CRI_UPDCTL, 0x08);
	WriteARCmem(CRI_CCR0, 0x14);
	WriteARCmem(CRI_CCR1, 0x500); 
	WriteARCmem(afe_config,0x01c8); 
	WriteARCmem(afe_serial_cfg,0x16); // (DANUBE_PCI_CFG_BASE+(1<<addrline))AFE serial interface clock & data latch edge
	WriteARCmem(afe_tcr_0,0x2);
	//Take afe out of reset
	WriteARCmem(afe_config,0x0c0); 
	WriteARCmem(iri_i_enable,0x0101); 
	WriteARCmem(sty_smode,0x01980); 
	for(i=0;i<0x100;i++);
	afe_reg_write(0x4c,0x3);
	
	return(0);

}
#endif

/*
 *This function create multiple dummy access to ROM space to ensure the MIPS to Xbar path is clear of pending DDR transaction.
 *These dummy cycle is use before disabling the DDR controller to ensure DDR is shut down when it is idle.
**/
void dummy_cycle()
{
    /* Dummy cycle access ROM space in SRAM bus */
    /* These cycle ensure that previous DDR cycle is completed due to in order return nature of x-bar */
    /* These cycle is place Just before DDR controller is disabled */
    REG32(0xbf000000) = REG32(0xbf000004);
    REG32(0xbf000004) = REG32(0xbf000008);
    REG32(0xbf000008) = REG32(0xbf000000);
}

void print_u8(u8 data)
{
   char string[3]={0,0,0};
   char ascii[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

   string[0]=ascii[(data&0xf0)>>4];
   string[1]=ascii[data&0xf];

   asc_puts(string);
}

void print_u32(u32 data)
{
   print_u8( (u8) (data>>24)&0xff);
   print_u8( (u8) (data>>16)&0xff);
   print_u8( (u8) (data>>8)&0xff);
   print_u8( (u8) (data>>0)&0xff);
}

#if 1
void print_state()
{
	switch(cur_state)
	{
		case 0:  asc_puts("\b\b\b[-]");
				 cur_state=1;
				 break;
		case 1:  asc_puts("\b\b\b[\\]");
				 cur_state=2;
				 break;
		case 2:  asc_puts("\b\b\b[|]");
				 cur_state=3;
				 break;
		case 3:  asc_puts("\b\b\b[/]");
				 cur_state=0;
				 break;
	    default: cur_state=0;
	    		 break;
	}
}
#else

void print_state(char c)
{
	asc_puts("\b\b\b["); asc_putc(c);asc_puts("]");
}

#endif

void debug_print(char* s)
{
#ifdef DEBUG
	asc_puts(s);
#else
	 //u32 i;
	 //for(i=0;i<0xff;i++);
#endif
}

#define TESTADDR    0x80100000
#define TESTADDR_UC 0xA0000000
#define CHECK_DQ_LINE_FAIL 0

#if CHECK_DQ_LINE_FAIL

void clear_error(u8* data)
{
    u8 i;

    for(i=0;i<16;i++)
        data[i] =0;
}

u16 check_data_bit_fail(u32 d1, u32 d2, u8* bit)
{
    u8 i;

    for(i=0;i<16;i++)
    {
        if((((u16)d1) & ~(1<<i))!=(((u16)d2) & ~(1<<i)))
            bit[i]=1;
        if((((u16)(d1>>16)) & ~(1<<i))!=(((u16)(d2>>16)) & ~(1<<i)))
            bit[i]=1;
    }
    return(0);
}
#endif

u32 d_pattern[8];
u16 w_pattern[4];
u8  b_pattern[4];

void init_pattern()
{
    b_pattern[0]=0x55;
    b_pattern[1]=0x00;
    b_pattern[2]=0xFE;
    b_pattern[3]=0x01;

    w_pattern[0]=0x5555;
    w_pattern[1]=0xFFFF;
    w_pattern[2]=0x8000;
    w_pattern[3]=0x7FFF;

    d_pattern[0]=0x5555aaaa;
    d_pattern[1]=0xFFFF0000;
    d_pattern[2]=0x80000001;
    d_pattern[3]=0x7FFFFFFE;
    d_pattern[4]=0x12345678;
    d_pattern[5]=0x9ABCDEF0;
    d_pattern[6]=0xC3C3C3C3;
    d_pattern[7]=0xFFFFFFFF;
}

u32 sdramtest(u8 masktype, u8 mode)
{
    u32 j,k,l;
    u32 x;
    u32 mask,pattern;
    u16 wmask;
    u8 bmask;
    //u8  dq_error[16];
    if (masktype == 0) mask =0x00ff00ff;
    else if(masktype==1) mask = 0xff00ff00;
    else mask = 0xffffffff;

    wmask =(u16) mask;
    bmask = (u8) mask;

// Test# 1 32bit short Uncache Access
    //print_state('a');
    for(j=0;j<8;j++)
    {
        for(k=0;k<0x20;k=k+4)
        {
            l=j;
            REG32(TESTADDR_UC+(j<<16)+k)=d_pattern[l];
            REG32(TESTADDR_UC+(ddrsize>>1)+(j<<16)+k)=~d_pattern[l];
        }
    }
    //print_state('b');
    for(j=0;j<8;j++)
    {
        for(k=0;k<0x20;k=k+4)
        {
            l=j;
            x = REG32(TESTADDR_UC+(j<<16)+k);
            if((x&mask)!=(d_pattern[l]&mask))
                return(1);
            x = REG32(TESTADDR_UC+(ddrsize>>1)+(j<<16)+k);
            if((x&mask)!=((~d_pattern[l])&mask))
                return(1);
        }
    }

    if(mode != 1) // Normal mode 1: Quick test
    {
    // Test# 2 16bit Uncache Access
    	//print_state('c');
        for(j=0;j<4;j++)
        {
            for(k=0;k<0x40;k=k+2)
            {
                l=j;
                REG16(TESTADDR_UC+(j<<16)+k)=w_pattern[l];
                REG16(TESTADDR_UC+(ddrsize>>1)+(j<<16)+k)=~w_pattern[l];
            }
        }
    	//print_state('d');
        for(j=0;j<4;j++)
        {
            for(k=0;k<0x40;k=k+2)
            {
                l=j;
                x = REG16(TESTADDR_UC+(j<<16)+k);
                if((x&wmask)!=(w_pattern[l]&wmask))
                    return(1);
                x = REG16(TESTADDR_UC+(ddrsize>>1)+(j<<16)+k);
                if((x&wmask)!=((~w_pattern[l])&wmask))
                    return(1);
            }
        }

    // Test# 3 8bit Uncache Access
    	//print_state('e');
        for(j=0;j<4;j++)
        {
            for(k=0;k<0x80;k=k+1)
            {
                l=j;
                REG8(TESTADDR_UC+(j<<16)+k)=b_pattern[l];
                REG8(TESTADDR_UC+(ddrsize>>1)+(j<<16)+k)=~b_pattern[l];
            }
        }
    	//print_state('f');
        for(j=0;j<4;j++)
        {
            for(k=0;k<0x80;k=k+1)
            {
                l=j;
                x = REG8(TESTADDR_UC+(j<<16)+k);
                if((x&bmask)!=(b_pattern[l]&bmask))
                    return(1);
                x = REG8(TESTADDR_UC+(ddrsize>>1)+(j<<16)+k);
                if((x&bmask)!=((~b_pattern[l])&bmask))
                    return(1);
            }
        }

    // Test# 4 32bit Cache Access Random Pattern (short)
    	//print_state('g');
        for(j=0;j<8;j++)
        {
            for(k=0;k<0x100;k=k+4)
            {
                l=(j+(k>>2))%8;
                REG32(TESTADDR+(j<<16)+k)=d_pattern[l];
                REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k)=~d_pattern[l];
            }
        }
    	//print_state('h');
        for(j=0;j<8;j++)
        {
            for(k=0;k<0x100;k=k+4)
            {
                l=(j+(k>>2))%8;
                x = REG32(TESTADDR+(j<<16)+k);
                if((x&mask)!=(d_pattern[l]&mask))
                    return(1);
                x = REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k);
                if((x&mask)!=((~d_pattern[l])&mask))
                    return(1);
            }
        }

    // Test# 5 32bit Cache Access Checker Pattern (short)
        pattern=0x55555555;
    	//print_state('i');
        for(j=0;j<8;j++)
        {
            for(k=0;k<0x400;k=k+4)
            {
                REG32(TESTADDR+(j<<16)+k)=pattern;
                REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k)=~pattern;
            }
        }
    	//print_state('j');
        for(j=0;j<8;j++)
        {
            for(k=0;k<0x400;k=k+4)
            {
                x = REG32(TESTADDR+(j<<16)+k);
                if((x&mask)!=(pattern&mask))
                    return(1);
                x = REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k);
                if((x&mask)!=((~pattern)&mask))
                    return(1);
            }
        }

    // Test# 6 32bit Cache Access Moving 0 & 1 Pattern
    	//print_state('k');
        for(j=0;j<8;j++)
        {
            pattern=0x10001;
            for(k=0;k<0x400;k=k+4)
            {
                REG32(TESTADDR+(j<<16)+k)=pattern;
                REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k)=~pattern;
                pattern=pattern<<1;
                if(pattern==0) pattern=0x10001;
            }
        }
    	//print_state('l');
        for(j=0;j<8;j++)
        {
            pattern=0x10001;
            for(k=0;k<0x400;k=k+4)
            {
                x = REG32(TESTADDR+(j<<16)+k);
                if((x&mask)!=(pattern&mask))
                    return(1);
                x = REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k);
                if((x&mask)!=((~pattern)&mask))
                    return(1);
                pattern=pattern<<1;
                if(pattern==0) pattern=0x10001;
            }
        }

    // Test# 7 32bit Cache Access Random Pattern (long)
    	//print_state('m');
        for(j=0;j<8;j++)
        {
            for(k=0;k<0x4000;k=k+4)
            {
                l=(j+(k>>2)+2)%8;
                REG32(TESTADDR+(j<<16)+k)=d_pattern[l];
                REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k)=~d_pattern[l];
            }
        }
    	//print_state('n');
        for(j=0;j<8;j++)
        {
            for(k=0;k<0x4000;k=k+4)
            {
                l=(j+(k>>2)+2)%8;
                x = REG32(TESTADDR+(j<<16)+k);
                if((x&mask)!=(d_pattern[l]&mask))
                    return(1);
                x = REG32(TESTADDR+(ddrsize>>1)+(j<<16)+k);
                if((x&mask)!=((~d_pattern[l])&mask))
                    return(1);
            }
        }
    }

    return(0);
}

/******************************************************************************
 * Global routines
 ******************************************************************************/

void tune_ddr(void)
{
	u32 min_l, max_l, max_u, min_u;
	u32 echo_dll_l, echo_dll_u;
	u32 write_l, read_l, read_u;
    u32 readq_l, readq_u;
	u32 l,u,k,i,j;
	u16 pass=0;
	u8 test_l[256], test_u[256];
#if defined(VRX_CHIP) || defined(HNX_CHIP)
    u32 write_u;
#endif

	ddrsize=0x20000000;
	for(k=0;k<128;k++)
    {
        test_l[k]=0;
        test_u[k]=0;
    }
	//cache_enable();
	for(k=0;k<0xffff;k++);

	chipid = REG32(0xbf107344);

    REG32(0xbe100b1c) &= ~(1<<3);
    REG32(0xbe100b20) &= ~(1<<3);
#ifdef	ARX_CHIP
	enable_afe();
#endif

#if 0 // asc_init not needed to be done by u-boot
	asc_init();
#endif
	asc_puts("\nDDR autotuning Rev 1.0\n");
#if 0 // Chip ID detection not required
	//print_state('0');
    switch(chipid & 0x0fffffff)
    {
		case 0x0016d083 :
			 asc_puts("ARX 168 chip found\n");
			 if((fpiclock & 0x18) != 0 )
			 {
			 	  asc_puts("CGU_SYS setting not supported by ARX188, Exit!!!\n");
			 	  goto end;
			 }
			 break;
		case 0x0016c083 :
			 asc_puts("ARX188 found\n");
			 break;
		case 0x00171083 :
			 asc_puts("GRX168 found\n");
			 break;
		case 0x00170083 :
			 asc_puts("GRX188 found\n");
			 break;
	    default:
			 asc_puts("XRX1xx found\n");
			 break;
	}
#endif
#if defined(VRX_CHIP) || defined(HNX_CHIP)
   #ifdef CONFIG_LANTIQ_UBOOT_ar10  //AR10 CHIP
   	ddrsize = ddrsize << 1;
		ddrsize = ddrsize >> ((REG32(0xBF8011F0)>>24)&0x7) ; 	//row address bits
		//added by Prabir
		//Row Address[26:24]; "000"=15, "001"=14, "010"=13, "011"=12, "100"=11 , "101"=10
		ddrsize = ddrsize >> ((REG32(0xBF801200))&0x7) ; 	//Column address bits  
		//added by Prabir 
		//Col Address[2:0]; "000"=12, "001"=11, "010"=10, "011"=9, 100=8;
		//Bank Address
		ddrsize = ddrsize >> ((~(REG32(0xBF8011f0)>16))&0x1) ;
		if(REG32(0xbf801230)&0x100) ddrsize = ddrsize >> 1;

		switch ((REG32(0xBF801230))&0xf)
		{
		   case 1:
		   		k=0;// DDR_CS0 active 
		   		break;
   		   case 3:
   		   		k=1; //DDR_CS0 and DDR_CS1  are active  
   		   		break;
           	   case 0xf:
           			k=2; //DDR_CS0 ,DDR_CS1 ,DDR_CS2 and DDR_CS3 are active
           			break;
   		   default:
   		        	asc_puts("Chip select selection not define correctly, EXIT\n");
   		        	goto end;
   		        	break;
		}
	#else
  
    ddrsize = ddrsize << 1;
	ddrsize = ddrsize >> ((REG32(0xBF4010B0)&0x7)) ;
    //Row Address; 0=14, 1=13, 2=12, 3=11, 4=10
	ddrsize = ddrsize >> ((REG32(0xBF4010B0)>>24)&0x7) ;
    //Col Address; 0=12, 1=11, 2=10, 3=9, 4=8;
	ddrsize = ddrsize >> ((~(REG32(0xBF401030)))&0x1) ;
    //Bank Address;
	switch ((REG32(0xBF401080)>>24)&0x3)
	{
		   case 1:
		   		k=0;
		   		break;
   		   case 3:
   		   		k=1;
   		   		break;
   		   default:
   		        asc_puts("Wrong Chip select, EXIT\n");
   		        goto end;
   		        break;
	 }
	 #endif
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
	ddrsize = ddrsize >> (((REG32(0xBF801130)>>8)&0x7)-2) ;
	ddrsize = ddrsize >> ((REG32(0xBF801140))&0x7) ;
	switch ((REG32(0xBF8010F0)>>8)&0xf)
	{
		   case 1:
		   		k=0;
		   		break;
   		   case 3:
   		   		k=1;
   		   		break;
           case 0xf:
           		k=2;
           		break;
   		   default:
   		        asc_puts("Wrong Chip select, EXIT\n");
   		        goto end;
   		        break;
	}
#endif
	ddrsize = ddrsize << k;
	//print_u32(ddrsize); asc_putc('\n');
#if 0
	testch=asc_getc();
	if(testch=='~') mode =2;
	else if (testch=='*') {mode =1; asc_puts("Debug mode tunning started\n");}
	else if (testch=='&') {mode =1;
		 	asc_puts("Debug mode tunning started with Class II\n");
			REG32(0xBF103020) |= (1<<21);
			REG32(0xBF103014) = 1;
		 }
	else mode =0;
#else
	 mode =0;
#endif

#if 0 // no need to determine clock speed.
    switch(fpiclock &0x19)
    {
            case 0x1 :
	            asc_puts("DDR set @ 111.1MHz\n");
                break;
            case 0x10:
	    		if(REG32(0xbf103008)==0x9800f25f)
				    asc_puts("DDR set @ 166.6MHz\n");
				else if(REG32(0xbf103008)==0x9d26f017)
				    asc_puts("DDR set @ 196.6Mhz\n");
				else
				{
					asc_puts("DDR set @ 221.2Mhz\n");
					REG32(0xBF103020) |= (1<<21);
					REG32(0xBF103014) = 1;
				}
				break;
	    	case 0x9:
	    	case 0x0:
        	/*115200 @83.3M, delta 0.000231*/
	            asc_puts("DDR set @ 166.6MHz\n");
                break;
	    	case 0x8:
        	/*115200 @83.3M, delta 0.000231*/
            	asc_puts("DDR set @ 250MHz\n");
				REG32(0xBF103020) |= (1<<21);
				REG32(0xBF103014) = 1;
                break;
    }
#endif
	asc_puts("DDR size from 0xa0000000 - 0x"); print_u32(0xa0000000+(ddrsize-1));asc_putc('\n');
	//asc_puts("DDR DLL lock element = "); print_u32((REG32(0xbf801150)&0x7f));asc_putc('\n');
    #ifdef CONFIG_DEBUG
	asc_puts("DDR tuning magic values:\n");
	asc_puts("STATUS Addr="); print_u32(STATUS); asc_puts(" Val="); print_u32(REG32(STATUS)); asc_puts(" \n");
    asc_puts("REG01 Addr="); print_u32(REG01); asc_puts(" Val="); print_u32(REG32(REG01)); asc_puts(" \n");
    asc_puts("REG02 Addr="); print_u32(REG02); asc_puts(" Val="); print_u32(REG32(REG02)); asc_puts(" \n");
    asc_puts("REG03 Addr="); print_u32(REG03); asc_puts(" Val="); print_u32(REG32(REG03)); asc_puts(" \n");
    asc_puts("REG04 Addr="); print_u32(REG04); asc_puts(" Val="); print_u32(REG32(REG04)); asc_puts(" \n");
	#if defined(VRX_CHIP) || defined(HNX_CHIP)
    asc_puts("REG05 Addr="); print_u32(REG05); asc_puts(" Val="); print_u32(REG32(REG05)); asc_puts(" \n");
    asc_puts("REG06 Addr="); print_u32(REG06); asc_puts(" Val="); print_u32(REG32(REG06)); asc_puts(" \n");
	
	#endif
    #endif

  init_pattern();
  if(REG32(STATUS)==0x0)
  {
	   if(sdramtest(2,0)==0) pass=1; //asc_puts("Initial DDR setting for SDRAM test pass\n");
  }

	if(pass)
	{
		asc_puts("DDR check ok... start booting...\n\n");
		REG32(STATUS)=0x1;
		goto start_uboot;
	}
	/*
	else
	{
		if(REG32(STATUS)!=0xff)
  		    asc_puts("Unknown command from u-boot\n");
		pass=0;
		asc_puts("Start DDR tuning ");
	}
	*/
	REG32(STATUS)=0x10;

#if defined(VRX_CHIP) || defined(HNX_CHIP)
	REG32(DDR_ECHO_DLL0) = 0x20;
	REG32(DDR_ECHO_DLL1) = 0x20;
#endif

    cur_state=1;
    asc_puts("[-]");

/* -------------------------------------------------------------------- */
/* Perform quick test to determine the inital readdqs for write tunning */
#if DEBUGMODE
	for(k=0;k<128;k++)
    {
        test_l[k]=0;
        test_u[k]=0;
    }
#endif

	min_l = READMAX_Q;
	max_l = READMIN_Q;
	min_u = READMAX_Q;
	max_u = READMIN_Q;

#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
    REG32(MC_DC24) = (REG32(MC_DC24) & (~((u32)0xff))) | DQSOUTSHIFT;        // Program for the fix DQS out shift
#endif
    for(j=0;j<15;j++)
    {
    	//print_state('1');
    	asm("sync");
		dummy_cycle();
		REG32(MC_START) = 0;
#if defined(VRX_CHIP) || defined(HNX_CHIP)
        REG32(MC_WR_SLICE0) = (REG32(MC_WR_SLICE0)&0xffff00ff)| ((WRITEDQS_Q+j)<<8);
        REG32(MC_WR_SLICE1) = (REG32(MC_WR_SLICE1)&0xffff00ff)| ((WRITEDQS_Q+j)<<8);
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
        REG32(MC_DC15) = (REG32(MC_DC15) & ~0xff) | (WRITEDQS_Q+j);
#endif
        for(k=READMIN_Q;k<READMAX_Q;k++)
        {
    	    //print_state('2');
    	    asm("sync");
			dummy_cycle();
            REG32(MC_START) = 0;
#if defined(VRX_CHIP) || defined(HNX_CHIP)
            REG32(MC_RD_SLICE0) = (REG32(MC_RD_SLICE0)&0xffff00ff)| k<<8;
            REG32(MC_RD_SLICE1) = (REG32(MC_RD_SLICE1)&0xffff00ff)| k<<8;
            
       #ifdef CONFIG_LANTIQ_UBOOT_ar10
            REG32(MC_START) = 0x401;
            while(((REG32(MC_INT_STAT)&0x4)!=0x4) || (((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0));
       #else  
            REG32(MC_START) = 0x1010100;      
            while(((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0);
       #endif
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
            REG32(MC_DC22) = (REG32(MC_DC22) & (~((u32)0xffff))) | k | k<<0x8;
            REG32(MC_DC21) = (REG32(MC_DC21) & (~((u32)0xff00))) | k<<0x8;
	        REG32(MC_START) = 0x00000100;
	        {
	        	int timeout_cnt=0;
	          while( (REG32(MC_STAT)&0x4)!=0x4 || (REG32(MC_STAT)&0x8)!=0x8 ){
	          	 timeout_cnt++;
	          	 __udelay(1);
	          	 if(timeout_cnt>100){asc_puts("status timeout\n"); break;}
	          };
	        }
#endif
    	    asm("sync");
            __udelay(100);
            l=0; u=0;
            if(sdramtest(0,1)==0)
            {
                l=1;
                if(min_l > k) min_l = k;
                if(max_l < k) max_l = k;
            }
            print_state();
            if(sdramtest(1,1)==0)
            {
                u=1;
                if(min_u > k) min_u = k;
                if(max_u < k) max_u = k;
            }
            test_l[k]=l;
            test_u[k]=u;
        }
    }
    if( max_l > min_l)
    {
        readq_l = (min_l+max_l)>>1;
        //asc_puts("\nStep1: readq_l = "); print_u32(readq_l);
    }
    else
    {
        asc_puts("Can't determine a suitable read DQS delay for slice 0!\n");
        goto end;
    }
    if( max_u > min_u)
    {
        readq_u = (min_u+max_u)>>1;
        //asc_puts("\nStep1: readq_u = "); print_u32(readq_u); asc_puts("\n");
    }
    else
    {
        asc_puts("Can't determine a suitable read DQS delay for slice 1!\n");
        goto end;
    }


/*-----------------End of Quick Test to determine Read DQS-------------------------------*/
/*---------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------*/
/*------------------ Start of DDR GATE Echo DLL Tuning ----------------------------------*/

#if defined(VRX_CHIP) || defined(HNX_CHIP)
#if DEBUGMODE
	for(k=0;k<128;k++)
    {
        test_l[k]=0;
        test_u[k]=0;
    }
#endif
    #define ECHO_DLL_SIZE 0x80

    min_l = ECHO_DLL_SIZE;
    max_l = 0;
    min_u = ECHO_DLL_SIZE;
    max_u = 0;

    for(k=0;k<ECHO_DLL_SIZE;k++)
	{
		REG32(DDR_ECHO_DLL0)  = (REG32(DDR_ECHO_DLL0) & 0xff00) | k;
		REG32(DDR_ECHO_DLL1)  = (REG32(DDR_ECHO_DLL1) & 0xff00) | k;

        l=0; u=0;
        if(sdramtest(0,0)==0)
        {
            l=1;
            if(min_l > k) min_l = k;
            if(max_l < k) max_l = k;
        }

        if(sdramtest(1,0)==0)
        {
            u=1;
            if(min_u > k) min_u = k;
            if(max_u < k) max_u = k;
        }
	
		print_state();

#if DEBUGMODE
        test_l[k]=l;
        test_u[k]=u;
#endif
	}
#if DEBUGMODE
    asc_puts("\n Show slice 0 echo DLL setting\n");
    for(k=0; k< ECHO_DLL_SIZE; k++)
    {
        if(test_l[k]==0)
              asc_putc('0');
        else asc_putc('1');
        if(k%16 == 15) asc_putc('\n');
        else asc_putc(' ');
    }

    asc_puts("\n Show slice 1 echo DLL setting\n");
    for(k=0; k< ECHO_DLL_SIZE; k++)
    {
        if(test_u[k]==0)
              asc_putc('0');
        else asc_putc('1');
        if(k%16 == 15) asc_putc('\n');
        else asc_putc(' ');
    }
#endif

    if( max_l > min_l){
        echo_dll_l = (min_l+max_l)>>1;
		//asc_puts("\nWDQS0 WINDOW:"); print_u32(min_l);asc_putc('--');print_u32(max_l);asc_putc('\n');
		}
    else
    {
        asc_puts("Can't determine a suitable Echo DLL delay setting for slice 0!\n");
        goto end;
    }

    if( max_u > min_u){
        echo_dll_u = (min_u+max_u)>>1;
		//asc_puts("\nWDQS1 WINDOW:"); print_u32(min_u);asc_putc('--');print_u32(max_u);asc_putc('\n');
		}
    else
    {
        asc_puts("Can't determine a suitable Echo DLL delay setting for slice 1!\n");
        goto end;
    }
	
	REG32(DDR_ECHO_DLL0) = echo_dll_l;
	REG32(DDR_ECHO_DLL1) = echo_dll_u;
	
#endif //(VRX/AR10/390 & HNX for echo gate tuning)

/*------------------- End of DDR GATE Echo DLL Tuning -----------------------------------*/
/*---------------------------------------------------------------------------------------*/  

/*---------------------------------------------------------------------------------------*/
/*------------------------ Start of Write Data Eye Tuning -------------------------------*/

#if DEBUGMODE
	for(k=0;k<128;k++)
    {
        test_l[k]=0;
        test_u[k]=0;
    }
#endif

    min_l = WRITEMAX;
    max_l = WRITEMIN;
    min_u = WRITEMAX;
    max_u = WRITEMIN;

	for(k=0;k<0x1fff;k++);
 	print_state();
    asm("sync");
	dummy_cycle();

    REG32(MC_START) = 0;
#if defined(VRX_CHIP) || defined(HNX_CHIP)
    REG32(MC_RD_SLICE0) = (REG32(MC_RD_SLICE0)&0xffff00ff)| readq_l<<8;
    REG32(MC_RD_SLICE1) = (REG32(MC_RD_SLICE1)&0xffff00ff)| readq_u<<8;
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
    REG32(MC_DC22) = (REG32(MC_DC22) & (~((u32)0xffff))) | readq_u | readq_u <<0x8;
    REG32(MC_DC21) = (REG32(MC_DC21) & (~((u32)0xff00))) | readq_l<<0x8;
#endif
    for(k=WRITEMIN;k<WRITEMAX;k++)
    {
        asm("sync");
		dummy_cycle();
        REG32(MC_START) = 0;
#if defined(VRX_CHIP) || defined(HNX_CHIP)
        REG32(MC_WR_SLICE0) = (REG32(MC_WR_SLICE0)&0xffff00ff)| k<<8;
        REG32(MC_WR_SLICE1) = (REG32(MC_WR_SLICE1)&0xffff00ff)| k<<8;
        
        #ifdef CONFIG_LANTIQ_UBOOT_ar10
           REG32(MC_START) = 0x401;
           while(((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0);
        #else
			REG32(MC_START) = 0x1010100;
			while(((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0);
        #endif
        asm("sync");
        __udelay(100);
        l=0; u=0;
        if(sdramtest(0,0)==0)
        {
            l=1;
            if(min_l > k) min_l = k;
            if(max_l < k) max_l = k;
        }

        if(sdramtest(1,0)==0)
        {
            u=1;
            if(min_u > k) min_u = k;
            if(max_u < k) max_u = k;
        }
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
        REG32(MC_DC15) = (REG32(MC_DC15) & ~0xff) | (k);

        REG32(MC_START) = 0x00000100;
         {
	        	int timeout_cnt=0;
	          while( (REG32(MC_STAT)&0x4)!=0x4 || (REG32(MC_STAT)&0x8)!=0x8 ){
	          	 timeout_cnt++;
	          	 __udelay(1);
	          	 if(timeout_cnt>100){asc_puts("status timeout\n"); break;}
	          };
	        }


        asm("sync");
        __udelay(100);
        l=0;
        if(sdramtest(2,0)==0)
        {
            l=1;
            if(min_l > k) min_l = k;
            if(max_l < k) max_l = k;
        }
#endif
	print_state();

#if DEBUGMODE
        test_l[k]=l;
        test_u[k]=u;
#endif
    }
#if DEBUGMODE
#if defined(VRX_CHIP) || defined(HNX_CHIP)
    asc_puts("\n Show slice 0 write setting\n");
    for(k=WRITEMIN; k< WRITEMAX+1; k++)
    {
        if(test_l[k]==0)
              asc_putc('0');
        else asc_putc('1');
        if(k%16 == 15) asc_putc('\n');
        else asc_putc(' ');
    }

    asc_puts("\n Show slice 1 write setting\n");
    for(k=WRITEMIN; k< WRITEMAX+1; k++)
    {
        if(test_u[k]==0)
              asc_putc('0');
        else asc_putc('1');
        if(k%16 == 15) asc_putc('\n');
        else asc_putc(' ');
    }
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
    asc_puts("\n Show Write DQS setting\n");
    for(k=WRITEMIN; k< WRITEMAX+1; k++)
    {
        if(test_l[k]==0)
              asc_putc('0');
        else asc_putc('1');
        if(k%16 == 15) asc_putc('\n');
        else asc_putc(' ');
    }
#endif
#endif
    //print_state('9');
    if( max_l > min_l){
        write_l = (min_l+max_l)>>1;
		//asc_puts("\nWDQS0 WINDOW:"); print_u32(min_l);asc_putc('--');print_u32(max_l);asc_putc('\n');
		}
    else
    {
        asc_puts("Can't determine a suitable write DQS delay for slice 0!\n");
        goto end;
    }
#if defined(VRX_CHIP) || defined(HNX_CHIP)
    if( max_u > min_u){
        write_u = (min_u+max_u)>>1;
		//asc_puts("\nWDQS1 WINDOW:"); print_u32(min_u);asc_putc('--');print_u32(max_u);asc_putc('\n');
		}
    else
    {
        asc_puts("Can't determine a suitable write DQS delay for slice 1!\n");
        goto end;
    }
#endif

	REG32(STATUS)=0x11;
/*------------------------ End of Write Data Eye Tuning ---------------------------------*/
/*---------------------------------------------------------------------------------------*/
   //__udelay(50);

/*---------------------------------------------------------------------------------------*/
/*------------------------ Start of Read Data Eye Tuning --------------------------------*/

#if DEBUGMODE
	for(k=0;k<128;k++)
    {
        test_l[k]=0;
        test_u[k]=0;
    }
#endif
	min_l = READMAX;
	max_l = READMIN;
	min_u = READMAX;
	max_u = READMIN;

    asm("sync");
	dummy_cycle();

    REG32(MC_START) = 0;
#if defined(VRX_CHIP) || defined(HNX_CHIP)
    REG32(MC_WR_SLICE0) = (REG32(MC_WR_SLICE0)&0xffff00ff)| write_l<<8;
    REG32(MC_WR_SLICE1) = (REG32(MC_WR_SLICE1)&0xffff00ff)| write_u<<8;
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
    REG32(MC_DC15) = (REG32(MC_DC15) & ~0xff) | (write_l);
#endif
    for(k=READMIN;k<READMAX;k++)
    {
        //print_state('B');
		dummy_cycle();
        REG32(MC_START) = 0;
#if defined(VRX_CHIP) || defined(HNX_CHIP)
        REG32(MC_RD_SLICE0) = (REG32(MC_RD_SLICE0)&0xffff00ff)| k<<8;
        REG32(MC_RD_SLICE1) = (REG32(MC_RD_SLICE1)&0xffff00ff)| k<<8;
        
        #ifdef CONFIG_LANTIQ_UBOOT_ar10
          REG32(MC_START) = 0x401;
          while(((REG32(MC_INT_STAT)&0x4)!=0x4) || (((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0));
        #else
			REG32(MC_START) = 0x1010100;
            while(((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0);
        #endif 
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
        REG32(MC_DC22) = (REG32(MC_DC22) & (~((u32)0xffff))) | k | k<<0x8;
        REG32(MC_DC21) = (REG32(MC_DC21) & (~((u32)0xff00))) | k<<0x8;
        REG32(MC_START) = 0x00000100;
   	     {
	        	int timeout_cnt=0;
	          while( (REG32(MC_STAT)&0x4)!=0x4 || (REG32(MC_STAT)&0x8)!=0x8 ){
	          	 timeout_cnt++;
	          	 __udelay(1);
	          	 if(timeout_cnt>100){asc_puts("status timeout\n"); break;}
	          };
	        }

#endif
        asm("sync");
        //print_state('C');
        __udelay(100);
        l=0; u=0;
        if(sdramtest(0,0)==0)
        {
            l=1;
            if(min_l > k) min_l = k;
            if(max_l < k) max_l = k;
        }
        print_state();
        if(sdramtest(1,0)==0)
        {
            u=1;
            if(min_u > k) min_u = k;
               if(max_u < k) max_u = k;
        }
#if DEBUGMODE
        test_l[k]=l;
        test_u[k]=u;
#endif
    }
#if DEBUGMODE
    asc_puts("\n Show slice 0 read setting\n");
    for(k=READMIN; k< READMAX+1; k++)
    {
        if(test_l[k]==0)
              asc_putc('0');
        else asc_putc('1');
        if(k%16 == 15) asc_putc('\n');
        else asc_putc(' ');
    }

    asc_puts("\n Show slice 1 read setting\n");
    for(k=READMIN; k< READMAX+1; k++)
    {
        if(test_u[k]==0)
              asc_putc('0');
        else asc_putc('1');
        if(k%16 == 15) asc_putc('\n');
        else asc_putc(' ');
    }
#endif
    if( max_l > min_l){
        read_l = (min_l+max_l)>>1;
        //asc_puts("\nRDQS0 WINDOW:"); print_u32(min_l);asc_putc('--');print_u32(max_l);asc_putc('\n');
		}
    else
    {
        //asc_puts("Can't determine a suitable read DQS delay for slice 0 !\n");
        goto end;
    }
    if( max_u > min_u){
        read_u = (min_u+max_u)>>1;
        //asc_puts("\nRDQS1 WINDOW:"); print_u32(min_u);asc_putc('--');print_u32(max_u);asc_putc('\n');
		}
    else
    {
        //asc_puts("Can't determine a suitable read DQS delay for slice 1!\n");
        goto end;
    }
	REG32(STATUS)=0x12;

/*------------------------- End of Read Data Eye Tuning ---------------------------------*/
/*---------------------------------------------------------------------------------------*/

    asm("sync");
	dummy_cycle();
    REG32(MC_START) = 0;
#if defined(VRX_CHIP) || defined(HNX_CHIP)
	asc_puts("\nDQS GATE ECHO DLL Delay Slice0:"); print_u32(echo_dll_l); asc_putc('\n');
	asc_puts("DQS GATE ECHO DLL Delay Slice1:"); print_u32(echo_dll_u); asc_putc('\n');
	asc_puts("Read DQS Delay Slice0:"); print_u32(read_l); asc_putc('\n');
	asc_puts("Read DQS Delay Slice1:"); print_u32(read_u); asc_putc('\n');
	asc_puts("Write DQS Delay Slice0:"); print_u32(write_l); asc_putc('\n');
	asc_puts("Write DQS Delay Slice1:"); print_u32(write_u); asc_putc('\n');
    REG32(MC_RD_SLICE0) = (REG32(MC_RD_SLICE0)&0xffff00ff)| read_l<<8;
    REG32(MC_RD_SLICE1) = (REG32(MC_RD_SLICE1)&0xffff00ff)| read_u<<8;
          #ifdef CONFIG_LANTIQ_UBOOT_ar10
            REG32(MC_START) = 0x401;
            while(((REG32(MC_INT_STAT)&0x4)!=0x4)|| (((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0));
          #else
            REG32(MC_START) = 0x1010100;
            while(((REG32(MC_DLL_SLICE0)&0x1)&(REG32(MC_DLL_SLICE1)&0x1))==0);
          #endif 
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
/* TODO print*/
	asc_puts("\nRead DQS Delay Slice0:"); print_u32(read_l); asc_putc('\n');
	asc_puts("Read DQS Delay Slice1:"); print_u32(read_u); asc_putc('\n');
	asc_puts("Write DQS Setting:"); print_u32(write_l); asc_putc('\n');
	asc_puts("Fix DQS Out Shift:"); print_u32(DQSOUTSHIFT); asc_putc('\n');
    REG32(MC_DC22) = (REG32(MC_DC22) & (~((u32)0xffff))) | read_u | read_u<<0x8;
    REG32(MC_DC21) = (REG32(MC_DC21) & (~((u32)0xff00))) | read_l<<0x8;
    REG32(MC_START) = 0x00000100;
    	    {
	        	int timeout_cnt=0;
	          while( (REG32(MC_STAT)&0x4)!=0x4 || (REG32(MC_STAT)&0x8)!=0x8 ){
	          	 timeout_cnt++;
	          	 __udelay(1);
	          	 if(timeout_cnt>100){asc_puts("status timeout\n"); break;}	          	
	          };
	        }  

#endif
    //for(i=0;i<0x2000;i++);
    asm("sync");
    __udelay(100);
    //print_state();
	goto store_para;
end:
	//TODO: need to decide what happen if tunning fail.....
	REG32(STATUS) = 0x1f;
	while(1);
	//asc_getc();
store_para:
#if defined(VRX_CHIP) || defined(HNX_CHIP)
	REG32(REG01) = REG32(MC_RD_SLICE0);
	REG32(REG02) = REG32(MC_RD_SLICE1);
	REG32(REG03) = REG32(MC_WR_SLICE0);
	REG32(REG04) = REG32(MC_WR_SLICE1);
	REG32(REG05) = REG32(DDR_ECHO_DLL0);
	REG32(REG06) = REG32(DDR_ECHO_DLL1);
#endif
#if defined(ARX_CHIP) || defined(DANUBE_CHIP)
	REG32(REG01) = REG32(MC_DC15);
	REG32(REG02) = REG32(MC_DC21);
	REG32(REG03) = REG32(MC_DC22);
	REG32(REG04) = REG32(MC_DC24);
#endif
	REG32(STATUS) = 0x2;
    asm("sync");
start_uboot:
#ifdef CONFIG_BOOT_FROM_NOR	
	for(k=0;k<0x80;k++); // jump delay
	void (*jump)(void);
	jump = (void (*)(void))(0xB0000000);
	for(k=0;k<0x80;k++); // jump delay
	(*jump)();

	while(1);
#endif
    asm("sync");
	return;
	/* TODO: Needs to be updated acc. to final CFG definition! */
}


