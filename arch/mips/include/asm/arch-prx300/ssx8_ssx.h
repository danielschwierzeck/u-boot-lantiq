/* Copyright (c) 2017, Intel Corporation.
 * 
 * SSX8 XBAR header file
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/

#ifndef _SSX8_SSX_H
#define _SSX8_SSX_H

/*! \defgroup SSX8_SSX Register File SSX8_SSX - SSX8_ssx */
/*! @{ */

/*! Base Address of SSX8_SSX */
#define SSX8_SSX_MODULE_BASE 0xA0000000u

/*! \defgroup TREG8_RT_COMPONENT Register TREG8_RT_COMPONENT - component */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_RT_COMPONENT 0x0
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_RT_COMPONENT 0xA0000000u

/*! Register Reset Value */
#define TREG8_RT_COMPONENT_RST 0x0000000062003532u

/*! Field REV - rev */
#define TREG8_RT_COMPONENT_REV_POS 0
/*! Field REV - rev */
#define TREG8_RT_COMPONENT_REV_MASK 0xFFFFu

/*! Field CODE - code */
#define TREG8_RT_COMPONENT_CODE_POS 16
/*! Field CODE - code */
#define TREG8_RT_COMPONENT_CODE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup TREG8_RT_NETWORK Register TREG8_RT_NETWORK - network */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_RT_NETWORK 0x10
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_RT_NETWORK 0xA0000010u

/*! Register Reset Value */
#define TREG8_RT_NETWORK_RST 0x0000000000000000u

/*! Field REV - rev */
#define TREG8_RT_NETWORK_REV_POS 32
/*! Field REV - rev */
#define TREG8_RT_NETWORK_REV_MASK 0xFFFF00000000u

/*! Field ID - id */
#define TREG8_RT_NETWORK_ID_POS 48
/*! Field ID - id */
#define TREG8_RT_NETWORK_ID_MASK 0xFFFF000000000000u

/*! @} */

/*! \defgroup TREG8_RT_INITID_READBACK Register TREG8_RT_INITID_READBACK - initid_readback */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_RT_INITID_READBACK 0x70
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_RT_INITID_READBACK 0xA0000070u

/*! Register Reset Value */
#define TREG8_RT_INITID_READBACK_RST 0x0000000000000000u

/*! Field INITID - initid */
#define TREG8_RT_INITID_READBACK_INITID_POS 0
/*! Field INITID - initid */
#define TREG8_RT_INITID_READBACK_INITID_MASK 0xFFu

/*! @} */

/*! \defgroup TREG8_RT_NETWORK_CONTROL Register TREG8_RT_NETWORK_CONTROL - network_control */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_RT_NETWORK_CONTROL 0x78
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_RT_NETWORK_CONTROL 0xA0000078u

/*! Register Reset Value */
#define TREG8_RT_NETWORK_CONTROL_RST 0x0000000000000000u

/*! Field TIMEOUT_BASE - timeout_base */
#define TREG8_RT_NETWORK_CONTROL_TIMEOUT_BASE_POS 8
/*! Field TIMEOUT_BASE - timeout_base */
#define TREG8_RT_NETWORK_CONTROL_TIMEOUT_BASE_MASK 0x700u

/*! Field CLOCK_GATE_DISABLE - clock_gate_disable */
#define TREG8_RT_NETWORK_CONTROL_CLOCK_GATE_DISABLE_POS 56
/*! Field CLOCK_GATE_DISABLE - clock_gate_disable */
#define TREG8_RT_NETWORK_CONTROL_CLOCK_GATE_DISABLE_MASK 0x100000000000000u

/*! @} */

/*! \defgroup TREG8_SI_CONTROL Register TREG8_SI_CONTROL - control */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_CONTROL 0x420
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_CONTROL 0xA0000420u

/*! Register Reset Value */
#define TREG8_SI_CONTROL_RST 0x0000000000000000u

/*! Field CLOCK_GATE_DISABLE - clock_gate_disable */
#define TREG8_SI_CONTROL_CLOCK_GATE_DISABLE_POS 56
/*! Field CLOCK_GATE_DISABLE - clock_gate_disable */
#define TREG8_SI_CONTROL_CLOCK_GATE_DISABLE_MASK 0x100000000000000u

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_0 Register TREG8_SI_FLAG_STATUS_0 - flag_status_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_0 0x510
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_0 0xA0000510u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_0_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_0_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_0_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_1 Register TREG8_SI_FLAG_STATUS_1 - flag_status_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_1 0x530
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_1 0xA0000530u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_1_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_1_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_1_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_2 Register TREG8_SI_FLAG_STATUS_2 - flag_status_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_2 0x550
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_2 0xA0000550u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_2_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_2_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_2_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_3 Register TREG8_SI_FLAG_STATUS_3 - flag_status_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_3 0x570
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_3 0xA0000570u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_3_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_3_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_3_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_4 Register TREG8_SI_FLAG_STATUS_4 - flag_status_4 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_4 0x590
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_4 0xA0000590u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_4_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_4_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_4_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_5 Register TREG8_SI_FLAG_STATUS_5 - flag_status_5 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_5 0x5B0
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_5 0xA00005B0u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_5_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_5_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_5_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_6 Register TREG8_SI_FLAG_STATUS_6 - flag_status_6 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_6 0x5D0
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_6 0xA00005D0u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_6_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_6_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_6_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TREG8_SI_FLAG_STATUS_7 Register TREG8_SI_FLAG_STATUS_7 - flag_status_7 */
/*! @{ */

/*! Register Offset (relative) */
#define TREG8_SI_FLAG_STATUS_7 0x5F0
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TREG8_SI_FLAG_STATUS_7 0xA00005F0u

/*! Register Reset Value */
#define TREG8_SI_FLAG_STATUS_7_RST 0x0000000000000000u

/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_7_STATUS_POS 0
/*! Field STATUS - status */
#define TREG8_SI_FLAG_STATUS_7_STATUS_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TMCPY_TA_COMPONENT Register TMCPY_TA_COMPONENT - component */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_COMPONENT 0x800
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_COMPONENT 0xA0000800u

/*! Register Reset Value */
#define TMCPY_TA_COMPONENT_RST 0x0000000060203532u

/*! Field REV - rev */
#define TMCPY_TA_COMPONENT_REV_POS 0
/*! Field REV - rev */
#define TMCPY_TA_COMPONENT_REV_MASK 0xFFFFu

/*! Field CODE - code */
#define TMCPY_TA_COMPONENT_CODE_POS 16
/*! Field CODE - code */
#define TMCPY_TA_COMPONENT_CODE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup TMCPY_TA_CORE Register TMCPY_TA_CORE - core */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_CORE 0x818
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_CORE 0xA0000818u

/*! Register Reset Value */
#define TMCPY_TA_CORE_RST 0x000088C309220001u

/*! Field REV_CODE - rev_code */
#define TMCPY_TA_CORE_REV_CODE_POS 0
/*! Field REV_CODE - rev_code */
#define TMCPY_TA_CORE_REV_CODE_MASK 0xFFFFu

/*! Field CORE_CODE - core_code */
#define TMCPY_TA_CORE_CORE_CODE_POS 16
/*! Field CORE_CODE - core_code */
#define TMCPY_TA_CORE_CORE_CODE_MASK 0xFFFF0000u

/*! Field VENDOR_CODE - vendor_code */
#define TMCPY_TA_CORE_VENDOR_CODE_POS 32
/*! Field VENDOR_CODE - vendor_code */
#define TMCPY_TA_CORE_VENDOR_CODE_MASK 0xFFFF00000000u

/*! @} */

/*! \defgroup TMCPY_TA_AGENT_CONTROL Register TMCPY_TA_AGENT_CONTROL - agent_control */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_AGENT_CONTROL 0x820
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_AGENT_CONTROL 0xA0000820u

/*! Register Reset Value */
#define TMCPY_TA_AGENT_CONTROL_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TMCPY_TA_AGENT_CONTROL_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TMCPY_TA_AGENT_CONTROL_CORE_RESET_MASK 0x1u

/*! Field REJECT - reject */
#define TMCPY_TA_AGENT_CONTROL_REJECT_POS 4
/*! Field REJECT - reject */
#define TMCPY_TA_AGENT_CONTROL_REJECT_MASK 0x10u

/*! Field REQ_TIMEOUT - req_timeout */
#define TMCPY_TA_AGENT_CONTROL_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TMCPY_TA_AGENT_CONTROL_REQ_TIMEOUT_MASK 0x700u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMCPY_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_POS 16
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMCPY_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_MASK 0x70000u

/*! Field SERROR_REP - serror_rep */
#define TMCPY_TA_AGENT_CONTROL_SERROR_REP_POS 24
/*! Field SERROR_REP - serror_rep */
#define TMCPY_TA_AGENT_CONTROL_SERROR_REP_MASK 0x1000000u

/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TMCPY_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_POS 25
/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TMCPY_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_MASK 0x2000000u

/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TMCPY_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_POS 26
/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TMCPY_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_MASK 0x4000000u

/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TMCPY_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_POS 27
/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TMCPY_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_MASK 0x8000000u

/*! Field RFU0 - rfu0 */
#define TMCPY_TA_AGENT_CONTROL_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TMCPY_TA_AGENT_CONTROL_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TMCPY_TA_AGENT_CONTROL_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TMCPY_TA_AGENT_CONTROL_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TMCPY_TA_AGENT_CONTROL_RFU2_POS 30
/*! Field RFU2 - rfu2 */
#define TMCPY_TA_AGENT_CONTROL_RFU2_MASK 0x40000000u

/*! Field RFU3 - rfu3 */
#define TMCPY_TA_AGENT_CONTROL_RFU3_POS 31
/*! Field RFU3 - rfu3 */
#define TMCPY_TA_AGENT_CONTROL_RFU3_MASK 0x80000000u

/*! @} */

/*! \defgroup TMCPY_TA_AGENT_STATUS Register TMCPY_TA_AGENT_STATUS - agent_status */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_AGENT_STATUS 0x828
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_AGENT_STATUS 0xA0000828u

/*! Register Reset Value */
#define TMCPY_TA_AGENT_STATUS_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TMCPY_TA_AGENT_STATUS_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TMCPY_TA_AGENT_STATUS_CORE_RESET_MASK 0x1u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMCPY_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_POS 3
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMCPY_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_MASK 0x8u

/*! Field REQ_WAITING - req_waiting */
#define TMCPY_TA_AGENT_STATUS_REQ_WAITING_POS 4
/*! Field REQ_WAITING - req_waiting */
#define TMCPY_TA_AGENT_STATUS_REQ_WAITING_MASK 0x10u

/*! Field RESP_ACTIVE - resp_active */
#define TMCPY_TA_AGENT_STATUS_RESP_ACTIVE_POS 5
/*! Field RESP_ACTIVE - resp_active */
#define TMCPY_TA_AGENT_STATUS_RESP_ACTIVE_MASK 0x20u

/*! Field BURST - burst */
#define TMCPY_TA_AGENT_STATUS_BURST_POS 6
/*! Field BURST - burst */
#define TMCPY_TA_AGENT_STATUS_BURST_MASK 0x40u

/*! Field READEX - readex */
#define TMCPY_TA_AGENT_STATUS_READEX_POS 7
/*! Field READEX - readex */
#define TMCPY_TA_AGENT_STATUS_READEX_MASK 0x80u

/*! Field REQ_TIMEOUT - req_timeout */
#define TMCPY_TA_AGENT_STATUS_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TMCPY_TA_AGENT_STATUS_REQ_TIMEOUT_MASK 0x100u

/*! Field TIMEBASE - timebase */
#define TMCPY_TA_AGENT_STATUS_TIMEBASE_POS 12
/*! Field TIMEBASE - timebase */
#define TMCPY_TA_AGENT_STATUS_TIMEBASE_MASK 0xF000u

/*! Field BURST_CLOSE - burst_close */
#define TMCPY_TA_AGENT_STATUS_BURST_CLOSE_POS 16
/*! Field BURST_CLOSE - burst_close */
#define TMCPY_TA_AGENT_STATUS_BURST_CLOSE_MASK 0x10000u

/*! Field SERROR - serror */
#define TMCPY_TA_AGENT_STATUS_SERROR_POS 24
/*! Field SERROR - serror */
#define TMCPY_TA_AGENT_STATUS_SERROR_MASK 0x1000000u

/*! Field RFU0 - rfu0 */
#define TMCPY_TA_AGENT_STATUS_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TMCPY_TA_AGENT_STATUS_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TMCPY_TA_AGENT_STATUS_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TMCPY_TA_AGENT_STATUS_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TMCPY_TA_AGENT_STATUS_RFU2_POS 31
/*! Field RFU2 - rfu2 */
#define TMCPY_TA_AGENT_STATUS_RFU2_MASK 0x80000000u

/*! @} */

/*! \defgroup TMCPY_TA_ERROR_LOG Register TMCPY_TA_ERROR_LOG - error_log */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_ERROR_LOG 0x858
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_ERROR_LOG 0xA0000858u

/*! Register Reset Value */
#define TMCPY_TA_ERROR_LOG_RST 0x0000000000000000u

/*! Field CMD - cmd */
#define TMCPY_TA_ERROR_LOG_CMD_POS 0
/*! Field CMD - cmd */
#define TMCPY_TA_ERROR_LOG_CMD_MASK 0x7u

/*! Field INITID - initid */
#define TMCPY_TA_ERROR_LOG_INITID_POS 8
/*! Field INITID - initid */
#define TMCPY_TA_ERROR_LOG_INITID_MASK 0xFF00u

/*! Field CODE - code */
#define TMCPY_TA_ERROR_LOG_CODE_POS 24
/*! Field CODE - code */
#define TMCPY_TA_ERROR_LOG_CODE_MASK 0xF000000u

/*! Field MULTI - multi */
#define TMCPY_TA_ERROR_LOG_MULTI_POS 31
/*! Field MULTI - multi */
#define TMCPY_TA_ERROR_LOG_MULTI_MASK 0x80000000u

/*! Field REQ_INFO - req_info */
#define TMCPY_TA_ERROR_LOG_REQ_INFO_POS 32
/*! Field REQ_INFO - req_info */
#define TMCPY_TA_ERROR_LOG_REQ_INFO_MASK 0xFFFFFFFF00000000u

/*! @} */

/*! \defgroup TMCPY_TA_ERROR_LOG_ADDR Register TMCPY_TA_ERROR_LOG_ADDR - error_log_addr */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_ERROR_LOG_ADDR 0x860
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_ERROR_LOG_ADDR 0xA0000860u

/*! Register Reset Value */
#define TMCPY_TA_ERROR_LOG_ADDR_RST 0x0000000000000000u

