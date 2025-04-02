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

#ifndef ZIPWIRE_IP_PRIVATE_H
#define ZIPWIRE_IP_PRIVATE_H

/**
*   @file       Zipwire_Ip_Private.h
*   @version    5.0.0
*
*   @brief      AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @defgroup   ZIPWIRE_IP_DRIVER ZIPWIRE IPL Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Zipwire_Ip_Types.h"
#include "Zipwire_Ip_Cfg.h"
#ifdef ZIPWIRE_IP_DEV_ERROR_DETECT
#if (STD_ON == ZIPWIRE_IP_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif /* (STD_ON == ZIPWIRE_IP_DEV_ERROR_DETECT) */
#endif /* #ifdef ZIPWIRE_IP_DEV_ERROR_DETECT */
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_IP_PRIVATE_VENDOR_ID                   43
#define ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION    4
#define ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION    7
#define ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION 0
#define ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION            5
#define ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION            0
#define ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION            0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Zipwire_Ip_Private.h file and Zipwire_Ip_Types.h file have same versions */
#if (ZIPWIRE_IP_PRIVATE_VENDOR_ID != ZIPWIRE_IP_TYPES_VENDOR_ID)
#error "Zipwire_Ip_Private.h and Zipwire_Ip_Types.h have different vendor IDs"
#endif

/* Check if Zipwire_Ip_Private.h file and Zipwire_Ip_Types.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip_Private.h and Zipwire_Ip_Types.h are different"
#endif

/* Check if Zipwire_Ip_Private.h file and Zipwire_Ip_Types.h file are of the same Software version */
#if ((ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION != ZIPWIRE_IP_TYPES_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION != ZIPWIRE_IP_TYPES_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION != ZIPWIRE_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Zipwire_Ip_Private.h and Zipwire_Ip_Types.h are different"
#endif

/* Check if Zipwire_Ip_Private.h file and Zipwire_Ip_Cfg.h file have same versions */
#if (ZIPWIRE_IP_PRIVATE_VENDOR_ID != ZIPWIRE_IP_CFG_VENDOR_ID)
#error "Zipwire_Ip_Private.h and Zipwire_Ip_Cfg.h have different vendor IDs"
#endif

/* Check if Zipwire_Ip_Private.h file and Zipwire_Ip_Cfg.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip_Private.h and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip_Private.h file and Zipwire_Ip_Cfg.h file are of the same Software version */
#if ((ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION != ZIPWIRE_IP_CFG_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION != ZIPWIRE_IP_CFG_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION != ZIPWIRE_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Zipwire_Ip_Private.h and Zipwire_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#ifdef ZIPWIRE_IP_DEV_ERROR_DETECT
#if (STD_ON == ZIPWIRE_IP_DEV_ERROR_DETECT)
/* Check if Zipwire_Ip_Private.h file and Devassert.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip_Private.h and Devassert.h are different"
#endif
#endif /* (STD_ON == ZIPWIRE_IP_DEV_ERROR_DETECT) */
#endif /* #ifdef ZIPWIRE_IP_DEV_ERROR_DETECT */
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"
/*!
 * @brief Initializes a starting reference point for timeout
 *
 * @param[out] StartTimeOut    The starting time from which elapsed time is measured
 * @param[out] ElapsedTimeOut  The elapsed time to be passed to Zipwire_Ip_TimeoutExpired
 * @param[out] TimeoutTicksOut The timeout value (in ticks) to be passed to Zipwire_Ip_TimeoutExpired
 * @param[in]  TimeoutUs       The timeout value (in microseconds)
 */
void Zipwire_Ip_StartTimeout(uint32 * StartTimeOut,
                             uint32 * ElapsedTimeOut,
                             uint32 * TimeoutTicksOut,
                             uint32 TimeoutUs);

/*!
 * @brief Checks for timeout condition.
 *
 * @param[in,out] StartTimeInOut    The starting time from which elapsed time is measured
 * @param[in,out] ElapsedTimeInOut  The accumulated elapsed time from the starting time reference
 * @param[in]     TimeoutTicks      The timeout limit (in ticks)
 */
boolean Zipwire_Ip_TimeoutExpired(uint32 * startTimeInOut,
                                  uint32 * elapsedTimeInOut,
                                  uint32 TimeoutTicks);


#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* ZIPWIRE_IP_PRIVATE_H */
