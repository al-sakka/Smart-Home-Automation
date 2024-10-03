/******************************************************************************
*
* Module: DC Motor
*
* File Name: motor.c
*
* Description: Source file for the DC Motor driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include "../../Utils/std_types.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/PWM/pwm.h"
#include "motor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/*
 * Initializes the DC motor by setting the direction for the motor pins
 * and stopping the motor at the beginning
 */
void DCMotor_Init(void)
{
	GPIO_setupPinDirection(IN1_PORT, IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(IN2_PORT, IN2_PIN, PIN_OUTPUT);

	GPIO_setupPinDirection(EN1_PORT, EN1_PIN, PIN_OUTPUT);

	GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
	GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);

	PWM_Timer0_init();
	PWM_Timer0_Start(0);
}

/*
 *  Controls the motor's state (Clockwise/Anti-Clockwise/Stop)
 *  and adjusts the speed based on the input duty cycle.
 */
static void DCMotor_Rotate(DCMotor_State state, uint8 speed)
{
	switch(state)
	{
		case Stop:
			GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
			GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
			break;
		case CW:
			GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_HIGH);
			GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
			break;
		case A_CW:
			GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
			GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_HIGH);
			break;
	}

	uint8 _duty = (uint8)(PWM_MAX_VALUE * speed / PWM_OFFSET);

	PWM_Timer0_Start(_duty);
}

/*
 * Configure Motor Logic:
 * Temperature ≥ 40°C: Fan ON at 100% speed.
 * Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
 * Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
 * Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
 * Temperature < 25°C: Fan OFF.
 */
DCMotor_State DCMotor_config(uint8 temp)
{
	DCMotor_State motorState;

	if(temp >= 40)
    {
		motorState = CW;
        DCMotor_Rotate(motorState, 100);  /* Full speed */
    }
    else if((temp >= 35) && (temp < 40))
    {
    	motorState = CW;
        DCMotor_Rotate(motorState, 75);   /* 75% speed */
    }
    else if((temp >= 30) && (temp < 35))
    {
    	motorState = CW;
        DCMotor_Rotate(motorState, 50);   /* 50% speed */
    }
    else if((temp >= 25) && (temp < 30))
    {
    	motorState = CW;
        DCMotor_Rotate(motorState, 25);   /* 25% speed */
    }
    else
    {
    	motorState = Stop;
        DCMotor_Rotate(motorState, 0);  /* Stop the motor */
    }

	return (motorState);
}

