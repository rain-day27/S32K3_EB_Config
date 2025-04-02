/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
/*==================================================================================================
==================================================================================================*/
/**
* @file         CanTrcv_43_AE_Ipw.c
*
* @addtogroup   CANTRCV_43_AE_DRIVER Can Transceiver Driver
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
#include "CanTrcv_43_AE_Ipw.h"
#include "CanTrcv_43_AE.h"
#if (CANTRCV_43_AE_ICU_USED == STD_ON)
    #include "Icu.h"
#endif
#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
#include "EcuM.h"
#endif
#if (CANTRCV_43_AE_DEM_USED == STD_ON)
#include "Dem.h"
#endif
#include "Aecanphy_Ip.h"
#include "Det.h"
#include "CanIf_CanTrcv.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_IPW_VENDOR_ID_C                      43
#define CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define CANTRCV_43_AE_IPW_SW_MAJOR_VERSION_C               5
#define CANTRCV_43_AE_IPW_SW_MINOR_VERSION_C               0
#define CANTRCV_43_AE_IPW_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE_Ipw.h header file are of the same vendor */
#if (CANTRCV_43_AE_IPW_VENDOR_ID_C != CANTRCV_43_AE_IPW_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE_Ipw.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE_Ipw.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE_Ipw.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE_Ipw.h header file are of the same software version */
#if ((CANTRCV_43_AE_IPW_SW_MAJOR_VERSION_C != CANTRCV_43_AE_IPW_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_MINOR_VERSION_C != CANTRCV_43_AE_IPW_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_PATCH_VERSION_C != CANTRCV_43_AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE_Ipw.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE.h header file are of the same vendor */
#if (CANTRCV_43_AE_IPW_VENDOR_ID_C != CANTRCV_43_AE_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE.h header file are of the same software version */
#if ((CANTRCV_43_AE_IPW_SW_MAJOR_VERSION_C != CANTRCV_43_AE_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_MINOR_VERSION_C != CANTRCV_43_AE_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_PATCH_VERSION_C != CANTRCV_43_AE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and CanTrcv_43_AE.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.c and Aecanphy_Ip.h header file are of the same vendor */
#if (CANTRCV_43_AE_IPW_VENDOR_ID_C != AECANPHY_IP_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw.c and Aecanphy_Ip.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw.c and Aecanphy_Ip.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != AECANPHY_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != AECANPHY_IP_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION_C != AECANPHY_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw.c and Aecanphy_Ip.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw.c and Aecanphy_Ip.h header file are of the same software version */
#if ((CANTRCV_43_AE_IPW_SW_MAJOR_VERSION_C != AECANPHY_IP_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_MINOR_VERSION_C != AECANPHY_IP_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW_SW_PATCH_VERSION_C != AECANPHY_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and Aecanphy_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CANTRCV_43_AE_ICU_USED == STD_ON)
    /* Check if CanTrcv_43_AE_Ipw.c and Icu.h are of the same software version */
    #if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and Icu.h are different"
    #endif
#endif

#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
    /* Check if CanTrcv_43_AE_Ipw.c and EcuM.h are of the same software version */
    #if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and EcuM.h are different"
    #endif
#endif

#if (CANTRCV_43_AE_DEM_USED == STD_ON)
    /* Check if CanTrcv_43_AE_Ipw.c and Dem.h are of the same software version */
    #if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and Dem.h are different"
    #endif
#endif

    /* Check if CanTrcv_43_AE_Ipw.c and Det.h are of the same software version */
    #if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and Det.h are different"
    #endif

    /* Check if CanTrcv_43_AE_Ipw.c and CanIf_CanTrcv.h are of the same software version */
    #if ((CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION_C != CANIF_CANTRCV_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION_C != CANIF_CANTRCV_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw.c and CanIf_CanTrcv.h are different"
    #endif

#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
#define CANTRCV_43_AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

static CanTrcv_TrcvWakeupModeType CanTrcv_Ipw_eWakeupMode[CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT];

#define CANTRCV_43_AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
#endif
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

