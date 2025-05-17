#include <Arduino.h>
#include "pump.h"
#include "sensor.h"
#include "display.h"
#include "watering.h"

# define SOIL_PIN A0

# define PUMP_PIN 9
# define PUMP_MANUAL_SWITCH_PIN 10 
# define PUMP_RELAY_IS_ACTIVE_LOW true


# define DISP_1_ADDR 0x3F
# define DISP_1_CHARS 16
# define DISP_1_LINES 2

# define DRY_PERCENT 15
# define WATERED_PERCENT 85


void setup() {
  initDisplay(
    DISP_1_ADDR,
    DISP_1_CHARS,
    DISP_1_LINES
  );

  initSoilSensor(SOIL_PIN);
  initPump(PUMP_PIN, PUMP_RELAY_IS_ACTIVE_LOW);

  initWateringSetup(WATERED_PERCENT, DRY_PERCENT);
}


void loop() {
  // put your main code here, to run repeatedly:
  wateringLoop();

}
