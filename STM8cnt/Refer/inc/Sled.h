#ifndef _SLED_H_
#define _SLED_H_

#include "stm8s.h"

#define A GPIOD
#define AP (1<<4)
#define B GPIOC
#define BP (1<<4)
#define C GPIOD
#define CP (1<<1)
#define D GPIOD
#define DP (1<<2)
#define E GPIOD
#define EP (1<<3)
#define F GPIOB
#define FP (1<<5)
#define G GPIOC
#define GP (1<<7)


#define D1 GPIOC
#define D1P (1<<3)
#define D2 GPIOB
#define D2P (1<<4)
#define D3 GPIOD
#define D3P (1<<5)
#define D4 GPIOA
#define D4P (1<<1)
#define D5 GPIOA
#define D5P (1<<2)
#define D6 GPIOA
#define D6P (1<<3)


#define A_SET A->ODR|=AP
#define A_CLR A->ODR&=~AP
#define B_SET B->ODR|=BP
#define B_CLR B->ODR&=~BP
#define C_SET C->ODR|=CP
#define C_CLR C->ODR&=~CP
#define D_SET D->ODR|=DP
#define D_CLR D->ODR&=~DP
#define E_SET E->ODR|=EP
#define E_CLR E->ODR&=~EP
#define F_SET F->ODR|=FP
#define F_CLR F->ODR&=~FP
#define G_SET G->ODR|=GP
#define G_CLR G->ODR&=~GP


#define D1_SET D1->ODR|=D1P
#define D1_CLR D1->ODR&=~D1P
#define D2_SET D2->ODR|=D2P
#define D2_CLR D2->ODR&=~D2P
#define D3_SET D3->ODR|=D3P
#define D3_CLR D3->ODR&=~D3P
#define D4_SET D4->ODR|=D4P
#define D4_CLR D4->ODR&=~D4P
#define D5_SET D5->ODR|=D5P
#define D5_CLR D5->ODR&=~D5P
#define D6_SET D6->ODR|=D6P
#define D6_CLR D6->ODR&=~D6P



void SLED_Init();



#endif


