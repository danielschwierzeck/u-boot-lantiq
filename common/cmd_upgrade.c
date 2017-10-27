/*
 * (C) Copyright 2000
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Cache support: switch on or off, get status
 */
#include <common.h>
#include <command.h>
#include <cmd_upgrade.h>

#if defined(BUILD_FROM_IFX_UTILITIES)
#include "crc32.h"
#include <syslog.h>
#define getenv(x)		get_env(x)
#define simple_strtoul(a,b,c)	strtoul(a,b,c)
#define setenv(x,y)		set_env(x,y)
#define uchar			unsigned char
#define ulong			unsigned long
#define uint32_t		unsigned int
#define uint8_t			unsigned char
//#define printf(format, args...)	syslog(LOG_INFO, format, ##args)
#endif //BUILD_FROM_IFX_UTILITIES


#include "image.h"

#ifdef CONFIG_LTQ_IMAGE_EXTRA_CHECKS
char* get_string_value(char* str, char* delim, int n)
{
   int i;
   char* ptr=NULL;
   ptr = strtok(str, delim);
   if(n==0) return ptr;
   for(i=0;i<n;i++){
     ptr = strtok(NULL, delim);
   }
   return ptr;
}




/* compare the version with the built-in-version,
   return 1 if v_new is equal to or bigger than v_old
   return 0 otherwise 
*/
int compare_version(char *v_old, char *v_new)
{
	
	 int res=0;
   int i=0;
   char* p=NULL;
   char tmp_str[32];
   int old_v_num=0;
   int new_v_num=0;
   for(i=0;i<32;i++){
     strcpy(tmp_str, v_old);
     p = get_string_value(tmp_str,".",i);
     if(!p) break;
     old_v_num=simple_strtoul(p,NULL,0);
     //printf("old_v_num=%d\n",old_v_num);
     strcpy(tmp_str, v_new);
     p = get_string_value(tmp_str,".",i);
     if(!p) { break;}
     new_v_num=simple_strtoul(p,NULL,0);
     //printf("new_v_num=%d\n",new_v_num);
     if(new_v_num>=old_v_num) res=1;
     else res=0;
   }
   return res;
}
#endif

#if !defined(BUILD_FROM_IFX_UTILITIES)
int do_upgrade( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]) {
	ulong srcAddr=0;
	int srcLen;
	ulong srcHeader=0;
	int curParSize=0, dir, pad;
	image_header_t *pimg_header = NULL;
	char name[16], strimg_crc[32], buf[32];
#ifdef CONFIG_CMD_UBI
    int ubi = 0;
#endif
	if(argc != 3) {
		printf("Usage :\n%s\n",cmdtp->usage);
		return 1;
	}

	srcAddr = simple_strtoul(argv[1], NULL, 16);
	srcLen = simple_strtoul(argv[2], NULL, 16);

	do {
		srcHeader = (!srcHeader ? srcAddr : srcHeader + curParSize);
		pimg_header = (image_header_t *)srcHeader;		
		curParSize = sizeof(image_header_t) + ntohl(pimg_header->ih_size);
		pad = (16 - (curParSize % 16)) % 16;

        if (!image_check_hcrc (pimg_header) || !image_check_dcrc (pimg_header)) {
		     printf ("Bad Header Checksum\n");
			 return 1;
		    }

		switch(pimg_header->ih_type) {
			case IH_TYPE_MULTI:
#ifdef CONFIG_LTQ_IMAGE_EXTRA_CHECKS
        if(strncmp(pimg_header->ih_vendor, CONFIG_VENDOR_NAME, sizeof(pimg_header->ih_vendor)) || \
		   strncmp(pimg_header->ih_board, CONFIG_BOARD_NAME, sizeof(pimg_header->ih_board))    || \
		   !compare_version(CONFIG_BOARD_VERSION, pimg_header->ih_boardVer)                    || \
		   strncmp(pimg_header->ih_chip, CONFIG_CHIP_NAME, sizeof(pimg_header->ih_chip))       || \
		   !compare_version(CONFIG_CHIP_VERSION, pimg_header->ih_chipVer)                      || \
           !compare_version(CONFIG_SW_VERSION, pimg_header->ih_swVer))
       	{
        		printf("wrong image, update failed!\n");
        		return 0;
       	}
#endif				
				curParSize = sizeof(image_header_t) + 8;
				continue;
			case IH_TYPE_FILESYSTEM:
            #ifdef CONFIG_CMD_UBI
                if(strncmp(pimg_header->ih_name, "LTQCPE UBI_RootFS", sizeof(pimg_header->ih_name)) == 0) ubi=1;
		    #endif
				sprintf(name, "rootfs");
				dir = 0;
				break;
			case IH_TYPE_KERNEL:
			#ifdef CONFIG_CMD_UBI
			    if(strncmp(pimg_header->ih_name, "LTQCPE UBI_Kernel", sizeof(pimg_header->ih_name)) == 0) ubi=1;
			#endif	
				if (strncmp(pimg_header->ih_name, "MIPS 4Kec Bootcore", sizeof(pimg_header->ih_name)) == 0)
					sprintf(name, "bootcore");
				else
					sprintf(name, "kernel");
				dir = 1;
				break;
			case IH_TYPE_FIRMWARE:
			#ifdef CONFIG_CMD_UBI    
				if(strncmp(pimg_header->ih_name, "LTQCPE UBI_Firmware", sizeof(pimg_header->ih_name)) == 0) ubi=1;
			#endif	
				sprintf(name, "firmware");
				dir = 0;
				break;
			case IH_TYPE_UBOOT:
				sprintf(name, "uboot");
				dir = 0;
				break;	
			default:
				printf("Unknown image type!!\n");
				curParSize = curParSize + pad + 8;
				continue;
		}
        if(upgrade_img(srcHeader, curParSize, name, dir, 0)) {
            printf("Can not upgrade the image %s\n", name);
		} else {
			sprintf(strimg_crc, "f_%s_crc", name);
			sprintf(buf, "%lX", ntohl(pimg_header->ih_dcrc));
			setenv(strimg_crc, buf);
			saveenv();
#ifdef UBOOT_ENV_COPY
			saveenv_copy();
#endif
		}
		curParSize = curParSize + pad;
#ifdef CONFIG_CMD_UBI		
		ubi=0;
#endif		
	} while(srcLen > (srcHeader - srcAddr) + curParSize);

	return 0;
}


