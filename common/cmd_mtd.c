/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <asm/io.h>
#include <linux/err.h>
#include <linux/mtd/mtd.h>

enum {
	CMD_MTD_READ,
	CMD_MTD_WRITE,
	CMD_MTD_ERASE,
	CMD_MTD_LOCK,
	CMD_MTD_UNLOCK,
};

static int do_mtd_read_write(unsigned cmd, int argc, char * const argv[])
{
	struct mtd_info *mtd;
	char *endp, *mtdid;
	ulong addr;
	loff_t offset;
	void *buf;
	int ret;
	size_t len, retlen;

	if (argc < 4)
		return -1;

	mtdid = argv[2];
	mtd = get_mtd_device_nm(mtdid);
	if (IS_ERR(mtd)) {
		printf("invalid MTD device: %s\n", mtdid);
		return -1;
	}

	addr = simple_strtoul(argv[1], &endp, 16);
	if (*argv[1] == 0 || *endp != 0) {
		ret = -1;
		goto done;
	}

	offset = simple_strtoul(argv[3], &endp, 16);
	if (*argv[2] == 0 || *endp != 0) {
		ret = -1;
		goto done;
	}

	len = simple_strtoul(argv[4], &endp, 16);
	if (*argv[3] == 0 || *endp != 0) {
		ret = -1;
		goto done;
	}

	buf = map_physmem(addr, len, MAP_WRBACK);
	if (!buf) {
		ret = 1;
		goto done;
	}

	switch (cmd) {
	case CMD_MTD_READ:
		ret = mtd->_read(mtd, offset, len, &retlen, buf);
		break;
	case CMD_MTD_WRITE:
		ret = mtd->_write(mtd, offset, len, &retlen, buf);
		break;
	default:
		ret = -1;
	}

	unmap_physmem(buf, len);

done:
	put_mtd_device(mtd);

	return ret;
}

/*
 * Adopted from cmd_sf.c
 *
 * This function computes the length argument for the erase command.
 * The length on which the command is to operate can be given in two forms:
 * 1. <cmd> offset len  - operate on <'offset',  'len')
 * 2. <cmd> offset +len - operate on <'offset',  'round_up(len)')
 * If the second form is used and the length doesn't fall on the
 * sector boundary, than it will be adjusted to the next sector boundary.
 * If it isn't in the flash, the function will fail (return -1).
 * Input:
 *    arg: length specification (i.e. both command arguments)
 * Output:
 *    len: computed length for operation
 * Return:
 *    1: success
 *   -1: failure (bad format, bad address).
 */
static int mtd_parse_len_arg(struct mtd_info *mtd, const char *arg, uint64_t *len)
{
	char *ep;
	char round_up_len; /* indicates if the "+length" form used */
	uint64_t len_arg;

	round_up_len = 0;
	if (*arg == '+') {
		round_up_len = 1;
		++arg;
	}

	len_arg = simple_strtoul(arg, &ep, 16);
	if (ep == arg || *ep != 0)
		return -1;

	if (round_up_len && mtd->erasesize > 0)
		*len = ROUND(len_arg, mtd->erasesize);
	else
		*len = len_arg;

	return 0;
}

static int do_mtd_erase_lock_unlock(unsigned cmd, int argc, char * const argv[])
{
	struct mtd_info *mtd;
	struct erase_info instr;
	char *endp, *mtdid;
	int ret;

	if (argc < 3)
		return -1;

	mtdid = argv[1];
	mtd = get_mtd_device_nm(mtdid);
	if (IS_ERR(mtd)) {
		printf("invalid MTD device: %s\n", mtdid);
		return -1;
	}

	instr.addr = simple_strtoul(argv[2], &endp, 16);
	if (*argv[1] == 0 || *endp != 0) {
		ret = -1;
		goto done;
	}

	ret = mtd_parse_len_arg(mtd, argv[3], &instr.len);
	if (ret)
		goto done;

	switch (cmd) {
	case CMD_MTD_ERASE:
		instr.mtd = mtd;
		instr.callback = NULL;
		ret = mtd->_erase(mtd, &instr);
		break;
	case CMD_MTD_LOCK:
		ret = mtd->_lock(mtd, instr.addr, instr.len);
		break;
	case CMD_MTD_UNLOCK:
		ret = mtd->_unlock(mtd, instr.addr, instr.len);
		break;
	default:
		ret = -1;
	}

done:
	put_mtd_device(mtd);

	return ret;
}

static const char mtd_type_str[][12] = {
	"Absent",
	"RAM",
	"ROM",
	"NOR flash",
	"NAND flash",
	"DATA flash",
	"UBI volume"
};

static int do_mtd_info(int argc, char * const argv[])
{
	struct mtd_info *mtd;
	const char *str;

	mtd_for_each_device(mtd) {
		str = mtd_type_str[mtd->type];
		printf("%-16s - %s, ", mtd->name, str);
		print_size(mtd->size, "\n");
	}

	return 0;
}

static int do_mtd(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	const char *cmd;
	int ret;

	/* need at least two arguments */
	if (argc < 2)
		goto usage;

	cmd = argv[1];
	argc--;
	argv++;

	if (strcmp(cmd, "read") == 0)
		ret = do_mtd_read_write(CMD_MTD_READ, argc, argv);
	else if (strcmp(cmd, "write") == 0)
		ret = do_mtd_read_write(CMD_MTD_WRITE, argc, argv);
	else if (strcmp(cmd, "erase") == 0)
		ret = do_mtd_erase_lock_unlock(CMD_MTD_ERASE, argc, argv);
	else if (strcmp(cmd, "lock") == 0)
		ret = do_mtd_erase_lock_unlock(CMD_MTD_LOCK, argc, argv);
	else if (strcmp(cmd, "unlock") == 0)
		ret = do_mtd_erase_lock_unlock(CMD_MTD_UNLOCK, argc, argv);
	else if (strcmp(cmd, "info") == 0)
		ret = do_mtd_info(argc, argv);
	else
		ret = -1;

	if (ret != -1)
		return ret;

usage:
	return cmd_usage(cmdtp);
}

U_BOOT_CMD(
	mtd, 6, 0, do_mtd,
	"MTD sub-system",
	"info\n"
	"    - show available MTD devices\n"
	"mtd read addr mtdid offset len\n"
	"    - read 'len' bytes from MTD 'mtdid' starting at 'offset' "
		"to memory at 'addr'\n"
	"mtd write addr mtdid offset len\n"
	"    - write 'len' bytes from memory at 'addr' to MTD 'mtdid' "
		"at 'offset'\n"
	"mtd erase mtdid offset [+]len\n"
	"    - erase 'len' bytes in MTD 'mtdid' from 'offset'\n"
	"      +len' round up 'len' to MTD erase size\n"
	"mtd lock|unlock mtdid offset [+]len\n"
	"    - lock/unlock 'len' bytes in MTD 'mtdid' from 'offset'\n"
	"      +len' round up 'len' to MTD erase size"
);
