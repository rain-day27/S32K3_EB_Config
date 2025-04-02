/*
** ###################################################################
**     Processor:           S32K312
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K3xx RM Rev.4
**     Version:             rev. 1.4, 2022-06-20
**     Build:               b220620
**
**     Abstract:
**         Peripheral Access Layer for S32K312
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32K312_PMC.h
 * @version 1.4
 * @date 2022-06-20
 * @brief Peripheral Access Layer for S32K312_PMC
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
#if !defined(S32K312_PMC_H_)  /* Check if memory map has not been already included */
#define S32K312_PMC_H_

#include "S32K312_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t LVSC;                              /**< Low Voltage Status And Control, offset: 0x0 */
  __IO uint32_t CONFIG;                            /**< PMC Configuration, offset: 0x4 */
  uint8_t RESERVED_0[4];
  __I  uint32_t VERID;                             /**< Version ID, offset: 0xC */
} PMC_Type, *PMC_MemMapPtr;

/** Number of instances of the PMC module. */
#define PMC_INSTANCE_COUNT                       (1u)

/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define IP_PMC_BASE                              (0x402E8000u)
/** Peripheral PMC base pointer */
#define IP_PMC                                   ((PMC_Type *)IP_PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define IP_PMC_BASE_ADDRS                        { IP_PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define IP_PMC_BASE_PTRS                         { IP_PMC }

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name LVSC - Low Voltage Status And Control */
/*! @{ */

#define PMC_LVSC_HVDAF_MASK                      (0x1U)
#define PMC_LVSC_HVDAF_SHIFT                     (0U)
#define PMC_LVSC_HVDAF_WIDTH                     (1U)
#define PMC_LVSC_HVDAF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDAF_SHIFT)) & PMC_LVSC_HVDAF_MASK)

#define PMC_LVSC_HVD25F_MASK                     (0x4U)
#define PMC_LVSC_HVD25F_SHIFT                    (2U)
#define PMC_LVSC_HVD25F_WIDTH                    (1U)
#define PMC_LVSC_HVD25F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD25F_SHIFT)) & PMC_LVSC_HVD25F_MASK)

#define PMC_LVSC_HVD11F_MASK                     (0x8U)
#define PMC_LVSC_HVD11F_SHIFT                    (3U)
#define PMC_LVSC_HVD11F_WIDTH                    (1U)
#define PMC_LVSC_HVD11F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD11F_SHIFT)) & PMC_LVSC_HVD11F_MASK)

#define PMC_LVSC_LVD5AF_MASK                     (0x10U)
#define PMC_LVSC_LVD5AF_SHIFT                    (4U)
#define PMC_LVSC_LVD5AF_WIDTH                    (1U)
#define PMC_LVSC_LVD5AF(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD5AF_SHIFT)) & PMC_LVSC_LVD5AF_MASK)

#define PMC_LVSC_HVDAS_MASK                      (0x100U)
#define PMC_LVSC_HVDAS_SHIFT                     (8U)
#define PMC_LVSC_HVDAS_WIDTH                     (1U)
#define PMC_LVSC_HVDAS(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDAS_SHIFT)) & PMC_LVSC_HVDAS_MASK)

#define PMC_LVSC_HVD25S_MASK                     (0x400U)
#define PMC_LVSC_HVD25S_SHIFT                    (10U)
#define PMC_LVSC_HVD25S_WIDTH                    (1U)
#define PMC_LVSC_HVD25S(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD25S_SHIFT)) & PMC_LVSC_HVD25S_MASK)

#define PMC_LVSC_HVD11S_MASK                     (0x800U)
#define PMC_LVSC_HVD11S_SHIFT                    (11U)
#define PMC_LVSC_HVD11S_WIDTH                    (1U)
#define PMC_LVSC_HVD11S(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD11S_SHIFT)) & PMC_LVSC_HVD11S_MASK)

#define PMC_LVSC_LVD5AS_MASK                     (0x1000U)
#define PMC_LVSC_LVD5AS_SHIFT                    (12U)
#define PMC_LVSC_LVD5AS_WIDTH                    (1U)
#define PMC_LVSC_LVD5AS(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD5AS_SHIFT)) & PMC_LVSC_LVD5AS_MASK)

#define PMC_LVSC_LVRAF_MASK                      (0x10000U)
#define PMC_LVSC_LVRAF_SHIFT                     (16U)
#define PMC_LVSC_LVRAF_WIDTH                     (1U)
#define PMC_LVSC_LVRAF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRAF_SHIFT)) & PMC_LVSC_LVRAF_MASK)

#define PMC_LVSC_LVRALPF_MASK                    (0x20000U)
#define PMC_LVSC_LVRALPF_SHIFT                   (17U)
#define PMC_LVSC_LVRALPF_WIDTH                   (1U)
#define PMC_LVSC_LVRALPF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRALPF_SHIFT)) & PMC_LVSC_LVRALPF_MASK)

