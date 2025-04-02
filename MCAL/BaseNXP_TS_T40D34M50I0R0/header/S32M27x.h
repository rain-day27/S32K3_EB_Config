/*
** ###################################################################
**     Processor:           S32M27x
**     Reference manual:    S32M27x RM Rev.3
**     Version:             rev. 1.4, 2024-07-02
**     Build:               b240702
**
**     Abstract:
**         Peripheral Access Layer for S32M27x
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
**     Revisions:
**     - rev. 1.0 Taru Shree 23-Dec-21  Initial release based on 
**                                      S32M27x RM Rev.1 Draft C.
**
**     - rev. 1.1 Taru Shree 03-Jan-23  1)Initial release based on
**                                      S32M27x RM Rev.1.
**                                      2)Interrupt changes-
**                                      -FlexCAN3_0, FlexCAN3_1, 
**                                       FlexCAN4_0, FlexCAN4_1,
**                                       FlexCAN5_0, LPUART4, LPUART5,
**                                       LPUART6, LPUART7, I3C,
**                                       LPI2C0, LPSPI2, LPCMP1 and
**                                       LPCMP2 interrupts are removed.
**                                      -LPCMP0 interrupt is added.
**                                      3)DCM_GPR-
**                                      DCMRWF2 register: 
**                                      PMC_TRIM_RGM_DCF__BYP_STDBY_EXT 
**                                      bitfield is renamed as 
**                                      PMC_TRIM_RGM_DCF_BYP_STDBY_EXT.
**                                      4)TCD instance is renamed as
**                                      DMA_TCD.
**                                      5)FLASH-
**                                      -FLASH_INSTANCE_COUNT's value 
**                                       is changed from 2 to 1.
**                                      -FLASH_ALT instance is removed.
**                                      6)CAN_0, CAN_1 and CAN_2 instances
**                                      are merged together as FLEXCAN.
**                                      7)I3C instance is removed.
**                                      8)MC_ME-
**                                      PRTN0_CORE2_STAT and PRTN0_CORE2_ADDR 
**                                      registers are removed.
**                                      9)PFLASH-
**                                      -PFLASH_PFCBLKI_SPELOCK_COUNT 's 
**                                       value is changed from 2 to 3.
**                                      -PFLASH_PFCBLKI_SSPELOCK_COUNT's 
**                                       value is changed from 1 to 2.
**                                      -PFLASH_PFCBLKI_SETSLOCK_COUNT's 
**                                       value is changed from 2 to 3.
**                                      -PFLASH_PFCBLKI_SSETSLOCK_COUNT's 
**                                       value is changed from 1 to 2.
**                                      -PFLASH_PFCBLKI_LOCKMASTER_S_COUNT's 
**                                       value is changed from 2 to 3.
**                                      -PFLASH_PFCBLKI_LOCKMASTER_SS_COUNT's 
**                                       value is changed from 1 to 2.
**                                      -PFLASH_INSTANCE_COUNT's value is
**                                       changed from 2 to 1.
**                                      -PFLASH_ALT instance is removed.
**                                      -PFCR register: P1_CBFEN, P1_DBFEN
**                                       and P1_CPFEN bitfield's position 
**                                       is changed.
**                                       10)PMC_AE- 
**                                       MONCHECK register is added.
**                                       11)TRGMUX-
**                                       Structure is changed.
**                                       12)EMIOS_0 and EMIOS_1 instances
**                                       are merged together as eMIOS.
**
** - rev. 1.2 Jalaj Awasthi 24-May-2023  1)Initial release based on RM Rev.2  
**                                       Draft B.                             
**                                       2)ADC-                               
**                                       -In AMSIO register                   
**                                       Bit field CMPCTRL0 is added.         
**                                       3)AEC_AE-                            
**                                       -In CLKGEN_CFG register              
**                                       The size of the bit field CLKGEN_CFG 
**                                       is changed from 9 to 8.              
**                                       Bit fields CXPI_CLK_EN,              
**                                       RCOSC_MOD_ENA, RCOSC_MOD_FRQ,        
**                                       RCOSC_MOD_NBR are added.             
**                                       -In LINPHY_CFG register              
**                                       Bit fields CXPI_SLOPE, CXPI_BOOST,   
**                                       LIN_CXPI_SEL are added.              
**                                       4)DCM_GPR-                           
**                                       -In DCMROD5 register.                
**                                       Bit field TEST_ACTIVATION_3_ERR      
**                                       is removed.                          
**                                       -In DCMRWP1 register                 
**                                       Bit fields DEST_RESET_COUNT,         
**                                       SYS_REC_COUNTER, SBAF_REC_DIS_FRST,  
**                                       SBAF_REC_DIS_DRST are added           
**                                       -In DCMRWF2 register                 
**                                       Bit field SIRC_TRIM_BYP_STDBY_EXT    
**                                       is removed.                          
**                                       5)LPI2C-                             
**                                       -In MCFGR1 register                  
**                                       Bit field FRCHS is removed           
**                                       6)MC_CGM-                            
**                                       -In MUX_5_DC_0 register              
**                                       The size of the bit field DIV is     
**                                       changed from 6 to 3.                 
**                                       7)MEM_OTP_AE-                        
**                                       MIRR_ADDR, DATAIN registers          
**                                       are removed                          
**                                       -In ERROR Register                    
**                                       Bit fields PGMERR, VRRERR,           
**                                       PGMWPERR are removed                 
**                                       8)PFLASH-                            
**                                       -In PFCR4 register                   
**                                       Bit field DERR_SUP is removed        
**                                       9)PIT-                               
**                                       -In RTI_TCTRL register               
**                                       Bit field CHN is removed             
**                                       10)SIUL2-                            
**                                       -Registers UDR1, UDR0, UDR3,         
**                                       UDR2, are removed.                   
**                                       Registers MUX0_EMIOS_EN1,            
**                                       MUX0_MISC_EN, MUX1_EMIOS_EN,         
**                                       MUX1_MISC_EN, are added.             
**                                       -In MSCR register                    
**                                       Bit field SSS_3 is added.            
**
** - rev. 1.3 Navdeep Singh 09-Nov-2023  1)Initial release based on RM Rev 2.
**										 2)LPSPI2_IRQn interrupt has been 
**										 added.
**										 3)Names have been added in all the 
**                                       nested structures.
**										 4)MEM_OTP_AE-
**										 -ERROR register:
**										  -RDTRIES bitfield has been removed.
**
** - rev. 1.4 Jalaj Awasthi 02-July-2024 1)Initial release based on RM Rev 3. 
**									     2)SIUL2-				     		  
**									     -MIDR4 register:					  
**									     -Bit fields EMAC_FET and SEC_FET      
**                                       are removed.                          
**
** ##################################################################################
*/

