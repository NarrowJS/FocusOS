#ifndef TIMER_H
#define TIMER_H
#include <Arduino.h>
#include "Countimer.h"


void timerHandler();
void timerScreenUpdate();
void breakHandler();
void timerCompleteHandler();
bool checkMonitorLight();

extern char oledTitle[10];
extern String focusDuration;
extern int focusDurationHours;
extern int focusDurationMinutes;
extern String focusMessage;
extern Countimer timer;
extern bool durationSet;

#endif
