//
// Created by ADMIN on 07-Oct-25.
//

#include "Cat.h"

Cat::Cat(const char *nm) throw(int) :
    Animal(nm) {
    std::cout << "Constructing Cat" << animal_num
            << " name [ " << name << ']' << std::endl;
}


Cat::~Cat() {
    std::cout << "Destructing Cat" << animal_num
            << " name [ " << name << ']' << std::endl;
}

void* Cat::operator new [](size_t sz) {
    std::cout << "Cat::new[]" << std::endl;
    return ::new char[sz];
}

void Cat::operator delete [](void *p) {
    std::cout << "Cat::delete[]" << std::endl;
    return ::delete[] p;
}
