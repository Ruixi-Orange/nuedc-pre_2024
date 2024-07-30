#include "encoder.h"

uint32_t gpio_interrup;


void GROUP1_IRQHandler(void)
{
	//使用我司D153C驱动模块时，E1A连接PA15、E1B连接PA16、E2A连接PA17，E2B连接PA22
	//获取中断信号
	gpio_interrup = DL_GPIO_getEnabledInterruptStatus(GPIOA,ENCODER_E1A_PIN|ENCODER_E1B_PIN|ENCODER_E2A_PIN|ENCODER_E2B_PIN);
	
	uint8_t E1A=DL_GPIO_readPins(GPIOA,ENCODER_E1A_PIN);
	uint8_t E1B=DL_GPIO_readPins(GPIOA,ENCODER_E1B_PIN);
	uint8_t E2A=DL_GPIO_readPins(GPIOA,ENCODER_E2A_PIN);
	uint8_t E2B=DL_GPIO_readPins(GPIOA,ENCODER_E2B_PIN);
	
	if((gpio_interrup & ENCODER_E1A_PIN)==ENCODER_E1A_PIN)	//E1A上升沿
	{
		if(E1B)	//E1B高电平
		{
			GetEncoderCountA++;
    }
    else
		{
			GetEncoderCountA--;
		}
	}
	else if((gpio_interrup & ENCODER_E1B_PIN)==ENCODER_E1B_PIN)	//E1B上升沿
	{
		if(!E1A)
		{
			GetEncoderCountA++;
    }
    else
		{
			GetEncoderCountA--;
		}
	}
	
	if((gpio_interrup & ENCODER_E2A_PIN)==ENCODER_E2A_PIN)	//E1A上升沿
	{
		if(E2B)	//E1B高电平
		{
			GetEncoderCountB++;
    }
    else
		{
			GetEncoderCountB--;
		}
	}
	else if((gpio_interrup & ENCODER_E2B_PIN)==ENCODER_E2B_PIN)	//E1B上升沿
	{
		if(!E2A)
		{
			GetEncoderCountB++;
    }
    else
		{
			GetEncoderCountB--;
		}
	}
	DL_GPIO_clearInterruptStatus(GPIOA,ENCODER_E1A_PIN|ENCODER_E1B_PIN|ENCODER_E2A_PIN|ENCODER_E2B_PIN);

}
