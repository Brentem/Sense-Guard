#include "Logic.hpp"

const char* AVAILABLE_MSG = "Available";
const char* OCCUPIED_MSG = "Occupied";

Logic::Logic()
{
    timer = new Timer(1000);
}

void Logic::Start()
{
    comm.Begin();
    controller.Initialize();
    controller.ChangeOverlay(Overlay::OCCUPIED);
}

void Logic::Run()
{
    comm.Reading();
    
    if(comm.Received())
    {
        char* msg = comm.GetMessage();

        if(msg != nullptr)
        {
            if(strcmp(msg, AVAILABLE_MSG) == 0)
            {
                controller.ChangeOverlay(Overlay::AVAILABLE);
            }
            else if(strcmp(msg, OCCUPIED_MSG) == 0)
            {
                controller.ChangeOverlay(Overlay::OCCUPIED);
            }
        }

        comm.EmptyBuffer();
    }

    if(!timer->Started())
    {
        timer->Start();
    }

    timer->Run();

    if(timer->Finished())
    {
        controller.SubtractMinutes();
    }

    controller.Refresh();
}