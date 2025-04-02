/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
/*==================================================================================================
==================================================================================================*/
/**
* @file         CanTrcv_43_AE.c
*
* @addtogroup   CANTRCV_43_AE_DRIVER Can Transceiver Driver
* @{
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
#include "CanTrcv_43_AE.h"
#include "CanTrcv_43_AE_Ipw.h"
#include "CanIf_CanTrcv.h"
#include "SchM_CanTrcv_43_AE.h"
#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
#include "EcuM.h"
#endif

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
/* guard including Det.h here because only development errors checked in this file */
#include "Det.h"
#endif

#if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
#include "Mcal.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_VENDOR_ID_C                      43
#define CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C       4
#define CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C       7
#define CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION_C    0
#define CANTRCV_43_AE_SW_MAJOR_VERSION_C               5
#define CANTRCV_43_AE_SW_MINOR_VERSION_C               0
#define CANTRCV_43_AE_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if CanTrcv_43_AE.c and CanTrcv_43_AE.h header file are of the same vendor */
#if (CANTRCV_43_AE_VENDOR_ID_C != CANTRCV_43_AE_VENDOR_ID)
    #error "CanTrcv_43_AE.c and CanTrcv_43_AE.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE.c and CanTrcv_43_AE.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C != CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C != CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE.c and CanTrcv_43_AE.h are different"
#endif

/* Check if CanTrcv_43_AE.c and CanTrcv_43_AE.h header file are of the same software version */
#if ((CANTRCV_43_AE_SW_MAJOR_VERSION_C != CANTRCV_43_AE_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_SW_MINOR_VERSION_C != CANTRCV_43_AE_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_SW_PATCH_VERSION_C != CANTRCV_43_AE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE.c and CanTrcv_43_AE.h are different"
#endif

/* Check if CanTrcv_43_AE.c and CanTrcv_43_AE_Ipw.h header file are of the same vendor */
#if (CANTRCV_43_AE_VENDOR_ID_C != CANTRCV_43_AE_IPW_VENDOR_ID)
    #error "CanTrcv_43_AE.c and CanTrcv_43_AE_Ipw.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE.c and CanTrcv_43_AE_Ipw.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C != CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C != CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE.c and CanTrcv_43_AE_Ipw.h are different"
#endif

/* Check if CanTrcv_43_AE.c and CanTrcv_43_AE_Ipw.h header file are of the same software version */
#if ((CANTRCV_43_AE_SW_MAJOR_VERSION_C != CANTRCV_43_AE_IPW_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_SW_MINOR_VERSION_C != CANTRCV_43_AE_IPW_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_SW_PATCH_VERSION_C != CANTRCV_43_AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE.c and CanTrcv_43_AE_Ipw.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if CanTrcv_43_AE.c and CanIf_CanTrcv.h are of the same software version */
    #if ((CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C != CANIF_CANTRCV_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C != CANIF_CANTRCV_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE.c and CanIf_CanTrcv.h are different"
    #endif

    /* Check if CanTrcv_43_AE.c and SchM_CanTrcv_43_AE.h are of the same software version */
    #if ((CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C != SCHM_CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C != SCHM_CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE.c and SchM_CanTrcv_43_AE.h are different"
    #endif

#if (CANTRCV_43_AE_ECUM_USED == STD_ON)
    /* Check if CanTrcv_43_AE.c and EcuM.h are of the same software version */
    #if ((CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE.c and EcuM.h are different"
    #endif
#endif

#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    /* Check if CanTrcv_43_AE.c and Det.h are of the same software version */
    #if ((CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE.c and Det.h are different"
    #endif
#endif

#if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
    /* Check if current file and Mcal.h header file are of the same version */
    #if ((CANTRCV_43_AE_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (CANTRCV_43_AE_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE.c and Mcal.h are different"
    #endif
#endif

#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
    #define CanTrcv_GetUserId()       ((uint32)OsIf_GetUserId())
#else
    #define CanTrcv_GetUserId()       ((uint32)0UL)
#endif
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

static CanTrcv_TrcvModeType CanTrcv_eTrcvMode[CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT];


