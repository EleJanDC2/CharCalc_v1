#include <iostream>
#include <vector>

#include "MatChar.h"

void test1() {
    try {
        { // Dodawanie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.0", true)) std::cout << "TEST 1.01 - OK" << std::endl;
            else std::cout << "TEST 1.01 - EROOR" << std::endl;
        }
        { // Dodawanie | + + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(98.300);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.5", true)) std::cout << "TEST 1.02 - OK" << std::endl;
            else std::cout << "TEST 1.02 - EROOR" << std::endl;
        }
        { // Dodawanie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.0", true)) std::cout << "TEST 1.03 - OK" << std::endl;
            else std::cout << "TEST 1.03 - EROOR" << std::endl;
        }
        { // Dodawanie | + + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.5", true)) std::cout << "TEST 1.04 - OK" << std::endl;
            else std::cout << "TEST 1.04 - EROOR" << std::endl;
        }
        //
        { // Dodawanie | - - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.0", false)) std::cout << "TEST 1.05 - OK" << std::endl;
            else std::cout << "TEST 1.05 - EROOR" << std::endl;
        }
        { // Dodawanie | - - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(-98.3);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.5", false)) std::cout << "TEST 1.06 - OK" << std::endl;
            else std::cout << "TEST 1.06 - EROOR" << std::endl;
        }
        { // Dodawanie | - - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.0", false)) std::cout << "TEST 1.07 - OK" << std::endl;
            else std::cout << "TEST 1.07 - EROOR" << std::endl;
        }
        { // Dodawanie | - - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("221.5", false)) std::cout << "TEST 1.08 - OK" << std::endl;
            else std::cout << "TEST 1.08 - EROOR" << std::endl;
        }
        //
        { // Dodawanie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("25.0", true)) std::cout << "TEST 1.09 - OK" << std::endl;
            else std::cout << "TEST 1.09 - EROOR" << std::endl;
        }
        { // Dodawanie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(-98.300);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("24.9", true)) std::cout << "TEST 1.10 - OK" << std::endl;
            else std::cout << "TEST 1.10 - EROOR" << std::endl;
        }
        { // Dodawanie | + - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("25.0", false)) std::cout << "TEST 1.11 - OK" << std::endl;
            else std::cout << "TEST 1.11 - EROOR" << std::endl;
        }
        { // Dodawanie | + - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("25.1", false)) std::cout << "TEST 1.12 - OK" << std::endl;
            else std::cout << "TEST 1.12 - EROOR" << std::endl;
        }
        //
        { // Dodawanie | - + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("25.0", false)) std::cout << "TEST 1.13 - OK" << std::endl;
            else std::cout << "TEST 1.13 - EROOR" << std::endl;
        }
        { // Dodawanie | - + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(98.3);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("24.9", false)) std::cout << "TEST 1.14 - OK" << std::endl;
            else std::cout << "TEST 1.14 - EROOR" << std::endl;
        }
        { // Dodawanie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("25.0", true)) std::cout << "TEST 1.15 - OK" << std::endl;
            else std::cout << "TEST 1.15 - EROOR" << std::endl;
        }
        { // Dodawanie | - + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("25.1", true)) std::cout << "TEST 1.16 - OK" << std::endl;
            else std::cout << "TEST 1.16 - EROOR" << std::endl;
        }
        //
        { // Dodawanie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("102.0", true)) std::cout << "TEST 1.17 - OK" << std::endl;
            else std::cout << "TEST 1.17 - EROOR" << std::endl;
        }
        { // Dodawanie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(2);
            mc::MatChar num2(100);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("102.0", true)) std::cout << "TEST 1.18 - OK" << std::endl;
            else std::cout << "TEST 1.18 - EROOR" << std::endl;
        }
        { // Dodawanie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("98.0", false)) std::cout << "TEST 1.19 - OK" << std::endl;
            else std::cout << "TEST 1.19 - EROOR" << std::endl;
        }
        { // Dodawanie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(-2);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("98.0", true)) std::cout << "TEST 1.20 - OK" << std::endl;
            else std::cout << "TEST 1.20 - EROOR" << std::endl;
        }
        //
        { // Dodawanie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(5);
            mc::MatChar num2(-5);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("0.0", true)) std::cout << "TEST 1.21 - OK" << std::endl;
            else std::cout << "TEST 1.21 - EROOR" << std::endl;
        }
        { // Dodawanie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-5);
            mc::MatChar num2(5);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("0.0", true)) std::cout << "TEST 1.22 - OK" << std::endl;
            else std::cout << "TEST 1.22 - EROOR" << std::endl;
        }
        { // Dodawanie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(5.2);
            mc::MatChar num2(-5.2);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("0.0", true)) std::cout << "TEST 1.23 - OK" << std::endl;
            else std::cout << "TEST 1.23 - EROOR" << std::endl;
        }
        { // Dodawanie | - + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-5.2);
            mc::MatChar num2(5.2);
            mc::MatChar num3 = num1 + num2;
            num3.print();
            if (num3.test("0.0", true)) std::cout << "TEST 1.24 - OK" << std::endl;
            else std::cout << "TEST 1.24 - EROOR" << std::endl;
        }
        //
        //
        //
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(9);
            mc::MatChar num2 = num1 + 1;
            num2.print();
            if (num2.test("10.0", true)) std::cout << "TEST 1.25 - OK" << std::endl;
            else std::cout << "TEST 1.25 - EROOR" << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(1);
            mc::MatChar num2 = num1 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2 = num2 + 1;
            num2.print();
            if (num2.test("13.0", true)) std::cout << "TEST 1.26 - OK" << std::endl;
            else std::cout << "TEST 1.26 - EROOR" << std::endl;
        }
    } catch (const char * txtException){
        std::cout << "EXEPTION: " << txtException << std::endl;
    }
}

