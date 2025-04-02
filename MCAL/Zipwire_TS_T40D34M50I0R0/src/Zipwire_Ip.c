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

/**
*   @file Zipwire_Ip.c
*
*   @addtogroup ZIPWIRE_IP_DRIVER
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
#include "Zipwire_Ip.h"
#include "Zipwire_Ip_Sipi_Hw_Access.h"
#include "Zipwire_Ip_Sipi_Irq.h"
#include "Zipwire_Ip_Lfast_Hw_Access.h"
#include "Zipwire_Ip_Lfast.h"
#include "Zipwire_Ip_DevAssert.h"
#include "Zipwire_Ip_Private.h"

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#include "Dma_Ip.h"
#endif

#if (defined (ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT))
#define USER_MODE_REG_PROT_ENABLED (STD_ON)
#include "Zipwire_Ip_TrustedFunctions.h"
#include "OsIf_Internal.h"
#include "Reg_eSys.h"
#include "RegLockMacros.h"
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define ZIPWIRE_IP_VENDOR_ID_C                   43
#define ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C    4
#define ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C    7
#define ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C 0
#define ZIPWIRE_IP_SW_MAJOR_VERSION_C            5
#define ZIPWIRE_IP_SW_MINOR_VERSION_C            0
#define ZIPWIRE_IP_SW_PATCH_VERSION_C            0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Zipwire_Ip.c and Zipwire_Ip_Lfast.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_VENDOR_ID)
#error "Zipwire_Ip.c and Zipwire_Ip_Lfast.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Lfast.h are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Lfast.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast.h are different"
#endif

/* Check if the files Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_DEVASSERT_VENDOR_ID)
#error "Zipwire_Ip.c and Zipwire_Ip_DevAssert.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c file and Zipwire_Ip_DevAssert.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_DevAssert.h are different"
#endif

/* Check if the files Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_LFAST_HW_ACCESS_VENDOR_ID)
#error "Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c file and Zipwire_Ip_Lfast_Hw_Access.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_LFAST_HW_ACCESS_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Lfast_Hw_Access.h are different"
#endif

/* Check if the files Zipwire_Ip.c and Zipwire_Ip_Private.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_PRIVATE_VENDOR_ID)
#error "Zipwire_Ip.c and Zipwire_Ip_Private.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c file and Zipwire_Ip_Private.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Private.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Private.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_PRIVATE_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_PRIVATE_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_PRIVATE_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Private.h are different"
#endif

/* Check if the files Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are of the same version */
#if (ZIPWIRE_IP_VENDOR_ID_C != ZIPWIRE_IP_SIPI_HW_ACCESS_VENDOR_ID)
#error "Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h have different vendor ids"
#endif

/* Check if Zipwire_Ip.c file and Zipwire_Ip_Sipi_Hw_Access.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_REVISION_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are different"
#endif

/* Check if Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are of the same Software version */
#if ((ZIPWIRE_IP_SW_MAJOR_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MAJOR_VERSION) || \
    (ZIPWIRE_IP_SW_MINOR_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_MINOR_VERSION) || \
    (ZIPWIRE_IP_SW_PATCH_VERSION_C != ZIPWIRE_IP_SIPI_HW_ACCESS_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Zipwire_Ip.c and Zipwire_Ip_Sipi_Hw_Access.h are different"
#endif

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Zipwire_Ip.c file and Dma_Ip.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip.c and Dma_Ip.h are different"
#endif
#endif
#endif

#if (defined (ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

/* Check if Zipwire_Ip_Hardware.c file and OsIf_Internal.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip.c and OsIf_Internal.h are different"
#endif

/* Check if Zipwire_Ip_Hardware.c file and Reg_eSys.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip.c and Reg_eSys.h are different"
#endif

/* Check if Zipwire_Ip_Hardware.c file and RegLockMacros.h header file are of the same Autosar version */
#if ((ZIPWIRE_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
    (ZIPWIRE_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Zipwire_Ip.c and RegLockMacros.h are different"
#endif

#endif /* ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* if (defined (ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT)) */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#define ZIPWIRE_IP_DMA_GLOBAL_CONFIG_DIMENSION  (2U)
#define ZIPWIRE_IP_DMA_DATA_CONFIG_DIMENSION    (15U)
#define ZIPWIRE_IP_DMA_ADDRESS_CONFIG_DIMENSION (11U)
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

#if (STD_ON == ZIPWIRE_IP_MULTIPARTITION_SUPPORT_ENABLED)
    #define Zipwire_Ip_GetUserId()            OsIf_GetUserId()
#endif /* #if (ZIPWIRE_MULTIPARTITION_SUPPORT_ENABLED == STD_ON) */
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ZIPWIRE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"
static const Zipwire_Ip_LogicChannelConfigType * const * s_ppaxLogicChannelInit;
static const Zipwire_Ip_LogicInstanceConfigType * const * s_ppaxLogicInstanceInit;
#define ZIPWIRE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"

#define ZIPWIRE_START_SEC_CONST_UNSPECIFIED
#include "Zipwire_MemMap.h"


static SIPI_Type * s_ZipwireSipiInstances[ZIPWIRE_IP_INSTANCE_COUNT_U8] = IP_SIPI_BASE_PTRS;
static LFAST_Type * s_ZipwireLfastInstances[ZIPWIRE_IP_INSTANCE_COUNT_U8] = IP_LFAST_BASE_PTRS;
static Zipwire_Ip_SIPI_Channel_Type * s_ZipwireSipiChannels[ZIPWIRE_IP_INSTANCE_COUNT_U8][ZIPWIRE_IP_CHANNEL_COUNT_U8] = IP_SIPI_CHANNEL_BASE_PTRS;

#define ZIPWIRE_STOP_SEC_CONST_UNSPECIFIED
#include "Zipwire_MemMap.h"

#define ZIPWIRE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"

static Zipwire_Ip_InstanceState s_axLogicInstanceState[ZIPWIRE_IP_INSTANCE_COUNT_U8];
static Zipwire_Ip_ChannelState s_axLogicChannelState[ZIPWIRE_IP_INSTANCE_COUNT_U8][ZIPWIRE_IP_CHANNEL_COUNT_U8];

#define ZIPWIRE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Zipwire_MemMap.h"

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
#define ZIPWIRE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Zipwire_MemMap.h"

static Dma_Ip_LogicChannelGlobalListType s_atDmaGlobalList[ZIPWIRE_IP_DMA_GLOBAL_CONFIG_DIMENSION] =
{
    {DMA_IP_CH_SET_EN_BUFFERED_WRITES, TRUE},
    {DMA_IP_CH_SET_EN_HARDWARE_REQ, TRUE}
};

static Dma_Ip_LogicChannelTransferListType s_atAddressDmaTransferList[ZIPWIRE_IP_DMA_ADDRESS_CONFIG_DIMENSION] =
{
    {DMA_IP_CH_SET_SOURCE_ADDRESS, 0U},
    {DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_DESTINATION_ADDRESS, 0U},
    {DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_MINORLOOP_SIZE, 4U},
    {DMA_IP_CH_SET_MAJORLOOP_COUNT, 1U},
    {DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, FALSE},
    {DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST, TRUE},
    {DMA_IP_CH_SET_CONTROL_BANDWIDTH, 0U}
};

static Dma_Ip_LogicChannelTransferListType s_atDataDmaTransferList[ZIPWIRE_IP_DMA_DATA_CONFIG_DIMENSION] =
{
    {DMA_IP_CH_SET_SOURCE_ADDRESS, 0U},
    {DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_DESTINATION_ADDRESS, 0U},
    {DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET, 0U},
    {DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE, 0U},
    {DMA_IP_CH_SET_MINORLOOP_SIZE, 4U},
    {DMA_IP_CH_SET_MINORLOOP_EN_LINK, TRUE},
    {DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH, 0U},
    {DMA_IP_CH_SET_MAJORLOOP_EN_LINK, TRUE},
    {DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH, 0U},
    {DMA_IP_CH_SET_MAJORLOOP_COUNT, 1U},
    {DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, FALSE},
    {DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST, TRUE},
    {DMA_IP_CH_SET_CONTROL_BANDWIDTH, 0U}
};

#define ZIPWIRE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Zipwire_MemMap.h"
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)

Dma_Ip_LogicChannelStatusType Zipwire_Ip_xDmaChStatusData;
Dma_Ip_LogicChannelStatusType Zipwire_Ip_xDmaChStatusAddress;

#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

volatile Zipwire_StatusType ZipwireIpInitState[ZIPWIRE_IP_INSTANCE_COUNT_U8];
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchReadCommand(Zipwire_Ip_ChannelState * ChannelState,
                                                          Zipwire_Ip_TransferDescriptor * DataArray,
                                                          uint32 DataArrayLength,
                                                          boolean IsBlocking);

static Zipwire_Ip_StatusType Zipwire_Ip_LaunchWriteCommand(Zipwire_Ip_ChannelState * ChannelState,
                                                           Zipwire_Ip_TransferDescriptor * DataArray,
                                                           uint32 DataArrayLength,
                                                           boolean IsBlocking);

static void Zipwire_Ip_WriteData(uint8 HwInstance,
                                 uint8 HwChannel,
                                 const Zipwire_Ip_TransferDescriptor * DataArray);

static void Zipwire_Ip_StopTransfer(uint8 HwInstance,
                                    uint8 HwChannel);

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchReadCommandWithDma(Zipwire_Ip_ChannelState * ChannelState,
                                                                 const uint32 * DataArray,
                                                                 const uint32 * AddressArray,
                                                                 uint32 DataArrayLength,
                                                                 boolean IsBlocking);

static Zipwire_Ip_StatusType Zipwire_Ip_LaunchWriteCommandWithDma(Zipwire_Ip_ChannelState * ChannelState,
                                                                  const uint32 * DataArray,
                                                                  const uint32 * AddressArray,
                                                                  uint32 DataArrayLength,
                                                                  boolean IsBlocking);

#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define ZIPWIRE_START_SEC_CODE
#include "Zipwire_MemMap.h"

#if (STD_ON == ZIPWIRE_IP_LFAST_REGISTER_PROTECTION)
#if (defined (ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief This function configure Set User Access Allowed
 */
void Zipwire_Ip_SetUserAccessAllowed(uint32 const pxZipwireBaseAddr)
{
    /* ZIPWIRE SetUserAccessAllowed */
#if defined (MCAL_ZIPWIRE_REG_PROT_AVAILABLE)
#if (STD_ON == MCAL_ZIPWIRE_REG_PROT_AVAILABLE)
    SET_USER_ACCESS_ALLOWED(pxZipwireBaseAddr, ZIPWIRE_PROT_MEM_U32);
#endif
#endif
#if defined (MCAL_DCM_REG_PROT_AVAILABLE)
#if (STD_ON == MCAL_DCM_REG_PROT_AVAILABLE)
    SET_USER_ACCESS_ALLOWED(IP_DCM_GPR_BASE, DCM_PROT_MEM_U32);
#endif
#endif
    /* Avoid compiler warning */
    (void)pxZipwireBaseAddr;
}

#endif /* STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT */


#if (defined (ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief This function configure Set User Access Allowed for ZIPWIRE
 */
static void Zipwire_Ip_SpecificSetUserAccessAllowed(uint32 const pxZipwireBaseAddr)
{
    OsIf_Trusted_Call1param(Zipwire_Ip_SetUserAccessAllowed, pxZipwireBaseAddr);
}

#endif /* STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT */
#endif /* #if (STD_ON == ZIPWIRE_IP_LFAST_REGISTER_PROTECTION) */

/**
 * @brief         Initializes the Zipwire Instances based on the user configuration.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_InitInstance(const Zipwire_Ip_LogicInstanceConfigType *pxZipwireInstanceConfig)
{
    LFAST_Type * pxLfastBase = s_ZipwireLfastInstances[pxZipwireInstanceConfig->HwInstance];
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[pxZipwireInstanceConfig->HwInstance];
    Zipwire_Ip_InstanceState * InstanceState = &s_axLogicInstanceState[pxZipwireInstanceConfig->HwInstance];
    Zipwire_Ip_StatusType ZipwireIpStatus;

    ZIPWIRE_IP_DEV_ASSERT(pxZipwireInstanceConfig->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireInstanceConfig != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireInstanceConfig->LfastConfig != NULL_PTR);

    /* Perform a soft reset of the SIPI state machine */
    ZipwireIpStatus = hwAccZipwireSipi_SoftReset(pxSipiBase);
    if (ZipwireIpStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        Zipwire_Ip_InitSipiInstance(pxZipwireInstanceConfig);

        /* Configure user callbacks */
        InstanceState->Callback = pxZipwireInstanceConfig->Callback;
        InstanceState->CallbackParam = pxZipwireInstanceConfig->CallbackParam;
#if (STD_ON == ZIPWIRE_IP_LFAST_REGISTER_PROTECTION)
#if (defined (ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT))

        static uint32 const s_pxZipwireBaseAddr[ZIPWIRE_IP_INSTANCE_COUNT_U8] = IP_LFAST_BASE_ADDRS;
        /* Allow user access to register protected */
        Zipwire_Ip_SpecificSetUserAccessAllowed(s_pxZipwireBaseAddr[pxZipwireInstanceConfig->HwInstance]);

#endif /* #if (STD_ON == ZIPWIRE_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* #if (STD_ON == ZIPWIRE_IP_LFAST_REGISTER_PROTECTION) */
#if (STD_OFF == ZIPWIRE_IP_LOOPBACK_MODE)
        /* Initialize appropriate LFAST interface */
        if (pxZipwireInstanceConfig->LfastConfig->Role == LFAST_MASTER)
        {
            ZipwireIpStatus = Zipwire_Ip_MasterInit(pxLfastBase,
                                                    pxZipwireInstanceConfig->LfastConfig);
        }
        else
        {
            ZipwireIpStatus = Zipwire_Ip_SlaveInit(pxLfastBase,
                                                   pxZipwireInstanceConfig->LfastConfig);
        }

#else  /* if (STD_OFF == ZIPWIRE_IP_LOOPBACK_MODE) */
        if (pxZipwireInstanceConfig->LfastConfig->Role == LFAST_MASTER)
        {
            ZipwireIpStatus = Zipwire_Ip_InitLfastLoopback(pxLfastBase, pxZipwireInstanceConfig->LfastConfig);
        }

#endif /* if (STD_OFF == ZIPWIRE_IP_LOOPBACK_MODE) */
    }
    if (ZipwireIpStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        ZipwireIpInitState[pxZipwireInstanceConfig->HwInstance] = ZIPWIRE_INIT;
    }
    return ZipwireIpStatus;
}

