 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for STM32F405RG Micro-controller - Port Driver
 *
 * Author: Boules Rufael
 *
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)


/*
 * AUTOSAR Version R21.11.0
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (21U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (11U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (0U)



/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT				(STD_OFF)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API				(STD_ON)

/* Pre-compile option for Compensation cell Enabling */
#define PORT_COMPENSATION_CELL				(STD_OFF)

/* pre-compile option for PORT SET PIN DIRECTION API */
#define PORT_SET_PIN_DIRECTION_API			(STD_ON)



#endif /* PORT_CFG_H */
