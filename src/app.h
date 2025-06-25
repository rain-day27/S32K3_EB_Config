/*
 * app.h
 *
 *  Created on: 2025年5月14日
 *      Author: 周大王
 */

#ifndef APP_H_
#define APP_H_

typedef enum __adc0_ch_e{
	e_adc0_ch_p0,	//PIN PTD1
	e_adc0_ch_S10,	//PIN PTD3
	e_adc0_ch_max
}adc0_ch_e;

extern uint8_t spi_tx_buff[2][128];
extern uint8_t spi_rx_buff[128];

void app_task(void* param);
uint64_t get_sys_time(void);

/* other file. */
void mcu_goto_low_power(void);

#endif /* APP_H_ */
