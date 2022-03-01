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
/*
#define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define GPIO_PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define GPIO_PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define GPIO_PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))*/
//GPIO PORT DATA REGISTERS
#define GPIO_PORTA_BASE_ADDRESS           0x40020000		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTB_BASE_ADDRESS           0x40020400		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTC_BASE_ADDRESS           0x40020800		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTD_BASE_ADDRESS           0x40020C00		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTE_BASE_ADDRESS           0x40021000
#define GPIO_PORTF_BASE_ADDRESS           0x40021400
#define GPIO_PORTG_BASE_ADDRESS           0x40021800
#define GPIO_PORTH_BASE_ADDRESS           0x40021C00		/* STM32F40xx LQFP64 pinout */
#define GPIO_PORTI_BASE_ADDRESS           0x40022000


//GPIO output data register
#define GPIO_PORTA_Data_Reg         (*((volatile uint32 *)0x40020014))
#define GPIO_PORTB_Data_Reg         (*((volatile uint32 *)0x40020414))
#define GPIO_PORTC_Data_Reg         (*((volatile uint32 *)0x40020814))
#define GPIO_PORTD_Data_Reg         (*((volatile uint32 *)  0x40020C14))
#define GPIO_PORTE_Data_Reg           (*((volatile uint32 *)0x40021014))
#define GPIO_PORTF_Data_Reg           (*((volatile uint32 *)0x40021414))
#define GPIO_PORTG_Data_Reg           (*((volatile uint32 *)0x40021814))
#define GPIO_PORTH_Data_Reg           (*((volatile uint32 *)0x40021C14))
#define GPIO_PORTI_Data_Reg           (*((volatile uint32 *)0x40022014))
/* GPIO output_type Data Registers  */
#define GPIO_PORTA_OTYPER_Reg           (*((volatile uint32 *)0x40020004))
#define GPIO_PORTB_OTYPER_Reg           (*((volatile uint32 *)0x40020404))
#define GPIO_PORTC_OTYPER_Reg          (*((volatile uint32 *) 0x40020804))
#define GPIO_PORTD_OTYPER_Reg           (*((volatile uint32 *)0x40020C04))
#define GPIO_PORTE_OTYPER_Reg           (*((volatile uint32 *)0x40021004))
#define GPIO_PORTF_OTYPER_Reg           (*((volatile uint32 *)0x40021404))
#define GPIO_PORTG_OTYPER_Reg           (*((volatile uint32 *)0x40021804))
#define GPIO_PORTH_OTYPER_Reg           (*((volatile uint32 *)0x40021C04))
#define GPIO_PORTI_OTYPER_Reg           (*((volatile uint32 *)0x40022004))

/* GPIO OSPEED Registers  */
#define GPIO_PORTA_OSPEEDR_Reg           (*((volatile uint32 *)0x40020008))
#define GPIO_PORTB_OSPEEDR_Reg           (*((volatile uint32 *)0x40020408))
#define GPIO_PORTC_OSPEEDR_Reg           (*((volatile uint32 *)0x40020808))
#define GPIO_PORTD_OSPEEDR_Reg           (*((volatile uint32 *)0x40020C08))
#define GPIO_PORTE_OSPEEDR_Reg           (*((volatile uint32 *)0x40021008))
#define GPIO_PORTF_OSPEEDR_Reg           (*((volatile uint32 *)0x40021408))
#define GPIO_PORTG_OSPEEDR_Reg           (*((volatile uint32 *)0x40021808))
#define GPIO_PORTH_OSPEEDR_Reg           (*((volatile uint32 *)0x40021C08))
#define GPIO_PORTI_OSPEEDR_Reg           (*((volatile uint32 *)0x40022008))

