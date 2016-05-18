#include "Sled.h"
void SLED_Init()
{
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
}

