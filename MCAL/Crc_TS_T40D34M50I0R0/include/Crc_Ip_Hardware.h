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
#ifndef CRC_IP_HARDWARE_H
#define CRC_IP_HARDWARE_H

/**
*   @file    Crc_Ip_Hardware.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup
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
#include "Crc_Ip_Types.h"
#include "Crc_Ip_State.h"

#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_HARDWARE_VENDOR_ID                      43
#define CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION       4
#define CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION       7
#define CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION    0
#define CRC_IP_HARDWARE_SW_MAJOR_VERSION               5
#define CRC_IP_HARDWARE_SW_MINOR_VERSION               0
#define CRC_IP_HARDWARE_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Crc_Ip_Types.h file are of the same vendor */
#if (CRC_IP_HARDWARE_VENDOR_ID != CRC_IP_TYPES_VENDOR_ID)
    #error "Crc_Ip_Hardware.h and Crc_Ip_Types.h have different vendor ids"
#endif

/* Check if source file and Crc_Ip_Types.h file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION != CRC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Hardware.h and Crc_Ip_Types.h are different"
#endif

/* Check if source file and Crc_Ip_Types.h header file are of the same Software version */
#if ((CRC_IP_HARDWARE_SW_MAJOR_VERSION != CRC_IP_TYPES_SW_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_MINOR_VERSION != CRC_IP_TYPES_SW_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_PATCH_VERSION != CRC_IP_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Hardware.h and Crc_Ip_Types.h are different"
#endif

/* Check if source file and Crc_Ip_State.h file are of the same vendor */
#if (CRC_IP_HARDWARE_VENDOR_ID != CRC_IP_STATE_VENDOR_ID)
    #error "Crc_Ip_Hardware.h and Crc_Ip_State.h have different vendor ids"
#endif

/* Check if source file and Crc_Ip_State.h file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION    != CRC_IP_STATE_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION    != CRC_IP_STATE_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION != CRC_IP_STATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Hardware.h and Crc_Ip_State.h are different"
#endif

/* Check if source file and Crc_Ip_State.h file are of the same Software version */
#if ((CRC_IP_HARDWARE_SW_MAJOR_VERSION != CRC_IP_STATE_SW_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_MINOR_VERSION != CRC_IP_STATE_SW_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_PATCH_VERSION != CRC_IP_STATE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Hardware.h and Crc_Ip_State.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
/**
 * @brief   This function configures the CRC module from a user configuration structure.
 * @details This service is a non-reentrant function that shall initializes parameters list for the CRC Channel.
 *          The list is composed of an array of Crc Channel parameters settings.
 *
 * @param[in]  *pxLogicChannelInitCfg       - Pointer to list LogicChannelInitCfg
 * @param[in]  *pxLogicChannelState   - Pointer to the Crc Channel Config State Information
 *
 * @return void
 **/
void Crc_Ip_HwSetConfig(const Crc_Ip_LogicChannelType * pxLogicChannelInitCfg,
                        const Crc_Ip_LogicChannelStateType *pxLogicChannelState
                       );

/**
 * @brief   This function shall start algorithm calculate CRC
 * @details This service is a reentrant function that shall start algorithm calculate in CRC Channel
 *
 * @param[in]  HwInst           - Crc Hardware Instance
 * @param[in]  HwChannel        - Crc Hardware Channel
 * @param[in]  DmaLogicChannel  - Dma Logic Channel
 * @param[in]  *DataPtr         - Pointer to the Crc Data Input.
 * @param[in]  Length           - Length of crcDataPtr block to be calculated in bytes.
 * @param[in]  InitialSeedValue - Initial Seed Value when the algorithm starts.
 *
 * @return void
 **/

uint64 Crc_Ip_HwCalculate(const Crc_Ip_LogicChannelType * LogicChannelInitCfg,
                          const uint8 *DataPtr,
                          const uint32 Length,
                          const uint64 InitialSeedValue
                         );

/**
 * @brief   This function get result CRC after finish calculated
 * @details This service is a function that shall get result CRC after finish calculated
 *
 * @param[in]  *pxLogicChannelInitCfg       - Pointer to list LogicChannelInitCfg
 *
 * @return     result of CRC calculated.
 **/
uint64 Crc_Ip_HwGetLocResult(const Crc_Ip_LogicChannelType *pxLogicChannelInitCfg);

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"
#endif /* #if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IP_HARDWARE_H */
