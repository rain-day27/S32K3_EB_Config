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
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_HW_ACCESS_VENDOR_ID_C                      43
#define AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define AEC_IP_HW_ACCESS_SW_MAJOR_VERSION_C               5
#define AEC_IP_HW_ACCESS_SW_MINOR_VERSION_C               0
#define AEC_IP_HW_ACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip_Hw_Access.h */
#if (AEC_IP_HW_ACCESS_VENDOR_ID_C != AEC_IP_HW_ACCESS_VENDOR_ID)
    #error "Aec_Ip_Hw_Access.c and Aec_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C    != AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_C != AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Hw_Access.c and Aec_Ip_Hw_Access.h are different"
#endif
#if ((AEC_IP_HW_ACCESS_SW_MAJOR_VERSION_C != AEC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (AEC_IP_HW_ACCESS_SW_MINOR_VERSION_C != AEC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (AEC_IP_HW_ACCESS_SW_PATCH_VERSION_C != AEC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Hw_Access.c and Aec_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if (( AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        ( AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Hw_Access.c and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#define AEC_DATAWIDTH_16                    (16U)

#define AEC_EVENTS_AEC_MASK                 (0xC108U)
#define AEC_FAULTS_AEC_MASK                 (0xCF80U)

#define AEC_EVENT_SUPPORT_MASK              (0xD3FCU)
#define AEC_FAULTS_SUPPORT_MASK             (0xFF9FU)
#define AEC_FAULT_START_POS                 (14U)

#define AEC_EVENT_STATUS_ADDR               ((uint32)(&IP_AEC_AE->EVENTS_STATUS))
#define AEC_EVENT_EN_ADDR                   ((uint32)(&IP_AEC_AE->EVENTS_ENABLE))
#define AEC_FAULT_STATUS_ADDR               ((uint32)(&IP_AEC_AE->FAULTS_STATUS))
#define AEC_FAULT_EN_ADDR                   ((uint32)(&IP_AEC_AE->FAULTS_ENABLE))

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

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void Aec_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(AEC_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, AEC_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean Aec_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    boolean RetVal = FALSE;
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, AEC_TIMEOUT_TYPE);

    if (*ElapsedTimeInOut >= TimeoutTicks)
    {
        RetVal = TRUE;
    }
    return RetVal;
}
/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_EventsFaultsEnable
 * Description   : Set up to enable for events/faults to raise interrupt_out.
 *
 *END**************************************************************************/
Aec_Ip_StatusType Aec_EventsFaultsEnable(void)
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;
    Aec_Ip_StatusType SpiWriteStatus = AEC_STATUS_SUCCESS;

    SpiWriteStatus = Aec_Ip_SpiWrite(AEC_EVENT_EN_ADDR, AEC_DATAWIDTH_16, Aec_intRouteConfig.AecEnEvents);

    if(AEC_STATUS_SUCCESS != SpiWriteStatus)
    {
        Status = AEC_STATUS_ERROR;
    }

    SpiWriteStatus = Aec_Ip_SpiWrite(AEC_FAULT_EN_ADDR, AEC_DATAWIDTH_16, Aec_intRouteConfig.AecEnFaults);

    if(AEC_STATUS_SUCCESS != SpiWriteStatus)
    {
        Status = AEC_STATUS_ERROR;
    }
    return Status;
}

/**
 * @brief Handle interrupt that trigger interrupt_out.
 * @implements Aec_IRQEventFaultHandler_Activity
 */
void Aec_IRQEventFaultHandler(void)
{
    uint32 RegStatusEventVal = 0U;
    uint32 RegStatusFault = 0U;
    uint8 Index;
    uint8 IsrPrio;
    uint16 HealthStatus = 0U;

    /* Call read function to get newest value of HealthStatus variable */
    (void)Aec_Ip_SpiRead(AEC_FAULT_STATUS_ADDR, AEC_DATAWIDTH_16, &RegStatusFault);
    HealthStatus = Aec_Ip_DecodeGlobalHealthStatus();
    (void)Aec_Ip_SpiRead(AEC_EVENT_STATUS_ADDR, AEC_DATAWIDTH_16, &RegStatusEventVal);
    HealthStatus |= Aec_Ip_DecodeGlobalHealthStatus();
    HealthStatus &= (AEC_STATUS_EVENT_NOTIFY | AEC_STATUS_FAULT_NOTIFY );

    /* Use HEALTH STATUS register to distinguish which register (FAULTS/EVENTS) to read
       to avoid clearing of error flag triggered by the fault injection. */
    if (0U != HealthStatus)
    {
        for (IsrPrio = 0U; IsrPrio < AEC_EVENT_FAULT_NUM_MAX; IsrPrio++)
        {
            /* Event/Fault will be handled from low to high */
            for (Index = 0U; Index < AEC_EVENT_FAULT_NUM_MAX; Index++)
            {
                if (IsrPrio == Aec_intRouteConfig.aIntConfig[Index].IsrPriority)
                {
                    /* if it is fault */
                    /* Check this event/fault raised or not */
                    if ((Index < AEC_FAULT_START_POS) && (0U != (RegStatusFault & Aec_intRouteConfig.aIntConfig[Index].IsrMask)) && (0U != (Aec_intRouteConfig.aIntConfig[Index].IsrMask  & AEC_FAULTS_AEC_MASK)))
                    {
                        #if(STD_ON == AEC_EVENT_FAULT_FLAG_CLEAR)
                        /* Clear the interrupt flag */
                        (void)Aec_Ip_SpiWrite(AEC_FAULT_STATUS_ADDR, AEC_DATAWIDTH_16, Aec_intRouteConfig.aIntConfig[Index].IsrMask);
                        #endif
                    }

                    if ((Index < AEC_FAULT_START_POS) && (0U != (RegStatusFault & Aec_intRouteConfig.aIntConfig[Index].IsrMask)) && (NULL_PTR != Aec_intRouteConfig.aIntConfig[Index].pfHandler))
                    {
                        Aec_intRouteConfig.aIntConfig[Index].pfHandler();
                    }

                    /* if it is event */
                    /* Check this event/fault raised or not */
                    if ((Index >= AEC_FAULT_START_POS) && (0U != (RegStatusEventVal & Aec_intRouteConfig.aIntConfig[Index].IsrMask)) && (0U != (Aec_intRouteConfig.aIntConfig[Index].IsrMask & AEC_EVENTS_AEC_MASK)))
                    {
                        #if(STD_ON == AEC_EVENT_FAULT_FLAG_CLEAR)
                        /* Clear the interrupt flag */
                        (void)Aec_Ip_SpiWrite(AEC_EVENT_STATUS_ADDR, AEC_DATAWIDTH_16, Aec_intRouteConfig.aIntConfig[Index].IsrMask);
                        #endif
                    }

                    if ((Index >= AEC_FAULT_START_POS) && (0U != (RegStatusEventVal & Aec_intRouteConfig.aIntConfig[Index].IsrMask)) && (NULL_PTR != Aec_intRouteConfig.aIntConfig[Index].pfHandler))
                    {
                        Aec_intRouteConfig.aIntConfig[Index].pfHandler();
                    }
                    break;
                }
            }
        }
    }
}

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
