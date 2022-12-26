 /******************************************************************************
 *
 * Module: can
 *
 * File Name: can.c
 *
 * Description: Source file to Initilaze can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/ 




#include "can.h"



/******************************  Variables  ******************************/
tCANMsgObject sCANMessage;
uint8_t pui8MsgData;          // store Transmitted data


/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */
static void (*g_Can_Call_Back_Ptr)(void) = NULL_PTR;


/************************************************************************************
* Name: initcan
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Initilaize can
************************************************************************************/
void initcan(){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

  /* Initialize the CAN controller*/
    CANInit(CAN0_BASE);

  /*Set up the bit rate for the CAN bus. */
    #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
      defined(TARGET_IS_TM4C129_RA1) ||                                         \
      defined(TARGET_IS_TM4C129_RA2)
      CANBitRateSet(CAN0_BASE, ui32SysClock, 500000);
    #else
      CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
    #endif
  
  /* Enable interrupts on the CAN peripheral.  */
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
  
  /* Enable the CAN interrupt on the processor (NVIC).
  */
    IntEnable(INT_CAN0);
    IntPrioritySet(INT_CAN0,0XE0);

  
  /* Enable the CAN for operation.*/
    CANEnable(CAN0_BASE);

    /*Initialize the message object that will be used for sending CAN
    messages.  The message will be 4 bytes that will contain an incrementing
    value.  Initially it will be set to 0.*/
    pui8MsgData = 0;
    sCANMessage.ui32MsgID = CAN0TXID;
    sCANMessage.ui32MsgIDMask = 0;
    sCANMessage.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    sCANMessage.ui32MsgLen = sizeof(pui8MsgData);
    sCANMessage.pui8MsgData = (uint8_t *)&pui8MsgData;

}

/************************************************************************************
* Name: CAN0IntHandler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Initilaize can
************************************************************************************/

void CAN0IntHandler(void)
{
  if (g_Can_Call_Back_Ptr != NULL_PTR)
  {
    (*g_Can_Call_Back_Ptr)();
  }
  
}

/************************************************************************************
* Name: cantransmit
* Reentrancy: reentrant
* Parameters (in):  pointer,index
* Return value: None
* Description:Transmit data with can bus
************************************************************************************/

void cantransmit(uint16 index)
{
  pui8MsgData = index; 
  CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);
}



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
void Can_SetCallBack(void(*Ptr2Func)(void))
{
  g_Can_Call_Back_Ptr = Ptr2Func;
}
