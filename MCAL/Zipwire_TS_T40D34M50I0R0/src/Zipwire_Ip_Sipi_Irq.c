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
*   @file    Zipwire_Ip_Sipi_Irq.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Zipwire - Zipwire Ip driver source file.
*   @details
*
*   @addtogroup ZIPWIRE_IP_DRIVER ZIPWIRE IP Driver
*   @{
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Zipwire_Ip_Sipi_Irq.h"
#include "Zipwire_Ip_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID_C                   43
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION_C    4
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION_C    7
#define ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION_C 0
#define ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION_C            5
#define ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION_C            0
#define ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION_C            0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Cfg.h file are of the same vendor */
#if (ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID_C != ZIPWIRE_IP_CFG_VENDOR_ID)
#error "Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Cfg.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Cfg.h file are of the same Software version */
#if ((ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION_C != ZIPWIRE_IP_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Irq.h file are of the same vendor */
#if (ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID_C != ZIPWIRE_IP_SIPI_IRQ_VENDOR_ID)
#error "Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Irq.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Irq.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Irq.h are different"
#endif

/* Check if Zipwire_Ip_Sipi_Irq.c file and Zipwire_Ip_Sipi_Irq.h file are of the same Software version */
#if ((ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION_C != ZIPWIRE_IP_SIPI_IRQ_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Zipwire_Ip_Sipi_Irq.c and Zipwire_Ip_Sipi_Irq.h are different"
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
#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

/* INSTANCE 0 IRQ */
#if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED)
#if (STD_ON == ZIPWIRE_IP_ORED_IRQ_LINES)
/* SIPI irq handler */

static void Zipwire_Ip_Sipi0_ClearFlag(void)
{
    /**** CHANNELS READ/ACK INTERRUPTS ****/
    /* Clear flag channel 0 ack or read answer received */
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_READ_ANSWER_FLAG);
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_ACK_FLAG);

    /* Clear flag channel 1 ack or read answer received */
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_READ_ANSWER_FLAG);
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_ACK_FLAG);

    /* Clear flag channel 2 ack or read answer received */
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_READ_ANSWER_FLAG);
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_ACK_FLAG);

    /* Clear flag channel 3 ack or read answer received */
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_READ_ANSWER_FLAG);
    hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_ACK_FLAG);

    /**** CHANNELS ERROR INTERRUPTS ****/
    /* Clear flag channel 0 Timeout Transaction Id and Ack Errors */
    hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);
    hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);
    hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);

    /* Clear flag channel 1 Timeout Transaction Id and Ack Errors */
    hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);
    hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);
    hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);

    /* Clear flag channel 2 Timeout Transaction Id and Ack Errors */
    hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);
    hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);
    hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);

    /* Clear flag channel 3 Timeout Transaction Id and Ack Errors */
    hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);
    hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);
    hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);

    /**** GLOBAL CRC ERROR INTERRUPT ****/
    /* Clear flag CRC Errors */
    hwAccZipwireSipi_ClearGlobalCrcErrFlag(IP_SIPI_0);

    /**** TRIGGER OR MAX COUNT REACHED INTERRUPT ****/
    /* Clear flag Max Count Reached Errors */
    hwAccZipwireSipi_ClearMaxCountReachedFlag(IP_SIPI_0);

    /* Clear flag channel 0 Trigger Event */
    hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);

    /* Clear flag channel 1 Trigger Event */
    hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);

    /* Clear flag channel 2 Trigger Event */
    hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);

    /* Clear flag channel 3 Trigger Event */
    hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);
}

