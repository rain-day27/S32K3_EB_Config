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
*   @file CDD_Zipwire.c
*
*   @addtogroup ZIPWIRE_HLD_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Zipwire.h"

#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
#include "Det.h"
#endif

#if (STD_ON == ZIPWIRE_MULTIPARTITION_SUPPORT_ENABLED)
    #include "OsIf.h"
#endif
/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Zipwire driver header file and also in the
*        module's description file
*/
#define ZIPWIRE_VENDOR_ID_C                   43
#define ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C    4
#define ZIPWIRE_AR_RELEASE_MINOR_VERSION_C    7
#define ZIPWIRE_AR_RELEASE_REVISION_VERSION_C 0
#define ZIPWIRE_SW_MAJOR_VERSION_C            5
#define ZIPWIRE_SW_MINOR_VERSION_C            0
#define ZIPWIRE_SW_PATCH_VERSION_C            0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if source file and Zipwire header file are of the same vendor */
#if (ZIPWIRE_VENDOR_ID_C != CDD_ZIPWIRE_VENDOR_ID)
#error "CDD_Zipwire.c and CDD_Zipwire.h have different vendor ids"
#endif

/* Check if source file and Zipwire header file are of the same Autosar version */
#if ((ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C != CDD_ZIPWIRE_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_AR_RELEASE_MINOR_VERSION_C != CDD_ZIPWIRE_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_AR_RELEASE_REVISION_VERSION_C != CDD_ZIPWIRE_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CDD_Zipwire.c and CDD_Zipwire.h are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_SW_MAJOR_VERSION_C != CDD_ZIPWIRE_SW_MAJOR_VERSION) || \
    (ZIPWIRE_SW_MINOR_VERSION_C != CDD_ZIPWIRE_SW_MINOR_VERSION) || \
    (ZIPWIRE_SW_PATCH_VERSION_C != CDD_ZIPWIRE_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of CDD_Zipwire.c and CDD_Zipwire.h are different"
#endif

/* Check if source file and Zipwire_Ipw.h file are of the same vendor */
#if (ZIPWIRE_VENDOR_ID_C != ZIPWIRE_IPW_VENDOR_ID)
#error "CDD_Zipwire.c and Zipwire_Ipw.h have different vendor ids"
#endif

/* Check if the source file and Zipwire_Ipw.h file are of the same Autosar version */
#if ((ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IPW_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IPW_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CDD_Zipwire.c and Zipwire_Ipw.h are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_SW_MAJOR_VERSION_C != ZIPWIRE_IPW_SW_MAJOR_VERSION) || \
    (ZIPWIRE_SW_MINOR_VERSION_C != ZIPWIRE_IPW_SW_MINOR_VERSION) || \
    (ZIPWIRE_SW_PATCH_VERSION_C != ZIPWIRE_IPW_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of CDD_Zipwire.c and Zipwire_Ipw.h are different"
#endif

#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if the source file and Zipwire_Ipw.h file are of the same Autosar version */
#if ((ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_AR_RELEASE_REVISION_VERSION_C != DET_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CDD_Zipwire.c and Det.h are different"
#endif

/* Check if source file and Zipwire header file are of the same Software version */
#if ((ZIPWIRE_SW_MAJOR_VERSION_C != DET_SW_MAJOR_VERSION) || \
    (ZIPWIRE_SW_MINOR_VERSION_C != DET_SW_MINOR_VERSION) || \
    (ZIPWIRE_SW_PATCH_VERSION_C != DET_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of CDD_Zipwire.c and Det.h are different"
#endif
#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Osif.h file are of the same Autosar version */
    #if (STD_ON == ZIPWIRE_MULTIPARTITION_SUPPORT_ENABLED)
        #if ((ZIPWIRE_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (ZIPWIRE_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CDD_Zipwire.c and OsIf.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == ZIPWIRE_MULTIPARTITION_SUPPORT_ENABLED)
    #define Zipwire_GetUserId()            OsIf_GetUserId()
#else
    #define Zipwire_GetUserId()            (ZIPWIRE_CORE_DEFAULT)
#endif /* #if (ZIPWIRE_MULTIPARTITION_SUPPORT_ENABLED == STD_ON) */
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define ZIPWIRE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Zipwire_MemMap.h"
/**
* @brief          Global Configuration Pointer.
* @details        Data structure containing the set of configuration parameters required for
*                 initializing the ZIPWIRE Driver Instances.
*/
static const Zipwire_InitType * s_pxZipwireInit;


#define ZIPWIRE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Zipwire_MemMap.h"
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
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
/**
 * @brief      This function reports an development error to the Det module and records the failure in the local structure.
 * @details    This function reports an development error to the Det module and records the failure in the local structure.
 *
 * @param[in]  ServiceId       The service id of the caller function
 * @param[in]  ErrorId         The error id to be reported
 */
static inline void Zipwire_ReportDetError(uint8 ServiceId,
                                          uint8 ErrorId)
{
    (void)Det_ReportError((uint16)CDD_ZIPWIRE_MODULE_ID, ZIPWIRE_INSTANCE_ID, ServiceId, ErrorId);
}
#endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */

static inline boolean Zipwire_CheckInit(uint8 ServiceId, const Zipwire_InitType * ConfigPtr)
{
    boolean Status     = TRUE;
    uint32 IndexInstance;
    const Zipwire_PartitionType *ConfigPartition;
    
    #if (STD_OFF == ZIPWIRE_DET_IS_AVAILABLE)
    (void)ServiceId;
    #endif

#if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT)
        if (NULL_PTR != ConfigPtr)
        {
            #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
                Zipwire_ReportDetError(ZIPWIRE_INIT_ID, ZIPWIRE_E_INIT_FAILED);
            #endif
            Status = FALSE;
        }
        else
        {
        (void)ConfigPtr;
        }
#endif /* #if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT) */
 
 
#if (ZIPWIRE_MULTIPARTITION_SUPPORT_ENABLED == STD_ON)
    uint8 UserId  = (uint8)Zipwire_GetUserId();
    ConfigPartition = (const Zipwire_PartitionType *)Zipwire_pxPartitionConfig[UserId];
#else
    ConfigPartition = (const Zipwire_PartitionType *)&Zipwire_xConfigPartition;
#endif
    for (IndexInstance = 0U; IndexInstance < ConfigPartition->InstanceMax; IndexInstance++)
    {
        if (ZipwireIpInitState[ConfigPartition->InstanceUsed[IndexInstance]] == ZIPWIRE_INIT)
        {
            #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
                Zipwire_ReportDetError(ServiceId, ZIPWIRE_E_ALREADY_INITIALIZED);
            #endif
            Status = FALSE;
            break;
        }
    }
    return Status;
}

/**
 * @brief      This function check if the channel and instance are valid.
 * @details    This function check if the channel and instance are valid.
 *
 * @param[in]  Channel       The service id of the caller function
 */
static inline boolean Zipwire_CheckInvalid(const uint8 Instance,
                                           const uint8 Channel,
                                           uint8 ServiceId
                                           )
{
    boolean Status     = TRUE;
    boolean TempStatus = FALSE;
    uint32 IndexInstance;
    const Zipwire_PartitionType *ConfigPartition;
    Zipwire_StatusType InitStatus;

    #if (STD_OFF == ZIPWIRE_DET_IS_AVAILABLE)
    (void)ServiceId;
    #endif

#if (ZIPWIRE_MULTIPARTITION_SUPPORT_ENABLED == STD_ON)
    uint8 UserId  = (uint8)Zipwire_GetUserId();
    ConfigPartition = (const Zipwire_PartitionType *)Zipwire_pxPartitionConfig[UserId];
#else
    ConfigPartition = (const Zipwire_PartitionType *)&Zipwire_xConfigPartition;
#endif

    if(ZIPWIRE_CHANNEL_PLACEHOLDER != Channel)
    {
        if (ZIPWIRE_CHANNEL_COUNT_U8 <= Channel)
        {
            #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
            Zipwire_ReportDetError(ServiceId, ZIPWIRE_E_INVALID_CHANNEL);
            #endif

            Status = FALSE;
        }
    }

    if (ZIPWIRE_INSTANCE_COUNT_U8 <= Instance)
    {
        #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
        Zipwire_ReportDetError(ServiceId, ZIPWIRE_E_INVALID_INSTANCE);
        #endif
        Status = FALSE;
    }
    else
    {
        for (IndexInstance = 0U; IndexInstance < ConfigPartition->InstanceMax; IndexInstance++)
        {
            if (ConfigPartition->InstanceUsed[IndexInstance] == Instance)
            {
                InitStatus = ZipwireIpInitState[ConfigPartition->InstanceUsed[IndexInstance]];
                if ((ZIPWIRE_UNINIT == InitStatus) || (ZIPWIRE_DEINIT == InitStatus))
                {
                    #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
                    Zipwire_ReportDetError(ServiceId, ZIPWIRE_E_UNINIT);
                    #endif
                    Status = FALSE;
                }

                TempStatus = TRUE;
                break;
            }
        }
        
        if (FALSE == TempStatus)
        {   
            #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
            Zipwire_ReportDetError(ServiceId, ZIPWIRE_E_INVALID_INSTANCE);
            #endif
            Status = FALSE;
        }
    }
    return Status;
}

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

/**
 * @brief         Initializes the ZIPWIRE Driver settings based on user configuration.
 * @implements    Zipwire_Init_Activity
 */
Zipwire_Ip_StatusType Zipwire_Init(const Zipwire_InitType * ConfigPtr)
{
    Zipwire_Ip_StatusType ZipwireStatus = ZIPWIRE_IP_STATUS_ERROR;

    if (Zipwire_CheckInit(ZIPWIRE_INIT_ID, ConfigPtr) == TRUE)
    {
        s_pxZipwireInit = &Zipwire_xConfigInit;
        /* Init driver */
        ZipwireStatus = Zipwire_Ipw_Init(s_pxZipwireInit);
    }
    return ZipwireStatus;
}


/**
 * @brief         Deinitializes the ZIPWIRE Driver.
 * @implements    Zipwire_DeInit_Activity
 */
void Zipwire_DeInit(const Zipwire_InitType * ConfigPtr)
{
#if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT)
#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    if (NULL_PTR != ConfigPtr)
    {
        Zipwire_ReportDetError(ZIPWIRE_DEINIT_ID, ZIPWIRE_E_DEINIT_FAILED);
    }
    else
    {
#else
    (void)ConfigPtr;
#endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
        s_pxZipwireInit = &Zipwire_xConfigInit;
        /* DeInit driver */
        Zipwire_Ipw_DeInit(s_pxZipwireInit);
#if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE)
    }

#endif /* #if (STD_ON == ZIPWIRE_DET_IS_AVAILABLE) */
#endif /* #if (STD_ON == ZIPWIRE_PRECOMPILE_SUPPORT) */
}

/**
 * @brief         Performs multiple read transfers.
 * @implements    Zipwire_Read_Activity
 */
Zipwire_Ip_StatusType Zipwire_Read(uint8 HwInstance, 
                                   uint8 HwChannel, 
                                   Zipwire_Ip_TransferDescriptor *DataArray, 
                                   uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadStatus = ZIPWIRE_IP_STATUS_ERROR;

    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_READ_ID))
    {
        ReadStatus = Zipwire_Ipw_Read(HwInstance, HwChannel, DataArray, DataArrayLength);
    }
    return ReadStatus;
}


/**
 * @brief         Performs multiple read transfers synchronously.
 * @implements    Zipwire_ReadBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_ReadBlocking(uint8 HwInstance, 
                                           uint8 HwChannel, 
                                           Zipwire_Ip_TransferDescriptor *DataArray, 
                                           uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_READBLOCKING_ID))
    {
    ReadBlockingStatus = Zipwire_Ipw_ReadBlocking(HwInstance, HwChannel, DataArray, DataArrayLength);
    }
    return ReadBlockingStatus;
}

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         Performs multiple read transfers with DMA.
 * @implements    Zipwire_ReadDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_ReadDma(uint8 HwInstance, 
                                      uint8 HwChannel, 
                                      const uint32 *DataArray, 
                                      const uint32 *AddressArray, 
                                      uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadDmaStatus = ZIPWIRE_IP_STATUS_ERROR;

    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_READDMA_ID))
    {
    ReadDmaStatus = Zipwire_Ipw_ReadDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    }
    return ReadDmaStatus;
}


/**
 * @brief         Performs multiple read transfers synchronously with DMA.
 * @implements    Zipwire_ReadDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_ReadDmaBlocking(uint8 HwInstance, 
                                              uint8 HwChannel, 
                                              const uint32 *DataArray, 
                                              const uint32 *AddressArray, 
                                              uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadDmaBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_READDMABLOCKING_ID))
    {
    ReadDmaBlockingStatus = Zipwire_Ipw_ReadDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    }
    return ReadDmaBlockingStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

/**
 * @brief         Performs multiple write transfers.
 * @implements    Zipwire_Write_Activity
 */
Zipwire_Ip_StatusType Zipwire_Write(uint8 HwInstance, 
                                    uint8 HwChannel, 
                                    Zipwire_Ip_TransferDescriptor *DataArray, 
                                    uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_WRITE_ID))
    {
    WriteStatus = Zipwire_Ipw_Write(HwInstance, HwChannel, DataArray, DataArrayLength);
    }
    return WriteStatus;
}


