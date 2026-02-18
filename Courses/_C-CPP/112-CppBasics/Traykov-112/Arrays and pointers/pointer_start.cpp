//
// Created by LOCAL_ADMIN on 18.2.2026 г..
//

#define SEPERATE std::cout << "=======================\n";

#include <iostream>


int copyValueFunction(int a) {
    return a + 1;
}

int modifyValueFunction(int& a) {
    return a + 1;
}

int pointerValueFunction(int* a) {
    return *a + 1;
}

int main() {


    int a = 5;
    int * pA = &a;

    // memory address
    std::cout << "memory address" << '\n';
    std::cout << &a << '\n';
    std::cout << pA << '\n';
    SEPERATE;

    // value
    std::cout << "value" << '\n';
    std::cout << a << '\n';
    std::cout << *pA << '\n';
    SEPERATE;


    std::cout << "\"pass by value\" (copy)" << '\n';
    std::cout << a << '\n';
    std::cout << copyValueFunction(a) << '\n';
    std::cout << copyValueFunction(*pA) << '\n';
    std::cout << a << '\n'; // original does not change; pass by value - it copies value to the function argument, which gets modified

    SEPERATE;

    std::cout << "\"pass by reference (&)\"" << '\n';
    std::cout << a << '\n';
    std::cout << modifyValueFunction(a) << '\n';
    std::cout << modifyValueFunction(*pA) << '\n';
    std::cout << a << '\n'; // original changes; argument is passed by reference - changes are made on the original address passed in the function argument;

    SEPERATE;


    std::cout << "\"pass by pointer\"" << '\n';
    std::cout << a << '\n';
    std::cout << pointerValueFunction(&a) << '\n'; // must use &
    std::cout << pointerValueFunction(pA) << '\n'; // must use &
    std::cout << a << '\n';


    std::flush(std::cout);
    return 0;
}