static CanTrcv_43_AE_eDriverStatusType CanTrcv_eDriverStatus[CANTRCV_43_AE_MAX_PARTITIONS];


/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by CanTrcv_Init(). */
static const CanTrcv_43_AE_ConfigType * CanTrcv_apxConfig[CANTRCV_43_AE_MAX_PARTITIONS];

#define CANTRCV_43_AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON)
    #define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "CanTrcv_43_AE_MemMap.h"
    #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
        extern const CanTrcv_43_AE_ConfigType * const CanTrcv_43_AE_Config[CANTRCV_43_AE_MAX_PARTITIONS];
    #else
        extern const CanTrcv_43_AE_ConfigType CanTrcv_43_AE_Config;
    #endif
    #define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "CANTRCV_43_AE_MemMap.h"
#endif
/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

/* Validate Tranceiver param */
static boolean CanTrcv_ValidateTransceiverParam(uint32 u32PartitionId,
                                                uint8 Transceiver
                                                #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                                                ,uint8 u8Sid
                                                #endif
                                               );

static boolean CanTrcv_ValidateCallSetOpMode(uint32 u32PartitionId,
                                             uint8 Transceiver,
                                             CanTrcv_TrcvModeType OpMode
                                            );

/* Init all transceivers */
static Std_ReturnType CanTrcv_InitTransceiver(uint32 u32PartitionId);

/* DeInit all transceivers */
static Std_ReturnType CanTrcv_DeInitTransceiver(uint32 u32PartitionId);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Validate Tranceiver param */
static boolean CanTrcv_ValidateTransceiverParam(uint32 u32PartitionId,
                                                uint8 Transceiver
                                                #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                                                ,uint8 u8Sid
                                                #endif
                                               )
{
    boolean bValid;

    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32PartitionId])
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              u8Sid,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        bValid = FALSE;
    }
    else if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                u8Sid,
                                (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        bValid = FALSE;
    }
    else
    {
        bValid = TRUE;
    }

    return bValid;
}

static boolean CanTrcv_ValidateCallSetOpMode(uint32 u32PartitionId,
                                             uint8 Transceiver,
                                             CanTrcv_TrcvModeType OpMode
                                            )
{
    boolean RetVal;

    if (FALSE == CanTrcv_ValidateTransceiverParam(u32PartitionId,
                                                  Transceiver
                                                  #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                                                  ,(uint8)CANTRCV_43_AE_SID_SET_OPMODE
                                                  #endif
                                                 )
       )
    {
        RetVal = FALSE;
    }
    else if ((CANTRCV_TRCVMODE_NORMAL != OpMode) && (CANTRCV_TRCVMODE_STANDBY != OpMode) && (CANTRCV_TRCVMODE_SLEEP   != OpMode))
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                                (uint8)CANTRCV_43_AE_E_PARAM_TRCV_OPMODE);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        RetVal = FALSE;
    }
    else if ((CANTRCV_TRCVMODE_STANDBY == OpMode) && (CANTRCV_TRCVMODE_SLEEP == CanTrcv_eTrcvMode[Transceiver]))
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                            (uint8)CANTRCV_43_AE_INSTANCE,
                            (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                            (uint8)CANTRCV_43_AE_E_TRCV_NOT_NORMAL);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        RetVal = FALSE;
    }
    else if ((CANTRCV_TRCVMODE_SLEEP == OpMode) && (CANTRCV_TRCVMODE_NORMAL == CanTrcv_eTrcvMode[Transceiver]))
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                        (uint8)CANTRCV_43_AE_INSTANCE,
                        (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                        (uint8)CANTRCV_43_AE_E_TRCV_NOT_STANDBY);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        RetVal = FALSE;
    }
    else
    {
        RetVal = TRUE;
    }

    return RetVal;
}

/* Init all transceivers */
static Std_ReturnType CanTrcv_InitTransceiver(uint32 u32PartitionId)
{
    uint8 SwTransceiverId = 0U;
    Std_ReturnType TrcvStat = E_OK;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;
    
    for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
    {
        pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[SwTransceiverId];
        /* Init all controllers asigned to the current core/partition */
        if (NULL_PTR != pTransceiver)
        {
            if ((Std_ReturnType)E_OK != CanTrcv_43_AE_Ipw_Init(pTransceiver))
            {
                TrcvStat = E_NOT_OK;
                break;
            }
            else
            {
                CanTrcv_eTrcvMode[SwTransceiverId] = pTransceiver->CanTrcv_eInitState;
            }
        }
    }

    return TrcvStat;
}

