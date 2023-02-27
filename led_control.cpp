#include "config.h"
#include "led_control.h"

extern int FR_LED_STATE;
extern int FL_LED_STATE;
extern int BR_LED_STATE;
extern int BL_LED_STATE;
extern unsigned long PREVIOUS_MILLIS;
extern unsigned long CURRENT_MILLIS;
extern int CLOCK_STATE;

void clock() {
  CURRENT_MILLIS = millis();
  if (CURRENT_MILLIS - PREVIOUS_MILLIS >= INTERVAL)
  {
    // save the last time you blinked the LED
    PREVIOUS_MILLIS = CURRENT_MILLIS;
    if (CLOCK_STATE == LOW)
    {
      CLOCK_STATE = HIGH;
    } 
    else 
    {
      CLOCK_STATE = LOW;
    }
  }
}

void ledControl(int pin, int state) {
  if (state == ON) 
  {
    digitalWrite(pin, HIGH);
  }
  else if (state == BLINK)
  {
    // set the LED with the ledState of the variable:
    digitalWrite(pin, CLOCK_STATE);
  }
  }
  else
  {
    digitalWrite(pin, LOW);
  }
}