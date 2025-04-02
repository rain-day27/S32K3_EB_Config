/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : MEM_OTP_IP
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
*   @addtogroup MEM_OTP_IP
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
#include "Mem_Otp_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_OTP_IP_VENDOR_ID_C                    43
#define MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define MEM_OTP_IP_AR_RELEASE_MINOR_VERSION_C     7
#define MEM_OTP_IP_AR_RELEASE_REVISION_VERSION_C  0
#define MEM_OTP_IP_SW_MAJOR_VERSION_C             5
#define MEM_OTP_IP_SW_MINOR_VERSION_C             0
#define MEM_OTP_IP_SW_PATCH_VERSION_C             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_Otp_Ip header file are of the same vendor */
#if (MEM_OTP_IP_VENDOR_ID != MEM_OTP_IP_VENDOR_ID_C)
    #error "Mem_Otp_Ip.c and Mem_Otp_Ip.h have different vendor ids"
#endif
/* Check if current file and Mem_Otp_Ip header file are of the same Autosar version */
#if ((MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION    != MEM_OTP_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (MEM_OTP_IP_AR_RELEASE_MINOR_VERSION    != MEM_OTP_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (MEM_OTP_IP_AR_RELEASE_REVISION_VERSION != MEM_OTP_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Mem_Otp_Ip.c and Mem_Otp_Ip.h are different"
#endif
/* Check if current file and Mem_Otp_Ip header file are of the same Software version */
#if ((MEM_OTP_IP_SW_MAJOR_VERSION != MEM_OTP_IP_SW_MAJOR_VERSION_C) || \
     (MEM_OTP_IP_SW_MINOR_VERSION != MEM_OTP_IP_SW_MINOR_VERSION_C) || \
     (MEM_OTP_IP_SW_PATCH_VERSION != MEM_OTP_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of Mem_Otp_Ip.c and Mem_Otp_Ip.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define OCOTP_START_SEC_VAR_INIT_UNSPECIFIED
#include "Ocotp_MemMap.h"

static const Mem_Otp_Ip_ConfigType *Mem_Otp_Ip_pOcotpStateCfg[MEM_OTP_AE_INSTANCE_COUNT] = {NULL_PTR};

#define OCOTP_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Ocotp_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

static Mem_Otp_Ip_StatusType Mem_Otp_Ip_GetBusyFlag(uint32 instance);
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_GetErrorFlag(uint32 instance);

#if (MEM_OTP_IP_READ_OTP_MEM_API == STD_ON)
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_WaitDeviceReady(uint32 instance,
                                                        uint32 timeout
                                                       );
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_EnterRobinMode(void);
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_ExitRobinMode(void);
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_CfgSetParameters(void);
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_ReadOTP(uint32 instance,
                                                uint32 address,
                                                uint32 *data
                                               );
#endif

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
 * @brief        The function checks busy status of Mem_Otp_Ip.
 * @details      The function checks busy status of Mem_Otp_Ip.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       boolean
 * @retval       STATUS_MEM_OTP_IP_BUSY if hardware is busy.
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if hardware is NOT busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_GetBusyFlag(uint32 instance)
{
    uint32 regVal = 0U;
    uint8 AecStatus;
    Mem_Otp_Ip_StatusType eReturnCode = STATUS_MEM_OTP_IP_ERROR;

    DEV_ASSERT_OCOTP(instance < MEM_OTP_AE_INSTANCE_COUNT);

    AecStatus = (uint8)Aec_Ip_SpiRead((uint32)(MEM_OTP_AE_ERROR), MEM_OTP_IP_DATAWIDTH_16, &regVal);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_07);
    if ((uint8)AEC_STATUS_SUCCESS == AecStatus)
    {
        MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_01);
        if ((regVal & MEM_OTP_AE_ERROR_CTRLBUSY_MASK) != 0U)
        {
            eReturnCode = STATUS_MEM_OTP_IP_BUSY;
        }
        else
        {
            eReturnCode = STATUS_MEM_OTP_IP_SUCCESS;
        }
    }
    return eReturnCode;
}

