/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* Prevention from multiple including the same header */
#ifndef FLEXIO_MCL_IP_CFG_DEVICE_REGISTERS_H_
#define FLEXIO_MCL_IP_CFG_DEVICE_REGISTERS_H_

/**
*   @file    Flexio_Mcl_Ip_Cfg_DeviceRegisters.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Mcl - Flexio Ip Cfg Device Register header file.
*   @details Contains common register information and specific register information for
*            Flexio.
*
*   @addtogroup FLEXIO_MCL_IP_DRIVER FLEXIO IP Driver
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
#include "Mcal.h"


#include "S32K314_FLEXIO.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID                    43
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_MODULE_ID                    255
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION             5
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION             0
#define FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcal header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_DeviceRegisters.h and Mcal.h are different"
#endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef FLEXIO_MCL_IP_CFG_DEVICE_REGISTERS_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
