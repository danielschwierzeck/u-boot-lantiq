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
#if defined(CONFIG_BOOT_FROM_NOR) || defined(CONFIG_BOOT_FROM_UART)

#ifdef CONFIG_NOR_FLASH_2M
#define IFX_CONFIG_FLASH_SIZE 2
#elif CONFIG_NOR_FLASH_4M
#define IFX_CONFIG_FLASH_SIZE 4
#elif CONFIG_NOR_FLASH_8M
#define IFX_CONFIG_FLASH_SIZE 8
#endif

#ifndef IFX_CONFIG_FLASH_SIZE
#define IFX_CONFIG_FLASH_SIZE 4
#endif

#ifdef CONFIG_FIRMWARE_IN_ROOTFS
//2MB flash partition
#if (IFX_CONFIG_FLASH_SIZE == 2)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0xB0000000\0"                                      \
        "part1_begin=0xB0020000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0xB0000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0xB0020000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0xB01FADFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0xB01FB200
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x4000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0xB01FEDFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0xB01FEE00
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0xB01FFDFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0xB01FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0xB01FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0xB01FFFFF

//4MB flash partition
#elif (IFX_CONFIG_FLASH_SIZE == 4)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0xB0000000\0"                                      \
        "part1_begin=0xB0020000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0xB0000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0xB0020000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME          "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR          0xB03F6DFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME            "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR            0xB03ECE00
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                  0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR              0xB03FCDFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME             "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR             0xB03FEE00
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                   0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR               0xB03FFDFF


  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME         "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR         0xB03FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE               0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR           0xB03FFFFF

  #define IFX_CFG_FLASH_END_ADDR                         0xB03FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 8)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0xB0000000\0"                                      \
        "part1_begin=0xB0020000\0"                                      \
        "total_part=2\0"

#ifdef CONFIG_OVERLAY
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_OVERLAY_IMAGE_BLOCK_NAME "\0"         \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block7=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=8\0"        
#else
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block6=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=7\0"
#endif
  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0xB0000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0xB0020000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
#ifdef CONFIG_OVERLAY
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0xB078FFFF
#else
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0xB07DFFFF
#endif
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0
	
  #define IFX_CFG_FLASH_OVERLAY_IMAGE_BLOCK_NAME          "overlay"
  #define IFX_CFG_FLASH_OVERLAY_IMAGE_START_ADDR          0xB0790000
  #define IFX_CFG_FLASH_OVERLAY_IMAGE_SIZE                0x50000
  #define IFX_CFG_FLASH_OVERLAY_IMAGE_END_ADDR            0xB07DFFFF
	
  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0xB07E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0xB07EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0xB07F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0xB07F0FFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0xB07F1000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x1000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0xB07F1FFF
  
  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	      	  "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	      	  0xB07F2000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE		          0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR		  0xB07F3FFF  

  #define IFX_CFG_FLASH_END_ADDR                          0xB07FFFFF


#else
  #error "ERROR!! Define flash size first!"
#endif

#else /*Not defined CONFIG_FIRMWARE_IN_ROOTFS*/
//2MB flash partition
#if (IFX_CONFIG_FLASH_SIZE == 2)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0xB0000000\0"                                      \
        "part1_begin=0xB0020000\0"                                      \
        "part2_begin=0xB00A0000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0xB0000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME       "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR       0xB0020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE             0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME    "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0xB00A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0xB01FADFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0xB01FAE00
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x4000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0xB01FEDFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0xB01FEE00
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0xB01FFDFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0xB01FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0xB01FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0xB01FFFFF

//4MB flash partition
#elif (IFX_CONFIG_FLASH_SIZE == 4)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0xB0000000\0"                                      \
        "part1_begin=0xB0020000\0"                                      \
        "part2_begin=0xB00A0000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0xB0000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME        "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR        0xB0020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE              0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME     "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0xB00A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0xB03EDFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0xB03EE000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0xB03FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME             "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR             0xB03FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                   0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR               0xB03FEFFF


  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME         "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0xB03FF000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x400
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0xB03FF3FF


  #define IFX_CFG_FLASH_END_ADDR                         0xB03FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 8)
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0xB0000000\0"                                      \
        "part1_begin=0xB0010000\0"                                      \
        "part2_begin=0xB0020000\0"                                      \
        "part3_begin=0xB00A0000\0"                                      \
        "total_part=4\0"