/**
 * @brief         Initializes the Zipwire Instances based on the user configuration.
 *
 */
void Zipwire_Ip_InitSipiInstance(const Zipwire_Ip_LogicInstanceConfigType * pxZipwireInstanceConfig)
{
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[pxZipwireInstanceConfig->HwInstance];

    /* Enable SIPI module */
    hwAccZipwireSipi_Enable(pxSipiBase, TRUE);
    /* Enable target functionality for the SIPI module */
    hwAccZipwireSipi_TargetEnable(pxSipiBase, TRUE);
    /* Move SIPI to INIT mode */
    hwAccZipwireSipi_EnterInitMode(pxSipiBase);
    /* Configure address offset and clock prescaler with user options */
    hwAccZipwireSipi_SetAddrOffset(pxSipiBase, (uint8)pxZipwireInstanceConfig->AddrOffset);
    hwAccZipwireSipi_SetTimeoutClockPrescaler(pxSipiBase, ((uint16)pxZipwireInstanceConfig->TimeoutClkDiv));
    /* Move back to NORMAL mode */
    hwAccZipwireSipi_ExitInitMode(pxSipiBase);
    /* Enable CRC error interrupt */
    hwAccZipwireSipi_SetCrcErrInt(pxSipiBase, TRUE);
    /* Configure maximum address interrupt with user option */
    hwAccZipwireSipi_SetMaxCountReachedInt(pxSipiBase, pxZipwireInstanceConfig->MaxCountReachedInt);
}

/**
 * @brief         Deinitializes the Zipwire Instances.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_DeInitInstance(uint8 HwInstance)
{
    LFAST_Type * pxLfastBase = s_ZipwireLfastInstances[HwInstance];
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_InstanceState * InstanceState = &s_axLogicInstanceState[HwInstance];
    uint8 ChannelCounter;
    Zipwire_Ip_StatusType ZipwireIpStatus;

    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);

    /* Perform a soft reset of the SIPI state machine */
    ZipwireIpStatus = hwAccZipwireSipi_SoftReset(pxSipiBase);
    /* Perform a soft reset of the SIPI state machine */

    if (ZipwireIpStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        /* Disable SIPI global interrupts */
        hwAccZipwireSipi_SetCrcErrInt(pxSipiBase, FALSE);
        hwAccZipwireSipi_SetMaxCountReachedInt(pxSipiBase, FALSE);

        /* Reset user callbacks */
        InstanceState->Callback = NULL_PTR;
        InstanceState->CallbackParam = NULL_PTR;
        /* Deinitialize all channels */
        for (ChannelCounter = 0U; ChannelCounter < ZIPWIRE_IP_CHANNEL_COUNT_U8; ChannelCounter++)
        {
            (void)Zipwire_Ip_DeInitChannel(HwInstance, ChannelCounter);
        }

        /* Disable SIPI module */
        hwAccZipwireSipi_Enable(pxSipiBase, FALSE);
        /* LFAST interface */
        hwAccZipwireLfast_EnableLfast(pxLfastBase, FALSE);

        ZipwireIpInitState[HwInstance] = ZIPWIRE_UNINIT;
    }

    return ZipwireIpStatus;
}


