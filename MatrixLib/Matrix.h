#pragma once
#include "Row.h"

#include <string>

class Matrix
{
public:
	Matrix();
	Matrix(const size_t rows, const size_t columns);
	Matrix(const size_t rows, const size_t columns, double*& elements);
	Matrix(const Matrix& matr);
	~Matrix();

	Matrix& operator=(const Matrix& matr);
	static Matrix Sum(const Matrix& matr1, const Matrix& matr2);
	Matrix operator+(const Matrix& matr);
	Matrix Sum(const Matrix& matr);
	static Matrix Mult(Matrix& matr1, Matrix& matr2);
	Matrix Mult(Matrix& matr);
	Matrix operator*(Matrix& matr);
	static Matrix Mult(const Matrix& matr, const double num);
	Matrix Mult(const double num);
	Matrix operator*(const double num);
	Row operator[](const size_t row);
	double Trace();
	void Input();
	void Print();
	void Fill(const double num);
	size_t GetRows();
	size_t GetColumns();
	bool Dispose();
private:
	size_t rows, columns;
	double* elements;

	void static CheckMatrix(const size_t rows, const size_t columns);
	std::string static ReadLine();
	bool static ReadDouble(double& num);
};