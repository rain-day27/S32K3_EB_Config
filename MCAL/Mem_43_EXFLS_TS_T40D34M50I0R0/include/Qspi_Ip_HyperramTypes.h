/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
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

#ifndef QSPI_IP_HYPERRAMTYPES_H
#define QSPI_IP_HYPERRAMTYPES_H

/**
*   @file Qspi_Ip_HyperramTypes.h
*
*   @addtogroup IPV_QSPI
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HYPERRAMTYPES_VENDOR_ID                    43
#define QSPI_IP_HYPERRAMTYPES_AR_RELEASE_MAJOR_VERSION     4
#define QSPI_IP_HYPERRAMTYPES_AR_RELEASE_MINOR_VERSION     7
#define QSPI_IP_HYPERRAMTYPES_AR_RELEASE_REVISION_VERSION  0
#define QSPI_IP_HYPERRAMTYPES_SW_MAJOR_VERSION             5
#define QSPI_IP_HYPERRAMTYPES_SW_MINOR_VERSION             0
#define QSPI_IP_HYPERRAMTYPES_SW_PATCH_VERSION             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Qspi_Ip_HyperramTypes header file and Std_Types.h header file are of the same Autosar version */
    #if ((QSPI_IP_HYPERRAMTYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_HYPERRAMTYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Qspi_Ip_HyperramTypes.h and Std_Types.h are different"
    #endif
#endif


/*******************************************************************************
* Definitions
******************************************************************************/

/* LUT entries used for hyperflash command sequences */
#define QSPI_IP_HR_LUT_SIZE             23U

#define QSPI_IP_HR_LUT_READ             0U
#define QSPI_IP_HR_LUT_WRITE            6U
#define QSPI_IP_HR_LUT_READ_REG         12U
#define QSPI_IP_HR_LUT_WRITE_REG        18U

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

/*!
* @brief Drive strength
*
* Hyperflash driver strength settings.
*/
typedef enum
{
    QSPI_IP_HR_DRV_STRENGTH_000 = 0x00U,  /*!< Typical Impedance for 1.8V: 27,  Typical Impedance 3V: 20 */
    QSPI_IP_HR_DRV_STRENGTH_001 = 0x01U,  /*!< Typical Impedance for 1.8V: 117, Typical Impedance 3V: 71 */
    QSPI_IP_HR_DRV_STRENGTH_002 = 0x02U,  /*!< Typical Impedance for 1.8V: 68,  Typical Impedance 3V: 40 */
    QSPI_IP_HR_DRV_STRENGTH_003 = 0x03U,  /*!< Typical Impedance for 1.8V: 45,  Typical Impedance 3V: 27 */
    QSPI_IP_HR_DRV_STRENGTH_004 = 0x04U,  /*!< Typical Impedance for 1.8V: 34,  Typical Impedance 3V: 20 */
    QSPI_IP_HR_DRV_STRENGTH_005 = 0x05U,  /*!< Typical Impedance for 1.8V: 27,  Typical Impedance 3V: 16 */
    QSPI_IP_HR_DRV_STRENGTH_006 = 0x06U,  /*!< Typical Impedance for 1.8V: 24,  Typical Impedance 3V: 14 */
    QSPI_IP_HR_DRV_STRENGTH_007 = 0x07U   /*!< Typical Impedance for 1.8V: 20,  Typical Impedance 3V: 12 */
} Qspi_Ip_HyperramDrvStrengthType;


/*!
* @brief Initial latency
*
*/
typedef enum
{
    QSPI_IP_HR_INITIAL_LATENCY_5_CLOCKS  = 0U,  /*!< Read Initial 5 clocks  */
    QSPI_IP_HR_INITIAL_LATENCY_6_CLOCKS  = 1U,  /*!< Read Initial 6 clocks  */
    QSPI_IP_HR_INITIAL_LATENCY_7_CLOCKS  = 2U,  /*!< Read Initial 7 clocks  */
    QSPI_IP_HR_INITIAL_LATENCY_3_CLOCKS  = 14U, /*!< Read Initial 3 clocks */
    QSPI_IP_HR_INITIAL_LATENCY_4_CLOCKS  = 15U, /*!< Read Initial 4 clocks */
} Qspi_Ip_HyperramInitialLatencyType;

/*******************************************************************************
* Structures
******************************************************************************/
/*!
* @brief Master Clock
*
*/
typedef enum
{
    QSPI_IP_HR_MASTER_CLOCK_TYPE_SINGLE_ENDED = 1U,
    QSPI_IP_HR_MASTER_CLOCK_TYPE_DIFFERENTIAL = 0U
} Qspi_Ip_HyperramMasterClockType;

/*!
* @brief Array Refresh
*
*/
typedef enum
{
    QSPI_IP_HR_ARRAY_REFRESH_000 = 0U,
    QSPI_IP_HR_ARRAY_REFRESH_001 = 1U,
    QSPI_IP_HR_ARRAY_REFRESH_002 = 2U,
    QSPI_IP_HR_ARRAY_REFRESH_003 = 3U,
    QSPI_IP_HR_ARRAY_REFRESH_004 = 4U,
    QSPI_IP_HR_ARRAY_REFRESH_005 = 5U,
    QSPI_IP_HR_ARRAY_REFRESH_006 = 6U,
    QSPI_IP_HR_ARRAY_REFRESH_007 = 7U
} Qspi_Ip_HyperramArrayRefreshType;

/*!
* @brief Hyperram configuration structure
*
 * This structure is used to provide configuration parameters for HyperRam
 * at initialization time.
*/
typedef struct
{
    Qspi_Ip_HyperramDrvStrengthType       driveStrength;           /*!< Output driver level of the device                   */
    Qspi_Ip_HyperramInitialLatencyType    initialLatency;          /*!< Initial latency                                     */
    Qspi_Ip_HyperramMasterClockType       masterClockType;         /*!< Master Clock Type                                   */
    Qspi_Ip_HyperramArrayRefreshType      arrayRefresh;            /*!< Array Refresh                                       */
    uint32                                deviceIdWordAddress;     /*!< The word address of the device Id in register space */
} Qspi_Ip_HyperRamConfigType;


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_HYPERRAMTYPES_H */
