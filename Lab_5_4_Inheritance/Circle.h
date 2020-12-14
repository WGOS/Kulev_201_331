#pragma once
#include "Position.h"
class Circle :
    public Position
{
public:
    Circle(double radius);
    Circle(double x, double y, double radius);
    Circle(const Position& pos, double radius);

    double GetRadius();
    double GetDiameter();
private:
    double r;
};

