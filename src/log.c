/*
 * log.c
 *
 *  Created on: 2025年5月3日
 *      Author: 周大王
 */

#include "CDD_Uart.h"

#include "fifo.h"

#define UART0_CHANNL 0
#define	LOG_BUFF_SIZE 512
uint8_t log_tx_buff[LOG_BUFF_SIZE] = {0};
uint8_t log2uart_buff[LOG_BUFF_SIZE] = {0};
fifo_t log_fifo;


void app_debug(const char* str, uint16_t len)
{
	char new_line[2] = "\r\n";
	fifo_write(&log_fifo, str, len);
	fifo_write(&log_fifo, new_line, sizeof(new_line));
}

void log_print_init(void)
{
	fifo_init(&log_fifo, log_tx_buff, sizeof(log_tx_buff));
}

void log_print_task(uint8_t param)
{
	(void)param;

	uint16_t print_count= fifo_get_count(&log_fifo);
	if(fifo_read(&log_fifo, log2uart_buff, print_count))
	{
		Uart_AsyncSend(UART0_CHANNL, log2uart_buff, print_count);
	}
}
