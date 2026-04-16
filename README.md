# TensorLib

TensorLib is a simple C++ library for performing basic matrix (tensor) operations.

It provides implementations for common linear algebra operations such as:
- Matrix addition
- Matrix subtraction
- Matrix multiplication
- Determinant calculation
- Matrix inverse
- Transpose
- Scalar multiplication

---

## 🚀 Features

- Supports dynamic 2D matrices using `std::vector`
- Validates matrix dimensions before operations
- Efficient determinant calculation (Gaussian elimination for large matrices)
- Adjoint-based matrix inverse

---

## 🧠 Concepts Used

- Linear Algebra
- Matrix operations
- Recursion (minor & determinant)
- Gaussian elimination
- C++ STL (`vector`)

---

## 📦 Data Structures

```cpp
typedef vector<double> matrix;
typedef vector<vector<double>> matrix2d;
