/*
 * This is just an example of how to select the DDR setting header files for Lantiq reference boards.
 * User should use his own setting files according to the real DDR chip used on his own boards.
*/

#ifdef CONFIG_AR10_DDR2
 #if defined(CONFIG_AR10_CPU_150M_RAM_150M) || defined(CONFIG_AR10_CPU_300M_RAM_150M) || \
     defined(CONFIG_AR10_CPU_600M_RAM_150M) || defined(CONFIG_AR10_CPU_250M_RAM_125M) || \
	 defined(CONFIG_AR10_CPU_125M_RAM_125M) || defined(CONFIG_GRX390_CPU_180M_RAM_180M) || \
	 defined(CONFIG_GRX390_CPU_360M_RAM_180M)
    #ifdef CONFIG_AR10_DDR_8BIT
     #include "ddr2/xrx300_ddr2_8bit_150M_settings.h"
	#else
     #include "ddr2/xrx300_ddr2_150M_settings.h"
	#endif 
 #elif defined(CONFIG_AR10_CPU_500M_RAM_250M) || defined(CONFIG_AR10_CPU_250M_RAM_250M) 
    #ifdef CONFIG_AR10_DDR_8BIT
     #include "ddr2/xrx300_ddr2_8bit_250M_settings.h"
    #else
	   #if (CONFIG_IFX_MEMORY_SIZE == 256 )
         #include "ddr2/xrx300_ddr2_SZ256M_CLK250M_settings.h"
	   #else
         #include "ddr2/xrx300_ddr2_250M_settings.h" 
	   #endif
    #endif
 #elif defined(CONFIG_AR10_CPU_600M_RAM_300M) || defined(CONFIG_AR10_CPU_300M_RAM_300M)
    #ifdef CONFIG_AR10_DDR_8BIT
     #include "ddr2/xrx300_ddr2_8bit_250M_settings.h"
    #else
       #if (CONFIG_IFX_MEMORY_SIZE == 256 )
	     #include "ddr2/xrx300_ddr2_SZ256M_CLK300M_settings.h"
	   #else
         #include "ddr2/xrx300_ddr2_300M_settings.h"
	   #endif
    #endif
 #elif defined(CONFIG_GRX390_CPU_720M_RAM_360M) || defined(CONFIG_GRX390_CPU_360M_RAM_360M)
	#ifdef CONFIG_AR10_DDR_8BIT
	 #include "ddr2/grx390_ddr2_8bit_360M_settings.h"
	#else
	  #if (CONFIG_IFX_MEMORY_SIZE == 256 )
       #include "ddr2/grx390_ddr2_SZ256M_CLK360M_settings.h"
	  #else
	   #include "ddr2/grx390_ddr2_360M_settings.h"
	  #endif 
	#endif
 #elif defined(CONFIG_GRX390_CPU_666M_RAM_333M)
	#ifdef CONFIG_AR10_DDR_8BIT
	 #include "ddr2/grx390_ddr2_8bit_333M_settings.h"
	#else
      #if (CONFIG_IFX_MEMORY_SIZE == 256 )
 	   #include "ddr2/grx390_ddr2_SZ256M_CLK333M_settings.h"
	  #else
       #include "ddr2/grx390_ddr2_333M_settings.h"
	  #endif
	#endif
 #elif defined(CONFIG_GRX390_CPUFREQ_AUTO_DETECT)
 	#if (CONFIG_IFX_MEMORY_SIZE == 256)
	 #include "ddr2/grx390_ddr2_SZ256M_CLK360M_settings.h"
	 #include "ddr2/xrx300_ddr2_SZ256M_CLK300M_settings.h"
	#else
	 #include "ddr2/grx390_ddr2_360M_settings.h"
	 #include "ddr2/xrx300_ddr2_300M_settings.h"
	#endif
 #endif
