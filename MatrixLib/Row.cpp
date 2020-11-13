#include "pch.h"
#include "Matrix.h"
#include "Row.h"
#include <string>
#include <stdexcept>

Row::Row(double* elementPtr, const size_t columns) : ptr(elementPtr), columns(columns)
{
}

double& Row::operator[](const size_t coulumn)
{
	if (coulumn >= columns)
		throw std::invalid_argument(std::string("Column value larger than maximum culomns available! Range is 0.." + std::to_string(columns)));

	return ptr[coulumn];
}