void test2() {
    try {
        { // Odejmowanie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("25.0", true)) std::cout << "TEST 2.01 - OK" << std::endl;
            else std::cout << "TEST 2.01 - EROOR" << std::endl;
        }
        { // Odejmowanie | + + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(98.300);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("24.9", true)) std::cout << "TEST 2.02 - OK" << std::endl;
            else std::cout << "TEST 2.02 - EROOR" << std::endl;
        }
        { // Odejmowanie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("25.0", false)) std::cout << "TEST 2.03 - OK" << std::endl;
            else std::cout << "TEST 2.03 - EROOR" << std::endl;
        }
        { // Odejmowanie | + + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("25.1", false)) std::cout << "TEST 2.04 - OK" << std::endl;
            else std::cout << "TEST 2.04 - EROOR" << std::endl;
        }
        //
        { // Odejmowanie | - - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("25.0", false)) std::cout << "TEST 2.05 - OK" << std::endl;
            else std::cout << "TEST 2.05 - EROOR" << std::endl;
        }
        { // Odejmowanie | - - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(-98.3);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("24.9", false)) std::cout << "TEST 2.06 - OK" << std::endl;
            else std::cout << "TEST 2.06 - EROOR" << std::endl;
        }
        { // Odejmowanie | - - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("25.0", true)) std::cout << "TEST 2.07 - OK" << std::endl;
            else std::cout << "TEST 2.07 - EROOR" << std::endl;
        }
        { // Odejmowanie | - - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("25.1", true)) std::cout << "TEST 2.08 - OK" << std::endl;
            else std::cout << "TEST 2.08 - EROOR" << std::endl;
        }
        //
        { // Odejmowanie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.0", true)) std::cout << "TEST 2.09 - OK" << std::endl;
            else std::cout << "TEST 2.09 - EROOR" << std::endl;
        }
        { // Odejmowanie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(-98.300);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.5", true)) std::cout << "TEST 2.10 - OK" << std::endl;
            else std::cout << "TEST 2.10 - EROOR" << std::endl;
        }
        { // Odejmowanie | + - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.0", true)) std::cout << "TEST 2.11 - OK" << std::endl;
            else std::cout << "TEST 2.11 - EROOR" << std::endl;
        }
        { // Odejmowanie | + - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.5", true)) std::cout << "TEST 2.12 - OK" << std::endl;
            else std::cout << "TEST 2.12 - EROOR" << std::endl;
        }
        //
        { // Odejmowanie | - + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.0", false)) std::cout << "TEST 2.13 - OK" << std::endl;
            else std::cout << "TEST 2.13 - EROOR" << std::endl;
        }
        { // Odejmowanie | - + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(98.3);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.5", false)) std::cout << "TEST 2.14 - OK" << std::endl;
            else std::cout << "TEST 2.14 - EROOR" << std::endl;
        }
        { // Odejmowanie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.0", false)) std::cout << "TEST 2.15 - OK" << std::endl;
            else std::cout << "TEST 2.15 - EROOR" << std::endl;
        }
        { // Odejmowanie | - + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("221.5", false)) std::cout << "TEST 2.16 - OK" << std::endl;
            else std::cout << "TEST 2.16 - EROOR" << std::endl;
        }
        //
        { // Odejmowanie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("98.0", true)) std::cout << "TEST 2.17 - OK" << std::endl;
            else std::cout << "TEST 2.17 - EROOR" << std::endl;
        }
        { // Odejmowanie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(2);
            mc::MatChar num2(100);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("98.0", false)) std::cout << "TEST 2.18 - OK" << std::endl;
            else std::cout << "TEST 2.18 - EROOR" << std::endl;
        }
        { // Odejmowanie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("102.0", false)) std::cout << "TEST 2.19 - OK" << std::endl;
            else std::cout << "TEST 2.19 - EROOR" << std::endl;
        }
        { // Odejmowanie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(-2);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("102.0", true)) std::cout << "TEST 2.20 - OK" << std::endl;
            else std::cout << "TEST 2.20 - EROOR" << std::endl;
        }
        //
        { // Odejmowanie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(5);
            mc::MatChar num2(5);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("0.0", true)) std::cout << "TEST 2.21 - OK" << std::endl;
            else std::cout << "TEST 2.21 - EROOR" << std::endl;
        }
        { // Odejmowanie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(5.2);
            mc::MatChar num2(5.2);
            mc::MatChar num3 = num1 - num2;
            num3.print();
            if (num3.test("0.0", true)) std::cout << "TEST 2.22 - OK" << std::endl;
            else std::cout << "TEST 2.22 - EROOR" << std::endl;
        }
    } catch (const char * txtException){
        std::cout << "EXEPTION: " << txtException << std::endl;
    }
}

