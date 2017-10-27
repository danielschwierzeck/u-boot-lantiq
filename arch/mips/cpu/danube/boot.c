/*****************************************************************************
 * DANUBE BootROM
 * Copyright (c) 2005, Infineon Technologies AG, All rights reserved
 * IFAP DC COM SD
 *****************************************************************************/
// SchS: BOOT_CFG_STAT flags are set by the kernel module mps_device.c
// see MPS_CFG_STAT.
// decryption is set by flag FLAG_DEC (mps_device.c USE_ENCRYPTED_VOICE_FIRMWARE)
//2007-03-29 fuse_prg bootrom call added instead of efuse.c module

#include <common.h>
#include "boot.h"
#include "tag.h"
#include <asm/danube.h>

// SchS: Preinitialization for CPU1
boot_data bootrom =
{
  1,   /** CPU number */
  0,   /** Boot configuration */
  0,   /** CPU endianess */
  0,   /** Debug mode */
  0};   /** application vector */

/*TODO: make sure this is defined */
#define CHECK_EFUSE
#define USE_EEPROM

/*TODO: undefine this !*/
#undef DISPLAY_TIME_DATE

/******************************************************************************
 * Local routines
 ******************************************************************************/
/*
 Decrypt DSP FW
  data - pointer to encrypted firmware (32 bit aligned)
  n    - number of bytes in firmware (multiple of 32)
 */
//void decrypt(u32 addr, int n);
void (*decrypt) (u32 addr, int n) = 0xbf0014e8;
//void (*fuse_prg) (void) =0xbf002d28;
//void * decrypt = 0xbf0014e8;


void _boot_rvec(void)
{
   if (*BOOT_RVEC(bootrom.cpu) == 0)
   {
      boot_error(BOOT_ERR_NO_RVEC);
   }
   else
   {
   
      void (*start)(void) = (void *)*BOOT_RVEC(1);
      boot_set_status(BOOT_STAT_START, BOOT_STAT_MASK_STAT);
      if (*BOOT_CFG_STAT(bootrom.cpu) & FLAG_DEC)
      {
         u32 size = *BOOT_SIZE(bootrom.cpu);
         u32 addr = *BOOT_RVEC(bootrom.cpu);
         decrypt(addr, size);
      }
      start();
   }
}

/******************************************************************************
 * Global routines
 ******************************************************************************/

/* Togle HRST depending on error... */
void boot_error(u32 berr)
{
   int i;
   boot_set_status(BOOT_STAT_HALT, BOOT_STAT_MASK_STAT);
   boot_sdbg("** HALT, ", berr);
   while(1)
   {
      for (i = berr; i > 0; i--)
      {
         /* Toggle pin */
      }
      __asm__("nop;nop;nop;nop;nop;");
   }
}

void boot_sdbg(u8* string, u32 value)
{
}

void boot_set_size(u32 size)
{
   *BOOT_SIZE(bootrom.cpu) = size;
}

void boot_set_rvec(u32 vector)
{
   *BOOT_RVEC(bootrom.cpu) = vector;
}

void boot_set_status(u32 status, u32 mask)
{
  *BOOT_CFG_STAT(bootrom.cpu) = (*BOOT_CFG_STAT(bootrom.cpu) & ~mask) | (status & mask);
}

void boot_set_config(u32 config)
{
  *BOOT_CFG_STAT(bootrom.cpu) = (*BOOT_CFG_STAT(bootrom.cpu) & 0x0000FFFF) | (config & 0xFFFF0000);
}

void boot_clear(void)
{
   /* Clear virtual register space */
   *BOOT_RVEC(0)       = 0;
   *BOOT_NVEC(0)       = 0;
   *BOOT_EVEC(0)       = 0;
   *BOOT_CP0_STATUS(0) = 0;
   *BOOT_CP0_EPC(0)    = 0;
   *BOOT_CP0_EEPC(0)   = 0;
   *BOOT_CFG_STAT(0)   = 0;
   *BOOT_RVEC(1)       = 0;
   *BOOT_NVEC(1)       = 0;
   *BOOT_EVEC(1)       = 0;
   *BOOT_CP0_STATUS(1) = 0;
   *BOOT_CP0_EPC(1)    = 0;
   *BOOT_CP0_EEPC(1)   = 0;
   *BOOT_SIZE(1)       = 0;
   *BOOT_CFG_STAT(1)   = 0;
}



/* Boot routine for CPU1 */
void boot_cp1(void)
{
  int ret = 10;

  bootrom.cpu = 1;
  while (*BOOT_RVEC(bootrom.cpu) == 0);
  _boot_rvec();
  /* never get here...*/
  boot_error(ret);
}


