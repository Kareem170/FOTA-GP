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
#define  CAN_MCR_INRQ                        (0U)            /* Initialization Request */
#define  CAN_MCR_SLEEP                       (1U)            /* Sleep Mode Request */
#define  CAN_MCR_TXFP                        (2U)            /* Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        (3U)            /* Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        (4U)            /* No Automatic Retransmission */
#define  CAN_MCR_AWUM                        (5U)            /* Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        (6U)            /* Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        (7U)            /* Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       (15U)           /* bxCAN software master reset */
#define  CAN_MCR_DPF                         (16U)           /* bxCAN Debug Freeze */

/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        (0U)            /* Initialization Acknowledge */
#define  CAN_MSR_SLAK                        (1U)            /* Sleep Acknowledge */
#define  CAN_MSR_ERRI                        (2U)            /* Error Interrupt */
#define  CAN_MSR_WKUI                        (3U)            /* Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       (4U)            /* Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         (8U)            /* Transmit Mode */
#define  CAN_MSR_RXM                         (9U)            /* Receive Mode */
#define  CAN_MSR_SAMP                        (10U)           /* Last Sample Point */
#define  CAN_MSR_RX                          (11U)           /* CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       (0U)         /* Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       (1U)         /* Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       (2U)         /* Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       (3U)         /* Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       (7U)         /* Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       (8U)         /* Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       (9U)         /* Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       (10U)        /* Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       (11U)        /* Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       (15U)        /* Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       (16U)        /* Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       (17U)        /* Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       (18U)        /* Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       (19U)        /* Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       (23U)        /* Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        (24U)        /* Mailbox Code */

#define  CAN_TSR_TME                         (1C000000)        /* TME[2:0] bits */
#define  CAN_TSR_TME0                        (26U)        /* Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        (27U)        /* Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        (28U)        /* Transmit Mailbox 2 Empty */

//#define  CAN_TSR_LOW                         (E0000000)        /* LOW[2:0] bits */
#define  CAN_TSR_LOW0                        (29U)        /* Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        (30U)        /* Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        (31U)        /* Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define  CAN_RF0R_FMP0                       (0U)               /* FIFO 0 Message Pending */
#define  CAN_RF0R_FULL0                      (3U)               /* FIFO 0 Full */
#define  CAN_RF0R_FOVR0                      (4U)               /* FIFO 0 Overrun */
#define  CAN_RF0R_RFOM0                      (5U)               /* Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define  CAN_RF1R_FMP1                       (0U)               /* FIFO 1 Message Pending */
#define  CAN_RF1R_FULL1                      (3U)               /* FIFO 1 Full */
#define  CAN_RF1R_FOVR1                      (4U)               /* FIFO 1 Overrun */
#define  CAN_RF1R_RFOM1                      (5U)               /* Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       (0U)        /* Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      (1U)        /* FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       (2U)        /* FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      (3U)        /* FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      (4U)        /* FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       (5U)        /* FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      (6U)        /* FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       (8U)        /* Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       (9U)        /* Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       (10U)       /* Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       (11U)       /* Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       (15U)       /* Error Interrupt Enable */
#define  CAN_IER_WKUIE                       (16U)       /* Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       (17U)       /* Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define  CAN_ESR_EWGF                        (0U)         /* Error Warning Flag */
#define  CAN_ESR_EPVF                        (1U)         /* Error Passive Flag */
#define  CAN_ESR_BOFF                        (2U)         /* Bus-Off Flag */

#define  CAN_ESR_LEC                         (4U)         /* LEC[2:0] bits (Last Error Code) */
//#define  CAN_ESR_LEC_0                       (0U0)        /* Bit 0 */
//#define  CAN_ESR_LEC_1                       (0001U0)        /* Bit 1 */
//#define  CAN_ESR_LEC_2                       (00000040)        /* Bit 2 */

#define  CAN_ESR_TEC                         (16U)        /* Least significant byte of the 9-bit Transmit Error Counter */
#define  CAN_ESR_REC                         (24U)        /* Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         (0U)         /* Baud Rate Prescaler */
#define  CAN_BTR_TS1                         (16U)        /* Time Segment 1 */
#define  CAN_BTR_TS2                         (20U)        /* Time Segment 2 */
#define  CAN_BTR_SJW                         (24U)        /* Resynchronization Jump Width */
#define  CAN_BTR_LBKM                        (30U)        /* Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        (31U)        /* Silent Mode */

/* Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define  CAN_TI0R_TXRQ                       (0U)        /* Transmit Mailbox Request */
#define  CAN_TI0R_RTR                        (1U)        /* Remote Transmission Request */
#define  CAN_TI0R_IDE                        (2U)        /* Identifier Extension */
#define  CAN_TI0R_EXID                       (3U)        /* Extended Identifier */
#define  CAN_TI0R_STID                       (21U)       /* Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define  CAN_TDT0R_DLC                       (0U)        /* Data Length Code */
#define  CAN_TDT0R_TGT                       (8U)        /* Transmit Global Time */
#define  CAN_TDT0R_TIME                      (16U)       /* Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define  CAN_TDL0R_DATA0                     (0U)        /* Data byte 0 */
#define  CAN_TDL0R_DATA1                     (8U)        /* Data byte 1 */
#define  CAN_TDL0R_DATA2                     (16U)       /* Data byte 2 */
#define  CAN_TDL0R_DATA3                     (24U)       /* Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define  CAN_TDH0R_DATA4                     (0U)        /* Data byte 4 */
#define  CAN_TDH0R_DATA5                     (8U)        /* Data byte 5 */
#define  CAN_TDH0R_DATA6                     (16U)       /* Data byte 6 */
#define  CAN_TDH0R_DATA7                     (24U)       /* Data byte 7 */

/******************  Bit definition for CAN_TI1R register  ********************/
#define  CAN_TI1R_TXRQ                       (0U)        /* Transmit Mailbox Request */
#define  CAN_TI1R_RTR                        (1U)        /* Remote Transmission Request */
#define  CAN_TI1R_IDE                        (2U)        /* Identifier Extension */
#define  CAN_TI1R_EXID                       (3U)        /* Extended Identifier */
#define  CAN_TI1R_STID                       (21U)       /* Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT1R register  *******************/
#define  CAN_TDT1R_DLC                       (0U)        /* Data Length Code */
#define  CAN_TDT1R_TGT                       (8U)        /* Transmit Global Time */
#define  CAN_TDT1R_TIME                      (16U)       /* Message Time Stamp */

/******************  Bit definition for CAN_TDL1R register  *******************/
#define  CAN_TDL1R_DATA0                     (0U)        /* Data byte 0 */
#define  CAN_TDL1R_DATA1                     (8U)        /* Data byte 1 */
#define  CAN_TDL1R_DATA2                     (16U)       /* Data byte 2 */
#define  CAN_TDL1R_DATA3                     (24U)       /* Data byte 3 */

/******************  Bit definition for CAN_TDH1R register  *******************/
#define  CAN_TDH1R_DATA4                     (0U)        /* Data byte 4 */
#define  CAN_TDH1R_DATA5                     (8U)        /* Data byte 5 */
#define  CAN_TDH1R_DATA6                     (16U)       /* Data byte 6 */
#define  CAN_TDH1R_DATA7                     (24U)       /* Data byte 7 */


/******************  Bit definition for CAN_TI2R register  ********************/
#define  CAN_TI2R_TXRQ                       (0U)        /* Transmit Mailbox Request */
#define  CAN_TI2R_RTR                        (1U)        /* Remote Transmission Request */
#define  CAN_TI2R_IDE                        (2U)        /* Identifier Extension */
#define  CAN_TI2R_EXID                       (3U)        /* Extended Identifier */
#define  CAN_TI2R_STID                       (21U)       /* Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT2R register  *******************/
#define  CAN_TDT2R_DLC                       (0U)        /* Data Length Code */
#define  CAN_TDT2R_TGT                       (8U)        /* Transmit Global Time */
#define  CAN_TDT2R_TIME                      (16U)       /* Message Time Stamp */

/******************  Bit definition for CAN_TDL2R register  *******************/
#define  CAN_TDL2R_DATA0                     (0U)        /* Data byte 0 */
#define  CAN_TDL2R_DATA1                     (8U)        /* Data byte 1 */
#define  CAN_TDL2R_DATA2                     (16U)       /* Data byte 2 */
#define  CAN_TDL2R_DATA3                     (24U)       /* Data byte 3 */

