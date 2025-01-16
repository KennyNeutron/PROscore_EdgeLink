#include "Arduino.h"

#define LED_PIN 13

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    Serial.println("PROscore EdgeLink");
    Serial.println("PROGRAM STARTED...");
}


void loop(){
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
    Serial.println("LED BLINKED");
}