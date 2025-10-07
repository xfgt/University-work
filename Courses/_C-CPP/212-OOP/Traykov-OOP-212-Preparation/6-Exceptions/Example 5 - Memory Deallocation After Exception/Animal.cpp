//
// Created by ADMIN on 07-Oct-25.
//

#include "Animal.h"


Animal::Animal(const char *nm) throw(int) {
    animal_num = i++;

    memset(name, 0, sz);
    strncpy(name, nm, sz-1);

    std::cout << "Constructing Animal" << animal_num
                << " name [" << name << ']' << std::endl;

    if (animal_num == 5)
        throw int(5);

    if (*nm == 'z')
        throw char('z');
}

Animal::~Animal() {
    std::cout << "Destructing Animal" << animal_num
                << " name [ " << name << ']' << std::endl;
}


void *Animal::operator new [](size_t sz) {
    std::cout << "Animal::new[]" << std::endl;
    return ::new char[sz]; // from the main scope (::)
}


void Animal::operator delete [](void* p) {
    std::cout << "Animal::delete[]" << std::endl;
    return ::delete[] p; // from the main scope (::)
}