/* GPIO pull_up/pull_down Registers  */
#define GPIO_PORTA_PUPDR_Reg          (*((volatile uint32 *) 0x4002000C))
#define GPIO_PORTB_PUPDR_Reg           (*((volatile uint32 *)0x4002040C))
#define GPIO_PORTC_PUDPR_Reg           (*((volatile uint32 *)0x4002080C))
#define GPIO_PORTD_PUPDR_Reg           (*((volatile uint32 *)0x40020C0C))
#define GPIO_PORTE_PUPDR_Reg           (*((volatile uint32 *)0x4002100C))
#define GPIO_PORTF_PUPDR_Reg           (*((volatile uint32 *)0x4002140C))
#define GPIO_PORTG_PUPDR_Reg           (*((volatile uint32 *)0x4002180C))
#define GPIO_PORTH_PUPDR_Reg           (*((volatile uint32 *)0x40021C0C))
#define GPIO_PORTI_PUPDR_Reg          (*((volatile uint32 *) 0x4002200C))

/* GPIO input data Registers  */
#define GPIO_PORTA_IDR_Reg          (*((volatile uint32 *) 0x40020010))
#define GPIO_PORTB_IDR_Reg           (*((volatile uint32 *)0x40020410))
#define GPIO_PORTC_IDR_Reg           (*((volatile uint32 *)0x40020810))
#define GPIO_PORTD_IDR_Reg           (*((volatile uint32 *)0x40020C10))
#define GPIO_PORTE_IDR_Reg           (*((volatile uint32 *)0x40021010))
#define GPIO_PORTF_IDR_Reg           (*((volatile uint32 *)0x40021410))
#define GPIO_PORTG_IDR_Reg           (*((volatile uint32 *)0x40021810))
#define GPIO_PORTH_IDR_Reg           (*((volatile uint32 *)0x40021C10))
#define GPIO_PORTI_IDR_Reg           (*((volatile uint32 *)0x40022010))

/* GPIO input bit set/reset data Registers  */
#define GPIO_PORTA_BSRR_Reg            (*((volatile uint32 *)0x40020018))
#define GPIO_PORTB_BSRR_Reg            (*((volatile uint32 *)0x40020418))
#define GPIO_PORTC_BSRR_Reg            (*((volatile uint32 *)0x40020818))
#define GPIO_PORTD_BSRR_Reg            (*((volatile uint32 *)0x40020C18))
#define GPIO_PORTE_BSRR_Reg            (*((volatile uint32 *)0x40021018))
#define GPIO_PORTF_BSRR_Reg            (*((volatile uint32 *)0x40021418))
#define GPIO_PORTG_BSRR_Reg            (*((volatile uint32 *)0x40021818))
#define GPIO_PORTH_BSRR_Reg            (*((volatile uint32 *)0x40021C18))
#define GPIO_PORTI_BSRR_Reg            (*((volatile uint32 *)0x40022018))

/* GPIO port configuration lock Registers  */
#define GPIO_PORTA_LCKR_Reg            0x4002001C
#define GPIO_PORTB_LCKR_Reg            0x4002041C
#define GPIO_PORTC_LCKR_Reg            0x4002081C
#define GPIO_PORTD_LCKR_Reg            0x40020C1C
#define GPIO_PORTE_LCKR_Reg            0x4002101C
#define GPIO_PORTF_LCKR_Reg            0x4002141C
#define GPIO_PORTG_LCKR_Reg            0x4002181C
#define GPIO_PORTH_LCKR_Reg            0x40021C1C
#define GPIO_PORTI_LCKR_Reg            0x4002201C