/* DeInit all transceivers */
static Std_ReturnType CanTrcv_DeInitTransceiver(uint32 u32PartitionId)
{
    Std_ReturnType TrcvStat = E_OK;
    uint8 SwTransceiverId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
    {
        pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[SwTransceiverId];
        /* DeInit all controllers asigned to the current core */
        if (NULL_PTR != pTransceiver)
        {
            if ((Std_ReturnType)E_OK != CanTrcv_43_AE_Ipw_DeInit(pTransceiver))
            {
                TrcvStat = E_NOT_OK;
                break;
            }
        }
    }

    return TrcvStat;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*-------------------------Functions which are used only in CanTrcv driver internally--------------*/
CanTrcv_TrcvModeType CanTrcv_43_AE_GetTrcvSwMode(uint8 Transceiver)
{
    return CanTrcv_eTrcvMode[Transceiver];
}
/*-------------------------------------------------------------------------------------------------*/
#if (CANTRCV_43_AE_VERSION_INFO_API == STD_ON)
/**
* @brief        CAN transceiver driver get version info function. SID is 0x04.
* @details      Returns the version information of this module.
*
* @param[out]   versioninfo     Pointer to where to store the version information of this module.
*
* @return       void
*
* @api
*/
/** @implements   CanTrcv_GetVersionInfo_Activity */
void CanTrcv_43_AE_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
    if (NULL_PTR == versioninfo)
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16) CANTRCV_43_AE_MODULE_ID,
                (uint8) CANTRCV_43_AE_INSTANCE,
                (uint8) CANTRCV_43_AE_SID_GET_VERSION_INFO,
                (uint8) CANTRCV_43_AE_E_PARAM_POINTER);
    #endif /* CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        versioninfo->vendorID = (uint16)CANTRCV_43_AE_VENDOR_ID;
        versioninfo->moduleID = (uint16)CANTRCV_43_AE_MODULE_ID;
        versioninfo->sw_major_version = (uint8)CANTRCV_43_AE_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)CANTRCV_43_AE_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)CANTRCV_43_AE_SW_PATCH_VERSION;
    }
}
#endif /* CANTRCV_43_AE_VERSION_INFO_API == STD_ON */

