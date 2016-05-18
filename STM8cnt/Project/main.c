
#include "ALL_Includes.h"
#include "24l01.h"
#include "time.h"
#include "EXIT.h"
#include "remote.h"
#include "led.h"
#include "motor.h"
#include "ADC.h"
#include "eeprom.h"
#include "Sled.h"






#define  SYS_CLOCK    16


void CLOCK_Config(u8 SYS_CLK);
void All_Congfig(void);


int main(void)
{     
	u8 key;
	u8 s=0;
  u8 rx_buff[33];
  u16 t=0;
  u16 a=0;
  u16 buf;
      All_Congfig();
  ADC_Init(Channel_6);
  
  LED_Init();
  LED_R_CLR;
  
  SLED_Init();
  D1_CLR;
  D2_CLR;
  D3_CLR;
  D4_CLR;
  
  A_CLR;
  B_CLR;
  C_CLR;
  D_CLR;
  E_CLR;
  F_CLR;
  G_CLR;
  
  delay_ms(100);
  eep_16bit_write(EEPADDR,0x0000);
  eep_16bit_read(EEPADDR,&a);
  buf=a;
  

  
  
  delay_ms(100);

  
  while(1)
  {
    t = ADC_Data();
//    buf=t;
    

    if(t>400)
    {
      LED_R_SET;
      eep_16bit_write(EEPADDR,0xdddd);
      LED_R_CLR;
    }
//    delay_ms(2);
  }
  

}
void All_Congfig(void)
{
    CLOCK_Config(SYS_CLOCK);//系统时钟初始化  
	
}

/// <summary>
///函数功能：系统内部时钟配置
///输入参数：SYS_CLK : 2、4、8、16
///输出参数：无
///备    注：系统启动默认内部2ＭＨＺ
/// </summary>
void CLOCK_Config(u8 SYS_CLK)
{
   //时钟配置为内部RC，16M
   CLK->CKDIVR &=~(BIT(4)|BIT(3));
  
   switch(SYS_CLK)
   {
      case 2: CLK->CKDIVR |=((1<<4)|(1<<3)); break;
      case 4: CLK->CKDIVR |=(1<<4); break;
      case 8: CLK->CKDIVR |=(1<<3); break;
   }
}



