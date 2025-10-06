//
// Created by ADMIN on 05-Oct-25.
//
#include <iostream>
using namespace std;

struct Base {
    int a;
    float b;
};

struct Derived : public Base {
    int c;
    int d;
};


int main() {


    Base q;
    Derived w;

    Base* pq = &w;

    pq->a;


    return 0;
}