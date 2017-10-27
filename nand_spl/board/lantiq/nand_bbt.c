/******************************************************************************
 * lightweight nand bad block table management
 * modified from linux kernel nand_bbt.c
 * ** 19 Dec 2012  Wu Qi Ming   1.0        initial version
 * *******************************************************************************/

#include <common.h>
#include <nand.h>

#define SPL_BBT_TABLE_LOCATION 0x80800000
#define SPL_BLOCK_BUF 0x80900000

static uint8_t scan_ff_pattern[] = { 0xff, 0xff };

static struct nand_bbt_descr smallpage_memorybased = {
    .options = NAND_BBT_SCAN2NDPAGE,
    .offs = 5,
    .len = 1,
    .pattern = scan_ff_pattern
};

static struct nand_bbt_descr largepage_memorybased = {
    .options = 0,
    .offs = 0,
    .len = 2,
    .pattern = scan_ff_pattern
};

static struct nand_bbt_descr smallpage_flashbased = {
    .options = NAND_BBT_SCAN2NDPAGE,
    .offs = 5,
    .len = 1,
    .pattern = scan_ff_pattern
};

static struct nand_bbt_descr largepage_flashbased = {
    .options = NAND_BBT_SCAN2NDPAGE,
    .offs = 0,
    .len = 2,
    .pattern = scan_ff_pattern
};

static uint8_t bbt_pattern[] = {'B', 'b', 't', '0' };
static uint8_t mirror_pattern[] = {'1', 't', 'b', 'B' };

static struct nand_bbt_descr bbt_main_descr = {
    .options = NAND_BBT_LASTBLOCK | NAND_BBT_CREATE | NAND_BBT_WRITE
        | NAND_BBT_2BIT | NAND_BBT_VERSION | NAND_BBT_PERCHIP,
    .offs = 8,
    .len = 4,
    .veroffs = 12,
    .maxblocks = 4,
    .pattern = bbt_pattern
};

static struct nand_bbt_descr bbt_mirror_descr = {
    .options = NAND_BBT_LASTBLOCK | NAND_BBT_CREATE | NAND_BBT_WRITE
        | NAND_BBT_2BIT | NAND_BBT_VERSION | NAND_BBT_PERCHIP,
    .offs = 8,
    .len = 4,
    .veroffs = 12,
    .maxblocks = 4,
    .pattern = mirror_pattern
};


extern int scan_read_raw(struct mtd_info *mtd, uint8_t *buf, loff_t offs, size_t len);
extern int nand_read_page(struct mtd_info *mtd, int block, int page, uchar *dst);
/**
 * check_pattern - [GENERIC] check if a pattern is in the buffer
 * @buf:	the buffer to search
 * @len:	the length of buffer to search
 * @paglen:	the pagelength
 * @td:		search pattern descriptor
 *
 * Check for a pattern at the given place. Used to search bad block
 * tables and good / bad block identifiers.
 * If the SCAN_EMPTY option is set then check, if all bytes except the
 * pattern area contain 0xff
 *
*/
static int check_pattern(uint8_t *buf, int len, int paglen, struct nand_bbt_descr *td)
{
    int i, end = 0;
	uint8_t *p = buf;

	end = paglen + td->offs;
	if (td->options & NAND_BBT_SCANEMPTY) {
		for (i = 0; i < end; i++) {
			if (p[i] != 0xff)
				return -1;
		}
	}
	p += end;

	/* Compare the pattern */
	for (i = 0; i < td->len; i++) {
		if (p[i] != td->pattern[i])
			return -1;
	}

	if (td->options & NAND_BBT_SCANEMPTY) {
		p += td->len;
		end += td->len;
		for (i = end; i < len; i++) {
			if (*p++ != 0xff)
				return -1;
		}
	}

	return 0;
}

/**
 * check_short_pattern - [GENERIC] check if a pattern is in the buffer
 * @buf:	the buffer to search
 * @td:		search pattern descriptor
 *
 * Check for a pattern at the given place. Used to search bad block
 * tables and good / bad block identifiers. Same as check_pattern, but
 * no optional empty check
 *
*/
static int check_short_pattern(uint8_t *buf, struct nand_bbt_descr *td)
{
	int i;
	uint8_t *p = buf;

	/* Compare the pattern */
	for (i = 0; i < td->len; i++) {
		if (p[td->offs + i] != td->pattern[i])
			return -1;
	}
	return 0;
}





