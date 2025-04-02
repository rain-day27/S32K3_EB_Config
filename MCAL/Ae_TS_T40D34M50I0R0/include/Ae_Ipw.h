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

#ifndef AE_IPW_H
#define AE_IPW_H

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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ae_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_IPW_VENDOR_ID                    43
#define AE_IPW_AR_RELEASE_MAJOR_VERSION     4
#define AE_IPW_AR_RELEASE_MINOR_VERSION     7
#define AE_IPW_AR_RELEASE_REVISION_VERSION  0
#define AE_IPW_SW_MAJOR_VERSION             5
#define AE_IPW_SW_MINOR_VERSION             0
#define AE_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Ae_Ipw_Cfg.h */
#if (AE_IPW_VENDOR_ID != AE_IPW_CFG_VENDOR_ID)
    #error "Ae_Ipw.h and Ae_Ipw_Cfg.h have different vendor ids"
#endif
#if ((AE_IPW_AR_RELEASE_MAJOR_VERSION    != AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_AR_RELEASE_MINOR_VERSION    != AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_AR_RELEASE_REVISION_VERSION != AE_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae_Ipw.h and Ae_Ipw_Cfg.h are different"
#endif
#if ((AE_IPW_SW_MAJOR_VERSION != AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (AE_IPW_SW_MINOR_VERSION != AE_IPW_CFG_SW_MINOR_VERSION) || \
     (AE_IPW_SW_PATCH_VERSION != AE_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae_Ipw.h and Ae_Ipw_Cfg.h are different"
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

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

Std_ReturnType  Ae_Ipw_Init (const Ae_Ipw_ConfigType *pConfig);
Std_ReturnType Ae_Ipw_WriteReg (const uint32 RegAddr,
                                uint8 DataWidth,
                                uint32 RegValue
                                );
Std_ReturnType Ae_Ipw_ReadReg (const uint32 RegAddr,
                               uint8 DataWidth,
                               uint32 * const RegValue
                               );
boolean Ae_Ipw_Frame_Counter( boolean IsVerify,
                              uint8 ExpectedFrameCount,
                              uint8 *ActualFrameCount
                            );
uint16 Ae_Ipw_DecodeGlobalHealthStatus(void);
Std_ReturnType  Ae_Ipw_AdcMeasureConfig(const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                        Ae_AnalogInputType AnalogInputSelect
                                        );
Std_ReturnType  Ae_Ipw_DigitalInputEventConfig(const Ae_HviChannelConfig *pAeHviChannelConfig);
Std_ReturnType  Ae_Ipw_VoltageMonitorConfig(const Ae_VmConfig *pAeVmConfig,
                                            const Ae_HviHighVoltageInputConfig *pHighVoltageInput
                                            );
void Ae_Ipw_FaultsEventsProccess(void);
void Ae_Ipw_ReadFaultsEventsStatus(void);
void Ae_Ipw_SetRaw(boolean Activate);

#if(STD_ON == AE_USE_NMI_INTERRUPT)
void Ae_Ipw_InterruptSetupEventFaultHandler(void);
void Ae_Ipw_NMISetupEventFaultHandler(void);
#endif

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AE_IPW_H */