/******************  Bit definition for CAN_TDH2R register  *******************/
#define  CAN_TDH2R_DATA4                     (0U)        /* Data byte 4 */
#define  CAN_TDH2R_DATA5                     (8U)        /* Data byte 5 */
#define  CAN_TDH2R_DATA6                     (16U)       /* Data byte 6 */
#define  CAN_TDH2R_DATA7                     (24U)       /* Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define  CAN_RI0R_RTR                        (1U)        /* Remote Transmission Request */
#define  CAN_RI0R_IDE                        (2U)        /* Identifier Extension */
#define  CAN_RI0R_EXID                       (3U)        /* Extended Identifier */
#define  CAN_RI0R_STID                       (21U)       /* Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define  CAN_RDT0R_DLC                       (0U)        /* Data Length Code */
#define  CAN_RDT0R_FMI                       (8U)        /* Filter Match Index */
#define  CAN_RDT0R_TIME                      (16U)       /* Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define  CAN_RDL0R_DATA0                     (0U)        /* Data byte 0 */
#define  CAN_RDL0R_DATA1                     (8U)        /* Data byte 1 */
#define  CAN_RDL0R_DATA2                     (16U)       /* Data byte 2 */
#define  CAN_RDL0R_DATA3                     (24U)       /* Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define  CAN_RDH0R_DATA4                     (0U)        /* Data byte 4 */
#define  CAN_RDH0R_DATA5                     (8U)        /* Data byte 5 */
#define  CAN_RDH0R_DATA6                     (16U)       /* Data byte 6 */
#define  CAN_RDH0R_DATA7                     (24U)       /* Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define  CAN_RI1R_RTR                        (1U)        /* Remote Transmission Request */
#define  CAN_RI1R_IDE                        (2U)        /* Identifier Extension */
#define  CAN_RI1R_EXID                       (3U)        /* Extended Identifier */
#define  CAN_RI1R_STID                       (21U)       /* Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define  CAN_RDT1R_DLC                       (0U)        /* Data Length Code */
#define  CAN_RDT1R_FMI                       (8U)        /* Filter Match Index */
#define  CAN_RDT1R_TIME                      (16U)       /* Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define  CAN_RDL1R_DATA0                     (0U)        /* Data byte 0 */
#define  CAN_RDL1R_DATA1                     (8U)        /* Data byte 1 */
#define  CAN_RDL1R_DATA2                     (16U)       /* Data byte 2 */
#define  CAN_RDL1R_DATA3                     (24U)       /* Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define  CAN_RDH1R_DATA4                     (0U)        /* Data byte 4 */
#define  CAN_RDH1R_DATA5                     (8U)        /* Data byte 5 */
#define  CAN_RDH1R_DATA6                     (16U)       /* Data byte 6 */
#define  CAN_RDH1R_DATA7                     (24U)       /* Data byte 7 */

/* CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define  CAN_FMR_FINIT                       (0U)        /* Filter Init Mode */
#define  CAN_FMR_CAN2SB                      (8U)        /* CAN2 Start Bank */

/*******************  Bit definition for CAN_FM1R register  *******************/
//#define  CAN_FM1R_FBM                        ( 3FFF)       /* Filter Mode */
#define  CAN_FM1R_FBM0                       (0U)         /* Filter Init Mode bit 0 */
#define  CAN_FM1R_FBM1                       (1U)         /* Filter Init Mode bit 1 */
#define  CAN_FM1R_FBM2                       (2U)         /* Filter Init Mode bit 2 */
#define  CAN_FM1R_FBM3                       (3U)         /* Filter Init Mode bit 3 */
#define  CAN_FM1R_FBM4                       (4U)         /* Filter Init Mode bit 4 */
#define  CAN_FM1R_FBM5                       (5U)         /* Filter Init Mode bit 5 */
#define  CAN_FM1R_FBM6                       (6U)         /* Filter Init Mode bit 6 */
#define  CAN_FM1R_FBM7                       (7U)         /* Filter Init Mode bit 7 */
#define  CAN_FM1R_FBM8                       (8U)         /* Filter Init Mode bit 8 */
#define  CAN_FM1R_FBM9                       (9U)         /* Filter Init Mode bit 9 */
#define  CAN_FM1R_FBM10                      (10U)        /* Filter Init Mode bit 10 */
#define  CAN_FM1R_FBM11                      (11U)        /* Filter Init Mode bit 11 */
#define  CAN_FM1R_FBM12                      (12U)        /* Filter Init Mode bit 12 */
#define  CAN_FM1R_FBM13                      (13U)        /* Filter Init Mode bit 13 */
#define  CAN_FM1R_FBM14                      (14U)        /* Filter Init Mode bit 14 */
#define  CAN_FM1R_FBM15                      (15U)        /* Filter Init Mode bit 15 */
#define  CAN_FM1R_FBM16                      (16U)        /* Filter Init Mode bit 16 */
#define  CAN_FM1R_FBM17                      (17U)        /* Filter Init Mode bit 17 */
#define  CAN_FM1R_FBM18                      (18U)        /* Filter Init Mode bit 18 */
#define  CAN_FM1R_FBM19                      (19U)        /* Filter Init Mode bit 19 */
#define  CAN_FM1R_FBM20                      (20U)        /* Filter Init Mode bit 20 */
#define  CAN_FM1R_FBM21                      (21U)        /* Filter Init Mode bit 21 */
#define  CAN_FM1R_FBM22                      (22U)        /* Filter Init Mode bit 22 */
#define  CAN_FM1R_FBM23                      (23U)        /* Filter Init Mode bit 23 */
#define  CAN_FM1R_FBM24                      (24U)        /* Filter Init Mode bit 24 */
#define  CAN_FM1R_FBM25                      (25U)        /* Filter Init Mode bit 25 */
#define  CAN_FM1R_FBM26                      (26U)        /* Filter Init Mode bit 26 */
#define  CAN_FM1R_FBM27                      (27U)        /* Filter Init Mode bit 27 */

