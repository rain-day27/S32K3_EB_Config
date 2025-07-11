/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
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
*   @file Mem_43_EXFLS.c
*
*   @addtogroup MEM_43_EXFLS
*   @implements Mem_43_EXFLS.c_Artifact
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
#include "Det.h"
#include "SchM_Mem_43_EXFLS.h"
#include "Mem_43_EXFLS_Ipw.h"
#if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
#include "Mcal.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_VENDOR_ID_C                      43
#define MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_C       4
#define MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_C       7
#define MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_C    0
#define MEM_43_EXFLS_SW_MAJOR_VERSION_C               5
#define MEM_43_EXFLS_SW_MINOR_VERSION_C               0
#define MEM_43_EXFLS_SW_PATCH_VERSION_C               0


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_EXFLS.c and Det.h are different"
    #endif
    /* Check if current file and SchM_Fls header file are of the same Autosar version */
    #if ((MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_C != SCHM_MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_C != SCHM_MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_EXFLS.c and SchM_Mem_43_EXFLS.h are different"
    #endif

    #if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
    /* Check if current file  and Mcal.h are of the same version */
        #if ((MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
            (MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of MemAcc.h and Mcal.h are different"
        #endif
    #endif
#endif

/* Check if current file and Mem_43_EXFLS_Ipw.h header file are of the same vendor */
#if (MEM_43_EXFLS_VENDOR_ID_C != MEM_43_EXFLS_IPW_VENDOR_ID)
    #error "Mem_43_EXFLS.c and Mem_43_EXFLS_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EXFLS_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_C    != MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_C != MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EXFLS.c and Mem_43_EXFLS_Ipw.h are different"
#endif
/* Check if current file and Mem_43_EXFLS_Ipw.h header file are of the same Software version */
#if ((MEM_43_EXFLS_SW_MAJOR_VERSION_C != MEM_43_EXFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_EXFLS_SW_MINOR_VERSION_C != MEM_43_EXFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_EXFLS_SW_PATCH_VERSION_C != MEM_43_EXFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EXFLS.c and Mem_43_EXFLS_Ipw.h are different"
#endif

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*When multicore type3 is enabled on MemAcc, global variables must be allocated to share memory section */
#if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"

/* Pointer to current mem external flash module configuration set */
const Mem_43_EXFLS_ConfigType            *Mem_43_EXFLS_pConfigPtr;

/* Information of the current processing job of each Mem instance */
static Mem_43_EXFLS_JobRuntimeInfoType    Mem_43_EXFLS_eJobRuntimeInfo[MEM_43_EXFLS_MEM_INSTANCE_COUNT];

#if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"


/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*! Specifies invalid mem instance index (valid ones will be in range 0 to MEM_43_EXFLS_MEM_INSTANCE_COUNT-1) */
#define MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID              MEM_43_EXFLS_MEM_INSTANCE_COUNT

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#if (MEM_43_EXFLS_CHECK_CFG_CRC == STD_ON)
/**
 * Pointer to current module configuration set
 */
static uint32 u32AccCRCremainder;
#endif /* MEM_43_EXFLS_CHECK_CFG_CRC */

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (MEM_43_EXFLS_CHECK_CFG_CRC == STD_ON)
static void Mem_43_EXFLS_AccumulateCRC(uint32 InputData);
static void Mem_43_EXFLS_ResetCRC(void);
static uint32 Mem_43_EXFLS_FinalizeCRC(void);
static void Mem_43_EXFLS_UpdateCRCreminder(Mem_43_EXFLS_CrcDataSizeType DataSize);

static Mem_43_EXFLS_CrcType Mem_43_EXFLS_CalcCfgCRC(void);
#endif /* MEM_43_EXFLS_CHECK_CFG_CRC */

/*==================================================================================================
                                       LOCAL FUNCTIONS (internal usage)
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/**
 * @brief       Checks if the Mem module has been initialized.
 *              Mem_43_EXFLS_ValidateModuleInitialized_Activity
 */
static inline uint32 Mem_43_EXFLS_ValidateModuleInitialized(void)
{
    uint32 ErrorId = MEM_43_EXFLS_E_OK;

#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    /* Only check if development error detection is enabled */
    if (NULL_PTR == Mem_43_EXFLS_pConfigPtr)
    {
        /* The Mem module has not been initialized */
        ErrorId = MEM_43_EXFLS_E_UNINIT;
    }
#endif

    return ErrorId;
}

/**
 * @brief    Report a development error
 */
static void Mem_43_EXFLS_ReportDevError(Mem_43_EXFLS_InstanceIdType    InstanceId,
                                        uint32                      ApiId,
                                        uint32                      ErrorId
                                       )
{
    #if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    /* Raise the development error via Det function */
    (void)Det_ReportError(MEM_43_EXFLS_MODULE_ID, (uint8)InstanceId, (uint8)ApiId, (uint8)ErrorId);
    #endif

    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
}


/**
 * @brief    Computes and checks the CRC over configuration set
 */
static Std_ReturnType Mem_43_EXFLS_ValidateConfigCRC(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

#if (MEM_43_EXFLS_CHECK_CFG_CRC == STD_ON)
    if (Mem_43_EXFLS_pConfigPtr->u16ConfigCrc != Mem_43_EXFLS_CalcCfgCRC())
    {
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
#endif /* MEM_43_EXFLS_CHECK_CFG_CRC */

    return RetVal;
}


/**
* @brief    Search the list of Mem instances and returns index of instance with matching InstanceId
*/
static uint32 Mem_43_EXFLS_GetInstanceIndex(const Mem_43_EXFLS_InstanceIdType InstanceId)
{
    const  Mem_43_EXFLS_MemInstanceType *MemInstance;
    uint32 Index = 0U;

    MemInstance = Mem_43_EXFLS_pConfigPtr->MemInstances;  /* Point to the first instance */
    /* Loop through all configured memory instances */
    for (Index = 0U; Index < MEM_43_EXFLS_MEM_INSTANCE_COUNT; Index++)
    {
        if (InstanceId == MemInstance->InstanceId)
        {
            /* InstanceId is matched, exit loop */
            break;
        }

        /* Move to the next mem instance */
        MemInstance++;
    }
    /* The returned value will be INVALID if InstanceId is not matched with any index or the Mem module has not been initialized*/
    return Index;
}


/**
 * @brief    Search for the sector batch that contains the provided address
 */
static const Mem_43_EXFLS_SectorBatchType * Mem_43_EXFLS_GetSectorBatch(uint32                   InstanceIndex,
                                                                        Mem_43_EXFLS_AddressType    Address
                                                                       )
{
    const Mem_43_EXFLS_MemInstanceType *MemInstance = &(Mem_43_EXFLS_pConfigPtr->MemInstances[InstanceIndex]);
    const Mem_43_EXFLS_SectorBatchType *SectorBatch = MemInstance->SectorBatches;
    uint32 Index = 0U;

    /* Loop through all configured sector batches of this memory instance */
    do
    {
        if ((SectorBatch->StartAddress <= Address) && (Address <= SectorBatch->EndAddress))
        {
            /* The address falls within this sector batch */
            break;
        }

        /* Move to the next sector batch */
        SectorBatch++;
        Index++;
    }
    while (Index < MemInstance->SectorBatchCount);

    /* The returned value will be NULL_PTR if Address does not fall within any sector batch */
    if (Index >= MemInstance->SectorBatchCount)
    {
        SectorBatch = NULL_PTR;
    }

    return SectorBatch;
}


/**
 * @brief    Checks if the provided address and length are valid
 */
static uint32 Mem_43_EXFLS_ValidateAddressAndLength(Mem_43_EXFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    JobRequest->SectorBatch = Mem_43_EXFLS_GetSectorBatch(JobRequest->InstanceIndex, JobRequest->Address);
    if (NULL_PTR == JobRequest->SectorBatch)
    {
        /* Could not find the sector batch, the address is invalid */
        ErrorId = MEM_43_EXFLS_E_PARAM_ADDRESS;
    }
    else if ((0U == JobRequest->Length) ||
             ((JobRequest->Length - 1U) > (JobRequest->SectorBatch->EndAddress - JobRequest->Address))
            )
    {
        /* The length is invalid */
        ErrorId = MEM_43_EXFLS_E_PARAM_LENGTH;
    }
    else
    {
        /* Both address and length are valid */
        ErrorId = MEM_43_EXFLS_E_OK;
    }

    if ((MEM_43_EXFLS_E_OK == ErrorId) && (MEM_43_EXFLS_JOB_ERASE == JobRequest->JobType))
    {
        if((JobRequest->Address % JobRequest->SectorBatch->SectorSize) != 0U)
        {
            /* The address is not align with Sector size */
            ErrorId = MEM_43_EXFLS_E_PARAM_ADDRESS;
        }
        else if((JobRequest->Length % JobRequest->SectorBatch->SectorSize) != 0U)
        {
            /* The Length is not align with Sector size */
            ErrorId = MEM_43_EXFLS_E_PARAM_LENGTH;
        }
        else
        {
            /*Address and length are aligned with Sector size*/
            ErrorId = MEM_43_EXFLS_E_OK;
        }
    }

    return ErrorId;
}

/**
 * @brief    Checks if provided InstanceId is consistent with the configuration
 */
static uint32 Mem_43_EXFLS_ValidateInstanceId(Mem_43_EXFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_EXFLS_ValidateModuleInitialized();
    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        /* Get the mem index number according to the mem instance id */
        JobRequest->InstanceIndex = Mem_43_EXFLS_GetInstanceIndex(JobRequest->InstanceId);
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
        /* Only check if development error detection is enabled */
        if (MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID == JobRequest->InstanceIndex)
        {
            /* The provided InstanceId is inconsistent with the configuration */
            ErrorId = MEM_43_EXFLS_E_PARAM_INSTANCE_ID;
        }
#endif
    }
    else
    {
        /*the Mem module has not been initialized, return INVALID value*/
        ErrorId = MEM_43_EXFLS_MEM_INSTANCE_COUNT;
    }
    return ErrorId;
}

/**
 * @brief    Common checks of input parameters for driver APIs.
 */
static uint32 Mem_43_EXFLS_ValidateParamJobCommon(Mem_43_EXFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_EXFLS_ValidateModuleInitialized();

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        /* Check if the provided InstanceId is consistent with the configuration */
        ErrorId = Mem_43_EXFLS_ValidateInstanceId(JobRequest);
    }

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        /* Check if the address and the length are valid */
        ErrorId = Mem_43_EXFLS_ValidateAddressAndLength(JobRequest);
    }

    return ErrorId;
}


