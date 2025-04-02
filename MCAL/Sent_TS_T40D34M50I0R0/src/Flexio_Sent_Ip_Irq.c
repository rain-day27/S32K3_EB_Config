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

/**
*   @file    Flexio_Sent_Ip_Irq.c
*   @version 5.0.0
*
*   @brief   AUTOSAR Sent - Low level source of Sent driver.
*   @details Interrupt routines for Sent driver.
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
#include "Flexio_Sent_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SENT_IP_IRQ_VENDOR_ID_C                      43
#define FLEXIO_SENT_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_SENT_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_SENT_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_SENT_IP_IRQ_SW_MAJOR_VERSION_C               5
#define FLEXIO_SENT_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXIO_SENT_IP_IRQ_SW_PATCH_VERSION_C               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Flexio_Sent_Ip.h header file are of the same vendor */
#if (FLEXIO_SENT_IP_IRQ_VENDOR_ID_C != FLEXIO_SENT_IP_VENDOR_ID)
    #error "Flexio_Sent_Ip_Irq.c and Flexio_Sent_Ip.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXIO_SENT_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION) || \
    (FLEXIO_SENT_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Flexio_Sent_Ip_Irq.c and Flexio_Sent_Ip.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip header file are of the same Software version */
#if ((FLEXIO_SENT_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_SENT_IP_SW_MAJOR_VERSION) || \
    (FLEXIO_SENT_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_SENT_IP_SW_MINOR_VERSION) || \
    (FLEXIO_SENT_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_SENT_IP_SW_PATCH_VERSION)    \
    )
    #error "Flexio_Sent_Ip_Irq.c and Flexio_Sent_Ip.h have different vendor IDs"
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

#if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE)
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 0)
extern void Flexio_Sent_Ip_Ch0Callback(void);

#endif
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 1)
extern void Flexio_Sent_Ip_Ch1Callback(void);

#endif
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 2)
extern void Flexio_Sent_Ip_Ch2Callback(void);

#endif
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 3)
extern void Flexio_Sent_Ip_Ch3Callback(void);

#endif
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 4)
extern void Flexio_Sent_Ip_Ch4Callback(void);

#endif
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 5)
extern void Flexio_Sent_Ip_Ch5Callback(void);

#endif
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 6)
extern void Flexio_Sent_Ip_Ch6Callback(void);

#endif
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 7)
extern void Flexio_Sent_Ip_Ch7Callback(void);

#endif
#endif /*#if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE)*/
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_ChnCallback
 * Description   : Implementation of DMA handler
 *
 ******************************************************************************/
#if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE)
#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 0)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch0Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 0);
}

#endif

#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 1)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch1Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 1);
}

#endif

#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 2)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch2Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 2);
}

#endif

#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 3)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch3Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 3);
}

#endif

#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 4)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch4Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 4);
}

#endif

#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 5)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch5Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 5);
}

#endif

#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 6)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch6Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 6);
}

#endif

#if (FEATURE_FLEXIO_SENT_CHANNEL_COUNT > 7)
/* Dma complete notification */
void Flexio_Sent_Ip_Ch7Callback(void)
{
    Flexio_Sent_Ip_DmaHandler(0, 7);
}

#endif
#endif /* if (STD_ON == FEATURE_FLEXIO_SENT_DMA_ENABLE) */

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
