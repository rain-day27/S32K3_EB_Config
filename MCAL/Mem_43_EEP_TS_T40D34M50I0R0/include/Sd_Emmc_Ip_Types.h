/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
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

#ifndef SD_EMMC_IP_TYPES_H
#define SD_EMMC_IP_TYPES_H

/**
*   @file
*
*   @addtogroup IPV_SD_EMMC SD_EMMC
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Usdhc_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SD_EMMC_IP_TYPES_VENDOR_ID                    43
#define SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define SD_EMMC_IP_TYPES_SW_MAJOR_VERSION             5
#define SD_EMMC_IP_TYPES_SW_MINOR_VERSION             0
#define SD_EMMC_IP_TYPES_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Usdhc_Ip_Types.h header file are of the same vendor */
#if (SD_EMMC_IP_TYPES_VENDOR_ID != USDHC_IP_TYPES_VENDOR_ID_H)
    #error "Sd_Emmc_Ip_Types.h and Usdhc_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Usdhc_Ip_Types.h header file are of the same Autosar version */
#if ((SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION != USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip_Types.h and Usdhc_Ip_Types.h are different"
#endif
/* Check if header file and Usdhc_Ip_Types.h header file are of the same software version */
#if ((SD_EMMC_IP_TYPES_SW_MAJOR_VERSION != USDHC_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (SD_EMMC_IP_TYPES_SW_MINOR_VERSION != USDHC_IP_TYPES_SW_MINOR_VERSION_H) || \
     (SD_EMMC_IP_TYPES_SW_PATCH_VERSION != USDHC_IP_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip_Types.h and Usdhc_Ip_Types.h are different"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief SD/MMC generic status. */
typedef enum
{
    SD_IP_STATUS_SUCCESS                         = 0x000U,    /*!< Generic operation success status */
    SD_IP_STATUS_PENDING                         = 0x001U,    /*!< Generic operation success status */
    SD_IP_STATUS_ERROR                           = 0x002U,    /*!< Generic operation failure status */
    SD_IP_STATUS_TIMEOUT                         = 0x003U,    /*!< Generic operation timeout status */
    SD_IP_STATUS_NOT_SUPPORTED                   = 0x004U,    /*!< Ip is noto supported */
    SD_IP_STATUS_TRANSFER_FAILED                 = 0x005U,    /*!< Send command failed */
    SD_IP_STATUS_SET_CARD_BLOCK_SIZE_FAILED      = 0x006U,    /*!< Set block size failed */
    SD_IP_STATUS_CARD_NOT_SUPPORTED              = 0x007U,    /*!< Card doesn't support */
    SD_IP_STATUS_ALL_SEND_CID_FAILED             = 0x008U,    /*!< Send CID failed */
    SD_IP_STATUS_SEND_RELATIVE_ADDRESS_FAILED    = 0x009U,    /*!< Send relative address failed */
    SD_IP_STATUS_SEND_CSD_FAILED                 = 0x00AU,    /*!< Send CSD failed */
    SD_IP_STATUS_SELECT_CARD_FAILED              = 0x00BU,    /*!< Select card failed */
    SD_IP_STATUS_SEND_SCR_FAILED                 = 0x00CU,    /*!< Send SCR failed */
    SD_IP_STATUS_SET_DATA_BUS_WIDTH_FAILED       = 0x00DU,    /*!< Set bus width failed */
    SD_IP_STATUS_GO_IDLE_FAILED                  = 0x00EU,    /*!< Go idle failed */
    SD_IP_STATUS_HANDSHAKE_OP_FAILED             = 0x00FU,    /*!< Send Operation Condition failed */
    SD_IP_STATUS_SEND_APPL_COMMAND_FAILED        = 0x010U,    /*!< Send application command failed */
    SD_IP_STATUS_SWITCH_FAILED                   = 0x011U,    /*!< Switch command failed */
    SD_IP_STATUS_STOP_TRANSMISION_FAILED         = 0x012U,    /*!< Stop transmission failed */
    SD_IP_STATUS_WAIT_WRITE_COMPLETE_FAILED      = 0x013U,    /*!< Wait write complete failed */
    SD_IP_STATUS_SET_BLOCK_COUNT_FAILED          = 0x014U,    /*!< Set block count failed */
    SD_IP_STATUS_SWITCH_HIGH_SPEED_FAILED        = 0x015U,    /*!< Switch high speed failed */
    SD_IP_STATUS_CARD_IS_WRITE_PROTECTED         = 0x016U,    /*!< Card write protection lock enabled */
    SD_IP_STATUS_SWITCH_VOLTAGE_FAILED           = 0x017U,    /*!< Card switch voltage failed */
    SD_IP_STATUS_BLOCK_SIZE_INCORRECT            = 0x018U,    /*!< Block size is not as defined in HLD */
    SD_IP_STATUS_BLOCK_COUNT_INCORRECT           = 0x019U,    /*!< Block count is not as defined in HLD */
    SD_IP_STATUS_MEMORY_CARD_INCORRECT           = 0x01AU,     /*!< Memory card type is not as defined in HLD */
    SD_IP_STATUS_TUNING_FAILED                   = 0x01BU     /*!< Tuning data does not match with pattern */
 } Sd_Emmc_Ip_StatusType;

/*! @brief SD/MMC card initialization clock frequency */
#define SD_EMMC_IP_CLOCK_100KHZ (100000U)
/*! @brief SD/MMC card initialization clock frequency */
#define SD_EMMC_IP_CLOCK_400KHZ (400000U)
/*! @brief SD card bus frequency 1 in high speed mode */
#define SD_EMMC_IP_CLOCK_25MHZ (25000000U)
/*! @brief SD card bus frequency 1 in high speed mode */
#define SD_EMMC_IP_CLOCK_26MHZ (26000000U)
/*! @brief SD card bus frequency 2 in high speed mode */
#define SD_EMMC_IP_CLOCK_40MHZ (40000000U)
/*! @brief SD card bus frequency 3 in high speed mode */
#define SD_EMMC_IP_CLOCK_50MHZ (50000000U)
/*! @brief MMC card bus frequency 2 in high speed mode */
#define SD_EMMC_IP_CLOCK_52MHZ (52000000U)
/*! @brief MMC card bus frequency 3 in HS200 or HS400 mode */
#define SD_EMMC_IP_CLOCK_200MHZ (200000000U)

/*! Bit fields to access EXT_CSD register */
/*! @brief Access Set Bits field */
#define SD_EMMC_IP_MMC_SET_BITS ((uint32)((uint32)1U << 24U))
/*! @brief Access Clear Bits field */
#define SD_EMMC_IP_MMC_CLEAR_BITS ((uint32)((uint32)2U << 24U))
/*! @brief Access Write Bits field */
#define SD_EMMC_IP_MMC_WRITE_BITS ((uint32)((uint32)3U << 24U))
/*! @brief Access Command Set field */
#define SD_EMMC_IP_MMC_COMMAND_SETS ((uint32)0x0U)
/*! @brief Shift index field */
#define SD_EMMC_IP_MMC_SHIFT_INDEX ((uint8)0x10U)
/*! @brief Default Speed field */
#define SD_EMMC_IP_MMC_DEFAULT_SPEED ((uint32)0x0U)
/*! @brief High Speed field */
#define SD_EMMC_IP_MMC_HIGH_SPEED ((uint32)((uint32)1U << 8U))
/*! @brief HS200 Speed field */
#define SD_EMMC_IP_MMC_HS200_SPEED ((uint32)2U)
/*! @brief HS400 Speed field */
#define SD_EMMC_IP_MMC_HS400_SPEED ((uint32)3U)

/*! @brief Power Class 100 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_100 (0x0U)
/*! @brief Power Class 120 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_120 ((uint32)((uint32)1U << 8U))
/*! @brief Power Class 150 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_150 ((uint32)((uint32)2U << 8U))
/*! @brief Power Class 180 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_180 ((uint32)((uint32)3U << 8U))
/*! @brief Power Class 200 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_200 ((uint32)((uint32)4U << 8U))
/*! @brief Power Class 220 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_220 ((uint32)((uint32)5U << 8U))
/*! @brief Power Class 250 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_250 ((uint32)((uint32)6U << 8U))
/*! @brief Power Class 300 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_300 ((uint32)((uint32)7U << 8U))
/*! @brief Power Class 350 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_350 ((uint32)((uint32)8U << 8U))
/*! @brief Power Class 400 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_400 ((uint32)((uint32)9U << 8U))
/*! @brief Power Class 450 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_450 ((uint32)((uint32)10U << 8U))
/*! @brief Power Class 500 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_500 ((uint32)((uint32)11U << 8U))
/*! @brief Power Class 600 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_600 ((uint32)((uint32)12U << 8U))
/*! @brief Power Class 700 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_700 ((uint32)((uint32)13U << 8U))
/*! @brief Power Class 800 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_800 ((uint32)((uint32)14U << 8U))
/*! @brief Power Class >800 field */
#define SD_EMMC_IP_MMC_POWER_CLASS_900 ((uint32)((uint32)15U << 8U))

/*! @brief Bus width 1 bit field */
#define SD_EMMC_IP_MMC_BUS_WIDTH_1 (0x0U)
/*! @brief Bus width 4 bits field */
#define SD_EMMC_IP_MMC_BUS_WIDTH_4 ((uint32)((uint32)1U << 8U))
/*! @brief Bus width 8 bits field */
#define SD_EMMC_IP_MMC_BUS_WIDTH_8 ((uint32)((uint32)2U << 8U))
/*! @brief Bus width 4 bits ddr field */
#define SD_EMMC_IP_MMC_BUS_WIDTH_4_DDR ((uint32)((uint32)5U << 8U))
/*! @brief Bus width 8 bit ddr field */
#define SD_EMMC_IP_MMC_BUS_WIDTH_8_DDR ((uint32)((uint32)6U << 8U))

/*! @brief Alternate boot support(BOOT_INFO in Extended CSD) */
#define SD_EMMC_IP_MMC_ALTERNATE_BOOT_SUPPORT_MASK (0x01)

/*! @brief The power class value bit mask when bus in 4 bit mode */
#define SD_EMMC_IP_MMC_POWER_CLASS_4BIT_MASK (0x0FU)
/*! @brief The power class current value bit mask when bus in 8 bit mode */
#define SD_EMMC_IP_MMC_POWER_CLASS_8BIT_MASK (0xF0U)

/*! @brief The bit shift for PARTITION ACCESS filed in PARTITION_CONFIG (PARTITION_CONFIG in Extend CSD) */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ACCESS_SHIFT (0U)
/*! @brief The bit mask for PARTITION ACCESS field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ACCESS_MASK (0x00000007U)
/*! @brief The bit set for PARTITION ACCESS field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ACCESS(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_PARTITION_CONFIG_ACCESS_SHIFT)) & SD_EMMC_IP_MMC_PARTITION_CONFIG_ACCESS_MASK)

/*! @brief The bit shift for PARTITION ENABLE field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ENABLE_SHIFT (3U)
/*! @brief The bit mask for PARTITION ENABLE field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ENABLE_MASK (0x00000038U)
/*! @brief The bit set for PARTITION ENABLE field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ENABLE(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_PARTITION_CONFIG_ENABLE_SHIFT)) & SD_EMMC_IP_MMC_PARTITION_CONFIG_ENABLE_MASK)

/*! @brief The bit shift for ACK field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ACK_SHIFT (6U)
/*! @brief The bit mask for ACK field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ACK_MASK (0x00000040U)
/*! @brief The bit set for ACK field in PARTITION_CONFIG */
#define SD_EMMC_IP_MMC_PARTITION_CONFIG_ACK(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_PARTITION_CONFIG_ACK_SHIFT)) & SD_EMMC_IP_MMC_PARTITION_CONFIG_ACK_MASK)

/*! @brief The bit shift for BOOT BUS WIDTH field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_WIDTH_SHIFT (0U)
/*! @brief The bit mask for BOOT BUS WIDTH field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_WIDTH_MASK (0x1FU)
/*! @brief The bit set for BOOT BUS WIDTH field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_WIDTH(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_WIDTH_SHIFT)) & SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_WIDTH_MASK)

/*! @brief The bit shift for BOOT BUS WIDTH RESET field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_RESET_SHIFT (2U)
/*! @brief The bit mask for BOOT BUS WIDTH RESET field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_RESET_MASK (0x00000002U)
/*! @brief The bit set for BOOT BUS WIDTH RESET field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_RESET(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_RESET_SHIFT)) & SD_EMMC_IP_MMC_BOOT_BUS_WIDTH_RESET_MASK)

/*! @brief The bit shift for BOOT BUS WIDTH RESET field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_MODE_SHIFT (3U)
/*! @brief The bit mask for BOOT BUS WIDTH RESET field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_MODE_MASK (0x00000018U)
/*! @brief The bit set for BOOT BUS WIDTH RESET field in BOOT_BUS_CONDITIONS */
#define SD_EMMC_IP_MMC_BOOT_MODE(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_BOOT_MODE_SHIFT)) & SD_EMMC_IP_MMC_BOOT_MODE_MASK)

/*! @brief The bit shift for HS_BOOT_MODE field in BOOT_INFO */
#define SD_EMMC_IP_MMC_HS_BOOT_MODE_SHIFT (2U)
/*! @brief The bit mask for HS_BOOT_MODE field in BOOT_INFO */
#define SD_EMMC_IP_MMC_HS_BOOT_MODE_MASK (0x00000004U)
/*! @brief The bit set for HS_BOOT_MODE field in BOOT_INFO */
#define SD_EMMC_IP_MMC_HS_BOOT_MODE(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_HS_BOOT_MODE_SHIFT)) & SD_EMMC_IP_MMC_HS_BOOT_MODE_MASK)

/*! @brief The bit shift for DDR_BOOT_MODE field in BOOT_INFO */
#define SD_EMMC_IP_MMC_DDR_BOOT_MODE_SHIFT (2U)
/*! @brief The bit mask for DDR_BOOT_MODE field in BOOT_INFO */
#define SD_EMMC_IP_MMC_DDR_BOOT_MODE_MASK (0x00000004U)
/*! @brief The bit set for DDR_BOOT_MODE field in BOOT_INFO */
#define SD_EMMC_IP_MMC_DDR_BOOT_MODE(x) (((uint32)(((uint32)(x)) << SD_EMMC_IP_MMC_DDR_BOOT_MODE_SHIFT)) & SD_EMMC_IP_MMC_DDR_BOOT_MODE_MASK)

/*! @brief Card status bit in R1 */
#define SD_IP_R1_OUT_OF_RANGE_ERROR              ((uint32)0x80000000U)                  /*!< (1 << 31) Out of range status bit */
#define SD_IP_R1_ADDRESS_ERROR                   ((uint32)0x40000000U)                  /*!< (1 << 30) Address error status bit */
#define SD_IP_R1_BLOCK_LENGHT_ERROR              ((uint32)0x20000000U)                  /*!< (1 << 29) Block length error status bit */
#define SD_IP_R1_ERASE_SEQ_ERROR                 ((uint32)0x10000000U)                  /*!< (1 << 28) Erase sequence error status bit */
#define SD_IP_R1_ERASE_PARAMETER_ERROR           ((uint32)0x08000000U)                  /*!< (1 << 27) Erase parameter error status bit */
#define SD_IP_R1_WRITE_PROTECT_VIOLATION         ((uint32)0x04000000U)                  /*!< (1 << 26) Write protection violation status bit */
#define SD_IP_R1_CARD_IS_LOCKED                  ((uint32)0x02000000U)                  /*!< (1 << 25) Card locked status bit */
#define SD_IP_R1_LOCK_UNLOCK_FAILED              ((uint32)0x01000000U)                  /*!< (1 << 24) lock/unlock error status bit */
#define SD_IP_R1_COMMAND_CRC_FAILED              ((uint32)0x00800000U)                  /*!< (1 << 23) CRC error status bit */
#define SD_IP_R1_ILLEGAL_COMMAND                 ((uint32)0x00400000U)                  /*!< (1 << 22) Illegal command status bit */
#define SD_IP_R1_CARD_ECC_FAILED                 ((uint32)0x00200000U)                  /*!< (1 << 21) Card ecc error status bit */
#define SD_IP_R1_CARD_CONTROLLER_ERROR           ((uint32)0x00100000U)                  /*!< (1 << 20) Internal card controller error status bit */
#define SD_IP_R1_UNKNOWN_ERROR                   ((uint32)0x00080000U)                  /*!< (1 << 19) A general or an unknown error status bit */
#define SD_IP_R1_CID_CSD_OVERWRITE               ((uint32)0x00010000U)                  /*!< (1 << 16) Cid/csd overwrite status bit */
#define SD_IP_R1_WRITE_PROTECT_ERASE_SKIP_FLAG   ((uint32)0x00008000U)                  /*!< (1 << 15) Write protection erase skip status bit */
#define SD_IP_R1_CARD_ECC_DISABLED_FLAG          ((uint32)0x00004000U)                  /*!< (1 << 14) Card ecc disabled status bit */
#define SD_IP_R1_ERASE_RESET_FLAG                ((uint32)0x00002000U)                  /*!< (1 << 13) Erase reset status bit */
#define SD_IP_R1_READY_FOR_DATA_FLAG             ((uint32)0x00000100U)                  /*!< (1 << 8) Ready for data status bit */
#define SD_IP_R1_SWITCH_ERROR_FLAG               ((uint32)0x00000080U)                  /*!< (1 << 7) Switch error status bit */
#define SD_IP_R1_APPLICATIONC_COMMAND_FLAG       ((uint32)0x00000020U)                  /*!< (1 << 5) Application command enabled status bit */
#define SD_IP_R1_AUTHENTICATE_SEQ_ERROR          ((uint32)0x00000008U)                  /*!< (1 << 3) error in the sequence of authentication process */

#define SD_IP_R1_ALL_ERROR_FLAGS  (SD_IP_R1_OUT_OF_RANGE_ERROR | SD_IP_R1_ADDRESS_ERROR | SD_IP_R1_BLOCK_LENGHT_ERROR | SD_IP_R1_ERASE_SEQ_ERROR | \
        SD_IP_R1_ERASE_PARAMETER_ERROR | SD_IP_R1_WRITE_PROTECT_VIOLATION | SD_IP_R1_CARD_IS_LOCKED | SD_IP_R1_LOCK_UNLOCK_FAILED | SD_IP_R1_COMMAND_CRC_FAILED | \
        SD_IP_R1_ILLEGAL_COMMAND | SD_IP_R1_CARD_ECC_FAILED | SD_IP_R1_CARD_CONTROLLER_ERROR | SD_IP_R1_UNKNOWN_ERROR | SD_IP_R1_CID_CSD_OVERWRITE | SD_IP_R1_AUTHENTICATE_SEQ_ERROR)

