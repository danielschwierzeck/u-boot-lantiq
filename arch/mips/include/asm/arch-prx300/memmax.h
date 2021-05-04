/*----------------------------------------------------------------------------- */
/* LSD Generator */
/*----------------------------------------------------------------------------- */
/* Perl Package        : LSD::generator::targetC (v1.1) */
/* LSD Source          : C:/Users/huchunfe/Perforce/huchunfe_huchunfe-MOBL1_dev.FalcONT/ipg_lsd/lsd_sys/source/xml/reg_files/memmax_memmax.xml */
/* Register File Name  : MEMMAX */
/* Register File Title : DDR Memory Access Scheduler Register Description */
/* Register Width      : 64 */
/* Note                : Doxygen compliant comments */
/*----------------------------------------------------------------------------- */

#ifndef _MEMMAX_H
#define _MEMMAX_H

/*! \defgroup MEMMAX Register File MEMMAX - DDR Memory Access Scheduler Register Description */
/*! @{ */

/*! Base Address of DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MODULE_BASE 0x12200000u

/*! \defgroup MEMMAX_DRAMCONFIG Register MEMMAX_DRAMCONFIG - DRAMCONFIG */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_DRAMCONFIG 0x0
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_DRAMCONFIG 0x12200000u

/*! Register Reset Value */
#define MEMMAX_DRAMCONFIG_RST 0x00000000100C0131u

/*! Field BANK8 - bank8 */
#define MEMMAX_DRAMCONFIG_BANK8_POS 0
/*! Field BANK8 - bank8 */
#define MEMMAX_DRAMCONFIG_BANK8_MASK 0x1u

/*! Field DRAM_BURST_TYPE - dram_burst_type */
#define MEMMAX_DRAMCONFIG_DRAM_BURST_TYPE_POS 2
/*! Field DRAM_BURST_TYPE - dram_burst_type */
#define MEMMAX_DRAMCONFIG_DRAM_BURST_TYPE_MASK 0x4u

/*! Field DRAM_TYPE - dram_type */
#define MEMMAX_DRAMCONFIG_DRAM_TYPE_POS 4
/*! Field DRAM_TYPE - dram_type */
#define MEMMAX_DRAMCONFIG_DRAM_TYPE_MASK 0x30u

/*! Field DRAM_BLK_LOGSIZE - dram_blk_logsize */
#define MEMMAX_DRAMCONFIG_DRAM_BLK_LOGSIZE_POS 8
/*! Field DRAM_BLK_LOGSIZE - dram_blk_logsize */
#define MEMMAX_DRAMCONFIG_DRAM_BLK_LOGSIZE_MASK 0x700u

/*! Field BANK_BIT_LOCATION - bank_bit_location */
#define MEMMAX_DRAMCONFIG_BANK_BIT_LOCATION_POS 16
/*! Field BANK_BIT_LOCATION - bank_bit_location */
#define MEMMAX_DRAMCONFIG_BANK_BIT_LOCATION_MASK 0xF0000u

/*! Field CHIP_BIT_LOCATION - chip_bit_location */
#define MEMMAX_DRAMCONFIG_CHIP_BIT_LOCATION_POS 24
/*! Field CHIP_BIT_LOCATION - chip_bit_location */
#define MEMMAX_DRAMCONFIG_CHIP_BIT_LOCATION_MASK 0x7000000u

/*! Field CHIP_BITS - chip_bits */
#define MEMMAX_DRAMCONFIG_CHIP_BITS_POS 28
/*! Field CHIP_BITS - chip_bits */
#define MEMMAX_DRAMCONFIG_CHIP_BITS_MASK 0x30000000u

/*! @} */

/*! \defgroup MEMMAX_DRAMREGCONFIG Register MEMMAX_DRAMREGCONFIG - DRAMREGCONFIG */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_DRAMREGCONFIG 0x8
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_DRAMREGCONFIG 0x12200008u

/*! Register Reset Value */
#define MEMMAX_DRAMREGCONFIG_RST 0x0000000000400000u

/*! Field REG_BASE_ADDR - reg_base_addr */
#define MEMMAX_DRAMREGCONFIG_REG_BASE_ADDR_POS 0
/*! Field REG_BASE_ADDR - reg_base_addr */
#define MEMMAX_DRAMREGCONFIG_REG_BASE_ADDR_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup MEMMAX_GLOBALSCHEDULING Register MEMMAX_GLOBALSCHEDULING - GLOBALSCHEDULING */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_GLOBALSCHEDULING 0x10
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_GLOBALSCHEDULING 0x12200010u

/*! Register Reset Value */
#define MEMMAX_GLOBALSCHEDULING_RST 0x0000000000000000u

/*! Field BANKBUSY_TREAD - bankbusy_tread */
#define MEMMAX_GLOBALSCHEDULING_BANKBUSY_TREAD_POS 32
/*! Field BANKBUSY_TREAD - bankbusy_tread */
#define MEMMAX_GLOBALSCHEDULING_BANKBUSY_TREAD_MASK 0xFF00000000u

/*! Field BANKBUSY_TWRITE - bankbusy_twrite */
#define MEMMAX_GLOBALSCHEDULING_BANKBUSY_TWRITE_POS 40
/*! Field BANKBUSY_TWRITE - bankbusy_twrite */
#define MEMMAX_GLOBALSCHEDULING_BANKBUSY_TWRITE_MASK 0xFF0000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCH0 Register MEMMAX_THREADSCH0 - THREADSCH0 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH0 0x20
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH0 0x12200020u

/*! Register Reset Value */
#define MEMMAX_THREADSCH0_RST 0x0016002004000001u

/*! Field QOS_MODE0 - qos_mode0 */
#define MEMMAX_THREADSCH0_QOS_MODE0_POS 0
/*! Field QOS_MODE0 - qos_mode0 */
#define MEMMAX_THREADSCH0_QOS_MODE0_MASK 0x3u

/*! Field PAGEMODE0 - pagemode0 */
#define MEMMAX_THREADSCH0_PAGEMODE0_POS 7
/*! Field PAGEMODE0 - pagemode0 */
#define MEMMAX_THREADSCH0_PAGEMODE0_MASK 0x80u

/*! Field STARVATION_COUNTER0 - starvation_counter0 */
#define MEMMAX_THREADSCH0_STARVATION_COUNTER0_POS 8
/*! Field STARVATION_COUNTER0 - starvation_counter0 */
#define MEMMAX_THREADSCH0_STARVATION_COUNTER0_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE0 - request_group_size0 */
#define MEMMAX_THREADSCH0_REQUEST_GROUP_SIZE0_POS 24
/*! Field REQUEST_GROUP_SIZE0 - request_group_size0 */
#define MEMMAX_THREADSCH0_REQUEST_GROUP_SIZE0_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE0 - bandwidth_rate0 */
#define MEMMAX_THREADSCH0_BANDWIDTH_RATE0_POS 32
/*! Field BANDWIDTH_RATE0 - bandwidth_rate0 */
#define MEMMAX_THREADSCH0_BANDWIDTH_RATE0_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD0 - words_per_period0 */
#define MEMMAX_THREADSCH0_WORDS_PER_PERIOD0_POS 48
/*! Field WORDS_PER_PERIOD0 - words_per_period0 */
#define MEMMAX_THREADSCH0_WORDS_PER_PERIOD0_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT0 Register MEMMAX_THREADSCHEXT0 - THREADSCHEXT0 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT0 0x28
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT0 0x12200028u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT0_RST 0x0000000000000004u

/*! Field WORDS_PER_PERIOD_MAX0 - words_per_period_max0 */
#define MEMMAX_THREADSCHEXT0_WORDS_PER_PERIOD_MAX0_POS 0
/*! Field WORDS_PER_PERIOD_MAX0 - words_per_period_max0 */
#define MEMMAX_THREADSCHEXT0_WORDS_PER_PERIOD_MAX0_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_THREADSCH1 Register MEMMAX_THREADSCH1 - THREADSCH1 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH1 0x30
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH1 0x12200030u

/*! Register Reset Value */
#define MEMMAX_THREADSCH1_RST 0x0016002004000001u

