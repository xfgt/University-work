//
// Created by twister on 8/27/24.
//


#include <iostream>


int main(){

    int a{}, b{};
    char sign{};


    std::cin >> a >> b >> sign;

    switch (sign){
    case '+':
        std::cout <<  a + b;
        break;
    case '-':
        std::cout << a - b;
        break;
    case '*':
        std::cout <<  a * b;
        break;
    case '/':
        std::cout << a / b;
        break;
    }


    return 0;
}