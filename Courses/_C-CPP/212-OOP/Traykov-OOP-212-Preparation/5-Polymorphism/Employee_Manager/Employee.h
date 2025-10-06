//
// Created by ADMIN on 06-Oct-25.
//

#ifndef CPP_EMPLOYEE_H
#define CPP_EMPLOYEE_H

#include <iostream>
class Employee {
private:
    char* m_name;
    double m_salary;
    float m_yearsExperience;

public:
    explicit Employee(char* n="", double slr=.0l, float xp=.0f);
    virtual ~Employee();
    virtual void print() const;
};

class Manager : public Employee {
private:
    std::string m_departament;
public:
    explicit Manager(char* n="", double slr=.0l, float xp=.0f, std::string dept="");
    ~Manager() override;

    void print() const override;
};

class Executive : public Manager {
public:
    explicit Executive(char * n="", double slr=.0l, float xp=.0f, std::string dept="");

    void print() const override;
    ~Executive() override;
};


#endif //CPP_EMPLOYEE_H