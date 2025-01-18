// buttons.cpp
#include "buttons.h"


Buttons::Buttons() {
}


void Buttons::initialize() {
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(BACK, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  if (EnableBuzzer) {
    pinMode(BUZZER_PIN, OUTPUT);
  }
}

bool Buttons::getStatus(int thisButton) {
  bool buttonStatus = digitalRead(thisButton);
  if (!buttonStatus) {
    buttonPressed = thisButton;
    return true;
  } else {
    return false;
  }
}

void Buttons::setDebug(bool debugStatus) {
  buttonTest = debugStatus;
}

void Buttons::update() {
  if (!buttonToggle && (getStatus(UP) || getStatus(DOWN) || getStatus(BACK) || getStatus(SELECT))) {
    buttonToggle = true;
    buttonFunctionExecuted=false;
    switch (buttonPressed) {
      case UP:
        if (buttonTest) {
          Serial.println("UP Button Pressed");
        }
        break;
      case DOWN:
        if (buttonTest) {
          Serial.println("DOWN Button Pressed");
        }
        break;
      case BACK:
        if (buttonTest) {
          Serial.println("BACK Button Pressed");
        }
        break;
      case SELECT:
        if (buttonTest) {
          Serial.println("SELECT Button Pressed");
        }
        break;
      default:
        break;
    }

    if (EnableBuzzer) {
      Serial.println("Buzzer Enabled");
      if (buzzerType == "passive") {
        tone(BUZZER_PIN, buzzerFrequency, 50);
        Serial.println("Passive Buzzer");
      } else {
        digitalWrite(BUZZER_PIN, 1);
        delay(50);
        digitalWrite(BUZZER_PIN, 0);
        Serial.println("Active Buzzer");
      }
    }
  }

  if (!getStatus(UP) && !getStatus(DOWN) && !getStatus(BACK) && !getStatus(SELECT)) {
    buttonToggle = false;
    buttonPressed = 0;
  }
}

void Buttons::enableBuzzer(bool buzzerStatus) {
  EnableBuzzer = buzzerStatus;
}

void Buttons::setBuzzerFrequency(uint16_t frequency) {
  buzzerFrequency = frequency;
}

void Buttons::setBuzzerType(String type) {
  buzzerType = type;
}

String Buttons::getPressedButton() {
  switch (buttonPressed) {
    case UP:
      if (buttonTest) {
        return "UP";
      }
      break;
    case DOWN:
      if (buttonTest) {
        return "DOWN";
      }
      break;
    case BACK:
      if (buttonTest) {
        return "BACK";
      }
      break;
    case SELECT:
      if (buttonTest) {
        return "SELECT";
      }
      break;
    default:
      return "NONE";
      break;
  }
}

void Buttons::functionExecuted() {
  buttonFunctionExecuted = true;
}

bool Buttons::isFunctionExecuted() {
  return buttonFunctionExecuted;
}