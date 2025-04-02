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
*   @addtogroup group_name
*   @{
*/

#ifdef _cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Zipwire_Ip_Lfast.h"
#include "Zipwire_Ip_Lfast_Hw_Access.h"
#include "Zipwire_Ip_DevAssert.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_LFAST_VENDOR_ID_C                   43
#define ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C    4
#define ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C    7
#define ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION_C 0
#define ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION_C            5
#define ZIPWIRE_IP_LFAST_SW_MINOR_VERSION_C            0
#define ZIPWIRE_IP_LFAST_SW_PATCH_VERSION_C            0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip_Lfast.h file and Mcal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Mcal.h are different"
#endif
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same vendor */
#if (ZIPWIRE_IP_LFAST_VENDOR_ID_C != ZIPWIRE_IP_LFAST_HW_ACCESS_VENDOR_ID)
#error "Zipwire_Ip_Lfast.h and Zipwire_Ip_Lfast_Hw_Access.h have different vendor ids"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h header file are of the same Software version */
#if ((ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_SW_MINOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_SW_PATCH_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif


/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same vendor */
#if (ZIPWIRE_IP_LFAST_VENDOR_ID_C != ZIPWIRE_IP_DEVASSERT_VENDOR_ID)
#error "Zipwire_Ip_Lfast.h and Zipwire_Ip_DevAssert.h have different vendor ids"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_DevAssert.h are different"
#endif

/* Check if source file and Zipwire_Ip_CfgDefines.h header file are of the same Software version */
#if ((ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_SW_MINOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_SW_PATCH_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_DevAssert.h are different"
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
/*
*@brief This function sends an ICLC frame with the given payload.
*@details This function sends an ICLC frame with the given payload.
*
*@param[in]  pxLfastBase - LFAST base pointer.
*@param[in]  EnableArbiter - true->enable rx, false->disable rx.
*@param[in]  Timeout - Cycles allowed for the synchronization to complete.
*A value of zero passed for the timeout parameter is disregarded by the
* @return Zipwire_Ip_StatusType.
*@retval ZIPWIRE_IP_STATUS_TIMEOUT Timeout for synchronizing between master and slave.
*@retval ZIPWIRE_IP_STATUS_SUCCESS Synchronized successfully.
*
*@api
*
*
*@note Service ID: 0x00.
* @note Synchronous, non reentrant function.
*
* */
static Zipwire_Ip_StatusType Zipwire_SendIclcFrame(LFAST_Type * pxLfastBase,
                                                   uint8 IclcPayload,
                                                   uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean frameTransmitted = FALSE;
    Zipwire_Ip_StatusType IclcStatus;

    /* Set the playload and send the frame */
    hwAccZipwireLfast_SetIclcPayload(pxLfastBase, IclcPayload);
    hwAccZipwireLfast_IclcFrameRequest(pxLfastBase);

    /* Wait for ICLC frame transmission to be confirmed */
    do
    {
        frameTransmitted = hwAccZipwireLfast_IclcFrameTransmittedFlag(pxLfastBase);
        tempTimeout--;
    }
    while ((!frameTransmitted) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcFrameTransmittedFlag(pxLfastBase);
        IclcStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        IclcStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return IclcStatus;
}

/**
 * @brief    This function polls the ping response flag to check if slave confirmed it's status.
 * @details  This function polls the ping response flag to check if slave confirmed it's status.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 **/
static Zipwire_Ip_StatusType Zipwire_WaitPingResponse(LFAST_Type * pxLfastBase,
                                                      uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pingResponse = FALSE;
    Zipwire_Ip_StatusType WaitStatus;

    /* Check if the ping response was received */
    do
    {
        pingResponse = hwAccZipwireLfast_IclcPingFrameResponseSuccessfulFlag(pxLfastBase);
        tempTimeout--;
    }
    while ((!pingResponse) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcPingFrameResponseSuccessfulFlag(pxLfastBase);
        WaitStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        WaitStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return WaitStatus;
}

/**
 * @brief    This function polls the master speed mode flag to check whether
 *           high speed mode has been activated for both rx and tx interfaces.
 * @details  This function polls the master speed mode flag to check whether
 *           high speed mode has been activated for both rx and tx interfaces.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 **/
static Zipwire_Ip_StatusType Zipwire_WaitMasterSpeedModeSwitch(const LFAST_Type * pxLfastBase,
                                                               boolean tx,
                                                               uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean speedModeChanged = FALSE;
    Zipwire_Ip_StatusType ModeSwitchStatus;

    /* Wait for the master speed mode change */
    do
    {
        if (tx)
        {
            speedModeChanged = hwAccZipwireLfast_GetTxSpeedMode(pxLfastBase);
        }
        else
        {
            speedModeChanged = hwAccZipwireLfast_GetRxSpeedMode(pxLfastBase);
        }

        tempTimeout--;
    }
    while ((!speedModeChanged) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        ModeSwitchStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        ModeSwitchStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return ModeSwitchStatus;
}

/**
 * @brief    This function launches the master high speed mode initialization.
 * @details  This function launches the master high speed mode initialization
 *           procedure; it follows all the steps needed to synchronize with
 *           the slave in high speed.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_MasterHighSpeedInit(LFAST_Type * pxLfastBase,
                                                         uint32 Timeout)
{
    Zipwire_Ip_StatusType MasterHighSpeedInitStatus;
    uint8 Status;
    uint8 TempStatus = 0x01;
    uint32 tempTimeout = Timeout;
    boolean SpeedModeChange = FALSE;

    /* Enable pll on master side */
    hwAccZipwireLfast_TurnOnPll(pxLfastBase);

    /* Enable pll on slave side (ICLC 0x02) */
    Status = (uint8)Zipwire_SendIclcFrame(pxLfastBase, ZIPWIRE_IP_LFAST_ENABLE_SLAVE_PLL_CMD_U8, Timeout);

    /* Change slave tx speed mode (ICLC 0x80) */
    Status |= (uint8)Zipwire_SendIclcFrame(pxLfastBase, ZIPWIRE_IP_LFAST_CHANGE_SLAVE_TX_SPEED_MODE_CMD_U8, Timeout);

    /* Change slave rx speed mode (ICLC 0x10) */
    Status |= (uint8)Zipwire_SendIclcFrame(pxLfastBase, ZIPWIRE_IP_LFAST_CHANGE_SLAVE_RX_SPEED_MODE_CMD_U8, Timeout);


    /* Disable ICLC frames to write master data rate */
    hwAccZipwireLfast_EnableIclcSequence(pxLfastBase, FALSE);

    /* Change master tx/rx speed mode */
    hwAccZipwireLfast_EnableIclcSpeedModeChange(pxLfastBase, FALSE);
    hwAccZipwireLfast_SetRxSpeedMode(pxLfastBase, LFAST_HIGH_SPEED);
    hwAccZipwireLfast_SetTxSpeedMode(pxLfastBase, LFAST_HIGH_SPEED);

    /* Wait for the master rx speed mode change */
    Status |= (uint8)Zipwire_WaitMasterSpeedModeSwitch(pxLfastBase, FALSE, Timeout);


    /* Wait for the master tx speed mode change */
    Status |= (uint8)Zipwire_WaitMasterSpeedModeSwitch(pxLfastBase, TRUE, Timeout);

    /* Enable ICLC frames to confirm slave status */
    hwAccZipwireLfast_EnableIclcSequence(pxLfastBase, TRUE);

    /* Try to enable slave tx and confirm synchronization */
    while ((!SpeedModeChange) && ((Timeout == 0U) || (tempTimeout > 0U)))
    {
        tempTimeout--;
        /* Enable tx arbitrer */
        hwAccZipwireLfast_EnableTxArbitrer(pxLfastBase, TRUE);

        /* Check slave status (ICLC 0x00) */
        hwAccZipwireLfast_SetIclcPayload(pxLfastBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD_U8);
        Status |= (uint8)Zipwire_SendIclcFrame(pxLfastBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD_U8, Timeout);

        if (Status == (uint8)ZIPWIRE_IP_STATUS_SUCCESS)
        {
            /* Disable tx arbitrer */
            hwAccZipwireLfast_EnableTxArbitrer(pxLfastBase, FALSE);

            /* Slave speed mode change confirmed by successful ping response */
            TempStatus = (uint8)Zipwire_WaitPingResponse(pxLfastBase, Timeout);
            if (TempStatus == (uint8)ZIPWIRE_IP_STATUS_SUCCESS)
            {
                SpeedModeChange = TRUE;
            }
        }
    }

    Status |= TempStatus;
    
    /* Disable ICLC frames */
    hwAccZipwireLfast_EnableIclcSequence(pxLfastBase, FALSE);

    /* Enable tx arbitrer */
    hwAccZipwireLfast_EnableTxArbitrer(pxLfastBase, TRUE);

    if (Status == (uint8)ZIPWIRE_IP_STATUS_SUCCESS)
    {
        MasterHighSpeedInitStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        MasterHighSpeedInitStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return MasterHighSpeedInitStatus;
}

/**
 * @brief    This function launches the master high speed mode initialization.
 * @details  This function launches the master high speed mode initialization
 *           procedure; it follows all the steps needed to synchronize with
 *           the slave in high speed.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitSlaveTxEnable(const LFAST_Type * pxLfastBase,
                                                       uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean txEnabled = FALSE;
    Zipwire_Ip_StatusType SlaveTxStatus;

    /* Wait for tx to be enabled through ICLC frame from master */
    do
    {
        txEnabled = hwAccZipwireLfast_IsTxEnabled(pxLfastBase);
        tempTimeout--;
    }
    while ((!txEnabled) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        SlaveTxStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        SlaveTxStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return SlaveTxStatus;
}

/**
 * @brief    This function polls the ping request flag.
 * @details  This function polls the ping request flag. If a ping request
 *           is received from the master, the automatic response will
 *           confirm slave status.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitPingRequest(LFAST_Type * pxLfastBase,
                                                     uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pingRequestReceived = FALSE;
    Zipwire_Ip_StatusType PingStatus;

    /* Wait for ping request; automatic response will confirm slave status */
    do
    {
        pingRequestReceived = hwAccZipwireLfast_IclcPingFrameRequestReceivedFlag(pxLfastBase);
        tempTimeout--;
    }
    while ((!pingRequestReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcPingFrameRequestReceivedFlag(pxLfastBase);
        PingStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        PingStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return PingStatus;
}

/**
 * @brief    This function checks whether the command to turn on the PLL was received from the master.
 * @details  This function checks whether the command to turn on the PLL was received from the master.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitPllOnCommand(LFAST_Type * pxLfastBase,
                                                      uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pllOnCmdReceived = FALSE;
    Zipwire_Ip_StatusType WaitPllOnCommandStatus;

    /* Wait for PLL start request */
    do
    {
        pllOnCmdReceived = hwAccZipwireLfast_IclcPllOnReceivedFlag(pxLfastBase);
        tempTimeout--;
    }
    while ((!pllOnCmdReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcPllOnReceivedFlag(pxLfastBase);
        WaitPllOnCommandStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        WaitPllOnCommandStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return WaitPllOnCommandStatus;
}

/**
 * @brief    This function polls the PLL active flag, so no other operation is done until the PLL is stable.
 * @details  This function polls the PLL active flag, so no other operation is done until the PLL is stable.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitPllActive(const LFAST_Type * pxLfastBase,
                                                   uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pllActive = FALSE;
    Zipwire_Ip_StatusType WaitPllActiveStatus;

    /* Wait for PLL disable signal to be negated */
    do
    {
        pllActive = hwAccZipwireLfast_PllActive(pxLfastBase);
        tempTimeout--;
    }
    while ((!pllActive) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        WaitPllActiveStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        WaitPllActiveStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return WaitPllActiveStatus;
}

/**
 * @brief    This function waits for the PLL locked flag to be asserted.
 * @details  This function waits for the PLL locked flag to be asserted.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitPllLock(const LFAST_Type * pxLfastBase,
                                                 uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean pllLocked = FALSE;
    Zipwire_Ip_StatusType WaitPllLockStatus;

    /* Wait for PLL to lock. */
    do
    {
        pllLocked = hwAccZipwireLfast_PllLocked(pxLfastBase);
        tempTimeout--;
    }
    while ((!pllLocked) && ((Timeout == 0U) || (tempTimeout > 0U)));

    /* Check if the operation has timed out */
    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        WaitPllLockStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        WaitPllLockStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return WaitPllLockStatus;
}

/**
 * @brief    This function waits for the tx speed mode change command to be received from the master.
 * @details  This function waits for the tx speed mode change command to be received from the master.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitTxSpeedModeChange(LFAST_Type * pxLfastBase,
                                                           uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean txFastModeCmdReceived = FALSE;
    Zipwire_Ip_StatusType WaitTxSpeedModeChangeStatus;
    /* Speed of Tx interface is changed by receiving a ICLC frame with 0x80 payload */
    do
    {
        txFastModeCmdReceived = hwAccZipwireLfast_IclcSlaveTxFastModeReceivedFlag(pxLfastBase);
        tempTimeout--;
    }
    while((!txFastModeCmdReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcSlaveTxFastModeReceivedFlag(pxLfastBase);
        WaitTxSpeedModeChangeStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        WaitTxSpeedModeChangeStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return WaitTxSpeedModeChangeStatus;
}

/**
 * @brief    This function waits for the rx speed mode change command to be received from the master.
 * @details  This function waits for the rx speed mode change command to be received from the master.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_WaitRxSpeedModeChange(LFAST_Type * pxLfastBase,
                                                           uint32 Timeout)
{
    uint32 tempTimeout = Timeout;
    boolean rxFastModeCmdReceived = FALSE;
    Zipwire_Ip_StatusType WaitRxSpeedModeChangeStatus;
    /* Speed of Rx interface is changed by receiving a ICLC frame with 0x10 payload */
    do
    {
        rxFastModeCmdReceived = hwAccZipwireLfast_IclcSlaveRxFastModeReceivedFlag(pxLfastBase);
        tempTimeout--;
    }
    while((!rxFastModeCmdReceived) && ((Timeout == 0U) || (tempTimeout > 0U)));

    if ((Timeout == 0U) || (tempTimeout > 0U))
    {
        hwAccZipwireLfast_ClearIclcSlaveRxFastModeReceivedFlag(pxLfastBase);
        WaitRxSpeedModeChangeStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        WaitRxSpeedModeChangeStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return WaitRxSpeedModeChangeStatus;
}

/**
 * @brief    This function launches the slave high speed mode initialization procedure.
 * @details  This function launches the slave high speed mode initialization
 *           procedure. It follows all the steps needed to synchronize with
 *           the master in high speed.
 *
 * @param[in]  pxLfastBase          - LFAST base pointer.
 * @param[in]  Timeout                - Cycles allowed for the synchronization to complete.
 *                                      A value of zero passed for the timeout parameter is disregarded by the
 * @return     Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
*/
static Zipwire_Ip_StatusType Zipwire_SlaveHighSpeedInit(LFAST_Type * pxLfastBase,
                                                        uint32 Timeout)
{
    Zipwire_Ip_StatusType SlaveHighSpeedInitStatus;
    uint8 Status;

    /* Wait for PLL start request */
    Status = (uint8)Zipwire_WaitPllOnCommand(pxLfastBase, Timeout);

    /* Wait for PLL to become active. */
    Status |= (uint8)Zipwire_WaitPllActive(pxLfastBase, Timeout);

    /* Wait for PLL to lock. */
    Status |= (uint8)Zipwire_WaitPllLock(pxLfastBase, Timeout);

    /* Speed of Tx interface is changed by receiving a ICLC frame with 0x80 payload */
    Status |= (uint8)Zipwire_WaitTxSpeedModeChange(pxLfastBase, Timeout);

    /* Speed of Rx interface is changed by receiving a ICLC frame with 0x10 payload */
    Status |= (uint8)Zipwire_WaitRxSpeedModeChange(pxLfastBase, Timeout);

    /* Wait for ping request; automatic response will confirm slave status */
    Status |= (uint8)Zipwire_WaitPingRequest(pxLfastBase, Timeout);

    if (Status == (uint8)ZIPWIRE_IP_STATUS_SUCCESS)
    {
        SlaveHighSpeedInitStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        SlaveHighSpeedInitStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }


    return SlaveHighSpeedInitStatus;
}

/*!
 * @brief LFAST Role.
 *
 * Initializes the LFAST Role.
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.
 * @param[in] LfastRole       - Lfast Role Master or Slave.

 * @return      None.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
static void Zipwire_Ip_LfastSetRole(LFAST_Type * pxLfastBase,
                                    const Zipwire_Ip_LfastRole LfastRole)
{
    hwAccZipwireLfast_SetRole(pxLfastBase, LfastRole);

    if (LFAST_MASTER == LfastRole)
    {
        /* Enable CTSEN */
        hwAccZipwireLfast_EnableCtsen(pxLfastBase, TRUE);
    }
}

/*!
 * @brief LFAST Enable Transmission.
 *
 * Initializes the LFAST TX interface.
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.

 * @return      None.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
static void Zipwire_Ip_EnableTransmission(LFAST_Type * pxLfastBase)
{
    /* Enable transmitter */
    hwAccZipwireLfast_EnableTx(pxLfastBase, TRUE);

    /* Enable ICLC frames */
    hwAccZipwireLfast_EnableIclcSequence(pxLfastBase, TRUE);

    /* Enable tx arbiter */
    hwAccZipwireLfast_EnableTxArbitrer(pxLfastBase, TRUE);
}

/*!
 * @brief LFAST Enable Reception.
 *
 * Initializes the LFAST RX interface.
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.

 * @return      None.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
static void Zipwire_Ip_EnableReception(LFAST_Type * pxLfastBase)
{
#ifdef ERR_IPV_ZIPWIRE_E051988
    /* Enable transmitter */
    hwAccZipwireLfast_EnableTx(pxLfastBase, TRUE);
#endif
    
    /* Enable speed mode change upon ICLC frames reception */
    hwAccZipwireLfast_EnableIclcSpeedModeChange(pxLfastBase, TRUE);

    /* Enable automatic ping response */
    hwAccZipwireLfast_EnableAutomaticPingResponse(pxLfastBase, TRUE);
}

/*!
 * @brief LFAST initialization.
 *
 * Initializes the LFAST interface.
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] LfastRole         - Lfast Role Master or Slave.

 * @return      None.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
static void Zipwire_Ip_LfastConfigureMcr(LFAST_Type * pxLfastBase,
                                         Zipwire_Ip_LfastLowSpeedClk LowSpeedClkDiv,
                                         Zipwire_Ip_LfastRole LfastRole)
{
#ifdef ERR_IPV_ZIPWIRE_E051988
    uint32 Timeout = ZIPWIRE_IP_HARDWARE_RESET_TIMEOUT_U32;
#endif
    Zipwire_Ip_LfastSetRole(pxLfastBase, LfastRole);

    /* Enable data frames */
    hwAccZipwireLfast_EnableData(pxLfastBase, TRUE);

    /* Enable LFAST module */
    hwAccZipwireLfast_EnableLfast(pxLfastBase, TRUE);

    /* Select low speed clock input */
    hwAccZipwireLfast_SetLowSpeedClk(pxLfastBase, LowSpeedClkDiv);

#ifdef ERR_IPV_ZIPWIRE_E051988
    if (LfastRole == LFAST_MASTER)
    {   
        Zipwire_Ip_EnableTransmission(pxLfastBase);

        /* Enable receiver */
        hwAccZipwireLfast_EnableRx(pxLfastBase, TRUE);
    }
    else
    {
        Zipwire_Ip_EnableReception(pxLfastBase);
        
        /* Enable receiver */
        hwAccZipwireLfast_EnableRx(pxLfastBase, TRUE);
    }

#if (STD_ON == ZIPWIRE_IP_LFAST_LCR_LVTXOE_MASK)
    /* Clears LVDS receiver pad fault */
    do 
    {
        Timeout--;
        hwAccZipwireLfast_ClearDCM_GPR_LVDS();
    }
    while((hwAccZipwireLfast_CheckDCM_GPR_LVDS()) && (Timeout > 0U));

#endif
#else
    /* Enable receiver */
    hwAccZipwireLfast_EnableRx(pxLfastBase, TRUE);

    if (LfastRole == LFAST_MASTER)
    {   
        Zipwire_Ip_EnableTransmission(pxLfastBase);
    }
    else
    {
        Zipwire_Ip_EnableReception(pxLfastBase);
    }
#endif
}

/*!
 * @brief LFAST initialization.
 *
 * Initializes the LFAST interface.
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] LfastRole         - Lfast Role Master or Slave.

 * @return      None.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
static void Zipwire_Ip_LfastInit(LFAST_Type * pxLfastBase, const Zipwire_Ip_LfastChannelConfigType *LfastConfig)
{
    /* Soft reset LFAST interface */
    hwAccZipwireLfast_Reset(pxLfastBase);

    ZIPWIRE_IP_DEV_ASSERT(ZIPWIRE_IP_LFAST_RATE_CHANGE_DELAY_U8 <= 0xFU);
    hwAccZipwireLfast_SetRateChangeDelay(pxLfastBase, ZIPWIRE_IP_LFAST_RATE_CHANGE_DELAY_U8);

    /* Configure LFAST PLL */
    hwAccZipwireLfast_SetPllReferenceDivisionFactor(pxLfastBase, LfastConfig->PreDiv);
    hwAccZipwireLfast_SetPllFeedbackDivisionFactor(pxLfastBase, LfastConfig->FeedbackDiv);

#if (STD_ON == ZIPWIRE_IP_LFAST_LCR_LVTXOE_MASK)
    /* Configure LCR interface */
    hwAccZipwireLfast_ConfigureLCR(pxLfastBase);
    hwAccZipwireLfast_ConfigureDCM_GPR(TRUE);
    hwAccZipwireLfast_ConfigureLFAST_GPR(pxLfastBase, TRUE);
#endif
}

