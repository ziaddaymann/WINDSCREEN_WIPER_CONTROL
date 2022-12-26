 /******************************************************************************
 *
 * [FILE NAME]: <adc.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <03/11/2022>
 *
 * [DESCRIPTION]: <Source file for ADC>
 *
 *******************************************************************************/

#include "adc.h"
#include "Common_Macros.h" /* To use the macros like SET_BIT */
#include "tm4c123gh6pm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(void)
{
    // Enable the clock for the ADC module
    SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;
    // Wait for the ADC module to be ready
    while(!(SYSCTL_PRADC_R & SYSCTL_PRADC_R0));

    // Configure the ADC to use sample sequence 3
    ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN3;
    ADC0_EMUX_R &= ~ADC_EMUX_EM3_M;
    ADC0_SSMUX3_R = 0; // Set channel 0 as the input for sample sequence 3
    ADC0_SSCTL3_R = ADC_SSCTL3_END0; // End sample sequence after 1 sample
    ADC0_IM_R &= ~ADC_IM_MASK3; // Disable interrupts for sample sequence 3
    ADC0_ACTSS_R |= ADC_ACTSS_ASEN3; // Enable sample sequence 3

    // Enable the ADC
    ADC0_ACTSS_R |= ADC_ACTSS_ASEN0;

}

uint16 ADC_readChannel(uint8 channel_num)
{
    // Configure the input channel for sample sequence 3
    ADC0_SSMUX3_R = channel_num;

    // Start the conversion
    ADC0_PSSI_R = ADC_PSSI_SS3;

    // Wait for the conversion to complete
    while(!(ADC0_RIS_R & ADC_RIS_INR3));

    // Clear the conversion complete flag
    ADC0_ISC_R = ADC_ISC_IN3;

    // Return the result of the conversion
    return ADC0_SSFIFO3_R;

}
