 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Regs.h
 *
 * Description: Header file for STM32F4xx Micro-controller - Port Driver Registers
 *
 * Author: Boules Rufael
 *
 ******************************************************************************/

#ifndef PORT_REGS_H
#define PORT_REGS_H


#include "Std_Types.h"


#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */


/********************  GPIO Registers base addresses  ********************/
#define GPIO_PORTA_BASE_ADDRESS           0x40020000
#define GPIO_PORTB_BASE_ADDRESS           0x40020400
#define GPIO_PORTC_BASE_ADDRESS           0x40020800
#define GPIO_PORTD_BASE_ADDRESS           0x40020C00
#define GPIO_PORTE_BASE_ADDRESS           0x40021000
#define GPIO_PORTF_BASE_ADDRESS           0x40021400
#define GPIO_PORTG_BASE_ADDRESS           0x40021800
#define GPIO_PORTH_BASE_ADDRESS           0x40021C00
#define GPIO_PORTI_BASE_ADDRESS           0x40022000


/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define  RCC_AHB1ENR_GPIOAEN                 ((uint32)0x00000001)
#define  RCC_AHB1ENR_GPIOBEN                 ((uint32)0x00000002)
#define  RCC_AHB1ENR_GPIOCEN                 ((uint32)0x00000004)
#define  RCC_AHB1ENR_GPIODEN                 ((uint32)0x00000008)
#define  RCC_AHB1ENR_GPIOEEN                 ((uint32)0x00000010)
#define  RCC_AHB1ENR_GPIOFEN                 ((uint32)0x00000020)
#define  RCC_AHB1ENR_GPIOGEN                 ((uint32)0x00000040)
#define  RCC_AHB1ENR_GPIOHEN                 ((uint32)0x00000080)
#define  RCC_AHB1ENR_GPIOIEN                 ((uint32)0x00000100)
#define  RCC_AHB1ENR_CRCEN                   ((uint32)0x00001000)
#define  RCC_AHB1ENR_BKPSRAMEN               ((uint32)0x00040000)
#define  RCC_AHB1ENR_CCMDATARAMEN            ((uint32)0x00100000)
#define  RCC_AHB1ENR_DMA1EN                  ((uint32)0x00200000)
#define  RCC_AHB1ENR_DMA2EN                  ((uint32)0x00400000)
#define  RCC_AHB1ENR_ETHMACEN                ((uint32)0x02000000)
#define  RCC_AHB1ENR_ETHMACTXEN              ((uint32)0x04000000)
#define  RCC_AHB1ENR_ETHMACRXEN              ((uint32)0x08000000)
#define  RCC_AHB1ENR_ETHMACPTPEN             ((uint32)0x10000000)
#define  RCC_AHB1ENR_OTGHSEN                 ((uint32)0x20000000)
#define  RCC_AHB1ENR_OTGHSULPIEN             ((uint32)0x40000000)


