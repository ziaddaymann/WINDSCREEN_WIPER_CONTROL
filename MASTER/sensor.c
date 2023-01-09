 /******************************************************************************
 *
 * [FILE NAME]: <sensor.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <03/11/2022>
 *
 * [DESCRIPTION]: <Source file for Humidity Sensor>
 *
 *******************************************************************************/

#include "tm4c123gh6pm.h"
#include "sensor.h"
#include "adc.h"

uint8 humidity_getread(void)
{
    // Read the ADC value for the humidity sensor
    uint32 adc_value = ADC_readChannel();

    // Convert the ADC value to a humidity value
    uint32 humidity = (adc_value / HUMIDITY_SENSOR_SCALE);

    // Return the humidity value
    return humidity;
}
