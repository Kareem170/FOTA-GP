/******************************************************************************
 *
 * Module: can
 *
 * File Name: can.c
 *
 * Description: Source file for STM32F405RG Microcontroller - can Driver.
 *
 * Author: Fayrouz Bakr & Kareem Mohamed
 ******************************************************************************/

#include "can.h"
#include "can_regs.h"

/*******************************************************************************
                            GLOBAL VARIABLES
*******************************************************************************/
uint8 InitStatus = CAN_INIT_STATUS_FAILED;


#if (CAN_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Can_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Config - Pointer to driver configuration.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function initializes the module.
************************************************************************************/
void Can_Init( 
              const Can_ConfigType* Config 
              )
{

uint32 wait_ack = 0x00000000;

/* Exit from sleep mode */
CLEAR_BIT(*(volatile uint32*)((volatile uint8*)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_SLEEP);

/* Request initialisation */
SET_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_INRQ);
  
/* Wait the acknowledge */
while (((*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MSR_OFFSET) & CAN_MSR_INAK) != CAN_MSR_INAK) && (wait_ack != INAK_TIMEOUT))
{
  wait_ack++;
}

/* Check acknowledge */
if ((*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MSR_OFFSET) & CAN_MSR_INAK) != CAN_MSR_INAK)
{
  InitStatus = CAN_INIT_STATUS_FAILED;
}
  else 
  {
    /* Set the time triggered communication mode */
    if (Config->CAN_TTCM == ENABLE)
    {
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_TTCM);

    }
    else
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_TTCM);
    }

    /* Set the automatic bus-off management */
    if (Config->CAN_ABOM == ENABLE)
    {
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_ABOM);
    }
    else
    {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_ABOM);
    }

    /* Set the automatic wake-up mode */
    if (Config->CAN_AWUM == ENABLE)
    {
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_AWUM);
    }
    else
    {
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_AWUM);
    }

    /* Set the no automatic retransmission */
    if (Config->CAN_NART == ENABLE)
    {
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_NART);
    }
    else
    {
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_NART);

    }

    /* Set the receive FIFO locked mode */
    if (Config->CAN_RFLM == ENABLE)
    {
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_RFLM);
    }
    else
    {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_RFLM);
    }

    /* Set the transmit FIFO priority */
    if (Config->CAN_TXFP == ENABLE)
    {
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_TXFP);
    }
    else
    {
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_TXFP);
    }

    /* Set the bit timing register */
    (*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_BTR_OFFSET)) 
      = (uint32)((uint32)Config->CAN_Mode << LBKM_PIN_NO)|\
                ((uint32)Config->CAN_SJW << SJW_PIN_NO)|\
                ((uint32)Config->CAN_BS1 << TS1_PIN_NO)|\
                ((uint32)Config->CAN_BS2 << TS2_PIN_NO)|\
                ((uint32)Config->CAN_Prescaler - 1);

    /* Request leave initialisation */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MCR_OFFSET) ,CAN_MCR_INRQ);

   /* Wait the acknowledge */
    wait_ack = 0;

   while (((*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MSR_OFFSET) & CAN_MSR_INAK) == CAN_MSR_INAK) && (wait_ack != INAK_TIMEOUT))
   {
     wait_ack++;
   }

    /* ...and check acknowledged */
    if ((*(volatile uint32 *)((volatile uint8 *)CANX_BASE_ADDRESS + CAN_MSR_OFFSET) & CAN_MSR_INAK) == CAN_MSR_INAK)
    {
      InitStatus = CAN_INIT_STATUS_FAILED;
    }
    else
    {
      InitStatus = CAN_NOT_INIT_STATUS_SUCCEED ;
    }
  }

}

/************************************************************************************
* Service Name: Can_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo-Pointer to where to store the version information of this module
* Return value: None
* Description: This function returns the version information of this module. 
************************************************************************************/
 void Can_GetVersionInfo( 
                       Std_VersionInfoType* versioninfo 
                        );

/************************************************************************************
* Service Name: Can_CheckBaudrate
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller - CAN Controller to check for the support of a certain baudrate.
                   Baudrate - Baudrate to check in kbps
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType :  E_OK: Baudrate supported by the CAN Controller 
                                  E_NOT_OK: Baudrate not supported / invalid CAN controller
* Description: This service shall check if a certain CAN controller supports a requested baudrate
************************************************************************************/
Std_ReturnType Can_CheckBaudrate( 
                                  uint8 Controller, 
                                  const uint16 Baudrate 
                                  ); 
