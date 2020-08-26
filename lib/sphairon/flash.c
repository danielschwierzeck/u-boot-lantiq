// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <memalign.h>
#include <watchdog.h>
#include <spi_flash.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <jffs2/load_kernel.h>
#include <ubi_uboot.h>

#include <sas/flash.h>
#include <sas/util.h>

#define ERASE_MAX_RETRIES	3

static struct list_head sas_flash_partitions;
static int sas_flash_verbose;
static struct mtd_info *sf_mtd;
static struct mtd_info *nand_mtd;

void sas_flash_init(void)
{
	INIT_LIST_HEAD(&sas_flash_partitions);
	mtdparts_init();
}

void sas_flash_mtdids_init(void)
{
	struct mtd_info *mtd;
	char mtdids[48];
	int n = 0;

#if defined(CONFIG_LTQ_SUPPORT_SPI_FLASH)
	mtd = get_mtd_device_nm("nor0");
	if (!IS_ERR(mtd)) {
		n = sprintf(mtdids, "nor0=spi0.4");
		sf_mtd = mtd;
	}
#endif
#if defined(CONFIG_NAND_LANTIQ)
	mtd = get_mtd_device_nm("nand0");
	if (!IS_ERR(mtd)) {
		n = sprintf(mtdids + n, "%snand0=nand-cs1", n ? "," : "");
		nand_mtd = mtd;
	}

	mtd = get_mtd_device_nm("nand1");
	if (!IS_ERR(mtd)) {
		n = sprintf(mtdids + n, "%snand1=nand-cs0", n ? "," : "");
	}
#endif

	debug("%s: mtdids %s\n", __func__, mtdids);
	debug("%s: mtdparts %s\n", __func__, MTDPARTS_DEFAULT);
	setenv("mtdparts", MTDPARTS_DEFAULT);
	setenv("mtdids", mtdids);
	setenv("partitons", NULL);
	mtdparts_init();
}

void sas_flash_verbose_set(int v)
{
	sas_flash_verbose = v;
}

struct sas_flash_partition *
sas_flash_part_create(enum sas_flash_part_type type)
{
	struct sas_flash_partition *part;

	part = calloc(1, sizeof(*part));
	if (!part)
		return NULL;

	INIT_LIST_HEAD(&part->link);
	part->type = type;

	return part;
}

void sas_flash_part_destroy(struct sas_flash_partition *part)
{
	free(part);
}

void sas_flash_part_add(struct sas_flash_partition *part)
{
	list_add_tail(&part->link, &sas_flash_partitions);
}

void sas_flash_part_del(struct sas_flash_partition *part)
{
	list_del(&part->link);
}

struct sas_flash_partition *
sas_flash_part_find(enum sas_flash_part_type type)
{
	struct sas_flash_partition *part;

	list_for_each_entry(part, &sas_flash_partitions, link)
		if (part->type == type)
			return part;

	return NULL;
}

int sas_flash_part_count(void)
{
	struct list_head *pos;
	int result = 0;

	list_for_each(pos, &sas_flash_partitions)
		result++;

	return result;
}

int sas_flash_part_mtdparts_sync(struct sas_flash_partition *part)
{
	const char *name = sas_flash_partition_str(part->type);
	struct mtd_info *mtd;
	struct part_info *pinfo;
	struct mtd_device *dev;
	char mtd_dev[16];
	int err;

	debug("%s: name %s\n", __func__, name);

	err = find_dev_and_part(name, &dev, &part->pnum, &pinfo);
	if (err) {
		debug("%s: find_dev_and_part failed (%d)\n",
			__func__, err);
		return 1;
	}

	sprintf(mtd_dev, "%s%d", MTD_DEV_TYPE(dev->id->type), dev->id->num);
	mtd = get_mtd_device_nm(mtd_dev);
	if (IS_ERR(mtd))
		return 1;

	part->parent = mtd;
	part->size = pinfo->size;
	part->offset = pinfo->offset;

	return 0;
}

int sas_flash_part_mtdparts_add(const struct mtd_info *mtd,
				struct sas_flash_partition *part,
				size_t size, loff_t offset)
{
	const char *name = sas_flash_partition_str(part->type);
	int err;

	debug("%s: name %s\n", __func__, name);

	err = sas_run_command("mtdparts add %s %u@%lld %s", mtd->name,
				size, offset, name);
	if (err) {
		debug("%s: mtdparts add failed (%d)\n",
			__func__, err);
		return 1;
	}

	return sas_flash_part_mtdparts_sync(part);
}

