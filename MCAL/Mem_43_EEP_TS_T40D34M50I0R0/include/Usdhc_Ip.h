/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
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

#ifndef USDHC_DRIVER_H
#define USDHC_DRIVER_H

/**
*   @file
*
*   @addtogroup IPV_USDHC uSDHC
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

#include "Usdhc_Ip_Cfg.h"

#if (STD_ON == USDHC_IP_DEV_ERROR_DETECT)
  #include "Devassert.h"
#endif

#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define USDHC_IP_VENDOR_ID_H                       43
#define USDHC_IP_AR_RELEASE_MAJOR_VERSION_H        4
#define USDHC_IP_AR_RELEASE_MINOR_VERSION_H        7
#define USDHC_IP_AR_RELEASE_REVISION_VERSION_H     0
#define USDHC_IP_SW_MAJOR_VERSION_H                5
#define USDHC_IP_SW_MINOR_VERSION_H                0
#define USDHC_IP_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Usdhc_Ip_Cfg.h header file are of the same vendor */
#if (USDHC_IP_VENDOR_ID_H != USDHC_VENDOR_ID_IP_CFG)
    #error "Usdhc_Ip.h and Usdhc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if header file and Usdhc_Ip_Cfg.h header file are of the same Autosar version */
#if ((USDHC_IP_AR_RELEASE_MAJOR_VERSION_H    != USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (USDHC_IP_AR_RELEASE_MINOR_VERSION_H    != USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (USDHC_IP_AR_RELEASE_REVISION_VERSION_H != USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Usdhc_Ip.h and Usdhc_Ip_Cfg.h are different"
#endif
/* Check if header file and Usdhc_Ip_Cfg.h header file are of the same software version */
#if ((USDHC_IP_SW_MAJOR_VERSION_H != USDHC_SW_MAJOR_VERSION_IP_CFG) || \
     (USDHC_IP_SW_MINOR_VERSION_H != USDHC_SW_MINOR_VERSION_IP_CFG) || \
     (USDHC_IP_SW_PATCH_VERSION_H != USDHC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Usdhc_Ip.h and Usdhc_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((USDHC_IP_AR_RELEASE_MAJOR_VERSION_H != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_IP_AR_RELEASE_MINOR_VERSION_H != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Usdhc_Ip.h and OsIf.h are different"
    #endif
#endif


/* Checks against Devassert.h */
#if USDHC_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((USDHC_IP_AR_RELEASE_MAJOR_VERSION_H != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_IP_AR_RELEASE_MINOR_VERSION_H != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Usdhc_Ip.h and Devassert.h are different"
    #endif
#endif
#endif /* STD_ON == USDHC_IP_DEV_ERROR_DETECT */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (USDHC_IP_USE_DMA == STD_ON)
#if (USDHC_IP_ADMA1_ENABLED == STD_ON)
/*! @brief uSDHC alignment size (4096U) for ADMA1 modes  */
#define USDHC_IP_ALIGNMENT_SIZE    USDHC_IP_ADMA1_ADDRESS_ALIGN
#else
/*! @brief uSDHC alignment size (page size 4U) for ADMA2 modes*/
#define USDHC_IP_ALIGNMENT_SIZE    USDHC_IP_ADMA2_ADDRESS_ALIGN
#endif
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_EEP_MemMap.h"

/*! @brief Usdhc base pointer array */
extern USDHC_Type * const Usdhc_Ip_BaseAddr[USDHC_INSTANCE_COUNT];

/* In order to check the failed timeout */
extern boolean Usdhc_Ip_bFailedTimeout;

ISR(uSDHC0_Isr);

#if (STD_ON == USDHC_IP_MMC_BOOT_ENABLED)
Usdhc_Ip_StatusType uSDHC_Ip_ProcessFastBoot(uint32 instance, const Usdhc_Ip_BootConfigType *UsdhcBootConfig, uint32 numberBlocks, uint32 * buffer);
#endif

Usdhc_Ip_StatusType uSDHC_Ip_Init(Usdhc_Ip_StateType * State,
                                  const Usdhc_Ip_ConfigType * Config,
                                  uint32 Instance
                                 );

Usdhc_Ip_StatusType uSDHC_Ip_DeInit(uint32 Instance);

uint32 uSDHC_Ip_GetPresentStatusFlags(uint32 Instance);

Usdhc_Ip_StatusType uSDHC_Ip_WaitPresentStatusFlagsVerified(uint32 Instance, uint32 StatusFlagsMask, uint32 Timeout);

Usdhc_Ip_StatusType uSDHC_Ip_Reset(uint32 Instance, uint32 Mask, uint32 TimeoutMs);

void uSDHC_Ip_GetCapability(uint32 Instance,
                             Usdhc_Ip_ControllerCapabilityType * Capability);

Usdhc_Ip_StatusType uSDHC_Ip_SetBusClock(uint32 Instance,
                                         uint32 BusClock,
                                         uint32 SrcClock,
                                         uint32 * NearestFrequency
                                        );

Usdhc_Ip_StatusType uSDHC_Ip_SetCardActive(uint32 Instance);

void uSDHC_Ip_SetDataBusWidth(uint32 Instance,
                              Usdhc_Ip_DataBusWidthType Width
                             );

Usdhc_Ip_StatusType uSDHC_Ip_SwitchVoltage(uint32 Instance, boolean IsLowVoltage);

Usdhc_Ip_StatusType uSDHC_Ip_Transfer(uint32 Instance,
                            const Usdhc_Ip_TransferType * Transfer,
                            boolean AsyncEnable);

Usdhc_Ip_StatusType uSDHC_Ip_Abort(uint32 Instance);

void uSDHC_Ip_SetSABGREQ(uint32 Instance);

void uSDHC_Ip_ClearSABGREQ(uint32 Instance);

void uSDHC_Ip_SetTiming(uint32 Instance, boolean DdrEnable, boolean EnHs400, boolean Hs400Mode);


void uSDHC_Ip_DiscardData(uint32 Instance);

#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_EEP_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* USDHC_DRIVER_H*/
