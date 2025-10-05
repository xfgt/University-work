//
// Created by twister on 8/27/24.
//


#include <iostream>
#include <cmath>



int getPow(const int& a, const int& b){
    if(a == 0) return 0;
    if(b == 0) return 1;
    return pow(a, b);

}

int main(){

    int a{}, b{};

    std::cin >> a >> b;

    std::cout << getPow(a, b);



    return 0;
}