int sas_flash_part_mtd_register(struct sas_flash_partition *part)
{
	const char *name = sas_flash_partition_str(part->type);
	struct mtd_info *mtd;
	int err;

	debug("%s: name %s\n", __func__, name);

	err = mtd_add_partition(part->parent, name, part->offset, part->size);
	if (err) {
		debug("%s: mtd_add_partition failed (%d)\n",
			__func__, err);
		return 1;
	}

	mtd = get_mtd_device_nm(name);
	if (IS_ERR(mtd))
		return 1;

	part->mtd = mtd;
	part->erase_size = mtd->erasesize;
	part->write_size = mtd->writesize;

	return 0;
}

struct mtd_info *sas_flash_boot_device(void)
{
	struct sas_flash_partition *part;

	part = sas_flash_part_find(SAS_PART_UBOOT_FIX);
	if (!part)
		return NULL;

	return part->parent;
}

struct mtd_info *sas_flash_nand_device(void)
{
	return nand_mtd;
}

struct mtd_info *sas_flash_spiflash_device(void)
{
	return sf_mtd;
}

struct mtd_info *sas_flash_storage_device(void)
{
	struct mtd_info *mtd = NULL;

#if defined(CONFIG_NAND_LANTIQ)
	mtd = get_mtd_device_nm("nand1");
	if (IS_ERR(mtd))
		return NULL;
#endif
	return mtd;
}

void sas_flash_partition_print(void)
{
	const struct sas_flash_partition *part;

	list_for_each_entry(part, &sas_flash_partitions, link) {
		sas_banner_content_print("%5s: %-16s %8x @ %08llx",
			part->parent->name, sas_flash_partition_str(part->type),
			part->size, part->offset);
	}
}

void sas_flash_ubi_volume_print(void)
{
	struct ubi_device *ubi;
	struct ubi_volume *vol;
	int i;

	ubi = ubi_get_device(0);
	if (!ubi)
		return;

	for (i = 0; i < ubi->vtbl_slots; i++) {
		vol = ubi->volumes[i];
		if (!vol)
			continue;

		sas_banner_content_print("  ubi: %-16s %8llx", vol->name,
			vol->used_bytes);
	}

	ubi_put_device(ubi);
}

static inline void sas_flash_info_print(const char *func,
					const struct sas_flash_partition *part,
					loff_t from, size_t len,
					const void *buf)
{
	if (sas_flash_verbose) {
		printf("%s: %x bytes @ %llx on %s ",
			func, len, from, part->mtd->name);
		if (buf)
			printf("-> %p ", buf);
	}
}

static inline void sas_flash_result_print(int result)
{
	if (result < 0 && result != -EOPNOTSUPP && result != -EUCLEAN) {
		printf(" failed (%d)\n", result);
		return;
	}

	if (!sas_flash_verbose)
		return;

	if (result == -EUCLEAN)
		puts(" ok, but bitflip threshold reached\n");
	else
		puts(" done\n");
}

size_t sas_flash_roundb(const struct sas_flash_partition *part, size_t len)
{
	return ROUND(len, part->mtd->erasesize);
}

int sas_flash_read(const struct sas_flash_partition *part,
			loff_t from, size_t len, void *buf)
{
	int ret;
	size_t retlen;

	sas_flash_info_print(__func__, part, from, len, buf);
	ret = mtd_read(part->mtd, from, len, &retlen, buf);
	sas_flash_result_print(ret);

	return ret;
}

static int __flash_write(struct mtd_info *mtd, loff_t off, size_t len,
			const void *buf, int scrub)
{
	size_t retlen;
	size_t write_len = len;
	loff_t write_addr = off;
	const void *src_buf = buf;
	int err;

	while (likely(len)) {
		if (!scrub) {
			err = mtd_block_isbad(mtd, write_addr);
			if (err > 0) {
				printf("\nskipping bad block at %08llx", write_addr);
				write_addr += mtd->erasesize;
				continue;
			}
		}

		write_len = len > mtd->erasesize ? mtd->erasesize : len;
		err = mtd_write(mtd, write_addr, write_len, &retlen, src_buf);
		if (err && !scrub)
			return err;

		len -= write_len;
		write_addr += mtd->erasesize;
		src_buf += mtd->erasesize;
	}

	return 0;
}

int sas_flash_write_scrub(const struct sas_flash_partition *part,
			loff_t to, size_t len, const void *buf, int scrub)
{
	int ret;

	sas_flash_info_print(__func__, part, to, len, buf);
	ret = __flash_write(part->mtd, to, len, buf, scrub);
	sas_flash_result_print(ret);

	return ret;
}

int sas_flash_lock(const struct sas_flash_partition *part,
			loff_t off, size_t len)
{
	int ret = 0;
	size_t erase_len = sas_flash_roundb(part, len);

	ret = mtd_is_locked(part->mtd, off, erase_len);
	if (ret != 0)
		return 0;

	sas_flash_info_print(__func__, part, off, erase_len, NULL);
	ret = mtd_lock(part->mtd, off, erase_len);
	sas_flash_result_print(ret);

	return ret;
}

