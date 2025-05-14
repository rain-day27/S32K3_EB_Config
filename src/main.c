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
#include "S32K314.h"
#include "Mcu.h"
#include "Port.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Gpt.h"
#include "CDD_Uart.h"
#include "Platform.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "log.h"
#include "app.h"

#include <stdio.h>


StaticTask_t xIdleTaskTCB;
StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
    // 返回这些缓冲区的地址和大小
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

uint8_t start_print[16] = "app_init_ok\n";

void user_init(void)
{
	/* open the uart0 interrupt. */
    //IntCtrl_Ip_EnableIrq(LPUART0_IRQn);

    log_print_init();

    /* Start the Gpt timer 1ms */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0, 40000);

    /* Enable the Gpt notification to get the event for toggling the LED periodically */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);

    Uart_AsyncSend(0, start_print, sizeof(start_print));
}
void Mcal_Init(void)
{
	/* Initialize the Mcu driver */
	Mcu_Init(&Mcu_Config);

	/* Initialize the clock tree and apply PLL as system clock */
	Mcu_InitClock(McuClockSettingConfig_0);
	while(MCU_PLL_LOCKED != Mcu_GetPllStatus())	{}
	Mcu_DistributePllClock();

	/* Apply a mode configuration */
	Mcu_SetMode(McuModeSettingConf_0);

	/* Initialize all pins using the Port driver */
	Port_Init(&Port_Config);

	/* Initialize IRQs */
	Platform_Init(NULL);

	/* Initialize the high level configuration structure of Gpt driver */
	Gpt_Init(NULL);

	/* Initializes an UART driver*/
	Uart_Init(&Uart_xConfig);
}

int main(void)
{
	Mcal_Init();

    user_init();

    xTaskCreate((TaskFunction_t)log_print_task, "LOG START", 256, NULL, 1, NULL);
    xTaskCreate((TaskFunction_t)app_task, "APP START", 256, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1)
    {

    }

    return (0U);
}

