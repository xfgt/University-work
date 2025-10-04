#include "Building.h"

int main (){

    Building b;

    cin >> b;
    cout << b;

    Building e;
    cout << e;
    e = b;
    cout << e;
    cout << b;

    Building k("jf", 23, 3, 1, 53);
    cout << k;

    b = k;
    cout << b;
    cout << e;
    cout << k;


    b + 2;
    13 + e;
    k + b.getBuilding_builtFloors();

    cout << b << e << k;


    return 0;
}