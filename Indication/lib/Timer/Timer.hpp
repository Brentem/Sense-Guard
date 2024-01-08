#pragma once

#include <Arduino.h>

class Timer
{
private:
    uint32_t prevMillis;
    uint32_t interval;
    bool started;
    bool finished;

public:
    Timer(uint32_t interval);
    void Start();
    void Run();
    void Stop();
    bool Started();
    bool Finished();
};