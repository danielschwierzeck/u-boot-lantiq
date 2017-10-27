/*
 * otp.c
 *
 * (C) Copyright 1-March-2016
 * simple OTP programming for GRX500 SoC
*/

#include <common.h>
#if defined(OTP_IN_FSB) | defined(CONFIG_GRX500_BOOT_4KEC_ONLY)
#include <otp_bin.h>
#endif /* defined(OTP_IN_FSB) | defined(CONFIG_GRX500_BOOT_4KEC_ONLY) */

#define DEBUG_OTP_PROG

#include <asm/boot.h>
#define SRAM_OTPADDR    MPS_DDR_LOC
#define SRAM_OTPSIZE    MPS_SIZE_LOC

/* if you like your own MAGIC and param location, undef below*/
//#define IPCMAGIC        0x344B6563          /* ASCII: 4Kec */
//#define SRAM_OTPADDR    0xbf807ff4
//#define SRAM_OTPSIZE    0xbf807ff8
//#define SRAMFLAG        0xbf807ffc

#define OTP_BASE_ADDR 0xbe200000
//#define OTP_BASE_ADDR 0xbf806000

#ifdef DEBUG_OTP_PROG
#define REG_OEMC        0xb6080128

//! Field OTP_PGM_STA - OTP Program Status
#define OEM_C_OTP_PGM_STA_POS 29
//! Field OTP_PGM_STA - OTP Program Status
#define OEM_C_OTP_PGM_STA_MASK 0x60000000u
//! Constant NOR - No Response
#define CONST_OEM_C_OTP_PGM_STA_NOR 0x0
//! Constant PASS
#define CONST_OEM_C_OTP_PGM_STA_PASS 0x1
//! Constant REV - reserved.
#define CONST_OEM_C_OTP_PGM_STA_REV 0x2
//! Constant FAIL - Programming failed
#define CONST_OEM_C_OTP_PGM_STA_FAIL 0x3

#endif /* DEBUG_OTP_PROG */

/*
 * !<WW: forgive me, but the XOR give the truth table i want
 * simple explanation :
 * this otp.c is common for both FSB and uboot
 * in normal manufacturing boot mode
 * - [4KEC] FSB -> program OTP , [IAP]UBOOT -> signal to FSB through cmd
 * in 4kec only manufacturing boot mode, only 4kec cpu is active
 * - [4KEC] FSB -> do nothing , [4KEC]UBOOT -> cmd to program otp directly.
*/
#if ((!defined(OTP_IN_FSB)) ^ defined(CONFIG_GRX500_BOOT_4KEC_ONLY))

u32 otp_prog_signal(void)
{
    #if 0 /* directly from header file now */
    /* tell where is otp content and size is*/
    REG32(SRAM_OTPADDR) = oem_keys;
    REG32(SRAM_OTPSIZE) = sizeof(oem_keys);
    #endif

    /* flag 4kec for start otp programming */
    REG32(SRAMFLAG) = IPCMAGIC;

    asm("sync");

    /* wait till 4kec finish  */
    while (IPCMAGIC == REG32(SRAMFLAG))
        ;

    /* otp programming result check in REG32(SRAM_OTPADDR)
     * 0 = otp program success
     * 1 = invalid param
     * 2 = otp content not word / 4 bytes aligned
     * 3 = otp program failure
    */

    return REG32(SRAM_OTPADDR);
}

void otp_prog_wait_cmd(void)
{

    /* poll */
    while (IPCMAGIC != REG32(SRAMFLAG))

    return;
}

#else /* ((!defined(OTP_IN_FSB)) ^ defined(CONFIG_GRX500_BOOT_4KEC_ONLY)) */

int otp_prog_execute(void)
{
    u32 i;
    u32 size;
    u8* p_oem_keys=NULL;
    #ifdef DEBUG_OTP_PROG
    u32 oemc = 0;
    #endif /* DEBUG_OTP_PROG */

    /* poll */
    // while (IPCMAGIC != REG32(SRAMFLAG))
        ;

    p_oem_keys = oem_keys;
    size       = sizeof(oem_keys);

    /* safety , if located outside lower 256 MB DDR */
    if (!p_oem_keys ||
        (((u32)p_oem_keys) & 0x1FFFFFFF) >= 0x10000000 ||
        (((u32)(p_oem_keys + size - 1)) & 0x1FFFFFFF) >= 0x10000000 ) {
        REG32(SRAM_OTPADDR) = 1;
        goto exit;
    }

    /* safety, if more than 2KB or not word aligned */
    if (size == 0 ||
        size % 4 != 0 ||
        size > 2048) {
        REG32(SRAM_OTPADDR) = 2;
        goto exit;
    }

    for (i=0; i < size; i+= sizeof(u32) ) {
        REG32(OTP_BASE_ADDR + i) = *((u32*)(p_oem_keys+i));

        #ifdef DEBUG_OTP_PROG
        oemc = REG32(REG_OEMC);
        oemc = (oemc & OEM_C_OTP_PGM_STA_MASK) >> OEM_C_OTP_PGM_STA_POS;

        if (oemc == CONST_OEM_C_OTP_PGM_STA_FAIL){
            REG32(SRAM_OTPADDR) = 3;
            goto exit;
        }
        #endif /* DEBUG_OTP_PROG */
    }

    REG32(SRAM_OTPADDR) = 0;

    exit:
    /* notify iap for finish */
    REG32(SRAMFLAG) = 0x00000000UL;

    return ((int)REG32(SRAM_OTPADDR));
}

#endif /* ((!defined(OTP_IN_FSB)) ^ defined(CONFIG_GRX500_BOOT_4KEC_ONLY)) */


