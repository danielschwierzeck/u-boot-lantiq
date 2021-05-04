#include <common.h>
#include <config.h>
#include <malloc.h>
#include <asm/addrspace.h>

#define INIT_ADDR	0xA0
#define TBAM		0x0
#define I2C_MODE	0x1

static int initialized = 0;

static void i2c_clear_int_status(void)
{
	/* p_ir status */
	while (REG32(I2C_P_IRQSS))
		REG32(I2C_P_IRQSC) = REG32(I2C_P_IRQSS);
	/* error_ir status */
	while (REG32(I2C_ERR_IRQSS))
		REG32(I2C_ERR_IRQSC) = REG32(I2C_ERR_IRQSS);
	/* interrupt */
	while (REG32(I2C_MIS))
		REG32(I2C_ICR) = REG32(I2C_MIS);
}

static void i2c_wait_bus_free(void)
{
	while ((REG32(I2C_BUS_STAT) & 0x03) != 0x0)
		debug("Bus stat is 0x%x\n", REG32(I2C_BUS_STAT));
}

/*
 * Initiate transmit process
 *   txd:    transmit data
 *   len:    data size in bytes
 *
 *   Returns: 0 on success, not 0 on failure
 */
static int i2c_tx(uchar *txd, int len)
{
	int ret = 0;
	int i;
	u32 prot;
	uint word = 0;

	/* Make sure these registers are cleared before read */
	i2c_clear_int_status();

	REG32(I2C_MRPS_CTRL) = 0;
	REG32(I2C_TPS_CTRL) = len;
	for (i = 0; i < len; i++) {
		/* init word */
		if (i % 4 == 0)
			word = 0;

		word |= ((uint)txd[i]) << (8 * (i % 4));

		/* transmit word */
		if ((i % 4 == 3) || (i == len - 1)) {
			REG32(I2C_TXD) = word;
			debug("txword[%d]: 0x%08x\n", i, word);
		}
	}

	/* wait tx end */
	while (1) {
		prot = REG32(I2C_P_IRQSS);
		if (prot & 0x30) {
			if (prot & 0x10) {
				debug("Receive NACK after send addr\n");
				ret = -ENXIO;
				break;
			}

			if (prot & 0x20) {
				debug("Receive tx-end\n");
				break;
			}
		}
	}

	return ret;
}

/************************************************************
	sope=0: send restart on package end 
	     1:      stop 
	sona=0: send restart on receiving NACK
	     1:      stop  
************************************************************/

int hal_i2c_setend(int sope, int sona){
	REG32(I2C_RUN_CTRL) = 0;		//RUN_CTRL
	u32 tmp = REG32(I2C_ADDR_CFG);
	if (sope)	
		tmp |= 0x200000;
	else
		tmp &= ~0x200000;	
	if (sona)	
		tmp |= 0x100000;
	else
		tmp &= ~0x100000;	
	REG32(I2C_ADDR_CFG) = tmp;
	REG32(I2C_RUN_CTRL) = 1;		//RUN_CTRL
	return 0;
}

int hal_i2c_read_reset_value(void)
{
    u32 flag = 0;
    flag += (REG32(I2C_ID)==0x00005702)?0:1;
    return flag;
}

/************************************************************
              1                     inc
	F(scl) = --- x F(kernel) x --------------  (ESTIMATED)
              2                  dec + inc

    - SETUP_A11: F(kernel) = 200MHz, std speed = 100KHz
    	+ std speed: inc =  1, dec = 999

    - SETUP_HAPS: F(kernel) = 4MHz, std speed = 100KHz
    	+ std speed: inc =  1, dec = 19

    - SETUP_PD: F(kernel) = 50KHz, fast speed = 5KHz
    	+ std speed: inc =  1, dec = 4
    
*************************************************************/

void i2c_init(int speed, int unused)

