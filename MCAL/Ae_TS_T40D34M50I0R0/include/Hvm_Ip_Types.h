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

#ifndef HVM_IP_TYPES_H
#define HVM_IP_TYPES_H

/**
*   @file
*
*   @addtogroup HVM_DRIVER HVM Driver
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
#include "Hvm_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_TYPES_VENDOR_ID                      43
#define HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define HVM_IP_TYPES_SW_MAJOR_VERSION               5
#define HVM_IP_TYPES_SW_MINOR_VERSION               0
#define HVM_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Hvm_Ip_Types.h and Mcal.h are different"
    #endif
#endif

/* Checks against Hvm_Ip_Cfg_Defines.h */
#if (HVM_IP_TYPES_VENDOR_ID != HVM_IP_CFG_DEFINES_VENDOR_ID)
    #error "Hvm_Ip_Types.h and Hvm_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((HVM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != HVM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != HVM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_TYPES_AR_RELEASE_REVISION_VERSION != HVM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Types.h and Hvm_Ip_Cfg_Defines.h are different"
#endif
#if ((HVM_IP_TYPES_SW_MAJOR_VERSION != HVM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (HVM_IP_TYPES_SW_MINOR_VERSION != HVM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (HVM_IP_TYPES_SW_PATCH_VERSION != HVM_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip_Types.h and Hvm_Ip_Cfg_Defines.h are different"
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

 /**
 * @brief Hvm_Ip_StatusType_Enumeration
 * @implements Hvm_Ip_StatusType_Enumeration
 */
typedef enum
{
    /* Generic error codes */
    HVM_STATUS_SUCCESS                    = 0x000U,   /*!< Generic operation success status */
    HVM_STATUS_ERROR                      = 0x001U,   /*!< Generic operation failure status */
    HVM_STATUS_TIMEOUT                    = 0x002U    /*!< Generic operation timeout status */

} Hvm_Ip_StatusType;

/**
 * @brief Hvm_Ip_OutputStatusType_Enumeration
 * @implements Hvm_Ip_OutputStatusType_Enumeration
 */
typedef enum
{
    /* Generic error codes */
    HVM_STATUS_NOTHING_DETECT               = 0x000U,   /*!< Generic operation nothing detect status */
    HVM_STATUS_HIGH_DETECT                  = 0x001U,   /*!< Generic operation high voltage detect status */
    HVM_STATUS_LOW_DETECT                   = 0x002U,   /*!< Generic operation low voltage detect status */
    HVM_STATUS_DIGITAL_INPUT_ACTIVE         = 0x004U,   /*!< Generic operation digital input active status */
    HVM_STATUS_OUTPUT_ERROR                 = 0x008U    /*!< Generic operation failure status */

} Hvm_Ip_OutputStatusType;

/**
 * @brief Hvm_Ip_ChannelType_Enumeration
 * @implements Hvm_Ip_ChannelType_Enumeration
 */
typedef enum
{
   HVI0_CHANNEL = 0U,
   HVI1_CHANNEL = 1U
} Hvm_Ip_ChannelType;

/**
 * @brief Hvm_Ip_HighVoltDetectRefType_Enumeration
 * @implements Hvm_Ip_HighVoltDetectRefType_Enumeration
 */
typedef enum
{
   VM_HBI1 = 0U,
   VM_HBI2 = 1U
} Hvm_Ip_HighVoltDetectRefType;

/**
 * @brief Hvm_Ip_LowVoltDetectRefType_Enumeration
 * @implements Hvm_Ip_LowVoltDetectRefType_Enumeration
 */
typedef enum
{
   VM_LBI1 = 0U,
   VM_LBI2 = 1U,
   VM_LBI3 = 2U,
   VM_LBI4 = 3U
} Hvm_Ip_LowVoltDetectRefType;

/**
 * @brief Hvm_Ip_VoltageMonitorInputType_Enumeration
 * @implements Hvm_Ip_VoltageMonitorInputType_Enumeration
 */
typedef enum
{
   VM_HIGH_VOLTAGE_INPUT = 0U,
   VM_SENSE_VOLTAGE      = 1U
} Hvm_Ip_VoltageMonitorInputType;

/**
 * @brief Hvm_Ip_DigitalInputPolarityType_Enumeration
 * @implements Hvm_Ip_DigitalInputPolarityType_Enumeration
 */
typedef enum
{
   HVI_DIGITAL_INPUT_POLARITY_PULLDOWN       = 0U,
   HVI_DIGITAL_INPUT_POLARITY_PULLUP         = 1U
} Hvm_Ip_DigitalInputPolarityType;

/**
 * @brief Ae_AnalogInputType_Enumeration
 * @implements Ae_AnalogInputType_Enumeration
 */
typedef enum
{
   HVI_ANALOG_OUT_OHMIC                         = 0U,
   HVI_ANALOG_INPUT_BUFFERED                    = 1U,
   HVI_ANALOG_DIVIDE_DOWN_HIGH_INPUT_BUFFERED   = 2U,
   HVI_ANALOG_INPUT_UNBUFFERED                  = 3U
} Ae_AnalogInputType;

/**
 * @brief Hvm_Ip_DivVoltageType_Enumeration
 * @implements Hvm_Ip_DivVoltageType_Enumeration
 */
typedef enum
{
   HVI_VOLTAGE_DIVISION_2       = 0U,
   HVI_VOLTAGE_DIVISION_6       = 1U,
   HVI_VOLTAGE_DIVISION_11      = 2U,
   HVI_VOLTAGE_DIVISION_16      = 3U
} Hvm_Ip_DivVoltageType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* Callback function for events */
typedef void (*Hvm_Ip_ReportEventCallbackType)(uint8 Instance, Hvm_Ip_OutputStatusType Event);

/**
 * @brief Ae_HviHighVoltageInputConfig_structure
 * @implements Ae_HviHighVoltageInputConfig_structure
 */
typedef struct
{
    uint8 Hvichannel;
    boolean PullUpEn;
    boolean PullDownEn;
    Hvm_Ip_DivVoltageType VoltDiv;
} Ae_HviHighVoltageInputConfig;

/**
 * @brief Ae_VmConfig_structure
 * @implements Ae_VmConfig_structure
 */
typedef struct Hvm_Ip_sVmConfig
{
    Hvm_Ip_VoltageMonitorInputType VoltageMonitor;
    boolean HighVolDectEn;
    boolean LowVolDectEn;
    boolean IntHighVoltageEn;
    boolean IntLowVoltageEn;
    Hvm_Ip_HighVoltDetectRefType HighVoltDect;
    Hvm_Ip_LowVoltDetectRefType LowVoltDect;
} Ae_VmConfig;

/**
 * @brief Ae_HviChannelConfig
 * @implements Ae_HviChannelConfig_structure
 */
typedef struct Hvm_Ip_sHviChannelConfig
{
    Ae_HviHighVoltageInputConfig HviHighVolInputConfig;
    boolean InputDigitalEn;
    Hvm_Ip_DigitalInputPolarityType InputPolarity;
    boolean IntDiditalInputEn;

} Ae_HviChannelConfig;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* HVM_IP_TYPES_H */
