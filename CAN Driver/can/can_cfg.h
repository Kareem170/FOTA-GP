 /******************************************************************************
 *
 * Module: CAN Driver
 *
 * File Name: can_cfg.h
 *
 * Description: This File Contains The main definitions and configuration for STM32F405RG Microcontroller CAN Driver
 *
 * Author: Fayrouz Bakr & Kareem mohamed
 ******************************************************************************/

#ifndef CAN_CFG_H
#define CAN_CFG_H

/*
 * Module Version 1.0.0
 */
#define CAN_CFG_SW_MAJOR_VERSION              (1U)
#define CAN_CFG_SW_MINOR_VERSION              (0U)
#define CAN_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.0
 */
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define CAN_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define CAN_CFG_AR_RELEASE_PATCH_VERSION     (0U)

/* Pre-compile option for Development Error Detect */
#define CAN_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define CAN_VERSION_INFO_API                (STD_OFF)

/* STM32F405RG Pin Numbers */
#define PINS_NUM (100U)
   

/* Macros for CAN Status */
#define CAN_INIT_STATUS_FAILED               (0U)
#define CAN_NOT_INIT_STATUS_SUCCEED          (1U)

/* Configured CAN Address ( CAN1 OR CAN2 )*/
#define CANX_BASE_ADDRESS                    (0x40006400)   

/* CAN Master Control Register bits */
#define MCR_DBF           ((uint32)0x00010000) /* software master reset */

/* CAN Mailbox Transmit Request */
#define TMIDxR_TXRQ       ((uint32)0x00000001) /* Transmit mailbox request */

/* CAN Filter Master Register bits */
#define FMR_FINIT         ((uint32)0x00000001) /* Filter init mode */

/* Time out for INAK bit */
#define INAK_TIMEOUT      ((uint32)0x0000FFFF)

/* Time out for SLAK bit */
#define SLAK_TIMEOUT      ((uint32)0x0000FFFF)

/* Flags in TSR register */
#define CAN_FLAGS_TSR     ((uint32)0x08000000) 

/* Flags in RF1R register */
#define CAN_FLAGS_RF1R    ((uint32)0x04000000) 

/* Flags in RF0R register */
#define CAN_FLAGS_RF0R    ((uint32)0x02000000) 

/* Flags in MSR register */
#define CAN_FLAGS_MSR     ((uint32)0x01000000) 

/* Flags in ESR register */
#define CAN_FLAGS_ESR     ((uint32)0x00F00000) 

/* Mailboxes definition */
#define CAN_TXMAILBOX_0   ((uint8)0x00)
#define CAN_TXMAILBOX_1   ((uint8)0x01)
#define CAN_TXMAILBOX_2   ((uint8)0x02) 

#define CAN_MODE_MASK     ((uint32) 0x00000003)

/* Loop back mode PIN NUMBER */
#define LBKM_PIN_NO                          (30U)

/*  Resynchronization jump width PIN NUMBER */
#define SJW_PIN_NO                           (24U)

/* Time segment 1 PIN NUMBER */
#define TS1_PIN_NO                           (16U)

/* Time segment 2 PIN NUMBER */
#define TS2_PIN_NO                           (20U)  
   
   
#endif /* CAN_CFG_H */
