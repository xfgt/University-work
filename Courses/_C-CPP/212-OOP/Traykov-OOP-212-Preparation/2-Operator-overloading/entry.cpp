//
// Created by ADMIN on 28-Aug-25.
//

#include "Money.h"
#include "BigInteger.h"

int main() {


    Money m1(1,50), m2;

    std::cout << m1;
    std::cin >> m2;
    std::cout << m2;

    std::cout << std::boolalpha << (m1 < m2) << std::endl;
    std::cout << (m1 - m2) << std::endl;



    BigInteger a("123456789");
    BigInteger b("987654321");
    std::cout << (a * b);



}