/**
 * search_bbt - [GENERIC] scan the device for a specific bad block table
 * @mtd:	MTD device structure
 * @buf:	temporary buffer
 * @td:		descriptor for the bad block table
 *
 * Read the bad block table by searching for a given ident pattern.
 * Search is preformed either from the beginning up or from the end of
 * the device downwards. The search starts always at the start of a
 * block.
 * If the option NAND_BBT_PERCHIP is given, each chip is searched
 * for a bbt, which contains the bad block information of this chip.
 * This is necessary to provide support for certain DOC devices.
 *
 * The bbt ident pattern resides in the oob area of the first page
 * in a block.
 */
static int search_bbt(struct mtd_info *mtd, uint8_t *buf, struct nand_bbt_descr *td)
{
	struct nand_chip *this = mtd->priv;
	int i, chips;
	int bits, startblock, block, dir;
	int scanlen = mtd->writesize + mtd->oobsize;
	int bbtblocks;
	int blocktopage = this->bbt_erase_shift - this->page_shift;

	/* Search direction top -> down ? */
	if (td->options & NAND_BBT_LASTBLOCK) {
		startblock = (mtd->size >> this->bbt_erase_shift) - 1;
		dir = -1;
	} else {
		startblock = 0;
		dir = 1;
	}
	
	asm("sync");

	/* Do we have a bbt per chip ? */
	if (td->options & NAND_BBT_PERCHIP) {
		chips = this->numchips;
		bbtblocks = this->chipsize >> this->bbt_erase_shift;
		startblock &= bbtblocks - 1;
	} else {
		chips = 1;
		bbtblocks = mtd->size >> this->bbt_erase_shift;
	}

	/* Number of bits for each erase block in the bbt */
	bits = td->options & NAND_BBT_NRBITS_MSK;

	for (i = 0; i < chips; i++) {
		/* Reset version information */
		td->version[i] = 0;
		td->pages[i] = -1;
		/* Scan the maximum number of blocks */
		for (block = 0; block < td->maxblocks; block++) {

			int actblock = startblock + dir * block;
			asm("sync");
			loff_t offs = (loff_t)actblock << this->bbt_erase_shift;
      asm("sync");
			/* Read first page */
			scan_read_raw(mtd, buf, offs, mtd->writesize);
			if (!check_pattern(buf, scanlen, mtd->writesize, td)) {
				td->pages[i] = actblock << blocktopage;
				if (td->options & NAND_BBT_VERSION) {
					td->version[i] = buf[mtd->writesize + td->veroffs];
				}
				break;
			}
		}
		startblock += this->chipsize >> this->bbt_erase_shift;
	}
	
	return 0;
}

/**
 * search_read_bbts - [GENERIC] scan the device for bad block table(s)
 * @mtd:	MTD device structure
 * @buf:	temporary buffer
 * @td:		descriptor for the bad block table
 * @md:		descriptor for the bad block table mirror
 *
 * Search and read the bad block table(s)
*/
static int search_read_bbts(struct mtd_info *mtd, uint8_t * buf, struct nand_bbt_descr *td, struct nand_bbt_descr *md)
{
	/* Search the primary table */
	search_bbt(mtd, buf, td);

	/* Search the mirror table */
	if (md)
		search_bbt(mtd, buf, md);

	/* Force result check */
	return 1;
}


/**
 * read_bbt - [GENERIC] Read the bad block table starting from page
 * @mtd:	MTD device structure
 * @buf:	temporary buffer
 * @page:	the starting page
 * @num:	the number of bbt descriptors to read
 * @bits:	number of bits per block
 * @offs:	offset in the memory table
 * @reserved_block_code:	Pattern to identify reserved blocks
 *
 * Read the bad block table starting from page.
 *
 */
