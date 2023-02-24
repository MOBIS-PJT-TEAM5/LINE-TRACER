#include "SmartCruise.h"
#include <SoftwareSerial.h>
#include <Arduino.h>
#include "AFMotor.h"
#include "Motor_move.h"
#include "line_trace.h"

#define max_speed 120
#define slow_mulitple 0.2
#define fast_plus 5
#define IR_sensor_threshold 500
//참조 _ network slowstart


void SmartCruise ( AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin, int now_speed, int IR_Sensor ){
  
  int change_speed = now_speed;
  if ( analogRead (IR_Sensor) < IR_sensor_threshold ){
    change_speed *= slow_mulitple;
    line_trace(L, R, Lpin, Rpin, change_speed);
    //return change_speed;
  } else {
    change_speed += fast_plus;
    change_speed = (change_speed > max_speed) ?  max_speed : change_speed;
    line_trace(L, R, Lpin, Rpin, change_speed);
    //return change_speed;
  }

}
