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
*   @file       Clock_Ip_PBcfg.c
*   @version    5.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Clock_Ip_PBcfg.h"
#include "Std_Types.h"
#include "Clock_Ip.h"
#include "Clock_Ip_Private.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_PBCFG_VENDOR_ID_C                      43
#define CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C               5
#define CLOCK_IP_PBCFG_SW_MINOR_VERSION_C               0
#define CLOCK_IP_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_PBcfg.h file are of the same vendor */
#if (CLOCK_IP_PBCFG_VENDOR_ID_C != CLOCK_IP_PBCFG_VENDOR_ID)
    #error "Clock_Ip_PBcfg.c and Clock_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_PBcfg.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_PBcfg.h are different"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_PBcfg.h file are of the same Software version */
#if ((CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C != CLOCK_IP_PBCFG_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_MINOR_VERSION_C != CLOCK_IP_PBCFG_SW_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_PATCH_VERSION_C != CLOCK_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_PBcfg.h are different"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip.h file are of the same vendor */
#if (CLOCK_IP_PBCFG_VENDOR_ID_C != CLOCK_IP_VENDOR_ID)
    #error "Clock_Ip_PBcfg.c and Clock_Ip.h have different vendor ids"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip.h are different"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip.h file are of the same Software version */
#if ((CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C != CLOCK_IP_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_MINOR_VERSION_C != CLOCK_IP_SW_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_PATCH_VERSION_C != CLOCK_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip.h are different"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_PBCFG_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_PBcfg.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_Private.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h file are of the same Autosar version */
    #if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C  != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and Std_Types.h are different"
    #endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/


#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"








static const Clock_Ip_IrcoscConfigType Clock_Ip_IrcoscConfigurations_0[CLOCK_IP_CONFIGURED_IRCOSCS_0_NO] = {

    {
        FIRC_CLK,
        1U,
        0U,
        CLOCK_IP_SUPPORTS_48MHZ_FREQUENCY,
        0U,
        0U,
    },

    {
        FIRC_STANDBY_CLK,
        0U,
        0U,
        0U,
        0U,
        0U,
    },

    {
        SIRC_STANDBY_CLK,
        0U,
        0U,
        0U,
        0U,
        0U,
    },

};

static const Clock_Ip_XoscConfigType Clock_Ip_XoscConfigurations_0[CLOCK_IP_CONFIGURED_XOSCS_0_NO] = {

    {
        FXOSC_CLK,                    /* Clock name associated to xosc */
        16000000U,                    /* External oscillator frequency. */
        1U,                           /* Enable xosc. */
        49U,                         /* Startup stabilization time. */
        0U,                           /* XOSC bypass option */
        1U,                           /* Comparator enable */
        12U,                          /* Crystal overdrive protection */
        0U,                     /* Gain value */
        0U,                     /* Monitor type */
        0U,                     /* Automatic level controller */
        0U,                     /* Level Shifter Current */
        0U,                     /* Comparator Current */
    },

    {
        SXOSC_CLK,                    /* Clock name associated to xosc */
        0U,                    /* External oscillator frequency. */
        0U,                           /* Enable xosc. */
        125U,                         /* Startup stabilization time. */
        0U,                           /* XOSC bypass option */
        0U,                           /* Comparator enable */
        0U,                          /* Crystal overdrive protection */
        0U,                     /* Gain value */
        0U,                     /* Monitor type */
        0U,                     /* Automatic level controller */
        0U,                     /* Level Shifter Current */
        0U,                     /* Comparator Current */
    },

};


static const Clock_Ip_PllConfigType Clock_Ip_PllConfigurations_0[CLOCK_IP_CONFIGURED_PLLS_0_NO] = {

    {
        PLL_CLK,                  /*!<     name;                    */
        1U,                           /*!<     enable;                  */
        FXOSC_CLK,                    /*!<     inputReference           */
        0U,                           /*!<     bypass;                  */
        2U,                           /*!<     predivider;              */
        0U,                           /*!<     multiplier;              */
        0U,                           /*!<     postdivider;              */
        0U,                           /*!<     numeratorFracLoopDiv;    */
        120U,                          /*!<     mulFactorDiv;            */
        1U,                           /*!<     ModulationBypass;              */
        1U,                           /*!<     modulationType;          */
        0U,                           /*!<     modulationPeriod;        */
        1U,                           /*!<     incrementStep;           */
        0U,                           /*!<     sigmaDelta;              */
        0U,                           /*!<     ditherControl;           */
        0U,                           /*!<     ditherControlValue;      */
        0U,                           /*!<     Monitor type */
        {                             /*!<     Dividers */
                0U,
                0U,
                0U,
        },
        0U,                     /* SoftwareDisable */
    },

};



