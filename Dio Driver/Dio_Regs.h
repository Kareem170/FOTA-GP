 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver Registers
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef DIO_REGS_H
#define DIO_REGS_H

#include "Std_Types.h"
/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40020000		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTB_BASE_ADDRESS           0x40020400		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTC_BASE_ADDRESS           0x40020800		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTD_BASE_ADDRESS           0x40020C00		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTE_BASE_ADDRESS           0x40021000
#define GPIO_PORTF_BASE_ADDRESS           0x40021400
#define GPIO_PORTG_BASE_ADDRESS           0x40021800
#define GPIO_PORTH_BASE_ADDRESS           0x40021C00		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTI_BASE_ADDRESS           0x40022000

/* GPIO output Data Registers  */
#define GPIO_PORTA_Data_Reg         (*((volatile uint32 *)0x40020014))
#define GPIO_PORTB_Data_Reg         (*((volatile uint32 *)0x40020414))
#define GPIO_PORTC_Data_Reg         (*((volatile uint32 *)0x40020814))
#define GPIO_PORTD_Data_Reg         (*((volatile uint32 *)  0x40020C14))
#define GPIO_PORTE_Data_Reg           (*((volatile uint32 *)0x40021014))
#define GPIO_PORTF_Data_Reg           (*((volatile uint32 *)0x40021414))
#define GPIO_PORTG_Data_Reg           (*((volatile uint32 *)0x40021814))
#define GPIO_PORTH_Data_Reg           (*((volatile uint32 *)0x40021C14))
#define GPIO_PORTI_Data_Reg           (*((volatile uint32 *)0x40022014))




#define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define GPIO_PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define GPIO_PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define GPIO_PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))

#endif /* DIO_REGS_H */
