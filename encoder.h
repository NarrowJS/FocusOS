#ifndef ENCODER_H
#define ENCODER_H
#include <Arduino.h>

void updateEncoder();

extern int counter;
extern int currentStateCLK;
extern int lastStateCLK;
extern String currentDir;
extern String focusDuration;
extern char oledTitle[10];
extern int focusDurationHours;
extern int focusDurationMinutes;
extern bool durationSet;

#endif
