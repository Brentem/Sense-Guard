#include "BTComm.hpp"

#include <Arduino.h>

BTComm::BTComm()
{
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        buf[i] = '\0';
    }

    receiving = false;
    received = false;
    counter = 0;
}

void BTComm::Begin()
{
    Serial.begin(9600);
}

void BTComm::Reading()
{
    if(!Serial.available())
        return;

    char receivedChar = Serial.read();

    if(receivedChar == END_CHAR)
    {
        receiving = false;
        received = true;
        buf[counter] = '\0';
    }

    if(receiving)
    {
        buf[counter] = receivedChar;
        counter++;
    }

    if(receivedChar == START_CHAR)
    {
        receiving = true;
        received = false;
        counter = 0;
    }
}

bool BTComm::Received()
{
    return received;
}

char* BTComm::GetMessage()
{
    char* bufPtr = nullptr;

    if(received)
    {
        bufPtr = buf;
        received = false;
    }

    return bufPtr;
}

void BTComm::EmptyBuffer()
{
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        buf[i] = '\0';
    }

    received = false;
    receiving = false;
    counter = 0;
}