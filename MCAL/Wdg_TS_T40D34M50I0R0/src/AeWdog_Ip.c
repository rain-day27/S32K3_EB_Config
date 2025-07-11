/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup AeWdog_Ip
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

#include "AeWdog_Ip.h"
#include "Devassert.h"
#include "OsIf.h"
#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_VENDOR_ID_C                      43
#define AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C       7
#define AEWDOG_IP_AR_RELEASE_REVISION_VERSION_C    0
#define AEWDOG_IP_SW_MAJOR_VERSION_C               5
#define AEWDOG_IP_SW_MINOR_VERSION_C               0
#define AEWDOG_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and AeWdog_Ip header file are of the same vendor */
#if (AEWDOG_IP_VENDOR_ID_C != AEWDOG_IP_VENDOR_ID)
#error "AeWdog_Ip.c and AeWdog_Ip.h have different vendor ids"
#endif

/* Check if current file and AeWdog_Ip header file are of the same Autosar version */
#if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C     != AEWDOG_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != AEWDOG_IP_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_REVISION_VERSION_C  != AEWDOG_IP_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of AeWdog_Ip.c and AeWdog_Ip.h are different"
#endif

/* Check if current file and AeWdog_Ip header file are of the same software version */
#if ((AEWDOG_IP_SW_MAJOR_VERSION_C != AEWDOG_IP_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_SW_MINOR_VERSION_C != AEWDOG_IP_SW_MINOR_VERSION) || \
     (AEWDOG_IP_SW_PATCH_VERSION_C != AEWDOG_IP_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of AeWdog_Ip.c and AeWdog_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert header file are of the same Autosar version */
    #if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C    != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of AeWdog_Ip.c and Devassert.h are different"
    #endif
        /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of AeWdog_Ip.c and Mcal.h are different"
    #endif

    /* Check if current file and Osif header file are of the same Autosar version */
    #if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of AeWdog_Ip.c and Osif.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#if (AEWDOG_IP_ENABLE == STD_ON)

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
    #define AEWDOG_IP_LFSR_POLYNOMIAL_16               ((uint16)0x1021)
#else
    #define AEWDOG_IP_DEFAULT_TOKEN_VALUE_16           ((uint16)0x5AB2)
#endif

#define AEWDOG_IP_DATA_WIDTH_16                 ((uint8)16UL)

#define AEWDOG_IP_UNLOCK_KEY_16                 ((uint16)0xAE00)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONST_UNSPECIFIED

#include "Wdg_MemMap.h"

/*! @brief Table of base addresses for AEWDOG instances. */
static AEC_AE_Type * const AeWdog_Ip_apxBase[] = IP_AEC_AE_BASE_PTRS;

#define WDG_STOP_SEC_CONST_UNSPECIFIED

#include "Wdg_MemMap.h"

#ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED

#define WDG_START_SEC_VAR_INIT_16
#include "Wdg_MemMap.h"

static uint16 AeWdog_Ip_u16LFSRValue = AEWDOG_IP_TOKEN_INIT_VALUE_16;

#define WDG_STOP_SEC_VAR_INIT_16
#include "Wdg_MemMap.h"

#endif
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

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

#ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
/*!
 * @brief Compute answer expected by alive watchdog in challenger mode.
 *
 * @param[in] N/A
 * @return 16 bit word which is the new LFSR value
 */
static uint16 AeWdog_Ip_ComputeAnswer(void)
{
    uint16 Ret= (uint16) AeWdog_Ip_u16LFSRValue;

    if ((uint16)0 != (AeWdog_Ip_u16LFSRValue & (((uint16)1) << 15)))
    {
        AeWdog_Ip_u16LFSRValue = ((AeWdog_Ip_u16LFSRValue << 1) & ((uint16)0xffff)) ^ AEWDOG_IP_LFSR_POLYNOMIAL_16;
    }
    else
    {
        AeWdog_Ip_u16LFSRValue = ((AeWdog_Ip_u16LFSRValue << 1) & ((uint16)0xffff));
    }
    return ((uint16) Ret);
}
#endif /* AEWDOG_IP_CHALLENGER_WATCHDOG_USED */

/*!
 * @brief convert status from AEC to AEWDOG.
 *
 * @param[in] status of Aec
 * @return The status of the process:
 *      -   AEWDOG_IP_STATUS_SUCCESS - successfully
 *      -   AEWDOG_IP_STATUS_ERROR  - error
 *      -   AEWDOG_IP_STATUS_TIMEOUT - timeout
 */
static inline AeWdog_Ip_StatusType AeWdog_Ip_ConvertAecToAeWdogStatus(const uint32 AecErrorCode)
{
    const AeWdog_Ip_StatusType AeWdogStatus[] =
    {
        AEWDOG_IP_STATUS_SUCCESS,   /*!< Success */
        AEWDOG_IP_STATUS_ERROR,     /*!< failure */
        AEWDOG_IP_STATUS_TIMEOUT,   /*!< Timeout */
        AEWDOG_IP_STATUS_ERROR      /*!< Special case to cover both ERROR and TIMEOUT cases */
    };

     /* Convert to AeWdog status */
    return AeWdogStatus[AecErrorCode];
}

/*!
 * @brief Refresh AEWDOG
 *
 * This method needs to be called within the window period
 * specified by the Compare Low and Compare High registers
 *
 * @param[in] Base AEWDOG base pointer
 */
static inline void AeWdog_Ip_Refresh(AEC_AE_Type * const Base)
{
    uint32 TempRegAnswer;

    /* Check watchdog mode */
    #ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
    TempRegAnswer = (uint32)AeWdog_Ip_ComputeAnswer();
    #else
    TempRegAnswer = AEWDOG_IP_DEFAULT_TOKEN_VALUE_16;
    #endif
    (void)Aec_Ip_SpiWrite((uint32)(&(Base->ALIVE_WD_ANSWER)), AEWDOG_IP_DATA_WIDTH_16, TempRegAnswer);
}

/*!
 * @brief Get the AEWDOG enable bit.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The state of the device enable bit:
 *      -   FALSE - AEWDOG disabled
 *      -   TRUE  - AEWDOG enabled
 */
static inline boolean AeWdog_Ip_IsEnabled(const AEC_AE_Type * const Base)
{
    uint32 TempRegVal = 0U;
    boolean Ret = TRUE;
    Aec_Ip_StatusType ReturnStatus;
    uint16 CurrentPeriod;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->ALIVE_WD_CFG)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);
    if (AEC_STATUS_SUCCESS != ReturnStatus)
    {
        Ret = FALSE;
    }
    else
    {
        CurrentPeriod = (uint16)TempRegVal & (AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_MASK);
        /* Check if CurrentPeriod is disabled or has time value */
        if ((uint16)AEWDOG_IP_WD_PERIOD_DISABLED == CurrentPeriod)
        {
            Ret = FALSE;
        }
    }

    return Ret;
}

