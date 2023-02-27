 # :car: Safety goal 만족을 위한 자율주행 자동차 설계 
  <br>  
 
본 팀에서는 강의시간 중 학습한 ISO-26262 내용을 반영한, 자율주행 차량을 제작하고자 한다.
ISO-26262의 모든 과정을 거칠 수는 없어, 특정 situation에 한정하여 HARA및 Safty Goal 설정을
거쳐, Safty Goal들을 만족시킬 수 있는 개발을 진행할 것이다. 개발하고자 하는 **기능은 스마트
크루즈 컨트롤, 응급차량 주행 양보, 조향등 자동 점등, 차량 시동 및 모드 전환** 4가지 이다.
 <br>  
 
## :alarm_clock: **프로젝트 기간**
 <br>  
 
- 2023년 2월 23일 ~ 2023년 2월 28일
 <br>  
 
## :construction_worker: **팀원 및 역할**
 <br>  
 
- 이상묵
  - HW 조립 및 센서 성능개선
  - 라인 트레이싱 최적화
  - 스크럼 마스터
- 이세영
  - 크루즈 컨트롤 기능 개발
  - 응급차량 양보 기능 개발
  - 개요서, 발표 자료 작성
- 장영남
  - 라인트레이서 기능 개발
  - 시동 및 모드 전환 기능 개발
  - 조향등 자동 점등 기능 개발
 <br>  
 
## :pencil2: HARA 수행 및 Safty Goal 설정을 통한 기능추가
 <br>  
   
:star:**ISO-26262 HARA - Malfunction**
- MF1. 자율주행 차량이 전방차량과의 차간거리를 생각하지 않고 고속 주행을 하면 안된다.
  - S3 E3 C3 -> ASIL D
- MF2. 방향을 바꾸거나 브레이크 시에는 조향등을 켜야한다.
  - S2 E4 C2 -> ASIL B
- MF3. 운전자의 request없이 차량이 움직이면 안된다.
  - S3 E4 C2 -> ASIL B
- MF4. 응급차량이 다가오면 응급차량에게 주행을 양보해야 한다.
  - S0 E3 C0 -> QM
 <br>  
 
:star:**Safty Goal**  

:one: 전방 차량과의 충돌이 없이 거리를 일정하게 유지하도록 하는 스마트 크루즈 기능 개발  
:two: 운전자의 상태를 후방차량이 알 수 있도록 조향등 자동 점등  
:three:차량이 운전자의 의도와 상관없이 주행을 시작하지 않도록 차량 시동 및 모드 전환 버튼 탑재  
:four:후방 응급차량 주행 자동 양보 기능 개발  
 <br>  
 
:star:**핵심 기능과 활용한 아두이노 센서 및 부품**  

:one: 스마트 크루즈 컨트롤 (ACC) :electric_plug: IR센서  
:two: 자율 조향등 점등 :electric_plug: LED :   
:three: 차량 시동 및 모드 전환 버튼 :electric_plug: 푸시버튼 스위치  
:four: 응급 차량 주행 자동 양보 :electric_plug: 사운드 감지 센서  
:five: 라인 트레이싱 :electric_plug: 라인트레이서 모듈  
 <br>  
 
## 프로젝트 진행 - 협업 방식
 <br>  
 
:star:**프로젝트 관리** #Scrum #JIRA 
 <br>  
 
:ballot_box_with_check: 로드맵과 칸반보드를 통한 작업 효율성 극대화  
:ballot_box_with_check: JIRA와 GITHUB를 연동한 개발 진행  
 :point_right:이슈 생성 및 담당자 분배 :point_right: 이슈 별 브랜치 생성 :point_right: 이슈 개발 :point_right: Pull Request + 코드 리뷰  
 <br>  
 
:star:**코드 관리** #GIT #GITHUB  

:ballot_box_with_check: 기능 별로 헤더 파일분리  
:ballot_box_with_check: 센서 설정 값 분리 (config.h)  
:ballot_box_with_check: 코드 테스팅 : google test를 활용한 코드 TEST 
 <br>  
 
## 핵심 코드
:one: 스마트 크루즈 컨트롤 기능 개발

```cpp
int SmartCruise ( AF_DCMotor &L, AF_DCMotor &R, int Lpin, int Rpin, int now_speed, int IR_Sensor ){
  
  int change_speed = now_speed;
  if ( analogRead (IR_Sensor) < IR_sensor_threshold ){
    change_speed *= slow_mulitple;
  } else {
    change_speed += fast_plus;
    change_speed = (change_speed > max_speed) ?        
    max_speed : change_speed;
  }
  line_trace(L, R, Lpin, Rpin, change_speed);
  return change_speed;
}
```

:star: TCP 혼잡 제어에서의 AIMD 접근법을 응용하여 감속 및 가속 : 송신 측이 transmission rate를 패킷 손실이 일어날 때까지 증가시키는 식의 접근법  
![image](https://user-images.githubusercontent.com/39327058/221467724-d8c960a3-2f5a-4bcc-afbd-83ba41bdb904.png)

