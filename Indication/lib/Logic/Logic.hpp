#pragma once

#include <Timer.hpp>
#include <LedMatrixController.hpp>
#include <BTComm.hpp>

class Logic
{
private:
    // Timer* timer;
    LedMatrixController controller;
    BTComm comm;

public:
    Logic();
    void Start();
    void Run();
};