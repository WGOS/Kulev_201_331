#pragma once
class Row {
public:
	Row(double* elementPtr, const size_t columns);
	double& operator[](const size_t coulumn);

private:
	const size_t columns;
	double* ptr;
};