/**
 * @brief         Initializes the Zipwire SIPI Channels based on the user configuration.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_InitChannel(const Zipwire_Ip_LogicChannelConfigType *pxZipwireChannelConfig)
{
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[pxZipwireChannelConfig->HwInstance];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[pxZipwireChannelConfig->HwInstance][pxZipwireChannelConfig->HwChannel];
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[pxZipwireChannelConfig->HwInstance][pxZipwireChannelConfig->HwChannel];

    ZIPWIRE_IP_DEV_ASSERT(pxZipwireChannelConfig->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(pxZipwireChannelConfig->HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    /* Create the synchronization semaphore */
    ChannelState->SyncSemaphore = 0U;

    /* Save instance & channel info */
    ChannelState->HwInstance = pxZipwireChannelConfig->HwInstance;
    ChannelState->HwChannel  = pxZipwireChannelConfig->HwChannel;

    /* Save references user callbacks */
    ChannelState->Callback = pxZipwireChannelConfig->Callback;
    ChannelState->CallbackParam = pxZipwireChannelConfig->CallbackParam;

    /* Initialize channel status */
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    /* Initialize transfer buffer reference to NULL_PTR */
    ChannelState->TransferBuffer = NULL_PTR;
    /* Initialize Id request and target ID to zero */
    ChannelState->TargetId = NULL_PTR;
    ChannelState->IdRequest = FALSE;
    ChannelState->DisableNotification = FALSE;

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
    /* Initialize DMA */
    ChannelState->DmaEnable = pxZipwireChannelConfig->DmaEnable;
    ChannelState->DmaDataChn = pxZipwireChannelConfig->DmaDataChn;
    ChannelState->DmaAddrChn = pxZipwireChannelConfig->DmaAddrChn;
    ChannelState->DmaWriteTransfer = FALSE;
#endif

    /* Enable channel interrupts */
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_ERR_IRQ, pxZipwireChannelConfig->AckErrIrq);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TIMEOUT_IRQ, pxZipwireChannelConfig->TimeoutErrIrq);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRANS_ID_ERR_IRQ, pxZipwireChannelConfig->TransIdErrIrq);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRIGGER_IRQ, TRUE);
    /* Move SIPI to INIT mode */
    hwAccZipwireSipi_EnterInitMode(pxSipiBase);
    /* Configure channel timeout */
    hwAccZipwireSipi_SetChannelTimeout(pxSipiChannelBase, pxZipwireChannelConfig->Timeout);
    /* Enable the channel */
    hwAccZipwireSipi_EnableChannel(pxSipiChannelBase, TRUE);
    /* Move back to NORMAL mode*/
    hwAccZipwireSipi_ExitInitMode(pxSipiBase);

    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief         Deinitializes the Zipwire SIPI Channels.
 *
 */
Zipwire_Ip_StatusType Zipwire_Ip_DeInitChannel(uint8 HwInstance, uint8 HwChannel)
{
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    /* Reset user callbacks */
    ChannelState->Callback = NULL_PTR;
    ChannelState->CallbackParam = NULL_PTR;

    /* Disable channel interrupts */
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_ERR_IRQ, FALSE);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TIMEOUT_IRQ, FALSE);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRANS_ID_ERR_IRQ, FALSE);
    hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_TRIGGER_IRQ, FALSE);

    /* Move SIPI to INIT mode */
    hwAccZipwireSipi_EnterInitMode(pxSipiBase);
    /* Disable the channel */
    hwAccZipwireSipi_EnableChannel(pxSipiChannelBase, FALSE);
    /* Move back to NORMAL mode*/
    hwAccZipwireSipi_ExitInitMode(pxSipiBase);

    return ZIPWIRE_IP_STATUS_SUCCESS;
}


/**
 * @brief         This internal function launches a Read command at the
 *                initiator.
 * @implements    Zipwire_Ip_LaunchReadCommand
 */
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchReadCommand(Zipwire_Ip_ChannelState * ChannelState,
                                                          Zipwire_Ip_TransferDescriptor * DataArray,
                                                          uint32 DataArrayLength,
                                                          boolean IsBlocking)
{
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[ChannelState->HwInstance][ChannelState->HwChannel];
    Zipwire_Ip_StatusType retValue;

    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(DataArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArrayLength > 0U);

    /* Check if Hardware Channel is busy with another transfer */
    if (ChannelState->ChannelStatus != ZIPWIRE_IP_STATUS_BUSY)
    {
        /* Transfer setup */
        ChannelState->IsBlocking = IsBlocking;
        ChannelState->TransferBuffer = DataArray;
        ChannelState->RemainingTransfers = DataArrayLength - 1U;
        ChannelState->IdRequest = FALSE;
        /* Channel becomes busy now */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

        /* Configure the word length */
        hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, DataArray->TransferSize);
        /* Enable read request */
        hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, TRUE);
        /* Enable read answer interrupt */
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_READ_ANSWER_FLAG);
        MCAL_FAULT_INJECTION_POINT(ZIPWIRE_CHECK_LAUNCH_READ_FAULT_INJECTION);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, TRUE);
        
        /* Set the target address - this will trigger the transfer */
        hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, DataArray->Address);

        retValue = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        retValue = ZIPWIRE_IP_STATUS_BUSY;
    }

    return retValue;
}

/**
 * @brief         This internal function launches a Write command at the
 *                initiator.
 * @implements    Zipwire_Ip_LaunchWriteCommand
 */
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchWriteCommand(Zipwire_Ip_ChannelState * ChannelState,
                                                           Zipwire_Ip_TransferDescriptor * DataArray,
                                                           uint32 DataArrayLength,
                                                           boolean IsBlocking)
{
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[ChannelState->HwInstance][ChannelState->HwChannel];
    Zipwire_Ip_StatusType retValue;

    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(DataArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArrayLength > 0U);

    /* Check if Hardware Channel is busy with another transfer */
    if (ChannelState->ChannelStatus != ZIPWIRE_IP_STATUS_BUSY)
    {
        /* Transfer setup */
        ChannelState->IsBlocking = IsBlocking;
        ChannelState->TransferBuffer = DataArray;
        ChannelState->RemainingTransfers = DataArrayLength - 1U;
        ChannelState->IdRequest = FALSE;
        /* Channel becomes busy now */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

        /* Enable Write request */
        hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, TRUE);
        /* Enable Write ACK interrupt */
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_ACK_FLAG);
        MCAL_FAULT_INJECTION_POINT(ZIPWIRE_CHECK_LAUNCH_WRITE_FAULT_INJECTION);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, TRUE);

        /* Write the DataArray and trigger the transfer */
        Zipwire_Ip_WriteData(ChannelState->HwInstance, ChannelState->HwChannel, DataArray);

        retValue = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        retValue = ZIPWIRE_IP_STATUS_BUSY;
    }

    return retValue;
}

