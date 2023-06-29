#include "MatChar.h"

const bool DEBUG = false;

namespace mc {

    // Konstruktor 0.0
    MatChar::MatChar() { // ODŚWIEŻONA
        // if(DEBUG) std::cout << "Constructor 1 : " << this << std::endl;
        if (DEBUG) std::cout << "Constructor 1 : " << this;
        this->mpNumber = new(std::nothrow) char[4];
        this->mpNumber[0] = '0';
        this->mpNumber[1] = '.';
        this->mpNumber[2] = '0';
        this->mpNumber[3] = '\0';
        this->mIsPositive = true;
        if (DEBUG) std::cout << " OK" << std::endl;
    }

    // Konstruktor z liczby typu int
    MatChar::MatChar(int _number) { // ODŚWIEŻONA
        if (DEBUG) std::cout << "Constructor 2 : " << this;
        //Ustalanie znaku liczby.
        if (_number < 0) {
            this->mIsPositive = false;
            _number = abs(_number);
        } else {
            this->mIsPositive = true;
        }

        //Zmiana int'a na char array pointer.
        std::string str = std::to_string(_number);
        int size = mDesigneteSizeOfDigits(_number);
        this->mpNumber = new(std::nothrow) char[size + 1 + 2];
        if (this->mpNumber == nullptr) throw "Constructor 2";
        strcpy(mpNumber, str.c_str());
        mpNumber[size] = '.';
        mpNumber[size + 1] = '0';
        mpNumber[size + 2] = '\0';
        if (DEBUG) std::cout << " OK" << std::endl;
    }

    // https://stackoverflow.com/questions/1786497/sprintf-double-precision-in-c
    MatChar::MatChar(double _number) { // ODŚWIEŻONA
        if (DEBUG) std::cout << "Constructor 3 : " << this;
        if (_number < 0) {
            this->mIsPositive = false;
            _number = std::abs(_number);
        } else {
            this->mIsPositive = true;
        }


        std::string str = std::to_string(_number);
        int sizeall = static_cast<int> (str.length());

        int size = 0;
        bool findDot = false;
        int afterDot = 0;
        for (int i = 0; i < sizeall; i++) {
            if (str[i] == '.'){
                findDot = true;
            }
            if(findDot && str[i] != '\0'){
                afterDot++;
            }
            if(str[i] == '\0' || afterDot == 6){
                size = sizeall;
                break;
            }
        }

        this->mpNumber = new(std::nothrow) char[size + 1];

        for (int i = 0; i < size; i++) {
            this->mpNumber[i] = str[i];
        }
        //std::strcpy(this->mpNumber,str.c_str());
        mpNumber[size] = '\0';

        mRemoveZeros(mpNumber);
    }

// WYMAGANIA: _mpNumber ma nie posiadać przednich i tylnich zer oraz znaku '-'. Musi posiadać '\0' na końcu.
// TODO: dodać zabezpieczenia | Może zmienić na konstruktor prywatny
    MatChar::MatChar(char *_mpNumber, bool _mIsPositive) { // ODŚWIEŻONA
        if (DEBUG) std::cout << "Constructor 4 : " << this;
        unsigned long long size = strlen(_mpNumber);
        this->mpNumber = new(std::nothrow) char[size + 1];
        if (this->mpNumber == nullptr) throw "Constructor 4";
        memcpy(this->mpNumber, _mpNumber, size);
        this->mpNumber[size] = '\0';
        //
        this->mIsPositive = _mIsPositive;

        if (DEBUG) std::cout << " OK" << std::endl;
    }

    // Konstruktor przesuwający
    MatChar::MatChar(const MatChar &obj) {
        if (DEBUG) std::cout << "Constructor 5 : " << this;
        unsigned long long size = strlen(obj.mpNumber);
        this->mpNumber = new(std::nothrow) char[size + 1];
        memcpy(this->mpNumber, obj.mpNumber, size);
        this->mpNumber[size] = '\0';
        //
        this->mIsPositive = obj.mIsPositive;

        if (DEBUG) std::cout << " OK" << std::endl;
    }

