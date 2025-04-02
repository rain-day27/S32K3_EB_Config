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
#include "Ae_Ipw.h"
#include "Aec_Ip.h"
#include "Hvm_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AE_IPW_VENDOR_ID_C                      43
#define AE_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define AE_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define AE_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define AE_IPW_SW_MAJOR_VERSION_C               5
#define AE_IPW_SW_MINOR_VERSION_C               0
#define AE_IPW_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Ae_Ipw.h */
#if (AE_IPW_VENDOR_ID_C != AE_IPW_VENDOR_ID)
    #error "Ae_Ipw.c and Ae_Ipw.h have different vendor ids"
#endif
#if ((AE_IPW_AR_RELEASE_MAJOR_VERSION_C    != AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_AR_RELEASE_MINOR_VERSION_C    != AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_AR_RELEASE_REVISION_VERSION_C != AE_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae_Ipw.c and Ae_Ipw.h are different"
#endif
#if ((AE_IPW_SW_MAJOR_VERSION_C != AE_IPW_SW_MAJOR_VERSION) || \
     (AE_IPW_SW_MINOR_VERSION_C != AE_IPW_SW_MINOR_VERSION) || \
     (AE_IPW_SW_PATCH_VERSION_C != AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae_Ipw.c and Ae_Ipw.h are different"
#endif

/* Checks against Aec_Ip.h */
#if (AE_IPW_VENDOR_ID_C != AEC_IP_VENDOR_ID)
    #error "Ae_Ipw.c and Aec_Ip.h have different vendor ids"
#endif
#if ((AE_IPW_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_AR_RELEASE_REVISION_VERSION_C != AEC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae_Ipw.c and Aec_Ip.h are different"
#endif
#if ((AE_IPW_SW_MAJOR_VERSION_C != AEC_IP_SW_MAJOR_VERSION) || \
     (AE_IPW_SW_MINOR_VERSION_C != AEC_IP_SW_MINOR_VERSION) || \
     (AE_IPW_SW_PATCH_VERSION_C != AEC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae_Ipw.c and Aec_Ip.h are different"
#endif

/* Checks against Hvm_Ip.h */
#if (AE_IPW_VENDOR_ID_C != HVM_IP_VENDOR_ID)
    #error "Ae_Ipw.c and Hvm_Ip.h have different vendor ids"
#endif
#if ((AE_IPW_AR_RELEASE_MAJOR_VERSION_C    != HVM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AE_IPW_AR_RELEASE_MINOR_VERSION_C    != HVM_IP_AR_RELEASE_MINOR_VERSION) || \
     (AE_IPW_AR_RELEASE_REVISION_VERSION_C != HVM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Ae_Ipw.c and Hvm_Ip.h are different"
#endif
#if ((AE_IPW_SW_MAJOR_VERSION_C != HVM_IP_SW_MAJOR_VERSION) || \
     (AE_IPW_SW_MINOR_VERSION_C != HVM_IP_SW_MINOR_VERSION) || \
     (AE_IPW_SW_PATCH_VERSION_C != HVM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ae_Ipw.c and Hvm_Ip.h are different"
#endif

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


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief         Initializes the Aec Driver
* @details       The configuration pointer is internally stored and
*                the driver is initialized.
* @retval        E_OK success to initialize.
*                E_NOT_OK failed to initialize.
*/
Std_ReturnType  Ae_Ipw_Init(const Ae_Ipw_ConfigType *pConfig)
{
    Aec_Ip_StatusType AecStatus;
    Hvm_Ip_StatusType HvmStatus;

    AecStatus = Aec_Ip_Init(pConfig->Ae_Ipw_pAecConfig);
    HvmStatus = Hvm_Ip_Init(pConfig->Ae_Ipw_pHvmConfig);

    return (((AEC_STATUS_SUCCESS == AecStatus) && (HVM_STATUS_SUCCESS == HvmStatus))? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}
/**
* @brief         Read value to indexed register.
* @param[in]     RegAddr Register address to read from.
* @param[out]     RegValue Value need to read from register.
*
* @retval        E_OK success to read.
*                E_NOT_OK failed to read.
*/
Std_ReturnType Ae_Ipw_ReadReg ( \
                        const uint32 RegAddr, \
                        uint8 DataWidth, \
                        uint32 * const RegValue \
                        )
{

    return ((AEC_STATUS_SUCCESS == Aec_Ip_SpiRead(RegAddr, DataWidth, RegValue))? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}

/*================================================================================================*/
/**
* @brief         Write value to indexed register.
* @param[in]     RegAddr Register address to write to.
* @param[in]     RegValue Value need to write to register.
*
* @retval        E_OK success to read.
*                E_NOT_OK failed to read.
*/
Std_ReturnType Ae_Ipw_WriteReg ( \
                        const uint32 RegAddr, \
                        uint8 DataWidth, \
                        uint32 RegValue \
                        )
{
    return ((AEC_STATUS_SUCCESS == Aec_Ip_SpiWrite(RegAddr, DataWidth, RegValue))? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}

/*================================================================================================*/

/**
 * @brief Verify for correctness the received frame counter or just read number of frames.
 *
 * @param[in]     IsVerify want to verify for correctness for frame counter.
 * @param[in]     ExpectedFrameCount Number of frame expected get.
 * @param[out]    ActualFrameCount Number of frame get in real.
 *
 * @return TRUE if verify correct.
 */
boolean Ae_Ipw_Frame_Counter( boolean IsVerify,
                              uint8 ExpectedFrameCount,
                              uint8 *ActualFrameCount
                            )
{
    return Aec_Ip_Spi_Frame_Counter(IsVerify, ExpectedFrameCount, ActualFrameCount);
}

/*================================================================================================*/
/*!
 * @brief Return status of global health.
 *
 */
uint16 Ae_Ipw_DecodeGlobalHealthStatus(void)
{
    return Aec_Ip_DecodeGlobalHealthStatus();
}

/*================================================================================================*/
/**
* @brief         Initializes the configuration for analog input for measurement.
* @details       Base on configuration to select analog input, HVI channel, divider if high voltage input selected.
*
* @param[in]     pHviHighVoltConfig Pointer to configuration for High Voltage Input.
* @param[in]     AnalogInputSelect Type of analog input.
*
* @return        HVM_STATUS_SUCCESS The initialization was successful.
*/
Std_ReturnType  Ae_Ipw_AdcMeasureConfig(const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                        Ae_AnalogInputType AnalogInputSelect
                                        )
{
    return ((HVM_STATUS_SUCCESS == Hvm_Ip_AdcMeasureConfig(pHviHighVoltConfig, AnalogInputSelect))? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
}

/*================================================================================================*/

/**
* @brief         Initializes the configuration for digital input.
* @details       Initializes the configuration for digital input include: voltage input source, divider, mode polling or interrupt used.
*
* @param[in]     pHviConfig HVI channels configuration.
*
* @retval        HVM_STATUS_SUCCESS The initialization was successful.
*/
Std_ReturnType  Ae_Ipw_DigitalInputEventConfig(const Ae_HviChannelConfig *pAeHviChannelConfig)
{
    /* Elements of struct is same */
    return ((HVM_STATUS_SUCCESS == Hvm_Ip_DigitalInputEventConfig(pAeHviChannelConfig))? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief         Initializes the configuration for Voltage Monitor.
* @details       Initializes the configuration for High/Low voltage detect.
*
* @param[in]     pAeVmConfig       Pointer to configuration of VM.
* @param[in]     pHighVoltageInput Pointer to configuration of High Voltage Input.
*
* @retval        HVM_STATUS_SUCCESS The initialization was successful.
*/
Std_ReturnType  Ae_Ipw_VoltageMonitorConfig(const Ae_VmConfig *pAeVmConfig,
                                            const Ae_HviHighVoltageInputConfig *pHighVoltageInput
                                            )
{
    return ((HVM_STATUS_SUCCESS == Hvm_Ip_VoltageMonitorConfig(pAeVmConfig, pHighVoltageInput))? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
}
/*================================================================================================*/
/*!
 * @brief Check and clear interrupt flag used in interrupt mode.
 *
 */
void Ae_Ipw_FaultsEventsProccess(void)
{
    Hvm_Ip_FaultsEventsProccess();
}

/*================================================================================================*/
/*!
 * @brief Check status flag used in polling mode for digital input, high/low voltage detect.
 *
 */
void Ae_Ipw_ReadFaultsEventsStatus(void)
{
    Hvm_Ip_ReadFaultsEventsStatus();
}

/*================================================================================================*/
/**
 * @brief Enable/Disable read after write.
 */
void Ae_Ipw_SetRaw(boolean Activate)
{
    Aec_Ip_SetRaw(Activate);
}

#if(STD_ON == AEC_IP_USE_NMI_INTERRUPT)
void Ae_Ipw_NMISetupEventFaultHandler(void)
{
    /* Disable NMI and trigger an interrupt */
    Aec_Ip_NMISetupEventFaultHandler();
}

void Ae_Ipw_InterruptSetupEventFaultHandler(void)
{
    /* Enable NMI and execute Events/Faults */
    Aec_Ip_InterruptSetupEventFaultHandler();
}
#endif

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
