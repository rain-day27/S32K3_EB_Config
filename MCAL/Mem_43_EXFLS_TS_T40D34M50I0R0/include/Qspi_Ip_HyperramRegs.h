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

#ifndef QSPI_IP_HYPERRAMREGS_H
#define QSPI_IP_HYPERRAMREGS_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HYPERRAMREGS_VENDOR_ID_H                    43
#define QSPI_IP_HYPERRAMREGS_AR_RELEASE_MAJOR_VERSION_H     4
#define QSPI_IP_HYPERRAMREGS_AR_RELEASE_MINOR_VERSION_H     7
#define QSPI_IP_HYPERRAMREGS_AR_RELEASE_REVISION_VERSION_H  0
#define QSPI_IP_HYPERRAMREGS_SW_MAJOR_VERSION_H             5
#define QSPI_IP_HYPERRAMREGS_SW_MINOR_VERSION_H             0
#define QSPI_IP_HYPERRAMREGS_SW_PATCH_VERSION_H             0


/*******************************************************************************
 *                                       DEFINITIONS
 ******************************************************************************/
/*Address of Configuarion Register 0*/
#define QSPI_IP_HR_REGCFG0_ADDR         0x001000U

/*Address of Configuarion Register 1*/
#define QSPI_IP_HR_REGCFG1_ADDR         0x001002U

#define QSPI_IP_HR_CR0_DRIVE_STRENGTH_MASK           0x70U
#define QSPI_IP_HR_CR0_DRIVE_STRENGTH_SHIFT          4U
#define QSPI_IP_HR_CR0_DRIVE_STRENGTH(x)             (((uint16)(((uint16)(x)) << QSPI_IP_HR_CR0_DRIVE_STRENGTH_SHIFT)) & QSPI_IP_HR_CR0_DRIVE_STRENGTH_MASK)

#define QSPI_IP_HR_CR0_INITIAL_LATENCY_MASK          0xF000U
#define QSPI_IP_HR_CR0_INITIAL_LATENCY_SHIFT         12U
#define QSPI_IP_HR_CR0_INITIAL_LATENCY(x)            (((uint16)(((uint16)(x)) << QSPI_IP_HR_CR0_INITIAL_LATENCY_SHIFT)) & QSPI_IP_HR_CR0_INITIAL_LATENCY_MASK)

/*Default value of CR0*/
/*Drive strength and initial latency bits field will be configured by the driver.
  Other bits field will be kept as default follow datasheet of the hyperram */
#define QSPI_IP_HR_CR0_DEFAULT_VALUE                 0x0F8FU

/* Macros for Configuation Register 1 bits manipulation */
#define QSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_MASK        0x4000U
#define QSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_SHIFT       14U
#define QSPI_IP_HR_CR1_MASTER_CLOCK_TYPE(x)          (((uint16)(((uint16)(x)) << QSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_SHIFT)) & QSPI_IP_HR_CR1_MASTER_CLOCK_TYPE_MASK)

#define QSPI_IP_HR_CR1_PARTIAL_REFRESH_MASK          0x1C00U
#define QSPI_IP_HR_CR1_PARTIAL_REFRESH_SHIFT         10U
#define QSPI_IP_HR_CR1_PARTIAL_REFRESH(x)            (((uint16)(((uint16)(x)) << QSPI_IP_HR_CR1_PARTIAL_REFRESH_SHIFT)) & QSPI_IP_HR_CR1_PARTIAL_REFRESH_MASK)

/*Default value of CR1*/
/*Master clock type and Partial array refresh bits field will be configured by the driver.
  Other bits field will be kept as default follow datasheet of the hyperram */
#define QSPI_IP_HR_CR1_DEFAULT_VALUE                 0x81FFU

#ifdef __cplusplus
}
#endif


#endif /* QSPI_IP_HYPERRAMREGS_H */
