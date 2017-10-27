#include <config.h>
#include <common.h>
#include <malloc.h>
#include <net.h>
#include <command.h>

#include "vbg400.h"
#include "miiphy.h"

//#define VBG400_DUMP_REGS

/* PLL2 is out of order.
* When fix, delete this compilation switch and test functionality.
*/
#define VBG400_PLL2_WORKAROUND

//#define VBG400_DEBUG_NET
#ifdef VBG400_DEBUG_NET
#define printf_chip(fmt, args...) do { printf("%s(): ", __func__); printf(fmt, ##args); } while (0)
#else
#define printf_chip(fmt, args...)
#endif

#define DEBUG 0

DECLARE_GLOBAL_DATA_PTR;
#define PATTERN 1540

static uint rxIdx;		/* index of the current RX buffer */
static uint txIdx;		/* index of the current TX buffer */

typedef volatile struct rtxbd {
	DmaDesc txbd[TRANSMIT_DESC_SIZE];
	DmaDesc rxbd[RECEIVE_DESC_SIZE];
} RTXBD;

#ifdef __GNUC__
static RTXBD gmacRtx ;
#else
#error "gmacRtx must be 64-bit aligned"
#endif

static int relocated = 0;
#ifdef VBG400_DUMP_REGS
static void dump_registers(struct tsec_private *priv);
#endif
static struct tsec_private *privlist[4];

static int gmac_send(struct eth_device *dev,
		volatile void *packet, int length);
static int gmac_recv(struct eth_device *dev);
static int gmac_init(struct eth_device *dev, bd_t * bd);
static void gmac_halt(struct eth_device *dev);
static int init_phy(struct eth_device *dev);
void write_phy_reg(struct tsec_private *priv, uint regnum, uint value);
uint read_phy_reg(struct tsec_private *priv, uint regnum);
//#ifndef CONFIG_VBG400_CHIPIT
void write_any_phy_reg(struct tsec_private *priv, uint phyid, uint regnum, uint value);
uint read_any_phy_reg(struct tsec_private *priv, uint phyid, uint regnum);
//#endif
struct phy_info *get_phy_info(struct eth_device *dev);
void phy_run_commands(struct tsec_private *priv, struct phy_cmd *cmd);
static void relocate_cmds(void);
static int gmac_miiphy_write(char *devname, unsigned char addr,
			unsigned char reg, unsigned short value);
static int gmac_miiphy_read(char *devname, unsigned char addr,
			unsigned char reg, unsigned short *value);
#ifdef CONFIG_MCAST_TFTP
static int tsec_mcast_addr (struct eth_device *dev, u8 mcast_mac, u8 set);
#endif
void  synopGMAC_attach (GMACdevice * gmacdev, u32 macBase, u32 dmaBase, u32 phyBase) ;
u32 synopGMAC_set_mac_addr(GMACdevice *gmacdev, u32 MacHigh, u32 MacLow, u8 *MacAddr);
u32 synopGMAC_get_mac_addr(GMACdevice *gmacdev, u32 MacHigh, u32 MacLow, u8 *MacAddr);
s32 synopGMAC_read_version (GMACdevice * gmacdev);
s32 synopGMAC_setup_tx_desc_queue(GMACdevice * gmacdev,u32 no_of_desc);
s32 synopGMAC_setup_rx_desc_queue(GMACdevice * gmacdev,u32 no_of_desc);
void synopGMAC_desc_init_rx_ring(DmaDesc *desc, int last_ring_desc);
void synopGMAC_desc_init_tx_ring(DmaDesc *desc, int last_ring_desc);
s32 synopGMAC_dma_bus_mode_init(GMACdevice * gmacdev, u32 init_value );
s32 synopGMAC_dma_control_init(GMACdevice * gmacdev, u32 init_value);
void synopGMAC_disable_interrupt_all(GMACdevice *gmacdev);
void synopGMAC_init_rx_desc_base(GMACdevice *gmacdev);
void synopGMAC_init_tx_desc_base(GMACdevice *gmacdev);DECLARE_GLOBAL_DATA_PTR;
void synopGMAC_frame_filter_enable(GMACdevice * gmacdev);
s32 synopGMAC_mac_init(GMACdevice * gmacdev);
void synopGMAC_unicast_pause_frame_detect_disable(GMACdevice * gmacdev);
void synopGMAC_select_mii(GMACdevice * gmacdev);
void synopGMAC_tx_enable(GMACdevice * gmacdev);
void synopGMAC_rx_enable(GMACdevice * gmacdev);

void synopGMAC_deferral_check_disable(GMACdevice * gmacdev);
void synopGMAC_back_off_limit(GMACdevice * gmacdev, u32 value);
void synopGMAC_pad_crc_strip_disable(GMACdevice * gmacdev);
void synopGMAC_retry_enable(GMACdevice * gmacdev);
void synopGMAC_set_full_duplex(GMACdevice * gmacdev);
void synopGMAC_loopback_off(GMACdevice * gmacdev);
void synopGMAC_rx_own_enable(GMACdevice * gmacdev);
void synopGMAC_jumbo_frame_disable(GMACdevice * gmacdev);
void synopGMAC_frame_burst_enable(GMACdevice * gmacdev);
void synopGMAC_jab_disable(GMACdevice * gmacdev);
void synopGMAC_tx_flow_control_enable(GMACdevice * gmacdev);
void synopGMAC_rx_flow_control_enable(GMACdevice * gmacdev);
int synopGMAC_is_last_rx_desc(GMACdevice * gmacdev,DmaDesc *desc);
int synopGMAC_is_last_tx_desc(GMACdevice * gmacdev,DmaDesc *desc);
void synopGMAC_resume_dma_tx(GMACdevice * gmacdev);
void synopGMAC_enable_dma_tx(GMACdevice * gmacdev);
void synopGMAC_enable_dma_rx(GMACdevice * gmacdev);
u32 synopGMAC_get_rx_desc_frame_length(u32 status);
int synopGMAC_is_desc_empty(DmaDesc *desc);
int synopGMAC_is_desc_owned_by_dma(DmaDesc *desc);
void synopGMAC_resume_dma_rx(GMACdevice * gmacdev);
s32 synopGMAC_set_rx_qptr(GMACdevice * gmacdev, u32 Buffer1, u32 Length1);
void clear_status_dma (GMACdevice * gmacdev);
s32 synopGMAC_set_tx_qptr(GMACdevice * gmacdev, u32 Buffer1, u32 Length1);
s32 synopGMAC_get_rx_qptr(GMACdevice * gmacdev, u32 * Status, u32 * Buffer1, u32 * Length1);
void synopGMAC_wd_disable(GMACdevice * gmacdev);
void synopGMAC_unicast_hash_filter_disable(GMACdevice * gmacdev);
void synopGMAC_dst_addr_filter_normal(GMACdevice * gmacdev);
void synopGMAC_jab_enable(GMACdevice * gmacdev);
void synopGMAC_set_pass_control(GMACdevice * gmacdev,u32 passcontrol);
void synopGMAC_broadcast_enable(GMACdevice * gmacdev);
void synopGMAC_src_addr_filter_disable(GMACdevice * gmacdev);
void synopGMAC_multicast_disable(GMACdevice * gmacdev);
void synopGMAC_multicast_hash_filter_disable(GMACdevice * gmacdev);
void synopGMAC_promisc_disable(GMACdevice * gmacdev);
s32 synopGMAC_reset (GMACdevice * gmacdev );
int synopGMAC_is_rx_desc_valid(u32 status);
void get_tx_qptr(GMACdevice * gmacdev);
#if 0
void printBDT (void);
void printBDR (void);
#endif
static u8 MacAddr[6];

int get_phy_address(struct tsec_private *priv, unsigned int *phyaddr);

/* #define to provide old read_phy_reg functionality without duplicating code */
#define read_phy_reg(priv,regnum) read_any_phy_reg(priv,priv->phyaddr,regnum)

/* #define to provide old write_phy_reg functionality without duplicating code */
#define write_phy_reg(priv, regnum, value) write_any_phy_reg(priv,priv->phyaddr,regnum,value)

#define PHY_MIPSCR_TXSKEW_MASK 0x00007700
#define PHY_MIPSCR_TXSKEW_DATA 0x00004400

#ifndef CONFIG_VBG400_CHIPIT

/* Below is database that holds the configuration of the 3 NPU Shared IF Registers.
*/

#define _TODO    0   //for compilation, delete after database is completed

/*basic struct to hold data per register*/
typedef struct _gmac_interface {
	u32 gen3_shrd_gmac_mode_reg;
	u32 gen3_shrd_gmac_div_ratio_reg;
	u32 gen3_shrd_gmac_dly_pgm_reg;
}gmac_interface;

/*basic struct to hold mask per register*/
typedef struct _gmac_mask {
	u32 gen3_shrd_gmac_mode_reg_mask;
	u32 gen3_shrd_gmac_div_ratio_reg_mask;
	u32 gen3_shrd_gmac_dly_pgm_reg_mask;
}gmac_mask;

/*gmacx_mask_array*/
gmac_mask  gmac0_mask_array[]=
{
    {GMAC_MODE_REG_GMAC0_MASK},     /*gen3_shrd_gmac_mode_reg_mask     */
    {GMAC_DIV_RATIO_REG_GMAC0_MASK},/*gen3_shrd_gmac_div_ratio_reg_mask*/
    {GMAC_DLY_PGM_REG_GMAC0_MASK}   /*gen3_shrd_gmac_dly_pgm_reg_mask  */
};

gmac_mask  gmac1_mask_array[]=
{
    {GMAC_MODE_REG_GMAC1_MASK},     /*gen3_shrd_gmac_mode_reg_mask     */
    {GMAC_DIV_RATIO_REG_GMAC1_MASK},/*gen3_shrd_gmac_div_ratio_reg_mask*/
    {GMAC_DLY_PGM_REG_GMAC1_MASK}   /*gen3_shrd_gmac_dly_pgm_reg_mask  */
};

/*both normal and revered*/
gmac_mask* interface_mask_array[]=
{
    gmac0_mask_array,
    gmac1_mask_array
};

#define _NULL 0
/*mii_array: 10M 100M*/
gmac_interface mii_array[]=
{
               /* gmac_mode_reg,            gmac_div_ratio_reg,               gmac_dly_pgm_reg*/ 
    /*10M*/  { GMAC_MODE_REG_MII_10M_DATA,  GMAC_DIV_RATIO_REG_MII_10M_DATA,   GMAC_DLY_PGM_REG_MII_10M_DATA},
    /*100M*/ { GMAC_MODE_REG_MII_100M_DATA, GMAC_DIV_RATIO_REG_MII_100M_DATA,  GMAC_DLY_PGM_REG_MII_100M_DATA},
#ifdef VBG400_SEPERATE_MII_GMII
    /*1000M*/{ _NULL,                       _NULL,                             _NULL}
#else
    { GMAC_MODE_REG_GMII_1000M_DATA, GMAC_DIV_RATIO_REG_GMII_1000M_DATA,  GMAC_DLY_PGM_REG_GMII_1000M_DATA} 
#endif
};

gmac_interface mii_array_gmac1[]=
{
    { GMAC_MODE_REG_MII_10M_GMAC1_DATA,  GMAC_DIV_RATIO_REG_MII_10M_GMAC1_DATA,   GMAC_DLY_PGM_REG_MII_10M_GMAC1_DATA},
    { GMAC_MODE_REG_MII_100M_GMAC1_DATA, GMAC_DIV_RATIO_REG_MII_100M_GMAC1_DATA,  GMAC_DLY_PGM_REG_MII_100M_GMAC1_DATA},
#ifdef VBG400_SEPERATE_MII_GMII
    { _NULL,                             _NULL,                                   _NULL}
#else
    { GMAC_MODE_REG_GMII_1000M_GMAC1_DATA, GMAC_DIV_RATIO_REG_GMII_1000M_GMAC1_DATA,  GMAC_DLY_PGM_REG_GMII_1000M_GMAC1_DATA} 
#endif
};

#ifdef VBG400_SEPERATE_MII_GMII
/*gmii_array: 1000M*/
gmac_interface  gmii_array[]=
{
    { _NULL,                          _NULL,                                _NULL},
    { _NULL,                          _NULL,                                _NULL},
    { GMAC_MODE_REG_GMII_1000M_DATA, GMAC_DIV_RATIO_REG_GMII_1000M_DATA,  GMAC_DLY_PGM_REG_GMII_1000M_DATA} 
};

gmac_interface  gmii_array_gmac1[]=
{
    { _NULL,                                _NULL,   _NULL},
    { _NULL,                                _NULL,   _NULL},
    { GMAC_MODE_REG_GMII_1000M_GMAC1_DATA, GMAC_DIV_RATIO_REG_GMII_1000M_GMAC1_DATA,  GMAC_DLY_PGM_REG_GMII_1000M_GMAC1_DATA} 
};
#endif

/*rgmii_array: 10M 100M 1000M*/
gmac_interface  rgmii_array[]=
{
    { GMAC_MODE_REG_RGMII_10M_DATA,   GMAC_DIV_RATIO_REG_RGMII_10M_DATA,   GMAC_DLY_PGM_REG_RGMII_10M_DATA},
    { GMAC_MODE_REG_RGMII_100M_DATA,  GMAC_DIV_RATIO_REG_RGMII_100M_DATA,  GMAC_DLY_PGM_REG_RGMII_100M_DATA},
    { GMAC_MODE_REG_RGMII_1000M_DATA, GMAC_DIV_RATIO_REG_RGMII_1000M_DATA, GMAC_DLY_PGM_REG_RGMII_1000M_DATA} 
};

gmac_interface  rgmii_array_gmac1[]=
{
    { GMAC_MODE_REG_RGMII_10M_GMAC1_DATA,   GMAC_DIV_RATIO_REG_RGMII_10M_GMAC1_DATA,   GMAC_DLY_PGM_REG_RGMII_10M_GMAC1_DATA},
    { GMAC_MODE_REG_RGMII_100M_GMAC1_DATA,  GMAC_DIV_RATIO_REG_RGMII_100M_GMAC1_DATA,  GMAC_DLY_PGM_REG_RGMII_100M_GMAC1_DATA},
    { GMAC_MODE_REG_RGMII_1000M_GMAC1_DATA, GMAC_DIV_RATIO_REG_RGMII_1000M_GMAC1_DATA, GMAC_DLY_PGM_REG_RGMII_1000M_GMAC1_DATA} 
};

/*rmii_array: 10M 100M*/
gmac_interface  rmii_array[]=
{
    { GMAC_MODE_REG_RMII_10M_DATA,  GMAC_DIV_RATIO_REG_RMII_10M_DATA,  GMAC_DLY_PGM_REG_RMII_10M_DATA},
    { GMAC_MODE_REG_RMII_100M_DATA, GMAC_DIV_RATIO_REG_RMII_100M_DATA, GMAC_DLY_PGM_REG_RMII_100M_DATA},
    { _NULL, _NULL, _NULL} 
};

