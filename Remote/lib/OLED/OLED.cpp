#include "OLED.hpp"

// SCL A5
// SDA A4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

OLED::OLED()
{
    minutes = 59;
    seconds = 59;
}

void OLED::Initialize()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
    display.display();
  
    display.clearDisplay();
    display.setFont(&FreeSans9pt7b);
    display.setTextColor(WHITE);
    display.setCursor(0, 40);
    display.print("SENSE GUARD");
    display.display();
    delay(2000);
}

void OLED::StartSession()
{
    display.clearDisplay();

    display.setFont(&FreeSans12pt7b);
    display.setCursor(26,25);
    display.print("START");

    display.setFont(&FreeSans12pt7b);
    display.setCursor(22,55);
    display.print("SESSIE");

    display.display();
}

void OLED::Countdown()
{
    display.clearDisplay();

    display.setFont();
    display.setCursor(23,0);
    display.print("Tijd resterend");

    display.setFont(&FreeSansBold24pt7b);
    display.setCursor(5,50);
    display.print(minutes);
    display.print(':');
    display.print(seconds);

    display.display();
}

void OLED::Duration()
{
    display.clearDisplay();

    display.setFont();
    display.setCursor(30,10);
    display.print("Duur sessie:");

    display.setFont(&FreeSans12pt7b);
    display.setCursor(35,45);
    display.print(minutes);
    display.print(':');
    display.print(seconds);

    display.display();
}

void OLED::Clear()
{
    display.clearDisplay();
    display.setFont();
    display.setCursor(0, 0);
    display.display();
}