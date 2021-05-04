/*
 *                 Copyright Aquantia Corporation
 *
 *
 * Copyright (c) 2019, Intel Corporation.
 *
 * Aquantia Phy Boot via MDIO
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <console.h>
#include <command.h>
#include <asm/gpio.h>
#include <errno.h>
#include <dm.h>
#include <miiphy.h>
#include <phy.h>
#include <crc.h>

#define AQ_MDIO_BUS_NAME "mdio1"
#define PHY_ADDR 0x0
#define AQ_PHY_IMG_HEADER_OFFSET 0x300
#define AQ_IRAM_BASE_ADDRESS 0x40000000
#define AQ_DRAM_BASE_ADDRESS 0x3FFE0000
#define AQ_IRAM_LOADMODE	0
#define AQ_DRAM_LOADMODE	1

#define PHY_ID_AQR107   0x03a1b4e0
#define PHY_ID_AQR113C  0x31c31c10

#define AQ_MDIO_AN_VENDOR_1 0xC400
#define AQ_MDIO_AN_VENDOR_1_ADV1G 0x8000

#define ERR_MDIO_NO_DEVICE  1
#define ERR_MDIO_READ_FAIL  2
#define ERR_MDIO_WRITE_FAIL 3
#define ERR_CRC16_CHECK_FAIL 4
#define ERR_UNKNOWN_LOADMODE 5
#define ERR_GPIO_NUMBER_INVALID 6

static int aquantia_detect(struct mii_dev *mdio_bus)
{
	int phy_id = 0;

	phy_id = mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0x2) << 16;
	if (phy_id < 0)
		return phy_id;

	phy_id |= mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0x3);
	if (phy_id < 0)
		return phy_id;

	if ((phy_id & 0xFFFFFFF0) == (PHY_ID_AQR107 & 0xFFFFFFF0))
		printf("PHY : AQR 107\n");
	else if ((phy_id & 0xFFFFFFF0) == (PHY_ID_AQR113C & 0xFFFFFFF0))
		printf("PHY : AQR 113C\n");
	else
		printf("PHY ID [0x%X] not supported\n", phy_id);

	return 0;
}

static int dump_phy_info(struct mii_dev *mdio_bus)
{
	int reg = 0x0;
	int res = 0x0;

	printf("Dump Information :\n");
	reg = mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0x20);
	if (reg < 0)
		return reg;

	printf("Current Revision : 0x%x\n", reg);
	res = aquantia_detect(mdio_bus);
	if (res < 0)
		return res;

	mdelay(2000);

	return 0;
}

static int aquantia_backup_ggp1(struct mii_dev *mdio_bus, u16 *ggp1value)
{
	*ggp1value = mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0xC441);
	if (*ggp1value < 0)
		return *ggp1value;

	return 0;
}

static int check_image(u8 *image, unsigned int size)
{
	u16 crc16calculated = 0x0000;
	u16 filecrc;

	filecrc = image[size - 2] << 8 | image[size - 1];

	crc16calculated = crc16_ccitt(crc16calculated, image, size - 2);

	if (crc16calculated != filecrc) {
		printf("CRC check failed (expected 0x%X, found 0x%X)\n",
					filecrc, crc16calculated);
		return -ERR_CRC16_CHECK_FAIL;
	}

	printf("CRC check good on image file (0x%04X)\n", crc16calculated);
	return 0;
}

static int aquantia_enable_boot_load_mode(struct mii_dev *mdio_bus,
				unsigned int provisioningaddress)
{
	int reg = 0x0;
	int newreg = 0x0;
	int res = 0;

	reg =  mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0xC452);
	if (reg < 0)
		return reg;

	newreg = reg | 0x1;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC452, newreg);
	if (res < 0)
		return res;

	reg = mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0xC471);
	if (reg < 0)
		return reg;

	newreg = reg | provisioningaddress | 0x40;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC471, newreg);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_enable_gang_load_mode(struct mii_dev *mdio_bus,
				unsigned int gangloadaddress)
{
	int reg = 0x0;
	int newreg = 0x0;
	int res = 0;

	reg = mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0xC447);
	if (reg < 0)
		return reg;

	newreg = (reg & 0xFF00) | gangloadaddress;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC447, newreg);
	if (res < 0)
		return res;

	reg =  mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0xC441);
	if (reg < 0)
		return reg;

	newreg = reg | 0x4000;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC441, newreg);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_disable_gang_load_mode(struct mii_dev *mdio_bus,
				u16 ggp1value)
{
	int reg = 0x0;
	int res = 0;

	reg = mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0xC441);
	if (reg < 0)
		return reg;

	reg = ggp1value & 0xBFFFF;
	mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC441, reg);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_stall_up(struct mii_dev *mdio_bus)
{
	int reg = 0x0;
	int newreg = 0x0;
	int res = 0;

	reg =  mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0xC001);
	if (reg < 0)
		return reg;

	newreg = reg | 0x0041;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC001, newreg);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_release_up(struct mii_dev *mdio_bus)
{
	int res = 0;

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC001, 0x0041);
	if (res < 0)
		return res;

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC001, 0x8041);
	if (res < 0)
		return res;

	udelay(200);
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0xC001, 0x0040);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_mailbox_clear_crc(struct mii_dev *mdio_bus)
{
	int reg = 0x0;
	int newreg = 0x0;
	int res = 0;

	reg =  mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0x200);
	if (reg < 0)
		return reg;

	newreg = reg | 0x1000;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x200, newreg);
	if (res < 0)
		return res;

	newreg = reg & 0xEFFF;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x200, newreg);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_mailbox_init(struct mii_dev *mdio_bus, u16 *mailboxwrite)
{
	int reg = 0x0;
	int newreg = 0x0;

	reg =  mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0x200);
	if (reg < 0)
		return reg;

	newreg = reg | 0xC000;
	*mailboxwrite = newreg;

	return 0;
}

static int aquantia_segment_read(int mode, u8 *image,
				u32 *primaryramptr, u32 *primaryramsize)
{
	u32 priheadptr = 0x00000000;
	int res = 0;

	priheadptr = (((image[0x9] & 0x0F) << 8) | image[0x8]) << 12;
	*primaryramptr = 0x00000000;
	*primaryramsize = 0x00000000;
	switch (mode) {
	case 0:
		*primaryramptr =
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0x4 + 2] << 16) |
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0x4 + 1] << 8) |
		image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0x4];

		*primaryramsize =
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0x7 + 2] << 16) |
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0x7 + 1] << 8) |
		image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0x7];

		*primaryramptr += priheadptr;
		break;
	case 1:
		*primaryramptr =
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0xa + 2] << 16) |
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0xa + 1] << 8) |
		image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0xa];

		*primaryramsize =
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0xd + 2] << 16) |
		(image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0xd + 1] << 8) |
		image[priheadptr + AQ_PHY_IMG_HEADER_OFFSET + 0xd];

		*primaryramptr += priheadptr;
		break;
	default:
		printf("\nUnknown Mode [0 : IRAM | 1 : DRAM]\n");
		res = -ERR_UNKNOWN_LOADMODE;
	}

	return res;
}

static void aquantia_update_crc(u32 lsw, u32 msw, u16 *crc16calculated)
{
	u8 imgdata;
	u16 cksum;

	cksum = *crc16calculated;
	imgdata = msw >> 8;
	*crc16calculated = crc16_ccitt(cksum, &imgdata, 1);

	cksum = *crc16calculated;
	imgdata = msw & 0xFF;
	*crc16calculated = crc16_ccitt(cksum, &imgdata, 1);

	cksum = *crc16calculated;
	imgdata = lsw >> 8;
	*crc16calculated = crc16_ccitt(cksum, &imgdata, 1);

	cksum = *crc16calculated;
	imgdata = lsw & 0xFF;
	*crc16calculated = crc16_ccitt(cksum, &imgdata, 1);
}

static int aquantia_mailbox_write(struct mii_dev *mdio_bus,
				u32 lsw, u32 msw, u16 mailboxwrite)
{
	int res = 0;

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x204, msw & 0xFFFF);
	if (res < 0)
		return res;

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x205, lsw & 0xFFFF);
	if (res < 0)
		return res;

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x200, mailboxwrite);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_firmware_load(struct mii_dev *mdio_bus, int mode, u8 *image,
					u16 *crc16calculated, u16 mailboxwrite)
{
	u16 msw = 0x0;
	u16 lsw = 0x0;
	u32 bytesize = 0x0;
	u32 dwordsize = 0x0;
	u32 bytepointer = 0x0;
	int i = 0;
	u32 primramptr = 0x00000000;
	u32 primramsize = 0x00000000;
	int res = 0;

	res = aquantia_segment_read(mode, image, &primramptr, &primramsize);
	if (res < 0)
		return res;

	bytesize = primramsize;
	dwordsize = bytesize >> 2;
	bytepointer = primramptr;

	*crc16calculated = 0x0;

	res = aquantia_mailbox_clear_crc(mdio_bus);
	if (res < 0)
		return res;

	switch (mode) {
	case 0:
		msw = (u16)(AQ_IRAM_BASE_ADDRESS >> 16);
		lsw = (u16)((AQ_IRAM_BASE_ADDRESS & 0xFFFF) >> 2);
		printf("Loading IRAM: Size %d", dwordsize);
		break;
	case 1:
		msw = (u16)(AQ_DRAM_BASE_ADDRESS >> 16);
		lsw = (u16)((AQ_DRAM_BASE_ADDRESS & 0xFFFF) >> 2);
		printf("\nLoading DRAM: Size %d", dwordsize);
		break;
	default:
		printf("\nUnknown Mode [0 : IRAM | 1 : DRAM]\n");
	}

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x202, msw);
	if (res < 0)
		return res;

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x203, lsw);
	if (res < 0)
		return res;

	for (i = 0; i < dwordsize; i++) {
		lsw = image[bytepointer] | (image[bytepointer + 1] << 8);
		msw = image[bytepointer + 2] | (image[bytepointer + 3] << 8);
		bytepointer += 4;
		res = aquantia_mailbox_write(mdio_bus, lsw, msw, mailboxwrite);
		if (res < 0)
			return res;

		aquantia_update_crc(lsw, msw, crc16calculated);
		if (i && ((i % 512) == 0))
			printf(".");
	}

	lsw = 0x0;
	msw = 0x0;
	switch (bytesize & 0x3) {
	case 0x1:
		/* write first byte of data */
		lsw = image[bytepointer];
		bytepointer += 1;
	case 0x2:
		/* write second byte of data */
		lsw = image[bytepointer];
		bytepointer += 1;
		lsw |= image[bytepointer] << 8;
		bytepointer += 1;
	case 0x3:
		/* write third byte of data */
		lsw = image[bytepointer];
		bytepointer += 1;
		lsw |= image[bytepointer] << 8;
		bytepointer += 1;
		msw = image[bytepointer];
		bytepointer += 1;
	default:
		/* write mailbox */
		res = aquantia_mailbox_write(mdio_bus, lsw, msw, mailboxwrite);
		if (res < 0)
			return res;

		aquantia_update_crc(lsw, msw, crc16calculated);
		break;
	}

	return 0;
}

