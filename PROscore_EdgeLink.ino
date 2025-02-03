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
#include <Wire.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 NRF(4, 5);  // CE, CSN
Buttons btn;
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);


char SerialData[17] = " ";
void setup() {
  Serial.begin(115200);
  Serial.println("System Starting...");
  u8g2.begin();

  // displayCenterOnly("PROscore EdgeLink");
  // delay(2000);
  // displayCenterOnly("Booting...");
  // delay(2000);
  // displayCenterOnly("Initializing...");
  btn.initialize();
  btn.setDebug(true);
  btn.enableBuzzer(false);
  btn.setBuzzerType("active");
  delay(2000);

  if (!NRF.begin()) {
    Serial.println("NRF24L01 is Broken or Hardware Not Installed");
  } else {
    Serial.println("NRF24L01 detected!");
  }
  NRF.setPALevel(RF24_PA_MAX);
  NRF.setDataRate(RF24_250KBPS);
  NRF.openReadingPipe(0, address);
  NRF.startListening();
}


void loop() {
  btn.update();

  if (NRF.available()) {
    NRF24L01_DecodeData();
    NRF24L01_isAvailable = true;
    //Serial.println("NRF24L01 Data Received");
    //Serial.println("GameTime_Minute: " + String(GameTime_Minute) + " GameTime_Second: " + String(GameTime_Second) + " GameTime_Millis: " + String(GameTime_Millis));
  } else {
    NRF24L01_isAvailable = false;
  }

  switch (nowDisplaying) {
    case 0x00000:
      Display_Main();
      Display_Main_ButtonFunctions();
      break;
    case 0x0003:
      display_PROscore();
      display_PROscore_ButtonFunctions();
      break;
  }


}
