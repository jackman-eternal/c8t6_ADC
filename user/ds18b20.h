#ifndef __DS18B20_H
#define __DS18B20_H

#include "stm32f10x.h"
#include "delay.h"

#define DS18B20_OUT_HIGH GPIO_SetBits(GPIOB,GPIO_Pin_11) 
#define DS18B20_OUT_LOW  GPIO_ResetBits(GPIOB,GPIO_Pin_11)

void Ds18b20_Out(void);
void Ds18b20_In(void);
void Ds18b20_Reset(void);
u8 Ds18b20_Init(void);

#endif

