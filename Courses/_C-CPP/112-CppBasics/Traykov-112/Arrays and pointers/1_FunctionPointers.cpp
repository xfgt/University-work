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



    va_start (list, n); // get the address of n in the argument list (where n is the last known argument in the argument list)
//                  ^
    //              |           get contents of va_list -> gdb: x/6dg <address of list> https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
    /*Because the address of this argument may be used in the va_start() macro,
     * it should not be declared as a register variable,
     *  or as a function
     *     or an array type.
     */

    for (int arg = 0; arg < n; arg++) {
        sum += va_arg(list, int);       // accessing each argument one-by-one
    }

    va_end(list); // deallocation of va_list;


    return sum / n;
}
//https://linux.die.net/man/3/va_start



int sum(int count, ...) {

    int s{};


    va_list args;
    va_start(args, count);


    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int);

        printf("%p: %d\n", &x, x);
        s += x;
    }


    /// do not forget!
    va_end(args);


    return s;
}

int main() {

    myPrintfXD("hello", 1, 'a', 3.14);



    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n'; // normal sum
    std::cout << findAverage(5, 1, '2', 3, 4, 5) << '\n'; // '2' is 50 so sum is 63 -> (63/5=12.6)
    std::cout << findAverage(6, 1, 2, 3,'4', 5, 6) << '\n'; // nice


    printf("Sum is: %d\n", sum(3, 1,23,4));



    return 0;
}