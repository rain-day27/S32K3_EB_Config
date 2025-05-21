/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup adc_ipw_config Adc Ipw Configuration
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

#include "Adc_Ipw_CfgDefines.h"
#include "Adc_Ipw_PBcfg.h"
#include "Adc_Sar_Ip_PBcfg.h"
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
#include "Sdadc_Ip_PBcfg.h"
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_PBCFG_C                      43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C       7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define ADC_IPW_SW_MAJOR_VERSION_PBCFG_C               5
#define ADC_IPW_SW_MINOR_VERSION_PBCFG_C               0
#define ADC_IPW_SW_PATCH_VERSION_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Ipw_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_PBCFG_C != ADC_IPW_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_PBcfg.c and Adc_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Ipw_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_PBCFG_C != ADC_IPW_VENDOR_ID_PBCFG)
    #error "Adc_Ipw_PBcfg.c and Adc_Ipw_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Ipw_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_PBcfg.c and Adc_Ipw_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Ipw_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_PBcfg.c and Adc_Ipw_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Sar_Ip_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_PBCFG_C != ADC_SAR_IP_VENDOR_ID_PBCFG)
    #error "Adc_Ipw_PBcfg.c and Adc_Sar_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Sar_Ip_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_PBcfg.c and Adc_Sar_Ip_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_PBcfg.c file and Adc_Sar_Ip_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_PBCFG_C != ADC_SAR_IP_SW_MAJOR_VERSION_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_PBCFG_C != ADC_SAR_IP_SW_MINOR_VERSION_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_PBCFG_C != ADC_SAR_IP_SW_PATCH_VERSION_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_PBcfg.c and Adc_Sar_Ip_PBcfg.h are different"
#endif



/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


/**
* @brief          Definition of Adc Ipw Channel for Logical Unit Id 0 configuration variant .
*/
static const Adc_Ipw_ChannelConfig AdcIpwChannelConfig_0[] =
{
    /**< @brief Channel logical Id 0 */
    {
        NULL_PTR, /* WdgNotification */
        0U, /* LogicalThresholdId */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /* ChannelLimitCheckingConfig */
        {
            /**< @brief limit check enabled */
            (boolean)FALSE, /* ChannelLimitCheckEnabled */
            /**< @brief range for limit check */
            ADC_RANGE_ALWAYS, /* ChannelRange */
            /**< @brief high limit value */
            4095U, /* ChannelHighLimit */
            /**< @brief low limit value */
            0U /* ChannelLowLimit */
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    },
    /**< @brief Channel logical Id 1 */
    {
        NULL_PTR, /* WdgNotification */
        0U, /* LogicalThresholdId */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /* ChannelLimitCheckingConfig */
        {
            /**< @brief limit check enabled */
            (boolean)FALSE, /* ChannelLimitCheckEnabled */
            /**< @brief range for limit check */
            ADC_RANGE_ALWAYS, /* ChannelRange */
            /**< @brief high limit value */
            4095U, /* ChannelHighLimit */
            /**< @brief low limit value */
            0U /* ChannelLowLimit */
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          Adc Ipw Config configuration variant .
*/
const Adc_Ipw_Config AdcIpwCfg =
{
    { &AdcSarIpConfig_0, NULL_PTR, NULL_PTR }, /* AdcConfigPtrArr */
#if (ADC_IPW_SDADC_IS_USED == STD_ON)
    { NULL_PTR, NULL_PTR, NULL_PTR }, /* SdadcConfigPtrArr */
#endif /* (ADC_IPW_SDADC_IS_USED == STD_ON) */
    { 0U, ADC_IPW_INVALID_LOGICAL_UNIT_ID, ADC_IPW_INVALID_LOGICAL_UNIT_ID }, /* AdcPhysicalIdArr */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { NULL_PTR, NULL_PTR, NULL_PTR }, /* AdcAltClockConfig */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { AdcIpwChannelConfig_0, NULL_PTR, NULL_PTR }, /* AdcIpwChannelConfig */
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    { NULL_PTR }, /* CtuConfigTriggerMode */
    { NULL_PTR }, /* CtuConfigControlMode */
#endif
#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_BCTU_AVAILABLE == STD_ON) || (ADC_IPW_CTU_AVAILABLE == STD_ON)))
    { 0U, 0U, 0U }, /* CtuListStartIndex */
    { 0U, 0U, 0U }, /* CtuListMaxNumElems */
#endif /* ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_BCTU_AVAILABLE == STD_ON) || (ADC_IPW_CTU_AVAILABLE == STD_ON))) */
    { 1U, 0U, 0U }, /* AdcUnitSupportCtuControlMode */
    /* Mapping */
    {
        { ADC_INTERRUPT, ADC_IPW_INVALID_TRANSFER_TYPE /* Unit not used */, ADC_IPW_INVALID_TRANSFER_TYPE /* Unit not used */ }, /* AdcDmaInterruptSoftware */
        /**< @brief number of the maximum hardware units in the current configuration */
        1U, /* AdcMaxHwCfg */
        /**< @brief number of groups per hw unit > */
        { 1U, 0U, 0U }, /* AdcGroups */
        /**< @brief number of channels per hw unit > */
        { 2U, 0U, 0U }, /* AdcChannels */
#if ((defined(ADC_ANY_UNIT_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
        /* ChannelLogicalId */
        {
            { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
            { 0U }, /* Unit not used */
            { 0U } /* Unit not used */
        },
#endif /* ((defined(ADC_ANY_UNIT_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcDmaChannelLogicId */
        { 0U, 0U, 0U }, /* DmaNumSgaElement */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcCountingDmaChanLogicId */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        { STD_ON, STD_OFF, STD_OFF }, /* AdcHwUnitArr */
        { 0U, ADC_IPW_INVALID_LOGICAL_UNIT_ID, ADC_IPW_INVALID_LOGICAL_UNIT_ID }, /* HwLogicalId */
#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON))
        { }, /* CtuLogToPhyId */
        { ADC_IPW_INVALID_LOGICAL_UNIT_ID }, /* CtuPhyToLogId */
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
    }
};


#ifdef ADC_AVERAGING_FUNCTIONALITY_SUPPORT
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          ADC Ipw Group 0 Config .
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_0 =
{
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelect */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_SAR_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
    { 22U, 22U, 22U }, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME, ADC_SAR_IP_DEF_SAMPLE_TIME } /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
};

#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
#endif /* ADC_AVERAGING_FUNCTIONALITY_SUPPORT */

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

