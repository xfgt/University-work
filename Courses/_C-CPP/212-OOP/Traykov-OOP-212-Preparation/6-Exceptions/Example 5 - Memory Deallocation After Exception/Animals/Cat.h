//
// Created by ADMIN on 07-Oct-25.
//

#ifndef CPP_CAT_H
#define CPP_CAT_H

#include "Animal.h"

class Cat : public Animal{
public:
    Cat(const char* nm="Cat") throw(int);
    ~Cat();

    void* operator new[](size_t sz);
    void operator delete[](void* p);

};


#endif //CPP_CAT_H