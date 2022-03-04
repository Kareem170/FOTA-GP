/******************************************************************************
 *
 * Module: flash memory
 *
 * File Name: fls_PBCfg.h
 *
 * Description: Post build configuration Source file for STM32F405RG Microcontroller - Flash memory Driver
 *
 * Author: Karim Mohamed Amin
 ******************************************************************************/
#include "fls.h"
#include "Fee_Cbk.h"
/*
 * Module Version 1.0.0
 */
#define FLS_PBCFG_SW_MAJOR_VERSION              (1U)
#define FLS_PBCFG_SW_MINOR_VERSION              (0U)
#define FLS_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define FLS_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define FLS_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define FLS_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between fls_PBcfg.c and fls.h files */
#if ((FLS_PBCFG_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION)\
 ||  (FLS_PBCFG_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION)\
 ||  (FLS_PBCFG_AR_RELEASE_PATCH_VERSION != FLS_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected AUTOSAR version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((FLS_PBCFG_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION)\
 ||  (FLS_PBCFG_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION)\
 ||  (FLS_PBCFG_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected Software version"
#endif
/* PB structure used with FLS_Init API */
const  Fls_configType  fls_configuration = { /* the latency (number of wait state) */
                                            five_ws ,
                                            /* parallelism Size*/
                                            x32_psize ,
                                            /* Brownout level settings */
                                            BOR_off ,
                                            /* Cycle time of calls of the flash driver's main function */
                                            0.5 ,
                                            /* Mode of operation of flash module */
                                            MEMIF_MODE_SLOW ,
                                            /* The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in fast mode.*/
                                            (12),
                                            /* The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in normal mode.*/
                                            (12),
                                            /* The maximum number of bytes to Write in one cycle of the flash driver's job processing function in fast mode.*/
                                            (12),
                                            /* The maximum number of bytes to Write in one cycle of the flash driver's job processing function in normal mode.*/
                                            (12),
                                            /* Read protection level */
                                            read_level_0 ,
                                            /* Write protection enable */
                                            FALSE ,
                                            /* Data cache enable*/
                                            TRUE ,
                                            /* Instruction cache enable */
                                            TRUE ,
                                            /* Prefetch enable*/
                                            TRUE,
                                            Fee_JobEndNotification,
                                            Fee_JobErrorNotification
};
