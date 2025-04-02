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

/**
*   @file    Crc_Ip_Hardware.c
*
*   @version 5.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup
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
#include "Crc_Ip_Hardware.h"
#include "Crc_Ip_Hw_Access.h"
#include "Crc_Ip_Devassert.h"

#if (defined(CRC_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT))
#define USER_MODE_REG_PROT_ENABLED      (STD_ON)
#include "OsIf_Internal.h"
#include "Reg_eSys.h"
#include "RegLockMacros.h"
#endif

#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
#include "Dma_Ip.h"
#endif

#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_HARDWARE_VENDOR_ID_C                      43
#define CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C       4
#define CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C       7
#define CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION_C    0
#define CRC_IP_HARDWARE_SW_MAJOR_VERSION_C               5
#define CRC_IP_HARDWARE_SW_MINOR_VERSION_C               0
#define CRC_IP_HARDWARE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Crc_Ip_Hardware.c and Crc_Ip_Hardware.h are of the same version */
#if (CRC_IP_HARDWARE_VENDOR_ID_C != CRC_IP_HARDWARE_VENDOR_ID)
    #error "Crc_Ip_Hardware.c and Crc_Ip_Hardware.h have different vendor ids"
#endif

/* Check if Crc_Ip_Hardware.c and Crc_Ip_Hardware.h are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION_C != CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Hardware.c and Crc_Ip_Hardware.h are different"
#endif

/* Check if Crc_Ip_Hardware.c and Crc_Ip_Hardware.h are of the same Software version */
#if ((CRC_IP_HARDWARE_SW_MAJOR_VERSION_C != CRC_IP_HARDWARE_SW_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_MINOR_VERSION_C != CRC_IP_HARDWARE_SW_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_PATCH_VERSION_C != CRC_IP_HARDWARE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Hardware.c and Crc_Ip_Hardware.h are different"
#endif

/* Check if the files Crc_Ip_Hardware.c and Crc_Ip_Devassert.h are of the same version */
#if (CRC_IP_HARDWARE_VENDOR_ID_C != CRC_IP_DEVASSERT_VENDOR_ID)
    #error "Crc_Ip_Hardware.c and Crc_Ip_Devassert.h have different vendor ids"
#endif

/* Check if Crc_Ip_Hardware.c file and Crc_Ip_Devassert.h header file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION_C != CRC_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
     )
    #error "AutoSar Version Numbers of Crc_Ip_Hardware.c and Crc_Ip_Devassert.h are different"
#endif

/* Check if Crc_Ip_Hardware.c and Crc_Ip_Devassert.h are of the same Software version */
#if ((CRC_IP_HARDWARE_SW_MAJOR_VERSION_C != CRC_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_MINOR_VERSION_C != CRC_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_PATCH_VERSION_C != CRC_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Hardware.c and Crc_Ip_Devassert.h are different"
#endif

/* Check if the files Crc_Ip_Hardware.c and Crc_Ip_Hw_Access.h are of the same version */
#if (CRC_IP_HARDWARE_VENDOR_ID_C != CRC_IP_HW_ACCESS_VENDOR_ID)
    #error "Crc_Ip_Hardware.c and Crc_Ip_Hw_Access.h have different vendor ids"
#endif

/* Check if Crc_Ip_Hardware.c file and Crc_Ip_Hw_Access.h header file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION_C != CRC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
     )
    #error "AutoSar Version Numbers of Crc_Ip_Hardware.c and Crc_Ip_Hw_Access.h are different"
#endif

/* Check if Crc_Ip_Hardware.c and Crc_Ip_Hw_Access.h are of the same Software version */
#if ((CRC_IP_HARDWARE_SW_MAJOR_VERSION_C != CRC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_MINOR_VERSION_C != CRC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (CRC_IP_HARDWARE_SW_PATCH_VERSION_C != CRC_IP_HW_ACCESS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Hardware.c and Crc_Ip_Hw_Access.h are different"
#endif

#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Crc_Ip_Hardware.c file and Dma_Ip.h header file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcl.c and Dma_Ip.h are different"
#endif
#endif
#endif

#if (defined(CRC_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

