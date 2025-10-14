//
// Created by twister on 8/27/24.
//



#include <iostream>
#include <cmath>

int main(){


    double a{}, b{}, c{};


    std::cin >> a >> b >> c;


    double det = b*b - (4 * a * c);


    if (det > 0)
        std::cout << (-b + sqrt(det)) / (2 * a) << ' ' << (-b - sqrt(det)) / (2 * a);

    else if(det == 0)
        std::cout << (-b - sqrt(det)) / (2 * a);
    else
        std::cout << "no roots";






    return 0;
}