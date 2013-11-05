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
	IMAGE_SFSPL,
	IMAGE_NANDSPL,
	IMAGE_NORSPL,
	IMAGE_NANDHWSPL
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

#define HSNAND_SPL_SIZE		(32 * 1024)
#define roundup(x, y)		((((x) + ((y) - 1)) / (y)) * (y))

struct args {
	enum image_types type;
	__u32		entry_addr;
	loff_t		uboot_offset;
	loff_t		tpl_offset;
	size_t		uboot_size;
	unsigned int	page_size;
	unsigned int	eb_size;
	unsigned int	redund_images;
	bool		build_nvb;
	bool		spl_csum;
	bool		spl_swap;
	const char	*uboot_bin;
	const char	*spl_bin;
	const char	*tpl_bin;
	const char	*out_bin;
};

static void usage_msg(const char *name)
{
	fprintf(stderr, "%s: [-h] [-b] -t type -e entry-addr -x uboot-offset [-X tpl-offset] -U uboot-size [-p page-size] [-E eraseblock-size] [-r redund-images] -u uboot-bin [-s spl-bin] [-T spl-bin] -o out-bin\n",
		name);
	fprintf(stderr, " Image types:\n"
			"  sfspl     - SPL + [compressed] U-Boot for SPI flash\n"
			"  nandspl   - SPL + TPL + [compressed] U-Boot for NAND flash\n"
			"  nandhwspl - SPL + [compressed] U-Boot for NAND flash with HW ECC and DMA\n");
}

static enum image_types parse_image_type(const char *type)
{
	if (!type)
		return IMAGE_NONE;

	if (!strncmp(type, "sfspl", 6))
		return IMAGE_SFSPL;

	if (!strncmp(type, "nandspl", 6))
		return IMAGE_NANDSPL;

	if (!strncmp(type, "norspl", 6))
		return IMAGE_NORSPL;

	if (!strncmp(type, "nandhwspl", 6))
		return IMAGE_NANDHWSPL;

	return IMAGE_NONE;
}

