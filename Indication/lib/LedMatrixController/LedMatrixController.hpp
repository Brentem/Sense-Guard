#pragma once

#include <Arduino.h>

enum Overlay
{
    AVAILABLE,
    OCCUPIED,
    OVERLAY_OFF
};

class LedMatrixController{
private:
    uint16_t redColor;
    uint16_t greenColor;
    uint16_t blackColor;
    Overlay overlay;
    int8_t currMinutes;
    int8_t prevMinutes;
    uint8_t loadbar;

    void availableOverlay();
    void occupiedOverlay();

public:
    LedMatrixController();
    void Initialize();
    void Refresh();
    void ChangeOverlay(Overlay overlay);
    void SubtractMinutes();
    void TurnOn(bool on);
};