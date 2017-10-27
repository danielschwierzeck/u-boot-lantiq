/******************************************************************************
 * **
 * ** FILE NAME    : lq_spinand.c
 * ** PROJECT      : GRX500
 * ** MODULES      : SPI NAND Flash
 * **
 * ** DATE         : 22 Oct 2015
 * ** AUTHOR       : Wu Qi Ming
 * ** DESCRIPTION  : SPI NAND Flash MTD Driver
 * ** COPYRIGHT    :       Copyright (c) 2015
 * **                      Lantiq Technologies 
 * **                      
 * **
 * **    This program is free software; you can redistribute it and/or modify
 * **    it under the terms of the GNU General Public License as published by
 * **    the Free Software Foundation; either version 2 of the License, or
 * **    (at your option) any later version.
 * **
 * ** HISTORY
 * ** $Date        $Author      $Version   $Comment
 * ** 22 Oct 2015  Wu Qi Ming   1.0        initial version
 * *******************************************************************************/

#include <common.h>


#include <nand.h>
#include <asm/errno.h>
#include <asm/addrspace.h>
#include <spi.h>
#include <spinand.h>


struct spinand_info spinand_info={NULL, NULL, NULL};
struct spinand_state spinand_state={0, 0, 0, NULL};
/*fix me, hardcoded to 4K page+256 oob, might need to adjust for bigger spi nand flashes*/
unsigned char spinand_buf[4096+256]; 

static void spinand_write_byte(struct spi_slave *spi, u_char byte);

static inline struct spinand_state *mtd_to_state(struct mtd_info *mtd)
{
        struct nand_chip *chip = (struct nand_chip *)mtd->priv;
        struct spinand_info *info = (struct spinand_info *)chip->priv;
        struct spinand_state *state = (struct spinand_state *)info->priv;

        return state;
}



static void spinand_chip_init(void)
{
    
}


static void spinand_write_byte(struct spi_slave *spi, u_char byte)
{
      unsigned long flags = SPI_XFER_BEGIN|SPI_XFER_END;
      spi_xfer(spi, 8, &byte, NULL, flags);
}


static uint8_t spinand_read_byte(struct mtd_info *mtd)
{
       struct spinand_state *state = mtd_to_state(mtd);
       u8 data;

       data = state->buf[state->buf_ptr];
       state->buf_ptr++;
       return data;

}



static void spinand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
        struct nand_chip *chip = (struct nand_chip *)mtd->priv;
        struct spi_slave *spi = (struct spi_slave *)chip->priv;
        spi_xfer(spi, len * 8, NULL, buf, SPI_XFER_BEGIN|SPI_XFER_END);        
}

static void spinand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
        struct nand_chip *chip = (struct nand_chip *)mtd->priv;
        struct spi_slave *spi = (struct spi_slave *)chip->priv;
        spi_xfer(spi, len * 8, buf, NULL, SPI_XFER_BEGIN|SPI_XFER_END); 
}


/*
 * spinand_cmd - to process a command to send to the SPI Nand
 * Description:
 *    Set up the command buffer to send to the SPI controller.
 *    The command buffer has to initialized to 0.
 */

static int spinand_cmd(struct spi_slave *spi, struct spinand_cmd *cmd)
{
       int retval=0;
       spi_xfer(spi, 8, &(cmd->cmd), NULL, SPI_XFER_BEGIN);
       /* send addr if any */
       spi_xfer(spi, 8*(cmd->n_addr), cmd->addr, NULL, 0);
       /*send tx dummy bytes if any*/
       spi_xfer(spi, 8*(cmd->n_tx), cmd->tx_buf, NULL, 0);  
       spi_xfer(spi, 8*(cmd->n_rx), NULL,cmd->rx_buf, SPI_XFER_END);  
       return retval;
}



/*
 * spinand_read_id- Read SPI Nand ID
 * Description:
 *    Read ID: read two ID bytes from the SPI Nand device
 */
static int spinand_read_id(struct spinand_info *spi_nand, u8 *id)
{
        int retval;
        u8 nand_id[3];
        struct spinand_cmd cmd = {0};
        struct spi_slave *spi=spi_nand->spi;

        cmd.cmd = CMD_READ_ID;
        cmd.n_rx = 3;
        cmd.rx_buf = &nand_id[0];

        retval = spinand_cmd(spi, &cmd);
        if (retval < 0) {
                return retval;
        }
        id[0] = nand_id[0];
        id[1] = nand_id[1];
        id[2] = nand_id[2];
        if(id[0]==0 || id[0]==0xff){
           id[0]=id[1];
           id[1]=id[2];
        }
        
        if(id[0]==0xc8){
           spi_nand->options|=GIGADEVICE_DUMMY_TYPE;
        }
        return retval;
}


