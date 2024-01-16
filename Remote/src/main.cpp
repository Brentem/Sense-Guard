#include <Arduino.h>

#include <OLED.hpp>

OLED oled;

void setup() {
  // put your setup code here, to run once:
  oled.Initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  oled.StartSession();
  delay(2000);
  oled.Countdown();
  delay(2000);
  oled.Duration(); 
  delay(2000);
}
