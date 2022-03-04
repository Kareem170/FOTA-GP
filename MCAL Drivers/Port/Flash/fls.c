/******************************************************************************
 *
 * Module: flash memory
 *
 * File Name: fls.c
 *
 * Description: Source file for STM32F405RG Microcontroller - Flash memory Driver
 *
 * Author: Karim Mohamed Amin
 ******************************************************************************/
#include "fls.h"
#include "fls_reg.h"

/* check as it is optional feature */
#if (FLS_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and flash Modules */
#if ((DET_AR_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != FLS_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of fls.h does not match the expected version"
#endif

#endif

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I");

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")
/******************************************************************************
 *                      Private Global variable                               *
******************************************************************************/
/* To Be able to track the module status */
STATIC MemIf_StatusType g_Flash_Status = MEMIF_UNINIT;

/* To Be able to track the module Mode */
STATIC MemIf_ModeType g_Flash_Mode;

/* To Be able to track the result of initiated task  */
STATIC MemIf_JobResultType g_Flash_Job_Result ;

/* To Hold the result of the last job in the flash module */
STATIC MemIf_JobResultType g_Flash_Last_Job_Result ;

/* To Store the configuration set if wanted in run time */
STATIC const Fls_configType* g_Fls_config_ptr = NULL_PTR;

/* To make the main function Know the type of operation */
FLS_Kind_of_operation g_Fls_operation_type = NO_OPERATION;

/* module internal variables To hold the data of the initiated task */
STATIC Fls_AddressType g_TargetAdderss;
STATIC Fls_AddressType g_SourceAdderss;
STATIC  const uint8* g_SourceAdderss_ptr = NULL_PTR;
STATIC  uint8* g_TargetAdderss_ptr = NULL_PTR;
STATIC Fls_LengthType  g_Length;
/* To hold the max number of bytes based on the module operation mode*/
 Fls_LengthType g_max_bytes = FLS_ZERO_VALUE;
/* To Hold the first sector number and number of sectors which included in the operation*/
STATIC uint8  g_First_Sector_number;
STATIC uint8  g_number_of_sectors = FLS_ZERO_VALUE;
/******************************************************************************
 *                      Helper Functions  Definitions                         *
*******************************************************************************/

/*******************************************************************************
 * Description : Compares the contents of the source address and target data buffer  
 * Returns : None  
 *******************************************************************************/
void Helper_Compare_Task_Cycle(uint32* Source_Buffer , uint32* Taregt_Buffer)
{
  /* To hold the numer of processing bytes to compare with the max. */
  Fls_LengthType processed_bytes = FLS_ZERO_VALUE;
  /* To hold the offest number in the target data buffer and maintain its previous value */
  STATIC uint32 data_offest = FLS_ZERO_VALUE;
  /* this flag will be raised whenever Memory location not equal the location in the data buffer */
  boolean Not_Equal_Flag = FALSE;
  /* Do not end the cycle untill handling the max number of bytes */
   while( (processed_bytes < g_max_bytes) && ( g_Length > FLS_ZERO_VALUE)){
     
    if( *(Source_Buffer+data_offest) != *(Taregt_Buffer+data_offest))
    {
      /* Rias the Flag */
      Not_Equal_Flag = TRUE;
      break;
    }
    /* increment the number of bytes by four as i access four bytes at a Time */
    processed_bytes += FLS_FOUR_BYTES;
    /* increment the data offest to get the next location */
    data_offest++;
    /* decrement the number of bytes by four as i access four bytes at a Time */
    g_Length -= FLS_FOUR_BYTES;
   }
   /* Check the flag */
   if( Not_Equal_Flag == TRUE)
   {
     /* reset the offest variable */
     data_offest = FLS_ZERO_VALUE;
     /* Set the job Result to inconsistent */
     g_Flash_Job_Result = MEMIF_BLOCK_INCONSISTENT;
     g_Flash_Status = MEMIF_IDLE;
     /* Store the job Result After finishing the task */
     g_Flash_Last_Job_Result = g_Flash_Job_Result;
     /* Call Error End notification Function in the configuration structure */
     g_Fls_config_ptr->Fee_JobErrorNotification_ptr();
   }
   /* Check if the Compare Task is Finished */
   if((g_Length == FLS_ZERO_VALUE) && (g_Flash_Job_Result == MEMIF_JOB_PENDING) && (Not_Equal_Flag == FALSE) )
   {
     /* reset the offest variable */
     data_offest = FLS_ZERO_VALUE;
     g_Flash_Job_Result = MEMIF_JOB_OK;
     g_Flash_Status = MEMIF_IDLE;
     /* Store the job Result After finishing the task */
     g_Flash_Last_Job_Result = g_Flash_Job_Result;
     /* Call Job End notification Function in the configuration structure */
     g_Fls_config_ptr->Fee_JobEndNotification_ptr();
   }
    
}

