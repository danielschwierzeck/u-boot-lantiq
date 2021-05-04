/*----------------------------------------------------------------------------- */
/* LSD Generator */
/*----------------------------------------------------------------------------- */
/* Perl Package        : LSD::generator::targetC (v1.1) */
/* LSD Source          : C:/Users/huchunfe/Perforce/huchunfe_huchunfe-MOBL1_dev.FalcONT/ipg_lsd/lsd_sys/source/xml/reg_files/gphy_cdb_pdi_def.xml */
/* Register File Name  : GPHY_CDB_PDI */
/* Register File Title : Control/Status registers of GPHY CDB */
/* Register Width      : 32 */
/* Note                : Doxygen compliant comments */
/*----------------------------------------------------------------------------- */

#ifndef _GPHY_CDB_PDI_H
#define _GPHY_CDB_PDI_H

/*! \defgroup GPHY_CDB_PDI Register File GPHY_CDB_PDI - Control/Status registers of GPHY CDB */
/*! @{ */

/*! Base Address of GPHY_CDB_PDI */
#define GPHY_CDB_PDI_MODULE_BASE 0x16210100u

/*! \defgroup GPHY_CDB_PDI_PLL_CFG0 Register GPHY_CDB_PDI_PLL_CFG0 - Configuration Register 0 of CDB PLL */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY_CDB_PDI_PLL_CFG0 0x0
/*! Register Offset (absolute) for 1st Instance GPHY_CDB_PDI */
#define GPHY_CDB_PDI_GPHY_CDB_PDI_PLL_CFG0 0x16210100u

/*! Register Reset Value */
#define GPHY_CDB_PDI_PLL_CFG0_RST 0x00000821u

/*! Field PLL_RSTN - Reserved */
#define GPHY_CDB_PDI_PLL_CFG0_PLL_RSTN_POS 0
/*! Field PLL_RSTN - Reserved */
#define GPHY_CDB_PDI_PLL_CFG0_PLL_RSTN_MASK 0x1u

/*! Field PLL_LCK - Locked indication of PLL */
#define GPHY_CDB_PDI_PLL_CFG0_PLL_LCK_POS 1
/*! Field PLL_LCK - Locked indication of PLL */
#define GPHY_CDB_PDI_PLL_CFG0_PLL_LCK_MASK 0x2u
/*! Constant FREE - Free Running */
#define CONST_GPHY_CDB_PDI_PLL_CFG0_PLL_LCK_FREE 0x0
/*! Constant LOCK - ROPLL is locked */
#define CONST_GPHY_CDB_PDI_PLL_CFG0_PLL_LCK_LOCK 0x1

/*! Field PLL_FBDIV - VCO Feedback Clock Divisor 11:0 */
#define GPHY_CDB_PDI_PLL_CFG0_PLL_FBDIV_POS 4
/*! Field PLL_FBDIV - VCO Feedback Clock Divisor 11:0 */
#define GPHY_CDB_PDI_PLL_CFG0_PLL_FBDIV_MASK 0xFFF0u

/*! @} */

/*! \defgroup GPHY_CDB_PDI_PLL_CFG1 Register GPHY_CDB_PDI_PLL_CFG1 - Configuration Register 1 of CDB PLL */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY_CDB_PDI_PLL_CFG1 0x4
/*! Register Offset (absolute) for 1st Instance GPHY_CDB_PDI */
#define GPHY_CDB_PDI_GPHY_CDB_PDI_PLL_CFG1 0x16210104u

/*! Register Reset Value */
#define GPHY_CDB_PDI_PLL_CFG1_RST 0x00000000u

/*! Field PLL_FRAC - Fractional K factor, bits 23:8 */
#define GPHY_CDB_PDI_PLL_CFG1_PLL_FRAC_POS 0
/*! Field PLL_FRAC - Fractional K factor, bits 23:8 */
#define GPHY_CDB_PDI_PLL_CFG1_PLL_FRAC_MASK 0xFFFFu

/*! @} */

/*! \defgroup GPHY_CDB_PDI_PLL_CFG2 Register GPHY_CDB_PDI_PLL_CFG2 - Configuration Register 2 of CDB PLL */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY_CDB_PDI_PLL_CFG2 0x8
/*! Register Offset (absolute) for 1st Instance GPHY_CDB_PDI */
#define GPHY_CDB_PDI_GPHY_CDB_PDI_PLL_CFG2 0x16210108u

/*! Register Reset Value */
#define GPHY_CDB_PDI_PLL_CFG2_RST 0x00000100u

/*! Field PLL_FRAC - Fractional K factor, bits 7:0 */
#define GPHY_CDB_PDI_PLL_CFG2_PLL_FRAC_POS 0
/*! Field PLL_FRAC - Fractional K factor, bits 7:0 */
#define GPHY_CDB_PDI_PLL_CFG2_PLL_FRAC_MASK 0xFFu

/*! Field PLL_REFDIV - Input Reference Clock Frequency Divisor 6:0 */
#define GPHY_CDB_PDI_PLL_CFG2_PLL_REFDIV_POS 8
/*! Field PLL_REFDIV - Input Reference Clock Frequency Divisor 6:0 */
#define GPHY_CDB_PDI_PLL_CFG2_PLL_REFDIV_MASK 0x3F00u

/*! @} */

/*! \defgroup GPHY_CDB_PDI_PLL_MISC Register GPHY_CDB_PDI_PLL_MISC - Miscellaneous control register of ROPLL */
/*! @{ */

/*! Register Offset (relative) */
#define GPHY_CDB_PDI_PLL_MISC 0xC
/*! Register Offset (absolute) for 1st Instance GPHY_CDB_PDI */
#define GPHY_CDB_PDI_GPHY_CDB_PDI_PLL_MISC 0x1621010Cu

/*! Register Reset Value */
#define GPHY_CDB_PDI_PLL_MISC_RST 0x00000000u

/*! Field FORCE - Force Latching Of Shadow Registers */
#define GPHY_CDB_PDI_PLL_MISC_FORCE_POS 13
/*! Field FORCE - Force Latching Of Shadow Registers */
#define GPHY_CDB_PDI_PLL_MISC_FORCE_MASK 0x2000u

/*! Field UNLCK - Sticky bit for unlock status */
#define GPHY_CDB_PDI_PLL_MISC_UNLCK_POS 14
/*! Field UNLCK - Sticky bit for unlock status */
#define GPHY_CDB_PDI_PLL_MISC_UNLCK_MASK 0x4000u

/*! @} */

/*! @} */

#endif
