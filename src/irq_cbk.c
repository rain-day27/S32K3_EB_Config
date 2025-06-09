#include "Platform.h"
#include "irq_cbk.h"
#include "Lpuart_Uart_Ip.h"
#include "Gpt.h"
#include "Adc.h"
#include "Gpt_Irq.h"
#include "eMIOS_Mcl_ip_irq.h"
#include "Wkpu_Ip_Irq.h"

#include "FreeRTOS.h"
#include "task.h"

/* define. */
#define USER_TASK_TICK	(1*40*1000)	//1ms=40*1000us*

/* global variable. */
volatile uint64_t system_count = 0;

/* external declaration. */
extern void PIT_0_ISR(void);
extern void Adc_Sar_0_Isr(void);


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
	//Gpt_ProcessCommonInterrupt(GptConf_GptChannelConfiguration_GptChannelConfiguration_Pit0_Ch0);
}

/* Execute once every 1ms. */
void Gpt_Pit0_Ch0_cbk(void)
{
	system_count++;
}

uint64_t get_sys_time(void)
{
	return system_count;
}

void Adc0_Irq_handler(void)
{
	Adc_Sar_0_Isr();
}

void eMIOS1_5_Irq_handler(void)
{
	EMIOS1_5_IRQ();
}

uint8_t wake_falg = 0;
void WakeUp_handler(void)
{
	wake_falg++;
	WKPU_EXT_IRQ_SINGLE_ISR();
}


