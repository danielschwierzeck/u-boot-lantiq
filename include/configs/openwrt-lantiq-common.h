/*
 * Copyright (C) 2013 Luka Perkov <luka@openwrt.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __OPENWRT_LANTIQ_COMMON_H
#define __OPENWRT_LANTIQ_COMMON_H

/* Commands */
#if defined(CONFIG_LTQ_SUPPORT_ETHERNET)
#define CONFIG_CMD_PING
#endif

/* Compression */
#define CONFIG_LZMA

/* Auto boot */
#define CONFIG_BOOTDELAY	2

/* Environment */
#if !defined(CONFIG_SYS_BOOT_RAM)
#define CONFIG_BOOTCOMMAND \
	"bootm ${kernel_addr}"
#endif

/* Ethernet */
#if defined(CONFIG_LTQ_SUPPORT_ETHERNET)
#define CONFIG_ETHADDR		00:01:02:03:04:05
#define CONFIG_SERVERIP		192.168.1.2
#define CONFIG_IPADDR		192.168.1.1
#endif

/* Unnecessary */
#undef CONFIG_BOOTM_NETBSD
#undef CONFIG_BOOTM_PLAN9
#undef CONFIG_BOOTM_RTEMS

#endif /* __OPENWRT_LANTIQ_COMMON_H */
