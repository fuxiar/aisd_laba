#pragma once
#include <iostream>
class Matrix {
private:
	int rows, columns;
	double** data;

public:
	Matrix();
	Matrix(int rows, int columns);
	Matrix(Matrix& rhs);
	int GetRows() const;
	int GetCols() const;
	double& operator () (int i, int j);
	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator * (const Matrix& rhs);
	Matrix operator * (const double h);
	Matrix operator / (const double h);
	friend Matrix operator * (double h, Matrix matrix);
	friend Matrix operator / (double h, Matrix matrix);
	double tr();

	void EnterMatrix();
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
};

