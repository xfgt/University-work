//
// Created by ADMIN on 07-Oct-25.
//

#ifndef CPP_DOG_H
#define CPP_DOG_H
#include "Animal.h"

class Dog : public Animal{
public:
    Dog(const char* nm="Dog") throw(int);
    ~Dog();
    void* operator new[](size_t sz);
    void operator delete[](void* p);
};


#endif //CPP_DOG_H