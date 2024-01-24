#pragma once

#include <FastLED.h>

#define NUM_LEDS 45 // Final result should be 30
#define DATA_PIN_1 11
#define DATA_PIN_2 12

enum LedState
{
    OFF,
    GREEN,
    RED
};

class LedStripController
{
private:
    CRGB leds_1[NUM_LEDS];
    CRGB leds_2[NUM_LEDS];
    LedState state;

    void fillLeds(CRGB color);
    void fillLeds(CRGB::HTMLColorCode colorCode);

public:
    LedStripController();
    void Initialize();
    void Refresh();
    void ChangeState(LedState state);
    void TurnOn(bool on);
};