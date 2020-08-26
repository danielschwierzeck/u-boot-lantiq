// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <malloc.h>
#include <linux/mtd/mtd.h>
#include <ubi_uboot.h>

#include <sas/boot.h>
#include <sas/util.h>
#include <sas/flash.h>

struct sas_boot_image {
	struct list_head link;
	enum sas_image_type type;
	size_t size;
	loff_t offset;
	const struct sas_flash_partition *part;
	char name[SAS_IMAGE_NAME_LEN];
	enum sas_ubi_volume_type ubi_vol;
};

static struct list_head sas_boot_images;

void sas_boot_init(void)
{
	INIT_LIST_HEAD(&sas_boot_images);
}

static int sas_boot_image_add(const struct sas_flash_partition *part,
				const struct sas_image *img, loff_t offset,
				enum sas_ubi_volume_type ubi_vol)
{
	struct sas_boot_image *image;

	image = malloc(sizeof(*image));
	if (!image)
		return 1;

	INIT_LIST_HEAD(&image->link);
	image->type = img->type;
	image->size = img->size;
	image->offset = offset;
	image->part = part;
	image->ubi_vol = ubi_vol;
	strncpy(image->name, img->name, SAS_IMAGE_NAME_LEN);

	list_add_tail(&image->link, &sas_boot_images);

	return 0;
}

/*
 * Scan for boot images.
 *
 * - with PSH layout we expect a kernel image or servicefs image
 *   at partition begin
 * - with all other layouts we expect only a kernel image at
 *   partition begin
 * - if kernel image or servicefs image could not found we can abort
 *   the scan for this partition
 */
static int sas_boot_image_part_scan(const struct sas_flash_partition *part)
{
	const size_t hdr_size = sas_image_hdr_size();
	int ret;
	struct sas_image img;
	loff_t offset;
	u8 img_hdr[hdr_size];

	debug("%s: mtd->name %s, mtd->size %llx, mtd->erasesize %x\n",
		__func__, part->mtd->name, part->mtd->size, part->mtd->erasesize);

	offset = 0;
	do {
		ret = sas_flash_read(part, offset, hdr_size, img_hdr);
		if (ret)
			return ret;

		ret = sas_image_parse(img_hdr, &img);
		if (ret) {
			offset += CONFIG_SPHAIRON_SCAN_STEP_SIZE;
			continue;
		}

		/*
		 * Skip image and abort scan if image size exceeds
		 * remaining gap between current offset and MTD size.
		 * This situation can occur after changes on
		 * flash layout.
		 */
		if (img.size >= part->mtd->size - offset)
			return 0;

		ret = sas_boot_image_add(part, &img, offset, SAS_UBI_INVALID);
		if (ret)
			return ret;

		offset += img.size;
		offset = ALIGN(offset, CONFIG_SPHAIRON_SCAN_STEP_SIZE);
	} while (offset < part->mtd->size);

	return 0;
}

static void sas_boot_content_set(unsigned int index, int has_platform,
					int has_service, int *save_env)
{
	unsigned int content = (has_platform | (has_service << 1));
	char buf[32];

	sprintf(buf, "image_content%u", index);
	printf("Setting content of image %u to %u\n",
		index, content);

	sas_setenv_num(buf, content, save_env);
}

static enum sas_boot_state sas_boot_state_get(unsigned int index)
{
	char buf[32];
	int state;

	sprintf(buf, "image_state%u", index);

	state = getenv_ulong(buf, 10, SAS_BOOT_NOTAVAILABLE);
	if (state > SAS_BOOT_IGNORED)
		state = SAS_BOOT_NOTAVAILABLE;

	return state;
}

static void sas_boot_state_set(unsigned int index, enum sas_boot_state state,
				int *save_env)
{
	char buf[32];

	sprintf(buf, "image_state%u", index);
	printf("Setting state of image %u to '%s'\n",
		index, sas_boot_state_str(state));

	sas_setenv_num(buf, state, save_env);
}

static int sas_boot_bootcount_get(void)
{
	return getenv_ulong("boot_count", 10, 0);
}

static int sas_boot_bootcountmax_get(void)
{
	return getenv_ulong("boot_count_max", 10, 3);
}

static void sas_boot_bootcount_set(int value, int *save_env)
{
	printf("Setting boot_count to %d\n", value);
	sas_setenv_num("boot_count", value, save_env);
}

