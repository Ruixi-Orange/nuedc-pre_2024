#include "motor.h"

struct motorPID
{
float Kp;
float Ki;
float	Kd; //相关速度PID参数
}Velcity = {1.0, 0.5, 0};

int VelocityA(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;
		static int ControlVelocityA, LastBiasA; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityA+=Velcity.Ki*(Bias-LastBiasA)+Velcity.Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		LastBiasA=Bias;	
	  
		if(ControlVelocityA>8000) ControlVelocityA=8000;
	  else if(ControlVelocityA<-8000) ControlVelocityA=-8000;
		return ControlVelocityA; //返回速度控制值
}

/***************************************************************************
函数功能：电机的PID闭环控制
入口参数：左右电机的编码器值
返回值  ：电机的PWM
***************************************************************************/
int VelocityB(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;
		static int ControlVelocityB, LastBiasB; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityB+=Velcity.Ki*(Bias-LastBiasB)+Velcity.Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		LastBiasB=Bias;	
	  
		if(ControlVelocityB>8000) ControlVelocityB=8000;
	  else if(ControlVelocityB<-8000) ControlVelocityB=-8000;
		return ControlVelocityB; //返回速度控制值
}

void SetMotorPWM(int pwma,int pwmb)
{
	//PA12接AIN2,PA13接AIN1,PA14接PWMA
	//PB15接BIN1,PB16接BIN2,PB17接PWMB
	
	if(pwma>8000)	pwma=8000;
	else if(pwma<-8000)	pwma=-8000;
	
	if(pwmb>8000) pwmb=8000;
	else if(pwmb<-8000)	pwmb=-8000;
	
	if(pwma>0) 
	{
		DL_GPIO_setPins(AIN_PORT,AIN_AIN1_PIN);
		DL_GPIO_clearPins(AIN_PORT,AIN_AIN2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_A_INST,pwma,GPIO_PWM_MOTOR_A_C0_IDX);
	}
	else
	{
		DL_GPIO_clearPins(AIN_PORT,AIN_AIN1_PIN);
		DL_GPIO_setPins(AIN_PORT,AIN_AIN2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_A_INST,-pwma,GPIO_PWM_MOTOR_A_C0_IDX);
	}
	
	if(pwmb>0) 
	{
		DL_GPIO_setPins(BIN_PORT,BIN_BIN1_PIN);
		DL_GPIO_clearPins(BIN_PORT,BIN_BIN2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_B_INST,pwmb,GPIO_PWM_MOTOR_B_C0_IDX);
	}
	else
	{
		DL_GPIO_clearPins(BIN_PORT,BIN_BIN1_PIN);
		DL_GPIO_setPins(BIN_PORT,BIN_BIN2_PIN);
		DL_TimerG_setCaptureCompareValue(PWM_MOTOR_B_INST,-pwmb,GPIO_PWM_MOTOR_B_C0_IDX);
	}

}



