/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*/

#ifndef LINTRCV_43_AE_IPW_TYPES_H
#define LINTRCV_43_AE_IPW_TYPES_H

/**
*   @file
*
*   @internal
*   @addtogroup LINTRCV_43_AE_IPW
*   @{
*/

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

#include "LinTrcv_43_AE_Cfg.h"
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
#include "EcuM_Externals.h"
#endif
#include "AeLinPhy_LinTrcv_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINTRCV_43_AE_IPW_TYPES_VENDOR_ID                    43
#define LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION     7
#define LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LINTRCV_43_AE_IPW_TYPES_SW_MAJOR_VERSION             5
#define LINTRCV_43_AE_IPW_TYPES_SW_MINOR_VERSION             0
#define LINTRCV_43_AE_IPW_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#if (LINTRCV_43_AE_IPW_TYPES_VENDOR_ID != AELINPHY_LINTRCV_IP_TYPES_VENDOR_ID)
    #error "AeLinPhy_Ipw_Types.h and AeLinPhy_LinTrcv_Ip_Types.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION != AELINPHY_LINTRCV_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of AeLinPhy_Ipw_Types.h and AeLinPhy_LinTrcv_Ip_Types.h are different"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip_Types header file are of the same Software version */
#if ((LINTRCV_43_AE_IPW_TYPES_SW_MAJOR_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_SW_MINOR_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_SW_PATCH_VERSION != AELINPHY_LINTRCV_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of AeLinPhy_Ipw_Types.h and AeLinPhy_LinTrcv_Ip_Types.h are different"
#endif

/* Checks against LinTrcv_43_AE_Cfg.h */
#if (LINTRCV_43_AE_IPW_TYPES_VENDOR_ID != LINTRCV_43_AE_CFG_VENDOR_ID)
    #error "LinTrcv_43_AE_Ipw_Types.h and LinTrcv_43_AE_Cfg.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LINTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Ipw_Types.h and LinTrcv_43_AE_Cfg.h are different"
#endif
#if ((LINTRCV_43_AE_IPW_TYPES_SW_MAJOR_VERSION != LINTRCV_43_AE_CFG_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_SW_MINOR_VERSION != LINTRCV_43_AE_CFG_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_IPW_TYPES_SW_PATCH_VERSION != LINTRCV_43_AE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Ipw_Types.h and LinTrcv_43_AE_Cfg.h are different"
#endif
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and ComStackTypes header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (LINTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of LinTrcv_43_AE_Ipw_Types.h and EcuM_Externals.h are different"
    #endif
#endif
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
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @internal
 * @brief        Structure which brings together all the hardware specific information regarding a channel
 * @details      This structure contains:
 *               - u8LinTrcvIpType member which indicates the type of hardware instance configured for the current channel.
 *               - pIpConfig member containing a singular valid pointer to a hardware specific user configured structure.
 *               - u8LinTrcvHwChannel which specifies the number of hardware instance configured for the current channel.
 *
 *
 * */
typedef struct
{
    const uint8 LinTrcvHwChannel;                           /**< @brief The number of hardware instance configured */
    const AeLinPhy_LinTrcv_Ip_UserConfigType *AeLinPhyConfigPtr; /**< @brief A pointer to a AELINPHY user configuration structure */
} LinTrcv_43_AE_HwConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                  EXTERNAL CONSTANTS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINTRCV_43_AE_IPW_TYPES_H */
