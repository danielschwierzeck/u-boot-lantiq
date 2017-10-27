  "mem="CONFIG_MEM"\0"                              
  "phym="CONFIG_PHYM"\0"                            
#ifdef CONFIG_DRIVER_AR10
  "wlanm="CONFIG_WLANM"\0"
#endif
  "ipaddr=" CONFIG_IP_ADDRESS "\0"                  
  "serverip=" CONFIG_SERVER_IP_ADDRESS "\0"         
  "ethaddr=" CONFIG_ETHERNET_ADDRESS "\0"           
  "sup_mac=" CONFIG_NUMBER_OF_MAC_SUPPORTED "\0"           
  "res_mac=" CONFIG_NUMBER_OF_MAC_RESERVED "\0" 
  "netdev=" CONFIG_ETHERNET_DEVICE "\0"             
  "console="CONFIG_CONSOLE"\0"                      
  "tftppath="CONFIG_TFTPPATH"\0"                    
  "loadaddr=" CONFIG_TFTP_LOAD_ADDRESS "\0"         
  "rootpath="CONFIG_ROOT_PATH "\0"                  
  "rootfsmtd="CONFIG_ROOTFSMTD"\0"                  
  "nfsargs= "CONFIG_NFSARGS"\0"                     
  "ramargs="CONFIG_RAMARGS"\0"                      
  "addip="CONFIG_ADDIP"\0"                          
  "addmisc="CONFIG_ADDMISC" \0"                     
  "flash_nfs="CONFIG_FLASH_NFS"\0"                  
  "net_nfs="CONFIG_NET_NFS"\0"                      
  "net_flash="CONFIG_NET_FLASH"\0"                  
  "net_ram="CONFIG_NET_RAM"\0"                      
  "u-boot="CONFIG_U_BOOT"\0"                        
  "rootfs="CONFIG_ROOTFS"\0"                        
  "firmware="CONFIG_FIRMWARE"\0"                    
  "fullimage="CONFIG_FULLIMAGE"\0"                  
  "totalimage="CONFIG_TOTALIMAGE"\0"                
  "load=tftp $(loadaddr) $(u-boot)\0"               
  "update=protect off 1:0-2;era 1:0-2;cp.b $(loadaddr) B0000000 $(filesize)\0"  
  "flashargs="CONFIG_FLASHARGS"\0"                  
  "flash_flash="CONFIG_FLASH_FLASH"\0"              
#if defined(CONFIG_BOOT_FROM_NAND) || defined(CONFIG_SPI_WITH_NAND)  
  "update_nandboot="CONFIG_UPDATE_NANDBOOT"\0"
 #ifdef CONFIG_CMD_UBI
  "ubi_init="CONFIG_UBI_INIT"\0"
 #ifdef CONFIG_DUAL_IMAGE
  "update_chk="CONFIG_UPDATE_CHK"\0"
  "switchbankA="CONFIG_SWITCH_BANKA"\0"
  "switchbankB="CONFIG_SWITCH_BANKB"\0"
  "check_image0="CONFIG_CHECK_IMAGE0"\0"
  "check_image1="CONFIG_CHECK_IMAGE1"\0"
  "check_image2="CONFIG_CHECK_IMAGE2"\0"
  "check_image3="CONFIG_CHECK_IMAGE3"\0"
 #endif
 #endif  
#endif
  "update_uboot="CONFIG_UPDATE_UBOOT"\0"            
  "update_kernel="CONFIG_UPDATE_KERNEL"\0"          
  "update_bootloader="CONFIG_UPDATE_BOOTLOADER"\0"
  "update_rootfs="CONFIG_UPDATE_ROOTFS"\0"          
#ifdef CONFIG_UPDATE_FIRMWARE
  "update_firmware="CONFIG_UPDATE_FIRMWARE"\0"      
#endif 
  "update_fullimage="CONFIG_UPDATE_FULLIMAGE"\0"    
  "update_totalimage="CONFIG_UPDATE_TOTALIMAGE"\0"  
#if defined(CONFIG_DRIVER_VR9) && !defined(CONFIG_VR9_GPHY_FW_EMBEDDED)
  "update_gphyfirmware="CONFIG_UPDATE_GPHYFIRMWARE"\0"
  "gphy_fw_addr="MK_STR(CONFIG_VR9_EXTERN_GPHY_FW_ADDR)"\0"
#endif
#if defined(CONFIG_DRIVER_AR10) && !defined(CONFIG_AR10_GPHY_FW_EMBEDDED)
  "update_gphyfirmware="CONFIG_UPDATE_GPHYFIRMWARE"\0"
  "gphy_fw_addr="MK_STR(CONFIG_AR10_EXTERN_GPHY_FW_ADDR)"\0"
#endif
#if defined(CONFIG_DRIVER_HN1) && !defined(CONFIG_HN1_GPHY_FW_EMBEDDED)
  "update_gphyfirmware="CONFIG_UPDATE_GPHYFIRMWARE"\0"
  "gphy_fw_addr="MK_STR(CONFIG_HN1_EXTERN_GPHY_FW_ADDR)"\0"
