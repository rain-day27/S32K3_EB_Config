/*
 * app.c
 *
 *  Created on: 2025年5月14日
 *      Author: 周大王
 */

#include "main.h"
#include "fifo.h"
#include "app.h"
#include "log.h"

#define APP_DEBUG(fmt,...)	app_log(e_log_debug, "APP", "[%lu]"fmt NEW_LINE, (uint32_t)get_sys_time(), ##__VA_ARGS__);
#define OWM_MAX_DUTY		0x8fff
#define I2C_SLAVE_ADDRESS	(uint8_t)0x50	//7 bit address

Std_ReturnType adc0_group0_ret = E_OK;
Adc_ValueGroupType adc0_group0_result[e_adc0_ch_max] = {0};
Icu_DutyCycleType DutyCycle = {0,0};
uint8_t user_i2c_rx_buff[9] = {0};
uint8_t user_i2c_tx_buff[9] = {0x00,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00};


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

void icu_ch2_duty_mesure(void)
{
	Icu_GetDutyCycleValues(IcuChannel_EM1_CH2, &DutyCycle);
	APP_DEBUG("[ICU] active = %d prior = %d)", DutyCycle.ActiveTime, DutyCycle.PeriodTime);
}

uint8_t read_data_to_i2c(uint8_t* data,uint8_t size)
{
	uint8_t ret = false;
	I2c_RequestType I2c_Request = {0};
	I2c_Request.BitsSlaveAddressSize = false;
	I2c_Request.BufferSize = size;
	I2c_Request.DataBuffer = data;
	I2c_Request.DataDirection = I2C_RECEIVE_DATA;
	I2c_Request.ExpectNack = false;
	I2c_Request.RepeatedStart = false;
	I2c_Request.SlaveAddress = I2C_SLAVE_ADDRESS;

	//ret = I2c_SyncTransmit(I2cChannel_I2C1, &I2c_Request);
	ret = I2c_AsyncTransmit(I2cChannel_I2C1, &I2c_Request);

	//APP_DEBUG("[I2C] ret = %d", ret);
	return ret;
}

uint8_t write_data_to_i2c(uint8_t* data,uint8_t size)
{
	uint8_t ret = false;
	I2c_RequestType I2c_Request = {0};
	I2c_Request.BitsSlaveAddressSize = false;
	I2c_Request.BufferSize = size;
	I2c_Request.DataBuffer = data;
	I2c_Request.DataDirection = I2C_SEND_DATA;
	I2c_Request.ExpectNack = false;
	I2c_Request.RepeatedStart = false;
	I2c_Request.SlaveAddress = I2C_SLAVE_ADDRESS;

	//ret = I2c_SyncTransmit(I2cChannel_I2C1, &I2c_Request);
	ret = I2c_AsyncTransmit(I2cChannel_I2C1, &I2c_Request);

	//APP_DEBUG("[I2C] ret = %d", ret);
	return ret;
}

uint8_t read_data_from_eep(void)
{
	uint8_t ret = 0;
	/* 1.write data to eeprom (write). */
	ret = write_data_to_i2c(user_i2c_tx_buff, sizeof(user_i2c_tx_buff));
	APP_DEBUG("[I2C] ret1 = %d", ret);
	vTaskDelay(50);

	/* 2.write need to read data address to eeprom (read step 1). */
	ret = write_data_to_i2c(user_i2c_rx_buff, 1);
	APP_DEBUG("[I2C] ret2 = %d", ret);
	vTaskDelay(50);

	/* 3.read need  from eeprom (read step 2). */
	read_data_to_i2c(user_i2c_rx_buff, 8);
	vTaskDelay(50);
	APP_DEBUG("[I2C] ret3 = %d", ret);
	for(int i=0;i<8;i++)
	{
		APP_DEBUG("[I2C] data[%d]= %d",i, user_i2c_rx_buff[i]);
		vTaskDelay(10);
	}

	return ret;
}

void user_adc_init(void)
{
	Adc_SetupResultBuffer(AdcGroup_0, adc0_group0_result);
	Adc_StartGroupConversion(AdcGroup_0);
}

void app_task(void* param)
{
	(void)param;
	uint32_t app_count = 0;

	user_adc_init();
	Icu_StartSignalMeasurement(IcuChannel_EM1_CH2);

	while(1)
	{
		board_break_led();
		if(app_count % 100 == 0)	//1s
		{
			adc_data_updata();
			icu_ch2_duty_mesure();
			read_data_from_eep();
		}

		if(app_count > 20 * 100)	//running 20s goto standby
		{
			//APP_DEBUG("mcu goto standby %d)", app_count);
			vTaskDelay(10);
			//mcu_goto_low_power();
		}

		app_count++;
		vTaskDelay(10);
	}
}