/**
 * @brief        The function checks error status of Mem_Otp_Ip.
 * @details      The function checks error status of Mem_Otp_Ip.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_ERROR if hardware is error.
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if hardware is NOT error.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_GetErrorFlag(uint32 instance)
{
    uint32 regVal = 0U;
    uint8 AecStatus;
    Mem_Otp_Ip_StatusType eReturnCode = STATUS_MEM_OTP_IP_ERROR;

    DEV_ASSERT_OCOTP(instance < MEM_OTP_AE_INSTANCE_COUNT);

    AecStatus = (uint8)Aec_Ip_SpiRead((uint32)(MEM_OTP_AE_ERROR), MEM_OTP_IP_DATAWIDTH_16, &regVal);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_09);
    if ((uint8)AEC_STATUS_SUCCESS == AecStatus)
    {
        MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_02);
        if ((regVal & OTPC_ERR_FLAGS_MASK) != 0U)
        {
            eReturnCode = STATUS_MEM_OTP_IP_ERROR;
        }
        else
        {
            eReturnCode = STATUS_MEM_OTP_IP_SUCCESS;
        }
    }
    return eReturnCode;
}

#if (MEM_OTP_IP_READ_OTP_MEM_API == STD_ON)
/**
 * @brief        The function waits Ocotp is ready.
 * @details      The function checks error and busy status of Ocotp.
 *               If the status is different busy, this function will return.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if no errors occurred and hardware is not busy.
 * @retval       STATUS_MEM_OTP_IP_ERROR if error flag is set.
 * @retval       STATUS_MEM_OTP_IP_ERROR_TIMEOUT timeout supervision is enbaled and timeout occurred.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 */
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_WaitDeviceReady(uint32 instance,
                                                        uint32 timeout
                                                       )
{
    uint32 u32ElapsedTicks = 0U;
    uint32 u32TimeoutTicks;
    uint32 u32CurrentTicks;
    volatile Mem_Otp_Ip_StatusType eReturnVal;

    eReturnVal = Mem_Otp_Ip_GetBusyFlag(instance);
    u32TimeoutTicks = OsIf_MicrosToTicks(timeout, (OsIf_CounterType)MEM_OTP_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)MEM_OTP_IP_TIMEOUT_TYPE);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_03);
    while ((STATUS_MEM_OTP_IP_BUSY == eReturnVal) && (u32ElapsedTicks < u32TimeoutTicks))
    {
        eReturnVal = Mem_Otp_Ip_GetBusyFlag(instance);
        MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_08);
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)MEM_OTP_IP_TIMEOUT_TYPE);
    }
    if (u32ElapsedTicks >= u32TimeoutTicks)
    {
        eReturnVal = STATUS_MEM_OTP_IP_ERROR_TIMEOUT;
    }
    return eReturnVal;
}

/**
 * @brief        The function enter Robin mode to activate low level access to OTP.
 * @details      The function enter Robin mode to activate low level access to OTP.
 *
 * @param[in]    (void)
 *
 * @return       void
 *
 * @pre          NA
 *
 */
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_EnterRobinMode(void)
{
    Mem_Otp_Ip_StatusType eReturnVal = STATUS_MEM_OTP_IP_ERROR;
    uint8 AecStatus = 0U;
    uint32 ValRstgenCfg = 0U;

    AecStatus |= (uint8)Aec_Ip_SpiRead(AEC_RSTGEN_CFG, MEM_OTP_IP_DATAWIDTH_16, &ValRstgenCfg);
    AecStatus |= (uint8)Aec_Ip_SpiWrite(AEC_RSTGEN_CFG, MEM_OTP_IP_DATAWIDTH_16, (ValRstgenCfg | AEC_RSTGEN_CFG_ACTIVATE_REGS_OTP));
    AecStatus |= (uint8)Aec_Ip_SpiWrite(AEC_MODE_CONTROL, MEM_OTP_IP_DATAWIDTH_16, AEC_MODE_CONTROL_SECRET_0);
    AecStatus |= (uint8)Aec_Ip_SpiWrite(AEC_MODE_CONTROL, MEM_OTP_IP_DATAWIDTH_16, AEC_MODE_CONTROL_SECRET_1);

    if ((uint8)AEC_STATUS_SUCCESS == AecStatus)
    {
        eReturnVal = STATUS_MEM_OTP_IP_SUCCESS;
    }
    return eReturnVal;
}
/**
 * @brief        The function exit Robin mode.
 * @details      The function exit Robin mode.
 *
 * @param[in]    (void)
 *
 * @return       void
 *
 * @pre          NA
 *
 */
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_ExitRobinMode(void)
{
    Mem_Otp_Ip_StatusType eReturnVal = STATUS_MEM_OTP_IP_ERROR;
    uint8 AecStatus;

    AecStatus = (uint8)Aec_Ip_SpiWrite(AEC_MODE_CONTROL, MEM_OTP_IP_DATAWIDTH_16, AEC_MODE_CONTROL_DISABLE_TEST_MODE);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_06);
    if ((uint8)AEC_STATUS_SUCCESS == AecStatus)
    {
        eReturnVal = STATUS_MEM_OTP_IP_SUCCESS;
    }
    return eReturnVal;
}

