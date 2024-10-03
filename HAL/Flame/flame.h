/******************************************************************************
*
* Module: FLAME
*
* File Name: flame.h
*
* Description: Header file for the flame driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#ifndef FLAME_H_
#define FLAME_H_

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/

#define FLAME_SENSOR_PORT_ID	(PORTD_ID)
#define FLAME_SENSOR_PIN_ID		(PIN2_ID)

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*
 * Initializes the flame sensor pin direction.
 */
void FlameSensor_init(void);

/*
 * Reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void);

/*
 * Configure flame logic (Buzzer + LCD)
 */
void FlameSensor_config(uint8 sensorValue);

#endif /* FLAME_FLAME_H_ */