    MatChar::~MatChar() { // OK
        if (DEBUG) std::cout << "DESTRUCTOR 1 : " << this;
//        std::cout << (this->mpNumber);
        // delete [] (char*)(this->mpNumber);
        delete[] mpNumber;
        if (DEBUG) std::cout << " OK" << std::endl;
    }

//------------------------------------------------------------------------------------------------------------
// OPERATORY

//    MatChar MatChar::operator=(const MatChar &MatChar2) {
//        delete [] this->mpNumber;
//        this->mpNumber = MatChar2.mpNumber;
//
//        return *this;
//    }

    MatChar &MatChar::operator=( const MatChar &obj) {
        if( this == &obj )
        {
            return *this;
        }
        int size = static_cast<int> (strlen(obj.mpNumber));
        char * newmpNumber = new char[size+1];
        memcpy(newmpNumber,obj.mpNumber,size);
        newmpNumber[size] = '\0';
        this->mpNumber = newmpNumber;
        return *this;
    }

    MatChar MatChar::operator+(const MatChar &MatChar2) { // TODO: DO SPRAWDZENIA
        unsigned long long sizempNumber1 = strlen(mpNumber);
        unsigned long long sizempNumber2 = strlen(MatChar2.mpNumber);

        char * str1 = new(std::nothrow) char[sizempNumber1 + 1];
        char * str2 = new(std::nothrow) char[sizempNumber2 + 1];

        memcpy(str1, this->mpNumber, sizempNumber1);
        memcpy(str2, MatChar2.mpNumber, sizempNumber2);

        str1[sizempNumber1] = '\0';
        str2[sizempNumber2] = '\0';

        alingTwoChararray(str1, str2);

        if (this->mIsPositive == MatChar2.mIsPositive) { // Znaki takie same
            char *added = add(str1, str2);
            mRemoveZeros(added);
            MatChar ansObj(added, this->mIsPositive);
            //
            delete[] added;
            //
            return ansObj;
        } else { // Znaki inne
            int comp = compare(str1, str2);

            if (comp == 0) { // równe
                delete[] str1;
                delete[] str2;
                return {}; // 0.0
            } else if (comp == 1) { // str1 większe
                char *subtracted = subtract(str1, str2);
                mRemoveZeros(subtracted);
                MatChar ansObj(subtracted, this->mIsPositive);
                delete[] subtracted;
                return ansObj;
            } else if (comp == -1) { // str2 większe
                char *subtracted = subtract(str2, str1);
                mRemoveZeros(subtracted);
                MatChar ansObj(subtracted, MatChar2.mIsPositive);
                delete[] subtracted;
                return ansObj;
            }
        }

        delete[] str1;
        delete[] str2;
        return {}; // 0,0 - nigdy nie powinno się wykonać
    }

    MatChar MatChar::operator-(const MatChar &MatChar2) {
        unsigned long long sizempNumber1 = strlen(this->mpNumber);
        unsigned long long sizempNumber2 = strlen(MatChar2.mpNumber);

        char *str1 = new(std::nothrow) char[sizempNumber1 + 1];
        char *str2 = new(std::nothrow) char[sizempNumber2 + 1];

        memcpy(str1, this->mpNumber, sizempNumber1);
        memcpy(str2, MatChar2.mpNumber, sizempNumber2);

        str1[sizempNumber1] = '\0';
        str2[sizempNumber2] = '\0';

        int dot1 = findDot(str1);
        int dot2 = findDot(str2);

        if(!(dot1 == -2 || dot2 == -2)) alingTwoChararray(str1, str2);

        if (this->mIsPositive && MatChar2.mIsPositive) { // + +
            int comp = compare(str1, str2);
            if (comp == 0) {
                delete[] str1;
                delete[] str2;
                return {}; // 0.0
            } else if (comp == 1) {
                char *subtracted = subtract(str1, str2);
                mRemoveZeros(subtracted);
                MatChar ansObj(subtracted, true);
                delete[] subtracted;
                return ansObj;
            } else if (comp == -1) {
                char *subtracted = subtract(str2, str1);
                mRemoveZeros(subtracted);
                MatChar ansObj(subtracted, false);
                delete[] subtracted;
                return ansObj;
            }
        }

        if (!this->mIsPositive && !MatChar2.mIsPositive) { // - -
            int comp = compare(str1, str2);
            if (comp == 0) {
                delete[] str1;
                delete[] str2;
                return {}; // 0.0
            } else if (comp == 1) {
                char *subtracted = subtract(str1, str2);
                mRemoveZeros(subtracted);
                MatChar ansObj(subtracted, false);
                delete[] subtracted;
                return ansObj;
            } else if (comp == -1) {
                char *subtracted = subtract(str2, str1);
                mRemoveZeros(subtracted);
                MatChar ansObj(subtracted, true);
                delete[] subtracted;
                return ansObj;
            }
        }

        if (this->mIsPositive && !MatChar2.mIsPositive) { // + -
            char *added = add(str1, str2);
            mRemoveZeros(added);
            MatChar ansObj(added, true);
            delete[] added;
            return ansObj;
        }


        if (!this->mIsPositive && MatChar2.mIsPositive) { // - +
            char *added = add(str1, str2);
            mRemoveZeros(added);
            MatChar ansObj(added, false);
            delete[] added;
            return ansObj;
        }

        delete[] str1;
        delete[] str2;
        std::cout << "CO TY TU KÓRWA ROBISZ? !!! " << std::endl;
        return {}; // NIGDY NIE POWINNO SIĘ WYKONAĆ
    }