/************************************************************************************
* Service Name: Can_ChangeBaudrate
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller - CAN Controller, whose baudrate shall be changed
                   Baudrate - Requested baudrate in kbps 
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType: E_OK: Service request accepted, baudrate change started 
                                E_NOT_OK: Service request not accepted 
* Description: This service shall change the baudrate of the CAN controller.
************************************************************************************/
 Std_ReturnType Can_ChangeBaudrate( 
                                  uint8 Controller, 
                                  const uint16 Baudrate 
                                   );

/************************************************************************************
* Service Name: Can_SetControllerMode
* Sync/Async: Asynchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller - CAN controller for which the status shall be changed 
                  Transition - Transition value to request new CAN controller state 
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType:  CAN_OK: request accepted 
                                 CAN_NOT_OK: request not accepted, a development error occurred
 
* Description: This function performs software triggered state transitions of the CAN controller 
State machine. 
************************************************************************************/
Can_ReturnType Can_SetControllerMode( 
                                    uint8 Controller, 
                                    Can_StateTransitionType Transition 
                                    ); 
/************************************************************************************
* Service Name: Can_DisableControllerInterrupts
* Sync/Async: Synchronous
* Reentrancy: Reentrant 
* Parameters (in): Controller - CAN controller for which interrupts shall be disabled. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function disables all interrupts for this CAN controller. 
************************************************************************************/
void Can_DisableControllerInterrupts( 
                                    uint8 Controller 
                                    ); 

/************************************************************************************
* Service Name: Can_EnableControllerInterrupts
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Controller - CAN controller for which interrupts shall be re-enabled
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function enables all allowed interrupts. 
************************************************************************************/
void Can_EnableControllerInterrupts( 
                                   uint8 Controller 
                                   );


/************************************************************************************
* Service Name: Can_CheckWakeup
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Controller - Controller to be checked for a wakeup. 
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType : CAN_OK: A wakeup was detected for the given controller. 
                                 CAN_NOT_OK: No wakeup was detected for the given controller. 
* Description: This function checks if a wakeup has occurred for the given controller. 
************************************************************************************/
Can_ReturnType Can_CheckWakeup( 
                              uint8 Controller 
                               ); 


/************************************************************************************
* Service Name: Can_Write
* Sync/Async: Synchronous
* Reentrancy: Reentrant (thread-safe) 
* Parameters (in): Hth - information which HW-transmit handle shall be used for transmit. 
                         Implicitly this is also the information about the controller to use 
                         because the Hth numbers are unique inside one hardware unit
                PduInfo - Pointer to SDU user memory, DLC and Identifier. 
* Parameters (inout): None
* Parameters (out): None
* Return value: Can_ReturnType : CAN_OK: Write command has been accepted 
                                 CAN_NOT_OK: development error occurred 
                                 CAN_BUSY: No TX hardware buffer available or pre-emptive call 
                                           of Can_Write that can't be implemented re-entrant 
* Description: This function Can_Write first checks if the hardware transmit object that is identified 
by the HTH is free and if another Can_Write is ongoing for the same HTH.
************************************************************************************/
Can_ReturnType Can_Write( 
                        Can_HwHandleType Hth, 
                        const Can_PduType* PduInfo 
                        ); 


/**********************************************************************************************************************************************
* Service Name: Can_MainFunction_Write 
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING. 
***********************************************************************************************************************************************/
void Can_MainFunction_Write( 
                            void
                            );


/*****************************************************************************************************************
* Service Name: Can_MainFunction_Read 
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING. 
*********************************************************************************************************************/
void Can_MainFunction_Read(
                           void
                           );

/*****************************************************************************************************************
* Service Name: Can_MainFunction_BusOff 
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function performs the polling of bus-off events that are configured statically as 'to be polled'. 
*********************************************************************************************************************/
void Can_MainFunction_BusOff( 
                             void 
                             );

/*****************************************************************************************************************
* Service Name: Can_MainFunction_Wakeup
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function performs the polling of wake-up events that are configured statically as 'to be polled'. 
*********************************************************************************************************************/
void Can_MainFunction_Wakeup( 
                             void
                             ); 

/************************************************************************************
* Service Name: Can_MainFunction_Mode
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: This function performs the polling of CAN controller mode transitions.
************************************************************************************/
void Can_MainFunction_Mode ( 
                            void 
                            );