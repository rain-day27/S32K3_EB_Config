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

#ifndef AE_IPW_TYPES_H
#define AE_IPW_TYPES_H

/**
*   @file
*
*   @addtogroup AE_DRIVER Ae Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Aec_Ip_Types.h"
#include "Hvm_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_IPW_TYPES_VENDOR_ID                    43
#define AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION     7
#define AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define AE_IPW_TYPES_SW_MAJOR_VERSION             5
#define AE_IPW_TYPES_SW_MINOR_VERSION             0
#define AE_IPW_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Types.h */
#if (AE_IPW_TYPES_VENDOR_ID != AEC_IP_TYPES_VENDOR_ID)
    #error "Ae_Ipw_Types.h and Aec_Ip_Types.h have different vendor ids"
#endif
#if ((AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION != AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae_Ipw_Types.h and Aec_Ip_Types.h are different"
#endif
#if ((AE_IPW_TYPES_SW_MAJOR_VERSION != AEC_IP_TYPES_SW_MAJOR_VERSION) || \
     (AE_IPW_TYPES_SW_MINOR_VERSION != AEC_IP_TYPES_SW_MINOR_VERSION) || \
     (AE_IPW_TYPES_SW_PATCH_VERSION != AEC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae_Ipw_Types.h and Aec_Ip_Types.h are different"
#endif

/* Checks against Hvm_Ip_Types.h */
#if (AE_IPW_TYPES_VENDOR_ID != HVM_IP_TYPES_VENDOR_ID)
    #error "Ae_Ipw_Types.h and Hvm_Ip_Types.h have different vendor ids"
#endif
#if ((AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION != HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Ae_Ipw_Types.h and Hvm_Ip_Types.h are different"
#endif
#if ((AE_IPW_TYPES_SW_MAJOR_VERSION != HVM_IP_TYPES_SW_MAJOR_VERSION) || \
     (AE_IPW_TYPES_SW_MINOR_VERSION != HVM_IP_TYPES_SW_MINOR_VERSION) || \
     (AE_IPW_TYPES_SW_PATCH_VERSION != HVM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ae_Ipw_Types.h and Hvm_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Forward IPW structure declarations */
struct Aec_Ip_sConfigType;
struct Hvm_Ip_sConfigType;

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct Ae_Ipw_sConfigType
{
    const struct Aec_Ip_sConfigType *Ae_Ipw_pAecConfig;
    const struct Hvm_Ip_sConfigType *Ae_Ipw_pHvmConfig;

} Ae_Ipw_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AE_IPW_TYPES_H */