/*!
 * @brief Check if access to AEWDOG is locked by lock control register.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The state of the device enable bit:
 *      -   FALSE - access to AEWDOG locked
 *      -   TRUE  - access to AEWDOG unlocked
 */
static inline boolean AeWdog_Ip_IsAccessEnabled(const AEC_AE_Type * const Base)
{
    uint32 TempRegVal = 0U;
    boolean Ret;
    Aec_Ip_StatusType ReturnStatus;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);

    if (AEC_STATUS_SUCCESS != ReturnStatus)
    {
        Ret = FALSE;
    }
    else
    {
        if ((uint16)0 != (((uint16)TempRegVal) & (AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK)) )
        {
            Ret = FALSE;
        }
        else
        {
            Ret = TRUE;
        }
    }
    return Ret;
}

/*!
 * @brief Lock Write Access to Registers of the Alive Watchdog.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The status of the process:
 *      -   AEWDOG_IP_STATUS_SUCCESS - successfully
 *      -   AEWDOG_IP_STATUS_ERROR  - error
 *      -   AEWDOG_IP_STATUS_TIMEOUT - timeout
 */
static AeWdog_Ip_StatusType AeWdog_Ip_Lock(AEC_AE_Type * const Base)
{
    Aec_Ip_StatusType ReturnStatus;
    uint32 TempCr;
    uint32 TempRegVal = 0U;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);
    if (AEC_STATUS_SUCCESS == ReturnStatus)
    {
        TempCr = (TempRegVal | AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK | AEWDOG_IP_UNLOCK_KEY_16 | AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK_MASK);
        ReturnStatus = Aec_Ip_SpiWrite((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,TempCr);
    }
    return AeWdog_Ip_ConvertAecToAeWdogStatus((uint32)ReturnStatus);
}

