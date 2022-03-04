/******************************************************************************
 *
 * Module: flash memory
 *
 * File Name: fls.h
 *
 * Description: Header file for STM32F405RG Microcontroller - Flash memory Driver
 *
 * Author: Karim Mohamed Amin
 ******************************************************************************/
#ifndef FLS_H
#define FLS_H
/* my company id */
#define FLS_VENDOR_ID                  (2000U)

/* the FLS driver id in software module doc*/
#define FLS_MODULE_ID                  (92U)

/* FLS Instance Id */
#define FLS_INSTANCE_ID                (0U)

/*
 * Module Version 1.0.0
 */
#define FLS_SW_MAJOR_VERSION           (1U)
#define FLS_SW_MINOR_VERSION           (0U)
#define FLS_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define FLS_AR_RELEASE_MAJOR_VERSION   (4U)
#define FLS_AR_RELEASE_MINOR_VERSION   (0U)
#define FLS_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for FLS Status
 */
#define FLS_INITIALIZED                (1U)
#define FLS_NOT_INITIALIZED            (0U)

/*
 * Include the standard AUTOSAR types std_types.h file
 */
#include "Std_Types.h"
#include "Cpu.h"
/*
 * check that the two files from the same software version and AUTOSAR verion
 */

#if ((FLS_SW_MAJOR_VERSION != STD_TYPES_SW_MAJOR_VERSION)\
 ||  (FLS_SW_MINOR_VERSION != STD_TYPES_SW_MINOR_VERSION)\
 ||  (FLS_SW_PATCH_VERSION != STD_TYPES_SW_PATCH_VERSION))

  #error "Incompatable Software versions between fls.h and Std_Types.h";
#endif
   
 /*
 * check that the two files from the same AUTOSAR version 
 */

#if ((FLS_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
   ||(FLS_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
   ||(FLS_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))

  #error "Incompatable AUTOSAR versions between fls.h and Std_Types.h";
#endif
   
/* Port Pre-Compile Configuration Header file */
#include "fls_Cfg.h"

