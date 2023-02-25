#include "config.h"
#include "button_control.h"
#include <Arduino.h>

// extern int MODE_CNT;
// extern int STOP_CNT;
// extern bool IS_SCC;
// extern bool IS_STOP;

bool isButtonPushed(int pin) {
  int value = analogRead(pin);
  // Serial.println(temp);
  if (value > BUTTON_PUSH_THRESHOLD) {
    return true;
  } else 
    return false;
}

// void pushModeBtn(int pin) {
//   if (isButtonPushed(pin)) {
//     mode_cnt ++;
//     if (mode_cnt == BUTTON_PUSH_TIME) {
//       // mode_cnt = 0;
//       is_scc = !is_scc;
//       // Serial.println(cnt);
//       Serial.println("scc 누름");
//       Serial.println(is_scc);
//     }
//   } else {
//     mode_cnt = 0;
//   }
// }

// void pushStopBtn(int pin){
//   if (isButtonPushed(pin)) {
//     stop_cnt ++;
//     if (stop_cnt == BUTTON_PUSH_TIME) {
//       // stop_cnt = 0;
//       is_stop = !is_stop;
//       Serial.println("stop누름");
//       Serial.println(is_stop);
//     }
//   } else {
//     stop_cnt = 0;
//   }
// }

void pushBtn(int pin, &cnt, &state){
  if (isButtonPushed(pin)) {
    cnt ++;
    if (cnt == BUTTON_PUSH_TIME) {
      // stop_cnt = 0;
      state = !state;
      Serial.print(pin);
      Serial.print("버튼누름 ");
      Serial.println(state);
    }
  } else {
    cnt = 0;
  }
}