gmac_interface  rmii_array_gmac1[]=
{
    { GMAC_MODE_REG_RMII_10M_GMAC1_DATA,  GMAC_DIV_RATIO_REG_RMII_10M_GMAC1_DATA,  GMAC_DLY_PGM_REG_RMII_10M_GMAC1_DATA},
    { GMAC_MODE_REG_RMII_100M_GMAC1_DATA, GMAC_DIV_RATIO_REG_RMII_100M_GMAC1_DATA, GMAC_DLY_PGM_REG_RMII_100M_GMAC1_DATA},
    { _NULL, _NULL, _NULL} 
};

/******************** Reversed ***************************************************
*/

gmac_interface  mii_array_r[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};

gmac_interface  mii_array_r_gmac1[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};

#ifdef VBG400_SEPERATE_MII_GMII
gmac_interface  gmii_array_r[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};

gmac_interface  gmii_array_r_gmac1[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};
#endif

gmac_interface  rgmii_array_r[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};

gmac_interface  rgmii_array_r_gmac1[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};

gmac_interface  rmii_array_r[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};

gmac_interface  rmii_array_r_gmac1[]=
{
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO},
    { _TODO, _TODO, _TODO} 
};

/*interface array:
*/
gmac_interface* interface_mode_array[]=
{
    mii_array, /*ptr to array*/
#ifdef VBG400_SEPERATE_MII_GMII
    gmii_array,
#endif
    rgmii_array,
    rmii_array,
    mii_array_r,
#ifdef VBG400_SEPERATE_MII_GMII
    gmii_array_r,
#endif
    rgmii_array_r,
    rmii_array_r,
};

gmac_interface* interface_mode_array_gmac1[]=
{
    mii_array_gmac1, /*ptr to array*/
#ifdef VBG400_SEPERATE_MII_GMII
    gmii_array_gmac1,
#endif
    rgmii_array_gmac1,
    rmii_array_gmac1,
    mii_array_r_gmac1,
#ifdef VBG400_SEPERATE_MII_GMII
    gmii_array_r_gmac1,
#endif
    rgmii_array_r_gmac1,
    rmii_array_r_gmac1,
};

enum vbg400_npu_config{
VBG400_PRE_CONFIG,
VBG400_INIT,
VBG400_RUN_TIME
};

extern void ReadModWriteReg(unsigned long , unsigned long , unsigned long, unsigned long );
extern void WriteReg(unsigned long , unsigned long , unsigned long );
extern unsigned long ReadReg (unsigned long , unsigned long  );

void synopGMAC_select_gmii(GMACdevice * gmacdev);
void synopGMAC_select_speed_10(GMACdevice * gmacdev);
void synopGMAC_select_speed_100(GMACdevice * gmacdev);


int data_gmac_mode_2_default=0;

/**********************************************
* clock_delay_calibration - calculate gmac delay calibration and set
*            gmac_dly_pgm reg (gmac0_dly_phy_clk_tx, gmac1_dly_phy_clk_tx fields)
*           It reads the result from gmac_hcycle_calib_indic reg
*  Description:
*  //both GMAC0/GMAC1
*    //write 0x00003131 to addr 0x71c0080 (gmac_mode2_reg, fields gmac0_div_ratio+ gmac1_div_ratio)....
*    //write the sys clock to addr 0x71c0068   (gmac_mode_reg reg val=0xc2844494)....
*    //it sets DLY_PGM_REG with 0x1000100
*    //in a loop it add 0x1000100 every iteration to previous, sets DLY_PGM_REG nd reads calibration result from gmac_hcycle_calib_indic reg
*    //loop stop condition: if calibration results in HCYCLE_CALIB_IND = 0, or loop more than 0x7e times
*    //reset release (val=0x0001fe1f) - TODO readWriteModify and set MACs bit - ? we do it in start.S, to change???
*     * note- tx only need delay adjustment (gmac_dly_pgm_reg: fields gmac0_dly_phy_clk_tx, gmac1_dly_phy_clk_tx)
*     * note- due to some limitation the calc done on 240M clock and then fix value to suit the 125M clock of the MAC
*
*  both GMAC0/GMAC1
*     // return to 125MHz clock config - return to reconfigure gmac_mode_reg according to interface mode and speed, reset the MAC ()
*/
int clock_delay_calibration(int gmac_index)
{
#define GMAC0_SW_RST_N                  0x00000010
#define GMAC1_SW_RST_N                  0x00004000
#define GMAC0_FIX_VALUE                 0x600
#define GMAC1_FIX_VALUE                 0x6000000
#define VBG400_GMAC_MODE_SET_SYS_CLOCK  0xc2844494 //set system clock for test, register changed after delay found
#define DLY_MAC0_PGM_CLK_TX_SHIFT       8
#define DLY_MAC0_PGM_CLK_TX_VAL         0x00000031
#define DLY_MAC1_PGM_CLK_TX_SHIFT       24
#define DLY_MAC1_PGM_CLK_TX_VAL         0x00003100
#define VBG400_USE_FIX_DELAY_VALUE
    int div_ratio[] = {0x00000031,0x00003100};  /*set field gmac0_dly_phy_clk_tx of gmac_dly_pgm_reg*/;
#ifdef VBG400_USE_FIX_DELAY_VALUE
    //int field_value[] = {0xa00,0xa000000};        /*add this value to field gmac0_dly_phy_clk_tx */;
    int field_value[] = {0x300,0x4000000};        /*add this value to field gmac0_dly_phy_clk_tx */;
#else
    int counter = 0;
    int field_value[] = {0x100,0x1000000};        /*add this value to field gmac0_dly_phy_clk_tx */;
    int count_down = 0x7e;
    int hcycle_calib_val;
    int fix_delay[] = {GMAC0_FIX_VALUE, GMAC1_FIX_VALUE};
    u32 reset_mac_mask[] = {GMAC0_SW_RST_N, GMAC1_SW_RST_N};
    u32 reset_reg;
#endif

#ifdef VBG400_DUMP_NPU_DEFAULT
    printf("read default VBG400_GMAC_MODE_REG_OFFSET = 0x%08x\n",ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_GMAC_MODE_REG_OFFSET));
    printf("read default VBG400_GMAC_MODE_2_REG_OFFSET = 0x%08x\n",ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_GMAC_MODE_2_REG_OFFSET));
    printf("read default VBG400_DLY_PGM_REG_OFFSET = 0x%08x\n",ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_DLY_PGM_REG_OFFSET));
#endif
    data_gmac_mode_2_default=ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_GMAC_MODE_2_REG_OFFSET);
    WriteReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_GMAC_MODE_2_REG_OFFSET, div_ratio[gmac_index]);
    WriteReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_GMAC_MODE_REG_OFFSET, VBG400_GMAC_MODE_SET_SYS_CLOCK);

#ifdef VBG400_USE_FIX_DELAY_VALUE
    WriteReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_DLY_PGM_REG_OFFSET, field_value[gmac_index]);
#else
    while(count_down--) {
        counter += field_value[gmac_index];
        WriteReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_DLY_PGM_REG_OFFSET, counter);
        asm("sync");                                
        hcycle_calib_val = ReadReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_HCYCLE_CALIB_IND_REG_OFFSET);
        if (hcycle_calib_val == 0)
            break;
    }
    if (count_down <= 0)
        return -1;
    //fix value by add 6 to it, write to 0x71c0064  ($12 need to add 6 go get 90 degree shift for 150 mhz)
    counter += fix_delay[gmac_index];
    WriteReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_DLY_PGM_REG_OFFSET, counter);
    //reset release
    reset_reg = ReadReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_RESET_OFFSET);
    reset_reg &= (~reset_mac_mask[gmac_index]);
    WriteReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_RESET_OFFSET, reset_reg);
    WriteReg(VBG400_SHARED_GMAC_BASE_ADDR,VBG400_RESET_OFFSET, reset_reg | reset_mac_mask[gmac_index]);
#endif
    return 0;
}

void init_npu_gmac_regs(int interface_mode, int reversed, int gmac_index, int speed, int config)
{
    gmac_interface* interface_mode_ptr;
    gmac_mask* mask_ptr;
    u32 data;
#ifdef VBG400_PLL2_WORKAROUND
    int mac_clock = USE_CLK_OTHER;
#else
    int mac_clock = CONFIG_MAC_DIV_CLOCK;
#endif
#define GMAC_MODE_GMAC0_DIV_CLK_SRC_SEL        0x0000000C
#define GMAC_MODE_GMAC1_DIV_CLK_SRC_SEL        0x000c0000
    int gmac_clk_src_select[2] = {GMAC_MODE_GMAC0_DIV_CLK_SRC_SEL, GMAC_MODE_GMAC1_DIV_CLK_SRC_SEL};
    int gmac_sma_select[2] = {GMAC_MODE_REG_SMA_MASTER_GMAC0_FIELD, GMAC_MODE_REG_SMA_MASTER_GMAC1_FIELD};

    /*point to data of the relevant interface*/
    interface_mode_ptr  = interface_mode_array[interface_mode];
    if (gmac_index == INDEX_GMAC1)
        interface_mode_ptr  = interface_mode_array_gmac1[interface_mode];
    /*point to mask of the relevant gmac*/
    mask_ptr            = interface_mask_array[gmac_index];

    if (config == VBG400_PRE_CONFIG) {
        /*in pre, speed is not known yet. Select 100M*/
        speed = 1;
        printf("In init_npu_gmac_regs: gmac_index = %d, interface_mode = %d, speed = %d, config = %d\n",gmac_index, interface_mode, speed, config);
        /*calculate gmac delay calibration, has to be done before calibration of the system.
        It is becaseu the RGMII is dual clock rate (ddr: data in clock arise and fall)*/
        if (interface_mode == INTERFACE_RGMII/* && speed == SPEED_1000M*/)
            if (clock_delay_calibration(gmac_index) != 0)
                return;
    }
    else {
        if (speed == 10)
            speed = SPEED_10M;
        else if (speed == 100)
            speed = SPEED_100M;
        else
            speed = SPEED_1000M;
        printf("In init_npu_gmac_regs: gmac_index = %d, interface_mode = %d, speed = %d, config = %d\n",gmac_index, interface_mode, speed, config);
    }
    /*GMAC_MODE_REG_ADDR:
    */
    data=ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_GMAC_MODE_REG_OFFSET);
    printf("read VBG400_GMAC_MODE_REG_OFFSET data = 0x%08x\n",data);
    //clean relevant bits, some fields are gmac0/1 related, defaults are needed
    data = data & ~(mask_ptr->gen3_shrd_gmac_mode_reg_mask);
    /*select SMA, if Reversed mode it is overun below*/
    data |= gmac_sma_select[gmac_index];
#ifdef VBG400_SUPPORT_INTERFACE_REVERSED
    /*for reversed mode gmii_r, rgmii_r and rmii_r GMAC1 need to control the sma bus (gmac_sma_lp and gmac1_mstr_sma so): */
    if (reversed && (interface_mode != INTERFACE_MII_GMII_R)) data &= (data & GMAC_MODE_REG_SMA_MASTER_REVERSED_FIELD_MASK) | GMAC_MODE_REG_SMA_MASTER_REVERSED_FIELD;
#endif
    printf("for VBG400_GMAC_MODE_REG_OFFSET, data from DB = 0x%08x\n",(interface_mode_ptr + speed)->gen3_shrd_gmac_mode_reg);
    //or with data
    data = data | (interface_mode_ptr + speed)->gen3_shrd_gmac_mode_reg;
    //if PLL2 is configured set the coresponding bits (the data is already set for the GMII that request PLL2 always)
    if (mac_clock == USE_CLK_PLL2)
        data |= gmac_clk_src_select[gmac_index];
    printf("write VBG400_GMAC_MODE_REG_OFFSET data = 0x%08x\n",data);
    WriteReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_GMAC_MODE_REG_OFFSET, data);


    if (config == VBG400_RUN_TIME) {
        /*GMAC_DIV_RATIO_REG_ADDR:
        */
        /*use the default value*/
        data=data_gmac_mode_2_default/*ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_GMAC_MODE_2_REG_OFFSET)*/;
        printf("read VBG400_GMAC_MODE_2_REG_OFFSET data = 0x%08x\n",data);
        //clean relevant bits, some fields are gmac0/1 related, defaults are needed
        data = data & ~(mask_ptr->gen3_shrd_gmac_div_ratio_reg_mask);
        printf("init_npu_gmac_regs: for GMAC_DIV_RATIO_REG_ADDR, data from DB = 0x%08x\n",(interface_mode_ptr + speed)->gen3_shrd_gmac_div_ratio_reg);
        //or with data
        data = data | (interface_mode_ptr + speed)->gen3_shrd_gmac_div_ratio_reg;
        printf("write VBG400_GMAC_MODE_2_REG_OFFSET data = 0x%08x\n",data);
        WriteReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_GMAC_MODE_2_REG_OFFSET, data);

        /*GMAC_DLY_PGM_REG_ADDR:
        */
        if (interface_mode != INTERFACE_RGMII/* && speed ....? SPEED_1000M*/)
        {
            data=ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_DLY_PGM_REG_OFFSET);
            printf("read VBG400_DLY_PGM_REG_OFFSET data = 0x%08x\n",data);
            //clean relevant bits, some fields are gmac0/1 related, defaults are needed
            data = data & ~(mask_ptr->gen3_shrd_gmac_dly_pgm_reg_mask);
            printf("init_npu_gmac_regs: for GMAC_DLY_PGM_REG_ADDR, data from DB = 0x%08x\n",(interface_mode_ptr + speed)->gen3_shrd_gmac_dly_pgm_reg);
            //or with data
            /* For fields gmac0_dly_phy_clk_tx/gmac1_dly_phy_clk_tx value already in place, don't overun.
               For clk_rx value is not important (use default)*/
            data = data | (interface_mode_ptr + speed)->gen3_shrd_gmac_dly_pgm_reg;
            printf("write VBG400_DLY_PGM_REG_OFFSET data = 0x%08x\n",data);
            WriteReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_DLY_PGM_REG_OFFSET, data);
        }
        else {
            printf("read VBG400_DLY_PGM_REG_OFFSET data = 0x%lx\n",ReadReg(VBG400_SHARED_GMAC_BASE_ADDR, VBG400_DLY_PGM_REG_OFFSET));
        }
    }
}

