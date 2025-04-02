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

#ifndef QSPI_IP_TRUSTEDFUNCTIONS_H
#define QSPI_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Qspi_Ip_TrustedFunctions.h
*
*   @addtogroup IPV_QSPI
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Qspi_Ip_Types.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        7
#define QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define QSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                5
#define QSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                0
#define QSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Types header file are of the same vendor */
#if (QSPI_IP_TYPES_VENDOR_ID_CFG != QSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H)
    #error "Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Autosar version */
#if ((QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Types.h are different"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Software version */
#if ((QSPI_IP_TYPES_SW_MAJOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_TYPES_SW_MINOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_TYPES_SW_PATCH_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Types.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_CFG != QSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H)
    #error "Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_SW_MINOR_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_SW_PATCH_VERSION_CFG != QSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_TrustedFunctions.h and Qspi_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


#if (QSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)

extern void Qspi_Ip_Sfp_Configure_Privileged(QuadSPI_Type * baseAddr,
                                             Qspi_Ip_ControllerConfigType const * userConfigPtr
                                            );

extern void Qspi_Ip_Sfp_ClearLatchedErrors_Privileged(QuadSPI_Type * BaseAddr);

extern void Qspi_Ip_ResetPrivilegedRegisters_Privileged(QuadSPI_Type * BaseAddr);

extern void Qspi_Ip_WriteLuts_Privileged(uint32 Instance,
                                         uint8 StartLutRegister,
                                         const uint32 *Data,
                                         uint8 Size
                                        );

extern void Qspi_Ip_SetAhbSeqId_Privileged(uint32 instance, uint8 seqID);

#endif /* QSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON */


#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_TRUSTEDFUNCTIONS_H */

