//
// Created by ADMIN on 06-Oct-25.
//


#include "Employee.h"

int main() {


    Employee* bp;
    bp = new Employee("Teodor", 1337.420, 3.5);
    bp->print();
    delete bp;

    bp = new Manager("Sava", 25000, 15, "CEO");
    bp->print();
    delete bp;

    bp = new Executive("Michael", 1001, 2, "Finances");
    bp->print();
    delete bp;


    bp = nullptr;


    return 0;
}