static int sas_boot_boottry_get(void)
{
	return getenv_ulong("boot_try", 10, 0);
}

static void sas_boot_boottry_set(int value, int *save_env)
{
	printf("Setting boot_try to %d\n", value);
	sas_setenv_num("boot_try", value, save_env);
}

static void sas_boot_flush_images(void)
{
	struct sas_boot_image *image;

	while (!list_empty(&sas_boot_images)) {
		image = list_first_entry(&sas_boot_images,
					 struct sas_boot_image, link);
		list_del(&image->link);
		free(image);
	}
}

static int sas_boot_scan_images_legacy(int *save_env)
{
	const struct sas_flash_partition *part;
	enum sas_flash_layout_type flash_layout = sas_flash_layout_current();
	enum sas_boot_state state_new, state_cur;
	int ret, image_cnt, i;
	int has_platformfs, has_servicefs;

	image_cnt = sas_flash_layout_image_part_cnt(flash_layout);

	for (i = 0; i < sas_flash_layout_max_image_parts(); i++) {
		if (i >= image_cnt) {
			sas_boot_state_set(i + 1, SAS_BOOT_NOTAVAILABLE,
				save_env);
			sas_boot_content_set(i + 1, 0, 0, save_env);
			continue;
		}

		part = sas_flash_layout_image_partition(i);

		ret = sas_boot_image_part_scan(part);
		if (ret)
			return ret;

		has_platformfs = sas_boot_has_platform_images(part);
		has_servicefs = sas_boot_has_service_images(part);

		sas_boot_content_set(i + 1, has_platformfs, has_servicefs,
			save_env);

		state_cur = sas_boot_state_get(i + 1);
		state_new = SAS_BOOT_NOTAVAILABLE;

		if (has_platformfs)
			state_new = SAS_BOOT_AVAILABLE;

		if (state_new == SAS_BOOT_AVAILABLE &&
			state_cur != SAS_BOOT_NOTAVAILABLE)
			state_new = state_cur;

		sas_boot_state_set(i + 1, state_new, save_env);
	}

	return 0;
}

static int sas_boot_ubi_scan_image(const struct ubi_device *ubi,
				const struct sas_flash_partition *part,
				enum sas_ubi_volume_type vol_type)
{
	const size_t hdr_size = sas_image_hdr_size();
	struct sas_image img;
	u8 img_hdr[hdr_size];
	int ret;

	if (!sas_ubi_volume_find(ubi, vol_type))
		return 0;

	ret = sas_ubi_volume_read(vol_type, img_hdr, hdr_size);
	if (ret)
		return 0;

	ret = sas_image_parse(img_hdr, &img);
	if (ret)
		return 0;

	ret = sas_boot_image_add(part, &img, 0, vol_type);
	if (ret)
		return 0;

	return 1;
}

struct squashfs_super_block {
	__le32 s_magic;
	__le32 pad0[9];
	__le64 bytes_used;
};

#define SQUASHFS_MAGIC	0x73717368

static int sas_boot_ubi_scan_squashfs(const struct ubi_device *ubi,
					const struct sas_flash_partition *part,
					enum sas_ubi_volume_type vol_type)
{
	struct sas_image img;
	struct squashfs_super_block sq_sb;
	int ret;

	if (!sas_ubi_volume_find(ubi, vol_type))
		return 0;

	ret = sas_ubi_volume_read(vol_type, &sq_sb, sizeof(sq_sb));
	if (ret)
		return 0;

	if (le32_to_cpu(sq_sb.s_magic) != SQUASHFS_MAGIC)
		return 0;

	sprintf(img.name, "rootfs#SQFS");
	img.type = SAS_IMG_ROOTFS;
	img.size = le64_to_cpu(sq_sb.bytes_used);

	ret = sas_boot_image_add(part, &img, 0, vol_type);
	if (ret)
		return 0;

	return 1;
}

