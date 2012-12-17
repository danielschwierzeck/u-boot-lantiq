/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <netdev.h>
#include <miiphy.h>
#include <switch.h>

static struct list_head switch_drivers;
static struct list_head switch_devices;

void switch_init(void)
{
	INIT_LIST_HEAD(&switch_drivers);
	INIT_LIST_HEAD(&switch_devices);

#if defined(CONFIG_SWITCH_PSB697X)
	switch_psb697x_init();
#endif
#if defined(CONFIG_SWITCH_ADM6996I)
	switch_adm6996i_init();
#endif
#if defined(CONFIG_SWITCH_AR8216)
	switch_ar8216_init();
#endif
#if defined(CONFIG_SWITCH_RTL8306)
	switch_rtl8306_init();
#endif

	board_switch_init();
}

void switch_driver_register(struct switch_driver *drv)
{
	INIT_LIST_HEAD(&drv->list);
	list_add_tail(&drv->list, &switch_drivers);
}

int switch_device_register(struct switch_device *dev)
{
	struct switch_driver *drv;

	/* Add switch device only, if an adequate driver is registered */
	list_for_each_entry(drv, &switch_drivers, list) {
		if (!strcmp(drv->name, dev->name)) {
			dev->drv = drv;

			INIT_LIST_HEAD(&dev->list);
			list_add_tail(&dev->list, &switch_devices);

			return 0;
		}
	}

	return -1;
}

struct switch_device *switch_connect(struct mii_dev *bus)
{
	struct switch_device *sw;
	int err;

	list_for_each_entry(sw, &switch_devices, list) {
		sw->bus = bus;

		err = sw->drv->probe(sw);
		if (!err)
			return sw;
	}

	return NULL;
}
