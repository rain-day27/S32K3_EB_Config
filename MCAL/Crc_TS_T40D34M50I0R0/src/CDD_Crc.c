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
*   @file    CDD_Crc.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup CRC_HLD_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Crc.h"
#include "Crc_Ipw.h"
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    #include "Det.h"
#endif
#if (STD_ON == CRC_MULTIPARTITION_SUPPORT_ENABLED)
    #include "OsIf.h"
#endif

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Crc driver header file and also in the
*        module's description file
*/
#define CRC_VENDOR_ID_C                    43
#define CRC_AR_RELEASE_MAJOR_VERSION_C     4
#define CRC_AR_RELEASE_MINOR_VERSION_C     7
#define CRC_AR_RELEASE_REVISION_VERSION_C  0
#define CRC_SW_MAJOR_VERSION_C             5
#define CRC_SW_MINOR_VERSION_C             0
#define CRC_SW_PATCH_VERSION_C             0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if source file and Crc header file are of the same vendor */
#if (CRC_VENDOR_ID_C != CDD_CRC_VENDOR_ID)
    #error "CDD_Crc.c and CDD_Crc.h have different vendor ids"
#endif

/* Check if source file and Crc header file are of the same Autosar version */
#if ((CRC_AR_RELEASE_MAJOR_VERSION_C    != CDD_CRC_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_AR_RELEASE_MINOR_VERSION_C    != CDD_CRC_AR_RELEASE_MINOR_VERSION) || \
     (CRC_AR_RELEASE_REVISION_VERSION_C != CDD_CRC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crc.c and CDD_Crc.h are different"
#endif

/* Check if source file and Crc header file are of the same Software version */
#if ((CRC_SW_MAJOR_VERSION_C != CDD_CRC_SW_MAJOR_VERSION) || \
     (CRC_SW_MINOR_VERSION_C != CDD_CRC_SW_MINOR_VERSION) || \
     (CRC_SW_PATCH_VERSION_C != CDD_CRC_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crc.c and CDD_Crc.h are different"
#endif

/* Check if source file and CRC_Ipw.h file are of the same vendor */
#if (CRC_VENDOR_ID_C != CRC_IPW_VENDOR_ID)
    #error "CDD_Crc.c and CRC_Ipw.h have different vendor ids"
#endif

/* Check if the source file and CRC_Ipw.h file are of the same Autosar version */
#if ((CRC_AR_RELEASE_MAJOR_VERSION_C    != CRC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_AR_RELEASE_MINOR_VERSION_C    != CRC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CRC_AR_RELEASE_REVISION_VERSION_C != CRC_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crc.c and CRC_Ipw.h are different"
#endif

/* Check if source file and Crc header file are of the same Software version */
#if ((CRC_SW_MAJOR_VERSION_C != CRC_IPW_SW_MAJOR_VERSION) || \
     (CRC_SW_MINOR_VERSION_C != CRC_IPW_SW_MINOR_VERSION) || \
     (CRC_SW_PATCH_VERSION_C != CRC_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crc.c and CRC_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Det.h file are of the same Autosar version */
    #if (STD_ON == CRC_DET_IS_AVAILABLE)
        #if ((CRC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (CRC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CDD_Crc.c and Det.h are different"
        #endif
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Osif.h file are of the same Autosar version */
    #if (STD_ON == CRC_MULTIPARTITION_SUPPORT_ENABLED)
        #if ((CRC_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (CRC_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CDD_Crc.c and OsIf.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == CRC_MULTIPARTITION_SUPPORT_ENABLED)
    #define Crc_GetUserId()            OsIf_GetUserId()
#else
    #define Crc_GetUserId()            (CRC_CORE_DEFAULT)
#endif /* #if (CRC_MULTIPARTITION_SUPPORT_ENABLED == STD_ON) */
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/
#define CRC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Crc_MemMap.h"
/**
* @brief          Global Configuration Pointer.
* @details        Data structure containing the set of configuration parameters required for
*                 initializing the CRC Driver
*/
static const Crc_InitType * s_pxCrcInit;
#define CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Crc_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

#if (STD_ON == CRC_DET_IS_AVAILABLE)
/**
 * @brief      This function reports an development error to the Det module and records the failure in the local structure.
 * @details    This function reports an development error to the Det module and records the failure in the local structure.
 *
 * @param[in]  ServiceId       The service id of the caller function
 * @param[in]  ErrorId         The error id to be reported
 */
static inline void Crc_ReportDetError(uint8 ServiceId,
                                      uint8 ErrorId
                                     )
{
    (void)Det_ReportError((uint16)CDD_CRC_MODULE_ID, CRC_INSTANCE_ID, ServiceId, ErrorId);
}

/**
 * @brief      This function check channel Invalid
 * @details    This function check channel Invalid
 *
 * @param[in]  Channel       The service id of the caller function
 */
static inline boolean Crc_CheckChannelInvalid(const uint32 Channel,
                                              uint8 ServiceId
                                             )
{
    boolean Status      = FALSE;
    uint32 IndexChannel = 0U;
    const Crc_PartitionType *ConfigPartition;

#if (CRC_MULTIPARTITION_SUPPORT_ENABLED == STD_ON)
    uint8 UserId  = (uint8)Crc_GetUserId();
    ConfigPartition = (const Crc_PartitionType *)Crc_pxPartitionConfig[UserId];
#else
    ConfigPartition = (const Crc_PartitionType *)&Crc_xConfigPartition;
#endif

    if (CRC_NUM_CHANNEL_MAX <= Channel)
    {
        Crc_ReportDetError(ServiceId, CRC_E_INVALID_CHANNEL);
    }
    else
    {
        for (IndexChannel = 0U; IndexChannel < ConfigPartition->ChannelMax; IndexChannel++)
        {
            if (ConfigPartition->ChannelList[IndexChannel] == Channel)
            {
                Status = TRUE;
                break;
            }
        }
        if (FALSE == Status)
        {
            Crc_ReportDetError(ServiceId, CRC_E_INVALID_CHANNEL);
        }
    }

    return Status;
}
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the CRC Driver settings based on user configuration.
 * @implements    Crc_Init_Activity
 */
void Crc_Init(const Crc_InitType * ConfigPtr)
{
#if (STD_ON == CRC_PRECOMPILE_SUPPORT)
    #if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR != ConfigPtr)
    {
        Crc_ReportDetError(CRC_INIT_ID, CRC_E_INIT_FAILED);
    }
    else
    {
    #else
        (void)ConfigPtr;
    #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        s_pxCrcInit = &Crc_xConfigInit;
        /* Init driver */
        Crc_Ipw_Init(s_pxCrcInit->pxCrcIpConfigInit);
    #if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
    #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
#endif /* #if (STD_ON == CRC_PRECOMPILE_SUPPORT) */
}


/**
 * @brief         This function initializes the CRC Channel configuration by LogicChannel's info
 * @implements    Crc_SetChannelConfig_Activity
 */
void Crc_SetChannelConfig(const uint32 Channel,
                          const Crc_ChannelConfigType *pxChannelConfig
                         )
{
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (Crc_CheckChannelInvalid(Channel, CRC_SETCHANNELCONFIG_ID))
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        Crc_Ipw_SetChannelConfig(Channel, pxChannelConfig);
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
}


/**
 * @brief         This function shall start algorithm calculate CRC
 * @implements    Crc_SetChannelCalculate_Activity
 */
uint64 Crc_SetChannelCalculate(const uint32 Channel,
                               const uint8 * pCrcData,
                               const uint32 CrcLength,
                               const uint64 CrcStartValue,
                               const boolean IsFirstCall
                              )
{
    uint64 Result = 0U;

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (Crc_CheckChannelInvalid(Channel, CRC_SETCHANNELCALCULATE_ID))
    {
        if (NULL_PTR == pCrcData)
        {
            Crc_ReportDetError(CRC_SETCHANNELCALCULATE_ID, CRC_E_INVALID_POINTER);
        }
        else
        {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
            Result = Crc_Ipw_SetChannelCalculate(Channel, pCrcData, CrcLength, CrcStartValue, IsFirstCall);
#if (STD_ON == CRC_DET_IS_AVAILABLE)
        }
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}


/**
 * @brief         This function get result CRC after finish calculated.
 * @implements    Crc_GetChannelResult_Activity
 */
uint64 Crc_GetChannelResult(const uint32 Channel)
{
    uint64 Result = 0U;

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (Crc_CheckChannelInvalid(Channel, CRC_GETCHANNELRESULT_ID))
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        Result = Crc_Ipw_GetChannelResult(Channel);
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
    return Result;
}


#if (STD_ON  == CRC_AUTOSAR_LIBRARY_IS_AVAILABLE)
/**
 * @brief         This function calculates CRC8 and returns the result
 * @implements    Crc_CalculateCRC8_Activity
 */
uint8 Crc_CalculateCRC8(const uint8 *Crc_DataPtr,
                        uint32 Crc_Length,
                        uint8 Crc_StartValue8,
                        boolean Crc_IsFirstCall
                       )
{
    uint8 Result      = 0U;
    uint8 UserId    = (uint8)Crc_GetUserId();
    /* Initialized values to avoid Misra violation 9.1 */
    Crc_ChannelConfigType xChannelConfig = {CRC_PROTOCOL_8BIT_CUSTOM,0U,FALSE,FALSE,FALSE,FALSE,FALSE, NULL_PTR};

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Crc_DataPtr)
    {
        Crc_ReportDetError(CRC_CALCULATECRC8_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        if (CRC_IP_CHANNEL_INVALID_U32 == Crc_au32Crc8BitSaeJ1850[UserId])
        {
            #if (STD_ON == CRC_DET_IS_AVAILABLE)
            /* CPR_RTD_00420.crc */
            Crc_ReportDetError(CRC_CALCULATECRC8_ID, CRC_E_PARAM_CONFIG);
            #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        }
        else
        {
            xChannelConfig.Protocol = CRC_PROTOCOL_8BIT_SAE_J1850;
            Crc_Ipw_SetChannelConfig(Crc_au32Crc8BitSaeJ1850[UserId], &xChannelConfig);
            Result = (uint8)Crc_Ipw_SetChannelCalculate(Crc_au32Crc8BitSaeJ1850[UserId],
                                                        Crc_DataPtr,
                                                        Crc_Length,
                                                        Crc_StartValue8,
                                                        Crc_IsFirstCall
                                                    );
        }
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}


/**
 * @brief         This function calculates CRC8H2F and returns the result
 * @implements    Crc_CalculateCRC8H2F_Activity
 */
uint8 Crc_CalculateCRC8H2F(const uint8 *Crc_DataPtr,
                           uint32 Crc_Length,
                           uint8 Crc_StartValue8H2F,
                           boolean Crc_IsFirstCall
                          )
{
    uint8 Result = 0U;
    uint8 UserId = (uint8)Crc_GetUserId();
    /* Initialized values to avoid Misra violation 9.1 */
    Crc_ChannelConfigType xChannelConfig = {CRC_PROTOCOL_8BIT_CUSTOM,0U,FALSE,FALSE,FALSE,FALSE,FALSE, NULL_PTR};

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Crc_DataPtr)
    {
        Crc_ReportDetError(CRC_CALCULATECRC8H2F_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        if (CRC_IP_CHANNEL_INVALID_U32 == Crc_au32Crc8BitH2f[UserId])
        {
            #if (STD_ON == CRC_DET_IS_AVAILABLE)
            /* CPR_RTD_00420.crc */
            Crc_ReportDetError(CRC_CALCULATECRC8H2F_ID, CRC_E_PARAM_CONFIG);
            #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        }
        else
        {
            xChannelConfig.Protocol = CRC_PROTOCOL_8BIT_H2F;
            Crc_Ipw_SetChannelConfig(Crc_au32Crc8BitH2f[UserId], &xChannelConfig);
            Result = (uint8)Crc_Ipw_SetChannelCalculate(Crc_au32Crc8BitH2f[UserId],
                                                        Crc_DataPtr,
                                                        Crc_Length,
                                                        Crc_StartValue8H2F,
                                                        Crc_IsFirstCall
                                                    );
        }
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}


/**
 * @brief         This function calculates CRC16 and returns the result
 * @implements    Crc_CalculateCRC16_Activity
 */
uint16 Crc_CalculateCRC16(const uint8 *Crc_DataPtr,
                          uint32 Crc_Length,
                          uint16 Crc_StartValue16,
                          boolean Crc_IsFirstCall
                         )
{
    uint16 Result = 0U;
    uint8 UserId = (uint8)Crc_GetUserId();
    /* Initialized values to avoid Misra violation 9.1 */
    Crc_ChannelConfigType xChannelConfig = {CRC_PROTOCOL_8BIT_CUSTOM,0U,FALSE,FALSE,FALSE,FALSE,FALSE, NULL_PTR};

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Crc_DataPtr)
    {
        Crc_ReportDetError(CRC_CALCULATECRC16_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        if (CRC_IP_CHANNEL_INVALID_U32 == Crc_au32Crc16BitCcittFalse[UserId])
        {
            #if (STD_ON == CRC_DET_IS_AVAILABLE)
            /* CPR_RTD_00420.crc */
            Crc_ReportDetError(CRC_CALCULATECRC16_ID, CRC_E_PARAM_CONFIG);
            #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        }
        else
        {

            xChannelConfig.Protocol = CRC_PROTOCOL_16BIT_CCITT_FALSE;
            Crc_Ipw_SetChannelConfig(Crc_au32Crc16BitCcittFalse[UserId], &xChannelConfig);
            Result = (uint16)Crc_Ipw_SetChannelCalculate(Crc_au32Crc16BitCcittFalse[UserId],
                                                         Crc_DataPtr,
                                                         Crc_Length,
                                                         Crc_StartValue16,
                                                         Crc_IsFirstCall
                                                        );
        }
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}


/**
 * @brief         This function calculates CRC16ARC and returns the result
 * @implements    Crc_CalculateCRC16ARC_Activity
 */
uint16 Crc_CalculateCRC16ARC(const uint8 *Crc_DataPtr,
                             uint32 Crc_Length,
                             uint16 Crc_StartValue16,
                             boolean Crc_IsFirstCall
                            )
{
    uint16 Result = 0U;
    uint8 UserId = (uint8)Crc_GetUserId();
    /* Initialized values to avoid Misra violation 9.1 */
    Crc_ChannelConfigType xChannelConfig = {CRC_PROTOCOL_8BIT_CUSTOM,0U,FALSE,FALSE,FALSE,FALSE,FALSE, NULL_PTR};

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Crc_DataPtr)
    {
        Crc_ReportDetError(CRC_CALCULATECRC16ARC_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        if (CRC_IP_CHANNEL_INVALID_U32 == Crc_au32Crc16BitArc[UserId])
        {
            #if (STD_ON == CRC_DET_IS_AVAILABLE)
            /* CPR_RTD_00420.crc */
            Crc_ReportDetError(CRC_CALCULATECRC16ARC_ID, CRC_E_PARAM_CONFIG);
            #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        }
        else
        {
            xChannelConfig.Protocol = CRC_PROTOCOL_16BIT_ARC;
            Crc_Ipw_SetChannelConfig(Crc_au32Crc16BitArc[UserId], &xChannelConfig);
            Result = (uint16)Crc_Ipw_SetChannelCalculate(Crc_au32Crc16BitArc[UserId],
                                                         Crc_DataPtr,
                                                         Crc_Length,
                                                         Crc_StartValue16,
                                                         Crc_IsFirstCall
                                                        );
        }
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}


/**
 * @brief         This function calculates CRC32 and returns the result
 * @implements    Crc_CalculateCRC32_Activity
 */
uint32 Crc_CalculateCRC32(const uint8 *Crc_DataPtr,
                          uint32 Crc_Length,
                          uint32 Crc_StartValue32,
                          boolean Crc_IsFirstCall
                         )
{
    uint32 Result = 0U;
    uint8 UserId = (uint8)Crc_GetUserId();
    /* Initialized values to avoid Misra violation 9.1 */
    Crc_ChannelConfigType xChannelConfig = {CRC_PROTOCOL_8BIT_CUSTOM,0U,FALSE,FALSE,FALSE,FALSE,FALSE, NULL_PTR};

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Crc_DataPtr)
    {
        Crc_ReportDetError(CRC_CALCULATECRC32_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        if (CRC_IP_CHANNEL_INVALID_U32 == Crc_au32Crc32BitEthernet[UserId])
        {
            #if (STD_ON == CRC_DET_IS_AVAILABLE)
            /* CPR_RTD_00420.crc */
            Crc_ReportDetError(CRC_CALCULATECRC32_ID, CRC_E_PARAM_CONFIG);
            #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        }
        else
        {
            xChannelConfig.Protocol = CRC_PROTOCOL_32BIT_ETHERNET;
            Crc_Ipw_SetChannelConfig(Crc_au32Crc32BitEthernet[UserId], &xChannelConfig);
            Result = (uint32)Crc_Ipw_SetChannelCalculate(Crc_au32Crc32BitEthernet[UserId],
                                                         Crc_DataPtr,
                                                         Crc_Length,
                                                         Crc_StartValue32,
                                                         Crc_IsFirstCall
                                                        );
        }
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}


/**
 * @brief         This function calculates CRC32P4 and returns the result
 * @implements    Crc_CalculateCRC32P4_Activity
 */
uint32 Crc_CalculateCRC32P4(const uint8 *Crc_DataPtr,
                            uint32 Crc_Length,
                            uint32 Crc_StartValue32,
                            boolean Crc_IsFirstCall
                           )
{
    uint32 Result  = 0U;
    uint8 UserId = (uint8)Crc_GetUserId();
    /* Initialized values to avoid Misra violation 9.1 */
    Crc_ChannelConfigType xChannelConfig = {CRC_PROTOCOL_8BIT_CUSTOM,0U,FALSE,FALSE,FALSE,FALSE,FALSE, NULL_PTR};

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Crc_DataPtr)
    {
        Crc_ReportDetError(CRC_CALCULATECRC32P4_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        if (CRC_IP_CHANNEL_INVALID_U32 == Crc_au32Crc32BitE2ep4[UserId])
        {
            #if (STD_ON == CRC_DET_IS_AVAILABLE)
            /* CPR_RTD_00420.crc */
            Crc_ReportDetError(CRC_CALCULATECRC32P4_ID, CRC_E_PARAM_CONFIG);
            #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        }
        else
        {

            xChannelConfig.Protocol = CRC_PROTOCOL_32BIT_E2E_P4;
            Crc_Ipw_SetChannelConfig(Crc_au32Crc32BitE2ep4[UserId], &xChannelConfig);
            Result = (uint32)Crc_Ipw_SetChannelCalculate(Crc_au32Crc32BitE2ep4[UserId],
                                                         Crc_DataPtr,
                                                         Crc_Length,
                                                         Crc_StartValue32,
                                                         Crc_IsFirstCall
                                                        );
        }
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}

/**
 * @brief         This function calculates CRC64 and returns the result
 * @implements    Crc_CalculateCRC64_Activity
 */
uint64 Crc_CalculateCRC64(const uint8 *Crc_DataPtr,
                          uint32 Crc_Length,
                          uint64 Crc_StartValue64,
                          boolean Crc_IsFirstCall
                         )
{
    uint64 Result  = 0U;
    uint8 UserId = (uint8)Crc_GetUserId();
    /* Initialized values to avoid Misra violation 9.1 */
    Crc_ChannelConfigType xChannelConfig = {CRC_PROTOCOL_8BIT_CUSTOM,0U,FALSE,FALSE,FALSE,FALSE,FALSE, NULL_PTR};

#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Crc_DataPtr)
    {
        Crc_ReportDetError(CRC_CALCULATECRC64_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        if (CRC_IP_CHANNEL_INVALID_U32 == Crc_au32Crc64BitEcma[UserId])
        {
            #if (STD_ON == CRC_DET_IS_AVAILABLE)
            /* CPR_RTD_00420.crc */
            Crc_ReportDetError(CRC_CALCULATECRC64_ID, CRC_E_PARAM_CONFIG);
            #endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        }
        else
        {

            xChannelConfig.Protocol = CRC_PROTOCOL_64BIT_ECMA;
            Crc_Ipw_SetChannelConfig(Crc_au32Crc64BitEcma[UserId], &xChannelConfig);
            Result = (uint64)Crc_Ipw_SetChannelCalculate(Crc_au32Crc64BitEcma[UserId],
                                                         Crc_DataPtr,
                                                         Crc_Length,
                                                         Crc_StartValue64,
                                                         Crc_IsFirstCall
                                                        );
        }
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */

    return Result;
}
#endif /* #if (STD_ON  == CRC_AUTOSAR_LIBRARY_IS_AVAILABLE) */


#if (STD_ON == CRC_VERSION_INFO_API_ENABLE)
/**
 * @brief         Returns the version information of this module
 * @implements    Crc_GetVersionInfo_Activity
 */
void Crc_GetVersionInfo(Std_VersionInfoType *Versioninfo)
{
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    if (NULL_PTR == Versioninfo)
    {
        Crc_ReportDetError(CRC_GETVERSIONINFO_ID, CRC_E_INVALID_POINTER);
    }
    else
    {
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
        Versioninfo->vendorID         = (uint16)CDD_CRC_VENDOR_ID;
        Versioninfo->moduleID         = (uint16)CDD_CRC_MODULE_ID;
        Versioninfo->sw_major_version = (uint8)CDD_CRC_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = (uint8)CDD_CRC_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = (uint8)CDD_CRC_SW_PATCH_VERSION;
#if (STD_ON == CRC_DET_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_DET_IS_AVAILABLE) */
}
#endif /* #if (STD_ON == CRC_VERSION_INFO_API_ENABLE) */


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