/* GPIO Alternate function low Registers  */
#define GPIO_PORTA_AFRL_Reg           (*((volatile uint32 *) 0x40020020))
#define GPIO_PORTB_AFRL_Reg            (*((volatile uint32 *)0x40020420))
#define GPIO_PORTC_AFRL_Reg            (*((volatile uint32 *)0x40020820))
#define GPIO_PORTD_AFRL_Reg            (*((volatile uint32 *)0x40020C20))
#define GPIO_PORTE_AFRL_Reg            (*((volatile uint32 *)0x40021020))
#define GPIO_PORTF_AFRL_Reg            (*((volatile uint32 *)0x40021420))
#define GPIO_PORTG_AFRL_Reg            (*((volatile uint32 *)0x40021820))
#define GPIO_PORTH_AFRL_Reg            (*((volatile uint32 *)0x40021C20))
#define GPIO_PORTI_AFRL_Reg           (*((volatile uint32 *) 0x40022020))

/* GPIO Alternate function high Registers  */
#define GPIO_PORTA_AFRH_Reg            (*((volatile uint32 *)0x40020024))
#define GPIO_PORTB_AFRH_Reg            (*((volatile uint32 *)0x40020424))
#define GPIO_PORTC_AFRH_Reg            (*((volatile uint32 *)0x40020824))
#define GPIO_PORTD_AFRH_Reg            (*((volatile uint32 *)0x40020C24))
#define GPIO_PORTE_AFRH_Reg            (*((volatile uint32 *)0x40021024))
#define GPIO_PORTF_AFRH_Reg            (*((volatile uint32 *)0x40021424))
#define GPIO_PORTG_AFRH_Reg            (*((volatile uint32 *)0x40021824))
#define GPIO_PORTH_AFRH_Reg            (*((volatile uint32 *)0x40021C24))
#define GPIO_PORTI_AFRH_Reg           (*((volatile uint32 *) 0x40022024))

#define GPIO_IDR_IDR_0                  (*((volatile uint32 *)0x00000001))
#define GPIO_IDR_IDR_1                  (*((volatile uint32 *)0x00000002))
#define GPIO_IDR_IDR_2                  (*((volatile uint32 *)0x00000004))
#define GPIO_IDR_IDR_3                  (*((volatile uint32 *)0x00000008))
#define GPIO_IDR_IDR_4                  (*((volatile uint32 *)0x00000010))
#define GPIO_IDR_IDR_5                  (*((volatile uint32 *)0x00000020))
#define GPIO_IDR_IDR_6                  (*((volatile uint32 *)0x00000040))
#define GPIO_IDR_IDR_7                  (*((volatile uint32 *)0x00000080))
#define GPIO_IDR_IDR_8                  (*((volatile uint32 *)0x00000100))
#define GPIO_IDR_IDR_9                  (*((volatile uint32 *)0x00000200))
#define GPIO_IDR_IDR_10                 (*((volatile uint32 *)0x00000400))
#define GPIO_IDR_IDR_11                 (*((volatile uint32 *)0x00000800))
#define GPIO_IDR_IDR_12                 (*((volatile uint32 *)0x00001000))
#define GPIO_IDR_IDR_13                 (*((volatile uint32 *)0x00002000))
#define GPIO_IDR_IDR_14                 (*((volatile uint32 *)0x00004000))
#define GPIO_IDR_IDR_15                 (*((volatile uint32 *)0x00008000))
/*
#define pin0              &GPIO_IDR_IDR_0
#define pin1              &GPIO_IDR_IDR_1
#define pin2              &GPIO_IDR_IDR_2
#define pin3              &GPIO_IDR_IDR_3
#define pin4              &GPIO_IDR_IDR_4
#define pin5              &GPIO_IDR_IDR_5
#define pin6              &GPIO_IDR_IDR_6
#define pin7              &GPIO_IDR_IDR_7
#define pin8              &GPIO_IDR_IDR_8
#define pin9              &GPIO_IDR_IDR_9
#define pin10             &GPIO_IDR_IDR_10
#define pin11             &GPIO_IDR_IDR_11
#define pin12             &GPIO_IDR_IDR_12
#define pin13             &GPIO_IDR_IDR_13
#define pin14             &GPIO_IDR_IDR_14
#define pin15             &GPIO_IDR_IDR_15 */

#endif /* DIO_REGS_H */
