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

#ifndef AECANPHY_HWACCESS_H
#define AECANPHY_HWACCESS_H

/**
*   @file Aecanphy_HwAccess.h
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
#include "Aecanphy_Ip_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AECANPHY_HWACCESS_VENDOR_ID                    43
#define AECANPHY_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define AECANPHY_HWACCESS_AR_RELEASE_MINOR_VERSION     7
#define AECANPHY_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define AECANPHY_HWACCESS_SW_MAJOR_VERSION             5
#define AECANPHY_HWACCESS_SW_MINOR_VERSION             0
#define AECANPHY_HWACCESS_SW_PATCH_VERSION             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Aecanphy_HwAccess.h and Aecanphy_Ip_Types.h header file are of the same vendor */
#if (AECANPHY_HWACCESS_VENDOR_ID != AECANPHY_IP_TYPES_VENDOR_ID)
    #error "Aecanphy_HwAccess.h and Aecanphy_Ip_Types.h have different vendor ids"
#endif
/* Check if Aecanphy_HwAccess.h and Aecanphy_Ip_Types.h header file are of the same Autosar version */
#if ((AECANPHY_HWACCESS_AR_RELEASE_MAJOR_VERSION != AECANPHY_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AECANPHY_HWACCESS_AR_RELEASE_MINOR_VERSION != AECANPHY_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AECANPHY_HWACCESS_AR_RELEASE_REVISION_VERSION != AECANPHY_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Aecanphy_HwAccess.h and Aecanphy_Ip_Types.h are different"
#endif

/* Check if Aecanphy_HwAccess.h and Aecanphy_Ip_Types.h header file are of the same software version */
#if ((AECANPHY_HWACCESS_SW_MAJOR_VERSION != AECANPHY_IP_TYPES_SW_MAJOR_VERSION) || \
     (AECANPHY_HWACCESS_SW_MINOR_VERSION != AECANPHY_IP_TYPES_SW_MINOR_VERSION) || \
     (AECANPHY_HWACCESS_SW_PATCH_VERSION != AECANPHY_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aecanphy_HwAccess.h and Aecanphy_Ip_Types.h are different"
#endif

/* Check if Aecanphy_HwAccess.h and Std_Types.h are of the same software version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((AECANPHY_HWACCESS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (AECANPHY_HWACCESS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of Aecanphy_HwAccess.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define AE_CANPHY_CANPHY_CFG_REG_ADDR                  (0x70U)
#define AE_CANPHY_CANPHY_MONITOR_REG_ADDR              (0x74U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

Aecanphy_Ip_StatusType Aecanphy_WriteRegisterViaSpi(const Aecanphy_Ip_SpiConfigType * SpiConfig,
                                                    uint16 RegAddr,
                                                    uint32 writeData,
                                                    uint8 Size
                                                   );

Aecanphy_Ip_StatusType Aecanphy_ReadRegisterViaSpi(const Aecanphy_Ip_SpiConfigType * SpiConfig,
                                                   uint16 RegAddr,
                                                   uint32 * rxData,
                                                   uint8 Size
                                                  );

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AECANPHY_HWACCESS_H */
