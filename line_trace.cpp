#include "line_trace.h"
#include "AFMotor.h"
#include "Motor_move.h"
#define 

// 매개변수로 모터객체를 넣어서 그 모터가 검은색을 감지하면 true를 리턴하는 함수
bool is_detect(int motor) {
  if (analogRead(motor) > 300) return true;
  else return false;
}

int last_state = 0;

void line_trace(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin) {
  int speed = 50;
  if (is_detect(Lpin) && is_detect(Rpin)) 
    // AF_DCMotor L, AF_DCMotor R, int speed_L, int speed_R, bool left_front, bool right_front
    {
      MV(L, R, speed, speed, true, true);
      Serial.print(analogRead(Lpin));
      Serial.print(" ");
      Serial.println(analogRead(Rpin));
    }

  else if (!is_detect(Lpin) && is_detect(Rpin)) {
    // 오른쪽만 감지시 우회전
    MV(L, R, speed, 0, true, true);
    last_state = 0;
    Serial.print(analogRead(Lpin));
    Serial.print(" ");
    Serial.println(analogRead(Rpin));
  } 
  else if (is_detect(Lpin) && !is_detect(Rpin)) {
    MV(L, R, 0, speed, true, true);
    last_state = 1;
    Serial.print(analogRead(Lpin));
    Serial.print(" ");
    Serial.println(analogRead(Rpin));
  }
  else {
    Serial.print(analogRead(Lpin));
    Serial.print(" ");
    Serial.println(analogRead(Rpin));
    if (last_state == 0) MV(L, R, speed, 0, true, true);
    else if (last_state == 1) MV(L, R, 0, speed, true, true);
  }
}