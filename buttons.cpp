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
}

bool Buttons::getStatus(int thisButton) {
    bool buttonStatus=digitalRead(thisButton);
    if(!buttonStatus){
        return true;
    }else{
        return false;
    }
}

void Buttons::setDebug(bool debugStatus) {
    buttonTest=debugStatus;
}

void Buttons::update() {
    if(getStatus(UP) && !buttonToggle){
        buttonToggle=true;
        if(buttonTest){
            Serial.println("Pressed UP");
        }
    }
    if(getStatus(DOWN) && !buttonToggle){
        buttonToggle=true;
        if(buttonTest){
            Serial.println("Pressed DOWN");
        }
    }
    if(getStatus(BACK) && !buttonToggle){
        buttonToggle=true;
        if(buttonTest){
            Serial.println("Pressed BACK");
        }
    }
    if(getStatus(SELECT) && !buttonToggle){
        buttonToggle=true;
        if(buttonTest){
            Serial.println("Pressed SELECT");
        }
    }

    if(!getStatus(UP) && !getStatus(DOWN) && !getStatus(BACK) && !getStatus(SELECT)){
        buttonToggle=false;
    }
}