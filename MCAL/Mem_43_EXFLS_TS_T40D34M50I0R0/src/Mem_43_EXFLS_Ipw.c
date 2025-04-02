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
*   @file Mem_43_EXFLS_Ipw.c
*
*   @addtogroup MEM_43_EXFLS
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
#include "Det.h"
#include "OsIf.h"
#include "Mem_43_EXFLS.h"
#include "Mem_43_EXFLS_Ipw.h"
#include "Qspi_Ip.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_IPW_VENDOR_ID_C                           43
#define MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION_C            7
#define MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define MEM_43_EXFLS_IPW_SW_MAJOR_VERSION_C                    5
#define MEM_43_EXFLS_IPW_SW_MINOR_VERSION_C                    0
#define MEM_43_EXFLS_IPW_SW_PATCH_VERSION_C                    0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_EXFLS.h header file are of the same vendor */
#if (MEM_43_EXFLS_IPW_VENDOR_ID_C != MEM_43_EXFLS_VENDOR_ID)
    #error "Mem_43_EXFLS_Ipw.c and Mem_43_EXFLS.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EXFLS.h header file are of the same Autosar version */
#if ((MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EXFLS_Ipw.c and Mem_43_EXFLS.h are different"
#endif
/* Check if current file and Mem_43_EXFLS.h header file are of the same Software version */
#if ((MEM_43_EXFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_EXFLS_SW_MAJOR_VERSION) || \
     (MEM_43_EXFLS_IPW_SW_MINOR_VERSION_C != MEM_43_EXFLS_SW_MINOR_VERSION) || \
     (MEM_43_EXFLS_IPW_SW_PATCH_VERSION_C != MEM_43_EXFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EXFLS_Ipw.c and Mem_43_EXFLS.h are different"
#endif

/* Check if current file and Mem_43_EXFLS_Ipw.h header file are of the same vendor */
#if (MEM_43_EXFLS_IPW_VENDOR_ID_C != MEM_43_EXFLS_IPW_VENDOR_ID)
    #error "Mem_43_EXFLS_Ipw.c and Mem_43_EXFLS_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EXFLS_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EXFLS_Ipw.c and Mem_43_EXFLS_Ipw.h are different"
#endif
/* Check if current file and Mem_43_EXFLS_Ipw.h header file are of the same Software version */
#if ((MEM_43_EXFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_EXFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_EXFLS_IPW_SW_MINOR_VERSION_C != MEM_43_EXFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_EXFLS_IPW_SW_PATCH_VERSION_C != MEM_43_EXFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EXFLS_Ipw.c and Mem_43_EXFLS_Ipw.h are different"
#endif

/* Check if current file and Qspi_Ip.h header file are of the same vendor */
#if (MEM_43_EXFLS_IPW_VENDOR_ID_C != QSPI_IP_VENDOR_ID_H)
    #error "Mem_43_EXFLS_Ipw.c and Qspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip.h header file are of the same Autosar version */
#if ((MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_EXFLS_Ipw.c and Qspi_Ip.h are different"
#endif
/* Check if current file and Qspi_Ip.h header file are of the same Software version */
#if ((MEM_43_EXFLS_IPW_SW_MAJOR_VERSION_C != QSPI_IP_SW_MAJOR_VERSION_H) || \
     (MEM_43_EXFLS_IPW_SW_MINOR_VERSION_C != QSPI_IP_SW_MINOR_VERSION_H) || \
     (MEM_43_EXFLS_IPW_SW_PATCH_VERSION_C != QSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_EXFLS_Ipw.c and Qspi_Ip.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if (MEM_43_EXFLS_DEVICES_USING_SFDP > 0)

#define MEM_43_EXFLS_QSPI_SFDP_LUT_SIZE               (130U)
#define MEM_43_EXFLS_QSPI_SFDP_INIT_OP_SIZE           (4U * 2U)    /* Double size for insert wait operations */

typedef struct
{
    Qspi_Ip_InstrOpType         lutOps[MEM_43_EXFLS_QSPI_SFDP_LUT_SIZE];       /*!< Array for virtual LUT instructions   */
    Qspi_Ip_InitOperationType   initOps[MEM_43_EXFLS_QSPI_SFDP_INIT_OP_SIZE];  /*!< Array for initial operations         */
    Qspi_Ip_MemoryConfigType    sfdpCfg;                                     /*!< Flash device configuration structure */
} Mem_43_EXFLS_Qspi_SfdpConfigType;

#endif


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


#if (MEM_43_EXFLS_DEVICES_USING_SFDP > 0)

/* Array of configurations for flash devices configured to use SFDP  */
static Mem_43_EXFLS_Qspi_SfdpConfigType  Mem_43_EXFLS_Ipw_axSfdpConfigs[MEM_43_EXFLS_DEVICES_USING_SFDP];

/* Configurations indexes for flash devices configured to use SFDP   */
static uint8                           Mem_43_EXFLS_Ipw_au8SfdpConfigsIndex[MEM_43_EXFLS_MEM_UNIT_COUNT];

#endif


#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

#if (MEM_43_EXFLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

/* Counters for timeout detection */
static uint32 Mem_43_EXFLS_Ipw_u32QspiElapsedTicks[MEM_43_EXFLS_MEM_INSTANCE_COUNT];
static uint32 Mem_43_EXFLS_Ipw_u32QspiTimeoutTicks[MEM_43_EXFLS_MEM_INSTANCE_COUNT];
static uint32 Mem_43_EXFLS_Ipw_u32QspiCurrentTicks[MEM_43_EXFLS_MEM_INSTANCE_COUNT];

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_32
#include "Mem_43_EXFLS_MemMap.h"

#endif
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


static Std_ReturnType Mem_43_EXFLS_IPW_InitControllers(void);

static Std_ReturnType Mem_43_EXFLS_IPW_InitMemories(void);

static const Qspi_Ip_MemoryConfigType * Mem_43_EXFLS_IPW_GetMemoryConfig(uint32 MemUnitIndex);


#if (MEM_43_EXFLS_DEVICES_USING_SFDP > 0)

static const Qspi_Ip_MemoryConfigType * Mem_43_EXFLS_IPW_ReadSfdp(const  Qspi_Ip_MemoryConnectionType *MemConnect,
                                                                  uint32 SfdpConfigsCount
                                                                 );

#endif


static Std_ReturnType Mem_43_EXFLS_IPW_CheckDevicesId(void);

static Std_ReturnType Mem_43_EXFLS_IPW_DeviceIdMatches(uint32 Instance,
                                                       const Qspi_Ip_MemoryConfigType * pConfig
                                                      );


#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/*
 * Description:    Get the memory unit index of the memory instance
*/
static inline uint32 Mem_43_EXFLS_IPW_GetMemoryUnitIndex(uint32 InstanceIndex)
{
    /* Get the memory unit index */
    return (Mem_43_EXFLS_pConfigPtr->MemInstances[InstanceIndex].MemUnitIndex);
}


/*
 * Description:    Update the job status after processing a chunk
*/
static void Mem_43_EXFLS_IPW_UpdateJobProcessedLength(Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo,
                                                      Mem_43_EXFLS_LengthType            TransferLength
                                                     )
{
    /* Move to the next chunk of job */
    JobInfo->Address += TransferLength;
    JobInfo->Length  -= TransferLength;

    /* Update data buffer pointer if required */
    if (NULL_PTR != JobInfo->DataPtr)
    {
        JobInfo->DataPtr = &(JobInfo->DataPtr[TransferLength]);
    }
}


/**
 * @brief    Computes the size for an erase job.
 *           Based on physical hardware capability and device sector size boundary.
*/
static Mem_43_EXFLS_LengthType Mem_43_EXFLS_IPW_ComputeEraseLength(const Mem_43_EXFLS_JobRuntimeInfoType *JobInfo)
{
    Mem_43_EXFLS_LengthType EraseLength = JobInfo->SectorBatch->SectorSize;  /* default is normal size */
    const uint32 BurstSize           = JobInfo->SectorBatch->EraseBurstSize;

    /* Check for burst mode */
    if ((0U == (JobInfo->Address % BurstSize)) &&
        (0U == (JobInfo->Length  % BurstSize))
       )
    {
        /* Both start address and length are aligned with the burst setting */
        EraseLength = BurstSize;
    }

    return EraseLength;
}


/**
 * @brief    Computes the size of the next chunk of a write job.
 *           Based on physical hardware capability and device page size boundary.
*/
static Mem_43_EXFLS_LengthType Mem_43_EXFLS_IPW_ComputeWriteLength(const Mem_43_EXFLS_JobRuntimeInfoType    *JobInfo,
                                                                   uint32                                 MemUnitIndex
                                                                  )
{
    uint32 WriteLength = JobInfo->Length;  /* the remaining length of the job */

    /* Step 1
     * Check external device restrictions: WriteLength can not exceed the device page size
     * If address is not aligned, max. WriteLength is the amount left in the current page
     */
    /* Get configuration for current flash memory device */
    const Qspi_Ip_MemoryConfigType *MemCfg = Mem_43_EXFLS_IPW_GetMemoryConfig(MemUnitIndex);
    const uint32 MemoryMaxWriteLength      = MemCfg->pageSize - (JobInfo->Address % MemCfg->pageSize);
    if (WriteLength > MemoryMaxWriteLength)
    {
        WriteLength = MemoryMaxWriteLength;
    }

    /* Step 2
     * Check if chunk does not exceed IP driver capabilities
     * Reserve size for padding in case of writing from odd starting address
     */
    const Mem_43_EXFLS_MemoryUnitType *MemUnit = &(Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits[MemUnitIndex]);
    const uint32 MemAlignment       = MemUnit->Connect->memAlignment;
    const uint32 AddressOffset      = JobInfo->Address & (MemAlignment - 1U);
    const uint32 QspiMaxWriteLength = FEATURE_QSPI_TX_BUF_SIZE - AddressOffset;
    if (WriteLength > QspiMaxWriteLength)
    {
        WriteLength = QspiMaxWriteLength;
    }

    return WriteLength;
}


/*
 * Description:    Compute the number of bytes to read for the current job.
*/
static Mem_43_EXFLS_LengthType Mem_43_EXFLS_IPW_ComputeReadLength(const Mem_43_EXFLS_JobRuntimeInfoType *JobInfo)
{
    Mem_43_EXFLS_LengthType ReadLength = JobInfo->Length;

    /* Adjust size based on hardware controller capability */
    if (ReadLength > QSPI_IP_MAX_READ_SIZE)
    {
        ReadLength = QSPI_IP_MAX_READ_SIZE;
    }

    return ReadLength;
}


/*
 * Description   : Retrieves flash configuration for the current flash memory unit
*/
static const Qspi_Ip_MemoryConfigType * Mem_43_EXFLS_IPW_GetMemoryConfig(uint32 MemUnitIndex)
{
    const Qspi_Ip_MemoryConfigType *MemCfg = Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits[MemUnitIndex].Config;

#if (MEM_43_EXFLS_DEVICES_USING_SFDP > 0)
    uint8 SfdpConfigIndex;
    if (NULL_PTR == MemCfg)
    {
        /* SFDP auto-filled configuration */
        SfdpConfigIndex = Mem_43_EXFLS_Ipw_au8SfdpConfigsIndex[MemUnitIndex];
        MemCfg = &(Mem_43_EXFLS_Ipw_axSfdpConfigs[SfdpConfigIndex].sfdpCfg);
    }
#endif

    return MemCfg;
}


/*
 * Description   : Initialize QSPI controllers
*/
static Std_ReturnType Mem_43_EXFLS_IPW_InitControllers(void)
{
    const  Mem_43_EXFLS_QspiUnitType *QspiUnits = Mem_43_EXFLS_pConfigPtr->MemDevices->QspiUnits;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Qspi_Ip_StatusType Status;
    uint32 Unit;

    for (Unit = 0U; Unit < MEM_43_EXFLS_MEM_UNIT_COUNT; Unit++)
    {
        if (NULL_PTR != QspiUnits[Unit].Config)
        {
            /* Use configuration "Config" to initialize QSPI controller "HardwareInstance" */
            Status = Qspi_Ip_ControllerInit(QspiUnits[Unit].HardwareInstance, QspiUnits[Unit].Config);
            if (STATUS_QSPI_IP_SUCCESS != Status)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }

    return RetVal;
}


/*
 * Description   : Initialize Qspi external flash devices
*/
static Std_ReturnType Mem_43_EXFLS_IPW_InitMemories(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Qspi_Ip_StatusType Status = STATUS_QSPI_IP_SUCCESS;
    const  Mem_43_EXFLS_MemoryUnitType   *MemUnits = Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits;
    const Qspi_Ip_MemoryConnectionType *MemConnect;
    const Qspi_Ip_MemoryConfigType     *MemCfg;
    uint32 Unit;

#if (MEM_43_EXFLS_DEVICES_USING_SFDP > 0)
    uint32 SfdpConfigsCount = 0U;    /* Current SFDP configuration  */
#endif

    for (Unit = 0U; Unit < MEM_43_EXFLS_MEM_UNIT_COUNT; Unit++)
    {
        MemCfg     = MemUnits[Unit].Config;
        MemConnect = MemUnits[Unit].Connect;

#if (MEM_43_EXFLS_DEVICES_USING_SFDP > 0)
        if (NULL_PTR == MemCfg)
        {
            /* Use SFDP auto-filled configuration for this flash memory unit */
            MemCfg = Mem_43_EXFLS_IPW_ReadSfdp(MemConnect, SfdpConfigsCount);

            /* Store index to allow configuration to be retrieved later */
            Mem_43_EXFLS_Ipw_au8SfdpConfigsIndex[Unit] = SfdpConfigsCount;
            SfdpConfigsCount++;

            if (NULL_PTR == MemCfg)
            {
                /* Read SFDP failed */
                Status = STATUS_QSPI_IP_ERROR;
            }
        }
        if (STATUS_QSPI_IP_SUCCESS == Status)
        {
            /* Use configuration "Config" to initialize flash device "Unit" at "Connect" */
            Status = Qspi_Ip_Init(Unit, MemCfg, MemConnect);
        }
#else
        /* Use configuration "Config" to initialize flash device "Unit" at "Connect" */
        Status = Qspi_Ip_Init(Unit, MemCfg, MemConnect);
#endif

        if ((STATUS_QSPI_IP_SUCCESS == Status) && ((boolean)TRUE == MemUnits[Unit].AHBRead))
        {
            /* Configure the AHB reads for memory flash "Unit" */
            Status = Qspi_Ip_AhbReadEnable(Unit);
        }

        if ((STATUS_QSPI_IP_SUCCESS == Status) && ((boolean)TRUE == MemUnits[Unit].AHBWrite))
        {
            /* Configure the AHB writes for memory flash "Unit" */
            Status = Qspi_Ip_AhbWriteEnable(Unit);
        }

        if (STATUS_QSPI_IP_SUCCESS != Status)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return RetVal;
}


#if (MEM_43_EXFLS_DEVICES_USING_SFDP > 0)
/*
 * Description   : Build the flash configuration based on SFDP tables information
*/
static const Qspi_Ip_MemoryConfigType * Mem_43_EXFLS_IPW_ReadSfdp(const  Qspi_Ip_MemoryConnectionType *MemConnect,
                                                                  uint32 SfdpConfigsCount
                                                                 )
{
    Qspi_Ip_MemoryConfigType *MemCfg;
    Qspi_Ip_StatusType Status;

    /* Prepare configuration structure, link lut and init operations arrays */
    MemCfg = &(Mem_43_EXFLS_Ipw_axSfdpConfigs[SfdpConfigsCount].sfdpCfg);
    MemCfg->memType                      = QSPI_IP_SERIAL_FLASH;
    MemCfg->lutSequences.opCount         = MEM_43_EXFLS_QSPI_SFDP_LUT_SIZE;
    MemCfg->lutSequences.lutOps          = Mem_43_EXFLS_Ipw_axSfdpConfigs[SfdpConfigsCount].lutOps;
    MemCfg->initConfiguration.opCount    = MEM_43_EXFLS_QSPI_SFDP_INIT_OP_SIZE;
    MemCfg->initConfiguration.operations = Mem_43_EXFLS_Ipw_axSfdpConfigs[SfdpConfigsCount].initOps;

    /* Read the SFDP tables information and build the flash configuration */
    Status = Qspi_Ip_ReadSfdp(MemCfg, MemConnect);
    if (STATUS_QSPI_IP_SUCCESS != Status)
    {
        /* Read SFDP failed */
        MemCfg = NULL_PTR;
    }

    return MemCfg;
}
#endif


/*
 * Description   : Check the identification of the external flash device against the configured one
*/
static Std_ReturnType Mem_43_EXFLS_IPW_CheckDevicesId(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    const Qspi_Ip_MemoryConfigType * MemCfg;
    uint32 MemUnit;

    for (MemUnit = 0U; MemUnit < MEM_43_EXFLS_MEM_UNIT_COUNT; MemUnit++)
    {
        /* Get configuration for current flash memory device */
        MemCfg = Mem_43_EXFLS_IPW_GetMemoryConfig(MemUnit);

        /* If enabled, check identification of the external flash device */
        if (QSPI_IP_LUT_INVALID != MemCfg->readIdSettings.readIdLut)
        {
            RetVal = Mem_43_EXFLS_IPW_DeviceIdMatches(MemUnit, MemCfg);
            if ((Std_ReturnType)E_OK != RetVal)
            {
                break;
            }
        }
    }

    return RetVal;
}


/*
 * Description   : Check the identification of one external flash device against the configured one
*/
static Std_ReturnType Mem_43_EXFLS_IPW_DeviceIdMatches(uint32 Instance,
                                                       const Qspi_Ip_MemoryConfigType *pConfig
                                                      )
{
    uint8 ReadIdActual[FEATURE_EXFLS_FLASH_MDID_SIZE];
    const uint32 IdSize = (uint32)(pConfig->readIdSettings.readIdSize);
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    Qspi_Ip_StatusType Status;
    uint32 Index;

    /* Read the device identification value */
    Status = Qspi_Ip_ReadId(Instance, ReadIdActual);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        /* Assign status is E_OK if the ID verification below is success */
        RetVal = (Std_ReturnType)E_OK;

        /* Verify the device identification */
        for (Index = 0U; Index < IdSize; Index++)
        {
            if (ReadIdActual[Index] != pConfig->readIdSettings.readIdExpected[Index])
            {
                /* Id value is not matched */
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }

    return RetVal;
}


/*
 * Description:    Check that external memory is idle and reset external memory
*/
static Qspi_Ip_StatusType Mem_43_EXFLS_IPW_CheckAndReset(uint32 InstanceIndex)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    /* Check that external memory is idle */
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_GetMemoryStatus(InstanceIndex))
    {
        /* Reset external memory */
        status = Qspi_Ip_Reset(InstanceIndex);
    }
    return status;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*
 * Function Name : Mem_43_EXFLS_IPW_Init
 * Description   : Initialize memory flash devices
 */
Std_ReturnType Mem_43_EXFLS_IPW_Init(void)
{
    Std_ReturnType RetVal;

#if (MEM_43_EXFLS_PERFORM_DEVICE_CONFIG == STD_ON)
    /* Initialize QSPI hardware controllers */
    RetVal = Mem_43_EXFLS_IPW_InitControllers();

    /* Initialize external flash devices */
    if ((Std_ReturnType)E_OK == RetVal)
    {
        RetVal = Mem_43_EXFLS_IPW_InitMemories();
    }

    /* Verify the hardware ID of the external flash devices */
    if ((Std_ReturnType)E_OK == RetVal)
    {
        RetVal = Mem_43_EXFLS_IPW_CheckDevicesId();
    }
#else
    RetVal = (Std_ReturnType)E_OK;
#endif

    return RetVal;
}

/*
 * Function Name : Mem_43_EXFLS_IPW_DeInit
 * Description   : De-Initialize memory flash devices
 */
void Mem_43_EXFLS_IPW_DeInit(uint32 InstanceIndex)
{
    (void)Qspi_Ip_Deinit(InstanceIndex);
}

/**
* @brief    Returns synchronously the result of the last job.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_GetJobResult(uint32 InstanceIndex,
                                                         Mem_43_EXFLS_JobType JobType
                                                        )
{
    Mem_43_EXFLS_JobResultType JobResult;
    Qspi_Ip_StatusType Status;
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(InstanceIndex);

    /* Check hardware status */
    Status = Qspi_Ip_GetMemoryStatus(MemUnitIndex);

    /*If enable timeout supervison, perform timeout check for erase/write job*/
#if (MEM_43_EXFLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    if ((MEM_43_EXFLS_JOB_ERASE == JobType) || (MEM_43_EXFLS_JOB_WRITE == JobType))
    {
        if (STATUS_QSPI_IP_BUSY == Status)
        {
            Mem_43_EXFLS_Ipw_u32QspiElapsedTicks[MemUnitIndex] += OsIf_GetElapsed(&Mem_43_EXFLS_Ipw_u32QspiCurrentTicks[MemUnitIndex], (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
            if (Mem_43_EXFLS_Ipw_u32QspiElapsedTicks[MemUnitIndex] >= Mem_43_EXFLS_Ipw_u32QspiTimeoutTicks[MemUnitIndex])
            {
                Status = STATUS_QSPI_IP_TIMEOUT;
            }
        }
    }
#else
    (void)JobType;
#endif

    switch (Status)
    {
        case STATUS_QSPI_IP_BUSY:
            /* The job is still being processed */
            JobResult = MEM_43_EXFLS_JOB_PENDING;
            break;

        case STATUS_QSPI_IP_SUCCESS:
            /* The job has completed */
            JobResult = MEM_43_EXFLS_JOB_OK;
            break;

        default:
            /* Timeout or hardware errors */
            JobResult = MEM_43_EXFLS_JOB_FAILED;
            break;
    }

    return JobResult;
}


/**
* @brief        Abort a suspended hardware job to prepare for a new job.
*
* @details      Check the hardware status and clear any suspended job.
*
*/
void Mem_43_EXFLS_IPW_AbortSuspended(uint32 InstanceIndex)
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(InstanceIndex);
    const Mem_43_EXFLS_MemoryUnitType *MemUnit = &(Mem_43_EXFLS_pConfigPtr->MemDevices->MemUnits[MemUnitIndex]);
    Qspi_Ip_StatusType Status;

    /* Prepare timeout counter */
    const uint32 TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_CMD_COMPLETE_TIMEOUT, QSPI_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(QSPI_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0U;

    /* Wait for the controller to become idle */
    do
    {
        Status = Qspi_Ip_ControllerGetStatus(MemUnit->Connect->qspiInstance);
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, QSPI_IP_TIMEOUT_TYPE);
        if ((STATUS_QSPI_IP_BUSY == Status) && (ElapsedTicks >= TimeoutTicks))
        {
            Status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }
    }
    while (STATUS_QSPI_IP_BUSY == Status);

#if (MEM_43_EXFLS_HWUNIT_HANG_RECOVERY == STD_ON)
            if (STATUS_QSPI_IP_TIMEOUT == Status)
            {
                /* The controller is being stuck in BUSY state, perform the abort sequence */
                Status = Qspi_Ip_Abort(MemUnit->Connect->qspiInstance);
            }
#endif /* (MEM_43_EXFLS_HWUNIT_HANG_RECOVERY == STD_ON) */

    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        Status = Mem_43_EXFLS_IPW_CheckAndReset(MemUnitIndex);
    }

    (void)Status;
}


/**
* @brief          IP wrapper read function.
* @details        Route the read job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Read(uint32                          InstanceIndex,
                                                 Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                )
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(InstanceIndex);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Mem_43_EXFLS_LengthType TransferLength;
    Qspi_Ip_StatusType Status;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_EXFLS_IPW_ComputeReadLength(JobInfo);

    /* Read data from flash memory device */
    Status = Qspi_Ip_Read(MemUnitIndex, JobInfo->Address, JobInfo->DataPtr, TransferLength);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        /* The Read operations are SYNC, so the job result is OK immediately without PENDING state */
        JobResult = MEM_43_EXFLS_JOB_OK;

        /* Update job state */
        Mem_43_EXFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
    }

    return JobResult;
}


/**
* @brief          IP wrapper blank check function.
* @details        Route the blank check job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_BlankCheck(uint32                          InstanceIndex,
                                                       Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                      )
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(InstanceIndex);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Mem_43_EXFLS_LengthType TransferLength;
    Qspi_Ip_StatusType Status;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_EXFLS_IPW_ComputeReadLength(JobInfo);

    /* Read data from flash memory device and verify that it is in erased state */
    Status = Qspi_Ip_EraseVerify(MemUnitIndex, JobInfo->Address, TransferLength);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        /* The Read operations are SYNC, so the job result is OK immediately without PENDING state */
        JobResult = MEM_43_EXFLS_JOB_OK;

        /* Update job state */
        Mem_43_EXFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
    }
    else
    {
        if (STATUS_QSPI_IP_ERROR_BLANK_CHECK == Status)
        {
            /* The memory area is not in the erased state */
            JobResult = MEM_43_EXFLS_INCONSISTENT;
        }
    }

    return JobResult;
}


