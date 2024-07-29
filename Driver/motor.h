#ifndef _MOTOR_H
#define _MOTOR_H

#include "ti_msp_dl_config.h"
#include "board.h"

int VelocityA(int TargetVelocity, int CurrentVelocity);
int VelocityB(int TargetVelocity, int CurrentVelocity);
void SetMotorPWM(int pwma,int pwmb);

#endif 