/*! Field ADDR - addr */
#define TMCPY_TA_ERROR_LOG_ADDR_ADDR_POS 0
/*! Field ADDR - addr */
#define TMCPY_TA_ERROR_LOG_ADDR_ADDR_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TMCPY_TA_BANDWIDTH_0 Register TMCPY_TA_BANDWIDTH_0 - bandwidth_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_BANDWIDTH_0 0x900
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_BANDWIDTH_0 0xA0000900u

/*! Register Reset Value */
#define TMCPY_TA_BANDWIDTH_0_RST 0x0000000000000000u

/*! Field FRACTION_0 - fraction_0 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_0_POS 8
/*! Field FRACTION_0 - fraction_0 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_0_MASK 0xFF00u

/*! Field FRACTION_1 - fraction_1 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_1_POS 24
/*! Field FRACTION_1 - fraction_1 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_1_MASK 0xFF000000u

/*! Field FRACTION_2 - fraction_2 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_2_POS 40
/*! Field FRACTION_2 - fraction_2 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_2_MASK 0xFF0000000000u

/*! Field FRACTION_3 - fraction_3 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_3_POS 56
/*! Field FRACTION_3 - fraction_3 */
#define TMCPY_TA_BANDWIDTH_0_FRACTION_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMCPY_TA_BANDWIDTH_1 Register TMCPY_TA_BANDWIDTH_1 - bandwidth_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_BANDWIDTH_1 0x908
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_BANDWIDTH_1 0xA0000908u

/*! Register Reset Value */
#define TMCPY_TA_BANDWIDTH_1_RST 0x0000000000000000u

/*! Field FRACTION_4 - fraction_4 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_4_POS 8
/*! Field FRACTION_4 - fraction_4 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_4_MASK 0xFF00u

/*! Field FRACTION_5 - fraction_5 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_5_POS 24
/*! Field FRACTION_5 - fraction_5 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_5_MASK 0xFF000000u

/*! Field FRACTION_6 - fraction_6 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_6_POS 40
/*! Field FRACTION_6 - fraction_6 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_6_MASK 0xFF0000000000u

/*! Field FRACTION_7 - fraction_7 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_7_POS 56
/*! Field FRACTION_7 - fraction_7 */
#define TMCPY_TA_BANDWIDTH_1_FRACTION_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMCPY_TA_BANDWIDTH_2 Register TMCPY_TA_BANDWIDTH_2 - bandwidth_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_BANDWIDTH_2 0x910
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_BANDWIDTH_2 0xA0000910u

/*! Register Reset Value */
#define TMCPY_TA_BANDWIDTH_2_RST 0x0000000000000000u

/*! Field FRACTION_8 - fraction_8 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_8_POS 8
/*! Field FRACTION_8 - fraction_8 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_8_MASK 0xFF00u

/*! Field FRACTION_9 - fraction_9 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_9_POS 24
/*! Field FRACTION_9 - fraction_9 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_9_MASK 0xFF000000u

/*! Field FRACTION_10 - fraction_10 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_10_POS 40
/*! Field FRACTION_10 - fraction_10 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_10_MASK 0xFF0000000000u

/*! Field FRACTION_11 - fraction_11 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_11_POS 56
/*! Field FRACTION_11 - fraction_11 */
#define TMCPY_TA_BANDWIDTH_2_FRACTION_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMCPY_TA_BANDWIDTH_3 Register TMCPY_TA_BANDWIDTH_3 - bandwidth_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_BANDWIDTH_3 0x918
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_BANDWIDTH_3 0xA0000918u

/*! Register Reset Value */
#define TMCPY_TA_BANDWIDTH_3_RST 0x0000000000000000u

/*! Field FRACTION_12 - fraction_12 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_12_POS 8
/*! Field FRACTION_12 - fraction_12 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_12_MASK 0xFF00u

/*! Field FRACTION_13 - fraction_13 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_13_POS 24
/*! Field FRACTION_13 - fraction_13 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_13_MASK 0xFF000000u

/*! Field FRACTION_14 - fraction_14 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_14_POS 40
/*! Field FRACTION_14 - fraction_14 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_14_MASK 0xFF0000000000u

/*! Field FRACTION_15 - fraction_15 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_15_POS 56
/*! Field FRACTION_15 - fraction_15 */
#define TMCPY_TA_BANDWIDTH_3_FRACTION_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMCPY_TA_ALLOC_LIMIT_0 Register TMCPY_TA_ALLOC_LIMIT_0 - alloc_limit_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_ALLOC_LIMIT_0 0xA00
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_ALLOC_LIMIT_0 0xA0000A00u

/*! Register Reset Value */
#define TMCPY_TA_ALLOC_LIMIT_0_RST 0x0000000000000000u

/*! Field MIN_VALUE_0 - min_value_0 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_0_POS 0
/*! Field MIN_VALUE_0 - min_value_0 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_0_MASK 0xFFu

/*! Field MAX_VALUE_0 - max_value_0 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_0_POS 8
/*! Field MAX_VALUE_0 - max_value_0 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_0_MASK 0xFF00u

/*! Field MIN_VALUE_1 - min_value_1 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_1_POS 16
/*! Field MIN_VALUE_1 - min_value_1 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_1_MASK 0xFF0000u

/*! Field MAX_VALUE_1 - max_value_1 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_1_POS 24
/*! Field MAX_VALUE_1 - max_value_1 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_1_MASK 0xFF000000u

/*! Field MIN_VALUE_2 - min_value_2 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_2_POS 32
/*! Field MIN_VALUE_2 - min_value_2 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_2_MASK 0xFF00000000u

/*! Field MAX_VALUE_2 - max_value_2 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_2_POS 40
/*! Field MAX_VALUE_2 - max_value_2 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_2_MASK 0xFF0000000000u

/*! Field MIN_VALUE_3 - min_value_3 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_3_POS 48
/*! Field MIN_VALUE_3 - min_value_3 */
#define TMCPY_TA_ALLOC_LIMIT_0_MIN_VALUE_3_MASK 0xFF000000000000u

/*! Field MAX_VALUE_3 - max_value_3 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_3_POS 56
/*! Field MAX_VALUE_3 - max_value_3 */
#define TMCPY_TA_ALLOC_LIMIT_0_MAX_VALUE_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMCPY_TA_ALLOC_LIMIT_1 Register TMCPY_TA_ALLOC_LIMIT_1 - alloc_limit_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_ALLOC_LIMIT_1 0xA08
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_ALLOC_LIMIT_1 0xA0000A08u

/*! Register Reset Value */
#define TMCPY_TA_ALLOC_LIMIT_1_RST 0x0000000000000000u

/*! Field MIN_VALUE_4 - min_value_4 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_4_POS 0
/*! Field MIN_VALUE_4 - min_value_4 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_4_MASK 0xFFu

/*! Field MAX_VALUE_4 - max_value_4 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_4_POS 8
/*! Field MAX_VALUE_4 - max_value_4 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_4_MASK 0xFF00u

/*! Field MIN_VALUE_5 - min_value_5 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_5_POS 16
/*! Field MIN_VALUE_5 - min_value_5 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_5_MASK 0xFF0000u

/*! Field MAX_VALUE_5 - max_value_5 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_5_POS 24
/*! Field MAX_VALUE_5 - max_value_5 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_5_MASK 0xFF000000u

/*! Field MIN_VALUE_6 - min_value_6 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_6_POS 32
/*! Field MIN_VALUE_6 - min_value_6 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_6_MASK 0xFF00000000u

/*! Field MAX_VALUE_6 - max_value_6 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_6_POS 40
/*! Field MAX_VALUE_6 - max_value_6 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_6_MASK 0xFF0000000000u

/*! Field MIN_VALUE_7 - min_value_7 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_7_POS 48
/*! Field MIN_VALUE_7 - min_value_7 */
#define TMCPY_TA_ALLOC_LIMIT_1_MIN_VALUE_7_MASK 0xFF000000000000u

/*! Field MAX_VALUE_7 - max_value_7 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_7_POS 56
/*! Field MAX_VALUE_7 - max_value_7 */
#define TMCPY_TA_ALLOC_LIMIT_1_MAX_VALUE_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMCPY_TA_ALLOC_LIMIT_2 Register TMCPY_TA_ALLOC_LIMIT_2 - alloc_limit_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_ALLOC_LIMIT_2 0xA10
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_ALLOC_LIMIT_2 0xA0000A10u

/*! Register Reset Value */
#define TMCPY_TA_ALLOC_LIMIT_2_RST 0x0000000000000000u

/*! Field MIN_VALUE_8 - min_value_8 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_8_POS 0
/*! Field MIN_VALUE_8 - min_value_8 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_8_MASK 0xFFu

/*! Field MAX_VALUE_8 - max_value_8 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_8_POS 8
/*! Field MAX_VALUE_8 - max_value_8 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_8_MASK 0xFF00u

/*! Field MIN_VALUE_9 - min_value_9 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_9_POS 16
/*! Field MIN_VALUE_9 - min_value_9 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_9_MASK 0xFF0000u

/*! Field MAX_VALUE_9 - max_value_9 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_9_POS 24
/*! Field MAX_VALUE_9 - max_value_9 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_9_MASK 0xFF000000u

/*! Field MIN_VALUE_10 - min_value_10 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_10_POS 32
/*! Field MIN_VALUE_10 - min_value_10 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_10_MASK 0xFF00000000u

/*! Field MAX_VALUE_10 - max_value_10 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_10_POS 40
/*! Field MAX_VALUE_10 - max_value_10 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_10_MASK 0xFF0000000000u

/*! Field MIN_VALUE_11 - min_value_11 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_11_POS 48
/*! Field MIN_VALUE_11 - min_value_11 */
#define TMCPY_TA_ALLOC_LIMIT_2_MIN_VALUE_11_MASK 0xFF000000000000u

/*! Field MAX_VALUE_11 - max_value_11 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_11_POS 56
/*! Field MAX_VALUE_11 - max_value_11 */
#define TMCPY_TA_ALLOC_LIMIT_2_MAX_VALUE_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMCPY_TA_ALLOC_LIMIT_3 Register TMCPY_TA_ALLOC_LIMIT_3 - alloc_limit_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TMCPY_TA_ALLOC_LIMIT_3 0xA18
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMCPY_TA_ALLOC_LIMIT_3 0xA0000A18u

/*! Register Reset Value */
#define TMCPY_TA_ALLOC_LIMIT_3_RST 0x0000000000000000u

/*! Field MIN_VALUE_12 - min_value_12 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_12_POS 0
/*! Field MIN_VALUE_12 - min_value_12 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_12_MASK 0xFFu

/*! Field MAX_VALUE_12 - max_value_12 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_12_POS 8
/*! Field MAX_VALUE_12 - max_value_12 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_12_MASK 0xFF00u

/*! Field MIN_VALUE_13 - min_value_13 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_13_POS 16
/*! Field MIN_VALUE_13 - min_value_13 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_13_MASK 0xFF0000u

/*! Field MAX_VALUE_13 - max_value_13 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_13_POS 24
/*! Field MAX_VALUE_13 - max_value_13 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_13_MASK 0xFF000000u

/*! Field MIN_VALUE_14 - min_value_14 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_14_POS 32
/*! Field MIN_VALUE_14 - min_value_14 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_14_MASK 0xFF00000000u

/*! Field MAX_VALUE_14 - max_value_14 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_14_POS 40
/*! Field MAX_VALUE_14 - max_value_14 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_14_MASK 0xFF0000000000u

/*! Field MIN_VALUE_15 - min_value_15 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_15_POS 48
/*! Field MIN_VALUE_15 - min_value_15 */
#define TMCPY_TA_ALLOC_LIMIT_3_MIN_VALUE_15_MASK 0xFF000000000000u

/*! Field MAX_VALUE_15 - max_value_15 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_15_POS 56
/*! Field MAX_VALUE_15 - max_value_15 */
#define TMCPY_TA_ALLOC_LIMIT_3_MAX_VALUE_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_COMPONENT Register TMPEC_TA_COMPONENT - component */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_COMPONENT 0xC00
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_COMPONENT 0xA0000C00u

/*! Register Reset Value */
#define TMPEC_TA_COMPONENT_RST 0x0000000060203532u

/*! Field REV - rev */
#define TMPEC_TA_COMPONENT_REV_POS 0
/*! Field REV - rev */
#define TMPEC_TA_COMPONENT_REV_MASK 0xFFFFu

/*! Field CODE - code */
#define TMPEC_TA_COMPONENT_CODE_POS 16
/*! Field CODE - code */
#define TMPEC_TA_COMPONENT_CODE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup TMPEC_TA_CORE Register TMPEC_TA_CORE - core */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_CORE 0xC18
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_CORE 0xA0000C18u

/*! Register Reset Value */
#define TMPEC_TA_CORE_RST 0x000088C309220001u

/*! Field REV_CODE - rev_code */
#define TMPEC_TA_CORE_REV_CODE_POS 0
/*! Field REV_CODE - rev_code */
#define TMPEC_TA_CORE_REV_CODE_MASK 0xFFFFu

/*! Field CORE_CODE - core_code */
#define TMPEC_TA_CORE_CORE_CODE_POS 16
/*! Field CORE_CODE - core_code */
#define TMPEC_TA_CORE_CORE_CODE_MASK 0xFFFF0000u

/*! Field VENDOR_CODE - vendor_code */
#define TMPEC_TA_CORE_VENDOR_CODE_POS 32
/*! Field VENDOR_CODE - vendor_code */
#define TMPEC_TA_CORE_VENDOR_CODE_MASK 0xFFFF00000000u

/*! @} */

/*! \defgroup TMPEC_TA_AGENT_CONTROL Register TMPEC_TA_AGENT_CONTROL - agent_control */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_AGENT_CONTROL 0xC20
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_AGENT_CONTROL 0xA0000C20u

/*! Register Reset Value */
#define TMPEC_TA_AGENT_CONTROL_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TMPEC_TA_AGENT_CONTROL_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TMPEC_TA_AGENT_CONTROL_CORE_RESET_MASK 0x1u

/*! Field REJECT - reject */
#define TMPEC_TA_AGENT_CONTROL_REJECT_POS 4
/*! Field REJECT - reject */
#define TMPEC_TA_AGENT_CONTROL_REJECT_MASK 0x10u

/*! Field REQ_TIMEOUT - req_timeout */
#define TMPEC_TA_AGENT_CONTROL_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TMPEC_TA_AGENT_CONTROL_REQ_TIMEOUT_MASK 0x700u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMPEC_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_POS 16
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMPEC_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_MASK 0x70000u

/*! Field SERROR_REP - serror_rep */
#define TMPEC_TA_AGENT_CONTROL_SERROR_REP_POS 24
/*! Field SERROR_REP - serror_rep */
#define TMPEC_TA_AGENT_CONTROL_SERROR_REP_MASK 0x1000000u

