/******************************************************************************
*
* Module: LDR
*
* File Name: ldr.h
*
* Description: Header file for the LDR driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#ifndef LDR_H_
#define LDR_H_


/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/

#define LDR_SENSOR_CHANNEL_ID			(0)
#define LDR_SENSOR_MAX_VOLT_VALUE		(2.56)
#define LDR_SENSOR_MAX_LIGHT_INTENSITY	(100u)

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*
 * Reads the LDR sensor value and returns the light intensity
 */
uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
