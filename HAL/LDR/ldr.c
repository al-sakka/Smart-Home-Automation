/******************************************************************************
*
* Module: LDR
*
* File Name: ldr.c
*
* Description: Source file for the LDR driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include "../../Utils/std_types.h"
#include "../../MCAL/ADC/adc.h"
#include "ldr.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/*
 * Reads the LDR sensor value and returns the light intensity
 */
uint16 LDR_getLightIntensity(void)
{
	uint16 adc_digital_value = (uint16)ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	uint16 ldr_value = (uint16)(((uint32)adc_digital_value*LDR_SENSOR_MAX_LIGHT_INTENSITY)/ADC_MAXIMUM_VALUE);

	return (ldr_value);
}
