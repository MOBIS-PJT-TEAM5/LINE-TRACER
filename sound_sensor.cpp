#include "sound_sensor.h"

//bool do_test = false; //한번만 작동하도록
int value_sound = 0;
int point_sound = 0;

void hear_emergency(AF_DCMotor &Lmotor, AF_DCMotor &Rmotor, int Sound_Sensor){

  //if (do_test == true){ // 한번만 작동하도록
  Serial.println(analogRead(Sound_Sensor));//code for test
  value_sound = analogRead(Sound_Sensor);

  point_sound +=  ( (value_sound < SOUND_HEAR) ? PLUS_POINT : MINUS_POINT );   //들리면 + 100, 안들리면 -1
  
  if (point_sound > THRESHOLD_SS_1) { 
    
    Serial.println("Car go right side");
    MV(Lmotor, Rmotor, SPEED_LOW, 0, true, true); // 우회전
    delay(ROTATE_TIME);
    MV(Lmotor, Rmotor, SPEED_LOW, SPEED_LOW, true, true);//직진
    delay(STRAIGHT_TIME); 
    MV(Lmotor, Rmotor, 0,SPEED_LOW, true, true); // 좌회전
    delay(ROTATE_TIME);
    

    Serial.println("Car stopped");
    MV(Lmotor, Rmotor, 0, 0, true, true); // 정지

    while(true){ //소리 안들릴 때까지 정지, 무한루프
      Serial.println("Car stopped - in while loop");
      value_sound = analogRead(Sound_Sensor);
      point_sound +=  ( (value_sound < SOUND_HEAR) ? PLUS_POINT : MINUS_POINT );   //들리면 + 100, 안들리면 -1
      if (point_sound < THRESHOLD_SS_2) break; // 300이 0보다 작아지면 안들린다고 판단 
    }
    
    Serial.println("Car go back to road");
    MV(Lmotor, Rmotor, 0, SPEED_LOW, true, true); // 좌회전
    delay(ROTATE_TIME);
    MV(Lmotor, Rmotor, SPEED_LOW, SPEED_LOW, true, true);//직진
    delay(STRAIGHT_TIME); 
    MV(Lmotor, Rmotor, SPEED_LOW, 0, true, true); // 우회전
    delay(ROTATE_TIME);

    //do_test = true // 한번만 작동하도록  
    //} 
  }
}