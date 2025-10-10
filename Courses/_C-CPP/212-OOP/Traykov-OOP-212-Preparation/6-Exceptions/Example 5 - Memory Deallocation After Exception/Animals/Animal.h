//
// Created by ADMIN on 07-Oct-25.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H

#include <iostream>
#include <cstddef> //std::size_t
#include <cstring> // memset



class Animal {

protected:
    static int i;
    int animal_num;
    static const int sz = 40;
    char name[sz];

public:
    Animal(const char* nm="Animal") throw(int);
    ~Animal();

    void* operator new[](size_t sz);
    void operator delete[](void* p);

};
int Animal::i = 0;


#endif //CPP_ANIMAL_H