#ifndef VBG400_PLL2_WORKAROUND
//PLL2 not working at the moment
int init_npu_pll2_regs(int interface_mode, int reversed, int gmac_index, int speed)
{
    u32 data_ctrl, data_stat, i=0;
    int ret_value;

#define VBG400_PLL2_CTL_OFFSET                      0x48
#define VBG400_PLL2_LOCK_OFFSET                     0x4C
#define VBG400_PLL2_CTL_PUP_D2A_FIELD               0x100
#define VBG400_PLL2_CTL_RSTQ_D2A_FIELD              0x200
#define VBG400_PLL2_CTL_GMAC_CLK_ENABLE_D2A_FIELD   0x8000
#define VBG400_PLL2_CTL_GMAC_CLK_DIV_25MHZ_D2A      1
#define VBG400_PLL2_CTL_GMAC_CLK_DIV_50MHZ_D2A      2
#define VBG400_PLL2_CTL_GMAC_CLK_DIV_125MHZ_D2A     3
#define VBG400_PLL2_CTL_GMAC_CLK_DIV_D2A_SHIFT      15

    data_ctrl=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_PLL2_CTL_OFFSET);
    printf_chip("read VBG400_PLL2_CTL_OFFSET data_ctrl = 0x%08x\n",data_ctrl);
    if ((data_ctrl & VBG400_PLL2_CTL_PUP_D2A_FIELD) && (data_ctrl & VBG400_PLL2_CTL_RSTQ_D2A_FIELD))
    {
        printf_chip("PLL2 already set\n");
        ret_value = 0;
    }
    else
    {
        ret_value = 0;
        data_ctrl = data_ctrl | (VBG400_PLL2_CTL_PUP_D2A_FIELD | VBG400_PLL2_CTL_RSTQ_D2A_FIELD);
        WriteReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_PLL2_CTL_OFFSET, data_ctrl);
        // wait for lock indication
        data_stat=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_PLL2_LOCK_OFFSET);
        while (data_stat == 0 && i < 10)
        {
            __udelay(1);	/* 1 micro delay */
            data_stat=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_PLL2_LOCK_OFFSET);
            i++;
        }
        if (i >= 5)
        {
            printf("Error in PLL2 lock\n");
            ret_value = -1;
        }
    }
    // CONFIGURE PLL2 FOR GMAC PURPOSES
    data_ctrl |= VBG400_PLL2_CTL_GMAC_CLK_ENABLE_D2A_FIELD;
    if((interface_mode==INTERFACE_RGMII) && (!((reversed==MAC_REVERSED) && (gmac_index = INDEX_GMAC0))) )
        data_ctrl |= (VBG400_PLL2_CTL_GMAC_CLK_DIV_125MHZ_D2A << VBG400_PLL2_CTL_GMAC_CLK_DIV_D2A_SHIFT); 
    else
    {
        if (speed == SPEED_1000M)
            data_ctrl |= (VBG400_PLL2_CTL_GMAC_CLK_DIV_125MHZ_D2A << VBG400_PLL2_CTL_GMAC_CLK_DIV_D2A_SHIFT); 
        if (interface_mode==INTERFACE_RMII)
            data_ctrl |= (VBG400_PLL2_CTL_GMAC_CLK_DIV_50MHZ_D2A << VBG400_PLL2_CTL_GMAC_CLK_DIV_D2A_SHIFT); 
        else
            data_ctrl |= (VBG400_PLL2_CTL_GMAC_CLK_DIV_25MHZ_D2A << VBG400_PLL2_CTL_GMAC_CLK_DIV_D2A_SHIFT); 
    }

    WriteReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_PLL2_CTL_OFFSET, data_ctrl);
    
    return ret_value;
}
#endif
#endif

int vbg400_switch_initialize(bd_t * bis)
{
	struct eth_device *dev;
	int i;
	struct tsec_private *priv;
	volatile GMACdevice *gmacdev ;
    u32 dmaBase;
#ifndef CONFIG_VBG400_CHIPIT
    int reversed = CONFIG_MAC_MODE_REVERSED;        //0=normal, 1=reversed
    int interface_mode = CONFIG_VBG400_MAC_INTERFACE_MODE; //interface_mode - 0=mii/gmii, 1=rgmii, 2=rmii 3=mii_r/gmii_r, 4=rgmii_r, 5=rmii_r
    int gmac_index = CONFIG_VBG400_MAC_GMAC_INDEX;         //0=GMAC0 1=GMAC1
#endif
    int retValue = 1;
    uint data;

    printf_chip("In vbg400_switch_initialize\n");
    //printf("** WORK GMAC %d **\n",gmac_index);

#ifdef VBG400_SUPPORT_INTERFACE_REVERSED
    /* In reversed mode the use of two devices is required.
    *  This is not supported yet.
    *  One is to support the reversed mode, the other is to give the SMA bus control.
    *  Open: What does it take to use the second MAC for the SMA bus access? Some steps are obvious, what more(?):
    *   * release reset
    *   * config Shared registerss
    *       * gen3_shrd_gmac_mode_reg field gmac1_mstr_sma
    *       * ? (what else?)
    *   * config phyregsSmaMaster with the master MAC address
    */
#endif

	dev = (struct eth_device *)malloc(sizeof (*dev));

	if (NULL == dev)
		return 0;

	memset(dev, 0, sizeof *dev);
	priv = (struct tsec_private *)malloc(sizeof(*priv));

	if (NULL == priv)
		return 0;

	memset(priv, 0, sizeof (*priv));
	privlist[0] = priv;

	gmacdev = (volatile GMACdevice *) malloc (sizeof (*gmacdev));
	if (NULL == gmacdev)
		return 0;

	priv->gmacRegs = (volatile GMACdevice *) gmacdev;
	memset((GMACdevice *) gmacdev, 0, sizeof (*gmacdev));

    /*default is GMAC0, change if GMAC1 is used*/
    priv->phyregs = (volatile gphy_t *)(GMAC_BASE_ADDR);
    dmaBase = GMAC_DMA_BASE;
#ifndef CONFIG_VBG400_CHIPIT
    priv->phyregsSmaMaster =  (volatile gphy_t *) (GMAC_BASE_ADDR);
    if (gmac_index == INDEX_GMAC1)
    {
        priv->phyregs = (volatile gphy_t *)(GMAC_BASE_ADDR_GMAC1);
        priv->phyregsSmaMaster = (volatile gphy_t *) (GMAC_BASE_ADDR_GMAC1);
        dmaBase = GMAC_DMA_BASE_GMAC1;
    }
    printf_chip("vbg400_switch_initialize: priv->phyregsSmaMaster = 0x%08x\n",priv->phyregsSmaMaster);

    /*configure interface mode in the NPU shared registers */
    init_npu_gmac_regs(interface_mode, reversed, gmac_index, priv->speed, VBG400_PRE_CONFIG);
    priv->phyaddr = CONFIG_VBG400_PHY_ADDR_GMAC_0;    
    if (gmac_index == INDEX_GMAC1)
        priv->phyaddr = CONFIG_VBG400_PHY_ADDR_GMAC_1;    
    printf_chip("call get_phy_address with phyaddr %d\n",priv->phyaddr);
#endif
    if (get_phy_address(priv, &priv->phyaddr) < 0)
    {
        printf("error in get_phy_address, set default\n");
        priv->phyaddr = GMAC_DEFAULT_PHY_ADRS;
    }
    printf_chip("vbg400_switch_initialize: priv->phyaddr = 0x%08x\n",priv->phyaddr);
    synopGMAC_attach (( GMACdevice *) gmacdev, (u32)priv->phyregs, dmaBase, (u32) priv->phyaddr) ;

#ifdef VBG400_SUPPORT_INTERFACE_REVERSED
//TODO: in reverse mode need to set phyregsSmaMaster with GMAC1
#endif

    /*Lets read the version of ip in to device structure*/	
	synopGMAC_read_version((GMACdevice *) gmacdev); 

	synopGMAC_get_mac_addr((GMACdevice *) gmacdev,(u32) GmacAddr0High,(u32) GmacAddr0Low, (u8 *) &MacAddr); 
	/*Now set the broadcast address*/	
	for(i = 0; i <6; i++){
		priv->broadcast[i] = 0xff;
	}

	priv->flags = 0;

	sprintf(dev->name, "VBG400_SW");

	dev->iobase = 0;
	dev->priv = priv;
	dev->init = gmac_init;
	dev->halt = gmac_halt;
	dev->send = gmac_send;
	dev->recv = gmac_recv;

#ifdef CONFIG_MCAST_TFTP
	dev->mcast = tsec_mcast_addr;
#endif

	/* Tell u-boot to get the addr from the env */
	for (i = 0; i < 6; i++)
		dev->enetaddr[i] = 0;

	eth_register(dev);

	/* Reset the PHY */

	miiphy_init();

	miiphy_register(dev->name, gmac_miiphy_read, gmac_miiphy_write);

	/* Try to initialize PHY here, and return.
	* init_phy() for 11G PHY does not reset the PHY, therefore we reset before call */

    data=read_phy_reg(priv, PHY_BMCR);
    data |= PHY_BMCR_RESET;
    write_phy_reg(priv, PHY_BMCR, data);

	retValue = init_phy(dev);

    return retValue;
}



#ifndef CONFIG_VBG400_CHIPIT
void gmac_reset_phy_set_skew(struct eth_device *dev)
{
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
    int data;

    /* phy_info struct does not reset the 11G PHY.
    *  Therefore reset the PHY is done prior to init_phy().
    * Also, add configuration of TXSKEW
    */
    data=read_phy_reg(priv, PHY_BMCR);
    printf_chip("gmac_reset_phy_set_skew: read PHY_BMCR data = 0x%08x\n",data);
    data |= PHY_BMCR_RESET;
    printf_chip("gmac_reset_phy_set_skew: (reset phy) write PHY_BMCR data = 0x%08x\n",data);
    write_phy_reg(priv, PHY_BMCR, data);

	init_phy(dev);
#if 0
/* skew is already in GPHY - add to any new phy !*/
    data=read_phy_reg(priv, PHY_LBR);
    printf_chip("gmac_reset_phy_set_skew: read PHY_LBR data = 0x%08x\n",data);
    data &= ~(PHY_MIPSCR_TXSKEW_MASK);
    data |= PHY_MIPSCR_TXSKEW_DATA;
    write_phy_reg(priv, PHY_LBR, data);
    data=0;
    data=read_phy_reg(priv, PHY_LBR);
    printf_chip("gmac_reset_phy_set_skew: verify write PHY_LBR data = 0x%08x\n",data);
#endif
	if (priv->link == 0) {
        printf("gmac_reset_phy_set_skew: priv->link == 0, return -1\n");
	    return;
    }
}


void gmac_set_phy_clksel_and_skew(struct eth_device *dev, int interface_mode)
{
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
    int data;
    int gmac_index = CONFIG_VBG400_MAC_GMAC_INDEX;         //0=GMAC0 1=GMAC1

    if (interface_mode == INTERFACE_RGMII) //for all speeds 
    {
        printf_chip("gmac_set_phy_clksel_and_skew: set MIIM_PHYCTL2 bit 10 for clock 125MHz\n");
        //set clock in Reg 0x14 bit CLKSEL
#ifdef VBG400_PLL2_WORKAROUND
#define VBG400_GMAC0_PHY    0
        //gmac0 sma master
        data = read_any_phy_reg(priv, VBG400_GMAC0_PHY, MIIM_PHYCTL2);
        printf_chip("gmac_set_phy_clksel_and_skew: read data = 0x%08x\n",data);
        data |= MIIM_PHYCTL2_CLKSEL;
        printf_chip("gmac_set_phy_clksel_and_skew: write data = 0x%08x\n",data);
        write_any_phy_reg(priv, VBG400_GMAC0_PHY, MIIM_PHYCTL2, data);
        if (gmac_index == INDEX_GMAC1) {
            /*force autoneg on gmac0 in order to have change take action.
            * if it is gmac0, autoneg would be follow later
            */
            write_any_phy_reg(priv, VBG400_GMAC0_PHY, PHY_BMCR, PHY_BMCR_RST_NEG|PHY_BMCR_AUTON);
        }
        /* Do also for gmac 1.
        * TODO: write clock can be deleted when pll2 is working !?
        */
        data = read_phy_reg(priv, MIIM_PHYCTL2);
        printf_chip("gmac_set_phy_clksel_and_skew: data = 0x%08x\n",data);
        data |= MIIM_PHYCTL2_CLKSEL;
        write_phy_reg(priv, MIIM_PHYCTL2, data);
#endif
    }
    else
        printf_chip("gmac_set_phy_clksel_and_skew: not INTERFACE_RGMII\n");
    /*Force Autoneg*/
	init_phy(dev);
}
#endif


