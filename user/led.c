#include "led.h"
//PC 13//PB12 标有FT的引脚才能开漏到5v
void LED_INIT()
{
	GPIO_InitTypeDef GPIO_LED;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE); 
//	GPIO_LED.GPIO_Mode = GPIO_Mode_Out_PP ;
	GPIO_LED.GPIO_Mode = GPIO_Mode_Out_OD; 
	GPIO_LED.GPIO_Pin  = GPIO_Pin_12 ;
	GPIO_LED.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOB ,&GPIO_LED);
	GPIO_SetBits(GPIOB,GPIO_Pin_12); 
//	GPIO_ResetBits(GPIOC,GPIO_Pin_13 ); 
	
}

