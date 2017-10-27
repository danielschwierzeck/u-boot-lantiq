
#include <common.h>
#include <command.h>

//#ifdef VBG400_COMPILE_EFUSE

#define VBG400_MAC_HT_EXTENSION_BASE	    0x001F0000 /*hyp_mac_top: base addr for 'select addr' and 'fix value' for shram*/
#define VBG400_EMERALD_ENV_BASE		        0x00180000 /*CPU system I/F: base addr for 'select addr' and 'fix value' for other memories*/

/*the next registers are in the "shared reg"*/
#define VBG400_EFUSE_DATA_OFFSET		    0x120
#define VBG400_EFUSE_ADDR_OFFSET		    0x124
#define VBG400_EFUSE_CONTROL_OFFSET	        0x128
#define VBG400_EFUSE_STATUS_OFFSET	        0x12C
#define VBG400_EFUSE_PD_OFFSET		        0x13C
/*the next registers are in the "MAC_HT_extensions"( 0x001f0000)*/
#define VBG400_MAC_HT_EXT_SHRAM_RM_OFFSET	0x178
#define VBG400_MAC_HT_EXT_RAMS_RM_OFFSET	0x17C
/*the next registers are in the "emerald_env regs" (0x00180000)*/
#define VBG400_BIST_RED_FIX_SEL_OFFSET		0xE0
#define VBG400_RED_FIX_LOAD_VAL_OFFSET		0xEC
/*other definitions*/
#define VBG400_EFUSE_STATUS_CTRL_BUSY_FIELD	0x1
#define VBG400_EFUSE_STATUS_WR_RD_FIELD		0x2
#define VBG400_EFUSE_MEM_FIX_MAX           18
#define VBG400_EFUSE_CALIBRATION_MAX		18
//#define VBG400_EFUSE_BYTES_READ_MAX (VBG400_EFUSE_MEM_FIX_MAX+ VBG400_EFUSE_CALIBRATION_MAX)
#define VBG400_EFUSE_BYTES_READ_MAX VBG400_EFUSE_MEM_FIX_MAX
/*point to cell in array*/
#define EFUSE_OFFSET_SELECT_INDEX   0
#define EFUSE_OFFSET_DATA_INDEX   1

/* There are some HW limitations that make the code complicated:
*   1. fix vector (8bits) of RAM is written to one or more locations (ram type dependent).
*      efuse_loops_per_ram[] - holds number of addresses per RAM.
*      efuse_ram_select[][] - holds the ram index to use per RAM.
*   2. different base address for SHRAM than other RAMs
*      efuse_base[] is used for it.
*   3. different offset for SHRAM than other RAMs.
*      efuse_offset[][] - holds the offsets (addr+data) per RAM
*/

/*any uninitialize data is put in bss section. bss is outside of bootstrap image (after uboot_end_data).
* u-boot.ltq is built of bootstrp.bin and u-boot.lzimg. When bootstrap uses uninitialized param it
* overwrite lzma header and u-boot.lzimg.
* Therefore, efuse_data is initialized to dummy value (1) to force it to other memory section*/
static u32 efuse_data[VBG400_EFUSE_BYTES_READ_MAX] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

static u32 efuse_loops_per_ram[18] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 4};

#define _NULL 0

static u32 efuse_ram_select[18][4] = {{0,_NULL,_NULL,_NULL},    /*shram0*/
                                         {2,_NULL,_NULL,_NULL},    /*shram1*/
                                         {4,_NULL,_NULL,_NULL},    /*shram2*/
                                         {6,_NULL,_NULL,_NULL},    /*shram3*/
                                         {0x10,_NULL,_NULL,_NULL}, /*cpu_ram0*/
                                         {0x12,_NULL,_NULL,_NULL}, /*cpu_ram1*/
                                         {0x14,_NULL,_NULL,_NULL}, /*cpu_ram2*/
                                         {0x16,_NULL,_NULL,_NULL}, /*cpu_ram3*/
                                         {0x18,_NULL,_NULL,_NULL}, /*cpu_ram4*/
                                         {0x1a,_NULL,_NULL,_NULL}, /*cpu_ram5*/
                                         {0x1C,_NULL,_NULL,_NULL}, /*cpu_ram6*/
                                         {0x1E,_NULL,_NULL,_NULL}, /*cpu_ram7*/
                                         {0x20,_NULL,_NULL,_NULL}, /*cpu_ram8*/
                                         {0x22,_NULL,_NULL,_NULL}, /*cpu_ram9*/
                                         {0x24,_NULL,_NULL,_NULL}, /*cpu_ram10*/
                                         {0x8,0x9,_NULL,_NULL},    /*dcache0*/
                                         {0xa,0xb,_NULL,_NULL},    /*dcache1*/
                                         {0,1,2,3}};               /*icache*/

static u32 efuse_base[] =            {VBG400_MAC_HT_EXTENSION_BASE,\
                                         VBG400_MAC_HT_EXTENSION_BASE,\
                                         VBG400_MAC_HT_EXTENSION_BASE,\
                                         VBG400_MAC_HT_EXTENSION_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE,\
                                         VBG400_EMERALD_ENV_BASE};

