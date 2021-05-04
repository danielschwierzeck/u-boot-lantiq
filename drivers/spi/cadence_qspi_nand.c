/*
 * Copyright (C) 2012
 * Altera Corporation <www.altera.com>
 *
 * Copyright (C) 2017 
 * Mohammad Firdaus B Alias Thani <m.aliasthani@intel.com>
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

#define DEFAULT_BLOCKSIZE	0x20000
#define	DEFAULT_PGSIZE		2048
#define DEFAULT_TSHSL		200
#define DEFAULT_TSD2D		255
#define DEFAULT_TCHSH		20
#define DEFAULT_TSLCH		20
#define DEFAULT_SRAM_SIZE	128
#define CONFIG_CQSPI_REF_CLK 	100000000
#define CONFIG_CQSPI_DECODER 0

#define QSPI_FLASH_SDRAM	0x00000000
#define QSPI_ADDRESS	1
#define QSPI_DUMMY		2
#define QSPI_TX			3
#define QSPI_RX			4
#define QSPI_DONE		7

DECLARE_GLOBAL_DATA_PTR;

struct cadence_spi_platdata *cadence_plat_data;
struct cadence_spi_priv *cadence_priv_data;
struct spi_slave cadence_slave;
unsigned int qspi_is_init = 1;
extern int qspi_gpio_init(unsigned int cs);

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

static int cadence_qspi_nand_read_id(struct spi_slave *spi, u8 *cmd,
			unsigned int rx_bytes, u8 *id)
{
	int retval = 0;
	u8 dummy[6] = {0};
	u8 nand_id[3] = {0};
	u8 addr = 0;
	u8 dummy_bytes = 1;
	u8 tx_bytes = 0;

	spi_xfer(spi, 8, cmd, NULL, SPI_XFER_BEGIN);
	/* send addr if any */
	spi_xfer(spi, 8 * addr, &addr, NULL, 0);
	/*send tx dummy bytes if any*/
	spi_xfer(spi, 8 * dummy_bytes, &dummy, NULL, 0);
	spi_xfer(spi, 8 * tx_bytes, NULL, NULL, 0);  
	spi_xfer(spi, 8 * rx_bytes, NULL, &nand_id[0], SPI_XFER_END);  

	id[0] = nand_id[0];
	id[1] = nand_id[1];
	id[2] = nand_id[2];
	if (id[0]==0 || id[0]==0xff) {
		id[0]=id[1];
		id[1]=id[2];
	}

	return retval;
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

	/* read nand id */
	err = cadence_qspi_nand_read_id(slave, &opcode_rdid,
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
		udelay(100);
		err = cadence_qspi_nand_read_id(slave, &opcode_rdid,
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
	    priv->qspi_calibrated_cs != slave->cs) {
		err = spi_calibration(slave, hz);
		if (err) {
			printf("QSPI speed calibration error\n");
			return;
		}

		/* prevent calibration run when same as previous request */
		priv->previous_hz = hz;
	}

	/* Enable QSPI */
	cadence_qspi_apb_controller_enable(priv->regbase);

	debug("%s: speed=%d\n", __func__, hz);

}

static int cadence_spi_probe(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode)
{
	struct cadence_spi_platdata *plat;
	struct cadence_spi_priv *priv;

	plat = kmalloc(sizeof(struct cadence_spi_platdata), GFP_KERNEL);
	if (!plat)
		return -ENOMEM;

	priv = kmalloc(sizeof(struct cadence_spi_priv), GFP_KERNEL);
	if (!priv) {
		kfree(plat);
		return -ENOMEM;
	}

	priv->regbase = (uint32_t *)(KSEG1 | QSPI_MODULE_BASE);
	priv->ahbbase = (uint32_t *)(QSPI_FLASH_SDRAM);

	plat->regbase = (uint32_t *)(KSEG1 | QSPI_MODULE_BASE);
	plat->ahbbase = (uint32_t *)(QSPI_FLASH_SDRAM);

	plat->max_hz = max_hz; 
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

	return 0;
}

int cadence_spi_set_mode(uint mode)
{
	struct cadence_spi_priv *priv = cadence_priv_data;
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

	/* set the baudrate and calibrate the delay registers */
	spi_calibration(&cadence_slave, CONFIG_SF_DEFAULT_SPEED);

	return &cadence_slave;		
}

