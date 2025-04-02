/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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
*   @addtogroup flexio_i2s_ip FLEXIO_I2S IPL
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Flexio_I2s_Ip.h"
#include "Flexio_I2s_Ip_HwAccess.h"
#include "OsIf.h"
#include "Devassert.h"
#if (STD_ON == FLEXIO_I2S_IP_ENABLE)
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    #include "Dma_Ip.h"
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
#endif /* (STD_ON == FLEXIO_I2S_IP_ENABLE) */


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2S_IP_VENDOR_ID_C                      43
#define FLEXIO_I2S_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_I2S_IP_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_I2S_IP_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_I2S_IP_SW_MAJOR_VERSION_C               5
#define FLEXIO_I2S_IP_SW_MINOR_VERSION_C               0
#define FLEXIO_I2S_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (STD_ON == FLEXIO_I2S_IP_ENABLE)

#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
/* Size of 32 bit register in byte */
#define SIZE_OF_32BIT_REG         (4U)
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */

/* Number of empty frames to be transmitted in order to keep the line open to transmit the last frames after SHIFTBUF was emptied.*/
#define FLEXIO_I2S_IP_LASTFRAME_COUNT   (2U)

/* Shifters/Timers used for I2S simulation The parameter x represents the
   ResourceIndex value for the current driver Instance */
#define SCK_TIMER(x)              (x)
#define WS_TIMER(x)               (uint8)((x) + 1U)
#define WS_TIMER_RISING_BLK(x)    (uint8)((x) + 2U)

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define I2S_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2s_MemMap.h"

#if (FLEXIO_I2S_IP_NUMBER_OF_CHANNEL != 0U)
Flexio_I2s_Ip_StateType Flexio_I2s_Ip_MasterSlaveState[FLEXIO_I2S_IP_NUMBER_OF_CHANNEL];
#endif

/* Pointer to runtime Master/Slave state structures.*/
Flexio_I2s_Ip_StateType *Flexio_I2s_Ip_pxState[FLEXIO_I2S_IP_INSTANCE_COUNT][FLEXIO_I2S_IP_NUMBER_OF_CHANNEL];

#define I2S_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "I2s_MemMap.h"

#define I2S_START_SEC_CONST_UNSPECIFIED
#include "I2s_MemMap.h"
static FLEXIO_Type * const Flexio_I2s_Ip_pBaseAddr[FLEXIO_I2S_IP_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;

#define I2S_STOP_SEC_CONST_UNSPECIFIED
#include "I2s_MemMap.h"

#define I2S_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "I2s_MemMap.h"
/* I2s channel init status*/
static uint8 Flexio_I2s_Ip_ChannelStatus[FLEXIO_I2S_IP_MAX_CHANNEL_COUNT];
static uint8 Flexio_I2s_Ip_ChannelMapping[FLEXIO_I2S_IP_MAX_CHANNEL_COUNT];

#define I2S_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "I2s_MemMap.h"


#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Flexio_I2s_Ip_MasterCheckRxStatus(Flexio_I2s_Ip_StateType *Master,
                                              const FLEXIO_Type *baseAddr);

static void Flexio_I2s_Ip_MasterCheckTxStatus(Flexio_I2s_Ip_StateType *Master,
                                              const FLEXIO_Type *baseAddr);

static void Flexio_I2s_Ip_MasterCheckTransferFinished(Flexio_I2s_Ip_StateType *Master);

static Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_WaitTimeout(const Flexio_I2s_Ip_StateType *pState,
                                                          uint32 u32Timeout);

static void Flexio_I2s_Ip_MasterConfigure(const Flexio_I2s_Ip_StateType *Master,
                                          const Flexio_I2s_Ip_MasterConfigType *ConfigPtr);

static void Flexio_I2s_Ip_SlaveConfigure(const Flexio_I2s_Ip_StateType *Slave,
                                         const Flexio_I2s_Ip_SlaveConfigType *ConfigPtr);

static void Flexio_I2s_Ip_MasterEndTransfer(Flexio_I2s_Ip_StateType *Master);

static void Flexio_I2s_Ip_MasterEnableTransfer(const Flexio_I2s_Ip_StateType *Master);

static void Flexio_I2s_Ip_MasterStopTransfer(Flexio_I2s_Ip_StateType *Master);

static Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterWaitTransferEnd(uint8 Instance,
                                                                    uint8 Channel,
                                                                    uint32 Timeout);

static void Flexio_I2s_Ip_ReadData(Flexio_I2s_Ip_StateType *Master);

static void Flexio_I2s_Ip_WriteData(Flexio_I2s_Ip_StateType *Master);

static void Flexio_I2s_Ip_MasterCheckStatus(uint8 Instance,
                                            uint8 Channel);

#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
static void Flexio_I2s_Ip_MasterEndDmaTxTransfer(uint8 Instance,
                                                 const uint8 FlexIOChannel);

static void Flexio_I2s_Ip_MasterEndDmaRxTransfer(uint8 Instance,
                                                 const uint8 FlexIOChannel);

#endif

static void Flexio_I2s_Ip_ResourcesInit(uint8 Instance,
                                        const Flexio_I2s_Ip_CommonStateType *Driver);

static void Flexio_I2s_Ip_InitDriver(uint8 Instance,
                                     uint8 Channel,
                                     const Flexio_I2s_Ip_CommonStateType *Driver);

static void Flexio_I2s_Ip_DeinitDriver(const Flexio_I2s_Ip_CommonStateType *Driver);

static void Flexio_I2s_Ip_ResetStatusStruct(uint8 Instance,
                                            uint8 Channel);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_WaitTimeout(const Flexio_I2s_Ip_StateType *pState,
                                                          uint32 u32Timeout)
{
    Flexio_I2s_Ip_StatusType eRet = FLEXIO_I2S_IP_STATUS_SUCCESS;

    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(u32Timeout, FLEXIO_I2S_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(FLEXIO_I2S_IP_TIMEOUT_TYPE);
    uint32 u32ElapsedTicks = 0U;

    while ((FLEXIO_I2S_IP_STATUS_BUSY == pState->status) && (u32ElapsedTicks < u32TimeoutTicks))
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, FLEXIO_I2S_IP_TIMEOUT_TYPE);
    }

    if (u32ElapsedTicks >= u32TimeoutTicks)
    {
        eRet = FLEXIO_I2S_IP_STATUS_TIMEOUT;
    }

    return eRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterConfigure
 * Description   : configures the FLEXIO module as I2S Master
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterConfigure(const Flexio_I2s_Ip_StateType *Master,
                                          const Flexio_I2s_Ip_MasterConfigType *ConfigPtr)
{
    FLEXIO_Type *baseAddr;
    uint16 divider;
    uint16 bits;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_TimerConfig TempTimerConfig;
    Flexio_I2s_Ip_TimerControl TempTimerControl;
    Flexio_I2s_Ip_ShifterControl ShifterControl;

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    /* Convert bytes to bits */
    bits = (uint16)(8U * ((uint16)ConfigPtr->byteWidth));
    divider = ConfigPtr->DividerValue;

#if (STD_ON == FLEXIO_I2S_IP_TX_ENABLED)
    if (TRUE == Master->FlexioCommon.TxEnabled)
    {
        /* Configure tx shifter */
        Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                       Master->FlexioCommon.TxShifter,
                                       FLEXIO_SHIFTER_START_BIT_DISABLED_SH,
                                       FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                       FLEXIO_SHIFTER_SOURCE_PIN);

        ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
        ShifterControl.Pin = (uint8)(ConfigPtr->txPin - (uint8)1U);
        ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
        ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
        ShifterControl.Timer = SCK_TIMER(ResourceIndex);
        ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_POSEDGE;
        Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                        Master->FlexioCommon.TxShifter,
                                        &ShifterControl);
    }
#endif/*(STD_ON == FLEXIO_I2S_IP_TX_ENABLED)*/