#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         This internal function launches a Write command at the
 *                initiator using DMA requests.
 *
 * @implements    Zipwire_Ip_LaunchWriteCommandWithDma
 */
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchWriteCommandWithDma(Zipwire_Ip_ChannelState * ChannelState,
                                                                  const uint32 * DataArray,
                                                                  const uint32 * AddressArray,
                                                                  uint32 DataArrayLength,
                                                                  boolean IsBlocking)
{
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[ChannelState->HwInstance];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[ChannelState->HwInstance][ChannelState->HwChannel];
    Zipwire_Ip_StatusType retValue;
    Dma_Ip_ReturnType DmaReturnStatus;

    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(AddressArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArrayLength > 0U);
    ZIPWIRE_IP_DEV_ASSERT(ChannelState->DmaEnable);

    /* Check if channel is busy with another transfer */
    if (ChannelState->ChannelStatus != ZIPWIRE_IP_STATUS_BUSY)
    {
        /* Set up parameters for Dma_Ip_LogicChannelTransferListType Address Channel*/
        s_atAddressDmaTransferList[7U].Value = DataArrayLength;                                              /* DMA_IP_CH_SET_MAJORLOOP_COUNT */

        s_atAddressDmaTransferList[0U].Value = ((uint32)AddressArray);                                       /* DMA_IP_CH_SET_SOURCE_ADDRESS */
        s_atAddressDmaTransferList[3U].Value = (uint32)(&(pxSipiChannelBase->CAR));                          /* DMA_IP_CH_SET_DESTINATION_ADDRESS */
        s_atAddressDmaTransferList[1U].Value = 4;                                                            /* DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET */
        s_atAddressDmaTransferList[4U].Value = 0;                                                            /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET
                                                                                                              * */
        s_atAddressDmaTransferList[2U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                  /* DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE */
        s_atAddressDmaTransferList[5U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                  /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE
                                                                                                              * */

        s_atAddressDmaTransferList[8U].Value = TRUE;                                                         /*
                                                                                                              * DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT
                                                                                                              * */

        /* Set up parameters for Dma_Ip_LogicChannelTransferListType Data Channel*/
        s_atDataDmaTransferList[8U].Value = ChannelState->DmaAddrChn;                                        /* DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH
                                                                                                              * */
        s_atDataDmaTransferList[9U].Value = TRUE;                                                            /* DMA_IP_CH_SET_MAJORLOOP_EN_LINK */
        s_atDataDmaTransferList[10U].Value = ChannelState->DmaAddrChn;                                       /* DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH
                                                                                                              * */
        s_atDataDmaTransferList[11U].Value = DataArrayLength;                                                /* DMA_IP_CH_SET_MAJORLOOP_COUNT */
        s_atDataDmaTransferList[12U].Value = FALSE;                                                          /*
                                                                                                              * DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT
                                                                                                              * */

        s_atDataDmaTransferList[0U].Value = ((uint32)(DataArray));                                           /* DMA_IP_CH_SET_SOURCE_ADDRESS */
        s_atDataDmaTransferList[3U].Value = ((uint32)(&(pxSipiChannelBase->CDR)));                           /* DMA_IP_CH_SET_DESTINATION_ADDRESS */
        s_atDataDmaTransferList[1U].Value = ((int16_t)4);                                                    /* DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET */
        s_atDataDmaTransferList[4U].Value = ((int16_t)0);                                                    /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET
                                                                                                              * */
        s_atDataDmaTransferList[2U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                     /* DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE */
        s_atDataDmaTransferList[5U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                     /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE
                                                                                                              * */

        /* Transfer setup */
        ChannelState->IsBlocking = IsBlocking;
        ChannelState->RemainingTransfers = 0U;
        ChannelState->IdRequest = FALSE;
        ChannelState->DmaWriteTransfer = TRUE;
        /* Channel becomes busy now */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

        DmaReturnStatus = Dma_Ip_SetLogicChannelGlobalList(ChannelState->DmaDataChn, s_atDmaGlobalList, ZIPWIRE_IP_DMA_GLOBAL_CONFIG_DIMENSION);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);

        s_atDmaGlobalList[1U].Value = FALSE;
        DmaReturnStatus = Dma_Ip_SetLogicChannelGlobalList(ChannelState->DmaAddrChn, s_atDmaGlobalList, ZIPWIRE_IP_DMA_GLOBAL_CONFIG_DIMENSION);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);

        /* Set the DMA configurations in the two TCDs and start the channels */
        if (s_atAddressDmaTransferList[7U].Value > 0U)
        {
            DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(ChannelState->DmaAddrChn, s_atAddressDmaTransferList, ZIPWIRE_IP_DMA_ADDRESS_CONFIG_DIMENSION);
            ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);
        }

        DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(ChannelState->DmaDataChn, s_atDataDmaTransferList, ZIPWIRE_IP_DMA_DATA_CONFIG_DIMENSION);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);
        /* Start transfer with Dma Logic Channel Name */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(ChannelState->DmaDataChn, DMA_IP_CH_SET_HARDWARE_REQUEST);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);

        if (DmaReturnStatus == DMA_IP_STATUS_SUCCESS)
        {
            /* Only 32 bits transfers supported in DMA mode */
            hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, ZIPWIRE_32_BITS);

            /* Enable Write request */
            hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, TRUE);

            /* Enable DMA functionality for the channel */
            hwAccZipwireSipi_EnterInitMode(pxSipiBase);
            hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, TRUE);
            hwAccZipwireSipi_ExitInitMode(pxSipiBase);

            retValue = ZIPWIRE_IP_STATUS_SUCCESS;
        }
        else
        {
            retValue = ZIPWIRE_IP_STATUS_ERROR;
        }
    }
    else
    {
        retValue = ZIPWIRE_IP_STATUS_BUSY;
    }

    return retValue;
}

/**
 * @brief         This internal function launches a Read command at the
 *                initiator using DMA requests.
 *
 * @implements    Zipwire_Ip_LaunchReadCommandWithDma
 */
static Zipwire_Ip_StatusType Zipwire_Ip_LaunchReadCommandWithDma(Zipwire_Ip_ChannelState * ChannelState,
                                                                 const uint32 * DataArray,
                                                                 const uint32 * AddressArray,
                                                                 uint32 DataArrayLength,
                                                                 boolean IsBlocking)
{
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[ChannelState->HwInstance];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[ChannelState->HwInstance][ChannelState->HwChannel];
    Zipwire_Ip_StatusType retValue;
    Dma_Ip_ReturnType DmaReturnStatus;

    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(ChannelState->HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(AddressArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArray != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT(DataArrayLength > 1U);
    ZIPWIRE_IP_DEV_ASSERT(ChannelState->DmaEnable);


    /* Check if channel is busy with another transfer */
    if (ChannelState->ChannelStatus != ZIPWIRE_IP_STATUS_BUSY)
    {
        /* Set up parameters for Dma_Ip_LogicChannelTransferListType Address Channel*/
        s_atAddressDmaTransferList[7U].Value = ((DataArrayLength - 1));                                      /* DMA_IP_CH_SET_MAJORLOOP_COUNT */

        s_atAddressDmaTransferList[0U].Value = ((uint32)AddressArray);                                       /* DMA_IP_CH_SET_SOURCE_ADDRESS */
        s_atAddressDmaTransferList[3U].Value = (uint32)(&(pxSipiChannelBase->CAR));                          /* DMA_IP_CH_SET_DESTINATION_ADDRESS */
        s_atAddressDmaTransferList[1U].Value = 4;                                                            /* DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET */
        s_atAddressDmaTransferList[4U].Value = 0;                                                            /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET
                                                                                                              * */
        s_atAddressDmaTransferList[2U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                  /* DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE */
        s_atAddressDmaTransferList[5U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                  /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE
                                                                                                              * */

        s_atAddressDmaTransferList[8U].Value = FALSE;                                                        /*
                                                                                                              * DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT
                                                                                                              * */

        /* Set up parameters for Dma_Ip_LogicChannelTransferListType Data Channel*/
        s_atDataDmaTransferList[8U].Value = ChannelState->DmaAddrChn;                                        /* DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH
                                                                                                              * */
        s_atDataDmaTransferList[9U].Value = FALSE;                                                           /* DMA_IP_CH_SET_MAJORLOOP_EN_LINK */
        s_atDataDmaTransferList[10U].Value = ChannelState->DmaAddrChn;                                       /* DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH
                                                                                                              * */
        s_atDataDmaTransferList[11U].Value = DataArrayLength;                                                /* DMA_IP_CH_SET_MAJORLOOP_COUNT */
        s_atDataDmaTransferList[12U].Value = TRUE;                                                           /*
                                                                                                              * DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT
                                                                                                              * */

        s_atDataDmaTransferList[0U].Value = ((uint32)(&(pxSipiChannelBase->CDR)));                           /* DMA_IP_CH_SET_SOURCE_ADDRESS */
        s_atDataDmaTransferList[3U].Value = ((uint32)DataArray);                                             /* DMA_IP_CH_SET_DESTINATION_ADDRESS */
        s_atDataDmaTransferList[1U].Value = ((int16_t)0);                                                    /* DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET */
        s_atDataDmaTransferList[4U].Value = ((int16_t)4);                                                    /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET
                                                                                                              * */
        s_atDataDmaTransferList[2U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                     /* DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE */
        s_atDataDmaTransferList[5U].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;                                     /*
                                                                                                              * DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE
                                                                                                              * */

        /* Transfer setup */
        ChannelState->IsBlocking = IsBlocking;
        ChannelState->RemainingTransfers = 0U;
        ChannelState->IdRequest = FALSE;
        ChannelState->DmaWriteTransfer = FALSE;
        /* Channel becomes busy now */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

        /* Set the DMA configurations in the two TCDs and start the channels */
        if (s_atAddressDmaTransferList[7U].Value > 0U)
        {
            /* First address is written by sw, DMA starts transferring from the next */
            s_atAddressDmaTransferList[0U].Value += 4U;

            DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(ChannelState->DmaAddrChn, s_atAddressDmaTransferList, ZIPWIRE_IP_DMA_ADDRESS_CONFIG_DIMENSION);
            ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);
        }

        DmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(ChannelState->DmaDataChn, s_atDataDmaTransferList, ZIPWIRE_IP_DMA_DATA_CONFIG_DIMENSION);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);
        /* Start transfer with Dma Logic Channel Name */
        DmaReturnStatus = Dma_Ip_SetLogicChannelCommand(ChannelState->DmaDataChn, DMA_IP_CH_SET_HARDWARE_REQUEST);
        ZIPWIRE_IP_DEV_ASSERT(DmaReturnStatus == DMA_IP_STATUS_SUCCESS);

        if (DmaReturnStatus == DMA_IP_STATUS_SUCCESS)
        {
            /* Only 32 bits transfers supported in DMA mode */
            hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, ZIPWIRE_32_BITS);

            /* Enable Read request */
            hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, TRUE);

            /* Enable DMA functionality for the channel */
            hwAccZipwireSipi_EnterInitMode(pxSipiBase);
            hwAccZipwireSipi_SetChannelTimeout(pxSipiChannelBase, 0xFF);
            hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, TRUE);
            hwAccZipwireSipi_ExitInitMode(pxSipiBase);

            hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, *AddressArray);

            retValue = ZIPWIRE_IP_STATUS_SUCCESS;
        }
        else
        {
            retValue = ZIPWIRE_IP_STATUS_ERROR;
        }
    }
    else
    {
        retValue = ZIPWIRE_IP_STATUS_BUSY;
    }

    return retValue;
}

/**
 * @brief         This internal function represents the DMA Callback used
 *                internally by the driver to finish DMA transfers.
 *
 *
 */
