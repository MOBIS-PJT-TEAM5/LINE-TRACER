
#include "AFMotor.h"
#include "Motor_move.h"
#include <SoftwareSerial.h>
#include <Arduino.h>

void MV( AF_DCMotor &L, AF_DCMotor &R, int speed_L, int speed_R, bool left_front, bool right_front ){
  // Serial.println("----------");
  // Serial.println(speed_L);
  // Serial.println(speed_R);
  // Serial.println(left_front);
  // Serial.println(right_front);

  left_front == false ? L.run(BACKWARD) : L.run(FORWARD);
  right_front == false ? R.run(BACKWARD) : R.run(FORWARD);

  L.setSpeed( speed_L );
  R.setSpeed( speed_R );  

}