static int sas_boot_scan_images_ubi(int *save_env)
{
	const struct sas_flash_partition *part;
	struct ubi_device *ubi;
	enum sas_ubi_volume_type kernel_vol, rootfs_vol;
	enum sas_boot_state state_new, state_cur;
	int has_kernel, has_rootfs, has_platform, i;

	part = sas_flash_part_find(SAS_PART_UBI);
	if (!part)
		return 1;

	ubi = ubi_get_device(0);
	if (!ubi) {
		puts("No attached UBI found\n");
		return 0;
	}

	for (i = 0; i < 2; i++) {
		if (i) {
			kernel_vol = SAS_UBI_KERNEL2;
			rootfs_vol = SAS_UBI_ROOTFS2;
		} else {
			kernel_vol = SAS_UBI_KERNEL1;
			rootfs_vol = SAS_UBI_ROOTFS1;
		}

		has_kernel = sas_boot_ubi_scan_image(ubi, part, kernel_vol);
		has_rootfs = sas_boot_ubi_scan_squashfs(ubi, part, rootfs_vol);
		has_platform = has_kernel && has_rootfs;

		sas_boot_content_set(i + 1, has_platform, 0, save_env);

		state_cur = sas_boot_state_get(i + 1);
		state_new = SAS_BOOT_NOTAVAILABLE;

		if (has_platform)
			state_new = SAS_BOOT_AVAILABLE;

		if (state_new == SAS_BOOT_AVAILABLE &&
			state_cur != SAS_BOOT_NOTAVAILABLE)
			state_new = state_cur;

		sas_boot_state_set(i + 1, state_new, save_env);
	}

	ubi_put_device(ubi);

	return 0;
}

int sas_boot_scan_images(int *save_env)
{
	enum sas_flash_layout_type flash_layout = sas_flash_layout_current();

	debug("sas_boot: scanning\n");

	sas_boot_flush_images();

	if (sas_flash_layout_has_image_parts(flash_layout))
		return sas_boot_scan_images_legacy(save_env);

	if (sas_flash_ubi_support())
		return sas_boot_scan_images_ubi(save_env);

	return 0;
}

static struct sas_boot_image *
sas_boot_image_find(enum sas_image_type type,
			const struct sas_flash_partition *part)
{
	struct sas_boot_image *image;

	list_for_each_entry(image, &sas_boot_images, link) {
		if (part == image->part && type == image->type)
			return image;
	}

	return NULL;
}

static int sas_boot_fs_part_add(const struct sas_flash_partition *part,
				enum sas_image_type type, const char *name)
{
	struct sas_boot_image *image;
	int err;
	size_t size;
	loff_t offset;

	debug("%s: part %d, name %s\n", __func__, part->type, name);

	image = sas_boot_image_find(type, part);
	if (!image)
		return 1;

	size = image->size - sizeof(image_header_t);
	offset = image->offset + part->offset + sizeof(image_header_t);

	err = sas_run_command("mtdparts add %s %zu@%lld %s ro",
		part->parent->name, size, offset, name);
	if (err)
		return err;

	return 0;
}

int sas_boot_init_platform_mtdparts(int active_image,
					enum sas_flash_layout_type layout)
{
	const struct sas_flash_partition *part;

	if (!active_image)
		return 1;

	part = sas_flash_layout_image_partition(active_image - 1);
	if (!part)
		return 1;

	return sas_boot_fs_part_add(part, SAS_IMG_ROOTFS, "rootfs");
}

int sas_boot_init_service_mtdparts(int active_image,
					enum sas_flash_layout_type layout)
{
	const struct sas_flash_partition *part;
	int ret;

	if (!active_image)
		return 1;

	part = sas_flash_layout_image_partition(active_image - 1);
	if (!part)
		return 1;

	ret = sas_boot_fs_part_add(part, SAS_IMG_SERVICEFS, "servicefs");
	if (ret)
		return ret;

	ret = sas_boot_fs_part_add(part, SAS_IMG_DEFCONFIG, "defconfig");
	if (ret)
		return ret;

	return 0;
}

static int sas_boot_sysconfig_part_add(enum sas_flash_part_type type,
					const char *name)
{
	const struct sas_flash_partition *part;
	int ret;

	debug("%s: type %d, name %s\n", __func__, type, name);

	part = sas_flash_part_find(type);
	if (!part)
		return 1;

	ret = sas_run_command("mtdparts add %s %zu@%lld %s", part->parent->name,
		part->size, part->offset, name);
	if (ret)
		return ret;

	return 0;
}

int sas_boot_init_sysconfig_mtdparts(int active_image,
					enum sas_flash_layout_type layout)
{
	enum sas_flash_part_type cfg_active, cfg_backup;
	int ret;