/*! Field QOS_MODE1 - qos_mode1 */
#define MEMMAX_THREADSCH1_QOS_MODE1_POS 0
/*! Field QOS_MODE1 - qos_mode1 */
#define MEMMAX_THREADSCH1_QOS_MODE1_MASK 0x3u

/*! Field PAGEMODE1 - pagemode1 */
#define MEMMAX_THREADSCH1_PAGEMODE1_POS 7
/*! Field PAGEMODE1 - pagemode1 */
#define MEMMAX_THREADSCH1_PAGEMODE1_MASK 0x80u

/*! Field STARVATION_COUNTER1 - starvation_counter1 */
#define MEMMAX_THREADSCH1_STARVATION_COUNTER1_POS 8
/*! Field STARVATION_COUNTER1 - starvation_counter1 */
#define MEMMAX_THREADSCH1_STARVATION_COUNTER1_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE1 - request_group_size1 */
#define MEMMAX_THREADSCH1_REQUEST_GROUP_SIZE1_POS 24
/*! Field REQUEST_GROUP_SIZE1 - request_group_size1 */
#define MEMMAX_THREADSCH1_REQUEST_GROUP_SIZE1_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE1 - bandwidth_rate1 */
#define MEMMAX_THREADSCH1_BANDWIDTH_RATE1_POS 32
/*! Field BANDWIDTH_RATE1 - bandwidth_rate1 */
#define MEMMAX_THREADSCH1_BANDWIDTH_RATE1_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD1 - words_per_period1 */
#define MEMMAX_THREADSCH1_WORDS_PER_PERIOD1_POS 48
/*! Field WORDS_PER_PERIOD1 - words_per_period1 */
#define MEMMAX_THREADSCH1_WORDS_PER_PERIOD1_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT1 Register MEMMAX_THREADSCHEXT1 - THREADSCHEXT1 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT1 0x38
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT1 0x12200038u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT1_RST 0x0000000000000004u

/*! Field WORDS_PER_PERIOD_MAX1 - words_per_period_max1 */
#define MEMMAX_THREADSCHEXT1_WORDS_PER_PERIOD_MAX1_POS 0
/*! Field WORDS_PER_PERIOD_MAX1 - words_per_period_max1 */
#define MEMMAX_THREADSCHEXT1_WORDS_PER_PERIOD_MAX1_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_THREADSCH2 Register MEMMAX_THREADSCH2 - THREADSCH2 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH2 0x40
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH2 0x12200040u

/*! Register Reset Value */
#define MEMMAX_THREADSCH2_RST 0x0016002004000001u

/*! Field QOS_MODE2 - qos_mode2 */
#define MEMMAX_THREADSCH2_QOS_MODE2_POS 0
/*! Field QOS_MODE2 - qos_mode2 */
#define MEMMAX_THREADSCH2_QOS_MODE2_MASK 0x3u

/*! Field PAGEMODE2 - pagemode2 */
#define MEMMAX_THREADSCH2_PAGEMODE2_POS 7
/*! Field PAGEMODE2 - pagemode2 */
#define MEMMAX_THREADSCH2_PAGEMODE2_MASK 0x80u

/*! Field STARVATION_COUNTER2 - starvation_counter2 */
#define MEMMAX_THREADSCH2_STARVATION_COUNTER2_POS 8
/*! Field STARVATION_COUNTER2 - starvation_counter2 */
#define MEMMAX_THREADSCH2_STARVATION_COUNTER2_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE2 - request_group_size2 */
#define MEMMAX_THREADSCH2_REQUEST_GROUP_SIZE2_POS 24
/*! Field REQUEST_GROUP_SIZE2 - request_group_size2 */
#define MEMMAX_THREADSCH2_REQUEST_GROUP_SIZE2_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE2 - bandwidth_rate2 */
#define MEMMAX_THREADSCH2_BANDWIDTH_RATE2_POS 32
/*! Field BANDWIDTH_RATE2 - bandwidth_rate2 */
#define MEMMAX_THREADSCH2_BANDWIDTH_RATE2_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD2 - words_per_period2 */
#define MEMMAX_THREADSCH2_WORDS_PER_PERIOD2_POS 48
/*! Field WORDS_PER_PERIOD2 - words_per_period2 */
#define MEMMAX_THREADSCH2_WORDS_PER_PERIOD2_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT2 Register MEMMAX_THREADSCHEXT2 - THREADSCHEXT2 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT2 0x48
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT2 0x12200048u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT2_RST 0x0000000000000004u

/*! Field WORDS_PER_PERIOD_MAX2 - words_per_period_max2 */
#define MEMMAX_THREADSCHEXT2_WORDS_PER_PERIOD_MAX2_POS 0
/*! Field WORDS_PER_PERIOD_MAX2 - words_per_period_max2 */
#define MEMMAX_THREADSCHEXT2_WORDS_PER_PERIOD_MAX2_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_THREADSCH3 Register MEMMAX_THREADSCH3 - THREADSCH3 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH3 0x50
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH3 0x12200050u

/*! Register Reset Value */
#define MEMMAX_THREADSCH3_RST 0x0016002004000001u

/*! Field QOS_MODE3 - qos_mode3 */
#define MEMMAX_THREADSCH3_QOS_MODE3_POS 0
/*! Field QOS_MODE3 - qos_mode3 */
#define MEMMAX_THREADSCH3_QOS_MODE3_MASK 0x3u

/*! Field PAGEMODE3 - pagemode3 */
#define MEMMAX_THREADSCH3_PAGEMODE3_POS 7
/*! Field PAGEMODE3 - pagemode3 */
#define MEMMAX_THREADSCH3_PAGEMODE3_MASK 0x80u

/*! Field STARVATION_COUNTER3 - starvation_counter3 */
#define MEMMAX_THREADSCH3_STARVATION_COUNTER3_POS 8
/*! Field STARVATION_COUNTER3 - starvation_counter3 */
#define MEMMAX_THREADSCH3_STARVATION_COUNTER3_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE3 - request_group_size3 */
#define MEMMAX_THREADSCH3_REQUEST_GROUP_SIZE3_POS 24
/*! Field REQUEST_GROUP_SIZE3 - request_group_size3 */
#define MEMMAX_THREADSCH3_REQUEST_GROUP_SIZE3_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE3 - bandwidth_rate3 */
#define MEMMAX_THREADSCH3_BANDWIDTH_RATE3_POS 32
/*! Field BANDWIDTH_RATE3 - bandwidth_rate3 */
#define MEMMAX_THREADSCH3_BANDWIDTH_RATE3_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD3 - words_per_period3 */
#define MEMMAX_THREADSCH3_WORDS_PER_PERIOD3_POS 48
/*! Field WORDS_PER_PERIOD3 - words_per_period3 */
#define MEMMAX_THREADSCH3_WORDS_PER_PERIOD3_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT3 Register MEMMAX_THREADSCHEXT3 - THREADSCHEXT3 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT3 0x58
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT3 0x12200058u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT3_RST 0x0000000000000004u

/*! Field WORDS_PER_PERIOD_MAX3 - words_per_period_max3 */
#define MEMMAX_THREADSCHEXT3_WORDS_PER_PERIOD_MAX3_POS 0
/*! Field WORDS_PER_PERIOD_MAX3 - words_per_period_max3 */
#define MEMMAX_THREADSCHEXT3_WORDS_PER_PERIOD_MAX3_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_THREADSCH4 Register MEMMAX_THREADSCH4 - THREADSCH4 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH4 0x60
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH4 0x12200060u

/*! Register Reset Value */
#define MEMMAX_THREADSCH4_RST 0x0016002004000001u

/*! Field QOS_MODE4 - qos_mode4 */
#define MEMMAX_THREADSCH4_QOS_MODE4_POS 0
/*! Field QOS_MODE4 - qos_mode4 */
#define MEMMAX_THREADSCH4_QOS_MODE4_MASK 0x3u

/*! Field PAGEMODE4 - pagemode4 */
#define MEMMAX_THREADSCH4_PAGEMODE4_POS 7
/*! Field PAGEMODE4 - pagemode4 */
#define MEMMAX_THREADSCH4_PAGEMODE4_MASK 0x80u

