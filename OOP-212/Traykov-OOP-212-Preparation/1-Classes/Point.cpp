//
// Created by ADMIN on 28-Aug-25.
//


#include "Point.h"

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {};
void Point::getCoordinates() const {
    std::cout << x << ", " << y << ", " << z << std::endl;
}

void Point::scaleUp(double _x, double _y, double _z) {
    x *= _x;
    y *= _y;
    z *= _z;
}

void Point::translate(double scalar) {
    y *= scalar;
}