/**
* @brief          IP wrapper sector function.
* @details        Route the erase job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Erase(uint32                          InstanceIndex,
                                                  Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                 )
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(InstanceIndex);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Mem_43_EXFLS_LengthType TransferLength;
    Qspi_Ip_StatusType Status;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_EXFLS_IPW_ComputeEraseLength(JobInfo);

    /* Call IP routine to erase external flash memory sector */
    Status = Qspi_Ip_EraseBlock(MemUnitIndex, JobInfo->Address, TransferLength);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        /* Command is sent, the actual job is being processed in the memory device */
        JobResult = MEM_43_EXFLS_JOB_PENDING;

        /* Update job state */
        Mem_43_EXFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);

#if (MEM_43_EXFLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        /* Prepare timeout counter */
        Mem_43_EXFLS_Ipw_u32QspiElapsedTicks[MemUnitIndex] = 0U;
        Mem_43_EXFLS_Ipw_u32QspiTimeoutTicks[MemUnitIndex] = OsIf_MicrosToTicks(MEM_43_EXFLS_QSPI_ERASE_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
        Mem_43_EXFLS_Ipw_u32QspiCurrentTicks[MemUnitIndex] = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
#endif /* (MEM_43_EXFLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
    }

    return JobResult;
}


/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Write(uint32                          InstanceIndex,
                                                  Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                 )
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(InstanceIndex);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Mem_43_EXFLS_LengthType TransferLength;
    Qspi_Ip_StatusType Status;

    /* Calculate length of data transfer */
    TransferLength = Mem_43_EXFLS_IPW_ComputeWriteLength(JobInfo, MemUnitIndex);

    /* Call IP routine to write data to external flash memory */
    Status = Qspi_Ip_Program(MemUnitIndex, JobInfo->Address, JobInfo->DataPtr, TransferLength);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        /* Command is sent, the actual job is being processed in the memory device */
        JobResult = MEM_43_EXFLS_JOB_PENDING;

        /* Update job state */
        Mem_43_EXFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);

