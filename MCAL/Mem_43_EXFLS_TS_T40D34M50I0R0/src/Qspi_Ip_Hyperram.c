/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
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
*   @file Qspi_Ip_Hyperram.c
*
*   @addtogroup IPV_QSPI
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "OsIf.h"
#include "Qspi_Ip.h"
#include "Qspi_Ip_Common.h"
#include "Qspi_Ip_Controller.h"
#include "Qspi_Ip_Hyperram.h"
#include "Qspi_Ip_HyperramRegs.h"


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HYPERRAM_VENDOR_ID_C                    43
#define QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C     4
#define QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C     7
#define QSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C  0
#define QSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C             5
#define QSPI_IP_HYPERRAM_SW_MINOR_VERSION_C             0
#define QSPI_IP_HYPERRAM_SW_PATCH_VERSION_C             0

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Hyperram.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Qspi_Ip header file are of the same vendor */
#if (QSPI_IP_HYPERRAM_VENDOR_ID_C != QSPI_IP_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperram.c and Qspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip header file are of the same Autosar version */
#if ((QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip.h are different"
#endif
/* Check if current file and Qspi_Ip header file are of the same Software version */
#if ((QSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != QSPI_IP_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != QSPI_IP_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != QSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip.h are different"
#endif

/* Check if current file and Qspi_Ip_Common header file are of the same vendor */
#if (QSPI_IP_HYPERRAM_VENDOR_ID_C != QSPI_IP_COMMON_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperram.c and Qspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Common header file are of the same Autosar version */
#if ((QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_Common.h are different"
#endif
/* Check if current file and Qspi_Ip_Common header file are of the same Software version */
#if ((QSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != QSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != QSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != QSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_Common.h are different"
#endif

/* Check if current file and Qspi_Ip_Controller header file are of the same vendor */
#if (QSPI_IP_HYPERRAM_VENDOR_ID_C != QSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperram.c and Qspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Autosar version */
#if ((QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_Controller.h are different"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Software version */
#if ((QSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_Controller.h are different"
#endif

/* Check if current file and Qspi_Ip_Hyperram header file are of the same vendor */
#if (QSPI_IP_HYPERRAM_VENDOR_ID_C != QSPI_IP_HYPERRAM_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperram.c and Qspi_Ip_Hyperram.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Hyperram header file are of the same Autosar version */
#if ((QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_Hyperram.h are different"
#endif
/* Check if current file and Qspi_Ip_Hyperram header file are of the same Software version */
#if ((QSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != QSPI_IP_HYPERRAM_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != QSPI_IP_HYPERRAM_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != QSPI_IP_HYPERRAM_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_Hyperram.h are different"
#endif

/* Check if current file and Qspi_Ip_Hyperram header file are of the same vendor */
#if (QSPI_IP_HYPERRAM_VENDOR_ID_C != QSPI_IP_HYPERRAMREGS_VENDOR_ID_H)
    #error "Qspi_Ip_Hyperram.c and Qspi_Ip_HyperramRegs.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_HyperramRegs header file are of the same Autosar version */
#if ((QSPI_IP_HYPERRAM_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_HYPERRAMREGS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_HYPERRAMREGS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_HYPERRAMREGS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_HyperramRegs.h are different"
#endif
/* Check if current file and Qspi_Ip_HyperramRegs header file are of the same Software version */
#if ((QSPI_IP_HYPERRAM_SW_MAJOR_VERSION_C != QSPI_IP_HYPERRAMREGS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_MINOR_VERSION_C != QSPI_IP_HYPERRAMREGS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_HYPERRAM_SW_PATCH_VERSION_C != QSPI_IP_HYPERRAMREGS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperram.c and Qspi_Ip_HyperramRegs.h are different"
#endif

 /*******************************************************************************
 * Variables
 ******************************************************************************/