/*
 * Description : compares the content of  flash memory location  and constant value passed as a parameter .
 * Returns : TRUE -> if the content is equal to constant 
 *           FALSE -> if the content is not equal to constant 
 */
boolean Helper_verify (Fls_AddressType* location_ptr , uint32 compared_value)
{
  if(*location_ptr == compared_value)
  {
    return TRUE;
  }
  return FALSE;
}

/*
 * Description : erases one sector from the flash memory  
 * Returns : None
 *           
 */
void Helper_Erase_Task_Cycle(void)
{
  /* this variable will be initialized once by to be add to the first sector number and used in erase task */
  STATIC uint8 sector_offest = FLS_ZERO_VALUE;
  /* Check that there are sectors to erase */
  if(g_number_of_sectors != FLS_ZERO_VALUE)
  {
     /* check if the flash module not busy By Check the bit number 16 (BSY BIT) in the status register */
     while(BIT_IS_SET(FLASH->SR , FLS_BIT_NUMBER_16));
          
     /* UNLOCK the flash control register by put in the flash key register two magic numbers
      * 1=> KEY1 = 0x45670123
      * 2=> KEY2 = 0xCDEF89AB
      */
     FLASH->KEYR = FLS_UNLOCK_CR_KEY1;
     FLASH->KEYR = FLS_UNLOCK_CR_KEY2;
       
      /* Select the sector number to erase */
      /* 
       * 1) clear the bits [6:3] which is SNB (sector number).
       * 2) add first sector number to sector offest to get the sector number .
       * 3) shift left by 3 as it is the start bit number of SNB bits .
       */
      FLASH->CR = (FLASH->CR & FLS_CR_SNB_MASK) | ((g_First_Sector_number + sector_offest) << FLS_BIT_NUMBER_3);
         
      /* set the bit SER (sector erase ) which is bit number 1*/
      SET_BIT(FLASH->CR,FLS_BIT_NUMBER_1);
          
      /* Set the start bit to start the operation which is bit number 16 */
      SET_BIT(FLASH->CR,FLS_BIT_NUMBER_16);
          
      /* Lock again the control register for security (LOCK bit in 31 position) */
      SET_BIT(FLASH->CR , FLS_BIT_NUMBER_31);
      /* incerment the offest var. */
      sector_offest++;
      /* decrement the number of sectors by one */
      g_number_of_sectors--;
   }
      /* Check that if the erase task is finished */
   if( (g_number_of_sectors == FLS_ZERO_VALUE) && (g_Flash_Job_Result == MEMIF_JOB_PENDING) )
   {
      /* reset the value of the variable for future use */
      sector_offest = FLS_ZERO_VALUE;
      /* IF the Dev error enable Check by reading the target address and it must equal to flash erased cell (0xFFFFFFFF)*/
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Check if the content of the target address is not equal to erased flash cell*/
        if(! Helper_verify( (Fls_AddressType*) (g_TargetAdderss + FLS_BASE_ADDRESS) ,FLS_ERASED_FLASH_CELL))
        {
           g_Flash_Job_Result = MEMIF_JOB_FAILED;
           /* Call Error End notification Function in the configuration structure */
           g_Fls_config_ptr->Fee_JobErrorNotification_ptr();
           /* Report dev error if the erase job failed  */
           Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_MAIN_FUNCTION_SID , FLS_E_VERIFY_ERASE_FAILED);
           /* exit the function */
           return;
         }
         else  
      #endif
         {
           g_Flash_Job_Result = MEMIF_JOB_OK;
         }
           g_Flash_Status = MEMIF_IDLE;
            
           /* Store the job Result After finishing the task */
           g_Flash_Last_Job_Result = g_Flash_Job_Result;
            
          /* Call Job End notification Function in the configuration structure */
          g_Fls_config_ptr->Fee_JobEndNotification_ptr();
        }
  
}

/******************************************************************************************************
 * Description : Reads the data From the source Address to target data buffer untill the max number of Bytes 
 * Returns : None  
 ******************************************************************************************************/
void Helper_Read_Task_Cycle(uint32* Source_Buffer , uint32* Taregt_Buffer)
{
  /* To hold the numer of processing bytes to compare with the max. */
  Fls_LengthType processed_bytes = FLS_ZERO_VALUE;
  /* To hold the offest number in the target data buffer and maintain its previous value */
  STATIC uint32 data_offest = FLS_ZERO_VALUE;
  /* Do not end the cycle untill handling the max number of bytes */
   while( (processed_bytes < g_max_bytes) && ( g_Length > FLS_ZERO_VALUE)){
    
        /* cast the source address to pointer to long to access four bytes */
         *((uint32*)Taregt_Buffer + data_offest)  = *((uint32*)Source_Buffer + data_offest); 
        /* increment the number of bytes by four as i access four bytes at a Time */
         processed_bytes += FLS_FOUR_BYTES;
        /* increment the data offest to get the next location */
         data_offest++;
        /* decrement the number of bytes by four as i access four bytes at a Time */
         g_Length -= FLS_FOUR_BYTES;
   }
   /* Check if the Read Task is Finished */
   if((g_Length == FLS_ZERO_VALUE) && (g_Flash_Job_Result == MEMIF_JOB_PENDING) )
   {
     /* reset the offest variable */
     data_offest = FLS_ZERO_VALUE;
     g_Flash_Job_Result = MEMIF_JOB_OK;
     g_Flash_Status = MEMIF_IDLE;
     /* Store the job Result After finishing the task */
     g_Flash_Last_Job_Result = g_Flash_Job_Result;
     /* Call Job End notification Function in the configuration structure */
     g_Fls_config_ptr->Fee_JobEndNotification_ptr();
   }
  
}

