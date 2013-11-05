/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <compiler.h>
#include <sys/stat.h>

enum image_types {
	IMAGE_NONE,
	IMAGE_SFSPL
};

/* Lantiq non-volatile bootstrap command IDs */
enum nvb_cmd_ids {
	NVB_CMD_DEBUG	= 0x11,
	NVB_CMD_REGCFG	= 0x22,
	NVB_CMD_IDWNLD	= 0x33,
	NVB_CMD_CDWNLD	= 0x44,
	NVB_CMD_DWNLD	= 0x55,
	NVB_CMD_IFCFG	= 0x66,
	NVB_CMD_START	= 0x77
};

/* Lantiq non-volatile bootstrap command flags */
enum nvb_cmd_flags {
	NVB_FLAG_START	= 1,
	NVB_FLAG_DEC	= (1 << 1),
	NVB_FLAG_DBG	= (1 << 2),
	NVB_FLAG_SDBG	= (1 << 3),
	NVB_FLAG_CFG0	= (1 << 4),
	NVB_FLAG_CFG1	= (1 << 5),
	NVB_FLAG_CFG2	= (1 << 6),
	NVB_FLAG_RST	= (1 << 7)
};

struct args {
	enum image_types type;
	__u32		entry_addr;
	const char	*uboot_bin;
	const char	*spl_bin;
	const char	*out_bin;
};

static void usage_msg(const char *name)
{
	fprintf(stderr, "%s: [-h] -t type -e entry-addr -u uboot-bin [-s spl-bin] -o out-bin\n",
		name);
	fprintf(stderr, " Image types:\n"
			"  sfspl  - SPL + [compressed] U-Boot for SPI flash\n");
}

static enum image_types parse_image_type(const char *type)
{
	if (!type)
		return IMAGE_NONE;

	if (!strncmp(type, "sfspl", 6))
		return IMAGE_SFSPL;

	return IMAGE_NONE;
}

static int parse_args(int argc, char *argv[], struct args *arg)
{
	int opt;

	memset(arg, 0, sizeof(*arg));

	while ((opt = getopt(argc, argv, "ht:e:u:s:o:")) != -1) {
		switch (opt) {
		case 'h':
			usage_msg(argv[0]);
			return 1;
		case 't':
			arg->type = parse_image_type(optarg);
			break;
		case 'e':
			arg->entry_addr = strtoul(optarg, NULL, 16);
			break;
		case 'u':
			arg->uboot_bin = optarg;
			break;
		case 's':
			arg->spl_bin = optarg;
			break;
		case 'o':
			arg->out_bin = optarg;
			break;
		default:
			fprintf(stderr, "Invalid option -%c\n", opt);
			goto parse_error;
		}
	}

	if (arg->type == IMAGE_NONE) {
		fprintf(stderr, "Invalid image type\n");
		goto parse_error;
	}

	if (!arg->uboot_bin) {
		fprintf(stderr, "Missing U-Boot binary\n");
		goto parse_error;
	}

	if (!arg->out_bin) {
		fprintf(stderr, "Missing output binary\n");
		goto parse_error;
	}

	if (arg->type == IMAGE_SFSPL && !arg->spl_bin) {
		fprintf(stderr, "Missing SPL binary\n");
		goto parse_error;
	}

	return 0;

parse_error:
	usage_msg(argv[0]);
	return -1;
}

static __u32 build_nvb_command(unsigned cmdid, unsigned cmdflags)
{
	__u32 cmd;
	__u16 tag;

	tag = (cmdid << 8) | cmdflags;
	cmd = (tag << 16) | (0xFFFF - tag);

	return cpu_to_be32(cmd);
}

static int write_header(int fd, const void *hdr, size_t size)
{
	ssize_t n;

	n = write(fd, hdr, size);
	if (n != size) {
		fprintf(stderr, "Cannot write header: %s\n",
			strerror(errno));
		return -1;
	}

	return 0;
}

