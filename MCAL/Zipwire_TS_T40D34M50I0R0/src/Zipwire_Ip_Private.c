/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
/**
*   @file       Zipwire_Ip_Private.c
*   @version    5.0.0
*
*   @brief
*   @brief   ZIPWIRE IP driver implementations.
*   @details ZIPWIRE IP driver implementations.
*
*   @addtogroup ZIPWIRE_IP_DRIVER
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Zipwire_Ip.h"
#include "Zipwire_Ip_Private.h"
#include "OsIf.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_IP_PRIVATE_VENDOR_ID_C                   43
#define ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C    4
#define ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C    7
#define ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C 0
#define ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION_C            5
#define ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION_C            0
#define ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION_C            0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and OsIf header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Power_Ip_Private.c and OsIf.h are different"
#endif
#endif

/* Check if current file and Power_Ip header file are of the same Autosar version */
#if (ZIPWIRE_IP_PRIVATE_VENDOR_ID_C != ZIPWIRE_IP_VENDOR_ID)
#error "Power_Ip_Private.c and Power_Ip.h have different vendor ids"
#endif
/* Check if current file and Power_Ip header file are of the same Autosar version */
#if ((ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Power_Ip_Private.c and Power_Ip.h are different"
#endif
/* Check if current file and Power_Ip header file are of the same Software version */
#if ((ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION_C != ZIPWIRE_IP_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION_C != ZIPWIRE_IP_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION_C != ZIPWIRE_IP_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Power_Ip_Private.c and Power_Ip.h are different"
#endif

/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if (ZIPWIRE_IP_PRIVATE_VENDOR_ID_C != ZIPWIRE_IP_PRIVATE_VENDOR_ID)
#error "Power_Ip_Private.c and Power_Ip_Private.h have different vendor ids"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if ((ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Power_Ip_Private.c and Power_Ip_Private.h are different"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Software version */
#if ((ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION_C != ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION_C != ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION_C != ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Power_Ip_Private.c and Power_Ip_Private.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

/**
* @brief         Zipwire_Ip_StartTimeout
*
*/
void Zipwire_Ip_StartTimeout(uint32 * StartTimeOut,
                             uint32 * ElapsedTimeOut,
                             uint32 * TimeoutTicksOut,
                             uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(ZIPWIRE_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, ZIPWIRE_IP_TIMEOUT_TYPE);
}

/**
* @brief         Zipwire_Ip_TimeoutExpired
*
*/
boolean Zipwire_Ip_TimeoutExpired(uint32 * startTimeInOut,
                                  uint32 * elapsedTimeInOut,
                                  uint32 TimeoutTicks)
{
    boolean Status = FALSE;
    *elapsedTimeInOut += OsIf_GetElapsed(startTimeInOut, ZIPWIRE_IP_TIMEOUT_TYPE);

    if (*elapsedTimeInOut >= TimeoutTicks)
    {
        Status = TRUE;
    }

    return Status;
}

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