/*
 * Description : Writes the data From the source buffer to target buffer untill the max number of Bytes 
 * Returns : None
 *           
 */
void Helper_Write_Task_Cycle(uint8* Source_Buffer , uint8* Taregt_Buffer)
{
  /* To hold the numer of processing bytes to compare with the max. */
  Fls_LengthType processed_bytes = FLS_ZERO_VALUE;
  /* To hold the offest number in the target data buffer and maintain its previous value */
  STATIC uint32 data_offest = FLS_ZERO_VALUE;
  
  /*  Before writing a flash block, shall compare the contents of the addressed memory area against 
      the value of an erased flash cell to check that the block has been completely erased. */
   #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Check if the content of the target address is not equal to erased flash cell*/
      if(! Helper_verify(  (Fls_AddressType*)(g_TargetAdderss + FLS_BASE_ADDRESS ) + data_offest ,FLS_ERASED_FLASH_CELL))
      {
          g_Flash_Job_Result = MEMIF_JOB_FAILED;
          /* Call Error End notification Function in the configuration structure */
          g_Fls_config_ptr->Fee_JobErrorNotification_ptr();
          /* Store the job Result After finishing the task */
          g_Flash_Last_Job_Result = g_Flash_Job_Result;
          
          
          /* Report dev error if the erase job failed  */
          Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_MAIN_FUNCTION_SID , FLS_E_VERIFY_ERASE_FAILED);
          /* exit the function */
          return;
       }
    #endif
      
    /* UNLOCK the flash control register by put in the flash key register two magic numbers
     * 1=> KEY1 = 0x45670123
     * 2=> KEY2 = 0xCDEF89AB
     */
    FLASH->KEYR = FLS_UNLOCK_CR_KEY1;
    FLASH->KEYR = FLS_UNLOCK_CR_KEY2;
          
    /* Set the PG BIT (program) in the flash control register which bit number 0 */
    SET_BIT(FLASH->CR,FLS_BIT_NUMBER_0);
          
    /* Lock again the control register for security (LOCK bit in 31 position) */
    SET_BIT(FLASH->CR , FLS_BIT_NUMBER_31);
    
  /* Do not end the cycle untill handling the max number of bytes */
   while( (processed_bytes < g_max_bytes) && ( g_Length > FLS_ZERO_VALUE)){
     
        /* check if the flash module not busy By Check the bit number 16 (BSY BIT) in the status register */
        while(BIT_IS_SET(FLASH->SR , FLS_BIT_NUMBER_16));
        
        /* Check the parallelism */
        switch(g_Fls_config_ptr->fls_p_size)
        {
              case x8_psize :
                    /* cast the source address to pointer to char to access one byte */
                    *((uint8*)Taregt_Buffer + data_offest)  = *((uint8*)Source_Buffer + data_offest); 
                    /* increment the number of bytes by one as i access one byte at a Time */
                    processed_bytes++;
                    /* increment the data offest to get the next location */
                    data_offest++;
                    /* decrement the number of bytes by one as i access one byte at a Time */
                    g_Length--;
              break; 
                  
              case x16_psize : 
                    /* cast the source address to pointer to short to access two bytes */
                    *((uint16*)Taregt_Buffer + data_offest)  = *((uint16*)Source_Buffer + data_offest); 
                    /* increment the number of bytes by two as i access two bytes at a Time */
                    processed_bytes += FLS_TWO_BYTES;
                    /* increment the data offest to get the next location */
                    data_offest++;
                    /* decrement the number of bytes by two as i access two bytes at a Time */
                    g_Length -= FLS_TWO_BYTES;
              break; 
                  
              case x32_psize : 
                    /* cast the source address to pointer to long to access four bytes */
                    *((uint32*)Taregt_Buffer + data_offest)  = *((uint32*)Source_Buffer + data_offest); 
                    /* increment the number of bytes by four as i access four bytes at a Time */
                    processed_bytes += FLS_FOUR_BYTES;
                    /* increment the data offest to get the next location */
                    data_offest++;
                    /* decrement the number of bytes by four as i access four bytes at a Time */
                    g_Length -= FLS_FOUR_BYTES;
               break; 
                  
               case x64_psize : 
                    /* cast the source address to pointer to long to access eight bytes */
                    *((uint64*)Taregt_Buffer + data_offest)  = *((uint64*)Source_Buffer + data_offest); 
                    /* increment the number of bytes by eight as i access eight bytes at a Time */
                    processed_bytes += FLS_EIGHT_BYTES;
                    /* increment the data offest to get the next location */
                    data_offest++;
                    /* decrement the number of bytes by eight as i access eight bytes at a Time */
                    g_Length -= FLS_EIGHT_BYTES;
               break; 
           }
      }
   if((g_Length == FLS_ZERO_VALUE) && (g_Flash_Job_Result == MEMIF_JOB_PENDING) )
   {
     /* reset the offest variable */
     data_offest = FLS_ZERO_VALUE;
    
     g_Flash_Status = MEMIF_IDLE;
     
     /* After writing a flash block, compare the contents of the reprogrammed memory area against 
        the contents of the provided application buffer to check that the block has been completely reprogrammed*/
     #if (FLS_DEV_ERROR_DETECT == STD_ON)      
        /* Check if the content of the target address is equal to Reprogrammed buffer */
        if(! Helper_verify( (Fls_AddressType*) (g_TargetAdderss + FLS_BASE_ADDRESS) , *(Fls_AddressType*)g_SourceAdderss_ptr))
        {
              g_Flash_Job_Result = MEMIF_JOB_FAILED;
              /* Call Error End notification Function in the configuration structure */
              g_Fls_config_ptr->Fee_JobErrorNotification_ptr();
              /* Report dev error if the erase job failed  */
              Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_MAIN_FUNCTION_SID , FLS_E_VERIFY_WRITE_FAILED);
              
              /* exit the function */
              return;
         }
        else
      #endif
        {
            g_Flash_Job_Result = MEMIF_JOB_OK;
 
        }
        /* Store the job Result After finishing the task */
        g_Flash_Last_Job_Result = g_Flash_Job_Result;
        /* Call Job End notification Function in the configuration structure */
        g_Fls_config_ptr->Fee_JobEndNotification_ptr();
        
   }
}
/******************************************************************************
 *                      API Service Definitions                               *
******************************************************************************/

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
void Fls_Init( const Fls_configType  * config_ptr){
/* Check the development errors if enabled */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
  /* Check the content of the given configuration set to be valid  */
  if( (config_ptr->fls_call_cycle > FLS_MAX_CALL_CYCLE)\
     || (config_ptr->fls_p_size > x64_psize)\
     || (config_ptr->fls_BOR_level > BOR_off)\
     || (config_ptr->fls_latancy > seven_ws))
  {
    /* Report dev error if the contents are invalid */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_INIT_SID,FLS_E_PARAM_CONFIG);
  }else{
    /* Do nothing */
  }
  /* Check the flash module status */
  if(g_Flash_Status == MEMIF_BUSY )
  {
     /* Report dev error if the flash module status */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_INIT_SID,FLS_E_BUSY);
  }else{
    /* Do nothing */
  }
  
  /* Check if the pointer is null */
  if(config_ptr == NULL_PTR)
  {
    /* Report dev error if the config ptr is null */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_INIT_SID,FLS_E_PARAM_POINTER);
  }else
