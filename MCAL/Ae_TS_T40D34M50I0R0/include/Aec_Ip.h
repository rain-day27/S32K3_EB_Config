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

#ifndef AEC_IP_H
#define AEC_IP_H

/**
*   @file
*
*   @addtogroup AEC_DRIVER AEC Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Aec_Ip_Types.h"
#include "Aec_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_VENDOR_ID                      43
#define AEC_IP_AR_RELEASE_MAJOR_VERSION       4
#define AEC_IP_AR_RELEASE_MINOR_VERSION       7
#define AEC_IP_AR_RELEASE_REVISION_VERSION    0
#define AEC_IP_SW_MAJOR_VERSION               5
#define AEC_IP_SW_MINOR_VERSION               0
#define AEC_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Types.h */
#if (AEC_IP_VENDOR_ID != AEC_IP_TYPES_VENDOR_ID)
    #error "Aec_Ip.h and Aec_Ip_Types.h have different vendor ids"
#endif
#if (( AEC_IP_AR_RELEASE_MAJOR_VERSION    != AEC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_MINOR_VERSION    != AEC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_REVISION_VERSION != AEC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip.h and Aec_Ip_Types.h are different"
#endif
#if (( AEC_IP_SW_MAJOR_VERSION != AEC_IP_TYPES_SW_MAJOR_VERSION) || \
     ( AEC_IP_SW_MINOR_VERSION != AEC_IP_TYPES_SW_MINOR_VERSION) || \
     ( AEC_IP_SW_PATCH_VERSION != AEC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip.h and Aec_Ip_Types.h are different"
#endif

/* Checks against Aec_Ip_Cfg.h */
#if (AEC_IP_VENDOR_ID != AEC_IP_CFG_VENDOR_ID)
    #error "Aec_Ip.h and Aec_Ip_Cfg.h have different vendor ids"
#endif
#if (( AEC_IP_AR_RELEASE_MAJOR_VERSION    != AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_MINOR_VERSION    != AEC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_REVISION_VERSION != AEC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip.h and Aec_Ip_Cfg.h are different"
#endif
#if (( AEC_IP_SW_MAJOR_VERSION != AEC_IP_CFG_SW_MAJOR_VERSION) || \
     ( AEC_IP_SW_MINOR_VERSION != AEC_IP_CFG_SW_MINOR_VERSION) || \
     ( AEC_IP_SW_PATCH_VERSION != AEC_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip.h and Aec_Ip_Cfg.h are different"
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

#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

AEC_CONFIG_EXT

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"


#define AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

extern const Aec_Ip_ConfigType *Aec_apxInternalCfg;

#define AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

/**
* @brief         Initializes the Aec Driver
* @details       The configuration pointer is internally stored and
*                the driver is initialized.
*
* @return         AEC_STATUS_SUCCESS if initialized successful.
*                AEC_STATUS_TIMEOUT if initialized failed.
*/
Aec_Ip_StatusType  Aec_Ip_Init (const Aec_Ip_ConfigType *AecConfig);
/**
 * @brief Write Value to indexed register by Register address through SPI
 *
 * @param[in] RegAddr Register address want to write to.
 * @param[in] DataWidth Size of register in AEC that want to read/write.
 * @param[in] Data Value want to write to indexed register.
 * @return Status of transmission
 */
Aec_Ip_StatusType Aec_Ip_SpiWrite (uint32 RegAddr,
                                   uint8 DataWidth,
                                   uint32 Data
                                   );
/**
 * @brief Read Value return from indexed register by Register address through SPI
 *
 * @param[in] RegAddr Register address want to read from.
 * @param[in] DataWidth Size of register in AEC that want to read/write.
 * @param[out] Data Value want to read from indexed register.
 * @return Status of transmission
 */
Aec_Ip_StatusType Aec_Ip_SpiRead (uint32 RegAddr,
                                  uint8 DataWidth,
                                  uint32 *Data
                                  );
/**
 * @brief Verify for correctness the received frame counter or just read number of frames.
 *
 * @param[in]     IsVerify want to verify for correctness for frame counter.
 * @param[in]     ExpectedFrameCount Number of frame expected get.
 * @param[out]    ActualFrameCount Number of frame get in real.
 *
 * @return TRUE if verify correct.
 */
boolean Aec_Ip_Spi_Frame_Counter(boolean IsVerify,
                                uint8 ExpectedFrameCount,
                                uint8 *ActualFrameCount
                                );

/**
 * @brief Return status of global health.
 *
 */
uint16 Aec_Ip_DecodeGlobalHealthStatus(void);

/**
 * @brief Enable/Disable read after write.
 */
void Aec_Ip_SetRaw(boolean Activate);

#if(STD_ON == AEC_IP_USE_NMI_INTERRUPT)
/**
 * @brief Handle NMI event/faults handler
 *
 */
void Aec_Ip_InterruptSetupEventFaultHandler(void);
/**
 * @brief Handle Interrupt Event/Faults
 *
 */
void Aec_Ip_NMISetupEventFaultHandler(void);
#endif

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEC_IP_H */

