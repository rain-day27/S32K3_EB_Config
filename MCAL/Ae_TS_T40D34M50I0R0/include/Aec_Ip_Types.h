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

#ifndef AEC_IP_TYPES_H
#define AEC_IP_TYPES_H

/**
*   @file
*
*   @addtogroup AEC_DRIVER AEC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Lpspi_Ip.h"
#include "Aec_Ip_Cfg_Defines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_TYPES_VENDOR_ID                      43
#define AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define AEC_IP_TYPES_SW_MAJOR_VERSION               5
#define AEC_IP_TYPES_SW_MINOR_VERSION               0
#define AEC_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Cfg_Defines.h */
#if (AEC_IP_TYPES_VENDOR_ID != AEC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Aec_Ip_Types.h and Aec_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != AEC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != AEC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION != AEC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Types.h and Aec_Ip_Cfg_Defines.h are different"
#endif
#if ((AEC_IP_TYPES_SW_MAJOR_VERSION != AEC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (AEC_IP_TYPES_SW_MINOR_VERSION != AEC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (AEC_IP_TYPES_SW_PATCH_VERSION != AEC_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Types.h and Aec_Ip_Cfg_Defines.h are different"
#endif

/* Checks against Lpspi_Ip.h */
#if (AEC_IP_TYPES_VENDOR_ID != LPSPI_IP_VENDOR_ID)
    #error "Aec_Ip_Types.h and Lpspi_Ip.h have different vendor ids"
#endif
#if ((AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != LPSPI_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != LPSPI_IP_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION != LPSPI_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Types.h and Lpspi_Ip.h are different"
#endif
#if ((AEC_IP_TYPES_SW_MAJOR_VERSION != LPSPI_IP_SW_MAJOR_VERSION) || \
     (AEC_IP_TYPES_SW_MINOR_VERSION != LPSPI_IP_SW_MINOR_VERSION) || \
     (AEC_IP_TYPES_SW_PATCH_VERSION != LPSPI_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Types.h and Lpspi_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Types.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Return status of global health for each frame. User can use this to read status. */
#define AEC_STATUS_CLOCK_MISS               (0x0001U)
#define AEC_STATUS_WRONG_ANSWER             (0x0002U)
#define AEC_STATUS_FSM_STATUS               (0x0004U)
#define AEC_STATUS_TST_MODE                 (0x0010U)
#define AEC_STATUS_PMC_MODE                 (0x0020U)
#define AEC_STATUS_FAULT_NOTIFY             (0x0040U)
#define AEC_STATUS_EVENT_NOTIFY             (0x0080U)
#define AEC_STATUS_FRAME_COUNT              (0x7F00U)
#define AEC_STATUS_FIRST_FRAME              (0x8000U)

#define AEC_STATUS_GLOBAL_HEALTH_MASK        (0x80F7U)

#define AEC_SPI_FRAME_COUNT_SHIFT           8U
#define AEC_SPI_FRAME_COUNT_MASK            0x7F00U

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief          Status type.
* @implements     Aec_Ip_StatusType_Enumeration
*/
typedef enum
{
    /* Generic error codes */
    AEC_STATUS_SUCCESS                    = 0x000U,   /*!< Generic operation success status */
    AEC_STATUS_ERROR                      = 0x001U,   /*!< Generic operation failure status */
    AEC_STATUS_TIMEOUT                    = 0x002U    /*!< Generic operation timeout status */

} Aec_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief SPI configuration for access
 * @implements  Aec_Ip_SpiConfigType_structure
 *
 */
typedef struct Aec_Ip_sSpiConfigType
{
    boolean SyncTransmit;   /* SPI sync/async transmission */
    uint32 Timeout;
    const Lpspi_Ip_ExternalDeviceType *Extension;
} Aec_Ip_SpiConfigType;

/**
* @brief          Interrupt handler type.
*/
typedef void (*Aec_Ip_IntHandlerType)(void);

/**
* @brief          Interrupt handler type.
*/
typedef void (*Aec_Ip_GHSHandlerType)(void);

/**
* @brief          Structure storing the routing and handler configuration for an interrupt request.
* @implements     Aec_Ip_IntRouteConfigType_structure
*/
typedef struct Aec_Ip_sIntRouteConfigType
{
    /** @brief Name of event/fault */
    uint16 IsrMask;
    /** @brief Priority for event/fault */
    uint8 IsrPriority;
    /** @brief Interrupt handler */
    Aec_Ip_IntHandlerType pfHandler;

} Aec_Ip_IntRouteConfigType;

/**
* @brief          Structure storing the routing and handler configuration for an interrupt request.
*/
typedef struct Aec_Ip_sGHSRouteConfigType
{
    /** @brief Name of event/fault */
    uint16 Mask;
    /** @brief Priority for event/fault */
    uint8 Priority;
    /** @brief Interrupt handler */
    Aec_Ip_GHSHandlerType pfHandler;

} Aec_Ip_GHSRouteConfigType;

#ifdef __cplusplus
}
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

/** @} */

#endif /* AEC_IP_TYPES_H */
