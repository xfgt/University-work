//
// Created by ADMIN on 07-Oct-25.
//

#include <iostream>

#include "FutureValueError.h"

int main() {


    try {


        throw FutureValueError("Some error");
        // throw std::logic_error("Some logic_error");
        // throw std::overflow_error("Some overflow_error");


    } catch (const FutureValueError& e) {
        std::cerr << "Caught of type FutureValueError: " << e.what() << std::endl;

    } catch (const std::logic_error& le) {
        std::cerr << "Caught of type logic_error: " << le.what() << std::endl;

    } catch (const std::exception& x) {
        std::cerr << "Caught of whatever type: " << x.what() << std::endl;
    }


    return 0;
}