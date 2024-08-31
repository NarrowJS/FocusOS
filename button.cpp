#include "button.h"
#include "timer.h"
#include "Countimer.h"


void buttonHandler() {
  int buttonState = digitalRead(5);
  if (buttonState == LOW) {
      Serial.println("Button pressed");
      if (durationSet == false) {
        focusMessage = "Focus Mode";
        durationSet = true;

        digitalWrite(A3,HIGH);
        delay(300);
        digitalWrite(A3,LOW);
        timerHandler();
        delay(100);
      }
  }
}
