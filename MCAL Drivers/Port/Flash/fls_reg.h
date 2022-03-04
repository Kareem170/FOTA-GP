/*****************************************************
 * file name : fls_reg.h
 * module : flash memory 
 * Date : 14 / 02 /2022
 * Auth : Karim Mohamed Amin
******************************************************/
#ifndef FLS_REG_H
#define FLS_REG_H
#include "Std_Types.h"
/*****************************************************
 *              struct of all offsets                *
******************************************************/
typedef struct
{
   uint32 ACR;      /* FLASH access control register,   Address offset: 0x00 */
   uint32 KEYR;     /* FLASH key register,              Address offset: 0x04 */
   uint32 OPTKEYR;  /* FLASH option key register,       Address offset: 0x08 */
   uint32 SR;       /* FLASH status register,           Address offset: 0x0C */
   uint32 CR;       /* FLASH control register,          Address offset: 0x10 */
   uint32 OPTCR;    /* FLASH option control register ,  Address offset: 0x14 */
} FLASH_TypeDef;
/*****************************************************
 *              FLASH MEMORY REGISTERS               *
******************************************************/
#define PERIPH_BASE           ((uint32)0x40000000) /* Peripheral base address in the alias region                                */
/* Peripheral memory map */
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00)
#define FLASH                 ((FLASH_TypeDef *) FLASH_R_BASE)
#endif /* FLS_REG_H */