/*! Field STARVATION_COUNTER4 - starvation_counter4 */
#define MEMMAX_THREADSCH4_STARVATION_COUNTER4_POS 8
/*! Field STARVATION_COUNTER4 - starvation_counter4 */
#define MEMMAX_THREADSCH4_STARVATION_COUNTER4_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE4 - request_group_size4 */
#define MEMMAX_THREADSCH4_REQUEST_GROUP_SIZE4_POS 24
/*! Field REQUEST_GROUP_SIZE4 - request_group_size4 */
#define MEMMAX_THREADSCH4_REQUEST_GROUP_SIZE4_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE4 - bandwidth_rate4 */
#define MEMMAX_THREADSCH4_BANDWIDTH_RATE4_POS 32
/*! Field BANDWIDTH_RATE4 - bandwidth_rate4 */
#define MEMMAX_THREADSCH4_BANDWIDTH_RATE4_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD4 - words_per_period4 */
#define MEMMAX_THREADSCH4_WORDS_PER_PERIOD4_POS 48
/*! Field WORDS_PER_PERIOD4 - words_per_period4 */
#define MEMMAX_THREADSCH4_WORDS_PER_PERIOD4_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT4 Register MEMMAX_THREADSCHEXT4 - THREADSCHEXT4 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT4 0x68
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT4 0x12200068u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT4_RST 0x0000000000000004u

/*! Field WORDS_PER_PERIOD_MAX4 - words_per_period_max4 */
#define MEMMAX_THREADSCHEXT4_WORDS_PER_PERIOD_MAX4_POS 0
/*! Field WORDS_PER_PERIOD_MAX4 - words_per_period_max4 */
#define MEMMAX_THREADSCHEXT4_WORDS_PER_PERIOD_MAX4_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_THREADSCH5 Register MEMMAX_THREADSCH5 - THREADSCH5 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH5 0x70
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH5 0x12200070u

/*! Register Reset Value */
#define MEMMAX_THREADSCH5_RST 0x0016002004000001u

/*! Field QOS_MODE5 - qos_mode5 */
#define MEMMAX_THREADSCH5_QOS_MODE5_POS 0
/*! Field QOS_MODE5 - qos_mode5 */
#define MEMMAX_THREADSCH5_QOS_MODE5_MASK 0x3u

/*! Field PAGEMODE5 - pagemode5 */
#define MEMMAX_THREADSCH5_PAGEMODE5_POS 7
/*! Field PAGEMODE5 - pagemode5 */
#define MEMMAX_THREADSCH5_PAGEMODE5_MASK 0x80u

/*! Field STARVATION_COUNTER5 - starvation_counter5 */
#define MEMMAX_THREADSCH5_STARVATION_COUNTER5_POS 8
/*! Field STARVATION_COUNTER5 - starvation_counter5 */
#define MEMMAX_THREADSCH5_STARVATION_COUNTER5_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE5 - request_group_size5 */
#define MEMMAX_THREADSCH5_REQUEST_GROUP_SIZE5_POS 24
/*! Field REQUEST_GROUP_SIZE5 - request_group_size5 */
#define MEMMAX_THREADSCH5_REQUEST_GROUP_SIZE5_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE5 - bandwidth_rate5 */
#define MEMMAX_THREADSCH5_BANDWIDTH_RATE5_POS 32
/*! Field BANDWIDTH_RATE5 - bandwidth_rate5 */
#define MEMMAX_THREADSCH5_BANDWIDTH_RATE5_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD5 - words_per_period5 */
#define MEMMAX_THREADSCH5_WORDS_PER_PERIOD5_POS 48
/*! Field WORDS_PER_PERIOD5 - words_per_period5 */
#define MEMMAX_THREADSCH5_WORDS_PER_PERIOD5_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT5 Register MEMMAX_THREADSCHEXT5 - THREADSCHEXT5 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT5 0x78
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT5 0x12200078u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT5_RST 0x0000000000000004u

/*! Field WORDS_PER_PERIOD_MAX5 - words_per_period_max5 */
#define MEMMAX_THREADSCHEXT5_WORDS_PER_PERIOD_MAX5_POS 0
/*! Field WORDS_PER_PERIOD_MAX5 - words_per_period_max5 */
#define MEMMAX_THREADSCHEXT5_WORDS_PER_PERIOD_MAX5_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_THREADSCH6 Register MEMMAX_THREADSCH6 - THREADSCH6 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH6 0x80
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH6 0x12200080u

/*! Register Reset Value */
#define MEMMAX_THREADSCH6_RST 0x0016002004000002u

/*! Field QOS_MODE6 - qos_mode6 */
#define MEMMAX_THREADSCH6_QOS_MODE6_POS 0
/*! Field QOS_MODE6 - qos_mode6 */
#define MEMMAX_THREADSCH6_QOS_MODE6_MASK 0x3u

/*! Field PAGEMODE6 - pagemode6 */
#define MEMMAX_THREADSCH6_PAGEMODE6_POS 7
/*! Field PAGEMODE6 - pagemode6 */
#define MEMMAX_THREADSCH6_PAGEMODE6_MASK 0x80u

/*! Field STARVATION_COUNTER6 - starvation_counter6 */
#define MEMMAX_THREADSCH6_STARVATION_COUNTER6_POS 8
/*! Field STARVATION_COUNTER6 - starvation_counter6 */
#define MEMMAX_THREADSCH6_STARVATION_COUNTER6_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE6 - request_group_size6 */
#define MEMMAX_THREADSCH6_REQUEST_GROUP_SIZE6_POS 24
/*! Field REQUEST_GROUP_SIZE6 - request_group_size6 */
#define MEMMAX_THREADSCH6_REQUEST_GROUP_SIZE6_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE6 - bandwidth_rate6 */
#define MEMMAX_THREADSCH6_BANDWIDTH_RATE6_POS 32
/*! Field BANDWIDTH_RATE6 - bandwidth_rate6 */
#define MEMMAX_THREADSCH6_BANDWIDTH_RATE6_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD6 - words_per_period6 */
#define MEMMAX_THREADSCH6_WORDS_PER_PERIOD6_POS 48
/*! Field WORDS_PER_PERIOD6 - words_per_period6 */
#define MEMMAX_THREADSCH6_WORDS_PER_PERIOD6_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT6 Register MEMMAX_THREADSCHEXT6 - THREADSCHEXT6 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT6 0x88
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT6 0x12200088u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT6_RST 0x0000000000000004u

/*! Field WORDS_PER_PERIOD_MAX6 - words_per_period_max6 */
#define MEMMAX_THREADSCHEXT6_WORDS_PER_PERIOD_MAX6_POS 0
/*! Field WORDS_PER_PERIOD_MAX6 - words_per_period_max6 */
#define MEMMAX_THREADSCHEXT6_WORDS_PER_PERIOD_MAX6_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_THREADSCH7 Register MEMMAX_THREADSCH7 - THREADSCH7 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCH7 0x90
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCH7 0x12200090u

/*! Register Reset Value */
#define MEMMAX_THREADSCH7_RST 0x0001002000000000u

/*! Field QOS_MODE7 - qos_mode7 */
#define MEMMAX_THREADSCH7_QOS_MODE7_POS 0
/*! Field QOS_MODE7 - qos_mode7 */
#define MEMMAX_THREADSCH7_QOS_MODE7_MASK 0x3u

/*! Field PAGEMODE7 - pagemode7 */
#define MEMMAX_THREADSCH7_PAGEMODE7_POS 7
/*! Field PAGEMODE7 - pagemode7 */
#define MEMMAX_THREADSCH7_PAGEMODE7_MASK 0x80u

/*! Field STARVATION_COUNTER7 - starvation_counter7 */
#define MEMMAX_THREADSCH7_STARVATION_COUNTER7_POS 8
/*! Field STARVATION_COUNTER7 - starvation_counter7 */
#define MEMMAX_THREADSCH7_STARVATION_COUNTER7_MASK 0xFF00u

/*! Field REQUEST_GROUP_SIZE7 - request_group_size7 */
#define MEMMAX_THREADSCH7_REQUEST_GROUP_SIZE7_POS 24
/*! Field REQUEST_GROUP_SIZE7 - request_group_size7 */
#define MEMMAX_THREADSCH7_REQUEST_GROUP_SIZE7_MASK 0xFF000000u

