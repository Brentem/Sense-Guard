#include <Arduino.h>

#include <Logic.hpp>

LedMatrixController matrixController;

Logic logic;

void setup() {
  // put your setup code here, to run once:
  logic.Start();
}

void loop() {
  // put your main code here, to run repeatedly:
  logic.Run();
}
