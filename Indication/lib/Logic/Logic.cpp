#include "Logic.hpp"

Logic::Logic()
{
    timer = new Timer(1000);
}

void Logic::Start()
{
    controller.Initialize();
    controller.ChangeOverlay(Overlay::OCCUPIED);
}

void Logic::Run()
{
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