/*! @brief R1: current state */
#define SD_IP_R1_CURRENT_STATE(x)    (((x)&0x00001E00U) >> 9U)

/*! @brief CURRENT_STATE filed in R1 */
typedef enum
{
    SD_EMMC_IP_R1_STATE_IDLE = 0U,        /*!< R1: current state: idle */
    SD_EMMC_IP_R1_STATE_READY = 1U,       /*!< R1: current state: ready */
    SD_EMMC_IP_R1_STATE_IDENTIFY = 2U,    /*!< R1: current state: identification */
    SD_EMMC_IP_R1_STATE_STANDBY = 3U,     /*!< R1: current state: standby */
    SD_EMMC_IP_R1_STATE_TRANSFER = 4U,    /*!< R1: current state: transfer */
    SD_EMMC_IP_R1_STATE_SEND_DATA = 5U,    /*!< R1: current state: sending data */
    SD_EMMC_IP_R1_STATE_RECEIVE_DATA = 6U, /*!< R1: current state: receiving data */
    SD_EMMC_IP_R1_STATE_PROGRAM = 7U,     /*!< R1: current state: programming */
    SD_EMMC_IP_R1_STATE_DISCONNECT = 8U,  /*!< R1: current state: disconnect */
} Sd_Ip_R1CurrentStateType;

