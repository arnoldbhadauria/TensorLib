#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::cerr;

typedef vector<double> matrix;
typedef vector<vector<double>> matrix2d;

class Tensor{

    bool checkMatrixValidity(const matrix2d& m){
        int n=m[0].size();
        for(int i=0;i<m.size();++i){
            if(m[i].size()==n){
                continue;
            }else{
                cerr<<"Matrix is not valid."<<endl;
                return false;
            }
        }
        return true;
    }

    bool equivalence(const matrix2d& m1, const matrix2d& m2){
        if(checkMatrixValidity(m1) && checkMatrixValidity(m2)){
            if(m1.size()==m2.size() && m1[0].size()==m2[0].size()){
                return true;
            }else{
                cerr<<"Matrices are not of same dimensions."<<endl;
                return false;
            }
        }else{
            return false;
        }
    }

    bool canMultiply(const matrix2d& m1, const matrix2d& m2){
        if(checkMatrixValidity(m1) && checkMatrixValidity(m2)){
            if(m1[0].size()==m2.size()){
                return true;
            }else{
                cerr<<"Can't multiply matrices. Both matrices are not compatible."<<endl;
                return false;
            }
        }else{
            return false;
        }
    }

    bool isSquareMatrix(const matrix2d& m){
        if(checkMatrixValidity(m)){
            int r=m.size();
            int c=m[0].size();
            if(r==c){
                return true;
            }else{
                cerr<<"Matrix is not a square matrix."<<endl;
                return false;
            }
        }else{
            return false;
        }
    }

    public: // public functions
    matrix2d addMatrix(const matrix2d& m1, const matrix2d& m2){
        if(equivalence(m1,m2)){
            int r=m1.size();
            int c=m1[0].size();
            matrix2d m3(r, matrix(c));
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    m3[i][j]=m1[i][j]+m2[i][j];
                }
            }
            return m3;
        }
        return {};
    }

    matrix2d diffMatrix(const matrix2d& m1, const matrix2d& m2){
        if(equivalence(m1,m2)){
            int r=m1.size();
            int c=m1[0].size();
            matrix2d m3(r, matrix(c));
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    m3[i][j]=m1[i][j]-m2[i][j];
                }
            }
            return m3;
        }
        return {};
    }

    matrix2d productMatrix(const matrix2d& m1, const matrix2d& m2){
        if(canMultiply(m1, m2)){
            int r=m1.size();
            int c=m2[0].size();
            matrix2d m3(m1.size(), matrix(m2[0].size(),0.0));
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    for(int k=0;k<m1.size();++k){
                        m3[i][j]+=m1[i][k]*m2[k][j];
                    }
                }
            }
            return m3;
        }
        return {};
    }

    // Helper: get minor matrix
    matrix2d getMinor(const matrix2d& m, int row, int col) {
        int n = m.size();
        matrix2d minor(n - 1, matrix(n - 1));
        int r = 0, c = 0;

        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            c = 0;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                minor[r][c] = m[i][j];
                c++;
            }
            r++;
        }
        return minor;
    }

    double determinant(const matrix2d& m){
        if(isSquareMatrix(m)){
            if(m.size()==1){
                return m[0][0];
            }else if(m.size()==2){
                return m[0][0]*m[1][1]-m[0][1]*m[1][0];
            }else if(m.size()==3){
                return m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]) - m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[0][2]) + m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
            }else if(m.size()>3){
                int n = m.size();
                matrix2d mat = m; // make a copy
                double det = 1.0;

                for (int i = 0; i < n; i++) {
                    // Find pivot
                    int pivot = i;
                    for (int j = i + 1; j < n; j++) {
                        if (fabs(mat[j][i]) > fabs(mat[pivot][i])) {
                            pivot = j;
                        }
                    }

                    // If pivot is zero, determinant is zero
                    if (fabs(mat[pivot][i]) < 1e-9) return 0.0;

                    // Swap rows if needed
                    if (pivot != i) {
                        std::swap(mat[i], mat[pivot]);
                        det *= -1; // row swap changes sign
                    }

                    // Multiply determinant by pivot element
                    det *= mat[i][i];

                    // Eliminate below pivot
                    for (int j = i + 1; j < n; j++) {
                        double factor = mat[j][i] / mat[i][i];
                        for (int k = i; k < n; k++) {
                            mat[j][k] -= factor * mat[i][k];
                        }
                    }
                }

                return det;
            }
        }else{
            return NAN;
        }
    }
    // Adjoint function
    matrix2d adjointMatrix(const matrix2d& mat) {
        int n = mat.size();
        matrix2d adj(n, vector<double>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix2d minor = getMinor(mat, i, j);
                double cofactor = ((i+j)%2==0 ? 1 : -1) * determinant(minor);
                adj[j][i] = cofactor; // transpose step
            }
        }
        return adj;
    }

    matrix2d inverseMatrix(const matrix2d& m){
        if(checkMatrixValidity(m)){
            matrix2d adj=adjointMatrix(m);
            scalarProduct(adj,(1/determinant(m)));
            return adj;
        }else{
            return {};
        }
    }

    void transpose(matrix2d& m){
        if(checkMatrixValidity(m)){
            int r=m.size();
            int c=m[0].size();
            matrix2d m3=m;
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    m[j][i]=m3[i][j];
                }
            }
        }
    }

    void scalarProduct(matrix2d& m, double scalar){
        if(checkMatrixValidity(m)){
            int r=m.size();
            int c=m[0].size();
            for(int i=0;i<r;++i){
                for(int j=0;j<c;++j){
                    m[i][j]*=scalar;
                }
            }
        }
    }

    void printVector(const matrix2d& arr){
        if(checkMatrixValidity(arr)){
            cout<<"{"<<endl;
            for(int i=0;i<arr.size();++i){
                cout<<"\t{ ";
                for(int j=0;j<arr[0].size();++j){
                    cout<<arr[i][j]<<" ";
                }
                cout<<"},"<<endl;
            }
            cout<<"}"<<endl;
        }
    }
};

// main function
int main(int argc, char *argv[]){
    Tensor t;
    matrix2d v1={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    matrix2d v2={
        {1,2,1,2},
        {3,1,1,4},
        {1,3,1,1},
        {4,1,1,2}
    };

    t.printVector(v2);
    matrix2d inverse = t.inverseMatrix(v2);
    t.printVector(inverse);
    return 0;
}