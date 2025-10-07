//
// Created by ADMIN on 07-Oct-25.
//

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"


#include <iostream>



void unexpected_rethrow() {
    std::cout << "Unexpected error occurred!!!" << std::endl;
    throw;
}

int main() {
    std::set_unexpected(unexpected_rethrow); // setting unexpected error to use the function pointer to our ~
                                            // ~ custom defined function.


    try {
        Animal n1{"Animal before array"};
        // Throws exception
        Animal* arr = new Animal[7];
        Cat n2("Cat after array");

    } catch (int i) {
        std::cout << "Caught " << i << std::endl;
    }


    try {
        Animal n3("Animal before unexpected");
        Cat n4("z");
        Dog d5("Dog after unexpected");
    }catch (char c) {
        std::cout << "Caught " << c << std::endl;
    }

    return 0;
}