#endif  
  {
    g_Fls_config_ptr = config_ptr;
  }
  /* Insert in the access control register how many wait states */
  FLASH->ACR = (FLASH->ACR & FLS_ACR_MASK)|(config_ptr->fls_latancy);
  
  /* Configure the data and instruction caches and Prefetch */
  if( config_ptr->fls_data_cache_enable == TRUE){

  /* SET DCEN bit => BIT NUMBER 10 in ACR register */
  SET_BIT(FLASH->ACR,FLS_BIT_NUMBER_10);
  }
  else if( config_ptr->fls_data_cache_enable == FALSE)
  {
    
  /* CLEAR DCEN bit in ACR register */
  CLEAR_BIT(FLASH->ACR,FLS_BIT_NUMBER_10);
  }else{
    
    /*do nothing */ 
  }
  
   /* Configure the data and instruction caches and Prefetch */
  if( config_ptr->fls_instruction_cache_enable == TRUE){

  /* SET ICEN bit number 9 in ACR register */
  SET_BIT(FLASH->ACR,FLS_BIT_NUMBER_9);
  }
  else if( config_ptr->fls_data_cache_enable == FALSE)
  {
    
  /* CLEAR ICEN bit number 9 in ACR register */
  CLEAR_BIT(FLASH->ACR,FLS_BIT_NUMBER_9);
  }else{
    
    /*do nothing */ 
  }
  
   /* Configure the data and instruction caches and Prefetch */
  if( config_ptr->fls_prefetch_enable == TRUE){

  /* SET PRFTEN bit number 8 in ACR register */
  SET_BIT(FLASH->ACR,FLS_BIT_NUMBER_8);
  }
  else if( config_ptr->fls_data_cache_enable == FALSE)
  {
    
  /* CLEAR PRFTEN bit number 8 in ACR register */
  CLEAR_BIT(FLASH->ACR,FLS_BIT_NUMBER_8);
  }else{
    
    /*do nothing */ 
  }
  /* UNLOCK the flash control register by put in the flash key register two magic numbers
   * 1=> KEY1 = 0x45670123
   * 2=> KEY2 = 0xCDEF89AB
   */
  FLASH->KEYR = FLS_UNLOCK_CR_KEY1;
  FLASH->KEYR = FLS_UNLOCK_CR_KEY2;
  
  /* check the usage of the interrupts */
