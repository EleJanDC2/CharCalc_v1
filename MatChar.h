#ifndef CHARCALCULATOR_MATCHAR_H
#define CHARCALCULATOR_MATCHAR_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>

namespace mc {

    class MatChar {
    //public:

    private:
        char * mpNumber;
        bool mIsPositive;

    public:
        MatChar();
        MatChar(int _number);
        MatChar(double _number);
        MatChar(char * _mpNumber, bool _mIsPositive);
        MatChar(const MatChar &obj);
        //
        ~MatChar();
        //
        MatChar &operator=(const MatChar &MatChar2);
        //MatChar operator=(const MatChar &MatChar2);
        MatChar operator+(const MatChar &MatChar2);
        MatChar operator-(const MatChar &MatChar2);
        MatChar operator*(const MatChar &MatChar2);
        MatChar operator/(const MatChar &MatChar2);
        MatChar operator!();
        bool operator>(const MatChar &MatChar2);
        bool operator<(const MatChar &MatChar2);
        //
        void print();
        bool test(std::string str, bool _mIsPositive);

        static char * convertToExponentialFigure(const MatChar &MatChar2);

    private:
        // Modyfikacja numeru w char array:
        static void alingTwoChararray(char * &str1, char * &str2); // Dodaje zera na początku i końcu liczb tak by były jednakowej długości i miały znak '.' na tej samej pozycji.
        static void mRemoveZeros(char * &str); // Usuwa niepotrzebne zera z początku i końca liczby.
        //
        static void insertDecimalPoint(char * &str, int index);
        static void removeDecimalPoint(char * &str);
        //
        //static void addMinusSymbol(char * &str);
        //static void removeMinusSymbol(char * &str);
        //
        static void reverseCharArray(char * str);

        //Znajdowanie informacji na temat napisu / liczby / itp:
        static int mDesigneteSizeOfDigits(int _number);
        static int mDesigneteSizeOfDigits(double _number);
        static int findDot(char * str);
        static int compare(char * str1, char * str2);

        //Używane tylko przez inne funkcje
        static char * addZerosLeft(char * str, int numZeros);
        static char * addZerosRight(char * str, int numZeros);

        //Funkcie matematyczne
        static char * add(char * num1, char * num2);
        static char * subtract(char * num1, char * num2);
        static char * multiply(char *num1, char *num2);
        static char * divide(char *num1, char *num2);

        static char * convertToExponentialFigure(const char * str);

        //
        //static bool IsClearNumber(char * str);
    };

} // mc

#endif //CHARCALCULATOR_MATCHAR_H


/*
 * Konwencja nazewnictwa: https://www.geeksforgeeks.org/naming-convention-in-c/
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
