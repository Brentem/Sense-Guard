#include "LedStripController.hpp"

LedStripController::LedStripController()
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB::Black;
    }

    state = OFF;
}

void LedStripController::Initialize()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void LedStripController::Refresh()
{
    switch (state)
    {
    case OFF:
        fillLeds(CRGB::Black);
        break;

    case GREEN:
        fillLeds(CRGB::Green);
        break;

    case RED:
        fillLeds(CRGB::Red);
        break;
    
    default:
        fillLeds(CRGB::Purple);
        break;
    }

    FastLED.show();
}

void LedStripController::ChangeState(LedState state)
{
    this->state = state;
}

void LedStripController::fillLeds(CRGB::HTMLColorCode colorCode)
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = colorCode;
    }
}
