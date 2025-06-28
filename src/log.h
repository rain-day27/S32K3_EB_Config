/*
 * log.h
 *
 *  Created on: 2025年5月3日
 *      Author: 周大王
 */

#ifndef LOG_H_
#define LOG_H_

#define NEW_LINE	"\r\n"

typedef enum {
    e_log_debug,
    e_log_info,
    e_log_warn,
    e_log_error,
} log_level_e;

void log_print_init(void);
void log_print_task(void* param);
void app_log(log_level_e level, const char* tag, const char* fmt, ...);
void Uart_TxRxCallback(uint8 Channel, Uart_EventType Event);

#endif /* LOG_H_ */