void Zipwire_Ip_DmaCallback(uint8 HwInstance,
                            uint8 HwChannel)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    Zipwire_Ip_Events Event;

    /* Disable read/write requests */
    if (ChannelState->DmaWriteTransfer)
    {
        hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_ACK_FLAG);
        Event = ZIPWIRE_EVENT_WRITE_COMPLETE;
    }
    else
    {
        hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_READ_ANSWER_FLAG);
        Event = ZIPWIRE_EVENT_READ_COMPLETE;
    }

    /* Update internal DmaStatus */
    if (((Zipwire_Ip_xDmaChStatusData.Done == TRUE) && (Zipwire_Ip_xDmaChStatusData.Errors == 0x00U)) && (((Zipwire_Ip_xDmaChStatusAddress.Done == TRUE) && (Zipwire_Ip_xDmaChStatusAddress.Errors == 0x00U))))
    {
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ERROR;
    }

    /* If the transfer was blocking, notify the waiting thread */
    if (ChannelState->IsBlocking)
    {
        ChannelState->SyncSemaphore = 1U;
        ChannelState->IsBlocking = FALSE;
    }

    /* Call the user Callback, if any */
    if (ChannelState->Callback != NULL_PTR)
    {
        if (((Zipwire_Ip_xDmaChStatusData.Done == TRUE) && (Zipwire_Ip_xDmaChStatusData.Errors == 0x00U)) && (((Zipwire_Ip_xDmaChStatusAddress.Done == TRUE) && (Zipwire_Ip_xDmaChStatusAddress.Errors == 0x00U))))
        {
            ChannelState->Callback(ChannelState->HwInstance, ChannelState->HwChannel, Event, ChannelState->CallbackParam);
        }
        else
        {
            ChannelState->Callback(ChannelState->HwInstance, ChannelState->HwChannel, ZIPWIRE_EVENT_DMA_ERR, ChannelState->CallbackParam);
        }
    }
}

#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/**
 * @brief         This internal function stops the ongoing transfer.
 *
 * @implements    Zipwire_Ip_StopTransfer_Activity.
 */
static void Zipwire_Ip_StopTransfer(uint8 HwInstance,
                                    uint8 HwChannel)
{
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[HwInstance];

    /* Stop DMA */
    if (ChannelState->DmaEnable)
    {
        hwAccZipwireSipi_EnterInitMode(pxSipiBase);
        hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, FALSE);
        hwAccZipwireSipi_ExitInitMode(pxSipiBase);
    }

#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */

    if (ChannelState->IsBlocking)
    {
        ChannelState->SyncSemaphore = 1U;
    }

    /* Disable all requests */
    pxSipiChannelBase->CCR &= ~(SIPI_CCR0_WRT_MASK | SIPI_CCR0_RRT_MASK | SIPI_CCR0_TC_MASK);
    /* Disable read answer/write ack interrupts */
    pxSipiChannelBase->CIR &= ~(SIPI_CIR0_WAIE_MASK | SIPI_CIR0_RAIE_MASK);
}

/**
 * @brief         This internal function computes the correct values for DataArray
 *                and Address registers for the desired DataArray to reach the right
 *                location at the target node.
 *
 */
static void Zipwire_Ip_WriteData(uint8 HwInstance,
                                 uint8 HwChannel,
                                 const Zipwire_Ip_TransferDescriptor * DataArray)
{
    ZIPWIRE_IP_DEV_ASSERT((DataArray->TransferSize != ZIPWIRE_16_BITS) || ((DataArray->Address & 1U) == 0U));
    ZIPWIRE_IP_DEV_ASSERT((DataArray->TransferSize != ZIPWIRE_32_BITS) || ((DataArray->Address & 3U) == 0U));

    uint32 Address = DataArray->Address;
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* Configure transfer Size */
    hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, DataArray->TransferSize);

    switch (DataArray->TransferSize)
    {
        case ZIPWIRE_32_BITS:
            /* No processing needed for 32-bit words */
            hwAccZipwireSipi_SetChannelData(pxSipiChannelBase, DataArray->Data);
        break;
        case ZIPWIRE_16_BITS:
            /* For 16-bit words with multiple-of-4 addresses (ending in 0b00), Data needs to be shifted with 16 bits */
            hwAccZipwireSipi_SetChannelData(pxSipiChannelBase, (DataArray->Data << ((DataArray->Address & 2U) << 3U)));
            /* LSB of Address determines which half word will be transferred from the DataArray register */
            Address |= (((DataArray->Address & 2U) >> 1U) ^ 1U);
        break;
        case ZIPWIRE_8_BITS:
            /* For 8-bit transfers, Data needs to be shifted on the appropriate byte within the DATA register */
            hwAccZipwireSipi_SetChannelData(pxSipiChannelBase, (DataArray->Data << (((Address & 3U) ^ 3U) << 3U)));
        break;
        default:
            /* This branch should never be reached */
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
        break;
    }

    /* Set the target Address - this will trigger the transfer */
    hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, Address);
}

/*==================================================================================================
 *                                   IRQ HANDLER FUNCTIONS
==================================================================================================*/

/**
 * @brief         IRQ handler for read answer received interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_ChnReadAnswerHandler(uint8 HwInstance,
                                          uint8 HwChannel)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];


    /* ID request serviced */
    if (ChannelState->IdRequest)
    {
        /* Get the received ID */
        *ChannelState->TargetId = ZIPWIRE_IP_SIPI_DATA(hwAccZipwireSipi_GetChannelData(pxSipiChannelBase), ZIPWIRE_32_BITS);

        /* Update HwChannel state */
        ChannelState->TargetId = NULL_PTR;
        ChannelState->IdRequest = FALSE;

        /* Disable the interrupt and the Id requests for this HwChannel */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
        hwAccZipwireSipi_SetChannelIdTransferRequest(pxSipiChannelBase, FALSE);

        /* Update internal status */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;
        ChannelState->SyncSemaphore = 1U;
        /* Call the user Callback, if any */
        if (ChannelState->Callback != NULL_PTR)
        {
            ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_TARGET_ID_RECEIVED, ChannelState->CallbackParam);
        }
    }
    /* Read request serviced */
    else
    {
        /* Get the received data in the user buffer */
        ChannelState->TransferBuffer->Data = ZIPWIRE_IP_SIPI_DATA(hwAccZipwireSipi_GetChannelData(pxSipiChannelBase), ChannelState->TransferBuffer->TransferSize);

        /* If this was the last transfer, disable this HwChannel from further listening for answers */
        if (ChannelState->RemainingTransfers == 0U)
        {
            /* Disable the interrupt and the read requests for this HwChannel */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);

            /* Update internal status */
            ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;

            /* If the transfer was blocking, notify the waiting thread */
            if (ChannelState->IsBlocking)
            {
                ChannelState->IsBlocking = FALSE;
                ChannelState->SyncSemaphore = 1U;
            }

            /* Call the user Callback, if any */
            if (ChannelState->Callback != NULL_PTR)
            {
                ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_READ_COMPLETE, ChannelState->CallbackParam);
            }
        }
        /* More transfers to be done */
        else
        {
            /* Update buffer reference */
            ChannelState->TransferBuffer++;
            ChannelState->RemainingTransfers--;

            /* Configure and launch the next transfer */
            hwAccZipwireSipi_SetChannelWordLength(pxSipiChannelBase, ChannelState->TransferBuffer->TransferSize);
            hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, ChannelState->TransferBuffer->Address);
        }
    }
}

/**
 * @brief         IRQ handler for ACK received interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_ChnAckHandler(uint8 HwInstance,
                                   uint8 HwChannel)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* If this was the last transfer, disable this channel from further writing data */
    if (ChannelState->RemainingTransfers == 0U)
    {
        /* Disable the interrupt and the write transfers for this HwChannel */
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
        pxSipiChannelBase->CCR &= ~(SIPI_CCR0_WRT_MASK | SIPI_CCR0_TC_MASK);

        /* Update internal status */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_SUCCESS;

        /* If the transfer was blocking, notify the waiting thread */
        if (ChannelState->IsBlocking)
        {
            ChannelState->IsBlocking = FALSE;
            ChannelState->SyncSemaphore = 1U;
        }

        /* Call the user Callback, if any */
        if ((ChannelState->Callback != NULL_PTR) && (!(ChannelState->DisableNotification)))
        {
            ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_WRITE_COMPLETE, ChannelState->CallbackParam);
        }
    }
    /* More transfers to be done */
    else
    {
        /* Update buffer reference */
        ChannelState->TransferBuffer++;
        ChannelState->RemainingTransfers--;

        /* Launch the next transfer */
        Zipwire_Ip_WriteData(HwInstance, HwChannel, ChannelState->TransferBuffer);
    }
}

