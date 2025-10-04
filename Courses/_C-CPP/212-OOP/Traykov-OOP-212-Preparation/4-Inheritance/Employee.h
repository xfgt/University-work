//
// Created by jeff on 18.09.25 г..
//

#ifndef ASDF_EMPLOYEE_H
#define ASDF_EMPLOYEE_H
#include <iostream>
#include <string>

using namespace std;
class Employee {

    friend ostream& operator<<(ostream&, const Employee&);
    friend istream& operator>>(istream&, Employee&);

private:
    string m_name;
    double m_salary;

public:
    Employee(string ="", double=0.0L);

    string getName() const;
    double getSalary() const;

    void setName(string);
    void setSalary(double);

};


#endif //ASDF_EMPLOYEE_H