/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TMPEC_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_POS 25
/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TMPEC_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_MASK 0x2000000u

/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TMPEC_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_POS 26
/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TMPEC_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_MASK 0x4000000u

/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TMPEC_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_POS 27
/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TMPEC_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_MASK 0x8000000u

/*! Field RFU0 - rfu0 */
#define TMPEC_TA_AGENT_CONTROL_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TMPEC_TA_AGENT_CONTROL_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TMPEC_TA_AGENT_CONTROL_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TMPEC_TA_AGENT_CONTROL_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TMPEC_TA_AGENT_CONTROL_RFU2_POS 30
/*! Field RFU2 - rfu2 */
#define TMPEC_TA_AGENT_CONTROL_RFU2_MASK 0x40000000u

/*! Field RFU3 - rfu3 */
#define TMPEC_TA_AGENT_CONTROL_RFU3_POS 31
/*! Field RFU3 - rfu3 */
#define TMPEC_TA_AGENT_CONTROL_RFU3_MASK 0x80000000u

/*! @} */

/*! \defgroup TMPEC_TA_AGENT_STATUS Register TMPEC_TA_AGENT_STATUS - agent_status */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_AGENT_STATUS 0xC28
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_AGENT_STATUS 0xA0000C28u

/*! Register Reset Value */
#define TMPEC_TA_AGENT_STATUS_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TMPEC_TA_AGENT_STATUS_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TMPEC_TA_AGENT_STATUS_CORE_RESET_MASK 0x1u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMPEC_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_POS 3
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMPEC_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_MASK 0x8u

/*! Field REQ_WAITING - req_waiting */
#define TMPEC_TA_AGENT_STATUS_REQ_WAITING_POS 4
/*! Field REQ_WAITING - req_waiting */
#define TMPEC_TA_AGENT_STATUS_REQ_WAITING_MASK 0x10u

/*! Field RESP_ACTIVE - resp_active */
#define TMPEC_TA_AGENT_STATUS_RESP_ACTIVE_POS 5
/*! Field RESP_ACTIVE - resp_active */
#define TMPEC_TA_AGENT_STATUS_RESP_ACTIVE_MASK 0x20u

/*! Field BURST - burst */
#define TMPEC_TA_AGENT_STATUS_BURST_POS 6
/*! Field BURST - burst */
#define TMPEC_TA_AGENT_STATUS_BURST_MASK 0x40u

/*! Field READEX - readex */
#define TMPEC_TA_AGENT_STATUS_READEX_POS 7
/*! Field READEX - readex */
#define TMPEC_TA_AGENT_STATUS_READEX_MASK 0x80u

/*! Field REQ_TIMEOUT - req_timeout */
#define TMPEC_TA_AGENT_STATUS_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TMPEC_TA_AGENT_STATUS_REQ_TIMEOUT_MASK 0x100u

/*! Field TIMEBASE - timebase */
#define TMPEC_TA_AGENT_STATUS_TIMEBASE_POS 12
/*! Field TIMEBASE - timebase */
#define TMPEC_TA_AGENT_STATUS_TIMEBASE_MASK 0xF000u

/*! Field BURST_CLOSE - burst_close */
#define TMPEC_TA_AGENT_STATUS_BURST_CLOSE_POS 16
/*! Field BURST_CLOSE - burst_close */
#define TMPEC_TA_AGENT_STATUS_BURST_CLOSE_MASK 0x10000u

/*! Field SERROR - serror */
#define TMPEC_TA_AGENT_STATUS_SERROR_POS 24
/*! Field SERROR - serror */
#define TMPEC_TA_AGENT_STATUS_SERROR_MASK 0x1000000u

/*! Field RFU0 - rfu0 */
#define TMPEC_TA_AGENT_STATUS_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TMPEC_TA_AGENT_STATUS_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TMPEC_TA_AGENT_STATUS_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TMPEC_TA_AGENT_STATUS_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TMPEC_TA_AGENT_STATUS_RFU2_POS 31
/*! Field RFU2 - rfu2 */
#define TMPEC_TA_AGENT_STATUS_RFU2_MASK 0x80000000u

/*! @} */

/*! \defgroup TMPEC_TA_ERROR_LOG Register TMPEC_TA_ERROR_LOG - error_log */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_ERROR_LOG 0xC58
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_ERROR_LOG 0xA0000C58u

/*! Register Reset Value */
#define TMPEC_TA_ERROR_LOG_RST 0x0000000000000000u

/*! Field CMD - cmd */
#define TMPEC_TA_ERROR_LOG_CMD_POS 0
/*! Field CMD - cmd */
#define TMPEC_TA_ERROR_LOG_CMD_MASK 0x7u

/*! Field INITID - initid */
#define TMPEC_TA_ERROR_LOG_INITID_POS 8
/*! Field INITID - initid */
#define TMPEC_TA_ERROR_LOG_INITID_MASK 0xFF00u

/*! Field CODE - code */
#define TMPEC_TA_ERROR_LOG_CODE_POS 24
/*! Field CODE - code */
#define TMPEC_TA_ERROR_LOG_CODE_MASK 0xF000000u

/*! Field MULTI - multi */
#define TMPEC_TA_ERROR_LOG_MULTI_POS 31
/*! Field MULTI - multi */
#define TMPEC_TA_ERROR_LOG_MULTI_MASK 0x80000000u

/*! Field REQ_INFO - req_info */
#define TMPEC_TA_ERROR_LOG_REQ_INFO_POS 32
/*! Field REQ_INFO - req_info */
#define TMPEC_TA_ERROR_LOG_REQ_INFO_MASK 0xFFFFFFFF00000000u

/*! @} */

/*! \defgroup TMPEC_TA_ERROR_LOG_ADDR Register TMPEC_TA_ERROR_LOG_ADDR - error_log_addr */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_ERROR_LOG_ADDR 0xC60
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_ERROR_LOG_ADDR 0xA0000C60u

/*! Register Reset Value */
#define TMPEC_TA_ERROR_LOG_ADDR_RST 0x0000000000000000u

/*! Field ADDR - addr */
#define TMPEC_TA_ERROR_LOG_ADDR_ADDR_POS 0
/*! Field ADDR - addr */
#define TMPEC_TA_ERROR_LOG_ADDR_ADDR_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TMPEC_TA_BANDWIDTH_0 Register TMPEC_TA_BANDWIDTH_0 - bandwidth_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_BANDWIDTH_0 0xD00
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_BANDWIDTH_0 0xA0000D00u

/*! Register Reset Value */
#define TMPEC_TA_BANDWIDTH_0_RST 0x0000000000000000u

/*! Field FRACTION_0 - fraction_0 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_0_POS 8
/*! Field FRACTION_0 - fraction_0 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_0_MASK 0xFF00u

/*! Field FRACTION_1 - fraction_1 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_1_POS 24
/*! Field FRACTION_1 - fraction_1 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_1_MASK 0xFF000000u

/*! Field FRACTION_2 - fraction_2 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_2_POS 40
/*! Field FRACTION_2 - fraction_2 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_2_MASK 0xFF0000000000u

/*! Field FRACTION_3 - fraction_3 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_3_POS 56
/*! Field FRACTION_3 - fraction_3 */
#define TMPEC_TA_BANDWIDTH_0_FRACTION_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_BANDWIDTH_1 Register TMPEC_TA_BANDWIDTH_1 - bandwidth_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_BANDWIDTH_1 0xD08
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_BANDWIDTH_1 0xA0000D08u

/*! Register Reset Value */
#define TMPEC_TA_BANDWIDTH_1_RST 0x0000000000000000u

/*! Field FRACTION_4 - fraction_4 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_4_POS 8
/*! Field FRACTION_4 - fraction_4 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_4_MASK 0xFF00u

/*! Field FRACTION_5 - fraction_5 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_5_POS 24
/*! Field FRACTION_5 - fraction_5 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_5_MASK 0xFF000000u

/*! Field FRACTION_6 - fraction_6 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_6_POS 40
/*! Field FRACTION_6 - fraction_6 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_6_MASK 0xFF0000000000u

/*! Field FRACTION_7 - fraction_7 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_7_POS 56
/*! Field FRACTION_7 - fraction_7 */
#define TMPEC_TA_BANDWIDTH_1_FRACTION_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_BANDWIDTH_2 Register TMPEC_TA_BANDWIDTH_2 - bandwidth_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_BANDWIDTH_2 0xD10
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_BANDWIDTH_2 0xA0000D10u

/*! Register Reset Value */
#define TMPEC_TA_BANDWIDTH_2_RST 0x0000000000000000u

/*! Field FRACTION_8 - fraction_8 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_8_POS 8
/*! Field FRACTION_8 - fraction_8 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_8_MASK 0xFF00u

/*! Field FRACTION_9 - fraction_9 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_9_POS 24
/*! Field FRACTION_9 - fraction_9 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_9_MASK 0xFF000000u

/*! Field FRACTION_10 - fraction_10 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_10_POS 40
/*! Field FRACTION_10 - fraction_10 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_10_MASK 0xFF0000000000u

/*! Field FRACTION_11 - fraction_11 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_11_POS 56
/*! Field FRACTION_11 - fraction_11 */
#define TMPEC_TA_BANDWIDTH_2_FRACTION_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_BANDWIDTH_3 Register TMPEC_TA_BANDWIDTH_3 - bandwidth_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_BANDWIDTH_3 0xD18
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_BANDWIDTH_3 0xA0000D18u

/*! Register Reset Value */
#define TMPEC_TA_BANDWIDTH_3_RST 0x0000000000000000u

/*! Field FRACTION_12 - fraction_12 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_12_POS 8
/*! Field FRACTION_12 - fraction_12 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_12_MASK 0xFF00u

/*! Field FRACTION_13 - fraction_13 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_13_POS 24
/*! Field FRACTION_13 - fraction_13 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_13_MASK 0xFF000000u

/*! Field FRACTION_14 - fraction_14 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_14_POS 40
/*! Field FRACTION_14 - fraction_14 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_14_MASK 0xFF0000000000u

/*! Field FRACTION_15 - fraction_15 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_15_POS 56
/*! Field FRACTION_15 - fraction_15 */
#define TMPEC_TA_BANDWIDTH_3_FRACTION_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_ALLOC_LIMIT_0 Register TMPEC_TA_ALLOC_LIMIT_0 - alloc_limit_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_ALLOC_LIMIT_0 0xE00
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_ALLOC_LIMIT_0 0xA0000E00u

/*! Register Reset Value */
#define TMPEC_TA_ALLOC_LIMIT_0_RST 0x0000000000000000u

/*! Field MIN_VALUE_0 - min_value_0 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_0_POS 0
/*! Field MIN_VALUE_0 - min_value_0 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_0_MASK 0xFFu

/*! Field MAX_VALUE_0 - max_value_0 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_0_POS 8
/*! Field MAX_VALUE_0 - max_value_0 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_0_MASK 0xFF00u

/*! Field MIN_VALUE_1 - min_value_1 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_1_POS 16
/*! Field MIN_VALUE_1 - min_value_1 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_1_MASK 0xFF0000u

/*! Field MAX_VALUE_1 - max_value_1 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_1_POS 24
/*! Field MAX_VALUE_1 - max_value_1 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_1_MASK 0xFF000000u

/*! Field MIN_VALUE_2 - min_value_2 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_2_POS 32
/*! Field MIN_VALUE_2 - min_value_2 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_2_MASK 0xFF00000000u

/*! Field MAX_VALUE_2 - max_value_2 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_2_POS 40
/*! Field MAX_VALUE_2 - max_value_2 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_2_MASK 0xFF0000000000u

/*! Field MIN_VALUE_3 - min_value_3 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_3_POS 48
/*! Field MIN_VALUE_3 - min_value_3 */
#define TMPEC_TA_ALLOC_LIMIT_0_MIN_VALUE_3_MASK 0xFF000000000000u

/*! Field MAX_VALUE_3 - max_value_3 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_3_POS 56
/*! Field MAX_VALUE_3 - max_value_3 */
#define TMPEC_TA_ALLOC_LIMIT_0_MAX_VALUE_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_ALLOC_LIMIT_1 Register TMPEC_TA_ALLOC_LIMIT_1 - alloc_limit_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_ALLOC_LIMIT_1 0xE08
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_ALLOC_LIMIT_1 0xA0000E08u

/*! Register Reset Value */
#define TMPEC_TA_ALLOC_LIMIT_1_RST 0x0000000000000000u

/*! Field MIN_VALUE_4 - min_value_4 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_4_POS 0
/*! Field MIN_VALUE_4 - min_value_4 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_4_MASK 0xFFu

/*! Field MAX_VALUE_4 - max_value_4 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_4_POS 8
/*! Field MAX_VALUE_4 - max_value_4 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_4_MASK 0xFF00u

/*! Field MIN_VALUE_5 - min_value_5 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_5_POS 16
/*! Field MIN_VALUE_5 - min_value_5 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_5_MASK 0xFF0000u

/*! Field MAX_VALUE_5 - max_value_5 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_5_POS 24
/*! Field MAX_VALUE_5 - max_value_5 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_5_MASK 0xFF000000u

/*! Field MIN_VALUE_6 - min_value_6 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_6_POS 32
/*! Field MIN_VALUE_6 - min_value_6 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_6_MASK 0xFF00000000u

/*! Field MAX_VALUE_6 - max_value_6 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_6_POS 40
/*! Field MAX_VALUE_6 - max_value_6 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_6_MASK 0xFF0000000000u

/*! Field MIN_VALUE_7 - min_value_7 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_7_POS 48
/*! Field MIN_VALUE_7 - min_value_7 */
#define TMPEC_TA_ALLOC_LIMIT_1_MIN_VALUE_7_MASK 0xFF000000000000u

/*! Field MAX_VALUE_7 - max_value_7 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_7_POS 56
/*! Field MAX_VALUE_7 - max_value_7 */
#define TMPEC_TA_ALLOC_LIMIT_1_MAX_VALUE_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_ALLOC_LIMIT_2 Register TMPEC_TA_ALLOC_LIMIT_2 - alloc_limit_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_ALLOC_LIMIT_2 0xE10
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_ALLOC_LIMIT_2 0xA0000E10u

/*! Register Reset Value */
#define TMPEC_TA_ALLOC_LIMIT_2_RST 0x0000000000000000u