/* Initializes data structures and registers for the controller 
* (the values for DMA registers was taken from VLSI simmulation tests),
* and brings the interface up.	 Returns the link status, meaning
* that it returns success if the link is up, failure otherwise.
* This allows u-boot to find the first active controller.
*/
int gmac_init(struct eth_device *dev, bd_t * bd)
{
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
	volatile GMACdevice *gmacdev = priv->gmacRegs;
	s32 status, indx ;
	uint addr;
#ifndef CONFIG_VBG400_CHIPIT
    int reversed = CONFIG_MAC_MODE_REVERSED;        //0=normal, 1=reversed
    int interface_mode = CONFIG_VBG400_MAC_INTERFACE_MODE; //interface_mode - 0=mii/gmii, 1=rgmii, 2=rmii 3=mii_r/gmii_r, 4=rgmii_r, 5=rmii_r
    int gmac_index = CONFIG_VBG400_MAC_GMAC_INDEX;         //0=GMAC0 1=GMAC1
    int speed;
#ifndef VBG400_PLL2_WORKAROUND
    //PLL2 not working at the moment
    int mac_clock = CONFIG_MAC_DIV_CLOCK;
#endif
#endif

    printf_chip("In gmac_init: interface_mode=%d, gmac_index=%d\n",interface_mode,gmac_index);

#ifndef CONFIG_VBG400_CHIPIT
    gmac_reset_phy_set_skew(dev);
    //reconfig shared regs after autoneg (speed is known after phy Init)
    init_npu_gmac_regs(interface_mode, reversed, gmac_index, priv->speed, VBG400_RUN_TIME);
    /*In case there is no external clock in the GMAC need to configure PLL2*/
#ifndef VBG400_PLL2_WORKAROUND
    //PLL2 not working at the moment
    if (mac_clock == USE_CLK_PLL2 ||
        (interface_mode == INTERFACE_MII_GMII && priv->speed == SPEED_1000M)
#ifdef VBG400_SUPPORT_INTERFACE_REVERSED
        reversed == MAC_REVERSED
#endif
        )
        if (init_npu_pll2_regs(interface_mode, reversed, gmac_index, priv->speed) != 0)
	        return -1;
#endif //VBG400_PLL2_WORKAROUND
#endif //CONFIG_VBG400_CHIPIT

	/* reset the indices to zero */
	rxIdx = 0;
	txIdx = 0;

	synopGMAC_reset((GMACdevice *) gmacdev);
    printf_chip("TRANSMIT_DESC_SIZE=%d, RECEIVE_DESC_SIZE=%d\n",TRANSMIT_DESC_SIZE,RECEIVE_DESC_SIZE);
    /*Set up the tx and rx descriptor queue/ring*/
	synopGMAC_setup_tx_desc_queue((GMACdevice *) gmacdev,TRANSMIT_DESC_SIZE);
	synopGMAC_setup_rx_desc_queue((GMACdevice *) gmacdev,RECEIVE_DESC_SIZE );
    //printf("gmac_init: setup %d rx descriptors, %d tx descriptors\n", RECEIVE_DESC_SIZE, TRANSMIT_DESC_SIZE);
	synopGMAC_dma_bus_mode_init((GMACdevice *)gmacdev, DmaUseSeparatePBL|DmaRxBurstLength8|DmaBurstLength1 );
	synopGMAC_dma_control_init((GMACdevice *)gmacdev, DmaStoreAndForward|DmaDisableDropTcpCs|DmaDisablFlushFrames);
	synopGMAC_disable_interrupt_all((GMACdevice *)gmacdev);

    //Program the transmit descriptor base address in to DmaTxBase addr	
	synopGMAC_init_rx_desc_base ((GMACdevice *)gmacdev);
	synopGMAC_init_tx_desc_base ((GMACdevice *)gmacdev);
	
	synopGMAC_mac_init ((GMACdevice *)gmacdev);
#ifndef CONFIG_VBG400_CHIPIT
    if (priv->speed == 10)
        speed = SPEED_10M;
    else if (priv->speed == 100)
        speed = SPEED_100M;
    else
        speed = SPEED_1000M;
    /* Some configurations are interface mode related.
       In "MAC Configuration Register" handle bits 14+15 and 24
       TODO: what about interrupts ? ("	GMAC Register 15 bit 0, ) */
    if (interface_mode == INTERFACE_MII_GMII)
    {
        /*config speed (10/100=MII, 1000=GMII)
         */
        if (speed == SPEED_1000M) {
            printf_chip("clear bit 15 in control reg, SPEED_1000M\n");
            synopGMAC_select_gmii((GMACdevice *)gmacdev);
        }
    } else if (interface_mode == INTERFACE_RMII || interface_mode == INTERFACE_RGMII)
    {
        printf_chip("set/clear bit 15 in control reg, speed = %d\n",priv->speed);
        if (speed == SPEED_10M)
            synopGMAC_select_speed_10((GMACdevice *)gmacdev);
        else if (speed == SPEED_100M)
            synopGMAC_select_speed_100((GMACdevice *)gmacdev);
        else {
            printf_chip("clear bit 15 in control reg\n");
            synopGMAC_select_gmii((GMACdevice *)gmacdev);
        }
    }
#endif
	indx = 0;
	do{
		addr = (uint ) NetRxPackets[indx++];
		status = synopGMAC_set_rx_qptr((GMACdevice *) gmacdev,(uint) addr, PATTERN);
	}while(status < RECEIVE_DESC_SIZE -1 );

    /* TO DO Timer unplug */

	/*Enter run state for both mode*/
	synopGMAC_enable_dma_tx((GMACdevice *) gmacdev);
	synopGMAC_enable_dma_rx((GMACdevice *) gmacdev);

#ifndef CONFIG_VBG400_CHIPIT
    gmac_set_phy_clksel_and_skew(dev, interface_mode);
#ifdef VBG400_DUMP_REGS
    dump_registers(priv);
#endif
#else
#ifdef VBG400_DUMP_REGS
    dump_registers(priv);
#endif
	init_phy(dev);
#endif

	if (priv->link == 0)	printf ("No link\n");
	return (priv->link ? 0 : -1);
}

/*
  * Populate the tx desc structure with the buffer address.
  * Once the driver has a packet ready to be transmitted, this function is called with the
  * valid dma-able buffer addresses and their lengths. This function populates the descriptor
  * and make the DMA the owner for the descriptor. This function also controls whetther Checksum
  * offloading to be done in hardware or not.
  * This api is same for both ring mode and chain mode.
  * @param[in] pointer to synopGMACdevice.
  * @param[in] Dma-able buffer1 pointer.
  * @param[in] length of buffer1 (Max is 2048).
  * @param[in] virtual pointer for buffer1.
  * @param[in] Dma-able buffer2 pointer.
  * @param[in] length of buffer2 (Max is 2048).
  * @param[in] virtual pointer for buffer2.
  * @param[in] u32 data indicating whether the descriptor is in ring mode or chain mode.
  * @param[in] u32 indicating whether the checksum offloading in HW/SW.
  * \return returns present tx descriptor index on success. Negative value if error.
  */
s32 synopGMAC_set_tx_qptr(GMACdevice * gmacdev, u32 Buffer1, u32 Length1)
{
        u32  txnext      = gmacdev->TxNext;
        DmaDesc * txdesc = gmacdev->TxNextDesc;

        if(!synopGMAC_is_desc_empty(txdesc))  {
//		printf ("ERROR synopGMAC_set_tx_qptr\n");
//                return -1;

	}
	
       txdesc->length |= (((Length1 <<DescSize1Shift) & DescSize1Mask) );
#ifdef SYNOP_GMAC_ENHANCED_DESCRIPTOR
       /* End of ring bit in last descriptor of the ring is set during init stage - don't overrun it! */
       txdesc->status = synopGMAC_is_last_tx_desc(gmacdev,txdesc) ? (DescTxEndOfRing | DescTxFirst | DescTxLast) : (DescTxFirst | DescTxLast); 
#else
       txdesc->status = 0;
       txdesc->length |=  (DescTxFirst | DescTxLast ); 
       /* End of ring bit in last descriptor of the ring is set only once during init stage */
#endif
        //Its always assumed that complete data will fit in to one descriptor

        txdesc->buffer1 = Buffer1;
        txdesc->buffer2 = 0;
        //printf("synopGMAC_set_tx_qptr: tx_desc[%d] length = 0x%lx, descr = %x status=0x%x, Buffer1=0x%lx Buffer2=0x%lx \n",gmacdev->TxNext, txdesc->length, txdesc,  txdesc->status, txdesc->buffer1, txdesc->buffer2);

        txdesc->status |= DescOwnByDma;
        gmacdev->TxNext = synopGMAC_is_last_tx_desc(gmacdev,txdesc) ? 0 : txnext + 1;
        gmacdev->TxNextDesc = synopGMAC_is_last_tx_desc(gmacdev,txdesc) ? gmacdev->TxDesc : (txdesc + 1);
        printf_chip("synopGMAC_set_tx_qptr: in txdesc - length=0x%08x, buffer1=0x%08x, buffer2=0x%08x, status=0x%08x\n",txdesc->length,txdesc->buffer1,txdesc->buffer2,txdesc->status);
       
	return txnext;
}


/*
  * Prepares the descriptor to receive packets.
  * The descriptor is allocated with the valid buffer addresses (sk_buff address) and the length fields
  * and handed over to DMA by setting the ownership. After successful return from this function the
  * descriptor is added to the receive descriptor pool/queue.
  * This api is same for both ring mode and chain mode.
  * @param[in] pointer to synopGMACdevice.
  * @param[in] Dma-able buffer1 pointer.
  * @param[in] length of buffer1 (Max is 2048).
  * @param[in] Dma-able buffer2 pointer.
  * @param[in] length of buffer2 (Max is 2048).
  * @param[in] u32 data indicating whether the descriptor is in ring mode or chain mode.
  * \return returns present rx descriptor index on success. Negative value if error.
  */
s32 synopGMAC_set_rx_qptr(GMACdevice * gmacdev, u32 Buffer1, u32 Length1)
{
    u32  rxnext      = gmacdev->RxNext;
    DmaDesc * rxdesc = gmacdev->RxNextDesc;

    if(!synopGMAC_is_desc_empty(rxdesc)) {
        printf_chip ("Rx desc empty, rxdesc->length: %x\n", rxdesc->length);
        return -1;
    }

    rxdesc->length |= (((Length1 <<DescSize1Shift) & DescSize1Mask));

    rxdesc->buffer1 = virt_to_phys(Buffer1);

    rxdesc->status = DescOwnByDma;

    gmacdev->RxNext     = synopGMAC_is_last_rx_desc(gmacdev,rxdesc) ? 0 : rxnext + 1;
    gmacdev->RxNextDesc = synopGMAC_is_last_rx_desc(gmacdev,rxdesc) ? gmacdev->RxDesc : (rxdesc + 1);
    printf_chip("synopGMAC_set_rx_qptr: in rxdesc - length=0x%08x, buffer1=0x%08x, status=0x%08x\n",rxdesc->length,rxdesc->buffer1,rxdesc->status);

    return rxnext ;
}


/**
  * Get back the descriptor from DMA after data has been received.
  * When the DMA indicates that the data is received (interrupt is generated), this function should be
  * called to get the descriptor and hence the data buffers received. With successful return from this
  * function caller gets the descriptor fields for processing. check the parameters to understand the
  * fields returned.`
  * @param[in] pointer to synopGMACdevice.
  * @param[out] pointer to hold the status of DMA.
  * @param[out] Dma-able buffer1 pointer.
  * @param[out] pointer to hold length of buffer1 (Max is 2048).
  * @param[out] virtual pointer for buffer1.
  * @param[out] Dma-able buffer2 pointer.
  * @param[out] pointer to hold length of buffer2 (Max is 2048).
  * @param[out] virtual pointer for buffer2.
  * \return 0 upon success. Error code upon failure.
  */
s32 synopGMAC_get_rx_qptr(GMACdevice * gmacdev, u32 * Status, u32 * Buffer1, u32 * Length1)
{
    u32 rxnext       = gmacdev->RxBusy;     
    DmaDesc * rxdesc = gmacdev->RxBusyDesc;

    //printf ("synopGMAC_get_rx_qptr: treating descriptor 0x%lx [%d], status set to 0x%x, length=0x%x\n", rxdesc,  rxnext, rxdesc->status, rxdesc->length);
    if(synopGMAC_is_desc_owned_by_dma(rxdesc)) {
        //printf ("G-ERROR desc_owned_by_dma\n");
        return -1;
    }

    if(synopGMAC_is_desc_empty(rxdesc)) {
		printf_chip ("Rx desc empty, rxdesc->length: %x\n", rxdesc->length);
        return -1;
	}

    if(Status != 0)
        *Status = rxdesc->status;// send the status of this descriptor

    if(Length1 != 0)
        *Length1 = (rxdesc->length & DescSize1Mask) >> DescSize1Shift;
    if(Buffer1 != 0)
        *Buffer1 = rxdesc->buffer1;

    gmacdev->RxBusy     = synopGMAC_is_last_rx_desc(gmacdev,rxdesc) ? 0 : rxnext + 1;
    gmacdev->RxBusyDesc = synopGMAC_is_last_rx_desc(gmacdev,rxdesc) ? gmacdev->RxDesc : (rxdesc + 1);
    synopGMAC_desc_init_rx_ring(rxdesc, synopGMAC_is_last_rx_desc(gmacdev,rxdesc));

    return(rxnext);
}

void get_tx_qptr(GMACdevice * gmacdev)
{
        u32 txnext       = gmacdev->TxBusy;
        DmaDesc * txdesc = gmacdev->TxBusyDesc;

        gmacdev->TxBusy     = synopGMAC_is_last_tx_desc(gmacdev,txdesc) ? 0 : txnext + 1;
	gmacdev->TxBusyDesc = synopGMAC_is_last_tx_desc(gmacdev,txdesc) ? gmacdev->TxDesc : (txdesc + 1);
	txdesc = gmacdev->TxBusyDesc;
	txdesc->length = 0;
}


/**
  * Example mac initialization sequence (taken from VLSI simmulation tests)
  * This function calls the initialization routines to initialize the GMAC register.
  * One can change the functions invoked here to have different configuration as per the requirement
  * @param[in] pointer to synopGMACdevice.
  * \return Returns 0 on success.
  */
s32 synopGMAC_mac_init(GMACdevice * gmacdev)
{
                synopGMAC_wd_disable(gmacdev);
                synopGMAC_jab_enable(gmacdev);
                //synopGMAC_frame_burst_enable(gmacdev);
                synopGMAC_jumbo_frame_disable(gmacdev);
                synopGMAC_rx_own_enable(gmacdev);
                synopGMAC_loopback_off(gmacdev);
                synopGMAC_set_full_duplex(gmacdev);
                synopGMAC_retry_enable(gmacdev);
                synopGMAC_pad_crc_strip_disable(gmacdev);
                //synopGMAC_back_off_limit(gmacdev,GmacBackoffLimit0);
                synopGMAC_deferral_check_disable(gmacdev);
                synopGMAC_tx_enable(gmacdev);
                synopGMAC_rx_enable(gmacdev);
                synopGMAC_select_mii(gmacdev);

                /*Frame Filter Configuration*/
                synopGMAC_frame_filter_enable(gmacdev);
                //synopGMAC_set_pass_control(gmacdev,GmacPassControl0);
                //synopGMAC_broadcast_enable(gmacdev);
                //synopGMAC_src_addr_filter_disable(gmacdev);
                //synopGMAC_multicast_disable(gmacdev);
                //synopGMAC_dst_addr_filter_normal(gmacdev);
                //synopGMAC_multicast_hash_filter_disable(gmacdev);
                //synopGMAC_promisc_disable(gmacdev);
                //synopGMAC_unicast_hash_filter_disable(gmacdev);

                /*Flow Control Configuration*/
                synopGMAC_unicast_pause_frame_detect_disable(gmacdev);
                synopGMAC_rx_flow_control_enable(gmacdev);
                synopGMAC_tx_flow_control_enable(gmacdev);

	return 0;
}


/*Receive frame filter configuration functions*/

/*
  * Enables reception of all the frames to application.
  * GMAC passes all the frames received to application irrespective of whether they
  * pass SA/DA address filtering or not.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_frame_filter_enable(GMACdevice * gmacdev)
{	
	synopGMACSetBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacFilter);
        return;
}


/**
  * Programs the DmaRxBaseAddress with the Rx descriptor base address.
  * Rx Descriptor's base address is available in the gmacdev structure. This function progrms the * Dma Rx Base address with the starting address of the descriptor ring or chain.
  * @param[in] pointer to synopGMACdevice.
  * \return returns void.
  */
void synopGMAC_init_rx_desc_base(GMACdevice *gmacdev)
{
        printf_chip("synopGMAC_init_rx_desc_base: DmaRxBaseAddr(RxDescDma) = 0x%08x\n",(u32)gmacdev->RxDescDma);
        synopGMACWriteReg((u32 *)gmacdev->DmaBase,DmaRxBaseAddr,(u32)gmacdev->RxDescDma);
        return;
}

/**
  * Programs the DmaTxBaseAddress with the Tx descriptor base address.
  * Tx Descriptor's base address is available in the gmacdev structure. This function progrms the
  * Dma Tx Base address with the starting address of the descriptor ring or chain.
  * @param[in] pointer to synopGMACdevice.
  * \return returns void.
  */
void synopGMAC_init_tx_desc_base(GMACdevice *gmacdev)
{
        printf_chip("synopGMAC_init_rx_desc_base: DmaTxBaseAddr(TxDescDma) = 0x%08x\n",(u32)gmacdev->TxDescDma);
        synopGMACWriteReg((u32 *)gmacdev->DmaBase,DmaTxBaseAddr,(u32)gmacdev->TxDescDma);
        return;
}