/*******************  Bit definition for CAN_FS1R register  *******************/
//#define  CAN_FS1R_FSC                        ( 3FFF)       /* Filter Scale Configuration */
#define  CAN_FS1R_FSC0                       (0U)         /* Filter Scale Configuration bit 0 */
#define  CAN_FS1R_FSC1                       (1U)         /* Filter Scale Configuration bit 1 */
#define  CAN_FS1R_FSC2                       (2U)         /* Filter Scale Configuration bit 2 */
#define  CAN_FS1R_FSC3                       (3U)         /* Filter Scale Configuration bit 3 */
#define  CAN_FS1R_FSC4                       (4U)         /* Filter Scale Configuration bit 4 */
#define  CAN_FS1R_FSC5                       (5U)         /* Filter Scale Configuration bit 5 */
#define  CAN_FS1R_FSC6                       (6U)         /* Filter Scale Configuration bit 6 */
#define  CAN_FS1R_FSC7                       (7U)         /* Filter Scale Configuration bit 7 */
#define  CAN_FS1R_FSC8                       (8U)         /* Filter Scale Configuration bit 8 */
#define  CAN_FS1R_FSC9                       (9U)         /* Filter Scale Configuration bit 9 */
#define  CAN_FS1R_FSC10                      (10U)        /* Filter Scale Configuration bit 10 */
#define  CAN_FS1R_FSC11                      (11U)        /* Filter Scale Configuration bit 11 */
#define  CAN_FS1R_FSC12                      (12U)        /* Filter Scale Configuration bit 12 */
#define  CAN_FS1R_FSC13                      (13U)        /* Filter Scale Configuration bit 13 */
#define  CAN_FS1R_FSC14                      (14U)        /* Filter Scale Configuration bit 14 */
#define  CAN_FS1R_FSC15                      (15U)        /* Filter Scale Configuration bit 15 */
#define  CAN_FS1R_FSC16                      (16U)        /* Filter Scale Configuration bit 16 */
#define  CAN_FS1R_FSC17                      (17U)        /* Filter Scale Configuration bit 17 */
#define  CAN_FS1R_FSC18                      (18U)        /* Filter Scale Configuration bit 18 */
#define  CAN_FS1R_FSC19                      (19U)        /* Filter Scale Configuration bit 19 */
#define  CAN_FS1R_FSC20                      (20U)        /* Filter Scale Configuration bit 20 */
#define  CAN_FS1R_FSC21                      (21U)        /* Filter Scale Configuration bit 21 */
#define  CAN_FS1R_FSC22                      (22U)        /* Filter Scale Configuration bit 22 */
#define  CAN_FS1R_FSC23                      (23U)        /* Filter Scale Configuration bit 23 */
#define  CAN_FS1R_FSC24                      (24U)        /* Filter Scale Configuration bit 24 */
#define  CAN_FS1R_FSC25                      (25U)        /* Filter Scale Configuration bit 25 */
#define  CAN_FS1R_FSC26                      (26U)        /* Filter Scale Configuration bit 26 */
#define  CAN_FS1R_FSC27                      (27U)        /* Filter Scale Configuration bit 27 */

