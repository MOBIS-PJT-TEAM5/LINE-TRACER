#include "sound_sensor.h"

#define threshold_SS_1 300 // 소리 센서 Db threshold
#define threshold_SS_2 0 // 소리 센서 Db threshold
#define sound_hear 500 // 500보다 적은 숫자로 입력받으면, 소리가 들리는 것으로 판단.
#define plus_point 100
#define minus_point -1
#define speed_low 125 //갓길로 갈 때 주행 속도 
#define rotate_time 500
#define straight_time 500

//bool do_test = false; //한번만 작동하도록
int value_sound = 0;
int point_sound = 0;

void hear_emergency(AF_DCMotor &Lmotor, AF_DCMotor &Rmotor, int speed, int soundSensor){

  //if (do_test == true){ // 한번만 작동하도록
  Serial.println(analogRead(soundSensor));//code for test
  value_sound = analogRead(soundSensor);

  point_sound +=  ( (value_sound < sound_hear) ? plus_point : minus_point );   //들리면 + 100, 안들리면 -1
  
  if (point_sound > threshold_SS_1) { 
    
    Serial.println("Car go right side");
    MV(Lmotor, Rmotor, speed_low, 0, true, true); // 우회전
    delay(rotate_time);
    MV(Lmotor, Rmotor, speed_low, speed_low, true, true);//직진
    delay(straight_time); 
    MV(Lmotor, Rmotor, 0, speed_low, true, true); // 좌회전
    delay(rotate_time);
    

    Serial.println("Car stopped");
    MV(Lmotor, Rmotor, 0, 0, true, true); // 정지

    while(true){ //소리 안들릴 때까지 정지, 무한루프
      Serial.println("Car stopped - in while loop");
     
      point_sound +=  ( (value_sound < sound_hear) ? plus_point : minus_point );   //들리면 + 100, 안들리면 -1
      if (point_sound < threshold_SS_2) break; // 300이 0보다 작아지면 안들린다고 판단 
    }
    
    Serial.println("Car go back to road");
    MV(Lmotor, Rmotor, 0, speed_low, true, true); // 좌회전
    delay(rotate_time);
    MV(Lmotor, Rmotor, speed_low, speed_low, true, true);//직진
    delay(straight_time); 
    MV(Lmotor, Rmotor, speed_low, 0, true, true); // 우회전
    delay(rotate_time);

    //do_test = true // 한번만 작동하도록  
    //} 
  }
}