/*
 * spinand_get_feature- get spi nand feature
 * Description: get spi nand feature
 */
static u8 spinand_get_feature(struct spi_slave *spi, u8 addr)
{       
        u8 feature=0;
        struct spinand_cmd cmd = {0};

        cmd.cmd = CMD_GET_FEATURE;
        cmd.n_addr = 1;
        cmd.addr[0] = addr;
        cmd.n_rx = 1;
        cmd.rx_buf = &feature;
        spinand_cmd(spi, &cmd);
        return feature;
}


/*
 * spinand_set_feature- set spi nand feature
 * Description: set spi nand feature
 */
static int spinand_set_feature(struct spi_slave *spi, u8 addr, u8 feature)
{
        int retval;
        struct spinand_cmd cmd = {0};

        cmd.cmd = CMD_SET_FEATURE;
        cmd.n_addr = 1;
        cmd.addr[0] = addr;
        cmd.n_tx = 1;
        cmd.tx_buf = &feature;
        retval = spinand_cmd(spi, &cmd);
        return retval;
}


static int spinand_ready(struct mtd_info *mtd)
{
      struct nand_chip *chip = (struct nand_chip *)mtd->priv;
      struct spinand_info *info = (struct spinand_info *)chip->priv;

       /*check OIP status bit*/
      while(spinand_get_feature(info->spi, REG_STATUS) & 0x1);
      return 1;
}




/*
 * spinand_reset -reset spi nand 
 * Description: reset spi nand flash
 */
static int spinand_reset(struct spi_slave *spi)
{
        int retval;
        struct spinand_cmd cmd = {0};
        cmd.cmd = CMD_RESET;
        retval = spinand_cmd(spi, &cmd);
        /*check OIP status bit*/
        while(spinand_get_feature(spi, REG_STATUS) & 0x1);
        /*unlock the whole spi nand flash*/
        spinand_set_feature(spi, REG_BLOCK_LOCK, 0);
        /*unlock the whole spi nand flash*/
        while(spinand_get_feature(spi, REG_STATUS) & 0x1);

        return retval;        
}



/**
 * spi_nand_write_enable- send command 0x06 to enable write or erase the
 * Nand cells
 * Description:
 *   Before write and erase the Nand cells, the write enable has to be set.
 *   After the write or erase, the write enable bit is automatically
 *   cleared (status register bit 2)
 *   Set the bit 2 of the status register has the same effect
 */
static int spi_nand_write_enable(struct spi_slave *spi)
{
    struct spinand_cmd cmd = {0};

    cmd.cmd = CMD_WR_ENABLE;
    return spinand_cmd(spi, &cmd);
}



/**
 * spi_nand_write_disable- send command 0x04 to disable write or erase the nand flash
 */
static int spi_nand_write_disable(struct spi_slave *spi)
{
    struct spinand_cmd cmd = {0};

    cmd.cmd = CMD_WR_DISABLE;
    return spinand_cmd(spi, &cmd);
}


/*
 * spinand_erase_block -erase an spi nand block
 * Description: erase an spi nand block
 */

static int spinand_erase_block(struct spi_slave *spi, int page_addr)
{
      struct spinand_cmd cmd = {0};
      int retval;
      spi_nand_write_enable(spi);

      cmd.cmd = CMD_ERASE_BLK;
      cmd.n_addr = 3;
      cmd.addr[0] = (u8)(page_addr >> 16);
      cmd.addr[1] = (u8)(page_addr >> 8);
      cmd.addr[2] = (u8)page_addr;

      retval=spinand_cmd(spi, &cmd);

      /*check OIP status bit*/
      while(spinand_get_feature(spi, REG_STATUS) & 0x1);

      spi_nand_write_disable(spi);

      return retval;
}


/*
 *Build a "fake" nand flash status to make the nand flash driver happy
 *
*/
static int spinand_read_status(struct spinand_info *spi_nand)
{
     struct spinand_state *state = spi_nand->priv;
     u8 status;
     status=0x80;
     state->buf[0]=status;
     state->buf_ptr=0;
     return 1;
}