/*******************  Bit definition for CAN_FFA1R register  *******************/
//#define  CAN_FFA1R_FFA                        ( 3FFF)       /* Filter FIFO Assignment */
#define  CAN_FFA1R_FFA0                       (0U)         /* Filter FIFO Assignment for Filter 0 */
#define  CAN_FFA1R_FFA1                       (1U)         /* Filter FIFO Assignment for Filter 1 */
#define  CAN_FFA1R_FFA2                       (2U)         /* Filter FIFO Assignment for Filter 2 */
#define  CAN_FFA1R_FFA3                       (3U)         /* Filter FIFO Assignment for Filter 3 */
#define  CAN_FFA1R_FFA4                       (4U)         /* Filter FIFO Assignment for Filter 4 */
#define  CAN_FFA1R_FFA5                       (5U)         /* Filter FIFO Assignment for Filter 5 */
#define  CAN_FFA1R_FFA6                       (6U)         /* Filter FIFO Assignment for Filter 6 */
#define  CAN_FFA1R_FFA7                       (7U)         /* Filter FIFO Assignment for Filter 7 */
#define  CAN_FFA1R_FFA8                       (8U)         /* Filter FIFO Assignment for Filter 8 */
#define  CAN_FFA1R_FFA9                       (9U)         /* Filter FIFO Assignment for Filter 9 */
#define  CAN_FFA1R_FFA10                      (10U)        /* Filter FIFO Assignment for Filter 10 */
#define  CAN_FFA1R_FFA11                      (11U)        /* Filter FIFO Assignment for Filter 11 */
#define  CAN_FFA1R_FFA12                      (12U)        /* Filter FIFO Assignment for Filter 12 */
#define  CAN_FFA1R_FFA13                      (13U)        /* Filter FIFO Assignment for Filter 13 */
#define  CAN_FFA1R_FFA14                      (14U)        /* Filter FIFO Assignment for Filter 14 */
#define  CAN_FFA1R_FFA15                      (15U)        /* Filter FIFO Assignment for Filter 15 */
#define  CAN_FFA1R_FFA16                      (16U)        /* Filter FIFO Assignment for Filter 16 */
#define  CAN_FFA1R_FFA17                      (17U)        /* Filter FIFO Assignment for Filter 17 */
#define  CAN_FFA1R_FFA18                      (18U)        /* Filter FIFO Assignment for Filter 18 */
#define  CAN_FFA1R_FFA19                      (19U)        /* Filter FIFO Assignment for Filter 19 */
#define  CAN_FFA1R_FFA20                      (20U)        /* Filter FIFO Assignment for Filter 20 */
#define  CAN_FFA1R_FFA21                      (21U)        /* Filter FIFO Assignment for Filter 21 */
#define  CAN_FFA1R_FFA22                      (22U)        /* Filter FIFO Assignment for Filter 22 */
#define  CAN_FFA1R_FFA23                      (23U)        /* Filter FIFO Assignment for Filter 23 */
#define  CAN_FFA1R_FFA24                      (24U)        /* Filter FIFO Assignment for Filter 24 */
#define  CAN_FFA1R_FFA25                      (25U)        /* Filter FIFO Assignment for Filter 25 */
#define  CAN_FFA1R_FFA26                      (26U)        /* Filter FIFO Assignment for Filter 26 */
#define  CAN_FFA1R_FFA27                      (27U)        /* Filter FIFO Assignment for Filter 27 */

