// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <linux/list.h>
#include <linux/mtd/mtd.h>
#include <ubi_uboot.h>

#include <sas/util.h>
#include <sas/flash.h>
#include <sas/flashlayout.h>
#include <sas/boot.h>
#include <sas/etl.h>

#define SAS_UBOOT_USED		SAS_UBOOT_LZO_NANDSPL

static int sas_upgrade_images_load(const char *name1, ulong *addr1,
					size_t *size1, const char *name2,
					ulong *addr2, size_t *size2)
{
	ulong loadaddr;
	size_t size;

	loadaddr = getenv_ulong("loadaddr", 16, 0);

	size = sas_run_tftpboot(loadaddr, name1);
	if (!size)
		goto err;

	*addr1 = loadaddr;
	*size1 = size;

	debug("addr1 %08lx, size1 %zu\n", *addr1, *size1);

	if (!name2)
		return 0;

	loadaddr += size + 1;
	loadaddr = ROUND(loadaddr, 32);

	size = sas_run_tftpboot(loadaddr, name2);
	if (!size)
		goto err;

	*addr2 = loadaddr;
	*size2 = size;

	debug("addr2 %08lx, size2 %zu\n", *addr2, *size2);

	return 0;

err:
	puts("Could not load images\n");

	return 1;
}

static int sas_upgrade_image_load(cmd_tbl_t * cmdtp, int argc,
					char *const argv[], const char *image,
					ulong *addr, size_t *size)
{
	int ret;
	ulong val;

	if (argc == 1) {
		return sas_upgrade_images_load(image, addr, size,
						NULL, NULL, NULL);
	} else if (argc == 3) {
		ret = strict_strtoul(argv[1], 16, &val);
		if (ret)
			return 1;

		*addr = val;

		ret = strict_strtoul(argv[2], 16, &val);
		if (ret)
			return 1;

		if (!val) {
			printf("Invalid size %08zx\n", *size);
			return 1;
		}

		*size = val;

		return 0;
	}

	return cmd_usage(cmdtp);
}

static int sas_upgrade_image_check(ulong loadaddr, enum sas_image_type image_type)
{
	int ret;
	const void *addr = (const void *) loadaddr;
	struct sas_image img;

	ret = sas_image_parse(addr, &img);
	if (img.type != image_type) {
		puts("invalid image type\n");
		return 0;
	}

	ret = sas_run_command("iminfo %p", addr);
	if (ret)
		return 0;

	return 1;
}

static int sas_upgrade_check_forced(int argc, char *const argv[])
{
	return (argc == 2 || argc == 4) && !strcmp(argv[1], "-f");
}

