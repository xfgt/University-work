//
// Created by jeff on 18.09.25 г..
//

#include "Employee.h"

Employee::Employee(string n, double sal) {
    m_name = n;
    m_salary = sal;
}
string Employee::getName() const { return m_name; }
double Employee::getSalary() const { return m_salary; }

void Employee::setName(string n) { m_name = n; }
void Employee::setSalary(double s) { m_salary = s; }

ostream& operator<<(ostream& out, const Employee& obj) {
    out << "Name: " << obj.getName() << ", Salary: " << obj.getSalary();
    return out;
}

istream& operator>>(istream& is, Employee& obj) {
    Employee temp;
    string n{};
    double sl{};
    is >> n >> sl;

    obj.setName(n);
    obj.setSalary(sl);
    return is;
}

