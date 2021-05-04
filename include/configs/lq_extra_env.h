
#ifdef CONFIG_DRIVER_AR10
#define WLAN_ENV			"wlanm="CONFIG_WLANM"\0"
  #ifndef CONFIG_AR10_GPHY_FW_EMBEDDED
   #define GPHY_FW_ADDR_ENV	"gphy_fw_addr="__stringify(CONFIG_AR10_EXTERN_GPHY_FW_ADDR)"\0"
   #define GPHY_UPDATE_ENV	"update_gphyfirmware="CONFIG_UPDATE_GPHYFIRMWARE"\0"
  #else
   #define GPHY_FW_ADDR_ENV	""
   #define GPHY_UPDATE_ENV	""
  #endif /* CONFIG_AR10_GPHY_FW_EMBEDDED */
#elif CONFIG_DRIVER_HN1
#define WLAN_ENV		""
  #ifdef CONFIG_HN1_GPHY_FW_EMBEDDED
   #define GPHY_FW_ADDR_ENV	"gphy_fw_addr="__stringify(CONFIG_HN1_EXTERN_GPHY_FW_ADDR)"\0"
  #else
   #define GPHY_FW_ADDR_ENV  ""
  #endif /* CONFIG_HN1_GPHY_FW_EMBEDDED */
#elif CONFIG_DRIVER_VBG400
#define WLAN_ENV		""
#define GPHY_FW_ADDR_ENV  ""
#elif CONFIG_DRIVER_VR9
#define WLAN_ENV		""
  #ifndef CONFIG_VR9_GPHY_FW_EMBEDDED
   #define GPHY_FW_ADDR_ENV	"gphy_fw_addr="__stringify(CONFIG_VR9_EXTERN_GPHY_FW_ADDR)"\0"
   #define GPHY_UPDATE_ENV	"update_gphyfirmware="CONFIG_UPDATE_GPHYFIRMWARE"\0"
  #else
   #define GPHY_FW_ADDR_ENV  ""
   #define GPHY_UPDATE_ENV ""
  #endif /* CONFIG_VR9_GPHY_FW_EMBEDDED */
#elif CONFIG_DRIVER_GRX500
#define WLAN_ENV		""
  #ifndef CONFIG_GRX500_GPHY_FW_EMBEDDED
   #define GPHY_FW_ADDR_ENV 	"gphy_fw_addr="__stringify(CONFIG_GRX500_EXTERN_GPHY_FW_ADDR)"\0"
   #define GPHY_UPDATE_ENV	"update_gphyfirmware="CONFIG_UPDATE_GPHYFIRMWARE"\0"
  #else
   #define GPHY_FW_ADDR_ENV  ""
   #define GPHY_UPDATE_ENV ""
  #endif /* CONFIG_GRX500_GPHY_FW_EMBEDDED */
#else
  #define WLAN_ENV        	""
  #define GPHY_FW_ADDR_ENV 	""
  #define GPHY_UPDATE_ENV ""
#endif /* CONFIG_DRIVER_XXX  */

#ifdef CONFIG_UPDATE_FIRMWARE
#define UPDATE_FIRMWARE_ENV		"update_firmware="CONFIG_UPDATE_FIRMWARE"\0"
#else
#define UPDATE_FIRMWARE_ENV		""
#endif /* CONFIG_UPDATE_FIRMWARE */

#ifndef CONFIG_FIRMWARE_IN_ROOTFS
#define FIRMWARE_ENV_ADDR	"f_firmware_addr=" __stringify(IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR) "\0"
#define FIRMWARE_ENV_SIZE	"f_firmware_size=" __stringify(IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE) "\0"
#else
#define FIRMWARE_ENV_ADDR	""
#define FIRMWARE_ENV_SIZE	""
#endif /* CONFIG_FIRMWARE_IN_ROOTFS */

