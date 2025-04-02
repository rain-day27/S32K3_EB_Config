/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : MEM_OTP_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef MEM_OTP_IP_DEFINES_H
#define MEM_OTP_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup MEM_OTP_IP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_OTP_IP_DEFINES_VENDOR_ID                    43
#define MEM_OTP_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define MEM_OTP_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define MEM_OTP_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define MEM_OTP_IP_DEFINES_SW_MAJOR_VERSION             5
#define MEM_OTP_IP_DEFINES_SW_MINOR_VERSION             0
#define MEM_OTP_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/* Base address of MODE_CONTROL register of AEC module */
#define AEC_MODE_CONTROL                    0x04
/* Base address of RSTGEN_CFG register of AEC module */
#define AEC_RSTGEN_CFG                      0x44

/* Value passed MODE CONTROL to enable access to test registers  */
#define AEC_MODE_CONTROL_SECRET_0           0x455CU
#define AEC_MODE_CONTROL_SECRET_1           0xE80CU
#define AEC_MODE_CONTROL_DISABLE_TEST_MODE  0x0U
/* Set regs_otp bit to activate OTP */
#define AEC_RSTGEN_CFG_ACTIVATE_REGS_OTP    0x01U

/* Base address of Mem_Otp_Ip_Ae registers */
#define MEM_OTP_AE_CTRL_CMD         0x120
#define MEM_OTP_AE_STRT_STP         0x122
#define MEM_OTP_AE_DATAOUT          0x128
#define MEM_OTP_AE_ERROR            0x13C
#define MEM_OTP_AE_ADVCFG0          0x12C
#define MEM_OTP_AE_ADVCFG3          0x132
#define MEM_OTP_AE_MREF_TST         0x138
#define MEM_OTP_AE_MR_TST           0x13A

/* Config parameters such as VRR Regulator Level, Read Pulse to read OTP memory */
#define MEM_OTP_IP_DATAWIDTH_16        16U
#define MEM_OTP_IP_NO_MR_DURING_TEST   0x38C2
#define MEM_OTP_IP_NO_MREF_DURING_TEST 0x8400
#define MEM_OTP_IP_SELECT_VRR_FOR_VDR  0x0880
#define MEM_OTP_IP_READ_PULSE_3000NS   0x0D00

/* OTP commands: Programming information */
#define OTPC_C_RD_ONE               0x0B

#define OTPC_ERR_FLAGS_MASK         (MEM_OTP_AE_ERROR_CTRLERR_MASK | \
                                     MEM_OTP_AE_ERROR_ECC2ERR_MASK | \
                                     MEM_OTP_AE_ERROR_ECC1ERR_MASK | \
                                     MEM_OTP_AE_ERROR_BOOTERR_MASK)

#define OTPC_ERR_ECC_MASK           (MEM_OTP_AE_ERROR_ECC2ERR_MASK | \
                                     MEM_OTP_AE_ERROR_ECC1ERR_MASK)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_OTP_IP_DEFINES_H */