static void spinand_cmdfunc(struct mtd_info *mtd, unsigned int command,
                int column, int page)
{
      struct nand_chip *chip = (struct nand_chip *)mtd->priv;
      struct spinand_info *info = (struct spinand_info *)chip->priv;
      struct spinand_state *state = (struct spinand_state *)info->priv;
      u8 cmd;
      u8 id[2];
      switch (command) {
          case NAND_CMD_READ1:
          case NAND_CMD_READ0:
          case NAND_CMD_ERASE2:
                break;
          case NAND_CMD_SEQIN:
                *((u32*)state->buf)=page; /*record the page information*/
                state->buf_ptr=0;
                break;
          case NAND_CMD_STATUS:
                spinand_read_status(info); 
                break;
          case NAND_CMD_ERASE1: 
                spinand_erase_block(info->spi, page); 
                break;
          case NAND_CMD_READID:
                state->buf_ptr = 0;
                spinand_read_id(info, (u8 *)state->buf);
                break;
          case NAND_CMD_RESET:
                spinand_reset(info->spi); 
                break;
          default:
                break;
      }
}





static void spinand_select_chip(struct mtd_info *mtd, int dev)
{
}


int spinand_read_from_cache(struct nand_chip *chip, u32 column, size_t len, u8 *rbuf)
{
    struct spinand_info *info = (struct spinand_info *)chip->priv;
    struct spinand_cmd cmd = {0};
    cmd.cmd = CMD_READ_FROM_CACHE;
    cmd.n_addr = 3;
    if(info->options & GIGADEVICE_DUMMY_TYPE){
      cmd.addr[0] = 0; 
      cmd.addr[1] = (u8)(column >> 8);
      cmd.addr[2] = (u8)column;
    } else {
      cmd.addr[0] = (u8)(column >> 8);
      cmd.addr[1] = (u8)column;
      cmd.addr[2] = 0;
    }
    cmd.n_rx = len;
    cmd.rx_buf = rbuf;
    spinand_cmd(info->spi, &cmd);
    return 1;
}


int spinand_read_page_to_cache(struct nand_chip *chip, int page)
{
    int retval=0;
    struct spinand_info *info = (struct spinand_info *)chip->priv;
    struct spinand_cmd cmd = {0};
    u8 status=0x1;
    cmd.cmd = CMD_READ_PAGE_TO_CACHE;
    cmd.n_addr = 3;
    cmd.addr[0] = (u8)(page >> 16);
    cmd.addr[1] = (u8)(page >> 8);
    cmd.addr[2] = (u8)page;
    cmd.n_tx=0;
    cmd.n_rx=0;
    retval = spinand_cmd(info->spi, &cmd);
    while(status & 0x1){
      status = spinand_get_feature(info->spi, REG_STATUS);
    }
    if((status>>4)==0x7) retval=-1;
    return retval; 
}


static int spinand_read_page(struct mtd_info *mtd, struct nand_chip *chip,
                uint8_t *rbuf, int page)
{
 
    int retval = spinand_read_page_to_cache(chip, page);
    spinand_read_from_cache(chip, 0, mtd->writesize, rbuf);
    return retval;
}


static int spinand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
                uint8_t *rbuf, int page)
{
     int retval = spinand_read_page(mtd, chip, rbuf, page);
     spinand_read_from_cache(chip, mtd->writesize, mtd->oobsize, chip->oob_poi);
     return retval;
}



static int spinand_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
                           int page, int sndcmd)
{
       int retval = spinand_read_page_to_cache(chip, page);
       spinand_read_from_cache(chip, mtd->writesize, mtd->oobsize, chip->oob_poi);
       return retval;
}


static int spi_nand_program_data_to_cache(struct nand_chip *chip, u32 column, size_t len, u8 *wbuf)
{
    struct spinand_cmd cmd = {0};
    struct spinand_info *info = (struct spinand_info *)chip->priv;
    cmd.cmd = CMD_PROG_LOAD_TO_CACHE;
    cmd.n_addr = 2;
    cmd.addr[0] = (u8)(column >> 8);
    cmd.addr[1] = (u8)column;
    cmd.n_tx = len;
    cmd.tx_buf = wbuf;
    return spinand_cmd(info->spi, &cmd);
}


static int spi_nand_program_data_to_cache_random(struct nand_chip *chip, u32 column, size_t len, u8 *wbuf)
{
    struct spinand_cmd cmd = {0};
    struct spinand_info *info = (struct spinand_info *)chip->priv;
    cmd.cmd = CMD_PROG_LOAD_TO_CACHE_RANDOM;
    cmd.n_addr = 2;
    cmd.addr[0] = (u8)(column >> 8);
    cmd.addr[1] = (u8)column;
    cmd.n_tx = len;
    cmd.tx_buf = wbuf;
    return spinand_cmd(info->spi, &cmd);
}



