//#ifndef MATRIX_H
//#define MATRIX_H

#include <iostream>
#include "cmath"
#include "string"
using namespace std;


struct matrix {
    int rows;
    int cols;
    double **data;
};

void initialize (matrix &m);

double returnData(int i, int j, matrix m);

matrix inverse(matrix m);

void swapRows(int i, int j, matrix &m);

void scaleRow(int i, double scalar, matrix &m);

void addMultipleOfRow(int i, int j, double scalar, matrix &m);

int findPivotRowIndex(int startRow, matrix &m);


//class Matrix {
//public:
//    Matrix(int rows, int cols);
//
//    Matrix(const Matrix &other);
//
//    ~Matrix();
//
//    int getRows() const;
//
//    int getCols() const;
//
//    double &operator()(int i, int j);
//
//    double operator()(int i, int j) const;
//
//    Matrix inverse() const;

//private:
//
//
//    void swapRows(int i, int j);
//
//    void scaleRow(int i, double scalar);
//
//    void addMultipleOfRow(int i, int j, double scalar);
//
//    int findPivotRowIndex(int startRow) const;
//};

//#endif