 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Regs.h
 *
 * Description: Header file for STM32F405RG Micro-controller - Port Driver Registers
 *
 * Author: Boules Rufael
 *
 ******************************************************************************/

#ifndef PORT_REGS_H
#define PORT_REGS_H

#include "config/MC/stm32f4xx.h"
#include "config/Std_Types.h"

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40020000		/* STM32F40xx LQFP64 pin out (GPIOA_BASE)*/
#define GPIO_PORTB_BASE_ADDRESS           0x40020400		/* STM32F40xx LQFP64 pin out */
#define GPIO_PORTC_BASE_ADDRESS           0x40020800		/* STM32F40xx LQFP64 pin out */
#define GPIO_PORTD_BASE_ADDRESS           0x40020C00		/* STM32F40xx LQFP64 pin out */
#define GPIO_PORTE_BASE_ADDRESS           0x40021000
#define GPIO_PORTF_BASE_ADDRESS           0x40021400
#define GPIO_PORTG_BASE_ADDRESS           0x40021800
#define GPIO_PORTH_BASE_ADDRESS           0x40021C00		/* STM32F40xx LQFP64 pin out */
#define GPIO_PORTI_BASE_ADDRESS           0x40022000

//#define IS_CONFIG_MODER(GPIOx_Ptr, PinId)			((GPIOx_Ptr->MODER & ((uint32_t)GPIO_MODER_MODER0 << (PinId * CONFG_PINS_P_PORT_2))) >> (PinId * CONFG_PINS_P_PORT_2))


#endif /* PORT_REGS_H */
