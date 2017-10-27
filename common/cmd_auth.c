/*Copyright, Lantiq Asia Pacific,Ltd         */
/*Revision history:                          */
/*1 March, 2013 Wu Qi Ming Initial version   */
/*********************************************/

/*
 * watch dog timer support
 */
#include <common.h>
#include <command.h>


#define EVA_ADDR
#ifdef EVA_ADDR
#define KADDR(x) (((unsigned long)x &0x1FFFFFFF) | 0x60000000)
#else /* EVA_ADDR */
/* havent test this , i assume in non eva it is in KSEG0 cachec ? */
#define KADDR(x) (((unsigned long)x &0x1FFFFFFF) | KSEG0)
#endif /* EVA_ADDR */

/* Allow ports to override the default behavior */
__attribute__((weak))

int do_auth (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
        ulong *img_p=NULL;
        int image_len, certnum;
        ulong   src_addr, dst_addr;
        int     rcode = 0;
        u8      auth_res = 0;

	if (argc < 2) {
		cmd_usage(cmdtp);
		return 1;
	}

	src_addr=simple_strtoul(argv[1], NULL, 16);
        dst_addr=simple_strtoul(argv[2], NULL, 16);
        
        img_p=(ulong*)src_addr;
        certnum=(int)(*(img_p+65));
        image_len=66*4+128*certnum+(int)(*(img_p+48));

        REG32(0xBF201010)=0x000001EC;
        REG32(0xBF201014)=0x000001EC;
        REG32(0xBF201018)=0x000001E8;
        REG32(0xBF20101C)=0x000001E8;

        /*clear the status*/
          REG32(0xbf2013f8)=0x0;
          asm("sync");


          /*send mailbox message*/
          REG32(0xBF20120C)=0x01010001;
          REG32(0xBF201208)=(src_addr & 0x0fffffff);
          REG32(0xBF201204)=image_len;
          REG32(0xBF201200)=0x00000000;
          REG32(0xBF2011FC)=0x00000000;
          asm("sync");
          /*kick start the interrupt*/
          REG32(0xBF201014)=0x000001D8;
          REG32(0xBF107448)=0x00000001;

          while((REG32(0xbf2013f8) & 0xFFFF0000) !=0x01010000);

          auth_res = (REG32(0xbf2013f8) >> 8) & 0xFF;

          if ( auth_res != 1 )
              return 1; // fail

          img_p+=66+(128/4)*certnum;
          image_len-=66*4+128*certnum;

          memcpy(dst_addr,img_p,image_len);


          return rcode;
}

__attribute__((weak))

