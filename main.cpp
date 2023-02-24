#include "line_trace.h"
#include "AFMotor.h"
#include "Motor_move.h"
#include "SmartCruise.h"
#define IRL 0
#define IRR 5
#define IR_Sensor A3

AF_DCMotor Lmotor(2);
AF_DCMotor Rmotor(1);

void setup() {
  // put your setup code here, to run once:
  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IR_Sensor, INPUT);
  Serial.begin(9600);
  Lmotor.setSpeed(255);    // 모터 1 속도 설정
  Lmotor.run(RELEASE);     // 모터 1 돌리지 않는 상태
  Rmotor.setSpeed(255);    // 모터 1 속도 설정
  Rmotor.run(RELEASE);     // 모터 1 돌리지 않는 상태
}
int speed = 150;
void loop() {
  // delay(400);
  // Serial.println(analogRead(IR_Sensor));
  // line_trace(Lmotor, Rmotor, IRL, IRR, 130);
  speed = SmartCruise(Lmotor, Rmotor, IRL, IRR, speed, IR_Sensor);
  // MV(Lmotor, Rmotor, 130, 130, 1, 1);
  // Serial.println(digitalRead(servo1));
  // delay(100);
}