/* Local function to report det_runtime error about a Spi miscommunication */
static void CanTrcv_Ipw_ReportSpiMiscommunication(Aecanphy_Ip_StatusType DeviceStatus,
                                                  uint8 Sid
                                                 );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void CanTrcv_Ipw_ReportSpiMiscommunication(Aecanphy_Ip_StatusType DeviceStatus,
                                                  uint8 Sid
                                                 )
{
    if (AE_CANPHY_STATUS_ERR_SPI == DeviceStatus)
    {
        (void)Det_ReportRuntimeError((uint16)CANTRCV_43_AE_IPW_MODULE_ID,
                                     (uint8)CANTRCV_43_AE_INSTANCE,
                                     (uint8)Sid,
                                     (uint8)CANTRCV_43_AE_E_NO_TRCV_CONTROL);
    }
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Ipw_Init */
Std_ReturnType CanTrcv_43_AE_Ipw_Init(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig)
{
    Aecanphy_Ip_StatusType Retval = AE_CANPHY_STATUS_SUCCESS;
#if ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) && (CANTRCV_43_AE_ECUM_USED == STD_ON))
    uint32 Flag = 0U;
#endif

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    /* Inital vaue assigned */
    CanTrcv_Ipw_eWakeupMode[TransceiverConfig->CanTrcv_u8SwTransceiverId] = CANTRCV_WUMODE_DISABLE;

    /* Check if a wakeup event stored by HW
     * This case may be occurred when a POWER-UP after exit from deepsleep mode of AE
     * Note: in deepsleep mode AE will POWER-OFF MCU, after that if a WUP(Wakeup Patern) dettected by CANPHY => CAN_WU_FLAG is set
     * It causes a Wakeup of AE => POWER UP MCU => CanTrcv_Init called again.
    */
    #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
    Retval = Aecanphy_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);
    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
        {
            EcuM_SetWakeupEvent(TransceiverConfig->CanTrcv_WakeupSourceMask);
        }
    }
    #endif /* (CANTRCV_43_AE_ECUM_USED == STD_ON) */

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        /* Ready to send notification to AEC
        * Whenever CAN_WU_FLAG is set => a notification sent to AEC => trigger an interupt signal on PTD3 of MCU and
        * If external interrupt is configured on PTD3(via ICU driver) => ICU ISR is invoked => call AE ISR
        *  => call CanTrcv user's notification(configured via AE driver) => call CanTrcv_CheckWakeup => call EcuM_SetWakeupEvent(Interrupt context)
        * Else no ICU channel configured for PTD3, the notification to MCU will be lost, in this case CanTrcv_Mainfunction can be used(Polling context).
        */
        Retval = Aecanphy_Ip_SetEventNotification(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_WKUP_EVENT, TRUE);
    }
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        Retval = Aecanphy_Ip_Init(TransceiverConfig->CanTrcv_u8HwTransceiverId, TransceiverConfig->CanTrcv_IpwTransceiverConfig->CanTrcv_Ipw_HwConfig);
    }

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        CanTrcv_Ipw_eWakeupMode[TransceiverConfig->CanTrcv_u8SwTransceiverId] = CANTRCV_WUMODE_ENABLE;
    #if (CANTRCV_43_AE_ICU_USED == STD_ON)
        if (CANTRCV_TRCVMODE_STANDBY == TransceiverConfig->CanTrcv_eInitState)
        {
            /* Enable wakeup notification */
            Icu_EnableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
        }
    #endif
    }
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_INIT);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
}

/* Ipw_SetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                         CanTrcv_TrcvModeType OpMode
                                                        )
{
    Aecanphy_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;

    /* Map the modes supported by hw to modes of autosar */
    switch (OpMode)
    {
        case CANTRCV_TRCVMODE_NORMAL:
        {
            Retval = Aecanphy_Ip_SetMode(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_NORMAL_MODE);
        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            if (AE_CANPHY_STATUS_SUCCESS == Retval)
            {
                /* Disable Icu channel notification to ensure no notification raised from CanTrcv Drv */
                Icu_DisableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
            }
        #endif
            break;
        }
        case CANTRCV_TRCVMODE_STANDBY:
        {
            Retval = Aecanphy_Ip_SetMode(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_OFFLINE_MODE);
        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            if (AE_CANPHY_STATUS_SUCCESS == Retval)
            {
                /* Enable Icu channel notification  */
                Icu_EnableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
            }
        #endif
            break;
        }
        case CANTRCV_TRCVMODE_SLEEP:
        {
            Retval = Aecanphy_Ip_SetMode(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_OFFLINE_MODE);
            break;
        }
        default:
        {
            /* nothing to do */
            break;
        }
    }

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_SET_OPMODE);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
}

