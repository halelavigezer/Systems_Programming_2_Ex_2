
// Created by halel on 5/4/25.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "SquareMat.hpp"

using namespace my_matrx ;
// בדיקה עבור בנאי ומחיקת זיכרון
TEST_CASE("Constructor and Destructor") {
    // בודקים בנאי עם גודל תקין
    SquareMat mat(3);
    CHECK(mat.size == 3);

    // / ומוציאים חריגע אם הוא שלילי או אפס הגודל/בודקים בנאי עם גודל לא תקין
    CHECK_THROWS(SquareMat(0));
    CHECK_THROWS(SquareMat(-1));
}
// בדיקה עבור בנאי העתקה
TEST_CASE("Copy Constructor") {
    // יוצרים אובייקט מהבנאי
    SquareMat mat1(3);  // יוצרים מטריצה בגודל 3
    SquareMat mat2 = mat1;  // יוצרים עותק באמצעות בנאי ההעתקה
    CHECK(mat1.size == mat2.size);  // בודקים שהגודל זהה
    for (int i = 0; i < mat1.size; ++i) {
        for (int j = 0; j < mat1.size; ++j) {
            CHECK(mat1[i][j] == mat2[i][j]);  // בודקים שהערכים במטריצות זהים
        }
    }
}

TEST_CASE("Copy constructor copies correctly") {
    SquareMat original(2);
    original[0][0] = 1.5;
    original[1][1] = 2.5;

    SquareMat copy(original);

    // בדיקה שהערכים זהים
    CHECK(copy.size == 2);
    CHECK(copy[0][0] == doctest::Approx(1.5));
    CHECK(copy[1][1] == doctest::Approx(2.5));

    // שינוי ההעתק לא משפיע על המקור
    copy[0][0] = 9.9;
    CHECK(original[0][0] == doctest::Approx(1.5));
}
// בדיקה עבור אופרטור השיבוץ (=)
TEST_CASE("Assignment Operator") {
    SquareMat mat1(3);
    mat1[0][0] = 1;  // שינוי ערך במטריצה
    mat1[1][1] = 2;  // שינוי ערך נוסף
    mat1[2][2] = 3;  // שינוי ערך נוסף
    SquareMat mat2(3);

    // מבצעים את השיבוץ (הקצאת ערכים ממטריצה אחת לשנייה)
    mat2 = mat1;

    // בודקים שהגודל של המטריצות זהה
    CHECK(mat1.size == mat2.size);

    // בודקים שכל ערך במטריצה המקורית עבר בהצלחה למטריצה החדשה
    CHECK(mat1[0][0] == mat2[0][0]);
    CHECK(mat1[1][1] == mat2[1][1]);
    CHECK(mat1[2][2] == mat2[2][2]);

    // בודקים ששיבוץ של מטריצה לא ישפיע על המטריצה המקורית
    mat2[0][0] = 10;
    CHECK(mat1[0][0] != mat2[0][0]);  // המטריצות לא צריכות להיות שוות אחרי שינוי במטריצה השנייה
}
// בדיקה עבור אופרטור החיבור (+)
TEST_CASE("Addition Operator") {
    SquareMat mat1(3);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[0][2] = 3;
    mat1[1][0] = 4;
    mat1[1][1] = 5;
    mat1[1][2] = 6;
    mat1[2][0] = 7;
    mat1[2][1] = 8;
    mat1[2][2] = 9;

    SquareMat mat2(3);
    mat2[0][0] = 9;
    mat2[0][1] = 8;
    mat2[0][2] = 7;
    mat2[1][0] = 6;
    mat2[1][1] = 5;
    mat2[1][2] = 4;
    mat2[2][0] = 3;
    mat2[2][1] = 2;
    mat2[2][2] = 1;

    // חיבור של המטריצות mat1 ו-mat2
    SquareMat result = mat1 + mat2;
    // בודקים שהגודל של המטריצה התוצאה הוא 3
    CHECK(result.size == 3);
    // בודקים שכל הערכים במטריצה התוצאה הם החיבור של הערכים המקוריים
    CHECK(result[0][0] == 10);  // 1 + 9
    CHECK(result[0][1] == 10);  // 2 + 8
    CHECK(result[0][2] == 10);  // 3 + 7
    CHECK(result[1][0] == 10);  // 4 + 6
    CHECK(result[1][1] == 10);  // 5 + 5
    CHECK(result[1][2] == 10);  // 6 + 4
    CHECK(result[2][0] == 10);  // 7 + 3
    CHECK(result[2][1] == 10);  // 8 + 2
    CHECK(result[2][2] == 10);  // 9 + 1
}
// בדיקה עבור חיבור של מטריצה עם מטריצה ריקה
TEST_CASE("Addition with Empty Matrix") {
    SquareMat mat1(3);
    mat1[0][0] = 1;
    mat1[1][1] = 2;
    mat1[2][2] = 3;

    SquareMat mat2(3);
    SquareMat result = mat1 + mat2;
    CHECK(result.size == 3);
    // בודקים שהערכים במטריצה התוצאה הם בדיוק כמו במטריצה הראשונה
    CHECK(result[0][0] == 1);
    CHECK(result[1][1] == 2);
    CHECK(result[2][2] == 3);
}
// בדיקה של פעולה חיסור בין שתי מטריצות
// יוצרים מטריצה ראשונה בגודל 3x3 וממלאים ערכים
// יוצרים מטריצה שנייה בגודל 3x3 וממלאים ערכים
// מבצעים חיסור: mat1 - mat2
//בודקים שהתוצאה יצאה נכונה בכל איברים

