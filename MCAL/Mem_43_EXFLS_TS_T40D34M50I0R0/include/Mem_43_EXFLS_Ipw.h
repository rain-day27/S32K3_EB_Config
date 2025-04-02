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

#ifndef MEM_43_EXFLS_IPW_H
#define MEM_43_EXFLS_IPW_H

/**
*   @file Mem_43_EXFLS_Ipw.h
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
#include "Mem_43_EXFLS.h"
#include "Mem_43_EXFLS_Ipw_Cfg.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_IPW_VENDOR_ID                       43
#define MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION        4
#define MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION        7
#define MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION     0
#define MEM_43_EXFLS_IPW_SW_MAJOR_VERSION                5
#define MEM_43_EXFLS_IPW_SW_MINOR_VERSION                0
#define MEM_43_EXFLS_IPW_SW_PATCH_VERSION                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_EXFLS_Cfg.h header file are of the same vendor */
#if (MEM_43_EXFLS_IPW_VENDOR_ID != MEM_43_EXFLS_TYPES_VENDOR_ID)
    #error "Mem_43_EXFLS_Ipw.h and Mem_43_EXFLS_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EXFLS_Cfg.h header file are of the same Autosar version */
#if ((MEM_43_EXFLS_IPW_AR_RELEASE_MAJOR_VERSION    != MEM_43_EXFLS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_MINOR_VERSION    != MEM_43_EXFLS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EXFLS_IPW_AR_RELEASE_REVISION_VERSION != MEM_43_EXFLS_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EXFLS_Ipw.h and Mem_43_EXFLS_Cfg.h are different"
#endif
/* Check if current file and Mem_43_EXFLS_Cfg.h header file are of the same Software version */
#if ((MEM_43_EXFLS_IPW_SW_MAJOR_VERSION != MEM_43_EXFLS_TYPES_SW_MAJOR_VERSION) || \
     (MEM_43_EXFLS_IPW_SW_MINOR_VERSION != MEM_43_EXFLS_TYPES_SW_MINOR_VERSION) || \
     (MEM_43_EXFLS_IPW_SW_PATCH_VERSION != MEM_43_EXFLS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EXFLS_Ipw.h and Mem_43_EXFLS_Cfg.h are different"
#endif

/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                    VARIABLE DECLARATIONS
==================================================================================================*/



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/**
* @brief          Initialize the hardware resources.
*/
Std_ReturnType Mem_43_EXFLS_IPW_Init(void);

/*
 * Function Name : Mem_43_EXFLS_IPW_DeInit
 * Description   : De-Initialize memory flash devices
 */
void Mem_43_EXFLS_IPW_DeInit(uint32 InstanceIndex);

/**
* @brief          Returns synchronously the result of the last job.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_GetJobResult(uint32 InstanceIndex,
                                                         Mem_43_EXFLS_JobType JobType
                                                        );


/**
* @brief          Abort a suspended hardware job to prepare for a new job.
*/
void Mem_43_EXFLS_IPW_AbortSuspended(uint32 InstanceIndex);


/**
* @brief          IP wrapper read function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Read(uint32                          InstanceIndex,
                                                 Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                );


/**
* @brief          IP wrapper blank check function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_BlankCheck(uint32                          InstanceIndex,
                                                       Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                      );


/**
* @brief          IP wrapper write function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Write(uint32                          InstanceIndex,
                                                  Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                 );


/**
* @brief          IP wrapper erase function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Erase(uint32                          InstanceIndex,
                                                  Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                 );

#if (MEM_43_EXFLS_SERVICE_COMPARE == STD_ON)
/**
* @brief          IP wrapper compare function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_Compare(uint32                          InstanceIndex,
                                                    Mem_43_EXFLS_JobRuntimeInfoType   *JobInfo
                                                   );
#endif

/**
* @brief          IP wrapper IsSupportEraseSupendResume function.
*/
boolean Mem_43_EXFLS_IPW_IsSupportEraseSupendResume(uint32 Index);

/**
* @brief          IP wrapper IsSupportProgramSupendResume function.
*/
boolean Mem_43_EXFLS_IPW_IsSupportProgramSupendResume(uint32 Index);

/**
* @brief          IP wrapper Write_Suspend function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_WriteSuspend(uint32 Index);

/**
* @brief          IP wrapper Erase_Suspend function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_EraseSuspend(uint32 Index);

/**
* @brief          IP wrapper Write_esume function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_WriteResume(uint32 Index);

/**
* @brief          IP wrapper Erase_Resume function.
*/
Mem_43_EXFLS_JobResultType Mem_43_EXFLS_IPW_EraseResume(uint32 Index);

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_EXFLS_IPW_H */
