/*
 * app.c
 *
 *  Created on: 2025年5月14日
 *      Author: 周大王
 */

#include "FreeRTOS.h"
#include "task.h"
#include "Dio.h"
#include "Adc.h"
#include "Pwm.h"

#include "fifo.h"
#include "app.h"
#include "log.h"

#define APP_DEBUG(fmt,...)	app_log(e_log_debug, "APP", "[%lu]"fmt NEW_LINE, (uint32_t)get_sys_time(), ##__VA_ARGS__);
#define OWM_MAX_DUTY		0x8fff

Std_ReturnType adc0_group0_ret = E_OK;
Adc_ValueGroupType adc0_group0_result[e_adc0_ch_max] = {0};

/* 1s flash once. */
void board_break_led(void)
{
#if 0	//flash led
	static uint8_t led_state = STD_HIGH;
	led_state ^= 0x01;
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_LED3_GREEN_PB14, led_state);
#else	//breath led
	static uint16_t led_prior = 0;
	static bool increase = true;

	if(increase)
	{
		if(led_prior + 327 >= OWM_MAX_DUTY)
		{
			led_prior = OWM_MAX_DUTY;
			increase = false;
		}
		else
		{
			led_prior += 327;
		}
	}
	else
	{
		if(led_prior <= 327)
		{
			led_prior = 0;
			increase = true;
		}
		else
		{
			led_prior -= 327;
		}
	}

	Pwm_SetDutyCycle(PwmChannel_LED_FREEN, led_prior);
#endif
}

#if 1
void adc_data_updata(void)
{
	adc0_group0_ret = Adc_ReadGroup(AdcGroup_0, adc0_group0_result);
	if(adc0_group0_ret == E_OK)
	{
		APP_DEBUG("p0:%d x10:%d", adc0_group0_result[e_adc0_ch_p0], adc0_group0_result[e_adc0_ch_S10]);
	}
	else
	{
		APP_DEBUG("adc conversion error %d", adc0_group0_ret);
	}
	Adc_StartGroupConversion(AdcGroup_0);
}
#else
void adc_data_updata(void)
{
    Adc_StatusType status = Adc_GetGroupStatus(AdcGroup_0);
    if (status == ADC_STREAM_COMPLETED)
    {
        Std_ReturnType adc0_group0_ret = Adc_ReadGroup(AdcGroup_0, adc0_group0_result);
        if (adc0_group0_ret == E_OK)
        {
            APP_DEBUG("[OK] p0:%d x10:%d", adc0_group0_result[0], adc0_group0_result[1]);
        }
        else
        {
            APP_DEBUG("[ERROR] adc read failed: %d", adc0_group0_ret);
        }

        // 再次启动下一次转换
        Adc_StartGroupConversion(AdcGroup_0);
    }
    else
    {
        APP_DEBUG("[WAIT] ADC not ready (status = %d)", status);
    }
}

#endif
void user_adc_init(void)
{
	Adc_SetupResultBuffer(AdcGroup_0, adc0_group0_result);
	Adc_StartGroupConversion(AdcGroup_0);
}

void app_task(void* param)
{
	(void)param;
	user_adc_init();

	while(1)
	{
		board_break_led();
		adc_data_updata();

		vTaskDelay(10);
	}
}