/**
* @brief        Initializes CanTrcv module. SID 0x00.
* @details      Initializes all transceivers configured in ConfigPtr parameter.
*               The CANTRCV module shall be initialized by CanTrcv_43_AE_Init() service call during the
*               start-up.
*
* @param[in]    ConfigPtr       Pointer to driver configuration structure.
*
* @return       void
*
*
* @pre          CanTrcv_43_AE_Init shall be called at most once during runtime.
* @post         CanTrcv_43_AE_Init shall initialize all the transceivers and set the driver in READY state.
*
* @api
*/
/** @implements   CanTrcv_Init_Activity */
void CanTrcv_43_AE_Init(const CanTrcv_43_AE_ConfigType * ConfigPtr)
{
    uint32 u32PartitionId = 0U;
    Std_ReturnType TrcvStat = E_OK;

    u32PartitionId = CanTrcv_GetUserId();

    if (CANTRCV_43_AE_ACTIVE == CanTrcv_eDriverStatus[u32PartitionId])
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        /* Just Init CanTrcv driver when it was being un-init(not_active) */
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_INIT,
                              (uint8)CANTRCV_43_AE_E_INIT_FAILED);
    #endif
    }
    else
    {
    #if (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != ConfigPtr)
    #else
        if (NULL_PTR == ConfigPtr)
    #endif
        {
        #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                  (uint8)CANTRCV_43_AE_INSTANCE,
                                  (uint8)CANTRCV_43_AE_SID_INIT,
                                  (uint8)CANTRCV_43_AE_E_INIT_FAILED);
        #endif
        }
        else
        {
    #if (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON)
        #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
            if (NULL_PTR != CanTrcv_43_AE_Config[u32PartitionId])
            {
                /* Update config pointer with default configuration if precompile support on. */
                CanTrcv_apxConfig[u32PartitionId] = CanTrcv_43_AE_Config[u32PartitionId];
            }
        #else
            /* Update config pointer with default configuration if precompile support on. */
            CanTrcv_apxConfig[u32PartitionId] = &CanTrcv_43_AE_Config;
        #endif
            (void)ConfigPtr; /* Prevent compiler warning */
    #else
        #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
            if (u32PartitionId == ConfigPtr->CanTrcv_u32PartitionId)
            {
        #endif /* (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON) */
                /* Copy pointer to current Can Driver configuration. */
                CanTrcv_apxConfig[u32PartitionId] = ConfigPtr;
        #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
            }
        #endif /* (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON) */
    #endif /* (CANTRCV_43_AE_PRECOMPILE_SUPPORT == STD_ON) */
            if (NULL_PTR != CanTrcv_apxConfig[u32PartitionId])
            {
                TrcvStat = CanTrcv_InitTransceiver(u32PartitionId);
                if ((Std_ReturnType)E_OK == TrcvStat)
                {
                    /* Set driver status to NOT_ACTIVE when all Transceivers init successfully */
                    CanTrcv_eDriverStatus[u32PartitionId] = CANTRCV_43_AE_ACTIVE;
                }
            }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
            else
            {
                (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                      (uint8)CANTRCV_43_AE_INSTANCE,
                                      (uint8)CANTRCV_43_AE_SID_INIT,
                                      (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
            }
        #endif /* (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON) */
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        }
    }
}

/*================================================================================================*/
/**
* @brief        Sets the mode of the Transceiver to the value OpMode. SID 0x01.
* @details      Puts the device in one of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver         Index of the transceiver.
* @param[out]   OpMode              Desired operating mode.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_SetOpMode method.
* @post         CanTrcv_43_AE_SetOpMode shall set the transceiver in the desired state.
*
* @api
*/
/** @implements   CanTrcv_SetOpMode_Activity */
Std_ReturnType CanTrcv_43_AE_SetOpMode(uint8 Transceiver,
                                                     CanTrcv_TrcvModeType OpMode
                                                    )
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32PartitionId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (TRUE == CanTrcv_ValidateCallSetOpMode(u32PartitionId, Transceiver, OpMode))
    {
        if ((NULL_PTR != CanTrcv_apxConfig[u32PartitionId]) && (NULL_PTR != (CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver])))
        {
            pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver];
            eRetVal = CanTrcv_43_AE_Ipw_SetOpMode(pTransceiver, OpMode);

            if ((Std_ReturnType)E_OK == eRetVal)
            {
                CanIf_TrcvModeIndication(pTransceiver->CanTrcv_u8CanIfTransceiverId, OpMode);
                CanTrcv_eTrcvMode[Transceiver] = OpMode;
            }
        }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_SET_OPMODE,
                                (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
        }
    #endif
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }

    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Gets current operation mode. SID 0x02.
* @details      Gets the mode of the Transceiver and returns it in OpMode. The device is in one
*               of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver         CAN transceiver ID.
* @param[out]   OpMode              Current operating mode.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_GetOpMode method.
* @post         CanTrcv_43_AE_GetOpMode shall return the currently working mode of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_GetOpMode_Activity */
Std_ReturnType CanTrcv_43_AE_GetOpMode(uint8 Transceiver,
                                                     CanTrcv_TrcvModeType* OpMode
                                                    )
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32PartitionId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (TRUE == CanTrcv_ValidateTransceiverParam(u32PartitionId,
                                                 Transceiver
                                                #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                                                 ,(uint8)CANTRCV_43_AE_SID_GET_OPMODE
                                                #endif
                                                )
       )
    {
        if (NULL_PTR == OpMode)
        {
        #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                    (uint8)CANTRCV_43_AE_INSTANCE,
                                    (uint8)CANTRCV_43_AE_SID_GET_OPMODE,
                                    (uint8)CANTRCV_43_AE_E_PARAM_POINTER);
        #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if ((NULL_PTR != CanTrcv_apxConfig[u32PartitionId]) && (NULL_PTR != (CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver])))
            {
                pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver];
                eRetVal = CanTrcv_43_AE_Ipw_GetOpMode(pTransceiver, OpMode);
                if ((Std_ReturnType)E_OK == eRetVal)
                {
                    CanTrcv_eTrcvMode[Transceiver] = *OpMode;
                }
            }
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
            else
            {
                (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                        (uint8)CANTRCV_43_AE_INSTANCE,
                                        (uint8)CANTRCV_43_AE_SID_GET_OPMODE,
                                        (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
            }
        #endif
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
        }
    }
    
    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Gets the wakeup reason of the Transceiver and returns it in parameter Reason. SID 0x03.