/*! @brief SD card individual commands */
typedef enum
{
    SD_EMMC_IP_COMMAND_SEND_RELATIVE_ADDRESS = 3U,    /*!< Send Relative Address */
    SD_EMMC_IP_COMMAND_SWITCH = 6U,                   /*!< Switch Function */
    SD_EMMC_IP_COMMAND_SEND_INTERFACE_CONDITION = 8U, /*!< Send Interface Condition */
    SD_EMMC_IP_COMMAND_VOLTAGE_SWITCH = 11U,          /*!< Voltage Switch */
    SD_EMMC_IP_COMMAND_SPEED_CLASS_CONTROL = 20U,     /*!< Speed Class control */
    SD_EMMC_IP_COMMAND_ERASE_WRITE_BLOCK_START = 32U, /*!< Write Block Start */
    SD_EMMC_IP_COMMAND_ERASE_WRITE_BLOCK_END = 33U,   /*!< Write Block End */
} Sd_Ip_CommandType;

/*! @brief SD card individual application commands */
typedef enum
{
    SD_EMMC_IP_COMMAND_APPLICATION_SET_BUS_WIDTH = 6U,               /*!< Set Bus Width */
    SD_EMMC_IP_COMMAND_APPLICATION_STATUS = 13U,                      /*!< Send SD status */
    SD_EMMC_IP_COMMAND_APPLICATION_SEND_NUMBER_WRITE_BLOCKS = 22U,    /*!< Send Number Of Written Blocks */
    SD_EMMC_IP_COMMAND_APPLICATION_SET_WRITE_BLOCK_ERASE_COUNT = 23U, /*!< Set Write Block Erase Count */
    SD_EMMC_IP_COMMAND_APPLICATION_SEND_OPERATION_CONDITION = 41U,    /*!< Send Operation Condition */
    SD_EMMC_IP_COMMAND_APPLICATION_SET_CLEAR_CARD_DETECT = 42U,       /*!< Set Connect/Disconnect pull up on detect pin */
    SD_EMMC_IP_COMMAND_APPLICATION_SEND_SCR = 51U,                    /*!< Send Scr */
} Sd_Ip_ApplicationCmdType;

/*! @brief SD/MMC card common commands */
typedef enum
{
    SD_EMMC_IP_COMMAND_GO_IDLE_STATE = 0U,         /*!< Go Idle State */
    SD_EMMC_IP_COMMAND_ALL_SEND_CID = 2U,          /*!< All Send CID */
    SD_EMMC_IP_COMMAND_SET_DSR = 4U,               /*!< Set DSR */
    SD_EMMC_IP_COMMAND_SELECT_CARD = 7U,           /*!< Select Card */
    SD_EMMC_IP_COMMAND_SEND_CSD = 9U,              /*!< Send CSD */
    SD_EMMC_IP_COMMAND_SEND_CID = 10U,             /*!< Send CID */
    SD_EMMC_IP_COMMAND_STOP_TRANSMISSION = 12U,    /*!< Stop Transmission */
    SD_EMMC_IP_COMMAND_SEND_STATUS = 13U,          /*!< Send Status */
    SD_EMMC_IP_COMMAND_GO_INACTIVE_STATE = 15U,    /*!< Go Inactive State */
    SD_EMMC_IP_COMMAND_SET_BLOCK_LENGTH = 16U,     /*!< Set Block Length */
    SD_EMMC_IP_COMMAND_READ_SINGLE_BLOCK = 17U,    /*!< Read Single Block */
    SD_EMMC_IP_COMMAND_READ_MULTIPLE_BLOCK = 18U,  /*!< Read Multiple Block */
    SD_EMMC_IP_COMMAND_SEND_TUNING_BLOCK = 19U,    /*!< Send Tuning Block */
    SD_EMMC_IP_COMMAND_SEND_TUNING_PATTERN = 21U,  /*!< Send Tuning Pattern HS200 */
    SD_EMMC_IP_COMMAND_SET_BLOCK_COUNT = 23U,      /*!< Set Block Count */
    SD_EMMC_IP_COMMAND_WRITE_SINGLE_BLOCK = 24U,   /*!< Write Single Block */
    SD_EMMC_IP_COMMAND_WRITE_MULTIPLE_BLOCK = 25U, /*!< Write Multiple Block */
    SD_EMMC_IP_COMMAND_PROGRAM_CSD = 27U,          /*!< Program CSD */
    SD_EMMC_IP_COMMAND_SET_WRITE_PROTECT = 28U,    /*!< Set Write Protect */
    SD_EMMC_IP_COMMAND_CLEAR_WRITE_PROTECT = 29U,  /*!< Clear Write Protect */
    SD_EMMC_IP_COMMAND_SEND_WRITE_PROTECT = 30U,   /*!< Send Write Protect */
    SD_EMMC_IP_COMMAND_ERASE = 38U,                /*!< Erase */
    SD_EMMC_IP_COMMAND_LOCK_UNLOCK = 42U,          /*!< Lock Unlock */
    SD_EMMC_IP_COMMAND_SEND_APPLICATION_COMMAND = 55U,  /*!< Send Application Command */
    SD_EMMC_IP_COMMAND_GENERAL_COMMAND = 56U,      /*!< General Purpose Command */
    SD_EMMC_IP_COMMAND_READ_OCR = 58U,             /*!< Read OCR */
} Sd_Ip_SDMMC_CommandType;

/*! @brief MMC card individual commands */
typedef enum
{
    SD_EMMC_IP_COMMAND_MMC_SEND_OPERATION_CONDITION = 1U, /*!< Send Operation Condition */
    SD_EMMC_IP_COMMAND_MMC_SET_RELATIVE_ADDRESS = 3U,     /*!< Set Relative Address */
    SD_EMMC_IP_COMMAND_MMC_SLEEP_AWAKE = 5U,              /*!< Sleep Awake */
    SD_EMMC_IP_COMMAND_MMC_SWITCH = 6U,                   /*!< Switch */
    SD_EMMC_IP_COMMAND_MMC_SEND_EXTENDED_CSD = 8U,        /*!< Send EXT_CSD */
    SD_EMMC_IP_COMMAND_MMC_READ_DATA_UNTIL_STOP = 11U,    /*!< Read Data Until Stop */
    SD_EMMC_IP_COMMAND_MMC_BUS_TEST_READ = 14U,           /*!< Test Read */
    SD_EMMC_IP_COMMAND_MMC_WRITE_DATA_UNTIL_STOP = 20U,   /*!< Write Data Until Stop */
    SD_EMMC_IP_COMMAND_MMC_PROGRAM_CID = 26U,             /*!< Program CID */
    SD_EMMC_IP_COMMAND_MMC_ERASE_GROUP_START = 35U,       /*!< Erase Group Start */
    SD_EMMC_IP_COMMAND_MMC_ERASE_GROUP_END = 36U,         /*!< Erase Group End */
    SD_EMMC_IP_COMMAND_MMC_FAST_INPUT_OUTPUT = 39U,       /*!< Fast IO */
    SD_EMMC_IP_COMMAND_MMC_GO_INTERRUPT_STATE = 40U,      /*!< Go interrupt State */
} Sd_Ip_MmcCommandType;

