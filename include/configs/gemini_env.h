/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef _GEMINI_ENV_H_
#define _GEMINI_ENV_H_

/* Network */
#define CONFIG_TFTP_BLOCKSIZE	1400
#define CONFIG_NET_RETRY_COUNT	10
#define CONFIG_BOOTP_SEND_HOSTNAME

/* MTD */
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTD
#define CONFIG_CMD_MTDPARTS
#if defined(CONFIG_NAND_BOOT)
#define CONFIG_CMD_UBI
#define CONFIG_RBTREE
#define CONFIG_UBI_SILENCE_MSG
#endif

#define CONFIG_LZMA

#if defined(CONFIG_UART_BOOT)
#define CONFIG_ENV_IS_NOWHERE
#endif

#if defined(CONFIG_NAND_BOOT)
#define CONFIG_ENV_IS_IN_UBI
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_UBI_PART		"ubi"
#define CONFIG_ENV_UBI_VOLUME		"uboot_env"
#endif

/* Environment */
#define CONFIG_IPADDR		192.168.100.1
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_SERVERIP		192.168.100.100
#define CONFIG_GATEWAYIP	192.168.100.100
#define CONFIG_ETHADDR		10:7b:ef:ff:00:10
#define CONFIG_LOADADDR		CONFIG_SYS_LOAD_ADDR

#define CONFIG_ENV_NETDEV					\
	"netdev=lan1\0"

#define CONFIG_ENV_ETHADDR					\
	"ethaddr="__stringify(CONFIG_ETHADDR)"\0"

#define CONFIG_ENV_MTDPARTS					\
	"mtdids="MTDIDS_DEFAULT"\0"				\
	"mtdparts="MTDPARTS_DEFAULT"\0"

#define CONFIG_ENV_WRITE_UBOOT_NAND				\
	"write-uboot-nand="					\
	"nand erase 0 $filesize && "				\
	"nand write $fileaddr 0 $filesize\0"

#define CONFIG_ENV_LOAD_UBOOT_NAND				\
	"load-uboot-nand=tftpboot $loadaddr u-boot.ltq.lzo.nandspl\0"

#define CONFIG_ENV_UPDATE_UBOOT_NAND				\
	"update-uboot-nand=run load-uboot-nand write-uboot-nand\0"

#define CONFIG_ENV_LOAD_UBOOT_RAM				\
	"uboot-ram=tftpboot " __stringify(CONFIG_SYS_TEXT_BASE)	\
	" u-boot.bin && go " __stringify(CONFIG_SYS_TEXT_BASE) "\0"

#define CONFIG_ENV_GEMINI					\
	CONFIG_ENV_NETDEV					\
	CONFIG_ENV_ETHADDR					\
	CONFIG_ENV_MTDPARTS					\
	CONFIG_ENV_WRITE_UBOOT_NAND				\
	CONFIG_ENV_LOAD_UBOOT_NAND				\
	CONFIG_ENV_UPDATE_UBOOT_NAND				\
	CONFIG_ENV_LOAD_UBOOT_RAM

#endif /* _GEMINI_ENV_H_ */
