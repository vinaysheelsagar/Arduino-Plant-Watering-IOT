
# Arduino Plant Watering IoT

An automated plant watering system using Arduino, designed to monitor soil moisture and control a water pump. The system displays real-time moisture levels on an LCD and allows manual override via a switch.

## Features
- **Soil Moisture Monitoring:** Reads soil moisture using an analog sensor.
- **Automated Watering:** Activates a pump when soil is dry, stops when adequately watered.
- **Manual Override:** Physical switch to manually control the pump.
- **LCD Display:** Shows current moisture percentage and watering status.
- **Configurable Thresholds:** Easily adjust dry and watered percentage levels.

## Hardware Requirements
- Arduino-compatible board (ATmega328P)
- Soil moisture sensor (analog)
- Water pump + relay (active low supported)
- LCD display (LiquidCrystal I2C)
- Manual switch

## Software
- Written in C++ using the Arduino framework.
- Uses [LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C) library.

## Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/vinaysheelsagar/Arduino-Plant-Watering-IOT.git
   ```

2. **Install PlatformIO:**  
   [PlatformIO Installation Guide](https://platformio.org/install)

3. **Connect hardware as per pin definitions in `src/main.cpp`.**

4. **Build and upload:**
   ```bash
   platformio run --target upload
   ```

## Configuration
- Pin assignments and thresholds can be changed in `src/main.cpp`.
- Library dependencies are managed in `platformio.ini`.

## File Structure
- `src/` - Main source code
- `include/` - Header files
- `lib/` - External libraries
- `test/` - Test code

## License
This project is licensed under the MIT License.