#if (STD_ON == ZIPWIRE_IP_LOOPBACK_MODE)
/*!
 * @brief LFAST Loopback initialization.
 *
 * Initializes the LFAST Loopback master interface
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.
 * @param[in] PllClkDiv         - LFAST PLL reference clock divider.
 * @param[in] SpeedMode         - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout           - Cycles allowed for the synchronization to complete.
 *                                A value of zero passed for the timeout parameter is disregarded by the
 *                                driver; the master will wait forever for the responses from the slave.
 * @param[in] Attempts          - Number of Attempts for the master to synchronize with the slave;
 *                                A value of zero for this parameter is equivalent to an infinite
 *                                number of Attempts; the LFAST master will wait forever for the
 *                                slave to confirm it's status.
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_InitLfastLoopback(LFAST_Type *pxLfastBase,
                                                   const Zipwire_Ip_LfastChannelConfigType *LfastConfig)
{
    Zipwire_Ip_StatusType LoopbackStatus = ZIPWIRE_IP_STATUS_ERROR;
    uint32 tempTimeout = LfastConfig->SyncTimeout;
    boolean CheckLoopbackTransfer = FALSE;

    /* Initialize LFAST Master */
    Zipwire_Ip_LfastInit(pxLfastBase, LfastConfig);

    /* Configure LFAST MCR */
    Zipwire_Ip_LfastConfigureMcr(pxLfastBase, LfastConfig->LowSpeedClkDiv, LFAST_MASTER);

    /* Disable ICLC frames */
    hwAccZipwireLfast_EnableIclcSequence(pxLfastBase, FALSE);

    /* Set loopback mode */
    hwAccZipwireLfast_LoopbackMode(pxLfastBase, (uint8)LfastConfig->LoopbackMode);

    /* Set the number of succesfull transimissions */
    hwAccZipwireLfast_LoopbackCounter(pxLfastBase, 0x01U);

    /* Enable Loopback Mode */
    hwAccZipwireLfast_EnableLoopback(pxLfastBase, TRUE);

    if((LFAST_TX_AUTOMATIC_LVDS_LOOPBACK == LfastConfig->LoopbackMode)||(LFAST_TX_AUTOMATIC_LOOPBACK == LfastConfig->LoopbackMode))
    {
        /* Wait for Loopback Counter */
        do
        {
            CheckLoopbackTransfer = hwAccZipwireLfast_CheckLoopbackTransfer(pxLfastBase);
            tempTimeout--;
        }
        while ((!CheckLoopbackTransfer) && (tempTimeout > 0U));

        if (TRUE == CheckLoopbackTransfer)
        {
            LoopbackStatus = ZIPWIRE_IP_STATUS_SUCCESS;  
        }
    }
    else
    {
        LoopbackStatus = ZIPWIRE_IP_STATUS_SUCCESS;  
    }

    hwAccZipwireLfast_EnableLoopback(pxLfastBase, FALSE);
    return LoopbackStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_LOOPBACK_MODE) */

