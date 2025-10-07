//
// Created by ADMIN on 07-Oct-25.
//

#include <iostream>
#include "MyCustomException.h"

int main() {


    try {
        throw MyCustomException("Illegal value.");

    } catch (const MyCustomException& e) {
        std::cerr << "Caught exception [" << e.what() << "]\n";
    }


    return 0;
}