#if (STD_ON == FLEXIO_I2S_IP_RX_ENABLED)
    if (TRUE == Master->FlexioCommon.RxEnabled)
    {
        /* TX pin not configured -> Configure RX on first Shifter */
        Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                       Master->FlexioCommon.RxShifter,
                                       FLEXIO_SHIFTER_START_BIT_DISABLED,
                                       FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                       FLEXIO_SHIFTER_SOURCE_PIN);

        ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
        ShifterControl.Pin = (uint8)(ConfigPtr->rxPin - (uint8)1U);
        ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
        ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
        ShifterControl.Timer = SCK_TIMER(ResourceIndex);
        ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_NEGEDGE;

        Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                        Master->FlexioCommon.RxShifter,
                                        &ShifterControl);
    }
    #endif/*(STD_ON == FLEXIO_I2S_IP_RX_ENABLED)*/

    /* Configure SCK timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, SCK_TIMER(ResourceIndex), (uint16)((uint16)(((uint16)(bits << 1U) - 1U) << 8U) + divider));

    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_ENABLED;
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_TRG_HIGH;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_NEVER;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_CLK_SHIFT_TMR;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;

    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                                 SCK_TIMER(ResourceIndex),
                                 &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(SCK_TIMER(ResourceIndex) << 2U) + 1U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_LOW;
    TempTimerControl.TriggerSource = FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->sckPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_OUTPUT;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;

    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  SCK_TIMER(ResourceIndex),
                                  &TempTimerControl);

    /* Configure WS timer */

    Flexio_I2s_Ip_SetTimerCompare(baseAddr, WS_TIMER(ResourceIndex), (uint16)((bits * ((divider + 1U) * 2U)) - 1U));

    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_TIM_ENABLE;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_NEVER;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_CLK_SHIFT_TMR;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;

    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                                 WS_TIMER(ResourceIndex),
                                 &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)0U; /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_HIGH;
    TempTimerControl.TriggerSource = FLEXIO_TRIGGER_SOURCE_EXTERNAL;
    TempTimerControl.Pin = ConfigPtr->wsPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_OUTPUT;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;

    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  WS_TIMER(ResourceIndex),
                                  &TempTimerControl);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_SlaveConfigure
 * Description   : configures the FLEXIO module as I2S Slave
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_SlaveConfigure(const Flexio_I2s_Ip_StateType *Slave,
                                         const Flexio_I2s_Ip_SlaveConfigType *ConfigPtr)
{
    FLEXIO_Type *baseAddr;
    uint16 bits;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_TimerConfig TempTimerConfig;
    Flexio_I2s_Ip_TimerControl TempTimerControl;
    Flexio_I2s_Ip_ShifterControl ShifterControl;

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Slave->FlexioCommon.Instance];
    ResourceIndex = Slave->FlexioCommon.ResourceIndex;
    /* Convert bytes to bits */
    bits = (uint16)(8U * ((uint16)ConfigPtr->byteWidth));

#if (STD_ON == FLEXIO_I2S_IP_TX_ENABLED)
    if (TRUE == Slave->FlexioCommon.TxEnabled)
    {
        Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                       Slave->FlexioCommon.TxShifter,
                                       FLEXIO_SHIFTER_START_BIT_DISABLED,
                                       FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                       FLEXIO_SHIFTER_SOURCE_PIN);

        ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
        ShifterControl.Pin = (uint8)(ConfigPtr->txPin - (uint8)1U);
        ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
        ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
        ShifterControl.Timer = WS_TIMER(ResourceIndex);
        ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_POSEDGE;

        Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                        Slave->FlexioCommon.TxShifter,
                                        &ShifterControl);
    }
#endif/*(STD_ON == FLEXIO_I2S_IP_TX_ENABLED)*/

#if (STD_ON == FLEXIO_I2S_IP_RX_ENABLED)
    if (TRUE == Slave->FlexioCommon.RxEnabled)
    {
        Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                       Slave->FlexioCommon.RxShifter,
                                       FLEXIO_SHIFTER_START_BIT_DISABLED,
                                       FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                       FLEXIO_SHIFTER_SOURCE_PIN);

        ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
        ShifterControl.Pin = (uint8)(ConfigPtr->rxPin - (uint8)1U);
        ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
        ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
        ShifterControl.Timer = WS_TIMER(ResourceIndex);
        ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_NEGEDGE;

        Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                        Slave->FlexioCommon.RxShifter,
                                        &ShifterControl);
    }
#endif/*(STD_ON == FLEXIO_I2S_IP_RX_ENABLED)*/

    /* Configure SCK timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, SCK_TIMER(ResourceIndex), (uint16)((uint16)(bits << 2U) - 3U));

    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_PIN_POSEDGE;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TIM_CMP;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_TRG_SHIFT_TRG;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;

    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                                 SCK_TIMER(ResourceIndex),
                                 &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)(ConfigPtr->sckPin << 1U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_LOW;
    TempTimerControl.TriggerSource = FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->wsPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;

    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  SCK_TIMER(ResourceIndex),
                                  &TempTimerControl);

    /* Configure WS_TIMER_RISING_BLK timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, WS_TIMER_RISING_BLK(ResourceIndex), (uint16)((uint16)(bits << 2U) - 4U));

    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_PIN_POSEDGE_TRG_HIGH;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TRG;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_PIN_SHIFT_PIN;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;

    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                                 WS_TIMER_RISING_BLK(ResourceIndex),
                                 &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(SCK_TIMER(ResourceIndex) << 2U) + 3U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_HIGH;
    TempTimerControl.TriggerSource = FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->sckPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;

    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  WS_TIMER_RISING_BLK(ResourceIndex),
                                  &TempTimerControl);

    /* Configure WS timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, WS_TIMER(ResourceIndex), (uint16)((uint16)(bits << 1U) - 1U));

    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_PIN_POSEDGE_TRG_HIGH;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TIM_CMP_TRG_LOW;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_PIN_SHIFT_PIN;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;

    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                                 WS_TIMER(ResourceIndex),
                                 &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(WS_TIMER_RISING_BLK(ResourceIndex) << 2U) + 3U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_HIGH;
    TempTimerControl.TriggerSource = FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->sckPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;

    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  WS_TIMER(ResourceIndex),
                                  &TempTimerControl);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEndTransfer
 * Description   : End the current transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEndTransfer(Flexio_I2s_Ip_StateType *Master)
{
    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    uint8 ShifterMask;      /* Mask to be used for Shifter configuration */

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    if ((TRUE == Master->FlexioCommon.RxEnabled) && (TRUE == Master->FlexioCommon.TxEnabled))
    {
        ShifterMask = (1U << Master->FlexioCommon.TxShifter) | (1U << Master->FlexioCommon.RxShifter);
    }
    else
    {
        ShifterMask = (1U << ResourceIndex);
    }

    /* Disable transfer engine */
    switch (Master->driverType)
    {
        case FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT:
            /* Both Tx and Rx enabled: Disable interrupts for Rx and Tx shifters */
            Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr,
                                              (uint8)(ShifterMask),
                                              FALSE);
            Flexio_Mcl_Ip_SetShifterErrorInterrupt(baseAddr,
                                                   (uint8)(ShifterMask),
                                                   FALSE);
        break;
        case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
            /* Nothing to do here */
        break;
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
        case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
            /* Stop DMA channels */
            Flexio_Mcl_Ip_SetShifterDMARequest(baseAddr, (uint8)(ShifterMask), FALSE);
        break;