#endif
#if defined(CONFIG_DRIVER_GRX500)
"update_gphyfirmware="CONFIG_UPDATE_GPHYFIRMWARE"\0"
"gphy_fw_addr="MK_STR(CONFIG_GRX500_EXTERN_GPHY_FW_ADDR)"\0"
"update_bootcore="CONFIG_UPDATE_BOOTCORE"\0"
"run_bootcore="CONFIG_RUN_BOOTCORE"\0"
"bootcore="CONFIG_BOOT_CORE"\0"
#endif
#ifndef CONFIG_ENV_IS_NOWHERE
  "reset_uboot_config="CONFIG_RESET_UBOOT_CONFIG"\0" 
  "reset_ddr_config="CONFIG_RESET_DDR_CONFIG"\0"
  "reset_sysconfig="CONFIG_RESET_SYSCONFIG"\0"
  "mtdparts="CONFIG_MTDPARTS"\0"                     
  IFX_CFG_FLASH_PARTITIONS_INFO   
  "flash_end=" MK_STR(IFX_CFG_FLASH_END_ADDR) "\0"   
  IFX_CFG_FLASH_DATA_BLOCKS_INFO  
  "f_uboot_addr=" MK_STR(IFX_CFG_FLASH_UBOOT_IMAGE_START_ADDR) "\0"      
  "f_uboot_size=" MK_STR(IFX_CFG_FLASH_UBOOT_IMAGE_SIZE) "\0"            
  "f_ubootconfig_addr=" MK_STR(CONFIG_ENV_OFFSET) "\0"  
  "f_ubootconfig_size=" MK_STR(CONFIG_ENV_SIZE) "\0"        
  "f_ubootconfig_end=" MK_STR(IFX_CFG_FLASH_UBOOT_CFG_END_ADDR) "\0"     
#ifdef CONFIG_BOOT_FROM_NAND
  "f_ubootconfig_range=" MK_STR(CONFIG_ENV_RANGE) "\0"
#ifdef CONFIG_ENV_REDUND
  "f_red_ubootconfig_addr=" MK_STR(CONFIG_ENV_OFFSET_REDUND) "\0"
#endif
#endif
  "f_gphy_firmware_addr=" MK_STR(IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_START_ADDR) "\0"    
  "f_gphy_firmware_size=" MK_STR(IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_SIZE) "\0"          
  "f_gphy_firmware_end=" MK_STR(IFX_CFG_FLASH_GPHY_FIRMWARE_IMAGE_END_ADDR) "\0"       
  "f_kernel_addr=" MK_STR(IFX_CFG_FLASH_KERNEL_IMAGE_START_ADDR) "\0"    
  "f_kernel_size=" MK_STR(IFX_CFG_FLASH_KERNEL_IMAGE_SIZE) "\0"          
  "f_kernel_end=" MK_STR(IFX_CFG_FLASH_KERNEL_IMAGE_END_ADDR) "\0"       
  "f_rootfs_addr=" MK_STR(IFX_CFG_FLASH_ROOTFS_IMAGE_START_ADDR) "\0"    
  "f_rootfs_size=" MK_STR(IFX_CFG_FLASH_ROOTFS_IMAGE_SIZE) "\0"          
  "f_rootfs_end=" MK_STR(IFX_CFG_FLASH_ROOTFS_IMAGE_END_ADDR) "\0"     
#ifndef CONFIG_FIRMWARE_IN_ROOTFS  
  "f_firmware_addr=" MK_STR(IFX_CFG_FLASH_FIRMWARE_IMAGE_START_ADDR) "\0" 
  "f_firmware_size=" MK_STR(IFX_CFG_FLASH_FIRMWARE_IMAGE_SIZE) "\0"       
#endif
  "f_fwdiag_addr=" MK_STR(IFX_CFG_FLASH_FIRMWARE_DIAG_START_ADDR) "\0"
  "f_fwdiag_size=" MK_STR(IFX_CFG_FLASH_FIRMWARE_DIAG_SIZE) "\0"
  "f_sysconfig_addr=" MK_STR(IFX_CFG_FLASH_SYSTEM_CFG_START_ADDR) "\0"    
  "f_sysconfig_size=" MK_STR(IFX_CFG_FLASH_SYSTEM_CFG_SIZE) "\0"          
  "f_dectconfig_addr=" MK_STR(IFX_CFG_FLASH_DECT_CFG_START_ADDR) "\0"    
  "f_dectconfig_size=" MK_STR(IFX_CFG_FLASH_DECT_CFG_SIZE) "\0"          
  "f_wlanconfig_addr= " MK_STR(IFX_CFG_FLASH_WLAN_CFG_START_ADDR) "\0"  
  "f_wlanconfig_size=" MK_STR(IFX_CFG_FLASH_WLAN_CFG_SIZE) "\0"  
  "f_ddrconfig_addr=" MK_STR(IFX_CFG_FLASH_DDR_CFG_START_ADDR) "\0"       
  "f_ddrconfig_size=" MK_STR(IFX_CFG_FLASH_DDR_CFG_SIZE) "\0"             
  "f_ddrconfig_end=" MK_STR(IFX_CFG_FLASH_DDR_CFG_END_ADDR) "\0"        
#ifdef CONFIG_OVERLAY
  "f_data_addr=" MK_STR(IFX_CFG_FLASH_DATA_IMAGE_START_ADDR) "\0"       
  "f_data_size=" MK_STR(IFX_CFG_FLASH_DATA_IMAGE_SIZE) "\0"   
  "f_data_end=" MK_STR(IFX_CFG_FLASH_DATA_IMAGE_END_ADDR) "\0"
#endif
#ifdef CONFIG_DRIVER_VBG400
  "wlanm=31M\0"
  "tftp_flash="CONFIG_TFTP_FLASH"\0"
  "tftp_nfs="CONFIG_TFTP_NFS"\0"
  "flash_nfs="CONFIG_FLASH_NFS"\0"
  "update_tftp_flash="CONFIG_UPDATE_TFTP_FLASH"\0"
  "upfate_tftp_nfs="CONFIG_UPDATE_TFTP_NFS"\0"
  "upfate_flash_flash="CONFIG_UPDATE_FLASH_FLASH"\0"
  "upfate_flash_nfs="CONFIG_UPDATE_FLASH_NFS"\0"
#endif
#endif
  ""
	
