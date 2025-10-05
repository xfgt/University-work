//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>


std::string encrypt(std::string x, size_t sz){

    for(size_t i = 0; i < sz; i++){

        // if(x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z' || (x[i] >= '0' && x[i] <= '9')){
        //
        //
        // } else if(){
        //
        // }

        x[i] += 3;
    }

    return x;
}


int main(){


    std::string input{};
    std::getline(std::cin, input);

    std::cout << encrypt(input, input.size());

    return 0;
}