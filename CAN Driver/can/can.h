 /******************************************************************************
 *
 * Module: CAN
 *
 * File Name: can.h
 *
 * Description:  Header file for STM32F405RG Microcontroller - CAN Driver.
 *
 * Author: Fayrouz Bakr & Kareem mohamed
 ******************************************************************************/

#ifndef CAN_H
#define CAN_H

#include "can_cfg.h"
#include "Common_Macros.h"

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* Id for the company in the AUTOSAR */
#define CAN_VENDOR_ID                 (0x0026)

/* CAN Module Id */
#define CAN_MODULE_ID                 (15U)

/* Instance Id */
#define CAN_INSTANCE_ID               (0U)

/*
 * CAN Software Module Version 1.0.0
 */
#define CAN_SW_MAJOR_VERSION          (1U)
#define CAN_SW_MINOR_VERSION          (0U)
#define CAN_SW_PATCH_VERSION          (0U)

/*
 * AUTOSAR Version 4.0.0
 */
#define CAN_AR_RELEASE_MAJOR_VERSION          (4U)
#define CAN_AR_RELEASE_MINOR_VERSION          (0U)
#define CAN_AR_RELEASE_PATCH_VERSION          (0U)


/* AUTOSAR checking between Std Types and CAN Modules */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (CAN_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (CAN_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

   
 /* AUTOSAR Version checking between can_cfg.h and can.h files */
#if ((CAN_CFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
  || (CAN_CFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
  || (CAN_CFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of can_Cfg.h does not match the expected version"
#endif

/* Software Version checking between can_cfg.h and can.h files */
#if ((CAN_CFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
  || (CAN_CFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
  || (CAN_CFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
  #error "The SW version of can_cfg.h does not match the expected version"
#endif
   
   
   
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Can_Init */
#define CAN_INIT_API                             (uint8)0x00


/* Service ID for Can_GetVersionInfo */
#define CAN_VERSION_INFO_API                     (uint8)0x07


/* Service ID for  Can_CheckBaudrate*/
#define CAN_CHECK_BAUDRATE_API                   (uint8)0x0E


/* Service ID for Can_ChangeBaudrate */
#define CAN_CHANGE_BAUDRATE_API                  (uint8)0x0D


/* Service ID for  Can_SetControllerMode */
#define CAN_SET_CONTROLLER_MODE_API              (uint8)0x03


/* Service ID for  Can_DisableControllerInterrupts */
#define CAN_DISABLE_CONTROLLER_INTERRUPTS_API    (uint8)0x04


/* Service ID for  Can_EnableControllerInterrupts */
#define CAN_ENABLE_CONTROLLER_INTERRUPTS_API     (uint8)0x05


/* Service ID for  Can_CheckWakeup */
#define CAN_CHECK_WAKEUP_API                     (uint8)0x0b


/* Service ID for  Can_Write */
#define CAN_WRITE_API                            (uint8)0x06


/* Service ID for  Can_MainFunction_Write */
#define CAN_MAINFUNCTION_WRITE_API               (uint8)0x01


/* Service ID for  Can_MainFunction_Read */
#define CAN_MAINFUNCTION_READ_API                (uint8)0x08


/* Service ID for  Can_MainFunction_BusOff */
#define CAN_MAINFUNCTION_BUSOFF_API              (uint8)0x09



/* Service ID for  Can_MainFunction_Wakeup */
#define CAN_MAINFUNCTION_WAKEUP_API              (uint8)0x0a


/* Service ID for  Can_MainFunction_Mode */
#define CAN_MAINFUNCTION_MODE_API                (uint8)0x0c

/******************************************************************************/

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
   
/* DET code to report wrong parameter */
#define CAN_E_PARAM_POINTER                         (uint8)0x01
#define CAN_E_PARAM_HANDLE                          (uint8)0x02
#define CAN_E_PARAM_DLC                             (uint8)0x03
#define CAN_E_PARAM_CONTROLLER                      (uint8)0x04
  
/* DET code to report API service called without module initialization*/
#define CAN_E_UNINIT                                (uint8)0x05
 
/* DET code to report APIs called with Invalid transition for the current mode*/
#define CAN_E_TRANSITION                            (uint8)0x06
   
/* DET code to report APIs called with Received CAN message is lost*/
#define CAN_E_DATALOST                              (uint8)0x07
   
   
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
 
/******************************************************************************************************
*  Describtion : This is the type of the external data structure containing the overall initialization 
*  data for the CAN driver and SFR settings affecting all controllers. Furthermore it 
*  contains pointers to controller configuration structures. The contents of the 
*  initialization data structure are CAN hardware specific.
******************************************************************************************************/

/* For ENABLE & DISABLE STATED BITS */   
typedef enum
{
  DISABLE , ENABLE 
}FunctionalState;
   
   
   
typedef struct
{
  uint16 CAN_Prescaler;           /* Specifies the length of a time quantum. 
                                  It ranges from 1 to 1024. */
  
  uint8 CAN_Mode;               /* Specifies the CAN operating mode.
                                  This parameter can be a value of @ref CAN_operating_mode */

  uint8 CAN_SJW;                /* Specifies the maximum number of time quanta 
                                  the CAN hardware is allowed to lengthen or 
                                  shorten a bit to perform resynchronization.
                                  This parameter can be a value of @ref CAN_synchronisation_jump_width */

  uint8 CAN_BS1;                /* Specifies the number of time quanta in Bit 
                                  Segment 1. This parameter can be a value of 
                                  @ref CAN_time_quantum_in_bit_segment_1 */

  uint8 CAN_BS2;                /* Specifies the number of time quanta in Bit Segment 2.
                                  This parameter can be a value of @ref CAN_time_quantum_in_bit_segment_2 */
  
  FunctionalState CAN_TTCM;       /* Enable or disable the time triggered communication mode.
                                  This parameter can be set either to ENABLE or DISABLE. */
  
  FunctionalState CAN_ABOM;       /* Enable or disable the automatic bus-off management.
                                  This parameter can be set either to ENABLE or DISABLE. */

  FunctionalState CAN_AWUM;       /* Enable or disable the automatic wake-up mode. 
                                  This parameter can be set either to ENABLE or DISABLE. */

  FunctionalState CAN_NART;       /* Enable or disable the non-automatic retransmission mode.
                                  This parameter can be set either to ENABLE or DISABLE. */

  FunctionalState CAN_RFLM;       /* Enable or disable the Receive FIFO Locked mode.
                                  This parameter can be set either to ENABLE or DISABLE. */

  FunctionalState CAN_TXFP;       /* Enable or disable the transmit FIFO priority.
                                  This parameter can be set either to ENABLE or DISABLE. */
}Can_ConfigType;



/*******************************************************************************************
*  Describtion : This is the type of the external data structure containing the bit timing related 
*  initialization data for one CAN controller. The contents of the initialization data 
*  structure are CAN hardware specific. 
*******************************************************************************************/
typedef struct
{
    uint16 BaudRateConfigIDs;   /* Baude Rate ID */
    uint16 BaudRate;            /* Baud rate in Kbps */
    uint8  TSEG2 ;              /* Time Segment after Sample Pointing in quanta */
    uint8  TSEG1 ;              /* Time Segment before Sample Pointing in quanta */
    uint8  SJW   ;              /* (Re)Synchronization Jump Width in quanta */

}Can_ControllerBaudrateConfigType;


/* uint16: if only Standard IDs are used */
/* uint32: if also Extended IDs are used */
typedef uint32 Can_IdType;

typedef uint16 PduIdType;

/***********************************************************************************************
*  Describtion : This type is used to provide ID, DLC and SDU from CAN interface to CAN driver. 
************************************************************************************************/
typedef struct
{
    PduIdType  swPduHandle;        /* ID of the PDU */
    uint8  length;                 
    Can_IdType  id;
    uint8*  sdu;                 /* SDU Service Data unit */
}Can_PduType;



/***********************************************************************************************
*  Describtion : Represents the hardware object handles of a CAN hardware unit. For CAN 
*  hardware units with more than 255 HW objects use extended range. 
************************************************************************************************/
typedef uint16 Can_HwHandleType ;



/***********************************************************************************************
*  Describtion : State transitions that are used by the function CAN_SetControllerMode.  
************************************************************************************************/
typedef enum
{
   CAN_T_START , CAN_T_STOP  , CAN_T_SLEEP , CAN_T_WAKEUP
}Can_StateTransitionType;


/***********************************************************************************************
*  Describtion : Return values of CAN driver API .   
************************************************************************************************/
typedef enum
{
  CAN_OK , CAN_NOT_OK , CAN_BUSY
}Can_ReturnType;
   
   
   
   
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
              );

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

#endif /* CAN_H */
