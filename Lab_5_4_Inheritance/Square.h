#pragma once
#include "Position.h"
class Square :
    public Position
{
public:
    Square(double a);
    Square(double x, double y, double a);
    Square(const Position& pos, double a);

    double GetSide();

private:
    double a;
};

