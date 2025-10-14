//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>

void sol(const std::string& x, const size_t& sz){
    for(size_t i = 0; i < sz; i++){
        if(x[i] != x[i-1])
            std::cout << x[i];
    }



}


int main(){

    std::string input{};
    std::getline(std::cin, input);
    sol(input, input.size());


    return 0;
}