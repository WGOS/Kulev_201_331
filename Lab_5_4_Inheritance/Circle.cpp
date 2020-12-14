#include "Circle.h"

Circle::Circle(double radius) : Circle(0, 0, radius)
{
}

Circle::Circle(double x, double y, double radius) : Position(x, y)
{
	this->r = radius;
}

Circle::Circle(const Position& pos, double radius) : Position(pos)
{
	this->r = radius;
}

double Circle::GetRadius()
{
	return r;
}

double Circle::GetDiameter()
{
	return r * 2;
}
