/*
  PROscore EdgeLink v.1.0.0
  Env: ESP32 Dev Module
  Author: Kenny Neutron (KWDiolola)
  Date Started: January 16, 2025

  Pin Usage:

  1. OLED Display
    - SDA: 21
    - SCL: 22
    - GND: GND
    - VCC: 3.3V

  2. NRF24L01
    - CE: 4
    - CSN: 5
    - SCK: 18
    - MOSI: 23
    - MISO: 19
    - VCC: 3.3V
    - GND: GND
  
  3. Buttons
    - UP: 15
    - DOWN: 2
    - BACK: 13 
    - OK: 12

*/
#include "Arduino.h"
#include "DataStructure_payload.h"
#include "buttons.h"
#include "variables.h"

#include <U8g2lib.h>


Buttons btn;
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);




void setup() {

    Serial.begin(115200);
    
    u8g2.begin();

    displayCenterOnly("PROscore EdgeLink");
    delay(2000);
    displayCenterOnly("Booting...");
    delay(2000);
    displayCenterOnly("Initializing...");
    btn.initialize();
    btn.setDebug(true);
    btn.enableBuzzer(true);
    btn.setBuzzerFrequency(2000);
    delay(2000);
}


void loop(){
    btn.update();

}