#if (MEM_43_EXFLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        /* Prepare timeout counter */
        Mem_43_EXFLS_Ipw_u32QspiElapsedTicks[MemUnitIndex] = 0U;
        Mem_43_EXFLS_Ipw_u32QspiTimeoutTicks[MemUnitIndex] = OsIf_MicrosToTicks(MEM_43_EXFLS_QSPI_WRITE_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
        Mem_43_EXFLS_Ipw_u32QspiCurrentTicks[MemUnitIndex] = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
#endif /* (MEM_43_EXFLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
    }

    return JobResult;
}

#if (MEM_43_EXFLS_SERVICE_COMPARE == STD_ON)
/**
* @brief          IP wrapper sector compare function.
* @details        Route the write job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Compare(uint32                          InstanceIndex,
                                                        Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                       )
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(InstanceIndex);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Mem_43_EXFLS_LengthType TransferLength;
    Qspi_Ip_StatusType Status;
    /* Calculate length of data transfer */
    TransferLength = Mem_43_EXFLS_IPW_ComputeReadLength(JobInfo);
    /* Compare data from flash memory device */
    Status = Qspi_Ip_ProgramVerify(MemUnitIndex, JobInfo->Address, JobInfo->DataPtr, TransferLength);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        /* The Comapre operations are SYNC, so the job result is OK immediately without PENDING state */
        JobResult = MEM_43_EXFLS_JOB_OK;
        /* Update job state */
        Mem_43_EXFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
    }
    return JobResult;
}
#endif

