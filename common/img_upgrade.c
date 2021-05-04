#include "common.h"
#include "command.h"
#include "cmd_upgrade.h"
#include "flash.h"

#ifdef CONFIG_CMD_UBI
#include <ubi_uboot.h>
#endif

/* SPI only boot without NAND support */
#if defined(CONFIG_LTQ_BOOT_FROM_SPI) && !defined(CONFIG_SPI_WITH_NAND)
#if defined(BUILD_FROM_IFX_UTILITIES)
#define u32 unsigned int
#endif

#include <spi_flash.h>
static struct spi_flash *flash_spi;
#ifndef CONFIG_ENV_SPI_BUS
# define CONFIG_ENV_SPI_BUS	0
#endif
#ifndef CONFIG_ENV_SPI_CS
# define CONFIG_ENV_SPI_CS		0
#endif
#ifndef CONFIG_ENV_SPI_MAX_HZ
# define CONFIG_ENV_SPI_MAX_HZ	1000000
#endif
#ifndef CONFIG_ENV_SPI_MODE
# define CONFIG_ENV_SPI_MODE	SPI_MODE_3
#endif

DECLARE_GLOBAL_DATA_PTR;
#endif

/* Upgrade using NAND APIs */
#if defined(CONFIG_LTQ_BOOT_FROM_NAND) || defined(CONFIG_SPI_WITH_NAND)
#define CONFIG_LTQ_BOOT_FROM_NAND_SPI
#if defined(BUILD_FROM_IFX_UTILITIES)
#define u16 unsigned short
#define u32 unsigned int
#define phys_addr_t unsigned long
#include <stdint.h>
#endif
#include <nand.h>
static struct mtd_info mtd_data[1];
#endif

#if defined(BUILD_FROM_IFX_UTILITIES)
#include "crc32.h"
#define getenv(x)					get_env(x)
#define simple_strtoul(a,b,c)				strtoul(a,b,c)
#define setenv(x,y)					set_env(x,y)
#define uchar						unsigned char
#define ulong						unsigned long
#define uint32_t					unsigned int
#define uint8_t						unsigned char
#endif

#include "image.h"

#ifdef DEBUG_UPGRADE_MECHANISM
#	ifdef BUILD_FROM_IFX_UTILITIES
#		define upgrade_debug_printf		printf
#	else
#		define upgrade_debug_printf		debug
#	endif
#else
#	ifdef BUILD_FROM_IFX_UTILITIES
#		define upgrade_debug_printf(...)
#	else
#		define upgrade_debug_printf(...)
#	endif
#endif

#ifdef CONFIG_CMD_UBI
extern int ubi_remove_vol(char *volume);
extern int ubi_create_vol(char *volume, int64_t size, int dynamic);
#endif

//#if !defined(BUILD_FROM_IFX_UTILITIES)
//extern int do_reset (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]);
//#endif

static int rootfs_programming=0;