static const Clock_Ip_SelectorConfigType Clock_Ip_SelectorConfigurations_0[CLOCK_IP_CONFIGURED_SELECTORS_0_NO] = {


    {
        SCS_CLK,                     /* Clock name associated to selector */
        PLL_PHI0_CLK,                       /* Name of the selected input source */
    },
        
    {
        STMA_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        FLEXCANA_CLK,                     /* Clock name associated to selector */
        AIPS_PLAT_CLK,                       /* Name of the selected input source */
    },
        
    {
        FLEXCANB_CLK,                     /* Clock name associated to selector */
        AIPS_PLAT_CLK,                       /* Name of the selected input source */
    },
        
    {
        CLKOUT_STANDBY_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        CLKOUT_RUN_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        EMAC_RX_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        EMAC_TX_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        EMAC_TS_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        QSPI_SFCK_CLK,                     /* Clock name associated to selector */
        PLL_PHI1_CLK,                       /* Name of the selected input source */
    },
        
    {
        RTC_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        TRACE_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
};

static const Clock_Ip_DividerConfigType Clock_Ip_DividerConfigurations_0[CLOCK_IP_CONFIGURED_DIVIDERS_0_NO] = {
    {
        PLL_POSTDIV_CLK,
        2U,
        {
            0U,
        }
    },

    {
        PLL_PHI0_CLK,
        3U,
        {
            0U,
        }
    },

    {
        PLL_PHI1_CLK,
        3U,
        {
            0U,
        }
    },

    {
        CORE_CLK,
        1U,
        {
            0U,
        }
    },

    {
        AIPS_PLAT_CLK,
        2U,
        {
            0U,
        }
    },

    {
        AIPS_SLOW_CLK,
        4U,
        {
            0U,
        }
    },

    {
        HSE_CLK,
        2U,
        {
            0U,
        }
    },

    {
        DCM_CLK,
        4U,
        {
            0U,
        }
    },

    {
        LBIST_CLK,
        4U,
        {
            0U,
        }
    },

    {
        QSPI_MEM_CLK,
        1U,
        {
            0U,
        }
    },

    {
        STMA_CLK,
        0U,
        {
            0U,
        }
    },

    {
        FLEXCANA_CLK,
        1U,
        {
            0U,
        }
    },

    {
        FLEXCANB_CLK,
        1U,
        {
            0U,
        }
    },

    {
        CLKOUT_STANDBY_CLK,
        2U,
        {
            0U,
        }
    },

    {
        CLKOUT_RUN_CLK,
        2U,
        {
            0U,
        }
    },

    {
        EMAC_RX_CLK,
        0U,
        {
            0U,
        }
    },

    {
        EMAC_TX_CLK,
        0U,
        {
            0U,
        }
    },

    {
        EMAC_TS_CLK,
        0U,
        {
            0U,
        }
    },

    {
        QSPI_SFCK_CLK,
        2U,
        {
            0U,
        }
    },

    {
        TRACE_CLK,
        1U,
        {
            0U,
        }
    },

};


static const Clock_Ip_DividerTriggerConfigType Clock_Ip_DividerTriggerConfigurations_0[CLOCK_IP_CONFIGURED_DIVIDER_TRIGGERS_0_NO] = {

    {
        CORE_CLK,                     /* divider name */
        COMMON_TRIGGER_DIVIDER_UPDATE,      /* trigger value */
        CORE_CLK,                     /* input source name */
    },
};

static const Clock_Ip_ExtClkConfigType Clock_Ip_ExtClkConfigurations_0[CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO] = {

    {
        EMAC_MII_RX_CLK,
        25000000U,
    },
    {
        EMAC_MII_RMII_TX_CLK,
        50000000U,
    },
};

static const Clock_Ip_CmuConfigType Clock_Ip_CmuConfigurations_0[CLOCK_IP_CONFIGURED_CMUS_0_NO] = {

    {
        FXOSC_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_0_FXOSC_CLK */
        (                                           /* IER for CMU_FC_0_FXOSC_CLK */
        CMU_FC_IER_FLLIE(0U) |
        CMU_FC_IER_FHHIE(0U) |
        CMU_FC_IER_FLLAIE(0U) |
        CMU_FC_IER_FHHAIE(0U)
        ),
        16000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    {
        CORE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_3_CORE_CLK */
        (                                           /* IER for CMU_FC_3_CORE_CLK */
        CMU_FC_IER_FLLIE(0U) |
        CMU_FC_IER_FHHIE(0U) |
        CMU_FC_IER_FLLAIE(0U) |
        CMU_FC_IER_FHHAIE(0U)
        ),
        160000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    {
        AIPS_PLAT_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_4_AIPS_PLAT_CLK */
        (                                           /* IER for CMU_FC_4_AIPS_PLAT_CLK */
        CMU_FC_IER_FLLIE(0U) |
        CMU_FC_IER_FHHIE(0U) |
        CMU_FC_IER_FLLAIE(0U) |
        CMU_FC_IER_FHHAIE(0U)
        ),
        80000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
};

static const Clock_Ip_ConfiguredFrequencyType Clock_Ip_ConfiguredFrequencyConfigurations_0[CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT] = {

    {
        CLOCK_IS_OFF,
        0U,
    },
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 1U
    {
        FIRC_CLK,
        48000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 2U
    {
        FXOSC_CLK,
        16000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 3U
    {
        CORE_CLK,
        160000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 4U
    {
        AIPS_PLAT_CLK,
        80000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 5U
    {
        AIPS_SLOW_CLK,
        40000000U,
    },
    #endif
};

static const Clock_Ip_IrcoscConfigType Clock_Ip_IrcoscConfigurations_1[CLOCK_IP_CONFIGURED_IRCOSCS_1_NO] = {

    {
        FIRC_CLK,
        1U,
        0U,
        CLOCK_IP_SUPPORTS_48MHZ_FREQUENCY,
        0U,
        0U,
    },

    {
        FIRC_STANDBY_CLK,
        0U,
        0U,
        0U,
        0U,
        0U,
    },

    {
        SIRC_STANDBY_CLK,
        0U,
        0U,
        0U,
        0U,
        0U,
    },

};

static const Clock_Ip_XoscConfigType Clock_Ip_XoscConfigurations_1[CLOCK_IP_CONFIGURED_XOSCS_1_NO] = {

    {
        FXOSC_CLK,                    /* Clock name associated to xosc */
        16000000U,                    /* External oscillator frequency. */
        1U,                           /* Enable xosc. */
        49U,                         /* Startup stabilization time. */
        0U,                           /* XOSC bypass option */
        1U,                           /* Comparator enable */
        12U,                          /* Crystal overdrive protection */
        0U,                     /* Gain value */
        0U,                     /* Monitor type */
        0U,                     /* Automatic level controller */
        0U,                     /* Level Shifter Current */
        0U,                     /* Comparator Current */
    },

    {
        SXOSC_CLK,                    /* Clock name associated to xosc */
        0U,                    /* External oscillator frequency. */
        0U,                           /* Enable xosc. */
        125U,                         /* Startup stabilization time. */
        0U,                           /* XOSC bypass option */
        0U,                           /* Comparator enable */
        0U,                          /* Crystal overdrive protection */
        0U,                     /* Gain value */
        0U,                     /* Monitor type */
        0U,                     /* Automatic level controller */
        0U,                     /* Level Shifter Current */
        0U,                     /* Comparator Current */
    },

};


static const Clock_Ip_PllConfigType Clock_Ip_PllConfigurations_1[CLOCK_IP_CONFIGURED_PLLS_1_NO] = {

    {
        PLL_CLK,                  /*!<     name;                    */
        0U,                           /*!<     enable;                  */
        FXOSC_CLK,                    /*!<     inputReference           */
        0U,                           /*!<     bypass;                  */
        2U,                           /*!<     predivider;              */
        0U,                           /*!<     multiplier;              */
        0U,                           /*!<     postdivider;              */
        0U,                           /*!<     numeratorFracLoopDiv;    */
        120U,                          /*!<     mulFactorDiv;            */
        1U,                           /*!<     ModulationBypass;              */
        1U,                           /*!<     modulationType;          */
        0U,                           /*!<     modulationPeriod;        */
        1U,                           /*!<     incrementStep;           */
        0U,                           /*!<     sigmaDelta;              */
        0U,                           /*!<     ditherControl;           */
        0U,                           /*!<     ditherControlValue;      */
        0U,                           /*!<     Monitor type */
        {                             /*!<     Dividers */
                0U,
                0U,
                0U,
        },
        0U,                     /* SoftwareDisable */
    },

};



static const Clock_Ip_SelectorConfigType Clock_Ip_SelectorConfigurations_1[CLOCK_IP_CONFIGURED_SELECTORS_1_NO] = {


    {
        SCS_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        STMA_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        FLEXCANA_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        FLEXCANB_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        CLKOUT_STANDBY_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        CLKOUT_RUN_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        EMAC_RX_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        EMAC_TX_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        EMAC_TS_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        QSPI_SFCK_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        RTC_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
    {
        TRACE_CLK,                     /* Clock name associated to selector */
        FIRC_CLK,                       /* Name of the selected input source */
    },
        
};

static const Clock_Ip_DividerConfigType Clock_Ip_DividerConfigurations_1[CLOCK_IP_CONFIGURED_DIVIDERS_1_NO] = {
    {
        PLL_POSTDIV_CLK,
        2U,
        {
            0U,
        }
    },

    {
        PLL_PHI0_CLK,
        0U,
        {
            0U,
        }
    },

    {
        PLL_PHI1_CLK,
        0U,
        {
            0U,
        }
    },

    {
        CORE_CLK,
        1U,
        {
            0U,
        }
    },

    {
        AIPS_PLAT_CLK,
        1U,
        {
            0U,
        }
    },

    {
        AIPS_SLOW_CLK,
        2U,
        {
            0U,
        }
    },

    {
        HSE_CLK,
        1U,
        {
            0U,
        }
    },

    {
        DCM_CLK,
        1U,
        {
            0U,
        }
    },

    {
        LBIST_CLK,
        4U,
        {
            0U,
        }
    },

    {
        QSPI_MEM_CLK,
        1U,
        {
            0U,
        }
    },

    {
        STMA_CLK,
        0U,
        {
            0U,
        }
    },

    {
        FLEXCANA_CLK,
        0U,
        {
            0U,
        }
    },

    {
        FLEXCANB_CLK,
        0U,
        {
            0U,
        }
    },

    {
        CLKOUT_STANDBY_CLK,
        2U,
        {
            0U,
        }
    },

    {
        CLKOUT_RUN_CLK,
        2U,
        {
            0U,
        }
    },

    {
        EMAC_RX_CLK,
        0U,
        {
            0U,
        }
    },

    {
        EMAC_TX_CLK,
        0U,
        {
            0U,
        }
    },

    {
        EMAC_TS_CLK,
        0U,
        {
            0U,
        }
    },

    {
        QSPI_SFCK_CLK,
        0U,
        {
            0U,
        }
    },

    {
        TRACE_CLK,
        1U,
        {
            0U,
        }
    },

};


static const Clock_Ip_DividerTriggerConfigType Clock_Ip_DividerTriggerConfigurations_1[CLOCK_IP_CONFIGURED_DIVIDER_TRIGGERS_1_NO] = {

    {
        CORE_CLK,                     /* divider name */
        COMMON_TRIGGER_DIVIDER_UPDATE,      /* trigger value */
        CORE_CLK,                     /* input source name */
    },
};

static const Clock_Ip_ExtClkConfigType Clock_Ip_ExtClkConfigurations_1[CLOCK_IP_CONFIGURED_EXT_CLKS_1_NO] = {

    {
        EMAC_MII_RX_CLK,
        25000000U,
    },
    {
        EMAC_MII_RMII_TX_CLK,
        50000000U,
    },
};

static const Clock_Ip_CmuConfigType Clock_Ip_CmuConfigurations_1[CLOCK_IP_CONFIGURED_CMUS_1_NO] = {

    {
        FXOSC_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_0_FXOSC_CLK */
        (                                           /* IER for CMU_FC_0_FXOSC_CLK */
        CMU_FC_IER_FLLIE(0U) |
        CMU_FC_IER_FHHIE(0U) |
        CMU_FC_IER_FLLAIE(0U) |
        CMU_FC_IER_FHHAIE(0U)
        ),
        16000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    {
        CORE_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_3_CORE_CLK */
        (                                           /* IER for CMU_FC_3_CORE_CLK */
        CMU_FC_IER_FLLIE(0U) |
        CMU_FC_IER_FHHIE(0U) |
        CMU_FC_IER_FLLAIE(0U) |
        CMU_FC_IER_FHHAIE(0U)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
    {
        AIPS_PLAT_CLK,            /* Clock name associated to clock monitor. */
        0U,                   /*Enable/disable clock monitor CMU_FC_4_AIPS_PLAT_CLK */
        (                                           /* IER for CMU_FC_4_AIPS_PLAT_CLK */
        CMU_FC_IER_FLLIE(0U) |
        CMU_FC_IER_FHHIE(0U) |
        CMU_FC_IER_FLLAIE(0U) |
        CMU_FC_IER_FHHAIE(0U)
        ),
        48000000U,
        {
            0U,          /* Start index in register values array */
            0U,          /* End index in register values array */
        },
    },
};

static const Clock_Ip_ConfiguredFrequencyType Clock_Ip_ConfiguredFrequencyConfigurations_1[CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT] = {

    {
        CLOCK_IS_OFF,
        0U,
    },
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 1U
    {
        FIRC_CLK,
        48000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 2U
    {
        FXOSC_CLK,
        16000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 3U
    {
        CORE_CLK,
        48000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 4U
    {
        AIPS_PLAT_CLK,
        48000000U,
    },
    #endif
    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 5U
    {
        AIPS_SLOW_CLK,
        24000000U,
    },
    #endif
};


/* *************************************************************************
 * Configuration structure for Clock Configuration 0
 * ************************************************************************* */
 /*! @brief User Configuration structure clock_Cfg_0 */
const Clock_Ip_ClockConfigType Mcu_aClockConfigPB[2U] = {

    {
        0U,                                 /* clkConfigId */

        (NULL_PTR),                                 /* Register data if register value optimization is enabled */

        3U,                                 /* ircoscsCount */
        2U,                                 /* xoscsCount */
        1U,                                 /* pllsCount */
        12U,                                /* selectorsCount */
        20U,                                /* dividersCount */
        1U,                                 /* dividerTriggersCount */
        0U,                                /* fracDivsCount */
        2U,                                /* extClksCount */
        0U,                                 /* gatesCount */
        0U,                                 /* pcfsCount */
        3U,                                /* cmusCount */
        6U,                                /* configureFrequenciesCount */

        (&Clock_Ip_IrcoscConfigurations_0),                    /* Ircosc configurations */
        (&Clock_Ip_XoscConfigurations_0),                      /* Xosc configurations */
        (&Clock_Ip_PllConfigurations_0),                       /* Pll configurations */
        (&Clock_Ip_SelectorConfigurations_0),                  /* Selectors configurations */
        (&Clock_Ip_DividerConfigurations_0),                   /* dividers configurations */
        (&Clock_Ip_DividerTriggerConfigurations_0),            /* dividerTriggers configurations */
        (NULL_PTR),                                 /* fracDivs configurations */
        (&Clock_Ip_ExtClkConfigurations_0),                    /* extClks configurations */
        (NULL_PTR),                                 /* gates configurations */
        (NULL_PTR),                                 /* pcfs configurations */
        (&Clock_Ip_CmuConfigurations_0),                       /* cmus configurations */
        (&Clock_Ip_ConfiguredFrequencyConfigurations_0),       /* configureFrequencies configurations */
    },

    {
        1U,                                 /* clkConfigId */

        (NULL_PTR),                                 /* Register data if register value optimization is enabled */

        3U,                                 /* ircoscsCount */
        2U,                                 /* xoscsCount */
        1U,                                 /* pllsCount */
        12U,                                /* selectorsCount */
        20U,                                /* dividersCount */
        1U,                                 /* dividerTriggersCount */
        0U,                                /* fracDivsCount */
        2U,                                /* extClksCount */
        0U,                                 /* gatesCount */
        0U,                                 /* pcfsCount */
        3U,                                /* cmusCount */
        6U,                                /* configureFrequenciesCount */

        (&Clock_Ip_IrcoscConfigurations_1),                    /* Ircosc configurations */
        (&Clock_Ip_XoscConfigurations_1),                      /* Xosc configurations */
        (&Clock_Ip_PllConfigurations_1),                       /* Pll configurations */
        (&Clock_Ip_SelectorConfigurations_1),                  /* Selectors configurations */
        (&Clock_Ip_DividerConfigurations_1),                   /* dividers configurations */
        (&Clock_Ip_DividerTriggerConfigurations_1),            /* dividerTriggers configurations */
        (NULL_PTR),                                 /* fracDivs configurations */
        (&Clock_Ip_ExtClkConfigurations_1),                    /* extClks configurations */
        (NULL_PTR),                                 /* gates configurations */
        (NULL_PTR),                                 /* pcfs configurations */
        (&Clock_Ip_CmuConfigurations_1),                       /* cmus configurations */
        (&Clock_Ip_ConfiguredFrequencyConfigurations_1),       /* configureFrequencies configurations */
    },

};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

