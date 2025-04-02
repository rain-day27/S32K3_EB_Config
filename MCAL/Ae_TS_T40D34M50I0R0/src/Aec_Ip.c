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
*   @file Aec_Ip.c
*
*   @addtogroup AEC_DRIVER AEC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Aec_Ip.h"
#include "Aec_Ip_Hw_Access.h"
#include "Mcal.h"
#include "Lpspi_Ip.h"
#if(STD_ON == AEC_IP_USE_NMI_INTERRUPT)
#include "IntCtrl_Ip.h"
#endif
#include "SchM_Ae.h"

#if (STD_ON == AEC_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == AEC_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                              SOURCE FILE VERSION InfoRMATION
==================================================================================================*/
#define AEC_IP_VENDOR_ID_C                      43
#define AEC_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define AEC_IP_AR_RELEASE_MINOR_VERSION_C       7
#define AEC_IP_AR_RELEASE_REVISION_VERSION_C    0
#define AEC_IP_SW_MAJOR_VERSION_C               5
#define AEC_IP_SW_MINOR_VERSION_C               0
#define AEC_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Aec_Ip.h */
#if (AEC_IP_VENDOR_ID_C !=  AEC_IP_VENDOR_ID)
    #error "Aec_Ip.c and Aec_Ip.h have different vendor ids"
