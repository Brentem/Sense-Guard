#pragma once

#include <Arduino.h>
#include <Timer.hpp>

#define ELEMENTS_NR 2

struct DispatchElements
{
    Timer timer;
    bool isFree;
    void (*functionPtr)();
};

class Dispatcher
{
private:
    DispatchElements elements[ELEMENTS_NR];

public:
    Dispatcher();
    void DoDispatch();
    bool AllocSlot(uint32_t interval, void (*functionPtr)(), uint8_t slotId);
    bool FreeSlot(uint8_t slotId);
};