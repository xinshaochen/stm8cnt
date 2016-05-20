#ifndef _KEY_H_
#define _KEY_H_
#include "delay.h"


#define ADD GPIOC
#define ADDP (1<<6)
#define Clear GPIOC
#define ClearP (1<<5)


#define AddS ((ADD->IDR&ADDP)>>6)
#define ClearS ((Clear->IDR&ClearP)>>5)

void Key_Init(void);
int Key_Scan(int mode);
int AddScan(int mode);


#endif