/*******************************************************************************
 *                            General Purpose I/O                              *
 ******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER0                    ((uint32)0x00000003)
#define GPIO_MODER_MODER0_0                  ((uint32)0x00000001)
#define GPIO_MODER_MODER0_1                  ((uint32)0x00000002)

#define GPIO_MODER_MODER1                    ((uint32)0x0000000C)
#define GPIO_MODER_MODER1_0                  ((uint32)0x00000004)
#define GPIO_MODER_MODER1_1                  ((uint32)0x00000008)

#define GPIO_MODER_MODER2                    ((uint32)0x00000030)
#define GPIO_MODER_MODER2_0                  ((uint32)0x00000010)
#define GPIO_MODER_MODER2_1                  ((uint32)0x00000020)

#define GPIO_MODER_MODER3                    ((uint32)0x000000C0)
#define GPIO_MODER_MODER3_0                  ((uint32)0x00000040)
#define GPIO_MODER_MODER3_1                  ((uint32)0x00000080)

#define GPIO_MODER_MODER4                    ((uint32)0x00000300)
#define GPIO_MODER_MODER4_0                  ((uint32)0x00000100)
#define GPIO_MODER_MODER4_1                  ((uint32)0x00000200)

#define GPIO_MODER_MODER5                    ((uint32)0x00000C00)
#define GPIO_MODER_MODER5_0                  ((uint32)0x00000400)
#define GPIO_MODER_MODER5_1                  ((uint32)0x00000800)

#define GPIO_MODER_MODER6                    ((uint32)0x00003000)
#define GPIO_MODER_MODER6_0                  ((uint32)0x00001000)
#define GPIO_MODER_MODER6_1                  ((uint32)0x00002000)

#define GPIO_MODER_MODER7                    ((uint32)0x0000C000)
#define GPIO_MODER_MODER7_0                  ((uint32)0x00004000)
#define GPIO_MODER_MODER7_1                  ((uint32)0x00008000)

#define GPIO_MODER_MODER8                    ((uint32)0x00030000)
#define GPIO_MODER_MODER8_0                  ((uint32)0x00010000)
#define GPIO_MODER_MODER8_1                  ((uint32)0x00020000)

#define GPIO_MODER_MODER9                    ((uint32)0x000C0000)
#define GPIO_MODER_MODER9_0                  ((uint32)0x00040000)
#define GPIO_MODER_MODER9_1                  ((uint32)0x00080000)

#define GPIO_MODER_MODER10                   ((uint32)0x00300000)
#define GPIO_MODER_MODER10_0                 ((uint32)0x00100000)
#define GPIO_MODER_MODER10_1                 ((uint32)0x00200000)

#define GPIO_MODER_MODER11                   ((uint32)0x00C00000)
#define GPIO_MODER_MODER11_0                 ((uint32)0x00400000)
#define GPIO_MODER_MODER11_1                 ((uint32)0x00800000)

#define GPIO_MODER_MODER12                   ((uint32)0x03000000)
#define GPIO_MODER_MODER12_0                 ((uint32)0x01000000)
#define GPIO_MODER_MODER12_1                 ((uint32)0x02000000)

#define GPIO_MODER_MODER13                   ((uint32)0x0C000000)
#define GPIO_MODER_MODER13_0                 ((uint32)0x04000000)
#define GPIO_MODER_MODER13_1                 ((uint32)0x08000000)

#define GPIO_MODER_MODER14                   ((uint32)0x30000000)
#define GPIO_MODER_MODER14_0                 ((uint32)0x10000000)
#define GPIO_MODER_MODER14_1                 ((uint32)0x20000000)

#define GPIO_MODER_MODER15                   ((uint32)0xC0000000)
#define GPIO_MODER_MODER15_0                 ((uint32)0x40000000)
#define GPIO_MODER_MODER15_1                 ((uint32)0x80000000)

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT_0                     ((uint32)0x00000001)
#define GPIO_OTYPER_OT_1                     ((uint32)0x00000002)
#define GPIO_OTYPER_OT_2                     ((uint32)0x00000004)
#define GPIO_OTYPER_OT_3                     ((uint32)0x00000008)
#define GPIO_OTYPER_OT_4                     ((uint32)0x00000010)
#define GPIO_OTYPER_OT_5                     ((uint32)0x00000020)
#define GPIO_OTYPER_OT_6                     ((uint32)0x00000040)
#define GPIO_OTYPER_OT_7                     ((uint32)0x00000080)
#define GPIO_OTYPER_OT_8                     ((uint32)0x00000100)
#define GPIO_OTYPER_OT_9                     ((uint32)0x00000200)
#define GPIO_OTYPER_OT_10                    ((uint32)0x00000400)
#define GPIO_OTYPER_OT_11                    ((uint32)0x00000800)
#define GPIO_OTYPER_OT_12                    ((uint32)0x00001000)
#define GPIO_OTYPER_OT_13                    ((uint32)0x00002000)
#define GPIO_OTYPER_OT_14                    ((uint32)0x00004000)
#define GPIO_OTYPER_OT_15                    ((uint32)0x00008000)

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDER_OSPEEDR0               ((uint32)0x00000003)
#define GPIO_OSPEEDER_OSPEEDR0_0             ((uint32)0x00000001)
#define GPIO_OSPEEDER_OSPEEDR0_1             ((uint32)0x00000002)

#define GPIO_OSPEEDER_OSPEEDR1               ((uint32)0x0000000C)
#define GPIO_OSPEEDER_OSPEEDR1_0             ((uint32)0x00000004)
#define GPIO_OSPEEDER_OSPEEDR1_1             ((uint32)0x00000008)

#define GPIO_OSPEEDER_OSPEEDR2               ((uint32)0x00000030)
#define GPIO_OSPEEDER_OSPEEDR2_0             ((uint32)0x00000010)
#define GPIO_OSPEEDER_OSPEEDR2_1             ((uint32)0x00000020)

#define GPIO_OSPEEDER_OSPEEDR3               ((uint32)0x000000C0)
#define GPIO_OSPEEDER_OSPEEDR3_0             ((uint32)0x00000040)
#define GPIO_OSPEEDER_OSPEEDR3_1             ((uint32)0x00000080)

#define GPIO_OSPEEDER_OSPEEDR4               ((uint32)0x00000300)
#define GPIO_OSPEEDER_OSPEEDR4_0             ((uint32)0x00000100)
#define GPIO_OSPEEDER_OSPEEDR4_1             ((uint32)0x00000200)

#define GPIO_OSPEEDER_OSPEEDR5               ((uint32)0x00000C00)
#define GPIO_OSPEEDER_OSPEEDR5_0             ((uint32)0x00000400)
#define GPIO_OSPEEDER_OSPEEDR5_1             ((uint32)0x00000800)

#define GPIO_OSPEEDER_OSPEEDR6               ((uint32)0x00003000)
#define GPIO_OSPEEDER_OSPEEDR6_0             ((uint32)0x00001000)
#define GPIO_OSPEEDER_OSPEEDR6_1             ((uint32)0x00002000)

#define GPIO_OSPEEDER_OSPEEDR7               ((uint32)0x0000C000)
#define GPIO_OSPEEDER_OSPEEDR7_0             ((uint32)0x00004000)
#define GPIO_OSPEEDER_OSPEEDR7_1             ((uint32)0x00008000)

#define GPIO_OSPEEDER_OSPEEDR8               ((uint32)0x00030000)
#define GPIO_OSPEEDER_OSPEEDR8_0             ((uint32)0x00010000)
#define GPIO_OSPEEDER_OSPEEDR8_1             ((uint32)0x00020000)

#define GPIO_OSPEEDER_OSPEEDR9               ((uint32)0x000C0000)
#define GPIO_OSPEEDER_OSPEEDR9_0             ((uint32)0x00040000)
#define GPIO_OSPEEDER_OSPEEDR9_1             ((uint32)0x00080000)

#define GPIO_OSPEEDER_OSPEEDR10              ((uint32)0x00300000)
#define GPIO_OSPEEDER_OSPEEDR10_0            ((uint32)0x00100000)
#define GPIO_OSPEEDER_OSPEEDR10_1            ((uint32)0x00200000)

#define GPIO_OSPEEDER_OSPEEDR11              ((uint32)0x00C00000)
#define GPIO_OSPEEDER_OSPEEDR11_0            ((uint32)0x00400000)
#define GPIO_OSPEEDER_OSPEEDR11_1            ((uint32)0x00800000)

#define GPIO_OSPEEDER_OSPEEDR12              ((uint32)0x03000000)
#define GPIO_OSPEEDER_OSPEEDR12_0            ((uint32)0x01000000)
#define GPIO_OSPEEDER_OSPEEDR12_1            ((uint32)0x02000000)

#define GPIO_OSPEEDER_OSPEEDR13              ((uint32)0x0C000000)
#define GPIO_OSPEEDER_OSPEEDR13_0            ((uint32)0x04000000)
#define GPIO_OSPEEDER_OSPEEDR13_1            ((uint32)0x08000000)

#define GPIO_OSPEEDER_OSPEEDR14              ((uint32)0x30000000)
#define GPIO_OSPEEDER_OSPEEDR14_0            ((uint32)0x10000000)
#define GPIO_OSPEEDER_OSPEEDR14_1            ((uint32)0x20000000)

#define GPIO_OSPEEDER_OSPEEDR15              ((uint32)0xC0000000)
#define GPIO_OSPEEDER_OSPEEDR15_0            ((uint32)0x40000000)
#define GPIO_OSPEEDER_OSPEEDR15_1            ((uint32)0x80000000)

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPDR0                    ((uint32)0x00000003)
#define GPIO_PUPDR_PUPDR0_0                  ((uint32)0x00000001)
#define GPIO_PUPDR_PUPDR0_1                  ((uint32)0x00000002)

#define GPIO_PUPDR_PUPDR1                    ((uint32)0x0000000C)
#define GPIO_PUPDR_PUPDR1_0                  ((uint32)0x00000004)
#define GPIO_PUPDR_PUPDR1_1                  ((uint32)0x00000008)

#define GPIO_PUPDR_PUPDR2                    ((uint32)0x00000030)
#define GPIO_PUPDR_PUPDR2_0                  ((uint32)0x00000010)
#define GPIO_PUPDR_PUPDR2_1                  ((uint32)0x00000020)

#define GPIO_PUPDR_PUPDR3                    ((uint32)0x000000C0)
#define GPIO_PUPDR_PUPDR3_0                  ((uint32)0x00000040)
#define GPIO_PUPDR_PUPDR3_1                  ((uint32)0x00000080)

#define GPIO_PUPDR_PUPDR4                    ((uint32)0x00000300)
#define GPIO_PUPDR_PUPDR4_0                  ((uint32)0x00000100)
#define GPIO_PUPDR_PUPDR4_1                  ((uint32)0x00000200)

#define GPIO_PUPDR_PUPDR5                    ((uint32)0x00000C00)
#define GPIO_PUPDR_PUPDR5_0                  ((uint32)0x00000400)
#define GPIO_PUPDR_PUPDR5_1                  ((uint32)0x00000800)

#define GPIO_PUPDR_PUPDR6                    ((uint32)0x00003000)
#define GPIO_PUPDR_PUPDR6_0                  ((uint32)0x00001000)
#define GPIO_PUPDR_PUPDR6_1                  ((uint32)0x00002000)

#define GPIO_PUPDR_PUPDR7                    ((uint32)0x0000C000)
#define GPIO_PUPDR_PUPDR7_0                  ((uint32)0x00004000)
#define GPIO_PUPDR_PUPDR7_1                  ((uint32)0x00008000)

#define GPIO_PUPDR_PUPDR8                    ((uint32)0x00030000)
#define GPIO_PUPDR_PUPDR8_0                  ((uint32)0x00010000)
#define GPIO_PUPDR_PUPDR8_1                  ((uint32)0x00020000)

#define GPIO_PUPDR_PUPDR9                    ((uint32)0x000C0000)
#define GPIO_PUPDR_PUPDR9_0                  ((uint32)0x00040000)
#define GPIO_PUPDR_PUPDR9_1                  ((uint32)0x00080000)

#define GPIO_PUPDR_PUPDR10                   ((uint32)0x00300000)
#define GPIO_PUPDR_PUPDR10_0                 ((uint32)0x00100000)
#define GPIO_PUPDR_PUPDR10_1                 ((uint32)0x00200000)

#define GPIO_PUPDR_PUPDR11                   ((uint32)0x00C00000)
#define GPIO_PUPDR_PUPDR11_0                 ((uint32)0x00400000)
#define GPIO_PUPDR_PUPDR11_1                 ((uint32)0x00800000)

#define GPIO_PUPDR_PUPDR12                   ((uint32)0x03000000)
#define GPIO_PUPDR_PUPDR12_0                 ((uint32)0x01000000)
#define GPIO_PUPDR_PUPDR12_1                 ((uint32)0x02000000)

#define GPIO_PUPDR_PUPDR13                   ((uint32)0x0C000000)
#define GPIO_PUPDR_PUPDR13_0                 ((uint32)0x04000000)
#define GPIO_PUPDR_PUPDR13_1                 ((uint32)0x08000000)

#define GPIO_PUPDR_PUPDR14                   ((uint32)0x30000000)
#define GPIO_PUPDR_PUPDR14_0                 ((uint32)0x10000000)
#define GPIO_PUPDR_PUPDR14_1                 ((uint32)0x20000000)

#define GPIO_PUPDR_PUPDR15                   ((uint32)0xC0000000)
#define GPIO_PUPDR_PUPDR15_0                 ((uint32)0x40000000)
#define GPIO_PUPDR_PUPDR15_1                 ((uint32)0x80000000)

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR_0                       ((uint32)0x00000001)
#define GPIO_IDR_IDR_1                       ((uint32)0x00000002)
#define GPIO_IDR_IDR_2                       ((uint32)0x00000004)
#define GPIO_IDR_IDR_3                       ((uint32)0x00000008)
#define GPIO_IDR_IDR_4                       ((uint32)0x00000010)
#define GPIO_IDR_IDR_5                       ((uint32)0x00000020)
#define GPIO_IDR_IDR_6                       ((uint32)0x00000040)
#define GPIO_IDR_IDR_7                       ((uint32)0x00000080)
#define GPIO_IDR_IDR_8                       ((uint32)0x00000100)
#define GPIO_IDR_IDR_9                       ((uint32)0x00000200)
#define GPIO_IDR_IDR_10                      ((uint32)0x00000400)
#define GPIO_IDR_IDR_11                      ((uint32)0x00000800)
#define GPIO_IDR_IDR_12                      ((uint32)0x00001000)
#define GPIO_IDR_IDR_13                      ((uint32)0x00002000)
#define GPIO_IDR_IDR_14                      ((uint32)0x00004000)
#define GPIO_IDR_IDR_15                      ((uint32)0x00008000)
/* Old GPIO_IDR register bits definition, maintained for legacy purpose */
#define GPIO_OTYPER_IDR_0                    GPIO_IDR_IDR_0
#define GPIO_OTYPER_IDR_1                    GPIO_IDR_IDR_1
#define GPIO_OTYPER_IDR_2                    GPIO_IDR_IDR_2
#define GPIO_OTYPER_IDR_3                    GPIO_IDR_IDR_3
#define GPIO_OTYPER_IDR_4                    GPIO_IDR_IDR_4
#define GPIO_OTYPER_IDR_5                    GPIO_IDR_IDR_5
#define GPIO_OTYPER_IDR_6                    GPIO_IDR_IDR_6
#define GPIO_OTYPER_IDR_7                    GPIO_IDR_IDR_7
#define GPIO_OTYPER_IDR_8                    GPIO_IDR_IDR_8
#define GPIO_OTYPER_IDR_9                    GPIO_IDR_IDR_9
#define GPIO_OTYPER_IDR_10                   GPIO_IDR_IDR_10
#define GPIO_OTYPER_IDR_11                   GPIO_IDR_IDR_11
#define GPIO_OTYPER_IDR_12                   GPIO_IDR_IDR_12
#define GPIO_OTYPER_IDR_13                   GPIO_IDR_IDR_13
#define GPIO_OTYPER_IDR_14                   GPIO_IDR_IDR_14
#define GPIO_OTYPER_IDR_15                   GPIO_IDR_IDR_15

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR_0                       ((uint32)0x00000001)
#define GPIO_ODR_ODR_1                       ((uint32)0x00000002)
#define GPIO_ODR_ODR_2                       ((uint32)0x00000004)
#define GPIO_ODR_ODR_3                       ((uint32)0x00000008)
#define GPIO_ODR_ODR_4                       ((uint32)0x00000010)
#define GPIO_ODR_ODR_5                       ((uint32)0x00000020)
#define GPIO_ODR_ODR_6                       ((uint32)0x00000040)
#define GPIO_ODR_ODR_7                       ((uint32)0x00000080)
#define GPIO_ODR_ODR_8                       ((uint32)0x00000100)
#define GPIO_ODR_ODR_9                       ((uint32)0x00000200)
#define GPIO_ODR_ODR_10                      ((uint32)0x00000400)
#define GPIO_ODR_ODR_11                      ((uint32)0x00000800)
#define GPIO_ODR_ODR_12                      ((uint32)0x00001000)
#define GPIO_ODR_ODR_13                      ((uint32)0x00002000)
#define GPIO_ODR_ODR_14                      ((uint32)0x00004000)
#define GPIO_ODR_ODR_15                      ((uint32)0x00008000)
/* Old GPIO_ODR register bits definition, maintained for legacy purpose */
#define GPIO_OTYPER_ODR_0                    GPIO_ODR_ODR_0
#define GPIO_OTYPER_ODR_1                    GPIO_ODR_ODR_1
#define GPIO_OTYPER_ODR_2                    GPIO_ODR_ODR_2
#define GPIO_OTYPER_ODR_3                    GPIO_ODR_ODR_3
#define GPIO_OTYPER_ODR_4                    GPIO_ODR_ODR_4
#define GPIO_OTYPER_ODR_5                    GPIO_ODR_ODR_5
#define GPIO_OTYPER_ODR_6                    GPIO_ODR_ODR_6
#define GPIO_OTYPER_ODR_7                    GPIO_ODR_ODR_7
#define GPIO_OTYPER_ODR_8                    GPIO_ODR_ODR_8
#define GPIO_OTYPER_ODR_9                    GPIO_ODR_ODR_9
#define GPIO_OTYPER_ODR_10                   GPIO_ODR_ODR_10
#define GPIO_OTYPER_ODR_11                   GPIO_ODR_ODR_11
#define GPIO_OTYPER_ODR_12                   GPIO_ODR_ODR_12
#define GPIO_OTYPER_ODR_13                   GPIO_ODR_ODR_13
#define GPIO_OTYPER_ODR_14                   GPIO_ODR_ODR_14
#define GPIO_OTYPER_ODR_15                   GPIO_ODR_ODR_15

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS_0                       ((uint32)0x00000001)
#define GPIO_BSRR_BS_1                       ((uint32)0x00000002)
#define GPIO_BSRR_BS_2                       ((uint32)0x00000004)
#define GPIO_BSRR_BS_3                       ((uint32)0x00000008)
#define GPIO_BSRR_BS_4                       ((uint32)0x00000010)
#define GPIO_BSRR_BS_5                       ((uint32)0x00000020)
#define GPIO_BSRR_BS_6                       ((uint32)0x00000040)
#define GPIO_BSRR_BS_7                       ((uint32)0x00000080)
#define GPIO_BSRR_BS_8                       ((uint32)0x00000100)
#define GPIO_BSRR_BS_9                       ((uint32)0x00000200)
#define GPIO_BSRR_BS_10                      ((uint32)0x00000400)
#define GPIO_BSRR_BS_11                      ((uint32)0x00000800)
#define GPIO_BSRR_BS_12                      ((uint32)0x00001000)
#define GPIO_BSRR_BS_13                      ((uint32)0x00002000)
#define GPIO_BSRR_BS_14                      ((uint32)0x00004000)
#define GPIO_BSRR_BS_15                      ((uint32)0x00008000)
#define GPIO_BSRR_BR_0                       ((uint32)0x00010000)
#define GPIO_BSRR_BR_1                       ((uint32)0x00020000)
#define GPIO_BSRR_BR_2                       ((uint32)0x00040000)
#define GPIO_BSRR_BR_3                       ((uint32)0x00080000)
#define GPIO_BSRR_BR_4                       ((uint32)0x00100000)
#define GPIO_BSRR_BR_5                       ((uint32)0x00200000)
#define GPIO_BSRR_BR_6                       ((uint32)0x00400000)
#define GPIO_BSRR_BR_7                       ((uint32)0x00800000)
#define GPIO_BSRR_BR_8                       ((uint32)0x01000000)
#define GPIO_BSRR_BR_9                       ((uint32)0x02000000)
#define GPIO_BSRR_BR_10                      ((uint32)0x04000000)
#define GPIO_BSRR_BR_11                      ((uint32)0x08000000)
#define GPIO_BSRR_BR_12                      ((uint32)0x10000000)
#define GPIO_BSRR_BR_13                      ((uint32)0x20000000)
#define GPIO_BSRR_BR_14                      ((uint32)0x40000000)
#define GPIO_BSRR_BR_15                      ((uint32)0x80000000)


/*******************************************************************************
 *                       GPIO Registers Structure Mapping                      *
 ******************************************************************************/
typedef struct
{
  volatile uint32 MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32 OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32 PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32 IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32 ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint16 BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
  volatile uint16 BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
  volatile uint32 LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32 AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/** 
  * @brief Reset and Clock Control (RCC)
  */
typedef struct
{
  volatile uint32 CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32 PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile uint32 CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile uint32 CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile uint32 AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile uint32 AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile uint32 AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile uint32 APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile uint32 APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile uint32 AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32 AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32 AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile uint32 APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32 APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile uint32 AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32 AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32 AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile uint32 APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32 APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32 BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32 CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32 SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32 PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */ 
} RCC_TypeDef;

/********************  Peripheral memory map  ***************/
#define PERIPH_BASE           ((uint32)0x40000000) /*!< Peripheral base address in the alias region                                */
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)


#endif /* PORT_REGS_H */
