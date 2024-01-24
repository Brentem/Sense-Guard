#include <Arduino.h>

#include <OLED.hpp>

OLED oled;

int buttonPin = 4;
int switchPin = 6;

int prevBtnState = LOW;
int currBtnState = LOW;

int counter = 0;

bool off = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);

  oled.Initialize();
  oled.StartSession();
}

void Communicate()
{
  if(counter == 1)
  {
    Serial.print("!Occupied&");
  }
  else
  {
    Serial.print("!Available&");
  }
}

void loop() {
  // int switchState = digitalRead(switchPin);

  // if(switchState == LOW)
  // {
  //   oled.Clear();
  //   counter = 0;

  //   if(!off)
  //   {
  //     off = true;
  //     Serial.print("!Off&");
  //   }
  //   return;
  // }

  // if(off)
  // {
  //   off = false;
  //   Serial.print("!On&");
  // }

  prevBtnState = currBtnState;
  currBtnState = digitalRead(buttonPin);

  if((currBtnState == LOW) && (prevBtnState == HIGH))
  {
    counter++;
    Communicate();
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
