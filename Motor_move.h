#ifndef _MotorMove_h_
#define _MotorMove_h_

#include "AFMotor.h"

void MV(AF_DCMotor& L, AF_DCMotor& R, int speed_L, int speed_R, bool left_front, bool right_front);

#endif 
