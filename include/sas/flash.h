/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_FLASH_H__
#define __SAS_FLASH_H__

#include <linux/list.h>
#include <sas/flash_user.h>

enum sas_flash_part_type {
	SAS_PART_UBOOT_FIX,
	SAS_PART_UBOOT_CFG,
	SAS_PART_UBOOT_UPDATE,
	SAS_PART_SYSCFG1,
	SAS_PART_SYSCFG2,
	SAS_PART_IMAGES1,
	SAS_PART_IMAGES2,
	SAS_PART_IMAGES3,
	SAS_PART_DEVICE,
	SAS_PART_DATA,
	SAS_PART_UBI,
	SAS_PART_RESERVED,
	SAS_PART_CALIBRATION,
	SAS_PART_SYSCFG,
	SAS_PART_ROMD,
	SAS_PART_MRDCERT1,
	SAS_PART_MRDCERT2,
	SAS_PART_STORAGE,
	SAS_PART_INVALID
};

enum sas_ubi_volume_type {
	SAS_UBI_UBOOT_ENV,
	SAS_UBI_KERNEL1,
	SAS_UBI_KERNEL2,
	SAS_UBI_ROOTFS1,
	SAS_UBI_ROOTFS2,
	SAS_UBI_CONFIG,
	SAS_UBI_UBOOT,
	SAS_UBI_INVALID,
};

struct mtd_info;
struct part_info;
struct ubi_device;

struct sas_flash_partition {
	struct list_head link;
	struct mtd_info *parent;
	struct mtd_info *mtd;
	enum sas_flash_part_type type;
	loff_t offset;
	size_t size;
	size_t erase_size;
	size_t write_size;
	u8 pnum;
};

/**
 * sas_flash_init - init the flash subsystem
 */
void sas_flash_init(void);
void sas_flash_mtdids_init(void);

/**
 * sas_flash_verbose_set - set verbosity of flash subsystem
 */
void sas_flash_verbose_set(int v);

/**
 * sas_flash_part_create - create a new partition instance
 *
 * @type: partition type
 */
struct sas_flash_partition *
sas_flash_part_create(enum sas_flash_part_type type);

/**
 * sas_flash_part_destroy - destroy a partition instance
 *
 * @part partition
 */
void sas_flash_part_destroy(struct sas_flash_partition *part);

/**
 * sas_flash_part_add - register a partition
 *
 * @part partition
 */
void sas_flash_part_add(struct sas_flash_partition *part);

/**
 * sas_flash_part_del - unregister a partition
 *
 * @part partition
 */
void sas_flash_part_del(struct sas_flash_partition *part);

/**
 * sas_flash_part_find - find a partition by its type
 *
 * @type: partition type
 */
struct sas_flash_partition *
sas_flash_part_find(enum sas_flash_part_type type);

/**
 * sas_flash_part_find_highest_id - find partition with highest
 * index
 */
int sas_flash_part_count(void);

/**
 * sas_flash_part_mtdparts_sync - sync a partition info with its according
 * mtdparts values
 *
 * @part partition
 */
int sas_flash_part_mtdparts_sync(struct sas_flash_partition *part);

/**
 * sas_flash_part_mtdparts_add - add a partition to mtdparts
 *
 * @mtd parent mtd device
 * @part partition
 */
int sas_flash_part_mtdparts_add(const struct mtd_info *mtd,
				struct sas_flash_partition *part,
				size_t size, loff_t offset);

/**
 * sas_flash_part_mtd_register - register a MTD device for given partition
 *
 * @part partition
 */
int sas_flash_part_mtd_register(struct sas_flash_partition *part);

struct mtd_info *sas_flash_boot_device(void);
struct mtd_info *sas_flash_nand_device(void);
struct mtd_info *sas_flash_spiflash_device(void);
struct mtd_info *sas_flash_storage_device(void);

void sas_flash_partition_print(void);
void sas_flash_ubi_volume_print(void);

size_t sas_flash_roundb(const struct sas_flash_partition *part, size_t len);

int sas_flash_read(const struct sas_flash_partition *part,
			loff_t from, size_t len, void *buf);

int sas_flash_write_scrub(const struct sas_flash_partition *part,
			loff_t to, size_t len, const void *buf, int scrub);

static inline int sas_flash_write(const struct sas_flash_partition *part,
			loff_t to, size_t len, const void *buf)
{
	return sas_flash_write_scrub(part, to, len, buf, 0);
}