#elif CONFIG_AR10_DDR1
 #if defined(CONFIG_AR10_CPU_150M_RAM_150M) || defined(CONFIG_AR10_CPU_300M_RAM_150M) || \
     defined(CONFIG_AR10_CPU_600M_RAM_150M) || defined(CONFIG_AR10_CPU_250M_RAM_125M) || \
     defined(CONFIG_AR10_CPU_125M_RAM_125M)
   #ifdef CONFIG_AR10_DDR_8BIT
     #include "ddr1/xrx300_ddr1_8bit_250M_settings.h"
   #else
     #include "ddr1/xrx300_ddr1_250M_settings.h"
   #endif
  #elif defined(CONFIG_AR10_CPU_500M_RAM_250M) || defined(CONFIG_AR10_CPU_250M_RAM_250M) || \
     defined(CONFIG_AR10_CPU_600M_RAM_300M) || defined(CONFIG_AR10_CPU_300M_RAM_300M)
    #ifdef CONFIG_AR10_DDR_8BIT
      #include "ddr1/xrx300_ddr1_8bit_250M_settings.h"
	#else
      #include "ddr1/xrx300_ddr1_250M_settings.h"
	#endif
  #endif 
#endif

#define DDR_OFFSET   0xbf801000
#define DDR_CCR00      (DDR_OFFSET + 0x0000 )
#define DDR_CCR01      (DDR_OFFSET + 0x0010 )
#define DDR_CCR02      (DDR_OFFSET + 0x0020 )
#define DDR_CCR03      (DDR_OFFSET + 0x0030 )
#define DDR_CCR04      (DDR_OFFSET + 0x0040 )
#define DDR_CCR05      (DDR_OFFSET + 0x0050 )
#define DDR_CCR06      (DDR_OFFSET + 0x0060 )
#define DDR_CCR07      (DDR_OFFSET + 0x0070 )
#define DDR_CCR08      (DDR_OFFSET + 0x0080 )
#define DDR_CCR09      (DDR_OFFSET + 0x0090 )
#define DDR_CCR10      (DDR_OFFSET + 0x00A0 )
#define DDR_CCR11      (DDR_OFFSET + 0x00B0 )
#define DDR_CCR12      (DDR_OFFSET + 0x00C0 )
#define DDR_CCR13      (DDR_OFFSET + 0x00D0 )
#define DDR_CCR14      (DDR_OFFSET + 0x00E0 )
#define DDR_CCR15      (DDR_OFFSET + 0x00F0 )
#define DDR_CCR16      (DDR_OFFSET + 0x0100 )
#define DDR_CCR17      (DDR_OFFSET + 0x0110 )
#define DDR_CCR18      (DDR_OFFSET + 0x0120 )
#define DDR_CCR19      (DDR_OFFSET + 0x0130 )
#define DDR_CCR20      (DDR_OFFSET + 0x0140 )
#define DDR_CCR21      (DDR_OFFSET + 0x0150 )
#define DDR_CCR22      (DDR_OFFSET + 0x0160 )
#define DDR_CCR23      (DDR_OFFSET + 0x0170 )
#define DDR_CCR24      (DDR_OFFSET + 0x0180 )
#define DDR_CCR25      (DDR_OFFSET + 0x0190 )
#define DDR_CCR26      (DDR_OFFSET + 0x01A0 )
#define DDR_CCR27      (DDR_OFFSET + 0x01B0 )
#define DDR_CCR28      (DDR_OFFSET + 0x01C0 )
#define DDR_CCR29      (DDR_OFFSET + 0x01D0 )
#define DDR_CCR30      (DDR_OFFSET + 0x01E0 )
#define DDR_CCR31      (DDR_OFFSET + 0x01F0 )
#define DDR_CCR32      (DDR_OFFSET + 0x0200 )
#define DDR_CCR33      (DDR_OFFSET + 0x0210 )
#define DDR_CCR34      (DDR_OFFSET + 0x0220 )
#define DDR_CCR35      (DDR_OFFSET + 0x0230 )
#define DDR_CCR36      (DDR_OFFSET + 0x0240 )
#define DDR_CCR37      (DDR_OFFSET + 0x0250 )
#define DDR_CCR38      (DDR_OFFSET + 0x0260 )
#define DDR_CCR39      (DDR_OFFSET + 0x0270 )
#define DDR_CCR40      (DDR_OFFSET + 0x0280 )
#define DDR_CCR41      (DDR_OFFSET + 0x0290 )
#define DDR_CCR42      (DDR_OFFSET + 0x02A0 )
#define DDR_CCR43      (DDR_OFFSET + 0x02B0 )
#define DDR_CCR44      (DDR_OFFSET + 0x02C0 )
#define DDR_CCR45      (DDR_OFFSET + 0x02D0 )
#define DDR_CCR46      (DDR_OFFSET + 0x02E0 )
#define DDR_CCR47      (DDR_OFFSET + 0x02F0 )
#define DDR_CCR48      (DDR_OFFSET + 0x0300 )
#define DDR_CCR49      (DDR_OFFSET + 0x0310 )
#define DDR_CCR50      (DDR_OFFSET + 0x0320 )
#define DDR_CCR51      (DDR_OFFSET + 0x0330 )
#define DDR_CCR52      (DDR_OFFSET + 0x0340 )
#define DDR_CCR53      (DDR_OFFSET + 0x0350 )
#define DDR_CCR54      (DDR_OFFSET + 0x0360 )
#define DDR_CCR55      (DDR_OFFSET + 0x0370 )
#define DDR_PHYR0      (DDR_OFFSET + 0x0400 )
#define DDR_PHYR1      (DDR_OFFSET + 0x0410 )
#define DDR_PHYR2      (DDR_OFFSET + 0x0420 )
#define DDR_PHYR3      (DDR_OFFSET + 0x0430 )
#define DDR_PHYR4      (DDR_OFFSET + 0x0440 )
#define DDR_PHYR5      (DDR_OFFSET + 0x0450 )
#define DDR_PHYR6      (DDR_OFFSET + 0x0460 )
#define DDR_PHYR7      (DDR_OFFSET + 0x0470 )
#define DDR_PHYR8      (DDR_OFFSET + 0x0480 )
#define DDR_PHYR9      (DDR_OFFSET + 0x0490 )
#define DDR_PHYR10     (DDR_OFFSET + 0x04A0 )
#define DDR_PHYR11     (DDR_OFFSET + 0x04B0 )
#define DDR_PHYR12     (DDR_OFFSET + 0x04C0 )
#define DDR_PHYR13     (DDR_OFFSET + 0x04D0 )
#define DDR_PHYR14     (DDR_OFFSET + 0x04E0 )
#define DDR_PHYR15     (DDR_OFFSET + 0x04F0 )



