#include <Arduino.h>
#include "sensor.h"
#include "pump.h"
#include "display.h"

int8_t wateredThresholdPercent;
int8_t dryThresholdPercent;
uint8_t pumpSwitchPin;

void initWateringSetup(
  uint8_t PUMP_MANUAL_SWITCH_PIN,
  int WATERED_PERCENT, 
  int DRY_PERCENT
) {
  dryThresholdPercent = DRY_PERCENT;
  wateredThresholdPercent = WATERED_PERCENT;

  pumpSwitchPin = PUMP_MANUAL_SWITCH_PIN;
  pinMode(PUMP_MANUAL_SWITCH_PIN, INPUT_PULLUP);
}

bool isSwitchOn(){
  if (digitalRead(pumpSwitchPin) == LOW){
    return true;
  }
  return false;

}

void wateringLoop() {
  int8_t moisturePercent = readSoilMoisture();

  if (isSwitchOn()) {
    if (moisturePercent >= wateredThresholdPercent) {
      displayWatered();
      turnOffPump();
    } else {
      displayWatering();
      turnOnPump();
    }

    displayMoisture(moisturePercent);
    return;

  }

  bool isPumpOn = getPumpStatus();

  if (moisturePercent < dryThresholdPercent) {
    displayNeedWater();
    turnOnPump();

  } else if (moisturePercent > wateredThresholdPercent) {
    displayWatered();
    turnOffPump();

  } else {

    if (isPumpOn) {
      displayWatering();

    } else {
      displayWaiting();

    }
  }

  displayMoisture(moisturePercent);

}