/*
  * Function to program DMA bus mode register.
  *
  * The Bus Mode register is programmed with the value given. The bits to be set are
  * bit wise or'ed and sent as the second argument to this function.
  * @param[in] pointer to synopGMACdevice.
  * @param[in] the data to be programmed.
  * \return 0 on success else return the error status.
  */
s32 synopGMAC_dma_bus_mode_init(GMACdevice * gmacdev, u32 init_value )
{ 
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaBusMode ,init_value);
        return 0;

}

/*
  * Function to program DMA Control register.
  *
  * The Dma Control register is programmed with the value given. The bits to be set are
  * bit wise or'ed and sent as the second argument to this function.
  * @param[in] pointer to synopGMACdevice.
  * @param[in] the data to be programmed.
  * \return 0 on success else return the error status.
  */
s32 synopGMAC_dma_control_init(GMACdevice * gmacdev, u32 init_value)
{
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaControl, init_value);
        return 0;
}

/**
  * Disable all the interrupts.
  * Disables all DMA interrupts.
  * @param[in] pointer to synopGMACdevice.
  * \return returns void.
  * \note This function disabled all the interrupts, if you want to disable a particular interrupt then
  *  use synopGMAC_disable_interrupt().
  */
void synopGMAC_disable_interrupt_all(GMACdevice *gmacdev)
{
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaInterrupt, DmaIntDisable);
        return;
}

/**
  * This sets up the receive Descriptor queue in ring or chain mode.
  * This function is tightly coupled to the platform and operating system
  * Device is interested only after the descriptors are setup. Therefore this function
  * is not included in the device driver API. This function should be treated as an
  * example code to design the descriptor structures in ring mode or chain mode.
  * This function depends on the pcidev structure for allocation of consistent dma-able memory in case of linux.
  * This limitation is due to the fact that linux uses pci structure to allocate a dmable memory
  *     - Allocates the memory for the descriptors.
  *     - Initialize the Busy and Next descriptors indices to 0(Indicating first descriptor).
  *     - Initialize the Busy and Next descriptors to first descriptor address.
  *     - Initialize the last descriptor with the endof ring in case of ring mode.
  *     - Initialize the descriptors in chain mode.
  * @param[in] pointer to synopGMACdevice.
  * @param[in] pointer to pci_device structure.
  * @param[in] number of descriptor expected in rx descriptor queue.
  * @param[in] whether descriptors to be created in RING mode or CHAIN mode.
  * return 0 upon success. Error code upon failure.
  * note This function fails if allocation fails for required number of descriptors in Ring mode, but in chain mode
  *  function returns -ESYNOPGMACNOMEM in the process of descriptor chain creation. once returned from this function
  *  user should for gmacdev->RxDescCount to see how many descriptors are there in the chain. Should continue further
  *  only if the number of descriptors in the chain meets the requirements
  */
s32 synopGMAC_setup_rx_desc_queue(GMACdevice * gmacdev,u32 no_of_desc )
{
	s32 i;
	
	gmacdev->RxDescCount = 0;
	
	gmacdev->RxDescCount = no_of_desc;
	gmacdev->RxDesc      = (DmaDesc *)(&gmacRtx.rxbd[0]);
	gmacdev->RxDescDma   = virt_to_phys((DmaDesc *)gmacdev->RxDesc);
	
	for(i =0; i < gmacdev->RxDescCount; i++)
			synopGMAC_desc_init_rx_ring(gmacdev->RxDesc + i, i == gmacdev->RxDescCount-1);
	
	gmacdev->RxNext = 0;
	gmacdev->RxNextDesc = gmacdev->RxDesc;
	gmacdev->RxBusyDesc = gmacdev->RxDesc;
	gmacdev->RxBusy = 0;
    printf_chip("synopGMAC_setup_rx_desc_queue: gmacdev->RxDesc=0x%p, gmacdev->RxDescDma=0x%08x\n",gmacdev->RxDesc,gmacdev->RxDescDma);	
	
	return -1;
}


/*
* This sets up the transmit Descriptor queue in ring or chain mode.
* This function is tightly coupled to the platform and operating system
* Device is interested only after the descriptors are setup. Therefore this function
* is not included in the device driver API. Thiss32 synopGMAC_setup_tx_desc_queue(synopGMACdevice * gmacdev,u32 noprintf ("gmacRtx.txbd[0]: %x  %x\n",&gmacRtx.txbd[0], gmacRtx.txbd[0]);_ofbool_desc) function should be treated as an
* example code to design the descriptor structures for ring mode or chain mode.
* This function depends on the pcidev structure for allocation consistent dma-able memory in case of linux.
* This limitation is due to the fact that linux uses pci structure to allocate a dmable memory
*     - Allocates the memory for the descriptors.
*     - Initialize the Busy and Next descriptors indices to 0(Indicating first descriptor).
*     - Initialize the Busy and Next descriptors to first descriptor address.
*     - Initialize the last descriptor with the endof ring in case of ring mode.
*     - Initialize the descriptors in chain mode.
* @param[in] pointer to synopGMACdevice.
* @param[in] pointer to pci_device structure.
* @param[in] number of descriptor expected in tx descriptor queue.
* @param[in] whether descriptors to be created in RING mode or CHAIN mode.
* \return 0 upon success. Error code upon failure.
* \note This function fails if allocation fails for required number of descriptors in Ring mode, but in chain mode
*  function returns -ESYNOPGMACNOMEM in the process of descriptor chain creation. once returned from this function
*  user should for gmacdev->TxDescCount to see how many descriptors are there in the chain. Should continue further
*  only if the number of descriptors in the chain meets the requirements
*/

s32 synopGMAC_setup_tx_desc_queue(GMACdevice * gmacdev,u32 no_of_desc)
{
	s32 i;

	gmacdev->TxDescCount = no_of_desc;
	gmacdev->TxDesc      = (DmaDesc *)(&gmacRtx.txbd[0]);
	gmacdev->TxDescDma   = virt_to_phys((DmaDesc *)gmacdev->TxDesc);

	for(i =0; i < gmacdev->TxDescCount; i++){
		synopGMAC_desc_init_tx_ring(gmacdev->TxDesc + i, i == gmacdev->TxDescCount-1);
	}

	gmacdev->TxNext = 0;
	gmacdev->TxBusy = 0;
	gmacdev->TxNextDesc = gmacdev->TxDesc;
	gmacdev->TxBusyDesc = gmacdev->TxDesc;
    printf_chip("synopGMAC_setup_tx_desc_queue: no_of_desc=%d, TxDesc=0x%p, TxDescDma=0x%08x\n",no_of_desc, gmacdev->TxDesc, gmacdev->TxDescDma);

	return -1;
}

/**
  * Initialize the descriptors for ring or chain mode operation.
  *     - Status field is initialized to 0.
  *     - EndOfRing set for the last descriptor.
  *     - buffer1 and buffer2 set to 0 for ring mode of operation. (note)
  *     - data1 and data2 set to 0. (note)
  * @param[in] pointer to DmaDesc structure.
  * @param[in] whether end of ring
  * \return 0 upon success. Error code upon failure.
  * \note Initialization of the buffer1, buffer2, data1,data2 and status are not done here. This only initializes whether one wants to use this descriptor
  * in chain mode or ring mode. For chain mode of operation the buffer2 and data2 are programmed before calling this function.
  */
void synopGMAC_desc_init_rx_ring(DmaDesc *desc, int last_ring_desc)
{
        desc->status = 0;
        desc->length = last_ring_desc ? DescEndOfRing : 0;
        desc->buffer1 = 0;
        desc->buffer2 = 0;

        return;
}

void synopGMAC_desc_init_tx_ring(DmaDesc *desc, int last_ring_desc)
{
#ifdef SYNOP_GMAC_ENHANCED_DESCRIPTOR
        desc->status = last_ring_desc ? DescTxEndOfRing : 0;
        desc->length = 0;
#else
        desc->status = 0;
        desc->length = last_ring_desc ? DescEndOfRing : 0;
#endif
        desc->buffer1 = 0;
        desc->buffer2 = 0;
//      printf("===synopGMAC_desc_init_tx_ring: desc=0x%p, desc->status=0x%08x, desc->length=0x%08x\n",desc, desc->status, desc->length);
        return;
}


/**
* Attaches the synopGMAC device structure to the hardware.
* Device structure is populated with MAC/DMA and PHY base addresses.
* @param[in] pointer to GMACdevice to populate mac dma and phy addresses.
* @param[in] GMAC IP mac base address.
* @param[in] GMAC IP dma base address.
* @param[in] GMAC IP phy base address.
* \return 0 upon success. Error code upon failure.
* \note This is important function. No kernel api provided by Synopsys 
*/

void  synopGMAC_attach (GMACdevice * gmacdev, u32 macBase, u32 dmaBase, u32 phyBase) 
{
	unsigned char mac_addr0[6] = DEFAULT_MAC_ADDRESS;
	/*Make sure the Device data strucure is cleared before we proceed further*/
//	memset((void *) gmacdev,0,sizeof(GMACdevice)); /*already done in vbg400_switch_initialize()*/
	/*Populate the mac and dma base addresses*/
	gmacdev->MacBase = macBase;
	gmacdev->DmaBase = dmaBase;
	gmacdev->PhyBase = phyBase;

	/* Program/flash in the station/IP's Mac address */
	synopGMAC_set_mac_addr(gmacdev,GmacAddr0High,GmacAddr0Low, mac_addr0); 
}

/**
* Get the Mac address in to the address specified.
* The mac register contents are read and written to buffer passed.
* @param[in] pointer to GMACdevice to populate mac dma and phy addresses.
* @param[in] Register offset for Mac address high
* @param[in] Register offset for Mac address low
* @param[out] buffer containing the device mac address.
* \return 0 upon success. Error code upon failure.
*/
u32 synopGMAC_get_mac_addr(GMACdevice *gmacdev, u32 MacHigh, u32 MacLow, u8 *MacAddr)
{
	u32 data;
		
	data = synopGMACReadReg((u32 *)gmacdev->MacBase,MacHigh);
	MacAddr[5] = (data >> 8) & 0xff;
	MacAddr[4] = (data)        & 0xff;

	data = synopGMACReadReg((u32 *)gmacdev->MacBase,MacLow);
	MacAddr[3] = (data >> 24) & 0xff;
	MacAddr[2] = (data >> 16) & 0xff;
	MacAddr[1] = (data >> 8 ) & 0xff;
	MacAddr[0] = (data )      & 0xff;

	return 0;
}

/**
* Sets the Mac address in to GMAC register.
* This function sets the MAC address to the MAC register in question.
* @param[in] pointer to GMACdevice to populate mac dma and phy addresses.
* @param[in] Register offset for Mac address high
* @param[in] Register offset for Mac address low
* @param[in] buffer containing mac address to be programmed.
* \return 0 upon success. Error code upon failure.
*/
u32 synopGMAC_set_mac_addr(GMACdevice *gmacdev, u32 MacHigh, u32 MacLow, u8 *MacAddr)
{
	u32 data;
	
	data = (MacAddr[5] << 8) | MacAddr[4];
	synopGMACWriteReg((u32 *)gmacdev->MacBase,MacHigh,data);
	data = (MacAddr[3] << 24) | (MacAddr[2] << 16) | (MacAddr[1] << 8) | MacAddr[0] ;
	synopGMACWriteReg((u32 *)gmacdev->MacBase,MacLow,data);
	return 0;
}

/**
* Function to read the GMAC IP Version and populates the same in device data structure.
* @param[in] pointer to synopGMACdevice.
* \return Always return 0.
*/

s32 synopGMAC_read_version (GMACdevice * gmacdev)
{
	u32 data = 0;
	data = synopGMACReadReg((u32 *)gmacdev->MacBase, GmacVersion );
	gmacdev->Version = data;
	printf ("Version is : %08x\n",data);
	return 0;
}


/* Write value to the device's PHY through the registers
* specified in priv, modifying the register specified in regnum.
* It will wait for the write to be done (or for a timeout to
* expire) before exiting
*/
void write_any_phy_reg(struct tsec_private *priv, uint phyid, uint regnum, uint value)
{
#ifndef CONFIG_VBG400_CHIPIT
    u32 clock = SYS_CLOCK_RATE;
    uint gmii_csr_clk;
    volatile gphy_t *regbase = priv->phyregsSmaMaster;
#else
	volatile gphy_t *regbase = priv->phyregs;
#endif
	volatile uint *addr_reg,*data_reg;
	int timeout = 1000000;

	addr_reg = (uint *)  &regbase->addReg;
	data_reg = (uint *)  &regbase->dataReg;

	*data_reg = value;

#ifndef CONFIG_VBG400_CHIPIT
    //new code to select clock according to clk_csr_i (see phy datasheet)
    if (clock > 240000000) {
        gmii_csr_clk = GmiiCsrClk5;
	    printf ("write_any_phy_reg: clock > 240000000 \n");
    }
    else
        gmii_csr_clk = GmiiCsrClk4;

	*addr_reg = ((phyid << GmiiDevShift) & GmiiDevMask) | 
                ((regnum << GmiiRegShift) & GmiiRegMask) | 
                (gmii_csr_clk) | MII_WRITE | GmiiBusy;
#else
    *addr_reg = 0x080b;
#endif //CONFIG_VBG400_CHIPIT

//    printf("%s[%d] ! Addr = 0x%08x RegData = 0x%08x\n", __FUNCTION__, __LINE__, *addr_reg, *data_reg );

	while ((*addr_reg & GmiiBusy) && timeout--) ;
	if (!timeout)
		printf ("time-out occured in read regs\n");
}

/* #define to provide old write_phy_reg functionality without duplicating code */
//#define write_phy_reg(priv, regnum, value) write_any_phy_reg(priv,priv->phyaddr,regnum,value)

/* Reads register regnum on the device's PHY through the
* registers specified in priv.	 It lowers and raises the read
* command, and waits for the data to become valid (miimind
* notvalid bit cleared), and the bus to cease activity (miimind
* busy bit cleared), and then returns the value
*/
uint read_any_phy_reg(struct tsec_private *priv, uint phyid, uint regnum)
{
	//int timeout = 1000000;
#ifndef CONFIG_VBG400_CHIPIT
	int timeout = 1000000; /*must be this value ! (for FPGA)*/
    uint gmii_csr_clk;
	volatile gphy_t *regbase = priv->phyregsSmaMaster;
#else
	int timeout = 1000000/*2000000*/; /*must be this value ! (for FPGA)*/
	volatile gphy_t *regbase = priv->phyregs;
#endif
	volatile uint *addr_reg,*data_reg;

	addr_reg = (uint *)  &regbase->addReg;
	data_reg = (uint *)  &regbase->dataReg;

#ifndef CONFIG_VBG400_CHIPIT
    gmii_csr_clk = GmiiCsrClk4;
#endif //CONFIG_VBG400_CHIPIT

	*addr_reg = ((phyid << GmiiDevShift) & GmiiDevMask) | 
                ((regnum << GmiiRegShift) & GmiiRegMask) | 
#ifndef CONFIG_VBG400_CHIPIT
                (gmii_csr_clk) | MII_READ | GmiiBusy;
#else
			(GmiiCsrClk2) | MII_READ | // divider for 20-35 MHz (current System Clock is 24 MHz)
			GmiiBusy;
#endif //CONFIG_VBG400_CHIPIT

	while ((*addr_reg & GmiiBusy) && timeout--) ;
	if (!timeout)
		printf ("time-out occured in read regs\n");

//    printf("%s[%d] ! Addr = 0x%08x RegData = 0x%08x\n", __FUNCTION__, __LINE__, *addr_reg, *data_reg );
	return *data_reg;
}

