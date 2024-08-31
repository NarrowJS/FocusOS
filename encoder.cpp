#include "encoder.h"

#define CLK 2
#define DT 3
#define SW 4


void updateEncoder(){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1 && durationSet == false){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {

      if (focusDurationMinutes > 0) {
        focusDurationMinutes --;
      }
      currentDir ="CCW";
      if (focusDurationMinutes == 0 && focusDurationHours > 0) {
      focusDurationHours --;
      focusDurationMinutes = 59;
      }

      
    } else {
      // Encoder is rotating CW so increment
      focusDurationMinutes = focusDurationMinutes + 1;
      currentDir ="CW";
    }


    if (focusDurationMinutes == 60) {
      focusDurationHours ++;
      focusDurationMinutes = 0;
    }
    

    
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;



  
  if (focusDurationMinutes < 10) {
    focusDuration = "0"+String(focusDurationHours) + ":0" + String(focusDurationMinutes)+":00";
  } else {
    focusDuration = "0"+String(focusDurationHours) + ":" + String(focusDurationMinutes)+":00";
  }
  




  
  focusDuration.toCharArray(oledTitle, 10);
}