/**
 * @brief        The function config parameters to read OTP memory
 * @details      The function config parameters such as VRR Regulator Level, Read Pulse to read OTP memory
 *
 * @param[in]    (void)
 *
 * @return       void
 *
 * @pre          NA
 *
 */
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_CfgSetParameters(void)
{
    Mem_Otp_Ip_StatusType eReturnVal = STATUS_MEM_OTP_IP_ERROR;
    uint8 AecStatus = 0U;

    /* Specify MF is not to be used during test mode */
    AecStatus |= (uint8)Aec_Ip_SpiWrite(MEM_OTP_AE_MR_TST, MEM_OTP_IP_DATAWIDTH_16, MEM_OTP_IP_NO_MR_DURING_TEST);
    /* Specify MREF is not to be used during test mode */
    AecStatus |= (uint8)Aec_Ip_SpiWrite(MEM_OTP_AE_MREF_TST, MEM_OTP_IP_DATAWIDTH_16, MEM_OTP_IP_NO_MREF_DURING_TEST);
    /* Specify the VRR regulator level */
    AecStatus |= (uint8)Aec_Ip_SpiWrite(MEM_OTP_AE_ADVCFG0, MEM_OTP_IP_DATAWIDTH_16, MEM_OTP_IP_SELECT_VRR_FOR_VDR);
    /* Selects the length of the read pulse duration is 3000ns */
    AecStatus |= (uint8)Aec_Ip_SpiWrite(MEM_OTP_AE_ADVCFG3, MEM_OTP_IP_DATAWIDTH_16, MEM_OTP_IP_READ_PULSE_3000NS);
    MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_12);
    if ((uint8)AEC_STATUS_SUCCESS == AecStatus)
    {
        eReturnVal = STATUS_MEM_OTP_IP_SUCCESS;
    }
    return eReturnVal;
}

/**
 * @brief        The function read OTP memory
 * @details      The function read OTP memory
 *
 * @param[in]    (void)
 *
 * @return       void
 *
 * @pre          NA
 *
 */
static Mem_Otp_Ip_StatusType Mem_Otp_Ip_ReadOTP(uint32 instance,
                                                uint32 address,
                                                uint32 *data)
{
    Mem_Otp_Ip_StatusType eReturnCode = STATUS_MEM_OTP_IP_ERROR;
    uint32 dataRead = 0U;
    uint32 EccErrorStatus = 0U;
    uint8 AecStatus = 0U;

    AecStatus |= (uint8)Aec_Ip_SpiWrite((uint32)(MEM_OTP_AE_STRT_STP), MEM_OTP_IP_DATAWIDTH_16, address);    /*Specify the OTP memory address to be read  */
    AecStatus |= (uint8)Aec_Ip_SpiWrite((uint32)(MEM_OTP_AE_CTRL_CMD), MEM_OTP_IP_DATAWIDTH_16, OTPC_C_RD_ONE);    /* Execute the C_RD_ONE command */
    if ((uint8)AEC_STATUS_SUCCESS == AecStatus)
    {
        /* Wait for the OTPC to complete execution of the command */
        eReturnCode = Mem_Otp_Ip_WaitDeviceReady(instance, MEM_OTP_IP_READ_TIMEOUT_VALUE);
        if (STATUS_MEM_OTP_IP_SUCCESS == eReturnCode)
        {
            AecStatus |= (uint8)Aec_Ip_SpiRead((uint32)(MEM_OTP_AE_DATAOUT), MEM_OTP_IP_DATAWIDTH_16, &dataRead); /* Read the returned data */
            AecStatus |= (uint8)Aec_Ip_SpiRead((uint32)(MEM_OTP_AE_ERROR), MEM_OTP_IP_DATAWIDTH_16, &EccErrorStatus);   /* Read the returned mirror data */
            MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_05);
            if ((uint8)AEC_STATUS_SUCCESS == AecStatus)
            {
                *data = (dataRead & MEM_OTP_AE_DATAOUT_OUTPUT_MASK) >> MEM_OTP_AE_DATAOUT_OUTPUT_SHIFT;
                MCAL_FAULT_INJECTION_POINT(OCOTP_INJ_13);
                if ((EccErrorStatus & OTPC_ERR_ECC_MASK) != 0U)
                {
                    eReturnCode = STATUS_MEM_OTP_IP_ERROR;
                }
            }
            else
            {
                eReturnCode = STATUS_MEM_OTP_IP_ERROR;
            }
        }
    }
    return eReturnCode;
}
#endif

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
 * @brief        The function initializes Mem_Otp_Ip module.
 * @details      The function clear all errors flag and initializes Mem_Otp_Ip module.
 *
 * @param[in]    pConfig       pointer points to configuration structure.
 *
 * @api
 *
 * @pre          Module has not been initialized.
 *
 * @implements   Mem_Otp_Ip_Init_Activity
 *
 */
