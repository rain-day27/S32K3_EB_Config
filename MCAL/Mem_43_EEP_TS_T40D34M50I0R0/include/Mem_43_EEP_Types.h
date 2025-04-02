/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : IPV_USDHC
* Dependencies : 
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef MEM_43_EEP_TYPES_H
#define MEM_43_EEP_TYPES_H

/**
*   @file Mem_43_EEPTypes.h
*
* @addtogroup MEM_43_EEP_DRIVER Mem_43_EEProm Driver
* @{
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

#include "Mem_43_EEP_CfgDefines.h"

#include "Sd_Emmc_Ip_Types.h"
#include "Usdhc_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_TYPES_VENDOR_ID                    43
#define MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define MEM_43_EEP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define MEM_43_EEP_TYPES_SW_MAJOR_VERSION             5
#define MEM_43_EEP_TYPES_SW_MINOR_VERSION             0
#define MEM_43_EEP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Mem_43_EEP_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if current file and Mem_43_EEP_CfgDefines header file are of the same vendor */
#if (MEM_43_EEP_TYPES_VENDOR_ID != MEM_43_EEP_VENDOR_ID_CFG_DEFINES)
    #error "Mem_43_EEP_Types.h and Mem_43_EEP_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EEP_CfgDefines header file are of the same Autosar version */
#if ((MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Types.h and Mem_43_EEP_CfgDefines.h are different"
#endif
/* Check if current file and Mem_43_EEP_CfgDefines header file are of the same software version */
#if ((MEM_43_EEP_TYPES_SW_MAJOR_VERSION != MEM_43_EEP_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_TYPES_SW_MINOR_VERSION != MEM_43_EEP_SW_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_TYPES_SW_PATCH_VERSION != MEM_43_EEP_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Types.h and Mem_43_EEP_CfgDefines.h are different"
#endif

/* Check if current file and Sd_Emmc_Ip_Types header file are of the same vendor */
#if (MEM_43_EEP_TYPES_VENDOR_ID != SD_EMMC_IP_TYPES_VENDOR_ID)
    #error "Mem_43_EEP_Types.h and Sd_Emmc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same Autosar version */
