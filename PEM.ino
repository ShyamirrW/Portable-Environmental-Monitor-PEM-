#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int thermistorPin = A0;
const float R_fixed = 10000.0;
const float T0 = 298.15;
const float R0 = 10000.0;
const float B = 3950.0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("ENV Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int raw = analogRead(thermistorPin);
  
  float voltage = raw * (5.0 / 1023.0);
  float R_therm = R_fixed * (5.0 / voltage - 1.0);
  
  float tempK = 1.0 / (1.0/T0 + (1.0/B) * log(R_therm/R0));
  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0/5.0) + 32.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempF, 1);
  lcd.print("F  ");

  lcd.setCursor(0, 1);
  lcd.print("Raw: ");
  lcd.print(raw);

  Serial.print("Temp: ");
  Serial.print(tempF);
  Serial.print("F | Raw: ");
  Serial.println(raw);

  delay(1000);
}
