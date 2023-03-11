#include "matrix.h"
#include <stdexcept>

//Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows * cols, 0) {}

//Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(other.data) {}

//Matrix::~Matrix() {}

//int Matrix::getRows() const {
//    return rows;
//}

//int Matrix::getCols() const {
//    return cols;
//}

matrix m1;
matrix m2;

void initialize(matrix &m) {
    cin >> m.cols;
    cin >> m.rows;
    for (int i = 0; i < m.cols; i++) {
        for (int j = 0; j < m.rows; j++) {
            cin >> m.data[i][j];
        }
    }
}

double returnData(int i, int j, matrix m) {
    if ((i < 0 || i >= m.rows) && (j < 0 || j >= m.cols)) {
        throw out_of_range("Matrix index out of range");
    }
    return m.data[i * m.cols][j];
}

//double Matrix::operator()(int i, int j) const {
//    if (i < 0 || i >= rows &&
//    j < 0 || j >= cols) {
//        throw std::out_of_range("Matrix index out of range");
//    }
//    return data[i * cols][j];
//}

matrix inverse(matrix m) {
    if (m.rows != m.cols) {
        throw invalid_argument("Matrix must be square");
    }

    matrix result;
    result.rows = m.rows;
    result.cols = m.cols;
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; i++) {
            result.data[i][j] = 1;
        }
    }

//    Matrix tmp(*this);
    matrix tmp = m;

    for (int i = 0; i < m.rows; i++) {
        int pivotRowIndex = findPivotRowIndex(i, tmp);
        if (pivotRowIndex == -1) {
            throw invalid_argument("Matrix is singular");
        }
        if (pivotRowIndex != i) {
            swapRows(i, pivotRowIndex, tmp);
            swapRows(i, pivotRowIndex, result);
        }
        double pivotValue = returnData(i, i, tmp);
        scaleRow(i, 1 / pivotValue, tmp);
        scaleRow(i, 1 / pivotValue, result);
        for (int j = i + 1; j < m.rows; j++) {
            double factor = returnData(j, i, tmp);
            addMultipleOfRow(j, i, -factor, tmp);
            addMultipleOfRow(j, i, -factor, result);
        }
    }

    for (int i = m.rows - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            double factor = returnData(j, i, tmp);
            addMultipleOfRow(j, i, -factor, tmp);
            addMultipleOfRow(j, i, -factor, result);
        }
    }
    return result;
}

void swapRows(int i, int j, matrix &m) {
    for (int k = 0; k < m.cols; k++) {
        swap(m.data[i][k], m.data[j][k]);
    }
}

void scaleRow(int i, double scalar, matrix &m) {
    for (int j = 0; j < m.cols; j++) {
        m.data[i][j] *= scalar;
    }
}

void addMultipleOfRow(int i, int j, double scalar, matrix &m) {
    for (int k = 0; k < m.cols; k++) {
        m.data[i][k] += scalar * m.data[j][k];
    }
}

int findPivotRowIndex(int startRow, matrix m) {
    int pivotRowIndex = -1;
    double pivotMax = 0;
    for (int i = startRow; i < m.rows; i++) {
        double rowMax = 0;
        for (int j = 0; j < m.cols; j++) {
            rowMax = max(rowMax, abs(m.data[i][j]));
        }
        if (rowMax > pivotMax) {
            pivotRowIndex = i;
            pivotMax = rowMax;
        }
    }
    return pivotRowIndex;
}