typedef struct ddr_setting{
   u32 addr;
   u32 value;
}ddr_t;

#ifndef CONFIG_GRX390_CPUFREQ_AUTO_DETECT
ddr_t ddr[]={ { DDR_CCR00, MC_CCR00_VALUE },
	            { DDR_CCR01, MC_CCR01_VALUE },
              { DDR_CCR02, MC_CCR02_VALUE },
              { DDR_CCR03, MC_CCR03_VALUE }, 
              { DDR_CCR04, MC_CCR04_VALUE }, 
              { DDR_CCR05, MC_CCR05_VALUE },
              { DDR_CCR06, MC_CCR06_VALUE },
              { DDR_CCR07, MC_CCR07_VALUE }, 
              { DDR_CCR08, MC_CCR08_VALUE },
              { DDR_CCR09, MC_CCR09_VALUE }, 
              { DDR_CCR10, MC_CCR10_VALUE }, 
              { DDR_CCR11, MC_CCR11_VALUE }, 
              { DDR_CCR12, MC_CCR12_VALUE }, 
              { DDR_CCR13, MC_CCR13_VALUE }, 
              { DDR_CCR14, MC_CCR14_VALUE }, 
              { DDR_CCR15, MC_CCR15_VALUE }, 
              { DDR_CCR16, MC_CCR16_VALUE }, 
              { DDR_CCR17, MC_CCR17_VALUE }, 
              { DDR_CCR18, MC_CCR18_VALUE }, 
              { DDR_CCR19, MC_CCR19_VALUE }, 
              { DDR_CCR20, MC_CCR20_VALUE }, 
              { DDR_CCR21, MC_CCR21_VALUE }, 
              { DDR_CCR22, MC_CCR22_VALUE }, 
              { DDR_CCR23, MC_CCR23_VALUE }, 
              { DDR_CCR24, MC_CCR24_VALUE }, 
              { DDR_CCR25, MC_CCR25_VALUE }, 
              { DDR_CCR26, MC_CCR26_VALUE }, 
              { DDR_CCR27, MC_CCR27_VALUE }, 
              { DDR_CCR28, MC_CCR28_VALUE }, 
              { DDR_CCR29, MC_CCR29_VALUE }, 
              { DDR_CCR30, MC_CCR30_VALUE },
              { DDR_CCR31, MC_CCR31_VALUE }, 
              { DDR_CCR32, MC_CCR32_VALUE }, 
              { DDR_CCR33, MC_CCR33_VALUE }, 
              { DDR_CCR34, MC_CCR34_VALUE }, 
              { DDR_CCR35, MC_CCR35_VALUE }, 
              { DDR_CCR36, MC_CCR36_VALUE }, 
              { DDR_CCR37, MC_CCR37_VALUE }, 
              { DDR_CCR38, MC_CCR38_VALUE },
              { DDR_CCR39, MC_CCR39_VALUE },
              { DDR_CCR40, MC_CCR40_VALUE }, 
              { DDR_CCR41, MC_CCR41_VALUE }, 
              { DDR_CCR42, MC_CCR42_VALUE },
              { DDR_CCR43, MC_CCR43_VALUE }, 
              { DDR_CCR44, MC_CCR44_VALUE }, 
              { DDR_CCR45, MC_CCR45_VALUE }, 
              { DDR_CCR46, MC_CCR46_VALUE }, 
              { DDR_CCR47, MC_CCR47_VALUE }, 
              { DDR_CCR48, MC_CCR48_VALUE },
              { DDR_CCR49, MC_CCR49_VALUE }, 
              { DDR_CCR50, MC_CCR50_VALUE }, 
              { DDR_CCR51, MC_CCR51_VALUE }, 
              { DDR_CCR52, MC_CCR52_VALUE }, 
              { DDR_CCR53, MC_CCR53_VALUE },
              { DDR_CCR54, MC_CCR54_VALUE }, 
              { DDR_CCR55, MC_CCR55_VALUE }, 
              { DDR_PHYR0, MC_PHYR0_VALUE }, 
              { DDR_PHYR1, MC_PHYR1_VALUE }, 
              { DDR_PHYR2, MC_PHYR2_VALUE },
              { DDR_PHYR3, MC_PHYR3_VALUE },
              { DDR_PHYR4, MC_PHYR4_VALUE },
              { DDR_PHYR5, MC_PHYR5_VALUE }, 
              { DDR_PHYR6, MC_PHYR6_VALUE }, 
              { DDR_PHYR7, MC_PHYR7_VALUE }, 
              { DDR_PHYR8, MC_PHYR8_VALUE }, 
              { DDR_PHYR9, MC_PHYR9_VALUE } };