#ifdef IFX_CFG_FLASH_FIRMWARE_DIAG_START_ADDR
#define F_FWDIAG_ADDR "f_fwdiag_addr=" __stringify(IFX_CFG_FLASH_FIRMWARE_DIAG_START_ADDR) "\0"
#else
#define F_FWDIAG_ADDR
#endif
#ifdef IFX_CFG_FLASH_FIRMWARE_DIAG_SIZE
#define F_FWDIAG_SIZE "f_fwdiag_size=" __stringify(IFX_CFG_FLASH_FIRMWARE_DIAG_SIZE) "\0"
#else
#define F_FWDIAG_SIZE
#endif

#ifndef MACHTYPE
#ifdef CONFIG_BOARD_NAME
#define MACHTYPE "machtype=" CONFIG_BOARD_NAME "\0"
#else
#define MACHTYPE
#endif
#endif

#if defined(CONFIG_LTQ_BOOT_FROM_NAND) || defined(CONFIG_SPI_WITH_NAND)
#define UPDATE_NANDBOOT	"update_nandboot="CONFIG_UPDATE_NANDBOOT"\0"
 #ifdef CONFIG_CMD_UBI
  #define UBI_INIT_ENV	"ubi_init="CONFIG_UBI_INIT"\0"
 #ifdef CONFIG_DUAL_IMAGE
  #define DUAL_IMAGE_ENV 					\
  "update_chk="CONFIG_UPDATE_CHK"\0"		\
  "switchbankA="CONFIG_SWITCH_BANKA"\0"		\
  "switchbankB="CONFIG_SWITCH_BANKB"\0"		\
  "check_image0="CONFIG_CHECK_IMAGE0"\0"	\
  "check_image1="CONFIG_CHECK_IMAGE1"\0"	\
  "check_image2="CONFIG_CHECK_IMAGE2"\0"	\
  "check_image3="CONFIG_CHECK_IMAGE3"\0"	\
  ""
 #else
   #define DUAL_IMAGE_ENV  ""
 #endif /* DUAL_IMAGE_ENV */
 #else
   #define UBI_INIT_ENV	""
   #define DUAL_IMAGE_ENV  ""
 #endif /* CONFIG_CMD_UBI */
#else
#define UPDATE_NANDBOOT	""
#define UBI_INIT_ENV	""
#define	DUAL_IMAGE_ENV	""
#endif /* CONFIG_LTQ_BOOT_FROM_NAND || CONFIG_SPI_WITH_NAND */

#ifdef CONFIG_PRX300_EXTERNAL_PHY
  #define PHYMODE	"lan0-xpcs-mode="CONFIG_LAN0_LINK_MODE"\0" 	\
			"lan1-xpcs-mode="CONFIG_LAN1_LINK_MODE"\0"
#else
  #define PHYMODE ""
#endif 


#ifdef CONFIG_OVERLAY											
#define OVERLAY_ENV												\
  "f_data_addr=" __stringify(IFX_CFG_FLASH_DATA_IMAGE_START_ADDR) "\0"   \
  "f_data_size=" __stringify(IFX_CFG_FLASH_DATA_IMAGE_SIZE) "\0"   		\
  "f_data_end=" __stringify(IFX_CFG_FLASH_DATA_IMAGE_END_ADDR) "\0"
#else
#define OVERLAY_ENV		""
#endif /* CONFIG_OVERLAY */

