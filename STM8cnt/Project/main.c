
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



#define clear_time 48



void CLOCK_Config(u8 SYS_CLK);
void All_Congfig(void);

void SetIo(u8 dat)
{
    
    AS(dat&0x01);
    BS(dat&0x02);
    CS(dat&0x04);
    DS(dat&0x08);
    ES(dat&0x10);
    FS(dat&0x20);
    GS(dat&0x40);
    //HS = dat&0x80;
}       
void DIo(u8 dat)
{
  u8 i=0x01;
  D1S(dat&i);i<<=1;
  D2S(dat&i);i<<=1;
  D3S(dat&i);i<<=1;
  D4S(dat&i);i<<=1;
  D5S(dat&i);i<<=1;
  D6S(dat&i);
}

int main(void)
{     
	u8 key;
  u8 rx_buff[33];
  u8 one=1;
  u16 t=0;
  float a=0;
  u16 buf;
  u16 i=0,l;
  u16 k=0;
  u8 s=0;
  u32 test;
  u32 lastnum=0;
  u32 eppnum=0;
  All_Congfig();
  ADC_Init(Channel_6);
  
  LED_Init();
  LED_R_CLR;

  test=0;
  //eep_32bit_write(EEPADDR,test);
  eep_32bit_read(EEPADDR,&num);
  eppnum = num;
  //EXTI_Init();
  Key_Init();
  SLED_Init();
  TIM4_Init();
//  D1_CLR;
//  D2_CLR;
//  D3_CLR;
//  D4_CLR;
//  D5_CLR;
//  D6_CLR;
//  
//  A_CLR;
//  B_CLR;
//  C_CLR;
//  D_CLR;
//  E_CLR;
//  F_CLR;
//  G_CLR;
  
  while(1)
  {
    t = ADC_Data();
    key=AddScan(0);
    if(key==0)
    {
      key=Key_Scan(1);
    }
    if(t>410)
    {
        if(num!=eppnum&&one==1)
        {
          LED_R_SET;
          eep_32bit_write(EEPADDR,num);
          one=0;
          eppnum=num;
          LED_R_CLR;
        }
    }else one=1;
    
    if(key==1)
    {
      num++;
    }
    if(key==2)
      {
        k++;
        switch(k/(clear_time/6))
        {
        case 0:
          Gen[0]=16;Gen[1]=17;Gen[2]=17;Gen[3]=17;Gen[4]=17;Gen[5]=17;
          break;
        case 1:
          Gen[0]=16;Gen[1]=16;Gen[2]=17;Gen[3]=17;Gen[4]=17;Gen[5]=17;
          break;
        case 2:
          Gen[0]=16;Gen[1]=16;Gen[2]=16;Gen[3]=17;Gen[4]=17;Gen[5]=17;
          break;
        case 3:
          Gen[0]=16;Gen[1]=16;Gen[2]=16;Gen[3]=16;Gen[4]=17;Gen[5]=17;
          break;
        case 4:
          Gen[0]=16;Gen[1]=16;Gen[2]=16;Gen[3]=16;Gen[4]=16;Gen[5]=17;
          break;
        case 5:
          Gen[0]=16;Gen[1]=16;Gen[2]=16;Gen[3]=16;Gen[4]=16;Gen[5]=16;
          break;
        }
        
        
          if(k>=clear_time)
          {
            k=0;
            a = num/20;
            if(a<1) a=1;
            l=20;
            while(l--)
            {
            num = num-a;
            NumSet(num);
            if(num==0) break;
            delay_ms(20);
            }
            num=0;
          }

      }else
      {
        if(k!=0)
        {
          NumSet(num);
          k=0;
        }
         
      }
       
    
    
//    if(i++>=120)
//    {
//      i=0;
//      num++;
//    }
    if(num!=lastnum&&key!=2)
    {
      NumSet(num);
      lastnum=num;
    }
    delay_ms(1);
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



