/******************************************************************************
*
* Module: FLAME
*
* File Name: flame.c
*
* Description: Source file for the flame driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include "../../Utils/std_types.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../Buzzer/buzzer.h"
#include "../LCD/lcd.h"
#include "flame.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/*
 * Initializes the flame sensor pin direction.
 */
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

/*
 * Reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void)
{
	uint8 flameSensorValue = GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
	return (flameSensorValue);
}

/*
 * Configure flame logic (Buzzer + LCD)
 */
void FlameSensor_config(uint8 sensorValue)
{
	if(sensorValue)
	{
		Buzzer_on();
	}
	else
	{
		Buzzer_off();
	}
}
