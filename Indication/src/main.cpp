#include <Arduino.h>
#include <LedMatrixController.hpp>
#include <Dispatcher.hpp>

Dispatcher dispatcher;
LedMatrixController controller;

void MinuteCountdown()
{
  controller.SubtractMinutes();
}

void setup() {
  // put your setup code here, to run once:
  // logic.Start();
  controller.Initialize();
  controller.ChangeOverlay(Overlay::OCCUPIED);
  dispatcher.AllocSlot(1000, MinuteCountdown, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  // logic.Run();
  dispatcher.DoDispatch();
  controller.Refresh();
}