    MatChar MatChar::operator*(const MatChar &MatChar2) {
        unsigned long long sizempNumber1 = strlen(this->mpNumber);
        unsigned long long sizempNumber2 = strlen(MatChar2.mpNumber);

        char *str1 = new(std::nothrow) char[sizempNumber1 + 1];
        char *str2 = new(std::nothrow) char[sizempNumber2 + 1];

        memcpy(str1, this->mpNumber, sizempNumber1);
        memcpy(str2, MatChar2.mpNumber, sizempNumber2);

        str1[sizempNumber1] = '\0';
        str2[sizempNumber2] = '\0';

        alingTwoChararray(str1, str2);

        if(this->mIsPositive == MatChar2.mIsPositive) {
            char * multiplied = multiply(str1,str2);
            mRemoveZeros(multiplied);
            MatChar ansObj(multiplied, true);
            delete[] multiplied;
            return ansObj;
        } else {
            char * multiplied = multiply(str1,str2);
            mRemoveZeros(multiplied);
            MatChar ansObj(multiplied, false);
            delete[] multiplied;
            return ansObj;
        }

        delete[] str1;
        delete[] str2;
        std::cout << "CO TY TU KÓRWA ROBISZ? !!! " << std::endl;
        return {}; // NIGDY NIE POWINNO SIĘ WYKONAĆ
    }

    MatChar MatChar::operator/(const MatChar &MatChar2) {

        // Kopiujemy wejściowe liczby, aby nie modyfikować oryginałów
        char *cDividend = new char[strlen(this->mpNumber) + 1];
        strcpy(cDividend, this->mpNumber);
        char *cDivisor = new char[strlen(MatChar2.mpNumber) + 1];
        strcpy(cDivisor, MatChar2.mpNumber);

        alingTwoChararray(cDividend, cDivisor);

        removeDecimalPoint(cDividend);
        removeDecimalPoint(cDivisor);

        bool znak = this->mIsPositive == MatChar2.mIsPositive;


        MatChar dividend(cDividend,true);
        MatChar divisor(cDivisor,true);
        MatChar quotient(0);


        while(compare(dividend.mpNumber,divisor.mpNumber) == 1){

            dividend = dividend - divisor;
            quotient = quotient + 1;
        }

//        std::cout << "dividend  " << dividend.mpNumber << std::endl;
//        std::cout << "divisor  " << divisor.mpNumber << std::endl;
//        std::cout << "quotient  " << quotient.mpNumber << std::endl;

        //RESZTA
        double n1 = std::atof(dividend.mpNumber);
        double n2 = std::atof(divisor.mpNumber );

        double n3 = n1 / n2;


        MatChar reszta(n3);
        MatChar ans = quotient + reszta;
        if(znak){
            ans.mIsPositive = true;
        } else {
            ans.mIsPositive = false;
        }

//        std::cout << "ans  " << ans.mpNumber << std::endl;

        return ans;
    }

    MatChar MatChar::operator!() {
        int n = std::atoi(this->mpNumber);

//        char * factorial = new char[4];
//        factorial[0] = '0';
//        factorial[1] = '.';
//        factorial[2] = '0';
//        factorial[3] = '\0';

        MatChar Factorial(1);

        mc::MatChar buf(1);

        for(int i = 1; i <= n; i++){
            Factorial = Factorial * i;
            //Factorial = buf;
        }

        return Factorial;
    }

