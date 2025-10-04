//
// Created by jeff on 18.09.25 г..
//

#include "Programmer.h"


Programmer::Programmer(string n, double sal) : Employee(n, sal) {}

string Programmer::getName() const {return "Hacker, " + Employee::getName() + "(Programmer)";}

ostream &operator<<(ostream &os, const Programmer &p) {
    os << p.getName() << ", Salary: " << p.getSalary();
    return os;
}