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
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/


#ifndef CRC_IP_TYPES_H
#define CRC_IP_TYPES_H

/**
*   @file    Crc_Ip_Types.h
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup CRC_IP_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Crc_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define CRC_IP_TYPES_VENDOR_ID                     43
#define CRC_IP_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define CRC_IP_TYPES_AR_RELEASE_MINOR_VERSION      7
#define CRC_IP_TYPES_AR_RELEASE_REVISION_VERSION   0
#define CRC_IP_TYPES_SW_MAJOR_VERSION              5
#define CRC_IP_TYPES_SW_MINOR_VERSION              0
#define CRC_IP_TYPES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Crc_Ip_Types.h file and Mcal.h header file are of the same Autosar version */
#if ((CRC_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Crc_Ip_Types.h and Mcal.h are different"
#endif
#endif


/* Check if the files Crc_Ip_Types.h and Crc_Ip_CfgDefines.h are of the same version */
#if (CRC_IP_TYPES_VENDOR_ID != CRC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Crc_Ip_Types.h and Crc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Crc_Ip_Types.h and Crc_Ip_CfgDefines.h are of the same Autosar version */
#if ((CRC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != CRC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != CRC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_TYPES_AR_RELEASE_REVISION_VERSION != CRC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Types.h and Crc_Ip_CfgDefines.h are different"
#endif

/* Check if Crc_Ip_Types.h and Crc_Ip_CfgDefines.h are of the same Software version */
#if ((CRC_IP_TYPES_SW_MAJOR_VERSION != CRC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CRC_IP_TYPES_SW_MINOR_VERSION != CRC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CRC_IP_TYPES_SW_PATCH_VERSION != CRC_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Types.h and Crc_Ip_CfgDefines.h are different"
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

#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 Crc_Ip_uintPtrType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 Crc_Ip_uintPtrType;
#else
    #error "Unsupported CPU_TYPE"
#endif

/**
 * @brief   This type contains the CRC Ip Channel Configuration.
 * @details The Channel is identified by the following structure
 *          Configure parameter for each CRC Channel
 *          Internal driver enumeration.
 * */
typedef enum
{
    CRC_IP_RUNTIME_CALCULATION     = 0U,  /**< Slower execution (software calculate), but small code size (no ROM table) */
    CRC_IP_TABLE_CALCULATION       = 1U,  /**< Fast execution (software calculate), but larger code size (ROM table) */
    CRC_IP_HARDWARE_CALCULATION    = 2U   /**< Fast execution, less CPU time */
} Crc_Ip_CalculationType;

/**
 * @brief   This type contains the CRC Ip Channel Protocol.
 * @details The Protocol shall be selected from the available list.
 *          Software CRC supports all protocols.
 *          Table based CRC support the following protocols:
 *          Hardware CRC supports implementation specific protocols.
 * */
typedef enum
{
    CRC_PROTOCOL_8BIT_CUSTOM       ,  /**< Generate 8-bit CUSTOM CRC with user defined algorithm */
    CRC_PROTOCOL_16BIT_CUSTOM      ,  /**< Generate 16-bit CUSTOM CRC with user defined algorithm */
    CRC_PROTOCOL_32BIT_CUSTOM      ,  /**< Generate 32-bit CUSTOM CRC with user defined algorithm */
    CRC_PROTOCOL_64BIT_CUSTOM      ,  /**< Generate 64-bit CUSTOM CRC with user defined algorithm */
    CRC_PROTOCOL_8BIT_H2F          ,  /**< Generate 8-bit CRC: H2F, AUTOSAR 4.0 CRC-8 0x2F */
    CRC_PROTOCOL_8BIT_SAE_J1850    ,  /**< Generate 8-bit CRC: VDA CAN, SAE-J1850 CRC-8. */
    CRC_PROTOCOL_16BIT_ARC         ,  /**< Generate 16-bit CRC ARC code with Polynomial: 0x8005 */
    CRC_PROTOCOL_16BIT_CCITT_FALSE ,  /**< Generate 16-bit CRC: x.25. CCITT16 CRC-16 0x1021 */
    CRC_PROTOCOL_32BIT_E2E_P4      ,  /**< Generate 32-bit CRC: E2E Profile 4 CRC-32 P4 0xF4ACFB13 */
    CRC_PROTOCOL_32BIT_ETHERNET    ,  /**< Generate 32-bit CRC: Ethernet (IEEE 802,3) CCITT32 CRC-32 0x04C11DB7 */
    CRC_PROTOCOL_64BIT_ECMA        , /**< Generate 64-bit CRC: ECMA */
    CRC_PROTOCOL_INVALID             /**< Invalid protocol */
} Crc_Ip_ProtocolType;


