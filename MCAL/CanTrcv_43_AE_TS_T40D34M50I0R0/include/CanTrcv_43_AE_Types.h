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
#ifndef CANTRCV_43_AE_TYPYES_H
#define CANTRCV_43_AE_TYPYES_H

/**
* @file         CanTrcv_43_AE_Types.h
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
#include "CanTrcv_43_AE_Cfg.h"
#include "CanTrcv_43_AE_Ipw_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_TYPES_VENDOR_ID                    43
#define CANTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION     7
#define CANTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION  0
#define CANTRCV_43_AE_TYPES_SW_MAJOR_VERSION             5
#define CANTRCV_43_AE_TYPES_SW_MINOR_VERSION             0
#define CANTRCV_43_AE_TYPES_SW_PATCH_VERSION             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Cfg.h header file are of the same vendor */
#if (CANTRCV_43_AE_TYPES_VENDOR_ID != CANTRCV_43_AE_CFG_VENDOR_ID)
    #error "CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Cfg.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Cfg.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Cfg.h are different"
#endif

/* Check if CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Cfg.h header file are of the same software version */
#if ((CANTRCV_43_AE_TYPES_SW_MAJOR_VERSION != CANTRCV_43_AE_CFG_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_SW_MINOR_VERSION != CANTRCV_43_AE_CFG_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_SW_PATCH_VERSION != CANTRCV_43_AE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Cfg.h are different"
#endif

/* Check if CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Ipw_Types.h header file are of the same vendor */
#if (CANTRCV_43_AE_TYPES_VENDOR_ID != CANTRCV_43_AE_IPW_TYPES_VENDOR_ID)
    #error "CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Ipw_Types.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Ipw_Types.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Ipw_Types.h are different"
#endif

/* Check if CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Ipw_Types.h header file are of the same software version */
#if ((CANTRCV_43_AE_TYPES_SW_MAJOR_VERSION != CANTRCV_43_AE_IPW_TYPES_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_SW_MINOR_VERSION != CANTRCV_43_AE_IPW_TYPES_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_TYPES_SW_PATCH_VERSION != CANTRCV_43_AE_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Types.h and CanTrcv_43_AE_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if CanTrcv_43_AE_Types.h and Std_Types.h are of the same software version */
    #if ((CANTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Types.h and Std_Types.h are different"
    #endif

    /* Check if CanTrcv_43_AE_Types.h and Can_GeneralTypes.h are of the same software version */
    #if ((CANTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Types.h and Can_GeneralTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief CanTrcv_43_AE_TransceiverConfigType
*/
typedef struct
{
    /** @brief The Id of Transceiver channel configured by tool configuration */
    const uint8 CanTrcv_u8SwTransceiverId;
    /** @brief The Id of Transceiver channel mapped in Hardware */
    const uint8 CanTrcv_u8HwTransceiverId;
    /** @brief The Id referred by CanIf to CanTrcv */
    const uint8 CanTrcv_u8CanIfTransceiverId;
#if (CANTRCV_43_AE_ICU_USED == STD_ON)
    /** @brief The Icu channel referred by the transceiver. */
    const boolean CanTrcv_bIcuUsed;
    /** @brief The Icu channel referred by the transceiver. */
    const uint16 CanTrcv_u16IcuChnId;
#endif
#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
    /** @brief The value report to EcuM for a wakeup event. */
    const uint32 CanTrcv_WakeupSourceMask;
#endif
#if (CANTRCV_43_AE_DEM_USED == STD_ON)
    /** @brief The value report to Dem for a bus error. */
    const uint16 CanTrcv_DemEventId;
#endif
    /** @brief Specifies if wakeup is enabled on the transceiver */
    const boolean CanTrcv_bWakeupByBusUsed;
    /** @brief The mode of Transceiver after Init */
    const CanTrcv_TrcvModeType CanTrcv_eInitState;
    /** @brief Pointer to Ipw configuration wrapped to specific IPV configuration */
    const CanTrcv_43_AE_Ipw_TransceiverConfigType * const CanTrcv_IpwTransceiverConfig;
}CanTrcv_43_AE_TransceiverConfigType;
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANTRCV_43_AE_TYPYES_H */
