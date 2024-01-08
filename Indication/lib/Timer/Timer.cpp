#include "Timer.hpp"

Timer::Timer(uint32_t interval)
{
    prevMillis = 0;
    this->interval = interval;
    started = false;
    finished = false;
}

void Timer::Start()
{
    prevMillis = millis();
    started = true;
}

void Timer::Run()
{
    if(!started)
        return;

    uint32_t currMillis = millis();

    if((currMillis - prevMillis) >= interval)
    {
        finished = true;
        started = false;
    }
}

void Timer::Stop()
{
    started = false;
    finished = false;
}

bool Timer::Started()
{
    return started;
}

bool Timer::Finished()
{
    bool temp = finished;
    finished = false;
    return temp;
}