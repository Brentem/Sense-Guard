#include <Arduino.h>
#include <LedMatrixController.hpp>
#include <Dispatcher.hpp>
#include <BTComm.hpp>
#include <LedStripController.hpp>

Dispatcher dispatcher;
LedMatrixController ledMatrix;
BTComm comm;
LedStripController ledStrip;

const char* AVAILABLE_MSG = "Available";
const char* OCCUPIED_MSG = "Occupied";
const char* ON_MSG = "On";
const char* OFF_MSG = "Off";

bool messageReceived = false;

void MinuteCountdown()
{
  ledMatrix.SubtractMinutes();
  ledMatrix.Refresh();
  ledStrip.Refresh();
}

void Communication()
{
  comm.Reading();

  char* message = comm.GetMessage();

  if(message == nullptr)
  {
    return;
  }

  messageReceived = true;

  if(strcmp(message, AVAILABLE_MSG) == 0)
  {
    ledMatrix.ChangeOverlay(Overlay::AVAILABLE);
    ledStrip.ChangeState(LedState::GREEN);
  }
  else if(strcmp(message, OCCUPIED_MSG) == 0)
  {
    ledMatrix.ChangeOverlay(Overlay::OCCUPIED);
    ledStrip.ChangeState(LedState::RED);
  }
  else if(strcmp(message, ON_MSG) == 0)
  {
    ledMatrix.TurnOn(true);
    // led strip turnon
  }
  else if(strcmp(message, OFF_MSG) == 0)
  {
    ledMatrix.TurnOn(false);
    // led strip turnoff
  }
}

void setup() {
  // put your setup code here, to run once:
  comm.Begin();

  ledMatrix.Initialize();
  ledMatrix.ChangeOverlay(Overlay::OCCUPIED);
  ledMatrix.Refresh();

  ledStrip.Initialize();
  ledStrip.ChangeState(LedState::RED);
  ledStrip.Refresh();

  dispatcher.AllocSlot(1000, MinuteCountdown, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  dispatcher.DoDispatch();

  if(messageReceived)
  {
    ledMatrix.Refresh();
    ledStrip.Refresh();
    messageReceived = false;
  }
  else
  {
    Communication();
  }
}
