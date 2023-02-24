#include "sound_sensor.h"
#include <Arduino_AVRSTL.h>
#include "Motor_move.h"
#include "AFMotor.h"
#include "line_trace.h"

#define threshold_SS 500 // 소리 센서 Db threshold
#define sound_vec_size 80 // sound_vector maximum size
#define percent_sound 0.2 // 전체 vector item 중, threshold를 넘은 비율 정지상태로 가기 위한 퍼센트
#define percent_sound2 0.01 // 전체 vector item 중, threshold를 넘은 비율 정지상태에서 벗어나기 위한 퍼센트
#define speed2 125 //갓길로 갈 때 주행 속도 
#define dt 500

using namespace std;

vector<int>sound_vec;
int over_sound = 0;

void hear_emergency(AF_DCMotor &Lmotor, AF_DCMotor &Rmotor, int speed, int soundSensor){

  sound_vec.push_back(analogRead(soundSensor));

  //Serial.println(analogRead(soundSensor));//code for test
  
  //벡터 사이즈 조절
  if ( sound_vec.size() == sound_vec_size ){ sound_vec.erase(sound_vec.begin());}

  //벡터안에 몇퍼센트가 소리가 들린다고 하는지..
  over_sound = count_if(sound_vec.begin(), sound_vec.end(),[](int i){return i < threshold_SS;});
  
  //percent_sound 이상으로 들어가 있다면, 움직이기
  if ( ((double)over_sound / (double)sound_vec.size()) >= percent_sound ) {
    Serial.println("over percent");
    Serial.println(((double)over_sound / (double)sound_vec.size()));
      
    Serial.println("응급차량이 오고 있다고 판단");

    Serial.println("차량 우측으로");
    MV(Lmotor, Rmotor, speed2, 0, true, true); // 우회전
    delay(dt);
    Serial.println("차량 front");
    MV(Lmotor, Rmotor, speed2, speed2, true, true);//직진
    delay(dt);
     Serial.println("차량 left");    
    MV(Lmotor, Rmotor, 0, speed2, true, true); // 좌회전
    delay(dt);
     Serial.println("차량 정지");
    MV(Lmotor, Rmotor, 0, 0, true, true); // 정지
    delay(dt);
    
    while(true){ //소리 안들릴 때까지 정지, 무한루프
      Serial.println("정지상태");
      //Serial.println(analogRead(soundSensor));//code for test
      sound_vec.push_back(analogRead(soundSensor));
      //벡터 사이즈 조절
      if ( sound_vec.size() == sound_vec_size ){ sound_vec.erase(sound_vec.begin());}

      over_sound = count_if(sound_vec.begin(), sound_vec.end(),[](int i){return i < threshold_SS;});
      if ( ((double)over_sound / (double)sound_vec.size()) < percent_sound2 )
      {
        Serial.println("under percent");
        Serial.println(((double)over_sound / (double)sound_vec.size()));
        break;  
      }
    }
    
    Serial.println("차량 제자리로1");
    MV(Lmotor, Rmotor, 0, speed2, true, true); // 좌회전
    delay(dt);

    Serial.println("차량 제자리로2");
    MV(Lmotor, Rmotor, speed2, speed2, true, true);//직진
    delay(dt);

    Serial.println("차량 제자리로3");
    MV(Lmotor, Rmotor, speed2, 0, true, true); // 우회전
    delay(dt);

    fill(sound_vec.begin(), sound_vec.end(), 1000);

  }

}