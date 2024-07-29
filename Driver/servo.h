#ifndef _SERVO_H
#define _SERVO_H

#include "ti_msp_dl_config.h"
#include "board.h"


void servoInit();
void setServoPWM(uint16_t pwm);
void setDirection(int direction);

#endif