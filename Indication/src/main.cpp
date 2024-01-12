#include <Arduino.h>
#include <LedMatrixController.hpp>
#include <Dispatcher.hpp>

Dispatcher dispatcher;
LedMatrixController controller;

#define BUFFER_SIZE 16

#define START_CHAR '!'
#define END_CHAR '&'

const char* AVAILABLE_MSG = "Available";
const char* OCCUPIED_MSG = "Occupied";

void MinuteCountdown()
{
  controller.SubtractMinutes();
  controller.Refresh();
}

void Communication()
{
  bool receiving = false;
  bool received = false;
  char message[BUFFER_SIZE];
  int8_t counter = 0;

  while (Serial.available())
  {
    char c = Serial.read();

    if(c == END_CHAR)
    {
      receiving = false;
      message[counter] = 0;
      received = true;
    }

    if(receiving)
    {
      message[counter] = c;
      counter++;
    }

    if(c == START_CHAR)
    {
      receiving = true;
      counter = 0;
    }
  }
  
  if(received == false)
  {
    return;
  }

  if(strcmp(message, AVAILABLE_MSG) == 0)
  {
    controller.ChangeOverlay(Overlay::AVAILABLE);
  }
  else if(strcmp(message, OCCUPIED_MSG) == 0)
  {
    controller.ChangeOverlay(Overlay::OCCUPIED);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  controller.Initialize();
  controller.ChangeOverlay(Overlay::OCCUPIED);
  controller.Refresh();

  dispatcher.AllocSlot(1000, MinuteCountdown, 0);
  // dispatcher.AllocSlot(100, Communication, 1); // Communication doesn't have to be delayed now.
}

void loop() {
  // put your main code here, to run repeatedly:
  dispatcher.DoDispatch();
  Communication();
}
