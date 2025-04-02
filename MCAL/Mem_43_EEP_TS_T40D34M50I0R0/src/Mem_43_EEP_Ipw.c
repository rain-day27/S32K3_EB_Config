/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : IPV_USDHC
* Dependencies : 
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 5.0.0
* Build Version : S32K3_RTD_5_0_0_D2408_ASR_REL_4_7_REV_0000_20241002
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
* @file
*
* @addtogroup MEM_43_EEP_DRIVER Mem_43_EEProm Driver
* @{
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
#include "Mem_43_EEP.h"
#include "Mem_43_EEP_Ipw.h"
#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_IPW_VENDOR_ID_C                      43
#define MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define MEM_43_EEP_IPW_SW_MAJOR_VERSION_C               5
#define MEM_43_EEP_IPW_SW_MINOR_VERSION_C               0
#define MEM_43_EEP_IPW_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Version checks for OsIf.h */
    #if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_EEP_Ipw.c and OsIf.h are different"
    #endif
#endif

/* Version checks for Mem_43_EEP.h */
#if (MEM_43_EEP_IPW_VENDOR_ID_C != MEM_43_EEP_VENDOR_ID)
    #error "Mem_43_EEP_Ipw.c and Mem_43_EEP.h have different vendor ids"
#endif
#if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Ipw.c and Mem_43_EEP.h are different"
#endif
#if ((MEM_43_EEP_IPW_SW_MAJOR_VERSION_C != MEM_43_EEP_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_IPW_SW_MINOR_VERSION_C != MEM_43_EEP_SW_MINOR_VERSION) || \
     (MEM_43_EEP_IPW_SW_PATCH_VERSION_C != MEM_43_EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Ipw.c and Mem_43_EEP.h are different"
#endif

/* Version checks for Mem_43_EEP_Ipw.h */
#if (MEM_43_EEP_IPW_VENDOR_ID_C != MEM_43_EEP_IPW_VENDOR_ID_H)
    #error "Mem_43_EEP_Ipw.c and Mem_43_EEP_Ipw.h have different vendor ids"
#endif
#if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_EEP_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Ipw.c and Mem_43_EEP_Ipw.h are different"
#endif
#if ((MEM_43_EEP_IPW_SW_MAJOR_VERSION_C != MEM_43_EEP_IPW_SW_MAJOR_VERSION_H) || \
     (MEM_43_EEP_IPW_SW_MINOR_VERSION_C != MEM_43_EEP_IPW_SW_MINOR_VERSION_H) || \
     (MEM_43_EEP_IPW_SW_PATCH_VERSION_C != MEM_43_EEP_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Ipw.c and Mem_43_EEP_Ipw.h are different"
#endif

/* Version checks for Det.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MEM_43_EEP_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_EEP_Ipw.c and Det.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#if (MEM_43_EEP_MULTIPARTITION_ENABLED == STD_ON)
#define MEM_43_EEP_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EEP_MemMap.h"
/**
*  @brief Variable that indicate the current configuration set for a memory chip
*/
static const Sd_Emmc_Ip_ConfigType * Mem_43_EEP_apCardConfigPtr;
static Usdhc_Ip_StateType  usdhcState;
static Sd_Emmc_Ip_CardInformationType sCardInformation;

#if (MEM_43_EEP_MULTIPARTITION_ENABLED == STD_ON)
#define MEM_43_EEP_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Mem_43_EEP_MemMap.h"

#if (USDHC_IP_USE_DMA == STD_ON)
#define MEM_43_EEP_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mem_43_EEP_MemMap.h"

VAR_ALIGN(static uint8 u8ReadBuffer[SD_IP_SDMMC_DEFAULT_BLOCK_SIZE], USDHC_IP_ALIGNMENT_SIZE)

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Mem_43_EEP_MemMap.h"
#else
#define MEM_43_EEP_START_SEC_VAR_CLEARED_8
#include "Mem_43_EEP_MemMap.h"

/* It is necessary to align u8ReadBuffer with 4U to facilitate comparing words in the BlankCheck or Compare function.*/
VAR_ALIGN(static uint8 u8ReadBuffer[SD_IP_SDMMC_DEFAULT_BLOCK_SIZE], 4U)

#define MEM_43_EEP_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_EEP_MemMap.h"
#endif /* (USDHC_IP_USE_DMA == STD_ON) */
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
#if (USDHC_IP_USE_DMA == STD_ON)
static Std_ReturnType Mem_43_EEP_Ipw_CheckingAlignmentSource(uint32 SourceAddress);
#endif /* (USDHC_IP_USE_DMA == STD_ON) */
static Std_ReturnType Mem_43_EEP_Ipw_CheckTotalSize
(
    Mem_43_EEP_AddressType TargetAddress,
    Mem_43_EEP_LengthType Length
);
static Mem_43_EEP_CompareCheckType Mem_43_EEP_Ipw_CompareReadBuffer(const uint8 *DestAddress);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#define MEM_43_EEP_START_SEC_CODE
#include "Mem_43_EEP_MemMap.h"

#if (USDHC_IP_USE_DMA == STD_ON)
/**
* @brief         Mem_43_EEP_Ipw_CheckingAlignmentSource
* @details       Check for source buffer data to be aligned or not
*
* @param[in]     SourceAddress Source buffer address
*
* @return        status
* @pre           None.
*/
static Std_ReturnType Mem_43_EEP_Ipw_CheckingAlignmentSource(uint32 SourceAddress)
{
    Std_ReturnType TransferRetVal = E_OK;

    /* DMA1 will have to be aligned data with 4k in system memory */
    if ((USDHC_IP_DMA_MODE_ADMA1 == Mem_43_EEP_apCardConfigPtr->usdhcConfig->dmaMode) && ((SourceAddress % 4096U) != 0U))
    {
        TransferRetVal = E_NOT_OK;
    }
    /* DMA2 will have to be aligned data with 4 bytes in system memory */
    else if ((USDHC_IP_DMA_MODE_ADMA2 == Mem_43_EEP_apCardConfigPtr->usdhcConfig->dmaMode) && ((SourceAddress % 4U) != 0U))
    {
        TransferRetVal = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    return TransferRetVal;
}
#endif /* (USDHC_IP_USE_DMA == STD_ON) */


/**
* @brief         Mem_43_EEP_Ipw_CheckTotalSize
* @details       Check if transfer size exceeds card total block size or not
*
* @param[in]     SourceAddress Target address
* @param[in]     Length        Transfer length
*
* @return        status
* @pre           None.
*/
static Std_ReturnType Mem_43_EEP_Ipw_CheckTotalSize
(
    Mem_43_EEP_AddressType TargetAddress,
    Mem_43_EEP_LengthType Length
)
{
    Std_ReturnType TransferRetVal = (Std_ReturnType)E_OK;
    uint32 TempTotalBlockCounts   = 0U;

    /* Get total block counts of SD/Emmc Cards */
    TempTotalBlockCounts = sCardInformation.u32BlockCount;
    /* Checking if inputs over total size of SD/Emmc */
    if (TempTotalBlockCounts < ((TargetAddress/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) + (Length/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE)))
    {
        TransferRetVal = (Std_ReturnType)E_NOT_OK;
    }

    return TransferRetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_CompareReadBuffer
* @details       Compare data buffer with u8ReadBuffer (a single block).
*
* @param[in]     DestAddress   Pointer to source buffer data will be comapre with u8ReadBuffer block.
*
* @return        status
* @pre           The driver needs to be initialized.
*/
static Mem_43_EEP_CompareCheckType Mem_43_EEP_Ipw_CompareReadBuffer
(
    const uint8 *DestAddress
)
{
    Mem_43_EEP_CompareCheckType eCompareBlockRetVal  = MEM_43_EEP_COMPARE_E_OK;
    uint32 TempDest                = (uint32)&DestAddress[0u];
    uint32 TempSrc                 = (uint32)u8ReadBuffer;
    uint32 TempLength              = SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
    uint32 CombinedAddress;

    while (0UL < TempLength)
    {
        /* Checking if all alignments and length >= 4U */
        CombinedAddress = TempSrc | TempDest;
        if (((CombinedAddress & 0x3U) == 0UL) && (TempLength >= 4UL))
        {
            if (*((uint32 *)TempSrc) != *((uint32 *)TempDest))
            {
                eCompareBlockRetVal = MEM_43_EEP_COMPARE_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Clearing that number in buffer which already compared to make sure that next read which buffer will be empty */
                *(uint32 *)TempSrc = 0UL;
                TempSrc = TempSrc + 4UL;
                TempDest = TempDest + 4UL;
                TempLength = TempLength - 4UL;
            }
        }
        /* Checking if data is unaligned and length < 4U */
        else
        {
            if (*((uint8 *)TempSrc) != *((uint8 *)TempDest))
            {
                eCompareBlockRetVal = MEM_43_EEP_COMPARE_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Clearing that number in buffer which already compared to make sure that next read which buffer will be empty */
                *(uint8 *)TempSrc = 0U;
                TempSrc = TempSrc + 1UL;
                TempDest = TempDest + 1UL;
                TempLength = TempLength - 1UL;
            }
        }

        if (MEM_43_EEP_COMPARE_E_OK != eCompareBlockRetVal)
        {
            /* Exit both this loop */
            break;
        }
    }

    return eCompareBlockRetVal;
}


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief         Mem_43_EEP_Ipw_Init
* @details       Initialize MEM_43_EEP module
*
* @param[in]     Config SD init configuration
*
* @return        status
* @pre           N/A
*/
Std_ReturnType Mem_43_EEP_Ipw_Init
(
    Mem_43_EEP_ConfigType const * Config,
    uint32 InstanceIndex
)
{
    const Sd_Emmc_Ip_ConfigType * SdIpConfig = Config->pxSdEmmcIpConfig;
    Std_ReturnType        RetVal     = E_OK;
    Sd_Emmc_Ip_StatusType SdRetVal           = SD_IP_STATUS_SUCCESS;
    Usdhc_Ip_StatusType   UsdhcRetVal        = STATUS_USDHC_IP_SUCCESS;

    /* Save configuration for the card that is Initialized */
    Mem_43_EEP_apCardConfigPtr = SdIpConfig;

    /* Init order the Usdhc controler */
    UsdhcRetVal = uSDHC_Ip_Init(&usdhcState, Mem_43_EEP_apCardConfigPtr->usdhcConfig, 0);
    if (STATUS_USDHC_IP_SUCCESS == UsdhcRetVal)
    {
        SdRetVal = Sd_Emmc_Ip_Init(Mem_43_EEP_apCardConfigPtr);
    }
    /* Init Sd protocol layer */
    if ((STATUS_USDHC_IP_SUCCESS != UsdhcRetVal) || (SD_IP_STATUS_SUCCESS != SdRetVal))
    {
        RetVal = E_NOT_OK;
        if (((Usdhc_Ip_StatusType)STATUS_USDHC_IP_TIMEOUT == UsdhcRetVal) || ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal))
        {
            /* Report timeout*/
            (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_INIT_ID, MEM_43_EEP_E_TIMEOUT);
        }
    }
    else
    {
        /* Get information from card */
        Sd_Emmc_Ip_GetCardInformation(&sCardInformation);
    }

    return RetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_DeInit
* @details       DeInitialize MEM_43_EEP module
*
* @param[in]     Config SD init configuration
*
* @return        status
* @pre           N/A
*/
void Mem_43_EEP_Ipw_DeInit
(
    uint32 InstanceIndex
)
{
    /* Re-initialize the Usdhc global variable */
    (void)uSDHC_Ip_DeInit(InstanceIndex);

}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check if the parameters are ok and the HLD can start the blank check job.
 *
 * @param[in]   TargetAddress
 * @param[in]   Length
 *
 * @return      Ok / Not ok to start the blanck check job.
 * @retval      E_OK
 * @retval      E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Mem_43_EEP_Ipw_CheckBlankCheckParams
(
    Mem_43_EEP_AddressType TargetAddress,
    Mem_43_EEP_LengthType Length,
    uint32 InstanceIndex
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    /* Check the target address */
    if ((TargetAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U)
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_BLANKCHECK_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* Check the validity of length */
    if ((0U == Length) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_BLANKCHECK_ID, MEM_43_EEP_E_PARAM_LENGTH);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_OFF)
    (void)InstanceIndex;    /* workaround unused parameter */
#endif

    return RetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_BlankCheck
* @details       Compare data for the given transfer length with data after erase of device (0U or 0xFFU)
*
* @param[in]     EepromAddrIt   Address to start comparing
* @param[in]     BlankLength   Transfer length to compare
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Mem_43_EEP_BlankCheckType Mem_43_EEP_Ipw_BlankCheck
(
    Mem_43_EEP_AddressType EepromAddrIt,
    Mem_43_EEP_LengthType BlankLength,
    uint32 InstanceIndex
)
{
    Mem_43_EEP_BlankCheckType BlankCheckRetVal  = MEM_43_EEP_BLANKCHECK_E_OK;
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;
    uint32 BlockCount              = (uint32)((BlankLength / SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock              = (uint32)((EepromAddrIt   / SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 EndBlock                = 0U;
    uint32 TempSrc                 = (uint32)u8ReadBuffer;
    uint32 TempLength              = SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;
    uint32 u32DataStatusAfterErase = 0U;

    if (sCardInformation.eCardType == SD_IP_MEMORY_CARD_SD)
    {
        if (0U != (sCardInformation.SdCardScrRegister->flags & (uint16)SD_EMMC_IP_SD_SCR_DATA_STATUS_AFTER_ERASE))
        {
            u32DataStatusAfterErase = (uint32)0xFFFFFFFFU;
        }
    }
    else     /* eMMC card*/
    {
        if (0U != sCardInformation.EmmcCsrRegister->eraseMemoryContent)
        {
            u32DataStatusAfterErase = (uint32)0xFFFFFFFFU;
        }
    }

    EndBlock = StartBlock + BlockCount;

    while (StartBlock < EndBlock)
    {
        SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_ReadBlocks(Mem_43_EEP_apCardConfigPtr, u8ReadBuffer, StartBlock, 1U, FALSE);
        /* if work is not successful */
        if (SD_IP_STATUS_SUCCESS != SdRetVal)
        {
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
            {
                /* Report timeout*/
                (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_MAINFUNCTION_ID, MEM_43_EEP_E_TIMEOUT);
            }
            BlankCheckRetVal = MEM_43_EEP_BLANKCHECK_E_NOT_OK;
            break;
        }
        else
        {
            while (0UL < TempLength)
            {
                /* TempSrc (u8ReadBuffer)  and u32DataStatusAfterErase are always alignments with 4byte */
                if (*((uint32 *)TempSrc) != u32DataStatusAfterErase)
                {
                    BlankCheckRetVal = MEM_43_EEP_BLANKCHECK_E_INCONSISTENT;
                    /* Exit both this loop and the outer loop */
                    StartBlock = EndBlock - 1U;
                    break;
                }
                else
                {
                    /* Clearing that number in buffer which already compared to make sure that next read which buffer will be empty */
                    *(uint32 *)TempSrc = 0UL;
                    TempSrc = TempSrc + 4UL;
                    TempLength = TempLength - 4UL;
                }
            }
            /* Increasing block */
            StartBlock++;
        }
    }

    return BlankCheckRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check if the parameters are ok and the HLD can start the erase job.
 *
 * @param[in]   TargetAddress
 * @param[in]   Length
 *
 * @return      Ok / Not ok to start the erase job.
 * @retval      E_OK
 * @retval      E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Mem_43_EEP_Ipw_CheckEraseParams
(
    Mem_43_EEP_AddressType TargetAddress,
    Mem_43_EEP_LengthType Length,
    uint32 InstanceIndex
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    /* Check the target address */
    if ((TargetAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U)
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_ERASE_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* Check the validity of length */
    if ((0U == Length) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_ERASE_ID, MEM_43_EEP_E_PARAM_LENGTH);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_OFF)
    (void)InstanceIndex;    /* workaround unused parameter */
#endif

    return RetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_Erase
* @details       Erase data for the given transfer length.
*
* @param[in]     Mem_43_EEPromAddrIt Address to start erase
* @param[in]     TransfLength Transfer length to erase
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Mem_43_EEP_ReturnType Mem_43_EEP_Ipw_Erase
(
    Mem_43_EEP_AddressType Mem_43_EEPromAddrIt,
    Mem_43_EEP_LengthType TransfLength,
    uint32 InstanceIndex
)
{
    Sd_Emmc_Ip_StatusType SdRetVal;
    Mem_43_EEP_ReturnType EraseRetVal;
    uint32 BlockCount              = (uint32)((TransfLength/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock              = (uint32)((Mem_43_EEPromAddrIt/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);

    #if (MEM_43_EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_EraseBlocks(Mem_43_EEP_apCardConfigPtr, StartBlock, BlockCount, (boolean)FALSE);
    #else
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_EraseBlocks(Mem_43_EEP_apCardConfigPtr, StartBlock, BlockCount, (boolean)TRUE);
    #endif

    if (SD_IP_STATUS_SUCCESS == SdRetVal)
    {
        /* Working is done */
        EraseRetVal = MEM_43_EEP_E_OK;
    }
    else if (SD_IP_STATUS_PENDING == SdRetVal)
    {
        /* Working is pending */
        EraseRetVal = MEM_43_EEP_E_PENDING;
    }
    else
    {
        /* Working is not successful */
        EraseRetVal = MEM_43_EEP_E_FAILED;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_MAINFUNCTION_ID, MEM_43_EEP_E_TIMEOUT);
        }
    }

    return EraseRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Check parameters for the Read job.
 * @param[in] Length
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Mem_43_EEP_Ipw_CheckReadParams
(
    Mem_43_EEP_AddressType SourceAddress,
    Mem_43_EEP_DataType const * TargetAddressPtr,
    Mem_43_EEP_LengthType Length,
    uint32 InstanceIndex
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Std_ReturnType CheckTotalSize;

    if (((SourceAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    CheckTotalSize = Mem_43_EEP_Ipw_CheckTotalSize(SourceAddress, Length);
    if ((0U == Length) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U) || ((Std_ReturnType)E_OK != CheckTotalSize))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_PARAM_LENGTH);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if ((NULL_PTR == TargetAddressPtr)
    #if (USDHC_IP_USE_DMA == STD_ON)
        || ((Std_ReturnType)E_OK != Mem_43_EEP_Ipw_CheckingAlignmentSource((uint32)TargetAddressPtr))
    #endif /* (USDHC_IP_USE_DMA == STD_ON) */
       )
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_READ_ID, MEM_43_EEP_E_PARAM_POINTER);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_OFF)
    (void)InstanceIndex;    /* workaround unused parameter */
#endif

    return RetVal;
}

Mem_43_EEP_ReturnType Mem_43_EEP_Ipw_Read
(
    Mem_43_EEP_AddressType Mem_43_EEPromAddrIt,
    Mem_43_EEP_DataType *JobDataDestPtr,
    Mem_43_EEP_LengthType TransfLength,
    uint32 InstanceIndex
)
{
    Mem_43_EEP_ReturnType ReadRetVal;
    uint32 BlockCount              = (uint32)((TransfLength/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock              = (uint32)((Mem_43_EEPromAddrIt/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;

    #if (MEM_43_EEP_ASYNC_READ_OPERATIONS_ENABLED == STD_OFF)
    /* Read blocks with sync mode */
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_ReadBlocks(Mem_43_EEP_apCardConfigPtr, (uint8 *)JobDataDestPtr, StartBlock, BlockCount, FALSE);
    #else
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_ReadBlocks(Mem_43_EEP_apCardConfigPtr, (uint8 *)JobDataDestPtr, StartBlock, BlockCount, TRUE);
    #endif /* #if (MEM_43_EEP_ASYNC_READ_OPERATIONS_ENABLED == STD_OFF) */

    if (SD_IP_STATUS_SUCCESS == SdRetVal)
    {
        /* Working is done */
        ReadRetVal = MEM_43_EEP_E_OK;
    }
    else if (SD_IP_STATUS_PENDING == SdRetVal)
    {
        /* Working is pending */
        ReadRetVal = MEM_43_EEP_E_PENDING;
    }
    else
    {
        /* Working is not successful */
        ReadRetVal = MEM_43_EEP_E_FAILED;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_MAINFUNCTION_ID, MEM_43_EEP_E_TIMEOUT);
        }
    }

    return ReadRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check the parameters given for a Write job.
 *
 * @param[in]   TargetAddress
 * @param[in]   pSourceAddressPtr
 * @param[in]   Length
 *
 * @return Ok / not ok to start the write job with those parameters.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Mem_43_EEP_Ipw_CheckWriteParams
(
    Mem_43_EEP_AddressType TargetAddress,
    const Mem_43_EEP_DataType * pSourceAddressPtr,
    Mem_43_EEP_LengthType Length,
    uint32 InstanceIndex
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Std_ReturnType CheckTotalSize;

    if ((TargetAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U)
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    CheckTotalSize = Mem_43_EEP_Ipw_CheckTotalSize(TargetAddress, Length);
    if ((0U == Length) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U) || ((Std_ReturnType)E_OK != CheckTotalSize))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_PARAM_LENGTH);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if ((NULL_PTR == pSourceAddressPtr)
    #if (USDHC_IP_USE_DMA == STD_ON)
        || ((Std_ReturnType)E_OK != Mem_43_EEP_Ipw_CheckingAlignmentSource((uint32)pSourceAddressPtr))
    #endif /* (USDHC_IP_USE_DMA == STD_ON) */
       )
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_WRITE_ID, MEM_43_EEP_E_PARAM_POINTER);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_OFF)
    (void)InstanceIndex;    /* workaround unused parameter */
#endif

    return RetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_Write
* @details       Write data for the given transfer length in sync mode
*
* @param[in]     JobSrcAddrPtr  Pointer to source buffer
* @param[in]     Mem_43_EEPromAddrIt   Address to start writing
* @param[in]     TransfLength   Transfer length to write
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Mem_43_EEP_ReturnType Mem_43_EEP_Ipw_Write
(
    Mem_43_EEP_AddressType Mem_43_EEPromAddrIt,
    const Mem_43_EEP_DataType *JobSrcAddrPtr,
    Mem_43_EEP_LengthType TransfLength,
    uint32 InstanceIndex
)
{
    Sd_Emmc_Ip_StatusType SdRetVal;
    Mem_43_EEP_ReturnType WriteRetVal;
    uint32 BlockCount            = (uint32)((TransfLength/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock            = (uint32)((Mem_43_EEPromAddrIt/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);

    #if (MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_WriteBlocks(Mem_43_EEP_apCardConfigPtr, (const uint8 *)JobSrcAddrPtr, StartBlock, BlockCount, (boolean)FALSE);
    #else
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_WriteBlocks(Mem_43_EEP_apCardConfigPtr, (const uint8 *)JobSrcAddrPtr, StartBlock, BlockCount, (boolean)TRUE);
    #endif /* #if (MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF) */

    if (SD_IP_STATUS_SUCCESS == SdRetVal)
    {
        /* Working is done */
        WriteRetVal = MEM_43_EEP_E_OK;
    }
    else if (SD_IP_STATUS_PENDING == SdRetVal)
    {
        /* Working is pending */
        WriteRetVal = MEM_43_EEP_E_PENDING;
    }
    else
    {
        /* Working is not successful */
        WriteRetVal = MEM_43_EEP_E_FAILED;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_MAINFUNCTION_ID, MEM_43_EEP_E_TIMEOUT);
        }
    }

    return WriteRetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_Cancel
* @details       Cancel current job
*
* @param[in]     void
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Std_ReturnType Mem_43_EEP_Ipw_Cancel(uint32 InstanceIndex)
{
    Std_ReturnType TransferRetVal  = E_NOT_OK;
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;
    /* Abort the on-going operation */
    SdRetVal = Sd_Emmc_Ip_Abort(Mem_43_EEP_apCardConfigPtr);
    if (SD_IP_STATUS_SUCCESS == SdRetVal)
    {
        TransferRetVal = E_OK;
    }
    else
    {
        /* Abort failed */
        TransferRetVal = E_NOT_OK;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_SUSPEND_ID, MEM_43_EEP_E_TIMEOUT);
        }
    }

    return TransferRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief  Check the params given for a Compare job.
 *
 * @param[in] u32EepromAddrNeedsCompared
 * @param[in] TargetAddressPtr
 * @param[in] Length
 * @param[in] InstanceIndex
 *
 * @return Ok / not ok to proceed to the compare operation with the given params.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Mem_43_EEP_Ipw_CheckCompareParams
(
    Mem_43_EEP_AddressType u32EepromAddrNeedsCompared,
    const uint8 * TargetAddressPtr,
    Mem_43_EEP_LengthType Length,
    uint32 InstanceIndex
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Std_ReturnType CheckTotalSize;

    if (((u32EepromAddrNeedsCompared % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    CheckTotalSize = Mem_43_EEP_Ipw_CheckTotalSize(u32EepromAddrNeedsCompared, Length);
    if ((0U == Length) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U) || ((Std_ReturnType)E_OK != CheckTotalSize))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_PARAM_LENGTH);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if (NULL_PTR == TargetAddressPtr)
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_PARAM_POINTER);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (USDHC_IP_USE_DMA == STD_ON)
    if ((Std_ReturnType)E_OK != Mem_43_EEP_Ipw_CheckingAlignmentSource((uint32)TargetAddressPtr))
    {
    #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_HWSPECIFICSERVICE_ID, MEM_43_EEP_E_PARAM_ADDRESS);
    #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif /* (USDHC_IP_USE_DMA == STD_ON) */

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_OFF)
    (void)InstanceIndex;    /* workaround unused parameter */
#endif

    return RetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_CompareSync
* @details       Compare data for the given transfer length in sync mode
*
* @param[in]     u32EepromAddrNeedsCompared  Address to start comparing
* @param[in]     DestAddress   Pointer to source buffer
* @param[in]     TransfLength      Transfer length to compare
* @param[in]     InstanceIndex     Instance Index
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Mem_43_EEP_CompareCheckType Mem_43_EEP_Ipw_CompareSync
(
    Mem_43_EEP_AddressType u32EepromAddrNeedsCompared,
    const uint8 *DestAddress,
    Mem_43_EEP_LengthType TransfLength,
    uint32 InstanceIndex
)
{
    Mem_43_EEP_CompareCheckType eCompareBlockRetVal  = MEM_43_EEP_COMPARE_E_OK;
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;
    uint32 BlockCount              = (uint32)((TransfLength / SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock              = (uint32)((u32EepromAddrNeedsCompared   / SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 EndBlock                = 0U;

    EndBlock = StartBlock + BlockCount;

    while (StartBlock < EndBlock)
    {
        SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_ReadBlocks(Mem_43_EEP_apCardConfigPtr, u8ReadBuffer, StartBlock, 1U, FALSE);
        /* if work is not successful */
        if (SD_IP_STATUS_SUCCESS != SdRetVal)
        {
        #if (MEM_43_EEP_DEV_ERROR_DETECT == STD_ON)
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
            {
                /* Report timeout*/
                (void)Det_ReportError((uint16)MEM_43_EEP_MODULE_ID, (uint8)InstanceIndex, MEM_43_EEP_MAINFUNCTION_ID, MEM_43_EEP_E_TIMEOUT);
            }
        #endif
            eCompareBlockRetVal = MEM_43_EEP_COMPARE_E_FAILED;
        }
        else
        {
            eCompareBlockRetVal = Mem_43_EEP_Ipw_CompareReadBuffer(DestAddress);
        }

        if (MEM_43_EEP_COMPARE_E_OK != eCompareBlockRetVal)
        {
            break;
        }

        /* Increasing block */
        StartBlock++;
    }

#if (MEM_43_EEP_DEV_ERROR_DETECT == STD_OFF)
    (void)InstanceIndex;    /* workaround unused parameter */
#endif

    return eCompareBlockRetVal;
}

/**
* @brief         Mem_43_EEP_Ipw_SwitchPartition
* @details       This function switch access to desired partition
*
* @param[in]     Sd_Ip_PartitionAccess Partition want to switch
*
* @return        Std_ReturnType
* @pre           The SD driver needs to be initialized.
*/
Std_ReturnType Mem_43_EEP_Ipw_SwitchPartitionAccess
(
    Sd_Ip_MmcPartitionAccessType Sd_Ip_PartitionAccess
)
{
    Std_ReturnType        RetVal = E_OK;
    Sd_Emmc_Ip_StatusType eSdRetVal       = SD_IP_STATUS_SUCCESS;

    /* Switch access to desired partition */
    eSdRetVal = Sd_Emmc_Ip_MmcSwitchPartitionAccess(Mem_43_EEP_apCardConfigPtr, Sd_Ip_PartitionAccess);

    if (SD_IP_STATUS_SUCCESS != eSdRetVal)
    {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

#if (STD_ON == USDHC_IP_MMC_BOOT_ENABLED)
Std_ReturnType Mem_43_EEP_IpwFastBoot
(
    const Mem_43_EEP_ConfigType * ConfigPtr,
    uint32 BootBlockCount, uint32* BootBuffer
)
{
    const Sd_Emmc_Ip_ConfigType * SdIpConfig = ConfigPtr->pxSdEmmcIpConfig;
    Usdhc_Ip_StatusType   UsdhcRetVal        = STATUS_USDHC_IP_SUCCESS;
    Std_ReturnType        RetVal             = E_NOT_OK;

    /* Init order the Usdhc controler */
    UsdhcRetVal = uSDHC_Ip_Init(&usdhcState, SdIpConfig->usdhcConfig, 0);

    if (STATUS_USDHC_IP_SUCCESS == UsdhcRetVal)
    {
        UsdhcRetVal = uSDHC_Ip_ProcessFastBoot(SdIpConfig->usdhcConfig->instance, SdIpConfig->usdhcConfig->bootConfig, BootBlockCount, BootBuffer);
        if (STATUS_USDHC_IP_SUCCESS == UsdhcRetVal)
        {
            RetVal = E_OK;
        }
    }

    return RetVal;
}
#endif

#define MEM_43_EEP_STOP_SEC_CODE
#include "Mem_43_EEP_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/

