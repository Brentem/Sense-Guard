#pragma once

#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 11

enum LedState
{
    OFF,
    GREEN,
    RED
};

class LedStripController
{
private:
    CRGB leds[NUM_LEDS];
    LedState state;

    void fillLeds(CRGB::HTMLColorCode colorCode);

public:
    LedStripController();
    void Initialize();
    void Refresh();
    void ChangeState(LedState state);
};