/* #define to provide old read_phy_reg functionality without duplicating code */
//#define read_phy_reg(priv,regnum) read_any_phy_reg(priv,priv->phyaddr,regnum)

#define VBG400_FORCE_PHY_STATUS_TEST
//#define VBG400_DUMP_REGS

/* Discover which PHY is attached to the device, and configure it
* properly.  If the PHY is not recognized, then return 0
* (failure).  Otherwise, return 1
* for vbg400, phy_info_vbg400 is used.
*/
static int init_phy(struct eth_device *dev)
{
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
	struct phy_info *curphy;

    printf_chip("init_phy()---///\n");
	if (0 == relocated)
		relocate_cmds();

	/* Get the cmd structure corresponding to the attached
	* PHY */
	curphy = get_phy_info(dev);

	if (curphy == NULL) {
		priv->phyinfo = NULL;
		printf("%s: No PHY found\n", dev->name);

		return 0;
	}
	priv->phyinfo = curphy;

	phy_run_commands(priv, priv->phyinfo->config);

#ifdef VBG400_FORCE_PHY_STATUS_TEST
    phy_run_commands(priv, priv->phyinfo->startup);
#endif

	return 1;
}

/*
* Returns which value to write to the control register.
* For 10/100, the value is slightly different
*/
uint mii_cr_init(uint mii_reg, struct tsec_private * priv)
{
	if (priv->flags & TSEC_GIGABIT) {
        printf("TSEC_GIGABIT\n");
		return MIIM_CONTROL_INIT;
	}
	else {
        printf("not TSEC_GIGABIT\n");
		return MIIM_CR_INIT;
    }
}

/* Parse the status register for link, and then do
* auto-negotiation
*/
uint mii_parse_sr(uint mii_reg, struct tsec_private * priv)
{
	/*
	* Wait if the link is up, and autonegotiation is in progress
	* (ie - we're capable and it's not done)
	*/
#ifdef CONFIG_VBG400_CHIPIT
	u32 delay=1000000/*2000000*/;
    __udelay(delay);	/* 2 sec - arad: to delete !!! ? */
#endif	

	mii_reg = read_phy_reg(priv, MIIM_STATUS);

    printf("mii_parse_sr: mii_reg reg = 0x%08x\n",mii_reg);
	if (((mii_reg & MIIM_STATUS_LINK) && (mii_reg & PHY_BMSR_AUTN_ABLE)
	&& !(mii_reg & PHY_BMSR_AUTN_COMP)) || !(mii_reg & MIIM_STATUS_LINK)) {
		int i = 0;

		//puts("Waiting for PHY auto negotiation to complete");

        printf("Waiting auto negotiation\n");
		while (!(mii_reg & PHY_BMSR_AUTN_COMP)) {
			/*
			* Timeout reached ?
			*/
#ifndef CONFIG_VBG400_CHIPIT
			__udelay(1000000);
            printf("mii_parse_sr: %d \n",i);
			if (i > 6) {
#else
			if (i > PHY_AUTONEGOTIATE_TIMEOUT) {
#endif
                printf("TIMEOUT \n");
				//puts(" TIMEOUT !\n");
				priv->link = 0;
				return 0;
			}

			if ((i++ % 1000) == 0) {
				putc('.');
			}
			__udelay(1000);	/* 1 milisec - arad: to delete !!! */
			mii_reg = read_phy_reg(priv, MIIM_STATUS);
		}
        printf("done\n");
		//puts(" done\n");
		priv->link = 1;
		__udelay(500000);	/* another 500 ms (results in faster booting) */
	} else {
        printf("in else, mii_reg=0x%08x, MIIM_STATUS_LINK=0x%08x\n",mii_reg,MIIM_STATUS_LINK);
		if (mii_reg & MIIM_STATUS_LINK)
			priv->link = 1;
		else
			priv->link = 0;
	}
    printf("end mii_parse_sr, priv->link = %d\n",priv->link);

#ifdef CONFIG_VBG400_CHIPIT
    __udelay(delay);	/* 1 sec - arad: to delete !!! */
#endif
	return 0;
}

/* Generic function which updates the speed and duplex.  If
* autonegotiation is enabled, it uses the AND of the link
* partner's advertised capabilities and our advertised
* capabilities.  If autonegotiation is disabled, we use the
* appropriate bits in the control register.
*
* Stolen from Linux's mii.c and phy_device.c
*/
uint mii_parse_link(uint mii_reg, struct tsec_private *priv)
{
	u32 delay=1000000;
	
    __udelay(delay);	/* 1 sec - arad: to delete !!! */

	/* We're using autonegotiation */
	printf("in mii_parse_link, mii_reg = 0x%x \n",mii_reg);
	if (mii_reg & PHY_BMSR_AUTN_ABLE) {
		uint lpa = 0;
		uint gblpa = 0;

		printf("PHY_BMSR_AUTN_ABLE \n");
		/* Check for gigabit capability */
		if (mii_reg & PHY_BMSR_EXT) {
			/* We want a list of states supported by
			* both PHYs in the link
			*/
			printf("PHY_BMSR_EXT \n");
			gblpa = read_phy_reg(priv, PHY_1000BTSR);
			printf("PHY_BMSR_EXT, PHY_1000BTSR REG=0x%08x \n",gblpa);
			gblpa &= read_phy_reg(priv, PHY_1000BTCR) << 2;
			//printf("PHY_BMSR_EXT, (PHY_1000BTSR & (PHY_1000BTCR << 2)) REG=0x%08x \n",gblpa);
		}

		/* Set the baseline so we only have to set them
		* if they're different
		*/
		priv->speed = 10;
		priv->duplexity = 0;

		/* Check the gigabit fields */
		if (gblpa & (PHY_1000BTSR_1000FD | PHY_1000BTSR_1000HD)) {
			priv->speed = 1000;

			if (gblpa & PHY_1000BTSR_1000FD) {
				printf("PHY_1000BTSR_1000FD \n");
	            printf("speed = %d, duplexity = %d \n",priv->speed,priv->duplexity);
				priv->duplexity = 1;
            }
			else {
				printf("PHY_1000BTSR_1000HD \n");
	            printf("speed = %d, duplexity = %d \n",priv->speed,priv->duplexity);
				/* We're done! */
#if 0
				return 0;
#endif
		    }
#if 1
			return 0;
#endif
		}

		lpa = read_phy_reg(priv, PHY_ANAR);
		//printf("PHY_BMSR_EXT, PHY_ANAR REG=0x%08x \n",gblpa);
		lpa &= read_phy_reg(priv, PHY_ANLPAR);
		//printf("PHY_BMSR_EXT, (PHY_ANAR & (PHY_ANLPAR << 2)) REG=0x%08x \n",gblpa);

		if (lpa & (PHY_ANLPAR_TXFD | PHY_ANLPAR_TX)) {
			priv->speed = 100;

			if (lpa & PHY_ANLPAR_TXFD) {
				printf("PHY_ANLPAR_TXFD \n");
				priv->duplexity = 1;
            }
            else
				printf("PHY_ANLPAR_TXHD \n");
		} else if (lpa & PHY_ANLPAR_10FD)
			priv->duplexity = 1;
	} else {
		uint bmcr = read_phy_reg(priv, PHY_BMCR);

		printf("NOTTTT PHY_BMSR_AUTN_ABLE !!!\n");
		priv->speed = 10;
		priv->duplexity = 0;

		if (bmcr & PHY_BMCR_DPLX) {
			priv->duplexity = 1;
			printf("PHY_BMCR_DPLX \n");
		}
		if (bmcr & PHY_BMCR_1000_MBPS)
			priv->speed = 1000;
		else if (bmcr & PHY_BMCR_100_MBPS)
			priv->speed = 100;
	}
	printf("speed = %d, duplexity = %d \n",priv->speed,priv->duplexity);
	printf("end mii_parse_link\n");

	return 0;
}


static int gmac_send(struct eth_device *dev, volatile void *packet, int length)
{
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
	volatile GMACdevice *gmacdev = priv->gmacRegs;
	s32 status;
    printf_chip("gmac_send :-) :-) :-) :-) :-) :-) :-) \n");

	status = synopGMAC_set_tx_qptr((GMACdevice *) gmacdev, (uint) virt_to_phys (packet), length);
//    printf("%s: %d: Desc->status is 0x%x\n", __FUNCTION__, __LINE__, gmacdev->TxNextDesc->status);
    if(status < 0){
                printf ("%s No More Free Tx Descriptors\n",__FUNCTION__);
                return -1;
    }
        synopGMAC_resume_dma_tx((GMACdevice *) gmacdev);
/*
        i=0;
        while ((gmacdev->TxNextDesc->status & DescOwnByDma) && i<100)
        {
            printf(".");
            __udelay(1);
            i++;
        } 
        gmacdev->TxNextDesc->length =0;
        dmastatus = synopGMACReadReg((u32 *)gmacdev->DmaBase, DmaStatus );
        printf("\nDesc->status is 0x%x, DMAstatus is 0x%x \n", gmacdev->TxNextDesc->status, dmastatus );*/
	return 0;
}

static int gmac_recv(struct eth_device *dev)
{
	int length;
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
	volatile GMACdevice *gmacdev = priv->gmacRegs;
	uint status, buffer1,lenght1;
	uint desc_index;

/* TO DO Handle errors */

   do{
	synopGMAC_resume_dma_rx((GMACdevice *) gmacdev);
	desc_index = synopGMAC_get_rx_qptr((GMACdevice *) gmacdev, &status, &buffer1, &lenght1 );

//printf_chip("%s: desc_index=%d, rxIdx=%d, packet length=%d, status = 0x%x\n", __FUNCTION__, desc_index, rxIdx, lenght1, status);

	if(desc_index >= 0 && desc_index < RECEIVE_DESC_SIZE ){
		if(synopGMAC_is_rx_desc_valid(status)){
			length =  ((status & DescFrameLengthMask) >> DescFrameLengthShift); 
		   	NetReceive((u8 *) NetRxPackets[rxIdx], length - 4);  /* No CRC */

		   	desc_index = synopGMAC_set_rx_qptr((GMACdevice *) gmacdev,(uint ) NetRxPackets[rxIdx], PATTERN);

			rxIdx = (rxIdx + 1) % RECEIVE_DESC_SIZE;

			if(desc_index < 0)
				printf("gmac_recv: Cannot set Rx Descriptor \n");		
		}
		else {
			printf ("ERROR rx_desc not Valid: Status is : %x\n", status);
			return -1;
		}
	}
   }while(desc_index != 0xffffffff);


   return 0;
}

/*
  * Checks whether the rx descriptor is valid.
  * if rx descripor is not in error and complete frame is available in the same descriptor
  * @param[in] pointer to DmaDesc structure.
  * \return returns true if no error and first and last desc bits are set, otherwise it returns false.
  */
int synopGMAC_is_rx_desc_valid(u32 status)
{
        return ((status & DescError) == 0) && ((status & DescRxFirst) == DescRxFirst) && ((status & DescRxLast) == DescRxLast);
}


/*
  * returns the byte length of received frame including CRC.
  * This returns the no of bytes received in the received ethernet frame including CRC(FCS).
  * @param[in] pointer to DmaDesc structure.
  * \return returns the length of received frame lengths in bytes.
  */
u32 synopGMAC_get_rx_desc_frame_length(u32 status)
{
        return ((status & DescFrameLengthMask) >> DescFrameLengthShift);
}


/**
  * Enable the DMA Reception.
  * @param[in] pointer to synopGMACdevice.
  * \return 0 upon success. Error code upon failure.
  */
void synopGMAC_enable_dma_rx(GMACdevice * gmacdev)
{
        u32 data;
        data = synopGMACReadReg((u32 *)gmacdev->DmaBase, DmaControl);
        data |= DmaRxStart;
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaControl ,data);

}


/**
* Function to reset the GMAC core.
* This reests the DMA and GMAC core. After reset all the registers holds their respective reset value
* @param[in] pointer to GMACdevice.
* \return 0 on success else return the error status.
*/
static void gmac_halt(struct eth_device *dev)
{
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
	volatile GMACdevice *gmacdev = priv->gmacRegs;
	u32 data = 0;
//Uncomment this code to leave Ethernet MAC initialized and working after current session (PING, tftp etc.) is finished
//return;
	synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaBusMode ,DmaResetOn);
	__udelay (1000);
	data = synopGMACReadReg((u32 *)gmacdev->DmaBase, DmaBusMode);
}


#ifdef CONFIG_VBG400_CHIPIT
//#define VBG400_FORCE_MODE

uint mii_parse_link_1378e(uint mii_reg, struct tsec_private *priv)
{
	u32 delay=1000000;
	u16 HALFDUPLEX = 1;
	u16 FULLDUPLEX = 2;
	u16 SPEED10    = 1;
	u16 SPEED100    = 2;
	
    __udelay(delay);	/* 1 sec - arad: to delete !!! */

	/* Set the baseline so we only have to set them
	* if they're different
	*/
	priv->speed = 10;
	priv->duplexity = 0;

	priv->duplexity = (mii_reg & 0x0200)  ? FULLDUPLEX: HALFDUPLEX ;
    /*not support speed 1000*/
	if(mii_reg & 0x4000)
		priv->speed =   SPEED100;
	else
		priv->speed =   SPEED10;

	printf("mii_parse_link_1378e: speed = %d \n",priv->speed);

	return 0;
}


/* a generic flavor.  */
struct phy_info phy_info_vbg400 =  {
	0x22161,
	"VBG400 PHY (KS8721)",
	4,
	(struct phy_cmd[]) { /* config */
#if 0
		{PHY_BMCR, PHY_BMCR_RESET, NULL},
#endif
#ifdef VBG400_FORCE_MODE
		{PHY_BMCR, PHY_BMCR_DPLX|PHY_BMCR_100MB, NULL},
#else
		{PHY_BMCR, PHY_BMCR_AUTON|PHY_BMCR_RST_NEG, NULL},
#endif
		{miim_end,}
	},
	(struct phy_cmd[]) { /* startup */
		{PHY_BMSR, miim_read, NULL},
		{PHY_BMSR, miim_read, &mii_parse_sr},
		{PHY_BMSR, miim_read, &mii_parse_link},
		{miim_end,}
	},
	(struct phy_cmd[]) { /* shutdown */
		{miim_end,}
	}
};

