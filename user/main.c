#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "bsp_adc.h"



unsigned char AD_CHANNEL=0;
unsigned long PH_num=0,PU_V=0;
float PH_Value=0;
u8 ph_temp=0,tu_temp=0;
u16 ph_result=0,tu_result=0;
u16 adc_1,adc_2;
u16 adc_v_1,adc_v_2;

unsigned char  Tx[20];   //无线发送缓存


// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint16_t ADC_ConvertedValue;

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal;  




void PH_Value_Conversion()
{
	
	  ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; // 读取转换的AD值
	
		PH_Value=-5.7541*ADC_ConvertedValueLocal+16.654;
	
    
	if(PH_Value<=0.0){PH_Value=0.0;}
	if(PH_Value>=14.0){PH_Value=14.0;}
	
		  /*显示电压*/
	Tx[0]=(int)(PH_Value*100)/1000+'0';	
	Tx[1]=(int)(PH_Value*100)%1000/100+'0';
	Tx[2]='.';
	Tx[3]=(int)(PH_Value*100)%100/10+'0';
	Tx[4]=(int)(PH_Value*100)%10+'0';
}


int main(void)
{
		
	delay_init(); 
	LED_INIT(0); 
	ADCx_Init(); 	
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2 );
	while(1)
	{
		PH_Value_Conversion();	
	 
	}	 


}
	


