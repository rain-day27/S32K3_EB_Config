#include "Platform.h"
#include "irq_cbk.h"
#include "Lpuart_Uart_Ip.h"
#include "Gpt.h"
#include "Gpt_Irq.h"

/* define. */
#define USER_TASK_TICK	(1*40*1000)	//1ms=40*1000us*

/* global variable. */
volatile uint64_t system_count = 0;

/* external declaration. */
extern void PIT_0_ISR(void);


void Uart0_Irq_handler(void)
{
    Lpuart_Uart_Ip_IrqHandler(0U);
}

void uart0_event_cbk(uint8 Channel, Uart_EventType Event)
{
	(void)Channel;
	(void)Event;
	return ;
}

void Pit0_Irq_handler(void)
{
	PIT_0_ISR();
	//Gpt_ProcessCommonInterrupt(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);
}

/* Execute once every 1ms. */
void Gpt_Pit0_Ch0_cnk(void)
{
	system_count++;
}

