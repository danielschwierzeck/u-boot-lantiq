/*
 * Copyright (C) 2012
 * Altera Corporation <www.altera.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <spi.h>
#include <asm/errno.h>
#include "cadence_qspi.h"

#define CQSPI_STIG_READ			0
#define CQSPI_STIG_WRITE		1
#define CQSPI_INDIRECT_READ		2
#define CQSPI_INDIRECT_WRITE		3
#define QUAD_RX_OUTPUT			BIT(5)

#ifndef CONFIG_DM_SPI
#define DEFAULT_BLOCKSIZE	0x10000
#define	DEFAULT_PGSIZE		256
#define DEFAULT_TSHSL		200
#define DEFAULT_TSD2D		255
#define DEFAULT_TCHSH		20
#define DEFAULT_TSLCH		20
#define DEFAULT_SRAM_SIZE	128
#define CONFIG_CQSPI_REF_CLK 	100000000
#define CONFIG_CQSPI_DECODER 0
#define QSPI_FLASH_SDRAM	0x00000000

struct cadence_spi_platdata *cadence_plat_data;
struct cadence_spi_priv *cadence_priv_data;
struct spi_slave cadence_slave;
unsigned int qspi_is_init = 1;
extern int qspi_gpio_init(unsigned int cs);

#endif /* CONFIG_DM_SPI */

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_DM_SPI
static int spi_calibration(struct udevice *bus, uint hz)
{
	struct cadence_spi_priv *priv = dev_get_priv(bus);
	void *base = priv->regbase;
	u8 opcode_rdid = 0x9F;
	unsigned int idcode = 0, temp = 0;
	int err = 0, i, range_lo = -1, range_hi = -1;

	/* start with slowest clock (1 MHz) */
	cadence_spi_write_speed(bus, 1000000);

	/* configure the read data capture delay register to 0 */
	cadence_qspi_apb_readdata_capture(base, 1, 0);

	/* Enable QSPI */
	cadence_qspi_apb_controller_enable(base);

	/* read the ID which will be our golden value */
	err = cadence_qspi_apb_command_read(base, 1, &opcode_rdid,
		3, (u8 *)&idcode);
	if (err) {
		puts("SF: Calibration failed (read)\n");
		return err;
	}

	/* use back the intended clock and find low range */
	cadence_spi_write_speed(bus, hz);
	for (i = 0; i < CQSPI_READ_CAPTURE_MAX_DELAY; i++) {
		/* Disable QSPI */
		cadence_qspi_apb_controller_disable(base);

		/* reconfigure the read data capture delay register */
		cadence_qspi_apb_readdata_capture(base, 1, i);

		/* Enable back QSPI */
		cadence_qspi_apb_controller_enable(base);

		/* issue a RDID to get the ID value */
		err = cadence_qspi_apb_command_read(base, 1, &opcode_rdid,
			3, (u8 *)&temp);
		if (err) {
			puts("SF: Calibration failed (read)\n");
			return err;
		}

		/* search for range lo */
		if (range_lo == -1 && temp == idcode) {
			range_lo = i;
			continue;
		}

		/* search for range hi */
		if (range_lo != -1 && temp != idcode) {
			range_hi = i - 1;
			break;
		}
		range_hi = i;
	}

	if (range_lo == -1) {
		puts("SF: Calibration failed (low range)\n");
		return err;
	}

	/* Disable QSPI for subsequent initialization */
	cadence_qspi_apb_controller_disable(base);

	/* configure the final value for read data capture delay register */
	cadence_qspi_apb_readdata_capture(base, 1, (range_hi + range_lo) / 2);
	debug("SF: Read data capture delay calibrated to %i (%i - %i)\n",
	      (range_hi + range_lo) / 2, range_lo, range_hi);

	/* just to ensure we do once only when speed or chip select change */
	priv->qspi_calibrated_hz = hz;
	priv->qspi_calibrated_cs = spi_chip_select(bus);

	return 0;
}

static int cadence_spi_set_speed(struct udevice *bus, uint hz)
{
	struct cadence_spi_platdata *plat = bus->platdata;
	struct cadence_spi_priv *priv = dev_get_priv(bus);
	int err;

	if (hz > plat->max_hz)
		hz = plat->max_hz;

	/* Disable QSPI */
	cadence_qspi_apb_controller_disable(priv->regbase);

	/*
	 * Calibration required for different current SCLK speed, requested
	 * SCLK speed or chip select
	 */
	if (priv->previous_hz != hz ||
	    priv->qspi_calibrated_hz != hz ||
	    priv->qspi_calibrated_cs != spi_chip_select(bus)) {
		err = spi_calibration(bus, hz);
		if (err)
			return err;

		/* prevent calibration run when same as previous request */
		priv->previous_hz = hz;
	}

	/* Enable QSPI */
	cadence_qspi_apb_controller_enable(priv->regbase);

	debug("%s: speed=%d\n", __func__, hz);

	return 0;
}