/* AUTOSAR Version checking between fls_Cfg.h and fls.h files */
#if ((FLS_CFG_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION)\
 ||  (FLS_CFG_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION)\
 ||  (FLS_CFG_AR_RELEASE_PATCH_VERSION != FLS_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of fls_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((FLS_CFG_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION)\
 ||  (FLS_CFG_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION)\
 ||  (FLS_CFG_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

 /* include non-AUTOSAR file so we do not have to check the version */
#include "Common_Macros.h"

/******************************************************************************
 *                         Constants Definitions                              *
*******************************************************************************/
#define FLS_BIT_NUMBER_0                (0U)
#define FLS_BIT_NUMBER_1                (1U)
#define FLS_BIT_NUMBER_2                (2U)
#define FLS_BIT_NUMBER_3                (3U)
#define FLS_BIT_NUMBER_4                (4U)
#define FLS_BIT_NUMBER_5                (5U)
#define FLS_BIT_NUMBER_6                (6U)
#define FLS_BIT_NUMBER_7                (7U)
#define FLS_BIT_NUMBER_8                (8U)
#define FLS_BIT_NUMBER_9                (9U)
#define FLS_BIT_NUMBER_10               (10U)
#define FLS_BIT_NUMBER_11               (11U)
#define FLS_BIT_NUMBER_12               (12U)
#define FLS_BIT_NUMBER_13               (13U)
#define FLS_BIT_NUMBER_14               (14U)
#define FLS_BIT_NUMBER_15               (15U)
#define FLS_BIT_NUMBER_16               (16U)
#define FLS_BIT_NUMBER_17               (17U)
#define FLS_BIT_NUMBER_18               (18U)
#define FLS_BIT_NUMBER_19               (19U)
#define FLS_BIT_NUMBER_20               (20U)
#define FLS_BIT_NUMBER_21               (21U)
#define FLS_BIT_NUMBER_22               (22U)
#define FLS_BIT_NUMBER_23               (23U)
#define FLS_BIT_NUMBER_24               (24U)
#define FLS_BIT_NUMBER_25               (25U)
#define FLS_BIT_NUMBER_26               (26U)
#define FLS_BIT_NUMBER_27               (27U)
#define FLS_BIT_NUMBER_28               (28U)
#define FLS_BIT_NUMBER_29               (29U)
#define FLS_BIT_NUMBER_30               (30U)
#define FLS_BIT_NUMBER_31               (31U)
#define FLS_MAX_CALL_CYCLE              (1U)
#define FLS_INTERRUPT_ENABLE_MASK       (0x03000000)
#define FLS_WRITE_PROTECTION_MASK       (0xF000FFFF)
#define FLS_READ_PROTECTION_MASK        (0xFFFF00FF)
#define FLS_ACR_MASK                    (0xFFFFFFF8)
#define FLS_BOR_LEVEL_MASK              (0xFFFFFFF3)
#define FLS_CR_SNB_MASK                 (0xFFFFFF87)
#define FLS_UNLOCK_CR_KEY1              (0x45670123)
#define FLS_UNLOCK_CR_KEY2              (0xCDEF89AB)
#define FLS_UNLOCK_OPTION_CR_KEY1       (0x08192A3B)
#define FLS_UNLOCK_OPTION_CR_KEY2       (0x4C5D6E7F)
#define FLS_ERASED_FLASH_CELL           (0xFFFFFFFF)
#define FLS_OPERATION_ZERO_LENGTH       (0U)
#define FLS_ZERO_VALUE                  (0U)
#define FLS_TWO_BYTES                   (2U)
#define FLS_FOUR_BYTES                  (4U)
#define FLS_EIGHT_BYTES                 (8U)
/******************************************************************************
 *                      API Service Id Macros                                 *
*******************************************************************************/
#define FLS_INIT_SID                    (0x00)
#define FLS_ERASE_SID                   (0x01)
#define FLS_WRITE_SID                   (0x02)
#define FLS_CANCEL_SID                  (0x03)
#define FLS_GET_STATUS_SID              (0x04)
#define FLS_GET_JOB_RESULT_SID          (0x05)
#define FLS_MAIN_FUNCTION_SID           (0x06)
#define FLS_READ_SID                    (0x07)
#define FLS_COMPARE_SID                 (0x08)
#define FLS_SET_MODE_SID                (0x09)
#define FLS_GET_VERSION_INFO_SID        (0x10)
/*******************************************************************************
 *                      DET Error Codes                                        *
********************************************************************************/
#define FLS_E_PARAM_CONFIG              (0x01)
#define FLS_E_PARAM_ADDRESS             (0x02)
#define FLS_E_PARAM_LENGTH              (0x03)
#define FLS_E_PARAM_DATA                (0x04)
#define FLS_E_UNINIT                    (0x05)
#define FLS_E_BUSY                      (0x06)
#define FLS_E_VERIFY_ERASE_FAILED       (0x07)
#define FLS_E_VERIFY_WRITE_FAILED       (0x08)
#define FLS_E_TIMEOUT                   (0x09)
#define FLS_E_PARAM_POINTER             (0x0A)
/*******************************************************************************
 *                        Types Definitions                                    *
********************************************************************************/

/* Used as address offset from the configured flash base address to access a certain flash memory area. */
typedef uint32          Fls_AddressType;
/* Specifies the number of bytes to read/write/erase/compare.  */
typedef uint32          Fls_LengthType;
/* Specifies the kind of operation to the flash module`s Main function */
typedef enum{
  /* When no operation is initiated */
  NO_OPERATION,
  /* When read operation is initiated */
  READ_OPERATION,
  /* When write operation is initiated */
  WRITE_OPERATION,
  /* When erase operation is initiated */
  ERASE_OPERATION,
  /* When compare operation is initiated */
  COMPARE_OPERATION
}FLS_Kind_of_operation;
/*******************************************************************************
 *                        Configuration Definitions                            *
********************************************************************************/
/* this is relation between the voltage range and cpu frequency (Data sheet page 80)*/
typedef enum{
  zero_ws,
  one_ws,
  two_ws,
  three_ws,
  four_ws,
  five_ws,
  six_ws,
  seven_ws
}Latancy_Type;

/* select this parallelism based on voltage range you use  (Data sheet page 85)*/
typedef enum{
  x8_psize,
  
  x16_psize,
  
  x32_psize,
  
  x64_psize
}parallelism_Type;
/*
 * Level 0 => read protection is not active 
 * Level 1 => read protection of memories active
 * Level 2 => chip read protection active
 */
typedef enum{
  read_level_0 = 0xAA,
  read_level_1 = 0x00,
  read_level_2 = 0xCC
}Read_protection_Type;
/*
 * BOR ( Brownout threshold level )=> These bits contain the supply level threshold that activates/releases the reset
 * 00: BOR Level 3 (VBOR3), brownout threshold level 3
 * 01: BOR Level 2 (VBOR2), brownout threshold level 2
 * 10: BOR Level 1 (VBOR1), brownout threshold level 1
 * 11: BOR off, POR/PDR reset threshold level is applied
 */
typedef enum{
  BOR_level_3,
  BOR_level_2,
  BOR_level_1,
  BOR_off
}BOR_Level_Type;
/* this struct for initializing the flash memory */
typedef struct{
  /* flash speed of operations */
  Latancy_Type          fls_latancy;
  parallelism_Type      fls_p_size;
  /* user option bytes */
  BOR_Level_Type        fls_BOR_level;
  /* Cycle time of calls of the flash driver's main function (in seconds ) range : 0 -> 1 */
  float32               fls_call_cycle;
  /* This parameter is the default FLS device mode after initialization */
  MemIf_ModeType        fls_default_mode;
  /* The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in fast mode.  */
  Fls_LengthType        fls_max_read_fast_mode;
  /* The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in normal mode.  */
  Fls_LengthType        fls_max_read_normal_mode;
  /* The maximum number of bytes to write in one cycle of the flash driver's job processing function in fast mode.  */
  Fls_LengthType        fls_max_write_fast_mode;
  /* The maximum number of bytes to write in one cycle of the flash driver's job processing function in normal mode.  */
  Fls_LengthType        fls_max_write_normal_mode;
  /* flash memory protection */
  Read_protection_Type  fls_read_protection;    
  boolean               fls_write_protection_enable;
  /* caching and prefetch feature */
  boolean               fls_data_cache_enable;
  boolean               fls_instruction_cache_enable;
  boolean               fls_prefetch_enable;
  /* Pointer to call back notification functions  */
  void (*Fee_JobEndNotification_ptr)(void);
  void (*Fee_JobErrorNotification_ptr)(void);
}Fls_configType;

/*******************************************************************************
 *                        Function Prototype                                   *
********************************************************************************/
/*******************************************************************************
 *                        Helper Functions Prototype                           *
********************************************************************************/

/*******************************************************************************
 * Description : Compares the contents of the source address and target data buffer  
 * Returns : None  
 *******************************************************************************/
void Helper_Compare_Task_Cycle(uint32* Source_Buffer , uint32* Taregt_Buffer);

/*******************************************************************************
 * Description : compares the content of  flash memory location  and constant value passed as a parameter .
 * Returns : TRUE -> if the content is equal to constant 
 *           FALSE -> if the content is not equal to constant 
 *******************************************************************************/
boolean Helper_verify (Fls_AddressType* location_ptr , uint32 compared_value);

/*******************************************************************************
 * Description : Writes the data From the source buffer to target buffer untill the max number of Bytes 
 * Returns : None
 *           
 ******************************************************************************/
void Helper_Write_Task_Cycle(uint8* Source_Buffer , uint8* Taregt_Buffer);

/*******************************************************************************
 * Description : Reads the data From the source Address to target data buffer untill the max number of Bytes 
 * Returns : None  
 *******************************************************************************/
void Helper_Read_Task_Cycle(uint32* Source_Buffer , uint32* Taregt_Buffer);

/*******************************************************************************
 * Description : erases one sector from the flash memory  
 * Returns : None          
 *******************************************************************************/
void Helper_Erase_Task_Cycle(void);

/*******************************************************************************
 *                        AUTOSAR Function Prototype                           *
********************************************************************************/
/*******************************************************************************
* Service Name: Fls_Init
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration struct
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: initilaze the flash memory driver module
********************************************************************************/
void Fls_Init( const Fls_configType  * config_ptr);

/*******************************************************************************
* Service Name: Fls_Erase
* Sync/Async: ASynchronous
* Reentrancy: Non-reentrant
* Parameters (in): TargetAdderss - Target address in flash memory. This address offset will be added to the flash memory base address.
*                  Length - Number of bytes to erase
* Parameters (inout): None
* Parameters (out): None
* Return value:  E_OK: erase command has been accepted 
*                E_NOT_OK: erase command has not been accepted
* Description: Erases flash sector(s).
********************************************************************************/
Std_ReturnType Fls_Erase(
                         Fls_AddressType TargetAdderss,
                         Fls_LengthType  Length
                                                      );

/*******************************************************************************
* Service Name: Fls_Write
* Sync/Async: ASynchronous
* Reentrancy: Non-reentrant
* Parameters (in): TargetAdderss => Target address in flash memory. This address offset will be added to the flash memory base address.
*                  SourceAddressPtr => Pointer to source data buffer.
*                  Length => Number of bytes to erase.
* Parameters (inout): None
* Parameters (out): None
* Return value:  E_OK: write command has been accepted 
*                E_NOT_OK: write command has not been accepted
* Description: Writes one or more complete flash pages.
********************************************************************************/
Std_ReturnType Fls_Write(
                         Fls_AddressType TargetAdderss,
                         const uint8* SourceAddressPtr,
                         Fls_LengthType  Length
                                                      );

/* Check if the user configured this api on or off*/
#if ( FLS_CANCEL_API == STD_ON)
/*******************************************************************************
* Service Name: Fls_Cancel
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: cancels an ongoing job 
********************************************************************************/
void Fls_Cancel( void );

#endif

/* Check if the user configured this api on or off*/
#if ( FLS_GET_STATUS_API == STD_ON)
/*******************************************************************************
* Service Name: Fls_GetStatus
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: MemIf_StatusType
* Description: returns the driver state
********************************************************************************/
MemIf_StatusType Fls_GetStatus( void );

#endif

/* Check if the user configured this api on or off*/
#if ( FLS_GET_JOB_RESULT_API == STD_ON)
/*******************************************************************************
* Service Name: Fls_GetJobResult
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: MemIf_JobResultType
* Description: returns the Result of the last job 
********************************************************************************/
MemIf_JobResultType Fls_GetJobResult( void );

#endif

/*******************************************************************************
* Service Name: Fls_Read
* Sync/Async: ASynchronous
* Reentrancy: Non-reentrant
* Parameters (in): SourceAdderss => Source address in flash memory. This address offset will be added to the flash memory base address
*                  TargetAddressPtr => Pointer to Target data buffer.
*                  Length => Number of bytes to Read.
*
* Parameters (inout): None
* Parameters (out): TargetAddressPtr => Pointer to Target data buffer.
*
* Return value:  E_OK: read command has been accepted 
*                E_NOT_OK: read command has not been accepted
* Description: Reads from the flash memory.
********************************************************************************/
Std_ReturnType Fls_Read(
                         Fls_AddressType SourceAdderss,
                         uint8* TargetAddressPtr,
                         Fls_LengthType  Length
                                                      );
/* Check if the user configured this api on or off*/
#if ( FLS_COMPARE_API == STD_ON)
/*******************************************************************************
* Service Name: Fls_Compare
* Sync/Async: ASynchronous
* Reentrancy: Non-reentrant
* Parameters (in): SourceAdderss => Source address in flash memory. This address offset will be added to the flash memory base address
*                  TargetAddressPtr => Pointer to Target data buffer.
*                  Length => Number of bytes to Read.
*
* Parameters (inout): None
* Parameters (out): None
*
* Return value:  E_OK: read command has been accepted 
*                E_NOT_OK: read command has not been accepted
*
* Description: Compares the contents of an area of flash memory with that of an application data buffer.
********************************************************************************/
Std_ReturnType Fls_Compare(
                         Fls_AddressType SourceAdderss,
                         const uint8* TargetAddressPtr,
                         Fls_LengthType  Length
                                                      );
#endif

/* Check if the user configured this api on or off*/
#if ( FLS_SET_MODE_API == STD_ON)
/*******************************************************************************
* Service Name: Fls_SetMode
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Mode => MEMIF_MODE_SLOW: Slow read access / normal SPI access. 
*                          MEMIF_MODE_FAST: Fast read access / SPI burst access. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: returns the driver state
********************************************************************************/
void Fls_SetMode( MemIf_ModeType Mode);

#endif  

/* Check if the user configured this api on or off*/
#if ( FLS_VERSION_INFO_API == STD_ON)
/*******************************************************************************
* Service Name: Fls_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfoPtr => Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module. 
********************************************************************************/
void Fls_GetVersionInfo( Std_VersionInfoType* versioninfoPtr );

#endif 

/*******************************************************************************
* Service Name: Fls_MainFunction
* Timing : Fixed_cyclic
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Performs the proccessing of jobs
********************************************************************************/
void Fls_MainFunction( void );

/* Extern PB structures to be used by fls and other modules */
extern const  Fls_configType  fls_configuration;
#endif /* FLS_H */