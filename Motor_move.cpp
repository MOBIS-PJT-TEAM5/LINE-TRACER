
#include "AFMotor.h"
#include "Motor_move.h"


void MV_forward(AF_DCMotor A,AF_DCMotor B){//전진 코드
    A.run(BACKWARD); B.run(FORWARD);
}

void MV_backward(AF_DCMotor A,AF_DCMotor B){//후진 코드
    A.run(FORWARD); B.run(BACKWARD);
}