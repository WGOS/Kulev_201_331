#include "Position.h"

Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(double x, double y)
{
	this->x = x;
	this->y = y;
}

Position::Position(const Position& pos)
{
	x = pos.x;
	y = pos.y;
}