int http_upgrade(ulong srcAddr, int srcLen) {
	ulong srcHeader=0;
	int curParSize=0, dir, pad;
	image_header_t *pimg_header = NULL;
	char name[16], strimg_crc[32], buf[32];;
	
	printf("srcAddr=%08x\n",srcAddr);
	printf("srcLen=%d\n",srcLen);
	do {
		srcHeader = (!srcHeader ? srcAddr : srcHeader + curParSize);
		printf("srcHeader=0x%08x\n",srcHeader);
		pimg_header = (image_header_t *)srcHeader;		
		curParSize = sizeof(image_header_t) + ntohl(pimg_header->ih_size);
		printf("curParSize=0x%x\n",curParSize);
		
		pad = (16 - (curParSize % 16)) % 16;
        printf("pad=0x%x\n",pad);
		switch(pimg_header->ih_type) {
			case IH_TYPE_MULTI:
				curParSize = sizeof(image_header_t) + 8;
				continue;
			case IH_TYPE_FILESYSTEM:
				sprintf(name, "rootfs");
				dir = 0;
				break;
			case IH_TYPE_KERNEL:
				sprintf(name, "kernel");
				dir = 1;
				break;
			case IH_TYPE_FIRMWARE:
				sprintf(name, "firmware");
				dir = 0;
				break;
			default:
				printf("Unknown image type!!\n");
				continue;
		}
        printf("upgrade now!\n");
		if(upgrade_img(srcHeader, curParSize, name, dir, 0)) {
			printf("Can not upgrade the image %s\n", name);
		} else {
			sprintf(strimg_crc, "f_%s_crc", name);
			sprintf(buf, "%lX", ntohl(pimg_header->ih_dcrc));
			setenv(strimg_crc, buf);
			saveenv();
		}
		printf("upgrade_img done!!\n");
		curParSize = curParSize + pad;
	} while(srcLen > (srcHeader - srcAddr) + curParSize);
	printf("http_upgrade done!\n");
	return 0;
}


#else

#ifdef CONFIG_FEATURE_LQ_NEW_UPGRADE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int image_check_hcrc (const image_header_t *hdr)
{
	ulong hcrc = 0;
	ulong len = image_get_header_size ();
	image_header_t header;

	/* Copy header so we can blank CRC field for re-calculation */
	memmove (&header, (char *)hdr, image_get_header_size ());
	image_set_hcrc (&header, 0);

	hcrc ^= 0xffffffffL;
	hcrc = crc32 (hcrc, (unsigned char *)&header, len);
	hcrc ^= 0xffffffffL;

	return (hcrc == image_get_hcrc (hdr));
}

int image_check_dcrc (const image_header_t *hdr)
{
	ulong data = image_get_data (hdr);
	ulong len = image_get_data_size (hdr);
	ulong dcrc = 0;

	dcrc ^= 0xffffffffL;
	dcrc = crc32 (dcrc, (unsigned char *)data, len);
	dcrc ^= 0xffffffffL;

	return (dcrc == image_get_dcrc (hdr));
}
#endif