#if (FLS_USE_INTERRUPTS == TRUE)
  FLASH->CR  |= FLS_INTERRUPT_ENABLE_MASK;
#endif
  /* Set the parallelism size which start from bit number 8 */
  FLASH->CR |= (config_ptr->fls_p_size) << FLS_BIT_NUMBER_8;
  /* Lock again the control register for security (LOCK bit in 31 position) */
  SET_BIT(FLASH->CR , FLS_BIT_NUMBER_31);
  /* unlock the option control register 
   * 1=> KEY1 = 0x45670123
   * 2=> KEY2 = 0xCDEF89AB
   */
  FLASH->OPTKEYR = FLS_UNLOCK_OPTION_CR_KEY1;
  FLASH->OPTKEYR = FLS_UNLOCK_OPTION_CR_KEY2;
  /* Check the Write protection option */
  if( config_ptr->fls_write_protection_enable == TRUE )
  {
    /* put zeros in the bits number [27 : 16] */
    FLASH->OPTCR &= FLS_WRITE_PROTECTION_MASK; 
  }else{
    /* put ones in the bits number [27 : 16] */
    FLASH->OPTCR |= ~(FLS_WRITE_PROTECTION_MASK);
  }
  /* set the Read protection option ( The Start position of read protection is bit number 8 )*/
  FLASH->OPTCR =  (FLASH->OPTCR & FLS_READ_PROTECTION_MASK) | ((config_ptr->fls_read_protection) << FLS_BIT_NUMBER_8);
  /* Set the brownout level ( The Start position of BOR level is bit number 2 ) */
  FLASH->OPTCR = (FLASH->OPTCR & FLS_BOR_LEVEL_MASK) | ((config_ptr->fls_BOR_level) << FLS_BIT_NUMBER_2);
  /* trigger user option operation The START BIT is the bit number 1 in OPTCR register */
  SET_BIT(FLASH->OPTCR,FLS_BIT_NUMBER_1);
  /* wait untill that operation compelete as it is Synchronous function */
  /* check the BSY bit that is bit number 16 in STATUS register */
  while(BIT_IS_SET(FLASH->SR,FLS_BIT_NUMBER_16));
  /* lock the option control register for security by setting OPTION LOCK BIT which is bit number zero */
  SET_BIT(FLASH->OPTCR,FLS_BIT_NUMBER_0);
  /* To enter the critical section */
  Disable_Interrupts();
  /* Get the flash memory Mode ( Fast or slow )*/
  g_Flash_Mode = config_ptr->fls_default_mode ;
  /* After finishing initialization set the flash status  to MEMIF_IDLE */
  g_Flash_Status = MEMIF_IDLE;
  /* After finishing initialization set the flash job result to MEMIF_JOB_OK */
  g_Flash_Job_Result = MEMIF_JOB_OK ; 
  /* Set the module mode */
  g_Flash_Mode = config_ptr->fls_default_mode;
  /* Check the mode of operation based on it know the max data handled in one cycle */
  if(g_Flash_Mode == MEMIF_MODE_FAST)
    {
      g_max_bytes = g_Fls_config_ptr->fls_max_read_fast_mode;
    }
  else if(g_Flash_Mode == MEMIF_MODE_SLOW)
    {
      g_max_bytes = g_Fls_config_ptr->fls_max_read_normal_mode;
            
    }else{
     /* Do nothing */
    }
  /* Exit the critical section */
  Enable_Interrupts();
}
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
                                                      )
{
  /* Check the development errors if enabled */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_ERASE_SID,FLS_E_UNINIT);
    return E_NOT_OK;
  }else{
     /* Do nothing */   
  }
  
  /* Check the flash module status */
  if(g_Flash_Status == MEMIF_BUSY )
  {
     /* Report dev error if the flash module status */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_ERASE_SID,FLS_E_BUSY);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + TargetAdderss)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + TargetAdderss)<= FLS_LAST_ADDRESS) ) )
  {
    /* Report dev error if the address is out of range */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_ERASE_SID,FLS_E_PARAM_ADDRESS);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address plus the length lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + TargetAdderss + Length)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + TargetAdderss)<= FLS_LAST_ADDRESS) && Length > FLS_OPERATION_ZERO_LENGTH) )
  {
      /* Report dev error if the address is out of range */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_ERASE_SID,FLS_E_PARAM_LENGTH);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
