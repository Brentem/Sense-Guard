#include "LedMatrixController.hpp"

#include <RGBmatrixPanel.h>

#define CLK  8
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

const uint8_t X_MARGIN = 2;
const uint8_t Y_MARGIN = 1;

const uint8_t BASE = 10;

const uint8_t M_CHAR = 15;
const uint8_t I_CHAR = 20;
const uint8_t N_CHAR = 25;

const uint8_t LOADBAR_Y_MARGIN = 10;
const uint8_t LOADBAR_WIDTH = 28;
const uint8_t LOADBAR_HEIGHT = 4;

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);

void availableOverlay(int unused);
void occupiedOverlay(int minutes);

LedMatrixController::LedMatrixController()
{
    overlay = Overlay::AVAILABLE;
    minutes = 60;
}

void LedMatrixController::Initialize()
{
    matrix.begin();
    matrix.setTextWrap(false);
    matrix.setTextSize(1);
}

void LedMatrixController::Refresh()
{
    matrix.fillScreen(matrix.Color333(0, 0, 0));

    switch (overlay)
    {
    case Overlay::AVAILABLE:
        availableOverlay();
        break;

    case Overlay::OCCUPIED:
        occupiedOverlay();
        break;
    
    default:
        matrix.fillScreen(matrix.Color333(0, 0, 0));
        break;
    }

    matrix.swapBuffers(false);
}

void LedMatrixController::ChangeOverlay(Overlay overlay)
{
    this->overlay = overlay;
    minutes = 60;
}

void LedMatrixController::SubtractMinutes()
{
    minutes--;

    if(minutes < 0)
    {
        minutes = 60;
    }
}

void LedMatrixController::availableOverlay()
{
    matrix.setTextColor(matrix.Color333(0, 7, 0));
    matrix.setCursor(2, 1);
    matrix.print("bruh");
}

void LedMatrixController::occupiedOverlay()
{
    matrix.setTextColor(matrix.Color333(7, 0, 0));
    matrix.setCursor(X_MARGIN, Y_MARGIN);
    matrix.print(minutes, BASE);
    matrix.setCursor(M_CHAR, Y_MARGIN);
    matrix.print('m');
    matrix.setCursor(I_CHAR, Y_MARGIN);
    matrix.print('i');
    matrix.setCursor(N_CHAR, Y_MARGIN);
    matrix.print('n');

    uint8_t loadbar = 13;

    matrix.drawRect(X_MARGIN, LOADBAR_Y_MARGIN, LOADBAR_WIDTH, LOADBAR_HEIGHT, matrix.Color333(7, 0, 0));
    matrix.fillRect((X_MARGIN + 1), (LOADBAR_Y_MARGIN + 1), loadbar, (LOADBAR_HEIGHT - 2), matrix.Color333(7, 0, 0));
}