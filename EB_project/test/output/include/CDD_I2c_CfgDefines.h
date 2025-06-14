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

#ifndef CDD_I2C_CFGDEFINES_H
#define CDD_I2C_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup I2c_driver_config I2c Driver Configuration
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_I2C_VENDOR_ID_CFGDEFINES                    43
#define CDD_I2C_MODULE_ID_CFGDEFINES                    255
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define CDD_I2C_AR_RELEASE_MINOR_VERSION_CFGDEFINES     7
#define CDD_I2C_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define CDD_I2C_SW_MAJOR_VERSION_CFGDEFINES             5
#define CDD_I2C_SW_MINOR_VERSION_CFGDEFINES             0
#define CDD_I2C_SW_PATCH_VERSION_CFGDEFINES             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*
* @api
*/
#define I2C_PRECOMPILE_SUPPORT (STD_ON)

/**
* @brief   Total number of I2c channel configured.
*/
#define I2C_HW_MAX_CONFIG           (1U)

/**
* @brief   Total number of available hardware I2C channels.
*/
#define I2C_HW_MAX_MODULES          (6U)

/**
* @brief   Total number of available hardware I2C channels.
*/
#define I2C_LPI2C_MAX_MODULES       (2U)


/**
* @brief            This is the ID of the first FLEXIO channel.
*/
#define I2C_FLEXIO_FIRST_CHANNEL_U8   (I2C_LPI2C_MAX_MODULES)


/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define I2C_DEV_ERROR_DETECT      (STD_ON)  /* Enable Development Error Detection */

/**
* @brief          Support for version info API.
* @details        Switches the I2c_GetVersionInfo() API ON or OFF.
*
* @api
*/
#define I2C_VERSION_INFO_API      (STD_ON)  /* Enable API I2c_GetVersionInfo      */


/**
* @brief          Link I2c channels symbolic names with I2c channel IDs.
* @details        Link I2c channels symbolic names with I2c channel IDs.
*
* @api
*/

#define I2C_LPI2C_1    (1U)

/**
* @brief  I2c channel name to logic channel id mapping
*/

#define I2cChannel_I2C1                 (0U)
            
#define I2C_MASTER_0             I2cChannel_I2C1
            
            


/**
* @brief          spurious partition id.
* @details        If multipartition support disable
*
* @api
*/
#define I2C_SPURIOUS_PARTITION_ID        (0U)

/**
* @brief          Symbolic names for configured channels.
* @details        Symbolic names for configured channels.
*
* @api
*/

#define I2cConf_I2cChannel_I2cChannel_I2C1         (0U)


/**
* @brief          FLEXIO Channel Used
*/
#define I2C_FLEXIO_USED   (STD_OFF)




/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define I2C_DISABLE_DEM_REPORT_ERROR_STATUS   (STD_OFF)

/**
* @brief            Enable/Disable Multi Partition Support.
*/
#define I2C_MULTIPARTITION_SUPPORT   (STD_OFF)

/**
* @brief            DMA is used for at least one channel (STD_ON/STD_OFF)
*/
#define I2C_DMA_USED   (STD_OFF)

#if (I2C_MULTIPARTITION_SUPPORT == STD_ON)
    #define I2c_GetUserID()            OsIf_GetUserId()
#else
    #define I2c_GetUserID()            ((uint32)0UL)
#endif /* (I2C_MULTIPARTITION_SUPPORT == STD_ON) */

/**
* @brief            TIMEOUT for sync transmissions
*/
#define I2C_TIMEOUT               (1000U)




/**
* @brief        Variable storing number of maximum partitions using in configuration.
*/



#define I2C_MAX_PARTITION_ID     ((uint8)1U)

/**
* @brief    The value initialization un init for each partition.
*/
#define I2C_UNINIT_PARTITION \
{ I2C_UNINIT }

/**
* @brief    The value initialization null pointer for each partition.
*/
#define I2C_NULL_PTR \
{ NULL_PTR }

/**
* @brief        The value initialization Hardware Map.
*/
#define I2C_HW_MAP_INIT \
{ 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU }
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHERS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_I2C_CFGDEFINES_H */
