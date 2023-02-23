#include "SmartCruise.h"

#define max_speed 120;
#define slow_mulitple 0.2;
#define fast_multiple 1.2;
//참조 _ network slowstart

int SmartCruise_slowly ( int now_speed ){
  int change_speed = now_speed;
  if ( analogRead(IR_sensor) < 500 ){
    change_speed *= slow_mulitple;
    return change_speed;
  } else {
    change_speed *= fast_multiple;
    change_speed = (change_speed > max_speed) ?  max_speed : change_speed;
    return change_speed;
  }
}