/*! Field MIN_VALUE_8 - min_value_8 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_8_POS 0
/*! Field MIN_VALUE_8 - min_value_8 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_8_MASK 0xFFu

/*! Field MAX_VALUE_8 - max_value_8 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_8_POS 8
/*! Field MAX_VALUE_8 - max_value_8 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_8_MASK 0xFF00u

/*! Field MIN_VALUE_9 - min_value_9 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_9_POS 16
/*! Field MIN_VALUE_9 - min_value_9 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_9_MASK 0xFF0000u

/*! Field MAX_VALUE_9 - max_value_9 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_9_POS 24
/*! Field MAX_VALUE_9 - max_value_9 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_9_MASK 0xFF000000u

/*! Field MIN_VALUE_10 - min_value_10 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_10_POS 32
/*! Field MIN_VALUE_10 - min_value_10 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_10_MASK 0xFF00000000u

/*! Field MAX_VALUE_10 - max_value_10 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_10_POS 40
/*! Field MAX_VALUE_10 - max_value_10 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_10_MASK 0xFF0000000000u

/*! Field MIN_VALUE_11 - min_value_11 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_11_POS 48
/*! Field MIN_VALUE_11 - min_value_11 */
#define TMPEC_TA_ALLOC_LIMIT_2_MIN_VALUE_11_MASK 0xFF000000000000u

/*! Field MAX_VALUE_11 - max_value_11 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_11_POS 56
/*! Field MAX_VALUE_11 - max_value_11 */
#define TMPEC_TA_ALLOC_LIMIT_2_MAX_VALUE_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMPEC_TA_ALLOC_LIMIT_3 Register TMPEC_TA_ALLOC_LIMIT_3 - alloc_limit_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TMPEC_TA_ALLOC_LIMIT_3 0xE18
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMPEC_TA_ALLOC_LIMIT_3 0xA0000E18u

/*! Register Reset Value */
#define TMPEC_TA_ALLOC_LIMIT_3_RST 0x0000000000000000u

/*! Field MIN_VALUE_12 - min_value_12 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_12_POS 0
/*! Field MIN_VALUE_12 - min_value_12 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_12_MASK 0xFFu

/*! Field MAX_VALUE_12 - max_value_12 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_12_POS 8
/*! Field MAX_VALUE_12 - max_value_12 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_12_MASK 0xFF00u

/*! Field MIN_VALUE_13 - min_value_13 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_13_POS 16
/*! Field MIN_VALUE_13 - min_value_13 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_13_MASK 0xFF0000u

/*! Field MAX_VALUE_13 - max_value_13 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_13_POS 24
/*! Field MAX_VALUE_13 - max_value_13 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_13_MASK 0xFF000000u

/*! Field MIN_VALUE_14 - min_value_14 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_14_POS 32
/*! Field MIN_VALUE_14 - min_value_14 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_14_MASK 0xFF00000000u

/*! Field MAX_VALUE_14 - max_value_14 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_14_POS 40
/*! Field MAX_VALUE_14 - max_value_14 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_14_MASK 0xFF0000000000u

/*! Field MIN_VALUE_15 - min_value_15 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_15_POS 48
/*! Field MIN_VALUE_15 - min_value_15 */
#define TMPEC_TA_ALLOC_LIMIT_3_MIN_VALUE_15_MASK 0xFF000000000000u

/*! Field MAX_VALUE_15 - max_value_15 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_15_POS 56
/*! Field MAX_VALUE_15 - max_value_15 */
#define TMPEC_TA_ALLOC_LIMIT_3_MAX_VALUE_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_COMPONENT Register TMTR_TA_COMPONENT - component */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_COMPONENT 0x1000
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_COMPONENT 0xA0001000u

/*! Register Reset Value */
#define TMTR_TA_COMPONENT_RST 0x0000000060203532u

/*! Field REV - rev */
#define TMTR_TA_COMPONENT_REV_POS 0
/*! Field REV - rev */
#define TMTR_TA_COMPONENT_REV_MASK 0xFFFFu

/*! Field CODE - code */
#define TMTR_TA_COMPONENT_CODE_POS 16
/*! Field CODE - code */
#define TMTR_TA_COMPONENT_CODE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup TMTR_TA_CORE Register TMTR_TA_CORE - core */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_CORE 0x1018
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_CORE 0xA0001018u

/*! Register Reset Value */
#define TMTR_TA_CORE_RST 0x000088C309220001u

/*! Field REV_CODE - rev_code */
#define TMTR_TA_CORE_REV_CODE_POS 0
/*! Field REV_CODE - rev_code */
#define TMTR_TA_CORE_REV_CODE_MASK 0xFFFFu

/*! Field CORE_CODE - core_code */
#define TMTR_TA_CORE_CORE_CODE_POS 16
/*! Field CORE_CODE - core_code */
#define TMTR_TA_CORE_CORE_CODE_MASK 0xFFFF0000u

/*! Field VENDOR_CODE - vendor_code */
#define TMTR_TA_CORE_VENDOR_CODE_POS 32
/*! Field VENDOR_CODE - vendor_code */
#define TMTR_TA_CORE_VENDOR_CODE_MASK 0xFFFF00000000u

/*! @} */

/*! \defgroup TMTR_TA_AGENT_CONTROL Register TMTR_TA_AGENT_CONTROL - agent_control */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_AGENT_CONTROL 0x1020
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_AGENT_CONTROL 0xA0001020u

/*! Register Reset Value */
#define TMTR_TA_AGENT_CONTROL_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TMTR_TA_AGENT_CONTROL_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TMTR_TA_AGENT_CONTROL_CORE_RESET_MASK 0x1u

/*! Field REJECT - reject */
#define TMTR_TA_AGENT_CONTROL_REJECT_POS 4
/*! Field REJECT - reject */
#define TMTR_TA_AGENT_CONTROL_REJECT_MASK 0x10u

/*! Field REQ_TIMEOUT - req_timeout */
#define TMTR_TA_AGENT_CONTROL_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TMTR_TA_AGENT_CONTROL_REQ_TIMEOUT_MASK 0x700u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMTR_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_POS 16
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMTR_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_MASK 0x70000u

/*! Field SERROR_REP - serror_rep */
#define TMTR_TA_AGENT_CONTROL_SERROR_REP_POS 24
/*! Field SERROR_REP - serror_rep */
#define TMTR_TA_AGENT_CONTROL_SERROR_REP_MASK 0x1000000u

/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TMTR_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_POS 25
/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TMTR_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_MASK 0x2000000u

/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TMTR_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_POS 26
/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TMTR_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_MASK 0x4000000u

/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TMTR_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_POS 27
/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TMTR_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_MASK 0x8000000u

/*! Field RFU0 - rfu0 */
#define TMTR_TA_AGENT_CONTROL_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TMTR_TA_AGENT_CONTROL_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TMTR_TA_AGENT_CONTROL_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TMTR_TA_AGENT_CONTROL_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TMTR_TA_AGENT_CONTROL_RFU2_POS 30
/*! Field RFU2 - rfu2 */
#define TMTR_TA_AGENT_CONTROL_RFU2_MASK 0x40000000u

/*! Field RFU3 - rfu3 */
#define TMTR_TA_AGENT_CONTROL_RFU3_POS 31
/*! Field RFU3 - rfu3 */
#define TMTR_TA_AGENT_CONTROL_RFU3_MASK 0x80000000u

/*! @} */

/*! \defgroup TMTR_TA_AGENT_STATUS Register TMTR_TA_AGENT_STATUS - agent_status */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_AGENT_STATUS 0x1028
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_AGENT_STATUS 0xA0001028u

/*! Register Reset Value */
#define TMTR_TA_AGENT_STATUS_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TMTR_TA_AGENT_STATUS_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TMTR_TA_AGENT_STATUS_CORE_RESET_MASK 0x1u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMTR_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_POS 3
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TMTR_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_MASK 0x8u

/*! Field REQ_WAITING - req_waiting */
#define TMTR_TA_AGENT_STATUS_REQ_WAITING_POS 4
/*! Field REQ_WAITING - req_waiting */
#define TMTR_TA_AGENT_STATUS_REQ_WAITING_MASK 0x10u

/*! Field RESP_ACTIVE - resp_active */
#define TMTR_TA_AGENT_STATUS_RESP_ACTIVE_POS 5
/*! Field RESP_ACTIVE - resp_active */
#define TMTR_TA_AGENT_STATUS_RESP_ACTIVE_MASK 0x20u

/*! Field BURST - burst */
#define TMTR_TA_AGENT_STATUS_BURST_POS 6
/*! Field BURST - burst */
#define TMTR_TA_AGENT_STATUS_BURST_MASK 0x40u

/*! Field READEX - readex */
#define TMTR_TA_AGENT_STATUS_READEX_POS 7
/*! Field READEX - readex */
#define TMTR_TA_AGENT_STATUS_READEX_MASK 0x80u

/*! Field REQ_TIMEOUT - req_timeout */
#define TMTR_TA_AGENT_STATUS_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TMTR_TA_AGENT_STATUS_REQ_TIMEOUT_MASK 0x100u

/*! Field TIMEBASE - timebase */
#define TMTR_TA_AGENT_STATUS_TIMEBASE_POS 12
/*! Field TIMEBASE - timebase */
#define TMTR_TA_AGENT_STATUS_TIMEBASE_MASK 0xF000u

/*! Field BURST_CLOSE - burst_close */
#define TMTR_TA_AGENT_STATUS_BURST_CLOSE_POS 16
/*! Field BURST_CLOSE - burst_close */
#define TMTR_TA_AGENT_STATUS_BURST_CLOSE_MASK 0x10000u

/*! Field SERROR - serror */
#define TMTR_TA_AGENT_STATUS_SERROR_POS 24
/*! Field SERROR - serror */
#define TMTR_TA_AGENT_STATUS_SERROR_MASK 0x1000000u

/*! Field RFU0 - rfu0 */
#define TMTR_TA_AGENT_STATUS_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TMTR_TA_AGENT_STATUS_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TMTR_TA_AGENT_STATUS_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TMTR_TA_AGENT_STATUS_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TMTR_TA_AGENT_STATUS_RFU2_POS 31
/*! Field RFU2 - rfu2 */
#define TMTR_TA_AGENT_STATUS_RFU2_MASK 0x80000000u

/*! @} */

/*! \defgroup TMTR_TA_ERROR_LOG Register TMTR_TA_ERROR_LOG - error_log */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_ERROR_LOG 0x1058
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_ERROR_LOG 0xA0001058u

/*! Register Reset Value */
#define TMTR_TA_ERROR_LOG_RST 0x0000000000000000u

/*! Field CMD - cmd */
#define TMTR_TA_ERROR_LOG_CMD_POS 0
/*! Field CMD - cmd */
#define TMTR_TA_ERROR_LOG_CMD_MASK 0x7u

/*! Field INITID - initid */
#define TMTR_TA_ERROR_LOG_INITID_POS 8
/*! Field INITID - initid */
#define TMTR_TA_ERROR_LOG_INITID_MASK 0xFF00u

/*! Field CODE - code */
#define TMTR_TA_ERROR_LOG_CODE_POS 24
/*! Field CODE - code */
#define TMTR_TA_ERROR_LOG_CODE_MASK 0xF000000u

/*! Field MULTI - multi */
#define TMTR_TA_ERROR_LOG_MULTI_POS 31
/*! Field MULTI - multi */
#define TMTR_TA_ERROR_LOG_MULTI_MASK 0x80000000u

/*! Field REQ_INFO - req_info */
#define TMTR_TA_ERROR_LOG_REQ_INFO_POS 32
/*! Field REQ_INFO - req_info */
#define TMTR_TA_ERROR_LOG_REQ_INFO_MASK 0xFFFFFFFF00000000u

/*! @} */

/*! \defgroup TMTR_TA_ERROR_LOG_ADDR Register TMTR_TA_ERROR_LOG_ADDR - error_log_addr */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_ERROR_LOG_ADDR 0x1060
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_ERROR_LOG_ADDR 0xA0001060u

/*! Register Reset Value */
#define TMTR_TA_ERROR_LOG_ADDR_RST 0x0000000000000000u

/*! Field ADDR - addr */
#define TMTR_TA_ERROR_LOG_ADDR_ADDR_POS 0
/*! Field ADDR - addr */
#define TMTR_TA_ERROR_LOG_ADDR_ADDR_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TMTR_TA_BANDWIDTH_0 Register TMTR_TA_BANDWIDTH_0 - bandwidth_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_BANDWIDTH_0 0x1100
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_BANDWIDTH_0 0xA0001100u

/*! Register Reset Value */
#define TMTR_TA_BANDWIDTH_0_RST 0x0000000000000000u

/*! Field FRACTION_0 - fraction_0 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_0_POS 8
/*! Field FRACTION_0 - fraction_0 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_0_MASK 0xFF00u

/*! Field FRACTION_1 - fraction_1 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_1_POS 24
/*! Field FRACTION_1 - fraction_1 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_1_MASK 0xFF000000u

/*! Field FRACTION_2 - fraction_2 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_2_POS 40
/*! Field FRACTION_2 - fraction_2 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_2_MASK 0xFF0000000000u

/*! Field FRACTION_3 - fraction_3 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_3_POS 56
/*! Field FRACTION_3 - fraction_3 */
#define TMTR_TA_BANDWIDTH_0_FRACTION_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_BANDWIDTH_1 Register TMTR_TA_BANDWIDTH_1 - bandwidth_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_BANDWIDTH_1 0x1108
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_BANDWIDTH_1 0xA0001108u

/*! Register Reset Value */
#define TMTR_TA_BANDWIDTH_1_RST 0x0000000000000000u

/*! Field FRACTION_4 - fraction_4 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_4_POS 8
/*! Field FRACTION_4 - fraction_4 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_4_MASK 0xFF00u

/*! Field FRACTION_5 - fraction_5 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_5_POS 24
/*! Field FRACTION_5 - fraction_5 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_5_MASK 0xFF000000u

/*! Field FRACTION_6 - fraction_6 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_6_POS 40
/*! Field FRACTION_6 - fraction_6 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_6_MASK 0xFF0000000000u

/*! Field FRACTION_7 - fraction_7 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_7_POS 56
/*! Field FRACTION_7 - fraction_7 */
#define TMTR_TA_BANDWIDTH_1_FRACTION_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_BANDWIDTH_2 Register TMTR_TA_BANDWIDTH_2 - bandwidth_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_BANDWIDTH_2 0x1110
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_BANDWIDTH_2 0xA0001110u

/*! Register Reset Value */
#define TMTR_TA_BANDWIDTH_2_RST 0x0000000000000000u

/*! Field FRACTION_8 - fraction_8 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_8_POS 8
/*! Field FRACTION_8 - fraction_8 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_8_MASK 0xFF00u

/*! Field FRACTION_9 - fraction_9 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_9_POS 24
/*! Field FRACTION_9 - fraction_9 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_9_MASK 0xFF000000u

/*! Field FRACTION_10 - fraction_10 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_10_POS 40
/*! Field FRACTION_10 - fraction_10 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_10_MASK 0xFF0000000000u

/*! Field FRACTION_11 - fraction_11 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_11_POS 56
/*! Field FRACTION_11 - fraction_11 */
#define TMTR_TA_BANDWIDTH_2_FRACTION_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_BANDWIDTH_3 Register TMTR_TA_BANDWIDTH_3 - bandwidth_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_BANDWIDTH_3 0x1118
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_BANDWIDTH_3 0xA0001118u

