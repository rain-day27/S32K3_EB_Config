/*
 * log.h
 *
 *  Created on: 2025��5��3��
 *      Author: �ܴ���
 */

#ifndef LOG_H_
#define LOG_H_

void log_print_init(void);
void log_print_task(void* param);
void app_debug(const char* str, uint16_t len);

#endif /* LOG_H_ */
