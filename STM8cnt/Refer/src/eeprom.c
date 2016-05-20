#include "eeprom.h"

void eeprom_read(u16 u16Addr, u8 *pdatas, u8 len) 
{ 
  u8 *eep=(u8 *)u16Addr; 
  u8 j; 

  for(j=0; j<len; j++) 
  { 
    pdatas[j]=eep[j];         
  } 
} 
void eep_32bit_read(u16 u16Addr, u32 *pdata)
{
  u8 *eep=(u8 *)u16Addr;
  u8 HHdata,Hdata,Ldata,LLdata;
  HHdata = *eep;
  Hdata = *(eep+1);
  Ldata = *(eep+2);
  LLdata = *(eep+3);
  *pdata = (u32)HHdata<<24;
  *pdata |= (u32)Hdata<<16;
  *pdata |= (u32)Ldata<<8;
  *pdata |= LLdata;
}
void eep_32bit_write(u16 u16Addr, u32 pdata)
{
  u8 *eep=(u8*)u16Addr; 
  u8 HHdata,Hdata,LLdata,Ldata;
  HHdata = (u8)(pdata>>24);
  Hdata = (u8)(pdata>>16);
  Ldata = (u8)(pdata>>8);
  LLdata = (u8)(pdata);
  
  FLASH->DUKR=EEPMASS1;                //��1             ��Կ  
  FLASH->DUKR=EEPMASS2;                //��2             ��Կ 
  while(!(FLASH->IAPSR&0x08));         //�ȴ����ܾ���
  FLASH->CR2 |= 0x40;     //               
  FLASH->NCR2 &= ~0x40;   //�����ֱ�� 
  
  *eep = HHdata;
  *(eep+1) = Hdata;
  *(eep+2) = Ldata;
  *(eep+3) = LLdata;
  while(!(FLASH->IAPSR&0x04)); 
  FLASH->IAPSR &=0xf7; 
  
}
void eep_16bit_read(u16 u16Addr, u16 *pdata)
{
  u8 *eep=(u8 *)u16Addr;
  u8 Hdata,Ldata;
  Hdata = *eep;
  Ldata = *(eep+1);
  *pdata = (u16)Hdata<<8;
  *pdata |= Ldata;
}
void eep_16bit_write(u16 u16Addr, u16 pdata)
{
  u8 *eep=(u8*)u16Addr; 
  u8 Hdata,Ldata;
  Hdata = (u8)(pdata>>8);
  Ldata = (u8)pdata;
  
  FLASH->DUKR=EEPMASS1;                //��1             ��Կ  
  FLASH->DUKR=EEPMASS2;                //��2             ��Կ 
  while(!(FLASH->IAPSR&0x08));         //�ȴ����ܾ���
  FLASH->CR2 |= 0x40;     //               
  FLASH->NCR2 &= ~0x40;   //�����ֱ�� 
  
  *eep = Hdata;
  *(eep+1) = Ldata;
  *(eep+2) = 0;
  *(eep+3) = 0;
  while(!(FLASH->IAPSR&0x04)); 
  FLASH->IAPSR &=0xf7;   
}
void eep_word_write(u16 u16Addr, u8 *pdatas, u8 len)
{ 
  u8 *eep=(u8*)u16Addr; 
  u8 j;

  FLASH->DUKR=EEPMASS1;                //��1��Կ  
  FLASH->DUKR=EEPMASS2;                //��2��Կ 
  while(!(FLASH->IAPSR&0x08));         //�ȴ����ܾ���
 
  //DISABLE_MAC_INTERRUPTS();
  FLASH->CR2 |= 0x40;     //               
  FLASH->NCR2 &= ~0x40;   //�����ֱ�� 
  for(j=0; j<len; j++) 
  { 
    eep[j] = pdatas[j]; 
    
  }
  while(!(FLASH->IAPSR&0x04)); 
  
  FLASH->IAPSR &=0xf7;    // off the eeprom program
 // ENABLE_MAC_INTERRUPTS();       
}


