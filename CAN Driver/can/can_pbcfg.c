 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: CAN_PBcfg.c
 *
 * Description: Post Build Configuration Source file for STM32F405RG Microcontroller - CAN Driver
 *
 * Author: Fayrouz Bakr & kareem Mohamed
 ******************************************************************************/

#include "can.h"

/*
 * Module Version 1.0.0
 */
#define CAN_PBCFG_SW_MAJOR_VERSION              (1U)
#define CAN_PBCFG_SW_MINOR_VERSION              (0U)
#define CAN_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.0
 */
#define CAN_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define CAN_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define CAN_PBCFG_AR_RELEASE_PATCH_VERSION     (0U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((CAN_PBCFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_PBCFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_PBCFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((CAN_PBCFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
 ||  (CAN_PBCFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
 ||  (CAN_PBCFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

 