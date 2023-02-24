#include "config.h"
#include "line_trace.h"
#include "AFMotor.h"
#include "Motor_move.h"

/**
 * 속도 관련 전역 변수
 * SPEED : 현재의 속력
 * LAST_CUR_STATE : 현재 차체의 상태(왼쪽 or 오른쪽)
 * REVERSE_SPEED
 */
int CUR_SPEED = INITIAL_SPEED;
int LAST_CUR_STATE = 0;


AF_DCMotor Lmotor(LMotor);
AF_DCMotor Rmotor(RMotor);

void setup() {
  // put your setup code here, to run once:
  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IR_Sensor, INPUT);
  Serial.begin(9600);
  Lmotor.setSpeed(INITIAL_SPEED);    // 모터 1 속도 설정
  Lmotor.run(RELEASE);     // 모터 1 돌리지 않는 상태
  Rmotor.setSpeed(INITIAL_SPEED);    // 모터 1 속도 설정
  Rmotor.run(RELEASE);     // 모터 1 돌리지 않는 상태
}

void loop() {
  // delay(400);
  // Serial.println(analogRead(IR_Sensor));
  // line_trace(Lmotor, Rmotor, IRL, IRR, 130);
  SmartCruise(Lmotor, Rmotor, IRL, IRR, IR_Sensor);
  // MV(Lmotor, Rmotor, 130, 130, 1, 1);
  // Serial.println(digitalRead(servo1));
  // delay(100);
}