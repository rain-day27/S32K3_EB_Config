/*
 * log.c
 *
 *  Created on: 2025年5月3日
 *      Author: 周大王
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
    char log_buffer[128];  // 注意内存占用，避免过大
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
