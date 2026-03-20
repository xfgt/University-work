//
// Created by LOCAL_ADMIN on 20-Mar-26.
//

// Macros
#include <iostream>


#define SquareOf(x) x *x
#define CorrectSquareOf(x) (x)*(x)



int main(){

    int x = 3;
    std::cout << SquareOf(x) << std::endl;
    std::cout << SquareOf(x+4) << std::endl;
    std::cout << SquareOf(x+x) << std::endl;

    /*
        Expected:
            9
            49
            36

        Actual:
            9
            19
            15

        problem. The priority is missing;
    */

    // CorrectSquareOf
    std::cout << CorrectSquareOf(x) << std::endl;
    std::cout << CorrectSquareOf(x+4) << std::endl;
    std::cout << CorrectSquareOf(x+x) << std::endl;

    /*
        Expected:
            9
            49
            36

        Actual:
            9
            49
            36

        Good.
    */

    return 0;
}