/*******************  Bit definition for CAN_FA1R register  *******************/
//#define  CAN_FA1R_FACT                        ( 3FFF)       /* Filter Active */
#define  CAN_FA1R_FACT0                       (0U)            /* Filter 0 Active */
#define  CAN_FA1R_FACT1                       (1U)            /* Filter 1 Active */
#define  CAN_FA1R_FACT2                       (2U)            /* Filter 2 Active */
#define  CAN_FA1R_FACT3                       (3U)            /* Filter 3 Active */
#define  CAN_FA1R_FACT4                       (4U)            /* Filter 4 Active */
#define  CAN_FA1R_FACT5                       (5U)            /* Filter 5 Active */
#define  CAN_FA1R_FACT6                       (6U)            /* Filter 6 Active */
#define  CAN_FA1R_FACT7                       (7U)            /* Filter 7 Active */
#define  CAN_FA1R_FACT8                       (8U)            /* Filter 8 Active */
#define  CAN_FA1R_FACT9                       (9U)            /* Filter 9 Active */
#define  CAN_FA1R_FACT10                      (10U)           /* Filter 10 Active */
#define  CAN_FA1R_FACT11                      (11U)           /* Filter 11 Active */
#define  CAN_FA1R_FACT12                      (12U)           /* Filter 12 Active */
#define  CAN_FA1R_FACT13                      (13U)           /* Filter 13 Active */
#define  CAN_FA1R_FACT14                      (14U)           /* Filter 14 Active */
#define  CAN_FA1R_FACT15                      (15U)           /* Filter 15 Active */
#define  CAN_FA1R_FACT16                      (16U)           /* Filter 16 Active */
#define  CAN_FA1R_FACT17                      (17U)           /* Filter 17 Active */
#define  CAN_FA1R_FACT18                      (18U)           /* Filter 18 Active */
#define  CAN_FA1R_FACT19                      (19U)           /* Filter 19 Active */
#define  CAN_FA1R_FACT20                      (20U)           /* Filter 20 Active */
#define  CAN_FA1R_FACT21                      (21U)           /* Filter 21 Active */
#define  CAN_FA1R_FACT22                      (22U)           /* Filter 22 Active */
#define  CAN_FA1R_FACT23                      (23U)           /* Filter 23 Active */
#define  CAN_FA1R_FACT24                      (24U)           /* Filter 24 Active */
#define  CAN_FA1R_FACT25                      (25U)           /* Filter 25 Active */
#define  CAN_FA1R_FACT26                      (26U)           /* Filter 26 Active */
#define  CAN_FA1R_FACT27                      (27U)           /* Filter 27 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define  CAN_F0R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F0R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F0R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F0R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F0R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F0R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F0R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F0R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F0R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F0R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F0R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F0R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F0R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F0R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F0R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F0R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F0R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F0R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F0R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F0R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F0R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F0R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F0R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F0R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F0R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F0R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F0R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F0R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F0R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F0R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F0R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F0R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define  CAN_F1R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F1R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F1R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F1R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F1R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F1R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F1R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F1R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F1R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F1R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F1R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F1R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F1R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F1R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F1R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F1R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F1R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F1R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F1R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F1R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F1R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F1R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F1R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F1R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F1R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F1R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F1R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F1R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F1R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F1R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F1R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F1R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define  CAN_F2R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F2R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F2R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F2R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F2R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F2R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F2R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F2R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F2R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F2R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F2R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F2R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F2R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F2R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F2R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F2R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F2R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F2R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F2R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F2R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F2R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F2R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F2R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F2R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F2R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F2R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F2R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F2R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F2R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F2R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F2R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F2R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define  CAN_F3R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F3R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F3R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F3R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F3R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F3R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F3R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F3R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F3R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F3R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F3R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F3R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F3R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F3R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F3R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F3R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F3R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F3R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F3R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F3R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F3R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F3R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F3R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F3R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F3R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F3R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F3R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F3R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F3R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F3R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F3R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F3R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define  CAN_F4R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F4R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F4R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F4R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F4R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F4R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F4R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F4R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F4R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F4R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F4R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F4R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F4R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F4R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F4R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F4R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F4R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F4R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F4R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F4R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F4R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F4R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F4R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F4R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F4R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F4R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F4R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F4R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F4R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F4R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F4R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F4R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define  CAN_F5R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F5R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F5R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F5R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F5R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F5R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F5R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F5R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F5R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F5R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F5R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F5R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F5R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F5R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F5R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F5R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F5R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F5R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F5R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F5R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F5R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F5R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F5R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F5R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F5R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F5R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F5R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F5R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F5R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F5R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F5R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F5R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define  CAN_F6R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F6R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F6R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F6R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F6R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F6R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F6R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F6R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F6R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F6R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F6R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F6R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F6R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F6R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F6R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F6R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F6R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F6R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F6R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F6R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F6R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F6R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F6R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F6R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F6R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F6R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F6R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F6R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F6R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F6R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F6R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F6R1_FB31                       (31U)        /* Filter bit 31 */


