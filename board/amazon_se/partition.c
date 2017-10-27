/******************************************************************************
 * **
 * ** FILE NAME    : partition.c
 * ** PROJECT      : AMAZON_SE
 * ** MODULES      : 
 * **
 * ** DATE         : 23 Apr 2005
 * ** AUTHOR       : Wu Qi Ming
 * ** DESCRIPTION  : partition map for flashes
 * ** COPYRIGHT    :       Copyright (c) 2010
 * **                      Lantiq Asia Pacific, Pte, Ltd
 * **                      8 Kallang Sector, Singapore 349282
 * **
 * **    This program is free software; you can redistribute it and/or modify
 * **    it under the terms of the GNU General Public License as published by
 * **    the Free Software Foundation; either version 2 of the License, or
 * **    (at your option) any later version.
 * **
 * ** HISTORY
 * ** $Date        $Author      $Version   $Comment
 * ** 14 Apr 2010  Wu Qi Ming   1.0        initial version
 * *******************************************************************************/

#include <config.h>
#include <environment.h>

#ifdef CONFIG_NOR_FLASH_AUTO



#ifdef CONFIG_FIRMWARE_IN_ROOTFS
xway_flash_partition_map_info flash_map[] = {
	              {
                   2, /*2M NOR flash map*/
                   "ifx_nor0:64k(uboot),-(rootfs)",
                  {  
                   {"uboot", 0, 0xB0000000, 0x10000},	
                   {"rootfs", 1, 0xB0010000, 0},
                   {"kernel", 1, 0xB01FBFFF, 0},
                   {"sysconfig", 1, 0xB01FA000,0x4000},
                   {"ubootconfig",1, 0xB01FE000, 0x1000},
                   {"fwdiag", 1, 0xB01FF000, 0x200}
                  }               	
	              },
	             {
                   4, /*4M NOR flash map*/
                   "ifx_nor0:64k(uboot),-(rootfs)",
                  {  
                    {"uboot", 0, 0xB0000000, 0x10000},
                    {"rootfs", 1, 0xB0010000, 0},
                    {"kernel", 1, 0xB03F6DFF, 0},
                    {"sysconfig", 1, 0xB03ECE00,0x10000},
                    {"ubootconfig",1, 0xB03FEE00, 0x1000},
                    {"fwdiag", 1, 0xB03FFE00, 0x200}
                  }               	
	              },
	              {
                   8, /*8M NOR flash map*/
                   "ifx_nor0:64k(uboot),-(rootfs)",
                  {  
                    {"uboot", 0, 0xB0000000, 0x10000},
                    {"rootfs", 1, 0xB0010000, 0},
                    {"kernel", 1, 0xB07EDFFF, 0},
                    {"sysconfig", 1, 0xB07EE000,0x10000},
                    {"ubootconfig",1, 0xB07FE000, 0x1000},
                    {"fwdiag", 1, 0xB07FF000, 0x400},
                  } 
                                	
	              },
	              {
	              	 0,
	              }
};
#else //!CONFIG_FIRMWARE_IN_ROOTFS
xway_flash_partition_map_info flash_map[] = {
	              {
                   2, /*2M NOR flash map*/
                   "ifx_nor0:64k(uboot),256k(firmware),-(rootfs)",
                  {  
                   {"uboot", 0, 0xB0000000, 0x10000},	
                   {"firmware", 1, 0xB0010000, 0x40000},
                   {"rootfs", 2, 0xB0050000, 0},
                   {"kernel", 2, 0xB01FBFFF, 0},
                   {"sysconfig", 2, 0xB01FA000,0x4000},
                   {"ubootconfig",2, 0xB01FE000, 0x1000},
                   {"fwdiag", 2, 0xB01FF000, 0x200}
                  }               	
	              },
	             {
                   4, /*4M NOR flash map*/
                   "ifx_nor0:64k(uboot),256k(firmware),-(rootfs)",
                  {  
                    {"uboot", 0, 0xB0000000, 0x10000},
                    {"firmware", 1, 0xB0010000, 0x40000},
                    {"rootfs", 2, 0xB0050000, 0},
                    {"kernel", 2, 0xB03F6DFF, 0},
                    {"sysconfig", 2, 0xB03ECE00,0x8000},
                    {"ubootconfig",2, 0xB03FEE00, 0x1000},
                    {"fwdiag", 2, 0xB03FFE00, 0x200}
                  }               	
	              },
	              {
                   8, /*8M NOR flash map*/
                   "ifx_nor0:64k(uboot),256k(firmware),-(rootfs)",
                  {  
                    {"uboot", 0, 0xB0000000, 0x10000},
                    {"firmware", 1, 0xB0010000, 0x40000},
                    {"rootfs", 2, 0xB0050000, 0},
                    {"kernel", 2, 0xB07EDFFF, 0},
                    {"sysconfig", 2, 0xB07EE000,0x10000},
                    {"ubootconfig",2, 0xB07FE000, 0x1000},
                    {"fwdiag", 2, 0xB07FF000, 0x400},
                  }               	
	              },
	              {
	              	 0,
	              }
};

#endif
#endif
