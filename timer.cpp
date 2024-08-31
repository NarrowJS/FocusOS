#include "timer.h"

String currentTime;

bool isBreakMode = false;
int focusSegments = 0;


void timerHandler() {

  if (isBreakMode == false) {

    if (focusSegments == 2) {
      timer.setCounter(focusDurationHours, focusDurationMinutes, 0, timer.COUNT_DOWN, timerCompleteHandler);
      timer.setInterval(timerScreenUpdate, 1000);
      focusMessage = "Set Time";
      focusDuration.toCharArray(oledTitle, 10);
      focusSegments = 0;
      durationSet = false;
    } else {
      timer.setCounter(focusDurationHours, focusDurationMinutes, 0, timer.COUNT_DOWN, timerCompleteHandler);
      timer.setInterval(timerScreenUpdate, 1000);
      focusMessage = "Focus Mode";
      timer.start();
    }
  } else {

    while (checkMonitorLight()) {
      Serial.println("Value is true, checking again");
      digitalWrite(A3, HIGH);
      Serial.println(analogRead(A1));
      delay(100);
    }

    Serial.println("Value is false, starting break");
    digitalWrite(A3, LOW);

    timer.setCounter(0, 1, 0, timer.COUNT_DOWN, timerCompleteHandler);
    timer.setInterval(timerScreenUpdate, 1000);
    focusMessage = "Break Mode";
    timer.start();
  }
}

void timerCompleteHandler() {
  isBreakMode = !isBreakMode;
  focusSegments ++;
  timerHandler();
}


bool checkMonitorLight() {
  int lightValue = analogRead(A1);
  Serial.println(lightValue);
  if (lightValue > 600) {
    return true;
  } else {
    return false;
  }
}


void breakHandler() {
  Serial.println("Timer Complete");
  focusMessage = "Break Mode";

  while (checkMonitorLight) {
    Serial.println("Value is true, checking again");
    digitalWrite(A3, HIGH);
    delay(100);
  }

  Serial.println("Value is false, starting break");
  digitalWrite(A3, LOW);
  timer.setCounter(0, 1, 0, timer.COUNT_DOWN, timerHandler);
  timer.setInterval(timerScreenUpdate, 1000);
}


void timerScreenUpdate() {
  Serial.println(timer.getCurrentTime());

  currentTime = timer.getCurrentTime();
  currentTime.toCharArray(oledTitle, 10);
}
