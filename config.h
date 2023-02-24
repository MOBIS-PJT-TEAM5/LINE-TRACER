
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


#endif //WORKSPACE_CONFIG_H
