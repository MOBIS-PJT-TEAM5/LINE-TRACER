#include "line_trace.h"
#include "AFMotor.h"

// 매개변수로 모터객체를 넣어서 그 모터가 검은색을 감지하면 true를 리턴하는 함수
bool is_detect(int motor) {
  if (analogRead(motor) > 300) return true;
  else return false;
}

int last_state = 0;

void line_trace(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin) {
  if (is_detect(Lpin) && is_detect(Rpin)) 
    // AF_DCMotor L, AF_DCMotor R, int speed_L, int speed_R, bool left_front, bool right_front
    {
      MV(L, R, 160, 160, true, true);
      Serial.println("both");
    }

  else if (!is_detect(Lpin) && is_detect(Rpin)) {
    // 오른쪽만 감지시 우회전
    MV(L, R, 90, 160, true, true);
    last_state = 0;
    Serial.println("right");
  } 
  else if (is_detect(Lpin) && !is_detect(Rpin)) {
    MV(L, R, 160, 90, true, true);
    last_state = 1;
    Serial.println("left");
  }
  else {
    Serial.println("no");
    if (last_state == 0) MV(L, R, 90, 200, true, true);
    else if (last_state == 1) MV(L, R, 200, 90, true, true);
  }
}