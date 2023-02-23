#include "line_trace.h"
#include "AFMotor.h"
#include "Motor_move.h"
#define IRL 0
#define IRR 5

AF_DCMotor Lmotor(IRL);
AF_DCMotor Rmotor(IRR);
//int speed = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  Serial.begin(9600);
  Lmotor.setSpeed(255);    // 모터 1 속도 설정          
  Lmotor.run(RELEASE);     // 모터 1 돌리지 않는 상태
  Rmotor.setSpeed(255);    // 모터 1 속도 설정          
  Rmotor.run(RELEASE);     // 모터 1 돌리지 않는 상태
}

void loop() {
  line_trace(Lmotor, Rmotor, IRL, IRR);
}