 /******************************************************************************
 *
 * [FILE NAME]: <sensor.h>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <03/11/2022>
 *
 * [DESCRIPTION]: <Header file for Humidity Sensor>
 *
 *******************************************************************************/


#ifndef HUMIDITY_SENSOR_H_
#define HUMIDITY_SENSOR_H_

#include "StandardTypes.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define HUMIDITY_SENSOR_CHANNEL         0
#define HUMIDITY_SENSOR_SCALE           4095

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the sensor from the ADC digital value.
 */
uint8 humidity_getread(void);

#endif /* HUMIDITY_SENSOR_H_ */