TEST_CASE("Subtraction Operator") {
    SquareMat mat1(3);
    mat1[0][0] = 10; mat1[0][1] = 9; mat1[0][2] = 8;
    mat1[1][0] = 7;  mat1[1][1] = 6; mat1[1][2] = 5;
    mat1[2][0] = 4;  mat1[2][1] = 3; mat1[2][2] = 2;
    SquareMat mat2(3);
    mat2[0][0] = 1;  mat2[0][1] = 2; mat2[0][2] = 3;
    mat2[1][0] = 4;  mat2[1][1] = 5; mat2[1][2] = 6;
    mat2[2][0] = 7;  mat2[2][1] = 8; mat2[2][2] = 9;

    SquareMat result = mat1 - mat2;

    CHECK(result.size == 3);
    CHECK(result[0][0] == 9);   // 10 - 1
    CHECK(result[0][1] == 7);   // 9 - 2
    CHECK(result[0][2] == 5);   // 8 - 3
    CHECK(result[1][0] == 3);   // 7 - 4
    CHECK(result[1][1] == 1);   // 6 - 5
    CHECK(result[1][2] == -1);  // 5 - 6
    CHECK(result[2][0] == -3);  // 4 - 7
    CHECK(result[2][1] == -5);  // 3 - 8
    CHECK(result[2][2] == -7);  // 2 - 9
}
// בדיקה לפעולה יונארית שלילית (כל איבר במטריצה משתנה לסימן ההפוך שלו)
TEST_CASE("Unary minus operator - returns a matrix with all elements negated") {
    // יוצרים מטריצה בגודל 2x2 וממלאים ערכים חיוביים ושליליים
    SquareMat mat(2);
    mat[0][0] = 1;  mat[0][1] = -2;
    mat[1][0] = 3;  mat[1][1] = -4;
    // מפעילים את הפעולה היונארית מינוס
    SquareMat neg = -mat;
    // בודקים שהתוצאה היא כל איבר במטריצה המקורית כפול -1
    CHECK(neg[0][0] == -1);
    CHECK(neg[0][1] == 2);
    CHECK(neg[1][0] == -3);
    CHECK(neg[1][1] == 4);
}
// בודקים כפל מטריצות
TEST_CASE("Matrix multiplication returns correct result") {
    // יוצרים שתי מטריצות בגודל 2x2 עם ערכים פשוטים
    SquareMat A(2);
    SquareMat B(2);

    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    SquareMat C = A * B;
    // בודקים שהתוצאה נכונה כמו שציפיתי
    CHECK(C[0][0] == 19); // C[0][0] = 1*5 + 2*7 = 19
    CHECK(C[0][1] == 22);  // C[0][1] = 1*6 + 2*8 = 22
    CHECK(C[1][0] == 43); // C[1][0] = 3*5 + 4*7 = 43
    CHECK(C[1][1] == 50); // C[1][1] = 3*6 + 4*8 = 50
}
//כפל מטריצה בסקלר
TEST_CASE("Matrix scalar multiplication works correctly") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    double scalar = 3.0;
    // מכפילים את כל הערכים במטריצה בסקלר 3.0
    SquareMat B = A * scalar;
    // בודקים שכל ערך הוכפל כמו שציפיתי
    CHECK(B[0][0] == doctest::Approx(3.0));
    CHECK(B[0][1] == doctest::Approx(6.0));
    CHECK(B[1][0] == doctest::Approx(9.0));
    CHECK(B[1][1] == doctest::Approx(12.0));
}
//בודקים את האופרטור החברתי שמבצע כפל של מטריצה בסקלר
TEST_CASE("Testing friend operator* (matrix * scalar)") {
    SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    SquareMat result = mat * 2.0;  // כפל המטריצה ב-2.0

    CHECK(result[0][0] == doctest::Approx(2.0));
    CHECK(result[0][1] == doctest::Approx(4.0));
    CHECK(result[1][0] == doctest::Approx(6.0));
    CHECK(result[1][1] == doctest::Approx(8.0));
}
//הכפלה של שתי מטריצות בצורה שכל איבר מוכפל באיבר שמתאים לו
TEST_CASE("Testing operator % (matrix % matrix)") {
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    SquareMat mat2(2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    SquareMat result = mat1 % mat2;  // מבצעים את פעולת % בין שתי המטריצות

    CHECK(result[0][0] == doctest::Approx(5));  // תא (0,0) מצפה 5
    CHECK(result[0][1] == doctest::Approx(12));  // תא (0,1)מצפה 12
    CHECK(result[1][0] == doctest::Approx(21));  // תא (1,0) מצפה 21
    CHECK(result[1][1] == doctest::Approx(32));  // תא (1,1) מצפה 32
}
//מודולו על אברי המטריצה אם סקלר שנכנס כקלט
TEST_CASE("Testing operator % (matrix % scalar)") {
    SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    double scalar = 2.0;
    SquareMat result = mat % scalar;  // פעולת % על המטריצה עם מספר

    CHECK(result[0][0] == doctest::Approx(1.0));  // תא (0,0)מצפה ל 1 % 2 = 1
    CHECK(result[0][1] == doctest::Approx(0.0));  // תא (0,1) מצפה ל 2 % 2 = 0
    CHECK(result[1][0] == doctest::Approx(1.0));  // תא (1,0) מצפה ל 3 % 2 = 1
    CHECK(result[1][1] == doctest::Approx(0.0));  // תא (1,1)מצפה ל 4 % 2 = 0
}
//ביצוע חילו של כל אברי המטריצה אם סקלר שניכנס כקלט
TEST_CASE("Testing operator / (matrix / scalar)") {
    SquareMat mat(2);
    mat[0][0] = 2;
    mat[0][1] = 4;
    mat[1][0] = 6;
    mat[1][1] = 8;

    double scalar = 2.0;
    SquareMat result = mat / scalar;  // פעולת / על המטריצה עם מספר
    CHECK(result[0][0] == doctest::Approx(1.0));  // תא (0,0)מצפה 2 / 2 = 1
    CHECK(result[0][1] == doctest::Approx(2.0));  // תא (0,1) מצפה 4 / 2 = 2
    CHECK(result[1][0] == doctest::Approx(3.0));  // תא (1,0) מצה 6 / 2 = 3
    CHECK(result[1][1] == doctest::Approx(4.0));  // תא (1,1) מצפה 8 / 2 = 4
}
//מטריצה בחזקת הסקלר שניכנס כקלט
TEST_CASE("Testing operator ^ (matrix ^ exponent)") {
    SquareMat mat(2);
    mat[0][0] = 2;
    mat[0][1] = 0;
    mat[1][0] = 0;
    mat[1][1] = 3;

    int exponent = 2;  // מעריך החזקה
    SquareMat result = mat ^ exponent;  // פעולת ^ על המטריצה עם מעריך החזקה

    CHECK(result[0][0] == doctest::Approx(4.0));  // תא (0,0) אמור להיות 2^2 = 4
    CHECK(result[0][1] == doctest::Approx(0.0));  // תא (0,1) אמור להישאר 0
    CHECK(result[1][0] == doctest::Approx(0.0));  // תא (1,0) אמור להישאר 0
    CHECK(result[1][1] == doctest::Approx(9.0));  // תא (1,1) אמור להיות 3^2 = 9
}
//מוסיפים 1 לכל איבר במטריצה
TEST_CASE("Testing operator ++ (prefix increment)") {
    SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    SquareMat& result = ++mat;  // האופרטור ++ משנה את המטריצה עצמה

    CHECK(result[0][0] == doctest::Approx(2.0));  // תא (0,0) מצפה 2
    CHECK(result[0][1] == doctest::Approx(3.0));  // תא (0,1) מצפה 3
    CHECK(result[1][0] == doctest::Approx(4.0));  // תא (1,0)מצפה 4
    CHECK(result[1][1] == doctest::Approx(5.0));  // תא (1,1) מצפה 5
}
//עוש הורדת 1 מכל איבר במטריצה
TEST_CASE("Testing operator -- (prefix decrement)") {
    SquareMat mat(2);
    mat[0][0] = 2;
    mat[0][1] = 3;
    mat[1][0] = 4;
    mat[1][1] = 5;
    SquareMat& result = --mat;

    CHECK(result[0][0] == doctest::Approx(1.0));  // תא (0,0)מצפה 1
    CHECK(result[0][1] == doctest::Approx(2.0));  // תא (0,1)מצפה 2
    CHECK(result[1][0] == doctest::Approx(3.0));  // תא (1,0) מצפה 3
    CHECK(result[1][1] == doctest::Approx(4.0));  // תא (1,1) מצפה 4
}
//מחליף שורה לעמודה(משחלף)
TEST_CASE("Testing operator ~ (transpose)") {
    SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;
    SquareMat result = ~mat;

    CHECK(result[0][0] == doctest::Approx(1.0));  // תא (0,0) נשאר 1
    CHECK(result[0][1] == doctest::Approx(3.0));  // תא (0,1) עבר מ (1,0)
    CHECK(result[1][0] == doctest::Approx(2.0));  // תא (1,0) עבר מ (0,1)
    CHECK(result[1][1] == doctest::Approx(4.0));  // תא (1,1) נשאר 4
}
//שליפת איפבר ל]י אינדקס מסויים
TEST_CASE("Testing operator[]") {
    SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;
    CHECK(mat[0][0] == doctest::Approx(1.0));  // תא (0,0)
    CHECK(mat[0][1] == doctest::Approx(2.0));  // תא (0,1)
    CHECK(mat[1][0] == doctest::Approx(3.0));  // תא (1,0)
    CHECK(mat[1][1] == doctest::Approx(4.0));  // תא (1,1)

    // בדיקה אם האופרטור [] עובד נכון גם כשהוא מחזיר את השורה כמצביע
    double* row = mat[0];
    CHECK(row[0] == doctest::Approx(1.0));  //  1
    CHECK(row[1] == doctest::Approx(2.0));  //  2
}
//שוךף את המידע מאינדקס מסויים
TEST_CASE("Testing const operator[]") {
    SquareMat mat(2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;
    CHECK(mat[0][0] == doctest::Approx(1.0));  // תא (0,0)
    CHECK(mat[0][1] == doctest::Approx(2.0));  // תא (0,1)
    CHECK(mat[1][0] == doctest::Approx(3.0));  // תא (1,0)
    CHECK(mat[1][1] == doctest::Approx(4.0));  // תא (1,1)

    // בדיקה אם האופרטור [] מחזיר מצביע לקריאה בלבד עבור מטריצה const
    const SquareMat constMat = mat;  // יצירת אובייקט מטריצה const
    const double* row = constMat[0];  // משתמשים באופרטור [] כדי לקבל את השורה הראשונה, כאובייקט const
    CHECK(row[0] == doctest::Approx(1.0));  //  1
    CHECK(row[1] == doctest::Approx(2.0));  //  2
}
//השוואה (==)
TEST_CASE("Testing operator== for SquareMat") {
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    SquareMat mat2(2);
    mat2[0][0] = 1;
    mat2[0][1] = 2;
    mat2[1][0] = 3;
    mat2[1][1] = 4;
    SquareMat mat3(2);
    mat3[0][0] = 5;
    mat3[0][1] = 6;
    mat3[1][0] = 7;
    mat3[1][1] = 8;
    CHECK(mat1 == mat2);  // הציפייה היא ש- mat1 שווה ל-mat2
    CHECK_FALSE(mat1 == mat3);  // הציפייה היא ש- mat1 לא שווה ל-mat3
}
//השוואה(!=)
TEST_CASE("Testing operator!= for SquareMat") {
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    SquareMat mat2(2);
    mat2[0][0] = 1;
    mat2[0][1] = 2;
    mat2[1][0] = 3;
    mat2[1][1] = 4;
    SquareMat mat3(2);
    mat3[0][0] = 9;
    mat3[0][1] = 8;
    mat3[1][0] = 7;
    mat3[1][1] = 6;
    // בודק שהמטריצות mat1 ו־mat2 זהות – אז הן לא צריכות להיות שונות
    CHECK_FALSE(mat1 != mat2);
    // בודק שהמטריצות mat1 ו־mat3 שונות – אז הן אמורות להיות שונות
    CHECK(mat1 != mat3);
}
TEST_CASE("Testing comparison operators: <, >, <=, >=") {
    SquareMat matA(2);
    matA[0][0] = 1;
    matA[0][1] = 2;
    matA[1][0] = 3;
    matA[1][1] = 4;
    SquareMat matB(2);
    matB[0][0] = 5;
    matB[0][1] = 6;
    matB[1][0] = 7;
    matB[1][1] = 8;
    SquareMat matC(2);
    matC[0][0] = 1;
    matC[0][1] = 2;
    matC[1][0] = 3;
    matC[1][1] = 4;
    // matA קטנה מ־matB, אז נצפה שהתוצאה תהיה true
    CHECK(matA < matB);
    CHECK_FALSE(matB < matA);
    // matB גדולה מ־matA, אז נצפה שהתוצאה תהיה true
    CHECK(matB > matA);
    CHECK_FALSE(matA > matB);
    // matA שווה ל־matC ולכן לא אמורה להיות קטנה או גדולה ממנה, אבל כן קטנה או שווה וגדולה או שווה
    CHECK(matA <= matC);
    CHECK(matA >= matC);
    // matA גם קטנה או שווה ל־matB, אבל לא גדולה או שווה לו
    CHECK(matA <= matB);
    CHECK_FALSE(matA >= matB);
    // matB גם גדולה או שווה ל־matA
    CHECK(matB >= matA);
    CHECK_FALSE(matB <= matA);
}
TEST_CASE("Testing operator! - determinant") {
    SquareMat mat(2);
    mat[0][0] = 4;
    mat[0][1] = 6;
    mat[1][0] = 3;
    mat[1][1] = 8;
    // כאן נחשב את הדטרמיננטה בצורה ידנית:
    // 4*8 - 6*3 = 32 - 18 = 14
    double expected_determinant = 14.0;
    CHECK(!mat == doctest::Approx(expected_determinant)); // operator! should return the determinant
}
//בדיקה של += \-= \*= \/= \%=
TEST_CASE("Testing compound assignment operators") {
    SquareMat mat1(2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;
    SquareMat mat2(2);
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;
    SUBCASE("operator +=") {
        mat1 += mat2; // mat1 becomes mat1 + mat2
        // mat1 צריכה להיות [6 8; 10 12]
        CHECK(mat1[0][0] == 6);
        CHECK(mat1[0][1] == 8);
        CHECK(mat1[1][0] == 10);
        CHECK(mat1[1][1] == 12);
    }
    SUBCASE("operator -=") {
        mat1 -= mat2; // mat1 becomes mat1 - mat2
        // mat1 צריכה להיות [-4 -4; -4 -4]
        CHECK(mat1[0][0] == -4);
        CHECK(mat1[0][1] == -4);
        CHECK(mat1[1][0] == -4);
        CHECK(mat1[1][1] == -4);
    }
    SUBCASE("operator *=(mat)") {
        mat1 *= mat2; // מטריצה כפול מטריצה
        // תוצאה ידנית:
        // [1*5+2*7, 1*6+2*8] = [19, 22]
        // [3*5+4*7, 3*6+4*8] = [43, 50]
        CHECK(mat1[0][0] == 19);
        CHECK(mat1[0][1] == 22);
        CHECK(mat1[1][0] == 43);
        CHECK(mat1[1][1] == 50);
    }
    SUBCASE("operator *= (scalar)") {
        mat1 *= 2.0; // כל איבר מוכפל פי 2
        // mat1 צריכה להיות [2 4; 6 8]
        CHECK(mat1[0][0] == 2);
        CHECK(mat1[0][1] == 4);
        CHECK(mat1[1][0] == 6);
        CHECK(mat1[1][1] == 8);
    }
    SUBCASE("operator /= (scalar)") {
        mat1 /= 2.0; // כל איבר מחולק ב-2
        // mat1 צריכה להיות [0.5 1; 1.5 2]
        CHECK(mat1[0][0] == doctest::Approx(0.5));
        CHECK(mat1[0][1] == doctest::Approx(1.0));
        CHECK(mat1[1][0] == doctest::Approx(1.5));
        CHECK(mat1[1][1] == doctest::Approx(2.0));
    }
    SUBCASE("operator %= (scalar)") {
        mat1 %= 2; // כל איבר עובר מודולו 2
        // mat1 צריכה להיות [1 0; 1 0]
        CHECK(mat1[0][0] == 1);
        CHECK(mat1[0][1] == 0);
        CHECK(mat1[1][0] == 1);
        CHECK(mat1[1][1] == 0);
    }
}