/*! Field BANDWIDTH_RATE7 - bandwidth_rate7 */
#define MEMMAX_THREADSCH7_BANDWIDTH_RATE7_POS 32
/*! Field BANDWIDTH_RATE7 - bandwidth_rate7 */
#define MEMMAX_THREADSCH7_BANDWIDTH_RATE7_MASK 0xFFFF00000000u

/*! Field WORDS_PER_PERIOD7 - words_per_period7 */
#define MEMMAX_THREADSCH7_WORDS_PER_PERIOD7_POS 48
/*! Field WORDS_PER_PERIOD7 - words_per_period7 */
#define MEMMAX_THREADSCH7_WORDS_PER_PERIOD7_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup MEMMAX_THREADSCHEXT7 Register MEMMAX_THREADSCHEXT7 - THREADSCHEXT7 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_THREADSCHEXT7 0x98
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_THREADSCHEXT7 0x12200098u

/*! Register Reset Value */
#define MEMMAX_THREADSCHEXT7_RST 0x0000000000000001u

/*! Field WORDS_PER_PERIOD_MAX7 - words_per_period_max7 */
#define MEMMAX_THREADSCHEXT7_WORDS_PER_PERIOD_MAX7_POS 0
/*! Field WORDS_PER_PERIOD_MAX7 - words_per_period_max7 */
#define MEMMAX_THREADSCHEXT7_WORDS_PER_PERIOD_MAX7_MASK 0xFFFFu

/*! @} */

/*! \defgroup MEMMAX_TILING_SWAP0 Register MEMMAX_TILING_SWAP0 - TILING_SWAP0 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_SWAP0 0x120
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_SWAP0 0x12200120u

/*! Register Reset Value */
#define MEMMAX_TILING_SWAP0_RST 0x0000000000000000u

/*! Field LEN0_F0 - len0_f0 */
#define MEMMAX_TILING_SWAP0_LEN0_F0_POS 0
/*! Field LEN0_F0 - len0_f0 */
#define MEMMAX_TILING_SWAP0_LEN0_F0_MASK 0x3Fu

/*! Field ILOC1_F0 - iloc1_f0 */
#define MEMMAX_TILING_SWAP0_ILOC1_F0_POS 6
/*! Field ILOC1_F0 - iloc1_f0 */
#define MEMMAX_TILING_SWAP0_ILOC1_F0_MASK 0xFC0u

/*! Field LEN1_F0 - len1_f0 */
#define MEMMAX_TILING_SWAP0_LEN1_F0_POS 12
/*! Field LEN1_F0 - len1_f0 */
#define MEMMAX_TILING_SWAP0_LEN1_F0_MASK 0x3F000u

/*! Field ILOC2_F0 - iloc2_f0 */
#define MEMMAX_TILING_SWAP0_ILOC2_F0_POS 18
/*! Field ILOC2_F0 - iloc2_f0 */
#define MEMMAX_TILING_SWAP0_ILOC2_F0_MASK 0xFC0000u

/*! Field LEN2_F0 - len2_f0 */
#define MEMMAX_TILING_SWAP0_LEN2_F0_POS 24
/*! Field LEN2_F0 - len2_f0 */
#define MEMMAX_TILING_SWAP0_LEN2_F0_MASK 0x3F000000u

/*! Field ILOC3_F0 - iloc3_f0 */
#define MEMMAX_TILING_SWAP0_ILOC3_F0_POS 32
/*! Field ILOC3_F0 - iloc3_f0 */
#define MEMMAX_TILING_SWAP0_ILOC3_F0_MASK 0x3F00000000u

/*! Field LEN3_F0 - len3_f0 */
#define MEMMAX_TILING_SWAP0_LEN3_F0_POS 38
/*! Field LEN3_F0 - len3_f0 */
#define MEMMAX_TILING_SWAP0_LEN3_F0_MASK 0xFC000000000u

/*! Field ILOC4_F0 - iloc4_f0 */
#define MEMMAX_TILING_SWAP0_ILOC4_F0_POS 44
/*! Field ILOC4_F0 - iloc4_f0 */
#define MEMMAX_TILING_SWAP0_ILOC4_F0_MASK 0x3F00000000000u

/*! Field LEN4_F0 - len4_f0 */
#define MEMMAX_TILING_SWAP0_LEN4_F0_POS 50
/*! Field LEN4_F0 - len4_f0 */
#define MEMMAX_TILING_SWAP0_LEN4_F0_MASK 0xFC000000000000u

/*! Field ILOC5_F0 - iloc5_f0 */
#define MEMMAX_TILING_SWAP0_ILOC5_F0_POS 56
/*! Field ILOC5_F0 - iloc5_f0 */
#define MEMMAX_TILING_SWAP0_ILOC5_F0_MASK 0x3F00000000000000u

/*! @} */

/*! \defgroup MEMMAX_TILING_BAOP0 Register MEMMAX_TILING_BAOP0 - TILING_BAOP0 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_BAOP0 0x130
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_BAOP0 0x12200130u

/*! Register Reset Value */
#define MEMMAX_TILING_BAOP0_RST 0x0000000000000000u

/*! Field WIDTH_F0 - width_f0 */
#define MEMMAX_TILING_BAOP0_WIDTH_F0_POS 0
/*! Field WIDTH_F0 - width_f0 */
#define MEMMAX_TILING_BAOP0_WIDTH_F0_MASK 0x3u

/*! Field LOW_LOC_F0 - low_loc_f0 */
#define MEMMAX_TILING_BAOP0_LOW_LOC_F0_POS 2
/*! Field LOW_LOC_F0 - low_loc_f0 */
#define MEMMAX_TILING_BAOP0_LOW_LOC_F0_MASK 0xFCu

/*! Field HIGH_LOC_F0 - high_loc_f0 */
#define MEMMAX_TILING_BAOP0_HIGH_LOC_F0_POS 8
/*! Field HIGH_LOC_F0 - high_loc_f0 */
#define MEMMAX_TILING_BAOP0_HIGH_LOC_F0_MASK 0x3F00u

/*! Field LOW_EN_F0 - low_en_f0 */
#define MEMMAX_TILING_BAOP0_LOW_EN_F0_POS 15
/*! Field LOW_EN_F0 - low_en_f0 */
#define MEMMAX_TILING_BAOP0_LOW_EN_F0_MASK 0x38000u

/*! Field HIGH_EN_F0 - high_en_f0 */
#define MEMMAX_TILING_BAOP0_HIGH_EN_F0_POS 19
/*! Field HIGH_EN_F0 - high_en_f0 */
#define MEMMAX_TILING_BAOP0_HIGH_EN_F0_MASK 0x380000u

/*! Field DISABLE_BIT_MOVE_F0 - disable_bit_move_f0 */
#define MEMMAX_TILING_BAOP0_DISABLE_BIT_MOVE_F0_POS 22
/*! Field DISABLE_BIT_MOVE_F0 - disable_bit_move_f0 */
#define MEMMAX_TILING_BAOP0_DISABLE_BIT_MOVE_F0_MASK 0x400000u

/*! @} */

/*! \defgroup MEMMAX_TILING_SWAP1 Register MEMMAX_TILING_SWAP1 - TILING_SWAP1 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_SWAP1 0x140
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_SWAP1 0x12200140u

/*! Register Reset Value */
#define MEMMAX_TILING_SWAP1_RST 0x0000000000000000u

/*! Field LEN0_F1 - len0_f1 */
#define MEMMAX_TILING_SWAP1_LEN0_F1_POS 0
/*! Field LEN0_F1 - len0_f1 */
#define MEMMAX_TILING_SWAP1_LEN0_F1_MASK 0x3Fu

/*! Field ILOC1_F1 - iloc1_f1 */
#define MEMMAX_TILING_SWAP1_ILOC1_F1_POS 6
/*! Field ILOC1_F1 - iloc1_f1 */
#define MEMMAX_TILING_SWAP1_ILOC1_F1_MASK 0xFC0u

/*! Field LEN1_F1 - len1_f1 */
#define MEMMAX_TILING_SWAP1_LEN1_F1_POS 12
/*! Field LEN1_F1 - len1_f1 */
#define MEMMAX_TILING_SWAP1_LEN1_F1_MASK 0x3F000u

