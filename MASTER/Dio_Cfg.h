  /******************************************************************************
 *
 * [FILE NAME]: <Dio_Cfg.h>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <03/11/2022>
 *
 * [DESCRIPTION]: <Header file for Pre Compile Configurations>
 *
 *******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H



/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES              (1U)

/* Channel Index in the array of structures in Dio_PBcfg.c */


#define DioConf_LED_CHANNEL_ID_INDEX         (uint8)0x00

/* DIO Configured Port ID's  */

#define DioConf_LED_PORT_NUM                 (Dio_PortType)5 /* PORTF */

/* DIO Configured Channel ID's */
#define DioConf_LED_CHANNEL_NUM              (Dio_ChannelType)2 /* Pin 4 in PORTF */


#endif /* DIO_CFG_H */