#else
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0xB0000000\0"                                      \
        "part1_begin=0xB0020000\0"                                      \
        "part2_begin=0xB00A0000\0"                                      \
        "total_part=3\0"
#endif

#ifdef CONFIG_OVERLAY
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME "\0"        \
        "data_block2=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block3=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block5=" IFX_CFG_FLASH_OVERLAY_IMAGE_BLOCK_NAME "\0"         \
        "data_block6=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block7=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block8=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block9=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=10\0"
#else
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_OVERLAY_IMAGE_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block6=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block7=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block8=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=9\0"
#endif
#else
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME "\0"        \
        "data_block2=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block3=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block5=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block6=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block7=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block8=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=9\0"
#else
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block7=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=8\0"
#endif
#endif
  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0xB0000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME            "gphy_firmware"
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_START_ADDR            0xB0010000
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock1"
#endif

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME         "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR         0xB0020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE               0
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock2"
#else
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"
#endif

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0xB00A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock3"
#else
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"
#endif

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
#ifdef CONFIG_OVERLAY
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0xB078FFFF
#else
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0xB07DFFFF
#endif
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_OVERLAY_IMAGE_BLOCK_NAME          "overlay"
  #define IFX_CFG_FLASH_OVERLAY_IMAGE_START_ADDR          0xB0790000
  #define IFX_CFG_FLASH_OVERLAY_IMAGE_SIZE                0x50000
  #define IFX_CFG_FLASH_OVERLAY_IMAGE_END_ADDR            0xB07DFFFF

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0xB07E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0xB07EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0xB07F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x2000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0xB07F1FFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME               "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR               0xB07F2000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                     0x1000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR                 0xB07F2FFF
  
  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	          "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	  	  0xB07F3000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE		          0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR		  0xB07F4FFF

  #define IFX_CFG_FLASH_END_ADDR                          0xB07FFFFF


#else
  #error "ERROR!! Define flash size first!"
#endif

#endif /*CONFIG_FIRMWARE_IN_ROOTFS*/


#endif /*CONFIG_BOOT_FROM_NOR*/

/***************************************************************************/
/***************************************************************************/
/***************SPI FLASH map starts here***********************************/
/***************************************************************************/
/***************************************************************************/

#ifdef CONFIG_BOOT_FROM_SPI

#ifdef CONFIG_SPI_FLASH_1M
#define IFX_CONFIG_FLASH_SIZE 1
#elif CONFIG_SPI_FLASH_2M
#define IFX_CONFIG_FLASH_SIZE 2
#elif CONFIG_SPI_FLASH_4M
#define IFX_CONFIG_FLASH_SIZE 4
#elif CONFIG_SPI_FLASH_8M
#define IFX_CONFIG_FLASH_SIZE 8
#elif CONFIG_SPI_FLASH_16M
#define IFX_CONFIG_FLASH_SIZE 16
#endif

#ifndef IFX_CONFIG_FLASH_SIZE
#define IFX_CONFIG_FLASH_SIZE 4
#endif

#ifdef CONFIG_FIRMWARE_IN_ROOTFS
//1MB flash partition
#if (IFX_CONFIG_FLASH_SIZE == 1)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00020000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0x00020000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0x000F5FFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0x000F6000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x8000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0x001FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0x000FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0x000FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0x000FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0x000FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0x000FFFFF
//2MB flash partition
#elif (IFX_CONFIG_FLASH_SIZE == 2)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0x00010000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0x001F5FFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0x001F6000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x8000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0x001FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0x001FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0x001FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0x001FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0x001FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0x001FFFFF

