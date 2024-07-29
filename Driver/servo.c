#include "servo.h"
#include "ti_msp_dl_config.h"

#define pwm_MID 1500					//С��ֱ��ʱPIDֵ(����֤)
#define pwm_MAX pwm_MID+500		//PID�����ޣ���ֹ������ת�������
#define pwm_MIN pwm_MID-500


int derection=0;

void setServoPWM(uint16_t pwm)
{
	if(pwm>pwm_MAX)
	{
		pwm=pwm_MAX;
	}
	else if(pwm<pwm_MIN)
	{
		pwm=pwm_MIN;
	}	
	DL_TimerG_setCaptureCompareValue(PWM_SERVO_INST,pwm,GPIO_PWM_SERVO_C0_IDX);
}

/**
 * ���ܣ��趨С������
 * ���룺�з���ʵ�� ������գ������ҹ�
 */
void setDirection(int direction)
{
	setServoPWM(pwm_MID-direction);	//����ֱ��
}