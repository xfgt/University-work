//
// Created by twister on 8/27/24.
//


#include <iomanip>
#include <iostream>

void sol(const std::string& product, const int& quantity){

    double price {};

    if(product == "coffee")         price = 1.5 * quantity;
    else if(product == "water")     price = 1.0 * quantity;
    else if(product == "coke")      price = 1.4 * quantity;
    else if(product == "snacks")    price = 2.0 * quantity;
    else return;

    std::cout << std::fixed << std::setprecision(2) << price;

}

int main(){


    std::string product{};
    int quantity{};
    std::getline(std::cin, product);

    std::cin >> quantity;

    sol(product, quantity);

    return 0;
}