    bool MatChar::operator>(const MatChar &MatChar2) {

        char * num1 = new char[strlen(this->mpNumber)+1];
        char * num2 = new char[strlen(MatChar2.mpNumber)+1];

        memcpy(num1, this->mpNumber,strlen(this->mpNumber)+1);
        memcpy(num2, MatChar2.mpNumber,strlen(MatChar2.mpNumber)+1);

        alingTwoChararray(num1,num2);

        if(this->mIsPositive && !MatChar2.mIsPositive) return true;

        if(compare(num1,num2) == 1){
            delete [] num1;
            delete [] num2;
            return true;
        } else
        {
            delete [] num1;
            delete [] num2;
            return false;
        }
    }

    bool MatChar::operator<(const MatChar &MatChar2) {
        char * num1 = new char[strlen(this->mpNumber)+1];
        char * num2 = new char[strlen(MatChar2.mpNumber)+1];

        memcpy(num1, this->mpNumber,strlen(this->mpNumber)+1);
        memcpy(num2, MatChar2.mpNumber,strlen(MatChar2.mpNumber)+1);

        alingTwoChararray(num1,num2);

        if(MatChar2.mIsPositive && !this->mIsPositive) return true;

        if(compare(num2,num1) == 1){
            delete [] num1;
            delete [] num2;
            return true;
        } else
        {
            delete [] num1;
            delete [] num2;
            return false;
        }
    }


//------------------------------------------------------------------------------------------------------------
// Operacje bezpośrednie

    char *MatChar::add(char *num1, char *num2) { // TODO: DO SPRAWDZENIA
        unsigned long long num1size = strlen(num1);
        unsigned long long num2size = strlen(num2);

        if (num1size != num2size) return nullptr;

        int num1dot = findDot(num1);
        int num2dot = findDot(num2);

        if (num1dot != num2dot) return nullptr;

        removeDecimalPoint(num1);
        removeDecimalPoint(num2);

        reverseCharArray(num1);
        reverseCharArray(num2);

        // Ponowne liczenie po usunięciu kropki
        num1size = strlen(num1);

        //Dodawanie;
        int transferred = 0;
        char *numAns = new(std::nothrow) char[num1size + 1 + 1];
        for (int i = 0; i < num1size + 1; i++) numAns[i] = '0';
        numAns[num1size + 1] = '\0';
        for (int i = 0; i < num1size; i++) {
            int n1 = ((int) num1[i] - 48);
            int n2 = ((int) num2[i] - 48);

            int n3 = n1 + n2 + (numAns[i] - 48) + transferred;

            if (n3 >= 10) {
                numAns[i] = static_cast<char> ((n3 % 10) + 48);
                transferred = (n3 / 10);
            } else {
                numAns[i] = static_cast<char> ((n3 % 10) + 48);
                transferred = 0;
            }
        }
        numAns[num1size] = static_cast<char> (transferred+48);
        //
        reverseCharArray(numAns);

        // numAns = mRemoveZeros(numAns);

        insertDecimalPoint(numAns, num1dot);

        delete [] num1;
        delete [] num2;

        return numAns;
    }

//Przyjmuje: 2 liczby "czyste" wyrównane
    char *MatChar::subtract(char *num1, char *num2) {
        unsigned long long num1size = strlen(num1);
        unsigned long long num2size = strlen(num2);

        if (num1size != num2size) return nullptr;

        int num1dot = findDot(num1);
        int num2dot = findDot(num2);

        if (num1dot != num2dot) return nullptr;

        removeDecimalPoint(num1);
        removeDecimalPoint(num2);

        reverseCharArray(num1);
        reverseCharArray(num2);

        // Ponowne liczenie po usunięciu kropki
        num1size = strlen(num1);
        num2size = strlen(num2);
        unsigned long long size;
        if (num1size == num2size) size = num1size;
        else return nullptr;

        //
        char *numAns = new(std::nothrow) char[size + 1]; // Wynik nie może zajmować więcej miejsca niż liczba, od której odejmujemy.
        for (int i = 0; i < size + 1; i++) numAns[i] = '0';
        numAns[size] = '\0';
        for (int i = 0; i < size; i++) { // Przejdz po każdym
            int n1 = ((int) num1[i] - 48);
            int n2 = ((int) num2[i] - 48);

            if (n1 >= n2) { // Po prosty odejmujemy
                numAns[i] = static_cast<char> ((n1 - n2) + 48);
            } else { // Przenoszenie
                int j = i;
                while (true) { // Idz, dopóki nie znajdziesz liczby większej od 0.
                    j++;
                    if (num1[j] == '0') continue;
                    else {
                        num1[j] = static_cast<char> (num1[j] - 1);
                        while (true) {
                            j--;
                            if (j == i) break;
                            else num1[j] = '9';
                        }
                    }
                    numAns[i] = static_cast<char> (n1 + 10 - n2 + 48);
                    break;
                }
            }

        }

        reverseCharArray(numAns);

        //numAns = mRemoveZeros(numAns);

        insertDecimalPoint(numAns, num1dot);

        delete [] num1;
        delete [] num2;

        return numAns;
    }