static u32 efuse_offset[18][2] =        {{VBG400_MAC_HT_EXT_SHRAM_RM_OFFSET, VBG400_MAC_HT_EXT_RAMS_RM_OFFSET},
                                         {VBG400_MAC_HT_EXT_SHRAM_RM_OFFSET, VBG400_MAC_HT_EXT_RAMS_RM_OFFSET},
                                         {VBG400_MAC_HT_EXT_SHRAM_RM_OFFSET, VBG400_MAC_HT_EXT_RAMS_RM_OFFSET},
                                         {VBG400_MAC_HT_EXT_SHRAM_RM_OFFSET, VBG400_MAC_HT_EXT_RAMS_RM_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET},
                                         {VBG400_BIST_RED_FIX_SEL_OFFSET, VBG400_RED_FIX_LOAD_VAL_OFFSET}};


/**********************************************************************
*  read_efuse()
*  Description: read eFuse and write the fix vector in order to fix RAMs
*  Algorithm:
*    Read eFuse
*      1.	Disable PD bit in Efuse_PD register by writing "0"
*      2.	Check BSY bit is cleared and DONE bit is set by reading STATUS register
*      3.	Write the Byte Address in the ADDR register
*      4.	Write "0" to the efuse_control register.
*      5.	Poll the EFUSE_STATUS register until the BSY bit is cleared
*      6.	Read the value from the EFUSE_DATA register (for more bytes do 1-6 in a loop)
*      7.	Enable PD bit in Efuse_PD register by writing "1".
*    Write the vector
*    "fix vector" is compressed into 8 bits. It holds bit fix number +1, only one fix bit exist.
*    It has to '-1' and change it to 32 bits having the appropriated bit set
*    Every "fix vectore" may have one target address (RAM address to write the vector) and up to 4 addresses.
*    Every address holds "fix vector" is 32 bits size.
*      1.	data = "fix vector" - 1
*      2.	if more than one target address:
*        2.1	select proper address out of max 4
*        2.2	data is 32 bits aligned, calculate new data based on it's target address
*/
void read_efuse(void)
{
    u32 data;
    int i;
    int ram_field_index;
    int vector;

    /*Read eFuse:
    * loop on all redundancy fix information bytes (what about calibrations?),
    * start from byte 2
    */
    for (i=2; i< VBG400_EFUSE_BYTES_READ_MAX+2; i++)
    {
        WriteReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_PD_OFFSET, 0);
        data=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_STATUS_OFFSET);
        /*wait for done bit set and busy bit to clear */
        while ( ! (data & VBG400_EFUSE_STATUS_WR_RD_FIELD) &&
                (data & VBG400_EFUSE_STATUS_CTRL_BUSY_FIELD))
        {
            //OPEN - use timer to failure?
            data=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_STATUS_OFFSET);
        }
        /*to read the next byte advance address by 8*/
        WriteReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_ADDR_OFFSET, i<<3);
        WriteReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_CONTROL_OFFSET, 0);
        data=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_STATUS_OFFSET);
        while (data & VBG400_EFUSE_STATUS_CTRL_BUSY_FIELD)
        {
            //OPEN - use timer to failure?
            data=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_STATUS_OFFSET);
        }
        efuse_data[i-2]=ReadReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_DATA_OFFSET);
    }
    WriteReg(VBG400_SYS_INTERFACE_BASE_ADDR, VBG400_EFUSE_PD_OFFSET, 1);
    
    /*Fix RAMs:
    * write the "fix vectors" to the RAMs allocated address
    */
    for (i=0; i< VBG400_EFUSE_MEM_FIX_MAX; i++)
    {
        /*only if fix is needed*/
        if (efuse_data[i] != 0)
        {
            ram_field_index = 0;
            data = efuse_data[i] - 1;
            if (efuse_loops_per_ram[i] > 1) {
                /*vector target bigger than 1 address (value can be higher than 32),
                  find the address to write to and chnage fix accordingly (data is 32 bits aliged up to 128 bits)*/
                if (efuse_data[i] > 32) {
                    data = efuse_data[i] - 1 - 32;
                    ram_field_index = 1;
                }
                else if (efuse_data[i] > 64) {
                    data = efuse_data[i] - 1 - 64;
                    ram_field_index = 2;
                }
                else if (efuse_data[i] > 96) {
                    data = efuse_data[i] - 1 - 96;
                    ram_field_index = 3;
                }
            }
            /*At this stage we have fixed value to create vector from
            */
            vector = 1<<data;
            WriteReg(efuse_base[i], efuse_offset[i][EFUSE_OFFSET_SELECT_INDEX], efuse_ram_select[i][ram_field_index]);
            WriteReg(efuse_base[i], efuse_offset[i][EFUSE_OFFSET_DATA_INDEX], vector);
        }
    }
}
//#endif VBG400_COMPILE_EFUSE