static int cadence_spi_set_mode(struct udevice *bus, uint mode)
{
	struct cadence_spi_priv *priv = dev_get_priv(bus);
	unsigned int clk_pol = (mode & SPI_CPOL) ? 1 : 0;
	unsigned int clk_pha = (mode & SPI_CPHA) ? 1 : 0;

	/* Disable QSPI */
	cadence_qspi_apb_controller_disable(priv->regbase);

	/* Set SPI mode */
	cadence_qspi_apb_set_clk_mode(priv->regbase, clk_pol, clk_pha);

	/* Enable QSPI */
	cadence_qspi_apb_controller_enable(priv->regbase);

	return 0;
}

static int cadence_spi_write_speed(struct udevice *bus, uint hz)
{
	struct cadence_spi_platdata *plat = bus->platdata;
	struct cadence_spi_priv *priv = dev_get_priv(bus);

	cadence_qspi_apb_config_baudrate_div(priv->regbase,
					     CONFIG_CQSPI_REF_CLK, hz);

	/* Reconfigure delay timing if speed is changed. */
	cadence_qspi_apb_delay(priv->regbase, CONFIG_CQSPI_REF_CLK, hz,
			       plat->tshsl_ns, plat->tsd2d_ns,
			       plat->tchsh_ns, plat->tslch_ns);

	return 0;
}

/* Calibration sequence to determine the read data capture delay register */
static int cadence_spi_probe(struct udevice *bus)
{
	struct cadence_spi_platdata *plat = bus->platdata;
	struct cadence_spi_priv *priv = dev_get_priv(bus);

	priv->regbase = plat->regbase;
	priv->ahbbase = plat->ahbbase;

	if (!priv->qspi_is_init) {
		cadence_qspi_apb_controller_init(plat);
		priv->qspi_is_init = 1;
	}

	return 0;
}

static int cadence_spi_xfer(struct udevice *dev, unsigned int bitlen,
			    const void *dout, void *din, unsigned long flags)
{
	struct udevice *bus = dev->parent;
	struct cadence_spi_platdata *plat = bus->platdata;
	struct cadence_spi_priv *priv = dev_get_priv(bus);
	void *base = priv->regbase;
	u8 *cmd_buf = priv->cmd_buf;
	size_t data_bytes;
	int err = 0;
	u32 mode = CQSPI_STIG_WRITE;

	if (flags & SPI_XFER_BEGIN) {
		/* copy command to local buffer */
		priv->cmd_len = bitlen / 8;
		memcpy(cmd_buf, dout, priv->cmd_len);
	}

	if (flags == (SPI_XFER_BEGIN | SPI_XFER_END)) {
		/* if start and end bit are set, the data bytes is 0. */
		data_bytes = 0;
	} else {
		data_bytes = bitlen / 8;
	}
	debug("%s: len=%d [bytes]\n", __func__, data_bytes);

	/* Set Chip select */
	cadence_qspi_apb_chipselect(base, spi_chip_select(dev),
				    CONFIG_CQSPI_DECODER);

	if ((flags & SPI_XFER_END) || (flags == 0)) {
		if (priv->cmd_len == 0) {
			printf("QSPI: Error, command is empty.\n");
			return -1;
		}

		if (din && data_bytes) {
			/* read */
			/* Use STIG if no address. */
			if (!CQSPI_IS_ADDR(priv->cmd_len))
				mode = CQSPI_STIG_READ;
			else
				mode = CQSPI_INDIRECT_READ;
		} else if (dout && !(flags & SPI_XFER_BEGIN)) {
			/* write */
			if (!CQSPI_IS_ADDR(priv->cmd_len))
				mode = CQSPI_STIG_WRITE;
			else
				mode = CQSPI_INDIRECT_WRITE;
		}

		switch (mode) {
		case CQSPI_STIG_READ:
			err = cadence_qspi_apb_command_read(
				base, priv->cmd_len, cmd_buf,
				data_bytes, din);

		break;
		case CQSPI_STIG_WRITE:
			err = cadence_qspi_apb_command_write(base,
				priv->cmd_len, cmd_buf,
				data_bytes, dout);
		break;
		case CQSPI_INDIRECT_READ:
			err = cadence_qspi_apb_indirect_read_setup(plat,
				priv->cmd_len, cmd_buf);
			if (!err) {
				err = cadence_qspi_apb_indirect_read_execute
				(plat, data_bytes, din);
			}
		break;
		case CQSPI_INDIRECT_WRITE:
			err = cadence_qspi_apb_indirect_write_setup
				(plat, priv->cmd_len, cmd_buf);
			if (!err) {
				err = cadence_qspi_apb_indirect_write_execute
				(plat, data_bytes, dout);
			}
		break;
		default:
			err = -1;
			break;
		}

		if (flags & SPI_XFER_END) {
			/* clear command buffer */
			memset(cmd_buf, 0, sizeof(priv->cmd_buf));
			priv->cmd_len = 0;
		}
	}

	return err;
}

