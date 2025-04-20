#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

LiquidCrystal_I2C* lcd = nullptr;

char moistureSymbol = 'W';

int moistureLineCols;
int moistureLine = 0;

String moistureHeader = "Moisture: ";

void initDisplay(uint8_t ADDR, uint8_t COLS, uint8_t ROWS) {
  moistureLineCols = COLS;

  lcd = new LiquidCrystal_I2C(ADDR, COLS, ROWS);

  lcd->init();
  lcd->backlight();
  initMoistureRow();
}

void initMoistureRow() {
  lcd->setCursor(0, moistureLine);
  lcd->print(moistureHeader);
}

void displayMoisture(int8_t moisturePercent) {
  lcd->setCursor(moistureHeader.length(), moistureLine);
  lcd->printf("%d%", moisturePercent);
  if (moisturePercent < 100) {
    lcd->print(" ");
  }
}

void setToEnd(char c) {
  lcd->setCursor(moistureLineCols - 2, moistureLine);
  lcd->printf("%v", c);
}

void displayWatering() {
  switch (moistureSymbol)
  {
  case '-':
    moistureSymbol = '=';
    break;

  case '=':
    moistureSymbol = '#';
    break;

  default:
    moistureSymbol = '-';
    break;
  }
  setToEnd(moistureSymbol);
}

void displayWaiting() {
  switch (moistureSymbol)
  {
  case '.':
    moistureSymbol = ' ';
    break;

  default:
    moistureSymbol = '.';
    break;
  }
  setToEnd(moistureSymbol);
}

void displayWatered() {
  setToEnd('W');
}

void displayNeedWater() {
  setToEnd('D');
}

