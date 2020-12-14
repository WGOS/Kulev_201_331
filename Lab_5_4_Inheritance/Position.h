#pragma once
class Position
{
public:
	explicit Position();
	explicit Position(double x, double y);
	explicit Position(const Position& pos);

	double x;
	double y;
};

