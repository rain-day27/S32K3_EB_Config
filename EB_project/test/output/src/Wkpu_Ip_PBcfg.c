/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

/**
 *   @file          Wkpu_Ip_PBcfg.c
 *   @version       5.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup wkpu_icu_ip WKPU IPL
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
*================================================================================================*/
#include "Std_Types.h"
#include "Wkpu_Ip_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define WKPU_IP_PBCFG_VENDOR_ID_C                    43
#define WKPU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define WKPU_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C     7
#define WKPU_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define WKPU_IP_PBCFG_SW_MAJOR_VERSION_C             5
#define WKPU_IP_PBCFG_SW_MINOR_VERSION_C             0
#define WKPU_IP_PBCFG_SW_PATCH_VERSION_C             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WKPU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_PBcfg.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_PBCFG_VENDOR_ID_C != WKPU_IP_TYPES_VENDOR_ID)
    #error "Wkpu_Ip_PBcfg.c and Wkpu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != WKPU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != WKPU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != WKPU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_PBcfg.c and Wkpu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_PBCFG_SW_MAJOR_VERSION_C != WKPU_IP_TYPES_SW_MAJOR_VERSION) || \
     (WKPU_IP_PBCFG_SW_MINOR_VERSION_C != WKPU_IP_TYPES_SW_MINOR_VERSION) || \
     (WKPU_IP_PBCFG_SW_PATCH_VERSION_C != WKPU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wkpu_Ip_PBcfg.c and Wkpu_Ip_Types.h are different"
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/
#if (STD_ON == WKPU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

/** @brief Signature of wakeup and overflow interrupt function. */
extern void Icu_ReportWakeupAndOverflow(uint16 Channel, boolean bOverflow);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/** @brief Variant: PB Default WKPU Configuration. */
const Wkpu_Ip_ChannelConfigType Wkpu_Ip_ChannelConfig_PB[1U] = 
{
    /** @brief IcuWkpuChannels_WKUP59_PA20 */
    {
        /** @brief Wkpu HW Channel used by the Icu channel */
        63U,
        /** @brief Wkpu HW Channel Filter enable */
        (boolean)TRUE,
        /** @brief Wkpu HW Channel Pullup enable */
        (boolean)FALSE,
        /** @brief Wkpu Default Start Edge */
        WKPU_IP_RISING_EDGE,
        /** @brief Wkpu Channel Callback */
        &Icu_ReportEvents,
        /** @brief The notification functions */
        NULL_PTR,
        /** @brief Wkpu Callback Param1 */
        1U
    }
};

/** @brief Variant: PB WKPU IP Configuration. */
const Wkpu_Ip_IrqConfigType Wkpu_Ip_Config_PB =
{
#if (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API))
    /** @brief Number of Wkpu NMI channels in the Icu configuration */
    (uint8)0U,
    /** @brief Pointer to the array of Wkpu enabled Icu channel configurations */
    NULL_PTR,
#endif
    /** @brief Number of Wkpu channels in the Icu configuration */
    (uint8)1U,
    /** @brief Pointer to the array of Wkpu enabled Icu channel configurations */
    &Wkpu_Ip_ChannelConfig_PB
};

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#endif /* WKPU_IP_USED */
/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