* @details      The device can be woken up by Wake Up Pattern
*
* @param[in]    Transceiver         CAN transceiver to which API call has to be applied.
* @param[out]   reason              Pointer to wake up reason.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_GetBusWuReason method.
* @post         CanTrcv_43_AE_GetBusWuReason shall return wake up reason.
*
* @api
*/
/** @implements   CanTrcv_GetBusWuReason_Activity */
Std_ReturnType CanTrcv_43_AE_GetBusWuReason(uint8 Transceiver,
                                                          CanTrcv_TrcvWakeupReasonType * reason
                                                         )
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32PartitionId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32PartitionId])
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                               (uint8)CANTRCV_43_AE_INSTANCE,
                               (uint8)CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                               (uint8)CANTRCV_43_AE_E_UNINIT);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                                (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else if (NULL_PTR == reason)
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16) CANTRCV_43_AE_MODULE_ID,
                                (uint8) CANTRCV_43_AE_INSTANCE,
                                (uint8) CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                                (uint8) CANTRCV_43_AE_E_PARAM_POINTER);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if ((NULL_PTR != CanTrcv_apxConfig[u32PartitionId]) && (NULL_PTR != (CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver])))
        {
            pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver];
            eRetVal = CanTrcv_43_AE_Ipw_GetBusWuReason(pTransceiver, reason);
        }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                    (uint8)CANTRCV_43_AE_INSTANCE,
                                    (uint8)CANTRCV_43_AE_SID_GET_BUS_WU_REASON,
                                    (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
        }
    #endif
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }

    return eRetVal;
}

/**
* @brief        Enables, disables or clears wake up events of the Transceiver according to TrcvWakeupMode. SID 0x05.
* @details      Enables, disables or clears wake up functionality. If WU mode is disabled all wake up sources
*               and interrupts are off. If WU mode is enabled, all wake up sources and interrupts are set
*               according to configuration. If WU mode is clear, pending wake up flag is cleared.
*
* @param[in]    Transceiver         CAN Transceiver ID.
* @param[in]    TrcvWakeupMode      Mode of wake up functionality (enabled, disabled, cleared).
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_SetWakeupMode method.
* @post         CanTrcv_43_AE_SetWakeupMode shall return status of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_SetWakeupMode_Activity */
Std_ReturnType CanTrcv_43_AE_SetWakeupMode(uint8 Transceiver,
                                                         CanTrcv_TrcvWakeupModeType TrcvWakeupMode
                                                        )
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32PartitionId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32PartitionId])
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                                (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else if ((CANTRCV_WUMODE_ENABLE != TrcvWakeupMode) && (CANTRCV_WUMODE_DISABLE != TrcvWakeupMode) && (CANTRCV_WUMODE_CLEAR   != TrcvWakeupMode))
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                                (uint8)CANTRCV_43_AE_E_PARAM_TRCV_WAKEUP_MODE);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if ((NULL_PTR != CanTrcv_apxConfig[u32PartitionId]) && (NULL_PTR != (CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver])))
        {
            pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver];
            eRetVal = CanTrcv_43_AE_Ipw_SetWakeupMode(pTransceiver, TrcvWakeupMode);
        }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_SET_WAKEUP_MODE,
                                (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
        }
    #endif
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Service is called by underlying CANIF in case a wake up interrupt is detected. SID 0x07.
* @details      Reads wake up source from the device and  reports it to ECUM.
*
* @param[in]    Transceiver         CAN transceiver ID.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_CheckWakeup method.
* @post         CanTrcv_43_AE_CheckWakeup shall read and report wake up reason.
*
* @api
*/
/** @implements   CanTrcv_CheckWakeup_Activity */
Std_ReturnType CanTrcv_43_AE_CheckWakeup(uint8 Transceiver)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32PartitionId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32PartitionId])
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_CHECK_WAKEUP,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_CHECK_WAKEUP,
                                (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if ((NULL_PTR != CanTrcv_apxConfig[u32PartitionId]) && (NULL_PTR != (CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver])))
        {
            pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver];
            eRetVal = CanTrcv_43_AE_Ipw_CheckWakeup(pTransceiver);
        }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_CHECK_WAKEUP,
                                (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
        }
    #endif
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }

    return eRetVal;
}