/*! @brief SD card command class */
typedef enum
{
    SD_EMMC_IP_COMMAND_CLASS_BASIC = 0x1U,                    /*!< (1U << 0U) Card command class 0 */
    SD_EMMC_IP_COMMAND_CLASS_BLOCK_READ = 0x4U,               /*!< (1U << 2U) Card command class 2 */
    SD_EMMC_IP_COMMAND_CLASS_BLOCK_WRITE = 0x10U,             /*!< (1U << 4U) Card command class 4 */
    SD_EMMC_IP_COMMAND_CLASS_ERASE = 0x20U,                   /*!< (1U << 5U) Card command class 5 */
    SD_EMMC_IP_COMMAND_CLASS_WRITE_PROTECT = 0x40U,           /*!< (1U << 6U) Card command class 6 */
    SD_EMMC_IP_COMMAND_CLASS_LOCK_CARD = 0x80U,               /*!< (1U << 7U) Card command class 7 */
    SD_EMMC_IP_COMMAND_CLASS_APPLICATION_SPECIFIC = 0x100U,   /*!< (1U << 8U) Card command class 8 */
    SD_EMMC_IP_COMMAND_CLASS_INPUT_OUTPUT_MODE = 0x200U,      /*!< (1U << 9U) Card command class 9 */
    SD_EMMC_IP_COMMAND_CLASS_SWITCH = 0x400U,                 /*!< (1U << 10U) Card command class 10 */
} Sd_Ip_CommandClassType;

/*! @brief OCR register in SD card */
#define    SD_EMMC_IP_SD_OCR_POWERUP_BUSY_FLAG               0x80000000U                          /*!< (int)(1U << 31U)Power up busy status */
#define    SD_EMMC_IP_SD_OCR_HOST_CAPACITY_SUPPORT_FLAG      0x40000000U                          /*!< (1U << 30U) Card capacity status */
#define    SD_EMMC_IP_SD_OCR_CARD_CAPACITY_SUPPORT_FLAG      SD_EMMC_IP_SD_OCR_HOST_CAPACITY_SUPPORT_FLAG   /*!< Card capacity status */
#define    SD_EMMC_IP_SD_OCR_SWITCH_18_REQUEST_FLAG          0x1000000U                           /*!< (1U << 24U) Switch to 1.8V request */
#define    SD_EMMC_IP_SD_OCR_SWITCH_18_ACCEPT_FLAG           SD_EMMC_IP_SD_OCR_SWITCH_18_REQUEST_FLAG       /*!< Switch to 1.8V accepted */
#define    SD_EMMC_IP_SD_OCR_SWITCH_SDXC_POWER_CONTROL_FLAG  0x10000000U                          /*!< (1U << 28U) SDXC Power Control */
#define    SD_EMMC_IP_SD_OCR_VDD_27_28_FLAG                  0x8000U                              /*!< (1U << 15U) VDD 2.7-2.8 */
#define    SD_EMMC_IP_SD_OCR_VDD_28_29_FLAG                  0x10000U                             /*!< (1U << 16U) VDD 2.8-2.9 */
#define    SD_EMMC_IP_SD_OCR_VDD_29_30_FLAG                  0x20000U                             /*!< (1U << 17U) VDD 2.9-3.0 */
#define    SD_EMMC_IP_SD_OCR_VDD_30_31_FLAG                  0x40000U                             /*!< (1U << 18U) VDD 3.0-3.1 */
#define    SD_EMMC_IP_SD_OCR_VDD_31_32_FLAG                  0x80000U                             /*!< (1U << 19U) VDD 3.1-3.2 */
#define    SD_EMMC_IP_SD_OCR_VDD_32_33_FLAG                  0x100000U                            /*!< (1U << 20U) VDD 3.2-3.3 */
#define    SD_EMMC_IP_SD_OCR_VDD_33_34_FLAG                  0x200000U                            /*!< (1U << 21U) VDD 3.3-3.4 */
#define    SD_EMMC_IP_SD_OCR_VDD_34_35_FLAG                  0x400000U                            /*!< (1U << 22U)VDD 3.4-3.5 */
#define    SD_EMMC_IP_SD_OCR_VDD_35_36_FLAG                  0x800000U                            /*!< (1U << 23U) VDD 3.5-3.6 */

/*! @brief SD card specification version number */
typedef enum
{
    SD_EMMC_IP_SD_SPECIFICATION_VERSION_1_0 = 0x1U, /*!< (1U << 0U) SD card version 1.0-1.01 */
    SD_EMMC_IP_SD_SPECIFICATION_VERSION_1_1 = 0x2U, /*!< (1U << 1U) SD card version 1.10 */
    SD_EMMC_IP_SD_SPECIFICATION_VERSION_2_0 = 0x4U, /*!< (1U << 2U) SD card version 2.00 */
    SD_EMMC_IP_SD_SPECIFICATION_VERSION_3_0 = 0x8U, /*!< (1U << 3U) SD card version 3.0 */
} Sd_Ip_SpecificationVersionType;

/*! @brief SD card bus width */
typedef enum
{
    SD_EMMC_IP_DATA_BUS_WIDTH_1BIT = 0x1U, /*!< (1U << 0U) SD data bus width 1-bit mode */
    SD_EMMC_IP_DATA_BUS_WIDTH_4BIT = 0x4U, /*!< (1U << 2U) SD data bus width 4-bit mode */
} Sd_Ip_DataBusWidthType;

/*! @brief SD bus speed mode selection */
typedef enum
{
    SD_IP_SD_CARD_DEFAULT_SPEED_SDR12_MODE   = 0U,   /* DEFAULT_SPEED mode for 3.3V signaling and SDR12 mode for 1.8V signaling */
    SD_IP_SD_CARD_HIGH_SPEED_SDR25_MODE     = 1U,   /* HIGH_SPEED mode for 3.3V signaling and SDR25 mode for 1.8V signaling */
} Sd_Ip_SdSpeedModeType;

/*! @brief SD card switch mode */
typedef enum
{
    SD_EMMC_IP_SD_SWITCH_CHECK = 0U,   /*!< SD switch mode 0: check function */
    SD_EMMC_IP_SD_SWITCH_SET   = 1U,   /*!< SD switch mode 1: set function */
} Sd_Ip_SwitchModeType;

/*! @brief SD timing function number */
typedef enum
{
    SD_EMMC_IP_SD_FUNCTION_SDR_12_DEFAULT    = 0U,    /*!< SDR12 mode & default */
    SD_EMMC_IP_SD_FUNCTION_SDR_25_HIGH_SPEED = 1U,    /*!< SDR25 & high speed */
    SD_EMMC_IP_SD_FUNCTION_SDR_50            = 2U,    /*!< SDR50 mode */
    SD_EMMC_IP_SD_FUNCTION_SDR_104           = 3U,    /*!< SDR104 mode */
    SD_EMMC_IP_SD_FUNCTION_DDR_50            = 4U,    /*!< DDR50 mode */
} Sd_Ip_TimingFunctionType;

/*! @brief SD group number */
typedef enum
{
    SD_EMMC_IP_SD_GROUP_TIMING_MODE     = 0U,   /*!< access mode group */
    SD_EMMC_IP_SD_GROUP_COMMAND_SYSTEM  = 1U,   /*!< command system group */
    SD_EMMC_IP_SD_GROUP_DRIVER_STRENGTH = 2U,   /*!< driver strength group */
    SD_EMMC_IP_SD_GROUP_CURRENT_LIMIT   = 3U,   /*!< current limit group */
} Sd_Ip_GroupNumType;

/*! @brief SD card driver strength */
typedef enum
{
    SD_EMMC_IP_SD_DRIVER_STRENGTH_TYPEB = 0U, /*!< default driver strength*/
    SD_EMMC_IP_SD_DRIVER_STRENGTH_TYPEA = 1U, /*!< driver strength TYPE A */
    SD_EMMC_IP_SD_DRIVER_STRENGTH_TYPEC = 2U, /*!< driver strength TYPE C */
    SD_EMMC_IP_SD_DRIVER_STRENGTH_TYPED = 3U, /*!< driver strength TYPE D */
} Sd_Ip_DriverStrenghtType;

/*! @brief SD card current limit */
typedef enum
{
    SD_EMMC_IP_SD_CURRENT_LIMIT_200MA = 0U, /*!< default current limit */
    SD_EMMC_IP_SD_CURRENT_LIMIT_400MA = 1U, /*!< current limit to 400MA */
    SD_EMMC_IP_SD_CURRENT_LIMIT_600MA = 2U, /*!< current limit to 600MA */
    SD_EMMC_IP_SD_CURRENT_LIMIT_800MA = 3U, /*!< current limit to 800MA */
} Sd_Ip_MaxCurrentType;

