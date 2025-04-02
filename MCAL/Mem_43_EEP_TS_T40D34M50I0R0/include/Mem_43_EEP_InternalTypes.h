
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

#ifndef MEM_43_EEP_INTERNALTYPES_H
#define MEM_43_EEP_INTERNALTYPES_H

/**
* @file
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

#include "Mem_43_EEP_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_INTERNALTYPES_VENDOR_ID                    43
#define MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION     4
#define MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION     7
#define MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION  0
#define MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION             5
#define MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION             0
#define MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_EEP_CfgDefines header file are of the same vendor */
#if (MEM_43_EEP_INTERNALTYPES_VENDOR_ID != MEM_43_EEP_VENDOR_ID_CFG_DEFINES)
    #error "Mem_43_EEP_InternalTypes.h and Mem_43_EEP_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EEP_CfgDefines header file are of the same Autosar version */
#if ((MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_InternalTypes.h and Mem_43_EEP_CfgDefines.h are different"
#endif
/* Check if current file and Mem_43_EEP_CfgDefines header file are of the same software version */
#if ((MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION != MEM_43_EEP_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION != MEM_43_EEP_SW_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION != MEM_43_EEP_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of Mem_43_EEP_InternalTypes.h and Mem_43_EEP_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @brief          Result of low-level eeprom operation.
*/
typedef enum
{
    MEM_43_EEP_E_OK = 0,                 /**< @brief operation succeeded */
    MEM_43_EEP_E_FAILED,                 /**< @brief operation failed due to hardware error */
    MEM_43_EEP_E_PENDING                 /**< @brief operation is pending */
} Mem_43_EEP_ReturnType;

/**
* @brief          Type of job currently executed by Mem_43_EEP_MainFunction.
*/
typedef enum
{
    /**
    * @brief erase one or more complete mem_eeprom sectors
    */
    MEM_43_EEP_JOB_ERASE = 0,
    /**
    * @brief write one or more complete mem_eeprom pages
    */
    MEM_43_EEP_JOB_WRITE,
    /**
    * @brief read one or more bytes from mem_eeprom memory
    */
    MEM_43_EEP_JOB_READ,
    /**
    * @brief check blank bytes from mem_eeprom memory
    */
    MEM_43_EEP_JOB_BLANKCHECK,
    /**
    * @brief hardware specific service
    */
    MEM_43_EEP_JOB_HWSPECIFICSERVICE
} Mem_43_EEP_JobType;

/**
* @brief           Asynchronous job result type.
*/
typedef enum
{
    /**
    * @brief Has been finished successfully
    */
    MEM_43_EEP_BLANKCHECK_E_OK,
    /**
    * @brief Has not been finished successfully
    */
    MEM_43_EEP_BLANKCHECK_E_NOT_OK,
    /**
    * @brief The checked page is not blank
    */
    MEM_43_EEP_BLANKCHECK_E_INCONSISTENT
} Mem_43_EEP_BlankCheckType;

/**
*           Result of compare operation.
*/
typedef enum
{
    MEM_43_EEP_COMPARE_E_OK,                   /* The data buffer match with content of eeprom memory. */
    MEM_43_EEP_COMPARE_E_FAILED,               /* Read the data from the card failed.*/
    MEM_43_EEP_COMPARE_E_BLOCK_INCONSISTENT,   /* The data buffer doesn't match with content of eeprom memory */
} Mem_43_EEP_CompareCheckType;

/**
* @brief          Size of data to be processeed by CRC.
*
*
*/
typedef enum
{
    MEM_43_EEP_CRC_8_BITS = 0,
    MEM_43_EEP_CRC_16_BITS
} Mem_43_EEP_CrcDataSizeType;


/**
 * @brief          Mem job runtime information Type
 * @details        This structure contains runtime information the current processing job of each Mem instance.
 *
 */
typedef struct
{
/**
* @brief Maximum number of bytes to read in one cycle of Mem_43_EEP_MainFunction
*/
    Mem_43_EEP_LengthType Mem_43_EEP_u32MaxRead;
/**
* @brief Maximum number of bytes to write in one cycle of Mem_43_EEP_MainFunction
*/
    Mem_43_EEP_LengthType Mem_43_EEP_u32MaxWrite;
/**
* @brief Logical address of data block currently processed by Mem_43_EEP_MainFunction
*/
    Mem_43_EEP_AddressType Mem_43_EEP_u32EepromAddrIt;
/**
* @brief Remainin length to be transfered until the end of the job
*/
     Mem_43_EEP_LengthType Mem_43_EEP_u32RemainingLength;
/**
* @brief Result of last mem_43_eeprom module job
*/
    Mem_43_EEP_JobResultType Mem_43_EEP_eJobResult;
/**
* @brief Type of currently executed job (erase, write, read, or blank)
*/
    Mem_43_EEP_JobType Mem_43_EEP_eJob;
/**
* @brief Type of currently executed HwServiceId job (compare) when executing ProcessHwSpecificServiceJob
*/
    Mem_43_EEP_HwServiceIdType    Mem_43_EEP_u32HwServiceIdJob;
/**
* @brief Pointer to current position in source data buffer
*/
    const Mem_43_EEP_DataType * Mem_43_EEP_pJobSrcAddrPtr;
/**
* @brief Pointer to current position in target data buffer
*/
    Mem_43_EEP_DataType * Mem_43_EEP_pJobDataDestPtr;
#if (MEM_43_EEP_MULTIPARTITION_ENABLED == STD_ON)
/**
* @brief The current User ID is requesting job
*/
    uint8 Mem_43_EEP_u8UserID;
#endif
} Mem_43_EEP_JobRuntimeInfoType;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* MEM_43_EEP_INTERNALTYPES_H */

/** @}*/