static int cadence_spi_ofdata_to_platdata(struct udevice *bus)
{
	struct cadence_spi_platdata *plat = bus->platdata;
	const void *blob = gd->fdt_blob;
	int node = bus->of_offset;
	int subnode;
	u32 data[4];
	int ret;

	/* 2 base addresses are needed, lets get them from the DT */
	ret = fdtdec_get_int_array(blob, node, "reg", data, ARRAY_SIZE(data));
	if (ret) {
		printf("Error: Can't get base addresses (ret=%d)!\n", ret);
		return -ENODEV;
	}

	plat->regbase = (void *)data[0];
	plat->ahbbase = (void *)data[2];

	/* All other paramters are embedded in the child node */
	subnode = fdt_first_subnode(blob, node);
	if (subnode < 0) {
		printf("Error: subnode with SPI flash config missing!\n");
		return -ENODEV;
	}

	/* Use 500 KHz as a suitable default */
	plat->max_hz = fdtdec_get_uint(blob, subnode, "spi-max-frequency",
				       500000);

	/* Read other parameters from DT */
	plat->page_size = fdtdec_get_int(blob, subnode, "page-size", 256);
	plat->block_size = fdtdec_get_int(blob, subnode, "block-size", 16);
	plat->tshsl_ns = fdtdec_get_int(blob, subnode, "tshsl-ns", 200);
	plat->tsd2d_ns = fdtdec_get_int(blob, subnode, "tsd2d-ns", 255);
	plat->tchsh_ns = fdtdec_get_int(blob, subnode, "tchsh-ns", 20);
	plat->tslch_ns = fdtdec_get_int(blob, subnode, "tslch-ns", 20);
	plat->sram_size = fdtdec_get_int(blob, node, "sram-size", 128);

	debug("%s: regbase=%p ahbbase=%p max-frequency=%d page-size=%d\n",
	      __func__, plat->regbase, plat->ahbbase, plat->max_hz,
	      plat->page_size);

	return 0;
}

static const struct dm_spi_ops cadence_spi_ops = {
	.xfer		= cadence_spi_xfer,
	.set_speed	= cadence_spi_set_speed,
	.set_mode	= cadence_spi_set_mode,
	/*
	 * cs_info is not needed, since we require all chip selects to be
	 * in the device tree explicitly
	 */
};

static const struct udevice_id cadence_spi_ids[] = {
	{ .compatible = "cadence,qspi" },
	{ }
};

U_BOOT_DRIVER(cadence_spi) = {
	.name = "cadence_spi",
	.id = UCLASS_SPI,
	.of_match = cadence_spi_ids,
	.ops = &cadence_spi_ops,
	.ofdata_to_platdata = cadence_spi_ofdata_to_platdata,
	.platdata_auto_alloc_size = sizeof(struct cadence_spi_platdata),
	.priv_auto_alloc_size = sizeof(struct cadence_spi_priv),
	.probe = cadence_spi_probe,
};

#else /* CONFIG_DM_SPI */

static int cadence_spi_write_speed(uint hz)
{
	struct cadence_spi_platdata *plat = cadence_plat_data;
	struct cadence_spi_priv *priv = cadence_priv_data;

	cadence_qspi_apb_config_baudrate_div(priv->regbase,
					     CONFIG_CQSPI_REF_CLK, hz);

	/* Reconfigure delay timing if speed is changed. */
	cadence_qspi_apb_delay(priv->regbase, CONFIG_CQSPI_REF_CLK, hz,
			       plat->tshsl_ns, plat->tsd2d_ns,
			       plat->tchsh_ns, plat->tslch_ns);

	return 0;
}

