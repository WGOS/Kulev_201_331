#include "Square.h"

Square::Square(double a) : Square(0, 0, a) {}

Square::Square(double x, double y, double a) : Position(x, y)
{
	this->a = a;
}

Square::Square(const Position& pos, double a) : Position(pos)
{
	this->a = a;
}

double Square::GetSide()
{
	return a;
}
