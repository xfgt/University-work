//
// Created by LOCAL_ADMIN on 19-Mar-26.
//


/*

    A function can be defined so that its code is copied to
    any location in memory where it is called.

    This was done to prevent copying the address of
    the function in the stack, the passing of parameters, and the execution of the reference to the function's location.
    This function is called inline.
    To indicate that a function will be built-in, its
    The definition must start with the keyword inline. For example:


*/


/*
    The compiler attempts to insert the function’s code directly at the call site, rather than creating a normal call.
    This removes Function call overhead,
    Stack operations,
    Return jumps,

    Inline Function — Best For

    Small functions (1–5 lines)
    Getters/setters
    Constructors/destructors defined in class bodies
    Utility functions in header files
    Performance‑critical tiny operations

*/

#include <iostream>

inline void PrintEndOfLine() {
    std::cout << '\n';
}

int main(){

    std::cout << 'a'; PrintEndOfLine();

    return 0;
}



/*

    Using built-in functions is justified when it is known that
    their code will be very short. Otherwise, their use
    This would result in excessive duplication of the same code in the stack.


*/