/* HyperFlash commands */
/* Read command with continuous burst type */
#define QSPI_IP_HR_READ           0xA0
/* Write command with continuous burst type */
#define QSPI_IP_HR_WRITE          0x20
/* READ reg command with continuous burst type */
#define QSPI_IP_HR_READ_REG       0xE0
/* Write reg command with continuous burst type */
#define QSPI_IP_HR_WRITE_REG      0x60


#define MEM_43_EXFLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/* Hyperflash virtual LUT */
Qspi_Ip_InstrOpType Qspi_Ip_HyperRamLutTable[QSPI_IP_HR_LUT_SIZE] =
{
    /* 0: QSPI_IP_HR_LUT_READ: Read command */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HR_READ),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)16U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY     | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),  /* dummy cycles to be patched in before use*/
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_READ_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x20),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 6: QSPI_IP_HR_LUT_WRITE: write command */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HR_WRITE),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)16U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY     | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x00),  /* dummy cycles to be patched in before use*/
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_WRITE_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x20),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 12: QSPI_IP_HR_LUT_READ_REG: Read register */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HR_READ_REG),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)16U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY     | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x4),  /* dummy cycles to be patched in before use*/
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_READ_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x2),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP),
    /* 18: QSPI_IP_HR_LUT_WRITE_REG: Write to register  */
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CMD_DDR   | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)QSPI_IP_HR_WRITE_REG),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_ADDR_DDR  | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)24U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_CADDR_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)16U),
    (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_WRITE_DDR | (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 | (Qspi_Ip_InstrOpType)0x2),
    (Qspi_Ip_InstrOpType)(QSPI_IP_LUT_INSTR_STOP)
};

#define MEM_43_EXFLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"