#else
#define SET_DDR_VALUE(x)	\
	ddr_t ddr_##x[] = {			\
			  { DDR_CCR00, MC_CCR00_VALUE_##x },		\
	          { DDR_CCR01, MC_CCR01_VALUE_##x }, 		\
              { DDR_CCR02, MC_CCR02_VALUE_##x },		\
              { DDR_CCR03, MC_CCR03_VALUE_##x }, 		\
              { DDR_CCR04, MC_CCR04_VALUE_##x }, 		\
              { DDR_CCR05, MC_CCR05_VALUE_##x },		\
              { DDR_CCR06, MC_CCR06_VALUE_##x },		\
              { DDR_CCR07, MC_CCR07_VALUE_##x }, 		\
              { DDR_CCR08, MC_CCR08_VALUE_##x },		\
              { DDR_CCR09, MC_CCR09_VALUE_##x }, 		\
              { DDR_CCR10, MC_CCR10_VALUE_##x }, 		\
              { DDR_CCR11, MC_CCR11_VALUE_##x }, 		\
              { DDR_CCR12, MC_CCR12_VALUE_##x }, 		\
              { DDR_CCR13, MC_CCR13_VALUE_##x }, 		\
              { DDR_CCR14, MC_CCR14_VALUE_##x }, 		\
              { DDR_CCR15, MC_CCR15_VALUE_##x }, 		\
              { DDR_CCR16, MC_CCR16_VALUE_##x }, 		\
              { DDR_CCR17, MC_CCR17_VALUE_##x }, 		\
              { DDR_CCR18, MC_CCR18_VALUE_##x }, 		\
              { DDR_CCR19, MC_CCR19_VALUE_##x }, 		\
              { DDR_CCR20, MC_CCR20_VALUE_##x }, 		\
              { DDR_CCR21, MC_CCR21_VALUE_##x }, 		\
              { DDR_CCR22, MC_CCR22_VALUE_##x }, 		\
              { DDR_CCR23, MC_CCR23_VALUE_##x }, 		\
              { DDR_CCR24, MC_CCR24_VALUE_##x }, 		\
              { DDR_CCR25, MC_CCR25_VALUE_##x }, 		\
              { DDR_CCR26, MC_CCR26_VALUE_##x }, 		\
              { DDR_CCR27, MC_CCR27_VALUE_##x }, 		\
              { DDR_CCR28, MC_CCR28_VALUE_##x }, 		\
              { DDR_CCR29, MC_CCR29_VALUE_##x }, 		\
              { DDR_CCR30, MC_CCR30_VALUE_##x },		\
              { DDR_CCR31, MC_CCR31_VALUE_##x }, 		\
              { DDR_CCR32, MC_CCR32_VALUE_##x }, 		\
              { DDR_CCR33, MC_CCR33_VALUE_##x }, 		\
              { DDR_CCR34, MC_CCR34_VALUE_##x }, 		\
              { DDR_CCR35, MC_CCR35_VALUE_##x }, 		\
              { DDR_CCR36, MC_CCR36_VALUE_##x }, 		\
              { DDR_CCR37, MC_CCR37_VALUE_##x }, 		\
              { DDR_CCR38, MC_CCR38_VALUE_##x },		\
              { DDR_CCR39, MC_CCR39_VALUE_##x },		\
              { DDR_CCR40, MC_CCR40_VALUE_##x }, 		\
              { DDR_CCR41, MC_CCR41_VALUE_##x }, 		\
              { DDR_CCR42, MC_CCR42_VALUE_##x },		\
              { DDR_CCR43, MC_CCR43_VALUE_##x }, 		\
              { DDR_CCR44, MC_CCR44_VALUE_##x }, 		\
              { DDR_CCR45, MC_CCR45_VALUE_##x }, 		\
              { DDR_CCR46, MC_CCR46_VALUE_##x }, 		\
              { DDR_CCR47, MC_CCR47_VALUE_##x }, 		\
              { DDR_CCR48, MC_CCR48_VALUE_##x },		\
              { DDR_CCR49, MC_CCR49_VALUE_##x }, 		\
              { DDR_CCR50, MC_CCR50_VALUE_##x }, 		\
              { DDR_CCR51, MC_CCR51_VALUE_##x }, 		\
              { DDR_CCR52, MC_CCR52_VALUE_##x }, 		\
              { DDR_CCR53, MC_CCR53_VALUE_##x },		\
              { DDR_CCR54, MC_CCR54_VALUE_##x }, 		\
              { DDR_CCR55, MC_CCR55_VALUE_##x }, 		\
              { DDR_PHYR0, MC_PHYR0_VALUE_##x }, 		\
              { DDR_PHYR1, MC_PHYR1_VALUE_##x }, 		\
              { DDR_PHYR2, MC_PHYR2_VALUE_##x },		\
              { DDR_PHYR3, MC_PHYR3_VALUE_##x },		\
              { DDR_PHYR4, MC_PHYR4_VALUE_##x },		\
              { DDR_PHYR5, MC_PHYR5_VALUE_##x }, 		\
              { DDR_PHYR6, MC_PHYR6_VALUE_##x }, 		\
              { DDR_PHYR7, MC_PHYR7_VALUE_##x }, 		\
              { DDR_PHYR8, MC_PHYR8_VALUE_##x }, 		\
              { DDR_PHYR9, MC_PHYR9_VALUE_##x } };		
#endif /* CONFIG_GRX390_CPUFREQ_AUTO_DETECT */
                
                
                
                
                