//4MB flash partition
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
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block6=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=7\0"
        
  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0x00010000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock1"

 #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x003DFFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x003E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x003EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x003F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x003F0FFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x003F1000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x1000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x003F1FFF
  
  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	      	  "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	      	  0x003F2000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE		          0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR		  0x003F3FFF  

  #define IFX_CFG_FLASH_END_ADDR                         0x003FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 8)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00020000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block6=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x00020000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x007DFFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x007E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x007EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x007F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x007F0FFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x007F1000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x1000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x007F1FFF
  
  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	      	  "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	      	  0x007F2000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE		          0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR		  0x007F3FFF  

  #define IFX_CFG_FLASH_END_ADDR                          0x007FFFFF
  
#else
  #error "ERROR!! Define flash size first!"
#endif

#else /*Not defined CONFIG_FIRMWARE_IN_ROOTFS*/
#if (IFX_CONFIG_FLASH_SIZE == 1)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00020000\0"                                      \
        "part2_begin=0x000A0000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME       "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR       0x00020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE             0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME    "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0x000A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0x000F5FFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0x000F6000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x8000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0x000FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0x000FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0x000FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0x000FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0x000FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0x000FFFFF

//2MB flash partition
#elif (IFX_CONFIG_FLASH_SIZE == 2)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00020000\0"                                      \
        "part2_begin=0x000A0000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME       "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR       0x00020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE             0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME    "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0x000A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0x001F5FFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0x001F6000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x8000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0x001FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0x001FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0x001FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0x001FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0x001FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0x001FFFFF

//4MB flash partition
#elif (IFX_CONFIG_FLASH_SIZE == 4)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00020000\0"                                      \
        "part2_begin=0x000A0000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block7=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=8\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME        "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR        0x00020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE              0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME     "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0x000A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x003DFFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x003E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x003EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x003F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x003F0FFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x003F1000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x1000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x003F1FFF
  
  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	      	  "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	      	  0x003F2000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE		          0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR		  0x003F3FFF  

  #define IFX_CFG_FLASH_END_ADDR                         0x003FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 8)
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "part2_begin=0x00020000\0"                                      \
        "part3_begin=0x000A0000\0"                                      \
        "total_part=4\0"
#else
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00020000\0"                                      \
        "part2_begin=0x000A0000\0"                                      \
        "total_part=3\0"
#endif

#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME "\0"        \
        "data_block2=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block3=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block5=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block6=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block7=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block8=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=9\0"
#else
#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block7=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=8\0"
#endif

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME            "gphy_firmware"
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_START_ADDR            0x00010000
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock1"
#endif

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME         "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR         0x00020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE               0
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock2"
#else
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"
#endif

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x000A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock3"
#else
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"
#endif

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x007DFFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x007E0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x007EFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x007F0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x2000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x007F1FFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME               "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR               0x007F2000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                     0x1000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR                 0x007F2FFF
  
  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	          "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	      	  0x007F3000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE		          0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR		  0x007F4FFF

  #define IFX_CFG_FLASH_END_ADDR                          0x007FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 16)
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "part2_begin=0x00020000\0"                                      \
        "part3_begin=0x000A0000\0"                                      \
        "total_part=4\0"
#else
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00020000\0"                                      \
        "part2_begin=0x000A0000\0"                                      \
        "total_part=3\0"
#endif

#ifdef CONFIG_OVERLAY
  #if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
    #define IFX_CFG_FLASH_DATA_BLOCKS_INFO                              \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME "\0"        \
        "data_block2=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block3=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block5=" IFX_CFG_FLASH_DATA_IMAGE_BLOCK_NAME "\0"         \
        "data_block6=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block7=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block8=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block9=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=10\0"
  #else
    #define IFX_CFG_FLASH_DATA_BLOCKS_INFO                              \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_DATA_IMAGE_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block6=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block7=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block8=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=9\0"
  #endif
#else
   #if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
    #define IFX_CFG_FLASH_DATA_BLOCKS_INFO                              \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME "\0"        \
        "data_block2=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block3=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block5=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block6=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block7=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block8=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=9\0"
  #else
    #define IFX_CFG_FLASH_DATA_BLOCKS_INFO                              \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "data_block7=" IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME "\0"    \
        "total_db=8\0"
  #endif