/*! @brief SD card SCR register flags */
typedef enum
{
    SD_EMMC_IP_SD_SCR_DATA_STATUS_AFTER_ERASE = 0x1U,     /*!< (1U << 0U) Data status after erases [55:55] */
    SD_EMMC_IP_SD_SCR_SD_SPECIFICATION_3      = 0x2U,     /*!< (1U << 1U) Specification version 3.00 or higher [47:47]*/
} Sd_Ip_ScrFlagType;

/*! @brief SD card CSD register flags */

#define SD_IP_CSD_READ_BLOCK_PARTIAL_FLAG           (0x0001U)   /*!< (1U << 0U) Partial blocks for read allowed [79:79] */
#define SD_IP_CSD_WRITE_BLOCK_MISALIGN_FLAG         (0x0002U)   /*!< (1U << 1U) Write block misalignment [78:78] */
#define SD_IP_CSD_READ_BLOCK_MISALIGN_FLAG          (0x0004U)   /*!< (1U << 2U) Read block misalignment [77:77] */
#define SD_IP_CSD_DSR_IMPLEMENTATION_FLAG           (0x0008U)   /*!< (1U << 3U) DSR implemented [76:76] */
#define SD_IP_CSD_ERASE_BLOCK_ENABLED_FLAG          (0x0010U)   /*!< (1U << 4U) Erase single block enabled [46:46] */
#define SD_IP_CSD_WRITE_PROTECT_GROUP_ENABLED_FLAG  (0x0020U)   /*!< (1U << 5U) Write protect group enabled [31:31] */
#define SD_IP_CSD_WRITE_BLOCK_PARTIAL_FLAG          (0x0040U)   /*!< (1U << 6U) Partial blocks for write allowed [21:21] */
#define SD_IP_CSD_FILE_FORMAT_GROUP_FLAG            (0x0080U)   /*!< (1U << 7U) File format group [15:15] */
#define SD_IP_CSD_COPY_FLAG                         (0x0100U)   /*!< (1U << 8U) Copy flag [14:14] */
#define SD_IP_CSD_PERMANENT_WRITE_PROTECT_FLAG      (0x0200U)   /*!< (1U << 9U) Permanent write protection [13:13] */
#define SD_IP_CSD_TEMPORARY_WRITE_PROTECT_FLAG      (0x0400U)   /*!< (1U << 10U) Temporary write protection [12:12] */

/*! @brief The bit mask for VOLTAGE WINDOW 1.70V to 1.95V field in OCR */
#define SD_EMMC_IP_MMC_OCR_V170TO195_SHIFT (7U)
/*! @brief The bit mask for VOLTAGE WINDOW 1.70V to 1.95V field in OCR */
#define SD_EMMC_IP_MMC_OCR_V170TO195_MASK (0x00000080U)
/*! @brief The bit shift for VOLTAGE WINDOW 2.00V to 2.60V field in OCR */
#define SD_EMMC_IP_MMC_OCR_V200TO260_SHIFT (8U)
/*! @brief The bit mask for VOLTAGE WINDOW 2.00V to 2.60V field in OCR */
#define SD_EMMC_IP_MMC_OCR_V200TO260_MASK (0x00007F00U)
/*! @brief The bit shift for VOLTAGE WINDOW 2.70V to 3.60V field in OCR */
#define SD_EMMC_IP_MMC_OCR_V270TO360_SHIFT (15U)
/*! @brief The bit mask for VOLTAGE WINDOW 2.70V to 3.60V field in OCR */
#define SD_EMMC_IP_MMC_OCR_V270TO360_MASK (0x00FF8000U)
/*! @brief The bit shift for ACCESS MODE field in OCR */
#define SD_EMMC_IP_MMC_OCR_ACCESS_MODE_SHIFT (29U)
/*! @brief The bit mask for ACCESS MODE field in OCR */
#define SD_EMMC_IP_MMC_OCR_ACCESS_MODE_MASK (0x60000000U)
/*! @brief The bit mask for SECTOR ACCESS MODE in OCR */
#define SD_EMMC_IP_MMC_OCR_SECTOR_ACCESS_MODE_MASK (0x40000000U)
/*! @brief The bit shift for BUSY field in OCR */
#define SD_EMMC_IP_MMC_OCR_BUSY_SHIFT (31UL)
/*! @brief The bit mask for BUSY field in OCR */
#define SD_EMMC_IP_MMC_OCR_BUSY_MASK (1UL << SD_EMMC_IP_MMC_OCR_BUSY_SHIFT)

/*! @brief The bit shift for FREQUENCY UNIT field in TRANSFER SPEED(TRAN-SPEED in Extended CSD) */
#define SD_EMMC_IP_MMC_TRANSFER_FREQUENCY_UNIT_SHIFT (0U)
/*! @brief The bit mask for FRQEUENCY UNIT in TRANSFER SPEED */
#define SD_EMMC_IP_MMC_TRANSFER_FREQUENCY_UNIT_MASK (0x07U)
/*! @brief The bit shift for MULTIPLIER field in TRANSFER SPEED */
#define SD_EMMC_IP_MMC_TRANSFER_MULTIPLIER_SHIFT (3U)
/*! @brief The bit mask for MULTIPLIER field in TRANSFER SPEED  */
#define SD_EMMC_IP_MMC_TRANSFER_MULTIPLIER_MASK (0x78U)

/*! @brief Read the value of FREQUENCY UNIT in TRANSFER SPEED. */
#define SD_EMMC_IP_READ_MMC_TRANSFER_SPEED_FREQUENCY_UNIT(CSD) \
    (((CSD.transferSpeed) & SD_EMMC_IP_MMC_TRANSFER_FREQUENCY_UNIT_MASK) >> SD_EMMC_IP_MMC_TRANSFER_FREQUENCY_UNIT_SHIFT)
/*! @brief Read the value of MULTIPLER filed in TRANSFER SPEED. */
#define SD_EMMC_IP_READ_MMC_TRANSFER_SPEED_MULTIPLIER(CSD) \
    (((CSD.transferSpeed) & SD_EMMC_IP_MMC_TRANSFER_MULTIPLIER_MASK) >> SD_EMMC_IP_MMC_TRANSFER_MULTIPLIER_SHIFT)

