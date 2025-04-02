/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
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

#ifndef CDD_GDU_H
#define CDD_GDU_H

/**
*   @file    CDD_Gdu.h
*   @version 5.0.0
*
*   @brief   AUTOSAR Gdu - HLD main header file.
*   @details This is the only header file that the user modules need to include.
*
*   @addtogroup CDD_GDU
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
#include "Gdu_Ip.h"
#include "CDD_Gdu_Cfg.h"
#include "CDD_Gdu_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_VENDOR_ID                    43
#define GDU_MODULE_ID                    123
#define GDU_AR_RELEASE_MAJOR_VERSION     4
#define GDU_AR_RELEASE_MINOR_VERSION     7
#define GDU_AR_RELEASE_REVISION_VERSION  0
#define GDU_SW_MAJOR_VERSION             5
#define GDU_SW_MINOR_VERSION             0
#define GDU_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_VENDOR_ID != GDU_IP_VENDOR_ID)
    #error "CDD_Gdu.h and Gdu_Ip.h have different vendor ids"
#endif
#if ((GDU_AR_RELEASE_MAJOR_VERSION    != GDU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_AR_RELEASE_MINOR_VERSION    != GDU_IP_AR_RELEASE_MINOR_VERSION) || \
     (GDU_AR_RELEASE_REVISION_VERSION != GDU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Gdu.h and Gdu_Ip.h are different"
#endif
#if ((GDU_SW_MAJOR_VERSION != GDU_IP_SW_MAJOR_VERSION) || \
     (GDU_SW_MINOR_VERSION != GDU_IP_SW_MINOR_VERSION) || \
     (GDU_SW_PATCH_VERSION != GDU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Gdu.h and Gdu_Ip.h are different"
#endif

#if (GDU_VENDOR_ID != GDU_CFG_VENDOR_ID)
#error "CDD_Gdu.h and CDD_Gdu_Cfg.h have different vendor ids"
#endif
#if ((GDU_AR_RELEASE_MAJOR_VERSION    != GDU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_AR_RELEASE_MINOR_VERSION    != GDU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_AR_RELEASE_REVISION_VERSION != GDU_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Gdu.h and CDD_Gdu_Cfg.h are different"
#endif
#if ((GDU_SW_MAJOR_VERSION != GDU_CFG_SW_MAJOR_VERSION) || \
     (GDU_SW_MINOR_VERSION != GDU_CFG_SW_MINOR_VERSION) || \
     (GDU_SW_PATCH_VERSION != GDU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Gdu.h and CDD_Gdu_Cfg.h are different"
#endif

#if (GDU_VENDOR_ID != GDU_TYPES_VENDOR_ID)
#error "CDD_Gdu.h and CDD_Gdu_Types.h have different vendor ids"
#endif
#if ((GDU_AR_RELEASE_MAJOR_VERSION    != GDU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_AR_RELEASE_MINOR_VERSION    != GDU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GDU_AR_RELEASE_REVISION_VERSION != GDU_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Gdu.h and CDD_Gdu_Types.h are different"
#endif
#if ((GDU_SW_MAJOR_VERSION != GDU_TYPES_SW_MAJOR_VERSION) || \
     (GDU_SW_MINOR_VERSION != GDU_TYPES_SW_MINOR_VERSION) || \
     (GDU_SW_PATCH_VERSION != GDU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Gdu.h and CDD_Gdu_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** Enumerators defined to be used with Std_ReturnType (see SWS_Std_00011).
 *  Their meaning is detailed in the description of each API.
 *  Make sure to not use b7 and b6, as they are reserved by the RTE.
 */
#define GDU_RET_ERROR                       0x02    /**< Return status code  */
#define GDU_RET_DET_PARAM                   0x04    /**< Return status code  */
#define GDU_RET_DET_UNINIT                  0x05    /**< Return status code  */

/** Service IDs for Det error reporting */
#define GDU_DET_SERVICE_INITIALIZATION      1u      /**< Gdu_Init                    */
#define GDU_DET_SERVICE_SETMODE             2u      /**< Gdu_SetMode                 */
#define GDU_DET_SERVICE_SETSAFESTATE        3u      /**< Gdu_SetSafeState            */
#define GDU_DET_SERVICE_GETSTATUS           4u      /**< Gdu_GetStatus               */
#define GDU_DET_SERVICE_START_DELAYMEAS     5u      /**< Gdu_StartDelayMeasurement   */
#define GDU_DET_SERVICE_READ_DELAYMEAS      6u      /**< Gdu_ReadDelayMeasurement    */
#define GDU_DET_SERVICE_ADJUSTSLEWRATE      7u      /**< Gdu_AdjustSlewRate          */
#define GDU_DET_SERVICE_SWIREFTRIMMING      8u      /**< Gdu_SwIrefTrimming          */
#define GDU_DET_SERVICE_OFFSTATEDIAG        9u      /**< Gdu_OffStateDiagnostics     */
#if (GDU_VERSION_INFO_API == STD_ON)
#define GDU_DET_SERVICE_GETVERSIONINFO     10u      /**< Gdu_GetVersionInfo          */
#endif

/** Error codes for Det error reporting */
#define GDU_DET_ERROR_PARAMETER             1u      /**< The provided arguments are not valid. */
#define GDU_DET_ERROR_UNINITIALIZED         2u      /**< The operation cannot be performed while the driver is uninitialized. */

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (GDU_PRECOMPILE_SUPPORT == STD_ON)
#define GDU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

extern const Gdu_Ip_ConfigType * const Gdu_ConfigVariantPredefined[1];

#define GDU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

#else /* GDU_PRECOMPILE_SUPPORT */

#define GDU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"

GDU_CONFIG_EXT

#define GDU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gdu_MemMap.h"
#endif /* GDU_PRECOMPILE_SUPPORT == STD_ON */

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

Std_ReturnType Gdu_Init (const Gdu_Ip_ConfigType * Configuration);

Std_ReturnType Gdu_SetMode (Gdu_Ip_ModeType Mode);

Std_ReturnType Gdu_SetSafeState (Gdu_Ip_SafeStateType SafeState);

Std_ReturnType Gdu_GetStatus (Gdu_Ip_ErrorStatusType * ErrorStatus);

Std_ReturnType Gdu_StartDelayMeasurement
(
    Gdu_Ip_PwmChannelType PwmChannel,
    Gdu_Ip_EdgeType Edge
);

Std_ReturnType Gdu_ReadDelayMeasurement (uint8 * Delay);

Std_ReturnType Gdu_AdjustSlewRate
(
    Gdu_Ip_SlewRateSelectType SlewRateSelect,
    const Gdu_Ip_SlewRateConfigType * SlewRateConfig
);

Std_ReturnType Gdu_SwIrefTrimming (Gdu_Ip_IrefTrimmingType IrefTrimming);

Std_ReturnType Gdu_OffStateDiagnostics (Gdu_Ip_OffStateDiagType OffStateDiagnostics);

#if (GDU_VERSION_INFO_API == STD_ON)
Std_ReturnType Gdu_GetVersionInfo (Std_VersionInfoType * VersionInfo);
#endif

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_GDU_H */
