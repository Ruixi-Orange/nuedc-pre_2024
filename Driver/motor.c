#include "motor.h"
float Velcity_Kp=1.0,  Velcity_Ki=0.5,  Velcity_Kd; //����ٶ�PID����

int Velocity_A(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //������ر���
		static int ControlVelocityA, Last_biasA; //��̬�������������ý�������ֵ��Ȼ����
		
		Bias=TargetVelocity-CurrentVelocity; //���ٶ�ƫ��
		
		ControlVelocityA+=Velcity_Ki*(Bias-Last_biasA)+Velcity_Kp*Bias;  //����ʽPI������
                                                                   //Velcity_Kp*(Bias-Last_bias) ����Ϊ���Ƽ��ٶ�
	                                                                 //Velcity_Ki*Bias             �ٶȿ���ֵ��Bias���ϻ��ֵõ� ƫ��Խ����ٶ�Խ��
		Last_biasA=Bias;	
	    if(ControlVelocityA>3600) ControlVelocityA=3600;
	    else if(ControlVelocityA<-3600) ControlVelocityA=-3600;
		return ControlVelocityA; //�����ٶȿ���ֵ
}

/***************************************************************************
�������ܣ������PID�ջ�����
��ڲ��������ҵ���ı�����ֵ
����ֵ  �������PWM
***************************************************************************/
int Velocity_B(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //������ر���
		static int ControlVelocityB, Last_biasB; //��̬�������������ý�������ֵ��Ȼ����
		
		Bias=TargetVelocity-CurrentVelocity; //���ٶ�ƫ��
		
		ControlVelocityB+=Velcity_Ki*(Bias-Last_biasB)+Velcity_Kp*Bias;  //����ʽPI������
                                                                   //Velcity_Kp*(Bias-Last_bias) ����Ϊ���Ƽ��ٶ�
	                                                                 //Velcity_Ki*Bias             �ٶȿ���ֵ��Bias���ϻ��ֵõ� ƫ��Խ����ٶ�Խ��
		Last_biasB=Bias;	
	    if(ControlVelocityB>3600) ControlVelocityB=3600;
	    else if(ControlVelocityB<-3600) ControlVelocityB=-3600;
		return ControlVelocityB; //�����ٶȿ���ֵ
}

void SetMotorPWM(int pwma,int pwmb)
{
	//PA12��AIN2,PA13��AIN1,PA14��PWMA
	//PB15��BIN1,PB16��BIN2,PB17��PWMB
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