/*! Register Reset Value */
#define TMTR_TA_BANDWIDTH_3_RST 0x0000000000000000u

/*! Field FRACTION_12 - fraction_12 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_12_POS 8
/*! Field FRACTION_12 - fraction_12 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_12_MASK 0xFF00u

/*! Field FRACTION_13 - fraction_13 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_13_POS 24
/*! Field FRACTION_13 - fraction_13 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_13_MASK 0xFF000000u

/*! Field FRACTION_14 - fraction_14 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_14_POS 40
/*! Field FRACTION_14 - fraction_14 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_14_MASK 0xFF0000000000u

/*! Field FRACTION_15 - fraction_15 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_15_POS 56
/*! Field FRACTION_15 - fraction_15 */
#define TMTR_TA_BANDWIDTH_3_FRACTION_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_ALLOC_LIMIT_0 Register TMTR_TA_ALLOC_LIMIT_0 - alloc_limit_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_ALLOC_LIMIT_0 0x1200
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_ALLOC_LIMIT_0 0xA0001200u

/*! Register Reset Value */
#define TMTR_TA_ALLOC_LIMIT_0_RST 0x0000000000000000u

/*! Field MIN_VALUE_0 - min_value_0 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_0_POS 0
/*! Field MIN_VALUE_0 - min_value_0 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_0_MASK 0xFFu

/*! Field MAX_VALUE_0 - max_value_0 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_0_POS 8
/*! Field MAX_VALUE_0 - max_value_0 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_0_MASK 0xFF00u

/*! Field MIN_VALUE_1 - min_value_1 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_1_POS 16
/*! Field MIN_VALUE_1 - min_value_1 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_1_MASK 0xFF0000u

/*! Field MAX_VALUE_1 - max_value_1 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_1_POS 24
/*! Field MAX_VALUE_1 - max_value_1 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_1_MASK 0xFF000000u

/*! Field MIN_VALUE_2 - min_value_2 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_2_POS 32
/*! Field MIN_VALUE_2 - min_value_2 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_2_MASK 0xFF00000000u

/*! Field MAX_VALUE_2 - max_value_2 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_2_POS 40
/*! Field MAX_VALUE_2 - max_value_2 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_2_MASK 0xFF0000000000u

/*! Field MIN_VALUE_3 - min_value_3 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_3_POS 48
/*! Field MIN_VALUE_3 - min_value_3 */
#define TMTR_TA_ALLOC_LIMIT_0_MIN_VALUE_3_MASK 0xFF000000000000u

/*! Field MAX_VALUE_3 - max_value_3 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_3_POS 56
/*! Field MAX_VALUE_3 - max_value_3 */
#define TMTR_TA_ALLOC_LIMIT_0_MAX_VALUE_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_ALLOC_LIMIT_1 Register TMTR_TA_ALLOC_LIMIT_1 - alloc_limit_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_ALLOC_LIMIT_1 0x1208
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_ALLOC_LIMIT_1 0xA0001208u

/*! Register Reset Value */
#define TMTR_TA_ALLOC_LIMIT_1_RST 0x0000000000000000u

/*! Field MIN_VALUE_4 - min_value_4 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_4_POS 0
/*! Field MIN_VALUE_4 - min_value_4 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_4_MASK 0xFFu

/*! Field MAX_VALUE_4 - max_value_4 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_4_POS 8
/*! Field MAX_VALUE_4 - max_value_4 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_4_MASK 0xFF00u

/*! Field MIN_VALUE_5 - min_value_5 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_5_POS 16
/*! Field MIN_VALUE_5 - min_value_5 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_5_MASK 0xFF0000u

/*! Field MAX_VALUE_5 - max_value_5 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_5_POS 24
/*! Field MAX_VALUE_5 - max_value_5 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_5_MASK 0xFF000000u

/*! Field MIN_VALUE_6 - min_value_6 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_6_POS 32
/*! Field MIN_VALUE_6 - min_value_6 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_6_MASK 0xFF00000000u

/*! Field MAX_VALUE_6 - max_value_6 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_6_POS 40
/*! Field MAX_VALUE_6 - max_value_6 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_6_MASK 0xFF0000000000u

/*! Field MIN_VALUE_7 - min_value_7 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_7_POS 48
/*! Field MIN_VALUE_7 - min_value_7 */
#define TMTR_TA_ALLOC_LIMIT_1_MIN_VALUE_7_MASK 0xFF000000000000u

/*! Field MAX_VALUE_7 - max_value_7 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_7_POS 56
/*! Field MAX_VALUE_7 - max_value_7 */
#define TMTR_TA_ALLOC_LIMIT_1_MAX_VALUE_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_ALLOC_LIMIT_2 Register TMTR_TA_ALLOC_LIMIT_2 - alloc_limit_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_ALLOC_LIMIT_2 0x1210
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_ALLOC_LIMIT_2 0xA0001210u

/*! Register Reset Value */
#define TMTR_TA_ALLOC_LIMIT_2_RST 0x0000000000000000u

/*! Field MIN_VALUE_8 - min_value_8 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_8_POS 0
/*! Field MIN_VALUE_8 - min_value_8 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_8_MASK 0xFFu

/*! Field MAX_VALUE_8 - max_value_8 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_8_POS 8
/*! Field MAX_VALUE_8 - max_value_8 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_8_MASK 0xFF00u

/*! Field MIN_VALUE_9 - min_value_9 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_9_POS 16
/*! Field MIN_VALUE_9 - min_value_9 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_9_MASK 0xFF0000u

/*! Field MAX_VALUE_9 - max_value_9 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_9_POS 24
/*! Field MAX_VALUE_9 - max_value_9 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_9_MASK 0xFF000000u

/*! Field MIN_VALUE_10 - min_value_10 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_10_POS 32
/*! Field MIN_VALUE_10 - min_value_10 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_10_MASK 0xFF00000000u

/*! Field MAX_VALUE_10 - max_value_10 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_10_POS 40
/*! Field MAX_VALUE_10 - max_value_10 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_10_MASK 0xFF0000000000u

/*! Field MIN_VALUE_11 - min_value_11 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_11_POS 48
/*! Field MIN_VALUE_11 - min_value_11 */
#define TMTR_TA_ALLOC_LIMIT_2_MIN_VALUE_11_MASK 0xFF000000000000u

/*! Field MAX_VALUE_11 - max_value_11 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_11_POS 56
/*! Field MAX_VALUE_11 - max_value_11 */
#define TMTR_TA_ALLOC_LIMIT_2_MAX_VALUE_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TMTR_TA_ALLOC_LIMIT_3 Register TMTR_TA_ALLOC_LIMIT_3 - alloc_limit_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TMTR_TA_ALLOC_LIMIT_3 0x1218
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TMTR_TA_ALLOC_LIMIT_3 0xA0001218u

/*! Register Reset Value */
#define TMTR_TA_ALLOC_LIMIT_3_RST 0x0000000000000000u

/*! Field MIN_VALUE_12 - min_value_12 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_12_POS 0
/*! Field MIN_VALUE_12 - min_value_12 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_12_MASK 0xFFu

/*! Field MAX_VALUE_12 - max_value_12 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_12_POS 8
/*! Field MAX_VALUE_12 - max_value_12 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_12_MASK 0xFF00u

/*! Field MIN_VALUE_13 - min_value_13 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_13_POS 16
/*! Field MIN_VALUE_13 - min_value_13 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_13_MASK 0xFF0000u

/*! Field MAX_VALUE_13 - max_value_13 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_13_POS 24
/*! Field MAX_VALUE_13 - max_value_13 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_13_MASK 0xFF000000u

/*! Field MIN_VALUE_14 - min_value_14 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_14_POS 32
/*! Field MIN_VALUE_14 - min_value_14 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_14_MASK 0xFF00000000u

/*! Field MAX_VALUE_14 - max_value_14 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_14_POS 40
/*! Field MAX_VALUE_14 - max_value_14 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_14_MASK 0xFF0000000000u

/*! Field MIN_VALUE_15 - min_value_15 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_15_POS 48
/*! Field MIN_VALUE_15 - min_value_15 */
#define TMTR_TA_ALLOC_LIMIT_3_MIN_VALUE_15_MASK 0xFF000000000000u

/*! Field MAX_VALUE_15 - max_value_15 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_15_POS 56
/*! Field MAX_VALUE_15 - max_value_15 */
#define TMTR_TA_ALLOC_LIMIT_3_MAX_VALUE_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_COMPONENT Register TSE_TA_COMPONENT - component */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_COMPONENT 0x1400
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_COMPONENT 0xA0001400u

/*! Register Reset Value */
#define TSE_TA_COMPONENT_RST 0x0000000060203532u

/*! Field REV - rev */
#define TSE_TA_COMPONENT_REV_POS 0
/*! Field REV - rev */
#define TSE_TA_COMPONENT_REV_MASK 0xFFFFu

/*! Field CODE - code */
#define TSE_TA_COMPONENT_CODE_POS 16
/*! Field CODE - code */
#define TSE_TA_COMPONENT_CODE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup TSE_TA_CORE Register TSE_TA_CORE - core */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_CORE 0x1418
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_CORE 0xA0001418u

/*! Register Reset Value */
#define TSE_TA_CORE_RST 0x000088C309220001u

/*! Field REV_CODE - rev_code */
#define TSE_TA_CORE_REV_CODE_POS 0
/*! Field REV_CODE - rev_code */
#define TSE_TA_CORE_REV_CODE_MASK 0xFFFFu

/*! Field CORE_CODE - core_code */
#define TSE_TA_CORE_CORE_CODE_POS 16
/*! Field CORE_CODE - core_code */
#define TSE_TA_CORE_CORE_CODE_MASK 0xFFFF0000u

/*! Field VENDOR_CODE - vendor_code */
#define TSE_TA_CORE_VENDOR_CODE_POS 32
/*! Field VENDOR_CODE - vendor_code */
#define TSE_TA_CORE_VENDOR_CODE_MASK 0xFFFF00000000u

/*! @} */

/*! \defgroup TSE_TA_AGENT_CONTROL Register TSE_TA_AGENT_CONTROL - agent_control */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_AGENT_CONTROL 0x1420
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_AGENT_CONTROL 0xA0001420u

/*! Register Reset Value */
#define TSE_TA_AGENT_CONTROL_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TSE_TA_AGENT_CONTROL_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TSE_TA_AGENT_CONTROL_CORE_RESET_MASK 0x1u

/*! Field REJECT - reject */
#define TSE_TA_AGENT_CONTROL_REJECT_POS 4
/*! Field REJECT - reject */
#define TSE_TA_AGENT_CONTROL_REJECT_MASK 0x10u

/*! Field REQ_TIMEOUT - req_timeout */
#define TSE_TA_AGENT_CONTROL_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TSE_TA_AGENT_CONTROL_REQ_TIMEOUT_MASK 0x700u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TSE_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_POS 16
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TSE_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_MASK 0x70000u

/*! Field SERROR_REP - serror_rep */
#define TSE_TA_AGENT_CONTROL_SERROR_REP_POS 24
/*! Field SERROR_REP - serror_rep */
#define TSE_TA_AGENT_CONTROL_SERROR_REP_MASK 0x1000000u

/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TSE_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_POS 25
/*! Field REQ_TIMEOUT_REP - req_timeout_rep */
#define TSE_TA_AGENT_CONTROL_REQ_TIMEOUT_REP_MASK 0x2000000u

/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TSE_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_POS 26
/*! Field FUNCTIONAL_RESET_TIMEOUT_REP - functional_reset_timeout_rep */
#define TSE_TA_AGENT_CONTROL_FUNCTIONAL_RESET_TIMEOUT_REP_MASK 0x4000000u

/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TSE_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_POS 27
/*! Field AUTO_WAKEUP_RESP_CODE - auto_wakeup_resp_code */
#define TSE_TA_AGENT_CONTROL_AUTO_WAKEUP_RESP_CODE_MASK 0x8000000u

/*! Field RFU0 - rfu0 */
#define TSE_TA_AGENT_CONTROL_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TSE_TA_AGENT_CONTROL_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TSE_TA_AGENT_CONTROL_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TSE_TA_AGENT_CONTROL_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TSE_TA_AGENT_CONTROL_RFU2_POS 30
/*! Field RFU2 - rfu2 */
#define TSE_TA_AGENT_CONTROL_RFU2_MASK 0x40000000u

/*! Field RFU3 - rfu3 */
#define TSE_TA_AGENT_CONTROL_RFU3_POS 31
/*! Field RFU3 - rfu3 */
#define TSE_TA_AGENT_CONTROL_RFU3_MASK 0x80000000u

/*! @} */

/*! \defgroup TSE_TA_AGENT_STATUS Register TSE_TA_AGENT_STATUS - agent_status */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_AGENT_STATUS 0x1428
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_AGENT_STATUS 0xA0001428u

/*! Register Reset Value */
#define TSE_TA_AGENT_STATUS_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define TSE_TA_AGENT_STATUS_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define TSE_TA_AGENT_STATUS_CORE_RESET_MASK 0x1u

/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TSE_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_POS 3
/*! Field FUNCTIONAL_RESET_TIMEOUT - functional_reset_timeout */
#define TSE_TA_AGENT_STATUS_FUNCTIONAL_RESET_TIMEOUT_MASK 0x8u

/*! Field REQ_WAITING - req_waiting */
#define TSE_TA_AGENT_STATUS_REQ_WAITING_POS 4
/*! Field REQ_WAITING - req_waiting */
#define TSE_TA_AGENT_STATUS_REQ_WAITING_MASK 0x10u

/*! Field RESP_ACTIVE - resp_active */
#define TSE_TA_AGENT_STATUS_RESP_ACTIVE_POS 5
/*! Field RESP_ACTIVE - resp_active */
#define TSE_TA_AGENT_STATUS_RESP_ACTIVE_MASK 0x20u

/*! Field BURST - burst */
#define TSE_TA_AGENT_STATUS_BURST_POS 6
/*! Field BURST - burst */
#define TSE_TA_AGENT_STATUS_BURST_MASK 0x40u

/*! Field READEX - readex */
#define TSE_TA_AGENT_STATUS_READEX_POS 7
/*! Field READEX - readex */
#define TSE_TA_AGENT_STATUS_READEX_MASK 0x80u

/*! Field REQ_TIMEOUT - req_timeout */
#define TSE_TA_AGENT_STATUS_REQ_TIMEOUT_POS 8
/*! Field REQ_TIMEOUT - req_timeout */
#define TSE_TA_AGENT_STATUS_REQ_TIMEOUT_MASK 0x100u

