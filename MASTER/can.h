 /******************************************************************************
 *
 * Module: can
 *
 * File Name: can.h
 *
 * Description: Header file to Initilaze can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/ 


#ifndef CAN
#define CAN

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom_map.h"
#include "StandardTypes.h"

#define CAN0TXID                1   //id for msg
#define TXOBJECT                1



/************************************************************************************
* Name: CAN0IntHandler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Responsible for Handling can interrupts
************************************************************************************/

void CAN0IntHandler(void);

/************************************************************************************
* Name: initcan
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Initilaize can
***********************************************************************************/
void initcan();

/************************************************************************************
* Name: cantransmit
* Reentrancy: reentrant
* Parameters (in):  pointer,index
* Return value: None
* Description:Transmit data with can bus
********************************************************************************/
void cantransmit(uint16 index);

/************************************************************************************
* Service Name: Can_SetCallBack
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Ptr2Func - Call Back function address
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the Can call back
************************************************************************************/
void Can_SetCallBack(void(*Ptr2Func)(void));

#endif