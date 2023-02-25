#ifndef _Sound_Sensor_h_
#define _Sound_Sensor_h_

#include <Arduino_AVRSTL.h>
#include "Motor_move.h"
#include "AFMotor.h"
#include "config.h"

/**
 * 스마트 크루즈 기능 (앞 차와의 간격 유지)
 * @param L 왼쪽 모터 객체
 * @param R 오른쪽 모터 객체
 * @param Sound_Sensor 사운드 감지 센서 번호
 */

void hear_emergency(AF_DCMotor &Lmotor, AF_DCMotor &Rmotor, int Sound_Sensor);

# endif