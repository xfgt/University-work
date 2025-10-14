//
// Created by twister on 8/27/24.
//


#include <iostream>

int main(){

    int a{};
    int b{};

    std::cin >> a >> b;

    if(a < b){
        std::cout << a << ' ' << b;
    } else{
        std::cout << b << ' ' << a;
    }


    return 0;
}