int do_auth_img (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
    ulong   *img_p=NULL;
    int     image_len, certnum;
    ulong   src_addr, dst_addr, src_size;
    int     rcode = 1;
    u8      auth_res = 0;
    ulong   srcHeader=0;
    int     curParSize=0, auth=0, pad;
    image_header_t *pimg_header = NULL;
#ifdef CONFIG_CMD_UBI
    int ubi = 0;
#endif

    if (argc < 3) {
        cmd_usage(cmdtp);
        return 1;
    }

    src_addr = simple_strtoul(argv[1], NULL, 16);
    dst_addr = simple_strtoul(argv[2], NULL, 16);
    src_size = simple_strtoul(argv[3], NULL, 16);

    do {
        srcHeader   = (!srcHeader ? src_addr : srcHeader + curParSize);
        pimg_header = (image_header_t *)srcHeader;
        curParSize  = sizeof(image_header_t) + ntohl(pimg_header->ih_size);
        pad         = (4 - (curParSize % 4)) % 4;

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
                    printf("wrong image, auth_img failed!\n");
                    return 0;
                }
                #endif
                curParSize = sizeof(image_header_t) + 8;
                continue;
            case IH_TYPE_KERNEL:
            #ifdef CONFIG_CMD_UBI
                if(strncmp(pimg_header->ih_name, "LTQCPE UBI_Kernel", sizeof(pimg_header->ih_name)) == 0) ubi=1;
            #endif
                auth = 1;
                break;
            case IH_TYPE_FILESYSTEM:
            case IH_TYPE_FIRMWARE:
            case IH_TYPE_UBOOT:
                auth = 0;
                break;
            default:
                printf("Unknown image type!!\n");
                continue;
        }

        if (auth){

            img_p     = (ulong*)(((ulong)pimg_header) + sizeof(image_header_t));
            certnum   = (int)(*(img_p+65));
            image_len = 66*4+128*certnum+(int)(*(img_p+48));

            /* simple overflow check, else bad thing gonna happen, so we check at least it can't be more than src_size */
            if( image_len > src_size ){
                printf("invalid image header!!\n");
                return 2;
            }

            memcpy(dst_addr,img_p,image_len);

            REG32(0xBF201010) = 0x000001EC;
            REG32(0xBF201014) = 0x000001EC;
            REG32(0xBF201018) = 0x000001E8;
            REG32(0xBF20101C) = 0x000001E8;

            /*clear the status*/
              REG32(0xbf2013f8) = 0x0;
              asm("sync");


              /*send mailbox message*/
              REG32(0xBF20120C) = 0x01010001;
              REG32(0xBF201208) = (dst_addr & 0x0fffffff);
              REG32(0xBF201204) = image_len;
              REG32(0xBF201200) = 0x00000000;
              REG32(0xBF2011FC) = 0x00000000;
              asm("sync");
              /*kick start the interrupt*/
              REG32(0xBF201014) = 0x000001D8;
              REG32(0xBF107448) = 0x00000001;

              while((REG32(0xbf2013f8) & 0xFFFF0000) !=0x01010000);

              auth_res = (REG32(0xbf2013f8) >> 8) & 0xFF;

              if ( auth_res != 1 )
                  return 1; // fail
              else
                  rcode = 0;

              img_p+=66+(128/4)*certnum;
              image_len-=66*4+128*certnum;

        }

        curParSize = curParSize + pad;
        #ifdef CONFIG_CMD_UBI
        ubi=0;
        #endif
        auth = 0;
    } while(src_size > (srcHeader - src_addr) + curParSize);

    return rcode;
}

__attribute__((weak))

int do_auth_img_initrd (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
    ulong          *img_p=NULL;
    int            image_len, certnum;
    ulong          src_addr, dst_addr, src_size;
    int            rcode = 1;
    u8             auth_res = 0;
    image_header_t *pimg_header = NULL;
    ulong          initrd_size = 0;
    ulong          initrd_start;
    char           str[33];

    if (argc != 2) {
        cmd_usage(cmdtp);
        return 1;
    }

    src_addr = simple_strtoul(argv[1], NULL, 16);
    //src_size = simple_strtoul(argv[2], NULL, 16);
    dst_addr = src_addr + sizeof(image_header_t);

    pimg_header = (image_header_t *)src_addr;

    if ( !image_check_hcrc(pimg_header) ) {
         printf ("Bad Overall Header Checksum\n");
         return 1;
    }

    src_size = ntohl(pimg_header->ih_size);

    /* auth */
    {
        img_p     = (ulong*)(((ulong)pimg_header) + sizeof(image_header_t));
        certnum   = (int)(*(img_p+65));
        image_len = 66*4+128*certnum+(int)(*(img_p+48));

        /* simple overflow check, else bad thing gonna happen, so we check at least it can't be more than src_size */
        if( image_len > src_size ){
            printf("invalid image header!!\n");
            return 2;
        }

        REG32(0xBF201010) = 0x000001EC;
        REG32(0xBF201014) = 0x000001EC;
        REG32(0xBF201018) = 0x000001E8;
        REG32(0xBF20101C) = 0x000001E8;

        /*clear the status*/
          REG32(0xbf2013f8) = 0x0;
          asm("sync");


          /*send mailbox message*/
          REG32(0xBF20120C) = 0x01010001;
          REG32(0xBF201208) = (((ulong)img_p) & 0x0fffffff);
          REG32(0xBF201204) = image_len;
          REG32(0xBF201200) = 0x00000000;
          REG32(0xBF2011FC) = 0x00000000;
          asm("sync");
          /*kick start the interrupt*/
          REG32(0xBF201014) = 0x000001D8;
          REG32(0xBF107448) = 0x00000001;

          while((REG32(0xbf2013f8) & 0xFFFF0000) !=0x01010000);

          auth_res = (REG32(0xbf2013f8) >> 8) & 0xFF;

          if ( auth_res != 1 )
              return 1; // fail
          else
              rcode = 0;

          img_p+=66+(128/4)*certnum;
          image_len-=66*4+128*certnum;

          /* !<TODO: force to copy to aligned addr*/
          memcpy(dst_addr, img_p,image_len);
    }

    /* kernel mkimage header */
    pimg_header = (image_header_t *)dst_addr;

    if (!image_check_hcrc (pimg_header) || !image_check_dcrc (pimg_header)) {
        printf ("Bad Header Checksum\n");
        return 2;
    }

    /* safety */
    if (pimg_header->ih_type != IH_TYPE_KERNEL) {
        printf ("Bad Header type \n");
        return 3;
    }

    initrd_start  = (ulong)pimg_header + sizeof(image_header_t) + ntohl(pimg_header->ih_size);
    initrd_start  = KADDR(initrd_start);
    initrd_size   = image_len - sizeof(image_header_t) - ntohl(pimg_header->ih_size);

    /* to env */
    sprintf(str, "0x%lx", initrd_start);
    setenv("initrd_start", str);
    sprintf(str, "%li", initrd_size);
    setenv("initrd_size", str);

    return rcode;
}

