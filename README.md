# TensorLib

A lightweight C++ matrix/tensor utility library for basic linear algebra operations.

Designed for learning how ML frameworks and linear algebra engines work under the hood.

---

## 🚀 Features

TensorLib supports:

* Matrix validation
* Addition / subtraction
* Matrix multiplication
* Scalar multiplication
* Transpose
* Determinant (recursive)
* Adjoint matrix
* Inverse matrix
* Random matrix generation
* Shape detection
* Pretty printing

---

## 📦 Data Types

```cpp
using matrix  = std::vector<double>;
using matrix2d = std::vector<std::vector<double>>;
```

A matrix looks like:

```
{
  {1, 2},
  {3, 4}
}
```

---

## 🧠 Namespace

All functions are inside:

```cpp
namespace Tensor
```

---

## 🔧 Setup

### Include header

```cpp
#include "Tensor.h"
```

### Compile

```bash
g++ main.cpp Tensor.cpp -o app
```

---

## 📌 Core Usage

### Matrix creation

```cpp
matrix2d A = {
    {1, 2},
    {3, 4}
};

matrix2d B = {
    {5, 6},
    {7, 8}
};
```

---

## ➕ Matrix Operations

### Addition

```cpp
auto C = Tensor::addMatrix(A, B);
```

### Subtraction

```cpp
auto C = Tensor::subtractMatrix(A, B);
```

---

### Multiplication

```cpp
auto C = Tensor::multiplyMatrix(A, B);
```

⚠️ Requires: columns(A) == rows(B)

---

### Scalar Product

```cpp
auto C = Tensor::scalarProduct(A, 2.0);
```

---

## 🔁 Transpose

```cpp
auto T = Tensor::transpose(A);
```

---

## 📏 Shape

```cpp
auto [rows, cols] = Tensor::shapeOfMatrix(A);
```

---

## 🎲 Random Matrix

```cpp
auto R = Tensor::randomMatrix(3, 3, -1.0, 1.0);
```

Uses C++ `<random>` (Mersenne Twister engine).

---

## 🔢 Determinant

```cpp
double det = Tensor::determinant(A);
```

⚠️ Only for square matrices.

⚠️ Uses recursive cofactor expansion (slow for large matrices).

---

## 🧮 Minor Matrix

Internal helper:

```cpp
Tensor::getMinor(A, row, col);
```

Used for determinant and adjoint.

---

## 🔄 Adjoint Matrix

```cpp
auto adj = Tensor::adjointMatrix(A);
```

---

## 🔁 Inverse Matrix

```cpp
auto inv = Tensor::inverseMatrix(A);
```

### Important behavior

* Checks matrix validity
* Computes determinant
* If determinant ≈ 0 → returns empty matrix
* Uses adjoint × (1/det)

✔ Fixed bug: scaling now correctly assigned

---

## 🖨️ Print Matrix

```cpp
Tensor::printVector(A);
```

Output:

```
{
    { 1 2 },
    { 3 4 },
}
```

---

## ⚠️ Internal Design Notes

### Validation system

Library includes safety checks:

* `checkMatrixValidity()` → ensures rectangular matrix
* `equivalence()` → same dimensions
* `canMultiply()` → multiplication rule check
* `isSquareMatrix()` → square validation

---

## 💡 Honest Feedback (important)

This version is better structured than before, especially:

✔ fixed inverse bug (scalar product now assigned)
✔ cleaner naming consistency
✔ better separation of checks

But there are still deeper design limits:

### 1. Determinant is expensive

* O(n!) recursion
* Not scalable beyond small matrices

👉 Future upgrade: LU decomposition

---

### 2. Validation printing inside logic

Right now functions print errors directly.

👉 Better design:

* return errors instead of printing
* or use exception system

---

### 3. Copy-heavy operations

Everything passes by value sometimes implicitly.

👉 Future upgrade:

* move semantics
* references where possible

---

## 🧪 Example Program

```cpp
#include "Tensor.h"
#include <iostream>

int main() {
    matrix2d A = {
        {1, 2},
        {3, 4}
    };

    matrix2d B = {
        {5, 6},
        {7, 8}
    };

    auto C = Tensor::inverseMatrix(A);

    Tensor::printVector(C);
}
```

---

## 🚀 Future Ideas (strong recommendation)

If you continue this project, focus on:

### High impact upgrades:

* LU decomposition (replace determinant)
* Caching shapes
* Operator overloading (+, -, *)
* Tensor (3D+) support

### ML direction:

* Activation functions
* Gradient descent
* Backprop engine

---

## 🏁 Final Thought

This is already a solid “mini linear algebra engine”. If you keep improving it, it can evolve into a real lightweight ML backend.
