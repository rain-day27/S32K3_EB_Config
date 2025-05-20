/*
 * irq_cbk.h
 *
 *  Created on: 2025年4月4日
 *      Author: 周大王
 */

#ifndef IRQ_CBK_H_
#define IRQ_CBK_H_

#include "Uart_ipw_Types.h"

void Uart0_irq_handler(void);
void uart0_event_cbk(uint8 Channel, Uart_EventType Event);
void Pit0_Irq_handler(void);
void Gpt_Pit0_Ch0_cbk(void);


#endif /* IRQ_CBK_H_ */