/* backward version */
typedef struct{
	uint32_t param3;
	uint32_t param2;
	uint32_t size;
	uint32_t addr;
	uint32_t header;
}icc_raw_s;

#define MPS_RAM_BASE 0xBF201000

#define MPS_PTR_BASE      MPS_RAM_BASE
#define MPS_PTR_SIZE      0x20
#define MPS_PTR_4KEC_UP_R (MPS_PTR_BASE + 0x10)
#define MPS_PTR_4KEC_UP_W (MPS_PTR_BASE + 0x14)
#define MPS_PTR_IAP_UP_R  (MPS_PTR_BASE + 0x18)
#define MPS_PTR_IAP_UP_W  (MPS_PTR_BASE + 0x1C)

#define MPS_4KEC_UP_BASE  (MPS_PTR_BASE + MPS_PTR_SIZE)
#define MPS_4KEC_UP_SIZE  496
#define MPS_4KEC_UP_TOP   (MPS_4KEC_UP_BASE + MPS_4KEC_UP_SIZE - 4)

#define MPS_IAP_UP_BASE   (MPS_4KEC_UP_BASE + MPS_4KEC_UP_SIZE)
#define MPS_IAP_UP_SIZE   492
#define MPS_IAP_UP_TOP    (MPS_IAP_UP_BASE + MPS_IAP_UP_SIZE - 4)

#define GET_ICC_MSG_PTR_4KEC_UP_R ((icc_raw_s*)(MPS_RAM_BASE + MPS_PTR_SIZE + REG32(MPS_PTR_4KEC_UP_R) - sizeof(icc_raw_s) + 4))
#define GET_ICC_MSG_PTR_4KEC_UP_W ((icc_raw_s*)(MPS_RAM_BASE + MPS_PTR_SIZE + REG32(MPS_PTR_4KEC_UP_W) - sizeof(icc_raw_s) + 4))
#define GET_ICC_MSG_PTR_IAP_UP_R  ((icc_raw_s*)(MPS_RAM_BASE + MPS_PTR_SIZE + MPS_4KEC_UP_SIZE + REG32(MPS_PTR_IAP_UP_R) - sizeof(icc_raw_s) + 4))
#define GET_ICC_MSG_PTR_IAP_UP_W  ((icc_raw_s*)(MPS_RAM_BASE + MPS_PTR_SIZE + MPS_4KEC_UP_SIZE + REG32(MPS_PTR_IAP_UP_W) - sizeof(icc_raw_s) + 4))

