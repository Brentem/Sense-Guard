// Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
// Arduino OLED Stopwatch

  #include <SPI.h>
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>
  #include <Fonts/FreeSans9pt7b.h>
  #include <Fonts/FreeSans12pt7b.h>
  #include <Fonts/FreeSansBold24pt7b.h>

//  #include <ezButton.h>
//  
  #define SCREEN_WIDTH 128 // OLED display width, in pixels
  #define SCREEN_HEIGHT 64 // OLED display height, in pixels
//
//  #define SWITCH_OFF 0
//  #define SWITCH_ON  1

//  ezButton button(6); // create ezButton object that attach to pin 6;
//  int switch_state = SWITCH_OFF; // initial state
  
  // SCL A5
  // SDA A4
  #define OLED_RESET 0  // GPIO0
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  
  #define LOGO_HEIGHT   16
  #define LOGO_WIDTH    16  
  
  void setup()   {
//
//    Serial.begin(9600);
//    button.setDebounceTime(50); // set debounce time to 50 milliseconds
  
    pinMode(4,INPUT_PULLUP);  //Switch red
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
    display.display();
  
  
    display.clearDisplay();
    display.setFont(&FreeSans9pt7b);
    //display.drawPixel(10, 10, SSD1306_WHITE);
    display.setTextColor(WHITE);
    display.setCursor(0, 40);
    display.print("SENSE GUARD");
      display.display();
      delay(2000);
  }
  int poz=1;
  int broj=1;
  int kretanjeY=30;
  
  int sec1=0;
  int min1=0;
  unsigned long msec=0;
  unsigned long mili=0;
  int pres=0;
  int fase=0;
  int start=0;
  unsigned long tim=0;
  
  void loop(){
//    button.loop();
//    
//      if (button.isPressed()) {
//       // change state of switch
//    if (switch_state == SWITCH_OFF)
//      switch_state = SWITCH_ON;
//    else
//      switch_state = SWITCH_OFF;
//
//    Serial.print("switch's state -> ");
//    Serial.println(switch_state);
//  }
//
//      if (switch_state == 0) {
//        clearDisplay();
//        
//        }
  
        display.clearDisplay();
        if(digitalRead(4)==1)   
        {
          if(pres==0)
             {
              fase=fase+1;
              pres=1;
              if(fase>2)
              fase=0;
              }
          
          }else{pres=0;}

  
       if(fase==0)
        {
          display.setFont(&FreeSans12pt7b);
          //display.setFont();
        display.setCursor(26,25);
        display.print("START");
       // display.drawBitmap(48, 8,  icon, 32, 32, WHITE);

          display.setFont(&FreeSans12pt7b);
          //display.setFont();
        display.setCursor(22,55);
        display.print("SESSIE");
  
  
        sec1=0;
        min1=0;
        tim=0;
        mili=0;
        msec=0;
        start=0;
        }
        
          
        if(fase==1)
        {
          display.clearDisplay();
          //display.setFont(&FreeSans12pt7b);
          display.setFont();
          display.setCursor(23,0);
          display.print("Tijd resterend");
          display.setFont(&FreeSansBold24pt7b); // tijd in midden
          
          if(start==0)
            {
              start=1;
              tim=millis();  
            }
         msec=(millis()-tim); 
  
          
        
          min1=msec/60000;
       
         
          if((msec/1000)>59)
             {
              sec1=(msec/1000)-(min1*60);
              }else{
                sec1=msec/1000;
                }
  
            mili=(msec%1000)/10;
        
             display.setCursor(5,50); //tijd in midden
             if(min1>=50) //
             {
              display.print("0");
              display.print(59-min1);
              }else {display.print(59-min1);}
  
              display.print(":");
  
               if(sec1>=50)
             {
              display.print("0");
              display.print(59-sec1);
              }else {display.print(59-sec1);}

              
//              display.setFont(&FreeSans12pt7b); //Snel oplopende text
//              display.setCursor(50,57);
  
//                    if(mili<=9)               
//             {
//              display.print("0");
//              display.print(mili);
//              }else {display.print(mili);}   
         }
  
  if(fase==2)
  {
       display.clearDisplay();
//       display.setFont(&FreeSans12pt7b);
          display.setFont();
          display.setCursor(30,10);
          display.print("Duur sessie:");
          display.setFont(&FreeSans12pt7b);
          display.setCursor(35,45);
             if(min1<=9)
             {
              display.print("0");
              display.print(min1);
              }else {display.print(min1);}
  
              display.print(":");
  
               if(sec1<=9)
             {
              display.print("0");
              display.print(sec1);
              }else {display.print(sec1);}
//              display.setFont(&FreeSans12pt7b);
//              display.setCursor(50,57);
//  
//                    if(mili<=9)
//             {
//              display.print("0");
//              display.print(mili);
//              }else {display.print(mili);}

// draw icons
               
    
    }
        
        
        display.display();
    }
