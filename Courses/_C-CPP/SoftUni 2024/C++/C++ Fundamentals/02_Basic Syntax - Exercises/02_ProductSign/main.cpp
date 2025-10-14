//
// Created by twister on 8/27/24.
//


#include <iostream>

int main(){
    double a{}, b{}, c{};
    int negatives{};

    std::cin >> a >> b >> c;
    if(a < 0)
        ++negatives;

    if(b < 0)
        ++negatives;

    if(c < 0)
        ++negatives;



    if(negatives == 1 || negatives == 3)
        std::cout << "-";
    else
        std::cout << "+";

    return 0;
}