static int write_nvb_dwnld_header(int fd, size_t size, __u32 addr)
{
	__u32 hdr[3];

	hdr[0] = build_nvb_command(NVB_CMD_DWNLD, NVB_FLAG_START |
					NVB_FLAG_SDBG);
	hdr[1] = cpu_to_be32(size + 4);
	hdr[2] = cpu_to_be32(addr);

	return write_header(fd, hdr, sizeof(hdr));
}

static int write_nvb_start_header(int fd, __u32 addr)
{
	__u32 hdr[3];

	hdr[0] = build_nvb_command(NVB_CMD_START, NVB_FLAG_SDBG);
	hdr[1] = cpu_to_be32(4);
	hdr[2] = cpu_to_be32(addr);

	return write_header(fd, hdr, sizeof(hdr));
}

static int open_input_bin(const char *name, void **ptr, size_t *size)
{
	struct stat sbuf;
	int ret, fd;

	fd = open(name, O_RDONLY | O_BINARY);
	if (0 > fd) {
		fprintf(stderr, "Cannot open %s: %s\n", name,
			strerror(errno));
		return -1;
	}

	ret = fstat(fd, &sbuf);
	if (0 > ret) {
		fprintf(stderr, "Cannot fstat %s: %s\n", name,
			strerror(errno));
		return -1;
	}

	*ptr = mmap(0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (*ptr == MAP_FAILED) {
		fprintf(stderr, "Cannot mmap %s: %s\n", name,
			strerror(errno));
		return -1;
	}

	*size = sbuf.st_size;

	return fd;
}

static void close_input_bin(int fd, void *ptr, size_t size)
{
	munmap(ptr, size);
	close(fd);
}

static int copy_bin(int fd, void *ptr, size_t size)
{
	ssize_t n;

	n = write(fd, ptr, size);
	if (n != size) {
		fprintf(stderr, "Cannot copy binary: %s\n", strerror(errno));
		return -1;
	}

	return 0;
}

static int open_output_bin(const char *name)
{
	int fd;

	fd = open(name, O_RDWR | O_CREAT | O_TRUNC | O_BINARY, 0666);
	if (0 > fd) {
		fprintf(stderr, "Cannot open %s: %s\n", name,
			strerror(errno));
		return -1;
	}

	return fd;
}

static int create_sfspl(const struct args *arg)
{
	int out_fd, uboot_fd, spl_fd, ret;
	void *uboot_ptr, *spl_ptr;
	size_t uboot_size, spl_size;

	out_fd = open_output_bin(arg->out_bin);
	if (0 > out_fd)
		goto err;

	spl_fd = open_input_bin(arg->spl_bin, &spl_ptr, &spl_size);
	if (0 > spl_fd)
		goto err_spl;

	uboot_fd = open_input_bin(arg->uboot_bin, &uboot_ptr, &uboot_size);
	if (0 > uboot_fd)
		goto err_uboot;

	ret = write_nvb_dwnld_header(out_fd, spl_size, arg->entry_addr);
	if (ret)
		goto err_write;

	ret = copy_bin(out_fd, spl_ptr, spl_size);
	if (ret)
		goto err_write;

	ret = write_nvb_start_header(out_fd, arg->entry_addr);
	if (ret)
		goto err_write;

	ret = copy_bin(out_fd, uboot_ptr, uboot_size);
	if (ret)
		goto err_write;

	close_input_bin(uboot_fd, uboot_ptr, uboot_size);
	close_input_bin(spl_fd, spl_ptr, spl_size);
	close(out_fd);

	return 0;

err_write:
	close_input_bin(uboot_fd, uboot_ptr, uboot_size);
err_uboot:
	close_input_bin(spl_fd, spl_ptr, spl_size);
err_spl:
	close(out_fd);
err:
	return -1;
}

int main(int argc, char *argv[])
{
	int ret;
	struct args arg;

	ret = parse_args(argc, argv, &arg);
	if (ret)
		goto done;

	switch (arg.type) {
	case IMAGE_SFSPL:
		ret = create_sfspl(&arg);
		break;
	default:
		fprintf(stderr, "Image type not implemented\n");
		ret = -1;
		break;
	}

done:
	if (ret >= 0)
		return EXIT_SUCCESS;

	return EXIT_FAILURE;
}
