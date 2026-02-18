//
// Created by LOCAL_ADMIN on 18.2.2026 г..
//


#include <iostream>
#define SEPERATE std::cout << "=======================\n";

int main() {



    int a = 3;
    void* void_a_ptr = &a;

    std::cout << a << '\n';
    std::cout << * (int*) void_a_ptr << '\n';
    // 1. cast void pointer to int poninter
    // 2. deref int ponter's value

    SEPERATE

    void *v;
    int *p;


    int i = 0;
    int j = 1;                  // constatnts


    v = &i;                     // void -> int address


    p = (int*)v;                // v is void* which gets cast to int*
    std::cout << *p << '\n';    // int pointer deref and print
    // p = v




    p = &j;                     // change point to another address (int)
    v = p;                      // v points to p
    std::cout << *(int*)v << '\n'; // void pointer deref and type cast
    // v = p




    std::flush(std::cout);
    return 0;
}