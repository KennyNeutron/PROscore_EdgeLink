/*
  PROscore EdgeLink v1.0.0
  Environment:           ESP32 Dev Module
  Author:                Kenny Neutron
  Date Started:          2025-01-16

  Pin Usage:
    OLED Display:
      SDA   - GPIO21
      SCL   - GPIO22
      VCC   - 3.3V
      GND   - GND

    NRF24L01:
      CE    - GPIO4
      CSN   - GPIO5
      SCK   - GPIO18
      MOSI  - GPIO23
      MISO  - GPIO19
      VCC   - 3.3V
      GND   - GND

    Buttons:
      UP    - GPIO15
      DOWN  - GPIO2
      BACK  - GPIO13
      OK    - GPIO12

  Board Settings:
    Board:                     ESP32 Dev Module
    Port:                      COM3
    CPU Frequency:             80 MHz (WiFi/BT)
    Core Debug Level:          None
    Erase Flash Before Upload: Disabled
    Events Run On:             Core 1
    Flash Frequency:           80 MHz
    Flash Mode:                QIO
    Flash Size:                4 MB (32 Mb)
    JTAG Adapter:              Disabled
    Arduino Runs On:           Core 1
    Partition Scheme:          Default 4 MB w/ SPIFFS (1.2 MB APP / 1.5 MB SPIFFS)
    PSRAM:                     Disabled
    Upload Speed:              921600
    Zigbee Mode:               Disabled
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
  btn.enableBuzzer(true);
  btn.setBuzzerType("passive");
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
    case 0x0000:
      Display_Main();
      Display_Main_ButtonFunctions();
      break;
    case 0x1000:
      display_NRF24L01_tester();
      display_NRF24L01_tester_ButtonFunctions();
      break;
    case 0x3000:
      display_PROscore();
      display_PROscore_ButtonFunctions();
      break;
    case 0x4000:
      display_HC05();
      display_HC05_ButtonFunctions();
      break;
  }
}