/*******************************************************************************
 * Functions
 ******************************************************************************/

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperramWriteConfigurationRegister
 * Description   : Write configuration registers
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperRamWriteConfigurationRegister(uint32 instance, uint32 RegAddress, const uint16 *data )
{
    Qspi_Ip_StatusType status;

    /* Run QSPI command */
    status = Qspi_Ip_RunWriteCommand(instance, QSPI_IP_HR_LUT_WRITE_REG, RegAddress, (const uint8 *)data, 2U);

    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperramReadConfigurationRegister
 * Description   : Read configuration registers
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperRamReadConfigurationRegister(uint32 instance, uint32 RegAddress, uint16 *data )
{
    Qspi_Ip_StatusType status;
    /* Run QSPI command */
    status = Qspi_Ip_RunReadCommand(instance, QSPI_IP_HR_LUT_READ_REG, RegAddress, (uint8 *)data, NULL_PTR, 2U);

    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperRamInitConfigurationRegister
 * Description   : Sets up configuration registers
 *
 *END**************************************************************************/
static Qspi_Ip_StatusType Qspi_Ip_HyperRamInitConfigurationRegister(uint32 instance)
{
    const Qspi_Ip_StateType * state = &(Qspi_Ip_MemoryStateStructure[instance]);
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint16 regWriteValue = 0U;
    uint16 regReadValue = 0U;

    const Qspi_Ip_HyperRamConfigType *hrConfig = state->configuration->hrConfig;

    /*Calculate the value to write to register configuartion 0*/
    regWriteValue = (QSPI_IP_HR_CR0_DEFAULT_VALUE) | QSPI_IP_HR_CR0_DRIVE_STRENGTH(hrConfig->driveStrength) | QSPI_IP_HR_CR0_INITIAL_LATENCY(hrConfig->initialLatency);

    /*Write to register configuartion 0*/
    status = Qspi_Ip_HyperRamWriteConfigurationRegister(instance, QSPI_IP_HR_REGCFG0_ADDR, &regWriteValue);

    if(STATUS_QSPI_IP_SUCCESS == status)
    {
        status = Qspi_Ip_HyperRamReadConfigurationRegister(instance, QSPI_IP_HR_REGCFG0_ADDR, &regReadValue);
        if ( (status == STATUS_QSPI_IP_SUCCESS) && (regReadValue != regWriteValue) )
        {
            status = STATUS_QSPI_IP_ERROR;
        }
    }

    if(STATUS_QSPI_IP_SUCCESS == status)
    {
        /*Calculate the value to write to register configuartion 1*/
        regWriteValue = (QSPI_IP_HR_CR1_DEFAULT_VALUE) | QSPI_IP_HR_CR1_MASTER_CLOCK_TYPE(hrConfig->masterClockType) | QSPI_IP_HR_CR1_PARTIAL_REFRESH(hrConfig->arrayRefresh);

        /*Write to register configuartion 1*/
        status = Qspi_Ip_HyperRamWriteConfigurationRegister(instance, QSPI_IP_HR_REGCFG1_ADDR, &regWriteValue);
        if(STATUS_QSPI_IP_SUCCESS == status)
        {
            status = Qspi_Ip_HyperRamReadConfigurationRegister(instance, QSPI_IP_HR_REGCFG1_ADDR, &regReadValue);
            if ( (status == STATUS_QSPI_IP_SUCCESS) && (regReadValue != regWriteValue) )
            {
                status = STATUS_QSPI_IP_ERROR;
            }
        }
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperRamInit
 * Description   : Initializes the hyper ram memory
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperRamInit(uint32 instance)
{
    Qspi_Ip_StatusType status;
    const Qspi_Ip_StateType *state = &Qspi_Ip_MemoryStateStructure[instance];
    uint8 dummyCycles;

    /* Set up Volatile and Non-Volatile Configuration Registers */
    status = Qspi_Ip_HyperRamInitConfigurationRegister(instance);
    if(STATUS_QSPI_IP_SUCCESS == status)
    {
        /*dummyCycles = initialLatency*2 - 1*/
        switch (state->configuration->hrConfig->initialLatency)
        {
            case QSPI_IP_HR_INITIAL_LATENCY_3_CLOCKS:
                dummyCycles = 5U;
                break;
            case QSPI_IP_HR_INITIAL_LATENCY_4_CLOCKS:
                dummyCycles = 7U;
                break;
            case QSPI_IP_HR_INITIAL_LATENCY_5_CLOCKS:
                dummyCycles = 9U;
                break;
            case QSPI_IP_HR_INITIAL_LATENCY_6_CLOCKS:
                dummyCycles = 11U;
                break;
            case QSPI_IP_HR_INITIAL_LATENCY_7_CLOCKS:
                dummyCycles = 13U;
                break;
            default:
                dummyCycles = 13U;
                break;
        }
        /* Patch command - set dummy cycles */
        Qspi_Ip_HyperRamLutTable[QSPI_IP_HR_LUT_READ + 3U]  =   (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY |
                                                                (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 |
                                                                (Qspi_Ip_InstrOpType)dummyCycles);
        /* Patch command - set dummy cycles */
        Qspi_Ip_HyperRamLutTable[QSPI_IP_HR_LUT_WRITE + 3U] =   (Qspi_Ip_InstrOpType)((Qspi_Ip_InstrOpType)QSPI_IP_LUT_INSTR_DUMMY |
                                                                (Qspi_Ip_InstrOpType)QSPI_IP_LUT_PADS_8 |
                                                                (Qspi_Ip_InstrOpType)dummyCycles);
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_HyperRamReadId
 * Description   : Read manufacturer ID from hyper ram.
 *
 *END**************************************************************************/
Qspi_Ip_StatusType Qspi_Ip_HyperRamReadId(uint32 instance,
                                          uint32 wordAddress,
                                          uint8 * data,
                                          uint32 size
                                         )
{
    Qspi_Ip_StatusType status;

    /* Run QSPI command */
    status = Qspi_Ip_RunReadCommand(instance, QSPI_IP_HR_LUT_READ_REG, wordAddress << 1U, (uint8 *)data, NULL_PTR, size);

    return status;
}
#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


#endif /* QSPI_IP_MEM_INSTANCE_COUNT */

#ifdef __cplusplus
}
#endif

/** @} */