#define PHY_100BTX_CTRL_REG 0x001f

struct phy_info phy_info_vbg400_1378e =  {
	0x1378e/*intel LXT971A on external board*/,
	"VBG400 PHY (LX971)",
	4,
	(struct phy_cmd[]) { /* config */
		{PHY_BMCR, PHY_BMCR_RESET, NULL},
#ifdef VBG400_FORCE_MODE
		{PHY_BMCR, PHY_BMCR_DPLX|PHY_BMCR_100MB, NULL},
#else
		{PHY_BMCR, PHY_BMCR_AUTON|PHY_BMCR_RST_NEG, NULL},
#endif
		{miim_end,}
	},
	(struct phy_cmd[]) { /* startup */
		{PHY_BMSR, miim_read, NULL},
		{PHY_BMSR, miim_read, &mii_parse_sr},
		{PHY_100BTX_CTRL_REG, miim_read, &mii_parse_link_1378e},
		{miim_end,}
	},
	(struct phy_cmd[]) { /* shutdown */
		{miim_end,}
	}
};

/* a generic flavor.  */
struct phy_info phy_info_generic =  {
	0,
	"Unknown/Generic PHY",
	32,
	(struct phy_cmd[]) { /* config */
		{PHY_BMCR, PHY_BMCR_RESET, NULL},
		{PHY_BMCR, PHY_BMCR_AUTON|PHY_BMCR_RST_NEG, NULL},
		{miim_end,}
	},
	(struct phy_cmd[]) { /* startup */
		{PHY_BMSR, miim_read, NULL},
		{PHY_BMSR, miim_read, &mii_parse_sr},
		{PHY_BMSR, miim_read, &mii_parse_link},
		{miim_end,}
	},
	(struct phy_cmd[]) { /* shutdown */
		{miim_end,}
	}
};

#else
/*
MIICTRL (offset=0x17)- Media-Independent Interface Control
MODE 3:0 RW MII Interface Mode
FLOW 5:4 RW Data Flow Configuration
CRS 7:6 RW CRS Sensitivity Configuration
TXSKEW 10:8 RW Transmit Timing Skew (RGMII)
V25_33 11 RW Power Supply Control for MII Pins
RXSKEW 14:12 RW Receive Timing Skew (RGMII)
RXCOFF 15 RW Receive Clock Control
*/
#define PHY_LBR_TX_SKEW  0x0
#define PHY_LBR_RX_SKEW  0x0  
#define PHY_LBR_RXCOFF   0x0  
struct phy_info phy_info_xway_gphy_1_4 =  {
	0xd565a400,
	"Lantiq XWay GPHY (1.4)",
	0,
#if 0
	(struct phy_cmd[]) { /* config */
		{PHY_BMCR, PHY_BMCR_AUTON|PHY_BMCR_RST_NEG, NULL},
		{PHY_LBR, PHY_LBR_RXCOFF|PHY_LBR_RX_SKEW|PHY_LBR_TX_SKEW, NULL},
		{PHY_BMCR, PHY_BMCR_RESET|PHY_BMCR_AUTON, NULL},
		{miim_end,}
	},
#else
	(struct phy_cmd[]) { /* config */
		{PHY_BMCR, PHY_BMCR_AUTON|PHY_BMCR_RST_NEG, NULL},
		{PHY_LBR, PHY_MIPSCR_TXSKEW_DATA, NULL},
		{PHY_BMCR, PHY_BMCR_RST_NEG|PHY_BMCR_AUTON, NULL},
		{miim_end,}
	},
#endif
	(struct phy_cmd[]) { /* startup */
		{PHY_BMSR, miim_read, NULL},
		{PHY_BMSR, miim_read, &mii_parse_sr},
		{PHY_BMSR, miim_read, &mii_parse_link},
		{miim_end,}
	},
	(struct phy_cmd[]) { /* shutdown */
		{miim_end,}
	}
};
#endif //CONFIG_VBG400_CHIPIT

struct phy_info *phy_info[] = {
#ifndef CONFIG_VBG400_CHIPIT
    &phy_info_xway_gphy_1_4,
#else
	&phy_info_vbg400,
	&phy_info_vbg400_1378e,
	&phy_info_generic,
#endif
	NULL
};

int get_phy_address(struct tsec_private *priv, unsigned int *phyaddr)
{
    uint j=0;
	uint phy_reg, phy_ID;
    /* In CHIP mode phyaddr already has phy address read from configuration,
    * It is only validate configuration by read ID (SMA constraint).
    * In FPGA it search and config when found.
    */
#ifdef CONFIG_VBG400_CHIPIT
    uint i;
    for (i=0;i<32;i++)
    {
        *phyaddr = i;
#endif
        phy_reg = read_any_phy_reg (priv, *phyaddr, MIIM_PHYIR1);
        phy_ID = (phy_reg & 0xffff) << 16;
        phy_reg = read_any_phy_reg (priv, *phyaddr, MIIM_PHYIR2);
        phy_ID |= (phy_reg & 0xffff);
        /* loop through all the known PHY types, and find one that matches the ID */
        for (j = 0; phy_info[j]; j++)
        {
            if(phy_info[j]->id == (phy_ID >> phy_info[j]->shift)) {
#ifdef CONFIG_VBG400_CHIPIT
                *phyaddr = i; 
#endif
                printf("\nget_phy_address: find phy_ID=0x%08x, phyaddr=0x%p\n",phy_ID,phyaddr);
                return 0;
            }
        }
#ifdef CONFIG_VBG400_CHIPIT
    }
#endif
    printf("get_phy_address: error find phy\n");
    return -1;
}



/* Grab the identifier of the device's PHY, and search through
* all of the known PHYs to see if one matches.	 If so, return
* it, if not, return NULL
*/
struct phy_info *get_phy_info(struct eth_device *dev)
{
	struct tsec_private *priv = (struct tsec_private *)dev->priv;
	uint phy_reg, phy_ID;
	int i;
	struct phy_info *theInfo = NULL;

	priv->link = (read_phy_reg(priv, MIIM_PHYSTAT) & 4) >> 2;

	/* Grab the bits from PHYIR1, and put them in the upper half */
	phy_reg = read_phy_reg(priv, MIIM_PHYIR1);
	phy_ID = (phy_reg & 0xffff) << 16;

	/* Grab the bits from PHYIR2, and put them in the lower half */
	phy_reg = read_phy_reg(priv, MIIM_PHYIR2);
	phy_ID |= (phy_reg & 0xffff);

	/* loop through all the known PHY types, and find one that */
	/* matches the ID we read from the PHY. */
	for (i = 0; phy_info[i]; i++) {
		if (phy_info[i]->id == (phy_ID >> phy_info[i]->shift)) {
			theInfo = phy_info[i];
			break;
		}
	}

	if (theInfo == NULL) {
		printf("%s: PHY id %x is not supported!\n", dev->name, phy_ID);
		return NULL;
	} else {
		printf("%s: PHY is %s (%x) (shifted %x)\n", dev->name, theInfo->name, phy_ID, (phy_info[i]->id));
	}

	return theInfo;
}


/* Execute the given series of commands on the given device's
* PHY, running functions as necessary
*/
void phy_run_commands(struct tsec_private *priv, struct phy_cmd *cmd)
{
	int i;
	uint result;

	for (i = 0; cmd->mii_reg != miim_end; i++) {
		if (cmd->mii_data == miim_read) {
			result = read_phy_reg(priv, cmd->mii_reg);
			printf("read PHY  result = 0x%x\n",result);

			if (cmd->funct != NULL)
				(*(cmd->funct)) (result, priv);

		} else {
			if (cmd->funct != NULL)
				result = (*(cmd->funct)) (cmd->mii_reg, priv);
			else
				result = cmd->mii_data;

			printf("write PHY  result = 0x%x\n",result);
			write_phy_reg(priv, cmd->mii_reg, result);
		}
		cmd++;
	}

}

/* Relocate the function pointers in the phy cmd lists */
static void relocate_cmds(void)
{
	struct phy_cmd **cmdlistptr;
	struct phy_cmd *cmd;
	int i, j, k;

	for (i = 0; phy_info[i]; i++) {
		/* First thing's first: relocate the pointers to the
		* PHY command structures (the structs were done) */
		phy_info[i] = (struct phy_info *)((uint) phy_info[i]
						+ gd->reloc_off);
		phy_info[i]->name += gd->reloc_off;
		phy_info[i]->config =
		(struct phy_cmd *)((uint) phy_info[i]->config
				+ gd->reloc_off);
		phy_info[i]->startup =
		(struct phy_cmd *)((uint) phy_info[i]->startup
				+ gd->reloc_off);
		phy_info[i]->shutdown =
		(struct phy_cmd *)((uint) phy_info[i]->shutdown
				+ gd->reloc_off);

		cmdlistptr = &phy_info[i]->config;
		j = 0;
		for (; cmdlistptr <= &phy_info[i]->shutdown; cmdlistptr++) {
			k = 0;
			for (cmd = *cmdlistptr;
			cmd->mii_reg != miim_end;
			cmd++) {
				/* Only relocate non-NULL pointers */
				if (cmd->funct)
					cmd->funct += gd->reloc_off;

				k++;
			}
			j++;
		}
	}

	relocated = 1;
}

#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII) \
	&& !defined(BITBANGMII)

/*
* Read a MII PHY register.
*
* Returns:
*  0 on success
*/
static int gmac_miiphy_read(char *devname, unsigned char addr,
			unsigned char reg, unsigned short *value)
{
	unsigned short ret;
	struct tsec_private *priv = privlist[0];

	if (NULL == priv) {
		printf("Can't read PHY at address %d\n", addr);
		return -1;
	}

	ret = (unsigned short)read_any_phy_reg(priv, addr, reg);
	*value = ret;

	return 0;
}

/*
* Write a MII PHY register.
*
* Returns:
*  0 on success
*/
static int gmac_miiphy_write(char *devname, unsigned char addr,
			unsigned char reg, unsigned short value)
{
	struct tsec_private *priv = privlist[0];

	if (NULL == priv) {
		printf("Can't write PHY at address %d\n", addr);
		return -1;
	}

	write_any_phy_reg(priv, addr, reg, value);

	return 0;
}

#endif

/*
  * Disables the Jabber frame support.
  * When disabled, GMAC enables jabber timer. It cuts of transmitter if application
  * sends more than 2048 bytes of data (10240 if Jumbo frame enabled).
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_jab_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacJabber);
        return;
}

/*
  * Enables Frame bursting (Only in Half Duplex Mode).
  * When enabled, GMAC allows frame bursting in GMII Half Duplex mode.
  * Reserved in 10/100 and Full-Duplex configurations.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_frame_burst_enable(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacFrameBurst);
        return;
}

/*
  * Disable Jumbo frame support.
  * When Disabled GMAC does not supports jumbo frames.
  * Giant frame error is reported in receive frame status.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_jumbo_frame_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacJumboFrame);
        return;
}

/*
  * Enables Receive Own bit (Only in Half Duplex Mode).
  * When enaled GMAC receives all the packets given by phy while transmitting.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_rx_own_enable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacRxOwn);
        return;
}

/*
  * Sets the GMAC in Normal mode.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_loopback_off(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacLoopback);
        return;
}

/*
  * Sets the GMAC core in Full-Duplex mode.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_set_full_duplex(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacDuplex);
        return;
}

/*
  * GMAC tries retransmission (Only in Half Duplex mode).
  * If collision occurs on the GMII/MII, GMAC attempt retries based on the
  * back off limit configured.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  * \note This function is tightly coupled with synopGMAC_back_off_limit(synopGMACdev *, u32).
  */
void synopGMAC_retry_enable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacRetry);
        return;
}

/*
  * GMAC doesnot strips the Pad/FCS field of incoming frames.
  * GMAC will pass all the incoming frames to Host unmodified.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_pad_crc_strip_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacPadCrcStrip);
        return;
}

/*
  * GMAC programmed with the back off limit value.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  * \note This function is tightly coupled with synopGMAC_retry_enable(synopGMACdevice * gmacdev)
  */
void synopGMAC_back_off_limit(GMACdevice * gmacdev, u32 value)
{
        u32 data;
        data = synopGMACReadReg((u32 *)gmacdev->MacBase, GmacConfig);
        data &= (~GmacBackoffLimit);
        data |= value;
        synopGMACWriteReg((u32 *)gmacdev->MacBase, GmacConfig,data);
        return;
}

/*
  * Disables the Deferral check in GMAC (Only in Half Duplex mode).
  * GMAC defers until the CRS signal goes inactive.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_deferral_check_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacDeferralCheck);
        return;
}

/*
  * Enable the reception of frames on GMII/MII.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_rx_enable(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacRx);
        return;
}

/*
  * Enable the transmission of frames on GMII/MII.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_tx_enable(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacTx);
        return;
}

/*
  * Selects the MII port.
  * When called MII (10/100Mbps) port is selected (programmable only in 10/100/1000 Mbps configuration).
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_select_mii(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacMiiGmii);
        return;
}

/*
  * Selects the GMII port.
  * When called GMII (1000Mbps) port is selected (programmable only in 10/100/1000 Mbps configuration).
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_select_gmii(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacMiiGmii);
        return;
}

/*
  * Selects speed 10Mb.
  * When interface mode RMII or RGMII is selected need to configure speed (1000Mb not relevant).
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_select_speed_10(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacFESpeed100 /*| GmacMiiGmii*/);
        return;
}

/*
  * Selects speed 100Mb.
  * When interface mode RMII or RGMII is selected need to configure speed (1000Mb not relevant).
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_select_speed_100(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacSelectFESpeed100);
        //synopGMACClearBits((u32 *)gmacdev->MacBase, GmacConfig, GmacMiiGmii);
        return;
}

/*
  * Disables detection of pause frames with stations unicast address.
  * When disabled GMAC only detects with the unique multicast address (802.3x).
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_unicast_pause_frame_detect_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFlowControl, GmacUnicastPauseFrame);
        return;
}

/*
  * Rx flow control enable.
  * When Enabled GMAC will decode the rx pause frame and disable the tx for a specified time.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_rx_flow_control_enable(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacFlowControl, GmacRxFlowControl);
        return;
}

/*
  * Tx flow control enable.
  * When Enabled
  *     - In full duplex GMAC enables flow control operation to transmit pause frames.
  *     - In Half duplex GMAC enables the back pressure operation
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_tx_flow_control_enable(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacFlowControl, GmacTxFlowControl);
        return;
}

/*
  * Checks whether the descriptor is empty.
  * If the buffer1 and buffer2 lengths are zero in ring mode, descriptor is empty.
  * In chain mode buffer2 length is 0 but buffer2 itself contains the next descriptor address.
  * @param[in] pointer to DmaDesc structure.
  * \return returns true if descriptor is empty, false if not empty.
  */
