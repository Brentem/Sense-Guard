#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

class OLED
{
private:
    uint8_t minutes;
    uint8_t seconds;

public:
    OLED();
    void Initialize();
    void StartSession();
    void Countdown();
    void Duration();
    void Clear();
    void AddSecond();
    void ClearSeconds();
};