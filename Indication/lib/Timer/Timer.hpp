#pragma once

#include <Arduino.h>

struct Timer
{
    uint32_t prevMillis;
    uint32_t interval;

    Timer();
    void Start(uint32_t interval);
    bool TimerFinished();
};