	if (!active_image)
		active_image = sas_boot_boottry_get();

	if (!active_image)
		active_image = 1;

	if (sas_flash_layout_is_mirrored(layout)) {
		if (active_image == 2) {
			cfg_active = SAS_PART_SYSCFG2;
			cfg_backup = SAS_PART_SYSCFG1;
		} else {
			cfg_active = SAS_PART_SYSCFG1;
			cfg_backup = SAS_PART_SYSCFG2;
		}
	} else {
		cfg_active = SAS_PART_SYSCFG1;
		cfg_backup = SAS_PART_INVALID;
	}

	ret = sas_boot_sysconfig_part_add(cfg_active, "cfg_active");
	if (ret)
		return ret;

	if (cfg_backup != SAS_PART_INVALID) {
		ret = sas_boot_sysconfig_part_add(cfg_backup, "cfg_backup");
		if (ret)
			return ret;
	}

	return 0;
}

int sas_boot_init_ubi_mtdparts(int active_image,
				enum sas_flash_layout_type layout)
{
	const struct sas_flash_partition *part;
	struct ubi_device *ubi;
	struct ubi_volume *vol;
	char buf[32];
	int part_cnt;

	part = sas_flash_part_find(SAS_PART_UBI);
	if (!part)
		return 1;

	ubi = ubi_get_device(0);
	if (!ubi)
		return 1;

	if (active_image == 2)
		vol = sas_ubi_volume_find(ubi, SAS_UBI_ROOTFS2);
	else
		vol = sas_ubi_volume_find(ubi, SAS_UBI_ROOTFS1);

	if (!vol) {
		ubi_put_device(ubi);
		return 1;
	}

	snprintf(buf, sizeof(buf), "ubi.mtd=%s,%d", part->mtd->name,
		ubi->vid_hdr_offset);
	sas_setenv("ubi_parts", buf, NULL);

	part_cnt = sas_flash_part_count();

	debug("%s: vol_id %d, part_cnt %d\n", __func__, vol->vol_id, part_cnt);

	snprintf(buf, sizeof(buf), "root=/dev/mtdblock%d rootfstype=squashfs",
		vol->vol_id + part_cnt);
	sas_setenv("ubi_root", buf, NULL);

	ubi_put_device(ubi);

	return 0;
}

int sas_boot_find_working_image(enum sas_flash_layout_type layout)
{
	unsigned int first_active_working = 0;
	unsigned int first_inactive_working = 0;
	unsigned int first_available = 0;
	unsigned int part_cnt = sas_flash_layout_image_part_cnt(layout);
	unsigned int i, image_index;
	enum sas_boot_state state;

	/*
	 * Boot image selection strategy:
	 * 1) use first active,working image if available
	 * 2) prefer first available image over inactive,working
	 *    -> firmware update case
	 * 3) use first inactive,working image
	 */

	for (i = 0; i < part_cnt; i++) {
		image_index = i + 1;
		state = sas_boot_state_get(image_index);

		switch (state) {
		case SAS_BOOT_ACTIVEWORKING:
			if (!first_active_working)
				first_active_working = image_index;
			break;
		case SAS_BOOT_INACTIVEWORKING:
			if (!first_inactive_working)
				first_inactive_working = image_index;
			break;
		case SAS_BOOT_AVAILABLE:
			if (!first_available)
				first_available = image_index;
			break;
		default:
			break;
		}
	}

	if (first_active_working) {
		printf("Using first active,working image %u\n",
			first_active_working);
		return first_active_working;
	}

	if (first_available) {
		printf("Using first available image %u\n",
			first_available);
		return first_available;
	}

	if (first_inactive_working) {
		printf("Using first inactive,working image %u\n",
			first_inactive_working);
		return first_inactive_working;
	}

	puts("No active image found\n");

	return 0;
}