void test3() {
    try {
        { // Mnożenie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", true)) std::cout << "TEST 3.01 - OK" << std::endl;
            else std::cout << "TEST 3.01 - EROOR" << std::endl;
        }
        { // Mnożenie | + + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(98.300);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12110.56", true)) std::cout << "TEST 3.02 - OK" << std::endl;
            else std::cout << "TEST 3.02 - EROOR" << std::endl;
        }
        { // Mnożenie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", true)) std::cout << "TEST 3.03 - OK" << std::endl;
            else std::cout << "TEST 3.03 - EROOR" << std::endl;
        }
        { // Mnożenie | + + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12108.06", true)) std::cout << "TEST 3.04 - OK" << std::endl;
            else std::cout << "TEST 3.04 - EROOR" << std::endl;
        }
        //
        { // Mnożenie | - - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", true)) std::cout << "TEST 3.05 - OK" << std::endl;
            else std::cout << "TEST 3.05 - EROOR" << std::endl;
        }
        { // Mnożenie | - - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(-98.3);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12110.56", true)) std::cout << "TEST 3.06 - OK" << std::endl;
            else std::cout << "TEST 3.06 - EROOR" << std::endl;
        }
        { // Mnożenie | - - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", true)) std::cout << "TEST 3.07 - OK" << std::endl;
            else std::cout << "TEST 3.07 - EROOR" << std::endl;
        }
        { // Mnożenie | - - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12108.06", true)) std::cout << "TEST 3.08 - OK" << std::endl;
            else std::cout << "TEST 3.08 - EROOR" << std::endl;
        }
        //
        { // Mnożenie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", false)) std::cout << "TEST 3.09 - OK" << std::endl;
            else std::cout << "TEST 3.09 - EROOR" << std::endl;
        }
        { // Mnożenie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(-98.300);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12110.56", false)) std::cout << "TEST 3.10 - OK" << std::endl;
            else std::cout << "TEST 3.10 - EROOR" << std::endl;
        }
        { // Mnożenie | + - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", false)) std::cout << "TEST 3.11 - OK" << std::endl;
            else std::cout << "TEST 3.11 - EROOR" << std::endl;
        }
        { // Mnożenie | + - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12108.06", false)) std::cout << "TEST 3.12 - OK" << std::endl;
            else std::cout << "TEST 3.12 - EROOR" << std::endl;
        }
        { // Mnożenie | - + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", false)) std::cout << "TEST 3.13 - OK" << std::endl;
            else std::cout << "TEST 3.13 - EROOR" << std::endl;
        }
        { // Mnożenie | - + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(98.3);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12110.56", false)) std::cout << "TEST 3.14 - OK" << std::endl;
            else std::cout << "TEST 3.14 - EROOR" << std::endl;
        }
        { // Mnożenie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12054.0", false)) std::cout << "TEST 3.15 - OK" << std::endl;
            else std::cout << "TEST 3.15 - EROOR" << std::endl;
        }
        { // Mnożenie | - + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("12108.06", false)) std::cout << "TEST 3.16 - OK" << std::endl;
            else std::cout << "TEST 3.16 - EROOR" << std::endl;
        }
        //===============================================================
        //~~~~~~~~~~~~~~~~~~~~~~~~~~Dodatkowe~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        //===============================================================

        { // Mnożenie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("200.0", true)) std::cout << "TEST 3.17 - OK" << std::endl;
            else std::cout << "TEST 3.17 - EROOR" << std::endl;
        }
        { // Mnożenie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(2);
            mc::MatChar num2(100);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("200.0", true)) std::cout << "TEST 3.18 - OK" << std::endl;
            else std::cout << "TEST 3.18 - EROOR" << std::endl;
        }
        { // Mnożenie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("200.0", false)) std::cout << "TEST 3.19 - OK" << std::endl;
            else std::cout << "TEST 3.19 - EROOR" << std::endl;
        }
        { // Mnożenie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(-2);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("200.0", false)) std::cout << "TEST 3.20 - OK" << std::endl;
            else std::cout << "TEST 3.20 - EROOR" << std::endl;
        }
        //
        { // Mnożenie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(5);
            mc::MatChar num2(-5);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("25.0", false)) std::cout << "TEST 3.21 - OK" << std::endl;
            else std::cout << "TEST 3.21 - EROOR" << std::endl;
        }
        { // Mnożenie | - + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-5);
            mc::MatChar num2(5);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("25.0", false)) std::cout << "TEST 3.22 - OK" << std::endl;
            else std::cout << "TEST 3.22 - EROOR" << std::endl;
        }
        { // Mnożenie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(5.2);
            mc::MatChar num2(-5.2);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("27.04", false)) std::cout << "TEST 3.23 - OK" << std::endl;
            else std::cout << "TEST 3.23 - EROOR" << std::endl;
        }
        { // Mnożenie | - + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-5.2);
            mc::MatChar num2(5.2);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("27.04", false)) std::cout << "TEST 3.24 - OK" << std::endl;
            else std::cout << "TEST 3.24 - EROOR" << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(1);
            mc::MatChar num2(1);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("1.0", true)) std::cout << "TEST 3.25 - OK" << std::endl;
            else std::cout << "TEST 3.25 - EROOR" << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(1);
            int num2 = 2;
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("2.0", true)) std::cout << "TEST 3.26 - OK" << std::endl;
            else std::cout << "TEST 3.26 - EROOR" << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(1);
            int num2 = 1;
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("1.0", true)) std::cout << "TEST 3.27 - OK" << std::endl;
            else std::cout << "TEST 3.27 - EROOR" << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(246);
            mc::MatChar num2(10);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("2460.0", true)) std::cout << "TEST 3.28 - OK" << std::endl;
            else std::cout << "TEST 3.28 - EROOR" << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(362880);
            mc::MatChar num2(10);
            mc::MatChar num3 = num1 * num2;
            num3.print();
            if (num3.test("3628800.0", true)) std::cout << "TEST 3.29 - OK" << std::endl;
            else std::cout << "TEST 3.29 - EROOR" << std::endl;
        }
    }
    catch (const char* txtException) {
        std::cout << "EXEPTION: " << txtException << std::endl;
    }
}

