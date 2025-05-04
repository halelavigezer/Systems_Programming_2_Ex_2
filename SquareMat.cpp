//
// Created by halel on 4/27/25.
//avigezerhalel@gmail.com
//

#include "SquareMat.hpp"
#include <cmath>
#include <stdexcept>

namespace my_matrx {
    SquareMat::SquareMat(int size):size(size) {
        if (size<=0) {
            throw std::invalid_argument("size must be greater than 0");
        }
        matrx = new double*[size];
        for (int i=0; i<size; i++) {
            matrx[i] = new double[size];

        }
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                matrx[i][j] = 0;
            }
        }
    }
    SquareMat::~SquareMat() {
        for (int i=0; i<size; i++) {
            delete[] matrx[i];
        }
        delete[] matrx;
    }
    SquareMat::SquareMat(const SquareMat &mat) :size(mat.size){
        matrx = new double*[size];
        for (int i=0; i<size; i++) {
            matrx[i] = new double[size];
        }
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                matrx[i][j] = mat.matrx[i][j];
            }
        }

    }
    SquareMat &SquareMat::operator=(const SquareMat &mat) {
        if (this != &mat) {
            if (this->size != mat.size) {
                for (int i=0; i<size; i++) {
                    delete[] matrx[i];
                }
                delete[] matrx;
                size = mat.size;
                matrx = new double*[size];
                for (int i=0; i<size; i++) {
                    matrx[i] = new double[size];
                }
            }
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    matrx[i][j] = mat.matrx[i][j];
                }
            }
        }
        return *this;
    }
    SquareMat SquareMat::operator+(const SquareMat &mat) {
        SquareMat m = SquareMat(size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                m.matrx[i][j] = this->matrx[i][j] + mat.matrx[i][j];
            }
        }
        return m;
    }
    SquareMat SquareMat::operator-(const SquareMat &mat) {
        SquareMat m = SquareMat(size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                m.matrx[i][j] = this->matrx[i][j] - mat.matrx[i][j];
            }
        }
        return m;
    }
    SquareMat SquareMat::operator-() {
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                matrx[i][j] = -matrx[i][j];
            }
        }
        return *this;
    }
    SquareMat SquareMat::operator*(const SquareMat &mat) {
        SquareMat m = SquareMat(size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                for (int k=0; k<size; k++) {
                    m.matrx[i][j] +=this->matrx[i][k] * mat.matrx[k][j];
                }
            }
        }
        return m;
    }
    SquareMat SquareMat::operator*(double scalar) {
        SquareMat m = SquareMat(size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                m.matrx[i][j] =this->matrx[i][j] * scalar;
            }
        }
        return m;
    }
    SquareMat operator*(const SquareMat &mat,double scalar) {///??
        SquareMat m = SquareMat(mat.size);
        for (int i=0; i<mat.size; i++) {
            for (int j=0; j<mat.size; j++) {
                m.matrx[i][j] = mat.matrx[i][j] * scalar;
            }
        }
        return m;
    }
    SquareMat SquareMat::operator%(const SquareMat &mat) {
        if (size!=mat.size) {
            throw std::invalid_argument("SquareMat::operator%: matrix size not equal");
        }
        SquareMat m = SquareMat(size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                m.matrx[i][j]=matrx[i][j] * mat.matrx[i][j];
            }
        }
        return m;
    }
    SquareMat SquareMat::operator%(double scalar) {
        SquareMat m = SquareMat(size);
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                m.matrx[i][j] = std::fmod((matrx[i][j] ), scalar);
            }
        }
        return m;
    }
    SquareMat SquareMat::operator/(double scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }

        SquareMat m=SquareMat(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                m.matrx[i][j] = this->matrx[i][j] / scalar;
            }
        }
        return m;
    }
    SquareMat SquareMat::operator^(int exponent) {
        if (exponent < 0) {
            throw std::invalid_argument("Exponent must be non-negative");
        }
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            result.matrx[i][i] = 1;
        }

        SquareMat base(*this);  // עותק של המטריצה המקורית

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            exponent /= 2;
        }

        return result;
    }
    SquareMat& SquareMat::operator++() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrx[i][j] += 1;
            }
        }
        return *this;
    }
    SquareMat& SquareMat::operator--() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrx[i][j] -= 1;
            }
        }
        return *this;
    }
    SquareMat SquareMat::operator~() const {
        SquareMat transposed = SquareMat(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                transposed.matrx[j][i] = matrx[i][j];
            }
        }

        return transposed;
    }
    double* SquareMat::operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return matrx[index];
    }

    const double* SquareMat::operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return matrx[index];
    }
    bool SquareMat::operator==(const SquareMat& other) const {
        double sum1 = 0;
        double sum2 = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sum1 += matrx[i][j];
                sum2 += other.matrx[i][j];
            }
        }

        return sum1 == sum2;
    }

    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }
    bool SquareMat::operator<(const SquareMat& other) const {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sum1 += matrx[i][j];
                sum2 += other.matrx[i][j];
            }
        }
        return sum1 < sum2;
    }
    // הפוך מהקטן
    bool SquareMat::operator>(const SquareMat& other) const {
        return other < *this;
    }
    // לא גדול ממנו
    bool SquareMat::operator<=(const SquareMat& other) const {
        return !(other < *this);
    }
    // לא קטן ממנו
    bool SquareMat::operator>=(const SquareMat& other) const {
        return !(*this < other);
    }
    SquareMat getMinor(const SquareMat& mat, int row, int col) {
        SquareMat minor(mat.size - 1);
        int mi = 0, mj = 0;

        for (int i = 0; i < mat.size; ++i) {
            if (i == row) continue;
            mj = 0;
            for (int j = 0; j < mat.size; ++j) {
                if (j == col) continue;
                minor.matrx[mi][mj] = mat.matrx[i][j];
                ++mj;
            }
            ++mi;
        }

        return minor;
    }
    double SquareMat::operator!() const {
        if (size == 1) {
            return matrx[0][0];
        }
        if (size == 2) {
            return matrx[0][0] * matrx[1][1] - matrx[0][1] * matrx[1][0];
        }

        double det = 0;
        for (int j = 0; j < size; ++j) {
            SquareMat minor = getMinor(*this, 0, j);
            det += (j % 2 == 0 ? 1 : -1) * matrx[0][j] * !minor;
        }
        return det;
    }
    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for +=");
        }
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                matrx[i][j] += other.matrx[i][j];
        return *this;
    }
    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for -=");
        }
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                matrx[i][j] -= other.matrx[i][j];
        return *this;
    }
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for *=");
        }
        SquareMat result = (*this) * other;
        *this = result;
        return *this;
    }
    SquareMat& SquareMat::operator*=(double scalar) {
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                matrx[i][j] *= scalar;
        return *this;
    }
    SquareMat& SquareMat::operator/=(double scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                matrx[i][j] /= scalar;
        return *this;
    }
    SquareMat& SquareMat::operator%=(int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Modulo by zero");
        }
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                matrx[i][j] = static_cast<int>(matrx[i][j]) % scalar;
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                os << mat.matrx[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }



} // my_matrx