#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
/**
 * @brief   This type contains the CRC Ip Dma Transfer Size options.
 * @details This type contains the CRC Ip Dma Transfer Size options.
 * */
typedef enum
{
    CRC_DMA_TRANSFER_SIZE_1_BYTE   = 0U,
    CRC_DMA_TRANSFER_SIZE_2_BYTE   = 1U,
    CRC_DMA_TRANSFER_SIZE_4_BYTE   = 2U
} Crc_Ip_DmaTransferSizeType;
#endif
/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief   This type contains the CRC Ip Channel Configuration.
 * @details The Channel is identified by the following structure
 *          Configure parameter for each CRC Channel
 * */
typedef struct
{
    Crc_Ip_ProtocolType Protocol;           /**< CRC protocol type. */
    uint64  PolynomValue;                   /**< Polynomial input, MSBit first. Example polynomial: 0x1021U = 1_0000_0010_0001 = x^12+x^5+1 */
    boolean WriteBitSwap;                   /**< Swap when writing CRC input data. */
    boolean WriteByteSwap;                  /**< Swap when writing CRC input data. */
    boolean ReadBitSwap;                    /**< Swap result bits after algorithm finished calculating CRC . */
    boolean ReadByteSwap;                   /**< Swap result bytes after algorithm finished calculating CRC . */
    boolean InverseEnable;                  /**< The inversion operation is a complement (or negation) of the content.  */
    const uint8 *LookUpTable;                    /**< LookUp Table address for 8 bits  */
} Crc_Ip_LogicChannelConfigType;

/**
 * @brief   This type contains the Crc Ip Channel Type
 * @details The Crc Ip Initialization contains all the information required to initialize the CRC Driver
 *          Internal driver structure.
 * */
typedef struct
{
    Crc_Ip_CalculationType CalculationType;                     /**< Software, Table, Hardware Calculation */
    uint8 HwInst;                                               /**< CRC hardware instance. */
    uint8 HwChannel;                                            /**< CRC hardware channel. */
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    boolean DmaLogicChannelEnable;                              /**< DMA Channel Enable. */
    uint32 DmaLogicChannelName;                                 /**< DMA Logic Channel. */
    Crc_Ip_DmaTransferSizeType DmaLogicChannelTransferSize;         /**< DMA Logic Channel Transfer Size. */
    uint8 DmaLogicChannelSignedOffset;                          /**< DMA Logic Channel Signed Offset. */
#endif /* STD_ON = CRC_IP_DMA_IS_AVAILABLE */
    Crc_Ip_LogicChannelConfigType *LogicChannelConfig;        /**< Pointer to LogicChannelConfig. */
} Crc_Ip_LogicChannelType;

/**
 * @brief   This type contains the Crc Ip Initialization.
 * @details The Crc Ip Initialization contains all the information required to initialize the CRC Driver
 *          Internal driver structure.
 * */
typedef struct
{
    const Crc_Ip_LogicChannelType *const *LogicChannelConfigList; /**< Pointer to list LogicChannelConfig */
} Crc_Ip_InitType;

/*=================================================================================================-
*                                GLOBAL VARIABLE DECLARATIONS
============================================================-=====================================*/

/*===================================================================================-==============
*                                    FUNCTION PROTOTYPES
========================================================================================-=========*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef CRC_IP_TYPES_H */
