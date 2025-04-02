/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
*   Dependencies         : 
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
/*==================================================================================================
==================================================================================================*/
#ifndef CANTRCV_43_AE_IPW_H
#define CANTRCV_43_AE_IPW_H

/**
* @file         CanTrcv_43_AE_Ipw.h
*
* @addtogroup   CANTRCV_43_AE_DRIVER Can Transceiver Driver
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Can_GeneralTypes.h"
#include "CanTrcv_43_AE_Types.h"
#include "CanTrcv_43_AE_Ipw_Cfg.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_IPW_VENDOR_ID                    43
#define CANTRCV_43_AE_IPW_MODULE_ID                    70
#define CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION     7
#define CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION  0
#define CANTRCV_43_AE_IPW_SW_MAJOR_VERSION             5
#define CANTRCV_43_AE_IPW_SW_MINOR_VERSION             0
#define CANTRCV_43_AE_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Types.h header file are of the same vendor */
#if (CANTRCV_43_AE_IPW_VENDOR_ID != CANTRCV_43_AE_TYPES_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Types.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Types.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Types.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Types.h header file are of the same software version */
#if ((CANTRCV_43_AE_IPW_SW_MAJOR_VERSION != CANTRCV_43_AE_TYPES_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_MINOR_VERSION != CANTRCV_43_AE_TYPES_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_PATCH_VERSION != CANTRCV_43_AE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Types.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Ipw_Cfg.h header file are of the same vendor */
#if (CANTRCV_43_AE_IPW_VENDOR_ID != CANTRCV_43_AE_IPW_CFG_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Ipw_Cfg.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Ipw_Cfg.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Ipw_Cfg.h header file are of the same software version */
#if ((CANTRCV_43_AE_IPW_SW_MAJOR_VERSION != CANTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_MINOR_VERSION != CANTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_PATCH_VERSION != CANTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw.h and CanTrcv_43_AE_Ipw_Cfg.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if CanTrcv_43_AE_Ipw.h and Std_Types.h are of the same software version */
    #if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw.h and Std_Types.h are different"
    #endif

    /* Check if CanTrcv_43_AE_Ipw.h and Can_GeneralTypes.h are of the same software version */
    #if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw.h and Can_GeneralTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

/* Import external structure defined by IPW */
CANTRCV_43_AE_IPW_EXT

#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

CanTrcv_TrcvModeType CanTrcv_43_AE_GetTrcvSwMode(uint8 Transceiver);

/* Ipw_Init */
Std_ReturnType CanTrcv_43_AE_Ipw_Init(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig);

/* Ipw_SetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                         CanTrcv_TrcvModeType OpMode
                                                        );

/* Ipw_GetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_GetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                         CanTrcv_TrcvModeType* OpMode
                                                        );

/* Ipw_GetBusWuReason */
Std_ReturnType CanTrcv_43_AE_Ipw_GetBusWuReason(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                              CanTrcv_TrcvWakeupReasonType * Reason
                                                             );

/* Ipw_SetWakeupMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetWakeupMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                             CanTrcv_TrcvWakeupModeType TrcvWakeupMode
                                                            );

/* Ipw_CheckWakeupFlag */
Std_ReturnType CanTrcv_43_AE_Ipw_CheckWakeupFlag(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig);

/* Ipw_CheckWakeup */
Std_ReturnType CanTrcv_43_AE_Ipw_CheckWakeup(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig);

#if ((CANTRCV_43_AE_BUSERR_EN == STD_ON) && (CANTRCV_43_AE_DEM_USED == STD_ON))
/* Ipw_CheckBusError */
void CanTrcv_43_AE_Ipw_CheckBusError(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig);
#endif /* ((CANTRCV_43_AE_BUSERR_EN == STD_ON) && (CANTRCV_43_AE_DEM_USED == STD_ON)) */

/* Ipw_DeInit */
Std_ReturnType CanTrcv_43_AE_Ipw_DeInit(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig);


#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANTRCV_43_AE_IPW_H */
