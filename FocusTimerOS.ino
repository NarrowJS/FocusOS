#include <Arduino.h>
#include <U8g2lib.h>
#include "encoder.h"
#include "button.h"
#include "timer.h"
#include "Countimer.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
U8G2_SSD1327_EA_W128128_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 9, /* data=*/ 8, /* cs=*/ 10, /* dc=*/ 7, /* reset=*/ 11);

#define CLK 2
#define DT 3
#define SW 4

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";


int focusDurationHours = 1;
int focusDurationMinutes = 0;

String focusDuration = "01:00:00";
String focusMessage = "Set Time";


char oledTitle[10];
char oledSubtitle[15];

bool durationSet = false;
bool isPaused = false;




Countimer timer;


void setup() {
  u8g2.begin();
  Serial.begin(9600);
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);

  pinMode(A3, OUTPUT); //Buzzer
  pinMode(A1, INPUT); // LDR

  lastStateCLK = digitalRead(CLK);
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);

  focusDuration.toCharArray(oledTitle, 10);
}



void loop() {
  
  buttonHandler();
  timer.run();
  
  u8g2.firstPage();
  do{
  u8g2.setFont(u8g2_font_fub20_tf); // choose a suitable font
  
  focusMessage.toCharArray(oledSubtitle, 15);
 
  u8g2.drawStr(10,50, oledTitle);
  u8g2.setFont(u8g2_font_t0_18b_tr); // choose a suitable font
  u8g2.drawStr(20,90, oledSubtitle);
  
  // write something to the internal memory
  } while (u8g2.nextPage());  
}
