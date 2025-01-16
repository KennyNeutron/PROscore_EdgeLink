// buttons.cpp
#include "buttons.h"


Buttons::Buttons()
{

}


void Buttons::initialize() {
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    pinMode(BACK, INPUT_PULLUP);
    pinMode(SELECT, INPUT_PULLUP);
    if(EnableBuzzer){
        pinMode(BUZZER_PIN, OUTPUT);
    }
}

bool Buttons::getStatus(int thisButton) {
    bool buttonStatus=digitalRead(thisButton);
    if(!buttonStatus){
        buttonPressed=thisButton;
        return true;
    }else{
        return false;
    }
}

void Buttons::setDebug(bool debugStatus) {
    buttonTest=debugStatus;
}

void Buttons::update() {
    if(!buttonToggle && (getStatus(UP) || getStatus(DOWN) || getStatus(BACK) || getStatus(SELECT))){
        buttonToggle=true;
        switch(buttonPressed){
            case UP:
                if(buttonTest){
                    Serial.println("UP Button Pressed");
                }
                break;
            case DOWN:
                if(buttonTest){
                    Serial.println("DOWN Button Pressed");
                }
                break;
            case BACK:
                if(buttonTest){
                    Serial.println("BACK Button Pressed");
                }
                break;
            case SELECT:    
                if(buttonTest){
                    Serial.println("SELECT Button Pressed");
                }
                break;            
            default:
                break;
        }

        if(EnableBuzzer){
            tone(BUZZER_PIN, buzzerFrequency, 50);
        }
    }

    if(!getStatus(UP) && !getStatus(DOWN) && !getStatus(BACK) && !getStatus(SELECT)){
        buttonToggle=false;
        buttonPressed=0;
    }
}

void Buttons::enableBuzzer(bool buzzerStatus) {
    EnableBuzzer=buzzerStatus;
}

void Buttons::setBuzzerFrequency(uint16_t frequency) {
    buzzerFrequency=frequency;
}