/**
 * @brief    Checks if the input argument is a NULL pointer.
 */
static inline uint32 Mem_43_EXFLS_ValidateDataPointer(const Mem_43_EXFLS_DataType *DataPtr)
{
    uint32 ErrorId = MEM_43_EXFLS_E_OK;

    if (NULL_PTR == DataPtr)
    {
        /* The DataPtr argument is a NULL pointer */
        ErrorId = MEM_43_EXFLS_E_PARAM_POINTER;
    }

    return ErrorId;
}


/**
 * @brief    Checks the input parameters for data transfer jobs (read, write)
 */
static uint32 Mem_43_EXFLS_ValidateParamJobDataTransfer(Mem_43_EXFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Perform the common checking */
    ErrorId = Mem_43_EXFLS_ValidateParamJobCommon(JobRequest);

    /* Perform the specific checking */
    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        ErrorId = Mem_43_EXFLS_ValidateDataPointer(JobRequest->DataPtr);
    }

    return ErrorId;
}


/**
 * @brief    Initialize the input parameter for the new job request
 */
static void Mem_43_EXFLS_InitJobRequest(Mem_43_EXFLS_JobRuntimeInfoType    *JobRequest,
                                        Mem_43_EXFLS_InstanceIdType         InstanceId,
                                        Mem_43_EXFLS_AddressType            Address,
                                        Mem_43_EXFLS_DataType               *DataPtr,
                                        Mem_43_EXFLS_LengthType             Length
                                    )
{
    /* Input value */
    JobRequest->InstanceId       = InstanceId;
    JobRequest->Address          = Address;
    JobRequest->DataPtr          = DataPtr;
    JobRequest->Length           = Length;
    /* Default value */
    JobRequest->InstanceIndex    = MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID;
    JobRequest->SectorBatch      = NULL_PTR;
    /* Prepare for a new job */
    JobRequest->JobFlags         = MEM_43_EXFLS_JOB_FLAG_STARTED;
    JobRequest->JobResult        = MEM_43_EXFLS_JOB_PENDING;
#if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
    JobRequest->PartitionId      = OsIf_GetUserId();
#endif
}


