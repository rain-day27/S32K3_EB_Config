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

/**
*   @file
*
*   @addtogroup AEC_DRIVER AEC Driver
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
#include "Aec_Ip_Hw_Access.h"
#include "Aec_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_IRQ_VENDOR_ID_C                      43
#define AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define AEC_IP_IRQ_SW_MAJOR_VERSION_C               5
#define AEC_IP_IRQ_SW_MINOR_VERSION_C               0
#define AEC_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Hw_Access.h */
#if (AEC_IP_IRQ_VENDOR_ID_C != AEC_IP_HW_ACCESS_VENDOR_ID)
    #error "Aec_Ip_Irq.c and Aec_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Hw_Access.h are different"
#endif
#if ((AEC_IP_IRQ_SW_MAJOR_VERSION_C != AEC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (AEC_IP_IRQ_SW_MINOR_VERSION_C != AEC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (AEC_IP_IRQ_SW_PATCH_VERSION_C != AEC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Hw_Access.h are different"
#endif

/* Checks against Aec_Ip_Irq.h */
#if (AEC_IP_IRQ_VENDOR_ID_C != AEC_IP_IRQ_VENDOR_ID)
    #error "Aec_Ip_Irq.c and Aec_Ip_Irq.h have different vendor ids"
#endif
#if ((AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != AEC_IP_IRQ_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Irq.h are different"
#endif
#if ((AEC_IP_IRQ_SW_MAJOR_VERSION_C != AEC_IP_IRQ_SW_MAJOR_VERSION) || \
     (AEC_IP_IRQ_SW_MINOR_VERSION_C != AEC_IP_IRQ_SW_MINOR_VERSION) || \
     (AEC_IP_IRQ_SW_PATCH_VERSION_C != AEC_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Irq.c and Aec_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

#if(STD_ON == AEC_IP_USE_NMI_INTERRUPT)
ISR(AEC_NMI_IRQHandler)
{
    /* Enable NMI and execute Events/Faults */
    Aec_Ip_InterruptSetupEventFaultHandler();
}
#endif

ISR(AEC_Common_IRQHandler)
{
    /* Events/Faults interrupt */
    Aec_IRQEventFaultHandler();
}

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

