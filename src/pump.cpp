#include <Arduino.h>

uint8_t pumpPin;
bool pumpStatus = false;

uint8_t onState = HIGH;
uint8_t offState = LOW;

void initPump(uint8_t PUMP_PIN, bool PUMP_RELAY_IS_ACTIVE_LOW) {
  pumpPin = PUMP_PIN;

  pinMode(pumpPin, OUTPUT);
  if (PUMP_RELAY_IS_ACTIVE_LOW) {
    onState = LOW;
    offState = HIGH;
  }
}

void turnOnPump() {
  digitalWrite(pumpPin, onState);
  pumpStatus = true;
}

void turnOffPump() {
  digitalWrite(pumpPin, offState);
  pumpStatus = false;
}

bool getPumpStatus() {
  return pumpStatus;
}
