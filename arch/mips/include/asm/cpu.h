
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

/*
 * ISA Level encodings
 *
 */
#define MIPS_CPU_ISA_I      0x00000001
#define MIPS_CPU_ISA_II     0x00000002
#define MIPS_CPU_ISA_III    0x00000004
#define MIPS_CPU_ISA_IV     0x00000008
#define MIPS_CPU_ISA_V      0x00000010
#define MIPS_CPU_ISA_M32R1  0x00000020
#define MIPS_CPU_ISA_M32R2  0x00000040
#define MIPS_CPU_ISA_M64R1  0x00000080
#define MIPS_CPU_ISA_M64R2  0x00000100

#define MIPS_CPU_ISA_32BIT (MIPS_CPU_ISA_I | MIPS_CPU_ISA_II | \
    MIPS_CPU_ISA_M32R1 | MIPS_CPU_ISA_M32R2)
#define MIPS_CPU_ISA_64BIT (MIPS_CPU_ISA_III | MIPS_CPU_ISA_IV | \
    MIPS_CPU_ISA_V | MIPS_CPU_ISA_M64R1 | MIPS_CPU_ISA_M64R2)

