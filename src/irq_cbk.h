/*
 * irq_cbk.h
 *
 *  Created on: 2025��4��4��
 *      Author: �ܴ���
 */

#ifndef IRQ_CBK_H_
#define IRQ_CBK_H_

#include "Uart_ipw_Types.h"

void Uart0_handler(void);
void uart0_event_cbk(uint8 Channel, Uart_EventType Event);

#endif /* IRQ_CBK_H_ */
