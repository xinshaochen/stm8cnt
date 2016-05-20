#include "EXIT.h"
#include "ALL_Includes.h"




void EXTI_Init(void)
{
  ADD->DDR&=~ADDP;
  ADD->CR1|=ADDP;
  ADD->CR2|=ADDP;
  EXTI->CR1=0x20;//下
 // EXTI->CR1=0x10;//上

    
    
//    CFG->GCR |= BIT(0);
//    EXIT_GPIO->DDR &=~EXIT_PIN;                                   
//    EXIT_GPIO->CR1 |= EXIT_PIN;       
//    
//    //上拉输入
//    EXIT_GPIO->CR2 |= EXIT_PIN;
//     
//    EXIT_GPIO->CR1  |= 0x20;
    
    asm("rim");    //开总中断
}

//#pragma   vector = EXTI0_PA_vector
//__interrupt  void  EXTI0_PA_IRQHandler(void)
//{     
//  
//}
//#pragma   vector = EXTI1_PB_vector
//__interrupt  void  EXTI1_PB_IRQHandler(void)
//{     
//  
//}



#pragma   vector = EXTI2_PC_vector
__interrupt  void  EXTI2_PC_IRQHandler(void)
{     
//  asm("sim");    //关总中断
  delay_ms(10);
  if(ADDS==0)
  {
    num++;
  }
  
 // asm("rim");    //开总中断  
 // EXIT_GPIO->CR2 |= EXIT_PIN;  
}
//#pragma   vector = EXTI3_PD_vector
//__interrupt  void  EXTI3_PD_IRQHandler(void)
//{     
//  
//}
//#pragma   vector = EXTI4_PE_vector
//__interrupt  void  EXTI4_PE_IRQHandler(void)
//{     
//  
//}





