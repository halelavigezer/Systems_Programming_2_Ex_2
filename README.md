# Square Matrix Project

This project implements a `SquareMat` class in C++ and includes a main program and unit tests.

## Files

- `SquareMat.hpp` – Header file for the SquareMat class.
- `SquareMat.cpp` – Implementation of the SquareMat class.
- `main.cpp` – Demonstration of how to use the class.
- `test.cpp` – Unit tests using Doctest.
- `doctest.h` – Header-only testing framework.
- `Makefile` – Build and test automation.

## Build and Run

### Compile and run the main program:
- make Main

- make test

- make valgrind
 
- make clean


---


## Requirements

- valgrind (optional, for memory checking)
- C++17 compiler


## Explanation of Functions

- **SquareMat(int n)** – Initializes an n x n matrix where all values are set to 0.

- **SquareMat operator+(const SquareMat& other)** – Returns a new matrix where each element is the sum of the matching elements in the two matrices.

- **SquareMat operator-(const SquareMat& other)** – Returns a new matrix where each element is the difference between matching elements.

- **SquareMat operator * (const SquareMat& other)** – Performs standard matrix multiplication and returns the result.

- **SquareMat operator * (int scalar)** – Multiplies every element in the matrix by the given number.

- **SquareMat operator%(int mod)** – Applies the modulo operation (%) to each element in the matrix.

- **SquareMat operator^(int power)** – Raises the matrix to the specified power using repeated multiplication.

- **int determinant()** – Computes the determinant of the matrix recursively (valid only for square matrices).

- **bool operator==(const SquareMat& other)** – Returns true if both matrices are the same size and all elements are equal.

- **bool operator!=(const SquareMat& other)** – Returns true if the matrices are different in size or elements.

- **SquareMat operator-()** – Returns a new matrix where each element is the opposite sign of the original (multiplied by -1).

- **SquareMat& operator++()** – Increases each element in the matrix by 1 (prefix form).

- **SquareMat operator++(int)** – Same as above, but in postfix form.

- **SquareMat& operator--()** – Decreases each element in the matrix by 1 (prefix form).

- **SquareMat operator--(int)** – Same as above, but in postfix form.

- **int operator()(int row, int col)** – Returns the value of the element at the given row and column.

- **void set(int row, int col, int value)** – Sets the element at the specified row and column to the given value.

- **void print()** – Displays the matrix content in a clean, readable format.


---

## Contact
Email: avigezerhalel@gmail.com
