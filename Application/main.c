/******************************************************************************
*
* File Name: main.c
*
* Description: Source file for the main application
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include "../HAL/LCD/lcd.h"
#include "../HAL/LM35/lm35.h"
#include "../HAL/Motor/motor.h"
#include "../HAL/LDR/ldr.h"
#include "../HAL/LED/led.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

int main(void)
{
	LCD_init();
	ADC_init();
	DCMotor_Init();
	LEDS_init();
	LCD_ShowInfo();

	DCMotor_State state = Stop;
	uint8 tempVal 		= (uint8)INIT_VALUE_ZERO;
	uint16 ldrVal 		= (uint16)INIT_VALUE_ZERO;

	while(1)
	{
		tempVal = LM35_getTemperature();
		ldrVal = LDR_getLightIntensity();
		state = DCMotor_config(tempVal);

		LED_config(ldrVal);
		LCD_ShowData(state, tempVal, ldrVal);
	}
}
