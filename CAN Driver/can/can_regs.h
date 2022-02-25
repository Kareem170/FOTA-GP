/******************************************************************************
 *
 * Module: CAN Driver
 *
 * File Name: can_regs.h
 *
 * Description: This File Contains STM32F405RG Microcontroller CAN Registers
 *
 * Author: Fayrouz Bakr & Kareem mohamed
 ******************************************************************************/
#ifndef CAN_REGS
#define CAN_REGS

/* CAN1 Base Address */
#define CAN1_BASE_ADDRESS      (0x4000 6400)

/* CAN2 Base Address */
#define CAN2_BASE_ADDRESS      (0x4000 6800)

/* CAN1 & CAN2 Registers */
#define CAN_MCR_OFFSET         0x000
#define CAN_MSR_OFFSET         0x004
#define CAN_TSR_OFFSET         0x008
#define CAN_RF0R_OFFSET        0x00C
#define CAN_RF1R_OFFSET        0x010
#define CAN_IER_OFFSET         0x014
#define CAN_ESR_OFFSET         0x018
#define CAN_BTR_OFFSET         0x01C
#define CAN_TI0R_OFFSET        0x180 
#define CAN_TDT0R_OFFSET       0x184  
#define CAN_TDL0R_OFFSET       0x188  


#define CAN_TDH0R_OFFSET       0x18C  
#define CAN_TI1R_OFFSET        0x190 
#define CAN_TDT1R_OFFSET       0x194  
#define CAN_TDL1R_OFFSET       0x198  
#define CAN_TDH1R_OFFSET       0x19C  
#define CAN_TI2R_OFFSET        0x1A0 
#define CAN_TDT2R_OFFSET       0x1A4  
#define CAN_TDL2R_OFFSET       0x1A8  
#define CAN_TDH2R_OFFSET       0x1AC  
#define CAN_RI0R_OFFSET        0x1B0 
#define CAN_RDT0R_OFFSET       0x1B4  
#define CAN_RDL0R_OFFSET       0x1B8  
#define CAN_RDH0R_OFFSET       0x1BC  
#define CAN_RI1R_OFFSET        0x1C0 


#define CAN_RDT1R_OFFSET       0x1C4  
#define CAN_RDL1R_OFFSET       0x1C8  
#define CAN_RDH1R_OFFSET       0x1CC 

/* CAN1 Registers */
#define CAN1_FMR_OFFSET        0x200
#define CAN1_FM1R_OFFSET       0x204
#define CAN1_FS1R_OFFSET       0x20C 
#define CAN1_FFA1R_OFFSET      0x214  
#define CAN1_FA1R_OFFSET       0x21C  
#define CAN1_F0R1_OFFSET       0x240 
#define CAN1_F0R2_OFFSET       0x244 
#define CAN1_F1R1_OFFSET       0x248 
#define CAN1_F1R2_OFFSET       0x24C 
#define CAN1_F27R1_OFFSET      0x318  
#define CAN1_F27R2_OFFSET      0x31C 




/******************************************************************************/
/*                                                                            */
/*                         Bit difinitions                                    */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CAN_MCR register  ********************/
#define  CAN_MCR_INRQ                        ((uint16)0x0001)            /* Initialization Request */
#define  CAN_MCR_SLEEP                       ((uint16)0x0002)            /* Sleep Mode Request */
#define  CAN_MCR_TXFP                        ((uint16)0x0004)            /* Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        ((uint16)0x0008)            /* Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        ((uint16)0x0010)            /* No Automatic Retransmission */
#define  CAN_MCR_AWUM                        ((uint16)0x0020)            /* Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        ((uint16)0x0040)            /* Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        ((uint16)0x0080)            /* Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       ((uint16)0x8000)            /* bxCAN software master reset */

/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        ((uint16)0x0001)            /* Initialization Acknowledge */
#define  CAN_MSR_SLAK                        ((uint16)0x0002)            /* Sleep Acknowledge */
#define  CAN_MSR_ERRI                        ((uint16)0x0004)            /* Error Interrupt */
#define  CAN_MSR_WKUI                        ((uint16)0x0008)            /* Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       ((uint16)0x0010)            /* Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         ((uint16)0x0100)            /* Transmit Mode */
#define  CAN_MSR_RXM                         ((uint16)0x0200)            /* Receive Mode */
#define  CAN_MSR_SAMP                        ((uint16)0x0400)            /* Last Sample Point */
#define  CAN_MSR_RX                          ((uint16)0x0800)            /* CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       ((uint32)0x00000001)        /* Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       ((uint32)0x00000002)        /* Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       ((uint32)0x00000004)        /* Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       ((uint32)0x00000008)        /* Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       ((uint32)0x00000080)        /* Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       ((uint32)0x00000100)        /* Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       ((uint32)0x00000200)        /* Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       ((uint32)0x00000400)        /* Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       ((uint32)0x00000800)        /* Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       ((uint32)0x00008000)        /* Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       ((uint32)0x00010000)        /* Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       ((uint32)0x00020000)        /* Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       ((uint32)0x00040000)        /* Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       ((uint32)0x00080000)        /* Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       ((uint32)0x00800000)        /* Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        ((uint32)0x03000000)        /* Mailbox Code */

