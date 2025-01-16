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
  
  // Button Pin Definitions
#define UP 15
#define DOWN 14
#define BACK 13
#define SELECT 12
private:
    bool buttonToggle=false;
    bool buttonTest=false;
};

#endif  // BUTTONS_H