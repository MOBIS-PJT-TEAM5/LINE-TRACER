#ifndef _MotorMove_h_
#define _MotorMove_h_

#include "AFMotor.h"

/**
 * 모터를 구동시키는 기본 함수
 * @param L 왼쪽 모터 객체
 * @param R 오른쪽 모터 객체
 * @param speed_L 왼쪽 모터 스피드
 * @param speed_R 오른쪽 모터 스피드
 * @param left_front 왼쪽 모터 가동 여부
 * @param right_front 오른쪽 모터 가동 여부
 */
void MV(AF_DCMotor& L, AF_DCMotor& R, int speed_L, int speed_R, bool left_front, bool right_front);

#endif 