static int do_sas_upgrade_uboot(cmd_tbl_t * cmdtp, int flag,
					int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	ulong loadaddr;
	void *addr;
	size_t size;
	int ret, eb;

	if (sas_upgrade_check_forced(argc, argv)) {
		argc--;
		argv++;
	} else {
		ret = sas_confirm("Caution: this can damage your board");
		if (!ret)
			return 0;
	}

	part = sas_flash_part_find(SAS_PART_UBOOT_FIX);
	if (!part)
		return 1;

	ret = sas_upgrade_image_load(cmdtp, argc, argv, SAS_UBOOT_USED,
					&loadaddr, &size);
	if (ret) {
#if defined(CONFIG_UART_BOOT)
		printf("Please link the correct image (%s or %s or %s) to %s!\n",
			   SAS_UBOOT_LZO_NANDSPL,
			   SAS_UBOOT_LZO_NANDHWSPL,
			   SAS_UBOOT_LZO_SFSPL,
			   SAS_UBOOT_USED);
#endif
		return ret;
	}

	if (size > part->size) {
		puts("Image size too big\n");
		return 1;
	}

	/* clear area after loaded image upto loadaddr + part->size */
	addr = (void *)(loadaddr + size);
	memset(addr, 0xff, part->size - size);

	/* read reserved area from flash and copy to loaded image */
	sas_flash_verbose_set(1);
	for (eb = 0; eb < sas_flash_reserved_max_eb(); eb++) {
		addr = (void *)(loadaddr + sas_flash_reserved_offset(part, eb));
		sas_flash_read(part, sas_flash_reserved_offset(part, eb),
			sas_flash_reserved_size(), addr);
	}

	ret = sas_flash_complete_write_scrub(part, 0, part->size, part->size,
					(const void *) loadaddr, 0, 1);

	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

static __maybe_unused int do_sas_upgrade_uboot_ubi(cmd_tbl_t * cmdtp, int flag,
					int argc, char *const argv[])
{
	int ret;
	ulong loadaddr;
	size_t size;
	enum sas_ubi_volume_type uboot_vol = SAS_UBI_UBOOT;

	if (sas_upgrade_check_forced(argc, argv)) {
		argc--;
		argv++;
	} else {
		ret = sas_confirm("Caution: this can damage your board");
		if (!ret)
			return 0;
	}

	ret = sas_upgrade_image_load(cmdtp, argc, argv, SAS_UBOOT_LZO_UBI_IMAGE,
					&loadaddr, &size);
	if (ret)
		return ret;

	ret = sas_upgrade_image_check(loadaddr, SAS_IMG_UBOOT);
	if (!ret)
		return 1;

	sas_flash_verbose_set(1);
	ret = sas_ubi_volume_write(uboot_vol, (const void *)loadaddr, size);

	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

#if defined(CONFIG_SPHAIRON_UBI_SUPPORT) && defined(CONFIG_SPHAIRON_MSTC_UBISQ)
U_BOOT_CMD(sas_upgrade_uboot, 4, 0, do_sas_upgrade_uboot_ubi,
	"Update U-Boot in UBI volume", "[-f] [addr size]\n");
#else
U_BOOT_CMD(sas_upgrade_uboot, 4, 0, do_sas_upgrade_uboot,
	"Update U-Boot in flash", "[-f] [addr size]\n");
#endif

static int do_sas_upgrade_etl(cmd_tbl_t * cmdtp, int flag,
				int argc, char *const argv[])
{
	ulong loadaddr;
	size_t size;
	int ret;

	if (sas_upgrade_check_forced(argc, argv)) {
		argc--;
		argv++;
	} else {
		ret = sas_confirm("Caution: this can damage your board");
		if (!ret)
			return 0;
	}

	ret = sas_upgrade_image_load(cmdtp, argc, argv, SAS_TYPELABEL_BIN,
					&loadaddr, &size);
	if (ret)
		return ret;

	ret = sas_etl_import(loadaddr);
	if (ret)
		return 1;

	sas_flash_verbose_set(1);
	ret = sas_etl_flash_write(loadaddr);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

U_BOOT_CMD(sas_upgrade_etl, 4, 0, do_sas_upgrade_etl,
	"Update ETL in flash", "[-f] [addr size]\n");

static int do_sas_erase_etl(cmd_tbl_t * cmdtp, int flag,
				int argc, char *const argv[])
{
	int ret;

	if (!sas_upgrade_check_forced(argc, argv)) {
		ret = sas_confirm("Caution: this can damage your board");
		if (!ret)
			return 0;
	}

	sas_flash_verbose_set(1);
	ret = sas_etl_flash_erase();
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

U_BOOT_CMD(sas_erase_etl, 2, 0, do_sas_erase_etl,
	"Erase ETL in flash", "[-f]");

static __maybe_unused int do_sas_erase_uboot_cfg(cmd_tbl_t * cmdtp, int flag,
					int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	int ret;

	part = sas_flash_part_find(SAS_PART_UBOOT_CFG);
	if (!part)
		return 1;

	sas_flash_verbose_set(1);
	ret = sas_flash_unlock(part, 0, part->size);
	if (ret)
		return 1;

	ret = sas_flash_erase(part, 0, part->size);

	sas_flash_lock(part, 0, part->size);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

static __maybe_unused int do_sas_erase_uboot_cfg_ubi(cmd_tbl_t * cmdtp, int flag,
					int argc, char *const argv[])
{
	int ret;

	sas_flash_verbose_set(1);
	ret = sas_ubi_volume_truncate(SAS_UBI_UBOOT_ENV);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

#if !defined(CONFIG_UART_BOOT)
#if defined(CONFIG_SPHAIRON_UBI_SUPPORT)
U_BOOT_CMD(sas_erase_uboot_cfg, 1, 0, do_sas_erase_uboot_cfg_ubi,
	"Truncate U-Boot config UBI volume", "");
#else
U_BOOT_CMD(sas_erase_uboot_cfg, 1, 0, do_sas_erase_uboot_cfg,
	"Erase U-Boot config in flash", "");
#endif
#endif

static void sas_upgrade_index(int argc, char *const argv[], int *index)
{
	int ret;
	ulong val;

	if (argc == 1) {
		*index = 0;
		return;
	}

	ret = strict_strtoul(argv[1], 10, &val);
	if (ret) {
		*index = -1;
		return;
	}

	*index = val - 1;
}

static __maybe_unused int do_sas_upgrade_platform(cmd_tbl_t * cmdtp, int flag,
					int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	int index = 0, ret;
	ulong uimage_srcaddr, uimage_dstaddr;
	ulong rootfs_srcaddr, rootfs_dstaddr;
	size_t uimage_size, rootfs_size, erase_len;

	sas_upgrade_index(argc, argv, &index);
	part = sas_flash_layout_image_partition(index);
	if (!part) {
		puts("Invalid index or partition\n");
		return 1;
	}

	debug("using partition %s\n", part->mtd->name);

	ret = sas_upgrade_images_load(SAS_KERNEL_IMAGE, &uimage_srcaddr,
					&uimage_size, SAS_ROOTFS_IMAGE,
					&rootfs_srcaddr, &rootfs_size);
	if (ret)
		return ret;

	ret = sas_upgrade_image_check(uimage_srcaddr, SAS_IMG_KERNEL);
	if (!ret)
		return 1;

	ret = sas_upgrade_image_check(rootfs_srcaddr, SAS_IMG_ROOTFS);
	if (!ret)
		return 1;

	ret = sas_boot_layout_platform(part, uimage_size, rootfs_size,
					&uimage_dstaddr, &rootfs_dstaddr,
					&erase_len);
	if (ret)
		return 1;

	sas_boot_invalidate_image_state(index + 1);

	ret = sas_boot_invalidate_platform_images(part);
	if (ret)
		return 1;

	sas_flash_verbose_set(1);

	ret = sas_flash_complete_write(part, uimage_dstaddr, uimage_size,
					erase_len,
					(const void *) uimage_srcaddr, 0);
	if (ret)
		goto done;

	ret = sas_flash_write(part, rootfs_dstaddr, rootfs_size,
				(const void *) rootfs_srcaddr);

done:
	sas_flash_verbose_set(0);
	ret = sas_boot_scan_images(NULL);

	return ret ? 1 : 0;
}

#if !defined(CONFIG_SPHAIRON_UBI_SUPPORT) && !defined(CONFIG_UART_BOOT)
U_BOOT_CMD(sas_upgrade_platform, 2, 0, do_sas_upgrade_platform,
	"Update kernel and rootfs in flash", "[index]");
#endif

static __maybe_unused int do_sas_upgrade_service(cmd_tbl_t * cmdtp, int flag,
					int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	int index = 0, ret;
	ulong servicefs_srcaddr, servicefs_dstaddr;
	ulong configfs_srcaddr, configfs_dstaddr;
	size_t servicefs_size, configfs_size, erase_len;

	sas_upgrade_index(argc, argv, &index);
	part = sas_flash_layout_image_partition(index);
	if (!part) {
		puts("Invalid index or partition\n");
		return 1;
	}

	debug("using partition %s\n", part->mtd->name);

	ret = sas_upgrade_images_load(SAS_SERVICEFS_IMAGE, &servicefs_srcaddr,
					&servicefs_size, SAS_CONFIGFS_IMAGE,
					&configfs_srcaddr, &configfs_size);
	if (ret)
		return ret;

	ret = sas_upgrade_image_check(servicefs_srcaddr, SAS_IMG_SERVICEFS);
	if (!ret)
		return 1;

	ret = sas_upgrade_image_check(configfs_srcaddr, SAS_IMG_DEFCONFIG);
	if (!ret)
		return 1;

	ret = sas_boot_layout_service(part, servicefs_size, configfs_size,
					&servicefs_dstaddr, &configfs_dstaddr,
					&erase_len);
	if (ret)
		return 1;

	sas_boot_invalidate_image_state(index + 1);

	ret = sas_boot_invalidate_service_images(part);
	if (ret)
		return 1;

	sas_flash_verbose_set(1);

	ret = sas_flash_complete_write(part, servicefs_dstaddr, servicefs_size,
					erase_len,
					(const void *) servicefs_srcaddr, 0);
	if (ret)
		goto done;

	ret = sas_flash_write(part, configfs_dstaddr, configfs_size,
				(const void *) configfs_srcaddr);

done:
	sas_flash_verbose_set(0);
	ret = sas_boot_scan_images(NULL);

	return ret ? 1 : 0;
}

#if !defined(CONFIG_SPHAIRON_UBI_SUPPORT) && !defined(CONFIG_UART_BOOT)
U_BOOT_CMD(sas_upgrade_service, 2, 0, do_sas_upgrade_service,
	"Update servicefs and defconfig in flash", "[index]");
#endif

static __maybe_unused int
do_sas_upgrade_platform_ubi(cmd_tbl_t * cmdtp, int flag, int argc,
				char *const argv[])
{
	int index = 0, ret;
	ulong uimage_srcaddr, rootfs_srcaddr;
	size_t uimage_size, rootfs_size;
	enum sas_ubi_volume_type kernel_vol, rootfs_vol;

	sas_upgrade_index(argc, argv, &index);

	if (index) {
		kernel_vol = SAS_UBI_KERNEL2;
		rootfs_vol = SAS_UBI_ROOTFS2;
	} else {
		kernel_vol = SAS_UBI_KERNEL1;
		rootfs_vol = SAS_UBI_ROOTFS1;
	}

	ret = sas_upgrade_images_load(SAS_KERNEL_IMAGE, &uimage_srcaddr,
					&uimage_size, SAS_ROOTFS_IMAGE,
					&rootfs_srcaddr, &rootfs_size);
	if (ret)
		return ret;

	ret = sas_upgrade_image_check(uimage_srcaddr, SAS_IMG_KERNEL);
	if (!ret)
		return 1;

	ret = sas_upgrade_image_check(rootfs_srcaddr, SAS_IMG_ROOTFS);
	if (!ret)
		return 1;

	sas_boot_invalidate_image_state(index + 1);
	sas_flash_verbose_set(1);

	ret = sas_ubi_volume_write(kernel_vol, (const void *)uimage_srcaddr,
		uimage_size);
	if (ret)
		goto done;

	ret = sas_ubi_volume_write(rootfs_vol, (const void *)(rootfs_srcaddr +
		sas_image_hdr_size()), rootfs_size);
	if (ret)
		goto done;

done:
	sas_flash_verbose_set(0);
	ret = sas_boot_scan_images(NULL);

	return ret ? 1 : 0;
}

#if defined(CONFIG_SPHAIRON_UBI_SUPPORT) && !defined(CONFIG_UART_BOOT)
U_BOOT_CMD(sas_upgrade_platform, 2, 0, do_sas_upgrade_platform_ubi,
	"Update kernel and rootfs in UBI volumes", "[index]");
#endif

static __maybe_unused int
do_sas_upgrade_ubi(cmd_tbl_t * cmdtp, int flag, int argc,
				char *const argv[])
{
	struct sas_flash_partition *part;
	ulong loadaddr;
	size_t size;
	int ret;

	part = sas_flash_part_find(SAS_PART_UBI);
	if (!part)
		return 1;

	ret = sas_upgrade_image_load(cmdtp, argc, argv, SAS_UBI_IMAGE,
					&loadaddr, &size);
	if (ret)
		return ret;

	sas_boot_invalidate_image_state(1);
	sas_boot_invalidate_image_state(2);
	ubi_detach();
	sas_flash_verbose_set(1);

	ret = sas_flash_complete_write(part, 0, size, part->size,
		(const void *) loadaddr, 0);

	sas_flash_verbose_set(0);
	if (ret)
		return 1;

	ret = ubi_part(part->mtd->name, NULL);
	if (ret)
		return 1;

	ret = sas_boot_scan_images(NULL);

	return ret ? 1 : 0;
}

#if defined(CONFIG_SPHAIRON_UBI_SUPPORT) && !defined(CONFIG_UART_BOOT)
U_BOOT_CMD(sas_upgrade_ubi, 1, 0, do_sas_upgrade_ubi,
	"Update kernel and rootfs via UBI image", "");
#endif

static __maybe_unused int do_sas_erase_syscfg(cmd_tbl_t * cmdtp, int flag,
				int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	enum sas_flash_part_type part_type;
	int index = 0, ret;

	sas_upgrade_index(argc, argv, &index);

	switch (index) {
	case 0:
		part_type = SAS_PART_SYSCFG1;
		break;
	case 1:
		part_type = SAS_PART_SYSCFG2;
		break;
	default:
		puts("Invalid index\n");
		return 1;
	}

	part = sas_flash_part_find(part_type);
	if (!part)
		return 1;

	sas_flash_verbose_set(1);
	ret = sas_flash_erase(part, 0, part->size);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

#if !defined(CONFIG_SPHAIRON_UBI_SUPPORT) && !defined(CONFIG_UART_BOOT)
U_BOOT_CMD(sas_erase_syscfg, 2, 0, do_sas_erase_syscfg,
	"Erase sysconfig in flash", "[index]");
#endif

static __maybe_unused int do_sas_erase_images(cmd_tbl_t * cmdtp, int flag,
				int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	enum sas_flash_part_type part_type;
	int index = 0, ret;

	sas_upgrade_index(argc, argv, &index);

	switch (index) {
	case 0:
		part_type = SAS_PART_IMAGES1;
		break;
	case 1:
		part_type = SAS_PART_IMAGES2;
		break;
	default:
		puts("Invalid index\n");
		return 1;
	}

	part = sas_flash_part_find(part_type);
	if (!part)
		return 1;

	sas_flash_verbose_set(1);
	ret = sas_flash_erase(part, 0, part->size);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

static __maybe_unused int do_sas_erase_images_ubi(cmd_tbl_t * cmdtp, int flag,
				int argc, char *const argv[])
{
	int index = 0, ret;
	enum sas_ubi_volume_type kernel_vol, rootfs_vol;

	sas_upgrade_index(argc, argv, &index);

	if (index) {
		kernel_vol = SAS_UBI_KERNEL2;
		rootfs_vol = SAS_UBI_ROOTFS2;
	} else {
		kernel_vol = SAS_UBI_KERNEL1;
		rootfs_vol = SAS_UBI_ROOTFS1;
	}

	sas_flash_verbose_set(1);
	ret = sas_ubi_volume_truncate(kernel_vol);
	ret |= sas_ubi_volume_truncate(rootfs_vol);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

#if !defined(CONFIG_UART_BOOT)
#if defined(CONFIG_SPHAIRON_UBI_SUPPORT)
U_BOOT_CMD(sas_erase_images, 2, 0, do_sas_erase_images_ubi,
	"Truncate image UBI volumes", "[index]");
#else
U_BOOT_CMD(sas_erase_images, 2, 0, do_sas_erase_images,
	"Erase images partition in flash", "[index]");
#endif
#endif

static __maybe_unused int do_sas_erase_data(cmd_tbl_t * cmdtp, int flag,
				int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	int ret;

	part = sas_flash_part_find(SAS_PART_DATA);
	if (!part)
		return 1;

	sas_flash_verbose_set(1);
	ret = sas_flash_erase(part, 0, part->size);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

static __maybe_unused int do_sas_erase_data_ubi(cmd_tbl_t * cmdtp, int flag,
					int argc, char *const argv[])
{
	int ret;

	sas_flash_verbose_set(1);
	ret = sas_ubi_volume_truncate(SAS_UBI_CONFIG);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

#if !defined(CONFIG_UART_BOOT)
#if defined(CONFIG_SPHAIRON_UBI_SUPPORT)
U_BOOT_CMD(sas_erase_data, 1, 0, do_sas_erase_data_ubi,
	"Truncate data UBI volume", "");
#else
U_BOOT_CMD(sas_erase_data, 1, 0, do_sas_erase_data,
	"Erase data partition in flash", "");
#endif
#endif

static __maybe_unused int do_sas_erase_ubi(cmd_tbl_t * cmdtp, int flag,
				int argc, char *const argv[])
{
	struct sas_flash_partition *part;
	int ret;

	part = sas_flash_part_find(SAS_PART_UBI);
	if (!part)
		return 1;

	sas_boot_invalidate_image_state(1);
	sas_boot_invalidate_image_state(2);
	ubi_detach();

	sas_flash_verbose_set(1);
	ret = sas_flash_erase(part, 0, part->size);
	sas_flash_verbose_set(0);

	return ret ? 1 : 0;
}

#if defined(CONFIG_SPHAIRON_UBI_SUPPORT)
U_BOOT_CMD(sas_erase_ubi, 1, 0, do_sas_erase_ubi,
	"Erase UBI partition in flash", "");
#endif
