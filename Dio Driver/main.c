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

/************************************************************************************
* Test ID :TestCase1
* Description: Test for Write, Read and Flip Channel API's report a DIO_E_UNINIT DET 
*              error in case the Dio_Init is not called yet.
* Pre-requisits: Dio Module is not initialized before Run this test case.
* Test Procedure : 1. Call Dio_WriteChannel DET error DIO_E_UNINIT should be reported.
*                  2. Call Dio_ReadChannel DET error DIO_E_UNINIT should be reported.
*                  3. Call Dio_FlipChannel DET error DIO_E_UNINIT should be reported.
*************************************************************************************/
void TestCase1(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID,DIO_E_UNINIT));
    
    Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID,DIO_E_UNINIT));
    
    Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID,DIO_E_UNINIT));
}

/************************************************************************************
* Test ID :TestCase2
* Description: Test for Dio_Init and Dio_GetVersionInfo API's report the correct DET 
*              error in case the API called with NULL pointer.
* Pre-requisits: No Need
* Test Procedure : 1. Call Dio_Init DET error DIO_E_PARAM_CONFIG should be reported.
*                  2. Call Dio_GetVersionInfo DET error DIO_E_PARAM_POINTER should be reported.
*************************************************************************************/
void TestCase2(void)
{
    Dio_Init(NULL_PTR);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_INIT_SID,DIO_E_PARAM_CONFIG));
    
#if (DIO_VERSION_INFO_API == STD_ON)
    Dio_GetVersionInfo(NULL_PTR);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_GET_VERSION_INFO_SID,DIO_E_PARAM_POINTER));
#endif    
}

/************************************************************************************
* Test ID :TestCase3
* Description: Test for Write, Read and Flip Channel API's report a 
*              DIO_E_PARAM_INVALID_CHANNEL_ID DET error in case invalid Channel ID.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Call Dio_WriteChannel DET error DIO_E_PARAM_INVALID_CHANNEL_ID 
*                     should be reported.
*                  2. Call Dio_ReadChannel DET error DIO_E_PARAM_INVALID_CHANNEL_ID 
*                     should be reported.
*                  3. Call Dio_FlipChannel DET error DIO_E_PARAM_INVALID_CHANNEL_ID 
*                     should be reported.
*************************************************************************************/
void TestCase3(void)
{
    Dio_WriteChannel(DIO_INVALIDE_CHANNEL_NUM,STD_HIGH);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID));
    
    Dio_ReadChannel(DIO_INVALIDE_CHANNEL_NUM);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID));
    
#if (DIO_FLIP_CHANNEL_API == STD_ON)
    Dio_FlipChannel(DIO_INVALIDE_CHANNEL_NUM);
    assert(Det_TestLastReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID));
#endif    
}

/************************************************************************************
* Test ID :TestCase4
* Description: Test for GetVersionInfo API functionality.
* Pre-requisits: No Need
* Test Procedure : Call Dio_GetVersionInfo and get the required information.
*************************************************************************************/
#if (DIO_VERSION_INFO_API == STD_ON)
void TestCase4(void)
{
    Std_VersionInfoType Version_Info;
    Dio_GetVersionInfo(&Version_Info);
    assert(Version_Info.vendorID == DIO_VENDOR_ID);
    assert(Version_Info.moduleID == DIO_MODULE_ID);
    assert(Version_Info.sw_major_version == DIO_SW_MAJOR_VERSION);
    assert(Version_Info.sw_minor_version == DIO_SW_MINOR_VERSION);
    assert(Version_Info.sw_patch_version == DIO_SW_PATCH_VERSION);
}
#endif  
/************************************************************************************
* Test ID :TestCase5
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press SW1(PF4) then the Red led(PF1) shall be turned on.
*                  2. Press SW2(PF0) then the Red led(PF1) shall be turned off.
*************************************************************************************/
void TestCase5(void)
{
    uint8 SW1_Value = STD_HIGH;
    uint8 SW2_Value = STD_HIGH;

    /* Wait until the SW1 is pressed */
    while(SW1_Value != STD_LOW)
    {
        SW1_Value = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
    }

    /* Turn on the Red Led */
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);

    /* Wait until the SW2 is pressed */
    while(SW2_Value != STD_LOW)
    {
        SW2_Value = Dio_ReadChannel(DioConf_SW2_CHANNEL_ID_INDEX);
    }

    /* Turn off the Red Led */
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_LOW);
}

/************************************************************************************
* Test ID :TestCase6
* Description: Test for Flip and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press SW1(PF4) then the blue led(PF2) shall be flipped (OFF --> ON).
*                  2. Press SW2(PF0) then the blue led(PF2) shall be flipped (ON --> OFF).
*************************************************************************************/
void TestCase6(void)
{
    uint8 SW1_Value = STD_HIGH;
    uint8 SW2_Value = STD_HIGH;

    /* Wait until SW1 is pressed */
    while(SW1_Value != STD_LOW)
    {
        SW1_Value = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
    }
    
    /* Flip the Blue Led */
    Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);
    
    /* Wait until SW2 button is pressed */
    while(SW2_Value != STD_LOW)
    {
        SW2_Value = Dio_ReadChannel(DioConf_SW2_CHANNEL_ID_INDEX);
    }
    
    /* Flip the Blue Led */
    Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);   
}

void GPIO_Pins_Init(void)
{
  
    
    
}

int main(void)
{
    /* Initailize PF0, PF1, PF2 and PF4 as GPIO pins */
    GPIO_Pins_Init();
    
    /* Run the First Test Case */
    TestCase1();

    /* Initialize the Dio Driver */
    Dio_Init(&Dio_Configuration);
    
    /* Run the Second Test Case */
    TestCase2();
    
    /* Run the Third Test Case */
    TestCase3();
    
#if (DIO_VERSION_INFO_API == STD_ON)
    /* Run the Forth Test Case */
    TestCase4();
#endif

    /* Run the Fifth Test Case */
    TestCase5();
    
#if (DIO_FLIP_CHANNEL_API == STD_ON)
    /* Run the Sixth Test Case */
    TestCase6();
#endif
}