/**
* @brief          IP wrapper IsSupportEraseSupendResume function.
* @details        Route the IsSupportEraseSupendResume job to appropriate low level IP function.
*/
boolean Mem_43_EXFLS_IPW_IsSupportEraseSupendResume(uint32 Index)
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(Index);
    const Qspi_Ip_MemoryConfigType * MemCfg;
    boolean retVal = (boolean)TRUE;

    MemCfg = Mem_43_EXFLS_IPW_GetMemoryConfig(MemUnitIndex);
    if ((QSPI_IP_LUT_INVALID == MemCfg->suspendSettings.eraseSuspendLut) || (QSPI_IP_LUT_INVALID == MemCfg->suspendSettings.eraseResumeLut))
    {
        retVal = (boolean)FALSE;
    }
    return retVal;
}

/**
* @brief          IP wrapper IsSupportProgramSupendResume function.
* @details        Route the IsSupportProgramSupendResume job to appropriate low level IP function.
*/
boolean Mem_43_EXFLS_IPW_IsSupportProgramSupendResume(uint32 Index)
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(Index);
    const Qspi_Ip_MemoryConfigType * MemCfg;
    boolean retVal = (boolean)TRUE;

    MemCfg = Mem_43_EXFLS_IPW_GetMemoryConfig(MemUnitIndex);
    if ((QSPI_IP_LUT_INVALID == MemCfg->suspendSettings.programSuspendLut) || (QSPI_IP_LUT_INVALID == MemCfg->suspendSettings.programResumeLut))
    {
        retVal = (boolean)FALSE;
    }
    return retVal;
}

