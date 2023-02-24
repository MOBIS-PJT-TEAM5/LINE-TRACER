#include "line_trace.h"
#include "AFMotor.h"
#include "Motor_move.h"

// 매개변수로 모터객체를 넣어서 그 모터가 검은색을 감지하면 true를 리턴하는 함수
bool is_detect(int motor) {
  if (analogRead(motor) > 300) return true;
  else return false;
}

int last_state = 0;
int reverse_speed = 110;

void line_trace(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin, int speed) {
  if (is_detect(Lpin) && is_detect(Rpin)) 
    // AF_DCMotor L, AF_DCMotor R, int speed_L, int speed_R, bool left_front, bool right_front
    {
      MV(L, R, speed, speed, true, true);
      // Serial.print(analogRead(Lpin));
      // Serial.print(" ");
      // Serial.println(analogRead(Rpin));
    }

  else if (!is_detect(Lpin) && is_detect(Rpin)) {
    // 오른쪽만 감지시 좌회전
    MV(L, R, speed, reverse_speed, true, false);
    last_state = 0;
    // Serial.print(analogRead(Lpin));
    // Serial.print(" ");
    // Serial.println(analogRead(Rpin));
  } 
  else if (is_detect(Lpin) && !is_detect(Rpin)) {
    MV(L, R, reverse_speed, speed, false, true);
    last_state = 1;
    // Serial.print(analogRead(Lpin));
    // Serial.print(" ");
    // Serial.println(analogRead(Rpin));
  }
  else {
    // Serial.print(analogRead(Lpin));
    // Serial.print(" ");
    // Serial.println(analogRead(Rpin));
    if (last_state == 0) MV(L, R, speed, reverse_speed, true, false);
    else if (last_state == 1) MV(L, R, reverse_speed, speed, false, true);
  }
}