#define  CAN_TSR_TME                         ((uint32)0x1C000000)        /* TME[2:0] bits */
#define  CAN_TSR_TME0                        ((uint32)0x04000000)        /* Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        ((uint32)0x08000000)        /* Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        ((uint32)0x10000000)        /* Transmit Mailbox 2 Empty */

#define  CAN_TSR_LOW                         ((uint32)0xE0000000)        /* LOW[2:0] bits */
#define  CAN_TSR_LOW0                        ((uint32)0x20000000)        /* Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        ((uint32)0x40000000)        /* Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        ((uint32)0x80000000)        /* Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define  CAN_RF0R_FMP0                       ((uint8)0x03)               /* FIFO 0 Message Pending */
#define  CAN_RF0R_FULL0                      ((uint8)0x08)               /* FIFO 0 Full */
#define  CAN_RF0R_FOVR0                      ((uint8)0x10)               /* FIFO 0 Overrun */
#define  CAN_RF0R_RFOM0                      ((uint8)0x20)               /* Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define  CAN_RF1R_FMP1                       ((uint8)0x03)               /* FIFO 1 Message Pending */
#define  CAN_RF1R_FULL1                      ((uint8)0x08)               /* FIFO 1 Full */
#define  CAN_RF1R_FOVR1                      ((uint8)0x10)               /* FIFO 1 Overrun */
#define  CAN_RF1R_RFOM1                      ((uint8)0x20)               /* Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       ((uint32)0x00000001)        /* Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      ((uint32)0x00000002)        /* FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       ((uint32)0x00000004)        /* FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      ((uint32)0x00000008)        /* FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      ((uint32)0x00000010)        /* FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       ((uint32)0x00000020)        /* FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      ((uint32)0x00000040)        /* FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       ((uint32)0x00000100)        /* Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       ((uint32)0x00000200)        /* Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       ((uint32)0x00000400)        /* Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       ((uint32)0x00000800)        /* Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       ((uint32)0x00008000)        /* Error Interrupt Enable */
#define  CAN_IER_WKUIE                       ((uint32)0x00010000)        /* Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       ((uint32)0x00020000)        /* Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define  CAN_ESR_EWGF                        ((uint32)0x00000001)        /* Error Warning Flag */
#define  CAN_ESR_EPVF                        ((uint32)0x00000002)        /* Error Passive Flag */
#define  CAN_ESR_BOFF                        ((uint32)0x00000004)        /* Bus-Off Flag */

#define  CAN_ESR_LEC                         ((uint32)0x00000070)        /* LEC[2:0] bits (Last Error Code) */
#define  CAN_ESR_LEC_0                       ((uint32)0x00000010)        /* Bit 0 */
#define  CAN_ESR_LEC_1                       ((uint32)0x00000020)        /* Bit 1 */
#define  CAN_ESR_LEC_2                       ((uint32)0x00000040)        /* Bit 2 */

#define  CAN_ESR_TEC                         ((uint32)0x00FF0000)        /* Least significant byte of the 9-bit Transmit Error Counter */
#define  CAN_ESR_REC                         ((uint32)0xFF000000)        /* Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         ((uint32)0x000003FF)        /* Baud Rate Prescaler */
#define  CAN_BTR_TS1                         ((uint32)0x000F0000)        /* Time Segment 1 */
#define  CAN_BTR_TS2                         ((uint32)0x00700000)        /* Time Segment 2 */
#define  CAN_BTR_SJW                         ((uint32)0x03000000)        /* Resynchronization Jump Width */
#define  CAN_BTR_LBKM                        ((uint32)0x40000000)        /* Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        ((uint32)0x80000000)        /* Silent Mode */

/* Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define  CAN_TI0R_TXRQ                       ((uint32)0x00000001)        /* Transmit Mailbox Request */
#define  CAN_TI0R_RTR                        ((uint32)0x00000002)        /* Remote Transmission Request */
#define  CAN_TI0R_IDE                        ((uint32)0x00000004)        /* Identifier Extension */
#define  CAN_TI0R_EXID                       ((uint32)0x001FFFF8)        /* Extended Identifier */
#define  CAN_TI0R_STID                       ((uint32)0xFFE00000)        /* Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define  CAN_TDT0R_DLC                       ((uint32)0x0000000F)        /* Data Length Code */
#define  CAN_TDT0R_TGT                       ((uint32)0x00000100)        /* Transmit Global Time */
#define  CAN_TDT0R_TIME                      ((uint32)0xFFFF0000)        /* Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define  CAN_TDL0R_DATA0                     ((uint32)0x000000FF)        /* Data byte 0 */
#define  CAN_TDL0R_DATA1                     ((uint32)0x0000FF00)        /* Data byte 1 */
#define  CAN_TDL0R_DATA2                     ((uint32)0x00FF0000)        /* Data byte 2 */
#define  CAN_TDL0R_DATA3                     ((uint32)0xFF000000)        /* Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define  CAN_TDH0R_DATA4                     ((uint32)0x000000FF)        /* Data byte 4 */
#define  CAN_TDH0R_DATA5                     ((uint32)0x0000FF00)        /* Data byte 5 */
#define  CAN_TDH0R_DATA6                     ((uint32)0x00FF0000)        /* Data byte 6 */
#define  CAN_TDH0R_DATA7                     ((uint32)0xFF000000)        /* Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define  CAN_TI1R_TXRQ                       ((uint32)0x00000001)        /* Transmit Mailbox Request */
#define  CAN_TI1R_RTR                        ((uint32)0x00000002)        /* Remote Transmission Request */
#define  CAN_TI1R_IDE                        ((uint32)0x00000004)        /* Identifier Extension */
#define  CAN_TI1R_EXID                       ((uint32)0x001FFFF8)        /* Extended Identifier */
#define  CAN_TI1R_STID                       ((uint32)0xFFE00000)        /* Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define  CAN_TDT1R_DLC                       ((uint32)0x0000000F)        /* Data Length Code */
#define  CAN_TDT1R_TGT                       ((uint32)0x00000100)        /* Transmit Global Time */
#define  CAN_TDT1R_TIME                      ((uint32)0xFFFF0000)        /* Message Time Stamp */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define  CAN_TDL1R_DATA0                     ((uint32)0x000000FF)        /* Data byte 0 */
#define  CAN_TDL1R_DATA1                     ((uint32)0x0000FF00)        /* Data byte 1 */
#define  CAN_TDL1R_DATA2                     ((uint32)0x00FF0000)        /* Data byte 2 */
#define  CAN_TDL1R_DATA3                     ((uint32)0xFF000000)        /* Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define  CAN_TDH1R_DATA4                     ((uint32)0x000000FF)        /* Data byte 4 */
#define  CAN_TDH1R_DATA5                     ((uint32)0x0000FF00)        /* Data byte 5 */
#define  CAN_TDH1R_DATA6                     ((uint32)0x00FF0000)        /* Data byte 6 */
#define  CAN_TDH1R_DATA7                     ((uint32)0xFF000000)        /* Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define  CAN_TI2R_TXRQ                       ((uint32)0x00000001)        /* Transmit Mailbox Request */
#define  CAN_TI2R_RTR                        ((uint32)0x00000002)        /* Remote Transmission Request */
#define  CAN_TI2R_IDE                        ((uint32)0x00000004)        /* Identifier Extension */
#define  CAN_TI2R_EXID                       ((uint32)0x001FFFF8)        /* Extended identifier */
#define  CAN_TI2R_STID                       ((uint32)0xFFE00000)        /* Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/  
#define  CAN_TDT2R_DLC                       ((uint32)0x0000000F)        /* Data Length Code */
#define  CAN_TDT2R_TGT                       ((uint32)0x00000100)        /* Transmit Global Time */
#define  CAN_TDT2R_TIME                      ((uint32)0xFFFF0000)        /* Message Time Stamp */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define  CAN_TDL2R_DATA0                     ((uint32)0x000000FF)        /* Data byte 0 */
#define  CAN_TDL2R_DATA1                     ((uint32)0x0000FF00)        /* Data byte 1 */
#define  CAN_TDL2R_DATA2                     ((uint32)0x00FF0000)        /* Data byte 2 */
#define  CAN_TDL2R_DATA3                     ((uint32)0xFF000000)        /* Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define  CAN_TDH2R_DATA4                     ((uint32)0x000000FF)        /* Data byte 4 */
#define  CAN_TDH2R_DATA5                     ((uint32)0x0000FF00)        /* Data byte 5 */
#define  CAN_TDH2R_DATA6                     ((uint32)0x00FF0000)        /* Data byte 6 */
#define  CAN_TDH2R_DATA7                     ((uint32)0xFF000000)        /* Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define  CAN_RI0R_RTR                        ((uint32)0x00000002)        /* Remote Transmission Request */
#define  CAN_RI0R_IDE                        ((uint32)0x00000004)        /* Identifier Extension */
#define  CAN_RI0R_EXID                       ((uint32)0x001FFFF8)        /* Extended Identifier */
#define  CAN_RI0R_STID                       ((uint32)0xFFE00000)        /* Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define  CAN_RDT0R_DLC                       ((uint32)0x0000000F)        /* Data Length Code */
#define  CAN_RDT0R_FMI                       ((uint32)0x0000FF00)        /* Filter Match Index */
#define  CAN_RDT0R_TIME                      ((uint32)0xFFFF0000)        /* Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define  CAN_RDL0R_DATA0                     ((uint32)0x000000FF)        /* Data byte 0 */
#define  CAN_RDL0R_DATA1                     ((uint32)0x0000FF00)        /* Data byte 1 */
#define  CAN_RDL0R_DATA2                     ((uint32)0x00FF0000)        /* Data byte 2 */
#define  CAN_RDL0R_DATA3                     ((uint32)0xFF000000)        /* Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define  CAN_RDH0R_DATA4                     ((uint32)0x000000FF)        /* Data byte 4 */
#define  CAN_RDH0R_DATA5                     ((uint32)0x0000FF00)        /* Data byte 5 */
#define  CAN_RDH0R_DATA6                     ((uint32)0x00FF0000)        /* Data byte 6 */
#define  CAN_RDH0R_DATA7                     ((uint32)0xFF000000)        /* Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define  CAN_RI1R_RTR                        ((uint32)0x00000002)        /* Remote Transmission Request */
#define  CAN_RI1R_IDE                        ((uint32)0x00000004)        /* Identifier Extension */
#define  CAN_RI1R_EXID                       ((uint32)0x001FFFF8)        /* Extended identifier */
#define  CAN_RI1R_STID                       ((uint32)0xFFE00000)        /* Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define  CAN_RDT1R_DLC                       ((uint32)0x0000000F)        /* Data Length Code */
#define  CAN_RDT1R_FMI                       ((uint32)0x0000FF00)        /* Filter Match Index */
#define  CAN_RDT1R_TIME                      ((uint32)0xFFFF0000)        /* Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define  CAN_RDL1R_DATA0                     ((uint32)0x000000FF)        /* Data byte 0 */
#define  CAN_RDL1R_DATA1                     ((uint32)0x0000FF00)        /* Data byte 1 */
#define  CAN_RDL1R_DATA2                     ((uint32)0x00FF0000)        /* Data byte 2 */
#define  CAN_RDL1R_DATA3                     ((uint32)0xFF000000)        /* Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define  CAN_RDH1R_DATA4                     ((uint32)0x000000FF)        /* Data byte 4 */
#define  CAN_RDH1R_DATA5                     ((uint32)0x0000FF00)        /* Data byte 5 */
#define  CAN_RDH1R_DATA6                     ((uint32)0x00FF0000)        /* Data byte 6 */
#define  CAN_RDH1R_DATA7                     ((uint32)0xFF000000)        /* Data byte 7 */

/* CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define  CAN_FMR_FINIT                       ((uint8)0x01)               /* Filter Init Mode */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define  CAN_FM1R_FBM                        ((uint16)0x3FFF)            /* Filter Mode */
#define  CAN_FM1R_FBM0                       ((uint16)0x0001)            /* Filter Init Mode bit 0 */
#define  CAN_FM1R_FBM1                       ((uint16)0x0002)            /* Filter Init Mode bit 1 */
#define  CAN_FM1R_FBM2                       ((uint16)0x0004)            /* Filter Init Mode bit 2 */
#define  CAN_FM1R_FBM3                       ((uint16)0x0008)            /* Filter Init Mode bit 3 */
#define  CAN_FM1R_FBM4                       ((uint16)0x0010)            /* Filter Init Mode bit 4 */
#define  CAN_FM1R_FBM5                       ((uint16)0x0020)            /* Filter Init Mode bit 5 */
#define  CAN_FM1R_FBM6                       ((uint16)0x0040)            /* Filter Init Mode bit 6 */
#define  CAN_FM1R_FBM7                       ((uint16)0x0080)            /* Filter Init Mode bit 7 */
#define  CAN_FM1R_FBM8                       ((uint16)0x0100)            /* Filter Init Mode bit 8 */
#define  CAN_FM1R_FBM9                       ((uint16)0x0200)            /* Filter Init Mode bit 9 */
#define  CAN_FM1R_FBM10                      ((uint16)0x0400)            /* Filter Init Mode bit 10 */
#define  CAN_FM1R_FBM11                      ((uint16)0x0800)            /* Filter Init Mode bit 11 */
#define  CAN_FM1R_FBM12                      ((uint16)0x1000)            /* Filter Init Mode bit 12 */
#define  CAN_FM1R_FBM13                      ((uint16)0x2000)            /* Filter Init Mode bit 13 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define  CAN_FS1R_FSC                        ((uint16)0x3FFF)            /* Filter Scale Configuration */
#define  CAN_FS1R_FSC0                       ((uint16)0x0001)            /* Filter Scale Configuration bit 0 */
#define  CAN_FS1R_FSC1                       ((uint16)0x0002)            /* Filter Scale Configuration bit 1 */
#define  CAN_FS1R_FSC2                       ((uint16)0x0004)            /* Filter Scale Configuration bit 2 */
#define  CAN_FS1R_FSC3                       ((uint16)0x0008)            /* Filter Scale Configuration bit 3 */
#define  CAN_FS1R_FSC4                       ((uint16)0x0010)            /* Filter Scale Configuration bit 4 */
#define  CAN_FS1R_FSC5                       ((uint16)0x0020)            /* Filter Scale Configuration bit 5 */
#define  CAN_FS1R_FSC6                       ((uint16)0x0040)            /* Filter Scale Configuration bit 6 */
#define  CAN_FS1R_FSC7                       ((uint16)0x0080)            /* Filter Scale Configuration bit 7 */
#define  CAN_FS1R_FSC8                       ((uint16)0x0100)            /* Filter Scale Configuration bit 8 */
#define  CAN_FS1R_FSC9                       ((uint16)0x0200)            /* Filter Scale Configuration bit 9 */
#define  CAN_FS1R_FSC10                      ((uint16)0x0400)            /* Filter Scale Configuration bit 10 */
#define  CAN_FS1R_FSC11                      ((uint16)0x0800)            /* Filter Scale Configuration bit 11 */
#define  CAN_FS1R_FSC12                      ((uint16)0x1000)            /* Filter Scale Configuration bit 12 */
#define  CAN_FS1R_FSC13                      ((uint16)0x2000)            /* Filter Scale Configuration bit 13 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define  CAN_FFA1R_FFA                       ((uint16)0x3FFF)            /* Filter FIFO Assignment */
#define  CAN_FFA1R_FFA0                      ((uint16)0x0001)            /* Filter FIFO Assignment for Filter 0 */
#define  CAN_FFA1R_FFA1                      ((uint16)0x0002)            /* Filter FIFO Assignment for Filter 1 */
#define  CAN_FFA1R_FFA2                      ((uint16)0x0004)            /* Filter FIFO Assignment for Filter 2 */
#define  CAN_FFA1R_FFA3                      ((uint16)0x0008)            /* Filter FIFO Assignment for Filter 3 */
#define  CAN_FFA1R_FFA4                      ((uint16)0x0010)            /* Filter FIFO Assignment for Filter 4 */
#define  CAN_FFA1R_FFA5                      ((uint16)0x0020)            /* Filter FIFO Assignment for Filter 5 */
#define  CAN_FFA1R_FFA6                      ((uint16)0x0040)            /* Filter FIFO Assignment for Filter 6 */
#define  CAN_FFA1R_FFA7                      ((uint16)0x0080)            /* Filter FIFO Assignment for Filter 7 */
#define  CAN_FFA1R_FFA8                      ((uint16)0x0100)            /* Filter FIFO Assignment for Filter 8 */
#define  CAN_FFA1R_FFA9                      ((uint16)0x0200)            /* Filter FIFO Assignment for Filter 9 */
#define  CAN_FFA1R_FFA10                     ((uint16)0x0400)            /* Filter FIFO Assignment for Filter 10 */
#define  CAN_FFA1R_FFA11                     ((uint16)0x0800)            /* Filter FIFO Assignment for Filter 11 */
#define  CAN_FFA1R_FFA12                     ((uint16)0x1000)            /* Filter FIFO Assignment for Filter 12 */
#define  CAN_FFA1R_FFA13                     ((uint16)0x2000)            /* Filter FIFO Assignment for Filter 13 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define  CAN_FA1R_FACT                       ((uint16)0x3FFF)            /* Filter Active */
#define  CAN_FA1R_FACT0                      ((uint16)0x0001)            /* Filter 0 Active */
#define  CAN_FA1R_FACT1                      ((uint16)0x0002)            /* Filter 1 Active */
#define  CAN_FA1R_FACT2                      ((uint16)0x0004)            /* Filter 2 Active */
#define  CAN_FA1R_FACT3                      ((uint16)0x0008)            /* Filter 3 Active */
#define  CAN_FA1R_FACT4                      ((uint16)0x0010)            /* Filter 4 Active */
#define  CAN_FA1R_FACT5                      ((uint16)0x0020)            /* Filter 5 Active */
#define  CAN_FA1R_FACT6                      ((uint16)0x0040)            /* Filter 6 Active */
#define  CAN_FA1R_FACT7                      ((uint16)0x0080)            /* Filter 7 Active */
#define  CAN_FA1R_FACT8                      ((uint16)0x0100)            /* Filter 8 Active */
#define  CAN_FA1R_FACT9                      ((uint16)0x0200)            /* Filter 9 Active */
#define  CAN_FA1R_FACT10                     ((uint16)0x0400)            /* Filter 10 Active */
#define  CAN_FA1R_FACT11                     ((uint16)0x0800)            /* Filter 11 Active */
#define  CAN_FA1R_FACT12                     ((uint16)0x1000)            /* Filter 12 Active */
#define  CAN_FA1R_FACT13                     ((uint16)0x2000)            /* Filter 13 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define  CAN_F0R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F0R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F0R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F0R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F0R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F0R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F0R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F0R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F0R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F0R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F0R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F0R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F0R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F0R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F0R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F0R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F0R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F0R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F0R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F0R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F0R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F0R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F0R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F0R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F0R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F0R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F0R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F0R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F0R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F0R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F0R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F0R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define  CAN_F1R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F1R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F1R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F1R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F1R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F1R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F1R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F1R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F1R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F1R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F1R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F1R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F1R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F1R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F1R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F1R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F1R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F1R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F1R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F1R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F1R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F1R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F1R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F1R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F1R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F1R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F1R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F1R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F1R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F1R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F1R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F1R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define  CAN_F2R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F2R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F2R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F2R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F2R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F2R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F2R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F2R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F2R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F2R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F2R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F2R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F2R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F2R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F2R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F2R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F2R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F2R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F2R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F2R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F2R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F2R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F2R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F2R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F2R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F2R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F2R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F2R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F2R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F2R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F2R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F2R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define  CAN_F3R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F3R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F3R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F3R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F3R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F3R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F3R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F3R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F3R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F3R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F3R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F3R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F3R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F3R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F3R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F3R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F3R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F3R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F3R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F3R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F3R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F3R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F3R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F3R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F3R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F3R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F3R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F3R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F3R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F3R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F3R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F3R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define  CAN_F4R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F4R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F4R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F4R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F4R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F4R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F4R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F4R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F4R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F4R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F4R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F4R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F4R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F4R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F4R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F4R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F4R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F4R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F4R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F4R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F4R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F4R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F4R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F4R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F4R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F4R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F4R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F4R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F4R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F4R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F4R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F4R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define  CAN_F5R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F5R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F5R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F5R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F5R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F5R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F5R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F5R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F5R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F5R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F5R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F5R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F5R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F5R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F5R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F5R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F5R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F5R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F5R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F5R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F5R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F5R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F5R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F5R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F5R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F5R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F5R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F5R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F5R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F5R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F5R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F5R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define  CAN_F6R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F6R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F6R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F6R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F6R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F6R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F6R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F6R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F6R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F6R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F6R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F6R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F6R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F6R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F6R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F6R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F6R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F6R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F6R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F6R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F6R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F6R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F6R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F6R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F6R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F6R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F6R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F6R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F6R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F6R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F6R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F6R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define  CAN_F7R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F7R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F7R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F7R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F7R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F7R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F7R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F7R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F7R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F7R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F7R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F7R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F7R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F7R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F7R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F7R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F7R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F7R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F7R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F7R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F7R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F7R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F7R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F7R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F7R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F7R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F7R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F7R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F7R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F7R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F7R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F7R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define  CAN_F8R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F8R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F8R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F8R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F8R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F8R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F8R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F8R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F8R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F8R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F8R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F8R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F8R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F8R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F8R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F8R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F8R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F8R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F8R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F8R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F8R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F8R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F8R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F8R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F8R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F8R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F8R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F8R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F8R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F8R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F8R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F8R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define  CAN_F9R1_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F9R1_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F9R1_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F9R1_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F9R1_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F9R1_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F9R1_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F9R1_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F9R1_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F9R1_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F9R1_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F9R1_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F9R1_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F9R1_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F9R1_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F9R1_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F9R1_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F9R1_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F9R1_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F9R1_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F9R1_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F9R1_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F9R1_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F9R1_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F9R1_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F9R1_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F9R1_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F9R1_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F9R1_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F9R1_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F9R1_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F9R1_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define  CAN_F10R1_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F10R1_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F10R1_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F10R1_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F10R1_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F10R1_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F10R1_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F10R1_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F10R1_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F10R1_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F10R1_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F10R1_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F10R1_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F10R1_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F10R1_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F10R1_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F10R1_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F10R1_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F10R1_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F10R1_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F10R1_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F10R1_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F10R1_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F10R1_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F10R1_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F10R1_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F10R1_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F10R1_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F10R1_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F10R1_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F10R1_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F10R1_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define  CAN_F11R1_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F11R1_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F11R1_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F11R1_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F11R1_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F11R1_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F11R1_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F11R1_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F11R1_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F11R1_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F11R1_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F11R1_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F11R1_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F11R1_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F11R1_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F11R1_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F11R1_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F11R1_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F11R1_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F11R1_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F11R1_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F11R1_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F11R1_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F11R1_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F11R1_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F11R1_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F11R1_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F11R1_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F11R1_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F11R1_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F11R1_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F11R1_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define  CAN_F12R1_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F12R1_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F12R1_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F12R1_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F12R1_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F12R1_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F12R1_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F12R1_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F12R1_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F12R1_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F12R1_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F12R1_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F12R1_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F12R1_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F12R1_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F12R1_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F12R1_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F12R1_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F12R1_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F12R1_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F12R1_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F12R1_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F12R1_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F12R1_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F12R1_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F12R1_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F12R1_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F12R1_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F12R1_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F12R1_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F12R1_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F12R1_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define  CAN_F13R1_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F13R1_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F13R1_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F13R1_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F13R1_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F13R1_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F13R1_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F13R1_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F13R1_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F13R1_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F13R1_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F13R1_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F13R1_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F13R1_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F13R1_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F13R1_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F13R1_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F13R1_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F13R1_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F13R1_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F13R1_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F13R1_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F13R1_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F13R1_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F13R1_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F13R1_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F13R1_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F13R1_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F13R1_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F13R1_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F13R1_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F13R1_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define  CAN_F0R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F0R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F0R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F0R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F0R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F0R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F0R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F0R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F0R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F0R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F0R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F0R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F0R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F0R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F0R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F0R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F0R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F0R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F0R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F0R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F0R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F0R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F0R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F0R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F0R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F0R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F0R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F0R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F0R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F0R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F0R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F0R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define  CAN_F1R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F1R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F1R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F1R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F1R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F1R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F1R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F1R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F1R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F1R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F1R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F1R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F1R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F1R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F1R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F1R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F1R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F1R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F1R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F1R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F1R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F1R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F1R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F1R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F1R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F1R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F1R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F1R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F1R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F1R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F1R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F1R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define  CAN_F2R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F2R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F2R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F2R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F2R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F2R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F2R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F2R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F2R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F2R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F2R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F2R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F2R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F2R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F2R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F2R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F2R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F2R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F2R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F2R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F2R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F2R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F2R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F2R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F2R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F2R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F2R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F2R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F2R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F2R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F2R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F2R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define  CAN_F3R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F3R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F3R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F3R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F3R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F3R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F3R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F3R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F3R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F3R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F3R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F3R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F3R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F3R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F3R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F3R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F3R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F3R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F3R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F3R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F3R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F3R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F3R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F3R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F3R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F3R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F3R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F3R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F3R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F3R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F3R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F3R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define  CAN_F4R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F4R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F4R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F4R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F4R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F4R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F4R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F4R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F4R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F4R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F4R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F4R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F4R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F4R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F4R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F4R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F4R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F4R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F4R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F4R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F4R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F4R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F4R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F4R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F4R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F4R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F4R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F4R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F4R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F4R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F4R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F4R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define  CAN_F5R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F5R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F5R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F5R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F5R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F5R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F5R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F5R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F5R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F5R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F5R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F5R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F5R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F5R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F5R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F5R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F5R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F5R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F5R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F5R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F5R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F5R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F5R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F5R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F5R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F5R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F5R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F5R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F5R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F5R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F5R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F5R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define  CAN_F6R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F6R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F6R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F6R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F6R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F6R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F6R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F6R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F6R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F6R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F6R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F6R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F6R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F6R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F6R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F6R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F6R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F6R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F6R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F6R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F6R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F6R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F6R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F6R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F6R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F6R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F6R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F6R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F6R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F6R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F6R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F6R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define  CAN_F7R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F7R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F7R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F7R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F7R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F7R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F7R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F7R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F7R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F7R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F7R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F7R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F7R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F7R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F7R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F7R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F7R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F7R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F7R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F7R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F7R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F7R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F7R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F7R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F7R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F7R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F7R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F7R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F7R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F7R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F7R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F7R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define  CAN_F8R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F8R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F8R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F8R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F8R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F8R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F8R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F8R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F8R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F8R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F8R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F8R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F8R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F8R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F8R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F8R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F8R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F8R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F8R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F8R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F8R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F8R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F8R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F8R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F8R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F8R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F8R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F8R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F8R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F8R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F8R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F8R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define  CAN_F9R2_FB0                        ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F9R2_FB1                        ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F9R2_FB2                        ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F9R2_FB3                        ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F9R2_FB4                        ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F9R2_FB5                        ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F9R2_FB6                        ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F9R2_FB7                        ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F9R2_FB8                        ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F9R2_FB9                        ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F9R2_FB10                       ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F9R2_FB11                       ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F9R2_FB12                       ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F9R2_FB13                       ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F9R2_FB14                       ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F9R2_FB15                       ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F9R2_FB16                       ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F9R2_FB17                       ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F9R2_FB18                       ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F9R2_FB19                       ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F9R2_FB20                       ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F9R2_FB21                       ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F9R2_FB22                       ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F9R2_FB23                       ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F9R2_FB24                       ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F9R2_FB25                       ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F9R2_FB26                       ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F9R2_FB27                       ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F9R2_FB28                       ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F9R2_FB29                       ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F9R2_FB30                       ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F9R2_FB31                       ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define  CAN_F10R2_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F10R2_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F10R2_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F10R2_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F10R2_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F10R2_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F10R2_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F10R2_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F10R2_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F10R2_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F10R2_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F10R2_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F10R2_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F10R2_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F10R2_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F10R2_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F10R2_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F10R2_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F10R2_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F10R2_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F10R2_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F10R2_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F10R2_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F10R2_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F10R2_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F10R2_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F10R2_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F10R2_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F10R2_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F10R2_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F10R2_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F10R2_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define  CAN_F11R2_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F11R2_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F11R2_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F11R2_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F11R2_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F11R2_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F11R2_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F11R2_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F11R2_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F11R2_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F11R2_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F11R2_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F11R2_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F11R2_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F11R2_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F11R2_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F11R2_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F11R2_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F11R2_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F11R2_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F11R2_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F11R2_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F11R2_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F11R2_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F11R2_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F11R2_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F11R2_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F11R2_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F11R2_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F11R2_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F11R2_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F11R2_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define  CAN_F12R2_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F12R2_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F12R2_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F12R2_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F12R2_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F12R2_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F12R2_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F12R2_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F12R2_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F12R2_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F12R2_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F12R2_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F12R2_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F12R2_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F12R2_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F12R2_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F12R2_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F12R2_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F12R2_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F12R2_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F12R2_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F12R2_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F12R2_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F12R2_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F12R2_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F12R2_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F12R2_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F12R2_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F12R2_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F12R2_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F12R2_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F12R2_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define  CAN_F13R2_FB0                       ((uint32)0x00000001)        /* Filter bit 0 */
#define  CAN_F13R2_FB1                       ((uint32)0x00000002)        /* Filter bit 1 */
#define  CAN_F13R2_FB2                       ((uint32)0x00000004)        /* Filter bit 2 */
#define  CAN_F13R2_FB3                       ((uint32)0x00000008)        /* Filter bit 3 */
#define  CAN_F13R2_FB4                       ((uint32)0x00000010)        /* Filter bit 4 */
#define  CAN_F13R2_FB5                       ((uint32)0x00000020)        /* Filter bit 5 */
#define  CAN_F13R2_FB6                       ((uint32)0x00000040)        /* Filter bit 6 */
#define  CAN_F13R2_FB7                       ((uint32)0x00000080)        /* Filter bit 7 */
#define  CAN_F13R2_FB8                       ((uint32)0x00000100)        /* Filter bit 8 */
#define  CAN_F13R2_FB9                       ((uint32)0x00000200)        /* Filter bit 9 */
#define  CAN_F13R2_FB10                      ((uint32)0x00000400)        /* Filter bit 10 */
#define  CAN_F13R2_FB11                      ((uint32)0x00000800)        /* Filter bit 11 */
#define  CAN_F13R2_FB12                      ((uint32)0x00001000)        /* Filter bit 12 */
#define  CAN_F13R2_FB13                      ((uint32)0x00002000)        /* Filter bit 13 */
#define  CAN_F13R2_FB14                      ((uint32)0x00004000)        /* Filter bit 14 */
#define  CAN_F13R2_FB15                      ((uint32)0x00008000)        /* Filter bit 15 */
#define  CAN_F13R2_FB16                      ((uint32)0x00010000)        /* Filter bit 16 */
#define  CAN_F13R2_FB17                      ((uint32)0x00020000)        /* Filter bit 17 */
#define  CAN_F13R2_FB18                      ((uint32)0x00040000)        /* Filter bit 18 */
#define  CAN_F13R2_FB19                      ((uint32)0x00080000)        /* Filter bit 19 */
#define  CAN_F13R2_FB20                      ((uint32)0x00100000)        /* Filter bit 20 */
#define  CAN_F13R2_FB21                      ((uint32)0x00200000)        /* Filter bit 21 */
#define  CAN_F13R2_FB22                      ((uint32)0x00400000)        /* Filter bit 22 */
#define  CAN_F13R2_FB23                      ((uint32)0x00800000)        /* Filter bit 23 */
#define  CAN_F13R2_FB24                      ((uint32)0x01000000)        /* Filter bit 24 */
#define  CAN_F13R2_FB25                      ((uint32)0x02000000)        /* Filter bit 25 */
#define  CAN_F13R2_FB26                      ((uint32)0x04000000)        /* Filter bit 26 */
#define  CAN_F13R2_FB27                      ((uint32)0x08000000)        /* Filter bit 27 */
#define  CAN_F13R2_FB28                      ((uint32)0x10000000)        /* Filter bit 28 */
#define  CAN_F13R2_FB29                      ((uint32)0x20000000)        /* Filter bit 29 */
#define  CAN_F13R2_FB30                      ((uint32)0x40000000)        /* Filter bit 30 */
#define  CAN_F13R2_FB31                      ((uint32)0x80000000)        /* Filter bit 31 */

#endif /* CAN_REGS */