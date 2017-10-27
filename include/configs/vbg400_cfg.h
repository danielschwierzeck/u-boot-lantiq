/* ============================================================================
 * Copyright (C) 2003[- 2004] ? Infineon Technologies AG.
 *
 * All rights reserved.
 * ============================================================================
 *
 * ============================================================================
 *
 * This document contains proprietary information belonging to Infineon
 * Technologies AG. Passing on and copying of this document, and communication
 * of its contents is not permitted without prior written authorisation.
 *
 * ============================================================================
 *
 * File Name: ifx_cfg.h
 * Author : Mars Lin (mars.lin@infineon.com)
 * Date:
 *
 * ===========================================================================
 *
 * Project:
 * Block:
 *
 * ===========================================================================
 * Contents:  This file contains the data structures and definitions used
 *        by the core iptables and the sip alg modules.
 * ===========================================================================
 * References:
 */

/*
 * This file contains the configuration parameters for the IFX board.
 */


/*-----------------------------------------------------------------------
 * Board specific configurations
 */
#ifdef CONFIG_BOOT_FROM_NOR
  #error "ERROR!! Define SPI Flash first!"
#endif /*CONFIG_BOOT_FROM_NOR*/


/***************************************************************************/
/***************************************************************************/
/***************SPI FLASH map starts here***********************************/
/***************************************************************************/
/***************************************************************************/

#ifdef CONFIG_BOOT_FROM_SPI
#ifdef CONFIG_SPI_FLASH_2M
#define IFX_CONFIG_FLASH_SIZE 2
#elif CONFIG_SPI_FLASH_4M
#define IFX_CONFIG_FLASH_SIZE 4
#elif CONFIG_SPI_FLASH_8M
#define IFX_CONFIG_FLASH_SIZE 8
#endif

#ifndef IFX_CONFIG_FLASH_SIZE
#define IFX_CONFIG_FLASH_SIZE 4
#endif

#ifdef CONFIG_FIRMWARE_IN_ROOTFS

#if (IFX_CONFIG_FLASH_SIZE == 2)
  #error "2M not supported for vbg400"

#elif (IFX_CONFIG_FLASH_SIZE == 4)

#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block5=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"      \
        "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0x00010000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME          "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR          0x003DFFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME            "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR            0x003E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                  0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR              0x003EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME             "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR             0x003F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                   0x2000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR               0x003F1FFF

  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	         "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	         0x003F2000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE                    0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR                0x003F3FFF

  #define IFX_CFG_FLASH_END_ADDR                         0x003FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 8)

#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"          \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"     \
        "data_block5=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"       \
        "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0x00010000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME          "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR          0x007DFFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_KERNEL_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock2"

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME            "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR            0x007E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                  0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR              0x007EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME             "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR             0x007F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                   0x2000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR               0x007F1FFF

  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME              "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR              0x007F2000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE                    0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR                0x007F3FFF

  #define IFX_CFG_FLASH_END_ADDR                         0x007FFFFF

#else
  #error "ERROR!! Define flash size first!"
#endif

#else /*Not defined CONFIG_FIRMWARE_IN_ROOTFS*/
  #error "ERROR!! Define Firmware in rootfs first!"
#endif /*CONFIG_FIRMWARE_IN_ROOTFS*/

#endif /*CONFIG_BOOT_FROM_SPI*/


/***************************************************************************/
/***************************************************************************/
/***************NAND FLASH map starts here***********************************/
/***************************************************************************/
/***************************************************************************/

#ifdef CONFIG_BOOT_FROM_NAND
  #error "ERROR!! Define SPI Flash first!"
#endif /*CONFIG_BOOT_FROM_NAND*/


/* End of Board specific configurations
 *-----------------------------------------------------------------------
 */

/*************************************************************************/

