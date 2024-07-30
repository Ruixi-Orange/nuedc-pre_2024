#include "motor.h"

struct motorPID
{
float Kp;
float Ki;
float	Kd; //����ٶ�PID����
}Velcity = {1.0, 0.5, 0};

int VelocityA(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;
		static int ControlVelocityA, LastBiasA; //��̬�������������ý�������ֵ��Ȼ����
		
		Bias=TargetVelocity-CurrentVelocity; //���ٶ�ƫ��
		
		ControlVelocityA+=Velcity.Ki*(Bias-LastBiasA)+Velcity.Kp*Bias;  //����ʽPI������
                                                                   //Velcity_Kp*(Bias-Last_bias) ����Ϊ���Ƽ��ٶ�
	                                                                 //Velcity_Ki*Bias             �ٶȿ���ֵ��Bias���ϻ��ֵõ� ƫ��Խ����ٶ�Խ��
		LastBiasA=Bias;	
	  
		if(ControlVelocityA>8000) ControlVelocityA=8000;
	  else if(ControlVelocityA<-8000) ControlVelocityA=-8000;
		return ControlVelocityA; //�����ٶȿ���ֵ
}

/***************************************************************************
�������ܣ������PID�ջ�����
��ڲ��������ҵ���ı�����ֵ
����ֵ  �������PWM
***************************************************************************/
int VelocityB(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;
		static int ControlVelocityB, LastBiasB; //��̬�������������ý�������ֵ��Ȼ����
		
		Bias=TargetVelocity-CurrentVelocity; //���ٶ�ƫ��
		
		ControlVelocityB+=Velcity.Ki*(Bias-LastBiasB)+Velcity.Kp*Bias;  //����ʽPI������
                                                                   //Velcity_Kp*(Bias-Last_bias) ����Ϊ���Ƽ��ٶ�
	                                                                 //Velcity_Ki*Bias             �ٶȿ���ֵ��Bias���ϻ��ֵõ� ƫ��Խ����ٶ�Խ��
		LastBiasB=Bias;	
	  
		if(ControlVelocityB>8000) ControlVelocityB=8000;
	  else if(ControlVelocityB<-8000) ControlVelocityB=-8000;
		return ControlVelocityB; //�����ٶȿ���ֵ
}

void SetMotorPWM(int pwma,int pwmb)
{
	//PA12��AIN2,PA13��AIN1,PA14��PWMA
	//PB15��BIN1,PB16��BIN2,PB17��PWMB
	
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