int synopGMAC_is_desc_empty(DmaDesc *desc)
{
//    printf("%s: desc= 0x%lx, len = 0x%x, mask=0x%x\n", __FUNCTION__,desc, desc->length, DescSize1Mask);
        //if both the buffer1 length and buffer2 length are zero desc is empty
        return(((desc->length  & DescSize1Mask) == 0));
}

/*
  * Checks whether this rx descriptor is last rx descriptor.
  * This returns true if it is last descriptor either in ring mode or in chain mode.
  * @param[in] pointer to devic structure.
  * @param[in] pointer to DmaDesc structure.
  * \return returns true if it is last descriptor, false if not.
  * \note This function should not be called before initializing the descriptor using synopGMAC_desc_init().
  */
int synopGMAC_is_last_rx_desc(GMACdevice * gmacdev,DmaDesc *desc)
{
return (((desc->length & DescEndOfRing) == DescEndOfRing) );
}

/*
  * Checks whether this tx descriptor is last tx descriptor.
  * This returns true if it is last descriptor either in ring mode or in chain mode.
  * @param[in] pointer to devic structure.
  * @param[in] pointer to DmaDesc structure.
  * \return returns true if it is last descriptor, false if not.
  * \note This function should not be called before initializing the descriptor using synopGMAC_desc_init().
  */
int synopGMAC_is_last_tx_desc(GMACdevice * gmacdev,DmaDesc *desc)
{
#ifdef SYNOP_GMAC_ENHANCED_DESCRIPTOR
return (((desc->status & DescTxEndOfRing) == DescTxEndOfRing));
#else
return (((desc->length & DescEndOfRing) == DescEndOfRing));
#endif
}

/*
  * Resumes the DMA Transmission.
  * the DmaTxPollDemand is written. (the data writeen could be anything).
  * This forces the DMA to 
 transmission.
  * @param[in] pointer to synopGMACdevice.
  * \return 0 upon success. Error code upon failure.
  */
void synopGMAC_resume_dma_tx(GMACdevice * gmacdev)
{
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaTxPollDemand, 0);

}

/*
  * Enable the DMA Transmission.
  * @param[in] pointer to synopGMACdevice.
  * \return 0 upon success. Error code upon failure.
  */
void synopGMAC_enable_dma_tx(GMACdevice * gmacdev)
{
//      synopGMACSetBits((u32 *)gmacdev->DmaBase, DmaControl, DmaTxStart);
        u32 data;
        data = synopGMACReadReg((u32 *)gmacdev->DmaBase, DmaControl);
        data |= DmaTxStart;
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaControl ,data);

}

/**
  * Checks whether the descriptor is owned by DMA.
  * If descriptor is owned by DMA then the OWN bit is set to 1. This API is same for both ring and chain mode.
  * @param[in] pointer to DmaDesc structure.
  * \return returns true if Dma owns descriptor and false if not.
  */
int synopGMAC_is_desc_owned_by_dma(DmaDesc *desc)
{
    return ((desc->status & DescOwnByDma) == DescOwnByDma );
}

/*
  * Resumes the DMA Reception.
  * the DmaRxPollDemand is written. (the data writeen could be anything).
  * This forces the DMA to resume reception.
  * @param[in] pointer to synopGMACdevice.
  * \return 0 upon success. Error code upon failure.
  */
void synopGMAC_resume_dma_rx(GMACdevice * gmacdev)
{
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaRxPollDemand, 0);

}

void clear_status_dma (GMACdevice * gmacdev)
{
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaStatus, 0);

}

/*
  * Disable the watchdog timer on the receiver.
  * When disabled, Gmac disabled watchdog timer, and can receive frames up to
  * 16,384 bytes.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_wd_disable(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacWatchdog);
        return;
}

/*
  * Enables the Jabber frame support.
  * When enabled, GMAC disabled the jabber timer, and can transfer 16,384 byte frames.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_jab_enable(GMACdevice * gmacdev)
{
        synopGMACSetBits((u32 *)gmacdev->MacBase, GmacConfig, GmacJabber);
        return;
}

/*
  * Enables forwarding of control frames.
  * When set forwards all the control frames (incl. unicast and multicast PAUSE frames).
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  * \note Depends on RFE of FlowControlRegister[2]
  */
void synopGMAC_set_pass_control(GMACdevice * gmacdev,u32 passcontrol)
{
        u32 data;
        data = synopGMACReadReg((u32 *)gmacdev->MacBase, GmacFrameFilter);
        data &= (~GmacPassControl);
        data |= passcontrol;
        synopGMACWriteReg((u32 *)gmacdev->MacBase,GmacFrameFilter,data);
        return;
}

/*
  * Enables Broadcast frames.
  * When enabled Address filtering module passes all incoming broadcast frames.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_broadcast_enable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacBroadcast);
        return;
}

/*
  * Disables Source address filtering.
  * When disabled GMAC forwards the received frames with updated SAMatch bit in RxStatus.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_src_addr_filter_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacSrcAddrFilter);
        return;
}

/*
  * Disable Multicast frames.
  * When disabled multicast frame filtering depends on HMC bit.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_multicast_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacMulticastFilter);
        return;
}

/*
  * Enables the normal Destination address filtering.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_dst_addr_filter_normal(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacDestAddrFilterNor);
        return;
}


/*
  * Disables multicast hash filtering.
  * When disabled GMAC performs perfect destination address filtering for multicast frames, it compares
  * DA field with the value programmed in DA register.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_multicast_hash_filter_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacMcastHashFilter);
        return;
}

/*
  * Clears promiscous mode.
  * When called the GMAC falls back to normal operation from promiscous mode.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_promisc_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacPromiscuousMode);
        return;
}

/*
  * Disables multicast hash filtering.
  * When disabled GMAC performs perfect destination address filtering for unicast frames, it compares
  * DA field with the value programmed in DA register.
  * @param[in] pointer to synopGMACdevice.
  * \return void.
  */
void synopGMAC_unicast_hash_filter_disable(GMACdevice * gmacdev)
{
        synopGMACClearBits((u32 *)gmacdev->MacBase, GmacFrameFilter, GmacUcastHashFilter);
        return;
}


/**
  * Function to reset the GMAC core.
  * This reests the DMA and GMAC core. After reset all the registers holds their respective reset value
  * @param[in] pointer to synopGMACdevice.
  * \return 0 on success else return the error status.
  */
s32 synopGMAC_reset (GMACdevice * gmacdev )
{
        u32 data = 0;
        synopGMACWriteReg((u32 *)gmacdev->DmaBase, DmaBusMode ,DmaResetOn);
        __udelay (2);
        data = synopGMACReadReg((u32 *)gmacdev->DmaBase, DmaBusMode);
#if 1
        while (data & DmaResetOn)
            printf("synopGMAC_reset: wait reset\n");
#endif
        return 0;
}


#if 0
void printBDR (void) 
{
	uint i,j;
	volatile uint *ptrlist, *ptr;

	ptrlist = (uint *) (GMAC_BASE_ADDR+0x100c);

	ptr = (uint *) *ptrlist;

	for (i=0;i<RECEIVE_DESC_SIZE;i++) {
		printf ("%p : ",&ptr[(i*4)]);
		for (j=0;j<4;j++)
			printf ("%8x ", ptr[(i*4)+j]);
		printf ("\n");
	}
	printf ("--------------------------------\n");
}

void printBDT (void) 
{
	uint i,j;
	volatile uint *ptrlist, *ptr;

	ptrlist = (uint *) (GMAC_BASE_ADDR+0x1010);

	ptr = (uint *) *ptrlist;

	for (i=0;i<TRANSMIT_DESC_SIZE;i++) {
		printf ("%p : ",&ptr[(i*4)]);
		for (j=0;j<4;j++)
			printf ("%8x ", ptr[(i*4)+j]);
		printf ("\n");
	}
	printf ("--------------------------------\n");
}
#endif

/************* Following code implements printing out all GMAC/DMA/PHY registers ***************************/
/************* See function dump_registers ()                                    ***************************/
enum MiiRegisters
{
  PHY_CONTROL_REG           = 0x0000,		/*Control Register*/
  PHY_STATUS_REG            = 0x0001,		/*Status Register */
  PHY_ID_HI_REG             = 0x0002,		/*PHY Identifier High Register*/
  PHY_ID_LOW_REG            = 0x0003,		/*PHY Identifier High Register*/
  PHY_AN_ADV_REG            = 0x0004,		/*Auto-Negotiation Advertisement Register*/
  PHY_LNK_PART_ABl_REG      = 0x0005,		/*Link Partner Ability Register (Base Page)*/
  PHY_AN_EXP_REG            = 0x0006,		/*Auto-Negotiation Expansion Register*/
  PHY_AN_NXT_PAGE_TX_REG    = 0x0007,		/*Next Page Transmit Register*/
  PHY_LNK_PART_NXT_PAGE_REG = 0x0008,		/*Link Partner Next Page Register*/
  PHY_1000BT_CTRL_REG       = 0x0009,		/*1000BASE-T Control Register*/
  PHY_1000BT_STATUS_REG     = 0x000a,		/*1000BASE-T Status Register*/
  PHY_SPECIFIC_CTRL_REG     = 0x0010,		/*Phy specific control register*/
  PHY_SPECIFIC_STATUS_REG   = 0x0011,		/*Phy specific status register*/
  PHY_INTERRUPT_ENABLE_REG  = 0x0012,		/*Phy interrupt enable register*/
  PHY_INTERRUPT_STATUS_REG  = 0x0013,		/*Phy interrupt status register*/
  PHY_EXT_PHY_SPC_CTRL	    = 0x0014,		/*Extended Phy specific control*/
  PHY_RX_ERR_COUNTER	    = 0x0015,		/*Receive Error Counter*/
  PHY_EXT_ADDR_CBL_DIAG     = 0x0016,		/*Extended address for cable diagnostic register*/
  PHY_LED_CONTROL	        = 0x0018,		/*LED Control*/			
  PHY_MAN_LED_OVERIDE       = 0x0019,		/*Manual LED override register*/
  PHY_EXT_PHY_SPC_CTRL2     = 0x001a,		/*Extended Phy specific control 2*/
  PHY_EXT_PHY_SPC_STATUS    = 0x001b,		/*Extended Phy specific status*/
  PHY_CBL_DIAG_REG	        = 0x001c,		/*Cable diagnostic registers*/
};

uint dump_phy_reg(struct tsec_private *priv, uint regnum)
{
	int timeout = 2000000;
	uint phyid = priv->phyaddr;
	volatile gphy_t *regbase = priv->phyregs;
	volatile uint *addr_reg,*data_reg;
uint gmii_csr_clk;
	addr_reg = (uint *)  &regbase->addReg;
	data_reg = (uint *)  &regbase->dataReg;
#if 0
	*addr_reg = ((phyid << GmiiDevShift) & GmiiDevMask) | 
			((regnum << GmiiRegShift) & GmiiRegMask) | 
			((GmiiCsrClk40 << GmiiCsrShift)  & GmiiCsrClkMask) |
			MII_WRITE;
#else
    gmii_csr_clk = GmiiCsrClk4;
	*addr_reg = ((phyid << GmiiDevShift) & GmiiDevMask) | 
                ((regnum << GmiiRegShift) & GmiiRegMask) | 
                (gmii_csr_clk) | MII_WRITE | GmiiBusy;
#endif
	while ((*addr_reg & GmiiBusy) && timeout--) ;
	if (!timeout)
		printf ("time-out occured in read regs\n");

	//printf (" 0x%08x\n",*data_reg);
	return *data_reg;
}

enum GmacExtendRegisters              
{
  /*Time Stamp Register Map*/
  GmacTSControl	          = 0x0700,  /* Controls the Timestamp update logic                         : only when IEEE 1588 time stamping is enabled in corekit            */

  GmacTSSubSecIncr     	  = 0x0704,  /* 8 bit value by which sub second register is incremented     : only when IEEE 1588 time stamping without external timestamp input */

  GmacTSHigh  	          = 0x0708,  /* 32 bit seconds(MS)                                          : only when IEEE 1588 time stamping without external timestamp input */
  GmacTSLow   	          = 0x070C,  /* 32 bit nano seconds(MS)                                     : only when IEEE 1588 time stamping without external timestamp input */
  
  GmacTSHighUpdate        = 0x0710,  /* 32 bit seconds(MS) to be written/added/subtracted           : only when IEEE 1588 time stamping without external timestamp input */
  GmacTSLowUpdate         = 0x0714,  /* 32 bit nano seconds(MS) to be writeen/added/subtracted      : only when IEEE 1588 time stamping without external timestamp input */
  
  GmacTSAddend            = 0x0718,  /* Used by Software to readjust the clock frequency linearly   : only when IEEE 1588 time stamping without external timestamp input */
  
  GmacTSTargetTimeHigh 	  = 0x071C,  /* 32 bit seconds(MS) to be compared with system time          : only when IEEE 1588 time stamping without external timestamp input */
  GmacTSTargetTimeLow     = 0x0720,  /* 32 bit nano seconds(MS) to be compared with system time     : only when IEEE 1588 time stamping without external timestamp input */

  GmacTSHighWord          = 0x0724,  /* Time Stamp Higher Word Register (Version 2 only); only lower 16 bits are valid                                                   */
  //GmacTSHighWordUpdate    = 0x072C,  /* Time Stamp Higher Word Update Register (Version 2 only); only lower 16 bits are valid                                            */
  
  GmacTSStatus            = 0x0728,  /* Time Stamp Status Register                                                                                                       */
};

static u32 __inline__ synopGMACDumpReg(u32 *RegBase, u32 RegOffset)
{
  u32 addr = (u32)RegBase + RegOffset;
  u32 data = readl((void *)addr);
  //printf (" 0x%08x\n",data);
  return data;

}


#ifdef VBG400_DUMP_REGS

void dump_registers(struct tsec_private *priv)
{
	volatile GMACdevice *gmacdev = priv->gmacRegs;
    int n = 0;
    int i = 0;

    printf("dump_registers (u-boot)\n");
    for (n=0; n<0xDC/*0x60*/; n+=4) {
        if (n<0x54 || n>0xBC)
            printf("%d MAC Register %08x (%08x) = %08x\n", i, n, (u32 *)gmacdev->MacBase+i, synopGMACDumpReg((u32 *)gmacdev->MacBase, n));
        i++;
    }
    i=0;
    for (n=0; n<0x5C/*0x60*/; n+=4) {
        if (n<0x30 || n>0x44)
            printf("%d DMA Register %08x (%08x) = %08x\n", i, n, (u32 *)gmacdev->DmaBase+i, synopGMACDumpReg((u32 *)gmacdev->DmaBase, n));
        i++;
    }
    for (n=0; n<0x001f; n+=1) {
	    //printf("%d PHY Register %08x\n",n,dump_phy_reg(priv,n));
	    printf("%d PHY Register %08x\n",n,read_phy_reg(priv,n));
    }
}
#endif
