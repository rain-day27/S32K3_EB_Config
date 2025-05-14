/*
 * app.c
 *
 *  Created on: 2025年5月14日
 *      Author: 周大王
 */

#include "FreeRTOS.h"
#include "task.h"
#include "Dio.h"

#include "fifo.h"
#include "app.h"

void app_task(void* param)
{
	(void)param;
	uint8_t led_state = STD_HIGH;

	while(1)
	{
		led_state ^= 0x01;
		Dio_WriteChannel(DioConf_DioChannel_DioChannel_LED3_GREEN_PB14, led_state);

		vTaskDelay(1000);
	}
}