static int check_mailbox_crc(struct mii_dev *mdio_bus, u16 crc16calculated)
{
	int mailboxcrc = 0x0;
	int res = 0;

	mailboxcrc = mdio_bus->read(mdio_bus, PHY_ADDR, 0x1E, 0x201);
	if (mailboxcrc != crc16calculated) {
		printf("\nMailbox CRC-16 (0x%X) not match calculated(0x%X)\n",
			mailboxcrc, crc16calculated);
		res = -ERR_CRC16_CHECK_FAIL;
	} else
		printf("\nImage load good - mailbox CRC-16 matches (0x%X)\n",
			mailboxcrc);

	return res;
}

static int aquantia_clear_reset(struct mii_dev *mdio_bus)
{
	int res = 0;

	res = mdio_bus->write(mdio_bus, PHY_ADDR, 0x1E, 0x0, 0x0000);
	if (res < 0)
		return res;

	return 0;
}

static int aquantia_gphy_config(struct mii_dev *mdio_bus)
{
	int reg = 0x0;
	int newreg = 0x0;
	int res = 0;

	reg = mdio_bus->read(mdio_bus,
				PHY_ADDR, MDIO_MMD_AN, MDIO_AN_ADVERTISE);
	if (reg < 0)
		return reg;

	newreg &= ~(ADVERTISE_ALL | ADVERTISE_100BASE4 | ADVERTISE_PAUSE_CAP |
							ADVERTISE_PAUSE_ASYM);
	if (reg != newreg) {
		res = mdio_bus->write(mdio_bus, PHY_ADDR, MDIO_MMD_AN,
						MDIO_AN_ADVERTISE, newreg);
		if (res < 0)
			return res;
	}

	/* Configure gigabit */
	reg = mdio_bus->read(mdio_bus, PHY_ADDR, MDIO_MMD_AN,
				AQ_MDIO_AN_VENDOR_1);
	if (reg < 0)
		return reg;

	newreg = reg | AQ_MDIO_AN_VENDOR_1_ADV1G;
	if (reg != newreg) {
		res = mdio_bus->write(mdio_bus, PHY_ADDR, MDIO_MMD_AN,
						AQ_MDIO_AN_VENDOR_1, newreg);
		if (res < 0)
			return res;
	}

	/* Configure 10Gigabit */
	reg = mdio_bus->read(mdio_bus,
				PHY_ADDR, MDIO_MMD_AN, MDIO_AN_10GBT_CTRL);
	if (reg < 0)
		return reg;

	newreg = reg | MDIO_AN_10GBT_CTRL_ADV10G;
	if (reg != newreg) {
		res = mdio_bus->write(mdio_bus, PHY_ADDR, MDIO_MMD_AN,
						MDIO_AN_10GBT_CTRL, newreg);
		if (res < 0)
			return res;
	}

	/* Restart Autonegtiation */
	reg = mdio_bus->read(mdio_bus,
					PHY_ADDR, MDIO_MMD_AN, MDIO_CTRL1);
	if (reg < 0)
		return reg;

	reg |= MDIO_AN_CTRL1_ENABLE | MDIO_AN_CTRL1_RESTART;
	res = mdio_bus->write(mdio_bus, PHY_ADDR, MDIO_MMD_AN, MDIO_CTRL1, reg);
		if (res < 0)
			return res;

	return 0;
}

