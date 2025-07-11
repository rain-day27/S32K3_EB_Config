/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO_SENT_IP
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

#ifndef FLEXIO_SENT_IP_H
#define FLEXIO_SENT_IP_H

/**
*   @file    Flexio_Sent_Ip.h
*   @version 5.0.0
*
*   @brief   AUTOSAR Sent - Low level header of Sent driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup SENT_DRIVER
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
#include "Flexio_Sent_Ip_Types.h"
#include "Flexio_Sent_Ip_HwAccess.h"
#include "OsIf.h"
#ifdef FEATURE_FLEXIO_SENT_DMA_ENABLE
    #if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE)
        #include "Dma_Ip.h"
    #endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SENT_IP_VENDOR_ID                      43
#define FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION       4
#define FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION       7
#define FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION    0
#define FLEXIO_SENT_IP_SW_MAJOR_VERSION               5
#define FLEXIO_SENT_IP_SW_MINOR_VERSION               0
#define FLEXIO_SENT_IP_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_Sent_Ip_Types header file are of the same vendor */
#if (FLEXIO_SENT_IP_VENDOR_ID != FLEXIO_SENT_IP_TYPES_VENDOR_ID)
#endif
/* Check if current file and Flexio_Sent_Ip_Types header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION != FLEXIO_SENT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#endif
/* Check if current file and Flexio_Sent_Ip_Types header file are of the same Software version */
#if ((FLEXIO_SENT_IP_SW_MAJOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MAJOR_VERSION) || \
    (FLEXIO_SENT_IP_SW_MINOR_VERSION != FLEXIO_SENT_IP_TYPES_SW_MINOR_VERSION) || \
    (FLEXIO_SENT_IP_SW_PATCH_VERSION != FLEXIO_SENT_IP_TYPES_SW_PATCH_VERSION)    \
    )
#endif

