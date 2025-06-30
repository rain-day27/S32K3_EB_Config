/*
 * irq_cbk.h
 *
 *  Created on: 2025年4月4日
 *      Author: 周大王
 */

#ifndef IRQ_CBK_H_
#define IRQ_CBK_H_

#include "Uart_ipw_Types.h"

typedef struct
{
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;     // return address
    uint32_t pc;     // program counter
    uint32_t xpsr;   // program status
} HardFaultStackFrame;


void Uart0_irq_handler(void);
void Pit0_Irq_handler(void);
void Gpt_Pit0_Ch0_cbk(void);


#endif /* IRQ_CBK_H_ */