#endif
#if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  AEC_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_MINOR_VERSION_C    !=  AEC_IP_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_REVISION_VERSION_C !=  AEC_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip.c and Aec_Ip.h are different"
#endif
#if (( AEC_IP_SW_MAJOR_VERSION_C !=  AEC_IP_SW_MAJOR_VERSION) || \
     ( AEC_IP_SW_MINOR_VERSION_C !=  AEC_IP_SW_MINOR_VERSION) || \
     ( AEC_IP_SW_PATCH_VERSION_C !=  AEC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip.c and Aec_Ip.h are different"
#endif

/* Checks against Aec_Ip_Hw_Access.h */
#if (AEC_IP_VENDOR_ID_C !=  AEC_IP_HW_ACCESS_VENDOR_ID)
    #error "Aec_Ip.c and Aec_Ip_Hw_Access.h have different vendor ids"
#endif
#if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  AEC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_MINOR_VERSION_C    !=  AEC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( AEC_IP_AR_RELEASE_REVISION_VERSION_C !=  AEC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip.c and Aec_Ip_Hw_Access.h are different"
#endif
#if (( AEC_IP_SW_MAJOR_VERSION_C !=  AEC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     ( AEC_IP_SW_MINOR_VERSION_C !=  AEC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     ( AEC_IP_SW_PATCH_VERSION_C !=  AEC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip.c and Aec_Ip_Hw_Access.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Devassert.h*/
    #if (STD_ON == AEC_IP_DEV_ERROR_DETECT)
        #if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            ( AEC_IP_AR_RELEASE_MINOR_VERSION_C     !=  DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Aec_Ip.c and Devassert.h are different"
        #endif
    #endif
    /* Checks against Lpspi_Ip.h*/
    #if (( AEC_IP_AR_RELEASE_MAJOR_VERSION_C    !=  LPSPI_IP_AR_RELEASE_MAJOR_VERSION) || \
        ( AEC_IP_AR_RELEASE_MINOR_VERSION_C     !=  LPSPI_IP_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip.c and Lpspi_Ip.h are different"
    #endif
    /* Checks against SchM_Ae.h */
#if ((AEC_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_AE_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_AE_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Aec_Ip.c and SchM_Ae.h are different"
#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (AEC_IP_DEV_ERROR_DETECT == STD_ON)
    #define AEC_DEV_ASSERT(x)      DevAssert(x)
#else
    #define AEC_DEV_ASSERT(x)
#endif

#define AEC_SPI_FRAME_HEADER                16U
#define AEC_SPI_FRAME_TAIL                  8U
#define AEC_NUMOF_BITS_IN_BYTE              8U
#define AEC_NUMOF_BYTES_IN_64BITS           8U
#define AEC_FRAME_COUNT_MAX                 128U

#define AEC_DATAWIDTH_16                        (16U)

#define AEC_EVENT_STATUS_ADDR               ((uint32)(&IP_AEC_AE->EVENTS_STATUS))
#define AEC_FAULT_STATUS_ADDR               ((uint32)(&IP_AEC_AE->FAULTS_STATUS))

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_VAR_CLEARED_32
#include "Ae_MemMap.h"

static uint32 Aec_Ip_u32GlobalHealth;

static uint32 Aec_Ip_u32FrameCounter;

#define AE_STOP_SEC_VAR_CLEARED_32
#include "Ae_MemMap.h"

#define AE_START_SEC_VAR_CLEARED_BOOLEAN

static boolean Aec_Ip_bRawBitEn;

#define AE_STOP_SEC_VAR_CLEARED_BOOLEAN


#define AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
/**
* @brief          Pointers to the configuration structures.
* @details        Used to store the configuration pointers for later use.
*/

const Aec_Ip_ConfigType *Aec_apxInternalCfg;

#define AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define AE_START_SEC_CODE
#include "Ae_MemMap.h"

static Aec_Ip_StatusType Aec_Ip_SpiTransfer(const Aec_Ip_SpiConfigType *SpiConfig,
                                            uint8 DataWidth,
                                            uint32 *SentWords,
                                            uint32 *RcevWords
                                            );
static uint16 Aec_Ip_Parity16(uint16 Value);
static Aec_Ip_StatusType Aec_Ip_WaitForAsyncTransmitEnd(uint8 Instance,
                                                        uint32 Timeout
                                                        );
static void Aec_Ip_Spi_Align_TxWords(uint8 N8bWords,
                                     uint32 *InpWordArray
                                     );
static void Aec_Ip_Spi_Align_RxWords(uint8 N8bWords,
                                    uint32 *InpWordArray
                                    );
static void Aec_Ip_SpiReadPayLoad(const uint32 *InData,
                                  uint8 DataWidth,
                                  uint32 *DataPayload
                                  );
static uint8 Aec_Ip_Spi_Cpu_Crc(uint8 N8bWords,
                                uint32 *InpWordArray
                                );
static void Aec_Ip_Spi_CreateSendFrame (boolean IsRead,
                                        uint8 DataWidth,
                                        boolean RawEn,
                                        uint32 RegAddr,
                                        uint32 *SentData
                                        );
static Aec_Ip_StatusType Aec_Ip_Spi_Status_Handle(boolean IsRead,
                                                  uint32 *RcevWords,
                                                  uint8 DataWidth
                                                  );

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Parity16
 * Description   : Calculate Parity field.
 *
 *END**************************************************************************/
static uint16 Aec_Ip_Parity16(uint16 Value)
{
    uint16 ParVal;

    ParVal = Value ^ (Value >> 1U);
    ParVal = ParVal ^ (ParVal >> 2U);
    ParVal = ParVal ^ (ParVal >> 4U);
    ParVal = ParVal ^ (ParVal >> 8U);

    return ParVal & 1U;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_WaitForAsyncTransmitEnd
 * Description   : Checks if the SPI transfer has ended
 *
 *END**************************************************************************/
static Aec_Ip_StatusType Aec_Ip_WaitForAsyncTransmitEnd(uint8 Instance,
                                                        uint32 Timeout
                                                        )
{
    Aec_Ip_StatusType Status = (Aec_Ip_StatusType)AEC_STATUS_TIMEOUT;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    Aec_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, Timeout);

    /* Read the sequence result until the timeout expire or it is SPI_SEQ_OK or SPI_SEQ_FAILED */
    do
    {
        Lpspi_Ip_ManageBuffers(Instance);
        if (LPSPI_IP_IDLE == Lpspi_Ip_GetStatus(Instance))
        {
            Status = (Aec_Ip_StatusType)AEC_STATUS_SUCCESS;
            break;
        }
    } while (!Aec_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Align_TxWords
 * Description   : Align number of bytes to fit payload.
 *
 *END**************************************************************************/
static void Aec_Ip_Spi_Align_TxWords(uint8 N8bWords,
                                    uint32 *InpWordArray
                                    )
{
    if (N8bWords > 4U)
    {
        InpWordArray[1U] >>= (8U * (4U - (N8bWords - 4U)));
    }
    else
    {
        InpWordArray[0U] >>= (8U * (4U - (N8bWords)));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Align_RxWords
 * Description   : Align number of bytes to fit payload.
 *
 *END**************************************************************************/
static void Aec_Ip_Spi_Align_RxWords(uint8 N8bWords,
                                    uint32 *InpWordArray
                                    )
{
    if (N8bWords > 4U)
    {
        InpWordArray[1U] <<= (8U * (4U - (N8bWords - 4U)));
    }
    else
    {
        InpWordArray[0U] <<= (8U * (4U - (N8bWords)));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_SpiReadPayLoad
 * Description   : Value from indexed register.
 *
 *END**************************************************************************/
static void Aec_Ip_SpiReadPayLoad(const uint32 *InData,
                                  uint8 DataWidth,
                                  uint32 *DataPayload
                                  )
{
    if (8U == DataWidth)
    {
        *DataPayload = (InData[0U] & 0x0000FF00U) >> 8U;
    }
    else if (16U == DataWidth)
    {
        *DataPayload = (InData[0U] & 0x0000FFFFU) >> 0U;
    }
    else
    {
        *DataPayload = (((InData[0U] & 0x0000FFFFU) << 16U) | ((InData[1U] & 0xFFFF0000U) >> 16U));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Cpu_Crc
 * Description   : Calculate CRC field.
 *
 *END**************************************************************************/
static uint8 Aec_Ip_Spi_Cpu_Crc(uint8 N8bWords,
                                 uint32 *InpWordArray
                                )
{
    uint8 Lpspi_crc = 0x3FU;
    uint8 Idx;

    for (Idx = 47U; Idx >= 16U; Idx--)
    {
        if (Idx >= (48U - (8U * N8bWords)))
        {
            if (1U == ((((uint32)Lpspi_crc >> 5U) & 0x01U) ^ ((InpWordArray[0U] >> (Idx - 16U)) & 0x01U)))
            {
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU) ^ 0x03U;
            }
            else
            {
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU);
            }
        }
    }

    for (Idx = 16U; Idx > 0U; Idx--)
    {
        if ((Idx - 1U) >= (48U - (8U * N8bWords)))
        {
            if (1U == ((((uint32)Lpspi_crc >> 5U) & 0x01U) ^ ((InpWordArray[1U] >> ((Idx -1U) + 16U)) & 0x01U)))
            {
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU) ^ 0x03U;
            }
            else
            {
                Lpspi_crc = ((Lpspi_crc << 1U) & 0x3FU);
            }
        }
    }

    return Lpspi_crc;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_CreateSendFrame
 * Description   : Create frame with header fileds.
 *
 *END**************************************************************************/
static void Aec_Ip_Spi_CreateSendFrame (boolean IsRead,
                                        uint8 DataWidth,
                                        boolean RawEn,
                                        uint32 RegAddr,
                                        uint32 *SentData
                                        )
{
    uint32 CodedAddr11b = 0U;
    uint32 Rwn = 1U;
    uint32 Parity, Raw;
    uint32 SentCRC;
    uint32 RawPar;

    switch (DataWidth)
    {
        case  8U:
            {
                CodedAddr11b = (((((uint32) (RegAddr))&(~0x00U)) | 0x00U)<<1U) | (0U);
                break;
            }
        case 16U:
            {
                CodedAddr11b = (((((uint32) (RegAddr))&(~0x01U)) | 0x00U)<<1U) | (1U);
                break;
            }
        case 32U:
            {
                CodedAddr11b = (((((uint32) (RegAddr))&(~0x03U)) | 0x01U)<<1U) | (1U);
                break;
            }
        default:
            {
                CodedAddr11b = 0U;
                break;
            }
    }

    SentData[0U]  |= ((uint32)0x0U << 29U) | (CodedAddr11b << 18U);

    Raw = (((boolean)TRUE == RawEn)? 1U : 0U);
    if (FALSE == IsRead)
    {
        RawPar = Raw;
    }
    else
    {
        SentData[0U] |= (Rwn << 31U);
        Parity = (uint32)(Aec_Ip_Parity16((uint16)(SentData[0U] >> 16U)));
        RawPar = Parity;
    }

    SentData[0U] |= (RawPar << 17U);

    if (DataWidth == 8U)
    {
        SentCRC=Aec_Ip_Spi_Cpu_Crc((16U + DataWidth) / 8U, SentData);
        SentData[0U] = SentData[0U] | ((SentCRC << 2U) << 0U);
        SentData[1U] = 0U;
    }
    else if (DataWidth == 16U)
    {
        SentData[1U] = 0U;
        SentCRC=Aec_Ip_Spi_Cpu_Crc((16U + DataWidth) / 8U, SentData);
        SentData[1U] = SentData[1U] | ((SentCRC << 2U) << 24U);
    }
    else
    {
        SentCRC=Aec_Ip_Spi_Cpu_Crc((16U + DataWidth) / 8U, SentData);
        SentData[1U] = SentData[1U] | ((SentCRC << 2U) << 8U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_Spi_Status_Handle
 * Description   : Read status after each transmit/receive a frame.
 *
 *END**************************************************************************/
static Aec_Ip_StatusType Aec_Ip_Spi_Status_Handle(boolean IsRead,
                                                uint32 *RcevWords,
                                                uint8 DataWidth
                                                )
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;
    uint32 RecvCRC, CmpCRC, RecvACK;
    uint8 TempDataSize;
#if(STD_ON == AEC_GHS_FAULT_HANDLER)
    uint8 IsrPrio;
    uint32 GHSFault;
#endif

    TempDataSize = ((FALSE == IsRead) ? ((uint8)0U) : ((uint8)DataWidth));

    Aec_Ip_u32GlobalHealth = ((RcevWords[0U] & 0xFFFF0000U) >> 16U);

    if (8U == DataWidth)
    {

        CmpCRC = Aec_Ip_Spi_Cpu_Crc((16U + TempDataSize) / 8U, RcevWords);
        RecvCRC = ((RcevWords[0U] & 0x000000FCU) >> 2U);
        RecvACK = ((RcevWords[0U] & 0x00000003U) >> 0U);
    }
    else if (16U == DataWidth)
    {
        CmpCRC = Aec_Ip_Spi_Cpu_Crc((16U + TempDataSize) / 8U, RcevWords);
        RecvCRC = ((RcevWords[1U] & 0xFC000000U) >> 26U);
        RecvACK = ((RcevWords[1U] & 0x03000000U) >> 24U);
    }
    else
    {
        CmpCRC = Aec_Ip_Spi_Cpu_Crc((16U + TempDataSize) / 8U, RcevWords);
        RecvCRC = ((RcevWords[1U] & 0x0000FC00U) >> 10U);
        RecvACK = ((RcevWords[1U] & 0x00000300U) >> 8U);
    }

    if ((RecvACK != 1U) && ((Aec_Ip_u32GlobalHealth & 0x01U) == 0U))
    {
        Status = AEC_STATUS_ERROR;
    }

    if (RecvCRC != CmpCRC)
    {
        Status = AEC_STATUS_ERROR;
    }

#if(STD_ON == AEC_GHS_FAULT_HANDLER)
    if(AEC_STATUS_ERROR != Status)
    {
        GHSFault = Aec_Ip_u32GlobalHealth;
        if(Aec_Ip_u32FrameCounter != (uint8)(((uint16)Aec_Ip_u32GlobalHealth & AEC_SPI_FRAME_COUNT_MASK) >> AEC_SPI_FRAME_COUNT_SHIFT))
        {
            GHSFault &= (AEC_STATUS_CLOCK_MISS | AEC_STATUS_WRONG_ANSWER | AEC_STATUS_FSM_STATUS);
            GHSFault |= ((uint32)AEC_STATUS_FRAME_COUNT);
        }
        else
        {
            GHSFault &= (AEC_STATUS_CLOCK_MISS | AEC_STATUS_WRONG_ANSWER | AEC_STATUS_FSM_STATUS);
        }
        if((0 != GHSFault) && (0!= Aec_GHSRouteConfig.AecGHSFaults))
        {
            /* Fault will be handled from low to high */
            for (IsrPrio = 0U; IsrPrio < AEC_GHS_NUM_MAX; IsrPrio++)
            {
                if (IsrPrio == Aec_GHSRouteConfig.aIntConfig[IsrPrio].Priority)
                {
                    if ((0U != (GHSFault & Aec_GHSRouteConfig.aIntConfig[IsrPrio].Mask)) && (NULL_PTR != Aec_GHSRouteConfig.aIntConfig[IsrPrio].pfHandler))
                    {
                        Aec_GHSRouteConfig.aIntConfig[IsrPrio].pfHandler();
                    }
                    if(0!= (GHSFault & AEC_STATUS_FRAME_COUNT))
                    {
                        Aec_Ip_u32FrameCounter = (uint8)(((uint16)Aec_Ip_u32GlobalHealth & AEC_SPI_FRAME_COUNT_MASK) >> AEC_SPI_FRAME_COUNT_SHIFT);
                    }
                }
            }
        }
    }

#if defined(AEC_IP_GHS_PROCESSING_CALLOUT)
    AEC_IP_GHS_PROCESSING_CALLOUT();
#endif

#endif
    Aec_Ip_u32FrameCounter++;
    if (AEC_FRAME_COUNT_MAX == Aec_Ip_u32FrameCounter)
    {
        Aec_Ip_u32FrameCounter = 1;
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Aec_Ip_SpiTransfer
 * Description   : Tranfer data
 *
 *END**************************************************************************/
static Aec_Ip_StatusType Aec_Ip_SpiTransfer(const Aec_Ip_SpiConfigType *SpiConfig,
                                            uint8 DataWidth,
                                            uint32 *SentWords,
                                            uint32 *RcevWords
                                            )
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;
    Lpspi_Ip_StatusType SpiStatus = LPSPI_IP_STATUS_SUCCESS;
    Lpspi_Ip_HwStatusType SpiHwStatus;
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice = (const Lpspi_Ip_ExternalDeviceType *)SpiConfig->Extension;
    uint8 FrameSize;
    uint16 N8bWords = (AEC_SPI_FRAME_HEADER + (uint16)DataWidth + AEC_SPI_FRAME_TAIL) / AEC_NUMOF_BITS_IN_BYTE;

    FrameSize = DataWidth + AEC_SPI_FRAME_HEADER + AEC_SPI_FRAME_TAIL;
    if (ExternalDevice->DeviceParams->FrameSize != FrameSize)
    {
        SpiHwStatus = Lpspi_Ip_GetStatus(ExternalDevice->Instance);
        /* Frame size can be changed when no transfers are in progress. */
        if (SpiHwStatus != LPSPI_IP_BUSY)
        {
            ExternalDevice->DeviceParams->FrameSize = FrameSize;
        }
        else
        {
            Status = AEC_STATUS_ERROR;
        }
    }
    if ((boolean)TRUE == ExternalDevice->DeviceParams->Lsb)
    {
        (void)Lpspi_Ip_UpdateLsb(ExternalDevice, FALSE);
    }
#if (STD_ON == AEC_IP_SPI_BYTESWAP_SUPPORT)
    if ((boolean)TRUE == ExternalDevice->DeviceParams->ByteSwap)
    {
        (void)Lpspi_Ip_UpdateByteSwap(ExternalDevice, FALSE);
    }
#endif
    /* Deal with LPSPI driver when input parameter checked */
    if ((N8bWords % 4U) > 0U)
    {
        N8bWords = AEC_NUMOF_BYTES_IN_64BITS;
    }
    if (FALSE == SpiConfig->SyncTransmit)
    {
        (void)Lpspi_Ip_UpdateTransferMode(ExternalDevice->Instance, LPSPI_IP_POLLING);

        SpiStatus = Lpspi_Ip_AsyncTransmit(ExternalDevice,
                                           (uint8 *)SentWords,
                                           (uint8 *)RcevWords,
                                           N8bWords,
                                           NULL_PTR);
        if ((AEC_STATUS_SUCCESS != Aec_Ip_WaitForAsyncTransmitEnd(ExternalDevice->Instance, AEC_TIMEOUT_VALUE_US)) || (LPSPI_IP_STATUS_SUCCESS != SpiStatus))
        {
            Status = AEC_STATUS_ERROR;
        }
    }
    else
    {

        SpiStatus = Lpspi_Ip_SyncTransmit(ExternalDevice,
                                          (uint8 *)SentWords,
                                          (uint8 *)RcevWords,
                                          N8bWords,
                                          SpiConfig->Timeout);

        if(LPSPI_IP_STATUS_SUCCESS != SpiStatus)
        {
            Status = AEC_STATUS_ERROR;
        }
    }
    return Status;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief         Initializes the Aec Driver
 * @details       The configuration pointer is internally stored and
 *                the driver is initialized.
 *
 * @param         AecConfig Pointer to configuration structure.
 *
 * @return        AEC_STATUS_SUCCESS if initialized successful.
 *                AEC_STATUS_TIMEOUT if initialized failed.
 *
 * @implements Aec_Ip_Init_Activity
 */
Aec_Ip_StatusType  Aec_Ip_Init(const Aec_Ip_ConfigType *AecConfig)
{
    Aec_Ip_StatusType Status = AEC_STATUS_SUCCESS;

    AEC_DEV_ASSERT(AecConfig           != NULL_PTR);

    Aec_apxInternalCfg = AecConfig;

    uint32 RegVerId;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;

    Aec_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, AEC_TIMEOUT_VALUE_US);

    /* Wait for the AE boot to be completed... */
    do
    {    /* this updates global variable Aec_Ip_u32GlobalHealth */
        (void)Aec_Ip_SpiRead((uint32)&IP_AEC_AE->VERID, 32U, &RegVerId);
        TimeoutOccurred = Aec_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    } while (((Aec_Ip_u32GlobalHealth & 0x01U) == 1U) && (FALSE == TimeoutOccurred));

    if (TRUE == TimeoutOccurred)
    {
        /* Report timeout error */
        Status = AEC_STATUS_TIMEOUT;
    }
    else
    {
        /* Set up to enable for events/faults to raise interrupt_out */
        Status = Aec_EventsFaultsEnable();
    }

    return Status;
}

/**
 * @brief Enable/Disable read after write.
 */
void Aec_Ip_SetRaw(boolean Activate)
{
    if (Activate)
    {
        Aec_Ip_bRawBitEn = (boolean)TRUE;
    }
    else
    {
        Aec_Ip_bRawBitEn = (boolean)FALSE;
    }
}

/**
 * @brief Read Value return from indexed register by Register address through SPI
 *
 * @param[in] RegAddr Register address want to read from.
 * @param[in] DataWidth Size of register in AEC that want to read/write.
 * @param[out] Data Value want to read from indexed register.
 * @return Status of transmission
 * @implements Aec_Ip_SpiRead_Activity
 */
Aec_Ip_StatusType Aec_Ip_SpiRead (uint32 RegAddr,
                                  uint8 DataWidth,
                                  uint32 *Data
                                  )
{
    Aec_Ip_StatusType Status;
    uint32 SentWords[2U] = {0U};
    uint32 RcevWords[2U] = {0U};
    uint8 N8bWords = (16U + DataWidth + 8U) / 8U;

    AEC_DEV_ASSERT(Aec_apxInternalCfg           != NULL_PTR);
    AEC_DEV_ASSERT(Aec_apxInternalCfg->AeSpiConfig           != NULL_PTR);
    AEC_DEV_ASSERT((DataWidth == 8U) || (DataWidth == 16U) || (DataWidth== 32U));
    AEC_DEV_ASSERT(RegAddr < 1024U);
    AEC_DEV_ASSERT(Data != NULL_PTR);

    Aec_Ip_Spi_CreateSendFrame(TRUE, DataWidth, (boolean)FALSE, RegAddr, SentWords);
    Aec_Ip_Spi_Align_TxWords(N8bWords, SentWords);

    SchM_Enter_Ae_AE_EXCLUSIVE_AREA_00();
    Status = Aec_Ip_SpiTransfer(Aec_apxInternalCfg->AeSpiConfig, DataWidth, SentWords, RcevWords);

    if (AEC_STATUS_SUCCESS == Status)
    {
        Aec_Ip_Spi_Align_RxWords(N8bWords, RcevWords);

        Status = Aec_Ip_Spi_Status_Handle(TRUE, RcevWords, DataWidth);

        if (AEC_STATUS_SUCCESS == Status)
        {
            Aec_Ip_SpiReadPayLoad(RcevWords, DataWidth, Data);
        }
    }
    SchM_Exit_Ae_AE_EXCLUSIVE_AREA_00();
    return Status;
}

/**
 * @brief Write Value to indexed register by Register address through SPI
 *
 * @param[in] RegAddr Register address want to write to.
 * @param[in] DataWidth Size of register in AEC that want to read/write.
 * @param[in] Data Value want to write to indexed register.
 * @return Status of transmission
 * @implements Aec_Ip_SpiWrite_Activity
 */
Aec_Ip_StatusType Aec_Ip_SpiWrite (uint32 RegAddr,
                                   uint8 DataWidth,
                                   uint32 Data
                                  )
{
    Aec_Ip_StatusType Status;
    uint32 SentWords[2U] = {0U};
    uint32 RcevWords[2U] = {0U};
    uint8 N8bWords = (16U + DataWidth + 8U) / 8U;

    AEC_DEV_ASSERT(Aec_apxInternalCfg           != NULL_PTR);
    AEC_DEV_ASSERT(Aec_apxInternalCfg->AeSpiConfig           != NULL_PTR);
    AEC_DEV_ASSERT((DataWidth == 8U) || (DataWidth == 16U) || (DataWidth == 32U));
    AEC_DEV_ASSERT(RegAddr < 1024U);

    if (8U == DataWidth)
    {
        SentWords[0U] = ((Data & 0x00FFU) << 8U);
    }
    else if (16U == DataWidth)
    {
        SentWords[0U] = ((Data & 0xFFFFU) << 0U);
    }
    else
    {
        SentWords[0U] = ((Data & 0xFFFFFFFFU) >> 16U);
        SentWords[1U] = ((Data & 0x0000FFFFU) << 16U);
    }

    Aec_Ip_Spi_CreateSendFrame(FALSE, DataWidth, Aec_Ip_bRawBitEn, RegAddr, SentWords);

    Aec_Ip_Spi_Align_TxWords(N8bWords, SentWords);

    SchM_Enter_Ae_AE_EXCLUSIVE_AREA_00();
    Status = Aec_Ip_SpiTransfer(Aec_apxInternalCfg->AeSpiConfig, DataWidth, SentWords, RcevWords);

    if (AEC_STATUS_SUCCESS == Status)
    {
        Aec_Ip_Spi_Align_RxWords(N8bWords, RcevWords);
        Status = Aec_Ip_Spi_Status_Handle(FALSE, RcevWords, DataWidth);
    }
    SchM_Exit_Ae_AE_EXCLUSIVE_AREA_00();
    return Status;
}

/**
 * @brief Return status of global health.
 * @implements  Aec_Ip_DecodeGlobalHealthStatus_Activity
 */
uint16 Aec_Ip_DecodeGlobalHealthStatus(void)
{
    uint16 RetVal = 0U;
    uint8 Index;
    uint16 Status;

    Status = ((uint16)Aec_Ip_u32GlobalHealth & AEC_STATUS_GLOBAL_HEALTH_MASK);
    for (Index = 0U; Index < 16U; Index++)
    {
        if (0x0001U == ((Status >> Index) & 0x0001U))
        {
            RetVal |= ((uint16)1U << Index);
        }
    }

    return RetVal;
}

/*!
 * @brief Verify for correctness the received frame counter or just read number of frames.
 *
 * @param[in]     IsVerify want to verify for correctness for frame counter.
 * @param[in]     ExpectedFrameCount Number of frame expected get.
 * @param[out]    ActualFrameCount Number of frame get in real.
 *
 * @return TRUE if verify correct.
 *
 * @implements   Aec_Ip_Spi_Frame_Counter_Activity
 */
boolean Aec_Ip_Spi_Frame_Counter(boolean IsVerify,
                                uint8 ExpectedFrameCount,
                                uint8 *ActualFrameCount
                                )
{
    boolean Status = (boolean)TRUE;

    *ActualFrameCount = (uint8)(((uint16)Aec_Ip_u32GlobalHealth & AEC_SPI_FRAME_COUNT_MASK) >> AEC_SPI_FRAME_COUNT_SHIFT);

    if ((boolean)TRUE == IsVerify)
    {
        if (ExpectedFrameCount != *ActualFrameCount)
        {
            Status = (boolean)FALSE;
        }
    }
    else
    {
        (void)ExpectedFrameCount;
    }

    return Status;
}

#if(STD_ON == AEC_IP_USE_NMI_INTERRUPT)
/**
 * @brief Handle NMI event/faults handler
 *
 */
void Aec_Ip_NMISetupEventFaultHandler(void)
{
    /* Disable NMI*/
#if(defined(AEC_IP_NMI_SPECIFIC_INTERRUPT) && (STD_ON == AEC_IP_NMI_SPECIFIC_INTERRUPT))
    IP_PORTD->PCR[3] = 0x0;
#else
    IP_WKPU->NCR = 0x60000000U;
#endif

    IntCtrl_Ip_SetPending((IRQn_Type)AEC_IP_NMI_SOURCE_INTERRUPT);
}

/**
 * @brief Handle Interrupt Event/Faults
 *
 */
void Aec_Ip_InterruptSetupEventFaultHandler(void)
{
#if(defined(AEC_IP_NMI_SPECIFIC_INTERRUPT) && (STD_OFF == AEC_IP_NMI_SPECIFIC_INTERRUPT))
    uint16 HealthStatus = 0U;
    uint32 RegStatusEventVal = 0U;
    uint32 RegStatusFault = 0U;
#endif

    Aec_IRQEventFaultHandler();

#if(defined(AEC_IP_NMI_SPECIFIC_INTERRUPT) && (STD_ON == AEC_IP_NMI_SPECIFIC_INTERRUPT))
    /* Enable NMI */
    IP_PORTD->PCR[3] = 0x700;
#else
    do
    {
        /* Call read function to get newest value of HealthStatus variable */
        (void)Aec_Ip_SpiRead(AEC_FAULT_STATUS_ADDR, AEC_DATAWIDTH_16, &RegStatusFault);
        HealthStatus = Aec_Ip_DecodeGlobalHealthStatus();
        (void)Aec_Ip_SpiRead(AEC_EVENT_STATUS_ADDR, AEC_DATAWIDTH_16, &RegStatusEventVal);
        HealthStatus |= Aec_Ip_DecodeGlobalHealthStatus();
        HealthStatus &= (AEC_STATUS_EVENT_NOTIFY | AEC_STATUS_FAULT_NOTIFY);
        if (0U != HealthStatus)
        {
            Aec_IRQEventFaultHandler();
        }
    } while (0U != HealthStatus);
    IP_WKPU->NSR =0X80000000U;
    /* Enable NMI*/
    IP_WKPU->NCR =0x6000000U;
#endif
    IntCtrl_Ip_ClearPending((IRQn_Type)AEC_IP_NMI_SOURCE_INTERRUPT);
}
#endif

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
