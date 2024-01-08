#pragma once

#include <Arduino.h>

enum Overlay
{
    AVAILABLE,
    OCCUPIED
};

class LedMatrixController{
private:
    Overlay overlay;
    int8_t minutes;

    void availableOverlay();
    void occupiedOverlay();

public:
    LedMatrixController();
    void Initialize();
    void Refresh();
    void ChangeOverlay(Overlay overlay);
    void SubtractMinutes();
};