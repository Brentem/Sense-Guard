#include <Arduino.h>

#include <LedMatrixController.hpp>

LedMatrixController matrixController;

void setup() {
  // put your setup code here, to run once:
  matrixController.Initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  matrixController.Refresh();
}
