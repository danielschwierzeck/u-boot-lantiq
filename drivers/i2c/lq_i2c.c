
#include <common.h>
#include <config.h>
#include <asm/addrspace.h>

#define INIT_ADDR	0xA0
#define TBAM		0x0
#define I2C_MODE	0x1

static int initialized = 0;

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

int i2c_probe(uchar chip) 
{
	return 0;
}

int i2c_read(uchar chip, uint addr, int alen, uchar *buf, int len)
{
    int i;  
    int  dwlen = (len / 4) + 1;
    u32 *rxword;                                //4K words = 16KBytes

	if (len < 1)
		return -1;

	if (!initialized)
		i2c_init(0, 0);

    hal_i2c_setend(1, 1);                               //Send end on PE, and end on NACK

    /*Make sure these registers are cleared before read*/
    while (REG32(I2C_P_IRQSS)){
        REG32(I2C_P_IRQSC) = REG32(I2C_P_IRQSS);          //clear p_ir status
    }
    while (REG32(I2C_ERR_IRQSS)){
        REG32(I2C_ERR_IRQSC) = REG32(I2C_ERR_IRQSS);          //clear error_ir status
    }
    while (REG32(I2C_MIS)){
        REG32(I2C_ICR) = REG32(I2C_MIS);          //clear interrupt
    }

	rxword = (u32 *) malloc(dwlen);

    REG32(I2C_P_IRQSM) |= 0x30;                          //Enable TX_END/NACK int

    //Master Send Read Address      
    //dwlen = rlen/4;
    REG32(I2C_MRPS_CTRL) = alen + 1;					 // addr + chip
    REG32(I2C_TPS_CTRL) = 1;                              //1 seems not have dummy cycle
    REG32(I2C_TXD) = (addr << 8) | (u32)chip | 0x01;

    while (REG32(I2C_MIS) & 0x0f){
        REG32(I2C_ICR) = REG32(I2C_MIS) &0x0f;    //clear interrupt for read
    }

    //Master Receive
    /*Burst Size = 1/2/4/8 words or 4/8/16/32 bytes
    - len <=  4: REG32(0xb6a00030) = len (max = BS) and REG32(0xb6a00088) = 0x21
    - len <=  8: REG32(0xb6a00030) = len (max = BS) and REG32(0xb6a00088) = 0x22
    - len <= 16: REG32(0xb6a00030) = len (max = BS) and REG32(0xb6a00088) = 0x24 (default)
    - len <= 32: REG32(0xb6a00030) = len (max = BS) and REG32(0xb6a00088) = 0x28
    */
    i = 0;
   while (1) {
        if (REG32(I2C_P_IRQSS) & 0x20){                  //NACK
			free(rxword);
            return 1;
        }
        if (REG32(I2C_MIS) & 0x0f){                  //wait for LREQ(<=4) | SREQ(<=8) | LBREQ(<=16) | BREQ(>16)  
            rxword[i++] = REG32(I2C_RXD);
            rxword[i++] = REG32(I2C_RXD);
            rxword[i++] = REG32(I2C_RXD);
            rxword[i++] = REG32(I2C_RXD);
            REG32(I2C_ICR) = REG32(I2C_MIS);      //clear interrupt, do it after 4 words are read
            if (REG32(I2C_RPS_STAT) >= len) {
                break;
            }
        }
    }

    for (i = 0; i < len; i+=4) {
        buf[i] = (u8)(rxword[i/4] & 0xff);
        buf[i+1] = (u8)((rxword[i/4]>>8)&0xff);
        buf[i+2] = (u8)((rxword[i/4]>>16)&0xff);
        buf[i+3] = (u8)((rxword[i/4]>>24)&0xff);
    }

    REG32(I2C_P_IRQSM) &= ~0x30;                     //disable TX_END/NACK int
    REG32(I2C_P_IRQSC) = REG32(I2C_P_IRQSS);          //clear p_ir status
    REG32(I2C_ERR_IRQSC) = REG32(I2C_ERR_IRQSS);          //clear error_ir status
    REG32(I2C_ICR) = REG32(I2C_MIS);          //clear interrupt

	free(rxword);

	return 0;
}

int i2c_write(uchar chip, uint addr, int alen, uchar *buf, int len)
{
	int i, j;
	u8 dummy = 0xff;
	u32 *txword;

	if (len < 1)
		return 1;

	if (!initialized)
		i2c_init(0, 0);

	txword = (u32 *)malloc(len);

	for (i = 0; i < len; i+=4) 
		txword[i/4] = ((u32)buf[i+1]<<24) + ((u32)buf[i]<<16) + ((u32)addr<<8) + (u32)chip;

	txword[0] &= 0xfffffffe;
	REG32(I2C_P_IRQSM) |= 0x30;							//Enable TX_END/NACK int
	j=(len-1)/4;										//OLD: j=(len-1)/4;
	
	hal_i2c_setend(1, 1);								//Send end on PE, and end on NACK

	REG32(I2C_TPS_CTRL) = len + 2; 						// add 2 (chip & address)
	for (i=0; i<=j; i++){
		REG32(I2C_TXD) = txword[i];
		//printf("txword[%d]: 0x%08x\n", i, txword[i]);
	}
	
	while (1){
		i = REG32(I2C_P_IRQSS);
		if (i & 0x30) {
			REG32(I2C_P_IRQSC) = i;
			REG32(I2C_ERR_IRQSC) = REG32(I2C_ERR_IRQSS);		//clear error_ir status
			REG32(I2C_ICR) = REG32(I2C_MIS);		//clear interrupt			
			if (i & 0x10){
				free (txword);
				return 1;
			}
			if (i & 0x20){
				free (txword);
				return 0;
			}
		}
	}		

	return 0;		
}