/*! Field ILOC2_F1 - iloc2_f1 */
#define MEMMAX_TILING_SWAP1_ILOC2_F1_POS 18
/*! Field ILOC2_F1 - iloc2_f1 */
#define MEMMAX_TILING_SWAP1_ILOC2_F1_MASK 0xFC0000u

/*! Field LEN2_F1 - len2_f1 */
#define MEMMAX_TILING_SWAP1_LEN2_F1_POS 24
/*! Field LEN2_F1 - len2_f1 */
#define MEMMAX_TILING_SWAP1_LEN2_F1_MASK 0x3F000000u

/*! Field ILOC3_F1 - iloc3_f1 */
#define MEMMAX_TILING_SWAP1_ILOC3_F1_POS 32
/*! Field ILOC3_F1 - iloc3_f1 */
#define MEMMAX_TILING_SWAP1_ILOC3_F1_MASK 0x3F00000000u

/*! Field LEN3_F1 - len3_f1 */
#define MEMMAX_TILING_SWAP1_LEN3_F1_POS 38
/*! Field LEN3_F1 - len3_f1 */
#define MEMMAX_TILING_SWAP1_LEN3_F1_MASK 0xFC000000000u

/*! Field ILOC4_F1 - iloc4_f1 */
#define MEMMAX_TILING_SWAP1_ILOC4_F1_POS 44
/*! Field ILOC4_F1 - iloc4_f1 */
#define MEMMAX_TILING_SWAP1_ILOC4_F1_MASK 0x3F00000000000u

/*! Field LEN4_F1 - len4_f1 */
#define MEMMAX_TILING_SWAP1_LEN4_F1_POS 50
/*! Field LEN4_F1 - len4_f1 */
#define MEMMAX_TILING_SWAP1_LEN4_F1_MASK 0xFC000000000000u

/*! Field ILOC5_F1 - iloc5_f1 */
#define MEMMAX_TILING_SWAP1_ILOC5_F1_POS 56
/*! Field ILOC5_F1 - iloc5_f1 */
#define MEMMAX_TILING_SWAP1_ILOC5_F1_MASK 0x3F00000000000000u

/*! @} */

/*! \defgroup MEMMAX_TILING_BAOP1 Register MEMMAX_TILING_BAOP1 - TILING_BAOP1 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_BAOP1 0x150
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_BAOP1 0x12200150u

/*! Register Reset Value */
#define MEMMAX_TILING_BAOP1_RST 0x0000000000000000u

/*! Field WIDTH_F1 - width_f1 */
#define MEMMAX_TILING_BAOP1_WIDTH_F1_POS 0
/*! Field WIDTH_F1 - width_f1 */
#define MEMMAX_TILING_BAOP1_WIDTH_F1_MASK 0x3u

/*! Field LOW_LOC_F1 - low_loc_f1 */
#define MEMMAX_TILING_BAOP1_LOW_LOC_F1_POS 2
/*! Field LOW_LOC_F1 - low_loc_f1 */
#define MEMMAX_TILING_BAOP1_LOW_LOC_F1_MASK 0xFCu

/*! Field HIGH_LOC_F1 - high_loc_f1 */
#define MEMMAX_TILING_BAOP1_HIGH_LOC_F1_POS 8
/*! Field HIGH_LOC_F1 - high_loc_f1 */
#define MEMMAX_TILING_BAOP1_HIGH_LOC_F1_MASK 0x3F00u

/*! Field LOW_EN_F1 - low_en_f1 */
#define MEMMAX_TILING_BAOP1_LOW_EN_F1_POS 15
/*! Field LOW_EN_F1 - low_en_f1 */
#define MEMMAX_TILING_BAOP1_LOW_EN_F1_MASK 0x38000u

/*! Field HIGH_EN_F1 - high_en_f1 */
#define MEMMAX_TILING_BAOP1_HIGH_EN_F1_POS 19
/*! Field HIGH_EN_F1 - high_en_f1 */
#define MEMMAX_TILING_BAOP1_HIGH_EN_F1_MASK 0x380000u

/*! Field DISABLE_BIT_MOVE_F1 - disable_bit_move_f1 */
#define MEMMAX_TILING_BAOP1_DISABLE_BIT_MOVE_F1_POS 22
/*! Field DISABLE_BIT_MOVE_F1 - disable_bit_move_f1 */
#define MEMMAX_TILING_BAOP1_DISABLE_BIT_MOVE_F1_MASK 0x400000u

/*! @} */

/*! \defgroup MEMMAX_TILING_SWAP2 Register MEMMAX_TILING_SWAP2 - TILING_SWAP2 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_SWAP2 0x160
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_SWAP2 0x12200160u

/*! Register Reset Value */
#define MEMMAX_TILING_SWAP2_RST 0x0000000000000000u

/*! Field LEN0_F2 - len0_f2 */
#define MEMMAX_TILING_SWAP2_LEN0_F2_POS 0
/*! Field LEN0_F2 - len0_f2 */
#define MEMMAX_TILING_SWAP2_LEN0_F2_MASK 0x3Fu

/*! Field ILOC1_F2 - iloc1_f2 */
#define MEMMAX_TILING_SWAP2_ILOC1_F2_POS 6
/*! Field ILOC1_F2 - iloc1_f2 */
#define MEMMAX_TILING_SWAP2_ILOC1_F2_MASK 0xFC0u

/*! Field LEN1_F2 - len1_f2 */
#define MEMMAX_TILING_SWAP2_LEN1_F2_POS 12
/*! Field LEN1_F2 - len1_f2 */
#define MEMMAX_TILING_SWAP2_LEN1_F2_MASK 0x3F000u

/*! Field ILOC2_F2 - iloc2_f2 */
#define MEMMAX_TILING_SWAP2_ILOC2_F2_POS 18
/*! Field ILOC2_F2 - iloc2_f2 */
#define MEMMAX_TILING_SWAP2_ILOC2_F2_MASK 0xFC0000u

/*! Field LEN2_F2 - len2_f2 */
#define MEMMAX_TILING_SWAP2_LEN2_F2_POS 24
/*! Field LEN2_F2 - len2_f2 */
#define MEMMAX_TILING_SWAP2_LEN2_F2_MASK 0x3F000000u

/*! Field ILOC3_F2 - iloc3_f2 */
#define MEMMAX_TILING_SWAP2_ILOC3_F2_POS 32
/*! Field ILOC3_F2 - iloc3_f2 */
#define MEMMAX_TILING_SWAP2_ILOC3_F2_MASK 0x3F00000000u

/*! Field LEN3_F2 - len3_f2 */
#define MEMMAX_TILING_SWAP2_LEN3_F2_POS 38
/*! Field LEN3_F2 - len3_f2 */
#define MEMMAX_TILING_SWAP2_LEN3_F2_MASK 0xFC000000000u

/*! Field ILOC4_F2 - iloc4_f2 */
#define MEMMAX_TILING_SWAP2_ILOC4_F2_POS 44
/*! Field ILOC4_F2 - iloc4_f2 */
#define MEMMAX_TILING_SWAP2_ILOC4_F2_MASK 0x3F00000000000u

/*! Field LEN4_F2 - len4_f2 */
#define MEMMAX_TILING_SWAP2_LEN4_F2_POS 50
/*! Field LEN4_F2 - len4_f2 */
#define MEMMAX_TILING_SWAP2_LEN4_F2_MASK 0xFC000000000000u

/*! Field ILOC5_F2 - iloc5_f2 */
#define MEMMAX_TILING_SWAP2_ILOC5_F2_POS 56
/*! Field ILOC5_F2 - iloc5_f2 */
#define MEMMAX_TILING_SWAP2_ILOC5_F2_MASK 0x3F00000000000000u

/*! @} */

/*! \defgroup MEMMAX_TILING_BAOP2 Register MEMMAX_TILING_BAOP2 - TILING_BAOP2 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_BAOP2 0x170
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_BAOP2 0x12200170u

/*! Register Reset Value */
#define MEMMAX_TILING_BAOP2_RST 0x0000000000000000u