void Zipwire_Ip_Sipi0_IRQHandler(void)
{
    if(ZipwireIpInitState[0] == ZIPWIRE_INIT)
    {
        uint32 SipiRarAckrMask = SIPI1_CSR0_RAR_MASK | SIPI1_CSR0_ACKR_MASK;
        
        /**** CHANNELS READ/ACK INTERRUPTS ****/
        /* Check channel 0 */
        if ((IP_SIPI_0->CSR0 & SipiRarAckrMask) > 0U)
        {
            Zipwire_Ip_Sipi0_Ch0ResponseOrAckIRQHandler();
        }

        /* Check channel 1 */
        if ((IP_SIPI_0->CSR1 & SipiRarAckrMask) > 0U)
        {
            Zipwire_Ip_Sipi0_Ch1ResponseOrAckIRQHandler();
        }

        /* Check channel 2 */
        if ((IP_SIPI_0->CSR2 & SipiRarAckrMask) > 0U)
        {
            Zipwire_Ip_Sipi0_Ch2ResponseOrAckIRQHandler();
        }

        /* Check channel 3 */
        if ((IP_SIPI_0->CSR3 & SipiRarAckrMask) > 0U)
        {
            Zipwire_Ip_Sipi0_Ch3ResponseOrAckIRQHandler();
        }

        /**** CHANNELS ERROR INTERRUPTS ****/
        if (IP_SIPI_0->ERR > 0U)
        {
            Zipwire_Ip_Sipi0_ErrorIRQHandler();
        }

        /**** GLOBAL CRC ERROR INTERRUPT ****/
        if (hwAccZipwireSipi_IsCrcErrIntEnabled(IP_SIPI_0))
        {
            if ((IP_SIPI_0->SR & SIPI1_SR_GCRCE_MASK) > 0U)
            {
                hwAccZipwireSipi_ClearGlobalCrcErrFlag(IP_SIPI_0);
                Zipwire_Ip_Sipi_CrcErrHandler(ZIPWIRE_LOGIC_INSTANCE_0);
            }
        }

        /**** TRIGGER OR MAX COUNT REACHED INTERRUPT ****/
        Zipwire_Ip_Sipi0_TriggerIRQHandler();
        Zipwire_Ip_Sipi0_MaxCountReachedIRQHandler();
    }
    else
    {
        Zipwire_Ip_Sipi0_ClearFlag();
    }
}

#endif /* #if (STD_ON == ZIPWIRE_IP_ORED_IRQ_LINES) */

void Zipwire_Ip_Sipi0_Channel0IRQHandler(void)
{
    /* Timeout error channel 0 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_TIMEOUT_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0))
        {
            hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);
            Zipwire_Ip_Sipi_ChnTimeoutErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
        }
    }

    /* Transaction ID error channel 0 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_TRANS_ID_ERR_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0))
        {
            hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);
            Zipwire_Ip_Sipi_ChnTransIdErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
        }
    }

    /* ACK error channel 0 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_ACK_ERR_IRQ))
    {
        if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0))
        {
            hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);
            Zipwire_Ip_Sipi_ChnAckErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
        }
    }
}

void Zipwire_Ip_Sipi0_Channel1IRQHandler(void)
{
    /* Timeout error channel 1 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_TIMEOUT_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1))
        {
            hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);
            Zipwire_Ip_Sipi_ChnTimeoutErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
        }
    }

    /* Transaction ID error channel 1 */
    if ((hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_TRANS_ID_ERR_IRQ)))
    {
        if ((hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1)))
        {
            hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);
            Zipwire_Ip_Sipi_ChnTransIdErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
        }
    }

    /* ACK error channel 1 */
    if ((hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_ACK_ERR_IRQ)))
    {
        if ((hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1)))
        {
            hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);
            Zipwire_Ip_Sipi_ChnAckErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
        }
    }
}

