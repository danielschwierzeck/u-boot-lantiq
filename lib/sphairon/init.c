// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <linux/err.h>
#include <linux/list.h>
#include <linux/mtd/mtd.h>

#include <sas/init.h>
#include <sas/util.h>
#include <sas/flash.h>
#include <sas/flashlayout.h>
#include <sas/etl.h>
#include <sas/zyclip.h>
#include <sas/boot.h>
#include <sas/controlfile.h>

#if defined(CONFIG_UART_BOOT)
#define init_flash_layout	0
#define init_flash_minimal	1
#define init_flash_etl		0
#else
#define init_flash_layout	1
#define init_flash_minimal	0
#define init_flash_etl		1
#endif

#if defined(CONFIG_SPHAIRON_ZYCLIP)
#undef init_flash_etl
#define init_flash_etl		0
#define init_flash_zyclip	1
#else
#define init_flash_zyclip	0
#endif

DECLARE_GLOBAL_DATA_PTR;

static bool early_init;

__weak int sas_board_init_f(void)
{
	return 0;
}

__weak int sas_board_early_init_r(void)
{
	return 0;
}

__weak int sas_board_late_init_r(void)
{
	return 0;
}

int sas_init_f(void)
{
	int ret;

	ret = sas_board_init_f();
	if (ret)
		return ret;

	return 0;
}

static void sas_init_error(void)
{
	puts("Failed to initialize Sphairon lib\n");
	setenv("bootcmd", NULL);
}

int sas_early_init_r(void)
{
	int ret;

	printf("Reloc: addr 0x%08lx offset 0x%lx\n",
		gd->relocaddr, gd->reloc_off);

	sas_flash_init();
	sas_etl_init();

	ret = sas_flash_layout_static_init(init_flash_minimal);
	if (ret)
		goto err;

	if (init_flash_etl) {
		ret = sas_etl_load();
		if (ret)
			goto err;
	}

	if (init_flash_zyclip) {
		ret = sas_zyclip_init();
		if (ret)
			goto err;

		sas_zyclip_update_etl();
	}

	ret = sas_board_early_init_r();
	if (ret)
		goto err;

	early_init = true;

	return 0;
err:
	sas_init_error();

	return 0;
}

int sas_late_init_r(void)
{
	int ret;
	int save_env = 0;

	sas_boot_init();
	sas_flash_mtdids_init();

	if (init_flash_layout && early_init) {
		if (sas_etl_version()) {
			sas_etl_env_set_ethaddr(&save_env);

			if (sas_flash_ubi_support())
				ret = sas_flash_layout_ubi_init();
			else
				ret = sas_flash_layout_dynamic_init();

			if (ret)
				goto err;

			ret = sas_boot_scan_images(&save_env);
			if (ret)
				goto err;
		}

		sas_etl_print();
		sas_flash_layout_print();
		sas_boot_print();
	}

	ret = sas_board_late_init_r();
	if (ret)
		goto err;

	sas_cf_run();

	if (!sas_cf_is_active()) {
		if (sas_etl_version()) {
			setenv("bootcmd", "sas_boot");
			setenv("bootdelay", "3");
		} else
			setenv("bootcmd", NULL);
	}

	sas_setenv_num("sas_saveenv", save_env, NULL);

	return 0;

err:
	sas_init_error();

	return 0;
}
