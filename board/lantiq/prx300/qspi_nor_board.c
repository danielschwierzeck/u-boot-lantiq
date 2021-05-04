#include <common.h>
#include <command.h>
#include <version.h>
#include <net.h>
#include <environment.h>
#include <asm/mipsregs.h>
#include <asm/mipsmtregs.h>
#include <asm/boot.h>
#include <lantiq.h>
#include <mapmem.h>
#include <spi.h>
#include <spi_flash.h>
#include <lq_spi.h>

DECLARE_GLOBAL_DATA_PTR;

#define U_BOOT_OFFSET		CONFIG_SPI_SPL_SIZE
#define U_BOOT_LOAD_ADDR	0x80200000
#define U_BOOT_SIZE			0x20000
#define	FIRMWARE_SIZE		0x10000

#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
// DDR temporary placeholder before secure boot authentication put it in right place
#define SECBOOT_TMP_ADDR	0xa0800000
#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */

#ifndef CONFIG_ENV_SPI_BUS
# define CONFIG_ENV_SPI_BUS 		0
#endif
#ifndef CONFIG_ENV_SPI_CS
# define CONFIG_ENV_SPI_CS		1
#endif
#ifndef CONFIG_ENV_SPI_MAX_HZ
# define CONFIG_ENV_SPI_MAX_HZ		10000000
#endif
#ifndef CONFIG_ENV_SPI_MODE
# define CONFIG_ENV_SPI_MODE		SPI_MODE_3
#endif

#define QSPI_CLK	0
#define	QSPI_CS		1
#define QSPI_IO_0	2
#define QSPI_IO_1	3
#define QSPI_IO_2	4
#define QSPI_IO_3	5

static struct spi_flash *qspi_flash;
extern void config_qspi_refclk(void);
extern int lzma_inflate(unsigned char *source, int s_len, 
				unsigned char *dest, int *d_len);
extern void start_interaptiv(u32 addr);
extern int lq_serial_init(void);
extern void ibl(u32 cpu_num, u32 core_num, u32 vpe_num);

extern u32 get_cpu_id(void);

void hw_watchdog_reset(void) {};

int cpu_is_cps(void)
{
	int ret = 0;

	if (get_cpu_id() == 0xa1)
		ret = 1;
	return ret;
}

int check_4kec_spi_header(u32 src, u32 *jmp_addr, u32 dst_size)
{		
	int image_len;
	u8 *image_start = NULL;
	u32 ret_check, checksum = 0;
	u32 hdr_len, load_addr;
	image_header_t *pimg_header = (image_header_t *)src;
		
	/* check magic number */	
	if (ntohl(pimg_header->ih_magic) != IH_MAGIC) {
		return -1;
	}
			
	asm("sync");
	/* mkimage type kernel without the 8B offset */
	image_start = (u8 *)pimg_header + sizeof(image_header_t);
	image_len = ntohl(pimg_header->ih_size);
	load_addr = ntohl(pimg_header->ih_load);
	*jmp_addr = load_addr;
	asm("sync");

	hdr_len = sizeof(image_header_t);
	checksum = ntohl(pimg_header->ih_hcrc);
	pimg_header->ih_hcrc = 0;

	asm("sync");
	ret_check = crc32(0, (unsigned char *) src, hdr_len);
	if (ret_check != checksum) {
		return -1;
	}

	asm("sync");
	memcpy((u32 *) load_addr, (u32 *)image_start, image_len);

	return 0; // success
}

static int initr_malloc(void)
{
	gd->malloc_base = CONFIG_SYS_SPL_MALLOC_START;
	gd->malloc_ptr = 0;
	gd->malloc_limit = CONFIG_SYS_SPL_MALLOC_START +
				CONFIG_SYS_MALLOC_F_LEN;
	return 0;
}

void uncompress_image(ulong image_addr)
{
	ulong   addr;
	ulong   data, len, checksum;
	int destLen;
	image_header_t header;
	image_header_t *hdr = &header;
	int (*fn)(void);

	addr = image_addr;
	memmove (&header, (char *)addr, sizeof(image_header_t));

	if (ntohl(hdr->ih_magic) != IH_MAGIC) {
		return;
	}

	data = (ulong)&header;
	len	= sizeof(image_header_t);

	checksum = ntohl(hdr->ih_hcrc);
	hdr->ih_hcrc = 0;
	asm("sync");
	if (crc32 (0, (unsigned char *)data, len) != checksum) {
		return;
	}

	asm("sync");

	data = addr + sizeof(image_header_t);

	asm("sync");

	len	= ntohl(hdr->ih_size);
	asm("sync");

	destLen = 0x0;

	lzma_inflate ((unsigned char *)data, len, (unsigned char*)ntohl(hdr->ih_load), &destLen);
	fn = (void *) ntohl(hdr->ih_load);

	(*fn)();
}

