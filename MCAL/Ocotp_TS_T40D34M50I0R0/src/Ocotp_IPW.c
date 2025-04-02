/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : MEM_OTP_IP
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
*   @addtogroup OCOTP
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
#include "CDD_Ocotp.h"
#include "Ocotp_IPW.h"
#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IPW_VENDOR_ID_C                           43
#define OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C            7
#define OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define OCOTP_IPW_SW_MAJOR_VERSION_C                    5
#define OCOTP_IPW_SW_MINOR_VERSION_C                    0
#define OCOTP_IPW_SW_PATCH_VERSION_C                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Ocotp.h header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID_C != CDD_OCOTP_VENDOR_ID)
    #error "Ocotp_IPW.c and CDD_Ocotp.h have different vendor ids"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same AutoSar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MAJOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MINOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_OCOTP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and CDD_Ocotp.h are different"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION_C != CDD_OCOTP_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION_C != CDD_OCOTP_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION_C != CDD_OCOTP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and CDD_Ocotp.h are different"
#endif

/* Check if current file and Ocotp_IPW.h header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID_C != OCOTP_IPW_VENDOR_ID)
    #error "Ocotp_IPW.c and Ocotp_IPW.h have different vendor ids"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same AutoSar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C != OCOTP_IPW_AR_RELEASE_MAJOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C != OCOTP_IPW_AR_RELEASE_MINOR_VERSION ) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C != OCOTP_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and Ocotp_IPW.h are different"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION_C != OCOTP_IPW_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION_C != OCOTP_IPW_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION_C != OCOTP_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and Ocotp_IPW.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ocotp_IPW.c and Det.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
* @brief         The function initializes Mem_Otp_Ip module
* @details       The function initializes Mem_Otp_Ip module
*
* @param[in]     pConfig pointer points to configuration structure.
*/
void Ocotp_IPW_Init(const Ocotp_ConfigType *pConfig)
{
    /* Call Mem_Otp_Ip_Init to initialize Ocotp Module */
    Mem_Otp_Ip_Init(pConfig->pHwConfig);
    return;
}

/************************/

void Ocotp_IPW_Deinit(void)
{
    /* Call Mem_Otp_Ip_DeInit to de-initialize Ocotp Module */
    Mem_Otp_Ip_DeInit(Ocotp_pConfigPtr->pHwConfig->ocotpInstance);
    return;
}

#if (OCOTP_READ_EFUSE_API == STD_ON)
Std_ReturnType Ocotp_IPW_ReadEFuse(const Ocotp_ChannelConfigType *pChannelCfg,
                                   uint32 *data
                                  )
{
    Mem_Otp_Ip_StatusType eStatus;
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

    /* Call Mem_Otp_Ip_ReadOTPMem to read data from the Mem Otp */
    eStatus = Mem_Otp_Ip_ReadOTPMem(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_MirrorAddress, data);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_10);
#if (OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (STATUS_MEM_OTP_IP_BUSY == eStatus)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_BUSY);
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    if (STATUS_MEM_OTP_IP_ERROR == eStatus)
    {
        (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_READ_FAILED);
    }
    if (STATUS_MEM_OTP_IP_ERROR_TIMEOUT == eStatus)
    {
        (void)Det_ReportRuntimeError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_TIMEOUT);
    }
    if (STATUS_MEM_OTP_IP_SUCCESS == eStatus)
    {
        eRetVal = (Std_ReturnType)E_OK;
    }

    return eRetVal;
}
#endif /* OCOTP_READ_EFUSE_API == STD_ON */

#if (OCOTP_GET_STATUS_API == STD_ON)
void Ocotp_IPW_GetStatus(const Mem_Otp_Ip_ConfigType *pHwCfg,
                         Ocotp_StatusType *pStatus
                        )
{
    Mem_Otp_Ip_StatusType eStatus;
    /* Get status of IP */
    eStatus = Mem_Otp_Ip_GetBusyState(pHwCfg->ocotpInstance);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_11);
    if (STATUS_MEM_OTP_IP_BUSY == eStatus)
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_BUSY;
    }
    else if (STATUS_MEM_OTP_IP_ERROR == eStatus)
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_ERROR;
    }
    else
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_IDLE;
    }
    return;
}
#endif /* OCOTP_GET_STATUS_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