static int read_bbt(struct mtd_info *mtd, uint8_t *buf, int page, int num,
		    int bits, int offs, int reserved_block_code)
{
	int res, i, j, act = 0;
	struct nand_chip *this = mtd->priv;
	size_t retlen, len, totlen;
	loff_t from;
	uint8_t msk = (uint8_t) ((1 << bits) - 1);
    int block;

	totlen = (num * bits) >> 3;
	from = ((loff_t) page) << this->page_shift;
    block = from >>this->bbt_erase_shift;
  

	while (totlen) {
		len = min(totlen, (size_t) (1 << this->bbt_erase_shift));
		//res = mtd->read(mtd, from, len, &retlen, buf);
		nand_read_page(mtd, block, 0, buf);

		/* Analyse data */
		for (i = 0; i < len; i++) {
			uint8_t dat = buf[i];
			for (j = 0; j < 8; j += bits, act += 2) {
				uint8_t tmp = (dat >> j) & msk;
				if (tmp == msk)
					continue;
				if (reserved_block_code && (tmp == reserved_block_code)) {
					this->bbt[offs + (act >> 3)] |= 0x2 << (act & 0x06);
					mtd->ecc_stats.bbtblocks++;
					continue;
				}
				/* Leave it for now, if its matured we can move this
				 * message to MTD_DEBUG_LEVEL0 */
				
				/* Factory marked bad or worn out ? */
				if (tmp == 0)
					this->bbt[offs + (act >> 3)] |= 0x3 << (act & 0x06);
				else
					this->bbt[offs + (act >> 3)] |= 0x1 << (act & 0x06);
				mtd->ecc_stats.badblocks++;
			}
		}
		totlen -= len;
		from += len;
	}
	return 0;
}

/**
 * read_abs_bbt - [GENERIC] Read the bad block table starting at a given page
 * @mtd:	MTD device structure
 * @buf:	temporary buffer
 * @td:		descriptor for the bad block table
 * @chip:	read the table for a specific chip, -1 read all chips.
 *		Applies only if NAND_BBT_PERCHIP option is set
 *
 * Read the bad block table for all chips starting at a given page
 * We assume that the bbt bits are in consecutive order.
*/
static int read_abs_bbt(struct mtd_info *mtd, uint8_t *buf, struct nand_bbt_descr *td, int chip)
{
	struct nand_chip *this = mtd->priv;
	int res = 0, i;
	int bits;

	bits = td->options & NAND_BBT_NRBITS_MSK;
	if (td->options & NAND_BBT_PERCHIP) {
		int offs = 0;
		for (i = 0; i < this->numchips; i++) {
			if (chip == -1 || chip == i)
				res = read_bbt (mtd, buf, td->pages[i], this->chipsize >> this->bbt_erase_shift, bits, offs, td->reserved_block_code);
			if (res)
				return res;
			offs += this->chipsize >> (this->bbt_erase_shift + 2);
		}
	} else {
		res = read_bbt (mtd, buf, td->pages[0], mtd->size >> this->bbt_erase_shift, bits, 0, td->reserved_block_code);
		if (res)
			return res;
	}
	return 0;
}


/**
 * check_create - [GENERIC] create and write bbt(s) if necessary
 * @mtd:	MTD device structure
 * @buf:	temporary buffer
 * @bd:		descriptor for the good/bad block search pattern
 *
 * The function checks the results of the previous call to read_bbt
 * and creates / updates the bbt(s) if necessary
 * Creation is necessary if no bbt was found for the chip/device
 * Update is necessary if one of the tables is missing or the
 * version nr. of one table is less than the other
*/
static int check_create(struct mtd_info *mtd, uint8_t *buf, struct nand_bbt_descr *bd)
{
	int i, chips, writeops, chipsel, res;
	struct nand_chip *this = mtd->priv;
	struct nand_bbt_descr *td = this->bbt_td;
	struct nand_bbt_descr *md = this->bbt_md;
	struct nand_bbt_descr *rd, *rd2;

	/* Do we have a bbt per chip ? */
	if (td->options & NAND_BBT_PERCHIP)
		chips = this->numchips;
	else
		chips = 1;

	for (i = 0; i < chips; i++) {
		writeops = 0;
		rd = NULL;
		rd2 = NULL;
		/* Per chip or per device ? */
		chipsel = (td->options & NAND_BBT_PERCHIP) ? i : -1;
		/* Mirrored table avilable ? */
		if (md) {
			if (td->pages[i] == -1 && md->pages[i] == -1) {
				writeops = 0x03;
				goto create;
			}

			if (td->pages[i] == -1) {
				rd = md;
				td->version[i] = md->version[i];
				writeops = 1;
				goto writecheck;
			}

			if (md->pages[i] == -1) {
				rd = td;
				md->version[i] = td->version[i];
				writeops = 2;
				goto writecheck;
			}

			if (td->version[i] == md->version[i]) {
				rd = td;
				if (!(td->options & NAND_BBT_VERSION))
					rd2 = md;
				goto writecheck;
			}

			if (((int8_t) (td->version[i] - md->version[i])) > 0) {
				rd = td;
				md->version[i] = td->version[i];
				writeops = 2;
			} else {
				rd = md;
				td->version[i] = md->version[i];
				writeops = 1;
			}

			goto writecheck;

		} else {
			if (td->pages[i] == -1) {
				writeops = 0x01;
				goto create;
			}
			rd = td;
			goto writecheck;
		}
	create:
	    return 0;	
	writecheck:
		/* read back first ? */
		if (rd)
			read_abs_bbt(mtd, buf, rd, chipsel);
		/* If they weren't versioned, read both. */
		if (rd2)
			read_abs_bbt(mtd, buf, rd2, chipsel);

	    return 1;
	}
	return 0;
}


