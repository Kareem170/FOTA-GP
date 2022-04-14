 /******************************************************************************
 *
 * Module: ModuleTest
 *
 * File Name: Dio_ModuleTest.c
 *
 * Description: Source file for the Dio Test Cases.
 *
 ******************************************************************************/
#include <assert.h>
#include "Dio.h"
#include "Dio_Regs.h"
#include "Det.h"
#include "tm4c123gh6pm_registers.h"

#define DIO_INVALIDE_CHANNEL_NUM 50

boolean Det_TestLastReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) 
{
    boolean result = (Det_ModuleId == ModuleId) && (Det_InstanceId == InstanceId) && 
                     (Det_ApiId == ApiId) && (Det_ErrorId == ErrorId);
    Det_ModuleId = 0;
    Det_InstanceId = 0;
    Det_ApiId = 0;
    Det_ErrorId = 0;
    
    return result;
}


/************************************************************************************/
int main(void)
{
    //  Port_Init( &Port_pinConfigurationSet);
    /* Initailize PF0, PF1, PF2 and PF4 as GPIO pins */
   Dio_Init(&Dio_Configuration);
    Dio_ReadChannel(0);
    Dio_WriteChannel(0,1);
    Dio_ReadPort(0);
    Dio_WritePort(0,0xFF);
}