/* Check if Crc_Ip_Hardware.c file and OsIf_Internal.h header file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcl.c and OsIf_Internal.h are different"
#endif

/* Check if Crc_Ip_Hardware.c file and Reg_eSys.h header file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcl.c and Reg_eSys.h are different"
#endif

/* Check if Crc_Ip_Hardware.c file and RegLockMacros.h header file are of the same Autosar version */
#if ((CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcl.c and RegLockMacros.h are different"
#endif

#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (STD_ON == CRC_IP_HARDWARE_USED)
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
#define CRC_IP_DMA_CONFIG_DIMENSION     (8U)
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define CRC_START_SEC_CONST_UNSPECIFIED
#include "Crc_MemMap.h"
/* Table of pxCrcBase addresses  for CRC instances. */
static CRC_Type * const s_pxCrcBase[CRC_INSTANCE_COUNT] = IP_CRC_BASE_PTRS;

#define CRC_STOP_SEC_CONST_UNSPECIFIED
#include "Crc_MemMap.h"

#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
#define CRC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"
static Dma_Ip_LogicChannelTransferListType s_atDmaTransferList[CRC_IP_DMA_CONFIG_DIMENSION] =
{
    {DMA_IP_CH_SET_SOURCE_ADDRESS, 0U},
    {DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, DMA_IP_TRANSFER_SIZE_1_BYTE},
    {DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, 1U},
    {DMA_IP_CH_SET_DESTINATION_ADDRESS, 0U},
    {DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE, DMA_IP_TRANSFER_SIZE_1_BYTE},
    {DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_MINORLOOP_SIZE, 0U},
    {DMA_IP_CH_SET_MAJORLOOP_COUNT, 1U}
};
#define CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (defined(CRC_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief This function configure Set User Access Allowed
 */
void Crc_Ip_SetUserAccessAllowed(uint32 const pxCrcBaseAddr);
#endif /* STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT */
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

#if (defined(CRC_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief This function configure Set User Access Allowed
 */
void Crc_Ip_SetUserAccessAllowed(uint32 const pxCrcBaseAddr)
{
    /* CRC SetUserAccessAllowed */
    #if defined(MCAL_CRC_REG_PROT_AVAILABLE)
        #if (STD_ON == MCAL_CRC_REG_PROT_AVAILABLE)
        SET_USER_ACCESS_ALLOWED(pxCrcBaseAddr, CRC_PROT_MEM_U32);
        #endif
    #endif
    /* Avoid compiler warning */
    (void)pxCrcBaseAddr;
}
#endif /* STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT */


#if (defined(CRC_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief This function configure Set User Access Allowed for CRC
 */
static void Crc_Ip_SpecificSetUserAccessAllowed(uint32 const pxCrcBaseAddr)
{
    OsIf_Trusted_Call1param(Crc_Ip_SetUserAccessAllowed, pxCrcBaseAddr);
}
#endif /* STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief         This function configures the CRC module from a user configuration structure.
 */