/*! Field TIMEBASE - timebase */
#define TSE_TA_AGENT_STATUS_TIMEBASE_POS 12
/*! Field TIMEBASE - timebase */
#define TSE_TA_AGENT_STATUS_TIMEBASE_MASK 0xF000u

/*! Field BURST_CLOSE - burst_close */
#define TSE_TA_AGENT_STATUS_BURST_CLOSE_POS 16
/*! Field BURST_CLOSE - burst_close */
#define TSE_TA_AGENT_STATUS_BURST_CLOSE_MASK 0x10000u

/*! Field SERROR - serror */
#define TSE_TA_AGENT_STATUS_SERROR_POS 24
/*! Field SERROR - serror */
#define TSE_TA_AGENT_STATUS_SERROR_MASK 0x1000000u

/*! Field RFU0 - rfu0 */
#define TSE_TA_AGENT_STATUS_RFU0_POS 28
/*! Field RFU0 - rfu0 */
#define TSE_TA_AGENT_STATUS_RFU0_MASK 0x10000000u

/*! Field RFU1 - rfu1 */
#define TSE_TA_AGENT_STATUS_RFU1_POS 29
/*! Field RFU1 - rfu1 */
#define TSE_TA_AGENT_STATUS_RFU1_MASK 0x20000000u

/*! Field RFU2 - rfu2 */
#define TSE_TA_AGENT_STATUS_RFU2_POS 31
/*! Field RFU2 - rfu2 */
#define TSE_TA_AGENT_STATUS_RFU2_MASK 0x80000000u

/*! @} */

/*! \defgroup TSE_TA_ERROR_LOG Register TSE_TA_ERROR_LOG - error_log */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_ERROR_LOG 0x1458
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_ERROR_LOG 0xA0001458u

/*! Register Reset Value */
#define TSE_TA_ERROR_LOG_RST 0x0000000000000000u

/*! Field CMD - cmd */
#define TSE_TA_ERROR_LOG_CMD_POS 0
/*! Field CMD - cmd */
#define TSE_TA_ERROR_LOG_CMD_MASK 0x7u

/*! Field INITID - initid */
#define TSE_TA_ERROR_LOG_INITID_POS 8
/*! Field INITID - initid */
#define TSE_TA_ERROR_LOG_INITID_MASK 0xFF00u

/*! Field CODE - code */
#define TSE_TA_ERROR_LOG_CODE_POS 24
/*! Field CODE - code */
#define TSE_TA_ERROR_LOG_CODE_MASK 0xF000000u

/*! Field MULTI - multi */
#define TSE_TA_ERROR_LOG_MULTI_POS 31
/*! Field MULTI - multi */
#define TSE_TA_ERROR_LOG_MULTI_MASK 0x80000000u

/*! Field REQ_INFO - req_info */
#define TSE_TA_ERROR_LOG_REQ_INFO_POS 32
/*! Field REQ_INFO - req_info */
#define TSE_TA_ERROR_LOG_REQ_INFO_MASK 0xFFFFFFFF00000000u

/*! @} */

/*! \defgroup TSE_TA_ERROR_LOG_ADDR Register TSE_TA_ERROR_LOG_ADDR - error_log_addr */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_ERROR_LOG_ADDR 0x1460
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_ERROR_LOG_ADDR 0xA0001460u

/*! Register Reset Value */
#define TSE_TA_ERROR_LOG_ADDR_RST 0x0000000000000000u

/*! Field ADDR - addr */
#define TSE_TA_ERROR_LOG_ADDR_ADDR_POS 0
/*! Field ADDR - addr */
#define TSE_TA_ERROR_LOG_ADDR_ADDR_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup TSE_TA_BANDWIDTH_0 Register TSE_TA_BANDWIDTH_0 - bandwidth_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_BANDWIDTH_0 0x1500
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_BANDWIDTH_0 0xA0001500u

/*! Register Reset Value */
#define TSE_TA_BANDWIDTH_0_RST 0x0000000000000000u

/*! Field FRACTION_0 - fraction_0 */
#define TSE_TA_BANDWIDTH_0_FRACTION_0_POS 8
/*! Field FRACTION_0 - fraction_0 */
#define TSE_TA_BANDWIDTH_0_FRACTION_0_MASK 0xFF00u

/*! Field FRACTION_1 - fraction_1 */
#define TSE_TA_BANDWIDTH_0_FRACTION_1_POS 24
/*! Field FRACTION_1 - fraction_1 */
#define TSE_TA_BANDWIDTH_0_FRACTION_1_MASK 0xFF000000u

/*! Field FRACTION_2 - fraction_2 */
#define TSE_TA_BANDWIDTH_0_FRACTION_2_POS 40
/*! Field FRACTION_2 - fraction_2 */
#define TSE_TA_BANDWIDTH_0_FRACTION_2_MASK 0xFF0000000000u

/*! Field FRACTION_3 - fraction_3 */
#define TSE_TA_BANDWIDTH_0_FRACTION_3_POS 56
/*! Field FRACTION_3 - fraction_3 */
#define TSE_TA_BANDWIDTH_0_FRACTION_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_BANDWIDTH_1 Register TSE_TA_BANDWIDTH_1 - bandwidth_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_BANDWIDTH_1 0x1508
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_BANDWIDTH_1 0xA0001508u

/*! Register Reset Value */
#define TSE_TA_BANDWIDTH_1_RST 0x0000000000000000u

/*! Field FRACTION_4 - fraction_4 */
#define TSE_TA_BANDWIDTH_1_FRACTION_4_POS 8
/*! Field FRACTION_4 - fraction_4 */
#define TSE_TA_BANDWIDTH_1_FRACTION_4_MASK 0xFF00u

/*! Field FRACTION_5 - fraction_5 */
#define TSE_TA_BANDWIDTH_1_FRACTION_5_POS 24
/*! Field FRACTION_5 - fraction_5 */
#define TSE_TA_BANDWIDTH_1_FRACTION_5_MASK 0xFF000000u

/*! Field FRACTION_6 - fraction_6 */
#define TSE_TA_BANDWIDTH_1_FRACTION_6_POS 40
/*! Field FRACTION_6 - fraction_6 */
#define TSE_TA_BANDWIDTH_1_FRACTION_6_MASK 0xFF0000000000u

/*! Field FRACTION_7 - fraction_7 */
#define TSE_TA_BANDWIDTH_1_FRACTION_7_POS 56
/*! Field FRACTION_7 - fraction_7 */
#define TSE_TA_BANDWIDTH_1_FRACTION_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_BANDWIDTH_2 Register TSE_TA_BANDWIDTH_2 - bandwidth_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_BANDWIDTH_2 0x1510
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_BANDWIDTH_2 0xA0001510u

/*! Register Reset Value */
#define TSE_TA_BANDWIDTH_2_RST 0x0000000000000000u

/*! Field FRACTION_8 - fraction_8 */
#define TSE_TA_BANDWIDTH_2_FRACTION_8_POS 8
/*! Field FRACTION_8 - fraction_8 */
#define TSE_TA_BANDWIDTH_2_FRACTION_8_MASK 0xFF00u

/*! Field FRACTION_9 - fraction_9 */
#define TSE_TA_BANDWIDTH_2_FRACTION_9_POS 24
/*! Field FRACTION_9 - fraction_9 */
#define TSE_TA_BANDWIDTH_2_FRACTION_9_MASK 0xFF000000u

/*! Field FRACTION_10 - fraction_10 */
#define TSE_TA_BANDWIDTH_2_FRACTION_10_POS 40
/*! Field FRACTION_10 - fraction_10 */
#define TSE_TA_BANDWIDTH_2_FRACTION_10_MASK 0xFF0000000000u

/*! Field FRACTION_11 - fraction_11 */
#define TSE_TA_BANDWIDTH_2_FRACTION_11_POS 56
/*! Field FRACTION_11 - fraction_11 */
#define TSE_TA_BANDWIDTH_2_FRACTION_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_BANDWIDTH_3 Register TSE_TA_BANDWIDTH_3 - bandwidth_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_BANDWIDTH_3 0x1518
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_BANDWIDTH_3 0xA0001518u

/*! Register Reset Value */
#define TSE_TA_BANDWIDTH_3_RST 0x0000000000000000u

/*! Field FRACTION_12 - fraction_12 */
#define TSE_TA_BANDWIDTH_3_FRACTION_12_POS 8
/*! Field FRACTION_12 - fraction_12 */
#define TSE_TA_BANDWIDTH_3_FRACTION_12_MASK 0xFF00u

/*! Field FRACTION_13 - fraction_13 */
#define TSE_TA_BANDWIDTH_3_FRACTION_13_POS 24
/*! Field FRACTION_13 - fraction_13 */
#define TSE_TA_BANDWIDTH_3_FRACTION_13_MASK 0xFF000000u

/*! Field FRACTION_14 - fraction_14 */
#define TSE_TA_BANDWIDTH_3_FRACTION_14_POS 40
/*! Field FRACTION_14 - fraction_14 */
#define TSE_TA_BANDWIDTH_3_FRACTION_14_MASK 0xFF0000000000u

/*! Field FRACTION_15 - fraction_15 */
#define TSE_TA_BANDWIDTH_3_FRACTION_15_POS 56
/*! Field FRACTION_15 - fraction_15 */
#define TSE_TA_BANDWIDTH_3_FRACTION_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_ALLOC_LIMIT_0 Register TSE_TA_ALLOC_LIMIT_0 - alloc_limit_0 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_ALLOC_LIMIT_0 0x1600
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_ALLOC_LIMIT_0 0xA0001600u

/*! Register Reset Value */
#define TSE_TA_ALLOC_LIMIT_0_RST 0x0000000000000000u

/*! Field MIN_VALUE_0 - min_value_0 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_0_POS 0
/*! Field MIN_VALUE_0 - min_value_0 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_0_MASK 0xFFu

/*! Field MAX_VALUE_0 - max_value_0 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_0_POS 8
/*! Field MAX_VALUE_0 - max_value_0 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_0_MASK 0xFF00u

/*! Field MIN_VALUE_1 - min_value_1 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_1_POS 16
/*! Field MIN_VALUE_1 - min_value_1 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_1_MASK 0xFF0000u

/*! Field MAX_VALUE_1 - max_value_1 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_1_POS 24
/*! Field MAX_VALUE_1 - max_value_1 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_1_MASK 0xFF000000u

/*! Field MIN_VALUE_2 - min_value_2 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_2_POS 32
/*! Field MIN_VALUE_2 - min_value_2 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_2_MASK 0xFF00000000u

/*! Field MAX_VALUE_2 - max_value_2 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_2_POS 40
/*! Field MAX_VALUE_2 - max_value_2 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_2_MASK 0xFF0000000000u

/*! Field MIN_VALUE_3 - min_value_3 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_3_POS 48
/*! Field MIN_VALUE_3 - min_value_3 */
#define TSE_TA_ALLOC_LIMIT_0_MIN_VALUE_3_MASK 0xFF000000000000u

/*! Field MAX_VALUE_3 - max_value_3 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_3_POS 56
/*! Field MAX_VALUE_3 - max_value_3 */
#define TSE_TA_ALLOC_LIMIT_0_MAX_VALUE_3_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_ALLOC_LIMIT_1 Register TSE_TA_ALLOC_LIMIT_1 - alloc_limit_1 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_ALLOC_LIMIT_1 0x1608
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_ALLOC_LIMIT_1 0xA0001608u

/*! Register Reset Value */
#define TSE_TA_ALLOC_LIMIT_1_RST 0x0000000000000000u

/*! Field MIN_VALUE_4 - min_value_4 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_4_POS 0
/*! Field MIN_VALUE_4 - min_value_4 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_4_MASK 0xFFu

/*! Field MAX_VALUE_4 - max_value_4 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_4_POS 8
/*! Field MAX_VALUE_4 - max_value_4 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_4_MASK 0xFF00u

/*! Field MIN_VALUE_5 - min_value_5 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_5_POS 16
/*! Field MIN_VALUE_5 - min_value_5 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_5_MASK 0xFF0000u

/*! Field MAX_VALUE_5 - max_value_5 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_5_POS 24
/*! Field MAX_VALUE_5 - max_value_5 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_5_MASK 0xFF000000u

/*! Field MIN_VALUE_6 - min_value_6 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_6_POS 32
/*! Field MIN_VALUE_6 - min_value_6 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_6_MASK 0xFF00000000u

/*! Field MAX_VALUE_6 - max_value_6 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_6_POS 40
/*! Field MAX_VALUE_6 - max_value_6 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_6_MASK 0xFF0000000000u

/*! Field MIN_VALUE_7 - min_value_7 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_7_POS 48
/*! Field MIN_VALUE_7 - min_value_7 */
#define TSE_TA_ALLOC_LIMIT_1_MIN_VALUE_7_MASK 0xFF000000000000u

/*! Field MAX_VALUE_7 - max_value_7 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_7_POS 56
/*! Field MAX_VALUE_7 - max_value_7 */
#define TSE_TA_ALLOC_LIMIT_1_MAX_VALUE_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_ALLOC_LIMIT_2 Register TSE_TA_ALLOC_LIMIT_2 - alloc_limit_2 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_ALLOC_LIMIT_2 0x1610
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_ALLOC_LIMIT_2 0xA0001610u

/*! Register Reset Value */
#define TSE_TA_ALLOC_LIMIT_2_RST 0x0000000000000000u

/*! Field MIN_VALUE_8 - min_value_8 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_8_POS 0
/*! Field MIN_VALUE_8 - min_value_8 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_8_MASK 0xFFu

/*! Field MAX_VALUE_8 - max_value_8 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_8_POS 8
/*! Field MAX_VALUE_8 - max_value_8 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_8_MASK 0xFF00u

/*! Field MIN_VALUE_9 - min_value_9 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_9_POS 16
/*! Field MIN_VALUE_9 - min_value_9 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_9_MASK 0xFF0000u

/*! Field MAX_VALUE_9 - max_value_9 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_9_POS 24
/*! Field MAX_VALUE_9 - max_value_9 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_9_MASK 0xFF000000u

/*! Field MIN_VALUE_10 - min_value_10 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_10_POS 32
/*! Field MIN_VALUE_10 - min_value_10 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_10_MASK 0xFF00000000u

/*! Field MAX_VALUE_10 - max_value_10 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_10_POS 40
/*! Field MAX_VALUE_10 - max_value_10 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_10_MASK 0xFF0000000000u

/*! Field MIN_VALUE_11 - min_value_11 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_11_POS 48
/*! Field MIN_VALUE_11 - min_value_11 */
#define TSE_TA_ALLOC_LIMIT_2_MIN_VALUE_11_MASK 0xFF000000000000u

