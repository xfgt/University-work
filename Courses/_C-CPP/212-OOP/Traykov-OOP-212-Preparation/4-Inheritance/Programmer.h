//
// Created by jeff on 18.09.25 г..
//

#ifndef ASDF_PROGRAMMER_H
#define ASDF_PROGRAMMER_H
#include "Employee.h"


class Programmer : public Employee {


private:
    friend ostream &operator<<(ostream &os, const Programmer &p);
public:
    Programmer(string="", double=0.0L);

    string getName() const;
};


#endif //ASDF_PROGRAMMER_H