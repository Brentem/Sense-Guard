#include "Logic.hpp"

const char* AVAILABLE_MSG = "Available";
const char* OCCUPIED_MSG = "Occupied";

uint8_t counter = 0;
uint8_t nogEen = 0;

// char* msg = NULL;

Logic::Logic()
{
    timer = new Timer(1000);
}

void Logic::Start()
{
    comm.Begin();
    controller.Initialize();
    controller.ChangeOverlay(Overlay::OCCUPIED);
    // controller.Refresh();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void Logic::Run()
{
    // if(nogEen == 2)
    // {
    //     comm.Reading();
    // }
    // else if(nogEen == 6)
    // {
    //     if(comm.Received())
    //     {
    //         msg = comm.GetMessage();
    //     }
    // }
    // else if(nogEen == 10)
    // {
    //     Serial.print("t");

    // // Dit stuk will helemaal niet werken
    // //     if(msg != NULL)
    // //     {
    // //         // Serial.print("T");
    // //         if(strcmp(msg, AVAILABLE_MSG) == 0)
    // //         {
    // //             controller.ChangeOverlay(Overlay::AVAILABLE);
    // //         }
    // //         else if(strcmp(msg, OCCUPIED_MSG) == 0)
    // //         {
    // //             controller.ChangeOverlay(Overlay::OCCUPIED);
    // //         }

    // //         msg = NULL;
    // //     }

    //     comm.EmptyBuffer();
    // }

    if(nogEen < 5)  
    {
        comm.Reading();

        char buffer[BUFFER_SIZE] = {0};
        bool received = comm.GetMessage2(buffer);

        if(received)
        {
            if(strcmp(buffer, AVAILABLE_MSG) == 0)
            {
                controller.ChangeOverlay(Overlay::AVAILABLE);
            }
            else if(strcmp(buffer, OCCUPIED_MSG) == 0)
            {
                controller.ChangeOverlay(Overlay::OCCUPIED);
            }
        }
    }

    if(!timer->Started())
    {
        timer->Start();
    }

    timer->Run();

    if(timer->Finished())
    {
        controller.SubtractMinutes();
        // controller.Refresh();
        counter++;
        nogEen++;

        if(counter == 2)
        {
            counter = 0;
        }

        if(nogEen == 10)
        {
            nogEen = 0;
            controller.Refresh();
        }
    }

    if(counter < 1)
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW);

    }

    // controller.Refresh();
}