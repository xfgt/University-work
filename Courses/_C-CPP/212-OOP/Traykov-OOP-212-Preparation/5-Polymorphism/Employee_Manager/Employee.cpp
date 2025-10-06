//
// Created by ADMIN on 06-Oct-25.
//

#include "Employee.h"

#include <iostream>
#include <cstring>
#include <cassert>

Employee::Employee(char *n, double slr, float xp) {
    std::cout << "Employee()\n";
    m_name = new char[strlen(n)+1];
    assert(m_name!=nullptr);
    strcpy_s(m_name, strlen(n)+1, n);

    m_salary = slr;
    m_yearsExperience = xp;
}

Employee::~Employee() {
    std::cout << "~Employee()\n";
    delete[] m_name;
}

void Employee::print() const {
    std::cout << "Name: " << m_name <<
                ", Salary: " << m_salary <<
                ", Years of experience: " << m_yearsExperience << '\n';
}

Manager::Manager(char *n, double slr, float xp, std::string dept)
    :Employee(n, slr, xp) {
    std::cout << "Manager()\n";
    m_departament = dept;
}

Manager::~Manager() {
    std::cout << "~Manager()\n";
}

void Manager::print() const {
    Employee::print();
    std::cout << "\tDepartament: " << m_departament << '\n';
}

Executive::Executive(char *n, double slr, float xp, std::string dept)
    :Manager(n, slr, xp, dept){
    std::cout << "Executive()\n";
}

void Executive::print() const {
    std::cout << "[Executive] ";
    Manager::print();
}

Executive::~Executive() {
    std::cout << "~Executive()\n";
}


