
/*
 * FPU implementation/revision register (CP1 control register 0).
 *
 * +---------------------------------+----------------+----------------+
 * | 0                   | Implementation | Revision       |
 * +---------------------------------+----------------+----------------+
 *  31                 16 15         8 7          0
 */

/*
 * These are the PRID's for when 23:16 == PRID_COMP_MIPS
 */

#define CPU_4KC        0x80
#define CPU_5KC        0x81
#define CPU_20KC       0x82
#define CPU_4KECR1     0x84
#define CPU_4KSC       0x86
#define CPU_25KF       0x88
#define CPU_5KE        0x89
#define CPU_4KEC       0x90
#define CPU_4KEMPR2    0x91
#define CPU_4KSD       0x92
#define CPU_24K        0x93
#define CPU_34K        0x95
#define CPU_24KE       0x96
#define CPU_74K        0x97
#define CPU_1004K      0x99
#define CPU_1074K      0x9a
#define CPU_M14KC      0x9c
#define CPU_M14KEC     0x9e
#define CPU_INTERAPTIV 0xa1

