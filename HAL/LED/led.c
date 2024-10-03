/******************************************************************************
*
* Module: KEYPAD
*
* File Name: keypad.c
*
* Description: Source file for the Keypad driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include "led.h"
#include "../../MCAL/GPIO/gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/*
 * Initializes all Leds (red, green, blue) pins direction.
 * and Turn off all the Leds
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GRN_PORT_ID, LED_GRN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLU_PORT_ID, LED_BLU_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_ON);
	GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_ON);
	GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_ON);
}

/*
 * Turns on the specified LED.
 */
void LED_on(LED_ID id)
{
	switch(id)
	{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_ON);
			break;
		case LED_GRN:
			GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_ON);
			break;
		case LED_BLU:
			GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_ON);
			break;
	}
}

/*
 * Turns off the specified LED.
 */
void LED_off(LED_ID id)
{
	switch(id)
	{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_OFF);
			break;
		case LED_GRN:
			GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_OFF);
			break;
		case LED_BLU:
			GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_OFF);
			break;
	}
}

/*
 * Configure LEDs based on the LDR readings:
 * Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
 * Intensity 16–50%: Red and Green LEDs turn ON.
 * Intensity 51–70%: Only the Red LED turns ON.
 * Intensity > 70%: All LEDs are turned OFF.
 */
void LED_config(uint16 a_ldr)
{
	if (a_ldr < 15)
	{
		LED_on(LED_RED);
		LED_on(LED_GRN);
		LED_on(LED_BLU);
	}
	else if ((a_ldr >= 15) && (a_ldr < 50))
	{
		LED_on(LED_RED);
		LED_on(LED_GRN);
		LED_off(LED_BLU);
	}
	else if ((a_ldr >= 50) && (a_ldr < 70))
	{
		LED_on(LED_RED);
		LED_off(LED_GRN);
		LED_off(LED_BLU);
	}
	else	/* a_ldr >= 70 */
	{
		LED_off(LED_RED);
		LED_off(LED_GRN);
		LED_off(LED_BLU);
	}
}
