//
// Created by ADMIN on 05-Oct-25.
//

#include <iostream>
using namespace std;


class B {
public:
    void print(int n) const;

    ~B(); // custom add by me
};
void B::print(int n) const {
    cout << n << "\n";
}
// custom add by me
B::~B() {
    cout << "~B() [" << this << "]\n";
}


class D : public B{
public:
    void print(int n) const;


    ~D(); // custom add by me
};

void D::print(int n) const {

    cout << "D::print() [" << this << "]\tn=" << n << '\n'; // custom add by me

    if (n <= 1)
        B::print(n);
    else if (n % 2 == 0)
        print(n/2);
    else
        print(3 * n + 1);
}


// custom add by me
D::~D() {
    cout << "~D() [" << this << "]\n";
}



int main() {
    D d;
    d.print(3);
    return 0;
}