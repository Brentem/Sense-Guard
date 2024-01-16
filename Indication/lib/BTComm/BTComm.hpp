#pragma once

#define BUFFER_SIZE 16

#define START_CHAR '!'
#define END_CHAR '&'

class BTComm
{
private:
    int counter;
    char buf[BUFFER_SIZE];
    bool receiving;
    bool received;

public:
    BTComm();
    void Begin();
    void Reading();
    bool Received();
    char* GetMessage();
    void EmptyBuffer();
};