/* Calibration sequence to determine the read data capture delay register */
static int spi_calibration(struct spi_slave *slave, uint hz)
{
	struct cadence_spi_priv *priv = cadence_priv_data;
	void *base = priv->regbase;
	u8 opcode_rdid = 0x9F;
	unsigned int idcode = 0, temp = 0;
	int err = 0, i, range_lo = -1, range_hi = -1;

	/* start with slowest clock (1 MHz) */
	cadence_spi_write_speed(1000000);

	/* configure the read data capture delay register to 0 */
	cadence_qspi_apb_readdata_capture(base, 1, 0);

	/* Enable QSPI */
	cadence_qspi_apb_controller_enable(base);

	/* read the ID which will be our golden value */
	err = cadence_qspi_apb_command_read(base, 1, &opcode_rdid,
		3, (u8 *)&idcode);
	if (err) {
		puts("SF: Calibration failed (read)\n");
		return err;
	}
	
	/* use back the intended clock and find low range */
	cadence_spi_write_speed(hz);
	for (i = 0; i < CQSPI_READ_CAPTURE_MAX_DELAY; i++) {
		/* Disable QSPI */
		cadence_qspi_apb_controller_disable(base);

		/* reconfigure the read data capture delay register */
		cadence_qspi_apb_readdata_capture(base, 1, i);

		/* Enable back QSPI */
		cadence_qspi_apb_controller_enable(base);

		/* issue a RDID to get the ID value */
		err = cadence_qspi_apb_command_read(base, 1, &opcode_rdid,
			3, (u8 *)&temp);
		if (err) {
			puts("SF: Calibration failed (read)\n");
			return err;
		}

		/* search for range lo */
		if (range_lo == -1 && temp == idcode) {
			range_lo = i;
			continue;
		}

		/* search for range hi */
		if (range_lo != -1 && temp != idcode) {
			range_hi = i - 1;
			break;
		}
		range_hi = i;
	}

	if (range_lo == -1) {
		puts("SF: Calibration failed (low range)\n");
		return err;
	}

	/* Disable QSPI for subsequent initialization */
	cadence_qspi_apb_controller_disable(base);

	/* configure the final value for read data capture delay register */
	cadence_qspi_apb_readdata_capture(base, 1, (range_hi + range_lo) / 2);
	debug("SF: Read data capture delay calibrated to %i (%i - %i)\n",
	      (range_hi + range_lo) / 2, range_lo, range_hi);

	/* just to ensure we do once only when speed or chip select change */
	priv->qspi_calibrated_hz = hz;
	priv->qspi_calibrated_cs = slave->cs;

	return 0;
}

void spi_set_speed(struct spi_slave *slave, uint hz)
{
	struct cadence_spi_platdata *plat = cadence_plat_data;
	struct cadence_spi_priv *priv = cadence_priv_data;

	if (hz > plat->max_hz)
		hz = plat->max_hz;

	/* Disable QSPI */
	cadence_qspi_apb_controller_disable(priv->regbase);

	/*
	 * Calibration required for different current SCLK speed, requested
	 * SCLK speed or chip select
	 */
	if (priv->previous_hz != hz ||
	    priv->qspi_calibrated_hz != hz ||
	    priv->qspi_calibrated_cs != slave->cs) {
		spi_calibration(slave, hz);

		/* prevent calibration run when same as previous request */
		priv->previous_hz = hz;
	}

	/* Enable QSPI */
	cadence_qspi_apb_controller_enable(priv->regbase);

	debug("%s: speed=%d\n", __func__, hz);

}

static int is_erase_cmd(uint8_t cmd)
{		
	if (cmd == 0x20 || cmd == 0x52 ||
			cmd == 0xd8 || cmd == 0xd7)
		return 1;
	
	return 0;
}

static int cadence_spi_probe(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode)
{
	struct cadence_spi_platdata *plat;
	struct cadence_spi_priv *priv;

	plat = kmalloc(sizeof(struct cadence_spi_platdata), GFP_KERNEL);
	priv = kmalloc(sizeof(struct cadence_spi_priv), GFP_KERNEL);

	if (!plat || !priv)
		return -ENOMEM;

	priv->regbase = (u32 *) (KSEG1 | QSPI_MODULE_BASE);
	priv->ahbbase = (QSPI_FLASH_SDRAM);

	plat->regbase = (u32 *) (KSEG1 | QSPI_MODULE_BASE);
	plat->ahbbase = (QSPI_FLASH_SDRAM);

	plat->max_hz = CONFIG_SF_DEFAULT_SPEED;
	plat->block_size = DEFAULT_BLOCKSIZE;
	plat->page_size = DEFAULT_PGSIZE;
	plat->tshsl_ns = DEFAULT_TSHSL;
	plat->tsd2d_ns = DEFAULT_TSD2D;
	plat->tchsh_ns = DEFAULT_TCHSH;
	plat->tslch_ns = DEFAULT_TSLCH;
	plat->sram_size = DEFAULT_SRAM_SIZE;

	cadence_qspi_apb_controller_init(plat);

	qspi_is_init = 0;

	cadence_plat_data = plat;
	cadence_priv_data = priv;
	
	debug("Running at %d hz\n", plat->max_hz);

	return 0;
}

struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode)
{
	int ret;
	
	if (!qspi_is_init)
		return &cadence_slave;

 	ret = qspi_gpio_init(cs);
	if (ret)
		return NULL;
	
	ret = cadence_spi_probe(bus, cs, max_hz, mode);
	if (ret)
		return NULL;

	cadence_slave.cs = 0;
	cadence_slave.bus = 0;
	cadence_slave.memory_map = NULL;

#ifdef CONFIG_SPI_FLASH_QUAD
	cadence_slave.mode = SPI_TX_QUAD;
	cadence_slave.mode_rx = QUAD_RX_OUTPUT;
#endif
	/* set the baudrate and calibrate the delays */
	spi_calibration(&cadence_slave, CONFIG_SF_DEFAULT_SPEED);

	return &cadence_slave;		
}

int spi_xfer(struct spi_slave *slave, unsigned int bitlen,
			    const void *dout, void *din, unsigned long flags)
{
	struct cadence_spi_platdata *plat = cadence_plat_data;
	struct cadence_spi_priv *priv = cadence_priv_data;
	void *base = priv->regbase;
	u8 *cmd_buf = priv->cmd_buf;
	size_t data_bytes;
	int err = 0;
	u32 mode = CQSPI_STIG_WRITE;

	if (flags & SPI_XFER_BEGIN) {
		/* copy command to local buffer */
		priv->cmd_len = bitlen / 8;
		memcpy(cmd_buf, dout, priv->cmd_len);
	}

	if (flags == (SPI_XFER_BEGIN | SPI_XFER_END)) {
		/* if start and end bit are set, the data bytes is 0. */
		data_bytes = 0;
	} else {
		data_bytes = bitlen / 8;
	}
	debug("%s: len=%d [bytes]\n", __func__, data_bytes);

	/* Set Chip select */
	cadence_qspi_apb_chipselect(base, slave->cs,
				    CONFIG_CQSPI_DECODER);

	if ((flags & SPI_XFER_END) || (flags == 0)) {
		if (priv->cmd_len == 0) {
			printf("QSPI: Error, command is empty.\n");
			return -1;
		}

		if (din && data_bytes) {
			/* read */
			/* Use STIG if no address. */
			if (!CQSPI_IS_ADDR(priv->cmd_len)) 
				mode = CQSPI_STIG_READ;
			else
				mode = CQSPI_INDIRECT_READ;
		} else if (dout && !(din)) {
			/* write */
			if (!CQSPI_IS_ADDR(priv->cmd_len) ||
				(is_erase_cmd(cmd_buf[0])))
				mode = CQSPI_STIG_WRITE;
			else
				mode = CQSPI_INDIRECT_WRITE;
		}

		debug("%s: cmd: 0x%02x, cmdlen: %d, bitlen: %d, flags: 0x%08x\n",
				__func__, cmd_buf[0], priv->cmd_len, bitlen, (u32) flags);

		switch (mode) {
		case CQSPI_STIG_READ:
			err = cadence_qspi_apb_command_read(
				base, priv->cmd_len, cmd_buf,
				data_bytes, din);

		break;
		case CQSPI_STIG_WRITE:
			err = cadence_qspi_apb_command_write(base,
				priv->cmd_len, cmd_buf,
				data_bytes, dout);
		break;
		case CQSPI_INDIRECT_READ:
			err = cadence_qspi_apb_indirect_read_setup(plat,
				priv->cmd_len, cmd_buf);
			if (!err) {
				err = cadence_qspi_apb_indirect_read_execute
				(plat, data_bytes, din);
			}
		break;
		case CQSPI_INDIRECT_WRITE:
			err = cadence_qspi_apb_indirect_write_setup
				(plat, priv->cmd_len, cmd_buf);
			if (!err) {
				err = cadence_qspi_apb_indirect_write_execute
				(plat, data_bytes, dout);
			}
		break;
		default:
			err = -1;
			break;
		}

		if (flags & SPI_XFER_END) {
			/* clear command buffer */
			memset(cmd_buf, 0, sizeof(priv->cmd_buf));
			priv->cmd_len = 0;
		}
	}

	return err;
}

void spi_free_slave(struct spi_slave *slave)
{
	return;
}

int spi_claim_bus(struct spi_slave *slave)
{
	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
	return;
}
#endif /* CONFIG_DM_SPI */