#endif

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_BLOCK_NAME            "gphy_firmware"
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_START_ADDR            0x00010000
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock1"
#endif

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME         "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR         0x00020000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE               0
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock2"
#else
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"
#endif

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x000A0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
#if !defined( CONFIG_VR9_GPHY_FW_EMBEDDED )
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock3"
#else
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"
#endif

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x00DDFFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

#ifdef CONFIG_OVERLAY
  #define IFX_CFG_FLASH_DATA_IMAGE_BLOCK_NAME             "data"
  #define IFX_CFG_FLASH_DATA_IMAGE_START_ADDR             0x00DE0000
  #define IFX_CFG_FLASH_DATA_IMAGE_SIZE                   0x200000
  #define IFX_CFG_FLASH_DATA_IMAGE_END_ADDR               0x00FDFFFF
#endif

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x00FE0000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x00FEFFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x00FF0000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x2000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x00FF1FFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME               "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR               0x00FF2000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                     0x1000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR                 0x00FF2FFF
  
  #define IFX_CFG_FLASH_WLAN_CFG_BLOCK_NAME	          "wlanconfig"
  #define IFX_CFG_FLASH_WLAN_CFG_START_ADDR	      	  0x00FF3000
  #define IFX_CFG_FLASH_WLAN_CFG_SIZE		          0x2000
  #define IFX_CFG_FLASH_WLAN_CFG_END_ADDR		  0x00FF4FFF

  #define IFX_CFG_FLASH_END_ADDR                          0x00FFFFFF
#else
  #error "ERROR!! Define flash size first!"
#endif

#endif /*CONFIG_FIRMWARE_IN_ROOTFS*/


#endif /*CONFIG_BOOT_FROM_SPI*/
/* End of Board specific configurations
 *-----------------------------------------------------------------------
 */



/***************************************************************************/
/***************************************************************************/
/***************NAND FLASH map starts here***********************************/
/***************************************************************************/
/***************************************************************************/

#ifdef CONFIG_BOOT_FROM_NAND

#ifdef CONFIG_NAND_FLASH_2M
#define IFX_CONFIG_FLASH_SIZE 2
#elif CONFIG_NAND_FLASH_4M
#define IFX_CONFIG_FLASH_SIZE 4
#elif CONFIG_NAND_FLASH_8M
#define IFX_CONFIG_FLASH_SIZE 8
#elif CONFIG_NAND_FLASH_128M
#define IFX_CONFIG_FLASH_SIZE 128
#elif CONFIG_NAND_FLASH_512M
#define IFX_CONFIG_FLASH_SIZE 512
#elif  CONFIG_NAND_FLASH_1024M
#define IFX_CONFIG_FLASH_SIZE 1024
#endif

#ifndef IFX_CONFIG_FLASH_SIZE
#define IFX_CONFIG_FLASH_SIZE 4
#endif

#ifdef CONFIG_FIRMWARE_IN_ROOTFS
//2MB flash partition
#if (IFX_CONFIG_FLASH_SIZE == 2)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "total_part=2\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0x00010000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0x001FADFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0x001FB200
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x4000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0x001FEDFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0x001FEE00
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0x001FFDFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0x001FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0x001FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0x001FFFFF

