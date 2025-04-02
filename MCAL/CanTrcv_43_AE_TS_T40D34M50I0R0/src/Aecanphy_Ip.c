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
* @file         Aecanphy_Ip.c
*
* @addtogroup
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
#include "Aecanphy_Ip.h"
#include "Aecanphy_HwAccess.h"
#include "Aecanphy_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AECANPHY_IP_VENDOR_ID_C                    43
#define AECANPHY_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define AECANPHY_IP_AR_RELEASE_MINOR_VERSION_C     7
#define AECANPHY_IP_AR_RELEASE_REVISION_VERSION_C  0
#define AECANPHY_IP_SW_MAJOR_VERSION_C             5
#define AECANPHY_IP_SW_MINOR_VERSION_C             0
#define AECANPHY_IP_SW_PATCH_VERSION_C             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Aecanphy_Ip.c and Aecanphy_Ip.h header file are of the same vendor */
#if (AECANPHY_IP_VENDOR_ID_C != AECANPHY_IP_VENDOR_ID)
    #error "Aecanphy_Ip.c and Aecanphy_Ip.h have different vendor ids"
#endif
/* Check if Aecanphy_Ip.c and Aecanphy_Ip.h header file are of the same Autosar version */
#if ((AECANPHY_IP_AR_RELEASE_MAJOR_VERSION_C != AECANPHY_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_MINOR_VERSION_C != AECANPHY_IP_AR_RELEASE_MINOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_REVISION_VERSION_C != AECANPHY_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Aecanphy_Ip.c and Aecanphy_Ip.h are different"
#endif

/* Check if Aecanphy_Ip.c and Aecanphy_Ip.h header file are of the same software version */
#if ((AECANPHY_IP_SW_MAJOR_VERSION_C != AECANPHY_IP_SW_MAJOR_VERSION) || \
     (AECANPHY_IP_SW_MINOR_VERSION_C != AECANPHY_IP_SW_MINOR_VERSION) || \
     (AECANPHY_IP_SW_PATCH_VERSION_C != AECANPHY_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aecanphy_Ip.c and Aecanphy_Ip.h are different"
#endif

/* Check if Aecanphy_Ip.c and Aecanphy_HwAccess.h header file are of the same vendor */
#if (AECANPHY_IP_VENDOR_ID_C != AECANPHY_HWACCESS_VENDOR_ID)
    #error "Aecanphy_Ip.c and Aecanphy_HwAccess.h have different vendor ids"
#endif
/* Check if Aecanphy_Ip.c and Aecanphy_HwAccess.h header file are of the same Autosar version */
#if ((AECANPHY_IP_AR_RELEASE_MAJOR_VERSION_C != AECANPHY_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_MINOR_VERSION_C != AECANPHY_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_REVISION_VERSION_C != AECANPHY_HWACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Aecanphy_Ip.c and Aecanphy_HwAccess.h are different"
#endif

/* Check if Aecanphy_Ip.c and Aecanphy_HwAccess.h header file are of the same software version */
#if ((AECANPHY_IP_SW_MAJOR_VERSION_C != AECANPHY_HWACCESS_SW_MAJOR_VERSION) || \
     (AECANPHY_IP_SW_MINOR_VERSION_C != AECANPHY_HWACCESS_SW_MINOR_VERSION) || \
     (AECANPHY_IP_SW_PATCH_VERSION_C != AECANPHY_HWACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aecanphy_Ip.c and Aecanphy_HwAccess.h are different"
#endif

/* Check if Aecanphy_Ip.c and Aecanphy_Ip_CfgDefines.h header file are of the same vendor */
#if (AECANPHY_IP_VENDOR_ID_C != AECANPHY_IP_CFGDEFINES_VENDOR_ID)
    #error "Aecanphy_Ip.c and Aecanphy_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if Aecanphy_Ip.c and Aecanphy_Ip_CfgDefines.h header file are of the same Autosar version */
#if ((AECANPHY_IP_AR_RELEASE_MAJOR_VERSION_C != AECANPHY_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_MINOR_VERSION_C != AECANPHY_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (AECANPHY_IP_AR_RELEASE_REVISION_VERSION_C != AECANPHY_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Aecanphy_Ip.c and Aecanphy_Ip_CfgDefines.h are different"
#endif

/* Check if Aecanphy_Ip.c and Aecanphy_Ip_CfgDefines.h header file are of the same software version */
#if ((AECANPHY_IP_SW_MAJOR_VERSION_C != AECANPHY_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (AECANPHY_IP_SW_MINOR_VERSION_C != AECANPHY_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (AECANPHY_IP_SW_PATCH_VERSION_C != AECANPHY_IP_CFGDEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aecanphy_Ip.c and Aecanphy_Ip_CfgDefines.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define AE_CANPHY_CANPHY_CFG_REG_ADDR                  (0x70U)
#define AE_CANPHY_CANPHY_MONITOR_REG_ADDR              (0x74U)
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

static const Aecanphy_Ip_ConfigType * Aecanphy_Ip_pxState[1U];

#define CANTRCV_43_AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_Init
 * Description   : Initialize state pointer and puts the device in OFFLINE mode.
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_Init(uint8 HwChannel,
                                        const Aecanphy_Ip_ConfigType * Config
                                       )
{
    uint32 Command = 0U;
    Aecanphy_Ip_StatusType RetVal;

    /* Enable Transceiver */
    Command = AEC_AE_CANPHY_CFG_CANPHY_ENABLE_MASK;

    /* Set mode for Transceiver */
    Command |= (uint32)Config->DeviceModeAfterInit;

    /* Write to CANPHY_CFG register */
    RetVal = Aecanphy_WriteRegisterViaSpi(&(Config->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        Aecanphy_Ip_pxState[HwChannel] = Config;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_SetMode
 * Description   : Puts the device in OFFLINE, NORMAL or LISTEN_ONLY modes.
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_SetMode(uint8 HwChannel,
                                           Aecanphy_Ip_TransceiverModeType Mode
                                          )
{
    uint32 Command = 0U;
    Aecanphy_Ip_StatusType RetVal;
    const Aecanphy_Ip_ConfigType * State = Aecanphy_Ip_pxState[HwChannel];

    Command = AEC_AE_CANPHY_CFG_CANPHY_ENABLE_MASK;

    /* Set mode for Transceiver */
    Command |= (uint32)Mode;

    /* Write to CANPHY_CFG register */
    RetVal = Aecanphy_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, Command, 16U);

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_GetMode
 * Description   : Gets the device mode.
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_GetMode(uint8 HwChannel,
                                           Aecanphy_Ip_TransceiverModeType * Mode
                                          )
{
    uint32 Data = 0U;
    Aecanphy_Ip_StatusType RetVal;
    const Aecanphy_Ip_ConfigType * State = Aecanphy_Ip_pxState[HwChannel];

    RetVal = Aecanphy_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, &Data, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        /* Get mode for Transceiver */
        switch(Data & AEC_AE_CANPHY_CFG_MODE_MASK)
        {
            case 0x00:
            {
                *Mode = AE_CANPHY_OFFLINE_MODE;
                break;
            }
            case 0x01:
            {
                *Mode = AE_CANPHY_NORMAL_MODE;
                break;
            }
            case 0x03:
            {
                *Mode = AE_CANPHY_LISTEN_ONLY_MODE;
                break;
            }
            default:
            {
                RetVal = AE_CANPHY_STATUS_FAILED;
                break;
            }
        }
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_GetEventStatusFlag
 * Description   : Gets device's event flags which are Wakeup, Invalid state, Tx-dominant timeout flags.
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_GetEventStatusFlag(uint8 HwChannel,
                                                      uint32 * Event
                                                     )
{
    uint32 Data = 0U;
    Aecanphy_Ip_StatusType RetVal;
    const Aecanphy_Ip_ConfigType * State = Aecanphy_Ip_pxState[HwChannel];

    RetVal = Aecanphy_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, &Data, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        /* Get all events for Transceiver */
        *Event = Data & (AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK | AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK | AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_GetLiveStatusFlag
 * Description   : Gets device's live status flags which are Wakeup, Invalid state, Tx-dominant timeout flags.
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_GetLiveStatusFlag(uint8 HwChannel,
                                                     uint32 * Event
                                                    )
{
    uint32 Data = 0U;
    Aecanphy_Ip_StatusType RetVal;
    const Aecanphy_Ip_ConfigType * State = Aecanphy_Ip_pxState[HwChannel];

    RetVal = Aecanphy_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, &Data, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        /* Get all events for Transceiver */
        *Event = Data & (AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_MON_MASK | AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_MON_MASK | AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_MON_MASK);
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_ClearEventStatusFlag
 * Description   : Clears a given event flag which are Wakeup, Invalid state, Tx-dominant timeout flags
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_ClearEventStatusFlag(uint8 HwChannel,
                                                        Aecanphy_Ip_TransceiverEventType Event
                                                       )
{
    uint32 Command = 0U;
    Aecanphy_Ip_StatusType RetVal;
    const Aecanphy_Ip_ConfigType * State = Aecanphy_Ip_pxState[HwChannel];

    RetVal = Aecanphy_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, &Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        Command &= ~(AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);

        switch (Event)
        {
            case AE_CANPHY_WKUP_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK;
                break;
            }
            case AE_CANPHY_INVALID_STATE_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK;
                break;
            }
            case AE_CANPHY_TXDOM_TIMEDOUT_EVENT:
            {
                Command |= AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK;
                break;
            }
            default:
            {
                /* nothing to do */
                break;
            }
        }

        /* Write to CANPHY_CFG register */
        RetVal = Aecanphy_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, Command, 16U);
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_SetEventNotification
 * Description   : Enable a given event notification, if coresponding flag is set,
 * a notification will be sent to AEC which raises a INTERRUPT signal on INTERRUPT_OUT pin of AEC.
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_SetEventNotification(uint8 HwChannel,
                                                        Aecanphy_Ip_TransceiverEventType Event,
                                                        boolean IsEnable
                                                       )
{
    uint32 Command = 0U;
    Aecanphy_Ip_StatusType RetVal;
    const Aecanphy_Ip_ConfigType * State = Aecanphy_Ip_pxState[HwChannel];

    RetVal = Aecanphy_ReadRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, &Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        Command &= ~(AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);

        switch (Event)
        {
            case AE_CANPHY_WKUP_EVENT:
            {
                Command = (Command & (~AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN_MASK)) | AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN(IsEnable ? 1U : 0U);
                break;
            }
            case AE_CANPHY_INVALID_STATE_EVENT:
            {
                Command = (Command & (~AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN_MASK)) | AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN(IsEnable ? 1U : 0U);
                break;
            }
            case AE_CANPHY_TXDOM_TIMEDOUT_EVENT:
            {
                Command = (Command & (~AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN_MASK)) | AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN(IsEnable ? 1U : 0U);
                break;
            }
            default:
            {
                /* nothing to do */
                break;
            }
        }
        /* Write to CANPHY_CFG register */
        RetVal = Aecanphy_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, Command, 16U);
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aecanphy_Ip_DeInit
 * Description   : Sets state pointer to NULL and set all CANPHY registers to default value.
 *
 *END**************************************************************************/
Aecanphy_Ip_StatusType Aecanphy_Ip_DeInit(uint8 HwChannel)
{
    Aecanphy_Ip_StatusType RetVal;
    const Aecanphy_Ip_ConfigType * State = Aecanphy_Ip_pxState[HwChannel];
    uint32 Command = 0U;

    /* Write reset value to CANPHY_CFG register */
    RetVal = Aecanphy_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_CFG_REG_ADDR, Command, 16U);

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        /* clear all event flags */
        Command = (AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK |
                    AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK);
        /* Write reset value to CANPHY_CFG register */
        RetVal = Aecanphy_WriteRegisterViaSpi(&(State->SpiConfig), AE_CANPHY_CANPHY_MONITOR_REG_ADDR, Command, 16U);
    }

    if (AE_CANPHY_STATUS_SUCCESS == RetVal)
    {
        Aecanphy_Ip_pxState[HwChannel] = NULL_PTR;
    }

    return RetVal;
}

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