int sas_flash_unlock(const struct sas_flash_partition *part,
			loff_t off, size_t len)
{
	int ret = 0;
	size_t erase_len = sas_flash_roundb(part, len);

	ret = mtd_is_locked(part->mtd, off, erase_len);
	if (ret <= 0)
		return 0;

	sas_flash_info_print(__func__, part, off, erase_len, NULL);
	ret = mtd_unlock(part->mtd, off, erase_len);
	sas_flash_result_print(ret);

	return ret;
}

static int __flash_erase_sync(struct mtd_info *mtd, loff_t off, void *buf,
				int scrub)
{
	struct erase_info instr;
	int err, retries;

	instr.mtd = mtd;
	instr.addr = off;
	instr.len = mtd->erasesize;
	instr.scrub = scrub;
	instr.callback = NULL;

	for (retries = 0; retries < ERASE_MAX_RETRIES; retries++) {
		err = mtd_erase(mtd, &instr);
		if (!err)
			break;

		/*
		 * Only if MTD_ERASE_FAILED is set, the erase should be retried.
		 * Otherwise the pre-conditions for mtd_erase() were not
		 * fullfilled.
		 */
		if (instr.state != MTD_ERASE_FAILED)
			return err;
	}

	/*
	 * This is reached if erase has failed. When fail_addr is set,
	 * mark the current erase block as bad.
	 */
	if (err && instr.fail_addr != MTD_FAIL_ADDR_UNKNOWN)
		err = mtd_block_markbad(mtd, instr.fail_addr);

	return err;
}

static int __flash_erase(struct mtd_info *mtd, loff_t off, size_t len, int scrub)
{
	size_t erase_len, erased_len; /* in blocks */
	loff_t addr;
	int err;
	void *buf;

	buf = malloc(mtd->erasesize);
	if (!buf) {
		puts("\nFailed to allocate mem\n");
		return -ENOMEM;
	}

	addr = off;
	erase_len = mtd_div_by_eb(len + mtd->erasesize - 1, mtd);

	putc('\n');

	for (erased_len = 0; erased_len < erase_len;
		addr += mtd->erasesize, erased_len++) {

		WATCHDOG_RESET();

		if (!scrub) {
			err = mtd_block_isbad(mtd, addr);
			if (err > 0) {
				printf("\nskipping bad block at %08llx", addr);
				continue;
			}
		}

		if (tstc()) {
			if ('c' == getc())
				return 1;
		}

		err = __flash_erase_sync(mtd, addr, buf, scrub);
		if (err && !scrub) {
			printf("\nErasing failed at block %zu\n", erase_len);
			return err;
		}

		printf("\rErasing block %zu/%zu (press c to cancel)",
			erased_len + 1, erase_len);
	}

	return 0;
}

int sas_flash_erase_scrub(const struct sas_flash_partition *part,
			loff_t off, size_t len, int scrub)
{
	size_t erase_len = sas_flash_roundb(part, len);
	int ret;

	sas_flash_info_print(__func__, part, off, erase_len, NULL);
	ret = __flash_erase(part->mtd, off, erase_len, scrub);
	sas_flash_result_print(ret);

	return ret;
}

int sas_flash_partial_erase_scrub(const struct sas_flash_partition *part,
				loff_t off, size_t len, int scrub)
{
	int ret;
	loff_t pre_start = 0, post_start = 0, post_end = 0;
	loff_t erase_start, erase_end;
	size_t pre_size, post_size, erase_len, retlen;
	void *pre_data = NULL, *post_data = NULL;
	const unsigned int write_shift = ffs(part->write_size) - 1;

	sas_flash_info_print(__func__, part, off, len, NULL);

	/* offset must align on page boundary */
	if (off & ((1ULL << write_shift) - 1)) {
		puts("offset not write size aligned\n");
		ret = -EINVAL;
		goto done;
	}

	/* length must align on page boundary */
	if (len & ((1ULL << write_shift) - 1)) {
		puts("length not write size aligned\n");
		ret = -EINVAL;
		goto done;
	}

	pre_size = mtd_mod_by_eb(off, part->mtd);
	if (pre_size) {
		pre_start = off - pre_size;
		erase_start = pre_start;

		pre_data = malloc_cache_aligned(pre_size);
		if (!pre_data) {
			ret = 1;
			goto done;
		}

		ret = mtd_read(part->mtd, pre_start, pre_size, &retlen,
			pre_data);
		if (ret < 0 && ret != -EUCLEAN)
			goto done;
	} else {
		erase_start = off;
	}

	post_size = mtd_mod_by_eb(off + len, part->mtd);
	if (post_size) {
		post_end = sas_flash_roundb(part, off + len) - 1;
		post_start = off + len;
		post_size = post_end - post_start + 1;
		erase_end = post_end;

		post_data = malloc_cache_aligned(post_size);
		if (!post_data) {
			ret = 1;
			goto done;
		}

		ret = mtd_read(part->mtd, post_start, post_size, &retlen,
			post_data);
		if (ret < 0 && ret != -EUCLEAN)
			goto done;
	} else {
		erase_end = off + len - 1;
	}

	erase_len = erase_end - erase_start + 1;

	ret = __flash_erase(part->mtd, erase_start, erase_len, scrub);
	if (ret)
		goto done;

	if (pre_data) {
		ret = mtd_write(part->mtd, pre_start, pre_size, &retlen,
			pre_data);
		if (ret)
			goto done;
	}

	if (post_data) {
		ret = mtd_write(part->mtd, post_start, post_size, &retlen,
			post_data);
		if (ret)
			goto done;
	}

done:
	sas_flash_result_print(ret);

	if (pre_data)
		free(pre_data);

	if (post_data)
		free(post_data);

	return ret;
}