static int do_aqc(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned int firmware_addr = 0x0;
	unsigned int firmware_size = 0x0;
	struct mii_dev *mdio_bus;
	u8 *image = 0x0;
	u16 crc16calculated = 0x0000;
	unsigned int provisioningaddress = 0x0;
	unsigned int gangloadaddress = 0x01;
	u16 ggp1value = 0x0;
	u16 mailboxwrite = 0x0;
	int res = 0;

	if (argc < 3)
		return CMD_RET_USAGE;

	firmware_addr = simple_strtol(argv[1], NULL, 16);
	firmware_size = simple_strtol(argv[2], NULL, 16);
	printf("Firmware Address [0x%x] Size [0x%x]\n",
		firmware_addr, firmware_size);

	mdio_bus = miiphy_get_dev_by_name(AQ_MDIO_BUS_NAME);
	if (mdio_bus == NULL)
		return -ERR_MDIO_NO_DEVICE;

	if (miiphy_set_current_dev(mdio_bus->name))
		return -ERR_MDIO_NO_DEVICE;

	res = dump_phy_info(mdio_bus);
	if (res < 0)
		return res;

	image = (u8 *)firmware_addr;
	res = check_image(image, firmware_size);
	if (res < 0) {
		printf("Image Check failed\n");
		return res;
	}

	res = aquantia_backup_ggp1(mdio_bus, &ggp1value);
	if (res < 0)
		return res;

	res = aquantia_enable_boot_load_mode(mdio_bus, provisioningaddress);
	if (res < 0)
		return res;

	res = aquantia_enable_gang_load_mode(mdio_bus, gangloadaddress);
	if (res < 0)
		return res;

	res = aquantia_stall_up(mdio_bus);
	if (res < 0)
		return res;

	res = aquantia_mailbox_init(mdio_bus, &mailboxwrite);
	if (res < 0)
		return res;

	res = aquantia_firmware_load(mdio_bus, AQ_IRAM_LOADMODE, image,
					&crc16calculated, mailboxwrite);
	if (res < 0)
		return res;

	res = check_mailbox_crc(mdio_bus, crc16calculated);
	if (res < 0)
		return res;

	res = aquantia_firmware_load(mdio_bus, AQ_DRAM_LOADMODE, image,
					&crc16calculated, mailboxwrite);
	if (res < 0)
		return res;

	res = aquantia_disable_gang_load_mode(mdio_bus, ggp1value);
	if (res < 0)
		return res;

	res = check_mailbox_crc(mdio_bus, crc16calculated);
	if (res < 0)
		return res;

	res = aquantia_clear_reset(mdio_bus);
	if (res < 0)
		return res;

	res = aquantia_release_up(mdio_bus);
	if (res < 0)
		return res;

	res = aquantia_gphy_config(mdio_bus);
	if (res < 0)
		return res;

	printf("Done\n");

	return 0;
}

U_BOOT_CMD(
	aqc,    3,    0,     do_aqc,
	"Aquantia Phy boot from MDIO",
	"aqc <load addr> <size>\n"
);