/*! Field MAX_VALUE_11 - max_value_11 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_11_POS 56
/*! Field MAX_VALUE_11 - max_value_11 */
#define TSE_TA_ALLOC_LIMIT_2_MAX_VALUE_11_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup TSE_TA_ALLOC_LIMIT_3 Register TSE_TA_ALLOC_LIMIT_3 - alloc_limit_3 */
/*! @{ */

/*! Register Offset (relative) */
#define TSE_TA_ALLOC_LIMIT_3 0x1618
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_TSE_TA_ALLOC_LIMIT_3 0xA0001618u

/*! Register Reset Value */
#define TSE_TA_ALLOC_LIMIT_3_RST 0x0000000000000000u

/*! Field MIN_VALUE_12 - min_value_12 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_12_POS 0
/*! Field MIN_VALUE_12 - min_value_12 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_12_MASK 0xFFu

/*! Field MAX_VALUE_12 - max_value_12 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_12_POS 8
/*! Field MAX_VALUE_12 - max_value_12 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_12_MASK 0xFF00u

/*! Field MIN_VALUE_13 - min_value_13 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_13_POS 16
/*! Field MIN_VALUE_13 - min_value_13 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_13_MASK 0xFF0000u

/*! Field MAX_VALUE_13 - max_value_13 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_13_POS 24
/*! Field MAX_VALUE_13 - max_value_13 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_13_MASK 0xFF000000u

/*! Field MIN_VALUE_14 - min_value_14 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_14_POS 32
/*! Field MIN_VALUE_14 - min_value_14 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_14_MASK 0xFF00000000u

/*! Field MAX_VALUE_14 - max_value_14 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_14_POS 40
/*! Field MAX_VALUE_14 - max_value_14 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_14_MASK 0xFF0000000000u

/*! Field MIN_VALUE_15 - min_value_15 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_15_POS 48
/*! Field MIN_VALUE_15 - min_value_15 */
#define TSE_TA_ALLOC_LIMIT_3_MIN_VALUE_15_MASK 0xFF000000000000u

/*! Field MAX_VALUE_15 - max_value_15 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_15_POS 56
/*! Field MAX_VALUE_15 - max_value_15 */
#define TSE_TA_ALLOC_LIMIT_3_MAX_VALUE_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_COMPONENT Register ISSX7_IA_COMPONENT - component */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_COMPONENT 0x2400
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_COMPONENT 0xA0002400u

/*! Register Reset Value */
#define ISSX7_IA_COMPONENT_RST 0x0000000060103532u

/*! Field REV - rev */
#define ISSX7_IA_COMPONENT_REV_POS 0
/*! Field REV - rev */
#define ISSX7_IA_COMPONENT_REV_MASK 0xFFFFu

/*! Field CODE - code */
#define ISSX7_IA_COMPONENT_CODE_POS 16
/*! Field CODE - code */
#define ISSX7_IA_COMPONENT_CODE_MASK 0xFFFF0000u

/*! @} */

/*! \defgroup ISSX7_IA_CORE Register ISSX7_IA_CORE - core */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_CORE 0x2418
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_CORE 0xA0002418u

/*! Register Reset Value */
#define ISSX7_IA_CORE_RST 0x000050C500200001u

/*! Field REV_CODE - rev_code */
#define ISSX7_IA_CORE_REV_CODE_POS 0
/*! Field REV_CODE - rev_code */
#define ISSX7_IA_CORE_REV_CODE_MASK 0xFFFFu

/*! Field CORE_CODE - core_code */
#define ISSX7_IA_CORE_CORE_CODE_POS 16
/*! Field CORE_CODE - core_code */
#define ISSX7_IA_CORE_CORE_CODE_MASK 0xFFFF0000u

/*! Field VENDOR_CODE - vendor_code */
#define ISSX7_IA_CORE_VENDOR_CODE_POS 32
/*! Field VENDOR_CODE - vendor_code */
#define ISSX7_IA_CORE_VENDOR_CODE_MASK 0xFFFF00000000u

/*! @} */

/*! \defgroup ISSX7_IA_AGENT_CONTROL Register ISSX7_IA_AGENT_CONTROL - agent_control */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_AGENT_CONTROL 0x2420
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_AGENT_CONTROL 0xA0002420u

/*! Register Reset Value */
#define ISSX7_IA_AGENT_CONTROL_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define ISSX7_IA_AGENT_CONTROL_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define ISSX7_IA_AGENT_CONTROL_CORE_RESET_MASK 0x1u

/*! Field REJECT - reject */
#define ISSX7_IA_AGENT_CONTROL_REJECT_POS 4
/*! Field REJECT - reject */
#define ISSX7_IA_AGENT_CONTROL_REJECT_MASK 0x10u

/*! Field RESP_TIMEOUT - resp_timeout */
#define ISSX7_IA_AGENT_CONTROL_RESP_TIMEOUT_POS 8
/*! Field RESP_TIMEOUT - resp_timeout */
#define ISSX7_IA_AGENT_CONTROL_RESP_TIMEOUT_MASK 0x700u

/*! Field BURST_TIMEOUT - burst_timeout */
#define ISSX7_IA_AGENT_CONTROL_BURST_TIMEOUT_POS 16
/*! Field BURST_TIMEOUT - burst_timeout */
#define ISSX7_IA_AGENT_CONTROL_BURST_TIMEOUT_MASK 0x70000u

/*! Field MERROR_REP - merror_rep */
#define ISSX7_IA_AGENT_CONTROL_MERROR_REP_POS 24
/*! Field MERROR_REP - merror_rep */
#define ISSX7_IA_AGENT_CONTROL_MERROR_REP_MASK 0x1000000u

/*! Field RESP_TIMEOUT_REP - resp_timeout_rep */
#define ISSX7_IA_AGENT_CONTROL_RESP_TIMEOUT_REP_POS 25
/*! Field RESP_TIMEOUT_REP - resp_timeout_rep */
#define ISSX7_IA_AGENT_CONTROL_RESP_TIMEOUT_REP_MASK 0x2000000u

/*! Field BURST_TIMEOUT_REP - burst_timeout_rep */
#define ISSX7_IA_AGENT_CONTROL_BURST_TIMEOUT_REP_POS 26
/*! Field BURST_TIMEOUT_REP - burst_timeout_rep */
#define ISSX7_IA_AGENT_CONTROL_BURST_TIMEOUT_REP_MASK 0x4000000u

/*! Field ALL_INBAND_ERROR_REP - all_inband_error_rep */
#define ISSX7_IA_AGENT_CONTROL_ALL_INBAND_ERROR_REP_POS 27
/*! Field ALL_INBAND_ERROR_REP - all_inband_error_rep */
#define ISSX7_IA_AGENT_CONTROL_ALL_INBAND_ERROR_REP_MASK 0x8000000u

/*! Field INBAND_ERROR_PRIMARY_REP - inband_error_primary_rep */
#define ISSX7_IA_AGENT_CONTROL_INBAND_ERROR_PRIMARY_REP_POS 28
/*! Field INBAND_ERROR_PRIMARY_REP - inband_error_primary_rep */
#define ISSX7_IA_AGENT_CONTROL_INBAND_ERROR_PRIMARY_REP_MASK 0x10000000u

/*! Field INBAND_ERROR_SECONDARY_REP - inband_error_secondary_rep */
#define ISSX7_IA_AGENT_CONTROL_INBAND_ERROR_SECONDARY_REP_POS 29
/*! Field INBAND_ERROR_SECONDARY_REP - inband_error_secondary_rep */
#define ISSX7_IA_AGENT_CONTROL_INBAND_ERROR_SECONDARY_REP_MASK 0x20000000u

/*! Field SECONDARY_REP_SHADOW - secondary_rep_shadow */
#define ISSX7_IA_AGENT_CONTROL_SECONDARY_REP_SHADOW_POS 30
/*! Field SECONDARY_REP_SHADOW - secondary_rep_shadow */
#define ISSX7_IA_AGENT_CONTROL_SECONDARY_REP_SHADOW_MASK 0x40000000u

/*! @} */

/*! \defgroup ISSX7_IA_AGENT_STATUS Register ISSX7_IA_AGENT_STATUS - agent_status */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_AGENT_STATUS 0x2428
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_AGENT_STATUS 0xA0002428u

/*! Register Reset Value */
#define ISSX7_IA_AGENT_STATUS_RST 0x0000000000000000u

/*! Field CORE_RESET - core_reset */
#define ISSX7_IA_AGENT_STATUS_CORE_RESET_POS 0
/*! Field CORE_RESET - core_reset */
#define ISSX7_IA_AGENT_STATUS_CORE_RESET_MASK 0x1u

/*! Field REQ_ACTIVE - req_active */
#define ISSX7_IA_AGENT_STATUS_REQ_ACTIVE_POS 4
/*! Field REQ_ACTIVE - req_active */
#define ISSX7_IA_AGENT_STATUS_REQ_ACTIVE_MASK 0x10u

/*! Field RESP_WAITING - resp_waiting */
#define ISSX7_IA_AGENT_STATUS_RESP_WAITING_POS 5
/*! Field RESP_WAITING - resp_waiting */
#define ISSX7_IA_AGENT_STATUS_RESP_WAITING_MASK 0x20u

/*! Field BURST - burst */
#define ISSX7_IA_AGENT_STATUS_BURST_POS 6
/*! Field BURST - burst */
#define ISSX7_IA_AGENT_STATUS_BURST_MASK 0x40u

/*! Field READEX - readex */
#define ISSX7_IA_AGENT_STATUS_READEX_POS 7
/*! Field READEX - readex */
#define ISSX7_IA_AGENT_STATUS_READEX_MASK 0x80u

/*! Field RESP_TIMEOUT - resp_timeout */
#define ISSX7_IA_AGENT_STATUS_RESP_TIMEOUT_POS 8
/*! Field RESP_TIMEOUT - resp_timeout */
#define ISSX7_IA_AGENT_STATUS_RESP_TIMEOUT_MASK 0x100u

/*! Field TIMEBASE - timebase */
#define ISSX7_IA_AGENT_STATUS_TIMEBASE_POS 12
/*! Field TIMEBASE - timebase */
#define ISSX7_IA_AGENT_STATUS_TIMEBASE_MASK 0xF000u

/*! Field BURST_TIMEOUT - burst_timeout */
#define ISSX7_IA_AGENT_STATUS_BURST_TIMEOUT_POS 16
/*! Field BURST_TIMEOUT - burst_timeout */
#define ISSX7_IA_AGENT_STATUS_BURST_TIMEOUT_MASK 0x10000u

/*! Field MERROR - merror */
#define ISSX7_IA_AGENT_STATUS_MERROR_POS 24
/*! Field MERROR - merror */
#define ISSX7_IA_AGENT_STATUS_MERROR_MASK 0x1000000u

/*! Field INBAND_ERROR_PRIMARY - inband_error_primary */
#define ISSX7_IA_AGENT_STATUS_INBAND_ERROR_PRIMARY_POS 28
/*! Field INBAND_ERROR_PRIMARY - inband_error_primary */
#define ISSX7_IA_AGENT_STATUS_INBAND_ERROR_PRIMARY_MASK 0x10000000u

/*! Field INBAND_ERROR_SECONDARY - inband_error_secondary */
#define ISSX7_IA_AGENT_STATUS_INBAND_ERROR_SECONDARY_POS 29
/*! Field INBAND_ERROR_SECONDARY - inband_error_secondary */
#define ISSX7_IA_AGENT_STATUS_INBAND_ERROR_SECONDARY_MASK 0x20000000u

/*! @} */

/*! \defgroup ISSX7_IA_ERROR_LOG Register ISSX7_IA_ERROR_LOG - error_log */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_ERROR_LOG 0x2458
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_ERROR_LOG 0xA0002458u

/*! Register Reset Value */
#define ISSX7_IA_ERROR_LOG_RST 0x0000000000000000u

/*! Field CMD - cmd */
#define ISSX7_IA_ERROR_LOG_CMD_POS 0
/*! Field CMD - cmd */
#define ISSX7_IA_ERROR_LOG_CMD_MASK 0x7u

/*! Field INITID - initid */
#define ISSX7_IA_ERROR_LOG_INITID_POS 8
/*! Field INITID - initid */
#define ISSX7_IA_ERROR_LOG_INITID_MASK 0xFF00u

/*! Field RFU0 - rfu0 */
#define ISSX7_IA_ERROR_LOG_RFU0_POS 16
/*! Field RFU0 - rfu0 */
#define ISSX7_IA_ERROR_LOG_RFU0_MASK 0x30000u

/*! Field RFU1 - rfu1 */
#define ISSX7_IA_ERROR_LOG_RFU1_POS 18
/*! Field RFU1 - rfu1 */
#define ISSX7_IA_ERROR_LOG_RFU1_MASK 0xC0000u

/*! Field RFU2 - rfu2 */
#define ISSX7_IA_ERROR_LOG_RFU2_POS 20
/*! Field RFU2 - rfu2 */
#define ISSX7_IA_ERROR_LOG_RFU2_MASK 0xF00000u

/*! Field CODE - code */
#define ISSX7_IA_ERROR_LOG_CODE_POS 24
/*! Field CODE - code */
#define ISSX7_IA_ERROR_LOG_CODE_MASK 0xF000000u

/*! Field SECONDARY - secondary */
#define ISSX7_IA_ERROR_LOG_SECONDARY_POS 30
/*! Field SECONDARY - secondary */
#define ISSX7_IA_ERROR_LOG_SECONDARY_MASK 0x40000000u

/*! Field MULTI - multi */
#define ISSX7_IA_ERROR_LOG_MULTI_POS 31
/*! Field MULTI - multi */
#define ISSX7_IA_ERROR_LOG_MULTI_MASK 0x80000000u

/*! Field REQ_INFO - req_info */
#define ISSX7_IA_ERROR_LOG_REQ_INFO_POS 32
/*! Field REQ_INFO - req_info */
#define ISSX7_IA_ERROR_LOG_REQ_INFO_MASK 0xFFFFFFFF00000000u

/*! @} */

/*! \defgroup ISSX7_IA_ERROR_LOG_ADDR Register ISSX7_IA_ERROR_LOG_ADDR - error_log_addr */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_ERROR_LOG_ADDR 0x2460
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_ERROR_LOG_ADDR 0xA0002460u

/*! Register Reset Value */
#define ISSX7_IA_ERROR_LOG_ADDR_RST 0x0000000000000000u

/*! Field ADDR - addr */
#define ISSX7_IA_ERROR_LOG_ADDR_ADDR_POS 0
/*! Field ADDR - addr */
#define ISSX7_IA_ERROR_LOG_ADDR_ADDR_MASK 0xFFFFFFFFFFFFFFFFu

/*! @} */

/*! \defgroup ISSX7_IA_CORE_FLAG Register ISSX7_IA_CORE_FLAG - core_flag */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_CORE_FLAG 0x2468
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_CORE_FLAG 0xA0002468u

