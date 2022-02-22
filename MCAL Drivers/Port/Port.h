 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for STM32F405RG Micro-controller - Port Driver.
 *
 * Author: Boules Rufael
 *
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "config/Common_Macros.h"
#include "config/Std_Types.h"
#include "Port_Cfg.h"
#include "Port_Regs.h"


/* Id for the company in the AUTOSAR */
#define PORT_VENDOR_ID    (1000U)

/* port Module Id */
#define PORT_MODULE_ID    (124U)

/* port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version R21.11.0
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (21U)
#define PORT_AR_RELEASE_MINOR_VERSION   (11U)
#define PORT_AR_RELEASE_PATCH_VERSION   (0U)




/* AUTOSAR checking between Std_Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif


/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/
/* Port Status */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#define UNCHANGEABLE	0x00U
#define CHANGEABLE		0x01U

/* Number of pins in configuration register per port */
#define CONFG_PINS_P_PORT_2		(2U)
#define CONFG_PINS_P_PORT_4 	(4U)

/* Number of Pins per Port of the MCU */
#define NUM_OF_PINS_PER_PORT	(16U)

/* Number of Pins per Port of the MCU */   /* STM32F40xx LQFP64 pinout */
#define PINS_OF_ALL_PORTS				(51U)

/* set IDs to portPinS */	/* STM32F40xx LQFP64 pinout */
enum  {
	PORT_PA0, PORT_PA1, PORT_PA2, PORT_PA3, PORT_PA4, PORT_PA5, PORT_PA6, PORT_PA7,
	PORT_PA8, PORT_PA9, PORT_PA10, PORT_PA11, PORT_PA12, PORT_PA13, PORT_PA14, PORT_PA15,

	PORT_PB0, PORT_PB1, PORT_PB2, PORT_PB3, PORT_PB4, PORT_PB5, PORT_PB6, PORT_PB7,
	PORT_PB8, PORT_PB9, PORT_PB10, PORT_PB11, PORT_PB12, PORT_PB13, PORT_PB14, PORT_PB15,

	PORT_PC0, PORT_PC1, PORT_PC2, PORT_PC3, PORT_PC4, PORT_PC5, PORT_PC6, PORT_PC7,
	PORT_PC8, PORT_PC9, PORT_PC10, PORT_PC11, PORT_PC12, PORT_PC13, PORT_PC14, PORT_PC15,

	PORT_PD2,

	PORT_PH0, PORT_PH1
};
enum  {
	PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG, PORTH
};

/*
* macros for pin different Modes,
* assigned to mode of type Port_PinModeType */

/* Alternate function for 4Bits(MCU)  */
#define PORT_ALTERNATE_FUNCTION_00_MODE (0U)
#define PORT_ALTERNATE_FUNCTION_01_MODE (1U)
#define PORT_ALTERNATE_FUNCTION_02_MODE (2U)
#define PORT_ALTERNATE_FUNCTION_03_MODE (3U)
#define PORT_ALTERNATE_FUNCTION_04_MODE (4U)
#define PORT_ALTERNATE_FUNCTION_05_MODE (5U)
#define PORT_ALTERNATE_FUNCTION_06_MODE (6U)
#define PORT_ALTERNATE_FUNCTION_07_MODE (7U)
#define PORT_ALTERNATE_FUNCTION_08_MODE (8U)
#define PORT_ALTERNATE_FUNCTION_09_MODE (9U)
#define PORT_ALTERNATE_FUNCTION_10_MODE (10U)
#define PORT_ALTERNATE_FUNCTION_11_MODE (11U)
#define PORT_ALTERNATE_FUNCTION_12_MODE (12U)
#define PORT_ALTERNATE_FUNCTION_13_MODE (13U)
#define PORT_ALTERNATE_FUNCTION_14_MODE (14U)
#define PORT_ALTERNATE_FUNCTION_15_MODE (15U)

#define PORT_DIO_MODE 					(16U)
#define PORT_ANALOG_MODE				(17U)




/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* fn1. PORT_init ID service */
#define PORT_INIT_SID						(uint8)0x00