#define PMC_LVSC_LVR25F_MASK                     (0x100000U)
#define PMC_LVSC_LVR25F_SHIFT                    (20U)
#define PMC_LVSC_LVR25F_WIDTH                    (1U)
#define PMC_LVSC_LVR25F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR25F_SHIFT)) & PMC_LVSC_LVR25F_MASK)

#define PMC_LVSC_LVR25LPF_MASK                   (0x200000U)
#define PMC_LVSC_LVR25LPF_SHIFT                  (21U)
#define PMC_LVSC_LVR25LPF_WIDTH                  (1U)
#define PMC_LVSC_LVR25LPF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR25LPF_SHIFT)) & PMC_LVSC_LVR25LPF_MASK)

#define PMC_LVSC_LVR11F_MASK                     (0x400000U)
#define PMC_LVSC_LVR11F_SHIFT                    (22U)
#define PMC_LVSC_LVR11F_WIDTH                    (1U)
#define PMC_LVSC_LVR11F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR11F_SHIFT)) & PMC_LVSC_LVR11F_MASK)

#define PMC_LVSC_LVR11LPF_MASK                   (0x800000U)
#define PMC_LVSC_LVR11LPF_SHIFT                  (23U)
#define PMC_LVSC_LVR11LPF_WIDTH                  (1U)
#define PMC_LVSC_LVR11LPF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR11LPF_SHIFT)) & PMC_LVSC_LVR11LPF_MASK)

#define PMC_LVSC_GNG25OSCF_MASK                  (0x1000000U)
#define PMC_LVSC_GNG25OSCF_SHIFT                 (24U)
#define PMC_LVSC_GNG25OSCF_WIDTH                 (1U)
#define PMC_LVSC_GNG25OSCF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_GNG25OSCF_SHIFT)) & PMC_LVSC_GNG25OSCF_MASK)

#define PMC_LVSC_GNG11OSCF_MASK                  (0x2000000U)
#define PMC_LVSC_GNG11OSCF_SHIFT                 (25U)
#define PMC_LVSC_GNG11OSCF_WIDTH                 (1U)
#define PMC_LVSC_GNG11OSCF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_GNG11OSCF_SHIFT)) & PMC_LVSC_GNG11OSCF_MASK)

#define PMC_LVSC_PORF_MASK                       (0x80000000U)
#define PMC_LVSC_PORF_SHIFT                      (31U)
#define PMC_LVSC_PORF_WIDTH                      (1U)
#define PMC_LVSC_PORF(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_PORF_SHIFT)) & PMC_LVSC_PORF_MASK)
/*! @} */

/*! @name CONFIG - PMC Configuration */
/*! @{ */

#define PMC_CONFIG_FASTREC_MASK                  (0x4U)
#define PMC_CONFIG_FASTREC_SHIFT                 (2U)
#define PMC_CONFIG_FASTREC_WIDTH                 (1U)
#define PMC_CONFIG_FASTREC(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_FASTREC_SHIFT)) & PMC_CONFIG_FASTREC_MASK)

#define PMC_CONFIG_LPM25EN_MASK                  (0x8U)
#define PMC_CONFIG_LPM25EN_SHIFT                 (3U)
#define PMC_CONFIG_LPM25EN_WIDTH                 (1U)
#define PMC_CONFIG_LPM25EN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LPM25EN_SHIFT)) & PMC_CONFIG_LPM25EN_MASK)

#define PMC_CONFIG_HVDIE_MASK                    (0x100U)
#define PMC_CONFIG_HVDIE_SHIFT                   (8U)
#define PMC_CONFIG_HVDIE_WIDTH                   (1U)
#define PMC_CONFIG_HVDIE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_HVDIE_SHIFT)) & PMC_CONFIG_HVDIE_MASK)

#define PMC_CONFIG_LVDIE_MASK                    (0x200U)
#define PMC_CONFIG_LVDIE_SHIFT                   (9U)
#define PMC_CONFIG_LVDIE_WIDTH                   (1U)
#define PMC_CONFIG_LVDIE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LVDIE_SHIFT)) & PMC_CONFIG_LVDIE_MASK)
/*! @} */

/*! @name VERID - Version ID */
/*! @{ */

#define PMC_VERID_LMFEAT_MASK                    (0x1U)
#define PMC_VERID_LMFEAT_SHIFT                   (0U)
#define PMC_VERID_LMFEAT_WIDTH                   (1U)
#define PMC_VERID_LMFEAT(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_VERID_LMFEAT_SHIFT)) & PMC_VERID_LMFEAT_MASK)

#define PMC_VERID_MINOR_MASK                     (0xFF0000U)
#define PMC_VERID_MINOR_SHIFT                    (16U)
#define PMC_VERID_MINOR_WIDTH                    (8U)
#define PMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MINOR_SHIFT)) & PMC_VERID_MINOR_MASK)

#define PMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define PMC_VERID_MAJOR_SHIFT                    (24U)
#define PMC_VERID_MAJOR_WIDTH                    (8U)
#define PMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MAJOR_SHIFT)) & PMC_VERID_MAJOR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PMC_Register_Masks */

/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K312_PMC_H_) */
