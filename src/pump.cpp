#include <Arduino.h>

uint8_t pumpPin;
bool pumpStatus = false;

void initPump(uint8_t PUMP_PIN) {
  pumpPin = PUMP_PIN;

  pinMode(pumpPin, OUTPUT);
}

void turnOnPump() {
  digitalWrite(pumpPin, HIGH);
  pumpStatus = true;
}

void turnOffPump() {
  digitalWrite(pumpPin, LOW);
  pumpStatus = false;
}

bool getPumpStatus() {
  return pumpStatus;
}
