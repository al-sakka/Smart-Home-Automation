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
#include "../HAL/Flame/flame.h"
#include "../HAL/Buzzer/buzzer.h"
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
	FlameSensor_init();
	Buzzer_init();
	LCD_ShowInfo();

	DCMotor_State state 	= Stop;
	uint8 currentFlameVal	= (uint8)INIT_VALUE_ZERO;
	uint8 *prevFlameVal		= (uint8 *)NULL_PTR;
	uint8 tempVal 			= (uint8)INIT_VALUE_ZERO;
	uint16 ldrVal 			= (uint16)INIT_VALUE_ZERO;

	while(1)
	{
		tempVal = LM35_getTemperature();
		ldrVal = LDR_getLightIntensity();
		state = DCMotor_config(tempVal);
		currentFlameVal = FlameSensor_getValue();

		LED_config(ldrVal);
		LCD_config(&prevFlameVal, currentFlameVal, state, tempVal, ldrVal);
		FlameSensor_config(currentFlameVal);
	}
}