void test4() {
    try {
        { // Dzielenie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.255102", true)) std::cout << "TEST 4.01 - OK" << std::endl;
            else std::cout << "TEST 4.01 - EROOR" << std::endl;
        }
        { // Dzielenie | + + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(98.300);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.253306", true)) std::cout << "TEST 4.02 - OK" << std::endl;
            else std::cout << "TEST 4.02 - EROOR" << std::endl;
        }
        { // Dzielenie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796748", true)) std::cout << "TEST 4.03 - OK" << std::endl;
            else std::cout << "TEST 4.03 - EROOR" << std::endl;
        }
        { // Dzielenie | + + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796431", true)) std::cout << "TEST 4.04 - OK" << std::endl;
            else std::cout << "TEST 4.04 - EROOR" << std::endl;
        }
        //
        { // Dzielenie | - - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.255102", true)) std::cout << "TEST 4.05 - OK" << std::endl;
            else std::cout << "TEST 4.05 - EROOR" << std::endl;
        }
        { // Dzielenie | - - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(-98.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.253306", true)) std::cout << "TEST 4.06 - OK" << std::endl;
            else std::cout << "TEST 4.06 - EROOR" << std::endl;
        }
        { // Dzielenie | - - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796748", true)) std::cout << "TEST 4.07 - OK" << std::endl;
            else std::cout << "TEST 4.07 - EROOR" << std::endl;
        }
        { // Dzielenie | - - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796431", true)) std::cout << "TEST 4.08 - OK" << std::endl;
            else std::cout << "TEST 4.08 - EROOR" << std::endl;
        }
        //
        { // Dzielenie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123);
            mc::MatChar num2(-98);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.255102", false)) std::cout << "TEST 4.09 - OK" << std::endl;
            else std::cout << "TEST 4.09 - EROOR" << std::endl;
        }
        { // Dzielenie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(123.200);
            mc::MatChar num2(-98.300);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.253306", false)) std::cout << "TEST 4.10 - OK" << std::endl;
            else std::cout << "TEST 4.10 - EROOR" << std::endl;
        }
        { // Dzielenie | + - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98);
            mc::MatChar num2(-123);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796748", false)) std::cout << "TEST 4.11 - OK" << std::endl;
            else std::cout << "TEST 4.11 - EROOR" << std::endl;
        }
        { // Dzielenie | + - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(98.2);
            mc::MatChar num2(-123.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796431", false)) std::cout << "TEST 4.12 - OK" << std::endl;
            else std::cout << "TEST 4.12 - EROOR" << std::endl;
        }
        //
        { // Dzielenie | - + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123);
            mc::MatChar num2(98);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.255102", false)) std::cout << "TEST 4.13 - OK" << std::endl;
            else std::cout << "TEST 4.13 - EROOR" << std::endl;
        }
        { // Dzielenie | - + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-123.2);
            mc::MatChar num2(98.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("1.253306", false)) std::cout << "TEST 4.14 - OK" << std::endl;
            else std::cout << "TEST 4.14 - EROOR" << std::endl;
        }
        { // Dzielenie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98);
            mc::MatChar num2(123);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796748", false)) std::cout << "TEST 4.15 - OK" << std::endl;
            else std::cout << "TEST 4.15 - EROOR" << std::endl;
        }
        { // Dzielenie | - + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-98.2);
            mc::MatChar num2(123.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.796431", false)) std::cout << "TEST 4.16 - OK" << std::endl;
            else std::cout << "TEST 4.16 - EROOR" << std::endl;
        }
        { // Dzielenie | + + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("50.0", true)) std::cout << "TEST 4.17 - OK" << std::endl;
            else std::cout << "TEST 4.17 - EROOR" << std::endl;
        }
        { // Dzielenie | + + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100.200);
            mc::MatChar num2(2.300);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("43.565217", true)) std::cout << "TEST 4.18 - OK" << std::endl;
            else std::cout << "TEST 4.18 - EROOR" << std::endl;
        }
        { // Dzielenie | + + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(2);
            mc::MatChar num2(100);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.02", true)) std::cout << "TEST 4.19 - OK" << std::endl;
            else std::cout << "TEST 4.19 - EROOR" << std::endl;
        }
        { // Dzielenie | + + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(2.2);
            mc::MatChar num2(100.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.021934", true)) std::cout << "TEST 4.20 - OK" << std::endl;
            else std::cout << "TEST 4.20 - EROOR" << std::endl;
        }
        //
        { // Dzielenie | - - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-100);
            mc::MatChar num2(-2);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("50.0", true)) std::cout << "TEST 4.21 - OK" << std::endl;
            else std::cout << "TEST 4.21 - EROOR" << std::endl;
        }
        { // Dzielenie | - - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-100.2);
            mc::MatChar num2(-2.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("43.565217", true)) std::cout << "TEST 4.22 - OK" << std::endl;
            else std::cout << "TEST 4.22 - EROOR" << std::endl;
        }
        { // Dzielenie | - - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-2);
            mc::MatChar num2(-100);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.02", true)) std::cout << "TEST 4.23 - OK" << std::endl;
            else std::cout << "TEST 4.23 - EROOR" << std::endl;
        }
        { // Dzielenie | - - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-2.2);
            mc::MatChar num2(-100.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.021934", true)) std::cout << "TEST 4.24 - OK" << std::endl;
            else std::cout << "TEST 4.24 - EROOR" << std::endl;
        }
        //
        { // Dzielenie | + - | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2(-2);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("50.0", false)) std::cout << "TEST 4.25 - OK" << std::endl;
            else std::cout << "TEST 4.25 - EROOR" << std::endl;
        }
        { // Dzielenie | + - | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100.200);
            mc::MatChar num2(-2.300);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("43.565217", false)) std::cout << "TEST 4.26 - OK" << std::endl;
            else std::cout << "TEST 4.26 - EROOR" << std::endl;
        }
        { // Dzielenie | + - | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(2);
            mc::MatChar num2(-100);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.02", false)) std::cout << "TEST 4.27 - OK" << std::endl;
            else std::cout << "TEST 4.27 - EROOR" << std::endl;
        }
        { // Dzielenie | + - | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(2.2);
            mc::MatChar num2(-100.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.021934", false)) std::cout << "TEST 4.28 - OK" << std::endl;
            else std::cout << "TEST 4.28 - EROOR" << std::endl;
        }
        //
        { // Dzielenie | - + | 1 > 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-100);
            mc::MatChar num2(2);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("50.0", false)) std::cout << "TEST 4.29 - OK" << std::endl;
            else std::cout << "TEST 4.29 - EROOR" << std::endl;
        }
        { // Dzielenie | - + | 1 > 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-100.2);
            mc::MatChar num2(2.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("43.565217", false)) std::cout << "TEST 4.30 - OK" << std::endl;
            else std::cout << "TEST 4.30 - EROOR" << std::endl;
        }
        { // Dzielenie | - + | 1 < 2 | int
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-2);
            mc::MatChar num2(100);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.02", false)) std::cout << "TEST 4.31 - OK" << std::endl;
            else std::cout << "TEST 4.31 - EROOR" << std::endl;
        }
        { // Dzielenie | - + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(-2.2);
            mc::MatChar num2(100.3);
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("0.021934", false)) std::cout << "TEST 4.32 - OK" << std::endl;
            else std::cout << "TEST 4.32 - EROOR" << std::endl;
        }
        //
        //
        //
        { // Dzielenie | - + | 1 < 2 | float
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(855553655);
            mc::MatChar num2(98655 );
            mc::MatChar num3 = num1 / num2;
            num3.print();
            if (num3.test("8672.177335", true)) std::cout << "TEST 4.33 - OK" << std::endl;
            else std::cout << "TEST 4.33 - EROOR" << std::endl;
        }

    } catch (const char * txtException){
        std::cout << "EXEPTION: " << txtException << std::endl;
    }
}

