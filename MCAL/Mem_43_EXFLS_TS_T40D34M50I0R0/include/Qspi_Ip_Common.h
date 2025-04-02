/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
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

#ifndef QSPI_IP_COMMON_H
#define QSPI_IP_COMMON_H

/**
*   @file Qspi_Ip_Common.h
*
*   @addtogroup IPV_QSPI
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_COMMON_VENDOR_ID_H                       43
#define QSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H        4
#define QSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H        7
#define QSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H     0
#define QSPI_IP_COMMON_SW_MAJOR_VERSION_H                5
#define QSPI_IP_COMMON_SW_MINOR_VERSION_H                0
#define QSPI_IP_COMMON_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/


/*******************************************************************************
* Definitions
******************************************************************************/

/*!
 * @brief Driver configuration structure
 *
 * This structure is used to provide configuration parameters for the external flash driver
 * at initialization time.
 */
typedef struct
{
    const Qspi_Ip_MemoryConfigType *configuration;      /*!< Serial flash device configuration                */
    const Qspi_Ip_MemoryConnectionType *connection;     /*!< Connection to a QSPI device                      */
    uint32 baseAddress;                                 /*!< Base address of serial flash device              */
    Qspi_Ip_LastCommandType lastCommand;                /*!< Last command sent to the flash device            */
    uint16 activeReadLut;                               /*!< LUT number for currently active read mode        */
    uint16 activeWriteLut;                              /*!< LUT number for currently active write mode       */
} Qspi_Ip_StateType;


/*******************************************************************************
 * External variable declarations.
 ******************************************************************************/

 /* Physical LUT seq to use for all flash commands */
#define QSPI_IP_COMMAND_LUT 0U

 /* Physical LUT seq to use for AHB reads */
#define QSPI_IP_AHB_LUT 1U

 /* Physical LUT seq to use for AHB write */
#define QSPI_IP_AHB_WRITE_LUT 2U

#define MEM_43_EXFLS_START_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Table of AHB addresses for QuadSPI instances. */
extern const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT];

#define MEM_43_EXFLS_STOP_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/*When multicore type3 is enabled on MemAcc, global variables must be allocated to share memory section */
#if (QSPI_IP_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"

/* Pointer to runtime state structures */
extern Qspi_Ip_StateType Qspi_Ip_MemoryStateStructure[];

#if (QSPI_IP_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"

/*******************************************************************************
 * API
 ******************************************************************************/

#endif /* QSPI_IP_MEM_INSTANCE_COUNT */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_COMMON_H */