{	
	u32 inc = 1, dec = 999;
	
	printf("Initializing LTQ I2C ... ");

	REG32(I2C_CLC) = 0x00010100;						//I2C_I2C_CLC - RMC=ORMC=1: full clock 
	REG32(0xb6c80054) = 1;								//SDA selected instead of GPIO21
	REG32(0xb6c80058) = 1;								//SCL selected instead of GPIO22	
	REG32(0xb6c80094) = 0x600000;						//GPIO21/22 PAD Drain Output Enabled
	REG32(I2C_RUN_CTRL) = 0;								//I2C_I2C_RUN_CTRL - RUN=0 to enter configuration mode

	REG32(I2C_FDIV_CFG) = inc*0x10000 + dec;  			//I2C_I2C_FDIV_CFG			
	
	REG32(I2C_ADDR_CFG) = (I2C_MODE<<19) + (TBAM<<16) + INIT_ADDR;	//I2C_I2C_ADDR_CFG
														//SONA=0: Send Restart on received NACK
														//SOPE=0: Send Restart on TX packet End 	
	REG32(I2C_FIFO_CFG) = 0x30022;						//I2C_I2C_FIFO_CFG - All byte alignment
	REG32(I2C_RUN_CTRL) = 1;								//I2C_I2C_RUN_CTRL - RUN=1 to enter listening mode

	REG32(I2C_ERR_IRQSM) = 0xf;							//I2C_ERR_IRQSM enable all
	REG32(I2C_P_IRQSM) = 0x7f;							//I2C_P_IRQSM enable all
	REG32(I2C_IMSC) = 0x3f;								//I2C_IMSC enable all
	REG32(I2C_ERR_IRQSC) = REG32(I2C_ERR_IRQSS);		//clear error_ir status
	REG32(I2C_P_IRQSC) = REG32(I2C_P_IRQSS);			//clear p_ir status
	REG32(I2C_ICR) = REG32(I2C_MIS);					//clear interrupt

	if (!hal_i2c_read_reset_value())
		printf("passed\n");
	else
		printf("failed\n");

	initialized = 1;

	return;
}

/*
 * Probe the given I2C chip address.  Returns 0 if a chip responded,
 * not 0 on failure.
 */
int i2c_probe(uchar chip)
{
	uchar txd[1];
	int ret;

	if (!initialized)
		i2c_init(0, 0);

	/* Send end on PE and NACK */
	hal_i2c_setend(1, 1);

	/* we probe by writing slave address (no register address) */
	txd[0] = (chip << 1) | 0 /* write */;
	ret = i2c_tx(txd, 1);

	/* wait until controller enter listening mode and clear interrupt.
	 * sope/sona is set, so we do not need to send SETEND.
	 */
	i2c_wait_bus_free();
	i2c_clear_int_status();

	return ret;
}

/*
 * Read interface:
 *   chip:    I2C chip address, range 0..127
 *   addr:    Memory (register) address within the chip
 *   alen:    Number of bytes to use for addr (typically 1, 2 for larger
 *              memories, 0 for register type devices with only one
 *              register)
 *   buffer:  Where to read the data
 *   len:     How many bytes to read
 *
 *   Returns: 0 on success, not 0 on failure
 */
