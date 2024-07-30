#include "encoder.h"

uint32_t gpio_interrup;


void GROUP1_IRQHandler(void)
{
	//ʹ����˾D153C����ģ��ʱ��E1A����PA15��E1B����PA16��E2A����PA17��E2B����PA22
	//��ȡ�ж��ź�
	gpio_interrup = DL_GPIO_getEnabledInterruptStatus(GPIOA,ENCODER_E1A_PIN|ENCODER_E1B_PIN|ENCODER_E2A_PIN|ENCODER_E2B_PIN);
	
	uint8_t E1A=DL_GPIO_readPins(GPIOA,ENCODER_E1A_PIN);
	uint8_t E1B=DL_GPIO_readPins(GPIOA,ENCODER_E1B_PIN);
	uint8_t E2A=DL_GPIO_readPins(GPIOA,ENCODER_E2A_PIN);
	uint8_t E2B=DL_GPIO_readPins(GPIOA,ENCODER_E2B_PIN);
	
	if((gpio_interrup & ENCODER_E1A_PIN)==ENCODER_E1A_PIN)	//E1A������
	{
		if(E1B)	//E1B�ߵ�ƽ
		{
			GetEncoderCountA++;
    }
    else
		{
			GetEncoderCountA--;
		}
	}
	else if((gpio_interrup & ENCODER_E1B_PIN)==ENCODER_E1B_PIN)	//E1B������
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
	
	if((gpio_interrup & ENCODER_E2A_PIN)==ENCODER_E2A_PIN)	//E1A������
	{
		if(E2B)	//E1B�ߵ�ƽ
		{
			GetEncoderCountB++;
    }
    else
		{
			GetEncoderCountB--;
		}
	}
	else if((gpio_interrup & ENCODER_E2B_PIN)==ENCODER_E2B_PIN)	//E1B������
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
