/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
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
*   @file    CDD_Gdu.c
*   @version 5.0.0
*
*   @brief   AUTOSAR Gdu - HLD main source file.
*   @details Acts mostly as a wrapper for the low level driver.
*
*   @addtogroup CDD_GDU
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
#include "CDD_Gdu.h"
#include "SchM_Gdu.h"
#if (GDU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_VENDOR_ID_C                      43
#define GDU_AR_RELEASE_MAJOR_VERSION_C       4
#define GDU_AR_RELEASE_MINOR_VERSION_C       7
#define GDU_AR_RELEASE_REVISION_VERSION_C    0
#define GDU_SW_MAJOR_VERSION_C               5
#define GDU_SW_MINOR_VERSION_C               0
#define GDU_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (GDU_VENDOR_ID_C != GDU_VENDOR_ID)
    #error "CDD_Gdu.c and CDD_Gdu.h have different vendor ids"
#endif
#if ((GDU_AR_RELEASE_MAJOR_VERSION_C    != GDU_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_AR_RELEASE_MINOR_VERSION_C    != GDU_AR_RELEASE_MINOR_VERSION) || \
     (GDU_AR_RELEASE_REVISION_VERSION_C != GDU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Gdu.c and CDD_Gdu.h are different"
#endif
#if ((GDU_SW_MAJOR_VERSION_C != GDU_SW_MAJOR_VERSION) || \
     (GDU_SW_MINOR_VERSION_C != GDU_SW_MINOR_VERSION) || \
     (GDU_SW_PATCH_VERSION_C != GDU_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Gdu.c and CDD_Gdu.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (GDU_DEV_ERROR_DETECT == STD_ON)
    /* Check if source file and DET header file are of the same version */
    #if ((GDU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
            (GDU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Gdu.c and Det.h are different"
    #endif
#endif /* GDU_DEV_ERROR_DETECT == STD_ON */

    /* Check if current file and SchM_Gdu header file are of the same Autosar version */
    #if ((GDU_AR_RELEASE_MAJOR_VERSION_C != SCHM_GDU_AR_RELEASE_MAJOR_VERSION) || \
         (GDU_AR_RELEASE_MINOR_VERSION_C != SCHM_GDU_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Gdu.c and SchM_Gdu.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (GDU_DEV_ERROR_DETECT == STD_ON)

/** Macro used to check for development errors */
#define GDU_DEV_ASSERT(Expression) (Expression)

/** Macro used to call the Det error reporting mechanism */
#define Gdu_ReportDetError(ServiceId, ErrorId) \
    (void) Det_ReportError((uint16)GDU_MODULE_ID, 0u, ServiceId, ErrorId);

#else /* GDU_DEV_ERROR_DETECT == STD_ON */

/** Macro used to skip the dev error checks by replacing the given expression with TRUE */
#define GDU_DEV_ASSERT(Expression) (TRUE)

/** Macro used to skip the error reporting to Det when GDU_DEV_ERROR_DETECT is STD_OFF */
#define Gdu_ReportDetError(ServiceId, ErrorId)

#endif /* GDU_DEV_ERROR_DETECT == STD_ON */

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
#define GDU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Gdu_MemMap.h"

#if (GDU_DEV_ERROR_DETECT == STD_ON)
static boolean Gdu_bInitialized;
#endif

#define GDU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Gdu_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        GDU initialization API.
* @details      Call this API to configure the driver.
*
* @param[in]    Configuration Contains the address of the configuration structure.
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          The 6 PWM lines routed to this module are OFF.
* @implements   Gdu_Init_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_Init (const Gdu_Ip_ConfigType * Configuration)
{
    Std_ReturnType Status = E_NOT_OK;
    boolean RetVal = FALSE;
    /* Rule 17.8 A function parameter should not be modified */
    const Gdu_Ip_ConfigType * LocalConfig = Configuration;

#if (GDU_PRECOMPILE_SUPPORT == STD_ON)
    if (GDU_DEV_ASSERT(LocalConfig == NULL_PTR))
    {
        LocalConfig = Gdu_ConfigVariantPredefined[0];
        RetVal = TRUE;
    }
#else /* GDU_PRECOMPILE_SUPPORT */
    if (GDU_DEV_ASSERT(LocalConfig != NULL_PTR))
    {
        (void)LocalConfig;
        RetVal = TRUE;
    }
#endif /* GDU_PRECOMPILE_SUPPORT */
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_INITIALIZATION, GDU_DET_ERROR_PARAMETER);
    }

    if (RetVal == TRUE)
    {
        if (GDU_IP_STATUS_OK == Gdu_Ip_Init(LocalConfig))
        {
#if (GDU_DEV_ERROR_DETECT == STD_ON)
            Gdu_bInitialized = TRUE;
#endif
            Status = E_OK;
        }
        else
        {
            Status = E_NOT_OK;
        }
    }
    else
    {
        Status = GDU_RET_DET_PARAM;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Control the operation mode (enable/disable).
* @details      Following the recommendations from the manual, charge pump [CPEN] follows
*               the mode of the GDU [GDUEN].
*
* @param[in]    Mode specifies the desired mode
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @implements   Gdu_SetMode_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_SetMode (Gdu_Ip_ModeType Mode)
{
    Std_ReturnType Status = E_NOT_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((Mode > GDU_IP_MODE_MIN) && (Mode < GDU_IP_MODE_MAX)))
        {
            /* Enter critical region */
            SchM_Enter_Gdu_GDU_EXCLUSIVE_AREA_00();
            if (GDU_IP_STATUS_OK == Gdu_Ip_SetMode(Mode))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
            /* Exit critical region*/
            SchM_Exit_Gdu_GDU_EXCLUSIVE_AREA_00();
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_SETMODE, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_SETMODE, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Control the safe state (on/off).
* @details      Call this API to enable safe state before entering low power mode.
*
* @param[in]    SafeState specifies the desired safe state
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @implements   Gdu_SetSafeState_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_SetSafeState (Gdu_Ip_SafeStateType SafeState)
{
    Std_ReturnType Status = E_NOT_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((SafeState > GDU_IP_SAFESTATE_MIN) && (SafeState < GDU_IP_SAFESTATE_MAX)))
        {
            /* Enter critical region */
            SchM_Enter_Gdu_GDU_EXCLUSIVE_AREA_01();
            if (GDU_IP_STATUS_OK == Gdu_Ip_SetSafeState(SafeState))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
            /* Exit critical region*/
            SchM_Exit_Gdu_GDU_EXCLUSIVE_AREA_01();
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_SETSAFESTATE, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_SETSAFESTATE, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Get the status of the error conditions present in the INTF register.
*
* @param[out]   ErrorStatus structure containing bit-fields that indicate if an error is present or not
*               The user needs to create and pass an address to this type of structure
*               only if they are interested in the status of each error condition;
*               otherwise, the overall return status may be just enough.
*
* @return       the status of the command.
* @retval       E_OK no error conditions are active at the moment
* @retval       E_NOT_OK failure from the IP layer, *ErrorStatus was not written
* @retval       GDU_RET_ERROR one of the error conditions is active
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @implements   Gdu_GetStatus_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_GetStatus (Gdu_Ip_ErrorStatusType * ErrorStatus)
{
    Std_ReturnType Status = E_NOT_OK;
    Gdu_Ip_StatusType GduStatus = GDU_IP_STATUS_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        /* if ErrorStatus is a NULL_PTR the user will not get detailed information about each status bit;
        instead, they will know that one of the error bits is set when the return value is GDU_RET_ERROR */
        GduStatus = Gdu_Ip_GetStatus(ErrorStatus);

        if (GDU_IP_STATUS_OK == GduStatus)
        {
            Status = E_OK;
        }
        else if (GDU_IP_STATUS_ERROR == GduStatus)
        {
            Status = E_NOT_OK;
        }
        else
        {
            Status = GDU_RET_ERROR;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_GETSTATUS, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Start the delay measurement between the PWM edge and the feedback signal coming from
*               the FET gate driver.
*
* @param[in]    PwmChannel the measurement is performed on a specific PWM channel
* @param[in]    Edge the measurement is performed between two edges of the signal: rising or falling
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @pre          Make sure that the previous measurement had time to either finish or expire, because:
*               "Writting to DLYMCFG while delay measurement is enabled can corrupt the delay measurement."
* @implements   Gdu_StartDelayMeasurement_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_StartDelayMeasurement (Gdu_Ip_PwmChannelType PwmChannel,
                                          Gdu_Ip_EdgeType Edge
                                         )
{
    Std_ReturnType Status = E_NOT_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((PwmChannel > GDU_IP_PWM_CHANNEL_MIN) &&
                           (PwmChannel < GDU_IP_PWM_CHANNEL_MAX) &&
                           (Edge > GDU_IP_EDGE_MIN) &&
                           (Edge < GDU_IP_EDGE_MAX)))
        {
            if (GDU_IP_STATUS_OK == Gdu_Ip_StartDelayMeasurement(PwmChannel, Edge))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_START_DELAYMEAS, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_START_DELAYMEAS, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Read the delay measurement results.
*
* @param[out]   Delay delay measured in clock cycles
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_ERROR measurement result is unavailable or corrupted
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @implements   Gdu_ReadDelayMeasurement_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_ReadDelayMeasurement (uint8 * Delay)
{
    Std_ReturnType Status = E_NOT_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT(Delay != NULL_PTR))
        {
            switch (Gdu_Ip_ReadDelayMeasurement(Delay))
            {
                case GDU_IP_STATUS_OK:
                    Status = E_OK;
                break;

                case GDU_IP_STATUS_INVALID:
                    Status = GDU_RET_ERROR;
                break;

                case GDU_IP_STATUS_ERROR:
                default:
                    Status = E_NOT_OK;
                break;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_READ_DELAYMEAS, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_READ_DELAYMEAS, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Adjust the slew rate of the FET gate drivers.
*
* @param[in]    SlewRateSelect selects the HS/LS FETs, and the turn on / turn off waveforms
* @param[in]    SlewRateConfig pointer to a structure containing the configuration values
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @pre          Stop the PWMs inputs.
* @pre          Put the GDU in safe state before making big changes to these values.
* @implements   Gdu_AdjustSlewRate_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_AdjustSlewRate (Gdu_Ip_SlewRateSelectType SlewRateSelect,
                                   const Gdu_Ip_SlewRateConfigType * SlewRateConfig
                                  )
{
    Std_ReturnType Status = E_NOT_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if ((GDU_DEV_ASSERT(SlewRateSelect > GDU_IP_SLEWRATE_MIN) &&
                           (SlewRateSelect < GDU_IP_SLEWRATE_MAX) &&
                           (SlewRateConfig != NULL_PTR)))
        {
            if (GDU_IP_STATUS_OK == Gdu_Ip_AdjustSlewRate(SlewRateSelect, SlewRateConfig))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_ADJUSTSLEWRATE, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_ADJUSTSLEWRATE, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Configure the Iref trimming percentages.
*
* @param[in]    IrefTrimming structure containing trimming percentages for each of the six gates
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @implements   Gdu_SwIrefTrimming_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_SwIrefTrimming (Gdu_Ip_IrefTrimmingType IrefTrimming)
{
    Std_ReturnType Status = E_NOT_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_DEV_ASSERT((IrefTrimming.LG0 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.LG0 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.LG1 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.LG1 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.LG2 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.LG2 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.HG0 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.HG0 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.HG1 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.HG1 < GDU_IP_IREF_TRIM_MAX) &&
                           (IrefTrimming.HG2 > GDU_IP_IREF_TRIM_MIN) &&
                           (IrefTrimming.HG2 < GDU_IP_IREF_TRIM_MAX)))
        {
            /* Enter critical region */
            SchM_Enter_Gdu_GDU_EXCLUSIVE_AREA_02();
            if (GDU_IP_STATUS_OK == Gdu_Ip_SwIrefTrimming(IrefTrimming))
            {
                Status = E_OK;
            }
            else
            {
                Status = E_NOT_OK;
            }
            /* Exit critical region*/
            SchM_Exit_Gdu_GDU_EXCLUSIVE_AREA_02();
        }
        else
        {
            Gdu_ReportDetError(GDU_DET_SERVICE_SWIREFTRIMMING, GDU_DET_ERROR_PARAMETER);
            Status = GDU_RET_DET_PARAM;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_SWIREFTRIMMING, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Connect the HS pins towards HD or VSS in order to detect open loads,
*               loads shorted to HD, or loads shorted to GND.
* @details      Beware that pulling the same pin to both HD and VSS may cause a short circuit.
*
* @param[in]    OffStateDiagnostics structure containing boolean settings for each FET, and
*               each direction
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       E_NOT_OK failure from the IP layer
* @retval       GDU_RET_DET_UNINIT API called before driver initialization: error reported to Det
*
* @api
* @pre          CDD_GDU is initialized.
* @implements   Gdu_OffStateDiagnostics_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_OffStateDiagnostics (Gdu_Ip_OffStateDiagType OffStateDiagnostics)
{
    Std_ReturnType Status = E_NOT_OK;

    if (GDU_DEV_ASSERT(Gdu_bInitialized))
    {
        if (GDU_IP_STATUS_OK == Gdu_Ip_OffStateDiagnostics(OffStateDiagnostics))
        {
            Status = E_OK;
        }
        else
        {
            Status = E_NOT_OK;
        }
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_OFFSTATEDIAG, GDU_DET_ERROR_UNINITIALIZED);
        Status = GDU_RET_DET_UNINIT;
    }

    return Status;
}

#if (GDU_VERSION_INFO_API == STD_ON)
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Get the module's version information.
*
* @param[out]   VersionInfo pointer to a structure containing version information
*
* @return       the status of the command.
* @retval       E_OK command processed successfully
* @retval       GDU_RET_DET_PARAM one of the provided arguments is invalid: error reported to Det
*
* @api
* @pre          No preconditions are necessary.
* @implements   Gdu_GetVersionInfo_Activity
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Gdu_GetVersionInfo (Std_VersionInfoType * VersionInfo)
{
    Std_ReturnType Status = E_OK;

    if (GDU_DEV_ASSERT(VersionInfo != NULL_PTR))
    {
        VersionInfo->moduleID = GDU_MODULE_ID;
        VersionInfo->vendorID = GDU_VENDOR_ID;
        VersionInfo->sw_major_version = GDU_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = GDU_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = GDU_SW_PATCH_VERSION;
    }
    else
    {
        Gdu_ReportDetError(GDU_DET_SERVICE_GETVERSIONINFO, GDU_DET_ERROR_PARAMETER);
        Status = GDU_RET_DET_PARAM;
    }

    return Status;
}
#endif

#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
