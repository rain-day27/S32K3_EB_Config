/*
 * log.c
 *
 *  Created on: 2025��5��3��
 *      Author: �ܴ���
 */

#include "CDD_Uart.h"
#include "FreeRTOS.h"
#include "task.h"

#include "fifo.h"
#include "log.h"
#include "app.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define UART0_CHANNL 0
#define	LOG_BUFF_SIZE 512

#define LOG_DEBUG(fmt,...)	app_log(e_log_debug, "LOG", "[%lu]"fmt NEW_LINE, (uint32_t)get_sys_time(), ##__VA_ARGS__);

uint8_t log_tx_buff[LOG_BUFF_SIZE] = {0};
uint8_t log2uart_buff[LOG_BUFF_SIZE] = {0};
fifo_t log_fifo;


void app_debug(const char* str, uint16_t len)
{
	fifo_write(&log_fifo, str, len);
}


void app_log(log_level_e level, const char* tag, const char* fmt, ...)
{
    static const char* level_str[] = {"DEBUG", "INFO", "WARN", "ERROR"};
    char log_buffer[128];  // ע���ڴ�ռ�ã��������
    int len = 0;

    // ����ȼ���ģ���ʶ
    len = snprintf(log_buffer, sizeof(log_buffer), "[%s][%s] ", level_str[level], tag);

    // ��ʽ��ʵ����Ϣ
    va_list args;
    va_start(args, fmt);
    len += vsnprintf(log_buffer + len, sizeof(log_buffer) - len, fmt, args);
    va_end(args);

    // ��֤�������
    if (len > sizeof(log_buffer)) len = sizeof(log_buffer);

    // д�� FIFO���������� app_debug��
    app_debug(log_buffer, (uint16_t)len);
}

void log_print_init(void)
{
	fifo_init(&log_fifo, log_tx_buff, sizeof(log_tx_buff));
}

void log_print_task(void* param)
{
	(void)param;
	uint32_t count = 0;
	uint16_t print_count = 0;

	while(1)
	{
		count++;
		print_count = fifo_get_count(&log_fifo);

		if(fifo_read(&log_fifo, log2uart_buff, print_count))
		{
			Uart_AsyncSend(UART0_CHANNL, log2uart_buff, print_count);
		}

		if(count%100==0)
		{
			//LOG_DEBUG("run time %ds", count/100);
		}

		vTaskDelay(10);
	}
}
