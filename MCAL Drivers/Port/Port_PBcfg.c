 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for STM32F405RG Micro-controller - Port Driver
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


/* predefined configs for the pin */
typedef enum
{
	DIOIN_PP_NOPULL_2M, DIO_DEFAULT=0,				/*!< Default DIOIN */
	DIOOUT_PP_NOPULL_2M,							/*!< PP: Push-Pull,	2M: Speed in Hz*/
	DIOIN_OD,										/*!< OD: Open Drain*/
	DIOIN_OD_PU,									/*!< PU: PullUp,	PD: PullDp */
	DIOOUT_CONSTM_CONSTD_PU,						/*!< CONSTM: constant Mode, CONSTD: constant Direction */
	AF_PP_NOPULL_2M,								/*!< AF: Alternate Function */
	AN_NOPULL,										/*!< AM: Analog Mode */
	CUSTOM_ONE,
	CUSTOM_TWO
}pinPreDefined;



/*
 * array of struct  Port_ConfigPin which element is
                    1. mode
                    2. speed							!< don't cares in analog or input modes>
                    3. output Type						!< don't cares in analog or input modes>
                    4. pullUp/Down
                    5. direction
                    6. direction changeable
                    7. mode changeable
                    8. initial value
 */
const Port_ConfigPin Port_Configuration[]={
  
  {PORT_DIO_MODE, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, PORT_PIN_IN, CHANGEABLE, CHANGEABLE, STD_LOW}, /* DIO_DEFAULT */
  {PORT_DIO_MODE, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, PORT_PIN_OUT, CHANGEABLE, CHANGEABLE, STD_LOW}, /* DIOOUT_PP_NOPULL_2M */
  
  
};

  
/* configration to each pin in port
 * MC: STM32F40xx LQFP64 pinout
 * */
const Port_ConfigType Port_pinConfigurationSet = {{

  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA0 */ /* PORTA */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA1 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA2 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA3 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA4 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA5 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA6 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA7 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA8 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA9 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA10 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA11 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA12 */
  &Port_Configuration[DIO_DEFAULT],									/* PORT_PA13 */
  NULL_PTR,														/* PORT_PA14 */	/* if nullptr will do nothing (MC default) */
  NULL_PTR,				       									/* PORT_PA15 */
  NULL_PTR,														/* PORT_PB0 */	/* PORTB */
  NULL_PTR,														/* PORT_PB1 */
  NULL_PTR,														/* PORT_PB2 */
  NULL_PTR,														/* PORT_PB3 */
  NULL_PTR,														/* PORT_PB4 */
  NULL_PTR,														/* PORT_PB5 */
  NULL_PTR,														/* PORT_PB6 */
  NULL_PTR,														/* PORT_PB7 */
  NULL_PTR,														/* PORT_PB8 */
  NULL_PTR,														/* PORT_PB9 */
  NULL_PTR,														/* PORT_PB10 */
  NULL_PTR,														/* PORT_PB11 */
  NULL_PTR,														/* PORT_PB12 */
  NULL_PTR,														/* PORT_PB13 */
  NULL_PTR,														/* PORT_PB14 */
  NULL_PTR,														/* PORT_PB15 */
  NULL_PTR,														/* PORT_PC0 */	/* PORTC */
  NULL_PTR,														/* PORT_PC1 */
  NULL_PTR,														/* PORT_PC2 */
  NULL_PTR,														/* PORT_PC3 */
  NULL_PTR,														/* PORT_PC4 */
  NULL_PTR,														/* PORT_PC5 */
  NULL_PTR,														/* PORT_PC6 */
  NULL_PTR,														/* PORT_PC7 */
  NULL_PTR,														/* PORT_PC8 */
  NULL_PTR,														/* PORT_PC9 */
  NULL_PTR,														/* PORT_PC10 */
  NULL_PTR,														/* PORT_PC11 */
  NULL_PTR,														/* PORT_PC12 */
  NULL_PTR,														/* PORT_PC13 */
  NULL_PTR,														/* PORT_PC14 */
  NULL_PTR,														/* PORT_PC15 */
  NULL_PTR,														/* PORT_PD2 */	/* PORTD */
  NULL_PTR,														/* PORT_PH0 */	/* PORTH */
  NULL_PTR,														/* PORT_PH1 */

}};
