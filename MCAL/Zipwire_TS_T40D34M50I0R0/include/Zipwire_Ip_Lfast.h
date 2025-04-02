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

#ifndef ZIPWIRE_IP_LFAST_H
#define ZIPWIRE_IP_LFAST_H

/**
*   @file Zipwire_Ip_Lfast.h
*
*   @addtogroup ZIPWIRE_IP_DRIVER ZIPWIRE IP Configure Register
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
#include "Mcal.h"
#include "Zipwire_Ip_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_LFAST_VENDOR_ID                   43
#define ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION    4
#define ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION    7
#define ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION 0
#define ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION            5
#define ZIPWIRE_IP_LFAST_SW_MINOR_VERSION            0
#define ZIPWIRE_IP_LFAST_SW_PATCH_VERSION            0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip_Lfast.h file and Mcal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Mcal.h are different"
#endif
#endif

/* Check if source file and Zipwire_Ip_Types.h file are of the same vendor */
#if (ZIPWIRE_IP_LFAST_VENDOR_ID != ZIPWIRE_IP_TYPES_VENDOR_ID)
#error "Zipwire_Ip_Lfast.h and Zipwire_Ip_Types.h have different vendor ids"
#endif

/* Check if source file and Zipwire_Ip_Types.h file are of the same Autosar version */
#if ((ZIPWIRE_IP_LFAST_AR_RELEASE_MAJOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_MINOR_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_AR_RELEASE_REVISION_VERSION != ZIPWIRE_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_Types.h are different"
#endif

/* Check if source file and Zipwire_Ip_Types.h header file are of the same Software version */
#if ((ZIPWIRE_IP_LFAST_SW_MAJOR_VERSION != ZIPWIRE_IP_TYPES_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_SW_MINOR_VERSION != ZIPWIRE_IP_TYPES_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_LFAST_SW_PATCH_VERSION != ZIPWIRE_IP_TYPES_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip_Lfast.h and Zipwire_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/*!
 * @brief LFAST Loopback initialization.
 *
 * Initializes the LFAST loopback interface
 *
 * @param[in] pxLfastBase       - LFAST pxZipwireBase pointer.
 * @param[in] PllClkDiv         - LFAST PLL reference clock divider.
 * @param[in] FeedbackDiv       - Feedback Division factor for LFAST PLL VCO output clock.
 * @param[in] SpeedMode         - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout           - Cycles allowed for the synchronization to complete.
 *                                A value of zero passed for the timeout parameter is disregarded by the
 *                                driver; the master will wait forever for the responses from the slave.
 * @param[in] Attempts          - Number of Attempts for the master to synchronize with the slave;
 *                                A value of zero for this parameter is equivalent to an infinite
 *                                number of Attempts; the LFAST master will wait forever for the
 *                                slave to confirm it's status.
 * @return - error code
 */

Zipwire_Ip_StatusType Zipwire_Ip_InitLfastLoopback(LFAST_Type *pxLfastBase,
                                                   const Zipwire_Ip_LfastChannelConfigType *LfastConfig);

/*!
 * @brief LFAST Master initialization.
 *
 * Initializes the LFAST master interface
 *
 * @param[in] pxLfastBase       - LFAST pxZipwireBase pointer.
 * @param[in] PllClkDiv         - LFAST PLL reference clock divider.
 * @param[in] FeedbackDiv       - Feedback Division factor for LFAST PLL VCO output clock.
 * @param[in] SpeedMode         - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv    - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout           - Cycles allowed for the synchronization to complete.
 *                                A value of zero passed for the timeout parameter is disregarded by the
 *                                driver; the master will wait forever for the responses from the slave.
 * @param[in] Attempts          - Number of Attempts for the master to synchronize with the slave;
 *                                A value of zero for this parameter is equivalent to an infinite
 *                                number of Attempts; the LFAST master will wait forever for the
 *                                slave to confirm it's status.
 * @return - error code
 */

Zipwire_Ip_StatusType Zipwire_Ip_MasterInit(LFAST_Type *pxLfastBase,
                                            const Zipwire_Ip_LfastChannelConfigType *LfastConfig);


/*!
 * @brief LFAST Slave initialization.
 *
 * Initializes the LFAST slave interface
 *
 * @param[in] pxLfastBase    - LFAST pxZipwireBase pointer.
 * @param[in] PllClkDiv      - LFAST PLL reference clock divider.
 * @param[in] FeedbackDiv    - Feedback Division factor for LFAST PLL VCO output clock.
 * @param[in] SpeedMode      - low-speed/high-speed.
 * @param[in] LowSpeedClkDiv - low-speed clock input (sysclk/2 or sysclk/4).
 * @param[in] Timeout        - cycles allowed for the synchronization to complete.
 *                             A value of zero passed for the timeout parameter is disregarded by the
 *                             driver; the slave will wait forever for the commands from the master.
 * @return - error code
 */
Zipwire_Ip_StatusType Zipwire_Ip_SlaveInit(LFAST_Type *pxLfastBase,
                                           const Zipwire_Ip_LfastChannelConfigType *LfastConfig);


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ZIPWIRE_IP_LFAST_H */
