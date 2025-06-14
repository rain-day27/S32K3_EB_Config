/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : LPI2C
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may
* only be used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup LPI2C_DRIVER_CONFIGURATION Lpi2c Driver Configurations
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
#include "Lpi2c_Ip_PBcfg.h"

#if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
#include "Dma_Ip_Cfg.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_PBCFG_VENDOR_ID_C                     43
#define LPI2C_IP_PBCFG_MODULE_ID_C                     255
#define LPI2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LPI2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define LPI2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define LPI2C_IP_PBCFG_SW_MAJOR_VERSION_C              5
#define LPI2C_IP_PBCFG_SW_MINOR_VERSION_C              0
#define LPI2C_IP_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Lpi2c_Ip_PBcfg.h header file are of the same vendor */
#if (LPI2C_IP_PBCFG_VENDOR_ID_C != LPI2C_IP_PBCFG_VENDOR_ID)
    #error "Lpi2c_Ip_PBcfg.c and Lpi2c_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if current file and Lpi2c_Ip_PBcfg.h header file are of the same Autosar version */
#if ((LPI2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != LPI2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPI2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != LPI2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LPI2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != LPI2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lpi2c_Ip_PBcfg.c and Lpi2c_Ip_PBcfg.h are different"
#endif
/* Check if current file and Lpi2c_Ip_PBcfg.h header file are of the same Software version */
#if ((LPI2C_IP_PBCFG_SW_MAJOR_VERSION_C != LPI2C_IP_PBCFG_SW_MAJOR_VERSION) || \
     (LPI2C_IP_PBCFG_SW_MINOR_VERSION_C != LPI2C_IP_PBCFG_SW_MINOR_VERSION) || \
     (LPI2C_IP_PBCFG_SW_PATCH_VERSION_C != LPI2C_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpi2c_Ip_PBcfg.c and Lpi2c_Ip_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == LPI2C_IP_DMA_FEATURE_AVAILABLE)
        /* Check if current file and Dma_Ip_Cfg.h header file are of the same Autosar version */
        #if ((LPI2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
            (LPI2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lpi2c_Ip_PBcfg.c and Dma_Ip_Cfg.h are different"
        #endif
    #endif /* LPI2C_IP_DMA_FEATURE_AVAILABLE */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"


/* Baud rate structure for channel LPI2C_1 */
static const Lpi2c_Ip_BaudRateType baudrateParams0 =
{
    LPI2C_MASTER_PRESC_DIV_8,    /* Prescaler */
    24U,    /* ClkHI */
    24U,    /* ClkLO */
    6U,    /* Set Hold */
    8U,    /* Data Valid */
#if ( STD_ON == LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE )
    1U,    /* ClkHI HS */
    3U,    /* ClkLO HS */
    2U,    /* Set Hold HS */
    1U    /* Data Valid HS */
#endif
};

/* Channel configuration for channel LPI2C_1 - configured as master */
const Lpi2c_Ip_MasterConfigType I2c_Lpi2cMasterChannel0 =
{
    /* Slave address */
     0U,

    /*10-bit address */
    (boolean)FALSE,

    /* Operating Mode */
    LPI2C_STANDARD_MODE,

    /* Baudrate parameters */
    &baudrateParams0,

    /* Pin Low Timeout */
    0U,

    /* Bus Idle Timeout */
    0U,

    /* Glitch Filter SDA */
    1U,

    /* Glitch Filter SDA */
    1U,

    /* Master code */
    0U,

    /* Transfer Type */
    LPI2C_USING_INTERRUPTS,

    /* Dma Tx Channel */
    
    0U,
    
    /* Dma Rx Channel */
    
    0U,
    

    /* Master Callback */
    NULL_PTR,

    /* Master Callback Parameter */
    0U,

    /*  Master State index */
    0U
};
    


#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

