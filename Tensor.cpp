#include "Tensor.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cerr;

// ================= PRIVATE =================

namespace Tensor{

// check for matrix validity
bool checkMatrixValidity(const matrix2d& m){
    int n = m[0].size();
    for(int i = 0; i < m.size(); ++i){
        if(m[i].size() != n){
            cerr << "Matrix is not valid." << endl;
            return false;
        }
    }
    return true;
}
// check dimensionally equivalent matrices
bool equivalence(const matrix2d& m1, const matrix2d& m2){
    if(checkMatrixValidity(m1) && checkMatrixValidity(m2)){
        if(m1.size() == m2.size() && m1[0].size() == m2[0].size()){
            return true;
        }
        cerr << "Matrices are not of same dimensions." << endl;
    }
    return false;
}
// dimensionality check for multiplication
bool canMultiply(const matrix2d& m1, const matrix2d& m2){
    if(checkMatrixValidity(m1) && checkMatrixValidity(m2)){
        if(m1[0].size() == m2.size()){
            return true;
        }
        cerr << "Can't multiply matrices." << endl;
    }
    return false;
}
// check for square matrix
bool isSquareMatrix(const matrix2d& m){
    if(checkMatrixValidity(m)){
        if(m.size() == m[0].size()){
            return true;
        }
        cerr << "Matrix is not square." << endl;
    }
    return false;
}
// convert 1d matrix into 2d matrix
matrix2d get2dMatrix(matrix m){
    matrix2d m3(m.size(),matrix(1));
    for(int i=0;i<m3.size();++i){
        for(int j=0;j<m3[0].size();++j){
            m3[i][0]=m[i];
        }
    }
    return m3;
}

// ================= PUBLIC =================

// addition of matrices
matrix2d addMatrix(const matrix2d& m1, const matrix2d& m2){
    if(!equivalence(m1, m2)) return {};

    int r = m1.size();
    int c = m1[0].size();

    matrix2d m3(r, matrix(c));
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return m3;
}
// subtraction of matrices
matrix2d subtractMatrix(const matrix2d& m1, const matrix2d& m2){
    if(!equivalence(m1, m2)) return {};

    int r = m1.size();
    int c = m1[0].size();

    matrix2d m3(r, matrix(c));
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            m3[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return m3;
}
// multiplication of matrices
matrix2d multiplyMatrix(const matrix2d& m1, const matrix2d& m2){
    if(!canMultiply(m1, m2)) return {};

    int r = m1.size();
    int c = m2[0].size();

    matrix2d m3(r, matrix(c, 0.0));

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            for(int k = 0; k < m1[0].size(); ++k){
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return m3;
}
// scalar product of matrices
matrix2d scalarProduct(matrix2d& m, double scalar){
    for(auto &row : m){
        for(auto &val : row){
            val *= scalar;
        }
    }
    return m;
}

// minor
matrix2d getMinor(const matrix2d& m, int row, int col){
    int n = m.size();
    matrix2d minor(n - 1, matrix(n - 1));

    int r = 0;
    for(int i = 0; i < n; i++){
        if(i == row) continue;

        int c = 0;
        for(int j = 0; j < n; j++){
            if(j == col) continue;
            minor[r][c++] = m[i][j];
        }
        r++;
    }
    return minor;
}
// determinant
double determinant(const matrix2d& m){
    if(!isSquareMatrix(m)) return NAN;

    int n = m.size();

    if(n == 1) return m[0][0];

    if(n == 2){
        return m[0][0]*m[1][1] - m[0][1]*m[1][0];
    }

    double det = 0.0;
    for(int j = 0; j < n; j++){
        matrix2d minor = getMinor(m, 0, j);
        det += (j % 2 == 0 ? 1 : -1) * m[0][j] * determinant(minor);
    }

    return det;
}
// adjoint
matrix2d adjointMatrix(const matrix2d& mat){
    int n = mat.size();
    matrix2d adj(n, matrix(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix2d minor = getMinor(mat, i, j);
            double cofactor = ((i+j)%2==0 ? 1 : -1) * determinant(minor);
            adj[j][i] = cofactor;
        }
    }
    return adj;
}
// inverse
matrix2d inverseMatrix(const matrix2d& m){
    if(!checkMatrixValidity(m)) return {};

    double det = determinant(m);
    if(fabs(det) < 1e-9){
        cerr << "Matrix is singular." << endl;
        return {};
    }

    matrix2d adj = adjointMatrix(m);
    scalarProduct(adj, 1.0/det);
    return adj;
}

// transpose
void transpose(matrix2d& m){
    int r = m.size();
    int c = m[0].size();

    matrix2d temp = m;
    m = matrix2d(c, matrix(r));

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            m[j][i] = temp[i][j];
        }
    }
}
// printing matrices
void printVector(const matrix2d& arr){
    cout << "{\n";
    for(const auto& row : arr){
        cout << "\t{ ";
        for(double val : row){
            cout << val << " ";
        }
        cout << "},\n";
    }
    cout << "}\n";
}

}