//4MB flash partition
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
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=6\0"
        
  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0x00010000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x003EDFFF  
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x007EE000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x007FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x003FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x003FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x003FF000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x400
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x003FF3FF

  #define IFX_CFG_FLASH_END_ADDR                          0x003FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 8)
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
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x00010000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x007EDFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x007EE000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x007FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x007FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x007FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x007FF000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x400
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x007FF3FF

 
  #define IFX_CFG_FLASH_END_ADDR                         0x007FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 128)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00040000\0"                                      \
        "part2_begin=0x002C0000\0"                                      \
        "part3_begin=0x06C40000\0"                                      \
        "part4_begin=0x07040000\0"                                      \
        "part5_begin=0x07080000\0"                                      \
        "total_part=6\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block4=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0x40000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x00040000
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0x0
  #define IFX_CFG_FLASH_KERNEL_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x002C0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0x6980000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x06C40000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x400000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x0703FFFF
  #define IFX_CFG_FLASH_SYSTEM_CFG_MTDBLOCK_NAME          "/dev/mtdblock3"

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x7040000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x10000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x0704FFFF
  #define IFX_CFG_FLASH_UBOOT_CFG_MTDBLOCK_NAME           "/dev/mtdblock4"

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x07080000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x40000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x070BFFFF
  #define IFX_CFG_FLASH_DECT_CFG_MTDBLOCK_NAME       "/dev/mtdblock5"

  #define IFX_CFG_FLASH_END_ADDR                         0x07FFFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 512)
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
        "data_block5=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=6\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0x40000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x00040000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x007EDFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x007EE000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x007FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x007FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x007FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x007FF000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x400
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x007FF3FF

  #define IFX_CFG_FLASH_END_ADDR                         0x007FFFFF


#else
  #error "ERROR!! Define flash size first!"
#endif

#else /*Not defined CONFIG_FIRMWARE_IN_ROOTFS*/
//2MB flash partition
#if (IFX_CONFIG_FLASH_SIZE == 2)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "part2_begin=0x00040000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO          \
  "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"  \
  "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0" \
  "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0" \
  "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0" \
  "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"   \
  "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"    \
  "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"  \
  "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME          "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR          0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME       "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR       0x00010000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE             0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME    "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME         "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR         0x00040000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME         "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR         0x001FADFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE               0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME           "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR           0x001FAE00
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                 0x4000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR             0x001FEDFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME            "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR            0x001FEE00
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                  0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR              0x001FFDFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME        "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR        0x001FFE00
  #define IFX_CFG_FLASH_DECT_CFG_SIZE              0x0200
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR          0x001FFFFF

  #define IFX_CFG_FLASH_END_ADDR                        0x001FFFFF

//4MB flash partition
#elif (IFX_CONFIG_FLASH_SIZE == 4)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "part2_begin=0x00040000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME           "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR           0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME        "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR        0x00010000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE              0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME     "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME          "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR          0x00040000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME       "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x003EDFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x003EE000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x003FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x003FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x003FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x003FF000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x400
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x003FF3FF
  
  #define IFX_CFG_FLASH_END_ADDR                         0x003FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 8)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00010000\0"                                      \
        "part2_begin=0x00050000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME         "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR         0x00010000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x00050000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x007EDFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x007EE000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x007FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x007FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x1000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x007FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x007FF000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x400
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x007FF3FF
  
 
  #define IFX_CFG_FLASH_END_ADDR                          0x007FFFFF
  
#elif (IFX_CONFIG_FLASH_SIZE == 128)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00040000\0"                                      \
        "part2_begin=0x000C0000\0"                                      \
        "part3_begin=0x002C0000\0"                                      \
        "part4_begin=0x06C40000\0"                                      \
        "part5_begin=0x07040000\0"                                      \
        "part6_begin=0x07080000\0"                                      \
        "total_part=7\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME         "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR         0x00040000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x000C0000
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_KERNEL_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x002C0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0x6980000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock3"

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x06C40000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x400000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x0703FFFF
  #define IFX_CFG_FLASH_SYSTEM_CFG_MTDBLOCK_NAME          "/dev/mtdblock4"

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x07040000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x10000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x0704FFFF
  #define IFX_CFG_FLASH_UBOOT_CFG_MTDBLOCK_NAME           "/dev/mtdblock5"

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x07080000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x40000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x070BFFFF
  #define IFX_CFG_FLASH_DECT_CFG_MTDBLOCK_NAME       "/dev/mtdblock6"

  #define IFX_CFG_FLASH_END_ADDR                          0x07FFFFFF
#elif (IFX_CONFIG_FLASH_SIZE == 512)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00040000\0"                                      \
        "part2_begin=0x000C0000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=7\0"

  #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME         "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR         0x00040000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x000C0000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x007EDFFF
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x007EE000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x10000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x007FDFFF

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x007FE000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x10000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x007FEFFF

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x007FF000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x400
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x007FF3FF
  
 
  #define IFX_CFG_FLASH_END_ADDR                          0x007FFFFF