#endif
  /* To enter the critical section */
  Disable_Interrupts();
  /* Copy the method parameters to initiate erase job */
  g_TargetAdderss = TargetAdderss;
  g_Length = Length;
  /* iterator for the for loop which is looping untill the number of sectors */
  uint8 iterator;
  /* to hold the next start address of the sector */
  Fls_AddressType next_start_add = FLS_BASE_ADDRESS;
  /* declare the start address of each Sector */
  Fls_AddressType sectors_start_adresses[FLS_NUM_OF_SECTORS] ;
  
  for(iterator = 0; iterator < FLS_NUM_OF_SECTORS ; iterator++)
  {
    sectors_start_adresses[iterator] = next_start_add;

    switch(iterator){
      /* add the size of the sector to the base address (sector0 -> sector3 = 16 Kbytes)*/
    case FLS_SECTOR0:
    case FLS_SECTOR1:
    case FLS_SECTOR2:
    case FLS_SECTOR3: next_start_add += FLS_SECTOR0_SIZE;
      break;
      /* add the size of the sector to the base address ( sector4 = 16 Kbytes)*/
    case FLS_SECTOR4: next_start_add += FLS_SECTOR4_SIZE;
      break;
      /* add the size of the sector to the base address (sector5 -> sector11 = 128 Kbytes)*/
    case FLS_SECTOR5:
    case FLS_SECTOR6:
    case FLS_SECTOR7: next_start_add += FLS_SECTOR5_SIZE;
 
      break;
    }
  }
  /* make a loop to know the frist sector to erase and the number of sectors */
  for( iterator = 0;iterator < FLS_NUM_OF_SECTORS;iterator++ ){
    /* Check if it is not the last sector */
    if(iterator != FLS_SECTOR7){
      /* Check if the Target address within the sector range */
      if( ((TargetAdderss + FLS_BASE_ADDRESS) >= sectors_start_adresses[iterator])\
         &&((TargetAdderss + FLS_BASE_ADDRESS)< sectors_start_adresses[iterator + 1]))
      {
        /* Store the sector number */
        g_First_Sector_number = iterator;
        /* justficatoin: to end the loop once it finds the sector number */
        break;
      }
    }
    else{
      /* Store the sector number */
        g_First_Sector_number = FLS_SECTOR7;
    }
  }
  /* To Know how many sectors will be erased */
  for( iterator = g_First_Sector_number;iterator < FLS_NUM_OF_SECTORS;iterator++ ){
    /*  Length will be rounded up to the next full sector boundary */
    if( ((TargetAdderss + FLS_BASE_ADDRESS + Length) > sectors_start_adresses[iterator]) )
    {
      g_number_of_sectors++;
    }
  }
  /* Set the status of the module to Busy until it finishes */
  g_Flash_Status = MEMIF_BUSY;
  /* Set the job of the module to job pending */
  g_Flash_Job_Result = MEMIF_JOB_PENDING;
  /* Set the job Type to erase task */
  g_Fls_operation_type = ERASE_OPERATION;
   /* Exit the critical section */
  Enable_Interrupts();
  return E_OK;
}

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
                                                      )
{
  /* Check the development errors if enabled */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_WRITE_SID , FLS_E_UNINIT);
    return E_NOT_OK;
  }else{
     /* Do nothing */   
  }
  
  /* Check the flash module status */
  if(g_Flash_Status == MEMIF_BUSY )
  {
     /* Report dev error if the flash module status */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_WRITE_SID , FLS_E_BUSY);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + TargetAdderss)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + TargetAdderss)<= FLS_LAST_ADDRESS) ) )
  {
    /* Report dev error if the address is out of range */
    
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_WRITE_SID , FLS_E_PARAM_ADDRESS);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address plus the length lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + TargetAdderss + Length)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + TargetAdderss)<= FLS_LAST_ADDRESS) && Length > FLS_OPERATION_ZERO_LENGTH) )
  {
    /* Report dev error if the address is out of range */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_WRITE_SID,FLS_E_PARAM_LENGTH);
    return E_NOT_OK;
  }else{
  /* Do nothing */
  }
  
  /* Check if the data buffer pointer is being null pointer */
  if( SourceAddressPtr == NULL_PTR )
  {
  /* Report dev error if the data buffer pointer is null */
    
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_WRITE_SID,FLS_E_PARAM_DATA);
  }else{
  /* Do nothing */
  }
