#include "ds18b20.h"
//PB11
void Ds18b20_Out(void)
{
	GPIO_InitTypeDef DS18B20_GPIO;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,GPIO_Pin_11);
     
	DS18B20_GPIO.GPIO_Mode = GPIO_Mode_Out_PP ;
	DS18B20_GPIO.GPIO_Pin  = GPIO_Pin_11;
    DS18B20_GPIO.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_Init(GPIOB,&DS18B20_GPIO); 	
	GPIO_SetBits(GPIOB,GPIO_Pin_11) ;
//	GPIO_ResetBits(GPIOB,GPIO_Pin_11); 
}
void Ds18b20_In(void)
{
	GPIO_InitTypeDef DS18B20_GPIO;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,GPIO_Pin_11);
	
	DS18B20_GPIO.GPIO_Mode  = GPIO_Mode_IN_FLOATING ;
	DS18B20_GPIO.GPIO_Pin  = GPIO_Pin_11;
	GPIO_Init(GPIOB,&DS18B20_GPIO); 
}
//1 : fail 0:succeed
u8 Ds18b20_Init(void)
{
	uint8_t pulse = 0 ;
	Ds18b20_Out();
	DS18B20_OUT_LOW;
	delay_us(480);
	DS18B20_OUT_HIGH;
	delay_us(60); 
	Ds18b20_In();
	while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0))
	{
		pulse++;
		delay_us(1);		
	}
	if(pulse <=240&&pulse>60)
	{
		
		pulse = 0;
		
	}
    else 
	{
		pulse = 1;
	}
	delay_us(10);
    Ds18b20_Out();
    DS18B20_OUT_HIGH;	
	delay_us(180); 
	return pulse ;	
}

