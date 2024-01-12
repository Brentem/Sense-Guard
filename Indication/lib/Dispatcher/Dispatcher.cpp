#include <Dispatcher.hpp>

Dispatcher::Dispatcher()
{
    for(int i = 0; i < ELEMENTS_NR; i++)
    {
        elements[i].functionPtr = nullptr;
        elements[i].isFree = true;
    }
}

void Dispatcher::DoDispatch()
{
    for(int i = 0; i < ELEMENTS_NR; i++)
    {
        if((!elements[i].isFree) && (elements[i].timer.TimerFinished()))
        {
            elements[i].functionPtr();
        }
    }
}

bool Dispatcher::AllocSlot(uint32_t interval, void (*functionPtr)(), uint8_t slotId)
{
    if((slotId >= ELEMENTS_NR) || (!elements[slotId].isFree))
    {
        return false;
    }

    elements[slotId].isFree = false;
    elements[slotId].functionPtr = functionPtr;
    elements[slotId].timer.Start(interval);

    return true;
}

bool Dispatcher::FreeSlot(uint8_t slotId)
{
    if((slotId >= ELEMENTS_NR) || (elements[slotId].isFree))
    {
        return false;
    }

    elements[slotId].isFree = true;
    elements[slotId].functionPtr = nullptr;
    elements[slotId].timer.interval = 0;
    elements[slotId].timer.prevMillis = 0;

    return true;
}