/* Check if current file and Flexio_Ip_hw_access header file are of the same vendor */
#if (FLEXIO_SENT_IP_VENDOR_ID != FLEXIO_SENT_IP_HWACCESS_VENDOR_ID)
#endif
/* Check if current file and Flexio_Ip_hw_access header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
    (FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_SENT_IP_HWACCESS_AR_RELEASE_REVISION_VERSION) \
    )
#endif
/* Check if current file and Flexio_Ip_hw_access header file are of the same Software version */
#if ((FLEXIO_SENT_IP_SW_MAJOR_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_MAJOR_VERSION) || \
    (FLEXIO_SENT_IP_SW_MINOR_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_MINOR_VERSION) || \
    (FLEXIO_SENT_IP_SW_PATCH_VERSION != FLEXIO_SENT_IP_HWACCESS_SW_PATCH_VERSION)    \
    )
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Sent_Ip.h and OsIf.h are different"
    #endif

    #ifdef FEATURE_FLEXIO_SENT_DMA_ENABLE
        #if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE)
            /* Check if current file and OsIf.h header file are of the same Autosar version */
            #if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
            (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Flexio_Sent_Ip.h and Dma_Ip.h are different"
            #endif
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define FLEXIO_SYNC_CAL_TICK_U32                        ((uint32)56U)
/* FLEXIO_SYNC_CAL_TICK_U32 * 0.75 */
#define FLEXIO_SYNC_CAL_TICK_MIN_U32                    ((uint32)42U)
/* FLEXIO_SYNC_CAL_TICK_U32 * 1.25 */
#define FLEXIO_SYNC_CAL_TICK_MAX_U32                    ((uint32)70U)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*   Timer of FLEXIO IP used for the simulation of the SENT protocol
*/
#define FLEXIO_SENT_TIMER(x)                            (x)

/**
*   SENT SHORT DATA
*/
#define FLEXIO_SENT_SHORT_MSGID_MASK                    (0x0000F000U)
#define FLEXIO_SENT_SHORT_MSGID_SHIFT                   12U
#define FLEXIO_SENT_SHORT_MSGID(x)                      (((uint32)(((uint32)x)&FLEXIO_SENT_SHORT_MSGID_MASK)) >> FLEXIO_SENT_SHORT_MSGID_SHIFT)

#define FLEXIO_SENT_SHORT_DATA_MASK                     (0x00000FF0U)
#define FLEXIO_SENT_SHORT_DATA_SHIFT                    4U
#define FLEXIO_SENT_SHORT_DATA(x)                       (((uint32)(((uint32)x)&FLEXIO_SENT_SHORT_DATA_MASK)) >> FLEXIO_SENT_SHORT_DATA_SHIFT)

#define FLEXIO_SENT_SHORT_CRC_MASK                      (0x0000000FU)
#define FLEXIO_SENT_SHORT_CRC_SHIFT                     0U
#define FLEXIO_SENT_SHORT_CRC(x)                        (((uint32)(((uint32)x)&FLEXIO_SENT_SHORT_CRC_MASK)) >> FLEXIO_SENT_SHORT_CRC_SHIFT)

/**
*   SENT ENHANCED 12 BIT DATA + 8 BIT ID
*/
#define FLEXIO_SENT_ENHANCED8_MSGID74_MASK              (0x000003C0U)
#define FLEXIO_SENT_ENHANCED8_MSGID30_MASK              (0x0000001EU)
#define FLEXIO_SENT_ENHANCED8_MSGID(bit3)               ((((bit3)&FLEXIO_SENT_ENHANCED8_MSGID74_MASK) >> 2U) | (((bit3)&FLEXIO_SENT_ENHANCED8_MSGID30_MASK) >> 1U))

#define FLEXIO_SENT_ENHANCED8_DATA_MASK                 (0x00000FFFU)
#define FLEXIO_SENT_ENHANCED8_DATA_SHIFT                0U
#define FLEXIO_SENT_ENHANCED8_DATA(bit2)                (((uint32)(((uint32)(bit2))&FLEXIO_SENT_ENHANCED8_DATA_MASK)) >> FLEXIO_SENT_ENHANCED8_DATA_SHIFT)

#define FLEXIO_SENT_ENHANCED8_CRC_MASK                  (0x0003F000U)
#define FLEXIO_SENT_ENHANCED8_CRC_SHIFT                 12U
#define FLEXIO_SENT_ENHANCED8_CRC(bit2)                 (((uint32)(((uint32)(bit2))&FLEXIO_SENT_ENHANCED8_CRC_MASK)) >> FLEXIO_SENT_ENHANCED8_CRC_SHIFT)

/**
*   SENT ENHANCED 16 BIT DATA + 4 BIT ID
*/
#define FLEXIO_SENT_ENHANCED4_MSGID_MASK                (0x000003C0U)
#define FLEXIO_SENT_ENHANCED4_MSGID_SHIFT               6U
#define FLEXIO_SENT_ENHANCED4_MSGID(bit3)               (((uint32)(((uint32)bit3)&FLEXIO_SENT_ENHANCED4_MSGID_MASK)) >> FLEXIO_SENT_ENHANCED4_MSGID_SHIFT)

/* Get 4 bit high from Serial Data #BIT3 */
#define FLEXIO_SENT_ENHANCED4_DATA4_MASK                (0x0000001EU)
#define FLEXIO_SENT_ENHANCED4_DATA4_SHIFT               1U
#define FLEXIO_SENT_ENHANCED4_DATA4(bit3)               (((uint32)(((uint32)bit3)&FLEXIO_SENT_ENHANCED4_DATA4_MASK)) >> FLEXIO_SENT_ENHANCED4_DATA4_SHIFT)
/* Get 12 bit low from Serial Data #BIT2 */
#define FLEXIO_SENT_ENHANCED4_DATA12_MASK               (0x00000FFFU)
#define FLEXIO_SENT_ENHANCED4_DATA12_SHIFT              0U
#define FLEXIO_SENT_ENHANCED4_DATA12(bit2)              (((uint32)(((uint32)bit2)&FLEXIO_SENT_ENHANCED4_DATA12_MASK)) >> FLEXIO_SENT_ENHANCED4_DATA12_SHIFT)
/* Get complete 16 bit data */
#define FLEXIO_SENT_ENHANCED4_DATA(bit3, bit2)          ((FLEXIO_SENT_ENHANCED4_DATA4(bit3) << 12) | FLEXIO_SENT_ENHANCED4_DATA12(bit2))

#define FLEXIO_SENT_ENHANCED4_CRC_MASK                  (0x0003F000U)
#define FLEXIO_SENT_ENHANCED4_CRC_SHIFT                 12U
#define FLEXIO_SENT_ENHANCED4_CRC(bit2)                 (((uint32)(((uint32)bit2)&FLEXIO_SENT_ENHANCED4_CRC_MASK)) >> FLEXIO_SENT_ENHANCED4_CRC_SHIFT)

/**
*   Get configuration bit for enhanced data
*/
#define FLEXIO_SENT_ENHANCED_BIT_CONF_MASK              (0x00000400U)
#define FLEXIO_SENT_ENHANCED_BIT_CONF_SHIFT             10U
#define FLEXIO_SENT_ENHANCED_BIT_CONF(bit3)             (((uint32)(((uint32)bit3)&FLEXIO_SENT_ENHANCED_BIT_CONF_MASK)) >> FLEXIO_SENT_ENHANCED_BIT_CONF_SHIFT)

/**
*   Get all #BIT2 from status nibble
*/
#define FLEXIO_SENT_GET_BIT2(x, y)                      (((y) << 1) | (((x) & 0x4U) >> 2))
/**
*   Get all #BIT3 from status nibble
*/
#define FLEXIO_SENT_GET_BIT3(x, y)                      (((y) << 1) | (((x) & 0x8U) >> 3))
/**
*   bit XOR for CRC calculation
*/
#define FLEXIO_SENT_BITXOR(x, y)                        (((uint8)(x)) ^ ((uint8)(y)))
/**
*   Get bit from enhanced serial message to create 24 bit sequence for CRC checking
*   x: BIT serial data
*   y: bit order
*/
#define FLEXIO_SENT_SET_GET_BIT24(x, y)                 ((((x) & (uint32)0xFFF) & ((uint32)0x800 >> (uint32)(y))) >> ((uint8)11 - (y)))

#if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE)
    #define FLEXIO_SENT_DMA_CHANNEL_CONFIG_LIST_SIZE    (12U)
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

/*!
 * @brief Initialize the FLEXIO_Sent driver
 *
 * This function initializes the FLEXIO_Sent driver.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param config    Pointer to the FLEXIO_Sent controller configuration structure. The function
 *                  reads configuration data from this structure and initializes the
 *                  driver accordingly. The application may free this structure after
 *                  the function returns.
 * @return          Error or success status returned by API
 *
 */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_Init(uint8 Instance,
                                              const Flexio_CtrlConfigType *Config);

/*!
 * @brief De-Initialize the FLEXIO_Sent driver
 *
 * This function de-initializes the FLEXIO_Sent driver.
 *
 * @param instance  FLEXIO peripheral instance number
 * @return          Error or success status returned by API
 *
 */
void Flexio_Sent_Ip_DeInit(uint8 Instance);

/*!
 * @brief Get Fast message data for a channel
 *
 * This function gets Fast message data for a channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastChannelMsgData(const uint8 Instance,
                                                               const uint8 ChannelId);

/*!
 * @brief Get Fast message data for all channel
 *
 * This function gets Fast message data for all channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastMsgData(const uint8 Instance);

/*!
 * @brief Get Serial message data for a channel
 *
 * This function gets Serial message data for a channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialChannelMsgData(const uint8 Instance,
                                                                 const uint8 ChannelId);

/*!
 * @brief Get Serial message data for all channel.
 *
 * This function gets Serial message data for all channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialMsgData(const uint8 Instance);

/*!
 * @brief Start receiving SENT data from bus on specific channel.
 *
 * Start receiving SENT data from bus on specific channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 *
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StartChannelReceiving(const uint8 Instance,
                                                               const uint8 ChannelId);

/*!
 * @brief Stop receiving SENT data from bus on specific channel.
 *
 * Start receiving SENT data from bus on specific channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 *
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StopChannelReceiving(const uint8 Instance,
                                                              const uint8 ChannelId);

/*!
 * @brief triggers a low pulse for the specified SENT channel.
 *
 * Triggers a low pulse for the specified SENT channel.
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @param TimeTriggerPulse Time period in microseconds (us) to keep the trigger pulse low
 *
 * @return          Error or success status returned by API
*/
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_SpcRequest(const uint8 Instance,
                                                    const uint8 ChannelId,
                                                    const uint16 TimeTriggerPulse);

#ifdef FEATURE_FLEXIO_SENT_DMA_ENABLE
    #if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE)
/*!
 * @brief Flexio_Sent_Ip_DmaHandler
 *
 * Implementation of FLEXIO DMA handler for all fast and serial messages
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
void Flexio_Sent_Ip_DmaHandler(const uint8 Instance,
                               const uint8 ChannelId);

    #endif /* (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE) */
#endif /* FEATURE_FLEXIO_SENT_DMA_ENABLE */

#ifdef FLEXIO_ISR_PROCESS_MESSAGE_HANDLER_CTRL0_COMBINED

/*!
 * @brief Flexio_Sent_Ip_IRQMsgDataHandler
 *
 * Implementation of FLEXIO interrupt handler for all fast and serial message
 *
 * @param instance  FLEXIO peripheral instance number
 * @param channelID ID of FLEXIO TIMER channel
 * @return          Error or success status returned by API
*/
void Flexio_Sent_Ip_IRQMsgDataHandler(const uint8 Instance,
                                      const uint8 ChannelId,
                                      uint32 TimerVal);

#endif /* FLEXIO_ISR_PROCESS_MESSAGE_HANDLER_CTRL0_COMBINED */

#ifdef FLEXIO_ISR_PROCESS_TIMER_CTRL0

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_IRQTimerHandler
 * Description   : Collect timer values
 *
 *END**************************************************************************/
void Flexio_Sent_Ip_IRQTimerHandler(const uint8 Instance,
                                    const uint8 HwChannel,
                                    uint32 TimerVal);

#endif /* FLEXIO_ISR_PROCESS_TIMER_CTRL0 */

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FLEXIO_SENT_IP_H */