#ifdef CONFIG_LTQ_SECURE_BOOT
void bootrom_auth(u32 addr)
{
	ulong *img_p = (ulong *)addr;
	int    image_len;
	int    certnum;
	int ret = -1;
	u32 ver_rollback_img, ver_rollback_soc;
	int (*auth)(u32 addr, int len,u32* entry_p,
		u32* target_p, u32* ver_rollback_img_p,
		u32* ver_rollback_soc_p) = (void*)0x9fc1df11;

	certnum   = (int)(*(img_p+65));
	image_len = 66*4+128*certnum+(int)(*(img_p+48));

	asm("sync");

	ret = auth((u32)img_p, image_len, NULL, NULL, &ver_rollback_img, &ver_rollback_soc);

	/* safeguard, reset if fail */
	if (0 != ret)
		*((volatile u32 *)(0xb6100010)) = 0x40000000; //global sw reset

	/* rollback id check if you want */
	#if 0
	if (ver_rollback_img < ver_rollback_soc)
	*((volatile u32 *)(0xb6100010)) = 0x40000000; //global sw reset if img rollback version is less than soc, we prevent 4kec from loading it
	#endif

	return;
}
#endif /* CONFIG_LTQ_SECURE_BOOT */

#if defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT)
void enable_eip123_iap_access()
{
   u32 reg_val = 0;

   reg_val = REG32(0xbe003F10);
   REG32(0xbe003F10) = reg_val & 0xFFFFFF00;
}
#endif /* defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT) */

/* idx:  Index
 * v_a:  Virtual address mapping 
 * p_a:  Physical address to be mapped
 * pm:	 Page Mask
 * at:	 C, D, V, G Values
 * asid: Address Space Identifier 
*/
void config_tlb(u32 idx, u32 v_a, u32 p_a, u32 pm, u32 at, u32 asid)
{
	u32 entry_hi;
	u32 entry_lo0, entry_lo1;
	entry_hi = v_a | asid;
	entry_lo0 = ((p_a >> 6) & (~0x3f)) | at;  //page 0
	entry_lo1 = ((p_a >> 6) & (~0x3f)) | at; //page 1 = page 0
	
	write_c0_entryhi(entry_hi);
	asm volatile ("tlbwi");
	asm volatile ("ehb") ;

	write_c0_index(idx);
	write_c0_pagemask(pm);
	write_c0_entrylo0(entry_lo0);
	write_c0_entrylo1(entry_lo1);
	asm volatile ("tlbwi");
	asm volatile ("ehb") ;
}

void pads_init_pins(unsigned int pin, unsigned int value)
{
	u32 rel_pin_no = pin > 32 ? (pin - 32) : pin;
	u32 offset = pin > 32 ? (0x100 + (rel_pin_no << 2)) : (rel_pin_no << 2);
	u32 reg;

	reg = ltq_r32(GPIO_PAD_CTRL_MODULE_BASE, offset);
	if ((reg & 0x7) != value)
		ltq_w32(GPIO_PAD_CTRL_MODULE_BASE, offset, 
			(ltq_r32(GPIO_PAD_CTRL_MODULE_BASE, offset) | value));
}

int qspi_gpio_init(unsigned int cs)
{
	config_qspi_refclk();

	pads_init_pins(QSPI_CLK, 0x2);
	pads_init_pins(QSPI_CS, 0x2);
	pads_init_pins(QSPI_IO_0, 0x2);
	pads_init_pins(QSPI_IO_1, 0x2);
	pads_init_pins(QSPI_IO_2, 0x2);
	pads_init_pins(QSPI_IO_3, 0x2);
	
	ltq_w32(GPIO_PAD_CTRL_MODULE_BASE, DCC_0,
		(ltq_r32(GPIO_PAD_CTRL_MODULE_BASE, DCC_0) | 0xFFF));

	ltq_w32(GPIO_PAD_CTRL_MODULE_BASE, SRC_0,
		(ltq_r32(GPIO_PAD_CTRL_MODULE_BASE, SRC_0) | 0x3F));

	/* check for 1.8v */
	if ((ltq_r32(CHIP_TOP_MODULE_BASE, GP_STRAP)
			& (1 << 15)) != 0x00008000)
		ltq_w32(CHIP_TOP_MODULE_BASE, PAD_POWER_SUPPLY_SEL,
			(ltq_r32(CHIP_TOP_MODULE_BASE, PAD_POWER_SUPPLY_SEL)
			| CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT1_VDD1V8));

	return 0;
}

