#include "irq_cbk.h"
#include "Lpuart_Uart_Ip.h"

void Uart0_handler(void)
{
    Lpuart_Uart_Ip_IrqHandler(0U);
}


void uart0_event_cbk(uint8 Channel, Uart_EventType Event)
{

	return ;
}

