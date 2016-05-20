#include "key.h"
#include "stm8s.h"

void Key_Init()
{
  ADD->DDR&=~ADDP;
  ADD->CR1|=ADDP;
  ADD->CR2&=~ADDP;
    Clear->DDR&=~ClearP;
   Clear->CR1|=ClearP;
Clear->CR2&=~ClearP;
}
//1ÎªÁ¬°´
int Key_Scan(int mode)
{
  static u8 key_up=1;
  if(mode) key_up=1;
  if(key_up&&(/*AddS==0||*/ClearS==0))
  {
    
    delay_ms(10);
    key_up=0;
   /* if(AddS==0)return 1;
    else*/ if(ClearS==0)return 2;
    
  }else if(/*AddS==1&&*/ClearS==1)key_up=1;
  return 0;
}

int AddScan(int mode)
{
  static u8 addUp=1;
  if(mode) addUp=1;
  if(addUp&&(AddS==0))
  {
    delay_ms(10);
    addUp=0;
    if(AddS==0) return 1;
    
  }else if(AddS==1) addUp=1;
  return 0;
  
}