/**
 * @brief         Performs multiple write transfers synchronously.
 * @implements    Zipwire_WriteBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_WriteBlocking(uint8 HwInstance, 
                                            uint8 HwChannel, 
                                            Zipwire_Ip_TransferDescriptor *DataArray, 
                                            uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_WRITEBLOCKING_ID))
    {
    WriteBlockingStatus = Zipwire_Ipw_WriteBlocking(HwInstance, HwChannel, DataArray, DataArrayLength);
    }
    return WriteBlockingStatus;
}

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         Performs multiple write transfers with DMA.
 * @implements    Zipwire_WriteDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_WriteDma(uint8 HwInstance, 
                                       uint8 HwChannel, 
                                       const uint32 *DataArray, 
                                       const uint32 *AddressArray, 
                                       uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_WRITEDMA_ID))
    {
    WriteDmaStatus = Zipwire_Ipw_WriteDma(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    }
    return WriteDmaStatus;
}

/**
 * @brief         Performs multiple write transfers synchronously with DMA.
 * @implements    Zipwire_WriteDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_WriteDmaBlocking(uint8 HwInstance, 
                                               uint8 HwChannel, 
                                               const uint32 *DataArray, 
                                               const uint32 *AddressArray, 
                                               uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaBlockingStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_WRITEDMABLOCKING_ID))
    {
    WriteDmaBlockingStatus = Zipwire_Ipw_WriteDmaBlocking(HwInstance, HwChannel, DataArray, AddressArray, DataArrayLength);
    }
    return WriteDmaBlockingStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/**
 * @brief         Performs a synchronous stream write.
 * @implements    Zipwire_StreamWrite_Activity
 */
