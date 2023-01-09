  /******************************************************************************
 *
 * [FILE NAME]: <Port_PBcfg.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <03/11/2022>
 *
 * [DESCRIPTION]: <Source file for Post Compile Confg>
 *
 *******************************************************************************/
#include "Port.h"



/* PB structure used with Port_Init API */
const Port_ConfigType Port_ConfigSet[] = {
     PortConf_PORTA_NUM,PortConf_Pin0_CHANNEL_NUM,NOT_IN_OR_OUT,RESISTOR_OFF,PortConf_PortA_Pin0_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTA_NUM,PortConf_Pin1_CHANNEL_NUM,NOT_IN_OR_OUT,RESISTOR_OFF,PortConf_PortA_Pin1_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTA_NUM,PortConf_Pin2_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortA_Pin2_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTA_NUM,PortConf_Pin3_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortA_Pin3_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTA_NUM,PortConf_Pin4_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortA_Pin4_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTA_NUM,PortConf_Pin5_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortA_Pin5_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTA_NUM,PortConf_Pin6_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortA_Pin6_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTA_NUM,PortConf_Pin7_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortA_Pin7_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
 
     PortConf_PORTB_NUM,PortConf_Pin0_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortB_Pin0_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTB_NUM,PortConf_Pin1_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortB_Pin1_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTB_NUM,PortConf_Pin2_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortB_Pin2_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTB_NUM,PortConf_Pin3_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortB_Pin3_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTB_NUM,PortConf_Pin4_CHANNEL_NUM,NOT_IN_OR_OUT,RESISTOR_OFF,PortConf_PortB_Pin4_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTB_NUM,PortConf_Pin5_CHANNEL_NUM,NOT_IN_OR_OUT,RESISTOR_OFF,PortConf_PortB_Pin5_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTB_NUM,PortConf_Pin6_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortB_Pin6_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTB_NUM,PortConf_Pin7_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortB_Pin7_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     
     PortConf_PORTC_NUM,PortConf_Pin0_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortC_Pin0_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTC_NUM,PortConf_Pin1_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortC_Pin1_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTC_NUM,PortConf_Pin2_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortC_Pin2_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTC_NUM,PortConf_Pin3_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortC_Pin3_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTC_NUM,PortConf_Pin4_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortC_Pin4_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTC_NUM,PortConf_Pin5_CHANNEL_NUM,PORT_PIN_OUT,RESISTOR_OFF,PortConf_PortC_Pin5_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTC_NUM,PortConf_Pin6_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortC_Pin6_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTC_NUM,PortConf_Pin7_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortC_Pin7_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     
     PortConf_PORTD_NUM,PortConf_Pin0_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin0_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTD_NUM,PortConf_Pin1_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin1_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTD_NUM,PortConf_Pin2_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin2_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTD_NUM,PortConf_Pin3_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin3_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTD_NUM,PortConf_Pin4_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin4_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTD_NUM,PortConf_Pin5_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin5_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTD_NUM,PortConf_Pin6_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin6_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTD_NUM,PortConf_Pin7_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortD_Pin7_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     
     PortConf_PORTE_NUM,PortConf_Pin0_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortE_Pin0_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTE_NUM,PortConf_Pin1_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortE_Pin1_Mode,PORT_PIN_ANALOG,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTE_NUM,PortConf_Pin2_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortE_Pin2_Mode,PORT_PIN_ANALOG,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTE_NUM,PortConf_Pin3_CHANNEL_NUM,PORT_PIN_IN,PULL_UP,PortConf_PortE_Pin3_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTE_NUM,PortConf_Pin4_CHANNEL_NUM,PORT_PIN_OUT,RESISTOR_OFF,PortConf_PortE_Pin4_Mode,PORT_PIN_ANALOG,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTE_NUM,PortConf_Pin5_CHANNEL_NUM,PORT_PIN_IN,RESISTOR_OFF,PortConf_PortE_Pin5_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     
     PortConf_PORTF_NUM,PortConf_Pin0_CHANNEL_NUM,PORT_PIN_IN,PULL_UP,PortConf_PortF_Pin0_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTF_NUM,PortConf_Pin1_CHANNEL_NUM,PORT_PIN_OUT,PULL_DOWN,PortConf_PortF_Pin1_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTF_NUM,PortConf_Pin2_CHANNEL_NUM,PORT_PIN_OUT,PULL_DOWN,PortConf_PortF_Pin2_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTF_NUM,PortConf_Pin3_CHANNEL_NUM,PORT_PIN_OUT,PULL_DOWN,PortConf_PortF_Pin3_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW,
     PortConf_PORTF_NUM,PortConf_Pin4_CHANNEL_NUM,PORT_PIN_IN,PULL_UP,PortConf_PortF_Pin4_Mode,PORT_PIN_DIGITAL,PORT_PIN_CHANGEABLE,PORT_MODE_UNCHANGEABLE,OPEN_DRAIN_DISABLE,STD_LOW
				         };