/*! Field WIDTH_F2 - width_f2 */
#define MEMMAX_TILING_BAOP2_WIDTH_F2_POS 0
/*! Field WIDTH_F2 - width_f2 */
#define MEMMAX_TILING_BAOP2_WIDTH_F2_MASK 0x3u

/*! Field LOW_LOC_F2 - low_loc_f2 */
#define MEMMAX_TILING_BAOP2_LOW_LOC_F2_POS 2
/*! Field LOW_LOC_F2 - low_loc_f2 */
#define MEMMAX_TILING_BAOP2_LOW_LOC_F2_MASK 0xFCu

/*! Field HIGH_LOC_F2 - high_loc_f2 */
#define MEMMAX_TILING_BAOP2_HIGH_LOC_F2_POS 8
/*! Field HIGH_LOC_F2 - high_loc_f2 */
#define MEMMAX_TILING_BAOP2_HIGH_LOC_F2_MASK 0x3F00u

/*! Field LOW_EN_F2 - low_en_f2 */
#define MEMMAX_TILING_BAOP2_LOW_EN_F2_POS 15
/*! Field LOW_EN_F2 - low_en_f2 */
#define MEMMAX_TILING_BAOP2_LOW_EN_F2_MASK 0x38000u

/*! Field HIGH_EN_F2 - high_en_f2 */
#define MEMMAX_TILING_BAOP2_HIGH_EN_F2_POS 19
/*! Field HIGH_EN_F2 - high_en_f2 */
#define MEMMAX_TILING_BAOP2_HIGH_EN_F2_MASK 0x380000u

/*! Field DISABLE_BIT_MOVE_F2 - disable_bit_move_f2 */
#define MEMMAX_TILING_BAOP2_DISABLE_BIT_MOVE_F2_POS 22
/*! Field DISABLE_BIT_MOVE_F2 - disable_bit_move_f2 */
#define MEMMAX_TILING_BAOP2_DISABLE_BIT_MOVE_F2_MASK 0x400000u

/*! @} */

/*! \defgroup MEMMAX_TILING_SWAP3 Register MEMMAX_TILING_SWAP3 - TILING_SWAP3 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_SWAP3 0x180
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_SWAP3 0x12200180u

/*! Register Reset Value */
#define MEMMAX_TILING_SWAP3_RST 0x0000000000000000u

/*! Field LEN0_F3 - len0_f3 */
#define MEMMAX_TILING_SWAP3_LEN0_F3_POS 0
/*! Field LEN0_F3 - len0_f3 */
#define MEMMAX_TILING_SWAP3_LEN0_F3_MASK 0x3Fu

/*! Field ILOC1_F3 - iloc1_f3 */
#define MEMMAX_TILING_SWAP3_ILOC1_F3_POS 6
/*! Field ILOC1_F3 - iloc1_f3 */
#define MEMMAX_TILING_SWAP3_ILOC1_F3_MASK 0xFC0u

/*! Field LEN1_F3 - len1_f3 */
#define MEMMAX_TILING_SWAP3_LEN1_F3_POS 12
/*! Field LEN1_F3 - len1_f3 */
#define MEMMAX_TILING_SWAP3_LEN1_F3_MASK 0x3F000u

/*! Field ILOC2_F3 - iloc2_f3 */
#define MEMMAX_TILING_SWAP3_ILOC2_F3_POS 18
/*! Field ILOC2_F3 - iloc2_f3 */
#define MEMMAX_TILING_SWAP3_ILOC2_F3_MASK 0xFC0000u

/*! Field LEN2_F3 - len2_f3 */
#define MEMMAX_TILING_SWAP3_LEN2_F3_POS 24
/*! Field LEN2_F3 - len2_f3 */
#define MEMMAX_TILING_SWAP3_LEN2_F3_MASK 0x3F000000u

/*! Field ILOC3_F3 - iloc3_f3 */
#define MEMMAX_TILING_SWAP3_ILOC3_F3_POS 32
/*! Field ILOC3_F3 - iloc3_f3 */
#define MEMMAX_TILING_SWAP3_ILOC3_F3_MASK 0x3F00000000u

/*! Field LEN3_F3 - len3_f3 */
#define MEMMAX_TILING_SWAP3_LEN3_F3_POS 38
/*! Field LEN3_F3 - len3_f3 */
#define MEMMAX_TILING_SWAP3_LEN3_F3_MASK 0xFC000000000u

/*! Field ILOC4_F3 - iloc4_f3 */
#define MEMMAX_TILING_SWAP3_ILOC4_F3_POS 44
/*! Field ILOC4_F3 - iloc4_f3 */
#define MEMMAX_TILING_SWAP3_ILOC4_F3_MASK 0x3F00000000000u

/*! Field LEN4_F3 - len4_f3 */
#define MEMMAX_TILING_SWAP3_LEN4_F3_POS 50
/*! Field LEN4_F3 - len4_f3 */
#define MEMMAX_TILING_SWAP3_LEN4_F3_MASK 0xFC000000000000u

/*! Field ILOC5_F3 - iloc5_f3 */
#define MEMMAX_TILING_SWAP3_ILOC5_F3_POS 56
/*! Field ILOC5_F3 - iloc5_f3 */
#define MEMMAX_TILING_SWAP3_ILOC5_F3_MASK 0x3F00000000000000u

/*! @} */

/*! \defgroup MEMMAX_TILING_BAOP3 Register MEMMAX_TILING_BAOP3 - TILING_BAOP3 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_BAOP3 0x190
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_BAOP3 0x12200190u

/*! Register Reset Value */
#define MEMMAX_TILING_BAOP3_RST 0x0000000000000000u

/*! Field WIDTH_F3 - width_f3 */
#define MEMMAX_TILING_BAOP3_WIDTH_F3_POS 0
/*! Field WIDTH_F3 - width_f3 */
#define MEMMAX_TILING_BAOP3_WIDTH_F3_MASK 0x3u

/*! Field LOW_LOC_F3 - low_loc_f3 */
#define MEMMAX_TILING_BAOP3_LOW_LOC_F3_POS 2
/*! Field LOW_LOC_F3 - low_loc_f3 */
#define MEMMAX_TILING_BAOP3_LOW_LOC_F3_MASK 0xFCu

/*! Field HIGH_LOC_F3 - high_loc_f3 */
#define MEMMAX_TILING_BAOP3_HIGH_LOC_F3_POS 8
/*! Field HIGH_LOC_F3 - high_loc_f3 */
#define MEMMAX_TILING_BAOP3_HIGH_LOC_F3_MASK 0x3F00u

/*! Field LOW_EN_F3 - low_en_f3 */
#define MEMMAX_TILING_BAOP3_LOW_EN_F3_POS 15
/*! Field LOW_EN_F3 - low_en_f3 */
#define MEMMAX_TILING_BAOP3_LOW_EN_F3_MASK 0x38000u

/*! Field HIGH_EN_F3 - high_en_f3 */
#define MEMMAX_TILING_BAOP3_HIGH_EN_F3_POS 19
/*! Field HIGH_EN_F3 - high_en_f3 */
#define MEMMAX_TILING_BAOP3_HIGH_EN_F3_MASK 0x380000u

/*! Field DISABLE_BIT_MOVE_F3 - disable_bit_move_f3 */
#define MEMMAX_TILING_BAOP3_DISABLE_BIT_MOVE_F3_POS 22
/*! Field DISABLE_BIT_MOVE_F3 - disable_bit_move_f3 */
#define MEMMAX_TILING_BAOP3_DISABLE_BIT_MOVE_F3_MASK 0x400000u

/*! @} */

/*! \defgroup MEMMAX_TILING_SWAP4 Register MEMMAX_TILING_SWAP4 - TILING_SWAP4 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_SWAP4 0x1A0
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_SWAP4 0x122001A0u

/*! Register Reset Value */
#define MEMMAX_TILING_SWAP4_RST 0x0000000000000000u

/*! Field LEN0_F4 - len0_f4 */
#define MEMMAX_TILING_SWAP4_LEN0_F4_POS 0
/*! Field LEN0_F4 - len0_f4 */
#define MEMMAX_TILING_SWAP4_LEN0_F4_MASK 0x3Fu