void Zipwire_Ip_Sipi0_Channel2IRQHandler(void)
{
    /* Timeout error channel 2 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_TIMEOUT_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2))
        {
            hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);
            Zipwire_Ip_Sipi_ChnTimeoutErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
        }
    }

    /* Transaction ID error channel 2 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_TRANS_ID_ERR_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2))
        {
            hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);
            Zipwire_Ip_Sipi_ChnTransIdErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
        }
    }

    /* ACK error channel 2 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_ACK_ERR_IRQ))
    {
        if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2))
        {
            hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);
            Zipwire_Ip_Sipi_ChnAckErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
        }
    }
}

void Zipwire_Ip_Sipi0_Channel3IRQHandler(void)
{
    /* Timeout error channel 3 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_TIMEOUT_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3))
        {
            hwAccZipwireSipi_ClearChnTimeoutErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);
            Zipwire_Ip_Sipi_ChnTimeoutErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
        }
    }

    /* Transaction ID error channel 3 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_TRANS_ID_ERR_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3))
        {
            hwAccZipwireSipi_ClearChnTransactionIdErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);
            Zipwire_Ip_Sipi_ChnTransIdErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
        }
    }

    /* ACK error channel 3 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_ACK_ERR_IRQ))
    {
        if (hwAccZipwireSipi_GetChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3))
        {
            hwAccZipwireSipi_ClearChnAckErrFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);
            Zipwire_Ip_Sipi_ChnAckErrHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
        }
    }
}

/* SIPI channel error irq handler */
void Zipwire_Ip_Sipi0_ErrorIRQHandler(void)
{
    /* Check channel 0 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH0_ERR_MASK_U8) != 0U)
    {
        Zipwire_Ip_Sipi0_Channel0IRQHandler();
    }

    /* Check channel 1 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH1_ERR_MASK_U16) != 0U)
    {
        Zipwire_Ip_Sipi0_Channel1IRQHandler();
    }

    /* Check channel 2 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH2_ERR_MASK_U32) != 0U)
    {
        Zipwire_Ip_Sipi0_Channel2IRQHandler();
    }

    /* Check channel 3 */
    if ((IP_SIPI_0->ERR & ZIPWIRE_IP_SIPI_CH3_ERR_MASK_U32) != 0U)
    {
        Zipwire_Ip_Sipi0_Channel3IRQHandler();
    }
}

/* SIPI crc error irq handler */
void Zipwire_Ip_Sipi0_CrcErrorIRQHandler(void)
{
    hwAccZipwireSipi_ClearGlobalCrcErrFlag(IP_SIPI_0);
    Zipwire_Ip_Sipi_CrcErrHandler(ZIPWIRE_LOGIC_INSTANCE_0);
}

/* SIPI channel 0 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch0ResponseOrAckIRQHandler(void)
{
    /* Check channel 0 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
        }
    }

    /* Check channel 0 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_0, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
        }
    }
}

/* SIPI channel 1 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch1ResponseOrAckIRQHandler(void)
{
    /* Check channel 1 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
        }
    }

    /* Check channel 1 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_1, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
        }
    }
}

/* SIPI channel 2 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch2ResponseOrAckIRQHandler(void)
{
    /* Check channel 2 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
        }
    }

    /* Check channel 2 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_2, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
        }
    }
}

/* SIPI channel 3 response or ack irq handler */
void Zipwire_Ip_Sipi0_Ch3ResponseOrAckIRQHandler(void)
{
    /* Check channel 3 read answer received */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_READ_ANSWER_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_READ_ANSWER_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_READ_ANSWER_FLAG);
            Zipwire_Ip_Sipi_ChnReadAnswerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
        }
    }

    /* Check channel 3 ack */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_ACK_IRQ))
    {
        if (hwAccZipwireSipi_GetChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_ACK_FLAG))
        {
            hwAccZipwireSipi_ClearChannelFlag(IP_SIPI0_CHANNEL_3, SIPI_ACK_FLAG);
            Zipwire_Ip_Sipi_ChnAckHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
        }
    }
}

/* SIPI trigger or max count reached irq handler */
void Zipwire_Ip_Sipi0_MaxCountReachedIRQHandler(void)
{
    /* Max count reached */
    if (hwAccZipwireSipi_IsMaxCountReachedIntEnabled(IP_SIPI_0))
    {
        if (hwAccZipwireSipi_GetMaxCountReachedFlag(IP_SIPI_0))
        {
            hwAccZipwireSipi_ClearMaxCountReachedFlag(IP_SIPI_0);
            Zipwire_Ip_Sipi_MaxCountReachedHandler(ZIPWIRE_LOGIC_INSTANCE_0);
        }
    }
}

/* SIPI trigger or max count reached irq handler */
void Zipwire_Ip_Sipi0_TriggerIRQHandler(void)
{
    /* Trigger channel 0 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_0, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_0);
            Zipwire_Ip_Sipi_ChnTriggerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
        }
    }

    /* Trigger channel 1 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_1, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_1);
            Zipwire_Ip_Sipi_ChnTriggerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
        }
    }

    /* Trigger channel 2 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_2, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_2);
            Zipwire_Ip_Sipi_ChnTriggerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
        }
    }

    /* Trigger channel 3 */
    if (hwAccZipwireSipi_IsChannelInterruptEnabled(IP_SIPI0_CHANNEL_3, SIPI_TRIGGER_IRQ))
    {
        if (hwAccZipwireSipi_GetChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3))
        {
            hwAccZipwireSipi_ClearChnTriggerEventFlag(IP_SIPI_0, ZIPWIRE_LOGIC_CHANNEL_3);
            Zipwire_Ip_Sipi_ChnTriggerHandler(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
        }
    }
}

#endif /* #if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED) */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
