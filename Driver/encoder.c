#include "encoder.h"
#include "led.h"
uint32_t gpio_interrup;

/*******************************************************
�������ܣ��ⲿ�ж�ģ��������ź�
��ں�������
����  ֵ����
***********************************************************/
void GROUP1_IRQHandler(void)
{
	//ʹ����˾D153C����ģ��ʱ��E1A����PA15��E1B����PA16��E2A����PA17��E2B����PA22
	//��ȡ�ж��ź�
	gpio_interrup = DL_GPIO_getEnabledInterruptStatus(GPIOA,ENCODERA_E1A_PIN|ENCODERA_E1B_PIN|ENCODERB_E2A_PIN|ENCODERB_E2B_PIN);
	//encoderA
	if((gpio_interrup & ENCODERA_E1A_PIN)==ENCODERA_E1A_PIN)
	{
		if(!DL_GPIO_readPins(GPIOA,ENCODERA_E1B_PIN))
		{
			Get_Encoder_countA--;
		}
		else
		{
			Get_Encoder_countA++;
		}
	}
	else if((gpio_interrup & ENCODERA_E1B_PIN)==ENCODERA_E1B_PIN)
	{
		if(!DL_GPIO_readPins(GPIOA,ENCODERA_E1A_PIN))
		{
			Get_Encoder_countA++;
		}
		else
		{
			Get_Encoder_countA--;
		}
	}
	//encoderB
	if((gpio_interrup & ENCODERB_E2A_PIN)==ENCODERB_E2A_PIN)
	{
		if(!DL_GPIO_readPins(GPIOA,ENCODERB_E2B_PIN))
		{
			Get_Encoder_countB--;
		}
		else
		{
			Get_Encoder_countB++;
		}
	}
	else if((gpio_interrup & ENCODERB_E2B_PIN)==ENCODERB_E2B_PIN)
	{
		if(!DL_GPIO_readPins(GPIOA,ENCODERB_E2A_PIN))
		{
			Get_Encoder_countB++;
		}
		else
		{
			Get_Encoder_countB--;
		}
	}
	DL_GPIO_clearInterruptStatus(GPIOA,ENCODERA_E1A_PIN|ENCODERA_E1B_PIN|ENCODERB_E2A_PIN|ENCODERB_E2B_PIN);
}
