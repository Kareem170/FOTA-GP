#include "fls.h"
#include "Fee_Cbk.h"
const uint8 data_buffer[] = {0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xBB,0xBB,0xBB,0xBB,0xBB,0xBB};
uint8 read_data[32];
int main(void)
{ 
  Fls_Init(&fls_configuration);
  Fls_Write((Fls_AddressType)0x62df0,(const uint8*)data_buffer,16);
  uint8 i=0;
  while(i<2)
  {
    Fls_MainFunction();
    i++;
  }
 // Fls_Erase((Fls_AddressType)0xC000,16);
 // Fls_MainFunction();
 Fls_Read((Fls_AddressType)0x62df0,read_data,32);
while(1)
{
  Fls_MainFunction();
}

}

void Fee_JobEndNotification(void)
{
}
void Fee_JobErrorNotification(void)
{
}