/**
 * @brief         IRQ handler for trigger command received interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_ChnTriggerHandler(uint8 HwInstance,
                                       uint8 HwChannel)
{
    const Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_TRIGGER_COMMAND, ChannelState->CallbackParam);
    }
}

/**
 * @brief         IRQ handler for global CRC error interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_CrcErrHandler(uint8 HwInstance)
{
    const Zipwire_Ip_InstanceState * InstanceState = &s_axLogicInstanceState[HwInstance];
    if (InstanceState->Callback != NULL_PTR)
    {
        InstanceState->Callback(HwInstance, ZIPWIRE_EVENT_GLOBAL_CRC_ERR, InstanceState->CallbackParam);
    }
}

/**
 * @brief         IRQ handler for max count reached interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_MaxCountReachedHandler(uint8 HwInstance)
{
    const Zipwire_Ip_InstanceState * InstanceState = &s_axLogicInstanceState[HwInstance];
    if (InstanceState->Callback != NULL_PTR)
    {
        InstanceState->Callback(HwInstance, ZIPWIRE_EVENT_MAX_COUNT_REACHED, InstanceState->CallbackParam);
    }
}

/**
 * @brief         IRQ handler for channel timeout error interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_ChnTimeoutErrHandler(uint8 HwInstance,
                                          uint8 HwChannel)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ZIPWIRE_TIMEOUT_ERR;
    Zipwire_Ip_StopTransfer(HwInstance, HwChannel);
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_TIMEOUT_ERR, ChannelState->CallbackParam);
    }
}

/**
 * @brief         IRQ handler for channel transaction ID error interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_ChnTransIdErrHandler(uint8 HwInstance,
                                          uint8 HwChannel)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ZIPWIRE_TRANSACTION_ID_ERR;
    Zipwire_Ip_StopTransfer(HwInstance, HwChannel);
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_TRANSACTION_ID_ERR, ChannelState->CallbackParam);
    }
}

/**
 * @brief         IRQ handler for channel ACK error interrupt.
 *
 *
 */
void Zipwire_Ip_Sipi_ChnAckErrHandler(uint8 HwInstance,
                                      uint8 HwChannel)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_ZIPWIRE_ACK_ERR;
    Zipwire_Ip_StopTransfer(HwInstance, HwChannel);
    if (ChannelState->Callback != NULL_PTR)
    {
        ChannelState->Callback(HwInstance, HwChannel, ZIPWIRE_EVENT_ACK_ERR, ChannelState->CallbackParam);
    }
}

/**
 * @brief         This function returns the current channel status.
 *
 */
Zipwire_Ip_ChannelState Zipwire_Ip_GetChannelState(uint8 HwInstance, uint8 HwChannel)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    return s_axLogicChannelState[HwInstance][HwChannel];
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the ZIPWIRE Driver settings based on user configuration.
 * @implements    Zipwire_Ip_Init_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_Init(const Zipwire_Ip_ConfigType *const pxZipwireConfig)
{
    uint8 LocInstanceIndex = 0U;
    uint8 LocChannelIndex  = 0U;

    uint8 Status = (uint8)ZIPWIRE_IP_STATUS_SUCCESS;
    Zipwire_Ip_StatusType ZipwireIpStatus = ZIPWIRE_IP_STATUS_SUCCESS;

    ZIPWIRE_IP_DEV_ASSERT(NULL_PTR != pxZipwireConfig);

    /* Save pointer to initialization structure for LogicInstanceConfigList */
    s_ppaxLogicInstanceInit = pxZipwireConfig->ZipwireIpInstanceCfg->LogicInstanceConfigList;

    for (LocInstanceIndex = 0U; LocInstanceIndex < ZIPWIRE_IP_NUM_LOGIC_INSTANCE_MAX; LocInstanceIndex++)
    {
        if (NULL_PTR != s_ppaxLogicInstanceInit[LocInstanceIndex])
        {
        #if (ZIPWIRE_IP_MULTIPARTITION_SUPPORT_ENABLED == STD_ON)
            if(s_ppaxLogicInstanceInit[LocInstanceIndex]->ZipwireEcucPartitionRef == (uint32)Zipwire_Ip_GetUserId())
            {
        #endif
                ZIPWIRE_IP_DEV_ASSERT(ZipwireIpInitState[LocInstanceIndex] != ZIPWIRE_INIT);
                Status |= (uint8)Zipwire_Ip_InitInstance(s_ppaxLogicInstanceInit[LocInstanceIndex]);
        #if (ZIPWIRE_IP_MULTIPARTITION_SUPPORT_ENABLED == STD_ON)
            }
        #endif
        }
        else
        {
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
        }
    }

    /* Save pointer to initialization structure for LogicChannelConfig */
    s_ppaxLogicChannelInit = pxZipwireConfig->ZipwireIpChannelCfg->LogicChannelConfigList;

    for (LocChannelIndex = 0U; LocChannelIndex < ZIPWIRE_IP_NUM_LOGIC_CHANNEL_MAX; LocChannelIndex++)
    {
        if (NULL_PTR != s_ppaxLogicChannelInit[LocChannelIndex])
        {
            Status |= (uint8)Zipwire_Ip_InitChannel(s_ppaxLogicChannelInit[LocChannelIndex]);
        }
        else
        {
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
        }
    }

    if (Status == (uint8)ZIPWIRE_IP_STATUS_SUCCESS)
    {
        ZipwireIpStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        ZipwireIpStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
    }

    return ZipwireIpStatus;
}


/**
 * @brief         Deinitializes the ZIPWIRE Driver settings based on user configuration.
 * @implements    Zipwire_Ip_DeInit_Activity
 */
void Zipwire_Ip_DeInit(const Zipwire_Ip_ConfigType * const pxZipwireConfig)
{
    uint8 LocInstanceIndex = 0U;

    ZIPWIRE_IP_DEV_ASSERT(NULL_PTR != pxZipwireConfig);

    /* Save pointer to initialization structure for LogicInstanceConfigList */
    s_ppaxLogicInstanceInit = pxZipwireConfig->ZipwireIpInstanceCfg->LogicInstanceConfigList;
    for (LocInstanceIndex = 0U; LocInstanceIndex < ZIPWIRE_IP_NUM_LOGIC_INSTANCE_MAX; LocInstanceIndex++)
    {
        if (NULL_PTR != s_ppaxLogicInstanceInit[LocInstanceIndex])
        {
        #if (ZIPWIRE_IP_MULTIPARTITION_SUPPORT_ENABLED == STD_ON)
            if(s_ppaxLogicInstanceInit[LocInstanceIndex]->ZipwireEcucPartitionRef == (uint32)Zipwire_Ip_GetUserId())
            {
        #endif
                (void)Zipwire_Ip_DeInitInstance(s_ppaxLogicInstanceInit[LocInstanceIndex]->HwInstance);
        #if (ZIPWIRE_IP_MULTIPARTITION_SUPPORT_ENABLED == STD_ON)
            }
        #endif

        }
        else
        {
            ZIPWIRE_IP_DEV_ASSERT(FALSE);
        }
    }
}

/**
 * @brief         This function performs multiple read transfers, asynchronously.
 * @implements    Zipwire_Ip_Read_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_Read(uint8 HwInstance,
uint8 HwChannel,
      Zipwire_Ip_TransferDescriptor * DataArray,
uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadStatus;
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the read command and return */
    ReadStatus = Zipwire_Ip_LaunchReadCommand(ChannelState, DataArray, DataArrayLength, FALSE);

    return ReadStatus;
}


/**
 * @brief         This function performs multiple read transfers, asynchronously and
 *                waits for either transfer completion or timeout Event.
 * @implements    Zipwire_Ip_ReadBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadBlocking(uint8 HwInstance,
                                              uint8 HwChannel,
                                              Zipwire_Ip_TransferDescriptor * DataArray,
                                              uint32 DataArrayLength)
{
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_StatusType ReadBlockingStatus;
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the read command */
    ReadBlockingStatus = Zipwire_Ip_LaunchReadCommand(ChannelState, DataArray, DataArrayLength, TRUE);

    if (ReadBlockingStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        /* Wait for all the read requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while ((!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks)) && (ChannelState->SyncSemaphore == 0U))
        {
        }

        if (ElapsedTime >= TimeoutTicks)
        {
            ReadBlockingStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
            ChannelState->IsBlocking = FALSE;
            /* In case of timeout, disable channel logic, so no answers are considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);
            /* Update channel status */
            ChannelState->ChannelStatus = ReadBlockingStatus;
        }
        else
        {
            ReadBlockingStatus = ChannelState->ChannelStatus;
            ChannelState->SyncSemaphore = 0U;
        }
    }

    return ReadBlockingStatus;
}


#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         This function performs multiple read transfers using DMA.
 *                The function returns right after launching the first command.
 * @implements    Zipwire_Ip_ReadDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadDma(uint8 HwInstance,
                                         uint8 HwChannel,
                                         const uint32 * DataArray,
                                         const uint32 * AddressArray,
                                         uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadDmaStatus;
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the read command and return */
    ReadDmaStatus = Zipwire_Ip_LaunchReadCommandWithDma(ChannelState, DataArray, AddressArray, DataArrayLength, FALSE);

    return ReadDmaStatus;
}


