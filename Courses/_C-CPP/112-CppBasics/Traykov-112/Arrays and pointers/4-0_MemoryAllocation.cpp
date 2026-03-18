//
// Created by LOCAL_ADMIN on 18-Mar-26.
//

#include <iostream>
#include <exception>
#include <thread>
#include <chrono>

int main() {

    // On the stack: limited size; LIFO - Last in first out;
    int a;
    //long double ld[ 1000000 ]; // error on run time: Signal: SIGSEGV (Segmentation fault) (stack overflow).


    // Heap

    // THE RAM FILLER
    // int x = 10;
    // unsigned long long* ptr;
    // while (true) {
    //     ptr = new unsigned long long[x]{};
    //     std::cout << x << std::endl;
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    //
    //     x *= 5;
    // }




    //delete[] ptr;

    unsigned long long* asdf = new unsigned long long[999999999]{};
    std::this_thread::sleep_for(std::chrono::seconds(5));
    delete[] asdf;
    return 0;
}