    char *MatChar::multiply(char *num1, char *num2) { // TODO: DO SPRAWDZENIA
        unsigned long long num1size = strlen(num1);
        unsigned long long num2size = strlen(num2);

        if (num1size != num2size) return nullptr;

        int num1dot = findDot(num1);
        int num2dot = findDot(num2);

        if (num1dot != num2dot) return nullptr;

        removeDecimalPoint(num1);
        removeDecimalPoint(num2);

        //////

        char *multiplied; //Mnożona
        int multiplied_size = 0;
        char *multiplier; //Mnożąca
        int multiplier_size = 0;

        int compared = compare(num1,num2);
        if(compared == 1 || compared == 0) {
            multiplied = num1;
            multiplied_size = num1size - 1;
            multiplier = num2;
            multiplier_size = num2size - 1;
        } else {
            multiplied = num2;
            multiplied_size = num2size - 1;
            multiplier = num1;
            multiplier_size = num1size - 1;
        }

        //////

        reverseCharArray(num1);
        reverseCharArray(num2);

        //////

        int ansSize = num1size+num2size;
        int transfer = 0;
        char ** numAnsTabs = new char*[multiplier_size];
        for(int i = 0; i < multiplier_size; i++){
            numAnsTabs[i] = new char[ansSize+1];
            for(int j = 0;j < ansSize; j++) numAnsTabs[i][j] = '0';
            numAnsTabs[i][ansSize] = '\0';
        }

        //////

        for(int i = 0; i < multiplier_size; i++){
            for(int j = 0; j < multiplied_size; j++){
            int n1 = (int)(multiplied[j] - 48);
            int n2 = (int)(multiplier[i] - 48);

            int n3 = n1 * n2 + transfer;

            if(n3 >= 10){
                int c1 = n3 % 10;
                //numAns[i+j] = static_cast<char> (c1 + 48);
                numAnsTabs[i][i+j] = static_cast<char> (c1 + 48);
                transfer = n3 / 10;
            }else{
                numAnsTabs[i][i+j] = static_cast<char> (n3 + 48);
                transfer = 0;
            }
            }
            numAnsTabs[i][i + multiplied_size] = static_cast<char> (transfer + 48);
            transfer = 0;
        }

        char * numAns = new char[ansSize+1];
        for(int i = 0; i < ansSize; i++ ) numAns[i] = '0';
        numAns[ansSize] = '\0';
        int sum = 0;
        transfer = 0;
        for (int i = 0; i < ansSize; i++) {
            sum = 0;
            sum += transfer;
            for (int j = 0; j < multiplier_size; j++) {
                sum += (numAnsTabs[j][i] - 48);
            }
            int c1 = sum % 10;
            numAns[i] = static_cast<char> (c1 + 48);
            transfer = sum / 10;
        }

        //////

        reverseCharArray(numAns);

        insertDecimalPoint(numAns, num1dot+num2dot);

        mRemoveZeros(numAns);


        for (int i = 0; i < multiplier_size; i++) {
            delete[] numAnsTabs[i];
        }
        delete[] numAnsTabs;

        delete [] num1;
        delete [] num2;

        return numAns;
        //return nullptr;
    }

//    char *MatChar::divide(char* num1, char* num2) {
//        int B  = 10;
//        int m = strlen(num1), n = strlen(num2);
//        int q[m - n + 1];
//        int r[n];
//        for (int i = m - 1, j = n - 1; i >= n - 1; i--, j--)
//            r[j] = num1[i] - '0';
//        for (int j = m - n; j >= 0; j--) {
//            q[j] = (r[n - 1] * B + r[n - 2]) / (num2[n - 1] - '0');
//            r[n - 1] = r[n - 1] * B + r[n - 2] - q[j] * (num2[n - 1] - '0');
//            for (int i = n - 2; i >= 0; i--)
//                r[i] = r[i + 1] - q[j] * (num2[i] - '0');
//        }
//        char *result = new char[m+n+1];
//        int i = 0;
//        for(; i < m-n; i++)
//            result[i] = q[i]+'0';
//        result[i++] = ' ';
//        for(int j = 0; j < n; j++, i++)
//            result[i] = r[j]+'0';
//        result[i] = '\0';
//        return result;
//    }

//------------------------------------------------------------------------------------------------------------
// INNE

// Porównuje 2 liczby przekazane jako char array.
// Zwraca: -1, gdy liczba str2 jest większa | 0, gdy są równe | 1, gdy str1 jest większa | 2, gdy nastąpi błąd.
// Wymaga podania liczb o jednakowej długości i '.' na tej samej pozycji. (patrz alingTwoChararray())
// PS. Znaki '-' oraz '.' można zostawić, nie powinny wpływać na działanie funkcji.
    int MatChar::compare(char *str1, char *str2) { // TODO: DO SPRAWDZENIA
        unsigned long long str1size = strlen(str1);
        unsigned long long str2size = strlen(str2);

        if (str1size != str2size) return 2;
        unsigned long long size = str1size;

        int str1dot = findDot(str1);
        int str2dot = findDot(str2);

        if (str1dot != str2dot) return 2;

        for (int i = 0; i < size; i++) {
            int n1 = (int) str1[i] - 48;
            int n2 = (int) str2[i] - 48;

            if (n1 > n2) {
                return 1;
            }

            if (n2 > n1) {
                return -1;
            }
        }
        return 0;
    }