void Crc_Ip_HwSetConfig(const Crc_Ip_LogicChannelType * pxLogicChannelInitCfg,
                        const Crc_Ip_LogicChannelStateType *pxLogicChannelState
                       )
{
    CRC_Type *const pxCrcBase = s_pxCrcBase[pxLogicChannelInitCfg->HwInst];
    const Crc_Ip_CrcProtocolInfoType *ProtocolInfo = pxLogicChannelState->CrcProtocolInfo;

    CRC_IP_DEV_ASSERT(NULL_PTR != pxLogicChannelState);
    CRC_IP_DEV_ASSERT(pxLogicChannelInitCfg->HwInst < CRC_INSTANCE_COUNT);
    CRC_IP_DEV_ASSERT(pxLogicChannelInitCfg->HwChannel < CRC_IP_CHANNEL_COUNT_U8);

#if (defined(CRC_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT))
    /* Allow user access to register protected */
    static uint32 const s_pxCrcBaseAddr[CRC_INSTANCE_COUNT] = IP_CRC_BASE_ADDRS;

    Crc_Ip_SpecificSetUserAccessAllowed(s_pxCrcBaseAddr[pxLogicChannelInitCfg->HwInst]);
#endif /* #if (STD_ON == CRC_IP_ENABLE_USER_MODE_SUPPORT) */

#if (STD_ON == CRC_IP_HARDWARE_PROTOCOL_IS_AVAILABLE)
    hwAccCrc_SetCrcProtocol(pxCrcBase, pxLogicChannelInitCfg->HwChannel, pxLogicChannelState->Protocol);
#endif /* #if (STD_ON == CRC_IP_HARDWARE_PROTOCOL_IS_AVAILABLE) */

#if (STD_ON == CRC_IP_HARDWARE_WIDTH_IS_AVAILABLE)
    hwAccCrc_SetCrcWidth(pxCrcBase, pxLogicChannelInitCfg->HwChannel, ProtocolInfo->Width);
#endif /* #if (STD_ON == CRC_IP_HARDWARE_WIDTH_IS_AVAILABLE) */

#if (STD_ON == CRC_IP_HARDWARE_POLYNOM_IS_AVAILABLE)
    hwAccCrc_SetPolynom(pxCrcBase, pxLogicChannelInitCfg->HwChannel, (uint32)(ProtocolInfo->PolynomValue));
#endif /* #if (STD_ON == CRC_IP_HARDWARE_POLYNOM_IS_AVAILABLE) */

#if (STD_ON == CRC_IP_HARDWARE_INITIAL_SEED_VALUE_IS_AVAILABLE)
    hwAccCrc_SetInitialSeedValue(pxCrcBase, pxLogicChannelInitCfg->HwChannel, (uint32)ProtocolInfo->InitialSeedValue);
#endif /* #if (STD_ON == CRC_IP_HARDWARE_INITIAL_SEED_VALUE_IS_AVAILABLE) */

#if ((STD_ON == CRC_IP_HARDWARE_WRITE_BIT_SWAP_IS_AVAILABLE) || (STD_ON == CRC_IP_HARDWARE_WRITE_BYTE_SWAP_IS_AVAILABLE))
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    if ((pxLogicChannelInitCfg->DmaLogicChannelEnable == TRUE) && (pxLogicChannelInitCfg->DmaLogicChannelTransferSize != CRC_DMA_TRANSFER_SIZE_1_BYTE))
    {
        hwAccCrc_SetWriteSwap(pxCrcBase, pxLogicChannelInitCfg->HwChannel, ProtocolInfo->WriteBitSwap, !(ProtocolInfo->WriteByteSwap));
    }
    else
    {
#endif
        hwAccCrc_SetWriteSwap(pxCrcBase, pxLogicChannelInitCfg->HwChannel, ProtocolInfo->WriteBitSwap, ProtocolInfo->WriteByteSwap);
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    }
#endif
#endif /* #if ((STD_ON == CRC_IP_HARDWARE_WRITE_BIT_SWAP_IS_AVAILABLE) || (STD_ON == CRC_IP_HARDWARE_WRITE_BYTE_SWAP_IS_AVAILABLE)) */

#if (STD_ON == CRC_IP_HARDWARE_READ_BIT_SWAP_IS_AVAILABLE)
    hwAccCrc_SetReadSwap(pxCrcBase, pxLogicChannelInitCfg->HwChannel, ProtocolInfo->ReadBitSwap, ProtocolInfo->ReadByteSwap);
#endif /* #if (STD_ON == CRC_IP_HARDWARE_READ_BIT_SWAP_IS_AVAILABLE) */

#if (STD_ON == CRC_IP_HARDWARE_INVERSE_BIT_IS_AVAILABLE)
    hwAccCrc_SetInverseResult(pxCrcBase, pxLogicChannelInitCfg->HwChannel, ProtocolInfo->InverseEnable);
#endif /* #if (STD_ON == CRC_IP_HARDWARE_INVERSE_BIT_IS_AVAILABLE) */
}


/**
 * @brief         This function shall start algorithm calculation CRC.
 */
