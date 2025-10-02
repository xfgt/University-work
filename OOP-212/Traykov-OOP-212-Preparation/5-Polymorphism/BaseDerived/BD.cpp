//
// Created by jeff on 2.10.25 г..
//

#include <iostream>
#include <cassert>
#include <string.h>

using namespace std;

class A_Base{
public:
    A_Base(char * = "");
    virtual ~A_Base();
    A_Base(const A_Base&);
    A_Base& operator=(const A_Base&);
    virtual void print() const;
private:
    char * x;
};

class B_Derived: public A_Base{
public:
    B_Derived(char * = "", char * = "");
    ~B_Derived();
    B_Derived(const B_Derived&);
    B_Derived& operator=(const B_Derived&);
    void print() const;
private:
    char * x;
};

//Inheritance.cpp
A_Base::A_Base(char * a){
    x = new char[strlen(a)+1];
    assert(x != NULL);
    strcpy(x, a);
}

A_Base::~A_Base(){
    std::cout << "~A_Base() \n";
    delete [] x;
}

A_Base::A_Base(const A_Base& p){
    x = new char[strlen(p.x)+1];
    assert(x != NULL);
    strcpy(x, p.x);
}

A_Base& A_Base::operator=(const A_Base& p){
    if(this != &p){
        delete [] x;
        x = new char[strlen(p.x)+1];
        assert(x != NULL);
        strcpy(x, p.x);
    }
    return *this;
}

void A_Base::print() const{
    std::cout << "A_base::x = " << x << "\n";
}


B_Derived::B_Derived(char * a, char * b):A_Base(a){
    x = new char[strlen(b)+1];
    assert(x != NULL);
    strcpy(x, b);
}

B_Derived::~B_Derived(){
    std::cout << "~B_Derived() \n";
    delete [] x;
}

B_Derived::B_Derived(const B_Derived& p):A_Base(p){
    delete [] x;
    x = new char[strlen(p.x)+1];
    assert(x != NULL);
    strcpy(x, p.x);
}

B_Derived& B_Derived::operator=(const B_Derived& p){
    if(this != &p){
        A_Base::operator=(p);
        delete [] x;
        x = new char[strlen(p.x)+1];
        assert(x != NULL);
        strcpy(x, p.x);
    }
    return *this;
}

void B_Derived::print() const{
    A_Base::print();
    std::cout << "B_Derived::x = " << x << "\n";
}

//main.cpp
int main(){
    A_Base * ptr;
    ptr = new B_Derived("First value", "Second value");
    assert(ptr != NULL);
    ptr->print();
    delete ptr;
    return 0;
}