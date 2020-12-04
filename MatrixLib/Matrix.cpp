#include "pch.h"
#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <limits>

Matrix::Matrix() : rows(0), columns(0), elements(nullptr)
{
}

Matrix::Matrix(const size_t rows, const size_t columns)
	: rows(rows), columns(columns)
{
	if (rows == 0 || columns == 0)
		throw std::invalid_argument("Matrix size can't be zero");

	Matrix::CheckMatrix(rows, columns);

	elements = new double[rows * columns]{ 0 };
}

Matrix::Matrix(const size_t rows, const size_t columns, double*& elements) : rows(rows), columns(columns)
{
	Matrix::CheckMatrix(rows, columns);

	this->elements = elements;
}

Matrix::Matrix(const Matrix& matr) : rows(matr.rows), columns(matr.columns)
{
	Matrix::CheckMatrix(rows, columns);

	size_t size = rows * columns;

	elements = new double[size];
	std::copy(&matr.elements[0], &matr.elements[0] + size, elements);
}

Matrix::~Matrix()
{
	Dispose();
}

void Matrix::CheckMatrix(const size_t rows, const size_t columns)
{
	if (rows == 0 || columns == 0)
		throw std::invalid_argument("Matrix size can't be zero");

	if (std::numeric_limits<size_t>::max() < unsigned long long(rows) * unsigned long long(columns))
		throw std::invalid_argument(
			std::string("Size of matrix is too high (more than " + std::to_string(std::numeric_limits<size_t>::max()) + ")"));
}

std::string Matrix::ReadLine()
{
	std::string buf;
	std::getline(std::cin, buf);
	return buf;
}

bool Matrix::ReadDouble(double& num)
{
	try
	{
		num = std::stod(ReadLine());
	}
	catch (const std::exception&)
	{
		return false;
	}

	return true;
}

Matrix& Matrix::operator=(const Matrix& matr)
{
	if (&matr == this)
		return *this;

	size_t size = rows * columns;

	if (size != matr.rows * matr.columns)
	{
		if(elements != nullptr)
			delete[] elements;

		size = matr.rows * matr.columns;

		elements = new double[size];
	}

	rows = matr.rows;
	columns = matr.columns;

	std::copy(&matr.elements[0], &matr.elements[0] + size, &elements[0]);
	return *this;
}

Matrix Matrix::Sum(const Matrix& matr1, const Matrix& matr2)
{
	if (matr1.rows != matr2.rows || matr1.columns != matr2.columns)
		throw std::invalid_argument("Matricies can be added only if they are equal in size");

	double* sElements = new double[matr1.rows * matr1.columns];

	for (size_t i = 0, elmCnt = matr1.rows * matr1.columns; i < elmCnt; i++)
		sElements[i] = matr1.elements[i] + matr2.elements[i];

	return Matrix(matr1.rows, matr1.columns, sElements);
}

Matrix Matrix::operator+(const Matrix& matr)
{
	return Matrix::Sum(*this, matr);
}

Matrix Matrix::Sum(const Matrix& matr)
{
	return Matrix::Sum(*this, matr);
}

Matrix Matrix::Mult(Matrix& matr1, Matrix& matr2)
{
	if (matr1.columns != matr2.rows)
		throw std::invalid_argument("Can not multiply matricies as number of columns of matr1 is not equal to number of rows of matr2");

	Matrix::CheckMatrix(matr1.rows, matr2.columns);

	const size_t rows = matr1.rows;
	const size_t columns = matr2.columns;

	double* elements = new double[rows * columns]{ 0 };

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			double e = 0;
			for (size_t m = 0; m < columns; m++)
			{
				e += matr1[i][m] * matr2[m][j];
			}

			(elements + i * columns)[j] = e;
		}
	}

	return Matrix(rows, columns, elements);
}

Matrix Matrix::Mult(Matrix& matr)
{
	return Matrix::Mult(*this, matr);
}

Matrix Matrix::operator*(Matrix& matr)
{
	return Matrix::Mult(matr);
}

Matrix Matrix::Mult(const Matrix& matr, const double num)
{
	size_t size = matr.rows * matr.columns;
	double* elements = new double[size];

	for (size_t i = 0; i < size; i++)
		elements[i] = matr.elements[i] * num;

	return Matrix(matr.rows, matr.columns, elements);
}

Matrix Matrix::Mult(const double num)
{
	return Matrix::Mult(*this, num);
}

Matrix Matrix::operator*(const double num)
{
	return Matrix::Mult(*this, num);
}

Row Matrix::operator[](const size_t row)
{
	if (row >= rows)
		throw std::invalid_argument(std::string("Row value larger than maximum rows available! Range is 0.." + std::to_string(rows - 1)));

	return Row(elements + row * columns, columns);
}

double Matrix::Trace()
{
	if (rows != columns)
		throw std::invalid_argument("Trace can be done for square matricies only");

	double t = 0;

	for (size_t i = 0; i < rows; i++)
		t += this->operator[](i)[i];

	return t;
}

void Matrix::Input()
{
	printf_s("Input matrix now. Format is [row, column] = value\n");
	
	double elm;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
		{
			do
			{
				printf_s("[%d, %d] = ", i, j);
			} while (!ReadDouble(elm));
			
			this->operator[](i)[j] = elm;
		}
}

void Matrix::Print()
{
	printf_s(" i, j\n");

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
		{
			printf_s("[%u, %u] = %f\n", i, j, this->operator[](i)[j]);
		}
}

void Matrix::Fill(const double num)
{
	size_t elmCnt = rows * columns;
	for (size_t i = 0; i < elmCnt; i++)
		elements[i] = num;
}

size_t Matrix::GetRows()
{
	return rows;
}

size_t Matrix::GetColumns()
{
	return columns;
}

bool Matrix::Dispose()
{
	if (elements == nullptr)
		return false;

	delete[] elements;
	elements = nullptr;
	rows = 0;
	columns = 0;
	return true;
}

std::istream& operator>>(std::istream& in, Matrix& matr)
{
	matr.Dispose();

	in >> matr.rows;
	in >> matr.columns;

	Matrix::CheckMatrix(matr.rows, matr.columns);

	matr.elements = new double[matr.rows * matr.columns];

	for (size_t i = 0; i < matr.columns * matr.rows; i++)
		in >> matr.elements[i];

	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matr)
{
	out << matr.rows << std::endl;
	out << matr.columns << std::endl;

	for (size_t i = 0; i < matr.rows * matr.columns; i++)
		out << matr.elements[i] << std::endl;

	return out;
}