/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_SEC_CNT field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_SEC_CNT_SHIFT (0U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_DATA_SECTOR_SIZE field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_DATA_SECTOR_SIZE_SHIFT (8U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_ERASED_MEM_CONT field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_ERASED_MEM_CONT_SHIFT (8U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_BUS_WIDTH field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_BUS_WIDTH_SHIFT (24U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_REV field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_REV_SHIFT (0U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_STRUCTURE field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_STRUCTURE_SHIFT (16U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_CARD_TYPE field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_CARD_TYPE_SHIFT (0U)
/*! @brief The bit mask for SD_EMMC_IP_MMC_EXT_CSD_CARD_TYPE field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_CARD_TYPE_MASK (0xFFU)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_STROBE_SUPPORT field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_STROBE_SUPPORT_SHIFT (0U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_STROBE_SUPPORT field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_HS_TIMING_SHIFT (8U)

/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_INDEX_PARTITION_CONFIG field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_PARTITION_CONFIG_SHIFT (24U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_SIZE_MULT field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_BOOT_SIZE_MULT_SHIFT (16U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_INFO field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_BOOT_INFO_SHIFT (0U)
/*! @brief The bit shift for SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_BUS_CONDITIONS field in extended CSD register */
#define SD_EMMC_IP_MMC_EXT_CSD_BOOT_BUS_CONDITIONS_SHIFT (8U)

/*! @brief MMC card CSD register flags */
typedef enum
{
    SD_EMMC_IP_MMC_CSD_READ_BLOCK_PARTIAL_FLAG            = 0x1U,     /*!< (1U << 0U) Partial blocks for read allowed */
    SD_EMMC_IP_MMC_CSD_WRITE_BLOCK_MISALIGN_FLAG          = 0x02U,    /*!< (1U << 1U) Write block misalignment */
    SD_EMMC_IP_MMC_CSD_READ_BLOCK_MISALIGN_FLAG           = 0x4U,     /*!< (1U << 2U) Read block misalignment */
    SD_EMMC_IP_MMC_CSD_DSR_IMPLEMENTED_FLAG               = 0x8U,     /*!< (1U << 3U) DSR implemented */
    SD_EMMC_IP_MMC_CSD_WRITE_PROTECT_GROUP_ENABLED_FLAG   = 0x10U,    /*!< (1U << 4U) Write protect group enabled */
    SD_EMMC_IP_MMC_CSD_WRITE_BLOCK_PARTIAL_FLAG           = 0x20U,    /*!< (1U << 5U) Partial blocks for write allowed */
    SD_EMMC_IP_MMC_CSD_CONTENT_PROTECT_APPLICATION_FLAG       = 0x40U,    /*!< (1U << 6U) Content protect application */
    SD_EMMC_IP_MMC_CSD_FILE_FORMAT_GROUP_FLAG             = 0x80U,    /*!< (1U << 7U) File format group */
    SD_EMMC_IP_MMC_CSD_COPY_FLAG                          = 0x100U,   /*!< (1U << 8U) Copy flag */
    SD_EMMC_IP_MMC_CSD_PERMANENT_WRITE_PROTECT_FLAG       = 0x200U,   /*!< (1U << 9U) Permanent write protection */
    SD_EMMC_IP_MMC_CSD_TEMPORARY_WRITE_PROTECT_FLAG       = 0x400U,   /*!< (1U << 10U) Temporary write protection */
} Sd_Ip_MmcECsdFlagType;

/*! @brief EXT CSD byte index */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_FLUSH_CACHE            (32U)  /*!< W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_CACHE_CTRL             (33U)  /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_POWER_OFF_NOTIFICATION (34U)  /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_EXP_EVENTS_STATUS      (54U)  /*!< RO, 2 bytes */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_DATA_SECTOR_SIZE       (61U)  /*!< R */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_NATIVE_SECTOR_SIZE     (63U)  /*!< R */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_GP_SIZE_MULT           (143U) /*!< R/W, 12 bytes */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PARTITION_ATTRIBUTE    (156U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PARTITION_SUPPORT      (160U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_HPI_MGMT               (161U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_RST_N_FUNCTION         (162U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BKOPS_EN               (163U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BKOPS_START            (164U) /*!< W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_SANITIZE_START         (165U) /*!< W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_WR_REL_PARAM           (166U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_USER_WP                (171U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_WP                (173U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_WP_STATUS         (174U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_ERASE_GROUP_DEF        (175U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_BUS_CONDITIONS    (177U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_CONFIG_PROT       (178U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PARTITION_CONFIG       (179U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_ERASED_MEM_CONT        (181U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BUS_WIDTH              (183U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_STROBE_SUPPORT               (184U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_HS_TIMING              (185U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_POWER_CLASS            (187U) /*!< R/W */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_REV                    (192U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_STRUCTURE              (194U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_CARD_TYPE              (196U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_OUT_OF_INTERRUPT_TIME  (198U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PART_SWITCH_TIME       (199U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_52_195          (200U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_26_195          (201U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_52_360          (202U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_26_360          (203U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_SEC_CNT                (212U) /*!< RO, 4 bytes */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_S_A_TIMEOUT            (217U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_REL_WR_SEC_C           (222U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_HC_WP_GRP_SIZE         (221U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_ERASE_TIMEOUT_MULT     (223U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_HC_ERASE_GRP_SIZE      (224U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_SIZE_MULT         (226U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BOOT_INFO              (228U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_SEC_TRIM_MULT          (229U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_SEC_ERASE_MULT         (230U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_SEC_FEATURE_SUPPORT    (231U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_TRIM_MULT              (232U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_200_130         (236U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_200_195         (237U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_DDR_52_195      (238U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_PWR_CL_DDR_52_360      (239U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BKOPS_STATUS           (246U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_POWER_OFF_LONG_TIME    (247U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_GENERIC_CMD6_TIME      (248U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_CACHE_SIZE             (249U) /*!< RO, 4 bytes */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_TAG_UNIT_SIZE          (498U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_DATA_TAG_SUPPORT       (499U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_MAX_PACKED_WRITES      (500U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_MAX_PACKED_READS       (501U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_BKOPS_SUPPORT          (502U) /*!< RO */
#define SD_EMMC_IP_MMC_EXT_CSD_INDEX_HPI_FEATURES           (503U)  /*!< RO */

/*! @brief The length of Extended CSD register, unit as bytes. */
#define SD_EMMC_IP_MMC_EXTENDED_CSD_BYTES (512U)

/*! @brief MMC card default relative address */
#define SD_EMMC_IP_MMC_DEFAULT_RELATIVE_ADDRESS (2U)

/*! @brief SD card product name length united as bytes. */
#define SD_EMMC_IP_SD_PRODUCT_NAME_BYTES (5U)

/*! @brief MMC card product name length united as bytes. */
#define SD_EMMC_IP_MMC_PRODUCT_NAME_BYTES (6U)

/*! @brief SD card CID register */
typedef struct
{
    uint8 manufacturerID;                     /*!< Manufacturer ID [127:120] */
    uint16 applicationID;                     /*!< OEM/Application ID [119:104] */
    uint8 productName[SD_EMMC_IP_SD_PRODUCT_NAME_BYTES]; /*!< Product name [103:64] */
    uint8 productVersion;                     /*!< Product revision [63:56] */
    uint32 productSerialNumber;               /*!< Product serial number [55:24] */
    uint16 manufacturerData;                  /*!< Manufacturing date [19:8] */
} Sd_Ip_CidType;

/*! @brief MMC card CID register. */
typedef struct
{
    uint32 productSerialNumber;                /*!< Product serial number */
    uint16 applicationID;                      /*!< OEM/Application ID */
    uint8 manufacturerID;                      /*!< Manufacturer ID */
    uint8 productName[SD_EMMC_IP_MMC_PRODUCT_NAME_BYTES]; /*!< Product name */
    uint8 productVersion;                      /*!< Product revision */
    uint8 manufacturerData;                    /*!< Manufacturing date */
} Sd_Ip_MmcCidType;

/*! @brief SD card CSD register */
typedef struct
{
    uint8 csdStructure;        /*!< CSD structure [127:126] */
    uint8 dataReadAccessTime1; /*!< Data read access-time-1 [119:112] */
    uint8 dataReadAccessTime2; /*!< Data read access-time-2 in clock cycles (NSAC*100) [111:104] */
    uint8 transferSpeed;       /*!< Maximum data transfer rate [103:96] */
    uint16 cardCommandClass;   /*!< Card command classes [95:84] */
    uint8 readBlockLength;     /*!< Maximum read data block length [83:80] */
    uint16 flags;              /*!< Flags in sd_csd_flag_t */
    uint32 deviceSize;         /*!< Device size [73:62] */
    /* Following fields from 'readCurrentVddMin' to 'deviceSizeMultiplier' exist in CSD version 1 */
    uint8 readCurrentVddMin;    /*!< Maximum read current at VDD min [61:59] */
    uint8 readCurrentVddMax;    /*!< Maximum read current at VDD max [58:56] */
    uint8 writeCurrentVddMin;   /*!< Maximum write current at VDD min [55:53] */
    uint8 writeCurrentVddMax;   /*!< Maximum write current at VDD max [52:50] */
    uint8 deviceSizeMultiplier; /*!< Device size multiplier [49:47] */

    uint8 eraseSectorSize;       /*!< Erase sector size [45:39] */
    uint8 writeProtectGroupSize; /*!< Write protect group size [38:32] */
    uint8 writeSpeedFactor;      /*!< Write speed factor [28:26] */
    uint8 writeBlockLength;      /*!< Maximum write data block length [25:22] */
    uint8 fileFormat;            /*!< File format [11:10] */
} Sd_Ip_CsdType;

/*! @brief The bit shift for RATE UNIT field in TRANSFER SPEED */
#define SD_EMMC_IP_SD_TRANSFER_SPEED_RATE_UNIT_SHIFT (0U)
/*! @brief The bit mask for RATE UNIT field in TRANSFER SPEED */
#define SD_EMMC_IP_SD_TRANSFER_SPEED_RATE_UNIT_MASK (0x07U)
/*! @brief The bit shift for TIME VALUE field in TRANSFER SPEED */
#define SD_EMMC_IP_SD_TRANSFER_SPEED_TIME_VALUE_SHIFT (2U)
/*! @brief The bit mask for TIME VALUE field in TRANSFER SPEED */
#define SD_EMMC_IP_SD_TRANSFER_SPEED_TIME_VALUE_MASK (0x78U)
/*! @brief Read the value of FREQUENCY UNIT in TRANSFER SPEED field */
#define SD_EMMC_IP_SD_RD_TRANSFER_SPEED_RATE_UNIT(x) \
    (((x.transferSpeed) & SD_EMMC_IP_SD_TRANSFER_SPEED_RATE_UNIT_MASK) >> SD_EMMC_IP_SD_TRANSFER_SPEED_RATE_UNIT_SHIFT)
/*! @brief Read the value of TIME VALUE in TRANSFER SPEED field */
#define SD_EMMC_IP_SD_RD_TRANSFER_SPEED_TIME_VALUE(x) \
    (((x.transferSpeed) & SD_EMMC_IP_SD_TRANSFER_SPEED_TIME_VALUE_MASK) >> SD_EMMC_IP_SD_TRANSFER_SPEED_TIME_VALUE_SHIFT)

/*! @brief SD card SCR register */
typedef struct
{
    uint8 scrStructure;             /*!< SCR Structure [63:60] */
    uint8 sdSpecification;          /*!< SD memory card specification version [59:56] */
    uint16 flags;                   /*!< SCR flags in Sd_Ip_ScrFlagType */
    uint8 sdSecurity;               /*!< Security specification supported [54:52] */
    uint8 sdBusWidths;              /*!< Data bus widths supported [51:48] */
    uint8 extendedSecurity;         /*!< Extended security support [46:43] */
    uint8 commandSupport;           /*!< Command support bits [33:32] */
    uint32 reservedForManufacturer; /*!< reserved for manufacturer usage [31:0] */
} Sd_Ip_ScrType;

/*! @brief MMC and MMC card CSD register. */
typedef struct
{
    uint8 csdStructureVersion;        /*!< CSD structure [127:126] */
    uint8 systemSpecificationVersion; /*!< System specification version [125:122] */
    uint8 dataReadAccessTime1;        /*!< Data read access-time 1 [119:112] */
    uint8 dataReadAccessTime2;        /*!< Data read access-time 2 in CLOCK cycles (NSAC*100) [111:104] */
    uint8 transferSpeed;              /*!< Max. bus clock frequency [103:96] */
    uint16 cardCommandClass;          /*!< card command classes [95:84] */
    uint8 readBlockLength;            /*!< Max. read data block length [83:80] */
    uint16 flags;                     /*!< Contain flags in Sd_Ip_MmcECsdFlagType */
    uint16 deviceSize;                /*!< Device size [73:62] */
    uint8 readCurrentVddMin;          /*!< Max. read current @ VDD min [61:59] */
    uint8 readCurrentVddMax;          /*!< Max. read current @ VDD max [58:56] */
    uint8 writeCurrentVddMin;         /*!< Max. write current @ VDD min [55:53] */
    uint8 writeCurrentVddMax;         /*!< Max. write current @ VDD max [52:50] */
    uint8 deviceSizeMultiplier;       /*!< Device size multiplier [49:47] */
    uint8 eraseGroupSize;             /*!< Erase group size [46:42] */
    uint8 eraseGroupSizeMultiplier;   /*!< Erase group size multiplier [41:37] */
    uint8 writeProtectGroupSize;      /*!< Write protect group size [36:32] */
    uint8 defaultEcc;                 /*!< Manufacturer default ECC [30:29] */
    uint8 writeSpeedFactor;           /*!< Write speed factor [28:26] */
    uint8 maxWriteBlockLength;        /*!< Max. write data block length [25:22] */
    uint8 fileFormat;                 /*!< File format [11:10] */
    uint8 eccCode;                    /*!< ECC code [9:8] */
} Sd_Ip_MmcCsdType;

/*! @brief MMC and MMC card Extended CSD register (unit: byte). */
typedef struct
{
    uint8 highDensityEraseGroupDefinition;       /*!< High-density erase group definition [175] */
    uint8 bootBusCondition;                      /*!< Boot bus condition [177] */
    uint8 bootConfig;                            /*!< Boot configuration [179] */
    uint8 eraseMemoryContent;                    /*!< Erased memory content [181] */
    uint8 dataBusWidth;                          /*!< Data bus width mode [183] */
    uint8 strobeSupport;                         /*!< Enhanced strobe support [184] */
    uint8 highSpeedTiming;                       /*!< High-speed interface timing [185] */
    uint8 powerClass;                            /*!< Power class [187] */
    uint8 commandSetRevision;                    /*!< Command set revision [189] */
    uint8 commandSet;                            /*!< Command set [191] */
    uint8 extendecCsdVersion;                    /*!< Extended CSD revision [192] */
    uint8 csdStructureVersion;                   /*!< CSD structure version [194] */
    uint8 cardType;                              /*!< Card Type [196] */
    uint8 powerClass52MHz195V;                   /*!< Power Class for 52MHz @ 1.95V [200] */
    uint8 powerClass26MHz195V;                   /*!< Power Class for 26MHz @ 1.95V [201] */
    uint8 powerClass52MHz360V;                   /*!< Power Class for 52MHz @ 3.6V [202] */
    uint8 powerClass26MHz360V;                   /*!< Power Class for 26MHz @ 3.6V [203] */
    uint8 minimumReadPerformance4Bit26MHz;       /*!< Minimum Read Performance for 4bit at 26MHz [205] */
    uint8 minimumWritePerformance4Bit26MHz;      /*!< Minimum Write Performance for 4bit at 26MHz [206] */
    uint8 minimumReadPerformance8Bit26MHz4Bit52MHz; /*!< Minimum read Performance for 8bit at 26MHz/4bit @52MHz [207] */
    uint8 minimumWritePerformance8Bit26MHz4Bit52MHz; /*!< Minimum Write Performance for 8bit at 26MHz/4bit @52MHz [208] */
    uint8 minimumReadPerformance8Bit52MHz;       /*!< Minimum Read Performance for 8bit at 52MHz [209] */
    uint8 minimumWritePerformance8Bit52MHz;      /*!< Minimum Write Performance for 8bit at 52MHz [210] */
    uint32 sectorCount;                          /*!< Sector Count [215:212] */
    uint8 sleepAwakeTimeout;                     /*!< Sleep/awake timeout [217] */
    uint8 sleepCurrentVCCQ;                      /*!< Sleep current (VCCQ) [219] */
    uint8 sleepCurrentVCC;                       /*!< Sleep current (VCC) [220] */
    uint8 highCapacityWriteProtectGroupSize;     /*!< High-capacity write protect group size [221] */
    uint8 reliableWriteSectorCount;              /*!< Reliable write sector count [222] */
    uint8 highCapacityEraseTimeout;              /*!< High-capacity erase timeout [223] */
    uint8 highCapacityEraseUnitSize;             /*!< High-capacity erase unit size [224] */
    uint8 accessSize;                            /*!< Access size [225] */
    uint8 bootSizeMultiplier;                    /*!< Boot partition size [226] */
    uint8 bootInformation;                       /*!< Boot information [228] */
    uint8 supportedCommandSet;                   /*!< Supported Command Sets [504] */
    uint8 hdEraseGroupDef;                       /*!< High-density erase group definition [175]*/
    uint8 dataSectorSize;                        /*!< Sector Size [61]*/
    uint8 nativeSectorSize;                      /*!< Native sector Size [63]*/
} Sd_Ip_MmcECsrType;

/*! @brief The bit shift for COMMAND SET field in SWITCH command. */
#define SD_EMMC_IP_MMC_SWITCH_COMMAND_SET_SHIFT (0U)
/*! @brief The bit mask for COMMAND set field in SWITCH command. */
#define SD_EMMC_IP_MMC_SWITCH_COMMAND_SET_MASK (0x00000007U)
/*! @brief The bit shift for VALUE field in SWITCH command */
#define SD_EMMC_IP_MMC_SWITCH_VALUE_SHIFT (8U)
/*! @brief The bit mask for VALUE field in SWITCH command */
#define SD_EMMC_IP_MMC_SWITCH_VALUE_MASK (0x0000FF00U)
/*! @brief The bit shift for BYTE INDEX field in SWITCH command */
#define SD_EMMC_IP_MMC_SWITCH_BYTE_INDEX_SHIFT (16U)
/*! @brief The bit mask for BYTE INDEX field in SWITCH command */
#define SD_EMMC_IP_MMC_SWITCH_BYTE_INDEX_MASK (0x00FF0000U)
/*! @brief The bit shift for ACCESS MODE field in SWITCH command */
#define SD_EMMC_IP_MMC_SWITCH_ACCESS_MODE_SHIFT (24U)
/*! @brief The bit mask for ACCESS MODE field in SWITCH command */
#define SD_EMMC_IP_MMC_SWTICH_ACCESS_MODE_MASK (0x03000000U)


/*! @brief Memory card flags */
typedef enum
{
    SD_IP_SUPPORT_SPEED_CLASS_CONTROL_CMD =   (1U << 0U),    /*!< Card supports speed class */
    SD_IP_SUPPORT_SET_BLOCK_COUNT_CMD     =   (1U << 1U),    /*!< Card supports CMD23 */
    SD_IP_SUPPORT_4_BIT_WIDTH_FLAG        =   (1U << 2U),    /*!< Support 4-bit data width */
    SD_IP_SUPPORT_HIGH_CAPACITY_FLAG      =   (1U << 3U),    /*!< Support high capacity */
    SD_IP_SUPPORT_SDHC_FLAG               =   (1U << 4U),    /*!< Card is SDHC */
    SD_IP_SUPPORT_SDXC_FLAG               =   (1U << 5U),    /*!< Card is SDXC */
    SD_IP_WRITE_PROTECT_FLAG              =   (1U << 6U),    /*!< Card has write protection lock enabled */
    SD_IP_SUPPORT_VOLTAGE_180V            =   (1U << 7U),    /*!< Card supports 1.8V */
} Sd_Ip_CardFlagType;

/*! @brief SDHC transfer storage. */
typedef struct
{
    Usdhc_Ip_TransferType content;     /* Transfer state */
    Usdhc_Ip_CommandType  command;     /* Card command-related attribute */
    Usdhc_Ip_DataType     data;        /* Data-related attribute */
} Usdhc_Ip_TransferStorageType;

/*! @brief SD or MMC card type: memory card type that can be plugged into the SD port */
typedef uint8 Sd_Ip_ProtocolType;

#define SD_IP_MEMORY_CARD_SD               0U   /* SD card */
#define SD_IP_MEMORY_CARD_MMC              1U   /* MMC card */
#define SD_IP_MEMORY_CARD_NOT_SUPPORTED    2U   /* Unsupported card type */

/*! @brief MMC card partition access selection */
typedef enum
{
    SD_IP_MMC_PARTITION_DEFAULT           = 0U,
    SD_IP_MMC_PARTITION_BOOT_1            = 1U,
    SD_IP_MMC_PARTITION_BOOT_2            = 2U,
    SD_IP_MMC_PARTITION_RPMB              = 3U,
    SD_IP_MMC_PARTITION_GENERAL_PURPOSE_1 = 4U,
    SD_IP_MMC_PARTITION_GENERAL_PURPOSE_2 = 5U,
    SD_IP_MMC_PARTITION_GENERAL_PURPOSE_3 = 6U,
    SD_IP_MMC_PARTITION_GENERAL_PURPOSE_4 = 7U
} Sd_Ip_MmcPartitionAccessType;

/*! @brief MMC card boot partition selection */
typedef enum
{
    SD_IP_MMCBOOT_DISABLE     = 0U,
    SD_IP_MMCBOOT_PARTITION_1 = 1U,
    SD_IP_MMCBOOT_PARTITION_2 = 2U,
    SD_IP_MMCBOOT_USER_AREA   = 7U
} Sd_Ip_MmcBootPartitionType;


/*! @brief MMC card boot mode selection */
typedef enum
{
    SD_IP_MMCBOOT_SDR_LOW_SPEED  = 0U,
    SD_IP_MMCBOOT_SDR_HIGH_SPEED = 1U,
    SD_IP_MMCBOOT_DDR            = 2U
} Sd_Ip_MmcBootSpeedType;

/*! @brief MMC card boot width selection */
typedef enum
{
    SD_IP_MMCBOOT_DBW_1BIT = 0U,
    SD_IP_MMCBOOT_DBW_4BIT = 1U,
    SD_IP_MMCBOOT_DBW_8BIT = 2U
} Sd_Ip_MmcBootWidthType;

/*!
 * @brief SD and MMC card state
 *
 * Define the card structure including the necessary fields to identify and describe the card.
 */
typedef struct
{
    Sd_Ip_MmcBootPartitionType  bootPartitionSelect;        /*!< Boot partition selection */
    boolean                     ackEnable;                  /*!< ACK enable/disabled for boot process */
    Sd_Ip_MmcBootSpeedType      bootSpeed;                  /*!< Boot speed - SDR or DDR */
    Sd_Ip_MmcBootWidthType      bootWidth;                  /*!< Boot width - 1-4-8 bits */
} Sd_Emmc_Ip_BootConfigType;

/*! @brief MMC card bus width selection */
typedef enum
{
    SD_IP_DATABUSWIDTH_1BIT     = 0U,   /* 1 bit data width selection */
    SD_IP_DATABUSWIDTH_4BIT     = 1U,   /* 4 bit data width selection */
    SD_IP_DATABUSWIDTH_8BIT     = 2U,   /* 8 bit data width selection */
    SD_IP_DATABUSWIDTH_4BIT_DDR = 5U,   /* 4 bit DDR data width selection */
    SD_IP_DATABUSWIDTH_8BIT_DDR = 6U    /* 8 bit DDR data width selection */
} Sd_Ip_MmcBusWidthType;

/*! @brief MMC card speed supports */
typedef enum
{
    SD_IP_MMC_CARD_TYPE_HS_26          = (1U << 0U), /* High speed mode at 26 MHz */
    SD_IP_MMC_CARD_TYPE_HS_52          = (1U << 1U), /* High speed mode at 52 MHz */
    SD_IP_MMC_CARD_TYPE_HS_52_DDR_1_8V = (1U << 2U), /* High speed mode at 52 MHz, DDR mode, 1.8V */
    SD_IP_MMC_CARD_TYPE_HS_52_DDR_1_2V = (1U << 3U), /* High speed mode at MHz */
    SD_IP_MMC_CARD_TYPE_HS200_1_8V     = (1U << 4U), /* High speed mode at MHz */
    SD_IP_MMC_CARD_TYPE_HS200_1_2V     = (1U << 5U), /* High speed mode at MHz */
    SD_IP_MMC_CARD_TYPE_HS400_1_8V     = (1U << 6U), /* High speed mode at MHz */
    SD_IP_MMC_CARD_TYPE_HS400_1_2V     = (1U << 7U)  /* High speed mode at MHz */
} Sd_Ip_MmcCardType;

/*! @brief MMC card speed supports */
typedef enum
{
    SD_IP_MMC_BACKWARDS_COMPATIBILITY_WITH_LEGACY_MMC_CARD_MODE = 0U,   /* BACKWARDS_COMPATIBILITY_WITH_LEGACY_MMC_CARD_MODE up to 26 MHz */
    SD_IP_MMC_HIGH_SPEED_SDR_MODE  = 1U,   /* High speed mode up to 52 MHz SDR */
    SD_IP_MMC_HIGH_SPEED_DDR_MODE  = 2U,   /* High speed mode up to 52 MHz DDR */
    SD_IP_MMC_HS200_MODE           = 3U,   /* High speed mode up to maximum 200MHz, SDR */
    SD_IP_MMC_HS400_MODE           = 4U    /* High speed mode up to maximum 200MHz, DDR */
} Sd_Ip_MmcSpeedModeType;

/*!
 * @brief EMMC card capability information.
 *
 * Define structure to save the capability information of EMMC card.
 */
typedef struct
{
    boolean supportHS400; /*!< Capability flags to indicate the support for HS400 mode */
    boolean supportHS200;  /*!< Capability flags to indicate the support for HS200 mode */
    boolean supportHS52DDR; /*!< Capability flags to indicate the support for HS52DDR mode */
    boolean supportHSLegacy; /*!< Capability flags to indicate the support for HS legacy mode */
    boolean supportEnhanceStrobe; /*!< Capability flags to indicate the support for Enhanced strobe mode in HS400 */
} Sd_Ip_MmcCapabilityType;

/*!
 * @brief SD and MMC card information
 *
 * Get all information of Sd Card/Emmc
 */
typedef struct
{
    Sd_Ip_MmcCidType        *EmmcCidRegister;                        /*!< MMC Extended CID Register */
    Sd_Ip_MmcCsdType        *EmmcCsdRegister;                        /*!< MMC Extended CSD Register */
    Sd_Ip_MmcECsrType       *EmmcCsrRegister;                        /*!< MMC Extended CSR Register */
    Sd_Ip_CidType           *SdCardCidRegister;                      /*!< Sd CID Register. Uniquely identifies the card. */
    Sd_Ip_CsdType           *SdCardCsdRegister;                      /*!< Sd CSD Register. Information about card operation conditions. */
    Sd_Ip_ScrType           *SdCardScrRegister;                      /*!< Sd SCR Register. Information about card's special features. */
    uint32                  u32BlockCount;                           /*!< Card total block number */
    uint32                  u32BlockSize;                            /*!< Card block size */
    uint32                  u32BusClock_Hz;                          /*!< SD bus clock frequency united in Hz */
    uint32                  u32Version;                              /*!< Card version - SPEC_VERS in the CSD */
    Sd_Ip_ProtocolType      eCardType;                               /*!< Card type */
    Sd_Ip_SdSpeedModeType   eSdSpeedMode;                            /*!< SD bus speed mode selection */
    Sd_Ip_MmcSpeedModeType  eMmcSpeedMode;                           /*!< MMC bus speed mode selection */
} Sd_Emmc_Ip_CardInformationType;

/*!
 * @brief SD and MMC card state
 *
 * Define the card structure including the necessary fields to identify and describe the card.
 */
typedef struct
{
    const Usdhc_Ip_ConfigType *usdhcConfig;     /*!< Host information */
    uint32 SdConfigClock;                       /*!< afrequencyTable */
    uint32 u32McuClock;                         /*!< Clock given by the Mcu to the Usdhc peripheral in Hz*/
    uint32 flags;                               /*!< Flags in Sd_Ip_CardFlagType */
    Sd_Ip_ProtocolType cardType;                /*!< Card type */
    Sd_Ip_MmcBusWidthType  busWidthMode;        /*!< Bus width - Only selectable in MMC mode */
    uint8  driverStrength;                      /*!< Card driver strength - Only apply for eMMC HS200 or HS400 mode */
    const Sd_Emmc_Ip_BootConfigType *mmcBootConfig;   /*!< Boot Configuration for MMC boot */
} Sd_Emmc_Ip_ConfigType;

/*! @} */
#endif /* SD_IP_TYPES_H */
