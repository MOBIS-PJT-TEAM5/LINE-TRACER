#ifndef _LineTrace_h_
#define _LineTrace_h_

#include "AFMotor.h"
#include "Motor_move.h"
#include <Arduino.h>

void line_trace(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin);

#endif 