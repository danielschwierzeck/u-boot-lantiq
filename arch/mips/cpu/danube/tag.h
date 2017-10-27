#ifndef _BOOT_TAG_H
#define _BOOT_TAG_H

/* Common 32 bit tag format */
#define TAG_ID(tag) 	   (tag & 0xFF000000)
#define TAG_DEBUG       0x11000000
#define TAG_REGCFG	   0x22000000
#define TAG_IDWNLD	   0x33000000
#define TAG_CDWNLD	   0x44000000
#define TAG_DWNLD	      0x55000000
#define TAG_IFCFG       0x66000000
#define TAG_START       0x77000000

#define TAG_FLAG(tag)	   (tag & 0x00FF0000)
#define FLAG_RST	   0x00800000
#define FLAG_CFG	   0x00700000
#define FLAG_CFG2	   0x00400000
#define FLAG_CFG1	   0x00200000
#define FLAG_CFG0	   0x00100000
#define FLAG_SDBG 	0x00080000
#define FLAG_DBG	   0x00040000
#define FLAG_DEC	   0x00020000
#define FLAG_START	0x00010000

/* Sum of upper and lower 16 bit word must be equal to 0xFFFF */
#define TAG_VALID(tag) ((((tag) & 0xFFFF) + (((tag) >> 16) & 0xFFFF) == 0xFFFF)?1:0)

#define TAG_HEADER_SIZE 8  /* Size of common head in bytes */

#endif /* #ifdef _BOOT_TAG_H */

