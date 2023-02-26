#include "config.h"
#include "line_trace.h"
#include "AFMotor.h"
#include "Motor_move.h"
#include "led_control.h"

/**
 * 속도 관련 전역 변수
 * SPEED : 현재의 속력
 * LAST_CUR_STATE : 현재 차체의 상태(왼쪽 or 오른쪽)
 * REVERSE_SPEED
 */
int CUR_SPEED = INITIAL_SPEED;
int LAST_CUR_STATE = 0;

/**
 * LED 관련 전역 변수
 * ~_LED_STATE : 각 LED의 상태 (OFF, ON, BLINK)
 * PREVIOUS_MILLIS : 깜빡임 구현시 가장 최근 상태 바뀌었을 때의 시간을 저장
 * CURRENT_MILLIS : 현재 시간을 저장
 * CLOCK_STATE : 프로그램 실행중 INTERVAL 간격으로 1, 0상태를 반복
 */
int FR_LED_STATE = OFF;
int FL_LED_STATE = OFF;
int BR_LED_STATE = OFF;
int BL_LED_STATE = OFF;
unsigned long PREVIOUS_MILLIS = 0;
unsigned long CURRENT_MILLIS = 0;
int CLOCK_STATE = LOW;

AF_DCMotor Lmotor(LMotor);
AF_DCMotor Rmotor(RMotor);

void setup() {
  // put your setup code here, to run once:
  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IR_Sensor, INPUT);
  pinMode(FR_LED, OUTPUT);
  pinMode(FL_LED, OUTPUT);
  pinMode(BR_LED, OUTPUT);
  pinMode(BL_LED, OUTPUT);
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
  clock();
  ledControl(FR_LED, FR_LED_STATE);
  ledControl(FL_LED, FL_LED_STATE);
  ledControl(BR_LED, BR_LED_STATE);
  ledControl(BL_LED, BL_LED_STATE);
  
  SmartCruise(Lmotor, Rmotor, IRL, IRR, IR_Sensor);
  // MV(Lmotor, Rmotor, 130, 130, 1, 1);
  // Serial.println(digitalRead(servo1));
  // delay(100);
}