/******************************************************************************
 *
 * [FILE NAME]: <main.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <03/11/2022>
 *
 * [DESCRIPTION]: <Source file for main function>
 *
 *******************************************************************************/



#include "Dio.h"
#include "Port.h"
#include "can.h"
#include "tm4c123gh6pm.h"



/* A flag to indicate that some transmission error occurred.*/
volatile bool g_bErrFlag = 0;

/*A flag for the interrupt handler to indicate that a message was received.*/
volatile bool g_bRXFlag = 0;

void CAN_Refresh(void)
{
  uint32_t ui32Status;
  
  /*Read the CAN interrupt status to find the cause of the interrupt*/
  ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);
  
  
  /*If the cause is a controller status interrupt, then get the status*/
  
  if(ui32Status == CAN_INT_INTID_STATUS)
  {
    /*
    Read the controller status.  This will return a field of status
    error bits that can indicate various errors.  Error processing
    is not done in this example for simplicity.  Refer to the
    API documentation for details about the error status bits.
    The act of reading this status will clear the interrupt.  If the
    CAN peripheral is not connected to a CAN bus with other CAN devices
    present, then errors will occur and will be indicated in the
    controller status.*/
    
    ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);
    
    /*
     Set a flag to indicate some errors may have occurred.
   */
    g_bErrFlag = 1;
  }

    /*
    Check if the cause is message object 1, which what we are using for
    sending messages.
    */

    
    else if(ui32Status == RXOBJECT)
    {
        /*
        Getting to this point means that the TX interrupt occurred on
        message object TXOBJECT, and the message reception is complete.
        Clear the message object interrupt.
        */
        CANIntClear(CAN0_BASE, RXOBJECT);

        /*
         Set flag to indicate received message is pending.
        */
        g_bRXFlag = 1;
    
        /*
        Since the message was recived, clear any error flags.
        */
        g_bErrFlag = 0;
    }

    /*
    Otherwise, something unexpected caused the interrupt.  This should
    never happen.
    */
    else
    {
        /*
        Spurious interrupt handling can go here.
        */
    }
}


uint8 ReceptionState (uint8 ID)
{
  static uint8 DATA;
  DATA = Can_Recieve(ID);
  return DATA;
}

int main()
{
  
  static uint8 Variable;
  Dio_Init (&Config);
  
  Port_Init (&Port_Configuration);
  
  initcan();
  
  Can_SetCallBack (CAN_Refresh);
  
  while (1)
  {
    Variable = ReceptionState(g_bRXFlag);
    
    if (Variable == 0)
    {
      Dio_WriteChannel (DioConf_LED_CHANNEL_ID_INDEX,LOGIC_HIGH);
    }
    
    else if (Variable == 1)
    {
      Dio_WriteChannel (DioConf_LED_CHANNEL_ID_INDEX,LOGIC_LOW);
    }
    
    
  }
}
