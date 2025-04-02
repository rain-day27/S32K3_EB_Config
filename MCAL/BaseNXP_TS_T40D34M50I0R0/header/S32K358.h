/*
** ###############################################################################################################
**     Processor:           S32K358_M7
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K3xx RM Rev.8
**     Version:             rev. 1.2, 2024-02-12
**     Build:               b240212
**
**     Abstract:
**         Peripheral Access Layer for S32K358_M7
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
**  - rev. 1.0 Taru Shree 16-Jun-22     Initial release based on 
**                                      RM Rev.4.
**
**  - rev. 1.1 Jalaj Awasthi 30-Sept-22 1)Initial release based on
**                                      RM Rev.5.
**                                      2)DCM-
**                                      -In DCMLCC register
**                                       Bit fields DCMLCFN, and DCMFLC are removed.
**                                      -In DCMLCS register 
**                                       Bit fields DCMLCSS1, 
**                                       DCMLCC1, DCMLCE1, DCMLCFE1, DCMLCSS2, DCMLCC2, 
**                                       -DCMOTAA and DCMOTAR bitfields are removed.
**                                       DCMLCE2, DCMLCFE2 bit fields are removed.
**                                      3)DCM_GPR-
**                                      -In DCMROD1 register
**                                       Bit fields HSE_DCF_VIO, and KEY_RESP_READY are removed.
**                                      -In DCMROD3 register 
**                                       Bit fields CM7_1_LOCKUP, TCM_GSKT_ALARM, TCM_AXBS_ALARM, 
**                                       CM7_1_DCDATA_ECC_ERR, CM7_1_DCTAG_ECC_ERR, CM7_1_ICDATA_ECC_ERR 
**										 are removed.
**                                      -In DCMROD4 register
**                                       Bit fields CM7_1_ICTAG_ECC_ERR, PF2_CODE_ECC_ERR, PF2_DATA_ECC_ERR, 
**                                       FLASH_ACCESS_ERR are removed.
**                                      -Bit fields FLASH_ECC_ERR, CM7_2_LOCKUP are added.
**                                       DCMRWD14 and DCMRWD15 registers are added.
**                                      -DCMRWD
**                                      - I3C related bits removed.
**                                       ....Similar changes were encountered throughout the module.
**                                      4)I3C module is removed
**                                      5)MSCM-
**                                      -In ENEDC register
**                                       STAM bit field is removed. 
**                                      6)SIUL2-
**                                      -In MSCR register
**                                       Bit field SSS_3 is added
**                                      7)SXOSC-
**                                      -In CTRL register 
**                                       Bit fields GM_SEL, CURR_PRG_COMP, and CURR_PRG_SF are added.
**                                      8)USDHC-
**                                      -In VEND_SPEC register
**                                       Bit field CONFLICT_CHK_EN is removed.
**                                      9)eMIOS_0-
**                                      -In UC_A register
**                                       Bit field RISE_FALL is added.
**                                       Similar change in eMIOS_1 and eMIOS_2. 
**                                      10)EIM_2 instance is added.
**
** - rev. 1.2 Jalaj Awasthi 12-Feb-24   1)Initial release based on             
**                                      RM Rev.8                               
**                                      2)ADC-                                 
**                                      -CWSELRSI is unrolled to CWSELRSI0,    
**                                      CWSELREI is unrolled to CWSELRSI1      
**                                      -In the AMSIO register                  
**                                      Bit field CMPCTRL0 is added.           
**                                      3)CONFIGURATION_GPR-                   
**                                      Registers QSPI_SFP_CTRL,               
**                                      QSPI_SFP_CTRL_ALT are removed.         
**                                      4)DCM-                                 
**                                      DCMSRR is unrolled to DCMSRR1,         
**                                      DCMSRR2,...DCMSRR16.                   
**                                      5)DCM_GPR-                             
**                                      -In the DCMROD3 register               
**                                      Bit field EMAC_GSKT_ALARM is changed   
**                                      to MAC_GSKT_ALARM.                     
**                                      -In the DCMROD5 register               
**                                      Bit field TEST_ACTIVATION_3_ERR is     
**                                      removed.                               
**                                      The bit field name is changed from     
**                                      EMAC_RDATA_EDC_ERR to MAC_RDATA_EDC_ERR
**                                      -In the register DCMROF1               
**                                      bit fields name is changed:            
**                                      EMAC_MDC_CHID_0 to MAC_MDC_CHID_0,     
**                                      EMAC_MDC_CHID_1 to MAC_MDC_CHID_0,     
**                                      EMAC1_MDC_CHID_1 to MAC1_MDC_CHID_1,   
**                                      EMAC1_MDC_CHID_2 to MAC1_MDC_CHID_2.   
**                                      -In the DCMROF20 register              
**                                      Bit field CM7_TCM_WS_EN is removed.    
**                                      -In the DCMRWP1 register               
**                                      Bit fields DEST_RESET_COUNT,           
**                                      SYS_REC_COUNTER, SBAF_REC_DIS_FRST,    
**                                      SBAF_REC_DIS_DRST are added.           
**                                      -In the DCMRWF1 register,              
**                                      Bit field name is changed from         
**                                      EMAC_CONF_SEL to MAC_CONF_SEL.         
**                                      Bit fields PMIC_PGOOD_HNDSHK_BYP,      
**                                      MAC_TX_RMII_CLK_LPBCK_EN are added.    
**                                      6)I3C module is removed.               
**                                      7)LPI2C-                               
**                                      -In the MCFGR1 register                
**                                      Bit field FRCHS is removed.            
**                                      8)MC_RGM-                              
**                                      FRENTC register is removed.            
**                                      9)MDM_AP-                               
**                                      -In the MDMAPCTL register              
**                                      Bit fields RSTRELCM70, RSTRELCM71,     
**                                      RSTRELCM72 are removed.                
**                                      Bit fields DBGRSTFASTPAD,              
**                                      CM7_0_CORE_ACCESS, CM7_1_CORE_ACCESS,  
**                                      CM7_2_CORE_ACCESS, CM7_2_CHK are added.
**                                      -In the MDMAPWIREN register            
**                                      Bit field PRVNTRSTEN is added.         
**                                      10)PFLASH-                             
**                                      PFCR register array is unrolled to     
**                                      PFCR0, PFCR1, PFCR2, PFCR3.            
**                                      -In the PFAPR register                 
**                                      Bit field M3AP is added.               
**                                      11)QuadSPI-                            
**                                      -In the MCR register                   
**                                      Bit fields DQS_EN, DDR_EN are added.   
**                                      -In the FLSHCR register                
**                                      Bit field TDH is added.                
**                                      -In the FR register                    
**                                      Bit field AAEF is added.               
**                                      -In RSER register                      
**                                      Bit field AAIE is added.               
**                                      -In the SPTRCLR register               
**                                      Bit fields ABRT_CLR, PREFETCH_DIS,     
**                                      STREAM_EN are added.                   
**                                      12)USDHC-                              
**                                      -In the PRES_STATE register            
**                                      Bit fields RTR, TSCD, and CDPL are     
**                                      removed.                               
**                                      -In the PROT_CTRL register             
**                                      Bit fields CDTL, and CDSS are removed. 
**                                      -In the SYS_CTRL register              
**                                      Bit field RSTT is removed.             
**                                      Bit field RST_FIFO is added.           
**                                      -In the INT_STATUS register            
**                                      Bit fields RTE, TP, and TNE are removed
**                                      -In the INT_STATUS_EN register         
**                                      Bit fields RTESEN, TPSEN, TNESEN are   
**                                      removed.                               
**                                      -In INT_SIGNAL_EN register             
**                                      Bit fields RTEIEN, TPIEN, TNEIEN are   
**                                      removed.                               
**                                      -In the AUTOCMD12_ERR_STATUS Register  
**                                      Bit fields EXECUTE_TUNING, SMP_CLK_SEL 
**                                      are added.                             
**                                      -In HOST_CTRL_CAP register             
**                                      Bit fields SDR104_SUPPORT,             
**                                      USE_TUNING_SDR50, VS18 are removed.    
**                                      -In MIX_CTRL register                  
**                                      Bit fields EXE_TUNE, SMP_CLK_SEL,      
**                                      AUTO_TUNE_EN, FBCLK_SEL are removed.   
**                                      -In the FORCE_EVENT register           
**                                      Bit field FEVTTNE is removed.          
**                                      Register CLK_TUNE_CTRL_STATUS is       
**                                      removed.                               
**                                      -In the VEND_SPEC2 register            
**                                      Bit fields TUNING_8BIT_EN,             
**                                      TUNING_1BIT_EN, TUNING_CMD_EN are      
**                                      removed.                               
**                                      Bit field EN_32K_CLK is added.         
**                                      Bit field TUNING_CTRL is removed.      
**                                      13)GMAC_1 instance is added.           
**                                      14)PFLASH_ALT is removed.              
**                                      15)PIT_RTI-                            
**                                      -In TCTRL register                     
**                                      Bit field CHN is removed.              
**                                                                        
** #############################################################################################
*/

