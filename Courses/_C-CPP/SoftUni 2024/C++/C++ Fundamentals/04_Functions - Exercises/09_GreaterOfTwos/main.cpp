//
// Created by twister on 8/27/24.
//


#include <iostream>
#include <cstring>


void sol(const std::string& type, const std::string& a, const std::string& b){

    std::string larger{};

    if(type == "int") (std::stoi(a) > std::stoi(b)) ? larger = a : larger = b;
    else if(type == "char") (a.c_str() > b.c_str()) ? larger = a : larger = b;
    else if(type == "string") (std::strcmp(a.c_str(), b.c_str()) > 0) ? larger = a : larger = b;


    std::cout << larger;
}

int main(){

    std::string type{}, a{}, b{};

    std::getline(std::cin, type);
    std::getline(std::cin, a);
    std::getline(std::cin, b);


    sol(type, a, b);




    return 0;
}