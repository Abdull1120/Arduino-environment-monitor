#include <Wire.h>
#include <DHT.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

DHT dht(2, DHT22);
hd44780_I2Cexp lcd;

void setup() {
  Serial.begin(9600);
  dht.begin();

  int status = lcd.begin(16, 2);

  if (status != 0) {
    Serial.println("LCD not detected. Check wiring.");
    while (true) {
      delay(1000);
    }
  }

  lcd.backlight();
  lcd.print("Starting...");
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Erase the previous readings.
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor error");
    Serial.println("Sensor read failed. Check wiring.");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity, 1);
  Serial.println("%");
}