/*!
 * @brief Unlock Write Access to Registers of the Alive Watchdog.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The status of the process:
 *      -   AEWDOG_IP_STATUS_SUCCESS - successfully
 *      -   AEWDOG_IP_STATUS_ERROR  - error
 *      -   AEWDOG_IP_STATUS_TIMEOUT - timeout
 */
static AeWdog_Ip_StatusType AeWdog_Ip_Unlock(AEC_AE_Type * const Base)
{
    Aec_Ip_StatusType ReturnStatus;
    uint32 TempCr;
    uint32 TempRegVal = 0U;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);
    if (AEC_STATUS_SUCCESS == ReturnStatus)
    {
        TempCr = ((TempRegVal & (~(AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK | AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK_MASK))) | AEWDOG_IP_UNLOCK_KEY_16);
        ReturnStatus = Aec_Ip_SpiWrite((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,TempCr);
    }
    return AeWdog_Ip_ConvertAecToAeWdogStatus((uint32)ReturnStatus);
}
/*==================================================================================================
*                                 GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : AeWdog_Ip_Init
 * Description   : This function initializes the AEWDOG instance to a specified
 * state
 *
 * @implements     AeWdog_Ip_Init_Activity
 *END**************************************************************************/
AeWdog_Ip_StatusType AeWdog_Ip_Init(const uint8 Instance, const AeWdog_Ip_ConfigType * const ConfigPtr)
{
    /* Base pointer */
    AEC_AE_Type * const Base = AeWdog_Ip_apxBase[Instance];
    /* Initialize status of AEC is ERROR */
    uint32 AecErrorCode = (uint32)AEC_STATUS_ERROR;
    /* Temporary storage for configuration register value */
    uint16 TempCr;

#if (AEWDOG_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < AEC_AE_INSTANCE_COUNT);
    DevAssert(ConfigPtr != NULL_PTR);
#endif

    /* Check if the AeWdog instance is already enabled */
    if (FALSE == AeWdog_Ip_IsEnabled(Base))
    {
        /* If AEWDOG disabled, status of AEC is SUCCESS  */
        AecErrorCode = (uint32)AEC_STATUS_SUCCESS;
        /* Check access to AEWDOG */
        if (FALSE == AeWdog_Ip_IsAccessEnabled(Base))
        {
            AecErrorCode = (uint32)AeWdog_Ip_Unlock(Base);
        }

        /* Check status of AEC */
        if ((uint32)AEC_STATUS_SUCCESS == AecErrorCode)
        {
            /* Sets alive watchdog configuration */
            TempCr = (  AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC(ConfigPtr->eFaultRespType)
                        | AEC_AE_ALIVE_WD_CFG_WDW_MODE(ConfigPtr->eAeWdogMode)
                        | AEC_AE_ALIVE_WD_CFG_WDW_BADRESP(ConfigPtr->eMaxBadResp)
                        | AEC_AE_ALIVE_WD_CFG_WDW_PERIOD(ConfigPtr->eWindowPeriod)
                        | AEC_AE_ALIVE_WD_CFG_WDW_DC(ConfigPtr->eWindowDutyCycle));
#ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
            AecErrorCode |= (uint32)Aec_Ip_SpiWrite((uint32)(&(Base->ALIVE_WD_TOKEN)), \
                                                    AEWDOG_IP_DATA_WIDTH_16, \
                                                    (uint32)AEWDOG_IP_TOKEN_INIT_VALUE_16);
#endif

            AecErrorCode |= (uint32)Aec_Ip_SpiWrite((uint32)(&(Base->ALIVE_WD_CFG)), AEWDOG_IP_DATA_WIDTH_16, (uint32)TempCr);

            AecErrorCode |= (uint32)Aec_Ip_SpiWrite((uint32)(&(Base->FAULT_WD_CFG)), \
                                                    AEWDOG_IP_DATA_WIDTH_16, \
                                                    (uint32)AEWDOG_IP_FAULT_WATCHDOG_WINDOW_PERIOD_VALUE_16);

            AecErrorCode |= (uint32)AeWdog_Ip_Lock(Base);
        }

    }

    /* status of the process */
    return AeWdog_Ip_ConvertAecToAeWdogStatus(AecErrorCode);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : AeWdog_Ip_Service
 * Description   : This function services the AEWDOG instance counter
 *
 * @implements     AeWdog_Ip_Service_Activity
 *END**************************************************************************/
void AeWdog_Ip_Service(const uint8 Instance)
{
#if (AEWDOG_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < AEC_AE_INSTANCE_COUNT);
#endif

    /* Base pointer */
    AEC_AE_Type * Base = AeWdog_Ip_apxBase[Instance];

    if (TRUE == AeWdog_Ip_IsEnabled(Base))
    {
        if (FALSE == AeWdog_Ip_IsAccessEnabled(Base))
        {
            (void)AeWdog_Ip_Unlock(Base);
        }
        AeWdog_Ip_Refresh(Base);
        (void)AeWdog_Ip_Lock(Base);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : AeWdog_Ip_ConfigWindow
 * Description   : Configures the Window duty cycle and Watchdog Window Duration
 *                 for ae alive watchdog.
 *
 * @implements     AeWdog_Ip_ConfigWindow_Activity
 *END**************************************************************************/
AeWdog_Ip_StatusType AeWdog_Ip_ConfigWindow(const uint8 Instance,
                                            const AeWdog_Ip_WindowDutyCycleType WindowDutyCycle,
                                            const AeWdog_Ip_WindowPeriodType WindowPeriod
                                           )
{
#if (AEWDOG_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < AEC_AE_INSTANCE_COUNT);
    DevAssert( (uint32)WindowDutyCycle < (1UL << AEC_AE_ALIVE_WD_CFG_WDW_DC_WIDTH    ) );
    DevAssert( (uint32)WindowPeriod    < (1UL << AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_WIDTH) );
#endif

    uint32 AecErrorCode      = (uint32)AEC_STATUS_SUCCESS;   /* Initialize status of AEC is SUCCESS */
    uint32 ConfigRegVal      = 0U;                           /* Temporary storage for current configuration register value */
    uint16 ConfigWindow      = 0U;                           /* Temporary storage for configuration register value */
    AEC_AE_Type * const Base = AeWdog_Ip_apxBase[Instance];    /* Base pointer */

    /* Check if AEWDG is locked */
    if (FALSE == AeWdog_Ip_IsAccessEnabled(Base))
    {
        AecErrorCode = (uint32)AeWdog_Ip_Unlock(Base);
    }

    if ((uint32)AEC_STATUS_SUCCESS == AecErrorCode)
    {
        /* Read the current configuration value */
        AecErrorCode |= (uint32)Aec_Ip_SpiRead((uint32)(&(Base->ALIVE_WD_CFG)), AEWDOG_IP_DATA_WIDTH_16, &ConfigRegVal);

        /* Configure with new Window values */
        ConfigWindow = (uint16)(ConfigRegVal & (~(AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_MASK | AEC_AE_ALIVE_WD_CFG_WDW_DC_MASK)));
        ConfigWindow |= (AEC_AE_ALIVE_WD_CFG_WDW_PERIOD(WindowPeriod) | AEC_AE_ALIVE_WD_CFG_WDW_DC(WindowDutyCycle));

        /* Write it back */
        AecErrorCode |= (uint32)Aec_Ip_SpiWrite((uint32)(&(Base->ALIVE_WD_CFG)), AEWDOG_IP_DATA_WIDTH_16, (uint32)ConfigWindow);

        #ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
        if (AEWDOG_IP_WD_PERIOD_DISABLED == WindowPeriod)
        {
            /* Watchdog is disabled, re-seed the token for the next time enterring challenge mode */
            AeWdog_Ip_u16LFSRValue = AEWDOG_IP_TOKEN_INIT_VALUE_16;
        }
        #endif

        /* Lock write access to AEWDG */
        AecErrorCode |= (uint32)AeWdog_Ip_Lock(Base);
    }

    return AeWdog_Ip_ConvertAecToAeWdogStatus(AecErrorCode);
}

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif


#include "Wdg_MemMap.h"

#endif /* (AEWDOG_IP_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */
