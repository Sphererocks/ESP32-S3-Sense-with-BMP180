
#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_SSD1306.h>
#include <AHTxx.h>
#include <Adafruit_INA260.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

// Wi-Fi credentials
const char* ssid = "SphereMako";
const char* password = "5phere7708";

// OLED setup
Adafruit_SSD1306 display(128, 64, &Wire);

// AHT30 Sensor
AHTxx aht30(AHTXX_ADDRESS_X38);

// INA260 Sensor
Adafruit_INA260 ina260 = Adafruit_INA260();

// BMP180 Sensor
Adafruit_BMP085_Unified bmp180 = Adafruit_BMP085_Unified(10085);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(5, 4);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED initialization failed!"));
  } else {
    display.clearDisplay();
    display.display();
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected!");

  if (!aht30.begin()) {
    Serial.println("AHT30 not detected!");
  }
  if (!ina260.begin(0x40)) {
    Serial.println("INA260 not detected!");
  }
  if (!bmp180.begin()) {
    Serial.println("BMP180 not detected!");
  }
}

void loop() {
  sensors_event_t bmp_event;
  bmp180.getEvent(&bmp_event);

  float temperatureAHT = aht30.readTemperature();
  float humidityAHT = aht30.readHumidity();
  float voltage = ina260.readBusVoltage();
  float current = ina260.readCurrent();
  float power = ina260.readPower();
  float altitude = bmp180.pressureToAltitude(1013.25, bmp_event.pressure);

  Serial.printf("Temp: %.2f°C Humidity: %.2f%% Pressure: %.2fhPa Altitude: %.2fm Voltage: %.2fV Current: %.2fmA Power: %.2fmW\n",
                temperatureAHT, humidityAHT, bmp_event.pressure, altitude, voltage, current, power);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("T:%.1fC H:%.1f%%\nP:%.1fhPa A:%.1fm\nV:%.2fV\nI:%.1fmA\nP:%.1fmW",
                 temperatureAHT, humidityAHT, bmp_event.pressure, altitude, voltage, current, power);
  display.display();

  delay(3000);
}
