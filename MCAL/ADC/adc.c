/******************************************************************************
*
* Module: ADC
*
* File Name: adc.c
*
* Description: source file for the ATmega16/32 ADC driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include <avr/io.h>
#include "adc.h"
#include "../../Utils/common_macros.h"
#include "../GPIO/gpio.h"

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*
* Description :
* Function responsible for initialize the ADC driver.
*/
void ADC_init(void)
{
	/* Internal 2.56V Voltage Reference with external capacitor at AREF pin */
    ADMUX = (1 << REFS1) | (1 << REFS0);

    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);  /* N = 128 */

    GPIO_setupPinDirection(LM35_PORT_ID, LM35_PIN_ID, PIN_INPUT);
    GPIO_setupPinDirection(LDR_PORT_ID, LDR_PIN_ID, PIN_INPUT);
}

/*
* Description :
* Function responsible for read analog data from a certain ADC channel (0:7)
* and convert it to digital using the ADC driver.
*/
uint16 ADC_readChannel(uint8 channel_num)
{
    ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);
    SET_BIT(ADCSRA, ADSC);
    while(BIT_IS_CLEAR(ADCSRA, ADIF));      /* Polling */
    SET_BIT(ADCSRA, ADIF);
    return (ADC);
}