/*!
 * @brief LFAST Master initialization.
 *
 * Initializes the LFAST master interface
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.
 * @param[in] PllClkDiv         - LFAST PLL reference clock divider.
 * @param[in] SpeedMode         - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout           - Cycles allowed for the synchronization to complete.
 *                                A value of zero passed for the timeout parameter is disregarded by the
 *                                driver; the master will wait forever for the responses from the slave.
 * @param[in] Attempts          - Number of Attempts for the master to synchronize with the slave;
 *                                A value of zero for this parameter is equivalent to an infinite
 *                                number of Attempts; the LFAST master will wait forever for the
 *                                slave to confirm it's status.
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_MasterInit(LFAST_Type *pxLfastBase,
                                            const Zipwire_Ip_LfastChannelConfigType *LfastConfig)
{
    uint32 tempAttempts = LfastConfig->SyncAttempts;
    boolean slaveTxConfirmed = FALSE;
    Zipwire_Ip_StatusType MasterStatus = ZIPWIRE_IP_STATUS_SUCCESS;

    /* Initialize LFAST Master */
    Zipwire_Ip_LfastInit(pxLfastBase, LfastConfig);

    /* Configure LFAST MCR */
    Zipwire_Ip_LfastConfigureMcr(pxLfastBase, LfastConfig->LowSpeedClkDiv, LFAST_MASTER);