/*******************  Bit definition for CAN_F7R1 register  *******************/
#define  CAN_F7R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F7R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F7R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F7R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F7R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F7R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F7R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F7R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F7R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F7R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F7R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F7R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F7R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F7R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F7R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F7R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F7R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F7R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F7R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F7R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F7R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F7R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F7R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F7R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F7R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F7R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F7R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F7R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F7R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F7R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F7R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F7R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define  CAN_F8R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F8R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F8R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F8R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F8R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F8R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F8R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F8R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F8R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F8R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F8R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F8R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F8R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F8R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F8R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F8R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F8R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F8R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F8R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F8R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F8R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F8R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F8R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F8R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F8R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F8R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F8R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F8R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F8R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F8R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F8R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F8R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define  CAN_F9R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F9R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F9R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F9R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F9R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F9R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F9R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F9R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F9R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F9R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F9R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F9R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F9R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F9R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F9R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F9R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F9R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F9R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F9R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F9R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F9R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F9R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F9R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F9R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F9R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F9R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F9R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F9R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F9R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F9R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F9R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F9R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  *******************/
#define  CAN_F10R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F10R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F10R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F10R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F10R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F10R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F10R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F10R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F10R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F10R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F10R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F10R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F10R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F10R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F10R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F10R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F10R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F10R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F10R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F10R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F10R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F10R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F10R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F10R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F10R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F10R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F10R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F10R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F10R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F10R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F10R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F10R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  *******************/
#define  CAN_F11R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F11R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F11R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F11R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F11R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F11R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F11R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F11R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F11R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F11R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F11R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F11R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F11R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F11R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F11R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F11R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F11R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F11R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F11R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F11R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F11R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F11R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F11R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F11R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F11R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F11R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F11R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F11R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F11R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F11R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F11R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F11R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  *******************/
#define  CAN_F12R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F12R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F12R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F12R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F12R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F12R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F12R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F12R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F12R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F12R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F12R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F12R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F12R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F12R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F12R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F12R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F12R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F12R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F12R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F12R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F12R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F12R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F12R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F12R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F12R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F12R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F12R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F12R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F12R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F12R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F12R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F12R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  *******************/
#define  CAN_F13R1_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F13R1_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F13R1_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F13R1_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F13R1_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F13R1_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F13R1_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F13R1_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F13R1_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F13R1_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F13R1_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F13R1_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F13R1_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F13R1_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F13R1_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F13R1_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F13R1_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F13R1_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F13R1_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F13R1_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F13R1_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F13R1_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F13R1_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F13R1_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F13R1_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F13R1_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F13R1_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F13R1_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F13R1_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F13R1_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F13R1_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F13R1_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define  CAN_F0R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F0R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F0R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F0R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F0R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F0R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F0R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F0R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F0R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F0R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F0R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F0R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F0R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F0R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F0R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F0R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F0R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F0R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F0R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F0R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F0R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F0R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F0R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F0R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F0R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F0R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F0R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F0R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F0R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F0R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F0R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F0R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define  CAN_F1R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F1R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F1R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F1R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F1R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F1R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F1R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F1R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F1R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F1R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F1R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F1R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F1R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F1R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F1R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F1R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F1R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F1R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F1R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F1R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F1R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F1R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F1R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F1R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F1R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F1R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F1R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F1R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F1R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F1R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F1R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F1R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define  CAN_F2R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F2R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F2R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F2R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F2R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F2R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F2R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F2R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F2R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F2R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F2R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F2R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F2R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F2R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F2R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F2R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F2R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F2R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F2R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F2R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F2R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F2R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F2R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F2R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F2R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F2R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F2R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F2R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F2R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F2R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F2R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F2R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define  CAN_F3R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F3R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F3R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F3R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F3R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F3R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F3R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F3R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F3R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F3R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F3R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F3R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F3R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F3R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F3R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F3R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F3R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F3R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F3R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F3R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F3R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F3R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F3R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F3R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F3R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F3R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F3R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F3R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F3R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F3R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F3R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F3R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define  CAN_F4R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F4R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F4R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F4R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F4R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F4R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F4R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F4R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F4R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F4R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F4R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F4R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F4R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F4R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F4R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F4R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F4R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F4R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F4R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F4R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F4R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F4R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F4R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F4R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F4R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F4R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F4R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F4R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F4R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F4R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F4R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F4R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define  CAN_F5R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F5R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F5R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F5R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F5R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F5R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F5R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F5R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F5R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F5R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F5R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F5R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F5R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F5R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F5R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F5R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F5R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F5R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F5R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F5R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F5R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F5R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F5R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F5R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F5R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F5R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F5R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F5R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F5R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F5R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F5R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F5R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define  CAN_F6R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F6R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F6R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F6R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F6R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F6R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F6R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F6R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F6R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F6R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F6R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F6R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F6R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F6R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F6R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F6R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F6R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F6R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F6R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F6R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F6R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F6R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F6R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F6R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F6R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F6R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F6R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F6R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F6R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F6R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F6R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F6R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define  CAN_F7R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F7R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F7R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F7R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F7R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F7R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F7R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F7R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F7R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F7R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F7R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F7R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F7R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F7R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F7R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F7R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F7R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F7R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F7R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F7R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F7R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F7R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F7R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F7R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F7R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F7R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F7R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F7R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F7R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F7R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F7R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F7R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define  CAN_F8R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F8R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F8R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F8R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F8R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F8R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F8R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F8R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F8R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F8R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F8R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F8R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F8R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F8R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F8R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F8R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F8R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F8R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F8R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F8R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F8R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F8R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F8R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F8R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F8R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F8R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F8R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F8R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F8R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F8R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F8R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F8R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define  CAN_F9R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F9R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F9R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F9R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F9R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F9R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F9R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F9R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F9R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F9R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F9R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F9R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F9R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F9R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F9R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F9R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F9R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F9R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F9R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F9R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F9R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F9R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F9R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F9R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F9R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F9R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F9R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F9R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F9R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F9R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F9R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F9R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  *******************/
#define  CAN_F10R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F10R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F10R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F10R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F10R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F10R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F10R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F10R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F10R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F10R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F10R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F10R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F10R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F10R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F10R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F10R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F10R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F10R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F10R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F10R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F10R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F10R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F10R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F10R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F10R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F10R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F10R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F10R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F10R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F10R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F10R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F10R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  *******************/
#define  CAN_F11R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F11R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F11R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F11R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F11R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F11R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F11R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F11R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F11R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F11R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F11R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F11R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F11R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F11R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F11R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F11R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F11R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F11R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F11R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F11R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F11R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F11R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F11R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F11R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F11R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F11R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F11R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F11R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F11R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F11R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F11R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F11R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  *******************/
#define  CAN_F12R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F12R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F12R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F12R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F12R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F12R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F12R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F12R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F12R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F12R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F12R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F12R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F12R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F12R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F12R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F12R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F12R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F12R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F12R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F12R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F12R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F12R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F12R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F12R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F12R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F12R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F12R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F12R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F12R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F12R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F12R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F12R2_FB31                       (31U)        /* Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  *******************/
#define  CAN_F13R2_FB0                        (0U)         /* Filter bit 0 */
#define  CAN_F13R2_FB1                        (1U)         /* Filter bit 1 */
#define  CAN_F13R2_FB2                        (2U)         /* Filter bit 2 */
#define  CAN_F13R2_FB3                        (3U)         /* Filter bit 3 */
#define  CAN_F13R2_FB4                        (4U)         /* Filter bit 4 */
#define  CAN_F13R2_FB5                        (5U)         /* Filter bit 5 */
#define  CAN_F13R2_FB6                        (6U)         /* Filter bit 6 */
#define  CAN_F13R2_FB7                        (7U)         /* Filter bit 7 */
#define  CAN_F13R2_FB8                        (8U)         /* Filter bit 8 */
#define  CAN_F13R2_FB9                        (9U)         /* Filter bit 9 */
#define  CAN_F13R2_FB10                       (10U)        /* Filter bit 10 */
#define  CAN_F13R2_FB11                       (11U)        /* Filter bit 11 */
#define  CAN_F13R2_FB12                       (12U)        /* Filter bit 12 */
#define  CAN_F13R2_FB13                       (13U)        /* Filter bit 13 */
#define  CAN_F13R2_FB14                       (14U)        /* Filter bit 14 */
#define  CAN_F13R2_FB15                       (15U)        /* Filter bit 15 */
#define  CAN_F13R2_FB16                       (16U)        /* Filter bit 16 */
#define  CAN_F13R2_FB17                       (17U)        /* Filter bit 17 */
#define  CAN_F13R2_FB18                       (18U)        /* Filter bit 18 */
#define  CAN_F13R2_FB19                       (19U)        /* Filter bit 19 */
#define  CAN_F13R2_FB20                       (20U)        /* Filter bit 20 */
#define  CAN_F13R2_FB21                       (21U)        /* Filter bit 21 */
#define  CAN_F13R2_FB22                       (22U)        /* Filter bit 22 */
#define  CAN_F13R2_FB23                       (23U)        /* Filter bit 23 */
#define  CAN_F13R2_FB24                       (24U)        /* Filter bit 24 */
#define  CAN_F13R2_FB25                       (25U)        /* Filter bit 25 */
#define  CAN_F13R2_FB26                       (26U)        /* Filter bit 26 */
#define  CAN_F13R2_FB27                       (27U)        /* Filter bit 27 */
#define  CAN_F13R2_FB28                       (28U)        /* Filter bit 28 */
#define  CAN_F13R2_FB29                       (29U)        /* Filter bit 29 */
#define  CAN_F13R2_FB30                       (30U)        /* Filter bit 30 */
#define  CAN_F13R2_FB31                       (31U)        /* Filter bit 31 */

#endif /* CAN_REGS */