void board_init_f(ulong bootflag)
{
	u32 reg;
	int i, cpu_num, vpe_num, ret;
	__attribute__((noreturn)) void (*uboot)(void);

	asm("sync");
	if (cpu_is_cps()) {
		
		REG32(0xb23f0014) = 2;
		for (i=0; i<32; i++) {
			REG32(0xb23f0018 + i*4) = 5;
		}
		
		reg = read_c0_ebase();
		cpu_num = reg & 0x1ff;
		switch (cpu_num) {
		case 0:
			for (i=0; i<4; i++){							//Reset All MSG
				REG32(CPUMSG + 4*i) = 0;
				REG32(INTMSG + 4*i) = 0;
				REG32(JMPMSG + 4*i) = 0;
			}

			REG32(CPUMSG)+=1;

			lq_serial_init();
			initr_malloc();
			/* init spi */
			/* Map 0xb0000000 to VA 0x00000000 */
			config_tlb(16, 0x00000000, 0xb0000000, 0x7FFE000, 0x16, 0x08);
			qspi_flash = spi_flash_probe(CONFIG_ENV_SPI_BUS, CONFIG_ENV_SPI_CS,
						CONFIG_ENV_SPI_MAX_HZ, CONFIG_ENV_SPI_MODE);
			
			if (!qspi_flash)
				while(1);

			#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
			spi_flash_read(qspi_flash, (ulong) U_BOOT_OFFSET, (U_BOOT_SIZE+FIRMWARE_SIZE),
					(u8*) SECBOOT_TMP_ADDR);
			asm("sync");
			/* Inform 4kec , to auth img */
			REG32(SRAMFLAG) = IPCMAGIC;
			/* wait for reply , assume during delay, SRAMFLAG will be cleared by 4kec */
			mdelay(200);
			while (REG32(SRAMFLAG) != (~IPCMAGIC));
			REG32(SRAMFLAG) = 0;
			#else /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/
			spi_flash_read(qspi_flash, (ulong) U_BOOT_OFFSET, U_BOOT_SIZE,
						(u8*) U_BOOT_LOAD_ADDR);
			#endif /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/
			asm("sync");
			uncompress_image(U_BOOT_LOAD_ADDR);
		break;
		default:
			reg = read_c0_tcbind();
			vpe_num = reg & 0xf;

			ibl(cpu_num, cpu_num, vpe_num);
			break;	
		}
	} else {
		ulong load_address;
		ulong jump_address;
		ulong ddr_address, bootcore_size;

#if defined(CONFIG_PRX300_BOOT_4KEC_ONLY) 
		REG32(0xb49001d4) = CONFIG_PRX300_FMT1_REG;
		lq_serial_init();
		initr_malloc();
		/* init spi */
		/* Map 0xb0000000 to VA 0x00000000 */
		config_tlb(16, 0x00000000, 0xb0000000, 0x7FFE000, 0x16, 0x08);
		qspi_flash = spi_flash_probe(CONFIG_ENV_SPI_BUS, CONFIG_ENV_SPI_CS,
						CONFIG_ENV_SPI_MAX_HZ, CONFIG_ENV_SPI_MODE);
			
		if (!qspi_flash)
			while(1);

		#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		spi_flash_read(qspi_flash, (ulong) U_BOOT_OFFSET, (U_BOOT_SIZE+FIRMWARE_SIZE),
					(u8*) SECBOOT_TMP_ADDR);
		bootrom_auth(SECBOOT_TMP_ADDR);
		#else /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/
		spi_flash_read(qspi_flash, (ulong) U_BOOT_OFFSET, U_BOOT_SIZE,
					(u8*) U_BOOT_LOAD_ADDR);
		#endif /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/

		asm("sync");
		uncompress_image(U_BOOT_LOAD_ADDR);
#else
		/* Initialize flag */
		REG32(SRAMFLAG) = 0;
		/* trigger IAP to run */
		start_interaptiv(CONFIG_SFDDR_TEXT_BASE);
		while (REG32(SRAMFLAG) != IPCMAGIC);
		mdelay(300);	

		#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		/*auth uboot , agree on 0xa0800000 */
		bootrom_auth(SECBOOT_TMP_ADDR);
		/* inform iap done */
		REG32(SRAMFLAG)= (~IPCMAGIC);
		asm("sync");
		#ifdef CONFIG_LTQ_EIP123_IAP_ACCESS
		/* need to do it after bootrom img auth, since they reset eip123 again */
		enable_eip123_iap_access();
		#endif /* CONFIG_LTQ_EIP123_IAP_ACCESS */
		/* next round of wait, tos command */
		mdelay(200);
		while (REG32(SRAMFLAG) != IPCMAGIC);
		mdelay(300);
		#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */

		REG32(0xb49001d4) = CONFIG_PRX300_FMT1_REG;

		asm("sync");
		load_address = REG32(MPS_LOAD_ADDR); /* 4Kec load addr */
		ddr_address = REG32(MPS_DDR_LOC);	 /* ddr where TOS is copied to */
		bootcore_size = REG32(MPS_SIZE_LOC); /* size of TOS/bootcore img */

		#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		/* reuse ddr loc only */
		bootrom_auth((u32)ddr_address);

		/* safeguard , but shall never come here in first place*/
		while(1);
		#else /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
		memcpy((unsigned char *) load_address,
				 (unsigned char *) ddr_address,
				 bootcore_size);

		ret = check_4kec_spi_header(load_address,
									(u32 *) &jump_address,
									bootcore_size);
		if (ret)
			while(1); // if img is bad, we prevent 4kec from loading it

		uboot = (void*)jump_address;
		(*uboot)();
		#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
#endif
	}
}
