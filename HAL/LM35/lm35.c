/******************************************************************************
*
* Module: LM35
*
* File Name: lm35.c
*
* Description: Source file for the LM35 driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include "../../Utils/std_types.h"
#include "../../MCAL/ADC/adc.h"
#include "lm35.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/*
 * Description :
 * Function to measure temperature from LM35 sensor using ADC channel
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
	uint16 adc_digital_value = 0;

	adc_digital_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	temp_value = (uint8)(((uint32)adc_digital_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(SENSOR_MAX_VOLT_VALUE*ADC_MAXIMUM_VALUE));

	return (temp_value);
}


