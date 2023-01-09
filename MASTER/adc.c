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
#include "Common_Macros.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(void){
	SET_BIT(SYSCTL_RCGCGPIO_R, 4);
	SET_BIT(SYSCTL_RCGCADC_R, 0);
	SET_BIT(GPIO_PORTE_CR_R, 3); 
        CLEAR_BIT(GPIO_PORTE_DIR_R, 3);  // input
        CLEAR_BIT(GPIO_PORTE_DEN_R, 3);  // disaple the digital function
  //Set_Bit(GPIO_PORTE_PUR_R, 3);    // pullup resistance
	SET_BIT(GPIO_PORTE_AFSEL_R, 3);  // alternative function
	SET_BIT(GPIO_PORTE_AMSEL_R, 3);  // analog function
	CLEAR_BIT(ADC0_ACTSS_R, 3);      // disable SS3 during config
	ADC0_EMUX_R &=~ 0xF000; 
	ADC0_SSMUX3_R = 0;
	ADC0_SSCTL3_R |= 6;
	SET_BIT(ADC0_ACTSS_R, 3);
}

int ADC_readChannel(void){
	SET_BIT(ADC0_PSSI_R, 3);
	while((ADC0_RIS_R & 8) == 0);
	ADC0_ISC_R = 8;
	return ADC0_SSFIFO3_R;
	
}