int do_upgrade( int file_fd , int srcLen) {
	uint32_t curParSize=0, dir, pad;
	char name[16], strimg_crc[32], buf[32];;
	image_header_t xImgHeader;
#ifdef CONFIG_FEATURE_LQ_NEW_UPGRADE
	ulong srcHeader=0;
	image_header_t *pimg_header = NULL;
#endif
	char *xHeader = NULL;
	uint32_t iFileReadSize =0, iTotalFileReadSize = 0;
	int iRet = 0;

#ifdef CONFIG_FEATURE_LQ_NEW_UPGRADE
	char *p;
	p = mmap(0, srcLen, PROT_READ, MAP_SHARED, file_fd, 0);
	if (p == MAP_FAILED) {
		fprintf(stderr, "mmap failed\n");
	}
	xHeader = p;
#endif
	do {

#ifndef CONFIG_FEATURE_LQ_NEW_UPGRADE
		//first read only the header to figure our the image total size
		iRet = read(file_fd, (void *)&xImgHeader , (size_t)sizeof(image_header_t)); 
		if(iRet < sizeof(image_header_t)){
			printf("Failure : could read %d out of %d bytes from image\n", iRet, sizeof(image_header_t));
			return 1; //failure
		}
#else
		xImgHeader = *((image_header_t *)xHeader);
#endif

		printf("\nImage Header --> Data Size = %d\n Image Name = %s\n",xImgHeader.ih_size , xImgHeader.ih_name);

#ifdef CONFIG_FEATURE_LQ_NEW_UPGRADE
		srcHeader = (!srcHeader ? xHeader : srcHeader + curParSize);
		pimg_header = (image_header_t *)srcHeader;
		if (!image_check_hcrc (pimg_header) || !image_check_dcrc (pimg_header)) {
			printf ("Bad Header or Data Checksum\n");
			return 1;
		}
#endif

                if(xImgHeader.ih_type == IH_TYPE_MULTI){
                        curParSize = sizeof(image_header_t) + 8;
                        iTotalFileReadSize += curParSize;
#ifndef CONFIG_FEATURE_LQ_NEW_UPGRADE
                        if( lseek(file_fd, iTotalFileReadSize, SEEK_SET) == -1){
                                printf("Can not move the offset for image to upgrade\n");
                                return 1;  //failure
                        }
#else
			xHeader = p + iTotalFileReadSize;
#endif
                        continue;
                }


		curParSize = sizeof(image_header_t) + xImgHeader.ih_size;
		pad = (16 - (curParSize % 16)) % 16;

#ifndef CONFIG_FEATURE_LQ_NEW_UPGRADE
		// reposition the file read offset to the start of image
		if( lseek(file_fd, iTotalFileReadSize, SEEK_SET) == -1){
			printf("Can not move the offset for image to upgrade\n");
		        return 1;  //failure	
		}
#else
		xHeader = p + iTotalFileReadSize;

#endif

		// then read the total size into a buffer to be passed to upgrade_img
		iFileReadSize = curParSize + pad;
#ifndef CONFIG_FEATURE_LQ_NEW_UPGRADE
	        xHeader = (char *)malloc(iFileReadSize);			

		iRet = read(file_fd, xHeader , (size_t)iFileReadSize);
       		if(iRet < iFileReadSize){
			printf("Failure : could read %d out of %d bytes from image\n", iRet, iFileReadSize);
			return 1; //failure
		}
#endif        

		switch(xImgHeader.ih_type) {
			case IH_TYPE_MULTI:
				curParSize = sizeof(image_header_t) + 8;
				continue;
			case IH_TYPE_FILESYSTEM:
				sprintf(name, "rootfs");
				dir = 0;
				break;
			case IH_TYPE_KERNEL:
				if (strncmp(xImgHeader.ih_name, "MIPS 4Kec Bootcore", sizeof(xImgHeader.ih_name)) == 0)
          sprintf(name, "bootcore");
				else
					sprintf(name, "kernel");
				dir = 1;
				break;
			case IH_TYPE_FIRMWARE:
				sprintf(name, "firmware");
				dir = 0;
				break;
			case IH_TYPE_UBOOT:
			    sprintf(name, "uboot");
			    dir = 0;
			    break; 
			default:
				curParSize = curParSize + pad + 8;
				iTotalFileReadSize = (iTotalFileReadSize + iFileReadSize + 8);
				printf("Unknown image type!!\n");
				continue;
		}

		if(upgrade_img(xHeader, curParSize, name, dir, 0)) {
			printf("Can not upgrade the image %s\n", name);
		} else {
#if !defined (CONFIG_TARGET_UBI_MTD_SUPPORT)
			sprintf(strimg_crc, "f_%s_crc", name);
			sprintf(buf, "%lX", ntohl(xImgHeader.ih_dcrc));
			setenv(strimg_crc, buf);
			saveenv();
#ifdef UBOOT_ENV_COPY
			saveenv_copy();
#endif
#endif
		}
		iTotalFileReadSize += iFileReadSize;

#ifndef CONFIG_FEATURE_LQ_NEW_UPGRADE
		if(xHeader != NULL){
			free(xHeader);
			xHeader = NULL;
		}
#else
		xHeader += iFileReadSize; 
#endif

	} while(srcLen > iTotalFileReadSize );

#ifdef CONFIG_FEATURE_LQ_NEW_UPGRADE
	munmap(p, srcLen);
#endif

	return 0;
}
#endif


#if !defined(BUILD_FROM_IFX_UTILITIES)
U_BOOT_CMD(                                       
	upgrade,	3,	1,	do_upgrade,
	"upgrade - forward/backward copy memory to pre-defined flash location\n",
	"upgrade <source addr> <size> \n	- upgrade image to pre-define partition.\n"
);
#endif




