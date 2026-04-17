#ifndef TENSOR_H
#define TENSOR_H

#include <vector>
#include <string>

typedef std::vector<double> matrix;
typedef std::vector<std::vector<double>> matrix2d;

namespace Tensor {


    bool checkMatrixValidity(const matrix2d& m);
    bool equivalence(const matrix2d& m1, const matrix2d& m2);
    bool canMultiply(const matrix2d& m1, const matrix2d& m2);
    bool isSquareMatrix(const matrix2d& m);

    matrix2d addMatrix(const matrix2d& m1, const matrix2d& m2);
    matrix2d subtractMatrix(const matrix2d& m1, const matrix2d& m2);
    matrix2d multiplyMatrix(const matrix2d& m1, const matrix2d& m2);

    matrix2d getMinor(const matrix2d& m, int row, int col);
    double determinant(const matrix2d& m);

    matrix2d adjointMatrix(const matrix2d& mat);
    matrix2d inverseMatrix(const matrix2d& m);

    void transpose(matrix2d& m);
    void scalarProduct(matrix2d& m, double scalar);

    void printVector(const matrix2d& arr);
};

#endif