#ifdef ERR_IPV_ZIPWIRE_E051988
    /* Try to enable slave tx and confirm synchronization */
    while ((!slaveTxConfirmed) && ((LfastConfig->SyncAttempts == 0U) || (tempAttempts > 0U)))
    {
        tempAttempts--;

        /* Check slave status (ICLC 0x00) */
        hwAccZipwireLfast_SetIclcPayload(pxLfastBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD_U8);
        MasterStatus = Zipwire_SendIclcFrame(pxLfastBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD_U8, LfastConfig->SyncTimeout);
        if (MasterStatus == ZIPWIRE_IP_STATUS_SUCCESS)
        {
            /* Slave status confirmed by successful ping response */
            MasterStatus = Zipwire_WaitPingResponse(pxLfastBase, LfastConfig->SyncTimeout);
            if (MasterStatus == ZIPWIRE_IP_STATUS_SUCCESS)
            {
                slaveTxConfirmed = TRUE;
            }
        }
    }
#else
    /* Try to enable slave tx and confirm synchronization */
    while ((!slaveTxConfirmed) && ((LfastConfig->SyncAttempts == 0U) || (tempAttempts > 0U)))
    {
        tempAttempts--;

        /* Enable slave tx interface (ICLC 0x31) */
        MasterStatus = Zipwire_SendIclcFrame(pxLfastBase, ZIPWIRE_IP_LFAST_ENABLE_SLAVE_TX_CMD_U8, LfastConfig->SyncTimeout); 
        if (MasterStatus == ZIPWIRE_IP_STATUS_SUCCESS)
        {
            /* Check slave status (ICLC 0x00) */
            hwAccZipwireLfast_SetIclcPayload(pxLfastBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD_U8);
            MasterStatus = Zipwire_SendIclcFrame(pxLfastBase, ZIPWIRE_IP_LFAST_CHECK_SLAVE_STATUS_CMD_U8, LfastConfig->SyncTimeout);
            if (MasterStatus == ZIPWIRE_IP_STATUS_SUCCESS)
            {
                /* Slave status confirmed by successful ping response */
                MasterStatus = Zipwire_WaitPingResponse(pxLfastBase, LfastConfig->SyncTimeout);
                if (MasterStatus == ZIPWIRE_IP_STATUS_SUCCESS)
                {
                    slaveTxConfirmed = TRUE;
                }
            }
        }
    }