/*! Field ILOC1_F4 - iloc1_f4 */
#define MEMMAX_TILING_SWAP4_ILOC1_F4_POS 6
/*! Field ILOC1_F4 - iloc1_f4 */
#define MEMMAX_TILING_SWAP4_ILOC1_F4_MASK 0xFC0u

/*! Field LEN1_F4 - len1_f4 */
#define MEMMAX_TILING_SWAP4_LEN1_F4_POS 12
/*! Field LEN1_F4 - len1_f4 */
#define MEMMAX_TILING_SWAP4_LEN1_F4_MASK 0x3F000u

/*! Field ILOC2_F4 - iloc2_f4 */
#define MEMMAX_TILING_SWAP4_ILOC2_F4_POS 18
/*! Field ILOC2_F4 - iloc2_f4 */
#define MEMMAX_TILING_SWAP4_ILOC2_F4_MASK 0xFC0000u

/*! Field LEN2_F4 - len2_f4 */
#define MEMMAX_TILING_SWAP4_LEN2_F4_POS 24
/*! Field LEN2_F4 - len2_f4 */
#define MEMMAX_TILING_SWAP4_LEN2_F4_MASK 0x3F000000u

/*! Field ILOC3_F4 - iloc3_f4 */
#define MEMMAX_TILING_SWAP4_ILOC3_F4_POS 32
/*! Field ILOC3_F4 - iloc3_f4 */
#define MEMMAX_TILING_SWAP4_ILOC3_F4_MASK 0x3F00000000u

/*! Field LEN3_F4 - len3_f4 */
#define MEMMAX_TILING_SWAP4_LEN3_F4_POS 38
/*! Field LEN3_F4 - len3_f4 */
#define MEMMAX_TILING_SWAP4_LEN3_F4_MASK 0xFC000000000u

/*! Field ILOC4_F4 - iloc4_f4 */
#define MEMMAX_TILING_SWAP4_ILOC4_F4_POS 44
/*! Field ILOC4_F4 - iloc4_f4 */
#define MEMMAX_TILING_SWAP4_ILOC4_F4_MASK 0x3F00000000000u

/*! Field LEN4_F4 - len4_f4 */
#define MEMMAX_TILING_SWAP4_LEN4_F4_POS 50
/*! Field LEN4_F4 - len4_f4 */
#define MEMMAX_TILING_SWAP4_LEN4_F4_MASK 0xFC000000000000u

/*! Field ILOC5_F4 - iloc5_f4 */
#define MEMMAX_TILING_SWAP4_ILOC5_F4_POS 56
/*! Field ILOC5_F4 - iloc5_f4 */
#define MEMMAX_TILING_SWAP4_ILOC5_F4_MASK 0x3F00000000000000u

/*! @} */

/*! \defgroup MEMMAX_TILING_BAOP4 Register MEMMAX_TILING_BAOP4 - TILING_BAOP4 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_BAOP4 0x1B0
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_BAOP4 0x122001B0u

/*! Register Reset Value */
#define MEMMAX_TILING_BAOP4_RST 0x0000000000000000u

/*! Field WIDTH_F4 - width_f4 */
#define MEMMAX_TILING_BAOP4_WIDTH_F4_POS 0
/*! Field WIDTH_F4 - width_f4 */
#define MEMMAX_TILING_BAOP4_WIDTH_F4_MASK 0x3u

/*! Field LOW_LOC_F4 - low_loc_f4 */
#define MEMMAX_TILING_BAOP4_LOW_LOC_F4_POS 2
/*! Field LOW_LOC_F4 - low_loc_f4 */
#define MEMMAX_TILING_BAOP4_LOW_LOC_F4_MASK 0xFCu

/*! Field HIGH_LOC_F4 - high_loc_f4 */
#define MEMMAX_TILING_BAOP4_HIGH_LOC_F4_POS 8
/*! Field HIGH_LOC_F4 - high_loc_f4 */
#define MEMMAX_TILING_BAOP4_HIGH_LOC_F4_MASK 0x3F00u

/*! Field LOW_EN_F4 - low_en_f4 */
#define MEMMAX_TILING_BAOP4_LOW_EN_F4_POS 15
/*! Field LOW_EN_F4 - low_en_f4 */
#define MEMMAX_TILING_BAOP4_LOW_EN_F4_MASK 0x38000u

/*! Field HIGH_EN_F4 - high_en_f4 */
#define MEMMAX_TILING_BAOP4_HIGH_EN_F4_POS 19
/*! Field HIGH_EN_F4 - high_en_f4 */
#define MEMMAX_TILING_BAOP4_HIGH_EN_F4_MASK 0x380000u

/*! Field DISABLE_BIT_MOVE_F4 - disable_bit_move_f4 */
#define MEMMAX_TILING_BAOP4_DISABLE_BIT_MOVE_F4_POS 22
/*! Field DISABLE_BIT_MOVE_F4 - disable_bit_move_f4 */
#define MEMMAX_TILING_BAOP4_DISABLE_BIT_MOVE_F4_MASK 0x400000u

/*! @} */

/*! \defgroup MEMMAX_TILING_SWAP5 Register MEMMAX_TILING_SWAP5 - TILING_SWAP5 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_SWAP5 0x1C0
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_SWAP5 0x122001C0u

/*! Register Reset Value */
#define MEMMAX_TILING_SWAP5_RST 0x0000000000000000u

/*! Field LEN0_F5 - len0_f5 */
#define MEMMAX_TILING_SWAP5_LEN0_F5_POS 0
/*! Field LEN0_F5 - len0_f5 */
#define MEMMAX_TILING_SWAP5_LEN0_F5_MASK 0x3Fu

/*! Field ILOC1_F5 - iloc1_f5 */
#define MEMMAX_TILING_SWAP5_ILOC1_F5_POS 6
/*! Field ILOC1_F5 - iloc1_f5 */
#define MEMMAX_TILING_SWAP5_ILOC1_F5_MASK 0xFC0u

/*! Field LEN1_F5 - len1_f5 */
#define MEMMAX_TILING_SWAP5_LEN1_F5_POS 12
/*! Field LEN1_F5 - len1_f5 */
#define MEMMAX_TILING_SWAP5_LEN1_F5_MASK 0x3F000u

/*! Field ILOC2_F5 - iloc2_f5 */
#define MEMMAX_TILING_SWAP5_ILOC2_F5_POS 18
/*! Field ILOC2_F5 - iloc2_f5 */
#define MEMMAX_TILING_SWAP5_ILOC2_F5_MASK 0xFC0000u

/*! Field LEN2_F5 - len2_f5 */
#define MEMMAX_TILING_SWAP5_LEN2_F5_POS 24
/*! Field LEN2_F5 - len2_f5 */
#define MEMMAX_TILING_SWAP5_LEN2_F5_MASK 0x3F000000u

/*! Field ILOC3_F5 - iloc3_f5 */
#define MEMMAX_TILING_SWAP5_ILOC3_F5_POS 32
/*! Field ILOC3_F5 - iloc3_f5 */
#define MEMMAX_TILING_SWAP5_ILOC3_F5_MASK 0x3F00000000u

/*! Field LEN3_F5 - len3_f5 */
#define MEMMAX_TILING_SWAP5_LEN3_F5_POS 38
/*! Field LEN3_F5 - len3_f5 */
#define MEMMAX_TILING_SWAP5_LEN3_F5_MASK 0xFC000000000u

/*! Field ILOC4_F5 - iloc4_f5 */
#define MEMMAX_TILING_SWAP5_ILOC4_F5_POS 44
/*! Field ILOC4_F5 - iloc4_f5 */
#define MEMMAX_TILING_SWAP5_ILOC4_F5_MASK 0x3F00000000000u

/*! Field LEN4_F5 - len4_f5 */
#define MEMMAX_TILING_SWAP5_LEN4_F5_POS 50
/*! Field LEN4_F5 - len4_f5 */
#define MEMMAX_TILING_SWAP5_LEN4_F5_MASK 0xFC000000000000u

/*! Field ILOC5_F5 - iloc5_f5 */
#define MEMMAX_TILING_SWAP5_ILOC5_F5_POS 56
/*! Field ILOC5_F5 - iloc5_f5 */
#define MEMMAX_TILING_SWAP5_ILOC5_F5_MASK 0x3F00000000000000u

/*! @} */

