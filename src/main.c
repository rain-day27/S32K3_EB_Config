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
#include "CDD_Uart.h"

#include <stdio.h>

#if defined (__ghs__)
    #define __INTERRUPT_SVC  __interrupt
    #define __ASM_VOLATILE __asm volatile
    #define __NO_RETURN__ _Pragma("ghs nowarning 111")
#elif defined (__ICCARM__)
    #define __INTERRUPT_SVC  __svc
    #define __ASM_VOLATILE asm volatile
    #define __NO_RETURN__ _Pragma("diag_suppress=Pe111")
#elif defined ( __DCC__ )
  #define __INTERRUPT_SVC __attribute__ ((interrupt ("SWI")))
  #define __ASM_VOLATILE __asm volatile
  #define __NO_RETURN__
#elif defined (__GNUC__)
    #define __INTERRUPT_SVC  __attribute__ ((interrupt ("SVC")))
    #define __ASM_VOLATILE __asm volatile
    #define __NO_RETURN__
#else
    #define __INTERRUPT_SVC
    #define __NO_RETURN__
    #define __ASM_VOLATILE __asm volatile
#endif

int counter, accumulator = 0, limit_value = 1000000;

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

#define UART0_CHANNL 0
#define uart0_buff_size	256
uint8_t uart0_buff[uart0_buff_size] = {0};

void bsp_uart_init(void)
{
	Uart_AsyncReceive(UART0_CHANNL, uart0_buff, uart0_buff_size);
	IP_LPUART_0->CTRL &= ~(0xf<<24);
	IP_LPUART_0->CTRL |= LPUART_CTRL_IDLECFG(7);
	IP_LPUART_0->CTRL |= LPUART_CTRL_ILT(1);;
	IP_LPUART_0->CTRL |= LPUART_CTRL_ILIE(1);;

}

#define LPUART0_BASE (0x40154000u)
#define LPUART0_TDR  (*(volatile uint8_t *)(LPUART0_BASE + 0x1Cu)) // DATA¼Ä´æÆ÷
#define LPUART0_SR   (*(volatile uint32_t *)(LPUART0_BASE + 0x10u)) // STAT¼Ä´æÆ÷
#define LPUART0_SR_TDRE_MASK (1u << 23) // TX¿Õ±êÖ¾

// SCG register base
#define SCG_BASE        0x40064000UL
#define SCG_SOSCCSR     (*(volatile uint32_t*)(SCG_BASE + 0x100))
#define SCG_SPLLCSR     (*(volatile uint32_t*)(SCG_BASE + 0x200))

// PCC register base (Peripheral Clock Control)
#define PCC_BASE        0x40065000UL
#define PCC_LPUART0     (*(volatile uint32_t*)(PCC_BASE + 0xA0))

void EnableLpuart0Clock_Manually(void) {
    PCC_LPUART0 = 0xC0000000UL;  // Clock enabled, source = FIRC (3)
}

void TestUart0SendChar(char c) {
    while ((LPUART0_SR & LPUART0_SR_TDRE_MASK) == 0);  // µÈ´ýTX¿Õ
    LPUART0_TDR = c;
}


uint8_t uaer_tx_buff[32] = {0};
uint8_t uaer_tx_buff1[16] = "123456789";
int main(void) {
    /* Initialize the Mcu driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus())	{}
    Mcu_DistributePllClock();

    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize all pins using the Port driver */
    Port_Init(&Port_Config);

    /* Initializes an UART driver*/
    Uart_Init(&Uart_xConfig);

    Uart_SyncSend(0, uaer_tx_buff, 32, 100*1000);

    while (1)
    {
        Dio_WriteChannel(DioConf_DioChannel_DioChannel_LED3_GREEN_PB14, STD_HIGH);
        TestDelay(500000);
        Dio_WriteChannel(DioConf_DioChannel_DioChannel_LED3_GREEN_PB14, STD_LOW);
        TestDelay(500000);

        Uart_SyncSend(0, uaer_tx_buff1, 10, 100*1000);
    }

    return (0U);
}

__INTERRUPT_SVC void SVC_Handler() {
    accumulator += counter;
    printf("counter is 0x%08x, accumulator is 0x%08x\n", counter, accumulator);
}
