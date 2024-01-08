#pragma once

#include <Timer.hpp>
#include <LedMatrixController.hpp>

class Logic
{
private:
    Timer* timer;
    LedMatrixController controller;

public:
    Logic();
    void Start();
    void Run();
};