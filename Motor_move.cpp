
#include "AFMotor.h"
#include "Motor_move.h"

void MV( AF_DCMotor L, AF_DCMotor R, int speed_L, int speed_R, bool left_front, bool right_front ){
  
  if ( left_front == true ) L.run(BACKWARD);
  if ( right_front == true ) R.run(FORWARD);
  if ( left_front == false ) L.run(FORWARD);
  if ( right_front == false ) R.run(BACKWARD);

  L.setSpeed( speed_L );
  R.setSpeed( speed_R );  

}