/*================================================================================================*/
/**
* @brief        Requests to check the status of the wakeup flag from the transceiver hardware. SID 0x0E.
* @details      Checks wake up event and if WU occurred, reports it.
*
* @param[in]    Transceiver         CAN transceiver ID.
*
* @return       Std_ReturnType      Result of the transition.
* @retval       E_OK                Operation executed successfully.
* @retval       E_NOT_OK            Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_AE_CheckWakeFlag method.
* @post         CanTrcv_43_AE_CheckWakeFlag shall check for wake up event, and if such event occurred, report it.
*
* @api
*/
/** @implements   CanTrcv_CheckWakeFlag_Activity */
Std_ReturnType CanTrcv_43_AE_CheckWakeFlag(uint8 Transceiver)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32PartitionId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32PartitionId])
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_CHECK_WAKE_FLAG,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else if (Transceiver >= CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT)
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_CHECK_WAKE_FLAG,
                                (uint8)CANTRCV_43_AE_E_INVALID_TRANSCEIVER);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if ((NULL_PTR != CanTrcv_apxConfig[u32PartitionId]) && (NULL_PTR != (CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver])))
        {
            pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[Transceiver];
            eRetVal = CanTrcv_43_AE_Ipw_CheckWakeupFlag(pTransceiver);
        }
#if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
    #if (CANTRCV_43_AE_MULTIPARTITION_ENABLED == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                (uint8)CANTRCV_43_AE_INSTANCE,
                                (uint8)CANTRCV_43_AE_SID_CHECK_WAKE_FLAG,
                                (uint8)CANTRCV_43_AE_E_PARAM_CONFIG);
        }
    #endif
#endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    return eRetVal;
}

