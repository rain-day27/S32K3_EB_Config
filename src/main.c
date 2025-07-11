/* Copyright 2023 NXP */
/* License: BSD 3-clause
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/
/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "main.h"
#include "log.h"
#include "app.h"

uint8_t start_print[16] = "MCU Reset\n";
StaticTask_t xIdleTaskTCB;
StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
    // 返回这些缓冲区的地址和大小
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

void Wkup_Config(void)
{
    #ifdef FASTWKUP_STANDBY_RAM
        FastWkup_StandbyRAMECCInit();
    #endif

    /* Any reset occurred during standby will cause peripherals registers reset */
    //if(Mcu_GetResetReason() < MCU_WAKE_UP_REASON )
    if(1)
    {
    #if(WKUP_USE_FAST)
        IP_DCM_GPR->DCMRWF5 = (uint32_t)VectorTable |  /* Vector table address for Fast Standby Exit */
                              0x00000001UL;            /* Enable Fast Standby Exit */
        IP_PMC->CONFIG |= PMC_CONFIG_FAST_RECOVERY_ENABLE;/*Enable capacitor fast charging after standby exit*/
        IP_DCM_GPR->DCMRWF2 |= DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_MASK |  /* Bypass SIRC trimming on standby exit */
                               DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF_BYP_STDBY_EXT_MASK |  /* bypass the PMC trimming and RGM DCF loading on standby exit */
                               DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK |  /* Bypass FIRC trimming on standby exit */
                               DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_MASK;    /* bypass the DCM scanning on standby exit */
    #else
        IP_DCM_GPR->DCMRWF5 = 0x00000000UL;            /* Enable Normal Standby Exit */
    #endif
    }

    /* Initialize the Icu driver */
    Icu_Init(NULL_PTR);
    Icu_EnableEdgeDetection(IcuChannel_WKUP59_PA20);

    /* wkup edge detection */
    // Icu_EnableEdgeDetection(IcuWkpuChannel_LPCM1);
    // Icu_EnableEdgeDetection(IcuWkpuChannel_PTC20);
    // Icu_EnableEdgeDetection(IcuWkpuChannel_PTC11_CAN5_Rx_Wkup);
    // Icu_EnableEdgeDetection(IcuWkpuChannel_PTA6_CAN0_Rx_Wkup);

    /* Enable pad keeping in STANDBY IO configurations */
    IP_DCM_GPR->DCMRWF1 &= ~DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK;
}

void mcu_goto_low_power(void)
{
    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_Standby);
#if 0
    /* Initialize the WAKE_UP Mode */
    Icu_Init(NULL_PTR);
    /* Enble callback but not used */
    Icu_EnableEdgeDetection(IcuChannel_WKUP59_PA20);

    /* Disable standby IO pad keeping */
    IP_DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK;
#else
    Wkup_Config();
#endif
    /* Initialize the Mcu Mode */
    Mcu_SetMode(McuModeSettingConf_Standby);

}

void user_init(void)
{
	/* open the uart0 interrupt. */
    //IntCtrl_Ip_EnableIrq(LPUART0_IRQn);

    log_print_init();

    /* Start the Gpt timer 1ms */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_Pit0_Ch0, 40000);

    /* Enable the Gpt notification to get the event for toggling the LED periodically */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_Pit0_Ch0);

    /* uart config */
    //IP_LPUART_0->CTRL &= ~(0xf<<24);				//close err check
    IP_LPUART_0->CTRL |= LPUART_CTRL_IDLECFG(7);	//bus idle timeout
    IP_LPUART_0->CTRL |= LPUART_CTRL_ILT(1);		//starts counting logic 1s as idle character bits
    //IP_LPUART_0->CTRL |= LPUART_CTRL_ILIE(1);		//enable idle interrupt,EB already configured

}
void Mcal_Init(void)
{
	/* Initialize the Mcu driver */
	Mcu_Init(&Mcu_Config);

	/* Initialize the clock tree and apply PLL as system clock */
	Mcu_InitClock(McuClockSettingConfig_Running);
	while(MCU_PLL_LOCKED != Mcu_GetPllStatus())	{}
	Mcu_DistributePllClock();

	/* Apply a mode configuration */
	Mcu_SetMode(McuModeSettingConf_Running);

	Mcl_Init(NULL_PTR);

	/* Disable standby IO pad keeping */
	IP_DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK;

	/* Initialize all pins using the Port driver */
	Port_Init(&Port_Config);

	/* Adc Initialize */
	Adc_Init(NULL_PTR);

	/* Initialize IRQs */
	Platform_Init(NULL_PTR);

	/* Initialize the high level configuration structure of Gpt driver */
	Gpt_Init(NULL_PTR);

	/* Initializes an UART driver*/
	Uart_Init(&Uart_xConfig);

	I2c_Init(NULL_PTR);

	Pwm_Init(NULL_PTR);

	Spi_Init(NULL_PTR);

	Icu_Init(NULL_PTR);
}

int main(void)
{
	Mcal_Init();

    user_init();

    while(get_sys_time() < 300);

    xTaskCreate((TaskFunction_t)log_print_task, "LOG START", 256, NULL, 1, NULL);
    xTaskCreate((TaskFunction_t)app_task, "APP START", 512, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1)
    {

    }

    return (0U);
}

