#include "LedMatrixController.hpp"

#include <RGBmatrixPanel.h>

#define CLK  8
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);

void LedMatrixController::Initialize()
{
    matrix.begin();
    matrix.setTextWrap(false);
    matrix.setTextSize(2);
}

void LedMatrixController::Refresh()
{
    char str[3] = "60";

    matrix.setTextColor(matrix.Color333(0, 7, 0));
    matrix.setCursor(5, 1);
    matrix.print(str);

    matrix.swapBuffers(false);
}