#if (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON)
/*================================================================================================*/
/**
* @brief          Service to scan all busses for wake up events and perform these event. SID 0x06.
* @details        Scan transceivers for wake up event and reports such event.
*
* @param[in]      None
*
* @return         void
*
*
* @pre
* @post
*
* @api
*/
/** @implements     CanTrcv_MainFunction_Activity */
void CanTrcv_43_AE_MainFunction(void)
{
    uint32 u32PartitionId = 0U;
    uint8 SwTransceiverId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (NULL_PTR != CanTrcv_apxConfig[u32PartitionId])
    {
        for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
        {
            pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[SwTransceiverId];
            /* check all controllers asigned to the current core */
            if ((NULL_PTR != pTransceiver) && (TRUE == pTransceiver->CanTrcv_bWakeupByBusUsed))
            {
                if (CanTrcv_eTrcvMode[pTransceiver->CanTrcv_u8SwTransceiverId] != CANTRCV_TRCVMODE_NORMAL)
                {
                    (void)CanTrcv_43_AE_Ipw_CheckWakeup(pTransceiver);
                }
            }
        }
    }
}
#endif /* (CANTRCV_43_AEWAKEUP_MODE_POLLING == STD_ON) */
#if (CANTRCV_43_AE_BUSERR_EN == STD_ON)
/*================================================================================================*/
/**
* @brief          Reads the transceiver diagnostic status periodically and sets product/development accordingly. SID 0x08.
* @details        Reads system error, and reports it if any.
*
* @param[in]      None
*
* @return         void
*
*
* @pre
* @post
*
* @api
*/
/** @implements     CanTrcv_MainFunctionDiagnostics_Activity */
void CanTrcv_43_AE_MainFunctionDiagnostics(void)
{
#if (CANTRCV_43_AE_DEM_USED == STD_ON)
    uint32 u32PartitionId = 0U;
    uint8 SwTransceiverId = 0U;
    const CanTrcv_43_AE_TransceiverConfigType * pTransceiver = NULL_PTR;

    u32PartitionId = CanTrcv_GetUserId();

    if (NULL_PTR != CanTrcv_apxConfig[u32PartitionId])
    {
        for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
        {
            pTransceiver = CanTrcv_apxConfig[u32PartitionId]->CanTrcv_ppTransceivers[SwTransceiverId];
            /* check all controllers asigned to the current core */
            if ((NULL_PTR != pTransceiver) && (0U != pTransceiver->CanTrcv_DemEventId))
            {
                CanTrcv_43_AE_Ipw_CheckBusError(pTransceiver);
            }
        }
    }
#endif /* (CANTRCV_43_AE_DEM_USED == STD_ON) */
}
#endif /* (CANTRCV_43_AE_BUSERR_EN == STD_ON) */
/*================================================================================================*/
/**
* @brief          De-initializes the CanTrcv module. SID 0x10.
* @details        De-initialize all the transceivers.
*                 The CANTRCV module shall be de-initialized by CanTrcv_43_AE_DeInit() service call.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before transceiver de-initalization, the driver must be initialized and the transceivers must not be in Start state.
* @post           CanTrcv_43_AE_DeInit shall de-initialize all the transceivers and set the driver in UNINIT state.
*
* @api
*/
/** @implements     CanTrcv_DeInit_Activity */
void CanTrcv_43_AE_DeInit(void)
{
    uint32 u32PartitionId = 0U;
    uint8 SwTransceiverId = 0U;
    Std_ReturnType TrcvStat = E_OK;

    u32PartitionId = CanTrcv_GetUserId();

    if (CANTRCV_43_AE_NOT_ACTIVE == CanTrcv_eDriverStatus[u32PartitionId])
    {
    #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                              (uint8)CANTRCV_43_AE_INSTANCE,
                              (uint8)CANTRCV_43_AE_SID_DEINIT,
                              (uint8)CANTRCV_43_AE_E_UNINIT);
    #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        for (SwTransceiverId = 0U; SwTransceiverId < CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT; SwTransceiverId++)
        {
            /* if at least one transceiver is not in CANTRCV_TRCVMODE_STANDBY or CANTRCV_TRCVMODE_SLEEP, raise a DET error. */
            if (CANTRCV_TRCVMODE_NORMAL == CanTrcv_eTrcvMode[SwTransceiverId])
            {
            #if (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CANTRCV_43_AE_MODULE_ID,
                                      (uint8)CANTRCV_43_AE_INSTANCE,
                                      (uint8)CANTRCV_43_AE_SID_DEINIT,
                                      (uint8)CANTRCV_43_AE_E_TRCV_NOT_STANDBY);
            #endif /* (CANTRCV_43_AE_DEV_ERROR_DETECT == STD_ON) */
                TrcvStat = E_NOT_OK;
                break;
            }
        }

        if ((Std_ReturnType)E_OK == TrcvStat)
        {
            if (NULL_PTR != CanTrcv_apxConfig[u32PartitionId])
            {
                TrcvStat = CanTrcv_DeInitTransceiver(u32PartitionId);
                if ((Std_ReturnType)E_OK == TrcvStat)
                {
                    /* Set driver status to NOT_ACTIVE when all Transceivers de-init successfully */
                    CanTrcv_eDriverStatus[u32PartitionId] = CANTRCV_43_AE_NOT_ACTIVE;
                    CanTrcv_apxConfig[u32PartitionId] = NULL_PTR;
                }
            }
        }
    }
}

#define CANTRCV_43_AE_STOP_SEC_CODE
#include "CanTrcv_43_AE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