#endif
  /* To enter the critical section */
  Disable_Interrupts();
  /* copy the given parameters to Fls module internal variables */
  g_TargetAdderss = TargetAdderss;
  g_SourceAdderss_ptr = SourceAddressPtr;
  g_Length = Length;
  /* Set the status of the module to Busy until it finishes */
  g_Flash_Status = MEMIF_BUSY;
  /* Set the job of the module to job pending */
  g_Flash_Job_Result = MEMIF_JOB_PENDING;
  /* Set the job Type to write task */
  g_Fls_operation_type = WRITE_OPERATION;
  /* Exit the critical section */
  Enable_Interrupts();
  return E_OK;
}

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
                                                      )
{
    /* Check the development errors if enabled */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_READ_SID , FLS_E_UNINIT);
    return E_NOT_OK;
  }else{
     /* Do nothing */   
  }
  
  /* Check the flash module status */
  if(g_Flash_Status == MEMIF_BUSY )
  {
     /* Report dev error if the flash module status */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_READ_SID , FLS_E_BUSY);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + SourceAdderss)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + SourceAdderss)<= FLS_LAST_ADDRESS) ) )
  {
    /* Report dev error if the address is out of range */
    
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_READ_SID , FLS_E_PARAM_ADDRESS);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address plus the length lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + SourceAdderss + Length)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + SourceAdderss)<= FLS_LAST_ADDRESS) && Length > FLS_OPERATION_ZERO_LENGTH) )
  {
    /* Report dev error if the address is out of range */
    Det_ReportError( FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_READ_SID , FLS_E_PARAM_LENGTH );
    return E_NOT_OK;
  }else{
  /* Do nothing */
  }
  
  /* Check if the data buffer pointer is being null pointer */
  if( TargetAddressPtr == NULL_PTR )
  {
  /* Report dev error if the data buffer pointer is null */
    
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_READ_SID,FLS_E_PARAM_DATA);
  }else{
  /* Do nothing */
  }
#endif
  /* To enter the critical section */
  Disable_Interrupts();
  /* copy the given parameters to Fls module internal variables */
  g_SourceAdderss = SourceAdderss;
  g_TargetAdderss_ptr = TargetAddressPtr;
  g_Length = Length;
  /* Set the status of the module to Busy until it finishes */
  g_Flash_Status = MEMIF_BUSY;
  /* Set the job of the module to job pending */
  g_Flash_Job_Result = MEMIF_JOB_PENDING;
  /* Set the job Type to read task */
  g_Fls_operation_type = READ_OPERATION;
   /* Exit the critical section */
  Enable_Interrupts();
  return E_OK;
}

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
                                                      )
{
 /* Check the development errors if enabled */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_COMPARE_SID , FLS_E_UNINIT);
    return E_NOT_OK;
  }else{
     /* Do nothing */   
  }
  
  /* Check the flash module status */
  if(g_Flash_Status == MEMIF_BUSY )
  {
     /* Report dev error if the flash module status */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_COMPARE_SID , FLS_E_BUSY);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + SourceAdderss)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + SourceAdderss)<= FLS_LAST_ADDRESS) ) )
  {
    /* Report dev error if the address is out of range */
    
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_COMPARE_SID , FLS_E_PARAM_ADDRESS);
    return E_NOT_OK;
  }else{
    /* Do nothing */
  }
  
  /* Check that the address plus the length lies within the specified lower and upper flash address boundaries */
  if( !( ((FLS_BASE_ADDRESS + SourceAdderss + Length)>= FLS_BASE_ADDRESS) && ((FLS_BASE_ADDRESS + SourceAdderss)<= FLS_LAST_ADDRESS) && Length > FLS_OPERATION_ZERO_LENGTH) )
  {
    /* Report dev error if the address is out of range */
    Det_ReportError( FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_COMPARE_SID , FLS_E_PARAM_LENGTH );
    return E_NOT_OK;
  }else{
  /* Do nothing */
  }
  
  /* Check if the data buffer pointer is being null pointer */
  if( TargetAddressPtr == NULL_PTR )
  {
  /* Report dev error if the data buffer pointer is null */
    
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_COMPARE_SID,FLS_E_PARAM_DATA);
    return E_NOT_OK;
  }else{
  /* Do nothing */
  }
#endif
  /* To enter the critical section */
  Disable_Interrupts();
  /* copy the given parameters to Fls module internal variables */
  g_SourceAdderss = SourceAdderss;
  g_TargetAdderss_ptr = (uint8*)TargetAddressPtr;
  g_Length = Length;
  /* Set the status of the module to Busy until it finishes */
  g_Flash_Status = MEMIF_BUSY;
  /* Set the job of the module to job pending */
  g_Flash_Job_Result = MEMIF_JOB_PENDING;
  /* Set the job Type to read task */
  g_Fls_operation_type = COMPARE_OPERATION;
  /* To enter the critical section */
  Disable_Interrupts();
  return E_OK;
}
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
void Fls_MainFunction( void )
{
#if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_MAIN_FUNCTION_SID , FLS_E_UNINIT);
    
  }else{
     /* Do nothing */   
  }
