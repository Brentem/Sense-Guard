#include <Arduino.h>

#include <OLED.hpp>
#include <Timer.hpp>

OLED oled;
Timer timer;

int buttonPin = 4;
int switchPin = 6;

int prevBtnState = LOW;
int currBtnState = LOW;

int counter = 0;

int prevSwitchState = LOW;
int currSwitchState = LOW;
bool off = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);

  oled.Initialize();
  oled.StartSession();
  timer.Start(1000);
}

void Communicate()
{
  if(off)
    return;

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
  prevSwitchState = currSwitchState;
  currSwitchState = digitalRead(switchPin);

  if((currSwitchState == LOW) && (prevSwitchState == HIGH))
  {
    oled.Clear();
    oled.ClearSeconds();
    counter = 0;

    if(!off)
    {
      off = true;
      Serial.print("!Off&");
    }
    else
    {
      off = false;
      Serial.print("!On&");
    }
  }

  prevBtnState = currBtnState;
  currBtnState = digitalRead(buttonPin);

  if((currBtnState == LOW) && (prevBtnState == HIGH))
  {
    counter++;
    Communicate();

    if(counter == 1)
    {
      oled.ClearSeconds();
      timer.Start(1000);
    }
  }

  if(counter > 2)
  {
    counter = 0;
  }

  if(off)
  {
    counter = 3;
  }

  if((timer.TimerFinished()) && (counter == 1))
  {
    oled.AddSecond();
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