#ifndef CONFIG_ENV_IS_NOWHERE
  #define DEFINED_ENV_CFG															\
  "reset_uboot_config="CONFIG_RESET_UBOOT_CONFIG"\0" 								\
  "reset_ddr_config="CONFIG_RESET_DDR_CONFIG"\0"									\
  "reset_sysconfig="CONFIG_RESET_SYSCONFIG"\0"										\
  "mtdparts="CONFIG_MTDPARTS"\0"                     								\
  IFX_CFG_FLASH_PARTITIONS_INFO   													\
  "flash_end=" __stringify(IFX_CFG_FLASH_END_ADDR) "\0"   							\
  IFX_CFG_FLASH_DATA_BLOCKS_INFO  													\
  "f_uboot_addr=" __stringify(IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR) "\0"      		\
  "f_uboot_size=" __stringify(IFX_CFG_FLASH_UBOOT_IMAGE_SIZE) "\0"            		\
  "f_ubootconfig_addr=" __stringify(CONFIG_ENV_OFFSET) "\0"  						\
  "f_ubootconfig_size=" __stringify(CONFIG_ENV_SIZE) "\0"        					\
  "f_ubootconfig_end=" __stringify(IFX_CFG_FLASH_UBOOT_CFG_END_ADDR) "\0"			\
  ""
  #ifdef CONFIG_LTQ_BOOT_FROM_NAND													
   #define DEFINED_ENV_RANGE	"f_ubootconfig_range=" __stringify(CONFIG_ENV_RANGE) "\0"	
   #ifdef CONFIG_ENV_REDUND	
    #define DEFINED_ENV_REDUND_ADDR	"f_red_ubootconfig_addr=" __stringify(CONFIG_ENV_OFFSET_REDUND) "\0"
   #else
	 #define DEFINED_ENV_REDUND_ADDR 	""
    #endif /* CONFIG_ENV_REDUND */
   #else
    #define DEFINED_ENV_RANGE			""
	#define DEFINED_ENV_REDUND_ADDR 	""
   #endif /* CONFIG_LTQ_BOOT_FROM_NAND */
#else
#define DEFINED_ENV_CFG 				""
#define DEFINED_ENV_REDUND_ADDR    ""
#define DEFINED_ENV_RANGE           ""
#endif /* CONFIG_ENV_IS_NOWHERE */

#if defined(CONFIG_DRIVER_GRX500) || defined(CONFIG_DRIVER_PRX300)
#define BOOTCORE_ENV_CMD												\
 "update_bootcore="CONFIG_UPDATE_BOOTCORE"\0"                            \
 "run_bootcore="CONFIG_RUN_BOOTCORE"\0"                                  \
 "bootcore="CONFIG_BOOT_CORE"\0"
#else
#define BOOTCORE_ENV_CMD		""
#endif