/**
 * @brief    Check if the mem instance is idle and configure the new job request
 */
static uint32 Mem_43_EXFLS_ConfigureJobRequest(const Mem_43_EXFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    if (MEM_43_EXFLS_JOB_PENDING == Mem_43_EXFLS_eJobRuntimeInfo[JobRequest->InstanceIndex].JobResult)
    {
        /* A previous job is still being processed */
        ErrorId = MEM_43_EXFLS_E_JOB_PENDING;
    }
    else
    {
        /* Accept the requested job */
        ErrorId = MEM_43_EXFLS_E_OK;
        /* Configure the new job */
        Mem_43_EXFLS_eJobRuntimeInfo[JobRequest->InstanceIndex] = *JobRequest;
    }

    return ErrorId;
}


/**
 * @brief   Decides which sub-function to call based on the job type:
 *          Modify (Write, Erase) or Read (Read, BlankCheck).
 **/
static Mem_43_EXFLS_JobResultType Mem_43_EXFLS_DoRequestedJobs(uint32                           InstanceIndex,
                                                               Mem_43_EXFLS_JobRuntimeInfoType    *JobInfo
                                                              )
{
    /* Assume no more data to process, previous asynchronous job completed successfully */
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_OK;

    if (0U != JobInfo->Length)
    {
        /* Call Low-level driver to work with physical flash device
         * Process the maximum length depending on the hardware capabilities, or until a sector boundary
         */
        switch (JobInfo->JobType)
        {
            case MEM_43_EXFLS_JOB_ERASE:
                JobResult = Mem_43_EXFLS_IPW_Erase(InstanceIndex, JobInfo);
                break;

            case MEM_43_EXFLS_JOB_WRITE:
                JobResult = Mem_43_EXFLS_IPW_Write(InstanceIndex, JobInfo);
                break;

            case MEM_43_EXFLS_JOB_BLANK_CHECK:
                JobResult = Mem_43_EXFLS_IPW_BlankCheck(InstanceIndex, JobInfo);
                break;

#if (MEM_43_EXFLS_SERVICE_COMPARE == STD_ON)
            case MEM_43_EXFLS_JOB_COMPARE:
                JobResult = Mem_43_EXFLS_IPW_Compare(InstanceIndex, JobInfo);
                break;
#endif

            default:  /* MEM_43_EXFLS_JOB_READ */
                JobResult = Mem_43_EXFLS_IPW_Read(InstanceIndex, JobInfo);
                break;
        };

        if ((MEM_43_EXFLS_JOB_OK == JobResult) && (0U != JobInfo->Length))
        {
            /* The current chunk has completed but there is still data to process, need more MainFunction calls */
            JobResult = MEM_43_EXFLS_JOB_PENDING;
        }
    }

    return JobResult;
}


/**
 * @brief       Process the pending job for the mem instance
 *              MEM_43_EXFLS_ProcessRequestedJobs_Activity
 **/
static void Mem_43_EXFLS_ProcessRequestedJobs(uint32 InstanceIndex)
{
    Mem_43_EXFLS_JobRuntimeInfoType *JobInfo = &(Mem_43_EXFLS_eJobRuntimeInfo[InstanceIndex]);
    Mem_43_EXFLS_JobResultType     JobResult = MEM_43_EXFLS_JOB_OK;

    if ((JobInfo->JobFlags & (uint8)MEM_43_EXFLS_JOB_FLAG_STARTED) != 0U)
    {
        /* Clear any previous suspended job */
        Mem_43_EXFLS_IPW_AbortSuspended(InstanceIndex);
        /* Clear flag */
        JobInfo->JobFlags &= ~(uint8)MEM_43_EXFLS_JOB_FLAG_STARTED;
    }
    else
    {
        /* Check the status of the job is being processed in the low-level driver */
        JobResult = Mem_43_EXFLS_IPW_GetJobResult(InstanceIndex, JobInfo->JobType);
    }
    if (MEM_43_EXFLS_JOB_OK == JobResult)
    {
        /* The previous pending job has been done, launch new operation */
        JobResult = Mem_43_EXFLS_DoRequestedJobs(InstanceIndex, JobInfo);
    }

    /* Update the latest job result */
    JobInfo->JobResult = JobResult;
}

#if (MEM_43_EXFLS_SERVICE_COMPARE == STD_ON)
static Std_ReturnType Mem_43_EXFLS_Compare(Mem_43_EXFLS_InstanceIdType    InstanceId,
                                           Mem_43_EXFLS_AddressType       SourceAddress,
                                           Mem_43_EXFLS_DataType        * DestinationDataPtr,
                                           Mem_43_EXFLS_LengthType        Length
                                          )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;
    Mem_43_EXFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_EXFLS_JOB_COMPARE;
    Mem_43_EXFLS_InitJobRequest(&JobRequest, InstanceId, SourceAddress, DestinationDataPtr, Length);
    /* Perform the input parameters checking */
    ErrorId = Mem_43_EXFLS_ValidateParamJobDataTransfer(&JobRequest);
    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_13();
        ErrorId = Mem_43_EXFLS_ConfigureJobRequest(&JobRequest);
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_13();
    }
    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_HWSPECIFICSERVICE_ID, ErrorId);
    }
    return RetVal;
}
#endif