void Mem_Otp_Ip_Init(const Mem_Otp_Ip_ConfigType *pConfig)
{
    uint8 instance = pConfig->ocotpInstance;

    DEV_ASSERT_OCOTP(Mem_Otp_Ip_pOcotpStateCfg[instance] == NULL_PTR);
    Mem_Otp_Ip_pOcotpStateCfg[instance] = pConfig;

    return;
}

/**
 * @brief        The function de-initializes Ocotp module.
 * @details      The function de-initializes Ocotp module.
 *
 * @param[in]    instance       hardware instance.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 * @implements   Mem_Otp_Ip_DeInit_Activity
 *
 */
void Mem_Otp_Ip_DeInit (uint32 instance)
{
    DEV_ASSERT_OCOTP(instance < MEM_OTP_AE_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Mem_Otp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    Mem_Otp_Ip_pOcotpStateCfg[instance] = NULL_PTR;
    return;
}


#if (MEM_OTP_IP_READ_OTP_MEM_API == STD_ON)
/**
 * @brief        The function reads a single byte of data from OTP memory.
 * @details      The function reads a single byte of data from OTP memory.
 *
 * @param[in]    instance       hardware instance.
 * @param[in]    address        address of OTP memory.
 * @param[out]    data           pointer points to data result.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if read operation is successful.
 * @retval       STATUS_MEM_OTP_IP_ERROR if error flag is set.
 * @retval       STATUS_MEM_OTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 * @implements   Mem_Otp_Ip_ReadOTPMem_Activity
 *
 */
Mem_Otp_Ip_StatusType Mem_Otp_Ip_ReadOTPMem(uint32 instance,
                                            uint32 address,
                                            uint32 *data
                                           )
{
    Mem_Otp_Ip_StatusType eReturnCode = STATUS_MEM_OTP_IP_ERROR;
    Mem_Otp_Ip_StatusType eRobinStatus = STATUS_MEM_OTP_IP_ERROR;

    /* Check instance validity */
    DEV_ASSERT_OCOTP(instance < MEM_OTP_AE_INSTANCE_COUNT);
    /* Enter Robin mode to activate low level access to OTP */
    if (STATUS_MEM_OTP_IP_SUCCESS == Mem_Otp_Ip_EnterRobinMode())
    {
        /* Check OTPC is idle */
        if (STATUS_MEM_OTP_IP_SUCCESS == Mem_Otp_Ip_GetBusyFlag(instance))
        {
            /* Config parameters to read OTP memory */
            if (STATUS_MEM_OTP_IP_SUCCESS == Mem_Otp_Ip_CfgSetParameters())
            {
                eReturnCode = Mem_Otp_Ip_ReadOTP(instance, address, data);
            }
        }
        /* Exit Robin mode */
        eRobinStatus = Mem_Otp_Ip_ExitRobinMode();
        if ((STATUS_MEM_OTP_IP_ERROR == eRobinStatus) && (STATUS_MEM_OTP_IP_SUCCESS == eReturnCode))
        {
            eReturnCode = STATUS_MEM_OTP_IP_ERROR;
        }
    }
    return eReturnCode;
}
#endif /* MEM_OTP_IP_READ_EFUSE_API == STD_ON */

/**
 * @brief        The function checks busy and error state of hardware.
 * @details      The function checks busy and error state of hardware.
 *
 * @param[in]    instance       hardware instance.
 *
 * @return       Mem_Otp_Ip_StatusType
 * @retval       STATUS_MEM_OTP_IP_SUCCESS if hardware is ready.
 * @retval       STATUS_MEM_OTP_IP_ERROR if error flag is set.
 * @retval       STATUS_MEM_OTP_IP_BUSY hardware is busy.
 *
 * @api
 *
 * @pre          Module has been initialized.
 *
 * @implements   Mem_Otp_Ip_GetBusyState_Activity
 *
 */
Mem_Otp_Ip_StatusType Mem_Otp_Ip_GetBusyState(uint32 instance)
{
    DEV_ASSERT_OCOTP(instance < MEM_OTP_AE_INSTANCE_COUNT);
    DEV_ASSERT_OCOTP(Mem_Otp_Ip_pOcotpStateCfg[instance] != NULL_PTR);

    Mem_Otp_Ip_StatusType eRetVal;

    eRetVal = Mem_Otp_Ip_GetBusyFlag(instance);
    if (STATUS_MEM_OTP_IP_SUCCESS == eRetVal)
    {
       eRetVal = Mem_Otp_Ip_GetErrorFlag(instance);
    }
    return eRetVal;
}

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
