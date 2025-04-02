/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
*   @file AeLinPhy_LinTrcv_Ip.c
*
*   @addtogroup AELINPHY_IP
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "AeLinPhy_LinTrcv_Ip.h"
#include "Soc_Ips.h"
#include "OsIf.h"
#include "Aec_Ip.h"
#if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif /* (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON) */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define AELINPHY_LINTRCV_IP_VENDOR_ID_C                      43
#define AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION_C       7
#define AELINPHY_LINTRCV_IP_AR_RELEASE_REVISION_VERSION_C    0
#define AELINPHY_LINTRCV_IP_SW_MAJOR_VERSION_C               5
#define AELINPHY_LINTRCV_IP_SW_MINOR_VERSION_C               0
#define AELINPHY_LINTRCV_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if (AELINPHY_LINTRCV_IP_VENDOR_ID_C != AELINPHY_LINTRCV_IP_VENDOR_ID)
    #error "AeLinPhy_LinTrcv_Ip.c and AeLinPhy_LinTrcv_Ip.h have different vendor ids"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip header file are of the same Autosar version */
#if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION_C    != AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION_C    != AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_AR_RELEASE_REVISION_VERSION_C != AELINPHY_LINTRCV_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of AeLinPhy_LinTrcv_Ip.c and AeLinPhy_LinTrcv_Ip.h are different"
#endif
/* Check if current file and AeLinPhy_LinTrcv_Ip header file are of the same Software version */
#if ((AELINPHY_LINTRCV_IP_SW_MAJOR_VERSION_C != AELINPHY_LINTRCV_IP_SW_MAJOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_SW_MINOR_VERSION_C != AELINPHY_LINTRCV_IP_SW_MINOR_VERSION) || \
     (AELINPHY_LINTRCV_IP_SW_PATCH_VERSION_C != AELINPHY_LINTRCV_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of AeLinPhy_LinTrcv_Ip.c and AeLinPhy_LinTrcv_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Soc_Ips.h header file are of the same Autosar version */
    #if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION_C != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION_C !=  SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of AeLinPhy_LinTrcv_Ip.h and Soc_Ips.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION_C !=  OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of AeLinPhy_LinTrcv_Ip.h and OsIf.h are different"
    #endif
  
    /* Check if current file and Aec_Ip.h header file are of the same Autosar version */
    #if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION_C != AEC_IP_AR_RELEASE_MAJOR_VERSION) || \
         (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION_C !=  AEC_IP_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of AeLinPhy_LinTrcv_Ip.h and Aec_Ip.h are different"
    #endif

    #ifdef AELINPHY_LINTRCV_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
        /* Check if current file and RegLockMacros.h header file are of the same Autosar version */
        #if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of AeLinPhy_LinTrcv_Ip.h and RegLockMacros.h are different"
        #endif
    #endif /* AELINPHY_LINTRCV_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */

    #if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Devassert.h header file are of the same Autosar version */
        #if ((AELINPHY_LINTRCV_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (AELINPHY_LINTRCV_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of AeLinPhy_LinTrcv_Ip.h and Devassert.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#define AELINPHY_LINTRCV_IP_DATA_WIDTH                     (uint8)16U
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define AEC_AE_RSTGEN_CFG_ADDR                    (0x44U)
#define AEC_AE_LINPHY_CFG_ADDR                    (0x60U)
#define AEC_AE_LINPHY_MONITOR_ADDR                (0x64U)
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : AeLinPhy_LinTrcv_Ip_Init
 * Description   : This function initializes a LINPHY Instance for operation.
 *
 *END**************************************************************************/
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_Init(const uint8 Instance, const AeLinPhy_LinTrcv_Ip_UserConfigType *LinTrcvUserConfig)
{
    AeLinPhy_LinTrcv_Ip_StatusType RetVal = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    Aec_Ip_StatusType ReturnStatus;
    uint32 RegValue = 0;

#if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    AELINPHY_LINTRCV_IP_DEV_ASSERT(NULL_PTR != LinTrcvUserConfig);
    AELINPHY_LINTRCV_IP_DEV_ASSERT(Instance < AEC_AE_INSTANCE_COUNT);
    AELINPHY_LINTRCV_IP_DEV_ASSERT(Instance == LinTrcvUserConfig->Instance);
#endif /* (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON) */
    (void)LinTrcvUserConfig;
    (void)Instance;

    /*Allow user access to protected module specific when user mode is supported*/
#ifdef AELINPHY_LINTRCV_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
    AeLinTrcvPhy_LinTrcvTrcv_Ip_SetUserAccessAllowed(Instance);
#endif /* AELINPHY_LINTRCV_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */
    (void)Aec_Ip_SpiRead(AEC_AE_RSTGEN_CFG_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, &RegValue);
    /* Activate IP for Lin Phy */
    RegValue |= AEC_AE_RSTGEN_CFG_RSTGEN_CFG(4) | AEC_AE_RSTGEN_CFG_RSTGEN_CFG(8);
    /* Set RSTGEN_CFG register */
    ReturnStatus = Aec_Ip_SpiWrite(AEC_AE_RSTGEN_CFG_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, RegValue);
    
    /* Check if set RSTGEN_CFG register is successfully, then enable LinPhy and set mode to standby */
    if (AEC_STATUS_SUCCESS == ReturnStatus)
    {
        (void)Aec_Ip_SpiRead(AEC_AE_LINPHY_CFG_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, &RegValue);
        /* Enable LINPHY */
        RegValue |= AEC_AE_LINPHY_CFG_LINPHY_ENABLE(1);
        
        /* Set mode to Normal */
        RegValue |= AEC_AE_LINPHY_CFG_MODE(2);
        RegValue &= ~AEC_AE_LINPHY_CFG_ENAWUP(1);
        
        /* Set LINPHY_CFG register */
        ReturnStatus = Aec_Ip_SpiWrite(AEC_AE_LINPHY_CFG_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, RegValue);
        
        if (AEC_STATUS_SUCCESS == ReturnStatus)
        {
            RetVal = AELINPHY_LINTRCV_IP_STATUS_SUCCESS;
        }
    }
    
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : AeLinPhy_LinTrcv_Ip_SetMode
 * Description   : This function is switched to mode in the parameter OpMode.
 *
 *END**************************************************************************/
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_SetMode(const uint8 Instance, const AeLinPhy_LinTrcv_Ip_TransceiverModeType OpMode)
{
    AeLinPhy_LinTrcv_Ip_StatusType RetVal = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    Aec_Ip_StatusType ReturnStatus;
    uint32 RegValue = 0;

#if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    AELINPHY_LINTRCV_IP_DEV_ASSERT(Instance < AEC_AE_INSTANCE_COUNT);
#endif /* (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON) */
    (void)Instance;
    /* Get value of LINPHY_CFG register*/
    (void)Aec_Ip_SpiRead(AEC_AE_LINPHY_CFG_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, &RegValue);
    /* Clear bits in order avoid to set incorrect mode */
    RegValue &= ~AEC_AE_LINPHY_CFG_MODE(3);
    switch (OpMode)
    {
        case AELINPHY_LINTRCV_IP_STANDBY_MODE:
            /* Set mode to Standby */
            RegValue |= AEC_AE_LINPHY_CFG_MODE(0);
            RegValue |= AEC_AE_LINPHY_CFG_ENAWUP(1);
            break;
        case AELINPHY_LINTRCV_IP_NORMAL_MODE:
            /* Set mode to Normal */
            RegValue |= AEC_AE_LINPHY_CFG_MODE(2);
            RegValue &= ~AEC_AE_LINPHY_CFG_ENAWUP(1);
            break;
        case AELINPHY_LINTRCV_IP_RECV_ONLY_MODE:
            /* Set mode to Listen only */
            RegValue |= AEC_AE_LINPHY_CFG_MODE(1);
            RegValue &= ~AEC_AE_LINPHY_CFG_ENAWUP(1);
            break;
        default:
            /* Set mode to OFF */
            RegValue |= AEC_AE_LINPHY_CFG_MODE(0);
            RegValue &= ~AEC_AE_LINPHY_CFG_ENAWUP(1);
            break;
    }
    
    /* Set LINPHY_CFG register */
    ReturnStatus = Aec_Ip_SpiWrite(AEC_AE_LINPHY_CFG_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, RegValue);
    
    if (AEC_STATUS_SUCCESS == ReturnStatus)
    {
        RetVal = AELINPHY_LINTRCV_IP_STATUS_SUCCESS;
    }
    
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : AeLinPhy_LinTrcv_Ip_GetMode
 * Description   : This function is used to get the current mode of the LinTrcv.
 *
 *END**************************************************************************/
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_GetMode(const uint8 Instance, AeLinPhy_LinTrcv_Ip_TransceiverModeType *TransceiverMode)
{
    AeLinPhy_LinTrcv_Ip_StatusType RetVal = AELINPHY_LINTRCV_IP_STATUS_SUCCESS;
    Aec_Ip_StatusType ReturnStatus;
    uint32 RegValue = 0;

#if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    AELINPHY_LINTRCV_IP_DEV_ASSERT(Instance < AEC_AE_INSTANCE_COUNT);
#endif /* (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON) */
    (void)Instance;
    /* Get value of LINPHY_CFG register*/
    ReturnStatus = Aec_Ip_SpiRead(AEC_AE_LINPHY_CFG_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, &RegValue);
    
    /* Check Read register is successfully */
    if (AEC_STATUS_SUCCESS == ReturnStatus)
    {
        switch (RegValue & AEC_AE_LINPHY_CFG_MODE_MASK)
        {
            case 0x02:
                /* Set TransceiverMode to Normal when CurrentMode = 2 */
                *TransceiverMode = AELINPHY_LINTRCV_IP_NORMAL_MODE;
                break;
            case 0x01:
                /* Set TransceiverMode to Receive Only when CurrentMode = 1 */
                *TransceiverMode = AELINPHY_LINTRCV_IP_RECV_ONLY_MODE;
                break;
            case 0x00:
                if(0u == (RegValue & AEC_AE_LINPHY_CFG_ENAWUP_MASK))
                {
                    /* Set TransceiverMode to  OFF when CurrentMode = 0 and ENAWUP = 0 */
                    *TransceiverMode = AELINPHY_LINTRCV_IP_OFF_MODE;
                }
                else
                {
                    /* Set TransceiverMode to  OFF when CurrentMode = 0 and ENAWUP = 1 */
                    *TransceiverMode = AELINPHY_LINTRCV_IP_STANDBY_MODE;
                }
                break;
            default:
                /* Report to error when the current mode is not available */
                RetVal = AELINPHY_LINTRCV_IP_STATUS_ERROR;
                break;
            
        }
    }
    else
    {
        /* Report to error when there is no communication to the transceiver */
        RetVal = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    }
    
    return RetVal;
    
}

/*FUNCTION**********************************************************************
 *
 * Function Name : AeLinPhy_LinTrcv_Ip_SetWakeupMode
 * Description   : This function use to enable/disable/clear the wakeup events.
 *
 *END**************************************************************************/
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_SetWakeupMode(const uint8 Instance, AeLinPhy_LinTrcv_Ip_TrcvWakeupModeType TrcvWakupMode)
{
    AeLinPhy_LinTrcv_Ip_StatusType RetVal = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    Aec_Ip_StatusType ReturnStatus;
    uint32 RegValue = 0;

#if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    AELINPHY_LINTRCV_IP_DEV_ASSERT(Instance < AEC_AE_INSTANCE_COUNT);
#endif /* (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON) */
    (void)Instance;
    /* Get value of LINPHY_MONITOR register*/
    ReturnStatus = Aec_Ip_SpiRead(AEC_AE_LINPHY_MONITOR_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, &RegValue);
    /* Check Read register is successfully */
    if (AEC_STATUS_SUCCESS == ReturnStatus)
    {
        switch (TrcvWakupMode)
        {
            case AELINPHY_LINTRCV_IP_WUMODE_ENABLE:
                /* Enable wakeup interrupt, The notification for wakeup events is enabled on the addressed network. */
                RegValue |= AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN(1);
                /* Set WKUP_FL bit to 0 to avoid clearing wakeup event which detect by HW because write 1 to WKUP_FL bit which is cleared directly */
                RegValue &= ~AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL(1);
                break;
            
            case AELINPHY_LINTRCV_IP_WUMODE_DISABLE:
                /* Disbale wakeup interrupt, The notification for wakeup events is disabled on the addressed network */
                RegValue &= ~AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN(1);
                /* Set WKUP_FL bit to 0 to avoid clearing wakeup event which detect by HW because write 1 to WKUP_FL bit which is cleared directly */
                RegValue &= ~AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL(1);
                break;
            case AELINPHY_LINTRCV_IP_WUMODE_CLEAR:
                /* Clear wakeup event */
                RegValue |= AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL(1);
                break;
            default:
                /* Nothing */
                break;
        }
        /* Set LINPHY_MONITOR register */
        ReturnStatus = Aec_Ip_SpiWrite(AEC_AE_LINPHY_MONITOR_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, RegValue);
        
        if(AEC_STATUS_SUCCESS == ReturnStatus)
        {
            RetVal = AELINPHY_LINTRCV_IP_STATUS_SUCCESS;
        }
    
    }
    
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : AeLinPhy_LinTrcv_Ip_CheckWakeupFlag
 * Description   : This function use to check the wakeup event.
 *
 *END**************************************************************************/
AeLinPhy_LinTrcv_Ip_StatusType AeLinPhy_LinTrcv_Ip_CheckWakeupFlag(const uint8 Instance)
{
    AeLinPhy_LinTrcv_Ip_StatusType RetVal = AELINPHY_LINTRCV_IP_STATUS_ERROR;
    Aec_Ip_StatusType ReturnStatus;
    uint32 RegValue = 0;

#if (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    AELINPHY_LINTRCV_IP_DEV_ASSERT(Instance < AEC_AE_INSTANCE_COUNT);
#endif /* (AELINPHY_LINTRCV_IP_DEV_ERROR_DETECT == STD_ON) */
    (void)Instance;
    /* Get value of LINPHY_MONITOR register*/
    ReturnStatus = Aec_Ip_SpiRead(AEC_AE_LINPHY_MONITOR_ADDR, AELINPHY_LINTRCV_IP_DATA_WIDTH, &RegValue);
    /* Check Read register is successfully */
    if (AEC_STATUS_SUCCESS == ReturnStatus)
    {
        /* Check the wakeup is detected */
        if(0u != (RegValue & AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL_MASK))
        {
            RetVal = AELINPHY_LINTRCV_IP_STATUS_SUCCESS;
        }
    }
    
    return RetVal;
}

#define LINTRCV_43_AE_STOP_SEC_CODE
#include "LinTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