/**
* @brief          IP wrapper write_suspend function.
* @details        Route the write_suspend job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_WriteSuspend(uint32 Index)
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(Index);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Qspi_Ip_StatusType Status;

    Status = Qspi_Ip_ProgramSuspend(MemUnitIndex);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        JobResult = MEM_43_EXFLS_JOB_PENDING;
    }
    return JobResult;
}


/**
* @brief          IP wrapper erase_suspend function.
* @details        Route the erase_suspend job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_EraseSuspend(uint32 Index)
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(Index);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Qspi_Ip_StatusType Status;

    Status = Qspi_Ip_EraseSuspend(MemUnitIndex);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        JobResult = MEM_43_EXFLS_JOB_PENDING;
    }
    return JobResult;
}


/**
* @brief          IP wrapper write_resume function.
* @details        Route the write_resume job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_WriteResume(uint32 Index)
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(Index);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Qspi_Ip_StatusType Status;

    Status = Qspi_Ip_ProgramResume(MemUnitIndex);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        JobResult = MEM_43_EXFLS_JOB_PENDING;
    }
    return JobResult;
}


/**
* @brief          IP wrapper erase_resume function.
* @details        Route the erase_resume job to appropriate low level IP function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_EraseResume(uint32 Index)
{
    const uint32 MemUnitIndex = Mem_43_EXFLS_IPW_GetMemoryUnitIndex(Index);
    Mem_43_EXFLS_JobResultType JobResult = MEM_43_EXFLS_JOB_FAILED;
    Qspi_Ip_StatusType Status;

    Status = Qspi_Ip_EraseResume(MemUnitIndex);
    if (STATUS_QSPI_IP_SUCCESS == Status)
    {
        JobResult = MEM_43_EXFLS_JOB_PENDING;
    }
    return JobResult;
}

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