#endif
    /* Return TIMEOUT if slave status is not confirmed by ping response
     * and the maximum number of Attempts has been reached */
    if (slaveTxConfirmed == TRUE)
    {
        /* Speed mode change */
        if (LfastConfig->SpeedMode == LFAST_HIGH_SPEED)
        {
            MasterStatus = Zipwire_MasterHighSpeedInit(pxLfastBase, LfastConfig->SyncTimeout);
        }
        else
        {
            /* Disable ICLC frames */
            hwAccZipwireLfast_EnableIclcSequence(pxLfastBase, FALSE);
        }
    }
    else
    {
        MasterStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return MasterStatus;
}


/*!
 * @brief LFAST Slave initialization.
 *
 * Initializes the LFAST slave interface
 *
 * @param[in] pxLfastBase     - LFAST pxLfastBase pointer.
 * @param[in] PllClkDiv         - LFAST PLL reference clock divider.
 * @param[in] SpeedMode         - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout           - cycles allowed for the synchronization to complete.
 *                                A value of zero passed for the timeout parameter is disregarded by the
 *                                driver; the slave will wait forever for the commands from the master.
 * @return      Zipwire_Ip_StatusType.
 * @retval ZIPWIRE_IP_STATUS_TIMEOUT         Timeout for synchronizing between master and slave.
 * @retval ZIPWIRE_IP_STATUS_SUCCESS         Synchronized successfully.
 *
 * @api
 *
 *
 * @note    Service ID: 0x00.
 * @note    Synchronous, non reentrant function.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_SlaveInit(LFAST_Type *pxLfastBase,
                                           const Zipwire_Ip_LfastChannelConfigType *LfastConfig)
{
    Zipwire_Ip_StatusType SlaveStatus;

    /* Initialize LFAST Master */
    Zipwire_Ip_LfastInit(pxLfastBase, LfastConfig);

    /* Configure LFAST MCR */
    Zipwire_Ip_LfastConfigureMcr(pxLfastBase, LfastConfig->LowSpeedClkDiv, LFAST_SLAVE);

    /* Wait for tx to be enabled through ICLC frame from master */
    SlaveStatus = Zipwire_WaitSlaveTxEnable(pxLfastBase, LfastConfig->SyncTimeout);
    if (SlaveStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        /* Enable tx arbitrer */
        hwAccZipwireLfast_EnableTxArbitrer(pxLfastBase, TRUE);

        /* Wait for ping request; automatic response will confirm slave status */
        SlaveStatus = Zipwire_WaitPingRequest(pxLfastBase, LfastConfig->SyncTimeout);
        if (SlaveStatus == ZIPWIRE_IP_STATUS_SUCCESS)
        {
            /* Speed mode change */
            if (LfastConfig->SpeedMode == LFAST_HIGH_SPEED)
            {
                SlaveStatus = Zipwire_SlaveHighSpeedInit(pxLfastBase, LfastConfig->SyncTimeout);
            }
        }
    }

    return SlaveStatus;
}

#ifdef _cplusplus
}
#endif

/** @} */
