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

#ifndef MEM_43_EXFLS_TYPES_H
#define MEM_43_EXFLS_TYPES_H

/**
*   @file Mem_43_EXFLS_Types.h
*
*   @addtogroup MEM_43_EXFLS
*   @implements Mem_43_EXFLS_Types.h_Artifact
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
#include "Std_Types.h"
#include "Mem_43_EXFLS_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_TYPES_VENDOR_ID                      43
#define MEM_43_EXFLS_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MEM_43_EXFLS_TYPES_AR_RELEASE_MINOR_VERSION       7
#define MEM_43_EXFLS_TYPES_AR_RELEASE_REVISION_VERSION    0
#define MEM_43_EXFLS_TYPES_SW_MAJOR_VERSION               5
#define MEM_43_EXFLS_TYPES_SW_MINOR_VERSION               0
#define MEM_43_EXFLS_TYPES_SW_PATCH_VERSION               0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same Autosar version */
    #if ((MEM_43_EXFLS_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EXFLS_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_EXFLS_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if current file and Mem_43_EXFLS_Ipw_Types.h header file are of the same vendor */
#if (MEM_43_EXFLS_TYPES_VENDOR_ID != MEM_43_EXFLS_IPW_TYPES_VENDOR_ID)
    #error "Mem_43_EXFLS_Types.h and Mem_43_EXFLS_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EXFLS_Ipw_Types.h header file are of the same Autosar version */
