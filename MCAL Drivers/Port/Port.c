/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for STM32F4xx Micro-controller - Port Driver.
 *
 * Author: Boules Rufael
 *
 ******************************************************************************/

#include "Port.h"
#include "Det.h"
#include "Port_Regs.h"


#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
		|| (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
		|| (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
//#error "The AR version of Det.h does not match the expected version"
#endif

#endif

/*******************************************************************************
 *                              Golobal Variables                              *
 *******************************************************************************/
/* port initial status */
static uint8 Port_Status = PORT_NOT_INITIALIZED;


/*******************************************************************************
 *                               Static Functions                              *
 *******************************************************************************/
/* 
 *fn1 returns the port of the given PinId 
 */
static uint8 getPortId(Port_PinType PinId){  
#if (LQFP == 64)									/* for STM32F40xx LQFP64 pin out */
  if ( PinId < PORT_PD2 ) {
          return PinId / NUM_OF_PINS_PER_PORT;

  }else if (PinId == PORT_PD2){
          return PORTD;

  }else{
          return PORTH;
  }

#elif(LQFP == 100)									/* for STM32F40xx LQFP100 pin out */
  if ( PinId < PORT_PH0 ) {
          return PinId / NUM_OF_PINS_PER_PORT;

  }else{
          return PORTH;
  }
#endif
}


/*
 * fn2 returns pin position of the given PinId
 */
static uint8 getPinPos(Port_PinType PinId){
#if (LQFP == 64)									/* for STM32F40xx LQFP64 pin out */
  if ( PinId < PORT_PD2 ) {
          return PinId % NUM_OF_PINS_PER_PORT;

  }else if (PinId == PORT_PD2){
          return 2;

  }else{
          if (PinId == PORT_PH0){
                  return 0;
          }
          else {                                                                         /* PH1*/
                  return 1;
          }
  }

#elif(LQFP == 100)									/* for STM32F40xx LQFP100 pin out */
  if ( PinId < PORT_PH0 ) {
          return PinId % NUM_OF_PINS_PER_PORT;

  }else{
          if (PinId == PORT_PH0){
                  return 0;
          }
          else {										/* PH1*/
                  return 1;
          }
  }
#endif
}


/*
 * fn3 returns the address of the given PortId
 */
static volatile GPIO_TypeDef* getPortBasePtr(Port_PinType PinId_Port)
{
  /* calculating the PortId from the Port-PinId index */
  uint8 PortId = getPortId(PinId_Port);

  switch(PortId){
  case  PORTA:
          return (volatile GPIO_TypeDef *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
  case  PORTB:
          return (volatile GPIO_TypeDef *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
  case  PORTC:
          return (volatile GPIO_TypeDef *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
  case  PORTD:
          return (volatile GPIO_TypeDef *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
  case  PORTE:
          return (volatile GPIO_TypeDef *)GPIO_PORTE_BASE_ADDRESS; /* PORTD Base Address */
  case  PORTF:
          return (volatile GPIO_TypeDef *)GPIO_PORTF_BASE_ADDRESS; /* PORTD Base Address */
  case  PORTG:
          return (volatile GPIO_TypeDef *)GPIO_PORTG_BASE_ADDRESS; /* PORTD Base Address */
  case  PORTH:
          return (volatile GPIO_TypeDef *)GPIO_PORTH_BASE_ADDRESS; /* PORTH Base Address */
  case  PORTI:
          return (volatile GPIO_TypeDef *)GPIO_PORTI_BASE_ADDRESS; /* PORTH Base Address */
  default:
          return NULL_PTR;
  }
}


/*******************************************************************************
 *                          AutoSAR Defined Functions                          *
 *******************************************************************************/
/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr ){
/***** DET *****/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* check if the input configuration pointer is not a NULL_PTR */
  if (NULL_PTR == ConfigPtr){
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                          PORT_E_INIT_FAILED);
          return;
  }
  else {
          /* Do Nothing */
  }
#endif
/*****   *****/

  volatile GPIO_TypeDef * GPIOx_Ptr = NULL_PTR;

  uint8 Pin_Index = 0;
  for (Pin_Index = 0; Pin_Index < PINS_OF_ALL_PORTS; Pin_Index++){
    
          uint8 PinPos = getPinPos(Pin_Index);
          uint8 PortId = getPortId(Pin_Index);

          /* Ignore JTAG PINs */
          if ( Pin_Index >= PORT_PA13 &&  Pin_Index <= PORT_PA15){
            continue;
          }
          
          
          if (ConfigPtr->Pins[Pin_Index] != NULL_PTR){
                  Port_ConfigPin PinConfig = *(ConfigPtr->Pins[Pin_Index]);		/* pinConfig is  structure of configurations for each pin */

                  switch (PortId){
                  case PORTA:
                          GPIOx_Ptr = (volatile GPIO_TypeDef *)GPIO_PORTA_BASE_ADDRESS; /* PORTB Base Address */
                          RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;						  /* PORTA Enable*/
                          break;
                  case  PORTB:
                          GPIOx_Ptr = (volatile GPIO_TypeDef *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                          RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
                          break;
                  case  PORTC:
                          GPIOx_Ptr = (volatile GPIO_TypeDef *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                          RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
                          break;
                  case  PORTD:
                          GPIOx_Ptr = (volatile GPIO_TypeDef *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                          RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
                          break;
                  case  PORTH:
                          GPIOx_Ptr = (volatile GPIO_TypeDef *)GPIO_PORTH_BASE_ADDRESS; /* PORTH Base Address */
                          RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
                          break;
                  default:
                          /* if there's no such Port-PinId index in the MCU */
                          GPIOx_Ptr = NULL_PTR;
                  }

                  if (NULL_PTR != GPIOx_Ptr){
                          /* Start Mode configurations */
                          if(PinConfig.mode == PORT_DIO_MODE){
                                  if(PinConfig.direction == PORT_PIN_OUT){											/*!< Output direction*/
                                    
                                      GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Clear old configurations in MODER for PORT_Pin */
                                      GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_OUT << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Set new configurations in MODER for PORT_Pin as GPIO OUT */

                                      if(PinConfig.initial_value == STD_LOW){
                                              SET_BIT((GPIOx_Ptr->BSRRH), PinPos);          									/*!< At initial value Low setBit at Reset_Register(BSRRH) to Reset */
                                      } else {
                                              SET_BIT((GPIOx_Ptr->BSRRL), PinPos);										/*!< At initial value High setBit at set_Register(BSRRL) to Set */
                                      }

                                  }else {															/*!< Input direction default */
                                          GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Clear old configurations in MODER for PORT_Pin */
                                          GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_IN << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Set new configurations in MODER for PORT_Pin as GPIO IN*/

                                  }

                          }else if(PinConfig.mode == PORT_ANALOG_MODE){
                                  GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Clear old configurations in MODER for PORT_Pin */
                                  GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_AN << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Set new configurations in MODER for PORT_Pin as Analog */

                          }else if(PinConfig.mode <= PORT_ALTERNATE_FUNCTION_15_MODE){
                                  if(PinPos < 8){
                                          GPIOx_Ptr->AFR[0]	&= ~((uint32)PinConfig.mode << (PinPos * CONFG_PINS_P_PORT_4));				/*!< Set Alternate Function Register Low for pin(0:7) */
                                  } else {
                                          GPIOx_Ptr->AFR[1]	&= ~((uint32)PinConfig.mode << (PinPos * CONFG_PINS_P_PORT_4));				/*!< Set Alternate Function Register High for pin(8:15) */
                                  }

                                  GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Clear old configurations in MODER for PORT_Pin */
                                  GPIOx_Ptr->MODER |= ((uint32)(GPIO_Mode_AF) << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Set new configurations in MODER for PORT_Pin as Alternate Function */
                          } /* End Mode configurations */


                          /* Set OutputType & Speed configurations */
                          if ( (PinConfig.mode == PORT_DIO_MODE && PinConfig.direction == PORT_PIN_OUT) ||
                                          (PinConfig.mode <= PORT_ALTERNATE_FUNCTION_15_MODE) )												/*!< Set Output_type & Speed  only if mode is GPIO_OUT or AF */
                          {

                                  /* Speed mode configuration */
                                  GPIOx_Ptr->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Clear old configurations in OSPEEDR for PORT_Pin */
                                  GPIOx_Ptr->OSPEEDR |= ((uint32)(PinConfig.GPIO_Speed) << (PinPos * CONFG_PINS_P_PORT_2));				/*!< Set new configurations in OSPEEDR for PORT_Pin */

                                  /* Output mode configuration*/
                                  GPIOx_Ptr->OTYPER  &= ~((GPIO_OTYPER_OT_0) << ((uint16)PinPos)) ;										/*!< Clear old configurations in OTYPER for PORT_Pin */
                                  GPIOx_Ptr->OTYPER |= (uint16)(((uint16)PinConfig.GPIO_OType) << ((uint16)PinPos));					/*!< Set new configurations in OTYPER for PORT_Pin */

#if (PORT_COMPENSATION_CELL == STD_ON)
                                  if (GPIO_Speed_50MHz == PinConfig.GPIO_Speed || GPIO_Speed_100MHz == PinConfig.GPIO_Speed){				/*!< Compensation cell recommended at 50MHz speed or more */
                                          /* Enable SYSCFG clock */
                                          RCC->APB2ENR |= RCC_APB2LPENR_SYSCFGLPEN;

                                          /* Enable compensation cell */
                                          SYSCFG->CMPCR |= SYSCFG_CMPCR_CMP_PD;

                                          /* Wait till compensation cell is ready */
                                          while((SYSCFG->CMPCR & SYSCFG_CMPCR_READY) != SYSCFG_CMPCR_READY){
                                                  /* do nothing */
                                          }
                                  }
#endif
                          }/* End of OutputType & Speed configurations */

                          /* Pull-up Pull down resistor configuration !<note its disabled for analog mode by hardware */
                          GPIOx_Ptr->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16)PinPos * CONFG_PINS_P_PORT_2));						/*!< Clear old configurations in PUPDR for PORT_Pin */
                          GPIOx_Ptr->PUPDR |= (((uint32)PinConfig.GPIO_PuPd) << (PinPos * CONFG_PINS_P_PORT_2));					/*!< Set new configurations in PUPDR for PORT_Pin */

                  }  /* end of  if GPIOx_Ptr not null_ptr */
          } /* end of  if PinConfig not null_ptr */
  } /* end of for loop */
  Port_Status = PORT_INITIALIZED;
}


/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number,
*                  Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType PinId, Port_PinDirectionType Direction ){
/***** DET *****/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port driver initialized or Not */
	if(Port_Status != PORT_INITIALIZED){
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		return;
	}
	else  {
		/* No action Required */
	}

	/* check that this pin is available to be configured, or even EXIST! */
	if(PinId >= PINS_OF_ALL_PORTS){
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
		return;
	}
	else  {
		/* No action Required */
	}

	/* check if the pin direction is changeable */
	if (Port_pinConfigurationSet.Pins[PinId] != NULL_PTR){
		if(Port_pinConfigurationSet.Pins[PinId]->direction_change == UNCHANGEABLE){
			/* Report to DET  */
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
			return;
		}
		else  {
			/* No action Required */
		}
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
/*****   *****/

	volatile GPIO_TypeDef * GPIOx_Ptr = NULL_PTR;
	uint8 PinPos = getPinPos(PinId);
	GPIOx_Ptr = getPortBasePtr(PinId);
	if (NULL_PTR != GPIOx_Ptr){

		if (0 == (GPIOx_Ptr->MODER & ((uint32)GPIO_MODER_MODER0_1 << (PinPos * CONFG_PINS_P_PORT_2)))){					/*!< Check if it is GPIO now (not Analog nor AF) to set direction */

			if (Port_pinConfigurationSet.Pins[PinId] != NULL_PTR){																	/*!< Check if PinId is configured */
				if ((Port_pinConfigurationSet.Pins[PinId])->direction_change == UNCHANGEABLE){										/*!< Check if it is Direction Changeable */
					return;																									/*!< If Pin configured as direction unchangeable return */
				}																											/*!<you can delete this section if you wanna ignore the changeability */
			}

			if(Direction == PORT_PIN_IN){
				GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Clear old configurations in MODER for PORT_Pin */
				GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_IN << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Set new configurations in MODER for PORT_Pin as GPIO IN*/
			}else{
				GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Clear old configurations in MODER for PORT_Pin */
				GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_OUT << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Set new configurations in MODER for PORT_Pin as GPIO OUT */
			}

		}/* end of gpio checking */
	}/* end of  if GPIOx_Ptr not null_ptr */
}
#endif


/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection( void ){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port driver initialized or Not */
	if(Port_Status != PORT_INITIALIZED)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
	}
	else{
		/* Do nothing*/
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

	volatile GPIO_TypeDef * GPIOx_Ptr = NULL_PTR;
	Port_PinType Pin_Index = 0;
	for (Pin_Index = 0; Pin_Index < PINS_OF_ALL_PORTS; Pin_Index++){
		uint8 PinPos = getPinPos(Pin_Index);
		GPIOx_Ptr = getPortBasePtr(Pin_Index);

		if (Port_pinConfigurationSet.Pins[Pin_Index] != NULL_PTR){																	/*!< Check if PinId is configured */
			if (NULL_PTR != GPIOx_Ptr){

				if (0 == (GPIOx_Ptr->MODER & ((uint32)GPIO_MODER_MODER0_1 << (PinPos * CONFG_PINS_P_PORT_2)))){					/*!< Check if it is GPIO now (not Analog or AF) to set direction */

					if ((Port_pinConfigurationSet.Pins[Pin_Index])->direction_change == CHANGEABLE){								/*!< Check if it is Direction Changeable */
						if((Port_pinConfigurationSet.Pins[Pin_Index])->direction == PORT_PIN_IN){
							GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Clear old configurations in MODER for PORT_Pin */
							GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_IN << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Set new configurations in MODER for PORT_Pin as GPIO IN*/
						}else{
							GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Clear old configurations in MODER for PORT_Pin */
							GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_OUT << (PinPos * CONFG_PINS_P_PORT_2));					/*!< Set new configurations in MODER for PORT_Pin as GPIO OUT */
						}
					}/* end of changeable checking */

				}/* end of gpio checking */

			}/* end of  if GPIOx_Ptr not null_ptr */
		}/* end of  if Pins[Pin_Index] not null_ptr */

	} /* end of for loop */
}


/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo ){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo){
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
		return;
	}else {
		/* No action Required */
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	/* Copy the vendor Id */
	versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
	/* Copy the module Id */
	versioninfo->moduleID = (uint16)PORT_MODULE_ID;
	/* Copy Software Major Version */
	versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
	/* Copy Software Minor Version */
	versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
	/* Copy Software Patch Version */
	versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
}
#endif


/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number,
                   Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode( Port_PinType PinId, Port_PinModeType Mode ){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port driver initialized or Not */
	if(Port_Status != PORT_INITIALIZED){
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
		return;
	}else {
		/* No action Required */
	}

	/* check that this pin is available to be configured, or even EXIST! */
	if(PinId >= PINS_OF_ALL_PORTS){
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		return;
	}else {
		/* No action Required */
	}

	/* check if the mode passed is a valid mode */
	if(Mode > PORT_ANALOG_MODE){
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
		return;
	}else {
		/* No action Required */
	}

	/* check if the pin mode is changeable */
	if (Port_pinConfigurationSet.Pins[PinId] != NULL_PTR){
		if(Port_pinConfigurationSet.Pins[PinId]->mode_change == UNCHANGEABLE){
			/* Report to DET  */
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
			return;
		}else {
			/* No action Required */
		}
	}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

	volatile GPIO_TypeDef * GPIOx_Ptr = NULL_PTR;
	uint8 PinPos = getPinPos(PinId);
	GPIOx_Ptr = getPortBasePtr(PinId);

	if(NULL_PTR != GPIOx_Ptr){

		if (NULL_PTR != Port_pinConfigurationSet.Pins[PinId]){															/*!< if pin is post-build configured */
			Port_ConfigPin PinConfig = *(Port_pinConfigurationSet.Pins[PinId]);											/*!< pinConfig is structure of configurations for each pin */

			if (PinConfig.mode_change == UNCHANGEABLE){																	/*!< Check if Direction is Changeable */
				return;																									/*!< If Pin configured as direction unchangeable return */
			}																											/*!<you can delete this section if you want to ignore the changeability */

			/* Start Mode configurations */
			if(Mode == PORT_DIO_MODE){
				if(PinConfig.direction == PORT_PIN_IN){
					GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Clear old configurations in MODER for PORT_Pin */
					GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_IN << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Set new configurations in MODER for PORT_Pin as GPIO IN*/
				}else{
					GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Clear old configurations in MODER for PORT_Pin */
					GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_OUT << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Set new configurations in MODER for PORT_Pin as GPIO OUT */
				}

			}else if(Mode == PORT_ANALOG_MODE){
				GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Clear old configurations in MODER for PORT_Pin */
				GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_AN << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Set new configurations in MODER for PORT_Pin as Analog */

			}else if(Mode <= PORT_ALTERNATE_FUNCTION_15_MODE){
				if(PinPos < 8){
					GPIOx_Ptr->AFR[0]	&= ~((uint32)Mode << (PinPos * CONFG_PINS_P_PORT_4));							/*!< Set Alternate Function Register Low for pin(0:7) */
				} else {
					GPIOx_Ptr->AFR[1]	&= ~((uint32)Mode << (PinPos * CONFG_PINS_P_PORT_4));							/*!< Set Alternate Function Register High for pin(8:15) */
				}

				GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Clear old configurations in MODER for PORT_Pin */
				GPIOx_Ptr->MODER |= ((uint32)(GPIO_Mode_AF) << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Set new configurations in MODER for PORT_Pin as Alternate Function */
			}
			/* End Mode configurations */

			/* Setup OutputType & Speed configurations */
			if ( (Mode == PORT_DIO_MODE && PinConfig.direction == PORT_PIN_OUT) ||
					(Mode <= PORT_ALTERNATE_FUNCTION_15_MODE) )															/*!< Set Output_type & Speed  only if mode is GPIO_OUT or AF */
			{

				/* Speed mode configuration */
				GPIOx_Ptr->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (PinPos * CONFG_PINS_P_PORT_2));						/*!< Clear old configurations in OSPEEDR for PORT_Pin */
				GPIOx_Ptr->OSPEEDR |= ((uint32)(PinConfig.GPIO_Speed) << (PinPos * CONFG_PINS_P_PORT_2));				/*!< Set new configurations in OSPEEDR for PORT_Pin */

				/* Output mode configuration*/
				GPIOx_Ptr->OTYPER  &= ~((GPIO_OTYPER_OT_0) << ((uint16)PinPos)) ;										/*!< Clear old configurations in OTYPER for PORT_Pin */
				GPIOx_Ptr->OTYPER |= (uint16)(((uint16)PinConfig.GPIO_OType) << ((uint16)PinPos));					/*!< Set new configurations in OTYPER for PORT_Pin */

#if (PORT_COMPENSATION_CELL == STD_ON)
				if (GPIO_Speed_50MHz == PinConfig.GPIO_Speed || GPIO_Speed_100MHz == PinConfig.GPIO_Speed){				/*!< Compensation cell recommended at 50MHz speed or more */
					/* Enable SYSCFG clock */
					RCC->APB2ENR |= RCC_APB2LPENR_SYSCFGLPEN;

					/* Enable compensation cell */
					SYSCFG->CMPCR |= SYSCFG_CMPCR_CMP_PD;

					/* Wait till compensation cell is ready */
					while((SYSCFG->CMPCR & SYSCFG_CMPCR_READY) != SYSCFG_CMPCR_READY){
						/* do nothing */
					}
				}
#endif
			}
			/* End of OutputType & Speed configurations */


		} else { /*!< If Pin is not already configured  */

			if(Mode == PORT_DIO_MODE){
				GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Clear old configurations in MODER for PORT_Pin */
				GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_IN << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Set new configurations in MODER for PORT_Pin as GPIO IN*/

			}else if(Mode == PORT_ANALOG_MODE){
				GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Clear old configurations in MODER for PORT_Pin */
				GPIOx_Ptr->MODER |= ((uint32)GPIO_Mode_AN << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Set new configurations in MODER for PORT_Pin as Analog */

			}else if(Mode <= PORT_ALTERNATE_FUNCTION_15_MODE){
				if(PinPos < 8){
					GPIOx_Ptr->AFR[0]	&= ~((uint32)Mode << (PinPos * CONFG_PINS_P_PORT_4));								/*!< Set Alternate Function Register Low for pin(0:7) */
				} else {
					GPIOx_Ptr->AFR[1]	&= ~((uint32)Mode << (PinPos * CONFG_PINS_P_PORT_4));								/*!< Set Alternate Function Register High for pin(8:15) */
				}

				GPIOx_Ptr->MODER  &= ~(GPIO_MODER_MODER0 << (PinPos * CONFG_PINS_P_PORT_2));								/*!< Clear old configurations in MODER for PORT_Pin */
				GPIOx_Ptr->MODER |= ((uint32)(GPIO_Mode_AF) << (PinPos * CONFG_PINS_P_PORT_2));							/*!< Set new configurations in MODER for PORT_Pin as Alternate Function */
			}
		}

	}/* end of  if GPIOx_Ptr is not Null */
}