/*!
 * @file S32M27x.h
 * @version 1.4
 * @date 2024-07-02
 * @brief Peripheral Access Layer for S32M27x
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32M27x_H_)  /* Check if memory map has not been already included */
#define S32M27x_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32M27x_ADC.h"
#include "S32M27x_AEC_AE.h"
#include "S32M27x_BCTU.h"
#include "S32M27x_CMU_FC.h"
#include "S32M27x_CMU_FM.h"
#include "S32M27x_CONFIGURATION_GPR.h"
#include "S32M27x_CRC.h"
#include "S32M27x_DCM.h"
#include "S32M27x_DCM_GPR.h"
#include "S32M27x_DMAMUX.h"
#include "S32M27x_DMA_TCD.h"
#include "S32M27x_DPGA_AE.h"
#include "S32M27x_EDMA.h"
#include "S32M27x_EIM.h"
#include "S32M27x_EMIOS.h"
#include "S32M27x_ERM.h"
#include "S32M27x_FCCU.h"
#include "S32M27x_FIRC.h"
#include "S32M27x_FLASH.h"
#include "S32M27x_FLEXCAN.h"
#include "S32M27x_FLEXIO.h"
#include "S32M27x_FXOSC.h"
#include "S32M27x_GDU_AE.h"
#include "S32M27x_HVI_AE.h"
#include "S32M27x_INTM.h"
#include "S32M27x_JDC.h"
#include "S32M27x_LCU.h"
#include "S32M27x_LPCMP.h"
#include "S32M27x_LPI2C.h"
#include "S32M27x_LPSPI.h"
#include "S32M27x_LPUART.h"
#include "S32M27x_MCM_CM7.h"
#include "S32M27x_MC_CGM.h"
#include "S32M27x_MC_ME.h"
#include "S32M27x_MC_RGM.h"
#include "S32M27x_MDM_AP.h"
#include "S32M27x_MEM_OTP_AE.h"
#include "S32M27x_MSCM.h"
#include "S32M27x_MU.h"
#include "S32M27x_PFLASH.h"
#include "S32M27x_PIT.h"
#include "S32M27x_PLL.h"
#include "S32M27x_PMC.h"
#include "S32M27x_PMC_AE.h"
#include "S32M27x_PRAMC.h"
#include "S32M27x_RTC.h"
#include "S32M27x_SDA_AP.h"
#include "S32M27x_SELFTEST_GPR.h"
#include "S32M27x_SIRC.h"
#include "S32M27x_SIUL2.h"
#include "S32M27x_STCU.h"
#include "S32M27x_STM.h"
#include "S32M27x_SWT.h"
#include "S32M27x_TEMPSENSE.h"
#include "S32M27x_TRGMUX.h"
#include "S32M27x_TSPC.h"
#include "S32M27x_VIRT_WRAPPER.h"
#include "S32M27x_WKPU.h"
#include "S32M27x_XBIC.h"
#include "S32M27x_XRDC.h"
#include "S32M27x_NVIC.h"
#include "S32M27x_SCB.h"
#include "S32M27x_SYSTICK.h"
#include "S32M27x_MPU.h"
#endif  /* #if !defined(S32M27x_H_) */