#if (MEM_43_EXFLS_CHECK_CFG_CRC == STD_ON)
static void Mem_43_EXFLS_AccumulateCRC(uint32 InputData)
{
    if (0xFFFFU < InputData)
    {
        /* preparation for accumulation of higher 16 bits of the InputData */
        u32AccCRCremainder = (u32AccCRCremainder << 16U) | (InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of u32AccCRCremainder) */
        Mem_43_EXFLS_UpdateCRCreminder(CRC_16_BITS);
    }

    if (0xFFU < InputData)
    {
        /* preparation for accumulation of lower 16 bits of the InputData */
        u32AccCRCremainder = (u32AccCRCremainder << 16U) | (InputData & 0x0000FFFFU);
        /* make 16-bit accumulated result (in lower 16-bits of u32AccCRCremainder) */
        Mem_43_EXFLS_UpdateCRCreminder(CRC_16_BITS);
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the InputData */
        u32AccCRCremainder = (u32AccCRCremainder << 8U) | InputData;
        /* make 16-bit accumulated result (in lower 16-bits of u32AccCRCremainder) */
        Mem_43_EXFLS_UpdateCRCreminder(CRC_8_BITS);
    }
}

/**
 * @brief        Function to reset CRC calculation.
 *
 */
static void Mem_43_EXFLS_ResetCRC(void)
{
    u32AccCRCremainder = 0U;
}


static uint32 Mem_43_EXFLS_FinalizeCRC(void)
{
    /* add the final 0x0000 to the remainder */
    u32AccCRCremainder = (u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */
    Mem_43_EXFLS_UpdateCRCreminder(CRC_16_BITS);

    return u32AccCRCremainder;
}


static void Mem_43_EXFLS_UpdateCRCreminder(Mem_43_EXFLS_CrcDataSizeType DataSize)
{
    uint32 CrcPolynomSft;
    uint32 LeadingOne;
    uint32 AccDataLoc;
    uint32 LeadingOneInitial;

    switch (DataSize)
    {
        case CRC_8_BITS:
            CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 7U;
            break;

        case CRC_16_BITS:
        default:
            CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    AccDataLoc = u32AccCRCremainder;

    /* CRC computation */
    for (LeadingOne = LeadingOneInitial; LeadingOne >= 0x00010000U; LeadingOne >>= 1U)
    {
        if (0U != (AccDataLoc & LeadingOne))
        {
            AccDataLoc ^= CrcPolynomSft;
        }
        CrcPolynomSft >>= 1U;
    }

    /* copy back to static variable */
    u32AccCRCremainder = AccDataLoc;
}


static Mem_43_EXFLS_CrcType Mem_43_EXFLS_CalcCfgCRC(void)
{
    uint32 MemInstanceIndex;
    uint32 SectorBatcheIndex;
    uint32 ExUnitIndex;
    uint32 MemUnitIndex;
    /* Reset the accumulated CRC value */
    Mem_43_EXFLS_ResetCRC();

    /* CRC - Accumulate MemInstances */
    for (MemInstanceIndex = 0U; MemInstanceIndex < MEM_43_EXFLS_MEM_INSTANCE_COUNT; MemInstanceIndex++)
    {
        /* CRC - Accumulate InstanceId */
        Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].InstanceId);
        /* CRC - Accumulate SectorBatchCount */
        Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatchCount);
        /* CRC - Accumulate SectorBatches */
        for (SectorBatcheIndex =0u; SectorBatcheIndex < Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatchCount; SectorBatcheIndex++)
        {
            /* CRC - Accumulate SectorSize */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatcheIndex].SectorSize);
            /* CRC - Accumulate ReadPageSize */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatcheIndex].ReadPageSize);
            /* CRC - Accumulate WritePageSize */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatcheIndex].WritePageSize);
            /* CRC - Accumulate EraseBurstSize */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatcheIndex].EraseBurstSize);
            /* CRC - Accumulate ReadBurstSize */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatcheIndex].ReadBurstSize);
            /* CRC - Accumulate WriteBurstSize */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].SectorBatches[SectorBatcheIndex].WriteBurstSize);
        }
        /* CRC - Accumulate MemUnitIndex */
        Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemInstances[MemInstanceIndex].MemUnitIndex);
    }

    /* CRC - Accumulate MemDevices */
    /* CRC - Accumulate QspiUnits */
    for (ExUnitIndex = 0U; ExUnitIndex < MEM_43_EXFLS_QSPI_UNIT_COUNT; ExUnitIndex++)
    {
        /* CRC - Accumulate HardwareInstance */
        Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].HardwareInstance);
        /* CRC - Accumulate Selected ControllerCfg */
        if (NULL_PTR != Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config)
        {
            /* CRC - Accumulate dataRate */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dataRate);
            /* CRC - Accumulate memSizeA1 */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->memSizeA1);
            /* CRC - Accumulate memSizeA2 */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->memSizeA2);
            /* CRC - Accumulate csHoldTime */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->csHoldTime);
            /* CRC - Accumulate csSetupTime */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->csSetupTime);
            /* CRC - Accumulate columnAddr */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->columnAddr);
            /* CRC - Accumulate wordAddresable */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->wordAddresable);
            /* CRC - Accumulate readModeA */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->readModeA);
            /* CRC - Accumulate sampleDelay */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->sampleDelay);
            /* CRC - Accumulate samplePhase */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->samplePhase);
            /* CRC - Accumulate dllMode */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dllSettingsA.dllMode);
            /* CRC - Accumulate freqEnable */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dllSettingsA.freqEnable);
            /* CRC - Accumulate referenceCounter */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dllSettingsA.referenceCounter);
            /* CRC - Accumulate resolution */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dllSettingsA.resolution);
            /* CRC - Accumulate coarseDelay */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dllSettingsA.coarseDelay);
            /* CRC - Accumulate fineDelay */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dllSettingsA.fineDelay);
            /* CRC - Accumulate tapSelect */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dllSettingsA.tapSelect);
            /* CRC - Accumulate dataAlign */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->dataAlign);
            /* CRC - Accumulate io2IdleValueA */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->io2IdleValueA);
            /* CRC - Accumulate io3IdleValueA */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->io3IdleValueA);
            /* CRC - Accumulate byteSwap */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits[ExUnitIndex].Config->byteSwap);
            /* Bypass check CRC for SFP config and AHB configuration */
        }
    }
    /* CRC - Accumulate MemUnits */
    for (MemUnitIndex = 0U; MemUnitIndex < MEM_43_EXFLS_MEM_UNIT_COUNT; MemUnitIndex++)
    {
        /* CRC - Accumulate selected ConnectCfg */
            /* CRC - Accumulate qspiInstance */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits[MemUnitIndex].Connect->qspiInstance);
            /* CRC - Accumulate connectionType */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits[MemUnitIndex].Connect->connectionType);
            /* CRC - Accumulate memAlignment */
            Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits[MemUnitIndex].Connect->memAlignment);

        /* Bypass check CRC for External memory devices configuration */
        /* CRC - Accumulate AHBRead */
        Mem_43_EXFLS_AccumulateCRC((uint32) Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits[MemUnitIndex].AHBRead);
    }

    return ((Mem_43_EXFLS_CrcType)Mem_43_EXFLS_FinalizeCRC());
}
#endif /* MEM_43_EXFLS_CHECK_CFG_CRC */
/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes Mem_43_EXFLS module.
 *
 * @details      Initialization function - initializes all variables
 *               and sets the module state to initialized.
 *
 * @param[in]    ConfigPtr        Pointer to the configuration data structure - since Mem_43_EXFLS driver
 *                                is a precompile module this parameter is typically not used.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @pre          None
 *
 * @api
 *
 * @implements   Mem_43_EXFLS_Init_Activity
 */