Zipwire_Ip_StatusType Zipwire_StreamWrite(uint8 HwInstance,
                                          uint8 HwChannel,
                                          Zipwire_Ip_StreamWriteConfig TargetConfig,
                                          const uint32 * Data)
{
    Zipwire_Ip_StatusType StreamWriteStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_STREAMWRITE_ID))
    {
    StreamWriteStatus = Zipwire_Ipw_StreamWrite(HwInstance, HwChannel, TargetConfig, Data);
    }
    return StreamWriteStatus;
}


/**
 * @brief         Performs an ID request transfer.
 * @implements    Zipwire_RequestId_Activity
 */
Zipwire_Ip_StatusType Zipwire_RequestId(uint8 HwInstance, 
                                        uint8 HwChannel, 
                                        uint32 *Id)
{
    Zipwire_Ip_StatusType RequestIdStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_REQUESTID_ID))
    {
    RequestIdStatus = Zipwire_Ipw_RequestId(HwInstance, HwChannel, Id);
    } 
    return RequestIdStatus;
}


/**
 * @brief         Sends a trigger command to the target.
 * @implements    Zipwire_Trigger_Activity
 */
Zipwire_Ip_StatusType Zipwire_Trigger(uint8 HwInstance, 
                                      uint8 HwChannel)
{
    Zipwire_Ip_StatusType TriggerStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_TRIGGER_ID))
    {
    TriggerStatus = Zipwire_Ipw_Trigger(HwInstance, HwChannel);
    }
    return TriggerStatus;
}