#define CHUNK_SIZE (128*1024)//4096

/*
 * need this hack, since due to IS boot header size is 264 bytes
 * It make CHUNK_SIZE minus header size become not AES Block
 * size aligned (16 bytes) and it become the next chunk start (0x----8) become
 * not page aligned ( it make either mmap fail or eip123 refuse to decrypt it )
*/
#define USE_ALIGNED_BUFFER

/*
 * after each chunk, reset ICC ptr to top, it make the code simpler
 * else you gotta take care of not to overwrite the mbx icc_msg region
 * !<TODO: DO THE CIRCULAR BUFFER STYLE
*/
#define RESET_FIFO_PTR

#ifdef USE_ALIGNED_BUFFER
//u8 aligned_buf[CHUNK_SIZE+8];
u8* aligned_buf = 0xA0100000;
#endif /* USE_ALIGNED_BUFFER */

/*Always keep your new clients within InvalidClient and MAX_CLIENT*/
typedef enum
{
   ICC_Client,/*Icc client Id*/
	 IA,/*Image authenticator*/
	 SR,/*System reset driver*/
	 IR,/*Ioctl redirector*/
	 PR,/*procfs redirector*/
   MAX_CLIENT=21/*MAX_CLIENT_ID*/
} icc_devices;/*enum for all the possible clients*/

