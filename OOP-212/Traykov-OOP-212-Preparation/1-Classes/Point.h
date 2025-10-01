//
// Created by ADMIN on 28-Aug-25.
//

#pragma once
#include <iostream>
class Point {

private:
    double x;
    double y;
    double z;
public:
    explicit Point(double=0, double=0, double=0);
    void getCoordinates() const;
    void scaleUp(double=0, double=0, double=0);
    void translate(double=0);
};