int sas_flash_lock(const struct sas_flash_partition *part,
			loff_t off, size_t len);

int sas_flash_unlock(const struct sas_flash_partition *part,
			loff_t off, size_t len);

int sas_flash_erase_scrub(const struct sas_flash_partition *part,
			loff_t off, size_t len, int scrub);

static inline int sas_flash_erase(const struct sas_flash_partition *part,
			loff_t off, size_t len)
{
	return sas_flash_erase_scrub(part, off, len, 0);
}

int sas_flash_partial_erase_scrub(const struct sas_flash_partition *part,
				loff_t off, size_t len, int scrub);

static inline int sas_flash_partial_erase(const struct sas_flash_partition *part,
				loff_t off, size_t len)
{
	return sas_flash_partial_erase_scrub(part, off, len, 0);
}

int sas_flash_complete_write_scrub(const struct sas_flash_partition *part,
				loff_t to, size_t write_len, size_t erase_len,
				const void *buf, int partial_erase, int scrub);

static inline int sas_flash_complete_write(const struct sas_flash_partition *part,
				loff_t to, size_t write_len, size_t erase_len,
				const void *buf, int partial_erase)
{
	return sas_flash_complete_write_scrub(part, to, write_len, erase_len,
		buf, partial_erase, 0);
}

struct ubi_volume *sas_ubi_volume_find(const struct ubi_device *ubi,
					enum sas_ubi_volume_type vol_type);

int sas_ubi_volume_read(enum sas_ubi_volume_type vol_type,
			void *buf, size_t size);

int sas_ubi_volume_write(enum sas_ubi_volume_type vol_type,
				const void *buf, size_t size);

int sas_ubi_volume_truncate(enum sas_ubi_volume_type vol_type);

/**
 * Get size of area utilized by all ETL images
 *
 * On NAND flash this must be page-aligned.
 */
static inline size_t sas_flash_etl_size(void)
{
#if defined(CONFIG_SPHAIRON_ETL_NAND)
	return 4 * 1024;
#else
	return 256;
#endif
}

/**
 * Get count of available ETL images.
 *
 * On NAND flash multiple ETL images are stored for redundancy.
 */
static inline unsigned int sas_flash_etl_count(void)
{
#if defined(CONFIG_SPHAIRON_ETL_NAND)
	return 16 * 1024 / sas_flash_etl_size();
#else
	return 1;
#endif
}

/**
 * Get offset of one ETL image.
 *
 * On NAND flash all redundant ETL images can be addressed by erase block
 * number and ETL number inside that erase block.
 */
static inline ulong sas_flash_etl_offset(const struct sas_flash_partition *part,
					unsigned int erase_block,
					unsigned int num)
{
#if defined(CONFIG_SPHAIRON_ETL_NAND)
	return (erase_block + 1) * part->erase_size - 16 * 1024 +
		num * sas_flash_etl_size();
#else
	return part->size - 7 * 1024;
#endif
}

/**
 * Get number of erase blocks used for reserved area (CD + ETL)
 */
static inline unsigned int sas_flash_reserved_max_eb(void)
{
#if defined(CONFIG_LTQ_SPL_REDUND_IMAGES)
	return 1 + CONFIG_LTQ_SPL_REDUND_IMAGES;
#else
	return 1;
#endif
}

/**
 * Get size of reserved area (CD + ETL)
 */
static inline size_t sas_flash_reserved_size(void)
{
#if defined(CONFIG_SPHAIRON_ETL_NAND)
	return 32 * 1024;
#else
	return 8 * 1024;
#endif
}

/**
 * Get offset of reserved area (CD + ETL) per erase block.
 *
 * On NAND flash all reserved areas can be addressed by erase block number.
 */
static inline ulong
sas_flash_reserved_offset(const struct sas_flash_partition *part,
				unsigned int erase_block)
{
#if defined(CONFIG_SPHAIRON_ETL_NAND)
	return (erase_block + 1) * part->erase_size -
		sas_flash_reserved_size();
#else
	return part->size - sas_flash_reserved_size();
#endif
}

static inline int sas_flash_ubi_support(void)
{
#if defined(CONFIG_SPHAIRON_UBI_SUPPORT)
	return 1;
#else
	return 0;
#endif
}

const char* sas_flash_partition_str(enum sas_flash_part_type type);
const char* sas_ubi_volume_str(enum sas_ubi_volume_type type);

#endif /* __SAS_FLASH_H__ */