/*!
 * @file S32K358.h
 * @version 1.2
 * @date 2024-02-12
 * @brief Peripheral Access Layer for S32K358
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K358_H_)  /* Check if memory map has not been already included */
#define S32K358_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K358_ADC.h"
#include "S32K358_AXBS_LITE.h"
#include "S32K358_BCTU.h"
#include "S32K358_CMU_FC.h"
#include "S32K358_CMU_FM.h"
#include "S32K358_CONFIGURATION_GPR.h"
#include "S32K358_CRC.h"
#include "S32K358_DCM.h"
#include "S32K358_DCM_GPR.h"
#include "S32K358_DMA.h"
#include "S32K358_DMAMUX.h"
#include "S32K358_DMA_TCD.h"
#include "S32K358_EIM.h"
#include "S32K358_EMIOS.h"
#include "S32K358_ERM.h"
#include "S32K358_FCCU.h"
#include "S32K358_FIRC.h"
#include "S32K358_FLASH.h"
#include "S32K358_FLEXCAN.h"
#include "S32K358_FLEXIO.h"
#include "S32K358_FXOSC.h"
#include "S32K358_GMAC.h"
#include "S32K358_INTM.h"
#include "S32K358_JDC.h"
#include "S32K358_LCU.h"
#include "S32K358_LPCMP.h"
#include "S32K358_LPI2C.h"
#include "S32K358_LPSPI.h"
#include "S32K358_LPUART.h"
#include "S32K358_MCM_CM7.h"
#include "S32K358_MC_CGM.h"
#include "S32K358_MC_ME.h"
#include "S32K358_MC_RGM.h"
#include "S32K358_MDM_AP.h"
#include "S32K358_MSCM.h"
#include "S32K358_MU.h"
#include "S32K358_PFLASH.h"
#include "S32K358_PIT.h"
#include "S32K358_PLL.h"
#include "S32K358_PMC.h"
#include "S32K358_PRAMC.h"
#include "S32K358_QUADSPI.h"
#include "S32K358_QUADSPI_ARDB.h"
#include "S32K358_RTC.h"
#include "S32K358_SAI.h"
#include "S32K358_SDA_AP.h"
#include "S32K358_SELFTEST_GPR.h"
#include "S32K358_SEMA42.h"
#include "S32K358_SIRC.h"
#include "S32K358_SIUL2.h"
#include "S32K358_STCU.h"
#include "S32K358_STM.h"
#include "S32K358_SWT.h"
#include "S32K358_SXOSC.h"
#include "S32K358_TEMPSENSE.h"
#include "S32K358_TRGMUX.h"
#include "S32K358_TSPC.h"
#include "S32K358_USDHC.h"
#include "S32K358_VIRT_WRAPPER.h"
#include "S32K358_WKPU.h"
#include "S32K358_XBIC.h"
#include "S32K358_XRDC.h"
#include "S32K358_NVIC.h"
#include "S32K358_SCB.h"
#include "S32K358_SYSTICK.h"
#include "S32K358_MPU.h"
#endif  /* #if !defined(S32K358_H_) */