/**
 * @brief         This function performs multiple read transfers using DMA and
 *                waits for either transfer completion or timeout Event.
 * @implements    Zipwire_Ip_ReadDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_ReadDmaBlocking(uint8 HwInstance,
                                                 uint8 HwChannel,
                                                 const uint32 * DataArray,
                                                 const uint32 * AddressArray,
                                                 uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType ReadDmaBlockingStatus;
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the read command */
    ReadDmaBlockingStatus = Zipwire_Ip_LaunchReadCommandWithDma(ChannelState, DataArray, AddressArray, DataArrayLength, TRUE);

    if (ReadDmaBlockingStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        /* Wait for all the read requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while ((!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks)) && (ChannelState->SyncSemaphore == 0U))
        {
        }

        if (ElapsedTime >= TimeoutTicks)
        {
            ReadDmaBlockingStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
            ChannelState->IsBlocking = FALSE;
            /* Move SIPI to INIT mode */
            hwAccZipwireSipi_EnterInitMode(pxSipiBase);
            /* Disable HwChannel DMA */
            hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, FALSE);
            /* Move SIPI back to normal mode */
            hwAccZipwireSipi_ExitInitMode(pxSipiBase);
            /* Disable HwChannel read requests */
            hwAccZipwireSipi_SetChannelReadRequest(pxSipiChannelBase, FALSE);
            /* Update HwChannel status */
            ChannelState->ChannelStatus = ReadDmaBlockingStatus;
        }
        else
        {
            ReadDmaBlockingStatus = ChannelState->ChannelStatus;
            ChannelState->SyncSemaphore = 0U;
        }
    }

    return ReadDmaBlockingStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/**
 * @brief         This function performs multiple write transfers, asynchronously.
 * @implements    Zipwire_Ip_Write_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_Write(uint8 HwInstance,
                                       uint8 HwChannel,
                                       Zipwire_Ip_TransferDescriptor * DataArray,
                                       uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteStatus;
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the write command and return */
    WriteStatus = Zipwire_Ip_LaunchWriteCommand(ChannelState, DataArray, DataArrayLength, FALSE);

    return WriteStatus;
}


/**
 * @brief         This function performs multiple write transfers, synchronously.
 * @implements    Zipwire_Ip_WriteBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteBlocking(uint8 HwInstance,
                                               uint8 HwChannel,
                                               Zipwire_Ip_TransferDescriptor * DataArray,
                                               uint32 DataArrayLength)
{
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    Zipwire_Ip_StatusType WriteBlockingStatus;

    /* Launch the write command */
    WriteBlockingStatus = Zipwire_Ip_LaunchWriteCommand(ChannelState, DataArray, DataArrayLength, TRUE);

    if (WriteBlockingStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        /* Wait for all the write requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while ((!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks)) && (ChannelState->SyncSemaphore == 0U))
        {
        }

        if (ElapsedTime >= TimeoutTicks)
        {
            WriteBlockingStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
            ChannelState->IsBlocking = FALSE;
            /* In case of timeout, disable channel logic, so no ACK is considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
            /* Update channel status */
            ChannelState->ChannelStatus = WriteBlockingStatus;
        }
        else
        {
            WriteBlockingStatus = ChannelState->ChannelStatus;
            ChannelState->SyncSemaphore = 0U;
        }
    }

    return WriteBlockingStatus;
}


#if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE)
/**
 * @brief         This function performs multiple write transfers using DMA.
 *                The function returns right after launching the first command.
 * @implements    Zipwire_Ip_WriteDma_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteDma(uint8 HwInstance,
                                          uint8 HwChannel,
                                          const uint32 * DataArray,
                                          const uint32 * AddressArray,
                                          uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaStatus;
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    /* Launch the write command and return */
    WriteDmaStatus = Zipwire_Ip_LaunchWriteCommandWithDma(ChannelState, DataArray, AddressArray, DataArrayLength, FALSE);

    return WriteDmaStatus;
}


/**
 * @brief         This function performs multiple write transfers using DMA and
 *                waits for either transfer completion or timeout Event.
 * @implements    Zipwire_Ip_WriteDmaBlocking_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_WriteDmaBlocking(uint8 HwInstance,
                                                  uint8 HwChannel,
                                                  const uint32 * DataArray,
                                                  const uint32 * AddressArray,
                                                  uint32 DataArrayLength)
{
    Zipwire_Ip_StatusType WriteDmaBlockingStatus;
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];

    /* Launch the write command */
    WriteDmaBlockingStatus = Zipwire_Ip_LaunchWriteCommandWithDma(ChannelState, DataArray, AddressArray, DataArrayLength, TRUE);

    if (WriteDmaBlockingStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        /* Wait for all the write requests to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while ((!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks)) && (ChannelState->SyncSemaphore == 0U))
        {
        }

        if (ElapsedTime >= TimeoutTicks)
        {
            WriteDmaBlockingStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
            ChannelState->IsBlocking = FALSE;
            /* Move SIPI to INIT mode */
            hwAccZipwireSipi_EnterInitMode(pxSipiBase);
            /* Disable HwChannel DMA */
            hwAccZipwireSipi_EnableChannelDma(pxSipiChannelBase, FALSE);
            /* Move SIPI back to normal mode */
            hwAccZipwireSipi_ExitInitMode(pxSipiBase);
            /* Disable HwChannel write requests */
            hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
            /* Update HwChannel WriteDmaBlockingStatusus */
            ChannelState->ChannelStatus = WriteDmaBlockingStatus;
        }
        else
        {
            WriteDmaBlockingStatus = ChannelState->ChannelStatus;
            ChannelState->SyncSemaphore = 0U;
        }
    }

    return WriteDmaBlockingStatus;
}
#endif /* #if (STD_ON == ZIPWIRE_IP_DMA_IS_AVAILABLE) */


/**
 * @brief         This function performs a streaming write operation synchronously.
 * @implements    Zipwire_Ip_StreamWrite_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_StreamWrite(uint8 HwInstance,
                                             uint8 HwChannel,
                                             Zipwire_Ip_StreamWriteConfig TargetConfig,
                                             const uint32 * Data)
{
    uint8 StreamCounter;
    const uint32 * StreamData = Data;
    Zipwire_Ip_TransferDescriptor TargetConfigACR;
    Zipwire_Ip_TransferDescriptor TargetConfigARR;
    Zipwire_Ip_TransferDescriptor TargetConfigMAXCR;

    Zipwire_Ip_StatusType StreamWriteStatus;
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    SIPI_Type * pxSipiBase = s_ZipwireSipiInstances[HwInstance];
    uint8 Status = (uint8)ZIPWIRE_IP_STATUS_SUCCESS;

    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel == ZIPWIRE_IP_STREAMING_CHANNEL);
    ZIPWIRE_IP_DEV_ASSERT(Data != NULL_PTR);
    ZIPWIRE_IP_DEV_ASSERT((TargetConfig.AcrDataAddress & ZIPWIRE_IP_SIPI_STREAM_ADDRESS_MASK_U32) == TargetConfig.AcrDataAddress);
    ZIPWIRE_IP_DEV_ASSERT((TargetConfig.ArrDataAddress & ZIPWIRE_IP_SIPI_STREAM_ADDRESS_MASK_U32) == TargetConfig.ArrDataAddress);
    ZIPWIRE_IP_DEV_ASSERT((TargetConfig.TargetMaxcrRegAddress & ZIPWIRE_IP_SIPI_STREAM_ADDRESS_MASK_U32) == TargetConfig.TargetMaxcrRegAddress);

    /* Create a transfer descriptor for configuring target address in the ACR register */
    TargetConfigACR.TransferSize = ZIPWIRE_32_BITS;
    TargetConfigACR.Address = TargetConfig.TargetAcrRegAddress;
    TargetConfigACR.Data = TargetConfig.AcrDataAddress;

    /* Create a transfer descriptor for configuring target address in the ARR register */
    TargetConfigARR.TransferSize = ZIPWIRE_32_BITS;
    TargetConfigARR.Address = TargetConfig.TargetArrRegAddress;
    TargetConfigARR.Data = TargetConfig.ArrDataAddress;

    /* Create a transfer descriptor for configuring target address in the MAXCR register */
    TargetConfigMAXCR.TransferSize = ZIPWIRE_32_BITS;
    TargetConfigMAXCR.Address = TargetConfig.TargetMaxcrRegAddress;
    TargetConfigMAXCR.Data = TargetConfig.MaxcrDataAddress;

    /* Temporary disable notifications */
    ChannelState->DisableNotification = TRUE;

    /* Perform a single write command to set the ACR at the target node */
    Status |= (uint8)Zipwire_Ip_WriteBlocking(HwInstance, HwChannel, &TargetConfigACR, 1U);

    /* Perform a single write command to set the ARR at the target node */
    Status |= (uint8)Zipwire_Ip_WriteBlocking(HwInstance, HwChannel, &TargetConfigARR, 1U);

    /* Perform a single write command to set the MAXCR at the target node */
    Status |= (uint8)Zipwire_Ip_WriteBlocking(HwInstance, HwChannel, &TargetConfigMAXCR, 1U);

    if (Status == (uint8)ZIPWIRE_IP_STATUS_SUCCESS)
    {
        StreamWriteStatus = ZIPWIRE_IP_STATUS_SUCCESS;
    }
    else
    {
        StreamWriteStatus = (Zipwire_Ip_StatusType)Status;
    }

    /* Enable back success notification */
    ChannelState->DisableNotification = FALSE;
    if (StreamWriteStatus == ZIPWIRE_IP_STATUS_SUCCESS)
    {
        /* Channel setup */
        ChannelState->IsBlocking = TRUE;
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;
        ChannelState->RemainingTransfers = 0U;

        /* Fill in the Data for the streaming transfer */
        for (StreamCounter = 0U; StreamCounter < ZIPWIRE_IP_SIPI_STREAM_TRANSFER_LEN_U8; StreamCounter++)
        {
            ZIPWIRE_IP_SIPI_STREAM_DATA(pxSipiBase, StreamCounter) = *StreamData;
            StreamData++;
        }

        /* Enable write ACK interrupt */
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_ACK_FLAG);
        MCAL_FAULT_INJECTION_POINT(ZIPWIRE_CHECK_STREAM_FAULT_INJECTION);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, TRUE);

        /* Enable write and streaming requests */
        hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, TRUE);
        hwAccZipwireSipi_SetChannelStreamingWriteRequest(pxSipiChannelBase, TRUE);
        /* Write address register with dummy value to trigger the transfer */
        hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, 0U);

        /* Wait for the write request to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while ((!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks)) && (ChannelState->SyncSemaphore == 0U))
        {
        }

        if (ElapsedTime >= TimeoutTicks)
        {
            StreamWriteStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
            ChannelState->IsBlocking = FALSE;
            /* In case of Timeout, disable HwChannel logic, so no ACK is considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelStreamingWriteRequest(pxSipiChannelBase, FALSE);
            hwAccZipwireSipi_SetChannelWriteRequest(pxSipiChannelBase, FALSE);
            /* Update HwChannel status */
            ChannelState->ChannelStatus = StreamWriteStatus;
        }
        else
        {
            StreamWriteStatus = ChannelState->ChannelStatus;
            ChannelState->SyncSemaphore = 0U;
        }
    }

    return StreamWriteStatus;
}


