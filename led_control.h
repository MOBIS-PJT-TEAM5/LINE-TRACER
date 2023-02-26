#ifndef _ledControl_h_
#define _ledControl_h_

/**
 * led on off 기본 함수
 * @param led_state : 제어할 LED의 상태 변수
 * @param state : 바꿀 상태
 */
void setLedState(int &led_state, int state);

void clock();

/**
 * led blink하는 함수
 * @param pin : 제어할 LED 핀번호
 * @param state : 제어할 LED 현재 상태
 * @param blink_state : 제어할 LED 현재 상태가 BLINK일 경우, LED가 꺼져있는지 켜져있는지를 제어할 변수
 */
void ledControl(int pin, int state);

#endif 