/* fn2. PORT_set_pin_direction ID service */
#define PORT_SET_PIN_DIRECTION_SID			(uint8)0x01

/* fn3. PORT_refresh_pin_direction ID service */
#define PORT_REFRESH_PORT_DIRECTION_SID		(uint8)0x02

/* fn4. PORT_get_version_info ID service */
#define PORT_GET_VERSION_INFO_SID			(uint8)0x03

/* fn5. PORT_set_pin_mode ID service */
#define PORT_SET_PIN_MODE_SID				(uint8)0x04




/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET Code for Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                  (uint8)0x0A

/* DET Code for Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE     (uint8)0x0B

/* DET Code for API Port_Init service called with wrong parameter */
#define PORT_E_INIT_FAILED               (uint8)0x0C

/* DET Code for API Port_SetPinMode service called with wrong parameter Mode */
#define PORT_E_PARAM_INVALID_MODE         (uint8)0x0D

/* DET Code for API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE          (uint8)0x0E

/* DET Code for API service called without module initialization */
#define PORT_E_UNINIT                     (uint8)0x0F

/* DET Code for APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER              (uint8)0x10




/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* 2. Data type for port pin */ /* depends on number of pins in the MCU*/
typedef uint8 Port_PinType;

/* 3. PIN direction */
typedef enum{
  PORT_PIN_IN,
  PORT_PIN_OUT
}Port_PinDirectionType;


typedef enum
{
  GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode */
  GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode */
  GPIO_Mode_AF   = 0x02, /*!< GPIO Alternate function Mode */
  GPIO_Mode_AN   = 0x03  /*!< GPIO Analog Mode */
}GPIOMode_TypeDef;

typedef enum
{
  GPIO_OType_PP = 0x00,		/*!< Push-Pull*/
  GPIO_OType_OD = 0x01		/*!< Open Drain*/
}GPIOOType_TypeDef;

typedef enum
{
  GPIO_Speed_2MHz   = 0x00, /*!< Low speed */
  GPIO_Speed_25MHz  = 0x01, /*!< Medium speed */
  GPIO_Speed_50MHz  = 0x02, /*!< Fast speed */
  GPIO_Speed_100MHz = 0x03  /*!< High speed on 30 pF (80 MHz Output max speed on 15 pF) */
}GPIOSpeed_TypeDef;

typedef enum
{
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
}GPIOPuPd_TypeDef;



/* 4. Different port pin modes */
typedef uint8 Port_PinModeType;


/* Pin Configurations */
typedef struct
{
	Port_PinModeType			mode;						/* PORT_DIO_MODE...PORT_ANALOG_MODE */
	GPIOSpeed_TypeDef			GPIO_Speed;					/* GPIO_Speed_2MHz, GPIO_Speed_25MHz, GPIO_Speed_50MHz, GPIO_Speed_100MHz */
	GPIOOType_TypeDef			GPIO_OType;					/* GPIO_OType_PP,  GPIO_OType_OD */
    GPIOPuPd_TypeDef			GPIO_PuPd;					/* GPIO_PuPd_NOPULL, GPIO_PuPd_UP, GPIO_PuPd_DOWN */

    Port_PinDirectionType       direction;					/* PORT_PIN_IN, PORT_PIN_OUT */

    uint8                       direction_change;			/* STD_ON, STD_OFF */
    uint8                       mode_change;				/* STD_ON, STD_OFF */

    uint8                       initial_value;				/* STD_HIGH, STD_LOW */

}Port_ConfigPin;



/* 1. all (Ports) configurations*/
typedef struct
{
  /* array of pointers to struct pin config */
  const Port_ConfigPin* Pins[PINS_OF_ALL_PORTS];
}Port_ConfigType;




/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


/* 1. function for PORT initialization */
void Port_Init( const Port_ConfigType* ConfigPtr );


#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* 2. function for setting pin direction*/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif


/* 3. function for refreshing port direction */
void Port_RefreshPortDirection( void );


/* 4. function for getting version info */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif


/* 5. function for setting pin mode */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* extern confg structure to be determined in the parent modules */
extern const Port_ConfigType Port_pinConfigurationSet;



#endif /* PORT_H */
