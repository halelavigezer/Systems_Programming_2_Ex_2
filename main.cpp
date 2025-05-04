#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace my_matrx;

int main() {
    try {
        // יצירת שתי מטריצות 2x2
        SquareMat mat1(2);
        SquareMat mat2(2);

        // אתחול ערכים
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        mat2[0][0] = 5; mat2[0][1] = 6;
        mat2[1][0] = 7; mat2[1][1] = 8;

        // הדפסת מטריצות מקוריות
        cout << "Matrix 1:\n" << mat1;
        cout << "Matrix 2:\n" << mat2;

        // חיבור
        SquareMat sum = mat1 + mat2;
        cout << "Sum:\n" << sum;

        // כפל
        SquareMat product = mat1 * mat2;
        cout << "Product:\n" << product;

        // דטרמיננטה
        cout << "Determinant of Matrix 1: " << !mat1 << endl;

        // טרנספוז (שיקוף)
        cout << "Transpose of Matrix 1:\n" << ~mat1;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
