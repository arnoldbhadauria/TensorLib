#pragma once

#include <vector>
#include <string>

using matrix = std::vector<double>;
using matrix2d =  std::vector<std::vector<double>>;

namespace Tensor {

    enum Mode{
        VERTICAL,
        HORIZONTAL
    };

    bool checkMatrixValidity(const matrix2d& m);
    bool equivalence(const matrix2d& m1, const matrix2d& m2);
    bool canMultiply(const matrix2d& m1, const matrix2d& m2);
    bool isSquareMatrix(const matrix2d& m);

    matrix2d get2dMatrix(const matrix& m, Mode axis);
    double getRandom(double min, double max);
    matrix2d randomMatrix(int rows, int columns, double min, double max);
    std::pair<int,int> shapeOfMatrix(matrix2d m);

    matrix2d addMatrix(const matrix2d& m1, const matrix2d& m2);
    matrix2d subtractMatrix(const matrix2d& m1, const matrix2d& m2);
    matrix2d multiplyMatrix(const matrix2d& m1, const matrix2d& m2);
    matrix2d scalarProduct(const matrix2d& m, double scalar);

    matrix2d getMinor(const matrix2d& m, int row, int col);
    double determinant(const matrix2d& m);

    matrix2d adjointMatrix(const matrix2d& mat);
    matrix2d inverseMatrix(const matrix2d& m);

    matrix2d transpose(const matrix2d& m);

    void printVector(const matrix2d& arr);
    
};