static int spi_nand_program_execute(struct nand_chip *chip, u32 page_addr)
{
    struct spinand_cmd cmd = {0};
    struct spinand_info *info = (struct spinand_info *)chip->priv;
    cmd.cmd = CMD_PROG_PAGE_EXC;
    cmd.n_addr = 3;
    cmd.addr[0] = (u8)(page_addr >> 16);
    cmd.addr[1] = (u8)(page_addr >> 8);
    cmd.addr[2] = (u8)page_addr;
    spinand_cmd(info->spi, &cmd);

    /*check OIP status bit*/
    while(spinand_get_feature(info->spi, REG_STATUS) & 0x1);
}


static int spinand_write_page(struct mtd_info *mtd,
                struct nand_chip *chip, const uint8_t *buf)
{
        struct spinand_info *info = (struct spinand_info *)chip->priv;
        struct spinand_state *state = (struct spinand_state *)info->priv;
        int i;
        //spinand_read_page_to_cache(chip, *((u32*)state->buf));
        //spi_nand_program_data_to_cache_random(chip, 0, mtd->writesize, buf);
        //spi_nand_program_data_to_cache_random(chip, mtd->writesize, mtd->oobsize, chip->oob_poi);
        spi_nand_write_enable(info->spi);
        //spi_nand_program_data_to_cache(chip, 0, mtd->writesize, buf);    
        spi_nand_program_data_to_cache_random(chip, 0, mtd->writesize, buf);
        spi_nand_program_data_to_cache_random(chip, mtd->writesize, mtd->oobsize, chip->oob_poi);
        spi_nand_program_execute(chip, *((u32*)state->buf));
        spinand_ready(mtd);
        spi_nand_write_disable(info->spi);
        return 0;
}



static int spinand_write_oob(struct mtd_info *mtd, struct nand_chip *chip,
                  int page)
{
    struct spinand_info *info = (struct spinand_info *)chip->priv;
    spinand_read_page_to_cache(chip, page);
    spinand_ready(mtd);
    spi_nand_program_data_to_cache_random(chip, mtd->writesize, mtd->oobsize, chip->oob_poi);
    spi_nand_write_enable(info->spi);
    spi_nand_program_execute(chip, page);
    spinand_ready(mtd);
    spi_nand_write_disable(info->spi);
    return 0;
}



static int spinand_wait(struct mtd_info *mtd, struct nand_chip *chip)
{

       return 0;
}


static int spinand_block_bad(struct mtd_info *mtd, loff_t ofs, int getchip)
{
       int page;
       int retval=0;
       struct nand_chip *chip = mtd->priv;
       page = (int)(ofs >> chip->page_shift) & chip->pagemask;
       chip->ecc.read_oob(mtd, chip, page, 0);
       if(*(chip->oob_poi+CONFIG_SYS_NAND_BAD_BLOCK_POS)!=0xff) {
          retval=1;
       }
       return retval;
}



int board_nand_init(struct nand_chip *chip)
{
        unsigned int bus = 0;
        unsigned int cs=CONFIG_ENV_SPI_CS;
        unsigned int speed = CONFIG_SF_DEFAULT_SPEED;
        unsigned int mode = CONFIG_SF_DEFAULT_MODE;
        struct spi_slave *spi;
        struct spinand_info *info;
        struct spinand_state *state;
        int ret;

        spinand_chip_init();
        spi = spi_setup_slave(bus, cs, speed, mode);
        if (!spi) {
                debug("SF: Failed to set up slave\n");
                goto error;
        }

        ret = spi_claim_bus(spi);
        if (ret) {
                debug("SF: Failed to claim SPI bus: %d\n", ret);
                goto error;
        }

        /*init spinand info structure*/
        info = &spinand_info;
        info->options=0;
        info->spi = spi;
        state = &spinand_state;
        info->priv      = state;
        state->buf_ptr  = 0;
        state->buf      = &spinand_buf;

        chip->priv = info;
        chip->ecc.mode  = NAND_ECC_HW;
        chip->ecc.read_page = spinand_read_page;
        chip->ecc.read_page_raw = spinand_read_page_raw;
        chip->ecc.write_page = spinand_write_page;
        chip->ecc.read_oob = spinand_read_oob;
        chip->ecc.write_oob = spinand_write_oob;
        chip->read_buf  = spinand_read_buf;
        chip->write_buf = spinand_write_buf;
        chip->read_byte = spinand_read_byte;
        chip->cmdfunc   = spinand_cmdfunc;
	chip->block_bad = spinand_block_bad;
        chip->dev_ready = spinand_ready;
        chip->waitfunc  = spinand_wait;
        chip->select_chip = spinand_select_chip;
        chip->options|=NAND_USE_FLASH_BBT|NAND_NO_SUBPAGE_WRITE;; 

error:
        return 0;
}




