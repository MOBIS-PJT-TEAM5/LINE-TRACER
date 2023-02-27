#include "config.h"
#include "line_trace.h"
#include "AFMotor.h"
#include "Motor_move.h"
#include "button_control.h"

/**
 * 속도 관련 전역 변수
 * SPEED : 현재의 속력
 * LAST_CUR_STATE : 현재 차체의 상태(왼쪽 or 오른쪽)
 * REVERSE_SPEED
 */
int CUR_SPEED = INITIAL_SPEED;
int LAST_CUR_STATE = 0;

/**
 * 버튼 제어 관련 전역 변수
 * MODE_CNT : 모드버튼을 얼마나 길게 눌렀는가를 제어하기 위한 변수
 * STOP_CNT : 정지버튼을 얼마나 길게 눌렀는가를 제어하기 위한 변수
 * IS_SCC : 현재 모드가 SCC인지(true) 일반모드인지(false)
 * IS_STOP : 현재 정지상태인지(true) 주행상태인지(false)
 */
int MODE_CNT = 0;
int STOP_CNT = 0;
bool IS_SCC = false;
bool IS_STOP = false;

AF_DCMotor Lmotor(LMotor);
AF_DCMotor Rmotor(RMotor);

void setup() {
  // put your setup code here, to run once:
  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IR_Sensor, INPUT);
  pinMode(MODE_BUTTON, INPUT);
  pinMode(STOP_BUTTON, INPUT);
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
  // SmartCruise(Lmotor, Rmotor, IRL, IRR, IR_Sensor);
  // MV(Lmotor, Rmotor, 130, 130, 1, 1);
  // Serial.println(digitalRead(servo1));
  // delay(100);

  // 버튼 제어
  pushBtn(MODE_BUTTON, MODE_CNT, IS_SCC);
  pushBtn(STOP_BUTTON, STOP_CNT, IS_STOP);

  if (IS_STOP) 
  {
    Lmotor.run(RELEASE);
    Rmotor.run(RELEASE);
  } 
  else 
  {
    if (IS_SCC) 
    {
      SmartCruise(Lmotor, Rmotor, IRL, IRR, IR_Sensor);
    } 
    else 
    {
      lineTrace(Lmotor, Rmotor, IRL, IRR);
    }
  }
}