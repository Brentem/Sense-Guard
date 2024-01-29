#include <Arduino.h>
#include <LedMatrixController.hpp>
#include <Dispatcher.hpp>
#include <BTComm.hpp>
#include <LedStripController.hpp>

// Dispatcher dispatcher;
LedMatrixController ledMatrix;
BTComm comm;
LedStripController ledStrip;
Timer timer;

const char* AVAILABLE_MSG = "Available";
const char* OCCUPIED_MSG = "Occupied";
const char* ON_MSG = "On";
const char* OFF_MSG = "Off";

const uint32_t minuteInMillis = 60000;

bool messageReceived = false;
bool resetTimer = false;

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
    ledStrip.TurnOn(true);
  }
  else if(strcmp(message, OFF_MSG) == 0)
  {
    ledMatrix.TurnOn(false);
    ledStrip.TurnOn(false);
  }
}

void setup() {
  // put your setup code here, to run once:
  comm.Begin();

  ledMatrix.Initialize();
  ledMatrix.ChangeOverlay(Overlay::AVAILABLE);
  ledMatrix.Refresh();

  ledStrip.Initialize();
  ledStrip.ChangeState(LedState::GREEN);
  ledStrip.Refresh();

  // dispatcher.AllocSlot(60000, MinuteCountdown, 0);
  timer.Start(minuteInMillis);
}

void loop() {
  // put your main code here, to run repeatedly:
  // dispatcher.DoDispatch();

  if(resetTimer)
  {
    resetTimer = false;
    timer.Start(minuteInMillis);
  }
  
  if(messageReceived)
  {
    ledMatrix.Refresh();
    ledStrip.Refresh();
    messageReceived = false;
    resetTimer = true;
  }
  else
  {
    Communication();
  }

  if((!resetTimer) && timer.TimerFinished())
  {
    MinuteCountdown();
  }
}