void Mem_43_EXFLS_Init(const Mem_43_EXFLS_ConfigType *ConfigPtr)
{
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_OK;
    Std_ReturnType Status;
    uint32 InstanceIndex;

    if (NULL_PTR != ConfigPtr)
    {
        /* The ConfigPtr argument is not a NULL pointer */
        Mem_43_EXFLS_ReportDevError(0U, MEM_43_EXFLS_INIT_ID, MEM_43_EXFLS_E_PARAM_POINTER);
    }
    else
    {
        /* Initialize the Mem driver internal states and set the Mem driver job processing state to MEM_JOB_OK */
        Mem_43_EXFLS_pConfigPtr = &Mem_43_EXFLS_Config;

        Status = Mem_43_EXFLS_ValidateConfigCRC();
        if ((Std_ReturnType)E_OK == Status)
        {
            /* Initialize low-level hardware */
            Status = Mem_43_EXFLS_IPW_Init();
        }

        if ((Std_ReturnType)E_OK != Status)
        {
            /* Mark the driver as un-initialized */
            Mem_43_EXFLS_pConfigPtr = NULL_PTR;
            JobResult = MEM_43_EXFLS_JOB_FAILED;
        }

        /* Update job result */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_EXFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            Mem_43_EXFLS_eJobRuntimeInfo[InstanceIndex].JobResult = JobResult;
        }
    }
}


/**
 * @brief        The function de-initializes the Mem_43_EXFLS module.
 *
 * @details      De-initialize module. If there is still an access job pending,
 *               it is immediately terminated (using hardware cancel operation)
 *               and the Mem driver module state is set to unitialized.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre          The Mem_43_EXFLS module must be re-initialized before it will accept
 *               any new job requests after this service is processed.
 *
 * @implements   Mem_43_EXFLS_DeInit_Activity
 */
void Mem_43_EXFLS_DeInit(void)
{
    uint32 InstanceIndex;

    /* Check if the driver has been initialized before */
    if (NULL_PTR != Mem_43_EXFLS_pConfigPtr)
    {
        /* Cancel any ongoing flash operations in the hardware */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_EXFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_EXFLS_JOB_PENDING == Mem_43_EXFLS_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
                /* Cancel the on-going job for this mem instance */
                Mem_43_EXFLS_IPW_AbortSuspended(InstanceIndex);
                /* Set JobResult to Failed to avoid main function calls */
                Mem_43_EXFLS_eJobRuntimeInfo[InstanceIndex].JobResult = MEM_43_EXFLS_JOB_FAILED;
            }
            Mem_43_EXFLS_IPW_DeInit(InstanceIndex);
        }
        /* De-initialize the Mem driver internal states */
        Mem_43_EXFLS_pConfigPtr = NULL_PTR;
    }
}


/**
 * @brief        Return the version information of the Mem module.
 *
 * @details      Version information includes:
 *               - Module Id
 *               - Vendor Id
 *               - Vendor specific version numbers
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   VersionInfoPtr    Pointer to where to store the version information of this module.
 *
 * @return       None
 *
 * @api
 *
 * @implements    Mem_43_EXFLS_GetVersionInfo_Activity
 */
void Mem_43_EXFLS_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
    if (NULL_PTR != VersionInfoPtr)
    {
        /* Return version information about Mem module */
        VersionInfoPtr->moduleID         = (uint16)MEM_43_EXFLS_MODULE_ID;
        VersionInfoPtr->vendorID         = (uint16)MEM_43_EXFLS_VENDOR_ID;
        VersionInfoPtr->sw_major_version =  (uint8)MEM_43_EXFLS_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version =  (uint8)MEM_43_EXFLS_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version =  (uint8)MEM_43_EXFLS_SW_PATCH_VERSION;
    }
    else
    {
        /* The VersionInfoPtr argument is a NULL pointer */
        Mem_43_EXFLS_ReportDevError(0U, MEM_43_EXFLS_GETVERSIONINFO_ID, MEM_43_EXFLS_E_PARAM_POINTER);
    }
}


