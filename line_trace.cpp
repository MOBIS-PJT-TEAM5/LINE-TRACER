#include <SoftwareSerial.h>
#include <Arduino.h>
#include "AFMotor.h"
#include "Motor_move.h"
#include "line_trace.h"
#include "config.h"
#include "led_control.h"

extern int CUR_SPEED;
extern int LAST_CUR_STATE;

extern int FR_LED_STATE;
extern int FL_LED_STATE;
extern int BR_LED_STATE;
extern int BL_LED_STATE;
extern unsigned long PREVIOUS_MILLIS;
extern unsigned long CURRENT_MILLIS;

void SmartCruise(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin, int IR_Sensor){
    if (analogRead (IR_Sensor) < IR_SENSOR_THRESHOLD){
        CUR_SPEED *= SLOW_MULTIPLE;
        BR_LED_STATE = ON;
        BL_LED_STATE = ON;
    }
    else
    {
        CUR_SPEED += FAST_PLUS;
        CUR_SPEED = (CUR_SPEED > MAX_SPEED) ?  MAX_SPEED : CUR_SPEED;
        BR_LED_STATE = OFF;
        BL_LED_STATE = OFF;
    }
    lineTrace(L, R, Lpin, Rpin);
}



// 매개변수로 모터객체를 넣어서 그 모터가 검은색을 감지하면 true를 리턴하는 함수
bool isDetect(int motor) {
    return analogRead(motor) > IR_LINE_THRESHOLD;
}


void lineTrace(AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin) {
  if(isDetect(Lpin) && isDetect(Rpin))//둘 다 감지시 직진
  {
    FR_LED_STATE = ON;
    FL_LED_STATE = ON;
    BR_LED_STATE = OFF;
    BL_LED_STATE = OFF;
    MV(L, R, CUR_SPEED, CUR_SPEED, true, true);
  }
  else if(!isDetect(Lpin) && isDetect(Rpin)) {// 오른쪽만 감지시 우회전
    FR_LED_STATE = BLINK;
    FL_LED_STATE = OFF;
    BR_LED_STATE = BLINK;
    BL_LED_STATE = OFF;
    MV(L, R, CUR_SPEED, REVERSE_SPEED, true, false);
    LAST_CUR_STATE = 0;
  } 
  else if (isDetect(Lpin) && !isDetect(Rpin)) {// 왼쪽만 감지시 좌회전
    FR_LED_STATE = OFF;
    FL_LED_STATE = BLINK;
    BR_LED_STATE = OFF;
    BL_LED_STATE = BLINK;
    MV(L, R, REVERSE_SPEED, CUR_SPEED, false, true);
    LAST_CUR_STATE = 1;
  }
  else {//둘다 흰색 감지시 recovery
    if(LAST_CUR_STATE == 0) {
      FR_LED_STATE = BLINK;
      FL_LED_STATE = OFF;
      BR_LED_STATE = BLINK;
      BL_LED_STATE = OFF;
      MV(L, R, CUR_SPEED, REVERSE_SPEED, true, false);
    }
    else if (LAST_CUR_STATE == 1) {
      FR_LED_STATE = OFF;
      FL_LED_STATE = BLINK;
      BR_LED_STATE = OFF;
      BL_LED_STATE = BLINK; 
      MV(L, R, REVERSE_SPEED, CUR_SPEED, false, true);
    }
  }
}