#if ((MEM_43_EXFLS_TYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_EXFLS_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EXFLS_TYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_EXFLS_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EXFLS_TYPES_AR_RELEASE_REVISION_VERSION != MEM_43_EXFLS_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EXFLS_Types.h and Mem_43_EXFLS_Ipw_Types.h are different"
#endif
/* Check if current file and Mem_43_EXFLS_Ipw_Types.h header file are of the same Software version */
#if ((MEM_43_EXFLS_TYPES_SW_MAJOR_VERSION != MEM_43_EXFLS_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MEM_43_EXFLS_TYPES_SW_MINOR_VERSION != MEM_43_EXFLS_IPW_TYPES_SW_MINOR_VERSION) || \
     (MEM_43_EXFLS_TYPES_SW_PATCH_VERSION != MEM_43_EXFLS_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EXFLS_Types.h and Mem_43_EXFLS_Ipw_Types.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Job flags */
#define MEM_43_EXFLS_JOB_FLAG_NONE                        0x00U     /* Initial value                               */
#define MEM_43_EXFLS_JOB_FLAG_STARTED                     0x01U     /* Indicates that new job has been accepted    */

/* Define ServiceId for Compare feature */
#define MEM_43_EXFLS_HWSERVICEID_COMPARE                  0x11U

/*==================================================================================================
                                             TYPEDEFS
==================================================================================================*/

/**
* @brief          Mem Address Type
* @details        Physical memory device address type
* @implements     Mem_43_EXFLS_AddressType_typedef
*/
typedef MEM_43_EXFLS_ADDRESSTYPE Mem_43_EXFLS_AddressType;


/**
* @brief          Mem Instance Id Type
* @details        Mem Instance Id Type
* @implements     Mem_43_EXFLS_InstanceIdType_typedef
*/
typedef uint32 Mem_43_EXFLS_InstanceIdType;


/**
* @brief          Mem Length Type
* @details        Physical memory device length type
* @implements     Mem_43_EXFLS_LengthType_typedef
*/
typedef MEM_43_EXFLS_LENGTHTYPE Mem_43_EXFLS_LengthType;


/**
* @brief          Mem Data Type
* @details        Read data user buffer type
* @implements     Mem_43_EXFLS_DataType_typedef
*/
typedef uint8 Mem_43_EXFLS_DataType;


/**
* brief          Size of data to be processeed by CRC.
*/
typedef enum
{
    CRC_8_BITS = 0,
    CRC_16_BITS
} Mem_43_EXFLS_CrcDataSizeType;


/**
* @brief          Mem CRC Type
* @details        CRC computed over config set
*/
typedef uint16 Mem_43_EXFLS_CrcType;


/**
* @brief          Mem Hardware Service Id Type
* @details        Hardware specific service request identifier type
* @implements     Mem_43_EXFLS_HwServiceIdType_typedef
*/
typedef uint32 Mem_43_EXFLS_HwServiceIdType;


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief        Mem job result type
*               Mem_43_EXFLS_JobResultType_typedef
*/
typedef enum
{
    MEM_43_EXFLS_JOB_OK                 = 0x00,    /* The last job has been finished successfully                                    */
    MEM_43_EXFLS_JOB_PENDING            = 0x01,    /* A job is currently being processed                                             */
    MEM_43_EXFLS_JOB_FAILED             = 0x02,    /* Job failed for some unspecific reason                                          */
    MEM_43_EXFLS_INCONSISTENT           = 0x03,    /* The checked page is not blank                                                  */
    MEM_43_EXFLS_ECC_UNCORRECTED        = 0x04,    /* Uncorrectable ECC errors occurred during memory access                         */
    MEM_43_EXFLS_ECC_CORRECTED          = 0x05     /* Correctable ECC errors occurred during memory access                           */
} Mem_43_EXFLS_JobResultType;


/**
* @brief          Type of job currently executed by Mem_43_EXFLS_MainFunction.
*/
typedef enum
{
    MEM_43_EXFLS_JOB_NONE               = 0x00,    /* no job executed                                                                */
    MEM_43_EXFLS_JOB_ERASE              = 0x01,    /* erase one or more complete flash sectors                                       */
    MEM_43_EXFLS_JOB_WRITE              = 0x02,    /* write one or more complete flash pages                                         */
    MEM_43_EXFLS_JOB_READ               = 0x03,    /* read one or more bytes from flash memory                                       */
    MEM_43_EXFLS_JOB_COMPARE            = 0x04,    /* compare data buffer with content of flash memory                               */
    MEM_43_EXFLS_JOB_BLANK_CHECK        = 0x05,    /* check content of erased flash memory area                                      */
    MEM_43_EXFLS_JOB_ERASESUSPEND       = 0x06,    /* suspend erase job                                                              */
    MEM_43_EXFLS_JOB_WRITESUSPEND       = 0x07,    /* suspend write job                                                              */
    MEM_43_EXFLS_JOB_ERASERESUME        = 0x08,    /* resume erase job                                                               */
    MEM_43_EXFLS_JOB_WRITERESUME        = 0x09     /* resume write job                                                              */
} Mem_43_EXFLS_JobType;


/*==================================================================================================
                                        CONFIGURATION STRUCTURES
==================================================================================================*/

/**
* @brief          Sector Batch Type
* @details        Sector Batch data structure for group of identical sectors
*                 Note: burst sizes equal to normal sizes in case burst disabled
*/
typedef struct
{
    const Mem_43_EXFLS_AddressType    StartAddress;       /* Physical start address of the sector batch                              */
    const Mem_43_EXFLS_AddressType    EndAddress;         /* Physical end address of the sector batch                                */
    const uint32                   SectorSize;         /* Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                   ReadPageSize;       /* Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                   WritePageSize;      /* Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                   EraseBurstSize;     /* Size of sector erase burst in bytes (for improved performance)          */
    const uint32                   ReadBurstSize;      /* Size of page read burst in bytes (for improved performance)             */
    const uint32                   WriteBurstSize;     /* Size of page write/program burst in bytes (for improved performance)    */
} Mem_43_EXFLS_SectorBatchType;


/**
* @brief          Mem Instance Type
* @details        Mem Instance data structure
*/
typedef struct
{
    const Mem_43_EXFLS_InstanceIdType     InstanceId;          /* Unique numeric identifier for each a Mem driver instance           */
    const uint32                       SectorBatchCount;    /* Number of sector batches in this Mem instance                      */
    const Mem_43_EXFLS_SectorBatchType   *SectorBatches;       /* Point to first element in array of sector batches configurations   */
    const uint8                        MemUnitIndex;        /* Index of flash memory unit used for this Mem instance              */
} Mem_43_EXFLS_MemInstanceType;


/**
* @brief          Mem Configuration Type
* @details        Mem module initialization data structure
* @implements     Mem_43_EXFLS_ConfigType_typedef
*/
typedef struct
{
    const Mem_43_EXFLS_MemInstanceType   *MemInstances;        /* Point to first element in array of mem instances configurations    */
    const Mem_43_EXFLS_MemDeviceType     *MemDevices;          /* Mem devices configurations used by the mem instance                */
#if (STD_ON == MEM_43_EXFLS_CHECK_CFG_CRC)
    Mem_43_EXFLS_CrcType u16ConfigCrc;
#endif
} Mem_43_EXFLS_ConfigType;


/**
* @brief          Mem_43_EXFLS Compare Configuration Type
* @details        Mem_43_EXFLS Compare data structure for dataPtr of HwSpecificService
*
*                 Mem_43_EXFLS_CompareConfigType
*/
typedef struct
{
    Mem_43_EXFLS_AddressType compareAddr;
    Mem_43_EXFLS_DataType* dataSourcePtr;
    Mem_43_EXFLS_LengthType length;
} Mem_43_EXFLS_CompareConfigType;

/*==================================================================================================
                                        INTERNAL TYPES
==================================================================================================*/

/**
* @brief          Mem job runtime information Type
* @details        This structure contains runtime information the current processing job of each Mem instance.
*/
typedef struct
{
    /* Input information */
    Mem_43_EXFLS_InstanceIdType            InstanceId;         /* Unique numeric identifier for each a Mem driver instance           */
    Mem_43_EXFLS_JobType                   JobType;            /* Type of currently executed job (Erase, Write, or Read)             */
    Mem_43_EXFLS_AddressType               Address;            /* Last physical address to be processed                              */
    Mem_43_EXFLS_DataType                 *DataPtr;            /* Pointer to user data buffer (used in Read and Write)               */
    Mem_43_EXFLS_LengthType                Length;             /* Remaining bytes of data to be processed                            */
    /* Output result of the parameter checking stage */
    uint32                                 InstanceIndex;                       /* The mem index number according to the mem instance id              */
    const Mem_43_EXFLS_SectorBatchType    *SectorBatch;        /* The sector batch to be worked with the request job                 */
    /* Runtime information */
    Mem_43_EXFLS_JobResultType             JobResult;          /* The result of the most recent job                                  */
    uint8                                  JobFlags;                            /* Job information (Started state, burst mode)                        */
#if (STD_ON == MEM_43_EXFLS_MULTICORE_ENABLED)
    uint8                                  PartitionId;                         /* Running PartitionId                                                */
#endif
} Mem_43_EXFLS_JobRuntimeInfoType;


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* MEM_43_EXFLS_TYPES_H */

