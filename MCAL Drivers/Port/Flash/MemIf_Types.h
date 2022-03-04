/******************************************************************************
 *
 * Module: Memory Interface module
 *
 * File Name: MemIf_Types.h
 *
 * Description: memory interface data types used in the flash driver
 *
 * Author: Karim Mohamed Amin
 ******************************************************************************/

#ifndef MEMIF_TYPES_H_
#define MEMIF_TYPES_H_

typedef enum {

	/* Device is not initialized */
	MEMIF_UNINIT,
        
	/* device driver is idle (doing no thing) */ 
	MEMIF_IDLE,
	
	/* the device driver is currently busy */
	MEMIF_BUSY,
	
	/* The underlying abstraction module is busy with internal
	 * management operations. The underlying device driver
	 * can be busy or idle.
         */
	MEMIF_BUSY_INTERNAL  
          
} MemIf_StatusType;

typedef enum {
	/* The job has been finished successfully.*/
	MEMIF_JOB_OK,
        
	/* The job has not been finished successfully.*/
	MEMIF_JOB_FAILED,
        
	/* The job has not yet been finished.*/
	MEMIF_JOB_PENDING,
        
	/* The job has been canceled.*/
	MEMIF_JOB_CANCELLED,
        
	/* The requested block is inconsistent, it may contain
	 * corrupted data.
         */
	MEMIF_BLOCK_INCONSISTENT,
        
	/* The requested block has been marked as invalid,
	 * the requested operation can not be performed.
         */
	MEMIF_BLOCK_INVALID
	
} MemIf_JobResultType; 


typedef enum {
	/*    The underlying memory abstraction modules and
	 *    drivers are working in slow mode.
         */
	MEMIF_MODE_SLOW,
        
	/* The underlying memory abstraction modules and
	 * drivers are working in fast mode.
         */
        MEMIF_MODE_FAST
} MemIf_ModeType;

/* Definition of broadcast device ID */
#define MEMIF_BROADCAST_ID	0xff

#endif /*MEMIF_TYPES_H_*/