 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for STM32F4xx Micro-controller - Port Driver
 *
 * Author: Boules Rufael
 *
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version R21.11.0
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (21U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (11U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (0U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif


#define NULL_PTR          ((void *)0)
#define PORT_CAN_MODE                           (9U)                            /*!< PORT_ALTERNATE_FUNCTION_09_MODE*/
#define PORT_USART1_MODE                        (7U)                            /*!< PORT_ALTERNATE_FUNCTION_07_MODE*/



/* predefined configs for the pin */
typedef enum
{
	DIOIN_NOPULL, DIO_DEFAULT=0,				                /*!< Default DIOIN */
	DIOOUT_NOPULL,							        /*!< PP: Push-Pull,	2M: Speed in Hz*/
	Testing_lED,
	CAN_MODE = 3,
	USART1 = 4,
	LCD = 5,
        
        
        
	DIOIN_OD,								/*!< OD: Open Drain*/
	DIOIN_OD_PU,								/*!< PU: PullUp,	PD: PullDp */
	DIOOUT_CONSTM_CONSTD_PU,						/*!< CONSTM: constant Mode, CONSTD: constant Direction */
	AF_PP_NOPULL,							        /*!< AF: Alternate Function */
	AN_NOPULL,								/*!< AM: Analog Mode */
	CUSTOM_ONE,
	CUSTOM_TWO
}pinPreDefined;



/*
 * array of struct  Port_ConfigPin which element is
                    1. mode                                                                                                     !<GP Input initially>
                    2. mode changeable						
                    3. direction                                                !<only for dio>                                 !<mode dependent (GP IN initially) >
                    4. direction changeable
                    6. pullUp/Down                                                                                              !<No_Pull  initially>                   < No_Pull, Pull_Up, Pull_Down >
                    5. output Type						!< don't cares in analog or input modes>        !<PushPull initially>                   < OType_PP,  OType_OD >
                    7. initial value                                            !< only at dio>                                 !<STD_LOW  initially>                   < STD_HIGH, STD_LOW >
                    8. speed                                                    !< don't cares in analog or input modes>        !<GPIO_Speed_2MHz init>                 < GPIO_Speed_2MHz, GPIO_Speed_25MHz, GPIO_Speed_50MHz, GPIO_Speed_100MHz >
 */
const Port_ConfigPin Port_Configuration[]={
  
  {PORT_DIO_MODE, CHANGEABLE, PORT_PIN_IN,  CHANGEABLE, No_Pull, OType_PP, STD_LOW, GPIO_Speed_2MHz},           /* Initial status */ /* DIOIN_NOPULL */
  {PORT_DIO_MODE, CHANGEABLE, PORT_PIN_OUT, CHANGEABLE, No_Pull, OType_PP, STD_HIGH, GPIO_Speed_2MHz},           /* DIOOUT_NOPULL */
  {PORT_DIO_MODE, CHANGEABLE, PORT_PIN_OUT, CHANGEABLE, No_Pull, OType_PP, STD_HIGH, GPIO_Speed_2MHz},           /* testing led */
  {PORT_CAN_MODE, CHANGEABLE, PORT_PIN_OUT, CHANGEABLE, No_Pull, OType_PP, STD_LOW, GPIO_Speed_2MHz},           /* CAN_MODE */
  {PORT_USART1_MODE, UNCHANGEABLE, PORT_PIN_IN,  UNCHANGEABLE, No_Pull, OType_PP, STD_HIGH, GPIO_Speed_2MHz},     /* USART1 */
  {PORT_DIO_MODE, UNCHANGEABLE, PORT_PIN_OUT,  UNCHANGEABLE, No_Pull, OType_PP, STD_LOW, GPIO_Speed_2MHz}           /* LCD */

  
};

  
/* configuration to each pin in port
 * */
const Port_ConfigType Port_pinConfigurationSet = {{

  &Port_Configuration[Testing_lED],                     /* PORT_PA0 */ /* PORTA */
  NULL_PTR,                     						/* PORT_PA1 */
  NULL_PTR,                     						/* PORT_PA2 */
  NULL_PTR,                     						/* PORT_PA3 */
  NULL_PTR,                     						/* PORT_PA4 */
  NULL_PTR,                     						/* PORT_PA5 */
  NULL_PTR,                     						/* PORT_PA6 */
  NULL_PTR,                     						/* PORT_PA7 */
  &Port_Configuration[USART1],						/* PORT_PA8 */
  &Port_Configuration[USART1],						/* PORT_PA9 */
  &Port_Configuration[USART1],						/* PORT_PA10 */
  &Port_Configuration[USART1],						/* PORT_PA11 */
  &Port_Configuration[USART1],						/* PORT_PA12 */
  NULL_PTR,						            /* PORT_PA13 */ /* JTAG */
  NULL_PTR,									/* PORT_PA14 */	/* JTAG */      /* if nullptr will do nothing (MC default) */
  NULL_PTR,				       				/* PORT_PA15 */ /* JTAG */
  NULL_PTR,									/* PORT_PB0 */	/* PORTB */
  &Port_Configuration[LCD],									/* PORT_PB1 */
  &Port_Configuration[LCD],									/* PORT_PB2 */
  &Port_Configuration[LCD],									/* PORT_PB3 */
  &Port_Configuration[LCD],									/* PORT_PB4 */
  &Port_Configuration[LCD],									/* PORT_PB5 */
  &Port_Configuration[LCD],									/* PORT_PB6 */
  &Port_Configuration[LCD],									/* PORT_PB7 */
  NULL_PTR,									/* PORT_PB8 */
  NULL_PTR,									/* PORT_PB9 */
  NULL_PTR,									/* PORT_PB10 */
  NULL_PTR,									/* PORT_PB11 */
  NULL_PTR,									/* PORT_PB12 */
  NULL_PTR,									/* PORT_PB13 */
  NULL_PTR,									/* PORT_PB14 */
  NULL_PTR,									/* PORT_PB15 */
  &Port_Configuration[LCD],									/* PORT_PC0 */	/* PORTC */
  &Port_Configuration[LCD],									/* PORT_PC1 */
  &Port_Configuration[LCD],									/* PORT_PC2 */
  NULL_PTR,									/* PORT_PC3 */
  NULL_PTR,									/* PORT_PC4 */
  NULL_PTR,									/* PORT_PC5 */
  NULL_PTR,								    /* PORT_PC6 */
  NULL_PTR,									/* PORT_PC7 */
  NULL_PTR,									/* PORT_PC8 */
  NULL_PTR,									/* PORT_PC9 */
  NULL_PTR,									/* PORT_PC10 */
  NULL_PTR,									/* PORT_PC11 */
  NULL_PTR,									/* PORT_PC12 */
  NULL_PTR,									/* PORT_PC13 */
  NULL_PTR,									/* PORT_PC14 */
  NULL_PTR,									/* PORT_PC15 */
#if (LQFP == 64)
  NULL_PTR,									/* PORT_PD2 */	/* PORTD */
  NULL_PTR,									/* PORT_PH0 */	/* PORTH */
  NULL_PTR,									/* PORT_PH1 */
#elif (LQFP == 100)
  &Port_Configuration[CAN_MODE],						/* PORT_PD0 */	/* PORTD */
  &Port_Configuration[CAN_MODE],						/* PORT_PD1 */
  NULL_PTR,									/* PORT_PD2 */
  NULL_PTR,									/* PORT_PD3 */
  NULL_PTR,									/* PORT_PD4 */
  NULL_PTR,									/* PORT_PD5 */
  NULL_PTR,									/* PORT_PD6 */
  NULL_PTR,									/* PORT_PD7 */
  NULL_PTR,									/* PORT_PD8 */
  NULL_PTR,									/* PORT_PD9 */
  NULL_PTR,									/* PORT_PD10 */
  NULL_PTR,									/* PORT_PD11 */
  NULL_PTR,									/* PORT_PD12 */
  NULL_PTR,									/* PORT_PD13 */
  NULL_PTR,									/* PORT_PD14 */
  NULL_PTR,									/* PORT_PD15 */
  NULL_PTR,									/* PORT_PE0 */	/* PORTE */
  NULL_PTR,									/* PORT_PE1 */
  NULL_PTR,									/* PORT_PE2 */
  NULL_PTR,									/* PORT_PE3 */
  NULL_PTR,									/* PORT_PE4 */
  NULL_PTR,									/* PORT_PE5 */
  NULL_PTR,									/* PORT_PE6 */
  NULL_PTR,									/* PORT_PE7 */
  NULL_PTR,									/* PORT_PE8 */
  NULL_PTR,									/* PORT_PE9 */
  NULL_PTR,									/* PORT_PE10 */
  NULL_PTR,									/* PORT_PE11 */
  NULL_PTR,									/* PORT_PE12 */
  NULL_PTR,									/* PORT_PE13 */
  NULL_PTR,									/* PORT_PE14 */
  NULL_PTR,									/* PORT_PE15 */
  NULL_PTR,									/* PORT_PH0 */	/* PORTH */
  NULL_PTR,									/* PORT_PH1 */
#endif
}};
