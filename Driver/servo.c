#include "servo.h"
#include "ti_msp_dl_config.h"

#define pwm_MID 1500					//小车直走时PID值(待验证)
#define pwm_MAX pwm_MID+500		//PID上下限，防止阿克曼转向机构损坏
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
 * 功能：设定小车方向
 * 输入：有符号实数 负数左拐，正数右拐
 */
void setDirection(int direction)
{
	setServoPWM(pwm_MID-direction);	//符合直觉
}