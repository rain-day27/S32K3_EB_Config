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

#ifndef MEM_43_EXFLS_IPW_TYPES_H
#define MEM_43_EXFLS_IPW_TYPES_H

/**
*   @file Mem_43_ExFls_Ipw_Types.h
*
*   @addtogroup MEM_43_EXFLS Driver
*   @{
*/

/* implements Mem_43_ExFlsIpwTypes.h_Artifact */

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
#include "Mem_43_EXFLS_CfgDefines.h"
#include "Qspi_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EXFLS_IPW_TYPES_VENDOR_ID                      43
#define MEM_43_EXFLS_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MEM_43_EXFLS_IPW_TYPES_AR_RELEASE_MINOR_VERSION       7
#define MEM_43_EXFLS_IPW_TYPES_AR_RELEASE_REVISION_VERSION    0
#define MEM_43_EXFLS_IPW_TYPES_SW_MAJOR_VERSION               5
#define MEM_43_EXFLS_IPW_TYPES_SW_MINOR_VERSION               0
#define MEM_43_EXFLS_IPW_TYPES_SW_PATCH_VERSION               0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/



/*==================================================================================================
                                             TYPEDEFS
==================================================================================================*/



/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                        CONFIGURATION STRUCTURES
==================================================================================================*/


typedef struct
{
    const uint32                          HardwareInstance;            /* Hardware instance number                                 */
    const Qspi_Ip_ControllerConfigType   *Config;                      /* Hardware configuration                                   */
} Mem_43_EXFLS_QspiUnitType;


typedef struct
{
    const Qspi_Ip_MemoryConnectionType   *Connect;                     /* Connection for each external memory device               */
    const Qspi_Ip_MemoryConfigType       *Config;                      /* External memory devices configuration                    */
    boolean                               AHBRead;                     /* AHB direct reads configuration                           */
    boolean                               AHBWrite;                     /* AHB direct writes configuration                           */
} Mem_43_EXFLS_MemoryUnitType;


/**
* @brief          Mem device config type
* @details        Mem device config data structure
                  Mem_43_EXFLS_MemDeviceType_typedef
*/
typedef struct
{
    /**
    * @brief QSPI unit configurations (size = MEM_EXFLS_QSPI_UNIT_COUNT)
    */
    const Mem_43_EXFLS_QspiUnitType      *QspiUnits;         /* Point to first element in array of QSPI unit configurations          */
    /**
    * @brief Flash memory unit configurations (size = MEM_EXFLS_MEM_UNIT_COUNT)
    *        Each "MemUnit" = a pair of "MemConnection" + "MemCfg"
    */
    const Mem_43_EXFLS_MemoryUnitType    *MemUnits;          /* Point to first element in array of Flash memory unit configurations  */
} Mem_43_EXFLS_MemDeviceType;


/*==================================================================================================
                                        INTERNAL TYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* MEM_43_EXFLS_IPW_TYPES_H */