int spi_xfer(struct spi_slave *slave, unsigned int bitlen,
			    const void *dout, void *din, unsigned long flags)
{
	struct cadence_spi_platdata *plat = cadence_plat_data;
	struct cadence_spi_priv *priv = cadence_priv_data;
	void *base = priv->regbase;
	size_t data_bytes;
	int err = 0;
	uint8_t *cmd_buf = priv->cmd_buf;
	uint32_t mode = CQSPI_STIG_WRITE;

	debug("%s: State: %d, bitlen: %d, flags: %lu\n", __func__, priv->state, bitlen, flags);

	if (flags & SPI_XFER_BEGIN) {
		/* copy command to local buffer */
		priv->cmd_len = bitlen / 8;
		memcpy(cmd_buf, dout, priv->cmd_len);
		priv->state += 1;
		goto done;
	}

	if (bitlen == 0 && !(flags & SPI_XFER_END)) {
		priv->state += 1;
		goto done;
	}

	data_bytes = bitlen / 8;

	/* From the NAND driver side, these are the states 
	 * that the bus driver have to take note. Since we only
	 * start reading/writing after all the necessary 
	 * information is needed (i.e addr, data, etc), we have
	 * too keep track of all the states before sending a 
	 * request to the controller 
	 */
	switch (priv->state) {
	case QSPI_ADDRESS:
		if (!din && dout) {
			memcpy(&cmd_buf[1], dout, data_bytes);
			priv->cmd_len += data_bytes;
		}
		priv->state += 1;
		goto done;
	case QSPI_DUMMY:
		if (dout && data_bytes) {
			memcpy(&cmd_buf[priv->cmd_len], dout, data_bytes);
			priv->cmd_len += data_bytes;
		}
		priv->state += 1;
		goto done;
	case QSPI_TX:
		priv->state += 1;
		if (data_bytes && dout) { 
			/* if there is TX data, send out */
			priv->tx_len = data_bytes;
			break;
		}
		goto done;
	case QSPI_RX:
		/* If there is RX data, send out */
		if (data_bytes && din)
			priv->rx_len = data_bytes;
		priv->state += 1;
		break;
	case QSPI_DONE:
		flags |= SPI_XFER_END;
		goto done;
	default:
		printf("Unknown state\n");
		return -EINVAL;
	}
	
	debug("%s: rxlen: %d, txlen: %d, cmd: 0x%02x, cmdlen: 0x%02x, flags: %lu\n",
			__func__, priv->rx_len, priv->tx_len, cmd_buf[0], priv->cmd_len, flags);

	if ((flags & SPI_XFER_END) || (flags == 0)) {
		if (priv->cmd_len == 0) {
			printf("QSPI: Error, command is empty.\n");
			return -1;
		}

		/* Use STIG if tx/rx less than 8 bytes. */
		if (din && priv->rx_len) {
			/* read */
			if (priv->rx_len < 8) 
				mode = CQSPI_STIG_READ;
			else
				mode = CQSPI_INDIRECT_READ;
		} else if (dout && !(din)) {
			/* write */
			if (priv->tx_len < 8) 
				mode = CQSPI_STIG_WRITE;
			else
				mode = CQSPI_INDIRECT_WRITE;
		}

		switch (mode) {
		case CQSPI_STIG_READ:
			err = cadence_qspi_apb_command_read(
				base, priv->cmd_len, cmd_buf,
				priv->rx_len, din);
			priv->state = QSPI_DONE;
		break;
		case CQSPI_STIG_WRITE:
			err = cadence_qspi_apb_command_write(base,
				priv->cmd_len, cmd_buf,
				priv->tx_len, dout);
			priv->state = QSPI_DONE;
		break;
		case CQSPI_INDIRECT_READ:
			err = cadence_qspi_apb_indirect_read_setup(plat,
				priv->cmd_len, cmd_buf);
			if (!err) {
				err = cadence_qspi_apb_indirect_read_execute
				(plat, priv->rx_len, din);
			}
			priv->state = QSPI_DONE;
		break;
		case CQSPI_INDIRECT_WRITE:
			err = cadence_qspi_apb_indirect_write_setup
				(plat, priv->cmd_len, cmd_buf);
			if (!err) {
				err = cadence_qspi_apb_indirect_write_execute
				(plat, priv->tx_len, dout);
			}
			priv->state = QSPI_DONE;
		break;
		default:
			err = -1;
			break;
		}

done:
		if (flags & SPI_XFER_END) {
			/* clear command buffer */
			memset(cmd_buf, 0, sizeof(priv->cmd_buf));
			priv->cmd_len = 0;
			priv->state = 0;
			priv->rx_len = 0;
			priv->tx_len = 0;
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
