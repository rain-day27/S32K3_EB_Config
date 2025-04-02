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
 * @file S32K39_CONFIGURATION_GPR.h
 * @version 2.0
 * @date 2024-03-27
 * @brief Peripheral Access Layer for S32K39_CONFIGURATION_GPR
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
#if !defined(S32K39_CONFIGURATION_GPR_H_)  /* Check if memory map has not been already included */
#define S32K39_CONFIGURATION_GPR_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CONFIGURATION_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_GPR_Peripheral_Access_Layer CONFIGURATION_GPR Peripheral Access Layer
 * @{
 */

/** CONFIGURATION_GPR - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[28];
  __I  uint32_t CONFIG_REG0;                       /**< General Purpose Configuration 0, offset: 0x1C */
  uint8_t RESERVED_1[20];
  __I  uint32_t CONFIG_REG6;                       /**< General Purpose Configuration 6, offset: 0x34 */
  uint8_t RESERVED_2[44];
  __IO uint32_t CONFIG_REG_GPR;                    /**< Configuration REG_GPR, offset: 0x64 */
} CONFIGURATION_GPR_Type, *CONFIGURATION_GPR_MemMapPtr;

/** Number of instances of the CONFIGURATION_GPR module. */
#define CONFIGURATION_GPR_INSTANCE_COUNT         (1u)

/* CONFIGURATION_GPR - Peripheral instance base addresses */
/** Peripheral CONFIGURATION_GPR base address */
#define IP_CONFIGURATION_GPR_BASE                (0x4039C000u)
/** Peripheral CONFIGURATION_GPR base pointer */
#define IP_CONFIGURATION_GPR                     ((CONFIGURATION_GPR_Type *)IP_CONFIGURATION_GPR_BASE)
/** Array initializer of CONFIGURATION_GPR peripheral base addresses */
#define IP_CONFIGURATION_GPR_BASE_ADDRS          { IP_CONFIGURATION_GPR_BASE }
/** Array initializer of CONFIGURATION_GPR peripheral base pointers */
#define IP_CONFIGURATION_GPR_BASE_PTRS           { IP_CONFIGURATION_GPR }

/* ----------------------------------------------------------------------------
   -- CONFIGURATION_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_GPR_Register_Masks CONFIGURATION_GPR Register Masks
 * @{
 */

/*! @name CONFIG_REG0 - General Purpose Configuration 0 */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_REG0_EDB_MASK   (0x40U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB_SHIFT  (6U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB_WIDTH  (1U)
#define CONFIGURATION_GPR_CONFIG_REG0_EDB(x)     (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG0_EDB_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG0_EDB_MASK)
/*! @} */

/*! @name CONFIG_REG6 - General Purpose Configuration 6 */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_MASK (0x1U)
#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_SHIFT (0U)
#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_QUADSPI_SDID_PCTL_MASK)

#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_MASK (0x4U)
#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_SHIFT (2U)
#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_EMAC_CLOCK_GATE_MASK)

#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK (0x10U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT (4U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK)

#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_SHIFT (31U)
#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_WIDTH (1U)
#define CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG6_HARD_LOCK_MASK)
/*! @} */

/*! @name CONFIG_REG_GPR - Configuration REG_GPR */
/*! @{ */

#define CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK (0x3U)
#define CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_SHIFT (0U)
#define CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_WIDTH (2U)
#define CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK)

#define CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_MASK (0xE0000000U)
#define CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_SHIFT (29U)
#define CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_WIDTH (3U)
#define CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_SHIFT)) & CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CONFIGURATION_GPR_Register_Masks */

/*!
 * @}
 */ /* end of group CONFIGURATION_GPR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_CONFIGURATION_GPR_H_) */