/* Ipw_GetOpMode */
Std_ReturnType CanTrcv_43_AE_Ipw_GetOpMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                         CanTrcv_TrcvModeType* OpMode
                                                        )
{
    Aecanphy_Ip_StatusType Retval;
    Aecanphy_Ip_TransceiverModeType TransceiverMode;

    Retval = Aecanphy_Ip_GetMode(TransceiverConfig->CanTrcv_u8HwTransceiverId, &TransceiverMode);

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        /* Map the modes supported by hw to modes of autosar */
        switch (TransceiverMode)
        {
            case AE_CANPHY_NORMAL_MODE:
            {
                *OpMode = CANTRCV_TRCVMODE_NORMAL;
                break;
            }
            case AE_CANPHY_OFFLINE_MODE:
            {
                if (CANTRCV_TRCVMODE_STANDBY == CanTrcv_43_AE_GetTrcvSwMode(TransceiverConfig->CanTrcv_u8SwTransceiverId))
                {
                    *OpMode = CANTRCV_TRCVMODE_STANDBY;
                }
                else
                {
                    *OpMode = CANTRCV_TRCVMODE_SLEEP;
                }
                break;
            }
            default:
            {
                Retval = AE_CANPHY_STATUS_FAILED;
                break;
            }
        }
    }

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_GET_OPMODE);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
}

/* Ipw_GetBusWuReason */
Std_ReturnType CanTrcv_43_AE_Ipw_GetBusWuReason(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                              CanTrcv_TrcvWakeupReasonType * Reason
                                                             )
{
    Std_ReturnType Retval = E_OK;
#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    uint32 Flag = 0U;
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */
    CanTrcv_TrcvWakeupReasonType WuReasonTemp = CANTRCV_WU_NOT_SUPPORTED;

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    if (AE_CANPHY_STATUS_SUCCESS == Aecanphy_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag))
    {
        if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
        {
            /* A bus wakeup detected */
            WuReasonTemp = CANTRCV_WU_BY_BUS;
        }
        else
        {
            /* No reasons detected, return E_NOT_OK */
            Retval = E_NOT_OK;
        }
    }
    else
    {
        /* Still return E_OK in this case, because infact the reason here is CANTRCV_WU_ERROR */
        WuReasonTemp = CANTRCV_WU_ERROR;
        /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
        CanTrcv_Ipw_ReportSpiMiscommunication(AE_CANPHY_STATUS_ERR_SPI, CANTRCV_43_AE_SID_GET_BUS_WU_REASON);
    }
#else
    (void)TransceiverConfig;
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

    if ((Std_ReturnType)E_OK == Retval)
    {
        *Reason = WuReasonTemp;
    }
    return Retval;
}

/* Ipw_SetWakeupMode */
Std_ReturnType CanTrcv_43_AE_Ipw_SetWakeupMode(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig,
                                                             CanTrcv_TrcvWakeupModeType TrcvWakeupMode
                                                            )
{
#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    Aecanphy_Ip_StatusType Retval = AE_CANPHY_STATUS_SUCCESS;
#else
    /* If WAKEUP mode equals to NOT_SUPPORTED, this function will return NOT_OK always */
    Aecanphy_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;
#endif
#if ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) && (CANTRCV_43_AE_ECUM_USED == STD_ON))
    uint32 Flag = 0U;
#endif

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    switch (TrcvWakeupMode)
    {
        case CANTRCV_WUMODE_CLEAR:
        {
            /* Clear the wakeup flag stored from HW */
            Retval = Aecanphy_Ip_ClearEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, AE_CANPHY_WKUP_EVENT);
            break;
        }
        case CANTRCV_WUMODE_ENABLE:
        {
        #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
            Retval = Aecanphy_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);
            if (AE_CANPHY_STATUS_SUCCESS == Retval)
            {
                if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
                {
                    EcuM_SetWakeupEvent(TransceiverConfig->CanTrcv_WakeupSourceMask);
                }
            }
        #endif /* (CANTRCV_43_AE_ECUM_USED == STD_ON) */

        #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
            if (AE_CANPHY_STATUS_SUCCESS == Retval)
        #endif /* (CANTRCV_43_AE_ECUM_USED == STD_ON) */
            {
                CanTrcv_Ipw_eWakeupMode[TransceiverConfig->CanTrcv_u8SwTransceiverId] = CANTRCV_WUMODE_ENABLE;

            #if (CANTRCV_43_AE_ICU_USED == STD_ON)
                /* Use for interrupt context: CanTrcv_CheckWakeup */
                Icu_EnableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
            #endif /* (CANTRCV_43_AE_ICU_USED == STD_ON) */
            }
            break;
        }
        case CANTRCV_WUMODE_DISABLE:
        {
            CanTrcv_Ipw_eWakeupMode[TransceiverConfig->CanTrcv_u8SwTransceiverId] = CANTRCV_WUMODE_DISABLE;
        #if (CANTRCV_43_AE_ICU_USED == STD_ON)
            /* use for interrupt context: CanTrcv_CheckWakeup */
            Icu_DisableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
        #endif
            break;
        }
        default:
        {
            /* nothing to do */
            break;
        }
    }

    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_SET_WAKEUP_MODE);
#else
    /* Prevent compiler warnings */
    (void)TransceiverConfig;
    (void)TrcvWakeupMode;
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
}