/**
 * @brief        Returns the result of the most recent job.
 *
 * @details      Returns synchronously the result of the last job.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       Mem_43_EXFLS_JobResultType    Most recent job result.
 *
 * @api
 *
 * @implements   Mem_43_EXFLS_GetJobResult_Activity
 */
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_GetJobResult(Mem_43_EXFLS_InstanceIdType InstanceId)
{
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    uint32 ErrorId;
    uint32 Index;
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_EXFLS_ValidateModuleInitialized();
    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        Index = Mem_43_EXFLS_GetInstanceIndex(InstanceId);
        if (Index != MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID)
        {
            /* Get the most recent job result of the according driver instance */
            JobResult = Mem_43_EXFLS_eJobRuntimeInfo[Index].JobResult;
        }
    }

    return JobResult;
}


/**
 * @brief        Suspends active memory operation using hardware mechanism.
 *
 * @details      If the suspend mechanism is not supported by hardware,
 *               implementation based on physical segmentation.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_EXFLS_Suspend_Activity
 */
Std_ReturnType Mem_43_EXFLS_Suspend(Mem_43_EXFLS_InstanceIdType InstanceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 Index;
    Mem_43_EXFLS_JobResultType     JobResult;
    JobResult = Mem_43_EXFLS_GetJobResult(InstanceId);
    Mem_43_EXFLS_JobRuntimeInfoType *JobInfo;

#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_EXFLS_ValidateModuleInitialized();

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */
        /* Check if InstanceId is consistent with configuration */
        /* Get the mem index number according to the mem instance id */
        Index = Mem_43_EXFLS_GetInstanceIndex(InstanceId);
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
        if (MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID == Index)
        {
            /* The provided InstanceId is inconsistent with the configuration */
            ErrorId = MEM_43_EXFLS_E_PARAM_INSTANCE_ID;
        }
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_SUSPEND_ID, ErrorId);
    }
    else
    {
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */

        JobInfo = &(Mem_43_EXFLS_eJobRuntimeInfo[Index]);
        switch (JobInfo->JobType)
        {
            case MEM_43_EXFLS_JOB_ERASE:
                if ((boolean)TRUE == Mem_43_EXFLS_IPW_IsSupportEraseSupendResume(Index))
                {
                    if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                    {
                        JobResult=Mem_43_EXFLS_IPW_EraseSuspend(Index);
                        if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                        {
                            JobInfo->JobType=MEM_43_EXFLS_JOB_ERASESUSPEND;
                        }
                        else /* In case JobResult is MEM_43_EXFLS_JOB_FAILED */
                        {
                            RetVal = (Std_ReturnType)E_NOT_OK;
                        }
                    }
                    else
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                    }
                }
                else
                {
                    RetVal = (Std_ReturnType)E_MEM_SERVICE_NOT_AVAIL;
                }
                break;

            case MEM_43_EXFLS_JOB_WRITE:
                if ((boolean)TRUE == Mem_43_EXFLS_IPW_IsSupportProgramSupendResume(Index))
                {
                    if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                    {
                        JobResult=Mem_43_EXFLS_IPW_WriteSuspend(Index);
                        if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                        {
                            JobInfo->JobType=MEM_43_EXFLS_JOB_WRITESUSPEND;
                        }
                        else /* In case JobResult is MEM_43_EXFLS_JOB_FAILED */
                        {
                            RetVal = (Std_ReturnType)E_NOT_OK;
                        }
                    }
                    else
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                    }
                }
                else
                {
                    RetVal = (Std_ReturnType)E_MEM_SERVICE_NOT_AVAIL;
                }
                break;

            case MEM_43_EXFLS_JOB_ERASESUSPEND:
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;

            case MEM_43_EXFLS_JOB_WRITESUSPEND:
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;

            case MEM_43_EXFLS_JOB_NONE:
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;

            default: /* Read, compare, blankcheck*/
                RetVal = (Std_ReturnType)E_MEM_SERVICE_NOT_AVAIL;
                break;
        }
        JobInfo->JobResult = JobResult;

#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}


/**
 * @brief        Resumes suspended memory operation using hardware mechanism.
 *
 * @details      Resumes suspended memory operation using hardware mechanism.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_EXFLS_Resume_Activity
 */
Std_ReturnType Mem_43_EXFLS_Resume(Mem_43_EXFLS_InstanceIdType InstanceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 Index;
    Mem_43_EXFLS_JobResultType     JobResult;
    JobResult = Mem_43_EXFLS_GetJobResult(InstanceId);
    Mem_43_EXFLS_JobRuntimeInfoType *JobInfo;

#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_EXFLS_ValidateModuleInitialized();

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */
        /* Check if InstanceId is consistent with configuration */
        /* Get the mem index number according to the mem instance id */
        Index = Mem_43_EXFLS_GetInstanceIndex(InstanceId);
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
        if (MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID == Index)
        {
            /* The provided InstanceId is inconsistent with the configuration */
            ErrorId = MEM_43_EXFLS_E_PARAM_INSTANCE_ID;
        }
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_RESUME_ID, ErrorId);
    }
    else
    {
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */

        JobInfo = &(Mem_43_EXFLS_eJobRuntimeInfo[Index]);

        switch (JobInfo->JobType)
        {
            case MEM_43_EXFLS_JOB_ERASESUSPEND:
                if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                {
                    JobResult=Mem_43_EXFLS_IPW_EraseResume(Index);
                    if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                    {
                        JobInfo->JobType=MEM_43_EXFLS_JOB_ERASE;
                    }
                    else /* In case JobResult is MEM_43_EXFLS_JOB_FAILED */
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                    }
                }
                else
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
                break;

            case MEM_43_EXFLS_JOB_WRITESUSPEND:
                if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                {
                    JobResult=Mem_43_EXFLS_IPW_WriteResume(Index);
                    if (MEM_43_EXFLS_JOB_PENDING == JobResult)
                    {
                        JobInfo->JobType=MEM_43_EXFLS_JOB_WRITE;
                    }
                    else /* In case JobResult is MEM_43_EXFLS_JOB_FAILED */
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                    }
                }
                else
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
                break;

            case MEM_43_EXFLS_JOB_ERASE:
                if ((boolean)TRUE == Mem_43_EXFLS_IPW_IsSupportEraseSupendResume(Index))
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    RetVal = (Std_ReturnType)E_MEM_SERVICE_NOT_AVAIL;
                }
                break;

            case MEM_43_EXFLS_JOB_WRITE:
                if ((boolean)TRUE == Mem_43_EXFLS_IPW_IsSupportProgramSupendResume(Index))
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    RetVal = (Std_ReturnType)E_MEM_SERVICE_NOT_AVAIL;
                }
                break;

            case MEM_43_EXFLS_JOB_NONE:
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;

            default: /* No erase or write job is suspended */
                RetVal = (Std_ReturnType)E_MEM_SERVICE_NOT_AVAIL;
                break;
        }
        JobInfo->JobResult = JobResult;