int sas_boot_update_states(int active_image, int *retry, int *save_env)
{
	unsigned int boot_try = sas_boot_boottry_get();
	unsigned int boot_cnt = sas_boot_bootcount_get();
	unsigned int boot_cnt_max = sas_boot_bootcountmax_get();
	enum sas_boot_state state_cur, state_new;
	int can_boot = 0;

	if (active_image)
		state_cur = sas_boot_state_get(active_image);
	else
		state_cur = SAS_BOOT_NOTWORKING;

	state_new = state_cur;

	*retry = 0;

	switch (state_cur) {
	case SAS_BOOT_AVAILABLE:
		if (boot_cnt < boot_cnt_max) {
			boot_cnt++;
			boot_try = active_image;
			can_boot = 1;
		} else {
			printf("Boot retry count exceeded for image %u\n",
				active_image);
			state_new = SAS_BOOT_NOTWORKING;
			boot_cnt = 0;
			*retry = 1;
		}
		break;
	case SAS_BOOT_ACTIVEWORKING:
		boot_try = active_image;
		can_boot = 1;
		break;
	case SAS_BOOT_INACTIVEWORKING:
		state_new = SAS_BOOT_ACTIVEWORKING;
		boot_try = active_image;
		can_boot = 1;
		break;
	case SAS_BOOT_NOTWORKING:
		boot_try = 0;
		break;
	default:
		break;
	}

	if (state_new != state_cur) {
		printf("Changing image state %u: %s -> %s\n", active_image,
			sas_boot_state_str(state_cur),
			sas_boot_state_str(state_new));
	}

	sas_boot_state_set(active_image, state_new, save_env);
	sas_boot_bootcount_set(boot_cnt, save_env);
	sas_boot_boottry_set(boot_try, save_env);

	return can_boot;
}

int sas_boot_has_platform_images(const struct sas_flash_partition *part)
{
	struct sas_boot_image *image;
	int has_kernel = 0, has_rootfs = 0;

	list_for_each_entry(image, &sas_boot_images, link) {
		if (part != image->part)
			continue;

		if (SAS_IMG_KERNEL == image->type)
			has_kernel = 1;

		if (SAS_IMG_ROOTFS == image->type)
			has_rootfs = 1;
	}

	return has_kernel && has_rootfs;
}

int sas_boot_has_service_images(const struct sas_flash_partition *part)
{
	struct sas_boot_image *image;
	int has_servicefs = 0, has_defconfig = 0;

	list_for_each_entry(image, &sas_boot_images, link) {
		if (part != image->part)
			continue;

		if (SAS_IMG_SERVICEFS == image->type)
			has_servicefs = 1;

		if (SAS_IMG_DEFCONFIG == image->type)
			has_defconfig = 1;
	}

	return has_servicefs && has_defconfig;
}

void sas_boot_invalidate_image_state(unsigned int active_image)
{
	int save_env = 0;

	sas_boot_state_set(active_image, SAS_BOOT_NOTAVAILABLE, &save_env);

	if (save_env)
		sas_saveenv();
}

int sas_boot_invalidate_platform_images(const struct sas_flash_partition *part)
{
	struct sas_boot_image *image;
	ulong data = 0;
	int ret;

	list_for_each_entry(image, &sas_boot_images, link) {
		if (part != image->part || (SAS_IMG_KERNEL != image->type &&
			SAS_IMG_ROOTFS != image->type))
			continue;

		printf("Invalidating image %s @ %llx on %s\n",
			image->name, image->offset, part->mtd->name);

		ret = sas_flash_write(part, image->offset, sizeof(data), &data);
		if (ret)
			return ret;
	}

	return 0;
}

int sas_boot_invalidate_service_images(const struct sas_flash_partition *part)
{
	struct sas_boot_image *image;
	ulong data = 0;
	int ret;

	list_for_each_entry(image, &sas_boot_images, link) {
		if (part != image->part || (SAS_IMG_SERVICEFS != image->type &&
			SAS_IMG_DEFCONFIG != image->type))
			continue;

		printf("Invalidating image %s @ %llx on %s\n",
			image->name, image->offset, part->mtd->name);

		ret = sas_flash_write(part, image->offset, sizeof(data), &data);
		if (ret)
			return ret;
	}

	return 0;
}

