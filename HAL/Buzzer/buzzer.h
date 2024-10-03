/******************************************************************************
*
* Module: BUZZER
*
* File Name: buzzer.h
*
* Description: Header file for the buzzer driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/

#define BUZZER_PORT_ID		(PORTD_ID)
#define BUZZER_PIN_ID		(PIN3_ID)

#define BUZZER_ON			(LOGIC_HIGH)
#define BUZZER_OFF			(LOGIC_LOW)

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*
 * Initializes the buzzer pin direction and turn off the buzzer.
 */
void Buzzer_init(void);

/*
 * Activates the buzzer.
 */
void Buzzer_on(void);

/*
 * Deactivates the buzzer
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
