#pragma once

#include <Arduino.h>

// class Timer
// {
// private:
//     uint32_t prevMillis;
//     uint32_t interval;
//     bool started;
//     bool finished;

// public:
//     explicit Timer(uint32_t interval);
//     void Start();
//     void Run();
//     void Stop();
//     bool Started();
//     bool Finished();
// };

struct Timer
{
    uint32_t prevMillis;
    uint32_t interval;

    Timer();
    void Start(uint32_t interval);
    bool TimerFinished();
};