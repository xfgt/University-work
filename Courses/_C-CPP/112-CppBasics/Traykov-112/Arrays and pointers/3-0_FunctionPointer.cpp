//
// Created by LOCAL_ADMIN on 18-Mar-26.
//


#include <iostream>

using namespace std;
double Sum(double x, unsigned n) {
    double S = 0.0;
    unsigned i = 1;
    while(i <= n) {
        S += x / i;
        ++i;
    }
    return S;
}


int main() {

    double (*pFunc)( double, unsigned ); // function pointer called "pFunc"
    pFunc = Sum;
    cout << pFunc( 2.5, 10 ) << endl;

    return 0;
}