int program_img(ulong srcAddr,int srcLen,ulong destAddr)
{
	upgrade_debug_printf("program_img : the srcAddr is 0x%08lx, length is %d while destAddr is 0x%08lx\n",srcAddr,srcLen,destAddr);
#if (!defined(CONFIG_LTQ_BOOT_FROM_NAND) && (defined(CONFIG_LTQ_BOOT_FROM_NOR) || defined(BUILD_FROM_IFX_UTILITIES)))
	flash_sect_protect(0,destAddr,destAddr + srcLen-1);
	upgrade_debug_printf("Erase Flash from 0x%08lx to 0x%08lx\n", destAddr, destAddr + srcLen-1);
	if(flash_sect_erase(destAddr,destAddr + srcLen-1)) {
		return 1;
	}

	//puts ("Writing to Flash... ");
#if !defined(BUILD_FROM_IFX_UTILITIES)
	if(flash_write((char *)srcAddr,destAddr,srcLen)) {
#else
	if(flash_write(srcAddr,destAddr,srcLen)) {
#endif
		return 1;
	}
	//printf("flash writing finished!\n");
	upgrade_debug_printf("Image at 0x%08lx with size %d is programmed at 0x%08lx successfully\n",srcAddr,srcLen,destAddr);
	//printf ("Saving Environment ...\n");
	flash_sect_protect(1,destAddr,destAddr + srcLen-1);
#elif defined(CONFIG_LTQ_BOOT_FROM_SPI) && !defined(CONFIG_SPI_WITH_NAND)
	//puts ("Writing to Serial Flash... ");
	flash_spi = spi_flash_probe(CONFIG_ENV_SPI_BUS, CONFIG_ENV_SPI_CS,
			CONFIG_ENV_SPI_MAX_HZ, CONFIG_ENV_SPI_MODE);
	if (!flash_spi){
		  printf("probe fails!\n");
		  return 1;
	}
	spi_flash_write(flash_spi, destAddr, srcLen, (uchar *)srcAddr);
	/*
	if(eeprom_write (NULL, destAddr, (uchar *)srcAddr, srcLen)) {
		puts ("Serial flash write failed !!");
		return (1);
	}
	*/
	//puts ("done\n");
#elif defined(CONFIG_SPI_WITH_NAND) || defined(CONFIG_LTQ_BOOT_FROM_NAND)
 #if !defined(BUILD_FROM_IFX_UTILITIES)
  if(rootfs_programming)
  {
	int ret;
	int flags = 0;
	ulong rootfs_size;
	u64 srcLen64=(u64)srcLen;
	nand_erase_options_t opts;
	char *size = NULL;
	size_t actual = 0;

	size = (char *)getenv("f_rootfs_size");
	if (size)
		rootfs_size = simple_strtoul(size, NULL, 16);
	else
		rootfs_size = 0;

	memset(&opts, 0, sizeof(opts));
	opts.offset = destAddr;
	opts.length = rootfs_size;
	opts.jffs2  = 1;
	opts.quiet  = 0;
	printf("erasing 0x%08x size 0x%08x\n", (u32) destAddr, srcLen);
	ret = nand_erase_opts(&mtd_data[0], &opts);
	 printf("erase %s\n", ret ? "ERROR" : "OK");

	    printf("writing to 0x%08x size 0x%08x\n", (u32) destAddr, srcLen);
	    ret = nand_write_skip_bad(&mtd_data[0], destAddr, (size_t *) &srcLen64,
							  &actual, srcLen64, (u_char *)srcAddr, flags);
	    printf(" write 0x%08x bytes: %s\n", srcLen, ret ? "ERROR" : "OK");

	   rootfs_programming = 0;
   }else{
     u64 srcLen64=(u64)srcLen;
     nand_write_partial(&mtd_data[0], destAddr, &srcLen64, (u_char*)srcAddr);
   }
 #else
   nand_flash_write(srcAddr, destAddr, srcLen);
   puts ("NAND write done\n");
 #endif

#endif
	return 0;
}

int FindPartBoundary(ulong img_addr,ulong *curpart_begin,ulong *nextpart_begin)
{
	char strPartName[16];
	char *tmp_string = NULL;
	ulong part_begin_addr[MAX_PARTITION];
	int nPartNo,i;

	tmp_string = (char *)getenv("total_part");
	if (tmp_string) {
		nPartNo = simple_strtoul(tmp_string, NULL, 10);
	} else {
		printf("%d: env variable total_part not found\n", __LINE__);
		return 1;
	}
	if(nPartNo <= 0 || nPartNo >= MAX_PARTITION){
		printf("Total no. of current partitions [%d] is out of limit (0,%d)\n", nPartNo, MAX_PARTITION);
		return 1;
	}

	for(i = 0; i < nPartNo; i++){
		memset(strPartName,0x00,sizeof(strPartName));
		snprintf(strPartName, sizeof(strPartName) / sizeof(char),
				"part%d_begin", i);
		tmp_string = (char *)getenv(strPartName);
		if (tmp_string) {
			part_begin_addr[i] = simple_strtoul(tmp_string, NULL, 16);
		} else {
			printf("%d: env variable %s not found\n", __LINE__, strPartName);
			return 1;
		}
	}

	tmp_string = (char *)getenv("flash_end");
	if (tmp_string) {
		part_begin_addr[i] = simple_strtoul(tmp_string, NULL, 16) + 1;
	} else {
		printf("%d: env variable flash_end not found\n", __LINE__);
		return 1;
	}

	for(i = 0; i < nPartNo; i++){
		if(img_addr >= part_begin_addr[i] && img_addr < part_begin_addr[i+1]){
			*curpart_begin = part_begin_addr[i];
			*nextpart_begin = part_begin_addr[i+1];
			return 0;
		}
	}

	printf("The begining of the image to be programmed [0x%08lx] is not within current patition boundary\n",img_addr);
	return 1;
}

int FindNPImgLoc(ulong img_addr,ulong *nextStartAddr,ulong *preEndAddr)
{
	ulong Img_startAddr[MAX_DATABLOCK];
	ulong Img_size[MAX_DATABLOCK];
	ulong nDBNo;
	char strDBName[MAX_DATABLOCK][32];
	char strTemp[32];
	char *strT;
	char *tmp_string;
	ulong curpart_begin,nextpart_begin;
	int i;

	tmp_string = (char *)getenv("total_db");
	if (tmp_string) {
		nDBNo = simple_strtoul(tmp_string, NULL, 10);
	} else {
		printf("%d: env variable total_db not found\n", __LINE__);
		return 1;
	}

	if(nDBNo <= 0 || nDBNo >= MAX_DATABLOCK){
		printf("Total no. of current data blocks [%ld] is out of limit (0,%d)\n", nDBNo, MAX_PARTITION);
		return 1;
	}

	if(FindPartBoundary(img_addr,&curpart_begin,&nextpart_begin))
		return 1;

	upgrade_debug_printf("For the image address 0x%08lx, partition boundary is found as [0x%08lx,0x%08lx]\n",img_addr,curpart_begin,nextpart_begin);
	*nextStartAddr = nextpart_begin;
	*preEndAddr = curpart_begin;

	for(i = 0; i < nDBNo; i++){
		memset(strDBName[i],0x00,sizeof(strDBName[i]));
		memset(strTemp,0x00,sizeof(strTemp));
		snprintf(strTemp, sizeof(strTemp) / sizeof(char),
				"data_block%d", i);
		tmp_string = (char *)getenv(strTemp);
		if (tmp_string && strlen(tmp_string) < 32) {
			strncpy(strDBName[i], tmp_string, 32);
		} else {
			printf("%d: error processing env. variable %s\n", __LINE__, strTemp);
			return 1;
		}

		if (strcmp(strDBName[i],"") == 0) {
			printf("Variable %s is not set\n",strTemp);
			return 1;
		}
	}

	for(i = 0; i < nDBNo; i++){
		memset(strTemp,0x00,sizeof(strTemp));
		strT = NULL;
		snprintf(strTemp, 25, "f_%s_addr", strDBName[i]);
		strT = (char *)getenv(strTemp);
		if(strT == NULL){
			printf("Variable %s is not set\n",strTemp);
			return 1;
		}
		Img_startAddr[i] = simple_strtoul((char *)strT,NULL,16);

		memset(strTemp,0x00,sizeof(strTemp));
		strT = NULL;
		snprintf(strTemp, 25, "f_%s_size", strDBName[i]);
		strT = (char *)getenv(strTemp);
		if(strT == NULL){
			printf("Variable %s is not set\n",strTemp);
			return 1;
		}
		Img_size[i] = simple_strtoul((char *)strT,NULL,16);
	}

	for(i = 0; i < nDBNo; i++){
		if(Img_startAddr[i] > img_addr && Img_startAddr[i] < *nextStartAddr)
			*nextStartAddr = Img_startAddr[i];
		if(Img_startAddr[i] + Img_size[i] < img_addr && Img_startAddr[i] + Img_size[i] > *preEndAddr)
			*preEndAddr = Img_startAddr[i] + Img_size[i];
	}
	//printf("For img_addr 0x%08lx, nextStartAddr 0x%08lx and preEndAddr 0x%08lx\n",img_addr,*nextStartAddr,*preEndAddr);
	return 0;
}

#ifdef CONFIG_CMD_UBI
int upgrade_img(ulong srcAddr, int64_t srcLen, char *imgName, enum ExpandDir dir, int bSaveEnv)
{
#if !defined(BUILD_FROM_IFX_UTILITIES)
	char strimg_vol[32],strimg_vol_id[32];
	char *tmp_string;
	u32  destAddr=0;
#else
	FILE *fp;
	char strimg_dataout[100];
#endif
	int ret = 0;
	image_header_t *pimg_header = NULL;

#if !defined(BUILD_FROM_IFX_UTILITIES)
	memset(strimg_vol,0x00,sizeof(strimg_vol));
	memset(strimg_vol_id,0x00,sizeof(strimg_vol_id));
	snprintf(strimg_vol, sizeof(strimg_vol) / sizeof(char),
			"%s_vol", imgName);
	tmp_string = getenv(strimg_vol);
	if (tmp_string) {
		snprintf(strimg_vol_id, sizeof(strimg_vol_id) / sizeof(char),
				"%s_id", tmp_string);
	} else {
		printf("%d: Error processing env. variable %s\n", __LINE__, strimg_vol);
		return 1;
	}
#endif

	pimg_header = (image_header_t *)srcAddr;

	if (ntohl(pimg_header->ih_magic) == IH_MAGIC) {
		printf("Image contains header with name [%s]\n",pimg_header->ih_name);
		if(pimg_header->ih_type != IH_TYPE_KERNEL) {
			upgrade_debug_printf("This is not kernel image and so removing header\n");
			srcAddr += sizeof(*pimg_header);
			srcLen -= sizeof(*pimg_header);
		}
	}
#if !defined(BUILD_FROM_IFX_UTILITIES)
	if (pimg_header->ih_type==IH_TYPE_UBOOT) {
		tmp_string = (char *)getenv("f_uboot_addr");
		if (tmp_string) {
			destAddr = simple_strtoul(tmp_string, NULL, 16);
		} else {
			printf("%d: env. variable f_uboot_addr not found\n", __LINE__);
			return 1;
		}
		program_img(srcAddr,srcLen,destAddr);
	} else if (!strcmp((char *)pimg_header->ih_name,"gphyfw")) {
		tmp_string = (char *)getenv("gphy_fw_addr");
		if (tmp_string) {
			destAddr = simple_strtoul(tmp_string, NULL, 16);
		} else {
			printf("%d: env. variable gphy_fw_addr not found\n", __LINE__);
			return 1;
		}
		program_img(srcAddr,srcLen,destAddr);
	} else {
		ubi_remove_vol(getenv(strimg_vol));
		ret = ubi_create_vol(getenv(strimg_vol), srcLen, 1);
		if (ret)
			printf("Error %d creating volume\n", ret);
		ret = ubi_volume_write(getenv(strimg_vol), (void *)srcAddr, (size_t)srcLen);
		if (ret)
			printf("Error %d writing to volume\n", ret);
	}
#else
  #if defined(CONFIG_UBOOT_CONFIG_DUAL_IMAGE)
	snprintf(strimg_dataout, sizeof(strimg_dataout) / sizeof(char),
			"/usr/sbin/vol_mgmt upgrade_dualvol_stdin %s %u %s",
			imgName, (size_t)srcLen, pimg_header->ih_name);
  #else
	snprintf(strimg_dataout, sizeof(strimg_dataout) / sizeof(char),
			"/usr/sbin/vol_mgmt upgrade_vol_stdin %s %u %s",
			imgName, (size_t)srcLen, pimg_header->ih_name);
  #endif
	fp = popen (strimg_dataout, "w");
	if (fp == NULL) {
		fprintf(stderr, "upgrade %s: unable to open file for writing\n", imgName);
		return (0);
	} else {
		if(fwrite((void *)srcAddr, sizeof(char), (size_t)srcLen, fp) != srcLen)
			fprintf(stderr, "upgrade %s: unable to complete writing\n", imgName);
		pclose(fp);
	}
#endif
   return 0;
}

#else
int upgrade_img(ulong srcAddr, int64_t srcLen, char *imgName, enum ExpandDir dir, int bSaveEnv)
{
	ulong img_addr,img_size,img_endaddr;
	char newimg_para[32];
	char strimg_addr[32],strimg_size[32];
	ulong nextStartAddr,preEndAddr;
	image_header_t *pimg_header = NULL;
	char *srcData_Copy=NULL;

	memset(strimg_addr,0x00,sizeof(strimg_addr));
	snprintf(strimg_addr, sizeof(strimg_addr) / sizeof(char),
				"f_%s_addr", imgName);
	snprintf(strimg_size, sizeof(strimg_size) / sizeof(char),
				"f_%s_size", imgName);
	img_addr = simple_strtoul((char *)getenv(strimg_addr),NULL,16);
	/*
	if (img_addr == 0) {
		printf("The environment variable %s not found\n",strimg_addr);
		return 1;
	}
    */
	if (FindNPImgLoc(img_addr,&nextStartAddr,&preEndAddr))
		return 1;
	pimg_header = (image_header_t *)srcAddr;
	if (ntohl(pimg_header->ih_magic) == IH_MAGIC) {
		printf("Image contains header with name [%s]\n",pimg_header->ih_name);
		if(pimg_header->ih_type != IH_TYPE_KERNEL) {
			upgrade_debug_printf("This is not kernel image and so removing header\n");
			srcAddr += sizeof(*pimg_header);
			srcLen -= sizeof(*pimg_header);
		}
		img_size = simple_strtoul((char *)getenv(strimg_size),NULL,16); //509061:tc.chen
	} else if (!strcmp(imgName,"uboot")) {
		img_size = simple_strtoul((char *)getenv(strimg_size),NULL,16); //509061:tc.chen
	}
	 else {
		struct conf_header *header;
#if !defined(BUILD_FROM_IFX_UTILITIES)
		srcData_Copy = (char *)srcAddr;
		memmove(srcData_Copy + sizeof(struct conf_header) ,(void *)srcAddr,srcLen);
#else
		srcData_Copy = malloc(srcLen + sizeof(struct conf_header));
		memcpy(srcData_Copy+sizeof(struct conf_header),(char *)srcAddr,srcLen);
#endif
		header = (struct conf_header *)srcData_Copy;
		header->size = srcLen;
#if defined(BUILD_FROM_IFX_UTILITIES)
		header->crc = 0 ^ 0xffffffffL;
#else
		header->crc = 0;
#endif
		header->crc = crc32(header->crc,
						(const unsigned char *) srcData_Copy + sizeof(struct conf_header),
						srcLen);
#if defined(BUILD_FROM_IFX_UTILITIES)
		header->crc ^= 0xffffffffL;
#endif
	}
    if (!strcmp(imgName,"rootfs")) rootfs_programming=1;
	if (dir == FORWARD) {
		if (img_addr + srcLen > nextStartAddr) {
			printf("Cannot upgrade image %s.\n Error "
				": From start address 0x%08lx, the new size %lld is bigger"
				"than begining of next image/end of the partition 0x%08lx\n",
				strimg_addr, img_addr, srcLen, nextStartAddr);
			return 1;
		}
		upgrade_debug_printf("Programming for FORWARD direction\n");
	} else if (dir == BACKWARD) {
		img_endaddr = nextStartAddr - 1;
		if(img_endaddr - srcLen < preEndAddr) {
			printf("Cannot upgrade image %s.\n"
					"Error : From end address 0x%08lx, the new size %lld "
					"is bigger than end of previous image/begining of the partition 0x%08lx\n",
					strimg_addr, img_endaddr, srcLen, preEndAddr);
			return 1;
		}

		img_addr = img_endaddr - srcLen + 1;
		img_addr = (img_addr/16)*16;

		upgrade_debug_printf("Programming for BACKWARD direction\n");
	} else {
		printf("The expansion direction [%d] is invalid\n",dir);
		return 1;
	}
	if (srcData_Copy) {
		if (program_img((ulong)srcData_Copy,srcLen+sizeof(struct conf_header),img_addr)) {
#if defined(BUILD_FROM_IFX_UTILITIES)
			free(srcData_Copy);
#endif
			return 1;
		}
	} else {
		if (program_img(srcAddr,srcLen,img_addr)) {
			return 1;
		}
	}

	memset(newimg_para,0x00,sizeof(newimg_para));
	snprintf(newimg_para, sizeof(newimg_para) / sizeof(char),
				"0x%08llx",srcLen);
	setenv(strimg_size,newimg_para);
	upgrade_debug_printf("New variables %s = %s set\n",strimg_size,newimg_para);

	memset(newimg_para,0x00,sizeof(newimg_para));
	snprintf(newimg_para, sizeof(newimg_para) / sizeof(char),
				"0x%08lx", img_addr);
	setenv(strimg_addr,newimg_para);
	upgrade_debug_printf("New variables %s = %s set\n",strimg_addr,newimg_para);

	if (strcmp(strimg_addr,"f_kernel_addr") == 0) {
		setenv("kernel_addr",newimg_para);
		upgrade_debug_printf("New variables kernel_addr = %s set\n",newimg_para);
	}

	if (strcmp(strimg_addr,"f_rootfs_addr") == 0) {
		memset(newimg_para,0x00,sizeof(newimg_para));
		snprintf(newimg_para, sizeof(newimg_para) / sizeof(char),
				"0x%08llx", img_addr + srcLen);
		setenv("f_rootfs_end",newimg_para);
		upgrade_debug_printf("New variables kernel_addr = %s set\n",newimg_para);
	}

	if (bSaveEnv) {
		saveenv();
#ifdef UBOOT_ENV_COPY
		saveenv_copy();
#endif //UBOOT_ENV_COPY
	}
#if defined(BUILD_FROM_IFX_UTILITIES)
	if (srcData_Copy)
		free(srcData_Copy);
#endif

	debug("img_size: %lx\n", img_size);
	return 0;
}

#endif //CONFIG_CMD_UBI
