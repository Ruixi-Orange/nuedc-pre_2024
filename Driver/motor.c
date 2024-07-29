#include "motor.h"
float Velcity_Kp=1.0,  Velcity_Ki=0.5,  Velcity_Kd; //相关速度PID参数

int Velocity_A(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //定义相关变量
		static int ControlVelocityA, Last_biasA; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityA+=Velcity_Ki*(Bias-Last_biasA)+Velcity_Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		Last_biasA=Bias;	
	    if(ControlVelocityA>3600) ControlVelocityA=3600;
	    else if(ControlVelocityA<-3600) ControlVelocityA=-3600;
		return ControlVelocityA; //返回速度控制值
}

/***************************************************************************
函数功能：电机的PID闭环控制
入口参数：左右电机的编码器值
返回值  ：电机的PWM
***************************************************************************/
int Velocity_B(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //定义相关变量
		static int ControlVelocityB, Last_biasB; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityB+=Velcity_Ki*(Bias-Last_biasB)+Velcity_Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		Last_biasB=Bias;	
	    if(ControlVelocityB>3600) ControlVelocityB=3600;
	    else if(ControlVelocityB<-3600) ControlVelocityB=-3600;
		return ControlVelocityB; //返回速度控制值
}

void Set_PWM(int pwma,int pwmb)
{
	//在使用我司的D153C驱动模块的时候，PA12接AIN2、PA13解AIN1,PB16接BIN2、PB0接着BIN1
	if(pwma>0) 
	{
		DL_GPIO_setPins(AIN1_PORT,AIN1_PIN_12_PIN);
		DL_GPIO_clearPins(AIN2_PORT,AIN2_PIN_13_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwma),GPIO_PWM_0_C0_IDX);
	}
	else
	{
		DL_GPIO_setPins(AIN2_PORT,AIN2_PIN_13_PIN);
		DL_GPIO_clearPins(AIN1_PORT,AIN1_PIN_12_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwma),GPIO_PWM_0_C0_IDX);
	}
	if(pwmb>0)
	{
		DL_GPIO_setPins(BIN1_PORT,BIN1_Pin_Bin1_PIN);
		DL_GPIO_clearPins(BIN2_PORT,BIN2_Pin_Bin2_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwmb),GPIO_PWM_0_C1_IDX);
	}
    else
	{
		DL_GPIO_setPins(BIN2_PORT,BIN2_Pin_Bin2_PIN);
		DL_GPIO_clearPins(BIN1_PORT,BIN1_Pin_Bin1_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwmb),GPIO_PWM_0_C1_IDX);
	}		

}