#endif
/* Check if the module proccessing is configured to Work with interrups or polling */
#if(FLS_USE_INTERRUPTS == STD_OFF)
  /* Check The job result before execute the function if the job is pending -> execute */
  if( g_Flash_Job_Result == MEMIF_JOB_PENDING )
  {
    /* Check To Know the Type of the Job */
    switch(g_Fls_operation_type)
    {
      case NO_OPERATION:
        
        break;
        /*      Read Task Handlesr     */
      case READ_OPERATION:
          /* 
           * the source buffer will be the falsh address -> Source address
           * the target buffer will be the address of the data buffer 
           */
          Helper_Read_Task_Cycle((uint32*)(g_SourceAdderss + FLS_BASE_ADDRESS),(uint32*)g_TargetAdderss_ptr);
        break;
          /*      Write Task Handlesr     */
      case WRITE_OPERATION:
          /* Perform the data operations to desired Memory address */
          Helper_Write_Task_Cycle((uint8*)g_SourceAdderss_ptr,(uint8*)(g_TargetAdderss + FLS_BASE_ADDRESS));
        break;
          /*      Erase Task Handlesr     */
      case ERASE_OPERATION:
          /* Perform one sector erase per cycle */
          Helper_Erase_Task_Cycle();
        break;
        
          /*  Compare Task */ 
      case COMPARE_OPERATION:
          Helper_Compare_Task_Cycle( (uint32*)g_SourceAdderss, (uint32*)g_TargetAdderss_ptr);
        break;
      }
  }
#endif
  
}

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
void Fls_GetVersionInfo( Std_VersionInfoType* versioninfoPtr )
{
#if (FLS_DEV_ERROR_DETECT == STD_ON)
  if(versioninfoPtr == NULL_PTR)
  {
    /* Report det error */
    Det_ReportError(FLS_MODULE_ID,FLS_INSTANCE_ID,FLS_GET_VERSION_INFO_SID,FLS_E_PARAM_POINTER);
  }else {
    /* Do nothing */
  }
#endif
  versioninfoPtr->moduleID = FLS_MODULE_ID;
  versioninfoPtr->sw_major_version = FLS_SW_MAJOR_VERSION;
  versioninfoPtr->sw_minor_version = FLS_SW_MINOR_VERSION;
  versioninfoPtr->sw_patch_version = FLS_SW_PATCH_VERSION;
  versioninfoPtr->vendorID = FLS_VENDOR_ID;
}

#endif /* IF DET ENABLED */

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
MemIf_StatusType Fls_GetStatus( void )
{
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_GET_STATUS_SID , FLS_E_UNINIT);
    
  }else{
     /* Do nothing */   
  }
#endif
  /* returns the module status */
  return g_Flash_Status;
}
#endif /* IF DET ENABLED */

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
MemIf_JobResultType Fls_GetJobResult( void )
{
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_GET_JOB_RESULT_SID , FLS_E_UNINIT);
    
  }else{
     /* Do nothing */   
  }
  #endif
  /* returns the Last job result */
  return g_Flash_Last_Job_Result;
}
#endif /* IF DET ENABLED */

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
void Fls_SetMode( MemIf_ModeType Mode)
{
  /* Check the development errors if enabled */
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  /* Check the flash module status */
  if(g_Flash_Status == MEMIF_BUSY )
  {
     /* Report dev error if the flash module status */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_SET_MODE_SID , FLS_E_BUSY);
  }else{
    /* Do nothing */
  }
#endif
  /* set the FLS module’s operation mode to the given “Mode” parameter*/
  g_Flash_Mode = Mode;
}
#endif  /* IF DET ENABLED */

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
void Fls_Cancel( void )
{
   #if (FLS_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if the flash memory module is initialized or not */
  if(g_Flash_Status == MEMIF_UNINIT)
  {
    
    /* Report dev error if the module is not initialized */
    Det_ReportError(FLS_MODULE_ID , FLS_INSTANCE_ID , FLS_CANCEL_SID , FLS_E_UNINIT);
    
  }else{
     /* Do nothing */   
  }
  #endif
  /* Reset the internal job proccessing variables of the module */
  g_number_of_sectors = FLS_ZERO_VALUE;
  g_max_bytes = FLS_ZERO_VALUE;
  g_Length = FLS_ZERO_VALUE;
  /* reset the data pointers to null */
  g_TargetAdderss_ptr = NULL_PTR;
  g_SourceAdderss_ptr = NULL_PTR;
  /* Set the module state to ideal */
  g_Flash_Status = MEMIF_IDLE;
  
  /* set the job result to MEMIF_JOB_CANCELED if the job result currently has the value MEMIF_JOB_PENDING*/
  if (g_Flash_Job_Result == MEMIF_JOB_PENDING)
  {
    g_Flash_Job_Result = MEMIF_JOB_CANCELLED;
    g_Flash_Last_Job_Result = g_Flash_Job_Result;
    
  }
  
  /* Call Error End notification Function in the configuration structure */
    g_Fls_config_ptr->Fee_JobErrorNotification_ptr();
}
#endif /* IF DET ENABLED */