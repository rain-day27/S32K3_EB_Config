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

#ifndef AECANPHY_IP_H
#define AECANPHY_IP_H

/**
*   @file Aecanphy_Ip.h
*
*   @addtogroup
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
#include "Std_Types.h"
#include "Aecanphy_Ip_Cfg.h"
#include "Aecanphy_Ip_Types.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AECANPHY_IP_VENDOR_ID                    43
#define AECANPHY_IP_AR_RELEASE_MAJOR_VERSION     4
#define AECANPHY_IP_AR_RELEASE_MINOR_VERSION     7
#define AECANPHY_IP_AR_RELEASE_REVISION_VERSION  0
#define AECANPHY_IP_SW_MAJOR_VERSION             5
#define AECANPHY_IP_SW_MINOR_VERSION             0
#define AECANPHY_IP_SW_PATCH_VERSION             0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Aecanphy_Ip.h and Aecanphy_Ip_Cfg.h header file are of the same vendor */
#if (AECANPHY_IP_VENDOR_ID != AECANPHY_IP_CFG_VENDOR_ID)
    #error "Aecanphy_Ip.h and Aecanphy_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Aecanphy_Ip.h and Aecanphy_Ip_Cfg.h header file are of the same Autosar version */
#if ((AECANPHY_IP_AR_RELEASE_MAJOR_VERSION != AECANPHY_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_MINOR_VERSION != AECANPHY_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_REVISION_VERSION != AECANPHY_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Aecanphy_Ip.h and Aecanphy_Ip_Cfg.h are different"
#endif

/* Check if Aecanphy_Ip.h and Aecanphy_Ip_Cfg.h header file are of the same software version */
#if ((AECANPHY_IP_SW_MAJOR_VERSION != AECANPHY_IP_CFG_SW_MAJOR_VERSION) || \
     (AECANPHY_IP_SW_MINOR_VERSION != AECANPHY_IP_CFG_SW_MINOR_VERSION) || \
     (AECANPHY_IP_SW_PATCH_VERSION != AECANPHY_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aecanphy_Ip.h and Aecanphy_Ip_Cfg.h are different"
#endif

/* Check if Aecanphy_Ip.h and Aecanphy_Ip_Types.h header file are of the same vendor */
#if (AECANPHY_IP_VENDOR_ID != AECANPHY_IP_TYPES_VENDOR_ID)
    #error "Aecanphy_Ip.h and Aecanphy_Ip_Types.h have different vendor ids"
#endif
/* Check if Aecanphy_Ip.h and Aecanphy_Ip_Types.h header file are of the same Autosar version */
#if ((AECANPHY_IP_AR_RELEASE_MAJOR_VERSION != AECANPHY_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_MINOR_VERSION != AECANPHY_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_REVISION_VERSION != AECANPHY_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Aecanphy_Ip.h and Aecanphy_Ip_Types.h are different"
#endif

/* Check if Aecanphy_Ip.h and Aecanphy_Ip_Types.h header file are of the same software version */
#if ((AECANPHY_IP_SW_MAJOR_VERSION != AECANPHY_IP_TYPES_SW_MAJOR_VERSION) || \
     (AECANPHY_IP_SW_MINOR_VERSION != AECANPHY_IP_TYPES_SW_MINOR_VERSION) || \
     (AECANPHY_IP_SW_PATCH_VERSION != AECANPHY_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aecanphy_Ip.h and Aecanphy_Ip_Types.h are different"
#endif

/* Check if Aecanphy_Ip.h and Std_Types.h are of the same software version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((AECANPHY_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (AECANPHY_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of Aecanphy_Ip.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG                            (0x00000001U)
#define AE_CANPHY_CANPHY_MONITOR_REG_INVALID_STATE_LIVE_STATUS                   (0x00000040U)
#define AE_CANPHY_CANPHY_MONITOR_REG_TXDOM_TIMEDOUT_LIVE_STATUS                  (0x00000020U)
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

AECANPHY_IP_CONFIG_EXT

#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

/**
* @brief        Initialize state pointer and puts the device in OFFLINE mode.
* @details      Initialize state pointer and puts the device in OFFLINE mode.
*
* @param[in]    HwChannel         Index of the transceiver.
* @param[in]    Config            configuration pointer.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_Init(uint8 HwChannel,
                                        const Aecanphy_Ip_ConfigType * Config
                                       );

/**
* @brief        Puts the device in OFFLINE, NORMAL or LISTEN_ONLY modes.
* @details      Puts the device in OFFLINE, NORMAL or LISTEN_ONLY modes.
*
* @param[in]    HwChannel         Index of the transceiver.
* @param[in]    Mode              expected mode.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_SetMode(uint8 HwChannel,
                                           Aecanphy_Ip_TransceiverModeType Mode
                                          );

/**
* @brief        Gets the device mode.
* @details      Gets the device mode.
*
* @param[in]    HwChannel         Index of the transceiver.
* @param[out]   Mode              actual mode.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_GetMode(uint8 HwChannel,
                                           Aecanphy_Ip_TransceiverModeType * Mode
                                          );

/**
* @brief        Gets device's event flags.
* @details      Gets device's event flags which are Wakeup, Invalid state, Tx-dominant timeout flags
*
* @param[in]    HwChannel         Index of the transceiver.
* @param[out]   Event             All event flags.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_GetEventStatusFlag(uint8 HwChannel,
                                                      uint32 * Event
                                                     );

/**
* @brief        Gets device's live status flags.
* @details      Gets device's live status flags which are Wakeup, Invalid state, Tx-dominant timeout flags
*
* @param[in]    HwChannel         Index of the transceiver.
* @param[out]   Event             All live status flags.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_GetLiveStatusFlag(uint8 HwChannel,
                                                     uint32 * Event
                                                    );

/**
* @brief        Clears a given event flag.
* @details      Clears a given event flag which are Wakeup, Invalid state, Tx-dominant timeout flags
*
* @param[in]    HwChannel         Index of the transceiver.
* @param[out]   Event             The given event flag.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_ClearEventStatusFlag(uint8 HwChannel,
                                                        Aecanphy_Ip_TransceiverEventType Event
                                                       );

/**
* @brief        Enable a given event notification.
* @details      Enable a given event notification, if coresponding flag is set, a notification will be sent to AEC
*               which raises a INTERRUPT signal on INTERRUPT_OUT pin of AEC.
*
* @param[in]    HwChannel         Index of the transceiver.
* @param[in]    Event             The given event notification.
* @param[in]    IsEnable          FALSE - disables given notificattion, TRUE - enables given notification.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_SetEventNotification(uint8 HwChannel,
                                                        Aecanphy_Ip_TransceiverEventType Event,
                                                        boolean IsEnable
                                                       );

/**
* @brief        Sets state pointer to NULL and set all CANPHY registers to default value.
* @details      Sets state pointer to NULL and set all CANPHY registers to default value.
*
* @param[in]    HwChannel         Index of the transceiver.
*
* @return       Aecanphy_Ip_StatusType      Result of the transition.
* @retval       AE_CANPHY_STATUS_SUCCESS    Operation executed successfully.
* @retval       AE_CANPHY_STATUS_ERR_SPI    Operation failed due to SPI errors.
*
*/
Aecanphy_Ip_StatusType Aecanphy_Ip_DeInit(uint8 HwChannel);

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AECANPHY_IP_H */
