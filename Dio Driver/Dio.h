 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define DIO_VENDOR_ID    (1000U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (0U)
#define DIO_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (uint8)0x10

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (uint8)0x20

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define DIO_E_UNINIT                   (uint8)0xF0
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint16 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint32 Dio_PortLevelType;

/* Structure for Dio_ChannelGroup */
typedef struct
{
  /* Mask which defines the positions of the channel group */
  uint32 mask;
  /* Position of the group from LSB */
  uint8 offset;
  /* This shall be the port ID which the Channel group is defined. */
  Dio_PortType PortIndex;
} Dio_ChannelGroupType;

typedef struct
{
	/* Member contains the ID of the Port that this channel belongs to */
	Dio_PortType Port_Num;
	/* Member contains the ID of the Channel*/
	Dio_ChannelType Ch_Num;
}Dio_ConfigChannel;

/* Data Structure required for initializing the Dio Driver */
typedef struct Dio_ConfigType
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];

} Dio_ConfigType;

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
typedef struct
{
   uint32 MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
   uint32 OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
   uint32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
   uint32 PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
   uint32 IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
   uint32 ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
   uint32 BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
   uint32 LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
   uint32 AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO read Channel API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Port API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO write Channel Group API */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

/* Function for DIO read Channel Group API */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO write Channel Group API */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

/* Function for DIO read Channel Group API */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/* Function for DIO Initialization API */
void Dio_Init(const Dio_ConfigType * ConfigPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Dio_ConfigType Dio_Configuration;
extern const Dio_ConfigType Dio_ChannelGroup;
#endif /* DIO_H */
