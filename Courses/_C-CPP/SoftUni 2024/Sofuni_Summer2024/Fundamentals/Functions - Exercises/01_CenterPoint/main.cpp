//
// Created by twister on 8/27/24.
//


#include <cmath>
#include <iostream>


double getDistance(const int& x, const int& y){

    double d = pow(x, 2);
    double m = pow(y, 2);
    double s = d + m;

    double distance = sqrt(s);

    return distance;
}

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    double distance1 = getDistance(a, b);
    double distance2 = getDistance(c, d);


    if(distance1 > distance2)
        std::cout << "(" << c << ", " << d << ")";
    else
        std::cout << "(" << a << ", " << b << ")";

    return 0;
}