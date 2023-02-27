#include "sound_sensor.h"

int value_sound = 0;
int point_sound = 0;

void hear_emergency(AF_DCMotor &Lmotor, AF_DCMotor &Rmotor, int Lpin, int Rpin, int Sound_Sensor){

  lineTrace(Lmotor, Rmotor, Lpin, Rpin); //기본 주행

  value_sound = analogRead(Sound_Sensor);
  point_sound +=  ( (value_sound < SOUND_HEAR) ? PLUS_POINT : MINUS_POINT );   //들리면 + 100, 안들리면 -1
  
  if (point_sound > THRESHOLD_SS_1) { 

    Serial.println("Car go STOP");
    MV(Lmotor, Rmotor, 0,0, true, true); // 정지
    delay(200);

    Serial.println("Car go right side");
    MV(Lmotor, Rmotor, SPEED_LOW, 0, true, true); // 우회전
    delay(ROTATE_TIME);
    MV(Lmotor, Rmotor, SPEED_LOW, SPEED_LOW, true, true);//직진
    delay(STRAIGHT_TIME); 
    MV(Lmotor, Rmotor, 0,SPEED_LOW, true, true); // 좌회전
    delay(ROTATE_TIME2);

    Serial.println("Car go STOP");
    MV(Lmotor, Rmotor, 0,0, true, true); // 정지
    delay(1000);
    while(true){ //소리 안들릴 때까지 정지, 무한루프
      Serial.println("Car stopped - in while loop");
      value_sound = analogRead(Sound_Sensor);
      //point_sound =  ( (value_sound < SOUND_HEAR) ? (point_sound+PLUS_POINT) : (point_sound*MINUS_POINT_MULTIPLE) );   //들리면 + 100, 안들리면 *0.6
      point_sound +=  ( (value_sound < SOUND_HEAR) ? PLUS_POINT : MINUS_POINT );   //들리면 + 100, 안들리면 -1
      if (point_sound < THRESHOLD_SS_2) break; // 300이 20보다 작아지면 안들린다고 판단 
    }
    
    Serial.println("Car go back to road");
    MV(Lmotor, Rmotor, 0, SPEED_LOW, true, true); // 좌회전
    delay(ROTATE_TIME2);
    MV(Lmotor, Rmotor, SPEED_LOW, SPEED_LOW, true, true);//직진
    delay(STRAIGHT_TIME-300); 
    MV(Lmotor, Rmotor, SPEED_LOW, 0, true, true); // 우회전
    delay(ROTATE_TIME4);
    MV(Lmotor, Rmotor, 0, 0, true, true); //정지
    delay(1000);
  }
}