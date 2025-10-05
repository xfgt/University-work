#include <iostream>
#include <sstream>

#include "BigInt.h"

int main() {

    std::string a, b;
    std::cin >> a >> b;

    BigInt start{ a };
    BigInt finish{ b };
    std::ostringstream oss;
    
    bool noMatch = true;

    BigInt firstDivisibleBy_45;
    std::string strFirstDivisibleBy_45;
    std::string currBigIntStr = start.getDigits();
    BigInt currBigInt = start;



    while (noMatch && currBigInt < finish) {

        char lastDigit = currBigIntStr[currBigIntStr.size() - 1];
        bool IsDivisibleBy_5 = (lastDigit == '0' || lastDigit == '5');
        int sumOfDigits = 0;

        for (int i = 0; i < currBigIntStr.size(); i++) {
            sumOfDigits += currBigIntStr[i] - 48;
        }

        bool IsDivisibleBy_9 = !(sumOfDigits % 9);
        if (IsDivisibleBy_5 && IsDivisibleBy_9) {
            oss << currBigIntStr << std::endl;

            strFirstDivisibleBy_45 = currBigIntStr;
            firstDivisibleBy_45 = currBigIntStr;
            noMatch = false;
            continue;
        }

        currBigInt = currBigIntStr;
        BigInt bigInt_1{ 1 };
        currBigInt += bigInt_1;
        currBigIntStr = currBigInt.getDigits();
    }


    BigInt divisibleBy_45 = strFirstDivisibleBy_45;
    BigInt bigInt_45{ 45 };


    while (divisibleBy_45 < finish) {
        divisibleBy_45 += bigInt_45;
        if (divisibleBy_45 < finish) {
            std::string divisibleBy_45_Str = divisibleBy_45.getDigits();
            oss << divisibleBy_45_Str << std::endl;
        }
    }


    std::cout << oss.str();
    return 0;
}