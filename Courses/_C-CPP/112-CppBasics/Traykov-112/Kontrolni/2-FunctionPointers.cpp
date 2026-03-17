//
// Created by LOCAL_ADMIN on 17-Mar-26.
//


#include <iostream>
#include <cstdarg> // special signature (ellipsis)

// Special function signature "Ellipses" (how printf works with %s and \n, and etc..)
// printf() is declared as printf(const char*, ...);
// const char* is a requirement that says first argument must be char*
void myPrintfXD(const char* str, ...) {

}

double findAverage(int n, ...) {
    double sum{};

    va_list list; // getting the argument list

    va_start (list, n);

    for (int arg = 0; arg < n; arg++) {
        sum += va_arg(list, int);       // accessing each argument one-by-one
    }

    va_end(list); // deallocation of va_list;


    return sum / n;
}


int main() {

    myPrintfXD("hello", 1, 'a', 3.14);



    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n'; // normal sum
    std::cout << findAverage(5, 1, '2', 3, 4, 5) << '\n'; // '2' is 50 so sum is 63 -> (63/5=12.6)
    std::cout << findAverage(6, 1, 2, 3,'4', 5, 6) << '\n'; // nice




    return 0;
}