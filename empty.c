#include "ti_msp_dl_config.h"
#include "board.h"
#include "servo.h"
#include "motor.h"
#include "encoder.h"

int PWMA,PWMB,encoderA_cnt,encoderB_cnt;

void TIMER_0_INST_IRQHandler(void)
{
    //如果产生了定时器中断
    switch( DL_TimerG_getPendingInterrupt(ENCODER_TIM_INST) )
    {
        case DL_TIMER_IIDX_ZERO:
					encoderA_cnt = GetEncoderCountA;
			    encoderB_cnt = GetEncoderCountB;
					GetEncoderCountA = 0;//编码器计数值清零
			    GetEncoderCountB = 0;
					PWMA = VelocityA(-15,encoderA_cnt);
			    PWMB = VelocityB(-15,encoderB_cnt);
			    SetMotorPWM(PWMA,PWMB);
            break;

        default:
            break;
    }
}

int main(void)
{
    
  SYSCFG_DL_init();
	delay_ms(0);
	setDirection(0);
	SetMotorPWM(8000,8000);
	delay_ms(1000);
  while (1) 
  {
		//SetMotorPWM(0,0);
  }
}






