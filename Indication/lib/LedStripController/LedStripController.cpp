#include "LedStripController.hpp"

const CRGB redColor = CRGB(128, 0, 0);
const CRGB greenColor = CRGB(0, 128, 0);

LedStripController::LedStripController()
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds_1[i] = CRGB::Black;
        leds_2[i] = CRGB::Black;
    }

    state = OFF;
}

void LedStripController::Initialize()
{
    FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds_1, NUM_LEDS);
    FastLED.addLeds<WS2812B, DATA_PIN_2, GRB>(leds_2, NUM_LEDS);
}

void LedStripController::Refresh()
{
    switch (state)
    {
    case OFF:
        fillLeds(CRGB::Black);
        break;

    case GREEN:
        // fillLeds(CRGB::Green);
        fillLeds(greenColor);
        break;

    case RED:
        // fillLeds(CRGB::Red);
        fillLeds(redColor);
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

void LedStripController::TurnOn(bool on)
{
    if(on)
    {
        state = LedState::GREEN;
    }
    else
    {
        state = LedState::OFF;
    }
}

void LedStripController::fillLeds(CRGB color)
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds_1[i] = color;
        leds_2[i] = color;
    }
}

void LedStripController::fillLeds(CRGB::HTMLColorCode colorCode)
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds_1[i] = colorCode;
        leds_2[i] = colorCode;
    }
}