uint64 Crc_Ip_HwCalculate(const Crc_Ip_LogicChannelType * LogicChannelInitCfg,
                          const uint8 *DataPtr,
                          const uint32 Length,
                          const uint64 InitialSeedValue
                         )
{
    uint8 HwInst = LogicChannelInitCfg->HwInst;
    uint8 HwChannel = LogicChannelInitCfg->HwChannel;
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    boolean DmaLogicChannelEnable = LogicChannelInitCfg->DmaLogicChannelEnable;
    uint32 DmaLogicChannelName = LogicChannelInitCfg->DmaLogicChannelName;
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */
    uint64 LocResult = 0U;
    uint32 LocLength = 0U;
    CRC_Type *const pxCrcBase = s_pxCrcBase[HwInst];
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    Dma_Ip_ReturnType DmaReturnStatus;
    /* Set up parameters for Dma_Ip_LogicChannelTransferListType */

    s_atDmaTransferList[0U].Value = (Crc_Ip_uintPtrType)DataPtr;
    s_atDmaTransferList[6U].Value = Length;
    s_atDmaTransferList[3U].Value = hwAccCRC_GetDataInputAddress(pxCrcBase, HwChannel);
    s_atDmaTransferList[1U].Value = LogicChannelInitCfg->DmaLogicChannelTransferSize;
    s_atDmaTransferList[2U].Value = LogicChannelInitCfg->DmaLogicChannelSignedOffset;
    s_atDmaTransferList[4U].Value = LogicChannelInitCfg->DmaLogicChannelTransferSize;
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

    CRC_IP_DEV_ASSERT(HwInst < CRC_INSTANCE_COUNT);
    CRC_IP_DEV_ASSERT(HwChannel < CRC_IP_CHANNEL_COUNT_U8);
    CRC_IP_DEV_ASSERT(NULL_PTR != DataPtr);

#if (STD_ON == CRC_IP_HARDWARE_INITIAL_SEED_VALUE_IS_AVAILABLE)
    /* Write Initial Seed Value */
    hwAccCrc_SetInitialSeedValue(pxCrcBase, HwChannel, (uint32)(InitialSeedValue));
#else
    (void)InitialSeedValue;
#endif

#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    if (TRUE == DmaLogicChannelEnable)
    {
        /* Configure the transfer control descriptor for the DMA channel */
        DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(DmaLogicChannelName, s_atDmaTransferList, CRC_IP_DMA_CONFIG_DIMENSION);
        CRC_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);
        /* Start transfer with Dma Logic Channel Name */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(DmaLogicChannelName, DMA_IP_CH_SET_SOFTWARE_REQUEST);
        CRC_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);
    }
    else
    {
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */
        for (LocLength = 0U; LocLength < Length; LocLength++)
        {
            /* 8-bit writes till end of DataPtr buffer */
            hwAccCrc_SetInputData(pxCrcBase, HwChannel, DataPtr[LocLength]);
        }
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    }
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

    LocResult = Crc_Ip_HwGetLocResult(LogicChannelInitCfg);
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    (void)DmaReturnStatus;
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

    return LocResult;
}

/**
 * @brief         This function gets CRC result after crc is computed.
 */
uint64 Crc_Ip_HwGetLocResult(const Crc_Ip_LogicChannelType * pxLogicChannelInitCfg)
{
    const CRC_Type *const pxCrcBase = s_pxCrcBase[pxLogicChannelInitCfg->HwInst];
    uint64 CrcResult = 0U;
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    Dma_Ip_LogicChannelStatusType DmaChannelStatus;
    Dma_Ip_ReturnType DmaReturnStatus;

    if (TRUE == pxLogicChannelInitCfg->DmaLogicChannelEnable)
    {
        DmaReturnStatus = Dma_Ip_GetLogicChannelStatus(pxLogicChannelInitCfg->DmaLogicChannelName, &DmaChannelStatus);
        CRC_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);

        if (TRUE == DmaChannelStatus.Done)
        {
            CrcResult = hwAccCRC_GetResult(pxCrcBase, pxLogicChannelInitCfg->HwChannel);
        }
        else
        {
            CrcResult = 0U;
        }
    }
    else
    {
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */
        CrcResult = hwAccCRC_GetResult(pxCrcBase, pxLogicChannelInitCfg->HwChannel);
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
    }
    (void)DmaReturnStatus;
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

    return CrcResult;
}

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"
#endif /* #if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE) */

#endif /* #if (STD_ON == CRC_IP_HARDWARE_USED) */

#ifdef __cplusplus
}
#endif

/** @} */