    void MatChar::print() { //OK
        if (!mIsPositive) printf("-");
        printf("%s", mpNumber);
        printf("\n");
    }

// Przyjmuje liczbę
// Zwraca ile znaków zajmuje liczba (nie bierze pod uwagę znaku liczby)
    int MatChar::mDesigneteSizeOfDigits(int _number) {
        if (_number == 0) return 1;
        return static_cast<int> (floor(log10(abs(_number))) + 1);
    }

    int MatChar::mDesigneteSizeOfDigits(double _number) { // TODO: DO SPRAWDZENIA
        // Sprawdzenie, czy x jest równe 0
        if (_number == 0) return 1;

        // Obliczenie ilości cyfr za pomocą log10 ()
        int digits = (int) log10(_number) + 1;

        // Sprawdzenie, czy x ma część ułamkową
        if (_number - floor(_number) != 0) {
            // Jeśli tak, to obliczenie ilości cyfr w części ułamkowej za pomocą +sprintf ()
            char str[100];
            sprintf(str, "%.10f", _number);
            for (int i = 0; str[i] != '\0'; ++i) {
                if (str[i] == '.') {
                    ++digits;
                    break;
                }
            }
        }

        // Zwrócenie ilości cyfr
        return digits + 1; // +1 ponieważ '.'
    }

    int MatChar::findDot(char *str) {
        unsigned long long size = strlen(str);
        for (int i = 0; i < size; i++) {
            if (str[i] == '.') return static_cast<int> (size - i - 1);
            if (str[i] == '\0') return -1;
        }
        return -2;
    }

