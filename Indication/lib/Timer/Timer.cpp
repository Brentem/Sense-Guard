#include "Timer.hpp"

Timer::Timer()
{
    prevMillis = 0;
    interval = 0;
}

void Timer::Start(uint32_t interval)
{
    prevMillis = millis();
    this->interval = interval;
}

bool Timer::TimerFinished()
{
    bool finished = false;

    uint32_t currMillis = millis();
    if(currMillis >= (prevMillis + interval))
    {
        finished = true;
        prevMillis = currMillis;
    }

    return finished;
}