#include "EXIT.h"
#include "ALL_Includes.h"




void EXTI_Init(void)
{
  ADD->DDR&=~ADDP;
  ADD->CR1|=ADDP;
  ADD->CR2|=ADDP;
  EXTI->CR1=0x20;//��
 // EXTI->CR1=0x10;//��

    
    
//    CFG->GCR |= BIT(0);
//    EXIT_GPIO->DDR &=~EXIT_PIN;                                   
//    EXIT_GPIO->CR1 |= EXIT_PIN;       
//    
//    //��������
//    EXIT_GPIO->CR2 |= EXIT_PIN;
//     
//    EXIT_GPIO->CR1  |= 0x20;
    
    asm("rim");    //�����ж�
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
//  asm("sim");    //�����ж�
  delay_ms(10);
  if(ADDS==0)
  {
    num++;
  }
  
 // asm("rim");    //�����ж�  
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





