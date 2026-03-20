//
// Created by LOCAL_ADMIN on 18-Mar-26.
//


/*
 * Function ponters usually are used whenever we need to pass a fucntion as a paramter to another fucntion.
 *
 *  A();
 *  B(expects X())
 *
 *  We pass A();
 *  B(A);
 *
 * 1. The function that later is going to be passed
 * to another function is called "registering";
 *
 *
 * 2. The function that needs the parameter is a "callback fucntion" - it is unknown during compilation, only its arguments and which type of function it expects as an argument.
 *
 *
 * The meaning of these terms is that the logging function registers a single execution of program code,
 * which will happen after it is requested. This can only be accomplished by pointing to a function (executable),
 * passing the value of the pointer as a parameter of the logging function.
 *
 *
 */

#include <iostream>
using namespace std;
// myfunc is an alias to -> double (*)(double, unsigned); that's it!
typedef double (*myfunc)(double, unsigned);

/*
    typedef int asdf;
    asdf e = 4;

    Without the typedef, declaring a function that accepts another function as an argument looks messy:
    void Reg(double (*f)(double, unsigned));

    With the typedef, it becomes much more readable:
    void Reg(myfunc f);
*/

void Reg(myfunc);                               // more readable
void Reg2 ( double (*f)(double, unsigned) );    // messy variant, still compiles!
/*                          ^
 *      How to read this    |
 *
 * Function "Reg2" returns noting because its declared as void;
 * Function "Reg2" accepts an argument which:
 *      is a function pointer called 'f'
 *          which representing function returns a type of double
 *              which representing function accepts two arguments; double and unsigned types;
 */

void what( void (*h) (unsigned long long, ...)); // damn.

/*
 *  same as Reg2, but it accepts a function which accepts unsigned long long & unknown number of arguments
 *
 */


double Sum(double, unsigned);

int main(){
    Reg(Sum);

    return 0;
}
void Reg(myfunc p) {
    cout << (*p)(2.5, 10) << endl;
}

double Sum(double x, unsigned n) {
    double S = 0.0;
    unsigned i = 1;
    while(i <= n) {
        S += x / i;
        ++i;
    }
    return S;
}