int sas_flash_complete_write_scrub(const struct sas_flash_partition *part,
				loff_t to, size_t write_len,
				size_t erase_len, const void *buf,
				int partial_erase, int scrub)
{
	int ret;

	ret = sas_flash_unlock(part, 0, part->size);
	if (ret)
		return ret;

	if (partial_erase)
		ret = sas_flash_partial_erase_scrub(part, to, erase_len, scrub);
	else
		ret = sas_flash_erase_scrub(part, to, erase_len, scrub);

	if (ret)
		goto done;

	ret = sas_flash_write_scrub(part, to, write_len, buf, scrub);

done:
	sas_flash_lock(part, 0, part->size);

	return ret;
}

static inline void sas_ubi_info_print(const char *func, const char *vol_name,
					size_t len, const void *buf)
{
	if (sas_flash_verbose) {
		printf("%s: %x bytes on UBI volume %s ",
			func, len, vol_name);
		if (buf)
			printf("from %p ", buf);
	}
}

struct ubi_volume *sas_ubi_volume_find(const struct ubi_device *ubi,
					enum sas_ubi_volume_type vol_type)
{
	struct ubi_volume *vol;
	const char *vol_name;
	int i;

	vol_name = sas_ubi_volume_str(vol_type);
	if (!vol_name)
		return NULL;

	for (i = 0; i < ubi->vtbl_slots; i++) {
		vol = ubi->volumes[i];
		if (vol && !strcmp(vol->name, vol_name))
			return vol;
	}

	return NULL;
}

int sas_ubi_volume_read(enum sas_ubi_volume_type vol_type,
			void *buf, size_t size)
{
	const char *vol;
	int ret;

	vol = sas_ubi_volume_str(vol_type);
	if (!vol)
		return 1;

	sas_ubi_info_print(__func__, vol, size, buf);
	ret = ubi_volume_read((char *)vol, buf, size);
	sas_flash_result_print(ret);
	return ret;
}

int sas_ubi_volume_write(enum sas_ubi_volume_type vol_type,
				const void *buf, size_t size)
{
	const char *vol;
	int ret;

	vol = sas_ubi_volume_str(vol_type);
	if (!vol)
		return 1;

	sas_ubi_info_print(__func__, vol, size, buf);
	ret = ubi_volume_write((char *)vol, (void *)buf, size);
	sas_flash_result_print(ret);
	return ret;
}

int sas_ubi_volume_truncate(enum sas_ubi_volume_type vol_type)
{
	const char *vol;
	int ret;

	vol = sas_ubi_volume_str(vol_type);
	if (!vol)
		return 1;

	if (sas_flash_verbose)
		printf("%s: truncating UBI volume %s ",
			__func__, vol);

	ret = ubi_truncate_vol((char *)vol);
	sas_flash_result_print(ret);
	return ret;
}

static const char sas_flash_partition_strings[][16] = {
	"uboot_fix",
	"uboot_cfg",
	"uboot_update",
	"syscfg1",
	"syscfg2",
	"images1",
	"images2",
	"images3",
	"device",
	"data",
	"ubi",
	"reserved",
	"calibration",
	"syscfg",
	"romd",
	"mrd_cert1",
	"mrd_cert2",
	"storage",
	"invalid"
};

const char* sas_flash_partition_str(enum sas_flash_part_type type)
{
	assert(type <= SAS_PART_INVALID);

	return sas_flash_partition_strings[type];
}

static const char sas_ubi_volume_strings[][16] = {
	"uboot_env",
	"kernel1",
	"kernel2",
	"rootfs1",
	"rootfs2",
	"config",
	"uboot",
	"invalid"
};

const char* sas_ubi_volume_str(enum sas_ubi_volume_type type)
{
	assert(type <= SAS_UBI_INVALID);

	return sas_ubi_volume_strings[type];
}
