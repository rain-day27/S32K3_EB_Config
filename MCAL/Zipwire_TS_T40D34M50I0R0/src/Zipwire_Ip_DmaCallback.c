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
*   @file    Zipwire_Ip_DmaCallback.c
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

#include "Zipwire_Ip_Cfg.h"
#include "Zipwire_Ip_DmaCallback.h"
#include "Zipwire_Ip.h"

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)

#include "Dma_Ip.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ZIPWIRE_IP_DMA_CALLBACK_VENDOR_ID_C                   43
#define ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MAJOR_VERSION_C    4
#define ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MINOR_VERSION_C    7
#define ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_REVISION_VERSION_C 0
#define ZIPWIRE_IP_DMA_CALLBACK_SW_MAJOR_VERSION_C            5
#define ZIPWIRE_IP_DMA_CALLBACK_SW_MINOR_VERSION_C            0
#define ZIPWIRE_IP_DMA_CALLBACK_SW_PATCH_VERSION_C            0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Zipwire_Ip_DmaCallback.c file and Zipwire_Ip_Cfg.h file are of the same vendor */
#if (ZIPWIRE_IP_DMA_CALLBACK_VENDOR_ID_C != ZIPWIRE_IP_CFG_VENDOR_ID)
#error "Zipwire_Ip_DmaCallback.c and Zipwire_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_DmaCallback.c file and Zipwire_Ip_Cfg.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_DmaCallback.c and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip_DmaCallback.c file and Zipwire_Ip_Cfg.h file are of the same Software version */
#if ((ZIPWIRE_IP_DMA_CALLBACK_SW_MAJOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_SW_MINOR_VERSION_C != ZIPWIRE_IP_CFG_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_SW_PATCH_VERSION_C != ZIPWIRE_IP_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Zipwire_Ip_DmaCallback.c and Zipwire_Ip_Cfg.h are different"
#endif

/* Check if Zipwire_Ip_DmaCallback.c file and Zipwire_Ip_DmaCallback.h file are of the same vendor */
#if (ZIPWIRE_IP_DMA_CALLBACK_VENDOR_ID_C != ZIPWIRE_IP_DMA_CALLBACK_VENDOR_ID)
#error "Zipwire_Ip_DmaCallback.c and Zipwire_Ip_DmaCallback.h have different vendor ids"
#endif

/* Check if Zipwire_Ip_DmaCallback.c file and Zipwire_Ip_DmaCallback.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_DMA_CALLBACK_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_DmaCallback.c and Zipwire_Ip_DmaCallback.h are different"
#endif

/* Check if Zipwire_Ip_DmaCallback.c file and Zipwire_Ip_DmaCallback.h file are of the same Software version */
#if ((ZIPWIRE_IP_DMA_CALLBACK_SW_MAJOR_VERSION_C != ZIPWIRE_IP_DMA_CALLBACK_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_SW_MINOR_VERSION_C != ZIPWIRE_IP_DMA_CALLBACK_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_DMA_CALLBACK_SW_PATCH_VERSION_C != ZIPWIRE_IP_DMA_CALLBACK_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Zipwire_Ip_DmaCallback.c and Zipwire_Ip_DmaCallback.h are different"
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

#if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED)
void Zipwire_Ip_Instance0_Channel0_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_0);
}

void Zipwire_Ip_Instance0_Channel1_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_1);
}

void Zipwire_Ip_Instance0_Channel2_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_2);
}

void Zipwire_Ip_Instance0_Channel3_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_0, ZIPWIRE_LOGIC_CHANNEL_3);
}

#endif /* #if (STD_ON == ZIPWIRE_IP_INSTANCE_0_DEFINED) */


#if (STD_ON == ZIPWIRE_IP_INSTANCE_1_DEFINED)
void Zipwire_Ip_Instance1_Channel0_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_0);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_0);
}

void Zipwire_Ip_Instance1_Channel1_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_1);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_1);
}

void Zipwire_Ip_Instance1_Channel2_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_2);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_2);
}

void Zipwire_Ip_Instance1_Channel3_DmaCallback(void)
{
    Zipwire_Ip_ChannelState ChannelState;
    ChannelState = Zipwire_Ip_GetChannelState(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_3);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaDataChn, &Zipwire_Ip_xDmaChStatusData);
    (void)Dma_Ip_GetLogicChannelStatus(ChannelState.DmaAddrChn, &Zipwire_Ip_xDmaChStatusAddress);
    Zipwire_Ip_DmaCallback(ZIPWIRE_LOGIC_INSTANCE_1, ZIPWIRE_LOGIC_CHANNEL_3);
}

#endif /* #if (STD_ON == ZIPWIRE_IP_INSTANCE_1_DEFINED) */

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */
#ifdef __cplusplus
}
#endif

/** @} */
