
#ifndef _ConFig_h_
#define _ConFig_h_
/**
 * 센서 및 모터 기본 설정 정보
 * IRL : 라인 감지 센서 Left
 * IRR : 라인 감지 센서 Right
 * IR_Sensor : 적외선 장애물 감지(IR) 센서
 * LMotor : 왼쪽 모터 ex) M2
 * RMotor : 오른쪽 모터
 * MODE_BUTTON : 모드 버튼
 * STOP_BUTTON : 정지 버튼
 */
#define IRL 0
#define IRR 5
#define IR_Sensor A3

#define LMotor 2
#define RMotor 1

#define MODE_BUTTON A4
#define STOP_BUTTON A2

/**
 * 속도 관련 설정 정보
 * MAX_SPEED : 차의 최고 속력
 * SLOW_MULTIPLE : 크루즈 기능 사용시 감소 비율(ex. 0.89는 11% 감소)
 * FAST_PLUS : 속도 회복시 회복 속력 기준 (ex. 5 면 +5씩 증가폭)
 * IR_SENSOR_THRESHOLD : 적외선 센서의 감지 기준
 * REVERSE_SPEED : 역방향 바퀴 속력
 */

#define INITIAL_SPEED 150
#define MAX_SPEED 120
#define SLOW_MULTIPLE 0.89
#define FAST_PLUS 5
#define IR_SENSOR_THRESHOLD 500
#define IR_LINE_THRESHOLD 300
#define REVERSE_SPEED 110

/**
 * 버튼 제어 관련 설정 정보
 * BUTTON_PUSH_THRESHOLD: 버튼 눌림의 감지기준
 * BUTTON_PUSH_TIME: 얼마나 오래 눌러야 하는지의 기준
 */
#define BUTTON_PUSH_THRESHOLD 1000
#define BUTTON_PUSH_TIME 150

/**
 * LED 제어 관련 설정 정보
 * FR_LED : 전방 오른쪽 LED 핀 번호
 * FL_LED : 전방 왼쪽 LED 핀 번호
 * BR_LED : 후방 오른쪽 LED 핀 번호
 * BL_LED : 후방 왼쪽 LED 핀 번호
 * INTERVAL : 깜빡임 주기
 * BLINK : 깜빡이는 상태
 * ON : 켜져있는 상태
 * OFF : 꺼져있는 상태
 */
#define FR_LED 2
#define FL_LED 13
#define BR_LED 9
#define BL_LED 10
#define INTERVAL 300
#define BLINK 0
#define ON 1
#define OFF 2

/**
  *사운드 센서 관련 설정 정보
  *SOUND_SENSOR : 사운드 센서 핀 번호
  *THRESHOLD_SS_1 : 응급차량 양보 기능이 작동하는 한계치
  *THRESHOLD_SS_2 : 응급차량 양보 기능이 종료되는 한계치
  *SOUND_HEAR : 소리가 들리는 것으로 판단되는 기준
  *PLUS_POINT : SOUND_HEAR보다 값이 작을 때, 더해지는 값
  *MINUS_POINT : SOUND_HEAR보다 값이 클 때, 더해지는 값
  *MINUS_POINT_MULTIPLE : SOUND_HEAR보다 값이 클 때, 곱해지는 값
  *SPEED_LOW : 응급차량 양보 기능 중 주행 속도 
  *ROTATE_TIME : 회전에 걸리는 시간 
  *ROTATE_TIME2 : 회전에 걸리는 시간 
  *ROTATE_TIME3 : 회전에 걸리는 시간 
  *STRAIGHT_TIME : 직진에 걸리는 시간
**/

#define SOUND_SENSOR A1
#define THRESHOLD_SS_1 300
#define THRESHOLD_SS_2 20
#define SOUND_HEAR 500
#define PLUS_POINT 100
#define MINUS_POINT -1
#define MINUS_POINT_MULTIPLE 0.6
#define SPEED_LOW 125
#define ROTATE_TIME 400
#define ROTATE_TIME2 700
#define ROTATE_TIME3 800
#define ROTATE_TIME4 600
#define STRAIGHT_TIME 500
#define STOP_TIME 2000

#endif //WORKSPACE_CONFIG_H
