#include "Platform.h"
#include "irq_cbk.h"
#include "Lpuart_Uart_Ip.h"
#include "Gpt.h"
#include "Adc.h"
#include "Gpt_Irq.h"
#include "eMIOS_Mcl_ip_irq.h"
#include "Wkpu_Ip_Irq.h"
#include "S32K314_SCB.h"

#include "FreeRTOS.h"
#include "task.h"

#include "log.h"

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

void hard_fault_c_handler(HardFaultStackFrame *frame)
{
	debug_print("\n--- HardFault Occurred ---\n");
	debug_print("R0  = 0x%08lX\n", frame->r0);
	debug_print("R1  = 0x%08lX\n", frame->r1);
	debug_print("R2  = 0x%08lX\n", frame->r2);
	debug_print("R3  = 0x%08lX\n", frame->r3);
	debug_print("R12 = 0x%08lX\n", frame->r12);
	debug_print("LR  = 0x%08lX\n", frame->lr);
	debug_print("PC  = 0x%08lX\n", frame->pc);
	debug_print("xPSR= 0x%08lX\n", frame->xpsr);

    uint32_t cfsr  = S32_SCB->CFSR;
    uint32_t hfsr  = S32_SCB->HFSR;
    uint32_t mmfar = S32_SCB->MMFAR;
    uint32_t bfar  = S32_SCB->BFAR;

    debug_print("CFSR  = 0x%08lX\n", cfsr);
    debug_print("HFSR  = 0x%08lX\n", hfsr);
    debug_print("MMFAR = 0x%08lX\n", mmfar);
    debug_print("BFAR  = 0x%08lX\n", bfar);

    while (1);
}



