
# ESP32-S3 Sensor System

## Overview
This project integrates multiple sensors with an ESP32-S3:
- AHT30 (Temperature & Humidity)
- BMP180 (Pressure & Altitude)
- INA260 (Voltage, Current, Power)
- SSD1306 OLED display (Data visualization)

## Hardware Setup
### Connections (I²C)
| Device  | SDA Pin | SCL Pin | Address |
|---------|---------|---------|---------|
| AHT30   | GPIO 5  | GPIO 4  | 0x38    |
| BMP180  | GPIO 5  | GPIO 4  | 0x77    |
| INA260  | GPIO 5  | GPIO 4  | 0x40    |
| SSD1306 | GPIO 5  | GPIO 4  | 0x3C    |

### ESP32-S3 Pins
- SDA: GPIO 5
- SCL: GPIO 4

## Software Setup
- Arduino IDE with ESP32 support
- Libraries required:
  - Adafruit SSD1306
  - AHTxx by Enjoyneering
  - Adafruit INA260
  - Adafruit Unified Sensor
  - Adafruit BMP085 Unified

## Usage
1. Configure your Wi-Fi SSID and password in the sketch.
2. Compile and upload to ESP32-S3.

## Author
- mr collins

