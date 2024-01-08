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
    matrix.setTextSize(1);
}

void LedMatrixController::Refresh()
{
    matrix.setTextColor(matrix.Color333(7, 0, 0));
    matrix.setCursor(2, 1);
    matrix.print(60, 10);
    matrix.setCursor(15, 1);
    matrix.print('m');
    matrix.setCursor(20, 1);
    matrix.print('i');
    matrix.setCursor(25, 1);
    matrix.print('n');

    matrix.drawRect(2, 10, 28, 4, matrix.Color333(7, 0, 0));

    matrix.swapBuffers(false);
}