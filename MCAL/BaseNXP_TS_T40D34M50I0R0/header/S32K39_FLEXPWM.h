/*
** ###################################################################
**     Processor:           S32K39_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K39 RM Rev 3
**     Version:             rev. 2.0, 2024-03-27
**     Build:               b240327
**
**     Abstract:
**         Peripheral Access Layer for S32K39_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**
**     NXP Confidential and Proprietary. This software is owned or controlled
**     by NXP and may only be used strictly in accordance with the applicable
**     license terms. By expressly accepting such terms or by downloading,
**     installing, activating and/or otherwise using the software, you are
**     agreeing that you have read, and that you agree to comply with and are
**     bound by, such license terms. If you do not agree to be bound by the
**     applicable license terms, then you may not retain, install, activate
**     or otherwise use the software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32K39_FLEXPWM.h
 * @version 2.0
 * @date 2024-03-27
 * @brief Peripheral Access Layer for S32K39_FLEXPWM
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K39_FLEXPWM_H_)  /* Check if memory map has not been already included */
#define S32K39_FLEXPWM_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FLEXPWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXPWM_Peripheral_Access_Layer FLEXPWM Peripheral Access Layer
 * @{
 */

/** FLEXPWM - Size of Registers Arrays */
#define FLEXPWM_SM_COUNT                          4u
#define FLEXPWM_FP_COUNT                          1u

/** FLEXPWM - Register Layout Typedef */
typedef struct {
  struct FLEXPWM_SM {                              /* offset: 0x0, array step: 0x60 */
    __I  uint16_t CNT;                               /**< Submodule 0 Counter..Submodule 3 Counter, array offset: 0x0, array step: 0x60 */
    __IO uint16_t INIT;                              /**< Submodule 0 Initial Count..Submodule 3 Initial Count, array offset: 0x2, array step: 0x60 */
    __IO uint16_t CTRL2;                             /**< Submodule 0 Control 2..Submodule 3 Control 2, array offset: 0x4, array step: 0x60 */
    __IO uint16_t CTRL;                              /**< Submodule 0 Control..Submodule 3 Control, array offset: 0x6, array step: 0x60 */
    uint8_t RESERVED_0[2];
    __IO uint16_t VAL0;                              /**< Submodule 0 Value 0..Submodule 3 Value 0, array offset: 0xA, array step: 0x60 */
    __IO uint16_t FRACVAL1;                          /**< Submodule 0 Fractional Value 1..Submodule 3 Fractional Value 1, array offset: 0xC, array step: 0x60 */
    __IO uint16_t VAL1;                              /**< Submodule 0 Value 1..Submodule 3 Value 1, array offset: 0xE, array step: 0x60 */
    __IO uint16_t FRACVAL2;                          /**< Submodule 0 Fractional Value 2..Submodule 3 Fractional Value 2, array offset: 0x10, array step: 0x60 */
    __IO uint16_t VAL2;                              /**< Submodule 0 Value 2..Submodule 3 Value 2, array offset: 0x12, array step: 0x60 */
    __IO uint16_t FRACVAL3;                          /**< Submodule 0 Fractional Value 3..Submodule 3 Fractional Value 3, array offset: 0x14, array step: 0x60 */
    __IO uint16_t VAL3;                              /**< Submodule 0 Value 3..Submodule 3 Value 3, array offset: 0x16, array step: 0x60 */
    __IO uint16_t FRACVAL4;                          /**< Submodule 0 Fractional Value 4..Submodule 3 Fractional Value 4, array offset: 0x18, array step: 0x60 */
    __IO uint16_t VAL4;                              /**< Submodule 0 Value 4..Submodule 3 Value 4, array offset: 0x1A, array step: 0x60 */
    __IO uint16_t FRACVAL5;                          /**< Submodule 0 Fractional Value 5..Submodule 3 Fractional Value 5, array offset: 0x1C, array step: 0x60 */
    __IO uint16_t VAL5;                              /**< Submodule 0 Value 5..Submodule 3 Value 5, array offset: 0x1E, array step: 0x60 */
    __IO uint16_t FRCTRL;                            /**< Submodule 0 Fractional Control..Submodule 3 Fractional Control, array offset: 0x20, array step: 0x60 */
    __IO uint16_t OCTRL;                             /**< Submodule 0 Output Control..Submodule 3 Output Control, array offset: 0x22, array step: 0x60 */
    __IO uint16_t STS;                               /**< Submodule 0 Status..Submodule 3 Status, array offset: 0x24, array step: 0x60 */
    __IO uint16_t INTEN;                             /**< Submodule 0 Interrupt Enable..Submodule 3 Interrupt Enable, array offset: 0x26, array step: 0x60 */
    __IO uint16_t DMAEN;                             /**< Submodule 0 DMA Enable..Submodule 3 DMA Enable, array offset: 0x28, array step: 0x60 */
    __IO uint16_t TCTRL;                             /**< Submodule 0 Output Trigger Control..Submodule 3 Output Trigger Control, array offset: 0x2A, array step: 0x60 */
    __IO uint16_t DISMAP0;                           /**< Submodule 0 Fault Disable Mapping..Submodule 3 Fault Disable Mapping, array offset: 0x2C, array step: 0x60 */
    __IO uint16_t DISMAP1;                           /**< Submodule 0 Fault Disable Mapping..Submodule 3 Fault Disable Mapping, array offset: 0x2E, array step: 0x60 */
    __IO uint16_t DTCNT0;                            /**< Submodule 0 Deadtime Count 0..Submodule 3 Deadtime Count 0, array offset: 0x30, array step: 0x60 */
    __IO uint16_t DTCNT1;                            /**< Submodule 0 Deadtime Count 1..Submodule 3 Deadtime Count 1, array offset: 0x32, array step: 0x60 */
    __IO uint16_t CAPTCTRLA;                         /**< Submodule 0 Capture Control A..Submodule 3 Capture Control A, array offset: 0x34, array step: 0x60 */
    __IO uint16_t CAPTCOMPA;                         /**< Submodule 0 Capture Compare A..Submodule 3 Capture Compare A, array offset: 0x36, array step: 0x60 */
    __IO uint16_t CAPTCTRLB;                         /**< Submodule 0 Capture Control B..Submodule 3 Capture Control B, array offset: 0x38, array step: 0x60 */
    __IO uint16_t CAPTCOMPB;                         /**< Submodule 0 Capture Compare B..Submodule 3 Capture Compare B, array offset: 0x3A, array step: 0x60 */
    __IO uint16_t CAPTCTRLX;                         /**< Submodule 0 Capture Control X..Submodule 3 Capture Control X, array offset: 0x3C, array step: 0x60 */
    __IO uint16_t CAPTCOMPX;                         /**< Submodule 0 Capture Compare X..Submodule 3 Capture Compare X, array offset: 0x3E, array step: 0x60 */
    __I  uint16_t CVAL0;                             /**< Submodule 0 Capture Value 0..Submodule 3 Capture Value 0, array offset: 0x40, array step: 0x60 */
    __I  uint16_t CVAL0CYC;                          /**< Submodule 0 Capture Value 0 Cycle..Submodule 3 Capture Value 0 Cycle, array offset: 0x42, array step: 0x60 */
    __I  uint16_t CVAL1;                             /**< Submodule 0 Capture Value 1..Submodule 3 Capture Value 1, array offset: 0x44, array step: 0x60 */
    __I  uint16_t CVAL1CYC;                          /**< Submodule 0 Capture Value 1 Cycle..Submodule 3 Capture Value 1 Cycle, array offset: 0x46, array step: 0x60 */
    __I  uint16_t CVAL2;                             /**< Submodule 0 Capture Value 2..Submodule 3 Capture Value 2, array offset: 0x48, array step: 0x60 */
    __I  uint16_t CVAL2CYC;                          /**< Submodule 0 Capture Value 2 Cycle..Submodule 3 Capture Value 2 Cycle, array offset: 0x4A, array step: 0x60 */
    __I  uint16_t CVAL3;                             /**< Submodule 0 Capture Value 3..Submodule 3 Capture Value 3, array offset: 0x4C, array step: 0x60 */
    __I  uint16_t CVAL3CYC;                          /**< Submodule 0 Capture Value 3 Cycle..Submodule 3 Capture Value 3 Cycle, array offset: 0x4E, array step: 0x60 */
    __I  uint16_t CVAL4;                             /**< Submodule 0 Capture Value 4..Submodule 3 Capture Value 4, array offset: 0x50, array step: 0x60 */
    __I  uint16_t CVAL4CYC;                          /**< Submodule 0 Capture Value 4 Cycle..Submodule 3 Capture Value 4 Cycle, array offset: 0x52, array step: 0x60 */
    __I  uint16_t CVAL5;                             /**< Submodule 0 Capture Value 5..Submodule 3 Capture Value 5, array offset: 0x54, array step: 0x60 */
    __I  uint16_t CVAL5CYC;                          /**< Submodule 0 Capture Value 5 Cycle..Submodule 3 Capture Value 5 Cycle, array offset: 0x56, array step: 0x60 */
    __IO uint16_t PHASEDLY;                          /**< Submodule 1 Phase Delay..Submodule 3 Phase Delay, array offset: 0x58, array step: 0x60, valid indices: [1-3] */
    uint8_t RESERVED_1[6];
  } SM[FLEXPWM_SM_COUNT];
  __IO uint16_t OUTEN;                             /**< Output Enable, offset: 0x180 */
  __IO uint16_t MASK;                              /**< Mask, offset: 0x182 */
  __IO uint16_t SWCOUT;                            /**< Software Controlled Output, offset: 0x184 */
  __IO uint16_t DTSRCSEL;                          /**< PWM Source Select, offset: 0x186 */
  __IO uint16_t MCTRL;                             /**< Master Control, offset: 0x188 */
  __IO uint16_t MCTRL2;                            /**< Master Control 2, offset: 0x18A */
  struct FLEXPWM_FP {                              /* offset: 0x18C, array step: 0xA */
    __IO uint16_t CTRL;                              /**< Fault Protection 0 Control, array offset: 0x18C, array step: 0xA */
    __IO uint16_t STS;                               /**< Fault Protection 0 Status, array offset: 0x18E, array step: 0xA */
    __IO uint16_t FILT;                              /**< Fault Protection 0 Filter, array offset: 0x190, array step: 0xA */
    __IO uint16_t TST;                               /**< Fault Protection 0 Test, array offset: 0x192, array step: 0xA */
    __IO uint16_t CTRL2;                             /**< Fault Protection 0 Control 2, array offset: 0x194, array step: 0xA */
  } FP[FLEXPWM_FP_COUNT];
  uint8_t RESERVED_0[26];
  __IO uint16_t DLLSR;                             /**< DLL Status, offset: 0x1B0 */
  uint8_t RESERVED_1[6];
  __IO uint16_t SM0_BIST_CTRL;                     /**< Submodule 0 BIST Control, offset: 0x1B8 */
  __IO uint16_t SM0_BIST_CTRL1;                    /**< Submodule 0 BIST Control, offset: 0x1BA */
  __IO uint16_t SM1_BIST_CTRL;                     /**< Submodule 1 BIST Control, offset: 0x1BC */
  __IO uint16_t SM1_BIST_CTRL1;                    /**< Submodule 1 BIST Control, offset: 0x1BE */
  __IO uint16_t SM2_BIST_CTRL;                     /**< Submodule 2 BIST Control, offset: 0x1C0 */
  __IO uint16_t SM2_BIST_CTRL1;                    /**< Submodule 2 BIST Control, offset: 0x1C2 */
  __IO uint16_t SM3_BIST_CTRL;                     /**< Submodule 3 BIST Control, offset: 0x1C4 */
  __IO uint16_t SM3_BIST_CTRL1;                    /**< Submodule 3 BIST Control, offset: 0x1C6 */
  __I  uint16_t SM0_BIST_STATUS;                   /**< Submodule 0 BIST Status, offset: 0x1C8 */
  __I  uint16_t SM0_BIST_STATUS1;                  /**< Submodule 0 BIST Status, offset: 0x1CA */
  __I  uint16_t SM1_BIST_STATUS;                   /**< Submodule 1 BIST Status, offset: 0x1CC */
  __I  uint16_t SM1_BIST_STATUS1;                  /**< Submodule 1 BIST Status, offset: 0x1CE */
  __I  uint16_t SM2_BIST_STATUS;                   /**< Submodule 2 BIST Status, offset: 0x1D0 */
  __I  uint16_t SM2_BIST_STATUS1;                  /**< Submodule 2 BIST Status, offset: 0x1D2 */
  __I  uint16_t SM3_BIST_STATUS;                   /**< Submodule 3 BIST Status, offset: 0x1D4 */
  __I  uint16_t SM3_BIST_STATUS1;                  /**< Submodule 3 BIST Status, offset: 0x1D6 */
} FLEXPWM_Type, *FLEXPWM_MemMapPtr;

/** Number of instances of the FLEXPWM module. */
#define FLEXPWM_INSTANCE_COUNT                   (2u)

/* FLEXPWM - Peripheral instance base addresses */
/** Peripheral EFLEXPWM_0 base address */
#define IP_EFLEXPWM_0_BASE                       (0x406B8000u)
/** Peripheral EFLEXPWM_0 base pointer */
#define IP_EFLEXPWM_0                            ((FLEXPWM_Type *)IP_EFLEXPWM_0_BASE)
/** Peripheral EFLEXPWM_1 base address */
#define IP_EFLEXPWM_1_BASE                       (0x406BC000u)
/** Peripheral EFLEXPWM_1 base pointer */
#define IP_EFLEXPWM_1                            ((FLEXPWM_Type *)IP_EFLEXPWM_1_BASE)
/** Array initializer of FLEXPWM peripheral base addresses */
#define IP_FLEXPWM_BASE_ADDRS                    { IP_EFLEXPWM_0_BASE, IP_EFLEXPWM_1_BASE }
/** Array initializer of FLEXPWM peripheral base pointers */
#define IP_FLEXPWM_BASE_PTRS                     { IP_EFLEXPWM_0, IP_EFLEXPWM_1 }

/* ----------------------------------------------------------------------------
   -- FLEXPWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXPWM_Register_Masks FLEXPWM Register Masks
 * @{
 */

/*! @name CNT - Submodule 0 Counter..Submodule 3 Counter */
/*! @{ */

#define FLEXPWM_CNT_CNT_MASK                     (0xFFFFU)
#define FLEXPWM_CNT_CNT_SHIFT                    (0U)
#define FLEXPWM_CNT_CNT_WIDTH                    (16U)
#define FLEXPWM_CNT_CNT(x)                       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CNT_CNT_SHIFT)) & FLEXPWM_CNT_CNT_MASK)
/*! @} */

/*! @name INIT - Submodule 0 Initial Count..Submodule 3 Initial Count */
/*! @{ */

#define FLEXPWM_INIT_INIT_MASK                   (0xFFFFU)
#define FLEXPWM_INIT_INIT_SHIFT                  (0U)
#define FLEXPWM_INIT_INIT_WIDTH                  (16U)
#define FLEXPWM_INIT_INIT(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INIT_INIT_SHIFT)) & FLEXPWM_INIT_INIT_MASK)
/*! @} */

/*! @name CTRL2 - Submodule 0 Control 2..Submodule 3 Control 2 */
/*! @{ */

#define FLEXPWM_CTRL2_CLK_SEL_MASK               (0x3U)
#define FLEXPWM_CTRL2_CLK_SEL_SHIFT              (0U)
#define FLEXPWM_CTRL2_CLK_SEL_WIDTH              (2U)
#define FLEXPWM_CTRL2_CLK_SEL(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_CLK_SEL_SHIFT)) & FLEXPWM_CTRL2_CLK_SEL_MASK)

#define FLEXPWM_CTRL2_RELOAD_SEL_MASK            (0x4U)
#define FLEXPWM_CTRL2_RELOAD_SEL_SHIFT           (2U)
#define FLEXPWM_CTRL2_RELOAD_SEL_WIDTH           (1U)
#define FLEXPWM_CTRL2_RELOAD_SEL(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_RELOAD_SEL_SHIFT)) & FLEXPWM_CTRL2_RELOAD_SEL_MASK)

#define FLEXPWM_CTRL2_FORCE_SEL_MASK             (0x38U)
#define FLEXPWM_CTRL2_FORCE_SEL_SHIFT            (3U)
#define FLEXPWM_CTRL2_FORCE_SEL_WIDTH            (3U)
#define FLEXPWM_CTRL2_FORCE_SEL(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_FORCE_SEL_SHIFT)) & FLEXPWM_CTRL2_FORCE_SEL_MASK)

#define FLEXPWM_CTRL2_FORCE_MASK                 (0x40U)
#define FLEXPWM_CTRL2_FORCE_SHIFT                (6U)
#define FLEXPWM_CTRL2_FORCE_WIDTH                (1U)
#define FLEXPWM_CTRL2_FORCE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_FORCE_SHIFT)) & FLEXPWM_CTRL2_FORCE_MASK)

#define FLEXPWM_CTRL2_FRCEN_MASK                 (0x80U)
#define FLEXPWM_CTRL2_FRCEN_SHIFT                (7U)
#define FLEXPWM_CTRL2_FRCEN_WIDTH                (1U)
#define FLEXPWM_CTRL2_FRCEN(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_FRCEN_SHIFT)) & FLEXPWM_CTRL2_FRCEN_MASK)

#define FLEXPWM_CTRL2_INIT_SEL_MASK              (0x300U)
#define FLEXPWM_CTRL2_INIT_SEL_SHIFT             (8U)
#define FLEXPWM_CTRL2_INIT_SEL_WIDTH             (2U)
#define FLEXPWM_CTRL2_INIT_SEL(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_INIT_SEL_SHIFT)) & FLEXPWM_CTRL2_INIT_SEL_MASK)

#define FLEXPWM_CTRL2_PWMX_INIT_MASK             (0x400U)
#define FLEXPWM_CTRL2_PWMX_INIT_SHIFT            (10U)
#define FLEXPWM_CTRL2_PWMX_INIT_WIDTH            (1U)
#define FLEXPWM_CTRL2_PWMX_INIT(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_PWMX_INIT_SHIFT)) & FLEXPWM_CTRL2_PWMX_INIT_MASK)

#define FLEXPWM_CTRL2_PWM45_INIT_MASK            (0x800U)
#define FLEXPWM_CTRL2_PWM45_INIT_SHIFT           (11U)
#define FLEXPWM_CTRL2_PWM45_INIT_WIDTH           (1U)
#define FLEXPWM_CTRL2_PWM45_INIT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_PWM45_INIT_SHIFT)) & FLEXPWM_CTRL2_PWM45_INIT_MASK)

#define FLEXPWM_CTRL2_PWM23_INIT_MASK            (0x1000U)
#define FLEXPWM_CTRL2_PWM23_INIT_SHIFT           (12U)
#define FLEXPWM_CTRL2_PWM23_INIT_WIDTH           (1U)
#define FLEXPWM_CTRL2_PWM23_INIT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_PWM23_INIT_SHIFT)) & FLEXPWM_CTRL2_PWM23_INIT_MASK)

#define FLEXPWM_CTRL2_INDEP_MASK                 (0x2000U)
#define FLEXPWM_CTRL2_INDEP_SHIFT                (13U)
#define FLEXPWM_CTRL2_INDEP_WIDTH                (1U)
#define FLEXPWM_CTRL2_INDEP(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_INDEP_SHIFT)) & FLEXPWM_CTRL2_INDEP_MASK)

#define FLEXPWM_CTRL2_WAITEN_MASK                (0x4000U)
#define FLEXPWM_CTRL2_WAITEN_SHIFT               (14U)
#define FLEXPWM_CTRL2_WAITEN_WIDTH               (1U)
#define FLEXPWM_CTRL2_WAITEN(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_WAITEN_SHIFT)) & FLEXPWM_CTRL2_WAITEN_MASK)

#define FLEXPWM_CTRL2_DBGEN_MASK                 (0x8000U)
#define FLEXPWM_CTRL2_DBGEN_SHIFT                (15U)
#define FLEXPWM_CTRL2_DBGEN_WIDTH                (1U)
#define FLEXPWM_CTRL2_DBGEN(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_DBGEN_SHIFT)) & FLEXPWM_CTRL2_DBGEN_MASK)
/*! @} */

/*! @name CTRL - Submodule 0 Control..Submodule 3 Control */
/*! @{ */

#define FLEXPWM_CTRL_DBLEN_MASK                  (0x1U)
#define FLEXPWM_CTRL_DBLEN_SHIFT                 (0U)
#define FLEXPWM_CTRL_DBLEN_WIDTH                 (1U)
#define FLEXPWM_CTRL_DBLEN(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_DBLEN_SHIFT)) & FLEXPWM_CTRL_DBLEN_MASK)

#define FLEXPWM_CTRL_DBLX_MASK                   (0x2U)
#define FLEXPWM_CTRL_DBLX_SHIFT                  (1U)
#define FLEXPWM_CTRL_DBLX_WIDTH                  (1U)
#define FLEXPWM_CTRL_DBLX(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_DBLX_SHIFT)) & FLEXPWM_CTRL_DBLX_MASK)

#define FLEXPWM_CTRL_LDMOD_MASK                  (0x4U)
#define FLEXPWM_CTRL_LDMOD_SHIFT                 (2U)
#define FLEXPWM_CTRL_LDMOD_WIDTH                 (1U)
#define FLEXPWM_CTRL_LDMOD(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_LDMOD_SHIFT)) & FLEXPWM_CTRL_LDMOD_MASK)

#define FLEXPWM_CTRL_SPLIT_MASK                  (0x8U)
#define FLEXPWM_CTRL_SPLIT_SHIFT                 (3U)
#define FLEXPWM_CTRL_SPLIT_WIDTH                 (1U)
#define FLEXPWM_CTRL_SPLIT(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_SPLIT_SHIFT)) & FLEXPWM_CTRL_SPLIT_MASK)

#define FLEXPWM_CTRL_PRSC_MASK                   (0x70U)
#define FLEXPWM_CTRL_PRSC_SHIFT                  (4U)
#define FLEXPWM_CTRL_PRSC_WIDTH                  (3U)
#define FLEXPWM_CTRL_PRSC(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_PRSC_SHIFT)) & FLEXPWM_CTRL_PRSC_MASK)

#define FLEXPWM_CTRL_COMPMODE_MASK               (0x80U)
#define FLEXPWM_CTRL_COMPMODE_SHIFT              (7U)
#define FLEXPWM_CTRL_COMPMODE_WIDTH              (1U)
#define FLEXPWM_CTRL_COMPMODE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_COMPMODE_SHIFT)) & FLEXPWM_CTRL_COMPMODE_MASK)

#define FLEXPWM_CTRL_DT_MASK                     (0x300U)
#define FLEXPWM_CTRL_DT_SHIFT                    (8U)
#define FLEXPWM_CTRL_DT_WIDTH                    (2U)
#define FLEXPWM_CTRL_DT(x)                       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_DT_SHIFT)) & FLEXPWM_CTRL_DT_MASK)

#define FLEXPWM_CTRL_FULL_MASK                   (0x400U)
#define FLEXPWM_CTRL_FULL_SHIFT                  (10U)
#define FLEXPWM_CTRL_FULL_WIDTH                  (1U)
#define FLEXPWM_CTRL_FULL(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_FULL_SHIFT)) & FLEXPWM_CTRL_FULL_MASK)

#define FLEXPWM_CTRL_HALF_MASK                   (0x800U)
#define FLEXPWM_CTRL_HALF_SHIFT                  (11U)
#define FLEXPWM_CTRL_HALF_WIDTH                  (1U)
#define FLEXPWM_CTRL_HALF(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_HALF_SHIFT)) & FLEXPWM_CTRL_HALF_MASK)

#define FLEXPWM_CTRL_LDFQ_MASK                   (0xF000U)
#define FLEXPWM_CTRL_LDFQ_SHIFT                  (12U)
#define FLEXPWM_CTRL_LDFQ_WIDTH                  (4U)
#define FLEXPWM_CTRL_LDFQ(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_LDFQ_SHIFT)) & FLEXPWM_CTRL_LDFQ_MASK)
/*! @} */

/*! @name VAL0 - Submodule 0 Value 0..Submodule 3 Value 0 */
/*! @{ */

#define FLEXPWM_VAL0_VAL0_MASK                   (0xFFFFU)
#define FLEXPWM_VAL0_VAL0_SHIFT                  (0U)
#define FLEXPWM_VAL0_VAL0_WIDTH                  (16U)
#define FLEXPWM_VAL0_VAL0(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_VAL0_VAL0_SHIFT)) & FLEXPWM_VAL0_VAL0_MASK)
/*! @} */

/*! @name FRACVAL1 - Submodule 0 Fractional Value 1..Submodule 3 Fractional Value 1 */
/*! @{ */

#define FLEXPWM_FRACVAL1_FRACVAL1_MASK           (0xF800U)
#define FLEXPWM_FRACVAL1_FRACVAL1_SHIFT          (11U)
#define FLEXPWM_FRACVAL1_FRACVAL1_WIDTH          (5U)
#define FLEXPWM_FRACVAL1_FRACVAL1(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRACVAL1_FRACVAL1_SHIFT)) & FLEXPWM_FRACVAL1_FRACVAL1_MASK)
/*! @} */

/*! @name VAL1 - Submodule 0 Value 1..Submodule 3 Value 1 */
/*! @{ */

#define FLEXPWM_VAL1_VAL1_MASK                   (0xFFFFU)
#define FLEXPWM_VAL1_VAL1_SHIFT                  (0U)
#define FLEXPWM_VAL1_VAL1_WIDTH                  (16U)
#define FLEXPWM_VAL1_VAL1(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_VAL1_VAL1_SHIFT)) & FLEXPWM_VAL1_VAL1_MASK)
/*! @} */

/*! @name FRACVAL2 - Submodule 0 Fractional Value 2..Submodule 3 Fractional Value 2 */
/*! @{ */

#define FLEXPWM_FRACVAL2_FRACVAL2_MASK           (0xF800U)
#define FLEXPWM_FRACVAL2_FRACVAL2_SHIFT          (11U)
#define FLEXPWM_FRACVAL2_FRACVAL2_WIDTH          (5U)
#define FLEXPWM_FRACVAL2_FRACVAL2(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRACVAL2_FRACVAL2_SHIFT)) & FLEXPWM_FRACVAL2_FRACVAL2_MASK)
/*! @} */

/*! @name VAL2 - Submodule 0 Value 2..Submodule 3 Value 2 */
/*! @{ */

#define FLEXPWM_VAL2_VAL2_MASK                   (0xFFFFU)
#define FLEXPWM_VAL2_VAL2_SHIFT                  (0U)
#define FLEXPWM_VAL2_VAL2_WIDTH                  (16U)
#define FLEXPWM_VAL2_VAL2(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_VAL2_VAL2_SHIFT)) & FLEXPWM_VAL2_VAL2_MASK)
/*! @} */

/*! @name FRACVAL3 - Submodule 0 Fractional Value 3..Submodule 3 Fractional Value 3 */
/*! @{ */

#define FLEXPWM_FRACVAL3_FRACVAL3_MASK           (0xF800U)
#define FLEXPWM_FRACVAL3_FRACVAL3_SHIFT          (11U)
#define FLEXPWM_FRACVAL3_FRACVAL3_WIDTH          (5U)
#define FLEXPWM_FRACVAL3_FRACVAL3(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRACVAL3_FRACVAL3_SHIFT)) & FLEXPWM_FRACVAL3_FRACVAL3_MASK)
/*! @} */

/*! @name VAL3 - Submodule 0 Value 3..Submodule 3 Value 3 */
/*! @{ */

#define FLEXPWM_VAL3_VAL3_MASK                   (0xFFFFU)
#define FLEXPWM_VAL3_VAL3_SHIFT                  (0U)
#define FLEXPWM_VAL3_VAL3_WIDTH                  (16U)
#define FLEXPWM_VAL3_VAL3(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_VAL3_VAL3_SHIFT)) & FLEXPWM_VAL3_VAL3_MASK)
/*! @} */

/*! @name FRACVAL4 - Submodule 0 Fractional Value 4..Submodule 3 Fractional Value 4 */
/*! @{ */

#define FLEXPWM_FRACVAL4_FRACVAL4_MASK           (0xF800U)
#define FLEXPWM_FRACVAL4_FRACVAL4_SHIFT          (11U)
#define FLEXPWM_FRACVAL4_FRACVAL4_WIDTH          (5U)
#define FLEXPWM_FRACVAL4_FRACVAL4(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRACVAL4_FRACVAL4_SHIFT)) & FLEXPWM_FRACVAL4_FRACVAL4_MASK)
/*! @} */

/*! @name VAL4 - Submodule 0 Value 4..Submodule 3 Value 4 */
/*! @{ */

#define FLEXPWM_VAL4_VAL4_MASK                   (0xFFFFU)
#define FLEXPWM_VAL4_VAL4_SHIFT                  (0U)
#define FLEXPWM_VAL4_VAL4_WIDTH                  (16U)
#define FLEXPWM_VAL4_VAL4(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_VAL4_VAL4_SHIFT)) & FLEXPWM_VAL4_VAL4_MASK)
/*! @} */

/*! @name FRACVAL5 - Submodule 0 Fractional Value 5..Submodule 3 Fractional Value 5 */
/*! @{ */

#define FLEXPWM_FRACVAL5_FRACVAL5_MASK           (0xF800U)
#define FLEXPWM_FRACVAL5_FRACVAL5_SHIFT          (11U)
#define FLEXPWM_FRACVAL5_FRACVAL5_WIDTH          (5U)
#define FLEXPWM_FRACVAL5_FRACVAL5(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRACVAL5_FRACVAL5_SHIFT)) & FLEXPWM_FRACVAL5_FRACVAL5_MASK)
/*! @} */

/*! @name VAL5 - Submodule 0 Value 5..Submodule 3 Value 5 */
/*! @{ */

#define FLEXPWM_VAL5_VAL5_MASK                   (0xFFFFU)
#define FLEXPWM_VAL5_VAL5_SHIFT                  (0U)
#define FLEXPWM_VAL5_VAL5_WIDTH                  (16U)
#define FLEXPWM_VAL5_VAL5(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_VAL5_VAL5_SHIFT)) & FLEXPWM_VAL5_VAL5_MASK)
/*! @} */

/*! @name FRCTRL - Submodule 0 Fractional Control..Submodule 3 Fractional Control */
/*! @{ */

#define FLEXPWM_FRCTRL_FRAC1_EN_MASK             (0x2U)
#define FLEXPWM_FRCTRL_FRAC1_EN_SHIFT            (1U)
#define FLEXPWM_FRCTRL_FRAC1_EN_WIDTH            (1U)
#define FLEXPWM_FRCTRL_FRAC1_EN(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRCTRL_FRAC1_EN_SHIFT)) & FLEXPWM_FRCTRL_FRAC1_EN_MASK)

#define FLEXPWM_FRCTRL_FRAC23_EN_MASK            (0x4U)
#define FLEXPWM_FRCTRL_FRAC23_EN_SHIFT           (2U)
#define FLEXPWM_FRCTRL_FRAC23_EN_WIDTH           (1U)
#define FLEXPWM_FRCTRL_FRAC23_EN(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRCTRL_FRAC23_EN_SHIFT)) & FLEXPWM_FRCTRL_FRAC23_EN_MASK)

#define FLEXPWM_FRCTRL_FRAC45_EN_MASK            (0x10U)
#define FLEXPWM_FRCTRL_FRAC45_EN_SHIFT           (4U)
#define FLEXPWM_FRCTRL_FRAC45_EN_WIDTH           (1U)
#define FLEXPWM_FRCTRL_FRAC45_EN(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRCTRL_FRAC45_EN_SHIFT)) & FLEXPWM_FRCTRL_FRAC45_EN_MASK)

#define FLEXPWM_FRCTRL_FRAC_PU_MASK              (0x100U)
#define FLEXPWM_FRCTRL_FRAC_PU_SHIFT             (8U)
#define FLEXPWM_FRCTRL_FRAC_PU_WIDTH             (1U)
#define FLEXPWM_FRCTRL_FRAC_PU(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FRCTRL_FRAC_PU_SHIFT)) & FLEXPWM_FRCTRL_FRAC_PU_MASK)
/*! @} */

/*! @name OCTRL - Submodule 0 Output Control..Submodule 3 Output Control */
/*! @{ */

#define FLEXPWM_OCTRL_PWMXFS_MASK                (0x3U)
#define FLEXPWM_OCTRL_PWMXFS_SHIFT               (0U)
#define FLEXPWM_OCTRL_PWMXFS_WIDTH               (2U)
#define FLEXPWM_OCTRL_PWMXFS(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_PWMXFS_SHIFT)) & FLEXPWM_OCTRL_PWMXFS_MASK)

#define FLEXPWM_OCTRL_PWMBFS_MASK                (0xCU)
#define FLEXPWM_OCTRL_PWMBFS_SHIFT               (2U)
#define FLEXPWM_OCTRL_PWMBFS_WIDTH               (2U)
#define FLEXPWM_OCTRL_PWMBFS(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_PWMBFS_SHIFT)) & FLEXPWM_OCTRL_PWMBFS_MASK)

#define FLEXPWM_OCTRL_PWMAFS_MASK                (0x30U)
#define FLEXPWM_OCTRL_PWMAFS_SHIFT               (4U)
#define FLEXPWM_OCTRL_PWMAFS_WIDTH               (2U)
#define FLEXPWM_OCTRL_PWMAFS(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_PWMAFS_SHIFT)) & FLEXPWM_OCTRL_PWMAFS_MASK)

#define FLEXPWM_OCTRL_POLX_MASK                  (0x100U)
#define FLEXPWM_OCTRL_POLX_SHIFT                 (8U)
#define FLEXPWM_OCTRL_POLX_WIDTH                 (1U)
#define FLEXPWM_OCTRL_POLX(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_POLX_SHIFT)) & FLEXPWM_OCTRL_POLX_MASK)

#define FLEXPWM_OCTRL_POLB_MASK                  (0x200U)
#define FLEXPWM_OCTRL_POLB_SHIFT                 (9U)
#define FLEXPWM_OCTRL_POLB_WIDTH                 (1U)
#define FLEXPWM_OCTRL_POLB(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_POLB_SHIFT)) & FLEXPWM_OCTRL_POLB_MASK)

#define FLEXPWM_OCTRL_POLA_MASK                  (0x400U)
#define FLEXPWM_OCTRL_POLA_SHIFT                 (10U)
#define FLEXPWM_OCTRL_POLA_WIDTH                 (1U)
#define FLEXPWM_OCTRL_POLA(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_POLA_SHIFT)) & FLEXPWM_OCTRL_POLA_MASK)

#define FLEXPWM_OCTRL_PWMX_IN_MASK               (0x2000U)
#define FLEXPWM_OCTRL_PWMX_IN_SHIFT              (13U)
#define FLEXPWM_OCTRL_PWMX_IN_WIDTH              (1U)
#define FLEXPWM_OCTRL_PWMX_IN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_PWMX_IN_SHIFT)) & FLEXPWM_OCTRL_PWMX_IN_MASK)

#define FLEXPWM_OCTRL_PWMB_IN_MASK               (0x4000U)
#define FLEXPWM_OCTRL_PWMB_IN_SHIFT              (14U)
#define FLEXPWM_OCTRL_PWMB_IN_WIDTH              (1U)
#define FLEXPWM_OCTRL_PWMB_IN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_PWMB_IN_SHIFT)) & FLEXPWM_OCTRL_PWMB_IN_MASK)

#define FLEXPWM_OCTRL_PWMA_IN_MASK               (0x8000U)
#define FLEXPWM_OCTRL_PWMA_IN_SHIFT              (15U)
#define FLEXPWM_OCTRL_PWMA_IN_WIDTH              (1U)
#define FLEXPWM_OCTRL_PWMA_IN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OCTRL_PWMA_IN_SHIFT)) & FLEXPWM_OCTRL_PWMA_IN_MASK)
/*! @} */

/*! @name STS - Submodule 0 Status..Submodule 3 Status */
/*! @{ */

#define FLEXPWM_STS_CMPF_MASK                    (0x3FU)
#define FLEXPWM_STS_CMPF_SHIFT                   (0U)
#define FLEXPWM_STS_CMPF_WIDTH                   (6U)
#define FLEXPWM_STS_CMPF(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_CMPF_SHIFT)) & FLEXPWM_STS_CMPF_MASK)

#define FLEXPWM_STS_CFX0_MASK                    (0x40U)
#define FLEXPWM_STS_CFX0_SHIFT                   (6U)
#define FLEXPWM_STS_CFX0_WIDTH                   (1U)
#define FLEXPWM_STS_CFX0(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_CFX0_SHIFT)) & FLEXPWM_STS_CFX0_MASK)

#define FLEXPWM_STS_CFX1_MASK                    (0x80U)
#define FLEXPWM_STS_CFX1_SHIFT                   (7U)
#define FLEXPWM_STS_CFX1_WIDTH                   (1U)
#define FLEXPWM_STS_CFX1(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_CFX1_SHIFT)) & FLEXPWM_STS_CFX1_MASK)

#define FLEXPWM_STS_CFB0_MASK                    (0x100U)
#define FLEXPWM_STS_CFB0_SHIFT                   (8U)
#define FLEXPWM_STS_CFB0_WIDTH                   (1U)
#define FLEXPWM_STS_CFB0(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_CFB0_SHIFT)) & FLEXPWM_STS_CFB0_MASK)

#define FLEXPWM_STS_CFB1_MASK                    (0x200U)
#define FLEXPWM_STS_CFB1_SHIFT                   (9U)
#define FLEXPWM_STS_CFB1_WIDTH                   (1U)
#define FLEXPWM_STS_CFB1(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_CFB1_SHIFT)) & FLEXPWM_STS_CFB1_MASK)

#define FLEXPWM_STS_CFA0_MASK                    (0x400U)
#define FLEXPWM_STS_CFA0_SHIFT                   (10U)
#define FLEXPWM_STS_CFA0_WIDTH                   (1U)
#define FLEXPWM_STS_CFA0(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_CFA0_SHIFT)) & FLEXPWM_STS_CFA0_MASK)

#define FLEXPWM_STS_CFA1_MASK                    (0x800U)
#define FLEXPWM_STS_CFA1_SHIFT                   (11U)
#define FLEXPWM_STS_CFA1_WIDTH                   (1U)
#define FLEXPWM_STS_CFA1(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_CFA1_SHIFT)) & FLEXPWM_STS_CFA1_MASK)

#define FLEXPWM_STS_RF_MASK                      (0x1000U)
#define FLEXPWM_STS_RF_SHIFT                     (12U)
#define FLEXPWM_STS_RF_WIDTH                     (1U)
#define FLEXPWM_STS_RF(x)                        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_RF_SHIFT)) & FLEXPWM_STS_RF_MASK)

#define FLEXPWM_STS_REF_MASK                     (0x2000U)
#define FLEXPWM_STS_REF_SHIFT                    (13U)
#define FLEXPWM_STS_REF_WIDTH                    (1U)
#define FLEXPWM_STS_REF(x)                       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_REF_SHIFT)) & FLEXPWM_STS_REF_MASK)

#define FLEXPWM_STS_RUF_MASK                     (0x4000U)
#define FLEXPWM_STS_RUF_SHIFT                    (14U)
#define FLEXPWM_STS_RUF_WIDTH                    (1U)
#define FLEXPWM_STS_RUF(x)                       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_RUF_SHIFT)) & FLEXPWM_STS_RUF_MASK)
/*! @} */

/*! @name INTEN - Submodule 0 Interrupt Enable..Submodule 3 Interrupt Enable */
/*! @{ */

#define FLEXPWM_INTEN_CMPIE_MASK                 (0x3FU)
#define FLEXPWM_INTEN_CMPIE_SHIFT                (0U)
#define FLEXPWM_INTEN_CMPIE_WIDTH                (6U)
#define FLEXPWM_INTEN_CMPIE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_CMPIE_SHIFT)) & FLEXPWM_INTEN_CMPIE_MASK)

#define FLEXPWM_INTEN_CX0IE_MASK                 (0x40U)
#define FLEXPWM_INTEN_CX0IE_SHIFT                (6U)
#define FLEXPWM_INTEN_CX0IE_WIDTH                (1U)
#define FLEXPWM_INTEN_CX0IE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_CX0IE_SHIFT)) & FLEXPWM_INTEN_CX0IE_MASK)

#define FLEXPWM_INTEN_CX1IE_MASK                 (0x80U)
#define FLEXPWM_INTEN_CX1IE_SHIFT                (7U)
#define FLEXPWM_INTEN_CX1IE_WIDTH                (1U)
#define FLEXPWM_INTEN_CX1IE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_CX1IE_SHIFT)) & FLEXPWM_INTEN_CX1IE_MASK)

#define FLEXPWM_INTEN_CB0IE_MASK                 (0x100U)
#define FLEXPWM_INTEN_CB0IE_SHIFT                (8U)
#define FLEXPWM_INTEN_CB0IE_WIDTH                (1U)
#define FLEXPWM_INTEN_CB0IE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_CB0IE_SHIFT)) & FLEXPWM_INTEN_CB0IE_MASK)

#define FLEXPWM_INTEN_CB1IE_MASK                 (0x200U)
#define FLEXPWM_INTEN_CB1IE_SHIFT                (9U)
#define FLEXPWM_INTEN_CB1IE_WIDTH                (1U)
#define FLEXPWM_INTEN_CB1IE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_CB1IE_SHIFT)) & FLEXPWM_INTEN_CB1IE_MASK)

#define FLEXPWM_INTEN_CA0IE_MASK                 (0x400U)
#define FLEXPWM_INTEN_CA0IE_SHIFT                (10U)
#define FLEXPWM_INTEN_CA0IE_WIDTH                (1U)
#define FLEXPWM_INTEN_CA0IE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_CA0IE_SHIFT)) & FLEXPWM_INTEN_CA0IE_MASK)

#define FLEXPWM_INTEN_CA1IE_MASK                 (0x800U)
#define FLEXPWM_INTEN_CA1IE_SHIFT                (11U)
#define FLEXPWM_INTEN_CA1IE_WIDTH                (1U)
#define FLEXPWM_INTEN_CA1IE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_CA1IE_SHIFT)) & FLEXPWM_INTEN_CA1IE_MASK)

#define FLEXPWM_INTEN_RIE_MASK                   (0x1000U)
#define FLEXPWM_INTEN_RIE_SHIFT                  (12U)
#define FLEXPWM_INTEN_RIE_WIDTH                  (1U)
#define FLEXPWM_INTEN_RIE(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_RIE_SHIFT)) & FLEXPWM_INTEN_RIE_MASK)

#define FLEXPWM_INTEN_REIE_MASK                  (0x2000U)
#define FLEXPWM_INTEN_REIE_SHIFT                 (13U)
#define FLEXPWM_INTEN_REIE_WIDTH                 (1U)
#define FLEXPWM_INTEN_REIE(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_INTEN_REIE_SHIFT)) & FLEXPWM_INTEN_REIE_MASK)
/*! @} */

/*! @name DMAEN - Submodule 0 DMA Enable..Submodule 3 DMA Enable */
/*! @{ */

#define FLEXPWM_DMAEN_CX0DE_MASK                 (0x1U)
#define FLEXPWM_DMAEN_CX0DE_SHIFT                (0U)
#define FLEXPWM_DMAEN_CX0DE_WIDTH                (1U)
#define FLEXPWM_DMAEN_CX0DE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_CX0DE_SHIFT)) & FLEXPWM_DMAEN_CX0DE_MASK)

#define FLEXPWM_DMAEN_CX1DE_MASK                 (0x2U)
#define FLEXPWM_DMAEN_CX1DE_SHIFT                (1U)
#define FLEXPWM_DMAEN_CX1DE_WIDTH                (1U)
#define FLEXPWM_DMAEN_CX1DE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_CX1DE_SHIFT)) & FLEXPWM_DMAEN_CX1DE_MASK)

#define FLEXPWM_DMAEN_CB0DE_MASK                 (0x4U)
#define FLEXPWM_DMAEN_CB0DE_SHIFT                (2U)
#define FLEXPWM_DMAEN_CB0DE_WIDTH                (1U)
#define FLEXPWM_DMAEN_CB0DE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_CB0DE_SHIFT)) & FLEXPWM_DMAEN_CB0DE_MASK)

#define FLEXPWM_DMAEN_CB1DE_MASK                 (0x8U)
#define FLEXPWM_DMAEN_CB1DE_SHIFT                (3U)
#define FLEXPWM_DMAEN_CB1DE_WIDTH                (1U)
#define FLEXPWM_DMAEN_CB1DE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_CB1DE_SHIFT)) & FLEXPWM_DMAEN_CB1DE_MASK)

#define FLEXPWM_DMAEN_CA0DE_MASK                 (0x10U)
#define FLEXPWM_DMAEN_CA0DE_SHIFT                (4U)
#define FLEXPWM_DMAEN_CA0DE_WIDTH                (1U)
#define FLEXPWM_DMAEN_CA0DE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_CA0DE_SHIFT)) & FLEXPWM_DMAEN_CA0DE_MASK)

#define FLEXPWM_DMAEN_CA1DE_MASK                 (0x20U)
#define FLEXPWM_DMAEN_CA1DE_SHIFT                (5U)
#define FLEXPWM_DMAEN_CA1DE_WIDTH                (1U)
#define FLEXPWM_DMAEN_CA1DE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_CA1DE_SHIFT)) & FLEXPWM_DMAEN_CA1DE_MASK)

#define FLEXPWM_DMAEN_CAPTDE_MASK                (0xC0U)
#define FLEXPWM_DMAEN_CAPTDE_SHIFT               (6U)
#define FLEXPWM_DMAEN_CAPTDE_WIDTH               (2U)
#define FLEXPWM_DMAEN_CAPTDE(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_CAPTDE_SHIFT)) & FLEXPWM_DMAEN_CAPTDE_MASK)

#define FLEXPWM_DMAEN_FAND_MASK                  (0x100U)
#define FLEXPWM_DMAEN_FAND_SHIFT                 (8U)
#define FLEXPWM_DMAEN_FAND_WIDTH                 (1U)
#define FLEXPWM_DMAEN_FAND(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_FAND_SHIFT)) & FLEXPWM_DMAEN_FAND_MASK)

#define FLEXPWM_DMAEN_VALDE_MASK                 (0x200U)
#define FLEXPWM_DMAEN_VALDE_SHIFT                (9U)
#define FLEXPWM_DMAEN_VALDE_WIDTH                (1U)
#define FLEXPWM_DMAEN_VALDE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DMAEN_VALDE_SHIFT)) & FLEXPWM_DMAEN_VALDE_MASK)
/*! @} */

/*! @name TCTRL - Submodule 0 Output Trigger Control..Submodule 3 Output Trigger Control */
/*! @{ */

#define FLEXPWM_TCTRL_OUT_TRIG_EN_MASK           (0x3FU)
#define FLEXPWM_TCTRL_OUT_TRIG_EN_SHIFT          (0U)
#define FLEXPWM_TCTRL_OUT_TRIG_EN_WIDTH          (6U)
#define FLEXPWM_TCTRL_OUT_TRIG_EN(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_TCTRL_OUT_TRIG_EN_SHIFT)) & FLEXPWM_TCTRL_OUT_TRIG_EN_MASK)

#define FLEXPWM_TCTRL_TRGFRQ_MASK                (0x1000U)
#define FLEXPWM_TCTRL_TRGFRQ_SHIFT               (12U)
#define FLEXPWM_TCTRL_TRGFRQ_WIDTH               (1U)
#define FLEXPWM_TCTRL_TRGFRQ(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_TCTRL_TRGFRQ_SHIFT)) & FLEXPWM_TCTRL_TRGFRQ_MASK)

#define FLEXPWM_TCTRL_PWBOT1_MASK                (0x4000U)
#define FLEXPWM_TCTRL_PWBOT1_SHIFT               (14U)
#define FLEXPWM_TCTRL_PWBOT1_WIDTH               (1U)
#define FLEXPWM_TCTRL_PWBOT1(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_TCTRL_PWBOT1_SHIFT)) & FLEXPWM_TCTRL_PWBOT1_MASK)

#define FLEXPWM_TCTRL_PWAOT0_MASK                (0x8000U)
#define FLEXPWM_TCTRL_PWAOT0_SHIFT               (15U)
#define FLEXPWM_TCTRL_PWAOT0_WIDTH               (1U)
#define FLEXPWM_TCTRL_PWAOT0(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_TCTRL_PWAOT0_SHIFT)) & FLEXPWM_TCTRL_PWAOT0_MASK)
/*! @} */

/*! @name DISMAP0 - Submodule 0 Fault Disable Mapping..Submodule 3 Fault Disable Mapping */
/*! @{ */

#define FLEXPWM_DISMAP0_DIS0A_MASK               (0xFU)
#define FLEXPWM_DISMAP0_DIS0A_SHIFT              (0U)
#define FLEXPWM_DISMAP0_DIS0A_WIDTH              (4U)
#define FLEXPWM_DISMAP0_DIS0A(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DISMAP0_DIS0A_SHIFT)) & FLEXPWM_DISMAP0_DIS0A_MASK)

#define FLEXPWM_DISMAP0_DIS0B_MASK               (0xF0U)
#define FLEXPWM_DISMAP0_DIS0B_SHIFT              (4U)
#define FLEXPWM_DISMAP0_DIS0B_WIDTH              (4U)
#define FLEXPWM_DISMAP0_DIS0B(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DISMAP0_DIS0B_SHIFT)) & FLEXPWM_DISMAP0_DIS0B_MASK)

#define FLEXPWM_DISMAP0_DIS0X_MASK               (0xF00U)
#define FLEXPWM_DISMAP0_DIS0X_SHIFT              (8U)
#define FLEXPWM_DISMAP0_DIS0X_WIDTH              (4U)
#define FLEXPWM_DISMAP0_DIS0X(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DISMAP0_DIS0X_SHIFT)) & FLEXPWM_DISMAP0_DIS0X_MASK)
/*! @} */

/*! @name DISMAP1 - Submodule 0 Fault Disable Mapping..Submodule 3 Fault Disable Mapping */
/*! @{ */

#define FLEXPWM_DISMAP1_DIS1A_MASK               (0xFU)
#define FLEXPWM_DISMAP1_DIS1A_SHIFT              (0U)
#define FLEXPWM_DISMAP1_DIS1A_WIDTH              (4U)
#define FLEXPWM_DISMAP1_DIS1A(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DISMAP1_DIS1A_SHIFT)) & FLEXPWM_DISMAP1_DIS1A_MASK)

#define FLEXPWM_DISMAP1_DIS1B_MASK               (0xF0U)
#define FLEXPWM_DISMAP1_DIS1B_SHIFT              (4U)
#define FLEXPWM_DISMAP1_DIS1B_WIDTH              (4U)
#define FLEXPWM_DISMAP1_DIS1B(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DISMAP1_DIS1B_SHIFT)) & FLEXPWM_DISMAP1_DIS1B_MASK)

#define FLEXPWM_DISMAP1_DIS1X_MASK               (0xF00U)
#define FLEXPWM_DISMAP1_DIS1X_SHIFT              (8U)
#define FLEXPWM_DISMAP1_DIS1X_WIDTH              (4U)
#define FLEXPWM_DISMAP1_DIS1X(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DISMAP1_DIS1X_SHIFT)) & FLEXPWM_DISMAP1_DIS1X_MASK)
/*! @} */

/*! @name DTCNT0 - Submodule 0 Deadtime Count 0..Submodule 3 Deadtime Count 0 */
/*! @{ */

#define FLEXPWM_DTCNT0_DTCNT0_MASK               (0xFFFFU)
#define FLEXPWM_DTCNT0_DTCNT0_SHIFT              (0U)
#define FLEXPWM_DTCNT0_DTCNT0_WIDTH              (16U)
#define FLEXPWM_DTCNT0_DTCNT0(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTCNT0_DTCNT0_SHIFT)) & FLEXPWM_DTCNT0_DTCNT0_MASK)
/*! @} */

/*! @name DTCNT1 - Submodule 0 Deadtime Count 1..Submodule 3 Deadtime Count 1 */
/*! @{ */

#define FLEXPWM_DTCNT1_DTCNT1_MASK               (0xFFFFU)
#define FLEXPWM_DTCNT1_DTCNT1_SHIFT              (0U)
#define FLEXPWM_DTCNT1_DTCNT1_WIDTH              (16U)
#define FLEXPWM_DTCNT1_DTCNT1(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTCNT1_DTCNT1_SHIFT)) & FLEXPWM_DTCNT1_DTCNT1_MASK)
/*! @} */

/*! @name CAPTCTRLA - Submodule 0 Capture Control A..Submodule 3 Capture Control A */
/*! @{ */

#define FLEXPWM_CAPTCTRLA_ARMA_MASK              (0x1U)
#define FLEXPWM_CAPTCTRLA_ARMA_SHIFT             (0U)
#define FLEXPWM_CAPTCTRLA_ARMA_WIDTH             (1U)
#define FLEXPWM_CAPTCTRLA_ARMA(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_ARMA_SHIFT)) & FLEXPWM_CAPTCTRLA_ARMA_MASK)

#define FLEXPWM_CAPTCTRLA_ONESHOTA_MASK          (0x2U)
#define FLEXPWM_CAPTCTRLA_ONESHOTA_SHIFT         (1U)
#define FLEXPWM_CAPTCTRLA_ONESHOTA_WIDTH         (1U)
#define FLEXPWM_CAPTCTRLA_ONESHOTA(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_ONESHOTA_SHIFT)) & FLEXPWM_CAPTCTRLA_ONESHOTA_MASK)

#define FLEXPWM_CAPTCTRLA_EDGA0_MASK             (0xCU)
#define FLEXPWM_CAPTCTRLA_EDGA0_SHIFT            (2U)
#define FLEXPWM_CAPTCTRLA_EDGA0_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLA_EDGA0(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_EDGA0_SHIFT)) & FLEXPWM_CAPTCTRLA_EDGA0_MASK)

#define FLEXPWM_CAPTCTRLA_EDGA1_MASK             (0x30U)
#define FLEXPWM_CAPTCTRLA_EDGA1_SHIFT            (4U)
#define FLEXPWM_CAPTCTRLA_EDGA1_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLA_EDGA1(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_EDGA1_SHIFT)) & FLEXPWM_CAPTCTRLA_EDGA1_MASK)

#define FLEXPWM_CAPTCTRLA_INP_SELA_MASK          (0x40U)
#define FLEXPWM_CAPTCTRLA_INP_SELA_SHIFT         (6U)
#define FLEXPWM_CAPTCTRLA_INP_SELA_WIDTH         (1U)
#define FLEXPWM_CAPTCTRLA_INP_SELA(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_INP_SELA_SHIFT)) & FLEXPWM_CAPTCTRLA_INP_SELA_MASK)

#define FLEXPWM_CAPTCTRLA_EDGCNTA_EN_MASK        (0x80U)
#define FLEXPWM_CAPTCTRLA_EDGCNTA_EN_SHIFT       (7U)
#define FLEXPWM_CAPTCTRLA_EDGCNTA_EN_WIDTH       (1U)
#define FLEXPWM_CAPTCTRLA_EDGCNTA_EN(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_EDGCNTA_EN_SHIFT)) & FLEXPWM_CAPTCTRLA_EDGCNTA_EN_MASK)

#define FLEXPWM_CAPTCTRLA_CFAWM_MASK             (0x300U)
#define FLEXPWM_CAPTCTRLA_CFAWM_SHIFT            (8U)
#define FLEXPWM_CAPTCTRLA_CFAWM_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLA_CFAWM(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_CFAWM_SHIFT)) & FLEXPWM_CAPTCTRLA_CFAWM_MASK)

#define FLEXPWM_CAPTCTRLA_CA0CNT_MASK            (0x1C00U)
#define FLEXPWM_CAPTCTRLA_CA0CNT_SHIFT           (10U)
#define FLEXPWM_CAPTCTRLA_CA0CNT_WIDTH           (3U)
#define FLEXPWM_CAPTCTRLA_CA0CNT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_CA0CNT_SHIFT)) & FLEXPWM_CAPTCTRLA_CA0CNT_MASK)

#define FLEXPWM_CAPTCTRLA_CA1CNT_MASK            (0xE000U)
#define FLEXPWM_CAPTCTRLA_CA1CNT_SHIFT           (13U)
#define FLEXPWM_CAPTCTRLA_CA1CNT_WIDTH           (3U)
#define FLEXPWM_CAPTCTRLA_CA1CNT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLA_CA1CNT_SHIFT)) & FLEXPWM_CAPTCTRLA_CA1CNT_MASK)
/*! @} */

/*! @name CAPTCOMPA - Submodule 0 Capture Compare A..Submodule 3 Capture Compare A */
/*! @{ */

#define FLEXPWM_CAPTCOMPA_EDGCMPA_MASK           (0xFFU)
#define FLEXPWM_CAPTCOMPA_EDGCMPA_SHIFT          (0U)
#define FLEXPWM_CAPTCOMPA_EDGCMPA_WIDTH          (8U)
#define FLEXPWM_CAPTCOMPA_EDGCMPA(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCOMPA_EDGCMPA_SHIFT)) & FLEXPWM_CAPTCOMPA_EDGCMPA_MASK)

#define FLEXPWM_CAPTCOMPA_EDGCNTA_MASK           (0xFF00U)
#define FLEXPWM_CAPTCOMPA_EDGCNTA_SHIFT          (8U)
#define FLEXPWM_CAPTCOMPA_EDGCNTA_WIDTH          (8U)
#define FLEXPWM_CAPTCOMPA_EDGCNTA(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCOMPA_EDGCNTA_SHIFT)) & FLEXPWM_CAPTCOMPA_EDGCNTA_MASK)
/*! @} */

/*! @name CAPTCTRLB - Submodule 0 Capture Control B..Submodule 3 Capture Control B */
/*! @{ */

#define FLEXPWM_CAPTCTRLB_ARMB_MASK              (0x1U)
#define FLEXPWM_CAPTCTRLB_ARMB_SHIFT             (0U)
#define FLEXPWM_CAPTCTRLB_ARMB_WIDTH             (1U)
#define FLEXPWM_CAPTCTRLB_ARMB(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_ARMB_SHIFT)) & FLEXPWM_CAPTCTRLB_ARMB_MASK)

#define FLEXPWM_CAPTCTRLB_ONESHOTB_MASK          (0x2U)
#define FLEXPWM_CAPTCTRLB_ONESHOTB_SHIFT         (1U)
#define FLEXPWM_CAPTCTRLB_ONESHOTB_WIDTH         (1U)
#define FLEXPWM_CAPTCTRLB_ONESHOTB(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_ONESHOTB_SHIFT)) & FLEXPWM_CAPTCTRLB_ONESHOTB_MASK)

#define FLEXPWM_CAPTCTRLB_EDGB0_MASK             (0xCU)
#define FLEXPWM_CAPTCTRLB_EDGB0_SHIFT            (2U)
#define FLEXPWM_CAPTCTRLB_EDGB0_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLB_EDGB0(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_EDGB0_SHIFT)) & FLEXPWM_CAPTCTRLB_EDGB0_MASK)

#define FLEXPWM_CAPTCTRLB_EDGB1_MASK             (0x30U)
#define FLEXPWM_CAPTCTRLB_EDGB1_SHIFT            (4U)
#define FLEXPWM_CAPTCTRLB_EDGB1_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLB_EDGB1(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_EDGB1_SHIFT)) & FLEXPWM_CAPTCTRLB_EDGB1_MASK)

#define FLEXPWM_CAPTCTRLB_INP_SELB_MASK          (0x40U)
#define FLEXPWM_CAPTCTRLB_INP_SELB_SHIFT         (6U)
#define FLEXPWM_CAPTCTRLB_INP_SELB_WIDTH         (1U)
#define FLEXPWM_CAPTCTRLB_INP_SELB(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_INP_SELB_SHIFT)) & FLEXPWM_CAPTCTRLB_INP_SELB_MASK)

#define FLEXPWM_CAPTCTRLB_EDGCNTB_EN_MASK        (0x80U)
#define FLEXPWM_CAPTCTRLB_EDGCNTB_EN_SHIFT       (7U)
#define FLEXPWM_CAPTCTRLB_EDGCNTB_EN_WIDTH       (1U)
#define FLEXPWM_CAPTCTRLB_EDGCNTB_EN(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_EDGCNTB_EN_SHIFT)) & FLEXPWM_CAPTCTRLB_EDGCNTB_EN_MASK)

#define FLEXPWM_CAPTCTRLB_CFBWM_MASK             (0x300U)
#define FLEXPWM_CAPTCTRLB_CFBWM_SHIFT            (8U)
#define FLEXPWM_CAPTCTRLB_CFBWM_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLB_CFBWM(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_CFBWM_SHIFT)) & FLEXPWM_CAPTCTRLB_CFBWM_MASK)

#define FLEXPWM_CAPTCTRLB_CB0CNT_MASK            (0x1C00U)
#define FLEXPWM_CAPTCTRLB_CB0CNT_SHIFT           (10U)
#define FLEXPWM_CAPTCTRLB_CB0CNT_WIDTH           (3U)
#define FLEXPWM_CAPTCTRLB_CB0CNT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_CB0CNT_SHIFT)) & FLEXPWM_CAPTCTRLB_CB0CNT_MASK)

#define FLEXPWM_CAPTCTRLB_CB1CNT_MASK            (0xE000U)
#define FLEXPWM_CAPTCTRLB_CB1CNT_SHIFT           (13U)
#define FLEXPWM_CAPTCTRLB_CB1CNT_WIDTH           (3U)
#define FLEXPWM_CAPTCTRLB_CB1CNT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLB_CB1CNT_SHIFT)) & FLEXPWM_CAPTCTRLB_CB1CNT_MASK)
/*! @} */

/*! @name CAPTCOMPB - Submodule 0 Capture Compare B..Submodule 3 Capture Compare B */
/*! @{ */

#define FLEXPWM_CAPTCOMPB_EDGCMPB_MASK           (0xFFU)
#define FLEXPWM_CAPTCOMPB_EDGCMPB_SHIFT          (0U)
#define FLEXPWM_CAPTCOMPB_EDGCMPB_WIDTH          (8U)
#define FLEXPWM_CAPTCOMPB_EDGCMPB(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCOMPB_EDGCMPB_SHIFT)) & FLEXPWM_CAPTCOMPB_EDGCMPB_MASK)

#define FLEXPWM_CAPTCOMPB_EDGCNTB_MASK           (0xFF00U)
#define FLEXPWM_CAPTCOMPB_EDGCNTB_SHIFT          (8U)
#define FLEXPWM_CAPTCOMPB_EDGCNTB_WIDTH          (8U)
#define FLEXPWM_CAPTCOMPB_EDGCNTB(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCOMPB_EDGCNTB_SHIFT)) & FLEXPWM_CAPTCOMPB_EDGCNTB_MASK)
/*! @} */

/*! @name CAPTCTRLX - Submodule 0 Capture Control X..Submodule 3 Capture Control X */
/*! @{ */

#define FLEXPWM_CAPTCTRLX_ARMX_MASK              (0x1U)
#define FLEXPWM_CAPTCTRLX_ARMX_SHIFT             (0U)
#define FLEXPWM_CAPTCTRLX_ARMX_WIDTH             (1U)
#define FLEXPWM_CAPTCTRLX_ARMX(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_ARMX_SHIFT)) & FLEXPWM_CAPTCTRLX_ARMX_MASK)

#define FLEXPWM_CAPTCTRLX_ONESHOTX_MASK          (0x2U)
#define FLEXPWM_CAPTCTRLX_ONESHOTX_SHIFT         (1U)
#define FLEXPWM_CAPTCTRLX_ONESHOTX_WIDTH         (1U)
#define FLEXPWM_CAPTCTRLX_ONESHOTX(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_ONESHOTX_SHIFT)) & FLEXPWM_CAPTCTRLX_ONESHOTX_MASK)

#define FLEXPWM_CAPTCTRLX_EDGX0_MASK             (0xCU)
#define FLEXPWM_CAPTCTRLX_EDGX0_SHIFT            (2U)
#define FLEXPWM_CAPTCTRLX_EDGX0_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLX_EDGX0(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_EDGX0_SHIFT)) & FLEXPWM_CAPTCTRLX_EDGX0_MASK)

#define FLEXPWM_CAPTCTRLX_EDGX1_MASK             (0x30U)
#define FLEXPWM_CAPTCTRLX_EDGX1_SHIFT            (4U)
#define FLEXPWM_CAPTCTRLX_EDGX1_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLX_EDGX1(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_EDGX1_SHIFT)) & FLEXPWM_CAPTCTRLX_EDGX1_MASK)

#define FLEXPWM_CAPTCTRLX_INP_SELX_MASK          (0x40U)
#define FLEXPWM_CAPTCTRLX_INP_SELX_SHIFT         (6U)
#define FLEXPWM_CAPTCTRLX_INP_SELX_WIDTH         (1U)
#define FLEXPWM_CAPTCTRLX_INP_SELX(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_INP_SELX_SHIFT)) & FLEXPWM_CAPTCTRLX_INP_SELX_MASK)

#define FLEXPWM_CAPTCTRLX_EDGCNTX_EN_MASK        (0x80U)
#define FLEXPWM_CAPTCTRLX_EDGCNTX_EN_SHIFT       (7U)
#define FLEXPWM_CAPTCTRLX_EDGCNTX_EN_WIDTH       (1U)
#define FLEXPWM_CAPTCTRLX_EDGCNTX_EN(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_EDGCNTX_EN_SHIFT)) & FLEXPWM_CAPTCTRLX_EDGCNTX_EN_MASK)

#define FLEXPWM_CAPTCTRLX_CFXWM_MASK             (0x300U)
#define FLEXPWM_CAPTCTRLX_CFXWM_SHIFT            (8U)
#define FLEXPWM_CAPTCTRLX_CFXWM_WIDTH            (2U)
#define FLEXPWM_CAPTCTRLX_CFXWM(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_CFXWM_SHIFT)) & FLEXPWM_CAPTCTRLX_CFXWM_MASK)

#define FLEXPWM_CAPTCTRLX_CX0CNT_MASK            (0x1C00U)
#define FLEXPWM_CAPTCTRLX_CX0CNT_SHIFT           (10U)
#define FLEXPWM_CAPTCTRLX_CX0CNT_WIDTH           (3U)
#define FLEXPWM_CAPTCTRLX_CX0CNT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_CX0CNT_SHIFT)) & FLEXPWM_CAPTCTRLX_CX0CNT_MASK)

#define FLEXPWM_CAPTCTRLX_CX1CNT_MASK            (0xE000U)
#define FLEXPWM_CAPTCTRLX_CX1CNT_SHIFT           (13U)
#define FLEXPWM_CAPTCTRLX_CX1CNT_WIDTH           (3U)
#define FLEXPWM_CAPTCTRLX_CX1CNT(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCTRLX_CX1CNT_SHIFT)) & FLEXPWM_CAPTCTRLX_CX1CNT_MASK)
/*! @} */

/*! @name CAPTCOMPX - Submodule 0 Capture Compare X..Submodule 3 Capture Compare X */
/*! @{ */

#define FLEXPWM_CAPTCOMPX_EDGCMPX_MASK           (0xFFU)
#define FLEXPWM_CAPTCOMPX_EDGCMPX_SHIFT          (0U)
#define FLEXPWM_CAPTCOMPX_EDGCMPX_WIDTH          (8U)
#define FLEXPWM_CAPTCOMPX_EDGCMPX(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCOMPX_EDGCMPX_SHIFT)) & FLEXPWM_CAPTCOMPX_EDGCMPX_MASK)

#define FLEXPWM_CAPTCOMPX_EDGCNTX_MASK           (0xFF00U)
#define FLEXPWM_CAPTCOMPX_EDGCNTX_SHIFT          (8U)
#define FLEXPWM_CAPTCOMPX_EDGCNTX_WIDTH          (8U)
#define FLEXPWM_CAPTCOMPX_EDGCNTX(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CAPTCOMPX_EDGCNTX_SHIFT)) & FLEXPWM_CAPTCOMPX_EDGCNTX_MASK)
/*! @} */

/*! @name CVAL0 - Submodule 0 Capture Value 0..Submodule 3 Capture Value 0 */
/*! @{ */

#define FLEXPWM_CVAL0_CAPTVAL0_MASK              (0xFFFFU)
#define FLEXPWM_CVAL0_CAPTVAL0_SHIFT             (0U)
#define FLEXPWM_CVAL0_CAPTVAL0_WIDTH             (16U)
#define FLEXPWM_CVAL0_CAPTVAL0(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL0_CAPTVAL0_SHIFT)) & FLEXPWM_CVAL0_CAPTVAL0_MASK)
/*! @} */

/*! @name CVAL0CYC - Submodule 0 Capture Value 0 Cycle..Submodule 3 Capture Value 0 Cycle */
/*! @{ */

#define FLEXPWM_CVAL0CYC_CVAL0CYC_MASK           (0xFU)
#define FLEXPWM_CVAL0CYC_CVAL0CYC_SHIFT          (0U)
#define FLEXPWM_CVAL0CYC_CVAL0CYC_WIDTH          (4U)
#define FLEXPWM_CVAL0CYC_CVAL0CYC(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL0CYC_CVAL0CYC_SHIFT)) & FLEXPWM_CVAL0CYC_CVAL0CYC_MASK)
/*! @} */

/*! @name CVAL1 - Submodule 0 Capture Value 1..Submodule 3 Capture Value 1 */
/*! @{ */

#define FLEXPWM_CVAL1_CAPTVAL1_MASK              (0xFFFFU)
#define FLEXPWM_CVAL1_CAPTVAL1_SHIFT             (0U)
#define FLEXPWM_CVAL1_CAPTVAL1_WIDTH             (16U)
#define FLEXPWM_CVAL1_CAPTVAL1(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL1_CAPTVAL1_SHIFT)) & FLEXPWM_CVAL1_CAPTVAL1_MASK)
/*! @} */

/*! @name CVAL1CYC - Submodule 0 Capture Value 1 Cycle..Submodule 3 Capture Value 1 Cycle */
/*! @{ */

#define FLEXPWM_CVAL1CYC_CVAL1CYC_MASK           (0xFU)
#define FLEXPWM_CVAL1CYC_CVAL1CYC_SHIFT          (0U)
#define FLEXPWM_CVAL1CYC_CVAL1CYC_WIDTH          (4U)
#define FLEXPWM_CVAL1CYC_CVAL1CYC(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL1CYC_CVAL1CYC_SHIFT)) & FLEXPWM_CVAL1CYC_CVAL1CYC_MASK)
/*! @} */

/*! @name CVAL2 - Submodule 0 Capture Value 2..Submodule 3 Capture Value 2 */
/*! @{ */

#define FLEXPWM_CVAL2_CAPTVAL2_MASK              (0xFFFFU)
#define FLEXPWM_CVAL2_CAPTVAL2_SHIFT             (0U)
#define FLEXPWM_CVAL2_CAPTVAL2_WIDTH             (16U)
#define FLEXPWM_CVAL2_CAPTVAL2(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL2_CAPTVAL2_SHIFT)) & FLEXPWM_CVAL2_CAPTVAL2_MASK)
/*! @} */

/*! @name CVAL2CYC - Submodule 0 Capture Value 2 Cycle..Submodule 3 Capture Value 2 Cycle */
/*! @{ */

#define FLEXPWM_CVAL2CYC_CVAL2CYC_MASK           (0xFU)
#define FLEXPWM_CVAL2CYC_CVAL2CYC_SHIFT          (0U)
#define FLEXPWM_CVAL2CYC_CVAL2CYC_WIDTH          (4U)
#define FLEXPWM_CVAL2CYC_CVAL2CYC(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL2CYC_CVAL2CYC_SHIFT)) & FLEXPWM_CVAL2CYC_CVAL2CYC_MASK)
/*! @} */

/*! @name CVAL3 - Submodule 0 Capture Value 3..Submodule 3 Capture Value 3 */
/*! @{ */

#define FLEXPWM_CVAL3_CAPTVAL3_MASK              (0xFFFFU)
#define FLEXPWM_CVAL3_CAPTVAL3_SHIFT             (0U)
#define FLEXPWM_CVAL3_CAPTVAL3_WIDTH             (16U)
#define FLEXPWM_CVAL3_CAPTVAL3(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL3_CAPTVAL3_SHIFT)) & FLEXPWM_CVAL3_CAPTVAL3_MASK)
/*! @} */

/*! @name CVAL3CYC - Submodule 0 Capture Value 3 Cycle..Submodule 3 Capture Value 3 Cycle */
/*! @{ */

#define FLEXPWM_CVAL3CYC_CVAL3CYC_MASK           (0xFU)
#define FLEXPWM_CVAL3CYC_CVAL3CYC_SHIFT          (0U)
#define FLEXPWM_CVAL3CYC_CVAL3CYC_WIDTH          (4U)
#define FLEXPWM_CVAL3CYC_CVAL3CYC(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL3CYC_CVAL3CYC_SHIFT)) & FLEXPWM_CVAL3CYC_CVAL3CYC_MASK)
/*! @} */

/*! @name CVAL4 - Submodule 0 Capture Value 4..Submodule 3 Capture Value 4 */
/*! @{ */

#define FLEXPWM_CVAL4_CAPTVAL4_MASK              (0xFFFFU)
#define FLEXPWM_CVAL4_CAPTVAL4_SHIFT             (0U)
#define FLEXPWM_CVAL4_CAPTVAL4_WIDTH             (16U)
#define FLEXPWM_CVAL4_CAPTVAL4(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL4_CAPTVAL4_SHIFT)) & FLEXPWM_CVAL4_CAPTVAL4_MASK)
/*! @} */

/*! @name CVAL4CYC - Submodule 0 Capture Value 4 Cycle..Submodule 3 Capture Value 4 Cycle */
/*! @{ */

#define FLEXPWM_CVAL4CYC_CVAL4CYC_MASK           (0xFU)
#define FLEXPWM_CVAL4CYC_CVAL4CYC_SHIFT          (0U)
#define FLEXPWM_CVAL4CYC_CVAL4CYC_WIDTH          (4U)
#define FLEXPWM_CVAL4CYC_CVAL4CYC(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL4CYC_CVAL4CYC_SHIFT)) & FLEXPWM_CVAL4CYC_CVAL4CYC_MASK)
/*! @} */

/*! @name CVAL5 - Submodule 0 Capture Value 5..Submodule 3 Capture Value 5 */
/*! @{ */

#define FLEXPWM_CVAL5_CAPTVAL5_MASK              (0xFFFFU)
#define FLEXPWM_CVAL5_CAPTVAL5_SHIFT             (0U)
#define FLEXPWM_CVAL5_CAPTVAL5_WIDTH             (16U)
#define FLEXPWM_CVAL5_CAPTVAL5(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL5_CAPTVAL5_SHIFT)) & FLEXPWM_CVAL5_CAPTVAL5_MASK)
/*! @} */

/*! @name CVAL5CYC - Submodule 0 Capture Value 5 Cycle..Submodule 3 Capture Value 5 Cycle */
/*! @{ */

#define FLEXPWM_CVAL5CYC_CVAL5CYC_MASK           (0xFU)
#define FLEXPWM_CVAL5CYC_CVAL5CYC_SHIFT          (0U)
#define FLEXPWM_CVAL5CYC_CVAL5CYC_WIDTH          (4U)
#define FLEXPWM_CVAL5CYC_CVAL5CYC(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CVAL5CYC_CVAL5CYC_SHIFT)) & FLEXPWM_CVAL5CYC_CVAL5CYC_MASK)
/*! @} */

/*! @name PHASEDLY - Submodule 1 Phase Delay..Submodule 3 Phase Delay */
/*! @{ */

#define FLEXPWM_PHASEDLY_PHASEDLY_MASK           (0xFFFFU)
#define FLEXPWM_PHASEDLY_PHASEDLY_SHIFT          (0U)
#define FLEXPWM_PHASEDLY_PHASEDLY_WIDTH          (16U)
#define FLEXPWM_PHASEDLY_PHASEDLY(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_PHASEDLY_PHASEDLY_SHIFT)) & FLEXPWM_PHASEDLY_PHASEDLY_MASK)
/*! @} */

/*! @name OUTEN - Output Enable */
/*! @{ */

#define FLEXPWM_OUTEN_PWMX_EN_MASK               (0xFU)
#define FLEXPWM_OUTEN_PWMX_EN_SHIFT              (0U)
#define FLEXPWM_OUTEN_PWMX_EN_WIDTH              (4U)
#define FLEXPWM_OUTEN_PWMX_EN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OUTEN_PWMX_EN_SHIFT)) & FLEXPWM_OUTEN_PWMX_EN_MASK)

#define FLEXPWM_OUTEN_PWMB_EN_MASK               (0xF0U)
#define FLEXPWM_OUTEN_PWMB_EN_SHIFT              (4U)
#define FLEXPWM_OUTEN_PWMB_EN_WIDTH              (4U)
#define FLEXPWM_OUTEN_PWMB_EN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OUTEN_PWMB_EN_SHIFT)) & FLEXPWM_OUTEN_PWMB_EN_MASK)

#define FLEXPWM_OUTEN_PWMA_EN_MASK               (0xF00U)
#define FLEXPWM_OUTEN_PWMA_EN_SHIFT              (8U)
#define FLEXPWM_OUTEN_PWMA_EN_WIDTH              (4U)
#define FLEXPWM_OUTEN_PWMA_EN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OUTEN_PWMA_EN_SHIFT)) & FLEXPWM_OUTEN_PWMA_EN_MASK)
/*! @} */

/*! @name MASK - Mask */
/*! @{ */

#define FLEXPWM_MASK_MASKX_MASK                  (0xFU)
#define FLEXPWM_MASK_MASKX_SHIFT                 (0U)
#define FLEXPWM_MASK_MASKX_WIDTH                 (4U)
#define FLEXPWM_MASK_MASKX(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_MASKX_SHIFT)) & FLEXPWM_MASK_MASKX_MASK)

#define FLEXPWM_MASK_MASKB_MASK                  (0xF0U)
#define FLEXPWM_MASK_MASKB_SHIFT                 (4U)
#define FLEXPWM_MASK_MASKB_WIDTH                 (4U)
#define FLEXPWM_MASK_MASKB(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_MASKB_SHIFT)) & FLEXPWM_MASK_MASKB_MASK)

#define FLEXPWM_MASK_MASKA_MASK                  (0xF00U)
#define FLEXPWM_MASK_MASKA_SHIFT                 (8U)
#define FLEXPWM_MASK_MASKA_WIDTH                 (4U)
#define FLEXPWM_MASK_MASKA(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_MASKA_SHIFT)) & FLEXPWM_MASK_MASKA_MASK)

#define FLEXPWM_MASK_UPDATE_MASK_MASK            (0xF000U)
#define FLEXPWM_MASK_UPDATE_MASK_SHIFT           (12U)
#define FLEXPWM_MASK_UPDATE_MASK_WIDTH           (4U)
#define FLEXPWM_MASK_UPDATE_MASK(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_UPDATE_MASK_SHIFT)) & FLEXPWM_MASK_UPDATE_MASK_MASK)
/*! @} */

/*! @name SWCOUT - Software Controlled Output */
/*! @{ */

#define FLEXPWM_SWCOUT_SM0OUT45_MASK             (0x1U)
#define FLEXPWM_SWCOUT_SM0OUT45_SHIFT            (0U)
#define FLEXPWM_SWCOUT_SM0OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM0OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM0OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM0OUT45_MASK)

#define FLEXPWM_SWCOUT_SM0OUT23_MASK             (0x2U)
#define FLEXPWM_SWCOUT_SM0OUT23_SHIFT            (1U)
#define FLEXPWM_SWCOUT_SM0OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM0OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM0OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM0OUT23_MASK)

#define FLEXPWM_SWCOUT_SM1OUT45_MASK             (0x4U)
#define FLEXPWM_SWCOUT_SM1OUT45_SHIFT            (2U)
#define FLEXPWM_SWCOUT_SM1OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM1OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM1OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM1OUT45_MASK)

#define FLEXPWM_SWCOUT_SM1OUT23_MASK             (0x8U)
#define FLEXPWM_SWCOUT_SM1OUT23_SHIFT            (3U)
#define FLEXPWM_SWCOUT_SM1OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM1OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM1OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM1OUT23_MASK)

#define FLEXPWM_SWCOUT_SM2OUT45_MASK             (0x10U)
#define FLEXPWM_SWCOUT_SM2OUT45_SHIFT            (4U)
#define FLEXPWM_SWCOUT_SM2OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM2OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM2OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM2OUT45_MASK)

#define FLEXPWM_SWCOUT_SM2OUT23_MASK             (0x20U)
#define FLEXPWM_SWCOUT_SM2OUT23_SHIFT            (5U)
#define FLEXPWM_SWCOUT_SM2OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM2OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM2OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM2OUT23_MASK)

#define FLEXPWM_SWCOUT_SM3OUT45_MASK             (0x40U)
#define FLEXPWM_SWCOUT_SM3OUT45_SHIFT            (6U)
#define FLEXPWM_SWCOUT_SM3OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM3OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM3OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM3OUT45_MASK)

#define FLEXPWM_SWCOUT_SM3OUT23_MASK             (0x80U)
#define FLEXPWM_SWCOUT_SM3OUT23_SHIFT            (7U)
#define FLEXPWM_SWCOUT_SM3OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM3OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM3OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM3OUT23_MASK)
/*! @} */

/*! @name DTSRCSEL - PWM Source Select */
/*! @{ */

#define FLEXPWM_DTSRCSEL_SM0SEL45_MASK           (0x3U)
#define FLEXPWM_DTSRCSEL_SM0SEL45_SHIFT          (0U)
#define FLEXPWM_DTSRCSEL_SM0SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM0SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM0SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM0SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM0SEL23_MASK           (0xCU)
#define FLEXPWM_DTSRCSEL_SM0SEL23_SHIFT          (2U)
#define FLEXPWM_DTSRCSEL_SM0SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM0SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM0SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM0SEL23_MASK)

#define FLEXPWM_DTSRCSEL_SM1SEL45_MASK           (0x30U)
#define FLEXPWM_DTSRCSEL_SM1SEL45_SHIFT          (4U)
#define FLEXPWM_DTSRCSEL_SM1SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM1SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM1SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM1SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM1SEL23_MASK           (0xC0U)
#define FLEXPWM_DTSRCSEL_SM1SEL23_SHIFT          (6U)
#define FLEXPWM_DTSRCSEL_SM1SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM1SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM1SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM1SEL23_MASK)

#define FLEXPWM_DTSRCSEL_SM2SEL45_MASK           (0x300U)
#define FLEXPWM_DTSRCSEL_SM2SEL45_SHIFT          (8U)
#define FLEXPWM_DTSRCSEL_SM2SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM2SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM2SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM2SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM2SEL23_MASK           (0xC00U)
#define FLEXPWM_DTSRCSEL_SM2SEL23_SHIFT          (10U)
#define FLEXPWM_DTSRCSEL_SM2SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM2SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM2SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM2SEL23_MASK)

#define FLEXPWM_DTSRCSEL_SM3SEL45_MASK           (0x3000U)
#define FLEXPWM_DTSRCSEL_SM3SEL45_SHIFT          (12U)
#define FLEXPWM_DTSRCSEL_SM3SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM3SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM3SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM3SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM3SEL23_MASK           (0xC000U)
#define FLEXPWM_DTSRCSEL_SM3SEL23_SHIFT          (14U)
#define FLEXPWM_DTSRCSEL_SM3SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM3SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM3SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM3SEL23_MASK)
/*! @} */

/*! @name MCTRL - Master Control */
/*! @{ */

#define FLEXPWM_MCTRL_LDOK_MASK                  (0xFU)
#define FLEXPWM_MCTRL_LDOK_SHIFT                 (0U)
#define FLEXPWM_MCTRL_LDOK_WIDTH                 (4U)
#define FLEXPWM_MCTRL_LDOK(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_LDOK_SHIFT)) & FLEXPWM_MCTRL_LDOK_MASK)

#define FLEXPWM_MCTRL_CLDOK_MASK                 (0xF0U)
#define FLEXPWM_MCTRL_CLDOK_SHIFT                (4U)
#define FLEXPWM_MCTRL_CLDOK_WIDTH                (4U)
#define FLEXPWM_MCTRL_CLDOK(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_CLDOK_SHIFT)) & FLEXPWM_MCTRL_CLDOK_MASK)

#define FLEXPWM_MCTRL_RUN_MASK                   (0xF00U)
#define FLEXPWM_MCTRL_RUN_SHIFT                  (8U)
#define FLEXPWM_MCTRL_RUN_WIDTH                  (4U)
#define FLEXPWM_MCTRL_RUN(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_RUN_SHIFT)) & FLEXPWM_MCTRL_RUN_MASK)

#define FLEXPWM_MCTRL_IPOL_MASK                  (0xF000U)
#define FLEXPWM_MCTRL_IPOL_SHIFT                 (12U)
#define FLEXPWM_MCTRL_IPOL_WIDTH                 (4U)
#define FLEXPWM_MCTRL_IPOL(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_IPOL_SHIFT)) & FLEXPWM_MCTRL_IPOL_MASK)
/*! @} */

/*! @name MCTRL2 - Master Control 2 */
/*! @{ */

#define FLEXPWM_MCTRL2_MONPLL_MASK               (0x3U)
#define FLEXPWM_MCTRL2_MONPLL_SHIFT              (0U)
#define FLEXPWM_MCTRL2_MONPLL_WIDTH              (2U)
#define FLEXPWM_MCTRL2_MONPLL(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL2_MONPLL_SHIFT)) & FLEXPWM_MCTRL2_MONPLL_MASK)
/*! @} */

/*! @name CTRL - Fault Protection 0 Control */
/*! @{ */

#define FLEXPWM_CTRL_FIE_MASK                    (0xFU)
#define FLEXPWM_CTRL_FIE_SHIFT                   (0U)
#define FLEXPWM_CTRL_FIE_WIDTH                   (4U)
#define FLEXPWM_CTRL_FIE(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_FIE_SHIFT)) & FLEXPWM_CTRL_FIE_MASK)

#define FLEXPWM_CTRL_FSAFE_MASK                  (0xF0U)
#define FLEXPWM_CTRL_FSAFE_SHIFT                 (4U)
#define FLEXPWM_CTRL_FSAFE_WIDTH                 (4U)
#define FLEXPWM_CTRL_FSAFE(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_FSAFE_SHIFT)) & FLEXPWM_CTRL_FSAFE_MASK)

#define FLEXPWM_CTRL_FAUTO_MASK                  (0xF00U)
#define FLEXPWM_CTRL_FAUTO_SHIFT                 (8U)
#define FLEXPWM_CTRL_FAUTO_WIDTH                 (4U)
#define FLEXPWM_CTRL_FAUTO(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_FAUTO_SHIFT)) & FLEXPWM_CTRL_FAUTO_MASK)

#define FLEXPWM_CTRL_FLVL_MASK                   (0xF000U)
#define FLEXPWM_CTRL_FLVL_SHIFT                  (12U)
#define FLEXPWM_CTRL_FLVL_WIDTH                  (4U)
#define FLEXPWM_CTRL_FLVL(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL_FLVL_SHIFT)) & FLEXPWM_CTRL_FLVL_MASK)
/*! @} */

/*! @name STS - Fault Protection 0 Status */
/*! @{ */

#define FLEXPWM_STS_FFLAG_MASK                   (0xFU)
#define FLEXPWM_STS_FFLAG_SHIFT                  (0U)
#define FLEXPWM_STS_FFLAG_WIDTH                  (4U)
#define FLEXPWM_STS_FFLAG(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_FFLAG_SHIFT)) & FLEXPWM_STS_FFLAG_MASK)

#define FLEXPWM_STS_FFULL_MASK                   (0xF0U)
#define FLEXPWM_STS_FFULL_SHIFT                  (4U)
#define FLEXPWM_STS_FFULL_WIDTH                  (4U)
#define FLEXPWM_STS_FFULL(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_FFULL_SHIFT)) & FLEXPWM_STS_FFULL_MASK)

#define FLEXPWM_STS_FFPIN_MASK                   (0xF00U)
#define FLEXPWM_STS_FFPIN_SHIFT                  (8U)
#define FLEXPWM_STS_FFPIN_WIDTH                  (4U)
#define FLEXPWM_STS_FFPIN(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_FFPIN_SHIFT)) & FLEXPWM_STS_FFPIN_MASK)

#define FLEXPWM_STS_FHALF_MASK                   (0xF000U)
#define FLEXPWM_STS_FHALF_SHIFT                  (12U)
#define FLEXPWM_STS_FHALF_WIDTH                  (4U)
#define FLEXPWM_STS_FHALF(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_STS_FHALF_SHIFT)) & FLEXPWM_STS_FHALF_MASK)
/*! @} */

/*! @name FILT - Fault Protection 0 Filter */
/*! @{ */

#define FLEXPWM_FILT_FILT_PER_MASK               (0xFFU)
#define FLEXPWM_FILT_FILT_PER_SHIFT              (0U)
#define FLEXPWM_FILT_FILT_PER_WIDTH              (8U)
#define FLEXPWM_FILT_FILT_PER(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FILT_FILT_PER_SHIFT)) & FLEXPWM_FILT_FILT_PER_MASK)

#define FLEXPWM_FILT_FILT_CNT_MASK               (0x700U)
#define FLEXPWM_FILT_FILT_CNT_SHIFT              (8U)
#define FLEXPWM_FILT_FILT_CNT_WIDTH              (3U)
#define FLEXPWM_FILT_FILT_CNT(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FILT_FILT_CNT_SHIFT)) & FLEXPWM_FILT_FILT_CNT_MASK)

#define FLEXPWM_FILT_GSTR_MASK                   (0x8000U)
#define FLEXPWM_FILT_GSTR_SHIFT                  (15U)
#define FLEXPWM_FILT_GSTR_WIDTH                  (1U)
#define FLEXPWM_FILT_GSTR(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FILT_GSTR_SHIFT)) & FLEXPWM_FILT_GSTR_MASK)
/*! @} */

/*! @name TST - Fault Protection 0 Test */
/*! @{ */

#define FLEXPWM_TST_FTEST_MASK                   (0x1U)
#define FLEXPWM_TST_FTEST_SHIFT                  (0U)
#define FLEXPWM_TST_FTEST_WIDTH                  (1U)
#define FLEXPWM_TST_FTEST(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_TST_FTEST_SHIFT)) & FLEXPWM_TST_FTEST_MASK)
/*! @} */

/*! @name CTRL2 - Fault Protection 0 Control 2 */
/*! @{ */

#define FLEXPWM_CTRL2_NOCOMB_MASK                (0xFU)
#define FLEXPWM_CTRL2_NOCOMB_SHIFT               (0U)
#define FLEXPWM_CTRL2_NOCOMB_WIDTH               (4U)
#define FLEXPWM_CTRL2_NOCOMB(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_CTRL2_NOCOMB_SHIFT)) & FLEXPWM_CTRL2_NOCOMB_MASK)
/*! @} */

/*! @name DLLSR - DLL Status */
/*! @{ */

#define FLEXPWM_DLLSR_LOCK_MASK                  (0x1U)
#define FLEXPWM_DLLSR_LOCK_SHIFT                 (0U)
#define FLEXPWM_DLLSR_LOCK_WIDTH                 (1U)
#define FLEXPWM_DLLSR_LOCK(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DLLSR_LOCK_SHIFT)) & FLEXPWM_DLLSR_LOCK_MASK)

#define FLEXPWM_DLLSR_LOL_MASK                   (0x2U)
#define FLEXPWM_DLLSR_LOL_SHIFT                  (1U)
#define FLEXPWM_DLLSR_LOL_WIDTH                  (1U)
#define FLEXPWM_DLLSR_LOL(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DLLSR_LOL_SHIFT)) & FLEXPWM_DLLSR_LOL_MASK)
/*! @} */

/*! @name SM0_BIST_CTRL - Submodule 0 BIST Control */
/*! @{ */

#define FLEXPWM_SM0_BIST_CTRL_BIST_ENABLE_MASK   (0x1U)
#define FLEXPWM_SM0_BIST_CTRL_BIST_ENABLE_SHIFT  (0U)
#define FLEXPWM_SM0_BIST_CTRL_BIST_ENABLE_WIDTH  (1U)
#define FLEXPWM_SM0_BIST_CTRL_BIST_ENABLE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM0_BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM0_BIST_CTRL_CLK_INITIAL_MASK   (0x3EU)
#define FLEXPWM_SM0_BIST_CTRL_CLK_INITIAL_SHIFT  (1U)
#define FLEXPWM_SM0_BIST_CTRL_CLK_INITIAL_WIDTH  (5U)
#define FLEXPWM_SM0_BIST_CTRL_CLK_INITIAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM0_BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM0_BIST_CTRL_TOGGLE_MODE_MASK   (0x40U)
#define FLEXPWM_SM0_BIST_CTRL_TOGGLE_MODE_SHIFT  (6U)
#define FLEXPWM_SM0_BIST_CTRL_TOGGLE_MODE_WIDTH  (1U)
#define FLEXPWM_SM0_BIST_CTRL_TOGGLE_MODE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM0_BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM0_BIST_CTRL_MANUAL_TOGGLE_MASK (0x80U)
#define FLEXPWM_SM0_BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM0_BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM0_BIST_CTRL_MANUAL_TOGGLE(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM0_BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM0_BIST_CTRL_CLK_FINAL_MASK     (0x1F00U)
#define FLEXPWM_SM0_BIST_CTRL_CLK_FINAL_SHIFT    (8U)
#define FLEXPWM_SM0_BIST_CTRL_CLK_FINAL_WIDTH    (5U)
#define FLEXPWM_SM0_BIST_CTRL_CLK_FINAL(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM0_BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM0_BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM0_BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM0_BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM0_BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM0_BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM0_BIST_CTRL1 - Submodule 0 BIST Control */
/*! @{ */

#define FLEXPWM_SM0_BIST_CTRL1_DATA_INITIAL_MASK (0x1FU)
#define FLEXPWM_SM0_BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM0_BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM0_BIST_CTRL1_DATA_INITIAL(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM0_BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM0_BIST_CTRL1_DATA_FINAL_MASK   (0x1F00U)
#define FLEXPWM_SM0_BIST_CTRL1_DATA_FINAL_SHIFT  (8U)
#define FLEXPWM_SM0_BIST_CTRL1_DATA_FINAL_WIDTH  (5U)
#define FLEXPWM_SM0_BIST_CTRL1_DATA_FINAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM0_BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM1_BIST_CTRL - Submodule 1 BIST Control */
/*! @{ */

#define FLEXPWM_SM1_BIST_CTRL_BIST_ENABLE_MASK   (0x1U)
#define FLEXPWM_SM1_BIST_CTRL_BIST_ENABLE_SHIFT  (0U)
#define FLEXPWM_SM1_BIST_CTRL_BIST_ENABLE_WIDTH  (1U)
#define FLEXPWM_SM1_BIST_CTRL_BIST_ENABLE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM1_BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM1_BIST_CTRL_CLK_INITIAL_MASK   (0x3EU)
#define FLEXPWM_SM1_BIST_CTRL_CLK_INITIAL_SHIFT  (1U)
#define FLEXPWM_SM1_BIST_CTRL_CLK_INITIAL_WIDTH  (5U)
#define FLEXPWM_SM1_BIST_CTRL_CLK_INITIAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM1_BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM1_BIST_CTRL_TOGGLE_MODE_MASK   (0x40U)
#define FLEXPWM_SM1_BIST_CTRL_TOGGLE_MODE_SHIFT  (6U)
#define FLEXPWM_SM1_BIST_CTRL_TOGGLE_MODE_WIDTH  (1U)
#define FLEXPWM_SM1_BIST_CTRL_TOGGLE_MODE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM1_BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM1_BIST_CTRL_MANUAL_TOGGLE_MASK (0x80U)
#define FLEXPWM_SM1_BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM1_BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM1_BIST_CTRL_MANUAL_TOGGLE(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM1_BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM1_BIST_CTRL_CLK_FINAL_MASK     (0x1F00U)
#define FLEXPWM_SM1_BIST_CTRL_CLK_FINAL_SHIFT    (8U)
#define FLEXPWM_SM1_BIST_CTRL_CLK_FINAL_WIDTH    (5U)
#define FLEXPWM_SM1_BIST_CTRL_CLK_FINAL(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM1_BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM1_BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM1_BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM1_BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM1_BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM1_BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM1_BIST_CTRL1 - Submodule 1 BIST Control */
/*! @{ */

#define FLEXPWM_SM1_BIST_CTRL1_DATA_INITIAL_MASK (0x1FU)
#define FLEXPWM_SM1_BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM1_BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM1_BIST_CTRL1_DATA_INITIAL(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM1_BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM1_BIST_CTRL1_DATA_FINAL_MASK   (0x1F00U)
#define FLEXPWM_SM1_BIST_CTRL1_DATA_FINAL_SHIFT  (8U)
#define FLEXPWM_SM1_BIST_CTRL1_DATA_FINAL_WIDTH  (5U)
#define FLEXPWM_SM1_BIST_CTRL1_DATA_FINAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM1_BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM2_BIST_CTRL - Submodule 2 BIST Control */
/*! @{ */

#define FLEXPWM_SM2_BIST_CTRL_BIST_ENABLE_MASK   (0x1U)
#define FLEXPWM_SM2_BIST_CTRL_BIST_ENABLE_SHIFT  (0U)
#define FLEXPWM_SM2_BIST_CTRL_BIST_ENABLE_WIDTH  (1U)
#define FLEXPWM_SM2_BIST_CTRL_BIST_ENABLE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM2_BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM2_BIST_CTRL_CLK_INITIAL_MASK   (0x3EU)
#define FLEXPWM_SM2_BIST_CTRL_CLK_INITIAL_SHIFT  (1U)
#define FLEXPWM_SM2_BIST_CTRL_CLK_INITIAL_WIDTH  (5U)
#define FLEXPWM_SM2_BIST_CTRL_CLK_INITIAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM2_BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM2_BIST_CTRL_TOGGLE_MODE_MASK   (0x40U)
#define FLEXPWM_SM2_BIST_CTRL_TOGGLE_MODE_SHIFT  (6U)
#define FLEXPWM_SM2_BIST_CTRL_TOGGLE_MODE_WIDTH  (1U)
#define FLEXPWM_SM2_BIST_CTRL_TOGGLE_MODE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM2_BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM2_BIST_CTRL_MANUAL_TOGGLE_MASK (0x80U)
#define FLEXPWM_SM2_BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM2_BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM2_BIST_CTRL_MANUAL_TOGGLE(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM2_BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM2_BIST_CTRL_CLK_FINAL_MASK     (0x1F00U)
#define FLEXPWM_SM2_BIST_CTRL_CLK_FINAL_SHIFT    (8U)
#define FLEXPWM_SM2_BIST_CTRL_CLK_FINAL_WIDTH    (5U)
#define FLEXPWM_SM2_BIST_CTRL_CLK_FINAL(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM2_BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM2_BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM2_BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM2_BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM2_BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM2_BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM2_BIST_CTRL1 - Submodule 2 BIST Control */
/*! @{ */

#define FLEXPWM_SM2_BIST_CTRL1_DATA_INITIAL_MASK (0x1FU)
#define FLEXPWM_SM2_BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM2_BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM2_BIST_CTRL1_DATA_INITIAL(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM2_BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM2_BIST_CTRL1_DATA_FINAL_MASK   (0x1F00U)
#define FLEXPWM_SM2_BIST_CTRL1_DATA_FINAL_SHIFT  (8U)
#define FLEXPWM_SM2_BIST_CTRL1_DATA_FINAL_WIDTH  (5U)
#define FLEXPWM_SM2_BIST_CTRL1_DATA_FINAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM2_BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM3_BIST_CTRL - Submodule 3 BIST Control */
/*! @{ */

#define FLEXPWM_SM3_BIST_CTRL_BIST_ENABLE_MASK   (0x1U)
#define FLEXPWM_SM3_BIST_CTRL_BIST_ENABLE_SHIFT  (0U)
#define FLEXPWM_SM3_BIST_CTRL_BIST_ENABLE_WIDTH  (1U)
#define FLEXPWM_SM3_BIST_CTRL_BIST_ENABLE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM3_BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM3_BIST_CTRL_CLK_INITIAL_MASK   (0x3EU)
#define FLEXPWM_SM3_BIST_CTRL_CLK_INITIAL_SHIFT  (1U)
#define FLEXPWM_SM3_BIST_CTRL_CLK_INITIAL_WIDTH  (5U)
#define FLEXPWM_SM3_BIST_CTRL_CLK_INITIAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM3_BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM3_BIST_CTRL_TOGGLE_MODE_MASK   (0x40U)
#define FLEXPWM_SM3_BIST_CTRL_TOGGLE_MODE_SHIFT  (6U)
#define FLEXPWM_SM3_BIST_CTRL_TOGGLE_MODE_WIDTH  (1U)
#define FLEXPWM_SM3_BIST_CTRL_TOGGLE_MODE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM3_BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM3_BIST_CTRL_MANUAL_TOGGLE_MASK (0x80U)
#define FLEXPWM_SM3_BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM3_BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM3_BIST_CTRL_MANUAL_TOGGLE(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM3_BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM3_BIST_CTRL_CLK_FINAL_MASK     (0x1F00U)
#define FLEXPWM_SM3_BIST_CTRL_CLK_FINAL_SHIFT    (8U)
#define FLEXPWM_SM3_BIST_CTRL_CLK_FINAL_WIDTH    (5U)
#define FLEXPWM_SM3_BIST_CTRL_CLK_FINAL(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM3_BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM3_BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM3_BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM3_BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM3_BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM3_BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM3_BIST_CTRL1 - Submodule 3 BIST Control */
/*! @{ */

#define FLEXPWM_SM3_BIST_CTRL1_DATA_INITIAL_MASK (0x1FU)
#define FLEXPWM_SM3_BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM3_BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM3_BIST_CTRL1_DATA_INITIAL(x)   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM3_BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM3_BIST_CTRL1_DATA_FINAL_MASK   (0x1F00U)
#define FLEXPWM_SM3_BIST_CTRL1_DATA_FINAL_SHIFT  (8U)
#define FLEXPWM_SM3_BIST_CTRL1_DATA_FINAL_WIDTH  (5U)
#define FLEXPWM_SM3_BIST_CTRL1_DATA_FINAL(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM3_BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM0_BIST_STATUS - Submodule 0 BIST Status */
/*! @{ */

#define FLEXPWM_SM0_BIST_STATUS_BIST_DONE_MASK   (0x1U)
#define FLEXPWM_SM0_BIST_STATUS_BIST_DONE_SHIFT  (0U)
#define FLEXPWM_SM0_BIST_STATUS_BIST_DONE_WIDTH  (1U)
#define FLEXPWM_SM0_BIST_STATUS_BIST_DONE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM0_BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM0_BIST_STATUS_BIST_PASS_MASK   (0x2U)
#define FLEXPWM_SM0_BIST_STATUS_BIST_PASS_SHIFT  (1U)
#define FLEXPWM_SM0_BIST_STATUS_BIST_PASS_WIDTH  (1U)
#define FLEXPWM_SM0_BIST_STATUS_BIST_PASS(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM0_BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM0_BIST_STATUS_FAIL_CLK_MASK    (0x1F00U)
#define FLEXPWM_SM0_BIST_STATUS_FAIL_CLK_SHIFT   (8U)
#define FLEXPWM_SM0_BIST_STATUS_FAIL_CLK_WIDTH   (5U)
#define FLEXPWM_SM0_BIST_STATUS_FAIL_CLK(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM0_BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM0_BIST_STATUS1 - Submodule 0 BIST Status */
/*! @{ */

#define FLEXPWM_SM0_BIST_STATUS1_FAIL_DATA_MASK  (0x1FU)
#define FLEXPWM_SM0_BIST_STATUS1_FAIL_DATA_SHIFT (0U)
#define FLEXPWM_SM0_BIST_STATUS1_FAIL_DATA_WIDTH (5U)
#define FLEXPWM_SM0_BIST_STATUS1_FAIL_DATA(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0_BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM0_BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*! @name SM1_BIST_STATUS - Submodule 1 BIST Status */
/*! @{ */

#define FLEXPWM_SM1_BIST_STATUS_BIST_DONE_MASK   (0x1U)
#define FLEXPWM_SM1_BIST_STATUS_BIST_DONE_SHIFT  (0U)
#define FLEXPWM_SM1_BIST_STATUS_BIST_DONE_WIDTH  (1U)
#define FLEXPWM_SM1_BIST_STATUS_BIST_DONE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM1_BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM1_BIST_STATUS_BIST_PASS_MASK   (0x2U)
#define FLEXPWM_SM1_BIST_STATUS_BIST_PASS_SHIFT  (1U)
#define FLEXPWM_SM1_BIST_STATUS_BIST_PASS_WIDTH  (1U)
#define FLEXPWM_SM1_BIST_STATUS_BIST_PASS(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM1_BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM1_BIST_STATUS_FAIL_CLK_MASK    (0x1F00U)
#define FLEXPWM_SM1_BIST_STATUS_FAIL_CLK_SHIFT   (8U)
#define FLEXPWM_SM1_BIST_STATUS_FAIL_CLK_WIDTH   (5U)
#define FLEXPWM_SM1_BIST_STATUS_FAIL_CLK(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM1_BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM1_BIST_STATUS1 - Submodule 1 BIST Status */
/*! @{ */

#define FLEXPWM_SM1_BIST_STATUS1_FAIL_DATA_MASK  (0x1FU)
#define FLEXPWM_SM1_BIST_STATUS1_FAIL_DATA_SHIFT (0U)
#define FLEXPWM_SM1_BIST_STATUS1_FAIL_DATA_WIDTH (5U)
#define FLEXPWM_SM1_BIST_STATUS1_FAIL_DATA(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1_BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM1_BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*! @name SM2_BIST_STATUS - Submodule 2 BIST Status */
/*! @{ */

#define FLEXPWM_SM2_BIST_STATUS_BIST_DONE_MASK   (0x1U)
#define FLEXPWM_SM2_BIST_STATUS_BIST_DONE_SHIFT  (0U)
#define FLEXPWM_SM2_BIST_STATUS_BIST_DONE_WIDTH  (1U)
#define FLEXPWM_SM2_BIST_STATUS_BIST_DONE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM2_BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM2_BIST_STATUS_BIST_PASS_MASK   (0x2U)
#define FLEXPWM_SM2_BIST_STATUS_BIST_PASS_SHIFT  (1U)
#define FLEXPWM_SM2_BIST_STATUS_BIST_PASS_WIDTH  (1U)
#define FLEXPWM_SM2_BIST_STATUS_BIST_PASS(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM2_BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM2_BIST_STATUS_FAIL_CLK_MASK    (0x1F00U)
#define FLEXPWM_SM2_BIST_STATUS_FAIL_CLK_SHIFT   (8U)
#define FLEXPWM_SM2_BIST_STATUS_FAIL_CLK_WIDTH   (5U)
#define FLEXPWM_SM2_BIST_STATUS_FAIL_CLK(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM2_BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM2_BIST_STATUS1 - Submodule 2 BIST Status */
/*! @{ */

#define FLEXPWM_SM2_BIST_STATUS1_FAIL_DATA_MASK  (0x1FU)
#define FLEXPWM_SM2_BIST_STATUS1_FAIL_DATA_SHIFT (0U)
#define FLEXPWM_SM2_BIST_STATUS1_FAIL_DATA_WIDTH (5U)
#define FLEXPWM_SM2_BIST_STATUS1_FAIL_DATA(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2_BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM2_BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*! @name SM3_BIST_STATUS - Submodule 3 BIST Status */
/*! @{ */

#define FLEXPWM_SM3_BIST_STATUS_BIST_DONE_MASK   (0x1U)
#define FLEXPWM_SM3_BIST_STATUS_BIST_DONE_SHIFT  (0U)
#define FLEXPWM_SM3_BIST_STATUS_BIST_DONE_WIDTH  (1U)
#define FLEXPWM_SM3_BIST_STATUS_BIST_DONE(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM3_BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM3_BIST_STATUS_BIST_PASS_MASK   (0x2U)
#define FLEXPWM_SM3_BIST_STATUS_BIST_PASS_SHIFT  (1U)
#define FLEXPWM_SM3_BIST_STATUS_BIST_PASS_WIDTH  (1U)
#define FLEXPWM_SM3_BIST_STATUS_BIST_PASS(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM3_BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM3_BIST_STATUS_FAIL_CLK_MASK    (0x1F00U)
#define FLEXPWM_SM3_BIST_STATUS_FAIL_CLK_SHIFT   (8U)
#define FLEXPWM_SM3_BIST_STATUS_FAIL_CLK_WIDTH   (5U)
#define FLEXPWM_SM3_BIST_STATUS_FAIL_CLK(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM3_BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM3_BIST_STATUS1 - Submodule 3 BIST Status */
/*! @{ */

#define FLEXPWM_SM3_BIST_STATUS1_FAIL_DATA_MASK  (0x1FU)
#define FLEXPWM_SM3_BIST_STATUS1_FAIL_DATA_SHIFT (0U)
#define FLEXPWM_SM3_BIST_STATUS1_FAIL_DATA_WIDTH (5U)
#define FLEXPWM_SM3_BIST_STATUS1_FAIL_DATA(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3_BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM3_BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group FLEXPWM_Register_Masks */

/*!
 * @}
 */ /* end of group FLEXPWM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_FLEXPWM_H_) */
