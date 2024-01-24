#include "LedMatrixController.hpp"

#include <RGBmatrixPanel.h>

#define CLK  8 // Change this for Arduino Mega
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

const uint8_t LOADBAR_X_MARGIN = X_MARGIN + 1;
const uint8_t LOADBAR_Y_MARGIN = 10;
const uint8_t LOADBAR_WIDTH = 26;
const uint8_t LOADBAR_HEIGHT = 4;

const uint8_t LOADBAR_COUNTER_MAX = 24;
const uint8_t MINUTE_COUNTER_MAX = 60;

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);


void availableOverlay(int unused);
void occupiedOverlay(int minutes);

LedMatrixController::LedMatrixController()
{
    overlay = Overlay::AVAILABLE;
    currMinutes = MINUTE_COUNTER_MAX;
    prevMinutes = MINUTE_COUNTER_MAX;
    loadbar = LOADBAR_COUNTER_MAX;
    redColor = 0;
    greenColor = 0;
    blackColor = 0;
}

void LedMatrixController::Initialize()
{
    matrix.begin();
    matrix.setTextWrap(false);
    matrix.setTextSize(1);

    redColor = matrix.Color333(7, 0, 0);
    greenColor = matrix.Color333(0, 7, 0);
    blackColor = matrix.Color333(0, 0, 0);
}

void LedMatrixController::Refresh()
{
    matrix.fillScreen(blackColor);

    switch (overlay)
    {
    case Overlay::AVAILABLE:
        availableOverlay();
        break;

    case Overlay::OCCUPIED:
        occupiedOverlay();
        break;
    
    default:
        matrix.fillScreen(blackColor);
        break;
    }

    matrix.updateDisplay();
}

void LedMatrixController::ChangeOverlay(Overlay overlay)
{
    this->overlay = overlay;
    currMinutes = MINUTE_COUNTER_MAX;
    prevMinutes = MINUTE_COUNTER_MAX;
    loadbar = LOADBAR_COUNTER_MAX;
}

void LedMatrixController::SubtractMinutes()
{
    // currMinutes--;

    // if(currMinutes < 0)
    // {
    //     currMinutes = MINUTE_COUNTER_MAX;
    //     prevMinutes = MINUTE_COUNTER_MAX;

    //     loadbar = LOADBAR_COUNTER_MAX;
    // }

    if(currMinutes != 0)
    {
        currMinutes--;
    }

    if((prevMinutes - currMinutes) == 5)
    {
        loadbar = loadbar - 2;
        prevMinutes = currMinutes;
    }
}

void LedMatrixController::TurnOn(bool on)
{
    if(on)
    {
        overlay = Overlay::AVAILABLE;
    }
    else
    {
        overlay = Overlay::OVERLAY_OFF;
    }
}

void LedMatrixController::availableOverlay()
{
    // matrix.fillScreen(greenColor);
    matrix.setTextColor(greenColor);
    matrix.setCursor(X_MARGIN + 3, Y_MARGIN + 3);

    matrix.print("Vrij");
}

void LedMatrixController::occupiedOverlay()
{
    matrix.setTextColor(redColor);
    matrix.setCursor(X_MARGIN, Y_MARGIN);

    if(currMinutes < 10)
    {
        matrix.print(0, BASE);
    }

    matrix.print(currMinutes, BASE);
    matrix.setCursor(M_CHAR, Y_MARGIN);
    matrix.print('m');
    matrix.setCursor(I_CHAR, Y_MARGIN);
    matrix.print('i');
    matrix.setCursor(N_CHAR, Y_MARGIN);
    matrix.print('n');

    matrix.drawRect(LOADBAR_X_MARGIN, LOADBAR_Y_MARGIN, LOADBAR_WIDTH, LOADBAR_HEIGHT, redColor);
    matrix.fillRect((LOADBAR_X_MARGIN + 1), (LOADBAR_Y_MARGIN + 1), loadbar, (LOADBAR_HEIGHT - 2), redColor);
}