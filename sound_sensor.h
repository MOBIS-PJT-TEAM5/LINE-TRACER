#ifndef _Sound_sensor_h_
#define _Sound_sensor_h_

#include <Arduino_AVRSTL.h>
#include "Motor_move.h"
#include "AFMotor.h"
#include "line_trace.h"

void hear_emergency(AF_DCMotor &Lmotor, AF_DCMotor &Rmotor, int speed, int soundSensor);

# endif