#ifndef _buttonControl_h_
#define _buttonControl_h_

bool isButtonPushed(int pin);
void pushBtn(int pin, int& cnt, int& state);
#endif 