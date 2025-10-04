//
// Created by ADMIN on 28-Aug-25.
//

#include <iostream>

#include "Point.h"

int main() {

    Point p1(1,1,1);
    p1.getCoordinates();

    p1.scaleUp(-2, 0.5, 5);
    p1.getCoordinates();


    return 0;
}