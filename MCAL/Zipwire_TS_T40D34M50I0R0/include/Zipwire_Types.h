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

#ifndef ZIPWIRE_TYPES_H
#define ZIPWIRE_TYPES_H

/**
*   @file Zipwire_Types.h
*
*   @addtogroup ZIPWIRE_HLD_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Zipwire_Ip_Types.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Zipwire driver header file and also in the
*        module's description file
*/
#define ZIPWIRE_TYPES_VENDOR_ID                   43
#define ZIPWIRE_TYPES_AR_RELEASE_MAJOR_VERSION    4
#define ZIPWIRE_TYPES_AR_RELEASE_MINOR_VERSION    7
#define ZIPWIRE_TYPES_AR_RELEASE_REVISION_VERSION 0
#define ZIPWIRE_TYPES_SW_MAJOR_VERSION            5
#define ZIPWIRE_TYPES_SW_MINOR_VERSION            0
#define ZIPWIRE_TYPES_SW_PATCH_VERSION            0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Zipwire_Types.h and Zipwire_Ip_Types.h are of the same version */
#if (ZIPWIRE_TYPES_VENDOR_ID != ZIPWIRE_IP_TYPES_VENDOR_ID)
#error "Zipwire_Types.h and Zipwire_Ip_Types.h have different vendor ids"
#endif

/* Check if Zipwire_Types.h and Zipwire_Ip_Types.h are of the same Autosar version */
#if ((ZIPWIRE_TYPES_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_TYPES_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_TYPES_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Types.h and Zipwire_Ip_Types.h are different"
#endif

/* Check if Zipwire_Types.h and Zipwire_Ip_Types.h are of the same Software version */
#if ((ZIPWIRE_TYPES_SW_MAJOR_VERSION != ZIPWIRE_IP_TYPES_SW_MAJOR_VERSION) || \
    (ZIPWIRE_TYPES_SW_MINOR_VERSION != ZIPWIRE_IP_TYPES_SW_MINOR_VERSION) || \
    (ZIPWIRE_TYPES_SW_PATCH_VERSION != ZIPWIRE_IP_TYPES_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Types.h and Zipwire_Ip_Types.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief         ZIPWIRE Partition Configuration Type.
* @details       The Instance is identified by the following Partition
*/
typedef struct
{
    const uint32 InstanceMax;
    const uint32 *InstanceUsed;
} Zipwire_PartitionType;


/**
 * @brief   This type contains the Zipwire Initialization.
 * @details The Zipwire Ip Initialization contains all the information required to initialize the ZIPWIRE Channels
 *          Internal driver structure.
 *
 * */
typedef Zipwire_Ip_ConfigType Zipwire_InitType;
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ZIPWIRE_TYPES_H */