/**
 * @brief         Returns the channel status.
 * @implements    Zipwire_GetChannelStatus_Activity
 */
Zipwire_Ip_StatusType Zipwire_GetChannelStatus(uint8 HwInstance, 
                                               uint8 HwChannel)
{
    Zipwire_Ip_StatusType GetChannelStatus = ZIPWIRE_IP_STATUS_ERROR;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_GETCHANNELSTATUS_ID))
    {
    GetChannelStatus = Zipwire_Ipw_GetChannelStatus(HwInstance, HwChannel);
    }
    return GetChannelStatus;
}


/**
 * @brief         Installs a global driver callback.
 * @implements    Zipwire_InstallGlobalCallback_Activity
 */
Zipwire_Ip_Callback Zipwire_InstallGlobalCallback(uint8 HwInstance, 
                                                  Zipwire_Ip_Callback CallbackFunction, 
                                                  void * CallbackParam)
{
    Zipwire_Ip_Callback InstallGlobalCallbackStatus = CallbackFunction;
    if (Zipwire_CheckInvalid(HwInstance, ZIPWIRE_CHANNEL_PLACEHOLDER, ZIPWIRE_INSTALLGLOBALCALLBACK_ID))
    {
    InstallGlobalCallbackStatus = Zipwire_Ipw_InstallGlobalCallback(HwInstance, CallbackFunction, CallbackParam);
    }
    return InstallGlobalCallbackStatus;
}


