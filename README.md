# TensorLib 🚀

A simple C++ library for performing basic matrix (tensor) operations such as addition, subtraction, multiplication, determinant, inverse, and more.

---

## 📌 Features

* ✅ Matrix addition
* ✅ Matrix subtraction
* ✅ Matrix multiplication
* ✅ Determinant calculation (supports large matrices using Gaussian elimination)
* ✅ Matrix inverse (using adjoint method)
* ✅ Transpose of matrix
* ✅ Scalar multiplication
* ✅ Matrix validation checks
* ✅ Pretty printing of matrices

---

## 🧠 Concepts Used

* Vectors (`std::vector`)
* Object-Oriented Programming (OOP)
* Matrix algebra
* Recursion (for determinant via minors)
* Gaussian elimination

---

## 📂 Project Structure

```
TensorLib/
│── main.cpp   # Contains implementation and usage
```

---

## ⚙️ How to Compile & Run

### 🛠 Compile

```bash
g++ main.cpp -o tensor
```

### ▶️ Run

```bash
./tensor
```

---

## 📊 Example Usage

```cpp
Tensor t;

matrix2d v = {
    {1, 2, 1, 2},
    {3, 1, 1, 4},
    {1, 3, 1, 1},
    {4, 1, 1, 2}
};

t.printVector(v);

matrix2d inverse = t.inverseMatrix(v);
t.printVector(inverse);
```

---

## ⚠️ Limitations

* ❌ No exception handling (uses `cerr` for errors)
* ❌ Assumes valid input in some functions
* ❌ Inverse does not check for determinant = 0 (can cause issues)
* ❌ Not optimized for very large matrices

---

## 🛠 Possible Improvements

* Add exception handling
* Improve performance (use better algorithms like LU decomposition)
* Add support for templates (generic data types)
* Separate header (`.h`) and implementation (`.cpp`)
* Add unit tests

---

## 💡 Future Scope

This project can evolve into:

* A mini linear algebra library
* A base for machine learning implementations
* GPU-accelerated tensor library (advanced)

---

## 👨‍💻 Author

Developed as a learning project to understand matrix operations and C++ OOP concepts.

---

## 📜 License

This project is open-source and free to use.