static int parse_args(int argc, char *argv[], struct args *arg)
{
	int opt;

	memset(arg, 0, sizeof(*arg));

	while ((opt = getopt(argc, argv, "hbt:e:x:X:U:p:E:r:u:s:T:o:")) != -1) {
		switch (opt) {
		case 'h':
			usage_msg(argv[0]);
			return 1;
		case 'b':
			arg->spl_swap = true;
			break;
		case 't':
			arg->type = parse_image_type(optarg);
			break;
		case 'e':
			arg->entry_addr = strtoul(optarg, NULL, 16);
			break;
		case 'x':
			arg->uboot_offset = strtoul(optarg, NULL, 16);
			break;
		case 'X':
			arg->tpl_offset = strtoul(optarg, NULL, 16);
			break;
		case 'U':
			arg->uboot_size = strtoul(optarg, NULL, 0);
			break;
		case 'p':
			arg->page_size = strtoul(optarg, NULL, 0);
			break;
		case 'E':
			arg->eb_size = strtoul(optarg, NULL, 0);
			break;
		case 'r':
			arg->redund_images = strtoul(optarg, NULL, 0);
			break;
		case 'u':
			arg->uboot_bin = optarg;
			break;
		case 's':
			arg->spl_bin = optarg;
			break;
		case 'T':
			arg->tpl_bin = optarg;
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

	if (!arg->spl_bin) {
		fprintf(stderr, "Missing SPL binary\n");
		goto parse_error;
	}

	if (!arg->uboot_offset) {
		fprintf(stderr, "Missing U-Boot offset\n");
		goto parse_error;
	}

	if (!arg->uboot_size) {
		fprintf(stderr, "Missing U-Boot size\n");
		goto parse_error;
	}

	if (arg->type == IMAGE_NANDSPL || arg->type == IMAGE_NORSPL) {
		if (!arg->tpl_bin) {
			fprintf(stderr, "Missing TPL binary\n");
			goto parse_error;
		}

		if (!arg->tpl_offset) {
			fprintf(stderr, "Missing TPL offset\n");
			goto parse_error;
		}
	}

	if ((arg->type == IMAGE_NANDSPL || arg->type == IMAGE_NANDHWSPL)
		&& !arg->page_size) {
		fprintf(stderr, "Missing NAND page size\n");
		goto parse_error;
	}

	if (arg->type == IMAGE_SFSPL || arg->type == IMAGE_NANDSPL) {
		if (!arg->entry_addr) {
			fprintf(stderr, "Missing entry address\n");
			goto parse_error;
		}
		arg->build_nvb = true;
	}

	if ((arg->type == IMAGE_NANDHWSPL)
		&& !arg->eb_size) {
		fprintf(stderr, "Missing NAND erase block size\n");
		goto parse_error;
	}

	if (arg->type == IMAGE_NANDHWSPL)
		arg->spl_csum = true;

	return 0;

parse_error:
	usage_msg(argv[0]);
	return -1;
}

static __be32 build_nvb_command(unsigned int cmdid, unsigned int cmdflags)
{
	__u32 cmd;
	__u16 tag;

	tag = (cmdid << 8) | cmdflags;
	cmd = (tag << 16) | (0xFFFF - tag);

	return cpu_to_be32(cmd);
}

static ssize_t write_nvb_dwnld_header(int fd, size_t size, __u32 addr)
{
	__be32 hdr[3];

	hdr[0] = build_nvb_command(NVB_CMD_DWNLD, NVB_FLAG_START |
					NVB_FLAG_SDBG);
	hdr[1] = cpu_to_be32(size + 4);
	hdr[2] = cpu_to_be32(addr);

	return write(fd, hdr, sizeof(hdr));
}

static ssize_t write_nvb_start_header(int fd, __u32 addr)
{
	__be32 hdr[3];

	hdr[0] = build_nvb_command(NVB_CMD_START, NVB_FLAG_SDBG);
	hdr[1] = cpu_to_be32(4);
	hdr[2] = cpu_to_be32(addr);

	return write(fd, hdr, sizeof(hdr));
}

static ssize_t write_nvb_regcfg_header(int fd, size_t count)
{
	__be32 hdr[2];

	hdr[0] = build_nvb_command(NVB_CMD_REGCFG, NVB_FLAG_SDBG |
					NVB_FLAG_DBG);
	hdr[1] = cpu_to_be32(count);

	return write(fd, hdr, sizeof(hdr));
}

static int open_input_bin(const char *name, void **ptr, size_t *size)
{
	struct stat sbuf;
	int ret, fd;

	fd = open(name, O_RDONLY);
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
	if (fd >= 0) {
		munmap(ptr, size);
		close(fd);
	}
}

static int open_output_bin(const char *name)
{
	int fd;

	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (0 > fd) {
		fprintf(stderr, "Cannot open %s: %s\n", name,
			strerror(errno));
		return -1;
	}

	return fd;
}

static int write_pad_bytes(int fd, __u8 val, size_t size)
{
	ssize_t n;
	size_t cnt;
	__u8 buf[4];

	memset(buf, val, sizeof(buf));
	cnt = size / 4;

	while (cnt--) {
		n = write(fd, buf, sizeof(buf));
		if (n != sizeof(buf))
			return -1;
	}

	cnt = size % 4;
	if (cnt) {
		n = write(fd, buf, cnt);
		if (n != cnt)
			return -1;
	}

	return 0;
}

static int pad_to_offset(int fd, __u8 val, size_t offset)
{
	size_t pos;

	if (!offset)
		return 0;

	pos = lseek(fd, 0, SEEK_CUR);
	if (offset < pos) {
		fprintf(stderr, "Offset 0x%lx needs to be greater than 0x%lx\n",
			offset, pos);
		return -1;
	}

	return write_pad_bytes(fd, val, offset - pos);
}

static int write_spl_hsnand(int num, int fd, const void *ptr, size_t size,
				bool write_swapped)
{
	__be64 csum = 0;
	__be32 val;
	__u32 csum_final;
	const __u32 *p = ptr;
	ssize_t n;
	int ret;

	while (size > 0) {
		val = cpu_to_be32(*p);
		csum += val;
		csum &= 0xffffffff;

		if (write_swapped)
			n = write(fd, &val, 4);
		else
			n = write(fd, p, 4);

		if (n != 4)
			return -1;

		p++;
		size -= 4;
	}

	ret = pad_to_offset(fd, 0, num * HSNAND_SPL_SIZE - 4);
	if (ret)
		return ret;

	if (write_swapped)
		csum_final = csum;
	else
		csum_final = be32_to_cpu(csum);

	n = write(fd, &csum_final, sizeof(csum_final));
	if (n != sizeof(csum_final))
		return -1;

	return 0;
}

static int create_spl_image(const struct args *arg)
{
	int out_fd, uboot_fd, spl_fd, tpl_fd, i, j, ret = 0;
	void *uboot_ptr, *spl_ptr, *tpl_ptr;
	size_t uboot_size, uboot_size_align, spl_size, tpl_size;
	ssize_t n;
	unsigned int spl_cnt;

	out_fd = open_output_bin(arg->out_bin);
	if (0 > out_fd) {
		ret = -1;
		goto err;
	}

	spl_fd = open_input_bin(arg->spl_bin, &spl_ptr, &spl_size);
	if (0 > spl_fd) {
		ret = -1;
		goto err_spl;
	}

	if (arg->tpl_bin) {
		tpl_fd = open_input_bin(arg->tpl_bin, &tpl_ptr, &tpl_size);
		if (0 > tpl_fd) {
			ret = -1;
			goto err_tpl;
		}
	} else {
		tpl_fd = -1;
	}

	uboot_fd = open_input_bin(arg->uboot_bin, &uboot_ptr, &uboot_size);
	if (0 > uboot_fd) {
		ret = -1;
		goto err_uboot;
	}

	if (arg->uboot_size < uboot_size) {
		fprintf(stderr, "Configured U-Boot size (0x%lx) is smaller than needed (0x%lx)\n",
			arg->uboot_size, uboot_size);
		ret = -1;
		goto err_uboot;
	}

	if (arg->spl_csum && spl_size > HSNAND_SPL_SIZE - 4) {
		fprintf(stderr, "SPL size (0x%lx) is greater than allowed (0x%x)\n",
			spl_size, HSNAND_SPL_SIZE - 4);
		ret = -1;
		goto err_uboot;
	}

	if (arg->build_nvb) {
		n = write_nvb_regcfg_header(out_fd, 0);
		if (n == -1) {
			ret = -1;
			goto err_write;
		}

		n = write_nvb_dwnld_header(out_fd, spl_size, arg->entry_addr);
		if (n == -1) {
			ret = -1;
			goto err_write;
		}
	}

	if (arg->spl_csum) {
		spl_cnt = arg->eb_size / HSNAND_SPL_SIZE;

		for (j = 0; j < 1 + arg->redund_images; j++) {
			for (i = 1; i < spl_cnt; i++) {
				ret = write_spl_hsnand(j * spl_cnt + i, out_fd,
					spl_ptr, spl_size, arg->spl_swap);
				if (ret)
					goto err_write;
			}

			ret = pad_to_offset(out_fd, 0xff,
				(j + 1) * arg->eb_size);
			if (ret)
				goto err_write;
		}
	} else {
		n = write(out_fd, spl_ptr, spl_size);
		if (n == -1) {
			fprintf(stderr, "Failed to write u-boot image: %s\n",
				strerror(errno));
			ret = -1;
			goto err_write;
		}
	}

	if (arg->build_nvb) {
		n = write_nvb_start_header(out_fd, arg->entry_addr);
		if (n == -1) {
			ret = -1;
			goto err_write;
		}
	}

	if (arg->tpl_bin) {
		ret = pad_to_offset(out_fd, 0xff, arg->tpl_offset);
		if (ret)
			goto err_write;

		n = write(out_fd, tpl_ptr, tpl_size);
		if (n == -1) {
			fprintf(stderr, "Failed to write u-boot image: %s\n",
				strerror(errno));
			ret = -1;
			goto err_write;
		}
	}

	if (arg->spl_csum) {
		uboot_size_align = roundup(uboot_size, arg->eb_size);

		for (j = 0; j < 1 + arg->redund_images; j++) {
			n = write(out_fd, uboot_ptr, uboot_size);
			if (n == -1) {
				fprintf(stderr, "Failed to write u-boot image: %s\n",
					strerror(errno));
				ret = -1;
				goto err_write;
			}

			ret = pad_to_offset(out_fd, 0xff,
				(1 + arg->redund_images) * arg->eb_size +
				(j + 1) * uboot_size_align);
			if (ret)
				goto err_write;
		}
	} else {
		ret = pad_to_offset(out_fd, 0xff, arg->uboot_offset);
		if (ret)
			goto err_write;

		n = write(out_fd, uboot_ptr, uboot_size);
		if (n == -1) {
			fprintf(stderr, "Failed to write u-boot image: %s\n",
				strerror(errno));
			ret = -1;
			goto err_write;
		}
	}

err_write:
	close_input_bin(uboot_fd, uboot_ptr, uboot_size);
err_uboot:
	close_input_bin(tpl_fd, tpl_ptr, tpl_size);
err_tpl:
	close_input_bin(spl_fd, spl_ptr, spl_size);
err_spl:
	close(out_fd);
err:
	return ret;
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
	case IMAGE_NANDSPL:
	case IMAGE_NORSPL:
	case IMAGE_NANDHWSPL:
		ret = create_spl_image(&arg);
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