    void MatChar::alingTwoChararray(char * &str1, char * &str2) { // TODO: DO SPRAWDZENIA

        unsigned long long str1size = strlen(str1);
        unsigned long long str2size = strlen(str2);

        int str1dot = findDot(str1);
        int str2dot = findDot(str2);

        if (str1dot < 0 || str2dot < 0) exit(22);

        int str1right = str1dot;
        int str2right = str2dot;
        int str1left = static_cast<int> (str1size - (str1dot + 1));
        int str2left = static_cast<int> (str2size - (str2dot + 1));

        // Dodawanie liczb na prawo
        if (str1right > str2right) {
            int difference = str1right - str2right;
            if (difference < 0) exit(22); //DEBUG
            str2 = addZerosRight(str2, difference); // Stara tablica jest zwalniana w funkcji
        } else if (str1right < str2right) {
            int difference = str2right - str1right;
            if (difference < 0) exit(22); //DEBUG
            str1 = addZerosRight(str1, difference);
        }

        // Dodawanie liczb na lewo
        if (str1left > str2left) {
            int difference = str1left - str2left;
            str2 = addZerosLeft(str2, difference);
        } else if (str1left < str2left) {
            int difference = str2left - str1left;
            str1 = addZerosLeft(str1, difference);
        }
    }

    char *MatChar::addZerosLeft(char *str, int numZeros) { // TODO: DO SPRAWDZENIA
        unsigned long long length = strlen(str);
        char *newStr = new(std::nothrow) char[length + numZeros + 1]; // +1 dla znaku null na końcu nowego char array

        for (int i = 0; i < numZeros; i++) {
            newStr[i] = '0';
        }

        for (int i = 0; i < length; i++) {
            newStr[numZeros + i] = str[i];
        }

        newStr[length + numZeros] = '\0'; // dodaj znak null na końcu nowego char array

        delete[] str;

        // str = nullptr;

        return newStr;
    }

    char *MatChar::addZerosRight(char *str, int numZeros) { // TODO: DO SPRAWDZENIA
        unsigned long long length = strlen(str);

        char *newStr = new(std::nothrow) char[length + numZeros + 1]; // +1 dla znaku null na końcu nowego char array

        for (int i = 0; i < length; i++) {
            newStr[i] = str[i];
        }

        for (int i = 0; i < numZeros; i++) {
            newStr[length + i] = '0';
        }

        newStr[length + numZeros] = '\0'; // dodaj znak null na końcu nowego char array

        delete[] str;

        // str = nullptr;

        return newStr;
    }

    // Działa tylko w przypadku gdy napis posiada tylko 1 kropkę.
    void MatChar::removeDecimalPoint(char * &str) { // TODO: DO SPRAWDZENIA
        unsigned long long size = strlen(str);
        char * newStr = new (std::nothrow) char[size+1];
        memcpy(newStr,str,size);
        newStr[size] = '\0';

        int i;
        for (i = 0; newStr[i] != '\0'; i++) {
            if (newStr[i] == '.') {
                int j;
                for (j = i; newStr[j] != '\0'; j++) {
                    newStr[j] = newStr[j + 1];
                }
                // Zmniejsz licznik, aby sprawdzić ponownie aktualną pozycję
                i--;
            }
        }

        delete [] str;
        str = newStr;
    }

    void MatChar::insertDecimalPoint(char *&str, int index) {
        // Obliczamy długość ciągu
        unsigned long long length = strlen(str);

        // Sprawdzamy, czy indeks jest poprawny (nie może być mniejszy niż 0 ani większy niż długość ciągu)
        if (index < 0 || index > length) {
            return;
        }

        // Convert the index to a zero-based index
        index = length - index;

        char *newStr = new (std::nothrow) char[length + 1 + 1];

        memcpy(newStr, str, length);

        // Zmienna pomocnicza do przesuwania znaków
        char temp;

        // Pętla przechodząca przez ciąg od końca do indeksu, na którym ma być wstawiona kropka
        for (int i = static_cast<int>(length); i > index; i--) {
            // Przesuwamy znaki o jedno miejsce w prawo
            temp = newStr[i];
            newStr[i] = newStr[i - 1];
            newStr[i - 1] = temp;
        }

        // Wstawiamy kropkę na podany indeks
        newStr[index] = '.';
        newStr[length + 1] = '\0';

        delete[] str;

        str = newStr;
    }

    void MatChar::reverseCharArray(char *str) { // TODO: DO SPRAWDZENIA
        // Obliczamy długość ciągu
        unsigned long long length = strlen(str);

        // Zmienna pomocnicza do zamiany miejscami znaków
        char temp;

        // Pętla, która przechodzi przez ciąg od końca do początku
        for (int i = 0; i < length / 2; i++) {
            // Zamiana miejscami znaków
            temp = str[i];
            str[i] = str[length - i - 1];
            str[length - i - 1] = temp;
        }
    }

