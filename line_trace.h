#ifndef _LineTrace_h_
#define _LineTrace_h_

#include "AFMotor.h"
#include "Motor_move.h"
#include "config.h"
#include <Arduino.h>
/**
 * 스마트 크루즈 기능 (앞 차와의 간격 유지)
 * @param L 왼쪽 모터 객체
 * @param R 오른쪽 모터 객체
 * @param Lpin 라인 감지 왼쪽 센서 번호
 * @param Rpin 라인 감지 오른쪽 센서 번호
 * @param IR_Sensor 적외선 감지 센서 번호
 */
void SmartCruise(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin, int IR_Sensor);
/**
 * 기본 라인 트레이싱 기능
 * @param L 왼쪽 모터 객체
 * @param R 오른쪽 모터 객체
 * @param Lpin 라인 감지 왼쪽 센서 번호
 * @param Rpin 라인 감지 오른쪽 센서 번호
 */
void line_trace(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin);

#endif 