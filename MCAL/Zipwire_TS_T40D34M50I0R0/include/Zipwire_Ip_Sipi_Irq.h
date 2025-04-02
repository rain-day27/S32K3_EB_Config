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

#ifndef ZIPWIRE_IP_SIPI_IRQ_H_
#define ZIPWIRE_IP_SIPI_IRQ_H_

/**
*   @file Zipwire_Ip_Sipi_Irq.h
*
*   @addtogroup ZIPWIRE_IP_DRIVER ZIPWIRE IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Zipwire_Ip.h"
#include "Zipwire_Ip_Types.h"
#include "Zipwire_Ip_Sipi_Hw_Access.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID                   43
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION    4
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION    7
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION 0
#define ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION            5
#define ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION            0
#define ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION            0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Zipwire_Ip_Types.h file are of the same vendor */
#if (ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID != ZIPWIRE_IP_TYPES_VENDOR_ID)
#error "Zipwire_Ip_Irq.h and Zipwire_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Zipwire_Ip_Types.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_Irq.h and Zipwire_Ip_Types.h are different"
#endif

/* Check if header file and Zipwire_Ip_Types.h file are of the same Software version */
#if ((ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION != ZIPWIRE_IP_TYPES_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION != ZIPWIRE_IP_TYPES_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION != ZIPWIRE_IP_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Zipwire_Ip_Irq.h and Zipwire_Ip_Types.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Hw_Access.h file are of the same vendor */
#if (ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID != ZIPWIRE_IP_SIPI_HW_ACCESS_VENDOR_ID)
#error "Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Hw_Access.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Hw_Access.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Hw_Access.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Hw_Access.h file are of the same Software version */
#if ((ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Hw_Access.h are different"
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

/*==================================================================================================
*                                   DRIVER HANDLERS PROTOTYPE
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

void Zipwire_Ip_Sipi_CrcErrHandler(uint8 HwInstance);

void Zipwire_Ip_Sipi_MaxCountReachedHandler(uint8 HwInstance);

void Zipwire_Ip_Sipi_ChnTimeoutErrHandler(uint8 HwInstance,
                                          uint8 HwChannel);

void Zipwire_Ip_Sipi_ChnTransIdErrHandler(uint8 HwInstance,
                                          uint8 HwChannel);

void Zipwire_Ip_Sipi_ChnAckErrHandler(uint8 HwInstance,
                                      uint8 HwChannel);

void Zipwire_Ip_Sipi_ChnReadAnswerHandler(uint8 HwInstance,
                                          uint8 HwChannel);

void Zipwire_Ip_Sipi_ChnAckHandler(uint8 HwInstance,
                                   uint8 HwChannel);

void Zipwire_Ip_Sipi_ChnTriggerHandler(uint8 HwInstance,
                                       uint8 HwChannel);

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"
/*==================================================================================================
*                              DEFAULT INTERRUPT HANDLERS SIGNARUTRES
==================================================================================================*/
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

#if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED)
void Zipwire_Ip_Sipi0_Channel0IRQHandler(void);

void Zipwire_Ip_Sipi0_Channel1IRQHandler(void);

void Zipwire_Ip_Sipi0_Channel2IRQHandler(void);

void Zipwire_Ip_Sipi0_Channel3IRQHandler(void);

void Zipwire_Ip_Sipi0_ErrorIRQHandler(void);

void Zipwire_Ip_Sipi0_CrcErrorIRQHandler(void);

void Zipwire_Ip_Sipi0_Ch0ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi0_Ch1ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi0_Ch2ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi0_Ch3ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi0_MaxCountReachedIRQHandler(void);

void Zipwire_Ip_Sipi0_TriggerIRQHandler(void);

#ifdef ZIPWIRE_IP_ORED_IRQ_LINES
void Zipwire_Ip_Sipi0_IRQHandler(void);

#endif
#endif /* #if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED) */

#if (STD_ON == ZIPWIRE_IP_INSTANCE_1_DEFINED)
void Zipwire_Ip_Sipi1_Channel0IRQHandler(void);

void Zipwire_Ip_Sipi1_Channel1IRQHandler(void);

void Zipwire_Ip_Sipi1_Channel2IRQHandler(void);

void Zipwire_Ip_Sipi1_Channel3IRQHandler(void);

void Zipwire_Ip_Sipi1_ErrorIRQHandler(void);

void Zipwire_Ip_Sipi1_CrcErrorIRQHandler(void);

void Zipwire_Ip_Sipi1_Ch0ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi1_Ch1ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi1_Ch2ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi1_Ch3ResponseOrAckIRQHandler(void);

void Zipwire_Ip_Sipi1_MaxCountReachedIRQHandler(void);

void Zipwire_Ip_Sipi1_TriggerIRQHandler(void);

#if (STD_ON == ZIPWIRE_IP_ORED_IRQ_LINES)
void Zipwire_Ip_Sipi1_IRQHandler(void);

#endif
#endif /* #if (STD_ON == ZIPWIRE_IP_INSTANCE_1_DEFINED) */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef ZIPWIRE_IP_SIPI_IRQ_H_ */
