//
// Created by ADMIN on 07-Oct-25.
//

#include "Dog.h"

Dog::Dog(const char *nm) throw(int) :
    Animal(nm) {
    std::cout << "Constructing Dog" << animal_num
            << " name [ " << name << ']' << std::endl;
}

Dog::~Dog() {
    std::cout << "Destructing Dog" << animal_num
            << " name [ " << name << ']' << std::endl;
}

void* Dog::operator new[](size_t sz) {
    std::cout << "Dog::new[]" << std::endl;
    return ::new char[sz];
}


void Dog::operator delete[](void* p) {
    std::cout << "Dog::delete[]" << std::endl;
    return ::delete[] p;
}