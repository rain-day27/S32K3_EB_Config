/*
 * log.c
 *
 *  Created on: 2025年5月3日
 *      Author: 周大王
 */

#include "main.h"
#include "fifo.h"
#include "log.h"
#include "app.h"

#define UART0_CHANNL 0
#define	LOG_TX_BUFF_SIZE 512
#define	LOG_RX_BUFF_SIZE 128

#define LOG_DEBUG(fmt,...)	app_log(e_log_debug, "LOG", "[%lu]"fmt NEW_LINE, (uint32_t)get_sys_time(), ##__VA_ARGS__);

fifo_t log_tx_fifo;
uint8_t log_tx_buff[LOG_TX_BUFF_SIZE] = {0};
uint8_t log2uart_buff[LOG_TX_BUFF_SIZE] = {0};	//tx
uint8_t uart2log_buff[LOG_RX_BUFF_SIZE] = {0};	//rx
uint8_t uart0_rx_done_flag = false;
uint32_t err_flag = 0;


void Uart_TxRxCallback(uint8 Channel, Uart_EventType Event)
{
	(void)Channel;
	//uint32_t temp_val;
	//Uart_StatusType err_flag = UART_STATUS_NO_ERROR;

	switch(Channel)
	{
	case 0:	//UART channal1
		if (Event == UART_EVENT_RX_FULL)
		{
			uart0_rx_done_flag = true;
			Uart_AsyncReceive(UART0_CHANNL, uart2log_buff, LOG_RX_BUFF_SIZE);
		}
		else if (Event == UART_EVENT_END_TRANSFER)
		{

		}
		else if (Event == UART_EVENT_ERROR)
		{
			//err_flag = Uart_GetStatus(UART0_CHANNL, &temp_val, UART_RECEIVE);

			IP_LPUART_0->STAT &= ~(0xf<<16);
			Uart_AsyncReceive(UART0_CHANNL, uart2log_buff, LOG_RX_BUFF_SIZE);
		}
		else if (Event == UART_EVENT_IDLE_STATE)
		{
			uart0_rx_done_flag = true;
			Uart_AsyncReceive(UART0_CHANNL, uart2log_buff, LOG_RX_BUFF_SIZE);
		}
		break;

	default :
		break;
	}
}

void uart0_rx_handle(void)
{
	if (uart0_rx_done_flag)
	{
		uart0_rx_done_flag = 0;

	    Uart_AsyncSend(UART0_CHANNL, uart2log_buff, strlen((char*)uart2log_buff));

	    // 继续接收下一批数据
	    Uart_AsyncReceive(UART0_CHANNL, uart2log_buff, LOG_RX_BUFF_SIZE);
	}

}

void app_debug(const char* str, uint16_t len)
{
	fifo_write(&log_tx_fifo, str, len);
}

void app_log(log_level_e level, const char* tag, const char* fmt, ...)
{
    static const char* level_str[] = {"DEBUG", "INFO", "WARN", "ERROR"};
    char log_buffer[256];  // 注意内存占用，避免过大
    int len = 0;

    // 加入等级和模块标识
    len = snprintf(log_buffer, sizeof(log_buffer), "[%s][%s] ", level_str[level], tag);

    // 格式化实际消息
    va_list args;
    va_start(args, fmt);
    len += vsnprintf(log_buffer + len, sizeof(log_buffer) - len, fmt, args);
    va_end(args);

    // 保证不会溢出
    if (len > sizeof(log_buffer)) len = sizeof(log_buffer);

    // 写入 FIFO（复用已有 app_debug）
    app_debug(log_buffer, (uint16_t)len);
}

void debug_print(const char* fmt, ...)
{
	uint16_t str_len;
	uint8_t str_buff[100];
	va_list args;

	va_start(args, fmt);
	str_len = vsnprintf((char*)str_buff, 100, fmt, args);
	va_end(args);

	if(str_len)
	{
		Uart_SyncSend(UART0_CHANNL, str_buff, str_len, 0xffff);
	}
}

void creat_handfault(void)
{
	uint8_t arr[8] = {0};
	memset(arr, 0, 16);
}

void log_print_init(void)
{
	fifo_init(&log_tx_fifo, log_tx_buff, sizeof(log_tx_buff));
}

void log_print_task(void* param)
{
	(void)param;
	uint32_t count = 0;
	uint16_t print_count = 0;
	Uart_AsyncReceive(UART0_CHANNL, uart2log_buff, LOG_RX_BUFF_SIZE);

	while(1)
	{
		count++;
		print_count = fifo_get_count(&log_tx_fifo);

		if(fifo_read(&log_tx_fifo, log2uart_buff, print_count))
		{
			Uart_AsyncSend(UART0_CHANNL, log2uart_buff, print_count);
		}

		if(count%100==0)	//1000ms
		{
			creat_handfault();

			//LOG_DEBUG("run time %ds", count/100);
			uart0_rx_handle();
		}

		vTaskDelay(10);
	}
}
