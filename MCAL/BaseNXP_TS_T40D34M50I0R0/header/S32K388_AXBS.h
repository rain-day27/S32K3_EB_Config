/*
** ###################################################################
**     Processor:           S32K388_M7
**     Reference manual:    S32K3xx RM Rev.8 Draft B
**     Version:             rev. 1.3, 2023-09-12
**     Build:               b230922
**
**     Abstract:
**         Peripheral Access Layer for S32K388_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
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
 * @file S32K388_AXBS.h
 * @version 1.3
 * @date 2023-09-12
 * @brief Peripheral Access Layer for S32K388_AXBS
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
#if !defined(S32K388_AXBS_H_)  /* Check if memory map has not been already included */
#define S32K388_AXBS_H_

#include "S32K388_COMMON.h"

/* ----------------------------------------------------------------------------
   -- AXBS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Peripheral_Access_Layer AXBS Peripheral Access Layer
 * @{
 */

/** AXBS - Register Layout Typedef */
typedef struct {
  __IO uint32_t PRS0;                              /**< Priority Slave Registers, offset: 0x0 */
  uint8_t RESERVED_0[12];
  __IO uint32_t CRS0;                              /**< Control Register, offset: 0x10 */
  uint8_t RESERVED_1[236];
  __IO uint32_t PRS1;                              /**< Priority Slave Registers, offset: 0x100 */
  uint8_t RESERVED_2[12];
  __IO uint32_t CRS1;                              /**< Control Register, offset: 0x110 */
  uint8_t RESERVED_3[236];
  __IO uint32_t PRS2;                              /**< Priority Slave Registers, offset: 0x200 */
  uint8_t RESERVED_4[12];
  __IO uint32_t CRS2;                              /**< Control Register, offset: 0x210 */
  uint8_t RESERVED_5[236];
  __IO uint32_t PRS3;                              /**< Priority Slave Registers, offset: 0x300 */
  uint8_t RESERVED_6[12];
  __IO uint32_t CRS3;                              /**< Control Register, offset: 0x310 */
  uint8_t RESERVED_7[236];
  __IO uint32_t PRS4;                              /**< Priority Slave Registers, offset: 0x400 */
  uint8_t RESERVED_8[12];
  __IO uint32_t CRS4;                              /**< Control Register, offset: 0x410 */
  uint8_t RESERVED_9[236];
  __IO uint32_t PRS5;                              /**< Priority Slave Registers, offset: 0x500 */
  uint8_t RESERVED_10[12];
  __IO uint32_t CRS5;                              /**< Control Register, offset: 0x510 */
  uint8_t RESERVED_11[236];
  __IO uint32_t PRS6;                              /**< Priority Slave Registers, offset: 0x600 */
  uint8_t RESERVED_12[12];
  __IO uint32_t CRS6;                              /**< Control Register, offset: 0x610 */
  uint8_t RESERVED_13[236];
  __IO uint32_t PRS7;                              /**< Priority Slave Registers, offset: 0x700 */
  uint8_t RESERVED_14[12];
  __IO uint32_t CRS7;                              /**< Control Register, offset: 0x710 */
} AXBS_Type, *AXBS_MemMapPtr;

/** Number of instances of the AXBS module. */
#define AXBS_INSTANCE_COUNT                      (2u)

/* AXBS - Peripheral instance base addresses */
/** Peripheral AXBS_FEED base address */
#define IP_AXBS_FEED_BASE                        (0u)
/** Peripheral AXBS_FEED base pointer */
#define IP_AXBS_FEED                             ((AXBS_Type *)IP_AXBS_FEED_BASE)
/** Peripheral AXBS_RESULT base address */
#define IP_AXBS_RESULT_BASE                      (0u)
/** Peripheral AXBS_RESULT base pointer */
#define IP_AXBS_RESULT                           ((AXBS_Type *)IP_AXBS_RESULT_BASE)
/** Array initializer of AXBS peripheral base addresses */
#define IP_AXBS_BASE_ADDRS                       { IP_AXBS_FEED_BASE, IP_AXBS_RESULT_BASE }
/** Array initializer of AXBS peripheral base pointers */
#define IP_AXBS_BASE_PTRS                        { IP_AXBS_FEED, IP_AXBS_RESULT }

