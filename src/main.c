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

#include "log.h"

#include <stdio.h>


void TestDelay(uint32 delay);
void TestDelay(uint32 delay)
{
    static volatile uint32 DelayTimer = 0;
    while(DelayTimer<delay)
    {
        DelayTimer++;
    }
    DelayTimer=0;
}

uint8_t start_print[16] = "app_init_ok\n";

void user_init(void)
{
	/* open the uart0 interrupt. */
    //IntCtrl_Ip_EnableIrq(LPUART0_IRQn);

    log_print_init();

    /* Start the Gpt timer */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0, 120000000);

    /* Enable the Gpt notification to get the event for toggling the LED periodically */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);

    Uart_AsyncSend(0, start_print, sizeof(start_print));
}

int main(void) {
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

    user_init();

    volatile Gpt_ValueType before = 0;
    volatile Gpt_ValueType future = 0;
    while (1)
    {
    	log_print_task(0);

        Dio_WriteChannel(DioConf_DioChannel_DioChannel_LED3_GREEN_PB14, STD_HIGH);
        TestDelay(1000000);
        Dio_WriteChannel(DioConf_DioChannel_DioChannel_LED3_GREEN_PB14, STD_LOW);
        TestDelay(1000000);

        before = Gpt_GetTimeElapsed(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);
        future = Gpt_GetTimeRemaining(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);
        Uart_AsyncSend(0, start_print, sizeof(start_print));
    }

    return (0U);
}