void test6() {
    try {
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(10);
            mc::MatChar num2 = !num1;
            num2.print();
            if (num2.test("3628800.0", true)) std::cout << "TEST 6.01 - OK" << std::endl;
            else std::cout << "TEST 6.01 - EROOR" << std::endl;
            std::cout << mc::MatChar::convertToExponentialFigure(num2) << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(13);
            mc::MatChar num2 = !num1;
            num2.print();
            if (num2.test("6227020800.0", true)) std::cout << "TEST 6.02 - OK" << std::endl;
            else std::cout << "TEST 6.02 - EROOR" << std::endl;
            std::cout << mc::MatChar::convertToExponentialFigure(num2) << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(100);
            mc::MatChar num2 = !num1;
            num2.print();
            if (num2.test("93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000.0", true)) std::cout << "TEST 6.03 - OK" << std::endl;
            else std::cout << "TEST 6.03 - EROOR" << std::endl;
            std::cout << mc::MatChar::convertToExponentialFigure(num2) << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(400);
            mc::MatChar num2 = !num1;
            num2.print();
            if (num2.test("64034522846623895262347970319503005850702583026002959458684445942802397169186831436278478647463264676294350575035856810848298162883517435228961988646802997937341654150838162426461942352307046244325015114448670890662773914918117331955996440709549671345290477020322434911210797593280795101545372667251627877890009349763765710326350331533965349868386831339352024373788157786791506311858702618270169819740062983025308591298346162272304558339520759611505302236086810433297255194852674432232438669948422404232599805551610635942376961399231917134063858996537970147827206606320217379472010321356624613809077942304597360699567595836096158715129913822286578579549361617654480453222007825818400848436415591229454275384803558374518022675900061399560145595206127211192918105032491008000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", true)) std::cout << "TEST 6.04 - OK" << std::endl;
            else std::cout << "TEST 6.04 - EROOR" << std::endl;
            std::cout << mc::MatChar::convertToExponentialFigure(num2) << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(600);
            mc::MatChar num2 = !num1;
            num2.print();
            if (num2.test("12655723162254307425418678245150829297671403862274660768187828858528140823147351237817802795619571074765208532598060224803240903782164769430795025578054271906283387643826088448124626488332623608376164081221171179439885840257818732919037889603719186743943363062139593784473922231852782547619771723889252476871186000174697934549112845662596182308280390615184691924446215552586523740084932807259056238962104689731522587564412231618018774350801526839567367444928206231310973619440354723718012867753019556135721376207959558860559933052856914157120622980057169891912595926540427596853441276985006724869558201930657900240943007657817473684008944448183219124163017666607770667585082169598239230274035517738648065600492702095732843492708856036920219883363111527988109277392696562776813446645651238419301586157342867860646666350050113314787911320639668510871569846664873595017518995670958477806411667505346462590471136862647349666243426242677175204732314281064417939041868653741187423064985189556742640111598580035644021835576715752869397465453828584471291269955890393294448315746500268702149708808053100406398480942695623586049403348084970064668900206251516968479727515576425962392136269169089884609794271331061018895634421094082310408889752954265842691732460538911784960000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", true)) std::cout << "TEST 6.05 - OK" << std::endl;
            else std::cout << "TEST 6.05 - EROOR" << std::endl;
            std::cout << mc::MatChar::convertToExponentialFigure(num2) << std::endl;
        }
        {
            std::cout << "--------------------------------------------------" << std::endl;
            mc::MatChar num1(1000);
            mc::MatChar num2 = !num1;
            num2.print();
            if (num2.test("402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", true)) std::cout << "TEST 6.06 - OK" << std::endl;
            else std::cout << "TEST 6.06 - EROOR" << std::endl;
            std::cout << mc::MatChar::convertToExponentialFigure(num2) << std::endl;
        }
    }catch(const char * txtException){
        std::cout << "EXEPTION: " << txtException << std::endl;
    }
}

}
int main() {

test1();
test2();
test3();
test4();
test6();

    return 0;
}