/**
 * nand_scan_bbt - [NAND Interface] scan, find, read and maybe create bad block table(s)
 * @mtd:	MTD device structure
 * @bd:		descriptor for the good/bad block search pattern
 *
 * The function checks, if a bad block table(s) is/are already
 * available. If not it scans the device for manufacturer
 * marked good / bad blocks and writes the bad block table(s) to
 * the selected place.
 *
 * The bad block table memory is allocated here. It must be freed
 * by calling the nand_free_bbt function.
 *
*/
int nand_scan_bbt(struct mtd_info *mtd, struct nand_bbt_descr *bd)
{
	struct nand_chip *this = mtd->priv;
	int len, res = 0;
	uint8_t *buf;
	struct nand_bbt_descr *td = this->bbt_td;
	struct nand_bbt_descr *md = this->bbt_md;

	len = mtd->size >> (this->bbt_erase_shift + 2);
	/* Allocate memory (2bit per block) and clear the memory bad block table */
	this->bbt = SPL_BBT_TABLE_LOCATION;
    memset(this->bbt, 0, len);	

	/* Allocate a temporary buffer for one eraseblock incl. oob */
	buf = SPL_BLOCK_BUF;
	

		/* Search the bad block table using a pattern in oob */
	res = search_read_bbts(mtd, buf, td, md);

  if (res)
		res = check_create(mtd, buf, bd);
  
	return res;
	
}


/**
 * nand_default_bbt - [NAND Interface] Select a default bad block table for the device
 * @mtd:    MTD device structure
 *
 * This function selects the default bad block table
 * support for the device and calls the nand_scan_bbt function
 *
*/
int nand_default_bbt(struct mtd_info *mtd)
{
	   struct nand_chip *this = mtd->priv;
  
	    /* Is a flash based bad block table requested ? */
    if (this->options & NAND_USE_FLASH_BBT) {
        /* Use the default pattern descriptors */
        if (!this->bbt_td) {
            this->bbt_td = &bbt_main_descr;
            this->bbt_md = &bbt_mirror_descr;
        }
        if (!this->badblock_pattern) {
            this->badblock_pattern = (mtd->writesize > 512) ? &largepage_flashbased : &smallpage_flashbased;
        }
    } else {
        this->bbt_td = NULL;
        this->bbt_md = NULL;
        if (!this->badblock_pattern) {
            this->badblock_pattern = (mtd->writesize > 512) ?
                &largepage_memorybased : &smallpage_memorybased;
        }
    }
 
  
	return nand_scan_bbt(mtd, this->badblock_pattern);

}


/**
 * nand_isbad_bbt - [NAND Interface] Check if a block is bad
 * @mtd:    MTD device structure
 * @offs:   offset in the device
 * @allowbbt:   allow access to bad block table region
 *
 */
int nand_isbad_bbt(struct mtd_info *mtd, loff_t offs, int allowbbt)
{
   struct nand_chip *this = mtd->priv;
   int block;
   uint8_t res;

   /* Get block number * 2 */
   block = (int)(offs >> (this->bbt_erase_shift - 1));
   res = (this->bbt[block >> 3] >> (block & 0x06)) & 0x03;
   
   switch ((int)res) {
      case 0x00:
           return 0;
      case 0x01:
           return 1;
	  case 0x02:
	       return allowbbt ? 0 : 1;
		             }
		return 1;
}

