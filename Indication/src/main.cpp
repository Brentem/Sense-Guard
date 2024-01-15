#include <Arduino.h>
#include <LedMatrixController.hpp>
#include <Dispatcher.hpp>
#include <BTComm.hpp>

Dispatcher dispatcher;
LedMatrixController controller;
BTComm comm;

const char* AVAILABLE_MSG = "Available";
const char* OCCUPIED_MSG = "Occupied";

void MinuteCountdown()
{
  controller.SubtractMinutes();
  controller.Refresh();
}

void Communication()
{
  comm.Reading();

  char* message = comm.GetMessage();

  if(message == nullptr)
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
  comm.Begin();

  controller.Initialize();
  controller.ChangeOverlay(Overlay::OCCUPIED);
  controller.Refresh();

  dispatcher.AllocSlot(1000, MinuteCountdown, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  dispatcher.DoDispatch();
  Communication();
}
