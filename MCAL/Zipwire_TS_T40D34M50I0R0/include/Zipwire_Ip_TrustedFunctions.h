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
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.

==================================================================================================*/

/**
*   @file    Zipwire_Ip_TrustedFunctions.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @addtogroup
*   @{
*/


#ifndef ZIPWIRE_IP_TRUSTEDFUNCTIONS_H
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "Zipwire_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       7
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               5
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define ZIPWIRE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip_TrustedFunctions.h file and Mcal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Zipwire_Ip_TrustedFunctions.h and Mcal.h are different"
#endif
#endif


/* Check if the files Zipwire_Ip_TrustedFunctions.h and Zipwire_Ip_CfgDefines.h are of the same version */
#if (ZIPWIRE_IP_TRUSTEDFUNCTIONS_VENDOR_ID != ZIPWIRE_IP_CFG_DEFINES_VENDOR_ID)
    #error "Zipwire_Ip_TrustedFunctions.h and Zipwire_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_TrustedFunctions.h and Zipwire_Ip_CfgDefines.h are of the same Autosar version */
#if ((ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (ZIPWIRE_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Zipwire_Ip_TrustedFunctions.h and Zipwire_Ip_CfgDefines.h are different"
#endif

/* Check if Zipwire_Ip_TrustedFunctions.h and Zipwire_Ip_CfgDefines.h are of the same Software version */
#if ((ZIPWIRE_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (ZIPWIRE_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (ZIPWIRE_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != ZIPWIRE_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Zipwire_Ip_TrustedFunctions.h and Zipwire_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

#if (defined(ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) && (ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT == STD_ON))

/**
 * @brief This function configure Set User Access Allowed
 */
extern void Zipwire_Ip_SetUserAccessAllowed(uint32 const pxZipwireBaseAddr);

#endif

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ZIPWIRE_IP_TRUSTEDFUNCTIONS_H */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
