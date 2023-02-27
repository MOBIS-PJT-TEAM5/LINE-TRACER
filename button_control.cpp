#include "config.h"
#include "button_control.h"
#include <Arduino.h>

bool isButtonPushed(int pin) {
  int value = analogRead(pin);
  // Serial.println(temp);
  if (value > BUTTON_PUSH_THRESHOLD) {
    return true;
  } else 
    return false;
}

/*
  cnt는 버튼이 눌리지 않을때는 항상 0을 유지함
  버튼이 눌려져 있을때는 1씩 증가하며 쌓임
  config에서 설정한 BUTTON_PUSH_TIME만큼 cnt가 쌓이는 순간 버튼이 눌렸다고 인정하고 상태를 변경
*/
void pushBtn(int pin, int& cnt, int& state){
  if (isButtonPushed(pin)) {
    cnt ++;
    if (cnt == BUTTON_PUSH_TIME) {
      // stop_cnt = 0;
      state = (state + 1) % 3;
      // Serial.print(pin);
      // Serial.print("버튼누름 ");
      // Serial.println(state);
    }
  } else {
    cnt = 0;
  }
}

void pushStopBtn(int pin, int& cnt, bool& state){
  if (isButtonPushed(pin)) {
    cnt ++;
    if (cnt == BUTTON_PUSH_TIME) {
      // stop_cnt = 0;
      state = !state;
      // Serial.print(pin);
      // Serial.print("버튼누름 ");
      // Serial.println(state);
    }
  } else {
    cnt = 0;
  }
}

/*
  회로수정후 테스트 필요
*/

// unsigned long lastDebounceTime = 0;
// unsigned long debounceDelay = 50; //바운싱현상이 심한 스위치를 사용하는 경우에는 debounceDelay 값을 더 크게

// void pushBtn2(int pin, &state){
//   bool reading = isButtonPushed(pin);

//   if (reading != state)  //스위치의 이전과 지금 상태가 다르면
//     lastDebounceTime = millis();   //초를 기록

//   if ((millis() - lastDebounceTime) > debounceDelay) 
//   {//초가 기록되는 차이가 50ms보다 크면 (안정화가 됐다고 판단되면)
//     if (reading != state) 
//     {
//       state = reading;  //스위치를 누른 값과 다르면 대입
//     }
//   }
//   state = reading;
// }