/* Allow ports to override the default behavior */
__attribute__((weak))
int do_auth_chunk (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
    ulong     *img_p=NULL;
    int       image_len, certnum;
    ulong     src_addr, dst_addr;
    int       rcode = 0;
    u8        auth_res = 0;
    volatile ulong     *pWritePtr = NULL;
    volatile ulong     *pReadPtr = NULL;
    volatile icc_raw_s *pIcc = NULL;

    u32 readlen   = 0;
    u32 retlen    = 0;
    u32 data_size = CHUNK_SIZE;
    u32 size      = 0;
    u8  lastChunk = 0;
    u32 data_addr = 0;

    if (argc < 2) {
        cmd_usage(cmdtp);
        return 1;
    }

    src_addr = simple_strtoul(argv[1], NULL, 16);
    dst_addr = simple_strtoul(argv[2], NULL, 16);

    img_p     = (ulong*)src_addr;
    certnum   = (int)(*(img_p+65));
    image_len = 66*4+128*certnum+(int)(*(img_p+48));

    readlen   = image_len;
    data_addr = (u32)img_p;
    while (1){
        size = MIN(readlen, data_size);

        #if 1
        //first block hack
        if( readlen == image_len &&
            retlen  == 0 &&
            size > (66*4+128*certnum+8))
        {
            size += 8;
        }
        #endif

        /*indicate bit 31 in param[1] as more if there is data left before sending */
        if ( (readlen - size) == 0 &&
             (retlen  + size) == image_len)
            lastChunk = 1;

        /*------------------- initiate icc to 4kec ------------------------*/
        #ifdef RESET_FIFO_PTR
        /* reset fifo pointer, for convenience else had to take care the size of fifo */
        REG32(MPS_PTR_4KEC_UP_R) = MPS_4KEC_UP_SIZE - 4;
        REG32(MPS_PTR_4KEC_UP_W) = MPS_4KEC_UP_SIZE - 4;
        REG32(MPS_PTR_IAP_UP_R)  = MPS_IAP_UP_SIZE - 4;
        REG32(MPS_PTR_IAP_UP_W)  = MPS_IAP_UP_SIZE - 4;
        #endif /* RESET_FIFO_PTR */

        /* safety clear the reply status of iap up first mbx*/;
        pIcc         = GET_ICC_MSG_PTR_IAP_UP_W;
        pIcc->header = 0;

        asm("sync");

#ifdef USE_ALIGNED_BUFFER // aligned buffer hack
        memcpy((void *)aligned_buf, (const void*)data_addr, size);

        /*send mailbox message to 4kec*/
        pIcc         = GET_ICC_MSG_PTR_4KEC_UP_W;
        pIcc->header = 0x01010001;
        pIcc->addr   = (((ulong)aligned_buf) & 0x0fffffff);
        pIcc->size   = size;
        pIcc->param2 = 0x00000000;
        pIcc->param3 = 0x00000000;
#else /* USE_ALIGNED_BUFFER */
        /*send mailbox message to 4kec*/
        pIcc         = GET_ICC_MSG_PTR_4KEC_UP_W;
        pIcc->header = 0x01010001;
        pIcc->addr   = (data_addr & 0x0fffffff);
        pIcc->size   = size;
        pIcc->param2 = 0x00000000;
        pIcc->param3 = 0x00000000;
#endif /* /* USE_ALIGNED_BUFFER */

        if(!lastChunk)
            pIcc->size |= 0x80000000; //set bit 31 to indicate more

        /* update write pointer of 4kec up */
        pWritePtr  = (volatile ulong*)MPS_PTR_4KEC_UP_W;
        *pWritePtr = *pWritePtr - sizeof(icc_raw_s);
        asm("sync");

        /*kick start the interrupt*/
        REG32(0xBF107448) = 0x00000001;

        /* wait for reply */
        pIcc = GET_ICC_MSG_PTR_IAP_UP_R;
        while((pIcc->header & 0xFFFF0000) !=0x01010000);

        auth_res = (pIcc->header >> 8) & 0xFF;

        /* update read pointer to indicated readed */
        #ifndef RESET_FIFO_PTR /* need to do this if above reset fifo pointer is removed */
        pWritePtr  = (volatile ulong*)MPS_PTR_IAP_UP_W;
        pReadPtr   = (volatile ulong*)MPS_PTR_IAP_UP_R;
        *pReadPtr = *pWritePtr;
        /*
         * TODO: It doesn't take care of crossing the MBX Region
         * should return to top if reach MPS_IAP_UP_BASE (0xB2F201210)
        */
        #endif

        if ( auth_res != 1 )
            return 1; // fail

        #ifdef USE_ALIGNED_BUFFER // aligned buffer hack, copy back to destination
        memcpy((void *)data_addr, (const void*)aligned_buf, size);
        #endif /* USE_ALIGNED_BUFFER */

        /*------------------- end initiate icc to 4kec ------------------------*/

        retlen    += size;
        data_addr += size;
        readlen   -= size;

        if( !readlen)
            break;
    }

    img_p     += 66+(128/4)*certnum;
    image_len -= 66*4+128*certnum;

    memcpy(dst_addr,img_p,image_len);

    return rcode;
}

/* -------------------------------------------------------------------- */

U_BOOT_CMD(
	auth, CONFIG_SYS_MAXARGS, 2, do_auth,
	"authenticate an image",
	"auth src_addr dst_addr \n    - authenticate an image in src_addr, copy the authenticated image to dst_addr\n"
);

U_BOOT_CMD(
	auth_img, CONFIG_SYS_MAXARGS, 2, do_auth_img,
	"authenticate a uboot image format, search for kernel type and authenticate it",
	"auth_img <src_addr> <dst_addr> <src_size>\n    - authenticate an kernel type inside multi image in src_addr, copy the authenticated kernel image to dst_addr\n"
);

U_BOOT_CMD(
	auth_initrd, 3, 1, do_auth_img_initrd,
	"authenticate a secure_boot image format, kernel uimage + initrd image",
	"auth_initrd <src_addr>\n    - authenticate a secure_boot image format, kernel uimage + initrd image\n"
);

U_BOOT_CMD(
	auth_chunk, 3, 2, do_auth_chunk,
	"authenticate an image in block of chunks",
	"auth_chunk src_addr dst_addr \n    - authenticate an image in src_addr, copy the authenticated image to dst_addr\n"
);


