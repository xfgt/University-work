//
// Created by jeff on 18.09.25 г..
//


#include "Employee.h"
#include "../Programmer.h"


int main() {

    Employee e;
    cout << e << '\n';
    cin >> e;
    cout << e << '\n';

    Programmer p("Larry", 2341.234);
    cout << p << '\n';

    Programmer j;
    cin >> j;
    cout << j << '\n';
    return 0;
}
