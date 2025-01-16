// buttons.h
#ifndef BUTTONS_H
#define BUTTONS_H

#include "Arduino.h"

class Buttons {
public:
  Buttons();
  void initialize();
  bool getStatus(int thisButton);
  void update();
  void setDebug(bool debugStatus);
  void enableBuzzer(bool buzzerStatus);
  void setBuzzerFrequency(uint16_t frequency);
private:
  // Button Pin Definitions
#define UP 15
#define DOWN 14
#define BACK 13
#define SELECT 12
#define BUZZER_PIN 25
    bool buttonToggle=false;
    bool buttonTest=false;
    bool EnableBuzzer=false;
    uint8_t buttonPressed=0;
    uint16_t buzzerFrequency=1000;
};

#endif  // BUTTONS_H