    bool MatChar::test(std::string str, bool _mIsPositive) {
        // porównanie długości ciągów znaków
        if (str.length() != std::strlen(this->mpNumber))
            return false;

        // porównanie każdego znaku w obu ciągach
        for (std::size_t i = 0; i < str.length(); i++) {
            if (str[i] != this->mpNumber[i])
                return false;
        }

        if (this->mIsPositive != _mIsPositive) return false;

        return true;
    }

    void MatChar::mRemoveZeros(char *&str) { // TODO: do sprawdzenia || dodaprzypadek np 3400
        int frontZeros = 0;
        int backZeros = 0;
        //int startSize = mDesignateSizeOfmpNumber();
        unsigned long long startSize = strlen(str);

        // Wyznaczanie przednich 0
        while (true) {
            if (str[frontZeros] == '0') {
                if(str[frontZeros+1] != '.')frontZeros++;
                else break;
            }else break;
        }

        bool pointDetected = false;
        for (int i = 0; i < startSize; i++) {
            if (str[i] == '.') pointDetected = true;
            if (str[i] == '\0') break;
        }

        // Wyznaczanie tylnich 0, jeżeli w napisie istnieje kropka
        if (pointDetected) {
            while (true) {
                if (str[(startSize - 1) - backZeros] == '0' && str[(startSize - 1) - backZeros - 1] != '.') backZeros++;
                else break;
            }
        }

        char * newstr = new (std::nothrow) char[(startSize + 1) - frontZeros - backZeros];
        memcpy(newstr, (str + frontZeros), (startSize - frontZeros - backZeros));
        newstr[startSize - frontZeros - backZeros] = '\0';

        if (DEBUG) std::cout << "str - " << (str) << std::endl;
        if (DEBUG) std::cout << "newstr - " << (newstr) << std::endl;


        delete[] str;

        str = newstr;
    }

    char * MatChar::convertToExponentialFigure(const MatChar &MatChar2){
        char * str = MatChar2.mpNumber;
        int size = 0;
        int i = 1;
        while(true){
            if(str[i] == '.'){
                size = i - 7;
                break;
            }else{
                i++;
            }
        }
        //
        int exponentSize = mDesigneteSizeOfDigits(size);
        char * ExponentialFigure = new char[12+exponentSize];
        ExponentialFigure[0] = str[0];
        ExponentialFigure[1] = '.';
        ExponentialFigure[2] = str[1];
        ExponentialFigure[3] = str[2];
        ExponentialFigure[4] = str[3];
        ExponentialFigure[5] = str[4];
        ExponentialFigure[6] = str[5];
        ExponentialFigure[7] = str[6];
        ExponentialFigure[8] = 'x';
        ExponentialFigure[9] = '1';
        ExponentialFigure[10] = '0';
        ExponentialFigure[11] = '^';
        std::string s = std::to_string(size);
        char const *pchar = s.c_str();
        for(int j = 0; j  < exponentSize; j++){
            ExponentialFigure[12+j] = pchar[j];
        }
        ExponentialFigure[12+exponentSize] = '\0';
        //
        return ExponentialFigure;
    }

    char * MatChar::convertToExponentialFigure(const char * str){
        int size = 0;
        int i = 0;
        while(true){
            if(str[i] == '.'){
                size = i - 7 + 1;
                break;
            }else{
                i++;
            }
        }
        //
        int exponentSize = mDesigneteSizeOfDigits(size);
        char * ExponentialFigure = new char[12+exponentSize];
        ExponentialFigure[0] = str[0];
        ExponentialFigure[1] = '.';
        ExponentialFigure[2] = str[1];
        ExponentialFigure[3] = str[2];
        ExponentialFigure[4] = str[3];
        ExponentialFigure[5] = str[4];
        ExponentialFigure[6] = str[5];
        ExponentialFigure[7] = str[6];
        ExponentialFigure[8] = 'x';
        ExponentialFigure[9] = '1';
        ExponentialFigure[10] = '0';
        ExponentialFigure[11] = '^';
        std::string s = std::to_string(size);
        char const *pchar = s.c_str();
        for(int j = 0; j  < exponentSize; j++){
            ExponentialFigure[12+j] = pchar[j];
        }
        //
        return ExponentialFigure;
    }

} // mc
