#include "Sled.h"

u8 const LedCode[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71,0x3f,0x7f};
u8 Order[Dnum];
u32 num=0;
u8 Gen[Dnum];



void SLED_Init()
{
  u8 test;
  u8 s=0;
  u8 i;
  test = ~(0x01<<Dnum);
  for(i=0xfe;i!=test;i=i<<1|0x01)
  {
    Order[s]=i;
    s++;
  }
  A->DDR |= AP;
  A->CR1 |= AP;
  B->DDR |= BP;
  B->CR1 |= BP;
  C->DDR |= CP;
  C->CR1 |= CP;
  D->DDR |= DP;
  D->CR1 |= DP;
  E->DDR |= EP;
  E->CR1 |= EP;
  F->DDR |= FP;
  F->CR1 |= FP;
  G->DDR |= GP;
  G->CR1 |= GP;
  
  D1->DDR |= D1P;
  D1->CR1 |= D1P;
  D2->DDR |= D2P;
  D2->CR1 |= D2P;
  D3->DDR |= D3P;
  D3->CR1 |= D3P;
  D4->DDR |= D4P;
  D4->CR1 |= D4P;
  D5->DDR |= D5P;
  D5->CR1 |= D5P;
  D6->DDR |= D6P;
  D6->CR1 |= D6P;
}
void NumSet(u32 num)
{
  u8 i=0;
  for(i=0;i<Dnum;i++)
  {
    Gen[i]=0;
  }
  i=0;
  while(num>=10)
  {
  Gen[i++]=num%10;
  num/=10;
  }
  Gen[i] = num; 
}

