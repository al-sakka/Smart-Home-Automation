/******************************************************************************
*
* Module: DC Motor
*
* File Name: motor.h
*
* Description: Header file for the DC Motor driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#ifndef MOTOR_MOTOR_H_
#define MOTOR_MOTOR_H_

#include "../../Utils/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
*******************************************************************************/

#define IN1_PORT PORTB_ID
#define IN1_PIN  PIN0_ID

#define IN2_PORT PORTB_ID
#define IN2_PIN  PIN1_ID

#define EN1_PORT PORTB_ID
#define EN1_PIN  PIN3_ID


typedef enum
{
	Stop,	/* 0 */
	CW,		/* 1 */
	A_CW	/* 2 */
} DCMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
*******************************************************************************/

/*
 * Initializes the DC motor by setting the direction for the motor pins
 * and stopping the motor at the beginning
 */
void DCMotor_Init(void);

/*
 * Configure Motor Logic
 */
DCMotor_State DCMotor_config(uint8 temp);

#endif /* MOTOR_MOTOR_H_ */
