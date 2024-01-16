#include <Arduino.h>
#include <LedMatrixController.hpp>
#include <Dispatcher.hpp>
#include <BTComm.hpp>
#include <LedStripController.hpp>

Dispatcher dispatcher;
LedMatrixController matrix;
BTComm comm;
LedStripController ledStrip;

const char* AVAILABLE_MSG = "Available";
const char* OCCUPIED_MSG = "Occupied";

void MinuteCountdown()
{
  matrix.SubtractMinutes();
  matrix.Refresh();
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
    matrix.ChangeOverlay(Overlay::AVAILABLE);
    ledStrip.ChangeState(LedState::GREEN);
  }
  else if(strcmp(message, OCCUPIED_MSG) == 0)
  {
    matrix.ChangeOverlay(Overlay::OCCUPIED);
    ledStrip.ChangeState(LedState::RED);
  }
}

void setup() {
  // put your setup code here, to run once:
  comm.Begin();

  matrix.Initialize();
  matrix.ChangeOverlay(Overlay::OCCUPIED);
  matrix.Refresh();

  ledStrip.Initialize();
  ledStrip.ChangeState(LedState::RED);
  ledStrip.Refresh();

  dispatcher.AllocSlot(1000, MinuteCountdown, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  dispatcher.DoDispatch();
  Communication();
}