#elif (IFX_CONFIG_FLASH_SIZE == 1024)
#define IFX_CFG_FLASH_PARTITIONS_INFO                                   \
        "part0_begin=0x00000000\0"                                      \
        "part1_begin=0x00040000\0"                                      \
        "part2_begin=0x000C0000\0"                                      \
        "total_part=3\0"

#define IFX_CFG_FLASH_DATA_BLOCKS_INFO                                  \
        "data_block0=" IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME "\0"        \
        "data_block1=" IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME "\0"     \
        "data_block2=" IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME "\0"       \
        "data_block3=" IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME "\0"       \
        "data_block4=" IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME "\0"         \
        "data_block5=" IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME "\0"          \
        "data_block6=" IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME "\0"      \
        "total_db=7\0"

   #define IFX_CFG_FLASH_UBOOT_IMAGE_BLOCK_NAME            "uboot"
  #define IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR            0x00000000
  #define IFX_CFG_FLASH_UBOOT_IMAGE_SIZE                  0
  #define IFX_CFG_FLASH_UBOOT_IMAGE_MTDBLOCK_NAME         "/dev/mtdblock0"

  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_BLOCK_NAME         "firmware"
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR         0x00100000
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE               0
  #define IFX_CFG_FLASH_FIRMWARE_IMAGE_MTDBLOCK_NAME      "/dev/mtdblock1"

  #define IFX_CFG_FLASH_KERNEL_IMAGE_BLOCK_NAME           "kernel"
  #define IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR           0x00200000
  #define IFX_CFG_FLASH_KERNEL_IMAGE_SIZE                 0
  #define IFX_CFG_FLASH_KERNEL_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock2"

  #define IFX_CFG_FLASH_ROOTFS_IMAGE_BLOCK_NAME           "rootfs"
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR           0x00400000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE                 0x08000000
  #define IFX_CFG_FLASH_ROOTFS_IMAGE_MTDBLOCK_NAME        "/dev/mtdblock3"

  #define IFX_CFG_FLASH_SYSTEM_CFG_BLOCK_NAME             "sysconfig"
  #define IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR             0x08000000
  #define IFX_CFG_FLASH_SYSTEM_CFG_SIZE                   0x100000
  #define IFX_CFG_FLASH_SYSTEM_CFG_END_ADDR               0x081FFFFF
  #define IFX_CFG_FLASH_SYSTEM_CFG_MTDBLOCK_NAME          "/dev/mtdblock4"

  #define IFX_CFG_FLASH_UBOOT_CFG_BLOCK_NAME              "ubootconfig"
  #define IFX_CFG_FLASH_UBOOT_CFG_START_ADDR              0x08200000
  #define IFX_CFG_FLASH_UBOOT_CFG_SIZE                    0x10000
  #define IFX_CFG_FLASH_UBOOT_CFG_END_ADDR                0x082fffff
  #define IFX_CFG_FLASH_UBOOT_CFG_MTDBLOCK_NAME           "/dev/mtdblock5"

  #define IFX_CFG_FLASH_DECT_CFG_BLOCK_NAME          "dectconfig"
  #define IFX_CFG_FLASH_DECT_CFG_START_ADDR          0x08300000
  #define IFX_CFG_FLASH_DECT_CFG_SIZE                0x100000
  #define IFX_CFG_FLASH_DECT_CFG_END_ADDR            0x083fffff
  #define IFX_CFG_FLASH_DECT_CFG_MTDBLOCK_NAME       "/dev/mtdblock6"

  #define IFX_CFG_FLASH_END_ADDR                          0x08400000

#else
  #error "ERROR!! Define flash size first!"
#endif

#endif /*CONFIG_FIRMWARE_IN_ROOTFS*/


#endif /*CONFIG_BOOT_FROM_SPI*/


/* End of Board specific configurations
 *-----------------------------------------------------------------------
 */

/*************************************************************************/