#define CONFIG_EXTRA_ENV_SETTINGS 			\
  "mem="CONFIG_MEM"\0"                       \
  "phym="CONFIG_PHYM"\0"                      \
  "ipaddr=" CONFIG_IP_ADDRESS "\0"             	\
  "serverip=" CONFIG_SERVER_IP_ADDRESS "\0"         \
  "ethaddr=" CONFIG_ETHERNET_ADDRESS "\0"         \
  WLAN_ENV						\
  "netdev=" CONFIG_ETHERNET_DEVICE "\0"             \
  "console="CONFIG_CONSOLE"\0"                      \
  "tftppath="CONFIG_TFTPPATH"\0"                    \
  "loadaddr=" CONFIG_TFTP_LOAD_ADDRESS "\0"         \
  "rootpath="CONFIG_ROOT_PATH "\0"                  \
  "rootfsmtd="CONFIG_ROOTFSMTD"\0"                  \
  "nfsargs= "CONFIG_NFSARGS"\0"                     \
  "ramargs="CONFIG_RAMARGS"\0"                      \
  "addip="CONFIG_ADDIP"\0"                          \
  "addmisc="CONFIG_ADDMISC" \0"                     \
  "flash_nfs="CONFIG_FLASH_NFS"\0"                  \
  "net_nfs="CONFIG_NET_NFS"\0"                      \
  "net_flash="CONFIG_NET_FLASH"\0"                  \
  "net_ram="CONFIG_NET_RAM"\0"                      \
  "u-boot="CONFIG_U_BOOT"\0"                        \
  "rootfs="CONFIG_ROOTFS"\0"                        \
  "firmware="CONFIG_FIRMWARE"\0"                    \
  "fullimage="CONFIG_FULLIMAGE"\0"                  \
  "totalimage="CONFIG_TOTALIMAGE"\0"                \
  "load=tftp ${loadaddr} ${u-boot}\0"               \
  "update=protect off 1:0-2;era 1:0-2;cp.b ${loadaddr} B0000000 ${filesize}\0"  \
  "flashargs="CONFIG_FLASHARGS"\0"                  \
  "flash_flash="CONFIG_FLASH_FLASH"\0"              \
   UPDATE_NANDBOOT									\
   UBI_INIT_ENV										\
   DUAL_IMAGE_ENV 									\
  "update_uboot="CONFIG_UPDATE_UBOOT"\0"            \
  "update_kernel="CONFIG_UPDATE_KERNEL"\0"          \
  "update_bootloader="CONFIG_UPDATE_BOOTLOADER"\0"	\
  "update_rootfs="CONFIG_UPDATE_ROOTFS"\0"          \
  UPDATE_FIRMWARE_ENV								\
  "update_fullimage="CONFIG_UPDATE_FULLIMAGE"\0"    \
  "update_totalimage="CONFIG_UPDATE_TOTALIMAGE"\0"  \
  GPHY_FW_ADDR_ENV									\
  GPHY_UPDATE_ENV									\
  BOOTCORE_ENV_CMD									\
  DEFINED_ENV_CFG 									\
  DEFINED_ENV_RANGE           						\
  DEFINED_ENV_REDUND_ADDR    						\
  "f_gphy_firmware_addr=" __stringify(IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_START_ADDR) "\0" \
  "f_gphy_firmware_size=" __stringify(IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_SIZE) "\0"       \
  "f_gphy_firmware_end=" __stringify(IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_END_ADDR) "\0"    \
  "f_kernel_addr=" __stringify(IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR) "\0"    			\
  "f_kernel_size=" __stringify(IFX_CFG_FLASH_KERNEL_IMAGE_SIZE) "\0"         	\
  "f_kernel_end=" __stringify(IFX_CFG_FLASH_KERNEL_IMAGE_END_ADDR) "\0"       \
  "f_rootfs_addr=" __stringify(IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR) "\0"    \
  "f_rootfs_size=" __stringify(IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE) "\0"          \
  "f_rootfs_end=" __stringify(IFX_CFG_FLASH_ROOTFS_IMAGE_END_ADDR) "\0"     		\
  FIRMWARE_ENV_ADDR														\
  FIRMWARE_ENV_SIZE													\
  F_FWDIAG_ADDR	\
  F_FWDIAG_SIZE	\
  "f_sysconfig_addr=" __stringify(IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR) "\0"    \
  "f_sysconfig_size=" __stringify(IFX_CFG_FLASH_SYSTEM_CFG_SIZE) "\0"          \
  "f_dectconfig_addr=" __stringify(IFX_CFG_FLASH_DECT_CFG_START_ADDR) "\0"    \
  "f_dectconfig_size=" __stringify(IFX_CFG_FLASH_DECT_CFG_SIZE) "\0"          \
  "f_wlanconfig_addr= " __stringify(IFX_CFG_FLASH_WLAN_CFG_START_ADDR) "\0"  \
  "f_wlanconfig_size=" __stringify(IFX_CFG_FLASH_WLAN_CFG_SIZE) "\0"  		\
  "f_ddrconfig_addr=" __stringify(IFX_CFG_FLASH_DDR_CFG_START_ADDR) "\0"   	\
  "f_ddrconfig_size=" __stringify(IFX_CFG_FLASH_DDR_CFG_SIZE) "\0"        \
  "f_ddrconfig_end=" __stringify(IFX_CFG_FLASH_DDR_CFG_END_ADDR) "\0"    \
  OVERLAY_ENV													\
  PHYMODE								\
  MACHTYPE \
  CONFIG_EXTRA_ENV_DATA		\
  ""
