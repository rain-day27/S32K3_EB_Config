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

#ifndef AECANPHY_IP_TYPES_H
#define AECANPHY_IP_TYPES_H

/**
*   @file Aecanphy_Ip_Types.h
*
*   @addtogroup
*   @{
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
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AECANPHY_IP_TYPES_VENDOR_ID                    43
#define AECANPHY_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define AECANPHY_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define AECANPHY_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define AECANPHY_IP_TYPES_SW_MAJOR_VERSION             5
#define AECANPHY_IP_TYPES_SW_MINOR_VERSION             0
#define AECANPHY_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Aecanphy_Ip_Types.h and Std_Types.h are of the same software version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((AECANPHY_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (AECANPHY_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of Aecanphy_Ip_Types.h and Std_Types.h are different"
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
typedef enum
{
    /** @brief Offline mode. Wake-Up Pattern detection is enabled. */
    AE_CANPHY_OFFLINE_MODE          = 0U,
    /** @brief Normal mode. The full transceiver functionality is available. */
    AE_CANPHY_NORMAL_MODE               = 1U,
    /** @brief Listen only mode. The CAN transmitter is turned off. */
    AE_CANPHY_LISTEN_ONLY_MODE        = 3U
} Aecanphy_Ip_TransceiverModeType;

typedef enum
{
    /** @brief Listen only mode. The CAN transmitter is turned off. */
    AE_CANPHY_WKUP_EVENT                = 0U,
    /** @brief Offline mode. Wake-Up Pattern detection is enabled. */
    AE_CANPHY_INVALID_STATE_EVENT       = 1U,
    /** @brief Normal mode. The full transceiver functionality is available. */
    AE_CANPHY_TXDOM_TIMEDOUT_EVENT      = 2U
} Aecanphy_Ip_TransceiverEventType;

typedef enum
{
    /** @brief No error. */
    AE_CANPHY_STATUS_SUCCESS            = 0U,
    /** @brief General error, command failed to execute task successfully. */
    AE_CANPHY_STATUS_FAILED,
    /** @brief SPI communication error. */
    AE_CANPHY_STATUS_ERR_SPI,
} Aecanphy_Ip_StatusType;
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    /** @brief The Spi communication retries. */
    uint8 SpiCommRetries;
} Aecanphy_Ip_SpiConfigType;

typedef struct
{
    /** @brief The Spi configuration using for accessing to the Transceiver. */
    Aecanphy_Ip_SpiConfigType SpiConfig;
    /** @brief The mode of transceiver enterred after Initialization. */
    Aecanphy_Ip_TransceiverModeType DeviceModeAfterInit;
} Aecanphy_Ip_ConfigType;
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

#endif /* AECANPHY_IP_TYPES_H */