/**
 * @brief         This function performs an ID request transfer.
 *
 * @implements    Zipwire_Ip_RequestId_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_RequestId(uint8 HwInstance, 
                                           uint8 HwChannel, 
                                           uint32 *Id)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_StatusType RequestIdStatus = ChannelState->ChannelStatus;

    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(Id != NULL_PTR);

    /* Check if channel is busy with another transfer */
    if (RequestIdStatus == ZIPWIRE_IP_STATUS_BUSY)
    {
        RequestIdStatus = ZIPWIRE_IP_STATUS_BUSY;
    }
    else
    {
        /* Transfer setup */
        ChannelState->IdRequest = TRUE;
        ChannelState->RemainingTransfers = 0U;
        ChannelState->TargetId = Id;
        /* Channel becomes busy now */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

        /* Enable ID request */
        hwAccZipwireSipi_SetChannelIdTransferRequest(pxSipiChannelBase, TRUE);
        /* Enable read answer interrupt */
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_READ_ANSWER_FLAG);
        MCAL_FAULT_INJECTION_POINT(ZIPWIRE_CHECK_REQUEST_ID_FAULT_INJECTION);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, TRUE);

        /* Set the target address - dummy value to trigger the transfer */
        hwAccZipwireSipi_SetChannelAddr(pxSipiChannelBase, 0U);

        /* Wait for the ID request to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while ((!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks)) && (ChannelState->SyncSemaphore == 0U))
        {
        }

        if (ElapsedTime >= TimeoutTicks)
        {
            RequestIdStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
            ChannelState->IsBlocking = FALSE;
            /* In case of Timeout, disable HwChannel logic, so no ACK is considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_READ_ANSWER_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelIdTransferRequest(pxSipiChannelBase, FALSE);
            /* Update HwChannel status */
            ChannelState->ChannelStatus = RequestIdStatus;
        }
        else
        {
            RequestIdStatus = ChannelState->ChannelStatus;
            ChannelState->SyncSemaphore = 0U;
        }
    }

    return RequestIdStatus;
}


/**
 * @brief         This function sends a trigger command to the target.
 * @implements    Zipwire_Ip_Trigger_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_Trigger(uint8 HwInstance, 
                                         uint8 HwChannel)
{
    Zipwire_Ip_ChannelState * ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];
    Zipwire_Ip_SIPI_Channel_Type * pxSipiChannelBase = s_ZipwireSipiChannels[HwInstance][HwChannel];
    Zipwire_Ip_StatusType TriggerStatus = ChannelState->ChannelStatus;

    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    /* Check if channel is busy with another transfer */
    if (TriggerStatus == ZIPWIRE_IP_STATUS_BUSY)
    {
        TriggerStatus = ZIPWIRE_IP_STATUS_BUSY;
    }
    else
    {
        /* Transfer setup */
        ChannelState->IsBlocking = TRUE;
        ChannelState->RemainingTransfers = 0U;
        ChannelState->IdRequest = FALSE;
        /* Channel becomes busy now */
        ChannelState->ChannelStatus = ZIPWIRE_IP_STATUS_BUSY;

        /* Enable read answer interrupt */
        hwAccZipwireSipi_ClearChannelFlag(pxSipiChannelBase, SIPI_ACK_FLAG);
        MCAL_FAULT_INJECTION_POINT(ZIPWIRE_CHECK_TRIGGER_FAULT_INJECTION);
        hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, TRUE);

        /* Send ID request */
        hwAccZipwireSipi_SetChannelTriggerCommand(pxSipiChannelBase, TRUE);

        /* Wait for the ID request to be serviced */
        uint32 StartTime, ElapsedTime, TimeoutTicks;
        Zipwire_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ZIPWIRE_IP_TIMEOUT_COUNTER);
        while ((!Zipwire_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks)) && (ChannelState->SyncSemaphore == 0U))
        {
        }

        if (ElapsedTime >= TimeoutTicks)
        {
            TriggerStatus = ZIPWIRE_IP_STATUS_TIMEOUT;
            ChannelState->IsBlocking = FALSE;
            /* In case of Timeout, disable HwChannel logic, so no ACK is considered beyond this point */
            hwAccZipwireSipi_SetChannelInterrupt(pxSipiChannelBase, SIPI_ACK_IRQ, FALSE);
            hwAccZipwireSipi_SetChannelTriggerCommand(pxSipiChannelBase, FALSE);
            /* Update HwChannel status */
            ChannelState->ChannelStatus = TriggerStatus;
        }
        else
        {
            TriggerStatus = ChannelState->ChannelStatus;
            ChannelState->SyncSemaphore = 0U;
        }
    }

    return TriggerStatus;
}


/**
 * @brief         This function returns the current channel status.
 * @implements    Zipwire_Ip_GetChannelStatus_Activity
 */
Zipwire_Ip_StatusType Zipwire_Ip_GetChannelStatus(uint8 HwInstance, 
                                                  uint8 HwChannel)
{
    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    return s_axLogicChannelState[HwInstance][HwChannel].ChannelStatus;
}

/**
 * @brief         This function installs a global Callback for the driver.
 * @implements    Zipwire_Ip_InstallGlobalCallback_Activity
 */
Zipwire_Ip_Callback Zipwire_Ip_InstallGlobalCallback(uint8 HwInstance,
                                                     Zipwire_Ip_Callback CallbackFunction,
                                                     void * CallbackParam)
{
    Zipwire_Ip_InstanceState * InstanceState;

    InstanceState = &s_axLogicInstanceState[HwInstance];

    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);

    /* Save the previous callback and set the new one */
    Zipwire_Ip_Callback CurrentCallback = InstanceState->Callback;
    InstanceState->Callback = CallbackFunction;
    InstanceState->CallbackParam = CallbackParam;

    return CurrentCallback;
}


/**
 * @brief         This function installs a callback for a zipwire channel
 * @implements    Zipwire_Ip_InstallChannelCallback_Activity
 */
Zipwire_Ip_ChannelCallback Zipwire_Ip_InstallChannelCallback(uint8 HwInstance,
                                                             uint8 HwChannel,
                                                             Zipwire_Ip_ChannelCallback CallbackFunction,
                                                             void * CallbackParam)
{
    Zipwire_Ip_ChannelState * ChannelState;

    ChannelState = &s_axLogicChannelState[HwInstance][HwChannel];

    ZIPWIRE_IP_DEV_ASSERT(HwInstance < ZIPWIRE_IP_INSTANCE_COUNT_U8);
    ZIPWIRE_IP_DEV_ASSERT(HwChannel < ZIPWIRE_IP_CHANNEL_COUNT_U8);

    /* Save the previous callback and set the new one */
    Zipwire_Ip_ChannelCallback CurrentCallback = ChannelState->Callback;
    ChannelState->Callback = CallbackFunction;
    ChannelState->CallbackParam = CallbackParam;

    return CurrentCallback;
}

#define ZIPWIRE_STOP_SEC_CODE
#include "Zipwire_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