#endif
        default:
            /* Impossible type - do nothing */
        break;
    }

    /* Clear the tx/rx buffer pointers. */
    Master->txData = NULL_PTR;
    Master->rxData = NULL_PTR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEnableTransfer
 * Description   : Enables timers and shifters to start a transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEnableTransfer(const Flexio_I2s_Ip_StateType *Master)
{
    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* Enable timers and shifters */
    if (TRUE == Master->FlexioCommon.TxEnabled)
    {
        /* Configure Tx */
        Flexio_I2s_Ip_SetShifterMode(baseAddr, Master->FlexioCommon.TxShifter, FLEXIO_SHIFTER_MODE_TRANSMIT);
    }

    if (TRUE == Master->FlexioCommon.RxEnabled)
    {
        /* Configure Rx */
        Flexio_I2s_Ip_SetShifterMode(baseAddr, Master->FlexioCommon.RxShifter, FLEXIO_SHIFTER_MODE_RECEIVE);
    }

    if (TRUE == Master->Master)
    {
        Flexio_I2s_Ip_SetTimerMode(baseAddr, SCK_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_8BIT_BAUD);
    }
    else
    {
        Flexio_I2s_Ip_SetTimerMode(baseAddr, SCK_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_16BIT);
        Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER_RISING_BLK(ResourceIndex), FLEXIO_TIMER_MODE_16BIT);
    }

    Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_16BIT);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterStopTransfer
 * Description   : Stops the current transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterStopTransfer(Flexio_I2s_Ip_StateType *Master)
{
    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* Disable timers and shifters */
    if (TRUE == Master->FlexioCommon.TxEnabled)
    {
        Flexio_I2s_Ip_SetShifterMode(baseAddr, Master->FlexioCommon.TxShifter, FLEXIO_SHIFTER_MODE_DISABLED);
        /* Disable pin output */
        Flexio_I2s_Ip_SetShifterPinConfig(baseAddr, Master->FlexioCommon.TxShifter, FLEXIO_PIN_CONFIG_DISABLED);
        /* Clear any leftover error flags */
        Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, Master->FlexioCommon.TxShifter);
    }

    if (TRUE == Master->FlexioCommon.RxEnabled)
    {
        Flexio_I2s_Ip_SetShifterMode(baseAddr, Master->FlexioCommon.RxShifter, FLEXIO_SHIFTER_MODE_DISABLED);
        /* Clear any leftover error flags */
        Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, Master->FlexioCommon.RxShifter);
        /* Discard any leftover Rx. data */
        Flexio_Mcl_Ip_ClearShifterStatus(baseAddr, Master->FlexioCommon.RxShifter);
    }

    Flexio_I2s_Ip_SetTimerMode(baseAddr, SCK_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_DISABLED);
    if (!Master->Master)
    {
        Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER_RISING_BLK(ResourceIndex), FLEXIO_TIMER_MODE_DISABLED);
    }

    Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_DISABLED);
    /* End the transfer */
    Flexio_I2s_Ip_MasterEndTransfer(Master);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterWaitTransferEnd
 * Description   : waits for the end of a blocking transfer
 *
 *END**************************************************************************/
static Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterWaitTransferEnd(uint8 Instance,
                                                                    uint8 Channel,
                                                                    uint32 Timeout)
{
    Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];

    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, FLEXIO_I2S_IP_TIMEOUT_TYPE);

    CurrentTicks = OsIf_GetCounter(FLEXIO_I2S_IP_TIMEOUT_TYPE);
    /* Call Flexio_I2s_Ip_GetStatus() to do the transfer */
    do
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, FLEXIO_I2S_IP_TIMEOUT_TYPE);
    } while ((Flexio_I2s_Ip_GetStatus(Instance, Channel, NULL_PTR) == FLEXIO_I2S_IP_STATUS_BUSY) && (ElapsedTicks < TimeoutTicks));

    if (ElapsedTicks >= TimeoutTicks)
    {
        /* abort current transfer */
        Flexio->status = FLEXIO_I2S_IP_STATUS_TIMEOUT;
        Flexio_I2s_Ip_MasterStopTransfer(Flexio);
    }

    /* blocking transfer is over */
    Flexio->blocking = FALSE;

    return Flexio->status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ReadData
 * Description   : reads data received by the module
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_ReadData(Flexio_I2s_Ip_StateType *Master)
{
    const FLEXIO_Type *baseAddr;
    uint32 data;
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* Read data from shifter buffer */
    data = Flexio_I2s_Ip_ReadShifterBuffer(baseAddr, Master->FlexioCommon.RxShifter, FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);

    if (Master->rxRemainingWords > 0U)
    {
        if (Master->rxData != NULL_PTR)
        {
            switch (Master->byteWidth)
            {
                case 1U:
                    *(uint8 *)Master->rxData = (uint8)data;
                break;
                case 2U:
                    *(uint16 *)Master->rxData = (uint16)data;
                break;
                default:
                    *(uint32 *)Master->rxData = (uint32)data;
                break;
            }

            /* Update rx buffer pointer */
            Master->rxData = &Master->rxData[Master->byteWidth];
        }

        /* Update remaining bytes count even if buffer is null */
        Master->rxRemainingWords -= 1U;
    }
    else
    {
        /* No data to receive, just ignore the read data */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_WriteData
 * Description   : writes data to be transmitted by the module
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_WriteData(Flexio_I2s_Ip_StateType *Master)
{
    FLEXIO_Type *baseAddr;
    uint32 data;
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* If having more data to be transferred */
    if (Master->txRemainingWords != 0U)
    {
        /* Read data from user buffer and update tx buffer pointer and remaining bytes count */
        switch (Master->byteWidth)
        {
            case 1U:
                data = (uint32)(*(const uint8 *)Master->txData);
            break;
            case 2U:
                data = (uint32)(*(const uint16 *)Master->txData);
            break;
            default:
                data = (uint32)(*(const uint32 *)Master->txData);
            break;
        }
        /* When txRemaininWords is 1 the last frame is transmitted. Will exceed array length with increment. */
        if((FALSE == Master->lastFrame) && (Master->txRemainingWords > 1U))
        {
            Master->txData = &Master->txData[Master->byteWidth];
        }
        Master->txRemainingWords -= 1U;
        /* Write data to shifter buffer */
        /* Shift data before bit-swapping it to get the relevant bits in the lower part of the shifter */
        data <<= 32U - (uint32)(8U * ((uint32)Master->byteWidth));
        Flexio_I2s_Ip_WriteShifterBuffer(baseAddr, Master->FlexioCommon.TxShifter, data, FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterCheckRxStatus
 * Description   : Check status of the I2S Reception. This function is called in MasterCheckStatus
 * to verify the reception.
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterCheckRxStatus(Flexio_I2s_Ip_StateType *Master,
                                              const FLEXIO_Type *baseAddr)
{
    /* Check if data was received */
    if (Master->FlexioCommon.RxEnabled)
    {
        if (Flexio_Mcl_Ip_GetShifterStatus(baseAddr, Master->FlexioCommon.RxShifter))
        {
            Flexio_I2s_Ip_ReadData(Master);
            if ((Master->rxData != NULL_PTR) && (Master->rxRemainingWords == 0U))
            {
                Master->driverIdle = TRUE;
                Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
                /* Out of rx space, call callback to allow user to provide a new buffer */
                if (Master->rxCallback != NULL_PTR)
                {
                    Master->rxCallback(FLEXIO_I2S_IP_EVENT_RX_FULL, Master->rxCallbackParam);
                }
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterCheckTxStatus
 * Description   : Check status of the I2S Transmission. This function is called in MasterCheckStatus
 * to verify the transmission.
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterCheckTxStatus(Flexio_I2s_Ip_StateType *Master,
                                              const FLEXIO_Type *baseAddr)
{
    /* Check if data was received */
    if ((Master->FlexioCommon.TxEnabled) && (Master->txData != NULL_PTR) && (Flexio_Mcl_Ip_GetShifterStatus(baseAddr, Master->FlexioCommon.TxShifter)))
    {
        Flexio_I2s_Ip_WriteData(Master);
        if (Master->txRemainingWords == 0U)
        {
            /* If all words were loaded into shifter transmit 2 more frames to keep the clock and data lines for the remaining frames to be transmitted. */
            if(Master->lastFrame == FALSE)
            {
                Master->txRemainingWords = FLEXIO_I2S_IP_LASTFRAME_COUNT;
                Master->lastFrame = TRUE;
            }
            else
            {
                Master->driverIdle = TRUE;
                Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
                /* Out of data, call callback to allow user to provide a new buffer */
                if (Master->txCallback != NULL_PTR)
                {
                    Master->txCallback(FLEXIO_I2S_IP_EVENT_TX_EMPTY, Master->txCallbackParam);
                }
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterCheckTransferFinished
 * Description   : Check status of the I2S Transmission. This function is called in MasterCheckStatus
 * to verify the end of transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterCheckTransferFinished(Flexio_I2s_Ip_StateType *Master)
{
    /* Check if transfer is over */
    if ((TRUE == Master->FlexioCommon.RxEnabled) && (Master->rxRemainingWords == 0U) && (Master->rxData != NULL_PTR))
    {
        /* End transfer */
        Flexio_I2s_Ip_MasterStopTransfer(Master);
        /* Record success if there was no error */
        if (Master->status == FLEXIO_I2S_IP_STATUS_BUSY)
        {
            Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
        }

        /* Call callback to announce the event to the user */
        if (Master->rxCallback != NULL_PTR)
        {
            Master->driverIdle = TRUE;
            Master->rxCallback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, Master->rxCallbackParam);
        }
    }
    /* Check if Tx transfer is over */
    if ((TRUE == Master->FlexioCommon.TxEnabled) && (Master->txRemainingWords == 0U) && (Master->txData != NULL_PTR))
    {
        /* End transfer */
        Flexio_I2s_Ip_MasterStopTransfer(Master);
        /* Record success if there was no error */
        if (Master->status == FLEXIO_I2S_IP_STATUS_BUSY)
        {
            Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
        }

        /* Call callback to announce the event to the user */
        if (Master->txCallback != NULL_PTR)
        {
            Master->driverIdle = TRUE;
            Master->txCallback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, Master->txCallbackParam);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterCheckStatus
 * Description   : Check status of the I2S transfer. This function can be
 *                 called either in an interrupt routine or directly in polling
 *                 mode to advance the I2S transfer.
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterCheckStatus(uint8 Instance,
                                            uint8 Channel)
{
    Flexio_I2s_Ip_StateType *Master = Flexio_I2s_Ip_pxState[Instance][Channel];
    FLEXIO_Type *baseAddr;

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* Check for errors */
    if (Master->txData != NULL_PTR)
    {
        if (Flexio_Mcl_Ip_GetShifterErrorStatus(baseAddr, Master->FlexioCommon.TxShifter))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_TX_UNDERRUN;
            Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, Master->FlexioCommon.TxShifter);
            /* Continue processing events */
        }
    }

    if (Master->rxData != NULL_PTR)
    {
        if (Flexio_Mcl_Ip_GetShifterErrorStatus(baseAddr, Master->FlexioCommon.RxShifter))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_RX_OVERRUN;
            Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, Master->FlexioCommon.RxShifter);
            /* Continue processing events */
        }
    }

    /* Check if data was received */
    Flexio_I2s_Ip_MasterCheckRxStatus(Master, baseAddr);

    /* Check if transmitter needs more data */
    Flexio_I2s_Ip_MasterCheckTxStatus(Master, baseAddr);

    /* Check if transfer is over */
    Flexio_I2s_Ip_MasterCheckTransferFinished(Master);
}

#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEndDmaTxTransfer
 * Description   : function called at the end of a DMA Tx transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEndDmaTxTransfer(uint8 Instance,
                                                 const uint8 FlexIOChannel)
{
    Flexio_I2s_Ip_StateType *State = NULL_PTR;
    uint8 ChannelIndex;

    if (0U != Flexio_I2s_Ip_ChannelStatus[FlexIOChannel])
    {
        ChannelIndex = Flexio_I2s_Ip_ChannelMapping[FlexIOChannel];
        State = Flexio_I2s_Ip_pxState[Instance][ChannelIndex];
        if ((FlexIOChannel == State->FlexioCommon.TxShifter) && (State->FlexioCommon.TxEnabled))
        {
            /* Ready the driver for another transfer */
            State->driverIdle = TRUE;
            State->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
            /* Clear DMA requests */
            (void)Dma_Ip_SetLogicChannelCommand(State->txDMAChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            (void)Dma_Ip_SetLogicChannelCommand(State->txDMAChannel, DMA_IP_CH_CLEAR_DONE);
            Flexio_I2s_Ip_MasterEndTransfer(State);
            if (State->txCallback != NULL_PTR)
            {
                /* Callback for user handling of TX_EMPTY event */
                State->txCallback(FLEXIO_I2S_IP_EVENT_TX_EMPTY, State->txCallbackParam);
            }

            if (State->driverIdle == TRUE)
            {
                /* New transfer has not been started -> END Transfer */
                State->txData = NULL_PTR;
                Flexio_I2s_Ip_MasterStopTransfer(State);
                if (State->txCallback != NULL_PTR)
                {
                    State->txCallback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, State->txCallbackParam);
                }
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEndDmaRxTransfer
 * Description   : function called at the end of a DMA Tx transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEndDmaRxTransfer(uint8 Instance,
                                                 const uint8 FlexIOChannel)
{
    Flexio_I2s_Ip_StateType *State = NULL_PTR;
    uint8 ChannelIndex;

    if (0U != Flexio_I2s_Ip_ChannelStatus[FlexIOChannel])
    {
        ChannelIndex = Flexio_I2s_Ip_ChannelMapping[FlexIOChannel];
        State = Flexio_I2s_Ip_pxState[Instance][ChannelIndex];
        if ((FlexIOChannel == State->FlexioCommon.RxShifter) && (State->FlexioCommon.RxEnabled))
        {
            if (State->rxData != NULL_PTR)
            {
                if (State->rxCallback != NULL_PTR)
                {
                    State->driverIdle = TRUE;
                    State->rxCallback(FLEXIO_I2S_IP_EVENT_RX_FULL, State->rxCallbackParam);
                }
            }

            if (State->rxRemainingWords == 0U)
            {
                /* End transfer */
                Flexio_I2s_Ip_MasterStopTransfer(State);
                /* No more data, end transfer */
                if (State->status == FLEXIO_I2S_IP_STATUS_BUSY)
                {
                    State->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
                }

                /* Call callback to announce the event to the user */
                if (State->rxCallback != NULL_PTR)
                {
                    State->driverIdle = TRUE;
                    State->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
                    State->rxCallback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, State->rxCallbackParam);
                }
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterStartDmaTransfer
 * Description   : Starts a DMA transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterStartDmaTransfer(Flexio_I2s_Ip_StateType *Master)
{
    uint8 ShifterMask = 0u;
    FLEXIO_Type *baseAddr;
    Dma_Ip_LogicChannelTransferListType DmaTransferList[10u];
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    const uint8 DmaTransferSize[SIZE_OF_32BIT_REG] = { DMA_IP_TRANSFER_SIZE_1_BYTE, DMA_IP_TRANSFER_SIZE_2_BYTE, DMA_IP_TRANSFER_SIZE_4_BYTE, DMA_IP_TRANSFER_SIZE_4_BYTE };

    DmaTransferList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTransferList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTransferList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTransferList[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTransferList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTransferList[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTransferList[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTransferList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTransferList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTransferList[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    DmaTransferList[2u].Value = DmaTransferSize[Master->byteWidth - 1u];
    DmaTransferList[5u].Value = DmaTransferSize[Master->byteWidth - 1u];
    DmaTransferList[6u].Value = Master->byteWidth; /* Size of buffer */
    DmaTransferList[8u].Value = 1U;
    DmaTransferList[9u].Value = 1U;

    if (Master->txData != NULL_PTR)
    {
        /* Configure DMA channel for send transfers */
        /* Source/Destination configuration values */
        DmaTransferList[0u].Value = (uint32)(&(Master->txData[0U]));
        DmaTransferList[1u].Value = Master->byteWidth; /* Size of buffer */
        /* The bytes to be transferred are actually in SHIFBUF but data is written in SHIFTBUFBIS with bits are swapped
        So the offset for DMA to copy to SHIFTBUFBIS is swapped also
        Therefore, the correct offset = size of register (4bytes) - byteWidth */
        DmaTransferList[3u].Value = (uint32)(&(baseAddr->SHIFTBUFBIS[Master->FlexioCommon.TxShifter])) + (SIZE_OF_32BIT_REG - (uint32)Master->byteWidth);
        DmaTransferList[4u].Value = 0U;
        DmaTransferList[7u].Value = Master->txRemainingWords;

        /* Now that this tx is set up, clear remaining bytes count */
        Master->txRemainingWords = 0U;
        (void)Dma_Ip_SetLogicChannelTransferList(Master->txDMAChannel, DmaTransferList, 10u);
        /* Start DMA channel */
        (void)Dma_Ip_SetLogicChannelCommand(Master->txDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        ShifterMask = (1U << Master->FlexioCommon.TxShifter);
    }

    /* Configure DMA channel for receive transfers*/
    /* Source/Destination configuration values */
    if (Master->FlexioCommon.RxEnabled)
    {
        DmaTransferList[0u].Value = (uint32) (&(baseAddr->SHIFTBUFBIS[Master->FlexioCommon.RxShifter]));
        DmaTransferList[1u].Value = 0U;
        if (Master->rxData != NULL_PTR)
        {
            DmaTransferList[3u].Value = (uint32)(&(Master->rxData[0]));
            DmaTransferList[4u].Value = Master->byteWidth; /* Size of buffer */
        }
        else
        {
            DmaTransferList[3u].Value = (uint32)(&(Master->dummyDmaData));
            DmaTransferList[4u].Value = 0U;
        }

        DmaTransferList[7u].Value = Master->rxRemainingWords;

        /* Now that this rx is set up, clear remaining bytes count */
        Master->rxRemainingWords = 0U;
        (void)Dma_Ip_SetLogicChannelTransferList(Master->rxDMAChannel, DmaTransferList, 10u);
        /* Start DMA channel */
        (void)Dma_Ip_SetLogicChannelCommand(Master->rxDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);

        ShifterMask |= (1U << Master->FlexioCommon.RxShifter);
    }

    Flexio_Mcl_Ip_SetShifterDMARequest(baseAddr, ShifterMask, TRUE);
}

#endif /* #if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ResourcesInit
 * Description   : Initializes the resources for the current driver
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_ResourcesInit(uint8 Instance,
                                        const Flexio_I2s_Ip_CommonStateType *Driver)
{
    uint8 Resource;
    uint8 ResourceCount;
    uint8 ResourceIndex;
    FLEXIO_Type *BaseAddr;

    BaseAddr = Flexio_I2s_Ip_pBaseAddr[Instance];
    ResourceCount = Driver->ResourceCount;
    ResourceIndex = Driver->ResourceIndex;
    for (Resource = ResourceIndex; Resource < (ResourceIndex + ResourceCount); Resource++)
    {
        /* Ensure all shifters/timers are disabled */
        Flexio_I2s_Ip_SetShifterMode(BaseAddr, Resource, FLEXIO_SHIFTER_MODE_DISABLED);
        Flexio_I2s_Ip_SetTimerMode(BaseAddr, Resource, FLEXIO_TIMER_MODE_DISABLED);
        /* Ensure all interrupts and DMA requests are disabled */
        Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
        Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
        Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
        Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)(1U << Resource), FALSE);
        /* Clear any leftover flags */
        Flexio_Mcl_Ip_ClearShifterStatus(BaseAddr, Resource);
        Flexio_Mcl_Ip_ClearShifterErrorStatus(BaseAddr, Resource);
        Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, Resource);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_InitDriver
 * Description   : Initializes an Instance of FlexIO driver
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_InitDriver(uint8 Instance,
                                     uint8 Channel,
                                     const Flexio_I2s_Ip_CommonStateType *Driver)
{
    uint8 Index;
    uint8 ResourceCount; /* Only TX and RX Channel create event */
    const uint8 ResourceIndex = (uint8)(Driver->ResourceIndex);

    if ((Driver->TxEnabled) && (Driver->RxEnabled))
    {
        ResourceCount = (uint8)2U;
    }
    else
    {
        ResourceCount = (uint8)1U;
    }

    for (Index = (uint8)0U; Index < ResourceCount; Index++)
    {
        /* Shifter/Timer Channel is being used */
        Flexio_I2s_Ip_ChannelStatus[ResourceIndex + Index] = 1U;
        /* Mapping Shifter/Timer Channel with Hardware Channel */
        Flexio_I2s_Ip_ChannelMapping[ResourceIndex + Index] = Channel;
    }

    /* initialize the allocated resources */
    Flexio_I2s_Ip_ResourcesInit(Instance, Driver);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_DeinitDriver
 * Description   : De-initializes an Instance of FlexIO driver
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_DeinitDriver(const Flexio_I2s_Ip_CommonStateType *Driver)
{
    uint8 Index;
    uint8 ResourceCount; /* Only TX and RX Channel create event */
    const uint8 ResourceIndex = (uint8)(Driver->ResourceIndex);

    if ((Driver->TxEnabled) && (Driver->RxEnabled))
    {
        ResourceCount = (uint8)2U;
    }
    else
    {
        ResourceCount = (uint8)1U;
    }

    for (Index = (uint8)0U; Index < ResourceCount; Index++)
    {
        Flexio_I2s_Ip_ChannelStatus[ResourceIndex + Index] = (uint8)0U;
        Flexio_I2s_Ip_ChannelMapping[ResourceIndex + Index] = (uint8)0U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ResetStatusStruct
 * Description   : Resets FlexIO status structure
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_ResetStatusStruct(uint8 Instance,
                                            uint8 Channel)
{
    Flexio_I2s_Ip_StateType *pState = Flexio_I2s_Ip_pxState[Instance][Channel];

    if (NULL_PTR != pState)
    {
        pState->txData = NULL_PTR;
        pState->rxData = NULL_PTR;
        pState->txRemainingWords = (uint8)0U;
        pState->rxRemainingWords = (uint8)0U;
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
        pState->dummyDmaData = (uint8)0U;
        pState->rxDMAChannel = (uint8)0U;
        pState->txDMAChannel = (uint8)0U;
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
        pState->byteWidth = 0;
        pState->driverIdle = TRUE;
        pState->blocking = FALSE;
        pState->lastFrame = FALSE;
        pState->txCallback = NULL_PTR;
        pState->rxCallback = NULL_PTR;
        pState->txCallbackParam = NULL_PTR;
        pState->rxCallbackParam = NULL_PTR;
        pState->status = FLEXIO_I2S_IP_STATUS_UNINIT;
    }

    Flexio_I2s_Ip_pxState[Instance][Channel] = NULL_PTR;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterInit
 * Description   : Initialize the FLEXIO_I2S Master mode driver
 * @implements Flexio_I2s_Ip_MasterInit_Activity
 *
 *END**************************************************************************/
void Flexio_I2s_Ip_MasterInit(uint8 Instance,
                              uint8 Channel,
                              const Flexio_I2s_Ip_MasterConfigType *ConfigPtr)
{
    Flexio_I2s_Ip_StateType *Master;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(ConfigPtr != NULL_PTR);
    DevAssert(Flexio_I2s_Ip_pxState[Instance][Channel] == NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    Flexio_I2s_Ip_pxState[Instance][Channel] = ConfigPtr->MasterState;
    Master = Flexio_I2s_Ip_pxState[Instance][Channel];

    /* Instruct the resource allocator that we need two shifters/timers */
    if ((ConfigPtr->txPin > (uint8)0U) && (ConfigPtr->rxPin > (uint8)0U))
    {
        Master->FlexioCommon.ResourceCount = (uint8)2U;
        Master->FlexioCommon.TxEnabled = TRUE;
        Master->FlexioCommon.RxEnabled = TRUE;
        Master->FlexioCommon.TxShifter = ConfigPtr->ResourceIndex;
        Master->FlexioCommon.RxShifter = ConfigPtr->ResourceIndex + (uint8)1U;
    }
    else if (ConfigPtr->txPin > (uint8)0U)
    {
        Master->FlexioCommon.ResourceCount = (uint8)1U;
        Master->FlexioCommon.TxEnabled = TRUE;
        Master->FlexioCommon.RxEnabled = FALSE;
        Master->FlexioCommon.TxShifter = ConfigPtr->ResourceIndex;
    }
    else if (ConfigPtr->rxPin > (uint8)0U)
    {
        Master->FlexioCommon.ResourceCount = (uint8)1U;
        Master->FlexioCommon.TxEnabled = FALSE;
        Master->FlexioCommon.RxEnabled = TRUE;
        Master->FlexioCommon.RxShifter = ConfigPtr->ResourceIndex;
    }
    else
    {
        /* Avoid MISRA */
    }

    Master->FlexioCommon.ResourceIndex = ConfigPtr->ResourceIndex;

    /* Common FlexIO driver initialization */
    Flexio_I2s_Ip_InitDriver(Instance, Channel, &(Master->FlexioCommon));

    /* Initialize driver-specific context structure */
    Master->driverType = ConfigPtr->driverType;
    Master->byteWidth = ConfigPtr->byteWidth;
    Master->driverIdle = TRUE;
    Master->txCallback = ConfigPtr->txCallback;
    Master->rxCallback = ConfigPtr->rxCallback;
    Master->txCallbackParam = ConfigPtr->txCallbackParam;
    Master->rxCallbackParam = ConfigPtr->rxCallbackParam;
    Master->blocking = FALSE;
    Master->lastFrame = FALSE;
    Master->txData = NULL_PTR;
    Master->txRemainingWords = (uint32)0U;
    Master->rxData = NULL_PTR;
    Master->rxRemainingWords = (uint32)0U;
    Master->Master = TRUE;
    Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;

    /* Configure device for I2S mode */
    Flexio_I2s_Ip_MasterConfigure(Master, ConfigPtr);

    /* Set up transfer engine */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    if (FLEXIO_I2S_IP_DRIVER_TYPE_DMA == Master->driverType)
    {
        Master->txDMAChannel = ConfigPtr->txDMAChannel;
        Master->rxDMAChannel = ConfigPtr->rxDMAChannel;
    }
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_SlaveInit
 * Description   : Initialize the FLEXIO_I2S Slave mode driver
 * @implements Flexio_I2s_Ip_SlaveInit_Activity
 *
 *END**************************************************************************/
void Flexio_I2s_Ip_SlaveInit(uint8 Instance,
                             uint8 Channel,
                             const Flexio_I2s_Ip_SlaveConfigType *ConfigPtr)
{
    Flexio_I2s_Ip_StateType *Slave;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(ConfigPtr != NULL_PTR);
    DevAssert(Flexio_I2s_Ip_pxState[Instance][Channel] == NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    Flexio_I2s_Ip_pxState[Instance][Channel] = ConfigPtr->SlaveState;
    Slave =  Flexio_I2s_Ip_pxState[Instance][Channel];

    /* Instruct the resource allocator that we need three shifters/timers */
    if ((ConfigPtr->txPin > (uint8)0U) && (ConfigPtr->rxPin > (uint8)0U))
    {
        Slave->FlexioCommon.ResourceCount = (uint8)3U;
        Slave->FlexioCommon.TxEnabled = TRUE;
        Slave->FlexioCommon.RxEnabled = TRUE;
        Slave->FlexioCommon.TxShifter = ConfigPtr->ResourceIndex;
        Slave->FlexioCommon.RxShifter = ConfigPtr->ResourceIndex + (uint8)1U;
    }
    else if (ConfigPtr->txPin > (uint8)0U)
    {
        Slave->FlexioCommon.ResourceCount = (uint8)2U;
        Slave->FlexioCommon.TxEnabled = TRUE;
        Slave->FlexioCommon.RxEnabled = FALSE;
        Slave->FlexioCommon.TxShifter = ConfigPtr->ResourceIndex;
    }
    else if (ConfigPtr->rxPin > (uint8)0U)
    {
        Slave->FlexioCommon.ResourceCount = (uint8)2U;
        Slave->FlexioCommon.TxEnabled = FALSE;
        Slave->FlexioCommon.RxEnabled = TRUE;
        Slave->FlexioCommon.RxShifter = ConfigPtr->ResourceIndex;
    }
    else
    {
        /* Avoid MISRA */
    }

    Slave->FlexioCommon.ResourceIndex = ConfigPtr->ResourceIndex;

    /* Common FlexIO driver initialization */
    Flexio_I2s_Ip_InitDriver(Instance, Channel, &(Slave->FlexioCommon));

    /* Initialize driver-specific context structure */
    Slave->driverType = ConfigPtr->driverType;
    Slave->byteWidth = ConfigPtr->byteWidth;
    Slave->driverIdle = TRUE;
    Slave->txCallback = ConfigPtr->txCallback;
    Slave->rxCallback = ConfigPtr->rxCallback;
    Slave->txCallbackParam = ConfigPtr->txCallbackParam;
    Slave->rxCallbackParam = ConfigPtr->rxCallbackParam;
    Slave->blocking = FALSE;
    Slave->lastFrame = FALSE;
    Slave->txData = NULL_PTR;
    Slave->txRemainingWords = (uint32)0U;
    Slave->rxData = NULL_PTR;
    Slave->rxRemainingWords = (uint32)0U;
    Slave->Master = FALSE;
    Slave->status = FLEXIO_I2S_IP_STATUS_SUCCESS;

    /* Configure device for I2S mode */
    Flexio_I2s_Ip_SlaveConfigure(Slave, ConfigPtr);

    /* Set up transfer engine */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    if (FLEXIO_I2S_IP_DRIVER_TYPE_DMA == Slave->driverType)
    {
        Slave->txDMAChannel = ConfigPtr->txDMAChannel;
        Slave->rxDMAChannel = ConfigPtr->rxDMAChannel;
    }
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_Deinit
 * Description   : De-initialize the FLEXIO_I2S driver
 * @implements Flexio_I2s_Ip_Deinit_Activity
 *
 *END**************************************************************************/
void Flexio_I2s_Ip_Deinit(uint8 Instance,
                          uint8 Channel)
{
    const Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Flexio != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    /* Check if Driver is busy */
    if (FALSE == Flexio->driverIdle)
    {
        (void)Flexio_I2s_Ip_WaitTimeout(Flexio, FLEXIO_I2S_IP_INTERNAL_TIMEOUT_VALUE);
    }
    else
    {
        /*Do nothing*/
    }

    Flexio_I2s_Ip_DeinitDriver(&(Flexio->FlexioCommon));
    Flexio_I2s_Ip_ResetStatusStruct(Instance, Channel);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_SendData
 * Description   : Perform a non-blocking send transaction on the I2S bus
 * @implements Flexio_I2s_Ip_SendData_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SendData(uint8 Instance,
                                                uint8 Channel,
                                                const uint8 *TxBuff,
                                                uint32 TxSize)
{
    Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];

    FLEXIO_Type *baseAddr;
    Flexio_I2s_Ip_StatusType RetStatus = FLEXIO_I2S_IP_STATUS_SUCCESS;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Flexio != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Flexio->FlexioCommon.Instance];

    /* Check if driver is busy */
    if (Flexio->driverIdle == FALSE)
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
    }
    else
    {
        Flexio->txData = TxBuff;
        Flexio->txRemainingWords = TxSize;
        /* also count received data, it tells us when tx is actually completed */
        Flexio->rxRemainingWords = TxSize;
        Flexio->rxData = NULL_PTR;
        Flexio->status = FLEXIO_I2S_IP_STATUS_BUSY;
        Flexio->driverIdle = FALSE;
        Flexio->lastFrame = FALSE;

        /* Enable pin output */
        Flexio_I2s_Ip_SetShifterPinConfig(baseAddr, Flexio->FlexioCommon.TxShifter, FLEXIO_PIN_CONFIG_OUTPUT);
        /* Enable timers and shifters */
        Flexio_I2s_Ip_MasterEnableTransfer(Flexio);
        /* Enable transfer engine */
        switch (Flexio->driverType)
        {
            case FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT:
                /* Enable interrupts for Tx shifter */
                Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr,
                                                  (uint8)((1U << Flexio->FlexioCommon.TxShifter)),
                                                  TRUE);
                Flexio_Mcl_Ip_SetShifterErrorInterrupt(baseAddr,
                                                       (uint8)((1U << Flexio->FlexioCommon.TxShifter)),
                                                       TRUE);
            break;
            case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
                /* Call Flexio_I2s_Ip_MasterCheckStatus once to send the first byte */
                Flexio_I2s_Ip_MasterCheckStatus(Instance, Channel);
            break;
    #if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
            case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
                Flexio_I2s_Ip_MasterStartDmaTransfer(Flexio);
            break;
    #endif
            default:
                /* Impossible type - do nothing */
            break;
        }
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_SendDataBlocking
 * Description   : Perform a blocking send transaction on the I2S bus
 * @implements Flexio_I2s_Ip_SendDataBlocking_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SendDataBlocking(uint8 Instance,
                                                        uint8 Channel,
                                                        const uint8 *TxBuff,
                                                        uint32 TxSize,
                                                        uint32 Timeout)
{
    Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];
    Flexio_I2s_Ip_StatusType RetStatus;

    if (Flexio->driverType == FLEXIO_I2S_IP_DRIVER_TYPE_POLLING)
    {
        /* Check if driver is busy */
        if (Flexio->driverIdle == FALSE)
        {
            RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
        }
        else
        {
            /* mark transfer as blocking */
            Flexio->blocking = TRUE;
            /* Call Flexio_I2s_Ip_SendData to start transfer */
            (void)Flexio_I2s_Ip_SendData(Instance, Channel, TxBuff, TxSize);
            /* Wait for transfer to end */
            RetStatus = Flexio_I2s_Ip_MasterWaitTransferEnd(Instance, Channel, Timeout);
        }
    }
    else
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_ERROR;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ReceiveData
 * Description   : Perform a non-blocking receive transaction on the I2S bus
 * @implements Flexio_I2s_Ip_ReceiveData_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_ReceiveData(uint8 Instance,
                                                   uint8 Channel,
                                                   uint8 *RxBuff,
                                                   uint32 RxSize)
{
    Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];

    FLEXIO_Type *baseAddr;
    Flexio_I2s_Ip_StatusType RetStatus = FLEXIO_I2S_IP_STATUS_SUCCESS;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Flexio != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Flexio->FlexioCommon.Instance];

    /* Check if driver is busy */
    if (Flexio->driverIdle == FALSE)
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
    }
    else
    {
        Flexio->rxData = RxBuff;
        Flexio->rxRemainingWords = RxSize;
        Flexio->txData = NULL_PTR;
        Flexio->txRemainingWords = RxSize;
        Flexio->status = FLEXIO_I2S_IP_STATUS_BUSY;
        Flexio->driverIdle = FALSE;

        /* Enable timers and shifters */
        Flexio_I2s_Ip_MasterEnableTransfer(Flexio);

        /* Enable transfer engine */
        switch (Flexio->driverType)
        {
            case FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT:
                /* Enable interrupts for Rx shifter */
                Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr,
                                                  (uint8)(1U << Flexio->FlexioCommon.RxShifter),
                                                  TRUE);
                Flexio_Mcl_Ip_SetShifterErrorInterrupt(baseAddr,
                                                       (uint8)(1U << Flexio->FlexioCommon.RxShifter),
                                                       TRUE);
            break;
            case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
                /* Call Flexio_I2s_Ip_MasterCheckStatus once to send the first byte */
                Flexio_I2s_Ip_MasterCheckStatus(Instance, Channel);
            break;
    #if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
            case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
                Flexio_I2s_Ip_MasterStartDmaTransfer(Flexio);
            break;
    #endif
            default:
                /* Impossible type - do nothing */
            break;
        }

        if (Flexio->FlexioCommon.TxEnabled)
        {
            /* For Master we need to send a dummy char to start the clock.
               For Slave just put a 0 in the buffer to keep the tx line clear while receiving. */
            Flexio_I2s_Ip_WriteShifterBuffer(baseAddr, Flexio->FlexioCommon.TxShifter, 0x0, FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
        }
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ReceiveDataBlocking
 * Description   : Perform a blocking receive transaction on the I2S bus
 * @implements Flexio_I2s_Ip_ReceiveDataBlocking_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_ReceiveDataBlocking(uint8 Instance,
                                                           uint8 Channel,
                                                           uint8 *RxBuff,
                                                           uint32 RxSize,
                                                           uint32 Timeout)
{
    Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];
    Flexio_I2s_Ip_StatusType RetStatus;

    if (Flexio->driverType == FLEXIO_I2S_IP_DRIVER_TYPE_POLLING)
    {
        /* Check if driver is busy */
        if (Flexio->driverIdle == FALSE)
        {
            RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
        }
        else
        {
            /* mark transfer as blocking */
            Flexio->blocking = TRUE;

            /* Call Flexio_I2s_Ip_ReceiveData to start transfer */
            (void)Flexio_I2s_Ip_ReceiveData(Instance, Channel, RxBuff, RxSize);
            /* Wait for transfer to end */
            RetStatus = Flexio_I2s_Ip_MasterWaitTransferEnd(Instance, Channel, Timeout);
        }
    }
    else
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_ERROR;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_TransferAbort
 * Description   : Aborts a non-blocking I2S transaction
 * @implements Flexio_I2s_Ip_TransferAbort_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_TransferAbort(uint8 Instance,
                                                     uint8 Channel)
{
    Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];
    Flexio_I2s_Ip_StatusType t_Return = FLEXIO_I2S_IP_STATUS_SUCCESS;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Flexio != NULL_PTR);
#endif
    if (FLEXIO_I2S_IP_STATUS_UNINIT != Flexio->status)
    {
#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
        DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
        DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif
        /* Check if driver is busy */
        if (Flexio->driverIdle)
        {
            t_Return = FLEXIO_I2S_IP_STATUS_SUCCESS;
        }

        Flexio_I2s_Ip_MasterStopTransfer(Flexio);
        Flexio->status = FLEXIO_I2S_IP_STATUS_ABORTED;
        Flexio->driverIdle = TRUE;
    }
    else
    {
        t_Return = FLEXIO_I2S_IP_STATUS_UNINIT;
    }

    return t_Return;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_GetStatus
 * Description   : Get the status of the current non-blocking I2S Flexio transaction
 * @implements Flexio_I2s_Ip_GetStatus_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_GetStatus(uint8 Instance,
                                                 uint8 Channel,
                                                 uint32 *BytesRemaining)
{
    const Flexio_I2s_Ip_StateType *Flexio = Flexio_I2s_Ip_pxState[Instance][Channel];
    uint32 RemainingWords = (uint32)0U;
    Flexio_I2s_Ip_StatusType RetStatus;
    boolean IsChannelIdle;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Flexio != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    RetStatus = Flexio->status;
    if (RetStatus != FLEXIO_I2S_IP_STATUS_UNINIT)
    {
        IsChannelIdle = Flexio->driverIdle;
        if (IsChannelIdle == FALSE)
        {
            switch (Flexio->driverType)
            {
                case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
                    /* In polling mode advance the I2S transfer here */
                    Flexio_I2s_Ip_MasterCheckStatus(Instance, Channel);
                    RemainingWords = Flexio->rxRemainingWords;
                break;
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
                case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
                    /* In DMA mode just update the remaining count.
                    DO NOT write Flexio->rxRemainingWords directly !!! */
                    (void)Dma_Ip_GetLogicChannelParam(Flexio->rxDMAChannel, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &RemainingWords);
                break;
#endif
                default: /* Interrupt */
                    RemainingWords = Flexio->rxRemainingWords;
                break;
            }
        }

        if (RetStatus == FLEXIO_I2S_IP_STATUS_ABORTED)
        {
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
            if (Flexio->driverType == FLEXIO_I2S_IP_DRIVER_TYPE_DMA)
            {
                /* DO NOT write Flexio->rxRemainingWords directly !!! */
                (void)Dma_Ip_GetLogicChannelParam(Flexio->rxDMAChannel, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &RemainingWords);
            }
            else
#endif
            {
                RemainingWords = Flexio->rxRemainingWords;
            }
        }

        /* Use rxRemainingWords even for transmit; byte is not transmitted
        until rx shifter reports a receive event */
        if (BytesRemaining != NULL_PTR)
        {
            *BytesRemaining = RemainingWords;
        }

        if (IsChannelIdle == FALSE)
        {
            RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
        }
    }
    else
    {
        /* Driver uninitialized, do nothing. */
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterCheckEvent
 * Description   : Check if event had occurred for selected FlexIO channel
 *
 *END**************************************************************************/
static boolean Flexio_I2s_Ip_MasterCheckEvent(uint8 StatusMask,
                                              uint8 Channel)
{
    return (((((uint32)StatusMask) >> Channel) & 1U) == 1U) ? TRUE : FALSE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_TransmitEventHandler
 * Description   : handler for transmit event
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_TransmitEventHandler(Flexio_I2s_Ip_StateType *Master,
                                               uint8 ShifterMaskFlag,
                                               uint8 ShifterErrMaskFlag,
                                               uint8 TimerMaskFlag)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    boolean DoCallback = FALSE;

    BaseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Handle events for TX shifter or SCK timer */
    if (Flexio_I2s_Ip_MasterCheckEvent(ShifterErrMaskFlag, Master->FlexioCommon.TxShifter))
    {
        if (TRUE == Flexio_Mcl_Ip_GetShifterErrorStatus(BaseAddr, Master->FlexioCommon.TxShifter))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_TX_UNDERRUN;
            /* don't stop the transfer, continue processing events */
        }
    }

    /* Check if transmitter needs more data */
    if ((Flexio_I2s_Ip_MasterCheckEvent(ShifterMaskFlag, Master->FlexioCommon.TxShifter)) && (TRUE == Flexio_I2s_Ip_GetShifterInterrupt(BaseAddr, Master->FlexioCommon.TxShifter)))
    {
        Flexio_I2s_Ip_WriteData(Master);
        if (0U == Master->txRemainingWords)
        {
            /* If all words were loaded into shifter transmit 2 more frames to keep the clock and data lines for the remaining frames to be transmitted. */
            if(Master->lastFrame == FALSE)
            {
                Master->txRemainingWords = FLEXIO_I2S_IP_LASTFRAME_COUNT;
                Master->lastFrame = TRUE;
            }
            else
            {
                Master->driverIdle = TRUE;
                Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
                if (Master->txCallback != NULL_PTR)
                {
                    Master->txCallback(FLEXIO_I2S_IP_EVENT_TX_EMPTY, Master->txCallbackParam);
                }
                /* If still empty after callback. */
                if ((0U == Master->txRemainingWords) && (Flexio_I2s_Ip_MasterCheckEvent(TimerMaskFlag, SCK_TIMER(ResourceIndex))) && (TRUE == Flexio_Mcl_Ip_GetTimerStatus(BaseAddr,SCK_TIMER(ResourceIndex))))
                {
                   /* Done transmitting, disable Tx interrupt */
                   Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr, (uint8)(1U << Master->FlexioCommon.TxShifter), FALSE);
                   Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr, (uint8)(1U << Master->FlexioCommon.TxShifter), FALSE);
                   DoCallback = TRUE;
                }
            }
            
            if(DoCallback)
            {
                if (Master->txCallback != NULL_PTR)
                {
                    Master->txCallback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, Master->txCallbackParam);
                }
                Flexio_I2s_Ip_MasterStopTransfer(Master);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ReceiveEventHandler
 * Description   : handler for receive event
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_ReceiveEventHandler(Flexio_I2s_Ip_StateType *Master,
                                              uint8 ShifterMaskFlag,
                                              uint8 ShifterErrMaskFlag)
{
    const FLEXIO_Type *BaseAddr;
    BaseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    if (Flexio_I2s_Ip_MasterCheckEvent(ShifterErrMaskFlag, Master->FlexioCommon.RxShifter))
    {
        if (TRUE == Flexio_Mcl_Ip_GetShifterErrorStatus(BaseAddr, Master->FlexioCommon.RxShifter))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_RX_OVERRUN;
            /* don't stop the transfer, continue processing events */
        }
    }

    /* Check if data was received */
    if (TRUE == Flexio_I2s_Ip_MasterCheckEvent(ShifterMaskFlag, Master->FlexioCommon.RxShifter))
    {
        if (TRUE == Flexio_I2s_Ip_GetShifterInterrupt(BaseAddr, Master->FlexioCommon.RxShifter))
        {
            Flexio_I2s_Ip_ReadData(Master);
        }
    }

    /* Check if transfer is over */
    if ((Master->FlexioCommon.RxEnabled == TRUE) && (Master->rxRemainingWords == 0U))
    {
        /* Record success if there was no error */
        if (Master->status == FLEXIO_I2S_IP_STATUS_BUSY)
        {
            Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
        }
        /* User Callback handling for Full RX Buffer. */
        Master->driverIdle = TRUE;
        if (Master->rxCallback != NULL_PTR)
        {
            Master->rxCallback(FLEXIO_I2S_IP_EVENT_RX_FULL, Master->rxCallbackParam);
        }
        /* No new transfer initiated -> Stop transfer. */
        if(Master->rxRemainingWords == 0U)
        {
            /* Call callback to announce the event to the user */
            if (Master->rxCallback != NULL_PTR)
            {
                Master->rxCallback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, Master->rxCallbackParam);
            }
            /* End transfer */
            Flexio_I2s_Ip_MasterStopTransfer(Master);
        }
    }
}

/*!
 * @brief Handler for FlexIO I2s channels
 *
 * @param FlexIOChannel    FlexIO channel
 * @param ShifterMaskFlag  Status mask of Flexio channel
 * @param ShifterErrMaskFlag  Status error mask of Flexio channel
 * @param TimerMaskFlag  Timer mask of Flexio channel
 * @return
 * @implements Flexio_I2s_Ip_IrqHandler_Activity
 */
void Flexio_I2s_Ip_IrqHandler(uint8 FlexIOChannel,
                              uint8 ShifterMaskFlag,
                              uint8 ShifterErrMaskFlag,
                              uint8 TimerMaskFlag)
{
    Flexio_I2s_Ip_StateType *State = NULL_PTR;
    const uint8 Instance = 0U;
    uint8 ChannelIndex;

    if (0U != Flexio_I2s_Ip_ChannelStatus[FlexIOChannel])
    {
        ChannelIndex = Flexio_I2s_Ip_ChannelMapping[FlexIOChannel];
        State = Flexio_I2s_Ip_pxState[Instance][ChannelIndex];
        if ((FlexIOChannel == State->FlexioCommon.TxShifter) && (State->FlexioCommon.TxEnabled))
        {
            Flexio_I2s_Ip_TransmitEventHandler(State, ShifterMaskFlag, ShifterErrMaskFlag, TimerMaskFlag);
        }
        else if ((FlexIOChannel == State->FlexioCommon.RxShifter) && (State->FlexioCommon.RxEnabled))
        {
            Flexio_I2s_Ip_ReceiveEventHandler(State, ShifterMaskFlag, ShifterErrMaskFlag);
        }
        else
        {
            /* Avoid MISRA */
        }
    }
}

#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
/* Dma complete transmit notification for flexio channel 0 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter0(void);

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter0(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 0U); /* Dma complete transmit notification for flexio channel 0 */
}

/* Dma complete receive notification for flexio channel 1 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter1(void);

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter1(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 1U); /* Dma complete receive notification for flexio channel 1 */
}

/* Dma complete transmit notification for flexio channel 1 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter1(void);

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter1(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 1U); /* Dma complete transmit notification for flexio channel 1 */
}

/* Dma complete receive notification for flexio channel 2 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter2(void);

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter2(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 2U); /* Dma complete receive notification for flexio channel 2 */
}

/* Dma complete transmit notification for flexio channel 2 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter2(void);

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter2(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 2U); /* Dma complete transmit notification for flexio channel 2 */
}

/* Dma complete receive notification for flexio channel 3 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter3(void);

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter3(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 3U); /* Dma complete receive notification for flexio channel 3 */
}

#if (FLEXIO_I2S_IP_MAX_CHANNEL_COUNT > 4U)
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter3(void);

/* Dma complete transmit notification for flexio channel 3 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter3(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 3U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter4(void);

/* Dma complete receive notification for flexio channel 4 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter4(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 4U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter4(void);

/* Dma complete transmit notification for flexio channel 4 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter4(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 4U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter5(void);

/* Dma complete receive notification for flexio channel 5 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter5(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 5U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter5(void);

/* Dma complete transmit notification for flexio channel 5 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter5(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 5U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter6(void);

/* Dma complete receive notification for flexio channel 6 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter6(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 6U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter6(void);

/* Dma complete transmit notification for flexio channel 6 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter6(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 6U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter7(void);

/* Dma complete receive notification for flexio channel 7 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter7(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 7U);
}

#endif /* (FLEXIO_I2S_IP_MAX_CHANNEL_COUNT > 4U) */
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#endif /* (STD_ON == FLEXIO_I2S_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
