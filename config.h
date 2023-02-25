
#ifndef _ConFig_h_
#define _ConFig_h_
/**
 * 센서 및 모터 기본 설정 정보
 * IRL : 라인 감지 센서 Left
 * IRR : 라인 감지 센서 Right
 * IR_Sensor : 적외선 장애물 감지(IR) 센서
 * LMotor : 왼쪽 모터 ex) M2
 * RMotor : 오른쪽 모터
 */
#define IRL 0
#define IRR 5
#define IR_Sensor A3

#define LMotor 2
#define RMotor 1


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
  *사운드 센서 관련 설정 정보
  *THRESHOLD_SS_1 : 응급차량 양보 기능이 작동하는 한계치
  *THRESHOLD_SS_2 : 응급차량 양보 기능이 종료되는 한계치
  *SOUND_HEAR : 소리가 들리는 것으로 판단되는 기준
  *PLUS_POINT : SOUND_HEAR보다 값이 작을 때, 더해지는 값
  *MINUS_POINT : SOUND_HEAR보다 값이 클 때, 더해지는 값
  *SPEED_LOW : 응급차량 양보 기능 중 주행 속도 
  *ROTATE_TIME : 회전에 걸리는 시간 
  *STRAIGHT_TIME : 직진에 걸리는 시간
**/

#define THRESHOLD_SS_1 300
#define THRESHOLD_SS_2 0
#define SOUND_HEAR 500
#define PLUS_POINT 100
#define MINUS_POINT -1
#define SPEED_LOW 125
#define ROTATE_TIME 500
#define STRAIGHT_TIME 500

#endif //WORKSPACE_CONFIG_H