/*! Register Reset Value */
#define ISSX7_IA_CORE_FLAG_RST 0x0000000000000000u

/*! Field ENABLE_0 - enable_0 */
#define ISSX7_IA_CORE_FLAG_ENABLE_0_POS 0
/*! Field ENABLE_0 - enable_0 */
#define ISSX7_IA_CORE_FLAG_ENABLE_0_MASK 0x1u

/*! Field ENABLE_1 - enable_1 */
#define ISSX7_IA_CORE_FLAG_ENABLE_1_POS 1
/*! Field ENABLE_1 - enable_1 */
#define ISSX7_IA_CORE_FLAG_ENABLE_1_MASK 0x2u

/*! Field ENABLE_2 - enable_2 */
#define ISSX7_IA_CORE_FLAG_ENABLE_2_POS 2
/*! Field ENABLE_2 - enable_2 */
#define ISSX7_IA_CORE_FLAG_ENABLE_2_MASK 0x4u

/*! Field ENABLE_3 - enable_3 */
#define ISSX7_IA_CORE_FLAG_ENABLE_3_POS 3
/*! Field ENABLE_3 - enable_3 */
#define ISSX7_IA_CORE_FLAG_ENABLE_3_MASK 0x8u

/*! @} */

/*! \defgroup ISSX7_IA_ADDR_FILL_IN Register ISSX7_IA_ADDR_FILL_IN - addr_fill_in */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_ADDR_FILL_IN 0x2470
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_ADDR_FILL_IN 0xA0002470u

/*! Register Reset Value */
#define ISSX7_IA_ADDR_FILL_IN_RST 0x0000000000000000u

/*! Field VALUE - value */
#define ISSX7_IA_ADDR_FILL_IN_VALUE_POS 10
/*! Field VALUE - value */
#define ISSX7_IA_ADDR_FILL_IN_VALUE_MASK 0xFFFFFFFFFFFFFC00u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_0 Register ISSX7_IA_BANDWIDTH_0 - bandwidth_0 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_0 0x2500
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_0 0xA0002500u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_0_RST 0x0101010101010101u

/*! Field TARGET_GROUP_0 - target_group_0 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_0_POS 0
/*! Field TARGET_GROUP_0 - target_group_0 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_0_MASK 0xFFu

/*! Field TARGET_GROUP_1 - target_group_1 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_1_POS 8
/*! Field TARGET_GROUP_1 - target_group_1 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_1_MASK 0xFF00u

/*! Field TARGET_GROUP_2 - target_group_2 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_2_POS 16
/*! Field TARGET_GROUP_2 - target_group_2 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_2_MASK 0xFF0000u

/*! Field TARGET_GROUP_3 - target_group_3 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_3_POS 24
/*! Field TARGET_GROUP_3 - target_group_3 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_3_MASK 0xFF000000u

/*! Field TARGET_GROUP_4 - target_group_4 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_4_POS 32
/*! Field TARGET_GROUP_4 - target_group_4 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_4_MASK 0xFF00000000u

/*! Field TARGET_GROUP_5 - target_group_5 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_5_POS 40
/*! Field TARGET_GROUP_5 - target_group_5 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_5_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_6 - target_group_6 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_6_POS 48
/*! Field TARGET_GROUP_6 - target_group_6 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_6_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_7 - target_group_7 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_7_POS 56
/*! Field TARGET_GROUP_7 - target_group_7 */
#define ISSX7_IA_BANDWIDTH_0_TARGET_GROUP_7_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_1 Register ISSX7_IA_BANDWIDTH_1 - bandwidth_1 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_1 0x2508
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_1 0xA0002508u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_1_RST 0x0101010101010101u

/*! Field TARGET_GROUP_8 - target_group_8 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_8_POS 0
/*! Field TARGET_GROUP_8 - target_group_8 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_8_MASK 0xFFu

/*! Field TARGET_GROUP_9 - target_group_9 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_9_POS 8
/*! Field TARGET_GROUP_9 - target_group_9 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_9_MASK 0xFF00u

/*! Field TARGET_GROUP_10 - target_group_10 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_10_POS 16
/*! Field TARGET_GROUP_10 - target_group_10 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_10_MASK 0xFF0000u

/*! Field TARGET_GROUP_11 - target_group_11 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_11_POS 24
/*! Field TARGET_GROUP_11 - target_group_11 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_11_MASK 0xFF000000u

/*! Field TARGET_GROUP_12 - target_group_12 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_12_POS 32
/*! Field TARGET_GROUP_12 - target_group_12 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_12_MASK 0xFF00000000u

/*! Field TARGET_GROUP_13 - target_group_13 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_13_POS 40
/*! Field TARGET_GROUP_13 - target_group_13 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_13_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_14 - target_group_14 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_14_POS 48
/*! Field TARGET_GROUP_14 - target_group_14 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_14_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_15 - target_group_15 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_15_POS 56
/*! Field TARGET_GROUP_15 - target_group_15 */
#define ISSX7_IA_BANDWIDTH_1_TARGET_GROUP_15_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_2 Register ISSX7_IA_BANDWIDTH_2 - bandwidth_2 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_2 0x2510
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_2 0xA0002510u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_2_RST 0x0101010101010101u

/*! Field TARGET_GROUP_16 - target_group_16 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_16_POS 0
/*! Field TARGET_GROUP_16 - target_group_16 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_16_MASK 0xFFu

/*! Field TARGET_GROUP_17 - target_group_17 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_17_POS 8
/*! Field TARGET_GROUP_17 - target_group_17 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_17_MASK 0xFF00u

/*! Field TARGET_GROUP_18 - target_group_18 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_18_POS 16
/*! Field TARGET_GROUP_18 - target_group_18 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_18_MASK 0xFF0000u

/*! Field TARGET_GROUP_19 - target_group_19 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_19_POS 24
/*! Field TARGET_GROUP_19 - target_group_19 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_19_MASK 0xFF000000u

/*! Field TARGET_GROUP_20 - target_group_20 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_20_POS 32
/*! Field TARGET_GROUP_20 - target_group_20 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_20_MASK 0xFF00000000u

/*! Field TARGET_GROUP_21 - target_group_21 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_21_POS 40
/*! Field TARGET_GROUP_21 - target_group_21 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_21_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_22 - target_group_22 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_22_POS 48
/*! Field TARGET_GROUP_22 - target_group_22 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_22_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_23 - target_group_23 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_23_POS 56
/*! Field TARGET_GROUP_23 - target_group_23 */
#define ISSX7_IA_BANDWIDTH_2_TARGET_GROUP_23_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_3 Register ISSX7_IA_BANDWIDTH_3 - bandwidth_3 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_3 0x2518
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_3 0xA0002518u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_3_RST 0x0101010101010101u

/*! Field TARGET_GROUP_24 - target_group_24 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_24_POS 0
/*! Field TARGET_GROUP_24 - target_group_24 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_24_MASK 0xFFu

/*! Field TARGET_GROUP_25 - target_group_25 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_25_POS 8
/*! Field TARGET_GROUP_25 - target_group_25 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_25_MASK 0xFF00u

/*! Field TARGET_GROUP_26 - target_group_26 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_26_POS 16
/*! Field TARGET_GROUP_26 - target_group_26 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_26_MASK 0xFF0000u

/*! Field TARGET_GROUP_27 - target_group_27 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_27_POS 24
/*! Field TARGET_GROUP_27 - target_group_27 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_27_MASK 0xFF000000u

/*! Field TARGET_GROUP_28 - target_group_28 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_28_POS 32
/*! Field TARGET_GROUP_28 - target_group_28 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_28_MASK 0xFF00000000u

/*! Field TARGET_GROUP_29 - target_group_29 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_29_POS 40
/*! Field TARGET_GROUP_29 - target_group_29 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_29_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_30 - target_group_30 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_30_POS 48
/*! Field TARGET_GROUP_30 - target_group_30 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_30_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_31 - target_group_31 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_31_POS 56
/*! Field TARGET_GROUP_31 - target_group_31 */
#define ISSX7_IA_BANDWIDTH_3_TARGET_GROUP_31_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_4 Register ISSX7_IA_BANDWIDTH_4 - bandwidth_4 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_4 0x2520
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_4 0xA0002520u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_4_RST 0x0101010101010101u

/*! Field TARGET_GROUP_32 - target_group_32 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_32_POS 0
/*! Field TARGET_GROUP_32 - target_group_32 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_32_MASK 0xFFu

/*! Field TARGET_GROUP_33 - target_group_33 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_33_POS 8
/*! Field TARGET_GROUP_33 - target_group_33 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_33_MASK 0xFF00u

/*! Field TARGET_GROUP_34 - target_group_34 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_34_POS 16
/*! Field TARGET_GROUP_34 - target_group_34 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_34_MASK 0xFF0000u

/*! Field TARGET_GROUP_35 - target_group_35 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_35_POS 24
/*! Field TARGET_GROUP_35 - target_group_35 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_35_MASK 0xFF000000u

/*! Field TARGET_GROUP_36 - target_group_36 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_36_POS 32
/*! Field TARGET_GROUP_36 - target_group_36 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_36_MASK 0xFF00000000u

/*! Field TARGET_GROUP_37 - target_group_37 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_37_POS 40
/*! Field TARGET_GROUP_37 - target_group_37 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_37_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_38 - target_group_38 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_38_POS 48
/*! Field TARGET_GROUP_38 - target_group_38 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_38_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_39 - target_group_39 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_39_POS 56
/*! Field TARGET_GROUP_39 - target_group_39 */
#define ISSX7_IA_BANDWIDTH_4_TARGET_GROUP_39_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_5 Register ISSX7_IA_BANDWIDTH_5 - bandwidth_5 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_5 0x2528
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_5 0xA0002528u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_5_RST 0x0101010101010101u

/*! Field TARGET_GROUP_40 - target_group_40 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_40_POS 0
/*! Field TARGET_GROUP_40 - target_group_40 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_40_MASK 0xFFu

/*! Field TARGET_GROUP_41 - target_group_41 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_41_POS 8
/*! Field TARGET_GROUP_41 - target_group_41 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_41_MASK 0xFF00u

/*! Field TARGET_GROUP_42 - target_group_42 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_42_POS 16
/*! Field TARGET_GROUP_42 - target_group_42 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_42_MASK 0xFF0000u

/*! Field TARGET_GROUP_43 - target_group_43 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_43_POS 24
/*! Field TARGET_GROUP_43 - target_group_43 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_43_MASK 0xFF000000u

/*! Field TARGET_GROUP_44 - target_group_44 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_44_POS 32
/*! Field TARGET_GROUP_44 - target_group_44 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_44_MASK 0xFF00000000u

/*! Field TARGET_GROUP_45 - target_group_45 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_45_POS 40
/*! Field TARGET_GROUP_45 - target_group_45 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_45_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_46 - target_group_46 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_46_POS 48
/*! Field TARGET_GROUP_46 - target_group_46 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_46_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_47 - target_group_47 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_47_POS 56
/*! Field TARGET_GROUP_47 - target_group_47 */
#define ISSX7_IA_BANDWIDTH_5_TARGET_GROUP_47_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_6 Register ISSX7_IA_BANDWIDTH_6 - bandwidth_6 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_6 0x2530
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_6 0xA0002530u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_6_RST 0x0101010101010101u

/*! Field TARGET_GROUP_48 - target_group_48 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_48_POS 0
/*! Field TARGET_GROUP_48 - target_group_48 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_48_MASK 0xFFu

/*! Field TARGET_GROUP_49 - target_group_49 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_49_POS 8
/*! Field TARGET_GROUP_49 - target_group_49 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_49_MASK 0xFF00u

/*! Field TARGET_GROUP_50 - target_group_50 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_50_POS 16
/*! Field TARGET_GROUP_50 - target_group_50 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_50_MASK 0xFF0000u

/*! Field TARGET_GROUP_51 - target_group_51 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_51_POS 24
/*! Field TARGET_GROUP_51 - target_group_51 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_51_MASK 0xFF000000u

/*! Field TARGET_GROUP_52 - target_group_52 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_52_POS 32
/*! Field TARGET_GROUP_52 - target_group_52 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_52_MASK 0xFF00000000u

/*! Field TARGET_GROUP_53 - target_group_53 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_53_POS 40
/*! Field TARGET_GROUP_53 - target_group_53 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_53_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_54 - target_group_54 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_54_POS 48
/*! Field TARGET_GROUP_54 - target_group_54 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_54_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_55 - target_group_55 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_55_POS 56
/*! Field TARGET_GROUP_55 - target_group_55 */
#define ISSX7_IA_BANDWIDTH_6_TARGET_GROUP_55_MASK 0xFF00000000000000u

/*! @} */

/*! \defgroup ISSX7_IA_BANDWIDTH_7 Register ISSX7_IA_BANDWIDTH_7 - bandwidth_7 */
/*! @{ */

/*! Register Offset (relative) */
#define ISSX7_IA_BANDWIDTH_7 0x2538
/*! Register Offset (absolute) for 1st Instance SSX8_SSX */
#define SSX8_SSX_ISSX7_IA_BANDWIDTH_7 0xA0002538u

/*! Register Reset Value */
#define ISSX7_IA_BANDWIDTH_7_RST 0x0101010101010101u

/*! Field TARGET_GROUP_56 - target_group_56 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_56_POS 0
/*! Field TARGET_GROUP_56 - target_group_56 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_56_MASK 0xFFu

/*! Field TARGET_GROUP_57 - target_group_57 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_57_POS 8
/*! Field TARGET_GROUP_57 - target_group_57 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_57_MASK 0xFF00u

/*! Field TARGET_GROUP_58 - target_group_58 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_58_POS 16
/*! Field TARGET_GROUP_58 - target_group_58 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_58_MASK 0xFF0000u

/*! Field TARGET_GROUP_59 - target_group_59 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_59_POS 24
/*! Field TARGET_GROUP_59 - target_group_59 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_59_MASK 0xFF000000u

/*! Field TARGET_GROUP_60 - target_group_60 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_60_POS 32
/*! Field TARGET_GROUP_60 - target_group_60 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_60_MASK 0xFF00000000u

/*! Field TARGET_GROUP_61 - target_group_61 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_61_POS 40
/*! Field TARGET_GROUP_61 - target_group_61 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_61_MASK 0xFF0000000000u

/*! Field TARGET_GROUP_62 - target_group_62 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_62_POS 48
/*! Field TARGET_GROUP_62 - target_group_62 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_62_MASK 0xFF000000000000u

/*! Field TARGET_GROUP_63 - target_group_63 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_63_POS 56
/*! Field TARGET_GROUP_63 - target_group_63 */
#define ISSX7_IA_BANDWIDTH_7_TARGET_GROUP_63_MASK 0xFF00000000000000u

/*! @} */

/*! @} */

#endif