#if ((MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION    != SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION    != SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_REVISION_VERSION != SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Types.h and Sd_Emmc_Ip_Types.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same software version */
#if ((MEM_43_EEP_TYPES_SW_MAJOR_VERSION != SD_EMMC_IP_TYPES_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_TYPES_SW_MINOR_VERSION != SD_EMMC_IP_TYPES_SW_MINOR_VERSION) || \
     (MEM_43_EEP_TYPES_SW_PATCH_VERSION != SD_EMMC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Types.h and Sd_Emmc_Ip_Types.h are different"
#endif

/* Check if current file and Usdhc_Ip_Types header file are of the same vendor */
#if (MEM_43_EEP_TYPES_VENDOR_ID != USDHC_IP_TYPES_VENDOR_ID_H)
    #error "Mem_43_EEP_Types.h and Usdhc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same Autosar version */
#if ((MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION    != USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION    != USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_REVISION_VERSION != USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Types.h and Usdhc_Ip_Types.h are different"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same software version */
#if ((MEM_43_EEP_TYPES_SW_MAJOR_VERSION != USDHC_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (MEM_43_EEP_TYPES_SW_MINOR_VERSION != USDHC_IP_TYPES_SW_MINOR_VERSION_H) || \
     (MEM_43_EEP_TYPES_SW_PATCH_VERSION != USDHC_IP_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Types.h and Usdhc_Ip_Types.h are different"
#endif


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MEM_43_EEP_CHECK_CFG_CRC == STD_ON)
/**
* @brief          Mem_43_EEP CRC Type.
* @details        CRC computed over config set.
*
*/
typedef uint16 Mem_43_EEP_CrcType;
#endif

/**
* @brief          Mem_43_EEP Address Type.
* @details        Physical memory device address type.
*
* @implements     Mem_43_EEP_AddressType_typedef
*/
typedef MEM_43_EEP_ADDRESSTYPE Mem_43_EEP_AddressType;

/**
* @brief          Mem_43_EEP Data Type.
* @details        Read data user buffer type.
*
* @implements     Mem_43_EEP_DataType_typedef
*/
typedef uint8 Mem_43_EEP_DataType;

/**
* @brief          Mem_43_EEP InstanceId Type.
* @details        Job end notification function called by Mem in case the job processing is
*                 configured for job end notification.
*
* @implements     Mem_43_EEP_InstanceIdType_typedef
*/
typedef uint32 Mem_43_EEP_InstanceIdType;

/**
* @brief           Asynchronous job result type.
* @implements     Mem_43_EEP_JobResultType_typedef
*/
typedef enum
{
    /**
    * @brief The last job has been finished successfully
    */
    MEM_43_EEP_JOB_OK,
    /**
    * @brief A job is currently being processed
    */
    MEM_43_EEP_JOB_PENDING,
    /**
    * @brief Job failed for some unspecific reason
    */
    MEM_43_EEP_JOB_FAILED,
    /**
    * @brief The checked page is not blank
    */
    MEM_43_EEP_INCONSISTENT,
    /**
    * @brief Uncorrectable ECC errors occurred during memory access
    */
    MEM_43_EEP_ECC_UNCORRECTED,
    /**
    * @brief Correctable ECC errors occurred during memory access
    */
    MEM_43_EEP_ECC_CORRECTED
} Mem_43_EEP_JobResultType;

/**
* @brief          Mem_43_EEP Length Type.
* @details        Number of bytes to read,write,erase,compare
*
* @implements     Mem_43_EEP_LengthType_typedef
*/
typedef MEM_43_EEP_LENGTHTYPE Mem_43_EEP_LengthType;

/**
* @brief          Mem_43_EEP HwServiceId Type
* @details        Job end notification function called by Mem in case the job processing is
*                 configured for job end notification.
*
* @implements     Mem_43_EEP_HwServiceIdType_typedef
*/
typedef uint32 Mem_43_EEP_HwServiceIdType;

/**
 * @brief          Sector Batch Type
 * @details        Sector Batch data structure for group of identical sectors
 *                 Note: burst sizes equal to normal sizes in case burst disabled
 *
 */
typedef struct
{
    const Mem_43_EEP_AddressType    StartAddress;       /* Physical start address of the sector batch                              */
    const Mem_43_EEP_AddressType    EndAddress;         /* Physical end address of the sector batch                                */
    const uint32                      SectorSize;         /* Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                      ReadPageSize;       /* Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                      WritePageSize;      /* Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                      EraseBurstSize;     /* Size of sector erase burst in bytes (for improved performance)          */
    const uint32                      ReadBurstSize;      /* Size of page read burst in bytes (for improved performance)             */
    const uint32                      WriteBurstSize;     /* Size of page write/program burst in bytes (for improved performance)    */
} Mem_43_EEP_SectorBatchType;

/**
 * @brief          Mem Instance Type
 * @details        Mem Instance data structure
 *
 */
typedef struct
{
    const Mem_43_EEP_InstanceIdType     InstanceId;          /* Unique numeric identifier for each a Mem driver instance           */
    const uint32                                         SectorBatchCount;    /* Number of sector batches in this Mem instance                      */
    const Mem_43_EEP_SectorBatchType   *SectorBatches;       /* Point to first element in array of sector batches configurations   */
    const uint8                                          MemUnitIndex;        /* Index of flash memory unit used for this Mem instance              */
} Mem_43_EEP_MemInstanceType;


/**
* @brief          Mem_43_EEP Config Type
* @details        Mem_43_EEP module initialization data structure
* @implements     Mem_43_EEP_ConfigType_typedef
*
*/
typedef struct
{
    /**
    * @brief Point to first element in array of mem instances configurations
    */
    const Mem_43_EEP_MemInstanceType   *MemInstances;
#if (MEM_43_EEP_CHECK_CFG_CRC == STD_ON)
    /**
     * @brief MEM_43_Eep Config Set CRC checksum
     */
    Mem_43_EEP_CrcType u16ConfigCrc;
#endif
    /**
      * @brief SD Ip configuration pointer
    **/
    const Sd_Emmc_Ip_ConfigType * pxSdEmmcIpConfig;
} Mem_43_EEP_ConfigType;

/**
* @brief          Mem_43_EEP Compare Configuration Type
*
*                 Mem_43_EEP_CompareConfigType
*/
typedef struct
{
    Mem_43_EEP_AddressType eepromAddr;     /* Eep rom address needs compare */
    Mem_43_EEP_DataType* dataSourcePtr;    /* Data source pointer */
    Mem_43_EEP_LengthType length;          /* Length of data needs compare */
} Mem_43_EEP_CompareConfigType;

/**
* @brief          Mem_43_EEP mmc switch partition configuration type
*
*/
typedef Sd_Ip_MmcPartitionAccessType Mem_43_EEP_SwitchPartitionConfigType;

/**
* @brief          Mem_43_EEP mmc fast boot configuration type
*
*/
typedef struct
{
    const Mem_43_EEP_ConfigType * ConfigPtr;       /* Mem_Eep module initialization data structure pointer */
    Mem_43_EEP_LengthType BootBlockCount;    /* Block count of data need read when fast boot */
    uint32 * BootBuffer;                  /* Save the data need read when fast boot */
} Mem_43_EEP_FastBootConfigType;


#ifdef __cplusplus
}
#endif

#endif /* MEM_43_EEP_TYPES_H */

/** @}*/
