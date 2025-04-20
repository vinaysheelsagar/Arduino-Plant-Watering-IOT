#include <Arduino.h>

uint8_t soilPin;
int16_t maxResistance = 1024;
int16_t minResistance = 0;


void initSoilSensor(uint8_t SOIL_PIN) {
  soilPin = SOIL_PIN;

  pinMode(soilPin, INPUT);
}
  
int8_t readSoilMoisture() {
  int sensorValue = analogRead(soilPin);

  int8_t percentage = map(sensorValue, maxResistance, minResistance, 0, 100);
  return percentage;
}
