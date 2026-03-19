//
// Created by LOCAL_ADMIN on 18-Mar-26.
//

#include <iostream>
#include <exception>
#include <thread>
#include <chrono>


void demonstrateStack() {
    static int x = 0;
    std::cout << reinterpret_cast<void*>(demonstrateStack) << ":\t" << x << std::endl;
    if (x == 10) {
        std::cout << "Stack has reached size of 10!\nWe're backing up.." << std::endl;
        return;
    }
    x++;
    demonstrateStack(); // recursion
    x--;
    std::cout << reinterpret_cast<void*>(demonstrateStack) << ":\t" << x << std::endl;
}

int main() {

    // On the stack: limited size; LIFO - Last in first out;
    // https://web.stanford.edu/class/archive/cs/cs107/cs107.1258/lectures/7/Lecture7.pdf
    int a;
    //long double ld[ 1000000 ]; // error on run time: Signal: SIGSEGV (Segmentation fault) (stack overflow).
    demonstrateStack();

    // Heap

    // Filling the ram up (pt. 1)
    {
        unsigned long long* asdf = new unsigned long long[999999999]{};
        std::this_thread::sleep_for(std::chrono::seconds(5));
        delete[] asdf;
    }





    //THE RAM FILLER (pt. 2)
    {
        int x = 10;
        unsigned long long* ptr;
        while (true) {
            ptr = new unsigned long long[x]{};
            std::cout << x << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            x *= 5;
        }
        delete[] ptr; // wont execute because of exception
    }






    return 0;
}
