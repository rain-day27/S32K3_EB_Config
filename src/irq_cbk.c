#include "Platform.h"
#include "irq_cbk.h"
#include "Lpuart_Uart_Ip.h"
#include "Gpt.h"
#include "Gpt_Irq.h"

#define USER_TASK_TICK	(1*40*1000)	//1ms=40*1000us*

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

volatile uint64_t system_count = 0;
void Pit0_Irq_handler(void)
{
	system_count++;
	Gpt_ProcessCommonInterrupt(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);
}

/* Execute once every 1ms. */
void Gpt_Pit0_Ch0_cnk(void)
{
	Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);
   /* Start the Gpt timer */
	Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0, USER_TASK_TICK);
	/* Enable the Gpt notification to get the event for toggling the LED periodically */
	Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0_CH0);
}