int sas_boot_layout_platform(const struct sas_flash_partition *part,
				size_t uimage_size, size_t rootfs_size,
				ulong *uimage_addr, ulong *rootfs_addr,
				size_t *erase_len)
{
	ulong uimage_srcaddr, rootfs_srcaddr;

	debug("%s: part %s, uimage_size %zu, rootfs_size %zu\n",
		__func__, part->mtd->name, uimage_size, rootfs_size);

	uimage_srcaddr = 0;
	rootfs_srcaddr = uimage_srcaddr + uimage_size;

	debug("%s: uimage_srcaddr %08lx, rootfs_srcaddr %08lx\n",
		__func__, uimage_srcaddr, rootfs_srcaddr);

	*uimage_addr = uimage_srcaddr;
	*rootfs_addr = ALIGN(rootfs_srcaddr, CONFIG_SPHAIRON_SCAN_STEP_SIZE);

	*erase_len = *rootfs_addr + rootfs_size;
	*erase_len = sas_flash_roundb(part, *erase_len);

	if (*erase_len > part->size) {
		puts("Size of images exceeds partition size\n");
		return 1;
	}

	debug("%s: uimage_addr %08lx, rootfs_addr %08lx, erase_len %zu\n",
		__func__, *uimage_addr, *rootfs_addr, *erase_len);

	return 0;
}

int sas_boot_layout_service(const struct sas_flash_partition *part,
				size_t servicefs_size, size_t configfs_size,
				ulong *servicefs_addr, ulong *configfs_addr,
				size_t *erase_len)
{
	struct sas_boot_image *image;
	ulong servicefs_srcaddr, configfs_srcaddr;
	ulong rootfs_endaddr = 0;

	debug("%s: part %s, servicefs_size %zu, configfs_size %zu\n",
		__func__, part->mtd->name, servicefs_size, configfs_size);

	image = sas_boot_image_find(SAS_IMG_ROOTFS, part);
	if (image)
		rootfs_endaddr = image->offset + image->size;

	servicefs_srcaddr = ALIGN(rootfs_endaddr, part->mtd->erasesize);
	configfs_srcaddr = servicefs_srcaddr + servicefs_size;

	debug("%s: rootfs_endaddr %08lx, servicefs_srcaddr %08lx, configfs_srcaddr %08lx\n",
		__func__, rootfs_endaddr, servicefs_srcaddr, configfs_srcaddr);

	*servicefs_addr = servicefs_srcaddr;
	*configfs_addr = ALIGN(configfs_srcaddr, part->mtd->erasesize);

	*erase_len = *configfs_addr + configfs_size - *servicefs_addr;
	*erase_len = sas_flash_roundb(part, *erase_len);

	if (*erase_len > (part->size - servicefs_srcaddr)) {
		puts("Size of images exceeds partition size\n");
		return 1;
	}

	debug("%s: rootfs_endaddr %08lx, servicefs_addr %08lx, configfs_addr %08lx, erase_len %zu\n",
		__func__, rootfs_endaddr, *servicefs_addr, *configfs_addr,
		*erase_len);

	return 0;
}

int sas_boot_load_image(const struct sas_flash_partition *part,
			enum sas_image_type type, ulong addr)
{
	struct sas_boot_image *image;

	image = sas_boot_image_find(type, part);
	if (!image)
		return 1;

	return sas_flash_read(part, image->offset, image->size, (void *) addr);
}

void sas_boot_print(void)
{
	struct sas_boot_image *image;
	enum sas_boot_state state;
	unsigned int i;
	enum sas_flash_layout_type layout = sas_flash_layout_current();
	unsigned int images_max = sas_flash_layout_image_part_cnt(layout);

	sas_banner_header_print("Boot info");

	list_for_each_entry(image, &sas_boot_images, link)
		if (image->ubi_vol == SAS_UBI_INVALID)
			sas_banner_content_print("%-8s @ %08llx      %-32s",
				sas_flash_partition_str(image->part->type),
				image->offset, image->name);
		else
			sas_banner_content_print("ubi: %-20s%-32s",
				sas_ubi_volume_str(image->ubi_vol),
				image->name);

	sas_banner_line_print();

	for (i = 1; i <= images_max; i++) {
		state = sas_boot_state_get(i);
		sas_banner_content_print("Boot image %d%13s%-32s", i, "",
						sas_boot_state_str(state));
	}

	sas_banner_content_print("%-25s%-u ", "Boot count",
					sas_boot_bootcount_get());
	sas_banner_content_print("%-25s%-u ", "Boot try",
					sas_boot_boottry_get());

	sas_banner_footer_print();
}

static const char sas_boot_state_strings[][20] = {
	"not available",
	"available",
	"active,working",
	"inactive,working",
	"not working",
	"ignored",
	"invalid"
};

const char* sas_boot_state_str(enum sas_boot_state state)
{
	assert(state <= SAS_BOOT_INVALID);

	return sas_boot_state_strings[state];
}