/**
 * @brief         Installs a channel callback.
 * @implements    Zipwire_InstallChannelCallback_Activity
 */
Zipwire_Ip_ChannelCallback Zipwire_InstallChannelCallback(uint8 HwInstance, 
                                                          uint8 HwChannel, 
                                                          Zipwire_Ip_ChannelCallback CallbackFunction, 
                                                          void * CallbackParam)
{
    Zipwire_Ip_ChannelCallback InstallChannelCallbackStatus = CallbackFunction;
    if (Zipwire_CheckInvalid(HwInstance, HwChannel, ZIPWIRE_INSTALLCHANNELCALLBACK_ID))
    {
    InstallChannelCallbackStatus = Zipwire_Ipw_InstallChannelCallback(HwInstance, HwChannel, CallbackFunction, CallbackParam);
    }
    return InstallChannelCallbackStatus;
}


#if (ZIPWIRE_VERSION_INFO_API_ENABLE == STD_ON)
/**
 * @brief         Returns the version information of this module
 * @implements    Zipwire_GetVersionInfo_Activity
 */
void Zipwire_GetVersionInfo(Std_VersionInfoType * pVersionInfo)
{
    pVersionInfo->vendorID         = (uint16)CDD_ZIPWIRE_VENDOR_ID;
    pVersionInfo->moduleID         = (uint16)CDD_ZIPWIRE_MODULE_ID;
    pVersionInfo->sw_major_version = (uint8)CDD_ZIPWIRE_SW_MAJOR_VERSION;
    pVersionInfo->sw_minor_version = (uint8)CDD_ZIPWIRE_SW_MINOR_VERSION;
    pVersionInfo->sw_patch_version = (uint8)CDD_ZIPWIRE_SW_PATCH_VERSION;
}

#endif /* #if (ZIPWIRE_VERSION_INFO_API_ENABLE == STD_ON) */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