/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Register_Masks AXBS Register Masks
 * @{
 */

/*! @name PRS0 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS0_M0_MASK                        (0x7U)
#define AXBS_PRS0_M0_SHIFT                       (0U)
#define AXBS_PRS0_M0_WIDTH                       (3U)
#define AXBS_PRS0_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M0_SHIFT)) & AXBS_PRS0_M0_MASK)

#define AXBS_PRS0_M1_MASK                        (0x70U)
#define AXBS_PRS0_M1_SHIFT                       (4U)
#define AXBS_PRS0_M1_WIDTH                       (3U)
#define AXBS_PRS0_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M1_SHIFT)) & AXBS_PRS0_M1_MASK)
/*! @} */

/*! @name CRS0 - Control Register */
/*! @{ */

#define AXBS_CRS0_PARK_MASK                      (0x7U)
#define AXBS_CRS0_PARK_SHIFT                     (0U)
#define AXBS_CRS0_PARK_WIDTH                     (3U)
#define AXBS_CRS0_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_PARK_SHIFT)) & AXBS_CRS0_PARK_MASK)

#define AXBS_CRS0_PCTL_MASK                      (0x30U)
#define AXBS_CRS0_PCTL_SHIFT                     (4U)
#define AXBS_CRS0_PCTL_WIDTH                     (2U)
#define AXBS_CRS0_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_PCTL_SHIFT)) & AXBS_CRS0_PCTL_MASK)

#define AXBS_CRS0_ARB_MASK                       (0x300U)
#define AXBS_CRS0_ARB_SHIFT                      (8U)
#define AXBS_CRS0_ARB_WIDTH                      (2U)
#define AXBS_CRS0_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_ARB_SHIFT)) & AXBS_CRS0_ARB_MASK)

#define AXBS_CRS0_HLP_MASK                       (0x40000000U)
#define AXBS_CRS0_HLP_SHIFT                      (30U)
#define AXBS_CRS0_HLP_WIDTH                      (1U)
#define AXBS_CRS0_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_HLP_SHIFT)) & AXBS_CRS0_HLP_MASK)

#define AXBS_CRS0_RO_MASK                        (0x80000000U)
#define AXBS_CRS0_RO_SHIFT                       (31U)
#define AXBS_CRS0_RO_WIDTH                       (1U)
#define AXBS_CRS0_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_RO_SHIFT)) & AXBS_CRS0_RO_MASK)
/*! @} */

/*! @name PRS1 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS1_M0_MASK                        (0x7U)
#define AXBS_PRS1_M0_SHIFT                       (0U)
#define AXBS_PRS1_M0_WIDTH                       (3U)
#define AXBS_PRS1_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M0_SHIFT)) & AXBS_PRS1_M0_MASK)

#define AXBS_PRS1_M1_MASK                        (0x70U)
#define AXBS_PRS1_M1_SHIFT                       (4U)
#define AXBS_PRS1_M1_WIDTH                       (3U)
#define AXBS_PRS1_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M1_SHIFT)) & AXBS_PRS1_M1_MASK)
/*! @} */

/*! @name CRS1 - Control Register */
/*! @{ */

#define AXBS_CRS1_PARK_MASK                      (0x7U)
#define AXBS_CRS1_PARK_SHIFT                     (0U)
#define AXBS_CRS1_PARK_WIDTH                     (3U)
#define AXBS_CRS1_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_PARK_SHIFT)) & AXBS_CRS1_PARK_MASK)

#define AXBS_CRS1_PCTL_MASK                      (0x30U)
#define AXBS_CRS1_PCTL_SHIFT                     (4U)
#define AXBS_CRS1_PCTL_WIDTH                     (2U)
#define AXBS_CRS1_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_PCTL_SHIFT)) & AXBS_CRS1_PCTL_MASK)

#define AXBS_CRS1_ARB_MASK                       (0x300U)
#define AXBS_CRS1_ARB_SHIFT                      (8U)
#define AXBS_CRS1_ARB_WIDTH                      (2U)
#define AXBS_CRS1_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_ARB_SHIFT)) & AXBS_CRS1_ARB_MASK)

#define AXBS_CRS1_HLP_MASK                       (0x40000000U)
#define AXBS_CRS1_HLP_SHIFT                      (30U)
#define AXBS_CRS1_HLP_WIDTH                      (1U)
#define AXBS_CRS1_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_HLP_SHIFT)) & AXBS_CRS1_HLP_MASK)

#define AXBS_CRS1_RO_MASK                        (0x80000000U)
#define AXBS_CRS1_RO_SHIFT                       (31U)
#define AXBS_CRS1_RO_WIDTH                       (1U)
#define AXBS_CRS1_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_RO_SHIFT)) & AXBS_CRS1_RO_MASK)
/*! @} */

/*! @name PRS2 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS2_M0_MASK                        (0x7U)
#define AXBS_PRS2_M0_SHIFT                       (0U)
#define AXBS_PRS2_M0_WIDTH                       (3U)
#define AXBS_PRS2_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M0_SHIFT)) & AXBS_PRS2_M0_MASK)

#define AXBS_PRS2_M1_MASK                        (0x70U)
#define AXBS_PRS2_M1_SHIFT                       (4U)
#define AXBS_PRS2_M1_WIDTH                       (3U)
#define AXBS_PRS2_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M1_SHIFT)) & AXBS_PRS2_M1_MASK)
/*! @} */

/*! @name CRS2 - Control Register */
/*! @{ */

#define AXBS_CRS2_PARK_MASK                      (0x7U)
#define AXBS_CRS2_PARK_SHIFT                     (0U)
#define AXBS_CRS2_PARK_WIDTH                     (3U)
#define AXBS_CRS2_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_PARK_SHIFT)) & AXBS_CRS2_PARK_MASK)

#define AXBS_CRS2_PCTL_MASK                      (0x30U)
#define AXBS_CRS2_PCTL_SHIFT                     (4U)
#define AXBS_CRS2_PCTL_WIDTH                     (2U)
#define AXBS_CRS2_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_PCTL_SHIFT)) & AXBS_CRS2_PCTL_MASK)

#define AXBS_CRS2_ARB_MASK                       (0x300U)
#define AXBS_CRS2_ARB_SHIFT                      (8U)
#define AXBS_CRS2_ARB_WIDTH                      (2U)
#define AXBS_CRS2_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_ARB_SHIFT)) & AXBS_CRS2_ARB_MASK)

#define AXBS_CRS2_HLP_MASK                       (0x40000000U)
#define AXBS_CRS2_HLP_SHIFT                      (30U)
#define AXBS_CRS2_HLP_WIDTH                      (1U)
#define AXBS_CRS2_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_HLP_SHIFT)) & AXBS_CRS2_HLP_MASK)

#define AXBS_CRS2_RO_MASK                        (0x80000000U)
#define AXBS_CRS2_RO_SHIFT                       (31U)
#define AXBS_CRS2_RO_WIDTH                       (1U)
#define AXBS_CRS2_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_RO_SHIFT)) & AXBS_CRS2_RO_MASK)
/*! @} */

/*! @name PRS3 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS3_M0_MASK                        (0x7U)
#define AXBS_PRS3_M0_SHIFT                       (0U)
#define AXBS_PRS3_M0_WIDTH                       (3U)
#define AXBS_PRS3_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M0_SHIFT)) & AXBS_PRS3_M0_MASK)

#define AXBS_PRS3_M1_MASK                        (0x70U)
#define AXBS_PRS3_M1_SHIFT                       (4U)
#define AXBS_PRS3_M1_WIDTH                       (3U)
#define AXBS_PRS3_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M1_SHIFT)) & AXBS_PRS3_M1_MASK)
/*! @} */

/*! @name CRS3 - Control Register */
/*! @{ */

#define AXBS_CRS3_PARK_MASK                      (0x7U)
#define AXBS_CRS3_PARK_SHIFT                     (0U)
#define AXBS_CRS3_PARK_WIDTH                     (3U)
#define AXBS_CRS3_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_PARK_SHIFT)) & AXBS_CRS3_PARK_MASK)

#define AXBS_CRS3_PCTL_MASK                      (0x30U)
#define AXBS_CRS3_PCTL_SHIFT                     (4U)
#define AXBS_CRS3_PCTL_WIDTH                     (2U)
#define AXBS_CRS3_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_PCTL_SHIFT)) & AXBS_CRS3_PCTL_MASK)

#define AXBS_CRS3_ARB_MASK                       (0x300U)
#define AXBS_CRS3_ARB_SHIFT                      (8U)
#define AXBS_CRS3_ARB_WIDTH                      (2U)
#define AXBS_CRS3_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_ARB_SHIFT)) & AXBS_CRS3_ARB_MASK)

#define AXBS_CRS3_HLP_MASK                       (0x40000000U)
#define AXBS_CRS3_HLP_SHIFT                      (30U)
#define AXBS_CRS3_HLP_WIDTH                      (1U)
#define AXBS_CRS3_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_HLP_SHIFT)) & AXBS_CRS3_HLP_MASK)

#define AXBS_CRS3_RO_MASK                        (0x80000000U)
#define AXBS_CRS3_RO_SHIFT                       (31U)
#define AXBS_CRS3_RO_WIDTH                       (1U)
#define AXBS_CRS3_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_RO_SHIFT)) & AXBS_CRS3_RO_MASK)
/*! @} */

/*! @name PRS4 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS4_M0_MASK                        (0x7U)
#define AXBS_PRS4_M0_SHIFT                       (0U)
#define AXBS_PRS4_M0_WIDTH                       (3U)
#define AXBS_PRS4_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M0_SHIFT)) & AXBS_PRS4_M0_MASK)

#define AXBS_PRS4_M1_MASK                        (0x70U)
#define AXBS_PRS4_M1_SHIFT                       (4U)
#define AXBS_PRS4_M1_WIDTH                       (3U)
#define AXBS_PRS4_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M1_SHIFT)) & AXBS_PRS4_M1_MASK)
/*! @} */

/*! @name CRS4 - Control Register */
/*! @{ */

#define AXBS_CRS4_PARK_MASK                      (0x7U)
#define AXBS_CRS4_PARK_SHIFT                     (0U)
#define AXBS_CRS4_PARK_WIDTH                     (3U)
#define AXBS_CRS4_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_PARK_SHIFT)) & AXBS_CRS4_PARK_MASK)

#define AXBS_CRS4_PCTL_MASK                      (0x30U)
#define AXBS_CRS4_PCTL_SHIFT                     (4U)
#define AXBS_CRS4_PCTL_WIDTH                     (2U)
#define AXBS_CRS4_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_PCTL_SHIFT)) & AXBS_CRS4_PCTL_MASK)

#define AXBS_CRS4_ARB_MASK                       (0x300U)
#define AXBS_CRS4_ARB_SHIFT                      (8U)
#define AXBS_CRS4_ARB_WIDTH                      (2U)
#define AXBS_CRS4_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_ARB_SHIFT)) & AXBS_CRS4_ARB_MASK)

#define AXBS_CRS4_HLP_MASK                       (0x40000000U)
#define AXBS_CRS4_HLP_SHIFT                      (30U)
#define AXBS_CRS4_HLP_WIDTH                      (1U)
#define AXBS_CRS4_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_HLP_SHIFT)) & AXBS_CRS4_HLP_MASK)

#define AXBS_CRS4_RO_MASK                        (0x80000000U)
#define AXBS_CRS4_RO_SHIFT                       (31U)
#define AXBS_CRS4_RO_WIDTH                       (1U)
#define AXBS_CRS4_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_RO_SHIFT)) & AXBS_CRS4_RO_MASK)
/*! @} */

/*! @name PRS5 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS5_M0_MASK                        (0x7U)
#define AXBS_PRS5_M0_SHIFT                       (0U)
#define AXBS_PRS5_M0_WIDTH                       (3U)
#define AXBS_PRS5_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M0_SHIFT)) & AXBS_PRS5_M0_MASK)

#define AXBS_PRS5_M1_MASK                        (0x70U)
#define AXBS_PRS5_M1_SHIFT                       (4U)
#define AXBS_PRS5_M1_WIDTH                       (3U)
#define AXBS_PRS5_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M1_SHIFT)) & AXBS_PRS5_M1_MASK)
/*! @} */

/*! @name CRS5 - Control Register */
/*! @{ */

#define AXBS_CRS5_PARK_MASK                      (0x7U)
#define AXBS_CRS5_PARK_SHIFT                     (0U)
#define AXBS_CRS5_PARK_WIDTH                     (3U)
#define AXBS_CRS5_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_PARK_SHIFT)) & AXBS_CRS5_PARK_MASK)

#define AXBS_CRS5_PCTL_MASK                      (0x30U)
#define AXBS_CRS5_PCTL_SHIFT                     (4U)
#define AXBS_CRS5_PCTL_WIDTH                     (2U)
#define AXBS_CRS5_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_PCTL_SHIFT)) & AXBS_CRS5_PCTL_MASK)

#define AXBS_CRS5_ARB_MASK                       (0x300U)
#define AXBS_CRS5_ARB_SHIFT                      (8U)
#define AXBS_CRS5_ARB_WIDTH                      (2U)
#define AXBS_CRS5_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_ARB_SHIFT)) & AXBS_CRS5_ARB_MASK)

#define AXBS_CRS5_HLP_MASK                       (0x40000000U)
#define AXBS_CRS5_HLP_SHIFT                      (30U)
#define AXBS_CRS5_HLP_WIDTH                      (1U)
#define AXBS_CRS5_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_HLP_SHIFT)) & AXBS_CRS5_HLP_MASK)

#define AXBS_CRS5_RO_MASK                        (0x80000000U)
#define AXBS_CRS5_RO_SHIFT                       (31U)
#define AXBS_CRS5_RO_WIDTH                       (1U)
#define AXBS_CRS5_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_RO_SHIFT)) & AXBS_CRS5_RO_MASK)
/*! @} */

/*! @name PRS6 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS6_M0_MASK                        (0x7U)
#define AXBS_PRS6_M0_SHIFT                       (0U)
#define AXBS_PRS6_M0_WIDTH                       (3U)
#define AXBS_PRS6_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M0_SHIFT)) & AXBS_PRS6_M0_MASK)

#define AXBS_PRS6_M1_MASK                        (0x70U)
#define AXBS_PRS6_M1_SHIFT                       (4U)
#define AXBS_PRS6_M1_WIDTH                       (3U)
#define AXBS_PRS6_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M1_SHIFT)) & AXBS_PRS6_M1_MASK)
/*! @} */

/*! @name CRS6 - Control Register */
/*! @{ */

#define AXBS_CRS6_PARK_MASK                      (0x7U)
#define AXBS_CRS6_PARK_SHIFT                     (0U)
#define AXBS_CRS6_PARK_WIDTH                     (3U)
#define AXBS_CRS6_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_PARK_SHIFT)) & AXBS_CRS6_PARK_MASK)

#define AXBS_CRS6_PCTL_MASK                      (0x30U)
#define AXBS_CRS6_PCTL_SHIFT                     (4U)
#define AXBS_CRS6_PCTL_WIDTH                     (2U)
#define AXBS_CRS6_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_PCTL_SHIFT)) & AXBS_CRS6_PCTL_MASK)

#define AXBS_CRS6_ARB_MASK                       (0x300U)
#define AXBS_CRS6_ARB_SHIFT                      (8U)
#define AXBS_CRS6_ARB_WIDTH                      (2U)
#define AXBS_CRS6_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_ARB_SHIFT)) & AXBS_CRS6_ARB_MASK)

#define AXBS_CRS6_HLP_MASK                       (0x40000000U)
#define AXBS_CRS6_HLP_SHIFT                      (30U)
#define AXBS_CRS6_HLP_WIDTH                      (1U)
#define AXBS_CRS6_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_HLP_SHIFT)) & AXBS_CRS6_HLP_MASK)

#define AXBS_CRS6_RO_MASK                        (0x80000000U)
#define AXBS_CRS6_RO_SHIFT                       (31U)
#define AXBS_CRS6_RO_WIDTH                       (1U)
#define AXBS_CRS6_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_RO_SHIFT)) & AXBS_CRS6_RO_MASK)
/*! @} */

/*! @name PRS7 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS7_M0_MASK                        (0x7U)
#define AXBS_PRS7_M0_SHIFT                       (0U)
#define AXBS_PRS7_M0_WIDTH                       (3U)
#define AXBS_PRS7_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M0_SHIFT)) & AXBS_PRS7_M0_MASK)

#define AXBS_PRS7_M1_MASK                        (0x70U)
#define AXBS_PRS7_M1_SHIFT                       (4U)
#define AXBS_PRS7_M1_WIDTH                       (3U)
#define AXBS_PRS7_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M1_SHIFT)) & AXBS_PRS7_M1_MASK)
/*! @} */

/*! @name CRS7 - Control Register */
/*! @{ */

#define AXBS_CRS7_PARK_MASK                      (0x7U)
#define AXBS_CRS7_PARK_SHIFT                     (0U)
#define AXBS_CRS7_PARK_WIDTH                     (3U)
#define AXBS_CRS7_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_PARK_SHIFT)) & AXBS_CRS7_PARK_MASK)

#define AXBS_CRS7_PCTL_MASK                      (0x30U)
#define AXBS_CRS7_PCTL_SHIFT                     (4U)
#define AXBS_CRS7_PCTL_WIDTH                     (2U)
#define AXBS_CRS7_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_PCTL_SHIFT)) & AXBS_CRS7_PCTL_MASK)

#define AXBS_CRS7_ARB_MASK                       (0x300U)
#define AXBS_CRS7_ARB_SHIFT                      (8U)
#define AXBS_CRS7_ARB_WIDTH                      (2U)
#define AXBS_CRS7_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_ARB_SHIFT)) & AXBS_CRS7_ARB_MASK)

#define AXBS_CRS7_HLP_MASK                       (0x40000000U)
#define AXBS_CRS7_HLP_SHIFT                      (30U)
#define AXBS_CRS7_HLP_WIDTH                      (1U)
#define AXBS_CRS7_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_HLP_SHIFT)) & AXBS_CRS7_HLP_MASK)

#define AXBS_CRS7_RO_MASK                        (0x80000000U)
#define AXBS_CRS7_RO_SHIFT                       (31U)
#define AXBS_CRS7_RO_WIDTH                       (1U)
#define AXBS_CRS7_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_RO_SHIFT)) & AXBS_CRS7_RO_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group AXBS_Register_Masks */

/*!
 * @}
 */ /* end of group AXBS_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K388_AXBS_H_) */
