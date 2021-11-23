#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

bool double_control(char* xn);
double double_checker();
bool int_control(char* xn);
int int_checker();

Matrix::Matrix() {
    rows = 0;
    columns = 0;
    data = NULL;
}
Matrix::Matrix(int rows, int columns) {
    if (rows > 0)
        this->rows = rows;
    else throw "Недопустимое значение!";
    if (columns > 0)
        this->columns = columns;
    else throw "Недопустимое значение!";

    data = new double* [rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            data[i][j] = 1;
}
Matrix::Matrix(Matrix& rhs) {
    rows = rhs.rows;
    columns = rhs.columns;
    data = new double* [rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            data[i][j] = rhs(i, j);
}

int Matrix::GetRows() const {
    return rows;
}
int Matrix::GetCols() const {
    return columns;
}
double& Matrix::operator () (int i, int j) {
    if ((i >= 0) && (i < rows) && (j >= 0) && (j < columns))
        return data[i][j];
    else throw "Некорректные значения индексов!";
}
Matrix Matrix::operator + (const Matrix& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }
    throw "Размерности матриц не совпадают! Сложение матриц с разными размерностями недопустимо!";
}
Matrix Matrix::operator - (const Matrix& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.data[i][j] = data[i][j] - rhs.data[i][j];
        return result;
    }
    throw "Размерности матриц не совпадают! Вычитание матриц с разными размерностями недопустимо!";
}
Matrix Matrix::operator * (const Matrix& rhs) {
    if (columns == rhs.rows) {
        Matrix result(rows, rhs.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                result.data[i][j] = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                for (int k = 0; k < columns; k++)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }
    throw "Матрицы не могут быть перемножены! Недопустимая размерность!";
}
Matrix Matrix::operator * (const double h) {
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.data[i][j] = data[i][j] * h;
    return result;
}
Matrix Matrix::operator / (const double h) {
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.data[i][j] = data[i][j] / h;
    return result;
}
double Matrix::tr() {
    double trace = 0;
    for (int i = 0; i < rows; i++)
        trace += data[i][i];
    return trace;
}

void Matrix::EnterMatrix() {
    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;

    cout << "Введите размерность матрицы:" << endl;
    cout << "Количество строк: ";
    int newRows = int_checker();
    cout << "Количество столбцов: ";
    int newColumns = int_checker();

    Matrix newMatrix(newRows, newColumns);
    for (int i = 0; i < newRows; i++)
        for (int j = 0; j < newColumns; j++) {
            cout << "Ячейка (" << i << ", " << j << ") = ";
            newMatrix.data[i][j] = double_checker();
        }

    rows = newRows;
    columns = newColumns;
    data = new double* [rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            data[i][j] = newMatrix.data[i][j];
}
Matrix operator * (double h, Matrix matrix) {
    Matrix result(matrix.GetRows(), matrix.GetCols());
    result = matrix * h;
    return result;
}
Matrix operator / (double h, Matrix matrix) {
    Matrix result(matrix.GetRows(), matrix.GetCols());
    result = matrix / h;
    return result;
}
ostream& operator<< (ostream& s, const Matrix& matrix) {

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++)
            s << matrix.data[i][j] << " ";
        s << "\n";
    }
    return s;
}