#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}


/**
 * @brief        Propagates an ECC error to the memory upper layers
 *
 * @details      This service can be used to report an access error in case
 *               the Mem driver cannot provide the access error information - typically for ECC faults.
 *               It is called by the system ECC handler to propagate an ECC error to the memory upper layers.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_EXFLS_PropagateError_Activity
 */
void Mem_43_EXFLS_PropagateError(Mem_43_EXFLS_InstanceIdType InstanceId)
{
    uint32 Index;
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_EXFLS_ValidateModuleInitialized();

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */
        /* Check if InstanceId is consistent with configuration */
        /* Get the mem index number according to the mem instance id */
        Index = Mem_43_EXFLS_GetInstanceIndex(InstanceId);
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
        if (MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID == Index)
        {
            /* The provided InstanceId is inconsistent with the configuration */
            ErrorId = MEM_43_EXFLS_E_PARAM_INSTANCE_ID;
        }
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        /* Report the error */
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_PROPAGATEERROR_ID, ErrorId);
    }
    else
    {
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */
        if (MEM_43_EXFLS_JOB_PENDING == Mem_43_EXFLS_eJobRuntimeInfo[Index].JobResult)
        {
            /* Cancel the on-going job for this mem instance if pending*/
            Mem_43_EXFLS_IPW_AbortSuspended(Index);
        }
        Mem_43_EXFLS_eJobRuntimeInfo[Index].JobType=MEM_43_EXFLS_JOB_NONE;
        /* Set the job result code to MEM_ECC_UNCORRECTED */
        Mem_43_EXFLS_eJobRuntimeInfo[Index].JobResult=MEM_43_EXFLS_ECC_UNCORRECTED;
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Reads from flash memory.
 *
 * @details          Triggers a read job to copy the from the source address into the referenced destination data
 *                   buffer. The result of this service can be retrieved using the Mem_GetJobResult API. If the read
 *                   operation was successful, the result of the job is MEM_JOB_OK. If the read operation failed,
 *                   the result of the job is either MEM_JOB_FAILED in case of a general error or MEM_ECC_
 *                   CORRECTED/MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        SourceAddress         Physical address to read data from.
 * @param[in]        Length                Read length in bytes.
 *
 * @param[out]       DestinationDataPtr    Destination memory pointer to store the read data
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_EXFLS_Read_Activity
 */
Std_ReturnType Mem_43_EXFLS_Read(Mem_43_EXFLS_InstanceIdType    InstanceId,
                                 Mem_43_EXFLS_AddressType       SourceAddress,
                                 Mem_43_EXFLS_DataType          *DestinationDataPtr,
                                 Mem_43_EXFLS_LengthType        Length
                                )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_EXFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_EXFLS_JOB_READ;
    Mem_43_EXFLS_InitJobRequest(&JobRequest, InstanceId, SourceAddress, DestinationDataPtr, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_EXFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_12();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_EXFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_12();
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_READ_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Writes to flash memory.
 *
 * @details          Triggers a write job to store the passed data to the provided address area with given address
 *                   and length. The result of this service can be retrieved using the Mem_GetJobResult API. If the
 *                   write operation was successful, the job result is MEM_JOB_OK. If there was an issue writing
 *                   the data, the result is MEM_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical write address (aligned to page size).
 * @param[out]       SourceDataPtr         Source data pointer (aligned to page size).
 * @param[in]        Length                Write length in bytes (aligned to page size).
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_EXFLS_Write_Activity
 */
Std_ReturnType Mem_43_EXFLS_Write(Mem_43_EXFLS_InstanceIdType     InstanceId,
                                  Mem_43_EXFLS_AddressType        TargetAddress,
                                  const Mem_43_EXFLS_DataType     *SourceDataPtr,
                                  Mem_43_EXFLS_LengthType         Length
                                 )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_EXFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_EXFLS_JOB_WRITE;

#if (CPU_TYPE == CPU_TYPE_64)
    const uint64 SourceDataAddr = (uint64)&(SourceDataPtr[0]);
#else
    const uint32 SourceDataAddr = (uint32)&(SourceDataPtr[0]);
#endif
    Mem_43_EXFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, (Mem_43_EXFLS_DataType *)(SourceDataAddr), Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_EXFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_11();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_EXFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_11();
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_WRITE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Erase one or more complete flash sectors.
 *
 * @details          Triggers an erase job of the given sector/sector batch defined by targetAddress and length.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the erase operation
 *                   was successful, the result of the job is MEM_JOB_OK. If the erase operation failed, e.g. due to
 *                   a hardware issue, the result of the job is MEM_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical erase address (aligned to sector size).
 * @param[in]        Length                Erase length in bytes (aligned to sector size).
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_EXFLS_Erase_Activity
 */
Std_ReturnType Mem_43_EXFLS_Erase(Mem_43_EXFLS_InstanceIdType    InstanceId,
                                  Mem_43_EXFLS_AddressType       TargetAddress,
                                  Mem_43_EXFLS_LengthType        Length
                                 )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_EXFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_EXFLS_JOB_ERASE;
    Mem_43_EXFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_EXFLS_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_10();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_EXFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_10();
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_ERASE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 *
 * @details          Triggers a job to check the erased state of the page which is referenced by targetAddress.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the checked page is
 *                   blank, the result of the job is MEM_JOB_OK. Otherwise, if the page is not blank, the result is
 *                   MEM_INCONSISTENT.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical blank check address.
 * @param[in]        Length                Blank check length.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_EXFLS_BlankCheck_Activity
 */
Std_ReturnType Mem_43_EXFLS_BlankCheck(Mem_43_EXFLS_InstanceIdType    InstanceId,
                                       Mem_43_EXFLS_AddressType       TargetAddress,
                                       Mem_43_EXFLS_LengthType        Length
                                      )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_EXFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_EXFLS_JOB_BLANK_CHECK;
    Mem_43_EXFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_EXFLS_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_14();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_EXFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_EXFLS_MEM_EXCLUSIVE_AREA_14();
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_BLANKCHECK_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Trigger a hardware specific service.
 *
 * @details          Triggers a hardware specific memory driver job. DataPtr can be used to pass and return data to/
 *                   from this service. This service is just a dispatcher to the hardware specific service
 *                   implementation referenced by HwServiceId. The result of this service can be retrieved using the
 *                   Mem_GetJobResult API. If the hardware specific operation was successful, the result of the job
 *                   is MEM_JOB_OK. If the hardware specific operation failed, the result of the job is MEM_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        HwServiceId           Hardware specific service request identifier for dispatching the request.
 * @param[in]        DataPtr               Request specific data pointer.
 * @param[in]        LengthPtr             Size pointer of the data passed by dataPtr.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_EXFLS_HwSpecificService_Activity
 */
Std_ReturnType Mem_43_EXFLS_HwSpecificService(Mem_43_EXFLS_InstanceIdType     InstanceId,
                                              Mem_43_EXFLS_HwServiceIdType    HwServiceId,
                                              Mem_43_EXFLS_DataType         * DataPtr,
                                              Mem_43_EXFLS_LengthType       * LengthPtr
                                             )
{
    Std_ReturnType RetVal = E_MEM_SERVICE_NOT_AVAIL;
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;
#endif
#if (MEM_43_EXFLS_SERVICE_COMPARE == STD_ON)
    const Mem_43_EXFLS_CompareConfigType*  pCompareConfig = (Mem_43_EXFLS_CompareConfigType *)DataPtr;
#endif

#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_EXFLS_ValidateModuleInitialized();
    if (MEM_43_EXFLS_E_OK == ErrorId)
    {
        uint32 Index = Mem_43_EXFLS_GetInstanceIndex(InstanceId);
        /* If module has been initialized, check if instanceIndex invalid*/
        if (MEM_43_EXFLS_MEM_INSTANCE_INDEX_INVALID == Index)
        {
            /* The provided InstanceId is inconsistent with the configuration */
            ErrorId = MEM_43_EXFLS_E_PARAM_INSTANCE_ID;
        }

        if (MEM_43_EXFLS_E_OK == ErrorId)
        {
            /* If module has been initialized, instanceIndex is valid, check if DataPtr or LengthPtr is NULL*/
            if ((NULL_PTR == DataPtr)||(NULL_PTR == LengthPtr))
            {
                ErrorId = MEM_43_EXFLS_E_PARAM_POINTER;
            }
#if (MEM_43_EXFLS_SERVICE_COMPARE == STD_ON)
            if (MEM_43_EXFLS_E_OK == ErrorId){
                /* If module has been initialized, instanceIndex is valid, DataPtr or LengthPtr is not NULL, check if size of LengthPtr is invalid length*/
                if (sizeof(Mem_43_EXFLS_CompareConfigType) != *LengthPtr)
                {
                    ErrorId = MEM_43_EXFLS_E_PARAM_LENGTH;
                }
            }
#endif  /* MEM_43_EXFLS_SERVICE_COMPARE == STD_ON */
        }
    }

    if (MEM_43_EXFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error MEM_E_UNINIT or MEM_E_PARAM_INSTANCE_ID or MEM_E_PARAM_POINTER or MEM_E_PARAM_LENGTH*/
        Mem_43_EXFLS_ReportDevError(InstanceId, MEM_43_EXFLS_HWSPECIFICSERVICE_ID, ErrorId);
    }
    else
    {
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */
#if (MEM_43_EXFLS_SERVICE_COMPARE == STD_ON)
        if (MEM_43_EXFLS_HWSERVICEID_COMPARE == HwServiceId)
        {
            RetVal = Mem_43_EXFLS_Compare(InstanceId, pCompareConfig->compareAddr, pCompareConfig->dataSourcePtr, pCompareConfig->length);
        }
#else   /* MEM_43_EXFLS_SERVICE_COMPARE == STD_ON */
        (void)HwServiceId;
#endif  /* MEM_43_EXFLS_SERVICE_COMPARE == STD_ON */
#if (MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON)
    }
    (void)HwServiceId;
#else
    (void)DataPtr;
    (void)InstanceId;
    (void)LengthPtr;
#endif /* MEM_43_EXFLS_DEV_ERROR_DETECT == STD_ON */
    return RetVal;
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Scheduled Functions)
==================================================================================================*/

/**
 * @brief            Service to handle the requested jobs and the internal management operations.
 *
 * @details          Service to handle the requested jobs and the internal management operations.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @note             This function have to be called cyclically by the Basic Software Module;
 *                   it will do nothing if there aren't pending job.
 *
 * @implements       Mem_43_EXFLS_MainFunction_Activity
 */
void Mem_43_EXFLS_MainFunction(void)
{
    uint32 InstanceIndex;

    /* SWS_BSW_00037 - If the module is not initialized and the main function is executed
       then no error shall be reported and the main function shall return immediately.
    */
    if (NULL_PTR != Mem_43_EXFLS_pConfigPtr)
    {
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_EXFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_EXFLS_JOB_PENDING == Mem_43_EXFLS_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
#if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
                /*Check if the core is the core that requested the job*/
                if (OsIf_GetUserId() == Mem_43_EXFLS_eJobRuntimeInfo[InstanceIndex].PartitionId)
#endif
                {
                    /* Process the requested job for this mem instance */
                    Mem_43_EXFLS_ProcessRequestedJobs(InstanceIndex);
                }
            }
        }
    }
}


#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