/*! \defgroup MEMMAX_TILING_BAOP5 Register MEMMAX_TILING_BAOP5 - TILING_BAOP5 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_BAOP5 0x1D0
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_BAOP5 0x122001D0u

/*! Register Reset Value */
#define MEMMAX_TILING_BAOP5_RST 0x0000000000000000u

/*! Field WIDTH_F5 - width_f5 */
#define MEMMAX_TILING_BAOP5_WIDTH_F5_POS 0
/*! Field WIDTH_F5 - width_f5 */
#define MEMMAX_TILING_BAOP5_WIDTH_F5_MASK 0x3u

/*! Field LOW_LOC_F5 - low_loc_f5 */
#define MEMMAX_TILING_BAOP5_LOW_LOC_F5_POS 2
/*! Field LOW_LOC_F5 - low_loc_f5 */
#define MEMMAX_TILING_BAOP5_LOW_LOC_F5_MASK 0xFCu

/*! Field HIGH_LOC_F5 - high_loc_f5 */
#define MEMMAX_TILING_BAOP5_HIGH_LOC_F5_POS 8
/*! Field HIGH_LOC_F5 - high_loc_f5 */
#define MEMMAX_TILING_BAOP5_HIGH_LOC_F5_MASK 0x3F00u

/*! Field LOW_EN_F5 - low_en_f5 */
#define MEMMAX_TILING_BAOP5_LOW_EN_F5_POS 15
/*! Field LOW_EN_F5 - low_en_f5 */
#define MEMMAX_TILING_BAOP5_LOW_EN_F5_MASK 0x38000u

/*! Field HIGH_EN_F5 - high_en_f5 */
#define MEMMAX_TILING_BAOP5_HIGH_EN_F5_POS 19
/*! Field HIGH_EN_F5 - high_en_f5 */
#define MEMMAX_TILING_BAOP5_HIGH_EN_F5_MASK 0x380000u

/*! Field DISABLE_BIT_MOVE_F5 - disable_bit_move_f5 */
#define MEMMAX_TILING_BAOP5_DISABLE_BIT_MOVE_F5_POS 22
/*! Field DISABLE_BIT_MOVE_F5 - disable_bit_move_f5 */
#define MEMMAX_TILING_BAOP5_DISABLE_BIT_MOVE_F5_MASK 0x400000u

/*! @} */

/*! \defgroup MEMMAX_TILING_SWAP6 Register MEMMAX_TILING_SWAP6 - TILING_SWAP6 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_SWAP6 0x1E0
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_SWAP6 0x122001E0u

/*! Register Reset Value */
#define MEMMAX_TILING_SWAP6_RST 0x0000000000000000u

/*! Field LEN0_F6 - len0_f6 */
#define MEMMAX_TILING_SWAP6_LEN0_F6_POS 0
/*! Field LEN0_F6 - len0_f6 */
#define MEMMAX_TILING_SWAP6_LEN0_F6_MASK 0x3Fu

/*! Field ILOC1_F6 - iloc1_f6 */
#define MEMMAX_TILING_SWAP6_ILOC1_F6_POS 6
/*! Field ILOC1_F6 - iloc1_f6 */
#define MEMMAX_TILING_SWAP6_ILOC1_F6_MASK 0xFC0u

/*! Field LEN1_F6 - len1_f6 */
#define MEMMAX_TILING_SWAP6_LEN1_F6_POS 12
/*! Field LEN1_F6 - len1_f6 */
#define MEMMAX_TILING_SWAP6_LEN1_F6_MASK 0x3F000u

/*! Field ILOC2_F6 - iloc2_f6 */
#define MEMMAX_TILING_SWAP6_ILOC2_F6_POS 18
/*! Field ILOC2_F6 - iloc2_f6 */
#define MEMMAX_TILING_SWAP6_ILOC2_F6_MASK 0xFC0000u

/*! Field LEN2_F6 - len2_f6 */
#define MEMMAX_TILING_SWAP6_LEN2_F6_POS 24
/*! Field LEN2_F6 - len2_f6 */
#define MEMMAX_TILING_SWAP6_LEN2_F6_MASK 0x3F000000u

/*! Field ILOC3_F6 - iloc3_f6 */
#define MEMMAX_TILING_SWAP6_ILOC3_F6_POS 32
/*! Field ILOC3_F6 - iloc3_f6 */
#define MEMMAX_TILING_SWAP6_ILOC3_F6_MASK 0x3F00000000u

/*! Field LEN3_F6 - len3_f6 */
#define MEMMAX_TILING_SWAP6_LEN3_F6_POS 38
/*! Field LEN3_F6 - len3_f6 */
#define MEMMAX_TILING_SWAP6_LEN3_F6_MASK 0xFC000000000u

/*! Field ILOC4_F6 - iloc4_f6 */
#define MEMMAX_TILING_SWAP6_ILOC4_F6_POS 44
/*! Field ILOC4_F6 - iloc4_f6 */
#define MEMMAX_TILING_SWAP6_ILOC4_F6_MASK 0x3F00000000000u

/*! Field LEN4_F6 - len4_f6 */
#define MEMMAX_TILING_SWAP6_LEN4_F6_POS 50
/*! Field LEN4_F6 - len4_f6 */
#define MEMMAX_TILING_SWAP6_LEN4_F6_MASK 0xFC000000000000u

/*! Field ILOC5_F6 - iloc5_f6 */
#define MEMMAX_TILING_SWAP6_ILOC5_F6_POS 56
/*! Field ILOC5_F6 - iloc5_f6 */
#define MEMMAX_TILING_SWAP6_ILOC5_F6_MASK 0x3F00000000000000u

/*! @} */

/*! \defgroup MEMMAX_TILING_BAOP6 Register MEMMAX_TILING_BAOP6 - TILING_BAOP6 */
/*! @{ */

/*! Register Offset (relative) */
#define MEMMAX_TILING_BAOP6 0x1F0
/*! Register Offset (absolute) for 1st Instance DDR_MEMORY_SCHEDULER */
#define DDR_MEMORY_SCHEDULER_MEMMAX_TILING_BAOP6 0x122001F0u

/*! Register Reset Value */
#define MEMMAX_TILING_BAOP6_RST 0x0000000000000000u

/*! Field WIDTH_F6 - width_f6 */
#define MEMMAX_TILING_BAOP6_WIDTH_F6_POS 0
/*! Field WIDTH_F6 - width_f6 */
#define MEMMAX_TILING_BAOP6_WIDTH_F6_MASK 0x3u

/*! Field LOW_LOC_F6 - low_loc_f6 */
#define MEMMAX_TILING_BAOP6_LOW_LOC_F6_POS 2
/*! Field LOW_LOC_F6 - low_loc_f6 */
#define MEMMAX_TILING_BAOP6_LOW_LOC_F6_MASK 0xFCu

/*! Field HIGH_LOC_F6 - high_loc_f6 */
#define MEMMAX_TILING_BAOP6_HIGH_LOC_F6_POS 8
/*! Field HIGH_LOC_F6 - high_loc_f6 */
#define MEMMAX_TILING_BAOP6_HIGH_LOC_F6_MASK 0x3F00u

/*! Field LOW_EN_F6 - low_en_f6 */
#define MEMMAX_TILING_BAOP6_LOW_EN_F6_POS 15
/*! Field LOW_EN_F6 - low_en_f6 */
#define MEMMAX_TILING_BAOP6_LOW_EN_F6_MASK 0x38000u

/*! Field HIGH_EN_F6 - high_en_f6 */
#define MEMMAX_TILING_BAOP6_HIGH_EN_F6_POS 19
/*! Field HIGH_EN_F6 - high_en_f6 */
#define MEMMAX_TILING_BAOP6_HIGH_EN_F6_MASK 0x380000u

/*! Field DISABLE_BIT_MOVE_F6 - disable_bit_move_f6 */
#define MEMMAX_TILING_BAOP6_DISABLE_BIT_MOVE_F6_POS 22
/*! Field DISABLE_BIT_MOVE_F6 - disable_bit_move_f6 */
#define MEMMAX_TILING_BAOP6_DISABLE_BIT_MOVE_F6_MASK 0x400000u

/*! @} */

/*! @} */

#endif