int i2c_read(uchar chip, uint addr, int alen, uchar *buf, int len)
{
	int i;
	int dwlen = ((len + 15) / 16) * 4; /* uprounded to 4 words */
	u32 *rxword = NULL;
	uchar *txd = NULL;
	int ret = 0;

	debug("%s chip 0x%x addr %u alen %d buf %p len %d\n",
	      __func__, chip, addr, alen, buf, len);

	if (len < 1) {
		error("Invalid read length %d", len);
		return -EINVAL;
	}

	if (!initialized)
		i2c_init(0, 0);

	txd = (uchar *)malloc(1 + alen /* slave + reg addr */);
	rxword = (u32 *)malloc(dwlen * sizeof(u32));

	/* Send end on NACK */
	hal_i2c_setend(0, 1);

	/* construct txd from slave + reg addr */
	txd[0] = (chip << 1) | 0 /* write */;
	for (i = 1; i < 1 + alen; i++) {
		txd[i] = addr & 0xFF;
		addr = addr >> 8;
	}

	/* transmit txd */
	ret = i2c_tx(txd, 1 + alen);
	if (ret)
		goto exit;

	i2c_clear_int_status();

	/* send repeated start */
	REG32(I2C_MRPS_CTRL) = len;
	REG32(I2C_TPS_CTRL) = 0;
	REG32(I2C_TXD) = (chip << 1) | 1 /* read */;

	/* Master Receive
	 * Burst Size = 1/2/4/8 words or 4/8/16/32 bytes
	 * - len <=  4: REG32(0xb6a00030) = len (max = BS)
	 *   and REG32(0xb6a00088) = 0x21
	 * - len <=  8: REG32(0xb6a00030) = len (max = BS)
	 *   and REG32(0xb6a00088) = 0x22
	 * - len <= 16: REG32(0xb6a00030) = len (max = BS)
	 *   and REG32(0xb6a00088) = 0x24 (default)
	 * - len <= 32: REG32(0xb6a00030) = len (max = BS)
	 *   and REG32(0xb6a00088) = 0x28
	 */
	i = 0;
	while (1) {
		if (REG32(I2C_P_IRQSS) & 0x10) { /* NACK */
			debug("Received NACK while waiting rx\n");
			ret = -EREMOTEIO;
			goto exit;
		}
		/* wait for LREQ(<=4) | SREQ(<=8) | LBREQ(<=16) | BREQ(>16) */
		if (REG32(I2C_MIS) & 0x0f) {
			rxword[i++] = REG32(I2C_RXD);
			rxword[i++] = REG32(I2C_RXD);
			rxword[i++] = REG32(I2C_RXD);
			rxword[i++] = REG32(I2C_RXD);

			/* clear interrupt, do it after 4 words are read */
			REG32(I2C_ICR) = REG32(I2C_MIS);

			if (REG32(I2C_RPS_STAT) >= len || i > dwlen)
				break;
		}
	}

	/* convert word to byte */
	for (i = 0; i < len; i++)
		buf[i] = (u8)(rxword[i / 4] >> (8 * (i % 4)));

exit:
	/* wait until controller enter listening mode and clear interrupt */
	i2c_wait_bus_free();
	i2c_clear_int_status();

	free(txd);
	free(rxword);

	return ret;
}

/*
 * Write interface:
 *   chip:    I2C chip address, range 0..127
 *   addr:    Memory (register) address within the chip
 *   alen:    Number of bytes to use for addr (typically 1, 2 for larger
 *              memories, 0 for register type devices with only one
 *              register)
 *   buffer:  Where to write the data
 *   len:     How many bytes to write
 *
 *   Returns: 0 on success, not 0 on failure
 */
int i2c_write(uchar chip, uint addr, int alen, uchar *buf, int len)
{
	int i;
	int ret = 0;
	uchar *txd = NULL;

	debug("%s chip 0x%x addr %u alen %d buf %p len %d\n",
	      __func__, chip, addr, alen, buf, len);

	if (len < 1) {
		error("Invalid read length %d", len);
		return -EINVAL;
	}

	if (!initialized)
		i2c_init(0, 0);

	txd = (uchar *)malloc(1 + alen + len /* slave + reg addr + buf*/);

	/* Send end on PE and NACK */
	hal_i2c_setend(1, 1);

	/* construct txd from slave + reg addr + buf */
	txd[0] = (chip << 1) | 0 /* write */;
	for (i = 1; i < 1 + alen; i++) {
		txd[i] = addr & 0xFF;
		addr = addr >> 8;
	}
	for (; i < 1 + alen + len; i++)
		txd[i] = buf[i - 1 - alen];

	/* transmit txd */
	ret = i2c_tx(txd, 1 + alen + len);

	/* wait until controller enter listening mode and clear interrupt.
	 * sope/sona is set, so we do not need to send SETEND.
	 */
	i2c_wait_bus_free();
	i2c_clear_int_status();
	free(txd);
	return ret;
}
