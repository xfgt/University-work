//
// Created by ADMIN on 05-Oct-25.
//
#include <iostream>
using namespace std;

class B {
public:
    B();
    B(int n);
};

B::B() {
    cout << "B::B()\n";
}
B::B(int n) {
    cout << "B::B(" << n << ")\n";
}


class D : public B {
public:
    D();
    D(int n);
private:
    B b;
};

D::D() {
    cout << "D::D();\n";
}


D::D(int n)     // D::D(int)
: B(n)          // B::B()
{
    b = B(-n);  // B::B(int)
    cout << "D::D(" << n << ")\n";
}

int main() {
    D d(3);

    /*
     * output:
        B::B(3)
        B::B()
        B::B(-3)
        D::D(3)
     *
     */


    return 0;
}

