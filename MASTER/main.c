#include "Dio.h"
#include "Port.h"
#include "adc.h"
#include "can.h"
#include "sensor.h"
#include "tm4c123gh6pm.h"
#include "UART.h"



/************ Define for interrupt to be easily used **************************/
#define Enable_Interrupts()    __asm("CPSIE I")
#define Disable_Interrupts()   __asm("CPSID I")
#define Enable_Exceptions()    __asm("CPSIE F")
#define Disable_Exceptions()   __asm("CPSID F") 
#define Wait_For_Interrupt()   __asm("WFI")


uint8 state =0;
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

    
    else if(ui32Status == TXOBJECT)
    {
        /*
        Getting to this point means that the TX interrupt occurred on
        message object TXOBJECT, and the message reception is complete.
        Clear the message object interrupt.
        */
        CANIntClear(CAN0_BASE, TXOBJECT);

        /*
        Since a message was transmitted, clear any error flags.
        This is done because before the message is transmitted it triggers
        a Status Interrupt for TX complete. by clearing the flag here we
        prevent unnecessary error handling from happeneing
        */
        g_bErrFlag  = 0;
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

void transmit_state (uint8 msg)
{
  cantransmit (msg);
}

int main ()
{
  Enable_Interrupts();
  Dio_Init (&Dio_Configuration);
  Port_Init (&Port_ConfigSet[0]);
  initcan();
  UART0Init();
  Can_SetCallBack (CAN_Refresh);
  ADC_init();
  
  while (1)
  {
    uint8 sensor;
    
    sensor = humidity_getread();
    if (sensor > 0.5)
    {
      Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,LOGIC_HIGH);
      state =1;
      print("1");
    }
    
    else if (sensor < 0.5)
    {
      Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,LOGIC_LOW);
      state =0;
      print("0");
    }
    
    print("\n");
 transmit_state (sensor);

  }
    
}
