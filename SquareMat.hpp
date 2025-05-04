//avigezerhalel@gmail.com
//my_matrx
// Created by halel on 4/27/25.
//

#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include <iostream>



namespace my_matrx {

class SquareMat {
    public:
    int size;
    double** matrx;

    SquareMat(int size);
    ~SquareMat();
    SquareMat(const SquareMat& mat);
    SquareMat& operator=(const SquareMat& mat);
    SquareMat operator+(const SquareMat& other);
    SquareMat operator-(const SquareMat& other);
    SquareMat operator-();
    SquareMat operator*(const SquareMat& other);
    SquareMat operator*(double scalar);
    friend SquareMat operator*(const SquareMat& mat, double scalar);
    SquareMat operator %(const SquareMat &mat);
    SquareMat operator %(double scalar);
    SquareMat operator/(double scalar);
    SquareMat operator^(int exponent);
    SquareMat& operator++();
    SquareMat& operator--();
    SquareMat operator~() const;
    double* operator[](int index);             // גישה רגילה – אפשר לעדכן
    const double* operator[](int index) const; // גישה לקריאה בלבד
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    double operator!() const;
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(int scalar);
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

};

} // my_matrx

#endif //SQUAREMAT_H