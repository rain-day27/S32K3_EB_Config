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

#ifndef MEM_43_EXFLS_H
#define MEM_43_EXFLS_H

/**
*   @file Mem_43_EXFLS.h
*
*   @defgroup MEM_43_EXFLS MEM_43_EXFLS Driver
*   @implements Mem_43_EXFLS.h_Artifact
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
#include "Mem_43_EXFLS_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_VENDOR_ID                      43
#define MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION       4
#define MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION       7
#define MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION    0
#define MEM_43_EXFLS_SW_MAJOR_VERSION               5
#define MEM_43_EXFLS_SW_MINOR_VERSION               0
#define MEM_43_EXFLS_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_EXFLS_Cfg.h header file are of the same vendor */
#if (MEM_43_EXFLS_VENDOR_ID != MEM_43_EXFLS_VENDOR_ID_CFG)
    #error "Mem_43_EXFLS.h and Mem_43_EXFLS_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EXFLS_Cfg.h header file are of the same Autosar version */
#if ((MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION    != MEM_43_EXFLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION    != MEM_43_EXFLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION != MEM_43_EXFLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_EXFLS.h and Mem_43_EXFLS_Cfg.h are different"
#endif
/* Check if current file and Mem_43_EXFLS_Cfg.h header file are of the same Software version */
#if ((MEM_43_EXFLS_SW_MAJOR_VERSION != MEM_43_EXFLS_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_EXFLS_SW_MINOR_VERSION != MEM_43_EXFLS_SW_MINOR_VERSION_CFG) || \
     (MEM_43_EXFLS_SW_PATCH_VERSION != MEM_43_EXFLS_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_EXFLS.h and Mem_43_EXFLS_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
*  @brief    AUTOSAR module identification
*/
#define MEM_43_EXFLS_MODULE_ID               91U

/**
*  @brief    AUTOSAR module instance identification
*/
#define MEM_43_EXFLS_INSTANCE_ID             0U


/**
* @brief    Development error codes (passed to DET)
* @implements     Development_error_codes_define
*/
#define MEM_43_EXFLS_E_UNINIT                0x01U    /* API service called without module initialization               */
#define MEM_43_EXFLS_E_PARAM_POINTER         0x02U    /* API service called with NULL pointer                           */
#define MEM_43_EXFLS_E_PARAM_ADDRESS         0x03U    /* API service called with an invalid address                     */
#define MEM_43_EXFLS_E_PARAM_LENGTH          0x04U    /* API service called with an invalid length                      */
#define MEM_43_EXFLS_E_PARAM_INSTANCE_ID     0x05U    /* API service called with an invalid driver instance ID          */
#define MEM_43_EXFLS_E_JOB_PENDING           0x06U    /* API service called while a job request is still in progress    */
#define MEM_43_EXFLS_E_OK                    0xFFU    /* API service called without errors                              */


/**
* @brief    All service IDs (passed to DET)
*/
/* Synchronous Functions */
#define MEM_43_EXFLS_INIT_ID                 0x01U    /* Service ID of function Mem_43_EXFLS_Init                          */
#define MEM_43_EXFLS_GETVERSIONINFO_ID       0x02U    /* Service ID of function Mem_43_EXFLS_GetVersionInfo                */
#define MEM_43_EXFLS_GETJOBRESULT_ID         0x04U    /* Service ID of function Mem_43_EXFLS_GetJobResult                  */
#define MEM_43_EXFLS_PROPAGATEERROR_ID       0x08U    /* Service ID of function Mem_43_EXFLS_PropagateError                */
#define MEM_43_EXFLS_DEINIT_ID               0x0BU    /* Service ID of function Mem_43_EXFLS_DeInit                        */
#define MEM_43_EXFLS_SUSPEND_ID              0x0CU    /* Service ID of function Mem_43_EXFLS_Suspend                       */
#define MEM_43_EXFLS_RESUME_ID               0x0DU    /* Service ID of function Mem_43_EXFLS_Resume                        */

/* Asynchronous Functions */
#define MEM_43_EXFLS_READ_ID                 0x05U    /* Service ID of function Mem_43_EXFLS_Read                          */
#define MEM_43_EXFLS_WRITE_ID                0x06U    /* Service ID of function Mem_43_EXFLS_Write                         */
#define MEM_43_EXFLS_ERASE_ID                0x07U    /* Service ID of function Mem_43_EXFLS_Erase                         */
#define MEM_43_EXFLS_BLANKCHECK_ID           0x09U    /* Service ID of function Mem_43_EXFLS_BlankCheck                    */
#define MEM_43_EXFLS_HWSPECIFICSERVICE_ID    0x0AU    /* Service ID of function Mem_43_EXFLS_HwSpecificService             */

/* Scheduled Functions */
#define MEM_43_EXFLS_MAINFUNCTION_ID         0x03U    /* Service ID of function Mem_43_EXFLS_MainFunction                  */

/*==================================================================================================
                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/*When multicore type3 is enabled on MemAcc, global variables must be allocated to share memory section */
#if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"

/* Pointer to current mem external flash module configuration set */
extern const Mem_43_EXFLS_ConfigType            *Mem_43_EXFLS_pConfigPtr;


#if (MEM_43_EXFLS_MULTICORE_ENABLED == STD_ON)
#define MEM_43_EXFLS_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EXFLS_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes Mem_43_EXFLS module.
 */
void Mem_43_EXFLS_Init(const Mem_43_EXFLS_ConfigType *ConfigPtr);


/**
 * @brief        The function de-initializes the Mem_43_EXFLS module.
 */
void Mem_43_EXFLS_DeInit(void);


/**
 * @brief        Return the version information of the Mem module.
 */
void Mem_43_EXFLS_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);


