#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>


void buttonHandler();
extern char oledTitle[10];
extern String focusMessage;

extern bool durationSet;
extern bool isPaused;

#endif
