#include <Arduino.h>
#include "sensor.h"
#include "pump.h"
#include "display.h"


int8_t wateredThresholdPercent;
int8_t dryThresholdPercent;


void initWateringSetup(
  int WATERED_PERCENT, 
  int DRY_PERCENT
) {
  dryThresholdPercent = DRY_PERCENT;
  wateredThresholdPercent = WATERED_PERCENT;
}


void wateringLoop() {
  int8_t moisturePercent = readSoilMoisture();
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