/**
 * @brief        Returns the result of the most recent job.
 */
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_GetJobResult(Mem_43_EXFLS_InstanceIdType InstanceId);


/**
 * @brief        Suspends active memory operation using hardware mechanism.
 */
Std_ReturnType Mem_43_EXFLS_Suspend(Mem_43_EXFLS_InstanceIdType InstanceId);


/**
 * @brief        Resumes suspended memory operation using hardware mechanism.
 */
Std_ReturnType Mem_43_EXFLS_Resume(Mem_43_EXFLS_InstanceIdType InstanceId);


/**
 * @brief        Propagates an ECC error to the memory upper layers
 */
void Mem_43_EXFLS_PropagateError(Mem_43_EXFLS_InstanceIdType InstanceId);


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Reads from flash memory.
 */
Std_ReturnType Mem_43_EXFLS_Read(Mem_43_EXFLS_InstanceIdType  InstanceId,
                                 Mem_43_EXFLS_AddressType     SourceAddress,
                                 Mem_43_EXFLS_DataType        *DestinationDataPtr,
                                 Mem_43_EXFLS_LengthType      Length
                                );

/**
 * @brief            Writes to flash memory.
 */
Std_ReturnType Mem_43_EXFLS_Write(Mem_43_EXFLS_InstanceIdType  InstanceId,
                                  Mem_43_EXFLS_AddressType     TargetAddress,
                                  const Mem_43_EXFLS_DataType  *SourceDataPtr,
                                  Mem_43_EXFLS_LengthType      Length
                                 );


/**
 * @brief            Erase one or more complete flash sectors.
 */
Std_ReturnType Mem_43_EXFLS_Erase(Mem_43_EXFLS_InstanceIdType    InstanceId,
                                  Mem_43_EXFLS_AddressType       TargetAddress,
                                  Mem_43_EXFLS_LengthType        Length
                                 );


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 */
Std_ReturnType Mem_43_EXFLS_BlankCheck(Mem_43_EXFLS_InstanceIdType    InstanceId,
                                       Mem_43_EXFLS_AddressType       TargetAddress,
                                       Mem_43_EXFLS_LengthType        Length
                                      );


/**
 * @brief            Trigger a hardware specific service.
 */
Std_ReturnType Mem_43_EXFLS_HwSpecificService(Mem_43_EXFLS_InstanceIdType     InstanceId,
                                              Mem_43_EXFLS_HwServiceIdType    HwServiceId,
                                              Mem_43_EXFLS_DataType           *DataPtr,
                                              Mem_43_EXFLS_LengthType         *LengthPtr
                                             );

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_EXFLS_H */

