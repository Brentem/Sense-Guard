#include <Arduino.h>

#include <OLED.hpp>

OLED oled;

int buttonPin = 4;
int switchPin = 6;

int prevBtnState = LOW;
int currBtnState = LOW;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);

  oled.Initialize();
  oled.StartSession();
}

void loop() {
  int switchState = digitalRead(switchPin);

  if(switchState == LOW)
  {
    oled.Clear();
    counter = 0;
    return;
  }

  prevBtnState = currBtnState;
  currBtnState = digitalRead(buttonPin);

  if((currBtnState == LOW) && (prevBtnState == HIGH))
  {
    counter++;
  }

  if(counter > 2)
  {
    counter = 0;
  }

  switch (counter)
  {
  case 0:
    oled.StartSession();
    break;

  case 1:
    oled.Countdown();
    break;

  case 2:
    oled.Duration();
    break;
  
  default:
    oled.Clear();
    break;
  }
}