Std_ReturnType CanTrcv_43_AE_Ipw_CheckWakeupFlag(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig)
{
    Aecanphy_Ip_StatusType Retval;

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
    uint32 Flag = 0U;

    Retval = Aecanphy_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) == 0U)
        {
            CanIf_CheckTrcvWakeFlagIndication(TransceiverConfig->CanTrcv_u8CanIfTransceiverId);
        }
        else if (CANTRCV_WUMODE_ENABLE == CanTrcv_Ipw_eWakeupMode[TransceiverConfig->CanTrcv_u8SwTransceiverId])
        {
        #if (CANTRCV_43_AE_ECUM_USED == STD_ON)
            EcuM_SetWakeupEvent(TransceiverConfig->CanTrcv_WakeupSourceMask);
        #endif /* (CANTRCV_43_AE_ECUM_USED == STD_ON) */
        }
        else
        {
            /* Nothing to do */
        }
    }
#else
    /* Always return NOT_OK when WAKEUP mode equals to NOT_SUPPORTED */
    /* Prevent compiler warnings */
    (void)TransceiverConfig;
    Retval = AE_CANPHY_STATUS_FAILED;
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
}

Std_ReturnType CanTrcv_43_AE_Ipw_CheckWakeup(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig)
{
    Aecanphy_Ip_StatusType Retval = AE_CANPHY_STATUS_FAILED;
#if ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) && (CANTRCV_43_AE_ECUM_USED == STD_ON))
    uint32 Flag = 0U;

    /* if CanTrcv_SetWakeupMode(CANTRCV_WUMODE_DISABLE) was called, no events will be raised */
    if (CANTRCV_WUMODE_ENABLE == CanTrcv_Ipw_eWakeupMode[TransceiverConfig->CanTrcv_u8SwTransceiverId])
    {
        Retval = Aecanphy_Ip_GetEventStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);

        if (AE_CANPHY_STATUS_SUCCESS == Retval)
        {
            if ((AE_CANPHY_CANPHY_MONITOR_REG_CANPHY_WKUP_FLAG & Flag) != 0U)
            {
                EcuM_SetWakeupEvent(TransceiverConfig->CanTrcv_WakeupSourceMask);
            }
        }
    }
#else
    /* Prevent compiler warnings */
    (void)TransceiverConfig;
#endif /* ((CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) && (CANTRCV_43_AE_ECUM_USED == STD_ON)) */

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
}

#if ((CANTRCV_43_AE_BUSERR_EN == STD_ON) && (CANTRCV_43_AE_DEM_USED == STD_ON))
void CanTrcv_43_AE_Ipw_CheckBusError(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig)
{
    Aecanphy_Ip_StatusType Retval;
    uint32 Flag = 0U;

    Retval = Aecanphy_Ip_GetLiveStatusFlag(TransceiverConfig->CanTrcv_u8HwTransceiverId, &Flag);

    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        /* Check if the transceiver is one of error states: Dominant timeout, invalid state */
        if (((AE_CANPHY_CANPHY_MONITOR_REG_TXDOM_TIMEDOUT_LIVE_STATUS | AE_CANPHY_CANPHY_MONITOR_REG_INVALID_STATE_LIVE_STATUS) & Flag) != 0U)
        {
            (void)Dem_SetEventStatus(TransceiverConfig->CanTrcv_DemEventId, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void)Dem_SetEventStatus(TransceiverConfig->CanTrcv_DemEventId, DEM_EVENT_STATUS_PASSED);
        }
    }
}
#endif /* ((CANTRCV_43_AE_BUSERR_EN == STD_ON) && (CANTRCV_43_AE_DEM_USED == STD_ON)) */

/* Ipw_DeInit */
Std_ReturnType CanTrcv_43_AE_Ipw_DeInit(const CanTrcv_43_AE_TransceiverConfigType * TransceiverConfig)
{
    Aecanphy_Ip_StatusType Retval;

    Retval = Aecanphy_Ip_DeInit(TransceiverConfig->CanTrcv_u8HwTransceiverId);

#if (CANTRCV_43_AE_ICU_USED == STD_ON)
    if (AE_CANPHY_STATUS_SUCCESS == Retval)
    {
        /* Disable notification */
        Icu_DisableNotification(TransceiverConfig->CanTrcv_u16IcuChnId);
    }
#endif
    /* If the read/write commands can't be written successfully to transceiver by Spi, Report det runtime */
    CanTrcv_Ipw_ReportSpiMiscommunication(Retval, CANTRCV_43_AE_SID_DEINIT);

    return (AE_CANPHY_STATUS_SUCCESS == Retval) ? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK);
}

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
