/******************************************************************************
*
* Module: LM35
*
* File Name: lm35.h
*
* Description: Header file for the LM35 driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#ifndef LM35_H_
#define LM35_H_

#include "../../MCAL/ADC/adc.h"
#include "../../Utils/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         (1u)
#define SENSOR_MAX_VOLT_VALUE     (1.5)
#define SENSOR_MAX_TEMPERATURE    (150ul)

/*******************************************************************************
 *                       Functions Prototypes                                  *
*******************************************************************************/

/*
 * Description :
 * Function to measure temperature from LM35 sensor using ADC channel
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
