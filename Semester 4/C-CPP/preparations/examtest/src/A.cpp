#include "A.h"
#include <iostream>
#include <cstring>


A::A(const char* name, int number, float point) : number(number), point(point){
    this->setName(name);
}

void A::setName(const char* name){
    if(name){
        if(strlen(name) <= MAX_SIZE)
            strcpy(this->name, name);
        else
            strncpy(this->name, name, MAX_SIZE);
    }
}




char* A::getName(){ return name; }
int A::getNumber() {return number;}
float A::getPoint() {return point;}

